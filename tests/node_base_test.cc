// Nodebase test
#include <limits>

#include "catch.hpp"
#include "node_base.h"

//! \brief Check node base class for 1D case
TEST_CASE("Node base is checked for 1D case", "[node][1D]") {
  const unsigned Dim = 1;
  std::array<double, Dim> coords = {{0.}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    int id = 0;
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is zero") {
    //! Check for negative node id
    int id = std::numeric_limits<int>::min();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    int id = std::numeric_limits<int>::max();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    int id = 0;
    const double Tolerance = 1.E-7;

    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);

    //! Check for coordinates being zero
    auto coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));
    REQUIRE(coordinates.size() == Dim);

    //! Check for negative value of coordinates
    for (auto &coord : coords)
      coord = -1. * std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);

    //! Check for positive value of coordinates
    for (auto &coord : coords)
      coord = std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);
  }
}

//! \brief Check node base class for 2D case
TEST_CASE("Node base is checked for 2D case", "[node][2D]") {
  const unsigned Dim = 2;
  std::array<double, Dim> coords = {{0.}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    int id = 0;
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is zero") {
    //! Check for negative node id
    int id = std::numeric_limits<int>::min();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    int id = std::numeric_limits<int>::max();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    int id = 0;
    const double Tolerance = 1.E-7;

    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);

    //! Check for coordinates being zero
    auto coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));
    REQUIRE(coordinates.size() == Dim);

    //! Check for negative value of coordinates
    for (auto &coord : coords)
      coord = -1. * std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);

    //! Check for positive value of coordinates
    for (auto &coord : coords)
      coord = std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);
  }
}

//! \brief Check node base class for 3D case
TEST_CASE("Node base is checked for 3D case", "[node][3D]") {
  const unsigned Dim = 3;
  std::array<double, Dim> coords = {{0.}};

  //! Check for id = 0
  SECTION("Node id is zero") {
    int id = 0;
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == 0);
  }

  SECTION("Node id is zero") {
    //! Check for negative node id
    int id = std::numeric_limits<int>::min();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::min());
  }

  SECTION("Node id is positive") {
    //! Check for id is a positive value
    int id = std::numeric_limits<int>::max();
    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);
    REQUIRE(node->id() == std::numeric_limits<int>::max());
  }

  //! Test coordinates function
  SECTION("coordinates function is checked") {
    int id = 0;
    const double Tolerance = 1.E-7;

    auto node = std::make_shared<felib::NodeBase<Dim>>(id, coords);

    //! Check for coordinates being zero
    auto coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));
    REQUIRE(coordinates.size() == Dim);

    //! Check for negative value of coordinates
    for (auto &coord : coords)
      coord = -1. * std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);

    //! Check for positive value of coordinates
    for (auto &coord : coords)
      coord = std::numeric_limits<double>::max();
    node->coordinates(coords);
    coordinates = node->coordinates();
    for (unsigned i = 0; i < coordinates.size(); ++i)
      REQUIRE(coordinates.at(i) == Approx(coords.at(i)).epsilon(Tolerance));

    REQUIRE(coordinates.size() == Dim);
  }

}
