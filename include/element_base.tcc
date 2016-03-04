//! Compute and return centroid of the element
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
 // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid;
  for (unsigned j=0; j<vec_nodes_ptr.size(); ++j){
  for (unsigned i=0; i<Tdim; ++i){
    centroid(j) += (vec_node_ptr.at(i)).coordinates.at(j);
  }
  //centroid(j) = centroid
  }
  return centroid;
}


//! Add node pointers to element base class
template <unsigned Tdim>
//std::vector<std::shared_ptr<NodeBase<Tdim>>> felib::ElementBase<Tdim>::insert_node_ptr(){
void felib::ElementBase<Tdim>::insert_node_ptr(){
// Insert a pointer for each node


  
}

//! Insert node pointer at a given index
template <unsigned Tdim>
//std::vector<std::shared_ptr<NodeBase<Tdim>>> felib::ElementBase<Tdim>::insert_node_ptr_at(){
void felib::ElementBase<Tdim>::insert_node_ptr_at(){
// Insert node pointer at index: "node_ptr_index_"
  
  return 0;
}
