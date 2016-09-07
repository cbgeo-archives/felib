//! Compute and return centroid of the element
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
std::array<double, Tdim>
    felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::centroid() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid = {{0.}};

  for (unsigned edge_node_id = 0; edge_node_id < num_edge_nodes_;
       ++edge_node_id) {
    auto coordinates = array_nodes_ptr_.at(edge_node_id)->coordinates();
    std::transform(coordinates.begin(), coordinates.end(), centroid.begin(),
                   centroid.end(), std::plus<double>());
    centroid = centroid / Tdim;
  }
  return centroid;
}

//! Insert node pointer at a given index
//! Check if the node ptr is null at index, then insert pointer to element
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
bool felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::insert_node_ptr(
    std::shared_ptr<NodeBase<Tdim>>& node_ptr, const unsigned& index) {
  if (array_nodes_ptr_.at(index) == nullptr) {
    array_nodes_ptr_.at(index) = node_ptr;
    return true;
  } else
    return false;
}

//! Call a node base function for a particular node
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
template <typename Func>
Func felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::call_node_function(
    const unsigned& nnode, Func func) {
  return func(array_nodes_ptr_.at(nnode));
}

//! Iterate over nodes
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
template <typename Func>
Func felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::iterate_over_nodes(
    Func func) {

  return std::for_each(array_nodes_ptr_.begin(), array_nodes_ptr_.end(), func);
}

//! Iterate over neighbouring elements
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
template <typename Func>
Func felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::iterate_over_neighbours(
    Func func) {

  return std::for_each(vec_neighbours_.begin(), vec_neighbours_.end(), func);
}
