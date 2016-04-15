template <unsigned Tdim, unsigned Tnquadratures>
felib::TriangleQuadrature<Tdim, Tnquadratures>::TriangleQuadrature()
    : felib::QuadratureBase<Tdim, Tnquadratures>() {
  
  static_assert(Tdim == 2, "Invalid dimension for a triangle element");
  static_assert((Tnquadratures == 1) || (Tnquadratures == 3) ,
                "Invalid number of quadratures");

  if (Tnquadratures == 1) {
    // Define quadratures
    const double Val_1_by_3 = 1./3.;
    
    qpoints_(0, 0) = Val_1_by_3;
    qpoints_(0, 1) = Val_1_by_3;

    weights_.at(0) = 0.5;
    
  } else if (Tnquadratures == 3) {
    // Define quadratures
    const double Val_2_by_3 = 2./3.;
    const double Val_1_by_6 = 1./6.;
    
    qpoints_(0, 0) = Val_2_by_3;
    qpoints_(0, 1) = Val_1_by_6;
    
    qpoints_(1, 0) = Val_1_by_6;
    qpoints_(1, 1) = Val_1_by_6;
    
    qpoints_(2, 0) = Val_1_by_6;
    qpoints_(2, 1) = Val_2_by_3;
    

    weights_.at(0) = Val_1_by_3;
    weights_.at(1) = Val_1_by_3;
    weights_.at(2) = Val_1_by_3;

    
    
  } 


    
}
