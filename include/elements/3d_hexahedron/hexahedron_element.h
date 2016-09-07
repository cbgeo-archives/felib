#ifndef FELIB_HEXAHEDRON_ELEMENT_H_
#define FELIB_HEXAHEDRON_ELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "hexahedron_quadrature.h"
#include "hexahedron_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

//! \brief Hexahedron element derived class
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class HexahedronElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::HexahedronElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  HexahedronElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::HexahedronShapeFn<Tdim, Tnnodes>>(
        new felib::HexahedronShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::HexahedronQuadrature<Tdim, Tnquadratures>>(
            new felib::HexahedronQuadrature<Tdim, Tnquadratures>());
  }

  //! Return the length of the hexahedron element
  //! \param[in] recompute Recompute the volume of the element
  //! \param[out] volume_ volume of the element
  double volume(const bool& recompute) {
    // Recompute volume if volume is NaN or recompute is requested
    if (recompute || std::isnan(volume_)) {
      auto bottom_left = array_nodes_ptr_.at(0)->coordinates();
      auto top_right = array_nodes_ptr_.at(6)->coordinates();
      std::array<double, Tdim> length;
      std::transform(top_right.begin(), top_right.end(), bottom_left.begin(),
                     length.begin(), std::minus<double>());
      volume_ = std::fabs(length.at(0) * length.at(1) * length.at(2));
    }
    return volume_;
  }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::array_nodes_ptr_;
};

// #include "hexahedron_element.tcc"
#endif  // FELIB_HEXAHEDRON_ELEMENT_H_
