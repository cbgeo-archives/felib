#ifndef FELIB_LINE_QUADRATURE_H_
#define FELIB_LINE_QUADRATURE_H_

#include <eigen3/Eigen/Dense>

#include <vector>

#include "quadrature_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class LineQuadrature;
}

// Line quadrature class derived from quadrature base class
//! \brief Quadrature points for a line element
//! \tparam Tdim Dimenstion
//! \tparam Tnquadratures number of quadratures
template <unsigned Tdim, unsigned Tnquadratures>
class felib::LineQuadrature : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  // Default constructor
  LineQuadrature() : felib::QuadratureBase<Tdim, Tnquadratures>() {
    static_assert(Tdim == 1, "Invalid dimension for a 1D element");
    static_assert((Tnquadratures == 2), "Invalid number of quadratures");

    // Define quadratures
    qpoints_(0) = -0.577350;
    qpoints_(1) =  0.577350;

    weights_.at(0) = 1.;
    weights_.at(1) = 1.;
  }

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#endif  // FELIB_LINE_QUADRATURE_H_
