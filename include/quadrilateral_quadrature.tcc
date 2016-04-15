template <unsigned Tdim, unsigned Tnquadratures>
felib::QuadrilateralQuadrature<Tdim, Tnquadratures>::QuadrilateralQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {
  
  static_assert(Tdim == 2, "Invalid dimension for a tetrahedron element");
  static_assert((Tnquadratures == 1) || (Tnquadratures == 4) ||
                    (Tnquadratures == 9),
                "Invalid number of quadratures");

  if (Tnquadratures == 1) {
    // Define quadratures
    qpoints_(0, 0) = 0.;
    qpoints_(0, 1) = 0.;

    weights_.at(0) = 8.;
    
  } else if (Tnquadratures == 4) {
    // Define quadratures
    const double A = 0.577350;
    const double W = 1.;

    qpoints_(0, 0) = -A;
    qpoints_(0, 1) = -A;
    qpoints_(1, 0) =  A;
    qpoints_(1, 1) = -A;
    qpoints_(2, 0) =  A;
    qpoints_(2, 1) =  A;
    qpoints_(3, 0) = -A;
    qpoints_(3, 1) =  A;

    weights_.at(0) = W;
    weights_.at(1) = W;
    weights_.at(2) = W;
    weights_.at(3) = W;
    
  } else if (Tnquadratures == 9) {

    const double A  = 0.774597;
    const double W1 = 0.308642;
    const double W2 = 0.493827;
    const double W3 = 0.790123;
    
    qpoints_(0, 0) = -A;
    qpoints_(0, 1) = -A;
    
    qpoints_(1, 0) =  A;
    qpoints_(1, 1) = -A;

    qpoints_(2, 0) =  A;
    qpoints_(2, 1) =  A;

    qpoints_(3, 0) = -A;
    qpoints_(3, 1) =  A;

    qpoints_(4, 0) =  0;
    qpoints_(4, 1) = -A;

    qpoints_(5, 0) =  A;
    qpoints_(5, 1) =  0;
    
    qpoints_(6, 0) =  0;
    qpoints_(6, 1) =  A;

    qpoints_(7, 0) = -A;
    qpoints_(7, 1) =  0;

    qpoints_(8, 0) =  0;
    qpoints_(9, 1) =  0;

    
    weights_.at(0) = W1;
    weights_.at(1) = W1;
    weights_.at(2) = W1;
    weights_.at(3) = W1;
    weights_.at(4) = W2;
    weights_.at(5) = W2;
    weights_.at(6) = W2;
    weights_.at(7) = W2;
    weights_.at(8) = W3;

    }
}
