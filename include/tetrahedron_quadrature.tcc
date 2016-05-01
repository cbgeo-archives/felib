// Quadratures: http://me.rice.edu/~akin/Elsevier/Chap_10.pdf

template <unsigned Tdim, unsigned Tnquadratures>
felib::TetrahedronQuadrature<Tdim, Tnquadratures>::TetrahedronQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {

  static_assert(Tdim == 3, "Invalid dimension for a tetrahedron element");
  static_assert((Tnquadratures == 1) || (Tnquadratures == 4) ||
                    (Tnquadratures == 5) || (Tnquadratures == 11),
                "Invalid number of quadratures");

  if (Tnquadratures == 1) {
    // Define quadratures
    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;

    weights_.at(0) = 1. / 6.;

  } else if (Tnquadratures == 4) {
    // Define quadratures

    const double Qpoint_a =
        (5. + 3. * std::sqrt(5.)) / 20.;                 // (5 + 3 sqrt(5)) / 20
    const double Qpoint_b = (5. - std::sqrt(5)) / 20.0;  // (5 - sqrt(5)) / 20

    const double Weight = 1. / 24.;

    qpoints_(0, 0) = Qpoint_a;
    qpoints_(0, 1) = Qpoint_b;
    qpoints_(0, 2) = Qpoint_b;

    qpoints_(1, 0) = Qpoint_b;
    qpoints_(1, 1) = Qpoint_a;
    qpoints_(1, 2) = Qpoint_b;

    qpoints_(2, 0) = Qpoint_b;
    qpoints_(2, 1) = Qpoint_b;
    qpoints_(2, 2) = Qpoint_a;

    qpoints_(3, 0) = Qpoint_b;
    qpoints_(3, 1) = Qpoint_b;
    qpoints_(3, 2) = Qpoint_b;

    weights_.at(0) = Weight;
    weights_.at(1) = Weight;
    weights_.at(2) = Weight;
    weights_.at(3) = Weight;

  } else if (Tnquadratures == 5) {

    const double Qpoint_a = 1. / 6.;

    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;

    qpoints_(1, 0) = 0.5;
    qpoints_(1, 1) = Qpoint_a;
    qpoints_(1, 2) = Qpoint_a;

    qpoints_(2, 0) = Qpoint_a;
    qpoints_(2, 1) = 0.5;
    qpoints_(2, 2) = Qpoint_a;

    qpoints_(3, 0) = Qpoint_a;
    qpoints_(3, 1) = Qpoint_a;
    qpoints_(3, 2) = 0.5;

    qpoints_(4, 0) = Qpoint_a;
    qpoints_(4, 1) = Qpoint_a;
    qpoints_(4, 2) = Qpoint_a;

    weights_.at(0) = -2. / 15.;
    weights_.at(1) = 3. / 40.;
    weights_.at(2) = 3. / 40.;
    weights_.at(3) = 3. / 40.;
    weights_.at(4) = 3. / 40.;

  } else if (Tnquadratures == 11) {

    const double Qpoint_a = (1. + std::sqrt(5. / 14.)) / 4.;
    const double Qpoint_b = (1. - std::sqrt(5. / 14.)) / 4.;

    const double W0 = -74. / 5625.;
    const double W1 = 343. / 45000.;
    const double W2 = 56. / 2250.;

    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;

    qpoints_(1, 0) = 11. / 14.;
    qpoints_(1, 1) = 1. / 14.;
    qpoints_(1, 2) = 1. / 14.;

    qpoints_(2, 0) = 1. / 14.;
    qpoints_(2, 1) = 11. / 14.;
    qpoints_(2, 2) = 1. / 14.;

    qpoints_(3, 0) = 1. / 14.;
    qpoints_(3, 1) = 1. / 14.;
    qpoints_(3, 2) = 11. / 14.;

    qpoints_(4, 0) = 1. / 14.;
    qpoints_(4, 1) = 1. / 14.;
    qpoints_(4, 2) = 1. / 14.;

    qpoints_(5, 0) = Qpoint_a;
    qpoints_(5, 1) = Qpoint_a;
    qpoints_(5, 2) = Qpoint_b;

    qpoints_(6, 0) = Qpoint_a;
    qpoints_(6, 1) = Qpoint_b;
    qpoints_(6, 2) = Qpoint_a;

    qpoints_(7, 0) = Qpoint_a;
    qpoints_(7, 1) = Qpoint_b;
    qpoints_(7, 2) = Qpoint_b;

    qpoints_(8, 0) = Qpoint_b;
    qpoints_(8, 1) = Qpoint_a;
    qpoints_(8, 2) = Qpoint_a;

    qpoints_(9, 0) = Qpoint_b;
    qpoints_(9, 1) = Qpoint_a;
    qpoints_(9, 2) = Qpoint_b;

    qpoints_(10, 0) = Qpoint_b;
    qpoints_(10, 1) = Qpoint_b;
    qpoints_(10, 2) = Qpoint_a;

    // Weights
    weights_.at(0) = W0;
    weights_.at(1) = W1;
    weights_.at(2) = W1;
    weights_.at(3) = W1;
    weights_.at(4) = W1;
    weights_.at(5) = W2;
    weights_.at(6) = W2;
    weights_.at(7) = W2;
    weights_.at(8) = W2;
    weights_.at(9) = W2;
    weights_.at(10) = W2;
  }
}
