#ifndef FELIB_TRIANGLEELEMENT_H_
#define FELIB_TRIANGLEELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

// #include "triangle_quadrature.h"
#include "triangle_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

// Line Element derived class
//! tparam Tdim Dimension
//! tparam Tnumnodes Number of nodes
//! tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class TriangleElement;
}

template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class felib::TriangleElement
    : public felib::ElementBase<Tdim, Tnumnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  TriangleElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::TriangleShapeFn<Tdim, Tnumnodes>>(
        new felib::TriangleShapeFn<Tdim, Tnumnodes>());
    // quadrature_ptr_ =
    // std::unique_ptr<felib::TriangleQuadrature<Tdim, Tnquadratures>>(
    // new felib::TriangleQuadrature<Tdim, Tnquadratures>());
  }

  //! Add node pointers to line element
  //! \param[in] node_ptr Pointer to a node in the element
  bool add_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr) { return 1; }

  //! Add edge node pointers to line element
  //! \param[in] edge_node_ptr Pointer to an edge_node in the element
  bool add_edge_node_ptr(std::shared_ptr<NodeBase<Tdim>>& edge_node_ptr) {
    return 1;
  }

  //! Return the length of the line element
  //! \param[out] volume_ length of the element
  double volume() { return 1.; }

 protected:
  using felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>::vec_nodes_ptr_;
};

// #include "triangle_element.tcc"
#endif  // FELIB_LINEELEMENT_H_
