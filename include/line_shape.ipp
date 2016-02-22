namespace felib {

// Lagrange Linear shape functions for 1-D first order line element
// 2-node Line element
template<> inline
void LineShape<1, 2>::evaluate_shape_fun(const std::array<double, 1> &xi, std::array<double, 2> &sFun) {

  sFun.at(0) = 0.5 * (1 - xi.at(0)); 
  sFun.at(1) = 0.5 * (1 + xi.at(0));
}

// Gradient of linear shape functions for 1-D 2-node line element
template<> inline 
void LineShape<1, 2>::evaluate_grad_shape_fun(const std::array<double, 1> &xi, std::array<std::array<double, 2>, 1> &gradSfun) {

  gradSfun[0][0] = -0.5;
  gradSfun[0][1] =  0.5;
}

// Lagrange Quadratic shape functions for 1-D second order line element
// 3-node line element (third node at the middle)
template<> inline
void LineShape<1, 3>::evaluate_shape_fun(const std::array<double, 1> &xi, std::array<double, 3> &sFun) {

  sFun.at(0) = 0.5 * xi.at(0) * (xi.at(0) - 1);
  sFun.at(1) = 0.5 * xi.at(0) * (xi.at(0) + 1);
  sFun.at(2) =         1 - xi.at(0) * xi.at(0);
}

// Gradient of quadratic shape functions for 1-D 3-node line element
template<> inline
void LineShape<1, 3>::evaluate_grad_shape_fun(const std::array<double, 1> &xi, std::array<std::array<double, 3>, 1> &gradSfun) {

  gradSfun[0][0] = 0.5 * (2 * xi.at(0) - 1);
  gradSfun[0][1] = 0.5 * (2 * xi.at(0) + 1);
  gradSfun[0][2] =            -2 * xi.at(0);
}

}
