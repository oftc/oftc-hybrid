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

int yylex(void);

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
#line 182 "conf_parser.c"

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
     THROTTLE_TIME = 475,
     TOPICBURST = 476,
     TRUE_NO_OPER_FLOOD = 477,
     TKLINE = 478,
     TXLINE = 479,
     TRESV = 480,
     UNKLINE = 481,
     USER = 482,
     USE_EGD = 483,
     USE_EXCEPT = 484,
     USE_INVEX = 485,
     USE_KNOCK = 486,
     USE_LOGGING = 487,
     USE_WHOIS_ACTUALLY = 488,
     VHOST = 489,
     VHOST6 = 490,
     XLINE = 491,
     WARN = 492,
     WARN_NO_NLINE = 493,
     T_SIZE = 494,
     T_FILE = 495
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
#define THROTTLE_TIME 475
#define TOPICBURST 476
#define TRUE_NO_OPER_FLOOD 477
#define TKLINE 478
#define TXLINE 479
#define TRESV 480
#define UNKLINE 481
#define USER 482
#define USE_EGD 483
#define USE_EXCEPT 484
#define USE_INVEX 485
#define USE_KNOCK 486
#define USE_LOGGING 487
#define USE_WHOIS_ACTUALLY 488
#define VHOST 489
#define VHOST6 490
#define XLINE 491
#define WARN 492
#define WARN_NO_NLINE 493
#define T_SIZE 494
#define T_FILE 495




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 135 "conf_parser.y"

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
#define YYNTOKENS  246
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  305
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1311

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   495

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   245,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   241,
       2,   244,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,     2,   242,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240
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
     296,   301,   307,   310,   312,   314,   316,   319,   324,   325,
     332,   335,   337,   339,   341,   343,   346,   351,   356,   361,
     362,   368,   372,   374,   376,   378,   380,   382,   384,   386,
     388,   389,   396,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   420,   425,   430,   435,   440,   445,   450,
     451,   457,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   504,   510,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   553,   560,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   594,   599,   604,   609,   614,   619,   624,
     629,   634,   639,   644,   649,   654,   659,   660,   667,   668,
     674,   678,   680,   682,   684,   686,   689,   691,   693,   695,
     697,   699,   702,   703,   709,   713,   715,   717,   721,   726,
     731,   732,   739,   742,   744,   746,   748,   750,   752,   754,
     756,   758,   760,   763,   768,   773,   778,   783,   784,   790,
     794,   796,   798,   800,   802,   804,   806,   808,   810,   812,
     814,   819,   824,   829,   830,   837,   840,   842,   844,   846,
     848,   851,   856,   861,   866,   872,   875,   877,   879,   881,
     886,   887,   894,   897,   899,   901,   903,   905,   908,   913,
     918,   919,   925,   929,   931,   933,   935,   937,   939,   941,
     943,   945,   947,   949,   951,   952,   959,   962,   964,   966,
     968,   971,   976,   977,   983,   987,   989,   991,   993,   995,
     997,   999,  1001,  1003,  1005,  1007,  1009,  1010,  1017,  1020,
    1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
    1042,  1044,  1046,  1048,  1051,  1056,  1061,  1066,  1071,  1076,
    1081,  1086,  1091,  1092,  1098,  1102,  1104,  1106,  1108,  1110,
    1112,  1117,  1122,  1127,  1132,  1137,  1138,  1145,  1146,  1152,
    1156,  1158,  1160,  1163,  1165,  1167,  1169,  1171,  1173,  1178,
    1183,  1184,  1191,  1194,  1196,  1198,  1200,  1202,  1207,  1212,
    1218,  1221,  1223,  1225,  1227,  1232,  1233,  1240,  1241,  1247,
    1251,  1253,  1255,  1258,  1260,  1262,  1264,  1266,  1268,  1273,
    1278,  1284,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,
    1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,
    1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,
    1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,
    1383,  1385,  1387,  1389,  1391,  1393,  1398,  1403,  1408,  1413,
    1418,  1423,  1428,  1433,  1438,  1443,  1448,  1453,  1458,  1463,
    1468,  1473,  1478,  1483,  1488,  1493,  1498,  1503,  1508,  1513,
    1518,  1523,  1528,  1533,  1538,  1543,  1548,  1553,  1558,  1563,
    1568,  1573,  1578,  1583,  1588,  1593,  1598,  1603,  1608,  1613,
    1618,  1623,  1628,  1629,  1635,  1639,  1641,  1643,  1645,  1647,
    1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,
    1669,  1671,  1673,  1675,  1677,  1679,  1681,  1682,  1688,  1692,
    1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,
    1734,  1739,  1744,  1749,  1754,  1755,  1762,  1765,  1767,  1769,
    1771,  1773,  1775,  1777,  1779,  1781,  1786,  1791,  1792,  1798,
    1802,  1804,  1806,  1808,  1813,  1818,  1819,  1825,  1829,  1831,
    1833,  1835,  1841,  1844,  1846,  1848,  1850,  1852,  1854,  1856,
    1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,  1876,
    1878,  1880,  1882,  1884,  1889,  1894,  1899,  1904,  1909,  1914,
    1919,  1924,  1929,  1934,  1939,  1944,  1949,  1954,  1959,  1964,
    1969,  1974,  1980,  1983,  1985,  1987,  1989,  1991,  1993,  1995,
    1997,  1999,  2001,  2006,  2011,  2016,  2021,  2026,  2031
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     247,     0,    -1,    -1,   247,   248,    -1,   280,    -1,   286,
      -1,   300,    -1,   520,    -1,   318,    -1,   335,    -1,   349,
      -1,   258,    -1,   541,    -1,   364,    -1,   371,    -1,   375,
      -1,   385,    -1,   394,    -1,   414,    -1,   424,    -1,   430,
      -1,   444,    -1,   504,    -1,   434,    -1,   253,    -1,     1,
     241,    -1,     1,   242,    -1,    -1,   250,    -1,   110,   249,
      -1,   110,   153,   249,    -1,   110,   154,   249,    -1,   110,
     155,   249,    -1,   110,   156,   249,    -1,   110,   157,   249,
      -1,    -1,   252,    -1,   110,   251,    -1,   110,    14,   251,
      -1,   110,    15,   251,    -1,   110,    16,   251,    -1,    99,
     243,   254,   242,   241,    -1,   254,   255,    -1,   255,    -1,
     256,    -1,   257,    -1,     1,   241,    -1,    98,   244,   131,
     241,    -1,   126,   244,   131,   241,    -1,   161,   243,   259,
     242,   241,    -1,   259,   260,    -1,   260,    -1,   271,    -1,
     276,    -1,   279,    -1,   273,    -1,   274,    -1,   275,    -1,
     278,    -1,   269,    -1,   268,    -1,   277,    -1,   272,    -1,
     267,    -1,   261,    -1,   262,    -1,   270,    -1,     1,   241,
      -1,   147,   244,   263,   241,    -1,   148,   244,   265,   241,
      -1,   263,   245,   264,    -1,   264,    -1,   149,    -1,   150,
      -1,   265,   245,   266,    -1,   266,    -1,   149,    -1,   150,
      -1,   145,   244,   131,   241,    -1,   143,   244,   131,   241,
      -1,   146,   244,   131,   241,    -1,   188,   244,   131,   241,
      -1,   100,   244,   131,   241,    -1,   162,   244,   131,   241,
      -1,    31,   244,   131,   241,    -1,   103,   244,   131,   241,
      -1,   102,   244,   131,   241,    -1,   234,   244,   131,   241,
      -1,   235,   244,   131,   241,    -1,   200,   244,   110,   241,
      -1,    67,   244,   176,   241,    -1,     5,   243,   281,   242,
     241,    -1,   281,   282,    -1,   282,    -1,   283,    -1,   285,
      -1,   284,    -1,     1,   241,    -1,   100,   244,   131,   241,
      -1,    41,   244,   131,   241,    -1,    31,   244,   131,   241,
      -1,    83,   243,   287,   242,   241,    -1,   287,   288,    -1,
     288,    -1,   289,    -1,   290,    -1,     1,   241,    -1,   232,
     244,   176,   241,    -1,    -1,   291,   240,   243,   292,   242,
     241,    -1,   292,   293,    -1,   293,    -1,   294,    -1,   296,
      -1,   295,    -1,     1,   241,    -1,   100,   244,   131,   241,
      -1,   239,   244,   252,   241,    -1,   239,   244,   212,   241,
      -1,    -1,   166,   297,   244,   298,   241,    -1,   298,   245,
     299,    -1,   299,    -1,   227,    -1,   115,    -1,    51,    -1,
     192,    -1,    74,    -1,    72,    -1,   191,    -1,    -1,   115,
     301,   243,   302,   242,   241,    -1,   302,   303,    -1,   303,
      -1,   304,    -1,   305,    -1,   306,    -1,   310,    -1,   309,
      -1,   307,    -1,   308,    -1,   314,    -1,     1,   241,    -1,
     100,   244,   131,   241,    -1,   227,   244,   131,   241,    -1,
     125,   244,   131,   241,    -1,    43,   244,   176,   241,    -1,
     144,   244,   131,   241,    -1,    24,   244,   131,   241,    -1,
      -1,   209,   311,   244,   312,   241,    -1,   312,   245,   313,
      -1,   313,    -1,   183,    -1,   186,    -1,   187,    -1,   190,
      -1,   191,    -1,   195,    -1,    61,    -1,   206,    -1,   201,
      -1,   203,    -1,   210,    -1,   207,    -1,   194,    -1,   202,
      -1,   205,    -1,   196,    -1,   216,    -1,   184,    -1,   185,
      -1,   199,    -1,    -1,    47,   315,   244,   316,   241,    -1,
     316,   245,   317,    -1,   317,    -1,    57,    -1,   139,    -1,
      74,    -1,   226,    -1,   192,    -1,   211,    -1,   236,    -1,
      51,    -1,    32,    -1,   217,    -1,   137,    -1,     5,    -1,
     105,    -1,   202,    -1,   215,    -1,   119,    -1,   140,    -1,
      98,    -1,    -1,    24,   319,   243,   320,   242,   241,    -1,
     320,   321,    -1,   321,    -1,   322,    -1,   332,    -1,   333,
      -1,   323,    -1,   324,    -1,   334,    -1,   325,    -1,   326,
      -1,   327,    -1,   328,    -1,   329,    -1,   330,    -1,   331,
      -1,     1,   241,    -1,   100,   244,   131,   241,    -1,   128,
     244,   250,   241,    -1,   129,   244,   250,   241,    -1,   113,
     244,   110,   241,    -1,    26,   244,   250,   241,    -1,    92,
     244,   110,   241,    -1,    87,   244,   110,   241,    -1,    89,
     244,   110,   241,    -1,    88,   244,   110,   241,    -1,   158,
     244,   252,   241,    -1,    22,   244,   110,   241,    -1,    23,
     244,   110,   241,    -1,   112,   244,   110,   241,    -1,    -1,
      82,   336,   243,   341,   242,   241,    -1,    -1,    47,   338,
     244,   339,   241,    -1,   339,   245,   340,    -1,   340,    -1,
     208,    -1,    61,    -1,   204,    -1,   341,   342,    -1,   342,
      -1,   343,    -1,   337,    -1,   347,    -1,   348,    -1,     1,
     241,    -1,    -1,   130,   244,   345,   344,   241,    -1,   345,
     245,   346,    -1,   346,    -1,   110,    -1,   110,   181,   110,
      -1,    71,   244,   131,   241,    -1,    66,   244,   131,   241,
      -1,    -1,    58,   350,   243,   351,   242,   241,    -1,   351,
     352,    -1,   352,    -1,   353,    -1,   354,    -1,   355,    -1,
     357,    -1,   361,    -1,   362,    -1,   363,    -1,   356,    -1,
       1,   241,    -1,   227,   244,   131,   241,    -1,   125,   244,
     131,   241,    -1,    24,   244,   131,   241,    -1,    43,   244,
     176,   241,    -1,    -1,    47,   358,   244,   359,   241,    -1,
     359,   245,   360,    -1,   360,    -1,   170,    -1,    44,    -1,
      75,    -1,    59,    -1,    20,    -1,   109,    -1,    53,    -1,
     152,    -1,   101,    -1,   169,   244,   131,   241,    -1,   135,
     244,   131,   241,    -1,   134,   244,   110,   241,    -1,    -1,
     151,   365,   243,   366,   242,   241,    -1,   366,   367,    -1,
     367,    -1,   368,    -1,   369,    -1,   370,    -1,     1,   241,
      -1,   133,   244,   131,   241,    -1,    21,   244,   131,   241,
      -1,   104,   244,   131,   241,    -1,   218,   243,   372,   242,
     241,    -1,   372,   373,    -1,   373,    -1,   374,    -1,     1,
      -1,   100,   244,   131,   241,    -1,    -1,   164,   376,   243,
     377,   242,   241,    -1,   377,   378,    -1,   378,    -1,   379,
      -1,   380,    -1,   381,    -1,     1,   241,    -1,   100,   244,
     131,   241,    -1,   227,   244,   131,   241,    -1,    -1,   166,
     382,   244,   383,   241,    -1,   383,   245,   384,    -1,   384,
      -1,    74,    -1,   226,    -1,   192,    -1,   211,    -1,   236,
      -1,   214,    -1,   151,    -1,   213,    -1,   199,    -1,   182,
      -1,    -1,   165,   386,   243,   387,   242,   241,    -1,   387,
     388,    -1,   388,    -1,   389,    -1,   390,    -1,     1,   241,
      -1,   100,   244,   131,   241,    -1,    -1,   166,   391,   244,
     392,   241,    -1,   392,   245,   393,    -1,   393,    -1,    74,
      -1,   226,    -1,   192,    -1,   211,    -1,   236,    -1,   214,
      -1,   151,    -1,   213,    -1,   199,    -1,   182,    -1,    -1,
      25,   395,   243,   396,   242,   241,    -1,   396,   397,    -1,
     397,    -1,   398,    -1,   399,    -1,   400,    -1,   401,    -1,
     402,    -1,   404,    -1,   403,    -1,   413,    -1,   405,    -1,
     410,    -1,   411,    -1,   412,    -1,   409,    -1,     1,   241,
      -1,   100,   244,   131,   241,    -1,    66,   244,   131,   241,
      -1,   234,   244,   131,   241,    -1,   159,   244,   131,   241,
      -1,     3,   244,   131,   241,    -1,   130,   244,   110,   241,
      -1,     6,   244,   197,   241,    -1,     6,   244,   198,   241,
      -1,    -1,    47,   406,   244,   407,   241,    -1,   407,   245,
     408,    -1,   408,    -1,    10,    -1,    12,    -1,   221,    -1,
     208,    -1,    43,   244,   176,   241,    -1,    68,   244,   131,
     241,    -1,    80,   244,   131,   241,    -1,    24,   244,   131,
     241,    -1,   188,   244,   131,   241,    -1,    -1,    72,   415,
     243,   420,   242,   241,    -1,    -1,   166,   417,   244,   418,
     241,    -1,   418,   245,   419,    -1,   419,    -1,   136,    -1,
     420,   421,    -1,   421,    -1,   422,    -1,   423,    -1,   416,
      -1,     1,    -1,   227,   244,   131,   241,    -1,   133,   244,
     131,   241,    -1,    -1,    30,   425,   243,   426,   242,   241,
      -1,   426,   427,    -1,   427,    -1,   428,    -1,   429,    -1,
       1,    -1,    71,   244,   131,   241,    -1,   133,   244,   131,
     241,    -1,    45,   243,   431,   242,   241,    -1,   431,   432,
      -1,   432,    -1,   433,    -1,     1,    -1,    71,   244,   131,
     241,    -1,    -1,    49,   435,   243,   440,   242,   241,    -1,
      -1,   166,   437,   244,   438,   241,    -1,   438,   245,   439,
      -1,   439,    -1,   136,    -1,   440,   441,    -1,   441,    -1,
     442,    -1,   443,    -1,   436,    -1,     1,    -1,   100,   244,
     131,   241,    -1,   133,   244,   131,   241,    -1,    50,   243,
     445,   242,   241,    -1,   445,   446,    -1,   446,    -1,   454,
      -1,   455,    -1,   457,    -1,   458,    -1,   459,    -1,   460,
      -1,   461,    -1,   462,    -1,   463,    -1,   464,    -1,   453,
      -1,   466,    -1,   467,    -1,   468,    -1,   469,    -1,   484,
      -1,   471,    -1,   473,    -1,   475,    -1,   474,    -1,   478,
      -1,   472,    -1,   479,    -1,   480,    -1,   481,    -1,   482,
      -1,   483,    -1,   496,    -1,   485,    -1,   486,    -1,   487,
      -1,   492,    -1,   476,    -1,   477,    -1,   502,    -1,   500,
      -1,   501,    -1,   456,    -1,   503,    -1,   491,    -1,   465,
      -1,   489,    -1,   490,    -1,   452,    -1,   448,    -1,   449,
      -1,   450,    -1,   451,    -1,   470,    -1,   447,    -1,   488,
      -1,     1,    -1,    94,   244,   110,   241,    -1,    55,   244,
     110,   241,    -1,    56,   244,   110,   241,    -1,   233,   244,
     176,   241,    -1,   138,   244,   250,   241,    -1,   163,   244,
     176,   241,    -1,    73,   244,   250,   241,    -1,    65,   244,
     176,   241,    -1,    69,   244,   176,   241,    -1,    37,   244,
     176,   241,    -1,    46,   244,   176,   241,    -1,     8,   244,
     176,   241,    -1,    91,   244,   250,   241,    -1,    90,   244,
     110,   241,    -1,    84,   244,   110,   241,    -1,     9,   244,
     250,   241,    -1,   180,   244,   250,   241,    -1,   179,   244,
     250,   241,    -1,    60,   244,   110,   241,    -1,    77,   244,
     176,   241,    -1,    76,   244,   131,   241,    -1,    70,   244,
     176,   241,    -1,   238,   244,   176,   241,    -1,   171,   244,
     176,   241,    -1,   174,   244,   176,   241,    -1,   175,   244,
     176,   241,    -1,   173,   244,   176,   241,    -1,   173,   244,
     177,   241,    -1,   172,   244,   176,   241,    -1,   172,   244,
     177,   241,    -1,   123,   244,   250,   241,    -1,    19,   244,
     250,   241,    -1,   116,   244,   176,   241,    -1,   124,   244,
     250,   241,    -1,   167,   244,   176,   241,    -1,   108,   244,
     176,   241,    -1,   222,   244,   176,   241,    -1,   118,   244,
     176,   241,    -1,    95,   244,   131,   241,    -1,    38,   244,
     110,   241,    -1,    93,   244,   110,   241,    -1,   228,   244,
     176,   241,    -1,    40,   244,   131,   241,    -1,   219,   244,
     131,   241,    -1,   127,   244,   176,   241,    -1,    33,   244,
     176,   241,    -1,   220,   244,   250,   241,    -1,    -1,   120,
     493,   244,   494,   241,    -1,   494,   245,   495,    -1,   495,
      -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,   191,
      -1,   195,    -1,    61,    -1,   206,    -1,   201,    -1,   203,
      -1,   210,    -1,   207,    -1,   194,    -1,   202,    -1,   205,
      -1,   196,    -1,   216,    -1,   184,    -1,   185,    -1,   199,
      -1,    -1,   117,   497,   244,   498,   241,    -1,   498,   245,
     499,    -1,   499,    -1,   183,    -1,   186,    -1,   187,    -1,
     190,    -1,   191,    -1,   195,    -1,   206,    -1,    61,    -1,
     201,    -1,   203,    -1,   210,    -1,   207,    -1,   194,    -1,
     202,    -1,   205,    -1,   196,    -1,   216,    -1,   184,    -1,
     185,    -1,   199,    -1,    96,   244,   110,   241,    -1,    97,
     244,   110,   241,    -1,    27,   244,   110,   241,    -1,   189,
     244,   252,   241,    -1,    -1,    52,   505,   243,   506,   242,
     241,    -1,   506,   507,    -1,   507,    -1,   508,    -1,   509,
      -1,   510,    -1,   514,    -1,   515,    -1,   516,    -1,     1,
      -1,    42,   244,   176,   241,    -1,    39,   244,   250,   241,
      -1,    -1,    83,   511,   244,   512,   241,    -1,   512,   245,
     513,    -1,   513,    -1,   178,    -1,    11,    -1,   227,   244,
     131,   241,    -1,   100,   244,   131,   241,    -1,    -1,     4,
     517,   244,   518,   241,    -1,   518,   245,   519,    -1,   519,
      -1,   178,    -1,    11,    -1,    21,   243,   521,   242,   241,
      -1,   521,   522,    -1,   522,    -1,   525,    -1,   526,    -1,
     527,    -1,   528,    -1,   533,    -1,   529,    -1,   530,    -1,
     531,    -1,   532,    -1,   534,    -1,   535,    -1,   536,    -1,
     524,    -1,   537,    -1,   538,    -1,   539,    -1,   540,    -1,
     523,    -1,     1,    -1,    34,   244,   176,   241,    -1,   141,
     244,   176,   241,    -1,    36,   244,   176,   241,    -1,   229,
     244,   176,   241,    -1,   230,   244,   176,   241,    -1,   231,
     244,   176,   241,    -1,    78,   244,   250,   241,    -1,    79,
     244,   250,   241,    -1,    86,   244,   110,   241,    -1,   132,
     244,   176,   241,    -1,    85,   244,   110,   241,    -1,    29,
     244,   110,   241,    -1,    28,   244,   110,   241,    -1,   106,
     244,   176,   241,    -1,   107,   244,   176,   241,    -1,    13,
     244,   176,   241,    -1,   121,   244,   110,   241,    -1,   122,
     244,   250,   241,    -1,   160,   243,   542,   242,   241,    -1,
     542,   543,    -1,   543,    -1,   544,    -1,   545,    -1,   547,
      -1,   549,    -1,   548,    -1,   546,    -1,   550,    -1,     1,
      -1,    48,   244,   176,   241,    -1,    64,   244,   176,   241,
      -1,    62,   244,   131,   241,    -1,    81,   244,   250,   241,
      -1,    61,   244,   176,   241,    -1,    35,   244,   176,   241,
      -1,    63,   244,   176,   241,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   379,   379,   380,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   409,   409,   410,
     414,   418,   422,   426,   430,   436,   436,   437,   438,   439,
     440,   447,   450,   450,   451,   451,   451,   453,   459,   466,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   477,   480,   481,
     483,   483,   484,   490,   498,   498,   499,   505,   513,   552,
     611,   639,   647,   662,   677,   686,   700,   709,   737,   767,
     790,   799,   801,   801,   802,   802,   803,   803,   805,   814,
     823,   835,   836,   836,   838,   838,   839,   841,   848,   848,
     858,   859,   861,   861,   862,   862,   864,   869,   872,   878,
     877,   883,   883,   884,   888,   892,   896,   900,   904,   908,
     919,   918,  1016,  1016,  1017,  1017,  1017,  1018,  1018,  1018,
    1019,  1019,  1019,  1021,  1033,  1070,  1082,  1093,  1135,  1145,
    1144,  1150,  1150,  1151,  1155,  1159,  1163,  1167,  1171,  1175,
    1179,  1183,  1187,  1191,  1195,  1199,  1203,  1207,  1211,  1215,
    1219,  1223,  1227,  1234,  1233,  1239,  1239,  1240,  1244,  1248,
    1252,  1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,  1288,
    1292,  1296,  1300,  1304,  1308,  1319,  1318,  1368,  1368,  1369,
    1370,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1383,  1392,  1398,  1404,  1410,  1416,  1422,
    1428,  1434,  1440,  1446,  1452,  1458,  1468,  1467,  1484,  1483,
    1488,  1488,  1489,  1493,  1497,  1505,  1505,  1506,  1506,  1506,
    1506,  1506,  1508,  1508,  1510,  1510,  1512,  1526,  1546,  1555,
    1568,  1567,  1636,  1636,  1637,  1637,  1637,  1637,  1638,  1638,
    1638,  1639,  1639,  1641,  1678,  1691,  1700,  1712,  1711,  1715,
    1715,  1716,  1720,  1724,  1728,  1732,  1736,  1740,  1744,  1748,
    1755,  1774,  1784,  1798,  1797,  1813,  1813,  1814,  1814,  1814,
    1814,  1816,  1825,  1840,  1853,  1855,  1855,  1856,  1856,  1858,
    1874,  1873,  1889,  1889,  1890,  1890,  1890,  1890,  1892,  1901,
    1924,  1923,  1929,  1929,  1930,  1934,  1938,  1942,  1946,  1950,
    1954,  1958,  1962,  1966,  1976,  1975,  1992,  1992,  1993,  1993,
    1993,  1995,  2002,  2001,  2007,  2007,  2008,  2012,  2016,  2020,
    2024,  2028,  2032,  2036,  2040,  2044,  2054,  2053,  2182,  2182,
    2183,  2183,  2183,  2184,  2184,  2185,  2185,  2185,  2186,  2186,
    2186,  2187,  2187,  2188,  2190,  2199,  2208,  2234,  2252,  2270,
    2276,  2280,  2289,  2288,  2292,  2292,  2293,  2297,  2301,  2305,
    2311,  2322,  2335,  2348,  2357,  2376,  2375,  2441,  2440,  2444,
    2444,  2445,  2451,  2451,  2452,  2452,  2452,  2452,  2454,  2473,
    2483,  2482,  2507,  2507,  2508,  2508,  2508,  2510,  2516,  2525,
    2527,  2527,  2528,  2528,  2530,  2549,  2548,  2596,  2595,  2599,
    2599,  2600,  2606,  2606,  2607,  2607,  2607,  2607,  2609,  2615,
    2624,  2627,  2627,  2628,  2628,  2629,  2629,  2630,  2630,  2631,
    2631,  2632,  2632,  2633,  2633,  2634,  2634,  2635,  2635,  2636,
    2636,  2637,  2637,  2638,  2638,  2639,  2639,  2640,  2640,  2641,
    2642,  2642,  2643,  2643,  2644,  2644,  2645,  2645,  2646,  2646,
    2647,  2648,  2649,  2649,  2650,  2651,  2652,  2652,  2653,  2653,
    2654,  2654,  2655,  2655,  2656,  2659,  2664,  2669,  2674,  2679,
    2684,  2689,  2694,  2699,  2704,  2709,  2714,  2719,  2724,  2729,
    2734,  2739,  2744,  2750,  2761,  2766,  2775,  2780,  2785,  2790,
    2795,  2800,  2803,  2808,  2811,  2816,  2821,  2826,  2831,  2836,
    2841,  2846,  2851,  2856,  2867,  2872,  2877,  2882,  2891,  2900,
    2905,  2910,  2916,  2915,  2920,  2920,  2921,  2924,  2927,  2930,
    2933,  2936,  2939,  2942,  2945,  2948,  2951,  2954,  2957,  2960,
    2963,  2966,  2969,  2972,  2975,  2978,  2984,  2983,  2988,  2988,
    2989,  2992,  2995,  2998,  3001,  3004,  3007,  3010,  3013,  3016,
    3019,  3022,  3025,  3028,  3031,  3034,  3037,  3040,  3043,  3046,
    3051,  3056,  3061,  3066,  3076,  3075,  3099,  3099,  3100,  3101,
    3102,  3103,  3104,  3105,  3106,  3108,  3114,  3121,  3120,  3125,
    3125,  3126,  3130,  3136,  3170,  3180,  3179,  3229,  3229,  3230,
    3234,  3243,  3246,  3246,  3247,  3247,  3248,  3248,  3249,  3249,
    3250,  3250,  3251,  3251,  3252,  3253,  3253,  3254,  3254,  3255,
    3255,  3256,  3256,  3258,  3263,  3268,  3273,  3278,  3283,  3288,
    3293,  3298,  3303,  3308,  3313,  3318,  3323,  3328,  3333,  3338,
    3343,  3351,  3354,  3354,  3355,  3355,  3356,  3357,  3358,  3358,
    3359,  3360,  3362,  3368,  3374,  3383,  3397,  3403,  3409
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
  "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV",
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK",
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_client_method",
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
  "logging_file_entry", "$@1", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@2",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@3",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class",
  "oper_umodes", "$@4", "oper_umodes_items", "oper_umodes_item",
  "oper_flags", "$@5", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@6", "class_items", "class_item", "class_name",
  "class_ping_time", "class_ping_warning", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@7", "listen_flags", "$@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@11", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@12", "resv_items",
  "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "service_entry", "service_items", "service_item", "service_name",
  "shared_entry", "$@13", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "$@14", "shared_types", "shared_type_item",
  "cluster_entry", "$@15", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@16", "cluster_types", "cluster_type_item",
  "connect_entry", "$@17", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@18", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@19",
  "kill_type", "$@20", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@21",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@22",
  "gecos_flags", "$@23", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_min_cidr", "general_gline_min_cidr6",
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
  "general_dots_in_ident", "general_max_targets", "general_use_egd",
  "general_egdpool_path", "general_services_name", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "$@24", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@25", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "gline_entry", "$@26", "gline_items",
  "gline_item", "gline_enable", "gline_duration", "gline_logging", "$@27",
  "gline_logging_types", "gline_logging_type_item", "gline_user",
  "gline_server", "gline_action", "$@28", "gdeny_types", "gdeny_type_item",
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
     495,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   246,   247,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   250,   250,   250,   250,   251,   251,   252,   252,   252,
     252,   253,   254,   254,   255,   255,   255,   256,   257,   258,
     259,   259,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   261,   262,
     263,   263,   264,   264,   265,   265,   266,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   281,   282,   282,   282,   282,   283,   284,
     285,   286,   287,   287,   288,   288,   288,   289,   291,   290,
     292,   292,   293,   293,   293,   293,   294,   295,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     301,   300,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   304,   305,   306,   307,   308,   309,   311,
     310,   312,   312,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   315,   314,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   319,   318,   320,   320,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   336,   335,   338,   337,
     339,   339,   340,   340,   340,   341,   341,   342,   342,   342,
     342,   342,   344,   343,   345,   345,   346,   346,   347,   348,
     350,   349,   351,   351,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   353,   354,   355,   356,   358,   357,   359,
     359,   360,   360,   360,   360,   360,   360,   360,   360,   360,
     361,   362,   363,   365,   364,   366,   366,   367,   367,   367,
     367,   368,   369,   370,   371,   372,   372,   373,   373,   374,
     376,   375,   377,   377,   378,   378,   378,   378,   379,   380,
     382,   381,   383,   383,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   386,   385,   387,   387,   388,   388,
     388,   389,   391,   390,   392,   392,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   393,   395,   394,   396,   396,
     397,   397,   397,   397,   397,   397,   397,   397,   397,   397,
     397,   397,   397,   397,   398,   399,   400,   401,   402,   403,
     404,   404,   406,   405,   407,   407,   408,   408,   408,   408,
     409,   410,   411,   412,   413,   415,   414,   417,   416,   418,
     418,   419,   420,   420,   421,   421,   421,   421,   422,   423,
     425,   424,   426,   426,   427,   427,   427,   428,   429,   430,
     431,   431,   432,   432,   433,   435,   434,   437,   436,   438,
     438,   439,   440,   440,   441,   441,   441,   441,   442,   443,
     444,   445,   445,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   473,   474,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   493,   492,   494,   494,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   497,   496,   498,   498,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     500,   501,   502,   503,   505,   504,   506,   506,   507,   507,
     507,   507,   507,   507,   507,   508,   509,   511,   510,   512,
     512,   513,   513,   514,   515,   517,   516,   518,   518,   519,
     519,   520,   521,   521,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   542,   543,   543,   543,   543,   543,   543,
     543,   543,   544,   545,   546,   547,   548,   549,   550
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
       4,     5,     2,     1,     1,     1,     2,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       2,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   346,   400,     0,
     415,     0,   584,   250,   385,   226,     0,     0,   130,   283,
       0,     0,   300,   324,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    96,    95,   632,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     631,   626,   614,   615,   616,   617,   619,   620,   621,   622,
     618,   623,   624,   625,   627,   628,   629,   630,     0,     0,
       0,   413,     0,     0,   411,   412,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   556,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   482,   477,   478,   479,   480,   476,   443,   433,   434,
     470,   435,   436,   437,   438,   439,   440,   441,   442,   473,
     444,   445,   446,   447,   481,   449,   454,   450,   452,   451,
     465,   466,   453,   455,   456,   457,   458,   459,   448,   461,
     462,   463,   483,   474,   475,   472,   464,   460,   468,   469,
     467,   471,     0,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,     0,     0,    43,    44,    45,
       0,     0,   661,     0,     0,     0,     0,     0,     0,     0,
       0,   653,   654,   655,   659,   656,   658,   657,   660,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    64,    65,    63,
      60,    59,    66,    52,    62,    55,    56,    57,    53,    61,
      58,    54,     0,     0,   298,     0,     0,   296,   297,    97,
       0,     0,     0,     0,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     198,   199,   202,   203,   205,   206,   207,   208,   209,   210,
     211,   200,   201,   204,     0,     0,     0,     0,     0,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   349,
     350,   351,   352,   353,   354,   356,   355,   358,   362,   359,
     360,   361,   357,   406,     0,     0,     0,   403,   404,   405,
       0,     0,   410,   427,     0,     0,   417,   426,     0,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   431,   594,   605,     0,     0,   597,
       0,     0,     0,   587,   588,   589,   590,   591,   592,   593,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,   261,   257,   258,   259,   260,   397,
       0,   387,     0,   396,     0,   393,   394,   395,     0,   228,
       0,     0,     0,   238,     0,   236,   237,   239,   240,   106,
       0,     0,   102,     0,    46,     0,     0,     0,    42,     0,
       0,     0,   173,     0,     0,     0,   149,     0,     0,   133,
     134,   135,   136,   139,   140,   138,   137,   141,     0,     0,
       0,     0,     0,   286,   287,   288,   289,     0,     0,     0,
       0,     0,     0,     0,     0,   652,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,     0,     0,   310,     0,     0,   303,
     304,   305,   306,     0,     0,   332,     0,   327,   328,   329,
       0,     0,   295,     0,     0,     0,    91,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   611,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,   402,     0,   409,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,   586,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,   392,   241,
       0,     0,     0,     0,     0,   235,     0,   101,     0,     0,
       0,    41,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,   290,     0,     0,     0,     0,   285,     0,
       0,     0,     0,     0,     0,     0,   651,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    73,     0,    71,    76,
      77,     0,    75,     0,     0,     0,     0,     0,    49,   307,
       0,     0,     0,     0,   302,   330,     0,     0,     0,   326,
       0,   294,   100,    99,    98,   648,   645,   644,   633,   635,
      27,    27,    27,    27,    27,    29,    28,   639,   640,   643,
     641,   646,   647,   649,   650,   642,   634,   636,   637,   638,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,   401,   414,     0,     0,     0,   416,   496,   500,   516,
     582,   530,   494,   524,   527,   495,   486,   487,   503,   492,
     493,   506,   491,   505,   504,   499,   498,   497,   525,   485,
     523,   580,   581,   520,   517,   567,   560,   577,   578,   561,
     562,   563,   564,   572,   565,   575,   579,   568,   573,   569,
     574,   566,   571,   570,   576,     0,   559,   522,   542,   536,
     553,   554,   537,   538,   539,   540,   548,   541,   551,   555,
     544,   549,   545,   550,   543,   547,   546,   552,     0,   535,
     515,   518,   529,   489,   490,   519,   508,   513,   514,   511,
     512,   509,   510,   502,   501,    35,    35,    35,    37,    36,
     583,   528,   531,   521,   526,   488,   507,     0,     0,     0,
       0,     0,     0,   585,     0,     0,     0,     0,     0,     0,
       0,     0,   251,     0,     0,     0,   386,     0,     0,     0,
     246,   242,   245,   227,   107,     0,     0,   119,     0,     0,
     111,   112,   114,   113,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     0,   284,   667,
     662,   666,   664,   668,   663,   665,    84,    90,    82,    86,
      85,    79,    78,    80,    68,     0,    69,     0,    83,    81,
      89,    87,    88,     0,     0,     0,   301,     0,     0,   325,
     299,    30,    31,    32,    33,    34,   223,   224,   217,   219,
     221,   220,   218,   213,   225,   216,   214,   215,   222,   368,
     370,   371,   383,   380,   376,   377,   379,   378,     0,   375,
     365,   381,   382,   364,   369,   367,   384,   366,   407,   408,
     428,   429,   421,     0,   420,   557,     0,   533,     0,    38,
      39,    40,   610,   609,     0,   608,   596,   595,   602,   601,
       0,   600,   604,   603,   265,   266,   275,   272,   277,   274,
     273,   279,   276,   278,   271,     0,   270,   264,   282,   281,
     280,   263,   399,   391,     0,   390,   398,   233,   234,   232,
       0,   231,   249,   248,     0,     0,     0,   115,     0,     0,
       0,     0,   110,   148,   146,   188,   185,   184,   177,   179,
     194,   189,   192,   187,   178,   193,   181,   190,   182,   191,
     186,   180,   183,     0,   176,   143,   145,   147,   159,   153,
     170,   171,   154,   155,   156,   157,   165,   158,   168,   172,
     161,   166,   162,   167,   160,   164,   163,   169,     0,   152,
     144,   292,   293,   291,    70,    74,   308,   314,   320,   323,
     316,   322,   317,   321,   319,   315,   318,     0,   313,   309,
     331,   336,   342,   345,   338,   344,   339,   343,   341,   337,
     340,     0,   335,   373,     0,   418,     0,   558,   534,   606,
       0,   598,     0,   268,     0,   388,     0,   229,     0,   247,
     244,   243,     0,     0,     0,     0,   109,   174,     0,   150,
       0,   311,     0,   333,     0,   374,   419,   607,   599,   269,
     389,   230,   116,   125,   128,   127,   124,   129,   126,   123,
       0,   122,   118,   117,   175,   151,   312,   334,   120,     0,
     121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   835,   836,   978,   979,    26,   246,   247,
     248,   249,    27,   285,   286,   287,   288,   797,   798,   801,
     802,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,    28,    74,    75,    76,    77,    78,
      29,   238,   239,   240,   241,   242,  1019,  1020,  1021,  1022,
    1023,  1169,  1300,  1301,    30,    63,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   769,  1218,  1219,   547,   765,
    1193,  1194,    31,    51,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    32,
      60,   513,   750,  1160,  1161,   514,   515,   516,  1166,  1011,
    1012,   517,   518,    33,    58,   489,   490,   491,   492,   493,
     494,   495,   736,  1145,  1146,   496,   497,   498,    34,    64,
     552,   553,   554,   555,   556,    35,   306,   307,   308,    36,
      67,   588,   589,   590,   591,   592,   811,  1237,  1238,    37,
      68,   596,   597,   598,   599,   817,  1251,  1252,    38,    52,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     648,  1098,  1099,   388,   389,   390,   391,   392,    39,    59,
     503,   745,  1154,  1155,   504,   505,   506,   507,    40,    53,
     396,   397,   398,   399,    41,   123,   124,   125,    42,    55,
     407,   667,  1113,  1114,   408,   409,   410,   411,    43,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   442,   958,   959,
     227,   440,   935,   936,   228,   229,   230,   231,    44,    57,
     472,   473,   474,   475,   476,   728,  1130,  1131,   477,   478,
     479,   725,  1124,  1125,    45,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,    46,   260,   261,   262,   263,
     264,   265,   266,   267,   268
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -560
static const yytype_int16 yypact[] =
{
    -560,   667,  -560,  -206,  -223,  -221,  -560,  -560,  -560,  -218,
    -560,  -191,  -560,  -560,  -560,  -560,  -189,  -183,  -560,  -560,
    -154,  -136,  -560,  -560,  -133,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,    42,
     544,  -115,  -109,   -80,    32,   -72,   375,   -70,   -53,   -51,
     -33,    60,    87,   -20,   -18,   324,   334,    -5,    -3,    20,
     -89,    17,    35,    51,     9,  -560,  -560,  -560,  -560,  -560,
      61,    63,    73,    79,    96,   111,   117,   125,   131,   136,
     137,   152,   154,   156,   159,   162,   170,   175,   180,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   709,   461,
      98,  -560,   195,    10,  -560,  -560,   266,  -560,   198,   199,
     202,   203,   206,   213,   214,   216,   217,   219,   229,   230,
     231,   232,   242,   243,   246,   250,   253,   256,   257,   259,
     261,   263,   265,   268,   275,   276,  -560,   277,  -560,   281,
     282,   284,   287,   291,   293,   295,   296,   299,   300,   307,
     314,   315,   316,   318,   319,   321,   322,   323,   327,   110,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,     2,   509,    16,   326,    57,   330,    36,  -560,
    -560,  -560,     7,    77,   331,   332,    28,  -560,  -560,  -560,
     279,   211,  -560,   335,   338,   339,   341,   342,   343,   344,
       3,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   200,
     345,   346,   348,   349,   352,   355,   356,   357,   358,   360,
     362,   363,   365,   366,   367,    74,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,   197,     6,  -560,   368,    46,  -560,  -560,  -560,
     140,   173,   392,   329,  -560,   438,   328,   505,   441,   445,
     514,   514,   515,   516,   451,   452,   521,   514,   456,   457,
     459,   460,   462,   396,  -560,   398,   397,   401,   402,   403,
     404,   408,   409,   410,   411,   412,   413,   415,   416,     4,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,   399,   417,   418,   419,   420,  -560,
     425,   426,   429,   430,   431,   433,   435,   436,   290,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,   439,   440,    11,  -560,  -560,  -560,
     511,   446,  -560,  -560,   442,   449,  -560,  -560,    12,  -560,
    -560,  -560,   522,   514,   514,   590,   525,   526,   593,   573,
     532,   597,   599,   601,   546,   550,   551,   514,   598,   552,
     624,   627,   514,   628,   630,   610,   636,   637,   572,   575,
     508,   577,   510,   514,   514,   579,   514,   580,   583,   584,
    -105,   -99,   585,   586,   514,   514,   653,   633,   514,   589,
     592,   594,   595,   528,  -560,  -560,  -560,   533,   534,  -560,
     535,   536,    14,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     540,   539,   541,  -560,   543,   545,   547,   548,   549,    33,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     555,  -560,   556,  -560,    22,  -560,  -560,  -560,   553,  -560,
     558,   559,   560,  -560,     8,  -560,  -560,  -560,  -560,  -560,
     596,   554,  -560,   212,  -560,   645,   657,   564,  -560,   565,
     563,   566,  -560,   567,   568,   569,  -560,   570,    15,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   574,   576,
     581,   582,    27,  -560,  -560,  -560,  -560,   608,   614,   632,
     685,   641,   643,   514,   588,  -560,  -560,   692,   648,   699,
     702,   703,   704,   705,   708,   -63,   -49,   710,   711,   730,
     712,   713,   604,  -560,   611,   607,  -560,   612,    97,  -560,
    -560,  -560,  -560,   619,   617,  -560,    30,  -560,  -560,  -560,
     724,   622,  -560,   631,   634,   635,  -560,   654,   656,   660,
     664,   665,   272,   676,   677,   681,   684,   693,   695,   696,
     698,   701,   706,   707,   714,   715,  -560,  -560,   761,   764,
     514,   767,   768,   776,   779,   763,   823,   828,   514,   514,
     653,   716,  -560,  -560,   809,   -75,   812,   770,   700,   818,
     819,   820,   821,   843,   827,   829,   830,   718,  -560,   831,
     832,   723,  -560,   726,  -560,   834,   835,   728,   727,  -560,
     729,   732,   733,   734,   735,   736,   737,   739,   740,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   663,   760,
     697,   762,   765,   766,   769,   771,   772,   773,   774,   775,
     777,   778,   780,   782,   783,   784,    54,   785,   786,   787,
     788,   789,   790,   791,  -560,   792,   514,   793,   794,   871,
     873,   796,  -560,  -560,   874,   833,   795,   877,   844,   880,
     886,   889,   800,  -560,   902,   798,   903,   802,  -560,  -560,
     801,   904,   913,   936,   806,  -560,   807,  -560,   194,   808,
     810,  -560,  -560,   919,   876,   811,   922,   923,   925,   813,
     927,   822,  -560,  -560,   928,   929,   930,   824,  -560,   825,
     826,   836,   837,   838,   839,   840,  -560,   841,   842,   845,
     846,   847,   848,   849,   850,  -560,  -560,  -199,  -560,  -560,
    -560,  -196,  -560,   851,   852,   853,   854,   855,  -560,  -560,
     931,   856,   933,   857,  -560,  -560,   937,   858,   860,  -560,
     862,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     514,   514,   514,   514,   514,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     863,   864,   865,   866,   867,   868,   869,   872,   875,   878,
     879,   881,   882,  -560,   883,   884,   885,   887,   888,   141,
     890,   891,   892,   893,   894,   895,   896,   897,  -560,   898,
     899,  -560,  -560,   900,   901,   934,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -182,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   -30,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   653,   653,   653,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,    13,   905,   906,
      21,   907,   908,  -560,   909,   910,   870,   911,   912,   914,
     915,   916,  -560,   917,   935,   918,  -560,   -47,   920,   921,
     940,   924,  -560,  -560,  -560,   926,   932,  -560,   938,    89,
    -560,  -560,  -560,  -560,  -560,  -560,   939,   942,   479,   943,
     944,   945,   725,   946,  -560,   947,   948,   949,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   -63,  -560,   -49,  -560,  -560,
    -560,  -560,  -560,   950,   507,   951,  -560,   952,   531,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,    -6,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,    65,  -560,  -560,   663,  -560,   697,  -560,
    -560,  -560,  -560,  -560,   100,  -560,  -560,  -560,  -560,  -560,
     101,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,   106,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,   109,  -560,  -560,  -560,  -560,  -560,
     112,  -560,  -560,  -560,   959,   936,   953,  -560,   941,   954,
     -91,   955,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,   123,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   126,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,   133,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   148,  -560,  -560,   141,  -560,   934,  -560,  -560,  -560,
      13,  -560,    21,  -560,   870,  -560,   935,  -560,   -47,  -560,
    -560,  -560,   956,   262,   958,   960,  -560,  -560,   479,  -560,
     725,  -560,   507,  -560,   531,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
     150,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   262,
    -560
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -560,  -560,  -560,  -316,  -319,  -559,  -456,  -560,  -560,   957,
    -560,  -560,  -560,  -560,   799,  -560,  -560,  -560,    18,  -560,
      19,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  1000,  -560,  -560,  -560,
    -560,  -560,   859,  -560,  -560,  -560,  -560,    56,  -560,  -560,
    -560,  -560,  -560,  -224,  -560,  -560,  -560,   561,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -169,  -560,  -560,
    -560,  -166,  -560,  -560,  -560,   781,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -153,  -560,   600,  -560,  -560,  -560,
     -48,  -560,  -560,  -560,  -560,  -560,   629,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -137,  -560,  -560,  -560,  -560,  -560,
    -560,   591,  -560,  -560,  -560,  -560,  -560,   961,  -560,  -560,
    -560,  -560,   557,  -560,  -560,  -560,  -560,  -560,  -138,  -560,
    -560,  -560,   578,  -560,  -560,  -560,  -560,  -130,  -560,  -560,
    -560,   797,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,   -94,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -103,  -560,   661,  -560,  -560,  -560,  -560,
    -560,   804,  -560,  -560,  -560,  -560,  1041,  -560,  -560,  -560,
    -560,  -560,  -560,   -90,  -560,   803,  -560,  -560,  -560,  -560,
     989,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,    52,
    -560,  -560,  -560,    55,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   738,  -560,  -560,  -560,  -560,  -560,   -85,  -560,  -560,
    -560,  -560,  -560,   -88,  -560,  -560,  1075,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,   962,  -560,  -560,
    -560,  -560,  -560,  -560,  -560
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -109
static const yytype_int16 yytable[] =
{
     717,   613,   614,   465,   252,   335,   466,   593,   620,   508,
      70,   121,   393,   403,  1157,   465,   529,   499,   466,   716,
      49,   304,    50,   499,  1122,    54,   336,   337,   548,   243,
     338,   593,  1128,   121,   480,    47,    48,   236,   253,   530,
      71,   467,  1054,    70,   468,  1056,  1055,   304,   549,  1057,
      72,   254,    56,   467,    61,   509,   468,   481,   531,  1115,
      62,   236,   532,  1116,   255,   256,   257,   258,   975,   976,
     977,   708,   709,    71,   510,   269,   482,   710,   711,   511,
     483,   122,   394,    72,   259,   469,   795,   796,   243,    65,
    1015,   339,   340,   341,   671,   672,   342,   469,   584,   393,
     799,   800,   470,   122,   343,   270,   594,    66,   685,    73,
      69,   127,   404,   690,   470,   533,   344,   345,   128,   129,
     305,  1274,   865,   866,   701,   702,   244,   704,   118,   130,
     594,   550,   346,   347,   119,   714,   715,   131,   512,   719,
     534,   271,    73,   132,   395,   405,   305,   133,   134,   500,
     135,  1094,   309,  1095,   245,   500,   136,  1158,   484,   535,
     551,  1159,   348,   120,   716,   137,   138,   485,   486,   394,
     139,   126,   595,   232,   272,   140,   273,   274,   406,   141,
     142,    79,   501,   143,   862,   244,   144,   145,   501,  1016,
     233,  1123,   234,    80,   146,  1015,   595,   585,   584,  1129,
     147,   148,   487,   149,   150,   151,   152,   153,    81,    82,
     235,  1117,   548,   245,    83,  1118,    84,   275,   154,   276,
     277,   278,   279,   250,   536,   251,   155,   156,   157,   471,
     158,   395,   549,   159,   160,  1253,   280,   161,   302,  1254,
     303,   471,   537,   502,   785,   564,   641,   523,   162,   502,
     754,   313,   401,   661,   668,  1017,   731,   771,    85,    86,
     488,   310,   281,   586,   747,    87,    88,   403,   237,   777,
     527,   603,   818,   163,   282,   742,  -108,   164,   521,   311,
     529,   165,   166,   167,   168,   169,    89,    90,   601,   170,
     171,   364,   237,   365,  1016,   312,   366,   585,   519,   172,
    -108,    91,    92,   530,   604,   315,  1255,   316,   283,   284,
    1256,   852,    93,  1293,   367,   550,   582,   317,   524,   860,
     861,    94,   531,   318,   587,   252,   532,   508,  1018,   173,
     174,  1171,   175,   368,  1294,   269,  1295,   369,   176,   813,
     319,  1259,  1261,   177,   551,  1260,  1262,  1263,   178,  1096,
    1265,  1264,   463,  1267,  1266,   320,   370,  1268,   371,   253,
    1017,   321,  1097,   586,  1277,   270,   404,  1279,  1278,   322,
     372,  1280,   254,   509,  1281,   323,   127,  1296,  1282,   533,
     324,   325,   612,   128,   129,   255,   256,   257,   258,  1283,
     373,  1308,   510,  1284,   130,  1309,   326,   511,   327,   405,
     328,   271,   131,   329,   534,   259,   330,   988,   132,    95,
      96,    97,   133,   134,   331,   135,  1119,  1120,  1121,   332,
     374,   136,   333,   535,   587,   830,   831,   832,   833,   834,
     137,   138,   406,  1018,   272,   139,   273,   274,   608,   400,
     140,   566,   412,   413,   141,   142,   414,   415,   143,   375,
     416,   144,   145,  1297,  1298,   758,   512,   417,   418,   146,
     419,   420,   364,   421,   365,   147,   148,   366,   149,   150,
     151,   152,   153,   422,   423,   424,   425,   275,   376,   276,
     277,   278,   279,   154,  1175,   367,   426,   427,   536,  1299,
     428,   155,   156,   157,   429,   158,   280,   430,   159,   160,
     431,   432,   161,   433,   368,   434,   537,   435,   369,   436,
     480,  1176,   437,   162,  1071,  1072,  1073,  1074,  1075,   438,
     439,   441,   281,   605,   377,   443,   444,   370,   445,   371,
    1177,   446,   657,   481,   282,   447,  1178,   448,   163,   449,
     450,   372,   164,   451,   452,    79,   165,   166,   167,   168,
     169,   453,   482,  1179,   170,   171,   483,    80,   454,   455,
     456,   373,   457,   458,   172,   459,   460,   461,   283,   284,
     606,   462,    81,    82,   520,   525,   526,  1180,    83,   557,
      84,  1227,   558,   559,  1181,   560,   561,   562,   563,   567,
     568,   374,   569,   570,   173,   174,   571,   175,  1182,   572,
     573,   574,   575,   176,   576,  1241,   577,   578,   177,   579,
     580,   581,   600,   178,   607,   609,  1183,   610,  1184,  1185,
     375,   611,    85,    86,   612,   615,   616,   617,   618,    87,
      88,   619,   621,   622,   484,   623,   624,   626,   625,   627,
     643,   628,   663,   485,   486,   629,   630,   631,   632,   376,
      89,    90,   633,   634,   635,   636,   637,   638,  1228,   639,
     640,   644,   645,   646,   647,    91,    92,     2,     3,   649,
     650,  1186,     4,   651,   652,   653,    93,   654,   487,   655,
     656,  1187,  1242,   659,   660,    94,   665,   664,     5,  1229,
    1188,     6,     7,   666,  1189,   377,  1190,     8,   670,  1230,
     673,   674,   675,   676,   677,  1191,  1231,   679,   678,   680,
     335,   681,     9,  1243,  1275,  1192,    10,    11,  1232,    12,
    1233,  1234,   682,  1244,   915,    13,   683,   684,   687,   686,
    1245,   336,   337,  1235,   688,   338,   488,   689,   691,    14,
     692,   693,  1246,  1236,  1247,  1248,   694,   695,   696,    15,
      16,   697,   698,   699,   700,   703,   705,  1249,   938,   706,
     707,   712,   713,   716,   718,   720,    17,  1250,   721,   724,
     722,   723,   756,    95,    96,    97,   759,   726,   727,   729,
     730,   733,    18,   734,   779,   735,  1198,   737,   760,   738,
     780,   739,   740,   741,   749,   757,   339,   340,   341,   744,
     746,   342,   751,   752,   753,   761,   762,   763,   781,   343,
     764,   766,   767,   768,   770,   773,   782,   783,    19,   784,
     774,   344,   345,   787,   788,   775,   776,    20,    21,   786,
     789,    22,    23,   790,   791,   792,   793,   346,   347,   794,
     805,   803,   804,   806,   807,   808,   916,   917,   918,   919,
     920,   810,   809,   921,   922,   820,   812,   923,   924,   925,
     815,   816,   926,   821,   927,   928,   929,   348,   930,   931,
     932,   850,   822,   933,   851,   823,   824,   853,   854,   934,
     939,   940,   941,   942,   943,    24,   855,   944,   945,   856,
    1136,   946,   947,   948,   857,   825,   949,   826,   950,   951,
     952,   827,   953,   954,   955,   828,   829,   956,  1199,  1200,
    1201,  1202,  1203,   957,  1137,  1204,  1205,   837,   838,  1206,
    1207,  1208,   839,  1138,  1209,   840,  1210,  1211,  1212,  1139,
    1213,  1214,  1215,   858,   841,  1216,   842,   843,   859,   844,
     864,  1217,   845,   867,   869,  1140,   868,   846,   847,   870,
     871,   872,   873,   874,   998,   848,   849,   863,   875,   878,
     876,   877,   879,   880,   881,   883,   884,   882,   886,   989,
     887,  1141,   885,   888,   889,   890,   891,   892,   893,  1142,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,   912,   913,
     914,   937,   991,   960,   992,   994,   961,   962,   997,   995,
     963,   999,   964,   965,   966,   967,   968,  1000,   969,   970,
    1001,   971,  1143,   972,   973,   974,   980,   981,   982,   983,
     984,   985,   986,  1003,  1005,  1008,   987,   993,   990,   996,
    1144,  1002,  1004,  1006,  1009,  1007,  1010,  1013,  1014,  1024,
    1026,  1025,  1027,  1029,  1030,  1028,  1031,  1032,  1033,  1035,
    1036,  1037,  1063,  1034,  1065,  1038,  1039,  1040,  1067,  1269,
    1112,  1153,  1272,  1224,   314,  1172,  1225,  1041,  1042,  1043,
    1044,  1045,  1046,  1047,   583,  1310,  1048,  1049,  1050,  1051,
    1052,  1053,  1058,  1059,  1060,  1061,  1062,   522,  1066,   772,
    1064,  1069,  1068,  1070,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1305,  1304,  1083,   755,  1291,  1084,  1270,   743,  1085,
    1086,  1164,  1087,  1088,  1089,  1090,  1091,  1289,  1092,  1093,
     642,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,   778,  1306,   814,  1126,  1127,  1132,  1133,
    1134,  1135,  1147,  1148,  1307,  1149,  1150,  1151,  1152,  1156,
    1285,  1162,  1163,  1290,   402,   748,  1286,  1167,   464,  1165,
    1258,  1257,  1287,   334,   819,   658,  1168,  1288,     0,     0,
    1173,     0,  1170,  1174,  1195,  1196,  1197,  1220,  1221,  1222,
    1223,  1226,  1239,  1240,  1271,     0,  1276,  1292,  1273,  1302,
     662,  1303,     0,   528,     0,     0,     0,     0,     0,     0,
     732,   669,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   602
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-560))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     456,   320,   321,     1,     1,     1,     4,     1,   327,     1,
       1,     1,     1,     1,    61,     1,     1,     1,     4,   110,
     243,     1,   243,     1,    11,   243,    22,    23,     1,     1,
      26,     1,    11,     1,     1,   241,   242,     1,    35,    24,
      31,    39,   241,     1,    42,   241,   245,     1,    21,   245,
      41,    48,   243,    39,   243,    47,    42,    24,    43,   241,
     243,     1,    47,   245,    61,    62,    63,    64,    14,    15,
      16,   176,   177,    31,    66,     1,    43,   176,   177,    71,
      47,    71,    71,    41,    81,    83,   149,   150,     1,   243,
       1,    87,    88,    89,   413,   414,    92,    83,     1,     1,
     149,   150,   100,    71,   100,    31,   100,   243,   427,   100,
     243,     1,   100,   432,   100,   100,   112,   113,     8,     9,
     100,   212,   197,   198,   443,   444,    98,   446,   243,    19,
     100,   104,   128,   129,   243,   454,   455,    27,   130,   458,
     125,    67,   100,    33,   133,   133,   100,    37,    38,   133,
      40,    10,   241,    12,   126,   133,    46,   204,   125,   144,
     133,   208,   158,   243,   110,    55,    56,   134,   135,    71,
      60,   243,   166,   243,   100,    65,   102,   103,   166,    69,
      70,     1,   166,    73,   640,    98,    76,    77,   166,   100,
     243,   178,   243,    13,    84,     1,   166,   100,     1,   178,
      90,    91,   169,    93,    94,    95,    96,    97,    28,    29,
     243,   241,     1,   126,    34,   245,    36,   143,   108,   145,
     146,   147,   148,   243,   209,   243,   116,   117,   118,   227,
     120,   133,    21,   123,   124,   241,   162,   127,   243,   245,
     243,   227,   227,   227,   563,   242,   242,   240,   138,   227,
     242,   242,   242,   242,   242,   166,   242,   242,    78,    79,
     227,   244,   188,   166,   242,    85,    86,     1,   232,   242,
     242,   131,   242,   163,   200,   242,   240,   167,   242,   244,
       1,   171,   172,   173,   174,   175,   106,   107,   242,   179,
     180,     1,   232,     3,   100,   244,     6,   100,   241,   189,
     240,   121,   122,    24,   131,   244,   241,   244,   234,   235,
     245,   630,   132,    51,    24,   104,   242,   244,   241,   638,
     639,   141,    43,   244,   227,     1,    47,     1,   239,   219,
     220,   242,   222,    43,    72,     1,    74,    47,   228,   242,
     244,   241,   241,   233,   133,   245,   245,   241,   238,   208,
     241,   245,   242,   241,   245,   244,    66,   245,    68,    35,
     166,   244,   221,   166,   241,    31,   100,   241,   245,   244,
      80,   245,    48,    47,   241,   244,     1,   115,   245,   100,
     244,   244,   110,     8,     9,    61,    62,    63,    64,   241,
     100,   241,    66,   245,    19,   245,   244,    71,   244,   133,
     244,    67,    27,   244,   125,    81,   244,   726,    33,   229,
     230,   231,    37,    38,   244,    40,   975,   976,   977,   244,
     130,    46,   242,   144,   227,   153,   154,   155,   156,   157,
      55,    56,   166,   239,   100,    60,   102,   103,   110,   244,
      65,   241,   244,   244,    69,    70,   244,   244,    73,   159,
     244,    76,    77,   191,   192,   243,   130,   244,   244,    84,
     244,   244,     1,   244,     3,    90,    91,     6,    93,    94,
      95,    96,    97,   244,   244,   244,   244,   143,   188,   145,
     146,   147,   148,   108,     5,    24,   244,   244,   209,   227,
     244,   116,   117,   118,   244,   120,   162,   244,   123,   124,
     244,   244,   127,   244,    43,   244,   227,   244,    47,   244,
       1,    32,   244,   138,   830,   831,   832,   833,   834,   244,
     244,   244,   188,   131,   234,   244,   244,    66,   244,    68,
      51,   244,   242,    24,   200,   244,    57,   244,   163,   244,
     244,    80,   167,   244,   244,     1,   171,   172,   173,   174,
     175,   244,    43,    74,   179,   180,    47,    13,   244,   244,
     244,   100,   244,   244,   189,   244,   244,   244,   234,   235,
     241,   244,    28,    29,   244,   244,   244,    98,    34,   244,
      36,    74,   244,   244,   105,   244,   244,   244,   244,   244,
     244,   130,   244,   244,   219,   220,   244,   222,   119,   244,
     244,   244,   244,   228,   244,    74,   244,   244,   233,   244,
     244,   244,   244,   238,   176,   110,   137,   176,   139,   140,
     159,   176,    78,    79,   110,   110,   110,   176,   176,    85,
      86,   110,   176,   176,   125,   176,   176,   241,   176,   241,
     241,   244,   131,   134,   135,   244,   244,   244,   244,   188,
     106,   107,   244,   244,   244,   244,   244,   244,   151,   244,
     244,   244,   244,   244,   244,   121,   122,     0,     1,   244,
     244,   192,     5,   244,   244,   244,   132,   244,   169,   244,
     244,   202,   151,   244,   244,   141,   244,   241,    21,   182,
     211,    24,    25,   244,   215,   234,   217,    30,   176,   192,
     110,   176,   176,   110,   131,   226,   199,   110,   176,   110,
       1,   110,    45,   182,  1170,   236,    49,    50,   211,    52,
     213,   214,   176,   192,    61,    58,   176,   176,   176,   131,
     199,    22,    23,   226,   110,    26,   227,   110,   110,    72,
     110,   131,   211,   236,   213,   214,   110,   110,   176,    82,
      83,   176,   244,   176,   244,   176,   176,   226,    61,   176,
     176,   176,   176,   110,   131,   176,    99,   236,   176,   241,
     176,   176,   176,   229,   230,   231,   131,   244,   244,   244,
     244,   241,   115,   244,   176,   244,    61,   244,   131,   244,
     176,   244,   244,   244,   241,   241,    87,    88,    89,   244,
     244,    92,   244,   244,   244,   241,   241,   244,   176,   100,
     244,   244,   244,   244,   244,   241,   131,   176,   151,   176,
     244,   112,   113,   131,   176,   244,   244,   160,   161,   241,
     131,   164,   165,   131,   131,   131,   131,   128,   129,   131,
     110,   131,   131,   131,   131,   241,   183,   184,   185,   186,
     187,   244,   241,   190,   191,   131,   244,   194,   195,   196,
     241,   244,   199,   241,   201,   202,   203,   158,   205,   206,
     207,   110,   241,   210,   110,   241,   241,   110,   110,   216,
     183,   184,   185,   186,   187,   218,   110,   190,   191,   110,
      20,   194,   195,   196,   131,   241,   199,   241,   201,   202,
     203,   241,   205,   206,   207,   241,   241,   210,   183,   184,
     185,   186,   187,   216,    44,   190,   191,   241,   241,   194,
     195,   196,   241,    53,   199,   241,   201,   202,   203,    59,
     205,   206,   207,   110,   241,   210,   241,   241,   110,   241,
     131,   216,   241,   131,   244,    75,   176,   241,   241,   131,
     131,   131,   131,   110,   110,   241,   241,   241,   131,   241,
     131,   131,   131,   131,   241,   131,   131,   241,   241,   176,
     241,   101,   244,   241,   241,   241,   241,   241,   241,   109,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   131,   241,   131,   131,   241,   241,   131,   176,
     241,   131,   241,   241,   241,   241,   241,   131,   241,   241,
     131,   241,   152,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   131,   131,   131,   244,   241,   244,   244,
     170,   241,   244,   241,   131,   244,   110,   241,   241,   241,
     131,   241,   176,   131,   131,   244,   131,   244,   131,   131,
     131,   131,   131,   241,   131,   241,   241,   241,   131,   110,
     136,   136,   131,  1055,    74,  1019,  1057,   241,   241,   241,
     241,   241,   241,   241,   285,  1309,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   238,   241,   538,
     244,   241,   244,   241,   241,   241,   241,   241,   241,   241,
     241,  1280,  1278,   241,   514,  1268,   241,  1165,   489,   241,
     241,   181,   241,   241,   241,   241,   241,  1264,   241,   241,
     349,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   552,  1282,   588,   241,   241,   241,   241,
     241,   241,   241,   241,  1284,   241,   241,   241,   241,   241,
    1254,   241,   241,  1266,   123,   504,  1256,   241,   179,   245,
    1118,  1116,  1260,    98,   596,   378,   244,  1262,    -1,    -1,
     241,    -1,   244,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,    -1,   241,   241,   244,   241,
     396,   241,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
     472,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   247,     0,     1,     5,    21,    24,    25,    30,    45,
      49,    50,    52,    58,    72,    82,    83,    99,   115,   151,
     160,   161,   164,   165,   218,   248,   253,   258,   280,   286,
     300,   318,   335,   349,   364,   371,   375,   385,   394,   414,
     424,   430,   434,   444,   504,   520,   541,   241,   242,   243,
     243,   319,   395,   425,   243,   435,   243,   505,   350,   415,
     336,   243,   243,   301,   365,   243,   243,   376,   386,   243,
       1,    31,    41,   100,   281,   282,   283,   284,   285,     1,
      13,    28,    29,    34,    36,    78,    79,    85,    86,   106,
     107,   121,   122,   132,   141,   229,   230,   231,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   243,   243,
     243,     1,    71,   431,   432,   433,   243,     1,     8,     9,
      19,    27,    33,    37,    38,    40,    46,    55,    56,    60,
      65,    69,    70,    73,    76,    77,    84,    90,    91,    93,
      94,    95,    96,    97,   108,   116,   117,   118,   120,   123,
     124,   127,   138,   163,   167,   171,   172,   173,   174,   175,
     179,   180,   189,   219,   220,   222,   228,   233,   238,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   496,   500,   501,
     502,   503,   243,   243,   243,   243,     1,   232,   287,   288,
     289,   290,   291,     1,    98,   126,   254,   255,   256,   257,
     243,   243,     1,    35,    48,    61,    62,    63,    64,    81,
     542,   543,   544,   545,   546,   547,   548,   549,   550,     1,
      31,    67,   100,   102,   103,   143,   145,   146,   147,   148,
     162,   188,   200,   234,   235,   259,   260,   261,   262,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   243,   243,     1,   100,   372,   373,   374,   241,
     244,   244,   244,   242,   282,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   242,   522,     1,    22,    23,    26,    87,
      88,    89,    92,   100,   112,   113,   128,   129,   158,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,     1,     3,     6,    24,    43,    47,
      66,    68,    80,   100,   130,   159,   188,   234,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   409,   410,
     411,   412,   413,     1,    71,   133,   426,   427,   428,   429,
     244,   242,   432,     1,   100,   133,   166,   436,   440,   441,
     442,   443,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     497,   244,   493,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   242,   446,     1,     4,    39,    42,    83,
     100,   227,   506,   507,   508,   509,   510,   514,   515,   516,
       1,    24,    43,    47,   125,   134,   135,   169,   227,   351,
     352,   353,   354,   355,   356,   357,   361,   362,   363,     1,
     133,   166,   227,   416,   420,   421,   422,   423,     1,    47,
      66,    71,   130,   337,   341,   342,   343,   347,   348,   241,
     244,   242,   288,   240,   241,   244,   244,   242,   255,     1,
      24,    43,    47,   100,   125,   144,   209,   227,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   314,     1,    21,
     104,   133,   366,   367,   368,   369,   370,   244,   244,   244,
     244,   244,   244,   244,   242,   543,   241,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   242,   260,     1,   100,   166,   227,   377,   378,
     379,   380,   381,     1,   100,   166,   387,   388,   389,   390,
     244,   242,   373,   131,   131,   131,   241,   176,   110,   110,
     176,   176,   110,   250,   250,   110,   110,   176,   176,   110,
     250,   176,   176,   176,   176,   176,   241,   241,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   242,   321,   241,   244,   244,   244,   244,   406,   244,
     244,   244,   244,   244,   244,   244,   244,   242,   397,   244,
     244,   242,   427,   131,   241,   244,   244,   437,   242,   441,
     176,   250,   250,   110,   176,   176,   110,   131,   176,   110,
     110,   110,   176,   176,   176,   250,   131,   176,   110,   110,
     250,   110,   110,   131,   110,   110,   176,   176,   244,   176,
     244,   250,   250,   176,   250,   176,   176,   176,   176,   177,
     176,   177,   176,   176,   250,   250,   110,   252,   131,   250,
     176,   176,   176,   176,   241,   517,   244,   244,   511,   244,
     244,   242,   507,   241,   244,   244,   358,   244,   244,   244,
     244,   244,   242,   352,   244,   417,   244,   242,   421,   241,
     338,   244,   244,   244,   242,   342,   176,   241,   243,   131,
     131,   241,   241,   244,   244,   315,   244,   244,   244,   311,
     244,   242,   303,   241,   244,   244,   244,   242,   367,   176,
     176,   176,   131,   176,   176,   250,   241,   131,   176,   131,
     131,   131,   131,   131,   131,   149,   150,   263,   264,   149,
     150,   265,   266,   131,   131,   110,   131,   131,   241,   241,
     244,   382,   244,   242,   378,   241,   244,   391,   242,   388,
     131,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     153,   154,   155,   156,   157,   249,   250,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     110,   110,   250,   110,   110,   110,   110,   131,   110,   110,
     250,   250,   252,   241,   131,   197,   198,   131,   176,   244,
     131,   131,   131,   131,   110,   131,   131,   131,   241,   131,
     131,   241,   241,   131,   131,   244,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,    61,   183,   184,   185,   186,
     187,   190,   191,   194,   195,   196,   199,   201,   202,   203,
     205,   206,   207,   210,   216,   498,   499,   241,    61,   183,
     184,   185,   186,   187,   190,   191,   194,   195,   196,   199,
     201,   202,   203,   205,   206,   207,   210,   216,   494,   495,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,    14,    15,    16,   251,   252,
     241,   241,   241,   241,   241,   241,   241,   244,   250,   176,
     244,   131,   131,   241,   131,   176,   244,   131,   110,   131,
     131,   131,   241,   131,   244,   131,   241,   244,   131,   131,
     110,   345,   346,   241,   241,     1,   100,   166,   239,   292,
     293,   294,   295,   296,   241,   241,   131,   176,   244,   131,
     131,   131,   244,   131,   241,   131,   131,   131,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   245,   241,   245,   241,   241,
     241,   241,   241,   131,   244,   131,   241,   131,   244,   241,
     241,   249,   249,   249,   249,   249,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,    10,    12,   208,   221,   407,   408,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   136,   438,   439,   241,   245,   241,   245,   251,
     251,   251,    11,   178,   518,   519,   241,   241,    11,   178,
     512,   513,   241,   241,   241,   241,    20,    44,    53,    59,
      75,   101,   109,   152,   170,   359,   360,   241,   241,   241,
     241,   241,   241,   136,   418,   419,   241,    61,   204,   208,
     339,   340,   241,   241,   181,   245,   344,   241,   244,   297,
     244,   242,   293,   241,   241,     5,    32,    51,    57,    74,
      98,   105,   119,   137,   139,   140,   192,   202,   211,   215,
     217,   226,   236,   316,   317,   241,   241,   241,    61,   183,
     184,   185,   186,   187,   190,   191,   194,   195,   196,   199,
     201,   202,   203,   205,   206,   207,   210,   216,   312,   313,
     241,   241,   241,   241,   264,   266,   241,    74,   151,   182,
     192,   199,   211,   213,   214,   226,   236,   383,   384,   241,
     241,    74,   151,   182,   192,   199,   211,   213,   214,   226,
     236,   392,   393,   241,   245,   241,   245,   499,   495,   241,
     245,   241,   245,   241,   245,   241,   245,   241,   245,   110,
     346,   241,   131,   244,   212,   252,   241,   241,   245,   241,
     245,   241,   245,   241,   245,   408,   439,   519,   513,   360,
     419,   340,   241,    51,    72,    74,   115,   191,   192,   227,
     298,   299,   241,   241,   317,   313,   384,   393,   241,   245,
     299
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
#line 409 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 411 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 415 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 419 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 423 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 427 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 431 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 437 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 438 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 439 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 440 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 485 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 491 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 500 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 506 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 514 "conf_parser.y"
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
#line 553 "conf_parser.y"
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
#line 612 "conf_parser.y"
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
        if (DH_size(dh) < 128)
          ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
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
#line 640 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 648 "conf_parser.y"
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
#line 663 "conf_parser.y"
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
#line 678 "conf_parser.y"
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
#line 687 "conf_parser.y"
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
#line 701 "conf_parser.y"
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
#line 710 "conf_parser.y"
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
#line 738 "conf_parser.y"
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
#line 768 "conf_parser.y"
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
#line 791 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 806 "conf_parser.y"
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
#line 815 "conf_parser.y"
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
#line 824 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 848 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 865 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 870 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 873 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 889 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 897 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 919 "conf_parser.y"
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

  case 131:

/* Line 1806 of yacc.c  */
#line 932 "conf_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1022 "conf_parser.y"
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1034 "conf_parser.y"
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

  case 145:

/* Line 1806 of yacc.c  */
#line 1071 "conf_parser.y"
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

  case 146:

/* Line 1806 of yacc.c  */
#line 1083 "conf_parser.y"
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

  case 147:

/* Line 1806 of yacc.c  */
#line 1094 "conf_parser.y"
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

  case 148:

/* Line 1806 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1281 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1285 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1289 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1293 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1297 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1301 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1309 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1319 "conf_parser.y"
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
#line 1326 "conf_parser.y"
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

  case 213:

/* Line 1806 of yacc.c  */
#line 1384 "conf_parser.y"
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
#line 1393 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1399 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1411 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1423 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1447 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1468 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1475 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1484 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1490 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1494 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1498 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1508 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1513 "conf_parser.y"
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

  case 247:

/* Line 1806 of yacc.c  */
#line 1527 "conf_parser.y"
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

  case 248:

/* Line 1806 of yacc.c  */
#line 1547 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1556 "conf_parser.y"
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
#line 1568 "conf_parser.y"
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

  case 251:

/* Line 1806 of yacc.c  */
#line 1580 "conf_parser.y"
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

  case 263:

/* Line 1806 of yacc.c  */
#line 1642 "conf_parser.y"
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

  case 264:

/* Line 1806 of yacc.c  */
#line 1679 "conf_parser.y"
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

  case 265:

/* Line 1806 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1701 "conf_parser.y"
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

  case 267:

/* Line 1806 of yacc.c  */
#line 1712 "conf_parser.y"
    {
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1717 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1721 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1725 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1729 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1733 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1737 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1741 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1749 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1756 "conf_parser.y"
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

  case 281:

/* Line 1806 of yacc.c  */
#line 1775 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1785 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1798 "conf_parser.y"
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
#line 1805 "conf_parser.y"
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
#line 1817 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1826 "conf_parser.y"
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

  case 293:

/* Line 1806 of yacc.c  */
#line 1841 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1859 "conf_parser.y"
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

  case 300:

/* Line 1806 of yacc.c  */
#line 1874 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1902 "conf_parser.y"
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

  case 310:

/* Line 1806 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1951 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1955 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1959 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1963 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 2002 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2013 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2017 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2025 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2029 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2033 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2037 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2041 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2045 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2054 "conf_parser.y"
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

  case 347:

/* Line 1806 of yacc.c  */
#line 2069 "conf_parser.y"
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

  case 364:

/* Line 1806 of yacc.c  */
#line 2191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 2209 "conf_parser.y"
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

  case 367:

/* Line 1806 of yacc.c  */
#line 2235 "conf_parser.y"
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

  case 368:

/* Line 1806 of yacc.c  */
#line 2253 "conf_parser.y"
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

  case 369:

/* Line 1806 of yacc.c  */
#line 2271 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 2281 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2289 "conf_parser.y"
    {
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2294 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2312 "conf_parser.y"
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

  case 381:

/* Line 1806 of yacc.c  */
#line 2323 "conf_parser.y"
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

  case 382:

/* Line 1806 of yacc.c  */
#line 2336 "conf_parser.y"
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

  case 383:

/* Line 1806 of yacc.c  */
#line 2349 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2358 "conf_parser.y"
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

  case 385:

/* Line 1806 of yacc.c  */
#line 2376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2383 "conf_parser.y"
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
        find_and_delete_temporary(userbuf, hostbuf, CONF_KLINE);

        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KLINE, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2441 "conf_parser.y"
    {
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2455 "conf_parser.y"
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

  case 399:

/* Line 1806 of yacc.c  */
#line 2474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 2483 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      find_and_delete_temporary(NULL, hostbuf, CONF_DLINE);

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

  case 407:

/* Line 1806 of yacc.c  */
#line 2511 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 2517 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:

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

  case 415:

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

  case 416:

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

  case 417:

/* Line 1806 of yacc.c  */
#line 2596 "conf_parser.y"
    {
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:

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

  case 504:

/* Line 1806 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 505:

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

  case 506:

/* Line 1806 of yacc.c  */
#line 2776 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2812 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2827 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2832 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 523:

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

  case 524:

/* Line 1806 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 527:

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

  case 528:

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

  case 529:

/* Line 1806 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2943 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2955 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2958 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2964 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2970 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2973 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2979 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2984 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 2990 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2993 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3005 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3011 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3017 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3023 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3026 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3032 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3038 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3041 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3044 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3047 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3052 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3057 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3062 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3067 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

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

  case 585:

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

  case 595:

/* Line 1806 of yacc.c  */
#line 3109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 603:

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

  case 604:

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

  case 605:

/* Line 1806 of yacc.c  */
#line 3180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 606:

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

  case 609:

/* Line 1806 of yacc.c  */
#line 3231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 3235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 3259 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3264 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3269 "conf_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3274 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3279 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3284 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3289 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3294 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3299 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3304 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3309 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3314 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3319 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3324 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3329 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3334 "conf_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3339 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3344 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 664:

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

  case 665:

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

  case 666:

/* Line 1806 of yacc.c  */
#line 3398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7691 "conf_parser.c"
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



