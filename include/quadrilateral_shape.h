#ifndef FELIB_QUADRILATERALSHAPE_H_
#define FELIB_QUADRILATERALSHAPE_H_

#include <iostream>
#include <array>
#include <vector>
#include <Eigen/Dense>

#include "shapefun_base.h"

// Quadrilateral shape function class derived from Shape Fun Base Class
//! \shape functions of the quadrilateral element
//! \tparam Tdim Dimenstion
//! \tparam numFun number of shape functions
namespace felib {
  template <unsigned Tdim, unsigned numFun> class QuadrilateralShape;
}

template <unsigned Tdim, unsigned numFun> 
class felib::QuadrilateralShape 
  : public felib::ShapeFunBase<Tdim, numFun > {

public:
  // Default constructor do nothing
  QuadrilateralShape() {};

  // Default destructor
  ~QuadrilateralShape() {};

  // Evaluate shape functions
  //! param[in] xi given local coordinates
  //! param[out] sFun shape functins at local coordinates xi
  void evaluate_shape_fun(const std::array<double, Tdim> &xi, Eigen::Matrix<double, 1, numFun> &sFun);

  // Evaluate local gradient of shape functions
  //! param[in] xi given local coordinates
  //! param[out] gradSfun gradient of shape functions at local coordinates
  void evaluate_grad_shape_fun(const std::array<double, Tdim> &xi, Eigen::Matrix<double, Tdim, numFun> &gradSfun);

  void evaluate_jacobian() {};

  // Give quadrature points in local coordinates (p x p rule)
  //! param[in] p number of quadrature points
  //! param[out] qpoints quadrature points in local coordinates
  template<unsigned p>
    void quadrature_points(Eigen::Matrix<double, 2, p> &qpoints);

};

#include "quadrilateral_shape.tcc"

#endif // FELIB_QUADRILATERALSHAPE_H_
