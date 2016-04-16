# Stop autoconf looking for readme file
AUTOMAKE_OPTIONS = foreign

# M4 Macros
ACLOCAL_AMFLAGS = -I ./m4 

AM_LDFLAGS =  $(AM_LFLAGS)

AM_CPPFLAGS = -I include/ $(EIGEN_CPPFLAGS)

# Main Program 
bin_PROGRAMS 	= felib

felib_SOURCES 	= src/main.cc

# Tests
check_PROGRAMS  = felibtest

felibtest_SOURCES = tests/test.cc \
		    tests/node_base_test.cc \
		    tests/line_shapefn_test.cc \
		    tests/triangle_shapefn_test.cc \
		    tests/quadrilateral_shapefn_test.cc \
		    tests/hexahedron_shapefn_test.cc \
		    tests/line_quadrature_test.cc \
		    tests/triangle_quadrature_test.cc 
		    tests/quadrilateral_quadrature_test.cc 
