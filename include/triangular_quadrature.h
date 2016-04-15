#ifndef FELIB_TRIANGULARQUADRATURE_H_
#define FELIB_TRIANGULARQUADRATURE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "quadrature_base.h"

// Triangular quadrature class derived from quadrature base class
//! Triangular points for a quadrilateral element
//! \tparam Tdim Dimenstion
//! \tparam Tnquadratures number of quadratures


namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class TriangularQuadrature;
}

template <unsigned Tdim, unsigned Tnquadratures>
class felib::TriangularQuadrature : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  // Default constructor
  TriangularQuadrature() : felib::QuadratureBase<Tdim, Tnquadratures>() {
    static_assert(Tdim == 2, "Invalid dimension for a 1D element");
    static_assert( (Tnquadratures == 1)||(Tnquadratures == 3), "Invalid number of quadratures");

    // Define quadratures

    if (Tnquadratures == 1) {
    
    qpoints_(0,0) = 0;
    qpoints_(0,1) = 0;

    weights_(0) = 8.;

    }

    else if (Tnquadratures == 3) {
    
    qpoints_(0,0) =  0.666667;
    qpoints_(0,1) =  0.166667;
    
    qpoints_(1,0) =  0.166667;
    qpoints_(1,1) =  0.166667;

    qpoints_(2,0) =  0.166667;
    qpoints_(2,1) =  0.666667;

    weights_(0) = 0.333333;
    weights_(1) = 0.333333;
    weights_(2) = 0.333333;

    }

 
  }

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#endif  // FELIB_TRIANGULARQUADRATURE_H_
