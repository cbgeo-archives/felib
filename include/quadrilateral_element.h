#ifndef FELIB_QUADRILATERAL_ELEMENT_H_
#define FELIB_QUADRILATERAL_ELEMENT_H_

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

//! \brief  Quadrilateral Element derived class
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class QuadrilateralElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::QuadrilateralElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  QuadrilateralElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = 
        std::unique_ptr<felib::QuadrilateralShapeFn<Tdim, Tnnodes>>(
            new felib::QuadrilateralShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::QuadrilateralQuadrature<Tdim, Tnquadratures>>(
            new felib::QuadrilateralQuadrature<Tdim, Tnquadratures>());
  }

  //! Return the length of the quadrilateral element
  //! \param[out] volume_ length of the element
  double volume() { return 1.; }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::array_nodes_ptr_;
};

// #include "quadrilateral_element.tcc"
#endif  // FELIB_QUADRILATERAL_ELEMENT_H_
