#ifndef FELIB_ELEMENT_BASE_H_
#define FELIB_ELEMENT_BASE_H_

#include <array>
#include <iostream>
#include <limits>
#include <vector>
#include <memory>
#include <algorithm>

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
  }

  //! Destructor
  virtual ~ElementBase() {}

  //! Return id of the element
  //! \return id_ id of the element
  unsigned id() const { return id_; }

  //! Assign nodes
  //! <param[in] nodes Assign nodes as nodes of the element

  //  std::vector<std::shared_ptr<felib::NodeBase<Tdim>>> vec_nodes_ptr_;

  // Insert a node pointer at a specific index
  void insert_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr_,
                 const unsigned& index) {
    // Check if the node ptr is null and then insert pointer to element at the
    // given index
    // vec_nodes_ptr_.push_back(node_ptr_);
  }

  //! Info
  void info() {
    std::cout << "Element id: " << id_ << "\nnodes: ";
    for (const auto& node_ptr: vec_nodes_ptr_) 
        std::cout << node_ptr->id() << ", ";
    std::cout << std::endl;
  }

  std::array<double, Tdim> centroid();
  
  virtual double volume() = 0;
  
  virtual double area() = 0;

  //! Iterate over nodes
  template<typename FUNC> FUNC iterate_over_nodes(FUNC func);

  //! Iterate over neighbor elements
  template<typename FUNC> FUNC iterate_over_neighbors(FUNC func);
  
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

  //! vector of neighbor element pointers
  std::vector<std::shared_ptr<ElementBase<Tdim>>> vec_neighbors_;

  //! element centroid
  std::array<double, Tdim> centroid_;

  //! element volume
  double volume_;
  
  //! element area
  double area_;
};

#include "element_base.tcc"
#endif  // FELIB_ELEMENT_BASE_H_
