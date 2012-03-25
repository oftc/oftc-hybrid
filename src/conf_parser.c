/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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
#line 25 "ircd_parser.y"


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

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static dlink_list hub_conf_list  = { NULL, NULL, 0 };
static dlink_list leaf_conf_list = { NULL, NULL, 0 };
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

static void
unhook_hub_leaf_confs(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct CollectItem *yy_hconf;
  struct CollectItem *yy_lconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
  {
    yy_hconf = ptr->data;
    dlinkDelete(&yy_hconf->node, &hub_conf_list);
    free_collect_item(yy_hconf);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
  {
    yy_lconf = ptr->data;
    dlinkDelete(&yy_lconf->node, &leaf_conf_list);
    free_collect_item(yy_lconf);
  }
}



/* Line 268 of yacc.c  */
#line 180 "ircd_parser.c"

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
     BURST_TOPICWHO = 268,
     BYTES = 269,
     KBYTES = 270,
     MBYTES = 271,
     GBYTES = 272,
     TBYTES = 273,
     CALLER_ID_WAIT = 274,
     CAN_FLOOD = 275,
     CHANNEL = 276,
     CIDR_BITLEN_IPV4 = 277,
     CIDR_BITLEN_IPV6 = 278,
     CLASS = 279,
     CONNECT = 280,
     CONNECTFREQ = 281,
     DEFAULT_FLOODCOUNT = 282,
     DEFAULT_SPLIT_SERVER_COUNT = 283,
     DEFAULT_SPLIT_USER_COUNT = 284,
     DENY = 285,
     DESCRIPTION = 286,
     DIE = 287,
     DISABLE_AUTH = 288,
     DISABLE_FAKE_CHANNELS = 289,
     DISABLE_HIDDEN = 290,
     DISABLE_LOCAL_CHANNELS = 291,
     DISABLE_REMOTE_COMMANDS = 292,
     DOTS_IN_IDENT = 293,
     DURATION = 294,
     EGDPOOL_PATH = 295,
     EMAIL = 296,
     ENABLE = 297,
     ENCRYPTED = 298,
     EXCEED_LIMIT = 299,
     EXEMPT = 300,
     FAILED_OPER_NOTICE = 301,
     IRCD_FLAGS = 302,
     FLATTEN_LINKS = 303,
     GECOS = 304,
     GENERAL = 305,
     GLINE = 306,
     GLINES = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
     GLINE_MIN_CIDR = 310,
     GLINE_MIN_CIDR6 = 311,
     GLOBAL_KILL = 312,
     IRCD_AUTH = 313,
     NEED_IDENT = 314,
     HAVENT_READ_CONF = 315,
     HIDDEN = 316,
     HIDDEN_NAME = 317,
     HIDE_SERVER_IPS = 318,
     HIDE_SERVERS = 319,
     HIDE_SPOOF_IPS = 320,
     HOST = 321,
     HUB = 322,
     HUB_MASK = 323,
     IGNORE_BOGUS_TS = 324,
     INVISIBLE_ON_CONNECT = 325,
     IP = 326,
     KILL = 327,
     KILL_CHASE_TIME_LIMIT = 328,
     KLINE = 329,
     KLINE_EXEMPT = 330,
     KLINE_REASON = 331,
     KLINE_WITH_REASON = 332,
     KNOCK_DELAY = 333,
     KNOCK_DELAY_CHANNEL = 334,
     LEAF_MASK = 335,
     LINKS_DELAY = 336,
     LISTEN = 337,
     T_LOG = 338,
     MAX_ACCEPT = 339,
     MAX_BANS = 340,
     MAX_CHANS_PER_USER = 341,
     MAX_GLOBAL = 342,
     MAX_IDENT = 343,
     MAX_LOCAL = 344,
     MAX_NICK_CHANGES = 345,
     MAX_NICK_TIME = 346,
     MAX_NUMBER = 347,
     MAX_TARGETS = 348,
     MAX_WATCH = 349,
     MESSAGE_LOCALE = 350,
     MIN_NONWILDCARD = 351,
     MIN_NONWILDCARD_SIMPLE = 352,
     MODULE = 353,
     MODULES = 354,
     NAME = 355,
     NEED_PASSWORD = 356,
     NETWORK_DESC = 357,
     NETWORK_NAME = 358,
     NICK = 359,
     NICK_CHANGES = 360,
     NO_CREATE_ON_SPLIT = 361,
     NO_JOIN_ON_SPLIT = 362,
     NO_OPER_FLOOD = 363,
     NO_TILDE = 364,
     NUMBER = 365,
     NUMBER_PER_IDENT = 366,
     NUMBER_PER_CIDR = 367,
     NUMBER_PER_IP = 368,
     NUMBER_PER_IP_GLOBAL = 369,
     OPERATOR = 370,
     OPERS_BYPASS_CALLERID = 371,
     OPER_ONLY_UMODES = 372,
     OPER_PASS_RESV = 373,
     OPER_SPY_T = 374,
     OPER_UMODES = 375,
     JOIN_FLOOD_COUNT = 376,
     JOIN_FLOOD_TIME = 377,
     PACE_WAIT = 378,
     PACE_WAIT_SIMPLE = 379,
     PASSWORD = 380,
     PATH = 381,
     PING_COOKIE = 382,
     PING_TIME = 383,
     PING_WARNING = 384,
     PORT = 385,
     QSTRING = 386,
     QUIET_ON_BAN = 387,
     REASON = 388,
     REDIRPORT = 389,
     REDIRSERV = 390,
     REGEX_T = 391,
     REHASH = 392,
     TREJECT_HOLD_TIME = 393,
     REMOTE = 394,
     REMOTEBAN = 395,
     RESTRICT_CHANNELS = 396,
     RESTRICTED = 397,
     RSA_PRIVATE_KEY_FILE = 398,
     RSA_PUBLIC_KEY_FILE = 399,
     SSL_CERTIFICATE_FILE = 400,
     SSL_DH_PARAM_FILE = 401,
     T_SSL_CONNECTION_METHOD = 402,
     T_SSLV3 = 403,
     T_TLSV1 = 404,
     RESV = 405,
     RESV_EXEMPT = 406,
     SECONDS = 407,
     MINUTES = 408,
     HOURS = 409,
     DAYS = 410,
     WEEKS = 411,
     SENDQ = 412,
     SEND_PASSWORD = 413,
     SERVERHIDE = 414,
     SERVERINFO = 415,
     IRCD_SID = 416,
     TKLINE_EXPIRE_NOTICES = 417,
     T_SHARED = 418,
     T_CLUSTER = 419,
     TYPE = 420,
     SHORT_MOTD = 421,
     SILENT = 422,
     SPOOF = 423,
     SPOOF_NOTICE = 424,
     STATS_E_DISABLED = 425,
     STATS_I_OPER_ONLY = 426,
     STATS_K_OPER_ONLY = 427,
     STATS_O_OPER_ONLY = 428,
     STATS_P_OPER_ONLY = 429,
     TBOOL = 430,
     TMASKED = 431,
     T_REJECT = 432,
     TS_MAX_DELTA = 433,
     TS_WARN_DELTA = 434,
     TWODOTS = 435,
     T_ALL = 436,
     T_BOTS = 437,
     T_SOFTCALLERID = 438,
     T_CALLERID = 439,
     T_CCONN = 440,
     T_CCONN_FULL = 441,
     T_SSL_CIPHER_LIST = 442,
     T_CLIENT_FLOOD = 443,
     T_DEAF = 444,
     T_DEBUG = 445,
     T_DLINE = 446,
     T_DRONE = 447,
     T_EXTERNAL = 448,
     T_FULL = 449,
     T_INVISIBLE = 450,
     T_IPV4 = 451,
     T_IPV6 = 452,
     T_LOCOPS = 453,
     T_MAX_CLIENTS = 454,
     T_NCHANGE = 455,
     T_OPERWALL = 456,
     T_REJ = 457,
     T_SERVER = 458,
     T_SERVNOTICE = 459,
     T_SKILL = 460,
     T_SPY = 461,
     T_SSL = 462,
     T_UMODES = 463,
     T_UNAUTH = 464,
     T_UNDLINE = 465,
     T_UNLIMITED = 466,
     T_UNRESV = 467,
     T_UNXLINE = 468,
     T_GLOBOPS = 469,
     T_WALLOP = 470,
     T_RESTART = 471,
     T_SERVICE = 472,
     T_SERVICES_NAME = 473,
     T_TIMESTAMP = 474,
     THROTTLE_TIME = 475,
     TOPICBURST = 476,
     TRUE_NO_OPER_FLOOD = 477,
     TKLINE = 478,
     TXLINE = 479,
     TRESV = 480,
     UNKLINE = 481,
     USER = 482,
     USE_EGD = 483,
     USE_EXCEPT = 484,
     USE_INVEX = 485,
     USE_KNOCK = 486,
     USE_LOGGING = 487,
     USE_WHOIS_ACTUALLY = 488,
     VHOST = 489,
     VHOST6 = 490,
     XLINE = 491,
     WARN = 492,
     WARN_NO_NLINE = 493,
     T_SIZE = 494,
     T_FILE = 495
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
#define BURST_TOPICWHO 268
#define BYTES 269
#define KBYTES 270
#define MBYTES 271
#define GBYTES 272
#define TBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CHANNEL 276
#define CIDR_BITLEN_IPV4 277
#define CIDR_BITLEN_IPV6 278
#define CLASS 279
#define CONNECT 280
#define CONNECTFREQ 281
#define DEFAULT_FLOODCOUNT 282
#define DEFAULT_SPLIT_SERVER_COUNT 283
#define DEFAULT_SPLIT_USER_COUNT 284
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_HIDDEN 290
#define DISABLE_LOCAL_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DOTS_IN_IDENT 293
#define DURATION 294
#define EGDPOOL_PATH 295
#define EMAIL 296
#define ENABLE 297
#define ENCRYPTED 298
#define EXCEED_LIMIT 299
#define EXEMPT 300
#define FAILED_OPER_NOTICE 301
#define IRCD_FLAGS 302
#define FLATTEN_LINKS 303
#define GECOS 304
#define GENERAL 305
#define GLINE 306
#define GLINES 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
#define GLINE_MIN_CIDR 310
#define GLINE_MIN_CIDR6 311
#define GLOBAL_KILL 312
#define IRCD_AUTH 313
#define NEED_IDENT 314
#define HAVENT_READ_CONF 315
#define HIDDEN 316
#define HIDDEN_NAME 317
#define HIDE_SERVER_IPS 318
#define HIDE_SERVERS 319
#define HIDE_SPOOF_IPS 320
#define HOST 321
#define HUB 322
#define HUB_MASK 323
#define IGNORE_BOGUS_TS 324
#define INVISIBLE_ON_CONNECT 325
#define IP 326
#define KILL 327
#define KILL_CHASE_TIME_LIMIT 328
#define KLINE 329
#define KLINE_EXEMPT 330
#define KLINE_REASON 331
#define KLINE_WITH_REASON 332
#define KNOCK_DELAY 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LINKS_DELAY 336
#define LISTEN 337
#define T_LOG 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANS_PER_USER 341
#define MAX_GLOBAL 342
#define MAX_IDENT 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_TIME 346
#define MAX_NUMBER 347
#define MAX_TARGETS 348
#define MAX_WATCH 349
#define MESSAGE_LOCALE 350
#define MIN_NONWILDCARD 351
#define MIN_NONWILDCARD_SIMPLE 352
#define MODULE 353
#define MODULES 354
#define NAME 355
#define NEED_PASSWORD 356
#define NETWORK_DESC 357
#define NETWORK_NAME 358
#define NICK 359
#define NICK_CHANGES 360
#define NO_CREATE_ON_SPLIT 361
#define NO_JOIN_ON_SPLIT 362
#define NO_OPER_FLOOD 363
#define NO_TILDE 364
#define NUMBER 365
#define NUMBER_PER_IDENT 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP 368
#define NUMBER_PER_IP_GLOBAL 369
#define OPERATOR 370
#define OPERS_BYPASS_CALLERID 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
#define OPER_SPY_T 374
#define OPER_UMODES 375
#define JOIN_FLOOD_COUNT 376
#define JOIN_FLOOD_TIME 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PING_WARNING 384
#define PORT 385
#define QSTRING 386
#define QUIET_ON_BAN 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REGEX_T 391
#define REHASH 392
#define TREJECT_HOLD_TIME 393
#define REMOTE 394
#define REMOTEBAN 395
#define RESTRICT_CHANNELS 396
#define RESTRICTED 397
#define RSA_PRIVATE_KEY_FILE 398
#define RSA_PUBLIC_KEY_FILE 399
#define SSL_CERTIFICATE_FILE 400
#define SSL_DH_PARAM_FILE 401
#define T_SSL_CONNECTION_METHOD 402
#define T_SSLV3 403
#define T_TLSV1 404
#define RESV 405
#define RESV_EXEMPT 406
#define SECONDS 407
#define MINUTES 408
#define HOURS 409
#define DAYS 410
#define WEEKS 411
#define SENDQ 412
#define SEND_PASSWORD 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define IRCD_SID 416
#define TKLINE_EXPIRE_NOTICES 417
#define T_SHARED 418
#define T_CLUSTER 419
#define TYPE 420
#define SHORT_MOTD 421
#define SILENT 422
#define SPOOF 423
#define SPOOF_NOTICE 424
#define STATS_E_DISABLED 425
#define STATS_I_OPER_ONLY 426
#define STATS_K_OPER_ONLY 427
#define STATS_O_OPER_ONLY 428
#define STATS_P_OPER_ONLY 429
#define TBOOL 430
#define TMASKED 431
#define T_REJECT 432
#define TS_MAX_DELTA 433
#define TS_WARN_DELTA 434
#define TWODOTS 435
#define T_ALL 436
#define T_BOTS 437
#define T_SOFTCALLERID 438
#define T_CALLERID 439
#define T_CCONN 440
#define T_CCONN_FULL 441
#define T_SSL_CIPHER_LIST 442
#define T_CLIENT_FLOOD 443
#define T_DEAF 444
#define T_DEBUG 445
#define T_DLINE 446
#define T_DRONE 447
#define T_EXTERNAL 448
#define T_FULL 449
#define T_INVISIBLE 450
#define T_IPV4 451
#define T_IPV6 452
#define T_LOCOPS 453
#define T_MAX_CLIENTS 454
#define T_NCHANGE 455
#define T_OPERWALL 456
#define T_REJ 457
#define T_SERVER 458
#define T_SERVNOTICE 459
#define T_SKILL 460
#define T_SPY 461
#define T_SSL 462
#define T_UMODES 463
#define T_UNAUTH 464
#define T_UNDLINE 465
#define T_UNLIMITED 466
#define T_UNRESV 467
#define T_UNXLINE 468
#define T_GLOBOPS 469
#define T_WALLOP 470
#define T_RESTART 471
#define T_SERVICE 472
#define T_SERVICES_NAME 473
#define T_TIMESTAMP 474
#define THROTTLE_TIME 475
#define TOPICBURST 476
#define TRUE_NO_OPER_FLOOD 477
#define TKLINE 478
#define TXLINE 479
#define TRESV 480
#define UNKLINE 481
#define USER 482
#define USE_EGD 483
#define USE_EXCEPT 484
#define USE_INVEX 485
#define USE_KNOCK 486
#define USE_LOGGING 487
#define USE_WHOIS_ACTUALLY 488
#define VHOST 489
#define VHOST6 490
#define XLINE 491
#define WARN 492
#define WARN_NO_NLINE 493
#define T_SIZE 494
#define T_FILE 495




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 133 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 703 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 715 "ircd_parser.c"

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
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  246
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  304
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1307

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   245,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   241,
       2,   244,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,     2,   242,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    52,    55,    56,    58,
      61,    65,    69,    73,    77,    81,    82,    84,    87,    91,
      95,    99,   105,   108,   110,   112,   114,   117,   122,   127,
     133,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   169,   170,   176,
     180,   182,   184,   186,   191,   196,   201,   206,   211,   216,
     221,   226,   231,   236,   241,   246,   251,   257,   260,   262,
     264,   266,   268,   271,   276,   281,   286,   292,   295,   297,
     299,   301,   303,   306,   311,   316,   317,   324,   327,   329,
     331,   333,   335,   338,   343,   348,   353,   354,   360,   364,
     366,   368,   370,   372,   374,   376,   378,   380,   381,   388,
     391,   393,   395,   397,   399,   401,   403,   405,   407,   409,
     412,   417,   422,   427,   432,   437,   442,   443,   449,   453,
     455,   457,   459,   461,   463,   465,   467,   469,   471,   473,
     475,   477,   479,   481,   483,   485,   487,   489,   491,   493,
     495,   496,   502,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   528,   530,   532,   534,   536,   538,
     540,   542,   544,   545,   552,   555,   557,   559,   561,   563,
     565,   567,   569,   571,   573,   575,   577,   579,   581,   583,
     586,   591,   596,   601,   606,   611,   616,   621,   626,   631,
     636,   641,   646,   651,   652,   659,   660,   666,   670,   672,
     674,   676,   678,   681,   683,   685,   687,   689,   691,   694,
     695,   701,   705,   707,   709,   713,   718,   723,   724,   731,
     734,   736,   738,   740,   742,   744,   746,   748,   750,   752,
     755,   760,   765,   770,   775,   776,   782,   786,   788,   790,
     792,   794,   796,   798,   800,   802,   804,   806,   811,   816,
     821,   822,   829,   832,   834,   836,   838,   840,   843,   848,
     853,   858,   864,   867,   869,   871,   873,   878,   879,   886,
     889,   891,   893,   895,   897,   900,   905,   910,   911,   917,
     921,   923,   925,   927,   929,   931,   933,   935,   937,   939,
     941,   943,   944,   951,   954,   956,   958,   960,   963,   968,
     969,   975,   979,   981,   983,   985,   987,   989,   991,   993,
     995,   997,   999,  1001,  1002,  1009,  1012,  1014,  1016,  1018,
    1020,  1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,
    1040,  1043,  1048,  1053,  1058,  1063,  1068,  1073,  1078,  1083,
    1084,  1090,  1094,  1096,  1098,  1100,  1102,  1104,  1109,  1114,
    1119,  1124,  1129,  1130,  1137,  1138,  1144,  1148,  1150,  1152,
    1155,  1157,  1159,  1161,  1163,  1165,  1170,  1175,  1176,  1183,
    1186,  1188,  1190,  1192,  1194,  1199,  1204,  1210,  1213,  1215,
    1217,  1219,  1224,  1225,  1232,  1233,  1239,  1243,  1245,  1247,
    1250,  1252,  1254,  1256,  1258,  1260,  1265,  1270,  1276,  1279,
    1281,  1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,
    1301,  1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,
    1321,  1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,
    1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,
    1361,  1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,
    1381,  1383,  1385,  1390,  1395,  1400,  1405,  1410,  1415,  1420,
    1425,  1430,  1435,  1440,  1445,  1450,  1455,  1460,  1465,  1470,
    1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,  1515,  1520,
    1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,  1565,  1570,
    1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,  1615,  1620,
    1621,  1627,  1631,  1633,  1635,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1669,  1671,  1673,  1674,  1680,  1684,  1686,  1688,  1690,
    1692,  1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,
    1712,  1714,  1716,  1718,  1720,  1722,  1724,  1726,  1731,  1736,
    1741,  1746,  1747,  1754,  1757,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1773,  1778,  1783,  1784,  1790,  1794,  1796,  1798,
    1800,  1805,  1810,  1811,  1817,  1821,  1823,  1825,  1827,  1833,
    1836,  1838,  1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,
    1856,  1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,
    1876,  1881,  1886,  1891,  1896,  1901,  1906,  1911,  1916,  1921,
    1926,  1931,  1936,  1941,  1946,  1951,  1956,  1961,  1966,  1972,
    1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,  1991,  1993,
    1998,  2003,  2008,  2013,  2018,  2023
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     247,     0,    -1,    -1,   247,   248,    -1,   278,    -1,   284,
      -1,   299,    -1,   519,    -1,   317,    -1,   334,    -1,   348,
      -1,   258,    -1,   540,    -1,   363,    -1,   370,    -1,   374,
      -1,   384,    -1,   393,    -1,   413,    -1,   423,    -1,   429,
      -1,   443,    -1,   503,    -1,   433,    -1,   253,    -1,     1,
     241,    -1,     1,   242,    -1,    -1,   250,    -1,   110,   249,
      -1,   110,   152,   249,    -1,   110,   153,   249,    -1,   110,
     154,   249,    -1,   110,   155,   249,    -1,   110,   156,   249,
      -1,    -1,   252,    -1,   110,   251,    -1,   110,    14,   251,
      -1,   110,    15,   251,    -1,   110,    16,   251,    -1,    99,
     243,   254,   242,   241,    -1,   254,   255,    -1,   255,    -1,
     256,    -1,   257,    -1,     1,   241,    -1,    98,   244,   131,
     241,    -1,   126,   244,   131,   241,    -1,   160,   243,   259,
     242,   241,    -1,   259,   260,    -1,   260,    -1,   269,    -1,
     274,    -1,   277,    -1,   271,    -1,   272,    -1,   273,    -1,
     276,    -1,   267,    -1,   266,    -1,   275,    -1,   270,    -1,
     265,    -1,   261,    -1,   268,    -1,     1,   241,    -1,    -1,
     147,   262,   244,   263,   241,    -1,   263,   245,   264,    -1,
     264,    -1,   148,    -1,   149,    -1,   145,   244,   131,   241,
      -1,   143,   244,   131,   241,    -1,   146,   244,   131,   241,
      -1,   187,   244,   131,   241,    -1,   100,   244,   131,   241,
      -1,   161,   244,   131,   241,    -1,    31,   244,   131,   241,
      -1,   103,   244,   131,   241,    -1,   102,   244,   131,   241,
      -1,   234,   244,   131,   241,    -1,   235,   244,   131,   241,
      -1,   199,   244,   110,   241,    -1,    67,   244,   175,   241,
      -1,     5,   243,   279,   242,   241,    -1,   279,   280,    -1,
     280,    -1,   281,    -1,   283,    -1,   282,    -1,     1,   241,
      -1,   100,   244,   131,   241,    -1,    41,   244,   131,   241,
      -1,    31,   244,   131,   241,    -1,    83,   243,   285,   242,
     241,    -1,   285,   286,    -1,   286,    -1,   287,    -1,   288,
      -1,   289,    -1,     1,   241,    -1,   232,   244,   175,   241,
      -1,   219,   244,   175,   241,    -1,    -1,   290,   240,   243,
     291,   242,   241,    -1,   291,   292,    -1,   292,    -1,   293,
      -1,   295,    -1,   294,    -1,     1,   241,    -1,   100,   244,
     131,   241,    -1,   239,   244,   252,   241,    -1,   239,   244,
     211,   241,    -1,    -1,   165,   296,   244,   297,   241,    -1,
     297,   245,   298,    -1,   298,    -1,   227,    -1,   115,    -1,
      51,    -1,   191,    -1,    74,    -1,    72,    -1,   190,    -1,
      -1,   115,   300,   243,   301,   242,   241,    -1,   301,   302,
      -1,   302,    -1,   303,    -1,   304,    -1,   305,    -1,   309,
      -1,   308,    -1,   306,    -1,   307,    -1,   313,    -1,     1,
     241,    -1,   100,   244,   131,   241,    -1,   227,   244,   131,
     241,    -1,   125,   244,   131,   241,    -1,    43,   244,   175,
     241,    -1,   144,   244,   131,   241,    -1,    24,   244,   131,
     241,    -1,    -1,   208,   310,   244,   311,   241,    -1,   311,
     245,   312,    -1,   312,    -1,   182,    -1,   185,    -1,   186,
      -1,   189,    -1,   190,    -1,   194,    -1,    61,    -1,   205,
      -1,   200,    -1,   202,    -1,   209,    -1,   206,    -1,   193,
      -1,   201,    -1,   204,    -1,   195,    -1,   215,    -1,   183,
      -1,   184,    -1,   198,    -1,    -1,    47,   314,   244,   315,
     241,    -1,   315,   245,   316,    -1,   316,    -1,    57,    -1,
     139,    -1,    74,    -1,   226,    -1,   191,    -1,   210,    -1,
     236,    -1,    51,    -1,    32,    -1,   216,    -1,   137,    -1,
       5,    -1,   105,    -1,   201,    -1,   214,    -1,   119,    -1,
     140,    -1,    98,    -1,    -1,    24,   318,   243,   319,   242,
     241,    -1,   319,   320,    -1,   320,    -1,   321,    -1,   331,
      -1,   332,    -1,   322,    -1,   323,    -1,   333,    -1,   324,
      -1,   325,    -1,   326,    -1,   327,    -1,   328,    -1,   329,
      -1,   330,    -1,     1,   241,    -1,   100,   244,   131,   241,
      -1,   128,   244,   250,   241,    -1,   129,   244,   250,   241,
      -1,   113,   244,   110,   241,    -1,    26,   244,   250,   241,
      -1,    92,   244,   110,   241,    -1,    87,   244,   110,   241,
      -1,    89,   244,   110,   241,    -1,    88,   244,   110,   241,
      -1,   157,   244,   252,   241,    -1,    22,   244,   110,   241,
      -1,    23,   244,   110,   241,    -1,   112,   244,   110,   241,
      -1,    -1,    82,   335,   243,   340,   242,   241,    -1,    -1,
      47,   337,   244,   338,   241,    -1,   338,   245,   339,    -1,
     339,    -1,   207,    -1,    61,    -1,   203,    -1,   340,   341,
      -1,   341,    -1,   342,    -1,   336,    -1,   346,    -1,   347,
      -1,     1,   241,    -1,    -1,   130,   244,   344,   343,   241,
      -1,   344,   245,   345,    -1,   345,    -1,   110,    -1,   110,
     180,   110,    -1,    71,   244,   131,   241,    -1,    66,   244,
     131,   241,    -1,    -1,    58,   349,   243,   350,   242,   241,
      -1,   350,   351,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   356,    -1,   360,    -1,   361,    -1,   362,    -1,
     355,    -1,     1,   241,    -1,   227,   244,   131,   241,    -1,
     125,   244,   131,   241,    -1,    24,   244,   131,   241,    -1,
      43,   244,   175,   241,    -1,    -1,    47,   357,   244,   358,
     241,    -1,   358,   245,   359,    -1,   359,    -1,   169,    -1,
      44,    -1,    75,    -1,    59,    -1,    20,    -1,   109,    -1,
      53,    -1,   151,    -1,   101,    -1,   168,   244,   131,   241,
      -1,   135,   244,   131,   241,    -1,   134,   244,   110,   241,
      -1,    -1,   150,   364,   243,   365,   242,   241,    -1,   365,
     366,    -1,   366,    -1,   367,    -1,   368,    -1,   369,    -1,
       1,   241,    -1,   133,   244,   131,   241,    -1,    21,   244,
     131,   241,    -1,   104,   244,   131,   241,    -1,   217,   243,
     371,   242,   241,    -1,   371,   372,    -1,   372,    -1,   373,
      -1,     1,    -1,   100,   244,   131,   241,    -1,    -1,   163,
     375,   243,   376,   242,   241,    -1,   376,   377,    -1,   377,
      -1,   378,    -1,   379,    -1,   380,    -1,     1,   241,    -1,
     100,   244,   131,   241,    -1,   227,   244,   131,   241,    -1,
      -1,   165,   381,   244,   382,   241,    -1,   382,   245,   383,
      -1,   383,    -1,    74,    -1,   226,    -1,   191,    -1,   210,
      -1,   236,    -1,   213,    -1,   150,    -1,   212,    -1,   198,
      -1,   181,    -1,    -1,   164,   385,   243,   386,   242,   241,
      -1,   386,   387,    -1,   387,    -1,   388,    -1,   389,    -1,
       1,   241,    -1,   100,   244,   131,   241,    -1,    -1,   165,
     390,   244,   391,   241,    -1,   391,   245,   392,    -1,   392,
      -1,    74,    -1,   226,    -1,   191,    -1,   210,    -1,   236,
      -1,   213,    -1,   150,    -1,   212,    -1,   198,    -1,   181,
      -1,    -1,    25,   394,   243,   395,   242,   241,    -1,   395,
     396,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     400,    -1,   401,    -1,   403,    -1,   402,    -1,   412,    -1,
     404,    -1,   409,    -1,   410,    -1,   411,    -1,   408,    -1,
       1,   241,    -1,   100,   244,   131,   241,    -1,    66,   244,
     131,   241,    -1,   234,   244,   131,   241,    -1,   158,   244,
     131,   241,    -1,     3,   244,   131,   241,    -1,   130,   244,
     110,   241,    -1,     6,   244,   196,   241,    -1,     6,   244,
     197,   241,    -1,    -1,    47,   405,   244,   406,   241,    -1,
     406,   245,   407,    -1,   407,    -1,    10,    -1,    12,    -1,
     221,    -1,   207,    -1,    43,   244,   175,   241,    -1,    68,
     244,   131,   241,    -1,    80,   244,   131,   241,    -1,    24,
     244,   131,   241,    -1,   187,   244,   131,   241,    -1,    -1,
      72,   414,   243,   419,   242,   241,    -1,    -1,   165,   416,
     244,   417,   241,    -1,   417,   245,   418,    -1,   418,    -1,
     136,    -1,   419,   420,    -1,   420,    -1,   421,    -1,   422,
      -1,   415,    -1,     1,    -1,   227,   244,   131,   241,    -1,
     133,   244,   131,   241,    -1,    -1,    30,   424,   243,   425,
     242,   241,    -1,   425,   426,    -1,   426,    -1,   427,    -1,
     428,    -1,     1,    -1,    71,   244,   131,   241,    -1,   133,
     244,   131,   241,    -1,    45,   243,   430,   242,   241,    -1,
     430,   431,    -1,   431,    -1,   432,    -1,     1,    -1,    71,
     244,   131,   241,    -1,    -1,    49,   434,   243,   439,   242,
     241,    -1,    -1,   165,   436,   244,   437,   241,    -1,   437,
     245,   438,    -1,   438,    -1,   136,    -1,   439,   440,    -1,
     440,    -1,   441,    -1,   442,    -1,   435,    -1,     1,    -1,
     100,   244,   131,   241,    -1,   133,   244,   131,   241,    -1,
      50,   243,   444,   242,   241,    -1,   444,   445,    -1,   445,
      -1,   453,    -1,   454,    -1,   456,    -1,   457,    -1,   458,
      -1,   459,    -1,   460,    -1,   461,    -1,   462,    -1,   463,
      -1,   452,    -1,   465,    -1,   466,    -1,   467,    -1,   468,
      -1,   483,    -1,   470,    -1,   472,    -1,   474,    -1,   473,
      -1,   477,    -1,   471,    -1,   478,    -1,   479,    -1,   480,
      -1,   481,    -1,   482,    -1,   495,    -1,   484,    -1,   485,
      -1,   486,    -1,   491,    -1,   475,    -1,   476,    -1,   501,
      -1,   499,    -1,   500,    -1,   455,    -1,   502,    -1,   490,
      -1,   464,    -1,   488,    -1,   489,    -1,   451,    -1,   447,
      -1,   448,    -1,   449,    -1,   450,    -1,   469,    -1,   446,
      -1,   487,    -1,     1,    -1,    94,   244,   110,   241,    -1,
      55,   244,   110,   241,    -1,    56,   244,   110,   241,    -1,
     233,   244,   175,   241,    -1,   138,   244,   250,   241,    -1,
     162,   244,   175,   241,    -1,    73,   244,   250,   241,    -1,
      65,   244,   175,   241,    -1,    69,   244,   175,   241,    -1,
      37,   244,   175,   241,    -1,    46,   244,   175,   241,    -1,
       8,   244,   175,   241,    -1,    91,   244,   250,   241,    -1,
      90,   244,   110,   241,    -1,    84,   244,   110,   241,    -1,
       9,   244,   250,   241,    -1,   179,   244,   250,   241,    -1,
     178,   244,   250,   241,    -1,    60,   244,   110,   241,    -1,
      77,   244,   175,   241,    -1,    76,   244,   131,   241,    -1,
      70,   244,   175,   241,    -1,   238,   244,   175,   241,    -1,
     170,   244,   175,   241,    -1,   173,   244,   175,   241,    -1,
     174,   244,   175,   241,    -1,   172,   244,   175,   241,    -1,
     172,   244,   176,   241,    -1,   171,   244,   175,   241,    -1,
     171,   244,   176,   241,    -1,   123,   244,   250,   241,    -1,
      19,   244,   250,   241,    -1,   116,   244,   175,   241,    -1,
     124,   244,   250,   241,    -1,   166,   244,   175,   241,    -1,
     108,   244,   175,   241,    -1,   222,   244,   175,   241,    -1,
     118,   244,   175,   241,    -1,    95,   244,   131,   241,    -1,
      38,   244,   110,   241,    -1,    93,   244,   110,   241,    -1,
     228,   244,   175,   241,    -1,    40,   244,   131,   241,    -1,
     218,   244,   131,   241,    -1,   127,   244,   175,   241,    -1,
      33,   244,   175,   241,    -1,   220,   244,   250,   241,    -1,
      -1,   120,   492,   244,   493,   241,    -1,   493,   245,   494,
      -1,   494,    -1,   182,    -1,   185,    -1,   186,    -1,   189,
      -1,   190,    -1,   194,    -1,    61,    -1,   205,    -1,   200,
      -1,   202,    -1,   209,    -1,   206,    -1,   193,    -1,   201,
      -1,   204,    -1,   195,    -1,   215,    -1,   183,    -1,   184,
      -1,   198,    -1,    -1,   117,   496,   244,   497,   241,    -1,
     497,   245,   498,    -1,   498,    -1,   182,    -1,   185,    -1,
     186,    -1,   189,    -1,   190,    -1,   194,    -1,   205,    -1,
      61,    -1,   200,    -1,   202,    -1,   209,    -1,   206,    -1,
     193,    -1,   201,    -1,   204,    -1,   195,    -1,   215,    -1,
     183,    -1,   184,    -1,   198,    -1,    96,   244,   110,   241,
      -1,    97,   244,   110,   241,    -1,    27,   244,   110,   241,
      -1,   188,   244,   252,   241,    -1,    -1,    52,   504,   243,
     505,   242,   241,    -1,   505,   506,    -1,   506,    -1,   507,
      -1,   508,    -1,   509,    -1,   513,    -1,   514,    -1,   515,
      -1,     1,    -1,    42,   244,   175,   241,    -1,    39,   244,
     250,   241,    -1,    -1,    83,   510,   244,   511,   241,    -1,
     511,   245,   512,    -1,   512,    -1,   177,    -1,    11,    -1,
     227,   244,   131,   241,    -1,   100,   244,   131,   241,    -1,
      -1,     4,   516,   244,   517,   241,    -1,   517,   245,   518,
      -1,   518,    -1,   177,    -1,    11,    -1,    21,   243,   520,
     242,   241,    -1,   520,   521,    -1,   521,    -1,   524,    -1,
     525,    -1,   526,    -1,   527,    -1,   532,    -1,   528,    -1,
     529,    -1,   530,    -1,   531,    -1,   533,    -1,   534,    -1,
     535,    -1,   523,    -1,   536,    -1,   537,    -1,   538,    -1,
     539,    -1,   522,    -1,     1,    -1,    34,   244,   175,   241,
      -1,   141,   244,   175,   241,    -1,    36,   244,   175,   241,
      -1,   229,   244,   175,   241,    -1,   230,   244,   175,   241,
      -1,   231,   244,   175,   241,    -1,    78,   244,   250,   241,
      -1,    79,   244,   250,   241,    -1,    86,   244,   110,   241,
      -1,   132,   244,   175,   241,    -1,    85,   244,   110,   241,
      -1,    29,   244,   110,   241,    -1,    28,   244,   110,   241,
      -1,   106,   244,   175,   241,    -1,   107,   244,   175,   241,
      -1,    13,   244,   175,   241,    -1,   121,   244,   110,   241,
      -1,   122,   244,   250,   241,    -1,   159,   243,   541,   242,
     241,    -1,   541,   542,    -1,   542,    -1,   543,    -1,   544,
      -1,   546,    -1,   548,    -1,   547,    -1,   545,    -1,   549,
      -1,     1,    -1,    48,   244,   175,   241,    -1,    64,   244,
     175,   241,    -1,    62,   244,   131,   241,    -1,    81,   244,
     250,   241,    -1,    61,   244,   175,   241,    -1,    35,   244,
     175,   241,    -1,    63,   244,   175,   241,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   377,   377,   378,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   407,   407,   408,
     412,   416,   420,   424,   428,   434,   434,   435,   436,   437,
     438,   445,   448,   448,   449,   449,   449,   451,   457,   464,
     466,   466,   467,   467,   468,   468,   469,   469,   470,   470,
     471,   471,   472,   472,   473,   473,   474,   478,   477,   503,
     503,   504,   510,   518,   557,   616,   640,   650,   665,   680,
     689,   703,   712,   740,   770,   793,   802,   804,   804,   805,
     805,   806,   806,   808,   817,   826,   838,   839,   839,   841,
     841,   841,   842,   844,   850,   857,   857,   867,   868,   870,
     870,   871,   871,   873,   878,   881,   887,   886,   892,   892,
     893,   897,   901,   905,   909,   913,   917,   928,   927,  1025,
    1025,  1026,  1026,  1026,  1027,  1027,  1027,  1028,  1028,  1028,
    1030,  1042,  1079,  1091,  1102,  1144,  1154,  1153,  1159,  1159,
    1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,  1192,  1196,
    1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,
    1243,  1242,  1248,  1248,  1249,  1253,  1257,  1261,  1265,  1269,
    1273,  1277,  1281,  1285,  1289,  1293,  1297,  1301,  1305,  1309,
    1313,  1317,  1328,  1327,  1377,  1377,  1378,  1379,  1379,  1380,
    1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
    1392,  1401,  1407,  1413,  1419,  1425,  1431,  1437,  1443,  1449,
    1455,  1461,  1467,  1477,  1476,  1493,  1492,  1497,  1497,  1498,
    1502,  1506,  1514,  1514,  1515,  1515,  1515,  1515,  1515,  1517,
    1517,  1519,  1519,  1521,  1535,  1555,  1564,  1577,  1576,  1645,
    1645,  1646,  1646,  1646,  1646,  1647,  1647,  1647,  1648,  1648,
    1650,  1687,  1700,  1709,  1721,  1720,  1724,  1724,  1725,  1729,
    1733,  1737,  1741,  1745,  1749,  1753,  1757,  1764,  1783,  1793,
    1807,  1806,  1822,  1822,  1823,  1823,  1823,  1823,  1825,  1834,
    1849,  1862,  1864,  1864,  1865,  1865,  1867,  1883,  1882,  1898,
    1898,  1899,  1899,  1899,  1899,  1901,  1910,  1933,  1932,  1938,
    1938,  1939,  1943,  1947,  1951,  1955,  1959,  1963,  1967,  1971,
    1975,  1985,  1984,  2001,  2001,  2002,  2002,  2002,  2004,  2011,
    2010,  2016,  2016,  2017,  2021,  2025,  2029,  2033,  2037,  2041,
    2045,  2049,  2053,  2063,  2062,  2191,  2191,  2192,  2192,  2192,
    2193,  2193,  2194,  2194,  2194,  2195,  2195,  2195,  2196,  2196,
    2197,  2199,  2211,  2220,  2246,  2264,  2282,  2288,  2292,  2301,
    2300,  2304,  2304,  2305,  2309,  2313,  2317,  2323,  2334,  2347,
    2360,  2369,  2388,  2387,  2451,  2450,  2454,  2454,  2455,  2461,
    2461,  2462,  2462,  2462,  2462,  2464,  2483,  2493,  2492,  2515,
    2515,  2516,  2516,  2516,  2518,  2524,  2533,  2535,  2535,  2536,
    2536,  2538,  2557,  2556,  2604,  2603,  2607,  2607,  2608,  2614,
    2614,  2615,  2615,  2615,  2615,  2617,  2623,  2632,  2635,  2635,
    2636,  2636,  2637,  2637,  2638,  2638,  2639,  2639,  2640,  2640,
    2641,  2641,  2642,  2642,  2643,  2643,  2644,  2644,  2645,  2645,
    2646,  2646,  2647,  2647,  2648,  2648,  2649,  2650,  2650,  2651,
    2651,  2652,  2652,  2653,  2653,  2654,  2654,  2655,  2656,  2657,
    2657,  2658,  2659,  2660,  2660,  2661,  2661,  2662,  2662,  2663,
    2663,  2664,  2667,  2672,  2677,  2682,  2687,  2692,  2697,  2702,
    2707,  2712,  2717,  2722,  2727,  2732,  2737,  2742,  2747,  2752,
    2758,  2769,  2774,  2783,  2788,  2793,  2798,  2803,  2808,  2811,
    2816,  2819,  2824,  2829,  2834,  2839,  2844,  2849,  2854,  2859,
    2864,  2875,  2880,  2885,  2890,  2899,  2908,  2913,  2918,  2924,
    2923,  2928,  2928,  2929,  2932,  2935,  2938,  2941,  2944,  2947,
    2950,  2953,  2956,  2959,  2962,  2965,  2968,  2971,  2974,  2977,
    2980,  2983,  2986,  2992,  2991,  2996,  2996,  2997,  3000,  3003,
    3006,  3009,  3012,  3015,  3018,  3021,  3024,  3027,  3030,  3033,
    3036,  3039,  3042,  3045,  3048,  3051,  3054,  3059,  3064,  3069,
    3074,  3084,  3083,  3107,  3107,  3108,  3109,  3110,  3111,  3112,
    3113,  3114,  3116,  3122,  3129,  3128,  3133,  3133,  3134,  3138,
    3144,  3178,  3188,  3187,  3237,  3237,  3238,  3242,  3251,  3254,
    3254,  3255,  3255,  3256,  3256,  3257,  3257,  3258,  3258,  3259,
    3259,  3260,  3261,  3261,  3262,  3262,  3263,  3263,  3264,  3264,
    3266,  3271,  3276,  3281,  3286,  3291,  3296,  3301,  3306,  3311,
    3316,  3321,  3326,  3331,  3336,  3341,  3346,  3351,  3359,  3362,
    3362,  3363,  3363,  3364,  3365,  3366,  3366,  3367,  3368,  3370,
    3376,  3382,  3391,  3405,  3411,  3417
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", "KBYTES",
  "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH",
  "EMAIL", "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINES", "GLINE_EXEMPT", "GLINE_TIME", "GLINE_MIN_CIDR",
  "GLINE_MIN_CIDR6", "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT",
  "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE",
  "T_SSL_CONNECTION_METHOD", "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF",
  "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_SSL_CIPHER_LIST", "T_CLIENT_FLOOD", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE",
  "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_OPERWALL", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "T_TIMESTAMP", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_connection_method", "$@1",
  "method_types", "method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_use_logging",
  "logging_timestamp", "logging_file_entry", "$@2", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@3", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@4", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@5",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@6",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@7",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_ping_warning", "class_number_per_ip", "class_connectfreq",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "listen_entry", "$@8",
  "listen_flags", "$@9", "listen_flags_items", "listen_flags_item",
  "listen_items", "listen_item", "listen_port", "$@10", "port_items",
  "port_item", "listen_address", "listen_host", "auth_entry", "$@11",
  "auth_items", "auth_item", "auth_user", "auth_passwd", "auth_class",
  "auth_encrypted", "auth_flags", "$@12", "auth_flags_items",
  "auth_flags_item", "auth_spoof", "auth_redir_serv", "auth_redir_port",
  "resv_entry", "$@13", "resv_items", "resv_item", "resv_creason",
  "resv_channel", "resv_nick", "service_entry", "service_items",
  "service_item", "service_name", "shared_entry", "$@14", "shared_items",
  "shared_item", "shared_name", "shared_user", "shared_type", "$@15",
  "shared_types", "shared_type_item", "cluster_entry", "$@16",
  "cluster_items", "cluster_item", "cluster_name", "cluster_type", "$@17",
  "cluster_types", "cluster_type_item", "connect_entry", "$@18",
  "connect_items", "connect_item", "connect_name", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_flags", "$@19",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@20", "kill_type", "$@21",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@22", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@23", "gecos_flags", "$@24",
  "gecos_flags_items", "gecos_flags_item", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_max_watch", "general_gline_min_cidr",
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
  "general_oper_umodes", "$@25", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@26", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "gline_entry",
  "$@27", "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "$@28", "gline_logging_types",
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action",
  "$@29", "gdeny_types", "gdeny_type_item", "channel_entry",
  "channel_items", "channel_item", "channel_disable_fake_channels",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_burst_topicwho", "channel_jflood_count", "channel_jflood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_hide_servers",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
  "serverhide_disable_hidden", "serverhide_hide_server_ips", 0
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
     495,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   246,   247,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   250,   250,   250,   250,   251,   251,   252,   252,   252,
     252,   253,   254,   254,   255,   255,   255,   256,   257,   258,
     259,   259,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   262,   261,   263,
     263,   264,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   279,   280,
     280,   280,   280,   281,   282,   283,   284,   285,   285,   286,
     286,   286,   286,   287,   288,   290,   289,   291,   291,   292,
     292,   292,   292,   293,   294,   294,   296,   295,   297,   297,
     298,   298,   298,   298,   298,   298,   298,   300,   299,   301,
     301,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     303,   304,   305,   306,   307,   308,   310,   309,   311,   311,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     314,   313,   315,   315,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   318,   317,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   335,   334,   337,   336,   338,   338,   339,
     339,   339,   340,   340,   341,   341,   341,   341,   341,   343,
     342,   344,   344,   345,   345,   346,   347,   349,   348,   350,
     350,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     352,   353,   354,   355,   357,   356,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   360,   361,   362,
     364,   363,   365,   365,   366,   366,   366,   366,   367,   368,
     369,   370,   371,   371,   372,   372,   373,   375,   374,   376,
     376,   377,   377,   377,   377,   378,   379,   381,   380,   382,
     382,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   385,   384,   386,   386,   387,   387,   387,   388,   390,
     389,   391,   391,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   394,   393,   395,   395,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   397,   398,   399,   400,   401,   402,   403,   403,   405,
     404,   406,   406,   407,   407,   407,   407,   408,   409,   410,
     411,   412,   414,   413,   416,   415,   417,   417,   418,   419,
     419,   420,   420,   420,   420,   421,   422,   424,   423,   425,
     425,   426,   426,   426,   427,   428,   429,   430,   430,   431,
     431,   432,   434,   433,   436,   435,   437,   437,   438,   439,
     439,   440,   440,   440,   440,   441,   442,   443,   444,   444,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   472,
     473,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   492,
     491,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   496,   495,   497,   497,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   499,   500,   501,
     502,   504,   503,   505,   505,   506,   506,   506,   506,   506,
     506,   506,   507,   508,   510,   509,   511,   511,   512,   512,
     513,   514,   516,   515,   517,   517,   518,   518,   519,   520,
     520,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     541,   542,   542,   542,   542,   542,   542,   542,   542,   543,
     544,   545,   546,   547,   548,   549
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     1,     2,
       3,     3,     3,     3,     3,     0,     1,     2,     3,     3,
       3,     5,     2,     1,     1,     1,     2,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     0,     5,     3,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     6,     0,     5,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     0,     5,     3,     1,     1,     1,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   192,   343,   397,     0,
     412,     0,   581,   247,   382,   223,     0,     0,   127,   280,
       0,     0,   297,   321,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    91,    90,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     628,   623,   611,   612,   613,   614,   616,   617,   618,   619,
     615,   620,   621,   622,   624,   625,   626,   627,     0,     0,
       0,   410,     0,     0,   408,   409,     0,   481,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,   479,   474,   475,   476,   477,   473,   440,   430,   431,
     467,   432,   433,   434,   435,   436,   437,   438,   439,   470,
     441,   442,   443,   444,   478,   446,   451,   447,   449,   448,
     462,   463,   450,   452,   453,   454,   455,   456,   445,   458,
     459,   460,   480,   471,   472,   469,   461,   457,   465,   466,
     464,   468,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,     0,     0,     0,     0,     0,    43,
      44,    45,     0,     0,   658,     0,     0,     0,     0,     0,
       0,     0,     0,   650,   651,   652,   656,   653,   655,   654,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,     0,     0,    51,    64,    63,
      60,    59,    65,    52,    62,    55,    56,    57,    53,    61,
      58,    54,     0,     0,   295,     0,     0,   293,   294,    92,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     195,   196,   199,   200,   202,   203,   204,   205,   206,   207,
     208,   197,   198,   201,     0,     0,     0,     0,     0,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   346,
     347,   348,   349,   350,   351,   353,   352,   355,   359,   356,
     357,   358,   354,   403,     0,     0,     0,   400,   401,   402,
       0,     0,   407,   424,     0,     0,   414,   423,     0,   420,
     421,   422,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   428,   591,   602,     0,     0,   594,
       0,     0,     0,   584,   585,   586,   587,   588,   589,   590,
       0,     0,     0,   264,     0,     0,     0,     0,     0,     0,
     250,   251,   252,   253,   258,   254,   255,   256,   257,   394,
       0,   384,     0,   393,     0,   390,   391,   392,     0,   225,
       0,     0,     0,   235,     0,   233,   234,   236,   237,   102,
       0,     0,     0,    97,     0,    46,     0,     0,     0,    42,
       0,     0,     0,   170,     0,     0,     0,   146,     0,     0,
     130,   131,   132,   133,   136,   137,   135,   134,   138,     0,
       0,     0,     0,     0,   283,   284,   285,   286,     0,     0,
       0,     0,     0,     0,     0,     0,   649,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,   307,     0,     0,   300,
     301,   302,   303,     0,     0,   329,     0,   324,   325,   326,
       0,     0,   292,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   608,   209,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,   360,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   345,     0,
       0,     0,   399,     0,   406,     0,     0,     0,     0,   419,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,   427,     0,     0,     0,     0,     0,
       0,     0,   583,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,   389,   238,
       0,     0,     0,     0,     0,   232,     0,     0,    96,     0,
       0,     0,    41,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   287,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,   648,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,   304,     0,     0,     0,     0,   299,   327,
       0,     0,     0,   323,     0,   291,    95,    94,    93,   645,
     642,   641,   630,   632,    27,    27,    27,    27,    27,    29,
      28,   636,   637,   640,   638,   643,   644,   646,   647,   639,
     631,   633,   634,   635,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   344,     0,     0,   398,   411,     0,     0,     0,
     413,   493,   497,   513,   579,   527,   491,   521,   524,   492,
     483,   484,   500,   489,   490,   503,   488,   502,   501,   496,
     495,   494,   522,   482,   520,   577,   578,   517,   514,   564,
     557,   574,   575,   558,   559,   560,   561,   569,   562,   572,
     576,   565,   570,   566,   571,   563,   568,   567,   573,     0,
     556,   519,   539,   533,   550,   551,   534,   535,   536,   537,
     545,   538,   548,   552,   541,   546,   542,   547,   540,   544,
     543,   549,     0,   532,   512,   515,   526,   486,   487,   516,
     505,   510,   511,   508,   509,   506,   507,   499,   498,    35,
      35,    35,    37,    36,   580,   525,   528,   518,   523,   485,
     504,     0,     0,     0,     0,     0,     0,   582,     0,     0,
       0,     0,     0,     0,     0,     0,   248,     0,     0,     0,
     383,     0,     0,     0,   243,   239,   242,   224,   104,   103,
       0,     0,   116,     0,     0,   108,   109,   111,   110,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,   281,   664,   659,   663,   661,   665,   660,
     662,    79,    85,    77,    81,    80,    74,    73,    75,    71,
      72,     0,    70,    78,    76,    84,    82,    83,     0,     0,
       0,   298,     0,     0,   322,   296,    30,    31,    32,    33,
      34,   220,   221,   214,   216,   218,   217,   215,   210,   222,
     213,   211,   212,   219,   365,   367,   368,   380,   377,   373,
     374,   376,   375,     0,   372,   362,   378,   379,   361,   366,
     364,   381,   363,   404,   405,   425,   426,   418,     0,   417,
     554,     0,   530,     0,    38,    39,    40,   607,   606,     0,
     605,   593,   592,   599,   598,     0,   597,   601,   600,   262,
     263,   272,   269,   274,   271,   270,   276,   273,   275,   268,
       0,   267,   261,   279,   278,   277,   260,   396,   388,     0,
     387,   395,   230,   231,   229,     0,   228,   246,   245,     0,
       0,     0,   112,     0,     0,     0,     0,   107,   145,   143,
     185,   182,   181,   174,   176,   191,   186,   189,   184,   175,
     190,   178,   187,   179,   188,   183,   177,   180,     0,   173,
     140,   142,   144,   156,   150,   167,   168,   151,   152,   153,
     154,   162,   155,   165,   169,   158,   163,   159,   164,   157,
     161,   160,   166,     0,   149,   141,   289,   290,   288,    68,
       0,   305,   311,   317,   320,   313,   319,   314,   318,   316,
     312,   315,     0,   310,   306,   328,   333,   339,   342,   335,
     341,   336,   340,   338,   334,   337,     0,   332,   370,     0,
     415,     0,   555,   531,   603,     0,   595,     0,   265,     0,
     385,     0,   226,     0,   244,   241,   240,     0,     0,     0,
       0,   106,   171,     0,   147,     0,    69,   308,     0,   330,
       0,   371,   416,   604,   596,   266,   386,   227,   113,   122,
     125,   124,   121,   126,   123,   120,     0,   119,   115,   114,
     172,   148,   309,   331,   117,     0,   118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   829,   830,   972,   973,    26,   248,   249,
     250,   251,    27,   286,   287,   288,   576,  1051,  1052,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,    28,    74,    75,    76,    77,    78,    29,   239,
     240,   241,   242,   243,   244,  1014,  1015,  1016,  1017,  1018,
    1164,  1296,  1297,    30,    63,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   770,  1213,  1214,   548,   766,  1188,
    1189,    31,    51,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    32,    60,
     513,   750,  1155,  1156,   514,   515,   516,  1161,  1005,  1006,
     517,   518,    33,    58,   489,   490,   491,   492,   493,   494,
     495,   736,  1140,  1141,   496,   497,   498,    34,    64,   553,
     554,   555,   556,   557,    35,   306,   307,   308,    36,    67,
     588,   589,   590,   591,   592,   805,  1232,  1233,    37,    68,
     596,   597,   598,   599,   811,  1246,  1247,    38,    52,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   648,
    1093,  1094,   388,   389,   390,   391,   392,    39,    59,   503,
     745,  1149,  1150,   504,   505,   506,   507,    40,    53,   396,
     397,   398,   399,    41,   123,   124,   125,    42,    55,   407,
     667,  1108,  1109,   408,   409,   410,   411,    43,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   442,   952,   953,   227,
     440,   929,   930,   228,   229,   230,   231,    44,    57,   472,
     473,   474,   475,   476,   728,  1125,  1126,   477,   478,   479,
     725,  1119,  1120,    45,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,    46,   262,   263,   264,   265,   266,
     267,   268,   269,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -925
static const yytype_int16 yypact[] =
{
    -925,   650,  -925,  -171,  -239,  -236,  -925,  -925,  -925,  -233,
    -925,  -225,  -925,  -925,  -925,  -925,  -218,  -204,  -925,  -925,
    -170,  -165,  -925,  -925,  -159,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   298,
     486,  -139,  -122,   -83,    27,   -76,   368,   -66,   -33,   -31,
     -28,    76,   115,   -21,   -12,   549,   332,    50,    57,    74,
    -208,     7,    30,    59,    20,  -925,  -925,  -925,  -925,  -925,
      63,    65,    80,    87,    90,    92,   106,   117,   118,   120,
     121,   122,   123,   129,   130,   131,   134,   138,   180,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   736,   502,
      16,  -925,   140,    21,  -925,  -925,   218,  -925,   141,   142,
     144,   146,   147,   148,   156,   158,   169,   172,   174,   175,
     176,   182,   183,   185,   186,   187,   195,   198,   199,   203,
     204,   207,   211,   212,   213,   222,  -925,   223,  -925,   225,
     226,   228,   236,   238,   245,   252,   253,   256,   257,   258,
     260,   265,   272,   273,   277,   279,   281,   292,   293,   110,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   411,   393,   152,   402,    85,   299,   300,    73,
    -925,  -925,  -925,  -925,    17,   105,   304,   307,     8,  -925,
    -925,  -925,   346,    28,  -925,   308,   309,   313,   314,   315,
     316,   325,    19,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,   271,   330,   336,   339,   341,   347,   350,   351,   354,
    -925,   359,   365,   370,   371,   372,    12,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,   177,    23,  -925,   373,    10,  -925,  -925,  -925,
     241,   290,   323,   378,  -925,   446,   512,   514,   450,   451,
     519,   519,   523,   524,   462,   464,   531,   519,   465,   467,
     468,   469,   470,   405,  -925,   406,   404,   408,   410,   412,
     413,   414,   415,   417,   418,   419,   420,   422,   424,   268,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   431,   429,   432,   433,   434,  -925,
     435,   437,   438,   439,   440,   441,   442,   443,    62,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   444,   447,    36,  -925,  -925,  -925,
     522,   449,  -925,  -925,   448,   453,  -925,  -925,   102,  -925,
    -925,  -925,   518,   519,   519,   584,   526,   528,   588,   573,
     535,   595,   601,   602,   539,   544,   545,   519,   592,   551,
     614,   619,   519,   620,   624,   604,   629,   632,   568,   570,
     503,   575,   508,   519,   519,   578,   519,   579,   585,   586,
      14,    49,   589,   593,   519,   519,   653,   640,   519,   597,
     598,   599,   600,   536,  -925,  -925,  -925,   532,   534,  -925,
     537,   538,     2,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     543,   542,   546,  -925,   547,   548,   550,   552,   553,    29,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     554,  -925,   555,  -925,    11,  -925,  -925,  -925,   560,  -925,
     558,   559,   561,  -925,    22,  -925,  -925,  -925,  -925,  -925,
     605,   612,   563,  -925,   564,  -925,   648,   658,   565,  -925,
     567,   571,   572,  -925,   574,   576,   577,  -925,   582,    98,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   581,
     583,   587,   590,    13,  -925,  -925,  -925,  -925,   613,   636,
     637,   664,   642,   644,   519,   591,  -925,  -925,   698,   655,
     702,   704,   706,   707,   713,   714,   609,   723,   725,   750,
     737,   738,   630,  -925,   633,   626,  -925,   631,    95,  -925,
    -925,  -925,  -925,   635,   639,  -925,    26,  -925,  -925,  -925,
     742,   643,  -925,   646,   647,   651,  -925,   654,   662,   663,
     671,   674,   423,   675,   679,   680,   682,   686,   690,   691,
     693,   694,   695,   697,   699,   700,  -925,  -925,   767,   789,
     519,   827,   832,   833,   834,   814,   836,   837,   519,   519,
     653,   708,  -925,  -925,   817,   157,   819,   776,   709,   821,
     823,   824,   825,   847,   828,   829,   830,   717,  -925,   831,
     835,   722,  -925,   726,  -925,   838,   839,   720,   727,  -925,
     730,   731,   732,   733,   734,   735,   739,   740,   741,   743,
     744,   745,   746,   747,   748,   749,   751,   752,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   657,   763,
     696,   764,   765,   766,   768,   769,   770,   771,   772,   773,
     774,   775,   777,   778,   779,   780,    75,   781,   782,   783,
     784,   785,   786,   787,  -925,   721,   519,   802,   788,   848,
     852,   790,  -925,  -925,   860,   803,   791,   877,   907,   898,
     899,   902,   793,  -925,   905,   794,   906,   798,  -925,  -925,
     796,   910,   911,   933,   804,  -925,   805,   806,  -925,   132,
     807,   808,  -925,  -925,   913,   875,   809,   920,   921,   923,
     811,   925,   816,  -925,  -925,   927,   928,   929,   820,  -925,
     822,   826,   840,   841,   842,   843,   844,  -925,   845,   846,
     849,   850,   851,   853,   854,   855,   210,   856,   857,   858,
     859,   861,  -925,  -925,   931,   862,   934,   863,  -925,  -925,
     935,   864,   866,  -925,   868,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   519,   519,   519,   519,   519,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   869,   870,   871,   872,   873,   874,
     876,   878,   879,   880,   881,   882,   883,  -925,   884,   885,
     886,   887,   888,   128,   889,   890,   891,   892,   893,   894,
     895,   896,  -925,   897,   900,  -925,  -925,   901,   903,   932,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -226,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -210,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   653,
     653,   653,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,    -6,   904,   908,     5,   909,   912,  -925,   914,   915,
     454,   916,   917,   918,   919,   922,  -925,   924,   936,   926,
    -925,   -35,   930,   937,   938,   939,  -925,  -925,  -925,  -925,
     940,   941,  -925,   942,    31,  -925,  -925,  -925,  -925,  -925,
    -925,   946,   947,   530,   948,   949,   950,   724,   951,  -925,
     952,   953,   954,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -205,  -925,  -925,  -925,  -925,  -925,  -925,   955,   515,
     956,  -925,   957,   557,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -203,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -193,  -925,
    -925,   657,  -925,   696,  -925,  -925,  -925,  -925,  -925,  -181,
    -925,  -925,  -925,  -925,  -925,  -179,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -144,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,   -24,
    -925,  -925,  -925,  -925,  -925,    -5,  -925,  -925,  -925,   959,
     933,   958,  -925,   943,   960,   -60,   961,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,    -2,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,    34,  -925,  -925,  -925,  -925,  -925,  -925,
     210,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,    69,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,    82,  -925,  -925,   128,
    -925,   932,  -925,  -925,  -925,    -6,  -925,     5,  -925,   454,
    -925,   936,  -925,   -35,  -925,  -925,  -925,   962,   409,   964,
     965,  -925,  -925,   530,  -925,   724,  -925,  -925,   515,  -925,
     557,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,   100,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,   409,  -925
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -925,  -925,  -925,  -769,  -319,  -924,  -456,  -925,  -925,   963,
    -925,  -925,  -925,  -925,   792,  -925,  -925,  -925,  -156,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,   996,  -925,  -925,  -925,  -925,  -925,
     944,  -925,  -925,  -925,  -925,  -925,    61,  -925,  -925,  -925,
    -925,  -925,  -234,  -925,  -925,  -925,   540,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -202,  -925,  -925,  -925,
    -197,  -925,  -925,  -925,   728,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -183,  -925,   625,  -925,  -925,  -925,   -72,
    -925,  -925,  -925,  -925,  -925,   616,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -166,  -925,  -925,  -925,  -925,  -925,  -925,
     594,  -925,  -925,  -925,  -925,  -925,   795,  -925,  -925,  -925,
    -925,   501,  -925,  -925,  -925,  -925,  -925,  -175,  -925,  -925,
    -925,   520,  -925,  -925,  -925,  -925,  -140,  -925,  -925,  -925,
     797,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -106,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -115,  -925,   660,  -925,  -925,  -925,  -925,  -925,
     812,  -925,  -925,  -925,  -925,  1025,  -925,  -925,  -925,  -925,
    -925,  -925,  -100,  -925,   799,  -925,  -925,  -925,  -925,   973,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,    41,  -925,
    -925,  -925,    51,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
     689,  -925,  -925,  -925,  -925,  -925,   -91,  -925,  -925,  -925,
    -925,  -925,   -87,  -925,  -925,  1071,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,  -925,
    -925,  -925,  -925,  -925,  -925,  -925,   966,  -925,  -925,  -925,
    -925,  -925,  -925,  -925
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -106
static const yytype_int16 yytable[] =
{
     717,   613,   614,   465,    49,  1117,   466,    50,   620,   245,
      54,   304,   499,   271,   549,  1110,  1123,   393,    56,  1111,
     254,    70,   121,   508,   593,    61,  1152,   593,   121,   549,
     480,  1112,  1010,   309,   550,  1113,  1219,   393,  1248,    62,
    1220,   467,  1249,   272,   468,  1114,  1115,  1116,  1250,   550,
     716,    71,  1251,   481,   255,  1066,  1067,  1068,  1069,  1070,
    1254,    72,  1256,   364,  1255,   365,  1257,   256,   366,   509,
      47,    48,   482,    65,   236,   304,   483,   236,    66,   273,
     257,   258,   259,   260,    69,   469,   367,   394,   510,   969,
     970,   971,   122,   511,   671,   672,   584,  1258,   122,   530,
     261,  1259,   470,   403,   118,   368,   246,   394,   685,   369,
     305,   127,   274,   690,   275,   276,   245,   551,   128,   129,
      73,   119,   531,   594,   701,   702,   594,   704,   370,   130,
     371,  1011,   551,  1010,   247,   714,   715,   131,  1089,   719,
    1090,   532,   372,   132,   500,   533,   552,   133,   134,   395,
     135,  1269,   512,   499,   484,   277,   136,   278,   279,   280,
     120,   552,   373,   485,   486,   137,   138,   126,  1153,   395,
     139,  1118,  1154,   281,   305,   140,   501,   232,   584,   141,
     142,    79,  1124,   143,   856,   716,   144,   145,   595,   708,
     709,   595,   374,    80,   146,   585,  1012,   487,   534,   282,
     147,   148,   404,   149,   150,   151,   152,   153,    81,    82,
     233,   283,   234,   246,    83,   235,    84,  1260,   154,   403,
     375,  1261,   252,   535,   710,   711,   155,   156,   157,   471,
     158,   253,  1011,   159,   160,   405,  1262,   161,   502,  1272,
    1263,   247,   536,  1273,   731,   786,   284,   285,   162,   376,
     528,   310,   601,   747,   582,   778,   488,   524,    85,    86,
     586,   565,   313,   401,   754,    87,    88,   406,   812,   335,
    1013,   742,   163,  1166,   311,  1274,   164,   585,   661,  1275,
     165,   166,   167,   168,   169,   500,    89,    90,   170,   171,
     336,   337,   237,   302,   338,   237,   377,  1012,   172,    70,
     303,    91,    92,   312,   657,   238,   537,   315,   238,   316,
    1277,   846,    93,  -105,  1278,   522,  -105,   501,   404,   854,
     855,    94,   587,  1279,   317,   538,   519,  1280,   173,    71,
     174,   318,   175,   271,   319,  1091,   320,   807,   176,    72,
     772,  1304,   586,   177,   668,  1305,   525,   530,   178,  1092,
     321,   405,   463,   859,   860,   339,   340,   341,  1049,  1050,
     342,   322,   323,   272,   324,   325,   326,   327,   343,   127,
     531,  1013,   603,   328,   329,   330,   128,   129,   331,   502,
     344,   345,   332,   406,   400,   412,   413,   130,   414,   532,
     415,   416,   417,   533,   480,   131,   346,   347,    73,   273,
     418,   132,   419,   508,   587,   133,   134,   982,   135,    95,
      96,    97,   465,   420,   136,   466,   421,   481,   422,   423,
     424,   604,   333,   137,   138,   348,   425,   426,   139,   427,
     428,   429,   274,   140,   275,   276,   482,   141,   142,   430,
     483,   143,   431,   432,   144,   145,   534,   433,   434,   509,
     467,   435,   146,   468,   605,   436,   437,   438,   147,   148,
    1289,   149,   150,   151,   152,   153,   439,   441,   510,   443,
     444,   535,   445,   511,  1131,   277,   154,   278,   279,   280,
     446,  1290,   447,  1291,   155,   156,   157,    79,   158,   448,
     536,   159,   160,   281,   469,   161,   449,   450,  1132,    80,
     451,   452,   453,   364,   454,   365,   162,  1133,   366,   455,
     641,   470,   567,  1134,    81,    82,   456,   457,   484,   282,
      83,   458,    84,   459,  1292,   460,   367,   485,   486,  1135,
     163,   283,   512,   612,   164,  1170,   461,   462,   165,   166,
     167,   168,   169,   520,   521,   368,   170,   171,   526,   369,
     254,   527,   558,   559,   537,  1136,   172,   560,   561,   562,
     563,   487,  1171,  1137,    85,    86,   284,   285,   370,   564,
     371,    87,    88,   538,   568,   824,   825,   826,   827,   828,
     569,  1172,   372,   570,   255,   571,   173,  1173,   174,  1222,
     175,   572,    89,    90,   573,   574,   176,   256,   575,  1293,
    1294,   177,   373,   577,  1174,  1138,   178,    91,    92,   578,
     257,   258,   259,   260,   579,   580,   581,   600,    93,   606,
     488,   607,   608,  1139,   609,   610,   611,    94,  1175,   612,
     261,  1236,   374,   615,   616,  1176,  1295,   617,   471,   618,
     621,   619,   622,   623,   624,   625,   626,   627,   628,  1177,
       2,     3,   629,   663,   630,     4,   631,   632,   633,   634,
     375,   635,   636,   637,   638,  1223,   639,  1178,   640,  1179,
    1180,     5,   643,   644,     6,     7,   645,   646,   647,   649,
       8,   650,   651,   652,   653,   654,   655,   656,   659,   376,
     664,   660,   665,   670,   673,     9,  1224,   666,   676,    10,
      11,   674,    12,   675,   677,   679,  1225,  1237,    13,  1270,
     678,   680,   681,  1226,   682,    95,    96,    97,   909,   683,
     684,  1181,    14,   686,   688,  1227,   687,  1228,  1229,   689,
     691,  1182,    15,    16,   692,   693,   377,   335,  1238,   694,
    1183,  1230,   695,   696,  1184,   697,  1185,   698,  1239,    17,
     699,  1231,   700,   703,   705,  1240,  1186,   932,   336,   337,
     706,   707,   338,   716,   712,    18,  1187,  1241,   713,  1242,
    1243,   718,   720,   721,   722,   723,   726,   724,   727,   760,
     756,   729,   730,  1244,   733,  1193,   734,   757,   780,   761,
     735,   737,   738,  1245,   739,   783,   740,   741,   744,   746,
      19,   749,   751,   752,   758,   753,   762,   759,   763,    20,
      21,   781,   782,    22,    23,   764,   765,   784,   767,   785,
     768,   769,   774,   339,   340,   341,   771,   775,   342,   788,
     789,   776,   787,   790,   777,   791,   343,   792,   793,   910,
     911,   912,   913,   914,   794,   795,   915,   916,   344,   345,
     917,   918,   919,   796,   797,   920,   798,   921,   922,   923,
     799,   924,   925,   926,   346,   347,   927,    24,   800,   801,
     804,   802,   928,   814,   803,   806,   809,   844,   933,   934,
     935,   936,   937,   810,   815,   938,   939,   816,   817,   940,
     941,   942,   818,   348,   943,   819,   944,   945,   946,   845,
     947,   948,   949,   820,   821,   950,  1194,  1195,  1196,  1197,
    1198,   951,   822,  1199,  1200,   823,   831,  1201,  1202,  1203,
     832,   833,  1204,   834,  1205,  1206,  1207,   835,  1208,  1209,
    1210,   836,   837,  1211,   838,   839,   840,   847,   841,  1212,
     842,   843,   848,   849,   850,   851,   852,   853,   858,   857,
     861,   862,   864,   863,   865,   866,   867,   868,   872,   869,
     870,   871,   873,   875,   879,   981,   874,   876,   880,   877,
     878,   881,   882,   883,   884,   885,   886,   983,   989,   985,
     887,   888,   889,   986,   890,   891,   892,   893,   894,   895,
     896,   988,   897,   898,   899,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   931,   954,   955,   956,   991,   957,
     958,   959,   960,   961,   962,   963,   964,   992,   965,   966,
     967,   968,   974,   975,   976,   977,   978,   979,   980,   993,
     994,   987,   984,   995,   996,   990,   997,   999,   998,  1000,
    1001,  1002,  1003,  1004,  1021,  1007,  1008,  1009,  1019,  1020,
    1022,  1024,  1025,  1023,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1058,  1034,  1276,  1060,  1062,  1035,  1107,  1264,
     314,  1306,  1148,  1301,  1267,  1167,  1300,   642,   583,   773,
    1287,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1265,   808,
    1043,  1044,  1045,  1285,  1046,  1047,  1048,  1053,  1054,  1055,
    1056,   602,  1057,  1302,  1061,   743,  1059,  1064,  1063,  1065,
    1071,  1072,  1073,  1074,  1075,  1076,   813,  1077,  1159,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,   755,
    1303,  1104,  1105,  1281,  1106,  1121,  1286,   779,   402,  1122,
    1127,  1282,   464,  1128,  1253,  1129,  1130,  1142,  1143,  1144,
    1145,   732,  1252,  1146,   748,  1147,  1284,  1151,  1283,   334,
       0,  1157,     0,     0,     0,   658,     0,     0,  1158,     0,
       0,  1162,     0,   523,  1160,  1163,  1165,  1168,  1169,  1190,
    1191,  1192,  1215,  1216,  1217,  1218,  1221,  1234,  1235,  1266,
       0,     0,  1271,  1288,  1268,  1298,  1299,   669,   662,     0,
       0,   529,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   566
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-925))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     456,   320,   321,     1,   243,    11,     4,   243,   327,     1,
     243,     1,     1,     1,     1,   241,    11,     1,   243,   245,
       1,     1,     1,     1,     1,   243,    61,     1,     1,     1,
       1,   241,     1,   241,    21,   245,   241,     1,   241,   243,
     245,    39,   245,    31,    42,   969,   970,   971,   241,    21,
     110,    31,   245,    24,    35,   824,   825,   826,   827,   828,
     241,    41,   241,     1,   245,     3,   245,    48,     6,    47,
     241,   242,    43,   243,     1,     1,    47,     1,   243,    67,
      61,    62,    63,    64,   243,    83,    24,    71,    66,    14,
      15,    16,    71,    71,   413,   414,     1,   241,    71,     1,
      81,   245,   100,     1,   243,    43,    98,    71,   427,    47,
     100,     1,   100,   432,   102,   103,     1,   104,     8,     9,
     100,   243,    24,   100,   443,   444,   100,   446,    66,    19,
      68,   100,   104,     1,   126,   454,   455,    27,    10,   458,
      12,    43,    80,    33,   133,    47,   133,    37,    38,   133,
      40,   211,   130,     1,   125,   143,    46,   145,   146,   147,
     243,   133,   100,   134,   135,    55,    56,   243,   203,   133,
      60,   177,   207,   161,   100,    65,   165,   243,     1,    69,
      70,     1,   177,    73,   640,   110,    76,    77,   165,   175,
     176,   165,   130,    13,    84,   100,   165,   168,   100,   187,
      90,    91,   100,    93,    94,    95,    96,    97,    28,    29,
     243,   199,   243,    98,    34,   243,    36,   241,   108,     1,
     158,   245,   243,   125,   175,   176,   116,   117,   118,   227,
     120,   243,   100,   123,   124,   133,   241,   127,   227,   241,
     245,   126,   144,   245,   242,   564,   234,   235,   138,   187,
     242,   244,   242,   242,   242,   242,   227,   240,    78,    79,
     165,   242,   242,   242,   242,    85,    86,   165,   242,     1,
     239,   242,   162,   242,   244,   241,   166,   100,   242,   245,
     170,   171,   172,   173,   174,   133,   106,   107,   178,   179,
      22,    23,   219,   243,    26,   219,   234,   165,   188,     1,
     243,   121,   122,   244,   242,   232,   208,   244,   232,   244,
     241,   630,   132,   240,   245,   242,   240,   165,   100,   638,
     639,   141,   227,   241,   244,   227,   241,   245,   218,    31,
     220,   244,   222,     1,   244,   207,   244,   242,   228,    41,
     242,   241,   165,   233,   242,   245,   241,     1,   238,   221,
     244,   133,   242,   196,   197,    87,    88,    89,   148,   149,
      92,   244,   244,    31,   244,   244,   244,   244,   100,     1,
      24,   239,   131,   244,   244,   244,     8,     9,   244,   227,
     112,   113,   244,   165,   244,   244,   244,    19,   244,    43,
     244,   244,   244,    47,     1,    27,   128,   129,   100,    67,
     244,    33,   244,     1,   227,    37,    38,   726,    40,   229,
     230,   231,     1,   244,    46,     4,   244,    24,   244,   244,
     244,   131,   242,    55,    56,   157,   244,   244,    60,   244,
     244,   244,   100,    65,   102,   103,    43,    69,    70,   244,
      47,    73,   244,   244,    76,    77,   100,   244,   244,    47,
      39,   244,    84,    42,   131,   244,   244,   244,    90,    91,
      51,    93,    94,    95,    96,    97,   244,   244,    66,   244,
     244,   125,   244,    71,    20,   143,   108,   145,   146,   147,
     244,    72,   244,    74,   116,   117,   118,     1,   120,   244,
     144,   123,   124,   161,    83,   127,   244,   244,    44,    13,
     244,   244,   244,     1,   244,     3,   138,    53,     6,   244,
     242,   100,   241,    59,    28,    29,   244,   244,   125,   187,
      34,   244,    36,   244,   115,   244,    24,   134,   135,    75,
     162,   199,   130,   110,   166,     5,   244,   244,   170,   171,
     172,   173,   174,   244,   244,    43,   178,   179,   244,    47,
       1,   244,   244,   244,   208,   101,   188,   244,   244,   244,
     244,   168,    32,   109,    78,    79,   234,   235,    66,   244,
      68,    85,    86,   227,   244,   152,   153,   154,   155,   156,
     244,    51,    80,   244,    35,   244,   218,    57,   220,    74,
     222,   244,   106,   107,   244,   244,   228,    48,   244,   190,
     191,   233,   100,   244,    74,   151,   238,   121,   122,   244,
      61,    62,    63,    64,   244,   244,   244,   244,   132,   241,
     227,   175,   110,   169,   110,   175,   175,   141,    98,   110,
      81,    74,   130,   110,   110,   105,   227,   175,   227,   175,
     175,   110,   175,   175,   175,   175,   241,   241,   244,   119,
       0,     1,   244,   131,   244,     5,   244,   244,   244,   244,
     158,   244,   244,   244,   244,   150,   244,   137,   244,   139,
     140,    21,   241,   244,    24,    25,   244,   244,   244,   244,
      30,   244,   244,   244,   244,   244,   244,   244,   244,   187,
     241,   244,   244,   175,   110,    45,   181,   244,   110,    49,
      50,   175,    52,   175,   131,   110,   191,   150,    58,  1165,
     175,   110,   110,   198,   175,   229,   230,   231,    61,   175,
     175,   191,    72,   131,   110,   210,   175,   212,   213,   110,
     110,   201,    82,    83,   110,   131,   234,     1,   181,   110,
     210,   226,   110,   175,   214,   175,   216,   244,   191,    99,
     175,   236,   244,   175,   175,   198,   226,    61,    22,    23,
     175,   175,    26,   110,   175,   115,   236,   210,   175,   212,
     213,   131,   175,   175,   175,   175,   244,   241,   244,   131,
     175,   244,   244,   226,   241,    61,   244,   175,   175,   131,
     244,   244,   244,   236,   244,   131,   244,   244,   244,   244,
     150,   241,   244,   244,   241,   244,   241,   243,   241,   159,
     160,   175,   175,   163,   164,   244,   244,   175,   244,   175,
     244,   244,   241,    87,    88,    89,   244,   244,    92,   131,
     175,   244,   241,   131,   244,   131,   100,   131,   131,   182,
     183,   184,   185,   186,   131,   131,   189,   190,   112,   113,
     193,   194,   195,   244,   131,   198,   131,   200,   201,   202,
     110,   204,   205,   206,   128,   129,   209,   217,   131,   131,
     244,   241,   215,   131,   241,   244,   241,   110,   182,   183,
     184,   185,   186,   244,   241,   189,   190,   241,   241,   193,
     194,   195,   241,   157,   198,   241,   200,   201,   202,   110,
     204,   205,   206,   241,   241,   209,   182,   183,   184,   185,
     186,   215,   241,   189,   190,   241,   241,   193,   194,   195,
     241,   241,   198,   241,   200,   201,   202,   241,   204,   205,
     206,   241,   241,   209,   241,   241,   241,   110,   241,   215,
     241,   241,   110,   110,   110,   131,   110,   110,   131,   241,
     131,   175,   131,   244,   131,   131,   131,   110,   241,   131,
     131,   131,   131,   241,   244,   244,   131,   241,   241,   131,
     131,   241,   241,   241,   241,   241,   241,   175,   175,   131,
     241,   241,   241,   131,   241,   241,   241,   241,   241,   241,
     241,   131,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   131,   241,
     241,   241,   241,   241,   241,   241,   241,   110,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   131,
     131,   241,   244,   131,   241,   244,   131,   131,   244,   241,
     244,   131,   131,   110,   131,   241,   241,   241,   241,   241,
     175,   131,   131,   244,   131,   244,   131,   241,   131,   131,
     131,   241,   131,   241,  1220,   131,   131,   241,   136,   110,
      74,  1305,   136,  1275,   131,  1014,  1273,   349,   286,   539,
    1263,   241,   241,   241,   241,   241,   241,   241,  1160,   588,
     241,   241,   241,  1259,   241,   241,   241,   241,   241,   241,
     241,   306,   241,  1278,   241,   489,   244,   241,   244,   241,
     241,   241,   241,   241,   241,   241,   596,   241,   180,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   514,
    1280,   241,   241,  1249,   241,   241,  1261,   553,   123,   241,
     241,  1251,   179,   241,  1113,   241,   241,   241,   241,   241,
     241,   472,  1111,   241,   504,   241,  1257,   241,  1255,    98,
      -1,   241,    -1,    -1,    -1,   378,    -1,    -1,   241,    -1,
      -1,   241,    -1,   239,   245,   244,   244,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
      -1,    -1,   241,   241,   244,   241,   241,   408,   396,    -1,
      -1,   248,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   247,     0,     1,     5,    21,    24,    25,    30,    45,
      49,    50,    52,    58,    72,    82,    83,    99,   115,   150,
     159,   160,   163,   164,   217,   248,   253,   258,   278,   284,
     299,   317,   334,   348,   363,   370,   374,   384,   393,   413,
     423,   429,   433,   443,   503,   519,   540,   241,   242,   243,
     243,   318,   394,   424,   243,   434,   243,   504,   349,   414,
     335,   243,   243,   300,   364,   243,   243,   375,   385,   243,
       1,    31,    41,   100,   279,   280,   281,   282,   283,     1,
      13,    28,    29,    34,    36,    78,    79,    85,    86,   106,
     107,   121,   122,   132,   141,   229,   230,   231,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   243,   243,
     243,     1,    71,   430,   431,   432,   243,     1,     8,     9,
      19,    27,    33,    37,    38,    40,    46,    55,    56,    60,
      65,    69,    70,    73,    76,    77,    84,    90,    91,    93,
      94,    95,    96,    97,   108,   116,   117,   118,   120,   123,
     124,   127,   138,   162,   166,   170,   171,   172,   173,   174,
     178,   179,   188,   218,   220,   222,   228,   233,   238,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   495,   499,   500,
     501,   502,   243,   243,   243,   243,     1,   219,   232,   285,
     286,   287,   288,   289,   290,     1,    98,   126,   254,   255,
     256,   257,   243,   243,     1,    35,    48,    61,    62,    63,
      64,    81,   541,   542,   543,   544,   545,   546,   547,   548,
     549,     1,    31,    67,   100,   102,   103,   143,   145,   146,
     147,   161,   187,   199,   234,   235,   259,   260,   261,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   243,   243,     1,   100,   371,   372,   373,   241,
     244,   244,   244,   242,   280,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   242,   521,     1,    22,    23,    26,    87,
      88,    89,    92,   100,   112,   113,   128,   129,   157,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,     1,     3,     6,    24,    43,    47,
      66,    68,    80,   100,   130,   158,   187,   234,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   408,   409,
     410,   411,   412,     1,    71,   133,   425,   426,   427,   428,
     244,   242,   431,     1,   100,   133,   165,   435,   439,   440,
     441,   442,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     496,   244,   492,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   242,   445,     1,     4,    39,    42,    83,
     100,   227,   505,   506,   507,   508,   509,   513,   514,   515,
       1,    24,    43,    47,   125,   134,   135,   168,   227,   350,
     351,   352,   353,   354,   355,   356,   360,   361,   362,     1,
     133,   165,   227,   415,   419,   420,   421,   422,     1,    47,
      66,    71,   130,   336,   340,   341,   342,   346,   347,   241,
     244,   244,   242,   286,   240,   241,   244,   244,   242,   255,
       1,    24,    43,    47,   100,   125,   144,   208,   227,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   313,     1,
      21,   104,   133,   365,   366,   367,   368,   369,   244,   244,
     244,   244,   244,   244,   244,   242,   542,   241,   244,   244,
     244,   244,   244,   244,   244,   244,   262,   244,   244,   244,
     244,   244,   242,   260,     1,   100,   165,   227,   376,   377,
     378,   379,   380,     1,   100,   165,   386,   387,   388,   389,
     244,   242,   372,   131,   131,   131,   241,   175,   110,   110,
     175,   175,   110,   250,   250,   110,   110,   175,   175,   110,
     250,   175,   175,   175,   175,   175,   241,   241,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   242,   320,   241,   244,   244,   244,   244,   405,   244,
     244,   244,   244,   244,   244,   244,   244,   242,   396,   244,
     244,   242,   426,   131,   241,   244,   244,   436,   242,   440,
     175,   250,   250,   110,   175,   175,   110,   131,   175,   110,
     110,   110,   175,   175,   175,   250,   131,   175,   110,   110,
     250,   110,   110,   131,   110,   110,   175,   175,   244,   175,
     244,   250,   250,   175,   250,   175,   175,   175,   175,   176,
     175,   176,   175,   175,   250,   250,   110,   252,   131,   250,
     175,   175,   175,   175,   241,   516,   244,   244,   510,   244,
     244,   242,   506,   241,   244,   244,   357,   244,   244,   244,
     244,   244,   242,   351,   244,   416,   244,   242,   420,   241,
     337,   244,   244,   244,   242,   341,   175,   175,   241,   243,
     131,   131,   241,   241,   244,   244,   314,   244,   244,   244,
     310,   244,   242,   302,   241,   244,   244,   244,   242,   366,
     175,   175,   175,   131,   175,   175,   250,   241,   131,   175,
     131,   131,   131,   131,   131,   131,   244,   131,   131,   110,
     131,   131,   241,   241,   244,   381,   244,   242,   377,   241,
     244,   390,   242,   387,   131,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   152,   153,   154,   155,   156,   249,
     250,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   110,   110,   250,   110,   110,   110,
     110,   131,   110,   110,   250,   250,   252,   241,   131,   196,
     197,   131,   175,   244,   131,   131,   131,   131,   110,   131,
     131,   131,   241,   131,   131,   241,   241,   131,   131,   244,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,    61,
     182,   183,   184,   185,   186,   189,   190,   193,   194,   195,
     198,   200,   201,   202,   204,   205,   206,   209,   215,   497,
     498,   241,    61,   182,   183,   184,   185,   186,   189,   190,
     193,   194,   195,   198,   200,   201,   202,   204,   205,   206,
     209,   215,   493,   494,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,    14,
      15,    16,   251,   252,   241,   241,   241,   241,   241,   241,
     241,   244,   250,   175,   244,   131,   131,   241,   131,   175,
     244,   131,   110,   131,   131,   131,   241,   131,   244,   131,
     241,   244,   131,   131,   110,   344,   345,   241,   241,   241,
       1,   100,   165,   239,   291,   292,   293,   294,   295,   241,
     241,   131,   175,   244,   131,   131,   131,   244,   131,   241,
     131,   131,   131,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   148,
     149,   263,   264,   241,   241,   241,   241,   241,   131,   244,
     131,   241,   131,   244,   241,   241,   249,   249,   249,   249,
     249,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,    10,
      12,   207,   221,   406,   407,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   136,   437,   438,
     241,   245,   241,   245,   251,   251,   251,    11,   177,   517,
     518,   241,   241,    11,   177,   511,   512,   241,   241,   241,
     241,    20,    44,    53,    59,    75,   101,   109,   151,   169,
     358,   359,   241,   241,   241,   241,   241,   241,   136,   417,
     418,   241,    61,   203,   207,   338,   339,   241,   241,   180,
     245,   343,   241,   244,   296,   244,   242,   292,   241,   241,
       5,    32,    51,    57,    74,    98,   105,   119,   137,   139,
     140,   191,   201,   210,   214,   216,   226,   236,   315,   316,
     241,   241,   241,    61,   182,   183,   184,   185,   186,   189,
     190,   193,   194,   195,   198,   200,   201,   202,   204,   205,
     206,   209,   215,   311,   312,   241,   241,   241,   241,   241,
     245,   241,    74,   150,   181,   191,   198,   210,   212,   213,
     226,   236,   382,   383,   241,   241,    74,   150,   181,   191,
     198,   210,   212,   213,   226,   236,   391,   392,   241,   245,
     241,   245,   498,   494,   241,   245,   241,   245,   241,   245,
     241,   245,   241,   245,   110,   345,   241,   131,   244,   211,
     252,   241,   241,   245,   241,   245,   264,   241,   245,   241,
     245,   407,   438,   518,   512,   359,   418,   339,   241,    51,
      72,    74,   115,   190,   191,   227,   297,   298,   241,   241,
     316,   312,   383,   392,   241,   245,   298
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
        case 27:

/* Line 1806 of yacc.c  */
#line 407 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 409 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 413 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 417 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 421 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 425 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 429 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 434 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 435 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 436 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 437 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 452 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 478 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 484 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
  {
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_SSLV3))
    {
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
      SSL_CTX_set_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
    }

    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_TLSV1))
    {
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
      SSL_CTX_set_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
    }
  }
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 505 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 511 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 519 "ircd_parser.y"
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

  case 74:

/* Line 1806 of yacc.c  */
#line 558 "ircd_parser.y"
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

  case 75:

/* Line 1806 of yacc.c  */
#line 617 "ircd_parser.y"
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
        SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);
        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 641 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
  }
#endif
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 651 "ircd_parser.y"
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

  case 78:

/* Line 1806 of yacc.c  */
#line 666 "ircd_parser.y"
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

  case 79:

/* Line 1806 of yacc.c  */
#line 681 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 690 "ircd_parser.y"
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

  case 81:

/* Line 1806 of yacc.c  */
#line 704 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 713 "ircd_parser.y"
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

  case 83:

/* Line 1806 of yacc.c  */
#line 741 "ircd_parser.y"
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

  case 84:

/* Line 1806 of yacc.c  */
#line 771 "ircd_parser.y"
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

  case 85:

/* Line 1806 of yacc.c  */
#line 794 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 809 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 818 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 827 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 845 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 857 "ircd_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 862 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 874 "ircd_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 879 "ircd_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 882 "ircd_parser.y"
    {
  lsize = 0;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 887 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 894 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 898 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 906 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 910 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 914 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 918 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 928 "ircd_parser.y"
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

  case 128:

/* Line 1806 of yacc.c  */
#line 941 "ircd_parser.y"
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

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->ipnum,
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1031 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1043 "ircd_parser.y"
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

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->ipnum,
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1080 "ircd_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1092 "ircd_parser.y"
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1103 "ircd_parser.y"
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

  case 145:

/* Line 1806 of yacc.c  */
#line 1145 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1154 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1161 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1165 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1169 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1173 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1177 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1181 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1189 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1193 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1197 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1201 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1205 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1209 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1213 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1221 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1225 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1233 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1237 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1243 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1250 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1254 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1258 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1262 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1266 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1270 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1274 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1278 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1282 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1286 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1290 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1294 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1298 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1302 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1306 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1310 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1314 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1318 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1328 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1335 "ircd_parser.y"
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

  case 210:

/* Line 1806 of yacc.c  */
#line 1393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1402 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1408 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1414 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1420 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1426 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1432 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1438 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1444 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1450 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1462 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1468 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1484 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1493 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1499 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1503 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1517 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1522 "ircd_parser.y"
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

  case 244:

/* Line 1806 of yacc.c  */
#line 1536 "ircd_parser.y"
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

  case 245:

/* Line 1806 of yacc.c  */
#line 1556 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1565 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1577 "ircd_parser.y"
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

  case 248:

/* Line 1806 of yacc.c  */
#line 1589 "ircd_parser.y"
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

  case 260:

/* Line 1806 of yacc.c  */
#line 1651 "ircd_parser.y"
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

  case 261:

/* Line 1806 of yacc.c  */
#line 1688 "ircd_parser.y"
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

  case 262:

/* Line 1806 of yacc.c  */
#line 1701 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1710 "ircd_parser.y"
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

  case 264:

/* Line 1806 of yacc.c  */
#line 1721 "ircd_parser.y"
    {
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1726 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1734 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1738 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1742 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1746 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1750 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1754 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1758 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1765 "ircd_parser.y"
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

  case 278:

/* Line 1806 of yacc.c  */
#line 1784 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1794 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1807 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1814 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1826 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1835 "ircd_parser.y"
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

  case 290:

/* Line 1806 of yacc.c  */
#line 1850 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 296:

/* Line 1806 of yacc.c  */
#line 1868 "ircd_parser.y"
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

  case 297:

/* Line 1806 of yacc.c  */
#line 1883 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1891 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1911 "ircd_parser.y"
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

  case 307:

/* Line 1806 of yacc.c  */
#line 1933 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1940 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1944 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1948 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1952 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1956 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1960 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1964 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1972 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1985 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1992 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2005 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 2011 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2022 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2026 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2030 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2034 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2038 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2042 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2046 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2050 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2054 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2063 "ircd_parser.y"
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

  case 344:

/* Line 1806 of yacc.c  */
#line 2078 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->host &&
        yy_aconf->passwd && yy_aconf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
      {
        delete_conf_item(yy_conf);
	yy_conf = NULL;
	yy_aconf = NULL;
      }
    }
    else
    {
      /* Even if yy_conf ->name is NULL
       * should still unhook any hub/leaf confs still pending
       */
      unhook_hub_leaf_confs();

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

      yy_aconf = NULL;
      yy_conf = NULL;
    }

      /*
       * yy_conf is still pointing at the server that is having
       * a connect block built for it. This means, y_aconf->name 
       * points to the actual irc name this server will be known as.
       * Now this new server has a set or even just one hub_mask (or leaf_mask)
       * given in the link list at yy_hconf. Fill in the HUB confs
       * from this link list now.
       */        
      DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
      {
	struct ConfItem *new_hub_conf;
	struct MatchItem *match_item;

	yy_hconf = ptr->data;

	/* yy_conf == NULL is a fatal error for this connect block! */
	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_hub_conf = make_conf_item(HUB_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_hub_conf);
	  DupString(new_hub_conf->name, yy_conf->name);
	  if (yy_hconf->user != NULL)
	    DupString(match_item->user, yy_hconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_hconf->host != NULL)
	    DupString(match_item->host, yy_hconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_hconf->node, &hub_conf_list);
	free_collect_item(yy_hconf);
      }

      /* Ditto for the LEAF confs */

      DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
      {
	struct ConfItem *new_leaf_conf;
	struct MatchItem *match_item;

	yy_lconf = ptr->data;

	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_leaf_conf = make_conf_item(LEAF_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_leaf_conf);
	  DupString(new_leaf_conf->name, yy_conf->name);
	  if (yy_lconf->user != NULL)
	    DupString(match_item->user, yy_lconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_lconf->host != NULL)
	    DupString(match_item->host, yy_lconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_lconf->node, &leaf_conf_list);
	free_collect_item(yy_lconf);
      }
      MyFree(class_name);
      class_name = NULL;
      yy_conf = NULL;
      yy_aconf = NULL;
  }
}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 2200 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 2212 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 2221 "ircd_parser.y"
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

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 2247 "ircd_parser.y"
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

  case 365:

/* Line 1806 of yacc.c  */
#line 2265 "ircd_parser.y"
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

  case 366:

/* Line 1806 of yacc.c  */
#line 2283 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 2289 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 2293 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 2301 "ircd_parser.y"
    {
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2306 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2310 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2314 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2318 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2324 "ircd_parser.y"
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

  case 378:

/* Line 1806 of yacc.c  */
#line 2335 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2348 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2361 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 2370 "ircd_parser.y"
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

  case 382:

/* Line 1806 of yacc.c  */
#line 2388 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2395 "ircd_parser.y"
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
        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2451 "ircd_parser.y"
    {
}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 2456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 2465 "ircd_parser.y"
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

  case 396:

/* Line 1806 of yacc.c  */
#line 2484 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2493 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2497 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
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

  case 404:

/* Line 1806 of yacc.c  */
#line 2519 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2525 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 2539 "ircd_parser.y"
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

  case 412:

/* Line 1806 of yacc.c  */
#line 2557 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 2564 "ircd_parser.y"
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

  case 414:

/* Line 1806 of yacc.c  */
#line 2604 "ircd_parser.y"
    {
}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 2609 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 2618 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 2624 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 2668 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 2673 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2678 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2683 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2688 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2693 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2698 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2703 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2708 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2713 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2718 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2723 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2728 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2733 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2738 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2743 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2748 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2753 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2759 "ircd_parser.y"
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

  case 501:

/* Line 1806 of yacc.c  */
#line 2770 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2775 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2784 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2789 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2794 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2799 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2804 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2809 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2812 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2817 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2820 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2825 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2830 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2835 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2840 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2845 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2850 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2855 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2860 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2865 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2876 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2881 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2886 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2891 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2900 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2909 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2914 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2919 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2924 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2930 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2933 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2939 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2942 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2945 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2948 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2951 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2954 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2957 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2960 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2963 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2966 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2969 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2972 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2975 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2978 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2981 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2984 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2987 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2992 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 2998 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3001 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3004 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3007 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3010 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3013 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3016 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3019 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3022 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3025 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3028 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3031 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3034 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3037 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3043 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3046 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3049 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3052 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3055 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3065 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3070 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3091 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    /*
     * since we re-allocate yy_conf/yy_aconf after the end of action=, at the
     * end we will have one extra, so we should free it.
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
    {
      delete_conf_item(yy_conf);
      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3117 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3129 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3145 "ircd_parser.y"
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

  case 601:

/* Line 1806 of yacc.c  */
#line 3179 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3188 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3192 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr, *next_ptr;

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      yy_tmp = ptr->data;
      new_conf = make_conf_item(GDENY_TYPE);
      new_aconf = map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      else
        DupString(new_conf->name, "*");
      if (yy_aconf->user != NULL)
         DupString(new_aconf->user, yy_tmp->user);
      else   
        DupString(new_aconf->user, "*");
      if (yy_aconf->host != NULL)
        DupString(new_aconf->host, yy_tmp->host);
      else
        DupString(new_aconf->host, "*");

      dlinkDelete(&yy_tmp->node, &col_conf_list);
    }

    /*
     * In case someone has fed us with more than one action= after user/name
     * which would leak memory  -Michael
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
      delete_conf_item(yy_conf);

    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3243 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 3267 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 3272 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 3277 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 3282 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3287 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3292 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3297 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3302 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3307 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3312 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3317 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3327 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3332 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3337 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3342 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3347 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3352 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3371 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3377 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3383 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3392 "ircd_parser.y"
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

  case 663:

/* Line 1806 of yacc.c  */
#line 3406 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3412 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3418 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7694 "ircd_parser.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



