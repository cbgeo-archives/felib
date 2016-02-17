#ifndef FELIB_SRC_SHAPEFUN_BASE_H_
#define FELIB_SRC_SHAPEFUN_BASE_H_

#include <iostream>
#include <array>
#include <vector>

namespace felib {
  template <unsigned Tdim, unsigned numFun> class ShapeFunBase;
}

// Shape Functions Base Class
//! \brief Base Class that stores the information about shape
//! \tparam Tdim Dimension
//! \tparam numFun number of shape functions (equivalent to the number of nodes)
template <unsigned Tdim, unsigned numFun> class felib::ShapeFunBase {
public:
  //! Constructor

  //! Destructor
  virtual ~ShapeFunBase() {};

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  virtual void evaluateShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &sFun) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  virtual void evaluateGradShapeFun(const std::array<double, Tdim> &xi, std::array<std::array<double, numFun>, Tdim> &gradSfun) = 0;

  //! Evaluate Jacobian matrix
  virtual void evaluateJacobian() = 0;

  //! Give quadrature points
  virtual void quadraturePoints() = 0;

};

#endif // FELIB_SRC_SHAPEFUN_BASE_H_
