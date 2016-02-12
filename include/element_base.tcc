///#include <>

//! implementation of function centroid()
//! to calculate the centroid of the element
template<unsigned Tdim>

///double element_base<Tdim>::centroid(){
///std::array<double, Tdim> centroid()

std::array<double, Tdim> felib::ElementBase<Tdim>::centroid() {
for(unsigned i=0; i<Tdim; ++i){
  centroid(i) = 5; //change
}
}

//! implementation of function volume()
//! to calculate the volume of the element
template<unsigned Tdim>
double felib::ElementBase<Tdim>::volume(){
  volume = 5; //change
}

//! implementation of function info_pass_node()
//! to calculate the info_pass_node of the element
template<unsigned Tdim>
double felib::ElementBase<Tdim>::info_pass_node(){
  info_pass_node = 5; //change
}

