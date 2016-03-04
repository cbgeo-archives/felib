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

 //! pass arguments or call a node base function for a particular node
template <unsigned Tdim>
template<typename Func> 
Func felib::ElementBase<Tdim>::call_node(Func func, const unsigned numNode) {
  return func(vec_nodes_ptr_[numNode]);
}

 //! Iterate over nodes
template <unsigned Tdim>
template<typename Func> 
Func felib::ElementBase<Tdim>::iterate_over_nodes(Func func) {
    typename std::vector<std::shared_ptr<NodeBase<Tdim>>>::iterator begin = vec_nodes_ptr_.begin();
    typename std::vector<std::shared_ptr<NodeBase<Tdim>>>::iterator   end = vec_nodes_ptr_.end();
    return std::for_each( begin, end, func );
}


//! Iterate over neighbor elements
template <unsigned Tdim>
template<typename Func> 
Func felib::ElementBase<Tdim>::iterate_over_neighbors(Func func) {
    typename std::vector<std::shared_ptr<ElementBase<Tdim>>>::iterator begin = vec_neighbors_.begin();
    typename std::vector<std::shared_ptr<ElementBase<Tdim>>>::iterator   end = vec_neighbors_.end();
    return std::for_each( begin, end, func );
}
