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
     LEAF_MASK = 355,
     LINKS_DELAY = 356,
     LISTEN = 357,
     T_LOG = 358,
     LOGGING = 359,
     LOG_LEVEL = 360,
     MAX_ACCEPT = 361,
     MAX_BANS = 362,
     MAX_CHANS_PER_USER = 363,
     MAX_GLOBAL = 364,
     MAX_IDENT = 365,
     MAX_LOCAL = 366,
     MAX_NICK_CHANGES = 367,
     MAX_NICK_TIME = 368,
     MAX_NUMBER = 369,
     MAX_TARGETS = 370,
     MAX_WATCH = 371,
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
     T_SERVER = 485,
     T_SERVNOTICE = 486,
     T_SKILL = 487,
     T_SPY = 488,
     T_SSL = 489,
     T_UMODES = 490,
     T_UNAUTH = 491,
     T_UNRESV = 492,
     T_UNXLINE = 493,
     T_WALLOP = 494,
     THROTTLE_TIME = 495,
     TOPICBURST = 496,
     TRUE_NO_OPER_FLOOD = 497,
     TKLINE = 498,
     TXLINE = 499,
     TRESV = 500,
     UNKLINE = 501,
     USER = 502,
     USE_EGD = 503,
     USE_EXCEPT = 504,
     USE_INVEX = 505,
     USE_KNOCK = 506,
     USE_LOGGING = 507,
     USE_WHOIS_ACTUALLY = 508,
     VHOST = 509,
     VHOST6 = 510,
     XLINE = 511,
     WARN = 512,
     WARN_NO_NLINE = 513
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
#define LEAF_MASK 355
#define LINKS_DELAY 356
#define LISTEN 357
#define T_LOG 358
#define LOGGING 359
#define LOG_LEVEL 360
#define MAX_ACCEPT 361
#define MAX_BANS 362
#define MAX_CHANS_PER_USER 363
#define MAX_GLOBAL 364
#define MAX_IDENT 365
#define MAX_LOCAL 366
#define MAX_NICK_CHANGES 367
#define MAX_NICK_TIME 368
#define MAX_NUMBER 369
#define MAX_TARGETS 370
#define MAX_WATCH 371
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
#define T_SERVER 485
#define T_SERVNOTICE 486
#define T_SKILL 487
#define T_SPY 488
#define T_SSL 489
#define T_UMODES 490
#define T_UNAUTH 491
#define T_UNRESV 492
#define T_UNXLINE 493
#define T_WALLOP 494
#define THROTTLE_TIME 495
#define TOPICBURST 496
#define TRUE_NO_OPER_FLOOD 497
#define TKLINE 498
#define TXLINE 499
#define TRESV 500
#define UNKLINE 501
#define USER 502
#define USE_EGD 503
#define USE_EXCEPT 504
#define USE_INVEX 505
#define USE_KNOCK 506
#define USE_LOGGING 507
#define USE_WHOIS_ACTUALLY 508
#define VHOST 509
#define VHOST6 510
#define XLINE 511
#define WARN 512
#define WARN_NO_NLINE 513




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
#line 726 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 739 "y.tab.c"

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
#define YYLAST   1410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  264
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  342
/* YYNRULES -- Number of rules.  */
#define YYNRULES  736
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1483

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   513

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   263,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   259,
       2,   262,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   261,     2,   260,     2,     2,     2,     2,
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
     255,   256,   257,   258
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
     764,   771,   772,   778,   782,   784,   786,   788,   790,   793,
     795,   797,   799,   801,   803,   806,   807,   813,   817,   819,
     821,   825,   830,   835,   836,   843,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   878,   880,   883,   888,   893,   898,   903,   908,
     909,   915,   919,   921,   922,   926,   927,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   948,   950,   955,   960,
     965,   970,   975,   980,   985,   990,   995,  1000,  1001,  1008,
    1011,  1013,  1015,  1017,  1019,  1022,  1027,  1032,  1037,  1038,
    1045,  1048,  1050,  1052,  1054,  1056,  1059,  1064,  1069,  1070,
    1076,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1102,  1104,  1105,  1112,  1115,  1117,  1119,  1121,
    1124,  1129,  1130,  1136,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1162,  1164,  1165,  1173,  1174,
    1176,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,
    1217,  1219,  1222,  1227,  1229,  1234,  1239,  1244,  1249,  1254,
    1259,  1264,  1269,  1270,  1276,  1280,  1282,  1283,  1287,  1288,
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
    1617,  1622,  1627,  1632,  1637,  1642,  1647,  1652,  1657,  1662,
    1667,  1672,  1677,  1682,  1687,  1692,  1697,  1702,  1707,  1712,
    1717,  1722,  1727,  1732,  1737,  1742,  1747,  1752,  1757,  1762,
    1767,  1772,  1777,  1782,  1787,  1792,  1797,  1802,  1807,  1812,
    1817,  1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,
    1867,  1872,  1873,  1879,  1883,  1885,  1887,  1889,  1891,  1893,
    1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,
    1915,  1917,  1919,  1921,  1923,  1924,  1930,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,
    1960,  1962,  1964,  1966,  1968,  1970,  1972,  1974,  1979,  1984,
    1989,  1994,  1999,  2000,  2007,  2010,  2012,  2014,  2016,  2018,
    2020,  2022,  2024,  2026,  2031,  2036,  2037,  2043,  2047,  2049,
    2051,  2053,  2058,  2063,  2064,  2070,  2074,  2076,  2078,  2080,
    2086,  2089,  2091,  2093,  2095,  2097,  2099,  2101,  2103,  2105,
    2107,  2109,  2111,  2113,  2115,  2117,  2119,  2121,  2123,  2125,
    2127,  2129,  2134,  2139,  2144,  2149,  2154,  2159,  2164,  2169,
    2174,  2179,  2184,  2189,  2194,  2199,  2204,  2209,  2214,  2219,
    2225,  2228,  2230,  2232,  2234,  2236,  2238,  2240,  2242,  2244,
    2246,  2251,  2256,  2261,  2266,  2271,  2276
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     265,     0,    -1,    -1,   265,   266,    -1,   290,    -1,   296,
      -1,   311,    -1,   575,    -1,   348,    -1,   367,    -1,   381,
      -1,   276,    -1,   596,    -1,   407,    -1,   414,    -1,   424,
      -1,   433,    -1,   464,    -1,   474,    -1,   480,    -1,   494,
      -1,   559,    -1,   484,    -1,   271,    -1,     1,   259,    -1,
       1,   260,    -1,    -1,   268,    -1,   133,   267,    -1,   133,
     172,   267,    -1,   133,   173,   267,    -1,   133,   174,   267,
      -1,   133,   175,   267,    -1,   133,   176,   267,    -1,    -1,
     270,    -1,   133,   269,    -1,   133,    14,   269,    -1,   133,
      15,   269,    -1,   133,    16,   269,    -1,   121,   261,   272,
     260,   259,    -1,   272,   273,    -1,   273,    -1,   274,    -1,
     275,    -1,     1,   259,    -1,   120,   262,   155,   259,    -1,
     150,   262,   155,   259,    -1,   180,   261,   277,   260,   259,
      -1,   277,   278,    -1,   278,    -1,   281,    -1,   286,    -1,
     289,    -1,   283,    -1,   284,    -1,   285,    -1,   288,    -1,
     280,    -1,   287,    -1,   282,    -1,   279,    -1,     1,   259,
      -1,   169,   262,   155,   259,    -1,   167,   262,   155,   259,
      -1,   122,   262,   155,   259,    -1,   182,   262,   155,   259,
      -1,    37,   262,   155,   259,    -1,   125,   262,   155,   259,
      -1,   124,   262,   155,   259,    -1,   254,   262,   155,   259,
      -1,   255,   262,   155,   259,    -1,   226,   262,   133,   259,
      -1,    86,   262,   196,   259,    -1,     5,   261,   291,   260,
     259,    -1,   291,   292,    -1,   292,    -1,   293,    -1,   295,
      -1,   294,    -1,     1,   259,    -1,   122,   262,   155,   259,
      -1,    48,   262,   155,   259,    -1,    37,   262,   155,   259,
      -1,   104,   261,   297,   260,   259,    -1,   297,   298,    -1,
     298,    -1,   299,    -1,   300,    -1,   309,    -1,   310,    -1,
     301,    -1,   303,    -1,   305,    -1,   306,    -1,   308,    -1,
     304,    -1,   307,    -1,   302,    -1,     1,   259,    -1,   218,
     262,   155,   259,    -1,   140,   262,   155,   259,    -1,    64,
     262,   155,   259,    -1,    57,   262,   155,   259,    -1,    62,
     262,   155,   259,    -1,    63,   262,   155,   259,    -1,    60,
     262,   155,   259,    -1,    59,   262,   155,   259,    -1,    61,
     262,   155,   259,    -1,    58,   262,   155,   259,    -1,   105,
     262,   219,   259,    -1,   105,   262,   221,   259,    -1,   105,
     262,   225,   259,    -1,   105,   262,   223,   259,    -1,   105,
     262,   224,   259,    -1,   105,   262,   222,   259,    -1,   105,
     262,   220,   259,    -1,   252,   262,   196,   259,    -1,    -1,
     138,   312,   313,   261,   314,   260,   259,    -1,    -1,   317,
      -1,   314,   315,    -1,   315,    -1,   316,    -1,   318,    -1,
     319,    -1,   338,    -1,   339,    -1,   323,    -1,   322,    -1,
     327,    -1,   328,    -1,   330,    -1,   331,    -1,   332,    -1,
     333,    -1,   334,    -1,   329,    -1,   335,    -1,   336,    -1,
     337,    -1,   340,    -1,   320,    -1,   321,    -1,   341,    -1,
       1,   259,    -1,   122,   262,   155,   259,    -1,   155,    -1,
     247,   262,   155,   259,    -1,   149,   262,   155,   259,    -1,
      50,   262,   196,   259,    -1,   168,   262,   155,   259,    -1,
      26,   262,   155,   259,    -1,    -1,   235,   324,   262,   325,
     259,    -1,   325,   263,   326,    -1,   326,    -1,   203,    -1,
     206,    -1,   207,    -1,   209,    -1,   210,    -1,   213,    -1,
     232,    -1,   227,    -1,   229,    -1,   236,    -1,   233,    -1,
     212,    -1,   228,    -1,   231,    -1,   214,    -1,   239,    -1,
     204,    -1,   205,    -1,   217,    -1,    74,   262,   196,   259,
      -1,   163,   262,   196,   259,    -1,   164,   262,   196,   259,
      -1,    94,   262,   196,   259,    -1,   256,   262,   196,   259,
      -1,   246,   262,   196,   259,    -1,    67,   262,   196,   259,
      -1,   127,   262,   196,   259,    -1,    38,   262,   196,   259,
      -1,   161,   262,   196,   259,    -1,     5,   262,   196,   259,
      -1,    79,   262,   196,   259,    -1,    81,   262,   196,   259,
      -1,   228,   262,   196,   259,    -1,    -1,    55,   342,   262,
     343,   259,    -1,   343,   263,   344,    -1,   344,    -1,    -1,
     132,   345,   347,    -1,    -1,   346,   347,    -1,    74,    -1,
     163,    -1,    94,    -1,   246,    -1,   256,    -1,    67,    -1,
      38,    -1,   161,    -1,     5,    -1,    79,    -1,   127,    -1,
     228,    -1,   143,    -1,    81,    -1,   164,    -1,    50,    -1,
      -1,    26,   349,   350,   261,   351,   260,   259,    -1,    -1,
     354,    -1,   351,   352,    -1,   352,    -1,   353,    -1,   364,
      -1,   365,    -1,   355,    -1,   356,    -1,   366,    -1,   357,
      -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,   362,
      -1,   363,    -1,     1,   259,    -1,   122,   262,   155,   259,
      -1,   155,    -1,   152,   262,   268,   259,    -1,   153,   262,
     268,   259,    -1,   136,   262,   133,   259,    -1,    30,   262,
     268,   259,    -1,   114,   262,   133,   259,    -1,   109,   262,
     133,   259,    -1,   111,   262,   133,   259,    -1,   110,   262,
     133,   259,    -1,   177,   262,   270,   259,    -1,    23,   262,
     133,   259,    -1,    24,   262,   133,   259,    -1,   135,   262,
     133,   259,    -1,    -1,   102,   368,   261,   373,   260,   259,
      -1,    -1,    55,   370,   262,   371,   259,    -1,   371,   263,
     372,    -1,   372,    -1,   234,    -1,    78,    -1,   230,    -1,
     373,   374,    -1,   374,    -1,   375,    -1,   369,    -1,   379,
      -1,   380,    -1,     1,   259,    -1,    -1,   154,   262,   377,
     376,   259,    -1,   377,   263,   378,    -1,   378,    -1,   133,
      -1,   133,   201,   133,    -1,    91,   262,   155,   259,    -1,
      85,   262,   155,   259,    -1,    -1,    75,   382,   261,   383,
     260,   259,    -1,   383,   384,    -1,   384,    -1,   385,    -1,
     386,    -1,   388,    -1,   390,    -1,   397,    -1,   398,    -1,
     399,    -1,   401,    -1,   402,    -1,   403,    -1,   387,    -1,
     404,    -1,   405,    -1,   400,    -1,   406,    -1,   389,    -1,
       1,   259,    -1,   247,   262,   155,   259,    -1,   149,   262,
     155,   259,    -1,   190,   262,   196,   259,    -1,    26,   262,
     155,   259,    -1,    50,   262,   196,   259,    -1,    -1,    55,
     391,   262,   392,   259,    -1,   392,   263,   393,    -1,   393,
      -1,    -1,   132,   394,   396,    -1,    -1,   395,   396,    -1,
     190,    -1,    51,    -1,    95,    -1,    76,    -1,    20,    -1,
      21,    -1,   131,    -1,    69,    -1,   171,    -1,   123,    -1,
      95,   262,   196,   259,    -1,    76,   262,   196,   259,    -1,
      51,   262,   196,   259,    -1,    20,   262,   196,   259,    -1,
     131,   262,   196,   259,    -1,    69,   262,   196,   259,    -1,
     189,   262,   155,   259,    -1,   159,   262,   155,   259,    -1,
     158,   262,   133,   259,    -1,   123,   262,   196,   259,    -1,
      -1,   170,   408,   261,   409,   260,   259,    -1,   409,   410,
      -1,   410,    -1,   411,    -1,   412,    -1,   413,    -1,     1,
     259,    -1,   157,   262,   155,   259,    -1,    22,   262,   155,
     259,    -1,   126,   262,   155,   259,    -1,    -1,   184,   415,
     261,   416,   260,   259,    -1,   416,   417,    -1,   417,    -1,
     418,    -1,   419,    -1,   420,    -1,     1,   259,    -1,   122,
     262,   155,   259,    -1,   247,   262,   155,   259,    -1,    -1,
     186,   421,   262,   422,   259,    -1,   422,   263,   423,    -1,
     423,    -1,    94,    -1,   243,    -1,   246,    -1,   256,    -1,
     244,    -1,   238,    -1,   170,    -1,   245,    -1,   237,    -1,
     217,    -1,   202,    -1,    -1,   185,   425,   261,   426,   260,
     259,    -1,   426,   427,    -1,   427,    -1,   428,    -1,   429,
      -1,     1,   259,    -1,   122,   262,   155,   259,    -1,    -1,
     186,   430,   262,   431,   259,    -1,   431,   263,   432,    -1,
     432,    -1,    94,    -1,   243,    -1,   246,    -1,   256,    -1,
     244,    -1,   238,    -1,   170,    -1,   245,    -1,   237,    -1,
     217,    -1,   202,    -1,    -1,    29,   434,   435,   261,   436,
     260,   259,    -1,    -1,   439,    -1,   436,   437,    -1,   437,
      -1,   438,    -1,   440,    -1,   441,    -1,   442,    -1,   443,
      -1,   445,    -1,   444,    -1,   446,    -1,   447,    -1,   460,
      -1,   461,    -1,   462,    -1,   458,    -1,   455,    -1,   457,
      -1,   456,    -1,   454,    -1,   463,    -1,   459,    -1,     1,
     259,    -1,   122,   262,   155,   259,    -1,   155,    -1,    85,
     262,   155,   259,    -1,   254,   262,   155,   259,    -1,   178,
     262,   155,   259,    -1,     3,   262,   155,   259,    -1,   154,
     262,   133,   259,    -1,     6,   262,   215,   259,    -1,     6,
     262,   216,   259,    -1,    54,   262,   155,   259,    -1,    -1,
      55,   448,   262,   449,   259,    -1,   449,   263,   450,    -1,
     450,    -1,    -1,   132,   451,   453,    -1,    -1,   452,   453,
      -1,    27,    -1,    31,    -1,    10,    -1,    12,    -1,   241,
      -1,   168,   262,   155,   259,    -1,    50,   262,   196,   259,
      -1,    31,   262,   196,   259,    -1,    27,   262,   196,   259,
      -1,    10,   262,   196,   259,    -1,   241,   262,   196,   259,
      -1,    87,   262,   155,   259,    -1,   100,   262,   155,   259,
      -1,    26,   262,   155,   259,    -1,    25,   262,   155,   259,
      -1,    -1,    92,   465,   261,   470,   260,   259,    -1,    -1,
     186,   467,   262,   468,   259,    -1,   468,   263,   469,    -1,
     469,    -1,   160,    -1,   470,   471,    -1,   471,    -1,   472,
      -1,   473,    -1,   466,    -1,     1,    -1,   247,   262,   155,
     259,    -1,   157,   262,   155,   259,    -1,    -1,    36,   475,
     261,   476,   260,   259,    -1,   476,   477,    -1,   477,    -1,
     478,    -1,   479,    -1,     1,    -1,    91,   262,   155,   259,
      -1,   157,   262,   155,   259,    -1,    52,   261,   481,   260,
     259,    -1,   481,   482,    -1,   482,    -1,   483,    -1,     1,
      -1,    91,   262,   155,   259,    -1,    -1,    65,   485,   261,
     490,   260,   259,    -1,    -1,   186,   487,   262,   488,   259,
      -1,   488,   263,   489,    -1,   489,    -1,   160,    -1,   490,
     491,    -1,   491,    -1,   492,    -1,   493,    -1,   486,    -1,
       1,    -1,   122,   262,   155,   259,    -1,   157,   262,   155,
     259,    -1,    66,   261,   495,   260,   259,    -1,   495,   496,
      -1,   496,    -1,   505,    -1,   506,    -1,   508,    -1,   509,
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
      -1,   521,    -1,   497,    -1,     1,    -1,   116,   262,   133,
     259,    -1,    72,   262,   133,   259,    -1,    73,   262,   133,
     259,    -1,    12,   262,   196,   259,    -1,   253,   262,   196,
     259,    -1,   162,   262,   268,   259,    -1,   183,   262,   196,
     259,    -1,    93,   262,   133,   259,    -1,    84,   262,   196,
     259,    -1,    89,   262,   196,   259,    -1,    43,   262,   196,
     259,    -1,    53,   262,   196,   259,    -1,     8,   262,   196,
     259,    -1,   113,   262,   268,   259,    -1,   112,   262,   133,
     259,    -1,   106,   262,   133,   259,    -1,     9,   262,   268,
     259,    -1,   200,   262,   268,   259,    -1,   199,   262,   268,
     259,    -1,    77,   262,   133,   259,    -1,    97,   262,   196,
     259,    -1,    96,   262,   155,   259,    -1,    90,   262,   196,
     259,    -1,   258,   262,   196,   259,    -1,   191,   262,   196,
     259,    -1,   194,   262,   196,   259,    -1,   195,   262,   196,
     259,    -1,   193,   262,   196,   259,    -1,   193,   262,   197,
     259,    -1,   192,   262,   196,   259,    -1,   192,   262,   197,
     259,    -1,   147,   262,   268,   259,    -1,    19,   262,   268,
     259,    -1,   139,   262,   196,   259,    -1,   148,   262,   268,
     259,    -1,   187,   262,   196,   259,    -1,   130,   262,   196,
     259,    -1,   242,   262,   196,   259,    -1,   142,   262,   196,
     259,    -1,   117,   262,   155,   259,    -1,    88,   262,   268,
     259,    -1,    45,   262,   133,   259,    -1,   115,   262,   133,
     259,    -1,   181,   262,   155,   259,    -1,    32,   262,   155,
     259,    -1,    28,   262,   133,   259,    -1,   248,   262,   196,
     259,    -1,    47,   262,   155,   259,    -1,   151,   262,   196,
     259,    -1,    39,   262,   196,   259,    -1,   240,   262,   268,
     259,    -1,    -1,   144,   547,   262,   548,   259,    -1,   548,
     263,   549,    -1,   549,    -1,   203,    -1,   206,    -1,   207,
      -1,   209,    -1,   210,    -1,   213,    -1,   232,    -1,   227,
      -1,   229,    -1,   236,    -1,   233,    -1,   212,    -1,   228,
      -1,   231,    -1,   214,    -1,   239,    -1,   204,    -1,   205,
      -1,   217,    -1,    -1,   141,   551,   262,   552,   259,    -1,
     552,   263,   553,    -1,   553,    -1,   203,    -1,   206,    -1,
     207,    -1,   209,    -1,   210,    -1,   213,    -1,   232,    -1,
     227,    -1,   229,    -1,   236,    -1,   233,    -1,   212,    -1,
     228,    -1,   231,    -1,   214,    -1,   239,    -1,   204,    -1,
     205,    -1,   217,    -1,   118,   262,   133,   259,    -1,   119,
     262,   133,   259,    -1,    33,   262,   133,   259,    -1,   208,
     262,   270,   259,    -1,    44,   262,   196,   259,    -1,    -1,
      68,   560,   261,   561,   260,   259,    -1,   561,   562,    -1,
     562,    -1,   563,    -1,   564,    -1,   565,    -1,   569,    -1,
     570,    -1,   571,    -1,     1,    -1,    49,   262,   196,   259,
      -1,    46,   262,   268,   259,    -1,    -1,   104,   566,   262,
     567,   259,    -1,   567,   263,   568,    -1,   568,    -1,   198,
      -1,    11,    -1,   247,   262,   155,   259,    -1,   122,   262,
     155,   259,    -1,    -1,     4,   572,   262,   573,   259,    -1,
     573,   263,   574,    -1,   574,    -1,   198,    -1,    11,    -1,
      22,   261,   576,   260,   259,    -1,   576,   577,    -1,   577,
      -1,   580,    -1,   581,    -1,   582,    -1,   583,    -1,   588,
      -1,   584,    -1,   585,    -1,   586,    -1,   587,    -1,   589,
      -1,   590,    -1,   591,    -1,   579,    -1,   592,    -1,   593,
      -1,   594,    -1,   595,    -1,   578,    -1,     1,    -1,    40,
     262,   196,   259,    -1,   165,   262,   196,   259,    -1,    42,
     262,   196,   259,    -1,   249,   262,   196,   259,    -1,   250,
     262,   196,   259,    -1,   251,   262,   196,   259,    -1,    98,
     262,   268,   259,    -1,    99,   262,   268,   259,    -1,   108,
     262,   133,   259,    -1,   156,   262,   196,   259,    -1,   107,
     262,   133,   259,    -1,    35,   262,   133,   259,    -1,    34,
     262,   133,   259,    -1,   128,   262,   196,   259,    -1,   129,
     262,   196,   259,    -1,    13,   262,   196,   259,    -1,   145,
     262,   133,   259,    -1,   146,   262,   268,   259,    -1,   179,
     261,   597,   260,   259,    -1,   597,   598,    -1,   598,    -1,
     599,    -1,   600,    -1,   602,    -1,   604,    -1,   603,    -1,
     601,    -1,   605,    -1,     1,    -1,    56,   262,   196,   259,
      -1,    83,   262,   196,   259,    -1,    80,   262,   155,   259,
      -1,   101,   262,   268,   259,    -1,    78,   262,   196,   259,
      -1,    41,   262,   196,   259,    -1,    82,   262,   196,   259,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   396,   396,   397,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   425,   425,   426,   430,
     434,   438,   442,   446,   452,   452,   453,   454,   455,   456,
     463,   466,   466,   467,   467,   467,   469,   486,   497,   500,
     501,   502,   502,   503,   503,   504,   504,   505,   506,   506,
     507,   507,   508,   510,   544,   604,   618,   633,   642,   656,
     665,   693,   723,   746,   768,   770,   770,   771,   771,   772,
     772,   774,   783,   792,   805,   807,   808,   810,   810,   811,
     812,   812,   813,   813,   814,   814,   815,   815,   816,   817,
     819,   823,   827,   834,   841,   848,   855,   862,   869,   876,
     883,   887,   891,   895,   899,   903,   907,   913,   923,   922,
    1016,  1016,  1017,  1017,  1018,  1018,  1018,  1018,  1019,  1019,
    1020,  1020,  1020,  1021,  1021,  1021,  1022,  1022,  1022,  1023,
    1023,  1023,  1023,  1024,  1024,  1025,  1025,  1027,  1039,  1051,
    1085,  1097,  1108,  1150,  1160,  1159,  1165,  1165,  1166,  1170,
    1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,  1206,  1210,
    1214,  1218,  1222,  1226,  1230,  1234,  1238,  1244,  1255,  1266,
    1277,  1288,  1299,  1310,  1321,  1332,  1343,  1354,  1365,  1376,
    1387,  1399,  1398,  1402,  1402,  1403,  1403,  1404,  1404,  1406,
    1413,  1420,  1427,  1434,  1441,  1448,  1455,  1462,  1469,  1476,
    1483,  1490,  1497,  1504,  1511,  1525,  1524,  1574,  1574,  1576,
    1576,  1577,  1578,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1585,  1586,  1587,  1588,  1589,  1591,  1600,  1609,  1615,  1621,
    1627,  1633,  1639,  1645,  1651,  1657,  1663,  1669,  1675,  1685,
    1684,  1701,  1700,  1705,  1705,  1706,  1710,  1714,  1722,  1722,
    1723,  1723,  1723,  1723,  1723,  1725,  1725,  1727,  1727,  1729,
    1743,  1763,  1772,  1785,  1784,  1853,  1853,  1854,  1854,  1854,
    1854,  1855,  1855,  1856,  1856,  1856,  1857,  1857,  1858,  1858,
    1858,  1859,  1859,  1859,  1861,  1898,  1911,  1922,  1931,  1943,
    1942,  1946,  1946,  1947,  1947,  1948,  1948,  1950,  1958,  1965,
    1972,  1979,  1986,  1993,  2000,  2007,  2014,  2023,  2034,  2045,
    2056,  2067,  2078,  2090,  2109,  2119,  2128,  2144,  2143,  2159,
    2159,  2160,  2160,  2160,  2160,  2162,  2171,  2186,  2200,  2199,
    2215,  2215,  2216,  2216,  2216,  2216,  2218,  2227,  2250,  2249,
    2255,  2255,  2256,  2260,  2264,  2268,  2272,  2276,  2280,  2284,
    2288,  2292,  2296,  2306,  2305,  2322,  2322,  2323,  2323,  2323,
    2325,  2332,  2331,  2337,  2337,  2338,  2342,  2346,  2350,  2354,
    2358,  2362,  2366,  2370,  2374,  2378,  2388,  2387,  2533,  2533,
    2534,  2534,  2535,  2535,  2535,  2536,  2536,  2537,  2537,  2538,
    2538,  2538,  2539,  2539,  2539,  2540,  2540,  2540,  2541,  2541,
    2542,  2542,  2544,  2556,  2568,  2577,  2603,  2621,  2639,  2645,
    2649,  2657,  2667,  2666,  2670,  2670,  2671,  2671,  2672,  2672,
    2674,  2685,  2692,  2699,  2706,  2716,  2757,  2768,  2779,  2794,
    2805,  2816,  2829,  2842,  2851,  2887,  2886,  2951,  2950,  2954,
    2954,  2955,  2961,  2961,  2962,  2962,  2962,  2962,  2964,  2983,
    2993,  2992,  3014,  3014,  3015,  3015,  3015,  3017,  3026,  3038,
    3040,  3040,  3041,  3041,  3043,  3065,  3064,  3107,  3106,  3110,
    3110,  3111,  3117,  3117,  3118,  3118,  3118,  3118,  3120,  3126,
    3135,  3138,  3138,  3139,  3139,  3140,  3140,  3141,  3141,  3142,
    3142,  3143,  3143,  3144,  3144,  3145,  3145,  3146,  3146,  3147,
    3147,  3148,  3148,  3149,  3149,  3150,  3150,  3151,  3151,  3152,
    3152,  3153,  3153,  3154,  3154,  3155,  3155,  3156,  3156,  3157,
    3157,  3158,  3158,  3159,  3160,  3160,  3161,  3161,  3162,  3162,
    3163,  3163,  3164,  3164,  3165,  3165,  3166,  3166,  3167,  3168,
    3171,  3176,  3181,  3186,  3191,  3196,  3201,  3206,  3211,  3216,
    3221,  3226,  3231,  3236,  3241,  3246,  3251,  3256,  3261,  3267,
    3278,  3283,  3292,  3297,  3302,  3307,  3312,  3317,  3320,  3325,
    3328,  3333,  3338,  3343,  3348,  3353,  3358,  3363,  3368,  3373,
    3384,  3389,  3394,  3399,  3408,  3440,  3458,  3463,  3472,  3477,
    3482,  3488,  3487,  3492,  3492,  3493,  3496,  3499,  3502,  3505,
    3508,  3511,  3514,  3517,  3520,  3523,  3526,  3529,  3532,  3535,
    3538,  3541,  3544,  3547,  3553,  3552,  3557,  3557,  3558,  3561,
    3564,  3567,  3570,  3573,  3576,  3579,  3582,  3585,  3588,  3591,
    3594,  3597,  3600,  3603,  3606,  3609,  3612,  3617,  3622,  3627,
    3632,  3637,  3646,  3645,  3669,  3669,  3670,  3671,  3672,  3673,
    3674,  3675,  3676,  3678,  3684,  3691,  3690,  3695,  3695,  3696,
    3700,  3706,  3740,  3750,  3749,  3799,  3799,  3800,  3804,  3813,
    3816,  3816,  3817,  3817,  3818,  3818,  3819,  3819,  3820,  3820,
    3821,  3821,  3822,  3823,  3823,  3824,  3824,  3825,  3825,  3826,
    3826,  3828,  3833,  3838,  3843,  3848,  3853,  3858,  3863,  3868,
    3873,  3878,  3883,  3888,  3893,  3898,  3903,  3908,  3913,  3921,
    3924,  3924,  3925,  3925,  3926,  3927,  3928,  3928,  3929,  3930,
    3932,  3938,  3944,  3953,  3967,  3973,  3979
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
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL", "MAX_ACCEPT",
  "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
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
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVER", "T_SERVNOTICE",
  "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV",
  "T_UNXLINE", "T_WALLOP", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
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
  "general_item", "general_max_watch", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_burst_away",
  "general_use_whois_actually", "general_reject_hold_time",
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
  "general_oper_pass_resv", "general_message_locale", "general_idletime",
  "general_dots_in_ident", "general_max_targets", "general_servlink_path",
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
     505,   506,   507,   508,   509,   510,   511,   512,   513,    59,
     125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   264,   265,   265,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   267,   267,   268,   268,
     268,   268,   268,   268,   269,   269,   270,   270,   270,   270,
     271,   272,   272,   273,   273,   273,   274,   275,   276,   277,
     277,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   291,   292,   292,   292,
     292,   293,   294,   295,   296,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   309,   309,   309,   309,   309,   309,   310,   312,   311,
     313,   313,   314,   314,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   316,   317,   318,
     319,   320,   321,   322,   324,   323,   325,   325,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   342,   341,   343,   343,   345,   344,   346,   344,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   349,   348,   350,   350,   351,
     351,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   368,
     367,   370,   369,   371,   371,   372,   372,   372,   373,   373,
     374,   374,   374,   374,   374,   376,   375,   377,   377,   378,
     378,   379,   380,   382,   381,   383,   383,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   385,   386,   387,   388,   389,   391,
     390,   392,   392,   394,   393,   395,   393,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   408,   407,   409,
     409,   410,   410,   410,   410,   411,   412,   413,   415,   414,
     416,   416,   417,   417,   417,   417,   418,   419,   421,   420,
     422,   422,   423,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   425,   424,   426,   426,   427,   427,   427,
     428,   430,   429,   431,   431,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   434,   433,   435,   435,
     436,   436,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     445,   446,   448,   447,   449,   449,   451,   450,   452,   450,
     453,   453,   453,   453,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   465,   464,   467,   466,   468,
     468,   469,   470,   470,   471,   471,   471,   471,   472,   473,
     475,   474,   476,   476,   477,   477,   477,   478,   479,   480,
     481,   481,   482,   482,   483,   485,   484,   487,   486,   488,
     488,   489,   490,   490,   491,   491,   491,   491,   492,   493,
     494,   495,   495,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   524,   525,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   547,   546,   548,   548,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   551,   550,   552,   552,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   553,   553,   553,
     553,   553,   553,   553,   553,   553,   553,   554,   555,   556,
     557,   558,   560,   559,   561,   561,   562,   562,   562,   562,
     562,   562,   562,   563,   564,   566,   565,   567,   567,   568,
     568,   569,   570,   572,   571,   573,   573,   574,   574,   575,
     576,   576,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   577,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   597,   598,   598,   598,   598,   598,   598,   598,   598,
     599,   600,   601,   602,   603,   604,   605
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
       6,     0,     5,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     7,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     0,     3,     0,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     0,     5,     3,     1,     1,     1,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   215,   386,   460,     0,
     475,     0,   652,   273,   445,   249,     0,     0,   118,   327,
       0,     0,   338,   363,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   217,
     388,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   700,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   681,   699,   694,   682,
     683,   684,   685,   687,   688,   689,   690,   686,   691,   692,
     693,   695,   696,   697,   698,   236,     0,   218,   413,     0,
     389,     0,   473,     0,     0,   471,   472,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   624,     0,   601,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   492,   548,   543,   544,
     541,   545,   546,   542,   503,   493,   494,   532,   495,   496,
     497,   498,   499,   500,   501,   502,   537,   504,   505,   506,
     507,   547,   509,   514,   510,   512,   511,   526,   527,   513,
     515,   516,   517,   518,   520,   519,   508,   522,   531,   533,
     534,   523,   524,   539,   540,   536,   525,   521,   529,   530,
     528,   535,   538,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    91,    98,    92,    96,    93,    94,
      97,    95,    89,    90,     0,     0,     0,     0,    42,    43,
      44,   148,     0,   121,     0,   729,     0,     0,     0,     0,
       0,     0,     0,     0,   721,   722,   723,   727,   724,   726,
     725,   728,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,    61,    58,    51,    60,
      54,    55,    56,    52,    59,    57,    53,     0,     0,    80,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   680,     0,     0,   466,     0,     0,
       0,   463,   464,   465,     0,     0,   470,   487,     0,     0,
     477,   486,     0,   483,   484,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,   662,   673,     0,     0,   665,     0,
       0,     0,   655,   656,   657,   658,   659,   660,   661,     0,
       0,     0,     0,     0,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   276,   277,   278,
     287,   279,   292,   280,   281,   282,   283,   290,   284,   285,
     286,   288,   289,   291,   457,     0,   447,     0,   456,     0,
     453,   454,   455,     0,   251,     0,     0,     0,   261,     0,
     259,   260,   262,   263,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    45,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
     330,   331,   332,   333,     0,     0,     0,     0,     0,     0,
       0,     0,   720,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,   348,
       0,     0,   341,   342,   343,   344,     0,     0,   371,     0,
     366,   367,   368,     0,     0,     0,    74,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   679,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   224,   225,   227,   228,   229,   230,
     231,   232,   233,   222,   223,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   391,   392,   393,
     394,   395,   396,   398,   397,   399,   400,   408,   405,   407,
     406,   404,   410,   401,   402,   403,   409,     0,     0,     0,
     462,     0,   469,     0,     0,     0,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,   490,     0,     0,
       0,     0,     0,     0,     0,   654,   293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   275,     0,     0,     0,     0,   452,
     264,     0,     0,     0,     0,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    40,     0,
       0,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,   123,   124,   125,   126,   143,   144,   130,
     129,   131,   132,   138,   133,   134,   135,   136,   137,   139,
     140,   141,   127,   128,   142,   145,   334,     0,     0,     0,
       0,   329,     0,     0,     0,     0,     0,     0,     0,   719,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   345,     0,     0,     0,     0,   340,   369,     0,
       0,     0,   365,    83,    82,    81,   716,   713,   712,   701,
     703,    26,    26,    26,    26,    26,    28,    27,   707,   708,
     711,   709,   714,   715,   717,   718,   710,   702,   704,   705,
     706,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   390,     0,
       0,   461,   474,     0,     0,     0,   476,   562,   566,   553,
     582,   595,   594,   649,   599,   560,   651,   591,   597,   561,
     551,   552,   569,   558,   590,   559,   572,   557,   571,   570,
     565,   564,   563,   592,   550,   589,   647,   648,   586,   583,
     628,   644,   645,   629,   630,   631,   632,   639,   633,   642,
     646,   635,   640,   636,   641,   634,   638,   637,   643,     0,
     627,   588,   605,   621,   622,   606,   607,   608,   609,   616,
     610,   619,   623,   612,   617,   613,   618,   611,   615,   614,
     620,     0,   604,   581,   584,   598,   555,   593,   556,   585,
     574,   579,   580,   577,   578,   575,   576,   568,   567,    34,
      34,    34,    36,    35,   650,   600,   587,   596,   554,   573,
       0,     0,     0,     0,     0,     0,   653,     0,     0,     0,
       0,   305,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,   446,     0,     0,
       0,   269,   265,   268,   250,   103,   109,   107,   106,   108,
     104,   105,   102,   110,   116,   111,   115,   113,   114,   112,
     101,   100,   117,    46,    47,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,   328,   735,   730,   734,   732,   736,   731,
     733,    67,    73,    65,    69,    68,    64,    63,    66,    72,
      70,    71,     0,     0,     0,   339,     0,     0,   364,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   428,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   467,
     468,   488,   489,   481,     0,   480,   625,     0,   602,     0,
      37,    38,    39,   678,   677,     0,   676,   664,   663,   670,
     669,     0,   668,   672,   671,   320,   297,   298,   319,   303,
       0,   302,     0,   322,   318,   317,   326,   321,   295,   325,
     324,   323,   296,   294,   459,   451,     0,   450,   458,   256,
     257,   255,     0,   254,   272,   271,     0,     0,     0,     0,
       0,     0,     0,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   336,   337,   335,   346,   352,   358,   362,   361,
     360,   357,   353,   356,   359,   354,   355,     0,   351,   347,
     370,   375,   381,   385,   384,   383,   380,   376,   379,   382,
     377,   378,     0,   374,   246,   247,   240,   242,   244,   243,
     241,   235,   248,   239,   237,   238,   245,   417,   419,   420,
     439,   444,   443,   438,   437,   436,   421,   426,     0,   425,
       0,   414,   441,   442,   412,   418,   435,   416,   440,   415,
     478,     0,   626,   603,   674,     0,   666,     0,     0,   300,
     305,   311,   312,   308,   314,   310,   309,   316,   313,   315,
     307,   306,   448,     0,   252,     0,   270,   267,   266,   187,
     153,   185,   151,   195,     0,   194,     0,   183,   177,   188,
     189,   180,   147,   184,   150,   186,   178,   179,   152,   190,
     158,   174,   175,   159,   160,   161,   162,   169,   163,   172,
     176,   165,   170,   166,   171,   164,   168,   167,   173,     0,
     157,   182,   149,   181,   349,     0,   372,     0,     0,   423,
     428,   432,   433,   430,   431,   434,   429,   479,   675,   667,
     304,   301,   449,   253,     0,   192,   197,   207,   205,   214,
     204,   199,   208,   212,   201,   209,   211,   206,   200,   213,
     210,   202,   203,   198,   155,     0,   350,   373,   427,   424,
     196,   193,   156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   896,   897,  1052,  1053,    25,   277,   278,
     279,   280,    26,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,    27,    71,    72,    73,
      74,    75,    28,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,    29,    61,   282,
     822,   823,   824,   283,   825,   826,   827,   828,   829,   830,
    1134,  1429,  1430,   831,   832,   833,   834,   835,   836,   837,
     838,   839,   840,   841,   842,   843,   844,   845,  1120,  1394,
    1395,  1454,  1396,  1473,    30,    49,   116,   611,   612,   613,
     117,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,    31,    58,   498,   771,  1262,  1263,   499,
     500,   501,  1268,  1092,  1093,   502,   503,    32,    56,   466,
     467,   468,   469,   470,   471,   472,   473,   751,  1240,  1241,
    1368,  1242,  1381,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,    33,    62,   529,   530,   531,   532,   533,
      34,    65,   561,   562,   563,   564,   565,   874,  1307,  1308,
      35,    66,   569,   570,   571,   572,   880,  1322,  1323,    36,
      50,   119,   646,   647,   648,   120,   649,   650,   651,   652,
     653,   654,   655,   656,   937,  1348,  1349,  1438,  1350,  1446,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
      37,    57,   488,   766,  1256,  1257,   489,   490,   491,   492,
      38,    51,   360,   361,   362,   363,    39,   124,   125,   126,
      40,    53,   371,   675,  1214,  1215,   372,   373,   374,   375,
      41,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   411,  1031,  1032,   237,   409,  1009,  1010,
     238,   239,   240,   241,   242,    42,    55,   441,   442,   443,
     444,   445,   741,  1231,  1232,   446,   447,   448,   738,  1225,
    1226,    43,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   293,   294,   295,   296,   297,   298,   299,
     300,   301
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -811
static const yytype_int16 yypact[] =
{
    -811,   895,  -811,  -145,  -238,  -216,  -811,  -811,  -811,  -214,
    -811,  -204,  -811,  -811,  -811,  -811,  -196,  -190,  -811,  -811,
    -169,  -167,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,   349,   821,  -127,
    -119,  -153,    11,  -143,   548,  -139,  -124,  -116,  -112,   553,
      26,     1,  -110,     8,   212,  -103,   -81,   -64,   -65,   -60,
     -57,     4,  -811,  -811,  -811,  -811,  -811,   -55,   -53,   -41,
     -33,   -29,   -28,   -25,   -17,   -15,   -12,   -10,    -9,    -1,
      29,    30,    35,    39,    43,   276,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,    51,  -811,  -811,    52,
    -811,   103,  -811,    55,    42,  -811,  -811,   186,  -811,    58,
      63,    65,    68,    69,    70,    84,    85,    86,    91,    93,
      96,    98,   101,   104,   108,   109,   111,   114,   115,   123,
     126,   131,   133,   134,   136,   138,   139,   140,   141,   144,
     148,   156,  -811,   157,  -811,   173,   174,   180,   182,   184,
     187,   190,   191,   192,   193,   195,   198,   203,   206,   207,
     211,   214,   215,   218,   219,    23,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,   341,   650,    62,   153,   -23,   220,   221,
     232,   234,   237,   239,   240,   242,   243,   244,   246,   247,
     367,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,    31,   249,   250,     7,  -811,  -811,
    -811,  -811,    53,  -811,    24,  -811,   251,   253,   254,   255,
     257,   258,   259,   202,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,    45,   260,   262,   266,   268,   271,   272,   273,
     281,   282,   283,   286,   292,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,    10,    12,  -811,
     204,   209,   227,    82,  -811,   217,   315,   331,   307,   335,
     418,   418,   420,   422,   363,   366,   428,   418,   369,   370,
     372,   373,   374,   304,  -811,   823,   794,  -811,   309,   310,
      78,  -811,  -811,  -811,   423,   314,  -811,  -811,   313,   322,
    -811,  -811,     2,  -811,  -811,  -811,   381,   418,   390,   418,
     456,   439,   463,   401,   402,   406,   470,   449,   426,   490,
     491,   493,   432,   418,   433,   434,   500,   479,   443,   507,
     509,   418,   510,   513,   492,   515,   516,   454,   457,   393,
     461,   397,   418,   418,   466,   418,   497,   473,   475,   476,
      15,    28,   477,   478,   418,   418,   542,   418,   481,   483,
     485,   486,   424,  -811,  -811,  -811,   429,   436,  -811,   440,
     441,    79,  -811,  -811,  -811,  -811,  -811,  -811,  -811,   425,
     444,   445,   446,   450,  -811,   452,   453,   455,   458,   459,
     460,   465,   468,   471,   472,   474,    97,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   482,  -811,   487,  -811,   102,
    -811,  -811,  -811,   427,  -811,   488,   489,   504,  -811,    14,
    -811,  -811,  -811,  -811,  -811,   533,   539,   561,   563,   568,
     570,   573,   577,   540,   582,   583,   557,   495,  -811,  -811,
     600,   612,   511,  -811,   630,   517,   506,   512,   518,    18,
    -811,  -811,  -811,  -811,   576,   581,   587,   614,   588,   589,
     418,   519,  -811,  -811,   631,   596,   648,   652,   655,   656,
     657,   658,   681,   660,   661,   558,  -811,   559,   564,  -811,
     565,   120,  -811,  -811,  -811,  -811,   569,   567,  -811,   129,
    -811,  -811,  -811,   571,   572,   574,  -811,   578,   579,   584,
     586,   591,   365,   593,   595,   598,   601,   603,   605,   607,
     608,   609,   611,   615,   616,   619,  -811,   621,   580,   597,
     620,   622,   623,   625,   626,   627,   628,   629,   636,   637,
     639,   298,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,   624,   640,   641,   642,
     643,   644,   645,   646,   647,   649,  -811,   651,   653,   663,
     664,   665,   668,   673,   676,   677,   269,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,   686,   718,   633,
    -811,   634,  -811,   755,   757,   678,   659,  -811,   682,   683,
     684,   685,   687,   692,   693,   694,   696,   697,   698,   706,
     709,   710,   712,   714,   715,   719,   720,   721,   722,   723,
     724,   725,   726,   729,   730,   731,   732,   733,   734,   735,
     736,   798,   737,   878,   739,   747,   750,   754,   758,   759,
     760,   761,   762,   763,   764,   765,   769,   773,   777,   779,
      44,   780,   781,   782,   783,   784,   785,  -811,   752,   418,
     727,   787,   767,   890,   788,  -811,  -811,   850,   896,   854,
     856,   791,   858,   859,   860,   861,   862,   904,   690,   905,
     906,   866,   908,   805,  -811,   911,   806,   912,   810,  -811,
    -811,   811,   921,   922,   699,   819,  -811,   827,   830,   834,
     835,   837,   838,   839,   840,   841,   842,   843,   844,   845,
     849,   853,   857,   864,   867,  -811,   871,   872,  -811,   874,
     851,   873,   875,   876,  -811,   877,   879,   883,   887,   888,
     891,   893,   894,   897,   898,   899,   900,   901,  -811,   902,
     903,   907,   105,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,   960,   979,   981,
     881,  -811,   909,   913,   914,   916,   917,   918,   919,  -811,
     920,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,  -811,  -811,   997,   933,  1002,   934,  -811,  -811,  1003,
     935,   937,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,   418,   418,   418,   418,   418,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,   703,  1033,   418,  1034,  1037,  1038,  1041,  1025,
    1048,  1059,   418,   418,   542,   939,  -811,  -811,  1039,   -26,
    1004,  1044,  1046,  1006,  1007,  1008,  1050,   944,  1052,  1053,
    1054,  1055,  1078,  1057,  1058,  1018,  1060,   957,  -811,   958,
     959,  -811,  -811,   961,   962,  1062,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -249,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -243,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,   542,
     542,   542,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
      -7,   964,   965,    -5,   966,   967,  -811,   968,   969,   970,
     971,  1087,   972,   973,   974,   975,   976,   977,   978,   980,
     982,   983,   984,  -811,   985,  1080,   986,  -811,    -4,   987,
     988,   713,   152,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  1042,  1093,  1056,  1061,
     989,  1063,  1064,  1065,  1066,  1067,  1094,  1068,  1095,  1069,
    1070,  1071,  1098,  1072,   992,  1073,  1100,  1074,   999,  -811,
    1012,  1013,  1014,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  1015,   241,  1016,  -811,  1017,   362,  -811,  -811,
    -811,  -811,  -811,  -811,  1019,  1020,  1021,  1022,  1023,  1024,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  -811,  1035,  1036,
    1040,  1043,  1045,  1047,  1049,  1051,  1075,  1076,  1124,  1077,
    1079,  1081,  1082,  1083,  1084,  1085,  1086,  1088,  -811,  -811,
    -811,  -811,  -811,  -811,  -242,  -811,  -811,   798,  -811,   878,
    -811,  -811,  -811,  -811,  -811,  -241,  -811,  -811,  -811,  -811,
    -811,  -233,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -230,  -811,   419,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -225,  -811,  -811,  -811,
    -811,  -811,  -215,  -811,  -811,  -811,  1144,   699,  1089,  1090,
    1091,  1092,  1096,  1152,  1097,  1099,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,   915,  1112,  1113,
    1114,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -209,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -182,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -181,  -811,
     151,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  1062,  -811,  -811,  -811,    -7,  -811,    -5,   419,  -811,
    1087,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  1080,  -811,    -4,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -170,  -811,   708,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -162,
    -811,  -811,  -811,  -811,  -811,   241,  -811,   362,   151,  -811,
    1124,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,   708,  -811,  1152,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   915,  -811,  -811,  -811,  -811,
    -811,  -811,  -811
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -811,  -811,  -811,  -402,  -340,  -810,  -424,  -811,  -811,  1115,
    -811,  -811,  -811,  -811,   991,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  1221,  -811,
    -811,  -811,  -811,  -811,  1116,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,   494,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -179,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -163,  -811,  -811,  -157,  -811,  -811,  -811,  -811,   689,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,   -87,  -811,
     802,  -811,  -811,  -811,    36,  -811,  -811,  -811,  -811,  -811,
     846,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,   -63,
    -811,  -811,   -59,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,   786,  -811,  -811,  -811,
    -811,  -811,  -811,   753,  -811,  -811,  -811,  -811,  -811,  -122,
    -811,  -811,  -811,   742,  -811,  -811,  -811,  -811,  -120,  -811,
    -811,  -811,  -811,   672,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -121,  -811,  -811,  -118,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   -62,  -811,   833,  -811,  -811,
    -811,  -811,  -811,   963,  -811,  -811,  -811,  -811,  1200,  -811,
    -811,  -811,  -811,  -811,  -811,   -36,  -811,   954,  -811,  -811,
    -811,  -811,  1142,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   110,  -811,  -811,  -811,   113,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,   892,  -811,
    -811,  -811,  -811,  -811,   -39,  -811,  -811,  -811,  -811,  -811,
     -34,  -811,  -811,  1237,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  1117,  -811,  -811,  -811,  -811,  -811,
    -811,  -811
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     583,   584,   731,   367,  1223,    67,  1229,   590,   274,   285,
    1216,   557,   122,   566,  1217,   493,  1218,  1360,  1364,   525,
    1219,  1361,  1365,    47,   128,   525,  1366,   274,   115,  1369,
    1367,   129,   130,  1370,  1382,   131,   118,   679,  1383,   681,
     526,    68,   132,   122,  1384,    48,   526,    52,  1385,   286,
    1434,   133,    69,   695,  1435,   134,   135,    54,  1049,  1050,
    1051,   703,   136,   484,   287,    59,   137,   138,   139,   494,
     140,    60,   714,   715,  1259,   717,   141,  1436,  1439,   357,
     434,  1437,  1440,   435,   728,   729,   288,   732,   289,  1455,
     290,   291,    63,  1456,    64,   142,   143,  1474,   449,   495,
     144,  1475,   123,   484,   357,   496,   799,   145,   121,   292,
     800,   146,   147,   148,    45,    46,   149,   450,   127,   150,
     151,   557,   243,   451,   368,   436,    70,   275,   437,   152,
     566,   801,   558,   123,   567,   153,   154,   244,   155,   156,
     157,   158,   159,   802,   527,   245,   275,   452,   453,   246,
     527,   284,   454,   160,   493,   803,   281,   276,   327,   369,
     804,  1441,   161,  1442,   162,   163,   455,   164,   497,   358,
     165,   166,   805,   456,   167,   528,   276,   730,  1443,   806,
     328,   528,  1444,   438,   807,   168,   808,   367,   370,  1189,
    1190,  1224,   457,  1230,   358,   329,   559,   330,   568,   809,
     858,   439,   331,   285,   169,   332,   170,   335,   494,   336,
     171,   722,   723,   302,   172,   173,   174,   175,   176,   485,
     458,   337,   177,   178,   724,   725,  1260,   810,   459,   338,
    1261,   179,   811,   339,   340,   359,   504,   341,   495,  1220,
    1221,  1222,   558,   286,   496,   342,   460,   343,   486,   303,
     344,   567,   345,   346,   812,   461,   462,   560,   287,   485,
     359,   347,   676,   180,   333,   181,   813,   522,   814,   815,
     626,   182,   627,   816,   775,   628,   183,    76,   850,   629,
     288,   184,   289,   432,   290,   291,   463,   464,   486,    77,
     519,   348,   349,   302,   630,   631,   632,   350,   304,   597,
     633,   351,   365,   292,   543,   352,   559,   497,   368,   487,
      78,    79,   355,   356,   524,   568,    80,   364,    81,   634,
     376,   598,   599,   635,   636,   377,   440,   378,   600,   303,
     379,   380,   381,   817,   305,  1296,   306,   307,   669,   744,
     818,   576,   434,   369,   465,   435,   382,   383,   384,   487,
      67,   819,   820,   385,   637,   386,   638,   763,   387,   573,
     388,   821,   768,   389,   574,  1138,   390,   560,   247,   639,
     391,   392,   370,   393,    82,    83,   394,   395,   304,   308,
     876,   309,   575,    84,    85,   396,    68,   436,   397,   881,
     437,   640,  1445,   398,   310,   399,   400,    69,   401,  1061,
     402,   403,   404,   405,    86,    87,   406,   601,   602,   603,
     407,  1297,   604,   577,   305,  1267,   306,   307,   408,   410,
     605,    88,    89,   641,   248,   249,   250,   251,   252,   253,
     254,   255,    90,   606,   607,   412,   413,   642,   311,  1371,
    1372,    91,   414,  1298,   415,   438,   416,   643,   578,   417,
     608,   609,   418,   419,   420,   421,  1311,   422,  1299,   308,
     423,   309,   541,   439,   579,   424,   312,   313,   425,   426,
    1373,    70,   256,   427,   310,   610,   428,   429,  1300,  1301,
     430,   431,   505,   506,  1302,  1303,  1304,  1305,  1374,  1169,
    1170,  1171,  1172,  1173,   507,  1375,   508,  1306,   582,   509,
    1186,   510,   511,   580,   512,   513,   514,   257,   515,   516,
     644,   520,   521,   534,  1376,   535,   536,   537,   311,   538,
     539,   540,   544,   645,   545,    92,    93,    94,   546,   947,
     547,   581,  1312,   548,   549,   550,   353,   891,   892,   893,
     894,   895,  1377,   551,   552,   553,   312,   313,   554,   128,
    1378,   582,   555,   585,   247,   586,   129,   130,   925,   587,
     131,   589,   588,   596,  1313,   591,   592,   132,   593,   594,
     595,   667,   668,   672,  1176,   673,   133,   678,   671,  1314,
     134,   135,  1184,  1185,   674,   258,   680,   136,   440,   682,
    1379,   137,   138,   139,   683,   140,   684,   685,   686,  1315,
    1316,   141,   687,   688,   689,  1317,  1318,  1319,  1320,  1380,
     248,   249,   250,   251,   252,   253,   254,   255,  1321,   259,
     142,   143,   690,   691,   692,   144,   693,   517,   694,   696,
     697,   799,   145,   698,   699,   800,   146,   147,   148,   700,
     701,   149,   702,   704,   150,   151,   705,   706,   707,   708,
     709,   449,   718,   710,   152,   711,   801,   712,   256,   713,
     153,   154,   716,   155,   156,   157,   158,   159,   802,   719,
     450,   720,   721,   726,   727,   730,   451,   733,   160,   734,
     803,   735,   736,   737,   746,   804,   770,   161,   777,   162,
     163,   739,   164,   257,   778,   165,   166,   805,   740,   167,
     452,   453,   742,   743,   806,   454,   747,   748,   749,   807,
     168,   808,   750,  1457,   752,   753,   779,   754,   780,   455,
     755,   756,   757,   781,   809,   782,   456,   758,   783,   169,
     759,   170,   784,   760,   761,   171,   762,   792,   793,   172,
     173,   174,   175,   176,   765,   457,  1458,   177,   178,   767,
     772,   773,   810,   794,   795,   796,   179,   811,  1459,   785,
     786,   787,   788,   789,   790,   791,   774,   797,   847,   855,
     798,   258,   852,   458,   848,  1460,   846,   853,   859,   812,
     849,   459,  1461,   854,   856,   857,   860,  1462,   180,  1463,
     181,   813,   861,   814,   815,   626,   182,   627,   816,   460,
     628,   183,  1464,   862,   629,   259,   184,   863,   461,   462,
     864,   865,   866,   867,   868,   869,   870,   871,   872,   630,
     631,   632,    76,  1078,   597,   633,   873,   875,   878,   879,
     883,   884,  1091,   885,    77,  1465,  1174,   886,   887,   463,
     464,   949,   912,   888,   634,   889,   598,   599,   635,   636,
     890,  1466,   898,   600,   899,    78,    79,   900,   817,   913,
     901,    80,   902,    81,   903,   818,   904,   905,   906,  1467,
     907,  1468,  1469,   950,   908,   909,   819,   820,   910,   637,
     911,   638,   914,   927,   915,   916,   821,   917,   918,   919,
     920,   921,   951,   952,   639,     2,     3,   465,   922,   923,
       4,   924,   928,   929,   930,   931,   932,   933,   934,   935,
     953,   936,   954,   938,  1266,   939,   640,     5,   956,    82,
      83,     6,  1064,  1062,     7,   940,   941,   942,    84,    85,
     943,     8,   601,   602,   603,   944,  1470,   604,   945,   946,
     955,   957,   958,   959,   960,   605,   961,     9,   641,    86,
      87,   962,   963,   964,  1471,   965,   966,   967,   606,   607,
      10,    11,   642,    12,  1472,   968,    88,    89,   969,   970,
      13,   971,   643,   972,   973,   608,   609,    90,   974,   975,
     976,   977,   978,   979,   980,   981,    91,    14,   982,   983,
     984,   985,   986,   987,   988,   989,  1011,    15,  1033,    16,
     610,   990,   991,   992,   993,   994,  1034,   995,   996,  1035,
     997,   998,   999,  1036,  1060,  1000,    17,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1001,  1002,  1003,  1045,  1004,
    1005,  1006,  1046,    18,  1007,   644,  1047,  1008,  1048,  1054,
    1055,  1056,  1057,  1058,  1059,  1065,  1067,  1066,   645,  1063,
    1069,  1068,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1079,  1080,  1081,  1082,  1083,    19,  1084,  1086,  1085,  1087,
      92,    93,    94,  1088,    20,    21,  1089,  1090,  1094,    22,
      23,  1012,  1013,  1014,  1015,  1016,  1095,  1017,  1018,  1096,
    1019,  1020,  1021,  1097,  1098,  1022,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1023,  1024,  1025,  1108,  1026,
    1027,  1028,  1109,  1116,  1029,  1140,  1110,  1030,  1410,  1411,
    1412,  1413,  1414,  1111,  1415,  1416,  1112,  1417,  1418,  1419,
    1113,  1114,  1420,  1115,  1141,  1117,  1142,  1118,  1119,  1121,
    1143,  1122,  1421,  1422,  1423,  1123,  1424,  1425,  1426,  1124,
    1125,  1427,  1162,  1126,  1428,  1127,  1128,  1164,  1166,  1129,
    1130,  1131,  1132,  1133,  1135,  1136,  1175,  1177,  1144,  1137,
    1178,  1179,  1145,  1146,  1180,  1147,  1148,  1149,  1150,  1151,
    1181,  1182,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1183,  1165,  1188,  1163,  1168,  1167,  1187,  1192,
    1191,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1239,
    1211,  1212,  1213,  1227,  1228,  1233,  1234,  1235,  1236,  1237,
    1238,  1243,  1244,  1245,  1246,  1247,  1248,  1249,  1269,  1250,
    1255,  1251,  1252,  1253,  1254,  1258,  1264,  1265,  1270,  1279,
    1281,  1273,  1271,  1285,  1287,  1289,  1347,  1272,  1291,  1274,
    1275,  1276,  1277,  1278,  1280,  1282,  1283,  1284,  1286,  1288,
    1290,  1292,  1293,  1294,  1295,  1309,  1310,  1386,  1324,  1325,
    1326,  1327,  1328,  1329,  1393,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,   334,  1481,  1337,  1338,  1482,  1480,  1453,  1339,
     926,   776,  1340,  1387,  1341,   556,  1342,  1451,  1343,  1450,
    1344,   882,   764,  1476,   877,   851,  1139,  1477,   948,  1479,
    1478,  1452,   769,   670,   366,  1447,   677,   433,  1449,  1363,
    1362,  1448,   354,   745,  1345,  1346,  1351,     0,  1352,     0,
    1353,  1354,  1355,  1356,  1357,  1358,     0,  1359,  1388,  1389,
    1390,  1391,     0,     0,     0,  1392,  1397,     0,  1398,     0,
    1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,
    1409,  1431,  1432,  1433,     0,     0,   518,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     542
};

static const yytype_int16 yycheck[] =
{
     340,   341,   426,     1,    11,     1,    11,   347,     1,     1,
     259,     1,     1,     1,   263,     1,   259,   259,   259,     1,
     263,   263,   263,   261,     1,     1,   259,     1,   155,   259,
     263,     8,     9,   263,   259,    12,   155,   377,   263,   379,
      22,    37,    19,     1,   259,   261,    22,   261,   263,    41,
     259,    28,    48,   393,   263,    32,    33,   261,    14,    15,
      16,   401,    39,     1,    56,   261,    43,    44,    45,    55,
      47,   261,   412,   413,    78,   415,    53,   259,   259,     1,
       1,   263,   263,     4,   424,   425,    78,   427,    80,   259,
      82,    83,   261,   263,   261,    72,    73,   259,     1,    85,
      77,   263,    91,     1,     1,    91,     1,    84,   261,   101,
       5,    88,    89,    90,   259,   260,    93,    20,   261,    96,
      97,     1,   261,    26,   122,    46,   122,   120,    49,   106,
       1,    26,   122,    91,   122,   112,   113,   261,   115,   116,
     117,   118,   119,    38,   126,   261,   120,    50,    51,   261,
     126,   261,    55,   130,     1,    50,   155,   150,   261,   157,
      55,    10,   139,    12,   141,   142,    69,   144,   154,    91,
     147,   148,    67,    76,   151,   157,   150,   133,    27,    74,
     261,   157,    31,   104,    79,   162,    81,     1,   186,   215,
     216,   198,    95,   198,    91,   259,   186,   262,   186,    94,
     540,   122,   262,     1,   181,   262,   183,   262,    55,   262,
     187,   196,   197,     1,   191,   192,   193,   194,   195,   157,
     123,   262,   199,   200,   196,   197,   230,   122,   131,   262,
     234,   208,   127,   262,   262,   157,   259,   262,    85,  1049,
    1050,  1051,   122,    41,    91,   262,   149,   262,   186,    37,
     262,   122,   262,   262,   149,   158,   159,   247,    56,   157,
     157,   262,   260,   240,   260,   242,   161,   260,   163,   164,
       1,   248,     3,   168,   260,     6,   253,     1,   260,    10,
      78,   258,    80,   260,    82,    83,   189,   190,   186,    13,
     259,   262,   262,     1,    25,    26,    27,   262,    86,     1,
      31,   262,   260,   101,   259,   262,   186,   154,   122,   247,
      34,    35,   261,   261,   261,   186,    40,   262,    42,    50,
     262,    23,    24,    54,    55,   262,   247,   262,    30,    37,
     262,   262,   262,   228,   122,    94,   124,   125,   260,   260,
     235,   259,     1,   157,   247,     4,   262,   262,   262,   247,
       1,   246,   247,   262,    85,   262,    87,   260,   262,   155,
     262,   256,   260,   262,   155,   260,   262,   247,     1,   100,
     262,   262,   186,   262,    98,    99,   262,   262,    86,   167,
     260,   169,   155,   107,   108,   262,    37,    46,   262,   260,
      49,   122,   241,   262,   182,   262,   262,    48,   262,   739,
     262,   262,   262,   262,   128,   129,   262,   109,   110,   111,
     262,   170,   114,   196,   122,   263,   124,   125,   262,   262,
     122,   145,   146,   154,    57,    58,    59,    60,    61,    62,
      63,    64,   156,   135,   136,   262,   262,   168,   226,    20,
      21,   165,   262,   202,   262,   104,   262,   178,   133,   262,
     152,   153,   262,   262,   262,   262,    94,   262,   217,   167,
     262,   169,   260,   122,   133,   262,   254,   255,   262,   262,
      51,   122,   105,   262,   182,   177,   262,   262,   237,   238,
     262,   262,   262,   262,   243,   244,   245,   246,    69,   891,
     892,   893,   894,   895,   262,    76,   262,   256,   133,   262,
     924,   262,   262,   196,   262,   262,   262,   140,   262,   262,
     241,   262,   262,   262,    95,   262,   262,   262,   226,   262,
     262,   262,   262,   254,   262,   249,   250,   251,   262,   260,
     262,   196,   170,   262,   262,   262,   260,   172,   173,   174,
     175,   176,   123,   262,   262,   262,   254,   255,   262,     1,
     131,   133,   260,   133,     1,   133,     8,     9,   260,   196,
      12,   133,   196,   259,   202,   196,   196,    19,   196,   196,
     196,   262,   262,   259,   914,   262,    28,   196,   155,   217,
      32,    33,   922,   923,   262,   218,   196,    39,   247,   133,
     171,    43,    44,    45,   155,    47,   133,   196,   196,   237,
     238,    53,   196,   133,   155,   243,   244,   245,   246,   190,
      57,    58,    59,    60,    61,    62,    63,    64,   256,   252,
      72,    73,   196,   133,   133,    77,   133,   260,   196,   196,
     196,     1,    84,   133,   155,     5,    88,    89,    90,   196,
     133,    93,   133,   133,    96,    97,   133,   155,   133,   133,
     196,     1,   155,   196,   106,   262,    26,   196,   105,   262,
     112,   113,   196,   115,   116,   117,   118,   119,    38,   196,
      20,   196,   196,   196,   196,   133,    26,   196,   130,   196,
      50,   196,   196,   259,   259,    55,   259,   139,   155,   141,
     142,   262,   144,   140,   155,   147,   148,    67,   262,   151,
      50,    51,   262,   262,    74,    55,   262,   262,   262,    79,
     162,    81,   262,     5,   262,   262,   155,   262,   155,    69,
     262,   262,   262,   155,    94,   155,    76,   262,   155,   181,
     262,   183,   155,   262,   262,   187,   262,   155,   155,   191,
     192,   193,   194,   195,   262,    95,    38,   199,   200,   262,
     262,   262,   122,   196,   259,   155,   208,   127,    50,   219,
     220,   221,   222,   223,   224,   225,   262,   155,   262,   155,
     259,   218,   196,   123,   262,    67,   259,   196,   259,   149,
     262,   131,    74,   196,   196,   196,   155,    79,   240,    81,
     242,   161,   196,   163,   164,     1,   248,     3,   168,   149,
       6,   253,    94,   155,    10,   252,   258,   155,   158,   159,
     155,   155,   155,   155,   133,   155,   155,   259,   259,    25,
      26,    27,     1,   133,     1,    31,   262,   262,   259,   262,
     259,   259,   133,   259,    13,   127,   133,   259,   259,   189,
     190,   155,   262,   259,    50,   259,    23,    24,    54,    55,
     259,   143,   259,    30,   259,    34,    35,   259,   228,   262,
     259,    40,   259,    42,   259,   235,   259,   259,   259,   161,
     259,   163,   164,   155,   259,   259,   246,   247,   259,    85,
     259,    87,   262,   259,   262,   262,   256,   262,   262,   262,
     262,   262,   259,   259,   100,     0,     1,   247,   262,   262,
       5,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     155,   262,   155,   262,   201,   262,   122,    22,   259,    98,
      99,    26,   155,   196,    29,   262,   262,   262,   107,   108,
     262,    36,   109,   110,   111,   262,   228,   114,   262,   262,
     262,   259,   259,   259,   259,   122,   259,    52,   154,   128,
     129,   259,   259,   259,   246,   259,   259,   259,   135,   136,
      65,    66,   168,    68,   256,   259,   145,   146,   259,   259,
      75,   259,   178,   259,   259,   152,   153,   156,   259,   259,
     259,   259,   259,   259,   259,   259,   165,    92,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   102,   259,   104,
     177,   203,   204,   205,   206,   207,   259,   209,   210,   259,
     212,   213,   214,   259,   262,   217,   121,   259,   259,   259,
     259,   259,   259,   259,   259,   227,   228,   229,   259,   231,
     232,   233,   259,   138,   236,   241,   259,   239,   259,   259,
     259,   259,   259,   259,   259,   155,   196,   259,   254,   262,
     196,   155,   196,   262,   196,   196,   196,   196,   196,   155,
     155,   155,   196,   155,   259,   170,   155,   155,   262,   259,
     249,   250,   251,   262,   179,   180,   155,   155,   259,   184,
     185,   203,   204,   205,   206,   207,   259,   209,   210,   259,
     212,   213,   214,   259,   259,   217,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   227,   228,   229,   259,   231,
     232,   233,   259,   262,   236,   155,   259,   239,   203,   204,
     205,   206,   207,   259,   209,   210,   259,   212,   213,   214,
     259,   259,   217,   259,   155,   262,   155,   262,   262,   262,
     259,   262,   227,   228,   229,   262,   231,   232,   233,   262,
     262,   236,   155,   262,   239,   262,   262,   155,   155,   262,
     262,   262,   262,   262,   262,   262,   133,   133,   259,   262,
     133,   133,   259,   259,   133,   259,   259,   259,   259,   259,
     155,   133,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   133,   259,   155,   262,   259,   262,   259,   155,
     196,   155,   196,   196,   196,   155,   262,   155,   155,   155,
     155,   133,   155,   155,   196,   155,   259,   259,   259,   132,
     259,   259,   160,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   196,   259,
     160,   259,   259,   259,   259,   259,   259,   259,   155,   155,
     155,   262,   196,   155,   262,   155,   132,   196,   259,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   259,   259,   259,   259,   259,   259,   133,   259,   259,
     259,   259,   259,   259,   132,   259,   259,   259,   259,   259,
     259,   259,    71,  1456,   259,   259,  1475,  1454,  1385,   259,
     611,   499,   259,  1267,   259,   314,   259,  1370,   259,  1368,
     259,   569,   466,  1435,   561,   529,   822,  1437,   646,  1440,
    1438,  1383,   489,   360,   124,  1361,   372,   185,  1367,  1219,
    1217,  1365,    95,   441,   259,   259,   259,    -1,   259,    -1,
     259,   259,   259,   259,   259,   259,    -1,   259,   259,   259,
     259,   259,    -1,    -1,    -1,   259,   259,    -1,   259,    -1,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     293
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   265,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   102,   104,   121,   138,   170,
     179,   180,   184,   185,   266,   271,   276,   290,   296,   311,
     348,   367,   381,   407,   414,   424,   433,   464,   474,   480,
     484,   494,   559,   575,   596,   259,   260,   261,   261,   349,
     434,   475,   261,   485,   261,   560,   382,   465,   368,   261,
     261,   312,   408,   261,   261,   415,   425,     1,    37,    48,
     122,   291,   292,   293,   294,   295,     1,    13,    34,    35,
      40,    42,    98,    99,   107,   108,   128,   129,   145,   146,
     156,   165,   249,   250,   251,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   155,   350,   354,   155,   435,
     439,   261,     1,    91,   481,   482,   483,   261,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   106,   112,   113,   115,   116,   117,   118,   119,
     130,   139,   141,   142,   144,   147,   148,   151,   162,   181,
     183,   187,   191,   192,   193,   194,   195,   199,   200,   208,
     240,   242,   248,   253,   258,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   550,   554,   555,
     556,   557,   558,   261,   261,   261,   261,     1,    57,    58,
      59,    60,    61,    62,    63,    64,   105,   140,   218,   252,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,     1,   120,   150,   272,   273,   274,
     275,   155,   313,   317,   261,     1,    41,    56,    78,    80,
      82,    83,   101,   597,   598,   599,   600,   601,   602,   603,
     604,   605,     1,    37,    86,   122,   124,   125,   167,   169,
     182,   226,   254,   255,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   261,   261,   259,
     262,   262,   262,   260,   292,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   260,   577,   261,   261,     1,    91,   157,
     476,   477,   478,   479,   262,   260,   482,     1,   122,   157,
     186,   486,   490,   491,   492,   493,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   551,
     262,   547,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   260,   496,     1,     4,    46,    49,   104,   122,
     247,   561,   562,   563,   564,   565,   569,   570,   571,     1,
      20,    26,    50,    51,    55,    69,    76,    95,   123,   131,
     149,   158,   159,   189,   190,   247,   383,   384,   385,   386,
     387,   388,   389,   390,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,     1,   157,   186,   247,   466,   470,
     471,   472,   473,     1,    55,    85,    91,   154,   369,   373,
     374,   375,   379,   380,   259,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   260,   298,   259,
     262,   262,   260,   273,   261,     1,    22,   126,   157,   409,
     410,   411,   412,   413,   262,   262,   262,   262,   262,   262,
     262,   260,   598,   259,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   260,   278,     1,   122,   186,
     247,   416,   417,   418,   419,   420,     1,   122,   186,   426,
     427,   428,   429,   155,   155,   155,   259,   196,   133,   133,
     196,   196,   133,   268,   268,   133,   133,   196,   196,   133,
     268,   196,   196,   196,   196,   196,   259,     1,    23,    24,
      30,   109,   110,   111,   114,   122,   135,   136,   152,   153,
     177,   351,   352,   353,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,     1,     3,     6,    10,
      25,    26,    27,    31,    50,    54,    55,    85,    87,   100,
     122,   154,   168,   178,   241,   254,   436,   437,   438,   440,
     441,   442,   443,   444,   445,   446,   447,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   262,   262,   260,
     477,   155,   259,   262,   262,   487,   260,   491,   196,   268,
     196,   268,   133,   155,   133,   196,   196,   196,   133,   155,
     196,   133,   133,   133,   196,   268,   196,   196,   133,   155,
     196,   133,   133,   268,   133,   133,   155,   133,   133,   196,
     196,   262,   196,   262,   268,   268,   196,   268,   155,   196,
     196,   196,   196,   197,   196,   197,   196,   196,   268,   268,
     133,   270,   268,   196,   196,   196,   196,   259,   572,   262,
     262,   566,   262,   262,   260,   562,   259,   262,   262,   262,
     262,   391,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   260,   384,   262,   467,   262,   260,   471,
     259,   370,   262,   262,   262,   260,   374,   155,   155,   155,
     155,   155,   155,   155,   155,   219,   220,   221,   222,   223,
     224,   225,   155,   155,   196,   259,   155,   155,   259,     1,
       5,    26,    38,    50,    55,    67,    74,    79,    81,    94,
     122,   127,   149,   161,   163,   164,   168,   228,   235,   246,
     247,   256,   314,   315,   316,   318,   319,   320,   321,   322,
     323,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   259,   262,   262,   262,
     260,   410,   196,   196,   196,   155,   196,   196,   268,   259,
     155,   196,   155,   155,   155,   155,   155,   155,   133,   155,
     155,   259,   259,   262,   421,   262,   260,   417,   259,   262,
     430,   260,   427,   259,   259,   259,   259,   259,   259,   259,
     259,   172,   173,   174,   175,   176,   267,   268,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   260,   352,   259,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   448,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   260,   437,   155,
     155,   259,   259,   155,   155,   262,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     203,   204,   205,   206,   207,   209,   210,   212,   213,   214,
     217,   227,   228,   229,   231,   232,   233,   236,   239,   552,
     553,   259,   203,   204,   205,   206,   207,   209,   210,   212,
     213,   214,   217,   227,   228,   229,   231,   232,   233,   236,
     239,   548,   549,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,    14,
      15,    16,   269,   270,   259,   259,   259,   259,   259,   259,
     262,   268,   196,   262,   155,   155,   259,   196,   155,   196,
     196,   262,   196,   196,   196,   196,   196,   155,   133,   155,
     155,   196,   155,   259,   155,   262,   155,   259,   262,   155,
     155,   133,   377,   378,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   262,   262,   262,   262,
     342,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   324,   262,   262,   262,   260,   315,
     155,   155,   155,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   155,   262,   155,   259,   155,   262,   259,   267,
     267,   267,   267,   267,   133,   133,   268,   133,   133,   133,
     133,   155,   133,   133,   268,   268,   270,   259,   155,   215,
     216,   196,   155,   155,   196,   196,   196,   155,   262,   155,
     155,   155,   155,   133,   155,   155,   196,   155,   259,   259,
     259,   259,   259,   160,   488,   489,   259,   263,   259,   263,
     269,   269,   269,    11,   198,   573,   574,   259,   259,    11,
     198,   567,   568,   259,   259,   259,   259,   259,   259,   132,
     392,   393,   395,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   160,   468,   469,   259,    78,
     230,   234,   371,   372,   259,   259,   201,   263,   376,   196,
     155,   196,   196,   262,   196,   196,   196,   196,   196,   155,
     196,   155,   196,   196,   196,   155,   196,   262,   196,   155,
     196,   259,   259,   259,   259,   259,    94,   170,   202,   217,
     237,   238,   243,   244,   245,   246,   256,   422,   423,   259,
     259,    94,   170,   202,   217,   237,   238,   243,   244,   245,
     246,   256,   431,   432,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   132,   449,   450,
     452,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   263,   553,   549,   259,   263,   259,   263,   394,   259,
     263,    20,    21,    51,    69,    76,    95,   123,   131,   171,
     190,   396,   259,   263,   259,   263,   133,   378,   259,   259,
     259,   259,   259,   132,   343,   344,   346,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     203,   204,   205,   206,   207,   209,   210,   212,   213,   214,
     217,   227,   228,   229,   231,   232,   233,   236,   239,   325,
     326,   259,   259,   259,   259,   263,   259,   263,   451,   259,
     263,    10,    12,    27,    31,   241,   453,   489,   574,   568,
     396,   393,   469,   372,   345,   259,   263,     5,    38,    50,
      67,    74,    79,    81,    94,   127,   143,   161,   163,   164,
     228,   246,   256,   347,   259,   263,   423,   432,   453,   450,
     347,   344,   326
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
#line 425 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
#line 447 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
#line 452 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
#line 470 "ircd_parser.y"
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
#line 487 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 511 "ircd_parser.y"
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
#line 545 "ircd_parser.y"
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
#line 605 "ircd_parser.y"
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
#line 619 "ircd_parser.y"
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
#line 634 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 643 "ircd_parser.y"
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
#line 657 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 666 "ircd_parser.y"
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
#line 694 "ircd_parser.y"
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
#line 724 "ircd_parser.y"
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
#line 747 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      ServerInfo.hub = 1;
      delete_capability("HUB");
      add_capability("HUB", CAP_HUB, 1);
    }
    else if (ServerInfo.hub)
    {

      ServerInfo.hub = 0;
      delete_capability("HUB");
    }
  }
}
    break;

  case 81:
#line 775 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 784 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 793 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 820 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 824 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 828 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 835 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 842 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 849 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 856 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 863 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 870 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 877 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 884 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 888 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 892 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 896 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 900 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 904 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 908 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 914 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 923 "ircd_parser.y"
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
#line 936 "ircd_parser.y"
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
#line 1028 "ircd_parser.y"
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
#line 1040 "ircd_parser.y"
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
#line 1052 "ircd_parser.y"
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
#line 1086 "ircd_parser.y"
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
#line 1098 "ircd_parser.y"
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
#line 1109 "ircd_parser.y"
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
#line 1151 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1160 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1167 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1171 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1175 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 161:
#line 1179 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 162:
#line 1183 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 163:
#line 1187 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 164:
#line 1191 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 165:
#line 1195 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 166:
#line 1199 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 167:
#line 1203 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 168:
#line 1207 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 169:
#line 1211 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 170:
#line 1215 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 171:
#line 1219 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 172:
#line 1223 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 173:
#line 1227 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 174:
#line 1231 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 175:
#line 1235 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 176:
#line 1239 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 177:
#line 1245 "ircd_parser.y"
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
#line 1256 "ircd_parser.y"
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
#line 1267 "ircd_parser.y"
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
#line 1278 "ircd_parser.y"
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
#line 1289 "ircd_parser.y"
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
#line 1300 "ircd_parser.y"
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
#line 1311 "ircd_parser.y"
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
#line 1322 "ircd_parser.y"
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
#line 1333 "ircd_parser.y"
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
#line 1344 "ircd_parser.y"
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
#line 1355 "ircd_parser.y"
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
#line 1366 "ircd_parser.y"
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
#line 1377 "ircd_parser.y"
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
#line 1388 "ircd_parser.y"
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
#line 1399 "ircd_parser.y"
    {
}
    break;

  case 195:
#line 1403 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 197:
#line 1404 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 199:
#line 1407 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 200:
#line 1414 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 201:
#line 1421 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 202:
#line 1428 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 203:
#line 1435 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 204:
#line 1442 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 205:
#line 1449 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 206:
#line 1456 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 207:
#line 1463 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 208:
#line 1470 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 209:
#line 1477 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 210:
#line 1484 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 211:
#line 1491 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 212:
#line 1498 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 213:
#line 1505 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 214:
#line 1512 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 215:
#line 1525 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 216:
#line 1532 "ircd_parser.y"
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
#line 1592 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1601 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 237:
#line 1610 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
#line 1616 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
#line 1622 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
#line 1628 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
#line 1634 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
#line 1640 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
#line 1646 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
#line 1652 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
#line 1658 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
#line 1664 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
#line 1670 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
#line 1676 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
#line 1685 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 250:
#line 1692 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 251:
#line 1701 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 255:
#line 1707 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 256:
#line 1711 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 257:
#line 1715 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 265:
#line 1725 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 269:
#line 1730 "ircd_parser.y"
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

  case 270:
#line 1744 "ircd_parser.y"
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

  case 271:
#line 1764 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 272:
#line 1773 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 273:
#line 1785 "ircd_parser.y"
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

  case 274:
#line 1797 "ircd_parser.y"
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

  case 294:
#line 1862 "ircd_parser.y"
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

  case 295:
#line 1899 "ircd_parser.y"
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

  case 296:
#line 1912 "ircd_parser.y"
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

  case 297:
#line 1923 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 298:
#line 1932 "ircd_parser.y"
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

  case 299:
#line 1943 "ircd_parser.y"
    {
}
    break;

  case 303:
#line 1947 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 305:
#line 1948 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 307:
#line 1951 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 308:
#line 1959 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 309:
#line 1966 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 310:
#line 1973 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 311:
#line 1980 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 312:
#line 1987 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 313:
#line 1994 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 314:
#line 2001 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 315:
#line 2008 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 316:
#line 2015 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 317:
#line 2024 "ircd_parser.y"
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

  case 318:
#line 2035 "ircd_parser.y"
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

  case 319:
#line 2046 "ircd_parser.y"
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

  case 320:
#line 2057 "ircd_parser.y"
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

  case 321:
#line 2068 "ircd_parser.y"
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

  case 322:
#line 2079 "ircd_parser.y"
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

  case 323:
#line 2091 "ircd_parser.y"
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

  case 324:
#line 2110 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 325:
#line 2120 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 326:
#line 2129 "ircd_parser.y"
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

  case 327:
#line 2144 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 328:
#line 2151 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 335:
#line 2163 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 336:
#line 2172 "ircd_parser.y"
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

  case 337:
#line 2187 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 338:
#line 2200 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 339:
#line 2208 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 346:
#line 2219 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 347:
#line 2228 "ircd_parser.y"
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

  case 348:
#line 2250 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 352:
#line 2257 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 353:
#line 2261 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 354:
#line 2265 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 355:
#line 2269 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 356:
#line 2273 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 357:
#line 2277 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 358:
#line 2281 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 359:
#line 2285 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 360:
#line 2289 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 361:
#line 2293 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 362:
#line 2297 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 363:
#line 2306 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 364:
#line 2313 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 370:
#line 2326 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 371:
#line 2332 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 375:
#line 2339 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 376:
#line 2343 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 377:
#line 2347 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 378:
#line 2351 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 379:
#line 2355 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 380:
#line 2359 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 381:
#line 2363 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 382:
#line 2367 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 383:
#line 2371 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 384:
#line 2375 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 385:
#line 2379 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 386:
#line 2388 "ircd_parser.y"
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

  case 387:
#line 2406 "ircd_parser.y"
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

  case 412:
#line 2545 "ircd_parser.y"
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
#line 2557 "ircd_parser.y"
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

  case 414:
#line 2569 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 415:
#line 2578 "ircd_parser.y"
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

  case 416:
#line 2604 "ircd_parser.y"
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

  case 417:
#line 2622 "ircd_parser.y"
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

  case 418:
#line 2640 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 419:
#line 2646 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 420:
#line 2650 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 421:
#line 2658 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 422:
#line 2667 "ircd_parser.y"
    {
}
    break;

  case 426:
#line 2671 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 428:
#line 2672 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 430:
#line 2675 "ircd_parser.y"
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
#line 2686 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 432:
#line 2693 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 433:
#line 2700 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 434:
#line 2707 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 435:
#line 2717 "ircd_parser.y"
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
#line 2758 "ircd_parser.y"
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
#line 2769 "ircd_parser.y"
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
#line 2780 "ircd_parser.y"
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
#line 2795 "ircd_parser.y"
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
#line 2806 "ircd_parser.y"
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
#line 2817 "ircd_parser.y"
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
#line 2830 "ircd_parser.y"
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
#line 2843 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 444:
#line 2852 "ircd_parser.y"
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
#line 2887 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 446:
#line 2894 "ircd_parser.y"
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
#line 2951 "ircd_parser.y"
    {
}
    break;

  case 451:
#line 2956 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 458:
#line 2965 "ircd_parser.y"
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
#line 2984 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 460:
#line 2993 "ircd_parser.y"
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
#line 3002 "ircd_parser.y"
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
#line 3018 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 468:
#line 3027 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 474:
#line 3044 "ircd_parser.y"
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
#line 3065 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 476:
#line 3072 "ircd_parser.y"
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
#line 3107 "ircd_parser.y"
    {
}
    break;

  case 481:
#line 3112 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 488:
#line 3121 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 489:
#line 3127 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 550:
#line 3172 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 551:
#line 3177 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 552:
#line 3182 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 553:
#line 3187 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 554:
#line 3192 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 555:
#line 3197 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 556:
#line 3202 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 557:
#line 3207 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 558:
#line 3212 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 559:
#line 3217 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 560:
#line 3222 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 561:
#line 3227 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 562:
#line 3232 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 563:
#line 3237 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 564:
#line 3242 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 565:
#line 3247 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 566:
#line 3252 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 567:
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 568:
#line 3262 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 569:
#line 3268 "ircd_parser.y"
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

  case 570:
#line 3279 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 571:
#line 3284 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 572:
#line 3293 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 573:
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 574:
#line 3303 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 575:
#line 3308 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 576:
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 577:
#line 3318 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 578:
#line 3321 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 579:
#line 3326 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 580:
#line 3329 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 581:
#line 3334 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:
#line 3339 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:
#line 3344 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 584:
#line 3349 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:
#line 3354 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 586:
#line 3359 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 587:
#line 3364 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 588:
#line 3369 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 589:
#line 3374 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 590:
#line 3385 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:
#line 3390 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:
#line 3395 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 593:
#line 3400 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 594:
#line 3409 "ircd_parser.y"
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

  case 595:
#line 3441 "ircd_parser.y"
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

  case 596:
#line 3459 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 597:
#line 3464 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 598:
#line 3473 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 599:
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 600:
#line 3483 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 601:
#line 3488 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 605:
#line 3494 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 606:
#line 3497 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 607:
#line 3500 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 608:
#line 3503 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 609:
#line 3506 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 610:
#line 3509 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 611:
#line 3512 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 612:
#line 3515 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 613:
#line 3518 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 614:
#line 3521 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 615:
#line 3524 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 616:
#line 3527 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 617:
#line 3530 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 618:
#line 3533 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 619:
#line 3536 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 620:
#line 3539 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 621:
#line 3542 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 622:
#line 3545 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 623:
#line 3548 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 624:
#line 3553 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 628:
#line 3559 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 629:
#line 3562 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 630:
#line 3565 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 631:
#line 3568 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 632:
#line 3571 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 633:
#line 3574 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 634:
#line 3577 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 635:
#line 3580 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 636:
#line 3583 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 637:
#line 3586 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 638:
#line 3589 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 639:
#line 3592 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 640:
#line 3595 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 641:
#line 3598 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 642:
#line 3601 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 643:
#line 3604 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 644:
#line 3607 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 645:
#line 3610 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 646:
#line 3613 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 647:
#line 3618 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:
#line 3623 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 649:
#line 3628 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 650:
#line 3633 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 651:
#line 3638 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 652:
#line 3646 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 653:
#line 3653 "ircd_parser.y"
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

  case 663:
#line 3679 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 664:
#line 3685 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 665:
#line 3691 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 669:
#line 3697 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 670:
#line 3701 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 671:
#line 3707 "ircd_parser.y"
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

  case 672:
#line 3741 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 673:
#line 3750 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 674:
#line 3754 "ircd_parser.y"
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

  case 677:
#line 3801 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 678:
#line 3805 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 701:
#line 3829 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 702:
#line 3834 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 703:
#line 3839 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 704:
#line 3844 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 705:
#line 3849 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 706:
#line 3854 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 707:
#line 3859 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 708:
#line 3864 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 709:
#line 3869 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 710:
#line 3874 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 711:
#line 3879 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 712:
#line 3884 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 713:
#line 3889 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 714:
#line 3894 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 715:
#line 3899 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 716:
#line 3904 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 717:
#line 3909 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 718:
#line 3914 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 730:
#line 3933 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 731:
#line 3939 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 732:
#line 3945 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 733:
#line 3954 "ircd_parser.y"
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

  case 734:
#line 3968 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 735:
#line 3974 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 736:
#line 3980 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1267 of yacc.c.  */
#line 7779 "y.tab.c"
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



