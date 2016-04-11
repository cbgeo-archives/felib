// Hexahedron shape function test
#include <limits>

#include "catch.hpp"
#include "hexahedron_shapefn.h"

//! \brief Check hexahedron shapefn class
TEST_CASE("Hexahedron shape functions are checked",
          "[hexsf][hex][shapefn][2D]") {
  const unsigned Dim = 3;
  const double Tolerance = 1.E-7;

  //! Check for 8 noded shape function
  SECTION("Hexahedron shape function with eight nodes") {
    const unsigned Nfunctions = 8;
    auto hexsf = std::make_shared<felib::HexahedronShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0, 0, 0)
    SECTION("Eight noded hexahedron shape function for coordinates(0, 0, 0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = hexsf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(3) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(4) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(5) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(6) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(shapefn(7) == Approx(0.125).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = hexsf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(3, 0) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(4, 0) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(5, 0) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(6, 0) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(7, 0) == Approx(-0.125).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(3, 1) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(4, 1) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(5, 1) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(6, 1) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(7, 1) == Approx(0.125).epsilon(Tolerance));

      REQUIRE(gradsf(0, 2) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(1, 2) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(2, 2) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(3, 2) == Approx(-0.125).epsilon(Tolerance));
      REQUIRE(gradsf(4, 2) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(5, 2) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(6, 2) == Approx(0.125).epsilon(Tolerance));
      REQUIRE(gradsf(7, 2) == Approx(0.125).epsilon(Tolerance));
    }

    // Coordinates is (-1, -1, -1);
    SECTION(
        "Eight noded hexahedron shape function for coordinates(-1, -1, -1)") {
      std::array<double, Dim> coords = {{-1., -1., -1.}};
      auto shapefn = hexsf->shapefn(coords);
      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(3) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(4) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(5) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(6) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(7) == Approx(0.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = hexsf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(6, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(7, 0) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 1) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(4, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(6, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(7, 1) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 2) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(1, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 2) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(5, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(6, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(7, 2) == Approx(0.0).epsilon(Tolerance));
    }

    // Coordinates is (1, 1, 1)
    SECTION("Eight noded hexahedron shape function for coordinates(1, 1, 1)") {
      std::array<double, Dim> coords = {{1., 1., 1.}};
      auto shapefn = hexsf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      REQUIRE(shapefn(0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(3) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(4) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(5) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(shapefn(6) == Approx(1.0).epsilon(Tolerance));
      REQUIRE(shapefn(7) == Approx(0.0).epsilon(Tolerance));

      // Check gradient of shape functions
      auto gradsf = hexsf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);

      REQUIRE(gradsf(0, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 0) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(6, 0) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(7, 0) == Approx(-0.5).epsilon(Tolerance));

      REQUIRE(gradsf(0, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(3, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 1) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 1) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(6, 1) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(7, 1) == Approx(0.0).epsilon(Tolerance));

      REQUIRE(gradsf(0, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(1, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(2, 2) == Approx(-0.5).epsilon(Tolerance));
      REQUIRE(gradsf(3, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(4, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(5, 2) == Approx(0.0).epsilon(Tolerance));
      REQUIRE(gradsf(6, 2) == Approx(0.5).epsilon(Tolerance));
      REQUIRE(gradsf(7, 2) == Approx(0.0).epsilon(Tolerance));
    }
  }

  // 20-Node (Serendipity) Hexahedron Element
  //! Check for 8 noded shape function
  SECTION("Hexahedron shape function with twenty nodes") {
    const unsigned Nfunctions = 20;
    auto hexsf = std::make_shared<felib::HexahedronShapeFn<Dim, Nfunctions>>();

    // Coordinates is (0, 0, 0)
    SECTION("Twenty noded hexahedron shape function for coordinates(0, 0, 0)") {
      std::array<double, Dim> coords = {{0.}};
      auto shapefn = hexsf->shapefn(coords);

      // Check shape function
      REQUIRE(shapefn.size() == Nfunctions);

      // Check gradient of shape functions
      auto gradsf = hexsf->grad_shapefn(coords);
      REQUIRE(gradsf.rows() == Nfunctions);
      REQUIRE(gradsf.cols() == Dim);
    }
  }
}
