#ifndef FELIB_SHAPEFUN_BASE_H_
#define FELIB_SHAPEFUN_BASE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

namespace felib {
template <unsigned Tdim, unsigned Nfunctions>
class ShapeFunBase;
}

// Shape Functions Base Class
//! \brief Base Class that stores the information about shape functions
//! \tparam Tdim Dimension
//! \tparam Nfunctions number of shape functions (both Lagrange and Hermitian
//! Interpolation)
template <unsigned Tdim, unsigned Nfunctions>
class felib::ShapeFunBase {
 public:
  //! Default constructor do nothing
  ShapeFunBase(){};

  //! Destructor
  virtual ~ShapeFunBase(){};

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] sFun shape functions
  virtual void evaluate_shape_fun(
      const std::array<double, Tdim>& xi,
      Eigen::Matrix<double, Nfunctions, 1>& sFun) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \param[out] gradSfun local gradients of shape functions
  virtual void evaluate_grad_shape_fun(
      const std::array<double, Tdim>& xi,
      Eigen::Matrix<double, Nfunctions, Tdim>& gradSfun) = 0;

  //! Give quadrature points (number is equal to Nfunctions)
  //! \param[out] qpoints local coordinates of quadrature points
  virtual void quadrature_points(
      Eigen::Matrix<double, Nfunctions, Tdim>& qpoints) = 0;
  
};

#endif  // FELIB_SHAPEFUN_BASE_H_
