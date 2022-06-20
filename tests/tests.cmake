#
# This file lists all integration test sources and test suites
#
target_sources(testprecice
    PRIVATE
    tests/parallel/CouplingOnLine.cpp
    tests/parallel/ExportTimeseries.cpp
    tests/parallel/GlobalRBFPartitioning.cpp
    tests/parallel/LocalRBFPartitioning.cpp
    tests/parallel/NearestProjectionRePartitioning.cpp
    tests/parallel/PrimaryRankSockets.cpp
    tests/parallel/TestBoundingBoxInitialization.cpp
    tests/parallel/TestBoundingBoxInitializationTwoWay.cpp
    tests/parallel/TestFinalize.cpp
    tests/parallel/TestFinalizeDeprecatedTag.cpp
    tests/parallel/UserDefinedMPICommunicator.cpp
    tests/parallel/UserDefinedMPICommunicatorPetRBF.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshAndMapping.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshEmptyPartition.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshEmptyPartitionTwoLevelInit.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshNoOverlap.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshNoOverlapTwoLevelInit.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshOverlap.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshOverlapNoWrite.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshOverlapNoWriteTwoLevelInit.cpp
    tests/parallel/direct-mesh-access/AccessReceivedMeshOverlapTwoLevelInit.cpp
    tests/parallel/direct-mesh-access/helpers.cpp
    tests/parallel/direct-mesh-access/helpers.hpp
    tests/parallel/distributed-communication/TestDistributedCommunicationGatherScatterMPI.cpp
    tests/parallel/distributed-communication/TestDistributedCommunicationP2PMPI.cpp
    tests/parallel/distributed-communication/TestDistributedCommunicationP2PSockets.cpp
    tests/parallel/distributed-communication/helpers.cpp
    tests/parallel/distributed-communication/helpers.hpp
    tests/parallel/gather-scatter/EnforceGatherScatterEmptyPrimaryRank.cpp
    tests/parallel/gather-scatter/EnforceGatherScatterEmptyReceivedPrimaryRank.cpp
    tests/parallel/gather-scatter/helpers.cpp
    tests/parallel/gather-scatter/helpers.hpp
    tests/parallel/lifecycle/ConstructAndExplicitFinalize.cpp
    tests/parallel/lifecycle/ConstructOnly.cpp
    tests/parallel/lifecycle/Full.cpp
    tests/parallel/lifecycle/ImplicitFinalize.cpp
    tests/parallel/mapping-nearest-neighbor-gradient/GradientTestParallelScalar.cpp
    tests/parallel/mapping-nearest-neighbor-gradient/GradientTestParallelVector.cpp
    tests/parallel/mapping-nearest-neighbor-gradient/GradientTestParallelWriteVector.cpp
    tests/parallel/mapping-volume/ParallelSquare1To2.cpp
    tests/parallel/mapping-volume/ParallelCube3To1.cpp
    tests/parallel/mapping-volume/ParallelSquare2To1.cpp
    tests/parallel/mapping-volume/ParallelSquareConservative1To2.cpp
    tests/parallel/mapping-volume/ParallelTriangleConservative2To1.cpp
    tests/parallel/quasi-newton/TestQN1.cpp
    tests/parallel/quasi-newton/TestQN1EmptyPartition.cpp
    tests/parallel/quasi-newton/TestQN2.cpp
    tests/parallel/quasi-newton/TestQN2EmptyPartition.cpp
    tests/parallel/quasi-newton/TestQN3.cpp
    tests/parallel/quasi-newton/TestQN3EmptyPartition.cpp
    tests/parallel/quasi-newton/helpers.cpp
    tests/parallel/quasi-newton/helpers.hpp
    tests/serial/AitkenAcceleration.cpp
    tests/serial/PreconditionerBug.cpp
    tests/serial/SendMeshToMultipleParticipants.cpp
    tests/serial/SummationActionTwoSources.cpp
    tests/serial/TestExplicitWithDataMultipleReadWrite.cpp
    tests/serial/TestExplicitWithSolverGeometry.cpp
    tests/serial/TestImplicit.cpp
    tests/serial/TestReadAPI.cpp
    tests/serial/access-received-mesh/Explicit.cpp
    tests/serial/access-received-mesh/ExplicitAndMapping.cpp
    tests/serial/access-received-mesh/ExplicitRead.cpp
    tests/serial/access-received-mesh/Implicit.cpp
    tests/serial/action-timings/ActionTimingsExplicit.cpp
    tests/serial/action-timings/ActionTimingsImplicit.cpp
    tests/serial/convergence-measures/helpers.cpp
    tests/serial/convergence-measures/helpers.hpp
    tests/serial/convergence-measures/testConvergenceMeasures1.cpp
    tests/serial/convergence-measures/testConvergenceMeasures2.cpp
    tests/serial/convergence-measures/testConvergenceMeasures3.cpp
    tests/serial/explicit/TestExplicitMPI.cpp
    tests/serial/explicit/TestExplicitMPISingle.cpp
    tests/serial/explicit/TestExplicitSockets.cpp
    tests/serial/explicit/helpers.cpp
    tests/serial/explicit/helpers.hpp
    tests/serial/initialize-data/Explicit.cpp
    tests/serial/initialize-data/Implicit.cpp
    tests/serial/initialize-data/ReadMapping.cpp
    tests/serial/initialize-data/WriteMapping.cpp
    tests/serial/initialize-data/helpers.cpp
    tests/serial/initialize-data/helpers.hpp
    tests/serial/lifecycle/ConstructAndExplicitFinalize.cpp
    tests/serial/lifecycle/ConstructOnly.cpp
    tests/serial/lifecycle/Full.cpp
    tests/serial/lifecycle/ImplicitFinalize.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestBidirectionalReadScalar.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestBidirectionalReadVector.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestBidirectionalWriteScalar.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestBidirectionalWriteVector.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestUnidirectionalReadBlockVector.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestUnidirectionalReadScalar.cpp
    tests/serial/mapping-nearest-neighbor-gradient/GradientTestUnidirectionalReadVector.cpp
    tests/serial/mapping-nearest-neighbor-gradient/helpers.cpp
    tests/serial/mapping-nearest-neighbor-gradient/helpers.hpp
    tests/serial/mapping-nearest-projection/MappingNearestProjectionExplicitEdges.cpp
    tests/serial/mapping-nearest-projection/MappingNearestProjectionImplicitEdges.cpp
    tests/serial/mapping-nearest-projection/helpers.cpp
    tests/serial/mapping-nearest-projection/helpers.hpp
    tests/serial/mapping-nearest-projection/testQuadMappingDiagonalNearestProjectionExplicitEdgesTallKite.cpp
    tests/serial/mapping-nearest-projection/testQuadMappingDiagonalNearestProjectionExplicitEdgesWideKite.cpp
    tests/serial/mapping-nearest-projection/testQuadMappingDiagonalNearestProjectionImplicitEdgesTallKite.cpp
    tests/serial/mapping-nearest-projection/testQuadMappingDiagonalNearestProjectionImplicitEdgesWideKite.cpp
    tests/serial/mapping-nearest-projection/testQuadMappingNearestProjectionExplicitEdges.cpp
    tests/serial/mapping-nearest-projection/testQuadMappingNearestProjectionImplicitEdges.cpp
    tests/serial/mapping-rbf-gaussian/GaussianShapeParameter.cpp
    tests/serial/mapping-rbf-gaussian/GaussianSupportRadius.cpp
    tests/serial/mapping-rbf-gaussian/helpers.cpp
    tests/serial/mapping-rbf-gaussian/helpers.hpp
    tests/serial/mapping-scaled-consistent/helpers.cpp
    tests/serial/mapping-scaled-consistent/helpers.hpp
    tests/serial/mapping-scaled-consistent/testQuadMappingScaledConsistentOnA.cpp
    tests/serial/mapping-scaled-consistent/testQuadMappingScaledConsistentOnB.cpp
    tests/serial/mapping-volume/OneTetraConservativeRead.cpp
    tests/serial/mapping-volume/OneTetraConservativeWrite.cpp
    tests/serial/mapping-volume/OneTetraRead.cpp
    tests/serial/mapping-volume/OneTetraWrite.cpp
    tests/serial/mapping-volume/OneTriangleConservativeRead.cpp
    tests/serial/mapping-volume/OneTriangleConservativeWrite.cpp
    tests/serial/mapping-volume/OneTriangleRead.cpp
    tests/serial/mapping-volume/OneTriangleWrite.cpp
    tests/serial/mapping-volume/helpers.cpp
    tests/serial/mapping-volume/helpers.hpp
    tests/serial/mesh-requirements/NearestNeighborA.cpp
    tests/serial/mesh-requirements/NearestNeighborB.cpp
    tests/serial/mesh-requirements/NearestProjection2DA.cpp
    tests/serial/mesh-requirements/NearestProjection2DB.cpp
    tests/serial/multi-coupling/MultiCoupling.cpp
    tests/serial/multi-coupling/MultiCouplingFourSolvers1.cpp
    tests/serial/multi-coupling/MultiCouplingFourSolvers2.cpp
    tests/serial/multi-coupling/MultiCouplingThreeSolvers1.cpp
    tests/serial/multi-coupling/MultiCouplingThreeSolvers2.cpp
    tests/serial/multi-coupling/MultiCouplingThreeSolvers3.cpp
    tests/serial/multi-coupling/helpers.cpp
    tests/serial/multi-coupling/helpers.hpp
    tests/serial/multiple-mappings/MultipleReadFromMappings.cpp
    tests/serial/multiple-mappings/MultipleReadToMappings.cpp
    tests/serial/multiple-mappings/MultipleWriteFromMappings.cpp
    tests/serial/multiple-mappings/MultipleWriteFromMappingsAndData.cpp
    tests/serial/multiple-mappings/MultipleWriteToMappings.cpp
    tests/serial/stationary-mapping-with-solver-mesh/StationaryMappingWithSolverMesh2D.cpp
    tests/serial/stationary-mapping-with-solver-mesh/StationaryMappingWithSolverMesh3D.cpp
    tests/serial/stationary-mapping-with-solver-mesh/helpers.cpp
    tests/serial/stationary-mapping-with-solver-mesh/helpers.hpp
    tests/serial/three-solvers/ThreeSolversExplicitExplicit.cpp
    tests/serial/three-solvers/ThreeSolversExplicitImplicit.cpp
    tests/serial/three-solvers/ThreeSolversImplicitExplicit.cpp
    tests/serial/three-solvers/ThreeSolversImplicitImplicit.cpp
    tests/serial/three-solvers/ThreeSolversParallel.cpp
    tests/serial/three-solvers/helpers.cpp
    tests/serial/three-solvers/helpers.hpp
    tests/serial/time/explicit/compositional/ReadWriteScalarDataWithSubcycling.cpp
    tests/serial/time/explicit/parallel-coupling/ReadWriteScalarDataWithSubcycling.cpp
    tests/serial/time/explicit/serial-coupling/ReadWriteScalarDataWithSubcycling.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithSubcycling.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSamplingFirst.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSamplingFirstNoInit.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSamplingZero.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSubcyclingFirst.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSubcyclingMixed.cpp
    tests/serial/time/implicit/parallel-coupling/ReadWriteScalarDataWithWaveformSubcyclingZero.cpp
    tests/serial/time/implicit/serial-coupling/ReadWriteScalarDataWithSubcycling.cpp
    tests/serial/watch-integral/WatchIntegralScaleAndNoScale.cpp
    tests/serial/watch-integral/helpers.cpp
    tests/serial/watch-integral/helpers.hpp
    tests/serial/whitebox/TestConfigurationComsol.cpp
    tests/serial/whitebox/TestConfigurationPeano.cpp
    tests/serial/whitebox/TestExplicitWithDataScaling.cpp
    )

# Contains the list of integration test suites
set(PRECICE_TEST_SUITES Parallel Serial)
