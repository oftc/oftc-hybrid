/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     CAN_IDLE = 276,
     CHANNEL = 277,
     CIDR_BITLEN_IPV4 = 278,
     CIDR_BITLEN_IPV6 = 279,
     CIPHER_PREFERENCE = 280,
     CLASS = 281,
     COMPRESSED = 282,
     COMPRESSION_LEVEL = 283,
     CONNECT = 284,
     CONNECTFREQ = 285,
     CRYPTLINK = 286,
     DEFAULT_CIPHER_PREFERENCE = 287,
     DEFAULT_FLOODCOUNT = 288,
     DEFAULT_SPLIT_SERVER_COUNT = 289,
     DEFAULT_SPLIT_USER_COUNT = 290,
     DENY = 291,
     DESCRIPTION = 292,
     DIE = 293,
     DISABLE_AUTH = 294,
     DISABLE_FAKE_CHANNELS = 295,
     DISABLE_HIDDEN = 296,
     DISABLE_LOCAL_CHANNELS = 297,
     DISABLE_REMOTE_COMMANDS = 298,
     DOT_IN_IP6_ADDR = 299,
     DOTS_IN_IDENT = 300,
     DURATION = 301,
     EGDPOOL_PATH = 302,
     EMAIL = 303,
     ENABLE = 304,
     ENCRYPTED = 305,
     EXCEED_LIMIT = 306,
     EXEMPT = 307,
     FAILED_OPER_NOTICE = 308,
     FAKENAME = 309,
     IRCD_FLAGS = 310,
     FLATTEN_LINKS = 311,
     FFAILED_OPERLOG = 312,
     FKILLLOG = 313,
     FKLINELOG = 314,
     FGLINELOG = 315,
     FIOERRLOG = 316,
     FOPERLOG = 317,
     FOPERSPYLOG = 318,
     FUSERLOG = 319,
     GECOS = 320,
     GENERAL = 321,
     GLINE = 322,
     GLINES = 323,
     GLINE_EXEMPT = 324,
     GLINE_LOG = 325,
     GLINE_TIME = 326,
     GLINE_MIN_CIDR = 327,
     GLINE_MIN_CIDR6 = 328,
     GLOBAL_KILL = 329,
     IRCD_AUTH = 330,
     NEED_IDENT = 331,
     HAVENT_READ_CONF = 332,
     HIDDEN = 333,
     HIDDEN_ADMIN = 334,
     HIDDEN_NAME = 335,
     HIDDEN_OPER = 336,
     HIDE_SERVER_IPS = 337,
     HIDE_SERVERS = 338,
     HIDE_SPOOF_IPS = 339,
     HOST = 340,
     HUB = 341,
     HUB_MASK = 342,
     IDLETIME = 343,
     IGNORE_BOGUS_TS = 344,
     INVISIBLE_ON_CONNECT = 345,
     IP = 346,
     KILL = 347,
     KILL_CHASE_TIME_LIMIT = 348,
     KLINE = 349,
     KLINE_EXEMPT = 350,
     KLINE_REASON = 351,
     KLINE_WITH_REASON = 352,
     KNOCK_DELAY = 353,
     KNOCK_DELAY_CHANNEL = 354,
     LAZYLINK = 355,
     LEAF_MASK = 356,
     LINKS_DELAY = 357,
     LISTEN = 358,
     T_LOG = 359,
     LOGGING = 360,
     LOG_LEVEL = 361,
     MAX_ACCEPT = 362,
     MAX_BANS = 363,
     MAX_CHANS_PER_USER = 364,
     MAX_GLOBAL = 365,
     MAX_IDENT = 366,
     MAX_LOCAL = 367,
     MAX_NICK_CHANGES = 368,
     MAX_NICK_TIME = 369,
     MAX_NUMBER = 370,
     MAX_TARGETS = 371,
     MESSAGE_LOCALE = 372,
     MIN_NONWILDCARD = 373,
     MIN_NONWILDCARD_SIMPLE = 374,
     MODULE = 375,
     MODULES = 376,
     NAME = 377,
     NEED_PASSWORD = 378,
     NETWORK_DESC = 379,
     NETWORK_NAME = 380,
     NICK = 381,
     NICK_CHANGES = 382,
     NO_CREATE_ON_SPLIT = 383,
     NO_JOIN_ON_SPLIT = 384,
     NO_OPER_FLOOD = 385,
     NO_TILDE = 386,
     NOT = 387,
     NUMBER = 388,
     NUMBER_PER_IDENT = 389,
     NUMBER_PER_CIDR = 390,
     NUMBER_PER_IP = 391,
     NUMBER_PER_IP_GLOBAL = 392,
     OPERATOR = 393,
     OPERS_BYPASS_CALLERID = 394,
     OPER_LOG = 395,
     OPER_ONLY_UMODES = 396,
     OPER_PASS_RESV = 397,
     OPER_SPY_T = 398,
     OPER_UMODES = 399,
     JOIN_FLOOD_COUNT = 400,
     JOIN_FLOOD_TIME = 401,
     PACE_WAIT = 402,
     PACE_WAIT_SIMPLE = 403,
     PASSWORD = 404,
     PATH = 405,
     PING_COOKIE = 406,
     PING_TIME = 407,
     PING_WARNING = 408,
     PORT = 409,
     QSTRING = 410,
     QUIET_ON_BAN = 411,
     REASON = 412,
     REDIRPORT = 413,
     REDIRSERV = 414,
     REGEX_T = 415,
     REHASH = 416,
     TREJECT_HOLD_TIME = 417,
     REMOTE = 418,
     REMOTEBAN = 419,
     RESTRICT_CHANNELS = 420,
     RESTRICTED = 421,
     RSA_PRIVATE_KEY_FILE = 422,
     RSA_PUBLIC_KEY_FILE = 423,
     SSL_CERTIFICATE_FILE = 424,
     RESV = 425,
     RESV_EXEMPT = 426,
     SECONDS = 427,
     MINUTES = 428,
     HOURS = 429,
     DAYS = 430,
     WEEKS = 431,
     SENDQ = 432,
     SEND_PASSWORD = 433,
     SERVERHIDE = 434,
     SERVERINFO = 435,
     SERVLINK_PATH = 436,
     IRCD_SID = 437,
     TKLINE_EXPIRE_NOTICES = 438,
     T_SHARED = 439,
     T_CLUSTER = 440,
     TYPE = 441,
     SHORT_MOTD = 442,
     SILENT = 443,
     SPOOF = 444,
     SPOOF_NOTICE = 445,
     STATS_E_DISABLED = 446,
     STATS_I_OPER_ONLY = 447,
     STATS_K_OPER_ONLY = 448,
     STATS_O_OPER_ONLY = 449,
     STATS_P_OPER_ONLY = 450,
     TBOOL = 451,
     TMASKED = 452,
     T_REJECT = 453,
     TS_MAX_DELTA = 454,
     TS_WARN_DELTA = 455,
     TWODOTS = 456,
     T_ALL = 457,
     T_BOTS = 458,
     T_SOFTCALLERID = 459,
     T_CALLERID = 460,
     T_CCONN = 461,
     T_CCONN_FULL = 462,
     T_CLIENT_FLOOD = 463,
     T_DEAF = 464,
     T_DEBUG = 465,
     T_DRONE = 466,
     T_EXTERNAL = 467,
     T_FULL = 468,
     T_INVISIBLE = 469,
     T_IPV4 = 470,
     T_IPV6 = 471,
     T_LOCOPS = 472,
     T_LOGPATH = 473,
     T_L_CRIT = 474,
     T_L_DEBUG = 475,
     T_L_ERROR = 476,
     T_L_INFO = 477,
     T_L_NOTICE = 478,
     T_L_TRACE = 479,
     T_L_WARN = 480,
     T_MAX_CLIENTS = 481,
     T_NCHANGE = 482,
     T_OPERWALL = 483,
     T_REJ = 484,
     T_SERVNOTICE = 485,
     T_SKILL = 486,
     T_SPY = 487,
     T_SSL = 488,
     T_UMODES = 489,
     T_UNAUTH = 490,
     T_UNRESV = 491,
     T_UNXLINE = 492,
     T_WALLOP = 493,
     THROTTLE_TIME = 494,
     TOPICBURST = 495,
     TRUE_NO_OPER_FLOOD = 496,
     TKLINE = 497,
     TXLINE = 498,
     TRESV = 499,
     UNKLINE = 500,
     USER = 501,
     USE_EGD = 502,
     USE_EXCEPT = 503,
     USE_INVEX = 504,
     USE_KNOCK = 505,
     USE_LOGGING = 506,
     USE_WHOIS_ACTUALLY = 507,
     VHOST = 508,
     VHOST6 = 509,
     XLINE = 510,
     WARN = 511,
     WARN_NO_NLINE = 512
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
#define CAN_IDLE 276
#define CHANNEL 277
#define CIDR_BITLEN_IPV4 278
#define CIDR_BITLEN_IPV6 279
#define CIPHER_PREFERENCE 280
#define CLASS 281
#define COMPRESSED 282
#define COMPRESSION_LEVEL 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CRYPTLINK 286
#define DEFAULT_CIPHER_PREFERENCE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_SPLIT_SERVER_COUNT 289
#define DEFAULT_SPLIT_USER_COUNT 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_AUTH 294
#define DISABLE_FAKE_CHANNELS 295
#define DISABLE_HIDDEN 296
#define DISABLE_LOCAL_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DOT_IN_IP6_ADDR 299
#define DOTS_IN_IDENT 300
#define DURATION 301
#define EGDPOOL_PATH 302
#define EMAIL 303
#define ENABLE 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define FAILED_OPER_NOTICE 308
#define FAKENAME 309
#define IRCD_FLAGS 310
#define FLATTEN_LINKS 311
#define FFAILED_OPERLOG 312
#define FKILLLOG 313
#define FKLINELOG 314
#define FGLINELOG 315
#define FIOERRLOG 316
#define FOPERLOG 317
#define FOPERSPYLOG 318
#define FUSERLOG 319
#define GECOS 320
#define GENERAL 321
#define GLINE 322
#define GLINES 323
#define GLINE_EXEMPT 324
#define GLINE_LOG 325
#define GLINE_TIME 326
#define GLINE_MIN_CIDR 327
#define GLINE_MIN_CIDR6 328
#define GLOBAL_KILL 329
#define IRCD_AUTH 330
#define NEED_IDENT 331
#define HAVENT_READ_CONF 332
#define HIDDEN 333
#define HIDDEN_ADMIN 334
#define HIDDEN_NAME 335
#define HIDDEN_OPER 336
#define HIDE_SERVER_IPS 337
#define HIDE_SERVERS 338
#define HIDE_SPOOF_IPS 339
#define HOST 340
#define HUB 341
#define HUB_MASK 342
#define IDLETIME 343
#define IGNORE_BOGUS_TS 344
#define INVISIBLE_ON_CONNECT 345
#define IP 346
#define KILL 347
#define KILL_CHASE_TIME_LIMIT 348
#define KLINE 349
#define KLINE_EXEMPT 350
#define KLINE_REASON 351
#define KLINE_WITH_REASON 352
#define KNOCK_DELAY 353
#define KNOCK_DELAY_CHANNEL 354
#define LAZYLINK 355
#define LEAF_MASK 356
#define LINKS_DELAY 357
#define LISTEN 358
#define T_LOG 359
#define LOGGING 360
#define LOG_LEVEL 361
#define MAX_ACCEPT 362
#define MAX_BANS 363
#define MAX_CHANS_PER_USER 364
#define MAX_GLOBAL 365
#define MAX_IDENT 366
#define MAX_LOCAL 367
#define MAX_NICK_CHANGES 368
#define MAX_NICK_TIME 369
#define MAX_NUMBER 370
#define MAX_TARGETS 371
#define MESSAGE_LOCALE 372
#define MIN_NONWILDCARD 373
#define MIN_NONWILDCARD_SIMPLE 374
#define MODULE 375
#define MODULES 376
#define NAME 377
#define NEED_PASSWORD 378
#define NETWORK_DESC 379
#define NETWORK_NAME 380
#define NICK 381
#define NICK_CHANGES 382
#define NO_CREATE_ON_SPLIT 383
#define NO_JOIN_ON_SPLIT 384
#define NO_OPER_FLOOD 385
#define NO_TILDE 386
#define NOT 387
#define NUMBER 388
#define NUMBER_PER_IDENT 389
#define NUMBER_PER_CIDR 390
#define NUMBER_PER_IP 391
#define NUMBER_PER_IP_GLOBAL 392
#define OPERATOR 393
#define OPERS_BYPASS_CALLERID 394
#define OPER_LOG 395
#define OPER_ONLY_UMODES 396
#define OPER_PASS_RESV 397
#define OPER_SPY_T 398
#define OPER_UMODES 399
#define JOIN_FLOOD_COUNT 400
#define JOIN_FLOOD_TIME 401
#define PACE_WAIT 402
#define PACE_WAIT_SIMPLE 403
#define PASSWORD 404
#define PATH 405
#define PING_COOKIE 406
#define PING_TIME 407
#define PING_WARNING 408
#define PORT 409
#define QSTRING 410
#define QUIET_ON_BAN 411
#define REASON 412
#define REDIRPORT 413
#define REDIRSERV 414
#define REGEX_T 415
#define REHASH 416
#define TREJECT_HOLD_TIME 417
#define REMOTE 418
#define REMOTEBAN 419
#define RESTRICT_CHANNELS 420
#define RESTRICTED 421
#define RSA_PRIVATE_KEY_FILE 422
#define RSA_PUBLIC_KEY_FILE 423
#define SSL_CERTIFICATE_FILE 424
#define RESV 425
#define RESV_EXEMPT 426
#define SECONDS 427
#define MINUTES 428
#define HOURS 429
#define DAYS 430
#define WEEKS 431
#define SENDQ 432
#define SEND_PASSWORD 433
#define SERVERHIDE 434
#define SERVERINFO 435
#define SERVLINK_PATH 436
#define IRCD_SID 437
#define TKLINE_EXPIRE_NOTICES 438
#define T_SHARED 439
#define T_CLUSTER 440
#define TYPE 441
#define SHORT_MOTD 442
#define SILENT 443
#define SPOOF 444
#define SPOOF_NOTICE 445
#define STATS_E_DISABLED 446
#define STATS_I_OPER_ONLY 447
#define STATS_K_OPER_ONLY 448
#define STATS_O_OPER_ONLY 449
#define STATS_P_OPER_ONLY 450
#define TBOOL 451
#define TMASKED 452
#define T_REJECT 453
#define TS_MAX_DELTA 454
#define TS_WARN_DELTA 455
#define TWODOTS 456
#define T_ALL 457
#define T_BOTS 458
#define T_SOFTCALLERID 459
#define T_CALLERID 460
#define T_CCONN 461
#define T_CCONN_FULL 462
#define T_CLIENT_FLOOD 463
#define T_DEAF 464
#define T_DEBUG 465
#define T_DRONE 466
#define T_EXTERNAL 467
#define T_FULL 468
#define T_INVISIBLE 469
#define T_IPV4 470
#define T_IPV6 471
#define T_LOCOPS 472
#define T_LOGPATH 473
#define T_L_CRIT 474
#define T_L_DEBUG 475
#define T_L_ERROR 476
#define T_L_INFO 477
#define T_L_NOTICE 478
#define T_L_TRACE 479
#define T_L_WARN 480
#define T_MAX_CLIENTS 481
#define T_NCHANGE 482
#define T_OPERWALL 483
#define T_REJ 484
#define T_SERVNOTICE 485
#define T_SKILL 486
#define T_SPY 487
#define T_SSL 488
#define T_UMODES 489
#define T_UNAUTH 490
#define T_UNRESV 491
#define T_UNXLINE 492
#define T_WALLOP 493
#define THROTTLE_TIME 494
#define TOPICBURST 495
#define TRUE_NO_OPER_FLOOD 496
#define TKLINE 497
#define TXLINE 498
#define TRESV 499
#define UNKLINE 500
#define USER 501
#define USE_EGD 502
#define USE_EXCEPT 503
#define USE_INVEX 504
#define USE_KNOCK 505
#define USE_LOGGING 506
#define USE_WHOIS_ACTUALLY 507
#define VHOST 508
#define VHOST6 509
#define XLINE 510
#define WARN 511
#define WARN_NO_NLINE 512




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "ircd.h"
#include "tools.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "pcre.h"
#include "irc_string.h"
#include "irc_getaddrinfo.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
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

extern dlink_list gdeny_items; /* XXX */

static char *resv_reason = NULL;
static char *listener_address = NULL;
static int not_atom = 0;

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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 134 "ircd_parser.y"
{
  int number;
  char *string;
}
/* Line 193 of yacc.c.  */
#line 724 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 737 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1404

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  263
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  341
/* YYNRULES -- Number of rules.  */
#define YYNRULES  734
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1478

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   512

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   262,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   258,
       2,   261,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   260,     2,   259,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257
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
     154,   156,   158,   161,   166,   171,   176,   181,   186,   191,
     196,   201,   206,   211,   216,   222,   225,   227,   229,   231,
     233,   236,   241,   246,   251,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     289,   294,   299,   304,   309,   314,   319,   324,   329,   334,
     339,   344,   349,   354,   359,   364,   369,   374,   379,   380,
     388,   389,   391,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   443,   448,   450,
     455,   460,   465,   470,   475,   476,   482,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   526,   531,   536,
     541,   546,   551,   556,   561,   566,   571,   576,   581,   586,
     591,   596,   597,   603,   607,   609,   610,   614,   615,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   650,   651,   659,   660,   662,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   689,   691,   693,   696,   701,   703,   708,   713,
     718,   723,   728,   733,   738,   743,   748,   753,   758,   763,
     764,   771,   772,   778,   782,   784,   786,   788,   791,   793,
     795,   797,   799,   801,   804,   805,   811,   815,   817,   819,
     823,   828,   833,   834,   841,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   878,   881,   886,   891,   896,   901,   906,   907,
     913,   917,   919,   920,   924,   925,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   948,   953,   958,   963,
     968,   973,   978,   983,   988,   993,   998,   999,  1006,  1009,
    1011,  1013,  1015,  1017,  1020,  1025,  1030,  1035,  1036,  1043,
    1046,  1048,  1050,  1052,  1054,  1057,  1062,  1067,  1068,  1074,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1103,  1110,  1113,  1115,  1117,  1119,  1122,
    1127,  1128,  1134,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1162,  1163,  1171,  1172,  1174,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,
    1217,  1220,  1225,  1227,  1232,  1237,  1242,  1247,  1252,  1257,
    1262,  1267,  1268,  1274,  1278,  1280,  1281,  1285,  1286,  1289,
    1291,  1293,  1295,  1297,  1299,  1301,  1306,  1311,  1316,  1321,
    1326,  1331,  1336,  1341,  1346,  1351,  1352,  1359,  1360,  1366,
    1370,  1372,  1374,  1377,  1379,  1381,  1383,  1385,  1387,  1392,
    1397,  1398,  1405,  1408,  1410,  1412,  1414,  1416,  1421,  1426,
    1432,  1435,  1437,  1439,  1441,  1446,  1447,  1454,  1455,  1461,
    1465,  1467,  1469,  1472,  1474,  1476,  1478,  1480,  1482,  1487,
    1492,  1498,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,
    1620,  1625,  1630,  1635,  1640,  1645,  1650,  1655,  1660,  1665,
    1670,  1675,  1680,  1685,  1690,  1695,  1700,  1705,  1710,  1715,
    1720,  1725,  1730,  1735,  1740,  1745,  1750,  1755,  1760,  1765,
    1770,  1775,  1780,  1785,  1790,  1795,  1800,  1805,  1810,  1815,
    1820,  1825,  1830,  1835,  1840,  1845,  1850,  1855,  1860,  1865,
    1866,  1872,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,
    1912,  1914,  1916,  1917,  1923,  1927,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,
    1957,  1959,  1961,  1963,  1965,  1967,  1972,  1977,  1982,  1987,
    1992,  1993,  2000,  2003,  2005,  2007,  2009,  2011,  2013,  2015,
    2017,  2019,  2024,  2029,  2030,  2036,  2040,  2042,  2044,  2046,
    2051,  2056,  2057,  2063,  2067,  2069,  2071,  2073,  2079,  2082,
    2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,
    2104,  2106,  2108,  2110,  2112,  2114,  2116,  2118,  2120,  2122,
    2127,  2132,  2137,  2142,  2147,  2152,  2157,  2162,  2167,  2172,
    2177,  2182,  2187,  2192,  2197,  2202,  2207,  2212,  2218,  2221,
    2223,  2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2244,
    2249,  2254,  2259,  2264,  2269
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     264,     0,    -1,    -1,   264,   265,    -1,   289,    -1,   295,
      -1,   310,    -1,   573,    -1,   347,    -1,   366,    -1,   380,
      -1,   275,    -1,   594,    -1,   406,    -1,   413,    -1,   423,
      -1,   432,    -1,   463,    -1,   473,    -1,   479,    -1,   493,
      -1,   557,    -1,   483,    -1,   270,    -1,     1,   258,    -1,
       1,   259,    -1,    -1,   267,    -1,   133,   266,    -1,   133,
     172,   266,    -1,   133,   173,   266,    -1,   133,   174,   266,
      -1,   133,   175,   266,    -1,   133,   176,   266,    -1,    -1,
     269,    -1,   133,   268,    -1,   133,    14,   268,    -1,   133,
      15,   268,    -1,   133,    16,   268,    -1,   121,   260,   271,
     259,   258,    -1,   271,   272,    -1,   272,    -1,   273,    -1,
     274,    -1,     1,   258,    -1,   120,   261,   155,   258,    -1,
     150,   261,   155,   258,    -1,   180,   260,   276,   259,   258,
      -1,   276,   277,    -1,   277,    -1,   280,    -1,   285,    -1,
     288,    -1,   282,    -1,   283,    -1,   284,    -1,   287,    -1,
     279,    -1,   286,    -1,   281,    -1,   278,    -1,     1,   258,
      -1,   169,   261,   155,   258,    -1,   167,   261,   155,   258,
      -1,   122,   261,   155,   258,    -1,   182,   261,   155,   258,
      -1,    37,   261,   155,   258,    -1,   125,   261,   155,   258,
      -1,   124,   261,   155,   258,    -1,   253,   261,   155,   258,
      -1,   254,   261,   155,   258,    -1,   226,   261,   133,   258,
      -1,    86,   261,   196,   258,    -1,     5,   260,   290,   259,
     258,    -1,   290,   291,    -1,   291,    -1,   292,    -1,   294,
      -1,   293,    -1,     1,   258,    -1,   122,   261,   155,   258,
      -1,    48,   261,   155,   258,    -1,    37,   261,   155,   258,
      -1,   105,   260,   296,   259,   258,    -1,   296,   297,    -1,
     297,    -1,   298,    -1,   299,    -1,   308,    -1,   309,    -1,
     300,    -1,   302,    -1,   304,    -1,   305,    -1,   307,    -1,
     303,    -1,   306,    -1,   301,    -1,     1,   258,    -1,   218,
     261,   155,   258,    -1,   140,   261,   155,   258,    -1,    64,
     261,   155,   258,    -1,    57,   261,   155,   258,    -1,    62,
     261,   155,   258,    -1,    63,   261,   155,   258,    -1,    60,
     261,   155,   258,    -1,    59,   261,   155,   258,    -1,    61,
     261,   155,   258,    -1,    58,   261,   155,   258,    -1,   106,
     261,   219,   258,    -1,   106,   261,   221,   258,    -1,   106,
     261,   225,   258,    -1,   106,   261,   223,   258,    -1,   106,
     261,   224,   258,    -1,   106,   261,   222,   258,    -1,   106,
     261,   220,   258,    -1,   251,   261,   196,   258,    -1,    -1,
     138,   311,   312,   260,   313,   259,   258,    -1,    -1,   316,
      -1,   313,   314,    -1,   314,    -1,   315,    -1,   317,    -1,
     318,    -1,   337,    -1,   338,    -1,   322,    -1,   321,    -1,
     326,    -1,   327,    -1,   329,    -1,   330,    -1,   331,    -1,
     332,    -1,   333,    -1,   328,    -1,   334,    -1,   335,    -1,
     336,    -1,   339,    -1,   319,    -1,   320,    -1,   340,    -1,
       1,   258,    -1,   122,   261,   155,   258,    -1,   155,    -1,
     246,   261,   155,   258,    -1,   149,   261,   155,   258,    -1,
      50,   261,   196,   258,    -1,   168,   261,   155,   258,    -1,
      26,   261,   155,   258,    -1,    -1,   234,   323,   261,   324,
     258,    -1,   324,   262,   325,    -1,   325,    -1,   203,    -1,
     206,    -1,   207,    -1,   209,    -1,   210,    -1,   213,    -1,
     231,    -1,   227,    -1,   229,    -1,   235,    -1,   232,    -1,
     212,    -1,   228,    -1,   230,    -1,   214,    -1,   238,    -1,
     204,    -1,   205,    -1,   217,    -1,    74,   261,   196,   258,
      -1,   163,   261,   196,   258,    -1,   164,   261,   196,   258,
      -1,    94,   261,   196,   258,    -1,   255,   261,   196,   258,
      -1,   245,   261,   196,   258,    -1,    67,   261,   196,   258,
      -1,   127,   261,   196,   258,    -1,    38,   261,   196,   258,
      -1,   161,   261,   196,   258,    -1,     5,   261,   196,   258,
      -1,    79,   261,   196,   258,    -1,    81,   261,   196,   258,
      -1,   228,   261,   196,   258,    -1,    -1,    55,   341,   261,
     342,   258,    -1,   342,   262,   343,    -1,   343,    -1,    -1,
     132,   344,   346,    -1,    -1,   345,   346,    -1,    74,    -1,
     163,    -1,    94,    -1,   245,    -1,   255,    -1,    67,    -1,
      38,    -1,   161,    -1,     5,    -1,    79,    -1,   127,    -1,
     228,    -1,   143,    -1,    81,    -1,   164,    -1,    50,    -1,
      -1,    26,   348,   349,   260,   350,   259,   258,    -1,    -1,
     353,    -1,   350,   351,    -1,   351,    -1,   352,    -1,   363,
      -1,   364,    -1,   354,    -1,   355,    -1,   365,    -1,   356,
      -1,   357,    -1,   358,    -1,   359,    -1,   360,    -1,   361,
      -1,   362,    -1,     1,   258,    -1,   122,   261,   155,   258,
      -1,   155,    -1,   152,   261,   267,   258,    -1,   153,   261,
     267,   258,    -1,   136,   261,   133,   258,    -1,    30,   261,
     267,   258,    -1,   115,   261,   133,   258,    -1,   110,   261,
     133,   258,    -1,   112,   261,   133,   258,    -1,   111,   261,
     133,   258,    -1,   177,   261,   269,   258,    -1,    23,   261,
     133,   258,    -1,    24,   261,   133,   258,    -1,   135,   261,
     133,   258,    -1,    -1,   103,   367,   260,   372,   259,   258,
      -1,    -1,    55,   369,   261,   370,   258,    -1,   370,   262,
     371,    -1,   371,    -1,   233,    -1,    78,    -1,   372,   373,
      -1,   373,    -1,   374,    -1,   368,    -1,   378,    -1,   379,
      -1,     1,   258,    -1,    -1,   154,   261,   376,   375,   258,
      -1,   376,   262,   377,    -1,   377,    -1,   133,    -1,   133,
     201,   133,    -1,    91,   261,   155,   258,    -1,    85,   261,
     155,   258,    -1,    -1,    75,   381,   260,   382,   259,   258,
      -1,   382,   383,    -1,   383,    -1,   384,    -1,   385,    -1,
     387,    -1,   389,    -1,   396,    -1,   397,    -1,   398,    -1,
     400,    -1,   401,    -1,   402,    -1,   386,    -1,   403,    -1,
     404,    -1,   399,    -1,   405,    -1,   388,    -1,     1,   258,
      -1,   246,   261,   155,   258,    -1,   149,   261,   155,   258,
      -1,   190,   261,   196,   258,    -1,    26,   261,   155,   258,
      -1,    50,   261,   196,   258,    -1,    -1,    55,   390,   261,
     391,   258,    -1,   391,   262,   392,    -1,   392,    -1,    -1,
     132,   393,   395,    -1,    -1,   394,   395,    -1,   190,    -1,
      51,    -1,    95,    -1,    76,    -1,    20,    -1,    21,    -1,
     131,    -1,    69,    -1,   171,    -1,   123,    -1,    95,   261,
     196,   258,    -1,    76,   261,   196,   258,    -1,    51,   261,
     196,   258,    -1,    20,   261,   196,   258,    -1,   131,   261,
     196,   258,    -1,    69,   261,   196,   258,    -1,   189,   261,
     155,   258,    -1,   159,   261,   155,   258,    -1,   158,   261,
     133,   258,    -1,   123,   261,   196,   258,    -1,    -1,   170,
     407,   260,   408,   259,   258,    -1,   408,   409,    -1,   409,
      -1,   410,    -1,   411,    -1,   412,    -1,     1,   258,    -1,
     157,   261,   155,   258,    -1,    22,   261,   155,   258,    -1,
     126,   261,   155,   258,    -1,    -1,   184,   414,   260,   415,
     259,   258,    -1,   415,   416,    -1,   416,    -1,   417,    -1,
     418,    -1,   419,    -1,     1,   258,    -1,   122,   261,   155,
     258,    -1,   246,   261,   155,   258,    -1,    -1,   186,   420,
     261,   421,   258,    -1,   421,   262,   422,    -1,   422,    -1,
      94,    -1,   242,    -1,   245,    -1,   255,    -1,   243,    -1,
     237,    -1,   170,    -1,   244,    -1,   236,    -1,   217,    -1,
     202,    -1,    -1,   185,   424,   260,   425,   259,   258,    -1,
     425,   426,    -1,   426,    -1,   427,    -1,   428,    -1,     1,
     258,    -1,   122,   261,   155,   258,    -1,    -1,   186,   429,
     261,   430,   258,    -1,   430,   262,   431,    -1,   431,    -1,
      94,    -1,   242,    -1,   245,    -1,   255,    -1,   243,    -1,
     237,    -1,   170,    -1,   244,    -1,   236,    -1,   217,    -1,
     202,    -1,    -1,    29,   433,   434,   260,   435,   259,   258,
      -1,    -1,   438,    -1,   435,   436,    -1,   436,    -1,   437,
      -1,   439,    -1,   440,    -1,   441,    -1,   442,    -1,   444,
      -1,   443,    -1,   445,    -1,   446,    -1,   459,    -1,   460,
      -1,   461,    -1,   457,    -1,   454,    -1,   456,    -1,   455,
      -1,   453,    -1,   462,    -1,   458,    -1,     1,   258,    -1,
     122,   261,   155,   258,    -1,   155,    -1,    85,   261,   155,
     258,    -1,   253,   261,   155,   258,    -1,   178,   261,   155,
     258,    -1,     3,   261,   155,   258,    -1,   154,   261,   133,
     258,    -1,     6,   261,   215,   258,    -1,     6,   261,   216,
     258,    -1,    54,   261,   155,   258,    -1,    -1,    55,   447,
     261,   448,   258,    -1,   448,   262,   449,    -1,   449,    -1,
      -1,   132,   450,   452,    -1,    -1,   451,   452,    -1,   100,
      -1,    27,    -1,    31,    -1,    10,    -1,    12,    -1,   240,
      -1,   168,   261,   155,   258,    -1,    50,   261,   196,   258,
      -1,    31,   261,   196,   258,    -1,    27,   261,   196,   258,
      -1,    10,   261,   196,   258,    -1,   240,   261,   196,   258,
      -1,    87,   261,   155,   258,    -1,   101,   261,   155,   258,
      -1,    26,   261,   155,   258,    -1,    25,   261,   155,   258,
      -1,    -1,    92,   464,   260,   469,   259,   258,    -1,    -1,
     186,   466,   261,   467,   258,    -1,   467,   262,   468,    -1,
     468,    -1,   160,    -1,   469,   470,    -1,   470,    -1,   471,
      -1,   472,    -1,   465,    -1,     1,    -1,   246,   261,   155,
     258,    -1,   157,   261,   155,   258,    -1,    -1,    36,   474,
     260,   475,   259,   258,    -1,   475,   476,    -1,   476,    -1,
     477,    -1,   478,    -1,     1,    -1,    91,   261,   155,   258,
      -1,   157,   261,   155,   258,    -1,    52,   260,   480,   259,
     258,    -1,   480,   481,    -1,   481,    -1,   482,    -1,     1,
      -1,    91,   261,   155,   258,    -1,    -1,    65,   484,   260,
     489,   259,   258,    -1,    -1,   186,   486,   261,   487,   258,
      -1,   487,   262,   488,    -1,   488,    -1,   160,    -1,   489,
     490,    -1,   490,    -1,   491,    -1,   492,    -1,   485,    -1,
       1,    -1,   122,   261,   155,   258,    -1,   157,   261,   155,
     258,    -1,    66,   260,   494,   259,   258,    -1,   494,   495,
      -1,   495,    -1,   503,    -1,   504,    -1,   506,    -1,   507,
      -1,   508,    -1,   509,    -1,   510,    -1,   511,    -1,   512,
      -1,   513,    -1,   502,    -1,   515,    -1,   516,    -1,   517,
      -1,   518,    -1,   534,    -1,   520,    -1,   522,    -1,   524,
      -1,   523,    -1,   527,    -1,   521,    -1,   528,    -1,   529,
      -1,   530,    -1,   531,    -1,   533,    -1,   532,    -1,   548,
      -1,   535,    -1,   539,    -1,   540,    -1,   544,    -1,   525,
      -1,   526,    -1,   554,    -1,   552,    -1,   553,    -1,   536,
      -1,   505,    -1,   537,    -1,   538,    -1,   555,    -1,   543,
      -1,   514,    -1,   556,    -1,   541,    -1,   542,    -1,   498,
      -1,   501,    -1,   496,    -1,   497,    -1,   499,    -1,   500,
      -1,   519,    -1,     1,    -1,    72,   261,   133,   258,    -1,
      73,   261,   133,   258,    -1,    12,   261,   196,   258,    -1,
     252,   261,   196,   258,    -1,   162,   261,   267,   258,    -1,
     183,   261,   196,   258,    -1,    93,   261,   133,   258,    -1,
      84,   261,   196,   258,    -1,    89,   261,   196,   258,    -1,
      43,   261,   196,   258,    -1,    53,   261,   196,   258,    -1,
       8,   261,   196,   258,    -1,   114,   261,   267,   258,    -1,
     113,   261,   133,   258,    -1,   107,   261,   133,   258,    -1,
       9,   261,   267,   258,    -1,   200,   261,   267,   258,    -1,
     199,   261,   267,   258,    -1,    77,   261,   133,   258,    -1,
      97,   261,   196,   258,    -1,    96,   261,   155,   258,    -1,
      90,   261,   196,   258,    -1,   257,   261,   196,   258,    -1,
     191,   261,   196,   258,    -1,   194,   261,   196,   258,    -1,
     195,   261,   196,   258,    -1,   193,   261,   196,   258,    -1,
     193,   261,   197,   258,    -1,   192,   261,   196,   258,    -1,
     192,   261,   197,   258,    -1,   147,   261,   267,   258,    -1,
      19,   261,   267,   258,    -1,   139,   261,   196,   258,    -1,
     148,   261,   267,   258,    -1,   187,   261,   196,   258,    -1,
     130,   261,   196,   258,    -1,   241,   261,   196,   258,    -1,
     142,   261,   196,   258,    -1,   117,   261,   155,   258,    -1,
      88,   261,   267,   258,    -1,    45,   261,   133,   258,    -1,
     116,   261,   133,   258,    -1,   181,   261,   155,   258,    -1,
      32,   261,   155,   258,    -1,    28,   261,   133,   258,    -1,
     247,   261,   196,   258,    -1,    47,   261,   155,   258,    -1,
     151,   261,   196,   258,    -1,    39,   261,   196,   258,    -1,
     239,   261,   267,   258,    -1,    -1,   144,   545,   261,   546,
     258,    -1,   546,   262,   547,    -1,   547,    -1,   203,    -1,
     206,    -1,   207,    -1,   209,    -1,   210,    -1,   213,    -1,
     231,    -1,   227,    -1,   229,    -1,   235,    -1,   232,    -1,
     212,    -1,   228,    -1,   230,    -1,   214,    -1,   238,    -1,
     204,    -1,   205,    -1,   217,    -1,    -1,   141,   549,   261,
     550,   258,    -1,   550,   262,   551,    -1,   551,    -1,   203,
      -1,   206,    -1,   207,    -1,   209,    -1,   210,    -1,   213,
      -1,   231,    -1,   227,    -1,   229,    -1,   235,    -1,   232,
      -1,   212,    -1,   228,    -1,   230,    -1,   214,    -1,   238,
      -1,   204,    -1,   205,    -1,   217,    -1,   118,   261,   133,
     258,    -1,   119,   261,   133,   258,    -1,    33,   261,   133,
     258,    -1,   208,   261,   269,   258,    -1,    44,   261,   196,
     258,    -1,    -1,    68,   558,   260,   559,   259,   258,    -1,
     559,   560,    -1,   560,    -1,   561,    -1,   562,    -1,   563,
      -1,   567,    -1,   568,    -1,   569,    -1,     1,    -1,    49,
     261,   196,   258,    -1,    46,   261,   267,   258,    -1,    -1,
     105,   564,   261,   565,   258,    -1,   565,   262,   566,    -1,
     566,    -1,   198,    -1,    11,    -1,   246,   261,   155,   258,
      -1,   122,   261,   155,   258,    -1,    -1,     4,   570,   261,
     571,   258,    -1,   571,   262,   572,    -1,   572,    -1,   198,
      -1,    11,    -1,    22,   260,   574,   259,   258,    -1,   574,
     575,    -1,   575,    -1,   578,    -1,   579,    -1,   580,    -1,
     581,    -1,   586,    -1,   582,    -1,   583,    -1,   584,    -1,
     585,    -1,   587,    -1,   588,    -1,   589,    -1,   577,    -1,
     590,    -1,   591,    -1,   592,    -1,   593,    -1,   576,    -1,
       1,    -1,    40,   261,   196,   258,    -1,   165,   261,   196,
     258,    -1,    42,   261,   196,   258,    -1,   248,   261,   196,
     258,    -1,   249,   261,   196,   258,    -1,   250,   261,   196,
     258,    -1,    98,   261,   267,   258,    -1,    99,   261,   267,
     258,    -1,   109,   261,   133,   258,    -1,   156,   261,   196,
     258,    -1,   108,   261,   133,   258,    -1,    35,   261,   133,
     258,    -1,    34,   261,   133,   258,    -1,   128,   261,   196,
     258,    -1,   129,   261,   196,   258,    -1,    13,   261,   196,
     258,    -1,   145,   261,   133,   258,    -1,   146,   261,   267,
     258,    -1,   179,   260,   595,   259,   258,    -1,   595,   596,
      -1,   596,    -1,   597,    -1,   598,    -1,   600,    -1,   602,
      -1,   601,    -1,   599,    -1,   603,    -1,     1,    -1,    56,
     261,   196,   258,    -1,    83,   261,   196,   258,    -1,    80,
     261,   155,   258,    -1,   102,   261,   267,   258,    -1,    78,
     261,   196,   258,    -1,    41,   261,   196,   258,    -1,    82,
     261,   196,   258,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   395,   395,   396,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   424,   424,   425,   429,
     433,   437,   441,   445,   451,   451,   452,   453,   454,   455,
     462,   465,   465,   466,   466,   466,   468,   485,   496,   499,
     500,   501,   501,   502,   502,   503,   503,   504,   505,   505,
     506,   506,   507,   509,   543,   603,   617,   632,   641,   655,
     664,   692,   722,   745,   795,   797,   797,   798,   798,   799,
     799,   801,   810,   819,   832,   834,   835,   837,   837,   838,
     839,   839,   840,   840,   841,   841,   842,   842,   843,   844,
     846,   850,   854,   861,   868,   875,   882,   889,   896,   903,
     910,   914,   918,   922,   926,   930,   934,   940,   950,   949,
    1043,  1043,  1044,  1044,  1045,  1045,  1045,  1045,  1046,  1046,
    1047,  1047,  1047,  1048,  1048,  1048,  1049,  1049,  1049,  1050,
    1050,  1050,  1050,  1051,  1051,  1052,  1052,  1054,  1066,  1078,
    1112,  1124,  1135,  1177,  1187,  1186,  1192,  1192,  1193,  1197,
    1201,  1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,
    1241,  1245,  1249,  1253,  1257,  1261,  1265,  1271,  1282,  1293,
    1304,  1315,  1326,  1337,  1348,  1359,  1370,  1381,  1392,  1403,
    1414,  1426,  1425,  1429,  1429,  1430,  1430,  1431,  1431,  1433,
    1440,  1447,  1454,  1461,  1468,  1475,  1482,  1489,  1496,  1503,
    1510,  1517,  1524,  1531,  1538,  1552,  1551,  1601,  1601,  1603,
    1603,  1604,  1605,  1605,  1606,  1607,  1608,  1609,  1610,  1611,
    1612,  1613,  1614,  1615,  1616,  1618,  1627,  1636,  1642,  1648,
    1654,  1660,  1666,  1672,  1678,  1684,  1690,  1696,  1702,  1712,
    1711,  1728,  1727,  1732,  1732,  1733,  1737,  1743,  1743,  1744,
    1744,  1744,  1744,  1744,  1746,  1746,  1748,  1748,  1750,  1764,
    1784,  1793,  1806,  1805,  1874,  1874,  1875,  1875,  1875,  1875,
    1876,  1876,  1877,  1877,  1877,  1878,  1878,  1879,  1879,  1879,
    1880,  1880,  1880,  1882,  1919,  1932,  1943,  1952,  1964,  1963,
    1967,  1967,  1968,  1968,  1969,  1969,  1971,  1979,  1986,  1993,
    2000,  2007,  2014,  2021,  2028,  2035,  2044,  2055,  2066,  2077,
    2088,  2099,  2111,  2130,  2140,  2149,  2165,  2164,  2180,  2180,
    2181,  2181,  2181,  2181,  2183,  2192,  2207,  2221,  2220,  2236,
    2236,  2237,  2237,  2237,  2237,  2239,  2248,  2271,  2270,  2276,
    2276,  2277,  2281,  2285,  2289,  2293,  2297,  2301,  2305,  2309,
    2313,  2317,  2327,  2326,  2343,  2343,  2344,  2344,  2344,  2346,
    2353,  2352,  2358,  2358,  2359,  2363,  2367,  2371,  2375,  2379,
    2383,  2387,  2391,  2395,  2399,  2409,  2408,  2554,  2554,  2555,
    2555,  2556,  2556,  2556,  2557,  2557,  2558,  2558,  2559,  2559,
    2559,  2560,  2560,  2560,  2561,  2561,  2561,  2562,  2562,  2563,
    2563,  2565,  2577,  2589,  2598,  2624,  2642,  2660,  2666,  2670,
    2678,  2688,  2687,  2691,  2691,  2692,  2692,  2693,  2693,  2695,
    2702,  2713,  2720,  2727,  2734,  2744,  2785,  2796,  2807,  2822,
    2833,  2844,  2857,  2870,  2879,  2915,  2914,  2979,  2978,  2982,
    2982,  2983,  2989,  2989,  2990,  2990,  2990,  2990,  2992,  3011,
    3021,  3020,  3042,  3042,  3043,  3043,  3043,  3045,  3054,  3066,
    3068,  3068,  3069,  3069,  3071,  3093,  3092,  3135,  3134,  3138,
    3138,  3139,  3145,  3145,  3146,  3146,  3146,  3146,  3148,  3154,
    3163,  3166,  3166,  3167,  3167,  3168,  3168,  3169,  3169,  3170,
    3170,  3171,  3171,  3172,  3172,  3173,  3173,  3174,  3174,  3175,
    3175,  3176,  3176,  3177,  3177,  3178,  3178,  3179,  3179,  3180,
    3180,  3181,  3181,  3182,  3182,  3183,  3183,  3184,  3184,  3185,
    3185,  3186,  3186,  3187,  3188,  3188,  3189,  3189,  3190,  3190,
    3191,  3191,  3192,  3192,  3193,  3193,  3194,  3194,  3195,  3199,
    3204,  3209,  3214,  3219,  3224,  3229,  3234,  3239,  3244,  3249,
    3254,  3259,  3264,  3269,  3274,  3279,  3284,  3290,  3301,  3306,
    3315,  3320,  3325,  3330,  3335,  3340,  3343,  3348,  3351,  3356,
    3361,  3366,  3371,  3376,  3381,  3386,  3391,  3396,  3407,  3412,
    3417,  3422,  3431,  3463,  3481,  3486,  3495,  3500,  3505,  3511,
    3510,  3515,  3515,  3516,  3519,  3522,  3525,  3528,  3531,  3534,
    3537,  3540,  3543,  3546,  3549,  3552,  3555,  3558,  3561,  3564,
    3567,  3570,  3576,  3575,  3580,  3580,  3581,  3584,  3587,  3590,
    3593,  3596,  3599,  3602,  3605,  3608,  3611,  3614,  3617,  3620,
    3623,  3626,  3629,  3632,  3635,  3640,  3645,  3650,  3655,  3660,
    3669,  3668,  3692,  3692,  3693,  3694,  3695,  3696,  3697,  3698,
    3699,  3701,  3707,  3714,  3713,  3718,  3718,  3719,  3723,  3729,
    3763,  3773,  3772,  3822,  3822,  3823,  3827,  3836,  3839,  3839,
    3840,  3840,  3841,  3841,  3842,  3842,  3843,  3843,  3844,  3844,
    3845,  3846,  3846,  3847,  3847,  3848,  3848,  3849,  3849,  3851,
    3856,  3861,  3866,  3871,  3876,  3881,  3886,  3891,  3896,  3901,
    3906,  3911,  3916,  3921,  3926,  3931,  3936,  3944,  3947,  3947,
    3948,  3948,  3949,  3950,  3951,  3951,  3952,  3953,  3955,  3961,
    3967,  3976,  3990,  3996,  4002
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
  "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CAN_IDLE",
  "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIPHER_PREFERENCE",
  "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ",
  "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DOT_IN_IP6_ADDR", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL",
  "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FAKENAME", "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IDLETIME",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LAZYLINK",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NOT", "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID",
  "T_CALLERID", "T_CCONN", "T_CCONN_FULL", "T_CLIENT_FLOOD", "T_DEAF",
  "T_DEBUG", "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR",
  "T_L_INFO", "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "@1",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "@2",
  "oper_umodes_items", "oper_umodes_item", "oper_global_kill",
  "oper_remote", "oper_remoteban", "oper_kline", "oper_xline",
  "oper_unkline", "oper_gline", "oper_nick_changes", "oper_die",
  "oper_rehash", "oper_admin", "oper_hidden_admin", "oper_hidden_oper",
  "oper_operwall", "oper_flags", "@3", "oper_flags_items",
  "oper_flags_item", "@4", "@5", "oper_flags_item_atom", "class_entry",
  "@6", "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "@7", "listen_flags", "@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@11", "auth_flags_items",
  "auth_flags_item", "@12", "@13", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "@14", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "@15", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "@16", "shared_types",
  "shared_type_item", "cluster_entry", "@17", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "@18", "cluster_types",
  "cluster_type_item", "connect_entry", "@19", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "@20", "connect_flags_items",
  "connect_flags_item", "@21", "@22", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_topicburst",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "@23", "kill_type", "@24",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "@25", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "@26", "gecos_flags", "@27",
  "gecos_flags_items", "gecos_flags_item", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_burst_away", "general_use_whois_actually",
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
  "general_message_locale", "general_idletime", "general_dots_in_ident",
  "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@28", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@29",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@30",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@31", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@32", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_disable_local_channels", "channel_use_except",
  "channel_use_invex", "channel_use_knock", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_quiet_on_ban", "channel_max_bans",
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
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,    59,   125,
     123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   263,   264,   264,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   266,   266,   267,   267,
     267,   267,   267,   267,   268,   268,   269,   269,   269,   269,
     270,   271,   271,   272,   272,   272,   273,   274,   275,   276,
     276,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   290,   291,   291,   291,
     291,   292,   293,   294,   295,   296,   296,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   308,   308,   308,   308,   308,   308,   309,   311,   310,
     312,   312,   313,   313,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   316,   317,
     318,   319,   320,   321,   323,   322,   324,   324,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   341,   340,   342,   342,   344,   343,   345,   343,   346,
     346,   346,   346,   346,   346,   346,   346,   346,   346,   346,
     346,   346,   346,   346,   346,   348,   347,   349,   349,   350,
     350,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   367,
     366,   369,   368,   370,   370,   371,   371,   372,   372,   373,
     373,   373,   373,   373,   375,   374,   376,   376,   377,   377,
     378,   379,   381,   380,   382,   382,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   384,   385,   386,   387,   388,   390,   389,
     391,   391,   393,   392,   394,   392,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   407,   406,   408,   408,
     409,   409,   409,   409,   410,   411,   412,   414,   413,   415,
     415,   416,   416,   416,   416,   417,   418,   420,   419,   421,
     421,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   424,   423,   425,   425,   426,   426,   426,   427,
     429,   428,   430,   430,   431,   431,   431,   431,   431,   431,
     431,   431,   431,   431,   431,   433,   432,   434,   434,   435,
     435,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   444,
     445,   447,   446,   448,   448,   450,   449,   451,   449,   452,
     452,   452,   452,   452,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   464,   463,   466,   465,   467,
     467,   468,   469,   469,   470,   470,   470,   470,   471,   472,
     474,   473,   475,   475,   476,   476,   476,   477,   478,   479,
     480,   480,   481,   481,   482,   484,   483,   486,   485,   487,
     487,   488,   489,   489,   490,   490,   490,   490,   491,   492,
     493,   494,   494,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   522,   523,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   545,
     544,   546,   546,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     547,   547,   549,   548,   550,   550,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   552,   553,   554,   555,   556,
     558,   557,   559,   559,   560,   560,   560,   560,   560,   560,
     560,   561,   562,   564,   563,   565,   565,   566,   566,   567,
     568,   570,   569,   571,   571,   572,   572,   573,   574,   574,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   575,
     575,   575,   575,   575,   575,   575,   575,   575,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   595,
     596,   596,   596,   596,   596,   596,   596,   596,   597,   598,
     599,   600,   601,   602,   603
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
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     7,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       6,     0,     5,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     0,     5,     3,     1,     1,     1,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   215,   385,   460,     0,
     475,     0,   650,   272,   445,   249,     0,     0,   118,   326,
       0,     0,   337,   362,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   217,
     387,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   698,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   679,   697,   692,   680,
     681,   682,   683,   685,   686,   687,   688,   684,   689,   690,
     691,   693,   694,   695,   696,   236,     0,   218,   412,     0,
     388,     0,   473,     0,     0,   471,   472,     0,   548,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   622,     0,   599,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   492,   543,   544,   541,   545,
     546,   542,   503,   493,   494,   532,   495,   496,   497,   498,
     499,   500,   501,   502,   537,   504,   505,   506,   507,   547,
     509,   514,   510,   512,   511,   526,   527,   513,   515,   516,
     517,   518,   520,   519,   508,   522,   531,   533,   534,   523,
     524,   539,   540,   536,   525,   521,   529,   530,   528,   535,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    91,    98,    92,    96,    93,    94,    97,    95,
      89,    90,     0,     0,     0,     0,    42,    43,    44,   148,
       0,   121,     0,   727,     0,     0,     0,     0,     0,     0,
       0,     0,   719,   720,   721,   725,   722,   724,   723,   726,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    61,    58,    51,    60,    54,    55,
      56,    52,    59,    57,    53,     0,     0,    80,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   678,     0,     0,   466,     0,     0,     0,   463,
     464,   465,     0,     0,   470,   487,     0,     0,   477,   486,
       0,   483,   484,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     491,   660,   671,     0,     0,   663,     0,     0,     0,   653,
     654,   655,   656,   657,   658,   659,     0,     0,     0,     0,
       0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,   276,   277,   286,   278,   291,
     279,   280,   281,   282,   289,   283,   284,   285,   287,   288,
     290,   457,     0,   447,     0,   456,     0,   453,   454,   455,
       0,   251,     0,     0,     0,   260,     0,   258,   259,   261,
     262,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    45,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,   329,   330,   331,
     332,     0,     0,     0,     0,     0,     0,     0,     0,   718,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   347,     0,     0,   340,
     341,   342,   343,     0,     0,   370,     0,   365,   366,   367,
       0,     0,     0,    74,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   677,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     221,   224,   225,   227,   228,   229,   230,   231,   232,   233,
     222,   223,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   421,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   390,   391,   392,   393,   394,   395,
     397,   396,   398,   399,   407,   404,   406,   405,   403,   409,
     400,   401,   402,   408,     0,     0,     0,   462,     0,   469,
       0,     0,     0,     0,   482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,   490,     0,     0,     0,     0,     0,     0,
       0,   652,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,     0,     0,   452,   263,     0,     0,     0,
       0,     0,   257,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,    40,     0,     0,     0,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,   123,
     124,   125,   126,   143,   144,   130,   129,   131,   132,   138,
     133,   134,   135,   136,   137,   139,   140,   141,   127,   128,
     142,   145,   333,     0,     0,     0,     0,   328,     0,     0,
       0,     0,     0,     0,     0,   717,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,   344,     0,
       0,     0,     0,   339,   368,     0,     0,     0,   364,    83,
      82,    81,   714,   711,   710,   699,   701,    26,    26,    26,
      26,    26,    28,    27,   705,   706,   709,   707,   712,   713,
     715,   716,   708,   700,   702,   703,   704,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   410,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,     0,     0,   461,   474,     0,
       0,     0,   476,   560,   564,   551,   580,   593,   592,   647,
     597,   558,   649,   589,   595,   559,   549,   550,   567,   556,
     588,   557,   570,   555,   569,   568,   563,   562,   561,   590,
     587,   645,   646,   584,   581,   626,   642,   643,   627,   628,
     629,   630,   637,   631,   640,   644,   633,   638,   634,   639,
     632,   636,   635,   641,     0,   625,   586,   603,   619,   620,
     604,   605,   606,   607,   614,   608,   617,   621,   610,   615,
     611,   616,   609,   613,   612,   618,     0,   602,   579,   582,
     596,   553,   591,   554,   583,   572,   577,   578,   575,   576,
     573,   574,   566,   565,    34,    34,    34,    36,    35,   648,
     598,   585,   594,   552,   571,     0,     0,     0,     0,     0,
       0,   651,     0,     0,     0,     0,   304,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,     0,   446,     0,     0,     0,   268,   264,   267,   250,
     103,   109,   107,   106,   108,   104,   105,   102,   110,   116,
     111,   115,   113,   114,   112,   101,   100,   117,    46,    47,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   327,   733,
     728,   732,   730,   734,   729,   731,    67,    73,    65,    69,
      68,    64,    63,    66,    72,    70,    71,     0,     0,     0,
     338,     0,     0,   363,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   216,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   386,   467,   468,   488,   489,   481,     0,
     480,   623,     0,   600,     0,    37,    38,    39,   676,   675,
       0,   674,   662,   661,   668,   667,     0,   666,   670,   669,
     319,   296,   297,   318,   302,     0,   301,     0,   321,   317,
     316,   325,   320,   294,   324,   323,   322,   295,   293,   459,
     451,     0,   450,   458,   256,   255,     0,   254,   271,   270,
       0,     0,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   335,   336,   334,   345,
     351,   357,   361,   360,   359,   356,   352,   355,   358,   353,
     354,     0,   350,   346,   369,   374,   380,   384,   383,   382,
     379,   375,   378,   381,   376,   377,     0,   373,   246,   247,
     240,   242,   244,   243,   241,   235,   248,   239,   237,   238,
     245,   416,   418,   419,   439,   444,   443,   438,   437,   436,
     420,   425,     0,   424,     0,   413,   441,   442,   411,   417,
     435,   415,   440,   414,   478,     0,   624,   601,   672,     0,
     664,     0,     0,   299,   304,   310,   311,   307,   313,   309,
     308,   315,   312,   314,   306,   305,   448,     0,   252,     0,
     269,   266,   265,   187,   153,   185,   151,   195,     0,   194,
       0,   183,   177,   188,   189,   180,   147,   184,   150,   186,
     178,   179,   152,   190,   158,   174,   175,   159,   160,   161,
     162,   169,   163,   172,   176,   165,   170,   166,   171,   164,
     168,   167,   173,     0,   157,   182,   149,   181,   348,     0,
     371,     0,     0,   422,   427,   432,   433,   430,   431,   429,
     434,   428,   479,   673,   665,   303,   300,   449,   253,     0,
     192,   197,   207,   205,   214,   204,   199,   208,   212,   201,
     209,   211,   206,   200,   213,   210,   202,   203,   198,   155,
       0,   349,   372,   426,   423,   196,   193,   156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   892,   893,  1047,  1048,    25,   275,   276,
     277,   278,    26,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,    27,    71,    72,    73,
      74,    75,    28,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    29,    61,   280,
     818,   819,   820,   281,   821,   822,   823,   824,   825,   826,
    1129,  1423,  1424,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,  1115,  1388,
    1389,  1449,  1390,  1468,    30,    49,   116,   608,   609,   610,
     117,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,    31,    58,   495,   767,  1256,  1257,   496,
     497,   498,  1262,  1087,  1088,   499,   500,    32,    56,   463,
     464,   465,   466,   467,   468,   469,   470,   747,  1235,  1236,
    1362,  1237,  1375,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,    33,    62,   526,   527,   528,   529,   530,
      34,    65,   558,   559,   560,   561,   562,   870,  1301,  1302,
      35,    66,   566,   567,   568,   569,   876,  1316,  1317,    36,
      50,   119,   643,   644,   645,   120,   646,   647,   648,   649,
     650,   651,   652,   653,   933,  1342,  1343,  1432,  1344,  1441,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
      37,    57,   485,   762,  1251,  1252,   486,   487,   488,   489,
      38,    51,   358,   359,   360,   361,    39,   124,   125,   126,
      40,    53,   369,   672,  1209,  1210,   370,   371,   372,   373,
      41,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   408,  1026,  1027,   235,   406,  1004,  1005,   236,
     237,   238,   239,   240,    42,    55,   438,   439,   440,   441,
     442,   737,  1226,  1227,   443,   444,   445,   734,  1220,  1221,
      43,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,   291,   292,   293,   294,   295,   296,   297,   298,
     299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -917
static const yytype_int16 yypact[] =
{
    -917,   848,  -917,  -249,  -234,  -231,  -917,  -917,  -917,  -228,
    -917,  -217,  -917,  -917,  -917,  -917,  -202,  -197,  -917,  -917,
    -190,  -178,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,    53,   798,   -53,
     -50,  -153,    32,  -152,   514,  -147,  -146,  -119,  -117,   729,
      63,    -9,  -111,   334,   363,   -99,   -89,   -84,   -79,   -47,
     -42,     4,  -917,  -917,  -917,  -917,  -917,   -40,   -39,   -34,
     -33,   -31,   -26,   -24,   -23,   -18,   -15,    -5,    -3,     6,
       9,    25,    27,    36,    38,   205,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,   -83,  -917,  -917,    20,
    -917,    66,  -917,    39,     7,  -917,  -917,     2,  -917,    41,
      46,    48,    58,    69,    79,    83,    88,    94,    96,    97,
      98,   101,   102,   104,   105,   107,   113,   121,   122,   125,
     127,   128,   130,   131,   132,   133,   135,   138,   141,   143,
     145,  -917,   146,  -917,   147,   149,   150,   152,   154,   157,
     159,   171,   176,   178,   179,   180,   181,   183,   185,   186,
     187,   189,   190,   191,     3,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,   338,   836,    23,    77,    21,   195,   196,   202,   212,
     213,   222,   223,   225,   228,   229,   231,   232,   408,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,    73,   233,   234,     5,  -917,  -917,  -917,  -917,
      57,  -917,    84,  -917,   235,   236,   237,   240,   241,   242,
     244,    56,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
      87,   245,   246,   247,   250,   252,   255,   256,   258,   259,
     260,   264,    67,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,    65,    18,  -917,   129,   357,
     372,   270,  -917,   333,   401,   402,   340,   343,   407,   407,
     421,   422,   345,   360,   427,   407,   367,   368,   369,   370,
     373,   310,  -917,   887,   725,  -917,   309,   312,    12,  -917,
    -917,  -917,   416,   316,  -917,  -917,   314,   315,  -917,  -917,
      15,  -917,  -917,  -917,   381,   407,   382,   407,   446,   428,
     452,   392,   394,   396,   460,   439,   399,   463,   466,   467,
     409,   407,   410,   412,   476,   457,   418,   482,   485,   407,
     486,   465,   490,   491,   429,   433,   374,   440,   376,   407,
     407,   442,   407,   484,   444,   445,   447,  -176,  -108,   451,
     453,   407,   407,   509,   407,   454,   456,   458,   461,   390,
    -917,  -917,  -917,   403,   405,  -917,   411,   413,    13,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,   415,   417,   420,   423,
     430,  -917,   431,   438,   441,   449,   450,   455,   459,   464,
     471,   472,   473,   272,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,   475,  -917,   477,  -917,    22,  -917,  -917,  -917,
     424,  -917,   478,   479,   483,  -917,    24,  -917,  -917,  -917,
    -917,  -917,   513,   516,   528,   534,   545,   548,   549,   557,
     203,   560,   562,   523,   469,  -917,  -917,   566,   582,   488,
    -917,   596,   489,   487,   493,   501,    59,  -917,  -917,  -917,
    -917,   547,   567,   571,   614,   577,   578,   407,   518,  -917,
    -917,   622,   585,   623,   627,   628,   629,   639,   640,   536,
     642,   643,   542,  -917,   543,   541,  -917,   544,   110,  -917,
    -917,  -917,  -917,   550,   546,  -917,    26,  -917,  -917,  -917,
     551,   555,   556,  -917,   558,   559,   561,   563,   564,   204,
     565,   569,   570,   573,   581,   587,   588,   592,   599,   600,
     601,   602,   603,  -917,   606,   554,   568,   575,   604,   605,
     607,   610,   611,   612,   615,   617,   619,   620,   323,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,   609,   621,   624,   631,   633,   634,   637,
     638,   641,   647,  -917,   648,   654,   657,   659,   660,   661,
     663,   664,   667,   251,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,   651,   665,   625,  -917,   632,  -917,
     670,   688,   668,   646,  -917,   672,   674,   675,   676,   677,
     679,   680,   681,   683,   684,   687,   690,   692,   694,   697,
     698,   699,   700,   702,   703,   704,   706,   708,   710,   712,
     713,   714,   715,   716,   717,   718,   719,   846,   721,   882,
     723,   724,   726,   730,   731,   732,   733,   734,   735,   738,
     742,   743,   745,   746,   747,   748,   210,   749,   750,   752,
     753,   754,   755,  -917,   722,   407,   693,   756,   720,   794,
     757,  -917,  -917,   705,   832,   818,   820,   758,   824,   825,
     828,   833,   834,   876,   901,   880,   881,   841,   883,   783,
    -917,   888,   781,   889,   787,  -917,  -917,   793,   902,   906,
     929,   807,  -917,   808,   809,   810,   811,   812,   813,   814,
     821,   822,   835,   839,   840,   842,   843,   844,   845,   847,
     849,  -917,   850,   857,  -917,   858,   829,   865,   868,   872,
    -917,   873,   875,   877,   878,   879,   890,   891,   893,   894,
     896,   897,   898,   899,  -917,   900,   903,   904,   126,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,   928,   949,   951,   860,  -917,   861,   884,
     885,   886,   905,   908,   909,  -917,   910,   911,   912,   913,
     914,   915,   916,   917,   919,   920,   921,  -917,  -917,   982,
     922,   986,   923,  -917,  -917,  1007,   924,   926,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,   407,   407,   407,
     407,   407,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  1043,  1047,
     407,  1049,  1053,  1054,  1055,  1034,  1057,  1058,   407,   407,
     509,   934,  -917,  -917,  1038,  -121,   998,  1040,  1041,  1001,
    1002,  1003,  1045,   940,  1048,  1050,  1051,  1052,  1069,  1056,
    1059,  1008,  1060,   950,  -917,   952,   954,  -917,  -917,   955,
     958,  1061,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -224,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -218,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,   509,   509,   509,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,    17,   959,   960,    19,   961,
     962,  -917,   964,   965,   966,   967,   671,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,  -917,   979,
    1078,   981,  -917,   -60,   983,   984,    64,   947,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  1044,  1088,  1062,  1063,   985,  1064,  1065,  1066,  1067,
    1068,  1089,  1070,  1090,  1071,  1072,  1073,  1092,  1074,   987,
    1075,  1094,  1076,   992,  -917,   993,   994,   995,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,   996,   307,   997,
    -917,   999,   443,  -917,  -917,  -917,  -917,  -917,  -917,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  -917,  1028,  1029,  1030,  1031,  1032,  1033,  1035,
    1036,  1037,  1039,  1124,  1042,  1046,  1077,  1079,  1080,  1081,
    1082,  1083,  1084,  -917,  -917,  -917,  -917,  -917,  -917,  -213,
    -917,  -917,   846,  -917,   882,  -917,  -917,  -917,  -917,  -917,
    -207,  -917,  -917,  -917,  -917,  -917,  -193,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -185,  -917,   673,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -102,  -917,  -917,  -917,  -917,   -95,  -917,  -917,  -917,
    1132,   929,  1085,  1086,  1087,  1091,  1093,  1160,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,   918,  1108,  1109,  1110,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,   -92,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,   -29,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,    33,  -917,   298,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  1061,  -917,  -917,  -917,    17,
    -917,    19,   673,  -917,   671,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  1078,  -917,   -60,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,    54,  -917,
     691,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,    70,  -917,  -917,  -917,  -917,  -917,   307,
    -917,   443,   298,  -917,  1124,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,   691,
    -917,  1160,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
     918,  -917,  -917,  -917,  -917,  -917,  -917,  -917
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -917,  -917,  -917,  -409,  -338,  -916,  -421,  -917,  -917,  1111,
    -917,  -917,  -917,  -917,   989,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  1225,  -917,
    -917,  -917,  -917,  -917,  1112,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,   480,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -171,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -149,  -917,  -917,  -144,  -917,  -917,  -917,  -917,   695,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,   -73,  -917,
     815,  -917,  -917,  -917,    47,  -917,  -917,  -917,  -917,  -917,
     851,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,   -57,
    -917,  -917,   -52,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,   786,  -917,  -917,  -917,
    -917,  -917,  -917,   751,  -917,  -917,  -917,  -917,  -917,  -116,
    -917,  -917,  -917,   759,  -917,  -917,  -917,  -917,  -115,  -917,
    -917,  -917,  -917,   678,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -114,  -917,  -917,  -113,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,   -62,  -917,   831,  -917,  -917,
    -917,  -917,  -917,   988,  -917,  -917,  -917,  -917,  1194,  -917,
    -917,  -917,  -917,  -917,  -917,   -32,  -917,   956,  -917,  -917,
    -917,  -917,  1138,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,   114,  -917,  -917,  -917,   112,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,   892,  -917,  -917,
    -917,  -917,  -917,   -30,  -917,  -917,  -917,  -917,  -917,   -27,
    -917,  -917,  1232,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,  -917,
    -917,  -917,  -917,  1113,  -917,  -917,  -917,  -917,  -917,  -917,
    -917
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     580,   581,   727,   365,   128,    67,   272,   587,   122,    45,
      46,   129,   130,   355,   431,   131,   365,   432,  1254,   563,
     718,   719,   132,   481,   481,   490,    47,   563,  1218,    48,
    1224,   133,    52,   122,  1211,   134,   135,   676,  1212,   678,
    1213,    68,   136,    54,  1214,  1354,   137,   138,   139,  1355,
     140,  1358,    69,   692,    67,  1359,   141,   283,    59,   433,
     522,   700,   434,    60,   272,  1360,   554,   355,   300,  1361,
      63,   710,   711,  1363,   713,   142,   143,  1364,   490,   491,
     144,   523,    64,   724,   725,   522,   728,   145,   720,   721,
      68,   146,   147,   148,  1184,  1185,   149,   284,   123,   150,
     151,    69,   115,   356,   301,   118,   523,   121,   127,   492,
     152,   554,   285,   241,   242,   493,   153,   154,   435,   155,
     156,   157,   158,   123,   366,   273,    70,   795,  1215,  1216,
    1217,   796,   491,   159,   286,   436,   287,   366,   288,   289,
     564,   243,   160,   244,   161,   162,   279,   163,   564,   282,
     164,   165,   797,   302,   166,   274,  1376,   356,   290,   367,
    1377,   325,   492,  1378,   798,   167,  1428,  1379,   493,   357,
    1429,   326,   367,  1255,   327,    70,   799,   353,   494,   482,
     482,   800,   328,   273,   168,   524,   169,   555,   368,   303,
     170,   304,   305,   801,   171,   172,   173,   174,   175,   854,
     802,   368,   176,   177,   565,   803,    76,   804,   483,   483,
     524,   178,   565,   274,   329,  1219,   525,  1225,    77,   330,
     805,   333,   334,   357,  1044,  1045,  1046,   335,   336,  1430,
     337,   494,   555,  1431,   306,   338,   307,   339,   340,    78,
      79,   525,   179,   341,   180,    80,   342,    81,   806,   308,
     181,   556,   623,   807,   624,   182,   343,   625,   344,   437,
     183,   626,   429,   331,   519,  1260,   363,   345,   484,   484,
     346,   666,   740,   446,   673,   808,   627,   628,   629,   501,
     354,   764,   630,   771,   570,   877,   347,   809,   348,   810,
     811,  1433,   447,   309,   812,  1434,   556,   349,   448,   350,
     362,   631,   374,    82,    83,   632,   633,   375,  1435,   376,
    1436,   557,  1450,    84,    85,   538,  1451,   521,   846,   377,
     310,   311,   449,   450,   594,  1437,   552,   451,  1469,  1438,
     378,   516,  1470,    86,    87,   283,   634,   579,   635,   431,
     379,   452,   432,   726,   380,   540,   595,   596,   453,   381,
      88,    89,   636,   597,   813,   382,   557,   383,   384,   385,
     814,    90,   386,   387,   300,   388,   389,   454,   390,   872,
      91,   815,   816,   637,   391,   284,   887,   888,   889,   890,
     891,   817,   392,   393,   433,  1133,   394,   434,   395,   396,
     285,   397,   398,   399,   400,   455,   401,  1056,  1439,   402,
     301,  1290,   403,   456,   404,   638,   405,   407,   409,   245,
     410,   411,   286,   412,   287,   413,   288,   289,   414,   639,
     415,   457,   781,   782,   783,   784,   785,   786,   787,   640,
     458,   459,   416,   598,   599,   600,   290,   417,   601,   418,
     419,   420,   421,   435,   422,   602,   423,   424,   425,   302,
     426,   427,   428,    92,    93,    94,   502,   503,   603,   604,
     436,   460,   461,   504,   351,   246,   247,   248,   249,   250,
     251,   252,   253,   505,   506,   605,   606,  1291,  1164,  1165,
    1166,  1167,  1168,   507,   508,   303,   509,   304,   305,   510,
     511,   641,   512,   513,   517,   518,   531,   532,   533,  1181,
     607,   534,   535,   536,   642,   537,   541,   542,   543,  1292,
     943,   544,   571,   545,   254,   128,   546,   547,   462,   548,
     549,   550,   129,   130,  1293,   551,   131,   572,   573,   574,
     306,   759,   307,   132,   575,   576,   577,  1305,  1440,   578,
     579,   584,   133,  1294,  1295,   308,   134,   135,   255,  1296,
    1297,  1298,  1299,   136,   582,   583,   585,   137,   138,   139,
     586,   140,  1300,   588,   589,   590,   591,   141,   593,   592,
     664,   668,  1171,   665,   669,   670,   671,   675,   677,   679,
    1179,  1180,   921,   680,   437,   681,   142,   143,   682,   309,
     683,   144,   684,   685,   686,   687,   688,   795,   145,   689,
     690,   796,   146,   147,   148,   691,   693,   149,   694,   695,
     150,   151,   696,  1306,   697,   698,   310,   311,   699,   701,
     702,   152,   797,   703,   704,   705,   256,   153,   154,   706,
     155,   156,   157,   158,   798,   707,   708,   709,   712,   714,
     715,   716,   726,   717,   159,  1307,   799,   722,   733,   723,
     729,   800,   730,   160,   731,   161,   162,   732,   163,   257,
    1308,   164,   165,   801,   735,   166,   736,   514,   773,   864,
     802,   774,   738,   742,   739,   803,   167,   804,   743,  1309,
    1310,   744,   766,   775,   745,  1311,  1312,  1313,  1314,   776,
     805,   746,   748,  1365,  1366,   168,  1452,   169,  1315,   749,
     777,   170,   750,   778,   779,   171,   172,   173,   174,   175,
     751,   752,   780,   176,   177,   788,   753,   789,   806,   790,
     754,   792,   178,   807,  1367,   755,   623,   791,   624,  1453,
     245,   625,   756,   757,   758,   626,   761,   793,   763,   768,
     769,  1454,  1368,   848,   770,   808,   794,   842,   843,  1369,
     627,   628,   629,   179,   844,   180,   630,   809,  1455,   810,
     811,   181,   845,   849,   812,  1456,   182,   850,  1370,   851,
    1457,   183,  1458,   852,   853,   631,   855,   856,   858,   632,
     633,   857,   859,   860,   861,  1459,   246,   247,   248,   249,
     250,   251,   252,   253,   862,   863,  1371,   865,   866,    76,
     867,   868,   869,  1234,  1372,   871,   945,   875,   874,   879,
     634,    77,   635,   880,   881,   908,   882,   883,  1460,   884,
     946,   885,   886,   894,   813,   949,   636,   895,   896,   909,
     814,   897,    78,    79,  1461,   254,   910,   446,    80,   898,
      81,   815,   816,   950,  1373,   899,   900,   637,     2,     3,
     901,   817,  1462,     4,  1463,  1464,   447,   902,   903,   904,
     905,   906,   448,  1374,   907,   911,   912,   923,   913,   255,
       5,   914,   915,   916,     6,  1059,   917,     7,   918,   638,
     919,   920,   924,   947,     8,   925,   449,   450,   594,  1057,
     948,   451,   926,   639,   927,   928,    82,    83,   929,   930,
       9,  1062,   931,   640,   952,   452,    84,    85,   932,   934,
     595,   596,   453,    10,    11,   935,    12,   597,   936,  1465,
     937,   938,   939,    13,   940,   941,    86,    87,   942,   951,
     953,   454,   954,   955,   956,   957,  1466,   958,   959,   960,
      14,   961,   962,    88,    89,   963,  1467,   256,   964,  1060,
     965,    15,   966,    16,    90,   967,   968,   969,   970,   455,
     971,   972,   973,    91,   974,   641,   975,   456,   976,    17,
     977,   978,   979,   980,   981,   982,   983,   984,   642,  1006,
     257,  1028,  1029,  1055,  1030,   457,    18,  1063,  1031,  1032,
    1033,  1034,  1035,  1036,   458,   459,  1037,   598,   599,   600,
    1038,  1039,   601,  1040,  1041,  1042,  1043,  1049,  1050,   602,
    1051,  1052,  1053,  1054,  1064,  1061,  1065,  1058,    19,  1066,
    1067,  1068,   603,   604,  1069,   460,   461,    20,    21,  1070,
    1071,  1072,    22,    23,  1073,  1074,  1075,  1076,  1077,   605,
     606,  1078,  1080,  1079,  1081,  1082,    92,    93,    94,   985,
     986,   987,   988,   989,  1083,   990,   991,  1084,   992,   993,
     994,  1085,  1086,   995,   607,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,   996,   997,   998,   999,  1000,  1001,  1097,
    1098,  1002,   462,  1135,  1003,  1007,  1008,  1009,  1010,  1011,
    1111,  1012,  1013,  1099,  1014,  1015,  1016,  1100,  1101,  1017,
    1102,  1103,  1104,  1105,  1136,  1106,  1137,  1107,  1108,  1018,
    1019,  1020,  1021,  1022,  1023,  1109,  1110,  1024,  1138,  1139,
    1025,  1404,  1405,  1406,  1407,  1408,  1112,  1409,  1410,  1113,
    1411,  1412,  1413,  1114,  1116,  1414,  1117,  1157,  1118,  1119,
    1120,  1159,  1140,  1141,  1142,  1415,  1416,  1417,  1418,  1419,
    1420,  1121,  1122,  1421,  1123,  1124,  1422,  1125,  1126,  1127,
    1128,  1130,  1161,  1143,  1131,  1132,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1169,  1154,  1155,  1156,
    1170,  1160,  1172,  1158,  1163,  1162,  1173,  1174,  1175,  1176,
    1177,  1178,  1182,  1183,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1198,  1194,  1201,  1195,  1196,  1197,  1203,  1261,
    1204,  1199,  1205,  1206,  1200,  1202,  1207,  1222,  1223,  1228,
    1229,  1208,  1230,  1231,  1232,  1233,  1238,  1239,  1240,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1250,  1253,
    1263,  1258,  1259,  1264,  1273,  1275,  1267,  1279,  1281,  1283,
    1285,  1286,  1287,  1288,  1289,  1303,  1341,  1304,  1265,  1266,
    1268,  1269,  1270,  1271,  1272,  1380,  1274,  1276,  1277,  1278,
    1280,  1282,  1284,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1387,  1337,  1338,  1339,   332,  1340,  1134,  1477,
    1345,   553,  1476,   922,  1346,  1475,  1448,  1446,  1381,   873,
    1445,   772,   847,  1471,   760,  1447,  1472,   765,   364,  1473,
    1474,   944,   430,  1442,  1356,   878,   674,   352,  1357,     0,
     741,  1444,  1443,     0,     0,  1347,     0,  1348,  1349,  1350,
    1351,  1352,  1353,  1382,  1383,  1384,   667,     0,     0,  1385,
       0,  1386,     0,  1391,  1392,  1393,  1394,  1395,  1396,  1397,
    1398,  1399,  1400,  1401,  1402,  1403,  1425,  1426,  1427,     0,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   520,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   539
};

static const yytype_int16 yycheck[] =
{
     338,   339,   423,     1,     1,     1,     1,   345,     1,   258,
     259,     8,     9,     1,     1,    12,     1,     4,    78,     1,
     196,   197,    19,     1,     1,     1,   260,     1,    11,   260,
      11,    28,   260,     1,   258,    32,    33,   375,   262,   377,
     258,    37,    39,   260,   262,   258,    43,    44,    45,   262,
      47,   258,    48,   391,     1,   262,    53,     1,   260,    46,
       1,   399,    49,   260,     1,   258,     1,     1,     1,   262,
     260,   409,   410,   258,   412,    72,    73,   262,     1,    55,
      77,    22,   260,   421,   422,     1,   424,    84,   196,   197,
      37,    88,    89,    90,   215,   216,    93,    41,    91,    96,
      97,    48,   155,    91,    37,   155,    22,   260,   260,    85,
     107,     1,    56,   260,   260,    91,   113,   114,   105,   116,
     117,   118,   119,    91,   122,   120,   122,     1,  1044,  1045,
    1046,     5,    55,   130,    78,   122,    80,   122,    82,    83,
     122,   260,   139,   260,   141,   142,   155,   144,   122,   260,
     147,   148,    26,    86,   151,   150,   258,    91,   102,   157,
     262,   260,    85,   258,    38,   162,   258,   262,    91,   157,
     262,   260,   157,   233,   258,   122,    50,   260,   154,   157,
     157,    55,   261,   120,   181,   126,   183,   122,   186,   122,
     187,   124,   125,    67,   191,   192,   193,   194,   195,   537,
      74,   186,   199,   200,   186,    79,     1,    81,   186,   186,
     126,   208,   186,   150,   261,   198,   157,   198,    13,   261,
      94,   261,   261,   157,    14,    15,    16,   261,   261,   258,
     261,   154,   122,   262,   167,   261,   169,   261,   261,    34,
      35,   157,   239,   261,   241,    40,   261,    42,   122,   182,
     247,   186,     1,   127,     3,   252,   261,     6,   261,   246,
     257,    10,   259,   259,   259,   201,   259,   261,   246,   246,
     261,   259,   259,     1,   259,   149,    25,    26,    27,   258,
     260,   259,    31,   259,   155,   259,   261,   161,   261,   163,
     164,   258,    20,   226,   168,   262,   186,   261,    26,   261,
     261,    50,   261,    98,    99,    54,    55,   261,    10,   261,
      12,   246,   258,   108,   109,   259,   262,   260,   259,   261,
     253,   254,    50,    51,     1,    27,   259,    55,   258,    31,
     261,   258,   262,   128,   129,     1,    85,   133,    87,     1,
     261,    69,     4,   133,   261,   258,    23,    24,    76,   261,
     145,   146,   101,    30,   228,   261,   246,   261,   261,   261,
     234,   156,   261,   261,     1,   261,   261,    95,   261,   259,
     165,   245,   246,   122,   261,    41,   172,   173,   174,   175,
     176,   255,   261,   261,    46,   259,   261,    49,   261,   261,
      56,   261,   261,   261,   261,   123,   261,   735,   100,   261,
      37,    94,   261,   131,   261,   154,   261,   261,   261,     1,
     261,   261,    78,   261,    80,   261,    82,    83,   261,   168,
     261,   149,   219,   220,   221,   222,   223,   224,   225,   178,
     158,   159,   261,   110,   111,   112,   102,   261,   115,   261,
     261,   261,   261,   105,   261,   122,   261,   261,   261,    86,
     261,   261,   261,   248,   249,   250,   261,   261,   135,   136,
     122,   189,   190,   261,   259,    57,    58,    59,    60,    61,
      62,    63,    64,   261,   261,   152,   153,   170,   887,   888,
     889,   890,   891,   261,   261,   122,   261,   124,   125,   261,
     261,   240,   261,   261,   261,   261,   261,   261,   261,   920,
     177,   261,   261,   261,   253,   261,   261,   261,   261,   202,
     259,   261,   155,   261,   106,     1,   261,   261,   246,   261,
     261,   261,     8,     9,   217,   261,    12,   155,   258,   196,
     167,   259,   169,    19,   133,   133,   196,    94,   240,   196,
     133,   196,    28,   236,   237,   182,    32,    33,   140,   242,
     243,   244,   245,    39,   133,   133,   196,    43,    44,    45,
     133,    47,   255,   196,   196,   196,   196,    53,   258,   196,
     261,   155,   910,   261,   258,   261,   261,   196,   196,   133,
     918,   919,   259,   155,   246,   133,    72,    73,   196,   226,
     196,    77,   196,   133,   155,   196,   133,     1,    84,   133,
     133,     5,    88,    89,    90,   196,   196,    93,   196,   133,
      96,    97,   155,   170,   196,   133,   253,   254,   133,   133,
     155,   107,    26,   133,   133,   196,   218,   113,   114,   196,
     116,   117,   118,   119,    38,   261,   196,   261,   196,   155,
     196,   196,   133,   196,   130,   202,    50,   196,   258,   196,
     196,    55,   196,   139,   196,   141,   142,   196,   144,   251,
     217,   147,   148,    67,   261,   151,   261,   259,   155,   133,
      74,   155,   261,   258,   261,    79,   162,    81,   261,   236,
     237,   261,   258,   155,   261,   242,   243,   244,   245,   155,
      94,   261,   261,    20,    21,   181,     5,   183,   255,   261,
     155,   187,   261,   155,   155,   191,   192,   193,   194,   195,
     261,   261,   155,   199,   200,   155,   261,   155,   122,   196,
     261,   155,   208,   127,    51,   261,     1,   258,     3,    38,
       1,     6,   261,   261,   261,    10,   261,   155,   261,   261,
     261,    50,    69,   196,   261,   149,   258,   258,   261,    76,
      25,    26,    27,   239,   261,   241,    31,   161,    67,   163,
     164,   247,   261,   196,   168,    74,   252,   196,    95,   155,
      79,   257,    81,   196,   196,    50,   258,   155,   155,    54,
      55,   196,   155,   155,   155,    94,    57,    58,    59,    60,
      61,    62,    63,    64,   155,   155,   123,   155,   155,     1,
     258,   258,   261,   132,   131,   261,   155,   261,   258,   258,
      85,    13,    87,   258,   258,   261,   258,   258,   127,   258,
     155,   258,   258,   258,   228,   155,   101,   258,   258,   261,
     234,   258,    34,    35,   143,   106,   261,     1,    40,   258,
      42,   245,   246,   155,   171,   258,   258,   122,     0,     1,
     258,   255,   161,     5,   163,   164,    20,   258,   258,   258,
     258,   258,    26,   190,   258,   261,   261,   258,   261,   140,
      22,   261,   261,   261,    26,   155,   261,    29,   261,   154,
     261,   261,   261,   258,    36,   261,    50,    51,     1,   196,
     258,    55,   261,   168,   261,   261,    98,    99,   261,   261,
      52,   196,   261,   178,   258,    69,   108,   109,   261,   261,
      23,    24,    76,    65,    66,   261,    68,    30,   261,   228,
     261,   261,   261,    75,   261,   261,   128,   129,   261,   261,
     258,    95,   258,   258,   258,   258,   245,   258,   258,   258,
      92,   258,   258,   145,   146,   258,   255,   218,   258,   155,
     258,   103,   258,   105,   156,   258,   258,   258,   258,   123,
     258,   258,   258,   165,   258,   240,   258,   131,   258,   121,
     258,   258,   258,   258,   258,   258,   258,   258,   253,   258,
     251,   258,   258,   261,   258,   149,   138,   155,   258,   258,
     258,   258,   258,   258,   158,   159,   258,   110,   111,   112,
     258,   258,   115,   258,   258,   258,   258,   258,   258,   122,
     258,   258,   258,   258,   196,   258,   196,   261,   170,   261,
     196,   196,   135,   136,   196,   189,   190,   179,   180,   196,
     196,   155,   184,   185,   133,   155,   155,   196,   155,   152,
     153,   258,   261,   155,   155,   258,   248,   249,   250,   203,
     204,   205,   206,   207,   261,   209,   210,   155,   212,   213,
     214,   155,   133,   217,   177,   258,   258,   258,   258,   258,
     258,   258,   258,   227,   228,   229,   230,   231,   232,   258,
     258,   235,   246,   155,   238,   203,   204,   205,   206,   207,
     261,   209,   210,   258,   212,   213,   214,   258,   258,   217,
     258,   258,   258,   258,   155,   258,   155,   258,   258,   227,
     228,   229,   230,   231,   232,   258,   258,   235,   258,   258,
     238,   203,   204,   205,   206,   207,   261,   209,   210,   261,
     212,   213,   214,   261,   261,   217,   261,   155,   261,   261,
     261,   155,   258,   258,   258,   227,   228,   229,   230,   231,
     232,   261,   261,   235,   261,   261,   238,   261,   261,   261,
     261,   261,   155,   258,   261,   261,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   133,   258,   258,   258,
     133,   258,   133,   261,   258,   261,   133,   133,   133,   155,
     133,   133,   258,   155,   196,   155,   155,   196,   196,   196,
     155,   261,   133,   155,   196,   155,   155,   155,   258,   262,
     258,   155,   258,   258,   155,   155,   258,   258,   258,   258,
     258,   160,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   160,   258,
     196,   258,   258,   155,   155,   155,   261,   155,   261,   155,
     258,   258,   258,   258,   258,   258,   132,   258,   196,   196,
     196,   196,   196,   196,   196,   133,   196,   196,   196,   196,
     196,   196,   196,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   132,   258,   258,   258,    71,   258,   818,  1470,
     258,   312,  1451,   608,   258,  1449,  1379,  1364,  1261,   558,
    1362,   496,   526,  1429,   463,  1377,  1431,   486,   124,  1432,
    1434,   643,   184,  1355,  1212,   566,   370,    95,  1214,    -1,
     438,  1361,  1359,    -1,    -1,   258,    -1,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   358,    -1,    -1,   258,
      -1,   258,    -1,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,    -1,
     258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   264,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   103,   105,   121,   138,   170,
     179,   180,   184,   185,   265,   270,   275,   289,   295,   310,
     347,   366,   380,   406,   413,   423,   432,   463,   473,   479,
     483,   493,   557,   573,   594,   258,   259,   260,   260,   348,
     433,   474,   260,   484,   260,   558,   381,   464,   367,   260,
     260,   311,   407,   260,   260,   414,   424,     1,    37,    48,
     122,   290,   291,   292,   293,   294,     1,    13,    34,    35,
      40,    42,    98,    99,   108,   109,   128,   129,   145,   146,
     156,   165,   248,   249,   250,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   155,   349,   353,   155,   434,
     438,   260,     1,    91,   480,   481,   482,   260,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   107,   113,   114,   116,   117,   118,   119,   130,
     139,   141,   142,   144,   147,   148,   151,   162,   181,   183,
     187,   191,   192,   193,   194,   195,   199,   200,   208,   239,
     241,   247,   252,   257,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   548,   552,   553,   554,   555,
     556,   260,   260,   260,   260,     1,    57,    58,    59,    60,
      61,    62,    63,    64,   106,   140,   218,   251,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,     1,   120,   150,   271,   272,   273,   274,   155,
     312,   316,   260,     1,    41,    56,    78,    80,    82,    83,
     102,   595,   596,   597,   598,   599,   600,   601,   602,   603,
       1,    37,    86,   122,   124,   125,   167,   169,   182,   226,
     253,   254,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   260,   260,   258,   261,   261,
     261,   259,   291,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   259,   575,   260,   260,     1,    91,   157,   475,   476,
     477,   478,   261,   259,   481,     1,   122,   157,   186,   485,
     489,   490,   491,   492,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   549,   261,   545,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   259,
     495,     1,     4,    46,    49,   105,   122,   246,   559,   560,
     561,   562,   563,   567,   568,   569,     1,    20,    26,    50,
      51,    55,    69,    76,    95,   123,   131,   149,   158,   159,
     189,   190,   246,   382,   383,   384,   385,   386,   387,   388,
     389,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,     1,   157,   186,   246,   465,   469,   470,   471,   472,
       1,    55,    85,    91,   154,   368,   372,   373,   374,   378,
     379,   258,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   259,   297,   258,   261,   261,   259,
     272,   260,     1,    22,   126,   157,   408,   409,   410,   411,
     412,   261,   261,   261,   261,   261,   261,   261,   259,   596,
     258,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   259,   277,     1,   122,   186,   246,   415,   416,
     417,   418,   419,     1,   122,   186,   425,   426,   427,   428,
     155,   155,   155,   258,   196,   133,   133,   196,   196,   133,
     267,   267,   133,   133,   196,   196,   133,   267,   196,   196,
     196,   196,   196,   258,     1,    23,    24,    30,   110,   111,
     112,   115,   122,   135,   136,   152,   153,   177,   350,   351,
     352,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,     1,     3,     6,    10,    25,    26,    27,
      31,    50,    54,    55,    85,    87,   101,   122,   154,   168,
     178,   240,   253,   435,   436,   437,   439,   440,   441,   442,
     443,   444,   445,   446,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   261,   261,   259,   476,   155,   258,
     261,   261,   486,   259,   490,   196,   267,   196,   267,   133,
     155,   133,   196,   196,   196,   133,   155,   196,   133,   133,
     133,   196,   267,   196,   196,   133,   155,   196,   133,   133,
     267,   133,   155,   133,   133,   196,   196,   261,   196,   261,
     267,   267,   196,   267,   155,   196,   196,   196,   196,   197,
     196,   197,   196,   196,   267,   267,   133,   269,   267,   196,
     196,   196,   196,   258,   570,   261,   261,   564,   261,   261,
     259,   560,   258,   261,   261,   261,   261,   390,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   259,
     383,   261,   466,   261,   259,   470,   258,   369,   261,   261,
     261,   259,   373,   155,   155,   155,   155,   155,   155,   155,
     155,   219,   220,   221,   222,   223,   224,   225,   155,   155,
     196,   258,   155,   155,   258,     1,     5,    26,    38,    50,
      55,    67,    74,    79,    81,    94,   122,   127,   149,   161,
     163,   164,   168,   228,   234,   245,   246,   255,   313,   314,
     315,   317,   318,   319,   320,   321,   322,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   258,   261,   261,   261,   259,   409,   196,   196,
     196,   155,   196,   196,   267,   258,   155,   196,   155,   155,
     155,   155,   155,   155,   133,   155,   155,   258,   258,   261,
     420,   261,   259,   416,   258,   261,   429,   259,   426,   258,
     258,   258,   258,   258,   258,   258,   258,   172,   173,   174,
     175,   176,   266,   267,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   259,   351,   258,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   447,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   259,   436,   155,   155,   258,   258,   155,
     155,   261,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   203,   204,   205,   206,   207,
     209,   210,   212,   213,   214,   217,   227,   228,   229,   230,
     231,   232,   235,   238,   550,   551,   258,   203,   204,   205,
     206,   207,   209,   210,   212,   213,   214,   217,   227,   228,
     229,   230,   231,   232,   235,   238,   546,   547,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,    14,    15,    16,   268,   269,   258,
     258,   258,   258,   258,   258,   261,   267,   196,   261,   155,
     155,   258,   196,   155,   196,   196,   261,   196,   196,   196,
     196,   196,   155,   133,   155,   155,   196,   155,   258,   155,
     261,   155,   258,   261,   155,   155,   133,   376,   377,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   261,   261,   261,   261,   341,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   323,
     261,   261,   261,   259,   314,   155,   155,   155,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   155,   261,   155,
     258,   155,   261,   258,   266,   266,   266,   266,   266,   133,
     133,   267,   133,   133,   133,   133,   155,   133,   133,   267,
     267,   269,   258,   155,   215,   216,   196,   155,   155,   196,
     196,   196,   155,   261,   155,   155,   155,   155,   133,   155,
     155,   196,   155,   258,   258,   258,   258,   258,   160,   487,
     488,   258,   262,   258,   262,   268,   268,   268,    11,   198,
     571,   572,   258,   258,    11,   198,   565,   566,   258,   258,
     258,   258,   258,   258,   132,   391,   392,   394,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     160,   467,   468,   258,    78,   233,   370,   371,   258,   258,
     201,   262,   375,   196,   155,   196,   196,   261,   196,   196,
     196,   196,   196,   155,   196,   155,   196,   196,   196,   155,
     196,   261,   196,   155,   196,   258,   258,   258,   258,   258,
      94,   170,   202,   217,   236,   237,   242,   243,   244,   245,
     255,   421,   422,   258,   258,    94,   170,   202,   217,   236,
     237,   242,   243,   244,   245,   255,   430,   431,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   132,   448,   449,   451,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   262,   551,   547,   258,   262,
     258,   262,   393,   258,   262,    20,    21,    51,    69,    76,
      95,   123,   131,   171,   190,   395,   258,   262,   258,   262,
     133,   377,   258,   258,   258,   258,   258,   132,   342,   343,
     345,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   203,   204,   205,   206,   207,   209,
     210,   212,   213,   214,   217,   227,   228,   229,   230,   231,
     232,   235,   238,   324,   325,   258,   258,   258,   258,   262,
     258,   262,   450,   258,   262,    10,    12,    27,    31,   100,
     240,   452,   488,   572,   566,   395,   392,   468,   371,   344,
     258,   262,     5,    38,    50,    67,    74,    79,    81,    94,
     127,   143,   161,   163,   164,   228,   245,   255,   346,   258,
     262,   422,   431,   452,   449,   346,   343,   325
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 424 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 426 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
#line 430 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
#line 434 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
#line 438 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
#line 442 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
#line 446 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
#line 451 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
#line 469 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    add_conf_module(yylval.string);
  }
#endif
}
    break;

  case 47:
#line 486 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 510 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2 && ServerInfo.ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.ctx,
      yylval.string, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.ctx,
      ServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.ctx))
    {
      yyerror("RSA private key does not match the SSL certificate public key!");
      break;
    }
  }
#endif
}
    break;

  case 64:
#line 544 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 1)
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

    ServerInfo.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, NULL,
      0, NULL);

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

  case 65:
#line 604 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2)
  {
    if (ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if (strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name, yylval.string);
    }
  }
}
    break;

  case 66:
#line 618 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 633 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 642 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 69:
#line 656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 665 "ircd_parser.y"
    {
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 71:
#line 693 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 72:
#line 723 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 73:
#line 746 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "Ignoring config file line hub=yes; "
                             "due to active LazyLink (%s)", uplink->name);
      }
      else
      {
        ServerInfo.hub = 1;
        uplink = NULL;
        delete_capability("HUB");
        add_capability("HUB", CAP_HUB, 1);
      }
    }
    else if (ServerInfo.hub)
    {
      dlink_node *ptr = NULL;

      ServerInfo.hub = 0;
      delete_capability("HUB");

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        const struct Client *acptr = ptr->data;
        if (MyConnect(acptr) && IsCapable(acptr, CAP_LL))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               acptr->name);
          add_capability("HUB", CAP_HUB, 1);
          ServerInfo.hub = 1;
          break;
        }
      }
    }
  }
}
    break;

  case 81:
#line 802 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 811 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 820 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 847 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 851 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 855 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 862 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 869 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 876 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 883 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 890 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 897 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 904 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 911 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 915 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 919 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 923 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 927 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 931 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 935 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 941 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 950 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 119:
#line 963 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 147:
#line 1055 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 148:
#line 1067 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 149:
#line 1079 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 150:
#line 1113 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 151:
#line 1125 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 152:
#line 1136 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

  case 153:
#line 1178 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1187 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1194 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1198 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1202 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 161:
#line 1206 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 162:
#line 1210 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 163:
#line 1214 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 164:
#line 1218 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 165:
#line 1222 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 166:
#line 1226 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 167:
#line 1230 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 168:
#line 1234 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 169:
#line 1238 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 170:
#line 1242 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 171:
#line 1246 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 172:
#line 1250 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 173:
#line 1254 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 174:
#line 1258 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 175:
#line 1262 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 176:
#line 1266 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 177:
#line 1272 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 178:
#line 1283 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
}
    break;

  case 179:
#line 1294 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 180:
#line 1305 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
}
    break;

  case 181:
#line 1316 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
}
    break;

  case 182:
#line 1327 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
}
    break;

  case 183:
#line 1338 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
}
    break;

  case 184:
#line 1349 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
}
    break;

  case 185:
#line 1360 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
}
    break;

  case 186:
#line 1371 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
}
    break;

  case 187:
#line 1382 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
}
    break;

  case 188:
#line 1393 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 189:
#line 1404 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 190:
#line 1415 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
}
    break;

  case 191:
#line 1426 "ircd_parser.y"
    {
}
    break;

  case 195:
#line 1430 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 197:
#line 1431 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 199:
#line 1434 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 200:
#line 1441 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 201:
#line 1448 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 202:
#line 1455 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 203:
#line 1462 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 204:
#line 1469 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 205:
#line 1476 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 206:
#line 1483 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 207:
#line 1490 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 208:
#line 1497 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 209:
#line 1504 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 210:
#line 1511 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 211:
#line 1518 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 212:
#line 1525 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 213:
#line 1532 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 214:
#line 1539 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 215:
#line 1552 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 216:
#line 1559 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

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

  case 235:
#line 1619 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1628 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 237:
#line 1637 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
#line 1643 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
#line 1649 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
#line 1655 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
#line 1661 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
#line 1667 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
#line 1673 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
#line 1679 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
#line 1685 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
#line 1691 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
#line 1697 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
#line 1703 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
#line 1712 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 250:
#line 1719 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 251:
#line 1728 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 255:
#line 1734 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 256:
#line 1738 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 264:
#line 1746 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 268:
#line 1751 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), listener_address, listener_flags);
  }
}
    break;

  case 269:
#line 1765 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
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

  case 270:
#line 1785 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 271:
#line 1794 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 272:
#line 1806 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 273:
#line 1818 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 293:
#line 1883 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 294:
#line 1920 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 295:
#line 1933 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 296:
#line 1944 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 297:
#line 1953 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 298:
#line 1964 "ircd_parser.y"
    {
}
    break;

  case 302:
#line 1968 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 304:
#line 1969 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 306:
#line 1972 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 307:
#line 1980 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 308:
#line 1987 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 309:
#line 1994 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 310:
#line 2001 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 311:
#line 2008 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 312:
#line 2015 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 313:
#line 2022 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 314:
#line 2029 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 315:
#line 2036 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 316:
#line 2045 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
}
    break;

  case 317:
#line 2056 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 318:
#line 2067 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 319:
#line 2078 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 320:
#line 2089 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
}
    break;

  case 321:
#line 2100 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
}
    break;

  case 322:
#line 2112 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 323:
#line 2131 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 324:
#line 2141 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 325:
#line 2150 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 326:
#line 2165 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 327:
#line 2172 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 334:
#line 2184 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 335:
#line 2193 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 336:
#line 2208 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 337:
#line 2221 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 338:
#line 2229 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 345:
#line 2240 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 346:
#line 2249 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 347:
#line 2271 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 351:
#line 2278 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 352:
#line 2282 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 353:
#line 2286 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 354:
#line 2290 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 355:
#line 2294 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 356:
#line 2298 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 357:
#line 2302 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 358:
#line 2306 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 359:
#line 2310 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 360:
#line 2314 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 361:
#line 2318 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 362:
#line 2327 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 363:
#line 2334 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 369:
#line 2347 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 370:
#line 2353 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 374:
#line 2360 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 375:
#line 2364 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 376:
#line 2368 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 377:
#line 2372 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 378:
#line 2376 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 379:
#line 2380 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 380:
#line 2384 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 381:
#line 2388 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 382:
#line 2392 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 383:
#line 2396 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 384:
#line 2400 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 385:
#line 2409 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->passwd = NULL;
    /* defaults */
    yy_aconf->port = PORTNUM;

    if (ConfigFileEntry.burst_away)
      yy_aconf->flags = CONF_FLAGS_BURST_AWAY;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 386:
#line 2427 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr;
    dlink_node *next_ptr;
#ifdef HAVE_LIBCRYPTO
    if (yy_aconf->host &&
	((yy_aconf->passwd && yy_aconf->spasswd) ||
	 (yy_aconf->rsa_public_key && IsConfCryptLink(yy_aconf))))
#else /* !HAVE_LIBCRYPTO */
      if (yy_aconf->host && !IsConfCryptLink(yy_aconf) && 
	  yy_aconf->passwd && yy_aconf->spasswd)
#endif /* !HAVE_LIBCRYPTO */
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
#ifndef HAVE_LIBCRYPTO
	    if (IsConfCryptLink(yy_aconf))
	      yyerror("Ignoring connect block -- no OpenSSL support");
#else
	    if (IsConfCryptLink(yy_aconf) && !yy_aconf->rsa_public_key)
	      yyerror("Ignoring connect block -- missing key");
#endif
	    if (yy_aconf->host == NULL)
	      yyerror("Ignoring connect block -- missing host");
	    else if (!IsConfCryptLink(yy_aconf) && 
		    (!yy_aconf->passwd || !yy_aconf->spasswd))
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

  case 411:
#line 2566 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 412:
#line 2578 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 413:
#line 2590 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 414:
#line 2599 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);
    }
  }
}
    break;

  case 415:
#line 2625 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 416:
#line 2643 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 417:
#line 2661 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 418:
#line 2667 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 419:
#line 2671 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 420:
#line 2679 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 421:
#line 2688 "ircd_parser.y"
    {
}
    break;

  case 425:
#line 2692 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 427:
#line 2693 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 429:
#line 2696 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 430:
#line 2703 "ircd_parser.y"
    {
  if (ypass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   if (not_atom)ClearConfCompressed(yy_aconf);
   else SetConfCompressed(yy_aconf);
 }
#endif
}
    break;

  case 431:
#line 2714 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 432:
#line 2721 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 433:
#line 2728 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 434:
#line 2735 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 435:
#line 2745 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
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

  case 436:
#line 2786 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 437:
#line 2797 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
}
    break;

  case 438:
#line 2808 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
#ifndef HAVE_LIBZ
      yyerror("Ignoring compressed=yes; -- no zlib support");
#else
      yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
    else
      yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  }
}
    break;

  case 439:
#line 2823 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
}
    break;

  case 440:
#line 2834 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfTopicBurst(yy_aconf);
    else
      ClearConfTopicBurst(yy_aconf);
  }
}
    break;

  case 441:
#line 2845 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 442:
#line 2858 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 443:
#line 2871 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 444:
#line 2880 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    yy_aconf->cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        yy_aconf->cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 445:
#line 2915 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 446:
#line 2922 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
        pcre *exp_user = NULL;
        pcre *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
      }
      else
      {
        yy_conf = make_conf_item(KLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }
    else
      delete_conf_item(yy_conf);

    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 447:
#line 2979 "ircd_parser.y"
    {
}
    break;

  case 451:
#line 2984 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 458:
#line 2993 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 459:
#line 3012 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 460:
#line 3021 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
}
    break;

  case 461:
#line 3030 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_DLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 467:
#line 3046 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 468:
#line 3055 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 474:
#line 3072 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
      yy_aconf = map_to_conf(yy_conf);
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);

      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 475:
#line 3093 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 476:
#line 3100 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
        pcre *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
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

  case 477:
#line 3135 "ircd_parser.y"
    {
}
    break;

  case 481:
#line 3140 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 488:
#line 3149 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 489:
#line 3155 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 549:
#line 3200 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 550:
#line 3205 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 551:
#line 3210 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 552:
#line 3215 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 553:
#line 3220 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 554:
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 555:
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 556:
#line 3235 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 557:
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 558:
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 559:
#line 3250 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 560:
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 561:
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 562:
#line 3265 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 563:
#line 3270 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 564:
#line 3275 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 565:
#line 3280 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 566:
#line 3285 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 567:
#line 3291 "ircd_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 568:
#line 3302 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 569:
#line 3307 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 570:
#line 3316 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 571:
#line 3321 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 572:
#line 3326 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 573:
#line 3331 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 574:
#line 3336 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 575:
#line 3341 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 576:
#line 3344 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 577:
#line 3349 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 578:
#line 3352 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 579:
#line 3357 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 580:
#line 3362 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:
#line 3367 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 582:
#line 3372 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:
#line 3377 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 584:
#line 3382 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 585:
#line 3387 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 586:
#line 3392 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 587:
#line 3397 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 588:
#line 3408 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
#line 3413 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 590:
#line 3418 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:
#line 3423 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 592:
#line 3432 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    ConfigFileEntry.default_cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        ConfigFileEntry.default_cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 593:
#line 3464 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = (yyvsp[(3) - (4)].number);
#ifndef HAVE_LIBZ
    yyerror("Ignoring compression_level -- no zlib support");
#else
    if ((ConfigFileEntry.compression_level < 1) ||
        (ConfigFileEntry.compression_level > 9))
    {
      yyerror("Ignoring invalid compression_level, using default");
      ConfigFileEntry.compression_level = 0;
    }
#endif
  }
}
    break;

  case 594:
#line 3482 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 595:
#line 3487 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 596:
#line 3496 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 597:
#line 3501 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 598:
#line 3506 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 599:
#line 3511 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 603:
#line 3517 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 604:
#line 3520 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 605:
#line 3523 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 606:
#line 3526 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 607:
#line 3529 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 608:
#line 3532 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 609:
#line 3535 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 610:
#line 3538 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 611:
#line 3541 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 612:
#line 3544 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 613:
#line 3547 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 614:
#line 3550 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 615:
#line 3553 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 616:
#line 3556 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 617:
#line 3559 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 618:
#line 3562 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 619:
#line 3565 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 620:
#line 3568 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 621:
#line 3571 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 622:
#line 3576 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 626:
#line 3582 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 627:
#line 3585 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 628:
#line 3588 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 629:
#line 3591 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 630:
#line 3594 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 631:
#line 3597 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 632:
#line 3600 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 633:
#line 3603 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 634:
#line 3606 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 635:
#line 3609 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 636:
#line 3612 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 637:
#line 3615 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 638:
#line 3618 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 639:
#line 3621 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 640:
#line 3624 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 641:
#line 3627 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 642:
#line 3630 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 643:
#line 3633 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 644:
#line 3636 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 645:
#line 3641 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:
#line 3646 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:
#line 3651 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:
#line 3656 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 649:
#line 3661 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 650:
#line 3669 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 651:
#line 3676 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 661:
#line 3702 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 662:
#line 3708 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 663:
#line 3714 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 667:
#line 3720 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 668:
#line 3724 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 669:
#line 3730 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 670:
#line 3764 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 671:
#line 3773 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 672:
#line 3777 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 675:
#line 3824 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 676:
#line 3828 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 699:
#line 3852 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 700:
#line 3857 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 701:
#line 3862 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 702:
#line 3867 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 703:
#line 3872 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 704:
#line 3877 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 705:
#line 3882 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 706:
#line 3887 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 707:
#line 3892 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 708:
#line 3897 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 709:
#line 3902 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 710:
#line 3907 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 711:
#line 3912 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 712:
#line 3917 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 713:
#line 3922 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 714:
#line 3927 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 715:
#line 3932 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 716:
#line 3937 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 728:
#line 3956 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 729:
#line 3962 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 730:
#line 3968 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 731:
#line 3977 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 732:
#line 3991 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 733:
#line 3997 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 734:
#line 4003 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1267 of yacc.c.  */
#line 7794 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



