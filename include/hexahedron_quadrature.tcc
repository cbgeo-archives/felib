// Default constructor
template <unsigned Tdim, unsigned Tnquadratures>
felib::HexahedronQuadrature<Tdim, Tnquadratures>::HexahedronQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {

  static_assert(Tdim == 3, "Invalid dimension for a 3D hexahedron element");
  static_assert(
      (Tnquadratures == 1) || (Tnquadratures == 8) || (Tnquadratures == 27),
      "Invalid number of quadratures");

  if (Tnquadratures == 1) {
    // Define quadratures
    qpoints_(0, 0) = 0.;
    qpoints_(0, 1) = 0.;
    qpoints_(0, 2) = 0.;

    weights_.at(0) = 8.;
    
  } else if (Tnquadratures == 8) {
    qpoints_(0, 0) = -0.57735;
    qpoints_(0, 1) = -0.57735;
    qpoints_(0, 2) = -0.57735;
    
    qpoints_(1, 0) = 0.57735;
    qpoints_(1, 1) = -0.57735;
    qpoints_(1, 2) = -0.57735;

    qpoints_(2, 0) = 0.57735;
    qpoints_(2, 1) = 0.57735;
    qpoints_(2, 2) = -0.57735;

    qpoints_(3, 0) = -0.57735;
    qpoints_(3, 1) = 0.57735;
    qpoints_(3, 2) = -0.57735;

    qpoints_(4, 0) = -0.57735;
    qpoints_(4, 1) = -0.57735;
    qpoints_(4, 2) = 0.57735;

    qpoints_(5, 0) = 0.57735;
    qpoints_(5, 1) = -0.57735;
    qpoints_(5, 2) = 0.57735;

    qpoints_(6, 0) = 0.57735;
    qpoints_(6, 1) = 0.57735;
    qpoints_(6, 2) = 0.57735;

    qpoints_(7, 0) = -0.57735;
    qpoints_(7, 1) = 0.57735;
    qpoints_(7, 2) = 0.57735;

    weights_.at(0) = 1.;
    weights_.at(1) = 1.;
    weights_.at(2) = 1.;
    weights_.at(3) = 1.;
    weights_.at(4) = 1.;
    weights_.at(5) = 1.;
    weights_.at(6) = 1.;
    weights_.at(7) = 1.;
    
  } else if (Tnquadratures == 27) {
    const double a = 0.774597;
    const double b = 0.555556;
    const double c = 0.888889;

    qpoints_(0, 0) = -a;
    qpoints_(0, 1) = -a;
    qpoints_(0, 2) = -a;
    
    qpoints_(1, 0) = -a;
    qpoints_(1, 1) = -a;
    qpoints_(1, 2) = 0.;

    qpoints_(2, 0) = -a;
    qpoints_(2, 1) = -a;
    qpoints_(2, 2) = a;

    qpoints_(3, 0) = -a;
    qpoints_(3, 1) = 0.;
    qpoints_(3, 2) = -a;

    qpoints_(4, 0) = -a;
    qpoints_(4, 1) = 0.;
    qpoints_(4, 2) = 0.;

    qpoints_(5, 0) = -a;
    qpoints_(5, 1) = 0.;
    qpoints_(5, 2) = a;

    qpoints_(6, 0) = -a;
    qpoints_(6, 1) = a;
    qpoints_(6, 2) = -a;

    qpoints_(7, 0) = -a;
    qpoints_(7, 1) = a;
    qpoints_(7, 2) = 0.;

    qpoints_(8, 0) = -a;
    qpoints_(8, 1) = a;
    qpoints_(8, 2) = a;

    qpoints_(9, 0) = 0.;
    qpoints_(9, 1) = -a;
    qpoints_(9, 2) = -a;

    qpoints_(10, 0) = 0.;
    qpoints_(10, 1) = -a;
    qpoints_(10, 2) = 0.;

    qpoints_(11, 0) = 0.;
    qpoints_(11, 1) = -a;
    qpoints_(11, 2) = a;

    qpoints_(12, 0) = 0.;
    qpoints_(12, 1) = 0.;
    qpoints_(12, 2) = -a;

    qpoints_(13, 0) = 0.;
    qpoints_(13, 1) = 0.;
    qpoints_(13, 2) = 0.;

    qpoints_(14, 0) = 0.;
    qpoints_(14, 1) = 0.;
    qpoints_(14, 2) = a;

    qpoints_(15, 0) = 0.;
    qpoints_(15, 1) = a;
    qpoints_(15, 2) = -a;

    qpoints_(16, 0) = 0.;
    qpoints_(16, 1) = a;
    qpoints_(16, 2) = 0.;

    qpoints_(17, 0) = 0.;
    qpoints_(17, 1) = a;
    qpoints_(17, 2) = a;

    qpoints_(18, 0) = a;
    qpoints_(18, 1) = -a;
    qpoints_(18, 2) = -a;

    qpoints_(19, 0) = a;
    qpoints_(19, 1) = -a;
    qpoints_(19, 2) = 0.;

    qpoints_(20, 0) = a;
    qpoints_(20, 1) = -a;
    qpoints_(20, 2) = a;

    qpoints_(21, 0) = a;
    qpoints_(21, 1) = 0.;
    qpoints_(21, 2) = -a;

    qpoints_(22, 0) = a;
    qpoints_(22, 1) = 0.;
    qpoints_(22, 2) = 0.;

    qpoints_(23, 0) = a;
    qpoints_(23, 1) = 0.;
    qpoints_(23, 2) = a;

    qpoints_(24, 0) = a;
    qpoints_(24, 1) = a;
    qpoints_(24, 2) = -a;

    qpoints_(25, 0) = a;
    qpoints_(25, 1) = a;
    qpoints_(25, 2) = 0.;

    qpoints_(26, 0) = a;
    qpoints_(26, 1) = a;
    qpoints_(26, 2) = a;

    // Weights
    weights_.at(0) = b * b * b;
    weights_.at(1) = b * b * c;
    weights_.at(2) = b * b * b;
    weights_.at(3) = b * b * c;
    weights_.at(4) = b * c * c;
    weights_.at(5) = b * b * c;
    weights_.at(6) = b * b * b;
    weights_.at(7) = b * b * c;
    weights_.at(8) = b * b * b;

    weights_.at(9) = b * b * c;
    weights_.at(10) = b * c * c;
    weights_.at(11) = b * b * c;
    weights_.at(12) = b * c * c;
    weights_.at(13) = c * c * c;
    weights_.at(14) = b * c * c;
    weights_.at(15) = b * b * c;
    weights_.at(16) = b * c * c;
    weights_.at(17) = b * b * c;

    weights_.at(18) = b * b * b;
    weights_.at(19) = b * b * c;
    weights_.at(20) = b * b * b;
    weights_.at(21) = b * b * c;
    weights_.at(22) = b * c * c;
    weights_.at(23) = b * b * c;
    weights_.at(24) = b * b * b;
    weights_.at(25) = b * b * c;
    weights_.at(26) = b * b * b;
  }
}
