#ifndef FELIB_LINESHAPE_H_
#define FELIB_LINESHAPE_H_

#include <iostream>
#include <array>
#include <vector>

#include "shapefun_base.h"

//! \brief Line shape function class derived from Shape Fun Base Class
//! \shape functions of the line element
//! \tparam Tdim Dimenstion
//! \tparam numFun number of shape functions
namespace felib {
template <unsigned Tdim, unsigned numFun> class LineShape;
}

template <unsigned Tdim, unsigned numFun>
class felib::LineShape
    : public felib::ShapeFunBase<unsigned Tdim, unsigned numFun> {

  void evaluate_shape_fun(const std::array<double, Tdim> &xi,
                          std::array<double, numFun> &sFun);

  void evaluate_grad_shape_fun(
      const std::array<double, Tdim> &xi,
      std::array<std::array<double, numFun>, Tdim> &gradSfun);

  void evaluate_jacobian();

  void quadrature_points();
};

#include "line_shape.tcc"

#endif // FELIB_LINESHAPE_H_
