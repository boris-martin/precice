// Copyright (C) 2011 Technische Universitaet Muenchen
// This file is part of the preCICE project. For conditions of distribution and
// use, please see the license notice at http://www5.in.tum.de/wiki/index.php/PreCICE_License
#include "DistributedGeometry.hpp"
#include "com/CommunicateMesh.hpp"
#include "com/Communication.hpp"
#include "mesh/Mesh.hpp"
#include "utils/Globals.hpp"
#include "utils/Helpers.hpp"
#include "mesh/SharedPointer.hpp"

namespace precice {
namespace geometry {

tarch::logging::Log DistributedGeometry:: _log ( "precice::geometry::DistributedGeometry" );

DistributedGeometry:: DistributedGeometry
(
  const utils::DynVector&  offset,
  const std::string&       accessor,
  const std::string&       provider,
  com::PtrCommunication    masterSlaveCom,
  const int                rank,
  const int                size)
:
  CommunicatedGeometry ( offset, accessor, provider ),
  _masterSlaveCommunication ( masterSlaveCom ),
  _rank(rank),
  _size(size)
{
  preciceTrace2 ( "DistributedGeometry()", accessor, provider );
}

void DistributedGeometry:: specializedCreate
(
  mesh::Mesh& seed )
{
  preciceTrace1 ( "specializedCreate()", seed.getName() );
  preciceCheck ( _receivers.size() > 0, "specializedCreate()",
                 "No receivers specified for communicated geometry to create "
                 << "mesh \"" << seed.getName() << "\"!" );
  _isDistributed = true;
  if ( _accessorName == _providerName ) {

    if(_rank>0){ //slave
      com::CommunicateMesh(_masterSlaveCommunication).sendMesh ( seed, 0 );
    }
    else{ //master
      assertion(_rank==0);
      assertion(_size>1);
      _vertexDistribution[0]=seed.vertices().size();
      mesh::Mesh slaveMesh("SlaveMesh", seed.getDimensions(), seed.isFlipNormals());
      mesh::Mesh& rSlaveMesh = slaveMesh;

      for(int rankSlave = 1; rankSlave < _size; rankSlave++){
        //slaves have ranks from 0 to size-2
        //TODO better rewrite accept/request connection
        rSlaveMesh.clear();
        com::CommunicateMesh(_masterSlaveCommunication).receiveMesh ( rSlaveMesh, rankSlave-1);
        _vertexDistribution[rankSlave]=rSlaveMesh.vertices().size();
        int dim = rSlaveMesh.getDimensions();
        utils::DynVector coord(dim);
        foreach ( const mesh::Vertex& vertex, rSlaveMesh.vertices() ){
            coord = vertex.getCoords();
            seed.createVertex(coord);
        }
      }
      preciceCheck ( seed.vertices().size() > 0,
                       "specializedCreate()", "Participant \"" << _accessorName
                       << "\" provides an invalid (possibly empty) mesh \""
                       << seed.getName() << "\"!" );
      typedef std::map<std::string,com::PtrCommunication>::value_type Pair;
      foreach ( Pair & pair, _receivers ) {
        if ( ! pair.second->isConnected() ) {
          pair.second->acceptConnection ( _providerName, pair.first, 0, 1 );
        }
        com::CommunicateMesh(pair.second).sendMesh ( seed, 0 );
      }
    }

  }
  else if ( utils::contained(_accessorName, _receivers) ) {
    assertion(false);
//    assertion ( seed.vertices().size() == 0 );
//    assertion ( utils::contained(_accessorName, _receivers) );
//    com::PtrCommunication com ( _receivers[_accessorName] );
//    if ( ! com->isConnected() ) {
//      com->requestConnection ( _providerName, _accessorName, 0, 1 );
//    }
//    com::CommunicateMesh(com).receiveMesh ( seed, 0 );
  }
  else {
    preciceError( "specializedCreate()", "Participant \"" << _accessorName
                  << "\" uses a communicated geometry to create mesh \""
                  << seed.getName()
                  << "\" but is neither provider nor receiver!" );
  }
}


}} // namespace precice, geometry
