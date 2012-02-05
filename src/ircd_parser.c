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
#define YYLAST   1253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1317

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
     360,   362,   364,   366,   367,   374,   377,   379,   381,   383,
     385,   387,   389,   391,   393,   395,   398,   403,   408,   413,
     418,   423,   428,   429,   435,   439,   441,   443,   445,   447,
     449,   451,   453,   455,   457,   459,   461,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   480,   486,   490,   492,
     494,   496,   498,   500,   502,   504,   506,   508,   510,   512,
     514,   516,   518,   520,   522,   524,   526,   528,   529,   536,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   557,
     559,   561,   563,   565,   567,   570,   575,   580,   585,   590,
     595,   600,   605,   610,   615,   620,   625,   630,   635,   636,
     643,   644,   650,   654,   656,   658,   660,   662,   665,   667,
     669,   671,   673,   675,   678,   679,   685,   689,   691,   693,
     697,   702,   707,   708,   715,   718,   720,   722,   724,   726,
     728,   730,   732,   734,   736,   739,   744,   749,   754,   759,
     760,   766,   770,   772,   774,   776,   778,   780,   782,   784,
     786,   788,   790,   795,   800,   805,   806,   813,   816,   818,
     820,   822,   824,   827,   832,   837,   842,   848,   851,   853,
     855,   857,   862,   863,   870,   873,   875,   877,   879,   881,
     884,   889,   894,   895,   901,   905,   907,   909,   911,   913,
     915,   917,   919,   921,   923,   925,   927,   929,   930,   937,
     940,   942,   944,   946,   949,   954,   955,   961,   965,   967,
     969,   971,   973,   975,   977,   979,   981,   983,   985,   987,
     989,   990,   997,  1000,  1002,  1004,  1006,  1008,  1010,  1012,
    1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,  1030,  1033,
    1038,  1043,  1048,  1053,  1058,  1063,  1068,  1073,  1074,  1080,
    1084,  1086,  1088,  1090,  1092,  1094,  1096,  1101,  1106,  1111,
    1116,  1121,  1126,  1127,  1134,  1135,  1141,  1145,  1147,  1149,
    1152,  1154,  1156,  1158,  1160,  1162,  1167,  1172,  1173,  1180,
    1183,  1185,  1187,  1189,  1191,  1196,  1201,  1207,  1210,  1212,
    1214,  1216,  1221,  1222,  1229,  1230,  1236,  1240,  1242,  1244,
    1247,  1249,  1251,  1253,  1255,  1257,  1262,  1267,  1273,  1276,
    1278,  1280,  1282,  1284,  1286,  1288,  1290,  1292,  1294,  1296,
    1298,  1300,  1302,  1304,  1306,  1308,  1310,  1312,  1314,  1316,
    1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,
    1338,  1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,
    1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,
    1378,  1380,  1382,  1384,  1386,  1388,  1393,  1398,  1403,  1408,
    1413,  1418,  1423,  1428,  1433,  1438,  1443,  1448,  1453,  1458,
    1463,  1468,  1473,  1478,  1483,  1488,  1493,  1498,  1503,  1508,
    1513,  1518,  1523,  1528,  1533,  1538,  1543,  1548,  1553,  1558,
    1563,  1568,  1573,  1578,  1583,  1588,  1593,  1598,  1603,  1608,
    1613,  1618,  1623,  1628,  1633,  1638,  1639,  1645,  1649,  1651,
    1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,
    1673,  1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1690,
    1696,  1700,  1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,
    1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,
    1738,  1740,  1745,  1750,  1755,  1760,  1761,  1768,  1771,  1773,
    1775,  1777,  1779,  1781,  1783,  1785,  1787,  1792,  1797,  1798,
    1804,  1808,  1810,  1812,  1814,  1819,  1824,  1825,  1831,  1835,
    1837,  1839,  1841,  1847,  1850,  1852,  1854,  1856,  1858,  1860,
    1862,  1864,  1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,
    1882,  1884,  1886,  1888,  1890,  1895,  1900,  1905,  1910,  1915,
    1920,  1925,  1930,  1935,  1940,  1945,  1950,  1955,  1960,  1965,
    1970,  1975,  1980,  1986,  1989,  1991,  1993,  1995,  1997,  1999,
    2001,  2003,  2005,  2007,  2012,  2017,  2022,  2027,  2032,  2037
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     252,     0,    -1,    -1,   252,   253,    -1,   281,    -1,   287,
      -1,   302,    -1,   526,    -1,   320,    -1,   337,    -1,   351,
      -1,   263,    -1,   547,    -1,   366,    -1,   373,    -1,   377,
      -1,   387,    -1,   396,    -1,   417,    -1,   427,    -1,   433,
      -1,   447,    -1,   510,    -1,   437,    -1,   258,    -1,     1,
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
      81,    -1,    79,    -1,   196,    -1,    -1,   122,   303,   248,
     304,   247,   246,    -1,   304,   305,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   312,    -1,   311,    -1,   309,
      -1,   310,    -1,   316,    -1,     1,   246,    -1,   107,   249,
     138,   246,    -1,   232,   249,   138,   246,    -1,   132,   249,
     138,   246,    -1,    48,   249,   182,   246,    -1,   151,   249,
     138,   246,    -1,    25,   249,   138,   246,    -1,    -1,   214,
     313,   249,   314,   246,    -1,   314,   250,   315,    -1,   315,
      -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,   196,
      -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,   215,
      -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,   201,
      -1,   220,    -1,   190,    -1,   191,    -1,   204,    -1,    -1,
      52,   317,   249,   318,   246,    -1,   318,   250,   319,    -1,
     319,    -1,    62,    -1,   146,    -1,    81,    -1,   231,    -1,
     241,    -1,    56,    -1,    37,    -1,   221,    -1,   144,    -1,
       5,    -1,    67,    -1,   112,    -1,   207,    -1,   219,    -1,
     126,    -1,    69,    -1,   147,    -1,   105,    -1,    -1,    25,
     321,   248,   322,   247,   246,    -1,   322,   323,    -1,   323,
      -1,   324,    -1,   334,    -1,   335,    -1,   325,    -1,   326,
      -1,   336,    -1,   327,    -1,   328,    -1,   329,    -1,   330,
      -1,   331,    -1,   332,    -1,   333,    -1,     1,   246,    -1,
     107,   249,   138,   246,    -1,   135,   249,   255,   246,    -1,
     136,   249,   255,   246,    -1,   120,   249,   117,   246,    -1,
      29,   249,   255,   246,    -1,    99,   249,   117,   246,    -1,
      94,   249,   117,   246,    -1,    96,   249,   117,   246,    -1,
      95,   249,   117,   246,    -1,   163,   249,   257,   246,    -1,
      22,   249,   117,   246,    -1,    23,   249,   117,   246,    -1,
     119,   249,   117,   246,    -1,    -1,    89,   338,   248,   343,
     247,   246,    -1,    -1,    52,   340,   249,   341,   246,    -1,
     341,   250,   342,    -1,   342,    -1,   213,    -1,    66,    -1,
     209,    -1,   343,   344,    -1,   344,    -1,   345,    -1,   339,
      -1,   349,    -1,   350,    -1,     1,   246,    -1,    -1,   137,
     249,   347,   346,   246,    -1,   347,   250,   348,    -1,   348,
      -1,   117,    -1,   117,   187,   117,    -1,    78,   249,   138,
     246,    -1,    73,   249,   138,   246,    -1,    -1,    63,   352,
     248,   353,   247,   246,    -1,   353,   354,    -1,   354,    -1,
     355,    -1,   356,    -1,   357,    -1,   359,    -1,   363,    -1,
     364,    -1,   365,    -1,   358,    -1,     1,   246,    -1,   232,
     249,   138,   246,    -1,   132,   249,   138,   246,    -1,    25,
     249,   138,   246,    -1,    48,   249,   182,   246,    -1,    -1,
      52,   360,   249,   361,   246,    -1,   361,   250,   362,    -1,
     362,    -1,   176,    -1,    49,    -1,    82,    -1,    64,    -1,
      20,    -1,   116,    -1,    58,    -1,   157,    -1,   108,    -1,
     175,   249,   138,   246,    -1,   142,   249,   138,   246,    -1,
     141,   249,   117,   246,    -1,    -1,   156,   367,   248,   368,
     247,   246,    -1,   368,   369,    -1,   369,    -1,   370,    -1,
     371,    -1,   372,    -1,     1,   246,    -1,   140,   249,   138,
     246,    -1,    21,   249,   138,   246,    -1,   111,   249,   138,
     246,    -1,   222,   248,   374,   247,   246,    -1,   374,   375,
      -1,   375,    -1,   376,    -1,     1,    -1,   107,   249,   138,
     246,    -1,    -1,   170,   378,   248,   379,   247,   246,    -1,
     379,   380,    -1,   380,    -1,   381,    -1,   382,    -1,   383,
      -1,     1,   246,    -1,   107,   249,   138,   246,    -1,   232,
     249,   138,   246,    -1,    -1,   172,   384,   249,   385,   246,
      -1,   385,   250,   386,    -1,   386,    -1,    81,    -1,   228,
      -1,   231,    -1,   241,    -1,   229,    -1,   218,    -1,   156,
      -1,   230,    -1,   217,    -1,   204,    -1,   188,    -1,    -1,
     171,   388,   248,   389,   247,   246,    -1,   389,   390,    -1,
     390,    -1,   391,    -1,   392,    -1,     1,   246,    -1,   107,
     249,   138,   246,    -1,    -1,   172,   393,   249,   394,   246,
      -1,   394,   250,   395,    -1,   395,    -1,    81,    -1,   228,
      -1,   231,    -1,   241,    -1,   229,    -1,   218,    -1,   156,
      -1,   230,    -1,   217,    -1,   204,    -1,   188,    -1,    -1,
      28,   397,   248,   398,   247,   246,    -1,   398,   399,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,   406,    -1,   405,    -1,   407,    -1,   413,    -1,
     414,    -1,   415,    -1,   412,    -1,   411,    -1,   416,    -1,
       1,   246,    -1,   107,   249,   138,   246,    -1,    73,   249,
     138,   246,    -1,   239,   249,   138,   246,    -1,   164,   249,
     138,   246,    -1,     3,   249,   138,   246,    -1,   137,   249,
     117,   246,    -1,     6,   249,   202,   246,    -1,     6,   249,
     203,   246,    -1,    -1,    52,   408,   249,   409,   246,    -1,
     409,   250,   410,    -1,   410,    -1,    26,    -1,    30,    -1,
      10,    -1,    12,    -1,   226,    -1,   151,   249,   138,   246,
      -1,    48,   249,   182,   246,    -1,    75,   249,   138,   246,
      -1,    87,   249,   138,   246,    -1,    25,   249,   138,   246,
      -1,    24,   249,   138,   246,    -1,    -1,    79,   418,   248,
     423,   247,   246,    -1,    -1,   172,   420,   249,   421,   246,
      -1,   421,   250,   422,    -1,   422,    -1,   143,    -1,   423,
     424,    -1,   424,    -1,   425,    -1,   426,    -1,   419,    -1,
       1,    -1,   232,   249,   138,   246,    -1,   140,   249,   138,
     246,    -1,    -1,    35,   428,   248,   429,   247,   246,    -1,
     429,   430,    -1,   430,    -1,   431,    -1,   432,    -1,     1,
      -1,    78,   249,   138,   246,    -1,   140,   249,   138,   246,
      -1,    50,   248,   434,   247,   246,    -1,   434,   435,    -1,
     435,    -1,   436,    -1,     1,    -1,    78,   249,   138,   246,
      -1,    -1,    54,   438,   248,   443,   247,   246,    -1,    -1,
     172,   440,   249,   441,   246,    -1,   441,   250,   442,    -1,
     442,    -1,   143,    -1,   443,   444,    -1,   444,    -1,   445,
      -1,   446,    -1,   439,    -1,     1,    -1,   107,   249,   138,
     246,    -1,   140,   249,   138,   246,    -1,    55,   248,   448,
     247,   246,    -1,   448,   449,    -1,   449,    -1,   457,    -1,
     458,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     464,    -1,   465,    -1,   466,    -1,   467,    -1,   456,    -1,
     469,    -1,   470,    -1,   471,    -1,   472,    -1,   487,    -1,
     474,    -1,   476,    -1,   478,    -1,   477,    -1,   481,    -1,
     475,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     486,    -1,   502,    -1,   488,    -1,   492,    -1,   493,    -1,
     498,    -1,   479,    -1,   480,    -1,   508,    -1,   506,    -1,
     507,    -1,   489,    -1,   459,    -1,   490,    -1,   491,    -1,
     509,    -1,   497,    -1,   468,    -1,   495,    -1,   496,    -1,
     455,    -1,   451,    -1,   452,    -1,   453,    -1,   454,    -1,
     473,    -1,   450,    -1,   494,    -1,     1,    -1,   101,   249,
     117,   246,    -1,    60,   249,   117,   246,    -1,    61,   249,
     117,   246,    -1,   238,   249,   182,   246,    -1,   145,   249,
     255,   246,    -1,   169,   249,   182,   246,    -1,    80,   249,
     255,   246,    -1,    72,   249,   182,   246,    -1,    76,   249,
     182,   246,    -1,    42,   249,   182,   246,    -1,    51,   249,
     182,   246,    -1,     8,   249,   182,   246,    -1,    98,   249,
     255,   246,    -1,    97,   249,   117,   246,    -1,    91,   249,
     117,   246,    -1,     9,   249,   255,   246,    -1,   186,   249,
     255,   246,    -1,   185,   249,   255,   246,    -1,    65,   249,
     117,   246,    -1,    84,   249,   182,   246,    -1,    83,   249,
     138,   246,    -1,    77,   249,   182,   246,    -1,   243,   249,
     182,   246,    -1,   177,   249,   182,   246,    -1,   180,   249,
     182,   246,    -1,   181,   249,   182,   246,    -1,   179,   249,
     182,   246,    -1,   179,   249,   183,   246,    -1,   178,   249,
     182,   246,    -1,   178,   249,   183,   246,    -1,   130,   249,
     255,   246,    -1,    19,   249,   255,   246,    -1,   123,   249,
     182,   246,    -1,   131,   249,   255,   246,    -1,   173,   249,
     182,   246,    -1,   115,   249,   182,   246,    -1,   227,   249,
     182,   246,    -1,   125,   249,   182,   246,    -1,   102,   249,
     138,   246,    -1,    43,   249,   117,   246,    -1,   100,   249,
     117,   246,    -1,   167,   249,   138,   246,    -1,    31,   249,
     138,   246,    -1,    27,   249,   117,   246,    -1,   233,   249,
     182,   246,    -1,    45,   249,   138,   246,    -1,   223,   249,
     138,   246,    -1,   134,   249,   182,   246,    -1,    38,   249,
     182,   246,    -1,   225,   249,   255,   246,    -1,    -1,   127,
     499,   249,   500,   246,    -1,   500,   250,   501,    -1,   501,
      -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,   196,
      -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,   215,
      -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,   201,
      -1,   220,    -1,   190,    -1,   191,    -1,   204,    -1,    -1,
     124,   503,   249,   504,   246,    -1,   504,   250,   505,    -1,
     505,    -1,   189,    -1,   192,    -1,   193,    -1,   195,    -1,
     196,    -1,   200,    -1,   211,    -1,   206,    -1,   208,    -1,
     215,    -1,   212,    -1,   199,    -1,   207,    -1,   210,    -1,
     201,    -1,   220,    -1,   190,    -1,   191,    -1,   204,    -1,
     103,   249,   117,   246,    -1,   104,   249,   117,   246,    -1,
      32,   249,   117,   246,    -1,   194,   249,   257,   246,    -1,
      -1,    57,   511,   248,   512,   247,   246,    -1,   512,   513,
      -1,   513,    -1,   514,    -1,   515,    -1,   516,    -1,   520,
      -1,   521,    -1,   522,    -1,     1,    -1,    47,   249,   182,
     246,    -1,    44,   249,   255,   246,    -1,    -1,    90,   517,
     249,   518,   246,    -1,   518,   250,   519,    -1,   519,    -1,
     184,    -1,    11,    -1,   232,   249,   138,   246,    -1,   107,
     249,   138,   246,    -1,    -1,     4,   523,   249,   524,   246,
      -1,   524,   250,   525,    -1,   525,    -1,   184,    -1,    11,
      -1,    21,   248,   527,   247,   246,    -1,   527,   528,    -1,
     528,    -1,   531,    -1,   532,    -1,   533,    -1,   534,    -1,
     539,    -1,   535,    -1,   536,    -1,   537,    -1,   538,    -1,
     540,    -1,   541,    -1,   542,    -1,   530,    -1,   543,    -1,
     544,    -1,   545,    -1,   546,    -1,   529,    -1,     1,    -1,
      39,   249,   182,   246,    -1,   148,   249,   182,   246,    -1,
      41,   249,   182,   246,    -1,   234,   249,   182,   246,    -1,
     235,   249,   182,   246,    -1,   236,   249,   182,   246,    -1,
      85,   249,   255,   246,    -1,    86,   249,   255,   246,    -1,
      93,   249,   117,   246,    -1,   139,   249,   182,   246,    -1,
      92,   249,   117,   246,    -1,    34,   249,   117,   246,    -1,
      33,   249,   117,   246,    -1,   113,   249,   182,   246,    -1,
     114,   249,   182,   246,    -1,    13,   249,   182,   246,    -1,
     128,   249,   117,   246,    -1,   129,   249,   255,   246,    -1,
     165,   248,   548,   247,   246,    -1,   548,   549,    -1,   549,
      -1,   550,    -1,   551,    -1,   553,    -1,   555,    -1,   554,
      -1,   552,    -1,   556,    -1,     1,    -1,    53,   249,   182,
     246,    -1,    71,   249,   182,   246,    -1,    68,   249,   138,
     246,    -1,    88,   249,   255,   246,    -1,    66,   249,   182,
     246,    -1,    40,   249,   182,   246,    -1,    70,   249,   182,
     246,    -1
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
     868,   872,   876,   887,   886,   984,   984,   985,   985,   985,
     986,   986,   986,   987,   987,   987,   989,  1001,  1038,  1050,
    1061,  1103,  1113,  1112,  1118,  1118,  1119,  1123,  1127,  1131,
    1135,  1139,  1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,
    1175,  1179,  1183,  1187,  1191,  1198,  1197,  1203,  1203,  1204,
    1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,
    1248,  1252,  1256,  1260,  1264,  1268,  1272,  1283,  1282,  1332,
    1332,  1333,  1334,  1334,  1335,  1336,  1337,  1338,  1339,  1340,
    1341,  1342,  1343,  1344,  1345,  1347,  1356,  1362,  1368,  1374,
    1380,  1386,  1392,  1398,  1404,  1410,  1416,  1422,  1432,  1431,
    1448,  1447,  1452,  1452,  1453,  1457,  1461,  1469,  1469,  1470,
    1470,  1470,  1470,  1470,  1472,  1472,  1474,  1474,  1476,  1490,
    1510,  1519,  1532,  1531,  1600,  1600,  1601,  1601,  1601,  1601,
    1602,  1602,  1602,  1603,  1603,  1605,  1642,  1655,  1664,  1676,
    1675,  1679,  1679,  1680,  1684,  1688,  1692,  1696,  1700,  1704,
    1708,  1712,  1719,  1738,  1748,  1762,  1761,  1777,  1777,  1778,
    1778,  1778,  1778,  1780,  1789,  1804,  1817,  1819,  1819,  1820,
    1820,  1822,  1838,  1837,  1853,  1853,  1854,  1854,  1854,  1854,
    1856,  1865,  1888,  1887,  1893,  1893,  1894,  1898,  1902,  1906,
    1910,  1914,  1918,  1922,  1926,  1930,  1934,  1944,  1943,  1960,
    1960,  1961,  1961,  1961,  1963,  1970,  1969,  1975,  1975,  1976,
    1980,  1984,  1988,  1992,  1996,  2000,  2004,  2008,  2012,  2016,
    2026,  2025,  2168,  2168,  2169,  2169,  2169,  2170,  2170,  2171,
    2171,  2172,  2172,  2172,  2173,  2173,  2174,  2174,  2175,  2177,
    2189,  2198,  2224,  2242,  2260,  2266,  2270,  2279,  2278,  2282,
    2282,  2283,  2293,  2297,  2301,  2305,  2311,  2352,  2363,  2376,
    2389,  2398,  2434,  2433,  2497,  2496,  2500,  2500,  2501,  2507,
    2507,  2508,  2508,  2508,  2508,  2510,  2529,  2539,  2538,  2561,
    2561,  2562,  2562,  2562,  2564,  2570,  2579,  2581,  2581,  2582,
    2582,  2584,  2603,  2602,  2650,  2649,  2653,  2653,  2654,  2660,
    2660,  2661,  2661,  2661,  2661,  2663,  2669,  2678,  2681,  2681,
    2682,  2682,  2683,  2683,  2684,  2684,  2685,  2685,  2686,  2686,
    2687,  2687,  2688,  2688,  2689,  2689,  2690,  2690,  2691,  2691,
    2692,  2692,  2693,  2693,  2694,  2694,  2695,  2696,  2696,  2697,
    2697,  2698,  2698,  2699,  2699,  2700,  2700,  2701,  2701,  2702,
    2703,  2703,  2704,  2704,  2705,  2706,  2707,  2707,  2708,  2708,
    2709,  2709,  2710,  2710,  2711,  2714,  2719,  2724,  2729,  2734,
    2739,  2744,  2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,
    2789,  2794,  2799,  2805,  2816,  2821,  2830,  2835,  2840,  2845,
    2850,  2855,  2858,  2863,  2866,  2871,  2876,  2881,  2886,  2891,
    2896,  2901,  2906,  2911,  2922,  2927,  2932,  2941,  2973,  2991,
    2996,  3005,  3014,  3019,  3024,  3030,  3029,  3034,  3034,  3035,
    3038,  3041,  3044,  3047,  3050,  3053,  3056,  3059,  3062,  3065,
    3068,  3071,  3074,  3077,  3080,  3083,  3086,  3089,  3095,  3094,
    3099,  3099,  3100,  3103,  3106,  3109,  3112,  3115,  3118,  3121,
    3124,  3127,  3130,  3133,  3136,  3139,  3142,  3145,  3148,  3151,
    3154,  3159,  3164,  3169,  3174,  3184,  3183,  3207,  3207,  3208,
    3209,  3210,  3211,  3212,  3213,  3214,  3216,  3222,  3229,  3228,
    3233,  3233,  3234,  3238,  3244,  3278,  3288,  3287,  3337,  3337,
    3338,  3342,  3351,  3354,  3354,  3355,  3355,  3356,  3356,  3357,
    3357,  3358,  3358,  3359,  3359,  3360,  3361,  3361,  3362,  3362,
    3363,  3363,  3364,  3364,  3366,  3371,  3376,  3381,  3386,  3391,
    3396,  3401,  3406,  3411,  3416,  3421,  3426,  3431,  3436,  3441,
    3446,  3451,  3459,  3462,  3462,  3463,  3463,  3464,  3465,  3466,
    3466,  3467,  3468,  3470,  3476,  3482,  3491,  3505,  3511,  3517
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
     301,   301,   301,   303,   302,   304,   304,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   307,   308,   309,
     310,   311,   313,   312,   314,   314,   315,   315,   315,   315,
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
     386,   386,   386,   386,   386,   386,   386,   388,   387,   389,
     389,   390,   390,   390,   391,   393,   392,   394,   394,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     397,   396,   398,   398,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   400,
     401,   402,   403,   404,   405,   406,   406,   408,   407,   409,
     409,   410,   410,   410,   410,   410,   411,   412,   413,   414,
     415,   416,   418,   417,   420,   419,   421,   421,   422,   423,
     423,   424,   424,   424,   424,   425,   426,   428,   427,   429,
     429,   430,   430,   430,   431,   432,   433,   434,   434,   435,
     435,   436,   438,   437,   440,   439,   441,   441,   442,   443,
     443,   444,   444,   444,   444,   445,   446,   447,   448,   448,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   476,   477,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   499,   498,   500,   500,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   503,   502,
     504,   504,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   506,   507,   508,   509,   511,   510,   512,   512,   513,
     513,   513,   513,   513,   513,   513,   514,   515,   517,   516,
     518,   518,   519,   519,   520,   521,   523,   522,   524,   524,
     525,   525,   526,   527,   527,   528,   528,   528,   528,   528,
     528,   528,   528,   528,   528,   528,   528,   528,   528,   528,
     528,   528,   528,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   548,   549,   549,   549,   549,   549,
     549,   549,   549,   550,   551,   552,   553,   554,   555,   556
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
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     2,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
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
       2,     0,     1,     0,     0,     0,   187,   340,   397,     0,
     412,     0,   585,   242,   382,   218,     0,     0,   123,   275,
       0,     0,   292,   317,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   633,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     632,   627,   615,   616,   617,   618,   620,   621,   622,   623,
     619,   624,   625,   626,   628,   629,   630,   631,     0,     0,
       0,   410,     0,     0,   408,   409,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   558,     0,
     535,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   429,   482,   477,   478,   479,   480,   476,
     440,   430,   431,   468,   432,   433,   434,   435,   436,   437,
     438,   439,   473,   441,   442,   443,   444,   481,   446,   451,
     447,   449,   448,   462,   463,   450,   452,   453,   454,   455,
     456,   445,   458,   467,   469,   470,   459,   460,   483,   474,
     475,   472,   461,   457,   465,   466,   464,   471,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
     662,     0,     0,     0,     0,     0,     0,     0,     0,   654,
     655,   656,   660,   657,   659,   658,   661,     0,     0,     0,
       0,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,    51,    63,    62,    59,    52,    61,    55,    56,    57,
      53,    60,    58,    54,     0,     0,   290,     0,     0,   288,
     289,    88,     0,     0,     0,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   190,   191,   194,   195,   197,   198,   199,   200,
     201,   202,   203,   192,   193,   196,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   343,   344,   345,   346,   347,   348,   350,   349,
     351,   356,   355,   352,   353,   354,   357,   403,     0,     0,
       0,   400,   401,   402,     0,     0,   407,   424,     0,     0,
     414,   423,     0,   420,   421,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   428,   595,   606,     0,     0,   598,     0,     0,     0,
     588,   589,   590,   591,   592,   593,   594,     0,     0,     0,
     259,     0,     0,     0,     0,     0,     0,   245,   246,   247,
     248,   253,   249,   250,   251,   252,   394,     0,   384,     0,
     393,     0,   390,   391,   392,     0,   220,     0,     0,     0,
     230,     0,   228,   229,   231,   232,    98,     0,     0,     0,
      93,     0,    46,     0,     0,     0,    42,     0,     0,     0,
     165,     0,     0,     0,   142,     0,     0,   126,   127,   128,
     129,   132,   133,   131,   130,   134,     0,     0,     0,     0,
       0,   278,   279,   280,   281,     0,     0,     0,     0,     0,
       0,     0,     0,   653,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,     0,
       0,   302,     0,     0,   295,   296,   297,   298,     0,     0,
     325,     0,   320,   321,   322,     0,     0,   287,     0,     0,
       0,    82,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,   358,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   342,     0,     0,     0,   399,     0,
     406,     0,     0,     0,     0,   419,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,   427,     0,     0,     0,     0,     0,     0,
       0,   587,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   244,     0,     0,     0,     0,   389,   233,     0,
       0,     0,     0,     0,   227,     0,     0,    92,     0,     0,
       0,    41,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,   282,     0,     0,     0,     0,   277,     0,
       0,     0,     0,     0,     0,     0,   652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
     299,     0,     0,     0,     0,   294,   323,     0,     0,     0,
     319,     0,   286,    91,    90,    89,   649,   646,   645,   634,
     636,    27,    27,    27,    27,    27,    29,    28,   640,   641,
     644,   642,   647,   648,   650,   651,   643,   635,   637,   638,
     639,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     341,     0,     0,   398,   411,     0,     0,     0,   413,   496,
     500,   516,   528,   527,   583,   533,   494,   524,   530,   495,
     486,   487,   503,   492,   493,   506,   491,   505,   504,   499,
     498,   497,   525,   485,   523,   581,   582,   520,   517,   562,
     578,   579,   563,   564,   565,   566,   573,   567,   576,   580,
     569,   574,   570,   575,   568,   572,   571,   577,     0,   561,
     522,   539,   555,   556,   540,   541,   542,   543,   550,   544,
     553,   557,   546,   551,   547,   552,   545,   549,   548,   554,
       0,   538,   515,   518,   532,   489,   526,   490,   519,   508,
     513,   514,   511,   512,   509,   510,   502,   501,    35,    35,
      35,    37,    36,   584,   531,   534,   521,   529,   488,   507,
       0,     0,     0,     0,     0,     0,   586,     0,     0,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,   383,
       0,     0,     0,   238,   234,   237,   219,   100,    99,     0,
       0,   112,     0,     0,   104,   105,   107,   106,    47,    48,
       0,     0,     0,     0,     0,     0,     0,     0,   124,     0,
       0,     0,   276,   668,   663,   667,   665,   669,   664,   666,
      75,    81,    73,    77,    76,    72,    71,    69,    70,     0,
      68,    74,    80,    78,    79,     0,     0,     0,   293,     0,
       0,   318,   291,    30,    31,    32,    33,    34,   215,   216,
     209,   211,   213,   212,   210,   205,   217,   208,   206,   207,
     214,   363,   365,   366,   381,   380,   377,   373,   374,   371,
     372,   375,     0,   370,   360,   378,   379,   359,   364,   376,
     362,   361,   404,   405,   425,   426,   418,     0,   417,   559,
       0,   536,     0,    38,    39,    40,   611,   610,     0,   609,
     597,   596,   603,   602,     0,   601,   605,   604,   257,   258,
     267,   264,   269,   266,   265,   271,   268,   270,   263,     0,
     262,   256,   274,   273,   272,   255,   396,   388,     0,   387,
     395,   225,   226,   224,     0,   223,   241,   240,     0,     0,
       0,   108,     0,     0,     0,     0,   103,   141,   139,   178,
     175,   174,   169,   179,   184,   171,   186,   180,   183,   177,
     170,   185,   181,   182,   176,   172,   173,     0,   168,   136,
     138,   140,   146,   162,   163,   147,   148,   149,   150,   157,
     151,   160,   164,   153,   158,   154,   159,   152,   156,   155,
     161,     0,   145,   137,   284,   285,   283,    66,     0,   300,
     306,   312,   316,   315,   314,   311,   307,   310,   313,   308,
     309,     0,   305,   301,   324,   329,   335,   339,   338,   337,
     334,   330,   333,   336,   331,   332,     0,   328,   368,     0,
     415,     0,   560,   537,   607,     0,   599,     0,   260,     0,
     385,     0,   221,     0,   239,   236,   235,     0,     0,     0,
       0,   102,   166,     0,   143,     0,    67,   303,     0,   326,
       0,   369,   416,   608,   600,   261,   386,   222,   109,   118,
     121,   120,   117,   122,   119,   116,     0,   115,   111,   110,
     167,   144,   304,   327,   113,     0,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   836,   837,   981,   982,    26,   254,   255,
     256,   257,    27,   290,   291,   292,   582,  1059,  1060,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      28,    74,    75,    76,    77,    78,    29,   245,   246,   247,
     248,   249,   250,  1023,  1024,  1025,  1026,  1027,  1173,  1306,
    1307,    30,    63,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   779,  1221,  1222,   555,   775,  1197,  1198,    31,
      51,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,    32,    60,   520,   759,
    1164,  1165,   521,   522,   523,  1170,  1014,  1015,   524,   525,
      33,    58,   496,   497,   498,   499,   500,   501,   502,   745,
    1149,  1150,   503,   504,   505,    34,    64,   560,   561,   562,
     563,   564,    35,   308,   309,   310,    36,    67,   593,   594,
     595,   596,   597,   812,  1241,  1242,    37,    68,   601,   602,
     603,   604,   818,  1256,  1257,    38,    52,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   654,  1102,  1103,
     391,   392,   393,   394,   395,   396,    39,    59,   510,   754,
    1158,  1159,   511,   512,   513,   514,    40,    53,   400,   401,
     402,   403,    41,   123,   124,   125,    42,    55,   411,   673,
    1117,  1118,   412,   413,   414,   415,    43,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   448,   960,
     961,   233,   446,   938,   939,   234,   235,   236,   237,    44,
      57,   479,   480,   481,   482,   483,   737,  1134,  1135,   484,
     485,   486,   734,  1128,  1129,    45,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    46,   268,   269,   270,
     271,   272,   273,   274,   275,   276
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -769
static const yytype_int16 yypact[] =
{
    -769,   684,  -769,  -212,  -245,  -229,  -769,  -769,  -769,  -223,
    -769,  -208,  -769,  -769,  -769,  -769,  -198,  -191,  -769,  -769,
    -186,  -157,  -769,  -769,  -155,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,    43,
     588,  -147,   -97,   -94,     8,   -91,   418,   -84,   -63,   -60,
     -44,    50,     5,   -13,    27,   764,   457,    30,    33,    79,
     -21,    21,    34,    39,     9,  -769,  -769,  -769,  -769,  -769,
      40,    51,    60,    70,    72,    90,    98,   100,   101,   107,
     110,   117,   118,   119,   128,   130,   135,   136,   129,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   665,   486,
      91,  -769,   137,     6,  -769,  -769,   229,  -769,   139,   142,
     143,   144,   146,   149,   150,   151,   154,   156,   157,   159,
     160,   161,   164,   166,   169,   176,   179,   182,   183,   186,
     187,   189,   190,   191,   192,   193,   194,   198,  -769,   199,
    -769,   202,   205,   208,   210,   213,   215,   216,   217,   221,
     222,   223,   224,   225,   232,   233,   235,   237,   239,   242,
     247,   248,    22,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   304,   382,
     158,   309,   111,   250,   251,    35,  -769,  -769,  -769,  -769,
      73,   257,   255,   256,    38,  -769,  -769,  -769,   428,    69,
    -769,   258,   259,   263,   264,   268,   276,   278,   108,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,   260,   279,   280,
     281,   283,   288,   290,   291,  -769,   295,   297,   298,   301,
     228,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,   172,   131,  -769,   302,    26,  -769,
    -769,  -769,   116,   415,   416,   310,  -769,   373,   445,   448,
     386,   387,   453,   453,   454,   455,   392,   393,   459,   453,
     396,   398,   399,   400,   402,   340,  -769,   346,   345,   351,
     356,   357,   362,   364,   366,   367,   368,   369,   370,   371,
     375,   197,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,   384,   379,   383,   385,
     389,   390,  -769,   391,   395,   397,   403,   404,   405,   406,
     408,   238,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   409,   410,
      37,  -769,  -769,  -769,   493,   417,  -769,  -769,   420,   421,
    -769,  -769,    65,  -769,  -769,  -769,   466,   453,   453,   518,
     498,   532,   482,   490,   558,   538,   495,   561,   562,   565,
     504,   508,   509,   453,   554,   511,   578,   581,   453,   582,
     583,   566,   586,   589,   525,   526,   461,   531,   465,   453,
     453,   536,   453,   584,   539,   541,   542,   -75,   -48,   544,
     547,   453,   453,   603,   592,   453,   550,   551,   553,   567,
     497,  -769,  -769,  -769,   499,   501,  -769,   502,   505,    14,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,   507,   520,   522,
    -769,   528,   530,   533,   534,   537,   165,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,   540,  -769,   543,
    -769,    94,  -769,  -769,  -769,   524,  -769,   546,   548,   549,
    -769,    87,  -769,  -769,  -769,  -769,  -769,   585,   594,   545,
    -769,   555,  -769,   642,   649,   556,  -769,   559,   560,   563,
    -769,   564,   577,   580,  -769,   587,     4,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,   568,   593,   595,   596,
      47,  -769,  -769,  -769,  -769,   606,   611,   614,   672,   629,
     633,   453,   570,  -769,  -769,   689,   655,   700,   701,   703,
     705,   709,   597,   710,   734,   715,   718,   617,  -769,   620,
     608,  -769,   618,    20,  -769,  -769,  -769,  -769,   625,   623,
    -769,    68,  -769,  -769,  -769,   744,   632,  -769,   637,   639,
     640,  -769,   641,   644,   645,   646,   648,   212,   650,   656,
     659,   664,   667,   671,   675,   676,   678,   679,   680,   681,
     688,  -769,  -769,   771,   778,   453,   794,   820,   821,   825,
     805,   828,   832,   453,   453,   603,   707,  -769,  -769,   816,
      -9,   818,   819,   776,   712,   824,   826,   827,   829,   842,
     830,   831,   833,   720,  -769,   834,   835,   724,  -769,   728,
    -769,   837,   838,   714,   731,  -769,   732,   733,   735,   736,
     737,   738,   739,   741,   742,   743,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   765,   669,   766,   708,   767,
     768,   769,   770,   772,   773,   774,   775,   777,   779,   780,
     781,   782,   783,   784,   785,   338,   786,   787,   788,   789,
     790,   791,   792,  -769,   793,   453,   798,   795,   848,   852,
     797,  -769,  -769,   872,   840,   796,   879,   907,   901,   902,
     903,   800,  -769,   909,   799,   911,   804,  -769,  -769,   802,
     914,   915,   937,   809,  -769,   810,   811,  -769,    76,   812,
     813,  -769,  -769,   922,   880,   814,   923,   926,   927,   817,
     929,   822,  -769,  -769,   931,   932,   933,   836,  -769,   839,
     841,   843,   844,   845,   846,   847,  -769,   849,   850,   851,
     853,   854,   855,   856,    78,   857,   858,   859,   860,  -769,
    -769,   934,   861,   935,   862,  -769,  -769,   936,   863,   865,
    -769,   867,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,   453,   453,   453,   453,   453,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,   868,   869,   870,   871,   873,   874,   875,   876,   877,
     878,   881,   882,   883,  -769,   884,   885,   886,   887,   888,
     889,     2,   890,   891,   892,   893,   894,   895,   896,   897,
    -769,   898,   899,  -769,  -769,   900,   904,   938,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -233,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -230,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   603,   603,
     603,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
       0,   905,   906,    13,   908,   910,  -769,   912,   913,   717,
     916,   917,   918,   919,   920,  -769,   921,   940,   924,  -769,
     115,   925,   928,   939,   930,  -769,  -769,  -769,  -769,   941,
     942,  -769,   943,    99,  -769,  -769,  -769,  -769,  -769,  -769,
     944,   947,   521,   948,   949,   950,   740,   951,  -769,   952,
     953,   954,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -224,
    -769,  -769,  -769,  -769,  -769,   955,   527,   956,  -769,   957,
     590,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -213,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -204,  -769,  -769,
     669,  -769,   708,  -769,  -769,  -769,  -769,  -769,  -203,  -769,
    -769,  -769,  -769,  -769,  -187,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -175,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -174,  -769,
    -769,  -769,  -769,  -769,  -172,  -769,  -769,  -769,   958,   937,
     959,  -769,   946,   960,  -113,   961,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -165,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -132,  -769,  -769,  -769,  -769,  -769,  -769,    78,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,   -23,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,    81,  -769,  -769,     2,
    -769,   938,  -769,  -769,  -769,     0,  -769,    13,  -769,   717,
    -769,   940,  -769,   115,  -769,  -769,  -769,   962,   220,   964,
     965,  -769,  -769,   521,  -769,   740,  -769,  -769,   527,  -769,
     590,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,   112,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,   220,  -769
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -769,  -769,  -769,  -411,  -321,  -768,  -463,  -769,  -769,   823,
    -769,  -769,  -769,  -769,   808,  -769,  -769,  -769,  -152,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  1004,  -769,  -769,  -769,  -769,  -769,   864,  -769,
    -769,  -769,  -769,  -769,    56,  -769,  -769,  -769,  -769,  -769,
    -235,  -769,  -769,  -769,   572,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -199,  -769,  -769,  -769,  -195,  -769,
    -769,  -769,   806,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -179,  -769,   604,  -769,  -769,  -769,   -62,  -769,  -769,
    -769,  -769,  -769,   651,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -121,  -769,  -769,  -769,  -769,  -769,  -769,   600,  -769,
    -769,  -769,  -769,  -769,   945,  -769,  -769,  -769,  -769,   575,
    -769,  -769,  -769,  -769,  -769,  -139,  -769,  -769,  -769,   552,
    -769,  -769,  -769,  -769,  -135,  -769,  -769,  -769,   801,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   -98,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -102,  -769,   661,  -769,  -769,  -769,  -769,  -769,   815,
    -769,  -769,  -769,  -769,  1050,  -769,  -769,  -769,  -769,  -769,
    -769,   -86,  -769,   807,  -769,  -769,  -769,  -769,   994,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
      55,  -769,  -769,  -769,    58,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,   702,  -769,  -769,  -769,  -769,  -769,   -88,  -769,
    -769,  -769,  -769,  -769,   -82,  -769,  -769,  1086,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,
    -769,  -769,  -769,  -769,  -769,  -769,  -769,  -769,   963,  -769,
    -769,  -769,  -769,  -769,  -769,  -769
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     726,   618,   619,    49,   725,   537,   251,   121,   625,   121,
      70,  1126,  1097,  1119,  1098,   472,  1121,  1120,   473,    50,
    1122,   589,  1227,   127,  1132,    54,  1228,   306,  1099,   538,
     128,   129,  1100,  1258,    47,    48,   242,  1259,   397,   251,
      56,   130,  1260,  1264,    70,    71,  1261,  1265,   556,   131,
      61,   242,   539,   132,   133,    72,   540,    62,   474,  1266,
     134,   475,    65,  1267,   135,   136,   407,   137,   557,   598,
     556,  1268,  1270,   138,  1272,  1269,  1271,  1019,  1273,    71,
     306,  1282,   139,   140,   122,  1283,   122,   141,   515,    72,
     557,    66,   397,    69,   142,   506,   677,   678,   143,   144,
    1019,   118,   145,  1279,   476,   146,   147,   717,   718,   260,
     252,   541,   693,   148,  1284,   398,    73,   698,  1285,   149,
     150,   477,   151,   152,   153,   154,   155,   590,   709,   710,
      79,   712,   598,   307,   719,   720,   542,   156,   253,   516,
     723,   724,    80,   252,   728,   157,   158,   159,   261,   160,
      73,   119,   161,   162,   120,   543,   163,   126,   558,   506,
     517,   262,    81,    82,   238,   518,   487,   164,    83,   398,
      84,   253,   408,   589,   263,   599,   264,   399,   265,   266,
     558,  1161,   863,  1020,  1127,   239,   307,   559,   240,   165,
     488,   166,   591,   866,   867,   167,   267,  1133,   337,   168,
     169,   170,   171,   172,   241,   409,  1020,   173,   174,   559,
    1123,  1124,  1125,   489,    85,    86,   175,   490,   544,   338,
     339,    87,    88,  1287,   519,   311,   340,  1288,  1101,   277,
     407,   399,  1057,  1058,   507,   258,   545,   410,   599,   366,
     600,   367,    89,    90,   368,   176,   478,   177,  1021,   178,
     795,   781,   592,   405,   608,   179,   315,    91,    92,   243,
     180,   740,   369,   370,   278,   181,   508,   814,    93,   470,
     312,  1021,   244,   606,   243,   259,  1299,    94,   304,   590,
    -101,   305,   529,   313,   667,   535,   371,   244,   314,   317,
     372,   341,   342,   343,   787,  -101,   344,   491,   507,  1300,
     318,  1301,   279,   600,   345,   472,   492,   493,   473,   319,
     515,   373,   674,   374,   853,   819,   346,   347,   531,   320,
    1022,   321,   861,   862,  1162,   375,   509,  1289,  1163,   617,
     508,  1290,   348,   349,   763,   280,   408,   281,   282,   322,
     494,   756,  1302,  1022,   591,   376,  1175,   323,   474,   324,
     325,   475,   978,   979,   980,   572,   326,   526,  1314,   327,
     350,   516,  1315,    95,    96,    97,   328,   329,   330,   409,
     831,   832,   833,   834,   835,   377,   335,   331,   283,   332,
     284,   285,   517,   487,   333,   334,   404,   518,   416,   378,
     509,   417,   418,   419,   476,   420,   286,   495,   421,   422,
     423,   410,   379,   424,   592,   425,   426,   488,   427,   428,
     429,   477,   751,   430,   991,   431,  1303,  1304,   432,   127,
    1073,  1074,  1075,  1076,  1077,   433,   128,   129,   434,   537,
     489,   435,   436,   287,   490,   437,   438,   130,   439,   440,
     441,   442,   443,   444,   646,   131,   519,   445,   447,   132,
     133,   449,  1305,   538,   450,   725,   134,   451,   277,   452,
     135,   136,   453,   137,   454,   455,   456,   288,   289,   138,
     457,   458,   459,   460,   461,   587,   539,   380,   139,   140,
     540,   462,   463,   141,   464,   663,   465,   366,   466,   367,
     142,   467,   368,   278,   143,   144,   468,   469,   145,   527,
     528,   146,   147,   532,   533,   534,   574,   565,   566,   148,
     369,   370,   567,   568,   491,   149,   150,   569,   151,   152,
     153,   154,   155,   492,   493,   570,  1179,   571,   575,   576,
     577,   279,   578,   156,   371,   541,   478,   579,   372,   580,
     581,   157,   158,   159,   583,   160,   584,   585,   161,   162,
     586,   605,   163,   609,   610,   612,   611,   494,  1180,   373,
     542,   374,   613,   164,   280,   614,   281,   282,   615,   616,
     617,   620,   621,   375,   622,   623,   624,  1181,   626,   543,
     627,   628,   629,  1182,   630,   165,   631,   166,  1183,    79,
    1184,   167,   632,   376,   633,   168,   169,   170,   171,   172,
     634,    80,  1185,   173,   174,   635,   636,   283,  1230,   284,
     285,   637,   175,   638,   495,   639,   640,   641,   642,   643,
     644,    81,    82,   377,   645,   286,  1186,    83,   649,    84,
     648,   669,   650,  1187,   651,   679,   680,   378,   652,   653,
     655,   176,   544,   177,   656,   178,   657,  1188,   676,   681,
     379,   179,   658,   659,   660,   661,   180,   662,   665,   666,
     545,   181,   287,   670,   682,  1189,   337,  1190,  1191,   671,
     672,  1245,   683,    85,    86,   684,   685,   686,   687,   688,
      87,    88,   689,  1231,     2,     3,   690,   338,   339,     4,
     691,   692,   694,   695,   340,   696,   288,   289,   697,   699,
     700,    89,    90,   702,   701,     5,   703,   704,   705,     6,
     706,  1280,     7,   707,   708,  1232,    91,    92,   711,     8,
     725,   714,   713,   715,   716,   380,   721,    93,  1192,   722,
     727,  1233,   729,   730,     9,   731,    94,  1140,    10,    11,
    1193,    12,  1194,   733,  1234,  1235,  1246,    13,   735,   732,
     736,   738,  1195,   742,   739,  1236,  1237,  1238,  1239,   341,
     342,   343,  1196,    14,   344,   260,  1141,   765,  1240,   743,
     758,   744,   345,    15,    16,  1142,   766,   746,  1247,   747,
     769,  1143,   748,   749,   346,   347,   750,   770,   789,   753,
      17,   767,   755,   790,  1248,   760,   791,   761,   762,  1144,
     348,   349,   771,   768,   261,   772,    18,  1249,  1250,   773,
     792,   793,   774,   776,   783,   794,   796,   262,  1251,  1252,
    1253,  1254,    95,    96,    97,  1145,   777,   797,   350,   778,
     263,  1255,   264,  1146,   265,   266,   780,   798,   799,   800,
      19,   801,   784,   802,   785,   786,   804,   803,   805,    20,
      21,   806,   267,   807,    22,    23,   808,   811,   919,   920,
     921,   922,   923,   809,   924,   925,   810,   813,   926,   927,
     928,   816,   817,   929,  1147,   930,   931,   932,   822,   933,
     934,   935,   821,   823,   936,   824,   825,   826,   851,   937,
     827,   828,   829,  1148,   830,   852,   838,   941,   942,   943,
     944,   945,   839,   946,   947,   840,    24,   948,   949,   950,
     841,   854,   951,   842,   952,   953,   954,   843,   955,   956,
     957,   844,   845,   958,   846,   847,   848,   849,   959,  1202,
    1203,  1204,  1205,  1206,   850,  1207,  1208,   855,   856,  1209,
    1210,  1211,   857,   858,  1212,   859,  1213,  1214,  1215,   860,
    1216,  1217,  1218,   864,   865,  1219,   868,   869,   870,   876,
    1220,   871,   872,   887,   873,   874,   880,   875,   877,   878,
     883,   879,   881,   882,   884,   885,   886,   888,   889,   890,
     992,   891,   892,   893,   894,   895,   994,   896,   897,   898,
     995,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   914,   915,   916,   917,
     997,   918,   940,   962,   963,   964,   965,  1000,   966,   967,
     968,   969,   998,   970,  1001,   971,   972,   973,   974,   975,
     976,   977,   983,   984,   985,   986,   987,   988,   989,  1002,
    1003,  1004,   990,   996,   993,   999,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1016,  1017,  1018,  1028,  1029,
    1030,  1033,  1031,  1032,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1065,  1067,  1069,  1274,  1286,   536,   316,  1176,
    1316,  1116,  1042,  1157,  1277,  1043,  1311,  1044,  1310,  1045,
    1046,  1047,  1048,  1049,  1297,  1050,  1051,  1052,   588,  1053,
    1054,  1055,  1056,  1061,  1062,  1063,  1064,  1275,  1068,   530,
    1066,  1071,  1070,  1072,  1078,  1079,  1080,  1081,   782,  1082,
    1083,  1084,  1085,  1086,  1087,   764,  1168,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,   752,  1295,  1312,
    1115,  1130,  1131,   820,  1136,  1313,  1137,   647,  1138,  1139,
     788,  1291,  1151,  1152,  1153,  1154,  1155,  1156,   815,  1296,
    1160,  1166,   757,   406,  1167,  1292,   471,  1263,  1262,  1294,
    1169,   741,   664,  1293,   336,     0,     0,  1171,     0,     0,
    1177,  1172,  1174,  1178,  1199,  1200,  1201,  1223,  1224,  1225,
    1226,  1229,  1243,  1244,     0,  1276,     0,  1281,  1298,  1278,
    1308,  1309,     0,     0,     0,   668,     0,     0,     0,   675,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-769))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     463,   322,   323,   248,   117,     1,     1,     1,   329,     1,
       1,    11,    10,   246,    12,     1,   246,   250,     4,   248,
     250,     1,   246,     1,    11,   248,   250,     1,    26,    25,
       8,     9,    30,   246,   246,   247,     1,   250,     1,     1,
     248,    19,   246,   246,     1,    36,   250,   250,     1,    27,
     248,     1,    48,    31,    32,    46,    52,   248,    44,   246,
      38,    47,   248,   250,    42,    43,     1,    45,    21,     1,
       1,   246,   246,    51,   246,   250,   250,     1,   250,    36,
       1,   246,    60,    61,    78,   250,    78,    65,     1,    46,
      21,   248,     1,   248,    72,     1,   417,   418,    76,    77,
       1,   248,    80,   216,    90,    83,    84,   182,   183,     1,
     105,   107,   433,    91,   246,    78,   107,   438,   250,    97,
      98,   107,   100,   101,   102,   103,   104,   107,   449,   450,
       1,   452,     1,   107,   182,   183,   132,   115,   133,    52,
     461,   462,    13,   105,   465,   123,   124,   125,    40,   127,
     107,   248,   130,   131,   248,   151,   134,   248,   111,     1,
      73,    53,    33,    34,   248,    78,     1,   145,    39,    78,
      41,   133,   107,     1,    66,   107,    68,   140,    70,    71,
     111,    66,   645,   107,   184,   248,   107,   140,   248,   167,
      25,   169,   172,   202,   203,   173,    88,   184,     1,   177,
     178,   179,   180,   181,   248,   140,   107,   185,   186,   140,
     978,   979,   980,    48,    85,    86,   194,    52,   214,    22,
      23,    92,    93,   246,   137,   246,    29,   250,   226,     1,
       1,   140,   154,   155,   140,   248,   232,   172,   107,     1,
     172,     3,   113,   114,     6,   223,   232,   225,   172,   227,
     571,   247,   232,   247,   138,   233,   247,   128,   129,   224,
     238,   247,    24,    25,    36,   243,   172,   247,   139,   247,
     249,   172,   237,   247,   224,   248,    56,   148,   248,   107,
     245,   248,   247,   249,   247,   247,    48,   237,   249,   249,
      52,    94,    95,    96,   247,   245,    99,   132,   140,    79,
     249,    81,    74,   172,   107,     1,   141,   142,     4,   249,
       1,    73,   247,    75,   635,   247,   119,   120,   245,   249,
     244,   249,   643,   644,   209,    87,   232,   246,   213,   117,
     172,   250,   135,   136,   247,   107,   107,   109,   110,   249,
     175,   247,   122,   244,   172,   107,   247,   249,    44,   249,
     249,    47,    14,    15,    16,   247,   249,   246,   246,   249,
     163,    52,   250,   234,   235,   236,   249,   249,   249,   140,
     158,   159,   160,   161,   162,   137,   247,   249,   150,   249,
     152,   153,    73,     1,   249,   249,   249,    78,   249,   151,
     232,   249,   249,   249,    90,   249,   168,   232,   249,   249,
     249,   172,   164,   249,   232,   249,   249,    25,   249,   249,
     249,   107,   247,   249,   735,   249,   196,   197,   249,     1,
     831,   832,   833,   834,   835,   249,     8,     9,   249,     1,
      48,   249,   249,   205,    52,   249,   249,    19,   249,   249,
     249,   249,   249,   249,   247,    27,   137,   249,   249,    31,
      32,   249,   232,    25,   249,   117,    38,   249,     1,   249,
      42,    43,   249,    45,   249,   249,   249,   239,   240,    51,
     249,   249,   249,   249,   249,   247,    48,   239,    60,    61,
      52,   249,   249,    65,   249,   247,   249,     1,   249,     3,
      72,   249,     6,    36,    76,    77,   249,   249,    80,   249,
     249,    83,    84,   246,   249,   249,   246,   249,   249,    91,
      24,    25,   249,   249,   132,    97,    98,   249,   100,   101,
     102,   103,   104,   141,   142,   249,     5,   249,   249,   249,
     249,    74,   249,   115,    48,   107,   232,   249,    52,   249,
     249,   123,   124,   125,   249,   127,   249,   249,   130,   131,
     249,   249,   134,   138,   138,   182,   246,   175,    37,    73,
     132,    75,   117,   145,   107,   117,   109,   110,   182,   182,
     117,   117,   117,    87,   182,   182,   117,    56,   182,   151,
     182,   182,   182,    62,   182,   167,   246,   169,    67,     1,
      69,   173,   246,   107,   249,   177,   178,   179,   180,   181,
     249,    13,    81,   185,   186,   249,   249,   150,    81,   152,
     153,   249,   194,   249,   232,   249,   249,   249,   249,   249,
     249,    33,    34,   137,   249,   168,   105,    39,   249,    41,
     246,   138,   249,   112,   249,   117,   138,   151,   249,   249,
     249,   223,   214,   225,   249,   227,   249,   126,   182,   117,
     164,   233,   249,   249,   249,   249,   238,   249,   249,   249,
     232,   243,   205,   246,   182,   144,     1,   146,   147,   249,
     249,    81,   182,    85,    86,   117,   138,   182,   117,   117,
      92,    93,   117,   156,     0,     1,   182,    22,    23,     5,
     182,   182,   138,   182,    29,   117,   239,   240,   117,   117,
     117,   113,   114,   117,   138,    21,   117,   182,   182,    25,
     249,  1174,    28,   182,   249,   188,   128,   129,   182,    35,
     117,   182,   138,   182,   182,   239,   182,   139,   207,   182,
     138,   204,   182,   182,    50,   182,   148,    20,    54,    55,
     219,    57,   221,   246,   217,   218,   156,    63,   249,   182,
     249,   249,   231,   246,   249,   228,   229,   230,   231,    94,
      95,    96,   241,    79,    99,     1,    49,   182,   241,   249,
     246,   249,   107,    89,    90,    58,   182,   249,   188,   249,
     138,    64,   249,   249,   119,   120,   249,   138,   182,   249,
     106,   246,   249,   182,   204,   249,   182,   249,   249,    82,
     135,   136,   246,   248,    40,   246,   122,   217,   218,   249,
     138,   182,   249,   249,   246,   182,   246,    53,   228,   229,
     230,   231,   234,   235,   236,   108,   249,   138,   163,   249,
      66,   241,    68,   116,    70,    71,   249,   182,   138,   138,
     156,   138,   249,   138,   249,   249,   249,   138,   138,   165,
     166,   117,    88,   138,   170,   171,   138,   249,   189,   190,
     191,   192,   193,   246,   195,   196,   246,   249,   199,   200,
     201,   246,   249,   204,   157,   206,   207,   208,   246,   210,
     211,   212,   138,   246,   215,   246,   246,   246,   117,   220,
     246,   246,   246,   176,   246,   117,   246,   189,   190,   191,
     192,   193,   246,   195,   196,   246,   222,   199,   200,   201,
     246,   117,   204,   246,   206,   207,   208,   246,   210,   211,
     212,   246,   246,   215,   246,   246,   246,   246,   220,   189,
     190,   191,   192,   193,   246,   195,   196,   117,   117,   199,
     200,   201,   117,   138,   204,   117,   206,   207,   208,   117,
     210,   211,   212,   246,   138,   215,   138,   138,   182,   117,
     220,   249,   138,   249,   138,   138,   246,   138,   138,   138,
     246,   138,   138,   138,   246,   138,   138,   246,   246,   246,
     182,   246,   246,   246,   246,   246,   138,   246,   246,   246,
     138,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     138,   246,   246,   246,   246,   246,   246,   138,   246,   246,
     246,   246,   182,   246,   117,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   138,
     138,   138,   249,   246,   249,   249,   246,   138,   249,   138,
     246,   249,   138,   138,   117,   246,   246,   246,   246,   246,
     138,   138,   182,   249,   138,   138,   249,   138,   246,   138,
     138,   138,   138,   138,   138,   117,  1228,   254,    74,  1023,
    1315,   143,   246,   143,   138,   246,  1285,   246,  1283,   246,
     246,   246,   246,   246,  1273,   246,   246,   246,   290,   246,
     246,   246,   246,   246,   246,   246,   246,  1169,   246,   245,
     249,   246,   249,   246,   246,   246,   246,   246,   546,   246,
     246,   246,   246,   246,   246,   521,   187,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   496,  1269,  1288,
     246,   246,   246,   601,   246,  1290,   246,   351,   246,   246,
     560,  1259,   246,   246,   246,   246,   246,   246,   593,  1271,
     246,   246,   511,   123,   246,  1261,   182,  1122,  1120,  1267,
     250,   479,   381,  1265,    98,    -1,    -1,   246,    -1,    -1,
     246,   249,   249,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,    -1,   246,    -1,   246,   246,   249,
     246,   246,    -1,    -1,    -1,   400,    -1,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   308
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   252,     0,     1,     5,    21,    25,    28,    35,    50,
      54,    55,    57,    63,    79,    89,    90,   106,   122,   156,
     165,   166,   170,   171,   222,   253,   258,   263,   281,   287,
     302,   320,   337,   351,   366,   373,   377,   387,   396,   417,
     427,   433,   437,   447,   510,   526,   547,   246,   247,   248,
     248,   321,   397,   428,   248,   438,   248,   511,   352,   418,
     338,   248,   248,   303,   367,   248,   248,   378,   388,   248,
       1,    36,    46,   107,   282,   283,   284,   285,   286,     1,
      13,    33,    34,    39,    41,    85,    86,    92,    93,   113,
     114,   128,   129,   139,   148,   234,   235,   236,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   248,   248,
     248,     1,    78,   434,   435,   436,   248,     1,     8,     9,
      19,    27,    31,    32,    38,    42,    43,    45,    51,    60,
      61,    65,    72,    76,    77,    80,    83,    84,    91,    97,
      98,   100,   101,   102,   103,   104,   115,   123,   124,   125,
     127,   130,   131,   134,   145,   167,   169,   173,   177,   178,
     179,   180,   181,   185,   186,   194,   223,   225,   227,   233,
     238,   243,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   502,   506,   507,   508,   509,   248,   248,
     248,   248,     1,   224,   237,   288,   289,   290,   291,   292,
     293,     1,   105,   133,   259,   260,   261,   262,   248,   248,
       1,    40,    53,    66,    68,    70,    71,    88,   548,   549,
     550,   551,   552,   553,   554,   555,   556,     1,    36,    74,
     107,   109,   110,   150,   152,   153,   168,   205,   239,   240,
     264,   265,   266,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   248,   248,     1,   107,   374,   375,
     376,   246,   249,   249,   249,   247,   283,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   247,   528,     1,    22,    23,
      29,    94,    95,    96,    99,   107,   119,   120,   135,   136,
     163,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,     1,     3,     6,    24,
      25,    48,    52,    73,    75,    87,   107,   137,   151,   164,
     239,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   411,   412,   413,   414,   415,   416,     1,    78,   140,
     429,   430,   431,   432,   249,   247,   435,     1,   107,   140,
     172,   439,   443,   444,   445,   446,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   503,   249,   499,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     247,   449,     1,     4,    44,    47,    90,   107,   232,   512,
     513,   514,   515,   516,   520,   521,   522,     1,    25,    48,
      52,   132,   141,   142,   175,   232,   353,   354,   355,   356,
     357,   358,   359,   363,   364,   365,     1,   140,   172,   232,
     419,   423,   424,   425,   426,     1,    52,    73,    78,   137,
     339,   343,   344,   345,   349,   350,   246,   249,   249,   247,
     289,   245,   246,   249,   249,   247,   260,     1,    25,    48,
      52,   107,   132,   151,   214,   232,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   316,     1,    21,   111,   140,
     368,   369,   370,   371,   372,   249,   249,   249,   249,   249,
     249,   249,   247,   549,   246,   249,   249,   249,   249,   249,
     249,   249,   267,   249,   249,   249,   249,   247,   265,     1,
     107,   172,   232,   379,   380,   381,   382,   383,     1,   107,
     172,   389,   390,   391,   392,   249,   247,   375,   138,   138,
     138,   246,   182,   117,   117,   182,   182,   117,   255,   255,
     117,   117,   182,   182,   117,   255,   182,   182,   182,   182,
     182,   246,   246,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   247,   323,   246,   249,
     249,   249,   249,   249,   408,   249,   249,   249,   249,   249,
     249,   249,   249,   247,   399,   249,   249,   247,   430,   138,
     246,   249,   249,   440,   247,   444,   182,   255,   255,   117,
     138,   117,   182,   182,   117,   138,   182,   117,   117,   117,
     182,   182,   182,   255,   138,   182,   117,   117,   255,   117,
     117,   138,   117,   117,   182,   182,   249,   182,   249,   255,
     255,   182,   255,   138,   182,   182,   182,   182,   183,   182,
     183,   182,   182,   255,   255,   117,   257,   138,   255,   182,
     182,   182,   182,   246,   523,   249,   249,   517,   249,   249,
     247,   513,   246,   249,   249,   360,   249,   249,   249,   249,
     249,   247,   354,   249,   420,   249,   247,   424,   246,   340,
     249,   249,   249,   247,   344,   182,   182,   246,   248,   138,
     138,   246,   246,   249,   249,   317,   249,   249,   249,   313,
     249,   247,   305,   246,   249,   249,   249,   247,   369,   182,
     182,   182,   138,   182,   182,   255,   246,   138,   182,   138,
     138,   138,   138,   138,   249,   138,   117,   138,   138,   246,
     246,   249,   384,   249,   247,   380,   246,   249,   393,   247,
     390,   138,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   158,   159,   160,   161,   162,   254,   255,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   117,   117,   255,   117,   117,   117,   117,   138,   117,
     117,   255,   255,   257,   246,   138,   202,   203,   138,   138,
     182,   249,   138,   138,   138,   138,   117,   138,   138,   138,
     246,   138,   138,   246,   246,   138,   138,   249,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   189,
     190,   191,   192,   193,   195,   196,   199,   200,   201,   204,
     206,   207,   208,   210,   211,   212,   215,   220,   504,   505,
     246,   189,   190,   191,   192,   193,   195,   196,   199,   200,
     201,   204,   206,   207,   208,   210,   211,   212,   215,   220,
     500,   501,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,    14,    15,
      16,   256,   257,   246,   246,   246,   246,   246,   246,   246,
     249,   255,   182,   249,   138,   138,   246,   138,   182,   249,
     138,   117,   138,   138,   138,   246,   138,   249,   138,   246,
     249,   138,   138,   117,   347,   348,   246,   246,   246,     1,
     107,   172,   244,   294,   295,   296,   297,   298,   246,   246,
     138,   182,   249,   138,   138,   138,   249,   138,   246,   138,
     138,   138,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   154,   155,   268,
     269,   246,   246,   246,   246,   138,   249,   138,   246,   138,
     249,   246,   246,   254,   254,   254,   254,   254,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,    10,    12,    26,
      30,   226,   409,   410,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   143,   441,   442,   246,
     250,   246,   250,   256,   256,   256,    11,   184,   524,   525,
     246,   246,    11,   184,   518,   519,   246,   246,   246,   246,
      20,    49,    58,    64,    82,   108,   116,   157,   176,   361,
     362,   246,   246,   246,   246,   246,   246,   143,   421,   422,
     246,    66,   209,   213,   341,   342,   246,   246,   187,   250,
     346,   246,   249,   299,   249,   247,   295,   246,   246,     5,
      37,    56,    62,    67,    69,    81,   105,   112,   126,   144,
     146,   147,   207,   219,   221,   231,   241,   318,   319,   246,
     246,   246,   189,   190,   191,   192,   193,   195,   196,   199,
     200,   201,   204,   206,   207,   208,   210,   211,   212,   215,
     220,   314,   315,   246,   246,   246,   246,   246,   250,   246,
      81,   156,   188,   204,   217,   218,   228,   229,   230,   231,
     241,   385,   386,   246,   246,    81,   156,   188,   204,   217,
     218,   228,   229,   230,   231,   241,   394,   395,   246,   250,
     246,   250,   505,   501,   246,   250,   246,   250,   246,   250,
     246,   250,   246,   250,   117,   348,   246,   138,   249,   216,
     257,   246,   246,   250,   246,   250,   269,   246,   250,   246,
     250,   410,   442,   525,   519,   362,   422,   342,   246,    56,
      79,    81,   122,   196,   197,   232,   300,   301,   246,   246,
     319,   315,   386,   395,   246,   250,   301
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
#line 990 "ircd_parser.y"
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
#line 1002 "ircd_parser.y"
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
#line 1039 "ircd_parser.y"
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
#line 1051 "ircd_parser.y"
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
#line 1062 "ircd_parser.y"
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
#line 1104 "ircd_parser.y"
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
#line 1113 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1120 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1124 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1128 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1132 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1136 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1140 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1144 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1148 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1152 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1156 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1160 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1164 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1168 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1172 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1176 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1180 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1184 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1188 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1192 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1205 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1209 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1213 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1221 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1225 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1233 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1237 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1241 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1245 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1249 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1253 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1257 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1261 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1265 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1269 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1273 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1283 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1290 "ircd_parser.y"
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

  case 205:

/* Line 1806 of yacc.c  */
#line 1348 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 206:

/* Line 1806 of yacc.c  */
#line 1357 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 207:

/* Line 1806 of yacc.c  */
#line 1363 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1369 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1375 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1381 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1387 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1405 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1417 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1423 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1432 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1439 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1448 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1454 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1462 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1472 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 238:

/* Line 1806 of yacc.c  */
#line 1477 "ircd_parser.y"
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

  case 239:

/* Line 1806 of yacc.c  */
#line 1491 "ircd_parser.y"
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

  case 240:

/* Line 1806 of yacc.c  */
#line 1511 "ircd_parser.y"
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
#line 1520 "ircd_parser.y"
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
#line 1532 "ircd_parser.y"
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

  case 243:

/* Line 1806 of yacc.c  */
#line 1544 "ircd_parser.y"
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

  case 255:

/* Line 1806 of yacc.c  */
#line 1606 "ircd_parser.y"
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

  case 256:

/* Line 1806 of yacc.c  */
#line 1643 "ircd_parser.y"
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

  case 257:

/* Line 1806 of yacc.c  */
#line 1656 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 258:

/* Line 1806 of yacc.c  */
#line 1665 "ircd_parser.y"
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

  case 259:

/* Line 1806 of yacc.c  */
#line 1676 "ircd_parser.y"
    {
}
    break;

  case 263:

/* Line 1806 of yacc.c  */
#line 1681 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1685 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1689 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1693 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1697 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1701 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1705 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1709 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1713 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1720 "ircd_parser.y"
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

  case 273:

/* Line 1806 of yacc.c  */
#line 1739 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1749 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1762 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1769 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1781 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1790 "ircd_parser.y"
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

  case 285:

/* Line 1806 of yacc.c  */
#line 1805 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1823 "ircd_parser.y"
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

  case 292:

/* Line 1806 of yacc.c  */
#line 1838 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 293:

/* Line 1806 of yacc.c  */
#line 1846 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1857 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1866 "ircd_parser.y"
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

  case 302:

/* Line 1806 of yacc.c  */
#line 1888 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 306:

/* Line 1806 of yacc.c  */
#line 1895 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1899 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1903 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1907 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1915 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1923 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1927 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1931 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1935 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1944 "ircd_parser.y"
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
#line 1951 "ircd_parser.y"
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
#line 1964 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1970 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1977 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1981 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1985 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1989 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1993 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 1997 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2001 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2005 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2009 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2013 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2017 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2026 "ircd_parser.y"
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

  case 341:

/* Line 1806 of yacc.c  */
#line 2041 "ircd_parser.y"
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

  case 359:

/* Line 1806 of yacc.c  */
#line 2178 "ircd_parser.y"
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

  case 360:

/* Line 1806 of yacc.c  */
#line 2190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 361:

/* Line 1806 of yacc.c  */
#line 2199 "ircd_parser.y"
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

  case 362:

/* Line 1806 of yacc.c  */
#line 2225 "ircd_parser.y"
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

  case 363:

/* Line 1806 of yacc.c  */
#line 2243 "ircd_parser.y"
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

  case 364:

/* Line 1806 of yacc.c  */
#line 2261 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2267 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 2271 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 367:

/* Line 1806 of yacc.c  */
#line 2279 "ircd_parser.y"
    {
}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 2284 "ircd_parser.y"
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

  case 372:

/* Line 1806 of yacc.c  */
#line 2294 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfCryptLink(yy_aconf);
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2298 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2302 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2306 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2312 "ircd_parser.y"
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

  case 377:

/* Line 1806 of yacc.c  */
#line 2353 "ircd_parser.y"
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

  case 378:

/* Line 1806 of yacc.c  */
#line 2364 "ircd_parser.y"
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

  case 379:

/* Line 1806 of yacc.c  */
#line 2377 "ircd_parser.y"
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

  case 380:

/* Line 1806 of yacc.c  */
#line 2390 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 381:

/* Line 1806 of yacc.c  */
#line 2399 "ircd_parser.y"
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

  case 382:

/* Line 1806 of yacc.c  */
#line 2434 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2441 "ircd_parser.y"
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

  case 384:

/* Line 1806 of yacc.c  */
#line 2497 "ircd_parser.y"
    {
}
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 2502 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 395:

/* Line 1806 of yacc.c  */
#line 2511 "ircd_parser.y"
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

  case 396:

/* Line 1806 of yacc.c  */
#line 2530 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2539 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2543 "ircd_parser.y"
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

  case 404:

/* Line 1806 of yacc.c  */
#line 2565 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2571 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 2585 "ircd_parser.y"
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

  case 412:

/* Line 1806 of yacc.c  */
#line 2603 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 2610 "ircd_parser.y"
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

  case 414:

/* Line 1806 of yacc.c  */
#line 2650 "ircd_parser.y"
    {
}
    break;

  case 418:

/* Line 1806 of yacc.c  */
#line 2655 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 425:

/* Line 1806 of yacc.c  */
#line 2664 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 426:

/* Line 1806 of yacc.c  */
#line 2670 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2715 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2720 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2725 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2730 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2735 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2740 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2745 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2750 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2755 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2760 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2765 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2770 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2775 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2780 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2785 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2790 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2795 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2800 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2806 "ircd_parser.y"
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
#line 2817 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2822 "ircd_parser.y"
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
#line 2831 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2836 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2841 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2846 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2851 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2856 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2859 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2864 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2867 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2872 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2877 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2882 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2887 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2892 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2902 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2907 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2912 "ircd_parser.y"
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
#line 2923 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2928 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2933 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2942 "ircd_parser.y"
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

  case 528:

/* Line 1806 of yacc.c  */
#line 2974 "ircd_parser.y"
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

  case 529:

/* Line 1806 of yacc.c  */
#line 2992 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2997 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3006 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3015 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3020 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3025 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3030 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3036 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3039 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3042 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3048 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3051 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3054 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3057 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 3063 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3066 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3069 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3072 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3081 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 3087 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3090 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3095 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3101 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3104 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3107 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3110 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3113 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3116 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3119 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3122 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3125 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3128 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3131 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3134 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3137 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3140 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3143 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3146 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 3149 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 3152 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3155 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3160 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3175 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 585:

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

  case 586:

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

  case 596:

/* Line 1806 of yacc.c  */
#line 3217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 604:

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

  case 605:

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

  case 606:

/* Line 1806 of yacc.c  */
#line 3288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 607:

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

  case 610:

/* Line 1806 of yacc.c  */
#line 3339 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 611:

/* Line 1806 of yacc.c  */
#line 3343 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3367 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3372 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3377 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3382 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3387 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3392 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3397 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3402 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3407 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3412 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3417 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3422 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3427 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3432 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3437 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 649:

/* Line 1806 of yacc.c  */
#line 3442 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 650:

/* Line 1806 of yacc.c  */
#line 3447 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 651:

/* Line 1806 of yacc.c  */
#line 3452 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3477 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 665:

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

  case 666:

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

  case 667:

/* Line 1806 of yacc.c  */
#line 3506 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3512 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3518 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7823 "ircd_parser.c"
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



