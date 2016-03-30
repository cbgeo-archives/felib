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
template<>
inline Eigen::Matrix<double, 8, 1> felib::HexahedronShape<3, 8>::evaluate_shape_fun(const std::array<double, 3> &xi) {

  shape_fun(0) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)); 
  shape_fun(1) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2));
  shape_fun(2) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shape_fun(3) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shape_fun(4) = 0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2)); 
  shape_fun(5) = 0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2));
  shape_fun(6) = 0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  shape_fun(7) = 0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  return shape_fun;
}

template<>
inline Eigen::Matrix<double, 8, 3> felib::HexahedronShape<3, 8>::evaluate_grad_shape_fun(const std::array<double, 3> &xi) {

  grad_sfun(0,0) = -0.125 * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_sfun(1,0) =  0.125 * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_sfun(2,0) =  0.125 * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_sfun(3,0) = -0.125 * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_sfun(4,0) = -0.125 * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_sfun(5,0) =  0.125 * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_sfun(6,0) =  0.125 * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_sfun(7,0) = -0.125 * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_sfun(0,1) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_sfun(1,1) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_sfun(2,1) =  0.125 * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_sfun(3,1) =  0.125 * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_sfun(4,1) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(2));
  grad_sfun(5,1) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_sfun(6,1) =  0.125 * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_sfun(7,1) =  0.125 * (1 - xi.at(0)) * (1 + xi.at(2));
  grad_sfun(0,2) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(1,2) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_sfun(2,2) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_sfun(3,2) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1));
  grad_sfun(4,2) =  0.125 * (1 - xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(5,2) =  0.125 * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_sfun(6,2) =  0.125 * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_sfun(7,2) =  0.125 * (1 - xi.at(0)) * (1 + xi.at(1));
  return grad_sfun;
}


template<>
inline Eigen::Matrix<double, 8, 3> felib::HexahedronShape<3, 8>::quadrature_points() {

  qpoints(0,0) = -0.57735; qpoints(0,1) = -0.57735; qpoints(0,2) = -0.57735;
  qpoints(1,0) =  0.57735; qpoints(1,1) = -0.57735; qpoints(1,2) = -0.57735;
  qpoints(2,0) =  0.57735; qpoints(2,2) =  0.57735; qpoints(2,2) = -0.57735;
  qpoints(3,0) = -0.57735; qpoints(3,1) =  0.57735; qpoints(3,2) = -0.57735;
  qpoints(4,0) = -0.57735; qpoints(4,1) = -0.57735; qpoints(4,2) =  0.57735;
  qpoints(5,0) =  0.57735; qpoints(5,1) = -0.57735; qpoints(5,2) =  0.57735;
  qpoints(6,0) =  0.57735; qpoints(6,2) =  0.57735; qpoints(6,2) =  0.57735;
  qpoints(7,0) = -0.57735; qpoints(7,1) =  0.57735; qpoints(7,2) =  0.57735;
  return qpoints;
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
template<>
inline Eigen::Matrix<double, 20, 1> felib::HexahedronShape<3, 20>::evaluate_shape_fun(const std::array<double, 3> &xi) {

  shape_fun(0) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) * (2 + xi.at(0) + xi.at(1) + xi.at(2)); 
  shape_fun(1) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) * (2 - xi.at(0) + xi.at(1) + xi.at(2));
  shape_fun(2) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) * (2 - xi.at(0) - xi.at(1) + xi.at(2));
  shape_fun(3) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) * (2 + xi.at(0) - xi.at(1) + xi.at(2));
  shape_fun(4) = -0.125 * (1 - xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) * (2 + xi.at(0) + xi.at(1) - xi.at(2)); 
  shape_fun(5) = -0.125 * (1 + xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2)) * (2 - xi.at(0) + xi.at(1) - xi.at(2));
  shape_fun(6) = -0.125 * (1 + xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) * (2 - xi.at(0) - xi.at(1) - xi.at(2));
  shape_fun(7) = -0.125 * (1 - xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2)) * (2 + xi.at(0) - xi.at(1) - xi.at(2));
  shape_fun(8) =  0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(1)) * (1 - xi.at(2));
  shape_fun(9) =  0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(0)) * (1 - xi.at(2));
  shape_fun(10) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(1)) * (1 - xi.at(2));
  shape_fun(11) = 0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(0)) * (1 - xi.at(2));
  shape_fun(12) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(0)) * (1 - xi.at(1));
  shape_fun(13) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(0)) * (1 - xi.at(1));
  shape_fun(14) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(0)) * (1 + xi.at(1));
  shape_fun(15) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(0)) * (1 + xi.at(1));
  shape_fun(16) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(1)) * (1 + xi.at(2));
  shape_fun(17) = 0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(0)) * (1 + xi.at(2));
  shape_fun(18) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(1)) * (1 + xi.at(2));
  shape_fun(19) = 0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(0)) * (1 + xi.at(2));
  return shape_fun;
}

template<>
inline Eigen::Matrix<double, 20, 3> felib::HexahedronShape<3, 20>::evaluate_grad_shape_fun(const std::array<double, 3> &xi) {

  grad_sfun(0,0) =  0.125 * (2*xi.at(0) + xi.at(1) + xi.at(2) + 1) * (1 - xi.at(1)) * (1 - xi.at(2)); 
  grad_sfun(1,0) = -0.125 * (-2*xi.at(0) + xi.at(1) + xi.at(2) + 1) * (1 - xi.at(1)) * (1 - xi.at(2)); 
  grad_sfun(2,0) = -0.125 * (-2*xi.at(0) - xi.at(1) + xi.at(2) + 1) * (1 + xi.at(1)) * (1 - xi.at(2)); 
  grad_sfun(3,0) =  0.125 * (2*xi.at(0) - xi.at(1) + xi.at(2) + 1) * (1 + xi.at(1)) * (1 - xi.at(2)); 
  grad_sfun(4,0) =  0.125 * (2*xi.at(0) + xi.at(1) - xi.at(2) + 1) * (1 - xi.at(1)) * (1 + xi.at(2)); 
  grad_sfun(5,0) = -0.125 * (-2*xi.at(0) + xi.at(1) - xi.at(2) + 1) * (1 - xi.at(1)) * (1 + xi.at(2)); 
  grad_sfun(6,0) = -0.125 * (-2*xi.at(0) - xi.at(1) - xi.at(2) + 1) * (1 + xi.at(1)) * (1 + xi.at(2)); 
  grad_sfun(7,0) =  0.125 * (2*xi.at(0) - xi.at(1) - xi.at(2) + 1) * (1 + xi.at(1)) * (1 + xi.at(2)); 
  grad_sfun(8,0) = -0.5 * xi.at(0) * (1 - xi.at(1)) * (1 - xi.at(2));
  grad_sfun(9,0) =  0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(2));
  grad_sfun(10,0) = -0.5 * xi.at(0) * (1 + xi.at(1)) * (1 - xi.at(2));
  grad_sfun(11,0) = -0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(2));
  grad_sfun(12,0) = -0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(1));
  grad_sfun(13,0) =  0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(1));
  grad_sfun(14,0) =  0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(1));
  grad_sfun(15,0) = -0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(1));
  grad_sfun(16,0) = -0.5 * xi.at(0) * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_sfun(17,0) =  0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(2));
  grad_sfun(18, 0) = -0.5 * xi.at(0) * (1 + xi.at(1)) * (1 + xi.at(2));
  grad_sfun(19,0) = -0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(2));

  grad_sfun(0,1) =  0.125 * (xi.at(0) + 2*xi.at(1) + xi.at(2) + 1) * (1 - xi.at(0)) * (1 - xi.at(2)); 
  grad_sfun(1,1) =  0.125 * (-xi.at(0) + 2*xi.at(1) + xi.at(2) + 1) * (1 + xi.at(0)) * (1 - xi.at(2)); 
  grad_sfun(2,1) = -0.125 * (-xi.at(0) - 2*xi.at(1) + xi.at(2) + 1) * (1 + xi.at(0)) * (1 - xi.at(2)); 
  grad_sfun(3,1) = -0.125 * (xi.at(0) - 2*xi.at(1) + xi.at(2) + 1) * (1 - xi.at(1)) * (1 - xi.at(2)); 
  grad_sfun(4,1) =  0.125 * (xi.at(0) + 2*xi.at(1) - xi.at(2) + 1) * (1 - xi.at(0)) * (1 + xi.at(2)); 
  grad_sfun(5,1) =  0.125 * (-xi.at(0) + 2*xi.at(1) - xi.at(2) + 1) * (1 + xi.at(0)) * (1 + xi.at(2)); 
  grad_sfun(6,1) = -0.125 * (-xi.at(0) - 2*xi.at(1) - xi.at(2) + 1) * (1 + xi.at(0)) * (1 + xi.at(2)); 
  grad_sfun(7,1) = -0.125 * (xi.at(0) - 2*xi.at(1) - xi.at(2) + 1) * (1 - xi.at(1)) * (1 + xi.at(2));
  grad_sfun(8,1) = -0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(2));
  grad_sfun(9,1) = -0.5 * xi.at(1) * (1 + xi.at(0)) * (1 - xi.at(2));
  grad_sfun(10,1) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(2));
  grad_sfun(11,1) = -0.5 * xi.at(1) * (1 - xi.at(0)) * (1 - xi.at(2));
  grad_sfun(12,1) = -0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(0));
  grad_sfun(13,1) = -0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(0));
  grad_sfun(14,1) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 + xi.at(0));
  grad_sfun(15,1) = 0.25 * (1 - xi.at(2)*xi.at(2)) * (1 - xi.at(0));
  grad_sfun(16,1) = -0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(2));
  grad_sfun(17,1) = -0.5 * xi.at(1) * (1 + xi.at(0)) * (1 + xi.at(2));
  grad_sfun(18,1) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(2));
  grad_sfun(19,1) = -0.5 * xi.at(1) * (1 - xi.at(0)) * (1 + xi.at(2));

  grad_sfun(0,2) = 0.125 * (xi.at(0) + xi.at(1) + 2*xi.at(2) + 1) * (1 - xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(1,2) = 0.125 * (-xi.at(0) + xi.at(1) + 2*xi.at(2) + 1) * (1 + xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(2,2) = 0.125 * (-xi.at(0) - xi.at(1) + 2*xi.at(2) + 1) * (1 + xi.at(0)) * (1 + xi.at(1)); 
  grad_sfun(3,2) = 0.125 * (xi.at(0) - xi.at(1) + 2*xi.at(2) + 1) * (1 - xi.at(1)) * (1 + xi.at(1)); 
  grad_sfun(4,2) = 0.125 * (xi.at(0) + xi.at(1) - 2*xi.at(2) + 1) * (1 - xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(5,2) = 0.125 * (-xi.at(0) + xi.at(1) - 2*xi.at(2) + 1) * (1 + xi.at(0)) * (1 - xi.at(1)); 
  grad_sfun(6,2) = 0.125 * (-xi.at(0) - xi.at(1) - 2*xi.at(2) + 1) * (1 + xi.at(0)) * (1 + xi.at(1)); 
  grad_sfun(7,2) = 0.125 * (xi.at(0) - xi.at(1) - 2*xi.at(2) + 1) * (1 - xi.at(1)) * (1 + xi.at(1));
  grad_sfun(8,2) = -0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(1));
  grad_sfun(9,2) = -0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(0));
  grad_sfun(10,2) = -0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(1));
  grad_sfun(11,2) = -0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(0));
  grad_sfun(12,2) = -0.5 * xi.at(2) * (1 - xi.at(0)) * (1 - xi.at(1));
  grad_sfun(13,2) = -0.5 * xi.at(2) * (1 + xi.at(0)) * (1 - xi.at(1));
  grad_sfun(14,2) = -0.5 * xi.at(2) * (1 + xi.at(0)) * (1 + xi.at(1));
  grad_sfun(15,2) = -0.5 * xi.at(2) * (1 - xi.at(0)) * (1 + xi.at(1));
  grad_sfun(16,2) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 - xi.at(1));
  grad_sfun(17,2) = 0.25 * (1 - xi.at(1)*xi.at(1)) * (1 + xi.at(0));
  grad_sfun(18,2) = 0.25 * (1 - xi.at(0)*xi.at(0)) * (1 + xi.at(1));
  grad_sfun(19,2) = 0.25 * (1 - xi.at(1)*xi.at(1)) * (1 - xi.at(0)); 
  return grad_sfun;
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
