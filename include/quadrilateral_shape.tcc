// 4-node Quadrilateral Element
//! 3 0----------0 2
//!   |          |
//!   |          |
//!   |          |
//!   |          |
//! 0 0----------0 1

template<>
inline void felib::QuadrilateralShape<2, 4>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 4, 1> &sFun) {

  sFun(0) = 0.25 * (1 - xi.at(0)) * (1 - xi.at(1)); 
  sFun(1) = 0.25 * (1 + xi.at(0)) * (1 - xi.at(1));
  sFun(2) = 0.25 * (1 + xi.at(0)) * (1 + xi.at(1));
  sFun(3) = 0.25 * (1 - xi.at(0)) * (1 + xi.at(1));
}

template<>
inline void felib::QuadrilateralShape<2, 4>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 4, 2> &gradSfun) {

  gradSfun(0,0) = -0.25 * (1 - xi.at(1));
  gradSfun(1,0) =  0.25 * (1 - xi.at(1));
  gradSfun(2,0) =  0.25 * (1 + xi.at(1));
  gradSfun(3,0) = -0.25 * (1 + xi.at(1));
  gradSfun(0,1) = -0.25 * (1 - xi.at(0));
  gradSfun(1,1) = -0.25 * (1 + xi.at(0));
  gradSfun(2,1) =  0.25 * (1 + xi.at(0));
  gradSfun(3,1) =  0.25 * (1 - xi.at(0));
}


template<>
inline void felib::QuadrilateralShape<2, 4>::quadrature_points(Eigen::Matrix<double, 4, 2> &qpoints) {

  qpoints(0,0) = -0.57735; qpoints(0,1) = -0.57735;
  qpoints(1,0) =  0.57735; qpoints(1,1) = -0.57735;
  qpoints(2,0) = -0.57735; qpoints(3,2) =  0.57735; 
  qpoints(3,0) =  0.57735; qpoints(2,1) =  0.57735;

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

template<> 
inline void felib::QuadrilateralShape<2, 8>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 8, 1> &sFun) {

  sFun(0) = -0.25 * (1 - xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) + xi.at(1) + 1);
  sFun(1) =  0.25 * (1 + xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) - xi.at(1) - 1);
  sFun(2) =  0.25 * (1 + xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) + xi.at(1) - 1);
  sFun(3) = -0.25 * (1 - xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) - xi.at(1) + 1);
  sFun(4) =   0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 - xi.at(1));
  sFun(5) =   0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 + xi.at(0));
  sFun(6) =   0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 + xi.at(1));
  sFun(7) =   0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 - xi.at(0));
}

template<>
inline void felib::QuadrilateralShape<2, 8>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 8, 2> &gradSfun) {

  gradSfun(0,0) =  0.25 * (2 * xi.at(0) + xi.at(1)) * (1 - xi.at(1));
  gradSfun(1,0) =  0.25 * (2 * xi.at(0) - xi.at(1)) * (1 - xi.at(1));
  gradSfun(2,0) =  0.25 * (2 * xi.at(0) + xi.at(1)) * (1 + xi.at(1));
  gradSfun(3,0) =  0.25 * (2 * xi.at(0) - xi.at(1)) * (1 + xi.at(1));
  gradSfun(4,0) = -xi.at(0) * (1 - xi.at(1));
  gradSfun(5,0) =  0.5 * (1 - (xi.at(1) * xi.at(1)));
  gradSfun(6,0) = -xi.at(0) * (1 + xi.at(1));
  gradSfun(7,0) = -0.5 * (1 - (xi.at(1) * xi.at(1)));
  gradSfun(0,1) =  0.25 * (2 * xi.at(1) + xi.at(0)) * (1 - xi.at(0));
  gradSfun(1,1) =  0.25 * (2 * xi.at(1) - xi.at(0)) * (1 + xi.at(0));
  gradSfun(2,1) =  0.25 * (2 * xi.at(1) + xi.at(0)) * (1 + xi.at(0));
  gradSfun(3,1) =  0.25 * (2 * xi.at(1) - xi.at(0)) * (1 - xi.at(0));
  gradSfun(4,1) = -0.5 * (1 - (xi.at(0) * xi.at(0)));
  gradSfun(5,1) = -xi.at(1) * (1 + xi.at(0));
  gradSfun(6,1) =  0.5 * (1 - (xi.at(0) * xi.at(0)));
  gradSfun(7,1) = -xi.at(1) * (1 - xi.at(0));

}

template<>
inline void felib::QuadrilateralShape<2, 8>::quadrature_points(Eigen::Matrix<double, 8, 2> &qpoints) {

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
template<> 
inline void felib::QuadrilateralShape<2, 9>::evaluate_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 9, 1> &sFun) {

  sFun(0) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1) * (xi.at(1) - 1);
  sFun(1) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1) * (xi.at(1) - 1);
  sFun(2) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) + 1) * (xi.at(1) + 1);
  sFun(3) = 0.25 * xi.at(0) * xi.at(1) * (xi.at(0) - 1) * (xi.at(1) + 1);
  sFun(4) = -0.5 * xi.at(1) * (xi.at(1) - 1) * ((xi.at(0) * xi.at(0)) - 1);
  sFun(5) = -0.5 * xi.at(0) * (xi.at(0) + 1) * ((xi.at(1) * xi.at(1)) - 1);
  sFun(6) = -0.5 * xi.at(1) * (xi.at(1) + 1) * ((xi.at(0) * xi.at(0)) - 1);
  sFun(7) = -0.5 * xi.at(0) * (xi.at(0) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  sFun(8) = ((xi.at(0) * xi.at(0)) - 1) * ((xi.at(1) * xi.at(1)) - 1)

}

template<> 
inline void felib::QuadrilateralShape<2, 9>::evaluate_grad_shape_fun(const std::array<double, 2> &xi, Eigen::Matrix<double, 9, 2> &gradSfun) {

  gradSfun(0,0) =  0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) - 1);
  gradSfun(1,0) =  0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) + 1);
  gradSfun(2,0) =  0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) + 1);
  gradSfun(3,0) =  0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) - 1);
  gradSfun(4,0) = -xi.at(0) * xi.at(1) * (xi.at(1) - 1);
  gradSfun(5,0) = -0.5 * (2 * xi.at(0) + 1) * ((xi.at(1) * xi.at(1)) - 1);
  gradSfun(6,0) = -xi.at(0) * xi.at(1) * (xi.at(1) + 1);
  gradSfun(7,0) = -0.5 * (2 * xi.at(0) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  gradSfun(8,0) =  2 * xi.at(0) * ((xi.at(1) * xi.at(1)) - 1);
  gradSfun(0,1) =  0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) - 1);
  gradSfun(1,1) =  0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) - 1);
  gradSfun(2,1) =  0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) + 1);
  gradSfun(3,1) =  0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) + 1);
  gradSfun(4,1) = -0.5 * (2 * xi.at(1) - 1) * ((xi.at(0) * xi.at(0)) - 1);
  gradSfun(5,1) = -xi.at(0) * xi.at(1) * (xi.at(0) + 1);
  gradSfun(6,1) = -0.5 * (2 * xi.at(1) + 1) * ((xi.at(0) * xi.at(0)) - 1);
  gradSfun(7,1) = -xi.at(0) * xi.at(1) * (xi.at(0) - 1);
  gradSfun(8,1) =  2 * xi.at(1) * ((xi.at(0) * xi.at(0)) - 1);
}

template<>
inline void felib::QuadrilateralShape<2, 9>::quadrature_points(Eigen::Matrix<double, 9, 2> &qpoints) {

  qpoints(0,0) = -0.774597; qpoints(0,1) = -0.774597;
  qpoints(1,0) =  0.000000; qpoints(1,1) = -0.774597;
  qpoints(2,0) =  0.774597; qpoints(2,1) = -0.774597;
  qpoints(3,0) = -0.774597; qpoints(3,1) =  0.000000;
  qpoints(4,0) =  0.000000; qpoints(4,1) =  0.000000;
  qpoints(5,0) =  0.774597; qpoints(5,1) =  0.000000;
  qpoints(6,0) = -0.774597; qpoints(6,1) =  0.774597;
  qpoints(7,0) =  0.000000; qpoints(7,1) =  0.774597;
  qpoints(8,0) =  0.774597; qpoints(8,1) =  0.774597;
}

 
template<unsigned Tdim, unsigned Nfunctions>
template<unsigned p>
void felib::QuadrilateralShape<Tdim, Nfunctions>::custom_quadrature_points(Eigen::Matrix<double, p, Tdim> &qpoints) {
  if (p == 1) {
    qpoints(0,0) = 0.; qpoints(0,1) = 0.;
  }
  else if (p == 4) {
    qpoints(0,0) = -0.57735; qpoints(0,1) = -0.57735;
    qpoints(1,0) =  0.57735; qpoints(1,1) = -0.57735;
    qpoints(2,0) = -0.57735; qpoints(3,2) =  0.57735;
    qpoints(3,0) =  0.57735; qpoints(2,1) =  0.57735;
  }
  else if (p == 9) {
    qpoints(0,0) = -0.774597; qpoints(0,1) = -0.774597;
    qpoints(1,0) =  0.000000; qpoints(1,1) = -0.774597;
    qpoints(2,0) =  0.774597; qpoints(2,1) = -0.774597;
    qpoints(3,0) = -0.774597; qpoints(3,1) =  0.000000;
    qpoints(4,0) =  0.000000; qpoints(4,1) =  0.000000;
    qpoints(5,0) =  0.774597; qpoints(5,1) =  0.000000;
    qpoints(6,0) = -0.774597; qpoints(6,1) =  0.774597;
    qpoints(7,0) =  0.000000; qpoints(7,1) =  0.774597;
    qpoints(8,0) =  0.774597; qpoints(8,1) =  0.774597;
  }
  else if (p == 16) {
    qpoints(0,0) = -0.861136; qpoints(0,1) = -0.861136;
    qpoints(1,0) = -0.339981; qpoints(1,1) = -0.861136;
    qpoints(2,0) =  0.339981; qpoints(2,1) = -0.861136;
    qpoints(3,0) =  0.861136; qpoints(3,1) = -0.861136;
    qpoints(4,0) = -0.861136; qpoints(0,1) = -0.339981;
    qpoints(5,0) = -0.339981; qpoints(1,1) = -0.339981;
    qpoints(6,0) =  0.339981; qpoints(2,1) = -0.339981;
    qpoints(7,0) =  0.861136; qpoints(3,1) = -0.339981;
    qpoints(8,0) = -0.861136; qpoints(0,1) =  0.339981;
    qpoints(9,0) = -0.339981; qpoints(1,1) =  0.339981;
    qpoints(10,0) =  0.339981; qpoints(2,1) = 0.339981;
    qpoints(11,0) =  0.861136; qpoints(3,1) = 0.339981;
    qpoints(12,0) = -0.861136; qpoints(0,1) = 0.861136;
    qpoints(13,0) = -0.339981; qpoints(1,1) = 0.861136;
    qpoints(14,0) =  0.339981; qpoints(2,1) = 0.861136;
    qpoints(15,0) =  0.861136; qpoints(3,1) = 0.861136;
  }
}





