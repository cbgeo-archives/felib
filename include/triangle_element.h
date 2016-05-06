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
  //! \param[out] volume_ area of the element
  double volume() { 
    std::array<double, Tdim> first_node = array_nodes_ptr_.at(0)->coordinates();
    std::array<double, Tdim> second_node = array_nodes_ptr_.at(1)->coordinates();
    std::array<double, Tdim> third_node = array_nodes_ptr_.at(2)->coordinates();

    double length_x = second_node.at(0)  - first_node.at(0);
    double length_y = third_node.at(1) - first_node.at(1);
    volume_ = std::fabs(0.5 * length_x * length_y);
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
