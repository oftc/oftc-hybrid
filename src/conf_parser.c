/* A Bison parser, made by GNU Bison 2.6.2.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */
#line 25 "conf_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/dh.h>
#endif

int yylex(void);

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE];
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];
static char lfile[IRCD_BUFSIZE];
static unsigned int ltype = 0;
static unsigned int lsize = 0;
static char *resv_reason = NULL;
static char *listener_address = NULL;

struct CollectItem
{
  dlink_node node;
  char *name;
  char *user;
  char *host;
  char *passwd;
  int  port;
  int  flags;
#ifdef HAVE_LIBCRYPTO
  char *rsa_public_key_file;
  RSA *rsa_public_key;
#endif
};

static void
free_collect_item(struct CollectItem *item)
{
  MyFree(item->name);
  MyFree(item->user);
  MyFree(item->host);
  MyFree(item->passwd);
#ifdef HAVE_LIBCRYPTO
  MyFree(item->rsa_public_key_file);
#endif
  MyFree(item);
}


/* Line 336 of yacc.c  */
#line 153 "conf_parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_Y_TAB_H
# define YY_Y_TAB_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ADMIN = 259,
     AFTYPE = 260,
     ANTI_NICK_FLOOD = 261,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
     AUTOCONN = 263,
     BYTES = 264,
     KBYTES = 265,
     MBYTES = 266,
     CALLER_ID_WAIT = 267,
     CAN_FLOOD = 268,
     CHANNEL = 269,
     CIDR_BITLEN_IPV4 = 270,
     CIDR_BITLEN_IPV6 = 271,
     CLASS = 272,
     CONNECT = 273,
     CONNECTFREQ = 274,
     DEFAULT_FLOODCOUNT = 275,
     DEFAULT_SPLIT_SERVER_COUNT = 276,
     DEFAULT_SPLIT_USER_COUNT = 277,
     DENY = 278,
     DESCRIPTION = 279,
     DIE = 280,
     DISABLE_AUTH = 281,
     DISABLE_FAKE_CHANNELS = 282,
     DISABLE_REMOTE_COMMANDS = 283,
     DOTS_IN_IDENT = 284,
     EGDPOOL_PATH = 285,
     EMAIL = 286,
     ENCRYPTED = 287,
     EXCEED_LIMIT = 288,
     EXEMPT = 289,
     FAILED_OPER_NOTICE = 290,
     IRCD_FLAGS = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_REQUEST_DURATION = 299,
     GLINE_MIN_CIDR = 300,
     GLINE_MIN_CIDR6 = 301,
     GLOBAL_KILL = 302,
     IRCD_AUTH = 303,
     NEED_IDENT = 304,
     HAVENT_READ_CONF = 305,
     HIDDEN = 306,
     HIDDEN_NAME = 307,
     HIDE_SERVER_IPS = 308,
     HIDE_SERVERS = 309,
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     KILL = 317,
     KILL_CHASE_TIME_LIMIT = 318,
     KLINE = 319,
     KLINE_EXEMPT = 320,
     KLINE_REASON = 321,
     KLINE_WITH_REASON = 322,
     KNOCK_DELAY = 323,
     KNOCK_DELAY_CHANNEL = 324,
     LEAF_MASK = 325,
     LINKS_DELAY = 326,
     LISTEN = 327,
     T_LOG = 328,
     MAX_ACCEPT = 329,
     MAX_BANS = 330,
     MAX_CHANS_PER_OPER = 331,
     MAX_CHANS_PER_USER = 332,
     MAX_GLOBAL = 333,
     MAX_IDENT = 334,
     MAX_LOCAL = 335,
     MAX_NICK_CHANGES = 336,
     MAX_NICK_TIME = 337,
     MAX_NUMBER = 338,
     MAX_TARGETS = 339,
     MAX_WATCH = 340,
     MESSAGE_LOCALE = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MODULE = 344,
     MODULES = 345,
     NAME = 346,
     NEED_PASSWORD = 347,
     NETWORK_DESC = 348,
     NETWORK_NAME = 349,
     NICK = 350,
     NICK_CHANGES = 351,
     NO_CREATE_ON_SPLIT = 352,
     NO_JOIN_ON_SPLIT = 353,
     NO_OPER_FLOOD = 354,
     NO_TILDE = 355,
     NUMBER = 356,
     NUMBER_PER_CIDR = 357,
     NUMBER_PER_IP = 358,
     OPERATOR = 359,
     OPERS_BYPASS_CALLERID = 360,
     OPER_ONLY_UMODES = 361,
     OPER_PASS_RESV = 362,
     OPER_SPY_T = 363,
     OPER_UMODES = 364,
     JOIN_FLOOD_COUNT = 365,
     JOIN_FLOOD_TIME = 366,
     PACE_WAIT = 367,
     PACE_WAIT_SIMPLE = 368,
     PASSWORD = 369,
     PATH = 370,
     PING_COOKIE = 371,
     PING_TIME = 372,
     PING_WARNING = 373,
     PORT = 374,
     QSTRING = 375,
     QUIET_ON_BAN = 376,
     REASON = 377,
     REDIRPORT = 378,
     REDIRSERV = 379,
     REGEX_T = 380,
     REHASH = 381,
     TREJECT_HOLD_TIME = 382,
     REMOTE = 383,
     REMOTEBAN = 384,
     RESTRICT_CHANNELS = 385,
     RSA_PRIVATE_KEY_FILE = 386,
     RSA_PUBLIC_KEY_FILE = 387,
     SSL_CERTIFICATE_FILE = 388,
     SSL_DH_PARAM_FILE = 389,
     T_SSL_CLIENT_METHOD = 390,
     T_SSL_SERVER_METHOD = 391,
     T_SSLV3 = 392,
     T_TLSV1 = 393,
     RESV = 394,
     RESV_EXEMPT = 395,
     SECONDS = 396,
     MINUTES = 397,
     HOURS = 398,
     DAYS = 399,
     WEEKS = 400,
     SENDQ = 401,
     SEND_PASSWORD = 402,
     SERVERHIDE = 403,
     SERVERINFO = 404,
     IRCD_SID = 405,
     TKLINE_EXPIRE_NOTICES = 406,
     T_SHARED = 407,
     T_CLUSTER = 408,
     TYPE = 409,
     SHORT_MOTD = 410,
     SPOOF = 411,
     SPOOF_NOTICE = 412,
     STATS_E_DISABLED = 413,
     STATS_I_OPER_ONLY = 414,
     STATS_K_OPER_ONLY = 415,
     STATS_O_OPER_ONLY = 416,
     STATS_P_OPER_ONLY = 417,
     TBOOL = 418,
     TMASKED = 419,
     TS_MAX_DELTA = 420,
     TS_WARN_DELTA = 421,
     TWODOTS = 422,
     T_ALL = 423,
     T_BOTS = 424,
     T_SOFTCALLERID = 425,
     T_CALLERID = 426,
     T_CCONN = 427,
     T_CCONN_FULL = 428,
     T_SSL_CIPHER_LIST = 429,
     T_DEAF = 430,
     T_DEBUG = 431,
     T_DLINE = 432,
     T_EXTERNAL = 433,
     T_FULL = 434,
     T_INVISIBLE = 435,
     T_IPV4 = 436,
     T_IPV6 = 437,
     T_LOCOPS = 438,
     T_MAX_CLIENTS = 439,
     T_NCHANGE = 440,
     T_OPERWALL = 441,
     T_RECVQ = 442,
     T_REJ = 443,
     T_SERVER = 444,
     T_SERVNOTICE = 445,
     T_SET = 446,
     T_SKILL = 447,
     T_SPY = 448,
     T_SSL = 449,
     T_UMODES = 450,
     T_UNAUTH = 451,
     T_UNDLINE = 452,
     T_UNLIMITED = 453,
     T_UNRESV = 454,
     T_UNXLINE = 455,
     T_GLOBOPS = 456,
     T_WALLOP = 457,
     T_RESTART = 458,
     T_SERVICE = 459,
     T_SERVICES_NAME = 460,
     THROTTLE_TIME = 461,
     TRUE_NO_OPER_FLOOD = 462,
     UNKLINE = 463,
     USER = 464,
     USE_EGD = 465,
     USE_LOGGING = 466,
     VHOST = 467,
     VHOST6 = 468,
     XLINE = 469,
     WARN_NO_NLINE = 470,
     T_SIZE = 471,
     T_FILE = 472
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define BYTES 264
#define KBYTES 265
#define MBYTES 266
#define CALLER_ID_WAIT 267
#define CAN_FLOOD 268
#define CHANNEL 269
#define CIDR_BITLEN_IPV4 270
#define CIDR_BITLEN_IPV6 271
#define CLASS 272
#define CONNECT 273
#define CONNECTFREQ 274
#define DEFAULT_FLOODCOUNT 275
#define DEFAULT_SPLIT_SERVER_COUNT 276
#define DEFAULT_SPLIT_USER_COUNT 277
#define DENY 278
#define DESCRIPTION 279
#define DIE 280
#define DISABLE_AUTH 281
#define DISABLE_FAKE_CHANNELS 282
#define DISABLE_REMOTE_COMMANDS 283
#define DOTS_IN_IDENT 284
#define EGDPOOL_PATH 285
#define EMAIL 286
#define ENCRYPTED 287
#define EXCEED_LIMIT 288
#define EXEMPT 289
#define FAILED_OPER_NOTICE 290
#define IRCD_FLAGS 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_REQUEST_DURATION 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLOBAL_KILL 302
#define IRCD_AUTH 303
#define NEED_IDENT 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define KILL 317
#define KILL_CHASE_TIME_LIMIT 318
#define KLINE 319
#define KLINE_EXEMPT 320
#define KLINE_REASON 321
#define KLINE_WITH_REASON 322
#define KNOCK_DELAY 323
#define KNOCK_DELAY_CHANNEL 324
#define LEAF_MASK 325
#define LINKS_DELAY 326
#define LISTEN 327
#define T_LOG 328
#define MAX_ACCEPT 329
#define MAX_BANS 330
#define MAX_CHANS_PER_OPER 331
#define MAX_CHANS_PER_USER 332
#define MAX_GLOBAL 333
#define MAX_IDENT 334
#define MAX_LOCAL 335
#define MAX_NICK_CHANGES 336
#define MAX_NICK_TIME 337
#define MAX_NUMBER 338
#define MAX_TARGETS 339
#define MAX_WATCH 340
#define MESSAGE_LOCALE 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MODULE 344
#define MODULES 345
#define NAME 346
#define NEED_PASSWORD 347
#define NETWORK_DESC 348
#define NETWORK_NAME 349
#define NICK 350
#define NICK_CHANGES 351
#define NO_CREATE_ON_SPLIT 352
#define NO_JOIN_ON_SPLIT 353
#define NO_OPER_FLOOD 354
#define NO_TILDE 355
#define NUMBER 356
#define NUMBER_PER_CIDR 357
#define NUMBER_PER_IP 358
#define OPERATOR 359
#define OPERS_BYPASS_CALLERID 360
#define OPER_ONLY_UMODES 361
#define OPER_PASS_RESV 362
#define OPER_SPY_T 363
#define OPER_UMODES 364
#define JOIN_FLOOD_COUNT 365
#define JOIN_FLOOD_TIME 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PING_WARNING 373
#define PORT 374
#define QSTRING 375
#define QUIET_ON_BAN 376
#define REASON 377
#define REDIRPORT 378
#define REDIRSERV 379
#define REGEX_T 380
#define REHASH 381
#define TREJECT_HOLD_TIME 382
#define REMOTE 383
#define REMOTEBAN 384
#define RESTRICT_CHANNELS 385
#define RSA_PRIVATE_KEY_FILE 386
#define RSA_PUBLIC_KEY_FILE 387
#define SSL_CERTIFICATE_FILE 388
#define SSL_DH_PARAM_FILE 389
#define T_SSL_CLIENT_METHOD 390
#define T_SSL_SERVER_METHOD 391
#define T_SSLV3 392
#define T_TLSV1 393
#define RESV 394
#define RESV_EXEMPT 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define SENDQ 401
#define SEND_PASSWORD 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define IRCD_SID 405
#define TKLINE_EXPIRE_NOTICES 406
#define T_SHARED 407
#define T_CLUSTER 408
#define TYPE 409
#define SHORT_MOTD 410
#define SPOOF 411
#define SPOOF_NOTICE 412
#define STATS_E_DISABLED 413
#define STATS_I_OPER_ONLY 414
#define STATS_K_OPER_ONLY 415
#define STATS_O_OPER_ONLY 416
#define STATS_P_OPER_ONLY 417
#define TBOOL 418
#define TMASKED 419
#define TS_MAX_DELTA 420
#define TS_WARN_DELTA 421
#define TWODOTS 422
#define T_ALL 423
#define T_BOTS 424
#define T_SOFTCALLERID 425
#define T_CALLERID 426
#define T_CCONN 427
#define T_CCONN_FULL 428
#define T_SSL_CIPHER_LIST 429
#define T_DEAF 430
#define T_DEBUG 431
#define T_DLINE 432
#define T_EXTERNAL 433
#define T_FULL 434
#define T_INVISIBLE 435
#define T_IPV4 436
#define T_IPV6 437
#define T_LOCOPS 438
#define T_MAX_CLIENTS 439
#define T_NCHANGE 440
#define T_OPERWALL 441
#define T_RECVQ 442
#define T_REJ 443
#define T_SERVER 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SKILL 447
#define T_SPY 448
#define T_SSL 449
#define T_UMODES 450
#define T_UNAUTH 451
#define T_UNDLINE 452
#define T_UNLIMITED 453
#define T_UNRESV 454
#define T_UNXLINE 455
#define T_GLOBOPS 456
#define T_WALLOP 457
#define T_RESTART 458
#define T_SERVICE 459
#define T_SERVICES_NAME 460
#define THROTTLE_TIME 461
#define TRUE_NO_OPER_FLOOD 462
#define UNKLINE 463
#define USER 464
#define USE_EGD 465
#define USE_LOGGING 466
#define VHOST 467
#define VHOST6 468
#define XLINE 469
#define WARN_NO_NLINE 470
#define T_SIZE 471
#define T_FILE 472



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 636 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_Y_TAB_H  */

/* Copy the second part of user declarations.  */

/* Line 353 of yacc.c  */
#line 664 "conf_parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  223
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  286
/* YYNRULES -- Number of rules.  */
#define YYNRULES  633
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1243

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   472

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   222,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   218,
       2,   221,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   220,     2,   219,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   169,   174,   179,
     183,   185,   187,   189,   193,   195,   197,   199,   204,   209,
     214,   219,   224,   229,   234,   239,   244,   249,   254,   259,
     264,   270,   273,   275,   277,   279,   281,   284,   289,   294,
     299,   305,   308,   310,   312,   314,   317,   322,   323,   330,
     333,   335,   337,   339,   341,   344,   349,   354,   359,   360,
     366,   370,   372,   374,   376,   378,   380,   382,   384,   386,
     387,   394,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   418,   423,   428,   433,   438,   443,   448,   449,
     455,   459,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   502,   508,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   553,   560,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   593,   596,   601,   606,   611,   616,   621,
     626,   631,   636,   641,   646,   651,   656,   661,   666,   667,
     674,   675,   681,   685,   687,   689,   691,   693,   696,   698,
     700,   702,   704,   706,   709,   710,   716,   720,   722,   724,
     728,   733,   738,   739,   746,   749,   751,   753,   755,   757,
     759,   761,   763,   765,   767,   770,   775,   780,   785,   790,
     791,   797,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   819,   821,   826,   831,   836,   837,   844,   847,   849,
     851,   853,   855,   858,   863,   868,   873,   879,   882,   884,
     886,   888,   893,   894,   901,   904,   906,   908,   910,   912,
     915,   920,   925,   926,   932,   936,   938,   940,   942,   944,
     946,   948,   950,   952,   954,   956,   958,   959,   966,   969,
     971,   973,   975,   978,   983,   984,   990,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1017,
    1024,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1058,  1063,  1068,  1073,
    1078,  1083,  1088,  1093,  1098,  1099,  1105,  1109,  1111,  1113,
    1115,  1120,  1125,  1130,  1135,  1140,  1141,  1148,  1149,  1155,
    1159,  1161,  1163,  1166,  1168,  1170,  1172,  1174,  1176,  1181,
    1186,  1187,  1194,  1197,  1199,  1201,  1203,  1205,  1210,  1215,
    1221,  1224,  1226,  1228,  1230,  1235,  1236,  1243,  1244,  1250,
    1254,  1256,  1258,  1261,  1263,  1265,  1267,  1269,  1271,  1276,
    1281,  1287,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,
    1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,
    1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1403,  1408,  1413,
    1418,  1423,  1428,  1433,  1438,  1443,  1448,  1453,  1458,  1463,
    1468,  1473,  1478,  1483,  1488,  1493,  1498,  1503,  1508,  1513,
    1518,  1523,  1528,  1533,  1538,  1543,  1548,  1553,  1558,  1563,
    1568,  1573,  1578,  1583,  1588,  1593,  1598,  1603,  1608,  1613,
    1618,  1623,  1628,  1633,  1638,  1643,  1644,  1650,  1654,  1656,
    1658,  1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,
    1697,  1703,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,
    1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,
    1743,  1745,  1747,  1749,  1754,  1759,  1764,  1770,  1773,  1775,
    1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1797,  1799,  1801,  1803,  1805,  1810,  1815,  1820,  1825,  1830,
    1835,  1840,  1845,  1850,  1855,  1860,  1865,  1870,  1875,  1881,
    1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,  1900,  1905,
    1910,  1915,  1920,  1925
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     224,     0,    -1,    -1,   224,   225,    -1,   257,    -1,   263,
      -1,   277,    -1,   483,    -1,   295,    -1,   313,    -1,   327,
      -1,   235,    -1,   500,    -1,   342,    -1,   349,    -1,   353,
      -1,   363,    -1,   372,    -1,   392,    -1,   402,    -1,   408,
      -1,   422,    -1,   412,    -1,   230,    -1,     1,   218,    -1,
       1,   219,    -1,    -1,   227,    -1,   101,   226,    -1,   101,
     141,   226,    -1,   101,   142,   226,    -1,   101,   143,   226,
      -1,   101,   144,   226,    -1,   101,   145,   226,    -1,    -1,
     229,    -1,   101,   228,    -1,   101,     9,   228,    -1,   101,
      10,   228,    -1,   101,    11,   228,    -1,    90,   220,   231,
     219,   218,    -1,   231,   232,    -1,   232,    -1,   233,    -1,
     234,    -1,     1,   218,    -1,    89,   221,   120,   218,    -1,
     115,   221,   120,   218,    -1,   149,   220,   236,   219,   218,
      -1,   236,   237,    -1,   237,    -1,   248,    -1,   253,    -1,
     256,    -1,   250,    -1,   251,    -1,   252,    -1,   255,    -1,
     246,    -1,   245,    -1,   254,    -1,   249,    -1,   244,    -1,
     238,    -1,   239,    -1,   247,    -1,     1,   218,    -1,   135,
     221,   240,   218,    -1,   136,   221,   242,   218,    -1,   240,
     222,   241,    -1,   241,    -1,   137,    -1,   138,    -1,   242,
     222,   243,    -1,   243,    -1,   137,    -1,   138,    -1,   133,
     221,   120,   218,    -1,   131,   221,   120,   218,    -1,   134,
     221,   120,   218,    -1,   174,   221,   120,   218,    -1,    91,
     221,   120,   218,    -1,   150,   221,   120,   218,    -1,    24,
     221,   120,   218,    -1,    94,   221,   120,   218,    -1,    93,
     221,   120,   218,    -1,   212,   221,   120,   218,    -1,   213,
     221,   120,   218,    -1,   184,   221,   101,   218,    -1,    57,
     221,   163,   218,    -1,     4,   220,   258,   219,   218,    -1,
     258,   259,    -1,   259,    -1,   260,    -1,   262,    -1,   261,
      -1,     1,   218,    -1,    91,   221,   120,   218,    -1,    31,
     221,   120,   218,    -1,    24,   221,   120,   218,    -1,    73,
     220,   264,   219,   218,    -1,   264,   265,    -1,   265,    -1,
     266,    -1,   267,    -1,     1,   218,    -1,   211,   221,   163,
     218,    -1,    -1,   268,   217,   220,   269,   219,   218,    -1,
     269,   270,    -1,   270,    -1,   271,    -1,   273,    -1,   272,
      -1,     1,   218,    -1,    91,   221,   120,   218,    -1,   216,
     221,   229,   218,    -1,   216,   221,   198,   218,    -1,    -1,
     154,   274,   221,   275,   218,    -1,   275,   222,   276,    -1,
     276,    -1,   209,    -1,   104,    -1,    40,    -1,   177,    -1,
      64,    -1,    62,    -1,   176,    -1,    -1,   104,   278,   220,
     279,   219,   218,    -1,   279,   280,    -1,   280,    -1,   281,
      -1,   282,    -1,   283,    -1,   287,    -1,   286,    -1,   284,
      -1,   285,    -1,   291,    -1,     1,   218,    -1,    91,   221,
     120,   218,    -1,   209,   221,   120,   218,    -1,   114,   221,
     120,   218,    -1,    32,   221,   163,   218,    -1,   132,   221,
     120,   218,    -1,    17,   221,   120,   218,    -1,    -1,   195,
     288,   221,   289,   218,    -1,   289,   222,   290,    -1,   290,
      -1,   169,    -1,   172,    -1,   173,    -1,   175,    -1,   176,
      -1,   179,    -1,    51,    -1,   192,    -1,   185,    -1,   188,
      -1,   196,    -1,   193,    -1,   178,    -1,   186,    -1,   190,
      -1,   180,    -1,   202,    -1,   170,    -1,   171,    -1,   183,
      -1,    -1,    36,   292,   221,   293,   218,    -1,   293,   222,
     294,    -1,   294,    -1,    47,    -1,   128,    -1,    64,    -1,
     208,    -1,   177,    -1,   197,    -1,   214,    -1,    40,    -1,
      25,    -1,   203,    -1,   126,    -1,     4,    -1,    96,    -1,
     186,    -1,   201,    -1,   108,    -1,   129,    -1,   191,    -1,
      89,    -1,    -1,    17,   296,   220,   297,   219,   218,    -1,
     297,   298,    -1,   298,    -1,   299,    -1,   310,    -1,   311,
      -1,   300,    -1,   301,    -1,   312,    -1,   302,    -1,   303,
      -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,   308,
      -1,   309,    -1,     1,   218,    -1,    91,   221,   120,   218,
      -1,   117,   221,   227,   218,    -1,   118,   221,   227,   218,
      -1,   103,   221,   101,   218,    -1,    19,   221,   227,   218,
      -1,    83,   221,   101,   218,    -1,    78,   221,   101,   218,
      -1,    80,   221,   101,   218,    -1,    79,   221,   101,   218,
      -1,   146,   221,   229,   218,    -1,   187,   221,   229,   218,
      -1,    15,   221,   101,   218,    -1,    16,   221,   101,   218,
      -1,   102,   221,   101,   218,    -1,    -1,    72,   314,   220,
     319,   219,   218,    -1,    -1,    36,   316,   221,   317,   218,
      -1,   317,   222,   318,    -1,   318,    -1,   194,    -1,    51,
      -1,   189,    -1,   319,   320,    -1,   320,    -1,   321,    -1,
     315,    -1,   325,    -1,   326,    -1,     1,   218,    -1,    -1,
     119,   221,   323,   322,   218,    -1,   323,   222,   324,    -1,
     324,    -1,   101,    -1,   101,   167,   101,    -1,    61,   221,
     120,   218,    -1,    56,   221,   120,   218,    -1,    -1,    48,
     328,   220,   329,   219,   218,    -1,   329,   330,    -1,   330,
      -1,   331,    -1,   332,    -1,   333,    -1,   335,    -1,   339,
      -1,   340,    -1,   341,    -1,   334,    -1,     1,   218,    -1,
     209,   221,   120,   218,    -1,   114,   221,   120,   218,    -1,
      17,   221,   120,   218,    -1,    32,   221,   163,   218,    -1,
      -1,    36,   336,   221,   337,   218,    -1,   337,   222,   338,
      -1,   338,    -1,   157,    -1,    33,    -1,    65,    -1,    49,
      -1,    13,    -1,   100,    -1,    43,    -1,   140,    -1,    92,
      -1,   156,   221,   120,   218,    -1,   124,   221,   120,   218,
      -1,   123,   221,   101,   218,    -1,    -1,   139,   343,   220,
     344,   219,   218,    -1,   344,   345,    -1,   345,    -1,   346,
      -1,   347,    -1,   348,    -1,     1,   218,    -1,   122,   221,
     120,   218,    -1,    14,   221,   120,   218,    -1,    95,   221,
     120,   218,    -1,   204,   220,   350,   219,   218,    -1,   350,
     351,    -1,   351,    -1,   352,    -1,     1,    -1,    91,   221,
     120,   218,    -1,    -1,   152,   354,   220,   355,   219,   218,
      -1,   355,   356,    -1,   356,    -1,   357,    -1,   358,    -1,
     359,    -1,     1,   218,    -1,    91,   221,   120,   218,    -1,
     209,   221,   120,   218,    -1,    -1,   154,   360,   221,   361,
     218,    -1,   361,   222,   362,    -1,   362,    -1,    64,    -1,
     208,    -1,   177,    -1,   197,    -1,   214,    -1,   200,    -1,
     139,    -1,   199,    -1,   183,    -1,   168,    -1,    -1,   153,
     364,   220,   365,   219,   218,    -1,   365,   366,    -1,   366,
      -1,   367,    -1,   368,    -1,     1,   218,    -1,    91,   221,
     120,   218,    -1,    -1,   154,   369,   221,   370,   218,    -1,
     370,   222,   371,    -1,   371,    -1,    64,    -1,   208,    -1,
     177,    -1,   197,    -1,   214,    -1,   200,    -1,   139,    -1,
     199,    -1,   183,    -1,   168,    -1,    -1,    18,   373,   220,
     374,   219,   218,    -1,   374,   375,    -1,   375,    -1,   376,
      -1,   377,    -1,   378,    -1,   379,    -1,   380,    -1,   382,
      -1,   381,    -1,   391,    -1,   383,    -1,   388,    -1,   389,
      -1,   390,    -1,   387,    -1,     1,   218,    -1,    91,   221,
     120,   218,    -1,    56,   221,   120,   218,    -1,   212,   221,
     120,   218,    -1,   147,   221,   120,   218,    -1,     3,   221,
     120,   218,    -1,   119,   221,   101,   218,    -1,     5,   221,
     181,   218,    -1,     5,   221,   182,   218,    -1,    -1,    36,
     384,   221,   385,   218,    -1,   385,   222,   386,    -1,   386,
      -1,     8,    -1,   194,    -1,    32,   221,   163,   218,    -1,
      58,   221,   120,   218,    -1,    70,   221,   120,   218,    -1,
      17,   221,   120,   218,    -1,   174,   221,   120,   218,    -1,
      -1,    62,   393,   220,   398,   219,   218,    -1,    -1,   154,
     395,   221,   396,   218,    -1,   396,   222,   397,    -1,   397,
      -1,   125,    -1,   398,   399,    -1,   399,    -1,   400,    -1,
     401,    -1,   394,    -1,     1,    -1,   209,   221,   120,   218,
      -1,   122,   221,   120,   218,    -1,    -1,    23,   403,   220,
     404,   219,   218,    -1,   404,   405,    -1,   405,    -1,   406,
      -1,   407,    -1,     1,    -1,    61,   221,   120,   218,    -1,
     122,   221,   120,   218,    -1,    34,   220,   409,   219,   218,
      -1,   409,   410,    -1,   410,    -1,   411,    -1,     1,    -1,
      61,   221,   120,   218,    -1,    -1,    38,   413,   220,   418,
     219,   218,    -1,    -1,   154,   415,   221,   416,   218,    -1,
     416,   222,   417,    -1,   417,    -1,   125,    -1,   418,   419,
      -1,   419,    -1,   420,    -1,   421,    -1,   414,    -1,     1,
      -1,    91,   221,   120,   218,    -1,   122,   221,   120,   218,
      -1,    39,   220,   423,   219,   218,    -1,   423,   424,    -1,
     424,    -1,   434,    -1,   435,    -1,   437,    -1,   438,    -1,
     439,    -1,   440,    -1,   441,    -1,   442,    -1,   443,    -1,
     444,    -1,   433,    -1,   446,    -1,   447,    -1,   448,    -1,
     449,    -1,   464,    -1,   451,    -1,   453,    -1,   455,    -1,
     454,    -1,   458,    -1,   452,    -1,   459,    -1,   460,    -1,
     461,    -1,   462,    -1,   463,    -1,   476,    -1,   465,    -1,
     466,    -1,   467,    -1,   472,    -1,   456,    -1,   457,    -1,
     482,    -1,   480,    -1,   481,    -1,   436,    -1,   471,    -1,
     445,    -1,   469,    -1,   470,    -1,   432,    -1,   426,    -1,
     427,    -1,   428,    -1,   429,    -1,   430,    -1,   431,    -1,
     450,    -1,   425,    -1,   468,    -1,     1,    -1,    85,   221,
     101,   218,    -1,    42,   221,   163,   218,    -1,    41,   221,
     227,   218,    -1,    44,   221,   227,   218,    -1,    45,   221,
     101,   218,    -1,    46,   221,   101,   218,    -1,   127,   221,
     227,   218,    -1,   151,   221,   163,   218,    -1,    63,   221,
     227,   218,    -1,    55,   221,   163,   218,    -1,    59,   221,
     163,   218,    -1,    28,   221,   163,   218,    -1,    35,   221,
     163,   218,    -1,     6,   221,   163,   218,    -1,    82,   221,
     227,   218,    -1,    81,   221,   101,   218,    -1,    74,   221,
     101,   218,    -1,     7,   221,   227,   218,    -1,   166,   221,
     227,   218,    -1,   165,   221,   227,   218,    -1,    50,   221,
     101,   218,    -1,    67,   221,   163,   218,    -1,    66,   221,
     120,   218,    -1,    60,   221,   163,   218,    -1,   215,   221,
     163,   218,    -1,   158,   221,   163,   218,    -1,   161,   221,
     163,   218,    -1,   162,   221,   163,   218,    -1,   160,   221,
     163,   218,    -1,   160,   221,   164,   218,    -1,   159,   221,
     163,   218,    -1,   159,   221,   164,   218,    -1,   112,   221,
     227,   218,    -1,    12,   221,   227,   218,    -1,   105,   221,
     163,   218,    -1,   113,   221,   227,   218,    -1,   155,   221,
     163,   218,    -1,    99,   221,   163,   218,    -1,   207,   221,
     163,   218,    -1,   107,   221,   163,   218,    -1,    86,   221,
     120,   218,    -1,    29,   221,   101,   218,    -1,    84,   221,
     101,   218,    -1,   210,   221,   163,   218,    -1,    30,   221,
     120,   218,    -1,   205,   221,   120,   218,    -1,   116,   221,
     163,   218,    -1,    26,   221,   163,   218,    -1,   206,   221,
     227,   218,    -1,    -1,   109,   473,   221,   474,   218,    -1,
     474,   222,   475,    -1,   475,    -1,   169,    -1,   172,    -1,
     173,    -1,   175,    -1,   176,    -1,   179,    -1,    51,    -1,
     192,    -1,   185,    -1,   188,    -1,   196,    -1,   193,    -1,
     178,    -1,   186,    -1,   190,    -1,   180,    -1,   202,    -1,
     170,    -1,   171,    -1,   183,    -1,    -1,   106,   477,   221,
     478,   218,    -1,   478,   222,   479,    -1,   479,    -1,   169,
      -1,   172,    -1,   173,    -1,   175,    -1,   176,    -1,   179,
      -1,   192,    -1,    51,    -1,   185,    -1,   188,    -1,   196,
      -1,   193,    -1,   178,    -1,   186,    -1,   190,    -1,   180,
      -1,   202,    -1,   170,    -1,   171,    -1,   183,    -1,    87,
     221,   101,   218,    -1,    88,   221,   101,   218,    -1,    20,
     221,   101,   218,    -1,    14,   220,   484,   219,   218,    -1,
     484,   485,    -1,   485,    -1,   493,    -1,   488,    -1,   489,
      -1,   490,    -1,   491,    -1,   492,    -1,   494,    -1,   495,
      -1,   496,    -1,   487,    -1,   497,    -1,   498,    -1,   499,
      -1,   486,    -1,     1,    -1,    27,   221,   163,   218,    -1,
     130,   221,   163,   218,    -1,    68,   221,   227,   218,    -1,
      69,   221,   227,   218,    -1,    77,   221,   101,   218,    -1,
      76,   221,   101,   218,    -1,   121,   221,   163,   218,    -1,
      75,   221,   101,   218,    -1,    22,   221,   101,   218,    -1,
      21,   221,   101,   218,    -1,    97,   221,   163,   218,    -1,
      98,   221,   163,   218,    -1,   110,   221,   101,   218,    -1,
     111,   221,   227,   218,    -1,   148,   220,   501,   219,   218,
      -1,   501,   502,    -1,   502,    -1,   503,    -1,   504,    -1,
     506,    -1,   507,    -1,   505,    -1,   508,    -1,     1,    -1,
      37,   221,   163,   218,    -1,    54,   221,   163,   218,    -1,
      52,   221,   120,   218,    -1,    71,   221,   227,   218,    -1,
      51,   221,   163,   218,    -1,    53,   221,   163,   218,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   333,   333,   334,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   362,   362,   363,   367,
     371,   375,   379,   383,   389,   389,   390,   391,   392,   393,
     400,   403,   403,   404,   404,   404,   406,   412,   419,   421,
     421,   422,   422,   423,   423,   424,   424,   425,   425,   426,
     426,   427,   427,   428,   428,   429,   430,   433,   434,   436,
     436,   437,   443,   451,   451,   452,   458,   466,   505,   564,
     592,   600,   615,   630,   639,   653,   662,   690,   720,   743,
     752,   754,   754,   755,   755,   756,   756,   758,   767,   776,
     788,   789,   789,   791,   791,   792,   794,   801,   801,   811,
     812,   814,   814,   815,   815,   817,   822,   825,   831,   830,
     836,   836,   837,   841,   845,   849,   853,   857,   861,   872,
     871,   969,   969,   970,   970,   970,   971,   971,   971,   972,
     972,   972,   974,   983,  1020,  1032,  1043,  1085,  1095,  1094,
    1100,  1100,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,
    1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1177,  1184,  1183,  1189,  1189,  1190,  1194,  1198,  1202,
    1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,
    1246,  1250,  1254,  1258,  1262,  1273,  1272,  1322,  1322,  1323,
    1324,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1334,  1334,  1335,  1337,  1346,  1352,  1358,  1364,  1370,
    1376,  1382,  1388,  1394,  1400,  1407,  1413,  1419,  1429,  1428,
    1445,  1444,  1449,  1449,  1450,  1454,  1458,  1466,  1466,  1467,
    1467,  1467,  1467,  1467,  1469,  1469,  1471,  1471,  1473,  1487,
    1507,  1516,  1529,  1528,  1597,  1597,  1598,  1598,  1598,  1598,
    1599,  1599,  1599,  1600,  1600,  1602,  1637,  1650,  1659,  1671,
    1670,  1674,  1674,  1675,  1679,  1683,  1687,  1691,  1695,  1699,
    1703,  1707,  1713,  1732,  1742,  1756,  1755,  1771,  1771,  1772,
    1772,  1772,  1772,  1774,  1783,  1798,  1811,  1813,  1813,  1814,
    1814,  1816,  1832,  1831,  1847,  1847,  1848,  1848,  1848,  1848,
    1850,  1859,  1882,  1881,  1887,  1887,  1888,  1892,  1896,  1900,
    1904,  1908,  1912,  1916,  1920,  1924,  1934,  1933,  1950,  1950,
    1951,  1951,  1951,  1953,  1960,  1959,  1965,  1965,  1966,  1970,
    1974,  1978,  1982,  1986,  1990,  1994,  1998,  2002,  2012,  2011,
    2062,  2062,  2063,  2063,  2063,  2064,  2064,  2065,  2065,  2065,
    2066,  2066,  2066,  2067,  2067,  2068,  2070,  2079,  2088,  2114,
    2132,  2150,  2156,  2160,  2169,  2168,  2172,  2172,  2173,  2177,
    2183,  2194,  2205,  2216,  2225,  2244,  2243,  2309,  2308,  2312,
    2312,  2313,  2319,  2319,  2320,  2320,  2320,  2320,  2322,  2341,
    2351,  2350,  2375,  2375,  2376,  2376,  2376,  2378,  2384,  2393,
    2395,  2395,  2396,  2396,  2398,  2417,  2416,  2464,  2463,  2467,
    2467,  2468,  2474,  2474,  2475,  2475,  2475,  2475,  2477,  2483,
    2492,  2495,  2495,  2496,  2496,  2497,  2497,  2498,  2498,  2499,
    2499,  2500,  2500,  2501,  2501,  2502,  2502,  2503,  2503,  2504,
    2504,  2505,  2505,  2506,  2506,  2507,  2507,  2508,  2508,  2509,
    2510,  2510,  2511,  2511,  2512,  2512,  2513,  2513,  2514,  2514,
    2515,  2516,  2516,  2517,  2518,  2519,  2519,  2520,  2520,  2521,
    2522,  2523,  2523,  2524,  2524,  2525,  2528,  2533,  2539,  2545,
    2551,  2556,  2561,  2566,  2571,  2576,  2581,  2586,  2591,  2596,
    2601,  2606,  2611,  2616,  2621,  2626,  2632,  2643,  2648,  2657,
    2662,  2667,  2672,  2677,  2682,  2685,  2690,  2693,  2698,  2703,
    2708,  2713,  2718,  2723,  2728,  2733,  2738,  2749,  2754,  2759,
    2764,  2773,  2782,  2787,  2792,  2798,  2797,  2802,  2802,  2803,
    2806,  2809,  2812,  2815,  2818,  2821,  2824,  2827,  2830,  2833,
    2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,  2860,  2866,
    2865,  2870,  2870,  2871,  2874,  2877,  2880,  2883,  2886,  2889,
    2892,  2895,  2898,  2901,  2904,  2907,  2910,  2913,  2916,  2919,
    2922,  2925,  2928,  2933,  2938,  2943,  2952,  2955,  2955,  2956,
    2957,  2957,  2958,  2958,  2959,  2959,  2960,  2961,  2961,  2962,
    2963,  2963,  2964,  2964,  2966,  2971,  2976,  2981,  2986,  2991,
    2996,  3001,  3006,  3011,  3016,  3021,  3026,  3031,  3039,  3042,
    3042,  3043,  3043,  3044,  3045,  3045,  3046,  3047,  3049,  3055,
    3061,  3070,  3084,  3090
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN", "BYTES",
  "KBYTES", "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "EGDPOOL_PATH", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT",
  "GLINE_REQUEST_DURATION", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_REASON", "KLINE_WITH_REASON", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_WATCH",
  "MESSAGE_LOCALE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULES", "NAME", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NICK_CHANGES", "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES",
  "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT",
  "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH",
  "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT", "QSTRING",
  "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH",
  "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE", "USER", "USE_EGD",
  "USE_LOGGING", "VHOST", "VHOST6", "XLINE", "WARN_NO_NLINE", "T_SIZE",
  "T_FILE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_use_logging",
  "logging_file_entry", "$@1", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@2",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@3",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class",
  "oper_umodes", "$@4", "oper_umodes_items", "oper_umodes_item",
  "oper_flags", "$@5", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@6", "class_items", "class_item", "class_name",
  "class_ping_time", "class_ping_warning", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@7", "listen_flags", "$@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@11", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@12", "resv_items",
  "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "service_entry", "service_items", "service_item", "service_name",
  "shared_entry", "$@13", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "$@14", "shared_types", "shared_type_item",
  "cluster_entry", "$@15", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@16", "cluster_types", "cluster_type_item",
  "connect_entry", "$@17", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@18", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@19",
  "kill_type", "$@20", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@21",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@22",
  "gecos_flags", "$@23", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_reject_hold_time",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_hide_spoof_ips", "general_ignore_bogus_ts",
  "general_disable_remote_commands", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_havent_read_conf",
  "general_kline_with_reason", "general_kline_reason",
  "general_invisible_on_connect", "general_warn_no_nline",
  "general_stats_e_disabled", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_message_locale",
  "general_dots_in_ident", "general_max_targets", "general_use_egd",
  "general_egdpool_path", "general_services_name", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "$@24", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@25", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,    59,   125,
     123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   223,   224,   224,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   227,   227,
     227,   227,   227,   227,   228,   228,   229,   229,   229,   229,
     230,   231,   231,   232,   232,   232,   233,   234,   235,   236,
     236,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   239,   240,
     240,   241,   241,   242,   242,   243,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   258,   259,   259,   259,   259,   260,   261,   262,
     263,   264,   264,   265,   265,   265,   266,   268,   267,   269,
     269,   270,   270,   270,   270,   271,   272,   272,   274,   273,
     275,   275,   276,   276,   276,   276,   276,   276,   276,   278,
     277,   279,   279,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   281,   282,   283,   284,   285,   286,   288,   287,
     289,   289,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   292,   291,   293,   293,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   296,   295,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   314,   313,
     316,   315,   317,   317,   318,   318,   318,   319,   319,   320,
     320,   320,   320,   320,   322,   321,   323,   323,   324,   324,
     325,   326,   328,   327,   329,   329,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   331,   332,   333,   334,   336,
     335,   337,   337,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   339,   340,   341,   343,   342,   344,   344,   345,
     345,   345,   345,   346,   347,   348,   349,   350,   350,   351,
     351,   352,   354,   353,   355,   355,   356,   356,   356,   356,
     357,   358,   360,   359,   361,   361,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   364,   363,   365,   365,
     366,   366,   366,   367,   369,   368,   370,   370,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   373,   372,
     374,   374,   375,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   376,   377,   378,   379,
     380,   381,   382,   382,   384,   383,   385,   385,   386,   386,
     387,   388,   389,   390,   391,   393,   392,   395,   394,   396,
     396,   397,   398,   398,   399,   399,   399,   399,   400,   401,
     403,   402,   404,   404,   405,   405,   405,   406,   407,   408,
     409,   409,   410,   410,   411,   413,   412,   415,   414,   416,
     416,   417,   418,   418,   419,   419,   419,   419,   420,   421,
     422,   423,   423,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   453,   454,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   473,   472,   474,   474,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   477,
     476,   478,   478,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   480,   481,   482,   483,   484,   484,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     501,   502,   502,   502,   502,   502,   502,   502,   503,   504,
     505,   506,   507,   508
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     0,     1,     2,     3,     3,     3,
       5,     2,     1,     1,     1,     2,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     0,     5,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     0,     5,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   348,   400,     0,
     415,     0,   252,   385,   228,     0,     0,   129,   285,     0,
       0,   302,   326,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   603,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   602,   598,   590,   591,   592,   593,   594,
     589,   595,   596,   597,   599,   600,   601,     0,     0,     0,
     413,     0,     0,   411,   412,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   559,     0,
     535,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   483,   476,   477,   478,   479,   480,   481,   475,   443,
     433,   434,   470,   435,   436,   437,   438,   439,   440,   441,
     442,   472,   444,   445,   446,   447,   482,   449,   454,   450,
     452,   451,   465,   466,   453,   455,   456,   457,   458,   459,
     448,   461,   462,   463,   484,   473,   474,   471,   464,   460,
     468,   469,   467,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,     0,     0,     0,     0,    42,    43,    44,
       0,     0,   627,     0,     0,     0,     0,     0,     0,     0,
     620,   621,   622,   625,   623,   624,   626,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    63,    64,    62,    59,    58,
      65,    51,    61,    54,    55,    56,    52,    60,    57,    53,
       0,     0,   300,     0,     0,   298,   299,    96,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   199,   202,   203,   205,
     206,   207,   208,   209,   210,   211,   212,   200,   201,   204,
       0,     0,     0,     0,     0,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   351,   352,   353,   354,   355,
     356,   358,   357,   360,   364,   361,   362,   363,   359,   406,
       0,     0,     0,   403,   404,   405,     0,     0,   410,   427,
       0,     0,   417,   426,     0,   423,   424,   425,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,   263,   259,   260,   261,
     262,   397,     0,   387,     0,   396,     0,   393,   394,   395,
       0,   230,     0,     0,     0,   240,     0,   238,   239,   241,
     242,   105,     0,     0,   101,     0,    45,     0,     0,     0,
      41,     0,     0,     0,   172,     0,     0,     0,   148,     0,
       0,   132,   133,   134,   135,   138,   139,   137,   136,   140,
       0,     0,     0,     0,     0,   288,   289,   290,   291,     0,
       0,     0,     0,     0,     0,     0,   619,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,   312,     0,     0,
     305,   306,   307,   308,     0,     0,   334,     0,   329,   330,
     331,     0,     0,   297,     0,     0,     0,    90,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   213,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   365,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   350,     0,     0,     0,
     402,     0,   409,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   430,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   254,     0,     0,     0,     0,   392,   243,
       0,     0,     0,     0,     0,   237,     0,   100,     0,     0,
       0,    40,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   292,     0,     0,     0,     0,   287,     0,
       0,     0,     0,     0,     0,   618,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,     0,    70,    75,    76,
       0,    74,     0,     0,     0,     0,     0,    48,   309,     0,
       0,     0,     0,   304,   332,     0,     0,     0,   328,     0,
     296,    99,    98,    97,   613,   612,   604,    26,    26,    26,
      26,    26,    28,    27,   606,   607,   611,   609,   608,   614,
     615,   616,   617,   610,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   349,     0,     0,   401,   414,
       0,     0,     0,   416,   499,   503,   519,   585,   533,   497,
     527,   530,   498,   488,   487,   489,   490,   491,   506,   495,
     496,   509,   494,   508,   507,   502,   501,   500,   528,   486,
     526,   583,   584,   523,   520,   570,   563,   580,   581,   564,
     565,   566,   567,   575,   568,   578,   582,   571,   576,   572,
     577,   569,   574,   573,   579,     0,   562,   525,   545,   539,
     556,   557,   540,   541,   542,   543,   551,   544,   554,   558,
     547,   552,   548,   553,   546,   550,   549,   555,     0,   538,
     518,   521,   532,   492,   493,   522,   511,   516,   517,   514,
     515,   512,   513,   505,   504,   531,   534,   524,   529,   510,
       0,     0,     0,     0,     0,     0,     0,     0,   253,     0,
       0,     0,   386,     0,     0,     0,   248,   244,   247,   229,
     106,     0,     0,   118,     0,     0,   110,   111,   113,   112,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,   286,   628,   632,   630,   633,   629,
     631,    83,    89,    81,    85,    84,    78,    77,    79,    67,
       0,    68,     0,    82,    80,    88,    86,    87,     0,     0,
       0,   303,     0,     0,   327,   301,    29,    30,    31,    32,
      33,   225,   226,   218,   220,   222,   221,   219,   214,   227,
     217,   215,   216,    34,    34,    34,    36,    35,   223,   224,
     370,   372,   373,   383,   380,   378,   379,     0,   377,   367,
     381,   382,   366,   371,   369,   384,   368,   407,   408,   428,
     429,   421,     0,   420,   560,     0,   536,     0,   267,   268,
     277,   274,   279,   276,   275,   281,   278,   280,   273,     0,
     272,   266,   284,   283,   282,   265,   399,   391,     0,   390,
     398,   235,   236,   234,     0,   233,   251,   250,     0,     0,
       0,   114,     0,     0,     0,     0,   109,   147,   145,   187,
     184,   183,   176,   178,   194,   188,   191,   186,   177,   192,
     180,   189,   193,   181,   190,   185,   179,   182,     0,   175,
     142,   144,   146,   158,   152,   169,   170,   153,   154,   155,
     156,   164,   157,   167,   171,   160,   165,   161,   166,   159,
     163,   162,   168,     0,   151,   143,   294,   295,   293,    69,
      73,   310,   316,   322,   325,   318,   324,   319,   323,   321,
     317,   320,     0,   315,   311,   333,   338,   344,   347,   340,
     346,   341,   345,   343,   339,   342,     0,   337,    37,    38,
      39,   375,     0,   418,     0,   561,   537,   270,     0,   388,
       0,   231,     0,   249,   246,   245,     0,     0,     0,     0,
     108,   173,     0,   149,     0,   313,     0,   335,     0,   376,
     419,   271,   389,   232,   115,   124,   127,   126,   123,   128,
     125,   122,     0,   121,   117,   116,   174,   150,   314,   336,
     119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   792,   793,  1036,  1037,    25,   236,   237,
     238,   239,    26,   273,   274,   275,   276,   756,   757,   760,
     761,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,    27,    71,    72,    73,    74,    75,
      28,   228,   229,   230,   231,   232,   965,   966,   967,   968,
     969,  1103,  1232,  1233,    29,    60,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   729,  1153,  1154,   519,   725,
    1128,  1129,    30,    49,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
      31,    57,   485,   710,  1094,  1095,   486,   487,   488,  1100,
     957,   958,   489,   490,    32,    55,   461,   462,   463,   464,
     465,   466,   467,   696,  1079,  1080,   468,   469,   470,    33,
      61,   524,   525,   526,   527,   528,    34,   294,   295,   296,
      35,    64,   559,   560,   561,   562,   563,   770,  1172,  1173,
      36,    65,   567,   568,   569,   570,   776,  1186,  1187,    37,
      50,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   616,  1047,  1048,   374,   375,   376,   377,   378,    38,
      56,   475,   705,  1088,  1089,   476,   477,   478,   479,    39,
      51,   382,   383,   384,   385,    40,   112,   113,   114,    41,
      53,   393,   635,  1062,  1063,   394,   395,   396,   397,    42,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     431,   918,   919,   219,   429,   895,   896,   220,   221,   222,
      43,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    44,   249,   250,
     251,   252,   253,   254,   255,   256
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -745
static const yytype_int16 yypact[] =
{
    -745,   586,  -745,  -204,  -214,  -193,  -745,  -745,  -745,  -191,
    -745,  -188,  -745,  -745,  -745,  -177,  -175,  -745,  -745,  -161,
    -136,  -745,  -745,  -120,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   263,   837,   -87,
     -84,   -32,    17,   -25,   352,   -22,   -10,    -4,    61,     3,
      13,    36,   656,   389,    51,    75,    11,   -80,   -45,   -34,
      22,    16,  -745,  -745,  -745,  -745,  -745,    42,    76,    77,
      89,    91,    92,   111,   116,   117,   126,   128,   129,   130,
     135,   231,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   595,   470,   118,
    -745,   136,     6,  -745,  -745,   192,  -745,   141,   142,   144,
     146,   148,   150,   154,   155,   156,   158,   162,   163,   164,
     167,   171,   178,   180,   182,   183,   184,   187,   188,   189,
     195,   196,   199,   201,   202,   203,   204,   206,  -745,   207,
    -745,   211,   214,   220,   221,   222,   223,   226,   227,   232,
     234,   239,   241,   242,   245,   246,   248,   251,   253,   115,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   413,   157,   287,    20,   255,    48,  -745,
    -745,  -745,    79,   173,   257,   264,    65,  -745,  -745,  -745,
     338,   359,  -745,   265,   267,   268,   269,   270,   272,    18,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   266,   273,   274,
     275,   277,   279,   280,   283,   284,   288,   298,   300,   308,
     309,   311,   313,    73,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     191,    23,  -745,   314,    35,  -745,  -745,  -745,   388,   395,
     418,   324,  -745,   442,   443,   382,   445,   445,   448,   449,
     450,   391,   393,   463,   445,   402,   403,   350,  -745,   353,
     349,   351,   354,   355,   356,   358,   361,   362,   363,   364,
     367,   370,   371,   372,     7,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     376,   377,   378,   384,   385,  -745,   386,   387,   392,   394,
     397,   398,   400,   407,    43,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     409,   410,    50,  -745,  -745,  -745,   454,   379,  -745,  -745,
     411,   412,  -745,  -745,    15,  -745,  -745,  -745,   453,   445,
     445,   511,   460,   472,   535,   517,   476,   445,   477,   445,
     540,   541,   544,   483,   484,   487,   445,   531,   489,   553,
     560,   445,   561,   562,   549,   563,   569,   509,   518,   459,
     520,   468,   445,   445,   521,   445,   528,   529,   532,  -143,
     -82,   536,   538,   445,   445,   574,   445,   543,   548,   551,
     485,  -745,   486,   494,   495,  -745,   496,   497,   503,   505,
     507,   212,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   508,  -745,   510,  -745,    30,  -745,  -745,  -745,
     512,  -745,   515,   516,   519,  -745,    27,  -745,  -745,  -745,
    -745,  -745,   570,   524,  -745,   523,  -745,   629,   632,   539,
    -745,   546,   545,   552,  -745,   554,   557,   558,  -745,   559,
      41,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     556,   564,   566,   567,    90,  -745,  -745,  -745,  -745,   596,
     599,   649,   607,   609,   445,   565,  -745,  -745,   661,   621,
     669,   671,   673,   674,   680,   683,   -44,    81,   690,   693,
     714,   697,   700,   603,  -745,   613,   620,  -745,   627,    32,
    -745,  -745,  -745,  -745,   631,   633,  -745,   114,  -745,  -745,
    -745,   732,   635,  -745,   637,   639,   642,  -745,   643,   644,
     645,   578,   648,   651,   652,   653,   655,   657,   659,   660,
     662,   663,   666,  -745,  -745,   771,   773,   445,   778,   784,
     785,   786,   768,   788,   789,   445,   445,   790,   790,   675,
    -745,  -745,   772,   -33,   774,   733,   676,   775,   779,   781,
     782,   797,   783,   787,   791,   686,  -745,   795,   796,   691,
    -745,   692,  -745,   798,   799,   687,   699,  -745,   702,   703,
     704,   705,   706,   707,   708,   709,   710,   711,   712,   713,
     715,   718,   719,   720,   721,   722,   723,   724,   725,   726,
     727,   728,   731,   734,   735,   736,   737,   738,   739,   575,
     741,   626,   742,   744,   745,   746,   747,   748,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,  -745,  -745,   812,   819,   729,   831,   860,   863,
     864,   865,   769,  -745,   866,   767,   869,   776,  -745,  -745,
     770,   870,   872,   892,   777,  -745,   780,  -745,    29,   792,
     793,  -745,  -745,   876,   834,   794,   879,   880,   881,   800,
     882,   801,  -745,  -745,   883,   884,   885,   802,  -745,   804,
     805,   806,   807,   808,   809,  -745,   810,   811,   813,   814,
     815,   816,   817,   818,  -745,  -745,  -209,  -745,  -745,  -745,
    -184,  -745,   820,   821,   822,   823,   824,  -745,  -745,   886,
     825,   887,   826,  -745,  -745,   888,   827,   829,  -745,   832,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   445,   445,   445,
     445,   445,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   833,   835,   836,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   294,   847,   848,
    -745,   849,   850,   851,   852,   853,    -3,   854,   855,   856,
     857,   858,   859,   861,   862,  -745,   867,   868,  -745,  -745,
     871,   873,   889,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -183,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -181,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     874,   875,   743,   877,   878,   890,   891,   893,  -745,   894,
     905,   895,  -745,   -26,   896,   897,   911,   830,  -745,  -745,
    -745,   898,   828,  -745,   899,   170,  -745,  -745,  -745,  -745,
    -745,  -745,   900,   901,   452,   903,   904,   906,   654,   907,
    -745,   908,   909,   910,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     -44,  -745,    81,  -745,  -745,  -745,  -745,  -745,   912,   488,
     913,  -745,   914,   668,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   790,   790,   790,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -168,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -166,  -745,  -745,   575,  -745,   626,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -165,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -157,  -745,
    -745,  -745,  -745,  -745,  -154,  -745,  -745,  -745,   915,   892,
     916,  -745,   917,   902,   -90,   918,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -142,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   -71,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,    -7,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,   109,  -745,  -745,  -745,
    -745,  -745,    -3,  -745,   889,  -745,  -745,  -745,   743,  -745,
     905,  -745,   -26,  -745,  -745,  -745,   919,   491,   920,   921,
    -745,  -745,   452,  -745,   654,  -745,   488,  -745,   668,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   122,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   491,  -745
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -745,  -745,  -745,  -472,  -304,  -744,  -607,  -745,  -745,   922,
    -745,  -745,  -745,  -745,   740,  -745,  -745,  -745,     9,  -745,
      10,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,   946,  -745,  -745,  -745,
    -745,  -745,   923,  -745,  -745,  -745,  -745,    53,  -745,  -745,
    -745,  -745,  -745,  -198,  -745,  -745,  -745,   571,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -169,  -745,  -745,
    -745,  -130,  -745,  -745,  -745,   749,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -147,  -745,   598,  -745,  -745,
    -745,   -12,  -745,  -745,  -745,  -745,  -745,   636,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -110,  -745,  -745,  -745,  -745,
    -745,  -745,   576,  -745,  -745,  -745,  -745,  -745,   924,  -745,
    -745,  -745,  -745,   542,  -745,  -745,  -745,  -745,  -745,  -126,
    -745,  -745,  -745,   527,  -745,  -745,  -745,  -745,  -119,  -745,
    -745,  -745,   765,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   -94,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   -98,  -745,   628,  -745,  -745,  -745,
    -745,  -745,   764,  -745,  -745,  -745,  -745,   991,  -745,  -745,
    -745,  -745,  -745,  -745,   -89,  -745,   716,  -745,  -745,  -745,
    -745,   937,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,    40,  -745,  -745,  -745,    52,  -745,  -745,  -745,
    -745,  -745,  1042,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   925,
    -745,  -745,  -745,  -745,  -745,  -745
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     818,   819,   582,   583,   233,  1045,    47,   110,   319,   999,
     590,   817,   292,  1000,    45,    46,   389,    67,   110,   242,
     679,   680,   320,   321,   564,  1091,   322,    48,   480,    52,
     961,   471,    54,   555,  1001,  1064,   292,  1066,  1002,  1065,
      68,  1067,   501,    58,   350,    59,   351,    69,   352,   226,
    1191,   379,  1193,  1197,  1192,   243,  1194,  1198,   502,    62,
     353,  1199,   226,   481,  1201,  1200,   233,   111,  1202,   244,
     245,   246,   247,   503,   257,   354,  1211,   504,   111,   355,
    1212,   681,   682,   482,    63,   323,   324,   325,   483,   248,
     326,   520,   234,   754,   755,   639,   640,   258,   327,   356,
      66,   357,   293,   647,   521,   649,   390,    70,  1208,   328,
     329,   380,   656,   358,   565,   564,   116,   661,   235,   379,
     962,   117,   118,   556,   330,   331,   293,   119,   672,   673,
     259,   675,   505,   107,   359,   120,   108,   391,   297,   685,
     686,   121,   688,   122,   123,   124,   484,  1213,   822,   823,
     125,  1214,   472,   332,   234,   506,   126,   127,   471,   128,
     129,   130,   360,  1092,   260,   131,   261,   262,  1093,   392,
     132,   961,   381,   507,   133,   134,   298,   566,   135,   380,
     235,   136,   137,   963,   473,   522,   557,   299,   109,   138,
     361,  1046,   555,   389,   333,   115,   139,   140,   223,   141,
     142,   143,   144,   145,   263,   565,   264,   265,   266,   267,
     224,  1215,   523,   452,   146,  1216,   225,   362,   758,   759,
     147,   148,   149,   268,   150,   387,   609,   151,   152,   453,
     744,   153,    76,   240,   636,   301,   508,   535,   491,   474,
     381,   558,   154,   300,   454,   964,   714,   269,   455,   707,
     509,   772,    77,    78,   572,   363,   241,   270,    79,   227,
     731,   962,   625,   303,    67,  -107,   155,   493,   566,   629,
     156,   290,   227,   157,   158,   159,   160,   161,  -107,   472,
     162,   163,   556,   390,   499,   271,   272,    68,   480,  1188,
    1189,  1190,   553,   807,    69,   291,   495,   304,   305,    80,
      81,   815,   816,  1033,  1034,  1035,    82,    83,    84,   737,
     306,   473,   307,   308,   391,  1016,  1017,  1018,  1019,  1020,
     164,   165,   166,   481,   963,   167,   456,  1217,    85,    86,
     168,  1218,   309,   777,   450,   457,   458,   310,   311,   501,
    1240,    87,    88,   482,  1241,   557,   392,   312,   483,   313,
     314,   315,    89,   116,    70,   502,   316,   386,   117,   118,
     520,    90,   398,   399,   119,   400,   474,   401,   459,   402,
     503,   403,   120,   521,   504,   404,   405,   406,   121,   407,
     122,   123,   124,   408,   409,   410,   964,   125,   411,  1105,
     257,   496,   412,   126,   127,   817,   128,   129,   130,   413,
     558,   414,   131,   415,   416,   417,   484,   132,   418,   419,
     420,   133,   134,   258,   452,   135,   421,   422,   136,   137,
     423,   460,   424,   425,   426,   427,   138,   428,   430,   505,
     453,   702,   432,   139,   140,   433,   141,   142,   143,   144,
     145,   434,   435,   436,   437,   454,   259,   438,   439,   455,
     317,   146,   506,   440,   522,   441,  1109,   147,   148,   149,
     442,   150,   443,   444,   151,   152,   445,   446,   153,   447,
     507,   350,   448,   351,   449,   352,   492,  1110,   497,   154,
     260,   523,   261,   262,   537,   498,   529,   353,   530,   531,
     532,   533,  1111,   534,   538,   539,   540,  1209,   541,  1112,
     542,   543,   354,   155,   544,   545,   355,   156,   574,   546,
     157,   158,   159,   160,   161,   575,  1113,   162,   163,   547,
     263,   548,   264,   265,   266,   267,   356,   456,   357,   549,
     550,  1225,   551,   508,   552,   571,   457,   458,   576,   268,
     358,  1114,   577,   578,   579,   580,   581,   509,  1115,   584,
     585,   586,  1162,  1226,   587,  1227,   588,   164,   165,   166,
    1116,   359,   167,   269,   589,   591,   592,   168,   593,   459,
     595,   594,   596,   270,   631,   597,   598,   599,  1117,   600,
    1118,  1119,   601,   602,   603,   604,     2,     3,   605,   360,
       4,   606,   607,   608,   611,  1228,   319,   632,   612,   613,
       5,   271,   272,     6,     7,   614,   615,   617,   618,     8,
     320,   321,   641,   619,   322,   620,   638,   361,   621,   622,
       9,   623,   460,   642,    10,    11,   875,  1163,   624,  1120,
     627,   628,   633,   634,    12,   643,   644,   645,  1121,   646,
     648,   650,   651,  1122,   362,   652,   653,   654,    13,  1123,
     655,   657,   658,  1124,   659,  1125,  1164,   242,    14,    15,
    1126,   660,   662,   663,   665,  1165,  1127,  1229,  1230,   664,
     666,  1166,   667,   323,   324,   325,    16,   898,   326,   581,
     669,   668,   363,   670,   674,  1167,   327,  1168,  1169,   671,
      17,   676,   677,   243,   687,   678,  1170,   328,   329,   683,
    1231,   684,  1171,   692,   693,  1133,   689,   244,   245,   246,
     247,   690,   330,   331,   691,   694,   695,   697,   698,   787,
     788,   789,   790,   791,   699,    18,   700,   248,   701,   704,
     709,   706,  1176,   716,    19,    20,   711,   712,    21,    22,
     713,   332,   717,   718,   876,   877,   878,   879,   880,   719,
     881,   882,   720,   883,   884,   885,  1070,   721,   886,   739,
     887,   888,   740,   889,   722,   890,   723,   891,   892,   741,
     742,   893,   743,   724,   733,   726,  1071,   894,   727,   728,
     730,   746,   333,   745,   747,   734,  1072,   735,   736,   748,
      23,   749,  1073,   750,   751,   899,   900,   901,   902,   903,
     752,   904,   905,   753,   906,   907,   908,  1177,  1074,   909,
     762,   910,   911,   763,   912,   764,   913,   765,   914,   915,
     766,   767,   916,  1134,  1135,  1136,  1137,  1138,   917,  1139,
    1140,   768,  1141,  1142,  1143,  1075,  1178,  1144,    76,  1145,
    1146,   769,  1147,  1076,  1148,  1179,  1149,  1150,   771,   774,
    1151,  1180,   779,   780,   775,   781,  1152,   782,    77,    78,
     783,   784,   785,   786,    79,  1181,   794,  1182,  1183,   795,
     796,   797,   805,   798,   806,   799,  1184,   800,   801,   808,
     802,   803,  1185,  1077,   804,   809,   810,   811,   812,   813,
     814,   817,   821,   820,   824,   827,   825,   826,   831,   828,
    1078,   829,   830,   832,   835,    80,    81,   833,   842,   838,
     839,   834,    82,    83,    84,   836,   837,   843,   840,   841,
     844,   845,   846,   847,   848,   849,   850,   851,   852,   853,
     854,   855,   940,   856,    85,    86,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,    87,    88,   868,
     942,   943,   869,   870,   871,   872,   873,   874,    89,   897,
     920,   944,   921,   922,   923,   924,   925,    90,   926,   927,
     928,   929,   930,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   941,   945,   946,   947,   949,   948,   950,   951,
     954,   953,   955,   956,   952,   959,   972,   973,   960,   975,
     976,   977,   979,   981,   982,   983,  1008,  1010,  1012,  1159,
     970,   971,  1160,   554,  1061,   974,  1203,   302,  1106,   980,
     984,   978,   985,   986,   987,   988,   989,   990,   991,   992,
    1087,   993,   994,   995,   996,   997,   998,  1206,  1003,  1004,
    1005,  1006,  1007,  1242,  1011,  1237,  1009,  1014,  1013,  1102,
    1015,  1021,  1099,  1022,  1023,  1223,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1049,  1050,  1051,  1052,  1053,  1054,  1098,  1055,
    1056,   732,  1236,   610,   715,  1057,  1058,  1204,  1221,  1059,
    1238,  1060,  1068,  1069,   778,  1081,  1082,   703,  1219,  1239,
     738,   773,  1222,   388,   708,  1220,   451,  1196,  1083,  1084,
     637,  1085,  1086,  1090,  1096,  1097,  1101,  1195,  1107,  1108,
    1104,  1130,  1131,  1207,  1132,  1155,  1156,  1157,  1158,   626,
    1161,  1174,  1175,   318,  1205,     0,  1210,  1224,  1234,  1235,
       0,     0,     0,     0,     0,     0,   630,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,   500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   573
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-745))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     607,   608,   306,   307,     1,     8,   220,     1,     1,   218,
     314,   101,     1,   222,   218,   219,     1,     1,     1,     1,
     163,   164,    15,    16,     1,    51,    19,   220,     1,   220,
       1,     1,   220,     1,   218,   218,     1,   218,   222,   222,
      24,   222,     1,   220,     1,   220,     3,    31,     5,     1,
     218,     1,   218,   218,   222,    37,   222,   222,    17,   220,
      17,   218,     1,    36,   218,   222,     1,    61,   222,    51,
      52,    53,    54,    32,     1,    32,   218,    36,    61,    36,
     222,   163,   164,    56,   220,    78,    79,    80,    61,    71,
      83,     1,    89,   137,   138,   399,   400,    24,    91,    56,
     220,    58,    91,   407,    14,   409,    91,    91,   198,   102,
     103,    61,   416,    70,    91,     1,     1,   421,   115,     1,
      91,     6,     7,    91,   117,   118,    91,    12,   432,   433,
      57,   435,    91,   220,    91,    20,   220,   122,   218,   443,
     444,    26,   446,    28,    29,    30,   119,   218,   181,   182,
      35,   222,   122,   146,    89,   114,    41,    42,     1,    44,
      45,    46,   119,   189,    91,    50,    93,    94,   194,   154,
      55,     1,   122,   132,    59,    60,   221,   154,    63,    61,
     115,    66,    67,   154,   154,    95,   154,   221,   220,    74,
     147,   194,     1,     1,   187,   220,    81,    82,   220,    84,
      85,    86,    87,    88,   131,    91,   133,   134,   135,   136,
     220,   218,   122,     1,    99,   222,   220,   174,   137,   138,
     105,   106,   107,   150,   109,   219,   219,   112,   113,    17,
     534,   116,     1,   220,   219,   219,   195,   219,   218,   209,
     122,   209,   127,   221,    32,   216,   219,   174,    36,   219,
     209,   219,    21,    22,   219,   212,   220,   184,    27,   211,
     219,    91,   219,   221,     1,   217,   151,   219,   154,   219,
     155,   220,   211,   158,   159,   160,   161,   162,   217,   122,
     165,   166,    91,    91,   219,   212,   213,    24,     1,  1033,
    1034,  1035,   219,   597,    31,   220,   217,   221,   221,    68,
      69,   605,   606,     9,    10,    11,    75,    76,    77,   219,
     221,   154,   221,   221,   122,   787,   788,   789,   790,   791,
     205,   206,   207,    36,   154,   210,   114,   218,    97,    98,
     215,   222,   221,   219,   219,   123,   124,   221,   221,     1,
     218,   110,   111,    56,   222,   154,   154,   221,    61,   221,
     221,   221,   121,     1,    91,    17,   221,   221,     6,     7,
       1,   130,   221,   221,    12,   221,   209,   221,   156,   221,
      32,   221,    20,    14,    36,   221,   221,   221,    26,   221,
      28,    29,    30,   221,   221,   221,   216,    35,   221,   219,
       1,   218,   221,    41,    42,   101,    44,    45,    46,   221,
     209,   221,    50,   221,   221,   221,   119,    55,   221,   221,
     221,    59,    60,    24,     1,    63,   221,   221,    66,    67,
     221,   209,   221,   221,   221,   221,    74,   221,   221,    91,
      17,   219,   221,    81,    82,   221,    84,    85,    86,    87,
      88,   221,   221,   221,   221,    32,    57,   221,   221,    36,
     219,    99,   114,   221,    95,   221,     4,   105,   106,   107,
     221,   109,   221,   221,   112,   113,   221,   221,   116,   221,
     132,     1,   221,     3,   221,     5,   221,    25,   221,   127,
      91,   122,    93,    94,   218,   221,   221,    17,   221,   221,
     221,   221,    40,   221,   221,   221,   221,  1104,   221,    47,
     221,   221,    32,   151,   221,   221,    36,   155,   120,   221,
     158,   159,   160,   161,   162,   120,    64,   165,   166,   221,
     131,   221,   133,   134,   135,   136,    56,   114,    58,   221,
     221,    40,   221,   195,   221,   221,   123,   124,   120,   150,
      70,    89,   218,   101,   101,   163,   101,   209,    96,   101,
     101,   101,    64,    62,   163,    64,   163,   205,   206,   207,
     108,    91,   210,   174,   101,   163,   163,   215,   218,   156,
     221,   218,   221,   184,   120,   221,   221,   221,   126,   221,
     128,   129,   221,   221,   221,   221,     0,     1,   221,   119,
       4,   221,   221,   221,   218,   104,     1,   218,   221,   221,
      14,   212,   213,    17,    18,   221,   221,   221,   221,    23,
      15,    16,   101,   221,    19,   221,   163,   147,   221,   221,
      34,   221,   209,   163,    38,    39,    51,   139,   221,   177,
     221,   221,   221,   221,    48,   163,   101,   120,   186,   163,
     163,   101,   101,   191,   174,   101,   163,   163,    62,   197,
     163,   120,   163,   201,   101,   203,   168,     1,    72,    73,
     208,   101,   101,   101,   101,   177,   214,   176,   177,   120,
     101,   183,   163,    78,    79,    80,    90,    51,    83,   101,
     221,   163,   212,   163,   163,   197,    91,   199,   200,   221,
     104,   163,   163,    37,   120,   163,   208,   102,   103,   163,
     209,   163,   214,   218,   218,    51,   163,    51,    52,    53,
      54,   163,   117,   118,   163,   221,   221,   221,   221,   141,
     142,   143,   144,   145,   221,   139,   221,    71,   221,   221,
     218,   221,    64,   163,   148,   149,   221,   221,   152,   153,
     221,   146,   218,   220,   169,   170,   171,   172,   173,   120,
     175,   176,   120,   178,   179,   180,    13,   218,   183,   163,
     185,   186,   163,   188,   218,   190,   221,   192,   193,   120,
     163,   196,   163,   221,   218,   221,    33,   202,   221,   221,
     221,   120,   187,   218,   163,   221,    43,   221,   221,   120,
     204,   120,    49,   120,   120,   169,   170,   171,   172,   173,
     120,   175,   176,   120,   178,   179,   180,   139,    65,   183,
     120,   185,   186,   120,   188,   101,   190,   120,   192,   193,
     120,   218,   196,   169,   170,   171,   172,   173,   202,   175,
     176,   218,   178,   179,   180,    92,   168,   183,     1,   185,
     186,   221,   188,   100,   190,   177,   192,   193,   221,   218,
     196,   183,   120,   218,   221,   218,   202,   218,    21,    22,
     218,   218,   218,   218,    27,   197,   218,   199,   200,   218,
     218,   218,   101,   218,   101,   218,   208,   218,   218,   101,
     218,   218,   214,   140,   218,   101,   101,   101,   120,   101,
     101,   101,   120,   218,   120,   120,   163,   221,   101,   120,
     157,   120,   120,   120,   218,    68,    69,   120,   221,   218,
     218,   120,    75,    76,    77,   120,   120,   218,   120,   120,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   120,   218,    97,    98,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   110,   111,   218,
     221,   120,   218,   218,   218,   218,   218,   218,   121,   218,
     218,   101,   218,   218,   218,   218,   218,   130,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   163,   120,   120,   120,   120,   218,   221,   120,
     120,   221,   120,   101,   218,   218,   120,   163,   218,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,  1000,
     218,   218,  1002,   273,   125,   221,   101,    71,   965,   218,
     218,   221,   218,   218,   218,   218,   218,   218,   218,   218,
     125,   218,   218,   218,   218,   218,   218,   120,   218,   218,
     218,   218,   218,  1241,   218,  1214,   221,   218,   221,   221,
     218,   218,   222,   218,   218,  1202,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   167,   218,
     218,   510,  1212,   334,   486,   218,   218,  1099,  1198,   218,
    1216,   218,   218,   218,   567,   218,   218,   461,  1192,  1218,
     524,   559,  1200,   112,   476,  1194,   169,  1067,   218,   218,
     394,   218,   218,   218,   218,   218,   218,  1065,   218,   218,
     221,   218,   218,   221,   218,   218,   218,   218,   218,   364,
     218,   218,   218,    91,   218,    -1,   218,   218,   218,   218,
      -1,    -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,   236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   224,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    72,    73,    90,   104,   139,   148,
     149,   152,   153,   204,   225,   230,   235,   257,   263,   277,
     295,   313,   327,   342,   349,   353,   363,   372,   392,   402,
     408,   412,   422,   483,   500,   218,   219,   220,   220,   296,
     373,   403,   220,   413,   220,   328,   393,   314,   220,   220,
     278,   343,   220,   220,   354,   364,   220,     1,    24,    31,
      91,   258,   259,   260,   261,   262,     1,    21,    22,    27,
      68,    69,    75,    76,    77,    97,    98,   110,   111,   121,
     130,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   220,   220,   220,
       1,    61,   409,   410,   411,   220,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    66,    67,    74,    81,
      82,    84,    85,    86,    87,    88,    99,   105,   106,   107,
     109,   112,   113,   116,   127,   151,   155,   158,   159,   160,
     161,   162,   165,   166,   205,   206,   207,   210,   215,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   476,
     480,   481,   482,   220,   220,   220,     1,   211,   264,   265,
     266,   267,   268,     1,    89,   115,   231,   232,   233,   234,
     220,   220,     1,    37,    51,    52,    53,    54,    71,   501,
     502,   503,   504,   505,   506,   507,   508,     1,    24,    57,
      91,    93,    94,   131,   133,   134,   135,   136,   150,   174,
     184,   212,   213,   236,   237,   238,   239,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     220,   220,     1,    91,   350,   351,   352,   218,   221,   221,
     221,   219,   259,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   219,   485,     1,
      15,    16,    19,    78,    79,    80,    83,    91,   102,   103,
     117,   118,   146,   187,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
       1,     3,     5,    17,    32,    36,    56,    58,    70,    91,
     119,   147,   174,   212,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   387,   388,   389,   390,   391,     1,
      61,   122,   404,   405,   406,   407,   221,   219,   410,     1,
      91,   122,   154,   414,   418,   419,   420,   421,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   477,
     221,   473,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     219,   424,     1,    17,    32,    36,   114,   123,   124,   156,
     209,   329,   330,   331,   332,   333,   334,   335,   339,   340,
     341,     1,   122,   154,   209,   394,   398,   399,   400,   401,
       1,    36,    56,    61,   119,   315,   319,   320,   321,   325,
     326,   218,   221,   219,   265,   217,   218,   221,   221,   219,
     232,     1,    17,    32,    36,    91,   114,   132,   195,   209,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   291,
       1,    14,    95,   122,   344,   345,   346,   347,   348,   221,
     221,   221,   221,   221,   221,   219,   502,   218,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   219,   237,     1,    91,   154,   209,   355,
     356,   357,   358,   359,     1,    91,   154,   365,   366,   367,
     368,   221,   219,   351,   120,   120,   120,   218,   101,   101,
     163,   101,   227,   227,   101,   101,   101,   163,   163,   101,
     227,   163,   163,   218,   218,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   219,
     298,   218,   221,   221,   221,   221,   384,   221,   221,   221,
     221,   221,   221,   221,   221,   219,   375,   221,   221,   219,
     405,   120,   218,   221,   221,   415,   219,   419,   163,   227,
     227,   101,   163,   163,   101,   120,   163,   227,   163,   227,
     101,   101,   101,   163,   163,   163,   227,   120,   163,   101,
     101,   227,   101,   101,   120,   101,   101,   163,   163,   221,
     163,   221,   227,   227,   163,   227,   163,   163,   163,   163,
     164,   163,   164,   163,   163,   227,   227,   120,   227,   163,
     163,   163,   218,   218,   221,   221,   336,   221,   221,   221,
     221,   221,   219,   330,   221,   395,   221,   219,   399,   218,
     316,   221,   221,   221,   219,   320,   163,   218,   220,   120,
     120,   218,   218,   221,   221,   292,   221,   221,   221,   288,
     221,   219,   280,   218,   221,   221,   221,   219,   345,   163,
     163,   120,   163,   163,   227,   218,   120,   163,   120,   120,
     120,   120,   120,   120,   137,   138,   240,   241,   137,   138,
     242,   243,   120,   120,   101,   120,   120,   218,   218,   221,
     360,   221,   219,   356,   218,   221,   369,   219,   366,   120,
     218,   218,   218,   218,   218,   218,   218,   141,   142,   143,
     144,   145,   226,   227,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   101,   101,   227,   101,   101,
     101,   101,   120,   101,   101,   227,   227,   101,   229,   229,
     218,   120,   181,   182,   120,   163,   221,   120,   120,   120,
     120,   101,   120,   120,   120,   218,   120,   120,   218,   218,
     120,   120,   221,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,    51,   169,   170,   171,   172,
     173,   175,   176,   178,   179,   180,   183,   185,   186,   188,
     190,   192,   193,   196,   202,   478,   479,   218,    51,   169,
     170,   171,   172,   173,   175,   176,   178,   179,   180,   183,
     185,   186,   188,   190,   192,   193,   196,   202,   474,   475,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     120,   163,   221,   120,   101,   120,   120,   120,   218,   120,
     221,   120,   218,   221,   120,   120,   101,   323,   324,   218,
     218,     1,    91,   154,   216,   269,   270,   271,   272,   273,
     218,   218,   120,   163,   221,   120,   120,   120,   221,   120,
     218,   120,   120,   120,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     222,   218,   222,   218,   218,   218,   218,   218,   120,   221,
     120,   218,   120,   221,   218,   218,   226,   226,   226,   226,
     226,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,     9,    10,    11,   228,   229,   218,   218,
     218,   218,   218,   218,   218,     8,   194,   385,   386,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   125,   416,   417,   218,   222,   218,   222,   218,   218,
      13,    33,    43,    49,    65,    92,   100,   140,   157,   337,
     338,   218,   218,   218,   218,   218,   218,   125,   396,   397,
     218,    51,   189,   194,   317,   318,   218,   218,   167,   222,
     322,   218,   221,   274,   221,   219,   270,   218,   218,     4,
      25,    40,    47,    64,    89,    96,   108,   126,   128,   129,
     177,   186,   191,   197,   201,   203,   208,   214,   293,   294,
     218,   218,   218,    51,   169,   170,   171,   172,   173,   175,
     176,   178,   179,   180,   183,   185,   186,   188,   190,   192,
     193,   196,   202,   289,   290,   218,   218,   218,   218,   241,
     243,   218,    64,   139,   168,   177,   183,   197,   199,   200,
     208,   214,   361,   362,   218,   218,    64,   139,   168,   177,
     183,   197,   199,   200,   208,   214,   370,   371,   228,   228,
     228,   218,   222,   218,   222,   479,   475,   218,   222,   218,
     222,   218,   222,   101,   324,   218,   120,   221,   198,   229,
     218,   218,   222,   218,   222,   218,   222,   218,   222,   386,
     417,   338,   397,   318,   218,    40,    62,    64,   104,   176,
     177,   209,   275,   276,   218,   218,   294,   290,   362,   371,
     218,   222,   276
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 26:
/* Line 1787 of yacc.c  */
#line 362 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 364 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 368 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 372 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 376 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 380 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 384 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 389 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 390 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 391 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 392 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 393 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 438 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 444 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 453 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 459 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 467 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 506 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 1)
  {
    BIO *file;

    if (ServerInfo.rsa_private_key)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;
    }

    if (ServerInfo.rsa_private_key_file)
    {
      MyFree(ServerInfo.rsa_private_key_file);
      ServerInfo.rsa_private_key_file = NULL;
    }

    DupString(ServerInfo.rsa_private_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 565 "conf_parser.y"
    {
/* TBD - XXX: error reporting */
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) < 128)
          ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 593 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 601 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 616 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 631 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 640 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 663 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 691 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 721 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    recalc_fdlimit(NULL);

    if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 744 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 759 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 768 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 777 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 795 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 801 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 806 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 818 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 823 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 826 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 831 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 838 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    SetConfEncrypted(yy_aconf); /* Yes, the default is encrypted */
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);

    /* Now, make sure there is a copy of the "base" given oper
     * block in each of the collected copies
     */

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = make_conf_item(OPER_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_aconf->user, yy_tmp->user);
      else
	DupString(new_aconf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_aconf->host, yy_tmp->host);
      else
	DupString(new_aconf->host, "*");

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->addr,
                                     &new_aconf->bits);

      conf_add_class_to_conf(new_conf, class_name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->port = yy_aconf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_aconf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_aconf->rsa_public_key_file,
		  yy_aconf->rsa_public_key_file);

        file = BIO_new_file(yy_aconf->rsa_public_key_file, "r");
        new_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key)
	  && yy_tmp->host)
#else
      if (yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
      {
        conf_add_class_to_conf(new_conf, class_name);
	if (yy_tmp->name != NULL)
	  DupString(new_conf->name, yy_tmp->name);
      }

      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    yy_conf = NULL;
    yy_aconf = NULL;


    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 975 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->addr,
                                    &yy_aconf->bits);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1033 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1044 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file;

    if (yy_aconf->rsa_public_key != NULL)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file != NULL)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
}
    break;

  case 147:
/* Line 1787 of yacc.c  */
#line 1086 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1106 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1110 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1126 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1130 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1134 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1138 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1150 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1154 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1158 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1166 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1215 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1239 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1243 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1263 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, NULL, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        int user_count = 0;

        rebuild_cidr_class(cconf, yy_class);

        class = map_to_conf(cconf);

        user_count = class->curr_user_count;
        memcpy(class, yy_class, sizeof(*class));
        class->curr_user_count = user_count;
        class->active = 1;

        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
        yy_class->active = 1;
      }
    }

    yy_class_name = NULL;
  }
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1347 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1353 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1359 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1365 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1371 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1377 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1383 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1389 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1395 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1401 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1420 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1445 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1455 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1469 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), listener_address, listener_flags);
  }
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, listener_address, listener_flags);
  }
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1508 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1517 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1529 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1541 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->user && yy_aconf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = map_to_conf(new_conf);

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->flags = yy_aconf->flags;
      new_aconf->port  = yy_aconf->port;

      DupString(new_aconf->user, yy_tmp->user);
      collapse(new_aconf->user);

      DupString(new_aconf->host, yy_tmp->host);
      collapse(new_aconf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_aconf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1603 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1638 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1651 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1660 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1671 "conf_parser.y"
    {
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1680 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1684 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1688 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1708 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1714 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1733 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1743 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1756 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1763 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1775 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1784 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = "No reason";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1817 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      yy_conf = make_conf_item(SERVICE_TYPE);
      DupString(yy_conf->name, yylval.string);
    }
  }
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1832 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 1840 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    DupString(yy_match_item->user, userbuf);
    DupString(yy_match_item->host, hostbuf);
  }
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1889 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1897 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1921 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1954 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1960 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1971 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1975 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1979 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 1995 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2003 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = map_to_conf(yy_conf);

    /* defaults */
    yy_aconf->port = PORTNUM;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 2027 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->host && yy_aconf->passwd && yy_aconf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
        delete_conf_item(yy_conf);
    }
    else
    {
      if (yy_conf->name != NULL)
      {
        if (yy_aconf->host == NULL)
          yyerror("Ignoring connect block -- missing host");
        else if (!yy_aconf->passwd || !yy_aconf->spasswd)
          yyerror("Ignoring connect block -- missing password");
      }

      /* XXX
       * This fixes a try_connections() core (caused by invalid class_ptr
       * pointers) reported by metalrock. That's an ugly fix, but there
       * is currently no better way. The entire config subsystem needs an
       * rewrite ASAP. make_conf_item() shouldn't really add things onto
       * a doubly linked list immediately without any sanity checks!  -Michael
       */
      delete_conf_item(yy_conf);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 2071 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 2080 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 2089 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->bind, res->ai_addr, res->ai_addrlen);
      yy_aconf->bind.ss.ss_family = res->ai_family;
      yy_aconf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 2115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 2133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 2151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2161 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 2169 "conf_parser.y"
    {
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2226 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->cipher_list);
    DupString(yy_aconf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_user = NULL;
        void *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
               errptr);
          break;
        }

        yy_aconf = map_to_conf(make_conf_item(RKLINE_TYPE));
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
        break;
#endif
      }
      else
      {
        find_and_delete_temporary(userbuf, hostbuf, CONF_KLINE);

        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KLINE, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 2309 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2314 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2323 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);
  }
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2342 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2351 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2355 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      find_and_delete_temporary(NULL, hostbuf, CONF_DLINE);

      yy_aconf = map_to_conf(make_conf_item(DLINE_TYPE));
      DupString(yy_aconf->host, hostbuf);

      if (reasonbuf[0])
        DupString(yy_aconf->reason, reasonbuf);
      else
        DupString(yy_aconf->reason, "No reason");
      add_conf_by_address(CONF_DLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 2379 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2385 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2399 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_aconf = map_to_conf(make_conf_item(EXEMPTDLINE_TYPE));
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: no PCRE support");
        break;
#endif
      }
      else
        yy_conf = make_conf_item(XLINE_TYPE);

      yy_match_item = map_to_conf(yy_conf);
      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_match_item->reason, reasonbuf);
      else
        DupString(yy_match_item->reason, "No reason");
    }
  }
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2464 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2484 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 2529 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 2534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2540 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2587 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2592 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2597 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2602 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2607 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2612 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2617 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2622 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2633 "conf_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2658 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2686 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2750 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2807 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2875 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2887 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2890 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2893 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2905 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2917 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2923 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2929 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2939 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1787 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 605:
/* Line 1787 of yacc.c  */
#line 2972 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2977 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 2982 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2987 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 2992 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 2997 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3007 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3012 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3017 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3022 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3027 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3032 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 3056 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 3062 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 3071 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[(3) - (4)].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[(3) - (4)].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 3085 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 3091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6897 "conf_parser.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


