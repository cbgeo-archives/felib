#ifndef FELIB_SRC_LINESHAPE_H_
#define FELIB_SRC_LINESHAPE_H_

#include <iostream>
#include <array>
#include <vector>

#include "shapefun_base.h"

// Line shape function class derived from Shape Fun Base Class
//! \shape functions of the line element
//! \tparam Tdim Dimenstion
//! \tparam numFun number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned numFun> class LineShape;
}

template <unsigned Tdim, unsigned numFun> class felib::LineShape :
  public felib::ShapeFunBase <unsigned Tdim, unsigned numFun> {

  void evaluateShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &sFun);

  void evaluateGradShapeFun(const std::array<double, Tdim> &xi, std::array<std::array<double, numFun>, Tdim> &gradSfun);

  void evaluateJacobian();

  void quadraturePoints();

};

#include "lineShape.ipp"

#endif // FELIB_SRC_LINESHAPE_H_
