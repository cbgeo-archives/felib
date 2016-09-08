project(felib LANGUAGES CXX)

# Require C++11-compliant compiler; only available for CMake v. 3.1 and up
set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.1)

SET(CMAKE_COLOR_MAKEFILE ON)
SET(CMAKE_VERBOSE_MAKEFILE OFF)

# General compile settings
IF (NOT CMAKE_BUILD_TYPE)
 SET(CMAKE_BUILD_TYPE "Debug")
 #SET(CMAKE_BUILD_TYPE "Release")
ENDIF (NOT CMAKE_BUILD_TYPE)

# GNU Specific settings
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
endif()

# LBM-DEM settings
OPTION(USE_DOUBLE_PRECISION "Use double precision" ON)

# CMake Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Include directories
include_directories(
  ${felib_SOURCE_DIR}/include/base
  ${felib_SOURCE_DIR}/include/elements/1d_line
  ${felib_SOURCE_DIR}/include/elements/2d_quadrilateral
  ${felib_SOURCE_DIR}/include/elements/2d_triangle
  ${felib_SOURCE_DIR}/include/elements/3d_hexahedron
  ${felib_SOURCE_DIR}/include/elements/3d_tetrahedron
  ${felib_SOURCE_DIR}/external
)

# felib executable
SET(lbm_src
    src/main.cc
)
add_executable(felib
               ${lbm_src}
)

# Unit test
SET(test_src
  ${felib_SOURCE_DIR}/tests/test.cc
  ${felib_SOURCE_DIR}/tests/base/node_base_test.cc
  ${felib_SOURCE_DIR}/tests/line/line_shapefn_test.cc
  ${felib_SOURCE_DIR}/tests/line/line_quadrature_test.cc

)   
add_executable(felibtest
	       ${test_src}
)
add_test(NAME felibtest COMMAND $<TARGET_FILE:felibtest>)
enable_testing()

# Coverage
find_package(codecov)
add_coverage(felib)
add_coverage(felibtest)
