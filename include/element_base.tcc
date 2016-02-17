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


 //! Iterate over nodes
template <unsigned Tdim>
template<typename OP> 
OP felib::ElementBase<Tdim>::iterateOverNodes(OP op) {
for (const auto& node_ptr: vec_nodes_ptr_) 
  op(node_ptr);
}
