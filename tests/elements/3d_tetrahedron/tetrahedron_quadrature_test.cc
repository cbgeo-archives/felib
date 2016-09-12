// Tetrahedron quadrature test
#include <cmath>

#include <limits>

#include "catch.hpp"
#include "tetrahedron_quadrature.h"

//! \brief Check TetrahedronQuadratures class
TEST_CASE("Tetrahedron quadratures are checked",
          "[tetraquadrature][tetra][quadrature][3D]") {
  const unsigned Dim = 3;
  const double Tolerance = 1.E-7;

  //! Check for a single point quadrature function
  SECTION("Tetrahedron with a single quadrature") {
    const unsigned Nquadratures = 1;

    auto quad =
        std::make_shared<felib::TetrahedronQuadrature<Dim, Nquadratures>>();

    // Che quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 1);
    REQUIRE(points.cols() == 3);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(0.25).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(0.25).epsilon(Tolerance));
    REQUIRE(points(0, 2) == Approx(0.25).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 1);

    // Check weights
    REQUIRE(weights.at(0) == Approx(1. / 6.).epsilon(Tolerance));
  }

  //! Check for four quadrature points
  SECTION("Tetrahedron with four quadratures") {
    const unsigned Nquadratures = 4;

    auto quad =
        std::make_shared<felib::TetrahedronQuadrature<Dim, Nquadratures>>();

    // Check quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 4);
    REQUIRE(points.cols() == 3);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx((5. + 3* std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(0, 2) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));

    REQUIRE(points(1, 0) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(1, 1) == Approx((5. + 3 * std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(1, 2) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));

    REQUIRE(points(2, 0) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(2, 1) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(2, 2) == Approx((5. + 3. * std::sqrt(5.)) / 20.).epsilon(Tolerance));

    REQUIRE(points(3, 0) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(3, 1) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));
    REQUIRE(points(3, 2) == Approx((5. - std::sqrt(5.)) / 20.).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 4);

    // Check weights
    REQUIRE(weights.at(0) == Approx(1. / 24.).epsilon(Tolerance));
    REQUIRE(weights.at(1) == Approx(1. / 24.).epsilon(Tolerance));
    REQUIRE(weights.at(2) == Approx(1. / 24.).epsilon(Tolerance));
    REQUIRE(weights.at(3) == Approx(1. / 24.).epsilon(Tolerance));
  }

  //! Check for five quadrature points
  SECTION("Tetrahedron with five quadratures") {
    const unsigned Nquadratures = 5;

    auto quad =
        std::make_shared<felib::TetrahedronQuadrature<Dim, Nquadratures>>();

    // Check quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 5);
    REQUIRE(points.cols() == 3);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(1. / 4.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(1. / 4.).epsilon(Tolerance));
    REQUIRE(points(0, 2) == Approx(1. / 4.).epsilon(Tolerance));

    REQUIRE(points(1, 0) == Approx(1. / 2.).epsilon(Tolerance));
    REQUIRE(points(1, 1) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(1, 2) == Approx(1. / 6.).epsilon(Tolerance));

    REQUIRE(points(2, 0) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(2, 1) == Approx(1. / 2.).epsilon(Tolerance));
    REQUIRE(points(2, 2) == Approx(1. / 6.).epsilon(Tolerance));

    REQUIRE(points(3, 0) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(3, 1) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(3, 2) == Approx(1. / 2.).epsilon(Tolerance));

    REQUIRE(points(4, 0) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(4, 1) == Approx(1. / 6.).epsilon(Tolerance));
    REQUIRE(points(4, 2) == Approx(1. / 6.).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 5);

    // Check weights
    REQUIRE(weights.at(0) == Approx(-2. / 15.).epsilon(Tolerance));
    REQUIRE(weights.at(1) == Approx(+3. / 40.).epsilon(Tolerance));
    REQUIRE(weights.at(2) == Approx(+3. / 40.).epsilon(Tolerance));
    REQUIRE(weights.at(3) == Approx(+3. / 40.).epsilon(Tolerance));
    REQUIRE(weights.at(4) == Approx(+3. / 40.).epsilon(Tolerance));
  }

  //! Check for eleven quadrature points
  SECTION("Tetrahedron with eleven quadratures") {
    const unsigned Nquadratures = 11;

    auto quad =
        std::make_shared<felib::TetrahedronQuadrature<Dim, Nquadratures>>();

    // Check quadratures
    auto points = quad->quadratures();

    // Check size
    REQUIRE(points.rows() == 11);
    REQUIRE(points.cols() == 3);

    // Check quadrature points
    REQUIRE(points(0, 0) == Approx(1. / 4.).epsilon(Tolerance));
    REQUIRE(points(0, 1) == Approx(1. / 4.).epsilon(Tolerance));
    REQUIRE(points(0, 2) == Approx(1. / 4.).epsilon(Tolerance));

    REQUIRE(points(1, 0) == Approx(11. / 14.).epsilon(Tolerance));
    REQUIRE(points(1, 1) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(1, 2) == Approx(1. / 14.).epsilon(Tolerance));

    REQUIRE(points(2, 0) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(2, 1) == Approx(11. / 14.).epsilon(Tolerance));
    REQUIRE(points(2, 2) == Approx(1. / 14.).epsilon(Tolerance));

    REQUIRE(points(3, 0) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(3, 1) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(3, 2) == Approx(11. / 14.).epsilon(Tolerance));

    REQUIRE(points(4, 0) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(4, 1) == Approx(1. / 14.).epsilon(Tolerance));
    REQUIRE(points(4, 2) == Approx(1. / 14.).epsilon(Tolerance));

    REQUIRE(points(5, 0) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(5, 1) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(5, 2) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    REQUIRE(points(6, 0) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(6, 1) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(6, 2) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    REQUIRE(points(7, 0) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(7, 1) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(7, 2) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    REQUIRE(points(8, 0) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(8, 1) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(8, 2) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    REQUIRE(points(9, 0) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(9, 1) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(9, 2) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    REQUIRE(points(10, 0) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(10, 1) ==
            Approx((1. - std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));
    REQUIRE(points(10, 2) ==
            Approx((1. + std::sqrt(5. / 14.)) / 4.).epsilon(Tolerance));

    // Check weights
    auto weights = quad->weights();

    // Check size
    REQUIRE(weights.size() == 11);

    // Check weights
    REQUIRE(weights.at(0) == Approx(-74. / 5625.).epsilon(Tolerance));
    REQUIRE(weights.at(1) == Approx(+343. / 45000.).epsilon(Tolerance));
    REQUIRE(weights.at(2) == Approx(+343. / 45000.).epsilon(Tolerance));
    REQUIRE(weights.at(3) == Approx(+343. / 45000.).epsilon(Tolerance));
    REQUIRE(weights.at(4) == Approx(+343. / 45000.).epsilon(Tolerance));
    REQUIRE(weights.at(5) == Approx(+56. / 2250.).epsilon(Tolerance));
    REQUIRE(weights.at(6) == Approx(+56. / 2250.).epsilon(Tolerance));
    REQUIRE(weights.at(7) == Approx(+56. / 2250.).epsilon(Tolerance));
    REQUIRE(weights.at(8) == Approx(+56. / 2250.).epsilon(Tolerance));
    REQUIRE(weights.at(9) == Approx(+56. / 2250.).epsilon(Tolerance));
    REQUIRE(weights.at(10) == Approx(+56. / 2250.).epsilon(Tolerance));
  }
}
