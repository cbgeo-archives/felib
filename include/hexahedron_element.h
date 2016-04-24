#ifndef FELIB_HEXAHEDRONELEMENT_H_
#define FELIB_HEXAHEDRONELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

// #include "hexahedron_quadrature.h"
#include "hexahedron_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

// Hexhedron Element derived class
//! tparam Tdim Dimension
//! tparam Tnumnodes Number of nodes
//! tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class HexahedronElement;
}

template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class felib::HexahedronElement
    : public felib::ElementBase<Tdim, Tnumnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  HexahedronElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::HexahedronShapeFn<Tdim, Tnumnodes>>(
        new felib::LineShapeFn<Tdim, Tnumnodes>());
    // quadrature_ptr_ =
    // std::unique_ptr<felib::LineQuadrature<Tdim, Tnquadratures>>(
    // new felib::HexhedronQuadrature<Tdim, Tnquadratures>());
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

// #include "hexahedron_element.tcc"
#endif  // FELIB_LINEELEMENT_H_
