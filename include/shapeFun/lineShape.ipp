// Linear shape functions for 1-D first order line element
template<>
void felib::LineShape<1, 2>::evaluateShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &sFun) {

}

template<>
void felib::LineShape<1, 2>::evaluateGradShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &gradSfun) {

}

// Shape functions for 1-D second order line element 
template<>
void felib::LineShape<1, 3>::evaluateShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &sFun) {

}

template<>
void felib::LineShape<1, 3>::evaluateGradShapeFun(const std::array<double, Tdim> &xi, std::array<double, numFun> &gradSfun) {

}

