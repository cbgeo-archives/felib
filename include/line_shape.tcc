// Template specialisation for 2-node Line element
//! Lagrange Linear shape functions
template <>
inline void felib::LineShape<1, 2>::evaluate_shape_fun(
  const std::array<double, 1>& xi, Eigen::Matrix<double, 2, 1>& sfun) {

  sfun(0) = 0.5 * (1 - xi.at(0));
  sfun(1) = 0.5 * (1 + xi.at(0));
}

// Gradient of linear shape functions for 1-D 2-node line element
template <>
inline void felib::LineShape<1, 2>::evaluate_grad_shape_fun(
  const std::array<double, 1>& xi, Eigen::Matrix<double, 2, 1>& grad_sfun) {

  grad_sfun(0) = -0.5;
  grad_sfun(1) = 0.5;
}


// Give "2" quadrature points
template<>
inline void felib::LineShape<1,2>::quadrature_points(Eigen::Matrix<double, 2, 1>& qpoints) {
 
   qpoints(0) = -0.577350;
   qpoints(1) = 0.577350;
 }

// Template specialisatin for 3-node line element (third node at the middle)
// Lagrange Quadratic shape functions for 1-D second order line element
template <>
inline void felib::LineShape<1, 3>::evaluate_shape_fun(
  const std::array<double, 1>& xi, Eigen::Matrix<double, 3, 1>& sfun) {

  sfun(0) = 0.5 * xi.at(0) * (xi.at(0) - 1);
  sfun(1) = 0.5 * xi.at(0) * (xi.at(0) + 1);
  sfun(2) = 1 - xi.at(0) * xi.at(0);
}

// Gradient of quadratic shape functions for 1-D 3-node line element
template <>
inline void felib::LineShape<1, 3>::evaluate_grad_shape_fun(
  const std::array<double, 1>& xi, Eigen::Matrix<double, 3, 1>& grad_sfun) {

  grad_sfun(0) = 0.5 * (2 * xi.at(0) - 1);
  grad_sfun(1) = 0.5 * (2 * xi.at(0) + 1);
  grad_sfun(2) = -2 * xi.at(0);
}

// Give "3" quadrature points
template<>
inline void felib::LineShape<1,3>::quadrature_points(Eigen::Matrix<double, 3, 1>& qpoints) {
 
   qpoints(0) = -0.77459667;
   qpoints(1) = 0.77459667;
   qpoints(2) = 0.00000000;
 }


 
template<unsigned Tdim, unsigned Tnfunctions>
template <unsigned nquadratures>
void felib::LineShape<Tdim, Tnfunctions>::custom_quadrature_points(Eigen::Matrix<double, nquadratures, Tdim>& qpoints) {

  if (nquadratures == 2) {
   qpoints(0) = -0.577350;
   qpoints(1) = 0.577350;
  }
  else if (nquadratures == 3) {
   qpoints(0) = -0.77459667;
   qpoints(1) = 0.77459667;
   qpoints(2) = 0.00000000;
  }
}
