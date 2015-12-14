#ifndef FELIB_SRC_NODE_BASE_H_
#define FELIB_SRC_NODE_BASE_H_

#include <array>
#include <iostream>
#include <limits>
#include <vector>

namespace felib {
template <unsigned Tdim>
class NodeBase;
}

// Node Base class
//! \brief Base class that stores the information about nodes
//! \details NodeBase class: id_ and coordinates. test test test
//! \tparam Tdim Dimension
template <unsigned Tdim>
class felib::NodeBase {
 public:
  // Constructor with id and coordinates
  //! \param[in] id assign as the id_ of the node
  //! \param[in] coord coordinates of the node
  NodeBase(const unsigned& id, const std::array<double, Tdim>& coord)
      : id_{id} {
    coordinates_ = coord;
  };

  //! Destructor
  virtual ~NodeBase(){};

  //! Return id of the node
  //! \return id_ id of the node
  unsigned id() const { return id_; }

  //! Assign coordinates
  //! \param[in] coord Assign coord as coordinates of the node
  void coordinates(const std::array<double, Tdim>& coord) {
    coordinates_ = coord;
  }

  //! Return coordinates
  //! \return coordinates_ return coordinates of the node
  std::array<double, Tdim> coordinates() const { return coordinates_; }

  //! Info
  void info() {
    std::cout << "Node id: " << id_ << ", coordinates: ";
    for (auto coord : coordinates_) std::cout << coord << ", ";
    std::cout << std::endl;
  }

 private:
  //! Copy constructor
  NodeBase(const NodeBase<Tdim>&);

  //! Assignement operator
  NodeBase& operator=(const NodeBase<Tdim>&);

 protected:
  //! node id
  unsigned id_;

  //! nodal coordinates
  std::array<double, Tdim> coordinates_;
};

#endif  // FELIB_SRC_NODE_BASE_H_
