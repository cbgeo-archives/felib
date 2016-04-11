#ifndef FELIB_QUADRILATERALSHAPEFN_H_
#define FELIB_QUADRILATERALSHAPEFN_H_

#include <eigen3/Eigen/Dense>

#include <array>
#include <iostream>
#include <vector>

#include "shapefn_base.h"

//! Quadrilateral shape function class derived from ShapeFnBase class
//! \brief Shape functions of a quadrilateral element
//! \tparam Tdim Dimension
//! \tparam Tnfunctions Number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned Tnfunctions> 
  class QuadrilateralShapeFn;
}

template <unsigned Tdim, unsigned Tnfunctions> 
class felib::QuadrilateralShapeFn : public felib::ShapeFnBase<Tdim, Tnfunctions > {

public:
  //! Default constructor
  QuadrilateralShapeFn() : felib::ShapeFnBase<Tdim, Tnfunctions>() {
    static_assert(Tdim == 2, "Invalid dimension for a quadrilateral element");
    static_assert((Tnfunctions == 4 || Tnfunctions == 8 || Tnfunctions == 9),
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

#include "quadrilateral_shapefn.tcc"

#endif // FELIB_QUADRILATERALSHAPEFN_H_
