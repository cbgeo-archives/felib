//! Compute and return centroid of the element
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid = {{0.}};

  for (const auto node_ptr : vec_nodes_ptr_) {
    auto coordinates = node_ptr->coordinates();
    // Use an algorithm instead to iterate over coordinates
    // and add to centroid
    for (unsigned i = 0; i < Tdim; ++i) {
      centroid.at(i) += coordinates.at(i);
    }
    centroid = centroid/Tdim;
  }
  return centroid;
}



//! Compute and return centroid of the element (based on the edge nodes only)
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid_edge_nodes() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid_edge_nodes = {{0.}};

  for (const auto& node_ptr : vec_edge_nodes_ptr_) {
    auto coordinates = node_ptr->coordinates();
    // Use an algorithm instead to iterate over coordinates
    // and add to centroid
    for (unsigned i = 0; i < Tdim; ++i) {
      centroid_edge_nodes.at(i) += coordinates.at(i);
    }
    centroid_edge_nodes = centroid_edge_nodes/Tdim;
  }
  return centroid_edge_nodes;
}

//! Insert node pointer at a given index
//! Check if the node ptr is null at index, then insert pointer to element
template <unsigned Tdim>
bool felib::ElementBase<Tdim>::insert_node_ptr(
    std::shared_ptr<NodeBase<Tdim>>& node_ptr, const unsigned& index) {
  if (vec_nodes_ptr_.at(index) == nullptr) {
    vec_nodes_ptr_.at(index) = node_ptr;
    return true;
  } else
    return false;
}
