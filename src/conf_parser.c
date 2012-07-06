/* A Bison parser, made by GNU Bison 2.5.1.  */

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
#define YYBISON_VERSION "2.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 157 "conf_parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ACTION = 259,
     ADMIN = 260,
     AFTYPE = 261,
     T_ALLOW = 262,
     ANTI_NICK_FLOOD = 263,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 264,
     AUTOCONN = 265,
     T_BLOCK = 266,
     BURST_AWAY = 267,
     BYTES = 268,
     KBYTES = 269,
     MBYTES = 270,
     GBYTES = 271,
     TBYTES = 272,
     CALLER_ID_WAIT = 273,
     CAN_FLOOD = 274,
     CHANNEL = 275,
     CIDR_BITLEN_IPV4 = 276,
     CIDR_BITLEN_IPV6 = 277,
     CLASS = 278,
     CONNECT = 279,
     CONNECTFREQ = 280,
     DEFAULT_FLOODCOUNT = 281,
     DEFAULT_SPLIT_SERVER_COUNT = 282,
     DEFAULT_SPLIT_USER_COUNT = 283,
     DENY = 284,
     DESCRIPTION = 285,
     DIE = 286,
     DISABLE_AUTH = 287,
     DISABLE_FAKE_CHANNELS = 288,
     DISABLE_HIDDEN = 289,
     DISABLE_LOCAL_CHANNELS = 290,
     DISABLE_REMOTE_COMMANDS = 291,
     DOTS_IN_IDENT = 292,
     DURATION = 293,
     EGDPOOL_PATH = 294,
     EMAIL = 295,
     ENABLE = 296,
     ENCRYPTED = 297,
     EXCEED_LIMIT = 298,
     EXEMPT = 299,
     FAILED_OPER_NOTICE = 300,
     IRCD_FLAGS = 301,
     FLATTEN_LINKS = 302,
     GECOS = 303,
     GENERAL = 304,
     GLINE = 305,
     GLINE_DURATION = 306,
     GLINE_ENABLE = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
     GLINE_REQUEST_DURATION = 310,
     GLINE_MIN_CIDR = 311,
     GLINE_MIN_CIDR6 = 312,
     GLOBAL_KILL = 313,
     IRCD_AUTH = 314,
     NEED_IDENT = 315,
     HAVENT_READ_CONF = 316,
     HIDDEN = 317,
     HIDDEN_NAME = 318,
     HIDE_SERVER_IPS = 319,
     HIDE_SERVERS = 320,
     HIDE_SPOOF_IPS = 321,
     HOST = 322,
     HUB = 323,
     HUB_MASK = 324,
     IGNORE_BOGUS_TS = 325,
     INVISIBLE_ON_CONNECT = 326,
     IP = 327,
     KILL = 328,
     KILL_CHASE_TIME_LIMIT = 329,
     KLINE = 330,
     KLINE_EXEMPT = 331,
     KLINE_REASON = 332,
     KLINE_WITH_REASON = 333,
     KNOCK_DELAY = 334,
     KNOCK_DELAY_CHANNEL = 335,
     LEAF_MASK = 336,
     LINKS_DELAY = 337,
     LISTEN = 338,
     T_LOG = 339,
     MAX_ACCEPT = 340,
     MAX_BANS = 341,
     MAX_CHANS_PER_OPER = 342,
     MAX_CHANS_PER_USER = 343,
     MAX_GLOBAL = 344,
     MAX_IDENT = 345,
     MAX_LOCAL = 346,
     MAX_NICK_CHANGES = 347,
     MAX_NICK_TIME = 348,
     MAX_NUMBER = 349,
     MAX_TARGETS = 350,
     MAX_WATCH = 351,
     MESSAGE_LOCALE = 352,
     MIN_NONWILDCARD = 353,
     MIN_NONWILDCARD_SIMPLE = 354,
     MODULE = 355,
     MODULES = 356,
     NAME = 357,
     NEED_PASSWORD = 358,
     NETWORK_DESC = 359,
     NETWORK_NAME = 360,
     NICK = 361,
     NICK_CHANGES = 362,
     NO_CREATE_ON_SPLIT = 363,
     NO_JOIN_ON_SPLIT = 364,
     NO_OPER_FLOOD = 365,
     NO_TILDE = 366,
     NUMBER = 367,
     NUMBER_PER_IDENT = 368,
     NUMBER_PER_CIDR = 369,
     NUMBER_PER_IP = 370,
     NUMBER_PER_IP_GLOBAL = 371,
     OPERATOR = 372,
     OPERS_BYPASS_CALLERID = 373,
     OPER_ONLY_UMODES = 374,
     OPER_PASS_RESV = 375,
     OPER_SPY_T = 376,
     OPER_UMODES = 377,
     JOIN_FLOOD_COUNT = 378,
     JOIN_FLOOD_TIME = 379,
     PACE_WAIT = 380,
     PACE_WAIT_SIMPLE = 381,
     PASSWORD = 382,
     PATH = 383,
     PING_COOKIE = 384,
     PING_TIME = 385,
     PING_WARNING = 386,
     PORT = 387,
     QSTRING = 388,
     QUIET_ON_BAN = 389,
     REASON = 390,
     REDIRPORT = 391,
     REDIRSERV = 392,
     REGEX_T = 393,
     REHASH = 394,
     TREJECT_HOLD_TIME = 395,
     REMOTE = 396,
     REMOTEBAN = 397,
     RESTRICT_CHANNELS = 398,
     RESTRICTED = 399,
     RSA_PRIVATE_KEY_FILE = 400,
     RSA_PUBLIC_KEY_FILE = 401,
     SSL_CERTIFICATE_FILE = 402,
     SSL_DH_PARAM_FILE = 403,
     T_SSL_CLIENT_METHOD = 404,
     T_SSL_SERVER_METHOD = 405,
     T_SSLV3 = 406,
     T_TLSV1 = 407,
     RESV = 408,
     RESV_EXEMPT = 409,
     SECONDS = 410,
     MINUTES = 411,
     HOURS = 412,
     DAYS = 413,
     WEEKS = 414,
     SENDQ = 415,
     SEND_PASSWORD = 416,
     SERVERHIDE = 417,
     SERVERINFO = 418,
     IRCD_SID = 419,
     TKLINE_EXPIRE_NOTICES = 420,
     T_SHARED = 421,
     T_CLUSTER = 422,
     TYPE = 423,
     SHORT_MOTD = 424,
     SILENT = 425,
     SPOOF = 426,
     SPOOF_NOTICE = 427,
     STATS_E_DISABLED = 428,
     STATS_I_OPER_ONLY = 429,
     STATS_K_OPER_ONLY = 430,
     STATS_O_OPER_ONLY = 431,
     STATS_P_OPER_ONLY = 432,
     TBOOL = 433,
     TMASKED = 434,
     T_REJECT = 435,
     TS_MAX_DELTA = 436,
     TS_WARN_DELTA = 437,
     TWODOTS = 438,
     T_ALL = 439,
     T_BOTS = 440,
     T_SOFTCALLERID = 441,
     T_CALLERID = 442,
     T_CCONN = 443,
     T_CCONN_FULL = 444,
     T_SSL_CIPHER_LIST = 445,
     T_CLIENT_FLOOD = 446,
     T_DEAF = 447,
     T_DEBUG = 448,
     T_DLINE = 449,
     T_DRONE = 450,
     T_EXTERNAL = 451,
     T_FULL = 452,
     T_INVISIBLE = 453,
     T_IPV4 = 454,
     T_IPV6 = 455,
     T_LOCOPS = 456,
     T_MAX_CLIENTS = 457,
     T_NCHANGE = 458,
     T_OPERWALL = 459,
     T_REJ = 460,
     T_SERVER = 461,
     T_SERVNOTICE = 462,
     T_SKILL = 463,
     T_SPY = 464,
     T_SSL = 465,
     T_UMODES = 466,
     T_UNAUTH = 467,
     T_UNDLINE = 468,
     T_UNLIMITED = 469,
     T_UNRESV = 470,
     T_UNXLINE = 471,
     T_GLOBOPS = 472,
     T_WALLOP = 473,
     T_RESTART = 474,
     T_SERVICE = 475,
     T_SERVICES_NAME = 476,
     THROTTLE_TIME = 477,
     TOPICBURST = 478,
     TRUE_NO_OPER_FLOOD = 479,
     TKLINE = 480,
     TXLINE = 481,
     TRESV = 482,
     UNKLINE = 483,
     USER = 484,
     USE_EGD = 485,
     USE_EXCEPT = 486,
     USE_INVEX = 487,
     USE_KNOCK = 488,
     USE_LOGGING = 489,
     USE_WHOIS_ACTUALLY = 490,
     VHOST = 491,
     VHOST6 = 492,
     XLINE = 493,
     WARN = 494,
     WARN_NO_NLINE = 495,
     T_SIZE = 496,
     T_FILE = 497
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ACTION 259
#define ADMIN 260
#define AFTYPE 261
#define T_ALLOW 262
#define ANTI_NICK_FLOOD 263
#define ANTI_SPAM_EXIT_MESSAGE_TIME 264
#define AUTOCONN 265
#define T_BLOCK 266
#define BURST_AWAY 267
#define BYTES 268
#define KBYTES 269
#define MBYTES 270
#define GBYTES 271
#define TBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CLASS 278
#define CONNECT 279
#define CONNECTFREQ 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_HIDDEN 289
#define DISABLE_LOCAL_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DOTS_IN_IDENT 292
#define DURATION 293
#define EGDPOOL_PATH 294
#define EMAIL 295
#define ENABLE 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define FAILED_OPER_NOTICE 300
#define IRCD_FLAGS 301
#define FLATTEN_LINKS 302
#define GECOS 303
#define GENERAL 304
#define GLINE 305
#define GLINE_DURATION 306
#define GLINE_ENABLE 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
#define GLINE_REQUEST_DURATION 310
#define GLINE_MIN_CIDR 311
#define GLINE_MIN_CIDR6 312
#define GLOBAL_KILL 313
#define IRCD_AUTH 314
#define NEED_IDENT 315
#define HAVENT_READ_CONF 316
#define HIDDEN 317
#define HIDDEN_NAME 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SPOOF_IPS 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define IGNORE_BOGUS_TS 325
#define INVISIBLE_ON_CONNECT 326
#define IP 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_REASON 332
#define KLINE_WITH_REASON 333
#define KNOCK_DELAY 334
#define KNOCK_DELAY_CHANNEL 335
#define LEAF_MASK 336
#define LINKS_DELAY 337
#define LISTEN 338
#define T_LOG 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_CHANS_PER_OPER 342
#define MAX_CHANS_PER_USER 343
#define MAX_GLOBAL 344
#define MAX_IDENT 345
#define MAX_LOCAL 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_WATCH 351
#define MESSAGE_LOCALE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define NAME 357
#define NEED_PASSWORD 358
#define NETWORK_DESC 359
#define NETWORK_NAME 360
#define NICK 361
#define NICK_CHANGES 362
#define NO_CREATE_ON_SPLIT 363
#define NO_JOIN_ON_SPLIT 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER 367
#define NUMBER_PER_IDENT 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define NUMBER_PER_IP_GLOBAL 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define OPER_ONLY_UMODES 374
#define OPER_PASS_RESV 375
#define OPER_SPY_T 376
#define OPER_UMODES 377
#define JOIN_FLOOD_COUNT 378
#define JOIN_FLOOD_TIME 379
#define PACE_WAIT 380
#define PACE_WAIT_SIMPLE 381
#define PASSWORD 382
#define PATH 383
#define PING_COOKIE 384
#define PING_TIME 385
#define PING_WARNING 386
#define PORT 387
#define QSTRING 388
#define QUIET_ON_BAN 389
#define REASON 390
#define REDIRPORT 391
#define REDIRSERV 392
#define REGEX_T 393
#define REHASH 394
#define TREJECT_HOLD_TIME 395
#define REMOTE 396
#define REMOTEBAN 397
#define RESTRICT_CHANNELS 398
#define RESTRICTED 399
#define RSA_PRIVATE_KEY_FILE 400
#define RSA_PUBLIC_KEY_FILE 401
#define SSL_CERTIFICATE_FILE 402
#define SSL_DH_PARAM_FILE 403
#define T_SSL_CLIENT_METHOD 404
#define T_SSL_SERVER_METHOD 405
#define T_SSLV3 406
#define T_TLSV1 407
#define RESV 408
#define RESV_EXEMPT 409
#define SECONDS 410
#define MINUTES 411
#define HOURS 412
#define DAYS 413
#define WEEKS 414
#define SENDQ 415
#define SEND_PASSWORD 416
#define SERVERHIDE 417
#define SERVERINFO 418
#define IRCD_SID 419
#define TKLINE_EXPIRE_NOTICES 420
#define T_SHARED 421
#define T_CLUSTER 422
#define TYPE 423
#define SHORT_MOTD 424
#define SILENT 425
#define SPOOF 426
#define SPOOF_NOTICE 427
#define STATS_E_DISABLED 428
#define STATS_I_OPER_ONLY 429
#define STATS_K_OPER_ONLY 430
#define STATS_O_OPER_ONLY 431
#define STATS_P_OPER_ONLY 432
#define TBOOL 433
#define TMASKED 434
#define T_REJECT 435
#define TS_MAX_DELTA 436
#define TS_WARN_DELTA 437
#define TWODOTS 438
#define T_ALL 439
#define T_BOTS 440
#define T_SOFTCALLERID 441
#define T_CALLERID 442
#define T_CCONN 443
#define T_CCONN_FULL 444
#define T_SSL_CIPHER_LIST 445
#define T_CLIENT_FLOOD 446
#define T_DEAF 447
#define T_DEBUG 448
#define T_DLINE 449
#define T_DRONE 450
#define T_EXTERNAL 451
#define T_FULL 452
#define T_INVISIBLE 453
#define T_IPV4 454
#define T_IPV6 455
#define T_LOCOPS 456
#define T_MAX_CLIENTS 457
#define T_NCHANGE 458
#define T_OPERWALL 459
#define T_REJ 460
#define T_SERVER 461
#define T_SERVNOTICE 462
#define T_SKILL 463
#define T_SPY 464
#define T_SSL 465
#define T_UMODES 466
#define T_UNAUTH 467
#define T_UNDLINE 468
#define T_UNLIMITED 469
#define T_UNRESV 470
#define T_UNXLINE 471
#define T_GLOBOPS 472
#define T_WALLOP 473
#define T_RESTART 474
#define T_SERVICE 475
#define T_SERVICES_NAME 476
#define THROTTLE_TIME 477
#define TOPICBURST 478
#define TRUE_NO_OPER_FLOOD 479
#define TKLINE 480
#define TXLINE 481
#define TRESV 482
#define UNKLINE 483
#define USER 484
#define USE_EGD 485
#define USE_EXCEPT 486
#define USE_INVEX 487
#define USE_KNOCK 488
#define USE_LOGGING 489
#define USE_WHOIS_ACTUALLY 490
#define VHOST 491
#define VHOST6 492
#define XLINE 493
#define WARN 494
#define WARN_NO_NLINE 495
#define T_SIZE 496
#define T_FILE 497




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 295 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 295 of yacc.c  */
#line 692 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 345 of yacc.c  */
#line 704 "conf_parser.c"

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
#define YYLAST   1308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  646
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   247,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   243,
       2,   246,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,     2,   244,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242
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
     542,   544,   546,   548,   550,   551,   558,   561,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   592,   597,   602,   607,   612,   617,   622,   627,
     632,   637,   642,   647,   652,   657,   658,   665,   666,   672,
     676,   678,   680,   682,   684,   687,   689,   691,   693,   695,
     697,   700,   701,   707,   711,   713,   715,   719,   724,   729,
     730,   737,   740,   742,   744,   746,   748,   750,   752,   754,
     756,   758,   761,   766,   771,   776,   781,   782,   788,   792,
     794,   796,   798,   800,   802,   804,   806,   808,   810,   812,
     817,   822,   827,   828,   835,   838,   840,   842,   844,   846,
     849,   854,   859,   864,   870,   873,   875,   877,   879,   884,
     885,   892,   895,   897,   899,   901,   903,   906,   911,   916,
     917,   923,   927,   929,   931,   933,   935,   937,   939,   941,
     943,   945,   947,   949,   950,   957,   960,   962,   964,   966,
     969,   974,   975,   981,   985,   987,   989,   991,   993,   995,
     997,   999,  1001,  1003,  1005,  1007,  1008,  1015,  1018,  1020,
    1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
    1042,  1044,  1046,  1049,  1054,  1059,  1064,  1069,  1074,  1079,
    1084,  1089,  1090,  1096,  1100,  1102,  1104,  1106,  1108,  1110,
    1115,  1120,  1125,  1130,  1135,  1136,  1143,  1144,  1150,  1154,
    1156,  1158,  1161,  1163,  1165,  1167,  1169,  1171,  1176,  1181,
    1182,  1189,  1192,  1194,  1196,  1198,  1200,  1205,  1210,  1216,
    1219,  1221,  1223,  1225,  1230,  1231,  1238,  1239,  1245,  1249,
    1251,  1253,  1256,  1258,  1260,  1262,  1264,  1266,  1271,  1276,
    1282,  1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,
    1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,
    1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,
    1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,
    1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1402,  1407,
    1412,  1417,  1422,  1427,  1432,  1437,  1442,  1447,  1452,  1457,
    1462,  1467,  1472,  1477,  1482,  1487,  1492,  1497,  1502,  1507,
    1512,  1517,  1522,  1527,  1532,  1537,  1542,  1547,  1552,  1557,
    1562,  1567,  1572,  1577,  1582,  1587,  1592,  1597,  1602,  1607,
    1612,  1617,  1622,  1627,  1632,  1637,  1642,  1647,  1648,  1654,
    1658,  1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,
    1698,  1700,  1701,  1707,  1711,  1713,  1715,  1717,  1719,  1721,
    1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,
    1743,  1745,  1747,  1749,  1751,  1753,  1758,  1763,  1768,  1773,
    1779,  1782,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,
    1820,  1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,
    1867,  1872,  1877,  1882,  1887,  1892,  1897,  1902,  1907,  1912,
    1918,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1944,  1949,  1954,  1959,  1964,  1969
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     249,     0,    -1,    -1,   249,   250,    -1,   282,    -1,   288,
      -1,   302,    -1,   509,    -1,   320,    -1,   337,    -1,   351,
      -1,   260,    -1,   530,    -1,   366,    -1,   373,    -1,   377,
      -1,   387,    -1,   396,    -1,   416,    -1,   426,    -1,   432,
      -1,   446,    -1,   436,    -1,   255,    -1,     1,   243,    -1,
       1,   244,    -1,    -1,   252,    -1,   112,   251,    -1,   112,
     155,   251,    -1,   112,   156,   251,    -1,   112,   157,   251,
      -1,   112,   158,   251,    -1,   112,   159,   251,    -1,    -1,
     254,    -1,   112,   253,    -1,   112,    13,   253,    -1,   112,
      14,   253,    -1,   112,    15,   253,    -1,   101,   245,   256,
     244,   243,    -1,   256,   257,    -1,   257,    -1,   258,    -1,
     259,    -1,     1,   243,    -1,   100,   246,   133,   243,    -1,
     128,   246,   133,   243,    -1,   163,   245,   261,   244,   243,
      -1,   261,   262,    -1,   262,    -1,   273,    -1,   278,    -1,
     281,    -1,   275,    -1,   276,    -1,   277,    -1,   280,    -1,
     271,    -1,   270,    -1,   279,    -1,   274,    -1,   269,    -1,
     263,    -1,   264,    -1,   272,    -1,     1,   243,    -1,   149,
     246,   265,   243,    -1,   150,   246,   267,   243,    -1,   265,
     247,   266,    -1,   266,    -1,   151,    -1,   152,    -1,   267,
     247,   268,    -1,   268,    -1,   151,    -1,   152,    -1,   147,
     246,   133,   243,    -1,   145,   246,   133,   243,    -1,   148,
     246,   133,   243,    -1,   190,   246,   133,   243,    -1,   102,
     246,   133,   243,    -1,   164,   246,   133,   243,    -1,    30,
     246,   133,   243,    -1,   105,   246,   133,   243,    -1,   104,
     246,   133,   243,    -1,   236,   246,   133,   243,    -1,   237,
     246,   133,   243,    -1,   202,   246,   112,   243,    -1,    68,
     246,   178,   243,    -1,     5,   245,   283,   244,   243,    -1,
     283,   284,    -1,   284,    -1,   285,    -1,   287,    -1,   286,
      -1,     1,   243,    -1,   102,   246,   133,   243,    -1,    40,
     246,   133,   243,    -1,    30,   246,   133,   243,    -1,    84,
     245,   289,   244,   243,    -1,   289,   290,    -1,   290,    -1,
     291,    -1,   292,    -1,     1,   243,    -1,   234,   246,   178,
     243,    -1,    -1,   293,   242,   245,   294,   244,   243,    -1,
     294,   295,    -1,   295,    -1,   296,    -1,   298,    -1,   297,
      -1,     1,   243,    -1,   102,   246,   133,   243,    -1,   241,
     246,   254,   243,    -1,   241,   246,   214,   243,    -1,    -1,
     168,   299,   246,   300,   243,    -1,   300,   247,   301,    -1,
     301,    -1,   229,    -1,   117,    -1,    50,    -1,   194,    -1,
      75,    -1,    73,    -1,   193,    -1,    -1,   117,   303,   245,
     304,   244,   243,    -1,   304,   305,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   312,    -1,   311,    -1,   309,
      -1,   310,    -1,   316,    -1,     1,   243,    -1,   102,   246,
     133,   243,    -1,   229,   246,   133,   243,    -1,   127,   246,
     133,   243,    -1,    42,   246,   178,   243,    -1,   146,   246,
     133,   243,    -1,    23,   246,   133,   243,    -1,    -1,   211,
     313,   246,   314,   243,    -1,   314,   247,   315,    -1,   315,
      -1,   185,    -1,   188,    -1,   189,    -1,   192,    -1,   193,
      -1,   197,    -1,    62,    -1,   208,    -1,   203,    -1,   205,
      -1,   212,    -1,   209,    -1,   196,    -1,   204,    -1,   207,
      -1,   198,    -1,   218,    -1,   186,    -1,   187,    -1,   201,
      -1,    -1,    46,   317,   246,   318,   243,    -1,   318,   247,
     319,    -1,   319,    -1,    58,    -1,   141,    -1,    75,    -1,
     228,    -1,   194,    -1,   213,    -1,   238,    -1,    50,    -1,
      31,    -1,   219,    -1,   139,    -1,     5,    -1,   107,    -1,
     204,    -1,   217,    -1,   121,    -1,   142,    -1,   100,    -1,
      -1,    23,   321,   245,   322,   244,   243,    -1,   322,   323,
      -1,   323,    -1,   324,    -1,   334,    -1,   335,    -1,   325,
      -1,   326,    -1,   336,    -1,   327,    -1,   328,    -1,   329,
      -1,   330,    -1,   331,    -1,   332,    -1,   333,    -1,     1,
     243,    -1,   102,   246,   133,   243,    -1,   130,   246,   252,
     243,    -1,   131,   246,   252,   243,    -1,   115,   246,   112,
     243,    -1,    25,   246,   252,   243,    -1,    94,   246,   112,
     243,    -1,    89,   246,   112,   243,    -1,    91,   246,   112,
     243,    -1,    90,   246,   112,   243,    -1,   160,   246,   254,
     243,    -1,    21,   246,   112,   243,    -1,    22,   246,   112,
     243,    -1,   114,   246,   112,   243,    -1,    -1,    83,   338,
     245,   343,   244,   243,    -1,    -1,    46,   340,   246,   341,
     243,    -1,   341,   247,   342,    -1,   342,    -1,   210,    -1,
      62,    -1,   206,    -1,   343,   344,    -1,   344,    -1,   345,
      -1,   339,    -1,   349,    -1,   350,    -1,     1,   243,    -1,
      -1,   132,   246,   347,   346,   243,    -1,   347,   247,   348,
      -1,   348,    -1,   112,    -1,   112,   183,   112,    -1,    72,
     246,   133,   243,    -1,    67,   246,   133,   243,    -1,    -1,
      59,   352,   245,   353,   244,   243,    -1,   353,   354,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   359,    -1,
     363,    -1,   364,    -1,   365,    -1,   358,    -1,     1,   243,
      -1,   229,   246,   133,   243,    -1,   127,   246,   133,   243,
      -1,    23,   246,   133,   243,    -1,    42,   246,   178,   243,
      -1,    -1,    46,   360,   246,   361,   243,    -1,   361,   247,
     362,    -1,   362,    -1,   172,    -1,    43,    -1,    76,    -1,
      60,    -1,    19,    -1,   111,    -1,    53,    -1,   154,    -1,
     103,    -1,   171,   246,   133,   243,    -1,   137,   246,   133,
     243,    -1,   136,   246,   112,   243,    -1,    -1,   153,   367,
     245,   368,   244,   243,    -1,   368,   369,    -1,   369,    -1,
     370,    -1,   371,    -1,   372,    -1,     1,   243,    -1,   135,
     246,   133,   243,    -1,    20,   246,   133,   243,    -1,   106,
     246,   133,   243,    -1,   220,   245,   374,   244,   243,    -1,
     374,   375,    -1,   375,    -1,   376,    -1,     1,    -1,   102,
     246,   133,   243,    -1,    -1,   166,   378,   245,   379,   244,
     243,    -1,   379,   380,    -1,   380,    -1,   381,    -1,   382,
      -1,   383,    -1,     1,   243,    -1,   102,   246,   133,   243,
      -1,   229,   246,   133,   243,    -1,    -1,   168,   384,   246,
     385,   243,    -1,   385,   247,   386,    -1,   386,    -1,    75,
      -1,   228,    -1,   194,    -1,   213,    -1,   238,    -1,   216,
      -1,   153,    -1,   215,    -1,   201,    -1,   184,    -1,    -1,
     167,   388,   245,   389,   244,   243,    -1,   389,   390,    -1,
     390,    -1,   391,    -1,   392,    -1,     1,   243,    -1,   102,
     246,   133,   243,    -1,    -1,   168,   393,   246,   394,   243,
      -1,   394,   247,   395,    -1,   395,    -1,    75,    -1,   228,
      -1,   194,    -1,   213,    -1,   238,    -1,   216,    -1,   153,
      -1,   215,    -1,   201,    -1,   184,    -1,    -1,    24,   397,
     245,   398,   244,   243,    -1,   398,   399,    -1,   399,    -1,
     400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     406,    -1,   405,    -1,   415,    -1,   407,    -1,   412,    -1,
     413,    -1,   414,    -1,   411,    -1,     1,   243,    -1,   102,
     246,   133,   243,    -1,    67,   246,   133,   243,    -1,   236,
     246,   133,   243,    -1,   161,   246,   133,   243,    -1,     3,
     246,   133,   243,    -1,   132,   246,   112,   243,    -1,     6,
     246,   199,   243,    -1,     6,   246,   200,   243,    -1,    -1,
      46,   408,   246,   409,   243,    -1,   409,   247,   410,    -1,
     410,    -1,    10,    -1,    12,    -1,   223,    -1,   210,    -1,
      42,   246,   178,   243,    -1,    69,   246,   133,   243,    -1,
      81,   246,   133,   243,    -1,    23,   246,   133,   243,    -1,
     190,   246,   133,   243,    -1,    -1,    73,   417,   245,   422,
     244,   243,    -1,    -1,   168,   419,   246,   420,   243,    -1,
     420,   247,   421,    -1,   421,    -1,   138,    -1,   422,   423,
      -1,   423,    -1,   424,    -1,   425,    -1,   418,    -1,     1,
      -1,   229,   246,   133,   243,    -1,   135,   246,   133,   243,
      -1,    -1,    29,   427,   245,   428,   244,   243,    -1,   428,
     429,    -1,   429,    -1,   430,    -1,   431,    -1,     1,    -1,
      72,   246,   133,   243,    -1,   135,   246,   133,   243,    -1,
      44,   245,   433,   244,   243,    -1,   433,   434,    -1,   434,
      -1,   435,    -1,     1,    -1,    72,   246,   133,   243,    -1,
      -1,    48,   437,   245,   442,   244,   243,    -1,    -1,   168,
     439,   246,   440,   243,    -1,   440,   247,   441,    -1,   441,
      -1,   138,    -1,   442,   443,    -1,   443,    -1,   444,    -1,
     445,    -1,   438,    -1,     1,    -1,   102,   246,   133,   243,
      -1,   135,   246,   133,   243,    -1,    49,   245,   447,   244,
     243,    -1,   447,   448,    -1,   448,    -1,   459,    -1,   460,
      -1,   462,    -1,   463,    -1,   464,    -1,   465,    -1,   466,
      -1,   467,    -1,   468,    -1,   469,    -1,   458,    -1,   471,
      -1,   472,    -1,   473,    -1,   474,    -1,   489,    -1,   476,
      -1,   478,    -1,   480,    -1,   479,    -1,   483,    -1,   477,
      -1,   484,    -1,   485,    -1,   486,    -1,   487,    -1,   488,
      -1,   501,    -1,   490,    -1,   491,    -1,   492,    -1,   497,
      -1,   481,    -1,   482,    -1,   507,    -1,   505,    -1,   506,
      -1,   461,    -1,   508,    -1,   496,    -1,   470,    -1,   494,
      -1,   495,    -1,   457,    -1,   450,    -1,   451,    -1,   452,
      -1,   453,    -1,   454,    -1,   455,    -1,   456,    -1,   475,
      -1,   449,    -1,   493,    -1,     1,    -1,    96,   246,   112,
     243,    -1,    52,   246,   178,   243,    -1,    51,   246,   252,
     243,    -1,    55,   246,   252,   243,    -1,    56,   246,   112,
     243,    -1,    57,   246,   112,   243,    -1,   235,   246,   178,
     243,    -1,   140,   246,   252,   243,    -1,   165,   246,   178,
     243,    -1,    74,   246,   252,   243,    -1,    66,   246,   178,
     243,    -1,    70,   246,   178,   243,    -1,    36,   246,   178,
     243,    -1,    45,   246,   178,   243,    -1,     8,   246,   178,
     243,    -1,    93,   246,   252,   243,    -1,    92,   246,   112,
     243,    -1,    85,   246,   112,   243,    -1,     9,   246,   252,
     243,    -1,   182,   246,   252,   243,    -1,   181,   246,   252,
     243,    -1,    61,   246,   112,   243,    -1,    78,   246,   178,
     243,    -1,    77,   246,   133,   243,    -1,    71,   246,   178,
     243,    -1,   240,   246,   178,   243,    -1,   173,   246,   178,
     243,    -1,   176,   246,   178,   243,    -1,   177,   246,   178,
     243,    -1,   175,   246,   178,   243,    -1,   175,   246,   179,
     243,    -1,   174,   246,   178,   243,    -1,   174,   246,   179,
     243,    -1,   125,   246,   252,   243,    -1,    18,   246,   252,
     243,    -1,   118,   246,   178,   243,    -1,   126,   246,   252,
     243,    -1,   169,   246,   178,   243,    -1,   110,   246,   178,
     243,    -1,   224,   246,   178,   243,    -1,   120,   246,   178,
     243,    -1,    97,   246,   133,   243,    -1,    37,   246,   112,
     243,    -1,    95,   246,   112,   243,    -1,   230,   246,   178,
     243,    -1,    39,   246,   133,   243,    -1,   221,   246,   133,
     243,    -1,   129,   246,   178,   243,    -1,    32,   246,   178,
     243,    -1,   222,   246,   252,   243,    -1,    -1,   122,   498,
     246,   499,   243,    -1,   499,   247,   500,    -1,   500,    -1,
     185,    -1,   188,    -1,   189,    -1,   192,    -1,   193,    -1,
     197,    -1,    62,    -1,   208,    -1,   203,    -1,   205,    -1,
     212,    -1,   209,    -1,   196,    -1,   204,    -1,   207,    -1,
     198,    -1,   218,    -1,   186,    -1,   187,    -1,   201,    -1,
      -1,   119,   502,   246,   503,   243,    -1,   503,   247,   504,
      -1,   504,    -1,   185,    -1,   188,    -1,   189,    -1,   192,
      -1,   193,    -1,   197,    -1,   208,    -1,    62,    -1,   203,
      -1,   205,    -1,   212,    -1,   209,    -1,   196,    -1,   204,
      -1,   207,    -1,   198,    -1,   218,    -1,   186,    -1,   187,
      -1,   201,    -1,    98,   246,   112,   243,    -1,    99,   246,
     112,   243,    -1,    26,   246,   112,   243,    -1,   191,   246,
     254,   243,    -1,    20,   245,   510,   244,   243,    -1,   510,
     511,    -1,   511,    -1,   514,    -1,   515,    -1,   516,    -1,
     517,    -1,   523,    -1,   518,    -1,   519,    -1,   520,    -1,
     521,    -1,   522,    -1,   524,    -1,   525,    -1,   526,    -1,
     513,    -1,   527,    -1,   528,    -1,   529,    -1,   512,    -1,
       1,    -1,    33,   246,   178,   243,    -1,   143,   246,   178,
     243,    -1,    35,   246,   178,   243,    -1,   231,   246,   178,
     243,    -1,   232,   246,   178,   243,    -1,   233,   246,   178,
     243,    -1,    79,   246,   252,   243,    -1,    80,   246,   252,
     243,    -1,    88,   246,   112,   243,    -1,    87,   246,   112,
     243,    -1,   134,   246,   178,   243,    -1,    86,   246,   112,
     243,    -1,    28,   246,   112,   243,    -1,    27,   246,   112,
     243,    -1,   108,   246,   178,   243,    -1,   109,   246,   178,
     243,    -1,   123,   246,   112,   243,    -1,   124,   246,   252,
     243,    -1,   162,   245,   531,   244,   243,    -1,   531,   532,
      -1,   532,    -1,   533,    -1,   534,    -1,   536,    -1,   538,
      -1,   537,    -1,   535,    -1,   539,    -1,     1,    -1,    47,
     246,   178,   243,    -1,    65,   246,   178,   243,    -1,    63,
     246,   133,   243,    -1,    82,   246,   252,   243,    -1,    62,
     246,   178,   243,    -1,    34,   246,   178,   243,    -1,    64,
     246,   178,   243,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   356,   356,   357,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   385,   385,   386,   390,
     394,   398,   402,   406,   412,   412,   413,   414,   415,   416,
     423,   426,   426,   427,   427,   427,   429,   435,   442,   444,
     444,   445,   445,   446,   446,   447,   447,   448,   448,   449,
     449,   450,   450,   451,   451,   452,   453,   456,   457,   459,
     459,   460,   466,   474,   474,   475,   481,   489,   528,   587,
     615,   623,   638,   653,   662,   676,   685,   713,   743,   766,
     775,   777,   777,   778,   778,   779,   779,   781,   790,   799,
     811,   812,   812,   814,   814,   815,   817,   824,   824,   834,
     835,   837,   837,   838,   838,   840,   845,   848,   854,   853,
     859,   859,   860,   864,   868,   872,   876,   880,   884,   895,
     894,   992,   992,   993,   993,   993,   994,   994,   994,   995,
     995,   995,   997,  1006,  1043,  1055,  1066,  1108,  1118,  1117,
    1123,  1123,  1124,  1128,  1132,  1136,  1140,  1144,  1148,  1152,
    1156,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,  1192,
    1196,  1200,  1207,  1206,  1212,  1212,  1213,  1217,  1221,  1225,
    1229,  1233,  1237,  1241,  1245,  1249,  1253,  1257,  1261,  1265,
    1269,  1273,  1277,  1281,  1292,  1291,  1341,  1341,  1342,  1343,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,
    1353,  1354,  1356,  1365,  1371,  1377,  1383,  1389,  1395,  1401,
    1407,  1413,  1419,  1425,  1431,  1441,  1440,  1457,  1456,  1461,
    1461,  1462,  1466,  1470,  1478,  1478,  1479,  1479,  1479,  1479,
    1479,  1481,  1481,  1483,  1483,  1485,  1499,  1519,  1528,  1541,
    1540,  1609,  1609,  1610,  1610,  1610,  1610,  1611,  1611,  1611,
    1612,  1612,  1614,  1649,  1662,  1671,  1683,  1682,  1686,  1686,
    1687,  1691,  1695,  1699,  1703,  1707,  1711,  1715,  1719,  1726,
    1745,  1755,  1769,  1768,  1784,  1784,  1785,  1785,  1785,  1785,
    1787,  1796,  1811,  1824,  1826,  1826,  1827,  1827,  1829,  1845,
    1844,  1860,  1860,  1861,  1861,  1861,  1861,  1863,  1872,  1895,
    1894,  1900,  1900,  1901,  1905,  1909,  1913,  1917,  1921,  1925,
    1929,  1933,  1937,  1947,  1946,  1963,  1963,  1964,  1964,  1964,
    1966,  1973,  1972,  1978,  1978,  1979,  1983,  1987,  1991,  1995,
    1999,  2003,  2007,  2011,  2015,  2025,  2024,  2075,  2075,  2076,
    2076,  2076,  2077,  2077,  2078,  2078,  2078,  2079,  2079,  2079,
    2080,  2080,  2081,  2083,  2092,  2101,  2127,  2145,  2163,  2169,
    2173,  2182,  2181,  2185,  2185,  2186,  2190,  2194,  2198,  2204,
    2215,  2226,  2237,  2246,  2265,  2264,  2330,  2329,  2333,  2333,
    2334,  2340,  2340,  2341,  2341,  2341,  2341,  2343,  2362,  2372,
    2371,  2396,  2396,  2397,  2397,  2397,  2399,  2405,  2414,  2416,
    2416,  2417,  2417,  2419,  2438,  2437,  2485,  2484,  2488,  2488,
    2489,  2495,  2495,  2496,  2496,  2496,  2496,  2498,  2504,  2513,
    2516,  2516,  2517,  2517,  2518,  2518,  2519,  2519,  2520,  2520,
    2521,  2521,  2522,  2522,  2523,  2523,  2524,  2524,  2525,  2525,
    2526,  2526,  2527,  2527,  2528,  2528,  2529,  2529,  2530,  2531,
    2531,  2532,  2532,  2533,  2533,  2534,  2534,  2535,  2535,  2536,
    2537,  2538,  2538,  2539,  2540,  2541,  2541,  2542,  2542,  2543,
    2544,  2544,  2545,  2545,  2546,  2546,  2547,  2550,  2555,  2561,
    2567,  2573,  2578,  2583,  2588,  2593,  2598,  2603,  2608,  2613,
    2618,  2623,  2628,  2633,  2638,  2643,  2648,  2653,  2659,  2670,
    2675,  2684,  2689,  2694,  2699,  2704,  2709,  2712,  2717,  2720,
    2725,  2730,  2735,  2740,  2745,  2750,  2755,  2760,  2765,  2776,
    2781,  2786,  2791,  2800,  2809,  2814,  2819,  2825,  2824,  2829,
    2829,  2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,
    2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,
    2887,  2893,  2892,  2897,  2897,  2898,  2901,  2904,  2907,  2910,
    2913,  2916,  2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,
    2943,  2946,  2949,  2952,  2955,  2960,  2965,  2970,  2975,  2984,
    2987,  2987,  2988,  2988,  2989,  2989,  2989,  2990,  2990,  2991,
    2991,  2992,  2992,  2993,  2994,  2994,  2995,  2996,  2996,  2997,
    2997,  2999,  3004,  3009,  3014,  3019,  3024,  3029,  3034,  3039,
    3044,  3049,  3054,  3059,  3064,  3069,  3074,  3079,  3084,  3092,
    3095,  3095,  3096,  3096,  3097,  3098,  3099,  3099,  3100,  3101,
    3103,  3109,  3115,  3124,  3138,  3144,  3150
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BYTES", "KBYTES", "MBYTES",
  "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH",
  "EMAIL", "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_TIME",
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
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_IDENT",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "NUMBER_PER_IP_GLOBAL", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON",
  "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH", "TREJECT_HOLD_TIME",
  "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS", "RESTRICTED",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVER", "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'",
  "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_client_method",
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
  "class_max_local", "class_max_ident", "class_sendq",
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
  "general_gline_min_cidr6", "general_use_whois_actually",
  "general_reject_hold_time", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_kline_with_reason",
  "general_kline_reason", "general_invisible_on_connect",
  "general_warn_no_nline", "general_stats_e_disabled",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_message_locale", "general_dots_in_ident", "general_max_targets",
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@24", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@25", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "channel_entry",
  "channel_items", "channel_item", "channel_disable_fake_channels",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_disable_hidden", "serverhide_hide_server_ips", YY_NULL
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   248,   249,   249,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   252,
     252,   252,   252,   252,   253,   253,   254,   254,   254,   254,
     255,   256,   256,   257,   257,   257,   258,   259,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   283,   284,   284,   284,   284,   285,   286,   287,
     288,   289,   289,   290,   290,   290,   291,   293,   292,   294,
     294,   295,   295,   295,   295,   296,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   303,
     302,   304,   304,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   306,   307,   308,   309,   310,   311,   313,   312,
     314,   314,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   317,   316,   318,   318,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   321,   320,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   338,   337,   340,   339,   341,
     341,   342,   342,   342,   343,   343,   344,   344,   344,   344,
     344,   346,   345,   347,   347,   348,   348,   349,   350,   352,
     351,   353,   353,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   355,   356,   357,   358,   360,   359,   361,   361,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   363,
     364,   365,   367,   366,   368,   368,   369,   369,   369,   369,
     370,   371,   372,   373,   374,   374,   375,   375,   376,   378,
     377,   379,   379,   380,   380,   380,   380,   381,   382,   384,
     383,   385,   385,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   388,   387,   389,   389,   390,   390,   390,
     391,   393,   392,   394,   394,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   397,   396,   398,   398,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   400,   401,   402,   403,   404,   405,   406,
     406,   408,   407,   409,   409,   410,   410,   410,   410,   411,
     412,   413,   414,   415,   417,   416,   419,   418,   420,   420,
     421,   422,   422,   423,   423,   423,   423,   424,   425,   427,
     426,   428,   428,   429,   429,   429,   430,   431,   432,   433,
     433,   434,   434,   435,   437,   436,   439,   438,   440,   440,
     441,   442,   442,   443,   443,   443,   443,   444,   445,   446,
     447,   447,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   478,   479,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   498,   497,   499,
     499,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   502,   501,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   505,   506,   507,   508,   509,
     510,   510,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   531,   532,   532,   532,   532,   532,   532,   532,   532,
     533,   534,   535,   536,   537,   538,   539
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
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     6,     0,     5,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     0,     5,     3,     1,     1,     3,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   194,   345,   399,     0,
     414,     0,   249,   384,   225,     0,     0,   129,   282,     0,
       0,   299,   323,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   610,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   591,   609,   605,   592,
     593,   594,   595,   597,   598,   599,   600,   601,   596,   602,
     603,   604,   606,   607,   608,     0,     0,     0,   412,     0,
       0,   410,   411,     0,   486,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   561,     0,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     431,   484,   476,   477,   478,   479,   480,   481,   482,   475,
     442,   432,   433,   469,   434,   435,   436,   437,   438,   439,
     440,   441,   472,   443,   444,   445,   446,   483,   448,   453,
     449,   451,   450,   464,   465,   452,   454,   455,   456,   457,
     458,   447,   460,   461,   462,   485,   473,   474,   471,   463,
     459,   467,   468,   466,   470,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,   639,     0,     0,     0,     0,     0,
       0,     0,     0,   631,   632,   633,   637,   634,   636,   635,
     638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   297,     0,     0,   295,
     296,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   198,   201,   202,   204,   205,   206,   207,
     208,   209,   210,   199,   200,   203,     0,     0,     0,     0,
       0,   371,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,   349,   350,   351,   352,   353,   355,   354,   357,
     361,   358,   359,   360,   356,   405,     0,     0,     0,   402,
     403,   404,     0,     0,   409,   426,     0,     0,   416,   425,
       0,   422,   423,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   430,
       0,     0,     0,   266,     0,     0,     0,     0,     0,     0,
     252,   253,   254,   255,   260,   256,   257,   258,   259,   396,
       0,   386,     0,   395,     0,   392,   393,   394,     0,   227,
       0,     0,     0,   237,     0,   235,   236,   238,   239,   105,
       0,     0,   101,     0,    45,     0,     0,     0,    41,     0,
       0,     0,   172,     0,     0,     0,   148,     0,     0,   132,
     133,   134,   135,   138,   139,   137,   136,   140,     0,     0,
       0,     0,     0,   285,   286,   287,   288,     0,     0,     0,
       0,     0,     0,     0,     0,   630,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   309,     0,     0,   302,
     303,   304,   305,     0,     0,   331,     0,   326,   327,   328,
       0,     0,   294,     0,     0,     0,    90,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   589,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,   362,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,     0,   401,     0,   408,     0,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,   429,   261,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,     0,   391,   240,     0,     0,     0,     0,     0,
     234,     0,   100,     0,     0,     0,    40,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   289,     0,
       0,     0,     0,   284,     0,     0,     0,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,    70,    75,    76,     0,    74,     0,     0,
       0,     0,     0,    48,   306,     0,     0,     0,     0,   301,
     329,     0,     0,     0,   325,     0,   293,    99,    98,    97,
     624,   623,   611,   613,    26,    26,    26,    26,    26,    28,
      27,   617,   618,   622,   620,   619,   625,   626,   627,   628,
     621,   612,   614,   615,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   346,     0,     0,   400,   413,     0,     0,
       0,   415,   501,   505,   521,   587,   535,   499,   529,   532,
     500,   489,   488,   490,   491,   492,   508,   497,   498,   511,
     496,   510,   509,   504,   503,   502,   530,   487,   528,   585,
     586,   525,   522,   572,   565,   582,   583,   566,   567,   568,
     569,   577,   570,   580,   584,   573,   578,   574,   579,   571,
     576,   575,   581,     0,   564,   527,   547,   541,   558,   559,
     542,   543,   544,   545,   553,   546,   556,   560,   549,   554,
     550,   555,   548,   552,   551,   557,     0,   540,   520,   523,
     534,   494,   495,   524,   513,   518,   519,   516,   517,   514,
     515,   507,   506,    34,    34,    34,    36,    35,   588,   533,
     536,   526,   531,   493,   512,     0,     0,     0,     0,     0,
       0,     0,     0,   250,     0,     0,     0,   385,     0,     0,
       0,   245,   241,   244,   226,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   283,
     645,   640,   644,   642,   646,   641,   643,    83,    89,    81,
      85,    84,    78,    77,    79,    67,     0,    68,     0,    82,
      80,    88,    86,    87,     0,     0,     0,   300,     0,     0,
     324,   298,    29,    30,    31,    32,    33,   222,   223,   216,
     218,   220,   219,   217,   212,   224,   215,   213,   214,   221,
     367,   369,   370,   382,   379,   375,   376,   378,   377,     0,
     374,   364,   380,   381,   363,   368,   366,   383,   365,   406,
     407,   427,   428,   420,     0,   419,   562,     0,   538,     0,
      37,    38,    39,   264,   265,   274,   271,   276,   273,   272,
     278,   275,   277,   270,     0,   269,   263,   281,   280,   279,
     262,   398,   390,     0,   389,   397,   232,   233,   231,     0,
     230,   248,   247,     0,     0,     0,   114,     0,     0,     0,
       0,   109,   147,   145,   187,   184,   183,   176,   178,   193,
     188,   191,   186,   177,   192,   180,   189,   181,   190,   185,
     179,   182,     0,   175,   142,   144,   146,   158,   152,   169,
     170,   153,   154,   155,   156,   164,   157,   167,   171,   160,
     165,   161,   166,   159,   163,   162,   168,     0,   151,   143,
     291,   292,   290,    69,    73,   307,   313,   319,   322,   315,
     321,   316,   320,   318,   314,   317,     0,   312,   308,   330,
     335,   341,   344,   337,   343,   338,   342,   340,   336,   339,
       0,   334,   372,     0,   417,     0,   563,   539,   267,     0,
     387,     0,   228,     0,   246,   243,   242,     0,     0,     0,
       0,   108,   173,     0,   149,     0,   310,     0,   332,     0,
     373,   418,   268,   388,   229,   115,   124,   127,   126,   123,
     128,   125,   122,     0,   121,   117,   116,   174,   150,   311,
     333,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   819,   820,   966,   967,    25,   248,   249,
     250,   251,    26,   287,   288,   289,   290,   782,   783,   786,
     787,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    27,    71,    72,    73,    74,    75,
      28,   240,   241,   242,   243,   244,  1000,  1001,  1002,  1003,
    1004,  1138,  1263,  1264,    29,    60,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   754,  1187,  1188,   537,   750,
    1162,  1163,    30,    49,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,    31,
      57,   503,   735,  1129,  1130,   504,   505,   506,  1135,   992,
     993,   507,   508,    32,    55,   479,   480,   481,   482,   483,
     484,   485,   721,  1114,  1115,   486,   487,   488,    33,    61,
     542,   543,   544,   545,   546,    34,   308,   309,   310,    35,
      64,   578,   579,   580,   581,   582,   796,  1206,  1207,    36,
      65,   586,   587,   588,   589,   802,  1220,  1221,    37,    50,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     638,  1079,  1080,   390,   391,   392,   393,   394,    38,    56,
     493,   730,  1123,  1124,   494,   495,   496,   497,    39,    51,
     398,   399,   400,   401,    40,   120,   121,   122,    41,    53,
     409,   657,  1094,  1095,   410,   411,   412,   413,    42,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     447,   946,   947,   230,   445,   923,   924,   231,   232,   233,
     234,    43,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   262,   263,   264,   265,   266,   267,   268,
     269,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -635
static const yytype_int16 yypact[] =
{
    -635,   685,  -635,  -238,  -205,  -200,  -635,  -635,  -635,  -194,
    -635,  -191,  -635,  -635,  -635,  -186,  -173,  -635,  -635,  -171,
    -135,  -635,  -635,  -111,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,     7,   594,  -101,
     -96,   -94,    17,   -89,   425,   -88,   -78,   -68,    82,    14,
     -67,   -56,   355,   464,   -54,   -51,     2,  -130,   -50,   -49,
     -44,    16,  -635,  -635,  -635,  -635,  -635,   -42,   -33,   -23,
     -17,   -15,   -14,    -8,    -6,    -5,    -3,    -1,    39,    44,
      67,    68,    73,    75,    76,   209,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   755,   506,    10,  -635,    88,
      29,  -635,  -635,   172,  -635,    98,    99,   100,   109,   111,
     114,   116,   119,   120,   121,   124,   126,   128,   130,   132,
     135,   136,   137,   145,   146,   147,   149,   150,   151,   153,
     154,   155,   160,   161,   163,   164,  -635,   166,  -635,   167,
     179,   184,   185,   186,   189,   190,   192,   193,   206,   208,
     210,   212,   213,   214,   217,   220,   221,   222,   223,   129,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   348,    41,   291,   -25,   225,
      57,  -635,  -635,  -635,    45,   181,   226,   227,    32,  -635,
    -635,  -635,   537,   292,  -635,   232,   233,   237,   241,   242,
     243,   244,    15,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,   249,   247,   254,   255,   258,   259,   260,   265,   267,
     268,   269,   270,   279,   280,   281,   282,   178,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,   118,    25,  -635,   284,    34,  -635,
    -635,  -635,   134,   142,   322,   288,  -635,   140,   263,   358,
     359,   427,   427,   428,   429,   430,   368,   371,   443,   427,
     378,   379,   381,   384,   385,   321,  -635,   324,   325,   326,
     328,   330,   334,   335,   336,   338,   339,   340,   342,   343,
     345,   314,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   327,   346,   347,   350,
     351,  -635,   369,   372,   373,   374,   377,   380,   386,   387,
      21,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   390,   391,    35,  -635,
    -635,  -635,   471,   362,  -635,  -635,   394,   395,  -635,  -635,
      24,  -635,  -635,  -635,   439,   427,   427,   513,   452,   453,
     531,   515,   472,   427,   473,   427,   541,   544,   545,   480,
     483,   484,   427,   530,   490,   558,   560,   427,   563,   565,
     538,   567,   572,   509,   510,   445,   511,   447,   427,   427,
     516,   427,   517,   520,   521,  -166,  -147,   526,   528,   427,
     427,   598,   578,   427,   535,   543,   546,   547,   489,  -635,
     492,   469,   477,  -635,   493,   494,   499,   500,   501,    27,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
     504,  -635,   505,  -635,    37,  -635,  -635,  -635,   495,  -635,
     508,   518,   519,  -635,     9,  -635,  -635,  -635,  -635,  -635,
     548,   512,  -635,   491,  -635,   619,   626,   524,  -635,   536,
     527,   539,  -635,   549,   550,   552,  -635,   553,     6,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   540,   554,
     555,   557,    40,  -635,  -635,  -635,  -635,   571,   584,   585,
     648,   604,   606,   427,   561,  -635,  -635,   656,   613,   673,
     674,   675,   676,   677,   678,   -59,   -52,   679,   680,   702,
     683,   684,   575,  -635,   576,   574,  -635,   582,    33,  -635,
    -635,  -635,  -635,   580,   583,  -635,    19,  -635,  -635,  -635,
     688,   581,  -635,   587,   588,   589,  -635,   590,   591,   592,
     593,   229,   596,   597,   599,   600,   607,   610,   611,   612,
     615,   617,   618,   620,   621,   622,  -635,  -635,   725,   729,
     427,   744,   747,   750,   754,   734,   756,   759,   427,   427,
     598,   629,  -635,  -635,   740,   -75,   741,   697,   630,   745,
     746,   757,   761,   765,   762,   764,   768,   646,  -635,   773,
     775,   666,  -635,   667,  -635,   778,   779,   668,   689,  -635,
     691,   699,   700,   708,   711,   712,   716,   717,   719,   723,
     727,   728,   730,   731,   733,   736,   737,   738,   739,   742,
     743,   748,   749,   751,   752,   753,   758,   763,   766,   767,
     769,   695,   770,   732,   771,   772,   774,   776,   777,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789,    71,
     790,   791,   792,   793,   794,   795,   796,  -635,  -635,   798,
     797,   670,   805,   810,   844,   850,   851,   799,  -635,   854,
     681,   855,   800,  -635,  -635,   801,   856,   857,   811,   802,
    -635,   803,  -635,   170,   806,   807,  -635,  -635,   860,   819,
     808,   865,   866,   867,   809,   869,   813,  -635,  -635,   870,
     871,   872,   814,  -635,   815,   816,   817,   818,   820,   821,
     822,  -635,   823,   824,   825,   826,   827,   828,   829,   830,
    -635,  -635,  -224,  -635,  -635,  -635,  -204,  -635,   831,   832,
     833,   834,   835,  -635,  -635,   874,   836,   875,   837,  -635,
    -635,   878,   838,   840,  -635,   842,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,   427,   427,   427,   427,   427,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   843,   845,   846,   847,   848,
     849,   852,   853,   858,   859,   861,   862,   863,  -635,   864,
     868,   873,   876,   877,   138,   879,   880,   881,   882,   883,
     884,   885,   886,  -635,   887,   888,  -635,  -635,   889,   890,
     902,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -190,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -182,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,   598,   598,   598,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,   891,   892,   616,   893,   894,
     895,   896,   897,  -635,   898,   903,   899,  -635,   -48,   900,
     901,   839,   804,  -635,  -635,  -635,   904,   841,  -635,   905,
      20,  -635,  -635,  -635,  -635,  -635,  -635,   906,   907,   503,
     909,   910,   911,   760,   912,  -635,   913,   914,   915,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   -59,  -635,   -52,  -635,
    -635,  -635,  -635,  -635,   916,   559,   917,  -635,   918,   577,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -179,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -177,  -635,  -635,   695,  -635,   732,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -172,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -156,  -635,  -635,  -635,  -635,  -635,  -149,
    -635,  -635,  -635,   932,   811,   919,  -635,   920,   921,  -108,
     922,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -132,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -127,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   -31,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
     -28,  -635,  -635,   138,  -635,   902,  -635,  -635,  -635,   616,
    -635,   903,  -635,   -48,  -635,  -635,  -635,   923,   304,   925,
     926,  -635,  -635,   503,  -635,   760,  -635,   559,  -635,   577,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,   -13,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,   304,  -635
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -635,  -635,  -635,  -368,  -320,  -634,  -461,  -635,  -635,   924,
    -635,  -635,  -635,  -635,   639,  -635,  -635,  -635,   -20,  -635,
      43,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   947,  -635,  -635,  -635,
    -635,  -635,   812,  -635,  -635,  -635,  -635,    48,  -635,  -635,
    -635,  -635,  -635,  -251,  -635,  -635,  -635,   534,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -152,  -635,  -635,
    -635,  -164,  -635,  -635,  -635,   908,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -139,  -635,   595,  -635,  -635,  -635,
     -37,  -635,  -635,  -635,  -635,  -635,   624,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -131,  -635,  -635,  -635,  -635,  -635,
    -635,   566,  -635,  -635,  -635,  -635,  -635,   927,  -635,  -635,
    -635,  -635,   522,  -635,  -635,  -635,  -635,  -635,  -138,  -635,
    -635,  -635,   529,  -635,  -635,  -635,  -635,  -137,  -635,  -635,
    -635,   928,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -113,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -118,  -635,   623,  -635,  -635,  -635,  -635,
    -635,   720,  -635,  -635,  -635,  -635,   994,  -635,  -635,  -635,
    -635,  -635,  -635,  -104,  -635,   735,  -635,  -635,  -635,  -635,
     967,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,    49,  -635,  -635,  -635,    66,  -635,  -635,  -635,
    -635,  -635,  -635,  1069,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,   929,  -635,  -635,  -635,  -635,  -635,
    -635,  -635
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     710,   602,   603,   306,   709,    45,    46,   519,    67,   610,
     498,   395,   701,   702,  1126,   245,   254,    67,   118,  1035,
     583,   996,   366,  1036,   367,   405,   583,   368,   470,   520,
     118,   703,   704,   245,   574,   306,   395,    68,   489,  1037,
      47,   538,   489,  1038,   369,    48,    68,    69,   521,   255,
     471,    52,   522,  1096,    54,   499,    69,  1097,   238,    58,
     539,  1098,   256,   370,  1222,  1099,  1224,   371,  1223,   472,
    1225,  1228,    59,   473,    62,  1229,   500,   257,   258,   259,
     260,   501,   396,   238,   963,   964,   965,  1230,   372,   119,
     373,  1231,   780,   781,  1232,   661,   662,   261,  1233,   784,
     785,   119,   374,   669,   307,   671,  1239,   396,   523,    70,
      63,  1242,   678,   311,   246,  1243,  1244,   683,    70,   574,
    1245,   584,   997,   375,   850,   851,   406,   584,   694,   695,
     124,   697,   246,   524,    66,   575,   307,   125,   126,   707,
     708,   502,   247,   712,   115,   397,   540,   127,  1075,   116,
    1076,   117,   525,   376,   474,   128,   123,   235,  1127,   407,
     247,   129,  1128,   475,   476,   130,   131,   236,   132,   847,
     397,   996,   490,   405,   133,   541,   490,   237,   252,   271,
     134,   135,   377,   709,   136,   137,   138,   585,   998,   253,
     139,   304,   408,   585,   305,   140,   312,   313,   477,   141,
     142,   576,   314,   143,   317,   491,   144,   145,   272,   491,
      76,   378,  1246,   318,   146,  1248,  1247,   526,   509,  1249,
     575,   147,   148,   319,   149,   150,   151,   152,   153,   320,
    1271,   321,   322,   770,  1272,   527,    77,    78,   323,   154,
     324,   325,    79,   326,    80,   327,   273,   155,   156,   157,
     756,   158,   597,   739,   159,   160,   478,   379,   161,   554,
     315,   999,   577,   803,  1140,   647,   492,   593,   658,   162,
     492,   727,   997,   403,   406,   594,   517,   798,   591,   651,
     274,   732,   275,   276,   762,   328,   576,   513,    81,    82,
     329,   239,   498,   538,   163,    83,    84,    85,   164,  -107,
     837,   511,   165,   166,   167,   168,   169,   407,   845,   846,
     170,   171,   539,   330,   331,   337,   239,    86,    87,   332,
     172,   333,   334,   277,  -107,   278,   279,   280,   281,  1100,
    1101,  1102,    88,    89,   402,   338,   339,   499,   998,   340,
     408,   601,   282,    90,   414,   415,   416,   577,  1077,   470,
     173,   174,    91,   175,  1256,   417,   254,   418,   500,   176,
     419,  1078,   420,   501,   177,   421,   422,   423,   283,   178,
     424,   471,   425,   468,   426,   598,   427,  1257,   428,  1258,
     284,   429,   430,   431,   814,   815,   816,   817,   818,   255,
     472,   432,   433,   434,   473,   435,   436,   437,   540,   438,
     439,   440,   256,   341,   342,   343,   441,   442,   344,   443,
     444,   999,   446,   448,   285,   286,   345,   257,   258,   259,
     260,  1259,   572,   502,   514,   449,   124,   541,   346,   347,
     450,   451,   452,   125,   126,   453,   454,   261,   455,   456,
      92,    93,    94,   127,   348,   349,  1052,  1053,  1054,  1055,
    1056,   128,   457,   335,   458,   595,   459,   129,   460,   461,
     462,   130,   131,   463,   132,   271,   464,   465,   466,   467,
     133,   510,   515,   516,   350,   474,   134,   135,   547,   548,
     136,   137,   138,   549,   475,   476,   139,   550,   551,   552,
     553,   140,   556,   557,   272,   141,   142,  1260,  1261,   143,
     558,   559,   144,   145,   560,   561,   562,   366,  1144,   367,
     146,   563,   368,   564,   565,   566,   567,   147,   148,   477,
     149,   150,   151,   152,   153,   568,   569,   570,   571,   369,
     590,   596,   273,  1262,  1145,   154,   599,   600,   519,   601,
     604,   605,   606,   155,   156,   157,   607,   158,   370,   608,
     159,   160,   371,  1146,   161,   609,   611,   612,   631,   613,
     520,  1147,   614,   615,   616,   162,   274,   617,   275,   276,
     633,   618,   619,   372,   620,   373,   621,   478,  1148,   521,
     622,   623,   624,   522,   625,   626,   627,   374,   628,   629,
     163,   630,   634,   635,   164,    76,   636,   637,   165,   166,
     167,   168,   169,  1149,   653,   654,   170,   171,   375,   277,
    1150,   278,   279,   280,   281,   639,   172,   660,   640,   641,
     642,    77,    78,   643,  1151,   663,   644,    79,   282,    80,
     664,   665,   645,   646,  1196,  1105,   649,   650,   376,   523,
     655,   656,  1152,   666,  1153,  1154,   173,   174,   667,   175,
     668,   670,  1210,   672,   283,   176,   673,   674,   675,  1106,
     177,   676,   677,   679,   524,   178,   284,   377,   680,  1107,
     681,   686,   682,    81,    82,   684,  1108,   685,  1240,   687,
      83,    84,    85,   525,   688,     2,     3,   689,   690,   692,
       4,   691,  1109,   693,   696,   698,   378,  1155,   699,   700,
     285,   286,    86,    87,   705,     5,   706,  1156,     6,     7,
     709,   711,  1197,   713,     8,   719,  1157,    88,    89,  1110,
    1158,   714,  1159,   720,   715,   716,   741,  1111,    90,     9,
    1211,  1160,   717,    10,    11,   718,   743,    91,   734,   722,
     723,  1161,   379,  1198,    12,   724,   725,   726,   526,   764,
     729,   731,   744,  1199,   736,   742,   337,   903,    13,   745,
    1200,  1212,   765,   766,   737,   738,   527,   746,    14,    15,
    1112,  1213,  1201,   748,  1202,  1203,   338,   339,  1214,   747,
     340,   767,   768,   758,   769,   749,    16,  1204,  1113,   772,
    1215,   773,  1216,  1217,   926,   751,   752,  1205,   753,   755,
     759,   760,    17,   761,   771,  1218,   774,   775,   776,   777,
     778,   779,   788,   789,   790,  1219,   791,   792,   793,   794,
     795,   805,  1167,   800,   806,    92,    93,    94,   797,   801,
     807,   808,   809,   810,   811,   812,   813,   835,    18,   821,
     822,   836,   823,   824,   341,   342,   343,    19,    20,   344,
     825,    21,    22,   826,   827,   828,   838,   345,   829,   839,
     830,   831,   840,   832,   833,   834,   841,   842,   843,   346,
     347,   844,   848,   849,   852,   853,   854,   859,   855,   856,
     904,   905,   906,   907,   908,   348,   349,   909,   910,   863,
     857,   911,   912,   913,   858,   860,   914,   861,   915,   916,
     917,   862,   918,   919,   920,    23,   864,   921,   865,   866,
     867,   868,   869,   922,   870,   350,   977,   927,   928,   929,
     930,   931,   979,   991,   932,   933,   573,   985,   934,   935,
     936,   975,   871,   937,   872,   938,   939,   940,   978,   941,
     942,   943,   873,   874,   944,  1168,  1169,  1170,  1171,  1172,
     945,   875,  1173,  1174,   876,   877,  1175,  1176,  1177,   878,
     879,  1178,   880,  1179,  1180,  1181,   881,  1182,  1183,  1184,
     882,   883,  1185,   884,   885,   976,   886,   980,  1186,   887,
     888,   889,   890,   981,   982,   891,   892,   984,   986,   989,
     990,   893,   894,  1007,   895,   896,   897,  1008,  1010,  1011,
    1012,   898,  1014,  1016,  1017,  1018,   899,  1044,  1046,   900,
     901,  1048,   902,   925,   948,   949,  1193,   950,   316,   951,
     952,  1273,  1133,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   962,   968,   969,   970,   971,   972,   973,   974,
    1093,  1122,   983,   987,  1234,   994,   995,   988,  1141,  1005,
    1006,  1134,   512,  1237,  1009,  1013,  1015,  1019,  1020,  1021,
    1022,  1023,   757,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1039,  1040,  1041,  1042,  1043,  1267,
    1047,  1194,  1045,  1050,  1049,  1051,  1057,  1137,  1058,  1059,
    1060,  1061,  1062,  1268,  1254,  1063,  1064,  1235,  1252,   740,
     799,  1065,  1066,   728,  1067,  1068,  1069,  1070,   763,  1269,
    1250,  1071,  1270,  1253,   404,   804,  1072,   733,   652,  1073,
    1074,  1251,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1103,  1104,  1116,  1117,  1118,  1119,
    1120,  1121,  1125,  1131,  1132,   659,   469,  1136,  1227,  1142,
    1143,  1139,  1164,  1165,  1166,  1189,  1190,  1191,  1192,  1195,
    1208,  1209,  1236,  1226,   336,  1241,  1255,  1238,  1265,  1266,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   648
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-635))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     461,   321,   322,     1,   112,   243,   244,     1,     1,   329,
       1,     1,   178,   179,    62,     1,     1,     1,     1,   243,
       1,     1,     1,   247,     3,     1,     1,     6,     1,    23,
       1,   178,   179,     1,     1,     1,     1,    30,     1,   243,
     245,     1,     1,   247,    23,   245,    30,    40,    42,    34,
      23,   245,    46,   243,   245,    46,    40,   247,     1,   245,
      20,   243,    47,    42,   243,   247,   243,    46,   247,    42,
     247,   243,   245,    46,   245,   247,    67,    62,    63,    64,
      65,    72,    72,     1,    13,    14,    15,   243,    67,    72,
      69,   247,   151,   152,   243,   415,   416,    82,   247,   151,
     152,    72,    81,   423,   102,   425,   214,    72,   102,   102,
     245,   243,   432,   243,   100,   247,   243,   437,   102,     1,
     247,   102,   102,   102,   199,   200,   102,   102,   448,   449,
       1,   451,   100,   127,   245,   102,   102,     8,     9,   459,
     460,   132,   128,   463,   245,   135,   106,    18,    10,   245,
      12,   245,   146,   132,   127,    26,   245,   245,   206,   135,
     128,    32,   210,   136,   137,    36,    37,   245,    39,   630,
     135,     1,   135,     1,    45,   135,   135,   245,   245,     1,
      51,    52,   161,   112,    55,    56,    57,   168,   168,   245,
      61,   245,   168,   168,   245,    66,   246,   246,   171,    70,
      71,   168,   246,    74,   246,   168,    77,    78,    30,   168,
       1,   190,   243,   246,    85,   243,   247,   211,   243,   247,
     102,    92,    93,   246,    95,    96,    97,    98,    99,   246,
     243,   246,   246,   553,   247,   229,    27,    28,   246,   110,
     246,   246,    33,   246,    35,   246,    68,   118,   119,   120,
     244,   122,   112,   244,   125,   126,   229,   236,   129,   244,
     244,   241,   229,   244,   244,   244,   229,   133,   244,   140,
     229,   244,   102,   244,   102,   133,   244,   244,   244,   244,
     102,   244,   104,   105,   244,   246,   168,   242,    79,    80,
     246,   234,     1,     1,   165,    86,    87,    88,   169,   242,
     620,   244,   173,   174,   175,   176,   177,   135,   628,   629,
     181,   182,    20,   246,   246,     1,   234,   108,   109,   246,
     191,   246,   246,   145,   242,   147,   148,   149,   150,   963,
     964,   965,   123,   124,   246,    21,    22,    46,   168,    25,
     168,   112,   164,   134,   246,   246,   246,   229,   210,     1,
     221,   222,   143,   224,    50,   246,     1,   246,    67,   230,
     246,   223,   246,    72,   235,   246,   246,   246,   190,   240,
     246,    23,   246,   244,   246,   112,   246,    73,   246,    75,
     202,   246,   246,   246,   155,   156,   157,   158,   159,    34,
      42,   246,   246,   246,    46,   246,   246,   246,   106,   246,
     246,   246,    47,    89,    90,    91,   246,   246,    94,   246,
     246,   241,   246,   246,   236,   237,   102,    62,    63,    64,
      65,   117,   244,   132,   243,   246,     1,   135,   114,   115,
     246,   246,   246,     8,     9,   246,   246,    82,   246,   246,
     231,   232,   233,    18,   130,   131,   814,   815,   816,   817,
     818,    26,   246,   244,   246,   133,   246,    32,   246,   246,
     246,    36,    37,   246,    39,     1,   246,   246,   246,   246,
      45,   246,   246,   246,   160,   127,    51,    52,   246,   246,
      55,    56,    57,   246,   136,   137,    61,   246,   246,   246,
     246,    66,   243,   246,    30,    70,    71,   193,   194,    74,
     246,   246,    77,    78,   246,   246,   246,     1,     5,     3,
      85,   246,     6,   246,   246,   246,   246,    92,    93,   171,
      95,    96,    97,    98,    99,   246,   246,   246,   246,    23,
     246,   243,    68,   229,    31,   110,   178,   178,     1,   112,
     112,   112,   112,   118,   119,   120,   178,   122,    42,   178,
     125,   126,    46,    50,   129,   112,   178,   178,   244,   178,
      23,    58,   178,   178,   243,   140,   102,   243,   104,   105,
     243,   246,   246,    67,   246,    69,   246,   229,    75,    42,
     246,   246,   246,    46,   246,   246,   246,    81,   246,   246,
     165,   246,   246,   246,   169,     1,   246,   246,   173,   174,
     175,   176,   177,   100,   133,   243,   181,   182,   102,   145,
     107,   147,   148,   149,   150,   246,   191,   178,   246,   246,
     246,    27,    28,   246,   121,   112,   246,    33,   164,    35,
     178,   178,   246,   246,    75,    19,   246,   246,   132,   102,
     246,   246,   139,   112,   141,   142,   221,   222,   133,   224,
     178,   178,    75,   112,   190,   230,   112,   112,   178,    43,
     235,   178,   178,   133,   127,   240,   202,   161,   178,    53,
     112,   133,   112,    79,    80,   112,    60,   112,  1139,   112,
      86,    87,    88,   146,   112,     0,     1,   178,   178,   178,
       5,   246,    76,   246,   178,   178,   190,   194,   178,   178,
     236,   237,   108,   109,   178,    20,   178,   204,    23,    24,
     112,   133,   153,   178,    29,   246,   213,   123,   124,   103,
     217,   178,   219,   246,   178,   178,   178,   111,   134,    44,
     153,   228,   243,    48,    49,   243,   245,   143,   243,   246,
     246,   238,   236,   184,    59,   246,   246,   246,   211,   178,
     246,   246,   133,   194,   246,   243,     1,    62,    73,   133,
     201,   184,   178,   178,   246,   246,   229,   243,    83,    84,
     154,   194,   213,   246,   215,   216,    21,    22,   201,   243,
      25,   133,   178,   243,   178,   246,   101,   228,   172,   133,
     213,   178,   215,   216,    62,   246,   246,   238,   246,   246,
     246,   246,   117,   246,   243,   228,   133,   133,   133,   133,
     133,   133,   133,   133,   112,   238,   133,   133,   243,   243,
     246,   133,    62,   243,   243,   231,   232,   233,   246,   246,
     243,   243,   243,   243,   243,   243,   243,   112,   153,   243,
     243,   112,   243,   243,    89,    90,    91,   162,   163,    94,
     243,   166,   167,   243,   243,   243,   112,   102,   243,   112,
     243,   243,   112,   243,   243,   243,   112,   133,   112,   114,
     115,   112,   243,   133,   133,   178,   246,   112,   133,   133,
     185,   186,   187,   188,   189,   130,   131,   192,   193,   243,
     133,   196,   197,   198,   133,   133,   201,   133,   203,   204,
     205,   133,   207,   208,   209,   220,   133,   212,   133,   243,
     243,   133,   133,   218,   246,   160,   246,   185,   186,   187,
     188,   189,   112,   112,   192,   193,   287,   246,   196,   197,
     198,   133,   243,   201,   243,   203,   204,   205,   133,   207,
     208,   209,   243,   243,   212,   185,   186,   187,   188,   189,
     218,   243,   192,   193,   243,   243,   196,   197,   198,   243,
     243,   201,   243,   203,   204,   205,   243,   207,   208,   209,
     243,   243,   212,   243,   243,   178,   243,   133,   218,   243,
     243,   243,   243,   133,   133,   243,   243,   133,   133,   133,
     133,   243,   243,   133,   243,   243,   243,   178,   133,   133,
     133,   243,   133,   133,   133,   133,   243,   133,   133,   243,
     243,   133,   243,   243,   243,   243,  1036,   243,    71,   243,
     243,  1272,   183,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     138,   138,   243,   243,   112,   243,   243,   246,  1000,   243,
     243,   247,   240,   133,   246,   246,   243,   243,   243,   243,
     243,   243,   528,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,  1243,
     243,  1038,   246,   243,   246,   243,   243,   246,   243,   243,
     243,   243,   243,  1245,  1233,   243,   243,  1134,  1229,   504,
     578,   243,   243,   479,   243,   243,   243,   243,   542,  1247,
    1223,   243,  1249,  1231,   120,   586,   243,   494,   398,   243,
     243,  1225,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   410,   179,   243,  1099,   243,
     243,   246,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,  1097,    95,   243,   243,   246,   243,   243,
      -1,    -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   380
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   249,     0,     1,     5,    20,    23,    24,    29,    44,
      48,    49,    59,    73,    83,    84,   101,   117,   153,   162,
     163,   166,   167,   220,   250,   255,   260,   282,   288,   302,
     320,   337,   351,   366,   373,   377,   387,   396,   416,   426,
     432,   436,   446,   509,   530,   243,   244,   245,   245,   321,
     397,   427,   245,   437,   245,   352,   417,   338,   245,   245,
     303,   367,   245,   245,   378,   388,   245,     1,    30,    40,
     102,   283,   284,   285,   286,   287,     1,    27,    28,    33,
      35,    79,    80,    86,    87,    88,   108,   109,   123,   124,
     134,   143,   231,   232,   233,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   245,   245,   245,     1,    72,
     433,   434,   435,   245,     1,     8,     9,    18,    26,    32,
      36,    37,    39,    45,    51,    52,    55,    56,    57,    61,
      66,    70,    71,    74,    77,    78,    85,    92,    93,    95,
      96,    97,    98,    99,   110,   118,   119,   120,   122,   125,
     126,   129,   140,   165,   169,   173,   174,   175,   176,   177,
     181,   182,   191,   221,   222,   224,   230,   235,   240,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     501,   505,   506,   507,   508,   245,   245,   245,     1,   234,
     289,   290,   291,   292,   293,     1,   100,   128,   256,   257,
     258,   259,   245,   245,     1,    34,    47,    62,    63,    64,
      65,    82,   531,   532,   533,   534,   535,   536,   537,   538,
     539,     1,    30,    68,   102,   104,   105,   145,   147,   148,
     149,   150,   164,   190,   202,   236,   237,   261,   262,   263,
     264,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   245,   245,     1,   102,   374,   375,
     376,   243,   246,   246,   246,   244,   284,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   244,   511,     1,    21,    22,
      25,    89,    90,    91,    94,   102,   114,   115,   130,   131,
     160,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,     1,     3,     6,    23,
      42,    46,    67,    69,    81,   102,   132,   161,   190,   236,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     411,   412,   413,   414,   415,     1,    72,   135,   428,   429,
     430,   431,   246,   244,   434,     1,   102,   135,   168,   438,
     442,   443,   444,   445,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   502,   246,   498,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   244,   448,
       1,    23,    42,    46,   127,   136,   137,   171,   229,   353,
     354,   355,   356,   357,   358,   359,   363,   364,   365,     1,
     135,   168,   229,   418,   422,   423,   424,   425,     1,    46,
      67,    72,   132,   339,   343,   344,   345,   349,   350,   243,
     246,   244,   290,   242,   243,   246,   246,   244,   257,     1,
      23,    42,    46,   102,   127,   146,   211,   229,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   316,     1,    20,
     106,   135,   368,   369,   370,   371,   372,   246,   246,   246,
     246,   246,   246,   246,   244,   532,   243,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   244,   262,     1,   102,   168,   229,   379,   380,
     381,   382,   383,     1,   102,   168,   389,   390,   391,   392,
     246,   244,   375,   133,   133,   133,   243,   112,   112,   178,
     178,   112,   252,   252,   112,   112,   112,   178,   178,   112,
     252,   178,   178,   178,   178,   178,   243,   243,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   244,   323,   243,   246,   246,   246,   246,   408,   246,
     246,   246,   246,   246,   246,   246,   246,   244,   399,   246,
     246,   244,   429,   133,   243,   246,   246,   439,   244,   443,
     178,   252,   252,   112,   178,   178,   112,   133,   178,   252,
     178,   252,   112,   112,   112,   178,   178,   178,   252,   133,
     178,   112,   112,   252,   112,   112,   133,   112,   112,   178,
     178,   246,   178,   246,   252,   252,   178,   252,   178,   178,
     178,   178,   179,   178,   179,   178,   178,   252,   252,   112,
     254,   133,   252,   178,   178,   178,   178,   243,   243,   246,
     246,   360,   246,   246,   246,   246,   246,   244,   354,   246,
     419,   246,   244,   423,   243,   340,   246,   246,   246,   244,
     344,   178,   243,   245,   133,   133,   243,   243,   246,   246,
     317,   246,   246,   246,   313,   246,   244,   305,   243,   246,
     246,   246,   244,   369,   178,   178,   178,   133,   178,   178,
     252,   243,   133,   178,   133,   133,   133,   133,   133,   133,
     151,   152,   265,   266,   151,   152,   267,   268,   133,   133,
     112,   133,   133,   243,   243,   246,   384,   246,   244,   380,
     243,   246,   393,   244,   390,   133,   243,   243,   243,   243,
     243,   243,   243,   243,   155,   156,   157,   158,   159,   251,
     252,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   112,   112,   252,   112,   112,
     112,   112,   133,   112,   112,   252,   252,   254,   243,   133,
     199,   200,   133,   178,   246,   133,   133,   133,   133,   112,
     133,   133,   133,   243,   133,   133,   243,   243,   133,   133,
     246,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,    62,   185,   186,   187,   188,   189,   192,
     193,   196,   197,   198,   201,   203,   204,   205,   207,   208,
     209,   212,   218,   503,   504,   243,    62,   185,   186,   187,
     188,   189,   192,   193,   196,   197,   198,   201,   203,   204,
     205,   207,   208,   209,   212,   218,   499,   500,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,    13,    14,    15,   253,   254,   243,   243,
     243,   243,   243,   243,   243,   133,   178,   246,   133,   112,
     133,   133,   133,   243,   133,   246,   133,   243,   246,   133,
     133,   112,   347,   348,   243,   243,     1,   102,   168,   241,
     294,   295,   296,   297,   298,   243,   243,   133,   178,   246,
     133,   133,   133,   246,   133,   243,   133,   133,   133,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   247,   243,   247,   243,
     243,   243,   243,   243,   133,   246,   133,   243,   133,   246,
     243,   243,   251,   251,   251,   251,   251,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,    10,    12,   210,   223,   409,
     410,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   138,   440,   441,   243,   247,   243,   247,
     253,   253,   253,   243,   243,    19,    43,    53,    60,    76,
     103,   111,   154,   172,   361,   362,   243,   243,   243,   243,
     243,   243,   138,   420,   421,   243,    62,   206,   210,   341,
     342,   243,   243,   183,   247,   346,   243,   246,   299,   246,
     244,   295,   243,   243,     5,    31,    50,    58,    75,   100,
     107,   121,   139,   141,   142,   194,   204,   213,   217,   219,
     228,   238,   318,   319,   243,   243,   243,    62,   185,   186,
     187,   188,   189,   192,   193,   196,   197,   198,   201,   203,
     204,   205,   207,   208,   209,   212,   218,   314,   315,   243,
     243,   243,   243,   266,   268,   243,    75,   153,   184,   194,
     201,   213,   215,   216,   228,   238,   385,   386,   243,   243,
      75,   153,   184,   194,   201,   213,   215,   216,   228,   238,
     394,   395,   243,   247,   243,   247,   504,   500,   243,   247,
     243,   247,   243,   247,   112,   348,   243,   133,   246,   214,
     254,   243,   243,   247,   243,   247,   243,   247,   243,   247,
     410,   441,   362,   421,   342,   243,    50,    73,    75,   117,
     193,   194,   229,   300,   301,   243,   243,   319,   315,   386,
     395,   243,   247,   301
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

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


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


/* Prevent warnings from -Wmissing-prototypes.  */
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

/* Line 1810 of yacc.c  */
#line 385 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1810 of yacc.c  */
#line 387 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1810 of yacc.c  */
#line 391 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1810 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1810 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1810 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1810 of yacc.c  */
#line 407 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1810 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1810 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1810 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1810 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1810 of yacc.c  */
#line 416 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1810 of yacc.c  */
#line 430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:

/* Line 1810 of yacc.c  */
#line 436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:

/* Line 1810 of yacc.c  */
#line 461 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:

/* Line 1810 of yacc.c  */
#line 467 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:

/* Line 1810 of yacc.c  */
#line 476 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:

/* Line 1810 of yacc.c  */
#line 482 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:

/* Line 1810 of yacc.c  */
#line 490 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 529 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 588 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 616 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:

/* Line 1810 of yacc.c  */
#line 624 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 639 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:

/* Line 1810 of yacc.c  */
#line 663 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:

/* Line 1810 of yacc.c  */
#line 686 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 714 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 744 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 767 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:

/* Line 1810 of yacc.c  */
#line 782 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:

/* Line 1810 of yacc.c  */
#line 791 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:

/* Line 1810 of yacc.c  */
#line 800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:

/* Line 1810 of yacc.c  */
#line 818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:

/* Line 1810 of yacc.c  */
#line 824 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:

/* Line 1810 of yacc.c  */
#line 829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:

/* Line 1810 of yacc.c  */
#line 841 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:

/* Line 1810 of yacc.c  */
#line 846 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:

/* Line 1810 of yacc.c  */
#line 849 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:

/* Line 1810 of yacc.c  */
#line 854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:

/* Line 1810 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:

/* Line 1810 of yacc.c  */
#line 865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:

/* Line 1810 of yacc.c  */
#line 869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:

/* Line 1810 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:

/* Line 1810 of yacc.c  */
#line 877 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:

/* Line 1810 of yacc.c  */
#line 881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:

/* Line 1810 of yacc.c  */
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:

/* Line 1810 of yacc.c  */
#line 895 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 908 "conf_parser.y"
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
        new_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, 
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

/* Line 1810 of yacc.c  */
#line 998 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:

/* Line 1810 of yacc.c  */
#line 1007 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 1044 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 1056 "conf_parser.y"
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

/* Line 1810 of yacc.c  */
#line 1067 "conf_parser.y"
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

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

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

/* Line 1810 of yacc.c  */
#line 1109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:

/* Line 1810 of yacc.c  */
#line 1118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1810 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1810 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1810 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1810 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1810 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1810 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1810 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:

/* Line 1810 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:

/* Line 1810 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:

/* Line 1810 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:

/* Line 1810 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:

/* Line 1810 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:

/* Line 1810 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:

/* Line 1810 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:

/* Line 1810 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:

/* Line 1810 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:

/* Line 1810 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:

/* Line 1810 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:

/* Line 1810 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:

/* Line 1810 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:

/* Line 1810 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:

/* Line 1810 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:

/* Line 1810 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:

/* Line 1810 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:

/* Line 1810 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:

/* Line 1810 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:

/* Line 1810 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:

/* Line 1810 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:

/* Line 1810 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:

/* Line 1810 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:

/* Line 1810 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:

/* Line 1810 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:

/* Line 1810 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:

/* Line 1810 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:

/* Line 1810 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:

/* Line 1810 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:

/* Line 1810 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:

/* Line 1810 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:

/* Line 1810 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 194:

/* Line 1810 of yacc.c  */
#line 1292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 195:

/* Line 1810 of yacc.c  */
#line 1299 "conf_parser.y"
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

  case 212:

/* Line 1810 of yacc.c  */
#line 1357 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 213:

/* Line 1810 of yacc.c  */
#line 1366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1810 of yacc.c  */
#line 1372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1810 of yacc.c  */
#line 1378 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1810 of yacc.c  */
#line 1384 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1810 of yacc.c  */
#line 1390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1810 of yacc.c  */
#line 1396 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1810 of yacc.c  */
#line 1402 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1810 of yacc.c  */
#line 1408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1810 of yacc.c  */
#line 1414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1810 of yacc.c  */
#line 1420 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1810 of yacc.c  */
#line 1426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1810 of yacc.c  */
#line 1432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1810 of yacc.c  */
#line 1441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 226:

/* Line 1810 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 227:

/* Line 1810 of yacc.c  */
#line 1457 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 231:

/* Line 1810 of yacc.c  */
#line 1463 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 232:

/* Line 1810 of yacc.c  */
#line 1467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 233:

/* Line 1810 of yacc.c  */
#line 1471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 241:

/* Line 1810 of yacc.c  */
#line 1481 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 245:

/* Line 1810 of yacc.c  */
#line 1486 "conf_parser.y"
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

  case 246:

/* Line 1810 of yacc.c  */
#line 1500 "conf_parser.y"
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

  case 247:

/* Line 1810 of yacc.c  */
#line 1520 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 248:

/* Line 1810 of yacc.c  */
#line 1529 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:

/* Line 1810 of yacc.c  */
#line 1541 "conf_parser.y"
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

  case 250:

/* Line 1810 of yacc.c  */
#line 1553 "conf_parser.y"
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

  case 262:

/* Line 1810 of yacc.c  */
#line 1615 "conf_parser.y"
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

  case 263:

/* Line 1810 of yacc.c  */
#line 1650 "conf_parser.y"
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

  case 264:

/* Line 1810 of yacc.c  */
#line 1663 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 265:

/* Line 1810 of yacc.c  */
#line 1672 "conf_parser.y"
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

  case 266:

/* Line 1810 of yacc.c  */
#line 1683 "conf_parser.y"
    {
}
    break;

  case 270:

/* Line 1810 of yacc.c  */
#line 1688 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 271:

/* Line 1810 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 272:

/* Line 1810 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 273:

/* Line 1810 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 274:

/* Line 1810 of yacc.c  */
#line 1704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 275:

/* Line 1810 of yacc.c  */
#line 1708 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 276:

/* Line 1810 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 277:

/* Line 1810 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 278:

/* Line 1810 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 279:

/* Line 1810 of yacc.c  */
#line 1727 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 280:

/* Line 1810 of yacc.c  */
#line 1746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 281:

/* Line 1810 of yacc.c  */
#line 1756 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 282:

/* Line 1810 of yacc.c  */
#line 1769 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 283:

/* Line 1810 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 290:

/* Line 1810 of yacc.c  */
#line 1788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 291:

/* Line 1810 of yacc.c  */
#line 1797 "conf_parser.y"
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

  case 292:

/* Line 1810 of yacc.c  */
#line 1812 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 298:

/* Line 1810 of yacc.c  */
#line 1830 "conf_parser.y"
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

  case 299:

/* Line 1810 of yacc.c  */
#line 1845 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 300:

/* Line 1810 of yacc.c  */
#line 1853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 307:

/* Line 1810 of yacc.c  */
#line 1864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 308:

/* Line 1810 of yacc.c  */
#line 1873 "conf_parser.y"
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

  case 309:

/* Line 1810 of yacc.c  */
#line 1895 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 313:

/* Line 1810 of yacc.c  */
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 314:

/* Line 1810 of yacc.c  */
#line 1906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 315:

/* Line 1810 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 316:

/* Line 1810 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 317:

/* Line 1810 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 318:

/* Line 1810 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 319:

/* Line 1810 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 320:

/* Line 1810 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 321:

/* Line 1810 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 322:

/* Line 1810 of yacc.c  */
#line 1938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 323:

/* Line 1810 of yacc.c  */
#line 1947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 324:

/* Line 1810 of yacc.c  */
#line 1954 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 330:

/* Line 1810 of yacc.c  */
#line 1967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 331:

/* Line 1810 of yacc.c  */
#line 1973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 335:

/* Line 1810 of yacc.c  */
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 336:

/* Line 1810 of yacc.c  */
#line 1984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 337:

/* Line 1810 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 338:

/* Line 1810 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 339:

/* Line 1810 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 340:

/* Line 1810 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 341:

/* Line 1810 of yacc.c  */
#line 2004 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 342:

/* Line 1810 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 343:

/* Line 1810 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 344:

/* Line 1810 of yacc.c  */
#line 2016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 345:

/* Line 1810 of yacc.c  */
#line 2025 "conf_parser.y"
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

  case 346:

/* Line 1810 of yacc.c  */
#line 2040 "conf_parser.y"
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

  case 363:

/* Line 1810 of yacc.c  */
#line 2084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 364:

/* Line 1810 of yacc.c  */
#line 2093 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 365:

/* Line 1810 of yacc.c  */
#line 2102 "conf_parser.y"
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

  case 366:

/* Line 1810 of yacc.c  */
#line 2128 "conf_parser.y"
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

  case 367:

/* Line 1810 of yacc.c  */
#line 2146 "conf_parser.y"
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

  case 368:

/* Line 1810 of yacc.c  */
#line 2164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 369:

/* Line 1810 of yacc.c  */
#line 2170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 370:

/* Line 1810 of yacc.c  */
#line 2174 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 371:

/* Line 1810 of yacc.c  */
#line 2182 "conf_parser.y"
    {
}
    break;

  case 375:

/* Line 1810 of yacc.c  */
#line 2187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 376:

/* Line 1810 of yacc.c  */
#line 2191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 377:

/* Line 1810 of yacc.c  */
#line 2195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 378:

/* Line 1810 of yacc.c  */
#line 2199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 379:

/* Line 1810 of yacc.c  */
#line 2205 "conf_parser.y"
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

  case 380:

/* Line 1810 of yacc.c  */
#line 2216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 381:

/* Line 1810 of yacc.c  */
#line 2227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 382:

/* Line 1810 of yacc.c  */
#line 2238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 383:

/* Line 1810 of yacc.c  */
#line 2247 "conf_parser.y"
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

  case 384:

/* Line 1810 of yacc.c  */
#line 2265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 385:

/* Line 1810 of yacc.c  */
#line 2272 "conf_parser.y"
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

  case 386:

/* Line 1810 of yacc.c  */
#line 2330 "conf_parser.y"
    {
}
    break;

  case 390:

/* Line 1810 of yacc.c  */
#line 2335 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 397:

/* Line 1810 of yacc.c  */
#line 2344 "conf_parser.y"
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

  case 398:

/* Line 1810 of yacc.c  */
#line 2363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 399:

/* Line 1810 of yacc.c  */
#line 2372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 400:

/* Line 1810 of yacc.c  */
#line 2376 "conf_parser.y"
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

  case 406:

/* Line 1810 of yacc.c  */
#line 2400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 407:

/* Line 1810 of yacc.c  */
#line 2406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 413:

/* Line 1810 of yacc.c  */
#line 2420 "conf_parser.y"
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

  case 414:

/* Line 1810 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 415:

/* Line 1810 of yacc.c  */
#line 2445 "conf_parser.y"
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

  case 416:

/* Line 1810 of yacc.c  */
#line 2485 "conf_parser.y"
    {
}
    break;

  case 420:

/* Line 1810 of yacc.c  */
#line 2490 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 427:

/* Line 1810 of yacc.c  */
#line 2499 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 428:

/* Line 1810 of yacc.c  */
#line 2505 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 487:

/* Line 1810 of yacc.c  */
#line 2551 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:

/* Line 1810 of yacc.c  */
#line 2556 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 489:

/* Line 1810 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:

/* Line 1810 of yacc.c  */
#line 2568 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1810 of yacc.c  */
#line 2574 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1810 of yacc.c  */
#line 2579 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:

/* Line 1810 of yacc.c  */
#line 2584 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 494:

/* Line 1810 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 495:

/* Line 1810 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 496:

/* Line 1810 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:

/* Line 1810 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 498:

/* Line 1810 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 499:

/* Line 1810 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 500:

/* Line 1810 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 501:

/* Line 1810 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 502:

/* Line 1810 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 503:

/* Line 1810 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:

/* Line 1810 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1810 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1810 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:

/* Line 1810 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:

/* Line 1810 of yacc.c  */
#line 2660 "conf_parser.y"
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

  case 509:

/* Line 1810 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 510:

/* Line 1810 of yacc.c  */
#line 2676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 511:

/* Line 1810 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 512:

/* Line 1810 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 513:

/* Line 1810 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 514:

/* Line 1810 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 515:

/* Line 1810 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 516:

/* Line 1810 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 517:

/* Line 1810 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 518:

/* Line 1810 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 519:

/* Line 1810 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 520:

/* Line 1810 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:

/* Line 1810 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1810 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 523:

/* Line 1810 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:

/* Line 1810 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 525:

/* Line 1810 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 526:

/* Line 1810 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 527:

/* Line 1810 of yacc.c  */
#line 2761 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 528:

/* Line 1810 of yacc.c  */
#line 2766 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 529:

/* Line 1810 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:

/* Line 1810 of yacc.c  */
#line 2782 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:

/* Line 1810 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 532:

/* Line 1810 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 533:

/* Line 1810 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 534:

/* Line 1810 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 535:

/* Line 1810 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 536:

/* Line 1810 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 537:

/* Line 1810 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 541:

/* Line 1810 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 542:

/* Line 1810 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 543:

/* Line 1810 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 544:

/* Line 1810 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 545:

/* Line 1810 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 546:

/* Line 1810 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 547:

/* Line 1810 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 548:

/* Line 1810 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 549:

/* Line 1810 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 550:

/* Line 1810 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 551:

/* Line 1810 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 552:

/* Line 1810 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 553:

/* Line 1810 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 554:

/* Line 1810 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 555:

/* Line 1810 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 556:

/* Line 1810 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 557:

/* Line 1810 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 558:

/* Line 1810 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 559:

/* Line 1810 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 560:

/* Line 1810 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 561:

/* Line 1810 of yacc.c  */
#line 2893 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 565:

/* Line 1810 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 566:

/* Line 1810 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 567:

/* Line 1810 of yacc.c  */
#line 2905 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 568:

/* Line 1810 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 569:

/* Line 1810 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 570:

/* Line 1810 of yacc.c  */
#line 2914 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 571:

/* Line 1810 of yacc.c  */
#line 2917 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 572:

/* Line 1810 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 573:

/* Line 1810 of yacc.c  */
#line 2923 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 574:

/* Line 1810 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 575:

/* Line 1810 of yacc.c  */
#line 2929 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 576:

/* Line 1810 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 577:

/* Line 1810 of yacc.c  */
#line 2935 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 578:

/* Line 1810 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 579:

/* Line 1810 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 580:

/* Line 1810 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 581:

/* Line 1810 of yacc.c  */
#line 2947 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 582:

/* Line 1810 of yacc.c  */
#line 2950 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 583:

/* Line 1810 of yacc.c  */
#line 2953 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 584:

/* Line 1810 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 585:

/* Line 1810 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:

/* Line 1810 of yacc.c  */
#line 2966 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:

/* Line 1810 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:

/* Line 1810 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:

/* Line 1810 of yacc.c  */
#line 3000 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 612:

/* Line 1810 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 613:

/* Line 1810 of yacc.c  */
#line 3010 "conf_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 614:

/* Line 1810 of yacc.c  */
#line 3015 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 615:

/* Line 1810 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 616:

/* Line 1810 of yacc.c  */
#line 3025 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 617:

/* Line 1810 of yacc.c  */
#line 3030 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:

/* Line 1810 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:

/* Line 1810 of yacc.c  */
#line 3040 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:

/* Line 1810 of yacc.c  */
#line 3045 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:

/* Line 1810 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 622:

/* Line 1810 of yacc.c  */
#line 3055 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:

/* Line 1810 of yacc.c  */
#line 3060 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:

/* Line 1810 of yacc.c  */
#line 3065 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:

/* Line 1810 of yacc.c  */
#line 3070 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 626:

/* Line 1810 of yacc.c  */
#line 3075 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 627:

/* Line 1810 of yacc.c  */
#line 3080 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 628:

/* Line 1810 of yacc.c  */
#line 3085 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 640:

/* Line 1810 of yacc.c  */
#line 3104 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 641:

/* Line 1810 of yacc.c  */
#line 3110 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 642:

/* Line 1810 of yacc.c  */
#line 3116 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 643:

/* Line 1810 of yacc.c  */
#line 3125 "conf_parser.y"
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

  case 644:

/* Line 1810 of yacc.c  */
#line 3139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 645:

/* Line 1810 of yacc.c  */
#line 3145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 646:

/* Line 1810 of yacc.c  */
#line 3151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1810 of yacc.c  */
#line 7390 "conf_parser.c"
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



