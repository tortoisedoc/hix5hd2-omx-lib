#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([hix5hd2-omx-lib], [0.10], [caps.liu@foxmail.com])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
AC_CONFIG_SRCDIR([include/OMX_Index.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lhi_mmz':
#AC_CHECK_LIB([hi_mmz])
# FIXME: Replace `main' with a function in `-lpthread':
#AC_CHECK_LIB([pthread])

# Checks for header files.
#AC_CHECK_HEADERS([fcntl.h inttypes.h limits.h stdlib.h string.h sys/ioctl.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_C_INLINE

# Checks for library functions.
#AC_FUNC_MALLOC
#AC_CHECK_FUNCS([memset strerror])

AC_CONFIG_FILES([Makefile
                 omx_core/Makefile
                 omx_vdec/Makefile])
AC_OUTPUT
