//! Compute and return centroid of the element
template <unsigned Tdim>
std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
  // Compute centroid for 1D, 2D and 3D cases
  std::array<double, Tdim> centroid;
<<<<<<< HEAD
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


  
=======
  // return centroid;
  return 0;
>>>>>>> bf30a2ef6bb5c7b50cb460134dc343c849e8984c
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
