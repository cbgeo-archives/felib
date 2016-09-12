// Triangle shape function test
#include <limits>

#include "catch.hpp"
#include "triangle_shapefn.h"

//! \brief Check triangle shapefn class
TEST_CASE("Triangle shape functions are checked",
          "[trianglesf][triangle][shapefn][2D]") {
  const unsigned Dim = 2;
  const double Tolerance = 1.E-7;

  //! Check for 3 noded shape function
  SECTION("Triangle shape function with three nodes") {
    const unsigned Nfunctions = 3;
    auto trianglesf =
        std::make_shared<felib::TriangleShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0,0)
    SECTION("Three noded triangle shape function for coordinates(0,0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = trianglesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);
      
      REQUIRE(shapefn(0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = trianglesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);
      
      REQUIRE(gradsf(0, 0) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(1.0).epsilon(Tolerance));
    }

    // Coordinates is (0.5, 0.5);
    SECTION("Three noded triangle shape function for coordinates(-1, -1)") {
      std::array<double, Dim> coords = {{0.5, 0.5}};
      auto shapefn = trianglesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.5).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = trianglesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(1.0).epsilon(Tolerance));
    }
  }
  
  //! Check for 6-noded shape function
  SECTION("Triangle shape function with six nodes") {
    const unsigned Nfunctions = 6;
    auto trianglesf =
        std::make_shared<felib::TriangleShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0,0)
    SECTION("Six noded triangle shape function for coordinates(0,0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = trianglesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(3) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(4) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(5) == Approx(0.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = trianglesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(-3.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 0) == Approx(4.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 0) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(-3.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 1) == Approx(4.0).epsilon(Tolerance));
    }

    // Coordinates is (0.5,0.5)
    SECTION("Six noded triangle shape function for coordinates(0.5,0.5)") {
      std::array<double, Dim> coords = {{0.5, 0.5}};
      auto shapefn = trianglesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(3) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(4) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(shapefn(5) == Approx(0.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = trianglesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 0) == Approx(-2.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 0) == Approx(2.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 0) == Approx(-2.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 1) == Approx(-2.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 1) == Approx(2.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 1) == Approx(-2.0).epsilon(Tolerance));
    }
  }
}
