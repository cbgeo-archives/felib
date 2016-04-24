#ifndef FELIB_QUADRILATERALELEMENT_H_
#define FELIB_QUADRILATERALELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "quadrilateral_quadrature.h"
#include "quadrilateral_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

// Quadrilateral Element derived class
//! tparam Tdim Dimension
//! tparam Tnumnodes Number of nodes
//! tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class QuadrilateralElement;
}

template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class felib::QuadrilateralElement
    : public felib::ElementBase<Tdim, Tnumnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  QuadrilateralElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>(id) {
    shapefn_ptr_ = 
        std::unique_ptr<felib::QuadrilateralShapeFn<Tdim, Tnumnodes>>(
            new felib::QuadrilateralShapeFn<Tdim, Tnumnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::QuadrilateralQuadrature<Tdim, Tnquadratures>>(
            new felib::QuadrilateralQuadrature<Tdim, Tnquadratures>());
  }

  //! Add node pointers to quadrilateral element
  //! \param[in] node_ptr Pointer to a node in the element
  bool add_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr) { return 1; }

  //! Add edge node pointers to quadrilateral element
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

// #include "line_element.tcc"
#endif  // FELIB_LINEELEMENT_H_
