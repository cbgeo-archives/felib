namespace felib {

// Template specialisation for 2-node Line element
//! Lagrange Linear shape functions
template<> inline
void LineShape<1, 2>::evaluate_shape_fun(const std::array<double, 1> &xi, Eigen::Matrix<double, 1, 2> &sFun) {

  sFun(0) = 0.5 * (1 - xi.at(0)); 
  sFun(1) = 0.5 * (1 + xi.at(0));
}

// Gradient of linear shape functions for 1-D 2-node line element
template<> inline 
void LineShape<1, 2>::evaluate_grad_shape_fun(const std::array<double, 1> &xi, Eigen::Matrix<double, 1, 2> &gradSfun) {

  gradSfun(0) = -0.5;
  gradSfun(1) =  0.5;
}

// Template specialisatin for 3-node line element (third node at the middle)
// Lagrange Quadratic shape functions for 1-D second order line element
template<> inline
void LineShape<1, 3>::evaluate_shape_fun(const std::array<double, 1> &xi, Eigen::Matrix<double, 1, 3> &sFun) {

  sFun(0) = 0.5 * xi.at(0) * (xi.at(0) - 1);
  sFun(1) = 0.5 * xi.at(0) * (xi.at(0) + 1);
  sFun(2) =         1 - xi.at(0) * xi.at(0);
}

// Gradient of quadratic shape functions for 1-D 3-node line element
template<> inline
void LineShape<1, 3>::evaluate_grad_shape_fun(const std::array<double, 1> &xi, Eigen::Matrix<double, 1, 3> &gradSfun) {

  gradSfun(0) = 0.5 * (2 * xi.at(0) - 1);
  gradSfun(1) = 0.5 * (2 * xi.at(0) + 1);
  gradSfun(2) =            -2 * xi.at(0);
}

// Function template specialisation for p = 2 quadrature points
template<unsigned Tdim, unsigned numFunctions>
template<>
void quadrature_points<2>(Eigen::Matrix<double, Tdim, 2> &qpoints) {

  qpoints(0) = -0.577350;
  qpoints(1) =  0.577350;
}

// Function template specialisation for p = 3 quadrature points
template<unsigned Tdim, unsigned numFunctions>
template<>
void quadrature_points<3>(Eigen::Matrix<double, Tdim, 3> &qpoints) {

  qpoints(0) = -0.77459667;
  qpoints(1) =  0.77459667;
  qpoints(2) =  0.00000000;
}

}
