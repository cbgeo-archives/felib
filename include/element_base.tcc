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
template<typename FUNC> 
FUNC felib::ElementBase<Tdim>::iterate_over_nodes(FUNC func) {
    typename std::vector<std::shared_ptr<NodeBase<Tdim>>>::iterator begin = vec_nodes_ptr_.begin();
    typename std::vector<std::shared_ptr<NodeBase<Tdim>>>::iterator   end = vec_nodes_ptr_.end();
    return std::for_each( begin, end, func );
}


//! Iterate over neighbor elements
template <unsigned Tdim>
template<typename FUNC> 
FUNC felib::ElementBase<Tdim>::iterate_over_neighbors(FUNC func) {
    typename std::vector<std::shared_ptr<ElementBase<Tdim>>>::iterator begin = vec_neighbors_.begin();
    typename std::vector<std::shared_ptr<ElementBase<Tdim>>>::iterator   end = vec_neighbors_.end();
    return std::for_each( begin, end, func );
}
