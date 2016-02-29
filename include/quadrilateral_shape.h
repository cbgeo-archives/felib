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
//! \tparam Nfunctions number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned Nfunctions> 
  class QuadrilateralShape;
}

template <unsigned Tdim, unsigned Nfunctions> 
class felib::QuadrilateralShape : public felib::ShapeFunBase<Tdim, Nfunctions > {

public:
  // Evaluate shape functions
  //! param[in] xi given local coordinates
  //! param[out] sFun shape functins at local coordinates xi
  void evaluate_shape_fun(const std::array<double, Tdim>& xi, 
                          Eigen::Matrix<double, Nfunctions, 1>& sFun);

  // Evaluate local gradient of shape functions
  //! param[in] xi given local coordinates
  //! param[out] gradSfun gradient of shape functions at local coordinates
  void evaluate_grad_shape_fun(
         const std::array<double, Tdim>& xi, 
         Eigen::Matrix<double, Nfunctions, Tdim>& gradSfun);

  // Give quadrature points (number is equal to Nfunctions)
  //! \param[out] qpoints quadrature points in local coordinates
  void quadrature_points(Eigen::Matrix<double, Nfunctions, Tdim>& qpoints);

  // Give quadrature points in local coordinates (p x p rule)
  //! param[in] p number of quadrature points
  //! param[out] qpoints quadrature points in local coordinates
  template<unsigned p>
  void custom_quadrature_points(Eigen::Matrix<double, p, Tdim> &qpoints);

};

#include "quadrilateral_shape.tcc"

#endif // FELIB_QUADRILATERALSHAPE_H_
