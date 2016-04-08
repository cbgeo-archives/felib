# EIGEN M4 Macro 
# Author - Krishna Kumar
# Eigen parser library (taken from a static internally bundled version if no --with flag is specified)
AC_DEFUN([EIGEN_PATH], [
AC_ARG_WITH([eigen], AS_HELP_STRING([--with-eigen], [indicate the position of the eigen installation (should contain both lib and include dirs]))
AC_ARG_WITH([eigen-inc], AS_HELP_STRING([--with-eigen-inc], [indicate the position of the eigen include directory (the one *containing* the 'eigen' directory)]))
if test -z "$with_eigen" && test -z "$with_eigen_inc"; then
    AC_MSG_NOTICE([Using default location for Eigen])
    EIGEN_BUILTIN=yes
    EIGEN_CPPFLAGS="-I/usr/include/eigen3"
else
    EIGEN_BUILTIN=no
    EIGEN_CPPFLAGS=
    test "$with_eigen" && EIGEN_CPPFLAGS="-I$with_eigen/include/eigen3"
    test "$with_eigen_inc" && EIGEN_CPPFLAGS="-I$with_eigen_inc"

fi
AM_CONDITIONAL(USE_BUILTIN_EIGENCPP, [test $EIGEN_BUILTIN = yes])
AC_SUBST(EIGEN_CPPFLAGS)
])
