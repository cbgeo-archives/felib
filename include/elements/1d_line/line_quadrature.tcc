// Default constructor
template <unsigned Tdim, unsigned Tnquadratures>
felib::LineQuadrature<Tdim, Tnquadratures>::LineQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {
  static_assert(Tdim == 1, "Invalid dimension for a 1D element");
  static_assert(
      (Tnquadratures == 1 || Tnquadratures == 2 || Tnquadratures == 3),
      "Invalid number of quadratures");

  if (Tnquadratures == 1) {

    // Single point quadrature
    // Define quadratures
    qpoints_(0) = 0.;

    // Define weights
    weights_.at(0) = 2.;

  } else if (Tnquadratures == 2) {

    // Two point quadrature
    // Define quadratures
    qpoints_(0) = -0.57735026919;
    qpoints_(1) = 0.57735026919;

    // Define weights
    weights_.at(0) = 1.;
    weights_.at(1) = 1.;

  } else if (Tnquadratures == 3) {

    // Three point quadrature
    // Define quadratures
    qpoints_(0) = -0.7745966692;
    qpoints_(1) = 0.;
    qpoints_(2) = 0.7745966692;

    // Define weights
    weights_.at(0) = 0.5555555556;
    weights_.at(1) = 0.8888888889;
    weights_.at(2) = 0.5555555556;
  }
}
