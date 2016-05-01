// 4-node Quadrilateral Element
//! 3 0----------0 2
//!   |          |
//!   |          |
//!   |          |
//!   |          |
//! 0 0----------0 1

template <>
inline Eigen::Matrix<double, 4, 1> felib::QuadrilateralShapeFn<2, 4>::shapefn(
    const std::array<double, 2>& xi) {

  shapefn_(0) = 0.25 * (1 - xi.at(0)) * (1 - xi.at(1));
  shapefn_(1) = 0.25 * (1 + xi.at(0)) * (1 - xi.at(1));
  shapefn_(2) = 0.25 * (1 + xi.at(0)) * (1 + xi.at(1));
  shapefn_(3) = 0.25 * (1 - xi.at(0)) * (1 + xi.at(1));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 4, 2> felib::QuadrilateralShapeFn<
    2, 4>::grad_shapefn(const std::array<double, 2>& xi) {

  grad_shapefn_(0, 0) = -0.25 * (1 - xi.at(1));
  grad_shapefn_(1, 0) = 0.25 * (1 - xi.at(1));
  grad_shapefn_(2, 0) = 0.25 * (1 + xi.at(1));
  grad_shapefn_(3, 0) = -0.25 * (1 + xi.at(1));

  grad_shapefn_(0, 1) = -0.25 * (1 - xi.at(0));
  grad_shapefn_(1, 1) = -0.25 * (1 + xi.at(0));
  grad_shapefn_(2, 1) = 0.25 * (1 + xi.at(0));
  grad_shapefn_(3, 1) = 0.25 * (1 - xi.at(0));
  return grad_shapefn_;
}

// 8-node Quadrilateral Element
//!  3      6       2
//!   0-----0-----0
//!   |           |
//!   |           |
//! 7 0           0 5
//!   |           |
//!   |           |
//!   0-----0-----0
//! 0       4       1

template <>
inline Eigen::Matrix<double, 8, 1> felib::QuadrilateralShapeFn<2, 8>::shapefn(
    const std::array<double, 2>& xi) {

  shapefn_(0) =
      -0.25 * (1. - xi.at(0)) * (1. - xi.at(1)) * (xi.at(0) + xi.at(1) + 1.);
  shapefn_(1) =
      0.25 * (1. + xi.at(0)) * (1. - xi.at(1)) * (xi.at(0) - xi.at(1) - 1.);
  shapefn_(2) =
      0.25 * (1. + xi.at(0)) * (1. + xi.at(1)) * (xi.at(0) + xi.at(1) - 1.);
  shapefn_(3) =
      -0.25 * (1. - xi.at(0)) * (1. + xi.at(1)) * (xi.at(0) - xi.at(1) + 1.);
  shapefn_(4) = 0.5 * (1. - (xi.at(0) * xi.at(0))) * (1. - xi.at(1));
  shapefn_(5) = 0.5 * (1. - (xi.at(1) * xi.at(1))) * (1. + xi.at(0));
  shapefn_(6) = 0.5 * (1. - (xi.at(0) * xi.at(0))) * (1. + xi.at(1));
  shapefn_(7) = 0.5 * (1. - (xi.at(1) * xi.at(1))) * (1. - xi.at(0));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 8, 2> felib::QuadrilateralShapeFn<
    2, 8>::grad_shapefn(const std::array<double, 2>& xi) {

  grad_shapefn_(0, 0) = 0.25 * (2. * xi.at(0) + xi.at(1)) * (1. - xi.at(1));
  grad_shapefn_(1, 0) = 0.25 * (2. * xi.at(0) - xi.at(1)) * (1. - xi.at(1));
  grad_shapefn_(2, 0) = 0.25 * (2. * xi.at(0) + xi.at(1)) * (1. + xi.at(1));
  grad_shapefn_(3, 0) = 0.25 * (2. * xi.at(0) - xi.at(1)) * (1. + xi.at(1));
  grad_shapefn_(4, 0) = -xi.at(0) * (1. - xi.at(1));
  grad_shapefn_(5, 0) = 0.5 * (1. - (xi.at(1) * xi.at(1)));
  grad_shapefn_(6, 0) = -xi.at(0) * (1. + xi.at(1));
  grad_shapefn_(7, 0) = -0.5 * (1. - (xi.at(1) * xi.at(1)));

  grad_shapefn_(0, 1) = 0.25 * (2. * xi.at(1) + xi.at(0)) * (1. - xi.at(0));
  grad_shapefn_(1, 1) = 0.25 * (2. * xi.at(1) - xi.at(0)) * (1. + xi.at(0));
  grad_shapefn_(2, 1) = 0.25 * (2. * xi.at(1) + xi.at(0)) * (1. + xi.at(0));
  grad_shapefn_(3, 1) = 0.25 * (2. * xi.at(1) - xi.at(0)) * (1. - xi.at(0));
  grad_shapefn_(4, 1) = -0.5 * (1. - (xi.at(0) * xi.at(0)));
  grad_shapefn_(5, 1) = -xi.at(1) * (1. + xi.at(0));
  grad_shapefn_(6, 1) = 0.5 * (1 - (xi.at(0) * xi.at(0)));
  grad_shapefn_(7, 1) = -xi.at(1) * (1. - xi.at(0));
  return grad_shapefn_;
}

// 9-node Quadrilateral Element
//! 3       6       2
//!   0-----0-----0
//!   |           |
//!   |           |
//! 7 0   8 0     0 5
//!   |           |
//!   |           |
//!   0-----0-----0
//!  0      4       1
template <>
inline Eigen::Matrix<double, 9, 1> felib::QuadrilateralShapeFn<2, 9>::shapefn(
    const std::array<double, 2>& xi) {

  shapefn_(0) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1.) * (xi.at(1) - 1.);
  shapefn_(1) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1.) * (xi.at(1) - 1.);
  shapefn_(2) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1.) * (xi.at(1) + 1.);
  shapefn_(3) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1.) * (xi.at(1) + 1.);
  shapefn_(4) =
      -0.5 * xi.at(1) * (xi.at(1) - 1.) * ((xi.at(0) * xi.at(0)) - 1.);
  shapefn_(5) =
      -0.5 * xi.at(0) * (xi.at(0) + 1.) * ((xi.at(1) * xi.at(1)) - 1.);
  shapefn_(6) =
      -0.5 * xi.at(1) * (xi.at(1) + 1.) * ((xi.at(0) * xi.at(0)) - 1.);
  shapefn_(7) =
      -0.5 * xi.at(0) * (xi.at(0) - 1.) * ((xi.at(1) * xi.at(1)) - 1.);
  shapefn_(8) = ((xi.at(0) * xi.at(0)) - 1.) * ((xi.at(1) * xi.at(1)) - 1.);
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 9, 2> felib::QuadrilateralShapeFn<
    2, 9>::grad_shapefn(const std::array<double, 2>& xi) {

  grad_shapefn_(0, 0) = 0.25 * xi.at(1) * (xi.at(1) - 1.) * (2 * xi.at(0) - 1.);
  grad_shapefn_(1, 0) = 0.25 * xi.at(1) * (xi.at(1) - 1.) * (2 * xi.at(0) + 1.);
  grad_shapefn_(2, 0) = 0.25 * xi.at(1) * (xi.at(1) + 1.) * (2 * xi.at(0) + 1.);
  grad_shapefn_(3, 0) = 0.25 * xi.at(1) * (xi.at(1) + 1.) * (2 * xi.at(0) - 1.);
  grad_shapefn_(4, 0) = -xi.at(0) * xi.at(1) * (xi.at(1) - 1.);
  grad_shapefn_(5, 0) =
      -0.5 * (2. * xi.at(0) + 1.) * ((xi.at(1) * xi.at(1)) - 1.);
  grad_shapefn_(6, 0) = -xi.at(0) * xi.at(1) * (xi.at(1) + 1.);
  grad_shapefn_(7, 0) =
      -0.5 * (2. * xi.at(0) - 1.) * ((xi.at(1) * xi.at(1)) - 1.);
  grad_shapefn_(8, 0) = 2. * xi.at(0) * ((xi.at(1) * xi.at(1)) - 1.);
  grad_shapefn_(0, 1) =
      0.25 * xi.at(0) * (xi.at(0) - 1.) * (2. * xi.at(1) - 1.);
  grad_shapefn_(1, 1) =
      0.25 * xi.at(0) * (xi.at(0) + 1.) * (2. * xi.at(1) - 1.);
  grad_shapefn_(2, 1) =
      0.25 * xi.at(0) * (xi.at(0) + 1.) * (2. * xi.at(1) + 1.);
  grad_shapefn_(3, 1) =
      0.25 * xi.at(0) * (xi.at(0) - 1.) * (2. * xi.at(1) + 1.);
  grad_shapefn_(4, 1) =
      -0.5 * (2. * xi.at(1) - 1.) * ((xi.at(0) * xi.at(0)) - 1.);
  grad_shapefn_(5, 1) = -xi.at(0) * xi.at(1) * (xi.at(0) + 1.);
  grad_shapefn_(6, 1) =
      -0.5 * (2. * xi.at(1) + 1.) * ((xi.at(0) * xi.at(0)) - 1.);
  grad_shapefn_(7, 1) = -xi.at(0) * xi.at(1) * (xi.at(0) - 1.);
  grad_shapefn_(8, 1) = 2. * xi.at(1) * ((xi.at(0) * xi.at(0)) - 1.);
  return grad_shapefn_;
}
