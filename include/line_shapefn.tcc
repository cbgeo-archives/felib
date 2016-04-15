//! Template specialisation for a 2-node line element
//! 0            1
//!  0----------0
template <>
inline Eigen::Matrix<double, 2, 1> felib::LineShapeFn<1, 2>::shapefn(
    const std::array<double, 1>& xi) {
  shapefn_(0) = 0.5 * (1. - xi.at(0));
  shapefn_(1) = 0.5 * (1. + xi.at(0));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 2, 1> felib::LineShapeFn<1, 2>::grad_shapefn(
    const std::array<double, 1>& xi) {
  grad_shapefn_(0) = -0.5;
  grad_shapefn_(1) = 0.5;
  return grad_shapefn_;
}

//! Template specialisation for a 3-node line element (third node at the middle)
//! 0     2     1
//!  0----0----0
template <>
inline Eigen::Matrix<double, 3, 1> felib::LineShapeFn<1, 3>::shapefn(
    const std::array<double, 1>& xi) {
  shapefn_(0) = 0.5 * xi.at(0) * (xi.at(0) - 1.);
  shapefn_(1) = 0.5 * xi.at(0) * (xi.at(0) + 1.);
  shapefn_(2) = 1. - (xi.at(0) * xi.at(0));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 3, 1> felib::LineShapeFn<1, 3>::grad_shapefn(
    const std::array<double, 1>& xi) {
  grad_shapefn_(0) = 0.5 * (2 * xi.at(0) - 1.);
  grad_shapefn_(1) = 0.5 * (2 * xi.at(0) + 1.);
  grad_shapefn_(2) = -2 * xi.at(0);
  return grad_shapefn_;
}
