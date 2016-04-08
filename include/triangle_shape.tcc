// 3-node Triangle Element
//!   2 0
//!     |`\
//!     |  `\
//!     |    `\
//!     |      `\
//!     |        `\
//!   0 0----------0 1

template <>
inline Eigen::Matrix<double, 3, 1> felib::TriangleShape<
    2, 3>::evaluate_shape_fun(const std::array<double, 2>& xi) {

  shape_fun(0) = 1 - (xi.at(0) + xi.at(1));
  shape_fun(1) = xi.at(0);
  shape_fun(2) = xi.at(1);
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 3, 2> felib::TriangleShape<
    2, 3>::evaluate_grad_shape_fun(const std::array<double, 2>& xi) {

  grad_sfun(0, 0) = -1.;
  grad_sfun(1, 0) = 1.;
  grad_sfun(2, 0) = 0.;
  grad_sfun(0, 1) = -1.;
  grad_sfun(1, 1) = 0.;
  grad_sfun(2, 1) = 1.;
  return grad_sfun;
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
inline Eigen::Matrix<double, 6, 1> felib::TriangleShape<
    2, 6>::evaluate_shape_fun(const std::array<double, 2>& xi) {

  shape_fun(0) =
      (1. - xi.at(0) - xi.at(1)) * (1. - 2. * xi.at(0) - 2. * xi.at(1));
  shape_fun(1) = xi.at(0) * (2. * xi.at(0) - 1.);
  shape_fun(2) = xi.at(1) * (2. * xi.at(1) - 1.);
  shape_fun(3) = 4. * xi.at(0) * (1. - xi.at(0) - xi.at(1));
  shape_fun(4) = 4. * xi.at(0) * xi.at(1);
  shape_fun(5) = 4. * xi.at(1) * (1. - xi.at(0) - xi.at(1));
  return shape_fun;
}

template <>
inline Eigen::Matrix<double, 6, 2> felib::TriangleShape<
    2, 6>::evaluate_grad_shape_fun(const std::array<double, 2>& xi) {

  grad_sfun(0, 0) = 4. * xi.at(0) + 4. * xi.at(1) - 3.;
  grad_sfun(1, 0) = 4. * xi.at(0) - 1.;
  grad_sfun(2, 0) = 0;
  grad_sfun(3, 0) = 4. - 8. * xi.at(0) - 4. * xi.at(1);
  grad_sfun(4, 0) = 4. * xi.at(1);
  grad_sfun(5, 0) = -4. * xi.at(1);
  grad_sfun(0, 1) = 4. * xi.at(0) + 4. * xi.at(1) - 3.;
  grad_sfun(1, 1) = 0;
  grad_sfun(2, 1) = 4. * xi.at(1) - 1.;
  grad_sfun(3, 1) = -4. * xi.at(0);
  grad_sfun(4, 1) = 4. * xi.at(0);
  grad_sfun(5, 1) = 4. - 4. * xi.at(0) - 8. * xi.at(1);
  return grad_sfun;
}
