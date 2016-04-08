//! Template specialisation for 2-node Line element
//! 0            1
//!  0----------0
template <>
inline Eigen::Matrix<double, 2, 1> felib::LineShape<1, 2>::evaluate_shape_fun(
  const std::array<double, 1>& xi) {

  shape_fun(0) = 0.5 * (1 - xi.at(0));
  shape_fun(1) = 0.5 * (1 + xi.at(0));
  return shape_fun;
}


template <>
inline Eigen::Matrix<double, 2, 1> felib::LineShape<1, 2>::evaluate_grad_shape_fun( const std::array<double, 1>& xi) {

  grad_sfun(0) = -0.5;
  grad_sfun(1) =  0.5;
  return grad_sfun;
}

//! Template specialisation for 3-node line element (third node at the middle)
//! 0     2     1
//!  0----0----0
template <>
inline Eigen::Matrix<double, 3, 1> felib::LineShape<1, 3>::evaluate_shape_fun(
  const std::array<double, 1>& xi) {

  shape_fun(0) = 0.5 * xi.at(0) * (xi.at(0) - 1);
  shape_fun(1) = 0.5 * xi.at(0) * (xi.at(0) + 1);
  shape_fun(2) = 1 - xi.at(0) * xi.at(0);
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 3, 1> felib::LineShape<1, 3>::evaluate_grad_shape_fun(const std::array<double, 1>& xi) {

  grad_sfun(0) = 0.5 * (2 * xi.at(0) - 1);
  grad_sfun(1) = 0.5 * (2 * xi.at(0) + 1);
  grad_sfun(2) = -2 * xi.at(0);
  return grad_sfun;
}
