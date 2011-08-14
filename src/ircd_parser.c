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
     T_WALLOP = 493,
     T_SERVICE = 494,
     T_SERVICES_NAME = 495,
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
#define T_WALLOP 493
#define T_SERVICE 494
#define T_SERVICES_NAME 495
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 739 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 751 "ircd_parser.c"

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
#define YYLAST   1318

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  322
/* YYNRULES -- Number of rules.  */
#define YYNRULES  693
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1367

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
     563,   565,   567,   569,   571,   573,   574,   582,   583,   585,
     588,   590,   592,   594,   596,   598,   600,   602,   604,   606,
     608,   610,   612,   614,   616,   619,   624,   626,   631,   636,
     641,   646,   651,   656,   661,   666,   671,   676,   681,   686,
     687,   694,   695,   701,   705,   707,   709,   711,   713,   716,
     718,   720,   722,   724,   726,   729,   730,   736,   740,   742,
     744,   748,   753,   758,   759,   766,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   790,   795,   800,   805,
     810,   811,   817,   821,   823,   824,   828,   829,   832,   834,
     836,   838,   840,   842,   844,   846,   848,   850,   855,   860,
     865,   866,   873,   876,   878,   880,   882,   884,   887,   892,
     897,   902,   908,   911,   913,   915,   917,   922,   923,   930,
     933,   935,   937,   939,   941,   944,   949,   954,   955,   961,
     965,   967,   969,   971,   973,   975,   977,   979,   981,   983,
     985,   987,   989,   990,   997,  1000,  1002,  1004,  1006,  1009,
    1014,  1015,  1021,  1025,  1027,  1029,  1031,  1033,  1035,  1037,
    1039,  1041,  1043,  1045,  1047,  1049,  1050,  1058,  1059,  1061,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1097,  1102,  1104,  1109,
    1114,  1119,  1124,  1129,  1134,  1139,  1140,  1146,  1150,  1152,
    1153,  1157,  1158,  1161,  1163,  1165,  1167,  1169,  1171,  1176,
    1181,  1186,  1191,  1196,  1201,  1202,  1209,  1210,  1216,  1220,
    1222,  1224,  1227,  1229,  1231,  1233,  1235,  1237,  1242,  1247,
    1248,  1255,  1258,  1260,  1262,  1264,  1266,  1271,  1276,  1282,
    1285,  1287,  1289,  1291,  1296,  1297,  1304,  1305,  1311,  1315,
    1317,  1319,  1322,  1324,  1326,  1328,  1330,  1332,  1337,  1342,
    1348,  1351,  1353,  1355,  1357,  1359,  1361,  1363,  1365,  1367,
    1369,  1371,  1373,  1375,  1377,  1379,  1381,  1383,  1385,  1387,
    1389,  1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,  1407,
    1409,  1411,  1413,  1415,  1417,  1419,  1421,  1423,  1425,  1427,
    1429,  1431,  1433,  1435,  1437,  1439,  1441,  1443,  1445,  1447,
    1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,  1465,  1470,
    1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,  1515,  1520,
    1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,  1565,  1570,
    1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,  1615,  1620,
    1625,  1630,  1635,  1640,  1645,  1650,  1655,  1660,  1665,  1670,
    1675,  1680,  1685,  1690,  1695,  1700,  1705,  1710,  1715,  1720,
    1721,  1727,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,
    1747,  1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,
    1767,  1769,  1771,  1772,  1778,  1782,  1784,  1786,  1788,  1790,
    1792,  1794,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1810,
    1812,  1814,  1816,  1818,  1820,  1822,  1827,  1832,  1837,  1842,
    1843,  1850,  1853,  1855,  1857,  1859,  1861,  1863,  1865,  1867,
    1869,  1874,  1879,  1880,  1886,  1890,  1892,  1894,  1896,  1901,
    1906,  1907,  1913,  1917,  1919,  1921,  1923,  1929,  1932,  1934,
    1936,  1938,  1940,  1942,  1944,  1946,  1948,  1950,  1952,  1954,
    1956,  1958,  1960,  1962,  1964,  1966,  1968,  1970,  1972,  1977,
    1982,  1987,  1992,  1997,  2002,  2007,  2012,  2017,  2022,  2027,
    2032,  2037,  2042,  2047,  2052,  2057,  2062,  2068,  2071,  2073,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2094,  2099,
    2104,  2109,  2114,  2119
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     266,     0,    -1,    -1,   266,   267,    -1,   295,    -1,   301,
      -1,   316,    -1,   556,    -1,   339,    -1,   358,    -1,   372,
      -1,   277,    -1,   577,    -1,   390,    -1,   397,    -1,   401,
      -1,   411,    -1,   420,    -1,   446,    -1,   456,    -1,   462,
      -1,   476,    -1,   540,    -1,   466,    -1,   272,    -1,     1,
     260,    -1,     1,   261,    -1,    -1,   269,    -1,   129,   268,
      -1,   129,   171,   268,    -1,   129,   172,   268,    -1,   129,
     173,   268,    -1,   129,   174,   268,    -1,   129,   175,   268,
      -1,    -1,   271,    -1,   129,   270,    -1,   129,    14,   270,
      -1,   129,    15,   270,    -1,   129,    16,   270,    -1,   117,
     262,   273,   261,   260,    -1,   273,   274,    -1,   274,    -1,
     275,    -1,   276,    -1,     1,   260,    -1,   116,   263,   151,
     260,    -1,   146,   263,   151,   260,    -1,   179,   262,   278,
     261,   260,    -1,   278,   279,    -1,   279,    -1,   286,    -1,
     291,    -1,   294,    -1,   288,    -1,   289,    -1,   290,    -1,
     293,    -1,   285,    -1,   292,    -1,   287,    -1,   284,    -1,
     280,    -1,     1,   260,    -1,    -1,   166,   281,   263,   282,
     260,    -1,   282,   264,   283,    -1,   283,    -1,   167,    -1,
     168,    -1,   165,   263,   151,   260,    -1,   163,   263,   151,
     260,    -1,   118,   263,   151,   260,    -1,   181,   263,   151,
     260,    -1,    36,   263,   151,   260,    -1,   121,   263,   151,
     260,    -1,   120,   263,   151,   260,    -1,   255,   263,   151,
     260,    -1,   256,   263,   151,   260,    -1,   225,   263,   129,
     260,    -1,    83,   263,   195,   260,    -1,     5,   262,   296,
     261,   260,    -1,   296,   297,    -1,   297,    -1,   298,    -1,
     300,    -1,   299,    -1,     1,   260,    -1,   118,   263,   151,
     260,    -1,    46,   263,   151,   260,    -1,    36,   263,   151,
     260,    -1,   100,   262,   302,   261,   260,    -1,   302,   303,
      -1,   303,    -1,   304,    -1,   305,    -1,   314,    -1,   315,
      -1,   306,    -1,   308,    -1,   310,    -1,   311,    -1,   313,
      -1,   309,    -1,   312,    -1,   307,    -1,     1,   260,    -1,
     217,   263,   151,   260,    -1,   136,   263,   151,   260,    -1,
      61,   263,   151,   260,    -1,    54,   263,   151,   260,    -1,
      59,   263,   151,   260,    -1,    60,   263,   151,   260,    -1,
      57,   263,   151,   260,    -1,    56,   263,   151,   260,    -1,
      58,   263,   151,   260,    -1,    55,   263,   151,   260,    -1,
     101,   263,   218,   260,    -1,   101,   263,   220,   260,    -1,
     101,   263,   224,   260,    -1,   101,   263,   222,   260,    -1,
     101,   263,   223,   260,    -1,   101,   263,   221,   260,    -1,
     101,   263,   219,   260,    -1,   253,   263,   195,   260,    -1,
      -1,   134,   317,   318,   262,   319,   261,   260,    -1,    -1,
     322,    -1,   319,   320,    -1,   320,    -1,   321,    -1,   323,
      -1,   324,    -1,   328,    -1,   327,    -1,   325,    -1,   326,
      -1,   332,    -1,     1,   260,    -1,   118,   263,   151,   260,
      -1,   151,    -1,   248,   263,   151,   260,    -1,   145,   263,
     151,   260,    -1,    48,   263,   195,   260,    -1,   164,   263,
     151,   260,    -1,    25,   263,   151,   260,    -1,    -1,   234,
     329,   263,   330,   260,    -1,   330,   264,   331,    -1,   331,
      -1,   202,    -1,   205,    -1,   206,    -1,   208,    -1,   209,
      -1,   212,    -1,   231,    -1,   226,    -1,   228,    -1,   235,
      -1,   232,    -1,   211,    -1,   227,    -1,   230,    -1,   213,
      -1,   238,    -1,   203,    -1,   204,    -1,   216,    -1,    -1,
      52,   333,   263,   334,   260,    -1,   334,   264,   335,    -1,
     335,    -1,    -1,   128,   336,   338,    -1,    -1,   337,   338,
      -1,    71,    -1,   159,    -1,    90,    -1,   247,    -1,   257,
      -1,    64,    -1,    37,    -1,   157,    -1,     5,    -1,    76,
      -1,   123,    -1,   227,    -1,   139,    -1,    78,    -1,   160,
      -1,    48,    -1,    -1,    25,   340,   341,   262,   342,   261,
     260,    -1,    -1,   345,    -1,   342,   343,    -1,   343,    -1,
     344,    -1,   355,    -1,   356,    -1,   346,    -1,   347,    -1,
     357,    -1,   348,    -1,   349,    -1,   350,    -1,   351,    -1,
     352,    -1,   353,    -1,   354,    -1,     1,   260,    -1,   118,
     263,   151,   260,    -1,   151,    -1,   148,   263,   269,   260,
      -1,   149,   263,   269,   260,    -1,   132,   263,   129,   260,
      -1,    29,   263,   269,   260,    -1,   110,   263,   129,   260,
      -1,   105,   263,   129,   260,    -1,   107,   263,   129,   260,
      -1,   106,   263,   129,   260,    -1,   176,   263,   271,   260,
      -1,    22,   263,   129,   260,    -1,    23,   263,   129,   260,
      -1,   131,   263,   129,   260,    -1,    -1,    98,   359,   262,
     364,   261,   260,    -1,    -1,    52,   361,   263,   362,   260,
      -1,   362,   264,   363,    -1,   363,    -1,   233,    -1,    75,
      -1,   229,    -1,   364,   365,    -1,   365,    -1,   366,    -1,
     360,    -1,   370,    -1,   371,    -1,     1,   260,    -1,    -1,
     150,   263,   368,   367,   260,    -1,   368,   264,   369,    -1,
     369,    -1,   129,    -1,   129,   200,   129,    -1,    87,   263,
     151,   260,    -1,    82,   263,   151,   260,    -1,    -1,    72,
     373,   262,   374,   261,   260,    -1,   374,   375,    -1,   375,
      -1,   376,    -1,   377,    -1,   378,    -1,   380,    -1,   387,
      -1,   388,    -1,   389,    -1,   379,    -1,     1,   260,    -1,
     248,   263,   151,   260,    -1,   145,   263,   151,   260,    -1,
      25,   263,   151,   260,    -1,    48,   263,   195,   260,    -1,
      -1,    52,   381,   263,   382,   260,    -1,   382,   264,   383,
      -1,   383,    -1,    -1,   128,   384,   386,    -1,    -1,   385,
     386,    -1,   189,    -1,    49,    -1,    91,    -1,    73,    -1,
      20,    -1,   127,    -1,    66,    -1,   170,    -1,   119,    -1,
     188,   263,   151,   260,    -1,   155,   263,   151,   260,    -1,
     154,   263,   129,   260,    -1,    -1,   169,   391,   262,   392,
     261,   260,    -1,   392,   393,    -1,   393,    -1,   394,    -1,
     395,    -1,   396,    -1,     1,   260,    -1,   153,   263,   151,
     260,    -1,    21,   263,   151,   260,    -1,   122,   263,   151,
     260,    -1,   239,   262,   398,   261,   260,    -1,   398,   399,
      -1,   399,    -1,   400,    -1,     1,    -1,   118,   263,   151,
     260,    -1,    -1,   183,   402,   262,   403,   261,   260,    -1,
     403,   404,    -1,   404,    -1,   405,    -1,   406,    -1,   407,
      -1,     1,   260,    -1,   118,   263,   151,   260,    -1,   248,
     263,   151,   260,    -1,    -1,   185,   408,   263,   409,   260,
      -1,   409,   264,   410,    -1,   410,    -1,    90,    -1,   244,
      -1,   247,    -1,   257,    -1,   245,    -1,   237,    -1,   169,
      -1,   246,    -1,   236,    -1,   216,    -1,   201,    -1,    -1,
     184,   412,   262,   413,   261,   260,    -1,   413,   414,    -1,
     414,    -1,   415,    -1,   416,    -1,     1,   260,    -1,   118,
     263,   151,   260,    -1,    -1,   185,   417,   263,   418,   260,
      -1,   418,   264,   419,    -1,   419,    -1,    90,    -1,   244,
      -1,   247,    -1,   257,    -1,   245,    -1,   237,    -1,   169,
      -1,   246,    -1,   236,    -1,   216,    -1,   201,    -1,    -1,
      28,   421,   422,   262,   423,   261,   260,    -1,    -1,   426,
      -1,   423,   424,    -1,   424,    -1,   425,    -1,   427,    -1,
     428,    -1,   429,    -1,   430,    -1,   432,    -1,   431,    -1,
     433,    -1,   442,    -1,   443,    -1,   444,    -1,   441,    -1,
     440,    -1,   445,    -1,     1,   260,    -1,   118,   263,   151,
     260,    -1,   151,    -1,    82,   263,   151,   260,    -1,   255,
     263,   151,   260,    -1,   177,   263,   151,   260,    -1,     3,
     263,   151,   260,    -1,   150,   263,   129,   260,    -1,     6,
     263,   214,   260,    -1,     6,   263,   215,   260,    -1,    -1,
      52,   434,   263,   435,   260,    -1,   435,   264,   436,    -1,
     436,    -1,    -1,   128,   437,   439,    -1,    -1,   438,   439,
      -1,    26,    -1,    30,    -1,    10,    -1,    12,    -1,   242,
      -1,   164,   263,   151,   260,    -1,    48,   263,   195,   260,
      -1,    84,   263,   151,   260,    -1,    96,   263,   151,   260,
      -1,    25,   263,   151,   260,    -1,    24,   263,   151,   260,
      -1,    -1,    88,   447,   262,   452,   261,   260,    -1,    -1,
     185,   449,   263,   450,   260,    -1,   450,   264,   451,    -1,
     451,    -1,   156,    -1,   452,   453,    -1,   453,    -1,   454,
      -1,   455,    -1,   448,    -1,     1,    -1,   248,   263,   151,
     260,    -1,   153,   263,   151,   260,    -1,    -1,    35,   457,
     262,   458,   261,   260,    -1,   458,   459,    -1,   459,    -1,
     460,    -1,   461,    -1,     1,    -1,    87,   263,   151,   260,
      -1,   153,   263,   151,   260,    -1,    50,   262,   463,   261,
     260,    -1,   463,   464,    -1,   464,    -1,   465,    -1,     1,
      -1,    87,   263,   151,   260,    -1,    -1,    62,   467,   262,
     472,   261,   260,    -1,    -1,   185,   469,   263,   470,   260,
      -1,   470,   264,   471,    -1,   471,    -1,   156,    -1,   472,
     473,    -1,   473,    -1,   474,    -1,   475,    -1,   468,    -1,
       1,    -1,   118,   263,   151,   260,    -1,   153,   263,   151,
     260,    -1,    63,   262,   477,   261,   260,    -1,   477,   478,
      -1,   478,    -1,   487,    -1,   488,    -1,   490,    -1,   491,
      -1,   492,    -1,   493,    -1,   494,    -1,   495,    -1,   496,
      -1,   497,    -1,   486,    -1,   499,    -1,   500,    -1,   501,
      -1,   502,    -1,   517,    -1,   504,    -1,   506,    -1,   508,
      -1,   507,    -1,   511,    -1,   505,    -1,   512,    -1,   513,
      -1,   514,    -1,   515,    -1,   516,    -1,   532,    -1,   518,
      -1,   522,    -1,   523,    -1,   528,    -1,   509,    -1,   510,
      -1,   538,    -1,   536,    -1,   537,    -1,   519,    -1,   489,
      -1,   520,    -1,   521,    -1,   539,    -1,   527,    -1,   498,
      -1,   525,    -1,   526,    -1,   482,    -1,   485,    -1,   480,
      -1,   481,    -1,   483,    -1,   484,    -1,   503,    -1,   479,
      -1,   524,    -1,     1,    -1,   112,   263,   129,   260,    -1,
      69,   263,   129,   260,    -1,    70,   263,   129,   260,    -1,
      12,   263,   195,   260,    -1,   254,   263,   195,   260,    -1,
     158,   263,   269,   260,    -1,   182,   263,   195,   260,    -1,
      89,   263,   269,   260,    -1,    81,   263,   195,   260,    -1,
      85,   263,   195,   260,    -1,    42,   263,   195,   260,    -1,
      51,   263,   195,   260,    -1,     8,   263,   195,   260,    -1,
     109,   263,   269,   260,    -1,   108,   263,   129,   260,    -1,
     102,   263,   129,   260,    -1,     9,   263,   269,   260,    -1,
     199,   263,   269,   260,    -1,   198,   263,   269,   260,    -1,
      74,   263,   129,   260,    -1,    93,   263,   195,   260,    -1,
      92,   263,   151,   260,    -1,    86,   263,   195,   260,    -1,
     259,   263,   195,   260,    -1,   190,   263,   195,   260,    -1,
     193,   263,   195,   260,    -1,   194,   263,   195,   260,    -1,
     192,   263,   195,   260,    -1,   192,   263,   196,   260,    -1,
     191,   263,   195,   260,    -1,   191,   263,   196,   260,    -1,
     143,   263,   269,   260,    -1,    19,   263,   269,   260,    -1,
     135,   263,   195,   260,    -1,   144,   263,   269,   260,    -1,
     186,   263,   195,   260,    -1,   126,   263,   195,   260,    -1,
     243,   263,   195,   260,    -1,   138,   263,   195,   260,    -1,
     113,   263,   151,   260,    -1,    43,   263,   129,   260,    -1,
     111,   263,   129,   260,    -1,   180,   263,   151,   260,    -1,
      31,   263,   151,   260,    -1,    27,   263,   129,   260,    -1,
     249,   263,   195,   260,    -1,    45,   263,   151,   260,    -1,
     240,   263,   151,   260,    -1,   147,   263,   195,   260,    -1,
      38,   263,   195,   260,    -1,   241,   263,   269,   260,    -1,
      -1,   140,   529,   263,   530,   260,    -1,   530,   264,   531,
      -1,   531,    -1,   202,    -1,   205,    -1,   206,    -1,   208,
      -1,   209,    -1,   212,    -1,   231,    -1,   226,    -1,   228,
      -1,   235,    -1,   232,    -1,   211,    -1,   227,    -1,   230,
      -1,   213,    -1,   238,    -1,   203,    -1,   204,    -1,   216,
      -1,    -1,   137,   533,   263,   534,   260,    -1,   534,   264,
     535,    -1,   535,    -1,   202,    -1,   205,    -1,   206,    -1,
     208,    -1,   209,    -1,   212,    -1,   231,    -1,   226,    -1,
     228,    -1,   235,    -1,   232,    -1,   211,    -1,   227,    -1,
     230,    -1,   213,    -1,   238,    -1,   203,    -1,   204,    -1,
     216,    -1,   114,   263,   129,   260,    -1,   115,   263,   129,
     260,    -1,    32,   263,   129,   260,    -1,   207,   263,   271,
     260,    -1,    -1,    65,   541,   262,   542,   261,   260,    -1,
     542,   543,    -1,   543,    -1,   544,    -1,   545,    -1,   546,
      -1,   550,    -1,   551,    -1,   552,    -1,     1,    -1,    47,
     263,   195,   260,    -1,    44,   263,   269,   260,    -1,    -1,
     100,   547,   263,   548,   260,    -1,   548,   264,   549,    -1,
     549,    -1,   197,    -1,    11,    -1,   248,   263,   151,   260,
      -1,   118,   263,   151,   260,    -1,    -1,     4,   553,   263,
     554,   260,    -1,   554,   264,   555,    -1,   555,    -1,   197,
      -1,    11,    -1,    21,   262,   557,   261,   260,    -1,   557,
     558,    -1,   558,    -1,   561,    -1,   562,    -1,   563,    -1,
     564,    -1,   569,    -1,   565,    -1,   566,    -1,   567,    -1,
     568,    -1,   570,    -1,   571,    -1,   572,    -1,   560,    -1,
     573,    -1,   574,    -1,   575,    -1,   576,    -1,   559,    -1,
       1,    -1,    39,   263,   195,   260,    -1,   161,   263,   195,
     260,    -1,    41,   263,   195,   260,    -1,   250,   263,   195,
     260,    -1,   251,   263,   195,   260,    -1,   252,   263,   195,
     260,    -1,    94,   263,   269,   260,    -1,    95,   263,   269,
     260,    -1,   104,   263,   129,   260,    -1,   152,   263,   195,
     260,    -1,   103,   263,   129,   260,    -1,    34,   263,   129,
     260,    -1,    33,   263,   129,   260,    -1,   124,   263,   195,
     260,    -1,   125,   263,   195,   260,    -1,    13,   263,   195,
     260,    -1,   141,   263,   129,   260,    -1,   142,   263,   269,
     260,    -1,   178,   262,   578,   261,   260,    -1,   578,   579,
      -1,   579,    -1,   580,    -1,   581,    -1,   583,    -1,   585,
      -1,   584,    -1,   582,    -1,   586,    -1,     1,    -1,    53,
     263,   195,   260,    -1,    80,   263,   195,   260,    -1,    77,
     263,   151,   260,    -1,    97,   263,   269,   260,    -1,    75,
     263,   195,   260,    -1,    40,   263,   195,   260,    -1,    79,
     263,   195,   260,    -1
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
    1239,  1246,  1245,  1249,  1249,  1250,  1250,  1251,  1251,  1253,
    1260,  1267,  1274,  1281,  1288,  1295,  1302,  1309,  1316,  1323,
    1330,  1337,  1344,  1351,  1358,  1372,  1371,  1421,  1421,  1423,
    1423,  1424,  1425,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1436,  1438,  1447,  1456,  1462,  1468,
    1474,  1480,  1486,  1492,  1498,  1504,  1510,  1516,  1522,  1532,
    1531,  1548,  1547,  1552,  1552,  1553,  1557,  1561,  1569,  1569,
    1570,  1570,  1570,  1570,  1570,  1572,  1572,  1574,  1574,  1576,
    1590,  1610,  1619,  1632,  1631,  1700,  1700,  1701,  1701,  1701,
    1701,  1702,  1702,  1702,  1703,  1703,  1705,  1742,  1755,  1764,
    1776,  1775,  1779,  1779,  1780,  1780,  1781,  1781,  1783,  1790,
    1797,  1804,  1811,  1818,  1825,  1832,  1839,  1849,  1868,  1878,
    1892,  1891,  1907,  1907,  1908,  1908,  1908,  1908,  1910,  1919,
    1934,  1947,  1949,  1949,  1950,  1950,  1952,  1968,  1967,  1983,
    1983,  1984,  1984,  1984,  1984,  1986,  1995,  2018,  2017,  2023,
    2023,  2024,  2028,  2032,  2036,  2040,  2044,  2048,  2052,  2056,
    2060,  2064,  2074,  2073,  2090,  2090,  2091,  2091,  2091,  2093,
    2100,  2099,  2105,  2105,  2106,  2110,  2114,  2118,  2122,  2126,
    2130,  2134,  2138,  2142,  2146,  2156,  2155,  2301,  2301,  2302,
    2302,  2303,  2303,  2303,  2304,  2304,  2305,  2305,  2306,  2306,
    2306,  2307,  2307,  2308,  2308,  2309,  2311,  2323,  2335,  2344,
    2370,  2388,  2406,  2412,  2416,  2425,  2424,  2428,  2428,  2429,
    2429,  2430,  2430,  2432,  2443,  2450,  2457,  2464,  2474,  2515,
    2526,  2539,  2552,  2561,  2597,  2596,  2660,  2659,  2663,  2663,
    2664,  2670,  2670,  2671,  2671,  2671,  2671,  2673,  2692,  2702,
    2701,  2724,  2724,  2725,  2725,  2725,  2727,  2733,  2742,  2744,
    2744,  2745,  2745,  2747,  2766,  2765,  2813,  2812,  2816,  2816,
    2817,  2823,  2823,  2824,  2824,  2824,  2824,  2826,  2832,  2841,
    2844,  2844,  2845,  2845,  2846,  2846,  2847,  2847,  2848,  2848,
    2849,  2849,  2850,  2850,  2851,  2851,  2852,  2852,  2853,  2853,
    2854,  2854,  2855,  2855,  2856,  2856,  2857,  2857,  2858,  2859,
    2859,  2860,  2860,  2861,  2861,  2862,  2862,  2863,  2863,  2864,
    2864,  2865,  2866,  2866,  2867,  2867,  2868,  2869,  2869,  2870,
    2870,  2871,  2871,  2872,  2872,  2873,  2873,  2874,  2877,  2882,
    2887,  2892,  2897,  2902,  2907,  2912,  2917,  2922,  2927,  2932,
    2937,  2942,  2947,  2952,  2957,  2962,  2967,  2973,  2984,  2989,
    2998,  3003,  3008,  3013,  3018,  3023,  3026,  3031,  3034,  3039,
    3044,  3049,  3054,  3059,  3064,  3069,  3074,  3079,  3090,  3095,
    3100,  3109,  3141,  3159,  3164,  3173,  3182,  3187,  3192,  3198,
    3197,  3202,  3202,  3203,  3206,  3209,  3212,  3215,  3218,  3221,
    3224,  3227,  3230,  3233,  3236,  3239,  3242,  3245,  3248,  3251,
    3254,  3257,  3263,  3262,  3267,  3267,  3268,  3271,  3274,  3277,
    3280,  3283,  3286,  3289,  3292,  3295,  3298,  3301,  3304,  3307,
    3310,  3313,  3316,  3319,  3322,  3327,  3332,  3337,  3342,  3352,
    3351,  3375,  3375,  3376,  3377,  3378,  3379,  3380,  3381,  3382,
    3384,  3390,  3397,  3396,  3401,  3401,  3402,  3406,  3412,  3446,
    3456,  3455,  3505,  3505,  3506,  3510,  3519,  3522,  3522,  3523,
    3523,  3524,  3524,  3525,  3525,  3526,  3526,  3527,  3527,  3528,
    3529,  3529,  3530,  3530,  3531,  3531,  3532,  3532,  3534,  3539,
    3544,  3549,  3554,  3559,  3564,  3569,  3574,  3579,  3584,  3589,
    3594,  3599,  3604,  3609,  3614,  3619,  3627,  3630,  3630,  3631,
    3631,  3632,  3633,  3634,  3634,  3635,  3636,  3638,  3644,  3650,
    3659,  3673,  3679,  3685
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
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
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
      59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   265,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   268,   268,   269,
     269,   269,   269,   269,   269,   270,   270,   271,   271,   271,
     271,   272,   273,   273,   274,   274,   274,   275,   276,   277,
     278,   278,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   281,   280,   282,   282,   283,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   296,   297,   297,   297,   297,   298,
     299,   300,   301,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   314,
     314,   314,   314,   314,   314,   315,   317,   316,   318,   318,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   321,   322,   323,   324,   325,   326,   327,   329,   328,
     330,   330,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   333,   332,   334,   334,   336,   335,   337,   335,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   340,   339,   341,   341,   342,
     342,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   359,
     358,   361,   360,   362,   362,   363,   363,   363,   364,   364,
     365,   365,   365,   365,   365,   367,   366,   368,   368,   369,
     369,   370,   371,   373,   372,   374,   374,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   376,   377,   378,   379,
     381,   380,   382,   382,   384,   383,   385,   383,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   387,   388,   389,
     391,   390,   392,   392,   393,   393,   393,   393,   394,   395,
     396,   397,   398,   398,   399,   399,   400,   402,   401,   403,
     403,   404,   404,   404,   404,   405,   406,   408,   407,   409,
     409,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   412,   411,   413,   413,   414,   414,   414,   415,
     417,   416,   418,   418,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   421,   420,   422,   422,   423,
     423,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   432,   434,   433,   435,   435,   437,
     436,   438,   436,   439,   439,   439,   439,   439,   440,   441,
     442,   443,   444,   445,   447,   446,   449,   448,   450,   450,
     451,   452,   452,   453,   453,   453,   453,   454,   455,   457,
     456,   458,   458,   459,   459,   459,   460,   461,   462,   463,
     463,   464,   464,   465,   467,   466,   469,   468,   470,   470,
     471,   472,   472,   473,   473,   473,   473,   474,   475,   476,
     477,   477,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   506,   507,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   529,
     528,   530,   530,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   533,   532,   534,   534,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   536,   537,   538,   539,   541,
     540,   542,   542,   543,   543,   543,   543,   543,   543,   543,
     544,   545,   547,   546,   548,   548,   549,   549,   550,   551,
     553,   552,   554,   554,   555,   555,   556,   557,   557,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   558,   558,   558,   558,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   578,   579,
     579,   579,   579,   579,   579,   579,   579,   580,   581,   582,
     583,   584,   585,   586
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
       1,     1,     1,     1,     1,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       6,     0,     5,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     0,
       3,     0,     2,     1,     1,     1,     1,     1,     4,     4,
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
       2,     0,     1,     0,     0,     0,   195,   355,   419,     0,
     434,     0,   609,   253,   404,   229,     0,     0,   126,   290,
       0,     0,   307,   332,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   197,   357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   657,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   638,
     656,   651,   639,   640,   641,   642,   644,   645,   646,   647,
     643,   648,   649,   650,   652,   653,   654,   655,   216,     0,
     198,   377,     0,   358,     0,   432,     0,     0,   430,   431,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,     0,   559,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   451,   505,
     500,   501,   498,   502,   503,   499,   462,   452,   453,   490,
     454,   455,   456,   457,   458,   459,   460,   461,   495,   463,
     464,   465,   466,   504,   468,   473,   469,   471,   470,   484,
     485,   472,   474,   475,   476,   477,   478,   467,   480,   489,
     491,   492,   481,   482,   506,   496,   497,   494,   483,   479,
     487,   488,   486,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    99,   106,   100,   104,   101,
     102,   105,   103,    97,    98,     0,     0,     0,     0,    43,
      44,    45,   142,     0,   129,     0,   686,     0,     0,     0,
       0,     0,     0,     0,     0,   678,   679,   680,   684,   681,
     683,   682,   685,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,    51,    63,    62,
      59,    52,    61,    55,    56,    57,    53,    60,    58,    54,
       0,     0,   305,     0,     0,   303,   304,    88,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   637,     0,     0,   425,     0,     0,     0,   422,
     423,   424,     0,     0,   429,   446,     0,     0,   436,   445,
       0,   442,   443,   444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     450,   619,   630,     0,     0,   622,     0,     0,     0,   612,
     613,   614,   615,   616,   617,   618,     0,     0,     0,   270,
       0,     0,     0,     0,     0,     0,   256,   257,   258,   259,
     264,   260,   261,   262,   263,   416,     0,   406,     0,   415,
       0,   412,   413,   414,     0,   231,     0,     0,     0,   241,
       0,   239,   240,   242,   243,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      46,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,     0,     0,   677,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   317,     0,     0,   310,   311,   312,   313,     0,     0,
     340,     0,   335,   336,   337,     0,     0,   302,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   636,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,   201,   204,
     205,   207,   208,   209,   210,   211,   212,   213,   202,   203,
     206,     0,     0,     0,     0,     0,     0,   385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   360,   361,   362,
     363,   364,   365,   367,   366,   368,   373,   372,   369,   370,
     371,   374,     0,     0,     0,   421,     0,   428,     0,     0,
       0,     0,   441,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,   611,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     255,     0,     0,     0,     0,   411,   244,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,     0,    41,     0,     0,     0,   171,     0,
       0,     0,   148,     0,     0,   131,   132,   133,   134,   137,
     138,   136,   135,   139,   297,     0,     0,     0,     0,   292,
       0,     0,     0,     0,     0,     0,     0,   676,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,   314,     0,     0,     0,     0,   309,   338,     0,     0,
       0,   334,     0,   301,    91,    90,    89,   673,   670,   669,
     658,   660,    27,    27,    27,    27,    27,    29,    28,   664,
     665,   668,   666,   671,   672,   674,   675,   667,   659,   661,
     662,   663,   214,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   199,   375,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   359,     0,     0,   420,   433,     0,
       0,     0,   435,   520,   524,   511,   540,   552,   551,   607,
     557,   518,   548,   554,   519,   509,   510,   527,   516,   517,
     530,   515,   529,   528,   523,   522,   521,   549,   508,   547,
     605,   606,   544,   541,   586,   602,   603,   587,   588,   589,
     590,   597,   591,   600,   604,   593,   598,   594,   599,   592,
     596,   595,   601,     0,   585,   546,   563,   579,   580,   564,
     565,   566,   567,   574,   568,   577,   581,   570,   575,   571,
     576,   569,   573,   572,   578,     0,   562,   539,   542,   556,
     513,   550,   514,   543,   532,   537,   538,   535,   536,   533,
     534,   526,   525,    35,    35,    35,    37,    36,   608,   555,
     558,   545,   553,   512,   531,     0,     0,     0,     0,     0,
       0,   610,     0,     0,   276,     0,     0,     0,     0,     0,
     254,     0,     0,     0,   405,     0,     0,     0,   249,   245,
     248,   230,   111,   117,   115,   114,   116,   112,   113,   110,
     118,   124,   119,   123,   121,   122,   120,   109,   108,   125,
      47,    48,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,   291,   692,   687,   691,
     689,   693,   688,   690,    75,    81,    73,    77,    76,    72,
      71,    69,    70,     0,    68,    74,    80,    78,    79,     0,
       0,     0,   308,     0,     0,   333,   306,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,   391,     0,     0,     0,     0,     0,     0,     0,
       0,   356,   426,   427,   447,   448,   440,     0,   439,   583,
       0,   560,     0,    38,    39,    40,   635,   634,     0,   633,
     621,   620,   627,   626,     0,   625,   629,   628,   268,   269,
     274,     0,   273,     0,   267,   289,   288,   287,   266,   418,
     410,     0,   409,   417,   236,   237,   235,     0,   234,   252,
     251,     0,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,   127,   299,   300,   298,    66,     0,   315,   321,
     327,   331,   330,   329,   326,   322,   325,   328,   323,   324,
       0,   320,   316,   339,   344,   350,   354,   353,   352,   349,
     345,   348,   351,   346,   347,     0,   343,   226,   227,   220,
     222,   224,   223,   221,   215,   228,   219,   217,   218,   225,
     381,   383,   384,   403,   402,   399,   389,     0,   388,     0,
     378,   400,   401,   376,   382,   398,   380,   379,   437,     0,
     584,   561,   631,     0,   623,     0,     0,   271,   276,   282,
     279,   284,   281,   280,   286,   283,   285,   278,   277,   407,
       0,   232,     0,   250,   247,   246,   147,   145,   175,     0,
     174,     0,   141,   144,   146,   152,   168,   169,   153,   154,
     155,   156,   163,   157,   166,   170,   159,   164,   160,   165,
     158,   162,   161,   167,     0,   151,   143,    67,   318,     0,
     341,     0,     0,   386,   391,   395,   396,   393,   394,   397,
     392,   438,   632,   624,   275,   272,   408,   233,     0,   172,
     177,   187,   185,   194,   184,   179,   188,   192,   181,   189,
     191,   186,   180,   193,   190,   182,   183,   178,   149,     0,
     319,   342,   390,   387,   176,   173,   150
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
    1290,  1338,  1291,  1357,    31,    51,   119,   606,   607,   608,
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
#define YYPACT_NINF -662
static const yytype_int16 yypact[] =
{
    -662,   678,  -662,  -228,  -237,  -213,  -662,  -662,  -662,  -207,
    -662,  -195,  -662,  -662,  -662,  -662,  -193,  -190,  -662,  -662,
    -157,  -149,  -662,  -662,  -123,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   295,
     569,     3,    47,  -105,     5,   -94,   397,   -91,   -83,   -76,
     -58,   298,    28,    64,   -44,   756,   338,   -37,   -36,    25,
     -27,   -22,   -10,    -4,     2,  -662,  -662,  -662,  -662,  -662,
      44,    49,    54,    61,    63,    72,    75,    77,    79,    80,
      84,    88,    97,    98,    99,   100,   102,   109,   136,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   -19,
    -662,  -662,    30,  -662,    27,  -662,   110,    10,  -662,  -662,
     101,  -662,   113,   114,   116,   120,   127,   128,   129,   132,
     133,   138,   144,   145,   147,   149,   151,   152,   154,   155,
     159,   160,   163,   169,   170,   173,   174,   175,   178,   180,
     184,   192,   194,  -662,   199,  -662,   202,   205,   207,   209,
     210,   211,   213,   214,   216,   217,   218,   221,   222,   224,
     225,   229,   231,   232,   233,   235,   239,    15,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,   527,   520,    35,    94,   -24,   250,
     255,   259,   261,   270,   273,   275,   279,   283,   284,   285,
     286,    20,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,    42,   289,   290,    50,  -662,
    -662,  -662,  -662,    48,  -662,   228,  -662,   291,   294,   296,
     297,   299,   301,   302,   269,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,    53,   304,   306,   312,   313,   318,   321,
     322,  -662,   334,   335,   336,   337,   164,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
     130,    17,  -662,   342,     4,  -662,  -662,  -662,   153,   172,
     242,   142,  -662,   363,   362,   432,   406,   411,   478,   478,
     480,   482,   417,   420,   494,   478,   429,   433,   435,   436,
     438,   369,  -662,   613,   379,  -662,   376,   380,    19,  -662,
    -662,  -662,   493,   387,  -662,  -662,   385,   386,  -662,  -662,
       7,  -662,  -662,  -662,   455,   478,   457,   478,   524,   503,
     526,   462,   463,   537,   516,   473,   540,   541,   542,   486,
     487,   489,   478,   534,   491,   548,   558,   478,   559,   560,
     539,   562,   563,   500,   501,   437,   506,   441,   478,   478,
     512,   478,   546,   517,   519,   522,  -152,   -63,   529,   530,
     478,   478,   586,   547,   478,   532,   543,   551,   552,   472,
    -662,  -662,  -662,   459,   471,  -662,   479,   485,    18,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,   475,   490,   492,  -662,
     495,   497,   504,   507,   511,    39,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,   514,  -662,   521,  -662,
      14,  -662,  -662,  -662,   476,  -662,   525,   528,   531,  -662,
      11,  -662,  -662,  -662,  -662,  -662,   603,   605,   612,   614,
     618,   634,   639,   641,   398,   646,   647,   604,   544,  -662,
    -662,   649,   650,   545,  -662,   468,   550,   555,   561,   565,
      29,  -662,  -662,  -662,  -662,   607,   608,   616,   657,   627,
     628,   478,   553,  -662,  -662,   674,   631,   681,   683,   686,
     687,   688,   566,   689,   635,   690,   691,   583,  -662,   584,
     582,  -662,   585,    60,  -662,  -662,  -662,  -662,   590,   588,
    -662,    67,  -662,  -662,  -662,   695,   592,  -662,   594,   595,
     598,  -662,   599,   600,   611,   615,   619,   196,   620,   621,
     622,   623,   624,   625,   626,   630,   637,   638,   645,   648,
     652,  -662,   653,   632,   655,   656,   658,   659,   664,   668,
     669,   671,   672,   679,   682,   692,   188,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,   663,   693,   694,   696,   697,   701,  -662,   705,   706,
     708,   709,   711,   712,   713,   714,   139,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   717,   725,   718,  -662,   719,  -662,   727,   743,
     720,   721,  -662,   722,   724,   726,   728,   729,   730,   731,
     732,   733,   734,   736,   737,   738,   739,   740,   741,   742,
     744,   745,   746,   747,   748,   749,   750,   751,   752,   753,
     754,   755,   757,   758,   661,   759,   698,   760,   761,   762,
     763,   764,   765,   766,   767,   768,   769,   770,   771,   772,
     773,   774,   775,    95,   776,   777,   778,   779,   780,   781,
     782,  -662,   783,   478,   785,   784,   798,   799,   788,  -662,
    -662,   801,   790,   786,   802,   787,   803,   807,   836,   791,
    -662,   844,   789,   852,   793,  -662,  -662,   792,   865,   892,
     915,   794,  -662,   796,   797,   800,   804,   805,   806,   808,
     809,   810,   811,   812,   813,   814,   815,   816,   817,   818,
     819,  -662,   820,   821,  -662,   822,   795,   823,  -662,   824,
     825,   826,  -662,   827,   266,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,   894,   899,   908,   831,  -662,
     832,   833,   834,   835,   837,   838,   839,  -662,   840,   841,
     842,   843,   845,   846,   847,   -20,   848,   849,   850,   851,
    -662,  -662,   910,   853,   911,   854,  -662,  -662,   912,   855,
     857,  -662,   859,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   478,   478,   478,   478,   478,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,   938,   954,   478,   955,   956,   967,   975,
     961,   984,   986,   478,   478,   586,   860,  -662,  -662,   970,
      36,   971,   972,   929,   862,   976,   977,   978,   979,   997,
     980,   981,   982,   874,  -662,   875,   876,  -662,  -662,   877,
     878,   983,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -251,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -250,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,   586,   586,   586,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,    -7,   880,   881,     6,   882,
     883,  -662,   884,   885,  1018,   887,   888,   889,   890,   891,
    -662,   893,   996,   895,  -662,    13,   896,   897,   715,   898,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  1003,   963,   900,  1008,  1009,  1010,   901,
    1014,   906,  -662,   907,   909,   913,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -229,  -662,  -662,  -662,  -662,  -662,   914,
     536,   916,  -662,   917,   570,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   930,   931,  -662,   932,   933,   934,   935,
     936,   937,  1040,   939,   940,   941,   942,   943,   944,   945,
     946,  -662,  -662,  -662,  -662,  -662,  -662,  -219,  -662,  -662,
     661,  -662,   698,  -662,  -662,  -662,  -662,  -662,  -208,  -662,
    -662,  -662,  -662,  -662,  -170,  -662,  -662,  -662,  -662,  -662,
    -662,  -161,  -662,   660,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -148,  -662,  -662,  -662,  -662,  -662,  -145,  -662,  -662,
    -662,  1041,   915,   947,   948,   949,  1043,   950,   951,   952,
     735,   953,  -662,  -662,  -662,  -662,  -662,   -20,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -126,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,   -48,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,   -32,  -662,   434,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   983,
    -662,  -662,  -662,    -7,  -662,     6,   660,  -662,  1018,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
     996,  -662,    13,  -662,  -662,  -662,  -662,  -662,  -662,   -26,
    -662,   502,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,    41,  -662,  -662,  -662,  -662,   536,
    -662,   570,   434,  -662,  1040,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   502,  -662,
    1043,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   735,
    -662,  -662,  -662,  -662,  -662,  -662,  -662
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -662,  -662,  -662,  -392,  -348,  -661,  -430,  -662,  -662,   642,
    -662,  -662,  -662,  -662,   856,  -662,  -662,  -662,    -8,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  1101,  -662,  -662,  -662,  -662,  -662,   957,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,   414,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -144,  -662,  -662,  -662,
    -124,  -662,  -662,  -121,  -662,  -662,  -662,  -662,   617,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   -68,  -662,
     828,  -662,  -662,  -662,    37,  -662,  -662,  -662,  -662,  -662,
     829,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   -47,  -662,
    -662,   -46,  -662,  -662,  -662,  -662,  -662,  -662,   702,  -662,
    -662,  -662,  -662,  -662,   902,  -662,  -662,  -662,  -662,   673,
    -662,  -662,  -662,  -662,  -662,   -95,  -662,  -662,  -662,   666,
    -662,  -662,  -662,  -662,   -96,  -662,  -662,  -662,  -662,   593,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,   -93,  -662,  -662,   -92,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,   -52,  -662,   830,  -662,
    -662,  -662,  -662,  -662,   864,  -662,  -662,  -662,  -662,  1106,
    -662,  -662,  -662,  -662,  -662,  -662,   -25,  -662,   858,  -662,
    -662,  -662,  -662,  1048,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,   103,  -662,  -662,  -662,
     104,  -662,  -662,  -662,  -662,  -662,  -662,  -662,   861,  -662,
    -662,  -662,  -662,  -662,   -28,  -662,  -662,  -662,  -662,  -662,
     -23,  -662,  -662,  1141,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,  -662,
    -662,  -662,  -662,  -662,   958,  -662,  -662,  -662,  -662,  -662,
    -662,  -662
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     578,   579,   714,    70,  1146,   332,   125,   585,   375,  1139,
    1141,   125,   484,  1140,  1142,   475,   131,  1152,   558,   441,
     365,   248,   442,   132,   133,    49,   332,   134,   365,   275,
     516,  1196,    47,    48,   135,  1197,   475,   664,    71,   666,
     456,  1258,   136,   705,   706,  1259,   137,   138,    72,    50,
     517,   275,  1262,   139,   681,    54,  1263,   140,   141,   686,
     142,   549,   443,   485,   457,   444,   143,    56,   558,    61,
     697,   698,    62,   700,   249,   250,   251,   252,   253,   254,
     255,   256,   711,   712,   144,   145,   716,   458,  1174,   146,
    1264,   459,   126,   486,  1265,   484,   147,   126,   487,  1267,
     148,   149,   375,  1268,   150,    65,   366,   151,   152,   993,
     994,   995,  1279,    66,   366,  1281,  1280,   153,   445,  1282,
      73,   257,   333,   154,   155,   376,   156,   157,   158,   159,
     160,   549,   707,   708,  1318,   559,   446,    79,  1319,    69,
     621,   161,   622,   333,   276,   623,   485,  1081,  1082,    80,
     162,   518,   163,   164,   118,   165,   258,   124,   166,   167,
     377,   488,   168,   624,   625,   303,   276,   476,   130,    81,
      82,   244,   367,   169,   277,    83,   486,    84,   550,   245,
     367,   487,   519,   806,   460,   559,   246,   626,   476,   592,
    1147,   627,   378,   461,   462,   170,   277,   171,   121,   477,
     304,   172,   560,  1153,   247,   173,   174,   175,   176,   177,
     593,   594,  1320,   178,   179,   282,  1321,   595,   285,   376,
     477,   628,   180,   629,   713,   330,   331,   463,  1323,   516,
      85,    86,  1324,   337,  1339,   630,   495,   259,  1340,    87,
      88,   338,  1175,   363,   488,   551,  1176,   305,   550,   517,
    1117,  1118,   560,   339,   377,   181,   182,   631,   183,   340,
      89,    90,   478,   341,   184,   566,   447,   775,   661,   185,
     286,   373,   751,   260,   186,   744,   439,    91,    92,   728,
     654,   508,   306,   478,   307,   308,   378,   464,    93,   632,
     798,   776,   364,   596,   597,   598,    70,    94,   599,   248,
     739,  1358,   510,   633,   568,  1359,   600,   343,   552,   287,
     515,   513,   344,   534,   777,   551,   634,   345,   778,   601,
     602,   825,   288,   569,   346,   577,   347,   309,   830,   310,
     311,    71,  1143,  1144,  1145,   348,   603,   604,   349,   303,
     350,    72,   351,   352,   289,   312,   290,   353,   291,   292,
     518,   354,   249,   250,   251,   252,   253,   254,   255,   256,
     355,   356,   357,   358,   605,   359,   293,   842,   843,   844,
     845,   846,   360,   372,   304,  1006,   384,   385,   552,   386,
     621,   519,   622,   387,   779,   623,    95,    96,    97,   313,
     388,   389,   390,   570,   635,   391,   392,   361,   131,   257,
     893,   393,   571,   624,   625,   132,   133,   394,   395,   134,
     396,   780,   397,    73,   398,   399,   135,   400,   401,   314,
     315,   305,   402,   403,   136,   547,   404,   626,   137,   138,
     781,   627,   405,   406,   258,   139,   407,   408,   409,   140,
     141,   410,   142,   411,  1325,  1114,  1326,   412,   143,   876,
    1097,  1098,  1099,  1100,  1101,   413,   306,   414,   307,   308,
    1327,   628,   416,   629,  1328,   418,   144,   145,   419,   775,
     420,   146,   421,   422,   423,   630,   424,   425,   147,   426,
     427,   428,   148,   149,   429,   430,   150,   431,   432,   151,
     152,   573,   433,   776,   434,   435,   436,   631,   437,   153,
     782,   309,   438,   310,   311,   154,   155,  1341,   156,   157,
     158,   159,   160,   496,   783,   259,   777,  1104,   497,   312,
     778,   456,   498,   161,   499,  1112,  1113,  1061,   441,   632,
     532,   442,   162,   500,   163,   164,   501,   165,   502,  1342,
     166,   167,   503,   633,   168,   457,   504,   505,   506,   507,
    1343,   260,   511,   512,   525,   169,   634,   526,   572,   527,
     528,   574,   529,   313,   530,   531,  1344,   535,   458,   536,
      79,   443,   459,  1345,   444,   537,   538,   170,  1346,   171,
    1347,   539,    80,   172,   540,   541,   779,   173,   174,   175,
     176,   177,  1348,   314,   315,   178,   179,   543,   544,   545,
     546,   575,    81,    82,   180,   565,   576,   577,    83,   580,
      84,   581,   582,   780,   592,   583,   761,   762,   763,   764,
     765,   766,   767,   584,   586,  1349,  1199,   445,   587,   591,
     588,   589,   781,   590,   635,   593,   594,   181,   182,   652,
     183,  1350,   595,   653,   656,   446,   184,   657,   658,   659,
     663,   185,   665,   667,   668,   669,   186,   670,   671,  1351,
    1214,  1352,  1353,    85,    86,   460,   672,   673,   674,   675,
     676,   677,    87,    88,   461,   462,  1329,   684,     2,     3,
    1269,   678,   679,     4,   680,   682,   683,   685,   687,   688,
     689,   690,   691,    89,    90,   692,   693,   701,   715,     5,
     694,   695,   782,     6,   696,  1200,     7,   699,   463,  1270,
      91,    92,   702,     8,   703,   713,   783,   704,   596,   597,
     598,    93,   723,   599,   709,   710,  1271,   717,     9,  1354,
      94,   600,   721,  1272,   724,   730,   746,  1201,   718,  1215,
      10,    11,   726,    12,   601,   602,   719,   720,   727,  1355,
      13,  1273,  1202,   731,   753,   732,   754,   286,   734,  1356,
     735,   603,   604,   755,   817,   756,    14,   736,   464,   757,
     737,  1216,  1203,  1204,   738,   447,    15,   741,    16,  1274,
    1205,  1206,  1207,  1208,   743,   758,  1217,  1275,   748,   605,
     759,   749,   760,  1209,   750,    17,   287,   768,   769,   770,
     772,   773,   800,   801,   771,   774,  1218,  1219,   803,   288,
     794,   802,    18,   807,  1220,  1221,  1222,  1223,   795,    95,
      96,    97,   804,   805,   796,   808,   809,  1224,   797,   815,
    1276,   289,   810,   290,   811,   291,   292,   812,   813,   814,
     816,   818,   819,   820,   821,   822,   832,    19,   824,  1277,
     827,   828,   833,   293,   834,   835,    20,    21,   836,   837,
     838,    22,    23,   934,   935,   936,   937,   938,   895,   939,
     940,   839,   941,   942,   943,   840,   896,   944,   899,   841,
     849,   850,   851,   852,   853,   854,   855,   945,   946,   947,
     856,   948,   949,   950,   900,   863,   951,   857,   858,   952,
     956,   957,   958,   959,   960,   859,   961,   962,   860,   963,
     964,   965,   861,   862,   966,  1181,  1016,    24,   864,   865,
     514,   866,   867,   878,   967,   968,   969,   868,   970,   971,
     972,   869,   870,   973,   871,   872,   974,  1295,  1296,  1297,
    1298,  1299,   873,  1300,  1301,   874,  1302,  1303,  1304,  1009,
    1010,  1305,  1012,  1015,  1017,   875,   879,   880,  1018,   881,
     882,  1306,  1307,  1308,   883,  1309,  1310,  1311,   885,   886,
    1312,   887,   888,  1313,   889,   890,   891,   892,   897,   898,
    1007,   902,   903,   901,   904,  1013,   905,  1019,   906,   907,
     908,   909,   910,   911,   912,  1021,   913,   914,   915,   916,
     917,   918,   919,  1023,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   929,   930,   931,  1026,   932,   933,   955,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,   991,   992,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1027,  1028,  1063,  1005,  1008,  1011,  1014,
    1064,  1020,  1022,  1024,  1031,  1025,  1032,  1033,  1053,  1065,
    1034,  1089,  1091,  1093,  1035,  1036,  1037,  1102,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,
    1050,  1051,  1052,  1103,  1105,  1106,  1054,  1056,  1057,  1058,
    1060,  1066,  1067,  1068,  1069,  1070,  1107,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1108,  1078,  1079,  1080,  1085,  1086,
    1087,  1088,  1109,  1110,  1092,  1111,  1090,  1095,  1094,  1096,
    1115,  1116,  1119,  1120,  1121,  1122,  1127,  1123,  1124,  1125,
    1126,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1150,  1151,  1156,  1157,  1158,  1159,  1160,  1164,  1165,  1166,
    1167,  1168,  1170,  1169,  1184,  1173,  1179,  1180,  1185,  1187,
    1188,  1189,  1182,  1186,  1190,  1191,  1192,  1193,  1246,  1194,
    1283,  1288,   548,  1195,  1198,   342,  1212,  1213,  1227,  1228,
    1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1317,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1062,  1250,
    1251,  1252,  1253,  1254,  1255,  1256,  1257,  1285,  1286,  1287,
    1292,  1293,  1294,  1316,  1337,  1366,  1365,  1364,   509,  1284,
    1334,  1335,   799,   877,  1360,  1361,   826,   831,  1336,   894,
    1362,  1363,   655,   374,  1331,   440,   567,  1333,   662,   362,
    1332,     0,     0,     0,  1260,  1261,     0,     0,     0,     0,
       0,     0,   533,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   740,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   729,
     745,     0,     0,     0,     0,     0,     0,     0,   752
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-662))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     348,   349,   432,     1,    11,     1,     1,   355,     1,   260,
     260,     1,     1,   264,   264,     1,     1,    11,     1,     1,
       1,     1,     4,     8,     9,   262,     1,    12,     1,     1,
       1,   260,   260,   261,    19,   264,     1,   385,    36,   387,
       1,   260,    27,   195,   196,   264,    31,    32,    46,   262,
      21,     1,   260,    38,   402,   262,   264,    42,    43,   407,
      45,     1,    44,    52,    25,    47,    51,   262,     1,   262,
     418,   419,   262,   421,    54,    55,    56,    57,    58,    59,
      60,    61,   430,   431,    69,    70,   434,    48,    75,    74,
     260,    52,    87,    82,   264,     1,    81,    87,    87,   260,
      85,    86,     1,   264,    89,   262,    87,    92,    93,    14,
      15,    16,   260,   262,    87,   260,   264,   102,   100,   264,
     118,   101,   118,   108,   109,   118,   111,   112,   113,   114,
     115,     1,   195,   196,   260,   118,   118,     1,   264,   262,
       1,   126,     3,   118,   116,     6,    52,   167,   168,    13,
     135,   122,   137,   138,   151,   140,   136,   262,   143,   144,
     153,   150,   147,    24,    25,     1,   116,   153,   262,    33,
      34,   262,   153,   158,   146,    39,    82,    41,   118,   262,
     153,    87,   153,   531,   145,   118,   262,    48,   153,     1,
     197,    52,   185,   154,   155,   180,   146,   182,   151,   185,
      36,   186,   185,   197,   262,   190,   191,   192,   193,   194,
      22,    23,   260,   198,   199,   151,   264,    29,   262,   118,
     185,    82,   207,    84,   129,   262,   262,   188,   260,     1,
      94,    95,   264,   260,   260,    96,   260,   217,   264,   103,
     104,   263,   229,   262,   150,   185,   233,    83,   118,    21,
     214,   215,   185,   263,   153,   240,   241,   118,   243,   263,
     124,   125,   248,   261,   249,   261,   248,     1,   261,   254,
       1,   261,   261,   253,   259,   261,   261,   141,   142,   261,
     261,   261,   118,   248,   120,   121,   185,   248,   152,   150,
     261,    25,   262,   105,   106,   107,     1,   161,   110,     1,
     261,   260,   260,   164,   151,   264,   118,   263,   248,    40,
     262,   261,   263,   260,    48,   185,   177,   263,    52,   131,
     132,   261,    53,   151,   263,   129,   263,   163,   261,   165,
     166,    36,   993,   994,   995,   263,   148,   149,   263,     1,
     263,    46,   263,   263,    75,   181,    77,   263,    79,    80,
     122,   263,    54,    55,    56,    57,    58,    59,    60,    61,
     263,   263,   263,   263,   176,   263,    97,   171,   172,   173,
     174,   175,   263,   263,    36,   723,   263,   263,   248,   263,
       1,   153,     3,   263,   118,     6,   250,   251,   252,   225,
     263,   263,   263,   151,   255,   263,   263,   261,     1,   101,
     261,   263,   260,    24,    25,     8,     9,   263,   263,    12,
     263,   145,   263,   118,   263,   263,    19,   263,   263,   255,
     256,    83,   263,   263,    27,   261,   263,    48,    31,    32,
     164,    52,   263,   263,   136,    38,   263,   263,   263,    42,
      43,   263,    45,   263,    10,   875,    12,   263,    51,   261,
     842,   843,   844,   845,   846,   263,   118,   263,   120,   121,
      26,    82,   263,    84,    30,   263,    69,    70,   263,     1,
     263,    74,   263,   263,   263,    96,   263,   263,    81,   263,
     263,   263,    85,    86,   263,   263,    89,   263,   263,    92,
      93,   129,   263,    25,   263,   263,   263,   118,   263,   102,
     234,   163,   263,   165,   166,   108,   109,     5,   111,   112,
     113,   114,   115,   263,   248,   217,    48,   865,   263,   181,
      52,     1,   263,   126,   263,   873,   874,   261,     1,   150,
     261,     4,   135,   263,   137,   138,   263,   140,   263,    37,
     143,   144,   263,   164,   147,    25,   263,   263,   263,   263,
      48,   253,   263,   263,   263,   158,   177,   263,   195,   263,
     263,   129,   263,   225,   263,   263,    64,   263,    48,   263,
       1,    44,    52,    71,    47,   263,   263,   180,    76,   182,
      78,   263,    13,   186,   263,   263,   118,   190,   191,   192,
     193,   194,    90,   255,   256,   198,   199,   263,   263,   263,
     263,   195,    33,    34,   207,   263,   195,   129,    39,   129,
      41,   129,   195,   145,     1,   195,   218,   219,   220,   221,
     222,   223,   224,   129,   195,   123,    90,   100,   195,   260,
     195,   195,   164,   195,   255,    22,    23,   240,   241,   263,
     243,   139,    29,   263,   151,   118,   249,   260,   263,   263,
     195,   254,   195,   129,   151,   129,   259,   195,   195,   157,
      90,   159,   160,    94,    95,   145,   129,   151,   195,   129,
     129,   129,   103,   104,   154,   155,   242,   129,     0,     1,
      20,   195,   195,     5,   195,   151,   195,   129,   129,   129,
     151,   129,   129,   124,   125,   195,   195,   151,   151,    21,
     263,   195,   234,    25,   263,   169,    28,   195,   188,    49,
     141,   142,   195,    35,   195,   129,   248,   195,   105,   106,
     107,   152,   263,   110,   195,   195,    66,   195,    50,   227,
     161,   118,   260,    73,   263,   260,   260,   201,   195,   169,
      62,    63,   263,    65,   131,   132,   195,   195,   263,   247,
      72,    91,   216,   263,   151,   263,   151,     1,   263,   257,
     263,   148,   149,   151,   129,   151,    88,   263,   248,   151,
     263,   201,   236,   237,   263,   248,    98,   263,   100,   119,
     244,   245,   246,   247,   263,   151,   216,   127,   263,   176,
     151,   263,   151,   257,   263,   117,    40,   151,   151,   195,
     151,   151,   195,   195,   260,   260,   236,   237,   151,    53,
     260,   195,   134,   260,   244,   245,   246,   247,   263,   250,
     251,   252,   195,   195,   263,   151,   195,   257,   263,   263,
     170,    75,   151,    77,   151,    79,    80,   151,   151,   151,
     151,   151,   151,   260,   260,   263,   151,   169,   263,   189,
     260,   263,   260,    97,   260,   260,   178,   179,   260,   260,
     260,   183,   184,   202,   203,   204,   205,   206,   151,   208,
     209,   260,   211,   212,   213,   260,   151,   216,   151,   260,
     260,   260,   260,   260,   260,   260,   260,   226,   227,   228,
     260,   230,   231,   232,   151,   263,   235,   260,   260,   238,
     202,   203,   204,   205,   206,   260,   208,   209,   260,   211,
     212,   213,   260,   260,   216,   200,   129,   239,   263,   263,
     278,   263,   263,   260,   226,   227,   228,   263,   230,   231,
     232,   263,   263,   235,   263,   263,   238,   202,   203,   204,
     205,   206,   263,   208,   209,   263,   211,   212,   213,   151,
     151,   216,   151,   151,   151,   263,   263,   263,   151,   263,
     263,   226,   227,   228,   263,   230,   231,   232,   263,   263,
     235,   263,   263,   238,   263,   263,   263,   263,   260,   260,
     195,   260,   260,   263,   260,   195,   260,   151,   260,   260,
     260,   260,   260,   260,   260,   151,   260,   260,   260,   260,
     260,   260,   260,   151,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   151,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   151,   129,   151,   263,   263,   260,   263,
     151,   260,   263,   260,   260,   263,   260,   260,   263,   151,
     260,   151,   151,   151,   260,   260,   260,   129,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   129,   129,   129,   263,   263,   263,   263,
     263,   260,   260,   260,   260,   260,   129,   260,   260,   260,
     260,   260,   260,   260,   129,   260,   260,   260,   260,   260,
     260,   260,   151,   129,   260,   129,   263,   260,   263,   260,
     260,   151,   151,   151,   195,   263,   129,   151,   151,   151,
     151,   151,   151,   151,   260,   260,   260,   260,   260,   156,
     260,   260,   260,   260,   260,   260,   128,   260,   260,   260,
     260,   260,   156,   260,   151,   260,   260,   260,   195,   151,
     151,   151,   264,   263,   263,   151,   260,   260,   128,   260,
     129,   128,   316,   260,   260,    74,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,  1197,
     260,   260,   260,   260,   260,   260,   260,   260,   784,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,  1282,  1359,  1340,  1338,   261,  1182,
    1266,  1268,   520,   606,  1319,  1321,   553,   561,  1280,   636,
    1322,  1324,   368,   127,  1259,   187,   334,  1265,   380,    98,
    1263,    -1,    -1,    -1,  1140,  1142,    -1,    -1,    -1,    -1,
      -1,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   266,     0,     1,     5,    21,    25,    28,    35,    50,
      62,    63,    65,    72,    88,    98,   100,   117,   134,   169,
     178,   179,   183,   184,   239,   267,   272,   277,   295,   301,
     316,   339,   358,   372,   390,   397,   401,   411,   420,   446,
     456,   462,   466,   476,   540,   556,   577,   260,   261,   262,
     262,   340,   421,   457,   262,   467,   262,   541,   373,   447,
     359,   262,   262,   317,   391,   262,   262,   402,   412,   262,
       1,    36,    46,   118,   296,   297,   298,   299,   300,     1,
      13,    33,    34,    39,    41,    94,    95,   103,   104,   124,
     125,   141,   142,   152,   161,   250,   251,   252,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   151,   341,
     345,   151,   422,   426,   262,     1,    87,   463,   464,   465,
     262,     1,     8,     9,    12,    19,    27,    31,    32,    38,
      42,    43,    45,    51,    69,    70,    74,    81,    85,    86,
      89,    92,    93,   102,   108,   109,   111,   112,   113,   114,
     115,   126,   135,   137,   138,   140,   143,   144,   147,   158,
     180,   182,   186,   190,   191,   192,   193,   194,   198,   199,
     207,   240,   241,   243,   249,   254,   259,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   532,
     536,   537,   538,   539,   262,   262,   262,   262,     1,    54,
      55,    56,    57,    58,    59,    60,    61,   101,   136,   217,
     253,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,     1,   116,   146,   273,   274,
     275,   276,   151,   318,   322,   262,     1,    40,    53,    75,
      77,    79,    80,    97,   578,   579,   580,   581,   582,   583,
     584,   585,   586,     1,    36,    83,   118,   120,   121,   163,
     165,   166,   181,   225,   255,   256,   278,   279,   280,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     262,   262,     1,   118,   398,   399,   400,   260,   263,   263,
     263,   261,   297,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   261,   558,   262,   262,     1,    87,   153,   458,   459,
     460,   461,   263,   261,   464,     1,   118,   153,   185,   468,
     472,   473,   474,   475,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   533,   263,   529,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   261,
     478,     1,     4,    44,    47,   100,   118,   248,   542,   543,
     544,   545,   546,   550,   551,   552,     1,    25,    48,    52,
     145,   154,   155,   188,   248,   374,   375,   376,   377,   378,
     379,   380,   387,   388,   389,     1,   153,   185,   248,   448,
     452,   453,   454,   455,     1,    52,    82,    87,   150,   360,
     364,   365,   366,   370,   371,   260,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   261,   303,
     260,   263,   263,   261,   274,   262,     1,    21,   122,   153,
     392,   393,   394,   395,   396,   263,   263,   263,   263,   263,
     263,   263,   261,   579,   260,   263,   263,   263,   263,   263,
     263,   263,   281,   263,   263,   263,   263,   261,   279,     1,
     118,   185,   248,   403,   404,   405,   406,   407,     1,   118,
     185,   413,   414,   415,   416,   263,   261,   399,   151,   151,
     151,   260,   195,   129,   129,   195,   195,   129,   269,   269,
     129,   129,   195,   195,   129,   269,   195,   195,   195,   195,
     195,   260,     1,    22,    23,    29,   105,   106,   107,   110,
     118,   131,   132,   148,   149,   176,   342,   343,   344,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,     1,     3,     6,    24,    25,    48,    52,    82,    84,
      96,   118,   150,   164,   177,   255,   423,   424,   425,   427,
     428,   429,   430,   431,   432,   433,   440,   441,   442,   443,
     444,   445,   263,   263,   261,   459,   151,   260,   263,   263,
     469,   261,   473,   195,   269,   195,   269,   129,   151,   129,
     195,   195,   129,   151,   195,   129,   129,   129,   195,   195,
     195,   269,   151,   195,   129,   129,   269,   129,   129,   151,
     129,   129,   195,   195,   263,   195,   263,   269,   269,   195,
     269,   151,   195,   195,   195,   195,   196,   195,   196,   195,
     195,   269,   269,   129,   271,   151,   269,   195,   195,   195,
     195,   260,   553,   263,   263,   547,   263,   263,   261,   543,
     260,   263,   263,   381,   263,   263,   263,   263,   263,   261,
     375,   263,   449,   263,   261,   453,   260,   361,   263,   263,
     263,   261,   365,   151,   151,   151,   151,   151,   151,   151,
     151,   218,   219,   220,   221,   222,   223,   224,   151,   151,
     195,   260,   151,   151,   260,     1,    25,    48,    52,   118,
     145,   164,   234,   248,   319,   320,   321,   323,   324,   325,
     326,   327,   328,   332,   260,   263,   263,   263,   261,   393,
     195,   195,   195,   151,   195,   195,   269,   260,   151,   195,
     151,   151,   151,   151,   151,   263,   151,   129,   151,   151,
     260,   260,   263,   408,   263,   261,   404,   260,   263,   417,
     261,   414,   151,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   171,   172,   173,   174,   175,   268,   269,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   261,   343,   260,   263,
     263,   263,   263,   263,   434,   263,   263,   263,   263,   263,
     263,   263,   263,   261,   424,   151,   151,   260,   260,   151,
     151,   263,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   202,   203,   204,   205,   206,   208,
     209,   211,   212,   213,   216,   226,   227,   228,   230,   231,
     232,   235,   238,   534,   535,   260,   202,   203,   204,   205,
     206,   208,   209,   211,   212,   213,   216,   226,   227,   228,
     230,   231,   232,   235,   238,   530,   531,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,    14,    15,    16,   270,   271,   260,   260,
     260,   260,   260,   260,   260,   263,   269,   195,   263,   151,
     151,   260,   151,   195,   263,   151,   129,   151,   151,   151,
     260,   151,   263,   151,   260,   263,   151,   151,   129,   368,
     369,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   263,   263,   333,   263,   263,   263,   329,
     263,   261,   320,   151,   151,   151,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   167,   168,   282,   283,   260,   260,   260,   260,   151,
     263,   151,   260,   151,   263,   260,   260,   268,   268,   268,
     268,   268,   129,   129,   269,   129,   129,   129,   129,   151,
     129,   129,   269,   269,   271,   260,   151,   214,   215,   151,
     151,   195,   263,   151,   151,   151,   151,   129,   151,   151,
     151,   260,   260,   260,   260,   260,   156,   470,   471,   260,
     264,   260,   264,   270,   270,   270,    11,   197,   554,   555,
     260,   260,    11,   197,   548,   549,   260,   260,   260,   260,
     128,   382,   383,   385,   260,   260,   260,   260,   260,   260,
     156,   450,   451,   260,    75,   229,   233,   362,   363,   260,
     260,   200,   264,   367,   151,   195,   263,   151,   151,   151,
     263,   151,   260,   260,   260,   260,   260,   264,   260,    90,
     169,   201,   216,   236,   237,   244,   245,   246,   247,   257,
     409,   410,   260,   260,    90,   169,   201,   216,   236,   237,
     244,   245,   246,   247,   257,   418,   419,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   128,   435,   436,   438,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   264,
     535,   531,   260,   264,   260,   264,   384,   260,   264,    20,
      49,    66,    73,    91,   119,   127,   170,   189,   386,   260,
     264,   260,   264,   129,   369,   260,   260,   260,   128,   334,
     335,   337,   260,   260,   260,   202,   203,   204,   205,   206,
     208,   209,   211,   212,   213,   216,   226,   227,   228,   230,
     231,   232,   235,   238,   330,   331,   260,   283,   260,   264,
     260,   264,   437,   260,   264,    10,    12,    26,    30,   242,
     439,   471,   555,   549,   386,   383,   451,   363,   336,   260,
     264,     5,    37,    48,    64,    71,    76,    78,    90,   123,
     139,   157,   159,   160,   227,   247,   257,   338,   260,   264,
     410,   419,   439,   436,   338,   335,   331
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
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1250 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1251 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1254 "ircd_parser.y"
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
#line 1261 "ircd_parser.y"
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
#line 1268 "ircd_parser.y"
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
#line 1275 "ircd_parser.y"
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
#line 1282 "ircd_parser.y"
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
#line 1289 "ircd_parser.y"
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
#line 1296 "ircd_parser.y"
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
#line 1303 "ircd_parser.y"
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
#line 1310 "ircd_parser.y"
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
#line 1317 "ircd_parser.y"
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
#line 1324 "ircd_parser.y"
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
#line 1331 "ircd_parser.y"
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
#line 1338 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1345 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1352 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1359 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1372 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1379 "ircd_parser.y"
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

  case 215:

/* Line 1806 of yacc.c  */
#line 1439 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1448 "ircd_parser.y"
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
#line 1457 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1463 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1469 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1481 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1487 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1493 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1499 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1505 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1511 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1517 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1523 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1532 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1539 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1548 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1554 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1558 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1562 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1572 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1577 "ircd_parser.y"
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

  case 250:

/* Line 1806 of yacc.c  */
#line 1591 "ircd_parser.y"
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

  case 251:

/* Line 1806 of yacc.c  */
#line 1611 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 1620 "ircd_parser.y"
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
#line 1632 "ircd_parser.y"
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

  case 254:

/* Line 1806 of yacc.c  */
#line 1644 "ircd_parser.y"
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

  case 266:

/* Line 1806 of yacc.c  */
#line 1706 "ircd_parser.y"
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

  case 267:

/* Line 1806 of yacc.c  */
#line 1743 "ircd_parser.y"
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

  case 268:

/* Line 1806 of yacc.c  */
#line 1756 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1765 "ircd_parser.y"
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

  case 270:

/* Line 1806 of yacc.c  */
#line 1776 "ircd_parser.y"
    {
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1780 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1781 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1784 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1791 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1798 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1805 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1812 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1819 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1826 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1833 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1850 "ircd_parser.y"
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

  case 288:

/* Line 1806 of yacc.c  */
#line 1869 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1879 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1892 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1899 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1920 "ircd_parser.y"
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

  case 300:

/* Line 1806 of yacc.c  */
#line 1935 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1953 "ircd_parser.y"
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

  case 307:

/* Line 1806 of yacc.c  */
#line 1968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1987 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1996 "ircd_parser.y"
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

  case 317:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 2025 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2029 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2033 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2037 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2041 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2045 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2049 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2053 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 2057 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 2061 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 2065 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2074 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2081 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2094 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2100 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2107 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2111 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2127 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 2135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 2139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 2143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 2147 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 2156 "ircd_parser.y"
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

  case 356:

/* Line 1806 of yacc.c  */
#line 2174 "ircd_parser.y"
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

  case 376:

/* Line 1806 of yacc.c  */
#line 2312 "ircd_parser.y"
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

  case 377:

/* Line 1806 of yacc.c  */
#line 2324 "ircd_parser.y"
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
#line 2336 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2345 "ircd_parser.y"
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

  case 380:

/* Line 1806 of yacc.c  */
#line 2371 "ircd_parser.y"
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

  case 381:

/* Line 1806 of yacc.c  */
#line 2389 "ircd_parser.y"
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

  case 382:

/* Line 1806 of yacc.c  */
#line 2407 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2413 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2417 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2425 "ircd_parser.y"
    {
}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 2429 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2430 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 2433 "ircd_parser.y"
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

  case 394:

/* Line 1806 of yacc.c  */
#line 2444 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 2451 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 2458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2475 "ircd_parser.y"
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

  case 399:

/* Line 1806 of yacc.c  */
#line 2516 "ircd_parser.y"
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

  case 400:

/* Line 1806 of yacc.c  */
#line 2527 "ircd_parser.y"
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

  case 401:

/* Line 1806 of yacc.c  */
#line 2540 "ircd_parser.y"
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

  case 402:

/* Line 1806 of yacc.c  */
#line 2553 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 2562 "ircd_parser.y"
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

  case 404:

/* Line 1806 of yacc.c  */
#line 2597 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2604 "ircd_parser.y"
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

  case 406:

/* Line 1806 of yacc.c  */
#line 2660 "ircd_parser.y"
    {
}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 2665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 2674 "ircd_parser.y"
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

  case 418:

/* Line 1806 of yacc.c  */
#line 2693 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 2702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 2706 "ircd_parser.y"
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

  case 426:

/* Line 1806 of yacc.c  */
#line 2728 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 2734 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 2748 "ircd_parser.y"
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

  case 434:

/* Line 1806 of yacc.c  */
#line 2766 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 2773 "ircd_parser.y"
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

  case 436:

/* Line 1806 of yacc.c  */
#line 2813 "ircd_parser.y"
    {
}
    break;

  case 440:

/* Line 1806 of yacc.c  */
#line 2818 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 447:

/* Line 1806 of yacc.c  */
#line 2827 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 2833 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2878 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2883 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2888 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2893 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2898 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2903 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2908 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2913 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2918 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2923 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2928 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2933 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2938 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2943 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2948 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2953 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2958 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2963 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2974 "ircd_parser.y"
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

  case 528:

/* Line 1806 of yacc.c  */
#line 2985 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2990 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2999 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3004 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3009 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3014 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3019 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3024 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 3027 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 3032 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3035 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3050 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3055 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3065 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3070 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3080 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3091 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3096 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3101 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3110 "ircd_parser.y"
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

  case 552:

/* Line 1806 of yacc.c  */
#line 3142 "ircd_parser.y"
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

  case 553:

/* Line 1806 of yacc.c  */
#line 3160 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3183 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3188 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3193 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3198 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3204 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3207 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3210 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3213 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3219 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3222 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3228 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3234 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3237 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3243 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3249 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3252 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3258 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3275 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3278 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3284 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3287 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3290 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3293 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3296 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3299 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3302 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3305 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3308 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3311 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3314 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3317 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3320 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3323 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3328 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3333 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3338 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3343 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 3352 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 3359 "ircd_parser.y"
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

  case 620:

/* Line 1806 of yacc.c  */
#line 3385 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 3391 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 3397 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 3403 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 3407 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 3413 "ircd_parser.y"
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

  case 629:

/* Line 1806 of yacc.c  */
#line 3447 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 3456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 3460 "ircd_parser.y"
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

  case 634:

/* Line 1806 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3511 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3535 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3540 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3545 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3550 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3555 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3560 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3565 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3570 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3575 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3580 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3585 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3590 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3595 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 671:

/* Line 1806 of yacc.c  */
#line 3600 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 3605 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 3610 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 3615 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 3620 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 687:

/* Line 1806 of yacc.c  */
#line 3639 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 3645 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 689:

/* Line 1806 of yacc.c  */
#line 3651 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 690:

/* Line 1806 of yacc.c  */
#line 3660 "ircd_parser.y"
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

  case 691:

/* Line 1806 of yacc.c  */
#line 3674 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 692:

/* Line 1806 of yacc.c  */
#line 3680 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 3686 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 8104 "ircd_parser.c"
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



