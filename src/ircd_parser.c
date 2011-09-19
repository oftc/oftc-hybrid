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
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
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
#line 177 "ircd_parser.c"

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
     CIPHER_PREFERENCE = 279,
     CLASS = 280,
     COMPRESSED = 281,
     COMPRESSION_LEVEL = 282,
     CONNECT = 283,
     CONNECTFREQ = 284,
     CRYPTLINK = 285,
     DEFAULT_CIPHER_PREFERENCE = 286,
     DEFAULT_FLOODCOUNT = 287,
     DEFAULT_SPLIT_SERVER_COUNT = 288,
     DEFAULT_SPLIT_USER_COUNT = 289,
     DENY = 290,
     DESCRIPTION = 291,
     DIE = 292,
     DISABLE_AUTH = 293,
     DISABLE_FAKE_CHANNELS = 294,
     DISABLE_HIDDEN = 295,
     DISABLE_LOCAL_CHANNELS = 296,
     DISABLE_REMOTE_COMMANDS = 297,
     DOTS_IN_IDENT = 298,
     DURATION = 299,
     EGDPOOL_PATH = 300,
     EMAIL = 301,
     ENABLE = 302,
     ENCRYPTED = 303,
     EXCEED_LIMIT = 304,
     EXEMPT = 305,
     FAILED_OPER_NOTICE = 306,
     IRCD_FLAGS = 307,
     FLATTEN_LINKS = 308,
     FFAILED_OPERLOG = 309,
     FKILLLOG = 310,
     FKLINELOG = 311,
     FGLINELOG = 312,
     FIOERRLOG = 313,
     FOPERLOG = 314,
     FOPERSPYLOG = 315,
     FUSERLOG = 316,
     GECOS = 317,
     GENERAL = 318,
     GLINE = 319,
     GLINES = 320,
     GLINE_EXEMPT = 321,
     GLINE_LOG = 322,
     GLINE_TIME = 323,
     GLINE_MIN_CIDR = 324,
     GLINE_MIN_CIDR6 = 325,
     GLOBAL_KILL = 326,
     IRCD_AUTH = 327,
     NEED_IDENT = 328,
     HAVENT_READ_CONF = 329,
     HIDDEN = 330,
     HIDDEN_ADMIN = 331,
     HIDDEN_NAME = 332,
     HIDDEN_OPER = 333,
     HIDE_SERVER_IPS = 334,
     HIDE_SERVERS = 335,
     HIDE_SPOOF_IPS = 336,
     HOST = 337,
     HUB = 338,
     HUB_MASK = 339,
     IGNORE_BOGUS_TS = 340,
     INVISIBLE_ON_CONNECT = 341,
     IP = 342,
     KILL = 343,
     KILL_CHASE_TIME_LIMIT = 344,
     KLINE = 345,
     KLINE_EXEMPT = 346,
     KLINE_REASON = 347,
     KLINE_WITH_REASON = 348,
     KNOCK_DELAY = 349,
     KNOCK_DELAY_CHANNEL = 350,
     LEAF_MASK = 351,
     LINKS_DELAY = 352,
     LISTEN = 353,
     T_LOG = 354,
     LOGGING = 355,
     LOG_LEVEL = 356,
     MAX_ACCEPT = 357,
     MAX_BANS = 358,
     MAX_CHANS_PER_USER = 359,
     MAX_GLOBAL = 360,
     MAX_IDENT = 361,
     MAX_LOCAL = 362,
     MAX_NICK_CHANGES = 363,
     MAX_NICK_TIME = 364,
     MAX_NUMBER = 365,
     MAX_TARGETS = 366,
     MAX_WATCH = 367,
     MESSAGE_LOCALE = 368,
     MIN_NONWILDCARD = 369,
     MIN_NONWILDCARD_SIMPLE = 370,
     MODULE = 371,
     MODULES = 372,
     NAME = 373,
     NEED_PASSWORD = 374,
     NETWORK_DESC = 375,
     NETWORK_NAME = 376,
     NICK = 377,
     NICK_CHANGES = 378,
     NO_CREATE_ON_SPLIT = 379,
     NO_JOIN_ON_SPLIT = 380,
     NO_OPER_FLOOD = 381,
     NO_TILDE = 382,
     NUMBER = 383,
     NUMBER_PER_IDENT = 384,
     NUMBER_PER_CIDR = 385,
     NUMBER_PER_IP = 386,
     NUMBER_PER_IP_GLOBAL = 387,
     OPERATOR = 388,
     OPERS_BYPASS_CALLERID = 389,
     OPER_LOG = 390,
     OPER_ONLY_UMODES = 391,
     OPER_PASS_RESV = 392,
     OPER_SPY_T = 393,
     OPER_UMODES = 394,
     JOIN_FLOOD_COUNT = 395,
     JOIN_FLOOD_TIME = 396,
     PACE_WAIT = 397,
     PACE_WAIT_SIMPLE = 398,
     PASSWORD = 399,
     PATH = 400,
     PING_COOKIE = 401,
     PING_TIME = 402,
     PING_WARNING = 403,
     PORT = 404,
     QSTRING = 405,
     QUIET_ON_BAN = 406,
     REASON = 407,
     REDIRPORT = 408,
     REDIRSERV = 409,
     REGEX_T = 410,
     REHASH = 411,
     TREJECT_HOLD_TIME = 412,
     REMOTE = 413,
     REMOTEBAN = 414,
     RESTRICT_CHANNELS = 415,
     RESTRICTED = 416,
     RSA_PRIVATE_KEY_FILE = 417,
     RSA_PUBLIC_KEY_FILE = 418,
     SSL_CERTIFICATE_FILE = 419,
     T_SSL_CONNECTION_METHOD = 420,
     T_SSLV3 = 421,
     T_TLSV1 = 422,
     RESV = 423,
     RESV_EXEMPT = 424,
     SECONDS = 425,
     MINUTES = 426,
     HOURS = 427,
     DAYS = 428,
     WEEKS = 429,
     SENDQ = 430,
     SEND_PASSWORD = 431,
     SERVERHIDE = 432,
     SERVERINFO = 433,
     SERVLINK_PATH = 434,
     IRCD_SID = 435,
     TKLINE_EXPIRE_NOTICES = 436,
     T_SHARED = 437,
     T_CLUSTER = 438,
     TYPE = 439,
     SHORT_MOTD = 440,
     SILENT = 441,
     SPOOF = 442,
     SPOOF_NOTICE = 443,
     STATS_E_DISABLED = 444,
     STATS_I_OPER_ONLY = 445,
     STATS_K_OPER_ONLY = 446,
     STATS_O_OPER_ONLY = 447,
     STATS_P_OPER_ONLY = 448,
     TBOOL = 449,
     TMASKED = 450,
     T_REJECT = 451,
     TS_MAX_DELTA = 452,
     TS_WARN_DELTA = 453,
     TWODOTS = 454,
     T_ALL = 455,
     T_BOTS = 456,
     T_SOFTCALLERID = 457,
     T_CALLERID = 458,
     T_CCONN = 459,
     T_CCONN_FULL = 460,
     T_CLIENT_FLOOD = 461,
     T_DEAF = 462,
     T_DEBUG = 463,
     T_DRONE = 464,
     T_EXTERNAL = 465,
     T_FULL = 466,
     T_INVISIBLE = 467,
     T_IPV4 = 468,
     T_IPV6 = 469,
     T_LOCOPS = 470,
     T_LOGPATH = 471,
     T_L_CRIT = 472,
     T_L_DEBUG = 473,
     T_L_ERROR = 474,
     T_L_INFO = 475,
     T_L_NOTICE = 476,
     T_L_TRACE = 477,
     T_L_WARN = 478,
     T_MAX_CLIENTS = 479,
     T_NCHANGE = 480,
     T_OPERWALL = 481,
     T_REJ = 482,
     T_SERVER = 483,
     T_SERVNOTICE = 484,
     T_SKILL = 485,
     T_SPY = 486,
     T_SSL = 487,
     T_UMODES = 488,
     T_UNAUTH = 489,
     T_UNRESV = 490,
     T_UNXLINE = 491,
     T_GLOBOPS = 492,
     T_WALLOP = 493,
     T_RESTART = 494,
     T_SERVICE = 495,
     T_SERVICES_NAME = 496,
     THROTTLE_TIME = 497,
     TOPICBURST = 498,
     TRUE_NO_OPER_FLOOD = 499,
     TKLINE = 500,
     TXLINE = 501,
     TRESV = 502,
     UNKLINE = 503,
     USER = 504,
     USE_EGD = 505,
     USE_EXCEPT = 506,
     USE_INVEX = 507,
     USE_KNOCK = 508,
     USE_LOGGING = 509,
     USE_WHOIS_ACTUALLY = 510,
     VHOST = 511,
     VHOST6 = 512,
     XLINE = 513,
     WARN = 514,
     WARN_NO_NLINE = 515
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
#define CIPHER_PREFERENCE 279
#define CLASS 280
#define COMPRESSED 281
#define COMPRESSION_LEVEL 282
#define CONNECT 283
#define CONNECTFREQ 284
#define CRYPTLINK 285
#define DEFAULT_CIPHER_PREFERENCE 286
#define DEFAULT_FLOODCOUNT 287
#define DEFAULT_SPLIT_SERVER_COUNT 288
#define DEFAULT_SPLIT_USER_COUNT 289
#define DENY 290
#define DESCRIPTION 291
#define DIE 292
#define DISABLE_AUTH 293
#define DISABLE_FAKE_CHANNELS 294
#define DISABLE_HIDDEN 295
#define DISABLE_LOCAL_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DOTS_IN_IDENT 298
#define DURATION 299
#define EGDPOOL_PATH 300
#define EMAIL 301
#define ENABLE 302
#define ENCRYPTED 303
#define EXCEED_LIMIT 304
#define EXEMPT 305
#define FAILED_OPER_NOTICE 306
#define IRCD_FLAGS 307
#define FLATTEN_LINKS 308
#define FFAILED_OPERLOG 309
#define FKILLLOG 310
#define FKLINELOG 311
#define FGLINELOG 312
#define FIOERRLOG 313
#define FOPERLOG 314
#define FOPERSPYLOG 315
#define FUSERLOG 316
#define GECOS 317
#define GENERAL 318
#define GLINE 319
#define GLINES 320
#define GLINE_EXEMPT 321
#define GLINE_LOG 322
#define GLINE_TIME 323
#define GLINE_MIN_CIDR 324
#define GLINE_MIN_CIDR6 325
#define GLOBAL_KILL 326
#define IRCD_AUTH 327
#define NEED_IDENT 328
#define HAVENT_READ_CONF 329
#define HIDDEN 330
#define HIDDEN_ADMIN 331
#define HIDDEN_NAME 332
#define HIDDEN_OPER 333
#define HIDE_SERVER_IPS 334
#define HIDE_SERVERS 335
#define HIDE_SPOOF_IPS 336
#define HOST 337
#define HUB 338
#define HUB_MASK 339
#define IGNORE_BOGUS_TS 340
#define INVISIBLE_ON_CONNECT 341
#define IP 342
#define KILL 343
#define KILL_CHASE_TIME_LIMIT 344
#define KLINE 345
#define KLINE_EXEMPT 346
#define KLINE_REASON 347
#define KLINE_WITH_REASON 348
#define KNOCK_DELAY 349
#define KNOCK_DELAY_CHANNEL 350
#define LEAF_MASK 351
#define LINKS_DELAY 352
#define LISTEN 353
#define T_LOG 354
#define LOGGING 355
#define LOG_LEVEL 356
#define MAX_ACCEPT 357
#define MAX_BANS 358
#define MAX_CHANS_PER_USER 359
#define MAX_GLOBAL 360
#define MAX_IDENT 361
#define MAX_LOCAL 362
#define MAX_NICK_CHANGES 363
#define MAX_NICK_TIME 364
#define MAX_NUMBER 365
#define MAX_TARGETS 366
#define MAX_WATCH 367
#define MESSAGE_LOCALE 368
#define MIN_NONWILDCARD 369
#define MIN_NONWILDCARD_SIMPLE 370
#define MODULE 371
#define MODULES 372
#define NAME 373
#define NEED_PASSWORD 374
#define NETWORK_DESC 375
#define NETWORK_NAME 376
#define NICK 377
#define NICK_CHANGES 378
#define NO_CREATE_ON_SPLIT 379
#define NO_JOIN_ON_SPLIT 380
#define NO_OPER_FLOOD 381
#define NO_TILDE 382
#define NUMBER 383
#define NUMBER_PER_IDENT 384
#define NUMBER_PER_CIDR 385
#define NUMBER_PER_IP 386
#define NUMBER_PER_IP_GLOBAL 387
#define OPERATOR 388
#define OPERS_BYPASS_CALLERID 389
#define OPER_LOG 390
#define OPER_ONLY_UMODES 391
#define OPER_PASS_RESV 392
#define OPER_SPY_T 393
#define OPER_UMODES 394
#define JOIN_FLOOD_COUNT 395
#define JOIN_FLOOD_TIME 396
#define PACE_WAIT 397
#define PACE_WAIT_SIMPLE 398
#define PASSWORD 399
#define PATH 400
#define PING_COOKIE 401
#define PING_TIME 402
#define PING_WARNING 403
#define PORT 404
#define QSTRING 405
#define QUIET_ON_BAN 406
#define REASON 407
#define REDIRPORT 408
#define REDIRSERV 409
#define REGEX_T 410
#define REHASH 411
#define TREJECT_HOLD_TIME 412
#define REMOTE 413
#define REMOTEBAN 414
#define RESTRICT_CHANNELS 415
#define RESTRICTED 416
#define RSA_PRIVATE_KEY_FILE 417
#define RSA_PUBLIC_KEY_FILE 418
#define SSL_CERTIFICATE_FILE 419
#define T_SSL_CONNECTION_METHOD 420
#define T_SSLV3 421
#define T_TLSV1 422
#define RESV 423
#define RESV_EXEMPT 424
#define SECONDS 425
#define MINUTES 426
#define HOURS 427
#define DAYS 428
#define WEEKS 429
#define SENDQ 430
#define SEND_PASSWORD 431
#define SERVERHIDE 432
#define SERVERINFO 433
#define SERVLINK_PATH 434
#define IRCD_SID 435
#define TKLINE_EXPIRE_NOTICES 436
#define T_SHARED 437
#define T_CLUSTER 438
#define TYPE 439
#define SHORT_MOTD 440
#define SILENT 441
#define SPOOF 442
#define SPOOF_NOTICE 443
#define STATS_E_DISABLED 444
#define STATS_I_OPER_ONLY 445
#define STATS_K_OPER_ONLY 446
#define STATS_O_OPER_ONLY 447
#define STATS_P_OPER_ONLY 448
#define TBOOL 449
#define TMASKED 450
#define T_REJECT 451
#define TS_MAX_DELTA 452
#define TS_WARN_DELTA 453
#define TWODOTS 454
#define T_ALL 455
#define T_BOTS 456
#define T_SOFTCALLERID 457
#define T_CALLERID 458
#define T_CCONN 459
#define T_CCONN_FULL 460
#define T_CLIENT_FLOOD 461
#define T_DEAF 462
#define T_DEBUG 463
#define T_DRONE 464
#define T_EXTERNAL 465
#define T_FULL 466
#define T_INVISIBLE 467
#define T_IPV4 468
#define T_IPV6 469
#define T_LOCOPS 470
#define T_LOGPATH 471
#define T_L_CRIT 472
#define T_L_DEBUG 473
#define T_L_ERROR 474
#define T_L_INFO 475
#define T_L_NOTICE 476
#define T_L_TRACE 477
#define T_L_WARN 478
#define T_MAX_CLIENTS 479
#define T_NCHANGE 480
#define T_OPERWALL 481
#define T_REJ 482
#define T_SERVER 483
#define T_SERVNOTICE 484
#define T_SKILL 485
#define T_SPY 486
#define T_SSL 487
#define T_UMODES 488
#define T_UNAUTH 489
#define T_UNRESV 490
#define T_UNXLINE 491
#define T_GLOBOPS 492
#define T_WALLOP 493
#define T_RESTART 494
#define T_SERVICE 495
#define T_SERVICES_NAME 496
#define THROTTLE_TIME 497
#define TOPICBURST 498
#define TRUE_NO_OPER_FLOOD 499
#define TKLINE 500
#define TXLINE 501
#define TRESV 502
#define UNKLINE 503
#define USER 504
#define USE_EGD 505
#define USE_EXCEPT 506
#define USE_INVEX 507
#define USE_KNOCK 508
#define USE_LOGGING 509
#define USE_WHOIS_ACTUALLY 510
#define VHOST 511
#define VHOST6 512
#define XLINE 513
#define WARN 514
#define WARN_NO_NLINE 515




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 130 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 740 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 752 "ircd_parser.c"

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
#define YYLAST   1275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  313
/* YYNRULES -- Number of rules.  */
#define YYNRULES  683
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   515

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   265,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   261,
       2,   264,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   263,     2,   262,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259,   260
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
     154,   156,   158,   160,   162,   165,   166,   172,   176,   178,
     180,   182,   187,   192,   197,   202,   207,   212,   217,   222,
     227,   232,   237,   243,   246,   248,   250,   252,   254,   257,
     262,   267,   272,   278,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   310,   315,
     320,   325,   330,   335,   340,   345,   350,   355,   360,   365,
     370,   375,   380,   385,   390,   395,   400,   401,   409,   410,
     412,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     433,   436,   441,   443,   448,   453,   458,   463,   468,   469,
     475,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   513,   515,
     517,   519,   520,   526,   530,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   554,   556,   558,   560,
     562,   564,   566,   568,   569,   577,   578,   580,   583,   585,
     587,   589,   591,   593,   595,   597,   599,   601,   603,   605,
     607,   609,   611,   614,   619,   621,   626,   631,   636,   641,
     646,   651,   656,   661,   666,   671,   676,   681,   682,   689,
     690,   696,   700,   702,   704,   706,   708,   711,   713,   715,
     717,   719,   721,   724,   725,   731,   735,   737,   739,   743,
     748,   753,   754,   761,   764,   766,   768,   770,   772,   774,
     776,   778,   780,   782,   785,   790,   795,   800,   805,   806,
     812,   816,   818,   820,   822,   824,   826,   828,   830,   832,
     834,   836,   841,   846,   851,   852,   859,   862,   864,   866,
     868,   870,   873,   878,   883,   888,   894,   897,   899,   901,
     903,   908,   909,   916,   919,   921,   923,   925,   927,   930,
     935,   940,   941,   947,   951,   953,   955,   957,   959,   961,
     963,   965,   967,   969,   971,   973,   975,   976,   983,   986,
     988,   990,   992,   995,  1000,  1001,  1007,  1011,  1013,  1015,
    1017,  1019,  1021,  1023,  1025,  1027,  1029,  1031,  1033,  1035,
    1036,  1044,  1045,  1047,  1050,  1052,  1054,  1056,  1058,  1060,
    1062,  1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,
    1083,  1088,  1090,  1095,  1100,  1105,  1110,  1115,  1120,  1125,
    1126,  1132,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1153,
    1158,  1163,  1168,  1173,  1178,  1179,  1186,  1187,  1193,  1197,
    1199,  1201,  1204,  1206,  1208,  1210,  1212,  1214,  1219,  1224,
    1225,  1232,  1235,  1237,  1239,  1241,  1243,  1248,  1253,  1259,
    1262,  1264,  1266,  1268,  1273,  1274,  1281,  1282,  1288,  1292,
    1294,  1296,  1299,  1301,  1303,  1305,  1307,  1309,  1314,  1319,
    1325,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,
    1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,
    1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,
    1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,  1447,
    1452,  1457,  1462,  1467,  1472,  1477,  1482,  1487,  1492,  1497,
    1502,  1507,  1512,  1517,  1522,  1527,  1532,  1537,  1542,  1547,
    1552,  1557,  1562,  1567,  1572,  1577,  1582,  1587,  1592,  1597,
    1602,  1607,  1612,  1617,  1622,  1627,  1632,  1637,  1642,  1647,
    1652,  1657,  1662,  1667,  1672,  1677,  1682,  1687,  1692,  1697,
    1698,  1704,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1749,  1755,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,
    1789,  1791,  1793,  1795,  1797,  1799,  1804,  1809,  1814,  1819,
    1820,  1827,  1830,  1832,  1834,  1836,  1838,  1840,  1842,  1844,
    1846,  1851,  1856,  1857,  1863,  1867,  1869,  1871,  1873,  1878,
    1883,  1884,  1890,  1894,  1896,  1898,  1900,  1906,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,
    1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,  1949,  1954,
    1959,  1964,  1969,  1974,  1979,  1984,  1989,  1994,  1999,  2004,
    2009,  2014,  2019,  2024,  2029,  2034,  2039,  2045,  2048,  2050,
    2052,  2054,  2056,  2058,  2060,  2062,  2064,  2066,  2071,  2076,
    2081,  2086,  2091,  2096
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,    -1,   267,   268,    -1,   296,    -1,   302,
      -1,   317,    -1,   548,    -1,   337,    -1,   356,    -1,   370,
      -1,   278,    -1,   569,    -1,   385,    -1,   392,    -1,   396,
      -1,   406,    -1,   415,    -1,   438,    -1,   448,    -1,   454,
      -1,   468,    -1,   532,    -1,   458,    -1,   273,    -1,     1,
     261,    -1,     1,   262,    -1,    -1,   270,    -1,   128,   269,
      -1,   128,   170,   269,    -1,   128,   171,   269,    -1,   128,
     172,   269,    -1,   128,   173,   269,    -1,   128,   174,   269,
      -1,    -1,   272,    -1,   128,   271,    -1,   128,    14,   271,
      -1,   128,    15,   271,    -1,   128,    16,   271,    -1,   117,
     263,   274,   262,   261,    -1,   274,   275,    -1,   275,    -1,
     276,    -1,   277,    -1,     1,   261,    -1,   116,   264,   150,
     261,    -1,   145,   264,   150,   261,    -1,   178,   263,   279,
     262,   261,    -1,   279,   280,    -1,   280,    -1,   287,    -1,
     292,    -1,   295,    -1,   289,    -1,   290,    -1,   291,    -1,
     294,    -1,   286,    -1,   293,    -1,   288,    -1,   285,    -1,
     281,    -1,     1,   261,    -1,    -1,   165,   282,   264,   283,
     261,    -1,   283,   265,   284,    -1,   284,    -1,   166,    -1,
     167,    -1,   164,   264,   150,   261,    -1,   162,   264,   150,
     261,    -1,   118,   264,   150,   261,    -1,   180,   264,   150,
     261,    -1,    36,   264,   150,   261,    -1,   121,   264,   150,
     261,    -1,   120,   264,   150,   261,    -1,   256,   264,   150,
     261,    -1,   257,   264,   150,   261,    -1,   224,   264,   128,
     261,    -1,    83,   264,   194,   261,    -1,     5,   263,   297,
     262,   261,    -1,   297,   298,    -1,   298,    -1,   299,    -1,
     301,    -1,   300,    -1,     1,   261,    -1,   118,   264,   150,
     261,    -1,    46,   264,   150,   261,    -1,    36,   264,   150,
     261,    -1,   100,   263,   303,   262,   261,    -1,   303,   304,
      -1,   304,    -1,   305,    -1,   306,    -1,   315,    -1,   316,
      -1,   307,    -1,   309,    -1,   311,    -1,   312,    -1,   314,
      -1,   310,    -1,   313,    -1,   308,    -1,     1,   261,    -1,
     216,   264,   150,   261,    -1,   135,   264,   150,   261,    -1,
      61,   264,   150,   261,    -1,    54,   264,   150,   261,    -1,
      59,   264,   150,   261,    -1,    60,   264,   150,   261,    -1,
      57,   264,   150,   261,    -1,    56,   264,   150,   261,    -1,
      58,   264,   150,   261,    -1,    55,   264,   150,   261,    -1,
     101,   264,   217,   261,    -1,   101,   264,   219,   261,    -1,
     101,   264,   223,   261,    -1,   101,   264,   221,   261,    -1,
     101,   264,   222,   261,    -1,   101,   264,   220,   261,    -1,
     101,   264,   218,   261,    -1,   254,   264,   194,   261,    -1,
      -1,   133,   318,   319,   263,   320,   262,   261,    -1,    -1,
     323,    -1,   320,   321,    -1,   321,    -1,   322,    -1,   324,
      -1,   325,    -1,   329,    -1,   328,    -1,   326,    -1,   327,
      -1,   333,    -1,     1,   261,    -1,   118,   264,   150,   261,
      -1,   150,    -1,   249,   264,   150,   261,    -1,   144,   264,
     150,   261,    -1,    48,   264,   194,   261,    -1,   163,   264,
     150,   261,    -1,    25,   264,   150,   261,    -1,    -1,   233,
     330,   264,   331,   261,    -1,   331,   265,   332,    -1,   332,
      -1,   201,    -1,   204,    -1,   205,    -1,   207,    -1,   208,
      -1,   211,    -1,   230,    -1,   225,    -1,   227,    -1,   234,
      -1,   231,    -1,   210,    -1,   226,    -1,   229,    -1,   212,
      -1,   238,    -1,   202,    -1,   203,    -1,   215,    -1,    -1,
      52,   334,   264,   335,   261,    -1,   335,   265,   336,    -1,
     336,    -1,    71,    -1,   158,    -1,    90,    -1,   248,    -1,
     258,    -1,    64,    -1,    37,    -1,   239,    -1,   156,    -1,
       5,    -1,    76,    -1,   123,    -1,   226,    -1,   237,    -1,
     138,    -1,    78,    -1,   159,    -1,   116,    -1,    -1,    25,
     338,   339,   263,   340,   262,   261,    -1,    -1,   343,    -1,
     340,   341,    -1,   341,    -1,   342,    -1,   353,    -1,   354,
      -1,   344,    -1,   345,    -1,   355,    -1,   346,    -1,   347,
      -1,   348,    -1,   349,    -1,   350,    -1,   351,    -1,   352,
      -1,     1,   261,    -1,   118,   264,   150,   261,    -1,   150,
      -1,   147,   264,   270,   261,    -1,   148,   264,   270,   261,
      -1,   131,   264,   128,   261,    -1,    29,   264,   270,   261,
      -1,   110,   264,   128,   261,    -1,   105,   264,   128,   261,
      -1,   107,   264,   128,   261,    -1,   106,   264,   128,   261,
      -1,   175,   264,   272,   261,    -1,    22,   264,   128,   261,
      -1,    23,   264,   128,   261,    -1,   130,   264,   128,   261,
      -1,    -1,    98,   357,   263,   362,   262,   261,    -1,    -1,
      52,   359,   264,   360,   261,    -1,   360,   265,   361,    -1,
     361,    -1,   232,    -1,    75,    -1,   228,    -1,   362,   363,
      -1,   363,    -1,   364,    -1,   358,    -1,   368,    -1,   369,
      -1,     1,   261,    -1,    -1,   149,   264,   366,   365,   261,
      -1,   366,   265,   367,    -1,   367,    -1,   128,    -1,   128,
     199,   128,    -1,    87,   264,   150,   261,    -1,    82,   264,
     150,   261,    -1,    -1,    72,   371,   263,   372,   262,   261,
      -1,   372,   373,    -1,   373,    -1,   374,    -1,   375,    -1,
     376,    -1,   378,    -1,   382,    -1,   383,    -1,   384,    -1,
     377,    -1,     1,   261,    -1,   249,   264,   150,   261,    -1,
     144,   264,   150,   261,    -1,    25,   264,   150,   261,    -1,
      48,   264,   194,   261,    -1,    -1,    52,   379,   264,   380,
     261,    -1,   380,   265,   381,    -1,   381,    -1,   188,    -1,
      49,    -1,    91,    -1,    73,    -1,    20,    -1,   127,    -1,
      66,    -1,   169,    -1,   119,    -1,   187,   264,   150,   261,
      -1,   154,   264,   150,   261,    -1,   153,   264,   128,   261,
      -1,    -1,   168,   386,   263,   387,   262,   261,    -1,   387,
     388,    -1,   388,    -1,   389,    -1,   390,    -1,   391,    -1,
       1,   261,    -1,   152,   264,   150,   261,    -1,    21,   264,
     150,   261,    -1,   122,   264,   150,   261,    -1,   240,   263,
     393,   262,   261,    -1,   393,   394,    -1,   394,    -1,   395,
      -1,     1,    -1,   118,   264,   150,   261,    -1,    -1,   182,
     397,   263,   398,   262,   261,    -1,   398,   399,    -1,   399,
      -1,   400,    -1,   401,    -1,   402,    -1,     1,   261,    -1,
     118,   264,   150,   261,    -1,   249,   264,   150,   261,    -1,
      -1,   184,   403,   264,   404,   261,    -1,   404,   265,   405,
      -1,   405,    -1,    90,    -1,   245,    -1,   248,    -1,   258,
      -1,   246,    -1,   236,    -1,   168,    -1,   247,    -1,   235,
      -1,   215,    -1,   200,    -1,    -1,   183,   407,   263,   408,
     262,   261,    -1,   408,   409,    -1,   409,    -1,   410,    -1,
     411,    -1,     1,   261,    -1,   118,   264,   150,   261,    -1,
      -1,   184,   412,   264,   413,   261,    -1,   413,   265,   414,
      -1,   414,    -1,    90,    -1,   245,    -1,   248,    -1,   258,
      -1,   246,    -1,   236,    -1,   168,    -1,   247,    -1,   235,
      -1,   215,    -1,   200,    -1,    -1,    28,   416,   417,   263,
     418,   262,   261,    -1,    -1,   421,    -1,   418,   419,    -1,
     419,    -1,   420,    -1,   422,    -1,   423,    -1,   424,    -1,
     425,    -1,   427,    -1,   426,    -1,   428,    -1,   434,    -1,
     435,    -1,   436,    -1,   433,    -1,   432,    -1,   437,    -1,
       1,   261,    -1,   118,   264,   150,   261,    -1,   150,    -1,
      82,   264,   150,   261,    -1,   256,   264,   150,   261,    -1,
     176,   264,   150,   261,    -1,     3,   264,   150,   261,    -1,
     149,   264,   128,   261,    -1,     6,   264,   213,   261,    -1,
       6,   264,   214,   261,    -1,    -1,    52,   429,   264,   430,
     261,    -1,   430,   265,   431,    -1,   431,    -1,    26,    -1,
      30,    -1,    10,    -1,    12,    -1,   243,    -1,   163,   264,
     150,   261,    -1,    48,   264,   194,   261,    -1,    84,   264,
     150,   261,    -1,    96,   264,   150,   261,    -1,    25,   264,
     150,   261,    -1,    24,   264,   150,   261,    -1,    -1,    88,
     439,   263,   444,   262,   261,    -1,    -1,   184,   441,   264,
     442,   261,    -1,   442,   265,   443,    -1,   443,    -1,   155,
      -1,   444,   445,    -1,   445,    -1,   446,    -1,   447,    -1,
     440,    -1,     1,    -1,   249,   264,   150,   261,    -1,   152,
     264,   150,   261,    -1,    -1,    35,   449,   263,   450,   262,
     261,    -1,   450,   451,    -1,   451,    -1,   452,    -1,   453,
      -1,     1,    -1,    87,   264,   150,   261,    -1,   152,   264,
     150,   261,    -1,    50,   263,   455,   262,   261,    -1,   455,
     456,    -1,   456,    -1,   457,    -1,     1,    -1,    87,   264,
     150,   261,    -1,    -1,    62,   459,   263,   464,   262,   261,
      -1,    -1,   184,   461,   264,   462,   261,    -1,   462,   265,
     463,    -1,   463,    -1,   155,    -1,   464,   465,    -1,   465,
      -1,   466,    -1,   467,    -1,   460,    -1,     1,    -1,   118,
     264,   150,   261,    -1,   152,   264,   150,   261,    -1,    63,
     263,   469,   262,   261,    -1,   469,   470,    -1,   470,    -1,
     479,    -1,   480,    -1,   482,    -1,   483,    -1,   484,    -1,
     485,    -1,   486,    -1,   487,    -1,   488,    -1,   489,    -1,
     478,    -1,   491,    -1,   492,    -1,   493,    -1,   494,    -1,
     509,    -1,   496,    -1,   498,    -1,   500,    -1,   499,    -1,
     503,    -1,   497,    -1,   504,    -1,   505,    -1,   506,    -1,
     507,    -1,   508,    -1,   524,    -1,   510,    -1,   514,    -1,
     515,    -1,   520,    -1,   501,    -1,   502,    -1,   530,    -1,
     528,    -1,   529,    -1,   511,    -1,   481,    -1,   512,    -1,
     513,    -1,   531,    -1,   519,    -1,   490,    -1,   517,    -1,
     518,    -1,   474,    -1,   477,    -1,   472,    -1,   473,    -1,
     475,    -1,   476,    -1,   495,    -1,   471,    -1,   516,    -1,
       1,    -1,   112,   264,   128,   261,    -1,    69,   264,   128,
     261,    -1,    70,   264,   128,   261,    -1,    12,   264,   194,
     261,    -1,   255,   264,   194,   261,    -1,   157,   264,   270,
     261,    -1,   181,   264,   194,   261,    -1,    89,   264,   270,
     261,    -1,    81,   264,   194,   261,    -1,    85,   264,   194,
     261,    -1,    42,   264,   194,   261,    -1,    51,   264,   194,
     261,    -1,     8,   264,   194,   261,    -1,   109,   264,   270,
     261,    -1,   108,   264,   128,   261,    -1,   102,   264,   128,
     261,    -1,     9,   264,   270,   261,    -1,   198,   264,   270,
     261,    -1,   197,   264,   270,   261,    -1,    74,   264,   128,
     261,    -1,    93,   264,   194,   261,    -1,    92,   264,   150,
     261,    -1,    86,   264,   194,   261,    -1,   260,   264,   194,
     261,    -1,   189,   264,   194,   261,    -1,   192,   264,   194,
     261,    -1,   193,   264,   194,   261,    -1,   191,   264,   194,
     261,    -1,   191,   264,   195,   261,    -1,   190,   264,   194,
     261,    -1,   190,   264,   195,   261,    -1,   142,   264,   270,
     261,    -1,    19,   264,   270,   261,    -1,   134,   264,   194,
     261,    -1,   143,   264,   270,   261,    -1,   185,   264,   194,
     261,    -1,   126,   264,   194,   261,    -1,   244,   264,   194,
     261,    -1,   137,   264,   194,   261,    -1,   113,   264,   150,
     261,    -1,    43,   264,   128,   261,    -1,   111,   264,   128,
     261,    -1,   179,   264,   150,   261,    -1,    31,   264,   150,
     261,    -1,    27,   264,   128,   261,    -1,   250,   264,   194,
     261,    -1,    45,   264,   150,   261,    -1,   241,   264,   150,
     261,    -1,   146,   264,   194,   261,    -1,    38,   264,   194,
     261,    -1,   242,   264,   270,   261,    -1,    -1,   139,   521,
     264,   522,   261,    -1,   522,   265,   523,    -1,   523,    -1,
     201,    -1,   204,    -1,   205,    -1,   207,    -1,   208,    -1,
     211,    -1,   230,    -1,   225,    -1,   227,    -1,   234,    -1,
     231,    -1,   210,    -1,   226,    -1,   229,    -1,   212,    -1,
     238,    -1,   202,    -1,   203,    -1,   215,    -1,    -1,   136,
     525,   264,   526,   261,    -1,   526,   265,   527,    -1,   527,
      -1,   201,    -1,   204,    -1,   205,    -1,   207,    -1,   208,
      -1,   211,    -1,   230,    -1,   225,    -1,   227,    -1,   234,
      -1,   231,    -1,   210,    -1,   226,    -1,   229,    -1,   212,
      -1,   238,    -1,   202,    -1,   203,    -1,   215,    -1,   114,
     264,   128,   261,    -1,   115,   264,   128,   261,    -1,    32,
     264,   128,   261,    -1,   206,   264,   272,   261,    -1,    -1,
      65,   533,   263,   534,   262,   261,    -1,   534,   535,    -1,
     535,    -1,   536,    -1,   537,    -1,   538,    -1,   542,    -1,
     543,    -1,   544,    -1,     1,    -1,    47,   264,   194,   261,
      -1,    44,   264,   270,   261,    -1,    -1,   100,   539,   264,
     540,   261,    -1,   540,   265,   541,    -1,   541,    -1,   196,
      -1,    11,    -1,   249,   264,   150,   261,    -1,   118,   264,
     150,   261,    -1,    -1,     4,   545,   264,   546,   261,    -1,
     546,   265,   547,    -1,   547,    -1,   196,    -1,    11,    -1,
      21,   263,   549,   262,   261,    -1,   549,   550,    -1,   550,
      -1,   553,    -1,   554,    -1,   555,    -1,   556,    -1,   561,
      -1,   557,    -1,   558,    -1,   559,    -1,   560,    -1,   562,
      -1,   563,    -1,   564,    -1,   552,    -1,   565,    -1,   566,
      -1,   567,    -1,   568,    -1,   551,    -1,     1,    -1,    39,
     264,   194,   261,    -1,   160,   264,   194,   261,    -1,    41,
     264,   194,   261,    -1,   251,   264,   194,   261,    -1,   252,
     264,   194,   261,    -1,   253,   264,   194,   261,    -1,    94,
     264,   270,   261,    -1,    95,   264,   270,   261,    -1,   104,
     264,   128,   261,    -1,   151,   264,   194,   261,    -1,   103,
     264,   128,   261,    -1,    34,   264,   128,   261,    -1,    33,
     264,   128,   261,    -1,   124,   264,   194,   261,    -1,   125,
     264,   194,   261,    -1,    13,   264,   194,   261,    -1,   140,
     264,   128,   261,    -1,   141,   264,   270,   261,    -1,   177,
     263,   570,   262,   261,    -1,   570,   571,    -1,   571,    -1,
     572,    -1,   573,    -1,   575,    -1,   577,    -1,   576,    -1,
     574,    -1,   578,    -1,     1,    -1,    53,   264,   194,   261,
      -1,    80,   264,   194,   261,    -1,    77,   264,   150,   261,
      -1,    97,   264,   270,   261,    -1,    75,   264,   194,   261,
      -1,    40,   264,   194,   261,    -1,    79,   264,   194,   261,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   394,   394,   395,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   424,   424,   425,
     429,   433,   437,   441,   445,   451,   451,   452,   453,   454,
     455,   462,   465,   465,   466,   466,   466,   468,   474,   481,
     483,   483,   484,   484,   485,   485,   486,   486,   487,   488,
     488,   489,   489,   490,   491,   495,   494,   513,   513,   514,
     520,   528,   562,   622,   637,   652,   661,   675,   684,   712,
     742,   765,   774,   776,   776,   777,   777,   778,   778,   780,
     789,   798,   811,   813,   814,   816,   816,   817,   818,   818,
     819,   819,   820,   820,   821,   821,   822,   823,   825,   829,
     833,   840,   847,   854,   861,   868,   875,   882,   889,   893,
     897,   901,   905,   909,   913,   919,   929,   928,  1022,  1022,
    1023,  1023,  1024,  1024,  1024,  1025,  1025,  1025,  1026,  1026,
    1026,  1028,  1040,  1052,  1086,  1098,  1109,  1151,  1161,  1160,
    1166,  1166,  1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,
    1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,
    1239,  1246,  1245,  1251,  1251,  1252,  1256,  1260,  1264,  1268,
    1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,  1304,  1308,
    1312,  1316,  1320,  1331,  1330,  1380,  1380,  1382,  1382,  1383,
    1384,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,  1392,
    1393,  1394,  1395,  1397,  1406,  1415,  1421,  1427,  1433,  1439,
    1445,  1451,  1457,  1463,  1469,  1475,  1481,  1491,  1490,  1507,
    1506,  1511,  1511,  1512,  1516,  1520,  1528,  1528,  1529,  1529,
    1529,  1529,  1529,  1531,  1531,  1533,  1533,  1535,  1549,  1569,
    1578,  1591,  1590,  1659,  1659,  1660,  1660,  1660,  1660,  1661,
    1661,  1661,  1662,  1662,  1664,  1701,  1714,  1723,  1735,  1734,
    1738,  1738,  1739,  1743,  1747,  1751,  1755,  1759,  1763,  1767,
    1771,  1778,  1797,  1807,  1821,  1820,  1836,  1836,  1837,  1837,
    1837,  1837,  1839,  1848,  1863,  1876,  1878,  1878,  1879,  1879,
    1881,  1897,  1896,  1912,  1912,  1913,  1913,  1913,  1913,  1915,
    1924,  1947,  1946,  1952,  1952,  1953,  1957,  1961,  1965,  1969,
    1973,  1977,  1981,  1985,  1989,  1993,  2003,  2002,  2019,  2019,
    2020,  2020,  2020,  2022,  2029,  2028,  2034,  2034,  2035,  2039,
    2043,  2047,  2051,  2055,  2059,  2063,  2067,  2071,  2075,  2085,
    2084,  2230,  2230,  2231,  2231,  2232,  2232,  2232,  2233,  2233,
    2234,  2234,  2235,  2235,  2235,  2236,  2236,  2237,  2237,  2238,
    2240,  2252,  2264,  2273,  2299,  2317,  2335,  2341,  2345,  2354,
    2353,  2357,  2357,  2358,  2368,  2372,  2376,  2380,  2386,  2427,
    2438,  2451,  2464,  2473,  2509,  2508,  2572,  2571,  2575,  2575,
    2576,  2582,  2582,  2583,  2583,  2583,  2583,  2585,  2604,  2614,
    2613,  2636,  2636,  2637,  2637,  2637,  2639,  2645,  2654,  2656,
    2656,  2657,  2657,  2659,  2678,  2677,  2725,  2724,  2728,  2728,
    2729,  2735,  2735,  2736,  2736,  2736,  2736,  2738,  2744,  2753,
    2756,  2756,  2757,  2757,  2758,  2758,  2759,  2759,  2760,  2760,
    2761,  2761,  2762,  2762,  2763,  2763,  2764,  2764,  2765,  2765,
    2766,  2766,  2767,  2767,  2768,  2768,  2769,  2769,  2770,  2771,
    2771,  2772,  2772,  2773,  2773,  2774,  2774,  2775,  2775,  2776,
    2776,  2777,  2778,  2778,  2779,  2779,  2780,  2781,  2781,  2782,
    2782,  2783,  2783,  2784,  2784,  2785,  2785,  2786,  2789,  2794,
    2799,  2804,  2809,  2814,  2819,  2824,  2829,  2834,  2839,  2844,
    2849,  2854,  2859,  2864,  2869,  2874,  2879,  2885,  2896,  2901,
    2910,  2915,  2920,  2925,  2930,  2935,  2938,  2943,  2946,  2951,
    2956,  2961,  2966,  2971,  2976,  2981,  2986,  2991,  3002,  3007,
    3012,  3021,  3053,  3071,  3076,  3085,  3094,  3099,  3104,  3110,
    3109,  3114,  3114,  3115,  3118,  3121,  3124,  3127,  3130,  3133,
    3136,  3139,  3142,  3145,  3148,  3151,  3154,  3157,  3160,  3163,
    3166,  3169,  3175,  3174,  3179,  3179,  3180,  3183,  3186,  3189,
    3192,  3195,  3198,  3201,  3204,  3207,  3210,  3213,  3216,  3219,
    3222,  3225,  3228,  3231,  3234,  3239,  3244,  3249,  3254,  3264,
    3263,  3287,  3287,  3288,  3289,  3290,  3291,  3292,  3293,  3294,
    3296,  3302,  3309,  3308,  3313,  3313,  3314,  3318,  3324,  3358,
    3368,  3367,  3417,  3417,  3418,  3422,  3431,  3434,  3434,  3435,
    3435,  3436,  3436,  3437,  3437,  3438,  3438,  3439,  3439,  3440,
    3441,  3441,  3442,  3442,  3443,  3443,  3444,  3444,  3446,  3451,
    3456,  3461,  3466,  3471,  3476,  3481,  3486,  3491,  3496,  3501,
    3506,  3511,  3516,  3521,  3526,  3531,  3539,  3542,  3542,  3543,
    3543,  3544,  3545,  3546,  3546,  3547,  3548,  3550,  3556,  3562,
    3571,  3585,  3591,  3597
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
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIPHER_PREFERENCE", "CLASS",
  "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ", "CRYPTLINK",
  "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
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
  "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "T_SSL_CONNECTION_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "SERVLINK_PATH", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF",
  "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE",
  "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS",
  "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR", "T_L_INFO",
  "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_OPERWALL", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS",
  "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV",
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK",
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_connection_method", "$@1",
  "method_types", "method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "$@2",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@3",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@4",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@5",
  "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@6", "listen_flags", "$@7",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@8", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@9", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@10", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@11", "resv_items",
  "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "service_entry", "service_items", "service_item", "service_name",
  "shared_entry", "$@12", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "$@13", "shared_types", "shared_type_item",
  "cluster_entry", "$@14", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@15", "cluster_types", "cluster_type_item",
  "connect_entry", "$@16", "connect_name_b", "connect_items",
  "connect_item", "connect_name", "connect_name_t", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_flags", "$@17",
  "connect_flags_items", "connect_flags_item",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_cipher_preference",
  "kill_entry", "$@18", "kill_type", "$@19", "kill_type_items",
  "kill_type_item", "kill_items", "kill_item", "kill_user", "kill_reason",
  "deny_entry", "$@20", "deny_items", "deny_item", "deny_ip",
  "deny_reason", "exempt_entry", "exempt_items", "exempt_item",
  "exempt_ip", "gecos_entry", "$@21", "gecos_flags", "$@22",
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
  "general_oper_pass_resv", "general_message_locale",
  "general_dots_in_ident", "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@23", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@24", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "gline_entry",
  "$@25", "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "$@26", "gline_logging_types",
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action",
  "$@27", "gdeny_types", "gdeny_type_item", "channel_entry",
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
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   266,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   269,   269,   270,
     270,   270,   270,   270,   270,   271,   271,   272,   272,   272,
     272,   273,   274,   274,   275,   275,   275,   276,   277,   278,
     279,   279,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   282,   281,   283,   283,   284,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   297,   298,   298,   298,   298,   299,
     300,   301,   302,   303,   303,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   315,
     315,   315,   315,   315,   315,   316,   318,   317,   319,   319,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   322,   323,   324,   325,   326,   327,   328,   330,   329,
     331,   331,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   334,   333,   335,   335,   336,   336,   336,   336,   336,
     336,   336,   336,   336,   336,   336,   336,   336,   336,   336,
     336,   336,   336,   338,   337,   339,   339,   340,   340,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   357,   356,   359,
     358,   360,   360,   361,   361,   361,   362,   362,   363,   363,
     363,   363,   363,   365,   364,   366,   366,   367,   367,   368,
     369,   371,   370,   372,   372,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   374,   375,   376,   377,   379,   378,
     380,   380,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   382,   383,   384,   386,   385,   387,   387,   388,   388,
     388,   388,   389,   390,   391,   392,   393,   393,   394,   394,
     395,   397,   396,   398,   398,   399,   399,   399,   399,   400,
     401,   403,   402,   404,   404,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   407,   406,   408,   408,
     409,   409,   409,   410,   412,   411,   413,   413,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   416,
     415,   417,   417,   418,   418,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   427,   429,
     428,   430,   430,   431,   431,   431,   431,   431,   432,   433,
     434,   435,   436,   437,   439,   438,   441,   440,   442,   442,
     443,   444,   444,   445,   445,   445,   445,   446,   447,   449,
     448,   450,   450,   451,   451,   451,   452,   453,   454,   455,
     455,   456,   456,   457,   459,   458,   461,   460,   462,   462,
     463,   464,   464,   465,   465,   465,   465,   466,   467,   468,
     469,   469,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   498,   499,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   521,
     520,   522,   522,   523,   523,   523,   523,   523,   523,   523,
     523,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     523,   523,   525,   524,   526,   526,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   528,   529,   530,   531,   533,
     532,   534,   534,   535,   535,   535,   535,   535,   535,   535,
     536,   537,   539,   538,   540,   540,   541,   541,   542,   543,
     545,   544,   546,   546,   547,   547,   548,   549,   549,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   570,   571,
     571,   571,   571,   571,   571,   571,   571,   572,   573,   574,
     575,   576,   577,   578
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
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     7,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     7,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     6,     0,
       5,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       0,     5,     3,     1,     1,     1,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   193,   349,   409,     0,
     424,     0,   599,   251,   394,   227,     0,     0,   126,   284,
       0,     0,   301,   326,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   195,   351,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   647,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   628,
     646,   641,   629,   630,   631,   632,   634,   635,   636,   637,
     633,   638,   639,   640,   642,   643,   644,   645,   214,     0,
     196,   371,     0,   352,     0,   422,     0,     0,   420,   421,
       0,   497,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572,     0,   549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   441,   495,
     490,   491,   488,   492,   493,   489,   452,   442,   443,   480,
     444,   445,   446,   447,   448,   449,   450,   451,   485,   453,
     454,   455,   456,   494,   458,   463,   459,   461,   460,   474,
     475,   462,   464,   465,   466,   467,   468,   457,   470,   479,
     481,   482,   471,   472,   496,   486,   487,   484,   473,   469,
     477,   478,   476,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    99,   106,   100,   104,   101,
     102,   105,   103,    97,    98,     0,     0,     0,     0,    43,
      44,    45,   142,     0,   129,     0,   676,     0,     0,     0,
       0,     0,     0,     0,     0,   668,   669,   670,   674,   671,
     673,   672,   675,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,    51,    63,    62,
      59,    52,    61,    55,    56,    57,    53,    60,    58,    54,
       0,     0,   299,     0,     0,   297,   298,    88,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   627,     0,     0,   415,     0,     0,     0,   412,
     413,   414,     0,     0,   419,   436,     0,     0,   426,   435,
       0,   432,   433,   434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     440,   609,   620,     0,     0,   612,     0,     0,     0,   602,
     603,   604,   605,   606,   607,   608,     0,     0,     0,   268,
       0,     0,     0,     0,     0,     0,   254,   255,   256,   257,
     262,   258,   259,   260,   261,   406,     0,   396,     0,   405,
       0,   402,   403,   404,     0,   229,     0,     0,     0,   239,
       0,   237,   238,   240,   241,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      46,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   287,   288,   289,   290,     0,     0,     0,     0,     0,
       0,     0,     0,   667,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   311,     0,     0,   304,   305,   306,   307,     0,     0,
     334,     0,   329,   330,   331,     0,     0,   296,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   200,   201,
     204,     0,     0,     0,     0,     0,     0,   379,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   355,   356,
     357,   358,   359,   361,   360,   362,   367,   366,   363,   364,
     365,   368,     0,     0,     0,   411,     0,   418,     0,     0,
       0,     0,   431,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,   439,     0,     0,     0,     0,     0,     0,     0,   601,
     263,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,   401,   242,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    41,     0,     0,     0,   171,     0,
       0,     0,   148,     0,     0,   131,   132,   133,   134,   137,
     138,   136,   135,   139,   291,     0,     0,     0,     0,   286,
       0,     0,     0,     0,     0,     0,     0,   666,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,   308,     0,     0,     0,     0,   303,   332,     0,     0,
       0,   328,     0,   295,    91,    90,    89,   663,   660,   659,
     648,   650,    27,    27,    27,    27,    27,    29,    28,   654,
     655,   658,   656,   661,   662,   664,   665,   657,   649,   651,
     652,   653,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,     0,     0,   410,   423,     0,
       0,     0,   425,   510,   514,   501,   530,   542,   541,   597,
     547,   508,   538,   544,   509,   499,   500,   517,   506,   507,
     520,   505,   519,   518,   513,   512,   511,   539,   498,   537,
     595,   596,   534,   531,   576,   592,   593,   577,   578,   579,
     580,   587,   581,   590,   594,   583,   588,   584,   589,   582,
     586,   585,   591,     0,   575,   536,   553,   569,   570,   554,
     555,   556,   557,   564,   558,   567,   571,   560,   565,   561,
     566,   559,   563,   562,   568,     0,   552,   529,   532,   546,
     503,   540,   504,   533,   522,   527,   528,   525,   526,   523,
     524,   516,   515,    35,    35,    35,    37,    36,   598,   545,
     548,   535,   543,   502,   521,     0,     0,     0,     0,     0,
       0,   600,     0,     0,     0,     0,     0,     0,     0,     0,
     252,     0,     0,     0,   395,     0,     0,     0,   247,   243,
     246,   228,   111,   117,   115,   114,   116,   112,   113,   110,
     118,   124,   119,   123,   121,   122,   120,   109,   108,   125,
      47,    48,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,   285,   682,   677,   681,
     679,   683,   678,   680,    75,    81,    73,    77,    76,    72,
      71,    69,    70,     0,    68,    74,    80,    78,    79,     0,
       0,     0,   302,     0,     0,   327,   300,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   350,   416,   417,   437,   438,   430,     0,   429,   573,
       0,   550,     0,    38,    39,    40,   625,   624,     0,   623,
     611,   610,   617,   616,     0,   615,   619,   618,   266,   267,
     276,   273,   278,   275,   274,   280,   277,   279,   272,     0,
     271,   265,   283,   282,   281,   264,   408,   400,     0,   399,
     407,   234,   235,   233,     0,   232,   250,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     293,   294,   292,    66,     0,   309,   315,   321,   325,   324,
     323,   320,   316,   319,   322,   317,   318,     0,   314,   310,
     333,   338,   344,   348,   347,   346,   343,   339,   342,   345,
     340,   341,     0,   337,   224,   225,   218,   220,   222,   221,
     219,   213,   226,   217,   215,   216,   223,   375,   377,   378,
     393,   392,   389,   385,   386,   383,   384,   387,     0,   382,
     372,   390,   391,   370,   376,   388,   374,   373,   427,     0,
     574,   551,   621,     0,   613,     0,   269,     0,   397,     0,
     230,     0,   248,   245,   244,   147,   145,   184,   181,   180,
     175,   185,   190,   177,   192,   186,   189,   183,   176,   191,
     187,   188,   182,   178,   179,     0,   174,   141,   144,   146,
     152,   168,   169,   153,   154,   155,   156,   163,   157,   166,
     170,   159,   164,   160,   165,   158,   162,   161,   167,     0,
     151,   143,    67,   312,     0,   335,     0,   380,     0,   428,
     622,   614,   270,   398,   231,   172,     0,   149,     0,   313,
     336,   381,   173,   150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   847,   848,   996,   997,    26,   278,   279,
     280,   281,    27,   316,   317,   318,   542,  1083,  1084,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
      28,    74,    75,    76,    77,    78,    29,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    30,    63,   283,   784,   785,   786,   284,   787,   788,
     789,   790,   791,   792,  1059,  1329,  1330,   793,  1055,  1305,
    1306,    31,    51,   119,   606,   607,   608,   120,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   619,   620,
      32,    60,   489,   747,  1184,  1185,   490,   491,   492,  1190,
    1029,  1030,   493,   494,    33,    58,   465,   466,   467,   468,
     469,   470,   471,   733,  1169,  1170,   472,   473,   474,    34,
      64,   520,   521,   522,   523,   524,    35,   334,   335,   336,
      36,    67,   553,   554,   555,   556,   557,   823,  1217,  1218,
      37,    68,   561,   562,   563,   564,   829,  1232,  1233,    38,
      52,   122,   636,   637,   638,   123,   639,   640,   641,   642,
     643,   644,   645,   884,  1258,  1259,   646,   647,   648,   649,
     650,   651,    39,    59,   479,   742,  1178,  1179,   480,   481,
     482,   483,    40,    53,   368,   369,   370,   371,    41,   127,
     128,   129,    42,    55,   379,   660,  1137,  1138,   380,   381,
     382,   383,    43,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   417,   975,   976,   239,   415,
     953,   954,   240,   241,   242,   243,    44,    57,   448,   449,
     450,   451,   452,   725,  1154,  1155,   453,   454,   455,   722,
    1148,  1149,    45,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    46,   294,   295,   296,   297,   298,   299,
     300,   301,   302
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -918
static const yytype_int16 yypact[] =
{
    -918,   686,  -918,  -218,  -254,  -231,  -918,  -918,  -918,  -225,
    -918,  -214,  -918,  -918,  -918,  -918,  -195,  -184,  -918,  -918,
    -153,  -142,  -918,  -918,  -130,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,    29,
     599,    17,    32,   -66,    18,   -46,   401,   -45,   -37,   -31,
     -22,   564,   223,   101,   -17,   756,   294,    -3,    16,     7,
      22,    14,    37,    51,     4,  -918,  -918,  -918,  -918,  -918,
      54,    57,    59,    60,    70,    72,    74,    77,    79,    81,
      88,    90,    92,    93,   100,   102,   105,   106,    98,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,    99,
    -918,  -918,   108,  -918,   158,  -918,   115,    28,  -918,  -918,
      47,  -918,   121,   123,   124,   126,   130,   132,   133,   136,
     137,   139,   142,   152,   153,   154,   155,   157,   163,   166,
     170,   172,   173,   176,   177,   178,   183,   186,   187,   189,
     190,   191,   193,  -918,   197,  -918,   202,   204,   205,   209,
     216,   219,   221,   224,   225,   228,   232,   233,   234,   235,
     238,   247,   255,   256,   259,   264,   266,    15,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,   477,   251,   162,   311,    31,   267,
     275,   277,   281,   285,   293,   297,   298,   299,   300,   302,
     303,   119,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,    76,   305,   306,    24,  -918,
    -918,  -918,  -918,   109,  -918,    73,  -918,   307,   308,   309,
     312,   314,   315,   319,   229,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,    83,   320,   321,   324,   333,   337,   338,
     339,  -918,   340,   341,   344,   345,   167,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
     143,   135,  -918,   346,    27,  -918,  -918,  -918,   141,   226,
     249,    94,  -918,   171,   140,   165,   188,   381,   356,   356,
     483,   487,   433,   434,   501,   356,   436,   440,   441,   442,
     447,   122,  -918,   625,   383,  -918,   380,   382,    19,  -918,
    -918,  -918,   272,   388,  -918,  -918,   386,   389,  -918,  -918,
      96,  -918,  -918,  -918,   461,   356,   464,   356,   524,   276,
     532,   468,   469,   536,   518,   475,   542,   543,   544,   488,
     489,   491,   356,   531,   494,   561,   562,   356,   568,   570,
     550,   573,   577,   498,   510,   444,   516,   448,   356,   356,
     519,   356,   567,   525,   526,   528,  -133,  -107,   533,   535,
     356,   356,   590,   575,   356,   539,   548,   551,   552,   473,
    -918,  -918,  -918,   474,   490,  -918,   496,   497,    91,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,   476,   499,   500,  -918,
     502,   503,   504,   505,   506,   118,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,   507,  -918,   511,  -918,
     112,  -918,  -918,  -918,   480,  -918,   513,   514,   515,  -918,
      11,  -918,  -918,  -918,  -918,  -918,   602,   603,   615,   631,
     635,   637,   638,   639,   457,   640,   647,   604,   538,  -918,
    -918,   651,   652,   545,  -918,   424,   546,   549,   553,   556,
      12,  -918,  -918,  -918,  -918,   610,   614,   616,   664,   621,
     622,   356,   565,  -918,  -918,   675,   633,   678,   679,   680,
     682,   687,   574,   689,   712,   691,   692,   582,  -918,   583,
     581,  -918,   584,    35,  -918,  -918,  -918,  -918,   585,   591,
    -918,    63,  -918,  -918,  -918,   697,   588,  -918,   595,   596,
     597,  -918,   598,   600,   601,   605,   606,   334,   617,   624,
     626,   627,   628,   629,   630,   632,   636,   641,   643,   644,
     645,  -918,   655,   611,   618,   619,   649,   656,   657,   659,
     660,   661,   663,   665,   666,   667,    80,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,   674,   676,   690,   694,   695,   698,  -918,   699,   700,
     701,   702,   703,   704,   705,   709,    66,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,   710,   715,   681,  -918,   683,  -918,   736,   742,
     713,   717,  -918,   719,   720,   721,   723,   724,   725,   726,
     727,   728,   729,   730,   731,   732,   733,   734,   735,   737,
     738,   739,   740,   741,   743,   744,   746,   747,   748,   749,
     750,   751,   752,   753,   669,   754,   707,   755,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   220,   772,   773,   774,   775,   776,   777,
     778,  -918,   779,   356,   803,   780,   789,   793,   781,  -918,
    -918,   801,   809,   782,   811,   800,   856,   867,   890,   784,
    -918,   891,   783,   898,   788,  -918,  -918,   786,   901,   902,
     925,   794,  -918,   795,   796,   797,   798,   799,   802,   804,
     805,   806,   807,   808,   810,   812,   813,   814,   815,   816,
     817,  -918,   818,   819,  -918,   820,   790,   821,  -918,   822,
     823,   824,  -918,   825,   215,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   911,   912,   914,   829,  -918,
     830,   831,   832,   833,   834,   835,   836,  -918,   837,   838,
     839,   840,   841,   842,   843,   -11,   844,   845,   846,   847,
    -918,  -918,   920,   848,   922,   849,  -918,  -918,   932,   850,
     852,  -918,   854,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,   356,   356,   356,   356,   356,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,   955,   956,   356,   981,   983,   988,   989,
     968,   991,   992,   356,   356,   590,   860,  -918,  -918,   972,
      30,   973,   974,   931,   862,   977,   978,   979,   980,  1003,
     982,   984,   985,   872,  -918,   875,   876,  -918,  -918,   877,
     878,   986,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -255,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -250,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,   590,   590,   590,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,    -8,   879,   881,    -7,   882,
     883,  -918,   884,   885,   540,   886,   887,   888,   889,   892,
    -918,   893,   996,   894,  -918,     5,   895,   896,   953,   897,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  1008,   965,   899,  1010,  1011,  1014,   903,
    1015,   905,  -918,   907,   908,   909,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -247,  -918,  -918,  -918,  -918,  -918,   910,
     547,   913,  -918,   915,   576,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,   916,   917,   918,   919,   921,   923,   924,   926,
     927,   928,   929,   930,   933,  -918,   934,   935,   936,   937,
     938,   939,   290,   940,   941,   942,   943,   944,   945,   946,
     947,  -918,  -918,  -918,  -918,  -918,  -918,  -244,  -918,  -918,
     669,  -918,   707,  -918,  -918,  -918,  -918,  -918,  -239,  -918,
    -918,  -918,  -918,  -918,  -230,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -220,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -210,  -918,
    -918,  -918,  -918,  -918,  -209,  -918,  -918,  -918,  1044,   925,
     948,   949,   950,   458,   951,   952,   954,   745,   957,  -918,
    -918,  -918,  -918,  -918,   -11,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -149,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -119,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,    33,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,   986,
    -918,  -918,  -918,    -8,  -918,    -7,  -918,   540,  -918,   996,
    -918,     5,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,    46,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,    52,
    -918,  -918,  -918,  -918,   547,  -918,   576,  -918,   290,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,   458,  -918,   745,  -918,
    -918,  -918,  -918,  -918
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -918,  -918,  -918,  -290,  -348,  -917,  -430,  -918,  -918,   623,
    -918,  -918,  -918,  -918,   857,  -918,  -918,  -918,   -29,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  1107,  -918,  -918,  -918,  -918,  -918,   958,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   399,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -162,  -918,  -918,  -918,
    -154,  -918,  -918,  -918,  -918,   587,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   -67,  -918,   785,  -918,  -918,
    -918,    34,  -918,  -918,  -918,  -918,  -918,   787,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   -61,  -918,  -918,  -918,  -918,
    -918,  -918,   706,  -918,  -918,  -918,  -918,  -918,   900,  -918,
    -918,  -918,  -918,   668,  -918,  -918,  -918,  -918,  -918,  -117,
    -918,  -918,  -918,   670,  -918,  -918,  -918,  -918,  -116,  -918,
    -918,  -918,  -918,   586,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -114,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,   -54,  -918,   791,
    -918,  -918,  -918,  -918,  -918,   859,  -918,  -918,  -918,  -918,
    1101,  -918,  -918,  -918,  -918,  -918,  -918,   -40,  -918,   853,
    -918,  -918,  -918,  -918,  1043,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,    95,  -918,  -918,
    -918,   103,  -918,  -918,  -918,  -918,  -918,  -918,  -918,   792,
    -918,  -918,  -918,  -918,  -918,   -43,  -918,  -918,  -918,  -918,
    -918,   -38,  -918,  -918,  1138,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   959,  -918,  -918,  -918,  -918,
    -918,  -918,  -918
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     578,   579,   714,  1146,  1152,    70,  1139,   585,   332,    49,
    1140,  1141,   484,   516,  1203,  1142,   131,  1268,  1204,   125,
     365,  1269,  1272,   132,   133,   275,  1273,   134,   332,   125,
      70,  1274,    50,   517,   135,  1275,   549,   664,    54,   666,
      71,  1276,   136,    47,    48,  1277,   137,   138,   375,    56,
      72,  1278,  1280,   139,   681,  1279,  1281,   140,   141,   686,
     142,   705,   706,   485,   558,    71,   143,   621,    61,   622,
     697,   698,   623,   700,   516,    72,  1143,  1144,  1145,    62,
    1181,   592,   711,   712,   144,   145,   716,   707,   708,   146,
     624,   625,   441,   486,   517,   442,   147,   375,   487,    79,
     148,   149,   593,   594,   150,   126,   366,   151,   152,   595,
      65,    80,  1333,   475,   626,   126,  1334,   153,   627,   456,
     248,    66,    73,   154,   155,   333,   156,   157,   158,   159,
     160,    81,    82,    69,   518,   443,   558,    83,   444,    84,
     276,   161,  1335,   457,   549,   333,  1336,    73,   628,   162,
     629,   163,   164,   550,   165,  1081,  1082,   166,   167,   365,
     488,   168,   630,   475,   519,   376,   458,   118,   303,   277,
     459,   367,   169,   249,   250,   251,   252,   253,   254,   255,
     256,   559,   121,   806,   631,   596,   597,   598,  1147,  1153,
     599,   445,    85,    86,   170,   518,   171,   124,   600,   377,
     172,    87,    88,   304,   173,   174,   175,   176,   177,   446,
     601,   602,   178,   179,   376,   632,   775,   130,   244,   551,
     257,   180,    89,    90,   275,   519,   245,   603,   604,   633,
     286,   378,   246,  1182,   993,   994,   995,  1183,    91,    92,
     776,   247,   634,  1117,  1118,   366,   285,   560,   377,    93,
     305,   282,   456,   559,   258,   605,   181,   182,    94,   183,
     330,   550,   460,   777,   476,   184,   341,   778,   573,   287,
     185,   461,   462,   751,   798,   186,   457,   439,   338,   331,
     378,   654,   288,   337,   552,   306,   513,   307,   308,   566,
     373,   568,   495,   574,  1337,   303,   477,   825,  1338,   458,
    1253,   339,  1254,   459,   289,   463,   290,  1345,   291,   292,
     367,  1346,   484,  1347,   476,   340,  1255,  1348,   343,   560,
    1256,   344,   635,   345,   346,   830,   293,   551,   893,   309,
     304,   310,   311,   779,   347,   259,   348,   510,   349,   276,
     447,   350,   876,   351,   534,   352,   477,   312,   713,    95,
      96,    97,   353,   728,   354,   571,   355,   356,   661,   780,
     361,   478,   363,   485,   357,   572,   358,   464,   277,   359,
     360,   364,   515,   260,   744,  1006,   569,   305,   781,   372,
     739,   508,   575,   591,   621,   384,   622,   385,   386,   623,
     387,   313,   552,   486,   388,   460,   389,   390,   487,   570,
     391,   392,   131,   393,   461,   462,   394,   624,   625,   132,
     133,   478,   306,   134,   307,   308,   395,   396,   397,   398,
     135,   399,   656,   314,   315,   775,   668,   400,   136,   547,
     401,   626,   137,   138,   402,   627,   403,   404,   463,   139,
     405,   406,   407,   140,   141,  1114,   142,   408,   782,   776,
     409,   410,   143,   411,   412,   413,   309,   414,   310,   311,
     488,   416,   577,  1287,   783,   628,   418,   629,   419,   420,
     144,   145,   777,   421,   312,   146,   778,  1061,   441,   630,
     422,   442,   147,   423,   577,   424,   148,   149,   425,   426,
     150,   532,   427,   151,   152,  1288,   428,   429,   430,   431,
     464,   631,   432,   153,   842,   843,   844,   845,   846,   154,
     155,   433,   156,   157,   158,   159,   160,  1104,   313,   434,
     435,   443,  1289,   436,   444,  1112,  1113,   161,   437,  1290,
     438,   496,   632,  1257,  1291,   162,  1292,   163,   164,   497,
     165,   498,   779,   166,   167,   499,   633,   168,  1293,   500,
     314,   315,  1097,  1098,  1099,  1100,  1101,   501,   169,   634,
    1160,   502,   503,   504,   505,   248,   506,   507,   780,   511,
     512,   525,   526,   527,  1294,   576,   528,   445,   529,   530,
     170,  1295,   171,   531,   535,   536,   172,   781,   537,  1161,
     173,   174,   175,   176,   177,   446,  1296,   538,   178,   179,
      79,   539,   540,   541,   543,   544,  1162,   180,   545,   546,
     565,   580,    80,  1163,  1297,   581,  1298,  1299,   249,   250,
     251,   252,   253,   254,   255,   256,   592,   582,   583,   584,
     586,  1164,    81,    82,   587,   588,   589,  1206,    83,   635,
      84,   590,   181,   182,   652,   183,   653,   593,   594,   657,
     658,   184,   667,   659,   595,   663,   185,   782,   665,  1165,
     669,   186,   670,   671,   672,   257,  1221,  1166,   673,   674,
     675,   676,   677,   783,   761,   762,   763,   764,   765,   766,
     767,   682,   678,   679,  1300,   680,     2,     3,   683,   684,
     685,     4,   692,    85,    86,  1301,   687,  1302,   688,   258,
     689,   690,    87,    88,   693,   691,  1303,     5,   694,  1167,
     695,     6,   696,   699,     7,  1207,  1304,   701,   713,   702,
     703,     8,   704,    89,    90,   715,   447,   709,  1168,   710,
     596,   597,   598,   717,   721,   599,     9,   730,   723,    91,
      92,   746,   718,   600,  1222,   719,   720,  1208,    10,    11,
      93,    12,   753,   754,   724,   601,   602,   286,    13,    94,
     726,   727,  1209,   731,   732,   755,   734,   735,   736,   737,
     738,   741,   603,   604,    14,   743,  1223,   748,   749,   750,
     259,   756,  1210,  1211,    15,   757,    16,   758,   759,   760,
     768,  1224,  1212,  1213,  1214,  1215,   287,   769,   770,   771,
     605,   772,   773,    17,   800,  1216,   774,   794,   801,   288,
     802,  1225,  1226,   795,   803,   804,   805,   796,   260,    18,
     797,  1227,  1228,  1229,  1230,   808,   807,   809,   810,   811,
     812,   289,   813,   290,  1231,   291,   292,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   827,   832,   824,   833,
      95,    96,    97,   293,    19,   828,   834,   835,   836,   837,
     895,   838,   839,    20,    21,   896,   840,   841,    22,    23,
     934,   935,   936,   937,   938,   863,   939,   940,   849,   941,
     942,   943,   864,   865,   944,   850,   899,   851,   852,   853,
     854,   855,   900,   856,   945,   946,   947,   857,   948,   949,
     950,   514,   858,   951,   859,   860,   861,   952,   956,   957,
     958,   959,   960,   866,   961,   962,   862,   963,   964,   965,
     867,   868,   966,   869,   870,   871,    24,   872,  1016,   873,
     874,   875,   967,   968,   969,   878,   970,   971,   972,  1009,
     879,   973,   897,  1010,   898,   974,  1310,  1311,  1312,  1313,
    1314,  1012,  1315,  1316,   880,  1317,  1318,  1319,   881,   882,
    1320,  1015,   883,   885,   886,   887,   888,   889,   890,   891,
    1321,  1322,  1323,   892,  1324,  1325,  1326,   901,   902,  1327,
     903,   904,   905,  1328,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,  1007,   919,   920,
     921,   922,   923,  1013,   924,   925,  1017,   926,   927,   928,
     929,   930,   931,   932,   933,   955,   977,  1018,   978,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1019,  1021,  1011,  1005,  1008,  1020,  1014,  1022,  1023,  1024,
    1025,  1026,  1027,  1028,  1053,  1031,  1032,  1033,  1034,  1035,
    1036,  1063,  1064,  1037,  1065,  1038,  1039,  1040,  1041,  1042,
    1089,  1043,  1091,  1044,  1045,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1093,  1102,  1103,  1054,  1056,  1057,  1058,  1060,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1085,  1086,  1087,  1088,  1105,
    1092,  1106,  1090,  1095,  1094,  1096,  1107,  1108,  1109,  1110,
    1111,  1115,  1116,  1119,  1120,  1121,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1131,  1129,  1130,  1132,  1133,  1134,  1135,
    1150,  1136,  1151,  1156,  1157,  1158,  1159,  1171,  1172,  1173,
    1174,  1177,  1188,  1175,  1176,  1180,  1186,  1187,  1191,  1192,
    1194,  1195,  1189,  1193,  1196,  1198,  1199,  1197,  1200,  1201,
    1202,  1205,  1282,   548,  1219,  1332,  1220,  1234,  1235,  1236,
    1237,   342,  1238,  1062,  1239,  1240,  1353,  1241,  1242,  1243,
    1244,  1245,  1352,   877,  1246,  1247,  1248,  1249,  1250,  1251,
    1252,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1284,
    1285,  1286,  1307,  1308,  1344,  1309,  1342,  1349,  1331,   509,
    1350,   826,   894,  1283,  1351,  1343,   799,   655,   374,  1339,
     440,   831,  1341,   662,   567,  1340,   362,  1271,     0,     0,
     729,     0,     0,  1270,     0,     0,     0,     0,     0,     0,
       0,     0,   740,   533,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   745,     0,     0,     0,   752
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-918))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     348,   349,   432,    11,    11,     1,   261,   355,     1,   263,
     265,   261,     1,     1,   261,   265,     1,   261,   265,     1,
       1,   265,   261,     8,     9,     1,   265,    12,     1,     1,
       1,   261,   263,    21,    19,   265,     1,   385,   263,   387,
      36,   261,    27,   261,   262,   265,    31,    32,     1,   263,
      46,   261,   261,    38,   402,   265,   265,    42,    43,   407,
      45,   194,   195,    52,     1,    36,    51,     1,   263,     3,
     418,   419,     6,   421,     1,    46,   993,   994,   995,   263,
      75,     1,   430,   431,    69,    70,   434,   194,   195,    74,
      24,    25,     1,    82,    21,     4,    81,     1,    87,     1,
      85,    86,    22,    23,    89,    87,    87,    92,    93,    29,
     263,    13,   261,     1,    48,    87,   265,   102,    52,     1,
       1,   263,   118,   108,   109,   118,   111,   112,   113,   114,
     115,    33,    34,   263,   122,    44,     1,    39,    47,    41,
     116,   126,   261,    25,     1,   118,   265,   118,    82,   134,
      84,   136,   137,   118,   139,   166,   167,   142,   143,     1,
     149,   146,    96,     1,   152,   118,    48,   150,     1,   145,
      52,   152,   157,    54,    55,    56,    57,    58,    59,    60,
      61,   118,   150,   531,   118,   105,   106,   107,   196,   196,
     110,   100,    94,    95,   179,   122,   181,   263,   118,   152,
     185,   103,   104,    36,   189,   190,   191,   192,   193,   118,
     130,   131,   197,   198,   118,   149,     1,   263,   263,   184,
     101,   206,   124,   125,     1,   152,   263,   147,   148,   163,
       1,   184,   263,   228,    14,    15,    16,   232,   140,   141,
      25,   263,   176,   213,   214,    87,   263,   184,   152,   151,
      83,   150,     1,   118,   135,   175,   241,   242,   160,   244,
     263,   118,   144,    48,   152,   250,   262,    52,   128,    40,
     255,   153,   154,   262,   262,   260,    25,   262,   264,   263,
     184,   262,    53,   261,   249,   118,   262,   120,   121,   262,
     262,   150,   261,   128,   261,     1,   184,   262,   265,    48,
      10,   264,    12,    52,    75,   187,    77,   261,    79,    80,
     152,   265,     1,   261,   152,   264,    26,   265,   264,   184,
      30,   264,   256,   264,   264,   262,    97,   184,   262,   162,
      36,   164,   165,   118,   264,   216,   264,   261,   264,   116,
     249,   264,   262,   264,   261,   264,   184,   180,   128,   251,
     252,   253,   264,   262,   264,   261,   264,   264,   262,   144,
     262,   249,   263,    52,   264,   194,   264,   249,   145,   264,
     264,   263,   263,   254,   262,   723,   150,    83,   163,   264,
     262,   262,   194,   261,     1,   264,     3,   264,   264,     6,
     264,   224,   249,    82,   264,   144,   264,   264,    87,   150,
     264,   264,     1,   264,   153,   154,   264,    24,    25,     8,
       9,   249,   118,    12,   120,   121,   264,   264,   264,   264,
      19,   264,   150,   256,   257,     1,   150,   264,    27,   262,
     264,    48,    31,    32,   264,    52,   264,   264,   187,    38,
     264,   264,   264,    42,    43,   875,    45,   264,   233,    25,
     264,   264,    51,   264,   264,   264,   162,   264,   164,   165,
     149,   264,   128,     5,   249,    82,   264,    84,   264,   264,
      69,    70,    48,   264,   180,    74,    52,   262,     1,    96,
     264,     4,    81,   264,   128,   264,    85,    86,   264,   264,
      89,   262,   264,    92,    93,    37,   264,   264,   264,   264,
     249,   118,   264,   102,   170,   171,   172,   173,   174,   108,
     109,   264,   111,   112,   113,   114,   115,   865,   224,   264,
     264,    44,    64,   264,    47,   873,   874,   126,   264,    71,
     264,   264,   149,   243,    76,   134,    78,   136,   137,   264,
     139,   264,   118,   142,   143,   264,   163,   146,    90,   264,
     256,   257,   842,   843,   844,   845,   846,   264,   157,   176,
      20,   264,   264,   264,   264,     1,   264,   264,   144,   264,
     264,   264,   264,   264,   116,   194,   264,   100,   264,   264,
     179,   123,   181,   264,   264,   264,   185,   163,   264,    49,
     189,   190,   191,   192,   193,   118,   138,   264,   197,   198,
       1,   264,   264,   264,   264,   264,    66,   206,   264,   264,
     264,   128,    13,    73,   156,   128,   158,   159,    54,    55,
      56,    57,    58,    59,    60,    61,     1,   194,   194,   128,
     194,    91,    33,    34,   194,   194,   194,    90,    39,   256,
      41,   194,   241,   242,   264,   244,   264,    22,    23,   261,
     264,   250,   128,   264,    29,   194,   255,   233,   194,   119,
     128,   260,   194,   194,   128,   101,    90,   127,   150,   194,
     128,   128,   128,   249,   217,   218,   219,   220,   221,   222,
     223,   150,   194,   194,   226,   194,     0,     1,   194,   128,
     128,     5,   194,    94,    95,   237,   128,   239,   128,   135,
     150,   128,   103,   104,   194,   128,   248,    21,   264,   169,
     194,    25,   264,   194,    28,   168,   258,   150,   128,   194,
     194,    35,   194,   124,   125,   150,   249,   194,   188,   194,
     105,   106,   107,   194,   261,   110,    50,   261,   264,   140,
     141,   261,   194,   118,   168,   194,   194,   200,    62,    63,
     151,    65,   150,   150,   264,   130,   131,     1,    72,   160,
     264,   264,   215,   264,   264,   150,   264,   264,   264,   264,
     264,   264,   147,   148,    88,   264,   200,   264,   264,   264,
     216,   150,   235,   236,    98,   150,   100,   150,   150,   150,
     150,   215,   245,   246,   247,   248,    40,   150,   194,   261,
     175,   150,   150,   117,   194,   258,   261,   261,   194,    53,
     194,   235,   236,   264,   150,   194,   194,   264,   254,   133,
     264,   245,   246,   247,   248,   150,   261,   194,   150,   150,
     150,    75,   150,    77,   258,    79,    80,   150,   264,   150,
     128,   150,   150,   261,   261,   264,   261,   150,   264,   261,
     251,   252,   253,    97,   168,   264,   261,   261,   261,   261,
     150,   261,   261,   177,   178,   150,   261,   261,   182,   183,
     201,   202,   203,   204,   205,   264,   207,   208,   261,   210,
     211,   212,   264,   264,   215,   261,   150,   261,   261,   261,
     261,   261,   150,   261,   225,   226,   227,   261,   229,   230,
     231,   278,   261,   234,   261,   261,   261,   238,   201,   202,
     203,   204,   205,   264,   207,   208,   261,   210,   211,   212,
     264,   264,   215,   264,   264,   264,   240,   264,   128,   264,
     264,   264,   225,   226,   227,   261,   229,   230,   231,   150,
     264,   234,   261,   150,   261,   238,   201,   202,   203,   204,
     205,   150,   207,   208,   264,   210,   211,   212,   264,   264,
     215,   150,   264,   264,   264,   264,   264,   264,   264,   264,
     225,   226,   227,   264,   229,   230,   231,   264,   261,   234,
     261,   261,   261,   238,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   194,   261,   261,
     261,   261,   261,   194,   261,   261,   150,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   150,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     150,   150,   261,   264,   264,   261,   264,   264,   150,   261,
     264,   150,   150,   128,   264,   261,   261,   261,   261,   261,
     261,   150,   150,   261,   150,   261,   261,   261,   261,   261,
     150,   261,   150,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   150,   128,   128,   264,   264,   264,   264,   264,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   128,
     261,   128,   264,   261,   264,   261,   128,   128,   150,   128,
     128,   261,   150,   150,   150,   194,   264,   150,   150,   150,
     150,   128,   150,   261,   150,   150,   261,   261,   261,   261,
     261,   155,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   155,   199,   261,   261,   261,   261,   261,   150,   194,
     150,   150,   265,   264,   150,   150,   261,   264,   261,   261,
     261,   261,   128,   316,   261,  1204,   261,   261,   261,   261,
     261,    74,   261,   784,   261,   261,  1348,   261,   261,   261,
     261,   261,  1346,   606,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,  1281,   261,  1277,  1334,   261,   261,
    1336,   553,   636,  1189,  1338,  1279,   520,   368,   127,  1269,
     187,   561,  1275,   380,   334,  1273,    98,  1142,    -1,    -1,
     448,    -1,    -1,  1140,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   465,   294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,   490
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   267,     0,     1,     5,    21,    25,    28,    35,    50,
      62,    63,    65,    72,    88,    98,   100,   117,   133,   168,
     177,   178,   182,   183,   240,   268,   273,   278,   296,   302,
     317,   337,   356,   370,   385,   392,   396,   406,   415,   438,
     448,   454,   458,   468,   532,   548,   569,   261,   262,   263,
     263,   338,   416,   449,   263,   459,   263,   533,   371,   439,
     357,   263,   263,   318,   386,   263,   263,   397,   407,   263,
       1,    36,    46,   118,   297,   298,   299,   300,   301,     1,
      13,    33,    34,    39,    41,    94,    95,   103,   104,   124,
     125,   140,   141,   151,   160,   251,   252,   253,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   150,   339,
     343,   150,   417,   421,   263,     1,    87,   455,   456,   457,
     263,     1,     8,     9,    12,    19,    27,    31,    32,    38,
      42,    43,    45,    51,    69,    70,    74,    81,    85,    86,
      89,    92,    93,   102,   108,   109,   111,   112,   113,   114,
     115,   126,   134,   136,   137,   139,   142,   143,   146,   157,
     179,   181,   185,   189,   190,   191,   192,   193,   197,   198,
     206,   241,   242,   244,   250,   255,   260,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   524,
     528,   529,   530,   531,   263,   263,   263,   263,     1,    54,
      55,    56,    57,    58,    59,    60,    61,   101,   135,   216,
     254,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     1,   116,   145,   274,   275,
     276,   277,   150,   319,   323,   263,     1,    40,    53,    75,
      77,    79,    80,    97,   570,   571,   572,   573,   574,   575,
     576,   577,   578,     1,    36,    83,   118,   120,   121,   162,
     164,   165,   180,   224,   256,   257,   279,   280,   281,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     263,   263,     1,   118,   393,   394,   395,   261,   264,   264,
     264,   262,   298,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   550,   263,   263,     1,    87,   152,   450,   451,
     452,   453,   264,   262,   456,     1,   118,   152,   184,   460,
     464,   465,   466,   467,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   525,   264,   521,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   262,
     470,     1,     4,    44,    47,   100,   118,   249,   534,   535,
     536,   537,   538,   542,   543,   544,     1,    25,    48,    52,
     144,   153,   154,   187,   249,   372,   373,   374,   375,   376,
     377,   378,   382,   383,   384,     1,   152,   184,   249,   440,
     444,   445,   446,   447,     1,    52,    82,    87,   149,   358,
     362,   363,   364,   368,   369,   261,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   262,   304,
     261,   264,   264,   262,   275,   263,     1,    21,   122,   152,
     387,   388,   389,   390,   391,   264,   264,   264,   264,   264,
     264,   264,   262,   571,   261,   264,   264,   264,   264,   264,
     264,   264,   282,   264,   264,   264,   264,   262,   280,     1,
     118,   184,   249,   398,   399,   400,   401,   402,     1,   118,
     184,   408,   409,   410,   411,   264,   262,   394,   150,   150,
     150,   261,   194,   128,   128,   194,   194,   128,   270,   270,
     128,   128,   194,   194,   128,   270,   194,   194,   194,   194,
     194,   261,     1,    22,    23,    29,   105,   106,   107,   110,
     118,   130,   131,   147,   148,   175,   340,   341,   342,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,     1,     3,     6,    24,    25,    48,    52,    82,    84,
      96,   118,   149,   163,   176,   256,   418,   419,   420,   422,
     423,   424,   425,   426,   427,   428,   432,   433,   434,   435,
     436,   437,   264,   264,   262,   451,   150,   261,   264,   264,
     461,   262,   465,   194,   270,   194,   270,   128,   150,   128,
     194,   194,   128,   150,   194,   128,   128,   128,   194,   194,
     194,   270,   150,   194,   128,   128,   270,   128,   128,   150,
     128,   128,   194,   194,   264,   194,   264,   270,   270,   194,
     270,   150,   194,   194,   194,   194,   195,   194,   195,   194,
     194,   270,   270,   128,   272,   150,   270,   194,   194,   194,
     194,   261,   545,   264,   264,   539,   264,   264,   262,   535,
     261,   264,   264,   379,   264,   264,   264,   264,   264,   262,
     373,   264,   441,   264,   262,   445,   261,   359,   264,   264,
     264,   262,   363,   150,   150,   150,   150,   150,   150,   150,
     150,   217,   218,   219,   220,   221,   222,   223,   150,   150,
     194,   261,   150,   150,   261,     1,    25,    48,    52,   118,
     144,   163,   233,   249,   320,   321,   322,   324,   325,   326,
     327,   328,   329,   333,   261,   264,   264,   264,   262,   388,
     194,   194,   194,   150,   194,   194,   270,   261,   150,   194,
     150,   150,   150,   150,   150,   264,   150,   128,   150,   150,
     261,   261,   264,   403,   264,   262,   399,   261,   264,   412,
     262,   409,   150,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   170,   171,   172,   173,   174,   269,   270,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   262,   341,   261,   264,
     264,   264,   264,   264,   429,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   419,   150,   150,   261,   261,   150,
     150,   264,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   201,   202,   203,   204,   205,   207,
     208,   210,   211,   212,   215,   225,   226,   227,   229,   230,
     231,   234,   238,   526,   527,   261,   201,   202,   203,   204,
     205,   207,   208,   210,   211,   212,   215,   225,   226,   227,
     229,   230,   231,   234,   238,   522,   523,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,    14,    15,    16,   271,   272,   261,   261,
     261,   261,   261,   261,   261,   264,   270,   194,   264,   150,
     150,   261,   150,   194,   264,   150,   128,   150,   150,   150,
     261,   150,   264,   150,   261,   264,   150,   150,   128,   366,
     367,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   264,   264,   334,   264,   264,   264,   330,
     264,   262,   321,   150,   150,   150,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   166,   167,   283,   284,   261,   261,   261,   261,   150,
     264,   150,   261,   150,   264,   261,   261,   269,   269,   269,
     269,   269,   128,   128,   270,   128,   128,   128,   128,   150,
     128,   128,   270,   270,   272,   261,   150,   213,   214,   150,
     150,   194,   264,   150,   150,   150,   150,   128,   150,   150,
     150,   261,   261,   261,   261,   261,   155,   462,   463,   261,
     265,   261,   265,   271,   271,   271,    11,   196,   546,   547,
     261,   261,    11,   196,   540,   541,   261,   261,   261,   261,
      20,    49,    66,    73,    91,   119,   127,   169,   188,   380,
     381,   261,   261,   261,   261,   261,   261,   155,   442,   443,
     261,    75,   228,   232,   360,   361,   261,   261,   199,   265,
     365,   150,   194,   264,   150,   150,   150,   264,   150,   261,
     261,   261,   261,   261,   265,   261,    90,   168,   200,   215,
     235,   236,   245,   246,   247,   248,   258,   404,   405,   261,
     261,    90,   168,   200,   215,   235,   236,   245,   246,   247,
     248,   258,   413,   414,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,    10,    12,    26,    30,   243,   430,   431,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   265,
     527,   523,   261,   265,   261,   265,   261,   265,   261,   265,
     261,   265,   128,   367,   261,   261,   261,     5,    37,    64,
      71,    76,    78,    90,   116,   123,   138,   156,   158,   159,
     226,   237,   239,   248,   258,   335,   336,   261,   261,   261,
     201,   202,   203,   204,   205,   207,   208,   210,   211,   212,
     215,   225,   226,   227,   229,   230,   231,   234,   238,   331,
     332,   261,   284,   261,   265,   261,   265,   261,   265,   463,
     547,   541,   381,   443,   361,   261,   265,   261,   265,   405,
     414,   431,   336,   332
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
#line 424 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 426 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 430 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 434 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 442 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 446 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 451 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 469 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 495 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 501 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
  {
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_SSLV3))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_TLSV1))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
  }
#endif
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 515 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 521 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 529 "ircd_parser.y"
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
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 563 "ircd_parser.y"
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

  case 73:

/* Line 1806 of yacc.c  */
#line 623 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 638 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 653 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 662 "ircd_parser.y"
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

  case 77:

/* Line 1806 of yacc.c  */
#line 676 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 685 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
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

  case 79:

/* Line 1806 of yacc.c  */
#line 713 "ircd_parser.y"
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
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
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

  case 80:

/* Line 1806 of yacc.c  */
#line 743 "ircd_parser.y"
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

  case 81:

/* Line 1806 of yacc.c  */
#line 766 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 781 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 790 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 799 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 826 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 830 "ircd_parser.y"
    {
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 834 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 841 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 848 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 855 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 862 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 869 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 876 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 883 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 890 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 894 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 898 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 906 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 910 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 914 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 920 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 929 "ircd_parser.y"
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

  case 127:

/* Line 1806 of yacc.c  */
#line 942 "ircd_parser.y"
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1029 "ircd_parser.y"
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1041 "ircd_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1053 "ircd_parser.y"
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1087 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1099 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1110 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1152 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1161 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1168 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1172 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1176 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1180 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1184 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1188 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1192 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1196 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1200 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1204 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1208 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1212 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1216 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1220 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1224 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1228 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1232 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1236 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1240 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1246 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1253 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1257 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1261 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1265 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1273 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1277 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1281 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1285 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1289 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1293 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1297 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1301 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1305 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1309 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1313 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1317 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1321 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1331 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1338 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
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

  case 213:

/* Line 1806 of yacc.c  */
#line 1398 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1407 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1416 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1422 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1428 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1434 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1440 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1446 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1452 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1464 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1470 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1476 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1482 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1491 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1498 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1507 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1513 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1517 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1521 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1531 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 247:

/* Line 1806 of yacc.c  */
#line 1536 "ircd_parser.y"
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

  case 248:

/* Line 1806 of yacc.c  */
#line 1550 "ircd_parser.y"
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

  case 249:

/* Line 1806 of yacc.c  */
#line 1570 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1579 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 1591 "ircd_parser.y"
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

  case 252:

/* Line 1806 of yacc.c  */
#line 1603 "ircd_parser.y"
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

  case 264:

/* Line 1806 of yacc.c  */
#line 1665 "ircd_parser.y"
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

  case 265:

/* Line 1806 of yacc.c  */
#line 1702 "ircd_parser.y"
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

  case 266:

/* Line 1806 of yacc.c  */
#line 1715 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1724 "ircd_parser.y"
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

  case 268:

/* Line 1806 of yacc.c  */
#line 1735 "ircd_parser.y"
    {
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1740 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1744 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1748 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1752 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1756 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1760 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1764 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1768 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1772 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1779 "ircd_parser.y"
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
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1798 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1808 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1821 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1828 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1849 "ircd_parser.y"
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

  case 294:

/* Line 1806 of yacc.c  */
#line 1864 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1882 "ircd_parser.y"
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

  case 301:

/* Line 1806 of yacc.c  */
#line 1897 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1905 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1925 "ircd_parser.y"
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

  case 311:

/* Line 1806 of yacc.c  */
#line 1947 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1954 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1958 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1962 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1966 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1970 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1974 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1978 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1982 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1986 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1990 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1994 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2003 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2010 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2023 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2029 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2036 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2040 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2044 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2048 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2052 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2056 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2060 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2064 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2068 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2072 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2076 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2085 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 350:

/* Line 1806 of yacc.c  */
#line 2103 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 370:

/* Line 1806 of yacc.c  */
#line 2241 "ircd_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2253 "ircd_parser.y"
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

  case 372:

/* Line 1806 of yacc.c  */
#line 2265 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2274 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
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

  case 374:

/* Line 1806 of yacc.c  */
#line 2300 "ircd_parser.y"
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

  case 375:

/* Line 1806 of yacc.c  */
#line 2318 "ircd_parser.y"
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

  case 376:

/* Line 1806 of yacc.c  */
#line 2336 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2342 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2346 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2354 "ircd_parser.y"
    {
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2359 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   SetConfCompressed(yy_aconf);
 }
#endif
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2369 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2373 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2377 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2381 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 2387 "ircd_parser.y"
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

  case 389:

/* Line 1806 of yacc.c  */
#line 2428 "ircd_parser.y"
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

  case 390:

/* Line 1806 of yacc.c  */
#line 2439 "ircd_parser.y"
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

  case 391:

/* Line 1806 of yacc.c  */
#line 2452 "ircd_parser.y"
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

  case 392:

/* Line 1806 of yacc.c  */
#line 2465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 2474 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
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
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 2509 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 2516 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s",
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
        ilog(L_ERROR, "Failed to add regular expression based K-Line: no PCRE support");
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

  case 396:

/* Line 1806 of yacc.c  */
#line 2572 "ircd_parser.y"
    {
}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 2577 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 2586 "ircd_parser.y"
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

  case 408:

/* Line 1806 of yacc.c  */
#line 2605 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 409:

/* Line 1806 of yacc.c  */
#line 2614 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 2618 "ircd_parser.y"
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

  case 416:

/* Line 1806 of yacc.c  */
#line 2640 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 2646 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 2660 "ircd_parser.y"
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

  case 424:

/* Line 1806 of yacc.c  */
#line 2678 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 2685 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
#else
        ilog(L_ERROR, "Failed to add regular expression based X-Line: no PCRE support");
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

  case 426:

/* Line 1806 of yacc.c  */
#line 2725 "ircd_parser.y"
    {
}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 2730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 437:

/* Line 1806 of yacc.c  */
#line 2739 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 438:

/* Line 1806 of yacc.c  */
#line 2745 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2790 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2795 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2800 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2805 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2810 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2815 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2820 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2825 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2830 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2835 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2840 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2845 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2850 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2855 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2860 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2865 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2870 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2875 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2880 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2886 "ircd_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2911 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2916 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2921 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2926 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2931 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2939 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2944 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2947 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2952 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2957 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2962 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2967 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2972 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2977 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2982 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2987 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2992 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3003 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3008 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3013 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3022 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
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
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3054 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 543:

/* Line 1806 of yacc.c  */
#line 3072 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3077 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3086 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3095 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3100 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3105 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3110 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3116 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3119 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3122 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3125 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3128 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3131 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3134 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3140 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3143 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3146 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3149 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3155 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3158 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3161 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3164 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3167 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3175 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3181 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3184 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3187 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3190 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3193 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3196 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3199 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3202 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3205 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3208 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3211 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3214 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3217 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3220 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3223 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3226 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3229 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3232 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3235 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3250 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3264 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3271 "ircd_parser.y"
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

  case 610:

/* Line 1806 of yacc.c  */
#line 3297 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 3303 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3309 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 3315 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 3319 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 618:

/* Line 1806 of yacc.c  */
#line 3325 "ircd_parser.y"
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

  case 619:

/* Line 1806 of yacc.c  */
#line 3359 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 3368 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 3372 "ircd_parser.y"
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

  case 624:

/* Line 1806 of yacc.c  */
#line 3419 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 3423 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3447 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3452 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3457 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3462 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3467 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3472 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3477 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3482 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3487 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 3492 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3497 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3502 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3512 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3517 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3522 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3527 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3532 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 3551 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 3557 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 679:

/* Line 1806 of yacc.c  */
#line 3563 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 680:

/* Line 1806 of yacc.c  */
#line 3572 "ircd_parser.y"
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

  case 681:

/* Line 1806 of yacc.c  */
#line 3586 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 682:

/* Line 1806 of yacc.c  */
#line 3592 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 683:

/* Line 1806 of yacc.c  */
#line 3598 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7975 "ircd_parser.c"
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



