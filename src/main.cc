#include "node_base.h"
#include "shapefn_base.h"
#include "hexahedron_shapefn.h"
#include "tetrahedron_quadrature.h"

#include <iostream>
#include <memory>

int main(int argc, char** argv) {
  unsigned id = 0;
  const unsigned Dim = 3;
  std::array<double, Dim> coord = {{0.}};

  auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
  node->info();

  // auto hex = std::make_shared<felib::HexahedronShapeFn<Dim, 20>>();

  // auto sf = hex->shapefn(coord);

  // std::cout << sf << std::endl;
  
  // auto grad = hex->grad_shapefn(coord);

  // std::cout << grad << std::endl;
  
  auto quad = std::make_shared<felib::TetrahedronQuadrature<Dim, 11>>();

  auto points = quad->quadratures();

  std::cout << points << std::endl;
}
