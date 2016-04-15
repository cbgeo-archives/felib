// 3-node Triangle Element
//!   2 0
//!     |`\
//!     |  `\
//!     |    `\
//!     |      `\
//!     |        `\
//!   0 0----------0 1

template <>
inline Eigen::Matrix<double, 3, 1> felib::TriangleShapeFn<2, 3>::shapefn(
    const std::array<double, 2>& xi) {

  shapefn_(0) = 1 - (xi.at(0) + xi.at(1));
  shapefn_(1) = xi.at(0);
  shapefn_(2) = xi.at(1);
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 3, 2> felib::TriangleShapeFn<2, 3>::grad_shapefn(
    const std::array<double, 2>& xi) {

  grad_shapefn_(0, 0) = -1.;
  grad_shapefn_(1, 0) = 1.;
  grad_shapefn_(2, 0) = 0.;
  grad_shapefn_(0, 1) = -1.;
  grad_shapefn_(1, 1) = 0.;
  grad_shapefn_(2, 1) = 1.;
  return grad_shapefn_;
}

// 6-node Triangle Element
//!   2 0
//!     |`\
//!     |  `\
//!   5 0    `0 4
//!     |      `\
//!     |        `\
//!   0 0-----0----0 1
//!           3
template <>
inline Eigen::Matrix<double, 6, 1> felib::TriangleShapeFn<2, 6>::shapefn(
    const std::array<double, 2>& xi) {

  shapefn_(0) =
      (1. - xi.at(0) - xi.at(1)) * (1. - 2. * xi.at(0) - 2. * xi.at(1));
  shapefn_(1) = xi.at(0) * (2. * xi.at(0) - 1.);
  shapefn_(2) = xi.at(1) * (2. * xi.at(1) - 1.);
  shapefn_(3) = 4. * xi.at(0) * (1. - xi.at(0) - xi.at(1));
  shapefn_(4) = 4. * xi.at(0) * xi.at(1);
  shapefn_(5) = 4. * xi.at(1) * (1. - xi.at(0) - xi.at(1));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 6, 2> felib::TriangleShapeFn<2, 6>::grad_shapefn(
    const std::array<double, 2>& xi) {

  grad_shapefn_(0, 0) = 4. * xi.at(0) + 4. * xi.at(1) - 3.;
  grad_shapefn_(1, 0) = 4. * xi.at(0) - 1.;
  grad_shapefn_(2, 0) = 0;
  grad_shapefn_(3, 0) = 4. - 8. * xi.at(0) - 4. * xi.at(1);
  grad_shapefn_(4, 0) = 4. * xi.at(1);
  grad_shapefn_(5, 0) = -4. * xi.at(1);
  
  grad_shapefn_(0, 1) = 4. * xi.at(0) + 4. * xi.at(1) - 3.;
  grad_shapefn_(1, 1) = 0;
  grad_shapefn_(2, 1) = 4. * xi.at(1) - 1.;
  grad_shapefn_(3, 1) = -4. * xi.at(0);
  grad_shapefn_(4, 1) = 4. * xi.at(0);
  grad_shapefn_(5, 1) = 4. - 4. * xi.at(0) - 8. * xi.at(1);
  return grad_shapefn_;
}
