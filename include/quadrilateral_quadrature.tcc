// Default constructor
template <unsigned Tdim, unsigned Tnquadratures>
felib::QuadrilateralQuadrature<Tdim, Tnquadratures>::QuadrilateralQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {
  
  static_assert(Tdim == 2, "Invalid dimension for a quadrilateral element");
  static_assert(
      (Tnquadratures == 1) || (Tnquadratures == 4) || (Tnquadratures == 9),
      "Invalid number of quadratures");

  // Single point quadratures
  if (Tnquadratures == 1) {
    // Define quadratures
    qpoints_(0, 0) = 0.;
    qpoints_(0, 1) = 0.;

    // Define weights
    weights_.at(0) = 8.;

  } else if (Tnquadratures == 4) {
    // Four point quadrature

    // Define quadratures
    qpoints_(0, 0) = -0.577350;
    qpoints_(0, 1) = -0.577350;

    qpoints_(1, 0) = 0.577350;
    qpoints_(1, 1) = -0.577350;

    qpoints_(2, 0) = 0.577350;
    qpoints_(2, 1) = 0.577350;

    qpoints_(3, 0) = -0.577350;
    qpoints_(3, 1) = 0.577350;

    // Define weights
    weights_.at(0) = 1.;
    weights_.at(1) = 1.;
    weights_.at(2) = 1.;
    weights_.at(3) = 1.;

  } else if (Tnquadratures == 9) {
    // Nine point quadrature

    // Quadratures
    qpoints_(0, 0) = -0.774597;
    qpoints_(0, 1) = -0.774597;

    qpoints_(1, 0) = 0.774597;
    qpoints_(1, 1) = -0.774597;

    qpoints_(2, 0) = 0.774597;
    qpoints_(2, 1) = 0.774597;

    qpoints_(3, 0) = -0.774597;
    qpoints_(3, 1) = 0.774597;

    qpoints_(4, 0) = 0.000000;
    qpoints_(4, 1) = -0.774597;

    qpoints_(5, 0) = 0.774597;
    qpoints_(5, 1) = 0.000000;

    qpoints_(6, 0) = 0.000000;
    qpoints_(6, 1) = 0.774597;

    qpoints_(7, 0) = -0.774597;
    qpoints_(7, 1) = 0.000000;

    qpoints_(8, 0) = 0.;
    qpoints_(8, 1) = 0.;

    // Weights
    weights_.at(0) = 0.308642;
    weights_.at(1) = 0.308642;
    weights_.at(2) = 0.308642;
    weights_.at(3) = 0.308642;
    weights_.at(4) = 0.493827;
    weights_.at(5) = 0.493827;
    weights_.at(6) = 0.493827;
    weights_.at(7) = 0.493827;
    weights_.at(8) = 0.790123;
  }
}
