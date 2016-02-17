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
//! \tparam numFun number of shape functions (both Lagrange and Hermitian Interpolation)
template <unsigned Tdim, unsigned numFun> class felib::ShapeFunBase {
public:
  //! Constructor

  //! Destructor
  virtual ~ShapeFunBase() {};

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  virtual void evaluate_shape_fun(const std::array<double, Tdim> &xi, std::array<double, numFun> &sFun) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  virtual void evaluate_grad_shape_fun(const std::array<double, Tdim> &xi, std::array<std::array<double, numFun>, Tdim> &gradSfun) = 0;

  //! Evaluate Jacobian matrix
  virtual void evaluate_jacobian() = 0;

  //! Give quadrature points
  virtual void quadrature_points() = 0;

};

#endif // FELIB_SRC_SHAPEFUN_BASE_H_
