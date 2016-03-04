#ifndef FELIB_QUADRILATERALSHAPE_H_
#define FELIB_QUADRILATERALSHAPE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

#include "shapefun_base.h"

// Quadrilateral shape function class derived from Shape Fun Base Class
//! \shape functions of the quadrilateral element
//! \tparam Tdim Dimenstion
//! \tparam Tnfunctions number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned Tnfunctions> 
  class QuadrilateralShape;
}

template <unsigned Tdim, unsigned Tnfunctions> 
class felib::QuadrilateralShape : public felib::ShapeFunBase<Tdim, Tnfunctions > {

public:
  // Evaluate shape functions
  //! param[in] xi given local coordinates
  //! param[out] shape_fun shape functins at local coordinates xi
  Eigen::Matrix<double, Tnfunctions, 1> evaluate_shape_fun(
         const std::array<double, Tdim>& xi);

  // Evaluate local gradient of shape functions
  //! param[in] xi given local coordinates
  //! param[out] grad_sfun gradient of shape functions at local coordinates
  Eigen::Matrix<double, Tnfunctions, Tdim> evaluate_grad_shape_fun(
         const std::array<double, Tdim>& xi);

  // Give quadrature points (number is equal to Tnfunctions)
  //! \param[out] qpoints quadrature points in local coordinates
  Eigen::Matrix<double, Tnfunctions, Tdim> quadrature_points();

  // Give quadrature points in local coordinates (p x p rule)
  //! param[in] nquadratures number of quadrature points
  //! param[out] qpoints quadrature points in local coordinates
  template<unsigned nquadratures>
  void custom_quadrature_points(Eigen::Matrix<double, nquadratures, Tdim> &qpoints);

};

#include "quadrilateral_shape.tcc"

#endif // FELIB_QUADRILATERALSHAPE_H_
