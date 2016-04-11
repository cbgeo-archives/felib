// 8-node (Trilinear) Hexahedron Element
//!        7               6
//!          0_ _ _ _ _ _0
//!         /|           /|
//!        / |          / |
//!     4 0_ |_ _ _ _ _0 5|
//!       |  |         |  |
//!       |  |         |  |
//!       |  0_ _ _ _ _|_ 0
//!       | / 3        | / 2
//!       |/           |/
//!       0_ _ _ _ _ _ 0
//!     0               1
template <>
inline Eigen::Matrix<double, 8, 1> felib::HexahedronShapeFn<3, 8>::shapefn(
    const std::array<double, 3>& xi) {

  shapefn_(0) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2));
  shapefn_(1) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2));
  shapefn_(2) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shapefn_(3) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shapefn_(4) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2));
  shapefn_(5) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2));
  shapefn_(6) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  shapefn_(7) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 8, 3> felib::HexahedronShapeFn<3, 8>::grad_shapefn(
    const std::array<double, 3>& xi) {

  grad_shapefn_(0, 0) = -0.125 * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(1, 0) = 0.125 * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(2, 0) = 0.125 * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(3, 0) = -0.125 * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(4, 0) = -0.125 * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(5, 0) = 0.125 * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(6, 0) = 0.125 * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(7, 0) = -0.125 * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(0, 1) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(1, 1) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(2, 1) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(3, 1) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(4, 1) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(5, 1) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(6, 1) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(7, 1) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(0, 2) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(1, 2) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(2, 2) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(3, 2) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(4, 2) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(5, 2) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(6, 2) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(7, 2) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(1));
  return grad_shapefn_;
}

// 20-node (Serendipity) Hexahedron Element
//!        7       18          6
//!          0_ _ _ 0 _ _ _  0
//!          /|             / |
//!      19 0 |         17 0  |
//!        /  0 15        /   |
//!    4  0_ _| _ 0 _ _ _ 0 5 0 14
//!       |   |  16      |    |
//!       |   |      10  |    |
//!       | 3 0_ _ _ 0 _ |_ _ 0   2
//!    12 0  /           0 13 /
//!       | 0 11         |  0 9
//!       |/             | /
//!       0_ _ _ 0 _ _ _ 0
//!   0          8         1
template <>
inline Eigen::Matrix<double, 20, 1> felib::HexahedronShapeFn<3, 20>::shapefn(
    const std::array<double, 3>& xi) {

  shapefn_(0) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) *
                (2 + xi.at(0) + xi.at(1) + xi.at(2));
  shapefn_(1) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) *
                (2 - xi.at(0) + xi.at(1) + xi.at(2));
  shapefn_(2) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) *
                (2 - xi.at(0) - xi.at(1) + xi.at(2));
  shapefn_(3) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) *
                (2 + xi.at(0) - xi.at(1) + xi.at(2));
  shapefn_(4) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) *
                (2 + xi.at(0) + xi.at(1) - xi.at(2));
  shapefn_(5) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) *
                (2 - xi.at(0) + xi.at(1) - xi.at(2));
  shapefn_(6) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) *
                (2 - xi.at(0) - xi.at(1) - xi.at(2));
  shapefn_(7) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) *
                (2 + xi.at(0) - xi.at(1) - xi.at(2));
  shapefn_(8) =
      0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2));
  shapefn_(9) =
      0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(0)) * (1 - xi.at(2));
  shapefn_(10) =
      0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shapefn_(11) =
      0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(0)) * (1 - xi.at(2));
  shapefn_(12) =
      0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(0)) * (1 - xi.at(1));
  shapefn_(13) =
      0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(0)) * (1 - xi.at(1));
  shapefn_(14) =
      0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(0)) * (1 + xi.at(1));
  shapefn_(15) =
      0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(0)) * (1 + xi.at(1));
  shapefn_(16) =
      0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2));
  shapefn_(17) =
      0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(0)) * (1 + xi.at(2));
  shapefn_(18) =
      0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  shapefn_(19) =
      0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(0)) * (1 + xi.at(2));
  return shapefn_;
}

template <>
inline Eigen::Matrix<double, 20, 3> felib::HexahedronShapeFn<
    3, 20>::grad_shapefn(const std::array<double, 3>& xi) {

  grad_shapefn_(0, 0) = 0.125 * (2 * xi.at(0) + xi.at(1) + xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(1, 0) = -0.125 * (-2 * xi.at(0) + xi.at(1) + xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(2, 0) = -0.125 * (-2 * xi.at(0) - xi.at(1) + xi.at(2) + 1) *
                        (1 + xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(3, 0) = 0.125 * (2 * xi.at(0) - xi.at(1) + xi.at(2) + 1) *
                        (1 + xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(4, 0) = 0.125 * (2 * xi.at(0) + xi.at(1) - xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(5, 0) = -0.125 * (-2 * xi.at(0) + xi.at(1) - xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(6, 0) = -0.125 * (-2 * xi.at(0) - xi.at(1) - xi.at(2) + 1) *
                        (1 + xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(7, 0) = 0.125 * (2 * xi.at(0) - xi.at(1) - xi.at(2) + 1) *
                        (1 + xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(8, 0) = -0.5 * xi.at(0) * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(9, 0) = 0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(10, 0) = -0.5 * xi.at(0) * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(11, 0) = -0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(12, 0) = -0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(1));
  grad_shapefn_(13, 0) = 0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(1));
  grad_shapefn_(14, 0) = 0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(1));
  grad_shapefn_(15, 0) = -0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(1));
  grad_shapefn_(16, 0) = -0.5 * xi.at(0) * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(17, 0) = 0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(18, 0) = -0.5 * xi.at(0) * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(19, 0) = -0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(2));

  grad_shapefn_(0, 1) = 0.125 * (xi.at(0) + 2 * xi.at(1) + xi.at(2) + 1) *
                        (1 - xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(1, 1) = 0.125 * (-xi.at(0) + 2 * xi.at(1) + xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(2, 1) = -0.125 * (-xi.at(0) - 2 * xi.at(1) + xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(3, 1) = -0.125 * (xi.at(0) - 2 * xi.at(1) + xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 - xi.at(2));
  grad_shapefn_(4, 1) = 0.125 * (xi.at(0) + 2 * xi.at(1) - xi.at(2) + 1) *
                        (1 - xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(5, 1) = 0.125 * (-xi.at(0) + 2 * xi.at(1) - xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(6, 1) = -0.125 * (-xi.at(0) - 2 * xi.at(1) - xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(7, 1) = -0.125 * (xi.at(0) - 2 * xi.at(1) - xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 + xi.at(2));
  grad_shapefn_(8, 1) = -0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(9, 1) = -0.5 * xi.at(1) * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(10, 1) = 0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(11, 1) = -0.5 * xi.at(1) * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_shapefn_(12, 1) = -0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(0));
  grad_shapefn_(13, 1) = -0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(0));
  grad_shapefn_(14, 1) = 0.25 * (1 - xi.at(2) * xi.at(2)) * (1 + xi.at(0));
  grad_shapefn_(15, 1) = 0.25 * (1 - xi.at(2) * xi.at(2)) * (1 - xi.at(0));
  grad_shapefn_(16, 1) = -0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(17, 1) = -0.5 * xi.at(1) * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(18, 1) = 0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(2));
  grad_shapefn_(19, 1) = -0.5 * xi.at(1) * (1 - xi.at(0)) * (1 + xi.at(2));

  grad_shapefn_(0, 2) = 0.125 * (xi.at(0) + xi.at(1) + 2 * xi.at(2) + 1) *
                        (1 - xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(1, 2) = 0.125 * (-xi.at(0) + xi.at(1) + 2 * xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(2, 2) = 0.125 * (-xi.at(0) - xi.at(1) + 2 * xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(3, 2) = 0.125 * (xi.at(0) - xi.at(1) + 2 * xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 + xi.at(1));
  grad_shapefn_(4, 2) = 0.125 * (xi.at(0) + xi.at(1) - 2 * xi.at(2) + 1) *
                        (1 - xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(5, 2) = 0.125 * (-xi.at(0) + xi.at(1) - 2 * xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(6, 2) = 0.125 * (-xi.at(0) - xi.at(1) - 2 * xi.at(2) + 1) *
                        (1 + xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(7, 2) = 0.125 * (xi.at(0) - xi.at(1) - 2 * xi.at(2) + 1) *
                        (1 - xi.at(1)) * (1 + xi.at(1));
  grad_shapefn_(8, 2) = -0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(9, 2) = -0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(0));
  grad_shapefn_(10, 2) = -0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(11, 2) = -0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(0));
  grad_shapefn_(12, 2) = -0.5 * xi.at(2) * (1 - xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(13, 2) = -0.5 * xi.at(2) * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(14, 2) = -0.5 * xi.at(2) * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(15, 2) = -0.5 * xi.at(2) * (1 - xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(16, 2) = 0.25 * (1 - xi.at(0) * xi.at(0)) * (1 - xi.at(1));
  grad_shapefn_(17, 2) = 0.25 * (1 - xi.at(1) * xi.at(1)) * (1 + xi.at(0));
  grad_shapefn_(18, 2) = 0.25 * (1 - xi.at(0) * xi.at(0)) * (1 + xi.at(1));
  grad_shapefn_(19, 2) = 0.25 * (1 - xi.at(1) * xi.at(1)) * (1 - xi.at(0));
  return grad_shapefn_;
}

// 27-node (Triquadratic) Hexahedron Element
//!          7           18             6
//!            0_ _ _ _ _ 0 _ _ _ _ _ 0
//!            /|                     /|
//!           / |                    / |
//!          /  |    25             /  |
//!      19 0   |     0        17  0 17|
//!        /    |      23 0       /    |
//!       /  15 0                /     0 14
//!      /      |               /      |
//!  4  0_ _ _ _|_ 0 _ _ _ _ _ 0 5     |
//!     |       | 16           |       |
//!     |  0 24 |              |   0 22|
//!     |       |         10   |       |
//!     |     3 0_ _ _ _ _ 0_ _|_ _ _  0  2
//!     |      /               |      /
//!  12 0     /    0 21        0 13  /
//!     |    /                 |    /
//!     |11 0         0        |   0 9
//!     |  /         20        |  /
//!     | /                    | /
//!     |/                     |/
//!     0_ _ _ _ _ 0 _ _ _ _ _ 0
//!   0            8             1
