cmake_minimum_required(VERSION 2.6)
 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(INCLUDE_DIR ../)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS}, ${INCLUDE_DIR})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(allTests node_base_test.cpp)
target_link_libraries(allTests ${GTEST_LIBRARIES} pthread -std=c++11)
