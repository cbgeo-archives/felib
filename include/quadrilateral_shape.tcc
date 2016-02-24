namespace felib {
// 4-node Quadrilateral Element
//! 3 0----------0 2
//!   |          |
//!   |          |
//!   |          |
//!   |          |
//! 0 0----------0 1

template<> inline
void QuadrilateralShape<2, 4>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 1, 4> &sFun) {

  sFun(0) = 0.25 * (1 - xi.at(0)) * (1 - xi.at(1)); 
  sFun(1) = 0.25 * (1 + xi.at(0)) * (1 - xi.at(1));
  sFun(2) = 0.25 * (1 + xi.at(0)) * (1 + xi.at(1));
  sFun(3) = 0.25 * (1 - xi.at(0)) * (1 + xi.at(1));
}

template<> inline 
void QuadrilateralShape<2, 4>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 2, 4> &gradSfun) {

  gradSfun(0,0) = -0.25 * (1 - xi.at(1));
  gradSfun(0,1) =  0.25 * (1 - xi.at(1));
  gradSfun(0,2) =  0.25 * (1 + xi.at(1));
  gradSfun(0,3) = -0.25 * (1 + xi.at(1));
  gradSfun(1,0) = -0.25 * (1 - xi.at(0));
  gradSfun(1,1) = -0.25 * (1 + xi.at(0));
  gradSfun(1,2) =  0.25 * (1 + xi.at(0));
  gradSfun(1,3) =  0.25 * (1 - xi.at(0));
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

template<> inline
void QuadrilateralShape<2, 8>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 1, 8> &sFun) {

}

template<> inline
void QuadrilateralShape<2, 8>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 2, 8> &gradSfun) {


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
template<> inline
void QuadrilateralShape<2, 9>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 1, 9> &sFun) {

}

template<> inline
void QuadrilateralShape<2, 9>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 2, 9> &gradSfun) {


}

// quadrature points : 1x1 rule
template<unsigned Tdim, unsigned numFun>
template<>
void QuadrilateralShape::quadrature_points<1>(Eigen::Matrix<double, Tdim, 1> &qpoints) {

}


// quadrature points : 2x2 rule
template<unsigned Tdim, unsigned numFun>
template<>
void QuadrilateralShape::quadrature_points<4>(Eigen::Matrix<double, Tdim, 4> &qpoints) {

}

// quadrature points : 3x3 rule
template<unsigned Tdim, unsigned numFun>
template<>
void QuadrilateralShape::quadrature_points<9>(Eigen::Matrix<double, Tdim, 9> &qpoints) {

}

// quadrature points : 4x4 rule
template<unsigned Tdim, unsigned numFun>
template<>
void QuadrilateralShape::quadrature_points<16>(Eigen::Matrix<double, Tdim, 16> &qpoints) {

}

}
