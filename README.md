# Finite Element Base Library (felib)
> Cambridge Berkeley - Geomechanics

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/cb-geo/develop/license.md)
[![Documentation](https://img.shields.io/badge/docs-doxygen-blue.svg)](http://cb-geo.github.io/lbmdem)
[![Build status](https://api.travis-ci.org/cb-geo/lbmdem.svg)](https://travis-ci.org/cb-geo/lbmdem/builds)
[![Build status](https://ci.appveyor.com/api/projects/status/8v8cd7mnp2lahgmi?svg=true)](https://ci.appveyor.com/project/cbgeo/felib)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/10113/badge.svg)](https://scan.coverity.com/projects/cb-geo-lbmdem)
[![codecov.io](http://codecov.io/github/cb-geo/lbmdem/coverage.svg?branch=develop)](http://codecov.io/github/cb-geo/lbmdem?branch=develop)
[![](https://img.shields.io/github/issues-raw/cb-geo/lbmdem.svg)](https://github.com/cb-geo/lbmdem/issues)

## Install dependencies

* Docker image for CB-Geo LBM-DEM code [https://hub.docker.com/r/cbgeo/felib](https://hub.docker.com/r/cbgeo/felib)

* Instructions for running felib docker container: [https://github.com/cb-geo/docker-felib/blob/master/README.md](https://github.com/cb-geo/docker-felib/blob/master/README.md).

## Compile and Run

0. Run `mkdir build && cd build && cmake ..`

1. Run `make clean && make -jN` (where N is the number of cores)

3. Run felib `./felib`

4. Run felibtest `ctest -VV -S` or `./felibtest` to run test cases
