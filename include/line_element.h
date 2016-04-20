#ifndef FELIB_LINEELEMENT_H_
#define FELIB_LINEELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "line_quadrature.h"
#include "line_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

// Line Element derived class
//! tparam Tdim Dimension
//! tparam Tnumnodes Number of nodes
//! tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class LineElement;
}

template <unsigned Tdim, unsigned Tnumnodes, unsigned Tnquadratures>
class felib::LineElement : public felib::ElementBase<Tdim, Tnumnodes, Tnquadratures> {

public:
  // Default constructor
  LineElement(const unsigned&id) : felib::ElementBase<Tdim, Tnumnodes, Tnquadratures>(id, Tnumnodes){ 
        shapefn_ptr_ = std::unique_ptr<felib::LineShapeFn<Tdim, Tnumnodes>>(new felib::LineShapeFn<Tdim, Tnumnodes>());
        quadrature_ptr_ = std::unique_ptr<felib::LineQuadrature<Tdim, Tnquadratures>>(new felib::LineQuadrature<Tdim,Tnquadratures>());
  }

    bool add_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr) {return 1; }
    bool add_edge_node_ptr(std::shared_ptr<NodeBase<Tdim>>& edge_node_ptr) { return 1; }
    double volume() { return 1.; }

protected:
    using felib::ElementBase<Tdim,Tnumnodes,Tnquadratures>::shapefn_ptr_;
    using felib::ElementBase<Tdim,Tnumnodes,Tnquadratures>::quadrature_ptr_;
};

// #include "line_element.tcc"
#endif // FELIB_LINEELEMENT_H_
