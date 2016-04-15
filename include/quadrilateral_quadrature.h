#ifndef FELIB_QUADRILATERAL_QUADRATURE_H_
#define FELIB_QUADRILATERAL_QUADRATURE_H_

#include <eigen3/Eigen/Dense>

#include <vector>

#include "quadrature_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class QuadrilateralQuadrature;
}

// Quadrilateral quadrature class derived from quadrature base class
//! \brief Quadrature points for a quadrilateral element
//! \tparam Tdim Dimension
//! \tparam Tnquadratures number of quadratures
template <unsigned Tdim, unsigned Tnquadratures>
class felib::QuadrilateralQuadrature
    : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  // Default constructor
  QuadrilateralQuadrature();

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#include "quadrilateral_quadrature.tcc"

#endif  // FELIB_QUADRILATERAL_QUADRATURE_H_
