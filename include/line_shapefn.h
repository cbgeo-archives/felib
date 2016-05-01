#ifndef FELIB_LINESHAPEFN_H_
#define FELIB_LINESHAPEFN_H_

#include <array>
#include <iostream>
#include <vector>

#include <eigen3/Eigen/Dense>

#include "shapefn_base.h"

// Line shape function class derived from shape function base class
//! \brief Shape functions for a 1-D line element
//! \tparam Tdim Dimension
//! \tparam Tnfunctions Number of shape functions
namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class LineShapeFn;
}

template <unsigned Tdim, unsigned Tnfunctions>
class felib::LineShapeFn : public felib::ShapeFnBase<Tdim, Tnfunctions> {

 public:
  // Default constructor
  LineShapeFn() : felib::ShapeFnBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 1, "Invalid dimension for a 1D element");
    static_assert((Tnfunctions == 2 || Tnfunctions == 3),
                  "Invalid shape functions for a 1D element");
  }
  // Evaluate the shape functions
  //! \param[in] xi given local coordinates
  //! \param[out] shape_fn_ shape functions at given local coordinates
  Eigen::Matrix<double, Tnfunctions, 1> shapefn(
      const std::array<double, Tdim>& xi);

  // Evaluate the gradient of shape functions in local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] grad_shapefn_ local gradients of shape functions
  Eigen::Matrix<double, Tnfunctions, Tdim> grad_shapefn(
      const std::array<double, Tdim>& xi);
};

#include "line_shapefn.tcc"

#endif  // FELIB_LINESHAPEFN_H_
