
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



/* Line 189 of yacc.c  */
#line 184 "ircd_parser.c"

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
     T_SSL_CONNECTION_METHOD = 425,
     T_SSLV3 = 426,
     T_TLSV1 = 427,
     RESV = 428,
     RESV_EXEMPT = 429,
     SECONDS = 430,
     MINUTES = 431,
     HOURS = 432,
     DAYS = 433,
     WEEKS = 434,
     SENDQ = 435,
     SEND_PASSWORD = 436,
     SERVERHIDE = 437,
     SERVERINFO = 438,
     SERVLINK_PATH = 439,
     IRCD_SID = 440,
     TKLINE_EXPIRE_NOTICES = 441,
     T_SHARED = 442,
     T_CLUSTER = 443,
     TYPE = 444,
     SHORT_MOTD = 445,
     SILENT = 446,
     SPOOF = 447,
     SPOOF_NOTICE = 448,
     STATS_E_DISABLED = 449,
     STATS_I_OPER_ONLY = 450,
     STATS_K_OPER_ONLY = 451,
     STATS_O_OPER_ONLY = 452,
     STATS_P_OPER_ONLY = 453,
     TBOOL = 454,
     TMASKED = 455,
     T_REJECT = 456,
     TS_MAX_DELTA = 457,
     TS_WARN_DELTA = 458,
     TWODOTS = 459,
     T_ALL = 460,
     T_BOTS = 461,
     T_SOFTCALLERID = 462,
     T_CALLERID = 463,
     T_CCONN = 464,
     T_CCONN_FULL = 465,
     T_CLIENT_FLOOD = 466,
     T_DEAF = 467,
     T_DEBUG = 468,
     T_DRONE = 469,
     T_EXTERNAL = 470,
     T_FULL = 471,
     T_INVISIBLE = 472,
     T_IPV4 = 473,
     T_IPV6 = 474,
     T_LOCOPS = 475,
     T_LOGPATH = 476,
     T_L_CRIT = 477,
     T_L_DEBUG = 478,
     T_L_ERROR = 479,
     T_L_INFO = 480,
     T_L_NOTICE = 481,
     T_L_TRACE = 482,
     T_L_WARN = 483,
     T_MAX_CLIENTS = 484,
     T_NCHANGE = 485,
     T_OPERWALL = 486,
     T_REJ = 487,
     T_SERVER = 488,
     T_SERVNOTICE = 489,
     T_SKILL = 490,
     T_SPY = 491,
     T_SSL = 492,
     T_UMODES = 493,
     T_UNAUTH = 494,
     T_UNRESV = 495,
     T_UNXLINE = 496,
     T_WALLOP = 497,
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
#define T_SSL_CONNECTION_METHOD 425
#define T_SSLV3 426
#define T_TLSV1 427
#define RESV 428
#define RESV_EXEMPT 429
#define SECONDS 430
#define MINUTES 431
#define HOURS 432
#define DAYS 433
#define WEEKS 434
#define SENDQ 435
#define SEND_PASSWORD 436
#define SERVERHIDE 437
#define SERVERINFO 438
#define SERVLINK_PATH 439
#define IRCD_SID 440
#define TKLINE_EXPIRE_NOTICES 441
#define T_SHARED 442
#define T_CLUSTER 443
#define TYPE 444
#define SHORT_MOTD 445
#define SILENT 446
#define SPOOF 447
#define SPOOF_NOTICE 448
#define STATS_E_DISABLED 449
#define STATS_I_OPER_ONLY 450
#define STATS_K_OPER_ONLY 451
#define STATS_O_OPER_ONLY 452
#define STATS_P_OPER_ONLY 453
#define TBOOL 454
#define TMASKED 455
#define T_REJECT 456
#define TS_MAX_DELTA 457
#define TS_WARN_DELTA 458
#define TWODOTS 459
#define T_ALL 460
#define T_BOTS 461
#define T_SOFTCALLERID 462
#define T_CALLERID 463
#define T_CCONN 464
#define T_CCONN_FULL 465
#define T_CLIENT_FLOOD 466
#define T_DEAF 467
#define T_DEBUG 468
#define T_DRONE 469
#define T_EXTERNAL 470
#define T_FULL 471
#define T_INVISIBLE 472
#define T_IPV4 473
#define T_IPV6 474
#define T_LOCOPS 475
#define T_LOGPATH 476
#define T_L_CRIT 477
#define T_L_DEBUG 478
#define T_L_ERROR 479
#define T_L_INFO 480
#define T_L_NOTICE 481
#define T_L_TRACE 482
#define T_L_WARN 483
#define T_MAX_CLIENTS 484
#define T_NCHANGE 485
#define T_OPERWALL 486
#define T_REJ 487
#define T_SERVER 488
#define T_SERVNOTICE 489
#define T_SKILL 490
#define T_SPY 491
#define T_SSL 492
#define T_UMODES 493
#define T_UNAUTH 494
#define T_UNRESV 495
#define T_UNXLINE 496
#define T_WALLOP 497
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

/* Line 214 of yacc.c  */
#line 135 "ircd_parser.y"

  int number;
  char *string;



/* Line 214 of yacc.c  */
#line 749 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 761 "ircd_parser.c"

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
#define YYLAST   1413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  267
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  346
/* YYNRULES -- Number of rules.  */
#define YYNRULES  743
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1494

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
    1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,  1641,  1646,
    1651,  1656,  1661,  1666,  1671,  1676,  1681,  1686,  1691,  1696,
    1701,  1706,  1711,  1716,  1721,  1726,  1731,  1736,  1741,  1746,
    1751,  1756,  1761,  1766,  1771,  1776,  1781,  1786,  1791,  1796,
    1801,  1806,  1811,  1816,  1821,  1826,  1831,  1836,  1841,  1846,
    1851,  1856,  1861,  1866,  1871,  1876,  1881,  1886,  1891,  1892,
    1898,  1902,  1904,  1906,  1908,  1910,  1912,  1914,  1916,  1918,
    1920,  1922,  1924,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1943,  1949,  1953,  1955,  1957,  1959,  1961,  1963,
    1965,  1967,  1969,  1971,  1973,  1975,  1977,  1979,  1981,  1983,
    1985,  1987,  1989,  1991,  1993,  1998,  2003,  2008,  2013,  2018,
    2019,  2026,  2029,  2031,  2033,  2035,  2037,  2039,  2041,  2043,
    2045,  2050,  2055,  2056,  2062,  2066,  2068,  2070,  2072,  2077,
    2082,  2083,  2089,  2093,  2095,  2097,  2099,  2105,  2108,  2110,
    2112,  2114,  2116,  2118,  2120,  2122,  2124,  2126,  2128,  2130,
    2132,  2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2153,
    2158,  2163,  2168,  2173,  2178,  2183,  2188,  2193,  2198,  2203,
    2208,  2213,  2218,  2223,  2228,  2233,  2238,  2244,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2270,  2275,
    2280,  2285,  2290,  2295
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     268,     0,    -1,    -1,   268,   269,    -1,   297,    -1,   303,
      -1,   318,    -1,   582,    -1,   355,    -1,   374,    -1,   388,
      -1,   279,    -1,   603,    -1,   414,    -1,   421,    -1,   431,
      -1,   440,    -1,   471,    -1,   481,    -1,   487,    -1,   501,
      -1,   566,    -1,   491,    -1,   274,    -1,     1,   262,    -1,
       1,   263,    -1,    -1,   271,    -1,   133,   270,    -1,   133,
     175,   270,    -1,   133,   176,   270,    -1,   133,   177,   270,
      -1,   133,   178,   270,    -1,   133,   179,   270,    -1,    -1,
     273,    -1,   133,   272,    -1,   133,    14,   272,    -1,   133,
      15,   272,    -1,   133,    16,   272,    -1,   121,   264,   275,
     263,   262,    -1,   275,   276,    -1,   276,    -1,   277,    -1,
     278,    -1,     1,   262,    -1,   120,   265,   155,   262,    -1,
     150,   265,   155,   262,    -1,   183,   264,   280,   263,   262,
      -1,   280,   281,    -1,   281,    -1,   288,    -1,   293,    -1,
     296,    -1,   290,    -1,   291,    -1,   292,    -1,   295,    -1,
     287,    -1,   294,    -1,   289,    -1,   286,    -1,   282,    -1,
       1,   262,    -1,    -1,   170,   283,   265,   284,   262,    -1,
     284,   266,   285,    -1,   285,    -1,   171,    -1,   172,    -1,
     169,   265,   155,   262,    -1,   167,   265,   155,   262,    -1,
     122,   265,   155,   262,    -1,   185,   265,   155,   262,    -1,
      37,   265,   155,   262,    -1,   125,   265,   155,   262,    -1,
     124,   265,   155,   262,    -1,   257,   265,   155,   262,    -1,
     258,   265,   155,   262,    -1,   229,   265,   133,   262,    -1,
      86,   265,   199,   262,    -1,     5,   264,   298,   263,   262,
      -1,   298,   299,    -1,   299,    -1,   300,    -1,   302,    -1,
     301,    -1,     1,   262,    -1,   122,   265,   155,   262,    -1,
      48,   265,   155,   262,    -1,    37,   265,   155,   262,    -1,
     104,   264,   304,   263,   262,    -1,   304,   305,    -1,   305,
      -1,   306,    -1,   307,    -1,   316,    -1,   317,    -1,   308,
      -1,   310,    -1,   312,    -1,   313,    -1,   315,    -1,   311,
      -1,   314,    -1,   309,    -1,     1,   262,    -1,   221,   265,
     155,   262,    -1,   140,   265,   155,   262,    -1,    64,   265,
     155,   262,    -1,    57,   265,   155,   262,    -1,    62,   265,
     155,   262,    -1,    63,   265,   155,   262,    -1,    60,   265,
     155,   262,    -1,    59,   265,   155,   262,    -1,    61,   265,
     155,   262,    -1,    58,   265,   155,   262,    -1,   105,   265,
     222,   262,    -1,   105,   265,   224,   262,    -1,   105,   265,
     228,   262,    -1,   105,   265,   226,   262,    -1,   105,   265,
     227,   262,    -1,   105,   265,   225,   262,    -1,   105,   265,
     223,   262,    -1,   255,   265,   199,   262,    -1,    -1,   138,
     319,   320,   264,   321,   263,   262,    -1,    -1,   324,    -1,
     321,   322,    -1,   322,    -1,   323,    -1,   325,    -1,   326,
      -1,   345,    -1,   346,    -1,   330,    -1,   329,    -1,   334,
      -1,   335,    -1,   337,    -1,   338,    -1,   339,    -1,   340,
      -1,   341,    -1,   336,    -1,   342,    -1,   343,    -1,   344,
      -1,   347,    -1,   327,    -1,   328,    -1,   348,    -1,     1,
     262,    -1,   122,   265,   155,   262,    -1,   155,    -1,   250,
     265,   155,   262,    -1,   149,   265,   155,   262,    -1,    50,
     265,   199,   262,    -1,   168,   265,   155,   262,    -1,    26,
     265,   155,   262,    -1,    -1,   238,   331,   265,   332,   262,
      -1,   332,   266,   333,    -1,   333,    -1,   206,    -1,   209,
      -1,   210,    -1,   212,    -1,   213,    -1,   216,    -1,   235,
      -1,   230,    -1,   232,    -1,   239,    -1,   236,    -1,   215,
      -1,   231,    -1,   234,    -1,   217,    -1,   242,    -1,   207,
      -1,   208,    -1,   220,    -1,    74,   265,   199,   262,    -1,
     163,   265,   199,   262,    -1,   164,   265,   199,   262,    -1,
      94,   265,   199,   262,    -1,   259,   265,   199,   262,    -1,
     249,   265,   199,   262,    -1,    67,   265,   199,   262,    -1,
     127,   265,   199,   262,    -1,    38,   265,   199,   262,    -1,
     161,   265,   199,   262,    -1,     5,   265,   199,   262,    -1,
      79,   265,   199,   262,    -1,    81,   265,   199,   262,    -1,
     231,   265,   199,   262,    -1,    -1,    55,   349,   265,   350,
     262,    -1,   350,   266,   351,    -1,   351,    -1,    -1,   132,
     352,   354,    -1,    -1,   353,   354,    -1,    74,    -1,   163,
      -1,    94,    -1,   249,    -1,   259,    -1,    67,    -1,    38,
      -1,   161,    -1,     5,    -1,    79,    -1,   127,    -1,   231,
      -1,   143,    -1,    81,    -1,   164,    -1,    50,    -1,    -1,
      26,   356,   357,   264,   358,   263,   262,    -1,    -1,   361,
      -1,   358,   359,    -1,   359,    -1,   360,    -1,   371,    -1,
     372,    -1,   362,    -1,   363,    -1,   373,    -1,   364,    -1,
     365,    -1,   366,    -1,   367,    -1,   368,    -1,   369,    -1,
     370,    -1,     1,   262,    -1,   122,   265,   155,   262,    -1,
     155,    -1,   152,   265,   271,   262,    -1,   153,   265,   271,
     262,    -1,   136,   265,   133,   262,    -1,    30,   265,   271,
     262,    -1,   114,   265,   133,   262,    -1,   109,   265,   133,
     262,    -1,   111,   265,   133,   262,    -1,   110,   265,   133,
     262,    -1,   180,   265,   273,   262,    -1,    23,   265,   133,
     262,    -1,    24,   265,   133,   262,    -1,   135,   265,   133,
     262,    -1,    -1,   102,   375,   264,   380,   263,   262,    -1,
      -1,    55,   377,   265,   378,   262,    -1,   378,   266,   379,
      -1,   379,    -1,   237,    -1,    78,    -1,   233,    -1,   380,
     381,    -1,   381,    -1,   382,    -1,   376,    -1,   386,    -1,
     387,    -1,     1,   262,    -1,    -1,   154,   265,   384,   383,
     262,    -1,   384,   266,   385,    -1,   385,    -1,   133,    -1,
     133,   204,   133,    -1,    91,   265,   155,   262,    -1,    85,
     265,   155,   262,    -1,    -1,    75,   389,   264,   390,   263,
     262,    -1,   390,   391,    -1,   391,    -1,   392,    -1,   393,
      -1,   395,    -1,   397,    -1,   404,    -1,   405,    -1,   406,
      -1,   408,    -1,   409,    -1,   410,    -1,   394,    -1,   411,
      -1,   412,    -1,   407,    -1,   413,    -1,   396,    -1,     1,
     262,    -1,   250,   265,   155,   262,    -1,   149,   265,   155,
     262,    -1,   193,   265,   199,   262,    -1,    26,   265,   155,
     262,    -1,    50,   265,   199,   262,    -1,    -1,    55,   398,
     265,   399,   262,    -1,   399,   266,   400,    -1,   400,    -1,
      -1,   132,   401,   403,    -1,    -1,   402,   403,    -1,   193,
      -1,    51,    -1,    95,    -1,    76,    -1,    20,    -1,    21,
      -1,   131,    -1,    69,    -1,   174,    -1,   123,    -1,    95,
     265,   199,   262,    -1,    76,   265,   199,   262,    -1,    51,
     265,   199,   262,    -1,    20,   265,   199,   262,    -1,   131,
     265,   199,   262,    -1,    69,   265,   199,   262,    -1,   192,
     265,   155,   262,    -1,   159,   265,   155,   262,    -1,   158,
     265,   133,   262,    -1,   123,   265,   199,   262,    -1,    -1,
     173,   415,   264,   416,   263,   262,    -1,   416,   417,    -1,
     417,    -1,   418,    -1,   419,    -1,   420,    -1,     1,   262,
      -1,   157,   265,   155,   262,    -1,    22,   265,   155,   262,
      -1,   126,   265,   155,   262,    -1,    -1,   187,   422,   264,
     423,   263,   262,    -1,   423,   424,    -1,   424,    -1,   425,
      -1,   426,    -1,   427,    -1,     1,   262,    -1,   122,   265,
     155,   262,    -1,   250,   265,   155,   262,    -1,    -1,   189,
     428,   265,   429,   262,    -1,   429,   266,   430,    -1,   430,
      -1,    94,    -1,   246,    -1,   249,    -1,   259,    -1,   247,
      -1,   241,    -1,   173,    -1,   248,    -1,   240,    -1,   220,
      -1,   205,    -1,    -1,   188,   432,   264,   433,   263,   262,
      -1,   433,   434,    -1,   434,    -1,   435,    -1,   436,    -1,
       1,   262,    -1,   122,   265,   155,   262,    -1,    -1,   189,
     437,   265,   438,   262,    -1,   438,   266,   439,    -1,   439,
      -1,    94,    -1,   246,    -1,   249,    -1,   259,    -1,   247,
      -1,   241,    -1,   173,    -1,   248,    -1,   240,    -1,   220,
      -1,   205,    -1,    -1,    29,   441,   442,   264,   443,   263,
     262,    -1,    -1,   446,    -1,   443,   444,    -1,   444,    -1,
     445,    -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,
     452,    -1,   451,    -1,   453,    -1,   454,    -1,   467,    -1,
     468,    -1,   469,    -1,   465,    -1,   462,    -1,   464,    -1,
     463,    -1,   461,    -1,   470,    -1,   466,    -1,     1,   262,
      -1,   122,   265,   155,   262,    -1,   155,    -1,    85,   265,
     155,   262,    -1,   257,   265,   155,   262,    -1,   181,   265,
     155,   262,    -1,     3,   265,   155,   262,    -1,   154,   265,
     133,   262,    -1,     6,   265,   218,   262,    -1,     6,   265,
     219,   262,    -1,    54,   265,   155,   262,    -1,    -1,    55,
     455,   265,   456,   262,    -1,   456,   266,   457,    -1,   457,
      -1,    -1,   132,   458,   460,    -1,    -1,   459,   460,    -1,
      27,    -1,    31,    -1,    10,    -1,    12,    -1,   244,    -1,
     168,   265,   155,   262,    -1,    50,   265,   199,   262,    -1,
      31,   265,   199,   262,    -1,    27,   265,   199,   262,    -1,
      10,   265,   199,   262,    -1,   244,   265,   199,   262,    -1,
      87,   265,   155,   262,    -1,   100,   265,   155,   262,    -1,
      26,   265,   155,   262,    -1,    25,   265,   155,   262,    -1,
      -1,    92,   472,   264,   477,   263,   262,    -1,    -1,   189,
     474,   265,   475,   262,    -1,   475,   266,   476,    -1,   476,
      -1,   160,    -1,   477,   478,    -1,   478,    -1,   479,    -1,
     480,    -1,   473,    -1,     1,    -1,   250,   265,   155,   262,
      -1,   157,   265,   155,   262,    -1,    -1,    36,   482,   264,
     483,   263,   262,    -1,   483,   484,    -1,   484,    -1,   485,
      -1,   486,    -1,     1,    -1,    91,   265,   155,   262,    -1,
     157,   265,   155,   262,    -1,    52,   264,   488,   263,   262,
      -1,   488,   489,    -1,   489,    -1,   490,    -1,     1,    -1,
      91,   265,   155,   262,    -1,    -1,    65,   492,   264,   497,
     263,   262,    -1,    -1,   189,   494,   265,   495,   262,    -1,
     495,   266,   496,    -1,   496,    -1,   160,    -1,   497,   498,
      -1,   498,    -1,   499,    -1,   500,    -1,   493,    -1,     1,
      -1,   122,   265,   155,   262,    -1,   157,   265,   155,   262,
      -1,    66,   264,   502,   263,   262,    -1,   502,   503,    -1,
     503,    -1,   512,    -1,   513,    -1,   515,    -1,   516,    -1,
     517,    -1,   518,    -1,   519,    -1,   520,    -1,   521,    -1,
     522,    -1,   511,    -1,   524,    -1,   525,    -1,   526,    -1,
     527,    -1,   543,    -1,   529,    -1,   531,    -1,   533,    -1,
     532,    -1,   536,    -1,   530,    -1,   537,    -1,   538,    -1,
     539,    -1,   540,    -1,   542,    -1,   541,    -1,   557,    -1,
     544,    -1,   548,    -1,   549,    -1,   553,    -1,   534,    -1,
     535,    -1,   563,    -1,   561,    -1,   562,    -1,   545,    -1,
     514,    -1,   546,    -1,   547,    -1,   564,    -1,   552,    -1,
     523,    -1,   565,    -1,   550,    -1,   551,    -1,   507,    -1,
     510,    -1,   505,    -1,   506,    -1,   508,    -1,   509,    -1,
     528,    -1,   504,    -1,     1,    -1,   116,   265,   133,   262,
      -1,    72,   265,   133,   262,    -1,    73,   265,   133,   262,
      -1,    12,   265,   199,   262,    -1,   256,   265,   199,   262,
      -1,   162,   265,   271,   262,    -1,   186,   265,   199,   262,
      -1,    93,   265,   133,   262,    -1,    84,   265,   199,   262,
      -1,    89,   265,   199,   262,    -1,    43,   265,   199,   262,
      -1,    53,   265,   199,   262,    -1,     8,   265,   199,   262,
      -1,   113,   265,   271,   262,    -1,   112,   265,   133,   262,
      -1,   106,   265,   133,   262,    -1,     9,   265,   271,   262,
      -1,   203,   265,   271,   262,    -1,   202,   265,   271,   262,
      -1,    77,   265,   133,   262,    -1,    97,   265,   199,   262,
      -1,    96,   265,   155,   262,    -1,    90,   265,   199,   262,
      -1,   261,   265,   199,   262,    -1,   194,   265,   199,   262,
      -1,   197,   265,   199,   262,    -1,   198,   265,   199,   262,
      -1,   196,   265,   199,   262,    -1,   196,   265,   200,   262,
      -1,   195,   265,   199,   262,    -1,   195,   265,   200,   262,
      -1,   147,   265,   271,   262,    -1,    19,   265,   271,   262,
      -1,   139,   265,   199,   262,    -1,   148,   265,   271,   262,
      -1,   190,   265,   199,   262,    -1,   130,   265,   199,   262,
      -1,   245,   265,   199,   262,    -1,   142,   265,   199,   262,
      -1,   117,   265,   155,   262,    -1,    88,   265,   271,   262,
      -1,    45,   265,   133,   262,    -1,   115,   265,   133,   262,
      -1,   184,   265,   155,   262,    -1,    32,   265,   155,   262,
      -1,    28,   265,   133,   262,    -1,   251,   265,   199,   262,
      -1,    47,   265,   155,   262,    -1,   151,   265,   199,   262,
      -1,    39,   265,   199,   262,    -1,   243,   265,   271,   262,
      -1,    -1,   144,   554,   265,   555,   262,    -1,   555,   266,
     556,    -1,   556,    -1,   206,    -1,   209,    -1,   210,    -1,
     212,    -1,   213,    -1,   216,    -1,   235,    -1,   230,    -1,
     232,    -1,   239,    -1,   236,    -1,   215,    -1,   231,    -1,
     234,    -1,   217,    -1,   242,    -1,   207,    -1,   208,    -1,
     220,    -1,    -1,   141,   558,   265,   559,   262,    -1,   559,
     266,   560,    -1,   560,    -1,   206,    -1,   209,    -1,   210,
      -1,   212,    -1,   213,    -1,   216,    -1,   235,    -1,   230,
      -1,   232,    -1,   239,    -1,   236,    -1,   215,    -1,   231,
      -1,   234,    -1,   217,    -1,   242,    -1,   207,    -1,   208,
      -1,   220,    -1,   118,   265,   133,   262,    -1,   119,   265,
     133,   262,    -1,    33,   265,   133,   262,    -1,   211,   265,
     273,   262,    -1,    44,   265,   199,   262,    -1,    -1,    68,
     567,   264,   568,   263,   262,    -1,   568,   569,    -1,   569,
      -1,   570,    -1,   571,    -1,   572,    -1,   576,    -1,   577,
      -1,   578,    -1,     1,    -1,    49,   265,   199,   262,    -1,
      46,   265,   271,   262,    -1,    -1,   104,   573,   265,   574,
     262,    -1,   574,   266,   575,    -1,   575,    -1,   201,    -1,
      11,    -1,   250,   265,   155,   262,    -1,   122,   265,   155,
     262,    -1,    -1,     4,   579,   265,   580,   262,    -1,   580,
     266,   581,    -1,   581,    -1,   201,    -1,    11,    -1,    22,
     264,   583,   263,   262,    -1,   583,   584,    -1,   584,    -1,
     587,    -1,   588,    -1,   589,    -1,   590,    -1,   595,    -1,
     591,    -1,   592,    -1,   593,    -1,   594,    -1,   596,    -1,
     597,    -1,   598,    -1,   586,    -1,   599,    -1,   600,    -1,
     601,    -1,   602,    -1,   585,    -1,     1,    -1,    40,   265,
     199,   262,    -1,   165,   265,   199,   262,    -1,    42,   265,
     199,   262,    -1,   252,   265,   199,   262,    -1,   253,   265,
     199,   262,    -1,   254,   265,   199,   262,    -1,    98,   265,
     271,   262,    -1,    99,   265,   271,   262,    -1,   108,   265,
     133,   262,    -1,   156,   265,   199,   262,    -1,   107,   265,
     133,   262,    -1,    35,   265,   133,   262,    -1,    34,   265,
     133,   262,    -1,   128,   265,   199,   262,    -1,   129,   265,
     199,   262,    -1,    13,   265,   199,   262,    -1,   145,   265,
     133,   262,    -1,   146,   265,   271,   262,    -1,   182,   264,
     604,   263,   262,    -1,   604,   605,    -1,   605,    -1,   606,
      -1,   607,    -1,   609,    -1,   611,    -1,   610,    -1,   608,
      -1,   612,    -1,     1,    -1,    56,   265,   199,   262,    -1,
      83,   265,   199,   262,    -1,    80,   265,   155,   262,    -1,
     101,   265,   271,   262,    -1,    78,   265,   199,   262,    -1,
      41,   265,   199,   262,    -1,    82,   265,   199,   262,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   400,   400,   401,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   429,   429,   430,   434,
     438,   442,   446,   450,   456,   456,   457,   458,   459,   460,
     467,   470,   470,   471,   471,   471,   473,   481,   490,   492,
     492,   493,   493,   494,   494,   495,   495,   496,   497,   497,
     498,   498,   499,   500,   504,   503,   518,   518,   519,   523,
     529,   563,   623,   637,   652,   661,   675,   684,   712,   742,
     765,   787,   789,   789,   790,   790,   791,   791,   793,   802,
     811,   824,   826,   827,   829,   829,   830,   831,   831,   832,
     832,   833,   833,   834,   834,   835,   836,   838,   842,   846,
     853,   860,   867,   874,   881,   888,   895,   902,   906,   910,
     914,   918,   922,   926,   932,   942,   941,  1035,  1035,  1036,
    1036,  1037,  1037,  1037,  1037,  1038,  1038,  1039,  1039,  1039,
    1040,  1040,  1040,  1041,  1041,  1041,  1042,  1042,  1042,  1042,
    1043,  1043,  1044,  1044,  1046,  1058,  1070,  1104,  1116,  1127,
    1169,  1179,  1178,  1184,  1184,  1185,  1189,  1193,  1197,  1201,
    1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,
    1245,  1249,  1253,  1257,  1263,  1274,  1285,  1296,  1307,  1318,
    1329,  1340,  1351,  1362,  1373,  1384,  1395,  1406,  1418,  1417,
    1421,  1421,  1422,  1422,  1423,  1423,  1425,  1432,  1439,  1446,
    1453,  1460,  1467,  1474,  1481,  1488,  1495,  1502,  1509,  1516,
    1523,  1530,  1544,  1543,  1593,  1593,  1595,  1595,  1596,  1597,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1610,  1619,  1628,  1634,  1640,  1646,  1652,  1658,
    1664,  1670,  1676,  1682,  1688,  1694,  1704,  1703,  1720,  1719,
    1724,  1724,  1725,  1729,  1733,  1741,  1741,  1742,  1742,  1742,
    1742,  1742,  1744,  1744,  1746,  1746,  1748,  1762,  1782,  1791,
    1804,  1803,  1872,  1872,  1873,  1873,  1873,  1873,  1874,  1874,
    1875,  1875,  1875,  1876,  1876,  1877,  1877,  1877,  1878,  1878,
    1878,  1880,  1917,  1930,  1941,  1950,  1962,  1961,  1965,  1965,
    1966,  1966,  1967,  1967,  1969,  1977,  1984,  1991,  1998,  2005,
    2012,  2019,  2026,  2033,  2042,  2053,  2064,  2075,  2086,  2097,
    2109,  2128,  2138,  2147,  2163,  2162,  2178,  2178,  2179,  2179,
    2179,  2179,  2181,  2190,  2205,  2219,  2218,  2234,  2234,  2235,
    2235,  2235,  2235,  2237,  2246,  2269,  2268,  2274,  2274,  2275,
    2279,  2283,  2287,  2291,  2295,  2299,  2303,  2307,  2311,  2315,
    2325,  2324,  2341,  2341,  2342,  2342,  2342,  2344,  2351,  2350,
    2356,  2356,  2357,  2361,  2365,  2369,  2373,  2377,  2381,  2385,
    2389,  2393,  2397,  2407,  2406,  2552,  2552,  2553,  2553,  2554,
    2554,  2554,  2555,  2555,  2556,  2556,  2557,  2557,  2557,  2558,
    2558,  2558,  2559,  2559,  2559,  2560,  2560,  2561,  2561,  2563,
    2575,  2587,  2596,  2622,  2640,  2658,  2664,  2668,  2676,  2686,
    2685,  2689,  2689,  2690,  2690,  2691,  2691,  2693,  2704,  2711,
    2718,  2725,  2735,  2776,  2787,  2798,  2813,  2824,  2835,  2848,
    2861,  2870,  2906,  2905,  2970,  2969,  2973,  2973,  2974,  2980,
    2980,  2981,  2981,  2981,  2981,  2983,  3002,  3012,  3011,  3033,
    3033,  3034,  3034,  3034,  3036,  3045,  3057,  3059,  3059,  3060,
    3060,  3062,  3084,  3083,  3126,  3125,  3129,  3129,  3130,  3136,
    3136,  3137,  3137,  3137,  3137,  3139,  3145,  3154,  3157,  3157,
    3158,  3158,  3159,  3159,  3160,  3160,  3161,  3161,  3162,  3162,
    3163,  3163,  3164,  3164,  3165,  3165,  3166,  3166,  3167,  3167,
    3168,  3168,  3169,  3169,  3170,  3170,  3171,  3171,  3172,  3172,
    3173,  3173,  3174,  3174,  3175,  3175,  3176,  3176,  3177,  3177,
    3178,  3179,  3179,  3180,  3180,  3181,  3181,  3182,  3182,  3183,
    3183,  3184,  3184,  3185,  3185,  3186,  3187,  3190,  3195,  3200,
    3205,  3210,  3215,  3220,  3225,  3230,  3235,  3240,  3245,  3250,
    3255,  3260,  3265,  3270,  3275,  3280,  3286,  3297,  3302,  3311,
    3316,  3321,  3326,  3331,  3336,  3339,  3344,  3347,  3352,  3357,
    3362,  3367,  3372,  3377,  3382,  3387,  3392,  3403,  3408,  3413,
    3418,  3427,  3459,  3477,  3482,  3491,  3496,  3501,  3507,  3506,
    3511,  3511,  3512,  3515,  3518,  3521,  3524,  3527,  3530,  3533,
    3536,  3539,  3542,  3545,  3548,  3551,  3554,  3557,  3560,  3563,
    3566,  3572,  3571,  3576,  3576,  3577,  3580,  3583,  3586,  3589,
    3592,  3595,  3598,  3601,  3604,  3607,  3610,  3613,  3616,  3619,
    3622,  3625,  3628,  3631,  3636,  3641,  3646,  3651,  3656,  3665,
    3664,  3688,  3688,  3689,  3690,  3691,  3692,  3693,  3694,  3695,
    3697,  3703,  3710,  3709,  3714,  3714,  3715,  3719,  3725,  3759,
    3769,  3768,  3818,  3818,  3819,  3823,  3832,  3835,  3835,  3836,
    3836,  3837,  3837,  3838,  3838,  3839,  3839,  3840,  3840,  3841,
    3842,  3842,  3843,  3843,  3844,  3844,  3845,  3845,  3847,  3852,
    3857,  3862,  3867,  3872,  3877,  3882,  3887,  3892,  3897,  3902,
    3907,  3912,  3917,  3922,  3927,  3932,  3940,  3943,  3943,  3944,
    3944,  3945,  3946,  3947,  3947,  3948,  3949,  3951,  3957,  3963,
    3972,  3986,  3992,  3998
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
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "$@31",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
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
     269,   269,   269,   269,   269,   269,   270,   270,   271,   271,
     271,   271,   271,   271,   272,   272,   273,   273,   273,   273,
     274,   275,   275,   276,   276,   276,   277,   278,   279,   280,
     280,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   283,   282,   284,   284,   285,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   298,   299,   299,   299,   299,   300,   301,
     302,   303,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   316,   316,
     316,   316,   316,   316,   317,   319,   318,   320,   320,   321,
     321,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   323,   324,   325,   326,   327,   328,
     329,   331,   330,   332,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     333,   333,   333,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   349,   348,
     350,   350,   352,   351,   353,   351,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   356,   355,   357,   357,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   375,   374,   377,   376,
     378,   378,   379,   379,   379,   380,   380,   381,   381,   381,
     381,   381,   383,   382,   384,   384,   385,   385,   386,   387,
     389,   388,   390,   390,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   392,   393,   394,   395,   396,   398,   397,   399,   399,
     401,   400,   402,   400,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   415,   414,   416,   416,   417,   417,
     417,   417,   418,   419,   420,   422,   421,   423,   423,   424,
     424,   424,   424,   425,   426,   428,   427,   429,   429,   430,
     430,   430,   430,   430,   430,   430,   430,   430,   430,   430,
     432,   431,   433,   433,   434,   434,   434,   435,   437,   436,
     438,   438,   439,   439,   439,   439,   439,   439,   439,   439,
     439,   439,   439,   441,   440,   442,   442,   443,   443,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   452,   453,   455,
     454,   456,   456,   458,   457,   459,   457,   460,   460,   460,
     460,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   472,   471,   474,   473,   475,   475,   476,   477,
     477,   478,   478,   478,   478,   479,   480,   482,   481,   483,
     483,   484,   484,   484,   485,   486,   487,   488,   488,   489,
     489,   490,   492,   491,   494,   493,   495,   495,   496,   497,
     497,   498,   498,   498,   498,   499,   500,   501,   502,   502,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   531,   532,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   554,   553,
     555,   555,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   558,   557,   559,   559,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   561,   562,   563,   564,   565,   567,
     566,   568,   568,   569,   569,   569,   569,   569,   569,   569,
     570,   571,   573,   572,   574,   574,   575,   575,   576,   577,
     579,   578,   580,   580,   581,   581,   582,   583,   583,   584,
     584,   584,   584,   584,   584,   584,   584,   584,   584,   584,
     584,   584,   584,   584,   584,   584,   584,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   604,   605,
     605,   605,   605,   605,   605,   605,   605,   606,   607,   608,
     609,   610,   611,   612
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     0,
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   222,   393,   467,     0,
     482,     0,   659,   280,   452,   256,     0,     0,   125,   334,
       0,     0,   345,   370,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   224,
     395,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    86,    85,   707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   688,   706,   701,   689,
     690,   691,   692,   694,   695,   696,   697,   693,   698,   699,
     700,   702,   703,   704,   705,   243,     0,   225,   420,     0,
     396,     0,   480,     0,     0,   478,   479,     0,   556,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   631,     0,   608,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   499,   555,   550,   551,
     548,   552,   553,   549,   510,   500,   501,   539,   502,   503,
     504,   505,   506,   507,   508,   509,   544,   511,   512,   513,
     514,   554,   516,   521,   517,   519,   518,   533,   534,   520,
     522,   523,   524,   525,   527,   526,   515,   529,   538,   540,
     541,   530,   531,   546,   547,   543,   532,   528,   536,   537,
     535,   542,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    98,   105,    99,   103,   100,   101,
     104,   102,    96,    97,     0,     0,     0,     0,    42,    43,
      44,   155,     0,   128,     0,   736,     0,     0,     0,     0,
       0,     0,     0,     0,   728,   729,   730,   734,   731,   733,
     732,   735,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,     0,     0,     0,     0,    50,    62,    61,    58,
      51,    60,    54,    55,    56,    52,    59,    57,    53,     0,
       0,    87,     0,     0,     0,     0,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   687,     0,     0,   473,
       0,     0,     0,   470,   471,   472,     0,     0,   477,   494,
       0,     0,   484,   493,     0,   490,   491,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   498,   669,   680,     0,     0,
     672,     0,     0,     0,   662,   663,   664,   665,   666,   667,
     668,     0,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   283,
     284,   285,   294,   286,   299,   287,   288,   289,   290,   297,
     291,   292,   293,   295,   296,   298,   464,     0,   454,     0,
     463,     0,   460,   461,   462,     0,   258,     0,     0,     0,
     268,     0,   266,   267,   269,   270,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    45,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,   337,   338,   339,   340,     0,     0,     0,     0,
       0,     0,     0,     0,   727,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,   355,     0,     0,   348,   349,   350,   351,     0,
       0,   378,     0,   373,   374,   375,     0,     0,     0,    81,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   686,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   228,   231,   232,   234,
     235,   236,   237,   238,   239,   240,   229,   230,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   429,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     398,   399,   400,   401,   402,   403,   405,   404,   406,   407,
     415,   412,   414,   413,   411,   417,   408,   409,   410,   416,
       0,     0,     0,   469,     0,   476,     0,     0,     0,     0,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
     497,     0,     0,     0,     0,     0,     0,     0,   661,   300,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   282,     0,     0,
       0,     0,   459,   271,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
       0,    40,     0,     0,     0,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,     0,   130,   131,   132,   133,
     150,   151,   137,   136,   138,   139,   145,   140,   141,   142,
     143,   144,   146,   147,   148,   134,   135,   149,   152,   341,
       0,     0,     0,     0,   336,     0,     0,     0,     0,     0,
       0,     0,   726,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,   352,     0,     0,     0,
       0,   347,   376,     0,     0,     0,   372,    90,    89,    88,
     723,   720,   719,   708,   710,    26,    26,    26,    26,    26,
      28,    27,   714,   715,   718,   716,   721,   722,   724,   725,
     717,   709,   711,   712,   713,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   418,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   397,     0,     0,   468,   481,     0,     0,     0,
     483,   569,   573,   560,   589,   602,   601,   656,   606,   567,
     658,   598,   604,   568,   558,   559,   576,   565,   597,   566,
     579,   564,   578,   577,   572,   571,   570,   599,   557,   596,
     654,   655,   593,   590,   635,   651,   652,   636,   637,   638,
     639,   646,   640,   649,   653,   642,   647,   643,   648,   641,
     645,   644,   650,     0,   634,   595,   612,   628,   629,   613,
     614,   615,   616,   623,   617,   626,   630,   619,   624,   620,
     625,   618,   622,   621,   627,     0,   611,   588,   591,   605,
     562,   600,   563,   592,   581,   586,   587,   584,   585,   582,
     583,   575,   574,    34,    34,    34,    36,    35,   657,   607,
     594,   603,   561,   580,     0,     0,     0,     0,     0,     0,
     660,     0,     0,     0,     0,   312,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   281,     0,     0,
       0,   453,     0,     0,     0,   276,   272,   275,   257,   110,
     116,   114,   113,   115,   111,   112,   109,   117,   123,   118,
     122,   120,   121,   119,   108,   107,   124,    46,    47,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,   335,   742,   737,
     741,   739,   743,   738,   740,    74,    80,    72,    76,    75,
      71,    70,    68,    69,     0,    67,    73,    79,    77,    78,
       0,     0,     0,   346,     0,     0,   371,    29,    30,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,   474,   475,   495,
     496,   488,     0,   487,   632,     0,   609,     0,    37,    38,
      39,   685,   684,     0,   683,   671,   670,   677,   676,     0,
     675,   679,   678,   327,   304,   305,   326,   310,     0,   309,
       0,   329,   325,   324,   333,   328,   302,   332,   331,   330,
     303,   301,   466,   458,     0,   457,   465,   263,   264,   262,
       0,   261,   279,   278,     0,     0,     0,     0,     0,     0,
       0,   204,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     343,   344,   342,    65,     0,   353,   359,   365,   369,   368,
     367,   364,   360,   363,   366,   361,   362,     0,   358,   354,
     377,   382,   388,   392,   391,   390,   387,   383,   386,   389,
     384,   385,     0,   381,   253,   254,   247,   249,   251,   250,
     248,   242,   255,   246,   244,   245,   252,   424,   426,   427,
     446,   451,   450,   445,   444,   443,   428,   433,     0,   432,
       0,   421,   448,   449,   419,   425,   442,   423,   447,   422,
     485,     0,   633,   610,   681,     0,   673,     0,     0,   307,
     312,   318,   319,   315,   321,   317,   316,   323,   320,   322,
     314,   313,   455,     0,   259,     0,   277,   274,   273,   194,
     160,   192,   158,   202,     0,   201,     0,   190,   184,   195,
     196,   187,   154,   191,   157,   193,   185,   186,   159,   197,
     165,   181,   182,   166,   167,   168,   169,   176,   170,   179,
     183,   172,   177,   173,   178,   171,   175,   174,   180,     0,
     164,   189,   156,   188,    66,   356,     0,   379,     0,     0,
     430,   435,   439,   440,   437,   438,   441,   436,   486,   682,
     674,   311,   308,   456,   260,     0,   199,   204,   214,   212,
     221,   211,   206,   215,   219,   208,   216,   218,   213,   207,
     220,   217,   209,   210,   205,   162,     0,   357,   380,   434,
     431,   203,   200,   163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   900,   901,  1056,  1057,    25,   277,   278,
     279,   280,    26,   315,   316,   317,   553,  1164,  1165,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
      27,    71,    72,    73,    74,    75,    28,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,    29,    61,   282,   825,   826,   827,   283,   828,   829,
     830,   831,   832,   833,  1138,  1439,  1440,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,  1124,  1404,  1405,  1465,  1406,  1484,    30,    49,
     116,   614,   615,   616,   117,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,    31,    58,   500,
     774,  1270,  1271,   501,   502,   503,  1276,  1096,  1097,   504,
     505,    32,    56,   468,   469,   470,   471,   472,   473,   474,
     475,   754,  1248,  1249,  1378,  1250,  1391,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,    33,    62,   531,
     532,   533,   534,   535,    34,    65,   564,   565,   566,   567,
     568,   878,  1317,  1318,    35,    66,   572,   573,   574,   575,
     884,  1332,  1333,    36,    50,   119,   649,   650,   651,   120,
     652,   653,   654,   655,   656,   657,   658,   659,   941,  1358,
    1359,  1449,  1360,  1457,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,    37,    57,   490,   769,  1264,  1265,
     491,   492,   493,   494,    38,    51,   362,   363,   364,   365,
      39,   124,   125,   126,    40,    53,   373,   678,  1222,  1223,
     374,   375,   376,   377,    41,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   413,  1035,  1036,
     237,   411,  1013,  1014,   238,   239,   240,   241,   242,    42,
      55,   443,   444,   445,   446,   447,   744,  1239,  1240,   448,
     449,   450,   741,  1233,  1234,    43,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,    44,   293,   294,   295,
     296,   297,   298,   299,   300,   301
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -952
static const yytype_int16 yypact[] =
{
    -952,   888,  -952,  -233,  -260,  -258,  -952,  -952,  -952,  -255,
    -952,  -253,  -952,  -952,  -952,  -952,  -250,  -237,  -952,  -952,
    -228,  -226,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,   302,   766,  -136,
    -112,  -199,    17,  -193,   475,  -190,  -187,  -173,  -167,   702,
       2,   -46,  -149,   361,   520,  -140,  -134,  -130,  -121,  -102,
     -84,     4,  -952,  -952,  -952,  -952,  -952,   -82,   -77,   -62,
     -57,   -51,   -33,   -30,   -25,   -16,    -5,    -4,    20,    24,
      37,    40,    46,    49,    59,   286,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,    36,  -952,  -952,    63,
    -952,    19,  -952,    70,     7,  -952,  -952,   159,  -952,    71,
      76,    79,    84,    91,    98,   104,   105,   107,   108,   109,
     112,   113,   114,   116,   117,   118,   121,   125,   126,   130,
     132,   136,   140,   142,   144,   146,   148,   153,   155,   157,
     161,   164,  -952,   165,  -952,   169,   170,   171,   172,   173,
     181,   184,   185,   194,   196,   198,   199,   200,   201,   204,
     206,   209,   210,   212,   213,    23,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   552,   784,    93,    88,   217,   215,   216,
     220,   224,   225,   226,   227,   231,   232,   234,   235,   239,
     133,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   243,   241,   245,    27,  -952,  -952,
    -952,  -952,   247,  -952,    25,  -952,   248,   250,   252,   259,
     260,   261,   266,    45,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,   271,   269,   270,   272,   276,   278,   279,   280,
    -952,   281,   285,   289,   290,   303,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,    56,
      62,  -952,   357,   381,   396,   296,  -952,   363,   434,   436,
     374,   375,   444,   444,   449,   450,   387,   390,   462,   444,
     397,   400,   403,   404,   405,   318,  -952,   634,   703,  -952,
     342,   343,    15,  -952,  -952,  -952,   454,   348,  -952,  -952,
     346,   353,  -952,  -952,   158,  -952,  -952,  -952,   414,   444,
     421,   444,   494,   476,   497,   433,   435,   437,   500,   483,
     440,   510,   513,   514,   451,   444,   452,   453,   516,   499,
     461,   529,   530,   444,   533,   542,   512,   543,   546,   481,
     482,   417,   484,   419,   444,   444,   486,   444,   536,   489,
     493,   495,  -150,  -141,   496,   498,   444,   444,   560,   444,
     501,   503,   509,   511,   455,  -952,  -952,  -952,   446,   456,
    -952,   457,   459,    44,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,   463,   467,   468,   485,   487,  -952,   490,   506,   507,
     508,   519,   524,   526,   527,   531,   532,   544,   160,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,   548,  -952,   550,
    -952,    12,  -952,  -952,  -952,   465,  -952,   551,   553,   554,
    -952,    14,  -952,  -952,  -952,  -952,  -952,   557,   559,   561,
     564,   585,   586,   591,   592,   230,   596,   613,   577,   537,
    -952,  -952,   640,   643,   549,  -952,   574,   555,   556,   562,
     563,    32,  -952,  -952,  -952,  -952,   623,   630,   631,   665,
     632,   633,   444,   575,  -952,  -952,   681,   639,   685,   688,
     689,   690,   691,   582,   693,   565,   694,   695,   589,  -952,
     590,   593,  -952,   594,     9,  -952,  -952,  -952,  -952,   601,
     607,  -952,    33,  -952,  -952,  -952,   604,   614,   615,  -952,
     616,   619,   620,   624,   625,   189,   628,   629,   635,   636,
     637,   638,   641,   642,   644,   646,   647,   651,   654,  -952,
     656,   610,   618,   627,   655,   660,   661,   662,   663,   664,
     667,   669,   670,   671,   223,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   657,
     672,   673,   674,   676,   679,   680,   683,   684,   686,  -952,
     687,   696,   697,   699,   700,   701,   704,   705,   706,   238,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
     730,   741,   659,  -952,   668,  -952,   746,   747,   707,   711,
    -952,   712,   713,   716,   717,   719,   720,   721,   722,   723,
     724,   725,   726,   727,   729,   731,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   742,   743,   744,   745,   748,
     749,   750,   751,   752,   815,   753,   871,   754,   755,   767,
     771,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     786,   790,   791,   315,   793,   794,   796,   797,   798,   800,
    -952,   799,   444,   756,   801,   795,   803,   805,  -952,  -952,
     760,   812,   769,   804,   807,   809,   864,   866,   869,   870,
     918,   566,   919,   927,   886,   934,   828,  -952,   937,   829,
     938,   833,  -952,  -952,   831,   942,   943,   772,   837,  -952,
     838,   842,   846,   847,   849,   850,   857,   860,   865,   867,
     868,   872,   873,   874,   875,   879,   883,   884,  -952,   887,
     889,  -952,   890,   861,   891,   892,   893,  -952,   894,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,  -952,   907,   909,   910,   149,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
     976,   977,   978,   911,  -952,   914,   915,   916,   917,   920,
     921,   922,  -952,   923,   924,   925,   926,   928,   929,   930,
     -15,   931,   932,   933,   935,  -952,  -952,   993,   936,   998,
     940,  -952,  -952,   999,   939,   941,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   444,   444,   444,   444,   444,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,   813,  1022,   444,  1047,
    1048,  1056,  1063,  1043,  1066,  1067,   444,   444,   560,   944,
    -952,  -952,  1050,   -13,  1008,  1053,  1054,  1011,  1012,  1013,
    1058,   949,  1060,  1061,  1062,  1064,  1085,  1065,  1068,  1023,
    1069,   959,  -952,   963,   964,  -952,  -952,   965,   966,  1070,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -245,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -202,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   560,   560,   560,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,     1,   967,   969,    11,   970,   971,
    -952,   972,   973,   974,   975,  1106,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,  -952,   990,  1079,
     991,  -952,     0,   992,   994,   650,   995,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    1041,  1100,  1059,  1071,   997,  1072,  1073,  1074,  1075,  1076,
    1102,  1077,  1104,  1078,  1080,  1081,  1105,  1082,  1000,  1083,
    1108,  1084,  1002,  -952,  1004,  1005,  1006,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -174,  -952,  -952,  -952,  -952,  -952,
    1007,   534,  1016,  -952,  1024,   621,  -952,  -952,  -952,  -952,
    -952,  -952,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  -952,  1038,  1039,  1040,  1042,
    1044,  1045,  1046,  1049,  1051,  1052,  1152,  1055,  1057,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  -952,  -952,  -952,  -952,
    -952,  -952,  -148,  -952,  -952,   815,  -952,   871,  -952,  -952,
    -952,  -952,  -952,  -145,  -952,  -952,  -952,  -952,  -952,  -129,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -117,  -952,
     447,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,   -35,  -952,  -952,  -952,  -952,  -952,
     -10,  -952,  -952,  -952,  1170,   772,  1093,  1094,  1095,  1096,
    1097,  1153,  1098,  1099,  1101,  1103,  1107,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1116,   908,  1117,  1118,  1119,  -952,
    -952,  -952,  -952,  -952,   -15,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,    -8,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,    35,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,    80,  -952,
      13,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  1070,  -952,  -952,  -952,     1,  -952,    11,   447,  -952,
    1106,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  1079,  -952,     0,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,    89,  -952,   366,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,    95,
    -952,  -952,  -952,  -952,  -952,  -952,   534,  -952,   621,    13,
    -952,  1152,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   366,  -952,  1153,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,   908,  -952,  -952,  -952,
    -952,  -952,  -952,  -952
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -952,  -952,  -952,  -816,  -342,  -951,  -426,  -952,  -952,   578,
    -952,  -952,  -952,  -952,   541,  -952,  -952,  -952,     5,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  1234,  -952,  -952,  -952,  -952,  -952,  1122,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,   491,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -176,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -155,  -952,  -952,  -147,  -952,  -952,
    -952,  -952,   708,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,   -80,  -952,   819,  -952,  -952,  -952,    48,  -952,
    -952,  -952,  -952,  -952,   853,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,   -56,  -952,  -952,   -53,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
     802,  -952,  -952,  -952,  -952,  -952,  -952,   762,  -952,  -952,
    -952,  -952,  -952,  -119,  -952,  -952,  -952,   757,  -952,  -952,
    -952,  -952,  -120,  -952,  -952,  -952,  -952,   682,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -116,  -952,  -952,  -115,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   -63,
    -952,   841,  -952,  -952,  -952,  -952,  -952,  1021,  -952,  -952,
    -952,  -952,  1212,  -952,  -952,  -952,  -952,  -952,  -952,   -34,
    -952,   968,  -952,  -952,  -952,  -952,  1154,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,   111,
    -952,  -952,  -952,   115,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,   945,  -952,  -952,  -952,  -952,  -952,   -36,  -952,
    -952,  -952,  -952,  -952,   -32,  -952,  -952,  1249,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,
    -952,  -952,  -952,  -952,  -952,  -952,  -952,  -952,  1120,  -952,
    -952,  -952,  -952,  -952,  -952,  -952
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     586,   587,   734,   274,    47,    67,    48,   593,   122,    52,
     560,    54,  1231,   486,    59,   495,   359,  1224,   122,   115,
     359,  1225,  1237,  1452,   128,  1453,   527,    60,   274,    45,
      46,   129,   130,   527,   569,   131,    63,   682,    64,   684,
    1454,    68,   132,   118,  1455,   436,   285,   528,   437,   725,
     726,   133,    69,   698,   528,   134,   135,   560,   727,   728,
    1226,   706,   136,   569,  1227,   121,   137,   138,   139,   496,
     140,   127,   717,   718,   243,   720,   141,   244,  1267,  1177,
    1178,  1179,  1180,  1181,   731,   732,   286,   735,  1303,   495,
     438,   245,  1304,   439,   486,   142,   143,   246,   123,   497,
     144,   287,  1228,  1229,  1230,   498,   360,   145,   123,   281,
     360,   146,   147,   148,  1370,   284,   149,  1374,  1371,   150,
     151,  1375,   275,   288,   329,   289,    70,   290,   291,   152,
     330,   561,   331,  1376,   247,   153,   154,  1377,   155,   156,
     157,   158,   159,   496,   332,  1379,   292,   275,   440,  1380,
     802,   529,   276,   160,   803,   570,  1162,  1163,   529,   369,
     369,   451,   161,   333,   162,   163,   441,   164,   499,   487,
     165,   166,   361,   497,   167,   804,   361,   276,   561,   498,
     452,   334,   530,   337,   570,   168,   453,   805,   338,   530,
     248,   249,   250,   251,   252,   253,   254,   255,   562,   806,
     861,   488,  1232,   339,   807,  1197,  1198,   169,   340,   170,
     454,   455,  1238,   171,   341,   456,   808,   172,   173,   174,
     175,   176,   571,   809,   600,   177,   178,  1392,   810,   457,
     811,  1393,   342,  1268,   179,   343,   458,  1269,   256,   629,
     344,   630,   499,   812,   631,   562,   601,   602,   632,   345,
     487,   571,  1394,   603,  1445,   459,  1395,  1456,  1446,   563,
     346,   347,   489,   633,   634,   635,   180,   335,   181,   636,
     367,   813,   880,   257,   182,   771,   814,   778,   672,   183,
     370,   370,   488,   460,   184,   348,   434,    76,   637,   349,
     524,   461,   638,   639,   442,   853,   885,  1447,   815,    77,
     357,  1448,   350,    67,   302,   351,   563,   747,   543,   462,
     816,   352,   817,   818,   353,   371,   371,   819,   463,   464,
      78,    79,   585,   640,   354,   641,    80,   358,    81,  1053,
    1054,  1055,   604,   605,   606,   366,   378,   607,   642,    68,
     303,   379,  1450,   489,   380,   608,  1451,   372,   372,   381,
      69,  1466,   465,   466,   258,  1467,   382,  1485,   609,   610,
     643,  1486,   285,   383,   895,   896,   897,   898,   899,   384,
     385,  1468,   386,   387,   388,   611,   612,   389,   390,   391,
     820,   392,   393,   394,    82,    83,   395,   821,   259,   304,
     396,   397,   644,    84,    85,   398,   519,   399,   822,   823,
    1065,   400,   286,   613,  1469,   401,   645,   402,   824,   403,
     467,   404,  1142,   405,    86,    87,  1470,   287,   406,   646,
     407,   679,   408,   766,    70,   305,   409,   306,   307,   410,
     412,    88,    89,  1471,   414,   415,   416,   417,   418,   288,
    1472,   289,    90,   290,   291,  1473,   419,  1474,   733,   420,
     421,    91,   788,   789,   790,   791,   792,   793,   794,   422,
    1475,   423,   292,   424,   425,   426,   427,  1381,  1382,   428,
     308,   429,   309,   310,   430,   431,   128,   432,   433,   506,
     507,   508,   647,   129,   130,   509,   929,   131,   311,   510,
     511,   512,   513,  1476,   132,   648,   514,   515,  1383,   516,
     517,   951,  1194,   133,   518,   521,   522,   134,   135,  1477,
     523,   526,   576,   536,   136,   537,  1384,   538,   137,   138,
     139,   302,   140,  1385,   539,   540,   541,  1478,   141,  1479,
    1480,   542,   312,   545,   546,   547,   577,   548,    92,    93,
      94,   549,  1386,   550,   551,   552,   554,   142,   143,   355,
     555,   578,   144,   436,   556,   557,   437,   303,   579,   145,
     313,   314,   580,   146,   147,   148,   558,   581,   149,   582,
    1387,   150,   151,   583,   584,   802,  1184,   585,  1388,   803,
     599,   152,   588,   589,  1192,  1193,   590,   153,   154,   591,
     155,   156,   157,   158,   159,   592,   594,  1481,   438,   595,
     804,   439,   596,   597,   598,   160,   304,   670,   671,   674,
     675,   676,   805,   681,   161,  1482,   162,   163,   677,   164,
     683,  1389,   165,   166,   806,  1483,   167,   685,  1306,   807,
     687,   686,   688,   691,   689,   600,   690,   168,   692,   693,
    1390,   808,   305,   694,   306,   307,   695,   696,   809,   701,
     697,   699,   700,   810,   702,   811,   440,   601,   602,   169,
     703,   170,   704,   705,   603,   171,   707,   709,   812,   172,
     173,   174,   175,   176,   441,   708,   710,   177,   178,   711,
     712,   713,   714,   715,   716,   719,   179,   308,   722,   309,
     310,   721,   723,   733,   724,   729,   813,   730,   872,  1082,
     736,   814,   737,   247,   629,   311,   630,  1307,   738,   631,
     739,   742,   780,   632,   781,  1321,   782,   740,   180,   783,
     181,   743,   745,   815,   746,   749,   182,   773,   633,   634,
     635,   183,   750,   751,   636,   816,   184,   817,   818,  1308,
     784,   785,   819,   604,   605,   606,   786,   787,   607,   312,
     752,   795,   753,   637,  1309,   755,   608,   638,   639,   248,
     249,   250,   251,   252,   253,   254,   255,    76,   796,   609,
     610,   756,   757,   758,  1310,  1311,   797,   313,   314,    77,
    1312,  1313,  1314,  1315,   759,   451,   611,   612,   640,   760,
     641,   761,   762,  1316,  1322,   799,   763,   764,   800,   798,
      78,    79,   442,   642,   452,   820,    80,   256,    81,   765,
     453,   801,   821,   768,   613,   770,   775,   849,   776,   777,
     858,   850,   855,   822,   823,   643,  1323,   851,   852,   856,
     857,   859,   860,   824,   454,   455,   863,   862,   864,   456,
     865,  1324,   257,   866,   867,   868,   869,   870,   871,   873,
     874,   875,   876,   457,  1274,   525,   559,   644,   877,   879,
     458,  1325,  1326,   882,    82,    83,   887,  1327,  1328,  1329,
    1330,   645,   883,    84,    85,   916,   888,   889,   890,   459,
    1331,   891,   892,   917,   646,   953,   893,   894,     2,     3,
     902,   903,   918,     4,    86,    87,   954,   904,   905,   906,
     907,   957,   958,   908,   909,  1095,   910,   460,   911,   912,
       5,    88,    89,   913,     6,   461,   914,     7,   915,   931,
     919,   955,    90,   258,     8,   920,   921,   922,   923,   924,
     956,    91,   925,   462,   926,   927,   928,   932,   933,   934,
       9,   935,   463,   464,   936,   937,  1182,   647,   938,   939,
    1068,   940,   942,    10,    11,  1066,    12,   259,  1069,  1071,
     648,   943,   944,    13,   945,   946,   947,  1072,  1073,   948,
     949,   950,   959,   960,   961,   962,   465,   466,   963,   964,
      14,   965,   966,   967,   968,   969,   970,   971,   972,   973,
      15,   974,    16,   975,   976,   977,   978,   979,   980,   981,
     982,   983,   984,  1074,   985,   986,   987,   988,  1076,    17,
     989,   990,   991,   992,   993,  1015,  1037,  1038,    92,    93,
      94,   994,   995,   996,   997,   998,    18,   999,  1000,  1039,
    1001,  1002,  1003,  1040,   467,  1004,  1041,  1042,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1005,  1006,  1007,  1050,  1008,
    1009,  1010,  1051,  1052,  1011,  1058,  1059,  1012,  1060,  1061,
    1062,    19,  1063,  1077,  1064,  1078,  1067,  1070,  1079,  1080,
      20,    21,  1075,  1081,  1083,    22,    23,  1016,  1017,  1018,
    1019,  1020,  1084,  1021,  1022,  1085,  1023,  1024,  1025,  1086,
    1087,  1026,  1088,  1090,  1089,  1091,  1092,  1093,  1094,  1098,
    1099,  1027,  1028,  1029,  1100,  1030,  1031,  1032,  1101,  1102,
    1033,  1103,  1104,  1034,  1420,  1421,  1422,  1423,  1424,  1105,
    1425,  1426,  1106,  1427,  1428,  1429,  1120,  1107,  1430,  1108,
    1109,  1144,  1145,  1146,  1110,  1111,  1112,  1113,  1431,  1432,
    1433,  1114,  1434,  1435,  1436,  1115,  1116,  1437,  1170,  1117,
    1438,  1118,  1119,  1172,  1174,  1183,  1121,  1122,  1123,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1139,  1147,  1140,  1141,  1148,  1149,  1150,  1151,
    1185,  1186,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1187,
    1159,  1160,  1161,  1166,  1167,  1168,  1188,  1169,  1189,  1190,
    1191,  1171,  1173,  1176,  1175,  1196,  1195,  1199,  1200,  1201,
    1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,  1211,  1210,
    1212,  1216,  1214,  1213,  1215,  1217,  1218,  1219,  1220,  1235,
    1221,  1236,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1263,
    1277,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1266,  1272,  1278,  1273,  1287,  1279,  1289,
    1293,  1275,  1281,  1297,  1299,  1295,  1300,  1301,  1302,  1305,
    1280,  1282,  1283,  1284,  1285,  1286,  1288,  1290,  1319,  1291,
    1292,  1294,  1296,  1298,  1357,  1403,  1320,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1396,  1350,   336,  1351,  1352,  1353,  1444,
    1493,  1354,  1492,  1355,  1356,  1464,  1143,  1361,  1491,  1362,
     779,   767,   930,  1397,  1462,  1461,   881,  1487,  1488,   886,
    1463,   952,   772,   854,  1489,  1490,   368,  1458,  1373,   435,
    1372,  1460,   680,  1459,   356,     0,     0,     0,  1363,  1364,
    1365,  1366,  1367,  1368,  1369,  1398,  1399,  1400,  1401,  1402,
    1407,  1408,     0,  1409,     0,  1410,     0,     0,     0,  1411,
       0,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1441,
    1442,  1443,   520,   673,     0,     0,     0,     0,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   544
};

static const yytype_int16 yycheck[] =
{
     342,   343,   428,     1,   264,     1,   264,   349,     1,   264,
       1,   264,    11,     1,   264,     1,     1,   262,     1,   155,
       1,   266,    11,    10,     1,    12,     1,   264,     1,   262,
     263,     8,     9,     1,     1,    12,   264,   379,   264,   381,
      27,    37,    19,   155,    31,     1,     1,    22,     4,   199,
     200,    28,    48,   395,    22,    32,    33,     1,   199,   200,
     262,   403,    39,     1,   266,   264,    43,    44,    45,    55,
      47,   264,   414,   415,   264,   417,    53,   264,    78,   895,
     896,   897,   898,   899,   426,   427,    41,   429,   262,     1,
      46,   264,   266,    49,     1,    72,    73,   264,    91,    85,
      77,    56,  1053,  1054,  1055,    91,    91,    84,    91,   155,
      91,    88,    89,    90,   262,   264,    93,   262,   266,    96,
      97,   266,   120,    78,   264,    80,   122,    82,    83,   106,
     264,   122,   262,   262,     1,   112,   113,   266,   115,   116,
     117,   118,   119,    55,   265,   262,   101,   120,   104,   266,
       1,   126,   150,   130,     5,   122,   171,   172,   126,     1,
       1,     1,   139,   265,   141,   142,   122,   144,   154,   157,
     147,   148,   157,    85,   151,    26,   157,   150,   122,    91,
      20,   265,   157,   265,   122,   162,    26,    38,   265,   157,
      57,    58,    59,    60,    61,    62,    63,    64,   189,    50,
     542,   189,   201,   265,    55,   218,   219,   184,   265,   186,
      50,    51,   201,   190,   265,    55,    67,   194,   195,   196,
     197,   198,   189,    74,     1,   202,   203,   262,    79,    69,
      81,   266,   265,   233,   211,   265,    76,   237,   105,     1,
     265,     3,   154,    94,     6,   189,    23,    24,    10,   265,
     157,   189,   262,    30,   262,    95,   266,   244,   266,   250,
     265,   265,   250,    25,    26,    27,   243,   263,   245,    31,
     263,   122,   263,   140,   251,   263,   127,   263,   263,   256,
     122,   122,   189,   123,   261,   265,   263,     1,    50,   265,
     263,   131,    54,    55,   250,   263,   263,   262,   149,    13,
     264,   266,   265,     1,     1,   265,   250,   263,   263,   149,
     161,   265,   163,   164,   265,   157,   157,   168,   158,   159,
      34,    35,   133,    85,   265,    87,    40,   264,    42,    14,
      15,    16,   109,   110,   111,   265,   265,   114,   100,    37,
      37,   265,   262,   250,   265,   122,   266,   189,   189,   265,
      48,   262,   192,   193,   221,   266,   265,   262,   135,   136,
     122,   266,     1,   265,   175,   176,   177,   178,   179,   265,
     265,     5,   265,   265,   265,   152,   153,   265,   265,   265,
     231,   265,   265,   265,    98,    99,   265,   238,   255,    86,
     265,   265,   154,   107,   108,   265,   263,   265,   249,   250,
     742,   265,    41,   180,    38,   265,   168,   265,   259,   265,
     250,   265,   263,   265,   128,   129,    50,    56,   265,   181,
     265,   263,   265,   263,   122,   122,   265,   124,   125,   265,
     265,   145,   146,    67,   265,   265,   265,   265,   265,    78,
      74,    80,   156,    82,    83,    79,   265,    81,   133,   265,
     265,   165,   222,   223,   224,   225,   226,   227,   228,   265,
      94,   265,   101,   265,   265,   265,   265,    20,    21,   265,
     167,   265,   169,   170,   265,   265,     1,   265,   265,   262,
     265,   265,   244,     8,     9,   265,   263,    12,   185,   265,
     265,   265,   265,   127,    19,   257,   265,   265,    51,   265,
     265,   263,   928,    28,   265,   262,   265,    32,    33,   143,
     265,   264,   155,   265,    39,   265,    69,   265,    43,    44,
      45,     1,    47,    76,   265,   265,   265,   161,    53,   163,
     164,   265,   229,   262,   265,   265,   155,   265,   252,   253,
     254,   265,    95,   265,   265,   265,   265,    72,    73,   263,
     265,   155,    77,     1,   265,   265,     4,    37,   262,    84,
     257,   258,   199,    88,    89,    90,   263,   133,    93,   133,
     123,    96,    97,   199,   199,     1,   918,   133,   131,     5,
     262,   106,   133,   133,   926,   927,   199,   112,   113,   199,
     115,   116,   117,   118,   119,   133,   199,   231,    46,   199,
      26,    49,   199,   199,   199,   130,    86,   265,   265,   155,
     262,   265,    38,   199,   139,   249,   141,   142,   265,   144,
     199,   174,   147,   148,    50,   259,   151,   133,    94,    55,
     133,   155,   199,   133,   199,     1,   199,   162,   155,   199,
     193,    67,   122,   133,   124,   125,   133,   133,    74,   133,
     199,   199,   199,    79,   155,    81,   104,    23,    24,   184,
     199,   186,   133,   133,    30,   190,   133,   155,    94,   194,
     195,   196,   197,   198,   122,   133,   133,   202,   203,   133,
     199,   199,   265,   199,   265,   199,   211,   167,   199,   169,
     170,   155,   199,   133,   199,   199,   122,   199,   133,   133,
     199,   127,   199,     1,     1,   185,     3,   173,   199,     6,
     199,   265,   155,    10,   155,    94,   155,   262,   243,   155,
     245,   265,   265,   149,   265,   262,   251,   262,    25,    26,
      27,   256,   265,   265,    31,   161,   261,   163,   164,   205,
     155,   155,   168,   109,   110,   111,   155,   155,   114,   229,
     265,   155,   265,    50,   220,   265,   122,    54,    55,    57,
      58,    59,    60,    61,    62,    63,    64,     1,   155,   135,
     136,   265,   265,   265,   240,   241,   199,   257,   258,    13,
     246,   247,   248,   249,   265,     1,   152,   153,    85,   265,
      87,   265,   265,   259,   173,   155,   265,   265,   155,   262,
      34,    35,   250,   100,    20,   231,    40,   105,    42,   265,
      26,   262,   238,   265,   180,   265,   265,   262,   265,   265,
     155,   265,   199,   249,   250,   122,   205,   265,   265,   199,
     199,   199,   199,   259,    50,    51,   155,   262,   199,    55,
     155,   220,   140,   155,   155,   155,   155,   265,   155,   155,
     155,   262,   262,    69,   204,   277,   315,   154,   265,   265,
      76,   240,   241,   262,    98,    99,   262,   246,   247,   248,
     249,   168,   265,   107,   108,   265,   262,   262,   262,    95,
     259,   262,   262,   265,   181,   155,   262,   262,     0,     1,
     262,   262,   265,     5,   128,   129,   155,   262,   262,   262,
     262,   155,   155,   262,   262,   133,   262,   123,   262,   262,
      22,   145,   146,   262,    26,   131,   262,    29,   262,   262,
     265,   262,   156,   221,    36,   265,   265,   265,   265,   265,
     262,   165,   265,   149,   265,   265,   265,   265,   265,   265,
      52,   265,   158,   159,   265,   265,   133,   244,   265,   265,
     155,   265,   265,    65,    66,   199,    68,   255,   155,   199,
     257,   265,   265,    75,   265,   265,   265,   155,   199,   265,
     265,   265,   265,   262,   262,   262,   192,   193,   262,   262,
      92,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     102,   262,   104,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   199,   262,   262,   262,   262,   199,   121,
     262,   262,   262,   262,   262,   262,   262,   262,   252,   253,
     254,   206,   207,   208,   209,   210,   138,   212,   213,   262,
     215,   216,   217,   262,   250,   220,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   230,   231,   232,   262,   234,
     235,   236,   262,   262,   239,   262,   262,   242,   262,   262,
     262,   173,   262,   199,   265,   199,   265,   262,   199,   199,
     182,   183,   265,   155,   155,   187,   188,   206,   207,   208,
     209,   210,   155,   212,   213,   199,   215,   216,   217,   155,
     262,   220,   155,   155,   265,   262,   265,   155,   155,   262,
     262,   230,   231,   232,   262,   234,   235,   236,   262,   262,
     239,   262,   262,   242,   206,   207,   208,   209,   210,   262,
     212,   213,   262,   215,   216,   217,   265,   262,   220,   262,
     262,   155,   155,   155,   262,   262,   262,   262,   230,   231,
     232,   262,   234,   235,   236,   262,   262,   239,   155,   262,
     242,   262,   262,   155,   155,   133,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   262,   265,   265,   262,   262,   262,   262,
     133,   133,   262,   262,   262,   262,   262,   262,   262,   133,
     262,   262,   262,   262,   262,   262,   133,   262,   155,   133,
     133,   265,   262,   262,   265,   155,   262,   199,   155,   155,
     199,   199,   199,   155,   265,   155,   155,   155,   133,   155,
     155,   262,   199,   155,   155,   262,   262,   262,   262,   262,
     160,   262,   262,   262,   262,   262,   262,   262,   132,   160,
     199,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   155,   262,   155,   199,   155,
     155,   266,   265,   155,   262,   265,   262,   262,   262,   262,
     199,   199,   199,   199,   199,   199,   199,   199,   262,   199,
     199,   199,   199,   199,   132,   132,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   133,   262,    71,   262,   262,   262,  1304,
    1486,   262,  1467,   262,   262,  1395,   825,   262,  1465,   262,
     501,   468,   614,  1275,  1380,  1378,   564,  1446,  1448,   572,
    1393,   649,   491,   531,  1449,  1451,   124,  1371,  1227,   185,
    1225,  1377,   374,  1375,    95,    -1,    -1,    -1,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,    -1,   262,    -1,   262,    -1,    -1,    -1,   262,
      -1,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   260,   362,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   293
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   268,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   102,   104,   121,   138,   173,
     182,   183,   187,   188,   269,   274,   279,   297,   303,   318,
     355,   374,   388,   414,   421,   431,   440,   471,   481,   487,
     491,   501,   566,   582,   603,   262,   263,   264,   264,   356,
     441,   482,   264,   492,   264,   567,   389,   472,   375,   264,
     264,   319,   415,   264,   264,   422,   432,     1,    37,    48,
     122,   298,   299,   300,   301,   302,     1,    13,    34,    35,
      40,    42,    98,    99,   107,   108,   128,   129,   145,   146,
     156,   165,   252,   253,   254,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   155,   357,   361,   155,   442,
     446,   264,     1,    91,   488,   489,   490,   264,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   106,   112,   113,   115,   116,   117,   118,   119,
     130,   139,   141,   142,   144,   147,   148,   151,   162,   184,
     186,   190,   194,   195,   196,   197,   198,   202,   203,   211,
     243,   245,   251,   256,   261,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   557,   561,   562,
     563,   564,   565,   264,   264,   264,   264,     1,    57,    58,
      59,    60,    61,    62,    63,    64,   105,   140,   221,   255,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,     1,   120,   150,   275,   276,   277,
     278,   155,   320,   324,   264,     1,    41,    56,    78,    80,
      82,    83,   101,   604,   605,   606,   607,   608,   609,   610,
     611,   612,     1,    37,    86,   122,   124,   125,   167,   169,
     170,   185,   229,   257,   258,   280,   281,   282,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   264,
     264,   262,   265,   265,   265,   263,   299,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   263,   584,   264,   264,     1,
      91,   157,   483,   484,   485,   486,   265,   263,   489,     1,
     122,   157,   189,   493,   497,   498,   499,   500,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   558,   265,   554,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   263,   503,     1,     4,    46,    49,
     104,   122,   250,   568,   569,   570,   571,   572,   576,   577,
     578,     1,    20,    26,    50,    51,    55,    69,    76,    95,
     123,   131,   149,   158,   159,   192,   193,   250,   390,   391,
     392,   393,   394,   395,   396,   397,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,     1,   157,   189,   250,
     473,   477,   478,   479,   480,     1,    55,    85,    91,   154,
     376,   380,   381,   382,   386,   387,   262,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   263,
     305,   262,   265,   265,   263,   276,   264,     1,    22,   126,
     157,   416,   417,   418,   419,   420,   265,   265,   265,   265,
     265,   265,   265,   263,   605,   262,   265,   265,   265,   265,
     265,   265,   265,   283,   265,   265,   265,   265,   263,   281,
       1,   122,   189,   250,   423,   424,   425,   426,   427,     1,
     122,   189,   433,   434,   435,   436,   155,   155,   155,   262,
     199,   133,   133,   199,   199,   133,   271,   271,   133,   133,
     199,   199,   133,   271,   199,   199,   199,   199,   199,   262,
       1,    23,    24,    30,   109,   110,   111,   114,   122,   135,
     136,   152,   153,   180,   358,   359,   360,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,     1,
       3,     6,    10,    25,    26,    27,    31,    50,    54,    55,
      85,    87,   100,   122,   154,   168,   181,   244,   257,   443,
     444,   445,   447,   448,   449,   450,   451,   452,   453,   454,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     265,   265,   263,   484,   155,   262,   265,   265,   494,   263,
     498,   199,   271,   199,   271,   133,   155,   133,   199,   199,
     199,   133,   155,   199,   133,   133,   133,   199,   271,   199,
     199,   133,   155,   199,   133,   133,   271,   133,   133,   155,
     133,   133,   199,   199,   265,   199,   265,   271,   271,   199,
     271,   155,   199,   199,   199,   199,   200,   199,   200,   199,
     199,   271,   271,   133,   273,   271,   199,   199,   199,   199,
     262,   579,   265,   265,   573,   265,   265,   263,   569,   262,
     265,   265,   265,   265,   398,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   263,   391,   265,   474,
     265,   263,   478,   262,   377,   265,   265,   265,   263,   381,
     155,   155,   155,   155,   155,   155,   155,   155,   222,   223,
     224,   225,   226,   227,   228,   155,   155,   199,   262,   155,
     155,   262,     1,     5,    26,    38,    50,    55,    67,    74,
      79,    81,    94,   122,   127,   149,   161,   163,   164,   168,
     231,   238,   249,   250,   259,   321,   322,   323,   325,   326,
     327,   328,   329,   330,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   262,
     265,   265,   265,   263,   417,   199,   199,   199,   155,   199,
     199,   271,   262,   155,   199,   155,   155,   155,   155,   155,
     265,   155,   133,   155,   155,   262,   262,   265,   428,   265,
     263,   424,   262,   265,   437,   263,   434,   262,   262,   262,
     262,   262,   262,   262,   262,   175,   176,   177,   178,   179,
     270,   271,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   263,
     359,   262,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   455,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   263,   444,   155,   155,   262,   262,   155,   155,   265,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   206,   207,   208,   209,   210,   212,
     213,   215,   216,   217,   220,   230,   231,   232,   234,   235,
     236,   239,   242,   559,   560,   262,   206,   207,   208,   209,
     210,   212,   213,   215,   216,   217,   220,   230,   231,   232,
     234,   235,   236,   239,   242,   555,   556,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,    14,    15,    16,   272,   273,   262,   262,
     262,   262,   262,   262,   265,   271,   199,   265,   155,   155,
     262,   199,   155,   199,   199,   265,   199,   199,   199,   199,
     199,   155,   133,   155,   155,   199,   155,   262,   155,   265,
     155,   262,   265,   155,   155,   133,   384,   385,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     265,   265,   265,   265,   349,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   331,   265,
     265,   265,   263,   322,   155,   155,   155,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   171,   172,   284,   285,   262,   262,   262,   262,
     155,   265,   155,   262,   155,   265,   262,   270,   270,   270,
     270,   270,   133,   133,   271,   133,   133,   133,   133,   155,
     133,   133,   271,   271,   273,   262,   155,   218,   219,   199,
     155,   155,   199,   199,   199,   155,   265,   155,   155,   155,
     155,   133,   155,   155,   199,   155,   262,   262,   262,   262,
     262,   160,   495,   496,   262,   266,   262,   266,   272,   272,
     272,    11,   201,   580,   581,   262,   262,    11,   201,   574,
     575,   262,   262,   262,   262,   262,   262,   132,   399,   400,
     402,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   160,   475,   476,   262,    78,   233,   237,
     378,   379,   262,   262,   204,   266,   383,   199,   155,   199,
     199,   265,   199,   199,   199,   199,   199,   155,   199,   155,
     199,   199,   199,   155,   199,   265,   199,   155,   199,   262,
     262,   262,   262,   262,   266,   262,    94,   173,   205,   220,
     240,   241,   246,   247,   248,   249,   259,   429,   430,   262,
     262,    94,   173,   205,   220,   240,   241,   246,   247,   248,
     249,   259,   438,   439,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   132,   456,   457,
     459,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   266,   560,   556,   262,   266,   262,   266,   401,   262,
     266,    20,    21,    51,    69,    76,    95,   123,   131,   174,
     193,   403,   262,   266,   262,   266,   133,   385,   262,   262,
     262,   262,   262,   132,   350,   351,   353,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     206,   207,   208,   209,   210,   212,   213,   215,   216,   217,
     220,   230,   231,   232,   234,   235,   236,   239,   242,   332,
     333,   262,   262,   262,   285,   262,   266,   262,   266,   458,
     262,   266,    10,    12,    27,    31,   244,   460,   496,   581,
     575,   403,   400,   476,   379,   352,   262,   266,     5,    38,
      50,    67,    74,    79,    81,    94,   127,   143,   161,   163,
     164,   231,   249,   259,   354,   262,   266,   430,   439,   460,
     457,   354,   351,   333
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
#line 429 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 447 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 451 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 456 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 457 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 458 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 459 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 460 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 474 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
#endif
}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 482 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 504 "ircd_parser.y"
    {
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 508 "ircd_parser.y"
    {
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
  {
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_SSLV3))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_TLSV1))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
  }
}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 520 "ircd_parser.y"
    {
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 524 "ircd_parser.y"
    {
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
}
    break;

  case 70:

/* Line 1455 of yacc.c  */
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

  case 71:

/* Line 1455 of yacc.c  */
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

  case 72:

/* Line 1455 of yacc.c  */
#line 624 "ircd_parser.y"
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
#line 638 "ircd_parser.y"
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
#line 653 "ircd_parser.y"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 676 "ircd_parser.y"
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
#line 685 "ircd_parser.y"
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

  case 80:

/* Line 1455 of yacc.c  */
#line 766 "ircd_parser.y"
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
#line 794 "ircd_parser.y"
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
#line 803 "ircd_parser.y"
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
#line 812 "ircd_parser.y"
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
#line 839 "ircd_parser.y"
    {
                        }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 843 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 847 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 854 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 861 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 868 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 875 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 882 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 889 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 896 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 903 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 907 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 915 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 923 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 927 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 933 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 942 "ircd_parser.y"
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
#line 955 "ircd_parser.y"
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
#line 1047 "ircd_parser.y"
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
#line 1059 "ircd_parser.y"
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
#line 1071 "ircd_parser.y"
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
#line 1105 "ircd_parser.y"
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
#line 1117 "ircd_parser.y"
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
#line 1128 "ircd_parser.y"
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
#line 1170 "ircd_parser.y"
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
#line 1179 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1202 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1206 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1210 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1222 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1226 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1234 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1238 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1246 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1250 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1254 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1258 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1264 "ircd_parser.y"
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
#line 1275 "ircd_parser.y"
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
#line 1286 "ircd_parser.y"
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
#line 1297 "ircd_parser.y"
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
#line 1308 "ircd_parser.y"
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
#line 1319 "ircd_parser.y"
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
#line 1330 "ircd_parser.y"
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
#line 1341 "ircd_parser.y"
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
#line 1352 "ircd_parser.y"
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
#line 1363 "ircd_parser.y"
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
#line 1374 "ircd_parser.y"
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
#line 1385 "ircd_parser.y"
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
#line 1396 "ircd_parser.y"
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
#line 1407 "ircd_parser.y"
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
#line 1418 "ircd_parser.y"
    {
}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1422 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1423 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1426 "ircd_parser.y"
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
#line 1433 "ircd_parser.y"
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
#line 1440 "ircd_parser.y"
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
#line 1447 "ircd_parser.y"
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
#line 1454 "ircd_parser.y"
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
#line 1461 "ircd_parser.y"
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
#line 1468 "ircd_parser.y"
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
#line 1475 "ircd_parser.y"
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
#line 1482 "ircd_parser.y"
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
#line 1489 "ircd_parser.y"
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
#line 1496 "ircd_parser.y"
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
#line 1503 "ircd_parser.y"
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
#line 1510 "ircd_parser.y"
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
#line 1517 "ircd_parser.y"
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
#line 1524 "ircd_parser.y"
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
#line 1531 "ircd_parser.y"
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
#line 1544 "ircd_parser.y"
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
#line 1551 "ircd_parser.y"
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
#line 1611 "ircd_parser.y"
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
#line 1620 "ircd_parser.y"
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
#line 1629 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1635 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1641 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1647 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1653 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1671 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1677 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1683 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1689 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1695 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1704 "ircd_parser.y"
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
#line 1711 "ircd_parser.y"
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
#line 1720 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1726 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1734 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1744 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1749 "ircd_parser.y"
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
#line 1763 "ircd_parser.y"
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
#line 1783 "ircd_parser.y"
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
#line 1792 "ircd_parser.y"
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
#line 1804 "ircd_parser.y"
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
#line 1816 "ircd_parser.y"
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
#line 1881 "ircd_parser.y"
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
#line 1918 "ircd_parser.y"
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
#line 1931 "ircd_parser.y"
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
#line 1942 "ircd_parser.y"
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
#line 1951 "ircd_parser.y"
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
#line 1962 "ircd_parser.y"
    {
}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1966 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1967 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1970 "ircd_parser.y"
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
#line 1978 "ircd_parser.y"
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
#line 1985 "ircd_parser.y"
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
#line 1992 "ircd_parser.y"
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
#line 1999 "ircd_parser.y"
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
#line 2006 "ircd_parser.y"
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
#line 2013 "ircd_parser.y"
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
#line 2020 "ircd_parser.y"
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
#line 2027 "ircd_parser.y"
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
#line 2034 "ircd_parser.y"
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
#line 2043 "ircd_parser.y"
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
#line 2054 "ircd_parser.y"
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
#line 2065 "ircd_parser.y"
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
#line 2076 "ircd_parser.y"
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
#line 2087 "ircd_parser.y"
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
#line 2098 "ircd_parser.y"
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
#line 2110 "ircd_parser.y"
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
#line 2129 "ircd_parser.y"
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
#line 2139 "ircd_parser.y"
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
#line 2148 "ircd_parser.y"
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
#line 2163 "ircd_parser.y"
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
#line 2170 "ircd_parser.y"
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
#line 2182 "ircd_parser.y"
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
#line 2191 "ircd_parser.y"
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
#line 2206 "ircd_parser.y"
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
#line 2219 "ircd_parser.y"
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
#line 2227 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2238 "ircd_parser.y"
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
#line 2247 "ircd_parser.y"
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
#line 2269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2276 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 360:

/* Line 1455 of yacc.c  */
#line 2280 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2284 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2292 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2296 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2300 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2304 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2308 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2312 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2316 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2325 "ircd_parser.y"
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
#line 2332 "ircd_parser.y"
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
#line 2345 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 378:

/* Line 1455 of yacc.c  */
#line 2351 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2358 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 383:

/* Line 1455 of yacc.c  */
#line 2362 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 384:

/* Line 1455 of yacc.c  */
#line 2366 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2370 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 386:

/* Line 1455 of yacc.c  */
#line 2374 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 387:

/* Line 1455 of yacc.c  */
#line 2378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2382 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2386 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2390 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2394 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2398 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2407 "ircd_parser.y"
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
#line 2425 "ircd_parser.y"
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
#line 2564 "ircd_parser.y"
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
#line 2576 "ircd_parser.y"
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
#line 2588 "ircd_parser.y"
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
#line 2597 "ircd_parser.y"
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
#line 2623 "ircd_parser.y"
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
#line 2641 "ircd_parser.y"
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
#line 2659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2669 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2677 "ircd_parser.y"
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
#line 2686 "ircd_parser.y"
    {
}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2690 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2691 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2694 "ircd_parser.y"
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
#line 2705 "ircd_parser.y"
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
#line 2712 "ircd_parser.y"
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
#line 2719 "ircd_parser.y"
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
#line 2726 "ircd_parser.y"
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
#line 2736 "ircd_parser.y"
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
#line 2777 "ircd_parser.y"
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
#line 2788 "ircd_parser.y"
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
#line 2799 "ircd_parser.y"
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
#line 2814 "ircd_parser.y"
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
#line 2825 "ircd_parser.y"
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
#line 2836 "ircd_parser.y"
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
#line 2849 "ircd_parser.y"
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
#line 2862 "ircd_parser.y"
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
#line 2871 "ircd_parser.y"
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
#line 2906 "ircd_parser.y"
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
#line 2913 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 454:

/* Line 1455 of yacc.c  */
#line 2970 "ircd_parser.y"
    {
}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2975 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2984 "ircd_parser.y"
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
#line 3003 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 3012 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 3021 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 474:

/* Line 1455 of yacc.c  */
#line 3037 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 475:

/* Line 1455 of yacc.c  */
#line 3046 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 3063 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 482:

/* Line 1455 of yacc.c  */
#line 3084 "ircd_parser.y"
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
#line 3091 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 557:

/* Line 1455 of yacc.c  */
#line 3191 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 558:

/* Line 1455 of yacc.c  */
#line 3196 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 559:

/* Line 1455 of yacc.c  */
#line 3201 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 560:

/* Line 1455 of yacc.c  */
#line 3206 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 561:

/* Line 1455 of yacc.c  */
#line 3211 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 562:

/* Line 1455 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 563:

/* Line 1455 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 564:

/* Line 1455 of yacc.c  */
#line 3226 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 565:

/* Line 1455 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 566:

/* Line 1455 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 567:

/* Line 1455 of yacc.c  */
#line 3241 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 568:

/* Line 1455 of yacc.c  */
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 569:

/* Line 1455 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 570:

/* Line 1455 of yacc.c  */
#line 3256 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 571:

/* Line 1455 of yacc.c  */
#line 3261 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 572:

/* Line 1455 of yacc.c  */
#line 3266 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 573:

/* Line 1455 of yacc.c  */
#line 3271 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 574:

/* Line 1455 of yacc.c  */
#line 3276 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 575:

/* Line 1455 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 576:

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

  case 577:

/* Line 1455 of yacc.c  */
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 578:

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

  case 579:

/* Line 1455 of yacc.c  */
#line 3312 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 580:

/* Line 1455 of yacc.c  */
#line 3317 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 581:

/* Line 1455 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 582:

/* Line 1455 of yacc.c  */
#line 3327 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 583:

/* Line 1455 of yacc.c  */
#line 3332 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 584:

/* Line 1455 of yacc.c  */
#line 3337 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 585:

/* Line 1455 of yacc.c  */
#line 3340 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 586:

/* Line 1455 of yacc.c  */
#line 3345 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 587:

/* Line 1455 of yacc.c  */
#line 3348 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 588:

/* Line 1455 of yacc.c  */
#line 3353 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:

/* Line 1455 of yacc.c  */
#line 3358 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 590:

/* Line 1455 of yacc.c  */
#line 3363 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 591:

/* Line 1455 of yacc.c  */
#line 3368 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:

/* Line 1455 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 593:

/* Line 1455 of yacc.c  */
#line 3378 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 594:

/* Line 1455 of yacc.c  */
#line 3383 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 595:

/* Line 1455 of yacc.c  */
#line 3388 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 596:

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

  case 597:

/* Line 1455 of yacc.c  */
#line 3404 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:

/* Line 1455 of yacc.c  */
#line 3409 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1455 of yacc.c  */
#line 3414 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:

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

  case 601:

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

  case 602:

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

  case 603:

/* Line 1455 of yacc.c  */
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 604:

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

  case 605:

/* Line 1455 of yacc.c  */
#line 3492 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 606:

/* Line 1455 of yacc.c  */
#line 3497 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 607:

/* Line 1455 of yacc.c  */
#line 3502 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 608:

/* Line 1455 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 612:

/* Line 1455 of yacc.c  */
#line 3513 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 613:

/* Line 1455 of yacc.c  */
#line 3516 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 614:

/* Line 1455 of yacc.c  */
#line 3519 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 615:

/* Line 1455 of yacc.c  */
#line 3522 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 616:

/* Line 1455 of yacc.c  */
#line 3525 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 617:

/* Line 1455 of yacc.c  */
#line 3528 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 618:

/* Line 1455 of yacc.c  */
#line 3531 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 619:

/* Line 1455 of yacc.c  */
#line 3534 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 620:

/* Line 1455 of yacc.c  */
#line 3537 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 621:

/* Line 1455 of yacc.c  */
#line 3540 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 622:

/* Line 1455 of yacc.c  */
#line 3543 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 623:

/* Line 1455 of yacc.c  */
#line 3546 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 624:

/* Line 1455 of yacc.c  */
#line 3549 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 625:

/* Line 1455 of yacc.c  */
#line 3552 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 626:

/* Line 1455 of yacc.c  */
#line 3555 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 627:

/* Line 1455 of yacc.c  */
#line 3558 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 628:

/* Line 1455 of yacc.c  */
#line 3561 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 629:

/* Line 1455 of yacc.c  */
#line 3564 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 630:

/* Line 1455 of yacc.c  */
#line 3567 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 631:

/* Line 1455 of yacc.c  */
#line 3572 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 635:

/* Line 1455 of yacc.c  */
#line 3578 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 636:

/* Line 1455 of yacc.c  */
#line 3581 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 637:

/* Line 1455 of yacc.c  */
#line 3584 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 638:

/* Line 1455 of yacc.c  */
#line 3587 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 639:

/* Line 1455 of yacc.c  */
#line 3590 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 640:

/* Line 1455 of yacc.c  */
#line 3593 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 641:

/* Line 1455 of yacc.c  */
#line 3596 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 642:

/* Line 1455 of yacc.c  */
#line 3599 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 643:

/* Line 1455 of yacc.c  */
#line 3602 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 644:

/* Line 1455 of yacc.c  */
#line 3605 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 645:

/* Line 1455 of yacc.c  */
#line 3608 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 646:

/* Line 1455 of yacc.c  */
#line 3611 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 647:

/* Line 1455 of yacc.c  */
#line 3614 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 648:

/* Line 1455 of yacc.c  */
#line 3617 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 649:

/* Line 1455 of yacc.c  */
#line 3620 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 650:

/* Line 1455 of yacc.c  */
#line 3623 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 651:

/* Line 1455 of yacc.c  */
#line 3626 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 652:

/* Line 1455 of yacc.c  */
#line 3629 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 653:

/* Line 1455 of yacc.c  */
#line 3632 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 654:

/* Line 1455 of yacc.c  */
#line 3637 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 655:

/* Line 1455 of yacc.c  */
#line 3642 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 656:

/* Line 1455 of yacc.c  */
#line 3647 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 657:

/* Line 1455 of yacc.c  */
#line 3652 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 658:

/* Line 1455 of yacc.c  */
#line 3657 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 659:

/* Line 1455 of yacc.c  */
#line 3665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 660:

/* Line 1455 of yacc.c  */
#line 3672 "ircd_parser.y"
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

  case 670:

/* Line 1455 of yacc.c  */
#line 3698 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 671:

/* Line 1455 of yacc.c  */
#line 3704 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 672:

/* Line 1455 of yacc.c  */
#line 3710 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 676:

/* Line 1455 of yacc.c  */
#line 3716 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 677:

/* Line 1455 of yacc.c  */
#line 3720 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 678:

/* Line 1455 of yacc.c  */
#line 3726 "ircd_parser.y"
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

  case 679:

/* Line 1455 of yacc.c  */
#line 3760 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 680:

/* Line 1455 of yacc.c  */
#line 3769 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 681:

/* Line 1455 of yacc.c  */
#line 3773 "ircd_parser.y"
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

  case 684:

/* Line 1455 of yacc.c  */
#line 3820 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 685:

/* Line 1455 of yacc.c  */
#line 3824 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 708:

/* Line 1455 of yacc.c  */
#line 3848 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 709:

/* Line 1455 of yacc.c  */
#line 3853 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 710:

/* Line 1455 of yacc.c  */
#line 3858 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 711:

/* Line 1455 of yacc.c  */
#line 3863 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 712:

/* Line 1455 of yacc.c  */
#line 3868 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 713:

/* Line 1455 of yacc.c  */
#line 3873 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 714:

/* Line 1455 of yacc.c  */
#line 3878 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 715:

/* Line 1455 of yacc.c  */
#line 3883 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 716:

/* Line 1455 of yacc.c  */
#line 3888 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 717:

/* Line 1455 of yacc.c  */
#line 3893 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 718:

/* Line 1455 of yacc.c  */
#line 3898 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 719:

/* Line 1455 of yacc.c  */
#line 3903 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 720:

/* Line 1455 of yacc.c  */
#line 3908 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 721:

/* Line 1455 of yacc.c  */
#line 3913 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 722:

/* Line 1455 of yacc.c  */
#line 3918 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 723:

/* Line 1455 of yacc.c  */
#line 3923 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 724:

/* Line 1455 of yacc.c  */
#line 3928 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 725:

/* Line 1455 of yacc.c  */
#line 3933 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 737:

/* Line 1455 of yacc.c  */
#line 3952 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 738:

/* Line 1455 of yacc.c  */
#line 3958 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 739:

/* Line 1455 of yacc.c  */
#line 3964 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 740:

/* Line 1455 of yacc.c  */
#line 3973 "ircd_parser.y"
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

  case 741:

/* Line 1455 of yacc.c  */
#line 3987 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 742:

/* Line 1455 of yacc.c  */
#line 3993 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 743:

/* Line 1455 of yacc.c  */
#line 3999 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1455 of yacc.c  */
#line 8608 "ircd_parser.c"
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



