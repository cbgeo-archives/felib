#ifndef FELIB_LINESHAPE_H_
#define FELIB_LINESHAPE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "shapefun_base.h"

// Line shape function class derived from Shape Fun Base Class
//! \shape functions of the 1-D line element
//! \tparam Tdim Dimenstion
//! \tparam numFun number of shape functions
namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class LineShape;
}

template <unsigned Tdim, unsigned Tnfunctions>
class felib::LineShape : public felib::ShapeFunBase<Tdim, Tnfunctions> {

 public:
  // Evaluate shape functions
  //! \param[in] xi given local coordinates
  //! \param[out] sFun shape functions at given local coordinates
  void evaluate_shape_fun(const std::array<double, Tdim>& xi,
                          Eigen::Matrix<double, Tnfunctions, 1>& sFun);

  // Evaluate gradient of shape functions in local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] gradSfun local gradients of shape functions
  void evaluate_grad_shape_fun(
     const std::array<double, Tdim>& xi,
     Eigen::Matrix<double, Tnfunctions, Tdim>& gradSfun);

  // Give quadratue points (number is similar to Tnfunctions)
  //! \param[out] qpoints local coordinates of quadrature points
  void quadrature_points(Eigen::Matrix<double, Tnfunctions, Tdim>& qpoints);

  // Give quadrature points in local coordinates
  //! \tparam nquadratures number of quadrature points
  //! \param[out] qpoints local coordinates of quadrature points
  template <unsigned nquadratures>
  void custom_quadrature_points(Eigen::Matrix<double, nquadratures, Tdim>& qpoints);
};

#include "line_shape.tcc"

#endif  // FELIB_LINESHAPE_H_
