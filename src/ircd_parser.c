
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

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

/* Line 189 of yacc.c  */
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



/* Line 189 of yacc.c  */
#line 181 "ircd_parser.c"

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
     DOTS_IN_IDENT = 299,
     DURATION = 300,
     EGDPOOL_PATH = 301,
     EMAIL = 302,
     ENABLE = 303,
     ENCRYPTED = 304,
     EXCEED_LIMIT = 305,
     EXEMPT = 306,
     FAILED_OPER_NOTICE = 307,
     FAKENAME = 308,
     IRCD_FLAGS = 309,
     FLATTEN_LINKS = 310,
     FFAILED_OPERLOG = 311,
     FKILLLOG = 312,
     FKLINELOG = 313,
     FGLINELOG = 314,
     FIOERRLOG = 315,
     FOPERLOG = 316,
     FOPERSPYLOG = 317,
     FUSERLOG = 318,
     GECOS = 319,
     GENERAL = 320,
     GLINE = 321,
     GLINES = 322,
     GLINE_EXEMPT = 323,
     GLINE_LOG = 324,
     GLINE_TIME = 325,
     GLINE_MIN_CIDR = 326,
     GLINE_MIN_CIDR6 = 327,
     GLOBAL_KILL = 328,
     IRCD_AUTH = 329,
     NEED_IDENT = 330,
     HAVENT_READ_CONF = 331,
     HIDDEN = 332,
     HIDDEN_ADMIN = 333,
     HIDDEN_NAME = 334,
     HIDDEN_OPER = 335,
     HIDE_SERVER_IPS = 336,
     HIDE_SERVERS = 337,
     HIDE_SPOOF_IPS = 338,
     HOST = 339,
     HUB = 340,
     HUB_MASK = 341,
     IDLETIME = 342,
     IGNORE_BOGUS_TS = 343,
     INVISIBLE_ON_CONNECT = 344,
     IP = 345,
     KILL = 346,
     KILL_CHASE_TIME_LIMIT = 347,
     KLINE = 348,
     KLINE_EXEMPT = 349,
     KLINE_REASON = 350,
     KLINE_WITH_REASON = 351,
     KNOCK_DELAY = 352,
     KNOCK_DELAY_CHANNEL = 353,
     LEAF_MASK = 354,
     LINKS_DELAY = 355,
     LISTEN = 356,
     T_LOG = 357,
     LOGGING = 358,
     LOG_LEVEL = 359,
     MAX_ACCEPT = 360,
     MAX_BANS = 361,
     MAX_CHANS_PER_USER = 362,
     MAX_GLOBAL = 363,
     MAX_IDENT = 364,
     MAX_LOCAL = 365,
     MAX_NICK_CHANGES = 366,
     MAX_NICK_TIME = 367,
     MAX_NUMBER = 368,
     MAX_TARGETS = 369,
     MAX_WATCH = 370,
     MESSAGE_LOCALE = 371,
     MIN_NONWILDCARD = 372,
     MIN_NONWILDCARD_SIMPLE = 373,
     MODULE = 374,
     MODULES = 375,
     NAME = 376,
     NEED_PASSWORD = 377,
     NETWORK_DESC = 378,
     NETWORK_NAME = 379,
     NICK = 380,
     NICK_CHANGES = 381,
     NO_CREATE_ON_SPLIT = 382,
     NO_JOIN_ON_SPLIT = 383,
     NO_OPER_FLOOD = 384,
     NO_TILDE = 385,
     NOT = 386,
     NUMBER = 387,
     NUMBER_PER_IDENT = 388,
     NUMBER_PER_CIDR = 389,
     NUMBER_PER_IP = 390,
     NUMBER_PER_IP_GLOBAL = 391,
     OPERATOR = 392,
     OPERS_BYPASS_CALLERID = 393,
     OPER_LOG = 394,
     OPER_ONLY_UMODES = 395,
     OPER_PASS_RESV = 396,
     OPER_SPY_T = 397,
     OPER_UMODES = 398,
     JOIN_FLOOD_COUNT = 399,
     JOIN_FLOOD_TIME = 400,
     PACE_WAIT = 401,
     PACE_WAIT_SIMPLE = 402,
     PASSWORD = 403,
     PATH = 404,
     PING_COOKIE = 405,
     PING_TIME = 406,
     PING_WARNING = 407,
     PORT = 408,
     QSTRING = 409,
     QUIET_ON_BAN = 410,
     REASON = 411,
     REDIRPORT = 412,
     REDIRSERV = 413,
     REGEX_T = 414,
     REHASH = 415,
     TREJECT_HOLD_TIME = 416,
     REMOTE = 417,
     REMOTEBAN = 418,
     RESTRICT_CHANNELS = 419,
     RESTRICTED = 420,
     RSA_PRIVATE_KEY_FILE = 421,
     RSA_PUBLIC_KEY_FILE = 422,
     SSL_CERTIFICATE_FILE = 423,
     T_SSL_CONNECTION_METHOD = 424,
     T_SSLV3 = 425,
     T_TLSV1 = 426,
     RESV = 427,
     RESV_EXEMPT = 428,
     SECONDS = 429,
     MINUTES = 430,
     HOURS = 431,
     DAYS = 432,
     WEEKS = 433,
     SENDQ = 434,
     SEND_PASSWORD = 435,
     SERVERHIDE = 436,
     SERVERINFO = 437,
     SERVLINK_PATH = 438,
     IRCD_SID = 439,
     TKLINE_EXPIRE_NOTICES = 440,
     T_SHARED = 441,
     T_CLUSTER = 442,
     TYPE = 443,
     SHORT_MOTD = 444,
     SILENT = 445,
     SPOOF = 446,
     SPOOF_NOTICE = 447,
     STATS_E_DISABLED = 448,
     STATS_I_OPER_ONLY = 449,
     STATS_K_OPER_ONLY = 450,
     STATS_O_OPER_ONLY = 451,
     STATS_P_OPER_ONLY = 452,
     TBOOL = 453,
     TMASKED = 454,
     T_REJECT = 455,
     TS_MAX_DELTA = 456,
     TS_WARN_DELTA = 457,
     TWODOTS = 458,
     T_ALL = 459,
     T_BOTS = 460,
     T_SOFTCALLERID = 461,
     T_CALLERID = 462,
     T_CCONN = 463,
     T_CCONN_FULL = 464,
     T_CLIENT_FLOOD = 465,
     T_DEAF = 466,
     T_DEBUG = 467,
     T_DRONE = 468,
     T_EXTERNAL = 469,
     T_FULL = 470,
     T_INVISIBLE = 471,
     T_IPV4 = 472,
     T_IPV6 = 473,
     T_LOCOPS = 474,
     T_LOGPATH = 475,
     T_L_CRIT = 476,
     T_L_DEBUG = 477,
     T_L_ERROR = 478,
     T_L_INFO = 479,
     T_L_NOTICE = 480,
     T_L_TRACE = 481,
     T_L_WARN = 482,
     T_MAX_CLIENTS = 483,
     T_NCHANGE = 484,
     T_OPERWALL = 485,
     T_REJ = 486,
     T_SERVER = 487,
     T_SERVNOTICE = 488,
     T_SKILL = 489,
     T_SPY = 490,
     T_SSL = 491,
     T_UMODES = 492,
     T_UNAUTH = 493,
     T_UNRESV = 494,
     T_UNXLINE = 495,
     T_WALLOP = 496,
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
#define DOTS_IN_IDENT 299
#define DURATION 300
#define EGDPOOL_PATH 301
#define EMAIL 302
#define ENABLE 303
#define ENCRYPTED 304
#define EXCEED_LIMIT 305
#define EXEMPT 306
#define FAILED_OPER_NOTICE 307
#define FAKENAME 308
#define IRCD_FLAGS 309
#define FLATTEN_LINKS 310
#define FFAILED_OPERLOG 311
#define FKILLLOG 312
#define FKLINELOG 313
#define FGLINELOG 314
#define FIOERRLOG 315
#define FOPERLOG 316
#define FOPERSPYLOG 317
#define FUSERLOG 318
#define GECOS 319
#define GENERAL 320
#define GLINE 321
#define GLINES 322
#define GLINE_EXEMPT 323
#define GLINE_LOG 324
#define GLINE_TIME 325
#define GLINE_MIN_CIDR 326
#define GLINE_MIN_CIDR6 327
#define GLOBAL_KILL 328
#define IRCD_AUTH 329
#define NEED_IDENT 330
#define HAVENT_READ_CONF 331
#define HIDDEN 332
#define HIDDEN_ADMIN 333
#define HIDDEN_NAME 334
#define HIDDEN_OPER 335
#define HIDE_SERVER_IPS 336
#define HIDE_SERVERS 337
#define HIDE_SPOOF_IPS 338
#define HOST 339
#define HUB 340
#define HUB_MASK 341
#define IDLETIME 342
#define IGNORE_BOGUS_TS 343
#define INVISIBLE_ON_CONNECT 344
#define IP 345
#define KILL 346
#define KILL_CHASE_TIME_LIMIT 347
#define KLINE 348
#define KLINE_EXEMPT 349
#define KLINE_REASON 350
#define KLINE_WITH_REASON 351
#define KNOCK_DELAY 352
#define KNOCK_DELAY_CHANNEL 353
#define LEAF_MASK 354
#define LINKS_DELAY 355
#define LISTEN 356
#define T_LOG 357
#define LOGGING 358
#define LOG_LEVEL 359
#define MAX_ACCEPT 360
#define MAX_BANS 361
#define MAX_CHANS_PER_USER 362
#define MAX_GLOBAL 363
#define MAX_IDENT 364
#define MAX_LOCAL 365
#define MAX_NICK_CHANGES 366
#define MAX_NICK_TIME 367
#define MAX_NUMBER 368
#define MAX_TARGETS 369
#define MAX_WATCH 370
#define MESSAGE_LOCALE 371
#define MIN_NONWILDCARD 372
#define MIN_NONWILDCARD_SIMPLE 373
#define MODULE 374
#define MODULES 375
#define NAME 376
#define NEED_PASSWORD 377
#define NETWORK_DESC 378
#define NETWORK_NAME 379
#define NICK 380
#define NICK_CHANGES 381
#define NO_CREATE_ON_SPLIT 382
#define NO_JOIN_ON_SPLIT 383
#define NO_OPER_FLOOD 384
#define NO_TILDE 385
#define NOT 386
#define NUMBER 387
#define NUMBER_PER_IDENT 388
#define NUMBER_PER_CIDR 389
#define NUMBER_PER_IP 390
#define NUMBER_PER_IP_GLOBAL 391
#define OPERATOR 392
#define OPERS_BYPASS_CALLERID 393
#define OPER_LOG 394
#define OPER_ONLY_UMODES 395
#define OPER_PASS_RESV 396
#define OPER_SPY_T 397
#define OPER_UMODES 398
#define JOIN_FLOOD_COUNT 399
#define JOIN_FLOOD_TIME 400
#define PACE_WAIT 401
#define PACE_WAIT_SIMPLE 402
#define PASSWORD 403
#define PATH 404
#define PING_COOKIE 405
#define PING_TIME 406
#define PING_WARNING 407
#define PORT 408
#define QSTRING 409
#define QUIET_ON_BAN 410
#define REASON 411
#define REDIRPORT 412
#define REDIRSERV 413
#define REGEX_T 414
#define REHASH 415
#define TREJECT_HOLD_TIME 416
#define REMOTE 417
#define REMOTEBAN 418
#define RESTRICT_CHANNELS 419
#define RESTRICTED 420
#define RSA_PRIVATE_KEY_FILE 421
#define RSA_PUBLIC_KEY_FILE 422
#define SSL_CERTIFICATE_FILE 423
#define T_SSL_CONNECTION_METHOD 424
#define T_SSLV3 425
#define T_TLSV1 426
#define RESV 427
#define RESV_EXEMPT 428
#define SECONDS 429
#define MINUTES 430
#define HOURS 431
#define DAYS 432
#define WEEKS 433
#define SENDQ 434
#define SEND_PASSWORD 435
#define SERVERHIDE 436
#define SERVERINFO 437
#define SERVLINK_PATH 438
#define IRCD_SID 439
#define TKLINE_EXPIRE_NOTICES 440
#define T_SHARED 441
#define T_CLUSTER 442
#define TYPE 443
#define SHORT_MOTD 444
#define SILENT 445
#define SPOOF 446
#define SPOOF_NOTICE 447
#define STATS_E_DISABLED 448
#define STATS_I_OPER_ONLY 449
#define STATS_K_OPER_ONLY 450
#define STATS_O_OPER_ONLY 451
#define STATS_P_OPER_ONLY 452
#define TBOOL 453
#define TMASKED 454
#define T_REJECT 455
#define TS_MAX_DELTA 456
#define TS_WARN_DELTA 457
#define TWODOTS 458
#define T_ALL 459
#define T_BOTS 460
#define T_SOFTCALLERID 461
#define T_CALLERID 462
#define T_CCONN 463
#define T_CCONN_FULL 464
#define T_CLIENT_FLOOD 465
#define T_DEAF 466
#define T_DEBUG 467
#define T_DRONE 468
#define T_EXTERNAL 469
#define T_FULL 470
#define T_INVISIBLE 471
#define T_IPV4 472
#define T_IPV6 473
#define T_LOCOPS 474
#define T_LOGPATH 475
#define T_L_CRIT 476
#define T_L_DEBUG 477
#define T_L_ERROR 478
#define T_L_INFO 479
#define T_L_NOTICE 480
#define T_L_TRACE 481
#define T_L_WARN 482
#define T_MAX_CLIENTS 483
#define T_NCHANGE 484
#define T_OPERWALL 485
#define T_REJ 486
#define T_SERVER 487
#define T_SERVNOTICE 488
#define T_SKILL 489
#define T_SPY 490
#define T_SSL 491
#define T_UMODES 492
#define T_UNAUTH 493
#define T_UNRESV 494
#define T_UNXLINE 495
#define T_WALLOP 496
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

/* Line 214 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 214 of yacc.c  */
#line 744 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 756 "ircd_parser.c"

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  345
/* YYNRULES -- Number of rules.  */
#define YYNRULES  741
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1489

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
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   163,   164,   170,   174,   176,   178,
     180,   185,   190,   195,   200,   205,   210,   215,   220,   225,
     230,   235,   241,   244,   246,   248,   250,   252,   255,   260,
     265,   270,   276,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   308,   313,   318,
     323,   328,   333,   338,   343,   348,   353,   358,   363,   368,
     373,   378,   383,   388,   393,   398,   399,   407,   408,   410,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   437,   439,   441,   443,   445,   447,   449,   451,
     453,   455,   457,   459,   462,   467,   469,   474,   479,   484,
     489,   494,   495,   501,   505,   507,   509,   511,   513,   515,
     517,   519,   521,   523,   525,   527,   529,   531,   533,   535,
     537,   539,   541,   543,   545,   550,   555,   560,   565,   570,
     575,   580,   585,   590,   595,   600,   605,   610,   615,   616,
     622,   626,   628,   629,   633,   634,   637,   639,   641,   643,
     645,   647,   649,   651,   653,   655,   657,   659,   661,   663,
     665,   667,   669,   670,   678,   679,   681,   684,   686,   688,
     690,   692,   694,   696,   698,   700,   702,   704,   706,   708,
     710,   712,   715,   720,   722,   727,   732,   737,   742,   747,
     752,   757,   762,   767,   772,   777,   782,   783,   790,   791,
     797,   801,   803,   805,   807,   809,   812,   814,   816,   818,
     820,   822,   825,   826,   832,   836,   838,   840,   844,   849,
     854,   855,   862,   865,   867,   869,   871,   873,   875,   877,
     879,   881,   883,   885,   887,   889,   891,   893,   895,   897,
     899,   902,   907,   912,   917,   922,   927,   928,   934,   938,
     940,   941,   945,   946,   949,   951,   953,   955,   957,   959,
     961,   963,   965,   967,   969,   974,   979,   984,   989,   994,
     999,  1004,  1009,  1014,  1019,  1020,  1027,  1030,  1032,  1034,
    1036,  1038,  1041,  1046,  1051,  1056,  1057,  1064,  1067,  1069,
    1071,  1073,  1075,  1078,  1083,  1088,  1089,  1095,  1099,  1101,
    1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,  1119,  1121,
    1123,  1124,  1131,  1134,  1136,  1138,  1140,  1143,  1148,  1149,
    1155,  1159,  1161,  1163,  1165,  1167,  1169,  1171,  1173,  1175,
    1177,  1179,  1181,  1183,  1184,  1192,  1193,  1195,  1198,  1200,
    1202,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,  1220,
    1222,  1224,  1226,  1228,  1230,  1232,  1234,  1236,  1238,  1241,
    1246,  1248,  1253,  1258,  1263,  1268,  1273,  1278,  1283,  1288,
    1289,  1295,  1299,  1301,  1302,  1306,  1307,  1310,  1312,  1314,
    1316,  1318,  1320,  1325,  1330,  1335,  1340,  1345,  1350,  1355,
    1360,  1365,  1370,  1371,  1378,  1379,  1385,  1389,  1391,  1393,
    1396,  1398,  1400,  1402,  1404,  1406,  1411,  1416,  1417,  1424,
    1427,  1429,  1431,  1433,  1435,  1440,  1445,  1451,  1454,  1456,
    1458,  1460,  1465,  1466,  1473,  1474,  1480,  1484,  1486,  1488,
    1491,  1493,  1495,  1497,  1499,  1501,  1506,  1511,  1517,  1520,
    1522,  1524,  1526,  1528,  1530,  1532,  1534,  1536,  1538,  1540,
    1542,  1544,  1546,  1548,  1550,  1552,  1554,  1556,  1558,  1560,
    1562,  1564,  1566,  1568,  1570,  1572,  1574,  1576,  1578,  1580,
    1582,  1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,  1600,
    1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,  1618,  1620,
    1622,  1624,  1626,  1628,  1630,  1632,  1634,  1639,  1644,  1649,
    1654,  1659,  1664,  1669,  1674,  1679,  1684,  1689,  1694,  1699,
    1704,  1709,  1714,  1719,  1724,  1729,  1734,  1739,  1744,  1749,
    1754,  1759,  1764,  1769,  1774,  1779,  1784,  1789,  1794,  1799,
    1804,  1809,  1814,  1819,  1824,  1829,  1834,  1839,  1844,  1849,
    1854,  1859,  1864,  1869,  1874,  1879,  1884,  1889,  1890,  1896,
    1900,  1902,  1904,  1906,  1908,  1910,  1912,  1914,  1916,  1918,
    1920,  1922,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1941,  1947,  1951,  1953,  1955,  1957,  1959,  1961,  1963,
    1965,  1967,  1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,
    1985,  1987,  1989,  1991,  1996,  2001,  2006,  2011,  2012,  2019,
    2022,  2024,  2026,  2028,  2030,  2032,  2034,  2036,  2038,  2043,
    2048,  2049,  2055,  2059,  2061,  2063,  2065,  2070,  2075,  2076,
    2082,  2086,  2088,  2090,  2092,  2098,  2101,  2103,  2105,  2107,
    2109,  2111,  2113,  2115,  2117,  2119,  2121,  2123,  2125,  2127,
    2129,  2131,  2133,  2135,  2137,  2139,  2141,  2146,  2151,  2156,
    2161,  2166,  2171,  2176,  2181,  2186,  2191,  2196,  2201,  2206,
    2211,  2216,  2221,  2226,  2231,  2237,  2240,  2242,  2244,  2246,
    2248,  2250,  2252,  2254,  2256,  2258,  2263,  2268,  2273,  2278,
    2283,  2288
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,    -1,   267,   268,    -1,   296,    -1,   302,
      -1,   317,    -1,   580,    -1,   354,    -1,   373,    -1,   387,
      -1,   278,    -1,   601,    -1,   413,    -1,   420,    -1,   430,
      -1,   439,    -1,   470,    -1,   480,    -1,   486,    -1,   500,
      -1,   564,    -1,   490,    -1,   273,    -1,     1,   261,    -1,
       1,   262,    -1,    -1,   270,    -1,   132,   269,    -1,   132,
     174,   269,    -1,   132,   175,   269,    -1,   132,   176,   269,
      -1,   132,   177,   269,    -1,   132,   178,   269,    -1,    -1,
     272,    -1,   132,   271,    -1,   132,    14,   271,    -1,   132,
      15,   271,    -1,   132,    16,   271,    -1,   120,   263,   274,
     262,   261,    -1,   274,   275,    -1,   275,    -1,   276,    -1,
     277,    -1,     1,   261,    -1,   119,   264,   154,   261,    -1,
     149,   264,   154,   261,    -1,   182,   263,   279,   262,   261,
      -1,   279,   280,    -1,   280,    -1,   287,    -1,   292,    -1,
     295,    -1,   289,    -1,   290,    -1,   291,    -1,   294,    -1,
     286,    -1,   293,    -1,   288,    -1,   285,    -1,   281,    -1,
       1,   261,    -1,    -1,   169,   282,   264,   283,   261,    -1,
     283,   265,   284,    -1,   284,    -1,   170,    -1,   171,    -1,
     168,   264,   154,   261,    -1,   166,   264,   154,   261,    -1,
     121,   264,   154,   261,    -1,   184,   264,   154,   261,    -1,
      37,   264,   154,   261,    -1,   124,   264,   154,   261,    -1,
     123,   264,   154,   261,    -1,   256,   264,   154,   261,    -1,
     257,   264,   154,   261,    -1,   228,   264,   132,   261,    -1,
      85,   264,   198,   261,    -1,     5,   263,   297,   262,   261,
      -1,   297,   298,    -1,   298,    -1,   299,    -1,   301,    -1,
     300,    -1,     1,   261,    -1,   121,   264,   154,   261,    -1,
      47,   264,   154,   261,    -1,    37,   264,   154,   261,    -1,
     103,   263,   303,   262,   261,    -1,   303,   304,    -1,   304,
      -1,   305,    -1,   306,    -1,   315,    -1,   316,    -1,   307,
      -1,   309,    -1,   311,    -1,   312,    -1,   314,    -1,   310,
      -1,   313,    -1,   308,    -1,     1,   261,    -1,   220,   264,
     154,   261,    -1,   139,   264,   154,   261,    -1,    63,   264,
     154,   261,    -1,    56,   264,   154,   261,    -1,    61,   264,
     154,   261,    -1,    62,   264,   154,   261,    -1,    59,   264,
     154,   261,    -1,    58,   264,   154,   261,    -1,    60,   264,
     154,   261,    -1,    57,   264,   154,   261,    -1,   104,   264,
     221,   261,    -1,   104,   264,   223,   261,    -1,   104,   264,
     227,   261,    -1,   104,   264,   225,   261,    -1,   104,   264,
     226,   261,    -1,   104,   264,   224,   261,    -1,   104,   264,
     222,   261,    -1,   254,   264,   198,   261,    -1,    -1,   137,
     318,   319,   263,   320,   262,   261,    -1,    -1,   323,    -1,
     320,   321,    -1,   321,    -1,   322,    -1,   324,    -1,   325,
      -1,   344,    -1,   345,    -1,   329,    -1,   328,    -1,   333,
      -1,   334,    -1,   336,    -1,   337,    -1,   338,    -1,   339,
      -1,   340,    -1,   335,    -1,   341,    -1,   342,    -1,   343,
      -1,   346,    -1,   326,    -1,   327,    -1,   347,    -1,     1,
     261,    -1,   121,   264,   154,   261,    -1,   154,    -1,   249,
     264,   154,   261,    -1,   148,   264,   154,   261,    -1,    49,
     264,   198,   261,    -1,   167,   264,   154,   261,    -1,    26,
     264,   154,   261,    -1,    -1,   237,   330,   264,   331,   261,
      -1,   331,   265,   332,    -1,   332,    -1,   205,    -1,   208,
      -1,   209,    -1,   211,    -1,   212,    -1,   215,    -1,   234,
      -1,   229,    -1,   231,    -1,   238,    -1,   235,    -1,   214,
      -1,   230,    -1,   233,    -1,   216,    -1,   241,    -1,   206,
      -1,   207,    -1,   219,    -1,    73,   264,   198,   261,    -1,
     162,   264,   198,   261,    -1,   163,   264,   198,   261,    -1,
      93,   264,   198,   261,    -1,   258,   264,   198,   261,    -1,
     248,   264,   198,   261,    -1,    66,   264,   198,   261,    -1,
     126,   264,   198,   261,    -1,    38,   264,   198,   261,    -1,
     160,   264,   198,   261,    -1,     5,   264,   198,   261,    -1,
      78,   264,   198,   261,    -1,    80,   264,   198,   261,    -1,
     230,   264,   198,   261,    -1,    -1,    54,   348,   264,   349,
     261,    -1,   349,   265,   350,    -1,   350,    -1,    -1,   131,
     351,   353,    -1,    -1,   352,   353,    -1,    73,    -1,   162,
      -1,    93,    -1,   248,    -1,   258,    -1,    66,    -1,    38,
      -1,   160,    -1,     5,    -1,    78,    -1,   126,    -1,   230,
      -1,   142,    -1,    80,    -1,   163,    -1,    49,    -1,    -1,
      26,   355,   356,   263,   357,   262,   261,    -1,    -1,   360,
      -1,   357,   358,    -1,   358,    -1,   359,    -1,   370,    -1,
     371,    -1,   361,    -1,   362,    -1,   372,    -1,   363,    -1,
     364,    -1,   365,    -1,   366,    -1,   367,    -1,   368,    -1,
     369,    -1,     1,   261,    -1,   121,   264,   154,   261,    -1,
     154,    -1,   151,   264,   270,   261,    -1,   152,   264,   270,
     261,    -1,   135,   264,   132,   261,    -1,    30,   264,   270,
     261,    -1,   113,   264,   132,   261,    -1,   108,   264,   132,
     261,    -1,   110,   264,   132,   261,    -1,   109,   264,   132,
     261,    -1,   179,   264,   272,   261,    -1,    23,   264,   132,
     261,    -1,    24,   264,   132,   261,    -1,   134,   264,   132,
     261,    -1,    -1,   101,   374,   263,   379,   262,   261,    -1,
      -1,    54,   376,   264,   377,   261,    -1,   377,   265,   378,
      -1,   378,    -1,   236,    -1,    77,    -1,   232,    -1,   379,
     380,    -1,   380,    -1,   381,    -1,   375,    -1,   385,    -1,
     386,    -1,     1,   261,    -1,    -1,   153,   264,   383,   382,
     261,    -1,   383,   265,   384,    -1,   384,    -1,   132,    -1,
     132,   203,   132,    -1,    90,   264,   154,   261,    -1,    84,
     264,   154,   261,    -1,    -1,    74,   388,   263,   389,   262,
     261,    -1,   389,   390,    -1,   390,    -1,   391,    -1,   392,
      -1,   394,    -1,   396,    -1,   403,    -1,   404,    -1,   405,
      -1,   407,    -1,   408,    -1,   409,    -1,   393,    -1,   410,
      -1,   411,    -1,   406,    -1,   412,    -1,   395,    -1,     1,
     261,    -1,   249,   264,   154,   261,    -1,   148,   264,   154,
     261,    -1,   192,   264,   198,   261,    -1,    26,   264,   154,
     261,    -1,    49,   264,   198,   261,    -1,    -1,    54,   397,
     264,   398,   261,    -1,   398,   265,   399,    -1,   399,    -1,
      -1,   131,   400,   402,    -1,    -1,   401,   402,    -1,   192,
      -1,    50,    -1,    94,    -1,    75,    -1,    20,    -1,    21,
      -1,   130,    -1,    68,    -1,   173,    -1,   122,    -1,    94,
     264,   198,   261,    -1,    75,   264,   198,   261,    -1,    50,
     264,   198,   261,    -1,    20,   264,   198,   261,    -1,   130,
     264,   198,   261,    -1,    68,   264,   198,   261,    -1,   191,
     264,   154,   261,    -1,   158,   264,   154,   261,    -1,   157,
     264,   132,   261,    -1,   122,   264,   198,   261,    -1,    -1,
     172,   414,   263,   415,   262,   261,    -1,   415,   416,    -1,
     416,    -1,   417,    -1,   418,    -1,   419,    -1,     1,   261,
      -1,   156,   264,   154,   261,    -1,    22,   264,   154,   261,
      -1,   125,   264,   154,   261,    -1,    -1,   186,   421,   263,
     422,   262,   261,    -1,   422,   423,    -1,   423,    -1,   424,
      -1,   425,    -1,   426,    -1,     1,   261,    -1,   121,   264,
     154,   261,    -1,   249,   264,   154,   261,    -1,    -1,   188,
     427,   264,   428,   261,    -1,   428,   265,   429,    -1,   429,
      -1,    93,    -1,   245,    -1,   248,    -1,   258,    -1,   246,
      -1,   240,    -1,   172,    -1,   247,    -1,   239,    -1,   219,
      -1,   204,    -1,    -1,   187,   431,   263,   432,   262,   261,
      -1,   432,   433,    -1,   433,    -1,   434,    -1,   435,    -1,
       1,   261,    -1,   121,   264,   154,   261,    -1,    -1,   188,
     436,   264,   437,   261,    -1,   437,   265,   438,    -1,   438,
      -1,    93,    -1,   245,    -1,   248,    -1,   258,    -1,   246,
      -1,   240,    -1,   172,    -1,   247,    -1,   239,    -1,   219,
      -1,   204,    -1,    -1,    29,   440,   441,   263,   442,   262,
     261,    -1,    -1,   445,    -1,   442,   443,    -1,   443,    -1,
     444,    -1,   446,    -1,   447,    -1,   448,    -1,   449,    -1,
     451,    -1,   450,    -1,   452,    -1,   453,    -1,   466,    -1,
     467,    -1,   468,    -1,   464,    -1,   461,    -1,   463,    -1,
     462,    -1,   460,    -1,   469,    -1,   465,    -1,     1,   261,
      -1,   121,   264,   154,   261,    -1,   154,    -1,    84,   264,
     154,   261,    -1,   256,   264,   154,   261,    -1,   180,   264,
     154,   261,    -1,     3,   264,   154,   261,    -1,   153,   264,
     132,   261,    -1,     6,   264,   217,   261,    -1,     6,   264,
     218,   261,    -1,    53,   264,   154,   261,    -1,    -1,    54,
     454,   264,   455,   261,    -1,   455,   265,   456,    -1,   456,
      -1,    -1,   131,   457,   459,    -1,    -1,   458,   459,    -1,
      27,    -1,    31,    -1,    10,    -1,    12,    -1,   243,    -1,
     167,   264,   154,   261,    -1,    49,   264,   198,   261,    -1,
      31,   264,   198,   261,    -1,    27,   264,   198,   261,    -1,
      10,   264,   198,   261,    -1,   243,   264,   198,   261,    -1,
      86,   264,   154,   261,    -1,    99,   264,   154,   261,    -1,
      26,   264,   154,   261,    -1,    25,   264,   154,   261,    -1,
      -1,    91,   471,   263,   476,   262,   261,    -1,    -1,   188,
     473,   264,   474,   261,    -1,   474,   265,   475,    -1,   475,
      -1,   159,    -1,   476,   477,    -1,   477,    -1,   478,    -1,
     479,    -1,   472,    -1,     1,    -1,   249,   264,   154,   261,
      -1,   156,   264,   154,   261,    -1,    -1,    36,   481,   263,
     482,   262,   261,    -1,   482,   483,    -1,   483,    -1,   484,
      -1,   485,    -1,     1,    -1,    90,   264,   154,   261,    -1,
     156,   264,   154,   261,    -1,    51,   263,   487,   262,   261,
      -1,   487,   488,    -1,   488,    -1,   489,    -1,     1,    -1,
      90,   264,   154,   261,    -1,    -1,    64,   491,   263,   496,
     262,   261,    -1,    -1,   188,   493,   264,   494,   261,    -1,
     494,   265,   495,    -1,   495,    -1,   159,    -1,   496,   497,
      -1,   497,    -1,   498,    -1,   499,    -1,   492,    -1,     1,
      -1,   121,   264,   154,   261,    -1,   156,   264,   154,   261,
      -1,    65,   263,   501,   262,   261,    -1,   501,   502,    -1,
     502,    -1,   511,    -1,   512,    -1,   514,    -1,   515,    -1,
     516,    -1,   517,    -1,   518,    -1,   519,    -1,   520,    -1,
     521,    -1,   510,    -1,   523,    -1,   524,    -1,   525,    -1,
     526,    -1,   542,    -1,   528,    -1,   530,    -1,   532,    -1,
     531,    -1,   535,    -1,   529,    -1,   536,    -1,   537,    -1,
     538,    -1,   539,    -1,   541,    -1,   540,    -1,   556,    -1,
     543,    -1,   547,    -1,   548,    -1,   552,    -1,   533,    -1,
     534,    -1,   562,    -1,   560,    -1,   561,    -1,   544,    -1,
     513,    -1,   545,    -1,   546,    -1,   563,    -1,   551,    -1,
     522,    -1,   549,    -1,   550,    -1,   506,    -1,   509,    -1,
     504,    -1,   505,    -1,   507,    -1,   508,    -1,   527,    -1,
     503,    -1,     1,    -1,   115,   264,   132,   261,    -1,    71,
     264,   132,   261,    -1,    72,   264,   132,   261,    -1,    12,
     264,   198,   261,    -1,   255,   264,   198,   261,    -1,   161,
     264,   270,   261,    -1,   185,   264,   198,   261,    -1,    92,
     264,   270,   261,    -1,    83,   264,   198,   261,    -1,    88,
     264,   198,   261,    -1,    43,   264,   198,   261,    -1,    52,
     264,   198,   261,    -1,     8,   264,   198,   261,    -1,   112,
     264,   270,   261,    -1,   111,   264,   132,   261,    -1,   105,
     264,   132,   261,    -1,     9,   264,   270,   261,    -1,   202,
     264,   270,   261,    -1,   201,   264,   270,   261,    -1,    76,
     264,   132,   261,    -1,    96,   264,   198,   261,    -1,    95,
     264,   154,   261,    -1,    89,   264,   198,   261,    -1,   260,
     264,   198,   261,    -1,   193,   264,   198,   261,    -1,   196,
     264,   198,   261,    -1,   197,   264,   198,   261,    -1,   195,
     264,   198,   261,    -1,   195,   264,   199,   261,    -1,   194,
     264,   198,   261,    -1,   194,   264,   199,   261,    -1,   146,
     264,   270,   261,    -1,    19,   264,   270,   261,    -1,   138,
     264,   198,   261,    -1,   147,   264,   270,   261,    -1,   189,
     264,   198,   261,    -1,   129,   264,   198,   261,    -1,   244,
     264,   198,   261,    -1,   141,   264,   198,   261,    -1,   116,
     264,   154,   261,    -1,    87,   264,   270,   261,    -1,    44,
     264,   132,   261,    -1,   114,   264,   132,   261,    -1,   183,
     264,   154,   261,    -1,    32,   264,   154,   261,    -1,    28,
     264,   132,   261,    -1,   250,   264,   198,   261,    -1,    46,
     264,   154,   261,    -1,   150,   264,   198,   261,    -1,    39,
     264,   198,   261,    -1,   242,   264,   270,   261,    -1,    -1,
     143,   553,   264,   554,   261,    -1,   554,   265,   555,    -1,
     555,    -1,   205,    -1,   208,    -1,   209,    -1,   211,    -1,
     212,    -1,   215,    -1,   234,    -1,   229,    -1,   231,    -1,
     238,    -1,   235,    -1,   214,    -1,   230,    -1,   233,    -1,
     216,    -1,   241,    -1,   206,    -1,   207,    -1,   219,    -1,
      -1,   140,   557,   264,   558,   261,    -1,   558,   265,   559,
      -1,   559,    -1,   205,    -1,   208,    -1,   209,    -1,   211,
      -1,   212,    -1,   215,    -1,   234,    -1,   229,    -1,   231,
      -1,   238,    -1,   235,    -1,   214,    -1,   230,    -1,   233,
      -1,   216,    -1,   241,    -1,   206,    -1,   207,    -1,   219,
      -1,   117,   264,   132,   261,    -1,   118,   264,   132,   261,
      -1,    33,   264,   132,   261,    -1,   210,   264,   272,   261,
      -1,    -1,    67,   565,   263,   566,   262,   261,    -1,   566,
     567,    -1,   567,    -1,   568,    -1,   569,    -1,   570,    -1,
     574,    -1,   575,    -1,   576,    -1,     1,    -1,    48,   264,
     198,   261,    -1,    45,   264,   270,   261,    -1,    -1,   103,
     571,   264,   572,   261,    -1,   572,   265,   573,    -1,   573,
      -1,   200,    -1,    11,    -1,   249,   264,   154,   261,    -1,
     121,   264,   154,   261,    -1,    -1,     4,   577,   264,   578,
     261,    -1,   578,   265,   579,    -1,   579,    -1,   200,    -1,
      11,    -1,    22,   263,   581,   262,   261,    -1,   581,   582,
      -1,   582,    -1,   585,    -1,   586,    -1,   587,    -1,   588,
      -1,   593,    -1,   589,    -1,   590,    -1,   591,    -1,   592,
      -1,   594,    -1,   595,    -1,   596,    -1,   584,    -1,   597,
      -1,   598,    -1,   599,    -1,   600,    -1,   583,    -1,     1,
      -1,    40,   264,   198,   261,    -1,   164,   264,   198,   261,
      -1,    42,   264,   198,   261,    -1,   251,   264,   198,   261,
      -1,   252,   264,   198,   261,    -1,   253,   264,   198,   261,
      -1,    97,   264,   270,   261,    -1,    98,   264,   270,   261,
      -1,   107,   264,   132,   261,    -1,   155,   264,   198,   261,
      -1,   106,   264,   132,   261,    -1,    35,   264,   132,   261,
      -1,    34,   264,   132,   261,    -1,   127,   264,   198,   261,
      -1,   128,   264,   198,   261,    -1,    13,   264,   198,   261,
      -1,   144,   264,   132,   261,    -1,   145,   264,   270,   261,
      -1,   181,   263,   602,   262,   261,    -1,   602,   603,    -1,
     603,    -1,   604,    -1,   605,    -1,   607,    -1,   609,    -1,
     608,    -1,   606,    -1,   610,    -1,     1,    -1,    55,   264,
     198,   261,    -1,    82,   264,   198,   261,    -1,    79,   264,
     154,   261,    -1,   100,   264,   270,   261,    -1,    77,   264,
     198,   261,    -1,    41,   264,   198,   261,    -1,    81,   264,
     198,   261,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   396,   396,   397,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   425,   425,   426,   430,
     434,   438,   442,   446,   452,   452,   453,   454,   455,   456,
     463,   466,   466,   467,   467,   467,   469,   477,   486,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     494,   494,   495,   496,   500,   499,   518,   518,   519,   525,
     533,   567,   627,   641,   656,   665,   679,   688,   716,   746,
     769,   791,   793,   793,   794,   794,   795,   795,   797,   806,
     815,   828,   830,   831,   833,   833,   834,   835,   835,   836,
     836,   837,   837,   838,   838,   839,   840,   842,   846,   850,
     857,   864,   871,   878,   885,   892,   899,   906,   910,   914,
     918,   922,   926,   930,   936,   946,   945,  1039,  1039,  1040,
    1040,  1041,  1041,  1041,  1041,  1042,  1042,  1043,  1043,  1043,
    1044,  1044,  1044,  1045,  1045,  1045,  1046,  1046,  1046,  1046,
    1047,  1047,  1048,  1048,  1050,  1062,  1074,  1108,  1120,  1131,
    1173,  1183,  1182,  1188,  1188,  1189,  1193,  1197,  1201,  1205,
    1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,
    1249,  1253,  1257,  1261,  1267,  1278,  1289,  1300,  1311,  1322,
    1333,  1344,  1355,  1366,  1377,  1388,  1399,  1410,  1422,  1421,
    1425,  1425,  1426,  1426,  1427,  1427,  1429,  1436,  1443,  1450,
    1457,  1464,  1471,  1478,  1485,  1492,  1499,  1506,  1513,  1520,
    1527,  1534,  1548,  1547,  1597,  1597,  1599,  1599,  1600,  1601,
    1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,
    1611,  1612,  1614,  1623,  1632,  1638,  1644,  1650,  1656,  1662,
    1668,  1674,  1680,  1686,  1692,  1698,  1708,  1707,  1724,  1723,
    1728,  1728,  1729,  1733,  1737,  1745,  1745,  1746,  1746,  1746,
    1746,  1746,  1748,  1748,  1750,  1750,  1752,  1766,  1786,  1795,
    1808,  1807,  1876,  1876,  1877,  1877,  1877,  1877,  1878,  1878,
    1879,  1879,  1879,  1880,  1880,  1881,  1881,  1881,  1882,  1882,
    1882,  1884,  1921,  1934,  1945,  1954,  1966,  1965,  1969,  1969,
    1970,  1970,  1971,  1971,  1973,  1981,  1988,  1995,  2002,  2009,
    2016,  2023,  2030,  2037,  2046,  2057,  2068,  2079,  2090,  2101,
    2113,  2132,  2142,  2151,  2167,  2166,  2182,  2182,  2183,  2183,
    2183,  2183,  2185,  2194,  2209,  2223,  2222,  2238,  2238,  2239,
    2239,  2239,  2239,  2241,  2250,  2273,  2272,  2278,  2278,  2279,
    2283,  2287,  2291,  2295,  2299,  2303,  2307,  2311,  2315,  2319,
    2329,  2328,  2345,  2345,  2346,  2346,  2346,  2348,  2355,  2354,
    2360,  2360,  2361,  2365,  2369,  2373,  2377,  2381,  2385,  2389,
    2393,  2397,  2401,  2411,  2410,  2556,  2556,  2557,  2557,  2558,
    2558,  2558,  2559,  2559,  2560,  2560,  2561,  2561,  2561,  2562,
    2562,  2562,  2563,  2563,  2563,  2564,  2564,  2565,  2565,  2567,
    2579,  2591,  2600,  2626,  2644,  2662,  2668,  2672,  2680,  2690,
    2689,  2693,  2693,  2694,  2694,  2695,  2695,  2697,  2708,  2715,
    2722,  2729,  2739,  2780,  2791,  2802,  2817,  2828,  2839,  2852,
    2865,  2874,  2910,  2909,  2973,  2972,  2976,  2976,  2977,  2983,
    2983,  2984,  2984,  2984,  2984,  2986,  3005,  3015,  3014,  3037,
    3037,  3038,  3038,  3038,  3040,  3046,  3055,  3057,  3057,  3058,
    3058,  3060,  3079,  3078,  3126,  3125,  3129,  3129,  3130,  3136,
    3136,  3137,  3137,  3137,  3137,  3139,  3145,  3154,  3157,  3157,
    3158,  3158,  3159,  3159,  3160,  3160,  3161,  3161,  3162,  3162,
    3163,  3163,  3164,  3164,  3165,  3165,  3166,  3166,  3167,  3167,
    3168,  3168,  3169,  3169,  3170,  3170,  3171,  3171,  3172,  3172,
    3173,  3173,  3174,  3174,  3175,  3175,  3176,  3176,  3177,  3177,
    3178,  3179,  3179,  3180,  3180,  3181,  3182,  3182,  3183,  3183,
    3184,  3184,  3185,  3185,  3186,  3187,  3190,  3195,  3200,  3205,
    3210,  3215,  3220,  3225,  3230,  3235,  3240,  3245,  3250,  3255,
    3260,  3265,  3270,  3275,  3280,  3286,  3297,  3302,  3311,  3316,
    3321,  3326,  3331,  3336,  3339,  3344,  3347,  3352,  3357,  3362,
    3367,  3372,  3377,  3382,  3387,  3392,  3403,  3408,  3413,  3418,
    3427,  3459,  3477,  3482,  3491,  3496,  3501,  3507,  3506,  3511,
    3511,  3512,  3515,  3518,  3521,  3524,  3527,  3530,  3533,  3536,
    3539,  3542,  3545,  3548,  3551,  3554,  3557,  3560,  3563,  3566,
    3572,  3571,  3576,  3576,  3577,  3580,  3583,  3586,  3589,  3592,
    3595,  3598,  3601,  3604,  3607,  3610,  3613,  3616,  3619,  3622,
    3625,  3628,  3631,  3636,  3641,  3646,  3651,  3661,  3660,  3684,
    3684,  3685,  3686,  3687,  3688,  3689,  3690,  3691,  3693,  3699,
    3706,  3705,  3710,  3710,  3711,  3715,  3721,  3755,  3765,  3764,
    3814,  3814,  3815,  3819,  3828,  3831,  3831,  3832,  3832,  3833,
    3833,  3834,  3834,  3835,  3835,  3836,  3836,  3837,  3838,  3838,
    3839,  3839,  3840,  3840,  3841,  3841,  3843,  3848,  3853,  3858,
    3863,  3868,  3873,  3878,  3883,  3888,  3893,  3898,  3903,  3908,
    3913,  3918,  3923,  3928,  3936,  3939,  3939,  3940,  3940,  3941,
    3942,  3943,  3943,  3944,  3945,  3947,  3953,  3959,  3968,  3982,
    3988,  3994
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
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME",
  "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
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
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
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
  "oper_umodes_items", "oper_umodes_item", "oper_global_kill",
  "oper_remote", "oper_remoteban", "oper_kline", "oper_xline",
  "oper_unkline", "oper_gline", "oper_nick_changes", "oper_die",
  "oper_rehash", "oper_admin", "oper_hidden_admin", "oper_hidden_oper",
  "oper_operwall", "oper_flags", "$@4", "oper_flags_items",
  "oper_flags_item", "$@5", "$@6", "oper_flags_item_atom", "class_entry",
  "$@7", "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@8", "listen_flags", "$@9",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@10", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@11", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "$@12", "auth_flags_items",
  "auth_flags_item", "$@13", "$@14", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "$@15", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "$@16", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "$@17", "shared_types",
  "shared_type_item", "cluster_entry", "$@18", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "$@19", "cluster_types",
  "cluster_type_item", "connect_entry", "$@20", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "$@21", "connect_flags_items",
  "connect_flags_item", "$@22", "$@23", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_topicburst",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "$@24", "kill_type", "$@25",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@26", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@27", "gecos_flags", "$@28",
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
  "$@29", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@30", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "gline_entry", "$@31", "gline_items",
  "gline_item", "gline_enable", "gline_duration", "gline_logging", "$@32",
  "gline_logging_types", "gline_logging_type_item", "gline_user",
  "gline_server", "gline_action", "$@33", "gdeny_types", "gdeny_type_item",
  "channel_entry", "channel_items", "channel_item",
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
     515,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   266,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   271,   271,   272,   272,   272,   272,
     273,   274,   274,   275,   275,   275,   276,   277,   278,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   282,   281,   283,   283,   284,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   297,   298,   298,   298,   298,   299,   300,
     301,   302,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   315,   315,
     315,   315,   315,   315,   316,   318,   317,   319,   319,   320,
     320,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   322,   323,   324,   325,   326,   327,
     328,   330,   329,   331,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   348,   347,
     349,   349,   351,   350,   352,   350,   353,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   353,
     353,   353,   355,   354,   356,   356,   357,   357,   358,   358,
     358,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   374,   373,   376,   375,
     377,   377,   378,   378,   378,   379,   379,   380,   380,   380,
     380,   380,   382,   381,   383,   383,   384,   384,   385,   386,
     388,   387,   389,   389,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   391,   392,   393,   394,   395,   397,   396,   398,   398,
     400,   399,   401,   399,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   414,   413,   415,   415,   416,   416,
     416,   416,   417,   418,   419,   421,   420,   422,   422,   423,
     423,   423,   423,   424,   425,   427,   426,   428,   428,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     431,   430,   432,   432,   433,   433,   433,   434,   436,   435,
     437,   437,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   440,   439,   441,   441,   442,   442,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   451,   452,   454,
     453,   455,   455,   457,   456,   458,   456,   459,   459,   459,
     459,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   471,   470,   473,   472,   474,   474,   475,   476,
     476,   477,   477,   477,   477,   478,   479,   481,   480,   482,
     482,   483,   483,   483,   484,   485,   486,   487,   487,   488,
     488,   489,   491,   490,   493,   492,   494,   494,   495,   496,
     496,   497,   497,   497,   497,   498,   499,   500,   501,   501,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   530,   531,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   553,   552,   554,
     554,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     557,   556,   558,   558,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   560,   561,   562,   563,   565,   564,   566,
     566,   567,   567,   567,   567,   567,   567,   567,   568,   569,
     571,   570,   572,   572,   573,   573,   574,   575,   577,   576,
     578,   578,   579,   579,   580,   581,   581,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   602,   603,   603,   603,
     603,   603,   603,   603,   603,   604,   605,   606,   607,   608,
     609,   610
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
       1,     1,     1,     2,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     7,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     7,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   222,   393,   467,     0,
     482,     0,   657,   280,   452,   256,     0,     0,   125,   334,
       0,     0,   345,   370,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   224,
     395,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    86,    85,   705,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   686,   704,   699,   687,
     688,   689,   690,   692,   693,   694,   695,   691,   696,   697,
     698,   700,   701,   702,   703,   243,     0,   225,   420,     0,
     396,     0,   480,     0,     0,   478,   479,     0,   555,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   630,     0,   607,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   499,   554,   549,   550,   547,
     551,   552,   548,   510,   500,   501,   539,   502,   503,   504,
     505,   506,   507,   508,   509,   544,   511,   512,   513,   514,
     553,   516,   521,   517,   519,   518,   533,   534,   520,   522,
     523,   524,   525,   527,   526,   515,   529,   538,   540,   541,
     530,   531,   545,   546,   543,   532,   528,   536,   537,   535,
     542,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    98,   105,    99,   103,   100,   101,   104,   102,
      96,    97,     0,     0,     0,     0,    42,    43,    44,   155,
       0,   128,     0,   734,     0,     0,     0,     0,     0,     0,
       0,     0,   726,   727,   728,   732,   729,   731,   730,   733,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,    50,    62,    61,    58,    51,    60,
      54,    55,    56,    52,    59,    57,    53,     0,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   685,     0,     0,   473,     0,     0,
       0,   470,   471,   472,     0,     0,   477,   494,     0,     0,
     484,   493,     0,   490,   491,   492,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   498,   667,   678,     0,     0,   670,     0,     0,
       0,   660,   661,   662,   663,   664,   665,   666,     0,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   284,   285,   294,
     286,   299,   287,   288,   289,   290,   297,   291,   292,   293,
     295,   296,   298,   464,     0,   454,     0,   463,     0,   460,
     461,   462,     0,   258,     0,     0,     0,   268,     0,   266,
     267,   269,   270,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    45,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,   337,
     338,   339,   340,     0,     0,     0,     0,     0,     0,     0,
       0,   725,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,   355,
       0,     0,   348,   349,   350,   351,     0,     0,   378,     0,
     373,   374,   375,     0,     0,     0,    81,     0,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   684,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   231,   232,   234,   235,   236,   237,
     238,   239,   240,   229,   230,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   398,   399,   400,
     401,   402,   403,   405,   404,   406,   407,   415,   412,   414,
     413,   411,   417,   408,   409,   410,   416,     0,     0,     0,
     469,     0,   476,     0,     0,     0,     0,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,   497,     0,     0,     0,
       0,     0,     0,     0,   659,   300,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,     0,     0,   459,   271,
       0,     0,     0,     0,     0,   265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,    40,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,   130,   131,   132,   133,   150,   151,   137,   136,
     138,   139,   145,   140,   141,   142,   143,   144,   146,   147,
     148,   134,   135,   149,   152,   341,     0,     0,     0,     0,
     336,     0,     0,     0,     0,     0,     0,     0,   724,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   352,     0,     0,     0,     0,   347,   376,     0,
       0,     0,   372,    90,    89,    88,   721,   718,   717,   706,
     708,    26,    26,    26,    26,    26,    28,    27,   712,   713,
     716,   714,   719,   720,   722,   723,   715,   707,   709,   710,
     711,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   397,     0,
       0,   468,   481,     0,     0,     0,   483,   568,   572,   559,
     588,   601,   600,   655,   605,   566,   597,   603,   567,   557,
     558,   575,   564,   596,   565,   578,   563,   577,   576,   571,
     570,   569,   598,   556,   595,   653,   654,   592,   589,   634,
     650,   651,   635,   636,   637,   638,   645,   639,   648,   652,
     641,   646,   642,   647,   640,   644,   643,   649,     0,   633,
     594,   611,   627,   628,   612,   613,   614,   615,   622,   616,
     625,   629,   618,   623,   619,   624,   617,   621,   620,   626,
       0,   610,   587,   590,   604,   561,   599,   562,   591,   580,
     585,   586,   583,   584,   581,   582,   574,   573,    34,    34,
      34,    36,    35,   656,   606,   593,   602,   560,   579,     0,
       0,     0,     0,     0,     0,   658,     0,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,   453,     0,     0,     0,
     276,   272,   275,   257,   110,   116,   114,   113,   115,   111,
     112,   109,   117,   123,   118,   122,   120,   121,   119,   108,
     107,   124,    46,    47,   153,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,     0,   335,   740,   735,   739,   737,   741,   736,   738,
      74,    80,    72,    76,    75,    71,    70,    68,    69,     0,
      67,    73,    79,    77,    78,     0,     0,     0,   346,     0,
       0,   371,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   394,   474,   475,   495,   496,   488,     0,   487,   631,
       0,   608,     0,    37,    38,    39,   683,   682,     0,   681,
     669,   668,   675,   674,     0,   673,   677,   676,   327,   304,
     305,   326,   310,     0,   309,     0,   329,   325,   324,   333,
     328,   302,   332,   331,   330,   303,   301,   466,   458,     0,
     457,   465,   263,   264,   262,     0,   261,   279,   278,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   343,   344,   342,    65,     0,
     353,   359,   365,   369,   368,   367,   364,   360,   363,   366,
     361,   362,     0,   358,   354,   377,   382,   388,   392,   391,
     390,   387,   383,   386,   389,   384,   385,     0,   381,   253,
     254,   247,   249,   251,   250,   248,   242,   255,   246,   244,
     245,   252,   424,   426,   427,   446,   451,   450,   445,   444,
     443,   428,   433,     0,   432,     0,   421,   448,   449,   419,
     425,   442,   423,   447,   422,   485,     0,   632,   609,   679,
       0,   671,     0,     0,   307,   312,   318,   319,   315,   321,
     317,   316,   323,   320,   322,   314,   313,   455,     0,   259,
       0,   277,   274,   273,   194,   160,   192,   158,   202,     0,
     201,     0,   190,   184,   195,   196,   187,   154,   191,   157,
     193,   185,   186,   159,   197,   165,   181,   182,   166,   167,
     168,   169,   176,   170,   179,   183,   172,   177,   173,   178,
     171,   175,   174,   180,     0,   164,   189,   156,   188,    66,
     356,     0,   379,     0,     0,   430,   435,   439,   440,   437,
     438,   441,   436,   486,   680,   672,   311,   308,   456,   260,
       0,   199,   204,   214,   212,   221,   211,   206,   215,   219,
     208,   216,   218,   213,   207,   220,   217,   209,   210,   205,
     162,     0,   357,   380,   434,   431,   203,   200,   163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   896,   897,  1051,  1052,    25,   275,   276,
     277,   278,    26,   313,   314,   315,   550,  1159,  1160,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
      27,    71,    72,    73,    74,    75,    28,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,    29,    61,   280,   821,   822,   823,   281,   824,   825,
     826,   827,   828,   829,  1133,  1434,  1435,   830,   831,   832,
     833,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   844,  1119,  1399,  1400,  1460,  1401,  1479,    30,    49,
     116,   611,   612,   613,   117,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,    31,    58,   497,
     770,  1265,  1266,   498,   499,   500,  1271,  1091,  1092,   501,
     502,    32,    56,   465,   466,   467,   468,   469,   470,   471,
     472,   750,  1243,  1244,  1373,  1245,  1386,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,    33,    62,   528,
     529,   530,   531,   532,    34,    65,   561,   562,   563,   564,
     565,   874,  1312,  1313,    35,    66,   569,   570,   571,   572,
     880,  1327,  1328,    36,    50,   119,   646,   647,   648,   120,
     649,   650,   651,   652,   653,   654,   655,   656,   937,  1353,
    1354,  1444,  1355,  1452,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,    37,    57,   487,   765,  1259,  1260,
     488,   489,   490,   491,    38,    51,   360,   361,   362,   363,
      39,   124,   125,   126,    40,    53,   371,   675,  1217,  1218,
     372,   373,   374,   375,    41,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   410,  1030,  1031,
     236,   408,  1008,  1009,   237,   238,   239,   240,    42,    55,
     440,   441,   442,   443,   444,   740,  1234,  1235,   445,   446,
     447,   737,  1228,  1229,    43,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    44,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1031
static const yytype_int16 yypact[] =
{
   -1031,   898, -1031,  -226,  -255,  -252, -1031, -1031, -1031,  -235,
   -1031,  -230, -1031, -1031, -1031, -1031,  -225,  -209, -1031, -1031,
    -207,  -204, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031,    16,   727,   -73,
     -47,  -151,     9,  -132,   483,  -129,  -124,  -106,  -104,   349,
      96,    23,   -93,   642,   530,   -82,   -72,   -49,   -44,   -38,
     -37,    14, -1031, -1031, -1031, -1031, -1031,   -35,   -33,   -30,
     -28,   -27,   -25,   -20,   -17,    -9,    -3,    -1,     4,    17,
      27,    32,    38,    40,    45,   188, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031,    25, -1031, -1031,    50,
   -1031,    24, -1031,    54,    15, -1031, -1031,   215, -1031,    59,
      64,    67,    74,    75,    81,    82,    87,    90,    91,    92,
      95,    98,    99,   101,   103,   104,   105,   109,   119,   120,
     121,   122,   123,   124,   126,   129,   131,   132,   140,   151,
     152, -1031,   154, -1031,   158,   160,   161,   162,   163,   164,
     167,   168,   169,   174,   182,   184,   185,   187,   190,   192,
     193,   195,   196,   197,    57, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031,   296,   838,    31,    26,   -13,   201,   202,   203,   206,
     207,   208,   209,   210,   211,   218,   219,   223,   319, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031,    53,   225,   226,     2, -1031, -1031, -1031, -1031,
     230, -1031,   289, -1031,   233,   234,   235,   236,   239,   240,
     241,   248, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
     245,   243,   250,   253,   254,   255,   256,   264, -1031,   269,
     273,   274,   276,   268, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031,   213,     5, -1031,
     133,   267,   340,   251, -1031,   311,   400,   404,   343,   344,
     415,   415,   416,   421,   348,   358,   425,   415,   360,   362,
     363,   365,   366,   307, -1031,   899,   710, -1031,   301,   312,
      46, -1031, -1031, -1031,   423,   323, -1031, -1031,   316,   321,
   -1031, -1031,    20, -1031, -1031, -1031,   388,   415,   389,   415,
     457,   436,   459,   394,   395,   470,   450,   407,   474,   475,
     476,   412,   415,   413,   418,   415,   460,   419,   486,   487,
     415,   488,   490,   471,   495,   496,   433,   434,   378,   447,
     383,   415,   415,   451,   415,   494,   452,   454,   458,  -150,
     -51,   461,   462,   415,   415,   523,   415,   463,   465,   466,
     467,   397, -1031, -1031, -1031,   403,   405, -1031,   406,   409,
      22, -1031, -1031, -1031, -1031, -1031, -1031, -1031,   410,   411,
     426,   427,   428, -1031,   430,   431,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   272, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031,   448, -1031,   453, -1031,     8, -1031,
   -1031, -1031,   469, -1031,   468,   480,   481, -1031,     3, -1031,
   -1031, -1031, -1031, -1031,   528,   533,   535,   546,   561,   564,
     568,   572,   414,   577,   592,   549,   491, -1031, -1031,   594,
     597,   492, -1031,   608,   493,   501,   502,   509,   110, -1031,
   -1031, -1031, -1031,   557,   559,   562,   620,   578,   579,   415,
     517, -1031, -1031,   626,   583,   628,   630,   631,   634,   635,
     527,   638,   661,   641,   644,   538, -1031,   540,   539, -1031,
     541,    44, -1031, -1031, -1031, -1031,   545,   544, -1031,    21,
   -1031, -1031, -1031,   550,   552,   554, -1031,   555,   556,   558,
     560,   565,   303,   567,   569,   571,   574,   575,   576,   580,
     581,   582,   585,   586,   587,   588, -1031,   589,   598,   601,
     603,   604,   606,   609,   610,   611,   614,   615,   616,   617,
     619,   334, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031,   591,   621,   622,   625,
     629,   640,   643,   645,   646,   647, -1031,   648,   650,   651,
     653,   654,   655,   662,   664,   666,   157, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031,   656,   668,   600,
   -1031,   623, -1031,   675,   686,   667,   672, -1031,   674,   677,
     678,   679,   680,   685,   687,   689,   690,   691,   693,   695,
     696,   698,   700,   706,   708,   709,   712,   713,   714,   715,
     716,   720,   722,   723,   724,   726,   730,   732,   733,   736,
     833,   737,   883,   739,   741,   742,   743,   744,   745,   749,
     750,   752,   753,   754,   755,   756,   758,   760,   761,    -2,
     762,   763,   764,   765,   766,   767, -1031,   683,   415,   707,
     694,   699,   771,   770, -1031, -1031,   773,   834,   792,   839,
     768,   845,   848,   855,   856,   857,   882,   670,   902,   903,
     860,   905,   799, -1031,   907,   801,   915,   811, -1031, -1031,
     809,   921,   922,   688,   816, -1031,   820,   821,   822,   825,
     832,   835,   840,   842,   843,   844,   846,   847,   849,   850,
     854,   858,   859,   861, -1031,   862,   869, -1031,   872,   836,
     873,   874,   876, -1031,   877,   878,   879,   880,   881,   884,
     888,   892,   893,   895,   896,   900,   901, -1031,   904,   906,
     908,   112, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031,   952,   955,   992,   886,
   -1031,   910,   912,   913,   914,   916,   917,   918, -1031,   919,
     923,   924,   925,   926,   927,   928,   -16,   929,   930,   931,
     932, -1031, -1031,  1008,   933,  1009,   934, -1031, -1031,  1012,
     935,   937, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031,   415,   415,   415,   415,   415, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031,   776,  1035,   415,  1037,  1044,  1049,  1050,  1029,
    1062,  1064,   415,   415,   523,   939, -1031, -1031,  1047,     7,
    1004,  1051,  1052,  1005,  1006,  1010,  1053,   945,  1056,  1057,
    1058,  1059,  1082,  1061,  1063,  1018,  1065,   957, -1031,   959,
     960, -1031, -1031,   961,   962,   659, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,  -231, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
    -197, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,   523,   523,
     523, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,    -6,
     963,   964,    13,   965,   966, -1031,   967,   968,   969,   970,
    1101,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982, -1031,   983,  1086,   985, -1031,   -15,   986,   987,
     692,   984, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031,  1054,  1096,  1055,  1060,   990,
    1066,  1067,  1068,  1069,  1070,  1097,  1071,  1102,  1072,  1073,
    1074,  1103,  1075,   991,  1076,  1105,  1077,   999, -1031,  1000,
    1001,  1002, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,  -188,
   -1031, -1031, -1031, -1031, -1031,  1015,   304,  1016, -1031,  1017,
     697, -1031, -1031, -1031, -1031, -1031, -1031,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1030,  1031,  1032,
   -1031,  1033,  1034,  1036,  1038,  1039,  1040,  1041,  1042,  1043,
    1045,  1148,  1046,  1048,  1078,  1079,  1080,  1081,  1083,  1084,
    1085, -1031, -1031, -1031, -1031, -1031, -1031,  -186, -1031, -1031,
     833, -1031,   883, -1031, -1031, -1031, -1031, -1031,  -183, -1031,
   -1031, -1031, -1031, -1031,  -173, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031,  -170, -1031,   729, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,  -167,
   -1031, -1031, -1031, -1031, -1031,  -159, -1031, -1031, -1031,  1158,
     688,  1087,  1088,  1089,  1090,  1091,  1165,  1092,  1093,  1094,
    1095,  1098,  1099,  1100,  1104,  1106,  1107,  1108,  1109,  1110,
     920,  1111,  1112,  1113, -1031, -1031, -1031, -1031, -1031,   -16,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031,  -157, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031,  -146, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031,  -143, -1031,    19, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031,   659, -1031, -1031, -1031,
      -6, -1031,    13,   729, -1031,  1101, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,  1086, -1031,
     -15, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,  -141,
   -1031,   734, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031,  -138, -1031, -1031, -1031, -1031, -1031,
   -1031,   304, -1031,   697,    19, -1031,  1148, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
     734, -1031,  1165, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031,   920, -1031, -1031, -1031, -1031, -1031, -1031, -1031
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1031, -1031, -1031,  -851,  -340, -1030,  -423, -1031, -1031,  1114,
   -1031, -1031, -1031, -1031,   531, -1031, -1031, -1031,     6, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031,  1227, -1031, -1031, -1031, -1031, -1031,  1117, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031,   489, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031,  -169, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031,  -154, -1031, -1031,  -149, -1031, -1031,
   -1031, -1031,   702, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031,   -76, -1031,   817, -1031, -1031, -1031,    47, -1031,
   -1031, -1031, -1031, -1031,   851, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031,   -57, -1031, -1031,   -54, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
     793, -1031, -1031, -1031, -1031, -1031, -1031,   759, -1031, -1031,
   -1031, -1031, -1031,  -119, -1031, -1031, -1031,   757, -1031, -1031,
   -1031, -1031,  -120, -1031, -1031, -1031, -1031,   681, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
    -122, -1031, -1031,  -116, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,   -63,
   -1031,   841, -1031, -1031, -1031, -1031, -1031,   971, -1031, -1031,
   -1031, -1031,  1206, -1031, -1031, -1031, -1031, -1031, -1031,   -34,
   -1031,   994, -1031, -1031, -1031, -1031,  1149, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,   113,
   -1031, -1031, -1031,   114, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031,   897, -1031, -1031, -1031, -1031, -1031,   -36, -1031, -1031,
   -1031, -1031, -1031,   -32, -1031, -1031,  1248, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031, -1031, -1031,  1115, -1031, -1031,
   -1031, -1031, -1031, -1031, -1031
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     583,   584,   730,   272,   492,  1226,   566,   590,    47,   483,
     122,    48,  1048,  1049,  1050,    67,   122,    67,  1223,  1224,
    1225,   367,   566,   433,  1232,   357,   434,   492,    52,  1447,
    1219,  1448,   483,    54,  1220,    45,    46,   679,    59,   681,
    1172,  1173,  1174,  1175,  1176,   557,  1449,   357,   721,   722,
    1450,    68,   694,    68,    60,   697,    63,   493,   128,    64,
     702,    69,  1262,    69,  1221,   129,   130,   435,  1222,   131,
     436,   713,   714,  1298,   716,  1365,   132,  1299,  1369,  1366,
     493,   115,  1370,   727,   728,   133,   731,   494,  1371,   134,
     135,  1374,  1372,   495,  1387,  1375,   136,   272,  1388,   123,
     137,   138,  1389,   139,  1440,   123,  1390,   118,  1441,   140,
     494,   524,   121,   798,   358,  1442,   495,   799,  1445,  1443,
    1461,   273,  1446,  1480,  1462,   437,   567,  1481,   141,   142,
     729,   127,   525,   143,   241,    70,   358,    70,   800,   242,
     144,   368,   567,   438,   145,   146,   147,   723,   724,   148,
     801,   274,   149,   150,  1157,  1158,   496,   243,   626,   244,
     627,   802,   151,   628,   484,   558,   803,   629,   152,   153,
     282,   154,   155,   156,   157,   158,   369,   279,   804,   496,
     359,   327,   630,   631,   632,   805,   159,   484,   633,    76,
     806,   328,   807,   568,  1227,   160,   485,   161,   162,   857,
     163,    77,   359,   164,   165,   808,   634,   166,   370,   568,
     635,   636,   329,  1233,   557,   273,   367,  1263,   167,   485,
     330,  1264,    78,    79,  1192,  1193,   331,   332,    80,   335,
      81,   336,   559,   809,   337,   526,   338,   339,   810,   340,
     168,   637,   169,   638,   341,   274,   170,   342,   503,   283,
     171,   172,   173,   174,   175,   343,   639,   486,   176,   177,
     811,   344,  1451,   345,   521,   774,   527,   178,   346,   300,
     767,   439,   812,   448,   813,   814,   333,   365,   640,   815,
     486,   347,   676,   881,   743,    82,    83,   573,   355,   284,
     524,   348,   449,   560,    84,    85,   349,   433,   450,   179,
     434,   180,   350,   285,   351,   301,   876,   181,   669,   352,
     641,   525,   182,   356,   518,    86,    87,   183,   364,   431,
     245,   451,   452,   376,   642,   286,   453,   287,   377,   288,
     289,   378,    88,    89,   558,   597,   368,   643,   379,   380,
     454,   435,   816,    90,   436,   381,   382,   455,   290,   817,
     245,   383,    91,   302,   384,   385,   386,   598,   599,   387,
     818,   819,   388,   389,   600,   390,   456,   391,   392,   393,
     820,   369,   849,   394,  1137,   246,   247,   248,   249,   250,
     251,   252,   253,   395,   396,   397,   398,   399,   400,   303,
     401,   304,   305,   402,   457,   403,   404,  1301,  1060,   437,
     644,   559,   458,   370,   405,   246,   247,   248,   249,   250,
     251,   252,   253,   645,   526,   406,   407,   438,   409,   947,
     459,   574,   411,   254,   412,   413,   414,   415,   416,   460,
     461,   417,   418,   419,   306,   582,   307,   308,   420,    92,
      93,    94,   601,   602,   603,   527,   421,   604,   422,   423,
     353,   424,   309,   254,   425,   605,   426,   427,   255,   428,
     429,   430,   560,   462,   463,   504,   505,   506,   606,   607,
     507,   508,   509,   510,   511,   512,  1302,   891,   892,   893,
     894,   895,   513,   514,   128,   608,   609,   515,   255,   519,
     520,   129,   130,   523,   575,   131,   310,   533,   534,   535,
     536,  1189,   132,   537,   538,   539,   542,   543,  1303,   577,
     540,   133,   576,   610,   544,   134,   135,   545,   546,   547,
     548,   464,   136,  1304,   311,   312,   137,   138,   549,   139,
     555,   300,   578,   551,   762,   140,   579,   552,   553,   256,
     554,   580,   581,  1305,  1306,   439,   587,   582,   585,  1307,
    1308,  1309,  1310,   586,   141,   142,   588,   589,   591,   143,
     592,   593,  1311,   594,   595,   667,   144,   301,   596,   256,
     145,   146,   147,   257,  1179,   148,   668,   671,   149,   150,
     673,   516,  1187,  1188,   672,   674,   678,   680,   151,   682,
     683,   684,   685,   686,   152,   153,   925,   154,   155,   156,
     157,   158,   687,   257,   688,   689,   690,   691,   692,   798,
     693,   695,   159,   799,   698,   302,   696,   699,   700,   701,
     703,   160,   704,   161,   162,   705,   163,   706,   707,   164,
     165,   708,   709,   166,   800,   784,   785,   786,   787,   788,
     789,   790,   710,   283,   167,   711,   801,   712,   717,   715,
     718,   303,   719,   304,   305,   729,   720,   802,   736,   725,
     726,   732,   803,   733,   734,   735,   168,   738,   169,   739,
     741,   745,   170,   742,   804,   746,   171,   172,   173,   174,
     175,   805,   776,   284,   176,   177,   806,   777,   807,   778,
     747,   748,   749,   178,   751,   752,   306,   285,   307,   308,
     779,   808,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   626,   764,   627,   309,   780,   628,   766,   781,   286,
     629,   287,   782,   288,   289,   179,   783,   180,    76,   809,
     769,   791,   771,   181,   810,   630,   631,   632,   182,  1463,
      77,   633,   290,   183,   772,   773,   792,   793,   795,  1376,
    1377,   796,   794,   797,   845,   851,   811,   852,   310,   634,
     853,    78,    79,   635,   636,   846,   847,    80,   812,    81,
     813,   814,  1464,   848,   854,   815,   855,   856,   858,  1378,
     859,   860,   861,  1465,   862,   863,   311,   312,   864,   865,
    1316,   866,   867,   868,   637,   869,   638,  1379,   870,   871,
    1466,   872,  1077,   873,  1380,   875,   878,  1467,   879,   639,
     949,   883,  1468,   884,  1469,   885,   886,   887,  1216,   888,
    1090,   889,   950,  1381,    82,    83,   890,  1470,   898,   953,
     899,   640,   900,    84,    85,   901,   902,   903,   816,   448,
     954,   904,   905,   906,   556,   817,   907,   908,   909,   910,
     911,  1382,   927,  1063,    86,    87,   818,   819,   449,  1383,
    1471,   951,   912,   641,   450,   913,   820,   914,   915,  1317,
     916,    88,    89,   917,   918,   919,  1472,   642,   920,   921,
     922,   923,    90,   924,   952,   928,   929,   451,   452,   930,
     643,    91,   453,   931,  1473,  1269,  1474,  1475,     2,     3,
     597,  1318,  1384,     4,   932,  1061,   454,   933,  1177,   934,
     935,   936,   938,   455,   939,   940,  1319,   941,   942,   943,
       5,  1385,   598,   599,     6,  1064,   944,     7,   945,   600,
     946,   955,   456,   956,     8,   957,  1320,  1321,   958,   959,
     960,   961,  1322,  1323,  1324,  1325,   962,  1059,   963,     9,
     964,   965,   966,   644,   967,  1326,   968,   969,  1062,   970,
     457,   971,    10,    11,  1476,    12,   645,   972,   458,   973,
     974,  1066,    13,   975,   976,   977,   978,   979,    92,    93,
      94,   980,  1477,   981,   982,   983,   459,   984,  1067,    14,
    1068,   985,  1478,   986,   987,   460,   461,   988,  1010,    15,
    1032,    16,  1033,  1034,  1035,  1036,  1037,   601,   602,   603,
    1038,  1039,   604,  1040,  1041,  1042,  1043,  1044,    17,  1045,
     605,  1046,  1047,  1053,  1054,  1055,  1056,  1057,  1058,   462,
     463,  1065,  1070,   606,   607,    18,  1076,  1069,   989,   990,
     991,   992,   993,  1071,   994,   995,  1072,   996,   997,   998,
     608,   609,   999,  1073,  1074,  1075,  1078,  1079,  1080,  1081,
    1082,  1083,  1000,  1001,  1002,  1084,  1003,  1004,  1005,  1085,
      19,  1006,  1086,  1087,  1007,  1088,  1089,  1093,   610,    20,
      21,  1094,  1095,  1096,    22,    23,  1097,   464,  1011,  1012,
    1013,  1014,  1015,  1098,  1016,  1017,  1099,  1018,  1019,  1020,
    1115,  1100,  1021,  1101,  1102,  1103,  1139,  1104,  1105,  1140,
    1106,  1107,  1022,  1023,  1024,  1108,  1025,  1026,  1027,  1109,
    1110,  1028,  1111,  1112,  1029,  1415,  1416,  1417,  1418,  1419,
    1113,  1420,  1421,  1114,  1422,  1423,  1424,  1116,  1117,  1425,
    1118,  1120,  1121,  1122,  1123,  1124,  1141,  1142,  1125,  1426,
    1427,  1428,  1126,  1429,  1430,  1431,  1127,  1128,  1432,  1129,
    1130,  1433,  1165,  1167,  1131,  1132,  1169,  1178,  1134,  1180,
    1135,  1143,  1136,  1144,  1145,  1146,  1181,  1147,  1148,  1149,
    1150,  1182,  1183,  1184,  1151,  1152,  1153,  1154,  1155,  1156,
    1161,  1162,  1163,  1164,  1185,  1168,  1186,  1166,  1171,  1170,
    1190,  1191,  1194,  1197,  1198,  1195,  1196,  1200,  1199,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1209,  1208,  1211,  1210,
    1212,  1213,  1214,  1215,  1230,  1231,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1246,  1247,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1261,  1267,  1268,  1270,
    1273,  1282,  1272,  1274,  1276,  1290,  1284,  1288,  1275,  1292,
    1294,  1295,  1296,  1297,  1277,  1278,  1279,  1280,  1281,  1283,
    1285,  1286,  1287,  1289,  1291,  1293,  1300,  1314,  1315,  1352,
    1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,  1338,
    1391,  1339,  1340,  1341,  1342,  1343,  1398,  1344,   334,  1345,
    1346,  1347,  1348,  1349,  1350,  1439,  1351,  1356,  1487,  1357,
    1138,  1486,  1488,   926,  1459,   775,   763,  1392,  1457,  1456,
     877,   850,  1482,  1483,  1485,  1458,   882,   948,  1484,   768,
     366,   670,  1453,   432,  1367,  1368,  1455,   744,  1454,  1358,
    1359,  1360,  1361,   354,  1362,  1363,  1364,     0,  1393,  1394,
    1395,  1396,  1397,  1402,  1403,  1404,  1405,     0,     0,  1406,
    1407,  1408,     0,     0,     0,  1409,   677,  1410,  1411,  1412,
    1413,  1414,  1436,  1437,  1438,   517,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   541
};

static const yytype_int16 yycheck[] =
{
     340,   341,   425,     1,     1,    11,     1,   347,   263,     1,
       1,   263,    14,    15,    16,     1,     1,     1,  1048,  1049,
    1050,     1,     1,     1,    11,     1,     4,     1,   263,    10,
     261,    12,     1,   263,   265,   261,   262,   377,   263,   379,
     891,   892,   893,   894,   895,     1,    27,     1,   198,   199,
      31,    37,   392,    37,   263,   395,   263,    54,     1,   263,
     400,    47,    77,    47,   261,     8,     9,    45,   265,    12,
      48,   411,   412,   261,   414,   261,    19,   265,   261,   265,
      54,   154,   265,   423,   424,    28,   426,    84,   261,    32,
      33,   261,   265,    90,   261,   265,    39,     1,   265,    90,
      43,    44,   261,    46,   261,    90,   265,   154,   265,    52,
      84,     1,   263,     1,    90,   261,    90,     5,   261,   265,
     261,   119,   265,   261,   265,   103,   121,   265,    71,    72,
     132,   263,    22,    76,   263,   121,    90,   121,    26,   263,
      83,   121,   121,   121,    87,    88,    89,   198,   199,    92,
      38,   149,    95,    96,   170,   171,   153,   263,     1,   263,
       3,    49,   105,     6,   156,   121,    54,    10,   111,   112,
     263,   114,   115,   116,   117,   118,   156,   154,    66,   153,
     156,   263,    25,    26,    27,    73,   129,   156,    31,     1,
      78,   263,    80,   188,   200,   138,   188,   140,   141,   539,
     143,    13,   156,   146,   147,    93,    49,   150,   188,   188,
      53,    54,   261,   200,     1,   119,     1,   232,   161,   188,
     264,   236,    34,    35,   217,   218,   264,   264,    40,   264,
      42,   264,   188,   121,   264,   125,   264,   264,   126,   264,
     183,    84,   185,    86,   264,   149,   189,   264,   261,     1,
     193,   194,   195,   196,   197,   264,    99,   249,   201,   202,
     148,   264,   243,   264,   262,   262,   156,   210,   264,     1,
     262,   249,   160,     1,   162,   163,   262,   262,   121,   167,
     249,   264,   262,   262,   262,    97,    98,   154,   263,    41,
       1,   264,    20,   249,   106,   107,   264,     1,    26,   242,
       4,   244,   264,    55,   264,    37,   262,   250,   262,   264,
     153,    22,   255,   263,   261,   127,   128,   260,   264,   262,
       1,    49,    50,   264,   167,    77,    54,    79,   264,    81,
      82,   264,   144,   145,   121,     1,   121,   180,   264,   264,
      68,    45,   230,   155,    48,   264,   264,    75,   100,   237,
       1,   264,   164,    85,   264,   264,   264,    23,    24,   264,
     248,   249,   264,   264,    30,   264,    94,   264,   264,   264,
     258,   156,   262,   264,   262,    56,    57,    58,    59,    60,
      61,    62,    63,   264,   264,   264,   264,   264,   264,   121,
     264,   123,   124,   264,   122,   264,   264,    93,   738,   103,
     243,   188,   130,   188,   264,    56,    57,    58,    59,    60,
      61,    62,    63,   256,   125,   264,   264,   121,   264,   262,
     148,   154,   264,   104,   264,   264,   264,   264,   264,   157,
     158,   264,   264,   264,   166,   132,   168,   169,   264,   251,
     252,   253,   108,   109,   110,   156,   264,   113,   264,   264,
     262,   264,   184,   104,   264,   121,   264,   264,   139,   264,
     264,   264,   249,   191,   192,   264,   264,   264,   134,   135,
     264,   264,   264,   264,   264,   264,   172,   174,   175,   176,
     177,   178,   264,   264,     1,   151,   152,   264,   139,   264,
     264,     8,     9,   263,   154,    12,   228,   264,   264,   264,
     264,   924,    19,   264,   264,   264,   261,   264,   204,   198,
     262,    28,   261,   179,   264,    32,    33,   264,   264,   264,
     264,   249,    39,   219,   256,   257,    43,    44,   264,    46,
     262,     1,   132,   264,   262,    52,   132,   264,   264,   220,
     264,   198,   198,   239,   240,   249,   198,   132,   132,   245,
     246,   247,   248,   132,    71,    72,   198,   132,   198,    76,
     198,   198,   258,   198,   198,   264,    83,    37,   261,   220,
      87,    88,    89,   254,   914,    92,   264,   154,    95,    96,
     264,   262,   922,   923,   261,   264,   198,   198,   105,   132,
     154,   132,   198,   198,   111,   112,   262,   114,   115,   116,
     117,   118,   132,   254,   154,   198,   132,   132,   132,     1,
     198,   198,   129,     5,   154,    85,   198,   198,   132,   132,
     132,   138,   132,   140,   141,   154,   143,   132,   132,   146,
     147,   198,   198,   150,    26,   221,   222,   223,   224,   225,
     226,   227,   264,     1,   161,   198,    38,   264,   154,   198,
     198,   121,   198,   123,   124,   132,   198,    49,   261,   198,
     198,   198,    54,   198,   198,   198,   183,   264,   185,   264,
     264,   261,   189,   264,    66,   264,   193,   194,   195,   196,
     197,    73,   154,    41,   201,   202,    78,   154,    80,   154,
     264,   264,   264,   210,   264,   264,   166,    55,   168,   169,
     154,    93,   264,   264,   264,   264,   264,   264,   264,   264,
     264,     1,   264,     3,   184,   154,     6,   264,   154,    77,
      10,    79,   154,    81,    82,   242,   154,   244,     1,   121,
     261,   154,   264,   250,   126,    25,    26,    27,   255,     5,
      13,    31,   100,   260,   264,   264,   154,   198,   154,    20,
      21,   154,   261,   261,   261,   198,   148,   198,   228,    49,
     198,    34,    35,    53,    54,   264,   264,    40,   160,    42,
     162,   163,    38,   264,   154,   167,   198,   198,   261,    50,
     154,   198,   154,    49,   154,   154,   256,   257,   154,   154,
      93,   264,   154,   132,    84,   154,    86,    68,   154,   261,
      66,   261,   132,   264,    75,   264,   261,    73,   264,    99,
     154,   261,    78,   261,    80,   261,   261,   261,   159,   261,
     132,   261,   154,    94,    97,    98,   261,    93,   261,   154,
     261,   121,   261,   106,   107,   261,   261,   261,   230,     1,
     154,   261,   261,   261,   313,   237,   261,   261,   261,   261,
     261,   122,   261,   154,   127,   128,   248,   249,    20,   130,
     126,   261,   264,   153,    26,   264,   258,   264,   264,   172,
     264,   144,   145,   264,   264,   264,   142,   167,   264,   264,
     264,   264,   155,   264,   261,   264,   264,    49,    50,   264,
     180,   164,    54,   264,   160,   203,   162,   163,     0,     1,
       1,   204,   173,     5,   264,   198,    68,   264,   132,   264,
     264,   264,   264,    75,   264,   264,   219,   264,   264,   264,
      22,   192,    23,    24,    26,   154,   264,    29,   264,    30,
     264,   264,    94,   261,    36,   261,   239,   240,   261,   261,
     261,   261,   245,   246,   247,   248,   261,   264,   261,    51,
     261,   261,   261,   243,   261,   258,   261,   261,   264,   261,
     122,   261,    64,    65,   230,    67,   256,   261,   130,   261,
     261,   198,    74,   261,   261,   261,   261,   261,   251,   252,
     253,   261,   248,   261,   261,   261,   148,   261,   154,    91,
     198,   261,   258,   261,   261,   157,   158,   261,   261,   101,
     261,   103,   261,   261,   261,   261,   261,   108,   109,   110,
     261,   261,   113,   261,   261,   261,   261,   261,   120,   261,
     121,   261,   261,   261,   261,   261,   261,   261,   261,   191,
     192,   261,   264,   134,   135,   137,   154,   198,   205,   206,
     207,   208,   209,   198,   211,   212,   198,   214,   215,   216,
     151,   152,   219,   198,   198,   198,   154,   154,   198,   154,
     261,   154,   229,   230,   231,   264,   233,   234,   235,   154,
     172,   238,   261,   264,   241,   154,   154,   261,   179,   181,
     182,   261,   261,   261,   186,   187,   261,   249,   205,   206,
     207,   208,   209,   261,   211,   212,   261,   214,   215,   216,
     264,   261,   219,   261,   261,   261,   154,   261,   261,   154,
     261,   261,   229,   230,   231,   261,   233,   234,   235,   261,
     261,   238,   261,   261,   241,   205,   206,   207,   208,   209,
     261,   211,   212,   261,   214,   215,   216,   264,   264,   219,
     264,   264,   264,   264,   264,   264,   154,   261,   264,   229,
     230,   231,   264,   233,   234,   235,   264,   264,   238,   264,
     264,   241,   154,   154,   264,   264,   154,   132,   264,   132,
     264,   261,   264,   261,   261,   261,   132,   261,   261,   261,
     261,   132,   132,   154,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   132,   261,   132,   264,   261,   264,
     261,   154,   198,   198,   198,   154,   154,   154,   198,   264,
     154,   154,   154,   154,   132,   154,   198,   154,   261,   154,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   131,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   159,   261,   261,   261,   265,
     154,   154,   198,   198,   264,   264,   154,   154,   198,   154,
     261,   261,   261,   261,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   261,   261,   261,   131,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     132,   261,   261,   261,   261,   261,   131,   261,    71,   261,
     261,   261,   261,   261,   261,  1299,   261,   261,  1462,   261,
     821,  1460,  1481,   611,  1390,   498,   465,  1270,  1375,  1373,
     561,   528,  1441,  1443,  1446,  1388,   569,   646,  1444,   488,
     124,   360,  1366,   184,  1220,  1222,  1372,   440,  1370,   261,
     261,   261,   261,    95,   261,   261,   261,    -1,   261,   261,
     261,   261,   261,   261,   261,   261,   261,    -1,    -1,   261,
     261,   261,    -1,    -1,    -1,   261,   372,   261,   261,   261,
     261,   261,   261,   261,   261,   258,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   267,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   101,   103,   120,   137,   172,
     181,   182,   186,   187,   268,   273,   278,   296,   302,   317,
     354,   373,   387,   413,   420,   430,   439,   470,   480,   486,
     490,   500,   564,   580,   601,   261,   262,   263,   263,   355,
     440,   481,   263,   491,   263,   565,   388,   471,   374,   263,
     263,   318,   414,   263,   263,   421,   431,     1,    37,    47,
     121,   297,   298,   299,   300,   301,     1,    13,    34,    35,
      40,    42,    97,    98,   106,   107,   127,   128,   144,   145,
     155,   164,   251,   252,   253,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   154,   356,   360,   154,   441,
     445,   263,     1,    90,   487,   488,   489,   263,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    46,
      52,    71,    72,    76,    83,    87,    88,    89,    92,    95,
      96,   105,   111,   112,   114,   115,   116,   117,   118,   129,
     138,   140,   141,   143,   146,   147,   150,   161,   183,   185,
     189,   193,   194,   195,   196,   197,   201,   202,   210,   242,
     244,   250,   255,   260,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   556,   560,   561,   562,
     563,   263,   263,   263,   263,     1,    56,    57,    58,    59,
      60,    61,    62,    63,   104,   139,   220,   254,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     1,   119,   149,   274,   275,   276,   277,   154,
     319,   323,   263,     1,    41,    55,    77,    79,    81,    82,
     100,   602,   603,   604,   605,   606,   607,   608,   609,   610,
       1,    37,    85,   121,   123,   124,   166,   168,   169,   184,
     228,   256,   257,   279,   280,   281,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   263,   263,   261,
     264,   264,   264,   262,   298,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   582,   263,   263,     1,    90,   156,
     482,   483,   484,   485,   264,   262,   488,     1,   121,   156,
     188,   492,   496,   497,   498,   499,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   557,   264,
     553,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   502,     1,     4,    45,    48,   103,   121,   249,
     566,   567,   568,   569,   570,   574,   575,   576,     1,    20,
      26,    49,    50,    54,    68,    75,    94,   122,   130,   148,
     157,   158,   191,   192,   249,   389,   390,   391,   392,   393,
     394,   395,   396,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,     1,   156,   188,   249,   472,   476,   477,
     478,   479,     1,    54,    84,    90,   153,   375,   379,   380,
     381,   385,   386,   261,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   262,   304,   261,   264,
     264,   262,   275,   263,     1,    22,   125,   156,   415,   416,
     417,   418,   419,   264,   264,   264,   264,   264,   264,   264,
     262,   603,   261,   264,   264,   264,   264,   264,   264,   264,
     282,   264,   264,   264,   264,   262,   280,     1,   121,   188,
     249,   422,   423,   424,   425,   426,     1,   121,   188,   432,
     433,   434,   435,   154,   154,   154,   261,   198,   132,   132,
     198,   198,   132,   270,   270,   132,   132,   198,   198,   132,
     270,   198,   198,   198,   198,   198,   261,     1,    23,    24,
      30,   108,   109,   110,   113,   121,   134,   135,   151,   152,
     179,   357,   358,   359,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,     1,     3,     6,    10,
      25,    26,    27,    31,    49,    53,    54,    84,    86,    99,
     121,   153,   167,   180,   243,   256,   442,   443,   444,   446,
     447,   448,   449,   450,   451,   452,   453,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   264,   264,   262,
     483,   154,   261,   264,   264,   493,   262,   497,   198,   270,
     198,   270,   132,   154,   132,   198,   198,   132,   154,   198,
     132,   132,   132,   198,   270,   198,   198,   270,   154,   198,
     132,   132,   270,   132,   132,   154,   132,   132,   198,   198,
     264,   198,   264,   270,   270,   198,   270,   154,   198,   198,
     198,   198,   199,   198,   199,   198,   198,   270,   270,   132,
     272,   270,   198,   198,   198,   198,   261,   577,   264,   264,
     571,   264,   264,   262,   567,   261,   264,   264,   264,   264,
     397,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   262,   390,   264,   473,   264,   262,   477,   261,
     376,   264,   264,   264,   262,   380,   154,   154,   154,   154,
     154,   154,   154,   154,   221,   222,   223,   224,   225,   226,
     227,   154,   154,   198,   261,   154,   154,   261,     1,     5,
      26,    38,    49,    54,    66,    73,    78,    80,    93,   121,
     126,   148,   160,   162,   163,   167,   230,   237,   248,   249,
     258,   320,   321,   322,   324,   325,   326,   327,   328,   329,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   261,   264,   264,   264,   262,
     416,   198,   198,   198,   154,   198,   198,   270,   261,   154,
     198,   154,   154,   154,   154,   154,   264,   154,   132,   154,
     154,   261,   261,   264,   427,   264,   262,   423,   261,   264,
     436,   262,   433,   261,   261,   261,   261,   261,   261,   261,
     261,   174,   175,   176,   177,   178,   269,   270,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   262,   358,   261,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   454,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   262,   443,   154,
     154,   261,   261,   154,   154,   264,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   205,
     206,   207,   208,   209,   211,   212,   214,   215,   216,   219,
     229,   230,   231,   233,   234,   235,   238,   241,   558,   559,
     261,   205,   206,   207,   208,   209,   211,   212,   214,   215,
     216,   219,   229,   230,   231,   233,   234,   235,   238,   241,
     554,   555,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,    14,    15,
      16,   271,   272,   261,   261,   261,   261,   261,   261,   264,
     270,   198,   264,   154,   154,   261,   198,   154,   198,   198,
     264,   198,   198,   198,   198,   198,   154,   132,   154,   154,
     198,   154,   261,   154,   264,   154,   261,   264,   154,   154,
     132,   383,   384,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   264,   264,   264,   264,   348,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   330,   264,   264,   264,   262,   321,   154,
     154,   154,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   170,   171,   283,
     284,   261,   261,   261,   261,   154,   264,   154,   261,   154,
     264,   261,   269,   269,   269,   269,   269,   132,   132,   270,
     132,   132,   132,   132,   154,   132,   132,   270,   270,   272,
     261,   154,   217,   218,   198,   154,   154,   198,   198,   198,
     154,   264,   154,   154,   154,   154,   132,   154,   154,   198,
     154,   261,   261,   261,   261,   261,   159,   494,   495,   261,
     265,   261,   265,   271,   271,   271,    11,   200,   578,   579,
     261,   261,    11,   200,   572,   573,   261,   261,   261,   261,
     261,   261,   131,   398,   399,   401,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   159,   474,
     475,   261,    77,   232,   236,   377,   378,   261,   261,   203,
     265,   382,   198,   154,   198,   198,   264,   198,   198,   198,
     198,   198,   154,   198,   154,   198,   198,   198,   154,   198,
     264,   198,   154,   198,   261,   261,   261,   261,   261,   265,
     261,    93,   172,   204,   219,   239,   240,   245,   246,   247,
     248,   258,   428,   429,   261,   261,    93,   172,   204,   219,
     239,   240,   245,   246,   247,   248,   258,   437,   438,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   131,   455,   456,   458,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   265,   559,   555,   261,
     265,   261,   265,   400,   261,   265,    20,    21,    50,    68,
      75,    94,   122,   130,   173,   192,   402,   261,   265,   261,
     265,   132,   384,   261,   261,   261,   261,   261,   131,   349,
     350,   352,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   205,   206,   207,   208,   209,
     211,   212,   214,   215,   216,   219,   229,   230,   231,   233,
     234,   235,   238,   241,   331,   332,   261,   261,   261,   284,
     261,   265,   261,   265,   457,   261,   265,    10,    12,    27,
      31,   243,   459,   495,   579,   573,   402,   399,   475,   378,
     351,   261,   265,     5,    38,    49,    66,    73,    78,    80,
      93,   126,   142,   160,   162,   163,   230,   248,   258,   353,
     261,   265,   429,   438,   459,   456,   353,   350,   332
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1455 of yacc.c  */
#line 425 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 447 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 470 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
#endif
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 478 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 500 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 506 "ircd_parser.y"
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

  case 68:

/* Line 1455 of yacc.c  */
#line 520 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 526 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 534 "ircd_parser.y"
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

  case 71:

/* Line 1455 of yacc.c  */
#line 568 "ircd_parser.y"
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

  case 72:

/* Line 1455 of yacc.c  */
#line 628 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2)
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

  case 73:

/* Line 1455 of yacc.c  */
#line 642 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
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

  case 74:

/* Line 1455 of yacc.c  */
#line 657 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 666 "ircd_parser.y"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 680 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 689 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
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

  case 78:

/* Line 1455 of yacc.c  */
#line 717 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
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

  case 79:

/* Line 1455 of yacc.c  */
#line 747 "ircd_parser.y"
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

  case 80:

/* Line 1455 of yacc.c  */
#line 770 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 88:

/* Line 1455 of yacc.c  */
#line 798 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 807 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 816 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 843 "ircd_parser.y"
    {
                        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 847 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 858 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 865 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 872 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 879 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 886 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 893 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 900 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 907 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 915 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 923 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 927 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 931 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 937 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 946 "ircd_parser.y"
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

  case 126:

/* Line 1455 of yacc.c  */
#line 959 "ircd_parser.y"
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

  case 154:

/* Line 1455 of yacc.c  */
#line 1051 "ircd_parser.y"
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

  case 155:

/* Line 1455 of yacc.c  */
#line 1063 "ircd_parser.y"
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

  case 156:

/* Line 1455 of yacc.c  */
#line 1075 "ircd_parser.y"
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

  case 157:

/* Line 1455 of yacc.c  */
#line 1109 "ircd_parser.y"
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

  case 158:

/* Line 1455 of yacc.c  */
#line 1121 "ircd_parser.y"
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

  case 159:

/* Line 1455 of yacc.c  */
#line 1132 "ircd_parser.y"
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

  case 160:

/* Line 1455 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1183 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1202 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1206 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1210 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1222 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1226 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1234 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1238 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1246 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1250 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1254 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1258 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1262 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1268 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1279 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1290 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1301 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1312 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1323 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1334 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1345 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1356 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1367 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1389 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1400 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1422 "ircd_parser.y"
    {
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1426 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1427 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1430 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1437 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1444 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1451 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1472 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1479 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1486 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1493 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1500 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1514 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1521 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1528 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1535 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1548 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1555 "ircd_parser.y"
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

  case 242:

/* Line 1455 of yacc.c  */
#line 1615 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1624 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1633 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1639 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1645 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1651 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1657 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1663 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1669 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1675 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1681 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1687 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1693 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1699 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1708 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1715 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1724 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1734 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1738 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1748 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1753 "ircd_parser.y"
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

  case 277:

/* Line 1455 of yacc.c  */
#line 1767 "ircd_parser.y"
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

  case 278:

/* Line 1455 of yacc.c  */
#line 1787 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1796 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1808 "ircd_parser.y"
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

  case 281:

/* Line 1455 of yacc.c  */
#line 1820 "ircd_parser.y"
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

  case 301:

/* Line 1455 of yacc.c  */
#line 1885 "ircd_parser.y"
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

  case 302:

/* Line 1455 of yacc.c  */
#line 1922 "ircd_parser.y"
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

  case 303:

/* Line 1455 of yacc.c  */
#line 1935 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1946 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1955 "ircd_parser.y"
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

  case 306:

/* Line 1455 of yacc.c  */
#line 1966 "ircd_parser.y"
    {
}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1970 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1971 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1974 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1982 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1989 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1996 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 2003 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 2010 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 2017 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2024 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2031 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2038 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2047 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2058 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2069 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2080 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2091 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2102 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2114 "ircd_parser.y"
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

  case 331:

/* Line 1455 of yacc.c  */
#line 2133 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2152 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2167 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2195 "ircd_parser.y"
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

  case 344:

/* Line 1455 of yacc.c  */
#line 2210 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2231 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2251 "ircd_parser.y"
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

  case 355:

/* Line 1455 of yacc.c  */
#line 2273 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2280 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2284 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2292 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2296 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2300 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2304 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2308 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2312 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2316 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2320 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2329 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2336 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 377:

/* Line 1455 of yacc.c  */
#line 2349 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2355 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2362 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2366 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2370 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2374 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2382 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2386 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2390 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2394 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2398 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2402 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2411 "ircd_parser.y"
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

  case 394:

/* Line 1455 of yacc.c  */
#line 2429 "ircd_parser.y"
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

  case 419:

/* Line 1455 of yacc.c  */
#line 2568 "ircd_parser.y"
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

  case 420:

/* Line 1455 of yacc.c  */
#line 2580 "ircd_parser.y"
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

  case 421:

/* Line 1455 of yacc.c  */
#line 2592 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2601 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 423:

/* Line 1455 of yacc.c  */
#line 2627 "ircd_parser.y"
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

  case 424:

/* Line 1455 of yacc.c  */
#line 2645 "ircd_parser.y"
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

  case 425:

/* Line 1455 of yacc.c  */
#line 2663 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2669 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2673 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2681 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2690 "ircd_parser.y"
    {
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2694 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2695 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2698 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 438:

/* Line 1455 of yacc.c  */
#line 2709 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2716 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2723 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 442:

/* Line 1455 of yacc.c  */
#line 2740 "ircd_parser.y"
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

  case 443:

/* Line 1455 of yacc.c  */
#line 2781 "ircd_parser.y"
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

  case 444:

/* Line 1455 of yacc.c  */
#line 2792 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
}
    break;

  case 445:

/* Line 1455 of yacc.c  */
#line 2803 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 446:

/* Line 1455 of yacc.c  */
#line 2818 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2829 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfTopicBurst(yy_aconf);
    else
      ClearConfTopicBurst(yy_aconf);
  }
}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2840 "ircd_parser.y"
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

  case 449:

/* Line 1455 of yacc.c  */
#line 2853 "ircd_parser.y"
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

  case 450:

/* Line 1455 of yacc.c  */
#line 2866 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2875 "ircd_parser.y"
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

  case 452:

/* Line 1455 of yacc.c  */
#line 2910 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2917 "ircd_parser.y"
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

  case 454:

/* Line 1455 of yacc.c  */
#line 2973 "ircd_parser.y"
    {
}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2978 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2987 "ircd_parser.y"
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

  case 466:

/* Line 1455 of yacc.c  */
#line 3006 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 3015 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 3019 "ircd_parser.y"
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

  case 474:

/* Line 1455 of yacc.c  */
#line 3041 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 3047 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 3061 "ircd_parser.y"
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

  case 482:

/* Line 1455 of yacc.c  */
#line 3079 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 483:

/* Line 1455 of yacc.c  */
#line 3086 "ircd_parser.y"
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

  case 484:

/* Line 1455 of yacc.c  */
#line 3126 "ircd_parser.y"
    {
}
    break;

  case 488:

/* Line 1455 of yacc.c  */
#line 3131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 495:

/* Line 1455 of yacc.c  */
#line 3140 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 496:

/* Line 1455 of yacc.c  */
#line 3146 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 556:

/* Line 1455 of yacc.c  */
#line 3191 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 557:

/* Line 1455 of yacc.c  */
#line 3196 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3201 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3206 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3211 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3226 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3241 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3256 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3261 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3266 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3271 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3276 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3287 "ircd_parser.y"
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

  case 576:

/* Line 1455 of yacc.c  */
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 577:

/* Line 1455 of yacc.c  */
#line 3303 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 578:

/* Line 1455 of yacc.c  */
#line 3312 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 579:

/* Line 1455 of yacc.c  */
#line 3317 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3327 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3332 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3337 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3340 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3345 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3348 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3353 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3358 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3363 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3368 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3378 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3383 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3388 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 596:

/* Line 1455 of yacc.c  */
#line 3404 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 597:

/* Line 1455 of yacc.c  */
#line 3409 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3414 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3419 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 600:

/* Line 1455 of yacc.c  */
#line 3428 "ircd_parser.y"
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

  case 601:

/* Line 1455 of yacc.c  */
#line 3460 "ircd_parser.y"
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

  case 602:

/* Line 1455 of yacc.c  */
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 603:

/* Line 1455 of yacc.c  */
#line 3483 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 604:

/* Line 1455 of yacc.c  */
#line 3492 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 605:

/* Line 1455 of yacc.c  */
#line 3497 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3502 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 611:

/* Line 1455 of yacc.c  */
#line 3513 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3516 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3519 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3522 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3525 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3528 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3531 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3534 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3537 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3540 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3543 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3546 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3549 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3552 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3555 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3558 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3561 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3564 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3567 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3572 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 634:

/* Line 1455 of yacc.c  */
#line 3578 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 635:

/* Line 1455 of yacc.c  */
#line 3581 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 636:

/* Line 1455 of yacc.c  */
#line 3584 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 637:

/* Line 1455 of yacc.c  */
#line 3587 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 638:

/* Line 1455 of yacc.c  */
#line 3590 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 3593 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 640:

/* Line 1455 of yacc.c  */
#line 3596 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 641:

/* Line 1455 of yacc.c  */
#line 3599 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 642:

/* Line 1455 of yacc.c  */
#line 3602 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 643:

/* Line 1455 of yacc.c  */
#line 3605 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 644:

/* Line 1455 of yacc.c  */
#line 3608 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 645:

/* Line 1455 of yacc.c  */
#line 3611 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 3614 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 647:

/* Line 1455 of yacc.c  */
#line 3617 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 648:

/* Line 1455 of yacc.c  */
#line 3620 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 649:

/* Line 1455 of yacc.c  */
#line 3623 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 650:

/* Line 1455 of yacc.c  */
#line 3626 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 651:

/* Line 1455 of yacc.c  */
#line 3629 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 652:

/* Line 1455 of yacc.c  */
#line 3632 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 653:

/* Line 1455 of yacc.c  */
#line 3637 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 654:

/* Line 1455 of yacc.c  */
#line 3642 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 655:

/* Line 1455 of yacc.c  */
#line 3647 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 656:

/* Line 1455 of yacc.c  */
#line 3652 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 657:

/* Line 1455 of yacc.c  */
#line 3661 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 658:

/* Line 1455 of yacc.c  */
#line 3668 "ircd_parser.y"
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

  case 668:

/* Line 1455 of yacc.c  */
#line 3694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 669:

/* Line 1455 of yacc.c  */
#line 3700 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 670:

/* Line 1455 of yacc.c  */
#line 3706 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 674:

/* Line 1455 of yacc.c  */
#line 3712 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 675:

/* Line 1455 of yacc.c  */
#line 3716 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 676:

/* Line 1455 of yacc.c  */
#line 3722 "ircd_parser.y"
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

  case 677:

/* Line 1455 of yacc.c  */
#line 3756 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 678:

/* Line 1455 of yacc.c  */
#line 3765 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 679:

/* Line 1455 of yacc.c  */
#line 3769 "ircd_parser.y"
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

  case 682:

/* Line 1455 of yacc.c  */
#line 3816 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 683:

/* Line 1455 of yacc.c  */
#line 3820 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 706:

/* Line 1455 of yacc.c  */
#line 3844 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 707:

/* Line 1455 of yacc.c  */
#line 3849 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 708:

/* Line 1455 of yacc.c  */
#line 3854 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 709:

/* Line 1455 of yacc.c  */
#line 3859 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 710:

/* Line 1455 of yacc.c  */
#line 3864 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 711:

/* Line 1455 of yacc.c  */
#line 3869 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 712:

/* Line 1455 of yacc.c  */
#line 3874 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 713:

/* Line 1455 of yacc.c  */
#line 3879 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 714:

/* Line 1455 of yacc.c  */
#line 3884 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 715:

/* Line 1455 of yacc.c  */
#line 3889 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 716:

/* Line 1455 of yacc.c  */
#line 3894 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 717:

/* Line 1455 of yacc.c  */
#line 3899 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 718:

/* Line 1455 of yacc.c  */
#line 3904 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 719:

/* Line 1455 of yacc.c  */
#line 3909 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 720:

/* Line 1455 of yacc.c  */
#line 3914 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 721:

/* Line 1455 of yacc.c  */
#line 3919 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 722:

/* Line 1455 of yacc.c  */
#line 3924 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 723:

/* Line 1455 of yacc.c  */
#line 3929 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 735:

/* Line 1455 of yacc.c  */
#line 3948 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 736:

/* Line 1455 of yacc.c  */
#line 3954 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 737:

/* Line 1455 of yacc.c  */
#line 3960 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 738:

/* Line 1455 of yacc.c  */
#line 3969 "ircd_parser.y"
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

  case 739:

/* Line 1455 of yacc.c  */
#line 3983 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 740:

/* Line 1455 of yacc.c  */
#line 3989 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 741:

/* Line 1455 of yacc.c  */
#line 3995 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1455 of yacc.c  */
#line 8593 "ircd_parser.c"
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



