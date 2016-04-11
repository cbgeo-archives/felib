#ifndef FELIB_QUADRATURE_BASE_H_
#define FELIB_QUADRATURE_BASE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>

namespace felib {
  template <unsigned Tdim, unsigned Tnquadratures>
class QuadratureBase;
}

// Quadrature base class
//! \brief Base class for quadrature
//! \tparam Tdim Dimension
//! \tparam Tnquadratures number of quadratures

template <unsigned Tdim, unsigned Tnquadratures>
class felib::QuadratureBase {
 public:
  //! Constructor
  //! Assign variables to zero
  QuadratureBase() {
    qpoints_ = Eigen::Matrix<double, Tnquadratures, Tdim>::Zero();
    weights_ = Eigen::Matrix<double, Tnquadratures, Tdim>::Zero();
  }

  //! Destructor
  virtual ~QuadratureBase() {}
  
  //! Return quadrature points
  //! \param[out] qpoints Quadrature points in local coordinates
  Eigen::Matrix<double, Tnquadratures, Tdim> quadratures() {return qpoints_; }
  
  //! Return weights
  //! \param[out] weights Weights for quadrature points
  Eigen::Matrix<double, Tnquadratures, Tdim> weights() { return weights_; }

 protected:
  Eigen::Matrix<double, Tnquadratures, Tdim> qpoints_;
  Eigen::Matrix<double, Tnquadratures, Tdim> weights_;
};

#endif  // FELIB_QUADRATURE_BASE_H_
