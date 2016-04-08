#ifndef FELIB_QUADRILATERALSHAPE_H_
#define FELIB_QUADRILATERALSHAPE_H_

#include <eigen3/Eigen/Dense>

#include <array>
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
  // Default constructor
  QuadrilateralShape() : felib::ShapeFunBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 2, "Invalid dimension for a quadrilateral element");
    static_assert((Tnfunctions == 4 || Tnfunctions == 8 || Tnfunctions == 9),
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
};

#include "quadrilateral_shape.tcc"

#endif // FELIB_QUADRILATERALSHAPE_H_
