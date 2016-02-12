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

