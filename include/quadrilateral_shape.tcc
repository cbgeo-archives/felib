// 4-node Quadrilateral Element
//! 3 0----------0 2
//!   |          |
//!   |          |
//!   |          |
//!   |          |
//! 0 0----------0 1

template <>
inline Eigen::Matrix<double, 4, 1> felib::QuadrilateralShape<
    2, 4>::evaluate_shape_fun(const std::array<double, 2>& xi) {

  shape_fun(0) = 0.25 * (1 - xi.at(0)) * (1 - xi.at(1));
  shape_fun(1) = 0.25 * (1 + xi.at(0)) * (1 - xi.at(1));
  shape_fun(2) = 0.25 * (1 + xi.at(0)) * (1 + xi.at(1));
  shape_fun(3) = 0.25 * (1 - xi.at(0)) * (1 + xi.at(1));
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 4, 2> felib::QuadrilateralShape<
    2, 4>::evaluate_grad_shape_fun(const std::array<double, 2>& xi) {

  grad_sfun(0, 0) = -0.25 * (1 - xi.at(1));
  grad_sfun(1, 0) = 0.25 * (1 - xi.at(1));
  grad_sfun(2, 0) = 0.25 * (1 + xi.at(1));
  grad_sfun(3, 0) = -0.25 * (1 + xi.at(1));
  grad_sfun(0, 1) = -0.25 * (1 - xi.at(0));
  grad_sfun(1, 1) = -0.25 * (1 + xi.at(0));
  grad_sfun(2, 1) = 0.25 * (1 + xi.at(0));
  grad_sfun(3, 1) = 0.25 * (1 - xi.at(0));
  return grad_sfun;
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
inline Eigen::Matrix<double, 8, 1> felib::QuadrilateralShape<
    2, 8>::evaluate_shape_fun(const std::array<double, 2>& xi) {

  shape_fun(0) =
      -0.25 * (1 - xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) + xi.at(1) + 1);
  shape_fun(1) =
      0.25 * (1 + xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) - xi.at(1) - 1);
  shape_fun(2) =
      0.25 * (1 + xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) + xi.at(1) - 1);
  shape_fun(3) =
      -0.25 * (1 - xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) - xi.at(1) + 1);
  shape_fun(4) = 0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 - xi.at(1));
  shape_fun(5) = 0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 + xi.at(0));
  shape_fun(6) = 0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 + xi.at(1));
  shape_fun(7) = 0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 - xi.at(0));
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 8, 2> felib::QuadrilateralShape<
    2, 8>::evaluate_grad_shape_fun(const std::array<double, 2>& xi) {

  grad_sfun(0, 0) = 0.25 * (2 * xi.at(0) + xi.at(1)) * (1 - xi.at(1));
  grad_sfun(1, 0) = 0.25 * (2 * xi.at(0) - xi.at(1)) * (1 - xi.at(1));
  grad_sfun(2, 0) = 0.25 * (2 * xi.at(0) + xi.at(1)) * (1 + xi.at(1));
  grad_sfun(3, 0) = 0.25 * (2 * xi.at(0) - xi.at(1)) * (1 + xi.at(1));
  grad_sfun(4, 0) = -xi.at(0) * (1 - xi.at(1));
  grad_sfun(5, 0) = 0.5 * (1 - (xi.at(1) * xi.at(1)));
  grad_sfun(6, 0) = -xi.at(0) * (1 + xi.at(1));
  grad_sfun(7, 0) = -0.5 * (1 - (xi.at(1) * xi.at(1)));
  grad_sfun(0, 1) = 0.25 * (2 * xi.at(1) + xi.at(0)) * (1 - xi.at(0));
  grad_sfun(1, 1) = 0.25 * (2 * xi.at(1) - xi.at(0)) * (1 + xi.at(0));
  grad_sfun(2, 1) = 0.25 * (2 * xi.at(1) + xi.at(0)) * (1 + xi.at(0));
  grad_sfun(3, 1) = 0.25 * (2 * xi.at(1) - xi.at(0)) * (1 - xi.at(0));
  grad_sfun(4, 1) = -0.5 * (1 - (xi.at(0) * xi.at(0)));
  grad_sfun(5, 1) = -xi.at(1) * (1 + xi.at(0));
  grad_sfun(6, 1) = 0.5 * (1 - (xi.at(0) * xi.at(0)));
  grad_sfun(7, 1) = -xi.at(1) * (1 - xi.at(0));
  return grad_sfun;
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
inline Eigen::Matrix<double, 9, 1> felib::QuadrilateralShape<
    2, 9>::evaluate_shape_fun(const std::array<double, 2>& xi) {

  shape_fun(0) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1) * (xi.at(1) - 1);
  shape_fun(1) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1) * (xi.at(1) - 1);
  shape_fun(2) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1) * (xi.at(1) + 1);
  shape_fun(3) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1) * (xi.at(1) + 1);
  shape_fun(4) = -0.5 * xi.at(1) * (xi.at(1) - 1) * ((xi.at(0) * xi.at(0)) - 1);
  shape_fun(5) = -0.5 * xi.at(0) * (xi.at(0) + 1) * ((xi.at(1) * xi.at(1)) - 1);
  shape_fun(6) = -0.5 * xi.at(1) * (xi.at(1) + 1) * ((xi.at(0) * xi.at(0)) - 1);
  shape_fun(7) = -0.5 * xi.at(0) * (xi.at(0) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  shape_fun(8) = ((xi.at(0) * xi.at(0)) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 9, 2> felib::QuadrilateralShape<
    2, 9>::evaluate_grad_shape_fun(const std::array<double, 2>& xi) {

  grad_sfun(0, 0) = 0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) - 1);
  grad_sfun(1, 0) = 0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) + 1);
  grad_sfun(2, 0) = 0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) + 1);
  grad_sfun(3, 0) = 0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) - 1);
  grad_sfun(4, 0) = -xi.at(0) * xi.at(1) * (xi.at(1) - 1);
  grad_sfun(5, 0) = -0.5 * (2 * xi.at(0) + 1) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(6, 0) = -xi.at(0) * xi.at(1) * (xi.at(1) + 1);
  grad_sfun(7, 0) = -0.5 * (2 * xi.at(0) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(8, 0) = 2 * xi.at(0) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(0, 1) = 0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) - 1);
  grad_sfun(1, 1) = 0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) - 1);
  grad_sfun(2, 1) = 0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) + 1);
  grad_sfun(3, 1) = 0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) + 1);
  grad_sfun(4, 1) = -0.5 * (2 * xi.at(1) - 1) * ((xi.at(0) * xi.at(0)) - 1);
  grad_sfun(5, 1) = -xi.at(0) * xi.at(1) * (xi.at(0) + 1);
  grad_sfun(6, 1) = -0.5 * (2 * xi.at(1) + 1) * ((xi.at(0) * xi.at(0)) - 1);
  grad_sfun(7, 1) = -xi.at(0) * xi.at(1) * (xi.at(0) - 1);
  grad_sfun(8, 1) = 2 * xi.at(1) * ((xi.at(0) * xi.at(0)) - 1);
  return grad_sfun;
}
