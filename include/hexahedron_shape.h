#ifndef FELIB_HEXAHEDRONSHAPE_H_
#define FELIB_HEXAHEDRONSHAPE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "shapefun_base.h"

// Hexahedron shape function class derived from Shape Fun Base Class
//! \shape functions of the 3-D brick element
//! \tparam Tdim Dimenstion
//! \tparam Tnfunctions number of shape functions
namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class HexahedronShape;
}

template <unsigned Tdim, unsigned Tnfunctions>
class felib::HexahedronShape : public felib::ShapeFunBase<Tdim, Tnfunctions> {

 public:
  
  // Default constructor
  HexahedronShape() : felib::ShapeFunBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 3, "Invalid dimension for a hexahedron element");
    static_assert((Tnfunctions == 8 || Tnfunctions == 20),
                  "Invalid shape functions for a hexahedron element");
  }
  
  // Evaluate shape functions
  //! \param[in] xi given local coordinates
  //! \param[out] shape_fun shape functions at given local coordinates
  Eigen::Matrix<double, Tnfunctions, 1> evaluate_shape_fun(
      const std::array<double, Tdim>& xi);

  // Evaluate gradient of shape functions in local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] gradSfun local gradients of shape functions
  Eigen::Matrix<double, Tnfunctions, Tdim> evaluate_grad_shape_fun(
      const std::array<double, Tdim>& xi);

  // Give quadratue points (number is similar to Tnfunctions)
  //! \param[out] qpoints local coordinates of quadrature points
  Eigen::Matrix<double, Tnfunctions, Tdim> quadrature_points();

  // Give quadrature points in local coordinates
  //! \tparam nquadratures number of quadrature points
  //! \param[out] qpoints local coordinates of quadrature points
  template <unsigned nquadratures>
  void custom_quadrature_points(
      Eigen::Matrix<double, nquadratures, Tdim>& qpoints);
};

#include "hexahedron_shape.tcc"

#endif  // FELIB_HEXAHEDRONSHAPE_H_
