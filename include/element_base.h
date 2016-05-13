#ifndef FELIB_ELEMENT_BASE_H_
#define FELIB_ELEMENT_BASE_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class ElementBase;
}

// Element Base class
//! \brief Element class that stores the information about elements
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::ElementBase {
 public:
  // Constructor with id, num_nodes, nodes, num_edge_nodes and edge_nodes
  //! \param[in] id assign as the id_ of the element
  explicit ElementBase(const int& id) : id_{id}, num_nodes_{Tnnodes} {
    // initialise the size of vector of node pointers and set it to null_ptr
    std::fill(array_nodes_ptr_.begin(), array_nodes_ptr_.end(), nullptr);
    shapefn_ptr_ = nullptr;
    quadrature_ptr_ = nullptr;
    volume_ = std::numeric_limits<double>::quiet_NaN();
  }

  //! Destructor
  virtual ~ElementBase() {}

  //! Return id of the element
  //! \return id_ id of the element
  long long id() const { return id_; }

  //! Call a node base function for a particular node
  //! \tparam Func Function type
  //! \param[in] nnode Node number
  //! \param[in] func A node base function
  template <typename Func>
  Func call_node_function(const unsigned& nnode, Func func);

  //! Iterate over nodes
  //! \tparam Func Function type
  //! \param[in] func A node base function
  template <typename Func>
  Func iterate_over_nodes(Func func);

  //! Iterate over neighbour elements
  //! \tparam Func Function type
  //! \param[in] func Element base function
  template <typename Func>
  Func iterate_over_neighbours(Func func);

  //! Assign nodes
  //! \param[in] nodes Assign nodes as nodes of the element

  //! Insert a node pointer at a specific index
  //! \param[in] node_ptr Pointer to a node in the element
  //! \param[in] index Index at which the node pointer will be assigned
  bool insert_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr_,
                       const unsigned& index);
  
  //! Update a node pointer at a specific index
  //! \param[in] node_ptr Pointer to a node in the element
  //! \param[in] index Index at which the node pointer will be assigned
  bool update_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr_,
                       const unsigned& index);

  //! Info
  void info() {
    std::cout << "Element id: " << id_ << "\nnodes: ";
    for (const auto& node_ptr : array_nodes_ptr_)
      std::cout << node_ptr->id() << ", ";
    std::cout << std::endl;
  }

  //! Compute centroid
  std::array<double, Tdim> centroid();

  //! \brief Return the volume of the element
  //! \detail Return volume in 3D, area in 2D and length in 1D
  //! \param[in] recompute Recompute volume
  virtual double volume(const bool& recompute) = 0;

 private:
  //! Copy constructor
  ElementBase(const ElementBase<Tdim, Tnnodes, Tnquadratures>&);

  //! Assignement operator
  ElementBase& operator=(const ElementBase<Tdim, Tnnodes, Tnquadratures>&);

 protected:
  //! element id
  long long id_;
  //! element nodes number
  unsigned num_nodes_;
  //! element edge_nodes number
  unsigned num_edge_nodes_;
  //! vector of node pointers
  std::array<std::shared_ptr<NodeBase<Tdim>>, Tnnodes> array_nodes_ptr_;
  //! vector of neighbour element pointers
  std::vector<std::shared_ptr<ElementBase<Tdim, Tnnodes, Tnquadratures>>>
      vec_neighbours_;
  //! element centroid
  std::array<double, Tdim> centroid_;
  //! element volume
  double volume_;
  //! shape function base class pointer
  std::unique_ptr<felib::ShapeFnBase<Tdim, Tnnodes>> shapefn_ptr_;
  //! quadrature points base class pointer
  std::unique_ptr<felib::QuadratureBase<Tdim, Tnquadratures>> quadrature_ptr_;
};

#include "element_base.tcc"
#endif  // FELIB_ELEMENT_BASE_H_
