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
     HIDDEN_NAME = 322,
     HIDE_SERVER_IPS = 323,
     HIDE_SERVERS = 324,
     HIDE_SPOOF_IPS = 325,
     HOST = 326,
     HUB = 327,
     HUB_MASK = 328,
     IGNORE_BOGUS_TS = 329,
     INVISIBLE_ON_CONNECT = 330,
     IP = 331,
     KILL = 332,
     KILL_CHASE_TIME_LIMIT = 333,
     KLINE = 334,
     KLINE_EXEMPT = 335,
     KLINE_REASON = 336,
     KLINE_WITH_REASON = 337,
     KNOCK_DELAY = 338,
     KNOCK_DELAY_CHANNEL = 339,
     LEAF_MASK = 340,
     LINKS_DELAY = 341,
     LISTEN = 342,
     T_LOG = 343,
     MAX_ACCEPT = 344,
     MAX_BANS = 345,
     MAX_CHANS_PER_USER = 346,
     MAX_GLOBAL = 347,
     MAX_IDENT = 348,
     MAX_LOCAL = 349,
     MAX_NICK_CHANGES = 350,
     MAX_NICK_TIME = 351,
     MAX_NUMBER = 352,
     MAX_TARGETS = 353,
     MAX_WATCH = 354,
     MESSAGE_LOCALE = 355,
     MIN_NONWILDCARD = 356,
     MIN_NONWILDCARD_SIMPLE = 357,
     MODULE = 358,
     MODULES = 359,
     NAME = 360,
     NEED_PASSWORD = 361,
     NETWORK_DESC = 362,
     NETWORK_NAME = 363,
     NICK = 364,
     NICK_CHANGES = 365,
     NO_CREATE_ON_SPLIT = 366,
     NO_JOIN_ON_SPLIT = 367,
     NO_OPER_FLOOD = 368,
     NO_TILDE = 369,
     NUMBER = 370,
     NUMBER_PER_IDENT = 371,
     NUMBER_PER_CIDR = 372,
     NUMBER_PER_IP = 373,
     NUMBER_PER_IP_GLOBAL = 374,
     OPERATOR = 375,
     OPERS_BYPASS_CALLERID = 376,
     OPER_ONLY_UMODES = 377,
     OPER_PASS_RESV = 378,
     OPER_SPY_T = 379,
     OPER_UMODES = 380,
     JOIN_FLOOD_COUNT = 381,
     JOIN_FLOOD_TIME = 382,
     PACE_WAIT = 383,
     PACE_WAIT_SIMPLE = 384,
     PASSWORD = 385,
     PATH = 386,
     PING_COOKIE = 387,
     PING_TIME = 388,
     PING_WARNING = 389,
     PORT = 390,
     QSTRING = 391,
     QUIET_ON_BAN = 392,
     REASON = 393,
     REDIRPORT = 394,
     REDIRSERV = 395,
     REGEX_T = 396,
     REHASH = 397,
     TREJECT_HOLD_TIME = 398,
     REMOTE = 399,
     REMOTEBAN = 400,
     RESTRICT_CHANNELS = 401,
     RESTRICTED = 402,
     RSA_PRIVATE_KEY_FILE = 403,
     RSA_PUBLIC_KEY_FILE = 404,
     SSL_CERTIFICATE_FILE = 405,
     T_SSL_CONNECTION_METHOD = 406,
     T_SSLV3 = 407,
     T_TLSV1 = 408,
     RESV = 409,
     RESV_EXEMPT = 410,
     SECONDS = 411,
     MINUTES = 412,
     HOURS = 413,
     DAYS = 414,
     WEEKS = 415,
     SENDQ = 416,
     SEND_PASSWORD = 417,
     SERVERHIDE = 418,
     SERVERINFO = 419,
     SERVLINK_PATH = 420,
     IRCD_SID = 421,
     TKLINE_EXPIRE_NOTICES = 422,
     T_SHARED = 423,
     T_CLUSTER = 424,
     TYPE = 425,
     SHORT_MOTD = 426,
     SILENT = 427,
     SPOOF = 428,
     SPOOF_NOTICE = 429,
     STATS_E_DISABLED = 430,
     STATS_I_OPER_ONLY = 431,
     STATS_K_OPER_ONLY = 432,
     STATS_O_OPER_ONLY = 433,
     STATS_P_OPER_ONLY = 434,
     TBOOL = 435,
     TMASKED = 436,
     T_REJECT = 437,
     TS_MAX_DELTA = 438,
     TS_WARN_DELTA = 439,
     TWODOTS = 440,
     T_ALL = 441,
     T_BOTS = 442,
     T_SOFTCALLERID = 443,
     T_CALLERID = 444,
     T_CCONN = 445,
     T_CCONN_FULL = 446,
     T_CLIENT_FLOOD = 447,
     T_DEAF = 448,
     T_DEBUG = 449,
     T_DLINE = 450,
     T_DRONE = 451,
     T_EXTERNAL = 452,
     T_FULL = 453,
     T_INVISIBLE = 454,
     T_IPV4 = 455,
     T_IPV6 = 456,
     T_LOCOPS = 457,
     T_MAX_CLIENTS = 458,
     T_NCHANGE = 459,
     T_OPERWALL = 460,
     T_REJ = 461,
     T_SERVER = 462,
     T_SERVNOTICE = 463,
     T_SKILL = 464,
     T_SPY = 465,
     T_SSL = 466,
     T_UMODES = 467,
     T_UNAUTH = 468,
     T_UNDLINE = 469,
     T_UNLIMITED = 470,
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
#define HIDDEN_NAME 322
#define HIDE_SERVER_IPS 323
#define HIDE_SERVERS 324
#define HIDE_SPOOF_IPS 325
#define HOST 326
#define HUB 327
#define HUB_MASK 328
#define IGNORE_BOGUS_TS 329
#define INVISIBLE_ON_CONNECT 330
#define IP 331
#define KILL 332
#define KILL_CHASE_TIME_LIMIT 333
#define KLINE 334
#define KLINE_EXEMPT 335
#define KLINE_REASON 336
#define KLINE_WITH_REASON 337
#define KNOCK_DELAY 338
#define KNOCK_DELAY_CHANNEL 339
#define LEAF_MASK 340
#define LINKS_DELAY 341
#define LISTEN 342
#define T_LOG 343
#define MAX_ACCEPT 344
#define MAX_BANS 345
#define MAX_CHANS_PER_USER 346
#define MAX_GLOBAL 347
#define MAX_IDENT 348
#define MAX_LOCAL 349
#define MAX_NICK_CHANGES 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_WATCH 354
#define MESSAGE_LOCALE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MODULE 358
#define MODULES 359
#define NAME 360
#define NEED_PASSWORD 361
#define NETWORK_DESC 362
#define NETWORK_NAME 363
#define NICK 364
#define NICK_CHANGES 365
#define NO_CREATE_ON_SPLIT 366
#define NO_JOIN_ON_SPLIT 367
#define NO_OPER_FLOOD 368
#define NO_TILDE 369
#define NUMBER 370
#define NUMBER_PER_IDENT 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP 373
#define NUMBER_PER_IP_GLOBAL 374
#define OPERATOR 375
#define OPERS_BYPASS_CALLERID 376
#define OPER_ONLY_UMODES 377
#define OPER_PASS_RESV 378
#define OPER_SPY_T 379
#define OPER_UMODES 380
#define JOIN_FLOOD_COUNT 381
#define JOIN_FLOOD_TIME 382
#define PACE_WAIT 383
#define PACE_WAIT_SIMPLE 384
#define PASSWORD 385
#define PATH 386
#define PING_COOKIE 387
#define PING_TIME 388
#define PING_WARNING 389
#define PORT 390
#define QSTRING 391
#define QUIET_ON_BAN 392
#define REASON 393
#define REDIRPORT 394
#define REDIRSERV 395
#define REGEX_T 396
#define REHASH 397
#define TREJECT_HOLD_TIME 398
#define REMOTE 399
#define REMOTEBAN 400
#define RESTRICT_CHANNELS 401
#define RESTRICTED 402
#define RSA_PRIVATE_KEY_FILE 403
#define RSA_PUBLIC_KEY_FILE 404
#define SSL_CERTIFICATE_FILE 405
#define T_SSL_CONNECTION_METHOD 406
#define T_SSLV3 407
#define T_TLSV1 408
#define RESV 409
#define RESV_EXEMPT 410
#define SECONDS 411
#define MINUTES 412
#define HOURS 413
#define DAYS 414
#define WEEKS 415
#define SENDQ 416
#define SEND_PASSWORD 417
#define SERVERHIDE 418
#define SERVERINFO 419
#define SERVLINK_PATH 420
#define IRCD_SID 421
#define TKLINE_EXPIRE_NOTICES 422
#define T_SHARED 423
#define T_CLUSTER 424
#define TYPE 425
#define SHORT_MOTD 426
#define SILENT 427
#define SPOOF 428
#define SPOOF_NOTICE 429
#define STATS_E_DISABLED 430
#define STATS_I_OPER_ONLY 431
#define STATS_K_OPER_ONLY 432
#define STATS_O_OPER_ONLY 433
#define STATS_P_OPER_ONLY 434
#define TBOOL 435
#define TMASKED 436
#define T_REJECT 437
#define TS_MAX_DELTA 438
#define TS_WARN_DELTA 439
#define TWODOTS 440
#define T_ALL 441
#define T_BOTS 442
#define T_SOFTCALLERID 443
#define T_CALLERID 444
#define T_CCONN 445
#define T_CCONN_FULL 446
#define T_CLIENT_FLOOD 447
#define T_DEAF 448
#define T_DEBUG 449
#define T_DLINE 450
#define T_DRONE 451
#define T_EXTERNAL 452
#define T_FULL 453
#define T_INVISIBLE 454
#define T_IPV4 455
#define T_IPV6 456
#define T_LOCOPS 457
#define T_MAX_CLIENTS 458
#define T_NCHANGE 459
#define T_OPERWALL 460
#define T_REJ 461
#define T_SERVER 462
#define T_SERVNOTICE 463
#define T_SKILL 464
#define T_SPY 465
#define T_SSL 466
#define T_UMODES 467
#define T_UNAUTH 468
#define T_UNDLINE 469
#define T_UNLIMITED 470
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
#define YYLAST   1372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  250
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1318

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
     329,   334,   339,   340,   346,   350,   352,   354,   356,   358,
     360,   362,   364,   366,   367,   374,   377,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   398,   403,   408,   413,
     418,   423,   428,   429,   435,   439,   441,   443,   445,   447,
     449,   451,   453,   455,   457,   459,   461,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   481,   482,   488,   492,
     494,   496,   498,   500,   502,   504,   506,   508,   510,   512,
     514,   516,   518,   520,   522,   524,   526,   528,   530,   531,
     538,   541,   543,   545,   547,   549,   551,   553,   555,   557,
     559,   561,   563,   565,   567,   569,   572,   577,   582,   587,
     592,   597,   602,   607,   612,   617,   622,   627,   632,   637,
     638,   645,   646,   652,   656,   658,   660,   662,   664,   667,
     669,   671,   673,   675,   677,   680,   681,   687,   691,   693,
     695,   699,   704,   709,   710,   717,   720,   722,   724,   726,
     728,   730,   732,   734,   736,   738,   741,   746,   751,   756,
     761,   762,   768,   772,   774,   776,   778,   780,   782,   784,
     786,   788,   790,   792,   797,   802,   807,   808,   815,   818,
     820,   822,   824,   826,   829,   834,   839,   844,   850,   853,
     855,   857,   859,   864,   865,   872,   875,   877,   879,   881,
     883,   886,   891,   896,   897,   903,   907,   909,   911,   913,
     915,   917,   919,   921,   923,   925,   927,   929,   930,   937,
     940,   942,   944,   946,   949,   954,   955,   961,   965,   967,
     969,   971,   973,   975,   977,   979,   981,   983,   985,   987,
     988,   995,   998,  1000,  1002,  1004,  1006,  1008,  1010,  1012,
    1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,  1031,  1036,
    1041,  1046,  1051,  1056,  1061,  1066,  1071,  1072,  1078,  1082,
    1084,  1086,  1088,  1090,  1092,  1094,  1099,  1104,  1109,  1114,
    1119,  1124,  1125,  1132,  1133,  1139,  1143,  1145,  1147,  1150,
    1152,  1154,  1156,  1158,  1160,  1165,  1170,  1171,  1178,  1181,
    1183,  1185,  1187,  1189,  1194,  1199,  1205,  1208,  1210,  1212,
    1214,  1219,  1220,  1227,  1228,  1234,  1238,  1240,  1242,  1245,
    1247,  1249,  1251,  1253,  1255,  1260,  1265,  1271,  1274,  1276,
    1278,  1280,  1282,  1284,  1286,  1288,  1290,  1292,  1294,  1296,
    1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,
    1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,
    1338,  1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,
    1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,
    1378,  1380,  1382,  1384,  1386,  1391,  1396,  1401,  1406,  1411,
    1416,  1421,  1426,  1431,  1436,  1441,  1446,  1451,  1456,  1461,
    1466,  1471,  1476,  1481,  1486,  1491,  1496,  1501,  1506,  1511,
    1516,  1521,  1526,  1531,  1536,  1541,  1546,  1551,  1556,  1561,
    1566,  1571,  1576,  1581,  1586,  1591,  1596,  1601,  1606,  1611,
    1616,  1621,  1626,  1631,  1636,  1637,  1643,  1647,  1649,  1651,
    1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1690,
    1696,  1700,  1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,
    1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,
    1738,  1740,  1742,  1747,  1752,  1757,  1762,  1763,  1770,  1773,
    1775,  1777,  1779,  1781,  1783,  1785,  1787,  1789,  1794,  1799,
    1800,  1806,  1810,  1812,  1814,  1816,  1821,  1826,  1827,  1833,
    1837,  1839,  1841,  1843,  1849,  1852,  1854,  1856,  1858,  1860,
    1862,  1864,  1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,
    1882,  1884,  1886,  1888,  1890,  1892,  1897,  1902,  1907,  1912,
    1917,  1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,  1962,
    1967,  1972,  1977,  1982,  1988,  1991,  1993,  1995,  1997,  1999,
    2001,  2003,  2005,  2007,  2009,  2014,  2019,  2024,  2029,  2034,
    2039
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     251,     0,    -1,    -1,   251,   252,    -1,   280,    -1,   286,
      -1,   301,    -1,   525,    -1,   319,    -1,   336,    -1,   350,
      -1,   262,    -1,   546,    -1,   365,    -1,   372,    -1,   376,
      -1,   386,    -1,   395,    -1,   416,    -1,   426,    -1,   432,
      -1,   446,    -1,   509,    -1,   436,    -1,   257,    -1,     1,
     245,    -1,     1,   246,    -1,    -1,   254,    -1,   115,   253,
      -1,   115,   156,   253,    -1,   115,   157,   253,    -1,   115,
     158,   253,    -1,   115,   159,   253,    -1,   115,   160,   253,
      -1,    -1,   256,    -1,   115,   255,    -1,   115,    14,   255,
      -1,   115,    15,   255,    -1,   115,    16,   255,    -1,   104,
     247,   258,   246,   245,    -1,   258,   259,    -1,   259,    -1,
     260,    -1,   261,    -1,     1,   245,    -1,   103,   248,   136,
     245,    -1,   131,   248,   136,   245,    -1,   164,   247,   263,
     246,   245,    -1,   263,   264,    -1,   264,    -1,   271,    -1,
     276,    -1,   279,    -1,   273,    -1,   274,    -1,   275,    -1,
     278,    -1,   270,    -1,   277,    -1,   272,    -1,   269,    -1,
     265,    -1,     1,   245,    -1,    -1,   151,   266,   248,   267,
     245,    -1,   267,   249,   268,    -1,   268,    -1,   152,    -1,
     153,    -1,   150,   248,   136,   245,    -1,   148,   248,   136,
     245,    -1,   105,   248,   136,   245,    -1,   166,   248,   136,
     245,    -1,    36,   248,   136,   245,    -1,   108,   248,   136,
     245,    -1,   107,   248,   136,   245,    -1,   238,   248,   136,
     245,    -1,   239,   248,   136,   245,    -1,   203,   248,   115,
     245,    -1,    72,   248,   180,   245,    -1,     5,   247,   281,
     246,   245,    -1,   281,   282,    -1,   282,    -1,   283,    -1,
     285,    -1,   284,    -1,     1,   245,    -1,   105,   248,   136,
     245,    -1,    46,   248,   136,   245,    -1,    36,   248,   136,
     245,    -1,    88,   247,   287,   246,   245,    -1,   287,   288,
      -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,     1,
     245,    -1,   236,   248,   180,   245,    -1,   223,   248,   180,
     245,    -1,    -1,   292,   244,   247,   293,   246,   245,    -1,
     293,   294,    -1,   294,    -1,   295,    -1,   297,    -1,   296,
      -1,     1,   245,    -1,   105,   248,   136,   245,    -1,   243,
     248,   256,   245,    -1,   243,   248,   215,   245,    -1,    -1,
     170,   298,   248,   299,   245,    -1,   299,   249,   300,    -1,
     300,    -1,   231,    -1,   120,    -1,    56,    -1,   195,    -1,
      79,    -1,    77,    -1,   194,    -1,    -1,   120,   302,   247,
     303,   246,   245,    -1,   303,   304,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,   311,    -1,   310,    -1,   308,
      -1,   309,    -1,   315,    -1,     1,   245,    -1,   105,   248,
     136,   245,    -1,   231,   248,   136,   245,    -1,   130,   248,
     136,   245,    -1,    48,   248,   180,   245,    -1,   149,   248,
     136,   245,    -1,    25,   248,   136,   245,    -1,    -1,   212,
     312,   248,   313,   245,    -1,   313,   249,   314,    -1,   314,
      -1,   187,    -1,   190,    -1,   191,    -1,   193,    -1,   194,
      -1,   198,    -1,    66,    -1,   209,    -1,   204,    -1,   206,
      -1,   213,    -1,   210,    -1,   197,    -1,   205,    -1,   208,
      -1,   199,    -1,   219,    -1,   188,    -1,   189,    -1,   202,
      -1,    -1,    52,   316,   248,   317,   245,    -1,   317,   249,
     318,    -1,   318,    -1,    62,    -1,   144,    -1,    79,    -1,
     230,    -1,   195,    -1,   214,    -1,   240,    -1,    56,    -1,
      37,    -1,   220,    -1,   142,    -1,     5,    -1,   110,    -1,
     205,    -1,   218,    -1,   124,    -1,   145,    -1,   103,    -1,
      -1,    25,   320,   247,   321,   246,   245,    -1,   321,   322,
      -1,   322,    -1,   323,    -1,   333,    -1,   334,    -1,   324,
      -1,   325,    -1,   335,    -1,   326,    -1,   327,    -1,   328,
      -1,   329,    -1,   330,    -1,   331,    -1,   332,    -1,     1,
     245,    -1,   105,   248,   136,   245,    -1,   133,   248,   254,
     245,    -1,   134,   248,   254,   245,    -1,   118,   248,   115,
     245,    -1,    29,   248,   254,   245,    -1,    97,   248,   115,
     245,    -1,    92,   248,   115,   245,    -1,    94,   248,   115,
     245,    -1,    93,   248,   115,   245,    -1,   161,   248,   256,
     245,    -1,    22,   248,   115,   245,    -1,    23,   248,   115,
     245,    -1,   117,   248,   115,   245,    -1,    -1,    87,   337,
     247,   342,   246,   245,    -1,    -1,    52,   339,   248,   340,
     245,    -1,   340,   249,   341,    -1,   341,    -1,   211,    -1,
      66,    -1,   207,    -1,   342,   343,    -1,   343,    -1,   344,
      -1,   338,    -1,   348,    -1,   349,    -1,     1,   245,    -1,
      -1,   135,   248,   346,   345,   245,    -1,   346,   249,   347,
      -1,   347,    -1,   115,    -1,   115,   185,   115,    -1,    76,
     248,   136,   245,    -1,    71,   248,   136,   245,    -1,    -1,
      63,   351,   247,   352,   246,   245,    -1,   352,   353,    -1,
     353,    -1,   354,    -1,   355,    -1,   356,    -1,   358,    -1,
     362,    -1,   363,    -1,   364,    -1,   357,    -1,     1,   245,
      -1,   231,   248,   136,   245,    -1,   130,   248,   136,   245,
      -1,    25,   248,   136,   245,    -1,    48,   248,   180,   245,
      -1,    -1,    52,   359,   248,   360,   245,    -1,   360,   249,
     361,    -1,   361,    -1,   174,    -1,    49,    -1,    80,    -1,
      64,    -1,    20,    -1,   114,    -1,    58,    -1,   155,    -1,
     106,    -1,   173,   248,   136,   245,    -1,   140,   248,   136,
     245,    -1,   139,   248,   115,   245,    -1,    -1,   154,   366,
     247,   367,   246,   245,    -1,   367,   368,    -1,   368,    -1,
     369,    -1,   370,    -1,   371,    -1,     1,   245,    -1,   138,
     248,   136,   245,    -1,    21,   248,   136,   245,    -1,   109,
     248,   136,   245,    -1,   221,   247,   373,   246,   245,    -1,
     373,   374,    -1,   374,    -1,   375,    -1,     1,    -1,   105,
     248,   136,   245,    -1,    -1,   168,   377,   247,   378,   246,
     245,    -1,   378,   379,    -1,   379,    -1,   380,    -1,   381,
      -1,   382,    -1,     1,   245,    -1,   105,   248,   136,   245,
      -1,   231,   248,   136,   245,    -1,    -1,   170,   383,   248,
     384,   245,    -1,   384,   249,   385,    -1,   385,    -1,    79,
      -1,   230,    -1,   195,    -1,   214,    -1,   240,    -1,   217,
      -1,   154,    -1,   216,    -1,   202,    -1,   186,    -1,    -1,
     169,   387,   247,   388,   246,   245,    -1,   388,   389,    -1,
     389,    -1,   390,    -1,   391,    -1,     1,   245,    -1,   105,
     248,   136,   245,    -1,    -1,   170,   392,   248,   393,   245,
      -1,   393,   249,   394,    -1,   394,    -1,    79,    -1,   230,
      -1,   195,    -1,   214,    -1,   240,    -1,   217,    -1,   154,
      -1,   216,    -1,   202,    -1,   186,    -1,    -1,    28,   396,
     247,   397,   246,   245,    -1,   397,   398,    -1,   398,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     405,    -1,   404,    -1,   406,    -1,   412,    -1,   413,    -1,
     414,    -1,   411,    -1,   410,    -1,   415,    -1,     1,   245,
      -1,   105,   248,   136,   245,    -1,    71,   248,   136,   245,
      -1,   238,   248,   136,   245,    -1,   162,   248,   136,   245,
      -1,     3,   248,   136,   245,    -1,   135,   248,   115,   245,
      -1,     6,   248,   200,   245,    -1,     6,   248,   201,   245,
      -1,    -1,    52,   407,   248,   408,   245,    -1,   408,   249,
     409,    -1,   409,    -1,    26,    -1,    30,    -1,    10,    -1,
      12,    -1,   225,    -1,   149,   248,   136,   245,    -1,    48,
     248,   180,   245,    -1,    73,   248,   136,   245,    -1,    85,
     248,   136,   245,    -1,    25,   248,   136,   245,    -1,    24,
     248,   136,   245,    -1,    -1,    77,   417,   247,   422,   246,
     245,    -1,    -1,   170,   419,   248,   420,   245,    -1,   420,
     249,   421,    -1,   421,    -1,   141,    -1,   422,   423,    -1,
     423,    -1,   424,    -1,   425,    -1,   418,    -1,     1,    -1,
     231,   248,   136,   245,    -1,   138,   248,   136,   245,    -1,
      -1,    35,   427,   247,   428,   246,   245,    -1,   428,   429,
      -1,   429,    -1,   430,    -1,   431,    -1,     1,    -1,    76,
     248,   136,   245,    -1,   138,   248,   136,   245,    -1,    50,
     247,   433,   246,   245,    -1,   433,   434,    -1,   434,    -1,
     435,    -1,     1,    -1,    76,   248,   136,   245,    -1,    -1,
      54,   437,   247,   442,   246,   245,    -1,    -1,   170,   439,
     248,   440,   245,    -1,   440,   249,   441,    -1,   441,    -1,
     141,    -1,   442,   443,    -1,   443,    -1,   444,    -1,   445,
      -1,   438,    -1,     1,    -1,   105,   248,   136,   245,    -1,
     138,   248,   136,   245,    -1,    55,   247,   447,   246,   245,
      -1,   447,   448,    -1,   448,    -1,   456,    -1,   457,    -1,
     459,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     464,    -1,   465,    -1,   466,    -1,   455,    -1,   468,    -1,
     469,    -1,   470,    -1,   471,    -1,   486,    -1,   473,    -1,
     475,    -1,   477,    -1,   476,    -1,   480,    -1,   474,    -1,
     481,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     501,    -1,   487,    -1,   491,    -1,   492,    -1,   497,    -1,
     478,    -1,   479,    -1,   507,    -1,   505,    -1,   506,    -1,
     488,    -1,   458,    -1,   489,    -1,   490,    -1,   508,    -1,
     496,    -1,   467,    -1,   494,    -1,   495,    -1,   454,    -1,
     450,    -1,   451,    -1,   452,    -1,   453,    -1,   472,    -1,
     449,    -1,   493,    -1,     1,    -1,    99,   248,   115,   245,
      -1,    60,   248,   115,   245,    -1,    61,   248,   115,   245,
      -1,   237,   248,   180,   245,    -1,   143,   248,   254,   245,
      -1,   167,   248,   180,   245,    -1,    78,   248,   254,   245,
      -1,    70,   248,   180,   245,    -1,    74,   248,   180,   245,
      -1,    42,   248,   180,   245,    -1,    51,   248,   180,   245,
      -1,     8,   248,   180,   245,    -1,    96,   248,   254,   245,
      -1,    95,   248,   115,   245,    -1,    89,   248,   115,   245,
      -1,     9,   248,   254,   245,    -1,   184,   248,   254,   245,
      -1,   183,   248,   254,   245,    -1,    65,   248,   115,   245,
      -1,    82,   248,   180,   245,    -1,    81,   248,   136,   245,
      -1,    75,   248,   180,   245,    -1,   242,   248,   180,   245,
      -1,   175,   248,   180,   245,    -1,   178,   248,   180,   245,
      -1,   179,   248,   180,   245,    -1,   177,   248,   180,   245,
      -1,   177,   248,   181,   245,    -1,   176,   248,   180,   245,
      -1,   176,   248,   181,   245,    -1,   128,   248,   254,   245,
      -1,    19,   248,   254,   245,    -1,   121,   248,   180,   245,
      -1,   129,   248,   254,   245,    -1,   171,   248,   180,   245,
      -1,   113,   248,   180,   245,    -1,   226,   248,   180,   245,
      -1,   123,   248,   180,   245,    -1,   100,   248,   136,   245,
      -1,    43,   248,   115,   245,    -1,    98,   248,   115,   245,
      -1,   165,   248,   136,   245,    -1,    31,   248,   136,   245,
      -1,    27,   248,   115,   245,    -1,   232,   248,   180,   245,
      -1,    45,   248,   136,   245,    -1,   222,   248,   136,   245,
      -1,   132,   248,   180,   245,    -1,    38,   248,   180,   245,
      -1,   224,   248,   254,   245,    -1,    -1,   125,   498,   248,
     499,   245,    -1,   499,   249,   500,    -1,   500,    -1,   187,
      -1,   190,    -1,   191,    -1,   193,    -1,   194,    -1,   198,
      -1,    66,    -1,   209,    -1,   204,    -1,   206,    -1,   213,
      -1,   210,    -1,   197,    -1,   205,    -1,   208,    -1,   199,
      -1,   219,    -1,   188,    -1,   189,    -1,   202,    -1,    -1,
     122,   502,   248,   503,   245,    -1,   503,   249,   504,    -1,
     504,    -1,   187,    -1,   190,    -1,   191,    -1,   193,    -1,
     194,    -1,   198,    -1,   209,    -1,    66,    -1,   204,    -1,
     206,    -1,   213,    -1,   210,    -1,   197,    -1,   205,    -1,
     208,    -1,   199,    -1,   219,    -1,   188,    -1,   189,    -1,
     202,    -1,   101,   248,   115,   245,    -1,   102,   248,   115,
     245,    -1,    32,   248,   115,   245,    -1,   192,   248,   256,
     245,    -1,    -1,    57,   510,   247,   511,   246,   245,    -1,
     511,   512,    -1,   512,    -1,   513,    -1,   514,    -1,   515,
      -1,   519,    -1,   520,    -1,   521,    -1,     1,    -1,    47,
     248,   180,   245,    -1,    44,   248,   254,   245,    -1,    -1,
      88,   516,   248,   517,   245,    -1,   517,   249,   518,    -1,
     518,    -1,   182,    -1,    11,    -1,   231,   248,   136,   245,
      -1,   105,   248,   136,   245,    -1,    -1,     4,   522,   248,
     523,   245,    -1,   523,   249,   524,    -1,   524,    -1,   182,
      -1,    11,    -1,    21,   247,   526,   246,   245,    -1,   526,
     527,    -1,   527,    -1,   530,    -1,   531,    -1,   532,    -1,
     533,    -1,   538,    -1,   534,    -1,   535,    -1,   536,    -1,
     537,    -1,   539,    -1,   540,    -1,   541,    -1,   529,    -1,
     542,    -1,   543,    -1,   544,    -1,   545,    -1,   528,    -1,
       1,    -1,    39,   248,   180,   245,    -1,   146,   248,   180,
     245,    -1,    41,   248,   180,   245,    -1,   233,   248,   180,
     245,    -1,   234,   248,   180,   245,    -1,   235,   248,   180,
     245,    -1,    83,   248,   254,   245,    -1,    84,   248,   254,
     245,    -1,    91,   248,   115,   245,    -1,   137,   248,   180,
     245,    -1,    90,   248,   115,   245,    -1,    34,   248,   115,
     245,    -1,    33,   248,   115,   245,    -1,   111,   248,   180,
     245,    -1,   112,   248,   180,   245,    -1,    13,   248,   180,
     245,    -1,   126,   248,   115,   245,    -1,   127,   248,   254,
     245,    -1,   163,   247,   547,   246,   245,    -1,   547,   548,
      -1,   548,    -1,   549,    -1,   550,    -1,   552,    -1,   554,
      -1,   553,    -1,   551,    -1,   555,    -1,     1,    -1,    53,
     248,   180,   245,    -1,    69,   248,   180,   245,    -1,    67,
     248,   136,   245,    -1,    86,   248,   254,   245,    -1,    66,
     248,   180,   245,    -1,    40,   248,   180,   245,    -1,    68,
     248,   180,   245,    -1
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
     836,   839,   845,   844,   850,   850,   851,   855,   859,   863,
     867,   871,   875,   886,   885,   983,   983,   984,   984,   984,
     985,   985,   985,   986,   986,   986,   988,  1000,  1037,  1049,
    1060,  1102,  1112,  1111,  1117,  1117,  1118,  1122,  1126,  1130,
    1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,  1170,
    1174,  1178,  1182,  1186,  1190,  1194,  1201,  1200,  1206,  1206,
    1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,  1243,
    1247,  1251,  1255,  1259,  1263,  1267,  1271,  1275,  1286,  1285,
    1335,  1335,  1336,  1337,  1337,  1338,  1339,  1340,  1341,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1350,  1359,  1365,  1371,
    1377,  1383,  1389,  1395,  1401,  1407,  1413,  1419,  1425,  1435,
    1434,  1451,  1450,  1455,  1455,  1456,  1460,  1464,  1472,  1472,
    1473,  1473,  1473,  1473,  1473,  1475,  1475,  1477,  1477,  1479,
    1493,  1513,  1522,  1535,  1534,  1603,  1603,  1604,  1604,  1604,
    1604,  1605,  1605,  1605,  1606,  1606,  1608,  1645,  1658,  1667,
    1679,  1678,  1682,  1682,  1683,  1687,  1691,  1695,  1699,  1703,
    1707,  1711,  1715,  1722,  1741,  1751,  1765,  1764,  1780,  1780,
    1781,  1781,  1781,  1781,  1783,  1792,  1807,  1820,  1822,  1822,
    1823,  1823,  1825,  1841,  1840,  1856,  1856,  1857,  1857,  1857,
    1857,  1859,  1868,  1891,  1890,  1896,  1896,  1897,  1901,  1905,
    1909,  1913,  1917,  1921,  1925,  1929,  1933,  1943,  1942,  1959,
    1959,  1960,  1960,  1960,  1962,  1969,  1968,  1974,  1974,  1975,
    1979,  1983,  1987,  1991,  1995,  1999,  2003,  2007,  2011,  2021,
    2020,  2163,  2163,  2164,  2164,  2164,  2165,  2165,  2166,  2166,
    2167,  2167,  2167,  2168,  2168,  2169,  2169,  2170,  2172,  2184,
    2193,  2219,  2237,  2255,  2261,  2265,  2274,  2273,  2277,  2277,
    2278,  2288,  2292,  2296,  2300,  2306,  2347,  2358,  2371,  2384,
    2393,  2429,  2428,  2492,  2491,  2495,  2495,  2496,  2502,  2502,
    2503,  2503,  2503,  2503,  2505,  2524,  2534,  2533,  2556,  2556,
    2557,  2557,  2557,  2559,  2565,  2574,  2576,  2576,  2577,  2577,
    2579,  2598,  2597,  2645,  2644,  2648,  2648,  2649,  2655,  2655,
    2656,  2656,  2656,  2656,  2658,  2664,  2673,  2676,  2676,  2677,
    2677,  2678,  2678,  2679,  2679,  2680,  2680,  2681,  2681,  2682,
    2682,  2683,  2683,  2684,  2684,  2685,  2685,  2686,  2686,  2687,
    2687,  2688,  2688,  2689,  2689,  2690,  2691,  2691,  2692,  2692,
    2693,  2693,  2694,  2694,  2695,  2695,  2696,  2696,  2697,  2698,
    2698,  2699,  2699,  2700,  2701,  2702,  2702,  2703,  2703,  2704,
    2704,  2705,  2705,  2706,  2709,  2714,  2719,  2724,  2729,  2734,
    2739,  2744,  2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,
    2789,  2794,  2800,  2811,  2816,  2825,  2830,  2835,  2840,  2845,
    2850,  2853,  2858,  2861,  2866,  2871,  2876,  2881,  2886,  2891,
    2896,  2901,  2906,  2917,  2922,  2927,  2936,  2968,  2986,  2991,
    3000,  3009,  3014,  3019,  3025,  3024,  3029,  3029,  3030,  3033,
    3036,  3039,  3042,  3045,  3048,  3051,  3054,  3057,  3060,  3063,
    3066,  3069,  3072,  3075,  3078,  3081,  3084,  3087,  3093,  3092,
    3097,  3097,  3098,  3101,  3104,  3107,  3110,  3113,  3116,  3119,
    3122,  3125,  3128,  3131,  3134,  3137,  3140,  3143,  3146,  3149,
    3152,  3155,  3160,  3165,  3170,  3175,  3185,  3184,  3208,  3208,
    3209,  3210,  3211,  3212,  3213,  3214,  3215,  3217,  3223,  3230,
    3229,  3234,  3234,  3235,  3239,  3245,  3279,  3289,  3288,  3338,
    3338,  3339,  3343,  3352,  3355,  3355,  3356,  3356,  3357,  3357,
    3358,  3358,  3359,  3359,  3360,  3360,  3361,  3362,  3362,  3363,
    3363,  3364,  3364,  3365,  3365,  3367,  3372,  3377,  3382,  3387,
    3392,  3397,  3402,  3407,  3412,  3417,  3422,  3427,  3432,  3437,
    3442,  3447,  3452,  3460,  3463,  3463,  3464,  3464,  3465,  3466,
    3467,  3467,  3468,  3469,  3471,  3477,  3483,  3492,  3506,  3512,
    3518
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
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_REASON", "KLINE_WITH_REASON", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_WATCH", "MESSAGE_LOCALE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
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
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "T_TIMESTAMP", "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD",
  "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT",
  "USE_INVEX", "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST",
  "VHOST6", "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'",
  "'}'", "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
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
  "logging_file_type_item", "oper_entry", "$@4", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@5",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@6",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@7",
  "class_items", "class_item", "class_name", "class_ping_time",
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
  "connect_items", "connect_item", "connect_name", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_flags", "$@19",
  "connect_flags_items", "connect_flags_item",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_cipher_preference",
  "kill_entry", "$@20", "kill_type", "$@21", "kill_type_items",
  "kill_type_item", "kill_items", "kill_item", "kill_user", "kill_reason",
  "deny_entry", "$@22", "deny_items", "deny_item", "deny_ip",
  "deny_reason", "exempt_entry", "exempt_items", "exempt_item",
  "exempt_ip", "gecos_entry", "$@23", "gecos_flags", "$@24",
  "gecos_flags_items", "gecos_flags_item", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_max_watch", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_use_whois_actually",
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
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "gline_entry", "$@27", "gline_items",
  "gline_item", "gline_enable", "gline_duration", "gline_logging", "$@28",
  "gline_logging_types", "gline_logging_type_item", "gline_user",
  "gline_server", "gline_action", "$@29", "gdeny_types", "gdeny_type_item",
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
     296,   296,   298,   297,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   302,   301,   303,   303,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   305,   306,   307,   308,
     309,   310,   312,   311,   313,   313,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   316,   315,   317,   317,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   320,   319,
     321,   321,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   337,
     336,   339,   338,   340,   340,   341,   341,   341,   342,   342,
     343,   343,   343,   343,   343,   345,   344,   346,   346,   347,
     347,   348,   349,   351,   350,   352,   352,   353,   353,   353,
     353,   353,   353,   353,   353,   353,   354,   355,   356,   357,
     359,   358,   360,   360,   361,   361,   361,   361,   361,   361,
     361,   361,   361,   362,   363,   364,   366,   365,   367,   367,
     368,   368,   368,   368,   369,   370,   371,   372,   373,   373,
     374,   374,   375,   377,   376,   378,   378,   379,   379,   379,
     379,   380,   381,   383,   382,   384,   384,   385,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   387,   386,   388,
     388,   389,   389,   389,   390,   392,   391,   393,   393,   394,
     394,   394,   394,   394,   394,   394,   394,   394,   394,   396,
     395,   397,   397,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   399,   400,
     401,   402,   403,   404,   405,   405,   407,   406,   408,   408,
     409,   409,   409,   409,   409,   410,   411,   412,   413,   414,
     415,   417,   416,   419,   418,   420,   420,   421,   422,   422,
     423,   423,   423,   423,   424,   425,   427,   426,   428,   428,
     429,   429,   429,   430,   431,   432,   433,   433,   434,   434,
     435,   437,   436,   439,   438,   440,   440,   441,   442,   442,
     443,   443,   443,   443,   444,   445,   446,   447,   447,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   475,   476,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   498,   497,   499,   499,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   502,   501,
     503,   503,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   505,   506,   507,   508,   510,   509,   511,   511,
     512,   512,   512,   512,   512,   512,   512,   513,   514,   516,
     515,   517,   517,   518,   518,   519,   520,   522,   521,   523,
     523,   524,   524,   525,   526,   526,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   547,   548,   548,   548,   548,
     548,   548,   548,   548,   549,   550,   551,   552,   553,   554,
     555
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
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       6,     0,     5,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     5,     2,     1,
       1,     1,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     2,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
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
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     0,
       5,     3,     1,     1,     1,     4,     4,     0,     5,     3,
       1,     1,     1,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   188,   339,   396,     0,
     411,     0,   586,   243,   381,   219,     0,     0,   123,   276,
       0,     0,   293,   317,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   634,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     633,   628,   616,   617,   618,   619,   621,   622,   623,   624,
     620,   625,   626,   627,   629,   630,   631,   632,     0,     0,
       0,   409,     0,     0,   407,   408,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,     0,
     534,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   428,   481,   476,   477,   478,   479,   475,
     439,   429,   430,   467,   431,   432,   433,   434,   435,   436,
     437,   438,   472,   440,   441,   442,   443,   480,   445,   450,
     446,   448,   447,   461,   462,   449,   451,   452,   453,   454,
     455,   444,   457,   466,   468,   469,   458,   459,   482,   473,
     474,   471,   460,   456,   464,   465,   463,   470,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
     663,     0,     0,     0,     0,     0,     0,     0,     0,   655,
     656,   657,   661,   658,   660,   659,   662,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,    51,    63,    62,    59,    52,    61,    55,    56,    57,
      53,    60,    58,    54,     0,     0,   291,     0,     0,   289,
     290,    88,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   192,   195,   196,   198,   199,   200,   201,
     202,   203,   204,   193,   194,   197,     0,     0,     0,     0,
       0,     0,   366,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   342,   343,   344,   345,   346,   347,   349,   348,
     350,   355,   354,   351,   352,   353,   356,   402,     0,     0,
       0,   399,   400,   401,     0,     0,   406,   423,     0,     0,
     413,   422,     0,   419,   420,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,   596,   607,     0,     0,   599,     0,     0,     0,
     589,   590,   591,   592,   593,   594,   595,     0,     0,     0,
     260,     0,     0,     0,     0,     0,     0,   246,   247,   248,
     249,   254,   250,   251,   252,   253,   393,     0,   383,     0,
     392,     0,   389,   390,   391,     0,   221,     0,     0,     0,
     231,     0,   229,   230,   232,   233,    98,     0,     0,     0,
      93,     0,    46,     0,     0,     0,    42,     0,     0,     0,
     166,     0,     0,     0,   142,     0,     0,   126,   127,   128,
     129,   132,   133,   131,   130,   134,     0,     0,     0,     0,
       0,   279,   280,   281,   282,     0,     0,     0,     0,     0,
       0,     0,     0,   654,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   303,     0,     0,   296,   297,   298,   299,     0,     0,
     325,     0,   320,   321,   322,     0,     0,   288,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   190,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,     0,     0,     0,   398,     0,
     405,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,   588,   255,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,     0,     0,     0,     0,   388,   234,     0,
       0,     0,     0,     0,   228,     0,     0,    92,     0,     0,
       0,    41,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   283,     0,     0,     0,     0,   278,     0,
       0,     0,     0,     0,     0,     0,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
     300,     0,     0,     0,     0,   295,   323,     0,     0,     0,
     319,     0,   287,    91,    90,    89,   650,   647,   646,   635,
     637,    27,    27,    27,    27,    27,    29,    28,   641,   642,
     645,   643,   648,   649,   651,   652,   644,   636,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   189,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,     0,     0,   397,   410,     0,     0,     0,   412,   495,
     499,   515,   527,   526,   584,   532,   493,   523,   529,   494,
     485,   486,   502,   491,   492,   505,   490,   504,   503,   498,
     497,   496,   524,   484,   522,   582,   583,   519,   516,   569,
     562,   579,   580,   563,   564,   565,   566,   574,   567,   577,
     581,   570,   575,   571,   576,   568,   573,   572,   578,     0,
     561,   521,   544,   538,   555,   556,   539,   540,   541,   542,
     550,   543,   553,   557,   546,   551,   547,   552,   545,   549,
     548,   554,     0,   537,   514,   517,   531,   488,   525,   489,
     518,   507,   512,   513,   510,   511,   508,   509,   501,   500,
      35,    35,    35,    37,    36,   585,   530,   533,   520,   528,
     487,   506,     0,     0,     0,     0,     0,     0,   587,     0,
       0,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,   382,     0,     0,     0,   239,   235,   238,   220,   100,
      99,     0,     0,   112,     0,     0,   104,   105,   107,   106,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,   277,   669,   664,   668,   666,   670,
     665,   667,    75,    81,    73,    77,    76,    72,    71,    69,
      70,     0,    68,    74,    80,    78,    79,     0,     0,     0,
     294,     0,     0,   318,   292,    30,    31,    32,    33,    34,
     216,   217,   210,   212,   214,   213,   211,   206,   218,   209,
     207,   208,   215,   362,   364,   365,   380,   379,   376,   372,
     373,   370,   371,   374,     0,   369,   359,   377,   378,   358,
     363,   375,   361,   360,   403,   404,   424,   425,   417,     0,
     416,   559,     0,   535,     0,    38,    39,    40,   612,   611,
       0,   610,   598,   597,   604,   603,     0,   602,   606,   605,
     258,   259,   268,   265,   270,   267,   266,   272,   269,   271,
     264,     0,   263,   257,   275,   274,   273,   256,   395,   387,
       0,   386,   394,   226,   227,   225,     0,   224,   242,   241,
       0,     0,     0,   108,     0,     0,     0,     0,   103,   141,
     139,   181,   178,   177,   170,   172,   187,   182,   185,   180,
     171,   186,   174,   183,   175,   184,   179,   173,   176,     0,
     169,   136,   138,   140,   152,   146,   163,   164,   147,   148,
     149,   150,   158,   151,   161,   165,   154,   159,   155,   160,
     153,   157,   156,   162,     0,   145,   137,   285,   286,   284,
      66,     0,   301,   307,   313,   316,   309,   315,   310,   314,
     312,   308,   311,     0,   306,   302,   324,   329,   335,   338,
     331,   337,   332,   336,   334,   330,   333,     0,   328,   367,
       0,   414,     0,   560,   536,   608,     0,   600,     0,   261,
       0,   384,     0,   222,     0,   240,   237,   236,     0,     0,
       0,     0,   102,   167,     0,   143,     0,    67,   304,     0,
     326,     0,   368,   415,   609,   601,   262,   385,   223,   109,
     118,   121,   120,   117,   122,   119,   116,     0,   115,   111,
     110,   168,   144,   305,   327,   113,     0,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   836,   837,   983,   984,    26,   254,   255,
     256,   257,    27,   290,   291,   292,   582,  1061,  1062,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      28,    74,    75,    76,    77,    78,    29,   245,   246,   247,
     248,   249,   250,  1025,  1026,  1027,  1028,  1029,  1175,  1307,
    1308,    30,    63,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   779,  1224,  1225,   555,   775,  1199,  1200,    31,
      51,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,    32,    60,   520,   759,
    1166,  1167,   521,   522,   523,  1172,  1016,  1017,   524,   525,
      33,    58,   496,   497,   498,   499,   500,   501,   502,   745,
    1151,  1152,   503,   504,   505,    34,    64,   560,   561,   562,
     563,   564,    35,   308,   309,   310,    36,    67,   593,   594,
     595,   596,   597,   812,  1243,  1244,    37,    68,   601,   602,
     603,   604,   818,  1257,  1258,    38,    52,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   654,  1104,  1105,
     391,   392,   393,   394,   395,   396,    39,    59,   510,   754,
    1160,  1161,   511,   512,   513,   514,    40,    53,   400,   401,
     402,   403,    41,   123,   124,   125,    42,    55,   411,   673,
    1119,  1120,   412,   413,   414,   415,    43,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   448,   962,
     963,   233,   446,   939,   940,   234,   235,   236,   237,    44,
      57,   479,   480,   481,   482,   483,   737,  1136,  1137,   484,
     485,   486,   734,  1130,  1131,    45,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    46,   268,   269,   270,
     271,   272,   273,   274,   275,   276
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -805
static const yytype_int16 yypact[] =
{
    -805,   700,  -805,  -174,  -240,  -237,  -805,  -805,  -805,  -225,
    -805,  -205,  -805,  -805,  -805,  -805,  -202,  -197,  -805,  -805,
    -173,  -168,  -805,  -805,  -160,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   311,
     577,  -155,  -143,  -134,    12,  -131,   380,  -125,  -117,   -83,
     -80,    74,   178,   -78,   -73,   626,   420,   -63,   -34,    13,
     -15,   -13,    38,    39,    47,  -805,  -805,  -805,  -805,  -805,
      41,    54,    60,    63,    87,    92,    95,   103,   110,   120,
     123,   128,   135,   136,   138,   139,   143,   144,   132,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   647,   494,
      22,  -805,   146,    15,  -805,  -805,   231,  -805,   147,   149,
     152,   154,   156,   157,   158,   162,   165,   167,   169,   171,
     172,   176,   180,   181,   182,   184,   185,   188,   189,   190,
     191,   199,   200,   203,   204,   209,   211,   212,  -805,   215,
    -805,   216,   217,   219,   220,   223,   225,   229,   240,   241,
     242,   243,   246,   250,   251,   256,   258,   259,   262,   263,
     266,   267,    25,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   338,   525,
      76,   273,   -12,   269,   272,    52,  -805,  -805,  -805,  -805,
      80,   153,   274,   276,     8,  -805,  -805,  -805,   304,    34,
    -805,   281,   282,   283,   284,   285,   288,   289,   109,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,   201,   290,   291,
     292,   293,   295,   296,   300,  -805,   301,   305,   306,   313,
     134,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,   265,    10,  -805,   314,    31,  -805,
    -805,  -805,   385,   416,   424,   329,  -805,   168,   460,   461,
     400,   401,   467,   467,   468,   469,   409,   412,   478,   467,
     414,   415,   417,   418,   421,   351,  -805,   355,   357,   359,
     361,   365,   366,   367,   371,   372,   373,   377,   378,   382,
     383,   198,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,   358,   386,   388,   389,
     390,   392,  -805,   394,   396,   397,   398,   399,   402,   403,
     404,   228,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   406,   427,
      18,  -805,  -805,  -805,   492,   432,  -805,  -805,   433,   434,
    -805,  -805,   100,  -805,  -805,  -805,   453,   467,   467,   526,
     513,   542,   482,   483,   557,   544,   503,   569,   570,   571,
     507,   510,   511,   467,   560,   517,   584,   587,   467,   591,
     592,   572,   594,   596,   535,   536,   470,   537,   471,   467,
     467,   540,   467,   586,   546,   547,   549,   -99,    30,   550,
     551,   467,   467,   618,   600,   467,   565,   566,   568,   580,
     516,  -805,  -805,  -805,   489,   518,  -805,   520,   523,    14,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,   530,   531,   541,
    -805,   543,   545,   552,   554,   555,   133,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,   558,  -805,   559,
    -805,    48,  -805,  -805,  -805,   533,  -805,   561,   573,   575,
    -805,     2,  -805,  -805,  -805,  -805,  -805,   603,   604,   574,
    -805,   527,  -805,   654,   656,   581,  -805,   582,   583,   585,
    -805,   588,   589,   590,  -805,   593,   107,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,   595,   597,   598,   601,
      88,  -805,  -805,  -805,  -805,   617,   619,   625,   678,   637,
     638,   467,   602,  -805,  -805,   689,   648,   694,   698,   699,
     706,   707,   605,   708,   733,   714,   715,   607,  -805,   610,
     608,  -805,   609,    37,  -805,  -805,  -805,  -805,   613,   611,
    -805,    58,  -805,  -805,  -805,   724,   616,  -805,   620,   621,
     622,  -805,   627,   629,   630,   631,   632,   327,   633,   634,
     635,   636,   643,   646,   651,   652,   658,   662,   663,   665,
     666,  -805,  -805,   747,   755,   467,   767,   784,   797,   798,
     735,   799,   809,   467,   467,   618,   680,  -805,  -805,   793,
      24,   794,   796,   760,   688,   805,   815,   816,   820,   842,
     823,   827,   831,   723,  -805,   834,   835,   727,  -805,   728,
    -805,   838,   840,   730,   732,  -805,   734,   736,   737,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   748,   749,
     750,   751,   752,   753,   754,   757,   758,   759,   761,   762,
     763,   764,   765,   766,   768,   769,   696,   770,   729,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,   783,   785,   786,   787,   312,   788,   789,   790,   791,
     792,   795,   800,  -805,   801,   467,   812,   802,   844,   864,
     803,  -805,  -805,   865,   825,   804,   876,   914,   902,   903,
     905,   806,  -805,   906,   807,   907,   808,  -805,  -805,   810,
     908,   910,   932,   811,  -805,   814,   817,  -805,   160,   818,
     819,  -805,  -805,   918,   877,   813,   924,   929,   930,   821,
     931,   826,  -805,  -805,   934,   936,   937,   829,  -805,   830,
     832,   833,   836,   837,   839,   841,  -805,   843,   845,   846,
     847,   848,   849,   850,   222,   851,   852,   853,   854,  -805,
    -805,   940,   855,   943,   856,  -805,  -805,   944,   857,   859,
    -805,   861,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,   467,   467,   467,   467,   467,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,   862,   863,   866,   867,   868,   869,   870,   871,   872,
     873,   874,   875,   878,  -805,   879,   880,   881,   882,   883,
     884,    -6,   885,   886,   887,   888,   889,   890,   891,   892,
    -805,   893,   894,  -805,  -805,   895,   896,   927,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -224,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -209,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
     618,   618,   618,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,     1,   897,   898,     6,   899,   900,  -805,   901,
     904,   718,   909,   911,   912,   913,   915,  -805,   916,   942,
     917,  -805,   -20,   919,   920,   925,   860,  -805,  -805,  -805,
    -805,   921,   922,  -805,   923,   150,  -805,  -805,  -805,  -805,
    -805,  -805,   928,   933,   529,   935,   938,   939,   756,   941,
    -805,   945,   946,   947,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -208,  -805,  -805,  -805,  -805,  -805,   948,   556,   949,
    -805,   950,   599,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -206,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -198,
    -805,  -805,   696,  -805,   729,  -805,  -805,  -805,  -805,  -805,
    -185,  -805,  -805,  -805,  -805,  -805,  -183,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -180,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -165,  -805,  -805,  -805,  -805,  -805,   -56,  -805,  -805,  -805,
     970,   932,   951,  -805,   953,   926,  -110,   952,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   -51,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,    -9,  -805,  -805,  -805,  -805,  -805,
    -805,   222,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,    72,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,    96,  -805,  -805,
      -6,  -805,   927,  -805,  -805,  -805,     1,  -805,     6,  -805,
     718,  -805,   942,  -805,   -20,  -805,  -805,  -805,   954,   393,
     955,   956,  -805,  -805,   529,  -805,   756,  -805,  -805,   556,
    -805,   599,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,   105,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,   393,  -805
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -805,  -805,  -805,  -804,  -321,  -620,  -463,  -805,  -805,   957,
    -805,  -805,  -805,  -805,   858,  -805,  -805,  -805,  -144,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  1026,  -805,  -805,  -805,  -805,  -805,   958,  -805,
    -805,  -805,  -805,  -805,    77,  -805,  -805,  -805,  -805,  -805,
    -195,  -805,  -805,  -805,   576,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -139,  -805,  -805,  -805,  -133,  -805,
    -805,  -805,   824,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -124,  -805,   642,  -805,  -805,  -805,   -19,  -805,  -805,
    -805,  -805,  -805,   657,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -115,  -805,  -805,  -805,  -805,  -805,  -805,   612,  -805,
    -805,  -805,  -805,  -805,   959,  -805,  -805,  -805,  -805,   614,
    -805,  -805,  -805,  -805,  -805,  -130,  -805,  -805,  -805,   567,
    -805,  -805,  -805,  -805,  -122,  -805,  -805,  -805,   828,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   -93,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,   -96,  -805,   668,  -805,  -805,  -805,  -805,  -805,   822,
    -805,  -805,  -805,  -805,  1054,  -805,  -805,  -805,  -805,  -805,
    -805,   -81,  -805,   960,  -805,  -805,  -805,  -805,  1000,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
      61,  -805,  -805,  -805,    65,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,   709,  -805,  -805,  -805,  -805,  -805,   -79,  -805,
    -805,  -805,  -805,  -805,   -68,  -805,  -805,  1104,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,
    -805,  -805,  -805,  -805,  -805,  -805,  -805,  -805,   961,  -805,
    -805,  -805,  -805,  -805,  -805,  -805
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     726,   618,   619,   515,  1099,   725,  1100,    49,   625,   251,
      50,   598,  1128,   121,   306,   472,   121,  1134,   473,   397,
    1101,  1121,    54,   397,  1102,  1122,   127,  1075,  1076,  1077,
    1078,  1079,   306,   128,   129,   556,  1123,  1230,   589,  1259,
    1124,  1231,    56,  1260,   130,    61,  1163,  1261,    70,   506,
      62,  1262,   131,   242,   516,   557,   132,   133,   474,   598,
    1265,   475,  1267,   134,  1266,  1269,  1268,   135,   136,  1270,
     137,    47,    48,   517,    65,   242,   138,   506,   518,    66,
    1271,   717,   718,    71,  1272,   139,   140,    69,   122,   556,
     141,   122,   118,    72,   398,   142,   677,   678,   398,   143,
     144,   407,   476,   145,   119,  1280,   146,   147,   537,   557,
     260,   252,   693,   120,   148,   599,   126,   698,   307,   477,
     149,   150,   238,   151,   152,   153,   154,   155,   709,   710,
     239,   712,   538,    79,   487,   277,   307,   519,   156,   253,
     723,   724,   590,   558,   728,    80,   157,   158,   159,   261,
     160,  1021,    73,   161,   162,   539,   399,   163,   488,   540,
     399,  1021,   262,   599,   240,    81,    82,   241,   164,   258,
     278,    83,   559,    84,   259,   263,   264,   265,   266,   251,
     600,   489,   863,  1129,   304,   490,   507,  1164,  1135,  1273,
     165,  1165,   166,  1274,  1283,   267,   167,   558,  1284,   337,
     168,   169,   170,   171,   172,   408,   279,   591,   173,   174,
     719,   720,   541,   305,   507,    85,    86,   175,   508,  1103,
     338,   339,    87,    88,   866,   867,   559,   340,   600,   366,
     311,   367,   407,   526,   368,   312,  1285,   542,   409,   280,
    1286,   281,   282,    89,    90,   478,   508,   176,   763,   177,
     795,   178,   369,   370,   535,  1022,   543,   179,    91,    92,
     740,   405,   180,   491,   667,  1022,   589,   181,   592,    93,
     410,   470,   492,   493,   515,   243,   371,   606,    94,   509,
     372,   252,   283,   814,   284,   285,   313,   314,   244,   317,
     341,   342,   343,   315,   756,   344,  -101,   243,   529,   373,
     286,   374,   318,   345,   819,   537,   494,   509,   319,   253,
     244,   320,    70,   375,   853,   346,   347,  1288,  -101,   544,
    1023,  1289,   861,   862,   531,   516,   980,   981,   982,   538,
    1023,   348,   349,   376,   787,   321,   408,   287,   545,   472,
     322,  1290,   473,   323,   517,  1291,   674,    71,   612,   518,
    1315,   324,   539,   781,  1316,   572,   540,    72,   325,   350,
    1125,  1126,  1127,   377,   495,    95,    96,    97,   326,   409,
     590,   327,   288,   289,  1059,  1060,   328,   378,   335,   751,
     587,   127,   474,   329,   330,   475,   331,   332,   128,   129,
     379,   333,   334,  1024,   404,   416,  1177,   417,   532,   130,
     418,   410,   419,  1024,   420,   421,   422,   131,   519,   541,
     423,   132,   133,   424,   993,   425,    73,   426,   134,   427,
     428,   277,   135,   136,   429,   137,   476,   725,   430,   431,
     432,   138,   433,   434,   542,   591,   435,   436,   437,   438,
     139,   140,   617,   477,   646,   141,   574,   439,   440,  1300,
     142,   441,   442,   543,   143,   144,   278,   443,   145,   444,
     445,   146,   147,   447,   449,   450,   380,   451,   452,   148,
    1301,   453,  1302,   454,   663,   149,   150,   455,   151,   152,
     153,   154,   155,   831,   832,   833,   834,   835,   456,   457,
     458,   459,   279,   156,   460,   366,   592,   367,   461,   462,
     368,   157,   158,   159,   463,   160,   464,   465,   161,   162,
     466,   467,   163,  1303,   468,   469,   544,   527,   369,   370,
     528,   608,   533,   164,   534,   280,   487,   281,   282,   565,
     566,   567,   568,   569,  1181,   545,   570,   571,   575,   576,
     577,   578,   371,   579,   580,   165,   372,   166,   581,   583,
     488,   167,   609,   584,   585,   168,   169,   170,   171,   172,
     610,   586,   605,   173,   174,   373,  1182,   374,   283,   478,
     284,   285,   175,   489,   611,   613,   614,   490,    79,   375,
     615,   616,   617,   620,   621,  1183,   286,  1304,  1305,   622,
      80,  1184,   623,   624,   626,   627,   631,   628,   629,   376,
     632,   630,   176,   648,   177,   633,   178,   634,  1185,   635,
      81,    82,   179,   636,   637,   638,    83,   180,    84,   639,
     640,   641,   181,   287,  1306,   642,   643,   260,   669,   377,
     644,   645,  1186,   676,   649,  1233,   650,   651,   652,  1187,
     653,   679,   655,   378,   656,   657,   658,   659,   337,   680,
     660,   661,   662,  1188,   665,   491,   379,   681,   288,   289,
      85,    86,   682,   683,   492,   493,   261,    87,    88,   338,
     339,  1189,   684,  1190,  1191,   666,   340,   670,  1247,   262,
     685,   671,   672,   686,   687,   688,   689,   690,    89,    90,
     691,   692,   263,   264,   265,   266,   694,   695,   494,   696,
       2,     3,   697,    91,    92,     4,   699,   700,   701,   702,
    1234,   703,   267,  1281,    93,   704,   705,   707,   706,   708,
     711,     5,   713,    94,  1192,     6,   714,   715,     7,   716,
     721,   722,   380,   725,  1193,     8,   727,   735,  1142,   341,
     342,   343,  1235,  1194,   344,   729,   730,  1195,   731,  1196,
       9,  1236,   345,  1248,    10,    11,   495,    12,  1237,  1197,
     732,   733,   919,    13,   346,   347,   736,  1143,   738,  1198,
    1238,   739,  1239,  1240,   768,   742,  1144,    14,   758,   743,
     348,   349,  1145,   765,   766,  1249,  1241,    15,    16,   744,
     769,   746,   770,   747,  1250,   942,  1242,   789,  1146,   790,
     748,  1251,   749,   750,    17,   791,   753,   755,   350,   760,
      95,    96,    97,  1252,   792,  1253,  1254,   793,   794,   767,
      18,   761,  1204,   762,  1147,   797,   771,   772,   798,  1255,
     799,   773,  1148,   774,   800,   801,   776,   777,   778,  1256,
     783,   780,   802,   803,   805,   784,   785,   796,   806,   786,
     807,   808,   809,   804,    19,   810,   811,   813,   816,   817,
     821,   822,   851,    20,    21,   823,   824,   825,    22,    23,
     852,   858,   826,  1149,   827,   828,   829,   830,   838,   839,
     840,   841,   854,   920,   921,   922,   923,   924,   842,   925,
     926,   843,  1150,   927,   928,   929,   844,   845,   930,   855,
     931,   932,   933,   846,   934,   935,   936,   847,   848,   937,
     849,   850,   856,   857,   859,   938,   943,   944,   945,   946,
     947,    24,   948,   949,   860,   864,   950,   951,   952,   865,
     868,   953,   869,   954,   955,   956,   871,   957,   958,   959,
     870,   872,   960,  1205,  1206,  1207,  1208,  1209,   961,  1210,
    1211,   873,   874,  1212,  1213,  1214,   875,   876,  1215,   877,
    1216,  1217,  1218,   878,  1219,  1220,  1221,   879,   880,  1222,
     881,   882,   883,   884,   885,  1223,   886,   888,   887,   889,
     996,   890,   891,   892,   893,   894,   895,   896,   897,   898,
     899,   900,   994,   901,   902,   903,   904,   905,   906,   907,
     997,   999,   908,   909,   910,  1000,   911,   912,   913,   914,
     915,   916,  1002,   917,   918,   941,   964,   965,   966,   967,
     968,   969,   970,   971,   972,   973,   974,   975,   976,  1003,
     977,   978,   979,   985,   986,   987,   988,   989,  1004,  1005,
     990,  1006,  1008,  1010,  1013,   991,  1014,  1015,   998,   992,
     995,  1007,  1001,  1011,  1032,  1009,  1018,  1033,  1012,  1019,
    1035,  1034,  1020,  1030,  1031,  1036,  1037,  1039,  1118,  1038,
    1041,  1040,  1042,  1043,  1044,  1045,  1067,  1046,  1047,  1069,
    1071,  1048,  1049,  1159,  1050,  1275,  1051,  1287,  1052,  1278,
    1053,  1054,  1055,  1056,  1057,  1058,  1063,  1064,  1065,  1066,
     316,  1070,  1178,  1068,  1073,  1072,  1074,  1080,  1081,  1171,
    1170,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1317,   782,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,  1117,  1132,  1133,  1138,  1139,  1140,  1312,   588,  1141,
    1298,  1311,  1276,   752,  1153,  1296,  1154,  1155,  1156,  1313,
    1157,  1158,  1162,   764,  1168,  1169,  1173,  1292,   820,  1314,
    1174,  1176,   788,  1179,  1279,   647,  1297,   406,  1180,   757,
    1201,  1293,   471,  1202,  1203,  1264,  1226,  1263,   741,  1295,
    1227,  1228,  1229,  1232,  1245,  1246,  1277,  1282,  1294,  1299,
    1309,  1310,   336,   530,     0,     0,     0,   815,     0,   664,
       0,   536,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   668,     0,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   675
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-805))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     463,   322,   323,     1,    10,   115,    12,   247,   329,     1,
     247,     1,    11,     1,     1,     1,     1,    11,     4,     1,
      26,   245,   247,     1,    30,   249,     1,   831,   832,   833,
     834,   835,     1,     8,     9,     1,   245,   245,     1,   245,
     249,   249,   247,   249,    19,   247,    66,   245,     1,     1,
     247,   249,    27,     1,    52,    21,    31,    32,    44,     1,
     245,    47,   245,    38,   249,   245,   249,    42,    43,   249,
      45,   245,   246,    71,   247,     1,    51,     1,    76,   247,
     245,   180,   181,    36,   249,    60,    61,   247,    76,     1,
      65,    76,   247,    46,    76,    70,   417,   418,    76,    74,
      75,     1,    88,    78,   247,   215,    81,    82,     1,    21,
       1,   103,   433,   247,    89,   105,   247,   438,   105,   105,
      95,    96,   247,    98,    99,   100,   101,   102,   449,   450,
     247,   452,    25,     1,     1,     1,   105,   135,   113,   131,
     461,   462,   105,   109,   465,    13,   121,   122,   123,    40,
     125,     1,   105,   128,   129,    48,   138,   132,    25,    52,
     138,     1,    53,   105,   247,    33,    34,   247,   143,   247,
      36,    39,   138,    41,   247,    66,    67,    68,    69,     1,
     170,    48,   645,   182,   247,    52,   138,   207,   182,   245,
     165,   211,   167,   249,   245,    86,   171,   109,   249,     1,
     175,   176,   177,   178,   179,   105,    72,   170,   183,   184,
     180,   181,   105,   247,   138,    83,    84,   192,   170,   225,
      22,    23,    90,    91,   200,   201,   138,    29,   170,     1,
     245,     3,     1,   245,     6,   248,   245,   130,   138,   105,
     249,   107,   108,   111,   112,   231,   170,   222,   246,   224,
     571,   226,    24,    25,   246,   105,   149,   232,   126,   127,
     246,   246,   237,   130,   246,   105,     1,   242,   231,   137,
     170,   246,   139,   140,     1,   223,    48,   246,   146,   231,
      52,   103,   148,   246,   150,   151,   248,   248,   236,   248,
      92,    93,    94,   246,   246,    97,   244,   223,   246,    71,
     166,    73,   248,   105,   246,     1,   173,   231,   248,   131,
     236,   248,     1,    85,   635,   117,   118,   245,   244,   212,
     170,   249,   643,   644,   244,    52,    14,    15,    16,    25,
     170,   133,   134,   105,   246,   248,   105,   203,   231,     1,
     248,   245,     4,   248,    71,   249,   246,    36,   180,    76,
     245,   248,    48,   246,   249,   246,    52,    46,   248,   161,
     980,   981,   982,   135,   231,   233,   234,   235,   248,   138,
     105,   248,   238,   239,   152,   153,   248,   149,   246,   246,
     246,     1,    44,   248,   248,    47,   248,   248,     8,     9,
     162,   248,   248,   243,   248,   248,   246,   248,   245,    19,
     248,   170,   248,   243,   248,   248,   248,    27,   135,   105,
     248,    31,    32,   248,   735,   248,   105,   248,    38,   248,
     248,     1,    42,    43,   248,    45,    88,   115,   248,   248,
     248,    51,   248,   248,   130,   170,   248,   248,   248,   248,
      60,    61,   115,   105,   246,    65,   245,   248,   248,    56,
      70,   248,   248,   149,    74,    75,    36,   248,    78,   248,
     248,    81,    82,   248,   248,   248,   238,   248,   248,    89,
      77,   248,    79,   248,   246,    95,    96,   248,    98,    99,
     100,   101,   102,   156,   157,   158,   159,   160,   248,   248,
     248,   248,    72,   113,   248,     1,   231,     3,   248,   248,
       6,   121,   122,   123,   248,   125,   248,   248,   128,   129,
     248,   248,   132,   120,   248,   248,   212,   248,    24,    25,
     248,   136,   248,   143,   248,   105,     1,   107,   108,   248,
     248,   248,   248,   248,     5,   231,   248,   248,   248,   248,
     248,   248,    48,   248,   248,   165,    52,   167,   248,   248,
      25,   171,   136,   248,   248,   175,   176,   177,   178,   179,
     136,   248,   248,   183,   184,    71,    37,    73,   148,   231,
     150,   151,   192,    48,   245,   115,   115,    52,     1,    85,
     180,   180,   115,   115,   115,    56,   166,   194,   195,   180,
      13,    62,   180,   115,   180,   180,   245,   180,   180,   105,
     245,   180,   222,   245,   224,   248,   226,   248,    79,   248,
      33,    34,   232,   248,   248,   248,    39,   237,    41,   248,
     248,   248,   242,   203,   231,   248,   248,     1,   136,   135,
     248,   248,   103,   180,   248,    79,   248,   248,   248,   110,
     248,   115,   248,   149,   248,   248,   248,   248,     1,   136,
     248,   248,   248,   124,   248,   130,   162,   115,   238,   239,
      83,    84,   180,   180,   139,   140,    40,    90,    91,    22,
      23,   142,   115,   144,   145,   248,    29,   245,    79,    53,
     136,   248,   248,   180,   115,   115,   115,   180,   111,   112,
     180,   180,    66,    67,    68,    69,   136,   180,   173,   115,
       0,     1,   115,   126,   127,     5,   115,   115,   136,   115,
     154,   115,    86,  1176,   137,   180,   180,   180,   248,   248,
     180,    21,   136,   146,   195,    25,   180,   180,    28,   180,
     180,   180,   238,   115,   205,    35,   136,   248,    20,    92,
      93,    94,   186,   214,    97,   180,   180,   218,   180,   220,
      50,   195,   105,   154,    54,    55,   231,    57,   202,   230,
     180,   245,    66,    63,   117,   118,   248,    49,   248,   240,
     214,   248,   216,   217,   247,   245,    58,    77,   245,   248,
     133,   134,    64,   180,   180,   186,   230,    87,    88,   248,
     136,   248,   136,   248,   195,    66,   240,   180,    80,   180,
     248,   202,   248,   248,   104,   180,   248,   248,   161,   248,
     233,   234,   235,   214,   136,   216,   217,   180,   180,   245,
     120,   248,    66,   248,   106,   136,   245,   245,   180,   230,
     136,   248,   114,   248,   136,   136,   248,   248,   248,   240,
     245,   248,   136,   136,   136,   248,   248,   245,   115,   248,
     136,   136,   245,   248,   154,   245,   248,   248,   245,   248,
     136,   245,   115,   163,   164,   245,   245,   245,   168,   169,
     115,   136,   245,   155,   245,   245,   245,   245,   245,   245,
     245,   245,   115,   187,   188,   189,   190,   191,   245,   193,
     194,   245,   174,   197,   198,   199,   245,   245,   202,   115,
     204,   205,   206,   245,   208,   209,   210,   245,   245,   213,
     245,   245,   115,   115,   115,   219,   187,   188,   189,   190,
     191,   221,   193,   194,   115,   245,   197,   198,   199,   136,
     136,   202,   136,   204,   205,   206,   248,   208,   209,   210,
     180,   136,   213,   187,   188,   189,   190,   191,   219,   193,
     194,   136,   136,   197,   198,   199,   136,   115,   202,   136,
     204,   205,   206,   136,   208,   209,   210,   136,   245,   213,
     136,   136,   245,   245,   136,   219,   136,   245,   248,   245,
     136,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   180,   245,   245,   245,   245,   245,   245,   245,
     136,   136,   245,   245,   245,   180,   245,   245,   245,   245,
     245,   245,   136,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   115,
     245,   245,   245,   245,   245,   245,   245,   245,   136,   136,
     245,   136,   136,   136,   136,   245,   136,   115,   245,   248,
     248,   245,   248,   245,   136,   248,   245,   180,   248,   245,
     136,   248,   245,   245,   245,   136,   136,   136,   141,   248,
     136,   245,   136,   136,   245,   245,   136,   245,   245,   136,
     136,   245,   245,   141,   245,   115,   245,  1231,   245,   136,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
      74,   245,  1025,   248,   245,   248,   245,   245,   245,   249,
     185,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,  1316,   546,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,  1286,   290,   245,
    1274,  1284,  1171,   496,   245,  1270,   245,   245,   245,  1289,
     245,   245,   245,   521,   245,   245,   245,  1260,   601,  1291,
     248,   248,   560,   245,   248,   351,  1272,   123,   245,   511,
     245,  1262,   182,   245,   245,  1124,   245,  1122,   479,  1268,
     245,   245,   245,   245,   245,   245,   245,   245,  1266,   245,
     245,   245,    98,   245,    -1,    -1,    -1,   593,    -1,   381,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   400,    -1,    -1,    -1,    -1,    -1,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   251,     0,     1,     5,    21,    25,    28,    35,    50,
      54,    55,    57,    63,    77,    87,    88,   104,   120,   154,
     163,   164,   168,   169,   221,   252,   257,   262,   280,   286,
     301,   319,   336,   350,   365,   372,   376,   386,   395,   416,
     426,   432,   436,   446,   509,   525,   546,   245,   246,   247,
     247,   320,   396,   427,   247,   437,   247,   510,   351,   417,
     337,   247,   247,   302,   366,   247,   247,   377,   387,   247,
       1,    36,    46,   105,   281,   282,   283,   284,   285,     1,
      13,    33,    34,    39,    41,    83,    84,    90,    91,   111,
     112,   126,   127,   137,   146,   233,   234,   235,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   247,   247,
     247,     1,    76,   433,   434,   435,   247,     1,     8,     9,
      19,    27,    31,    32,    38,    42,    43,    45,    51,    60,
      61,    65,    70,    74,    75,    78,    81,    82,    89,    95,
      96,    98,    99,   100,   101,   102,   113,   121,   122,   123,
     125,   128,   129,   132,   143,   165,   167,   171,   175,   176,
     177,   178,   179,   183,   184,   192,   222,   224,   226,   232,
     237,   242,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   501,   505,   506,   507,   508,   247,   247,
     247,   247,     1,   223,   236,   287,   288,   289,   290,   291,
     292,     1,   103,   131,   258,   259,   260,   261,   247,   247,
       1,    40,    53,    66,    67,    68,    69,    86,   547,   548,
     549,   550,   551,   552,   553,   554,   555,     1,    36,    72,
     105,   107,   108,   148,   150,   151,   166,   203,   238,   239,
     263,   264,   265,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   247,   247,     1,   105,   373,   374,
     375,   245,   248,   248,   248,   246,   282,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   246,   527,     1,    22,    23,
      29,    92,    93,    94,    97,   105,   117,   118,   133,   134,
     161,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,     1,     3,     6,    24,
      25,    48,    52,    71,    73,    85,   105,   135,   149,   162,
     238,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   410,   411,   412,   413,   414,   415,     1,    76,   138,
     428,   429,   430,   431,   248,   246,   434,     1,   105,   138,
     170,   438,   442,   443,   444,   445,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   502,   248,   498,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     246,   448,     1,     4,    44,    47,    88,   105,   231,   511,
     512,   513,   514,   515,   519,   520,   521,     1,    25,    48,
      52,   130,   139,   140,   173,   231,   352,   353,   354,   355,
     356,   357,   358,   362,   363,   364,     1,   138,   170,   231,
     418,   422,   423,   424,   425,     1,    52,    71,    76,   135,
     338,   342,   343,   344,   348,   349,   245,   248,   248,   246,
     288,   244,   245,   248,   248,   246,   259,     1,    25,    48,
      52,   105,   130,   149,   212,   231,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   315,     1,    21,   109,   138,
     367,   368,   369,   370,   371,   248,   248,   248,   248,   248,
     248,   248,   246,   548,   245,   248,   248,   248,   248,   248,
     248,   248,   266,   248,   248,   248,   248,   246,   264,     1,
     105,   170,   231,   378,   379,   380,   381,   382,     1,   105,
     170,   388,   389,   390,   391,   248,   246,   374,   136,   136,
     136,   245,   180,   115,   115,   180,   180,   115,   254,   254,
     115,   115,   180,   180,   115,   254,   180,   180,   180,   180,
     180,   245,   245,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   246,   322,   245,   248,
     248,   248,   248,   248,   407,   248,   248,   248,   248,   248,
     248,   248,   248,   246,   398,   248,   248,   246,   429,   136,
     245,   248,   248,   439,   246,   443,   180,   254,   254,   115,
     136,   115,   180,   180,   115,   136,   180,   115,   115,   115,
     180,   180,   180,   254,   136,   180,   115,   115,   254,   115,
     115,   136,   115,   115,   180,   180,   248,   180,   248,   254,
     254,   180,   254,   136,   180,   180,   180,   180,   181,   180,
     181,   180,   180,   254,   254,   115,   256,   136,   254,   180,
     180,   180,   180,   245,   522,   248,   248,   516,   248,   248,
     246,   512,   245,   248,   248,   359,   248,   248,   248,   248,
     248,   246,   353,   248,   419,   248,   246,   423,   245,   339,
     248,   248,   248,   246,   343,   180,   180,   245,   247,   136,
     136,   245,   245,   248,   248,   316,   248,   248,   248,   312,
     248,   246,   304,   245,   248,   248,   248,   246,   368,   180,
     180,   180,   136,   180,   180,   254,   245,   136,   180,   136,
     136,   136,   136,   136,   248,   136,   115,   136,   136,   245,
     245,   248,   383,   248,   246,   379,   245,   248,   392,   246,
     389,   136,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   156,   157,   158,   159,   160,   253,   254,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   115,   115,   254,   115,   115,   115,   115,   136,   115,
     115,   254,   254,   256,   245,   136,   200,   201,   136,   136,
     180,   248,   136,   136,   136,   136,   115,   136,   136,   136,
     245,   136,   136,   245,   245,   136,   136,   248,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,    66,
     187,   188,   189,   190,   191,   193,   194,   197,   198,   199,
     202,   204,   205,   206,   208,   209,   210,   213,   219,   503,
     504,   245,    66,   187,   188,   189,   190,   191,   193,   194,
     197,   198,   199,   202,   204,   205,   206,   208,   209,   210,
     213,   219,   499,   500,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
      14,    15,    16,   255,   256,   245,   245,   245,   245,   245,
     245,   245,   248,   254,   180,   248,   136,   136,   245,   136,
     180,   248,   136,   115,   136,   136,   136,   245,   136,   248,
     136,   245,   248,   136,   136,   115,   346,   347,   245,   245,
     245,     1,   105,   170,   243,   293,   294,   295,   296,   297,
     245,   245,   136,   180,   248,   136,   136,   136,   248,   136,
     245,   136,   136,   136,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   152,
     153,   267,   268,   245,   245,   245,   245,   136,   248,   136,
     245,   136,   248,   245,   245,   253,   253,   253,   253,   253,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,    10,
      12,    26,    30,   225,   408,   409,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   141,   440,
     441,   245,   249,   245,   249,   255,   255,   255,    11,   182,
     523,   524,   245,   245,    11,   182,   517,   518,   245,   245,
     245,   245,    20,    49,    58,    64,    80,   106,   114,   155,
     174,   360,   361,   245,   245,   245,   245,   245,   245,   141,
     420,   421,   245,    66,   207,   211,   340,   341,   245,   245,
     185,   249,   345,   245,   248,   298,   248,   246,   294,   245,
     245,     5,    37,    56,    62,    79,   103,   110,   124,   142,
     144,   145,   195,   205,   214,   218,   220,   230,   240,   317,
     318,   245,   245,   245,    66,   187,   188,   189,   190,   191,
     193,   194,   197,   198,   199,   202,   204,   205,   206,   208,
     209,   210,   213,   219,   313,   314,   245,   245,   245,   245,
     245,   249,   245,    79,   154,   186,   195,   202,   214,   216,
     217,   230,   240,   384,   385,   245,   245,    79,   154,   186,
     195,   202,   214,   216,   217,   230,   240,   393,   394,   245,
     249,   245,   249,   504,   500,   245,   249,   245,   249,   245,
     249,   245,   249,   245,   249,   115,   347,   245,   136,   248,
     215,   256,   245,   245,   249,   245,   249,   268,   245,   249,
     245,   249,   409,   441,   524,   518,   361,   421,   341,   245,
      56,    77,    79,   120,   194,   195,   231,   299,   300,   245,
     245,   318,   314,   385,   394,   245,   249,   300
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
  if (conf_parser_ctx.pass == 2 && ltype > 0)
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
#line 840 "ircd_parser.y"
    {
  lsize = 0;
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 845 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 852 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 856 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 860 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 864 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 868 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 872 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 876 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 886 "ircd_parser.y"
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

  case 124:

/* Line 1806 of yacc.c  */
#line 899 "ircd_parser.y"
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

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->ipnum,
                                     &new_aconf->bits);

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

  case 136:

/* Line 1806 of yacc.c  */
#line 989 "ircd_parser.y"
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

  case 137:

/* Line 1806 of yacc.c  */
#line 1001 "ircd_parser.y"
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

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->ipnum,
                                    &yy_aconf->bits);
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

  case 138:

/* Line 1806 of yacc.c  */
#line 1038 "ircd_parser.y"
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

  case 139:

/* Line 1806 of yacc.c  */
#line 1050 "ircd_parser.y"
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1061 "ircd_parser.y"
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1103 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1112 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1127 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1147 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1151 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1155 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1159 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1163 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1167 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1171 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1175 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1179 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1183 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1187 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1191 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1195 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1201 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1208 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1212 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1216 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1220 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1224 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1228 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1232 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1236 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1240 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1244 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1248 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1252 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1256 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1260 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1264 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1268 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1272 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1276 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1286 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1293 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, NULL, yy_class_name, NULL, NULL);

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

  case 206:

/* Line 1806 of yacc.c  */
#line 1351 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1360 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1366 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1372 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1384 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1390 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1396 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1402 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1408 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1414 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1420 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1426 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1435 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1442 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1451 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1457 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1461 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1475 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1480 "ircd_parser.y"
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

  case 240:

/* Line 1806 of yacc.c  */
#line 1494 "ircd_parser.y"
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

  case 241:

/* Line 1806 of yacc.c  */
#line 1514 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1523 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 243:

/* Line 1806 of yacc.c  */
#line 1535 "ircd_parser.y"
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

  case 244:

/* Line 1806 of yacc.c  */
#line 1547 "ircd_parser.y"
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

  case 256:

/* Line 1806 of yacc.c  */
#line 1609 "ircd_parser.y"
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

  case 257:

/* Line 1806 of yacc.c  */
#line 1646 "ircd_parser.y"
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

  case 258:

/* Line 1806 of yacc.c  */
#line 1659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 259:

/* Line 1806 of yacc.c  */
#line 1668 "ircd_parser.y"
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

  case 260:

/* Line 1806 of yacc.c  */
#line 1679 "ircd_parser.y"
    {
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1684 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1688 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1692 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1696 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1700 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1704 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1708 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1712 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1716 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1723 "ircd_parser.y"
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

  case 274:

/* Line 1806 of yacc.c  */
#line 1742 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1752 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1765 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1772 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1784 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1793 "ircd_parser.y"
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

  case 286:

/* Line 1806 of yacc.c  */
#line 1808 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1826 "ircd_parser.y"
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

  case 293:

/* Line 1806 of yacc.c  */
#line 1841 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1849 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1860 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1869 "ircd_parser.y"
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

  case 303:

/* Line 1806 of yacc.c  */
#line 1891 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1898 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1906 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1910 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1914 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1918 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1922 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1926 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1930 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1934 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1943 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1950 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1963 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1969 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1980 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1984 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1988 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1992 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1996 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2000 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2004 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2008 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2012 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2021 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = map_to_conf(yy_conf);

    /* defaults */
    yy_aconf->port = PORTNUM;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2036 "ircd_parser.y"
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

  case 358:

/* Line 1806 of yacc.c  */
#line 2173 "ircd_parser.y"
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

  case 359:

/* Line 1806 of yacc.c  */
#line 2185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 360:

/* Line 1806 of yacc.c  */
#line 2194 "ircd_parser.y"
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

  case 361:

/* Line 1806 of yacc.c  */
#line 2220 "ircd_parser.y"
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

  case 362:

/* Line 1806 of yacc.c  */
#line 2238 "ircd_parser.y"
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

  case 363:

/* Line 1806 of yacc.c  */
#line 2256 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 2262 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2266 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 2274 "ircd_parser.y"
    {
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2279 "ircd_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2289 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2293 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2297 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2301 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2307 "ircd_parser.y"
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

  case 376:

/* Line 1806 of yacc.c  */
#line 2348 "ircd_parser.y"
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

  case 377:

/* Line 1806 of yacc.c  */
#line 2359 "ircd_parser.y"
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

  case 378:

/* Line 1806 of yacc.c  */
#line 2372 "ircd_parser.y"
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

  case 379:

/* Line 1806 of yacc.c  */
#line 2385 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2394 "ircd_parser.y"
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

  case 381:

/* Line 1806 of yacc.c  */
#line 2429 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2436 "ircd_parser.y"
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

  case 383:

/* Line 1806 of yacc.c  */
#line 2492 "ircd_parser.y"
    {
}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2497 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 2506 "ircd_parser.y"
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

  case 395:

/* Line 1806 of yacc.c  */
#line 2525 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 2534 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2538 "ircd_parser.y"
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

  case 403:

/* Line 1806 of yacc.c  */
#line 2560 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 2566 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 2580 "ircd_parser.y"
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

  case 411:

/* Line 1806 of yacc.c  */
#line 2598 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 2605 "ircd_parser.y"
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

  case 413:

/* Line 1806 of yacc.c  */
#line 2645 "ircd_parser.y"
    {
}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 2650 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 2659 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 2665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2710 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2715 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2720 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2725 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2730 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2735 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2740 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2745 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2750 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2755 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2760 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2765 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2770 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2775 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2780 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2785 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2790 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2795 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2801 "ircd_parser.y"
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

  case 503:

/* Line 1806 of yacc.c  */
#line 2812 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2817 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2826 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2831 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2836 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2841 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2846 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2851 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2854 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2859 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2862 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2867 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2872 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2877 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2882 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2887 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2892 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2902 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2907 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2918 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2923 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2928 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2937 "ircd_parser.y"
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

  case 527:

/* Line 1806 of yacc.c  */
#line 2969 "ircd_parser.y"
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

  case 528:

/* Line 1806 of yacc.c  */
#line 2987 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2992 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 3001 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3010 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3015 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3020 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3025 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3031 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3034 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3037 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3043 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3046 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3049 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3052 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3055 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3058 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3061 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3064 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3067 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3070 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3073 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3076 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3079 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3082 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3085 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3088 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3093 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3099 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3102 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3105 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3108 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3111 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3114 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3117 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3120 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3123 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3126 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3129 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3132 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3135 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3138 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3141 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3144 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3147 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3150 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3153 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3156 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3161 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3166 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3171 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3176 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3192 "ircd_parser.y"
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

  case 597:

/* Line 1806 of yacc.c  */
#line 3218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3224 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3240 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3246 "ircd_parser.y"
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

  case 606:

/* Line 1806 of yacc.c  */
#line 3280 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3289 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3293 "ircd_parser.y"
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

  case 611:

/* Line 1806 of yacc.c  */
#line 3340 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3344 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3368 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3378 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3383 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3388 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3393 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3398 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3403 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3408 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3413 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3418 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3423 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3428 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3433 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3438 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3443 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3448 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3453 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3472 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3478 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3484 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3493 "ircd_parser.y"
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

  case 668:

/* Line 1806 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3513 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3519 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7854 "ircd_parser.c"
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



