#ifndef FELIB_QUADRILATERALQUADRATURE_H_
#define FELIB_QUADRILATERALQUADRATURE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "quadrature_base.h"

// Quadrilateral quadrature class derived from quadrature base class
//! Quadrature points for a quadrilateral element
//! \tparam Tdim Dimenstion
//! \tparam Tnquadratures number of quadratures


namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class QuadrilateralQuadrature;
}

template <unsigned Tdim, unsigned Tnquadratures>
class felib::QuadrilateralQuadrature : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  // Default constructor
  QuadrilateralQuadrature() : felib::QuadratureBase<Tdim, Tnquadratures>() {
    static_assert(Tdim == 2, "Invalid dimension for a 1D element");
    static_assert( (Tnquadratures == 1)||(Tnquadratures == 4)||(Tnquadratures == 9), "Invalid number of quadratures");

    // Define quadratures

    if (Tnquadratures == 1) {
    
    qpoints_(0,0) = 0;
    qpoints_(0,1) = 0;

    weights_(0) = 8.;

    }

    else if (Tnquadratures == 4) {
    
    qpoints_(0,0) = -0.577350;
    qpoints_(0,1) = -0.577350;
    
    qpoints_(1,0) =  0.577350;
    qpoints_(1,1) = -0.577350;

    qpoints_(2,0) =  0.577350;
    qpoints_(2,1) =  0.577350;
    
    qpoints_(3,0) = -0.577350;
    qpoints_(3,1) =  0.577350;

    weights_(0) = 1.;
    weights_(1) = 1.;
    weights_(2) = 1.;
    weights_(3) = 1.;

    }

    else if (Tnquadratures == 9) {

    qpoints_(0,0) = -0.774597;
    qpoints_(0,1) = -0.774597;
    
    qpoints_(1,0) =  0.774597;
    qpoints_(1,1) = -0.774597;

    qpoints_(2,0) =  0.774597;
    qpoints_(2,1) =  0.774597;
    
    qpoints_(3,0) = -0.774597;
    qpoints_(3,1) =  0.774597;

    qpoints_(4,0) =  0.000000;
    qpoints_(4,1) = -0.774597;
    
    qpoints_(5,0) =  0.774597;
    qpoints_(5,1) =  0.000000;

    qpoints_(6,0) =  0.000000;
    qpoints_(6,1) =  0.774597;
    
    qpoints_(7,0) = -0.774597;
    qpoints_(7,1) =  0.000000;

    qpoints_(8,0) =  0;
    qpoints_(8,1) =  0;

    weights_(0) = 0.308642;
    weights_(1) = 0.308642;
    weights_(2) = 0.308642;
    weights_(3) = 0.308642;
    weights_(4) = 0.493827;
    weights_(5) = 0.493827;
    weights_(6) = 0.493827;
    weights_(7) = 0.493827;
    weights_(8) = 0.790123;

    }

    
  }

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#endif  // FELIB_QUADRILATERALQUADRATURE_H_
