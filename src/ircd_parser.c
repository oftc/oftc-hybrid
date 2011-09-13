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



/* Line 268 of yacc.c  */
#line 178 "ircd_parser.c"

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
     NOT = 383,
     NUMBER = 384,
     NUMBER_PER_IDENT = 385,
     NUMBER_PER_CIDR = 386,
     NUMBER_PER_IP = 387,
     NUMBER_PER_IP_GLOBAL = 388,
     OPERATOR = 389,
     OPERS_BYPASS_CALLERID = 390,
     OPER_LOG = 391,
     OPER_ONLY_UMODES = 392,
     OPER_PASS_RESV = 393,
     OPER_SPY_T = 394,
     OPER_UMODES = 395,
     JOIN_FLOOD_COUNT = 396,
     JOIN_FLOOD_TIME = 397,
     PACE_WAIT = 398,
     PACE_WAIT_SIMPLE = 399,
     PASSWORD = 400,
     PATH = 401,
     PING_COOKIE = 402,
     PING_TIME = 403,
     PING_WARNING = 404,
     PORT = 405,
     QSTRING = 406,
     QUIET_ON_BAN = 407,
     REASON = 408,
     REDIRPORT = 409,
     REDIRSERV = 410,
     REGEX_T = 411,
     REHASH = 412,
     TREJECT_HOLD_TIME = 413,
     REMOTE = 414,
     REMOTEBAN = 415,
     RESTRICT_CHANNELS = 416,
     RESTRICTED = 417,
     RSA_PRIVATE_KEY_FILE = 418,
     RSA_PUBLIC_KEY_FILE = 419,
     SSL_CERTIFICATE_FILE = 420,
     T_SSL_CONNECTION_METHOD = 421,
     T_SSLV3 = 422,
     T_TLSV1 = 423,
     RESV = 424,
     RESV_EXEMPT = 425,
     SECONDS = 426,
     MINUTES = 427,
     HOURS = 428,
     DAYS = 429,
     WEEKS = 430,
     SENDQ = 431,
     SEND_PASSWORD = 432,
     SERVERHIDE = 433,
     SERVERINFO = 434,
     SERVLINK_PATH = 435,
     IRCD_SID = 436,
     TKLINE_EXPIRE_NOTICES = 437,
     T_SHARED = 438,
     T_CLUSTER = 439,
     TYPE = 440,
     SHORT_MOTD = 441,
     SILENT = 442,
     SPOOF = 443,
     SPOOF_NOTICE = 444,
     STATS_E_DISABLED = 445,
     STATS_I_OPER_ONLY = 446,
     STATS_K_OPER_ONLY = 447,
     STATS_O_OPER_ONLY = 448,
     STATS_P_OPER_ONLY = 449,
     TBOOL = 450,
     TMASKED = 451,
     T_REJECT = 452,
     TS_MAX_DELTA = 453,
     TS_WARN_DELTA = 454,
     TWODOTS = 455,
     T_ALL = 456,
     T_BOTS = 457,
     T_SOFTCALLERID = 458,
     T_CALLERID = 459,
     T_CCONN = 460,
     T_CCONN_FULL = 461,
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
     T_SERVER = 484,
     T_SERVNOTICE = 485,
     T_SKILL = 486,
     T_SPY = 487,
     T_SSL = 488,
     T_UMODES = 489,
     T_UNAUTH = 490,
     T_UNRESV = 491,
     T_UNXLINE = 492,
     T_GLOBOPS = 493,
     T_WALLOP = 494,
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
#define NOT 383
#define NUMBER 384
#define NUMBER_PER_IDENT 385
#define NUMBER_PER_CIDR 386
#define NUMBER_PER_IP 387
#define NUMBER_PER_IP_GLOBAL 388
#define OPERATOR 389
#define OPERS_BYPASS_CALLERID 390
#define OPER_LOG 391
#define OPER_ONLY_UMODES 392
#define OPER_PASS_RESV 393
#define OPER_SPY_T 394
#define OPER_UMODES 395
#define JOIN_FLOOD_COUNT 396
#define JOIN_FLOOD_TIME 397
#define PACE_WAIT 398
#define PACE_WAIT_SIMPLE 399
#define PASSWORD 400
#define PATH 401
#define PING_COOKIE 402
#define PING_TIME 403
#define PING_WARNING 404
#define PORT 405
#define QSTRING 406
#define QUIET_ON_BAN 407
#define REASON 408
#define REDIRPORT 409
#define REDIRSERV 410
#define REGEX_T 411
#define REHASH 412
#define TREJECT_HOLD_TIME 413
#define REMOTE 414
#define REMOTEBAN 415
#define RESTRICT_CHANNELS 416
#define RESTRICTED 417
#define RSA_PRIVATE_KEY_FILE 418
#define RSA_PUBLIC_KEY_FILE 419
#define SSL_CERTIFICATE_FILE 420
#define T_SSL_CONNECTION_METHOD 421
#define T_SSLV3 422
#define T_TLSV1 423
#define RESV 424
#define RESV_EXEMPT 425
#define SECONDS 426
#define MINUTES 427
#define HOURS 428
#define DAYS 429
#define WEEKS 430
#define SENDQ 431
#define SEND_PASSWORD 432
#define SERVERHIDE 433
#define SERVERINFO 434
#define SERVLINK_PATH 435
#define IRCD_SID 436
#define TKLINE_EXPIRE_NOTICES 437
#define T_SHARED 438
#define T_CLUSTER 439
#define TYPE 440
#define SHORT_MOTD 441
#define SILENT 442
#define SPOOF 443
#define SPOOF_NOTICE 444
#define STATS_E_DISABLED 445
#define STATS_I_OPER_ONLY 446
#define STATS_K_OPER_ONLY 447
#define STATS_O_OPER_ONLY 448
#define STATS_P_OPER_ONLY 449
#define TBOOL 450
#define TMASKED 451
#define T_REJECT 452
#define TS_MAX_DELTA 453
#define TS_WARN_DELTA 454
#define TWODOTS 455
#define T_ALL 456
#define T_BOTS 457
#define T_SOFTCALLERID 458
#define T_CALLERID 459
#define T_CCONN 460
#define T_CCONN_FULL 461
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
#define T_SERVER 484
#define T_SERVNOTICE 485
#define T_SKILL 486
#define T_SPY 487
#define T_SSL 488
#define T_UMODES 489
#define T_UNAUTH 490
#define T_UNRESV 491
#define T_UNXLINE 492
#define T_GLOBOPS 493
#define T_WALLOP 494
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
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 741 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 753 "ircd_parser.c"

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
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  322
/* YYNRULES -- Number of rules.  */
#define YYNRULES  694
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1368

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
     517,   519,   520,   526,   530,   532,   533,   537,   538,   541,
     543,   545,   547,   549,   551,   553,   555,   557,   559,   561,
     563,   565,   567,   569,   571,   573,   575,   576,   584,   585,
     587,   590,   592,   594,   596,   598,   600,   602,   604,   606,
     608,   610,   612,   614,   616,   618,   621,   626,   628,   633,
     638,   643,   648,   653,   658,   663,   668,   673,   678,   683,
     688,   689,   696,   697,   703,   707,   709,   711,   713,   715,
     718,   720,   722,   724,   726,   728,   731,   732,   738,   742,
     744,   746,   750,   755,   760,   761,   768,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   789,   792,   797,   802,
     807,   812,   813,   819,   823,   825,   826,   830,   831,   834,
     836,   838,   840,   842,   844,   846,   848,   850,   852,   857,
     862,   867,   868,   875,   878,   880,   882,   884,   886,   889,
     894,   899,   904,   910,   913,   915,   917,   919,   924,   925,
     932,   935,   937,   939,   941,   943,   946,   951,   956,   957,
     963,   967,   969,   971,   973,   975,   977,   979,   981,   983,
     985,   987,   989,   991,   992,   999,  1002,  1004,  1006,  1008,
    1011,  1016,  1017,  1023,  1027,  1029,  1031,  1033,  1035,  1037,
    1039,  1041,  1043,  1045,  1047,  1049,  1051,  1052,  1060,  1061,
    1063,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1096,  1099,  1104,  1106,
    1111,  1116,  1121,  1126,  1131,  1136,  1141,  1142,  1148,  1152,
    1154,  1155,  1159,  1160,  1163,  1165,  1167,  1169,  1171,  1173,
    1178,  1183,  1188,  1193,  1198,  1203,  1204,  1211,  1212,  1218,
    1222,  1224,  1226,  1229,  1231,  1233,  1235,  1237,  1239,  1244,
    1249,  1250,  1257,  1260,  1262,  1264,  1266,  1268,  1273,  1278,
    1284,  1287,  1289,  1291,  1293,  1298,  1299,  1306,  1307,  1313,
    1317,  1319,  1321,  1324,  1326,  1328,  1330,  1332,  1334,  1339,
    1344,  1350,  1353,  1355,  1357,  1359,  1361,  1363,  1365,  1367,
    1369,  1371,  1373,  1375,  1377,  1379,  1381,  1383,  1385,  1387,
    1389,  1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,  1407,
    1409,  1411,  1413,  1415,  1417,  1419,  1421,  1423,  1425,  1427,
    1429,  1431,  1433,  1435,  1437,  1439,  1441,  1443,  1445,  1447,
    1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,  1465,  1467,
    1472,  1477,  1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,
    1522,  1527,  1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,
    1572,  1577,  1582,  1587,  1592,  1597,  1602,  1607,  1612,  1617,
    1622,  1627,  1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,
    1672,  1677,  1682,  1687,  1692,  1697,  1702,  1707,  1712,  1717,
    1722,  1723,  1729,  1733,  1735,  1737,  1739,  1741,  1743,  1745,
    1747,  1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,
    1767,  1769,  1771,  1773,  1774,  1780,  1784,  1786,  1788,  1790,
    1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1810,
    1812,  1814,  1816,  1818,  1820,  1822,  1824,  1829,  1834,  1839,
    1844,  1845,  1852,  1855,  1857,  1859,  1861,  1863,  1865,  1867,
    1869,  1871,  1876,  1881,  1882,  1888,  1892,  1894,  1896,  1898,
    1903,  1908,  1909,  1915,  1919,  1921,  1923,  1925,  1931,  1934,
    1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,
    1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,  1972,  1974,
    1979,  1984,  1989,  1994,  1999,  2004,  2009,  2014,  2019,  2024,
    2029,  2034,  2039,  2044,  2049,  2054,  2059,  2064,  2070,  2073,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2096,
    2101,  2106,  2111,  2116,  2121
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,    -1,   267,   268,    -1,   296,    -1,   302,
      -1,   317,    -1,   557,    -1,   340,    -1,   359,    -1,   373,
      -1,   278,    -1,   578,    -1,   391,    -1,   398,    -1,   402,
      -1,   412,    -1,   421,    -1,   447,    -1,   457,    -1,   463,
      -1,   477,    -1,   541,    -1,   467,    -1,   273,    -1,     1,
     261,    -1,     1,   262,    -1,    -1,   270,    -1,   129,   269,
      -1,   129,   171,   269,    -1,   129,   172,   269,    -1,   129,
     173,   269,    -1,   129,   174,   269,    -1,   129,   175,   269,
      -1,    -1,   272,    -1,   129,   271,    -1,   129,    14,   271,
      -1,   129,    15,   271,    -1,   129,    16,   271,    -1,   117,
     263,   274,   262,   261,    -1,   274,   275,    -1,   275,    -1,
     276,    -1,   277,    -1,     1,   261,    -1,   116,   264,   151,
     261,    -1,   146,   264,   151,   261,    -1,   179,   263,   279,
     262,   261,    -1,   279,   280,    -1,   280,    -1,   287,    -1,
     292,    -1,   295,    -1,   289,    -1,   290,    -1,   291,    -1,
     294,    -1,   286,    -1,   293,    -1,   288,    -1,   285,    -1,
     281,    -1,     1,   261,    -1,    -1,   166,   282,   264,   283,
     261,    -1,   283,   265,   284,    -1,   284,    -1,   167,    -1,
     168,    -1,   165,   264,   151,   261,    -1,   163,   264,   151,
     261,    -1,   118,   264,   151,   261,    -1,   181,   264,   151,
     261,    -1,    36,   264,   151,   261,    -1,   121,   264,   151,
     261,    -1,   120,   264,   151,   261,    -1,   256,   264,   151,
     261,    -1,   257,   264,   151,   261,    -1,   225,   264,   129,
     261,    -1,    83,   264,   195,   261,    -1,     5,   263,   297,
     262,   261,    -1,   297,   298,    -1,   298,    -1,   299,    -1,
     301,    -1,   300,    -1,     1,   261,    -1,   118,   264,   151,
     261,    -1,    46,   264,   151,   261,    -1,    36,   264,   151,
     261,    -1,   100,   263,   303,   262,   261,    -1,   303,   304,
      -1,   304,    -1,   305,    -1,   306,    -1,   315,    -1,   316,
      -1,   307,    -1,   309,    -1,   311,    -1,   312,    -1,   314,
      -1,   310,    -1,   313,    -1,   308,    -1,     1,   261,    -1,
     217,   264,   151,   261,    -1,   136,   264,   151,   261,    -1,
      61,   264,   151,   261,    -1,    54,   264,   151,   261,    -1,
      59,   264,   151,   261,    -1,    60,   264,   151,   261,    -1,
      57,   264,   151,   261,    -1,    56,   264,   151,   261,    -1,
      58,   264,   151,   261,    -1,    55,   264,   151,   261,    -1,
     101,   264,   218,   261,    -1,   101,   264,   220,   261,    -1,
     101,   264,   224,   261,    -1,   101,   264,   222,   261,    -1,
     101,   264,   223,   261,    -1,   101,   264,   221,   261,    -1,
     101,   264,   219,   261,    -1,   254,   264,   195,   261,    -1,
      -1,   134,   318,   319,   263,   320,   262,   261,    -1,    -1,
     323,    -1,   320,   321,    -1,   321,    -1,   322,    -1,   324,
      -1,   325,    -1,   329,    -1,   328,    -1,   326,    -1,   327,
      -1,   333,    -1,     1,   261,    -1,   118,   264,   151,   261,
      -1,   151,    -1,   249,   264,   151,   261,    -1,   145,   264,
     151,   261,    -1,    48,   264,   195,   261,    -1,   164,   264,
     151,   261,    -1,    25,   264,   151,   261,    -1,    -1,   234,
     330,   264,   331,   261,    -1,   331,   265,   332,    -1,   332,
      -1,   202,    -1,   205,    -1,   206,    -1,   208,    -1,   209,
      -1,   212,    -1,   231,    -1,   226,    -1,   228,    -1,   235,
      -1,   232,    -1,   211,    -1,   227,    -1,   230,    -1,   213,
      -1,   239,    -1,   203,    -1,   204,    -1,   216,    -1,    -1,
      52,   334,   264,   335,   261,    -1,   335,   265,   336,    -1,
     336,    -1,    -1,   128,   337,   339,    -1,    -1,   338,   339,
      -1,    71,    -1,   159,    -1,    90,    -1,   248,    -1,   258,
      -1,    64,    -1,    37,    -1,   157,    -1,     5,    -1,    76,
      -1,   123,    -1,   227,    -1,   238,    -1,   139,    -1,    78,
      -1,   160,    -1,    48,    -1,    -1,    25,   341,   342,   263,
     343,   262,   261,    -1,    -1,   346,    -1,   343,   344,    -1,
     344,    -1,   345,    -1,   356,    -1,   357,    -1,   347,    -1,
     348,    -1,   358,    -1,   349,    -1,   350,    -1,   351,    -1,
     352,    -1,   353,    -1,   354,    -1,   355,    -1,     1,   261,
      -1,   118,   264,   151,   261,    -1,   151,    -1,   148,   264,
     270,   261,    -1,   149,   264,   270,   261,    -1,   132,   264,
     129,   261,    -1,    29,   264,   270,   261,    -1,   110,   264,
     129,   261,    -1,   105,   264,   129,   261,    -1,   107,   264,
     129,   261,    -1,   106,   264,   129,   261,    -1,   176,   264,
     272,   261,    -1,    22,   264,   129,   261,    -1,    23,   264,
     129,   261,    -1,   131,   264,   129,   261,    -1,    -1,    98,
     360,   263,   365,   262,   261,    -1,    -1,    52,   362,   264,
     363,   261,    -1,   363,   265,   364,    -1,   364,    -1,   233,
      -1,    75,    -1,   229,    -1,   365,   366,    -1,   366,    -1,
     367,    -1,   361,    -1,   371,    -1,   372,    -1,     1,   261,
      -1,    -1,   150,   264,   369,   368,   261,    -1,   369,   265,
     370,    -1,   370,    -1,   129,    -1,   129,   200,   129,    -1,
      87,   264,   151,   261,    -1,    82,   264,   151,   261,    -1,
      -1,    72,   374,   263,   375,   262,   261,    -1,   375,   376,
      -1,   376,    -1,   377,    -1,   378,    -1,   379,    -1,   381,
      -1,   388,    -1,   389,    -1,   390,    -1,   380,    -1,     1,
     261,    -1,   249,   264,   151,   261,    -1,   145,   264,   151,
     261,    -1,    25,   264,   151,   261,    -1,    48,   264,   195,
     261,    -1,    -1,    52,   382,   264,   383,   261,    -1,   383,
     265,   384,    -1,   384,    -1,    -1,   128,   385,   387,    -1,
      -1,   386,   387,    -1,   189,    -1,    49,    -1,    91,    -1,
      73,    -1,    20,    -1,   127,    -1,    66,    -1,   170,    -1,
     119,    -1,   188,   264,   151,   261,    -1,   155,   264,   151,
     261,    -1,   154,   264,   129,   261,    -1,    -1,   169,   392,
     263,   393,   262,   261,    -1,   393,   394,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,     1,   261,    -1,   153,
     264,   151,   261,    -1,    21,   264,   151,   261,    -1,   122,
     264,   151,   261,    -1,   240,   263,   399,   262,   261,    -1,
     399,   400,    -1,   400,    -1,   401,    -1,     1,    -1,   118,
     264,   151,   261,    -1,    -1,   183,   403,   263,   404,   262,
     261,    -1,   404,   405,    -1,   405,    -1,   406,    -1,   407,
      -1,   408,    -1,     1,   261,    -1,   118,   264,   151,   261,
      -1,   249,   264,   151,   261,    -1,    -1,   185,   409,   264,
     410,   261,    -1,   410,   265,   411,    -1,   411,    -1,    90,
      -1,   245,    -1,   248,    -1,   258,    -1,   246,    -1,   237,
      -1,   169,    -1,   247,    -1,   236,    -1,   216,    -1,   201,
      -1,    -1,   184,   413,   263,   414,   262,   261,    -1,   414,
     415,    -1,   415,    -1,   416,    -1,   417,    -1,     1,   261,
      -1,   118,   264,   151,   261,    -1,    -1,   185,   418,   264,
     419,   261,    -1,   419,   265,   420,    -1,   420,    -1,    90,
      -1,   245,    -1,   248,    -1,   258,    -1,   246,    -1,   237,
      -1,   169,    -1,   247,    -1,   236,    -1,   216,    -1,   201,
      -1,    -1,    28,   422,   423,   263,   424,   262,   261,    -1,
      -1,   427,    -1,   424,   425,    -1,   425,    -1,   426,    -1,
     428,    -1,   429,    -1,   430,    -1,   431,    -1,   433,    -1,
     432,    -1,   434,    -1,   443,    -1,   444,    -1,   445,    -1,
     442,    -1,   441,    -1,   446,    -1,     1,   261,    -1,   118,
     264,   151,   261,    -1,   151,    -1,    82,   264,   151,   261,
      -1,   256,   264,   151,   261,    -1,   177,   264,   151,   261,
      -1,     3,   264,   151,   261,    -1,   150,   264,   129,   261,
      -1,     6,   264,   214,   261,    -1,     6,   264,   215,   261,
      -1,    -1,    52,   435,   264,   436,   261,    -1,   436,   265,
     437,    -1,   437,    -1,    -1,   128,   438,   440,    -1,    -1,
     439,   440,    -1,    26,    -1,    30,    -1,    10,    -1,    12,
      -1,   243,    -1,   164,   264,   151,   261,    -1,    48,   264,
     195,   261,    -1,    84,   264,   151,   261,    -1,    96,   264,
     151,   261,    -1,    25,   264,   151,   261,    -1,    24,   264,
     151,   261,    -1,    -1,    88,   448,   263,   453,   262,   261,
      -1,    -1,   185,   450,   264,   451,   261,    -1,   451,   265,
     452,    -1,   452,    -1,   156,    -1,   453,   454,    -1,   454,
      -1,   455,    -1,   456,    -1,   449,    -1,     1,    -1,   249,
     264,   151,   261,    -1,   153,   264,   151,   261,    -1,    -1,
      35,   458,   263,   459,   262,   261,    -1,   459,   460,    -1,
     460,    -1,   461,    -1,   462,    -1,     1,    -1,    87,   264,
     151,   261,    -1,   153,   264,   151,   261,    -1,    50,   263,
     464,   262,   261,    -1,   464,   465,    -1,   465,    -1,   466,
      -1,     1,    -1,    87,   264,   151,   261,    -1,    -1,    62,
     468,   263,   473,   262,   261,    -1,    -1,   185,   470,   264,
     471,   261,    -1,   471,   265,   472,    -1,   472,    -1,   156,
      -1,   473,   474,    -1,   474,    -1,   475,    -1,   476,    -1,
     469,    -1,     1,    -1,   118,   264,   151,   261,    -1,   153,
     264,   151,   261,    -1,    63,   263,   478,   262,   261,    -1,
     478,   479,    -1,   479,    -1,   488,    -1,   489,    -1,   491,
      -1,   492,    -1,   493,    -1,   494,    -1,   495,    -1,   496,
      -1,   497,    -1,   498,    -1,   487,    -1,   500,    -1,   501,
      -1,   502,    -1,   503,    -1,   518,    -1,   505,    -1,   507,
      -1,   509,    -1,   508,    -1,   512,    -1,   506,    -1,   513,
      -1,   514,    -1,   515,    -1,   516,    -1,   517,    -1,   533,
      -1,   519,    -1,   523,    -1,   524,    -1,   529,    -1,   510,
      -1,   511,    -1,   539,    -1,   537,    -1,   538,    -1,   520,
      -1,   490,    -1,   521,    -1,   522,    -1,   540,    -1,   528,
      -1,   499,    -1,   526,    -1,   527,    -1,   483,    -1,   486,
      -1,   481,    -1,   482,    -1,   484,    -1,   485,    -1,   504,
      -1,   480,    -1,   525,    -1,     1,    -1,   112,   264,   129,
     261,    -1,    69,   264,   129,   261,    -1,    70,   264,   129,
     261,    -1,    12,   264,   195,   261,    -1,   255,   264,   195,
     261,    -1,   158,   264,   270,   261,    -1,   182,   264,   195,
     261,    -1,    89,   264,   270,   261,    -1,    81,   264,   195,
     261,    -1,    85,   264,   195,   261,    -1,    42,   264,   195,
     261,    -1,    51,   264,   195,   261,    -1,     8,   264,   195,
     261,    -1,   109,   264,   270,   261,    -1,   108,   264,   129,
     261,    -1,   102,   264,   129,   261,    -1,     9,   264,   270,
     261,    -1,   199,   264,   270,   261,    -1,   198,   264,   270,
     261,    -1,    74,   264,   129,   261,    -1,    93,   264,   195,
     261,    -1,    92,   264,   151,   261,    -1,    86,   264,   195,
     261,    -1,   260,   264,   195,   261,    -1,   190,   264,   195,
     261,    -1,   193,   264,   195,   261,    -1,   194,   264,   195,
     261,    -1,   192,   264,   195,   261,    -1,   192,   264,   196,
     261,    -1,   191,   264,   195,   261,    -1,   191,   264,   196,
     261,    -1,   143,   264,   270,   261,    -1,    19,   264,   270,
     261,    -1,   135,   264,   195,   261,    -1,   144,   264,   270,
     261,    -1,   186,   264,   195,   261,    -1,   126,   264,   195,
     261,    -1,   244,   264,   195,   261,    -1,   138,   264,   195,
     261,    -1,   113,   264,   151,   261,    -1,    43,   264,   129,
     261,    -1,   111,   264,   129,   261,    -1,   180,   264,   151,
     261,    -1,    31,   264,   151,   261,    -1,    27,   264,   129,
     261,    -1,   250,   264,   195,   261,    -1,    45,   264,   151,
     261,    -1,   241,   264,   151,   261,    -1,   147,   264,   195,
     261,    -1,    38,   264,   195,   261,    -1,   242,   264,   270,
     261,    -1,    -1,   140,   530,   264,   531,   261,    -1,   531,
     265,   532,    -1,   532,    -1,   202,    -1,   205,    -1,   206,
      -1,   208,    -1,   209,    -1,   212,    -1,   231,    -1,   226,
      -1,   228,    -1,   235,    -1,   232,    -1,   211,    -1,   227,
      -1,   230,    -1,   213,    -1,   239,    -1,   203,    -1,   204,
      -1,   216,    -1,    -1,   137,   534,   264,   535,   261,    -1,
     535,   265,   536,    -1,   536,    -1,   202,    -1,   205,    -1,
     206,    -1,   208,    -1,   209,    -1,   212,    -1,   231,    -1,
     226,    -1,   228,    -1,   235,    -1,   232,    -1,   211,    -1,
     227,    -1,   230,    -1,   213,    -1,   239,    -1,   203,    -1,
     204,    -1,   216,    -1,   114,   264,   129,   261,    -1,   115,
     264,   129,   261,    -1,    32,   264,   129,   261,    -1,   207,
     264,   272,   261,    -1,    -1,    65,   542,   263,   543,   262,
     261,    -1,   543,   544,    -1,   544,    -1,   545,    -1,   546,
      -1,   547,    -1,   551,    -1,   552,    -1,   553,    -1,     1,
      -1,    47,   264,   195,   261,    -1,    44,   264,   270,   261,
      -1,    -1,   100,   548,   264,   549,   261,    -1,   549,   265,
     550,    -1,   550,    -1,   197,    -1,    11,    -1,   249,   264,
     151,   261,    -1,   118,   264,   151,   261,    -1,    -1,     4,
     554,   264,   555,   261,    -1,   555,   265,   556,    -1,   556,
      -1,   197,    -1,    11,    -1,    21,   263,   558,   262,   261,
      -1,   558,   559,    -1,   559,    -1,   562,    -1,   563,    -1,
     564,    -1,   565,    -1,   570,    -1,   566,    -1,   567,    -1,
     568,    -1,   569,    -1,   571,    -1,   572,    -1,   573,    -1,
     561,    -1,   574,    -1,   575,    -1,   576,    -1,   577,    -1,
     560,    -1,     1,    -1,    39,   264,   195,   261,    -1,   161,
     264,   195,   261,    -1,    41,   264,   195,   261,    -1,   251,
     264,   195,   261,    -1,   252,   264,   195,   261,    -1,   253,
     264,   195,   261,    -1,    94,   264,   270,   261,    -1,    95,
     264,   270,   261,    -1,   104,   264,   129,   261,    -1,   152,
     264,   195,   261,    -1,   103,   264,   129,   261,    -1,    34,
     264,   129,   261,    -1,    33,   264,   129,   261,    -1,   124,
     264,   195,   261,    -1,   125,   264,   195,   261,    -1,    13,
     264,   195,   261,    -1,   141,   264,   129,   261,    -1,   142,
     264,   270,   261,    -1,   178,   263,   579,   262,   261,    -1,
     579,   580,    -1,   580,    -1,   581,    -1,   582,    -1,   584,
      -1,   586,    -1,   585,    -1,   583,    -1,   587,    -1,     1,
      -1,    53,   264,   195,   261,    -1,    80,   264,   195,   261,
      -1,    77,   264,   151,   261,    -1,    97,   264,   270,   261,
      -1,    75,   264,   195,   261,    -1,    40,   264,   195,   261,
      -1,    79,   264,   195,   261,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   395,   395,   396,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   425,   425,   426,
     430,   434,   438,   442,   446,   452,   452,   453,   454,   455,
     456,   463,   466,   466,   467,   467,   467,   469,   475,   482,
     484,   484,   485,   485,   486,   486,   487,   487,   488,   489,
     489,   490,   490,   491,   492,   496,   495,   514,   514,   515,
     521,   529,   563,   623,   638,   653,   662,   676,   685,   713,
     743,   766,   775,   777,   777,   778,   778,   779,   779,   781,
     790,   799,   812,   814,   815,   817,   817,   818,   819,   819,
     820,   820,   821,   821,   822,   822,   823,   824,   826,   830,
     834,   841,   848,   855,   862,   869,   876,   883,   890,   894,
     898,   902,   906,   910,   914,   920,   930,   929,  1023,  1023,
    1024,  1024,  1025,  1025,  1025,  1026,  1026,  1026,  1027,  1027,
    1027,  1029,  1041,  1053,  1087,  1099,  1110,  1152,  1162,  1161,
    1167,  1167,  1168,  1172,  1176,  1180,  1184,  1188,  1192,  1196,
    1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,
    1240,  1247,  1246,  1250,  1250,  1251,  1251,  1252,  1252,  1254,
    1261,  1268,  1275,  1282,  1289,  1296,  1303,  1310,  1317,  1324,
    1331,  1338,  1345,  1352,  1359,  1366,  1380,  1379,  1429,  1429,
    1431,  1431,  1432,  1433,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1443,  1444,  1446,  1455,  1464,  1470,
    1476,  1482,  1488,  1494,  1500,  1506,  1512,  1518,  1524,  1530,
    1540,  1539,  1556,  1555,  1560,  1560,  1561,  1565,  1569,  1577,
    1577,  1578,  1578,  1578,  1578,  1578,  1580,  1580,  1582,  1582,
    1584,  1598,  1618,  1627,  1640,  1639,  1708,  1708,  1709,  1709,
    1709,  1709,  1710,  1710,  1710,  1711,  1711,  1713,  1750,  1763,
    1772,  1784,  1783,  1787,  1787,  1788,  1788,  1789,  1789,  1791,
    1798,  1805,  1812,  1819,  1826,  1833,  1840,  1847,  1857,  1876,
    1886,  1900,  1899,  1915,  1915,  1916,  1916,  1916,  1916,  1918,
    1927,  1942,  1955,  1957,  1957,  1958,  1958,  1960,  1976,  1975,
    1991,  1991,  1992,  1992,  1992,  1992,  1994,  2003,  2026,  2025,
    2031,  2031,  2032,  2036,  2040,  2044,  2048,  2052,  2056,  2060,
    2064,  2068,  2072,  2082,  2081,  2098,  2098,  2099,  2099,  2099,
    2101,  2108,  2107,  2113,  2113,  2114,  2118,  2122,  2126,  2130,
    2134,  2138,  2142,  2146,  2150,  2154,  2164,  2163,  2309,  2309,
    2310,  2310,  2311,  2311,  2311,  2312,  2312,  2313,  2313,  2314,
    2314,  2314,  2315,  2315,  2316,  2316,  2317,  2319,  2331,  2343,
    2352,  2378,  2396,  2414,  2420,  2424,  2433,  2432,  2436,  2436,
    2437,  2437,  2438,  2438,  2440,  2451,  2458,  2465,  2472,  2482,
    2523,  2534,  2547,  2560,  2569,  2605,  2604,  2668,  2667,  2671,
    2671,  2672,  2678,  2678,  2679,  2679,  2679,  2679,  2681,  2700,
    2710,  2709,  2732,  2732,  2733,  2733,  2733,  2735,  2741,  2750,
    2752,  2752,  2753,  2753,  2755,  2774,  2773,  2821,  2820,  2824,
    2824,  2825,  2831,  2831,  2832,  2832,  2832,  2832,  2834,  2840,
    2849,  2852,  2852,  2853,  2853,  2854,  2854,  2855,  2855,  2856,
    2856,  2857,  2857,  2858,  2858,  2859,  2859,  2860,  2860,  2861,
    2861,  2862,  2862,  2863,  2863,  2864,  2864,  2865,  2865,  2866,
    2867,  2867,  2868,  2868,  2869,  2869,  2870,  2870,  2871,  2871,
    2872,  2872,  2873,  2874,  2874,  2875,  2875,  2876,  2877,  2877,
    2878,  2878,  2879,  2879,  2880,  2880,  2881,  2881,  2882,  2885,
    2890,  2895,  2900,  2905,  2910,  2915,  2920,  2925,  2930,  2935,
    2940,  2945,  2950,  2955,  2960,  2965,  2970,  2975,  2981,  2992,
    2997,  3006,  3011,  3016,  3021,  3026,  3031,  3034,  3039,  3042,
    3047,  3052,  3057,  3062,  3067,  3072,  3077,  3082,  3087,  3098,
    3103,  3108,  3117,  3149,  3167,  3172,  3181,  3190,  3195,  3200,
    3206,  3205,  3210,  3210,  3211,  3214,  3217,  3220,  3223,  3226,
    3229,  3232,  3235,  3238,  3241,  3244,  3247,  3250,  3253,  3256,
    3259,  3262,  3265,  3271,  3270,  3275,  3275,  3276,  3279,  3282,
    3285,  3288,  3291,  3294,  3297,  3300,  3303,  3306,  3309,  3312,
    3315,  3318,  3321,  3324,  3327,  3330,  3335,  3340,  3345,  3350,
    3360,  3359,  3383,  3383,  3384,  3385,  3386,  3387,  3388,  3389,
    3390,  3392,  3398,  3405,  3404,  3409,  3409,  3410,  3414,  3420,
    3454,  3464,  3463,  3513,  3513,  3514,  3518,  3527,  3530,  3530,
    3531,  3531,  3532,  3532,  3533,  3533,  3534,  3534,  3535,  3535,
    3536,  3537,  3537,  3538,  3538,  3539,  3539,  3540,  3540,  3542,
    3547,  3552,  3557,  3562,  3567,  3572,  3577,  3582,  3587,  3592,
    3597,  3602,  3607,  3612,  3617,  3622,  3627,  3635,  3638,  3638,
    3639,  3639,  3640,  3641,  3642,  3642,  3643,  3644,  3646,  3652,
    3658,  3667,  3681,  3687,  3693
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
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS",
  "T_WALLOP", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
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
  "oper_flags_items", "oper_flags_item", "$@5", "$@6",
  "oper_flags_item_atom", "class_entry", "$@7", "class_name_b",
  "class_items", "class_item", "class_name", "class_name_t",
  "class_ping_time", "class_ping_warning", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@8", "listen_flags", "$@9",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@10", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@11", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@12", "auth_flags_items", "auth_flags_item", "$@13", "$@14",
  "auth_flags_item_atom", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_creason", "resv_channel", "resv_nick", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_name_b", "connect_items",
  "connect_item", "connect_name", "connect_name_t", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_flags", "$@21",
  "connect_flags_items", "connect_flags_item", "$@22", "$@23",
  "connect_flags_item_atom", "connect_rsa_public_key_file",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_cipher_preference", "kill_entry", "$@24",
  "kill_type", "$@25", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@26",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@27",
  "gecos_flags", "$@28", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_min_cidr", "general_gline_min_cidr6",
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
  "general_message_locale", "general_dots_in_ident", "general_max_targets",
  "general_servlink_path", "general_default_cipher_preference",
  "general_compression_level", "general_use_egd", "general_egdpool_path",
  "general_services_name", "general_ping_cookie", "general_disable_auth",
  "general_throttle_time", "general_oper_umodes", "$@29", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@30", "umode_items",
  "umode_item", "general_min_nonwildcard",
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
     332,   334,   333,   335,   335,   337,   336,   338,   336,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   341,   340,   342,   342,
     343,   343,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   344,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     360,   359,   362,   361,   363,   363,   364,   364,   364,   365,
     365,   366,   366,   366,   366,   366,   368,   367,   369,   369,
     370,   370,   371,   372,   374,   373,   375,   375,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   377,   378,   379,
     380,   382,   381,   383,   383,   385,   384,   386,   384,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   388,   389,
     390,   392,   391,   393,   393,   394,   394,   394,   394,   395,
     396,   397,   398,   399,   399,   400,   400,   401,   403,   402,
     404,   404,   405,   405,   405,   405,   406,   407,   409,   408,
     410,   410,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   413,   412,   414,   414,   415,   415,   415,
     416,   418,   417,   419,   419,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   422,   421,   423,   423,
     424,   424,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   433,   435,   434,   436,   436,
     438,   437,   439,   437,   440,   440,   440,   440,   440,   441,
     442,   443,   444,   445,   446,   448,   447,   450,   449,   451,
     451,   452,   453,   453,   454,   454,   454,   454,   455,   456,
     458,   457,   459,   459,   460,   460,   460,   461,   462,   463,
     464,   464,   465,   465,   466,   468,   467,   470,   469,   471,
     471,   472,   473,   473,   474,   474,   474,   474,   475,   476,
     477,   478,   478,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   507,   508,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     530,   529,   531,   531,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   534,   533,   535,   535,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   537,   538,   539,   540,
     542,   541,   543,   543,   544,   544,   544,   544,   544,   544,
     544,   545,   546,   548,   547,   549,   549,   550,   550,   551,
     552,   554,   553,   555,   555,   556,   556,   557,   558,   558,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   579,
     580,   580,   580,   580,   580,   580,   580,   580,   581,   582,
     583,   584,   585,   586,   587
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
       1,     0,     5,     3,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     7,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     6,     0,     5,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     7,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     4,
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   196,   356,   420,     0,
     435,     0,   610,   254,   405,   230,     0,     0,   126,   291,
       0,     0,   308,   333,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   198,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   658,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   639,
     657,   652,   640,   641,   642,   643,   645,   646,   647,   648,
     644,   649,   650,   651,   653,   654,   655,   656,   217,     0,
     199,   378,     0,   359,     0,   433,     0,     0,   431,   432,
       0,   508,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   583,     0,   560,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   452,   506,
     501,   502,   499,   503,   504,   500,   463,   453,   454,   491,
     455,   456,   457,   458,   459,   460,   461,   462,   496,   464,
     465,   466,   467,   505,   469,   474,   470,   472,   471,   485,
     486,   473,   475,   476,   477,   478,   479,   468,   481,   490,
     492,   493,   482,   483,   507,   497,   498,   495,   484,   480,
     488,   489,   487,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    99,   106,   100,   104,   101,
     102,   105,   103,    97,    98,     0,     0,     0,     0,    43,
      44,    45,   142,     0,   129,     0,   687,     0,     0,     0,
       0,     0,     0,     0,     0,   679,   680,   681,   685,   682,
     684,   683,   686,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,    51,    63,    62,
      59,    52,    61,    55,    56,    57,    53,    60,    58,    54,
       0,     0,   306,     0,     0,   304,   305,    88,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   638,     0,     0,   426,     0,     0,     0,   423,
     424,   425,     0,     0,   430,   447,     0,     0,   437,   446,
       0,   443,   444,   445,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     451,   620,   631,     0,     0,   623,     0,     0,     0,   613,
     614,   615,   616,   617,   618,   619,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,   257,   258,   259,   260,
     265,   261,   262,   263,   264,   417,     0,   407,     0,   416,
       0,   413,   414,   415,     0,   232,     0,     0,     0,   242,
       0,   240,   241,   243,   244,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      46,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   294,   295,   296,   297,     0,     0,     0,     0,     0,
       0,     0,     0,   678,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   318,     0,     0,   311,   312,   313,   314,     0,     0,
     341,     0,   336,   337,   338,     0,     0,   303,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   202,   205,
     206,   208,   209,   210,   211,   212,   213,   214,   203,   204,
     207,     0,     0,     0,     0,     0,     0,   386,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,   362,   363,
     364,   365,   366,   368,   367,   369,   374,   373,   370,   371,
     372,   375,     0,     0,     0,   422,     0,   429,     0,     0,
       0,     0,   442,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,   450,     0,     0,     0,     0,     0,     0,     0,   612,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,   412,   245,     0,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    41,     0,     0,     0,   171,     0,
       0,     0,   148,     0,     0,   131,   132,   133,   134,   137,
     138,   136,   135,   139,   298,     0,     0,     0,     0,   293,
       0,     0,     0,     0,     0,     0,     0,   677,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,   315,     0,     0,     0,     0,   310,   339,     0,     0,
       0,   335,     0,   302,    91,    90,    89,   674,   671,   670,
     659,   661,    27,    27,    27,    27,    27,    29,    28,   665,
     666,   669,   667,   672,   673,   675,   676,   668,   660,   662,
     663,   664,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   376,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   360,     0,     0,   421,   434,     0,
       0,     0,   436,   521,   525,   512,   541,   553,   552,   608,
     558,   519,   549,   555,   520,   510,   511,   528,   517,   518,
     531,   516,   530,   529,   524,   523,   522,   550,   509,   548,
     606,   607,   545,   542,   587,   603,   604,   588,   589,   590,
     591,   598,   592,   601,   605,   594,   599,   595,   600,   593,
     597,   596,   602,     0,   586,   547,   564,   580,   581,   565,
     566,   567,   568,   575,   569,   578,   582,   571,   576,   572,
     577,   570,   574,   573,   579,     0,   563,   540,   543,   557,
     514,   551,   515,   544,   533,   538,   539,   536,   537,   534,
     535,   527,   526,    35,    35,    35,    37,    36,   609,   556,
     559,   546,   554,   513,   532,     0,     0,     0,     0,     0,
       0,   611,     0,     0,   277,     0,     0,     0,     0,     0,
     255,     0,     0,     0,   406,     0,     0,     0,   250,   246,
     249,   231,   111,   117,   115,   114,   116,   112,   113,   110,
     118,   124,   119,   123,   121,   122,   120,   109,   108,   125,
      47,    48,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,   292,   693,   688,   692,
     690,   694,   689,   691,    75,    81,    73,    77,    76,    72,
      71,    69,    70,     0,    68,    74,    80,    78,    79,     0,
       0,     0,   309,     0,     0,   334,   307,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
       0,     0,   392,     0,     0,     0,     0,     0,     0,     0,
       0,   357,   427,   428,   448,   449,   441,     0,   440,   584,
       0,   561,     0,    38,    39,    40,   636,   635,     0,   634,
     622,   621,   628,   627,     0,   626,   630,   629,   269,   270,
     275,     0,   274,     0,   268,   290,   289,   288,   267,   419,
     411,     0,   410,   418,   237,   238,   236,     0,   235,   253,
     252,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,   127,   300,   301,   299,    66,     0,   316,   322,
     328,   332,   331,   330,   327,   323,   326,   329,   324,   325,
       0,   321,   317,   340,   345,   351,   355,   354,   353,   350,
     346,   349,   352,   347,   348,     0,   344,   227,   228,   221,
     223,   225,   224,   222,   216,   229,   220,   218,   219,   226,
     382,   384,   385,   404,   403,   400,   390,     0,   389,     0,
     379,   401,   402,   377,   383,   399,   381,   380,   438,     0,
     585,   562,   632,     0,   624,     0,     0,   272,   277,   283,
     280,   285,   282,   281,   287,   284,   286,   279,   278,   408,
       0,   233,     0,   251,   248,   247,   147,   145,   175,     0,
     174,     0,   141,   144,   146,   152,   168,   169,   153,   154,
     155,   156,   163,   157,   166,   170,   159,   164,   160,   165,
     158,   162,   161,   167,     0,   151,   143,    67,   319,     0,
     342,     0,     0,   387,   392,   396,   397,   394,   395,   398,
     393,   439,   633,   625,   276,   273,   409,   234,     0,   172,
     177,   187,   185,   195,   184,   179,   188,   193,   181,   189,
     192,   186,   180,   194,   190,   191,   182,   183,   178,   149,
       0,   320,   343,   391,   388,   176,   173,   150
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
     789,   790,   791,   792,  1059,  1314,  1315,   793,  1055,  1289,
    1290,  1338,  1291,  1358,    31,    51,   119,   606,   607,   608,
     120,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,    32,    60,   489,   747,  1177,  1178,   490,
     491,   492,  1183,  1029,  1030,   493,   494,    33,    58,   465,
     466,   467,   468,   469,   470,   471,   733,  1161,  1162,  1266,
    1163,  1278,   472,   473,   474,    34,    64,   520,   521,   522,
     523,   524,    35,   334,   335,   336,    36,    67,   553,   554,
     555,   556,   557,   823,  1210,  1211,    37,    68,   561,   562,
     563,   564,   829,  1225,  1226,    38,    52,   122,   636,   637,
     638,   123,   639,   640,   641,   642,   643,   644,   645,   884,
    1247,  1248,  1322,  1249,  1330,   646,   647,   648,   649,   650,
     651,    39,    59,   479,   742,  1171,  1172,   480,   481,   482,
     483,    40,    53,   368,   369,   370,   371,    41,   127,   128,
     129,    42,    55,   379,   660,  1137,  1138,   380,   381,   382,
     383,    43,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   417,   975,   976,   239,   415,   953,
     954,   240,   241,   242,   243,    44,    57,   448,   449,   450,
     451,   452,   725,  1154,  1155,   453,   454,   455,   722,  1148,
    1149,    45,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    46,   294,   295,   296,   297,   298,   299,   300,
     301,   302
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -622
static const yytype_int16 yypact[] =
{
    -622,   715,  -622,  -218,  -245,  -237,  -622,  -622,  -622,  -231,
    -622,  -228,  -622,  -622,  -622,  -622,  -202,  -196,  -622,  -622,
    -194,  -191,  -622,  -622,  -185,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   298,
     644,  -140,   -61,  -183,    16,  -161,   429,  -150,  -147,  -144,
    -124,   432,    75,    -9,  -109,   564,   248,   -88,   -70,    20,
     -45,   -64,   -16,   -13,     2,  -622,  -622,  -622,  -622,  -622,
      -6,     9,    23,    36,    50,    63,    82,    83,    92,    93,
      95,    98,    99,   101,   103,   106,   113,   115,   130,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   -28,
    -622,  -622,     5,  -622,    24,  -622,   116,    48,  -622,  -622,
     132,  -622,   120,   121,   123,   124,   125,   127,   129,   134,
     135,   136,   139,   140,   141,   142,   144,   145,   146,   148,
     151,   153,   154,   157,   161,   162,   163,   164,   168,   171,
     172,   179,   180,  -622,   182,  -622,   189,   190,   191,   194,
     198,   199,   200,   201,   202,   204,   205,   206,   211,   212,
     214,   215,   217,   218,   219,   220,   230,    15,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,   301,   510,     3,   236,   234,   232,
     233,   237,   238,   242,   243,   244,   245,   249,   252,   255,
     259,   185,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,   239,   260,   265,    30,  -622,
    -622,  -622,  -622,   131,  -622,    29,  -622,   266,   268,   270,
     272,   281,   282,   284,    35,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,   288,   290,   295,   296,   297,   306,   307,
     313,  -622,   314,   316,   324,   325,   195,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
     105,   186,  -622,   326,    39,  -622,  -622,  -622,   246,   308,
     406,   331,  -622,   399,   261,   466,   401,   402,   470,   470,
     471,   474,   411,   412,   479,   470,   415,   417,   418,   419,
     421,   340,  -622,   702,   550,  -622,   354,   360,     7,  -622,
    -622,  -622,   475,   364,  -622,  -622,   365,   366,  -622,  -622,
      19,  -622,  -622,  -622,   436,   470,   438,   470,   506,   486,
     511,   447,   452,   519,   499,   456,   523,   524,   527,   463,
     464,   465,   470,   512,   467,   537,   538,   470,   540,   547,
     529,   552,   553,   492,   493,   433,   504,   437,   470,   470,
     507,   470,   554,   509,   513,   514,  -103,   -48,   517,   518,
     470,   470,   577,   556,   470,   522,   526,   528,   531,   449,
    -622,  -622,  -622,   455,   458,  -622,   468,   469,    18,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,   473,   477,   480,  -622,
     481,   482,   485,   487,   488,    73,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,   490,  -622,   491,  -622,
      14,  -622,  -622,  -622,   476,  -622,   494,   496,   497,  -622,
     133,  -622,  -622,  -622,  -622,  -622,   578,   579,   584,   605,
     606,   611,   613,   615,   472,   616,   619,   533,   520,  -622,
    -622,   620,   623,   521,  -622,   278,   530,   508,   525,   534,
      76,  -622,  -622,  -622,  -622,   580,   581,   588,   633,   593,
     597,   470,   532,  -622,  -622,   643,   600,   648,   649,   650,
     651,   653,   546,   660,   685,   665,   666,   557,  -622,   558,
     559,  -622,   560,    62,  -622,  -622,  -622,  -622,   565,   561,
    -622,    27,  -622,  -622,  -622,   670,   566,  -622,   567,   569,
     570,  -622,   574,   575,   582,   585,   586,   410,   587,   591,
     592,   594,   595,   598,   599,   601,   602,   609,   610,   622,
     624,  -622,   626,   576,   590,   608,   617,   618,   625,   627,
     641,   652,   654,   655,   656,   657,   188,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,   629,   658,   659,   663,   667,   668,  -622,   671,   672,
     679,   682,   686,   687,   689,   690,   178,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,   688,   691,   631,  -622,   647,  -622,   694,   710,
     692,   673,  -622,   696,   697,   699,   700,   704,   708,   709,
     711,   712,   713,   720,   723,   727,   728,   730,   731,   732,
     733,   734,   735,   737,   738,   742,   746,   747,   749,   750,
     751,   753,   754,   755,   698,   756,   736,   757,   758,   759,
     760,   761,   762,   763,   764,   765,   766,   767,   768,   769,
     770,   771,   772,   293,   773,   775,   776,   777,   778,   779,
     780,  -622,   695,   470,   646,   781,   726,   729,   782,  -622,
    -622,   846,   693,   783,   884,   784,   891,   893,   895,   787,
    -622,   898,   786,   900,   791,  -622,  -622,   789,   903,   904,
     788,   795,  -622,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,   810,   811,   812,
     813,  -622,   814,   815,  -622,   816,   817,   818,  -622,   819,
     820,   821,  -622,   822,     4,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,   927,   928,   929,   826,  -622,
     827,   828,   829,   830,   831,   832,   833,  -622,   834,   835,
     836,   837,   838,   839,   840,   165,   841,   842,   843,   844,
    -622,  -622,   955,   845,   956,   847,  -622,  -622,   959,   848,
     850,  -622,   852,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,   470,   470,   470,   470,   470,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,   985,   986,   470,   987,   988,   989,   990,
     969,   992,   993,   470,   470,   577,   862,  -622,  -622,   973,
     126,   974,   975,   717,   863,   977,   978,   979,   980,  1003,
     982,   983,   984,   875,  -622,   876,   877,  -622,  -622,   878,
     879,   991,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -252,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -251,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,   577,   577,   577,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,    -5,   880,   881,    22,   882,
     883,  -622,   885,   887,  1017,   888,   889,   890,   892,   894,
    -622,   896,   996,   897,  -622,   -63,   899,   901,   638,   902,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  1005,   964,   905,  1010,  1012,  1013,   906,
    1014,   907,  -622,   910,   911,   912,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -220,  -622,  -622,  -622,  -622,  -622,   913,
     621,   914,  -622,   915,   628,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   925,   926,   930,   931,  -622,   932,   933,   934,   935,
     936,   937,  1026,   938,   939,   940,   941,   942,   943,   944,
     945,  -622,  -622,  -622,  -622,  -622,  -622,  -210,  -622,  -622,
     698,  -622,   736,  -622,  -622,  -622,  -622,  -622,  -197,  -622,
    -622,  -622,  -622,  -622,  -174,  -622,  -622,  -622,  -622,  -622,
    -622,  -156,  -622,   358,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -121,  -622,  -622,  -622,  -622,  -622,  -100,  -622,  -622,
    -622,  1037,   788,   946,   947,   948,  1060,   949,   950,   951,
     774,   952,  -622,  -622,  -622,  -622,  -622,   165,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
     -87,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,   -71,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,   -29,  -622,    69,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   991,
    -622,  -622,  -622,    -5,  -622,    22,   358,  -622,  1017,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
     996,  -622,   -63,  -622,  -622,  -622,  -622,  -622,  -622,    64,
    -622,   515,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,    78,  -622,  -622,  -622,  -622,   621,
    -622,   628,    69,  -622,  1026,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   515,  -622,
    1060,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
     774,  -622,  -622,  -622,  -622,  -622,  -622,  -622
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -622,  -622,  -622,  -493,  -348,  -621,  -430,  -622,  -622,   501,
    -622,  -622,  -622,  -622,   873,  -622,  -622,  -622,  -282,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  1116,  -622,  -622,  -622,  -622,  -622,   953,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,   431,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -143,  -622,  -622,  -622,
    -122,  -622,  -622,  -119,  -622,  -622,  -622,  -622,   614,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   -66,  -622,
     739,  -622,  -622,  -622,    40,  -622,  -622,  -622,  -622,  -622,
     785,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   -47,  -622,
    -622,   -43,  -622,  -622,  -622,  -622,  -622,  -622,   705,  -622,
    -622,  -622,  -622,  -622,   908,  -622,  -622,  -622,  -622,   674,
    -622,  -622,  -622,  -622,  -622,   -95,  -622,  -622,  -622,   669,
    -622,  -622,  -622,  -622,   -93,  -622,  -622,  -622,  -622,   596,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,   -98,  -622,  -622,   -91,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,   -46,  -622,   790,  -622,
    -622,  -622,  -622,  -622,   865,  -622,  -622,  -622,  -622,  1108,
    -622,  -622,  -622,  -622,  -622,  -622,   -23,  -622,   857,  -622,
    -622,  -622,  -622,  1051,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,    97,  -622,  -622,  -622,
     100,  -622,  -622,  -622,  -622,  -622,  -622,  -622,   793,  -622,
    -622,  -622,  -622,  -622,   -22,  -622,  -622,  -622,  -622,  -622,
     -19,  -622,  -622,  1147,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,  -622,
    -622,  -622,  -622,  -622,   954,  -622,  -622,  -622,  -622,  -622,
    -622,  -622
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     578,   579,   714,    70,   475,   775,  1146,   585,   365,  1139,
    1141,   118,  1174,  1140,  1142,   475,   131,   125,    49,   441,
     375,   332,   442,   132,   133,   365,    50,   134,   558,   776,
     516,   275,    54,  1152,   135,    56,   286,   664,    71,   666,
     332,  1196,   136,    47,    48,  1197,   137,   138,    72,   125,
     517,  1258,   777,   139,   681,  1259,   778,   140,   141,   686,
     142,    61,   443,   549,  1262,   444,   143,    62,  1263,    65,
     697,   698,    66,   700,   456,   287,   275,   516,    69,  1325,
     124,  1326,   711,   712,   144,   145,   716,  1264,   288,   146,
     121,  1265,   705,   706,   366,  1327,   147,   517,   457,  1328,
     148,   149,   130,   126,   150,  1267,   549,   151,   152,  1268,
     289,   366,   290,   244,   291,   292,   245,   153,   445,   246,
      73,   458,   779,   154,   155,   459,   156,   157,   158,   159,
     160,    79,   293,   375,   484,   126,   446,   376,   333,   247,
    1279,   161,   282,    80,  1280,   559,   276,   707,   708,   780,
     162,   518,   163,   164,   285,   165,   476,   333,   166,   167,
     367,  1281,   168,    81,    82,  1282,  1175,   476,   781,    83,
    1176,    84,   377,   169,  1318,   330,   277,   367,  1319,   621,
     550,   622,   519,   806,   623,   485,   248,   558,   477,   592,
    1320,   276,  1147,   331,  1321,   170,   303,   171,   518,   477,
     338,   172,   624,   625,   378,   173,   174,   175,   176,   177,
     593,   594,   560,   178,   179,   486,   337,   595,   460,  1153,
     487,   277,   180,   550,    85,    86,   626,   461,   462,   519,
     627,   304,  1323,    87,    88,   363,  1324,   484,   782,   249,
     250,   251,   252,   253,   254,   255,   256,   551,   339,   303,
     376,   340,   478,   783,    89,    90,   181,   182,   343,   183,
     628,   463,   629,   478,   341,   184,  1061,   447,   364,   654,
     185,    91,    92,   344,   630,   186,   744,   439,   305,   775,
     728,   661,    93,   488,   304,   377,   257,   345,   485,   830,
     551,    94,   513,   596,   597,   598,   631,   532,   599,    70,
     346,   566,   441,   776,   559,   442,   600,   993,   994,   995,
     373,   552,  1329,   306,   347,   307,   308,   378,   486,   601,
     602,   258,   464,   487,   825,  1339,   777,   348,   632,  1340,
     778,   305,  1081,  1082,    71,   739,   603,   604,   798,  1359,
    1117,  1118,   633,  1360,    72,   443,   349,   350,   444,  1097,
    1098,  1099,  1100,  1101,   552,   634,   351,   352,   309,   353,
     310,   311,   354,   355,   605,   356,   306,   357,   307,   308,
     358,   560,  1143,  1144,  1145,  1006,   312,   359,  1269,   360,
     372,    95,    96,    97,   384,   385,   488,   386,   387,   388,
     573,   389,   361,   390,   515,   751,   779,   568,   391,   392,
     393,   445,   259,   394,   395,   396,   397,  1270,   398,   399,
     400,   309,   401,   310,   311,   402,    73,   403,   404,   446,
     313,   405,   713,   780,  1271,   406,   407,   408,   409,   312,
     131,  1272,   410,   248,   635,   411,   412,   132,   133,   260,
     893,   134,   781,   413,   414,  1114,   416,   508,   135,  1273,
     876,   314,   315,   418,   419,   420,   136,   547,   421,   569,
     137,   138,   422,   423,   424,   425,   426,   139,   427,   428,
     429,   140,   141,   313,   142,   430,   431,  1274,   432,   433,
     143,   434,   435,   436,   437,  1275,   249,   250,   251,   252,
     253,   254,   255,   256,   438,   495,   496,   497,   144,   145,
     510,   498,   499,   146,   314,   315,   500,   501,   502,   503,
     147,   456,   782,   504,   148,   149,   505,  1104,   150,   506,
    1341,   151,   152,   507,   511,  1112,  1113,   783,  1276,   512,
     525,   153,   526,   257,   527,   457,   528,   154,   155,   577,
     156,   157,   158,   159,   160,   529,   530,  1277,   531,   534,
     447,   621,  1342,   622,   535,   161,   623,   570,   458,   536,
     537,   538,   459,  1343,   162,   286,   163,   164,   258,   165,
     539,   540,   166,   167,   624,   625,   168,   541,   543,  1344,
     544,   842,   843,   844,   845,   846,  1345,   169,   545,   546,
     565,  1346,   571,  1347,   572,   574,   575,   576,   626,   577,
     580,   591,   627,   581,   287,  1348,   582,   583,   584,   170,
     586,   171,   587,   588,   589,   172,   590,   288,   652,   173,
     174,   175,   176,   177,   653,   657,   656,   178,   179,   658,
     659,   663,   628,   665,   629,   667,   180,   668,  1349,   289,
     669,   290,   670,   291,   292,    79,   630,   671,   672,   259,
     673,   674,   675,   676,  1350,   460,   677,    80,   678,   679,
     680,   293,   683,   682,   461,   462,   684,   685,   631,   687,
     181,   182,  1351,   183,  1352,  1353,   688,    81,    82,   184,
     689,   690,   691,    83,   185,    84,   260,   692,   693,   186,
     761,   762,   763,   764,   765,   766,   767,   694,   463,   695,
     632,   696,   699,   592,   702,   701,   713,   715,   703,   704,
     721,  1199,   709,   710,   633,     2,     3,   717,  1214,   723,
       4,   718,   724,   719,   593,   594,   720,   634,   770,   753,
     754,   595,   726,   727,   730,   755,     5,   746,    85,    86,
       6,   731,  1354,     7,   732,   734,   735,    87,    88,   736,
       8,   737,   738,  1355,   741,   743,   756,   757,   748,   464,
     749,   750,   758,  1356,   759,     9,   760,   768,    89,    90,
     769,   772,   795,  1357,   773,   800,   801,    10,    11,   514,
      12,   771,   774,   802,   803,    91,    92,    13,   804,   796,
    1200,   794,   805,   807,   808,   809,    93,  1215,   797,   810,
     811,   812,   813,    14,   814,    94,   635,   596,   597,   598,
     815,   816,   599,    15,   817,    16,   818,   819,   820,   821,
     600,   832,  1201,   822,   824,   828,   827,   833,   834,  1216,
     835,   836,    17,   601,   602,   837,   838,  1202,  1181,   895,
     863,  1007,   896,   839,  1217,   899,   840,   841,   849,    18,
     603,   604,   850,   851,   864,   852,   853,  1203,  1204,   854,
     855,   900,   856,   857,  1218,  1219,  1205,  1206,  1207,  1208,
     858,   859,   865,  1220,  1221,  1222,  1223,  1009,   605,  1209,
    1010,   866,   867,   860,    19,   861,  1224,   862,  1013,   868,
     878,   869,   897,    20,    21,    95,    96,    97,    22,    23,
     934,   935,   936,   937,   938,   870,   939,   940,   898,   941,
     942,   943,  1121,  1016,   944,  1317,   871,  1028,   872,   873,
     874,   875,   879,   880,   945,   946,   947,   881,   948,   949,
     950,   882,   883,   951,   902,   885,   886,   952,   956,   957,
     958,   959,   960,   887,   961,   962,   888,   963,   964,   965,
     889,   890,   966,   891,   892,    24,   901,   903,   904,  1005,
     905,   906,   967,   968,   969,   907,   970,   971,   972,   908,
     909,   973,   910,   911,   912,   974,  1295,  1296,  1297,  1298,
    1299,   913,  1300,  1301,   914,  1302,  1303,  1304,   915,   916,
    1305,   917,   918,   919,   920,   921,   922,  1012,   923,   924,
    1306,  1307,  1308,   925,  1309,  1310,  1311,   926,   927,  1312,
     928,   929,   930,  1313,   931,   932,   933,   955,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,   991,   992,   998,  1015,   999,  1000,  1001,  1002,
    1003,  1004,  1017,  1011,  1018,  1008,  1019,  1014,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1063,  1064,
    1065,  1053,  1054,  1056,  1057,  1058,  1060,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1085,  1086,  1087,  1088,  1089,  1091,  1092,  1090,
    1093,  1095,  1094,  1096,  1102,  1103,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1115,  1116,  1119,  1120,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1150,  1151,  1156,  1157,  1160,  1158,  1136,  1159,  1164,
    1165,  1166,  1170,  1167,  1246,  1168,  1184,  1169,  1173,  1185,
    1179,  1187,  1180,  1188,  1189,  1191,  1283,  1182,  1192,  1186,
    1190,  1193,  1194,  1195,  1198,  1212,  1213,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1288,   548,
     342,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1285,  1286,  1287,
    1292,  1293,  1294,  1316,   509,  1062,  1337,  1367,  1366,  1365,
     877,  1335,  1284,  1334,  1361,   799,  1364,   826,  1362,   752,
     831,  1363,   894,   655,  1336,   374,  1331,   662,   440,  1261,
    1260,   729,   567,  1333,  1332,   362,     0,     0,   533,     0,
     740,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     745
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-622))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     348,   349,   432,     1,     1,     1,    11,   355,     1,   261,
     261,   151,    75,   265,   265,     1,     1,     1,   263,     1,
       1,     1,     4,     8,     9,     1,   263,    12,     1,    25,
       1,     1,   263,    11,    19,   263,     1,   385,    36,   387,
       1,   261,    27,   261,   262,   265,    31,    32,    46,     1,
      21,   261,    48,    38,   402,   265,    52,    42,    43,   407,
      45,   263,    44,     1,   261,    47,    51,   263,   265,   263,
     418,   419,   263,   421,     1,    40,     1,     1,   263,    10,
     263,    12,   430,   431,    69,    70,   434,   261,    53,    74,
     151,   265,   195,   196,    87,    26,    81,    21,    25,    30,
      85,    86,   263,    87,    89,   261,     1,    92,    93,   265,
      75,    87,    77,   263,    79,    80,   263,   102,   100,   263,
     118,    48,   118,   108,   109,    52,   111,   112,   113,   114,
     115,     1,    97,     1,     1,    87,   118,   118,   118,   263,
     261,   126,   151,    13,   265,   118,   116,   195,   196,   145,
     135,   122,   137,   138,   263,   140,   153,   118,   143,   144,
     153,   261,   147,    33,    34,   265,   229,   153,   164,    39,
     233,    41,   153,   158,   261,   263,   146,   153,   265,     1,
     118,     3,   153,   531,     6,    52,     1,     1,   185,     1,
     261,   116,   197,   263,   265,   180,     1,   182,   122,   185,
     264,   186,    24,    25,   185,   190,   191,   192,   193,   194,
      22,    23,   185,   198,   199,    82,   261,    29,   145,   197,
      87,   146,   207,   118,    94,    95,    48,   154,   155,   153,
      52,    36,   261,   103,   104,   263,   265,     1,   234,    54,
      55,    56,    57,    58,    59,    60,    61,   185,   264,     1,
     118,   264,   249,   249,   124,   125,   241,   242,   264,   244,
      82,   188,    84,   249,   262,   250,   262,   249,   263,   262,
     255,   141,   142,   264,    96,   260,   262,   262,    83,     1,
     262,   262,   152,   150,    36,   153,   101,   264,    52,   262,
     185,   161,   262,   105,   106,   107,   118,   262,   110,     1,
     264,   262,     1,    25,   118,     4,   118,    14,    15,    16,
     262,   249,   243,   118,   264,   120,   121,   185,    82,   131,
     132,   136,   249,    87,   262,   261,    48,   264,   150,   265,
      52,    83,   167,   168,    36,   262,   148,   149,   262,   261,
     214,   215,   164,   265,    46,    44,   264,   264,    47,   842,
     843,   844,   845,   846,   249,   177,   264,   264,   163,   264,
     165,   166,   264,   264,   176,   264,   118,   264,   120,   121,
     264,   185,   993,   994,   995,   723,   181,   264,    20,   264,
     264,   251,   252,   253,   264,   264,   150,   264,   264,   264,
     129,   264,   262,   264,   263,   262,   118,   151,   264,   264,
     264,   100,   217,   264,   264,   264,   264,    49,   264,   264,
     264,   163,   264,   165,   166,   264,   118,   264,   264,   118,
     225,   264,   129,   145,    66,   264,   264,   264,   264,   181,
       1,    73,   264,     1,   256,   264,   264,     8,     9,   254,
     262,    12,   164,   264,   264,   875,   264,   262,    19,    91,
     262,   256,   257,   264,   264,   264,    27,   262,   264,   151,
      31,    32,   264,   264,   264,   264,   264,    38,   264,   264,
     264,    42,    43,   225,    45,   264,   264,   119,   264,   264,
      51,   264,   264,   264,   264,   127,    54,    55,    56,    57,
      58,    59,    60,    61,   264,   261,   264,   264,    69,    70,
     261,   264,   264,    74,   256,   257,   264,   264,   264,   264,
      81,     1,   234,   264,    85,    86,   264,   865,    89,   264,
       5,    92,    93,   264,   264,   873,   874,   249,   170,   264,
     264,   102,   264,   101,   264,    25,   264,   108,   109,   129,
     111,   112,   113,   114,   115,   264,   264,   189,   264,   261,
     249,     1,    37,     3,   264,   126,     6,   151,    48,   264,
     264,   264,    52,    48,   135,     1,   137,   138,   136,   140,
     264,   264,   143,   144,    24,    25,   147,   264,   264,    64,
     264,   171,   172,   173,   174,   175,    71,   158,   264,   264,
     264,    76,   261,    78,   195,   129,   195,   195,    48,   129,
     129,   261,    52,   129,    40,    90,   195,   195,   129,   180,
     195,   182,   195,   195,   195,   186,   195,    53,   264,   190,
     191,   192,   193,   194,   264,   261,   151,   198,   199,   264,
     264,   195,    82,   195,    84,   129,   207,   151,   123,    75,
     129,    77,   195,    79,    80,     1,    96,   195,   129,   217,
     151,   195,   129,   129,   139,   145,   129,    13,   195,   195,
     195,    97,   195,   151,   154,   155,   129,   129,   118,   129,
     241,   242,   157,   244,   159,   160,   129,    33,    34,   250,
     151,   129,   129,    39,   255,    41,   254,   195,   195,   260,
     218,   219,   220,   221,   222,   223,   224,   264,   188,   195,
     150,   264,   195,     1,   195,   151,   129,   151,   195,   195,
     261,    90,   195,   195,   164,     0,     1,   195,    90,   264,
       5,   195,   264,   195,    22,    23,   195,   177,   195,   151,
     151,    29,   264,   264,   261,   151,    21,   261,    94,    95,
      25,   264,   227,    28,   264,   264,   264,   103,   104,   264,
      35,   264,   264,   238,   264,   264,   151,   151,   264,   249,
     264,   264,   151,   248,   151,    50,   151,   151,   124,   125,
     151,   151,   264,   258,   151,   195,   195,    62,    63,   278,
      65,   261,   261,   195,   151,   141,   142,    72,   195,   264,
     169,   261,   195,   261,   151,   195,   152,   169,   264,   151,
     151,   151,   151,    88,   151,   161,   256,   105,   106,   107,
     264,   151,   110,    98,   129,   100,   151,   151,   261,   261,
     118,   151,   201,   264,   264,   264,   261,   261,   261,   201,
     261,   261,   117,   131,   132,   261,   261,   216,   200,   151,
     264,   195,   151,   261,   216,   151,   261,   261,   261,   134,
     148,   149,   261,   261,   264,   261,   261,   236,   237,   261,
     261,   151,   261,   261,   236,   237,   245,   246,   247,   248,
     261,   261,   264,   245,   246,   247,   248,   151,   176,   258,
     151,   264,   264,   261,   169,   261,   258,   261,   195,   264,
     261,   264,   261,   178,   179,   251,   252,   253,   183,   184,
     202,   203,   204,   205,   206,   264,   208,   209,   261,   211,
     212,   213,   195,   129,   216,  1197,   264,   129,   264,   264,
     264,   264,   264,   264,   226,   227,   228,   264,   230,   231,
     232,   264,   264,   235,   261,   264,   264,   239,   202,   203,
     204,   205,   206,   264,   208,   209,   264,   211,   212,   213,
     264,   264,   216,   264,   264,   240,   264,   261,   261,   264,
     261,   261,   226,   227,   228,   261,   230,   231,   232,   261,
     261,   235,   261,   261,   261,   239,   202,   203,   204,   205,
     206,   261,   208,   209,   261,   211,   212,   213,   261,   261,
     216,   261,   261,   261,   261,   261,   261,   151,   261,   261,
     226,   227,   228,   261,   230,   231,   232,   261,   261,   235,
     261,   261,   261,   239,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   151,   261,   261,   261,   261,
     261,   261,   151,   261,   151,   264,   151,   264,   261,   151,
     264,   151,   261,   264,   151,   151,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   151,   151,
     151,   264,   264,   264,   264,   264,   264,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   151,   151,   261,   264,
     151,   261,   264,   261,   129,   129,   129,   129,   129,   129,
     151,   129,   129,   261,   151,   151,   151,   264,   151,   151,
     151,   151,   129,   151,   151,   151,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   128,   261,   156,   261,   261,
     261,   261,   156,   261,   128,   261,   151,   261,   261,   195,
     261,   151,   261,   151,   151,   151,   129,   265,   261,   264,
     264,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   128,   316,
      74,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   784,  1282,  1360,  1340,  1338,
     606,  1268,  1182,  1266,  1319,   520,  1324,   553,  1321,   490,
     561,  1322,   636,   368,  1280,   127,  1259,   380,   187,  1142,
    1140,   448,   334,  1265,  1263,    98,    -1,    -1,   294,    -1,
     465,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   267,     0,     1,     5,    21,    25,    28,    35,    50,
      62,    63,    65,    72,    88,    98,   100,   117,   134,   169,
     178,   179,   183,   184,   240,   268,   273,   278,   296,   302,
     317,   340,   359,   373,   391,   398,   402,   412,   421,   447,
     457,   463,   467,   477,   541,   557,   578,   261,   262,   263,
     263,   341,   422,   458,   263,   468,   263,   542,   374,   448,
     360,   263,   263,   318,   392,   263,   263,   403,   413,   263,
       1,    36,    46,   118,   297,   298,   299,   300,   301,     1,
      13,    33,    34,    39,    41,    94,    95,   103,   104,   124,
     125,   141,   142,   152,   161,   251,   252,   253,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   151,   342,
     346,   151,   423,   427,   263,     1,    87,   464,   465,   466,
     263,     1,     8,     9,    12,    19,    27,    31,    32,    38,
      42,    43,    45,    51,    69,    70,    74,    81,    85,    86,
      89,    92,    93,   102,   108,   109,   111,   112,   113,   114,
     115,   126,   135,   137,   138,   140,   143,   144,   147,   158,
     180,   182,   186,   190,   191,   192,   193,   194,   198,   199,
     207,   241,   242,   244,   250,   255,   260,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   533,
     537,   538,   539,   540,   263,   263,   263,   263,     1,    54,
      55,    56,    57,    58,    59,    60,    61,   101,   136,   217,
     254,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,     1,   116,   146,   274,   275,
     276,   277,   151,   319,   323,   263,     1,    40,    53,    75,
      77,    79,    80,    97,   579,   580,   581,   582,   583,   584,
     585,   586,   587,     1,    36,    83,   118,   120,   121,   163,
     165,   166,   181,   225,   256,   257,   279,   280,   281,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     263,   263,     1,   118,   399,   400,   401,   261,   264,   264,
     264,   262,   298,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   559,   263,   263,     1,    87,   153,   459,   460,
     461,   462,   264,   262,   465,     1,   118,   153,   185,   469,
     473,   474,   475,   476,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   534,   264,   530,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   262,
     479,     1,     4,    44,    47,   100,   118,   249,   543,   544,
     545,   546,   547,   551,   552,   553,     1,    25,    48,    52,
     145,   154,   155,   188,   249,   375,   376,   377,   378,   379,
     380,   381,   388,   389,   390,     1,   153,   185,   249,   449,
     453,   454,   455,   456,     1,    52,    82,    87,   150,   361,
     365,   366,   367,   371,   372,   261,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   262,   304,
     261,   264,   264,   262,   275,   263,     1,    21,   122,   153,
     393,   394,   395,   396,   397,   264,   264,   264,   264,   264,
     264,   264,   262,   580,   261,   264,   264,   264,   264,   264,
     264,   264,   282,   264,   264,   264,   264,   262,   280,     1,
     118,   185,   249,   404,   405,   406,   407,   408,     1,   118,
     185,   414,   415,   416,   417,   264,   262,   400,   151,   151,
     151,   261,   195,   129,   129,   195,   195,   129,   270,   270,
     129,   129,   195,   195,   129,   270,   195,   195,   195,   195,
     195,   261,     1,    22,    23,    29,   105,   106,   107,   110,
     118,   131,   132,   148,   149,   176,   343,   344,   345,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,     1,     3,     6,    24,    25,    48,    52,    82,    84,
      96,   118,   150,   164,   177,   256,   424,   425,   426,   428,
     429,   430,   431,   432,   433,   434,   441,   442,   443,   444,
     445,   446,   264,   264,   262,   460,   151,   261,   264,   264,
     470,   262,   474,   195,   270,   195,   270,   129,   151,   129,
     195,   195,   129,   151,   195,   129,   129,   129,   195,   195,
     195,   270,   151,   195,   129,   129,   270,   129,   129,   151,
     129,   129,   195,   195,   264,   195,   264,   270,   270,   195,
     270,   151,   195,   195,   195,   195,   196,   195,   196,   195,
     195,   270,   270,   129,   272,   151,   270,   195,   195,   195,
     195,   261,   554,   264,   264,   548,   264,   264,   262,   544,
     261,   264,   264,   382,   264,   264,   264,   264,   264,   262,
     376,   264,   450,   264,   262,   454,   261,   362,   264,   264,
     264,   262,   366,   151,   151,   151,   151,   151,   151,   151,
     151,   218,   219,   220,   221,   222,   223,   224,   151,   151,
     195,   261,   151,   151,   261,     1,    25,    48,    52,   118,
     145,   164,   234,   249,   320,   321,   322,   324,   325,   326,
     327,   328,   329,   333,   261,   264,   264,   264,   262,   394,
     195,   195,   195,   151,   195,   195,   270,   261,   151,   195,
     151,   151,   151,   151,   151,   264,   151,   129,   151,   151,
     261,   261,   264,   409,   264,   262,   405,   261,   264,   418,
     262,   415,   151,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   171,   172,   173,   174,   175,   269,   270,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   262,   344,   261,   264,
     264,   264,   264,   264,   435,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   425,   151,   151,   261,   261,   151,
     151,   264,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   202,   203,   204,   205,   206,   208,
     209,   211,   212,   213,   216,   226,   227,   228,   230,   231,
     232,   235,   239,   535,   536,   261,   202,   203,   204,   205,
     206,   208,   209,   211,   212,   213,   216,   226,   227,   228,
     230,   231,   232,   235,   239,   531,   532,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,    14,    15,    16,   271,   272,   261,   261,
     261,   261,   261,   261,   261,   264,   270,   195,   264,   151,
     151,   261,   151,   195,   264,   151,   129,   151,   151,   151,
     261,   151,   264,   151,   261,   264,   151,   151,   129,   369,
     370,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   264,   264,   334,   264,   264,   264,   330,
     264,   262,   321,   151,   151,   151,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   167,   168,   283,   284,   261,   261,   261,   261,   151,
     264,   151,   261,   151,   264,   261,   261,   269,   269,   269,
     269,   269,   129,   129,   270,   129,   129,   129,   129,   151,
     129,   129,   270,   270,   272,   261,   151,   214,   215,   151,
     151,   195,   264,   151,   151,   151,   151,   129,   151,   151,
     151,   261,   261,   261,   261,   261,   156,   471,   472,   261,
     265,   261,   265,   271,   271,   271,    11,   197,   555,   556,
     261,   261,    11,   197,   549,   550,   261,   261,   261,   261,
     128,   383,   384,   386,   261,   261,   261,   261,   261,   261,
     156,   451,   452,   261,    75,   229,   233,   363,   364,   261,
     261,   200,   265,   368,   151,   195,   264,   151,   151,   151,
     264,   151,   261,   261,   261,   261,   261,   265,   261,    90,
     169,   201,   216,   236,   237,   245,   246,   247,   248,   258,
     410,   411,   261,   261,    90,   169,   201,   216,   236,   237,
     245,   246,   247,   248,   258,   419,   420,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   128,   436,   437,   439,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   265,
     536,   532,   261,   265,   261,   265,   385,   261,   265,    20,
      49,    66,    73,    91,   119,   127,   170,   189,   387,   261,
     265,   261,   265,   129,   370,   261,   261,   261,   128,   335,
     336,   338,   261,   261,   261,   202,   203,   204,   205,   206,
     208,   209,   211,   212,   213,   216,   226,   227,   228,   230,
     231,   232,   235,   239,   331,   332,   261,   284,   261,   265,
     261,   265,   438,   261,   265,    10,    12,    26,    30,   243,
     440,   472,   556,   550,   387,   384,   452,   364,   337,   261,
     265,     5,    37,    48,    64,    71,    76,    78,    90,   123,
     139,   157,   159,   160,   227,   238,   248,   258,   339,   261,
     265,   411,   420,   440,   437,   339,   336,   332
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
#line 425 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 447 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 470 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 476 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 496 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 502 "ircd_parser.y"
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
#line 516 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 522 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 530 "ircd_parser.y"
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
#line 564 "ircd_parser.y"
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
#line 624 "ircd_parser.y"
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
#line 639 "ircd_parser.y"
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
#line 654 "ircd_parser.y"
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
#line 663 "ircd_parser.y"
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
#line 677 "ircd_parser.y"
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
#line 686 "ircd_parser.y"
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
#line 714 "ircd_parser.y"
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
#line 744 "ircd_parser.y"
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
#line 767 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 782 "ircd_parser.y"
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
#line 791 "ircd_parser.y"
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
#line 800 "ircd_parser.y"
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
#line 827 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 831 "ircd_parser.y"
    {
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 835 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 842 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 849 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 856 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 863 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 870 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 877 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 884 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 891 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 895 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 899 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 903 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 907 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 915 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 921 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 930 "ircd_parser.y"
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
#line 943 "ircd_parser.y"
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
#line 1030 "ircd_parser.y"
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
#line 1042 "ircd_parser.y"
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
#line 1054 "ircd_parser.y"
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
#line 1088 "ircd_parser.y"
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
#line 1100 "ircd_parser.y"
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
#line 1111 "ircd_parser.y"
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
#line 1153 "ircd_parser.y"
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
#line 1162 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1169 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1173 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1177 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1181 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1189 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1193 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1197 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1201 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1205 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1209 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1213 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1221 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1225 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1233 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1237 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1241 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1247 "ircd_parser.y"
    {
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1251 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1252 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1255 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1262 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1276 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1283 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1290 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1297 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1304 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1311 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1318 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1325 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1332 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1339 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLOBOPS;
    else yy_aconf->port |= OPER_FLAG_GLOBOPS;
  }
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1346 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1353 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1360 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1367 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1380 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1387 "ircd_parser.y"
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

  case 216:

/* Line 1806 of yacc.c  */
#line 1447 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1483 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1489 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1495 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1501 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1513 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1519 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1525 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1531 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1540 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1547 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1556 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1562 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1566 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1570 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1580 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1585 "ircd_parser.y"
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

  case 251:

/* Line 1806 of yacc.c  */
#line 1599 "ircd_parser.y"
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

  case 252:

/* Line 1806 of yacc.c  */
#line 1619 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 253:

/* Line 1806 of yacc.c  */
#line 1628 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 254:

/* Line 1806 of yacc.c  */
#line 1640 "ircd_parser.y"
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

  case 255:

/* Line 1806 of yacc.c  */
#line 1652 "ircd_parser.y"
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

  case 267:

/* Line 1806 of yacc.c  */
#line 1714 "ircd_parser.y"
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

  case 268:

/* Line 1806 of yacc.c  */
#line 1751 "ircd_parser.y"
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

  case 269:

/* Line 1806 of yacc.c  */
#line 1764 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1773 "ircd_parser.y"
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

  case 271:

/* Line 1806 of yacc.c  */
#line 1784 "ircd_parser.y"
    {
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1788 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1789 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1792 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1799 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1806 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1813 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1820 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1827 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1834 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1841 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1848 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1858 "ircd_parser.y"
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

  case 289:

/* Line 1806 of yacc.c  */
#line 1877 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1887 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1900 "ircd_parser.y"
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
#line 1907 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1928 "ircd_parser.y"
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

  case 301:

/* Line 1806 of yacc.c  */
#line 1943 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1961 "ircd_parser.y"
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

  case 308:

/* Line 1806 of yacc.c  */
#line 1976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1984 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1995 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 2004 "ircd_parser.y"
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

  case 318:

/* Line 1806 of yacc.c  */
#line 2026 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2033 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2037 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2041 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2045 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2049 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2053 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2057 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 2061 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 2065 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 2069 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2073 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2082 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2089 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2102 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2108 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2127 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 2139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 2143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 2147 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 2151 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 2155 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 2164 "ircd_parser.y"
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

  case 357:

/* Line 1806 of yacc.c  */
#line 2182 "ircd_parser.y"
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

  case 377:

/* Line 1806 of yacc.c  */
#line 2320 "ircd_parser.y"
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

  case 378:

/* Line 1806 of yacc.c  */
#line 2332 "ircd_parser.y"
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

  case 379:

/* Line 1806 of yacc.c  */
#line 2344 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2353 "ircd_parser.y"
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

  case 381:

/* Line 1806 of yacc.c  */
#line 2379 "ircd_parser.y"
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

  case 382:

/* Line 1806 of yacc.c  */
#line 2397 "ircd_parser.y"
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

  case 383:

/* Line 1806 of yacc.c  */
#line 2415 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2421 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2425 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2433 "ircd_parser.y"
    {
}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 2437 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2438 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 2441 "ircd_parser.y"
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

  case 395:

/* Line 1806 of yacc.c  */
#line 2452 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 2459 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2466 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2473 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 2483 "ircd_parser.y"
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

  case 400:

/* Line 1806 of yacc.c  */
#line 2524 "ircd_parser.y"
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

  case 401:

/* Line 1806 of yacc.c  */
#line 2535 "ircd_parser.y"
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

  case 402:

/* Line 1806 of yacc.c  */
#line 2548 "ircd_parser.y"
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

  case 403:

/* Line 1806 of yacc.c  */
#line 2561 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 2570 "ircd_parser.y"
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

  case 405:

/* Line 1806 of yacc.c  */
#line 2605 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 2612 "ircd_parser.y"
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

  case 407:

/* Line 1806 of yacc.c  */
#line 2668 "ircd_parser.y"
    {
}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 2673 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 2682 "ircd_parser.y"
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

  case 419:

/* Line 1806 of yacc.c  */
#line 2701 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 2710 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2714 "ircd_parser.y"
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

  case 427:

/* Line 1806 of yacc.c  */
#line 2736 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 2742 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 2756 "ircd_parser.y"
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

  case 435:

/* Line 1806 of yacc.c  */
#line 2774 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 436:

/* Line 1806 of yacc.c  */
#line 2781 "ircd_parser.y"
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

  case 437:

/* Line 1806 of yacc.c  */
#line 2821 "ircd_parser.y"
    {
}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 2826 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 2835 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 2841 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2886 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2891 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2896 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2901 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2906 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2911 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2916 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2921 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2926 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2931 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2941 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2946 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2951 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2956 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2961 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2966 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2971 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2982 "ircd_parser.y"
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

  case 529:

/* Line 1806 of yacc.c  */
#line 2993 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2998 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3007 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3012 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3017 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3022 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3027 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 3032 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 3035 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3043 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3048 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3053 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3058 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3063 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3068 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3073 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3083 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3088 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3099 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3104 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3109 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3118 "ircd_parser.y"
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

  case 553:

/* Line 1806 of yacc.c  */
#line 3150 "ircd_parser.y"
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

  case 554:

/* Line 1806 of yacc.c  */
#line 3168 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3173 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3191 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3196 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3201 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3206 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3212 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3215 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3218 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3224 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3227 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3233 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3242 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3248 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3266 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3271 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3277 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3280 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3283 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3286 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3289 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3292 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3295 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3301 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3304 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3307 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3316 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3319 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3325 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3328 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3331 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3336 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3341 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3346 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 3351 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 3360 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 3367 "ircd_parser.y"
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

  case 621:

/* Line 1806 of yacc.c  */
#line 3393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 3399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 3405 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 3411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 3415 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 3421 "ircd_parser.y"
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

  case 630:

/* Line 1806 of yacc.c  */
#line 3455 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 3464 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 3468 "ircd_parser.y"
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

  case 635:

/* Line 1806 of yacc.c  */
#line 3515 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3519 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3543 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3548 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3553 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3558 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3563 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3568 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3573 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3578 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3583 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3588 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3593 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3598 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 671:

/* Line 1806 of yacc.c  */
#line 3603 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 3608 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 3613 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 3618 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 3623 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 3628 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 3647 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 689:

/* Line 1806 of yacc.c  */
#line 3653 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 690:

/* Line 1806 of yacc.c  */
#line 3659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 3668 "ircd_parser.y"
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

  case 692:

/* Line 1806 of yacc.c  */
#line 3682 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 3688 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 694:

/* Line 1806 of yacc.c  */
#line 3694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 8111 "ircd_parser.c"
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



