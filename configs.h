#ifndef CONFIGS_H
#define CONFIGS_H
#include <string>
std::string out_pkgs;
std::string cname,cversion;
std::string configure_ac;
void confsetup() {
configure_ac= "#                                               -*- Autoconf -*-\n\
# Process this file with autoconf to produce a configure script.\n\
\n\
AC_PREREQ([2.69])\n\
AC_INIT(["+cname+"], ["+cversion+"], [BUG-REPORT-ADDRESS])\n\
#AC_CONFIG_HEADERS([config.h])\n\
AC_ENABLE_SHARED\n\
AM_INIT_AUTOMAKE\n\
# Checks for programs.\n\
AC_PROG_CXX\n\
LT_INIT\n\
# Checks for libraries.\n\
\n\
# Checks for header files.\n\
AC_CHECK_HEADERS([stdlib.h])\n\
\n\
# Checks for typedefs, structures, and compiler characteristics.\n\
# Checks for library functions.\n\
#AC_CHECK_FUNCS([pow sqrt])\n\
\n\
\n\
AC_CONFIG_FILES([Makefile src/Makefile] " + out_pkgs + ")\n\
AC_OUTPUT\n\
";
}
#endif // CONFIGS_H
