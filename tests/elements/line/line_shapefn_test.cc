// Line shape function test
#include <limits>

#include "catch.hpp"
#include "line_shapefn.h"

//! \brief Check line shapefn class
TEST_CASE("Line shape functions are checked", "[linesf][line][shapefn][1D]") {
  const unsigned Dim = 1;
  const double Tolerance = 1.E-7;

  //! Check for 2 noded shape function
  SECTION("Line shape function with two nodes") {
    const unsigned Nfunctions = 2;
    auto linesf = std::make_shared<felib::LineShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0)
    SECTION("Two noded line shape function for coordinates(0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.5).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(0.5).epsilon(Tolerance));
    }

    // Coordinates is (-0.5);
    SECTION("Two noded line shape function for coordinates(-0.5)") {
      std::array<double, Dim> coords = {{-0.5}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.75).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.25).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(0.5).epsilon(Tolerance));
    }

    // Coordinates is (0.5)
    SECTION("Two noded line shape function for coordinates(0.5)") {
      std::array<double, Dim> coords = {{0.5}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.25).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.75).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(0.5).epsilon(Tolerance));
    }
  }

  //! Check for 3 noded shape function
  SECTION("Line shape function with three nodes") {
    const unsigned Nfunctions = 3;
    auto linesf = std::make_shared<felib::LineShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0)
    SECTION("Three noded line shape function for coordinates(0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(1.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(2) == Approx(0.0).epsilon(Tolerance));
    }

    // Coordinates is (-0.5);
    SECTION("Three noded line shape function for coordinates(-0.5)") {
      std::array<double, Dim> coords = {{-0.5}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.375).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.75).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(-1.0).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2) == Approx(1.0).epsilon(Tolerance));
    }

    // Coordinates is (0.5)
    SECTION("Three noded line shape function for coordinates(0.5)") {
      std::array<double, Dim> coords = {{0.5}};
      auto shapefn = linesf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.375).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.75).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = linesf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(1) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(gradsf(2) == Approx(-1.0).epsilon(Tolerance));
    }
  }
}
