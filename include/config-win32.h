/* config.h for windows  */

/* Size of the auth heap. */
#define AUTH_HEAP_SIZE 256

/* Size of the ban heap. */
#define BAN_HEAP_SIZE 1024

/* Size of the read buffer heap. */
#define BUFFER_HEAP_SIZE 64

/* Size of the channel heap. */
#define CHANNEL_HEAP_SIZE 1024

/* Size of the client heap. */
#define CLIENT_HEAP_SIZE 1024

/* Set to datadir. */
#define DDIR "/home/stu/ircd/share"

/* Size of the dbuf heap. */
#define DBUF_HEAP_SIZE 512

/* Size of the dlink_node heap. */
#define DNODE_HEAP_SIZE 1024

/* Size of the dns heap. */
#define DNS_HEAP_SIZE 256

/* Define to 1 if you want halfops support. */
/* #undef HALFOPS */

/* Define to 1 if you have the `closedir' function. */
#define HAVE_CLOSEDIR 1

/* Define to 1 if you have the `EVP_bf_cfb' function. */
#define HAVE_EVP_BF_CFB 1

/* Define to 1 if you have the `EVP_cast5_cfb' function. */
#define HAVE_EVP_CAST5_CFB 1

/* Define to 1 if you have the `EVP_des_cfb' function. */
#define HAVE_EVP_DES_CFB 1

/* Define to 1 if you have the `EVP_des_ede3_cfb' function. */
#define HAVE_EVP_DES_EDE3_CFB 1

/* Define to 1 if you have the `EVP_idea_cfb' function. */
/* #undef HAVE_EVP_IDEA_CFB */

/* Define to 1 if you have the `EVP_rc5_32_12_16_cfb' function. */
#define HAVE_EVP_RC5_32_12_16_CFB 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

#define HAVE_DIRENT_H 1

/* If we support ssl */
#define HAVE_LIBCRYPTO 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `opendir' function. */
#define HAVE_OPENDIR 1

/* Define if libtool can extract symbol lists from object files. */
#define HAVE_PRELOADED_SYMBOLS 1

/* Define to 1 if you have the `readdir' function. */
#define HAVE_READDIR 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtok_r' function. */
#define HAVE_STRTOK_R 1

/* Define to 1 if the system has the type `struct addrinfo'. */
#define HAVE_STRUCT_ADDRINFO 1

/* Define to 1 if the system has the type `struct sockaddr_storage'. */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the `usleep' function. */
#define HAVE_USLEEP 1

/* Size of the local client heap. */
#define LCLIENT_HEAP_SIZE 512

/* Set to libdir. */
#define LIBDIR "/home/stu/ircd/lib"

/* Set to localstatedir. */
#define LOCALSTATEDIR "/home/stu/ircd/var"

/* Define to the system default library search path. */
#define LT_DLSEARCH_PATH "/lib:/usr/lib"

/* The archive extension */
#define LT_LIBEXT "a"

/* The archive prefix */
#define LT_LIBPREFIX "lib"

/* Define to the extension used for runtime loadable modules, say, ".so". */
#define LT_MODULE_EXT ".dll"

/* Define to the name of the environment variable that determines the run-time
   module search path. */
#define LT_MODULE_PATH_VAR "LD_LIBRARY_PATH"

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to the shared library suffix, say, ".dylib". */
/* #undef LT_SHARED_EXT */

/* Set to moduledir. */
#define MODULEDIR ""

/* Define to disable assert() statements. */
/* #undef NDEBUG */

/* Define if dlsym() requires a leading underscore in symbol names. */
/* #undef NEED_USCORE */

/* Size of the WHOWAS array. */
#define NICKNAMEHISTORYLENGTH 32768

/* Name of package */
#define PACKAGE "oftc-hybrid"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "oftc-hybrid"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "oftc-hybrid 1.7.0-alpha1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "oftc-hybrid"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.7.0-alpha1"

/* Set to prefix. */
#define PREFIX "/home/stu/ircd"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Set to sysconfdir. */
#define SYSCONFDIR "/home/stu/ircd/etc"

/* Size of the TCP handle heap. */
#define TCP_HANDLE_HEAP_SIZE 64

/* Size of the UDP handle heap. */
#define UDP_HANDLE_HEAP_SIZE 64

/* Size of the UDP send handle heap. */
#define UDP_SEND_HANDLE_HEAP_SIZE 64

/* use block alloc */
#define USE_BLOCK_ALLOC 1

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "1.7.0-alpha1"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Size of the write request heap. */
#define WRITE_REQ_HEAP_SIZE 64

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define so that glibc/gnulib argp.h does not typedef error_t. */
#define __error_t_defined 1

/* Define to a type to use for `error_t' if it is not otherwise available. */
#define error_t int

/* Define to empty if the keyword `volatile' does not work. Warning: valid
   code using `volatile' can become incorrect without. Disable with care. */
/* #undef volatile */
