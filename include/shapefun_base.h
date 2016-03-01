#ifndef FELIB_SHAPEFUN_BASE_H_
#define FELIB_SHAPEFUN_BASE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class ShapeFunBase;
}

// Shape Functions Base Class
//! \brief Base Class that stores the information about shape functions
//! \tparam Tdim Dimension
//! \tparam Tnfunctions number of shape functions (both Lagrange and Hermitian
//! Interpolation)
template <unsigned Tdim, unsigned Tnfunctions>
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
      Eigen::Matrix<double, Tnfunctions, 1>& sFun) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \param[in|out] gradSfun local gradients of shape functions
  virtual void evaluate_grad_shape_fun(
      const std::array<double, Tdim>& xi,
      Eigen::Matrix<double, Tnfunctions, Tdim>& gradSfun) = 0;

  //! Give quadrature points (number is equal to Tnfunctions)
  //! \param[in|out] qpoints local coordinates of quadrature points
  virtual void quadrature_points(
      Eigen::Matrix<double, Tnfunctions, Tdim>& qpoints) = 0;
  
};

#endif  // FELIB_SHAPEFUN_BASE_H_
