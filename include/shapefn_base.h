#ifndef FELIB_SHAPEFN_BASE_H_
#define FELIB_SHAPEFN_BASE_H_

#include <array>
#include <iostream>
#include <vector>

#include <eigen3/Eigen/Dense>

namespace felib {
template <unsigned Tdim, unsigned Tnfunctions>
class ShapeFnBase;
}

//! Base class of shape functions
//! \brief Base class that stores the information about shape functions
//! \tparam Tdim Dimension
//! \tparam Tnfunctions Number of shape functions

template <unsigned Tdim, unsigned Tnfunctions>
class felib::ShapeFnBase {
 public:
  //! Constructor
  //! Assign variables to zero
  ShapeFnBase() {
    shapefn_ = Eigen::Matrix<double, Tnfunctions, 1>::Zero();
    grad_shapefn_ = Eigen::Matrix<double, Tnfunctions, Tdim>::Zero();
  }

  //! Destructor
  virtual ~ShapeFnBase() {}

  //! Evaluate shape functions at given local coordinates
  //! \param[in] xi given local coordinates
  //! \param[out] shape_fun shape functions
  virtual Eigen::Matrix<double, Tnfunctions, 1> shapefn(
      const std::array<double, Tdim>& xi) = 0;

  //! Evaluate gradient of shape functions
  //! \param[in] xi given local coordinates
  //! \param[in|out] grad_sfun local gradients of shape functions
  virtual Eigen::Matrix<double, Tnfunctions, Tdim> grad_shapefn(
      const std::array<double, Tdim>& xi) = 0;

 protected:
  //! Shape functions
  Eigen::Matrix<double, Tnfunctions, 1> shapefn_;
  //! Gradient of shape functions
  Eigen::Matrix<double, Tnfunctions, Tdim> grad_shapefn_;
};

#endif  // FELIB_SHAPEFN_BASE_H_
