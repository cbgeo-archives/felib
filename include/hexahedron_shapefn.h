#ifndef FELIB_HEXAHEDRONSHAPEFN_H_
#define FELIB_HEXAHEDRONSHAPEFN_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "shapefn_base.h"

//! Hexahedron shape function class derived from Shape Fun Base Class
//! \brief Shape functions of the 3-D brick element
//! \tparam Tdim Dimension
//! \tparam Tnfunctions Number of shape functions
namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class HexahedronShapeFn;
}

template <unsigned Tdim, unsigned Tnfunctions>
class felib::HexahedronShapeFn : public felib::ShapeFnBase<Tdim, Tnfunctions> {

 public:
  
  // Default constructor
  HexahedronShapeFn() : felib::ShapeFnBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 3, "Invalid dimension for a hexahedron element");
    static_assert((Tnfunctions == 8 || Tnfunctions == 20),
                  "Invalid shape functions for a hexahedron element");
  }
  
  // Evaluate shape functions
  //! \param[in] xi Local coordinates
  //! \param[out] shapefn_ Shape functions at the given local coordinates
  Eigen::Matrix<double, Tnfunctions, 1> shapefn(
      const std::array<double, Tdim>& xi);

  // Evaluate gradient of shape functions in local coordinates
  //! \param[in] xi Local coordinates
  //! \param[out] grad_shapefn_ Local gradients of shape functions
  Eigen::Matrix<double, Tnfunctions, Tdim> grad_shapefn(
      const std::array<double, Tdim>& xi);
};

#include "hexahedron_shapefn.tcc"

#endif  // FELIB_HEXAHEDRONSHAPEFN_H_
