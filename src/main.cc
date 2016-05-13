#include "node_base.h"
#include "shapefn_base.h"
#include "hexahedron_shapefn.h"
#include "quadrilateral_quadrature.h"
#include "element_base.h"
#include "quadrilateral_element.h"
#include "hexahedron_element.h"
#include "triangle_element.h"


#include <array>
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
  long long id = 0;
  const unsigned Dim = 3;
  std::array<double, Dim> coord = {{0.}};

  auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
  node->info();

  auto quad = std::make_shared<felib::HexahedronElement<Dim, 8, 27>>(id);
}
