// Nodebase test

#include <limits>

#include "node_base.h"

#include "catch.hpp"

TEST_CASE("Node base is checked for 1D case", "[node][1D]") {
  const unsigned Dim = 1;
  std::array<double, Dim> coord = {{0.}};

  // Check for id = 0
  SECTION("node id is zero") {
    int id = 0;
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
    REQUIRE(node->id() == 0);

    // Test coordinates function
    SECTION("coordinates function is checked") {
      // Check for coordinates being zero
      auto coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for negative value of coordinates
      coord = {{-1. * std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for positive value of coordinates
      coord = {{std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));
    }
  }

  // Check for negative node id
  SECTION("negative node id") {

    int id = std::numeric_limits<int>::min();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
    REQUIRE(node->id() == std::numeric_limits<int>::min());

    // Test coordinates function
    SECTION("coordinates function is checked") {
      // Check for coordinates being zero
      auto coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for negative value of coordinates
      coord = {{-1. * std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for positive value of coordinates
      coord = {{std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));
    }
  }

  // Check for id is a positive value
  SECTION("positive node id") {
    int id = std::numeric_limits<int>::max();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coord);
    REQUIRE(node->id() == std::numeric_limits<int>::max());

    // Test coordinates function
    SECTION("coordinates function is checked") {
      // Check for coordinates being zero
      auto coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for negative value of coordinates
      coord = {{-1. * std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));

      // Check for positive value of coordinates
      coord = {{std::numeric_limits<double>::max()}};
      node->coordinates(coord);
      coordinates = node->coordinates();
      REQUIRE(coordinates.at(0) == Approx(coord.at(0)).epsilon(1.E-7));
    }
  }
}
