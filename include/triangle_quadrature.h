#ifndef FELIB_TRIANGLE_QUADRATURE_H_
#define FELIB_TRIANGLE_QUADRATURE_H_

#include <eigen3/Eigen/Dense>

#include <vector>

#include "quadrature_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class TriangleQuadrature;
}

// Triangle quadrature class derived from quadrature base class
//! \brief Quadrature points for a triangle element
//! \tparam Tdim Dimension
//! \tparam Tnquadratures number of quadratures
template <unsigned Tdim, unsigned Tnquadratures>
class felib::TriangleQuadrature
    : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  // Default constructor
  TriangleQuadrature();

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#include "triangle_quadrature.tcc"

#endif  // FELIB_TRIANGLE_QUADRATURE_H_
