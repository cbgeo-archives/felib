#ifndef FELIB_ELEMENT_BASE_H_
#define FELIB_ELEMENT_BASE_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "node_base.h"

namespace felib {
template <unsigned Tdim>
class ElementBase;
}

// Element Base class
//! \brief Element class that stores the information about elements
//! \details ElementBase class: id_ and nodes. test test test
//! \tparam Tdim Dimension
template <unsigned Tdim>
class felib::ElementBase {
 public:
  // Constructor with id, node_num and nodes
  //! \param[in] id assign as the id_ of the element
  //! \param[in] num_nodes number of nodes of the element
  ElementBase(const unsigned& id, const unsigned& num_nodes)
      : id_{id}, num_nodes_{num_nodes} {
    // initialise the size of vector of node pointers and set it to null_ptr
    vec_nodes_ptr_.resize(num_nodes_);
    vec_nodes_ptr_.fill(nullptr);
  }

  //! Destructor
  virtual ~ElementBase() {}

  //! Return id of the element
  //! \return id_ id of the element
  unsigned id() const { return id_; }

  //! Assign nodes
  //! \param[in] nodes Assign nodes as nodes of the element

  //  std::vector<std::shared_ptr<felib::NodeBase<Tdim>>> vec_nodes_ptr_;

  //! Insert a node pointer at a specific index
  //! \param[in] node_ptr Pointer to a node in the element
  //! \param[in] index Index at which the node pointer will be assigned
  bool insert_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr_,
                       const unsigned& index);

  //! Info
  void info() {
    std::cout << "Element id: " << id_ << "\nnodes: ";
    for (const auto& node_ptr : vec_nodes_ptr_)
      std::cout << node_ptr->id() << ", ";
    std::cout << std::endl;
  }

  //! Add node pointers to element base class
  //! \brief Virtual function to add node pointers to the element
  //! \param[in] node_ptr Pointer to a node in the element
  virtual bool add_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr) = 0;

  //! Add node pointer to a given index
  //! \brief Add a node pointer at a given index of the element
  bool insert_node_ptr_at(std::shared_ptr<NodeBase<Tdim>>& node_ptr,
                          const unsigned index);

  //! Compute centroid
  std::array<double, Tdim> centroid();

  //! \brief Return the volume of the element
  //! \detail Return volume in 3D, area in 2D and length in 1D
  virtual double volume() = 0;

 private:
  //! Copy constructor
  ElementBase(const ElementBase<Tdim>&);

  //! Assignement operator
  ElementBase& operator=(const ElementBase<Tdim>&);

 protected:
  //! element id
  unsigned id_;

  //! element nodes number
  unsigned num_nodes_;

  //! vector of node pointers
  std::vector<std::shared_ptr<NodeBase<Tdim>>> vec_nodes_ptr_;

  //! element centroid
  std::array<double, Tdim> centroid_;

  //! element volume
  double volume_;
};

#include "element_base.tcc"
#endif  // FELIB_ELEMENT_BASE_H_
