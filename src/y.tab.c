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
     T_CLIENT_FLOOD = 462,
     T_DEAF = 463,
     T_DEBUG = 464,
     T_DRONE = 465,
     T_EXTERNAL = 466,
     T_FULL = 467,
     T_INVISIBLE = 468,
     T_IPV4 = 469,
     T_IPV6 = 470,
     T_LOCOPS = 471,
     T_LOGPATH = 472,
     T_L_CRIT = 473,
     T_L_DEBUG = 474,
     T_L_ERROR = 475,
     T_L_INFO = 476,
     T_L_NOTICE = 477,
     T_L_TRACE = 478,
     T_L_WARN = 479,
     T_MAX_CLIENTS = 480,
     T_NCHANGE = 481,
     T_OPERWALL = 482,
     T_REJ = 483,
     T_SERVNOTICE = 484,
     T_SERVCONN = 485,
     T_SKILL = 486,
     T_SPY = 487,
     T_SSL = 488,
     T_UMODES = 489,
     T_UNAUTH = 490,
     T_UNRESV = 491,
     T_UNXLINE = 492,
     T_WALLOP = 493,
     T_GOD = 494,
     T_NICKSERVREG = 495,
     THROTTLE_TIME = 496,
     TOPICBURST = 497,
     TRUE_NO_OPER_FLOOD = 498,
     TKLINE = 499,
     TXLINE = 500,
     TRESV = 501,
     UNKLINE = 502,
     USER = 503,
     USE_EGD = 504,
     USE_EXCEPT = 505,
     USE_INVEX = 506,
     USE_KNOCK = 507,
     USE_LOGGING = 508,
     USE_WHOIS_ACTUALLY = 509,
     VHOST = 510,
     VHOST6 = 511,
     XLINE = 512,
     WARN = 513,
     WARN_NO_NLINE = 514
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
#define T_CLIENT_FLOOD 462
#define T_DEAF 463
#define T_DEBUG 464
#define T_DRONE 465
#define T_EXTERNAL 466
#define T_FULL 467
#define T_INVISIBLE 468
#define T_IPV4 469
#define T_IPV6 470
#define T_LOCOPS 471
#define T_LOGPATH 472
#define T_L_CRIT 473
#define T_L_DEBUG 474
#define T_L_ERROR 475
#define T_L_INFO 476
#define T_L_NOTICE 477
#define T_L_TRACE 478
#define T_L_WARN 479
#define T_MAX_CLIENTS 480
#define T_NCHANGE 481
#define T_OPERWALL 482
#define T_REJ 483
#define T_SERVNOTICE 484
#define T_SERVCONN 485
#define T_SKILL 486
#define T_SPY 487
#define T_SSL 488
#define T_UMODES 489
#define T_UNAUTH 490
#define T_UNRESV 491
#define T_UNXLINE 492
#define T_WALLOP 493
#define T_GOD 494
#define T_NICKSERVREG 495
#define THROTTLE_TIME 496
#define TOPICBURST 497
#define TRUE_NO_OPER_FLOOD 498
#define TKLINE 499
#define TXLINE 500
#define TRESV 501
#define UNKLINE 502
#define USER 503
#define USE_EGD 504
#define USE_EXCEPT 505
#define USE_INVEX 506
#define USE_KNOCK 507
#define USE_LOGGING 508
#define USE_WHOIS_ACTUALLY 509
#define VHOST 510
#define VHOST6 511
#define XLINE 512
#define WARN 513
#define WARN_NO_NLINE 514




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
#line 728 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 741 "y.tab.c"

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
#define YYLAST   1396

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  341
/* YYNRULES -- Number of rules.  */
#define YYNRULES  734
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1478

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   514

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   264,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   260,
       2,   263,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   262,     2,   261,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259
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
     266,     0,    -1,    -1,   266,   267,    -1,   291,    -1,   297,
      -1,   312,    -1,   575,    -1,   349,    -1,   368,    -1,   382,
      -1,   277,    -1,   596,    -1,   408,    -1,   415,    -1,   425,
      -1,   434,    -1,   465,    -1,   475,    -1,   481,    -1,   495,
      -1,   559,    -1,   485,    -1,   272,    -1,     1,   260,    -1,
       1,   261,    -1,    -1,   269,    -1,   133,   268,    -1,   133,
     172,   268,    -1,   133,   173,   268,    -1,   133,   174,   268,
      -1,   133,   175,   268,    -1,   133,   176,   268,    -1,    -1,
     271,    -1,   133,   270,    -1,   133,    14,   270,    -1,   133,
      15,   270,    -1,   133,    16,   270,    -1,   121,   262,   273,
     261,   260,    -1,   273,   274,    -1,   274,    -1,   275,    -1,
     276,    -1,     1,   260,    -1,   120,   263,   155,   260,    -1,
     150,   263,   155,   260,    -1,   180,   262,   278,   261,   260,
      -1,   278,   279,    -1,   279,    -1,   282,    -1,   287,    -1,
     290,    -1,   284,    -1,   285,    -1,   286,    -1,   289,    -1,
     281,    -1,   288,    -1,   283,    -1,   280,    -1,     1,   260,
      -1,   169,   263,   155,   260,    -1,   167,   263,   155,   260,
      -1,   122,   263,   155,   260,    -1,   182,   263,   155,   260,
      -1,    37,   263,   155,   260,    -1,   125,   263,   155,   260,
      -1,   124,   263,   155,   260,    -1,   255,   263,   155,   260,
      -1,   256,   263,   155,   260,    -1,   225,   263,   133,   260,
      -1,    86,   263,   196,   260,    -1,     5,   262,   292,   261,
     260,    -1,   292,   293,    -1,   293,    -1,   294,    -1,   296,
      -1,   295,    -1,     1,   260,    -1,   122,   263,   155,   260,
      -1,    48,   263,   155,   260,    -1,    37,   263,   155,   260,
      -1,   105,   262,   298,   261,   260,    -1,   298,   299,    -1,
     299,    -1,   300,    -1,   301,    -1,   310,    -1,   311,    -1,
     302,    -1,   304,    -1,   306,    -1,   307,    -1,   309,    -1,
     305,    -1,   308,    -1,   303,    -1,     1,   260,    -1,   217,
     263,   155,   260,    -1,   140,   263,   155,   260,    -1,    64,
     263,   155,   260,    -1,    57,   263,   155,   260,    -1,    62,
     263,   155,   260,    -1,    63,   263,   155,   260,    -1,    60,
     263,   155,   260,    -1,    59,   263,   155,   260,    -1,    61,
     263,   155,   260,    -1,    58,   263,   155,   260,    -1,   106,
     263,   218,   260,    -1,   106,   263,   220,   260,    -1,   106,
     263,   224,   260,    -1,   106,   263,   222,   260,    -1,   106,
     263,   223,   260,    -1,   106,   263,   221,   260,    -1,   106,
     263,   219,   260,    -1,   253,   263,   196,   260,    -1,    -1,
     138,   313,   314,   262,   315,   261,   260,    -1,    -1,   318,
      -1,   315,   316,    -1,   316,    -1,   317,    -1,   319,    -1,
     320,    -1,   339,    -1,   340,    -1,   324,    -1,   323,    -1,
     328,    -1,   329,    -1,   331,    -1,   332,    -1,   333,    -1,
     334,    -1,   335,    -1,   330,    -1,   336,    -1,   337,    -1,
     338,    -1,   341,    -1,   321,    -1,   322,    -1,   342,    -1,
       1,   260,    -1,   122,   263,   155,   260,    -1,   155,    -1,
     248,   263,   155,   260,    -1,   149,   263,   155,   260,    -1,
      50,   263,   196,   260,    -1,   168,   263,   155,   260,    -1,
      26,   263,   155,   260,    -1,    -1,   234,   325,   263,   326,
     260,    -1,   326,   264,   327,    -1,   327,    -1,   203,    -1,
     206,    -1,   208,    -1,   209,    -1,   212,    -1,   231,    -1,
     226,    -1,   228,    -1,   235,    -1,   232,    -1,   211,    -1,
     227,    -1,   229,    -1,   213,    -1,   238,    -1,   204,    -1,
     205,    -1,   216,    -1,   239,    -1,    74,   263,   196,   260,
      -1,   163,   263,   196,   260,    -1,   164,   263,   196,   260,
      -1,    94,   263,   196,   260,    -1,   257,   263,   196,   260,
      -1,   247,   263,   196,   260,    -1,    67,   263,   196,   260,
      -1,   127,   263,   196,   260,    -1,    38,   263,   196,   260,
      -1,   161,   263,   196,   260,    -1,     5,   263,   196,   260,
      -1,    79,   263,   196,   260,    -1,    81,   263,   196,   260,
      -1,   227,   263,   196,   260,    -1,    -1,    55,   343,   263,
     344,   260,    -1,   344,   264,   345,    -1,   345,    -1,    -1,
     132,   346,   348,    -1,    -1,   347,   348,    -1,    74,    -1,
     163,    -1,    94,    -1,   247,    -1,   257,    -1,    67,    -1,
      38,    -1,   161,    -1,     5,    -1,    79,    -1,   127,    -1,
     227,    -1,   143,    -1,    81,    -1,   164,    -1,    50,    -1,
      -1,    26,   350,   351,   262,   352,   261,   260,    -1,    -1,
     355,    -1,   352,   353,    -1,   353,    -1,   354,    -1,   365,
      -1,   366,    -1,   356,    -1,   357,    -1,   367,    -1,   358,
      -1,   359,    -1,   360,    -1,   361,    -1,   362,    -1,   363,
      -1,   364,    -1,     1,   260,    -1,   122,   263,   155,   260,
      -1,   155,    -1,   152,   263,   269,   260,    -1,   153,   263,
     269,   260,    -1,   136,   263,   133,   260,    -1,    30,   263,
     269,   260,    -1,   115,   263,   133,   260,    -1,   110,   263,
     133,   260,    -1,   112,   263,   133,   260,    -1,   111,   263,
     133,   260,    -1,   177,   263,   271,   260,    -1,    23,   263,
     133,   260,    -1,    24,   263,   133,   260,    -1,   135,   263,
     133,   260,    -1,    -1,   103,   369,   262,   374,   261,   260,
      -1,    -1,    55,   371,   263,   372,   260,    -1,   372,   264,
     373,    -1,   373,    -1,   233,    -1,    78,    -1,   374,   375,
      -1,   375,    -1,   376,    -1,   370,    -1,   380,    -1,   381,
      -1,     1,   260,    -1,    -1,   154,   263,   378,   377,   260,
      -1,   378,   264,   379,    -1,   379,    -1,   133,    -1,   133,
     201,   133,    -1,    91,   263,   155,   260,    -1,    85,   263,
     155,   260,    -1,    -1,    75,   383,   262,   384,   261,   260,
      -1,   384,   385,    -1,   385,    -1,   386,    -1,   387,    -1,
     389,    -1,   391,    -1,   398,    -1,   399,    -1,   400,    -1,
     402,    -1,   403,    -1,   404,    -1,   388,    -1,   405,    -1,
     406,    -1,   401,    -1,   407,    -1,   390,    -1,     1,   260,
      -1,   248,   263,   155,   260,    -1,   149,   263,   155,   260,
      -1,   190,   263,   196,   260,    -1,    26,   263,   155,   260,
      -1,    50,   263,   196,   260,    -1,    -1,    55,   392,   263,
     393,   260,    -1,   393,   264,   394,    -1,   394,    -1,    -1,
     132,   395,   397,    -1,    -1,   396,   397,    -1,   190,    -1,
      51,    -1,    95,    -1,    76,    -1,    20,    -1,    21,    -1,
     131,    -1,    69,    -1,   171,    -1,   123,    -1,    95,   263,
     196,   260,    -1,    76,   263,   196,   260,    -1,    51,   263,
     196,   260,    -1,    20,   263,   196,   260,    -1,   131,   263,
     196,   260,    -1,    69,   263,   196,   260,    -1,   189,   263,
     155,   260,    -1,   159,   263,   155,   260,    -1,   158,   263,
     133,   260,    -1,   123,   263,   196,   260,    -1,    -1,   170,
     409,   262,   410,   261,   260,    -1,   410,   411,    -1,   411,
      -1,   412,    -1,   413,    -1,   414,    -1,     1,   260,    -1,
     157,   263,   155,   260,    -1,    22,   263,   155,   260,    -1,
     126,   263,   155,   260,    -1,    -1,   184,   416,   262,   417,
     261,   260,    -1,   417,   418,    -1,   418,    -1,   419,    -1,
     420,    -1,   421,    -1,     1,   260,    -1,   122,   263,   155,
     260,    -1,   248,   263,   155,   260,    -1,    -1,   186,   422,
     263,   423,   260,    -1,   423,   264,   424,    -1,   424,    -1,
      94,    -1,   244,    -1,   247,    -1,   257,    -1,   245,    -1,
     237,    -1,   170,    -1,   246,    -1,   236,    -1,   216,    -1,
     202,    -1,    -1,   185,   426,   262,   427,   261,   260,    -1,
     427,   428,    -1,   428,    -1,   429,    -1,   430,    -1,     1,
     260,    -1,   122,   263,   155,   260,    -1,    -1,   186,   431,
     263,   432,   260,    -1,   432,   264,   433,    -1,   433,    -1,
      94,    -1,   244,    -1,   247,    -1,   257,    -1,   245,    -1,
     237,    -1,   170,    -1,   246,    -1,   236,    -1,   216,    -1,
     202,    -1,    -1,    29,   435,   436,   262,   437,   261,   260,
      -1,    -1,   440,    -1,   437,   438,    -1,   438,    -1,   439,
      -1,   441,    -1,   442,    -1,   443,    -1,   444,    -1,   446,
      -1,   445,    -1,   447,    -1,   448,    -1,   461,    -1,   462,
      -1,   463,    -1,   459,    -1,   456,    -1,   458,    -1,   457,
      -1,   455,    -1,   464,    -1,   460,    -1,     1,   260,    -1,
     122,   263,   155,   260,    -1,   155,    -1,    85,   263,   155,
     260,    -1,   255,   263,   155,   260,    -1,   178,   263,   155,
     260,    -1,     3,   263,   155,   260,    -1,   154,   263,   133,
     260,    -1,     6,   263,   214,   260,    -1,     6,   263,   215,
     260,    -1,    54,   263,   155,   260,    -1,    -1,    55,   449,
     263,   450,   260,    -1,   450,   264,   451,    -1,   451,    -1,
      -1,   132,   452,   454,    -1,    -1,   453,   454,    -1,   100,
      -1,    27,    -1,    31,    -1,    10,    -1,    12,    -1,   242,
      -1,   168,   263,   155,   260,    -1,    50,   263,   196,   260,
      -1,    31,   263,   196,   260,    -1,    27,   263,   196,   260,
      -1,    10,   263,   196,   260,    -1,   242,   263,   196,   260,
      -1,    87,   263,   155,   260,    -1,   101,   263,   155,   260,
      -1,    26,   263,   155,   260,    -1,    25,   263,   155,   260,
      -1,    -1,    92,   466,   262,   471,   261,   260,    -1,    -1,
     186,   468,   263,   469,   260,    -1,   469,   264,   470,    -1,
     470,    -1,   160,    -1,   471,   472,    -1,   472,    -1,   473,
      -1,   474,    -1,   467,    -1,     1,    -1,   248,   263,   155,
     260,    -1,   157,   263,   155,   260,    -1,    -1,    36,   476,
     262,   477,   261,   260,    -1,   477,   478,    -1,   478,    -1,
     479,    -1,   480,    -1,     1,    -1,    91,   263,   155,   260,
      -1,   157,   263,   155,   260,    -1,    52,   262,   482,   261,
     260,    -1,   482,   483,    -1,   483,    -1,   484,    -1,     1,
      -1,    91,   263,   155,   260,    -1,    -1,    65,   486,   262,
     491,   261,   260,    -1,    -1,   186,   488,   263,   489,   260,
      -1,   489,   264,   490,    -1,   490,    -1,   160,    -1,   491,
     492,    -1,   492,    -1,   493,    -1,   494,    -1,   487,    -1,
       1,    -1,   122,   263,   155,   260,    -1,   157,   263,   155,
     260,    -1,    66,   262,   496,   261,   260,    -1,   496,   497,
      -1,   497,    -1,   505,    -1,   506,    -1,   508,    -1,   509,
      -1,   510,    -1,   511,    -1,   512,    -1,   513,    -1,   514,
      -1,   515,    -1,   504,    -1,   517,    -1,   518,    -1,   519,
      -1,   520,    -1,   536,    -1,   522,    -1,   524,    -1,   526,
      -1,   525,    -1,   529,    -1,   523,    -1,   530,    -1,   531,
      -1,   532,    -1,   533,    -1,   535,    -1,   534,    -1,   550,
      -1,   537,    -1,   541,    -1,   542,    -1,   546,    -1,   527,
      -1,   528,    -1,   556,    -1,   554,    -1,   555,    -1,   538,
      -1,   507,    -1,   539,    -1,   540,    -1,   557,    -1,   545,
      -1,   516,    -1,   558,    -1,   543,    -1,   544,    -1,   500,
      -1,   503,    -1,   498,    -1,   499,    -1,   501,    -1,   502,
      -1,   521,    -1,     1,    -1,    72,   263,   133,   260,    -1,
      73,   263,   133,   260,    -1,    12,   263,   196,   260,    -1,
     254,   263,   196,   260,    -1,   162,   263,   269,   260,    -1,
     183,   263,   196,   260,    -1,    93,   263,   133,   260,    -1,
      84,   263,   196,   260,    -1,    89,   263,   196,   260,    -1,
      43,   263,   196,   260,    -1,    53,   263,   196,   260,    -1,
       8,   263,   196,   260,    -1,   114,   263,   269,   260,    -1,
     113,   263,   133,   260,    -1,   107,   263,   133,   260,    -1,
       9,   263,   269,   260,    -1,   200,   263,   269,   260,    -1,
     199,   263,   269,   260,    -1,    77,   263,   133,   260,    -1,
      97,   263,   196,   260,    -1,    96,   263,   155,   260,    -1,
      90,   263,   196,   260,    -1,   259,   263,   196,   260,    -1,
     191,   263,   196,   260,    -1,   194,   263,   196,   260,    -1,
     195,   263,   196,   260,    -1,   193,   263,   196,   260,    -1,
     193,   263,   197,   260,    -1,   192,   263,   196,   260,    -1,
     192,   263,   197,   260,    -1,   147,   263,   269,   260,    -1,
      19,   263,   269,   260,    -1,   139,   263,   196,   260,    -1,
     148,   263,   269,   260,    -1,   187,   263,   196,   260,    -1,
     130,   263,   196,   260,    -1,   243,   263,   196,   260,    -1,
     142,   263,   196,   260,    -1,   117,   263,   155,   260,    -1,
      88,   263,   269,   260,    -1,    45,   263,   133,   260,    -1,
     116,   263,   133,   260,    -1,   181,   263,   155,   260,    -1,
      32,   263,   155,   260,    -1,    28,   263,   133,   260,    -1,
     249,   263,   196,   260,    -1,    47,   263,   155,   260,    -1,
     151,   263,   196,   260,    -1,    39,   263,   196,   260,    -1,
     241,   263,   269,   260,    -1,    -1,   144,   547,   263,   548,
     260,    -1,   548,   264,   549,    -1,   549,    -1,   203,    -1,
     206,    -1,   208,    -1,   209,    -1,   212,    -1,   231,    -1,
     226,    -1,   228,    -1,   235,    -1,   232,    -1,   211,    -1,
     227,    -1,   229,    -1,   213,    -1,   238,    -1,   204,    -1,
     205,    -1,   216,    -1,   239,    -1,    -1,   141,   551,   263,
     552,   260,    -1,   552,   264,   553,    -1,   553,    -1,   203,
      -1,   206,    -1,   208,    -1,   209,    -1,   212,    -1,   231,
      -1,   226,    -1,   228,    -1,   235,    -1,   232,    -1,   211,
      -1,   227,    -1,   229,    -1,   230,    -1,   213,    -1,   238,
      -1,   204,    -1,   205,    -1,   216,    -1,   118,   263,   133,
     260,    -1,   119,   263,   133,   260,    -1,    33,   263,   133,
     260,    -1,   207,   263,   271,   260,    -1,    44,   263,   196,
     260,    -1,    -1,    68,   560,   262,   561,   261,   260,    -1,
     561,   562,    -1,   562,    -1,   563,    -1,   564,    -1,   565,
      -1,   569,    -1,   570,    -1,   571,    -1,     1,    -1,    49,
     263,   196,   260,    -1,    46,   263,   269,   260,    -1,    -1,
     105,   566,   263,   567,   260,    -1,   567,   264,   568,    -1,
     568,    -1,   198,    -1,    11,    -1,   248,   263,   155,   260,
      -1,   122,   263,   155,   260,    -1,    -1,     4,   572,   263,
     573,   260,    -1,   573,   264,   574,    -1,   574,    -1,   198,
      -1,    11,    -1,    22,   262,   576,   261,   260,    -1,   576,
     577,    -1,   577,    -1,   580,    -1,   581,    -1,   582,    -1,
     583,    -1,   588,    -1,   584,    -1,   585,    -1,   586,    -1,
     587,    -1,   589,    -1,   590,    -1,   591,    -1,   579,    -1,
     592,    -1,   593,    -1,   594,    -1,   595,    -1,   578,    -1,
       1,    -1,    40,   263,   196,   260,    -1,   165,   263,   196,
     260,    -1,    42,   263,   196,   260,    -1,   250,   263,   196,
     260,    -1,   251,   263,   196,   260,    -1,   252,   263,   196,
     260,    -1,    98,   263,   269,   260,    -1,    99,   263,   269,
     260,    -1,   109,   263,   133,   260,    -1,   156,   263,   196,
     260,    -1,   108,   263,   133,   260,    -1,    35,   263,   133,
     260,    -1,    34,   263,   133,   260,    -1,   128,   263,   196,
     260,    -1,   129,   263,   196,   260,    -1,    13,   263,   196,
     260,    -1,   145,   263,   133,   260,    -1,   146,   263,   269,
     260,    -1,   179,   262,   597,   261,   260,    -1,   597,   598,
      -1,   598,    -1,   599,    -1,   600,    -1,   602,    -1,   604,
      -1,   603,    -1,   601,    -1,   605,    -1,     1,    -1,    56,
     263,   196,   260,    -1,    83,   263,   196,   260,    -1,    80,
     263,   155,   260,    -1,   102,   263,   269,   260,    -1,    78,
     263,   196,   260,    -1,    41,   263,   196,   260,    -1,    82,
     263,   196,   260,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   397,   397,   398,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   426,   426,   427,   431,
     435,   439,   443,   447,   453,   453,   454,   455,   456,   457,
     464,   467,   467,   468,   468,   468,   470,   487,   498,   501,
     502,   503,   503,   504,   504,   505,   505,   506,   507,   507,
     508,   508,   509,   511,   545,   605,   619,   634,   643,   657,
     666,   694,   724,   747,   797,   799,   799,   800,   800,   801,
     801,   803,   812,   821,   834,   836,   837,   839,   839,   840,
     841,   841,   842,   842,   843,   843,   844,   844,   845,   846,
     848,   852,   856,   863,   870,   877,   884,   891,   898,   905,
     912,   916,   920,   924,   928,   932,   936,   942,   952,   951,
    1045,  1045,  1046,  1046,  1047,  1047,  1047,  1047,  1048,  1048,
    1049,  1049,  1049,  1050,  1050,  1050,  1051,  1051,  1051,  1052,
    1052,  1052,  1052,  1053,  1053,  1054,  1054,  1056,  1068,  1080,
    1114,  1126,  1137,  1179,  1189,  1188,  1194,  1194,  1195,  1199,
    1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,
    1243,  1247,  1251,  1255,  1259,  1263,  1267,  1273,  1284,  1295,
    1306,  1317,  1328,  1339,  1350,  1361,  1372,  1383,  1394,  1405,
    1416,  1428,  1427,  1431,  1431,  1432,  1432,  1433,  1433,  1435,
    1442,  1449,  1456,  1463,  1470,  1477,  1484,  1491,  1498,  1505,
    1512,  1519,  1526,  1533,  1540,  1554,  1553,  1595,  1595,  1597,
    1597,  1598,  1599,  1599,  1600,  1601,  1602,  1603,  1604,  1605,
    1606,  1607,  1608,  1609,  1610,  1612,  1621,  1630,  1636,  1642,
    1648,  1654,  1660,  1666,  1672,  1678,  1684,  1690,  1696,  1706,
    1705,  1722,  1721,  1726,  1726,  1727,  1731,  1737,  1737,  1738,
    1738,  1738,  1738,  1738,  1740,  1740,  1742,  1742,  1744,  1758,
    1778,  1787,  1800,  1799,  1868,  1868,  1869,  1869,  1869,  1869,
    1870,  1870,  1871,  1871,  1871,  1872,  1872,  1873,  1873,  1873,
    1874,  1874,  1874,  1876,  1913,  1926,  1937,  1946,  1958,  1957,
    1961,  1961,  1962,  1962,  1963,  1963,  1965,  1973,  1980,  1987,
    1994,  2001,  2008,  2015,  2022,  2029,  2038,  2049,  2060,  2071,
    2082,  2093,  2105,  2124,  2134,  2143,  2159,  2158,  2174,  2174,
    2175,  2175,  2175,  2175,  2177,  2186,  2201,  2215,  2214,  2230,
    2230,  2231,  2231,  2231,  2231,  2233,  2242,  2265,  2264,  2270,
    2270,  2271,  2275,  2279,  2283,  2287,  2291,  2295,  2299,  2303,
    2307,  2311,  2321,  2320,  2337,  2337,  2338,  2338,  2338,  2340,
    2347,  2346,  2352,  2352,  2353,  2357,  2361,  2365,  2369,  2373,
    2377,  2381,  2385,  2389,  2393,  2403,  2402,  2548,  2548,  2549,
    2549,  2550,  2550,  2550,  2551,  2551,  2552,  2552,  2553,  2553,
    2553,  2554,  2554,  2554,  2555,  2555,  2555,  2556,  2556,  2557,
    2557,  2559,  2571,  2583,  2592,  2618,  2636,  2654,  2660,  2664,
    2672,  2682,  2681,  2685,  2685,  2686,  2686,  2687,  2687,  2689,
    2696,  2707,  2714,  2721,  2728,  2738,  2779,  2790,  2801,  2816,
    2827,  2838,  2851,  2864,  2873,  2909,  2908,  2973,  2972,  2976,
    2976,  2977,  2983,  2983,  2984,  2984,  2984,  2984,  2986,  3005,
    3015,  3014,  3036,  3036,  3037,  3037,  3037,  3039,  3048,  3060,
    3062,  3062,  3063,  3063,  3065,  3087,  3086,  3129,  3128,  3132,
    3132,  3133,  3139,  3139,  3140,  3140,  3140,  3140,  3142,  3148,
    3157,  3160,  3160,  3161,  3161,  3162,  3162,  3163,  3163,  3164,
    3164,  3165,  3165,  3166,  3166,  3167,  3167,  3168,  3168,  3169,
    3169,  3170,  3170,  3171,  3171,  3172,  3172,  3173,  3173,  3174,
    3174,  3175,  3175,  3176,  3176,  3177,  3177,  3178,  3178,  3179,
    3179,  3180,  3180,  3181,  3182,  3182,  3183,  3183,  3184,  3184,
    3185,  3185,  3186,  3186,  3187,  3187,  3188,  3188,  3189,  3193,
    3198,  3203,  3208,  3213,  3218,  3223,  3228,  3233,  3238,  3243,
    3248,  3253,  3258,  3263,  3268,  3273,  3278,  3284,  3295,  3300,
    3309,  3314,  3319,  3324,  3329,  3334,  3337,  3342,  3345,  3350,
    3355,  3360,  3365,  3370,  3375,  3380,  3385,  3390,  3401,  3406,
    3411,  3416,  3425,  3457,  3475,  3480,  3489,  3494,  3499,  3505,
    3504,  3509,  3509,  3510,  3513,  3516,  3519,  3522,  3525,  3528,
    3531,  3534,  3537,  3540,  3543,  3546,  3549,  3552,  3555,  3558,
    3561,  3564,  3570,  3569,  3574,  3574,  3575,  3578,  3581,  3584,
    3587,  3590,  3593,  3596,  3599,  3602,  3605,  3608,  3611,  3614,
    3617,  3620,  3623,  3626,  3629,  3634,  3639,  3644,  3649,  3654,
    3663,  3662,  3686,  3686,  3687,  3688,  3689,  3690,  3691,  3692,
    3693,  3695,  3701,  3708,  3707,  3712,  3712,  3713,  3717,  3723,
    3757,  3767,  3766,  3816,  3816,  3817,  3821,  3830,  3833,  3833,
    3834,  3834,  3835,  3835,  3836,  3836,  3837,  3837,  3838,  3838,
    3839,  3840,  3840,  3841,  3841,  3842,  3842,  3843,  3843,  3845,
    3850,  3855,  3860,  3865,  3870,  3875,  3880,  3885,  3890,  3895,
    3900,  3905,  3910,  3915,  3920,  3925,  3930,  3938,  3941,  3941,
    3942,  3942,  3943,  3944,  3945,  3945,  3946,  3947,  3949,  3955,
    3961,  3970,  3984,  3990,  3996
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
  "T_CALLERID", "T_CCONN", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR",
  "T_L_INFO", "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVNOTICE", "T_SERVCONN",
  "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV",
  "T_UNXLINE", "T_WALLOP", "T_GOD", "T_NICKSERVREG", "THROTTLE_TIME",
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV",
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK",
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
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
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
      59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   265,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   268,   269,   269,
     269,   269,   269,   269,   270,   270,   271,   271,   271,   271,
     272,   273,   273,   274,   274,   274,   275,   276,   277,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   292,   293,   293,   293,
     293,   294,   295,   296,   297,   298,   298,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   310,   310,   310,   310,   310,   310,   311,   313,   312,
     314,   314,   315,   315,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   318,   319,
     320,   321,   322,   323,   325,   324,   326,   326,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   343,   342,   344,   344,   346,   345,   347,   345,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   348,   350,   349,   351,   351,   352,
     352,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   369,
     368,   371,   370,   372,   372,   373,   373,   374,   374,   375,
     375,   375,   375,   375,   377,   376,   378,   378,   379,   379,
     380,   381,   383,   382,   384,   384,   385,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   386,   387,   388,   389,   390,   392,   391,
     393,   393,   395,   394,   396,   394,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   409,   408,   410,   410,
     411,   411,   411,   411,   412,   413,   414,   416,   415,   417,
     417,   418,   418,   418,   418,   419,   420,   422,   421,   423,
     423,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   426,   425,   427,   427,   428,   428,   428,   429,
     431,   430,   432,   432,   433,   433,   433,   433,   433,   433,
     433,   433,   433,   433,   433,   435,   434,   436,   436,   437,
     437,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   446,
     447,   449,   448,   450,   450,   452,   451,   453,   451,   454,
     454,   454,   454,   454,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   466,   465,   468,   467,   469,
     469,   470,   471,   471,   472,   472,   472,   472,   473,   474,
     476,   475,   477,   477,   478,   478,   478,   479,   480,   481,
     482,   482,   483,   483,   484,   486,   485,   488,   487,   489,
     489,   490,   491,   491,   492,   492,   492,   492,   493,   494,
     495,   496,   496,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   524,   525,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   547,
     546,   548,   548,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   551,   550,   552,   552,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   554,   555,   556,   557,   558,
     560,   559,   561,   561,   562,   562,   562,   562,   562,   562,
     562,   563,   564,   566,   565,   567,   567,   568,   568,   569,
     570,   572,   571,   573,   573,   574,   574,   575,   576,   576,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   597,
     598,   598,   598,   598,   598,   598,   598,   598,   599,   600,
     601,   602,   603,   604,   605
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
     629,   636,   630,   640,   644,   632,   637,   633,   638,   639,
     631,   635,   634,   641,     0,   625,   586,   603,   618,   619,
     604,   605,   606,   613,   607,   616,   620,   609,   614,   610,
     615,   608,   612,   611,   617,   621,     0,   602,   579,   582,
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
     178,   179,   152,   190,   158,   173,   174,   159,   160,   161,
     168,   162,   171,   175,   164,   169,   165,   170,   163,   167,
     166,   172,   176,     0,   157,   182,   149,   181,   348,     0,
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
#define YYPACT_NINF -818
static const yytype_int16 yypact[] =
{
    -818,   918,  -818,   -37,  -253,  -245,  -818,  -818,  -818,  -242,
    -818,  -235,  -818,  -818,  -818,  -818,  -233,  -228,  -818,  -818,
    -219,  -204,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,   255,   785,   -90,
     -88,  -185,     7,  -183,   546,  -161,  -159,  -153,  -151,   549,
       5,   -31,  -144,   313,   320,  -130,  -122,  -117,  -115,  -103,
     -96,    15,  -818,  -818,  -818,  -818,  -818,   -74,   -72,   -55,
     -50,   -48,   -32,   -20,   -18,   -16,   -14,    -8,     6,     8,
      19,    34,    36,    41,    71,   273,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,   -80,  -818,  -818,    33,
    -818,     4,  -818,    73,    32,  -818,  -818,    65,  -818,    75,
      76,    79,    80,    81,    83,    84,    86,    88,    89,    92,
      93,    95,    98,   100,   101,   104,   105,   107,   112,   113,
     115,   123,   125,   127,   129,   131,   136,   137,   140,   141,
     142,  -818,   144,  -818,   149,   154,   164,   169,   170,   171,
     172,   173,   177,   178,   180,   183,   184,   187,   188,   189,
     199,   200,   201,   210,     3,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,    58,   830,    54,   329,    90,   212,   213,   214,   215,
     218,   219,   221,   222,   225,   234,   235,   237,   397,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,   102,   238,   241,    68,  -818,  -818,  -818,  -818,
      66,  -818,     2,  -818,   242,   243,   244,   245,   246,   247,
     248,    56,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
     226,   249,   250,   251,   252,   253,   257,   258,   263,   264,
     265,   267,   155,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,    40,    53,  -818,   319,   376,
     377,   275,  -818,   337,   134,   403,   343,   344,   408,   408,
     411,   413,   352,   356,   420,   408,   360,   361,   365,   366,
     367,   304,  -818,   407,   754,  -818,   303,   305,    17,  -818,
    -818,  -818,   412,   309,  -818,  -818,   307,   308,  -818,  -818,
      44,  -818,  -818,  -818,   381,   408,   386,   408,   440,   428,
     453,   391,   392,   396,   461,   441,   399,   464,   465,   469,
     409,   408,   419,   421,   470,   449,   424,   483,   488,   408,
     489,   471,   491,   494,   432,   433,   369,   437,   374,   408,
     408,   442,   408,   485,   445,   448,   450,   122,   130,   451,
     452,   408,   408,   512,   408,   456,   458,   472,   473,   401,
    -818,  -818,  -818,   388,   404,  -818,   410,   414,    24,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,   406,   415,   416,   417,
     418,  -818,   423,   435,   443,   446,   447,   454,   457,   459,
     460,   462,   463,   290,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,   467,  -818,   468,  -818,    20,  -818,  -818,  -818,
     422,  -818,   479,   481,   486,  -818,    50,  -818,  -818,  -818,
    -818,  -818,   517,   528,   529,   541,   550,   558,   560,   563,
     272,   566,   573,   508,   474,  -818,  -818,   577,   597,   475,
    -818,   669,   496,   495,   498,   499,    59,  -818,  -818,  -818,
    -818,   569,   571,   572,   599,   575,   576,   408,   509,  -818,
    -818,   618,   578,   620,   623,   627,   629,   638,   639,   644,
     642,   646,   539,  -818,   547,   543,  -818,   548,    87,  -818,
    -818,  -818,  -818,   552,   551,  -818,    48,  -818,  -818,  -818,
     553,   555,   556,  -818,   557,   561,   562,   568,   574,   295,
     582,   583,   584,   585,   586,   587,   588,   589,   591,   593,
     594,   600,   601,  -818,   602,   608,   611,   612,   614,   615,
     619,   624,   625,   626,   628,   632,   634,   635,   148,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,   603,   637,   641,   647,   648,   649,   652,
     657,   658,   661,  -818,   664,   665,   666,   670,   671,   672,
     674,   675,   676,   211,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,   655,   668,   604,  -818,   605,  -818,
     680,   685,   679,   630,  -818,   645,   683,   686,   688,   689,
     691,   692,   695,   697,   698,   699,   700,   702,   703,   704,
     705,   707,   708,   711,   712,   713,   714,   715,   716,   717,
     718,   720,   721,   722,   725,   727,   730,   915,   731,   837,
     732,   734,   735,   737,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   748,   751,    99,   752,   753,   755,
     756,   757,   758,  -818,   682,   408,   633,   706,   859,   867,
     764,  -818,  -818,   690,   870,   696,   831,   763,   832,   833,
     834,   835,   836,   879,   693,   883,   889,   851,   896,   773,
    -818,   897,   791,   900,   797,  -818,  -818,   795,   904,   905,
     724,   801,  -818,   802,   807,   810,   811,   813,   814,   817,
     819,   820,   825,   839,   840,   841,   848,   852,   854,   855,
     862,  -818,   865,   869,  -818,   872,   829,   871,   873,   874,
    -818,   875,   876,   877,   885,   886,   888,   891,   892,   893,
     894,   895,   898,   899,  -818,   901,   902,   903,   126,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,   938,   940,   941,   907,  -818,   908,   909,
     910,   911,   912,   913,   914,  -818,   916,   917,   919,   920,
     921,   922,   923,   924,   925,   926,   927,  -818,  -818,   956,
     928,   975,   929,  -818,  -818,   978,   930,   932,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,   408,   408,   408,
     408,   408,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   768,   769,
     408,   774,   776,  1002,  1019,  1004,  1027,  1030,   408,   408,
     512,   934,  -818,  -818,  1020,   117,   982,  1033,  1035,   999,
    1000,  1001,  1043,   936,  1045,  1046,  1047,  1048,  1071,  1050,
    1051,  1011,  1053,   949,  -818,   950,   951,  -818,  -818,   952,
     953,  1054,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -250,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -241,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,   512,   512,   512,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,    21,   955,   957,    27,   958,
     959,  -818,   960,   961,   962,   963,  1084,   964,   965,   966,
     967,   968,   969,   970,   971,   972,   973,   974,  -818,   976,
    1075,   977,  -818,   -65,   979,   980,  1037,   981,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  1052,  1086,  1055,  1056,   983,  1057,  1058,  1059,  1060,
    1061,  1087,  1062,  1088,  1063,  1064,  1065,  1089,  1066,   984,
    1067,  1094,  1068,   990,  -818,  1005,  1006,  1007,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  1008,   455,  1009,
    -818,  1010,   622,  -818,  -818,  -818,  -818,  -818,  -818,  1012,
    1013,  1014,  1015,  1016,  1017,  1018,  1021,  1022,  1023,  1024,
    1025,  1026,  -818,  1028,  1029,  1031,  1032,  1034,  1036,  1038,
    1039,  1040,  1041,  1139,  1042,  1044,  1049,  1069,  1070,  1072,
    1073,  1074,  1076,  -818,  -818,  -818,  -818,  -818,  -818,  -234,
    -818,  -818,   915,  -818,   837,  -818,  -818,  -818,  -818,  -818,
    -220,  -818,  -818,  -818,  -818,  -818,  -196,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -182,  -818,   580,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -175,  -818,  -818,  -818,  -818,  -170,  -818,  -818,  -818,
    1146,   724,  1077,  1078,  1079,  1080,  1081,  1148,  1082,  1083,
    1085,  1090,  1091,  1092,  1093,  1095,  1096,  1097,  1098,  1099,
    1100,   878,  1101,  1102,  1103,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -158,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -134,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -107,  -818,   223,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  1054,  -818,  -818,  -818,    21,
    -818,    27,   580,  -818,  1084,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  1075,  -818,   -65,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   -91,  -818,
     709,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,   -81,  -818,  -818,  -818,  -818,  -818,   455,
    -818,   622,   223,  -818,  1139,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   709,
    -818,  1148,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
     878,  -818,  -818,  -818,  -818,  -818,  -818,  -818
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -818,  -818,  -818,  -465,  -338,  -817,  -421,  -818,  -818,  1104,
    -818,  -818,  -818,  -818,   985,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  1216,  -818,
    -818,  -818,  -818,  -818,  1106,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,   477,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -180,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -148,  -818,  -818,  -156,  -818,  -818,  -818,  -818,   710,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   -73,  -818,
     809,  -818,  -818,  -818,    46,  -818,  -818,  -818,  -818,  -818,
     845,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,   -54,
    -818,  -818,   -51,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,   786,  -818,  -818,  -818,
    -818,  -818,  -818,   759,  -818,  -818,  -818,  -818,  -818,  -116,
    -818,  -818,  -818,   749,  -818,  -818,  -818,  -818,  -112,  -818,
    -818,  -818,  -818,   673,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -120,  -818,  -818,  -111,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,   -57,  -818,   838,  -818,  -818,
    -818,  -818,  -818,   986,  -818,  -818,  -818,  -818,  1198,  -818,
    -818,  -818,  -818,  -818,  -818,   -30,  -818,   995,  -818,  -818,
    -818,  -818,  1142,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,   109,  -818,  -818,  -818,   116,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,   931,  -818,  -818,
    -818,  -818,  -818,   -34,  -818,  -818,  -818,  -818,  -818,   -28,
    -818,  -818,  1240,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,  -818,
    -818,  -818,  -818,  1105,  -818,  -818,  -818,  -818,  -818,  -818,
    -818
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     580,   581,   727,   522,   128,   355,   272,   587,   122,    47,
    1211,   129,   130,  1254,  1212,   131,    67,    48,   355,  1213,
      52,   481,   132,  1214,   523,   431,  1354,    54,   432,    59,
    1355,   133,  1218,   122,    60,   134,   135,   676,  1224,   678,
    1358,   554,   136,    63,  1359,   365,   137,   138,   139,   563,
     140,   490,    68,   692,   563,   481,   141,   283,    64,   431,
     522,   700,   432,    69,  1360,   115,   365,   118,  1361,   272,
     433,   710,   711,   434,   713,   142,   143,   121,  1363,   127,
     144,   523,  1364,   724,   725,  1376,   728,   145,   554,  1377,
    1378,   146,   147,   148,  1379,   356,   149,   284,   123,   150,
     151,   241,  1428,   242,   433,   491,  1429,   434,   356,   243,
     152,   244,   285,  1044,  1045,  1046,   153,   154,   282,   155,
     156,   157,   158,   123,   279,   273,  1430,   795,   524,   435,
    1431,   796,   325,   159,   286,   492,   287,    70,   288,   289,
     326,   493,   160,   327,   161,   162,   436,   163,   328,   594,
     164,   165,   797,  1433,   166,   274,   300,  1434,   290,   525,
     329,   357,   555,   435,   798,   167,   366,   330,  1255,  1450,
     564,   595,   596,  1451,   357,   564,   799,   482,   597,  1469,
     436,   800,   353,  1470,   168,   524,   169,   366,   273,   333,
     170,   334,   301,   801,   171,   172,   173,   174,   175,   854,
     802,   367,   176,   177,   494,   803,   483,   804,   335,   555,
     178,   482,   623,   336,   624,   337,   525,   625,   274,  1219,
     805,   626,   367,    45,    46,  1225,   556,  1215,  1216,  1217,
     368,   338,   726,  1435,   565,  1436,   627,   628,   629,   565,
     483,   302,   630,   339,   179,   340,   180,   341,   806,   342,
    1437,   368,   181,   807,  1438,   343,    67,   182,   598,   599,
     600,   631,   183,   601,   429,   632,   633,   575,   484,   344,
     602,   345,   437,   556,    76,   808,   331,   303,   666,   304,
     305,   764,   346,   603,   604,   740,    77,   809,   557,   810,
     811,   446,    68,   363,   812,   354,   634,   347,   635,   348,
     605,   606,   484,    69,   349,   673,   437,    78,    79,   877,
     447,   771,   636,    80,   283,    81,   448,   538,   718,   719,
     846,   300,   306,  1439,   307,   607,   720,   721,   521,   519,
     490,  1184,  1185,   637,   350,   557,   362,   308,   374,   375,
     449,   450,   376,   377,   378,   451,   379,   380,   872,   381,
     501,   382,   383,   813,   284,   384,   385,   301,   386,   452,
     814,   387,   516,   388,   389,   638,   453,   390,   391,   285,
     392,    82,    83,   815,   816,   393,   394,    70,   395,   639,
     309,    84,    85,   817,   491,   454,   396,  1133,   397,   640,
     398,   286,   399,   287,   400,   288,   289,  1056,   245,   401,
     402,    86,    87,   403,   404,   405,   302,   407,   594,   921,
     310,   311,   409,   455,   492,   290,   552,   410,    88,    89,
     493,   456,  1164,  1165,  1166,  1167,  1168,   411,   579,    90,
     595,   596,   412,   413,   414,   415,   416,   597,    91,   457,
     417,   418,   303,   419,   304,   305,   420,   421,   458,   459,
     422,   423,   424,   641,   246,   247,   248,   249,   250,   251,
     252,   253,   425,   426,   427,  1440,   642,   887,   888,   889,
     890,   891,   943,   428,   570,   502,   503,   504,   505,   460,
     461,   506,   507,   494,   508,   509,   540,   306,   510,   307,
     781,   782,   783,   784,   785,   786,   787,   511,   512,  1181,
     513,   517,   308,   254,   518,   531,   532,   533,   534,   535,
     536,   537,   541,   542,   543,   544,   545,   598,   599,   600,
     546,   547,   601,    92,    93,    94,   548,   549,   550,   602,
     551,   571,   572,   574,   351,   573,   576,   255,   462,   577,
     578,   579,   603,   604,   582,   309,   583,   128,   584,  1290,
     245,   759,   585,   586,   129,   130,   588,   589,   131,   605,
     606,   590,   591,   592,   593,   132,   664,   668,   665,   669,
     670,   671,  1171,   679,   133,   310,   311,   675,   134,   135,
    1179,  1180,   677,   680,   607,   136,   681,   682,   683,   137,
     138,   139,   684,   140,   685,   687,   686,   688,   689,   141,
    1365,  1366,   690,   695,   696,   691,   246,   247,   248,   249,
     250,   251,   252,   253,   256,   693,   698,   694,   142,   143,
     697,   699,   701,   144,   703,  1291,   702,   704,   705,   706,
     145,  1367,   707,   708,   146,   147,   148,   709,   712,   149,
     714,   715,   150,   151,   716,   726,   717,   722,   723,  1368,
     257,   735,   729,   152,   730,   254,  1369,  1292,   514,   153,
     154,   733,   155,   156,   157,   158,   742,   736,   731,   732,
     795,  1293,   773,   738,   796,  1370,   159,   739,   743,   744,
     745,   746,   766,   774,   775,   160,   748,   161,   162,   255,
     163,  1294,  1295,   164,   165,   797,   776,   166,   749,  1296,
    1297,  1298,  1299,  1371,   790,   777,   750,   798,   167,   751,
     752,  1372,  1300,   778,  1452,   779,  1305,   753,   780,   799,
     754,   788,   755,   756,   800,   757,   758,   168,   789,   169,
     761,   763,   792,   170,   791,   794,   801,   171,   172,   173,
     174,   175,   768,   802,   769,   176,   177,  1453,   803,   770,
     804,  1373,   793,   178,   851,   623,   842,   624,   843,  1454,
     625,   844,   845,   805,   626,   848,   256,   849,   850,   855,
    1374,   852,   853,   856,   857,   858,  1455,   864,   859,   627,
     628,   629,   860,  1456,   861,   630,    76,   179,  1457,   180,
    1458,   806,  1306,   862,   863,   181,   807,   865,    77,   867,
     182,   866,   257,  1459,   631,   183,   869,   868,   632,   633,
     945,   871,   874,   879,   875,   880,   881,   882,   808,    78,
      79,   883,   884,   946,  1307,    80,  1073,    81,   885,  1057,
     809,   446,   810,   811,   886,   949,  1460,   812,  1308,   634,
     950,   635,   894,   895,   896,   897,   898,   899,   900,   901,
     447,   902,  1461,   903,   904,   636,   448,  1086,  1309,  1310,
     905,   906,   907,   923,   947,   948,  1311,  1312,  1313,  1314,
    1462,   908,  1463,  1464,   909,   910,   637,   911,   912,  1315,
     449,   450,   913,    82,    83,   451,  1062,   914,   915,   916,
     952,   917,  1064,    84,    85,   918,   813,   919,   920,   452,
     924,  1169,  1170,   814,   925,   953,   453,  1172,   638,  1173,
     926,   927,   928,    86,    87,   929,   815,   816,     2,     3,
     930,   931,   639,     4,   932,   454,   817,   934,   935,   936,
      88,    89,   640,   937,   938,   939,  1465,   940,   941,   942,
       5,    90,   951,   954,     6,  1055,   955,     7,   956,   957,
      91,   958,   959,   455,     8,   960,  1466,   961,   962,   963,
     964,   456,   965,   966,   967,   968,  1467,   969,   970,  1058,
       9,   971,   972,   973,   974,   975,   976,   977,   978,   457,
     979,   980,   981,    10,    11,   982,    12,   983,   458,   459,
     984,  1006,  1028,    13,  1029,  1030,   641,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,   642,
      14,  1043,  1049,  1050,  1059,  1051,  1052,  1053,  1054,   460,
     461,    15,  1060,    16,  1061,  1063,  1066,  1065,  1067,  1068,
    1069,  1070,  1071,  1078,  1072,    92,    93,    94,  1074,    17,
    1007,  1008,  1009,  1010,  1075,  1011,  1012,  1076,  1013,  1014,
    1015,  1077,  1079,  1016,  1080,  1081,    18,  1082,  1083,  1084,
    1085,  1089,  1090,  1017,  1018,  1019,  1020,  1091,  1021,  1022,
    1092,  1093,  1023,  1094,  1095,  1024,  1025,  1096,   462,  1097,
    1098,  1404,  1405,  1406,  1407,  1099,  1408,  1409,    19,  1410,
    1411,  1412,  1111,  1135,  1413,  1136,  1137,    20,    21,  1100,
    1101,  1102,    22,    23,  1414,  1415,  1416,  1417,  1103,  1418,
    1419,  1157,  1104,  1420,  1105,  1106,  1421,  1422,   985,   986,
     987,   988,  1107,   989,   990,  1108,   991,   992,   993,  1109,
    1159,   994,  1110,  1161,  1112,  1174,  1113,  1114,  1116,  1117,
    1118,   995,   996,   997,   998,   999,  1000,  1001,  1119,  1120,
    1002,  1121,  1175,  1003,  1122,  1123,  1124,  1125,  1126,  1176,
    1177,  1127,  1128,  1178,  1130,  1131,  1132,  1138,  1139,  1140,
    1141,  1142,  1143,  1144,  1145,  1183,  1146,  1147,  1186,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1187,  1160,
    1188,  1158,  1163,  1162,  1182,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1222,  1234,  1223,  1228,  1229,
    1230,  1231,  1232,  1233,  1238,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,  1248,  1250,  1249,  1253,  1260,  1258,
    1259,  1264,  1273,  1275,  1279,  1261,  1267,  1281,  1263,  1283,
    1285,  1265,  1266,  1268,  1269,  1270,  1271,  1272,  1274,  1276,
    1277,  1278,  1280,  1282,  1284,  1286,  1287,  1288,  1289,  1303,
    1304,  1341,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1380,
    1387,  1325,  1326,  1327,  1328,  1329,  1330,   332,  1331,  1332,
    1477,  1333,  1334,  1475,  1335,  1134,  1336,   553,  1337,  1338,
    1339,  1340,  1345,  1476,  1346,   772,  1448,  1381,   760,  1347,
    1446,  1445,   847,  1471,  1474,   878,   944,   873,   922,  1472,
    1447,  1473,   364,  1357,   765,  1442,   430,  1444,  1356,  1348,
    1349,  1443,  1350,  1351,  1352,   352,  1353,  1382,  1383,  1384,
    1385,  1386,  1391,  1392,   667,  1393,     0,     0,     0,     0,
    1394,  1395,  1396,  1397,     0,  1398,  1399,  1400,  1401,  1402,
    1403,  1425,  1426,  1427,   515,   674,     0,     0,     0,   741,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   539
};

static const yytype_int16 yycheck[] =
{
     338,   339,   423,     1,     1,     1,     1,   345,     1,   262,
     260,     8,     9,    78,   264,    12,     1,   262,     1,   260,
     262,     1,    19,   264,    22,     1,   260,   262,     4,   262,
     264,    28,    11,     1,   262,    32,    33,   375,    11,   377,
     260,     1,    39,   262,   264,     1,    43,    44,    45,     1,
      47,     1,    37,   391,     1,     1,    53,     1,   262,     1,
       1,   399,     4,    48,   260,   155,     1,   155,   264,     1,
      46,   409,   410,    49,   412,    72,    73,   262,   260,   262,
      77,    22,   264,   421,   422,   260,   424,    84,     1,   264,
     260,    88,    89,    90,   264,    91,    93,    41,    91,    96,
      97,   262,   260,   262,    46,    55,   264,    49,    91,   262,
     107,   262,    56,    14,    15,    16,   113,   114,   262,   116,
     117,   118,   119,    91,   155,   120,   260,     1,   126,   105,
     264,     5,   262,   130,    78,    85,    80,   122,    82,    83,
     262,    91,   139,   260,   141,   142,   122,   144,   263,     1,
     147,   148,    26,   260,   151,   150,     1,   264,   102,   157,
     263,   157,   122,   105,    38,   162,   122,   263,   233,   260,
     122,    23,    24,   264,   157,   122,    50,   157,    30,   260,
     122,    55,   262,   264,   181,   126,   183,   122,   120,   263,
     187,   263,    37,    67,   191,   192,   193,   194,   195,   537,
      74,   157,   199,   200,   154,    79,   186,    81,   263,   122,
     207,   157,     1,   263,     3,   263,   157,     6,   150,   198,
      94,    10,   157,   260,   261,   198,   186,  1044,  1045,  1046,
     186,   263,   133,    10,   186,    12,    25,    26,    27,   186,
     186,    86,    31,   263,   241,   263,   243,   263,   122,   263,
      27,   186,   249,   127,    31,   263,     1,   254,   110,   111,
     112,    50,   259,   115,   261,    54,    55,   133,   248,   263,
     122,   263,   248,   186,     1,   149,   261,   122,   261,   124,
     125,   261,   263,   135,   136,   261,    13,   161,   248,   163,
     164,     1,    37,   261,   168,   262,    85,   263,    87,   263,
     152,   153,   248,    48,   263,   261,   248,    34,    35,   261,
      20,   261,   101,    40,     1,    42,    26,   261,   196,   197,
     261,     1,   167,   100,   169,   177,   196,   197,   262,   261,
       1,   214,   215,   122,   263,   248,   263,   182,   263,   263,
      50,    51,   263,   263,   263,    55,   263,   263,   261,   263,
     260,   263,   263,   227,    41,   263,   263,    37,   263,    69,
     234,   263,   260,   263,   263,   154,    76,   263,   263,    56,
     263,    98,    99,   247,   248,   263,   263,   122,   263,   168,
     225,   108,   109,   257,    55,    95,   263,   261,   263,   178,
     263,    78,   263,    80,   263,    82,    83,   735,     1,   263,
     263,   128,   129,   263,   263,   263,    86,   263,     1,   261,
     255,   256,   263,   123,    85,   102,   261,   263,   145,   146,
      91,   131,   887,   888,   889,   890,   891,   263,   133,   156,
      23,    24,   263,   263,   263,   263,   263,    30,   165,   149,
     263,   263,   122,   263,   124,   125,   263,   263,   158,   159,
     263,   263,   263,   242,    57,    58,    59,    60,    61,    62,
      63,    64,   263,   263,   263,   242,   255,   172,   173,   174,
     175,   176,   261,   263,   155,   263,   263,   263,   263,   189,
     190,   263,   263,   154,   263,   263,   260,   167,   263,   169,
     218,   219,   220,   221,   222,   223,   224,   263,   263,   920,
     263,   263,   182,   106,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   110,   111,   112,
     263,   263,   115,   250,   251,   252,   263,   263,   263,   122,
     263,   155,   155,   196,   261,   260,   133,   140,   248,   196,
     196,   133,   135,   136,   133,   225,   133,     1,   196,    94,
       1,   261,   196,   133,     8,     9,   196,   196,    12,   152,
     153,   196,   196,   196,   260,    19,   263,   155,   263,   260,
     263,   263,   910,   133,    28,   255,   256,   196,    32,    33,
     918,   919,   196,   155,   177,    39,   133,   196,   196,    43,
      44,    45,   196,    47,   133,   196,   155,   133,   133,    53,
      20,    21,   133,   133,   155,   196,    57,    58,    59,    60,
      61,    62,    63,    64,   217,   196,   133,   196,    72,    73,
     196,   133,   133,    77,   133,   170,   155,   133,   196,   196,
      84,    51,   263,   196,    88,    89,    90,   263,   196,    93,
     155,   196,    96,    97,   196,   133,   196,   196,   196,    69,
     253,   263,   196,   107,   196,   106,    76,   202,   261,   113,
     114,   260,   116,   117,   118,   119,   260,   263,   196,   196,
       1,   216,   155,   263,     5,    95,   130,   263,   263,   263,
     263,   263,   260,   155,   155,   139,   263,   141,   142,   140,
     144,   236,   237,   147,   148,    26,   155,   151,   263,   244,
     245,   246,   247,   123,   196,   155,   263,    38,   162,   263,
     263,   131,   257,   155,     5,   155,    94,   263,   155,    50,
     263,   155,   263,   263,    55,   263,   263,   181,   155,   183,
     263,   263,   155,   187,   260,   260,    67,   191,   192,   193,
     194,   195,   263,    74,   263,   199,   200,    38,    79,   263,
      81,   171,   155,   207,   155,     1,   260,     3,   263,    50,
       6,   263,   263,    94,    10,   196,   217,   196,   196,   260,
     190,   196,   196,   155,   196,   155,    67,   133,   155,    25,
      26,    27,   155,    74,   155,    31,     1,   241,    79,   243,
      81,   122,   170,   155,   155,   249,   127,   155,    13,   260,
     254,   155,   253,    94,    50,   259,   263,   260,    54,    55,
     155,   263,   260,   260,   263,   260,   260,   260,   149,    34,
      35,   260,   260,   155,   202,    40,   133,    42,   260,   196,
     161,     1,   163,   164,   260,   155,   127,   168,   216,    85,
     155,    87,   260,   260,   260,   260,   260,   260,   260,   260,
      20,   260,   143,   260,   260,   101,    26,   133,   236,   237,
     260,   260,   260,   260,   260,   260,   244,   245,   246,   247,
     161,   263,   163,   164,   263,   263,   122,   263,   263,   257,
      50,    51,   263,    98,    99,    55,   196,   263,   263,   263,
     260,   263,   196,   108,   109,   263,   227,   263,   263,    69,
     263,   133,   133,   234,   263,   260,    76,   133,   154,   133,
     263,   263,   263,   128,   129,   263,   247,   248,     0,     1,
     263,   263,   168,     5,   263,    95,   257,   263,   263,   263,
     145,   146,   178,   263,   263,   263,   227,   263,   263,   263,
      22,   156,   263,   260,    26,   263,   260,    29,   260,   260,
     165,   260,   260,   123,    36,   260,   247,   260,   260,   260,
     260,   131,   260,   260,   260,   260,   257,   260,   260,   263,
      52,   260,   260,   260,   260,   260,   260,   260,   260,   149,
     260,   260,   260,    65,    66,   260,    68,   260,   158,   159,
     260,   260,   260,    75,   260,   260,   242,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   255,
      92,   260,   260,   260,   155,   260,   260,   260,   260,   189,
     190,   103,   155,   105,   260,   155,   263,   196,   196,   196,
     196,   196,   196,   260,   155,   250,   251,   252,   155,   121,
     203,   204,   205,   206,   155,   208,   209,   196,   211,   212,
     213,   155,   155,   216,   263,   155,   138,   260,   263,   155,
     155,   260,   260,   226,   227,   228,   229,   260,   231,   232,
     260,   260,   235,   260,   260,   238,   239,   260,   248,   260,
     260,   203,   204,   205,   206,   260,   208,   209,   170,   211,
     212,   213,   263,   155,   216,   155,   155,   179,   180,   260,
     260,   260,   184,   185,   226,   227,   228,   229,   260,   231,
     232,   155,   260,   235,   260,   260,   238,   239,   203,   204,
     205,   206,   260,   208,   209,   260,   211,   212,   213,   260,
     155,   216,   260,   155,   263,   133,   263,   263,   263,   263,
     263,   226,   227,   228,   229,   230,   231,   232,   263,   263,
     235,   263,   133,   238,   263,   263,   263,   263,   263,   155,
     133,   263,   263,   133,   263,   263,   263,   260,   260,   260,
     260,   260,   260,   260,   260,   155,   260,   260,   196,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   155,   260,
     155,   263,   260,   263,   260,   196,   196,   196,   155,   263,
     155,   155,   155,   155,   133,   155,   155,   196,   155,   260,
     260,   260,   260,   260,   160,   260,   132,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   160,   260,   260,   201,   260,
     260,   155,   155,   155,   155,   264,   263,   263,   196,   155,
     260,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   260,   260,   260,   260,   260,
     260,   132,   260,   260,   260,   260,   260,   260,   260,   133,
     132,   260,   260,   260,   260,   260,   260,    71,   260,   260,
    1470,   260,   260,  1449,   260,   818,   260,   312,   260,   260,
     260,   260,   260,  1451,   260,   496,  1379,  1261,   463,   260,
    1364,  1362,   526,  1429,  1434,   566,   643,   558,   608,  1431,
    1377,  1432,   124,  1214,   486,  1355,   184,  1361,  1212,   260,
     260,  1359,   260,   260,   260,    95,   260,   260,   260,   260,
     260,   260,   260,   260,   358,   260,    -1,    -1,    -1,    -1,
     260,   260,   260,   260,    -1,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   258,   370,    -1,    -1,    -1,   438,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   266,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   103,   105,   121,   138,   170,
     179,   180,   184,   185,   267,   272,   277,   291,   297,   312,
     349,   368,   382,   408,   415,   425,   434,   465,   475,   481,
     485,   495,   559,   575,   596,   260,   261,   262,   262,   350,
     435,   476,   262,   486,   262,   560,   383,   466,   369,   262,
     262,   313,   409,   262,   262,   416,   426,     1,    37,    48,
     122,   292,   293,   294,   295,   296,     1,    13,    34,    35,
      40,    42,    98,    99,   108,   109,   128,   129,   145,   146,
     156,   165,   250,   251,   252,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   155,   351,   355,   155,   436,
     440,   262,     1,    91,   482,   483,   484,   262,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   107,   113,   114,   116,   117,   118,   119,   130,
     139,   141,   142,   144,   147,   148,   151,   162,   181,   183,
     187,   191,   192,   193,   194,   195,   199,   200,   207,   241,
     243,   249,   254,   259,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   550,   554,   555,   556,   557,
     558,   262,   262,   262,   262,     1,    57,    58,    59,    60,
      61,    62,    63,    64,   106,   140,   217,   253,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,     1,   120,   150,   273,   274,   275,   276,   155,
     314,   318,   262,     1,    41,    56,    78,    80,    82,    83,
     102,   597,   598,   599,   600,   601,   602,   603,   604,   605,
       1,    37,    86,   122,   124,   125,   167,   169,   182,   225,
     255,   256,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   262,   262,   260,   263,   263,
     263,   261,   293,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   261,   577,   262,   262,     1,    91,   157,   477,   478,
     479,   480,   263,   261,   483,     1,   122,   157,   186,   487,
     491,   492,   493,   494,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   551,   263,   547,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   261,
     497,     1,     4,    46,    49,   105,   122,   248,   561,   562,
     563,   564,   565,   569,   570,   571,     1,    20,    26,    50,
      51,    55,    69,    76,    95,   123,   131,   149,   158,   159,
     189,   190,   248,   384,   385,   386,   387,   388,   389,   390,
     391,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,     1,   157,   186,   248,   467,   471,   472,   473,   474,
       1,    55,    85,    91,   154,   370,   374,   375,   376,   380,
     381,   260,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   261,   299,   260,   263,   263,   261,
     274,   262,     1,    22,   126,   157,   410,   411,   412,   413,
     414,   263,   263,   263,   263,   263,   263,   263,   261,   598,
     260,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   261,   279,     1,   122,   186,   248,   417,   418,
     419,   420,   421,     1,   122,   186,   427,   428,   429,   430,
     155,   155,   155,   260,   196,   133,   133,   196,   196,   133,
     269,   269,   133,   133,   196,   196,   133,   269,   196,   196,
     196,   196,   196,   260,     1,    23,    24,    30,   110,   111,
     112,   115,   122,   135,   136,   152,   153,   177,   352,   353,
     354,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,     1,     3,     6,    10,    25,    26,    27,
      31,    50,    54,    55,    85,    87,   101,   122,   154,   168,
     178,   242,   255,   437,   438,   439,   441,   442,   443,   444,
     445,   446,   447,   448,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   263,   263,   261,   478,   155,   260,
     263,   263,   488,   261,   492,   196,   269,   196,   269,   133,
     155,   133,   196,   196,   196,   133,   155,   196,   133,   133,
     133,   196,   269,   196,   196,   133,   155,   196,   133,   133,
     269,   133,   155,   133,   133,   196,   196,   263,   196,   263,
     269,   269,   196,   269,   155,   196,   196,   196,   196,   197,
     196,   197,   196,   196,   269,   269,   133,   271,   269,   196,
     196,   196,   196,   260,   572,   263,   263,   566,   263,   263,
     261,   562,   260,   263,   263,   263,   263,   392,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   261,
     385,   263,   468,   263,   261,   472,   260,   371,   263,   263,
     263,   261,   375,   155,   155,   155,   155,   155,   155,   155,
     155,   218,   219,   220,   221,   222,   223,   224,   155,   155,
     196,   260,   155,   155,   260,     1,     5,    26,    38,    50,
      55,    67,    74,    79,    81,    94,   122,   127,   149,   161,
     163,   164,   168,   227,   234,   247,   248,   257,   315,   316,
     317,   319,   320,   321,   322,   323,   324,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   260,   263,   263,   263,   261,   411,   196,   196,
     196,   155,   196,   196,   269,   260,   155,   196,   155,   155,
     155,   155,   155,   155,   133,   155,   155,   260,   260,   263,
     422,   263,   261,   418,   260,   263,   431,   261,   428,   260,
     260,   260,   260,   260,   260,   260,   260,   172,   173,   174,
     175,   176,   268,   269,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   261,   353,   260,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   449,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   261,   438,   155,   155,   260,   260,   155,
     155,   263,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   203,   204,   205,   206,   208,
     209,   211,   212,   213,   216,   226,   227,   228,   229,   230,
     231,   232,   235,   238,   552,   553,   260,   203,   204,   205,
     206,   208,   209,   211,   212,   213,   216,   226,   227,   228,
     229,   231,   232,   235,   238,   239,   548,   549,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,    14,    15,    16,   270,   271,   260,
     260,   260,   260,   260,   260,   263,   269,   196,   263,   155,
     155,   260,   196,   155,   196,   196,   263,   196,   196,   196,
     196,   196,   155,   133,   155,   155,   196,   155,   260,   155,
     263,   155,   260,   263,   155,   155,   133,   378,   379,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   263,   263,   263,   263,   343,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   325,
     263,   263,   263,   261,   316,   155,   155,   155,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   155,   263,   155,
     260,   155,   263,   260,   268,   268,   268,   268,   268,   133,
     133,   269,   133,   133,   133,   133,   155,   133,   133,   269,
     269,   271,   260,   155,   214,   215,   196,   155,   155,   196,
     196,   196,   155,   263,   155,   155,   155,   155,   133,   155,
     155,   196,   155,   260,   260,   260,   260,   260,   160,   489,
     490,   260,   264,   260,   264,   270,   270,   270,    11,   198,
     573,   574,   260,   260,    11,   198,   567,   568,   260,   260,
     260,   260,   260,   260,   132,   393,   394,   396,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     160,   469,   470,   260,    78,   233,   372,   373,   260,   260,
     201,   264,   377,   196,   155,   196,   196,   263,   196,   196,
     196,   196,   196,   155,   196,   155,   196,   196,   196,   155,
     196,   263,   196,   155,   196,   260,   260,   260,   260,   260,
      94,   170,   202,   216,   236,   237,   244,   245,   246,   247,
     257,   423,   424,   260,   260,    94,   170,   202,   216,   236,
     237,   244,   245,   246,   247,   257,   432,   433,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   132,   450,   451,   453,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   264,   553,   549,   260,   264,
     260,   264,   395,   260,   264,    20,    21,    51,    69,    76,
      95,   123,   131,   171,   190,   397,   260,   264,   260,   264,
     133,   379,   260,   260,   260,   260,   260,   132,   344,   345,
     347,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   203,   204,   205,   206,   208,   209,
     211,   212,   213,   216,   226,   227,   228,   229,   231,   232,
     235,   238,   239,   326,   327,   260,   260,   260,   260,   264,
     260,   264,   452,   260,   264,    10,    12,    27,    31,   100,
     242,   454,   490,   574,   568,   397,   394,   470,   373,   346,
     260,   264,     5,    38,    50,    67,    74,    79,    81,    94,
     127,   143,   161,   163,   164,   227,   247,   257,   348,   260,
     264,   424,   433,   454,   451,   348,   345,   327
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
#line 426 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 428 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
#line 432 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
#line 436 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
#line 440 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
#line 444 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
#line 448 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
#line 453 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
#line 457 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
#line 471 "ircd_parser.y"
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
#line 488 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 512 "ircd_parser.y"
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
#line 546 "ircd_parser.y"
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
#line 606 "ircd_parser.y"
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
#line 620 "ircd_parser.y"
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
#line 635 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 644 "ircd_parser.y"
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
#line 658 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 667 "ircd_parser.y"
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
#line 695 "ircd_parser.y"
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
#line 725 "ircd_parser.y"
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
#line 748 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
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
          sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
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
#line 804 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 813 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 822 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 849 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 853 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 857 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 864 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 871 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 878 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 885 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 892 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 899 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 906 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 913 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 917 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 921 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 925 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 929 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 933 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 937 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 943 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 952 "ircd_parser.y"
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
#line 965 "ircd_parser.y"
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
#line 1057 "ircd_parser.y"
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
#line 1069 "ircd_parser.y"
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
#line 1081 "ircd_parser.y"
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
#line 1115 "ircd_parser.y"
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
#line 1127 "ircd_parser.y"
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
#line 1138 "ircd_parser.y"
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
#line 1180 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1189 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1196 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1200 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1204 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1208 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1212 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1216 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1220 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1224 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1228 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1232 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1236 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1240 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1244 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1248 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1252 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1256 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1260 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1264 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1268 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_GOD;
}
    break;

  case 177:
#line 1274 "ircd_parser.y"
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
#line 1285 "ircd_parser.y"
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
#line 1296 "ircd_parser.y"
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
#line 1307 "ircd_parser.y"
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
#line 1318 "ircd_parser.y"
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
#line 1329 "ircd_parser.y"
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
#line 1340 "ircd_parser.y"
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
#line 1351 "ircd_parser.y"
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
#line 1362 "ircd_parser.y"
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
#line 1373 "ircd_parser.y"
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
#line 1384 "ircd_parser.y"
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
#line 1395 "ircd_parser.y"
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
#line 1406 "ircd_parser.y"
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
#line 1417 "ircd_parser.y"
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
#line 1428 "ircd_parser.y"
    {
}
    break;

  case 195:
#line 1432 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 197:
#line 1433 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 199:
#line 1436 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 200:
#line 1443 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 201:
#line 1450 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 202:
#line 1457 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 203:
#line 1464 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 204:
#line 1471 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 205:
#line 1478 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 206:
#line 1485 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 207:
#line 1492 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 208:
#line 1499 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 209:
#line 1506 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 210:
#line 1513 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 211:
#line 1520 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 212:
#line 1527 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 213:
#line 1534 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 214:
#line 1541 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 215:
#line 1554 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 216:
#line 1561 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
    {
      delete_conf_item(yy_conf);
    }
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        rebuild_cidr_class(cconf, yy_class);
        class = (struct ClassItem *) map_to_conf(cconf);
        *class = *yy_class;
        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
      }
    }
    yy_class_name = NULL;
  }
}
    break;

  case 235:
#line 1613 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1622 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 237:
#line 1631 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
#line 1637 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
#line 1643 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
#line 1649 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
#line 1655 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
#line 1661 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
#line 1667 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
#line 1673 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
#line 1679 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
#line 1685 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
#line 1691 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
#line 1697 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
#line 1706 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 250:
#line 1713 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 251:
#line 1722 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 255:
#line 1728 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 256:
#line 1732 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 264:
#line 1740 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 268:
#line 1745 "ircd_parser.y"
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
#line 1759 "ircd_parser.y"
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
#line 1779 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 271:
#line 1788 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 272:
#line 1800 "ircd_parser.y"
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
#line 1812 "ircd_parser.y"
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
#line 1877 "ircd_parser.y"
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
#line 1914 "ircd_parser.y"
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
#line 1927 "ircd_parser.y"
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
#line 1938 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 297:
#line 1947 "ircd_parser.y"
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
#line 1958 "ircd_parser.y"
    {
}
    break;

  case 302:
#line 1962 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 304:
#line 1963 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 306:
#line 1966 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 307:
#line 1974 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 308:
#line 1981 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 309:
#line 1988 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 310:
#line 1995 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 311:
#line 2002 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 312:
#line 2009 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 313:
#line 2016 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 314:
#line 2023 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 315:
#line 2030 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 316:
#line 2039 "ircd_parser.y"
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
#line 2050 "ircd_parser.y"
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
#line 2061 "ircd_parser.y"
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
#line 2072 "ircd_parser.y"
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
#line 2083 "ircd_parser.y"
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
#line 2094 "ircd_parser.y"
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
#line 2106 "ircd_parser.y"
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
#line 2125 "ircd_parser.y"
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
#line 2135 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 325:
#line 2144 "ircd_parser.y"
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
#line 2159 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 327:
#line 2166 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 334:
#line 2178 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 335:
#line 2187 "ircd_parser.y"
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
#line 2202 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 337:
#line 2215 "ircd_parser.y"
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
#line 2223 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 345:
#line 2234 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 346:
#line 2243 "ircd_parser.y"
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
#line 2265 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 351:
#line 2272 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 352:
#line 2276 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 353:
#line 2280 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 354:
#line 2284 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 355:
#line 2288 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 356:
#line 2292 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 357:
#line 2296 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 358:
#line 2300 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 359:
#line 2304 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 360:
#line 2308 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 361:
#line 2312 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 362:
#line 2321 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 363:
#line 2328 "ircd_parser.y"
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
#line 2341 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 370:
#line 2347 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 374:
#line 2354 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 375:
#line 2358 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 376:
#line 2362 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 377:
#line 2366 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 378:
#line 2370 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 379:
#line 2374 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 380:
#line 2378 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 381:
#line 2382 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 382:
#line 2386 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 383:
#line 2390 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 384:
#line 2394 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 385:
#line 2403 "ircd_parser.y"
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
#line 2421 "ircd_parser.y"
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
#line 2560 "ircd_parser.y"
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
#line 2572 "ircd_parser.y"
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
#line 2584 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 414:
#line 2593 "ircd_parser.y"
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
#line 2619 "ircd_parser.y"
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
#line 2637 "ircd_parser.y"
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
#line 2655 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 418:
#line 2661 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 419:
#line 2665 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 420:
#line 2673 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 421:
#line 2682 "ircd_parser.y"
    {
}
    break;

  case 425:
#line 2686 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 427:
#line 2687 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 429:
#line 2690 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 430:
#line 2697 "ircd_parser.y"
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
#line 2708 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 432:
#line 2715 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 433:
#line 2722 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 434:
#line 2729 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 435:
#line 2739 "ircd_parser.y"
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
#line 2780 "ircd_parser.y"
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
#line 2791 "ircd_parser.y"
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
#line 2802 "ircd_parser.y"
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
#line 2817 "ircd_parser.y"
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
#line 2828 "ircd_parser.y"
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
#line 2839 "ircd_parser.y"
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
#line 2852 "ircd_parser.y"
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
#line 2865 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 444:
#line 2874 "ircd_parser.y"
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
#line 2909 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 446:
#line 2916 "ircd_parser.y"
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
#line 2973 "ircd_parser.y"
    {
}
    break;

  case 451:
#line 2978 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 458:
#line 2987 "ircd_parser.y"
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
#line 3006 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 460:
#line 3015 "ircd_parser.y"
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
#line 3024 "ircd_parser.y"
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
#line 3040 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 468:
#line 3049 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 474:
#line 3066 "ircd_parser.y"
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
#line 3087 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 476:
#line 3094 "ircd_parser.y"
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
#line 3129 "ircd_parser.y"
    {
}
    break;

  case 481:
#line 3134 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 488:
#line 3143 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 489:
#line 3149 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 549:
#line 3194 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 550:
#line 3199 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 551:
#line 3204 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 552:
#line 3209 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 553:
#line 3214 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 554:
#line 3219 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 555:
#line 3224 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 556:
#line 3229 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 557:
#line 3234 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 558:
#line 3239 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 559:
#line 3244 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 560:
#line 3249 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 561:
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 562:
#line 3259 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 563:
#line 3264 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 564:
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 565:
#line 3274 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 566:
#line 3279 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 567:
#line 3285 "ircd_parser.y"
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
#line 3296 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 569:
#line 3301 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 570:
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 571:
#line 3315 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 572:
#line 3320 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 573:
#line 3325 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 574:
#line 3330 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 575:
#line 3335 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 576:
#line 3338 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 577:
#line 3343 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 578:
#line 3346 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 579:
#line 3351 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 580:
#line 3356 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:
#line 3361 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 582:
#line 3366 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:
#line 3371 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 584:
#line 3376 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 585:
#line 3381 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 586:
#line 3386 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 587:
#line 3391 "ircd_parser.y"
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
#line 3402 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
#line 3407 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 590:
#line 3412 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:
#line 3417 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 592:
#line 3426 "ircd_parser.y"
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
#line 3458 "ircd_parser.y"
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
#line 3476 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 595:
#line 3481 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 596:
#line 3490 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 597:
#line 3495 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 598:
#line 3500 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 599:
#line 3505 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 603:
#line 3511 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 604:
#line 3514 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 605:
#line 3517 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 606:
#line 3520 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 607:
#line 3523 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 608:
#line 3526 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 609:
#line 3529 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 610:
#line 3532 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 611:
#line 3535 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 612:
#line 3538 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 613:
#line 3541 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 614:
#line 3544 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 615:
#line 3547 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 616:
#line 3550 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 617:
#line 3553 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 618:
#line 3556 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 619:
#line 3559 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 620:
#line 3562 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 621:
#line 3565 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_GOD;
}
    break;

  case 622:
#line 3570 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 626:
#line 3576 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 627:
#line 3579 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 628:
#line 3582 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 629:
#line 3585 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 630:
#line 3588 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 631:
#line 3591 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 632:
#line 3594 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 633:
#line 3597 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 634:
#line 3600 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 635:
#line 3603 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 636:
#line 3606 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 637:
#line 3609 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 638:
#line 3612 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 639:
#line 3615 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERV;
}
    break;

  case 640:
#line 3618 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 641:
#line 3621 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 642:
#line 3624 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 643:
#line 3627 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 644:
#line 3630 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 645:
#line 3635 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:
#line 3640 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:
#line 3645 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:
#line 3650 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 649:
#line 3655 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 650:
#line 3663 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 651:
#line 3670 "ircd_parser.y"
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
#line 3696 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 662:
#line 3702 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 663:
#line 3708 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 667:
#line 3714 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 668:
#line 3718 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 669:
#line 3724 "ircd_parser.y"
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
#line 3758 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 671:
#line 3767 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 672:
#line 3771 "ircd_parser.y"
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
#line 3818 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 676:
#line 3822 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 699:
#line 3846 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 700:
#line 3851 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 701:
#line 3856 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 702:
#line 3861 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 703:
#line 3866 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 704:
#line 3871 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 705:
#line 3876 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 706:
#line 3881 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 707:
#line 3886 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 708:
#line 3891 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 709:
#line 3896 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 710:
#line 3901 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 711:
#line 3906 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 712:
#line 3911 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 713:
#line 3916 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 714:
#line 3921 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 715:
#line 3926 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 716:
#line 3931 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 728:
#line 3950 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 729:
#line 3956 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 730:
#line 3962 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 731:
#line 3971 "ircd_parser.y"
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
#line 3985 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 733:
#line 3991 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 734:
#line 3997 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1267 of yacc.c.  */
#line 7789 "y.tab.c"
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



