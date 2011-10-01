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
#line 179 "ircd_parser.c"

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
     GECOS = 309,
     GENERAL = 310,
     GLINE = 311,
     GLINES = 312,
     GLINE_EXEMPT = 313,
     GLINE_TIME = 314,
     GLINE_MIN_CIDR = 315,
     GLINE_MIN_CIDR6 = 316,
     GLOBAL_KILL = 317,
     IRCD_AUTH = 318,
     NEED_IDENT = 319,
     HAVENT_READ_CONF = 320,
     HIDDEN = 321,
     HIDDEN_ADMIN = 322,
     HIDDEN_NAME = 323,
     HIDDEN_OPER = 324,
     HIDE_SERVER_IPS = 325,
     HIDE_SERVERS = 326,
     HIDE_SPOOF_IPS = 327,
     HOST = 328,
     HUB = 329,
     HUB_MASK = 330,
     IGNORE_BOGUS_TS = 331,
     INVISIBLE_ON_CONNECT = 332,
     IP = 333,
     KILL = 334,
     KILL_CHASE_TIME_LIMIT = 335,
     KLINE = 336,
     KLINE_EXEMPT = 337,
     KLINE_REASON = 338,
     KLINE_WITH_REASON = 339,
     KNOCK_DELAY = 340,
     KNOCK_DELAY_CHANNEL = 341,
     LEAF_MASK = 342,
     LINKS_DELAY = 343,
     LISTEN = 344,
     T_LOG = 345,
     MAX_ACCEPT = 346,
     MAX_BANS = 347,
     MAX_CHANS_PER_USER = 348,
     MAX_GLOBAL = 349,
     MAX_IDENT = 350,
     MAX_LOCAL = 351,
     MAX_NICK_CHANGES = 352,
     MAX_NICK_TIME = 353,
     MAX_NUMBER = 354,
     MAX_TARGETS = 355,
     MAX_WATCH = 356,
     MESSAGE_LOCALE = 357,
     MIN_NONWILDCARD = 358,
     MIN_NONWILDCARD_SIMPLE = 359,
     MODULE = 360,
     MODULES = 361,
     NAME = 362,
     NEED_PASSWORD = 363,
     NETWORK_DESC = 364,
     NETWORK_NAME = 365,
     NICK = 366,
     NICK_CHANGES = 367,
     NO_CREATE_ON_SPLIT = 368,
     NO_JOIN_ON_SPLIT = 369,
     NO_OPER_FLOOD = 370,
     NO_TILDE = 371,
     NUMBER = 372,
     NUMBER_PER_IDENT = 373,
     NUMBER_PER_CIDR = 374,
     NUMBER_PER_IP = 375,
     NUMBER_PER_IP_GLOBAL = 376,
     OPERATOR = 377,
     OPERS_BYPASS_CALLERID = 378,
     OPER_ONLY_UMODES = 379,
     OPER_PASS_RESV = 380,
     OPER_SPY_T = 381,
     OPER_UMODES = 382,
     JOIN_FLOOD_COUNT = 383,
     JOIN_FLOOD_TIME = 384,
     PACE_WAIT = 385,
     PACE_WAIT_SIMPLE = 386,
     PASSWORD = 387,
     PATH = 388,
     PING_COOKIE = 389,
     PING_TIME = 390,
     PING_WARNING = 391,
     PORT = 392,
     QSTRING = 393,
     QUIET_ON_BAN = 394,
     REASON = 395,
     REDIRPORT = 396,
     REDIRSERV = 397,
     REGEX_T = 398,
     REHASH = 399,
     TREJECT_HOLD_TIME = 400,
     REMOTE = 401,
     REMOTEBAN = 402,
     RESTRICT_CHANNELS = 403,
     RESTRICTED = 404,
     RSA_PRIVATE_KEY_FILE = 405,
     RSA_PUBLIC_KEY_FILE = 406,
     SSL_CERTIFICATE_FILE = 407,
     T_SSL_CONNECTION_METHOD = 408,
     T_SSLV3 = 409,
     T_TLSV1 = 410,
     RESV = 411,
     RESV_EXEMPT = 412,
     SECONDS = 413,
     MINUTES = 414,
     HOURS = 415,
     DAYS = 416,
     WEEKS = 417,
     SENDQ = 418,
     SEND_PASSWORD = 419,
     SERVERHIDE = 420,
     SERVERINFO = 421,
     SERVLINK_PATH = 422,
     IRCD_SID = 423,
     TKLINE_EXPIRE_NOTICES = 424,
     T_SHARED = 425,
     T_CLUSTER = 426,
     TYPE = 427,
     SHORT_MOTD = 428,
     SILENT = 429,
     SPOOF = 430,
     SPOOF_NOTICE = 431,
     STATS_E_DISABLED = 432,
     STATS_I_OPER_ONLY = 433,
     STATS_K_OPER_ONLY = 434,
     STATS_O_OPER_ONLY = 435,
     STATS_P_OPER_ONLY = 436,
     TBOOL = 437,
     TMASKED = 438,
     T_REJECT = 439,
     TS_MAX_DELTA = 440,
     TS_WARN_DELTA = 441,
     TWODOTS = 442,
     T_ALL = 443,
     T_BOTS = 444,
     T_SOFTCALLERID = 445,
     T_CALLERID = 446,
     T_CCONN = 447,
     T_CCONN_FULL = 448,
     T_CLIENT_FLOOD = 449,
     T_DEAF = 450,
     T_DEBUG = 451,
     T_DLINE = 452,
     T_DRONE = 453,
     T_EXTERNAL = 454,
     T_FULL = 455,
     T_INVISIBLE = 456,
     T_IPV4 = 457,
     T_IPV6 = 458,
     T_LOCOPS = 459,
     T_MAX_CLIENTS = 460,
     T_NCHANGE = 461,
     T_OPERWALL = 462,
     T_REJ = 463,
     T_SERVER = 464,
     T_SERVNOTICE = 465,
     T_SKILL = 466,
     T_SPY = 467,
     T_SSL = 468,
     T_UMODES = 469,
     T_UNAUTH = 470,
     T_UNRESV = 471,
     T_UNXLINE = 472,
     T_GLOBOPS = 473,
     T_WALLOP = 474,
     T_RESTART = 475,
     T_SERVICE = 476,
     T_SERVICES_NAME = 477,
     T_TIMESTAMP = 478,
     THROTTLE_TIME = 479,
     TOPICBURST = 480,
     TRUE_NO_OPER_FLOOD = 481,
     TKLINE = 482,
     TXLINE = 483,
     TRESV = 484,
     UNKLINE = 485,
     USER = 486,
     USE_EGD = 487,
     USE_EXCEPT = 488,
     USE_INVEX = 489,
     USE_KNOCK = 490,
     USE_LOGGING = 491,
     USE_WHOIS_ACTUALLY = 492,
     VHOST = 493,
     VHOST6 = 494,
     XLINE = 495,
     WARN = 496,
     WARN_NO_NLINE = 497,
     T_SIZE = 498,
     T_FILE = 499
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
#define GECOS 309
#define GENERAL 310
#define GLINE 311
#define GLINES 312
#define GLINE_EXEMPT 313
#define GLINE_TIME 314
#define GLINE_MIN_CIDR 315
#define GLINE_MIN_CIDR6 316
#define GLOBAL_KILL 317
#define IRCD_AUTH 318
#define NEED_IDENT 319
#define HAVENT_READ_CONF 320
#define HIDDEN 321
#define HIDDEN_ADMIN 322
#define HIDDEN_NAME 323
#define HIDDEN_OPER 324
#define HIDE_SERVER_IPS 325
#define HIDE_SERVERS 326
#define HIDE_SPOOF_IPS 327
#define HOST 328
#define HUB 329
#define HUB_MASK 330
#define IGNORE_BOGUS_TS 331
#define INVISIBLE_ON_CONNECT 332
#define IP 333
#define KILL 334
#define KILL_CHASE_TIME_LIMIT 335
#define KLINE 336
#define KLINE_EXEMPT 337
#define KLINE_REASON 338
#define KLINE_WITH_REASON 339
#define KNOCK_DELAY 340
#define KNOCK_DELAY_CHANNEL 341
#define LEAF_MASK 342
#define LINKS_DELAY 343
#define LISTEN 344
#define T_LOG 345
#define MAX_ACCEPT 346
#define MAX_BANS 347
#define MAX_CHANS_PER_USER 348
#define MAX_GLOBAL 349
#define MAX_IDENT 350
#define MAX_LOCAL 351
#define MAX_NICK_CHANGES 352
#define MAX_NICK_TIME 353
#define MAX_NUMBER 354
#define MAX_TARGETS 355
#define MAX_WATCH 356
#define MESSAGE_LOCALE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULES 361
#define NAME 362
#define NEED_PASSWORD 363
#define NETWORK_DESC 364
#define NETWORK_NAME 365
#define NICK 366
#define NICK_CHANGES 367
#define NO_CREATE_ON_SPLIT 368
#define NO_JOIN_ON_SPLIT 369
#define NO_OPER_FLOOD 370
#define NO_TILDE 371
#define NUMBER 372
#define NUMBER_PER_IDENT 373
#define NUMBER_PER_CIDR 374
#define NUMBER_PER_IP 375
#define NUMBER_PER_IP_GLOBAL 376
#define OPERATOR 377
#define OPERS_BYPASS_CALLERID 378
#define OPER_ONLY_UMODES 379
#define OPER_PASS_RESV 380
#define OPER_SPY_T 381
#define OPER_UMODES 382
#define JOIN_FLOOD_COUNT 383
#define JOIN_FLOOD_TIME 384
#define PACE_WAIT 385
#define PACE_WAIT_SIMPLE 386
#define PASSWORD 387
#define PATH 388
#define PING_COOKIE 389
#define PING_TIME 390
#define PING_WARNING 391
#define PORT 392
#define QSTRING 393
#define QUIET_ON_BAN 394
#define REASON 395
#define REDIRPORT 396
#define REDIRSERV 397
#define REGEX_T 398
#define REHASH 399
#define TREJECT_HOLD_TIME 400
#define REMOTE 401
#define REMOTEBAN 402
#define RESTRICT_CHANNELS 403
#define RESTRICTED 404
#define RSA_PRIVATE_KEY_FILE 405
#define RSA_PUBLIC_KEY_FILE 406
#define SSL_CERTIFICATE_FILE 407
#define T_SSL_CONNECTION_METHOD 408
#define T_SSLV3 409
#define T_TLSV1 410
#define RESV 411
#define RESV_EXEMPT 412
#define SECONDS 413
#define MINUTES 414
#define HOURS 415
#define DAYS 416
#define WEEKS 417
#define SENDQ 418
#define SEND_PASSWORD 419
#define SERVERHIDE 420
#define SERVERINFO 421
#define SERVLINK_PATH 422
#define IRCD_SID 423
#define TKLINE_EXPIRE_NOTICES 424
#define T_SHARED 425
#define T_CLUSTER 426
#define TYPE 427
#define SHORT_MOTD 428
#define SILENT 429
#define SPOOF 430
#define SPOOF_NOTICE 431
#define STATS_E_DISABLED 432
#define STATS_I_OPER_ONLY 433
#define STATS_K_OPER_ONLY 434
#define STATS_O_OPER_ONLY 435
#define STATS_P_OPER_ONLY 436
#define TBOOL 437
#define TMASKED 438
#define T_REJECT 439
#define TS_MAX_DELTA 440
#define TS_WARN_DELTA 441
#define TWODOTS 442
#define T_ALL 443
#define T_BOTS 444
#define T_SOFTCALLERID 445
#define T_CALLERID 446
#define T_CCONN 447
#define T_CCONN_FULL 448
#define T_CLIENT_FLOOD 449
#define T_DEAF 450
#define T_DEBUG 451
#define T_DLINE 452
#define T_DRONE 453
#define T_EXTERNAL 454
#define T_FULL 455
#define T_INVISIBLE 456
#define T_IPV4 457
#define T_IPV6 458
#define T_LOCOPS 459
#define T_MAX_CLIENTS 460
#define T_NCHANGE 461
#define T_OPERWALL 462
#define T_REJ 463
#define T_SERVER 464
#define T_SERVNOTICE 465
#define T_SKILL 466
#define T_SPY 467
#define T_SSL 468
#define T_UMODES 469
#define T_UNAUTH 470
#define T_UNRESV 471
#define T_UNXLINE 472
#define T_GLOBOPS 473
#define T_WALLOP 474
#define T_RESTART 475
#define T_SERVICE 476
#define T_SERVICES_NAME 477
#define T_TIMESTAMP 478
#define THROTTLE_TIME 479
#define TOPICBURST 480
#define TRUE_NO_OPER_FLOOD 481
#define TKLINE 482
#define TXLINE 483
#define TRESV 484
#define UNKLINE 485
#define USER 486
#define USE_EGD 487
#define USE_EXCEPT 488
#define USE_INVEX 489
#define USE_KNOCK 490
#define USE_LOGGING 491
#define USE_WHOIS_ACTUALLY 492
#define VHOST 493
#define VHOST6 494
#define XLINE 495
#define WARN 496
#define WARN_NO_NLINE 497
#define T_SIZE 498
#define T_FILE 499




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 710 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 722 "ircd_parser.c"

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
#define YYNTOKENS  250
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  313
/* YYNRULES -- Number of rules.  */
#define YYNRULES  679
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1329

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   499

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   249,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   245,
       2,   248,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   247,     2,   246,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244
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
     262,   267,   272,   278,   281,   283,   285,   287,   289,   292,
     297,   302,   303,   310,   313,   315,   317,   319,   321,   324,
     329,   334,   335,   341,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   362,   370,   371,   373,   376,   378,   380,
     382,   384,   386,   388,   390,   392,   394,   397,   402,   404,
     409,   414,   419,   424,   429,   430,   436,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   462,   464,
     466,   468,   470,   472,   474,   476,   478,   480,   481,   487,
     491,   493,   495,   497,   499,   501,   503,   505,   507,   509,
     511,   513,   515,   517,   519,   521,   523,   525,   527,   529,
     530,   538,   539,   541,   544,   546,   548,   550,   552,   554,
     556,   558,   560,   562,   564,   566,   568,   570,   572,   575,
     580,   582,   587,   592,   597,   602,   607,   612,   617,   622,
     627,   632,   637,   642,   643,   650,   651,   657,   661,   663,
     665,   667,   669,   672,   674,   676,   678,   680,   682,   685,
     686,   692,   696,   698,   700,   704,   709,   714,   715,   722,
     725,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     746,   751,   756,   761,   766,   767,   773,   777,   779,   781,
     783,   785,   787,   789,   791,   793,   795,   797,   802,   807,
     812,   813,   820,   823,   825,   827,   829,   831,   834,   839,
     844,   849,   855,   858,   860,   862,   864,   869,   870,   877,
     880,   882,   884,   886,   888,   891,   896,   901,   902,   908,
     912,   914,   916,   918,   920,   922,   924,   926,   928,   930,
     932,   934,   936,   937,   944,   947,   949,   951,   953,   956,
     961,   962,   968,   972,   974,   976,   978,   980,   982,   984,
     986,   988,   990,   992,   994,   996,   997,  1005,  1006,  1008,
    1011,  1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,
    1031,  1033,  1035,  1037,  1039,  1041,  1044,  1049,  1051,  1056,
    1061,  1066,  1071,  1076,  1081,  1086,  1087,  1093,  1097,  1099,
    1101,  1103,  1105,  1107,  1109,  1114,  1119,  1124,  1129,  1134,
    1139,  1140,  1147,  1148,  1154,  1158,  1160,  1162,  1165,  1167,
    1169,  1171,  1173,  1175,  1180,  1185,  1186,  1193,  1196,  1198,
    1200,  1202,  1204,  1209,  1214,  1220,  1223,  1225,  1227,  1229,
    1234,  1235,  1242,  1243,  1249,  1253,  1255,  1257,  1260,  1262,
    1264,  1266,  1268,  1270,  1275,  1280,  1286,  1289,  1291,  1293,
    1295,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1315,  1317,  1319,  1321,  1323,  1325,  1327,  1329,  1331,  1333,
    1335,  1337,  1339,  1341,  1343,  1345,  1347,  1349,  1351,  1353,
    1355,  1357,  1359,  1361,  1363,  1365,  1367,  1369,  1371,  1373,
    1375,  1377,  1379,  1381,  1383,  1385,  1387,  1389,  1391,  1393,
    1395,  1397,  1399,  1401,  1403,  1408,  1413,  1418,  1423,  1428,
    1433,  1438,  1443,  1448,  1453,  1458,  1463,  1468,  1473,  1478,
    1483,  1488,  1493,  1498,  1503,  1508,  1513,  1518,  1523,  1528,
    1533,  1538,  1543,  1548,  1553,  1558,  1563,  1568,  1573,  1578,
    1583,  1588,  1593,  1598,  1603,  1608,  1613,  1618,  1623,  1628,
    1633,  1638,  1643,  1648,  1653,  1658,  1659,  1665,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,
    1693,  1695,  1697,  1699,  1701,  1703,  1705,  1707,  1709,  1710,
    1716,  1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,
    1738,  1740,  1742,  1744,  1746,  1748,  1750,  1752,  1754,  1756,
    1758,  1760,  1765,  1770,  1775,  1780,  1781,  1788,  1791,  1793,
    1795,  1797,  1799,  1801,  1803,  1805,  1807,  1812,  1817,  1818,
    1824,  1828,  1830,  1832,  1834,  1839,  1844,  1845,  1851,  1855,
    1857,  1859,  1861,  1867,  1870,  1872,  1874,  1876,  1878,  1880,
    1882,  1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,  1900,
    1902,  1904,  1906,  1908,  1910,  1915,  1920,  1925,  1930,  1935,
    1940,  1945,  1950,  1955,  1960,  1965,  1970,  1975,  1980,  1985,
    1990,  1995,  2000,  2006,  2009,  2011,  2013,  2015,  2017,  2019,
    2021,  2023,  2025,  2027,  2032,  2037,  2042,  2047,  2052,  2057
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     251,     0,    -1,    -1,   251,   252,    -1,   280,    -1,   286,
      -1,   301,    -1,   532,    -1,   321,    -1,   340,    -1,   354,
      -1,   262,    -1,   553,    -1,   369,    -1,   376,    -1,   380,
      -1,   390,    -1,   399,    -1,   422,    -1,   432,    -1,   438,
      -1,   452,    -1,   516,    -1,   442,    -1,   257,    -1,     1,
     245,    -1,     1,   246,    -1,    -1,   254,    -1,   117,   253,
      -1,   117,   158,   253,    -1,   117,   159,   253,    -1,   117,
     160,   253,    -1,   117,   161,   253,    -1,   117,   162,   253,
      -1,    -1,   256,    -1,   117,   255,    -1,   117,    14,   255,
      -1,   117,    15,   255,    -1,   117,    16,   255,    -1,   106,
     247,   258,   246,   245,    -1,   258,   259,    -1,   259,    -1,
     260,    -1,   261,    -1,     1,   245,    -1,   105,   248,   138,
     245,    -1,   133,   248,   138,   245,    -1,   166,   247,   263,
     246,   245,    -1,   263,   264,    -1,   264,    -1,   271,    -1,
     276,    -1,   279,    -1,   273,    -1,   274,    -1,   275,    -1,
     278,    -1,   270,    -1,   277,    -1,   272,    -1,   269,    -1,
     265,    -1,     1,   245,    -1,    -1,   153,   266,   248,   267,
     245,    -1,   267,   249,   268,    -1,   268,    -1,   154,    -1,
     155,    -1,   152,   248,   138,   245,    -1,   150,   248,   138,
     245,    -1,   107,   248,   138,   245,    -1,   168,   248,   138,
     245,    -1,    36,   248,   138,   245,    -1,   110,   248,   138,
     245,    -1,   109,   248,   138,   245,    -1,   238,   248,   138,
     245,    -1,   239,   248,   138,   245,    -1,   205,   248,   117,
     245,    -1,    74,   248,   182,   245,    -1,     5,   247,   281,
     246,   245,    -1,   281,   282,    -1,   282,    -1,   283,    -1,
     285,    -1,   284,    -1,     1,   245,    -1,   107,   248,   138,
     245,    -1,    46,   248,   138,   245,    -1,    36,   248,   138,
     245,    -1,    90,   247,   287,   246,   245,    -1,   287,   288,
      -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,     1,
     245,    -1,   236,   248,   182,   245,    -1,   223,   248,   182,
     245,    -1,    -1,   292,   244,   247,   293,   246,   245,    -1,
     293,   294,    -1,   294,    -1,   295,    -1,   297,    -1,   296,
      -1,     1,   245,    -1,   107,   248,   138,   245,    -1,   243,
     248,   256,   245,    -1,    -1,   172,   298,   248,   299,   245,
      -1,   299,   249,   300,    -1,   300,    -1,   231,    -1,   122,
      -1,    56,    -1,   197,    -1,    81,    -1,    79,    -1,   196,
      -1,    -1,   122,   302,   303,   247,   304,   246,   245,    -1,
      -1,   307,    -1,   304,   305,    -1,   305,    -1,   306,    -1,
     308,    -1,   309,    -1,   313,    -1,   312,    -1,   310,    -1,
     311,    -1,   317,    -1,     1,   245,    -1,   107,   248,   138,
     245,    -1,   138,    -1,   231,   248,   138,   245,    -1,   132,
     248,   138,   245,    -1,    48,   248,   182,   245,    -1,   151,
     248,   138,   245,    -1,    25,   248,   138,   245,    -1,    -1,
     214,   314,   248,   315,   245,    -1,   315,   249,   316,    -1,
     316,    -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,
     196,    -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,
     215,    -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,
     201,    -1,   219,    -1,   190,    -1,   191,    -1,   204,    -1,
      -1,    52,   318,   248,   319,   245,    -1,   319,   249,   320,
      -1,   320,    -1,    62,    -1,   146,    -1,    81,    -1,   230,
      -1,   240,    -1,    56,    -1,    37,    -1,   220,    -1,   144,
      -1,     5,    -1,    67,    -1,   112,    -1,   207,    -1,   218,
      -1,   126,    -1,    69,    -1,   147,    -1,   105,    -1,    -1,
      25,   322,   323,   247,   324,   246,   245,    -1,    -1,   327,
      -1,   324,   325,    -1,   325,    -1,   326,    -1,   337,    -1,
     338,    -1,   328,    -1,   329,    -1,   339,    -1,   330,    -1,
     331,    -1,   332,    -1,   333,    -1,   334,    -1,   335,    -1,
     336,    -1,     1,   245,    -1,   107,   248,   138,   245,    -1,
     138,    -1,   135,   248,   254,   245,    -1,   136,   248,   254,
     245,    -1,   120,   248,   117,   245,    -1,    29,   248,   254,
     245,    -1,    99,   248,   117,   245,    -1,    94,   248,   117,
     245,    -1,    96,   248,   117,   245,    -1,    95,   248,   117,
     245,    -1,   163,   248,   256,   245,    -1,    22,   248,   117,
     245,    -1,    23,   248,   117,   245,    -1,   119,   248,   117,
     245,    -1,    -1,    89,   341,   247,   346,   246,   245,    -1,
      -1,    52,   343,   248,   344,   245,    -1,   344,   249,   345,
      -1,   345,    -1,   213,    -1,    66,    -1,   209,    -1,   346,
     347,    -1,   347,    -1,   348,    -1,   342,    -1,   352,    -1,
     353,    -1,     1,   245,    -1,    -1,   137,   248,   350,   349,
     245,    -1,   350,   249,   351,    -1,   351,    -1,   117,    -1,
     117,   187,   117,    -1,    78,   248,   138,   245,    -1,    73,
     248,   138,   245,    -1,    -1,    63,   355,   247,   356,   246,
     245,    -1,   356,   357,    -1,   357,    -1,   358,    -1,   359,
      -1,   360,    -1,   362,    -1,   366,    -1,   367,    -1,   368,
      -1,   361,    -1,     1,   245,    -1,   231,   248,   138,   245,
      -1,   132,   248,   138,   245,    -1,    25,   248,   138,   245,
      -1,    48,   248,   182,   245,    -1,    -1,    52,   363,   248,
     364,   245,    -1,   364,   249,   365,    -1,   365,    -1,   176,
      -1,    49,    -1,    82,    -1,    64,    -1,    20,    -1,   116,
      -1,    58,    -1,   157,    -1,   108,    -1,   175,   248,   138,
     245,    -1,   142,   248,   138,   245,    -1,   141,   248,   117,
     245,    -1,    -1,   156,   370,   247,   371,   246,   245,    -1,
     371,   372,    -1,   372,    -1,   373,    -1,   374,    -1,   375,
      -1,     1,   245,    -1,   140,   248,   138,   245,    -1,    21,
     248,   138,   245,    -1,   111,   248,   138,   245,    -1,   221,
     247,   377,   246,   245,    -1,   377,   378,    -1,   378,    -1,
     379,    -1,     1,    -1,   107,   248,   138,   245,    -1,    -1,
     170,   381,   247,   382,   246,   245,    -1,   382,   383,    -1,
     383,    -1,   384,    -1,   385,    -1,   386,    -1,     1,   245,
      -1,   107,   248,   138,   245,    -1,   231,   248,   138,   245,
      -1,    -1,   172,   387,   248,   388,   245,    -1,   388,   249,
     389,    -1,   389,    -1,    81,    -1,   227,    -1,   230,    -1,
     240,    -1,   228,    -1,   217,    -1,   156,    -1,   229,    -1,
     216,    -1,   204,    -1,   188,    -1,    -1,   171,   391,   247,
     392,   246,   245,    -1,   392,   393,    -1,   393,    -1,   394,
      -1,   395,    -1,     1,   245,    -1,   107,   248,   138,   245,
      -1,    -1,   172,   396,   248,   397,   245,    -1,   397,   249,
     398,    -1,   398,    -1,    81,    -1,   227,    -1,   230,    -1,
     240,    -1,   228,    -1,   217,    -1,   156,    -1,   229,    -1,
     216,    -1,   204,    -1,   188,    -1,    -1,    28,   400,   401,
     247,   402,   246,   245,    -1,    -1,   405,    -1,   402,   403,
      -1,   403,    -1,   404,    -1,   406,    -1,   407,    -1,   408,
      -1,   409,    -1,   411,    -1,   410,    -1,   412,    -1,   418,
      -1,   419,    -1,   420,    -1,   417,    -1,   416,    -1,   421,
      -1,     1,   245,    -1,   107,   248,   138,   245,    -1,   138,
      -1,    73,   248,   138,   245,    -1,   238,   248,   138,   245,
      -1,   164,   248,   138,   245,    -1,     3,   248,   138,   245,
      -1,   137,   248,   117,   245,    -1,     6,   248,   202,   245,
      -1,     6,   248,   203,   245,    -1,    -1,    52,   413,   248,
     414,   245,    -1,   414,   249,   415,    -1,   415,    -1,    26,
      -1,    30,    -1,    10,    -1,    12,    -1,   225,    -1,   151,
     248,   138,   245,    -1,    48,   248,   182,   245,    -1,    75,
     248,   138,   245,    -1,    87,   248,   138,   245,    -1,    25,
     248,   138,   245,    -1,    24,   248,   138,   245,    -1,    -1,
      79,   423,   247,   428,   246,   245,    -1,    -1,   172,   425,
     248,   426,   245,    -1,   426,   249,   427,    -1,   427,    -1,
     143,    -1,   428,   429,    -1,   429,    -1,   430,    -1,   431,
      -1,   424,    -1,     1,    -1,   231,   248,   138,   245,    -1,
     140,   248,   138,   245,    -1,    -1,    35,   433,   247,   434,
     246,   245,    -1,   434,   435,    -1,   435,    -1,   436,    -1,
     437,    -1,     1,    -1,    78,   248,   138,   245,    -1,   140,
     248,   138,   245,    -1,    50,   247,   439,   246,   245,    -1,
     439,   440,    -1,   440,    -1,   441,    -1,     1,    -1,    78,
     248,   138,   245,    -1,    -1,    54,   443,   247,   448,   246,
     245,    -1,    -1,   172,   445,   248,   446,   245,    -1,   446,
     249,   447,    -1,   447,    -1,   143,    -1,   448,   449,    -1,
     449,    -1,   450,    -1,   451,    -1,   444,    -1,     1,    -1,
     107,   248,   138,   245,    -1,   140,   248,   138,   245,    -1,
      55,   247,   453,   246,   245,    -1,   453,   454,    -1,   454,
      -1,   463,    -1,   464,    -1,   466,    -1,   467,    -1,   468,
      -1,   469,    -1,   470,    -1,   471,    -1,   472,    -1,   473,
      -1,   462,    -1,   475,    -1,   476,    -1,   477,    -1,   478,
      -1,   493,    -1,   480,    -1,   482,    -1,   484,    -1,   483,
      -1,   487,    -1,   481,    -1,   488,    -1,   489,    -1,   490,
      -1,   491,    -1,   492,    -1,   508,    -1,   494,    -1,   498,
      -1,   499,    -1,   504,    -1,   485,    -1,   486,    -1,   514,
      -1,   512,    -1,   513,    -1,   495,    -1,   465,    -1,   496,
      -1,   497,    -1,   515,    -1,   503,    -1,   474,    -1,   501,
      -1,   502,    -1,   458,    -1,   461,    -1,   456,    -1,   457,
      -1,   459,    -1,   460,    -1,   479,    -1,   455,    -1,   500,
      -1,     1,    -1,   101,   248,   117,   245,    -1,    60,   248,
     117,   245,    -1,    61,   248,   117,   245,    -1,    12,   248,
     182,   245,    -1,   237,   248,   182,   245,    -1,   145,   248,
     254,   245,    -1,   169,   248,   182,   245,    -1,    80,   248,
     254,   245,    -1,    72,   248,   182,   245,    -1,    76,   248,
     182,   245,    -1,    42,   248,   182,   245,    -1,    51,   248,
     182,   245,    -1,     8,   248,   182,   245,    -1,    98,   248,
     254,   245,    -1,    97,   248,   117,   245,    -1,    91,   248,
     117,   245,    -1,     9,   248,   254,   245,    -1,   186,   248,
     254,   245,    -1,   185,   248,   254,   245,    -1,    65,   248,
     117,   245,    -1,    84,   248,   182,   245,    -1,    83,   248,
     138,   245,    -1,    77,   248,   182,   245,    -1,   242,   248,
     182,   245,    -1,   177,   248,   182,   245,    -1,   180,   248,
     182,   245,    -1,   181,   248,   182,   245,    -1,   179,   248,
     182,   245,    -1,   179,   248,   183,   245,    -1,   178,   248,
     182,   245,    -1,   178,   248,   183,   245,    -1,   130,   248,
     254,   245,    -1,    19,   248,   254,   245,    -1,   123,   248,
     182,   245,    -1,   131,   248,   254,   245,    -1,   173,   248,
     182,   245,    -1,   115,   248,   182,   245,    -1,   226,   248,
     182,   245,    -1,   125,   248,   182,   245,    -1,   102,   248,
     138,   245,    -1,    43,   248,   117,   245,    -1,   100,   248,
     117,   245,    -1,   167,   248,   138,   245,    -1,    31,   248,
     138,   245,    -1,    27,   248,   117,   245,    -1,   232,   248,
     182,   245,    -1,    45,   248,   138,   245,    -1,   222,   248,
     138,   245,    -1,   134,   248,   182,   245,    -1,    38,   248,
     182,   245,    -1,   224,   248,   254,   245,    -1,    -1,   127,
     505,   248,   506,   245,    -1,   506,   249,   507,    -1,   507,
      -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,   196,
      -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,   215,
      -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,   201,
      -1,   219,    -1,   190,    -1,   191,    -1,   204,    -1,    -1,
     124,   509,   248,   510,   245,    -1,   510,   249,   511,    -1,
     511,    -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,
     196,    -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,
     215,    -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,
     201,    -1,   219,    -1,   190,    -1,   191,    -1,   204,    -1,
     103,   248,   117,   245,    -1,   104,   248,   117,   245,    -1,
      32,   248,   117,   245,    -1,   194,   248,   256,   245,    -1,
      -1,    57,   517,   247,   518,   246,   245,    -1,   518,   519,
      -1,   519,    -1,   520,    -1,   521,    -1,   522,    -1,   526,
      -1,   527,    -1,   528,    -1,     1,    -1,    47,   248,   182,
     245,    -1,    44,   248,   254,   245,    -1,    -1,    90,   523,
     248,   524,   245,    -1,   524,   249,   525,    -1,   525,    -1,
     184,    -1,    11,    -1,   231,   248,   138,   245,    -1,   107,
     248,   138,   245,    -1,    -1,     4,   529,   248,   530,   245,
      -1,   530,   249,   531,    -1,   531,    -1,   184,    -1,    11,
      -1,    21,   247,   533,   246,   245,    -1,   533,   534,    -1,
     534,    -1,   537,    -1,   538,    -1,   539,    -1,   540,    -1,
     545,    -1,   541,    -1,   542,    -1,   543,    -1,   544,    -1,
     546,    -1,   547,    -1,   548,    -1,   536,    -1,   549,    -1,
     550,    -1,   551,    -1,   552,    -1,   535,    -1,     1,    -1,
      39,   248,   182,   245,    -1,   148,   248,   182,   245,    -1,
      41,   248,   182,   245,    -1,   233,   248,   182,   245,    -1,
     234,   248,   182,   245,    -1,   235,   248,   182,   245,    -1,
      85,   248,   254,   245,    -1,    86,   248,   254,   245,    -1,
      93,   248,   117,   245,    -1,   139,   248,   182,   245,    -1,
      92,   248,   117,   245,    -1,    34,   248,   117,   245,    -1,
      33,   248,   117,   245,    -1,   113,   248,   182,   245,    -1,
     114,   248,   182,   245,    -1,    13,   248,   182,   245,    -1,
     128,   248,   117,   245,    -1,   129,   248,   254,   245,    -1,
     165,   247,   554,   246,   245,    -1,   554,   555,    -1,   555,
      -1,   556,    -1,   557,    -1,   559,    -1,   561,    -1,   560,
      -1,   558,    -1,   562,    -1,     1,    -1,    53,   248,   182,
     245,    -1,    71,   248,   182,   245,    -1,    68,   248,   138,
     245,    -1,    88,   248,   254,   245,    -1,    66,   248,   182,
     245,    -1,    40,   248,   182,   245,    -1,    70,   248,   182,
     245,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   380,   380,   381,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   410,   410,   411,
     415,   419,   423,   427,   431,   437,   437,   438,   439,   440,
     441,   448,   451,   451,   452,   452,   452,   454,   460,   467,
     469,   469,   470,   470,   471,   471,   472,   472,   473,   474,
     474,   475,   475,   476,   477,   481,   480,   499,   499,   500,
     506,   514,   548,   608,   623,   638,   647,   661,   670,   698,
     728,   751,   760,   762,   762,   763,   763,   764,   764,   766,
     775,   784,   796,   797,   797,   799,   799,   799,   800,   802,
     808,   815,   815,   825,   826,   828,   828,   829,   829,   831,
     836,   842,   841,   847,   847,   848,   852,   856,   860,   864,
     868,   872,   883,   882,   976,   976,   977,   977,   978,   978,
     978,   979,   979,   979,   980,   980,   980,   982,   994,  1006,
    1040,  1052,  1063,  1105,  1115,  1114,  1120,  1120,  1121,  1125,
    1129,  1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,
    1169,  1173,  1177,  1181,  1185,  1189,  1193,  1200,  1199,  1205,
    1205,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,  1285,
    1284,  1334,  1334,  1336,  1336,  1337,  1338,  1338,  1339,  1340,
    1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1351,
    1360,  1369,  1375,  1381,  1387,  1393,  1399,  1405,  1411,  1417,
    1423,  1429,  1435,  1445,  1444,  1461,  1460,  1465,  1465,  1466,
    1470,  1474,  1482,  1482,  1483,  1483,  1483,  1483,  1483,  1485,
    1485,  1487,  1487,  1489,  1503,  1523,  1532,  1545,  1544,  1613,
    1613,  1614,  1614,  1614,  1614,  1615,  1615,  1615,  1616,  1616,
    1618,  1655,  1668,  1677,  1689,  1688,  1692,  1692,  1693,  1697,
    1701,  1705,  1709,  1713,  1717,  1721,  1725,  1732,  1751,  1761,
    1775,  1774,  1790,  1790,  1791,  1791,  1791,  1791,  1793,  1802,
    1817,  1830,  1832,  1832,  1833,  1833,  1835,  1851,  1850,  1866,
    1866,  1867,  1867,  1867,  1867,  1869,  1878,  1901,  1900,  1906,
    1906,  1907,  1911,  1915,  1919,  1923,  1927,  1931,  1935,  1939,
    1943,  1947,  1957,  1956,  1973,  1973,  1974,  1974,  1974,  1976,
    1983,  1982,  1988,  1988,  1989,  1993,  1997,  2001,  2005,  2009,
    2013,  2017,  2021,  2025,  2029,  2039,  2038,  2184,  2184,  2185,
    2185,  2186,  2186,  2186,  2187,  2187,  2188,  2188,  2189,  2189,
    2189,  2190,  2190,  2191,  2191,  2192,  2194,  2206,  2218,  2227,
    2253,  2271,  2289,  2295,  2299,  2308,  2307,  2311,  2311,  2312,
    2322,  2326,  2330,  2334,  2340,  2381,  2392,  2405,  2418,  2427,
    2463,  2462,  2526,  2525,  2529,  2529,  2530,  2536,  2536,  2537,
    2537,  2537,  2537,  2539,  2558,  2568,  2567,  2590,  2590,  2591,
    2591,  2591,  2593,  2599,  2608,  2610,  2610,  2611,  2611,  2613,
    2632,  2631,  2679,  2678,  2682,  2682,  2683,  2689,  2689,  2690,
    2690,  2690,  2690,  2692,  2698,  2707,  2710,  2710,  2711,  2711,
    2712,  2712,  2713,  2713,  2714,  2714,  2715,  2715,  2716,  2716,
    2717,  2717,  2718,  2718,  2719,  2719,  2720,  2720,  2721,  2721,
    2722,  2722,  2723,  2723,  2724,  2725,  2725,  2726,  2726,  2727,
    2727,  2728,  2728,  2729,  2729,  2730,  2730,  2731,  2732,  2732,
    2733,  2733,  2734,  2735,  2735,  2736,  2736,  2737,  2737,  2738,
    2738,  2739,  2739,  2740,  2743,  2748,  2753,  2758,  2763,  2768,
    2773,  2778,  2783,  2788,  2793,  2798,  2803,  2808,  2813,  2818,
    2823,  2828,  2833,  2839,  2850,  2855,  2864,  2869,  2874,  2879,
    2884,  2889,  2892,  2897,  2900,  2905,  2910,  2915,  2920,  2925,
    2930,  2935,  2940,  2945,  2956,  2961,  2966,  2975,  3007,  3025,
    3030,  3039,  3048,  3053,  3058,  3064,  3063,  3068,  3068,  3069,
    3072,  3075,  3078,  3081,  3084,  3087,  3090,  3093,  3096,  3099,
    3102,  3105,  3108,  3111,  3114,  3117,  3120,  3123,  3129,  3128,
    3133,  3133,  3134,  3137,  3140,  3143,  3146,  3149,  3152,  3155,
    3158,  3161,  3164,  3167,  3170,  3173,  3176,  3179,  3182,  3185,
    3188,  3193,  3198,  3203,  3208,  3218,  3217,  3241,  3241,  3242,
    3243,  3244,  3245,  3246,  3247,  3248,  3250,  3256,  3263,  3262,
    3267,  3267,  3268,  3272,  3278,  3312,  3322,  3321,  3371,  3371,
    3372,  3376,  3385,  3388,  3388,  3389,  3389,  3390,  3390,  3391,
    3391,  3392,  3392,  3393,  3393,  3394,  3395,  3395,  3396,  3396,
    3397,  3397,  3398,  3398,  3400,  3405,  3410,  3415,  3420,  3425,
    3430,  3435,  3440,  3445,  3450,  3455,  3460,  3465,  3470,  3475,
    3480,  3485,  3493,  3496,  3496,  3497,  3497,  3498,  3499,  3500,
    3500,  3501,  3502,  3504,  3510,  3516,  3525,  3539,  3545,  3551
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
  "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINES",
  "GLINE_EXEMPT", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
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
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "T_SSL_CONNECTION_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "SERVLINK_PATH", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF",
  "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVER", "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS", "T_WALLOP",
  "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "T_TIMESTAMP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'",
  "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item",
  "serverinfo_ssl_connection_method", "$@1", "method_types",
  "method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_use_logging",
  "logging_timestamp", "logging_file_entry", "$@2", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@3", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@4", "oper_name_b",
  "oper_items", "oper_item", "oper_name", "oper_name_t", "oper_user",
  "oper_password", "oper_encrypted", "oper_rsa_public_key_file",
  "oper_class", "oper_umodes", "$@5", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@6", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@7", "class_name_b", "class_items",
  "class_item", "class_name", "class_name_t", "class_ping_time",
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
  "connect_name_b", "connect_items", "connect_item", "connect_name",
  "connect_name_t", "connect_host", "connect_vhost",
  "connect_send_password", "connect_accept_password", "connect_port",
  "connect_aftype", "connect_flags", "$@19", "connect_flags_items",
  "connect_flags_item", "connect_rsa_public_key_file", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "$@20", "kill_type", "$@21",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@22", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@23", "gecos_flags", "$@24",
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
     495,   496,   497,   498,   499,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   250,   251,   251,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   253,   253,   254,
     254,   254,   254,   254,   254,   255,   255,   256,   256,   256,
     256,   257,   258,   258,   259,   259,   259,   260,   261,   262,
     263,   263,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   266,   265,   267,   267,   268,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   281,   282,   282,   282,   282,   283,
     284,   285,   286,   287,   287,   288,   288,   288,   288,   289,
     290,   292,   291,   293,   293,   294,   294,   294,   294,   295,
     296,   298,   297,   299,   299,   300,   300,   300,   300,   300,
     300,   300,   302,   301,   303,   303,   304,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   307,   308,
     309,   310,   311,   312,   314,   313,   315,   315,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   318,   317,   319,
     319,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   322,
     321,   323,   323,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   341,   340,   343,   342,   344,   344,   345,
     345,   345,   346,   346,   347,   347,   347,   347,   347,   349,
     348,   350,   350,   351,   351,   352,   353,   355,   354,   356,
     356,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     358,   359,   360,   361,   363,   362,   364,   364,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   366,   367,   368,
     370,   369,   371,   371,   372,   372,   372,   372,   373,   374,
     375,   376,   377,   377,   378,   378,   379,   381,   380,   382,
     382,   383,   383,   383,   383,   384,   385,   387,   386,   388,
     388,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   391,   390,   392,   392,   393,   393,   393,   394,
     396,   395,   397,   397,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   400,   399,   401,   401,   402,
     402,   403,   403,   403,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   411,   413,   412,   414,   414,   415,
     415,   415,   415,   415,   416,   417,   418,   419,   420,   421,
     423,   422,   425,   424,   426,   426,   427,   428,   428,   429,
     429,   429,   429,   430,   431,   433,   432,   434,   434,   435,
     435,   435,   436,   437,   438,   439,   439,   440,   440,   441,
     443,   442,   445,   444,   446,   446,   447,   448,   448,   449,
     449,   449,   449,   450,   451,   452,   453,   453,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   482,   483,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   505,   504,   506,   506,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   509,   508,
     510,   510,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   512,   513,   514,   515,   517,   516,   518,   518,   519,
     519,   519,   519,   519,   519,   519,   520,   521,   523,   522,
     524,   524,   525,   525,   526,   527,   529,   528,   530,   530,
     531,   531,   532,   533,   533,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   552,   553,   554,   554,   555,   555,   555,   555,   555,
     555,   555,   555,   556,   557,   558,   559,   560,   561,   562
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
       4,     4,     5,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     7,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     4,     4,     0,     5,     3,     1,
       1,     1,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   189,   345,   405,     0,
     420,     0,   595,   247,   390,   223,     0,     0,   122,   280,
       0,     0,   297,   322,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   191,   347,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   643,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   624,
     642,   637,   625,   626,   627,   628,   630,   631,   632,   633,
     629,   634,   635,   636,   638,   639,   640,   641,   210,     0,
     192,   367,     0,   348,     0,   418,     0,     0,   416,   417,
       0,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,     0,   545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   437,   491,
     486,   487,   484,   488,   489,   485,   448,   438,   439,   476,
     440,   441,   442,   443,   444,   445,   446,   447,   481,   449,
     450,   451,   452,   490,   454,   459,   455,   457,   456,   470,
     471,   458,   460,   461,   462,   463,   464,   453,   466,   475,
     477,   478,   467,   468,   492,   482,   483,   480,   469,   465,
     473,   474,   472,   479,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,     0,     0,     0,     0,
       0,    43,    44,    45,   138,     0,   125,     0,   672,     0,
       0,     0,     0,     0,     0,     0,     0,   664,   665,   666,
     670,   667,   669,   668,   671,     0,     0,     0,     0,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,    51,
      63,    62,    59,    52,    61,    55,    56,    57,    53,    60,
      58,    54,     0,     0,   295,     0,     0,   293,   294,    88,
       0,     0,     0,     0,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   623,     0,     0,   411,     0,     0,
       0,   408,   409,   410,     0,     0,   415,   432,     0,     0,
     422,   431,     0,   428,   429,   430,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   436,   605,   616,     0,     0,   608,     0,     0,
       0,   598,   599,   600,   601,   602,   603,   604,     0,     0,
       0,   264,     0,     0,     0,     0,     0,     0,   250,   251,
     252,   253,   258,   254,   255,   256,   257,   402,     0,   392,
       0,   401,     0,   398,   399,   400,     0,   225,     0,     0,
       0,   235,     0,   233,   234,   236,   237,    98,     0,     0,
       0,    93,     0,    46,     0,     0,     0,    42,     0,     0,
       0,     0,     0,     0,   283,   284,   285,   286,     0,     0,
       0,     0,     0,     0,     0,     0,   663,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,     0,   307,     0,     0,   300,   301,   302,
     303,     0,     0,   330,     0,   325,   326,   327,     0,     0,
     292,     0,     0,     0,    82,     0,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   195,   198,   199,   201,   202,   203,   204,   205,   206,
     207,   196,   197,   200,     0,     0,     0,     0,     0,     0,
     375,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     350,   351,   352,   353,   354,   355,   357,   356,   358,   363,
     362,   359,   360,   361,   364,     0,     0,     0,   407,     0,
     414,     0,     0,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,   435,     0,     0,     0,     0,     0,
       0,     0,   597,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,   397,   238,
       0,     0,     0,     0,     0,   232,     0,     0,    92,     0,
       0,     0,    41,     0,     0,     0,   167,     0,     0,     0,
     144,     0,     0,   127,   128,   129,   130,   133,   134,   132,
     131,   135,   287,     0,     0,     0,     0,   282,     0,     0,
       0,     0,     0,     0,     0,   662,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,   304,
       0,     0,     0,     0,   299,   328,     0,     0,     0,   324,
       0,   291,    91,    90,    89,   659,   656,   655,   644,   646,
      27,    27,    27,    27,    27,    29,    28,   650,   651,   654,
     652,   657,   658,   660,   661,   653,   645,   647,   648,   649,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,   365,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,   406,   419,     0,     0,     0,
     421,   506,   510,   497,   526,   538,   537,   593,   543,   504,
     534,   540,   505,   495,   496,   513,   502,   503,   516,   501,
     515,   514,   509,   508,   507,   535,   494,   533,   591,   592,
     530,   527,   572,   588,   589,   573,   574,   575,   576,   583,
     577,   586,   590,   579,   584,   580,   585,   578,   582,   581,
     587,     0,   571,   532,   549,   565,   566,   550,   551,   552,
     553,   560,   554,   563,   567,   556,   561,   557,   562,   555,
     559,   558,   564,     0,   548,   525,   528,   542,   499,   536,
     500,   529,   518,   523,   524,   521,   522,   519,   520,   512,
     511,    35,    35,    35,    37,    36,   594,   541,   544,   531,
     539,   498,   517,     0,     0,     0,     0,     0,     0,   596,
       0,     0,     0,     0,     0,     0,     0,     0,   248,     0,
       0,     0,   391,     0,     0,     0,   243,   239,   242,   224,
     100,    99,     0,     0,   111,     0,     0,   104,   105,   107,
     106,    47,    48,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,   281,   678,   673,
     677,   675,   679,   674,   676,    75,    81,    73,    77,    76,
      72,    71,    69,    70,     0,    68,    74,    80,    78,    79,
       0,     0,     0,   298,     0,     0,   323,   296,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   346,   412,   413,   433,   434,   426,     0,   425,
     569,     0,   546,     0,    38,    39,    40,   621,   620,     0,
     619,   607,   606,   613,   612,     0,   611,   615,   614,   262,
     263,   272,   269,   274,   271,   270,   276,   273,   275,   268,
       0,   267,   261,   279,   278,   277,   260,   404,   396,     0,
     395,   403,   230,   231,   229,     0,   228,   246,   245,     0,
       0,     0,   108,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   289,   290,   288,
      66,     0,   305,   311,   317,   321,   320,   319,   316,   312,
     315,   318,   313,   314,     0,   310,   306,   329,   334,   340,
     344,   343,   342,   339,   335,   338,   341,   336,   337,     0,
     333,   220,   221,   214,   216,   218,   217,   215,   209,   222,
     213,   211,   212,   219,   371,   373,   374,   389,   388,   385,
     381,   382,   379,   380,   383,     0,   378,   368,   386,   387,
     366,   372,   384,   370,   369,   423,     0,   570,   547,   617,
       0,   609,     0,   265,     0,   393,     0,   226,     0,   244,
     241,   240,     0,     0,     0,   102,   143,   141,   180,   177,
     176,   171,   181,   186,   173,   188,   182,   185,   179,   172,
     187,   183,   184,   178,   174,   175,     0,   170,   137,   140,
     142,   148,   164,   165,   149,   150,   151,   152,   159,   153,
     162,   166,   155,   160,   156,   161,   154,   158,   157,   163,
       0,   147,   139,    67,   308,     0,   331,     0,   376,     0,
     424,   618,   610,   266,   394,   227,   109,   117,   120,   119,
     116,   121,   118,   115,     0,   114,   110,   168,     0,   145,
       0,   309,   332,   377,   112,     0,   169,   146,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   805,   806,   954,   955,    26,   260,   261,
     262,   263,    27,   298,   299,   300,   515,  1034,  1035,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
      28,    74,    75,    76,    77,    78,    29,   251,   252,   253,
     254,   255,   256,   996,   997,   998,   999,  1000,  1144,  1314,
    1315,    30,    63,   265,   742,   743,   744,   266,   745,   746,
     747,   748,   749,   750,  1010,  1290,  1291,   751,  1006,  1266,
    1267,    31,    51,   119,   579,   580,   581,   120,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
      32,    60,   471,   720,  1135,  1136,   472,   473,   474,  1141,
     987,   988,   475,   476,    33,    58,   447,   448,   449,   450,
     451,   452,   453,   706,  1120,  1121,   454,   455,   456,    34,
      64,   493,   494,   495,   496,   497,    35,   316,   317,   318,
      36,    67,   526,   527,   528,   529,   530,   781,  1174,  1175,
      37,    68,   534,   535,   536,   537,   787,  1189,  1190,    38,
      52,   122,   609,   610,   611,   123,   612,   613,   614,   615,
     616,   617,   618,   842,  1215,  1216,   619,   620,   621,   622,
     623,   624,    39,    59,   461,   715,  1129,  1130,   462,   463,
     464,   465,    40,    53,   350,   351,   352,   353,    41,   127,
     128,   129,    42,    55,   361,   633,  1088,  1089,   362,   363,
     364,   365,    43,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   399,   933,   934,   239,   397,
     911,   912,   240,   241,   242,   243,    44,    57,   430,   431,
     432,   433,   434,   698,  1105,  1106,   435,   436,   437,   695,
    1099,  1100,    45,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,    46,   276,   277,   278,   279,   280,   281,
     282,   283,   284
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -652
static const yytype_int16 yypact[] =
{
    -652,   657,  -652,  -187,  -242,  -235,  -652,  -652,  -652,  -225,
    -652,  -219,  -652,  -652,  -652,  -652,  -216,  -214,  -652,  -652,
    -208,  -202,  -652,  -652,  -196,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   168,
     604,   -71,   -65,  -171,    15,  -156,   384,  -149,  -133,   -94,
     -93,    67,    29,    22,   -86,   519,   427,   -54,   -28,     8,
     -69,   -39,   -22,   -20,    18,  -652,  -652,  -652,  -652,  -652,
     -13,   -12,    -5,    -4,    11,    20,    44,    70,    75,    78,
      81,    89,   100,   118,   135,   139,   143,   149,   110,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,    -6,
    -652,  -652,    23,  -652,    19,  -652,   150,    43,  -652,  -652,
      33,  -652,   151,   152,   162,   164,   165,   166,   169,   173,
     177,   182,   184,   189,   190,   191,   192,   195,   198,   202,
     203,   204,   205,   206,   210,   214,   218,   222,   223,   225,
     226,   229,   232,  -652,   235,  -652,   241,   243,   245,   250,
     252,   262,   264,   265,   268,   269,   273,   277,   278,   279,
     280,   282,   283,   284,   285,   290,   294,     5,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   432,   471,    68,   311,   105,   295,
     296,     9,  -652,  -652,  -652,  -652,    49,   114,   297,   298,
      14,  -652,  -652,  -652,  -652,   157,  -652,   167,  -652,   299,
     301,   302,   304,   307,   308,   312,   251,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   212,   318,   325,   326,   328,
     334,   335,   336,  -652,   340,   343,   345,   346,   156,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,    45,    17,  -652,   348,    34,  -652,  -652,  -652,
     357,   433,   437,   353,  -652,   133,   483,   484,   420,   422,
     492,   492,   497,   498,   436,   438,   502,   492,   440,   441,
     442,   443,   445,   383,  -652,   646,   417,  -652,   381,   382,
      40,  -652,  -652,  -652,   493,   388,  -652,  -652,   386,   391,
    -652,  -652,   155,  -652,  -652,  -652,   454,   492,   458,   492,
     524,   506,   532,   468,   469,   536,   516,   477,   543,   544,
     547,   485,   488,   489,   492,   534,   491,   562,   563,   492,
     564,   566,   546,   569,   570,   509,   511,   446,   513,   450,
     492,   492,   517,   492,   550,   518,   521,   522,  -104,   -82,
     523,   526,   492,   492,   584,   568,   492,   527,   528,   531,
     533,   474,  -652,  -652,  -652,   473,   476,  -652,   478,   480,
      48,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   490,   482,
     486,  -652,   496,   501,   503,   508,   514,    79,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   520,  -652,
     529,  -652,    25,  -652,  -652,  -652,   494,  -652,   537,   538,
     541,  -652,    85,  -652,  -652,  -652,  -652,  -652,   540,   556,
     512,  -652,   507,  -652,   578,   587,   535,  -652,   327,   545,
     554,   555,   557,     2,  -652,  -652,  -652,  -652,   579,   582,
     590,   631,   592,   594,   492,   548,  -652,  -652,   640,   610,
     666,   668,   670,   672,   674,   572,   676,   698,   678,   680,
     574,  -652,   576,   581,  -652,   583,   109,  -652,  -652,  -652,
    -652,   585,   586,  -652,    41,  -652,  -652,  -652,   686,   588,
    -652,   591,   595,   601,  -652,   605,   609,   612,   616,   620,
     247,   623,   624,   625,   627,   628,   629,   630,   632,   634,
     643,   644,   648,   649,  -652,   651,   607,   656,   659,   660,
     661,   671,   677,   679,   683,   687,   688,   690,   692,   178,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   655,   694,   695,   696,   697,   699,
    -652,   700,   701,   702,   703,   704,   705,   706,   707,   209,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   711,   738,   675,  -652,   712,
    -652,   767,   778,   708,   713,  -652,   714,   715,   716,   717,
     718,   719,   720,   721,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   739,
     740,   741,   742,   743,   744,   745,   746,   652,   747,   691,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,    47,   764,   765,   766,
     768,   769,   770,   771,  -652,   772,   492,   650,   773,   786,
     801,   774,  -652,  -652,   808,   653,   775,   829,   866,   874,
     879,   880,   777,  -652,   886,   779,   887,   781,  -652,  -652,
     780,   891,   892,   914,   787,  -652,   788,   789,  -652,    26,
     790,   791,  -652,   792,   793,   794,  -652,   795,   796,   797,
    -652,   798,    74,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,   900,   901,   902,   802,  -652,   803,   804,
     805,   806,   807,   809,   810,  -652,   811,   812,   813,   814,
     815,   816,   817,   -38,   818,   819,   820,   821,  -652,  -652,
     915,   822,   929,   823,  -652,  -652,   931,   824,   826,  -652,
     828,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
     492,   492,   492,   492,   492,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,   957,   958,   492,   959,   960,   961,   962,   942,   964,
     965,   492,   492,   584,   838,  -652,  -652,   946,   -57,   947,
     948,   905,   840,   951,   952,   953,   954,   976,   956,   963,
     966,   850,  -652,   851,   852,  -652,  -652,   853,   854,   124,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -238,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -220,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,   584,   584,   584,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,    -7,   855,   857,    10,   858,   860,  -652,
     861,   862,   709,   863,   864,   865,   867,   868,  -652,   869,
     968,   870,  -652,   121,   871,   872,   639,   873,  -652,  -652,
    -652,  -652,   875,   876,  -652,   877,   111,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   980,   937,   878,   983,   985,   989,
     881,   990,   885,  -652,   888,   889,   890,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -192,  -652,  -652,  -652,  -652,  -652,
     893,   567,   894,  -652,   895,   571,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,   896,   897,   898,   899,   903,   904,   906,
     907,   908,   909,   910,   911,   912,  -652,   913,   916,   917,
     918,   919,   920,   323,   921,   922,   923,   924,   925,   926,
     927,   928,  -652,  -652,  -652,  -652,  -652,  -652,  -155,  -652,
    -652,   652,  -652,   691,  -652,  -652,  -652,  -652,  -652,   -79,
    -652,  -652,  -652,  -652,  -652,   -78,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
       1,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,    87,
    -652,  -652,  -652,  -652,  -652,    93,  -652,  -652,  -652,  1014,
     914,   930,  -652,   994,   932,   584,   933,  -652,   934,   936,
     530,   938,   939,   940,   722,   941,  -652,  -652,  -652,  -652,
    -652,   -38,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   102,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   113,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   129,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,   124,  -652,  -652,  -652,
      -7,  -652,    10,  -652,   709,  -652,   968,  -652,   121,  -652,
    -652,  -652,   943,   309,   944,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,   131,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
     132,  -652,  -652,  -652,  -652,   567,  -652,   571,  -652,   323,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,   137,  -652,  -652,  -652,   530,  -652,
     722,  -652,  -652,  -652,  -652,   309,  -652,  -652,  -652
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -652,  -652,  -652,  -432,  -329,  -651,  -414,  -652,  -652,   935,
    -652,  -652,  -652,  -652,   839,  -652,  -652,  -652,   -25,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  1071,  -652,  -652,  -652,  -652,  -652,   945,  -652,
    -652,  -652,  -652,  -652,   154,  -652,  -652,  -652,  -652,  -652,
    -179,  -652,  -652,  -652,  -652,   405,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -161,  -652,  -652,  -652,
    -158,  -652,  -652,  -652,  -652,   597,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   -64,  -652,   710,  -652,  -652,
    -652,    37,  -652,  -652,  -652,  -652,  -652,   776,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   -47,  -652,  -652,  -652,  -652,
    -652,  -652,   782,  -652,  -652,  -652,  -652,  -652,   882,  -652,
    -652,  -652,  -652,   664,  -652,  -652,  -652,  -652,  -652,  -103,
    -652,  -652,  -652,   663,  -652,  -652,  -652,  -652,  -106,  -652,
    -652,  -652,  -652,   593,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -105,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,   -43,  -652,   783,
    -652,  -652,  -652,  -652,  -652,   849,  -652,  -652,  -652,  -652,
    1073,  -652,  -652,  -652,  -652,  -652,  -652,   -23,  -652,   842,
    -652,  -652,  -652,  -652,  1018,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,   108,  -652,  -652,
    -652,   115,  -652,  -652,  -652,  -652,  -652,  -652,  -652,   784,
    -652,  -652,  -652,  -652,  -652,   -24,  -652,  -652,  -652,  -652,
    -652,   -21,  -652,  -652,  1109,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,  -652,
    -652,  -652,  -652,  -652,  -652,   949,  -652,  -652,  -652,  -652,
    -652,  -652,  -652
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     687,   551,   552,   489,  1097,    49,   131,  1090,   558,   314,
     248,  1091,    50,   132,   133,   257,   125,   134,   531,    70,
     347,  1103,    54,   490,   135,  1092,   457,   992,    56,  1093,
     257,    61,   136,    62,   357,   314,   137,   138,   637,    65,
     639,   347,   531,   139,   125,    66,   522,   140,   141,   423,
     142,    69,   424,  1160,    71,   654,   143,  1161,    47,    48,
     659,   951,   952,   953,    72,   144,   145,   118,   248,   457,
     146,   670,   671,   121,   673,   733,   124,   147,   678,   679,
     438,   148,   149,   684,   685,   150,   466,   689,   151,   152,
    1225,   130,   425,   126,  1226,   426,   153,   348,   244,   734,
     680,   681,   154,   155,   439,   156,   157,   158,   159,   160,
     522,    79,   992,   491,   245,   315,  1032,  1033,   348,   258,
     161,   126,   735,    80,   532,    73,   736,   440,   162,   163,
     164,   441,   165,   993,   258,   166,   167,   467,   427,   168,
     358,   315,   492,    81,    82,  1068,  1069,   259,   532,    83,
     169,    84,   523,   246,   247,   428,   357,   285,   468,   349,
     264,   267,   259,   469,   686,   458,  1229,  1231,   489,    70,
    1230,  1232,   170,   359,   171,   764,   319,  1098,   172,   565,
     349,   737,   173,   174,   175,   176,   177,  1132,   490,   533,
     178,   179,   286,   312,  1104,    85,    86,   459,   994,   180,
     566,   567,    87,    88,    71,   360,   738,   568,   458,   320,
     594,   442,   595,   533,    72,   596,   523,   524,   993,   313,
     443,   444,   470,    89,    90,   739,   321,   181,   322,   182,
     287,   183,   249,   597,   598,   325,   326,   184,    91,    92,
     459,   345,   185,   327,   328,   250,  1233,   186,   756,    93,
    1234,   421,   268,  -101,   445,   480,   460,   599,    94,   329,
     486,   600,   358,   288,   323,   289,   290,  1087,   330,   995,
     346,   717,   569,   570,   571,    73,   525,   572,   491,   429,
     539,   524,   601,   994,   602,   573,   627,   788,   740,   355,
     249,   269,   331,   482,   701,   359,   603,   574,   575,   460,
    1094,  1095,  1096,   250,   270,   741,   291,   492,   292,   293,
     446,  -101,   466,   576,   577,   545,   604,   271,   332,   272,
    1012,   273,   274,   333,   294,   712,   334,   360,   733,   335,
    1133,   724,  1235,  1210,  1134,  1211,  1236,   336,  1237,   275,
     525,   578,  1238,    95,    96,    97,   605,  1294,   337,  1212,
     477,  1295,   734,  1213,   995,   783,   343,  1146,  1296,   483,
     606,   295,  1297,   467,   550,  1307,   338,   964,  1048,  1049,
    1050,  1051,  1052,   607,  1298,   735,  1317,  1319,  1299,   736,
    1318,  1320,  1324,   339,   468,   131,  1325,   340,  1308,   469,
    1309,   341,   132,   133,   296,   297,   134,   342,   354,   366,
     367,   634,   520,   135,   488,   800,   801,   802,   803,   804,
     368,   136,   369,   370,   371,   137,   138,   372,   594,  1065,
     595,   373,   139,   596,   834,   374,   140,   141,   285,   142,
     375,  1310,   376,   423,   737,   143,   424,   377,   378,   379,
     380,   597,   598,   381,   144,   145,   382,   608,   470,   146,
     383,   384,   385,   386,   387,   851,   147,   507,   388,   738,
     148,   149,   389,   286,   150,   599,   390,   151,   152,   600,
     391,   392,   438,   393,   394,   153,   425,   395,   739,   426,
     396,   154,   155,   398,   156,   157,   158,   159,   160,   400,
     601,   401,   602,   402,  1055,   541,   439,   505,   403,   161,
     404,   287,  1063,  1064,   603,  1311,  1312,   162,   163,   164,
     405,   165,   406,   407,   166,   167,   408,   409,   168,   440,
     268,   410,   427,   441,   604,   411,   412,   413,   414,   169,
     415,   416,   417,   418,   288,  1248,   289,   290,   419,   428,
    1313,   740,   420,   478,   479,   484,   485,   498,  1214,   499,
     500,   170,   501,   171,   605,   502,   503,   172,   741,   269,
     504,   173,   174,   175,   176,   177,   508,  1249,   606,   178,
     179,   542,   270,   509,   510,   543,   511,   291,   180,   292,
     293,   607,   512,   513,   514,   271,  1250,   272,   516,   273,
     274,   517,  1251,   518,   519,   294,   538,  1252,   544,  1253,
     546,   547,   548,   442,   549,    79,   181,   275,   182,   550,
     183,  1254,   443,   444,   553,   554,   184,    80,   555,   557,
     556,   185,   559,   560,   561,   562,   186,   563,   564,   625,
     626,   629,   295,   630,   631,  1255,   636,    81,    82,   632,
     638,   640,  1256,    83,   641,    84,   445,   565,  1163,   642,
     643,   644,  1178,   645,   646,   608,  1257,     2,     3,   647,
     648,   649,     4,   429,   650,   296,   297,   651,   566,   567,
     652,   653,   655,   656,  1258,   568,  1259,  1260,     5,   657,
     658,   660,     6,   661,   662,     7,   663,   664,   674,    85,
      86,   665,     8,   666,   667,   668,    87,    88,   669,   672,
     675,   686,   446,   676,   677,   682,   688,     9,   683,   690,
     691,    10,    11,   692,    12,   693,   730,    89,    90,   694,
      13,   696,   726,  1164,   697,   731,   699,  1179,   700,  1111,
     704,  1244,    91,    92,   705,   703,    14,  1261,   727,   719,
     569,   570,   571,    93,   707,   572,    15,    16,  1262,   708,
    1263,   709,    94,   573,   729,  1165,   710,   728,  1112,  1180,
    1264,   758,   711,    17,   759,   574,   575,  1113,   714,   761,
    1265,  1166,   760,  1114,   762,  1181,   763,   716,   766,    18,
     732,   576,   577,  1167,  1168,   721,   722,  1182,  1183,   723,
     752,  1115,   767,   765,  1169,  1170,  1171,  1172,  1184,  1185,
    1186,  1187,   753,   754,   768,   755,   769,  1173,   770,   578,
     771,  1188,   772,    19,   774,   775,   776,  1116,   777,   778,
     773,   779,    20,    21,   790,  1117,  1139,    22,    23,   780,
     785,   782,   965,   791,   786,   971,   792,    95,    96,    97,
     793,   892,   893,   894,   895,   896,   794,   897,   898,   853,
     795,   899,   900,   901,   796,   821,   902,   797,   903,   904,
     905,   798,   906,   907,   908,   799,  1118,   909,   807,   808,
     809,   910,   810,   811,   812,   813,   854,   814,    24,   815,
     914,   915,   916,   917,   918,  1119,   919,   920,   816,   817,
     921,   922,   923,   818,   819,   924,   820,   925,   926,   927,
     836,   928,   929,   930,   822,   857,   931,   823,   824,   825,
     932,  1271,  1272,  1273,  1274,  1275,   858,  1276,  1277,   826,
     855,  1278,  1279,  1280,   967,   827,  1281,   828,  1282,  1283,
    1284,   829,  1285,  1286,  1287,   830,   831,  1288,   832,   968,
     833,  1289,   837,   838,   839,   840,   970,   841,   843,   844,
     845,   846,   847,   848,   849,   850,   859,   856,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   973,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   883,   974,   884,   885,   886,   887,   888,   889,
     890,   891,   913,   935,   936,   937,   938,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   956,
     957,   958,   975,   959,   960,   961,   962,   976,   977,   969,
     963,   966,   978,   972,   979,   981,   982,   980,   983,   984,
     985,   986,   989,   990,   991,  1001,  1002,  1003,  1014,  1015,
    1016,  1004,  1005,  1007,  1008,  1009,  1011,  1017,  1018,  1019,
    1020,  1021,  1022,  1040,  1023,  1024,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1036,  1037,  1038,  1039,  1042,  1043,  1044,
    1041,  1046,  1045,  1047,  1053,  1054,  1056,  1057,  1058,  1059,
    1060,  1061,  1062,  1066,  1067,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1082,  1083,  1084,  1085,  1086,
    1101,  1080,  1102,  1107,  1081,  1108,  1109,  1110,  1122,  1123,
    1124,  1128,  1125,  1126,  1127,  1131,  1137,  1138,  1148,  1149,
    1142,  1151,  1140,  1152,  1143,  1145,  1150,  1153,  1155,  1154,
    1156,  1239,  1242,  1157,  1158,  1159,  1293,   521,  1162,  1176,
    1177,  1191,  1192,  1193,  1194,   324,  1328,  1013,  1195,  1196,
    1147,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1327,
    1326,  1205,  1206,  1207,  1208,  1209,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1305,  1241,   835,  1240,  1245,  1246,
    1243,  1247,   725,  1268,  1269,  1270,  1292,  1303,  1306,  1316,
     784,  1322,  1321,  1304,  1323,   487,   481,   789,   540,   628,
     356,  1228,   852,  1300,   635,   422,  1227,   344,  1302,  1301,
       0,     0,     0,     0,   702,     0,     0,     0,     0,     0,
       0,     0,     0,   713,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   718,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   757
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-652))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     414,   330,   331,     1,    11,   247,     1,   245,   337,     1,
       1,   249,   247,     8,     9,     1,     1,    12,     1,     1,
       1,    11,   247,    21,    19,   245,     1,     1,   247,   249,
       1,   247,    27,   247,     1,     1,    31,    32,   367,   247,
     369,     1,     1,    38,     1,   247,     1,    42,    43,     1,
      45,   247,     4,   245,    36,   384,    51,   249,   245,   246,
     389,    14,    15,    16,    46,    60,    61,   138,     1,     1,
      65,   400,   401,   138,   403,     1,   247,    72,   182,   183,
       1,    76,    77,   412,   413,    80,     1,   416,    83,    84,
     245,   247,    44,    78,   249,    47,    91,    78,   247,    25,
     182,   183,    97,    98,    25,   100,   101,   102,   103,   104,
       1,     1,     1,   111,   247,   107,   154,   155,    78,   105,
     115,    78,    48,    13,   107,   107,    52,    48,   123,   124,
     125,    52,   127,   107,   105,   130,   131,    52,    90,   134,
     107,   107,   140,    33,    34,   202,   203,   133,   107,    39,
     145,    41,   107,   247,   247,   107,     1,     1,    73,   140,
     138,   247,   133,    78,   117,   140,   245,   245,     1,     1,
     249,   249,   167,   140,   169,   504,   245,   184,   173,     1,
     140,   107,   177,   178,   179,   180,   181,    66,    21,   172,
     185,   186,    36,   247,   184,    85,    86,   172,   172,   194,
      22,    23,    92,    93,    36,   172,   132,    29,   140,   248,
       1,   132,     3,   172,    46,     6,   107,   172,   107,   247,
     141,   142,   137,   113,   114,   151,   248,   222,   248,   224,
      74,   226,   223,    24,    25,   248,   248,   232,   128,   129,
     172,   247,   237,   248,   248,   236,   245,   242,   246,   139,
     249,   246,     1,   244,   175,   246,   231,    48,   148,   248,
     246,    52,   107,   107,   246,   109,   110,   143,   248,   243,
     247,   246,    94,    95,    96,   107,   231,    99,   111,   231,
     246,   172,    73,   172,    75,   107,   246,   246,   214,   246,
     223,    40,   248,   244,   246,   140,    87,   119,   120,   231,
     951,   952,   953,   236,    53,   231,   150,   140,   152,   153,
     231,   244,     1,   135,   136,   182,   107,    66,   248,    68,
     246,    70,    71,   248,   168,   246,   248,   172,     1,   248,
     209,   246,   245,    10,   213,    12,   249,   248,   245,    88,
     231,   163,   249,   233,   234,   235,   137,   245,   248,    26,
     245,   249,    25,    30,   243,   246,   246,   246,   245,   245,
     151,   205,   249,    52,   117,    56,   248,   696,   800,   801,
     802,   803,   804,   164,   245,    48,   245,   245,   249,    52,
     249,   249,   245,   248,    73,     1,   249,   248,    79,    78,
      81,   248,     8,     9,   238,   239,    12,   248,   248,   248,
     248,   246,   246,    19,   247,   158,   159,   160,   161,   162,
     248,    27,   248,   248,   248,    31,    32,   248,     1,   833,
       3,   248,    38,     6,   246,   248,    42,    43,     1,    45,
     248,   122,   248,     1,   107,    51,     4,   248,   248,   248,
     248,    24,    25,   248,    60,    61,   248,   238,   137,    65,
     248,   248,   248,   248,   248,   246,    72,   245,   248,   132,
      76,    77,   248,    36,    80,    48,   248,    83,    84,    52,
     248,   248,     1,   248,   248,    91,    44,   248,   151,    47,
     248,    97,    98,   248,   100,   101,   102,   103,   104,   248,
      73,   248,    75,   248,   823,   138,    25,   246,   248,   115,
     248,    74,   831,   832,    87,   196,   197,   123,   124,   125,
     248,   127,   248,   248,   130,   131,   248,   248,   134,    48,
       1,   248,    90,    52,   107,   248,   248,   248,   248,   145,
     248,   248,   248,   248,   107,     5,   109,   110,   248,   107,
     231,   214,   248,   248,   248,   248,   248,   248,   225,   248,
     248,   167,   248,   169,   137,   248,   248,   173,   231,    40,
     248,   177,   178,   179,   180,   181,   248,    37,   151,   185,
     186,   138,    53,   248,   248,   138,   248,   150,   194,   152,
     153,   164,   248,   248,   248,    66,    56,    68,   248,    70,
      71,   248,    62,   248,   248,   168,   248,    67,   245,    69,
     117,   117,   182,   132,   182,     1,   222,    88,   224,   117,
     226,    81,   141,   142,   117,   117,   232,    13,   182,   117,
     182,   237,   182,   182,   182,   182,   242,   182,   245,   248,
     248,   138,   205,   245,   248,   105,   182,    33,    34,   248,
     182,   117,   112,    39,   138,    41,   175,     1,    81,   117,
     182,   182,    81,   117,   138,   238,   126,     0,     1,   182,
     117,   117,     5,   231,   117,   238,   239,   182,    22,    23,
     182,   182,   138,   182,   144,    29,   146,   147,    21,   117,
     117,   117,    25,   117,   138,    28,   117,   117,   138,    85,
      86,   182,    35,   182,   248,   182,    92,    93,   248,   182,
     182,   117,   231,   182,   182,   182,   138,    50,   182,   182,
     182,    54,    55,   182,    57,   182,   138,   113,   114,   245,
      63,   248,   182,   156,   248,   138,   248,   156,   248,    20,
     248,  1145,   128,   129,   248,   245,    79,   207,   182,   245,
      94,    95,    96,   139,   248,    99,    89,    90,   218,   248,
     220,   248,   148,   107,   247,   188,   248,   245,    49,   188,
     230,   182,   248,   106,   182,   119,   120,    58,   248,   138,
     240,   204,   182,    64,   182,   204,   182,   248,   138,   122,
     245,   135,   136,   216,   217,   248,   248,   216,   217,   248,
     245,    82,   182,   245,   227,   228,   229,   230,   227,   228,
     229,   230,   248,   248,   138,   248,   138,   240,   138,   163,
     138,   240,   138,   156,   138,   117,   138,   108,   138,   245,
     248,   245,   165,   166,   138,   116,   187,   170,   171,   248,
     245,   248,   182,   245,   248,   182,   245,   233,   234,   235,
     245,   189,   190,   191,   192,   193,   245,   195,   196,   138,
     245,   199,   200,   201,   245,   248,   204,   245,   206,   207,
     208,   245,   210,   211,   212,   245,   157,   215,   245,   245,
     245,   219,   245,   245,   245,   245,   138,   245,   221,   245,
     189,   190,   191,   192,   193,   176,   195,   196,   245,   245,
     199,   200,   201,   245,   245,   204,   245,   206,   207,   208,
     245,   210,   211,   212,   248,   138,   215,   248,   248,   248,
     219,   189,   190,   191,   192,   193,   138,   195,   196,   248,
     245,   199,   200,   201,   138,   248,   204,   248,   206,   207,
     208,   248,   210,   211,   212,   248,   248,   215,   248,   138,
     248,   219,   248,   248,   248,   248,   138,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   138,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   117,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   138,   245,   245,   245,   245,   138,   138,   245,
     248,   248,   245,   248,   138,   138,   245,   248,   248,   138,
     138,   117,   245,   245,   245,   245,   245,   245,   138,   138,
     138,   248,   248,   248,   248,   248,   248,   245,   245,   245,
     245,   245,   245,   138,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   138,   245,   138,
     248,   245,   248,   245,   117,   117,   117,   117,   117,   117,
     138,   117,   117,   245,   138,   138,   138,   182,   248,   138,
     138,   138,   138,   117,   138,   245,   245,   245,   245,   245,
     245,   138,   245,   245,   138,   245,   245,   245,   245,   245,
     245,   143,   245,   245,   245,   245,   245,   245,   138,   182,
     245,   138,   249,   138,   248,   248,   248,   138,   138,   248,
     245,   117,   138,   245,   245,   245,  1161,   298,   245,   245,
     245,   245,   245,   245,   245,    74,  1325,   742,   245,   245,
     996,   245,   245,   245,   245,   245,   245,   245,   245,  1320,
    1318,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,  1238,   245,   579,  1140,   245,   245,
     248,   245,   472,   245,   245,   245,   245,  1234,   245,   245,
     526,  1297,  1295,  1236,  1299,   260,   251,   534,   316,   350,
     127,  1093,   609,  1226,   362,   187,  1091,    98,  1232,  1230,
      -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   447,    -1,   276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   493
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   251,     0,     1,     5,    21,    25,    28,    35,    50,
      54,    55,    57,    63,    79,    89,    90,   106,   122,   156,
     165,   166,   170,   171,   221,   252,   257,   262,   280,   286,
     301,   321,   340,   354,   369,   376,   380,   390,   399,   422,
     432,   438,   442,   452,   516,   532,   553,   245,   246,   247,
     247,   322,   400,   433,   247,   443,   247,   517,   355,   423,
     341,   247,   247,   302,   370,   247,   247,   381,   391,   247,
       1,    36,    46,   107,   281,   282,   283,   284,   285,     1,
      13,    33,    34,    39,    41,    85,    86,    92,    93,   113,
     114,   128,   129,   139,   148,   233,   234,   235,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   138,   323,
     327,   138,   401,   405,   247,     1,    78,   439,   440,   441,
     247,     1,     8,     9,    12,    19,    27,    31,    32,    38,
      42,    43,    45,    51,    60,    61,    65,    72,    76,    77,
      80,    83,    84,    91,    97,    98,   100,   101,   102,   103,
     104,   115,   123,   124,   125,   127,   130,   131,   134,   145,
     167,   169,   173,   177,   178,   179,   180,   181,   185,   186,
     194,   222,   224,   226,   232,   237,   242,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   508,
     512,   513,   514,   515,   247,   247,   247,   247,     1,   223,
     236,   287,   288,   289,   290,   291,   292,     1,   105,   133,
     258,   259,   260,   261,   138,   303,   307,   247,     1,    40,
      53,    66,    68,    70,    71,    88,   554,   555,   556,   557,
     558,   559,   560,   561,   562,     1,    36,    74,   107,   109,
     110,   150,   152,   153,   168,   205,   238,   239,   263,   264,
     265,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   247,   247,     1,   107,   377,   378,   379,   245,
     248,   248,   248,   246,   282,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   246,   534,   247,   247,     1,    78,   140,
     434,   435,   436,   437,   248,   246,   440,     1,   107,   140,
     172,   444,   448,   449,   450,   451,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   509,   248,   505,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   246,   454,     1,     4,    44,    47,    90,   107,   231,
     518,   519,   520,   521,   522,   526,   527,   528,     1,    25,
      48,    52,   132,   141,   142,   175,   231,   356,   357,   358,
     359,   360,   361,   362,   366,   367,   368,     1,   140,   172,
     231,   424,   428,   429,   430,   431,     1,    52,    73,    78,
     137,   342,   346,   347,   348,   352,   353,   245,   248,   248,
     246,   288,   244,   245,   248,   248,   246,   259,   247,     1,
      21,   111,   140,   371,   372,   373,   374,   375,   248,   248,
     248,   248,   248,   248,   248,   246,   555,   245,   248,   248,
     248,   248,   248,   248,   248,   266,   248,   248,   248,   248,
     246,   264,     1,   107,   172,   231,   382,   383,   384,   385,
     386,     1,   107,   172,   392,   393,   394,   395,   248,   246,
     378,   138,   138,   138,   245,   182,   117,   117,   182,   182,
     117,   254,   254,   117,   117,   182,   182,   117,   254,   182,
     182,   182,   182,   182,   245,     1,    22,    23,    29,    94,
      95,    96,    99,   107,   119,   120,   135,   136,   163,   324,
     325,   326,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,     1,     3,     6,    24,    25,    48,
      52,    73,    75,    87,   107,   137,   151,   164,   238,   402,
     403,   404,   406,   407,   408,   409,   410,   411,   412,   416,
     417,   418,   419,   420,   421,   248,   248,   246,   435,   138,
     245,   248,   248,   445,   246,   449,   182,   254,   182,   254,
     117,   138,   117,   182,   182,   117,   138,   182,   117,   117,
     117,   182,   182,   182,   254,   138,   182,   117,   117,   254,
     117,   117,   138,   117,   117,   182,   182,   248,   182,   248,
     254,   254,   182,   254,   138,   182,   182,   182,   182,   183,
     182,   183,   182,   182,   254,   254,   117,   256,   138,   254,
     182,   182,   182,   182,   245,   529,   248,   248,   523,   248,
     248,   246,   519,   245,   248,   248,   363,   248,   248,   248,
     248,   248,   246,   357,   248,   425,   248,   246,   429,   245,
     343,   248,   248,   248,   246,   347,   182,   182,   245,   247,
     138,   138,   245,     1,    25,    48,    52,   107,   132,   151,
     214,   231,   304,   305,   306,   308,   309,   310,   311,   312,
     313,   317,   245,   248,   248,   248,   246,   372,   182,   182,
     182,   138,   182,   182,   254,   245,   138,   182,   138,   138,
     138,   138,   138,   248,   138,   117,   138,   138,   245,   245,
     248,   387,   248,   246,   383,   245,   248,   396,   246,   393,
     138,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     158,   159,   160,   161,   162,   253,   254,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   246,   325,   245,   248,   248,   248,
     248,   248,   413,   248,   248,   248,   248,   248,   248,   248,
     248,   246,   403,   138,   138,   245,   245,   138,   138,   248,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   189,   190,   191,   192,   193,   195,   196,   199,
     200,   201,   204,   206,   207,   208,   210,   211,   212,   215,
     219,   510,   511,   245,   189,   190,   191,   192,   193,   195,
     196,   199,   200,   201,   204,   206,   207,   208,   210,   211,
     212,   215,   219,   506,   507,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,    14,    15,    16,   255,   256,   245,   245,   245,   245,
     245,   245,   245,   248,   254,   182,   248,   138,   138,   245,
     138,   182,   248,   138,   117,   138,   138,   138,   245,   138,
     248,   138,   245,   248,   138,   138,   117,   350,   351,   245,
     245,   245,     1,   107,   172,   243,   293,   294,   295,   296,
     297,   245,   245,   245,   248,   248,   318,   248,   248,   248,
     314,   248,   246,   305,   138,   138,   138,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   154,   155,   267,   268,   245,   245,   245,   245,
     138,   248,   138,   245,   138,   248,   245,   245,   253,   253,
     253,   253,   253,   117,   117,   254,   117,   117,   117,   117,
     138,   117,   117,   254,   254,   256,   245,   138,   202,   203,
     138,   138,   182,   248,   138,   138,   138,   138,   117,   138,
     138,   138,   245,   245,   245,   245,   245,   143,   446,   447,
     245,   249,   245,   249,   255,   255,   255,    11,   184,   530,
     531,   245,   245,    11,   184,   524,   525,   245,   245,   245,
     245,    20,    49,    58,    64,    82,   108,   116,   157,   176,
     364,   365,   245,   245,   245,   245,   245,   245,   143,   426,
     427,   245,    66,   209,   213,   344,   345,   245,   245,   187,
     249,   349,   245,   248,   298,   248,   246,   294,   138,   182,
     248,   138,   138,   138,   248,   138,   245,   245,   245,   245,
     245,   249,   245,    81,   156,   188,   204,   216,   217,   227,
     228,   229,   230,   240,   388,   389,   245,   245,    81,   156,
     188,   204,   216,   217,   227,   228,   229,   230,   240,   397,
     398,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
      10,    12,    26,    30,   225,   414,   415,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   249,   511,   507,   245,
     249,   245,   249,   245,   249,   245,   249,   245,   249,   117,
     351,   245,   138,   248,   256,   245,   245,   245,     5,    37,
      56,    62,    67,    69,    81,   105,   112,   126,   144,   146,
     147,   207,   218,   220,   230,   240,   319,   320,   245,   245,
     245,   189,   190,   191,   192,   193,   195,   196,   199,   200,
     201,   204,   206,   207,   208,   210,   211,   212,   215,   219,
     315,   316,   245,   268,   245,   249,   245,   249,   245,   249,
     447,   531,   525,   365,   427,   345,   245,    56,    79,    81,
     122,   196,   197,   231,   299,   300,   245,   245,   249,   245,
     249,   389,   398,   415,   245,   249,   320,   316,   300
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
#line 410 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 412 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 416 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 420 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 424 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 428 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 432 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 437 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 439 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 440 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 441 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 461 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 481 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 487 "ircd_parser.y"
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
#line 501 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 507 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 515 "ircd_parser.y"
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
#line 549 "ircd_parser.y"
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
#line 609 "ircd_parser.y"
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

  case 74:

/* Line 1806 of yacc.c  */
#line 624 "ircd_parser.y"
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

  case 75:

/* Line 1806 of yacc.c  */
#line 639 "ircd_parser.y"
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
#line 648 "ircd_parser.y"
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
#line 662 "ircd_parser.y"
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
#line 671 "ircd_parser.y"
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

  case 79:

/* Line 1806 of yacc.c  */
#line 699 "ircd_parser.y"
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

  case 80:

/* Line 1806 of yacc.c  */
#line 729 "ircd_parser.y"
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
#line 752 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 767 "ircd_parser.y"
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
#line 776 "ircd_parser.y"
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
#line 785 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 803 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 809 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 815 "ircd_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 820 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 832 "ircd_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 837 "ircd_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 842 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 849 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 853 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 857 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 861 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 865 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 869 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 873 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 883 "ircd_parser.y"
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

  case 123:

/* Line 1806 of yacc.c  */
#line 896 "ircd_parser.y"
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

  case 137:

/* Line 1806 of yacc.c  */
#line 983 "ircd_parser.y"
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

  case 138:

/* Line 1806 of yacc.c  */
#line 995 "ircd_parser.y"
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

  case 139:

/* Line 1806 of yacc.c  */
#line 1007 "ircd_parser.y"
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1041 "ircd_parser.y"
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1053 "ircd_parser.y"
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1064 "ircd_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1106 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1122 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1126 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1130 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1134 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1138 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1142 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1146 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1150 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1154 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1158 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1162 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1166 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1170 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1200 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1207 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1211 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1215 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1219 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1227 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1231 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1243 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1247 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1251 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1255 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1259 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1263 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1267 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1271 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1275 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1285 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1292 "ircd_parser.y"
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

  case 209:

/* Line 1806 of yacc.c  */
#line 1352 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1361 "ircd_parser.y"
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
#line 1370 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1376 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1382 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1388 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1394 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1400 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1406 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1412 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1418 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1424 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1430 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1436 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1445 "ircd_parser.y"
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
#line 1452 "ircd_parser.y"
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
#line 1461 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1467 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1485 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1490 "ircd_parser.y"
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
#line 1504 "ircd_parser.y"
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
#line 1524 "ircd_parser.y"
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
#line 1533 "ircd_parser.y"
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
#line 1545 "ircd_parser.y"
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
#line 1557 "ircd_parser.y"
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
#line 1619 "ircd_parser.y"
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
#line 1656 "ircd_parser.y"
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
#line 1669 "ircd_parser.y"
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
#line 1678 "ircd_parser.y"
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
#line 1689 "ircd_parser.y"
    {
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1698 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1706 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1710 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1714 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1718 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1722 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1726 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1733 "ircd_parser.y"
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
#line 1752 "ircd_parser.y"
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
#line 1762 "ircd_parser.y"
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
#line 1775 "ircd_parser.y"
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
#line 1782 "ircd_parser.y"
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
#line 1794 "ircd_parser.y"
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
#line 1803 "ircd_parser.y"
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
#line 1818 "ircd_parser.y"
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
#line 1836 "ircd_parser.y"
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
#line 1851 "ircd_parser.y"
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
#line 1859 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1870 "ircd_parser.y"
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
#line 1879 "ircd_parser.y"
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
#line 1901 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1908 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1912 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1920 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1924 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1928 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1932 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1936 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1940 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1944 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1948 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1957 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1964 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1977 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1983 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1990 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1994 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1998 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2002 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2006 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2010 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2014 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2022 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2026 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2030 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2039 "ircd_parser.y"
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

  case 346:

/* Line 1806 of yacc.c  */
#line 2057 "ircd_parser.y"
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

  case 366:

/* Line 1806 of yacc.c  */
#line 2195 "ircd_parser.y"
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

  case 367:

/* Line 1806 of yacc.c  */
#line 2207 "ircd_parser.y"
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

  case 368:

/* Line 1806 of yacc.c  */
#line 2219 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 2228 "ircd_parser.y"
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

  case 370:

/* Line 1806 of yacc.c  */
#line 2254 "ircd_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2272 "ircd_parser.y"
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

  case 372:

/* Line 1806 of yacc.c  */
#line 2290 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2296 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2300 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2308 "ircd_parser.y"
    {
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2313 "ircd_parser.y"
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

  case 380:

/* Line 1806 of yacc.c  */
#line 2323 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 2327 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2331 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2335 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2341 "ircd_parser.y"
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

  case 385:

/* Line 1806 of yacc.c  */
#line 2382 "ircd_parser.y"
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

  case 386:

/* Line 1806 of yacc.c  */
#line 2393 "ircd_parser.y"
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

  case 387:

/* Line 1806 of yacc.c  */
#line 2406 "ircd_parser.y"
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

  case 388:

/* Line 1806 of yacc.c  */
#line 2419 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 2428 "ircd_parser.y"
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

  case 390:

/* Line 1806 of yacc.c  */
#line 2463 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2470 "ircd_parser.y"
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

  case 392:

/* Line 1806 of yacc.c  */
#line 2526 "ircd_parser.y"
    {
}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 2531 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 2540 "ircd_parser.y"
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

  case 404:

/* Line 1806 of yacc.c  */
#line 2559 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2568 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 2572 "ircd_parser.y"
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

  case 412:

/* Line 1806 of yacc.c  */
#line 2594 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 2600 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 2614 "ircd_parser.y"
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

  case 420:

/* Line 1806 of yacc.c  */
#line 2632 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2639 "ircd_parser.y"
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

  case 422:

/* Line 1806 of yacc.c  */
#line 2679 "ircd_parser.y"
    {
}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 2684 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 433:

/* Line 1806 of yacc.c  */
#line 2693 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 2699 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2744 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2749 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2754 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2759 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2764 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2769 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2774 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2779 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2784 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2789 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2794 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2799 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2804 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2809 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2814 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2819 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2824 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2829 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2834 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2840 "ircd_parser.y"
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

  case 514:

/* Line 1806 of yacc.c  */
#line 2851 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2856 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2865 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2870 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2875 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2880 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2885 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2890 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2893 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2898 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2901 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2906 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2911 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2916 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2921 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2926 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2931 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2941 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2946 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2957 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2962 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2967 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2976 "ircd_parser.y"
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

  case 538:

/* Line 1806 of yacc.c  */
#line 3008 "ircd_parser.y"
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

  case 539:

/* Line 1806 of yacc.c  */
#line 3026 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3031 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3049 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3054 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3059 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3064 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3070 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3073 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3076 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3079 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3082 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3085 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3088 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3091 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3094 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3097 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3100 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3103 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3106 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3109 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3112 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3115 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3118 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3121 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3124 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3129 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3135 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3138 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3141 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3144 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3147 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3150 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3153 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3156 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3159 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3162 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3168 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3171 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3174 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3177 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3180 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3183 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3186 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3189 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3194 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3199 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3204 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3209 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3225 "ircd_parser.y"
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

  case 606:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3257 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3263 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 3273 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 614:

/* Line 1806 of yacc.c  */
#line 3279 "ircd_parser.y"
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

  case 615:

/* Line 1806 of yacc.c  */
#line 3313 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 3322 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 3326 "ircd_parser.y"
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

  case 620:

/* Line 1806 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 3377 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3401 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3406 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3411 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3416 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3421 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3426 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3431 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3436 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3441 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3446 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3451 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3456 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3461 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 3466 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3471 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3476 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3481 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3486 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 3505 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 3511 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 3517 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 676:

/* Line 1806 of yacc.c  */
#line 3526 "ircd_parser.y"
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

  case 677:

/* Line 1806 of yacc.c  */
#line 3540 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 3546 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 679:

/* Line 1806 of yacc.c  */
#line 3552 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7876 "ircd_parser.c"
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



