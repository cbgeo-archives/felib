#include "node_base.h"
#include "shapefun_base.h"
#include "line_shape.h"

#include <array>
#include <iostream>
#include <memory>

int main(int argc, char** argv) {
  unsigned id = 0;
  const unsigned Dim = 1;
  std::array<double, Dim> coord = {{0.}};

  auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
  node->info();
}
