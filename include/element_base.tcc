//! Compute and return centroid of the element
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid = {{0.}};

  for (const auto node_ptr : vec_nodes_ptr_) {
    auto coordinates = node_ptr->coordinates();
    std::transform(coordinates.begin(), coordinates.end(), centroid.begin(),
                   centroid.begin(), std::plus<double>());
  }
  centroid /= vec_nodes_ptr_.size();
  return centroid;
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
