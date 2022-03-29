#include <Eigen/Core>
#include <ostream>
#include "math/barycenter.hpp"
#include "math/constants.hpp"
#include "math/differences.hpp"
#include "testing/TestContext.hpp"
#include "testing/Testing.hpp"

using namespace precice;
using namespace precice::math::barycenter;

BOOST_AUTO_TEST_SUITE(MathTests)
BOOST_AUTO_TEST_SUITE(Barycenter)

BOOST_AUTO_TEST_CASE(BarycenterEdge2D)
{
  PRECICE_TEST(1_rank);
  using Eigen::Vector2d;
  using Eigen::Vector3d;
  using precice::testing::equals;
  Vector2d a(0.0, 0.0);
  Vector2d b(1.0, 0.0);
  Vector2d n(0.0, 1.0);
  {
    Vector2d l(0.5, 0.0);
    Vector2d coords(0.5, 0.5);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector2d l(0.0, 0.0);
    Vector2d coords(1.0, 0.0);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector2d l(1.0, 0.0);
    Vector2d coords(0, 1.0);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector2d l(0.75, 1.0);
    Vector2d coords(0.25, 0.75);
    auto     ret = calcBarycentricCoordsForEdge(a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords), "Coords are " << ret << " but should be " << coords);
  }
}

BOOST_AUTO_TEST_CASE(BarycenterEdge3D)
{
  PRECICE_TEST(1_rank);
  using Eigen::Vector2d;
  using Eigen::Vector3d;
  using precice::testing::equals;
  Vector3d a(0.0, 0.0, 0.0);
  Vector3d b(1.0, 0.0, 0.0);
  Vector3d n(0.0, 0.0, 1.0);
  {
    Vector3d l(0.5, 0.0, 0.0);
    Vector2d coords(0.5, 0.5);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector3d l(0.0, 0.0, 0.0);
    Vector2d coords(1.0, 0.0);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector3d l(1.0, 0.0, 0.0);
    Vector2d coords(0, 1.0);
    auto     ret = calcBarycentricCoordsForEdge(
        a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  {
    Vector3d l(0.75, 1.0, 0.0);
    Vector2d coords(0.25, 0.75);
    auto     ret = calcBarycentricCoordsForEdge(a, b, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords), fmt::format("Coords are {} but should be {}", ret, coords));
  }
}

BOOST_AUTO_TEST_CASE(BarycenterTriangle3D)
{
  PRECICE_TEST(1_rank);
  using Eigen::Vector3d;
  using precice::testing::equals;
  Vector3d a(0.0, 0.0, 0.0);
  Vector3d b(0.0, 1.0, 0.0);
  Vector3d c(1.0, 0.0, 0.0);
  Vector3d n(0.0, 0.0, 1.0);
  // is a?
  {
    Vector3d coords(1.0, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, a);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is b?
  {
    Vector3d coords(0.0, 1.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, b);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is c?
  {
    Vector3d coords(0.0, 0.0, 1.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, c);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle
  {
    Vector3d l = (a + b + c) / 3;
    Vector3d coords(1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of ab
  {
    Vector3d l = (a + b) / 2;
    Vector3d coords(0.5, 0.5, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of bc
  {
    Vector3d l = (b + c) / 2;
    Vector3d coords(0.0, 0.5, 0.5);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of ca
  {
    Vector3d l = (a + c) / 2;
    Vector3d coords(0.5, 0.0, 0.5);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is outside
  {
    Vector3d l(2.0, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST((ret.array() < -precice::math::NUMERICAL_ZERO_DIFFERENCE).any(), fmt::format("Min 1 coord should be negative {}", ret));
  }
}

BOOST_AUTO_TEST_CASE(BarycenterTriangle2D)
{
  PRECICE_TEST(1_rank);
  using Eigen::Vector2d;
  using Eigen::Vector3d;
  using precice::testing::equals;
  Vector2d a(0.0, 0.0);
  Vector2d b(0.0, 1.0);
  Vector2d c(1.0, 0.0);
  Vector2d n(0.0, 0.0);
  // is a?
  {
    Vector3d coords(1.0, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, a);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is b?
  {
    Vector3d coords(0.0, 1.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, b);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is c?
  {
    Vector3d coords(0.0, 0.0, 1.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, c);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle
  {
    Vector2d l = (a + b + c) / 3;
    Vector3d coords(1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of ab
  {
    Vector2d l = (a + b) / 2;
    Vector3d coords(0.5, 0.5, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of bc
  {
    Vector2d l = (b + c) / 2;
    Vector3d coords(0.0, 0.5, 0.5);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is in the middle of ca
  {
    Vector2d l = (a + c) / 2;
    Vector3d coords(0.5, 0.0, 0.5);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // is outside
  {
    Vector2d l(2.0, 0.0);
    auto     ret = calcBarycentricCoordsForTriangle(a, b, c, l);
    BOOST_TEST((ret.array() < -precice::math::NUMERICAL_ZERO_DIFFERENCE).any(), fmt::format("Min 1 coord should be negative {}", ret));
  }
}

BOOST_AUTO_TEST_CASE(BarycenterTetrahedron)
{
  PRECICE_TEST(1_rank);
  using Eigen::Vector3d;
  using Eigen::Vector4d;
  using precice::testing::equals;
  Vector3d a(0.0, 0.0, 0.0);
  Vector3d b(0.0, 1.0, 0.0);
  Vector3d c(1.0, 0.0, 0.0);
  Vector3d d(0.0, 0.0, 1.0);
  // is center?
  {
    Vector4d coords(0.25, 0.25, 0.25, 0.25);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, (a + b + c + d) / 4);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // random combination?
  {
    Vector4d coords(0.2, 0.3, 0.4, 0.1);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, 0.2 * a + +0.3 * b + +0.4 * c + +0.1 * d);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is A?
  {
    Vector4d coords(1.0, 0.0, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, a);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is B?
  {
    Vector4d coords(0.0, 1.0, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, b);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is C?
  {
    Vector4d coords(0.0, 0.0, 1.0, 0.0);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, c);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is D?
  {
    Vector4d coords(0.0, 0.0, 0.0, 1.0);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, d);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is middle of AB?
  {
    Vector4d coords(0.5, 0.5, 0.0, 0.0);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, 0.5 * a + 0.5 * b);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
  // Is middle of ABD?
  {
    Vector4d coords(1. / 3, 1. / 3, 0.0, 1. / 3);
    auto     ret = calcBarycentricCoordsForTetrahedron(a, b, c, d, (a + b + d) / 3);
    BOOST_TEST(ret.sum() == 1.0);
    BOOST_TEST(equals(ret, coords));
  }
}

BOOST_AUTO_TEST_SUITE_END() // Barycenter

BOOST_AUTO_TEST_SUITE_END() // Math
