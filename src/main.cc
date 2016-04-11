#include "node_base.h"
#include "shapefn_base.h"
#include "quadrilateral_shapefn.h"
#include "line_quadrature.h"

#include <array>
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
  unsigned id = 0;
  const unsigned Dim = 2;
  std::array<double, Dim> coord = {{0.}};

  auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
  node->info();

  auto quad = std::make_shared<felib::QuadrilateralShapeFn<Dim, 9>>();

  // auto quad = std::make_shared<felib::LineQuadrature<Dim, 2>>();

  // auto points = quad->quadratures();

  // std::cout << points << std::endl;
}
