// Line quadrature test
#include <cmath>

#include <limits>

#include "catch.hpp"
#include "quadrilateral_quadrature.h"

//! \brief Check QuadrilateralQuadratures class
TEST_CASE("Quadrilateral quadratures are checked",
          "[quadquadrature][quad][quadrature][2D]") {
  const unsigned Dim = 2;
  const double Tolerance = 1.E-7;

  //! Check for a single point quadrature function
  SECTION("Quadrilateral with a single quadrature") {
    const unsigned Nquadratures = 1;

    auto quad = std::make_shared<felib::QuadrilateralQuadrature<Dim, Nquadratures>>();

    // Che quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 1);
    REQUIRE(points.cols() == 2);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(0.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(0.).epsilon(Tolerance));
    
    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 1);

    // Check weights
    REQUIRE(weights.at(0) == Approx(8.0).epsilon(Tolerance));
  }

}
