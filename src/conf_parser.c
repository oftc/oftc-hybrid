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
#line 25 "conf_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "event.h"
#include "log.h"
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
#include <openssl/dh.h>
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
#line 180 "conf_parser.c"

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
     CLASS = 279,
     CONNECT = 280,
     CONNECTFREQ = 281,
     DEFAULT_FLOODCOUNT = 282,
     DEFAULT_SPLIT_SERVER_COUNT = 283,
     DEFAULT_SPLIT_USER_COUNT = 284,
     DENY = 285,
     DESCRIPTION = 286,
     DIE = 287,
     DISABLE_AUTH = 288,
     DISABLE_FAKE_CHANNELS = 289,
     DISABLE_HIDDEN = 290,
     DISABLE_LOCAL_CHANNELS = 291,
     DISABLE_REMOTE_COMMANDS = 292,
     DOTS_IN_IDENT = 293,
     DURATION = 294,
     EGDPOOL_PATH = 295,
     EMAIL = 296,
     ENABLE = 297,
     ENCRYPTED = 298,
     EXCEED_LIMIT = 299,
     EXEMPT = 300,
     FAILED_OPER_NOTICE = 301,
     IRCD_FLAGS = 302,
     FLATTEN_LINKS = 303,
     GECOS = 304,
     GENERAL = 305,
     GLINE = 306,
     GLINES = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
     GLINE_MIN_CIDR = 310,
     GLINE_MIN_CIDR6 = 311,
     GLOBAL_KILL = 312,
     IRCD_AUTH = 313,
     NEED_IDENT = 314,
     HAVENT_READ_CONF = 315,
     HIDDEN = 316,
     HIDDEN_NAME = 317,
     HIDE_SERVER_IPS = 318,
     HIDE_SERVERS = 319,
     HIDE_SPOOF_IPS = 320,
     HOST = 321,
     HUB = 322,
     HUB_MASK = 323,
     IGNORE_BOGUS_TS = 324,
     INVISIBLE_ON_CONNECT = 325,
     IP = 326,
     KILL = 327,
     KILL_CHASE_TIME_LIMIT = 328,
     KLINE = 329,
     KLINE_EXEMPT = 330,
     KLINE_REASON = 331,
     KLINE_WITH_REASON = 332,
     KNOCK_DELAY = 333,
     KNOCK_DELAY_CHANNEL = 334,
     LEAF_MASK = 335,
     LINKS_DELAY = 336,
     LISTEN = 337,
     T_LOG = 338,
     MAX_ACCEPT = 339,
     MAX_BANS = 340,
     MAX_CHANS_PER_USER = 341,
     MAX_GLOBAL = 342,
     MAX_IDENT = 343,
     MAX_LOCAL = 344,
     MAX_NICK_CHANGES = 345,
     MAX_NICK_TIME = 346,
     MAX_NUMBER = 347,
     MAX_TARGETS = 348,
     MAX_WATCH = 349,
     MESSAGE_LOCALE = 350,
     MIN_NONWILDCARD = 351,
     MIN_NONWILDCARD_SIMPLE = 352,
     MODULE = 353,
     MODULES = 354,
     NAME = 355,
     NEED_PASSWORD = 356,
     NETWORK_DESC = 357,
     NETWORK_NAME = 358,
     NICK = 359,
     NICK_CHANGES = 360,
     NO_CREATE_ON_SPLIT = 361,
     NO_JOIN_ON_SPLIT = 362,
     NO_OPER_FLOOD = 363,
     NO_TILDE = 364,
     NUMBER = 365,
     NUMBER_PER_IDENT = 366,
     NUMBER_PER_CIDR = 367,
     NUMBER_PER_IP = 368,
     NUMBER_PER_IP_GLOBAL = 369,
     OPERATOR = 370,
     OPERS_BYPASS_CALLERID = 371,
     OPER_ONLY_UMODES = 372,
     OPER_PASS_RESV = 373,
     OPER_SPY_T = 374,
     OPER_UMODES = 375,
     JOIN_FLOOD_COUNT = 376,
     JOIN_FLOOD_TIME = 377,
     PACE_WAIT = 378,
     PACE_WAIT_SIMPLE = 379,
     PASSWORD = 380,
     PATH = 381,
     PING_COOKIE = 382,
     PING_TIME = 383,
     PING_WARNING = 384,
     PORT = 385,
     QSTRING = 386,
     QUIET_ON_BAN = 387,
     REASON = 388,
     REDIRPORT = 389,
     REDIRSERV = 390,
     REGEX_T = 391,
     REHASH = 392,
     TREJECT_HOLD_TIME = 393,
     REMOTE = 394,
     REMOTEBAN = 395,
     RESTRICT_CHANNELS = 396,
     RESTRICTED = 397,
     RSA_PRIVATE_KEY_FILE = 398,
     RSA_PUBLIC_KEY_FILE = 399,
     SSL_CERTIFICATE_FILE = 400,
     SSL_DH_PARAM_FILE = 401,
     T_SSL_CLIENT_METHOD = 402,
     T_SSL_SERVER_METHOD = 403,
     T_SSLV3 = 404,
     T_TLSV1 = 405,
     RESV = 406,
     RESV_EXEMPT = 407,
     SECONDS = 408,
     MINUTES = 409,
     HOURS = 410,
     DAYS = 411,
     WEEKS = 412,
     SENDQ = 413,
     SEND_PASSWORD = 414,
     SERVERHIDE = 415,
     SERVERINFO = 416,
     IRCD_SID = 417,
     TKLINE_EXPIRE_NOTICES = 418,
     T_SHARED = 419,
     T_CLUSTER = 420,
     TYPE = 421,
     SHORT_MOTD = 422,
     SILENT = 423,
     SPOOF = 424,
     SPOOF_NOTICE = 425,
     STATS_E_DISABLED = 426,
     STATS_I_OPER_ONLY = 427,
     STATS_K_OPER_ONLY = 428,
     STATS_O_OPER_ONLY = 429,
     STATS_P_OPER_ONLY = 430,
     TBOOL = 431,
     TMASKED = 432,
     T_REJECT = 433,
     TS_MAX_DELTA = 434,
     TS_WARN_DELTA = 435,
     TWODOTS = 436,
     T_ALL = 437,
     T_BOTS = 438,
     T_SOFTCALLERID = 439,
     T_CALLERID = 440,
     T_CCONN = 441,
     T_CCONN_FULL = 442,
     T_SSL_CIPHER_LIST = 443,
     T_CLIENT_FLOOD = 444,
     T_DEAF = 445,
     T_DEBUG = 446,
     T_DLINE = 447,
     T_DRONE = 448,
     T_EXTERNAL = 449,
     T_FULL = 450,
     T_INVISIBLE = 451,
     T_IPV4 = 452,
     T_IPV6 = 453,
     T_LOCOPS = 454,
     T_MAX_CLIENTS = 455,
     T_NCHANGE = 456,
     T_OPERWALL = 457,
     T_REJ = 458,
     T_SERVER = 459,
     T_SERVNOTICE = 460,
     T_SKILL = 461,
     T_SPY = 462,
     T_SSL = 463,
     T_UMODES = 464,
     T_UNAUTH = 465,
     T_UNDLINE = 466,
     T_UNLIMITED = 467,
     T_UNRESV = 468,
     T_UNXLINE = 469,
     T_GLOBOPS = 470,
     T_WALLOP = 471,
     T_RESTART = 472,
     T_SERVICE = 473,
     T_SERVICES_NAME = 474,
     T_TIMESTAMP = 475,
     THROTTLE_TIME = 476,
     TOPICBURST = 477,
     TRUE_NO_OPER_FLOOD = 478,
     TKLINE = 479,
     TXLINE = 480,
     TRESV = 481,
     UNKLINE = 482,
     USER = 483,
     USE_EGD = 484,
     USE_EXCEPT = 485,
     USE_INVEX = 486,
     USE_KNOCK = 487,
     USE_LOGGING = 488,
     USE_WHOIS_ACTUALLY = 489,
     VHOST = 490,
     VHOST6 = 491,
     XLINE = 492,
     WARN = 493,
     WARN_NO_NLINE = 494,
     T_SIZE = 495,
     T_FILE = 496
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
#define CLASS 279
#define CONNECT 280
#define CONNECTFREQ 281
#define DEFAULT_FLOODCOUNT 282
#define DEFAULT_SPLIT_SERVER_COUNT 283
#define DEFAULT_SPLIT_USER_COUNT 284
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_HIDDEN 290
#define DISABLE_LOCAL_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DOTS_IN_IDENT 293
#define DURATION 294
#define EGDPOOL_PATH 295
#define EMAIL 296
#define ENABLE 297
#define ENCRYPTED 298
#define EXCEED_LIMIT 299
#define EXEMPT 300
#define FAILED_OPER_NOTICE 301
#define IRCD_FLAGS 302
#define FLATTEN_LINKS 303
#define GECOS 304
#define GENERAL 305
#define GLINE 306
#define GLINES 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
#define GLINE_MIN_CIDR 310
#define GLINE_MIN_CIDR6 311
#define GLOBAL_KILL 312
#define IRCD_AUTH 313
#define NEED_IDENT 314
#define HAVENT_READ_CONF 315
#define HIDDEN 316
#define HIDDEN_NAME 317
#define HIDE_SERVER_IPS 318
#define HIDE_SERVERS 319
#define HIDE_SPOOF_IPS 320
#define HOST 321
#define HUB 322
#define HUB_MASK 323
#define IGNORE_BOGUS_TS 324
#define INVISIBLE_ON_CONNECT 325
#define IP 326
#define KILL 327
#define KILL_CHASE_TIME_LIMIT 328
#define KLINE 329
#define KLINE_EXEMPT 330
#define KLINE_REASON 331
#define KLINE_WITH_REASON 332
#define KNOCK_DELAY 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LINKS_DELAY 336
#define LISTEN 337
#define T_LOG 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANS_PER_USER 341
#define MAX_GLOBAL 342
#define MAX_IDENT 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_TIME 346
#define MAX_NUMBER 347
#define MAX_TARGETS 348
#define MAX_WATCH 349
#define MESSAGE_LOCALE 350
#define MIN_NONWILDCARD 351
#define MIN_NONWILDCARD_SIMPLE 352
#define MODULE 353
#define MODULES 354
#define NAME 355
#define NEED_PASSWORD 356
#define NETWORK_DESC 357
#define NETWORK_NAME 358
#define NICK 359
#define NICK_CHANGES 360
#define NO_CREATE_ON_SPLIT 361
#define NO_JOIN_ON_SPLIT 362
#define NO_OPER_FLOOD 363
#define NO_TILDE 364
#define NUMBER 365
#define NUMBER_PER_IDENT 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP 368
#define NUMBER_PER_IP_GLOBAL 369
#define OPERATOR 370
#define OPERS_BYPASS_CALLERID 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
#define OPER_SPY_T 374
#define OPER_UMODES 375
#define JOIN_FLOOD_COUNT 376
#define JOIN_FLOOD_TIME 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PING_WARNING 384
#define PORT 385
#define QSTRING 386
#define QUIET_ON_BAN 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REGEX_T 391
#define REHASH 392
#define TREJECT_HOLD_TIME 393
#define REMOTE 394
#define REMOTEBAN 395
#define RESTRICT_CHANNELS 396
#define RESTRICTED 397
#define RSA_PRIVATE_KEY_FILE 398
#define RSA_PUBLIC_KEY_FILE 399
#define SSL_CERTIFICATE_FILE 400
#define SSL_DH_PARAM_FILE 401
#define T_SSL_CLIENT_METHOD 402
#define T_SSL_SERVER_METHOD 403
#define T_SSLV3 404
#define T_TLSV1 405
#define RESV 406
#define RESV_EXEMPT 407
#define SECONDS 408
#define MINUTES 409
#define HOURS 410
#define DAYS 411
#define WEEKS 412
#define SENDQ 413
#define SEND_PASSWORD 414
#define SERVERHIDE 415
#define SERVERINFO 416
#define IRCD_SID 417
#define TKLINE_EXPIRE_NOTICES 418
#define T_SHARED 419
#define T_CLUSTER 420
#define TYPE 421
#define SHORT_MOTD 422
#define SILENT 423
#define SPOOF 424
#define SPOOF_NOTICE 425
#define STATS_E_DISABLED 426
#define STATS_I_OPER_ONLY 427
#define STATS_K_OPER_ONLY 428
#define STATS_O_OPER_ONLY 429
#define STATS_P_OPER_ONLY 430
#define TBOOL 431
#define TMASKED 432
#define T_REJECT 433
#define TS_MAX_DELTA 434
#define TS_WARN_DELTA 435
#define TWODOTS 436
#define T_ALL 437
#define T_BOTS 438
#define T_SOFTCALLERID 439
#define T_CALLERID 440
#define T_CCONN 441
#define T_CCONN_FULL 442
#define T_SSL_CIPHER_LIST 443
#define T_CLIENT_FLOOD 444
#define T_DEAF 445
#define T_DEBUG 446
#define T_DLINE 447
#define T_DRONE 448
#define T_EXTERNAL 449
#define T_FULL 450
#define T_INVISIBLE 451
#define T_IPV4 452
#define T_IPV6 453
#define T_LOCOPS 454
#define T_MAX_CLIENTS 455
#define T_NCHANGE 456
#define T_OPERWALL 457
#define T_REJ 458
#define T_SERVER 459
#define T_SERVNOTICE 460
#define T_SKILL 461
#define T_SPY 462
#define T_SSL 463
#define T_UMODES 464
#define T_UNAUTH 465
#define T_UNDLINE 466
#define T_UNLIMITED 467
#define T_UNRESV 468
#define T_UNXLINE 469
#define T_GLOBOPS 470
#define T_WALLOP 471
#define T_RESTART 472
#define T_SERVICE 473
#define T_SERVICES_NAME 474
#define T_TIMESTAMP 475
#define THROTTLE_TIME 476
#define TOPICBURST 477
#define TRUE_NO_OPER_FLOOD 478
#define TKLINE 479
#define TXLINE 480
#define TRESV 481
#define UNKLINE 482
#define USER 483
#define USE_EGD 484
#define USE_EXCEPT 485
#define USE_INVEX 486
#define USE_KNOCK 487
#define USE_LOGGING 488
#define USE_WHOIS_ACTUALLY 489
#define VHOST 490
#define VHOST6 491
#define XLINE 492
#define WARN 493
#define WARN_NO_NLINE 494
#define T_SIZE 495
#define T_FILE 496




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 133 "conf_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 705 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 717 "conf_parser.c"

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
#define YYLAST   1267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  247
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  670
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1316

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   496

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   246,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   242,
       2,   245,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   244,     2,   243,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241
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
     154,   156,   158,   160,   162,   164,   166,   168,   171,   176,
     181,   185,   187,   189,   191,   195,   197,   199,   201,   206,
     211,   216,   221,   226,   231,   236,   241,   246,   251,   256,
     261,   266,   272,   275,   277,   279,   281,   283,   286,   291,
     296,   301,   307,   310,   312,   314,   316,   318,   321,   326,
     331,   332,   339,   342,   344,   346,   348,   350,   353,   358,
     363,   368,   369,   375,   379,   381,   383,   385,   387,   389,
     391,   393,   395,   396,   403,   406,   408,   410,   412,   414,
     416,   418,   420,   422,   424,   427,   432,   437,   442,   447,
     452,   457,   458,   464,   468,   470,   472,   474,   476,   478,
     480,   482,   484,   486,   488,   490,   492,   494,   496,   498,
     500,   502,   504,   506,   508,   510,   511,   517,   521,   523,
     525,   527,   529,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   560,   567,
     570,   572,   574,   576,   578,   580,   582,   584,   586,   588,
     590,   592,   594,   596,   598,   601,   606,   611,   616,   621,
     626,   631,   636,   641,   646,   651,   656,   661,   666,   667,
     674,   675,   681,   685,   687,   689,   691,   693,   696,   698,
     700,   702,   704,   706,   709,   710,   716,   720,   722,   724,
     728,   733,   738,   739,   746,   749,   751,   753,   755,   757,
     759,   761,   763,   765,   767,   770,   775,   780,   785,   790,
     791,   797,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   819,   821,   826,   831,   836,   837,   844,   847,   849,
     851,   853,   855,   858,   863,   868,   873,   879,   882,   884,
     886,   888,   893,   894,   901,   904,   906,   908,   910,   912,
     915,   920,   925,   926,   932,   936,   938,   940,   942,   944,
     946,   948,   950,   952,   954,   956,   958,   959,   966,   969,
     971,   973,   975,   978,   983,   984,   990,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1017,
    1024,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1058,  1063,  1068,  1073,
    1078,  1083,  1088,  1093,  1098,  1099,  1105,  1109,  1111,  1113,
    1115,  1117,  1119,  1124,  1129,  1134,  1139,  1144,  1145,  1152,
    1153,  1159,  1163,  1165,  1167,  1170,  1172,  1174,  1176,  1178,
    1180,  1185,  1190,  1191,  1198,  1201,  1203,  1205,  1207,  1209,
    1214,  1219,  1225,  1228,  1230,  1232,  1234,  1239,  1240,  1247,
    1248,  1254,  1258,  1260,  1262,  1265,  1267,  1269,  1271,  1273,
    1275,  1280,  1285,  1291,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,
    1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,
    1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1405,  1410,
    1415,  1420,  1425,  1430,  1435,  1440,  1445,  1450,  1455,  1460,
    1465,  1470,  1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,
    1515,  1520,  1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,
    1565,  1570,  1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,
    1615,  1620,  1625,  1630,  1635,  1636,  1642,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,
    1672,  1674,  1676,  1678,  1680,  1682,  1684,  1686,  1688,  1689,
    1695,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,
    1737,  1739,  1741,  1746,  1751,  1756,  1761,  1762,  1769,  1772,
    1774,  1776,  1778,  1780,  1782,  1784,  1786,  1788,  1793,  1798,
    1799,  1805,  1809,  1811,  1813,  1815,  1820,  1825,  1826,  1832,
    1836,  1838,  1840,  1842,  1848,  1851,  1853,  1855,  1857,  1859,
    1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,  1879,
    1881,  1883,  1885,  1887,  1889,  1891,  1896,  1901,  1906,  1911,
    1916,  1921,  1926,  1931,  1936,  1941,  1946,  1951,  1956,  1961,
    1966,  1971,  1976,  1981,  1987,  1990,  1992,  1994,  1996,  1998,
    2000,  2002,  2004,  2006,  2008,  2013,  2018,  2023,  2028,  2033,
    2038
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     248,     0,    -1,    -1,   248,   249,    -1,   281,    -1,   287,
      -1,   302,    -1,   522,    -1,   320,    -1,   337,    -1,   351,
      -1,   259,    -1,   543,    -1,   366,    -1,   373,    -1,   377,
      -1,   387,    -1,   396,    -1,   416,    -1,   426,    -1,   432,
      -1,   446,    -1,   506,    -1,   436,    -1,   254,    -1,     1,
     242,    -1,     1,   243,    -1,    -1,   251,    -1,   110,   250,
      -1,   110,   153,   250,    -1,   110,   154,   250,    -1,   110,
     155,   250,    -1,   110,   156,   250,    -1,   110,   157,   250,
      -1,    -1,   253,    -1,   110,   252,    -1,   110,    14,   252,
      -1,   110,    15,   252,    -1,   110,    16,   252,    -1,    99,
     244,   255,   243,   242,    -1,   255,   256,    -1,   256,    -1,
     257,    -1,   258,    -1,     1,   242,    -1,    98,   245,   131,
     242,    -1,   126,   245,   131,   242,    -1,   161,   244,   260,
     243,   242,    -1,   260,   261,    -1,   261,    -1,   272,    -1,
     277,    -1,   280,    -1,   274,    -1,   275,    -1,   276,    -1,
     279,    -1,   270,    -1,   269,    -1,   278,    -1,   273,    -1,
     268,    -1,   262,    -1,   263,    -1,   271,    -1,     1,   242,
      -1,   147,   245,   264,   242,    -1,   148,   245,   266,   242,
      -1,   264,   246,   265,    -1,   265,    -1,   149,    -1,   150,
      -1,   266,   246,   267,    -1,   267,    -1,   149,    -1,   150,
      -1,   145,   245,   131,   242,    -1,   143,   245,   131,   242,
      -1,   146,   245,   131,   242,    -1,   188,   245,   131,   242,
      -1,   100,   245,   131,   242,    -1,   162,   245,   131,   242,
      -1,    31,   245,   131,   242,    -1,   103,   245,   131,   242,
      -1,   102,   245,   131,   242,    -1,   235,   245,   131,   242,
      -1,   236,   245,   131,   242,    -1,   200,   245,   110,   242,
      -1,    67,   245,   176,   242,    -1,     5,   244,   282,   243,
     242,    -1,   282,   283,    -1,   283,    -1,   284,    -1,   286,
      -1,   285,    -1,     1,   242,    -1,   100,   245,   131,   242,
      -1,    41,   245,   131,   242,    -1,    31,   245,   131,   242,
      -1,    83,   244,   288,   243,   242,    -1,   288,   289,    -1,
     289,    -1,   290,    -1,   291,    -1,   292,    -1,     1,   242,
      -1,   233,   245,   176,   242,    -1,   220,   245,   176,   242,
      -1,    -1,   293,   241,   244,   294,   243,   242,    -1,   294,
     295,    -1,   295,    -1,   296,    -1,   298,    -1,   297,    -1,
       1,   242,    -1,   100,   245,   131,   242,    -1,   240,   245,
     253,   242,    -1,   240,   245,   212,   242,    -1,    -1,   166,
     299,   245,   300,   242,    -1,   300,   246,   301,    -1,   301,
      -1,   228,    -1,   115,    -1,    51,    -1,   192,    -1,    74,
      -1,    72,    -1,   191,    -1,    -1,   115,   303,   244,   304,
     243,   242,    -1,   304,   305,    -1,   305,    -1,   306,    -1,
     307,    -1,   308,    -1,   312,    -1,   311,    -1,   309,    -1,
     310,    -1,   316,    -1,     1,   242,    -1,   100,   245,   131,
     242,    -1,   228,   245,   131,   242,    -1,   125,   245,   131,
     242,    -1,    43,   245,   176,   242,    -1,   144,   245,   131,
     242,    -1,    24,   245,   131,   242,    -1,    -1,   209,   313,
     245,   314,   242,    -1,   314,   246,   315,    -1,   315,    -1,
     183,    -1,   186,    -1,   187,    -1,   190,    -1,   191,    -1,
     195,    -1,    61,    -1,   206,    -1,   201,    -1,   203,    -1,
     210,    -1,   207,    -1,   194,    -1,   202,    -1,   205,    -1,
     196,    -1,   216,    -1,   184,    -1,   185,    -1,   199,    -1,
      -1,    47,   317,   245,   318,   242,    -1,   318,   246,   319,
      -1,   319,    -1,    57,    -1,   139,    -1,    74,    -1,   227,
      -1,   192,    -1,   211,    -1,   237,    -1,    51,    -1,    32,
      -1,   217,    -1,   137,    -1,     5,    -1,   105,    -1,   202,
      -1,   215,    -1,   119,    -1,   140,    -1,    98,    -1,    -1,
      24,   321,   244,   322,   243,   242,    -1,   322,   323,    -1,
     323,    -1,   324,    -1,   334,    -1,   335,    -1,   325,    -1,
     326,    -1,   336,    -1,   327,    -1,   328,    -1,   329,    -1,
     330,    -1,   331,    -1,   332,    -1,   333,    -1,     1,   242,
      -1,   100,   245,   131,   242,    -1,   128,   245,   251,   242,
      -1,   129,   245,   251,   242,    -1,   113,   245,   110,   242,
      -1,    26,   245,   251,   242,    -1,    92,   245,   110,   242,
      -1,    87,   245,   110,   242,    -1,    89,   245,   110,   242,
      -1,    88,   245,   110,   242,    -1,   158,   245,   253,   242,
      -1,    22,   245,   110,   242,    -1,    23,   245,   110,   242,
      -1,   112,   245,   110,   242,    -1,    -1,    82,   338,   244,
     343,   243,   242,    -1,    -1,    47,   340,   245,   341,   242,
      -1,   341,   246,   342,    -1,   342,    -1,   208,    -1,    61,
      -1,   204,    -1,   343,   344,    -1,   344,    -1,   345,    -1,
     339,    -1,   349,    -1,   350,    -1,     1,   242,    -1,    -1,
     130,   245,   347,   346,   242,    -1,   347,   246,   348,    -1,
     348,    -1,   110,    -1,   110,   181,   110,    -1,    71,   245,
     131,   242,    -1,    66,   245,   131,   242,    -1,    -1,    58,
     352,   244,   353,   243,   242,    -1,   353,   354,    -1,   354,
      -1,   355,    -1,   356,    -1,   357,    -1,   359,    -1,   363,
      -1,   364,    -1,   365,    -1,   358,    -1,     1,   242,    -1,
     228,   245,   131,   242,    -1,   125,   245,   131,   242,    -1,
      24,   245,   131,   242,    -1,    43,   245,   176,   242,    -1,
      -1,    47,   360,   245,   361,   242,    -1,   361,   246,   362,
      -1,   362,    -1,   170,    -1,    44,    -1,    75,    -1,    59,
      -1,    20,    -1,   109,    -1,    53,    -1,   152,    -1,   101,
      -1,   169,   245,   131,   242,    -1,   135,   245,   131,   242,
      -1,   134,   245,   110,   242,    -1,    -1,   151,   367,   244,
     368,   243,   242,    -1,   368,   369,    -1,   369,    -1,   370,
      -1,   371,    -1,   372,    -1,     1,   242,    -1,   133,   245,
     131,   242,    -1,    21,   245,   131,   242,    -1,   104,   245,
     131,   242,    -1,   218,   244,   374,   243,   242,    -1,   374,
     375,    -1,   375,    -1,   376,    -1,     1,    -1,   100,   245,
     131,   242,    -1,    -1,   164,   378,   244,   379,   243,   242,
      -1,   379,   380,    -1,   380,    -1,   381,    -1,   382,    -1,
     383,    -1,     1,   242,    -1,   100,   245,   131,   242,    -1,
     228,   245,   131,   242,    -1,    -1,   166,   384,   245,   385,
     242,    -1,   385,   246,   386,    -1,   386,    -1,    74,    -1,
     227,    -1,   192,    -1,   211,    -1,   237,    -1,   214,    -1,
     151,    -1,   213,    -1,   199,    -1,   182,    -1,    -1,   165,
     388,   244,   389,   243,   242,    -1,   389,   390,    -1,   390,
      -1,   391,    -1,   392,    -1,     1,   242,    -1,   100,   245,
     131,   242,    -1,    -1,   166,   393,   245,   394,   242,    -1,
     394,   246,   395,    -1,   395,    -1,    74,    -1,   227,    -1,
     192,    -1,   211,    -1,   237,    -1,   214,    -1,   151,    -1,
     213,    -1,   199,    -1,   182,    -1,    -1,    25,   397,   244,
     398,   243,   242,    -1,   398,   399,    -1,   399,    -1,   400,
      -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,   406,
      -1,   405,    -1,   415,    -1,   407,    -1,   412,    -1,   413,
      -1,   414,    -1,   411,    -1,     1,   242,    -1,   100,   245,
     131,   242,    -1,    66,   245,   131,   242,    -1,   235,   245,
     131,   242,    -1,   159,   245,   131,   242,    -1,     3,   245,
     131,   242,    -1,   130,   245,   110,   242,    -1,     6,   245,
     197,   242,    -1,     6,   245,   198,   242,    -1,    -1,    47,
     408,   245,   409,   242,    -1,   409,   246,   410,    -1,   410,
      -1,    10,    -1,    12,    -1,   222,    -1,   208,    -1,    43,
     245,   176,   242,    -1,    68,   245,   131,   242,    -1,    80,
     245,   131,   242,    -1,    24,   245,   131,   242,    -1,   188,
     245,   131,   242,    -1,    -1,    72,   417,   244,   422,   243,
     242,    -1,    -1,   166,   419,   245,   420,   242,    -1,   420,
     246,   421,    -1,   421,    -1,   136,    -1,   422,   423,    -1,
     423,    -1,   424,    -1,   425,    -1,   418,    -1,     1,    -1,
     228,   245,   131,   242,    -1,   133,   245,   131,   242,    -1,
      -1,    30,   427,   244,   428,   243,   242,    -1,   428,   429,
      -1,   429,    -1,   430,    -1,   431,    -1,     1,    -1,    71,
     245,   131,   242,    -1,   133,   245,   131,   242,    -1,    45,
     244,   433,   243,   242,    -1,   433,   434,    -1,   434,    -1,
     435,    -1,     1,    -1,    71,   245,   131,   242,    -1,    -1,
      49,   437,   244,   442,   243,   242,    -1,    -1,   166,   439,
     245,   440,   242,    -1,   440,   246,   441,    -1,   441,    -1,
     136,    -1,   442,   443,    -1,   443,    -1,   444,    -1,   445,
      -1,   438,    -1,     1,    -1,   100,   245,   131,   242,    -1,
     133,   245,   131,   242,    -1,    50,   244,   447,   243,   242,
      -1,   447,   448,    -1,   448,    -1,   456,    -1,   457,    -1,
     459,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     464,    -1,   465,    -1,   466,    -1,   455,    -1,   468,    -1,
     469,    -1,   470,    -1,   471,    -1,   486,    -1,   473,    -1,
     475,    -1,   477,    -1,   476,    -1,   480,    -1,   474,    -1,
     481,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     498,    -1,   487,    -1,   488,    -1,   489,    -1,   494,    -1,
     478,    -1,   479,    -1,   504,    -1,   502,    -1,   503,    -1,
     458,    -1,   505,    -1,   493,    -1,   467,    -1,   491,    -1,
     492,    -1,   454,    -1,   450,    -1,   451,    -1,   452,    -1,
     453,    -1,   472,    -1,   449,    -1,   490,    -1,     1,    -1,
      94,   245,   110,   242,    -1,    55,   245,   110,   242,    -1,
      56,   245,   110,   242,    -1,   234,   245,   176,   242,    -1,
     138,   245,   251,   242,    -1,   163,   245,   176,   242,    -1,
      73,   245,   251,   242,    -1,    65,   245,   176,   242,    -1,
      69,   245,   176,   242,    -1,    37,   245,   176,   242,    -1,
      46,   245,   176,   242,    -1,     8,   245,   176,   242,    -1,
      91,   245,   251,   242,    -1,    90,   245,   110,   242,    -1,
      84,   245,   110,   242,    -1,     9,   245,   251,   242,    -1,
     180,   245,   251,   242,    -1,   179,   245,   251,   242,    -1,
      60,   245,   110,   242,    -1,    77,   245,   176,   242,    -1,
      76,   245,   131,   242,    -1,    70,   245,   176,   242,    -1,
     239,   245,   176,   242,    -1,   171,   245,   176,   242,    -1,
     174,   245,   176,   242,    -1,   175,   245,   176,   242,    -1,
     173,   245,   176,   242,    -1,   173,   245,   177,   242,    -1,
     172,   245,   176,   242,    -1,   172,   245,   177,   242,    -1,
     123,   245,   251,   242,    -1,    19,   245,   251,   242,    -1,
     116,   245,   176,   242,    -1,   124,   245,   251,   242,    -1,
     167,   245,   176,   242,    -1,   108,   245,   176,   242,    -1,
     223,   245,   176,   242,    -1,   118,   245,   176,   242,    -1,
      95,   245,   131,   242,    -1,    38,   245,   110,   242,    -1,
      93,   245,   110,   242,    -1,   229,   245,   176,   242,    -1,
      40,   245,   131,   242,    -1,   219,   245,   131,   242,    -1,
     127,   245,   176,   242,    -1,    33,   245,   176,   242,    -1,
     221,   245,   251,   242,    -1,    -1,   120,   495,   245,   496,
     242,    -1,   496,   246,   497,    -1,   497,    -1,   183,    -1,
     186,    -1,   187,    -1,   190,    -1,   191,    -1,   195,    -1,
      61,    -1,   206,    -1,   201,    -1,   203,    -1,   210,    -1,
     207,    -1,   194,    -1,   202,    -1,   205,    -1,   196,    -1,
     216,    -1,   184,    -1,   185,    -1,   199,    -1,    -1,   117,
     499,   245,   500,   242,    -1,   500,   246,   501,    -1,   501,
      -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,   191,
      -1,   195,    -1,   206,    -1,    61,    -1,   201,    -1,   203,
      -1,   210,    -1,   207,    -1,   194,    -1,   202,    -1,   205,
      -1,   196,    -1,   216,    -1,   184,    -1,   185,    -1,   199,
      -1,    96,   245,   110,   242,    -1,    97,   245,   110,   242,
      -1,    27,   245,   110,   242,    -1,   189,   245,   253,   242,
      -1,    -1,    52,   507,   244,   508,   243,   242,    -1,   508,
     509,    -1,   509,    -1,   510,    -1,   511,    -1,   512,    -1,
     516,    -1,   517,    -1,   518,    -1,     1,    -1,    42,   245,
     176,   242,    -1,    39,   245,   251,   242,    -1,    -1,    83,
     513,   245,   514,   242,    -1,   514,   246,   515,    -1,   515,
      -1,   178,    -1,    11,    -1,   228,   245,   131,   242,    -1,
     100,   245,   131,   242,    -1,    -1,     4,   519,   245,   520,
     242,    -1,   520,   246,   521,    -1,   521,    -1,   178,    -1,
      11,    -1,    21,   244,   523,   243,   242,    -1,   523,   524,
      -1,   524,    -1,   527,    -1,   528,    -1,   529,    -1,   530,
      -1,   535,    -1,   531,    -1,   532,    -1,   533,    -1,   534,
      -1,   536,    -1,   537,    -1,   538,    -1,   526,    -1,   539,
      -1,   540,    -1,   541,    -1,   542,    -1,   525,    -1,     1,
      -1,    34,   245,   176,   242,    -1,   141,   245,   176,   242,
      -1,    36,   245,   176,   242,    -1,   230,   245,   176,   242,
      -1,   231,   245,   176,   242,    -1,   232,   245,   176,   242,
      -1,    78,   245,   251,   242,    -1,    79,   245,   251,   242,
      -1,    86,   245,   110,   242,    -1,   132,   245,   176,   242,
      -1,    85,   245,   110,   242,    -1,    29,   245,   110,   242,
      -1,    28,   245,   110,   242,    -1,   106,   245,   176,   242,
      -1,   107,   245,   176,   242,    -1,    13,   245,   176,   242,
      -1,   121,   245,   110,   242,    -1,   122,   245,   251,   242,
      -1,   160,   244,   544,   243,   242,    -1,   544,   545,    -1,
     545,    -1,   546,    -1,   547,    -1,   549,    -1,   551,    -1,
     550,    -1,   548,    -1,   552,    -1,     1,    -1,    48,   245,
     176,   242,    -1,    64,   245,   176,   242,    -1,    62,   245,
     131,   242,    -1,    81,   245,   251,   242,    -1,    61,   245,
     176,   242,    -1,    35,   245,   176,   242,    -1,    63,   245,
     176,   242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   378,   378,   379,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   408,   408,   409,
     413,   417,   421,   425,   429,   435,   435,   436,   437,   438,
     439,   446,   449,   449,   450,   450,   450,   452,   458,   465,
     467,   467,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   473,   473,   474,   474,   475,   476,   479,   480,
     482,   482,   483,   489,   497,   497,   498,   504,   512,   551,
     610,   634,   642,   657,   672,   681,   695,   704,   732,   762,
     785,   794,   796,   796,   797,   797,   798,   798,   800,   809,
     818,   830,   831,   831,   833,   833,   833,   834,   836,   842,
     849,   849,   859,   860,   862,   862,   863,   863,   865,   870,
     873,   879,   878,   884,   884,   885,   889,   893,   897,   901,
     905,   909,   920,   919,  1017,  1017,  1018,  1018,  1018,  1019,
    1019,  1019,  1020,  1020,  1020,  1022,  1034,  1071,  1083,  1094,
    1136,  1146,  1145,  1151,  1151,  1152,  1156,  1160,  1164,  1168,
    1172,  1176,  1180,  1184,  1188,  1192,  1196,  1200,  1204,  1208,
    1212,  1216,  1220,  1224,  1228,  1235,  1234,  1240,  1240,  1241,
    1245,  1249,  1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,
    1285,  1289,  1293,  1297,  1301,  1305,  1309,  1320,  1319,  1369,
    1369,  1370,  1371,  1371,  1372,  1373,  1374,  1375,  1376,  1377,
    1378,  1379,  1380,  1381,  1382,  1384,  1393,  1399,  1405,  1411,
    1417,  1423,  1429,  1435,  1441,  1447,  1453,  1459,  1469,  1468,
    1485,  1484,  1489,  1489,  1490,  1494,  1498,  1506,  1506,  1507,
    1507,  1507,  1507,  1507,  1509,  1509,  1511,  1511,  1513,  1527,
    1547,  1556,  1569,  1568,  1637,  1637,  1638,  1638,  1638,  1638,
    1639,  1639,  1639,  1640,  1640,  1642,  1679,  1692,  1701,  1713,
    1712,  1716,  1716,  1717,  1721,  1725,  1729,  1733,  1737,  1741,
    1745,  1749,  1756,  1775,  1785,  1799,  1798,  1814,  1814,  1815,
    1815,  1815,  1815,  1817,  1826,  1841,  1854,  1856,  1856,  1857,
    1857,  1859,  1875,  1874,  1890,  1890,  1891,  1891,  1891,  1891,
    1893,  1902,  1925,  1924,  1930,  1930,  1931,  1935,  1939,  1943,
    1947,  1951,  1955,  1959,  1963,  1967,  1977,  1976,  1993,  1993,
    1994,  1994,  1994,  1996,  2003,  2002,  2008,  2008,  2009,  2013,
    2017,  2021,  2025,  2029,  2033,  2037,  2041,  2045,  2055,  2054,
    2183,  2183,  2184,  2184,  2184,  2185,  2185,  2186,  2186,  2186,
    2187,  2187,  2187,  2188,  2188,  2189,  2191,  2203,  2212,  2238,
    2256,  2274,  2280,  2284,  2293,  2292,  2296,  2296,  2297,  2301,
    2305,  2309,  2315,  2326,  2339,  2352,  2361,  2380,  2379,  2443,
    2442,  2446,  2446,  2447,  2453,  2453,  2454,  2454,  2454,  2454,
    2456,  2475,  2485,  2484,  2507,  2507,  2508,  2508,  2508,  2510,
    2516,  2525,  2527,  2527,  2528,  2528,  2530,  2549,  2548,  2596,
    2595,  2599,  2599,  2600,  2606,  2606,  2607,  2607,  2607,  2607,
    2609,  2615,  2624,  2627,  2627,  2628,  2628,  2629,  2629,  2630,
    2630,  2631,  2631,  2632,  2632,  2633,  2633,  2634,  2634,  2635,
    2635,  2636,  2636,  2637,  2637,  2638,  2638,  2639,  2639,  2640,
    2640,  2641,  2642,  2642,  2643,  2643,  2644,  2644,  2645,  2645,
    2646,  2646,  2647,  2648,  2649,  2649,  2650,  2651,  2652,  2652,
    2653,  2653,  2654,  2654,  2655,  2655,  2656,  2659,  2664,  2669,
    2674,  2679,  2684,  2689,  2694,  2699,  2704,  2709,  2714,  2719,
    2724,  2729,  2734,  2739,  2744,  2750,  2761,  2766,  2775,  2780,
    2785,  2790,  2795,  2800,  2803,  2808,  2811,  2816,  2821,  2826,
    2831,  2836,  2841,  2846,  2851,  2856,  2867,  2872,  2877,  2882,
    2891,  2900,  2905,  2910,  2916,  2915,  2920,  2920,  2921,  2924,
    2927,  2930,  2933,  2936,  2939,  2942,  2945,  2948,  2951,  2954,
    2957,  2960,  2963,  2966,  2969,  2972,  2975,  2978,  2984,  2983,
    2988,  2988,  2989,  2992,  2995,  2998,  3001,  3004,  3007,  3010,
    3013,  3016,  3019,  3022,  3025,  3028,  3031,  3034,  3037,  3040,
    3043,  3046,  3051,  3056,  3061,  3066,  3076,  3075,  3099,  3099,
    3100,  3101,  3102,  3103,  3104,  3105,  3106,  3108,  3114,  3121,
    3120,  3125,  3125,  3126,  3130,  3136,  3170,  3180,  3179,  3229,
    3229,  3230,  3234,  3243,  3246,  3246,  3247,  3247,  3248,  3248,
    3249,  3249,  3250,  3250,  3251,  3251,  3252,  3253,  3253,  3254,
    3254,  3255,  3255,  3256,  3256,  3258,  3263,  3268,  3273,  3278,
    3283,  3288,  3293,  3298,  3303,  3308,  3313,  3318,  3323,  3328,
    3333,  3338,  3343,  3351,  3354,  3354,  3355,  3355,  3356,  3357,
    3358,  3358,  3359,  3360,  3362,  3368,  3374,  3383,  3397,  3403,
    3409
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
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH",
  "EMAIL", "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINES", "GLINE_EXEMPT", "GLINE_TIME", "GLINE_MIN_CIDR",
  "GLINE_MIN_CIDR6", "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT",
  "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_SERVER_IPS",
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
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE",
  "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1",
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID",
  "T_CALLERID", "T_CCONN", "T_CCONN_FULL", "T_SSL_CIPHER_LIST",
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE", "T_DRONE",
  "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS",
  "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH",
  "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS",
  "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "T_TIMESTAMP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'",
  "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_use_logging",
  "logging_timestamp", "logging_file_entry", "$@1", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@2", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@3", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@4",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@5",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@6",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_ping_warning", "class_number_per_ip", "class_connectfreq",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "listen_entry", "$@7",
  "listen_flags", "$@8", "listen_flags_items", "listen_flags_item",
  "listen_items", "listen_item", "listen_port", "$@9", "port_items",
  "port_item", "listen_address", "listen_host", "auth_entry", "$@10",
  "auth_items", "auth_item", "auth_user", "auth_passwd", "auth_class",
  "auth_encrypted", "auth_flags", "$@11", "auth_flags_items",
  "auth_flags_item", "auth_spoof", "auth_redir_serv", "auth_redir_port",
  "resv_entry", "$@12", "resv_items", "resv_item", "resv_creason",
  "resv_channel", "resv_nick", "service_entry", "service_items",
  "service_item", "service_name", "shared_entry", "$@13", "shared_items",
  "shared_item", "shared_name", "shared_user", "shared_type", "$@14",
  "shared_types", "shared_type_item", "cluster_entry", "$@15",
  "cluster_items", "cluster_item", "cluster_name", "cluster_type", "$@16",
  "cluster_types", "cluster_type_item", "connect_entry", "$@17",
  "connect_items", "connect_item", "connect_name", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_flags", "$@18",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@19", "kill_type", "$@20",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "$@21", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "$@22", "gecos_flags", "$@23",
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
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@24", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@25", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "gline_entry",
  "$@26", "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "$@27", "gline_logging_types",
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action",
  "$@28", "gdeny_types", "gdeny_type_item", "channel_entry",
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
     495,   496,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   247,   248,   248,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   250,   250,   251,
     251,   251,   251,   251,   251,   252,   252,   253,   253,   253,
     253,   254,   255,   255,   256,   256,   256,   257,   258,   259,
     260,   260,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   262,   263,
     264,   264,   265,   265,   266,   266,   267,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   282,   283,   283,   283,   283,   284,   285,
     286,   287,   288,   288,   289,   289,   289,   289,   290,   291,
     293,   292,   294,   294,   295,   295,   295,   295,   296,   297,
     297,   299,   298,   300,   300,   301,   301,   301,   301,   301,
     301,   301,   303,   302,   304,   304,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   306,   307,   308,   309,   310,
     311,   313,   312,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   317,   316,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   321,   320,   322,
     322,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   338,   337,
     340,   339,   341,   341,   342,   342,   342,   343,   343,   344,
     344,   344,   344,   344,   346,   345,   347,   347,   348,   348,
     349,   350,   352,   351,   353,   353,   354,   354,   354,   354,
     354,   354,   354,   354,   354,   355,   356,   357,   358,   360,
     359,   361,   361,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   363,   364,   365,   367,   366,   368,   368,   369,
     369,   369,   369,   370,   371,   372,   373,   374,   374,   375,
     375,   376,   378,   377,   379,   379,   380,   380,   380,   380,
     381,   382,   384,   383,   385,   385,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   388,   387,   389,   389,
     390,   390,   390,   391,   393,   392,   394,   394,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   397,   396,
     398,   398,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   400,   401,   402,   403,
     404,   405,   406,   406,   408,   407,   409,   409,   410,   410,
     410,   410,   411,   412,   413,   414,   415,   417,   416,   419,
     418,   420,   420,   421,   422,   422,   423,   423,   423,   423,
     424,   425,   427,   426,   428,   428,   429,   429,   429,   430,
     431,   432,   433,   433,   434,   434,   435,   437,   436,   439,
     438,   440,   440,   441,   442,   442,   443,   443,   443,   443,
     444,   445,   446,   447,   447,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   475,   476,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   495,   494,   496,   496,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   499,   498,
     500,   500,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   502,   503,   504,   505,   507,   506,   508,   508,
     509,   509,   509,   509,   509,   509,   509,   510,   511,   513,
     512,   514,   514,   515,   515,   516,   517,   519,   518,   520,
     520,   521,   521,   522,   523,   523,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   544,   545,   545,   545,   545,
     545,   545,   545,   545,   546,   547,   548,   549,   550,   551,
     552
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
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       3,     1,     1,     1,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     0,
       5,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     0,
       5,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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
       2,     0,     1,     0,     0,     0,   197,   348,   402,     0,
     417,     0,   586,   252,   387,   228,     0,     0,   132,   285,
       0,     0,   302,   326,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    96,    95,   634,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     633,   628,   616,   617,   618,   619,   621,   622,   623,   624,
     620,   625,   626,   627,   629,   630,   631,   632,     0,     0,
       0,   415,     0,     0,   413,   414,     0,   486,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,     0,   534,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     434,   484,   479,   480,   481,   482,   478,   445,   435,   436,
     472,   437,   438,   439,   440,   441,   442,   443,   444,   475,
     446,   447,   448,   449,   483,   451,   456,   452,   454,   453,
     467,   468,   455,   457,   458,   459,   460,   461,   450,   463,
     464,   465,   485,   476,   477,   474,   466,   462,   470,   471,
     469,   473,     0,     0,     0,     0,     0,     0,     0,     0,
     103,   104,   105,   106,     0,     0,     0,     0,     0,    43,
      44,    45,     0,     0,   663,     0,     0,     0,     0,     0,
       0,     0,     0,   655,   656,   657,   661,   658,   660,   659,
     662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    64,
      65,    63,    60,    59,    66,    52,    62,    55,    56,    57,
      53,    61,    58,    54,     0,     0,   300,     0,     0,   298,
     299,    97,     0,     0,     0,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,   201,   204,   205,   207,   208,   209,   210,
     211,   212,   213,   202,   203,   206,     0,     0,     0,     0,
       0,   374,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   351,   352,   353,   354,   355,   356,   358,   357,   360,
     364,   361,   362,   363,   359,   408,     0,     0,     0,   405,
     406,   407,     0,     0,   412,   429,     0,     0,   419,   428,
       0,   425,   426,   427,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,   596,   607,     0,
       0,   599,     0,     0,     0,   589,   590,   591,   592,   593,
     594,   595,     0,     0,     0,   269,     0,     0,     0,     0,
       0,     0,   255,   256,   257,   258,   263,   259,   260,   261,
     262,   399,     0,   389,     0,   398,     0,   395,   396,   397,
       0,   230,     0,     0,     0,   240,     0,   238,   239,   241,
     242,   107,     0,     0,     0,   102,     0,    46,     0,     0,
       0,    42,     0,     0,     0,   175,     0,     0,     0,   151,
       0,     0,   135,   136,   137,   138,   141,   142,   140,   139,
     143,     0,     0,     0,     0,     0,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,     0,     0,   654,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,     0,     0,   312,
       0,     0,   305,   306,   307,   308,     0,     0,   334,     0,
     329,   330,   331,     0,     0,   297,     0,     0,     0,    91,
       0,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   365,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   350,     0,     0,     0,   404,     0,   411,     0,     0,
       0,     0,   424,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,     0,     0,     0,   432,     0,     0,
       0,     0,     0,     0,     0,   588,   264,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,     0,     0,
       0,   394,   243,     0,     0,     0,     0,     0,   237,     0,
       0,   101,     0,     0,     0,    41,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   292,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,     0,
     653,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,    71,    76,    77,     0,    75,     0,     0,     0,
       0,     0,    49,   309,     0,     0,     0,     0,   304,   332,
       0,     0,     0,   328,     0,   296,   100,    99,    98,   650,
     647,   646,   635,   637,    27,    27,    27,    27,    27,    29,
      28,   641,   642,   645,   643,   648,   649,   651,   652,   644,
     636,   638,   639,   640,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,     0,   403,   416,     0,     0,     0,
     418,   498,   502,   518,   584,   532,   496,   526,   529,   497,
     488,   489,   505,   494,   495,   508,   493,   507,   506,   501,
     500,   499,   527,   487,   525,   582,   583,   522,   519,   569,
     562,   579,   580,   563,   564,   565,   566,   574,   567,   577,
     581,   570,   575,   571,   576,   568,   573,   572,   578,     0,
     561,   524,   544,   538,   555,   556,   539,   540,   541,   542,
     550,   543,   553,   557,   546,   551,   547,   552,   545,   549,
     548,   554,     0,   537,   517,   520,   531,   491,   492,   521,
     510,   515,   516,   513,   514,   511,   512,   504,   503,    35,
      35,    35,    37,    36,   585,   530,   533,   523,   528,   490,
     509,     0,     0,     0,     0,     0,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,   253,     0,     0,     0,
     388,     0,     0,     0,   248,   244,   247,   229,   109,   108,
       0,     0,   121,     0,     0,   113,   114,   116,   115,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,   286,   669,   664,   668,   666,   670,   665,
     667,    84,    90,    82,    86,    85,    79,    78,    80,    68,
       0,    69,     0,    83,    81,    89,    87,    88,     0,     0,
       0,   303,     0,     0,   327,   301,    30,    31,    32,    33,
      34,   225,   226,   219,   221,   223,   222,   220,   215,   227,
     218,   216,   217,   224,   370,   372,   373,   385,   382,   378,
     379,   381,   380,     0,   377,   367,   383,   384,   366,   371,
     369,   386,   368,   409,   410,   430,   431,   423,     0,   422,
     559,     0,   535,     0,    38,    39,    40,   612,   611,     0,
     610,   598,   597,   604,   603,     0,   602,   606,   605,   267,
     268,   277,   274,   279,   276,   275,   281,   278,   280,   273,
       0,   272,   266,   284,   283,   282,   265,   401,   393,     0,
     392,   400,   235,   236,   234,     0,   233,   251,   250,     0,
       0,     0,   117,     0,     0,     0,     0,   112,   150,   148,
     190,   187,   186,   179,   181,   196,   191,   194,   189,   180,
     195,   183,   192,   184,   193,   188,   182,   185,     0,   178,
     145,   147,   149,   161,   155,   172,   173,   156,   157,   158,
     159,   167,   160,   170,   174,   163,   168,   164,   169,   162,
     166,   165,   171,     0,   154,   146,   294,   295,   293,    70,
      74,   310,   316,   322,   325,   318,   324,   319,   323,   321,
     317,   320,     0,   315,   311,   333,   338,   344,   347,   340,
     346,   341,   345,   343,   339,   342,     0,   337,   375,     0,
     420,     0,   560,   536,   608,     0,   600,     0,   270,     0,
     390,     0,   231,     0,   249,   246,   245,     0,     0,     0,
       0,   111,   176,     0,   152,     0,   313,     0,   335,     0,
     376,   421,   609,   601,   271,   391,   232,   118,   127,   130,
     129,   126,   131,   128,   125,     0,   124,   120,   119,   177,
     153,   314,   336,   122,     0,   123
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   839,   840,   982,   983,    26,   248,   249,
     250,   251,    27,   287,   288,   289,   290,   801,   802,   805,
     806,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    28,    74,    75,    76,    77,    78,
      29,   239,   240,   241,   242,   243,   244,  1024,  1025,  1026,
    1027,  1028,  1174,  1305,  1306,    30,    63,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   773,  1223,  1224,   550,
     769,  1198,  1199,    31,    51,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
      32,    60,   515,   753,  1165,  1166,   516,   517,   518,  1171,
    1015,  1016,   519,   520,    33,    58,   491,   492,   493,   494,
     495,   496,   497,   739,  1150,  1151,   498,   499,   500,    34,
      64,   555,   556,   557,   558,   559,    35,   308,   309,   310,
      36,    67,   591,   592,   593,   594,   595,   815,  1242,  1243,
      37,    68,   599,   600,   601,   602,   821,  1256,  1257,    38,
      52,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   651,  1103,  1104,   390,   391,   392,   393,   394,    39,
      59,   505,   748,  1159,  1160,   506,   507,   508,   509,    40,
      53,   398,   399,   400,   401,    41,   123,   124,   125,    42,
      55,   409,   670,  1118,  1119,   410,   411,   412,   413,    43,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   444,   962,
     963,   227,   442,   939,   940,   228,   229,   230,   231,    44,
      57,   474,   475,   476,   477,   478,   731,  1135,  1136,   479,
     480,   481,   728,  1129,  1130,    45,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    46,   262,   263,   264,
     265,   266,   267,   268,   269,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -773
static const yytype_int16 yypact[] =
{
    -773,   703,  -773,  -154,  -219,  -203,  -773,  -773,  -773,  -196,
    -773,  -187,  -773,  -773,  -773,  -773,  -184,  -176,  -773,  -773,
    -161,  -138,  -773,  -773,   -95,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,    30,
     578,   -93,   -72,   -60,    28,   -54,   398,   -48,   -45,   -36,
     -28,    91,     2,   -21,   -19,   495,   438,   -12,    -4,    38,
    -164,   -76,   -34,    -3,    12,  -773,  -773,  -773,  -773,  -773,
      29,    33,    42,    48,    60,    83,    85,    90,    96,   103,
     125,   132,   140,   142,   145,   146,   147,   149,   230,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   712,   480,
      31,  -773,   150,    11,  -773,  -773,   234,  -773,   151,   156,
     157,   160,   164,   165,   166,   167,   170,   171,   173,   176,
     177,   179,   183,   184,   185,   187,   192,   195,   196,   197,
     198,   201,   202,   204,   206,   207,  -773,   210,  -773,   212,
     214,   219,   220,   221,   225,   227,   239,   240,   242,   245,
     252,   253,   256,   257,   258,   263,   265,   266,   268,   110,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   303,   279,    86,   379,    18,   272,   274,    55,
    -773,  -773,  -773,  -773,   148,   121,   275,   283,    84,  -773,
    -773,  -773,   551,   255,  -773,   284,   287,   288,   289,   290,
     292,   294,   312,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,   181,   297,   299,   302,   304,   305,   309,   317,   318,
     319,   321,   322,   329,   337,   343,   344,    14,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,   144,    15,  -773,   345,    26,  -773,
    -773,  -773,   369,   393,   462,   353,  -773,   420,   324,   487,
     425,   426,   493,   493,   498,   499,   429,   435,   505,   493,
     440,   442,   444,   446,   447,   382,  -773,   383,   384,   390,
     391,   395,   396,   397,   399,   400,   401,   402,   403,   404,
     405,   269,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,   386,   407,   408,   409,
     410,  -773,   413,   414,   415,   417,   421,   422,   424,   427,
       4,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,   430,   432,    20,  -773,
    -773,  -773,   512,   423,  -773,  -773,   434,   437,  -773,  -773,
      22,  -773,  -773,  -773,   504,   493,   493,   560,   507,   511,
     579,   557,   515,   584,   587,   588,   525,   526,   531,   493,
     583,   542,   610,   613,   493,   615,   620,   601,   626,   627,
     563,   564,   497,   569,   501,   493,   493,   571,   493,   575,
     580,   582,   178,   189,   586,   590,   493,   493,   644,   632,
     493,   592,   593,   594,   595,   522,  -773,  -773,  -773,   527,
     528,  -773,   529,   532,    10,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   534,   533,   535,  -773,   537,   538,   543,   544,
     545,    43,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   546,  -773,   547,  -773,     8,  -773,  -773,  -773,
     552,  -773,   548,   550,   553,  -773,     3,  -773,  -773,  -773,
    -773,  -773,   611,   621,   554,  -773,   559,  -773,   674,   675,
     572,  -773,   574,   566,   568,  -773,   576,   577,   581,  -773,
     585,    97,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,   589,   591,   597,   598,    19,  -773,  -773,  -773,  -773,
     641,   647,   651,   689,   652,   653,   493,   596,  -773,  -773,
     701,   657,   704,   708,   713,   714,   715,   716,   118,   229,
     717,   718,   724,   719,   720,   614,  -773,   617,   607,  -773,
     608,    95,  -773,  -773,  -773,  -773,   618,   612,  -773,    58,
    -773,  -773,  -773,   730,   623,  -773,   624,   635,   638,  -773,
     639,   643,   646,   650,   654,   323,   655,   658,   659,   660,
     661,   663,   669,   670,   673,   678,   681,   685,   690,  -773,
    -773,   727,   745,   493,   752,   759,   776,   789,   785,   821,
     824,   493,   493,   644,   693,  -773,  -773,   805,   186,   806,
     762,   695,   815,   816,   819,   820,   845,   825,   827,   831,
     725,  -773,   835,   838,   728,  -773,   729,  -773,   841,   842,
     731,   733,  -773,   735,   736,   737,   738,   739,   740,   741,
     742,   743,   744,   746,   747,   748,   749,   750,   751,   753,
     754,   755,   756,   757,   760,   761,   763,   764,   765,   766,
     767,   688,   768,   723,   769,   770,   771,   772,   773,   774,
     775,   777,   778,   779,   780,   781,   782,   783,   784,    21,
     786,   787,   788,   790,   791,   792,   793,  -773,   794,   493,
     811,   795,   863,   869,   796,  -773,  -773,   870,   828,   797,
     887,   917,   900,   905,   906,   799,  -773,   912,   800,   913,
     804,  -773,  -773,   802,   918,   919,   938,   809,  -773,   810,
     812,  -773,    32,   813,   814,  -773,  -773,   922,   881,   817,
     927,   928,   929,   818,   930,   822,  -773,  -773,   934,   935,
     936,   826,  -773,   829,   830,   832,   833,   834,   836,   837,
    -773,   839,   840,   843,   844,   846,   847,   848,   849,  -773,
    -773,  -220,  -773,  -773,  -773,  -212,  -773,   850,   851,   852,
     853,   854,  -773,  -773,   939,   855,   942,   856,  -773,  -773,
     946,   857,   859,  -773,   861,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,   493,   493,   493,   493,   493,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,   862,   864,   865,   866,   867,   868,
     871,   872,   873,   874,   875,   876,   877,  -773,   878,   879,
     880,   882,   883,     7,   884,   885,   886,   888,   889,   890,
     891,   892,  -773,   893,   894,  -773,  -773,   895,   896,   933,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -204,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -188,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   644,
     644,   644,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,    -5,   897,   898,    13,   899,   901,  -773,   902,   903,
     706,   904,   907,   908,   909,   910,  -773,   911,   944,   914,
    -773,   -15,   915,   916,   924,   920,  -773,  -773,  -773,  -773,
     921,   923,  -773,   925,    54,  -773,  -773,  -773,  -773,  -773,
    -773,   931,   932,   494,   937,   940,   941,   758,   943,  -773,
     945,   947,   948,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
     118,  -773,   229,  -773,  -773,  -773,  -773,  -773,   949,   479,
     950,  -773,   951,   530,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -169,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -167,  -773,
    -773,   688,  -773,   723,  -773,  -773,  -773,  -773,  -773,  -166,
    -773,  -773,  -773,  -773,  -773,  -145,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -139,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -137,
    -773,  -773,  -773,  -773,  -773,  -100,  -773,  -773,  -773,   973,
     938,   952,  -773,   953,   926,   -92,   954,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   -75,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,   -33,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   -25,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,   104,  -773,  -773,     7,
    -773,   933,  -773,  -773,  -773,    -5,  -773,    13,  -773,   706,
    -773,   944,  -773,   -15,  -773,  -773,  -773,   955,   228,   956,
     957,  -773,  -773,   494,  -773,   758,  -773,   479,  -773,   530,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,   122,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,   228,  -773
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -773,  -773,  -773,  -772,  -321,  -662,  -458,  -773,  -773,   958,
    -773,  -773,  -773,  -773,   860,  -773,  -773,  -773,    27,  -773,
      35,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  1025,  -773,  -773,  -773,
    -773,  -773,   961,  -773,  -773,  -773,  -773,  -773,    87,  -773,
    -773,  -773,  -773,  -773,  -202,  -773,  -773,  -773,   619,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -162,  -773,
    -773,  -773,  -141,  -773,  -773,  -773,   803,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -144,  -773,   645,  -773,  -773,
    -773,   -22,  -773,  -773,  -773,  -773,  -773,   664,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -110,  -773,  -773,  -773,  -773,
    -773,  -773,   609,  -773,  -773,  -773,  -773,  -773,   959,  -773,
    -773,  -773,  -773,   604,  -773,  -773,  -773,  -773,  -773,  -125,
    -773,  -773,  -773,   570,  -773,  -773,  -773,  -773,  -124,  -773,
    -773,  -773,   798,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,   -87,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -104,  -773,   671,  -773,  -773,  -773,
    -773,  -773,   807,  -773,  -773,  -773,  -773,  1052,  -773,  -773,
    -773,  -773,  -773,  -773,   -85,  -773,   801,  -773,  -773,  -773,
    -773,  1001,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
      61,  -773,  -773,  -773,    65,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,   707,  -773,  -773,  -773,  -773,  -773,   -79,  -773,
    -773,  -773,  -773,  -773,   -64,  -773,  -773,  1104,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,
    -773,  -773,  -773,  -773,  -773,  -773,  -773,  -773,   960,  -773,
    -773,  -773,  -773,  -773,  -773,  -773
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -111
static const yytype_int16 yytable[] =
{
     720,   616,   617,   245,   510,   366,  1127,   367,   623,   501,
     368,   467,   121,    70,   468,   271,   596,  1099,   719,  1100,
     551,   395,  1059,   405,  1133,    49,  1060,   306,   369,   121,
    1061,    70,   395,  1020,  1062,   979,   980,   981,  1120,   306,
     552,    50,  1121,    71,   482,   272,  1162,   370,    54,   469,
     511,   371,   470,    72,  1122,  1020,   236,    56,  1123,   596,
      61,    71,  1076,  1077,  1078,  1079,  1080,   483,    62,   512,
     372,    72,   373,  1258,   513,  1260,  1264,  1259,   311,  1261,
    1265,   273,   122,    65,   374,   245,   484,   501,    47,    48,
     485,   396,   236,   471,   674,   675,   587,  1266,   532,   122,
     246,  1267,   396,  1268,   375,  1270,    66,  1269,   688,  1271,
     472,   127,    73,   693,   274,   597,   275,   276,   128,   129,
    1279,   533,   406,   553,   704,   705,   307,   707,   247,   130,
      73,   719,  1021,   514,   376,   717,   718,   131,   307,   722,
     534,   502,  1272,   132,   535,   587,  1273,   133,   134,    69,
     135,   118,   554,   397,  1021,   407,   136,   277,   597,   278,
     279,   280,   281,   377,   397,   137,   138,  1282,   486,   312,
     139,  1283,   119,  1128,   503,   140,   282,   487,   488,   141,
     142,   598,   246,   143,   120,   866,   144,   145,   408,  1163,
     126,  1134,   378,  1164,   146,   588,   232,   536,  1022,   233,
     147,   148,   283,   149,   150,   151,   152,   153,   234,  1284,
     247,   313,   489,  1285,   284,  1101,   235,  1286,   154,   502,
    1022,  1287,   537,   252,   598,   253,   155,   156,   157,  1102,
     158,    79,   304,   159,   160,   405,   504,   161,   473,   379,
     305,   538,   314,    80,   588,   789,   757,   660,   162,   285,
     286,   750,   503,   734,   403,   315,   551,   585,    81,    82,
     521,   589,   781,   664,    83,   671,    84,   799,   800,   604,
     337,   490,  1023,   163,   317,   237,   552,   164,   318,  1298,
     482,   165,   166,   167,   168,   169,   745,   319,   238,   170,
     171,   338,   339,   320,  1023,   340,  -110,  1176,   524,   172,
    1299,   822,  1300,   483,   467,   321,   539,   468,    85,    86,
     589,   237,   856,   254,   504,    87,    88,  1124,  1125,  1126,
     864,   865,   484,   590,   238,   540,   485,   530,   322,   173,
     323,   174,  -110,   175,   406,   324,    89,    90,   817,   176,
     775,   325,   469,  1301,   177,   470,  1288,   255,   326,   178,
    1289,    91,    92,   465,   711,   712,   341,   342,   343,   553,
     256,   344,    93,   527,  1313,   713,   714,   407,  1314,   345,
     327,    94,   590,   257,   258,   259,   260,   328,   803,   804,
     510,   346,   347,   869,   870,   329,   471,   330,   554,   526,
     331,   332,   333,   261,   334,   402,   414,   348,   349,   127,
     408,   415,   416,   472,   486,   417,   128,   129,   992,   418,
     419,   420,   421,   487,   488,   422,   423,   130,   424,  1302,
    1303,   425,   426,   569,   427,   131,   511,   350,   428,   429,
     430,   132,   431,   615,   611,   133,   134,   432,   135,   271,
     433,   434,   435,   436,   136,   512,   437,   438,   489,   439,
     513,   440,   441,   137,   138,   443,  1304,   445,   139,   446,
      95,    96,    97,   140,   447,   448,   449,   141,   142,   272,
     450,   143,   451,   335,   144,   145,   834,   835,   836,   837,
     838,   366,   146,   367,   452,   453,   368,   454,   147,   148,
     455,   149,   150,   151,   152,   153,   254,   456,   457,  1180,
     606,   458,   459,   460,   369,   273,   154,   490,   461,   514,
     462,   463,   644,   464,   155,   156,   157,   522,   158,   523,
     528,   159,   160,   370,   607,   161,  1181,   371,   529,   560,
     255,   473,   561,   562,   563,   564,   162,   565,   274,   566,
     275,   276,   570,   256,   571,  1182,   372,   572,   373,   573,
     574,  1183,   532,  1232,   575,   567,   257,   258,   259,   260,
     374,   163,   576,   577,   578,   164,   579,   580,  1184,   165,
     166,   167,   168,   169,   581,   533,   261,   170,   171,    79,
     375,   277,   582,   278,   279,   280,   281,   172,   583,   584,
     603,    80,  1185,   608,   534,   609,   610,   612,   535,  1186,
     282,   613,   614,   615,  1246,   620,    81,    82,   618,   619,
     376,   621,    83,  1187,    84,   622,   624,   173,   625,   174,
     626,   175,   627,   628,   629,   630,   283,   176,   646,   631,
    1233,  1188,   177,  1189,  1190,   632,   633,   178,   284,   377,
     634,   635,   636,   666,   637,   638,   639,   640,   641,   642,
     643,   536,   647,   648,   649,   650,    85,    86,   652,   653,
     654,  1234,   655,    87,    88,   667,   656,   657,   378,   658,
     676,  1235,   659,   285,   286,   662,   537,   663,  1236,   668,
     673,  1247,   669,   677,    89,    90,  1191,   678,   680,   679,
    1237,   681,  1238,  1239,   682,   538,  1192,   683,   684,    91,
      92,   685,   686,     2,     3,  1193,  1240,   687,     4,  1194,
      93,  1195,  1248,   337,   689,   379,  1241,  1280,   690,    94,
     691,  1196,  1249,   692,     5,   694,  1141,     6,     7,  1250,
     695,  1197,   696,     8,   338,   339,   697,   698,   340,   699,
     700,  1251,   701,  1252,  1253,   702,   703,   706,     9,   919,
    1142,   708,    10,    11,   719,    12,   709,  1254,   710,  1143,
     539,    13,   715,   721,   727,  1144,   716,  1255,   723,   724,
     725,   726,   729,   730,   732,    14,   736,   733,   737,   540,
     738,  1145,   740,   741,   942,    15,    16,   759,   742,   743,
     744,   747,   749,   754,   752,   755,   761,   760,   756,   341,
     342,   343,    17,   762,   344,   763,   764,  1146,    95,    96,
      97,   767,   345,   768,   765,  1147,   766,   783,    18,  1203,
     786,   770,   771,   784,   346,   347,   772,   785,   787,   788,
     774,   777,   791,   792,   809,   793,   778,   854,   790,   794,
     348,   349,   779,   780,   795,   796,   797,   798,   807,   808,
     810,   811,   814,   816,    19,   855,   812,   820,  1148,   813,
     819,   824,   857,    20,    21,   825,   826,    22,    23,   858,
     350,   920,   921,   922,   923,   924,  1149,   827,   925,   926,
     828,   829,   927,   928,   929,   830,   859,   930,   831,   931,
     932,   933,   832,   934,   935,   936,   833,   841,   937,   860,
     842,   843,   844,   845,   938,   846,   943,   944,   945,   946,
     947,   847,   848,   948,   949,   849,   861,   950,   951,   952,
     850,    24,   953,   851,   954,   955,   956,   852,   957,   958,
     959,   862,   853,   960,   863,   867,   868,   871,   872,   961,
     873,  1204,  1205,  1206,  1207,  1208,   874,   875,  1209,  1210,
     876,   877,  1211,  1212,  1213,   878,   879,  1214,   880,  1215,
    1216,  1217,   881,  1218,  1219,  1220,   883,   882,  1221,   884,
     885,   886,   887,   888,  1222,   890,   889,   891,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   993,   901,   902,
     903,   904,   905,   906,   995,   907,   908,   909,   910,   911,
     996,   998,   912,   913,   999,   914,   915,   916,   917,   918,
     941,   964,   965,   966,   967,   968,   969,   970,  1001,   971,
     972,   973,   974,   975,   976,   977,   978,  1002,   984,   985,
     986,  1003,   987,   988,   989,   990,  1004,  1005,   997,   991,
     994,  1006,  1000,  1007,  1009,  1008,  1010,  1011,  1014,  1012,
    1013,  1017,  1018,  1031,  1019,  1029,  1030,  1032,  1034,  1035,
    1036,  1038,  1033,  1037,  1039,  1040,  1041,  1042,  1043,  1117,
    1068,  1044,  1045,  1070,  1046,  1047,  1048,  1072,  1049,  1050,
    1158,  1051,  1052,  1274,  1277,  1053,  1054,  1229,  1055,  1056,
    1057,  1058,  1063,  1064,  1065,  1066,  1067,  1230,  1071,   316,
    1069,  1074,  1073,  1075,  1081,  1169,  1082,  1083,  1084,  1085,
    1086,  1177,  1315,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1310,  1097,  1098,  1105,  1106,  1107,  1296,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1131,
    1132,  1137,  1309,  1138,  1139,  1140,  1152,   586,  1275,  1153,
    1154,  1155,  1156,  1157,   645,   746,  1161,  1167,  1168,  1294,
     776,   758,  1311,  1172,   782,  1312,  1170,  1295,  1173,   823,
    1175,  1278,  1290,  1178,  1179,   404,  1291,   751,   661,  1200,
     466,   735,  1201,  1202,  1263,  1225,  1262,  1226,  1293,  1227,
    1228,  1231,  1244,  1245,  1276,   818,  1281,  1297,  1307,  1308,
     525,  1292,   336,     0,     0,   665,   531,     0,     0,     0,
       0,   672,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   568,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   605
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-773))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     458,   322,   323,     1,     1,     1,    11,     3,   329,     1,
       6,     1,     1,     1,     4,     1,     1,    10,   110,    12,
       1,     1,   242,     1,    11,   244,   246,     1,    24,     1,
     242,     1,     1,     1,   246,    14,    15,    16,   242,     1,
      21,   244,   246,    31,     1,    31,    61,    43,   244,    39,
      47,    47,    42,    41,   242,     1,     1,   244,   246,     1,
     244,    31,   834,   835,   836,   837,   838,    24,   244,    66,
      66,    41,    68,   242,    71,   242,   242,   246,   242,   246,
     246,    67,    71,   244,    80,     1,    43,     1,   242,   243,
      47,    71,     1,    83,   415,   416,     1,   242,     1,    71,
      98,   246,    71,   242,   100,   242,   244,   246,   429,   246,
     100,     1,   100,   434,   100,   100,   102,   103,     8,     9,
     212,    24,   100,   104,   445,   446,   100,   448,   126,    19,
     100,   110,   100,   130,   130,   456,   457,    27,   100,   460,
      43,   133,   242,    33,    47,     1,   246,    37,    38,   244,
      40,   244,   133,   133,   100,   133,    46,   143,   100,   145,
     146,   147,   148,   159,   133,    55,    56,   242,   125,   245,
      60,   246,   244,   178,   166,    65,   162,   134,   135,    69,
      70,   166,    98,    73,   244,   643,    76,    77,   166,   204,
     244,   178,   188,   208,    84,   100,   244,   100,   166,   244,
      90,    91,   188,    93,    94,    95,    96,    97,   244,   242,
     126,   245,   169,   246,   200,   208,   244,   242,   108,   133,
     166,   246,   125,   244,   166,   244,   116,   117,   118,   222,
     120,     1,   244,   123,   124,     1,   228,   127,   228,   235,
     244,   144,   245,    13,   100,   566,   243,   243,   138,   235,
     236,   243,   166,   243,   243,   243,     1,   243,    28,    29,
     242,   166,   243,   243,    34,   243,    36,   149,   150,   243,
       1,   228,   240,   163,   245,   220,    21,   167,   245,    51,
       1,   171,   172,   173,   174,   175,   243,   245,   233,   179,
     180,    22,    23,   245,   240,    26,   241,   243,   243,   189,
      72,   243,    74,    24,     1,   245,   209,     4,    78,    79,
     166,   220,   633,     1,   228,    85,    86,   979,   980,   981,
     641,   642,    43,   228,   233,   228,    47,   243,   245,   219,
     245,   221,   241,   223,   100,   245,   106,   107,   243,   229,
     243,   245,    39,   115,   234,    42,   242,    35,   245,   239,
     246,   121,   122,   243,   176,   177,    87,    88,    89,   104,
      48,    92,   132,   242,   242,   176,   177,   133,   246,   100,
     245,   141,   228,    61,    62,    63,    64,   245,   149,   150,
       1,   112,   113,   197,   198,   245,    83,   245,   133,   241,
     245,   245,   245,    81,   245,   245,   245,   128,   129,     1,
     166,   245,   245,   100,   125,   245,     8,     9,   729,   245,
     245,   245,   245,   134,   135,   245,   245,    19,   245,   191,
     192,   245,   245,   242,   245,    27,    47,   158,   245,   245,
     245,    33,   245,   110,   110,    37,    38,   245,    40,     1,
     245,   245,   245,   245,    46,    66,   245,   245,   169,   245,
      71,   245,   245,    55,    56,   245,   228,   245,    60,   245,
     230,   231,   232,    65,   245,   245,   245,    69,    70,    31,
     245,    73,   245,   243,    76,    77,   153,   154,   155,   156,
     157,     1,    84,     3,   245,   245,     6,   245,    90,    91,
     245,    93,    94,    95,    96,    97,     1,   245,   245,     5,
     131,   245,   245,   245,    24,    67,   108,   228,   245,   130,
     245,   245,   243,   245,   116,   117,   118,   245,   120,   245,
     245,   123,   124,    43,   131,   127,    32,    47,   245,   245,
      35,   228,   245,   245,   245,   245,   138,   245,   100,   245,
     102,   103,   245,    48,   245,    51,    66,   245,    68,   245,
     245,    57,     1,    74,   245,   243,    61,    62,    63,    64,
      80,   163,   245,   245,   245,   167,   245,   245,    74,   171,
     172,   173,   174,   175,   245,    24,    81,   179,   180,     1,
     100,   143,   245,   145,   146,   147,   148,   189,   245,   245,
     245,    13,    98,   131,    43,   242,   176,   110,    47,   105,
     162,   176,   176,   110,    74,   176,    28,    29,   110,   110,
     130,   176,    34,   119,    36,   110,   176,   219,   176,   221,
     176,   223,   176,   176,   242,   242,   188,   229,   242,   245,
     151,   137,   234,   139,   140,   245,   245,   239,   200,   159,
     245,   245,   245,   131,   245,   245,   245,   245,   245,   245,
     245,   100,   245,   245,   245,   245,    78,    79,   245,   245,
     245,   182,   245,    85,    86,   242,   245,   245,   188,   245,
     110,   192,   245,   235,   236,   245,   125,   245,   199,   245,
     176,   151,   245,   176,   106,   107,   192,   176,   131,   110,
     211,   176,   213,   214,   110,   144,   202,   110,   110,   121,
     122,   176,   176,     0,     1,   211,   227,   176,     5,   215,
     132,   217,   182,     1,   131,   235,   237,  1175,   176,   141,
     110,   227,   192,   110,    21,   110,    20,    24,    25,   199,
     110,   237,   131,    30,    22,    23,   110,   110,    26,   176,
     176,   211,   245,   213,   214,   176,   245,   176,    45,    61,
      44,   176,    49,    50,   110,    52,   176,   227,   176,    53,
     209,    58,   176,   131,   242,    59,   176,   237,   176,   176,
     176,   176,   245,   245,   245,    72,   242,   245,   245,   228,
     245,    75,   245,   245,    61,    82,    83,   176,   245,   245,
     245,   245,   245,   245,   242,   245,   242,   176,   245,    87,
      88,    89,    99,   244,    92,   131,   131,   101,   230,   231,
     232,   245,   100,   245,   242,   109,   242,   176,   115,    61,
     131,   245,   245,   176,   112,   113,   245,   176,   176,   176,
     245,   242,   131,   176,   110,   131,   245,   110,   242,   131,
     128,   129,   245,   245,   131,   131,   131,   131,   131,   131,
     131,   131,   245,   245,   151,   110,   242,   245,   152,   242,
     242,   131,   110,   160,   161,   242,   242,   164,   165,   110,
     158,   183,   184,   185,   186,   187,   170,   242,   190,   191,
     242,   242,   194,   195,   196,   242,   110,   199,   242,   201,
     202,   203,   242,   205,   206,   207,   242,   242,   210,   110,
     242,   242,   242,   242,   216,   242,   183,   184,   185,   186,
     187,   242,   242,   190,   191,   242,   131,   194,   195,   196,
     242,   218,   199,   242,   201,   202,   203,   242,   205,   206,
     207,   110,   242,   210,   110,   242,   131,   131,   176,   216,
     245,   183,   184,   185,   186,   187,   131,   131,   190,   191,
     131,   131,   194,   195,   196,   110,   131,   199,   131,   201,
     202,   203,   131,   205,   206,   207,   131,   242,   210,   131,
     242,   242,   131,   131,   216,   242,   245,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   176,   242,   242,
     242,   242,   242,   242,   131,   242,   242,   242,   242,   242,
     131,   131,   242,   242,   176,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   131,   242,
     242,   242,   242,   242,   242,   242,   242,   110,   242,   242,
     242,   131,   242,   242,   242,   242,   131,   131,   242,   245,
     245,   242,   245,   131,   131,   245,   242,   245,   110,   131,
     131,   242,   242,   131,   242,   242,   242,   176,   131,   131,
     131,   131,   245,   245,   242,   131,   131,   131,   242,   136,
     131,   242,   242,   131,   242,   242,   242,   131,   242,   242,
     136,   242,   242,   110,   131,   242,   242,  1060,   242,   242,
     242,   242,   242,   242,   242,   242,   242,  1062,   242,    74,
     245,   242,   245,   242,   242,   181,   242,   242,   242,   242,
     242,  1024,  1314,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,  1285,   242,   242,   242,   242,   242,  1273,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,  1283,   242,   242,   242,   242,   287,  1170,   242,
     242,   242,   242,   242,   351,   491,   242,   242,   242,  1269,
     541,   516,  1287,   242,   555,  1289,   246,  1271,   245,   599,
     245,   245,  1259,   242,   242,   123,  1261,   506,   380,   242,
     179,   474,   242,   242,  1123,   242,  1121,   242,  1267,   242,
     242,   242,   242,   242,   242,   591,   242,   242,   242,   242,
     239,  1265,    98,    -1,    -1,   398,   248,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   308
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   248,     0,     1,     5,    21,    24,    25,    30,    45,
      49,    50,    52,    58,    72,    82,    83,    99,   115,   151,
     160,   161,   164,   165,   218,   249,   254,   259,   281,   287,
     302,   320,   337,   351,   366,   373,   377,   387,   396,   416,
     426,   432,   436,   446,   506,   522,   543,   242,   243,   244,
     244,   321,   397,   427,   244,   437,   244,   507,   352,   417,
     338,   244,   244,   303,   367,   244,   244,   378,   388,   244,
       1,    31,    41,   100,   282,   283,   284,   285,   286,     1,
      13,    28,    29,    34,    36,    78,    79,    85,    86,   106,
     107,   121,   122,   132,   141,   230,   231,   232,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   244,   244,
     244,     1,    71,   433,   434,   435,   244,     1,     8,     9,
      19,    27,    33,    37,    38,    40,    46,    55,    56,    60,
      65,    69,    70,    73,    76,    77,    84,    90,    91,    93,
      94,    95,    96,    97,   108,   116,   117,   118,   120,   123,
     124,   127,   138,   163,   167,   171,   172,   173,   174,   175,
     179,   180,   189,   219,   221,   223,   229,   234,   239,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   498,   502,   503,
     504,   505,   244,   244,   244,   244,     1,   220,   233,   288,
     289,   290,   291,   292,   293,     1,    98,   126,   255,   256,
     257,   258,   244,   244,     1,    35,    48,    61,    62,    63,
      64,    81,   544,   545,   546,   547,   548,   549,   550,   551,
     552,     1,    31,    67,   100,   102,   103,   143,   145,   146,
     147,   148,   162,   188,   200,   235,   236,   260,   261,   262,
     263,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   244,   244,     1,   100,   374,   375,
     376,   242,   245,   245,   245,   243,   283,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   243,   524,     1,    22,    23,
      26,    87,    88,    89,    92,   100,   112,   113,   128,   129,
     158,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,     1,     3,     6,    24,
      43,    47,    66,    68,    80,   100,   130,   159,   188,   235,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     411,   412,   413,   414,   415,     1,    71,   133,   428,   429,
     430,   431,   245,   243,   434,     1,   100,   133,   166,   438,
     442,   443,   444,   445,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   499,   245,   495,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   243,   448,     1,     4,    39,
      42,    83,   100,   228,   508,   509,   510,   511,   512,   516,
     517,   518,     1,    24,    43,    47,   125,   134,   135,   169,
     228,   353,   354,   355,   356,   357,   358,   359,   363,   364,
     365,     1,   133,   166,   228,   418,   422,   423,   424,   425,
       1,    47,    66,    71,   130,   339,   343,   344,   345,   349,
     350,   242,   245,   245,   243,   289,   241,   242,   245,   245,
     243,   256,     1,    24,    43,    47,   100,   125,   144,   209,
     228,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     316,     1,    21,   104,   133,   368,   369,   370,   371,   372,
     245,   245,   245,   245,   245,   245,   245,   243,   545,   242,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   243,   261,     1,   100,   166,
     228,   379,   380,   381,   382,   383,     1,   100,   166,   389,
     390,   391,   392,   245,   243,   375,   131,   131,   131,   242,
     176,   110,   110,   176,   176,   110,   251,   251,   110,   110,
     176,   176,   110,   251,   176,   176,   176,   176,   176,   242,
     242,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   243,   323,   242,   245,   245,   245,
     245,   408,   245,   245,   245,   245,   245,   245,   245,   245,
     243,   399,   245,   245,   243,   429,   131,   242,   245,   245,
     439,   243,   443,   176,   251,   251,   110,   176,   176,   110,
     131,   176,   110,   110,   110,   176,   176,   176,   251,   131,
     176,   110,   110,   251,   110,   110,   131,   110,   110,   176,
     176,   245,   176,   245,   251,   251,   176,   251,   176,   176,
     176,   176,   177,   176,   177,   176,   176,   251,   251,   110,
     253,   131,   251,   176,   176,   176,   176,   242,   519,   245,
     245,   513,   245,   245,   243,   509,   242,   245,   245,   360,
     245,   245,   245,   245,   245,   243,   354,   245,   419,   245,
     243,   423,   242,   340,   245,   245,   245,   243,   344,   176,
     176,   242,   244,   131,   131,   242,   242,   245,   245,   317,
     245,   245,   245,   313,   245,   243,   305,   242,   245,   245,
     245,   243,   369,   176,   176,   176,   131,   176,   176,   251,
     242,   131,   176,   131,   131,   131,   131,   131,   131,   149,
     150,   264,   265,   149,   150,   266,   267,   131,   131,   110,
     131,   131,   242,   242,   245,   384,   245,   243,   380,   242,
     245,   393,   243,   390,   131,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   153,   154,   155,   156,   157,   250,
     251,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   110,   110,   251,   110,   110,   110,
     110,   131,   110,   110,   251,   251,   253,   242,   131,   197,
     198,   131,   176,   245,   131,   131,   131,   131,   110,   131,
     131,   131,   242,   131,   131,   242,   242,   131,   131,   245,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,    61,
     183,   184,   185,   186,   187,   190,   191,   194,   195,   196,
     199,   201,   202,   203,   205,   206,   207,   210,   216,   500,
     501,   242,    61,   183,   184,   185,   186,   187,   190,   191,
     194,   195,   196,   199,   201,   202,   203,   205,   206,   207,
     210,   216,   496,   497,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,    14,
      15,    16,   252,   253,   242,   242,   242,   242,   242,   242,
     242,   245,   251,   176,   245,   131,   131,   242,   131,   176,
     245,   131,   110,   131,   131,   131,   242,   131,   245,   131,
     242,   245,   131,   131,   110,   347,   348,   242,   242,   242,
       1,   100,   166,   240,   294,   295,   296,   297,   298,   242,
     242,   131,   176,   245,   131,   131,   131,   245,   131,   242,
     131,   131,   131,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     246,   242,   246,   242,   242,   242,   242,   242,   131,   245,
     131,   242,   131,   245,   242,   242,   250,   250,   250,   250,
     250,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,    10,
      12,   208,   222,   409,   410,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   136,   440,   441,
     242,   246,   242,   246,   252,   252,   252,    11,   178,   520,
     521,   242,   242,    11,   178,   514,   515,   242,   242,   242,
     242,    20,    44,    53,    59,    75,   101,   109,   152,   170,
     361,   362,   242,   242,   242,   242,   242,   242,   136,   420,
     421,   242,    61,   204,   208,   341,   342,   242,   242,   181,
     246,   346,   242,   245,   299,   245,   243,   295,   242,   242,
       5,    32,    51,    57,    74,    98,   105,   119,   137,   139,
     140,   192,   202,   211,   215,   217,   227,   237,   318,   319,
     242,   242,   242,    61,   183,   184,   185,   186,   187,   190,
     191,   194,   195,   196,   199,   201,   202,   203,   205,   206,
     207,   210,   216,   314,   315,   242,   242,   242,   242,   265,
     267,   242,    74,   151,   182,   192,   199,   211,   213,   214,
     227,   237,   385,   386,   242,   242,    74,   151,   182,   192,
     199,   211,   213,   214,   227,   237,   394,   395,   242,   246,
     242,   246,   501,   497,   242,   246,   242,   246,   242,   246,
     242,   246,   242,   246,   110,   348,   242,   131,   245,   212,
     253,   242,   242,   246,   242,   246,   242,   246,   242,   246,
     410,   441,   521,   515,   362,   421,   342,   242,    51,    72,
      74,   115,   191,   192,   228,   300,   301,   242,   242,   319,
     315,   386,   395,   242,   246,   301
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
#line 408 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 410 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 414 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 418 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 422 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 426 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 430 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 437 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 438 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 439 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 484 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 490 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 499 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 505 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 513 "conf_parser.y"
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
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 552 "conf_parser.y"
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

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

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

  case 80:

/* Line 1806 of yacc.c  */
#line 611 "conf_parser.y"
    {
/* TBD - XXX: error reporting */
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);
        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 635 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 643 "conf_parser.y"
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

  case 83:

/* Line 1806 of yacc.c  */
#line 658 "conf_parser.y"
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

  case 84:

/* Line 1806 of yacc.c  */
#line 673 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 682 "conf_parser.y"
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

  case 86:

/* Line 1806 of yacc.c  */
#line 696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 705 "conf_parser.y"
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

  case 88:

/* Line 1806 of yacc.c  */
#line 733 "conf_parser.y"
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

  case 89:

/* Line 1806 of yacc.c  */
#line 763 "conf_parser.y"
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

  case 90:

/* Line 1806 of yacc.c  */
#line 786 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 819 "conf_parser.y"
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
#line 837 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 843 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 849 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 866 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 871 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 874 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 886 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 920 "conf_parser.y"
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

  case 133:

/* Line 1806 of yacc.c  */
#line 933 "conf_parser.y"
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

  case 145:

/* Line 1806 of yacc.c  */
#line 1023 "conf_parser.y"
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

  case 146:

/* Line 1806 of yacc.c  */
#line 1035 "conf_parser.y"
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

  case 147:

/* Line 1806 of yacc.c  */
#line 1072 "conf_parser.y"
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

  case 148:

/* Line 1806 of yacc.c  */
#line 1084 "conf_parser.y"
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

  case 149:

/* Line 1806 of yacc.c  */
#line 1095 "conf_parser.y"
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

  case 150:

/* Line 1806 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1294 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1310 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 197:

/* Line 1806 of yacc.c  */
#line 1320 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 198:

/* Line 1806 of yacc.c  */
#line 1327 "conf_parser.y"
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

  case 215:

/* Line 1806 of yacc.c  */
#line 1385 "conf_parser.y"
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
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1485 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1491 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1495 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1499 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1509 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1514 "conf_parser.y"
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

  case 249:

/* Line 1806 of yacc.c  */
#line 1528 "conf_parser.y"
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

  case 250:

/* Line 1806 of yacc.c  */
#line 1548 "conf_parser.y"
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
#line 1557 "conf_parser.y"
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
#line 1569 "conf_parser.y"
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

  case 253:

/* Line 1806 of yacc.c  */
#line 1581 "conf_parser.y"
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

  case 265:

/* Line 1806 of yacc.c  */
#line 1643 "conf_parser.y"
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

  case 266:

/* Line 1806 of yacc.c  */
#line 1680 "conf_parser.y"
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

  case 267:

/* Line 1806 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1702 "conf_parser.y"
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

  case 269:

/* Line 1806 of yacc.c  */
#line 1713 "conf_parser.y"
    {
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1718 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1722 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1726 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1730 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1734 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1738 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1742 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1750 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1757 "conf_parser.y"
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

  case 283:

/* Line 1806 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1786 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1806 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 294:

/* Line 1806 of yacc.c  */
#line 1827 "conf_parser.y"
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

  case 295:

/* Line 1806 of yacc.c  */
#line 1842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1860 "conf_parser.y"
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

  case 302:

/* Line 1806 of yacc.c  */
#line 1875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1903 "conf_parser.y"
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

  case 312:

/* Line 1806 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1960 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1964 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 1977 "conf_parser.y"
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
#line 1984 "conf_parser.y"
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
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2003 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2010 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2014 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2018 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2022 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2026 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2034 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2038 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2042 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2046 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2055 "conf_parser.y"
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

  case 349:

/* Line 1806 of yacc.c  */
#line 2070 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->host &&
        yy_aconf->passwd && yy_aconf->spasswd)
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
        if (yy_aconf->host == NULL)
          yyerror("Ignoring connect block -- missing host");
        else if (!yy_aconf->passwd || !yy_aconf->spasswd)
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
#line 2192 "conf_parser.y"
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
#line 2204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 2213 "conf_parser.y"
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

  case 369:

/* Line 1806 of yacc.c  */
#line 2239 "conf_parser.y"
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

  case 370:

/* Line 1806 of yacc.c  */
#line 2257 "conf_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2275 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2281 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2285 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2293 "conf_parser.y"
    {
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 2310 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2316 "conf_parser.y"
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

  case 383:

/* Line 1806 of yacc.c  */
#line 2327 "conf_parser.y"
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

  case 384:

/* Line 1806 of yacc.c  */
#line 2340 "conf_parser.y"
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

  case 385:

/* Line 1806 of yacc.c  */
#line 2353 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2362 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->cipher_list);
    DupString(yy_aconf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2380 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 2387 "conf_parser.y"
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

  case 389:

/* Line 1806 of yacc.c  */
#line 2443 "conf_parser.y"
    {
}
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 2448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 2457 "conf_parser.y"
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

  case 401:

/* Line 1806 of yacc.c  */
#line 2476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 402:

/* Line 1806 of yacc.c  */
#line 2485 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 403:

/* Line 1806 of yacc.c  */
#line 2489 "conf_parser.y"
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

  case 409:

/* Line 1806 of yacc.c  */
#line 2511 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 410:

/* Line 1806 of yacc.c  */
#line 2517 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 2531 "conf_parser.y"
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

  case 417:

/* Line 1806 of yacc.c  */
#line 2549 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 2556 "conf_parser.y"
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

  case 419:

/* Line 1806 of yacc.c  */
#line 2596 "conf_parser.y"
    {
}
    break;

  case 423:

/* Line 1806 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 431:

/* Line 1806 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2751 "conf_parser.y"
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

  case 506:

/* Line 1806 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2776 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2812 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2827 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2832 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2883 "conf_parser.y"
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
#line 2892 "conf_parser.y"
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
#line 2901 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2943 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2955 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2958 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2964 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2970 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2973 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 2979 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 2984 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2990 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2993 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3005 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3011 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3017 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3023 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3026 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3032 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3038 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3041 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3044 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3047 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3052 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3057 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3062 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3067 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3076 "conf_parser.y"
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
#line 3083 "conf_parser.y"
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
#line 3109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3137 "conf_parser.y"
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
#line 3171 "conf_parser.y"
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
#line 3180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 608:

/* Line 1806 of yacc.c  */
#line 3184 "conf_parser.y"
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
#line 3231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3259 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3264 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3269 "conf_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3274 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3279 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3284 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3289 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3294 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3299 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3304 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3309 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3314 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3319 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3324 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3329 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3334 "conf_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3339 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3344 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3375 "conf_parser.y"
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
#line 3384 "conf_parser.y"
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
#line 3398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7701 "conf_parser.c"
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



