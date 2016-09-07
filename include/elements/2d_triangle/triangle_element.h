#ifndef FELIB_TRIANGLE_ELEMENT_H_
#define FELIB_TRIANGLE_ELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "triangle_quadrature.h"
#include "triangle_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

// Triangle Element derived class
//! \tparam Tdim Dimension
//! \tparam Tnumnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class TriangleElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::TriangleElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  TriangleElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::TriangleShapeFn<Tdim, Tnnodes>>(
        new felib::TriangleShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::TriangleQuadrature<Tdim, Tnquadratures>>(
            new felib::TriangleQuadrature<Tdim, Tnquadratures>());
  }

  //! Return the length of the triangle element
  //! \param[in] recompute Recompute the volume of the element
  //! \param[out] volume_ area of the element
  double volume(const bool& recompute) {
    // Recompute volume if volume is NaN or recompute is requested
    if (recompute || std::isnan(volume_)) {
      auto node1 = array_nodes_ptr_.at(0)->coordinates();
      auto node2 = array_nodes_ptr_.at(1)->coordinates();
      auto node3 = array_nodes_ptr_.at(2)->coordinates();
      // 2 * Area = (x2 * y3 - x3 * y2) - (x1 * y3 - x3 * y1) + (x1 * y2 - x2 * y1)
      volume_ = std::fabs(((node2.at(0) * node3.at(1)) - (node3.at(0) - node2.at(1))) -
                          ((node1.at(0) * node3.at(1)) - (node3.at(0) - node1.at(1))) +
                          ((node1.at(0) * node2.at(1)) - (node2.at(0) - node1.at(1))))/2.0;
    }
    return volume_;
  }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::array_nodes_ptr_;
};

// #include "triangle_element.tcc"
#endif  // FELIB_TRIANGLE_ELEMENT_H_
