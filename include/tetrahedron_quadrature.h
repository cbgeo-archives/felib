#ifndef FELIB_TETRAHEDRON_QUADRATURE_H_
#define FELIB_TETRAHEDRON_QUADRATURE_H_

#include <vector>

#include <Eigen/Dense>

#include "quadrature_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class TetrahedronQuadrature;
}

// Tetrahedron quadrature class derived from quadrature base class
//! Quadrature points for a tetrahedron element
//! \tparam Tdim Dimenstion
//! \tparam Tnquadratures number of quadratures
template <unsigned Tdim, unsigned Tnquadratures>
class felib::TetrahedronQuadrature
    : public felib::QuadratureBase<Tdim, Tnquadratures> {

 public:
  TetrahedronQuadrature();

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#include "tetrahedron_quadrature.tcc"

#endif  // FELIB_TETRAHEDRON_QUADRATURE_H_
