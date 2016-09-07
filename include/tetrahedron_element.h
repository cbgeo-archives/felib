#ifndef FELIB_TETRAHEDRON_ELEMENT_H_
#define FELIB_TETRAHEDRON_ELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include <Eigen/Dense>

#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"
#include "tetrahedron_quadrature.h"
#include "tetrahedron_shapefn.h"

//! \brief Tetrahedron element derived class
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class TetrahedronElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::TetrahedronElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  TetrahedronElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::TetrahedronShapeFn<Tdim, Tnnodes>>(
        new felib::TetrahedronShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::TetrahedronQuadrature<Tdim, Tnquadratures>>(
            new felib::TetrahedronQuadrature<Tdim, Tnquadratures>());
  }

  //! Return the length of the tetrahedron element
  //! \param[in] recompute Recompute the volume of the element
  //! \param[out] volume_ volume of the element
  double volume(const bool& recompute) {
    // Recompute volume if volume is NaN or recompute is requested
    if (recompute || std::isnan(volume_)) {
      // V = abs((a - d) . ((b - d) x (c - d))) / 6.
      Eigen::VectorXd a = array_nodes_ptr_.at(0)->coordinates();
      Eigen::VectorXd b = array_nodes_ptr_.at(1)->coordinates();
      Eigen::VectorXd c = array_nodes_ptr_.at(2)->coordinates();
      Eigen::VectorXd d = array_nodes_ptr_.at(3)->coordinates();

      volume_ = std::fabs((a - d).dot((b - d).cross(c - d))) / 6.;
    }
    return volume_;
  }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::array_nodes_ptr_;
};

// #include "tetrahedron_element.tcc"
#endif  // FELIB_TETRAHEDRON_ELEMENT_H_
