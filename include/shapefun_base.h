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
  //! Constructor
  //! Assign variables to zero
  ShapeFunBase() {
    shape_fun = Eigen::Matrix<double, Tnfunctions, 1>::Zero();
    grad_sfun = Eigen::Matrix<double, Tnfunctions, Tdim>::Zero();
    qpoints = Eigen::Matrix<double, Tnfunctions, Tdim>::Zero();
  }

  //! Destructor
  virtual ~ShapeFunBase() {}

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] shape_fun shape functions
  virtual Eigen::Matrix<double, Tnfunctions, 1> evaluate_shape_fun(
      const std::array<double, Tdim>& xi) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \param[in|out] grad_sfun local gradients of shape functions
  virtual Eigen::Matrix<double, Tnfunctions, Tdim> evaluate_grad_shape_fun(
      const std::array<double, Tdim>& xi) = 0;

  //! Give quadrature points (number is equal to Tnfunctions)
  //! \param[out] qpoints local coordinates of quadrature points
  virtual Eigen::Matrix<double, Tnfunctions, Tdim> quadrature_points() = 0;

 protected:
  Eigen::Matrix<double, Tnfunctions, 1> shape_fun;
  Eigen::Matrix<double, Tnfunctions, Tdim> grad_sfun;
  Eigen::Matrix<double, Tnfunctions, Tdim> qpoints;
};

#endif  // FELIB_SHAPEFUN_BASE_H_
