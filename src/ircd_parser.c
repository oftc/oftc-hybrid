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
     T_UNLIMITED = 469,
     T_UNRESV = 470,
     T_UNXLINE = 471,
     T_GLOBOPS = 472,
     T_WALLOP = 473,
     T_RESTART = 474,
     T_SERVICE = 475,
     T_SERVICES_NAME = 476,
     T_TIMESTAMP = 477,
     THROTTLE_TIME = 478,
     TOPICBURST = 479,
     TRUE_NO_OPER_FLOOD = 480,
     TKLINE = 481,
     TXLINE = 482,
     TRESV = 483,
     UNKLINE = 484,
     USER = 485,
     USE_EGD = 486,
     USE_EXCEPT = 487,
     USE_INVEX = 488,
     USE_KNOCK = 489,
     USE_LOGGING = 490,
     USE_WHOIS_ACTUALLY = 491,
     VHOST = 492,
     VHOST6 = 493,
     XLINE = 494,
     WARN = 495,
     WARN_NO_NLINE = 496,
     T_SIZE = 497,
     T_FILE = 498
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
#define T_UNLIMITED 469
#define T_UNRESV 470
#define T_UNXLINE 471
#define T_GLOBOPS 472
#define T_WALLOP 473
#define T_RESTART 474
#define T_SERVICE 475
#define T_SERVICES_NAME 476
#define T_TIMESTAMP 477
#define THROTTLE_TIME 478
#define TOPICBURST 479
#define TRUE_NO_OPER_FLOOD 480
#define TKLINE 481
#define TXLINE 482
#define TRESV 483
#define UNKLINE 484
#define USER 485
#define USE_EGD 486
#define USE_EXCEPT 487
#define USE_INVEX 488
#define USE_KNOCK 489
#define USE_LOGGING 490
#define USE_WHOIS_ACTUALLY 491
#define VHOST 492
#define VHOST6 493
#define XLINE 494
#define WARN 495
#define WARN_NO_NLINE 496
#define T_SIZE 497
#define T_FILE 498




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 708 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 720 "ircd_parser.c"

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
#define YYLAST   1351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1318

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   498

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   244,
       2,   247,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   246,     2,   245,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243
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
     514,   516,   518,   520,   522,   524,   526,   527,   534,   537,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   557,
     559,   561,   563,   565,   568,   573,   578,   583,   588,   593,
     598,   603,   608,   613,   618,   623,   628,   633,   634,   641,
     642,   648,   652,   654,   656,   658,   660,   663,   665,   667,
     669,   671,   673,   676,   677,   683,   687,   689,   691,   695,
     700,   705,   706,   713,   716,   718,   720,   722,   724,   726,
     728,   730,   732,   734,   737,   742,   747,   752,   757,   758,
     764,   768,   770,   772,   774,   776,   778,   780,   782,   784,
     786,   788,   793,   798,   803,   804,   811,   814,   816,   818,
     820,   822,   825,   830,   835,   840,   846,   849,   851,   853,
     855,   860,   861,   868,   871,   873,   875,   877,   879,   882,
     887,   892,   893,   899,   903,   905,   907,   909,   911,   913,
     915,   917,   919,   921,   923,   925,   927,   928,   935,   938,
     940,   942,   944,   947,   952,   953,   959,   963,   965,   967,
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
     250,     0,    -1,    -1,   250,   251,    -1,   279,    -1,   285,
      -1,   300,    -1,   524,    -1,   318,    -1,   335,    -1,   349,
      -1,   261,    -1,   545,    -1,   364,    -1,   371,    -1,   375,
      -1,   385,    -1,   394,    -1,   415,    -1,   425,    -1,   431,
      -1,   445,    -1,   508,    -1,   435,    -1,   256,    -1,     1,
     244,    -1,     1,   245,    -1,    -1,   253,    -1,   115,   252,
      -1,   115,   156,   252,    -1,   115,   157,   252,    -1,   115,
     158,   252,    -1,   115,   159,   252,    -1,   115,   160,   252,
      -1,    -1,   255,    -1,   115,   254,    -1,   115,    14,   254,
      -1,   115,    15,   254,    -1,   115,    16,   254,    -1,   104,
     246,   257,   245,   244,    -1,   257,   258,    -1,   258,    -1,
     259,    -1,   260,    -1,     1,   244,    -1,   103,   247,   136,
     244,    -1,   131,   247,   136,   244,    -1,   164,   246,   262,
     245,   244,    -1,   262,   263,    -1,   263,    -1,   270,    -1,
     275,    -1,   278,    -1,   272,    -1,   273,    -1,   274,    -1,
     277,    -1,   269,    -1,   276,    -1,   271,    -1,   268,    -1,
     264,    -1,     1,   244,    -1,    -1,   151,   265,   247,   266,
     244,    -1,   266,   248,   267,    -1,   267,    -1,   152,    -1,
     153,    -1,   150,   247,   136,   244,    -1,   148,   247,   136,
     244,    -1,   105,   247,   136,   244,    -1,   166,   247,   136,
     244,    -1,    36,   247,   136,   244,    -1,   108,   247,   136,
     244,    -1,   107,   247,   136,   244,    -1,   237,   247,   136,
     244,    -1,   238,   247,   136,   244,    -1,   203,   247,   115,
     244,    -1,    72,   247,   180,   244,    -1,     5,   246,   280,
     245,   244,    -1,   280,   281,    -1,   281,    -1,   282,    -1,
     284,    -1,   283,    -1,     1,   244,    -1,   105,   247,   136,
     244,    -1,    46,   247,   136,   244,    -1,    36,   247,   136,
     244,    -1,    88,   246,   286,   245,   244,    -1,   286,   287,
      -1,   287,    -1,   288,    -1,   289,    -1,   290,    -1,     1,
     244,    -1,   235,   247,   180,   244,    -1,   222,   247,   180,
     244,    -1,    -1,   291,   243,   246,   292,   245,   244,    -1,
     292,   293,    -1,   293,    -1,   294,    -1,   296,    -1,   295,
      -1,     1,   244,    -1,   105,   247,   136,   244,    -1,   242,
     247,   255,   244,    -1,   242,   247,   214,   244,    -1,    -1,
     170,   297,   247,   298,   244,    -1,   298,   248,   299,    -1,
     299,    -1,   230,    -1,   120,    -1,    56,    -1,   195,    -1,
      79,    -1,    77,    -1,   194,    -1,    -1,   120,   301,   246,
     302,   245,   244,    -1,   302,   303,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   310,    -1,   309,    -1,   307,
      -1,   308,    -1,   314,    -1,     1,   244,    -1,   105,   247,
     136,   244,    -1,   230,   247,   136,   244,    -1,   130,   247,
     136,   244,    -1,    48,   247,   180,   244,    -1,   149,   247,
     136,   244,    -1,    25,   247,   136,   244,    -1,    -1,   212,
     311,   247,   312,   244,    -1,   312,   248,   313,    -1,   313,
      -1,   187,    -1,   190,    -1,   191,    -1,   193,    -1,   194,
      -1,   198,    -1,    66,    -1,   209,    -1,   204,    -1,   206,
      -1,   213,    -1,   210,    -1,   197,    -1,   205,    -1,   208,
      -1,   199,    -1,   218,    -1,   188,    -1,   189,    -1,   202,
      -1,    -1,    52,   315,   247,   316,   244,    -1,   316,   248,
     317,    -1,   317,    -1,    62,    -1,   144,    -1,    79,    -1,
     229,    -1,   239,    -1,    56,    -1,    37,    -1,   219,    -1,
     142,    -1,     5,    -1,   110,    -1,   205,    -1,   217,    -1,
     124,    -1,   145,    -1,   103,    -1,    -1,    25,   319,   246,
     320,   245,   244,    -1,   320,   321,    -1,   321,    -1,   322,
      -1,   332,    -1,   333,    -1,   323,    -1,   324,    -1,   334,
      -1,   325,    -1,   326,    -1,   327,    -1,   328,    -1,   329,
      -1,   330,    -1,   331,    -1,     1,   244,    -1,   105,   247,
     136,   244,    -1,   133,   247,   253,   244,    -1,   134,   247,
     253,   244,    -1,   118,   247,   115,   244,    -1,    29,   247,
     253,   244,    -1,    97,   247,   115,   244,    -1,    92,   247,
     115,   244,    -1,    94,   247,   115,   244,    -1,    93,   247,
     115,   244,    -1,   161,   247,   255,   244,    -1,    22,   247,
     115,   244,    -1,    23,   247,   115,   244,    -1,   117,   247,
     115,   244,    -1,    -1,    87,   336,   246,   341,   245,   244,
      -1,    -1,    52,   338,   247,   339,   244,    -1,   339,   248,
     340,    -1,   340,    -1,   211,    -1,    66,    -1,   207,    -1,
     341,   342,    -1,   342,    -1,   343,    -1,   337,    -1,   347,
      -1,   348,    -1,     1,   244,    -1,    -1,   135,   247,   345,
     344,   244,    -1,   345,   248,   346,    -1,   346,    -1,   115,
      -1,   115,   185,   115,    -1,    76,   247,   136,   244,    -1,
      71,   247,   136,   244,    -1,    -1,    63,   350,   246,   351,
     245,   244,    -1,   351,   352,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   357,    -1,   361,    -1,   362,    -1,
     363,    -1,   356,    -1,     1,   244,    -1,   230,   247,   136,
     244,    -1,   130,   247,   136,   244,    -1,    25,   247,   136,
     244,    -1,    48,   247,   180,   244,    -1,    -1,    52,   358,
     247,   359,   244,    -1,   359,   248,   360,    -1,   360,    -1,
     174,    -1,    49,    -1,    80,    -1,    64,    -1,    20,    -1,
     114,    -1,    58,    -1,   155,    -1,   106,    -1,   173,   247,
     136,   244,    -1,   140,   247,   136,   244,    -1,   139,   247,
     115,   244,    -1,    -1,   154,   365,   246,   366,   245,   244,
      -1,   366,   367,    -1,   367,    -1,   368,    -1,   369,    -1,
     370,    -1,     1,   244,    -1,   138,   247,   136,   244,    -1,
      21,   247,   136,   244,    -1,   109,   247,   136,   244,    -1,
     220,   246,   372,   245,   244,    -1,   372,   373,    -1,   373,
      -1,   374,    -1,     1,    -1,   105,   247,   136,   244,    -1,
      -1,   168,   376,   246,   377,   245,   244,    -1,   377,   378,
      -1,   378,    -1,   379,    -1,   380,    -1,   381,    -1,     1,
     244,    -1,   105,   247,   136,   244,    -1,   230,   247,   136,
     244,    -1,    -1,   170,   382,   247,   383,   244,    -1,   383,
     248,   384,    -1,   384,    -1,    79,    -1,   226,    -1,   229,
      -1,   239,    -1,   227,    -1,   216,    -1,   154,    -1,   228,
      -1,   215,    -1,   202,    -1,   186,    -1,    -1,   169,   386,
     246,   387,   245,   244,    -1,   387,   388,    -1,   388,    -1,
     389,    -1,   390,    -1,     1,   244,    -1,   105,   247,   136,
     244,    -1,    -1,   170,   391,   247,   392,   244,    -1,   392,
     248,   393,    -1,   393,    -1,    79,    -1,   226,    -1,   229,
      -1,   239,    -1,   227,    -1,   216,    -1,   154,    -1,   228,
      -1,   215,    -1,   202,    -1,   186,    -1,    -1,    28,   395,
     246,   396,   245,   244,    -1,   396,   397,    -1,   397,    -1,
     398,    -1,   399,    -1,   400,    -1,   401,    -1,   402,    -1,
     404,    -1,   403,    -1,   405,    -1,   411,    -1,   412,    -1,
     413,    -1,   410,    -1,   409,    -1,   414,    -1,     1,   244,
      -1,   105,   247,   136,   244,    -1,    71,   247,   136,   244,
      -1,   237,   247,   136,   244,    -1,   162,   247,   136,   244,
      -1,     3,   247,   136,   244,    -1,   135,   247,   115,   244,
      -1,     6,   247,   200,   244,    -1,     6,   247,   201,   244,
      -1,    -1,    52,   406,   247,   407,   244,    -1,   407,   248,
     408,    -1,   408,    -1,    26,    -1,    30,    -1,    10,    -1,
      12,    -1,   224,    -1,   149,   247,   136,   244,    -1,    48,
     247,   180,   244,    -1,    73,   247,   136,   244,    -1,    85,
     247,   136,   244,    -1,    25,   247,   136,   244,    -1,    24,
     247,   136,   244,    -1,    -1,    77,   416,   246,   421,   245,
     244,    -1,    -1,   170,   418,   247,   419,   244,    -1,   419,
     248,   420,    -1,   420,    -1,   141,    -1,   421,   422,    -1,
     422,    -1,   423,    -1,   424,    -1,   417,    -1,     1,    -1,
     230,   247,   136,   244,    -1,   138,   247,   136,   244,    -1,
      -1,    35,   426,   246,   427,   245,   244,    -1,   427,   428,
      -1,   428,    -1,   429,    -1,   430,    -1,     1,    -1,    76,
     247,   136,   244,    -1,   138,   247,   136,   244,    -1,    50,
     246,   432,   245,   244,    -1,   432,   433,    -1,   433,    -1,
     434,    -1,     1,    -1,    76,   247,   136,   244,    -1,    -1,
      54,   436,   246,   441,   245,   244,    -1,    -1,   170,   438,
     247,   439,   244,    -1,   439,   248,   440,    -1,   440,    -1,
     141,    -1,   441,   442,    -1,   442,    -1,   443,    -1,   444,
      -1,   437,    -1,     1,    -1,   105,   247,   136,   244,    -1,
     138,   247,   136,   244,    -1,    55,   246,   446,   245,   244,
      -1,   446,   447,    -1,   447,    -1,   455,    -1,   456,    -1,
     458,    -1,   459,    -1,   460,    -1,   461,    -1,   462,    -1,
     463,    -1,   464,    -1,   465,    -1,   454,    -1,   467,    -1,
     468,    -1,   469,    -1,   470,    -1,   485,    -1,   472,    -1,
     474,    -1,   476,    -1,   475,    -1,   479,    -1,   473,    -1,
     480,    -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,
     500,    -1,   486,    -1,   490,    -1,   491,    -1,   496,    -1,
     477,    -1,   478,    -1,   506,    -1,   504,    -1,   505,    -1,
     487,    -1,   457,    -1,   488,    -1,   489,    -1,   507,    -1,
     495,    -1,   466,    -1,   493,    -1,   494,    -1,   453,    -1,
     449,    -1,   450,    -1,   451,    -1,   452,    -1,   471,    -1,
     448,    -1,   492,    -1,     1,    -1,    99,   247,   115,   244,
      -1,    60,   247,   115,   244,    -1,    61,   247,   115,   244,
      -1,   236,   247,   180,   244,    -1,   143,   247,   253,   244,
      -1,   167,   247,   180,   244,    -1,    78,   247,   253,   244,
      -1,    70,   247,   180,   244,    -1,    74,   247,   180,   244,
      -1,    42,   247,   180,   244,    -1,    51,   247,   180,   244,
      -1,     8,   247,   180,   244,    -1,    96,   247,   253,   244,
      -1,    95,   247,   115,   244,    -1,    89,   247,   115,   244,
      -1,     9,   247,   253,   244,    -1,   184,   247,   253,   244,
      -1,   183,   247,   253,   244,    -1,    65,   247,   115,   244,
      -1,    82,   247,   180,   244,    -1,    81,   247,   136,   244,
      -1,    75,   247,   180,   244,    -1,   241,   247,   180,   244,
      -1,   175,   247,   180,   244,    -1,   178,   247,   180,   244,
      -1,   179,   247,   180,   244,    -1,   177,   247,   180,   244,
      -1,   177,   247,   181,   244,    -1,   176,   247,   180,   244,
      -1,   176,   247,   181,   244,    -1,   128,   247,   253,   244,
      -1,    19,   247,   253,   244,    -1,   121,   247,   180,   244,
      -1,   129,   247,   253,   244,    -1,   171,   247,   180,   244,
      -1,   113,   247,   180,   244,    -1,   225,   247,   180,   244,
      -1,   123,   247,   180,   244,    -1,   100,   247,   136,   244,
      -1,    43,   247,   115,   244,    -1,    98,   247,   115,   244,
      -1,   165,   247,   136,   244,    -1,    31,   247,   136,   244,
      -1,    27,   247,   115,   244,    -1,   231,   247,   180,   244,
      -1,    45,   247,   136,   244,    -1,   221,   247,   136,   244,
      -1,   132,   247,   180,   244,    -1,    38,   247,   180,   244,
      -1,   223,   247,   253,   244,    -1,    -1,   125,   497,   247,
     498,   244,    -1,   498,   248,   499,    -1,   499,    -1,   187,
      -1,   190,    -1,   191,    -1,   193,    -1,   194,    -1,   198,
      -1,    66,    -1,   209,    -1,   204,    -1,   206,    -1,   213,
      -1,   210,    -1,   197,    -1,   205,    -1,   208,    -1,   199,
      -1,   218,    -1,   188,    -1,   189,    -1,   202,    -1,    -1,
     122,   501,   247,   502,   244,    -1,   502,   248,   503,    -1,
     503,    -1,   187,    -1,   190,    -1,   191,    -1,   193,    -1,
     194,    -1,   198,    -1,   209,    -1,    66,    -1,   204,    -1,
     206,    -1,   213,    -1,   210,    -1,   197,    -1,   205,    -1,
     208,    -1,   199,    -1,   218,    -1,   188,    -1,   189,    -1,
     202,    -1,   101,   247,   115,   244,    -1,   102,   247,   115,
     244,    -1,    32,   247,   115,   244,    -1,   192,   247,   255,
     244,    -1,    -1,    57,   509,   246,   510,   245,   244,    -1,
     510,   511,    -1,   511,    -1,   512,    -1,   513,    -1,   514,
      -1,   518,    -1,   519,    -1,   520,    -1,     1,    -1,    47,
     247,   180,   244,    -1,    44,   247,   253,   244,    -1,    -1,
      88,   515,   247,   516,   244,    -1,   516,   248,   517,    -1,
     517,    -1,   182,    -1,    11,    -1,   230,   247,   136,   244,
      -1,   105,   247,   136,   244,    -1,    -1,     4,   521,   247,
     522,   244,    -1,   522,   248,   523,    -1,   523,    -1,   182,
      -1,    11,    -1,    21,   246,   525,   245,   244,    -1,   525,
     526,    -1,   526,    -1,   529,    -1,   530,    -1,   531,    -1,
     532,    -1,   537,    -1,   533,    -1,   534,    -1,   535,    -1,
     536,    -1,   538,    -1,   539,    -1,   540,    -1,   528,    -1,
     541,    -1,   542,    -1,   543,    -1,   544,    -1,   527,    -1,
       1,    -1,    39,   247,   180,   244,    -1,   146,   247,   180,
     244,    -1,    41,   247,   180,   244,    -1,   232,   247,   180,
     244,    -1,   233,   247,   180,   244,    -1,   234,   247,   180,
     244,    -1,    83,   247,   253,   244,    -1,    84,   247,   253,
     244,    -1,    91,   247,   115,   244,    -1,   137,   247,   180,
     244,    -1,    90,   247,   115,   244,    -1,    34,   247,   115,
     244,    -1,    33,   247,   115,   244,    -1,   111,   247,   180,
     244,    -1,   112,   247,   180,   244,    -1,    13,   247,   180,
     244,    -1,   126,   247,   115,   244,    -1,   127,   247,   253,
     244,    -1,   163,   246,   546,   245,   244,    -1,   546,   547,
      -1,   547,    -1,   548,    -1,   549,    -1,   551,    -1,   553,
      -1,   552,    -1,   550,    -1,   554,    -1,     1,    -1,    53,
     247,   180,   244,    -1,    69,   247,   180,   244,    -1,    67,
     247,   136,   244,    -1,    86,   247,   253,   244,    -1,    66,
     247,   180,   244,    -1,    40,   247,   180,   244,    -1,    68,
     247,   180,   244,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   379,   379,   380,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   409,   409,   410,
     414,   418,   422,   426,   430,   436,   436,   437,   438,   439,
     440,   447,   450,   450,   451,   451,   451,   453,   459,   466,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   473,
     473,   474,   474,   475,   476,   480,   479,   498,   498,   499,
     505,   513,   547,   607,   622,   637,   646,   660,   669,   697,
     727,   750,   759,   761,   761,   762,   762,   763,   763,   765,
     774,   783,   795,   796,   796,   798,   798,   798,   799,   801,
     807,   814,   814,   824,   825,   827,   827,   828,   828,   830,
     835,   838,   844,   843,   849,   849,   850,   854,   858,   862,
     866,   870,   874,   885,   884,   982,   982,   983,   983,   983,
     984,   984,   984,   985,   985,   985,   987,   999,  1036,  1048,
    1059,  1101,  1111,  1110,  1116,  1116,  1117,  1121,  1125,  1129,
    1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1177,  1181,  1185,  1189,  1193,  1200,  1199,  1205,  1205,
    1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,
    1246,  1250,  1254,  1258,  1262,  1266,  1277,  1276,  1326,  1326,
    1327,  1328,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1339,  1341,  1350,  1356,  1362,  1368,  1374,
    1380,  1386,  1392,  1398,  1404,  1410,  1416,  1426,  1425,  1442,
    1441,  1446,  1446,  1447,  1451,  1455,  1463,  1463,  1464,  1464,
    1464,  1464,  1464,  1466,  1466,  1468,  1468,  1470,  1484,  1504,
    1513,  1526,  1525,  1594,  1594,  1595,  1595,  1595,  1595,  1596,
    1596,  1596,  1597,  1597,  1599,  1636,  1649,  1658,  1670,  1669,
    1673,  1673,  1674,  1678,  1682,  1686,  1690,  1694,  1698,  1702,
    1706,  1713,  1732,  1742,  1756,  1755,  1771,  1771,  1772,  1772,
    1772,  1772,  1774,  1783,  1798,  1811,  1813,  1813,  1814,  1814,
    1816,  1832,  1831,  1847,  1847,  1848,  1848,  1848,  1848,  1850,
    1859,  1882,  1881,  1887,  1887,  1888,  1892,  1896,  1900,  1904,
    1908,  1912,  1916,  1920,  1924,  1928,  1938,  1937,  1954,  1954,
    1955,  1955,  1955,  1957,  1964,  1963,  1969,  1969,  1970,  1974,
    1978,  1982,  1986,  1990,  1994,  1998,  2002,  2006,  2010,  2020,
    2019,  2162,  2162,  2163,  2163,  2163,  2164,  2164,  2165,  2165,
    2166,  2166,  2166,  2167,  2167,  2168,  2168,  2169,  2171,  2183,
    2192,  2218,  2236,  2254,  2260,  2264,  2273,  2272,  2276,  2276,
    2277,  2287,  2291,  2295,  2299,  2305,  2346,  2357,  2370,  2383,
    2392,  2428,  2427,  2491,  2490,  2494,  2494,  2495,  2501,  2501,
    2502,  2502,  2502,  2502,  2504,  2523,  2533,  2532,  2555,  2555,
    2556,  2556,  2556,  2558,  2564,  2573,  2575,  2575,  2576,  2576,
    2578,  2597,  2596,  2644,  2643,  2647,  2647,  2648,  2654,  2654,
    2655,  2655,  2655,  2655,  2657,  2663,  2672,  2675,  2675,  2676,
    2676,  2677,  2677,  2678,  2678,  2679,  2679,  2680,  2680,  2681,
    2681,  2682,  2682,  2683,  2683,  2684,  2684,  2685,  2685,  2686,
    2686,  2687,  2687,  2688,  2688,  2689,  2690,  2690,  2691,  2691,
    2692,  2692,  2693,  2693,  2694,  2694,  2695,  2695,  2696,  2697,
    2697,  2698,  2698,  2699,  2700,  2701,  2701,  2702,  2702,  2703,
    2703,  2704,  2704,  2705,  2708,  2713,  2718,  2723,  2728,  2733,
    2738,  2743,  2748,  2753,  2758,  2763,  2768,  2773,  2778,  2783,
    2788,  2793,  2799,  2810,  2815,  2824,  2829,  2834,  2839,  2844,
    2849,  2852,  2857,  2860,  2865,  2870,  2875,  2880,  2885,  2890,
    2895,  2900,  2905,  2916,  2921,  2926,  2935,  2967,  2985,  2990,
    2999,  3008,  3013,  3018,  3024,  3023,  3028,  3028,  3029,  3032,
    3035,  3038,  3041,  3044,  3047,  3050,  3053,  3056,  3059,  3062,
    3065,  3068,  3071,  3074,  3077,  3080,  3083,  3086,  3092,  3091,
    3096,  3096,  3097,  3100,  3103,  3106,  3109,  3112,  3115,  3118,
    3121,  3124,  3127,  3130,  3133,  3136,  3139,  3142,  3145,  3148,
    3151,  3154,  3159,  3164,  3169,  3174,  3184,  3183,  3207,  3207,
    3208,  3209,  3210,  3211,  3212,  3213,  3214,  3216,  3222,  3229,
    3228,  3233,  3233,  3234,  3238,  3244,  3278,  3288,  3287,  3337,
    3337,  3338,  3342,  3351,  3354,  3354,  3355,  3355,  3356,  3356,
    3357,  3357,  3358,  3358,  3359,  3359,  3360,  3361,  3361,  3362,
    3362,  3363,  3363,  3364,  3364,  3366,  3371,  3376,  3381,  3386,
    3391,  3396,  3401,  3406,  3411,  3416,  3421,  3426,  3431,  3436,
    3441,  3446,  3451,  3459,  3462,  3462,  3463,  3463,  3464,  3465,
    3466,  3466,  3467,  3468,  3470,  3476,  3482,  3491,  3505,  3511,
    3517
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
  "T_UNAUTH", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS",
  "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "T_TIMESTAMP",
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
     495,   496,   497,   498,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   252,   252,   253,
     253,   253,   253,   253,   253,   254,   254,   255,   255,   255,
     255,   256,   257,   257,   258,   258,   258,   259,   260,   261,
     262,   262,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   265,   264,   266,   266,   267,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   280,   281,   281,   281,   281,   282,
     283,   284,   285,   286,   286,   287,   287,   287,   287,   288,
     289,   291,   290,   292,   292,   293,   293,   293,   293,   294,
     295,   295,   297,   296,   298,   298,   299,   299,   299,   299,
     299,   299,   299,   301,   300,   302,   302,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   305,   306,   307,
     308,   309,   311,   310,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   315,   314,   316,   316,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   319,   318,   320,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   336,   335,   338,
     337,   339,   339,   340,   340,   340,   341,   341,   342,   342,
     342,   342,   342,   344,   343,   345,   345,   346,   346,   347,
     348,   350,   349,   351,   351,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   353,   354,   355,   356,   358,   357,
     359,   359,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   361,   362,   363,   365,   364,   366,   366,   367,   367,
     367,   367,   368,   369,   370,   371,   372,   372,   373,   373,
     374,   376,   375,   377,   377,   378,   378,   378,   378,   379,
     380,   382,   381,   383,   383,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   386,   385,   387,   387,
     388,   388,   388,   389,   391,   390,   392,   392,   393,   393,
     393,   393,   393,   393,   393,   393,   393,   393,   393,   395,
     394,   396,   396,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   397,   398,   399,
     400,   401,   402,   403,   404,   404,   406,   405,   407,   407,
     408,   408,   408,   408,   408,   409,   410,   411,   412,   413,
     414,   416,   415,   418,   417,   419,   419,   420,   421,   421,
     422,   422,   422,   422,   423,   424,   426,   425,   427,   427,
     428,   428,   428,   429,   430,   431,   432,   432,   433,   433,
     434,   436,   435,   438,   437,   439,   439,   440,   441,   441,
     442,   442,   442,   442,   443,   444,   445,   446,   446,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   474,   475,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   497,   496,   498,   498,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   501,   500,
     502,   502,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   504,   505,   506,   507,   509,   508,   510,   510,
     511,   511,   511,   511,   511,   511,   511,   512,   513,   515,
     514,   516,   516,   517,   517,   518,   519,   521,   520,   522,
     522,   523,   523,   524,   525,   525,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   526,   526,   526,   526,   526,
     526,   526,   526,   526,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   546,   547,   547,   547,   547,
     547,   547,   547,   547,   548,   549,   550,   551,   552,   553,
     554
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
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
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
       2,     0,     1,     0,     0,     0,   186,   339,   396,     0,
     411,     0,   586,   241,   381,   217,     0,     0,   123,   274,
       0,     0,   291,   316,     0,     3,    24,    11,     4,     5,
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
      53,    60,    58,    54,     0,     0,   289,     0,     0,   287,
     288,    88,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,   190,   193,   194,   196,   197,   198,   199,
     200,   201,   202,   191,   192,   195,     0,     0,     0,     0,
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
     258,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,   252,   248,   249,   250,   251,   393,     0,   383,     0,
     392,     0,   389,   390,   391,     0,   219,     0,     0,     0,
     229,     0,   227,   228,   230,   231,    98,     0,     0,     0,
      93,     0,    46,     0,     0,     0,    42,     0,     0,     0,
     166,     0,     0,     0,   142,     0,     0,   126,   127,   128,
     129,   132,   133,   131,   130,   134,     0,     0,     0,     0,
       0,   277,   278,   279,   280,     0,     0,     0,     0,     0,
       0,     0,     0,   654,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   301,     0,     0,   294,   295,   296,   297,     0,     0,
     324,     0,   319,   320,   321,     0,     0,   286,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   203,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   188,   357,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   341,     0,     0,     0,   398,     0,
     405,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,   588,   253,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   243,     0,     0,     0,     0,   388,   232,     0,
       0,     0,     0,     0,   226,     0,     0,    92,     0,     0,
       0,    41,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   281,     0,     0,     0,     0,   276,     0,
       0,     0,     0,     0,     0,     0,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
     298,     0,     0,     0,     0,   293,   322,     0,     0,     0,
     318,     0,   285,    91,    90,    89,   650,   647,   646,   635,
     637,    27,    27,    27,    27,    27,    29,    28,   641,   642,
     645,   643,   648,   649,   651,   652,   644,   636,   638,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   187,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,   242,     0,     0,
       0,   382,     0,     0,     0,   237,   233,   236,   218,   100,
      99,     0,     0,   112,     0,     0,   104,   105,   107,   106,
      47,    48,     0,     0,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,   275,   669,   664,   668,   666,   670,
     665,   667,    75,    81,    73,    77,    76,    72,    71,    69,
      70,     0,    68,    74,    80,    78,    79,     0,     0,     0,
     292,     0,     0,   317,   290,    30,    31,    32,    33,    34,
     214,   215,   208,   210,   212,   211,   209,   204,   216,   207,
     205,   206,   213,   362,   364,   365,   380,   379,   376,   372,
     373,   370,   371,   374,     0,   369,   359,   377,   378,   358,
     363,   375,   361,   360,   403,   404,   424,   425,   417,     0,
     416,   559,     0,   535,     0,    38,    39,    40,   612,   611,
       0,   610,   598,   597,   604,   603,     0,   602,   606,   605,
     256,   257,   266,   263,   268,   265,   264,   270,   267,   269,
     262,     0,   261,   255,   273,   272,   271,   254,   395,   387,
       0,   386,   394,   224,   225,   223,     0,   222,   240,   239,
       0,     0,     0,   108,     0,     0,     0,     0,   103,   141,
     139,   179,   176,   175,   170,   172,   185,   180,   183,   178,
     171,   184,   181,   182,   177,   173,   174,     0,   169,   136,
     138,   140,   152,   146,   163,   164,   147,   148,   149,   150,
     158,   151,   161,   165,   154,   159,   155,   160,   153,   157,
     156,   162,     0,   145,   137,   283,   284,   282,    66,     0,
     299,   305,   311,   315,   314,   313,   310,   306,   309,   312,
     307,   308,     0,   304,   300,   323,   328,   334,   338,   337,
     336,   333,   329,   332,   335,   330,   331,     0,   327,   367,
       0,   414,     0,   560,   536,   608,     0,   600,     0,   259,
       0,   384,     0,   220,     0,   238,   235,   234,     0,     0,
       0,     0,   102,   167,     0,   143,     0,    67,   302,     0,
     325,     0,   368,   415,   609,   601,   260,   385,   221,   109,
     118,   121,   120,   117,   122,   119,   116,     0,   115,   111,
     110,   168,   144,   303,   326,   113,     0,   114
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
     553,   554,   779,  1222,  1223,   555,   775,  1197,  1198,    31,
      51,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,    32,    60,   520,   759,
    1166,  1167,   521,   522,   523,  1172,  1016,  1017,   524,   525,
      33,    58,   496,   497,   498,   499,   500,   501,   502,   745,
    1151,  1152,   503,   504,   505,    34,    64,   560,   561,   562,
     563,   564,    35,   308,   309,   310,    36,    67,   593,   594,
     595,   596,   597,   812,  1242,  1243,    37,    68,   601,   602,
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
#define YYPACT_NINF -635
static const yytype_int16 yypact[] =
{
    -635,   676,  -635,  -199,  -237,  -225,  -635,  -635,  -635,  -222,
    -635,  -217,  -635,  -635,  -635,  -635,  -198,  -193,  -635,  -635,
    -185,  -175,  -635,  -635,  -164,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   318,
     632,  -154,  -151,  -146,    10,  -128,   431,  -119,  -113,   -92,
     -84,    89,    35,   -76,   -73,   450,   471,   -53,   -42,     9,
    -207,  -112,   -41,   -38,    11,  -635,  -635,  -635,  -635,  -635,
     -33,   -23,   -21,    29,    39,    48,    59,    65,   106,   111,
     113,   120,   121,   123,   130,   136,   137,   139,   147,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   744,   545,
       4,  -635,   140,    17,  -635,  -635,    58,  -635,   143,   146,
     148,   151,   152,   155,   156,   158,   166,   168,   169,   171,
     172,   174,   175,   177,   178,   180,   183,   184,   186,   187,
     188,   190,   197,   198,   199,   201,   202,   205,  -635,   207,
    -635,   209,   213,   217,   219,   221,   223,   224,   228,   230,
     233,   234,   236,   237,   238,   240,   241,   242,   246,   247,
     248,   250,    24,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   312,   395,
      13,   330,    44,   252,   253,    75,  -635,  -635,  -635,  -635,
      28,   194,   255,   257,    40,  -635,  -635,  -635,   337,    49,
    -635,   261,   263,   264,   268,   274,   275,   277,   214,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,   254,   281,   290,
     291,   292,   293,   294,   298,  -635,   300,   303,   308,   310,
     191,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,     5,     2,  -635,   311,    27,  -635,
    -635,  -635,   321,   387,   425,   320,  -635,   153,   447,   451,
     385,   391,   457,   457,   458,   460,   397,   400,   467,   457,
     403,   404,   405,   406,   407,   344,  -635,   345,   343,   347,
     348,   352,   353,   354,   356,   357,   358,   364,   365,   370,
     373,   210,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   380,   379,   381,   382,
     384,   388,  -635,   389,   393,   394,   396,   399,   401,   402,
     410,   216,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   411,   412,
      12,  -635,  -635,  -635,   455,   383,  -635,  -635,   413,   416,
    -635,  -635,    72,  -635,  -635,  -635,   454,   457,   457,   477,
     506,   529,   473,   484,   532,   515,   488,   554,   555,   563,
     495,   502,   503,   457,   548,   505,   572,   573,   457,   574,
     575,   556,   578,   580,   511,   516,   452,   518,   456,   457,
     457,   522,   457,   569,   526,   530,   537,   -16,    -2,   539,
     544,   457,   457,   597,   589,   457,   547,   549,   552,   557,
     490,  -635,  -635,  -635,   481,   491,  -635,   493,   500,    16,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,   498,   501,   504,
    -635,   507,   508,   509,   510,   513,   196,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,   514,  -635,   524,
    -635,   167,  -635,  -635,  -635,   521,  -635,   525,   527,   536,
    -635,    63,  -635,  -635,  -635,  -635,  -635,   570,   611,   533,
    -635,   109,  -635,   599,   613,   550,  -635,   558,   553,   559,
    -635,   565,   566,   567,  -635,   571,     6,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   579,   577,   581,   584,
      21,  -635,  -635,  -635,  -635,   612,   623,   624,   616,   627,
     636,   457,   585,  -635,  -635,   681,   639,   684,   689,   690,
     696,   697,   587,   706,   728,   710,   711,   604,  -635,   606,
     605,  -635,   608,    64,  -635,  -635,  -635,  -635,   607,   609,
    -635,   100,  -635,  -635,  -635,   717,   614,  -635,   615,   619,
     625,  -635,   626,   628,   629,   630,   631,   251,   635,   637,
     638,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,  -635,  -635,   742,   745,   457,   752,   753,   765,   768,
     735,   779,   782,   457,   457,   597,   654,  -635,  -635,   763,
      52,   764,   766,   723,   657,   770,   771,   772,   773,   786,
     774,   780,   783,   680,  -635,   784,   789,   683,  -635,   687,
    -635,   799,   800,   691,   695,  -635,   704,   707,   708,   712,
     713,   715,   719,   726,   727,   729,   736,   739,   740,   747,
     751,   755,   758,   759,   760,   761,   767,   769,   775,   776,
     777,   778,   781,   785,   787,   790,   724,   791,   756,   792,
     793,   794,   795,   796,   797,   798,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   276,   810,   811,   812,   813,
     814,   815,   816,  -635,   693,   457,   820,   694,   831,   832,
     817,  -635,  -635,   836,   827,   741,   853,   893,   873,   874,
     876,   818,  -635,   878,   819,   879,   821,  -635,  -635,   822,
     880,   881,   903,   823,  -635,   824,   826,  -635,   108,   828,
     829,  -635,  -635,   887,   844,   830,   890,   891,   892,   833,
     894,   834,  -635,  -635,   896,   897,   907,   835,  -635,   837,
     838,   839,   840,   841,   842,   843,  -635,   845,   846,   847,
     848,   849,   850,   851,    32,   852,   854,   855,   856,  -635,
    -635,   908,   857,   927,   858,  -635,  -635,   928,   859,   861,
    -635,   863,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,   457,   457,   457,   457,   457,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,   864,   865,   866,   867,   868,   869,   870,   871,   872,
     875,   877,   882,   883,  -635,   884,   885,   886,   888,   889,
     895,   164,   898,   899,   900,   901,   902,   904,   905,   906,
    -635,   909,   910,  -635,  -635,   911,   912,   930,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -229,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -221,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
     597,   597,   597,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,    38,   913,   914,    41,   915,   916,  -635,   917,
     918,   721,   919,   920,   921,   922,   923,  -635,   924,   933,
     925,  -635,   -50,   926,   929,   932,   931,  -635,  -635,  -635,
    -635,   934,   935,  -635,   936,   107,  -635,  -635,  -635,  -635,
    -635,  -635,   937,   940,   576,   941,   942,   943,   788,   944,
    -635,   945,   946,   947,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -218,  -635,  -635,  -635,  -635,  -635,   948,   560,   949,
    -635,   950,   582,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -210,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -209,
    -635,  -635,   724,  -635,   756,  -635,  -635,  -635,  -635,  -635,
    -204,  -635,  -635,  -635,  -635,  -635,  -176,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -170,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -167,  -635,  -635,  -635,  -635,  -635,  -165,  -635,  -635,  -635,
     960,   903,   951,  -635,   952,   953,  -111,   954,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -157,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,   -19,  -635,  -635,  -635,  -635,  -635,  -635,    32,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,    31,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,    81,  -635,  -635,
     164,  -635,   930,  -635,  -635,  -635,    38,  -635,    41,  -635,
     721,  -635,   933,  -635,   -50,  -635,  -635,  -635,   955,   284,
     957,   958,  -635,  -635,   576,  -635,   788,  -635,  -635,   560,
    -635,   582,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,    86,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,   284,  -635
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -635,  -635,  -635,  -459,  -321,  -634,  -463,  -635,  -635,   956,
    -635,  -635,  -635,  -635,   862,  -635,  -635,  -635,  -153,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  1023,  -635,  -635,  -635,  -635,  -635,   959,  -635,
    -635,  -635,  -635,  -635,    76,  -635,  -635,  -635,  -635,  -635,
    -213,  -635,  -635,  -635,   588,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -168,  -635,  -635,  -635,  -162,  -635,
    -635,  -635,   825,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -150,  -635,   602,  -635,  -635,  -635,   -51,  -635,  -635,
    -635,  -635,  -635,   651,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -145,  -635,  -635,  -635,  -635,  -635,  -635,   591,  -635,
    -635,  -635,  -635,  -635,   938,  -635,  -635,  -635,  -635,   538,
    -635,  -635,  -635,  -635,  -635,  -152,  -635,  -635,  -635,   534,
    -635,  -635,  -635,  -635,  -155,  -635,  -635,  -635,   757,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -120,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -131,  -635,   660,  -635,  -635,  -635,  -635,  -635,   860,
    -635,  -635,  -635,  -635,  1049,  -635,  -635,  -635,  -635,  -635,
    -635,   -88,  -635,   939,  -635,  -635,  -635,  -635,   993,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
      53,  -635,  -635,  -635,    74,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,   701,  -635,  -635,  -635,  -635,  -635,   -71,  -635,
    -635,  -635,  -635,  -635,   -63,  -635,  -635,  1107,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,
    -635,  -635,  -635,  -635,  -635,  -635,  -635,  -635,   961,  -635,
    -635,  -635,  -635,  -635,  -635,  -635
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     726,   618,   619,   598,   725,   397,   589,   537,   625,    49,
     306,   121,    70,   397,   506,  1121,  1163,   472,   121,  1122,
     473,    50,   556,  1123,    54,   127,  1228,  1124,   306,    56,
    1229,   538,   128,   129,  1259,  1261,   251,   311,  1260,  1262,
    1265,   251,   557,   130,  1266,    47,    48,    71,    61,  1128,
     556,   131,  1134,    62,   539,   132,   133,    72,   540,   407,
     474,    65,   134,   475,   515,   589,   135,   136,  1267,   137,
     557,    66,  1268,   407,  1269,   138,   242,  1271,  1270,  1273,
     398,  1272,    69,  1274,   139,   140,   122,  1283,   398,   141,
     242,  1284,   118,   122,   142,   119,   677,   678,   143,   144,
     120,   598,   145,  1280,   476,   146,   147,   599,  1021,  1021,
     590,   541,   693,   148,   307,   516,    73,   698,   126,   149,
     150,   477,   151,   152,   153,   154,   155,   238,   709,   710,
     558,   712,   307,   239,   517,   312,   542,   156,   252,   518,
     723,   724,   399,   252,   728,   157,   158,   159,    79,   160,
     399,   507,   161,   162,   240,   543,   163,  1164,   558,   559,
      80,  1165,   241,   408,   717,   718,   253,   164,   506,   590,
     258,   253,   600,   259,  1099,   591,  1100,   408,   719,   720,
      81,    82,   863,   508,  1059,  1060,    83,   559,    84,   165,
    1101,   166,   277,   304,  1102,   167,   409,   487,   519,   168,
     169,   170,   171,   172,   305,   599,   313,   173,   174,   314,
     409,   337,  1022,  1022,   317,   260,   175,   366,   544,   367,
    1129,   488,   368,  1135,   318,  1285,   319,   278,   410,  1286,
      85,    86,   338,   339,   591,   592,   545,    87,    88,   340,
     369,   370,   410,   509,   489,   176,   478,   177,   490,   178,
     795,   781,   866,   867,   261,   179,   315,   667,    89,    90,
     180,   740,   405,   279,   371,   181,   787,   262,   372,   470,
     600,   531,   606,    91,    92,  1288,   320,  1023,  1023,  1289,
     263,   264,   265,   266,    93,   535,   321,   373,   526,   374,
     980,   981,   982,    94,   592,   322,   280,   243,   281,   282,
     267,   375,   341,   342,   343,   507,   323,   344,   763,   814,
     244,   243,   324,   472,   853,   345,   473,   674,  -101,    70,
     529,   376,   861,   862,   244,  1290,   491,   346,   347,  1291,
    1315,   515,  -101,   612,  1316,   492,   493,   508,   537,   283,
    1300,   284,   285,   348,   349,   819,  1125,  1126,  1127,  1024,
    1024,   377,  1177,   325,    71,   768,   474,   286,   326,   475,
     327,  1301,   538,  1302,    72,   378,   617,   328,   329,   494,
     330,   350,  1075,  1076,  1077,  1078,  1079,   331,   379,    95,
      96,    97,   516,   332,   333,   539,   334,   404,  1103,   540,
     416,   725,   335,   417,   287,   418,   487,   509,   419,   420,
     476,   517,   421,   422,  1303,   423,   518,   831,   832,   833,
     834,   835,   756,   424,   993,   425,   426,   477,   427,   428,
     488,   429,   430,    73,   431,   432,   495,   433,   288,   289,
     434,   435,   127,   436,   437,   438,   587,   439,   532,   128,
     129,   751,   541,   489,   440,   441,   442,   490,   443,   444,
     130,   260,   445,   380,   447,   646,   449,   608,   131,   572,
     450,   663,   132,   133,   451,   519,   452,   542,   453,   134,
     454,   455,   277,   135,   136,   456,   137,   457,  1304,  1305,
     458,   459,   138,   460,   461,   462,   543,   463,   464,   465,
     261,   139,   140,   466,   467,   468,   141,   469,   574,   527,
     528,   142,   533,   262,   534,   143,   144,   278,   565,   145,
     566,   567,   146,   147,  1306,   568,   263,   264,   265,   266,
     148,   569,   570,   609,   571,   491,   149,   150,   575,   151,
     152,   153,   154,   155,   492,   493,   267,   576,   577,   578,
     579,   580,   478,   279,   156,   581,   366,   583,   367,   544,
     584,   368,   157,   158,   159,   585,   160,   586,   605,   161,
     162,   610,   613,   163,   611,   615,   614,   545,   494,   369,
     370,   616,   617,   620,   164,   621,   280,   622,   281,   282,
     623,  1181,   624,   626,   627,   628,   629,   630,   631,   632,
     633,   669,   679,   371,   634,   635,   165,   372,   166,   636,
     637,   638,   167,   639,   640,   641,   168,   169,   170,   171,
     172,   642,   643,  1182,   173,   174,   373,   644,   374,   283,
     645,   284,   285,   175,   648,   495,   649,   670,   650,   651,
     375,   652,  1183,    79,   676,   653,   655,   286,  1184,  1231,
     656,   657,   680,   658,   681,    80,   659,   684,   660,   661,
     376,   685,   176,   682,   177,  1185,   178,   662,   665,   666,
     671,  1246,   179,   672,   683,    81,    82,   180,   686,   687,
     688,    83,   181,    84,   287,   690,     2,     3,   689,  1186,
     377,     4,   691,   692,   694,   695,  1187,   696,   697,   699,
     700,   704,   701,   702,   378,   703,   705,     5,   707,   706,
    1188,     6,   711,   708,     7,   713,   714,   379,   288,   289,
     715,     8,   725,  1281,  1232,    85,    86,   716,  1189,   721,
    1190,  1191,    87,    88,   722,   727,     9,   729,   735,   730,
      10,    11,   731,    12,   733,   769,  1247,   732,   736,    13,
     738,  1142,   742,    89,    90,   337,  1233,   739,   743,   770,
     765,   744,   792,    14,   746,   747,   748,   749,    91,    92,
     750,   753,  1234,    15,    16,   758,   338,   339,  1248,    93,
    1143,   755,   760,   340,   761,  1235,  1236,   767,    94,  1144,
      17,  1192,   380,   762,  1249,  1145,  1237,  1238,  1239,  1240,
     919,   766,   789,  1193,   771,  1194,    18,  1250,  1251,  1241,
     773,  1146,   772,   790,   791,  1195,   774,   793,  1252,  1253,
    1254,  1255,   776,   777,   778,  1196,   794,   797,   780,   798,
     799,  1256,   942,   783,   784,   800,   801,  1147,   785,   796,
      19,   786,   802,   803,   804,  1148,   341,   342,   343,    20,
      21,   344,   805,   806,    22,    23,   807,   808,   809,   345,
     810,   816,   811,   821,  1202,   813,   817,   851,   822,   823,
     852,   346,   347,   824,    95,    96,    97,   854,   855,   825,
     826,   858,   827,   828,   829,   830,  1149,   348,   349,   838,
     856,   839,   840,   857,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   859,  1150,    24,   860,   864,   865,
     868,   876,   869,   870,   871,   350,   872,   873,   874,   875,
     877,   920,   921,   922,   923,   924,   878,   925,   926,   879,
     881,   927,   928,   929,   880,   882,   930,   883,   931,   932,
     933,   884,   934,   935,   936,   885,   886,   937,   887,   888,
     992,   995,   938,   943,   944,   945,   946,   947,   889,   948,
     949,   890,   891,   950,   951,   952,   892,   893,   953,   894,
     954,   955,   956,   895,   957,   958,   959,   996,   997,   960,
     896,   897,   999,   898,   961,  1203,  1204,  1205,  1206,  1207,
     899,  1208,  1209,   900,   901,  1210,  1211,  1212,  1001,  1002,
    1213,   902,  1214,  1215,  1216,   903,  1217,  1218,  1219,   904,
     994,  1220,   905,   906,   907,   908,  1221,  1000,  1003,  1004,
    1005,   909,  1006,   910,  1008,  1010,  1013,  1014,  1015,   911,
     912,   913,   914,  1032,  1033,   915,  1035,  1036,  1037,   916,
    1039,   917,  1041,  1042,   918,   941,   964,   965,   966,   967,
     968,   969,   970,  1043,  1067,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   985,   986,   987,   988,   989,   990,
     991,   998,  1007,  1069,  1071,  1011,  1009,  1018,  1019,  1012,
    1020,  1118,  1030,  1031,  1159,  1275,  1287,  1034,  1040,  1044,
    1038,  1045,  1046,  1047,  1048,  1049,  1050,  1051,  1278,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1063,   316,  1064,  1065,
    1066,  1178,  1070,  1317,  1068,  1073,  1072,  1074,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1170,  1312,  1089,
    1276,  1090,  1311,   764,  1298,  1296,  1091,  1092,  1093,  1094,
    1095,   815,  1096,  1097,   782,   820,  1314,  1313,   664,  1098,
    1292,  1297,  1106,  1107,  1108,  1109,  1110,   752,  1111,  1112,
    1113,   788,   588,  1114,  1115,  1116,  1117,  1132,  1133,  1138,
    1139,  1140,  1141,  1153,  1154,  1155,  1156,  1157,  1158,  1162,
    1168,   757,   406,  1169,  1293,   471,   647,  1264,  1173,  1171,
     741,  1179,  1174,  1176,  1180,  1199,  1200,  1201,  1224,  1225,
    1226,  1227,  1230,  1244,  1245,  1277,  1263,  1295,  1282,  1299,
    1279,  1309,  1310,  1294,   530,   336,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     668,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   675
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-635))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     463,   322,   323,     1,   115,     1,     1,     1,   329,   246,
       1,     1,     1,     1,     1,   244,    66,     1,     1,   248,
       4,   246,     1,   244,   246,     1,   244,   248,     1,   246,
     248,    25,     8,     9,   244,   244,     1,   244,   248,   248,
     244,     1,    21,    19,   248,   244,   245,    36,   246,    11,
       1,    27,    11,   246,    48,    31,    32,    46,    52,     1,
      44,   246,    38,    47,     1,     1,    42,    43,   244,    45,
      21,   246,   248,     1,   244,    51,     1,   244,   248,   244,
      76,   248,   246,   248,    60,    61,    76,   244,    76,    65,
       1,   248,   246,    76,    70,   246,   417,   418,    74,    75,
     246,     1,    78,   214,    88,    81,    82,   105,     1,     1,
     105,   105,   433,    89,   105,    52,   105,   438,   246,    95,
      96,   105,    98,    99,   100,   101,   102,   246,   449,   450,
     109,   452,   105,   246,    71,   247,   130,   113,   103,    76,
     461,   462,   138,   103,   465,   121,   122,   123,     1,   125,
     138,   138,   128,   129,   246,   149,   132,   207,   109,   138,
      13,   211,   246,   105,   180,   181,   131,   143,     1,   105,
     246,   131,   170,   246,    10,   170,    12,   105,   180,   181,
      33,    34,   645,   170,   152,   153,    39,   138,    41,   165,
      26,   167,     1,   246,    30,   171,   138,     1,   135,   175,
     176,   177,   178,   179,   246,   105,   247,   183,   184,   247,
     138,     1,   105,   105,   247,     1,   192,     1,   212,     3,
     182,    25,     6,   182,   247,   244,   247,    36,   170,   248,
      83,    84,    22,    23,   170,   230,   230,    90,    91,    29,
      24,    25,   170,   230,    48,   221,   230,   223,    52,   225,
     571,   245,   200,   201,    40,   231,   245,   245,   111,   112,
     236,   245,   245,    72,    48,   241,   245,    53,    52,   245,
     170,   243,   245,   126,   127,   244,   247,   170,   170,   248,
      66,    67,    68,    69,   137,   245,   247,    71,   244,    73,
      14,    15,    16,   146,   230,   247,   105,   222,   107,   108,
      86,    85,    92,    93,    94,   138,   247,    97,   245,   245,
     235,   222,   247,     1,   635,   105,     4,   245,   243,     1,
     245,   105,   643,   644,   235,   244,   130,   117,   118,   248,
     244,     1,   243,   180,   248,   139,   140,   170,     1,   148,
      56,   150,   151,   133,   134,   245,   980,   981,   982,   242,
     242,   135,   245,   247,    36,   246,    44,   166,   247,    47,
     247,    77,    25,    79,    46,   149,   115,   247,   247,   173,
     247,   161,   831,   832,   833,   834,   835,   247,   162,   232,
     233,   234,    52,   247,   247,    48,   247,   247,   224,    52,
     247,   115,   245,   247,   203,   247,     1,   230,   247,   247,
      88,    71,   247,   247,   120,   247,    76,   156,   157,   158,
     159,   160,   245,   247,   735,   247,   247,   105,   247,   247,
      25,   247,   247,   105,   247,   247,   230,   247,   237,   238,
     247,   247,     1,   247,   247,   247,   245,   247,   244,     8,
       9,   245,   105,    48,   247,   247,   247,    52,   247,   247,
      19,     1,   247,   237,   247,   245,   247,   136,    27,   245,
     247,   245,    31,    32,   247,   135,   247,   130,   247,    38,
     247,   247,     1,    42,    43,   247,    45,   247,   194,   195,
     247,   247,    51,   247,   247,   247,   149,   247,   247,   247,
      40,    60,    61,   247,   247,   247,    65,   247,   244,   247,
     247,    70,   247,    53,   247,    74,    75,    36,   247,    78,
     247,   247,    81,    82,   230,   247,    66,    67,    68,    69,
      89,   247,   247,   136,   247,   130,    95,    96,   247,    98,
      99,   100,   101,   102,   139,   140,    86,   247,   247,   247,
     247,   247,   230,    72,   113,   247,     1,   247,     3,   212,
     247,     6,   121,   122,   123,   247,   125,   247,   247,   128,
     129,   136,   115,   132,   244,   180,   115,   230,   173,    24,
      25,   180,   115,   115,   143,   115,   105,   180,   107,   108,
     180,     5,   115,   180,   180,   180,   180,   180,   244,   244,
     247,   136,   115,    48,   247,   247,   165,    52,   167,   247,
     247,   247,   171,   247,   247,   247,   175,   176,   177,   178,
     179,   247,   247,    37,   183,   184,    71,   247,    73,   148,
     247,   150,   151,   192,   244,   230,   247,   244,   247,   247,
      85,   247,    56,     1,   180,   247,   247,   166,    62,    79,
     247,   247,   136,   247,   115,    13,   247,   115,   247,   247,
     105,   136,   221,   180,   223,    79,   225,   247,   247,   247,
     247,    79,   231,   247,   180,    33,    34,   236,   180,   115,
     115,    39,   241,    41,   203,   180,     0,     1,   115,   103,
     135,     5,   180,   180,   136,   180,   110,   115,   115,   115,
     115,   180,   136,   115,   149,   115,   180,    21,   180,   247,
     124,    25,   180,   247,    28,   136,   180,   162,   237,   238,
     180,    35,   115,  1176,   154,    83,    84,   180,   142,   180,
     144,   145,    90,    91,   180,   136,    50,   180,   247,   180,
      54,    55,   180,    57,   244,   136,   154,   180,   247,    63,
     247,    20,   244,   111,   112,     1,   186,   247,   247,   136,
     180,   247,   136,    77,   247,   247,   247,   247,   126,   127,
     247,   247,   202,    87,    88,   244,    22,    23,   186,   137,
      49,   247,   247,    29,   247,   215,   216,   244,   146,    58,
     104,   205,   237,   247,   202,    64,   226,   227,   228,   229,
      66,   180,   180,   217,   244,   219,   120,   215,   216,   239,
     247,    80,   244,   180,   180,   229,   247,   180,   226,   227,
     228,   229,   247,   247,   247,   239,   180,   136,   247,   180,
     136,   239,    66,   244,   247,   136,   136,   106,   247,   244,
     154,   247,   136,   136,   247,   114,    92,    93,    94,   163,
     164,    97,   136,   115,   168,   169,   136,   136,   244,   105,
     244,   244,   247,   136,    66,   247,   247,   115,   244,   244,
     115,   117,   118,   244,   232,   233,   234,   115,   115,   244,
     244,   136,   244,   244,   244,   244,   155,   133,   134,   244,
     115,   244,   244,   115,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   115,   174,   220,   115,   244,   136,
     136,   115,   136,   180,   247,   161,   136,   136,   136,   136,
     136,   187,   188,   189,   190,   191,   136,   193,   194,   136,
     136,   197,   198,   199,   244,   136,   202,   244,   204,   205,
     206,   244,   208,   209,   210,   136,   136,   213,   247,   244,
     247,   247,   218,   187,   188,   189,   190,   191,   244,   193,
     194,   244,   244,   197,   198,   199,   244,   244,   202,   244,
     204,   205,   206,   244,   208,   209,   210,   136,   136,   213,
     244,   244,   136,   244,   218,   187,   188,   189,   190,   191,
     244,   193,   194,   244,   244,   197,   198,   199,   247,   136,
     202,   244,   204,   205,   206,   244,   208,   209,   210,   244,
     180,   213,   244,   244,   244,   244,   218,   180,   115,   136,
     136,   244,   136,   244,   136,   136,   136,   136,   115,   244,
     244,   244,   244,   136,   180,   244,   136,   136,   136,   244,
     136,   244,   136,   136,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   136,   136,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   136,   136,   244,   247,   244,   244,   247,
     244,   141,   244,   244,   141,   115,  1229,   247,   244,   244,
     247,   244,   244,   244,   244,   244,   244,   244,   136,   244,
     244,   244,   244,   244,   244,   244,   244,    74,   244,   244,
     244,  1025,   244,  1316,   247,   244,   247,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   185,  1286,   244,
    1171,   244,  1284,   521,  1274,  1270,   244,   244,   244,   244,
     244,   593,   244,   244,   546,   601,  1291,  1289,   381,   244,
    1260,  1272,   244,   244,   244,   244,   244,   496,   244,   244,
     244,   560,   290,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   511,   123,   244,  1262,   182,   351,  1124,   244,   248,
     479,   244,   247,   247,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,  1122,  1268,   244,   244,
     247,   244,   244,  1266,   245,    98,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     400,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   250,     0,     1,     5,    21,    25,    28,    35,    50,
      54,    55,    57,    63,    77,    87,    88,   104,   120,   154,
     163,   164,   168,   169,   220,   251,   256,   261,   279,   285,
     300,   318,   335,   349,   364,   371,   375,   385,   394,   415,
     425,   431,   435,   445,   508,   524,   545,   244,   245,   246,
     246,   319,   395,   426,   246,   436,   246,   509,   350,   416,
     336,   246,   246,   301,   365,   246,   246,   376,   386,   246,
       1,    36,    46,   105,   280,   281,   282,   283,   284,     1,
      13,    33,    34,    39,    41,    83,    84,    90,    91,   111,
     112,   126,   127,   137,   146,   232,   233,   234,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   246,   246,
     246,     1,    76,   432,   433,   434,   246,     1,     8,     9,
      19,    27,    31,    32,    38,    42,    43,    45,    51,    60,
      61,    65,    70,    74,    75,    78,    81,    82,    89,    95,
      96,    98,    99,   100,   101,   102,   113,   121,   122,   123,
     125,   128,   129,   132,   143,   165,   167,   171,   175,   176,
     177,   178,   179,   183,   184,   192,   221,   223,   225,   231,
     236,   241,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   500,   504,   505,   506,   507,   246,   246,
     246,   246,     1,   222,   235,   286,   287,   288,   289,   290,
     291,     1,   103,   131,   257,   258,   259,   260,   246,   246,
       1,    40,    53,    66,    67,    68,    69,    86,   546,   547,
     548,   549,   550,   551,   552,   553,   554,     1,    36,    72,
     105,   107,   108,   148,   150,   151,   166,   203,   237,   238,
     262,   263,   264,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   246,   246,     1,   105,   372,   373,
     374,   244,   247,   247,   247,   245,   281,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   245,   526,     1,    22,    23,
      29,    92,    93,    94,    97,   105,   117,   118,   133,   134,
     161,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,     1,     3,     6,    24,
      25,    48,    52,    71,    73,    85,   105,   135,   149,   162,
     237,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   409,   410,   411,   412,   413,   414,     1,    76,   138,
     427,   428,   429,   430,   247,   245,   433,     1,   105,   138,
     170,   437,   441,   442,   443,   444,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   501,   247,   497,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     245,   447,     1,     4,    44,    47,    88,   105,   230,   510,
     511,   512,   513,   514,   518,   519,   520,     1,    25,    48,
      52,   130,   139,   140,   173,   230,   351,   352,   353,   354,
     355,   356,   357,   361,   362,   363,     1,   138,   170,   230,
     417,   421,   422,   423,   424,     1,    52,    71,    76,   135,
     337,   341,   342,   343,   347,   348,   244,   247,   247,   245,
     287,   243,   244,   247,   247,   245,   258,     1,    25,    48,
      52,   105,   130,   149,   212,   230,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   314,     1,    21,   109,   138,
     366,   367,   368,   369,   370,   247,   247,   247,   247,   247,
     247,   247,   245,   547,   244,   247,   247,   247,   247,   247,
     247,   247,   265,   247,   247,   247,   247,   245,   263,     1,
     105,   170,   230,   377,   378,   379,   380,   381,     1,   105,
     170,   387,   388,   389,   390,   247,   245,   373,   136,   136,
     136,   244,   180,   115,   115,   180,   180,   115,   253,   253,
     115,   115,   180,   180,   115,   253,   180,   180,   180,   180,
     180,   244,   244,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   245,   321,   244,   247,
     247,   247,   247,   247,   406,   247,   247,   247,   247,   247,
     247,   247,   247,   245,   397,   247,   247,   245,   428,   136,
     244,   247,   247,   438,   245,   442,   180,   253,   253,   115,
     136,   115,   180,   180,   115,   136,   180,   115,   115,   115,
     180,   180,   180,   253,   136,   180,   115,   115,   253,   115,
     115,   136,   115,   115,   180,   180,   247,   180,   247,   253,
     253,   180,   253,   136,   180,   180,   180,   180,   181,   180,
     181,   180,   180,   253,   253,   115,   255,   136,   253,   180,
     180,   180,   180,   244,   521,   247,   247,   515,   247,   247,
     245,   511,   244,   247,   247,   358,   247,   247,   247,   247,
     247,   245,   352,   247,   418,   247,   245,   422,   244,   338,
     247,   247,   247,   245,   342,   180,   180,   244,   246,   136,
     136,   244,   244,   247,   247,   315,   247,   247,   247,   311,
     247,   245,   303,   244,   247,   247,   247,   245,   367,   180,
     180,   180,   136,   180,   180,   253,   244,   136,   180,   136,
     136,   136,   136,   136,   247,   136,   115,   136,   136,   244,
     244,   247,   382,   247,   245,   378,   244,   247,   391,   245,
     388,   136,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   156,   157,   158,   159,   160,   252,   253,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   115,   115,   253,   115,   115,   115,   115,   136,   115,
     115,   253,   253,   255,   244,   136,   200,   201,   136,   136,
     180,   247,   136,   136,   136,   136,   115,   136,   136,   136,
     244,   136,   136,   244,   244,   136,   136,   247,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,    66,
     187,   188,   189,   190,   191,   193,   194,   197,   198,   199,
     202,   204,   205,   206,   208,   209,   210,   213,   218,   502,
     503,   244,    66,   187,   188,   189,   190,   191,   193,   194,
     197,   198,   199,   202,   204,   205,   206,   208,   209,   210,
     213,   218,   498,   499,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
      14,    15,    16,   254,   255,   244,   244,   244,   244,   244,
     244,   244,   247,   253,   180,   247,   136,   136,   244,   136,
     180,   247,   136,   115,   136,   136,   136,   244,   136,   247,
     136,   244,   247,   136,   136,   115,   345,   346,   244,   244,
     244,     1,   105,   170,   242,   292,   293,   294,   295,   296,
     244,   244,   136,   180,   247,   136,   136,   136,   247,   136,
     244,   136,   136,   136,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   152,
     153,   266,   267,   244,   244,   244,   244,   136,   247,   136,
     244,   136,   247,   244,   244,   252,   252,   252,   252,   252,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,    10,
      12,    26,    30,   224,   407,   408,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   141,   439,
     440,   244,   248,   244,   248,   254,   254,   254,    11,   182,
     522,   523,   244,   244,    11,   182,   516,   517,   244,   244,
     244,   244,    20,    49,    58,    64,    80,   106,   114,   155,
     174,   359,   360,   244,   244,   244,   244,   244,   244,   141,
     419,   420,   244,    66,   207,   211,   339,   340,   244,   244,
     185,   248,   344,   244,   247,   297,   247,   245,   293,   244,
     244,     5,    37,    56,    62,    79,   103,   110,   124,   142,
     144,   145,   205,   217,   219,   229,   239,   316,   317,   244,
     244,   244,    66,   187,   188,   189,   190,   191,   193,   194,
     197,   198,   199,   202,   204,   205,   206,   208,   209,   210,
     213,   218,   312,   313,   244,   244,   244,   244,   244,   248,
     244,    79,   154,   186,   202,   215,   216,   226,   227,   228,
     229,   239,   383,   384,   244,   244,    79,   154,   186,   202,
     215,   216,   226,   227,   228,   229,   239,   392,   393,   244,
     248,   244,   248,   503,   499,   244,   248,   244,   248,   244,
     248,   244,   248,   244,   248,   115,   346,   244,   136,   247,
     214,   255,   244,   244,   248,   244,   248,   267,   244,   248,
     244,   248,   408,   440,   523,   517,   360,   420,   340,   244,
      56,    77,    79,   120,   194,   195,   230,   298,   299,   244,
     244,   317,   313,   384,   393,   244,   248,   299
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
#line 409 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 411 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 415 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 419 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 423 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 436 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 437 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 439 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 440 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 460 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 480 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 486 "ircd_parser.y"
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
#line 500 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 506 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 514 "ircd_parser.y"
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
#line 548 "ircd_parser.y"
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
#line 608 "ircd_parser.y"
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
#line 623 "ircd_parser.y"
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
#line 638 "ircd_parser.y"
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
#line 647 "ircd_parser.y"
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
#line 661 "ircd_parser.y"
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
#line 670 "ircd_parser.y"
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
#line 698 "ircd_parser.y"
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
#line 728 "ircd_parser.y"
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
#line 751 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 766 "ircd_parser.y"
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
#line 775 "ircd_parser.y"
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
#line 784 "ircd_parser.y"
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
#line 802 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 808 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 814 "ircd_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 819 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 831 "ircd_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 836 "ircd_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 839 "ircd_parser.y"
    {
  lsize = 0;
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 844 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 855 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 859 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 863 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 867 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 871 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 875 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 885 "ircd_parser.y"
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
#line 898 "ircd_parser.y"
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
#line 988 "ircd_parser.y"
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
#line 1000 "ircd_parser.y"
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
#line 1037 "ircd_parser.y"
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
#line 1049 "ircd_parser.y"
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
#line 1060 "ircd_parser.y"
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
#line 1102 "ircd_parser.y"
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
#line 1111 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1118 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1122 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1126 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1130 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1134 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1138 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1142 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1146 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1150 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1154 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1158 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1162 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1166 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1170 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1200 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1207 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1211 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1215 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1219 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1227 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1231 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1243 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1247 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1251 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1255 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1259 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1263 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1267 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1277 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1284 "ircd_parser.y"
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

  case 204:

/* Line 1806 of yacc.c  */
#line 1342 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 205:

/* Line 1806 of yacc.c  */
#line 1351 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 1357 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1363 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1369 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1375 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1381 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1387 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1405 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1417 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1426 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1433 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1442 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1448 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1452 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1466 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 237:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
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

  case 238:

/* Line 1806 of yacc.c  */
#line 1485 "ircd_parser.y"
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

  case 239:

/* Line 1806 of yacc.c  */
#line 1505 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 240:

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

  case 241:

/* Line 1806 of yacc.c  */
#line 1526 "ircd_parser.y"
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

  case 242:

/* Line 1806 of yacc.c  */
#line 1538 "ircd_parser.y"
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

  case 254:

/* Line 1806 of yacc.c  */
#line 1600 "ircd_parser.y"
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

  case 255:

/* Line 1806 of yacc.c  */
#line 1637 "ircd_parser.y"
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

  case 256:

/* Line 1806 of yacc.c  */
#line 1650 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 257:

/* Line 1806 of yacc.c  */
#line 1659 "ircd_parser.y"
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

  case 258:

/* Line 1806 of yacc.c  */
#line 1670 "ircd_parser.y"
    {
}
    break;

  case 262:

/* Line 1806 of yacc.c  */
#line 1675 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1679 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1683 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1687 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1691 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1695 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1699 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1703 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1707 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1714 "ircd_parser.y"
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

  case 272:

/* Line 1806 of yacc.c  */
#line 1733 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1743 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1756 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1763 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1775 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1784 "ircd_parser.y"
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

  case 284:

/* Line 1806 of yacc.c  */
#line 1799 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1817 "ircd_parser.y"
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

  case 291:

/* Line 1806 of yacc.c  */
#line 1832 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1860 "ircd_parser.y"
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

  case 301:

/* Line 1806 of yacc.c  */
#line 1882 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 305:

/* Line 1806 of yacc.c  */
#line 1889 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1893 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1897 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1901 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1905 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1909 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1913 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1917 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1921 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1925 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1929 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1938 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1945 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1958 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1964 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 1971 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1975 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1979 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1983 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1987 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1991 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1995 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1999 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2003 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2007 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2011 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2020 "ircd_parser.y"
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
#line 2035 "ircd_parser.y"
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
#line 2172 "ircd_parser.y"
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
#line 2184 "ircd_parser.y"
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
#line 2193 "ircd_parser.y"
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
#line 2219 "ircd_parser.y"
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
#line 2237 "ircd_parser.y"
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
#line 2255 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 2261 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2265 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 2273 "ircd_parser.y"
    {
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2278 "ircd_parser.y"
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
#line 2288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2292 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2296 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2300 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2306 "ircd_parser.y"
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
#line 2347 "ircd_parser.y"
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
#line 2358 "ircd_parser.y"
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
#line 2371 "ircd_parser.y"
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
#line 2384 "ircd_parser.y"
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
#line 2393 "ircd_parser.y"
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
#line 2428 "ircd_parser.y"
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
#line 2435 "ircd_parser.y"
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
#line 2491 "ircd_parser.y"
    {
}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2496 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 394:

/* Line 1806 of yacc.c  */
#line 2505 "ircd_parser.y"
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
#line 2524 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 396:

/* Line 1806 of yacc.c  */
#line 2533 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2537 "ircd_parser.y"
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
#line 2559 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 2565 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 2579 "ircd_parser.y"
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
#line 2597 "ircd_parser.y"
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
#line 2604 "ircd_parser.y"
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
#line 2644 "ircd_parser.y"
    {
}
    break;

  case 417:

/* Line 1806 of yacc.c  */
#line 2649 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 424:

/* Line 1806 of yacc.c  */
#line 2658 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 2664 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2709 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2714 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2719 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2724 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2729 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2734 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2739 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2744 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2749 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2754 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2759 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2764 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2769 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2774 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2779 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2784 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2789 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2794 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2800 "ircd_parser.y"
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
#line 2811 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2816 "ircd_parser.y"
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
#line 2825 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2830 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2835 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2840 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2845 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2850 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2853 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2858 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2861 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2866 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2871 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2876 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2881 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2886 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2891 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2896 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2901 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2906 "ircd_parser.y"
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
#line 2917 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2922 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2927 "ircd_parser.y"
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
#line 2936 "ircd_parser.y"
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
#line 2968 "ircd_parser.y"
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
#line 2986 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2991 "ircd_parser.y"
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
#line 3000 "ircd_parser.y"
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
#line 3009 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3014 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3019 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3024 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3030 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3033 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3036 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3039 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3042 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3048 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3051 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3054 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3057 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3063 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3066 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3069 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3072 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3081 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3087 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3092 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3098 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3101 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3104 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3107 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3110 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3113 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3116 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3119 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3122 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3125 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3128 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3131 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3134 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3140 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3143 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3146 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3149 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3155 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3160 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3175 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3184 "ircd_parser.y"
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
#line 3191 "ircd_parser.y"
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
#line 3217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
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
#line 3279 "ircd_parser.y"
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
#line 3288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3292 "ircd_parser.y"
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
#line 3339 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3343 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3367 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3372 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3377 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3382 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3387 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3392 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3397 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3402 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3407 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3412 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3417 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3422 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3427 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3432 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3437 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3442 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3447 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3452 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3483 "ircd_parser.y"
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
#line 3492 "ircd_parser.y"
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
#line 3506 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3512 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3518 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7848 "ircd_parser.c"
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



