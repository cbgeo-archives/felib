//! Compute and return centroid of the element
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid;
  // for (unsigned i = 0; i < Tdim; ++i) {
  //   centroid(i) = 5;  // change
  //  }
  return centroid;
}

//! Call a node base function for a particular node
template <unsigned Tdim>
template <typename Func>
Func felib::ElementBase<Tdim>::call_function_node(const unsigned& nnode,
                                                  Func func) {
  return func(vec_nodes_ptr_.at(nnode));
}

//! Iterate over nodes
template <unsigned Tdim>
template <typename Func>
Func felib::ElementBase<Tdim>::iterate_over_nodes(Func func) {
  return std::for_each(vec_nodes_ptr_.begin(), vec_nodes_ptr_.end(), func);
}

//! Iterate over neighbouring elements
template <unsigned Tdim>
template <typename Func>
Func felib::ElementBase<Tdim>::iterate_over_neighbours(Func func) {
  return std::for_each(vec_neighbours_.begin(), vec_neighbours_.end(), func);
}
