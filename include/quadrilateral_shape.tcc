// 4-node Quadrilateral Element
//! 3 0----------0 2
//!   |          |
//!   |          |
//!   |          |
//!   |          |
//! 0 0----------0 1

template<>
inline Eigen::Matrix<double, 4, 1> felib::QuadrilateralShape<2, 4>::evaluate_shape_fun(const std::array<double, 2> &xi) {

  shape_fun(0) = 0.25 * (1 - xi.at(0)) * (1 - xi.at(1)); 
  shape_fun(1) = 0.25 * (1 + xi.at(0)) * (1 - xi.at(1));
  shape_fun(2) = 0.25 * (1 + xi.at(0)) * (1 + xi.at(1));
  shape_fun(3) = 0.25 * (1 - xi.at(0)) * (1 + xi.at(1));
  return shape_fun;
}

template<>
inline Eigen::Matrix<double, 4, 2> felib::QuadrilateralShape<2, 4>::evaluate_grad_shape_fun(const std::array<double, 2> &xi) {

  grad_sfun(0,0) = -0.25 * (1 - xi.at(1));
  grad_sfun(1,0) =  0.25 * (1 - xi.at(1));
  grad_sfun(2,0) =  0.25 * (1 + xi.at(1));
  grad_sfun(3,0) = -0.25 * (1 + xi.at(1));
  grad_sfun(0,1) = -0.25 * (1 - xi.at(0));
  grad_sfun(1,1) = -0.25 * (1 + xi.at(0));
  grad_sfun(2,1) =  0.25 * (1 + xi.at(0));
  grad_sfun(3,1) =  0.25 * (1 - xi.at(0));
  return grad_sfun;
}

template<>
inline Eigen::Matrix<double, 4, 2> felib::QuadrilateralShape<2, 4>::quadrature_points() {

  qpoints(0,0) = -0.57735; qpoints(0,1) = -0.57735;
  qpoints(1,0) =  0.57735; qpoints(1,1) = -0.57735;
  qpoints(2,0) = -0.57735; qpoints(3,2) =  0.57735; 
  qpoints(3,0) =  0.57735; qpoints(2,1) =  0.57735;
  return qpoints;

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
inline Eigen::Matrix<double, 8, 1> felib::QuadrilateralShape<2, 8>::evaluate_shape_fun(const std::array<double, 2> &xi) {

  shape_fun(0) = -0.25 * (1 - xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) + xi.at(1) + 1);
  shape_(1) =  0.25 * (1 + xi.at(0)) * (1 - xi.at(1)) * (xi.at(0) - xi.at(1) - 1);
  shape_fun(2) =  0.25 * (1 + xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) + xi.at(1) - 1);
  shape_fun(3) = -0.25 * (1 - xi.at(0)) * (1 + xi.at(1)) * (xi.at(0) - xi.at(1) + 1);
  shape_fun(4) =   0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 - xi.at(1));
  shape_fun(5) =   0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 + xi.at(0));
  shape_fun(6) =   0.5 * (1 - (xi.at(0) * xi.at(0))) * (1 + xi.at(1));
  shape_fun(7) =   0.5 * (1 - (xi.at(1) * xi.at(1))) * (1 - xi.at(0));
  return shape_fun;
}

template<>
inline Eigen::Matrix<double, 8, 2> felib::QuadrilateralShape<2, 8>::evaluate_grad_shape_fun(const std::array<double, 2> &xi) {

  grad_sfun(0,0) =  0.25 * (2 * xi.at(0) + xi.at(1)) * (1 - xi.at(1));
  grad_sfun(1,0) =  0.25 * (2 * xi.at(0) - xi.at(1)) * (1 - xi.at(1));
  grad_sfun(2,0) =  0.25 * (2 * xi.at(0) + xi.at(1)) * (1 + xi.at(1));
  grad_sfun(3,0) =  0.25 * (2 * xi.at(0) - xi.at(1)) * (1 + xi.at(1));
  grad_sfun(4,0) = -xi.at(0) * (1 - xi.at(1));
  grad_sfun(5,0) =  0.5 * (1 - (xi.at(1) * xi.at(1)));
  grad_sfun(6,0) = -xi.at(0) * (1 + xi.at(1));
  grad_sfun(7,0) = -0.5 * (1 - (xi.at(1) * xi.at(1)));
  grad_sfun(0,1) =  0.25 * (2 * xi.at(1) + xi.at(0)) * (1 - xi.at(0));
  grad_sfun(1,1) =  0.25 * (2 * xi.at(1) - xi.at(0)) * (1 + xi.at(0));
  grad_sfun(2,1) =  0.25 * (2 * xi.at(1) + xi.at(0)) * (1 + xi.at(0));
  grad_sfun(3,1) =  0.25 * (2 * xi.at(1) - xi.at(0)) * (1 - xi.at(0));
  grad_sfun(4,1) = -0.5 * (1 - (xi.at(0) * xi.at(0)));
  grad_sfun(5,1) = -xi.at(1) * (1 + xi.at(0));
  grad_sfun(6,1) =  0.5 * (1 - (xi.at(0) * xi.at(0)));
  grad_sfun(7,1) = -xi.at(1) * (1 - xi.at(0));
  return grad_sfun;
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
inline Eigen::Matrix<double, 9, 1> felib::QuadrilateralShape<2, 9>::evaluate_shape_fun(const std::array<double, 2> &xi) {

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

template<> 
inline Eigen::Matrix<double, 9, 2> felib::QuadrilateralShape<2, 9>::evaluate_grad_shape_fun(const std::array<double, 2> &xi) {

  grad_sfun(0,0) =  0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) - 1);
  grad_sfun(1,0) =  0.25 * xi.at(1) * (xi.at(1) - 1) * (2 * xi.at(0) + 1);
  grad_sfun(2,0) =  0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) + 1);
  grad_sfun(3,0) =  0.25 * xi.at(1) * (xi.at(1) + 1) * (2 * xi.at(0) - 1);
  grad_sfun(4,0) = -xi.at(0) * xi.at(1) * (xi.at(1) - 1);
  grad_sfun(5,0) = -0.5 * (2 * xi.at(0) + 1) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(6,0) = -xi.at(0) * xi.at(1) * (xi.at(1) + 1);
  grad_sfun(7,0) = -0.5 * (2 * xi.at(0) - 1) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(8,0) =  2 * xi.at(0) * ((xi.at(1) * xi.at(1)) - 1);
  grad_sfun(0,1) =  0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) - 1);
  grad_sfun(1,1) =  0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) - 1);
  grad_sfun(2,1) =  0.25 * xi.at(0) * (xi.at(0) + 1) * (2 * xi.at(1) + 1);
  grad_sfun(3,1) =  0.25 * xi.at(0) * (xi.at(0) - 1) * (2 * xi.at(1) + 1);
  grad_sfun(4,1) = -0.5 * (2 * xi.at(1) - 1) * ((xi.at(0) * xi.at(0)) - 1);
  grad_sfun(5,1) = -xi.at(0) * xi.at(1) * (xi.at(0) + 1);
  grad_sfun(6,1) = -0.5 * (2 * xi.at(1) + 1) * ((xi.at(0) * xi.at(0)) - 1);
  grad_sfun(7,1) = -xi.at(0) * xi.at(1) * (xi.at(0) - 1);
  grad_sfun(8,1) =  2 * xi.at(1) * ((xi.at(0) * xi.at(0)) - 1);
  return grad_sfun;
}

template<>
inline Eigen::Matrix<double, 9, 2> felib::QuadrilateralShape<2, 9>::quadrature_points() {

  qpoints(0,0) = -0.774597; qpoints(0,1) = -0.774597;
  qpoints(1,0) =  0.000000; qpoints(1,1) = -0.774597;
  qpoints(2,0) =  0.774597; qpoints(2,1) = -0.774597;
  qpoints(3,0) = -0.774597; qpoints(3,1) =  0.000000;
  qpoints(4,0) =  0.000000; qpoints(4,1) =  0.000000;
  qpoints(5,0) =  0.774597; qpoints(5,1) =  0.000000;
  qpoints(6,0) = -0.774597; qpoints(6,1) =  0.774597;
  qpoints(7,0) =  0.000000; qpoints(7,1) =  0.774597;
  qpoints(8,0) =  0.774597; qpoints(8,1) =  0.774597;
  return qpoints;
}

 
template<unsigned Tdim, unsigned Tnfunctions>
template<unsigned nquadratures>
void felib::QuadrilateralShape<Tdim, Tnfunctions>::custom_quadrature_points(Eigen::Matrix<double, nquadratures, Tdim> &qpoints) {
  if (nquadratures == 1) {
    qpoints(0,0) = 0.; qpoints(0,1) = 0.;
  }
  else if (nquadratures == 4) {
    qpoints(0,0) = -0.57735; qpoints(0,1) = -0.57735;
    qpoints(1,0) =  0.57735; qpoints(1,1) = -0.57735;
    qpoints(2,0) = -0.57735; qpoints(3,2) =  0.57735;
    qpoints(3,0) =  0.57735; qpoints(2,1) =  0.57735;
  }
  else if (nquadratures == 9) {
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
  else if (nquadratures == 16) {
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
