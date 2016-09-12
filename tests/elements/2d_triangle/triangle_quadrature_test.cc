// Line quadrature test
#include <cmath>

#include <limits>

#include "catch.hpp"
#include "triangle_quadrature.h"

//! \brief Check TriangleQuadratures class
TEST_CASE("Triangle quadratures are checked",
          "[trianglequadrature][triangle][quadrature][2D]") {
  const unsigned Dim = 2;
  const double Tolerance = 1.E-7;

  //! Check for a single point quadrature function
  SECTION("Triangle with a single quadrature") {
    const unsigned Nquadratures = 1;

    auto quad =
        std::make_shared<felib::TriangleQuadrature<Dim, Nquadratures>>();

    // Che quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 1);
    REQUIRE(points.cols() == 2);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(1. / 3.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(1. / 3.).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 1);

    // Check weights
    REQUIRE(weights.at(0) == Approx(0.5).epsilon(Tolerance));
  }

  //! Check for three quadrature points
  SECTION("Triangle with three quadratures") {
    const unsigned Nquadratures = 3;

    auto quad =
        std::make_shared<felib::TriangleQuadrature<Dim, Nquadratures>>();

    // Check quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 3);
    REQUIRE(points.cols() == 2);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(1, 0) == Approx(2. / 3.).epsilon(Tolerance));
    REQUIRE(points(1, 1) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(2, 0) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(2, 1) == Approx(2. / 3.).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 3);

    // Check weights
    REQUIRE(weights.at(0) == Approx(1. / 3.).epsilon(Tolerance));
    REQUIRE(weights.at(1) == Approx(1. / 3.).epsilon(Tolerance));
    REQUIRE(weights.at(2) == Approx(1. / 3.).epsilon(Tolerance));
  }
}
