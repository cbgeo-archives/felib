template <unsigned Tdim, unsigned Tnquadratures>
felib::TetrahedronQuadrature<Tdim, Tnquadratures>::TetrahedronQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {
  
  static_assert(Tdim == 3, "Invalid dimension for a 1D element");
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
    const double a = 0.138197;
    const double b = 0.585410;
    const double w = 0.0416667;

    qpoints_(0, 0) = a;
    qpoints_(0, 1) = a;
    qpoints_(0, 2) = a;
    qpoints_(1, 0) = b;
    qpoints_(1, 1) = a;
    qpoints_(1, 2) = a;
    qpoints_(2, 0) = a;
    qpoints_(2, 1) = b;
    qpoints_(2, 2) = a;
    qpoints_(3, 0) = a;
    qpoints_(3, 1) = a;
    qpoints_(3, 2) = b;

    weights_.at(0) = w;
    weights_.at(1) = w;
    weights_.at(2) = w;
    weights_.at(3) = w;
    
  } else if (Tnquadratures == 5) {

    const double x = 0.1666666666666667;
    
    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;
    
    qpoints_(1, 0) = x;
    qpoints_(1, 1) = x;
    qpoints_(1, 2) = x;

    qpoints_(2, 0) = 0.5;
    qpoints_(2, 1) = x;
    qpoints_(2, 2) = x;

    qpoints_(3, 0) = x;
    qpoints_(3, 1) = 0.5;
    qpoints_(3, 2) = x;

    qpoints_(4, 0) = x;
    qpoints_(4, 1) = x;
    qpoints_(4, 2) = 0.5;

    weights_.at(0) = 0.075;
    weights_.at(1) = 0.075;
    weights_.at(2) = 0.075;
    weights_.at(3) = 0.075;
    weights_.at(4) = 0.075;

  } else if (Tnquadratures == 11) {
    
    const double u = 0.0714286;
    const double v = 0.785714;

    const double x = 0.100596;
    const double y = 0.399404;

    const double w0 = -0.0131556;
    const double w1 = 0.00762222;
    const double w2 = 0.0248889;

    qpoints_(0, 0) = 0.25;
    qpoints_(0, 1) = 0.25;
    qpoints_(0, 2) = 0.25;

    qpoints_(1, 0) = u;
    qpoints_(1, 1) = u;
    qpoints_(1, 2) = u;

    qpoints_(2, 0) = v;
    qpoints_(2, 1) = u;
    qpoints_(2, 2) = u;

    qpoints_(3, 0) = u;
    qpoints_(3, 1) = v;
    qpoints_(3, 2) = u;

    qpoints_(4, 0) = u;
    qpoints_(4, 1) = u;
    qpoints_(4, 2) = v;

    
    qpoints_(5, 0) = y;
    qpoints_(5, 1) = y;
    qpoints_(5, 2) = x;

    qpoints_(6, 0) = y;
    qpoints_(6, 1) = x;
    qpoints_(6, 2) = x;

    qpoints_(7, 0) = x;
    qpoints_(7, 1) = y;
    qpoints_(7, 2) = x;

    qpoints_(8, 0) = x;
    qpoints_(8, 1) = x;
    qpoints_(8, 2) = y;

    qpoints_(9, 0) = y;
    qpoints_(9, 1) = x;
    qpoints_(9, 2) = y;

    qpoints_(10, 0) = x;
    qpoints_(10, 1) = y;
    qpoints_(10, 2) = y;

    // Weights
    weights_.at(0) = w0;
    weights_.at(1) = w1;
    weights_.at(2) = w1;
    weights_.at(3) = w1;
    weights_.at(4) = w1;
    weights_.at(5) = w2;
    weights_.at(6) = w2;
    weights_.at(7) = w2;
    weights_.at(8) = w2;
    weights_.at(9) = w2;
    weights_.at(10) = w2;
  }
}
