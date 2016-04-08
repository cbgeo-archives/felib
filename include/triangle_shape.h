#ifndef FELIB_TRIANGLESHAPE_H_
#define FELIB_TRIANGLESHAPE_H_

#include <eigen3/Eigen/Dense>

#include <array>
#include <iostream>
#include <vector>

#include "shapefun_base.h"

// Triangle shape function class derived from Shape Fun Base Class
//! \shape functions of the triangle element
//! \tparam Tdim Dimenstion
//! \tparam Tnfunctions number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned Tnfunctions> 
  class TriangleShape;
}

template <unsigned Tdim, unsigned Tnfunctions> 
class felib::TriangleShape : public felib::ShapeFunBase<Tdim, Tnfunctions > {

public:
  // Default constructor
  TriangleShape() : felib::ShapeFunBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 2, "Invalid dimension for a triangle element");
    static_assert((Tnfunctions == 3 || Tnfunctions == 6),
                  "Invalid shape functions for a quadirlateral element");
  }
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

  // Give quadrature points in local coordinates (p x p rule)
  //! param[in] nquadratures number of quadrature points
  //! param[out] weights value of each qpoints weight
  template<unsigned nquadratures>
  void custom_quadrature_weights(std::array<double, nquadratures> &qweights);

};

#include "triangle_shape.tcc"

#endif // FELIB_TRIANGLESHAPE_H_
