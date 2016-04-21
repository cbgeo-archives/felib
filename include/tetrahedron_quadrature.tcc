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

    weights_.at(0) = 0.166667;
    
  } else if (Tnquadratures == 4) {
    // Define quadratures
    const double A = 0.138197;
    const double B = 0.585410;
    const double W = 0.0416667;

    qpoints_(0, 0) = A;
    qpoints_(0, 1) = A;
    qpoints_(0, 2) = A;
    qpoints_(1, 0) = B;
    qpoints_(1, 1) = A;
    qpoints_(1, 2) = A;
    qpoints_(2, 0) = A;
    qpoints_(2, 1) = B;
    qpoints_(2, 2) = A;
    qpoints_(3, 0) = A;
    qpoints_(3, 1) = A;
    qpoints_(3, 2) = B;

    weights_.at(0) = W;
    weights_.at(1) = W;
    weights_.at(2) = W;
    weights_.at(3) = W;
    
  } else if (Tnquadratures == 5) {

    const double A = 0.1666666666666667;
    
    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;
    
    qpoints_(1, 0) = A;
    qpoints_(1, 1) = A;
    qpoints_(1, 2) = A;

    qpoints_(2, 0) = 0.5;
    qpoints_(2, 1) = A;
    qpoints_(2, 2) = A;

    qpoints_(3, 0) = A;
    qpoints_(3, 1) = 0.5;
    qpoints_(3, 2) = A;

    qpoints_(4, 0) = A;
    qpoints_(4, 1) = A;
    qpoints_(4, 2) = 0.5;

    weights_.at(0) = 0.075;
    weights_.at(1) = 0.075;
    weights_.at(2) = 0.075;
    weights_.at(3) = 0.075;
    weights_.at(4) = 0.075;

  } else if (Tnquadratures == 11) {
    
    const double A = 0.0714286;
    const double B = 0.785714;

    const double C = 0.100596;
    const double D = 0.399404;

    const double W0 = -0.0131556;
    const double W1 = 0.00762222;
    const double W2 = 0.0248889;

    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;

    qpoints_(1, 0) = A;
    qpoints_(1, 1) = A;
    qpoints_(1, 2) = A;

    qpoints_(2, 0) = B;
    qpoints_(2, 1) = A;
    qpoints_(2, 2) = A;

    qpoints_(3, 0) = A;
    qpoints_(3, 1) = B;
    qpoints_(3, 2) = A;

    qpoints_(4, 0) = A;
    qpoints_(4, 1) = A;
    qpoints_(4, 2) = B;

    
    qpoints_(5, 0) = D;
    qpoints_(5, 1) = D;
    qpoints_(5, 2) = C;

    qpoints_(6, 0) = D;
    qpoints_(6, 1) = C;
    qpoints_(6, 2) = C;

    qpoints_(7, 0) = C;
    qpoints_(7, 1) = D;
    qpoints_(7, 2) = C;

    qpoints_(8, 0) = C;
    qpoints_(8, 1) = C;
    qpoints_(8, 2) = D;

    qpoints_(9, 0) = D;
    qpoints_(9, 1) = C;
    qpoints_(9, 2) = D;

    qpoints_(10, 0) = C;
    qpoints_(10, 1) = D;
    qpoints_(10, 2) = D;

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
