#ifndef FELIB_HEXAHEDRON_QUADRATURE_H_
#define FELIB_HEXAHEDRON_QUADRATURE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "quadrature_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnquadratures>
class HexahedronQuadrature;
}

// Hexahedron quadrature class derived from quadrature base class
//! \brief Quadrature points for a hexahedron element
//! \tparam Tdim Dimension
//! \tparam Tnquadratures number of quadratures
template <unsigned Tdim, unsigned Tnquadratures>
class felib::HexahedronQuadrature
    : public felib::QuadratureBase<Tdim, Tnquadratures> {
 public:
  HexahedronQuadrature();

 private:
  using QuadratureBase<Tdim, Tnquadratures>::qpoints_;
  using QuadratureBase<Tdim, Tnquadratures>::weights_;
};

#include "hexahedron_quadrature.tcc"

#endif  // FELIB_HEXAHEDRON_QUADRATURE_H_
