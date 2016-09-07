#ifndef FELIB_LINE_ELEMENT_H_
#define FELIB_LINE_ELEMENT_H_

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

// Line element derived class
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class LineElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::LineElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  LineElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::LineShapeFn<Tdim, Tnnodes>>(
        new felib::LineShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::LineQuadrature<Tdim, Tnquadratures>>(
            new felib::LineQuadrature<Tdim, Tnquadratures>());
  }

  //! Return the length of the line element
  //! \param[in] recompute Recompute the volume of the element
  //! \param[out] volume_ length of the element
  double volume(const bool& recompute) {
    // Recompute volume if volume is NaN or recompute is requested
    if (recompute || std::isnan(volume_)) {
      std::array<double, Tdim> first_node =
          array_nodes_ptr_.at(0)->coordinates();
      std::array<double, Tdim> second_node =
          array_nodes_ptr_.at(1)->coordinates();
      volume_ = std::fabs(second_node.at(0) - first_node.at(0));
    }
    return volume_;
  }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::array_nodes_ptr_;
};

// #include "line_element.tcc"
#endif  // FELIB_LINEELEMENT_H_
