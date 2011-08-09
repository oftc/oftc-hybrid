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
     IRCD_FLAGS = 308,
     FLATTEN_LINKS = 309,
     FFAILED_OPERLOG = 310,
     FKILLLOG = 311,
     FKLINELOG = 312,
     FGLINELOG = 313,
     FIOERRLOG = 314,
     FOPERLOG = 315,
     FOPERSPYLOG = 316,
     FUSERLOG = 317,
     GECOS = 318,
     GENERAL = 319,
     GLINE = 320,
     GLINES = 321,
     GLINE_EXEMPT = 322,
     GLINE_LOG = 323,
     GLINE_TIME = 324,
     GLINE_MIN_CIDR = 325,
     GLINE_MIN_CIDR6 = 326,
     GLOBAL_KILL = 327,
     IRCD_AUTH = 328,
     NEED_IDENT = 329,
     HAVENT_READ_CONF = 330,
     HIDDEN = 331,
     HIDDEN_ADMIN = 332,
     HIDDEN_NAME = 333,
     HIDDEN_OPER = 334,
     HIDE_SERVER_IPS = 335,
     HIDE_SERVERS = 336,
     HIDE_SPOOF_IPS = 337,
     HOST = 338,
     HUB = 339,
     HUB_MASK = 340,
     IDLETIME = 341,
     IGNORE_BOGUS_TS = 342,
     INVISIBLE_ON_CONNECT = 343,
     IP = 344,
     KILL = 345,
     KILL_CHASE_TIME_LIMIT = 346,
     KLINE = 347,
     KLINE_EXEMPT = 348,
     KLINE_REASON = 349,
     KLINE_WITH_REASON = 350,
     KNOCK_DELAY = 351,
     KNOCK_DELAY_CHANNEL = 352,
     LEAF_MASK = 353,
     LINKS_DELAY = 354,
     LISTEN = 355,
     T_LOG = 356,
     LOGGING = 357,
     LOG_LEVEL = 358,
     MAX_ACCEPT = 359,
     MAX_BANS = 360,
     MAX_CHANS_PER_USER = 361,
     MAX_GLOBAL = 362,
     MAX_IDENT = 363,
     MAX_LOCAL = 364,
     MAX_NICK_CHANGES = 365,
     MAX_NICK_TIME = 366,
     MAX_NUMBER = 367,
     MAX_TARGETS = 368,
     MAX_WATCH = 369,
     MESSAGE_LOCALE = 370,
     MIN_NONWILDCARD = 371,
     MIN_NONWILDCARD_SIMPLE = 372,
     MODULE = 373,
     MODULES = 374,
     NAME = 375,
     NEED_PASSWORD = 376,
     NETWORK_DESC = 377,
     NETWORK_NAME = 378,
     NICK = 379,
     NICK_CHANGES = 380,
     NO_CREATE_ON_SPLIT = 381,
     NO_JOIN_ON_SPLIT = 382,
     NO_OPER_FLOOD = 383,
     NO_TILDE = 384,
     NOT = 385,
     NUMBER = 386,
     NUMBER_PER_IDENT = 387,
     NUMBER_PER_CIDR = 388,
     NUMBER_PER_IP = 389,
     NUMBER_PER_IP_GLOBAL = 390,
     OPERATOR = 391,
     OPERS_BYPASS_CALLERID = 392,
     OPER_LOG = 393,
     OPER_ONLY_UMODES = 394,
     OPER_PASS_RESV = 395,
     OPER_SPY_T = 396,
     OPER_UMODES = 397,
     JOIN_FLOOD_COUNT = 398,
     JOIN_FLOOD_TIME = 399,
     PACE_WAIT = 400,
     PACE_WAIT_SIMPLE = 401,
     PASSWORD = 402,
     PATH = 403,
     PING_COOKIE = 404,
     PING_TIME = 405,
     PING_WARNING = 406,
     PORT = 407,
     QSTRING = 408,
     QUIET_ON_BAN = 409,
     REASON = 410,
     REDIRPORT = 411,
     REDIRSERV = 412,
     REGEX_T = 413,
     REHASH = 414,
     TREJECT_HOLD_TIME = 415,
     REMOTE = 416,
     REMOTEBAN = 417,
     RESTRICT_CHANNELS = 418,
     RESTRICTED = 419,
     RSA_PRIVATE_KEY_FILE = 420,
     RSA_PUBLIC_KEY_FILE = 421,
     SSL_CERTIFICATE_FILE = 422,
     T_SSL_CONNECTION_METHOD = 423,
     T_SSLV3 = 424,
     T_TLSV1 = 425,
     RESV = 426,
     RESV_EXEMPT = 427,
     SECONDS = 428,
     MINUTES = 429,
     HOURS = 430,
     DAYS = 431,
     WEEKS = 432,
     SENDQ = 433,
     SEND_PASSWORD = 434,
     SERVERHIDE = 435,
     SERVERINFO = 436,
     SERVLINK_PATH = 437,
     IRCD_SID = 438,
     TKLINE_EXPIRE_NOTICES = 439,
     T_SHARED = 440,
     T_CLUSTER = 441,
     TYPE = 442,
     SHORT_MOTD = 443,
     SILENT = 444,
     SPOOF = 445,
     SPOOF_NOTICE = 446,
     STATS_E_DISABLED = 447,
     STATS_I_OPER_ONLY = 448,
     STATS_K_OPER_ONLY = 449,
     STATS_O_OPER_ONLY = 450,
     STATS_P_OPER_ONLY = 451,
     TBOOL = 452,
     TMASKED = 453,
     T_REJECT = 454,
     TS_MAX_DELTA = 455,
     TS_WARN_DELTA = 456,
     TWODOTS = 457,
     T_ALL = 458,
     T_BOTS = 459,
     T_SOFTCALLERID = 460,
     T_CALLERID = 461,
     T_CCONN = 462,
     T_CCONN_FULL = 463,
     T_CLIENT_FLOOD = 464,
     T_DEAF = 465,
     T_DEBUG = 466,
     T_DRONE = 467,
     T_EXTERNAL = 468,
     T_FULL = 469,
     T_INVISIBLE = 470,
     T_IPV4 = 471,
     T_IPV6 = 472,
     T_LOCOPS = 473,
     T_LOGPATH = 474,
     T_L_CRIT = 475,
     T_L_DEBUG = 476,
     T_L_ERROR = 477,
     T_L_INFO = 478,
     T_L_NOTICE = 479,
     T_L_TRACE = 480,
     T_L_WARN = 481,
     T_MAX_CLIENTS = 482,
     T_NCHANGE = 483,
     T_OPERWALL = 484,
     T_REJ = 485,
     T_SERVER = 486,
     T_SERVNOTICE = 487,
     T_SKILL = 488,
     T_SPY = 489,
     T_SSL = 490,
     T_UMODES = 491,
     T_UNAUTH = 492,
     T_UNRESV = 493,
     T_UNXLINE = 494,
     T_WALLOP = 495,
     T_SERVICE = 496,
     T_SERVICE_NAME = 497,
     THROTTLE_TIME = 498,
     TOPICBURST = 499,
     TRUE_NO_OPER_FLOOD = 500,
     TKLINE = 501,
     TXLINE = 502,
     TRESV = 503,
     UNKLINE = 504,
     USER = 505,
     USE_EGD = 506,
     USE_EXCEPT = 507,
     USE_INVEX = 508,
     USE_KNOCK = 509,
     USE_LOGGING = 510,
     USE_WHOIS_ACTUALLY = 511,
     VHOST = 512,
     VHOST6 = 513,
     XLINE = 514,
     WARN = 515,
     WARN_NO_NLINE = 516
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
#define IRCD_FLAGS 308
#define FLATTEN_LINKS 309
#define FFAILED_OPERLOG 310
#define FKILLLOG 311
#define FKLINELOG 312
#define FGLINELOG 313
#define FIOERRLOG 314
#define FOPERLOG 315
#define FOPERSPYLOG 316
#define FUSERLOG 317
#define GECOS 318
#define GENERAL 319
#define GLINE 320
#define GLINES 321
#define GLINE_EXEMPT 322
#define GLINE_LOG 323
#define GLINE_TIME 324
#define GLINE_MIN_CIDR 325
#define GLINE_MIN_CIDR6 326
#define GLOBAL_KILL 327
#define IRCD_AUTH 328
#define NEED_IDENT 329
#define HAVENT_READ_CONF 330
#define HIDDEN 331
#define HIDDEN_ADMIN 332
#define HIDDEN_NAME 333
#define HIDDEN_OPER 334
#define HIDE_SERVER_IPS 335
#define HIDE_SERVERS 336
#define HIDE_SPOOF_IPS 337
#define HOST 338
#define HUB 339
#define HUB_MASK 340
#define IDLETIME 341
#define IGNORE_BOGUS_TS 342
#define INVISIBLE_ON_CONNECT 343
#define IP 344
#define KILL 345
#define KILL_CHASE_TIME_LIMIT 346
#define KLINE 347
#define KLINE_EXEMPT 348
#define KLINE_REASON 349
#define KLINE_WITH_REASON 350
#define KNOCK_DELAY 351
#define KNOCK_DELAY_CHANNEL 352
#define LEAF_MASK 353
#define LINKS_DELAY 354
#define LISTEN 355
#define T_LOG 356
#define LOGGING 357
#define LOG_LEVEL 358
#define MAX_ACCEPT 359
#define MAX_BANS 360
#define MAX_CHANS_PER_USER 361
#define MAX_GLOBAL 362
#define MAX_IDENT 363
#define MAX_LOCAL 364
#define MAX_NICK_CHANGES 365
#define MAX_NICK_TIME 366
#define MAX_NUMBER 367
#define MAX_TARGETS 368
#define MAX_WATCH 369
#define MESSAGE_LOCALE 370
#define MIN_NONWILDCARD 371
#define MIN_NONWILDCARD_SIMPLE 372
#define MODULE 373
#define MODULES 374
#define NAME 375
#define NEED_PASSWORD 376
#define NETWORK_DESC 377
#define NETWORK_NAME 378
#define NICK 379
#define NICK_CHANGES 380
#define NO_CREATE_ON_SPLIT 381
#define NO_JOIN_ON_SPLIT 382
#define NO_OPER_FLOOD 383
#define NO_TILDE 384
#define NOT 385
#define NUMBER 386
#define NUMBER_PER_IDENT 387
#define NUMBER_PER_CIDR 388
#define NUMBER_PER_IP 389
#define NUMBER_PER_IP_GLOBAL 390
#define OPERATOR 391
#define OPERS_BYPASS_CALLERID 392
#define OPER_LOG 393
#define OPER_ONLY_UMODES 394
#define OPER_PASS_RESV 395
#define OPER_SPY_T 396
#define OPER_UMODES 397
#define JOIN_FLOOD_COUNT 398
#define JOIN_FLOOD_TIME 399
#define PACE_WAIT 400
#define PACE_WAIT_SIMPLE 401
#define PASSWORD 402
#define PATH 403
#define PING_COOKIE 404
#define PING_TIME 405
#define PING_WARNING 406
#define PORT 407
#define QSTRING 408
#define QUIET_ON_BAN 409
#define REASON 410
#define REDIRPORT 411
#define REDIRSERV 412
#define REGEX_T 413
#define REHASH 414
#define TREJECT_HOLD_TIME 415
#define REMOTE 416
#define REMOTEBAN 417
#define RESTRICT_CHANNELS 418
#define RESTRICTED 419
#define RSA_PRIVATE_KEY_FILE 420
#define RSA_PUBLIC_KEY_FILE 421
#define SSL_CERTIFICATE_FILE 422
#define T_SSL_CONNECTION_METHOD 423
#define T_SSLV3 424
#define T_TLSV1 425
#define RESV 426
#define RESV_EXEMPT 427
#define SECONDS 428
#define MINUTES 429
#define HOURS 430
#define DAYS 431
#define WEEKS 432
#define SENDQ 433
#define SEND_PASSWORD 434
#define SERVERHIDE 435
#define SERVERINFO 436
#define SERVLINK_PATH 437
#define IRCD_SID 438
#define TKLINE_EXPIRE_NOTICES 439
#define T_SHARED 440
#define T_CLUSTER 441
#define TYPE 442
#define SHORT_MOTD 443
#define SILENT 444
#define SPOOF 445
#define SPOOF_NOTICE 446
#define STATS_E_DISABLED 447
#define STATS_I_OPER_ONLY 448
#define STATS_K_OPER_ONLY 449
#define STATS_O_OPER_ONLY 450
#define STATS_P_OPER_ONLY 451
#define TBOOL 452
#define TMASKED 453
#define T_REJECT 454
#define TS_MAX_DELTA 455
#define TS_WARN_DELTA 456
#define TWODOTS 457
#define T_ALL 458
#define T_BOTS 459
#define T_SOFTCALLERID 460
#define T_CALLERID 461
#define T_CCONN 462
#define T_CCONN_FULL 463
#define T_CLIENT_FLOOD 464
#define T_DEAF 465
#define T_DEBUG 466
#define T_DRONE 467
#define T_EXTERNAL 468
#define T_FULL 469
#define T_INVISIBLE 470
#define T_IPV4 471
#define T_IPV6 472
#define T_LOCOPS 473
#define T_LOGPATH 474
#define T_L_CRIT 475
#define T_L_DEBUG 476
#define T_L_ERROR 477
#define T_L_INFO 478
#define T_L_NOTICE 479
#define T_L_TRACE 480
#define T_L_WARN 481
#define T_MAX_CLIENTS 482
#define T_NCHANGE 483
#define T_OPERWALL 484
#define T_REJ 485
#define T_SERVER 486
#define T_SERVNOTICE 487
#define T_SKILL 488
#define T_SPY 489
#define T_SSL 490
#define T_UMODES 491
#define T_UNAUTH 492
#define T_UNRESV 493
#define T_UNXLINE 494
#define T_WALLOP 495
#define T_SERVICE 496
#define T_SERVICE_NAME 497
#define THROTTLE_TIME 498
#define TOPICBURST 499
#define TRUE_NO_OPER_FLOOD 500
#define TKLINE 501
#define TXLINE 502
#define TRESV 503
#define UNKLINE 504
#define USER 505
#define USE_EGD 506
#define USE_EXCEPT 507
#define USE_INVEX 508
#define USE_KNOCK 509
#define USE_LOGGING 510
#define USE_WHOIS_ACTUALLY 511
#define VHOST 512
#define VHOST6 513
#define XLINE 514
#define WARN 515
#define WARN_NO_NLINE 516




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 743 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 755 "ircd_parser.c"

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
#define YYLAST   1257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  267
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  323
/* YYNRULES -- Number of rules.  */
#define YYNRULES  696
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1373

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   516

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   266,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   262,
       2,   265,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   264,     2,   263,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259,   260,   261
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
    1469,  1474,  1479,  1484,  1489,  1494,  1499,  1504,  1509,  1514,
    1519,  1524,  1529,  1534,  1539,  1544,  1549,  1554,  1559,  1564,
    1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,  1609,  1614,
    1619,  1624,  1629,  1634,  1639,  1644,  1649,  1654,  1659,  1664,
    1669,  1674,  1679,  1684,  1689,  1694,  1699,  1704,  1709,  1714,
    1719,  1724,  1729,  1730,  1736,  1740,  1742,  1744,  1746,  1748,
    1750,  1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,  1768,
    1770,  1772,  1774,  1776,  1778,  1780,  1781,  1787,  1791,  1793,
    1795,  1797,  1799,  1801,  1803,  1805,  1807,  1809,  1811,  1813,
    1815,  1817,  1819,  1821,  1823,  1825,  1827,  1829,  1831,  1836,
    1841,  1846,  1851,  1852,  1859,  1862,  1864,  1866,  1868,  1870,
    1872,  1874,  1876,  1878,  1883,  1888,  1889,  1895,  1899,  1901,
    1903,  1905,  1910,  1915,  1916,  1922,  1926,  1928,  1930,  1932,
    1938,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,  1957,
    1959,  1961,  1963,  1965,  1967,  1969,  1971,  1973,  1975,  1977,
    1979,  1981,  1986,  1991,  1996,  2001,  2006,  2011,  2016,  2021,
    2026,  2031,  2036,  2041,  2046,  2051,  2056,  2061,  2066,  2071,
    2077,  2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2096,
    2098,  2103,  2108,  2113,  2118,  2123,  2128
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     268,     0,    -1,    -1,   268,   269,    -1,   297,    -1,   303,
      -1,   318,    -1,   559,    -1,   341,    -1,   360,    -1,   374,
      -1,   279,    -1,   580,    -1,   392,    -1,   399,    -1,   403,
      -1,   413,    -1,   422,    -1,   448,    -1,   458,    -1,   464,
      -1,   478,    -1,   543,    -1,   468,    -1,   274,    -1,     1,
     262,    -1,     1,   263,    -1,    -1,   271,    -1,   131,   270,
      -1,   131,   173,   270,    -1,   131,   174,   270,    -1,   131,
     175,   270,    -1,   131,   176,   270,    -1,   131,   177,   270,
      -1,    -1,   273,    -1,   131,   272,    -1,   131,    14,   272,
      -1,   131,    15,   272,    -1,   131,    16,   272,    -1,   119,
     264,   275,   263,   262,    -1,   275,   276,    -1,   276,    -1,
     277,    -1,   278,    -1,     1,   262,    -1,   118,   265,   153,
     262,    -1,   148,   265,   153,   262,    -1,   181,   264,   280,
     263,   262,    -1,   280,   281,    -1,   281,    -1,   288,    -1,
     293,    -1,   296,    -1,   290,    -1,   291,    -1,   292,    -1,
     295,    -1,   287,    -1,   294,    -1,   289,    -1,   286,    -1,
     282,    -1,     1,   262,    -1,    -1,   168,   283,   265,   284,
     262,    -1,   284,   266,   285,    -1,   285,    -1,   169,    -1,
     170,    -1,   167,   265,   153,   262,    -1,   165,   265,   153,
     262,    -1,   120,   265,   153,   262,    -1,   183,   265,   153,
     262,    -1,    37,   265,   153,   262,    -1,   123,   265,   153,
     262,    -1,   122,   265,   153,   262,    -1,   257,   265,   153,
     262,    -1,   258,   265,   153,   262,    -1,   227,   265,   131,
     262,    -1,    84,   265,   197,   262,    -1,     5,   264,   298,
     263,   262,    -1,   298,   299,    -1,   299,    -1,   300,    -1,
     302,    -1,   301,    -1,     1,   262,    -1,   120,   265,   153,
     262,    -1,    47,   265,   153,   262,    -1,    37,   265,   153,
     262,    -1,   102,   264,   304,   263,   262,    -1,   304,   305,
      -1,   305,    -1,   306,    -1,   307,    -1,   316,    -1,   317,
      -1,   308,    -1,   310,    -1,   312,    -1,   313,    -1,   315,
      -1,   311,    -1,   314,    -1,   309,    -1,     1,   262,    -1,
     219,   265,   153,   262,    -1,   138,   265,   153,   262,    -1,
      62,   265,   153,   262,    -1,    55,   265,   153,   262,    -1,
      60,   265,   153,   262,    -1,    61,   265,   153,   262,    -1,
      58,   265,   153,   262,    -1,    57,   265,   153,   262,    -1,
      59,   265,   153,   262,    -1,    56,   265,   153,   262,    -1,
     103,   265,   220,   262,    -1,   103,   265,   222,   262,    -1,
     103,   265,   226,   262,    -1,   103,   265,   224,   262,    -1,
     103,   265,   225,   262,    -1,   103,   265,   223,   262,    -1,
     103,   265,   221,   262,    -1,   255,   265,   197,   262,    -1,
      -1,   136,   319,   320,   264,   321,   263,   262,    -1,    -1,
     324,    -1,   321,   322,    -1,   322,    -1,   323,    -1,   325,
      -1,   326,    -1,   330,    -1,   329,    -1,   327,    -1,   328,
      -1,   334,    -1,     1,   262,    -1,   120,   265,   153,   262,
      -1,   153,    -1,   250,   265,   153,   262,    -1,   147,   265,
     153,   262,    -1,    49,   265,   197,   262,    -1,   166,   265,
     153,   262,    -1,    26,   265,   153,   262,    -1,    -1,   236,
     331,   265,   332,   262,    -1,   332,   266,   333,    -1,   333,
      -1,   204,    -1,   207,    -1,   208,    -1,   210,    -1,   211,
      -1,   214,    -1,   233,    -1,   228,    -1,   230,    -1,   237,
      -1,   234,    -1,   213,    -1,   229,    -1,   232,    -1,   215,
      -1,   240,    -1,   205,    -1,   206,    -1,   218,    -1,    -1,
      53,   335,   265,   336,   262,    -1,   336,   266,   337,    -1,
     337,    -1,    -1,   130,   338,   340,    -1,    -1,   339,   340,
      -1,    72,    -1,   161,    -1,    92,    -1,   249,    -1,   259,
      -1,    65,    -1,    38,    -1,   159,    -1,     5,    -1,    77,
      -1,   125,    -1,   229,    -1,   141,    -1,    79,    -1,   162,
      -1,    49,    -1,    -1,    26,   342,   343,   264,   344,   263,
     262,    -1,    -1,   347,    -1,   344,   345,    -1,   345,    -1,
     346,    -1,   357,    -1,   358,    -1,   348,    -1,   349,    -1,
     359,    -1,   350,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,     1,   262,    -1,   120,
     265,   153,   262,    -1,   153,    -1,   150,   265,   271,   262,
      -1,   151,   265,   271,   262,    -1,   134,   265,   131,   262,
      -1,    30,   265,   271,   262,    -1,   112,   265,   131,   262,
      -1,   107,   265,   131,   262,    -1,   109,   265,   131,   262,
      -1,   108,   265,   131,   262,    -1,   178,   265,   273,   262,
      -1,    23,   265,   131,   262,    -1,    24,   265,   131,   262,
      -1,   133,   265,   131,   262,    -1,    -1,   100,   361,   264,
     366,   263,   262,    -1,    -1,    53,   363,   265,   364,   262,
      -1,   364,   266,   365,    -1,   365,    -1,   235,    -1,    76,
      -1,   231,    -1,   366,   367,    -1,   367,    -1,   368,    -1,
     362,    -1,   372,    -1,   373,    -1,     1,   262,    -1,    -1,
     152,   265,   370,   369,   262,    -1,   370,   266,   371,    -1,
     371,    -1,   131,    -1,   131,   202,   131,    -1,    89,   265,
     153,   262,    -1,    83,   265,   153,   262,    -1,    -1,    73,
     375,   264,   376,   263,   262,    -1,   376,   377,    -1,   377,
      -1,   378,    -1,   379,    -1,   380,    -1,   382,    -1,   389,
      -1,   390,    -1,   391,    -1,   381,    -1,     1,   262,    -1,
     250,   265,   153,   262,    -1,   147,   265,   153,   262,    -1,
      26,   265,   153,   262,    -1,    49,   265,   197,   262,    -1,
      -1,    53,   383,   265,   384,   262,    -1,   384,   266,   385,
      -1,   385,    -1,    -1,   130,   386,   388,    -1,    -1,   387,
     388,    -1,   191,    -1,    50,    -1,    93,    -1,    74,    -1,
      20,    -1,    21,    -1,   129,    -1,    67,    -1,   172,    -1,
     121,    -1,   190,   265,   153,   262,    -1,   157,   265,   153,
     262,    -1,   156,   265,   131,   262,    -1,    -1,   171,   393,
     264,   394,   263,   262,    -1,   394,   395,    -1,   395,    -1,
     396,    -1,   397,    -1,   398,    -1,     1,   262,    -1,   155,
     265,   153,   262,    -1,    22,   265,   153,   262,    -1,   124,
     265,   153,   262,    -1,   241,   264,   400,   263,   262,    -1,
     400,   401,    -1,   401,    -1,   402,    -1,     1,    -1,   120,
     265,   153,   262,    -1,    -1,   185,   404,   264,   405,   263,
     262,    -1,   405,   406,    -1,   406,    -1,   407,    -1,   408,
      -1,   409,    -1,     1,   262,    -1,   120,   265,   153,   262,
      -1,   250,   265,   153,   262,    -1,    -1,   187,   410,   265,
     411,   262,    -1,   411,   266,   412,    -1,   412,    -1,    92,
      -1,   246,    -1,   249,    -1,   259,    -1,   247,    -1,   239,
      -1,   171,    -1,   248,    -1,   238,    -1,   218,    -1,   203,
      -1,    -1,   186,   414,   264,   415,   263,   262,    -1,   415,
     416,    -1,   416,    -1,   417,    -1,   418,    -1,     1,   262,
      -1,   120,   265,   153,   262,    -1,    -1,   187,   419,   265,
     420,   262,    -1,   420,   266,   421,    -1,   421,    -1,    92,
      -1,   246,    -1,   249,    -1,   259,    -1,   247,    -1,   239,
      -1,   171,    -1,   248,    -1,   238,    -1,   218,    -1,   203,
      -1,    -1,    29,   423,   424,   264,   425,   263,   262,    -1,
      -1,   428,    -1,   425,   426,    -1,   426,    -1,   427,    -1,
     429,    -1,   430,    -1,   431,    -1,   432,    -1,   434,    -1,
     433,    -1,   435,    -1,   444,    -1,   445,    -1,   446,    -1,
     443,    -1,   442,    -1,   447,    -1,     1,   262,    -1,   120,
     265,   153,   262,    -1,   153,    -1,    83,   265,   153,   262,
      -1,   257,   265,   153,   262,    -1,   179,   265,   153,   262,
      -1,     3,   265,   153,   262,    -1,   152,   265,   131,   262,
      -1,     6,   265,   216,   262,    -1,     6,   265,   217,   262,
      -1,    -1,    53,   436,   265,   437,   262,    -1,   437,   266,
     438,    -1,   438,    -1,    -1,   130,   439,   441,    -1,    -1,
     440,   441,    -1,    27,    -1,    31,    -1,    10,    -1,    12,
      -1,   244,    -1,   166,   265,   153,   262,    -1,    49,   265,
     197,   262,    -1,    85,   265,   153,   262,    -1,    98,   265,
     153,   262,    -1,    26,   265,   153,   262,    -1,    25,   265,
     153,   262,    -1,    -1,    90,   449,   264,   454,   263,   262,
      -1,    -1,   187,   451,   265,   452,   262,    -1,   452,   266,
     453,    -1,   453,    -1,   158,    -1,   454,   455,    -1,   455,
      -1,   456,    -1,   457,    -1,   450,    -1,     1,    -1,   250,
     265,   153,   262,    -1,   155,   265,   153,   262,    -1,    -1,
      36,   459,   264,   460,   263,   262,    -1,   460,   461,    -1,
     461,    -1,   462,    -1,   463,    -1,     1,    -1,    89,   265,
     153,   262,    -1,   155,   265,   153,   262,    -1,    51,   264,
     465,   263,   262,    -1,   465,   466,    -1,   466,    -1,   467,
      -1,     1,    -1,    89,   265,   153,   262,    -1,    -1,    63,
     469,   264,   474,   263,   262,    -1,    -1,   187,   471,   265,
     472,   262,    -1,   472,   266,   473,    -1,   473,    -1,   158,
      -1,   474,   475,    -1,   475,    -1,   476,    -1,   477,    -1,
     470,    -1,     1,    -1,   120,   265,   153,   262,    -1,   155,
     265,   153,   262,    -1,    64,   264,   479,   263,   262,    -1,
     479,   480,    -1,   480,    -1,   489,    -1,   490,    -1,   492,
      -1,   493,    -1,   494,    -1,   495,    -1,   496,    -1,   497,
      -1,   498,    -1,   499,    -1,   488,    -1,   501,    -1,   502,
      -1,   503,    -1,   504,    -1,   520,    -1,   506,    -1,   508,
      -1,   510,    -1,   509,    -1,   513,    -1,   507,    -1,   514,
      -1,   515,    -1,   516,    -1,   517,    -1,   519,    -1,   518,
      -1,   535,    -1,   521,    -1,   525,    -1,   526,    -1,   531,
      -1,   511,    -1,   512,    -1,   541,    -1,   539,    -1,   540,
      -1,   522,    -1,   491,    -1,   523,    -1,   524,    -1,   542,
      -1,   530,    -1,   500,    -1,   528,    -1,   529,    -1,   484,
      -1,   487,    -1,   482,    -1,   483,    -1,   485,    -1,   486,
      -1,   505,    -1,   481,    -1,   527,    -1,     1,    -1,   114,
     265,   131,   262,    -1,    70,   265,   131,   262,    -1,    71,
     265,   131,   262,    -1,    12,   265,   197,   262,    -1,   256,
     265,   197,   262,    -1,   160,   265,   271,   262,    -1,   184,
     265,   197,   262,    -1,    91,   265,   271,   262,    -1,    82,
     265,   197,   262,    -1,    87,   265,   197,   262,    -1,    43,
     265,   197,   262,    -1,    52,   265,   197,   262,    -1,     8,
     265,   197,   262,    -1,   111,   265,   271,   262,    -1,   110,
     265,   131,   262,    -1,   104,   265,   131,   262,    -1,     9,
     265,   271,   262,    -1,   201,   265,   271,   262,    -1,   200,
     265,   271,   262,    -1,    75,   265,   131,   262,    -1,    95,
     265,   197,   262,    -1,    94,   265,   153,   262,    -1,    88,
     265,   197,   262,    -1,   261,   265,   197,   262,    -1,   192,
     265,   197,   262,    -1,   195,   265,   197,   262,    -1,   196,
     265,   197,   262,    -1,   194,   265,   197,   262,    -1,   194,
     265,   198,   262,    -1,   193,   265,   197,   262,    -1,   193,
     265,   198,   262,    -1,   145,   265,   271,   262,    -1,    19,
     265,   271,   262,    -1,   137,   265,   197,   262,    -1,   146,
     265,   271,   262,    -1,   188,   265,   197,   262,    -1,   128,
     265,   197,   262,    -1,   245,   265,   197,   262,    -1,   140,
     265,   197,   262,    -1,   115,   265,   153,   262,    -1,    86,
     265,   271,   262,    -1,    44,   265,   131,   262,    -1,   113,
     265,   131,   262,    -1,   182,   265,   153,   262,    -1,    32,
     265,   153,   262,    -1,    28,   265,   131,   262,    -1,   251,
     265,   197,   262,    -1,    46,   265,   153,   262,    -1,   242,
     265,   153,   262,    -1,   149,   265,   197,   262,    -1,    39,
     265,   197,   262,    -1,   243,   265,   271,   262,    -1,    -1,
     142,   532,   265,   533,   262,    -1,   533,   266,   534,    -1,
     534,    -1,   204,    -1,   207,    -1,   208,    -1,   210,    -1,
     211,    -1,   214,    -1,   233,    -1,   228,    -1,   230,    -1,
     237,    -1,   234,    -1,   213,    -1,   229,    -1,   232,    -1,
     215,    -1,   240,    -1,   205,    -1,   206,    -1,   218,    -1,
      -1,   139,   536,   265,   537,   262,    -1,   537,   266,   538,
      -1,   538,    -1,   204,    -1,   207,    -1,   208,    -1,   210,
      -1,   211,    -1,   214,    -1,   233,    -1,   228,    -1,   230,
      -1,   237,    -1,   234,    -1,   213,    -1,   229,    -1,   232,
      -1,   215,    -1,   240,    -1,   205,    -1,   206,    -1,   218,
      -1,   116,   265,   131,   262,    -1,   117,   265,   131,   262,
      -1,    33,   265,   131,   262,    -1,   209,   265,   273,   262,
      -1,    -1,    66,   544,   264,   545,   263,   262,    -1,   545,
     546,    -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,
     553,    -1,   554,    -1,   555,    -1,     1,    -1,    48,   265,
     197,   262,    -1,    45,   265,   271,   262,    -1,    -1,   102,
     550,   265,   551,   262,    -1,   551,   266,   552,    -1,   552,
      -1,   199,    -1,    11,    -1,   250,   265,   153,   262,    -1,
     120,   265,   153,   262,    -1,    -1,     4,   556,   265,   557,
     262,    -1,   557,   266,   558,    -1,   558,    -1,   199,    -1,
      11,    -1,    22,   264,   560,   263,   262,    -1,   560,   561,
      -1,   561,    -1,   564,    -1,   565,    -1,   566,    -1,   567,
      -1,   572,    -1,   568,    -1,   569,    -1,   570,    -1,   571,
      -1,   573,    -1,   574,    -1,   575,    -1,   563,    -1,   576,
      -1,   577,    -1,   578,    -1,   579,    -1,   562,    -1,     1,
      -1,    40,   265,   197,   262,    -1,   163,   265,   197,   262,
      -1,    42,   265,   197,   262,    -1,   252,   265,   197,   262,
      -1,   253,   265,   197,   262,    -1,   254,   265,   197,   262,
      -1,    96,   265,   271,   262,    -1,    97,   265,   271,   262,
      -1,   106,   265,   131,   262,    -1,   154,   265,   197,   262,
      -1,   105,   265,   131,   262,    -1,    35,   265,   131,   262,
      -1,    34,   265,   131,   262,    -1,   126,   265,   197,   262,
      -1,   127,   265,   197,   262,    -1,    13,   265,   197,   262,
      -1,   143,   265,   131,   262,    -1,   144,   265,   271,   262,
      -1,   180,   264,   581,   263,   262,    -1,   581,   582,    -1,
     582,    -1,   583,    -1,   584,    -1,   586,    -1,   588,    -1,
     587,    -1,   585,    -1,   589,    -1,     1,    -1,    54,   265,
     197,   262,    -1,    81,   265,   197,   262,    -1,    78,   265,
     153,   262,    -1,    99,   265,   271,   262,    -1,    76,   265,
     197,   262,    -1,    41,   265,   197,   262,    -1,    80,   265,
     197,   262,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   396,   396,   397,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   426,   426,   427,
     431,   435,   439,   443,   447,   453,   453,   454,   455,   456,
     457,   464,   467,   467,   468,   468,   468,   470,   476,   483,
     485,   485,   486,   486,   487,   487,   488,   488,   489,   490,
     490,   491,   491,   492,   493,   497,   496,   515,   515,   516,
     522,   530,   564,   624,   639,   654,   663,   677,   686,   714,
     744,   767,   776,   778,   778,   779,   779,   780,   780,   782,
     791,   800,   813,   815,   816,   818,   818,   819,   820,   820,
     821,   821,   822,   822,   823,   823,   824,   825,   827,   831,
     835,   842,   849,   856,   863,   870,   877,   884,   891,   895,
     899,   903,   907,   911,   915,   921,   931,   930,  1024,  1024,
    1025,  1025,  1026,  1026,  1026,  1027,  1027,  1027,  1028,  1028,
    1028,  1030,  1042,  1054,  1088,  1100,  1111,  1153,  1163,  1162,
    1168,  1168,  1169,  1173,  1177,  1181,  1185,  1189,  1193,  1197,
    1201,  1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,
    1241,  1248,  1247,  1251,  1251,  1252,  1252,  1253,  1253,  1255,
    1262,  1269,  1276,  1283,  1290,  1297,  1304,  1311,  1318,  1325,
    1332,  1339,  1346,  1353,  1360,  1374,  1373,  1423,  1423,  1425,
    1425,  1426,  1427,  1427,  1428,  1429,  1430,  1431,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1440,  1449,  1458,  1464,  1470,
    1476,  1482,  1488,  1494,  1500,  1506,  1512,  1518,  1524,  1534,
    1533,  1550,  1549,  1554,  1554,  1555,  1559,  1563,  1571,  1571,
    1572,  1572,  1572,  1572,  1572,  1574,  1574,  1576,  1576,  1578,
    1592,  1612,  1621,  1634,  1633,  1702,  1702,  1703,  1703,  1703,
    1703,  1704,  1704,  1704,  1705,  1705,  1707,  1744,  1757,  1766,
    1778,  1777,  1781,  1781,  1782,  1782,  1783,  1783,  1785,  1792,
    1799,  1806,  1813,  1820,  1827,  1834,  1841,  1848,  1858,  1877,
    1887,  1901,  1900,  1916,  1916,  1917,  1917,  1917,  1917,  1919,
    1928,  1943,  1956,  1958,  1958,  1959,  1959,  1961,  1977,  1976,
    1992,  1992,  1993,  1993,  1993,  1993,  1995,  2004,  2027,  2026,
    2032,  2032,  2033,  2037,  2041,  2045,  2049,  2053,  2057,  2061,
    2065,  2069,  2073,  2083,  2082,  2099,  2099,  2100,  2100,  2100,
    2102,  2109,  2108,  2114,  2114,  2115,  2119,  2123,  2127,  2131,
    2135,  2139,  2143,  2147,  2151,  2155,  2165,  2164,  2310,  2310,
    2311,  2311,  2312,  2312,  2312,  2313,  2313,  2314,  2314,  2315,
    2315,  2315,  2316,  2316,  2317,  2317,  2318,  2320,  2332,  2344,
    2353,  2379,  2397,  2415,  2421,  2425,  2434,  2433,  2437,  2437,
    2438,  2438,  2439,  2439,  2441,  2452,  2459,  2466,  2473,  2483,
    2524,  2535,  2548,  2561,  2570,  2606,  2605,  2669,  2668,  2672,
    2672,  2673,  2679,  2679,  2680,  2680,  2680,  2680,  2682,  2701,
    2711,  2710,  2733,  2733,  2734,  2734,  2734,  2736,  2742,  2751,
    2753,  2753,  2754,  2754,  2756,  2775,  2774,  2822,  2821,  2825,
    2825,  2826,  2832,  2832,  2833,  2833,  2833,  2833,  2835,  2841,
    2850,  2853,  2853,  2854,  2854,  2855,  2855,  2856,  2856,  2857,
    2857,  2858,  2858,  2859,  2859,  2860,  2860,  2861,  2861,  2862,
    2862,  2863,  2863,  2864,  2864,  2865,  2865,  2866,  2866,  2867,
    2867,  2868,  2868,  2869,  2869,  2870,  2870,  2871,  2871,  2872,
    2872,  2873,  2873,  2874,  2875,  2875,  2876,  2876,  2877,  2878,
    2878,  2879,  2879,  2880,  2880,  2881,  2881,  2882,  2882,  2883,
    2886,  2891,  2896,  2901,  2906,  2911,  2916,  2921,  2926,  2931,
    2936,  2941,  2946,  2951,  2956,  2961,  2966,  2971,  2976,  2982,
    2993,  2998,  3007,  3012,  3017,  3022,  3027,  3032,  3035,  3040,
    3043,  3048,  3053,  3058,  3063,  3068,  3073,  3078,  3083,  3088,
    3099,  3104,  3109,  3114,  3123,  3155,  3173,  3178,  3187,  3196,
    3201,  3206,  3212,  3211,  3216,  3216,  3217,  3220,  3223,  3226,
    3229,  3232,  3235,  3238,  3241,  3244,  3247,  3250,  3253,  3256,
    3259,  3262,  3265,  3268,  3271,  3277,  3276,  3281,  3281,  3282,
    3285,  3288,  3291,  3294,  3297,  3300,  3303,  3306,  3309,  3312,
    3315,  3318,  3321,  3324,  3327,  3330,  3333,  3336,  3341,  3346,
    3351,  3356,  3366,  3365,  3389,  3389,  3390,  3391,  3392,  3393,
    3394,  3395,  3396,  3398,  3404,  3411,  3410,  3415,  3415,  3416,
    3420,  3426,  3460,  3470,  3469,  3519,  3519,  3520,  3524,  3533,
    3536,  3536,  3537,  3537,  3538,  3538,  3539,  3539,  3540,  3540,
    3541,  3541,  3542,  3543,  3543,  3544,  3544,  3545,  3545,  3546,
    3546,  3548,  3553,  3558,  3563,  3568,  3573,  3578,  3583,  3588,
    3593,  3598,  3603,  3608,  3613,  3618,  3623,  3628,  3633,  3641,
    3644,  3644,  3645,  3645,  3646,  3647,  3648,  3648,  3649,  3650,
    3652,  3658,  3664,  3673,  3687,  3693,  3699
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
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
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
  "T_SERVICE", "T_SERVICE_NAME", "THROTTLE_TIME", "TOPICBURST",
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
  "general_message_locale", "general_idletime", "general_dots_in_ident",
  "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_service_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@29", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@30", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "gline_entry",
  "$@31", "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "$@32", "gline_logging_types",
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action",
  "$@33", "gdeny_types", "gdeny_type_item", "channel_entry",
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
     515,   516,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   267,   268,   268,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   270,   270,   271,
     271,   271,   271,   271,   271,   272,   272,   273,   273,   273,
     273,   274,   275,   275,   276,   276,   276,   277,   278,   279,
     280,   280,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   283,   282,   284,   284,   285,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   298,   299,   299,   299,   299,   300,
     301,   302,   303,   304,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   316,
     316,   316,   316,   316,   316,   317,   319,   318,   320,   320,
     321,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   323,   324,   325,   326,   327,   328,   329,   331,   330,
     332,   332,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   335,   334,   336,   336,   338,   337,   339,   337,   340,
     340,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     340,   340,   340,   340,   340,   342,   341,   343,   343,   344,
     344,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   361,
     360,   363,   362,   364,   364,   365,   365,   365,   366,   366,
     367,   367,   367,   367,   367,   369,   368,   370,   370,   371,
     371,   372,   373,   375,   374,   376,   376,   377,   377,   377,
     377,   377,   377,   377,   377,   377,   378,   379,   380,   381,
     383,   382,   384,   384,   386,   385,   387,   385,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   389,   390,
     391,   393,   392,   394,   394,   395,   395,   395,   395,   396,
     397,   398,   399,   400,   400,   401,   401,   402,   404,   403,
     405,   405,   406,   406,   406,   406,   407,   408,   410,   409,
     411,   411,   412,   412,   412,   412,   412,   412,   412,   412,
     412,   412,   412,   414,   413,   415,   415,   416,   416,   416,
     417,   419,   418,   420,   420,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   423,   422,   424,   424,
     425,   425,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   434,   436,   435,   437,   437,
     439,   438,   440,   438,   441,   441,   441,   441,   441,   442,
     443,   444,   445,   446,   447,   449,   448,   451,   450,   452,
     452,   453,   454,   454,   455,   455,   455,   455,   456,   457,
     459,   458,   460,   460,   461,   461,   461,   462,   463,   464,
     465,   465,   466,   466,   467,   469,   468,   471,   470,   472,
     472,   473,   474,   474,   475,   475,   475,   475,   476,   477,
     478,   479,   479,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   508,   509,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   532,   531,   533,   533,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   536,   535,   537,   537,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   539,   540,
     541,   542,   544,   543,   545,   545,   546,   546,   546,   546,
     546,   546,   546,   547,   548,   550,   549,   551,   551,   552,
     552,   553,   554,   556,   555,   557,   557,   558,   558,   559,
     560,   560,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   561,   561,   561,   561,   561,   561,   561,   561,   561,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   581,   582,   582,   582,   582,   582,   582,   582,   582,
     583,   584,   585,   586,   587,   588,   589
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   356,   420,     0,
     435,     0,   612,   253,   405,   229,     0,     0,   126,   291,
       0,     0,   308,   333,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   197,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   660,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   641,
     659,   654,   642,   643,   644,   645,   647,   648,   649,   650,
     646,   651,   652,   653,   655,   656,   657,   658,   216,     0,
     198,   378,     0,   359,     0,   433,     0,     0,   431,   432,
       0,   509,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   585,     0,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   452,
     507,   502,   503,   500,   504,   505,   501,   463,   453,   454,
     492,   455,   456,   457,   458,   459,   460,   461,   462,   497,
     464,   465,   466,   467,   506,   469,   474,   470,   472,   471,
     486,   487,   473,   475,   476,   477,   478,   480,   479,   468,
     482,   491,   493,   494,   483,   484,   508,   498,   499,   496,
     485,   481,   489,   490,   488,   495,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    95,    96,    99,   106,   100,
     104,   101,   102,   105,   103,    97,    98,     0,     0,     0,
       0,    43,    44,    45,   142,     0,   129,     0,   689,     0,
       0,     0,     0,     0,     0,     0,     0,   681,   682,   683,
     687,   684,   686,   685,   688,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,    51,
      63,    62,    59,    52,    61,    55,    56,    57,    53,    60,
      58,    54,     0,     0,   306,     0,     0,   304,   305,    88,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   640,     0,     0,   426,     0,     0,
       0,   423,   424,   425,     0,     0,   430,   447,     0,     0,
     437,   446,     0,   443,   444,   445,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   451,   622,   633,     0,     0,   625,     0,
       0,     0,   615,   616,   617,   618,   619,   620,   621,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,   256,
     257,   258,   259,   264,   260,   261,   262,   263,   417,     0,
     407,     0,   416,     0,   413,   414,   415,     0,   231,     0,
       0,     0,   241,     0,   239,   240,   242,   243,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    46,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,   294,   295,   296,   297,     0,     0,
       0,     0,     0,     0,     0,     0,   680,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,   318,     0,     0,   311,   312,   313,
     314,     0,     0,   341,     0,   336,   337,   338,     0,     0,
     303,     0,     0,     0,    82,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,   201,   204,   205,   207,   208,   209,   210,   211,   212,
     213,   202,   203,   206,     0,     0,     0,     0,     0,     0,
     386,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     361,   362,   363,   364,   365,   366,   368,   367,   369,   374,
     373,   370,   371,   372,   375,     0,     0,     0,   422,     0,
     429,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,   450,     0,     0,     0,     0,
       0,     0,     0,   614,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,     0,     0,   412,
     244,     0,     0,     0,     0,     0,   238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,    41,     0,
       0,     0,   171,     0,     0,     0,   148,     0,     0,   131,
     132,   133,   134,   137,   138,   136,   135,   139,   298,     0,
       0,     0,     0,   293,     0,     0,     0,     0,     0,     0,
       0,   679,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,   315,     0,     0,     0,     0,
     310,   339,     0,     0,     0,   335,     0,   302,    91,    90,
      89,   676,   673,   672,   661,   663,    27,    27,    27,    27,
      27,    29,    28,   667,   668,   671,   669,   674,   675,   677,
     678,   670,   662,   664,   665,   666,   214,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,   376,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   360,     0,
       0,   421,   434,     0,     0,     0,   436,   522,   526,   513,
     542,   555,   554,   610,   560,   520,   551,   557,   521,   511,
     512,   529,   518,   550,   519,   532,   517,   531,   530,   525,
     524,   523,   552,   510,   549,   608,   609,   546,   543,   589,
     605,   606,   590,   591,   592,   593,   600,   594,   603,   607,
     596,   601,   597,   602,   595,   599,   598,   604,     0,   588,
     548,   566,   582,   583,   567,   568,   569,   570,   577,   571,
     580,   584,   573,   578,   574,   579,   572,   576,   575,   581,
       0,   565,   541,   544,   559,   515,   553,   516,   545,   534,
     539,   540,   537,   538,   535,   536,   528,   527,    35,    35,
      35,    37,    36,   611,   558,   561,   547,   556,   514,   533,
       0,     0,     0,     0,     0,     0,   613,     0,     0,   276,
       0,     0,     0,     0,     0,   254,     0,     0,     0,   406,
       0,     0,     0,   249,   245,   248,   230,   111,   117,   115,
     114,   116,   112,   113,   110,   118,   124,   119,   123,   121,
     122,   120,   109,   108,   125,    47,    48,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,   292,   695,   690,   694,   692,   696,   691,   693,    75,
      81,    73,    77,    76,    72,    71,    69,    70,     0,    68,
      74,    80,    78,    79,     0,     0,     0,   309,     0,     0,
     334,   307,    30,    31,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,   392,     0,     0,
       0,     0,     0,     0,     0,     0,   357,   427,   428,   448,
     449,   441,     0,   440,   586,     0,   563,     0,    38,    39,
      40,   638,   637,     0,   636,   624,   623,   630,   629,     0,
     628,   632,   631,   268,   269,   274,     0,   273,     0,   267,
     290,   289,   288,   266,   419,   411,     0,   410,   418,   236,
     237,   235,     0,   234,   252,   251,     0,     0,     0,     0,
       0,   177,     0,     0,     0,     0,     0,   127,   300,   301,
     299,    66,     0,   316,   322,   328,   332,   331,   330,   327,
     323,   326,   329,   324,   325,     0,   321,   317,   340,   345,
     351,   355,   354,   353,   350,   346,   349,   352,   347,   348,
       0,   344,   226,   227,   220,   222,   224,   223,   221,   215,
     228,   219,   217,   218,   225,   382,   384,   385,   404,   403,
     400,   390,     0,   389,     0,   379,   401,   402,   377,   383,
     399,   381,   380,   438,     0,   587,   564,   634,     0,   626,
       0,     0,   271,   276,   282,   283,   279,   285,   281,   280,
     287,   284,   286,   278,   277,   408,     0,   232,     0,   250,
     247,   246,   147,   145,   175,     0,   174,     0,   141,   144,
     146,   152,   168,   169,   153,   154,   155,   156,   163,   157,
     166,   170,   159,   164,   160,   165,   158,   162,   161,   167,
       0,   151,   143,    67,   319,     0,   342,     0,     0,   387,
     392,   396,   397,   394,   395,   398,   393,   439,   635,   627,
     275,   272,   409,   233,     0,   172,   177,   187,   185,   194,
     184,   179,   188,   192,   181,   189,   191,   186,   180,   193,
     190,   182,   183,   178,   149,     0,   320,   343,   391,   388,
     176,   173,   150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   851,   852,  1001,  1002,    26,   280,   281,
     282,   283,    27,   318,   319,   320,   545,  1088,  1089,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
      28,    74,    75,    76,    77,    78,    29,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,    30,    63,   285,   788,   789,   790,   286,   791,   792,
     793,   794,   795,   796,  1064,  1320,  1321,   797,  1060,  1295,
    1296,  1344,  1297,  1363,    31,    51,   119,   609,   610,   611,
     120,   612,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   622,   623,    32,    60,   492,   751,  1182,  1183,   493,
     494,   495,  1188,  1034,  1035,   496,   497,    33,    58,   468,
     469,   470,   471,   472,   473,   474,   737,  1166,  1167,  1271,
    1168,  1284,   475,   476,   477,    34,    64,   523,   524,   525,
     526,   527,    35,   336,   337,   338,    36,    67,   556,   557,
     558,   559,   560,   827,  1215,  1216,    37,    68,   564,   565,
     566,   567,   833,  1230,  1231,    38,    52,   122,   639,   640,
     641,   123,   642,   643,   644,   645,   646,   647,   648,   888,
    1252,  1253,  1328,  1254,  1336,   649,   650,   651,   652,   653,
     654,    39,    59,   482,   746,  1176,  1177,   483,   484,   485,
     486,    40,    53,   370,   371,   372,   373,    41,   127,   128,
     129,    42,    55,   381,   663,  1142,  1143,   382,   383,   384,
     385,    43,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   420,   980,   981,   241,   418,
     958,   959,   242,   243,   244,   245,    44,    57,   451,   452,
     453,   454,   455,   729,  1159,  1160,   456,   457,   458,   726,
    1153,  1154,    45,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    46,   296,   297,   298,   299,   300,   301,
     302,   303,   304
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -772
static const yytype_int16 yypact[] =
{
    -772,   705,  -772,  -235,  -259,  -243,  -772,  -772,  -772,  -229,
    -772,  -214,  -772,  -772,  -772,  -772,  -206,  -199,  -772,  -772,
    -191,  -182,  -772,  -772,  -133,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   116,
     603,   -45,   -16,  -124,     5,  -121,   435,  -110,   -95,   -89,
     -77,   595,   187,    36,   -56,   315,   328,   -51,   -50,    19,
     -37,   -32,   -20,   -19,    56,  -772,  -772,  -772,  -772,  -772,
     -14,    -5,    -3,    26,    34,    39,    44,    49,    57,    68,
      78,    79,    80,    86,    88,    96,    98,   101,    94,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,     3,
    -772,  -772,    66,  -772,    13,  -772,   102,    22,  -772,  -772,
     234,  -772,   105,   109,   113,   117,   118,   119,   120,   123,
     125,   133,   150,   152,   153,   157,   158,   160,   161,   162,
     163,   166,   167,   168,   174,   175,   177,   180,   188,   190,
     191,   193,   194,   195,  -772,   197,  -772,   199,   201,   204,
     205,   207,   208,   210,   211,   215,   217,   218,   223,   224,
     225,   229,   232,   233,   235,   236,   237,   238,    10,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,   314,   412,   114,   297,
     -34,   239,   242,   243,   244,   247,   248,   249,   250,   251,
     255,   259,   260,   222,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   230,   266,   267,
      23,  -772,  -772,  -772,  -772,   173,  -772,    11,  -772,   268,
     270,   271,   275,   276,   278,   288,   295,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   292,   291,   296,   300,   305,
     308,   311,   313,  -772,   318,   322,   323,   324,   172,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,    47,    31,  -772,   326,    24,  -772,  -772,  -772,
     228,   299,   333,   298,  -772,   302,   426,   431,   382,   395,
     462,   462,   466,   468,   403,   404,   472,   462,   409,   411,
     414,   416,   417,   347,  -772,   714,   541,  -772,   350,   353,
      30,  -772,  -772,  -772,   467,   360,  -772,  -772,   367,   368,
    -772,  -772,    40,  -772,  -772,  -772,   437,   462,   443,   462,
     510,   489,   515,   450,   451,   518,   506,   463,   532,   534,
     535,   470,   462,   471,   473,   462,   511,   474,   538,   542,
     462,   544,   545,   519,   548,   550,   485,   486,   419,   488,
     422,   462,   462,   493,   462,   549,   500,   504,   507,  -153,
    -130,   514,   516,   462,   462,   572,   559,   462,   517,   520,
     522,   524,   454,  -772,  -772,  -772,   457,   458,  -772,   459,
     460,   129,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   464,
     475,   478,  -772,   480,   483,   487,   490,   494,    60,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   495,
    -772,   499,  -772,     9,  -772,  -772,  -772,   477,  -772,   502,
     505,   508,  -772,    89,  -772,  -772,  -772,  -772,  -772,   575,
     579,   583,   597,   598,   600,   601,   605,   185,   612,   619,
     577,   513,  -772,  -772,   623,   624,   521,  -772,   371,   523,
     525,   526,   528,    69,  -772,  -772,  -772,  -772,   582,   584,
     587,   627,   589,   590,   462,   537,  -772,  -772,   635,   599,
     641,   647,   648,   649,   650,   539,   653,   677,   656,   658,
     551,  -772,   553,   547,  -772,   552,    25,  -772,  -772,  -772,
    -772,   554,   555,  -772,    45,  -772,  -772,  -772,   665,   557,
    -772,   563,   565,   567,  -772,   568,   569,   570,   571,   573,
     227,   574,   576,   581,   591,   592,   596,   604,   606,   607,
     608,   609,   610,   611,  -772,   615,   580,   586,   602,   613,
     614,   616,   617,   618,   622,   628,   629,   632,   633,   156,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   626,   634,   636,   637,   642,   643,
    -772,   646,   659,   672,   673,   675,   676,   678,   679,    63,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   684,   686,   638,  -772,   651,
    -772,   691,   693,   680,   652,  -772,   660,   661,   685,   690,
     694,   695,   697,   698,   708,   712,   713,   715,   716,   717,
     718,   719,   720,   722,   723,   727,   731,   732,   734,   735,
     742,   745,   749,   750,   752,   753,   754,   755,   721,   756,
     758,   757,   759,   760,   764,   768,   769,   771,   772,   774,
     775,   776,   777,   778,   779,   780,   781,     1,   782,   783,
     784,   785,   786,   787,   788,  -772,   683,   462,   655,   702,
     696,   709,   789,  -772,  -772,   710,   664,   790,   762,   802,
     830,   867,   899,   791,  -772,   901,   792,   903,   796,  -772,
    -772,   794,   907,   908,   811,   800,  -772,   801,   803,   804,
     805,   806,   807,   808,   809,   810,   812,   813,   814,   815,
     816,   817,   818,   819,   820,  -772,   821,   822,  -772,   823,
     799,   824,  -772,   825,   826,   827,  -772,   828,   221,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   920,
     933,   934,   832,  -772,   833,   834,   835,   836,   837,   838,
     839,  -772,   840,   841,   842,   843,   844,   845,   846,   -70,
     847,   848,   849,   850,  -772,  -772,   935,   851,   960,   852,
    -772,  -772,   962,   853,   855,  -772,   857,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,   462,   462,   462,   462,
     462,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   989,   990,   462,
     991,   992,   993,   994,   973,   996,   997,   462,   462,   572,
     868,  -772,  -772,   976,   -35,   978,   979,   687,   869,   980,
     982,   983,   984,  1007,   986,   987,   988,   880,  -772,   881,
     882,  -772,  -772,   883,   884,   763,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -258,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -232,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   572,   572,
     572,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
      -2,   885,   886,     2,   887,   888,  -772,   889,   890,  1023,
     892,   893,   894,   895,   896,  -772,   897,  1002,   900,  -772,
     -73,   902,   904,   959,   905,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  1010,   968,
     909,  1014,  1015,  1016,   910,  1017,   911,  -772,   914,   915,
     916,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -226,  -772,
    -772,  -772,  -772,  -772,   917,   657,   918,  -772,   919,   671,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   921,   922,   923,
     924,   925,   926,   927,   928,   929,   930,   931,   932,   936,
    -772,   937,   938,   939,   940,   941,   942,  1042,   943,   944,
     945,   946,   947,   948,   949,   950,  -772,  -772,  -772,  -772,
    -772,  -772,  -215,  -772,  -772,   721,  -772,   758,  -772,  -772,
    -772,  -772,  -772,  -203,  -772,  -772,  -772,  -772,  -772,  -156,
    -772,  -772,  -772,  -772,  -772,  -772,  -144,  -772,   668,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,   -36,  -772,  -772,  -772,
    -772,  -772,   -23,  -772,  -772,  -772,  1051,   811,   951,   952,
     953,  1065,   954,   955,   956,   795,   957,  -772,  -772,  -772,
    -772,  -772,   -70,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   -22,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
      -8,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,    62,  -772,   290,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   763,  -772,  -772,  -772,    -2,  -772,
       2,   668,  -772,  1023,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  1002,  -772,   -73,  -772,
    -772,  -772,  -772,  -772,  -772,    65,  -772,   533,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
      76,  -772,  -772,  -772,  -772,   657,  -772,   671,   290,  -772,
    1042,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   533,  -772,  1065,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   795,  -772,  -772,  -772,  -772,
    -772,  -772,  -772
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -772,  -772,  -772,  -771,  -350,  -687,  -433,  -772,  -772,   530,
    -772,  -772,  -772,  -772,   562,  -772,  -772,  -772,  -290,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  1122,  -772,  -772,  -772,  -772,  -772,   958,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   432,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -168,  -772,  -772,  -772,
    -123,  -772,  -772,  -122,  -772,  -772,  -772,  -772,   620,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   -64,  -772,
     733,  -772,  -772,  -772,    38,  -772,  -772,  -772,  -772,  -772,
     765,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   -46,  -772,
    -772,   -43,  -772,  -772,  -772,  -772,  -772,  -772,   707,  -772,
    -772,  -772,  -772,  -772,   898,  -772,  -772,  -772,  -772,   681,
    -772,  -772,  -772,  -772,  -772,   -94,  -772,  -772,  -772,   674,
    -772,  -772,  -772,  -772,   -92,  -772,  -772,  -772,  -772,   593,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,   -91,  -772,  -772,   -88,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,   -44,  -772,   761,  -772,
    -772,  -772,  -772,  -772,   866,  -772,  -772,  -772,  -772,  1114,
    -772,  -772,  -772,  -772,  -772,  -772,   -21,  -772,   863,  -772,
    -772,  -772,  -772,  1058,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   100,  -772,  -772,
    -772,   103,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   798,
    -772,  -772,  -772,  -772,  -772,   -18,  -772,  -772,  -772,  -772,
    -772,   -17,  -772,  -772,  1152,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   961,  -772,  -772,  -772,  -772,
    -772,  -772,  -772
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     581,   582,   718,  1179,  1144,    49,   125,   588,  1145,  1151,
     478,   131,   519,  1157,   367,   998,   999,  1000,   132,   133,
     334,    50,   134,   125,   277,   334,   552,    47,    48,   135,
    1146,   367,   561,   520,  1147,    54,  1201,   667,   136,   669,
    1202,   377,   137,   138,   709,   710,   561,  1263,   552,   139,
      56,  1264,   682,   140,   141,   685,   142,    70,    61,  1267,
     690,   459,   143,  1268,   624,    62,   625,   711,   712,   626,
     519,   701,   702,    65,   704,  1102,  1103,  1104,  1105,  1106,
     144,   145,    66,   715,   716,   146,   460,   720,   627,   628,
     487,   520,   147,    71,   126,    79,   148,   149,   150,  1086,
    1087,   151,   368,    72,   152,   153,  1269,    80,   118,   461,
    1270,   126,   629,   462,   154,   478,   630,    70,  1272,   368,
     155,   156,  1273,   157,   158,   159,   160,   161,    81,    82,
     444,    69,   717,   445,    83,   521,    84,   121,   162,   335,
     124,   278,   488,   130,   335,   553,   631,   163,   632,   164,
     165,   562,   166,    71,   246,   167,   168,   595,  1180,   169,
     378,   633,  1181,    72,   479,   562,   522,   553,   369,   247,
     170,   279,   489,   305,   446,   248,    73,   447,   490,   596,
     597,  1122,  1123,   634,   810,   369,   598,   249,   277,   284,
      85,    86,   171,   521,   172,   379,   480,  1152,   173,    87,
      88,  1158,   174,   175,   176,   177,   178,   463,   287,   306,
     179,   180,   554,   332,   333,   635,   464,   465,   563,   181,
      89,    90,   779,   250,   522,   339,  1285,   380,   498,   636,
    1286,   448,   563,   340,   554,   377,    73,    91,    92,  1287,
    1324,   491,   637,  1288,  1325,   341,   342,   780,    93,   449,
     466,   345,   182,   183,  1326,   184,   307,    94,  1327,   481,
     346,   185,   347,   599,   600,   601,   186,   365,   602,   479,
     781,   187,   748,   442,   782,   555,   603,   251,   252,   253,
     254,   255,   256,   257,   258,   375,   516,   569,   829,   604,
     605,   348,   308,   657,   309,   310,   288,   555,   487,   349,
    1331,   480,  1332,   664,   350,   278,   606,   607,   834,   351,
     467,  1148,  1149,  1150,   352,   444,   288,  1333,   445,   343,
     638,  1334,   353,   743,  1329,   259,   897,  1345,  1330,   305,
     366,  1346,   802,   354,   608,   279,   289,   311,  1364,   312,
     313,   783,  1365,   355,   356,   357,    95,    96,    97,   290,
     488,   358,   755,   359,   378,   314,   289,   363,   580,   446,
     260,   360,   447,   361,   481,   306,   362,   374,   784,   290,
     386,   291,   779,   292,   387,   293,   294,  1011,   388,   450,
     489,   571,   389,   390,   391,   392,   490,   785,   393,   379,
     394,   291,   732,   292,   295,   293,   294,   780,   395,   315,
     846,   847,   848,   849,   850,   765,   766,   767,   768,   769,
     770,   771,   307,   459,   295,   396,   448,   397,   398,   880,
     781,   380,   399,   400,   782,   401,   402,   403,   404,   316,
     317,   405,   406,   407,   449,   550,   131,   518,   460,   408,
     409,   261,   410,   132,   133,   411,  1119,   134,   308,   491,
     309,   310,   572,   412,   135,   413,   414,   786,   415,   416,
     417,   461,   419,   136,   421,   462,   422,   137,   138,   423,
     424,   787,   425,   426,   139,   427,   428,   262,   140,   141,
     429,   142,   430,   431,  1066,   511,   573,   143,   432,   433,
     434,   783,   513,   311,   435,   312,   313,   436,   437,   575,
     438,   439,   440,   441,   499,   144,   145,   500,   501,   502,
     146,   314,   503,   504,   505,   506,   507,   147,   784,  1109,
     508,   148,   149,   150,   509,   510,   151,  1117,  1118,   152,
     153,   514,   515,   528,  1335,   529,   530,   785,  1347,   154,
     531,   532,   624,   533,   625,   155,   156,   626,   157,   158,
     159,   160,   161,   534,   537,   315,   538,   576,   535,   463,
     574,   539,   577,   162,   450,   540,   627,   628,   464,   465,
     541,  1348,   163,   542,   164,   165,   543,   166,   544,   578,
     167,   168,  1349,   546,   169,   316,   317,   547,   548,   549,
     629,   568,   579,   580,   630,   170,   250,   583,  1350,   584,
     585,   586,   466,   587,    79,  1351,   589,   786,   590,   594,
    1352,   591,  1353,   592,   593,   655,    80,   171,   656,   172,
     659,   787,   660,   173,   631,  1354,   632,   174,   175,   176,
     177,   178,   661,   662,   666,   179,   180,    81,    82,   633,
     668,   670,   671,    83,   181,    84,   672,   673,   674,   675,
     251,   252,   253,   254,   255,   256,   257,   258,  1355,   676,
     677,   634,   467,   678,   686,   679,   680,   681,   683,   688,
     684,   687,   693,   689,  1356,   691,   692,   182,   183,   694,
     184,   695,   696,   697,   698,   699,   185,   700,  1274,  1275,
     703,   186,  1357,   635,  1358,  1359,   187,   706,   259,    85,
      86,   707,   705,   717,   708,     2,     3,   636,    87,    88,
       4,   713,   719,   714,   721,   595,   725,   722,  1276,   723,
     637,   724,   727,   728,   730,   731,   734,     5,   757,    89,
      90,     6,   758,   260,     7,  1277,   759,   596,   597,   750,
     735,     8,  1278,   736,   598,   738,    91,    92,   739,  1204,
     760,   761,   740,   762,   763,   741,     9,    93,   764,   742,
     745,  1279,  1360,  1219,   747,   772,    94,   752,    10,    11,
     753,    12,   773,   754,   774,   775,   776,   777,    13,   804,
     807,   805,  1361,   778,   806,   798,   808,   809,   812,  1280,
     799,   800,  1362,   801,   814,    14,   813,  1281,   638,   811,
     815,   816,   817,   818,   819,    15,   820,    16,   821,   822,
     517,   823,   826,   824,   261,   825,   831,   828,   836,   837,
     832,   599,   600,   601,    17,   838,   602,   839,  1205,   840,
     841,   842,   843,   844,   603,   845,   853,   899,   854,   900,
    1282,    18,  1220,   855,   903,   867,   904,   604,   605,  1014,
     262,   868,  1012,   856,   857,    95,    96,    97,   858,  1283,
    1206,  1018,  1015,  1017,   606,   607,   859,   869,   860,   861,
     862,   863,   864,   865,  1221,  1207,    19,   866,   870,   871,
     551,   872,   873,   874,  1126,    20,    21,   875,   882,  1222,
      22,    23,   608,   876,   877,  1208,  1209,   878,   879,   883,
     901,   884,   885,  1210,  1211,  1212,  1213,   886,   887,  1223,
    1224,   889,  1323,   902,   906,  1020,  1214,  1225,  1226,  1227,
    1228,  1141,   907,   908,   890,   939,   940,   941,   942,   943,
    1229,   944,   945,  1021,   946,   947,   948,   891,   892,   949,
     893,   894,  1033,   895,   896,   905,    24,   909,  1010,   950,
     951,   952,   910,   953,   954,   955,   911,   912,   956,   913,
     914,   957,   961,   962,   963,   964,   965,  1013,   966,   967,
     915,   968,   969,   970,   916,   917,   971,   918,   919,   920,
     921,   922,   923,  1022,   924,   925,   972,   973,   974,   926,
     975,   976,   977,   927,   928,   978,   929,   930,   979,  1301,
    1302,  1303,  1304,  1305,   931,  1306,  1307,   932,  1308,  1309,
    1310,   933,   934,  1311,   935,   936,   937,   938,   960,   982,
    1023,   983,   984,  1312,  1313,  1314,   985,  1315,  1316,  1317,
     986,   987,  1318,   988,   989,  1319,   990,   991,   992,   993,
     994,   995,   996,   997,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1016,  1024,  1025,  1026,  1019,  1028,  1027,  1029,  1030,
    1031,  1032,  1036,  1037,  1058,  1038,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1068,  1046,  1047,  1048,  1049,  1050,  1051,
    1052,  1053,  1054,  1055,  1056,  1057,  1069,  1070,  1094,  1059,
    1061,  1062,  1063,  1065,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1090,
    1091,  1092,  1093,  1096,  1097,  1098,  1095,  1100,  1099,  1101,
    1107,  1108,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1121,
    1120,  1124,  1125,  1128,  1127,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1155,  1156,  1161,
    1162,  1163,  1164,  1165,  1169,  1170,  1171,  1172,  1173,  1174,
    1175,  1186,  1178,  1189,  1184,  1190,  1185,  1192,  1193,  1194,
    1196,  1187,  1251,  1197,  1191,  1195,  1198,  1199,  1200,  1203,
    1217,  1218,  1289,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,  1294,   344,  1372,  1244,  1245,
    1246,  1247,  1248,  1249,  1250,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1291,  1292,  1293,  1298,  1299,  1300,  1322,
    1067,   512,  1370,  1371,  1343,  1290,   756,  1341,  1340,   881,
     803,  1366,   898,   744,   570,  1367,   658,   830,   835,  1369,
    1368,   376,  1342,  1337,   749,   665,   443,  1266,  1265,   733,
     364,  1338,  1339,     0,     0,     0,     0,   536
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-772))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     350,   351,   435,    76,   262,   264,     1,   357,   266,    11,
       1,     1,     1,    11,     1,    14,    15,    16,     8,     9,
       1,   264,    12,     1,     1,     1,     1,   262,   263,    19,
     262,     1,     1,    22,   266,   264,   262,   387,    28,   389,
     266,     1,    32,    33,   197,   198,     1,   262,     1,    39,
     264,   266,   402,    43,    44,   405,    46,     1,   264,   262,
     410,     1,    52,   266,     1,   264,     3,   197,   198,     6,
       1,   421,   422,   264,   424,   846,   847,   848,   849,   850,
      70,    71,   264,   433,   434,    75,    26,   437,    25,    26,
       1,    22,    82,    37,    89,     1,    86,    87,    88,   169,
     170,    91,    89,    47,    94,    95,   262,    13,   153,    49,
     266,    89,    49,    53,   104,     1,    53,     1,   262,    89,
     110,   111,   266,   113,   114,   115,   116,   117,    34,    35,
       1,   264,   131,     4,    40,   124,    42,   153,   128,   120,
     264,   118,    53,   264,   120,   120,    83,   137,    85,   139,
     140,   120,   142,    37,   264,   145,   146,     1,   231,   149,
     120,    98,   235,    47,   155,   120,   155,   120,   155,   264,
     160,   148,    83,     1,    45,   264,   120,    48,    89,    23,
      24,   216,   217,   120,   534,   155,    30,   264,     1,   153,
      96,    97,   182,   124,   184,   155,   187,   199,   188,   105,
     106,   199,   192,   193,   194,   195,   196,   147,   264,    37,
     200,   201,   187,   264,   264,   152,   156,   157,   187,   209,
     126,   127,     1,     1,   155,   262,   262,   187,   262,   166,
     266,   102,   187,   265,   187,     1,   120,   143,   144,   262,
     262,   152,   179,   266,   266,   265,   265,    26,   154,   120,
     190,   265,   242,   243,   262,   245,    84,   163,   266,   250,
     265,   251,   265,   107,   108,   109,   256,   264,   112,   155,
      49,   261,   263,   263,    53,   250,   120,    55,    56,    57,
      58,    59,    60,    61,    62,   263,   263,   263,   263,   133,
     134,   265,   120,   263,   122,   123,     1,   250,     1,   265,
      10,   187,    12,   263,   265,   118,   150,   151,   263,   265,
     250,   998,   999,  1000,   265,     1,     1,    27,     4,   263,
     257,    31,   265,   263,   262,   103,   263,   262,   266,     1,
     264,   266,   263,   265,   178,   148,    41,   165,   262,   167,
     168,   120,   266,   265,   265,   265,   252,   253,   254,    54,
      53,   265,   263,   265,   120,   183,    41,   263,   131,    45,
     138,   265,    48,   265,   250,    37,   265,   265,   147,    54,
     265,    76,     1,    78,   265,    80,    81,   727,   265,   250,
      83,   153,   265,   265,   265,   265,    89,   166,   265,   155,
     265,    76,   263,    78,    99,    80,    81,    26,   265,   227,
     173,   174,   175,   176,   177,   220,   221,   222,   223,   224,
     225,   226,    84,     1,    99,   265,   102,   265,   265,   263,
      49,   187,   265,   265,    53,   265,   265,   265,   265,   257,
     258,   265,   265,   265,   120,   263,     1,   264,    26,   265,
     265,   219,   265,     8,     9,   265,   879,    12,   120,   152,
     122,   123,   153,   265,    19,   265,   265,   236,   265,   265,
     265,    49,   265,    28,   265,    53,   265,    32,    33,   265,
     265,   250,   265,   265,    39,   265,   265,   255,    43,    44,
     265,    46,   265,   265,   263,   263,   153,    52,   265,   265,
     265,   120,   262,   165,   265,   167,   168,   265,   265,   197,
     265,   265,   265,   265,   265,    70,    71,   265,   265,   265,
      75,   183,   265,   265,   265,   265,   265,    82,   147,   869,
     265,    86,    87,    88,   265,   265,    91,   877,   878,    94,
      95,   265,   265,   265,   244,   265,   265,   166,     5,   104,
     265,   265,     1,   265,     3,   110,   111,     6,   113,   114,
     115,   116,   117,   265,   262,   227,   265,   131,   263,   147,
     262,   265,   131,   128,   250,   265,    25,    26,   156,   157,
     265,    38,   137,   265,   139,   140,   265,   142,   265,   197,
     145,   146,    49,   265,   149,   257,   258,   265,   265,   265,
      49,   265,   197,   131,    53,   160,     1,   131,    65,   131,
     197,   197,   190,   131,     1,    72,   197,   236,   197,   262,
      77,   197,    79,   197,   197,   265,    13,   182,   265,   184,
     153,   250,   262,   188,    83,    92,    85,   192,   193,   194,
     195,   196,   265,   265,   197,   200,   201,    34,    35,    98,
     197,   131,   153,    40,   209,    42,   131,   197,   197,   131,
      55,    56,    57,    58,    59,    60,    61,    62,   125,   153,
     197,   120,   250,   131,   153,   131,   131,   197,   197,   131,
     197,   197,   153,   131,   141,   131,   131,   242,   243,   131,
     245,   131,   197,   197,   265,   197,   251,   265,    20,    21,
     197,   256,   159,   152,   161,   162,   261,   197,   103,    96,
      97,   197,   153,   131,   197,     0,     1,   166,   105,   106,
       5,   197,   153,   197,   197,     1,   262,   197,    50,   197,
     179,   197,   265,   265,   265,   265,   262,    22,   153,   126,
     127,    26,   153,   138,    29,    67,   153,    23,    24,   262,
     265,    36,    74,   265,    30,   265,   143,   144,   265,    92,
     153,   153,   265,   153,   153,   265,    51,   154,   153,   265,
     265,    93,   229,    92,   265,   153,   163,   265,    63,    64,
     265,    66,   153,   265,   197,   262,   153,   153,    73,   197,
     153,   197,   249,   262,   197,   262,   197,   197,   153,   121,
     265,   265,   259,   265,   153,    90,   197,   129,   257,   262,
     153,   153,   153,   153,   265,   100,   153,   102,   131,   153,
     280,   153,   265,   262,   219,   262,   262,   265,   153,   262,
     265,   107,   108,   109,   119,   262,   112,   262,   171,   262,
     262,   262,   262,   262,   120,   262,   262,   153,   262,   153,
     172,   136,   171,   262,   153,   265,   153,   133,   134,   153,
     255,   265,   197,   262,   262,   252,   253,   254,   262,   191,
     203,   197,   153,   153,   150,   151,   262,   265,   262,   262,
     262,   262,   262,   262,   203,   218,   171,   262,   265,   265,
     318,   265,   265,   265,   197,   180,   181,   265,   262,   218,
     185,   186,   178,   265,   265,   238,   239,   265,   265,   265,
     262,   265,   265,   246,   247,   248,   249,   265,   265,   238,
     239,   265,  1202,   262,   262,   153,   259,   246,   247,   248,
     249,   158,   262,   262,   265,   204,   205,   206,   207,   208,
     259,   210,   211,   131,   213,   214,   215,   265,   265,   218,
     265,   265,   131,   265,   265,   265,   241,   262,   265,   228,
     229,   230,   262,   232,   233,   234,   262,   262,   237,   262,
     262,   240,   204,   205,   206,   207,   208,   265,   210,   211,
     262,   213,   214,   215,   262,   262,   218,   262,   262,   262,
     262,   262,   262,   153,   262,   262,   228,   229,   230,   262,
     232,   233,   234,   262,   262,   237,   262,   262,   240,   204,
     205,   206,   207,   208,   262,   210,   211,   262,   213,   214,
     215,   262,   262,   218,   262,   262,   262,   262,   262,   262,
     153,   262,   262,   228,   229,   230,   262,   232,   233,   234,
     262,   262,   237,   262,   262,   240,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   153,   262,   153,   265,   153,   265,   262,   265,
     153,   153,   262,   262,   265,   262,   262,   262,   262,   262,
     262,   262,   262,   153,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   153,   153,   153,   265,
     265,   265,   265,   265,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   153,   262,   153,   265,   262,   265,   262,
     131,   131,   131,   131,   131,   131,   153,   131,   131,   153,
     262,   153,   153,   153,   265,   153,   153,   153,   131,   153,
     153,   153,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   130,   262,   262,   262,   262,   262,   262,
     158,   202,   262,   153,   262,   197,   262,   153,   153,   153,
     153,   266,   130,   262,   265,   265,   262,   262,   262,   262,
     262,   262,   131,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   130,    74,  1365,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     788,   263,  1344,  1346,  1288,  1187,   493,  1273,  1271,   609,
     523,  1325,   639,   468,   336,  1327,   370,   556,   564,  1330,
    1328,   127,  1286,  1264,   483,   382,   188,  1147,  1145,   451,
      98,  1268,  1270,    -1,    -1,    -1,    -1,   296
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   268,     0,     1,     5,    22,    26,    29,    36,    51,
      63,    64,    66,    73,    90,   100,   102,   119,   136,   171,
     180,   181,   185,   186,   241,   269,   274,   279,   297,   303,
     318,   341,   360,   374,   392,   399,   403,   413,   422,   448,
     458,   464,   468,   478,   543,   559,   580,   262,   263,   264,
     264,   342,   423,   459,   264,   469,   264,   544,   375,   449,
     361,   264,   264,   319,   393,   264,   264,   404,   414,   264,
       1,    37,    47,   120,   298,   299,   300,   301,   302,     1,
      13,    34,    35,    40,    42,    96,    97,   105,   106,   126,
     127,   143,   144,   154,   163,   252,   253,   254,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   578,   579,   153,   343,
     347,   153,   424,   428,   264,     1,    89,   465,   466,   467,
     264,     1,     8,     9,    12,    19,    28,    32,    33,    39,
      43,    44,    46,    52,    70,    71,    75,    82,    86,    87,
      88,    91,    94,    95,   104,   110,   111,   113,   114,   115,
     116,   117,   128,   137,   139,   140,   142,   145,   146,   149,
     160,   182,   184,   188,   192,   193,   194,   195,   196,   200,
     201,   209,   242,   243,   245,   251,   256,   261,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   535,   539,   540,   541,   542,   264,   264,   264,   264,
       1,    55,    56,    57,    58,    59,    60,    61,    62,   103,
     138,   219,   255,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,     1,   118,   148,
     275,   276,   277,   278,   153,   320,   324,   264,     1,    41,
      54,    76,    78,    80,    81,    99,   581,   582,   583,   584,
     585,   586,   587,   588,   589,     1,    37,    84,   120,   122,
     123,   165,   167,   168,   183,   227,   257,   258,   280,   281,
     282,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   264,   264,     1,   120,   400,   401,   402,   262,
     265,   265,   265,   263,   299,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   263,   561,   264,   264,     1,    89,   155,
     460,   461,   462,   463,   265,   263,   466,     1,   120,   155,
     187,   470,   474,   475,   476,   477,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   536,   265,
     532,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   263,   480,     1,     4,    45,    48,   102,   120,
     250,   545,   546,   547,   548,   549,   553,   554,   555,     1,
      26,    49,    53,   147,   156,   157,   190,   250,   376,   377,
     378,   379,   380,   381,   382,   389,   390,   391,     1,   155,
     187,   250,   450,   454,   455,   456,   457,     1,    53,    83,
      89,   152,   362,   366,   367,   368,   372,   373,   262,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   263,   305,   262,   265,   265,   263,   276,   264,     1,
      22,   124,   155,   394,   395,   396,   397,   398,   265,   265,
     265,   265,   265,   265,   265,   263,   582,   262,   265,   265,
     265,   265,   265,   265,   265,   283,   265,   265,   265,   265,
     263,   281,     1,   120,   187,   250,   405,   406,   407,   408,
     409,     1,   120,   187,   415,   416,   417,   418,   265,   263,
     401,   153,   153,   153,   262,   197,   131,   131,   197,   197,
     131,   271,   271,   131,   131,   197,   197,   131,   271,   197,
     197,   197,   197,   197,   262,     1,    23,    24,    30,   107,
     108,   109,   112,   120,   133,   134,   150,   151,   178,   344,
     345,   346,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,     1,     3,     6,    25,    26,    49,
      53,    83,    85,    98,   120,   152,   166,   179,   257,   425,
     426,   427,   429,   430,   431,   432,   433,   434,   435,   442,
     443,   444,   445,   446,   447,   265,   265,   263,   461,   153,
     262,   265,   265,   471,   263,   475,   197,   271,   197,   271,
     131,   153,   131,   197,   197,   131,   153,   197,   131,   131,
     131,   197,   271,   197,   197,   271,   153,   197,   131,   131,
     271,   131,   131,   153,   131,   131,   197,   197,   265,   197,
     265,   271,   271,   197,   271,   153,   197,   197,   197,   197,
     198,   197,   198,   197,   197,   271,   271,   131,   273,   153,
     271,   197,   197,   197,   197,   262,   556,   265,   265,   550,
     265,   265,   263,   546,   262,   265,   265,   383,   265,   265,
     265,   265,   265,   263,   377,   265,   451,   265,   263,   455,
     262,   363,   265,   265,   265,   263,   367,   153,   153,   153,
     153,   153,   153,   153,   153,   220,   221,   222,   223,   224,
     225,   226,   153,   153,   197,   262,   153,   153,   262,     1,
      26,    49,    53,   120,   147,   166,   236,   250,   321,   322,
     323,   325,   326,   327,   328,   329,   330,   334,   262,   265,
     265,   265,   263,   395,   197,   197,   197,   153,   197,   197,
     271,   262,   153,   197,   153,   153,   153,   153,   153,   265,
     153,   131,   153,   153,   262,   262,   265,   410,   265,   263,
     406,   262,   265,   419,   263,   416,   153,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   173,   174,   175,   176,
     177,   270,   271,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     263,   345,   262,   265,   265,   265,   265,   265,   436,   265,
     265,   265,   265,   265,   265,   265,   265,   263,   426,   153,
     153,   262,   262,   153,   153,   265,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   204,
     205,   206,   207,   208,   210,   211,   213,   214,   215,   218,
     228,   229,   230,   232,   233,   234,   237,   240,   537,   538,
     262,   204,   205,   206,   207,   208,   210,   211,   213,   214,
     215,   218,   228,   229,   230,   232,   233,   234,   237,   240,
     533,   534,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,    14,    15,
      16,   272,   273,   262,   262,   262,   262,   262,   262,   262,
     265,   271,   197,   265,   153,   153,   262,   153,   197,   265,
     153,   131,   153,   153,   153,   262,   153,   265,   153,   262,
     265,   153,   153,   131,   370,   371,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   265,   265,
     335,   265,   265,   265,   331,   265,   263,   322,   153,   153,
     153,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   169,   170,   284,   285,
     262,   262,   262,   262,   153,   265,   153,   262,   153,   265,
     262,   262,   270,   270,   270,   270,   270,   131,   131,   271,
     131,   131,   131,   131,   153,   131,   131,   271,   271,   273,
     262,   153,   216,   217,   153,   153,   197,   265,   153,   153,
     153,   153,   131,   153,   153,   153,   262,   262,   262,   262,
     262,   158,   472,   473,   262,   266,   262,   266,   272,   272,
     272,    11,   199,   557,   558,   262,   262,    11,   199,   551,
     552,   262,   262,   262,   262,   130,   384,   385,   387,   262,
     262,   262,   262,   262,   262,   158,   452,   453,   262,    76,
     231,   235,   364,   365,   262,   262,   202,   266,   369,   153,
     197,   265,   153,   153,   153,   265,   153,   262,   262,   262,
     262,   262,   266,   262,    92,   171,   203,   218,   238,   239,
     246,   247,   248,   249,   259,   411,   412,   262,   262,    92,
     171,   203,   218,   238,   239,   246,   247,   248,   249,   259,
     420,   421,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   130,   437,   438,   440,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   266,   538,   534,   262,   266,   262,
     266,   386,   262,   266,    20,    21,    50,    67,    74,    93,
     121,   129,   172,   191,   388,   262,   266,   262,   266,   131,
     371,   262,   262,   262,   130,   336,   337,   339,   262,   262,
     262,   204,   205,   206,   207,   208,   210,   211,   213,   214,
     215,   218,   228,   229,   230,   232,   233,   234,   237,   240,
     332,   333,   262,   285,   262,   266,   262,   266,   439,   262,
     266,    10,    12,    27,    31,   244,   441,   473,   558,   552,
     388,   385,   453,   365,   338,   262,   266,     5,    38,    49,
      65,    72,    77,    79,    92,   125,   141,   159,   161,   162,
     229,   249,   259,   340,   262,   266,   412,   421,   441,   438,
     340,   337,   333
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
#line 426 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 428 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 432 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 436 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 440 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 444 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 448 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 457 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 497 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 503 "ircd_parser.y"
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
#line 517 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 523 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 531 "ircd_parser.y"
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
#line 565 "ircd_parser.y"
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
#line 625 "ircd_parser.y"
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
#line 640 "ircd_parser.y"
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
#line 655 "ircd_parser.y"
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
#line 664 "ircd_parser.y"
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
#line 678 "ircd_parser.y"
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
#line 687 "ircd_parser.y"
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
#line 715 "ircd_parser.y"
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
#line 745 "ircd_parser.y"
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
#line 768 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 783 "ircd_parser.y"
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
#line 792 "ircd_parser.y"
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
#line 801 "ircd_parser.y"
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
#line 828 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 832 "ircd_parser.y"
    {
                        }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 836 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 843 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 850 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 857 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 864 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 871 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 878 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 885 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 892 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 896 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 900 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 904 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 908 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 912 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 922 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 931 "ircd_parser.y"
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
#line 944 "ircd_parser.y"
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1043 "ircd_parser.y"
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
#line 1055 "ircd_parser.y"
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
#line 1089 "ircd_parser.y"
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
#line 1101 "ircd_parser.y"
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
#line 1112 "ircd_parser.y"
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
#line 1154 "ircd_parser.y"
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
#line 1163 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1170 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1202 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1206 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1210 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1222 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1226 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1234 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1238 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1248 "ircd_parser.y"
    {
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1252 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1253 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1256 "ircd_parser.y"
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
#line 1263 "ircd_parser.y"
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
#line 1270 "ircd_parser.y"
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
#line 1277 "ircd_parser.y"
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
#line 1284 "ircd_parser.y"
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
#line 1291 "ircd_parser.y"
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
#line 1298 "ircd_parser.y"
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
#line 1305 "ircd_parser.y"
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
#line 1312 "ircd_parser.y"
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
#line 1319 "ircd_parser.y"
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
#line 1326 "ircd_parser.y"
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
#line 1333 "ircd_parser.y"
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
#line 1340 "ircd_parser.y"
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
#line 1347 "ircd_parser.y"
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
#line 1354 "ircd_parser.y"
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
#line 1361 "ircd_parser.y"
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
#line 1374 "ircd_parser.y"
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
#line 1381 "ircd_parser.y"
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
#line 1441 "ircd_parser.y"
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
#line 1450 "ircd_parser.y"
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
#line 1459 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1483 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1489 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1495 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1501 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1513 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1519 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1525 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1534 "ircd_parser.y"
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
#line 1541 "ircd_parser.y"
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
#line 1550 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1556 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1560 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1564 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 245:

/* Line 1806 of yacc.c  */
#line 1574 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1579 "ircd_parser.y"
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
#line 1593 "ircd_parser.y"
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
#line 1613 "ircd_parser.y"
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
#line 1622 "ircd_parser.y"
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
#line 1634 "ircd_parser.y"
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
#line 1646 "ircd_parser.y"
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
#line 1708 "ircd_parser.y"
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
#line 1745 "ircd_parser.y"
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
#line 1758 "ircd_parser.y"
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
#line 1767 "ircd_parser.y"
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
#line 1778 "ircd_parser.y"
    {
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1782 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1783 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1786 "ircd_parser.y"
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
#line 1793 "ircd_parser.y"
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
#line 1800 "ircd_parser.y"
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
#line 1807 "ircd_parser.y"
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
#line 1814 "ircd_parser.y"
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
#line 1821 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1828 "ircd_parser.y"
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
#line 1835 "ircd_parser.y"
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
#line 1842 "ircd_parser.y"
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
#line 1849 "ircd_parser.y"
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
#line 1859 "ircd_parser.y"
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
#line 1878 "ircd_parser.y"
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
#line 1888 "ircd_parser.y"
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
#line 1901 "ircd_parser.y"
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
#line 1908 "ircd_parser.y"
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
#line 1920 "ircd_parser.y"
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
#line 1929 "ircd_parser.y"
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
#line 1944 "ircd_parser.y"
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
#line 1962 "ircd_parser.y"
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
#line 1977 "ircd_parser.y"
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
#line 1985 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1996 "ircd_parser.y"
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
#line 2005 "ircd_parser.y"
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
#line 2027 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2034 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2038 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2042 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2046 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2050 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2054 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2058 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 2062 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 2066 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 2070 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2074 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 2083 "ircd_parser.y"
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
#line 2090 "ircd_parser.y"
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
#line 2103 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2109 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2116 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2120 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2124 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2128 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2132 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2136 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 351:

/* Line 1806 of yacc.c  */
#line 2140 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 352:

/* Line 1806 of yacc.c  */
#line 2144 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 353:

/* Line 1806 of yacc.c  */
#line 2148 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 354:

/* Line 1806 of yacc.c  */
#line 2152 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 355:

/* Line 1806 of yacc.c  */
#line 2156 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 356:

/* Line 1806 of yacc.c  */
#line 2165 "ircd_parser.y"
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
#line 2183 "ircd_parser.y"
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
#line 2321 "ircd_parser.y"
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
#line 2333 "ircd_parser.y"
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
#line 2345 "ircd_parser.y"
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
#line 2354 "ircd_parser.y"
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
#line 2380 "ircd_parser.y"
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
#line 2398 "ircd_parser.y"
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
#line 2416 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2422 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2426 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2434 "ircd_parser.y"
    {
}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 2438 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2439 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 2442 "ircd_parser.y"
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
#line 2453 "ircd_parser.y"
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
#line 2460 "ircd_parser.y"
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
#line 2467 "ircd_parser.y"
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
#line 2474 "ircd_parser.y"
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
#line 2484 "ircd_parser.y"
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
#line 2525 "ircd_parser.y"
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
#line 2536 "ircd_parser.y"
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
#line 2549 "ircd_parser.y"
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
#line 2562 "ircd_parser.y"
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
#line 2571 "ircd_parser.y"
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
#line 2606 "ircd_parser.y"
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
#line 2613 "ircd_parser.y"
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
#line 2669 "ircd_parser.y"
    {
}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 2674 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 2683 "ircd_parser.y"
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
#line 2702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 2711 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2715 "ircd_parser.y"
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
#line 2737 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 2743 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 2757 "ircd_parser.y"
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
#line 2775 "ircd_parser.y"
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
#line 2782 "ircd_parser.y"
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
#line 2822 "ircd_parser.y"
    {
}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 2827 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 448:

/* Line 1806 of yacc.c  */
#line 2836 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 449:

/* Line 1806 of yacc.c  */
#line 2842 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2887 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2892 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2902 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2907 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2912 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2917 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2922 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2927 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2932 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2937 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2942 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2947 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2952 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2957 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2962 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2967 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2972 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2977 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2983 "ircd_parser.y"
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

  case 530:

/* Line 1806 of yacc.c  */
#line 2994 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2999 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3008 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3013 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3018 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3023 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 3028 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 3033 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3036 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3041 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3044 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3049 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3054 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3059 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3064 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3069 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3074 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3079 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3089 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3100 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3105 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3110 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3124 "ircd_parser.y"
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

  case 555:

/* Line 1806 of yacc.c  */
#line 3156 "ircd_parser.y"
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

  case 556:

/* Line 1806 of yacc.c  */
#line 3174 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3179 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3188 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3197 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3202 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3207 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3212 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3218 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3224 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3227 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3233 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3242 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3248 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3266 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3277 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3283 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3286 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3289 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3292 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3295 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3298 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3301 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3304 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3307 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3316 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3319 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3325 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3328 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3331 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3334 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3337 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3342 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:

/* Line 1806 of yacc.c  */
#line 3347 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 3352 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 3357 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3366 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 3373 "ircd_parser.y"
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

  case 623:

/* Line 1806 of yacc.c  */
#line 3399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 3405 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 3411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 3417 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 3421 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 3427 "ircd_parser.y"
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

  case 632:

/* Line 1806 of yacc.c  */
#line 3461 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 3470 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3474 "ircd_parser.y"
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

  case 637:

/* Line 1806 of yacc.c  */
#line 3521 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3525 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3549 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3554 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3559 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3564 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3569 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3574 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3579 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3584 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3589 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3594 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 671:

/* Line 1806 of yacc.c  */
#line 3599 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 3604 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 3609 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 3614 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 3619 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 3624 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 3629 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 3634 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 690:

/* Line 1806 of yacc.c  */
#line 3653 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 691:

/* Line 1806 of yacc.c  */
#line 3659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 692:

/* Line 1806 of yacc.c  */
#line 3665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 693:

/* Line 1806 of yacc.c  */
#line 3674 "ircd_parser.y"
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

  case 694:

/* Line 1806 of yacc.c  */
#line 3688 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 695:

/* Line 1806 of yacc.c  */
#line 3694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 696:

/* Line 1806 of yacc.c  */
#line 3700 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 8122 "ircd_parser.c"
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



