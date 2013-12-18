#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(syntox,2.6.1,lionel.clement@labri.fr)
AC_CONFIG_SRCDIR([src])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_LEX
AC_PROG_YACC

# Checks for libraries.
AM_PATH_XML2
LIBS="$LIBS $XML2_LIBS"

# Checks for header files.
#AC_HEADER_STDC
AC_CHECK_HEADERS([iostream stdarg.h libxml/tree.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile src/Makefile data/Makefile data/lefff/Makefile])
AC_OUTPUT
