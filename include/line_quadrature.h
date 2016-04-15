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
  LineQuadrature();
  
 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#include "line_quadrature.tcc"

#endif  // FELIB_LINE_QUADRATURE_H_
