//!   2 0
//!     |`\
//!     |  `\
//!     | c  `\
//!     |      `\
//!     | a    b `\
//!   0 0----------0 1
//!  a, b, c are 3 point gauss quadratures

template <unsigned Tdim, unsigned Tnquadratures>
felib::TriangleQuadrature<Tdim, Tnquadratures>::TriangleQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {

  static_assert(Tdim == 2, "Invalid dimension for a triangle element");
  static_assert((Tnquadratures == 1) || (Tnquadratures == 3),
                "Invalid number of quadratures");

  if (Tnquadratures == 1) {
    // Single point gauss quadrature
    // Define quadratures
    qpoints_(0, 0) = 1. / 3.;
    qpoints_(0, 1) = 1. / 3.;

    // Define weights
    weights_.at(0) = 0.5;

  } else if (Tnquadratures == 3) {
    // Three-point gauss quadrature
    // First set of quadratures
    // Define quadratures
    qpoints_(0, 0) = 1. / 6.;
    qpoints_(0, 1) = 1. / 6.;

    qpoints_(1, 0) = 2. / 3.;
    qpoints_(1, 1) = 1. / 6.;

    qpoints_(2, 0) = 1. / 6.;
    qpoints_(2, 1) = 2. / 3.;

    // Define weights
    weights_.at(0) = 1. / 3.;
    weights_.at(1) = 1. / 3.;
    weights_.at(2) = 1. / 3.;
  }
}
