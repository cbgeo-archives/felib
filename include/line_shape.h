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
template <unsigned Tdim, unsigned Nfunctions>
class LineShape;
}

template <unsigned Tdim, unsigned Nfunctions>
class felib::LineShape : public felib::ShapeFunBase<Tdim, Nfunctions> {

 public:
  // Evaluate shape functions
  //! param[in] xi given local coordinates
  //! param[out] sFun shape functions at given local coordinates
  void evaluate_shape_fun(const std::array<double, Tdim>& xi,
                          Eigen::Matrix<double, Nfunctions, 1>& sFun);

  // Evaluate gradient of shape functions in local coordinates
  //! param[in] xi given local coordinates
  //! param[out] gradSfun local gradients of shape functions
  void evaluate_grad_shape_fun(
     const std::array<double, Tdim>& xi,
     Eigen::Matrix<double, Nfunctions, Tdim>& gradSfun);

  // Give quadratue points (number is similar to Nfunctions)
  //! \param[out] qpoints local coordinates of quadrature points
  void quadrature_points(Eigen::Matrix<double, Nfunctions, Tdim>& qpoints);

  // Give quadrature points in local coordinates
  //! param[in] p number of quadrature points
  //! param[out] qpoints local coordinates of quadrature points
  template <unsigned p>
  void custom_quadrature_points(Eigen::Matrix<double, p, Tdim>& qpoints);
};

#include "line_shape.tcc"

#endif  // FELIB_LINESHAPE_H_
