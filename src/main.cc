#include "node_base.h"
#include "shapefun_base.h"
#include "line_shape.h"

#include <array>
#include <iostream>
#include <memory>

int main(int argc, char **argv) {
  unsigned id = 0;
  const unsigned Dim = 1;
  std::array<double, Dim> lcoord{0.};
  std::array<double, Dim> coord{0.};

  auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
  const unsigned NumOfSfun = 2;
  std::array<double, NumOfSfun> lineSfun{0.};
  auto line_shape = new felib::LineShape<Dim, NumOfSfun>;
  line_shape->evaluate_shape_fun(lcoord, lineSfun);
  std::cout << "Shape functions for the line element are: " << lineSfun[0] << " " << lineSfun[1] << std::endl;
  node->info();
}
