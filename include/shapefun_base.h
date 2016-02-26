#ifndef FELIB_SHAPEFUN_BASE_H_
#define FELIB_SHAPEFUN_BASE_H_

#include <iostream>
#include <array>
#include <vector>
#include <Eigen/Dense>

namespace felib {
template <unsigned Tdim, unsigned numFun>
class ShapeFunBase;
}

// Shape Functions Base Class
//! \brief Base Class that stores the information about shape functions
//! \tparam Tdim Dimension
//! \tparam numFun number of shape functions (both Lagrange and Hermitian
//! Interpolation)
template <unsigned Tdim, unsigned numFun>
class felib::ShapeFunBase {
 public:
  //! Default constructor do nothing
  ShapeFunBase(){};

  //! Destructor
  virtual ~ShapeFunBase(){};

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] sFun shape functions
  virtual void evaluate_shape_fun(const std::array<double, Tdim>& xi,
                                  Eigen::Matrix<double, 1, numFun>& sFun) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \param[out] gradSfun local gradients of shape functions
  virtual void evaluate_grad_shape_fun(
      const std::array<double, Tdim>& xi,
      Eigen::Matrix<double, Tdim, numFun>& gradSfun) = 0;

  //! Evaluate Jacobian matrix
  virtual void evaluate_jacobian() = 0;

  // Give quadrature points in local coordinates
  //! param[in] p number of quadrature points
  //! \param[out] qpoints local coordinates of quadrature points
  // template <unsigned p>
  // void quadrature_points(Eigen::Matrix<double, Tdim, p>& qpoints);
};

#endif  // FELIB_SHAPEFUN_BASE_H_
