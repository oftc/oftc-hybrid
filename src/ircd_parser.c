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
     T_UNLIMITED = 471,
     T_UNRESV = 472,
     T_UNXLINE = 473,
     T_GLOBOPS = 474,
     T_WALLOP = 475,
     T_RESTART = 476,
     T_SERVICE = 477,
     T_SERVICES_NAME = 478,
     T_TIMESTAMP = 479,
     THROTTLE_TIME = 480,
     TOPICBURST = 481,
     TRUE_NO_OPER_FLOOD = 482,
     TKLINE = 483,
     TXLINE = 484,
     TRESV = 485,
     UNKLINE = 486,
     USER = 487,
     USE_EGD = 488,
     USE_EXCEPT = 489,
     USE_INVEX = 490,
     USE_KNOCK = 491,
     USE_LOGGING = 492,
     USE_WHOIS_ACTUALLY = 493,
     VHOST = 494,
     VHOST6 = 495,
     XLINE = 496,
     WARN = 497,
     WARN_NO_NLINE = 498,
     T_SIZE = 499,
     T_FILE = 500
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
#define T_UNLIMITED 471
#define T_UNRESV 472
#define T_UNXLINE 473
#define T_GLOBOPS 474
#define T_WALLOP 475
#define T_RESTART 476
#define T_SERVICE 477
#define T_SERVICES_NAME 478
#define T_TIMESTAMP 479
#define THROTTLE_TIME 480
#define TOPICBURST 481
#define TRUE_NO_OPER_FLOOD 482
#define TKLINE 483
#define TXLINE 484
#define TRESV 485
#define UNKLINE 486
#define USER 487
#define USE_EGD 488
#define USE_EXCEPT 489
#define USE_INVEX 490
#define USE_KNOCK 491
#define USE_LOGGING 492
#define USE_WHOIS_ACTUALLY 493
#define VHOST 494
#define VHOST6 495
#define XLINE 496
#define WARN 497
#define WARN_NO_NLINE 498
#define T_SIZE 499
#define T_FILE 500




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 712 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 724 "ircd_parser.c"

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
#define YYLAST   1233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  312
/* YYNRULES -- Number of rules.  */
#define YYNRULES  678
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1326

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   500

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   250,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   246,
       2,   249,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   248,     2,   247,     2,     2,     2,     2,
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
     245
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
     360,   362,   364,   366,   367,   375,   376,   378,   381,   383,
     385,   387,   389,   391,   393,   395,   397,   399,   402,   407,
     409,   414,   419,   424,   429,   434,   435,   441,   445,   447,
     449,   451,   453,   455,   457,   459,   461,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   481,   483,   485,   486,
     492,   496,   498,   500,   502,   504,   506,   508,   510,   512,
     514,   516,   518,   520,   522,   524,   526,   528,   530,   532,
     534,   535,   543,   544,   546,   549,   551,   553,   555,   557,
     559,   561,   563,   565,   567,   569,   571,   573,   575,   577,
     580,   585,   587,   592,   597,   602,   607,   612,   617,   622,
     627,   632,   637,   642,   647,   648,   655,   656,   662,   666,
     668,   670,   672,   674,   677,   679,   681,   683,   685,   687,
     690,   691,   697,   701,   703,   705,   709,   714,   719,   720,
     727,   730,   732,   734,   736,   738,   740,   742,   744,   746,
     748,   751,   756,   761,   766,   771,   772,   778,   782,   784,
     786,   788,   790,   792,   794,   796,   798,   800,   802,   807,
     812,   817,   818,   825,   828,   830,   832,   834,   836,   839,
     844,   849,   854,   860,   863,   865,   867,   869,   874,   875,
     882,   885,   887,   889,   891,   893,   896,   901,   906,   907,
     913,   917,   919,   921,   923,   925,   927,   929,   931,   933,
     935,   937,   939,   941,   942,   949,   952,   954,   956,   958,
     961,   966,   967,   973,   977,   979,   981,   983,   985,   987,
     989,   991,   993,   995,   997,   999,  1001,  1002,  1010,  1011,
    1013,  1016,  1018,  1020,  1022,  1024,  1026,  1028,  1030,  1032,
    1034,  1036,  1038,  1040,  1042,  1044,  1046,  1049,  1054,  1056,
    1061,  1066,  1071,  1076,  1081,  1086,  1091,  1092,  1098,  1102,
    1104,  1106,  1108,  1110,  1112,  1114,  1119,  1124,  1129,  1134,
    1139,  1144,  1145,  1152,  1153,  1159,  1163,  1165,  1167,  1170,
    1172,  1174,  1176,  1178,  1180,  1185,  1190,  1191,  1198,  1201,
    1203,  1205,  1207,  1209,  1214,  1219,  1225,  1228,  1230,  1232,
    1234,  1239,  1240,  1247,  1248,  1254,  1258,  1260,  1262,  1265,
    1267,  1269,  1271,  1273,  1275,  1280,  1285,  1291,  1294,  1296,
    1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,
    1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,
    1338,  1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,
    1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,
    1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,  1396,
    1398,  1400,  1402,  1404,  1406,  1411,  1416,  1421,  1426,  1431,
    1436,  1441,  1446,  1451,  1456,  1461,  1466,  1471,  1476,  1481,
    1486,  1491,  1496,  1501,  1506,  1511,  1516,  1521,  1526,  1531,
    1536,  1541,  1546,  1551,  1556,  1561,  1566,  1571,  1576,  1581,
    1586,  1591,  1596,  1601,  1606,  1611,  1616,  1621,  1626,  1631,
    1636,  1641,  1646,  1651,  1656,  1657,  1663,  1667,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,
    1693,  1695,  1697,  1699,  1701,  1703,  1705,  1707,  1708,  1714,
    1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,
    1738,  1740,  1742,  1744,  1746,  1748,  1750,  1752,  1754,  1756,
    1758,  1763,  1768,  1773,  1778,  1779,  1786,  1789,  1791,  1793,
    1795,  1797,  1799,  1801,  1803,  1805,  1810,  1815,  1816,  1822,
    1826,  1828,  1830,  1832,  1837,  1842,  1843,  1849,  1853,  1855,
    1857,  1859,  1865,  1868,  1870,  1872,  1874,  1876,  1878,  1880,
    1882,  1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,  1900,
    1902,  1904,  1906,  1908,  1913,  1918,  1923,  1928,  1933,  1938,
    1943,  1948,  1953,  1958,  1963,  1968,  1973,  1978,  1983,  1988,
    1993,  1998,  2004,  2007,  2009,  2011,  2013,  2015,  2017,  2019,
    2021,  2023,  2025,  2030,  2035,  2040,  2045,  2050,  2055
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     252,     0,    -1,    -1,   252,   253,    -1,   281,    -1,   287,
      -1,   302,    -1,   532,    -1,   322,    -1,   341,    -1,   355,
      -1,   263,    -1,   553,    -1,   370,    -1,   377,    -1,   381,
      -1,   391,    -1,   400,    -1,   423,    -1,   433,    -1,   439,
      -1,   453,    -1,   516,    -1,   443,    -1,   258,    -1,     1,
     246,    -1,     1,   247,    -1,    -1,   255,    -1,   117,   254,
      -1,   117,   158,   254,    -1,   117,   159,   254,    -1,   117,
     160,   254,    -1,   117,   161,   254,    -1,   117,   162,   254,
      -1,    -1,   257,    -1,   117,   256,    -1,   117,    14,   256,
      -1,   117,    15,   256,    -1,   117,    16,   256,    -1,   106,
     248,   259,   247,   246,    -1,   259,   260,    -1,   260,    -1,
     261,    -1,   262,    -1,     1,   246,    -1,   105,   249,   138,
     246,    -1,   133,   249,   138,   246,    -1,   166,   248,   264,
     247,   246,    -1,   264,   265,    -1,   265,    -1,   272,    -1,
     277,    -1,   280,    -1,   274,    -1,   275,    -1,   276,    -1,
     279,    -1,   271,    -1,   278,    -1,   273,    -1,   270,    -1,
     266,    -1,     1,   246,    -1,    -1,   153,   267,   249,   268,
     246,    -1,   268,   250,   269,    -1,   269,    -1,   154,    -1,
     155,    -1,   152,   249,   138,   246,    -1,   150,   249,   138,
     246,    -1,   107,   249,   138,   246,    -1,   168,   249,   138,
     246,    -1,    36,   249,   138,   246,    -1,   110,   249,   138,
     246,    -1,   109,   249,   138,   246,    -1,   239,   249,   138,
     246,    -1,   240,   249,   138,   246,    -1,   205,   249,   117,
     246,    -1,    74,   249,   182,   246,    -1,     5,   248,   282,
     247,   246,    -1,   282,   283,    -1,   283,    -1,   284,    -1,
     286,    -1,   285,    -1,     1,   246,    -1,   107,   249,   138,
     246,    -1,    46,   249,   138,   246,    -1,    36,   249,   138,
     246,    -1,    90,   248,   288,   247,   246,    -1,   288,   289,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,     1,
     246,    -1,   237,   249,   182,   246,    -1,   224,   249,   182,
     246,    -1,    -1,   293,   245,   248,   294,   247,   246,    -1,
     294,   295,    -1,   295,    -1,   296,    -1,   298,    -1,   297,
      -1,     1,   246,    -1,   107,   249,   138,   246,    -1,   244,
     249,   257,   246,    -1,   244,   249,   216,   246,    -1,    -1,
     172,   299,   249,   300,   246,    -1,   300,   250,   301,    -1,
     301,    -1,   232,    -1,   122,    -1,    56,    -1,   197,    -1,
      81,    -1,    79,    -1,   196,    -1,    -1,   122,   303,   304,
     248,   305,   247,   246,    -1,    -1,   308,    -1,   305,   306,
      -1,   306,    -1,   307,    -1,   309,    -1,   310,    -1,   314,
      -1,   313,    -1,   311,    -1,   312,    -1,   318,    -1,     1,
     246,    -1,   107,   249,   138,   246,    -1,   138,    -1,   232,
     249,   138,   246,    -1,   132,   249,   138,   246,    -1,    48,
     249,   182,   246,    -1,   151,   249,   138,   246,    -1,    25,
     249,   138,   246,    -1,    -1,   214,   315,   249,   316,   246,
      -1,   316,   250,   317,    -1,   317,    -1,   189,    -1,   192,
      -1,   193,    -1,   195,    -1,   196,    -1,   200,    -1,   211,
      -1,   206,    -1,   208,    -1,   215,    -1,   212,    -1,   199,
      -1,   207,    -1,   210,    -1,   201,    -1,   220,    -1,   190,
      -1,   191,    -1,   204,    -1,    -1,    52,   319,   249,   320,
     246,    -1,   320,   250,   321,    -1,   321,    -1,    62,    -1,
     146,    -1,    81,    -1,   231,    -1,   241,    -1,    56,    -1,
      37,    -1,   221,    -1,   144,    -1,     5,    -1,    67,    -1,
     112,    -1,   207,    -1,   219,    -1,   126,    -1,    69,    -1,
     147,    -1,   105,    -1,    -1,    25,   323,   324,   248,   325,
     247,   246,    -1,    -1,   328,    -1,   325,   326,    -1,   326,
      -1,   327,    -1,   338,    -1,   339,    -1,   329,    -1,   330,
      -1,   340,    -1,   331,    -1,   332,    -1,   333,    -1,   334,
      -1,   335,    -1,   336,    -1,   337,    -1,     1,   246,    -1,
     107,   249,   138,   246,    -1,   138,    -1,   135,   249,   255,
     246,    -1,   136,   249,   255,   246,    -1,   120,   249,   117,
     246,    -1,    29,   249,   255,   246,    -1,    99,   249,   117,
     246,    -1,    94,   249,   117,   246,    -1,    96,   249,   117,
     246,    -1,    95,   249,   117,   246,    -1,   163,   249,   257,
     246,    -1,    22,   249,   117,   246,    -1,    23,   249,   117,
     246,    -1,   119,   249,   117,   246,    -1,    -1,    89,   342,
     248,   347,   247,   246,    -1,    -1,    52,   344,   249,   345,
     246,    -1,   345,   250,   346,    -1,   346,    -1,   213,    -1,
      66,    -1,   209,    -1,   347,   348,    -1,   348,    -1,   349,
      -1,   343,    -1,   353,    -1,   354,    -1,     1,   246,    -1,
      -1,   137,   249,   351,   350,   246,    -1,   351,   250,   352,
      -1,   352,    -1,   117,    -1,   117,   187,   117,    -1,    78,
     249,   138,   246,    -1,    73,   249,   138,   246,    -1,    -1,
      63,   356,   248,   357,   247,   246,    -1,   357,   358,    -1,
     358,    -1,   359,    -1,   360,    -1,   361,    -1,   363,    -1,
     367,    -1,   368,    -1,   369,    -1,   362,    -1,     1,   246,
      -1,   232,   249,   138,   246,    -1,   132,   249,   138,   246,
      -1,    25,   249,   138,   246,    -1,    48,   249,   182,   246,
      -1,    -1,    52,   364,   249,   365,   246,    -1,   365,   250,
     366,    -1,   366,    -1,   176,    -1,    49,    -1,    82,    -1,
      64,    -1,    20,    -1,   116,    -1,    58,    -1,   157,    -1,
     108,    -1,   175,   249,   138,   246,    -1,   142,   249,   138,
     246,    -1,   141,   249,   117,   246,    -1,    -1,   156,   371,
     248,   372,   247,   246,    -1,   372,   373,    -1,   373,    -1,
     374,    -1,   375,    -1,   376,    -1,     1,   246,    -1,   140,
     249,   138,   246,    -1,    21,   249,   138,   246,    -1,   111,
     249,   138,   246,    -1,   222,   248,   378,   247,   246,    -1,
     378,   379,    -1,   379,    -1,   380,    -1,     1,    -1,   107,
     249,   138,   246,    -1,    -1,   170,   382,   248,   383,   247,
     246,    -1,   383,   384,    -1,   384,    -1,   385,    -1,   386,
      -1,   387,    -1,     1,   246,    -1,   107,   249,   138,   246,
      -1,   232,   249,   138,   246,    -1,    -1,   172,   388,   249,
     389,   246,    -1,   389,   250,   390,    -1,   390,    -1,    81,
      -1,   228,    -1,   231,    -1,   241,    -1,   229,    -1,   218,
      -1,   156,    -1,   230,    -1,   217,    -1,   204,    -1,   188,
      -1,    -1,   171,   392,   248,   393,   247,   246,    -1,   393,
     394,    -1,   394,    -1,   395,    -1,   396,    -1,     1,   246,
      -1,   107,   249,   138,   246,    -1,    -1,   172,   397,   249,
     398,   246,    -1,   398,   250,   399,    -1,   399,    -1,    81,
      -1,   228,    -1,   231,    -1,   241,    -1,   229,    -1,   218,
      -1,   156,    -1,   230,    -1,   217,    -1,   204,    -1,   188,
      -1,    -1,    28,   401,   402,   248,   403,   247,   246,    -1,
      -1,   406,    -1,   403,   404,    -1,   404,    -1,   405,    -1,
     407,    -1,   408,    -1,   409,    -1,   410,    -1,   412,    -1,
     411,    -1,   413,    -1,   419,    -1,   420,    -1,   421,    -1,
     418,    -1,   417,    -1,   422,    -1,     1,   246,    -1,   107,
     249,   138,   246,    -1,   138,    -1,    73,   249,   138,   246,
      -1,   239,   249,   138,   246,    -1,   164,   249,   138,   246,
      -1,     3,   249,   138,   246,    -1,   137,   249,   117,   246,
      -1,     6,   249,   202,   246,    -1,     6,   249,   203,   246,
      -1,    -1,    52,   414,   249,   415,   246,    -1,   415,   250,
     416,    -1,   416,    -1,    26,    -1,    30,    -1,    10,    -1,
      12,    -1,   226,    -1,   151,   249,   138,   246,    -1,    48,
     249,   182,   246,    -1,    75,   249,   138,   246,    -1,    87,
     249,   138,   246,    -1,    25,   249,   138,   246,    -1,    24,
     249,   138,   246,    -1,    -1,    79,   424,   248,   429,   247,
     246,    -1,    -1,   172,   426,   249,   427,   246,    -1,   427,
     250,   428,    -1,   428,    -1,   143,    -1,   429,   430,    -1,
     430,    -1,   431,    -1,   432,    -1,   425,    -1,     1,    -1,
     232,   249,   138,   246,    -1,   140,   249,   138,   246,    -1,
      -1,    35,   434,   248,   435,   247,   246,    -1,   435,   436,
      -1,   436,    -1,   437,    -1,   438,    -1,     1,    -1,    78,
     249,   138,   246,    -1,   140,   249,   138,   246,    -1,    50,
     248,   440,   247,   246,    -1,   440,   441,    -1,   441,    -1,
     442,    -1,     1,    -1,    78,   249,   138,   246,    -1,    -1,
      54,   444,   248,   449,   247,   246,    -1,    -1,   172,   446,
     249,   447,   246,    -1,   447,   250,   448,    -1,   448,    -1,
     143,    -1,   449,   450,    -1,   450,    -1,   451,    -1,   452,
      -1,   445,    -1,     1,    -1,   107,   249,   138,   246,    -1,
     140,   249,   138,   246,    -1,    55,   248,   454,   247,   246,
      -1,   454,   455,    -1,   455,    -1,   463,    -1,   464,    -1,
     466,    -1,   467,    -1,   468,    -1,   469,    -1,   470,    -1,
     471,    -1,   472,    -1,   473,    -1,   462,    -1,   475,    -1,
     476,    -1,   477,    -1,   478,    -1,   493,    -1,   480,    -1,
     482,    -1,   484,    -1,   483,    -1,   487,    -1,   481,    -1,
     488,    -1,   489,    -1,   490,    -1,   491,    -1,   492,    -1,
     508,    -1,   494,    -1,   498,    -1,   499,    -1,   504,    -1,
     485,    -1,   486,    -1,   514,    -1,   512,    -1,   513,    -1,
     495,    -1,   465,    -1,   496,    -1,   497,    -1,   515,    -1,
     503,    -1,   474,    -1,   501,    -1,   502,    -1,   461,    -1,
     457,    -1,   458,    -1,   459,    -1,   460,    -1,   479,    -1,
     456,    -1,   500,    -1,     1,    -1,   101,   249,   117,   246,
      -1,    60,   249,   117,   246,    -1,    61,   249,   117,   246,
      -1,   238,   249,   182,   246,    -1,   145,   249,   255,   246,
      -1,   169,   249,   182,   246,    -1,    80,   249,   255,   246,
      -1,    72,   249,   182,   246,    -1,    76,   249,   182,   246,
      -1,    42,   249,   182,   246,    -1,    51,   249,   182,   246,
      -1,     8,   249,   182,   246,    -1,    98,   249,   255,   246,
      -1,    97,   249,   117,   246,    -1,    91,   249,   117,   246,
      -1,     9,   249,   255,   246,    -1,   186,   249,   255,   246,
      -1,   185,   249,   255,   246,    -1,    65,   249,   117,   246,
      -1,    84,   249,   182,   246,    -1,    83,   249,   138,   246,
      -1,    77,   249,   182,   246,    -1,   243,   249,   182,   246,
      -1,   177,   249,   182,   246,    -1,   180,   249,   182,   246,
      -1,   181,   249,   182,   246,    -1,   179,   249,   182,   246,
      -1,   179,   249,   183,   246,    -1,   178,   249,   182,   246,
      -1,   178,   249,   183,   246,    -1,   130,   249,   255,   246,
      -1,    19,   249,   255,   246,    -1,   123,   249,   182,   246,
      -1,   131,   249,   255,   246,    -1,   173,   249,   182,   246,
      -1,   115,   249,   182,   246,    -1,   227,   249,   182,   246,
      -1,   125,   249,   182,   246,    -1,   102,   249,   138,   246,
      -1,    43,   249,   117,   246,    -1,   100,   249,   117,   246,
      -1,   167,   249,   138,   246,    -1,    31,   249,   138,   246,
      -1,    27,   249,   117,   246,    -1,   233,   249,   182,   246,
      -1,    45,   249,   138,   246,    -1,   223,   249,   138,   246,
      -1,   134,   249,   182,   246,    -1,    38,   249,   182,   246,
      -1,   225,   249,   255,   246,    -1,    -1,   127,   505,   249,
     506,   246,    -1,   506,   250,   507,    -1,   507,    -1,   189,
      -1,   192,    -1,   193,    -1,   195,    -1,   196,    -1,   200,
      -1,   211,    -1,   206,    -1,   208,    -1,   215,    -1,   212,
      -1,   199,    -1,   207,    -1,   210,    -1,   201,    -1,   220,
      -1,   190,    -1,   191,    -1,   204,    -1,    -1,   124,   509,
     249,   510,   246,    -1,   510,   250,   511,    -1,   511,    -1,
     189,    -1,   192,    -1,   193,    -1,   195,    -1,   196,    -1,
     200,    -1,   211,    -1,   206,    -1,   208,    -1,   215,    -1,
     212,    -1,   199,    -1,   207,    -1,   210,    -1,   201,    -1,
     220,    -1,   190,    -1,   191,    -1,   204,    -1,   103,   249,
     117,   246,    -1,   104,   249,   117,   246,    -1,    32,   249,
     117,   246,    -1,   194,   249,   257,   246,    -1,    -1,    57,
     517,   248,   518,   247,   246,    -1,   518,   519,    -1,   519,
      -1,   520,    -1,   521,    -1,   522,    -1,   526,    -1,   527,
      -1,   528,    -1,     1,    -1,    47,   249,   182,   246,    -1,
      44,   249,   255,   246,    -1,    -1,    90,   523,   249,   524,
     246,    -1,   524,   250,   525,    -1,   525,    -1,   184,    -1,
      11,    -1,   232,   249,   138,   246,    -1,   107,   249,   138,
     246,    -1,    -1,     4,   529,   249,   530,   246,    -1,   530,
     250,   531,    -1,   531,    -1,   184,    -1,    11,    -1,    21,
     248,   533,   247,   246,    -1,   533,   534,    -1,   534,    -1,
     537,    -1,   538,    -1,   539,    -1,   540,    -1,   545,    -1,
     541,    -1,   542,    -1,   543,    -1,   544,    -1,   546,    -1,
     547,    -1,   548,    -1,   536,    -1,   549,    -1,   550,    -1,
     551,    -1,   552,    -1,   535,    -1,     1,    -1,    39,   249,
     182,   246,    -1,   148,   249,   182,   246,    -1,    41,   249,
     182,   246,    -1,   234,   249,   182,   246,    -1,   235,   249,
     182,   246,    -1,   236,   249,   182,   246,    -1,    85,   249,
     255,   246,    -1,    86,   249,   255,   246,    -1,    93,   249,
     117,   246,    -1,   139,   249,   182,   246,    -1,    92,   249,
     117,   246,    -1,    34,   249,   117,   246,    -1,    33,   249,
     117,   246,    -1,   113,   249,   182,   246,    -1,   114,   249,
     182,   246,    -1,    13,   249,   182,   246,    -1,   128,   249,
     117,   246,    -1,   129,   249,   255,   246,    -1,   165,   248,
     554,   247,   246,    -1,   554,   555,    -1,   555,    -1,   556,
      -1,   557,    -1,   559,    -1,   561,    -1,   560,    -1,   558,
      -1,   562,    -1,     1,    -1,    53,   249,   182,   246,    -1,
      71,   249,   182,   246,    -1,    68,   249,   138,   246,    -1,
      88,   249,   255,   246,    -1,    66,   249,   182,   246,    -1,
      40,   249,   182,   246,    -1,    70,   249,   182,   246,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   381,   381,   382,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   411,   411,   412,
     416,   420,   424,   428,   432,   438,   438,   439,   440,   441,
     442,   449,   452,   452,   453,   453,   453,   455,   461,   468,
     470,   470,   471,   471,   472,   472,   473,   473,   474,   475,
     475,   476,   476,   477,   478,   482,   481,   500,   500,   501,
     507,   515,   549,   609,   624,   639,   648,   662,   671,   699,
     729,   752,   761,   763,   763,   764,   764,   765,   765,   767,
     776,   785,   797,   798,   798,   800,   800,   800,   801,   803,
     809,   816,   816,   826,   827,   829,   829,   830,   830,   832,
     837,   840,   846,   845,   851,   851,   852,   856,   860,   864,
     868,   872,   876,   887,   886,   980,   980,   981,   981,   982,
     982,   982,   983,   983,   983,   984,   984,   984,   986,   998,
    1010,  1044,  1056,  1067,  1109,  1119,  1118,  1124,  1124,  1125,
    1129,  1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,
    1169,  1173,  1177,  1181,  1185,  1189,  1193,  1197,  1204,  1203,
    1209,  1209,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1242,  1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,
    1289,  1288,  1338,  1338,  1340,  1340,  1341,  1342,  1342,  1343,
    1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1355,  1364,  1373,  1379,  1385,  1391,  1397,  1403,  1409,  1415,
    1421,  1427,  1433,  1439,  1449,  1448,  1465,  1464,  1469,  1469,
    1470,  1474,  1478,  1486,  1486,  1487,  1487,  1487,  1487,  1487,
    1489,  1489,  1491,  1491,  1493,  1507,  1527,  1536,  1549,  1548,
    1617,  1617,  1618,  1618,  1618,  1618,  1619,  1619,  1619,  1620,
    1620,  1622,  1659,  1672,  1681,  1693,  1692,  1696,  1696,  1697,
    1701,  1705,  1709,  1713,  1717,  1721,  1725,  1729,  1736,  1755,
    1765,  1779,  1778,  1794,  1794,  1795,  1795,  1795,  1795,  1797,
    1806,  1821,  1834,  1836,  1836,  1837,  1837,  1839,  1855,  1854,
    1870,  1870,  1871,  1871,  1871,  1871,  1873,  1882,  1905,  1904,
    1910,  1910,  1911,  1915,  1919,  1923,  1927,  1931,  1935,  1939,
    1943,  1947,  1951,  1961,  1960,  1977,  1977,  1978,  1978,  1978,
    1980,  1987,  1986,  1992,  1992,  1993,  1997,  2001,  2005,  2009,
    2013,  2017,  2021,  2025,  2029,  2033,  2043,  2042,  2185,  2185,
    2186,  2186,  2187,  2187,  2187,  2188,  2188,  2189,  2189,  2190,
    2190,  2190,  2191,  2191,  2192,  2192,  2193,  2195,  2207,  2219,
    2228,  2254,  2272,  2290,  2296,  2300,  2309,  2308,  2312,  2312,
    2313,  2323,  2327,  2331,  2335,  2341,  2382,  2393,  2406,  2419,
    2428,  2464,  2463,  2527,  2526,  2530,  2530,  2531,  2537,  2537,
    2538,  2538,  2538,  2538,  2540,  2559,  2569,  2568,  2591,  2591,
    2592,  2592,  2592,  2594,  2600,  2609,  2611,  2611,  2612,  2612,
    2614,  2633,  2632,  2680,  2679,  2683,  2683,  2684,  2690,  2690,
    2691,  2691,  2691,  2691,  2693,  2699,  2708,  2711,  2711,  2712,
    2712,  2713,  2713,  2714,  2714,  2715,  2715,  2716,  2716,  2717,
    2717,  2718,  2718,  2719,  2719,  2720,  2720,  2721,  2721,  2722,
    2722,  2723,  2723,  2724,  2724,  2725,  2726,  2726,  2727,  2727,
    2728,  2728,  2729,  2729,  2730,  2730,  2731,  2731,  2732,  2733,
    2733,  2734,  2734,  2735,  2736,  2737,  2737,  2738,  2738,  2739,
    2739,  2740,  2740,  2741,  2744,  2749,  2754,  2759,  2764,  2769,
    2774,  2779,  2784,  2789,  2794,  2799,  2804,  2809,  2814,  2819,
    2824,  2829,  2835,  2846,  2851,  2860,  2865,  2870,  2875,  2880,
    2885,  2888,  2893,  2896,  2901,  2906,  2911,  2916,  2921,  2926,
    2931,  2936,  2941,  2952,  2957,  2962,  2971,  3003,  3021,  3026,
    3035,  3044,  3049,  3054,  3060,  3059,  3064,  3064,  3065,  3068,
    3071,  3074,  3077,  3080,  3083,  3086,  3089,  3092,  3095,  3098,
    3101,  3104,  3107,  3110,  3113,  3116,  3119,  3125,  3124,  3129,
    3129,  3130,  3133,  3136,  3139,  3142,  3145,  3148,  3151,  3154,
    3157,  3160,  3163,  3166,  3169,  3172,  3175,  3178,  3181,  3184,
    3189,  3194,  3199,  3204,  3214,  3213,  3237,  3237,  3238,  3239,
    3240,  3241,  3242,  3243,  3244,  3246,  3252,  3259,  3258,  3263,
    3263,  3264,  3268,  3274,  3308,  3318,  3317,  3367,  3367,  3368,
    3372,  3381,  3384,  3384,  3385,  3385,  3386,  3386,  3387,  3387,
    3388,  3388,  3389,  3389,  3390,  3391,  3391,  3392,  3392,  3393,
    3393,  3394,  3394,  3396,  3401,  3406,  3411,  3416,  3421,  3426,
    3431,  3436,  3441,  3446,  3451,  3456,  3461,  3466,  3471,  3476,
    3481,  3489,  3492,  3492,  3493,  3493,  3494,  3495,  3496,  3496,
    3497,  3498,  3500,  3506,  3512,  3521,  3535,  3541,  3547
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
     495,   496,   497,   498,   499,   500,    59,   125,   123,    61,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   251,   252,   252,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   254,   254,   255,
     255,   255,   255,   255,   255,   256,   256,   257,   257,   257,
     257,   258,   259,   259,   260,   260,   260,   261,   262,   263,
     264,   264,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   267,   266,   268,   268,   269,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   282,   283,   283,   283,   283,   284,
     285,   286,   287,   288,   288,   289,   289,   289,   289,   290,
     291,   293,   292,   294,   294,   295,   295,   295,   295,   296,
     297,   297,   299,   298,   300,   300,   301,   301,   301,   301,
     301,   301,   301,   303,   302,   304,   304,   305,   305,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   308,
     309,   310,   311,   312,   313,   315,   314,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   319,   318,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     323,   322,   324,   324,   325,   325,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   342,   341,   344,   343,   345,   345,
     346,   346,   346,   347,   347,   348,   348,   348,   348,   348,
     350,   349,   351,   351,   352,   352,   353,   354,   356,   355,
     357,   357,   358,   358,   358,   358,   358,   358,   358,   358,
     358,   359,   360,   361,   362,   364,   363,   365,   365,   366,
     366,   366,   366,   366,   366,   366,   366,   366,   367,   368,
     369,   371,   370,   372,   372,   373,   373,   373,   373,   374,
     375,   376,   377,   378,   378,   379,   379,   380,   382,   381,
     383,   383,   384,   384,   384,   384,   385,   386,   388,   387,
     389,   389,   390,   390,   390,   390,   390,   390,   390,   390,
     390,   390,   390,   392,   391,   393,   393,   394,   394,   394,
     395,   397,   396,   398,   398,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   401,   400,   402,   402,
     403,   403,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   412,   414,   413,   415,   415,
     416,   416,   416,   416,   416,   417,   418,   419,   420,   421,
     422,   424,   423,   426,   425,   427,   427,   428,   429,   429,
     430,   430,   430,   430,   431,   432,   434,   433,   435,   435,
     436,   436,   436,   437,   438,   439,   440,   440,   441,   441,
     442,   444,   443,   446,   445,   447,   447,   448,   449,   449,
     450,   450,   450,   450,   451,   452,   453,   454,   454,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   455,   455,   455,   455,   455,   455,
     455,   455,   455,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   482,   483,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   505,   504,   506,   506,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   509,   508,   510,
     510,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     512,   513,   514,   515,   517,   516,   518,   518,   519,   519,
     519,   519,   519,   519,   519,   520,   521,   523,   522,   524,
     524,   525,   525,   526,   527,   529,   528,   530,   530,   531,
     531,   532,   533,   533,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   554,   555,   555,   555,   555,   555,   555,
     555,   555,   556,   557,   558,   559,   560,   561,   562
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
       1,     1,     1,     0,     7,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     7,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
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
       2,     0,     1,     0,     0,     0,   190,   346,   406,     0,
     421,     0,   594,   248,   391,   224,     0,     0,   123,   281,
       0,     0,   298,   323,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,   192,   348,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   642,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   623,
     641,   636,   624,   625,   626,   627,   629,   630,   631,   632,
     628,   633,   634,   635,   637,   638,   639,   640,   211,     0,
     193,   368,     0,   349,     0,   419,     0,     0,   417,   418,
       0,   493,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   567,     0,   544,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,   491,   486,
     487,   488,   489,   485,   449,   439,   440,   477,   441,   442,
     443,   444,   445,   446,   447,   448,   482,   450,   451,   452,
     453,   490,   455,   460,   456,   458,   457,   471,   472,   459,
     461,   462,   463,   464,   465,   454,   467,   476,   478,   479,
     468,   469,   492,   483,   484,   481,   470,   466,   474,   475,
     473,   480,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,     0,     0,     0,     0,    43,
      44,    45,   139,     0,   126,     0,   671,     0,     0,     0,
       0,     0,     0,     0,     0,   663,   664,   665,   669,   666,
     668,   667,   670,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,    51,    63,    62,
      59,    52,    61,    55,    56,    57,    53,    60,    58,    54,
       0,     0,   296,     0,     0,   294,   295,    88,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   622,     0,     0,   412,     0,     0,     0,   409,
     410,   411,     0,     0,   416,   433,     0,     0,   423,   432,
       0,   429,   430,   431,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   437,
     604,   615,     0,     0,   607,     0,     0,     0,   597,   598,
     599,   600,   601,   602,   603,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,   251,   252,   253,   254,   259,
     255,   256,   257,   258,   403,     0,   393,     0,   402,     0,
     399,   400,   401,     0,   226,     0,     0,     0,   236,     0,
     234,   235,   237,   238,    98,     0,     0,     0,    93,     0,
      46,     0,     0,     0,    42,     0,     0,     0,     0,     0,
       0,   284,   285,   286,   287,     0,     0,     0,     0,     0,
       0,     0,     0,   662,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   308,     0,     0,   301,   302,   303,   304,     0,     0,
     331,     0,   326,   327,   328,     0,     0,   293,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,   196,   199,
     200,   202,   203,   204,   205,   206,   207,   208,   197,   198,
     201,     0,     0,     0,     0,     0,     0,   376,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,   356,   358,   357,   359,   364,   363,   360,   361,
     362,   365,     0,     0,     0,   408,     0,   415,     0,     0,
       0,     0,   428,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
     436,     0,     0,     0,     0,     0,     0,     0,   596,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,   398,   239,     0,     0,     0,     0,
       0,   233,     0,     0,    92,     0,     0,     0,    41,     0,
       0,     0,   168,     0,     0,     0,   145,     0,     0,   128,
     129,   130,   131,   134,   135,   133,   132,   136,   288,     0,
       0,     0,     0,   283,     0,     0,     0,     0,     0,     0,
       0,   661,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,   305,     0,     0,     0,     0,
     300,   329,     0,     0,     0,   325,     0,   292,    91,    90,
      89,   658,   655,   654,   643,   645,    27,    27,    27,    27,
      27,    29,    28,   649,   650,   653,   651,   656,   657,   659,
     660,   652,   644,   646,   647,   648,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   366,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   350,     0,
       0,   407,   420,     0,     0,     0,   422,   505,   509,   525,
     537,   536,   592,   542,   503,   533,   539,   504,   495,   496,
     512,   501,   502,   515,   500,   514,   513,   508,   507,   506,
     534,   494,   532,   590,   591,   529,   526,   571,   587,   588,
     572,   573,   574,   575,   582,   576,   585,   589,   578,   583,
     579,   584,   577,   581,   580,   586,     0,   570,   531,   548,
     564,   565,   549,   550,   551,   552,   559,   553,   562,   566,
     555,   560,   556,   561,   554,   558,   557,   563,     0,   547,
     524,   527,   541,   498,   535,   499,   528,   517,   522,   523,
     520,   521,   518,   519,   511,   510,    35,    35,    35,    37,
      36,   593,   540,   543,   530,   538,   497,   516,     0,     0,
       0,     0,     0,     0,   595,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,   392,     0,     0,
       0,   244,   240,   243,   225,   100,    99,     0,     0,   112,
       0,     0,   104,   105,   107,   106,    47,    48,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,     0,
       0,     0,   282,   677,   672,   676,   674,   678,   673,   675,
      75,    81,    73,    77,    76,    72,    71,    69,    70,     0,
      68,    74,    80,    78,    79,     0,     0,     0,   299,     0,
       0,   324,   297,    30,    31,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   347,   413,   414,
     434,   435,   427,     0,   426,   568,     0,   545,     0,    38,
      39,    40,   620,   619,     0,   618,   606,   605,   612,   611,
       0,   610,   614,   613,   263,   264,   273,   270,   275,   272,
     271,   277,   274,   276,   269,     0,   268,   262,   280,   279,
     278,   261,   405,   397,     0,   396,   404,   231,   232,   230,
       0,   229,   247,   246,     0,     0,     0,   108,     0,     0,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   290,   291,   289,    66,     0,   306,   312,   318,
     322,   321,   320,   317,   313,   316,   319,   314,   315,     0,
     311,   307,   330,   335,   341,   345,   344,   343,   340,   336,
     339,   342,   337,   338,     0,   334,   221,   222,   215,   217,
     219,   218,   216,   210,   223,   214,   212,   213,   220,   372,
     374,   375,   390,   389,   386,   382,   383,   380,   381,   384,
       0,   379,   369,   387,   388,   367,   373,   385,   371,   370,
     424,     0,   569,   546,   616,     0,   608,     0,   266,     0,
     394,     0,   227,     0,   245,   242,   241,     0,     0,     0,
       0,   102,   144,   142,   181,   178,   177,   172,   182,   187,
     174,   189,   183,   186,   180,   173,   188,   184,   185,   179,
     175,   176,     0,   171,   138,   141,   143,   149,   165,   166,
     150,   151,   152,   153,   160,   154,   163,   167,   156,   161,
     157,   162,   155,   159,   158,   164,     0,   148,   140,    67,
     309,     0,   332,     0,   377,     0,   425,   617,   609,   267,
     395,   228,   109,   118,   121,   120,   117,   122,   119,   116,
       0,   115,   111,   110,   169,     0,   146,     0,   310,   333,
     378,   113,     0,   170,   147,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   801,   802,   949,   950,    26,   258,   259,
     260,   261,    27,   296,   297,   298,   512,  1029,  1030,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      28,    74,    75,    76,    77,    78,    29,   249,   250,   251,
     252,   253,   254,   991,   992,   993,   994,   995,  1139,  1310,
    1311,    30,    63,   263,   738,   739,   740,   264,   741,   742,
     743,   744,   745,   746,  1005,  1286,  1287,   747,  1001,  1262,
    1263,    31,    51,   119,   576,   577,   578,   120,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
      32,    60,   468,   716,  1130,  1131,   469,   470,   471,  1136,
     982,   983,   472,   473,    33,    58,   444,   445,   446,   447,
     448,   449,   450,   702,  1115,  1116,   451,   452,   453,    34,
      64,   490,   491,   492,   493,   494,    35,   314,   315,   316,
      36,    67,   523,   524,   525,   526,   527,   777,  1169,  1170,
      37,    68,   531,   532,   533,   534,   783,  1184,  1185,    38,
      52,   122,   606,   607,   608,   123,   609,   610,   611,   612,
     613,   614,   615,   838,  1210,  1211,   616,   617,   618,   619,
     620,   621,    39,    59,   458,   711,  1124,  1125,   459,   460,
     461,   462,    40,    53,   348,   349,   350,   351,    41,   127,
     128,   129,    42,    55,   359,   630,  1083,  1084,   360,   361,
     362,   363,    43,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   396,   928,   929,   237,   394,   906,
     907,   238,   239,   240,   241,    44,    57,   427,   428,   429,
     430,   431,   694,  1100,  1101,   432,   433,   434,   691,  1094,
    1095,    45,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,    46,   274,   275,   276,   277,   278,   279,   280,
     281,   282
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -920
static const yytype_int16 yypact[] =
{
    -920,   681,  -920,  -169,  -242,  -239,  -920,  -920,  -920,  -237,
    -920,  -229,  -920,  -920,  -920,  -920,  -218,  -207,  -920,  -920,
    -190,  -188,  -920,  -920,  -185,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,   339,
     604,   -72,   -53,  -158,    25,  -156,   393,  -149,  -122,  -116,
    -108,    66,    31,    10,   -95,   351,   353,   -86,   -81,    16,
     -76,   -77,   -63,   -55,    15,  -920,  -920,  -920,  -920,  -920,
     -49,   -40,   -17,    -8,    -6,    -3,    18,    52,    63,    70,
      76,    89,   101,   107,   125,   143,   144,   148,   111,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,    34,
    -920,  -920,    37,  -920,   219,  -920,   149,    33,  -920,  -920,
     211,  -920,   150,   151,   157,   158,   160,   162,   164,   165,
     166,   167,   181,   183,   193,   194,   196,   198,   199,   200,
     202,   215,   217,   223,   226,   229,   230,   232,   233,   236,
     237,   238,  -920,   239,  -920,   240,   249,   250,   253,   258,
     260,   261,   262,   263,   264,   270,   273,   276,   279,   281,
     286,   287,   288,   290,   291,   293,     4,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,   436,   409,   141,   377,    12,   295,   305,    32,
    -920,  -920,  -920,  -920,    65,   120,   306,   307,    13,  -920,
    -920,  -920,  -920,   142,  -920,    96,  -920,   308,   310,   312,
     314,   316,   318,   319,    90,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,   159,   320,   326,   328,   332,   333,   336,
     337,  -920,   341,   342,   346,   348,   156,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
       3,    61,  -920,   349,     2,  -920,  -920,  -920,   114,   330,
     450,   182,  -920,   292,   482,   483,   420,   422,   489,   489,
     490,   492,   428,   429,   495,   489,   431,   432,   437,   439,
     440,   378,  -920,   655,   528,  -920,   374,   376,    88,  -920,
    -920,  -920,   491,   381,  -920,  -920,   379,   384,  -920,  -920,
      47,  -920,  -920,  -920,   448,   489,   489,   517,   502,   525,
     462,   465,   531,   511,   468,   534,   535,   537,   473,   475,
     476,   489,   521,   478,   544,   545,   489,   546,   547,   529,
     549,   552,   488,   493,   423,   494,   434,   489,   489,   498,
     489,   550,   503,   505,   509,    35,   140,   512,   513,   489,
     489,   576,   560,   489,   518,   519,   522,   523,   453,  -920,
    -920,  -920,   454,   458,  -920,   459,   461,     6,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,   466,   470,   471,  -920,   474,
     477,   479,   481,   496,    73,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,   506,  -920,   507,  -920,    23,
    -920,  -920,  -920,   469,  -920,   508,   510,   514,  -920,    42,
    -920,  -920,  -920,  -920,  -920,   532,   540,   501,  -920,   463,
    -920,   586,   587,   515,  -920,   301,   520,   516,   524,   536,
      36,  -920,  -920,  -920,  -920,   555,   557,   558,   589,   559,
     582,   489,   526,  -920,  -920,   638,   595,   640,   642,   643,
     646,   648,   543,   651,   625,   659,   660,   553,  -920,   554,
     556,  -920,   561,    44,  -920,  -920,  -920,  -920,   563,   562,
    -920,   115,  -920,  -920,  -920,   663,   566,  -920,   567,   568,
     569,  -920,   570,   573,   575,   578,   579,   387,   580,   581,
     583,   584,   585,   588,   596,   597,   598,   599,   602,   607,
     608,  -920,   609,   610,   615,   616,   617,   619,   620,   621,
     622,   623,   635,   636,   641,   647,   179,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,   611,   652,   656,   657,   664,   668,  -920,   672,   673,
     675,   679,   683,   684,   688,   689,   220,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,   666,   669,   612,  -920,   628,  -920,   690,   694,
     696,   654,  -920,   658,   702,   703,   707,   708,   710,   714,
     718,   721,   722,   723,   724,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   687,   744,   719,   745,   746,   747,   748,
     749,   750,   752,   753,   754,   755,   756,   757,   758,   760,
     761,   762,   354,   763,   764,   765,   766,   767,   768,   769,
    -920,   716,   489,   653,   770,   695,   798,   771,  -920,  -920,
     859,   674,   772,   867,   685,   878,   880,   882,   776,  -920,
     885,   775,   887,   780,  -920,  -920,   778,   890,   891,   705,
     784,  -920,   785,   786,  -920,    99,   787,   788,  -920,   789,
     790,   791,  -920,   792,   793,   794,  -920,   795,   209,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,   898,
     899,   900,   799,  -920,   800,   801,   802,   803,   804,   805,
     806,  -920,   807,   808,   809,   810,   811,   812,   813,   225,
     814,   815,   816,   817,  -920,  -920,   926,   818,   927,   820,
    -920,  -920,   930,   821,   823,  -920,   825,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,   489,   489,   489,   489,
     489,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,   955,   956,   489,
     957,   958,   959,   960,   940,   962,   963,   489,   489,   576,
     835,  -920,  -920,   944,   185,   945,   946,   699,   836,   948,
     949,   950,   951,   973,   953,   954,   961,   847,  -920,   848,
     849,  -920,  -920,   850,   851,   964,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -225,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -206,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,   576,   576,   576,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,     7,   852,
     854,     9,   855,   856,  -920,   857,   858,   759,   860,   862,
     863,   864,   865,  -920,   866,   970,   868,  -920,   -44,   869,
     870,   918,   639,  -920,  -920,  -920,  -920,   871,   872,  -920,
     873,    92,  -920,  -920,  -920,  -920,  -920,  -920,  -920,   980,
     937,   874,   982,   986,   987,   877,   989,   883,  -920,   884,
     886,   888,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -194,
    -920,  -920,  -920,  -920,  -920,   889,   565,   892,  -920,   893,
     632,  -920,  -920,  -920,  -920,  -920,  -920,  -920,   894,   895,
     896,   897,   901,   902,   903,   904,   905,   906,   907,   908,
     909,  -920,   910,   911,   912,   913,   914,   915,   129,   916,
     917,   919,   920,   921,   922,   923,   924,  -920,  -920,  -920,
    -920,  -920,  -920,  -178,  -920,  -920,   687,  -920,   719,  -920,
    -920,  -920,  -920,  -920,  -171,  -920,  -920,  -920,  -920,  -920,
    -113,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,    38,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,    46,  -920,  -920,  -920,  -920,  -920,
      54,  -920,  -920,  -920,  1011,   705,   925,  -920,   993,   928,
    -102,   929,  -920,   932,   933,   527,   934,   935,   936,   751,
     938,  -920,  -920,  -920,  -920,  -920,   225,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,    71,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,    98,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
     117,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,   964,  -920,  -920,  -920,     7,  -920,     9,  -920,   759,
    -920,   970,  -920,   -44,  -920,  -920,  -920,   939,   132,   941,
     942,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,   126,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,   131,  -920,  -920,  -920,
    -920,   565,  -920,   632,  -920,   129,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
     136,  -920,  -920,  -920,  -920,   527,  -920,   751,  -920,  -920,
    -920,  -920,   132,  -920,  -920,  -920
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -920,  -920,  -920,  -466,  -327,  -919,  -411,  -920,  -920,   634,
    -920,  -920,  -920,  -920,   837,  -920,  -920,  -920,   -20,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  1063,  -920,  -920,  -920,  -920,  -920,   943,  -920,
    -920,  -920,  -920,  -920,   153,  -920,  -920,  -920,  -920,  -920,
    -177,  -920,  -920,  -920,  -920,   408,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -153,  -920,  -920,  -920,
    -143,  -920,  -920,  -920,  -920,   600,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,   -60,  -920,   717,  -920,  -920,
    -920,    39,  -920,  -920,  -920,  -920,  -920,   773,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,   -46,  -920,  -920,  -920,  -920,
    -920,  -920,   700,  -920,  -920,  -920,  -920,  -920,   875,  -920,
    -920,  -920,  -920,   670,  -920,  -920,  -920,  -920,  -920,  -100,
    -920,  -920,  -920,   665,  -920,  -920,  -920,  -920,   -99,  -920,
    -920,  -920,  -920,   591,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,   -97,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,   -36,  -920,   774,
    -920,  -920,  -920,  -920,  -920,   853,  -920,  -920,  -920,  -920,
    1072,  -920,  -920,  -920,  -920,  -920,  -920,   -21,  -920,   842,
    -920,  -920,  -920,  -920,  1017,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,   116,  -920,  -920,  -920,
     119,  -920,  -920,  -920,  -920,  -920,  -920,  -920,   779,  -920,
    -920,  -920,  -920,  -920,   -19,  -920,  -920,  -920,  -920,  -920,
     -18,  -920,  -920,  1111,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,  -920,
    -920,  -920,  -920,  -920,   947,  -920,  -920,  -920,  -920,  -920,
    -920,  -920
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     683,   548,   549,   312,   519,   131,    49,   420,   555,    50,
     421,    54,   132,   133,   255,   682,    70,   312,  1092,    56,
    1098,  1085,  1127,   134,   454,  1086,   125,  1089,  1090,  1091,
      61,   135,   255,   246,   125,   136,   137,   486,   634,   635,
    1087,    62,   138,   463,  1088,   519,   139,   140,   355,   141,
     422,    71,  1155,   423,   650,   142,  1156,   487,    65,   655,
      66,    72,   528,    69,   143,   144,   118,   246,  1220,   145,
     666,   667,  1221,   669,   435,  1224,   146,    47,    48,  1225,
     147,   148,   680,   681,   149,   121,   685,   150,   151,   345,
     124,   266,   130,   987,   464,   152,   424,   486,   436,   242,
     987,   153,   154,   126,   155,   156,   157,   158,   159,   313,
     520,   126,    79,   425,  1239,   465,   528,   487,   256,   160,
     466,   437,    73,   313,    80,   438,   243,   161,   162,   163,
     267,   164,   244,  1226,   165,   166,   256,  1227,   167,  1205,
     245,  1206,   454,   268,    81,    82,   257,   488,   262,   168,
      83,   520,    84,   265,   356,  1207,   269,   283,   270,  1208,
     271,   272,   310,   455,   257,  1128,   346,   311,   529,  1129,
     317,   169,   318,   170,   760,   521,   489,   171,   273,   467,
     562,   172,   173,   174,   175,   176,   319,   357,  1303,   177,
     178,  1093,   284,  1099,   320,   456,    85,    86,   179,   988,
     323,   563,   564,    87,    88,   439,   988,   488,   565,   324,
     729,  1304,   355,  1305,   440,   441,   521,   674,   675,   358,
     345,   591,   529,   592,    89,    90,   593,   180,   347,   181,
     285,   182,   325,   530,   730,   522,   489,   183,   426,    91,
      92,   326,   184,   327,   594,   595,   328,   185,   442,   536,
      93,   418,   538,   697,  1306,   457,   247,   731,   474,    94,
     483,   732,   321,   286,   989,   287,   288,   329,   596,   248,
     713,   989,   597,   566,   567,   568,   522,  -101,   569,   477,
     353,   455,   343,   752,  1228,   344,   570,   530,  1229,   720,
     247,   779,  1230,   598,   631,   599,  1231,   346,   571,   572,
    1232,   330,   729,   248,  1233,   443,   289,   600,   290,   291,
     479,  -101,   331,   456,   573,   574,   733,  1290,   356,   332,
     708,  1291,   676,   677,   292,   333,   730,   601,  1307,  1308,
    1043,  1044,  1045,  1046,  1047,   624,   990,   502,   334,  1141,
      70,   734,   575,   990,  1292,    95,    96,    97,  1293,   731,
     335,   357,   266,   732,   283,  1209,   336,   602,   341,   347,
     735,   293,   784,  1294,  1309,   959,   480,  1295,   946,   947,
     948,   603,  1314,   457,   337,    71,  1315,  1316,   463,  1027,
    1028,  1317,  1321,   358,   604,    72,  1322,  1063,  1064,   284,
     485,   267,   338,   339,   131,   294,   295,   340,   352,   364,
     365,   132,   133,   517,   268,   504,   366,   367,   733,   368,
     435,   369,   134,   370,   371,   372,   373,   269,  1060,   270,
     135,   271,   272,   736,   136,   137,   830,   285,   541,   464,
     374,   138,   375,   734,   436,   139,   140,   420,   141,   273,
     421,   737,   376,   377,   142,   378,    73,   379,   380,   381,
     465,   382,   735,   143,   144,   466,  1007,   437,   145,   605,
     286,   438,   287,   288,   383,   146,   384,   847,   539,   147,
     148,   682,   385,   149,   542,   386,   150,   151,   387,   388,
     422,   389,   390,   423,   152,   391,   392,   393,   395,   397,
     153,   154,  1050,   155,   156,   157,   158,   159,   398,   399,
    1058,  1059,   400,   289,   547,   290,   291,   401,   160,   402,
     403,   404,   405,   406,   467,   736,   161,   162,   163,   407,
     164,   292,   408,   165,   166,   409,   424,   167,   410,   591,
     411,   592,  1244,   737,   593,   412,   413,   414,   168,   415,
     416,   439,   417,   425,   475,   796,   797,   798,   799,   800,
     440,   441,   594,   595,   476,   481,   482,   495,   293,   496,
     169,   497,   170,   498,  1245,   499,   171,   500,   501,   505,
     172,   173,   174,   175,   176,   506,   596,   507,   177,   178,
     597,   508,   509,  1246,   442,   510,   511,   179,   540,  1247,
     513,   514,   294,   295,  1248,   515,  1249,   516,   535,   543,
     544,   598,   545,   599,   546,    79,   547,   550,  1250,   551,
     552,   553,   554,   556,   557,   600,   180,    80,   181,   558,
     182,   559,   560,   622,   561,   623,   183,   627,   628,   626,
     633,   184,  1251,   629,   636,   601,   185,    81,    82,  1252,
     637,   443,   638,    83,   639,    84,  1158,   640,   641,   642,
     643,   644,   645,  1253,   646,   647,   562,   648,   649,   651,
     652,   653,   654,   656,   657,   602,   659,   658,   426,   660,
     661,  1254,   663,  1255,  1256,   662,   664,   563,   564,   603,
     668,     2,     3,   665,   565,   671,     4,   672,   670,    85,
      86,   673,   604,   682,   678,   679,    87,    88,   684,   690,
     686,   687,     5,   692,   688,   689,     6,   693,   695,     7,
     696,   725,   699,  1173,   722,   715,     8,    89,    90,   700,
     701,  1159,   723,   703,   726,   727,   704,   757,   705,  1240,
     706,     9,    91,    92,  1257,    10,    11,   754,    12,   755,
     756,   758,   771,    93,    13,   707,  1258,   724,  1259,   566,
     567,   568,    94,  1160,   569,   710,   712,   717,  1260,   718,
      14,   728,   570,   719,   759,   749,   748,   605,  1261,  1161,
      15,    16,   761,   750,   571,   572,   762,   763,   764,  1106,
     765,   766,  1162,  1163,   767,   751,   768,    17,  1174,   770,
     573,   574,   769,  1164,  1165,  1166,  1167,   772,   773,   774,
     775,   786,   969,    18,   849,   776,  1168,   850,  1107,   781,
     778,   782,   787,   788,   789,   790,   791,  1108,   575,   792,
    1175,   793,   981,  1109,   794,   795,   803,   804,   853,   805,
     806,   807,   854,   962,   808,   960,  1176,    19,    95,    96,
      97,  1110,   809,   810,   811,   812,    20,    21,   813,  1177,
    1178,    22,    23,   814,   815,   816,   966,   832,   851,   817,
    1179,  1180,  1181,  1182,   818,   819,   820,  1111,   821,   822,
     823,   824,   825,  1183,   852,  1112,   887,   888,   889,   890,
     891,  1067,   892,   893,   826,   827,   894,   895,   896,  1135,
     828,   897,   484,   898,   899,   900,   829,   901,   902,   903,
     856,   833,   904,    24,   857,   834,   835,   905,   909,   910,
     911,   912,   913,   836,   914,   915,  1113,   837,   916,   917,
     918,   839,   840,   919,   841,   920,   921,   922,   842,   923,
     924,   925,   843,   844,   926,  1114,   963,   845,   846,   927,
    1267,  1268,  1269,  1270,  1271,   855,  1272,  1273,   858,   859,
    1274,  1275,  1276,   860,   861,  1277,   862,  1278,  1279,  1280,
     863,  1281,  1282,  1283,   864,   958,  1284,   865,   866,   867,
     868,  1285,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     908,   930,   931,   932,   933,   934,   935,   965,   936,   937,
     938,   939,   940,   941,   942,   968,   943,   944,   945,   951,
     952,   953,   954,   955,   956,   957,   970,   964,   971,   961,
     972,   967,   973,   974,   975,   976,   977,   978,   979,   980,
     984,   985,   986,   996,   997,   998,  1009,  1010,  1011,   999,
    1000,  1002,  1003,  1004,  1006,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1031,  1032,  1033,  1034,  1035,  1037,  1038,  1036,  1039,  1041,
    1040,  1042,  1048,  1049,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1061,  1062,  1065,  1066,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1075,  1077,  1078,  1079,  1080,  1081,  1096,  1076,
    1097,  1102,  1103,  1104,  1105,  1134,  1117,  1082,  1118,  1119,
    1120,  1121,  1122,  1123,  1126,  1132,  1133,  1137,  1143,  1144,
    1146,  1138,  1140,  1145,  1147,  1148,  1149,  1150,  1234,  1151,
    1152,  1237,  1153,   518,  1154,  1157,  1289,   322,  1171,  1172,
    1186,  1187,  1188,  1189,  1142,  1325,  1008,  1190,  1191,  1192,
    1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1212,  1213,  1324,  1214,  1215,  1216,  1217,  1218,
    1219,  1236,  1323,  1301,  1235,  1241,   831,  1238,  1242,  1243,
    1264,  1265,  1266,  1299,  1288,  1302,   721,  1312,  1313,   537,
     753,  1318,   478,   780,  1319,  1300,   785,   848,  1320,   354,
    1296,   625,   632,   419,  1223,  1222,   698,  1297,  1298,   342,
       0,     0,     0,     0,     0,     0,     0,   709,     0,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   714
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-920))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     411,   328,   329,     1,     1,     1,   248,     1,   335,   248,
       4,   248,     8,     9,     1,   117,     1,     1,    11,   248,
      11,   246,    66,    19,     1,   250,     1,   946,   947,   948,
     248,    27,     1,     1,     1,    31,    32,     1,   365,   366,
     246,   248,    38,     1,   250,     1,    42,    43,     1,    45,
      44,    36,   246,    47,   381,    51,   250,    21,   248,   386,
     248,    46,     1,   248,    60,    61,   138,     1,   246,    65,
     397,   398,   250,   400,     1,   246,    72,   246,   247,   250,
      76,    77,   409,   410,    80,   138,   413,    83,    84,     1,
     248,     1,   248,     1,    52,    91,    90,     1,    25,   248,
       1,    97,    98,    78,   100,   101,   102,   103,   104,   107,
     107,    78,     1,   107,   216,    73,     1,    21,   105,   115,
      78,    48,   107,   107,    13,    52,   248,   123,   124,   125,
      40,   127,   248,   246,   130,   131,   105,   250,   134,    10,
     248,    12,     1,    53,    33,    34,   133,   111,   138,   145,
      39,   107,    41,   248,   107,    26,    66,     1,    68,    30,
      70,    71,   248,   140,   133,   209,    78,   248,   107,   213,
     246,   167,   249,   169,   501,   172,   140,   173,    88,   137,
       1,   177,   178,   179,   180,   181,   249,   140,    56,   185,
     186,   184,    36,   184,   249,   172,    85,    86,   194,   107,
     249,    22,    23,    92,    93,   132,   107,   111,    29,   249,
       1,    79,     1,    81,   141,   142,   172,   182,   183,   172,
       1,     1,   107,     3,   113,   114,     6,   223,   140,   225,
      74,   227,   249,   172,    25,   232,   140,   233,   232,   128,
     129,   249,   238,   249,    24,    25,   249,   243,   175,   247,
     139,   247,   138,   247,   122,   232,   224,    48,   246,   148,
     247,    52,   247,   107,   172,   109,   110,   249,    48,   237,
     247,   172,    52,    94,    95,    96,   232,   245,    99,   247,
     247,   140,   248,   247,   246,   248,   107,   172,   250,   247,
     224,   247,   246,    73,   247,    75,   250,    78,   119,   120,
     246,   249,     1,   237,   250,   232,   150,    87,   152,   153,
     245,   245,   249,   172,   135,   136,   107,   246,   107,   249,
     247,   250,   182,   183,   168,   249,    25,   107,   196,   197,
     796,   797,   798,   799,   800,   247,   244,   247,   249,   247,
       1,   132,   163,   244,   246,   234,   235,   236,   250,    48,
     249,   140,     1,    52,     1,   226,   249,   137,   247,   140,
     151,   205,   247,   246,   232,   692,   246,   250,    14,    15,
      16,   151,   246,   232,   249,    36,   250,   246,     1,   154,
     155,   250,   246,   172,   164,    46,   250,   202,   203,    36,
     248,    40,   249,   249,     1,   239,   240,   249,   249,   249,
     249,     8,     9,   247,    53,   246,   249,   249,   107,   249,
       1,   249,    19,   249,   249,   249,   249,    66,   829,    68,
      27,    70,    71,   214,    31,    32,   247,    74,   246,    52,
     249,    38,   249,   132,    25,    42,    43,     1,    45,    88,
       4,   232,   249,   249,    51,   249,   107,   249,   249,   249,
      73,   249,   151,    60,    61,    78,   247,    48,    65,   239,
     107,    52,   109,   110,   249,    72,   249,   247,   138,    76,
      77,   117,   249,    80,   182,   249,    83,    84,   249,   249,
      44,   249,   249,    47,    91,   249,   249,   249,   249,   249,
      97,    98,   819,   100,   101,   102,   103,   104,   249,   249,
     827,   828,   249,   150,   117,   152,   153,   249,   115,   249,
     249,   249,   249,   249,   137,   214,   123,   124,   125,   249,
     127,   168,   249,   130,   131,   249,    90,   134,   249,     1,
     249,     3,     5,   232,     6,   249,   249,   249,   145,   249,
     249,   132,   249,   107,   249,   158,   159,   160,   161,   162,
     141,   142,    24,    25,   249,   249,   249,   249,   205,   249,
     167,   249,   169,   249,    37,   249,   173,   249,   249,   249,
     177,   178,   179,   180,   181,   249,    48,   249,   185,   186,
      52,   249,   249,    56,   175,   249,   249,   194,   138,    62,
     249,   249,   239,   240,    67,   249,    69,   249,   249,   117,
     117,    73,   182,    75,   182,     1,   117,   117,    81,   117,
     182,   182,   117,   182,   182,    87,   223,    13,   225,   182,
     227,   182,   182,   249,   246,   249,   233,   246,   249,   138,
     182,   238,   105,   249,   117,   107,   243,    33,    34,   112,
     138,   232,   117,    39,   182,    41,    81,   182,   117,   138,
     182,   117,   117,   126,   117,   182,     1,   182,   182,   138,
     182,   117,   117,   117,   117,   137,   117,   138,   232,   117,
     182,   144,   249,   146,   147,   182,   182,    22,    23,   151,
     182,     0,     1,   249,    29,   182,     5,   182,   138,    85,
      86,   182,   164,   117,   182,   182,    92,    93,   138,   246,
     182,   182,    21,   249,   182,   182,    25,   249,   249,    28,
     249,   248,   246,    81,   182,   246,    35,   113,   114,   249,
     249,   156,   182,   249,   138,   138,   249,   138,   249,  1140,
     249,    50,   128,   129,   207,    54,    55,   182,    57,   182,
     182,   182,   117,   139,    63,   249,   219,   246,   221,    94,
      95,    96,   148,   188,    99,   249,   249,   249,   231,   249,
      79,   246,   107,   249,   182,   249,   246,   239,   241,   204,
      89,    90,   246,   249,   119,   120,   138,   182,   138,    20,
     138,   138,   217,   218,   138,   249,   138,   106,   156,   138,
     135,   136,   249,   228,   229,   230,   231,   138,   138,   246,
     246,   138,   117,   122,   138,   249,   241,   138,    49,   246,
     249,   249,   246,   246,   246,   246,   246,    58,   163,   246,
     188,   246,   117,    64,   246,   246,   246,   246,   138,   246,
     246,   246,   138,   138,   246,   182,   204,   156,   234,   235,
     236,    82,   246,   246,   246,   246,   165,   166,   246,   217,
     218,   170,   171,   246,   246,   246,   182,   246,   246,   249,
     228,   229,   230,   231,   249,   249,   249,   108,   249,   249,
     249,   249,   249,   241,   246,   116,   189,   190,   191,   192,
     193,   182,   195,   196,   249,   249,   199,   200,   201,   250,
     249,   204,   258,   206,   207,   208,   249,   210,   211,   212,
     246,   249,   215,   222,   246,   249,   249,   220,   189,   190,
     191,   192,   193,   249,   195,   196,   157,   249,   199,   200,
     201,   249,   249,   204,   249,   206,   207,   208,   249,   210,
     211,   212,   249,   249,   215,   176,   138,   249,   249,   220,
     189,   190,   191,   192,   193,   249,   195,   196,   246,   246,
     199,   200,   201,   246,   246,   204,   246,   206,   207,   208,
     246,   210,   211,   212,   246,   249,   215,   246,   246,   246,
     246,   220,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   138,   246,   246,
     246,   246,   246,   246,   246,   138,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   138,   246,   138,   249,
     138,   249,   246,   138,   249,   138,   246,   249,   138,   138,
     246,   246,   246,   246,   246,   246,   138,   138,   138,   249,
     249,   249,   249,   249,   249,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   138,   138,   246,   249,   138,   246,
     249,   246,   117,   117,   117,   117,   117,   117,   138,   117,
     117,   246,   138,   138,   138,   249,   138,   138,   138,   138,
     117,   138,   138,   246,   246,   246,   246,   246,   246,   138,
     246,   246,   246,   246,   246,   187,   246,   143,   246,   246,
     246,   246,   246,   143,   246,   246,   246,   246,   138,   182,
     138,   249,   249,   249,   138,   138,   249,   138,   117,   246,
     246,   138,   246,   296,   246,   246,  1156,    74,   246,   246,
     246,   246,   246,   246,   991,  1322,   738,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,  1317,   246,   246,   246,   246,   246,
     246,   246,  1315,  1233,  1135,   246,   576,   249,   246,   246,
     246,   246,   246,  1229,   246,   246,   469,   246,   246,   314,
     490,  1291,   249,   523,  1293,  1231,   531,   606,  1295,   127,
    1221,   348,   360,   186,  1088,  1086,   427,  1225,  1227,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   459
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   252,     0,     1,     5,    21,    25,    28,    35,    50,
      54,    55,    57,    63,    79,    89,    90,   106,   122,   156,
     165,   166,   170,   171,   222,   253,   258,   263,   281,   287,
     302,   322,   341,   355,   370,   377,   381,   391,   400,   423,
     433,   439,   443,   453,   516,   532,   553,   246,   247,   248,
     248,   323,   401,   434,   248,   444,   248,   517,   356,   424,
     342,   248,   248,   303,   371,   248,   248,   382,   392,   248,
       1,    36,    46,   107,   282,   283,   284,   285,   286,     1,
      13,    33,    34,    39,    41,    85,    86,    92,    93,   113,
     114,   128,   129,   139,   148,   234,   235,   236,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   138,   324,
     328,   138,   402,   406,   248,     1,    78,   440,   441,   442,
     248,     1,     8,     9,    19,    27,    31,    32,    38,    42,
      43,    45,    51,    60,    61,    65,    72,    76,    77,    80,
      83,    84,    91,    97,    98,   100,   101,   102,   103,   104,
     115,   123,   124,   125,   127,   130,   131,   134,   145,   167,
     169,   173,   177,   178,   179,   180,   181,   185,   186,   194,
     223,   225,   227,   233,   238,   243,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   508,   512,   513,
     514,   515,   248,   248,   248,   248,     1,   224,   237,   288,
     289,   290,   291,   292,   293,     1,   105,   133,   259,   260,
     261,   262,   138,   304,   308,   248,     1,    40,    53,    66,
      68,    70,    71,    88,   554,   555,   556,   557,   558,   559,
     560,   561,   562,     1,    36,    74,   107,   109,   110,   150,
     152,   153,   168,   205,   239,   240,   264,   265,   266,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     248,   248,     1,   107,   378,   379,   380,   246,   249,   249,
     249,   247,   283,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   247,   534,   248,   248,     1,    78,   140,   435,   436,
     437,   438,   249,   247,   441,     1,   107,   140,   172,   445,
     449,   450,   451,   452,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   509,   249,   505,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   247,   455,
       1,     4,    44,    47,    90,   107,   232,   518,   519,   520,
     521,   522,   526,   527,   528,     1,    25,    48,    52,   132,
     141,   142,   175,   232,   357,   358,   359,   360,   361,   362,
     363,   367,   368,   369,     1,   140,   172,   232,   425,   429,
     430,   431,   432,     1,    52,    73,    78,   137,   343,   347,
     348,   349,   353,   354,   246,   249,   249,   247,   289,   245,
     246,   249,   249,   247,   260,   248,     1,    21,   111,   140,
     372,   373,   374,   375,   376,   249,   249,   249,   249,   249,
     249,   249,   247,   555,   246,   249,   249,   249,   249,   249,
     249,   249,   267,   249,   249,   249,   249,   247,   265,     1,
     107,   172,   232,   383,   384,   385,   386,   387,     1,   107,
     172,   393,   394,   395,   396,   249,   247,   379,   138,   138,
     138,   246,   182,   117,   117,   182,   182,   117,   255,   255,
     117,   117,   182,   182,   117,   255,   182,   182,   182,   182,
     182,   246,     1,    22,    23,    29,    94,    95,    96,    99,
     107,   119,   120,   135,   136,   163,   325,   326,   327,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,     1,     3,     6,    24,    25,    48,    52,    73,    75,
      87,   107,   137,   151,   164,   239,   403,   404,   405,   407,
     408,   409,   410,   411,   412,   413,   417,   418,   419,   420,
     421,   422,   249,   249,   247,   436,   138,   246,   249,   249,
     446,   247,   450,   182,   255,   255,   117,   138,   117,   182,
     182,   117,   138,   182,   117,   117,   117,   182,   182,   182,
     255,   138,   182,   117,   117,   255,   117,   117,   138,   117,
     117,   182,   182,   249,   182,   249,   255,   255,   182,   255,
     138,   182,   182,   182,   182,   183,   182,   183,   182,   182,
     255,   255,   117,   257,   138,   255,   182,   182,   182,   182,
     246,   529,   249,   249,   523,   249,   249,   247,   519,   246,
     249,   249,   364,   249,   249,   249,   249,   249,   247,   358,
     249,   426,   249,   247,   430,   246,   344,   249,   249,   249,
     247,   348,   182,   182,   246,   248,   138,   138,   246,     1,
      25,    48,    52,   107,   132,   151,   214,   232,   305,   306,
     307,   309,   310,   311,   312,   313,   314,   318,   246,   249,
     249,   249,   247,   373,   182,   182,   182,   138,   182,   182,
     255,   246,   138,   182,   138,   138,   138,   138,   138,   249,
     138,   117,   138,   138,   246,   246,   249,   388,   249,   247,
     384,   246,   249,   397,   247,   394,   138,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   158,   159,   160,   161,
     162,   254,   255,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     247,   326,   246,   249,   249,   249,   249,   249,   414,   249,
     249,   249,   249,   249,   249,   249,   249,   247,   404,   138,
     138,   246,   246,   138,   138,   249,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   189,   190,   191,
     192,   193,   195,   196,   199,   200,   201,   204,   206,   207,
     208,   210,   211,   212,   215,   220,   510,   511,   246,   189,
     190,   191,   192,   193,   195,   196,   199,   200,   201,   204,
     206,   207,   208,   210,   211,   212,   215,   220,   506,   507,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,    14,    15,    16,   256,
     257,   246,   246,   246,   246,   246,   246,   246,   249,   255,
     182,   249,   138,   138,   246,   138,   182,   249,   138,   117,
     138,   138,   138,   246,   138,   249,   138,   246,   249,   138,
     138,   117,   351,   352,   246,   246,   246,     1,   107,   172,
     244,   294,   295,   296,   297,   298,   246,   246,   246,   249,
     249,   319,   249,   249,   249,   315,   249,   247,   306,   138,
     138,   138,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   154,   155,   268,
     269,   246,   246,   246,   246,   138,   249,   138,   246,   138,
     249,   246,   246,   254,   254,   254,   254,   254,   117,   117,
     255,   117,   117,   117,   117,   138,   117,   117,   255,   255,
     257,   246,   138,   202,   203,   138,   138,   182,   249,   138,
     138,   138,   138,   117,   138,   138,   138,   246,   246,   246,
     246,   246,   143,   447,   448,   246,   250,   246,   250,   256,
     256,   256,    11,   184,   530,   531,   246,   246,    11,   184,
     524,   525,   246,   246,   246,   246,    20,    49,    58,    64,
      82,   108,   116,   157,   176,   365,   366,   246,   246,   246,
     246,   246,   246,   143,   427,   428,   246,    66,   209,   213,
     345,   346,   246,   246,   187,   250,   350,   246,   249,   299,
     249,   247,   295,   138,   182,   249,   138,   138,   138,   249,
     138,   246,   246,   246,   246,   246,   250,   246,    81,   156,
     188,   204,   217,   218,   228,   229,   230,   231,   241,   389,
     390,   246,   246,    81,   156,   188,   204,   217,   218,   228,
     229,   230,   231,   241,   398,   399,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,    10,    12,    26,    30,   226,
     415,   416,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   250,   511,   507,   246,   250,   246,   250,   246,   250,
     246,   250,   246,   250,   117,   352,   246,   138,   249,   216,
     257,   246,   246,   246,     5,    37,    56,    62,    67,    69,
      81,   105,   112,   126,   144,   146,   147,   207,   219,   221,
     231,   241,   320,   321,   246,   246,   246,   189,   190,   191,
     192,   193,   195,   196,   199,   200,   201,   204,   206,   207,
     208,   210,   211,   212,   215,   220,   316,   317,   246,   269,
     246,   250,   246,   250,   246,   250,   448,   531,   525,   366,
     428,   346,   246,    56,    79,    81,   122,   196,   197,   232,
     300,   301,   246,   246,   246,   250,   246,   250,   390,   399,
     416,   246,   250,   321,   317,   301
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
#line 411 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 413 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 417 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 421 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 425 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 429 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 433 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 439 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 440 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 441 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 442 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 462 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 482 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 488 "ircd_parser.y"
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
#line 502 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 508 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 516 "ircd_parser.y"
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
#line 550 "ircd_parser.y"
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
#line 610 "ircd_parser.y"
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
#line 625 "ircd_parser.y"
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
#line 640 "ircd_parser.y"
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
#line 649 "ircd_parser.y"
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
#line 663 "ircd_parser.y"
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
#line 672 "ircd_parser.y"
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
#line 700 "ircd_parser.y"
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
#line 730 "ircd_parser.y"
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
#line 753 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 768 "ircd_parser.y"
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
#line 777 "ircd_parser.y"
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
#line 786 "ircd_parser.y"
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
#line 804 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 810 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 816 "ircd_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 821 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 833 "ircd_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 838 "ircd_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 841 "ircd_parser.y"
    {
  lsize = 0;
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 846 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 853 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 857 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 861 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 865 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 869 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 873 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 877 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 887 "ircd_parser.y"
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
#line 900 "ircd_parser.y"
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

  case 138:

/* Line 1806 of yacc.c  */
#line 987 "ircd_parser.y"
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
#line 999 "ircd_parser.y"
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1011 "ircd_parser.y"
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

  case 141:

/* Line 1806 of yacc.c  */
#line 1045 "ircd_parser.y"
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

  case 142:

/* Line 1806 of yacc.c  */
#line 1057 "ircd_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1068 "ircd_parser.y"
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

  case 144:

/* Line 1806 of yacc.c  */
#line 1110 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1126 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1130 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1134 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1138 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1142 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1146 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1150 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1154 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1158 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1162 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1166 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1170 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1204 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1211 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1215 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1219 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1227 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1231 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1243 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1247 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1251 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1255 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1259 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1263 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1267 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1271 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1275 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1279 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1289 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1296 "ircd_parser.y"
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

  case 210:

/* Line 1806 of yacc.c  */
#line 1356 "ircd_parser.y"
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
#line 1365 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1374 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1380 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1386 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1392 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1398 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1404 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1410 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1416 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1422 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1428 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1434 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1440 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1449 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 231:

/* Line 1806 of yacc.c  */
#line 1475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1479 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 240:

/* Line 1806 of yacc.c  */
#line 1489 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1494 "ircd_parser.y"
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

  case 245:

/* Line 1806 of yacc.c  */
#line 1508 "ircd_parser.y"
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

  case 246:

/* Line 1806 of yacc.c  */
#line 1528 "ircd_parser.y"
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
#line 1537 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1549 "ircd_parser.y"
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

  case 249:

/* Line 1806 of yacc.c  */
#line 1561 "ircd_parser.y"
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

  case 261:

/* Line 1806 of yacc.c  */
#line 1623 "ircd_parser.y"
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

  case 262:

/* Line 1806 of yacc.c  */
#line 1660 "ircd_parser.y"
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

  case 263:

/* Line 1806 of yacc.c  */
#line 1673 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1682 "ircd_parser.y"
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

  case 265:

/* Line 1806 of yacc.c  */
#line 1693 "ircd_parser.y"
    {
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1698 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1706 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1710 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1714 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1718 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1722 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1726 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1730 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1737 "ircd_parser.y"
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

  case 279:

/* Line 1806 of yacc.c  */
#line 1756 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1766 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1779 "ircd_parser.y"
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
#line 1786 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 289:

/* Line 1806 of yacc.c  */
#line 1798 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1807 "ircd_parser.y"
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

  case 291:

/* Line 1806 of yacc.c  */
#line 1822 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 297:

/* Line 1806 of yacc.c  */
#line 1840 "ircd_parser.y"
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

  case 298:

/* Line 1806 of yacc.c  */
#line 1855 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1863 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1874 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1883 "ircd_parser.y"
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

  case 308:

/* Line 1806 of yacc.c  */
#line 1905 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1912 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1920 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1924 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1928 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1932 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1936 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1940 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1944 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1948 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1952 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1961 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1981 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1987 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 1994 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1998 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2002 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2006 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2010 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2014 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2022 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2026 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2030 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2034 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2043 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->passwd = NULL;
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
#line 2058 "ircd_parser.y"
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

  case 367:

/* Line 1806 of yacc.c  */
#line 2196 "ircd_parser.y"
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
#line 2208 "ircd_parser.y"
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

  case 369:

/* Line 1806 of yacc.c  */
#line 2220 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2229 "ircd_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2255 "ircd_parser.y"
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

  case 372:

/* Line 1806 of yacc.c  */
#line 2273 "ircd_parser.y"
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

  case 373:

/* Line 1806 of yacc.c  */
#line 2291 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2297 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2301 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2309 "ircd_parser.y"
    {
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2314 "ircd_parser.y"
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

  case 381:

/* Line 1806 of yacc.c  */
#line 2324 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2328 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2332 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2336 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2342 "ircd_parser.y"
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

  case 386:

/* Line 1806 of yacc.c  */
#line 2383 "ircd_parser.y"
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

  case 387:

/* Line 1806 of yacc.c  */
#line 2394 "ircd_parser.y"
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

  case 388:

/* Line 1806 of yacc.c  */
#line 2407 "ircd_parser.y"
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

  case 389:

/* Line 1806 of yacc.c  */
#line 2420 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 2429 "ircd_parser.y"
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

  case 391:

/* Line 1806 of yacc.c  */
#line 2464 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2471 "ircd_parser.y"
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

  case 393:

/* Line 1806 of yacc.c  */
#line 2527 "ircd_parser.y"
    {
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2532 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 2541 "ircd_parser.y"
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

  case 405:

/* Line 1806 of yacc.c  */
#line 2560 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 406:

/* Line 1806 of yacc.c  */
#line 2569 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 2573 "ircd_parser.y"
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

  case 413:

/* Line 1806 of yacc.c  */
#line 2595 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 2601 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 2615 "ircd_parser.y"
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

  case 421:

/* Line 1806 of yacc.c  */
#line 2633 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 2640 "ircd_parser.y"
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

  case 423:

/* Line 1806 of yacc.c  */
#line 2680 "ircd_parser.y"
    {
}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 2685 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 2694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 2700 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2745 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2750 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2755 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2760 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2765 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2770 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2775 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2780 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2785 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2790 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2795 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2800 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2805 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2810 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2815 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2820 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2825 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2830 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2836 "ircd_parser.y"
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

  case 513:

/* Line 1806 of yacc.c  */
#line 2847 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2852 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2861 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2866 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2871 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2876 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2881 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2886 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2889 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2894 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2902 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2907 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2912 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2917 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2922 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2927 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2932 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2937 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2942 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2953 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2958 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2963 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2972 "ircd_parser.y"
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

  case 537:

/* Line 1806 of yacc.c  */
#line 3004 "ircd_parser.y"
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

  case 538:

/* Line 1806 of yacc.c  */
#line 3022 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3027 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3036 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3050 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3055 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3066 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3069 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3072 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3081 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3087 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3090 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3093 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3096 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3099 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3102 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3105 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3108 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3111 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3114 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3117 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3120 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3125 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3131 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3134 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3140 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3143 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3146 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3149 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3155 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3158 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3161 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3164 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3167 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3173 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3176 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3179 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3182 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3185 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3190 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3195 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3200 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3205 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3221 "ircd_parser.y"
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

  case 605:

/* Line 1806 of yacc.c  */
#line 3247 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3253 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:

/* Line 1806 of yacc.c  */
#line 3259 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 3265 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 612:

/* Line 1806 of yacc.c  */
#line 3269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 613:

/* Line 1806 of yacc.c  */
#line 3275 "ircd_parser.y"
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

  case 614:

/* Line 1806 of yacc.c  */
#line 3309 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 3318 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 3322 "ircd_parser.y"
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

  case 619:

/* Line 1806 of yacc.c  */
#line 3369 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3397 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3402 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3407 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3412 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3417 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3422 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3427 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3432 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3437 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3442 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3447 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3452 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3457 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3462 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 3467 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3472 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3477 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3482 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 672:

/* Line 1806 of yacc.c  */
#line 3501 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 673:

/* Line 1806 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 674:

/* Line 1806 of yacc.c  */
#line 3513 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 675:

/* Line 1806 of yacc.c  */
#line 3522 "ircd_parser.y"
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

  case 676:

/* Line 1806 of yacc.c  */
#line 3536 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 677:

/* Line 1806 of yacc.c  */
#line 3542 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 678:

/* Line 1806 of yacc.c  */
#line 3548 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7868 "ircd_parser.c"
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



