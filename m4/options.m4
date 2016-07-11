AC_DEFUN([AX_ARG_ENABLE_DEBUGGING],[
  AC_ARG_ENABLE([debugging],
    [AC_HELP_STRING([--enable-debugging],[Enable debugging.])],
        [debugging="$enableval"],[debugging="no"])
  if test "$debugging" = "yes" ; then
    AC_DEFINE([DEBUG],[1],[Define to 1 to enable debugging.])
    CFLAGS="$CFLAGS -O0"
  else
    AC_DEFINE([NDEBUG],[1],[Define to 1 to disable debugging.])
    CFLAGS="$CFLAGS -O2"
  fi
])

AC_DEFUN([AX_ARG_ENABLE_PROFILING],[
  AC_ARG_ENABLE([profiling],
    [AC_HELP_STRING([--enable-profiling],[Enable profiling.])],
        [profiling="$enableval"],[profiling="no"])
  if test "$profiling" = "yes" ; then
    CFLAGS="$CFLAGS --coverage"
  fi
])

