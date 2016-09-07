#ifndef FELIB_TIANGLESHAPEFN_H_
#define FELIB_TIANGLESHAPEFN_H_

#include <array>
#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "shapefn_base.h"

// Triangle shape function class derived from ShapeFnBase class
//! \brief shape functions of the triangle element
//! \tparam Tdim Dimension
//! \tparam Tnfunctions Number of shape functions
namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class TriangleShapeFn;
}

template <unsigned Tdim, unsigned Tnfunctions>
class felib::TriangleShapeFn : public felib::ShapeFnBase<Tdim, Tnfunctions> {

 public:
  // Default constructor
  TriangleShapeFn() : felib::ShapeFnBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 2, "Invalid dimension for a triangle element");
    static_assert((Tnfunctions == 3 || Tnfunctions == 6),
                  "Invalid shape functions for a quadirlateral element");
  }

  //! Evaluate the shape functions
  //! \param[in] xi Local coordinates
  //! \param[out] shapefn_ Shape functions at the given local coordinates
  Eigen::Matrix<double, Tnfunctions, 1> shapefn(
      const std::array<double, Tdim>& xi);

  //! Evaluate the gradient of shape functions in local coordinates
  //! \param[in] xi Local coordinates
  //! \param[out] grad_shapefn_ Local gradients of shape functions
  Eigen::Matrix<double, Tnfunctions, Tdim> grad_shapefn(
      const std::array<double, Tdim>& xi);
};

#include "triangle_shapefn.tcc"

#endif  // FELIB_TIANGLESHAPEFN_H_
