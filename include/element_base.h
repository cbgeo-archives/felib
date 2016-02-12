#ifndef FELIB_SRC_ELEMENT_BASE_H_
#define FELIB_SRC_ELEMENT_BASE_H_

#include <array>
#include <iostream>
#include <limits>
#include <vector>
#include <memory>

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
ElementBase(const unsigned& id, const unsigned num_nodes)
  : id_{id}, num_nodes_{num_nodes} {}
 
  //! Destructor
  virtual ~ElementBase(){}

  //! Return id of the element
  //! \return id_ id of the element
  unsigned id() const { return id_; }

//! Assign nodes
//! <param[in] nodes Assign nodes as nodes of the element

//  std::vector<std::shared_ptr<felib::NodeBase<Tdim>>> vec_nodes_ptr_;

//void ElementBase::add_nodes(){
  void add_nodes(std::shared_ptr<NodeBase<Tdim>> node_ptr_){
    vec_nodes_ptr_.push_back(node_ptr_);
  }


  //%% we need to change the following lines:
  /*
vec_nodes_ptr_.reserve(num_nodes_);
    vec_nodes_ptr_.resize(num_nodes_);
    for (auto node : num_nodes_){
      vec_nodes_ptr_.fill(vec_nodes_ptr_(node),vec_nodes_ptr_(node),vec_nodes_ptr.at(node);}

        return vec_nodes_ptr_;
    }
  */

  
   //! Assign nodes
  //! \param[in] nodes Assign nodes as nodes of the element
  void nodes(const std::array<double, Tdim>& nodes) {
    vec_nodes_ptr_ = nodes;
  }

  //! Return nodes
  //! \return nodes_ return nodes of the element
  std::array<double, Tdim> nodes() const { return vec_nodes_ptr_; }

  //! Info
  void info() {
    std::cout << "Element id: " << id_ << ", nodes: ";
    for (auto coord : vec_nodes_ptr_) std::cout << nodes << ", ";
    std::cout << std::endl;
  }


  std::array<double, Tdim> centroid();
  double volume();
  double info_pass_node();

  

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

  //! node pointer
  std::shared_ptr<NodeBase<Tdim>> node_ptr_;

  
  //! element nodes
  std::vector<std::shared_ptr<NodeBase<Tdim>>> vec_nodes_ptr_;
  ///vec_nodes_ptr_;
  ///std::array<double, Tdim> nodes_;
  ///std::vector<std::shared_ptr<Element<Tdim>>> vec_node_ptr_;


  
  //! element centroid
  std::array<double, Tdim> centroid_;

  //! element volume
  double volume_;

//! element info
  double info_pass_node_;

  
};


#include "element_base.tcc"
#endif  // FELIB_SRC_ELEMENT_BASE_H_
