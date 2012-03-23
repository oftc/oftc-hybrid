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
     T_SSL_CONNECTION_METHOD = 401,
     T_SSLV3 = 402,
     T_TLSV1 = 403,
     RESV = 404,
     RESV_EXEMPT = 405,
     SECONDS = 406,
     MINUTES = 407,
     HOURS = 408,
     DAYS = 409,
     WEEKS = 410,
     SENDQ = 411,
     SEND_PASSWORD = 412,
     SERVERHIDE = 413,
     SERVERINFO = 414,
     IRCD_SID = 415,
     TKLINE_EXPIRE_NOTICES = 416,
     T_SHARED = 417,
     T_CLUSTER = 418,
     TYPE = 419,
     SHORT_MOTD = 420,
     SILENT = 421,
     SPOOF = 422,
     SPOOF_NOTICE = 423,
     STATS_E_DISABLED = 424,
     STATS_I_OPER_ONLY = 425,
     STATS_K_OPER_ONLY = 426,
     STATS_O_OPER_ONLY = 427,
     STATS_P_OPER_ONLY = 428,
     TBOOL = 429,
     TMASKED = 430,
     T_REJECT = 431,
     TS_MAX_DELTA = 432,
     TS_WARN_DELTA = 433,
     TWODOTS = 434,
     T_ALL = 435,
     T_BOTS = 436,
     T_SOFTCALLERID = 437,
     T_CALLERID = 438,
     T_CCONN = 439,
     T_CCONN_FULL = 440,
     T_CLIENT_FLOOD = 441,
     T_DEAF = 442,
     T_DEBUG = 443,
     T_DLINE = 444,
     T_DRONE = 445,
     T_EXTERNAL = 446,
     T_FULL = 447,
     T_INVISIBLE = 448,
     T_IPV4 = 449,
     T_IPV6 = 450,
     T_LOCOPS = 451,
     T_MAX_CLIENTS = 452,
     T_NCHANGE = 453,
     T_OPERWALL = 454,
     T_REJ = 455,
     T_SERVER = 456,
     T_SERVNOTICE = 457,
     T_SKILL = 458,
     T_SPY = 459,
     T_SSL = 460,
     T_UMODES = 461,
     T_UNAUTH = 462,
     T_UNDLINE = 463,
     T_UNLIMITED = 464,
     T_UNRESV = 465,
     T_UNXLINE = 466,
     T_GLOBOPS = 467,
     T_WALLOP = 468,
     T_RESTART = 469,
     T_SERVICE = 470,
     T_SERVICES_NAME = 471,
     T_TIMESTAMP = 472,
     THROTTLE_TIME = 473,
     TOPICBURST = 474,
     TRUE_NO_OPER_FLOOD = 475,
     TKLINE = 476,
     TXLINE = 477,
     TRESV = 478,
     UNKLINE = 479,
     USER = 480,
     USE_EGD = 481,
     USE_EXCEPT = 482,
     USE_INVEX = 483,
     USE_KNOCK = 484,
     USE_LOGGING = 485,
     USE_WHOIS_ACTUALLY = 486,
     VHOST = 487,
     VHOST6 = 488,
     XLINE = 489,
     WARN = 490,
     WARN_NO_NLINE = 491,
     T_SIZE = 492,
     T_FILE = 493
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
#define T_SSL_CONNECTION_METHOD 401
#define T_SSLV3 402
#define T_TLSV1 403
#define RESV 404
#define RESV_EXEMPT 405
#define SECONDS 406
#define MINUTES 407
#define HOURS 408
#define DAYS 409
#define WEEKS 410
#define SENDQ 411
#define SEND_PASSWORD 412
#define SERVERHIDE 413
#define SERVERINFO 414
#define IRCD_SID 415
#define TKLINE_EXPIRE_NOTICES 416
#define T_SHARED 417
#define T_CLUSTER 418
#define TYPE 419
#define SHORT_MOTD 420
#define SILENT 421
#define SPOOF 422
#define SPOOF_NOTICE 423
#define STATS_E_DISABLED 424
#define STATS_I_OPER_ONLY 425
#define STATS_K_OPER_ONLY 426
#define STATS_O_OPER_ONLY 427
#define STATS_P_OPER_ONLY 428
#define TBOOL 429
#define TMASKED 430
#define T_REJECT 431
#define TS_MAX_DELTA 432
#define TS_WARN_DELTA 433
#define TWODOTS 434
#define T_ALL 435
#define T_BOTS 436
#define T_SOFTCALLERID 437
#define T_CALLERID 438
#define T_CCONN 439
#define T_CCONN_FULL 440
#define T_CLIENT_FLOOD 441
#define T_DEAF 442
#define T_DEBUG 443
#define T_DLINE 444
#define T_DRONE 445
#define T_EXTERNAL 446
#define T_FULL 447
#define T_INVISIBLE 448
#define T_IPV4 449
#define T_IPV6 450
#define T_LOCOPS 451
#define T_MAX_CLIENTS 452
#define T_NCHANGE 453
#define T_OPERWALL 454
#define T_REJ 455
#define T_SERVER 456
#define T_SERVNOTICE 457
#define T_SKILL 458
#define T_SPY 459
#define T_SSL 460
#define T_UMODES 461
#define T_UNAUTH 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_GLOBOPS 467
#define T_WALLOP 468
#define T_RESTART 469
#define T_SERVICE 470
#define T_SERVICES_NAME 471
#define T_TIMESTAMP 472
#define THROTTLE_TIME 473
#define TOPICBURST 474
#define TRUE_NO_OPER_FLOOD 475
#define TKLINE 476
#define TXLINE 477
#define TRESV 478
#define UNKLINE 479
#define USER 480
#define USE_EGD 481
#define USE_EXCEPT 482
#define USE_INVEX 483
#define USE_KNOCK 484
#define USE_LOGGING 485
#define USE_WHOIS_ACTUALLY 486
#define VHOST 487
#define VHOST6 488
#define XLINE 489
#define WARN 490
#define WARN_NO_NLINE 491
#define T_SIZE 492
#define T_FILE 493




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 698 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 710 "ircd_parser.c"

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
#define YYLAST   1354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  244
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  301
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1292

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   243,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   239,
       2,   242,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   241,     2,   240,     2,     2,     2,     2,
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
     235,   236,   237,   238
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
    1014,  1016,  1018,  1020,  1022,  1024,  1027,  1032,  1037,  1042,
    1047,  1052,  1057,  1062,  1067,  1068,  1074,  1078,  1080,  1082,
    1084,  1086,  1088,  1093,  1098,  1103,  1108,  1109,  1116,  1117,
    1123,  1127,  1129,  1131,  1134,  1136,  1138,  1140,  1142,  1144,
    1149,  1154,  1155,  1162,  1165,  1167,  1169,  1171,  1173,  1178,
    1183,  1189,  1192,  1194,  1196,  1198,  1203,  1204,  1211,  1212,
    1218,  1222,  1224,  1226,  1229,  1231,  1233,  1235,  1237,  1239,
    1244,  1249,  1255,  1258,  1260,  1262,  1264,  1266,  1268,  1270,
    1272,  1274,  1276,  1278,  1280,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1310,
    1312,  1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,
    1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1369,  1374,  1379,
    1384,  1389,  1394,  1399,  1404,  1409,  1414,  1419,  1424,  1429,
    1434,  1439,  1444,  1449,  1454,  1459,  1464,  1469,  1474,  1479,
    1484,  1489,  1494,  1499,  1504,  1509,  1514,  1519,  1524,  1529,
    1534,  1539,  1544,  1549,  1554,  1559,  1564,  1569,  1574,  1579,
    1584,  1589,  1594,  1599,  1600,  1606,  1610,  1612,  1614,  1616,
    1618,  1620,  1622,  1624,  1626,  1628,  1630,  1632,  1634,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1653,  1659,
    1663,  1665,  1667,  1669,  1671,  1673,  1675,  1677,  1679,  1681,
    1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,  1701,
    1703,  1705,  1710,  1715,  1720,  1725,  1726,  1733,  1736,  1738,
    1740,  1742,  1744,  1746,  1748,  1750,  1752,  1757,  1762,  1763,
    1769,  1773,  1775,  1777,  1779,  1784,  1789,  1790,  1796,  1800,
    1802,  1804,  1806,  1812,  1815,  1817,  1819,  1821,  1823,  1825,
    1827,  1829,  1831,  1833,  1835,  1837,  1839,  1841,  1843,  1845,
    1847,  1849,  1851,  1853,  1855,  1860,  1865,  1870,  1875,  1880,
    1885,  1890,  1895,  1900,  1905,  1910,  1915,  1920,  1925,  1930,
    1935,  1940,  1945,  1951,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1968,  1970,  1972,  1977,  1982,  1987,  1992,  1997,  2002
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     245,     0,    -1,    -1,   245,   246,    -1,   274,    -1,   280,
      -1,   295,    -1,   514,    -1,   313,    -1,   330,    -1,   344,
      -1,   256,    -1,   535,    -1,   359,    -1,   366,    -1,   370,
      -1,   380,    -1,   389,    -1,   408,    -1,   418,    -1,   424,
      -1,   438,    -1,   498,    -1,   428,    -1,   251,    -1,     1,
     239,    -1,     1,   240,    -1,    -1,   248,    -1,   110,   247,
      -1,   110,   151,   247,    -1,   110,   152,   247,    -1,   110,
     153,   247,    -1,   110,   154,   247,    -1,   110,   155,   247,
      -1,    -1,   250,    -1,   110,   249,    -1,   110,    14,   249,
      -1,   110,    15,   249,    -1,   110,    16,   249,    -1,    99,
     241,   252,   240,   239,    -1,   252,   253,    -1,   253,    -1,
     254,    -1,   255,    -1,     1,   239,    -1,    98,   242,   131,
     239,    -1,   126,   242,   131,   239,    -1,   159,   241,   257,
     240,   239,    -1,   257,   258,    -1,   258,    -1,   265,    -1,
     270,    -1,   273,    -1,   267,    -1,   268,    -1,   269,    -1,
     272,    -1,   264,    -1,   271,    -1,   266,    -1,   263,    -1,
     259,    -1,     1,   239,    -1,    -1,   146,   260,   242,   261,
     239,    -1,   261,   243,   262,    -1,   262,    -1,   147,    -1,
     148,    -1,   145,   242,   131,   239,    -1,   143,   242,   131,
     239,    -1,   100,   242,   131,   239,    -1,   160,   242,   131,
     239,    -1,    31,   242,   131,   239,    -1,   103,   242,   131,
     239,    -1,   102,   242,   131,   239,    -1,   232,   242,   131,
     239,    -1,   233,   242,   131,   239,    -1,   197,   242,   110,
     239,    -1,    67,   242,   174,   239,    -1,     5,   241,   275,
     240,   239,    -1,   275,   276,    -1,   276,    -1,   277,    -1,
     279,    -1,   278,    -1,     1,   239,    -1,   100,   242,   131,
     239,    -1,    41,   242,   131,   239,    -1,    31,   242,   131,
     239,    -1,    83,   241,   281,   240,   239,    -1,   281,   282,
      -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,     1,
     239,    -1,   230,   242,   174,   239,    -1,   217,   242,   174,
     239,    -1,    -1,   286,   238,   241,   287,   240,   239,    -1,
     287,   288,    -1,   288,    -1,   289,    -1,   291,    -1,   290,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,   237,
     242,   250,   239,    -1,   237,   242,   209,   239,    -1,    -1,
     164,   292,   242,   293,   239,    -1,   293,   243,   294,    -1,
     294,    -1,   225,    -1,   115,    -1,    51,    -1,   189,    -1,
      74,    -1,    72,    -1,   188,    -1,    -1,   115,   296,   241,
     297,   240,   239,    -1,   297,   298,    -1,   298,    -1,   299,
      -1,   300,    -1,   301,    -1,   305,    -1,   304,    -1,   302,
      -1,   303,    -1,   309,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,   225,   242,   131,   239,    -1,   125,   242,
     131,   239,    -1,    43,   242,   174,   239,    -1,   144,   242,
     131,   239,    -1,    24,   242,   131,   239,    -1,    -1,   206,
     306,   242,   307,   239,    -1,   307,   243,   308,    -1,   308,
      -1,   181,    -1,   184,    -1,   185,    -1,   187,    -1,   188,
      -1,   192,    -1,    61,    -1,   203,    -1,   198,    -1,   200,
      -1,   207,    -1,   204,    -1,   191,    -1,   199,    -1,   202,
      -1,   193,    -1,   213,    -1,   182,    -1,   183,    -1,   196,
      -1,    -1,    47,   310,   242,   311,   239,    -1,   311,   243,
     312,    -1,   312,    -1,    57,    -1,   139,    -1,    74,    -1,
     224,    -1,   189,    -1,   208,    -1,   234,    -1,    51,    -1,
      32,    -1,   214,    -1,   137,    -1,     5,    -1,   105,    -1,
     199,    -1,   212,    -1,   119,    -1,   140,    -1,    98,    -1,
      -1,    24,   314,   241,   315,   240,   239,    -1,   315,   316,
      -1,   316,    -1,   317,    -1,   327,    -1,   328,    -1,   318,
      -1,   319,    -1,   329,    -1,   320,    -1,   321,    -1,   322,
      -1,   323,    -1,   324,    -1,   325,    -1,   326,    -1,     1,
     239,    -1,   100,   242,   131,   239,    -1,   128,   242,   248,
     239,    -1,   129,   242,   248,   239,    -1,   113,   242,   110,
     239,    -1,    26,   242,   248,   239,    -1,    92,   242,   110,
     239,    -1,    87,   242,   110,   239,    -1,    89,   242,   110,
     239,    -1,    88,   242,   110,   239,    -1,   156,   242,   250,
     239,    -1,    22,   242,   110,   239,    -1,    23,   242,   110,
     239,    -1,   112,   242,   110,   239,    -1,    -1,    82,   331,
     241,   336,   240,   239,    -1,    -1,    47,   333,   242,   334,
     239,    -1,   334,   243,   335,    -1,   335,    -1,   205,    -1,
      61,    -1,   201,    -1,   336,   337,    -1,   337,    -1,   338,
      -1,   332,    -1,   342,    -1,   343,    -1,     1,   239,    -1,
      -1,   130,   242,   340,   339,   239,    -1,   340,   243,   341,
      -1,   341,    -1,   110,    -1,   110,   179,   110,    -1,    71,
     242,   131,   239,    -1,    66,   242,   131,   239,    -1,    -1,
      58,   345,   241,   346,   240,   239,    -1,   346,   347,    -1,
     347,    -1,   348,    -1,   349,    -1,   350,    -1,   352,    -1,
     356,    -1,   357,    -1,   358,    -1,   351,    -1,     1,   239,
      -1,   225,   242,   131,   239,    -1,   125,   242,   131,   239,
      -1,    24,   242,   131,   239,    -1,    43,   242,   174,   239,
      -1,    -1,    47,   353,   242,   354,   239,    -1,   354,   243,
     355,    -1,   355,    -1,   168,    -1,    44,    -1,    75,    -1,
      59,    -1,    20,    -1,   109,    -1,    53,    -1,   150,    -1,
     101,    -1,   167,   242,   131,   239,    -1,   135,   242,   131,
     239,    -1,   134,   242,   110,   239,    -1,    -1,   149,   360,
     241,   361,   240,   239,    -1,   361,   362,    -1,   362,    -1,
     363,    -1,   364,    -1,   365,    -1,     1,   239,    -1,   133,
     242,   131,   239,    -1,    21,   242,   131,   239,    -1,   104,
     242,   131,   239,    -1,   215,   241,   367,   240,   239,    -1,
     367,   368,    -1,   368,    -1,   369,    -1,     1,    -1,   100,
     242,   131,   239,    -1,    -1,   162,   371,   241,   372,   240,
     239,    -1,   372,   373,    -1,   373,    -1,   374,    -1,   375,
      -1,   376,    -1,     1,   239,    -1,   100,   242,   131,   239,
      -1,   225,   242,   131,   239,    -1,    -1,   164,   377,   242,
     378,   239,    -1,   378,   243,   379,    -1,   379,    -1,    74,
      -1,   224,    -1,   189,    -1,   208,    -1,   234,    -1,   211,
      -1,   149,    -1,   210,    -1,   196,    -1,   180,    -1,    -1,
     163,   381,   241,   382,   240,   239,    -1,   382,   383,    -1,
     383,    -1,   384,    -1,   385,    -1,     1,   239,    -1,   100,
     242,   131,   239,    -1,    -1,   164,   386,   242,   387,   239,
      -1,   387,   243,   388,    -1,   388,    -1,    74,    -1,   224,
      -1,   189,    -1,   208,    -1,   234,    -1,   211,    -1,   149,
      -1,   210,    -1,   196,    -1,   180,    -1,    -1,    25,   390,
     241,   391,   240,   239,    -1,   391,   392,    -1,   392,    -1,
     393,    -1,   394,    -1,   395,    -1,   396,    -1,   397,    -1,
     399,    -1,   398,    -1,   400,    -1,   405,    -1,   406,    -1,
     407,    -1,   404,    -1,     1,   239,    -1,   100,   242,   131,
     239,    -1,    66,   242,   131,   239,    -1,   232,   242,   131,
     239,    -1,   157,   242,   131,   239,    -1,     3,   242,   131,
     239,    -1,   130,   242,   110,   239,    -1,     6,   242,   194,
     239,    -1,     6,   242,   195,   239,    -1,    -1,    47,   401,
     242,   402,   239,    -1,   402,   243,   403,    -1,   403,    -1,
      10,    -1,    12,    -1,   219,    -1,   205,    -1,    43,   242,
     174,   239,    -1,    68,   242,   131,   239,    -1,    80,   242,
     131,   239,    -1,    24,   242,   131,   239,    -1,    -1,    72,
     409,   241,   414,   240,   239,    -1,    -1,   164,   411,   242,
     412,   239,    -1,   412,   243,   413,    -1,   413,    -1,   136,
      -1,   414,   415,    -1,   415,    -1,   416,    -1,   417,    -1,
     410,    -1,     1,    -1,   225,   242,   131,   239,    -1,   133,
     242,   131,   239,    -1,    -1,    30,   419,   241,   420,   240,
     239,    -1,   420,   421,    -1,   421,    -1,   422,    -1,   423,
      -1,     1,    -1,    71,   242,   131,   239,    -1,   133,   242,
     131,   239,    -1,    45,   241,   425,   240,   239,    -1,   425,
     426,    -1,   426,    -1,   427,    -1,     1,    -1,    71,   242,
     131,   239,    -1,    -1,    49,   429,   241,   434,   240,   239,
      -1,    -1,   164,   431,   242,   432,   239,    -1,   432,   243,
     433,    -1,   433,    -1,   136,    -1,   434,   435,    -1,   435,
      -1,   436,    -1,   437,    -1,   430,    -1,     1,    -1,   100,
     242,   131,   239,    -1,   133,   242,   131,   239,    -1,    50,
     241,   439,   240,   239,    -1,   439,   440,    -1,   440,    -1,
     448,    -1,   449,    -1,   451,    -1,   452,    -1,   453,    -1,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   458,    -1,
     447,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     478,    -1,   465,    -1,   467,    -1,   469,    -1,   468,    -1,
     472,    -1,   466,    -1,   473,    -1,   474,    -1,   475,    -1,
     476,    -1,   477,    -1,   490,    -1,   479,    -1,   480,    -1,
     481,    -1,   486,    -1,   470,    -1,   471,    -1,   496,    -1,
     494,    -1,   495,    -1,   450,    -1,   497,    -1,   485,    -1,
     459,    -1,   483,    -1,   484,    -1,   446,    -1,   442,    -1,
     443,    -1,   444,    -1,   445,    -1,   464,    -1,   441,    -1,
     482,    -1,     1,    -1,    94,   242,   110,   239,    -1,    55,
     242,   110,   239,    -1,    56,   242,   110,   239,    -1,   231,
     242,   174,   239,    -1,   138,   242,   248,   239,    -1,   161,
     242,   174,   239,    -1,    73,   242,   248,   239,    -1,    65,
     242,   174,   239,    -1,    69,   242,   174,   239,    -1,    37,
     242,   174,   239,    -1,    46,   242,   174,   239,    -1,     8,
     242,   174,   239,    -1,    91,   242,   248,   239,    -1,    90,
     242,   110,   239,    -1,    84,   242,   110,   239,    -1,     9,
     242,   248,   239,    -1,   178,   242,   248,   239,    -1,   177,
     242,   248,   239,    -1,    60,   242,   110,   239,    -1,    77,
     242,   174,   239,    -1,    76,   242,   131,   239,    -1,    70,
     242,   174,   239,    -1,   236,   242,   174,   239,    -1,   169,
     242,   174,   239,    -1,   172,   242,   174,   239,    -1,   173,
     242,   174,   239,    -1,   171,   242,   174,   239,    -1,   171,
     242,   175,   239,    -1,   170,   242,   174,   239,    -1,   170,
     242,   175,   239,    -1,   123,   242,   248,   239,    -1,    19,
     242,   248,   239,    -1,   116,   242,   174,   239,    -1,   124,
     242,   248,   239,    -1,   165,   242,   174,   239,    -1,   108,
     242,   174,   239,    -1,   220,   242,   174,   239,    -1,   118,
     242,   174,   239,    -1,    95,   242,   131,   239,    -1,    38,
     242,   110,   239,    -1,    93,   242,   110,   239,    -1,   226,
     242,   174,   239,    -1,    40,   242,   131,   239,    -1,   216,
     242,   131,   239,    -1,   127,   242,   174,   239,    -1,    33,
     242,   174,   239,    -1,   218,   242,   248,   239,    -1,    -1,
     120,   487,   242,   488,   239,    -1,   488,   243,   489,    -1,
     489,    -1,   181,    -1,   184,    -1,   185,    -1,   187,    -1,
     188,    -1,   192,    -1,    61,    -1,   203,    -1,   198,    -1,
     200,    -1,   207,    -1,   204,    -1,   191,    -1,   199,    -1,
     202,    -1,   193,    -1,   213,    -1,   182,    -1,   183,    -1,
     196,    -1,    -1,   117,   491,   242,   492,   239,    -1,   492,
     243,   493,    -1,   493,    -1,   181,    -1,   184,    -1,   185,
      -1,   187,    -1,   188,    -1,   192,    -1,   203,    -1,    61,
      -1,   198,    -1,   200,    -1,   207,    -1,   204,    -1,   191,
      -1,   199,    -1,   202,    -1,   193,    -1,   213,    -1,   182,
      -1,   183,    -1,   196,    -1,    96,   242,   110,   239,    -1,
      97,   242,   110,   239,    -1,    27,   242,   110,   239,    -1,
     186,   242,   250,   239,    -1,    -1,    52,   499,   241,   500,
     240,   239,    -1,   500,   501,    -1,   501,    -1,   502,    -1,
     503,    -1,   504,    -1,   508,    -1,   509,    -1,   510,    -1,
       1,    -1,    42,   242,   174,   239,    -1,    39,   242,   248,
     239,    -1,    -1,    83,   505,   242,   506,   239,    -1,   506,
     243,   507,    -1,   507,    -1,   176,    -1,    11,    -1,   225,
     242,   131,   239,    -1,   100,   242,   131,   239,    -1,    -1,
       4,   511,   242,   512,   239,    -1,   512,   243,   513,    -1,
     513,    -1,   176,    -1,    11,    -1,    21,   241,   515,   240,
     239,    -1,   515,   516,    -1,   516,    -1,   519,    -1,   520,
      -1,   521,    -1,   522,    -1,   527,    -1,   523,    -1,   524,
      -1,   525,    -1,   526,    -1,   528,    -1,   529,    -1,   530,
      -1,   518,    -1,   531,    -1,   532,    -1,   533,    -1,   534,
      -1,   517,    -1,     1,    -1,    34,   242,   174,   239,    -1,
     141,   242,   174,   239,    -1,    36,   242,   174,   239,    -1,
     227,   242,   174,   239,    -1,   228,   242,   174,   239,    -1,
     229,   242,   174,   239,    -1,    78,   242,   248,   239,    -1,
      79,   242,   248,   239,    -1,    86,   242,   110,   239,    -1,
     132,   242,   174,   239,    -1,    85,   242,   110,   239,    -1,
      29,   242,   110,   239,    -1,    28,   242,   110,   239,    -1,
     106,   242,   174,   239,    -1,   107,   242,   174,   239,    -1,
      13,   242,   174,   239,    -1,   121,   242,   110,   239,    -1,
     122,   242,   248,   239,    -1,   158,   241,   536,   240,   239,
      -1,   536,   537,    -1,   537,    -1,   538,    -1,   539,    -1,
     541,    -1,   543,    -1,   542,    -1,   540,    -1,   544,    -1,
       1,    -1,    48,   242,   174,   239,    -1,    64,   242,   174,
     239,    -1,    62,   242,   131,   239,    -1,    81,   242,   248,
     239,    -1,    61,   242,   174,   239,    -1,    35,   242,   174,
     239,    -1,    63,   242,   174,   239,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   374,   374,   375,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   404,   404,   405,
     409,   413,   417,   421,   425,   431,   431,   432,   433,   434,
     435,   442,   445,   445,   446,   446,   446,   448,   454,   461,
     463,   463,   464,   464,   465,   465,   466,   466,   467,   468,
     468,   469,   469,   470,   471,   475,   474,   500,   500,   501,
     507,   515,   554,   614,   629,   644,   653,   667,   676,   704,
     734,   757,   766,   768,   768,   769,   769,   770,   770,   772,
     781,   790,   802,   803,   803,   805,   805,   805,   806,   808,
     814,   821,   821,   831,   832,   834,   834,   835,   835,   837,
     842,   845,   851,   850,   856,   856,   857,   861,   865,   869,
     873,   877,   881,   892,   891,   989,   989,   990,   990,   990,
     991,   991,   991,   992,   992,   992,   994,  1006,  1043,  1055,
    1066,  1108,  1118,  1117,  1123,  1123,  1124,  1128,  1132,  1136,
    1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1176,
    1180,  1184,  1188,  1192,  1196,  1200,  1207,  1206,  1212,  1212,
    1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,
    1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,  1292,  1291,
    1341,  1341,  1342,  1343,  1343,  1344,  1345,  1346,  1347,  1348,
    1349,  1350,  1351,  1352,  1353,  1354,  1356,  1365,  1371,  1377,
    1383,  1389,  1395,  1401,  1407,  1413,  1419,  1425,  1431,  1441,
    1440,  1457,  1456,  1461,  1461,  1462,  1466,  1470,  1478,  1478,
    1479,  1479,  1479,  1479,  1479,  1481,  1481,  1483,  1483,  1485,
    1499,  1519,  1528,  1541,  1540,  1609,  1609,  1610,  1610,  1610,
    1610,  1611,  1611,  1611,  1612,  1612,  1614,  1651,  1664,  1673,
    1685,  1684,  1688,  1688,  1689,  1693,  1697,  1701,  1705,  1709,
    1713,  1717,  1721,  1728,  1747,  1757,  1771,  1770,  1786,  1786,
    1787,  1787,  1787,  1787,  1789,  1798,  1813,  1826,  1828,  1828,
    1829,  1829,  1831,  1847,  1846,  1862,  1862,  1863,  1863,  1863,
    1863,  1865,  1874,  1897,  1896,  1902,  1902,  1903,  1907,  1911,
    1915,  1919,  1923,  1927,  1931,  1935,  1939,  1949,  1948,  1965,
    1965,  1966,  1966,  1966,  1968,  1975,  1974,  1980,  1980,  1981,
    1985,  1989,  1993,  1997,  2001,  2005,  2009,  2013,  2017,  2027,
    2026,  2155,  2155,  2156,  2156,  2156,  2157,  2157,  2158,  2158,
    2159,  2159,  2159,  2160,  2160,  2161,  2163,  2175,  2184,  2210,
    2228,  2246,  2252,  2256,  2265,  2264,  2268,  2268,  2269,  2273,
    2277,  2281,  2287,  2298,  2311,  2324,  2337,  2336,  2400,  2399,
    2403,  2403,  2404,  2410,  2410,  2411,  2411,  2411,  2411,  2413,
    2432,  2442,  2441,  2464,  2464,  2465,  2465,  2465,  2467,  2473,
    2482,  2484,  2484,  2485,  2485,  2487,  2506,  2505,  2553,  2552,
    2556,  2556,  2557,  2563,  2563,  2564,  2564,  2564,  2564,  2566,
    2572,  2581,  2584,  2584,  2585,  2585,  2586,  2586,  2587,  2587,
    2588,  2588,  2589,  2589,  2590,  2590,  2591,  2591,  2592,  2592,
    2593,  2593,  2594,  2594,  2595,  2595,  2596,  2596,  2597,  2597,
    2598,  2599,  2599,  2600,  2600,  2601,  2601,  2602,  2602,  2603,
    2603,  2604,  2605,  2606,  2606,  2607,  2608,  2609,  2609,  2610,
    2610,  2611,  2611,  2612,  2612,  2613,  2616,  2621,  2626,  2631,
    2636,  2641,  2646,  2651,  2656,  2661,  2666,  2671,  2676,  2681,
    2686,  2691,  2696,  2701,  2707,  2718,  2723,  2732,  2737,  2742,
    2747,  2752,  2757,  2760,  2765,  2768,  2773,  2778,  2783,  2788,
    2793,  2798,  2803,  2808,  2813,  2824,  2829,  2834,  2839,  2848,
    2857,  2862,  2867,  2873,  2872,  2877,  2877,  2878,  2881,  2884,
    2887,  2890,  2893,  2896,  2899,  2902,  2905,  2908,  2911,  2914,
    2917,  2920,  2923,  2926,  2929,  2932,  2935,  2941,  2940,  2945,
    2945,  2946,  2949,  2952,  2955,  2958,  2961,  2964,  2967,  2970,
    2973,  2976,  2979,  2982,  2985,  2988,  2991,  2994,  2997,  3000,
    3003,  3008,  3013,  3018,  3023,  3033,  3032,  3056,  3056,  3057,
    3058,  3059,  3060,  3061,  3062,  3063,  3065,  3071,  3078,  3077,
    3082,  3082,  3083,  3087,  3093,  3127,  3137,  3136,  3186,  3186,
    3187,  3191,  3200,  3203,  3203,  3204,  3204,  3205,  3205,  3206,
    3206,  3207,  3207,  3208,  3208,  3209,  3210,  3210,  3211,  3211,
    3212,  3212,  3213,  3213,  3215,  3220,  3225,  3230,  3235,  3240,
    3245,  3250,  3255,  3260,  3265,  3270,  3275,  3280,  3285,  3290,
    3295,  3300,  3308,  3311,  3311,  3312,  3312,  3313,  3314,  3315,
    3315,  3316,  3317,  3319,  3325,  3331,  3340,  3354,  3360,  3366
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
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "T_SSL_CONNECTION_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
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
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class", "kill_entry",
  "$@20", "kill_type", "$@21", "kill_type_items", "kill_type_item",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@22", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@23", "gecos_flags", "$@24", "gecos_flags_items",
  "gecos_flags_item", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_max_watch", "general_gline_min_cidr", "general_gline_min_cidr6",
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
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,    59,
     125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   247,   247,   248,
     248,   248,   248,   248,   248,   249,   249,   250,   250,   250,
     250,   251,   252,   252,   253,   253,   253,   254,   255,   256,
     257,   257,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   260,   259,   261,   261,   262,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   275,   276,   276,   276,   276,   277,
     278,   279,   280,   281,   281,   282,   282,   282,   282,   283,
     284,   286,   285,   287,   287,   288,   288,   288,   288,   289,
     290,   290,   292,   291,   293,   293,   294,   294,   294,   294,
     294,   294,   294,   296,   295,   297,   297,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   299,   300,   301,   302,
     303,   304,   306,   305,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   310,   309,   311,   311,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   314,   313,
     315,   315,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   331,
     330,   333,   332,   334,   334,   335,   335,   335,   336,   336,
     337,   337,   337,   337,   337,   339,   338,   340,   340,   341,
     341,   342,   343,   345,   344,   346,   346,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   348,   349,   350,   351,
     353,   352,   354,   354,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   356,   357,   358,   360,   359,   361,   361,
     362,   362,   362,   362,   363,   364,   365,   366,   367,   367,
     368,   368,   369,   371,   370,   372,   372,   373,   373,   373,
     373,   374,   375,   377,   376,   378,   378,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   381,   380,   382,
     382,   383,   383,   383,   384,   386,   385,   387,   387,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   390,
     389,   391,   391,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   393,   394,   395,   396,
     397,   398,   399,   399,   401,   400,   402,   402,   403,   403,
     403,   403,   404,   405,   406,   407,   409,   408,   411,   410,
     412,   412,   413,   414,   414,   415,   415,   415,   415,   416,
     417,   419,   418,   420,   420,   421,   421,   421,   422,   423,
     424,   425,   425,   426,   426,   427,   429,   428,   431,   430,
     432,   432,   433,   434,   434,   435,   435,   435,   435,   436,
     437,   438,   439,   439,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   467,   468,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   487,   486,   488,   488,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   491,   490,   492,
     492,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   494,   495,   496,   497,   499,   498,   500,   500,   501,
     501,   501,   501,   501,   501,   501,   502,   503,   505,   504,
     506,   506,   507,   507,   508,   509,   511,   510,   512,   512,
     513,   513,   514,   515,   515,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   516,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   536,   537,   537,   537,   537,   537,
     537,   537,   537,   538,   539,   540,   541,   542,   543,   544
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
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     0,     6,     0,     5,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     0,     5,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       2,     0,     1,     0,     0,     0,   188,   339,   391,     0,
     406,     0,   575,   243,   376,   219,     0,     0,   123,   276,
       0,     0,   293,   317,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    87,    86,   623,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   604,
     622,   617,   605,   606,   607,   608,   610,   611,   612,   613,
     609,   614,   615,   616,   618,   619,   620,   621,     0,     0,
       0,   404,     0,     0,   402,   403,     0,   475,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   547,     0,   523,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,   473,   468,   469,   470,   471,   467,   434,   424,   425,
     461,   426,   427,   428,   429,   430,   431,   432,   433,   464,
     435,   436,   437,   438,   472,   440,   445,   441,   443,   442,
     456,   457,   444,   446,   447,   448,   449,   450,   439,   452,
     453,   454,   474,   465,   466,   463,   455,   451,   459,   460,
     458,   462,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,     0,     0,     0,     0,     0,    43,
      44,    45,     0,     0,   652,     0,     0,     0,     0,     0,
       0,     0,     0,   644,   645,   646,   650,   647,   649,   648,
     651,     0,     0,     0,     0,     0,     0,     0,     0,    65,
       0,     0,     0,     0,     0,    51,    63,    62,    59,    52,
      61,    55,    56,    57,    53,    60,    58,    54,     0,     0,
     291,     0,     0,   289,   290,    88,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   191,   192,   195,   196,
     198,   199,   200,   201,   202,   203,   204,   193,   194,   197,
       0,     0,     0,     0,     0,   364,     0,     0,     0,     0,
       0,     0,     0,     0,   342,   343,   344,   345,   346,   347,
     349,   348,   350,   354,   351,   352,   353,   397,     0,     0,
       0,   394,   395,   396,     0,     0,   401,   418,     0,     0,
     408,   417,     0,   414,   415,   416,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   422,   585,
     596,     0,     0,   588,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,   246,   247,   248,   249,   254,   250,
     251,   252,   253,   388,     0,   378,     0,   387,     0,   384,
     385,   386,     0,   221,     0,     0,     0,   231,     0,   229,
     230,   232,   233,    98,     0,     0,     0,    93,     0,    46,
       0,     0,     0,    42,     0,     0,     0,   166,     0,     0,
       0,   142,     0,     0,   126,   127,   128,   129,   132,   133,
     131,   130,   134,     0,     0,     0,     0,     0,   279,   280,
     281,   282,     0,     0,     0,     0,     0,     0,     0,     0,
     643,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    50,     0,     0,   303,     0,
       0,   296,   297,   298,   299,     0,     0,   325,     0,   320,
     321,   322,     0,     0,   288,     0,     0,     0,    82,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   602,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   190,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   341,
       0,     0,     0,   393,     0,   400,     0,     0,     0,     0,
     413,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,   577,   255,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,     0,     0,     0,     0,   383,
     234,     0,     0,     0,     0,     0,   228,     0,     0,    92,
       0,     0,     0,    41,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,   283,     0,     0,     0,     0,
     278,     0,     0,     0,     0,     0,     0,     0,   642,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,   300,     0,     0,     0,     0,   295,   323,     0,
       0,     0,   319,     0,   287,    91,    90,    89,   639,   636,
     635,   624,   626,    27,    27,    27,    27,    27,    29,    28,
     630,   631,   634,   632,   637,   638,   640,   641,   633,   625,
     627,   628,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,     0,     0,   392,   405,     0,     0,     0,   407,   487,
     491,   507,   573,   521,   485,   515,   518,   486,   477,   478,
     494,   483,   484,   497,   482,   496,   495,   490,   489,   488,
     516,   476,   514,   571,   572,   511,   508,   558,   551,   568,
     569,   552,   553,   554,   555,   563,   556,   566,   570,   559,
     564,   560,   565,   557,   562,   561,   567,     0,   550,   513,
     533,   527,   544,   545,   528,   529,   530,   531,   539,   532,
     542,   546,   535,   540,   536,   541,   534,   538,   537,   543,
       0,   526,   506,   509,   520,   480,   481,   510,   499,   504,
     505,   502,   503,   500,   501,   493,   492,    35,    35,    35,
      37,    36,   574,   519,   522,   512,   517,   479,   498,     0,
       0,     0,     0,     0,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,   244,     0,     0,     0,   377,     0,
       0,     0,   239,   235,   238,   220,   100,    99,     0,     0,
     112,     0,     0,   104,   105,   107,   106,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,   124,     0,     0,
       0,   277,   658,   653,   657,   655,   659,   654,   656,    75,
      81,    73,    77,    76,    72,    71,    69,    70,     0,    68,
      74,    80,    78,    79,     0,     0,     0,   294,     0,     0,
     318,   292,    30,    31,    32,    33,    34,   216,   217,   210,
     212,   214,   213,   211,   206,   218,   209,   207,   208,   215,
     360,   362,   363,   375,   372,   368,   369,   371,   370,     0,
     367,   357,   373,   374,   356,   361,   359,   358,   398,   399,
     419,   420,   412,     0,   411,   548,     0,   524,     0,    38,
      39,    40,   601,   600,     0,   599,   587,   586,   593,   592,
       0,   591,   595,   594,   258,   259,   268,   265,   270,   267,
     266,   272,   269,   271,   264,     0,   263,   257,   275,   274,
     273,   256,   390,   382,     0,   381,   389,   226,   227,   225,
       0,   224,   242,   241,     0,     0,     0,   108,     0,     0,
       0,     0,   103,   141,   139,   181,   178,   177,   170,   172,
     187,   182,   185,   180,   171,   186,   174,   183,   175,   184,
     179,   173,   176,     0,   169,   136,   138,   140,   152,   146,
     163,   164,   147,   148,   149,   150,   158,   151,   161,   165,
     154,   159,   155,   160,   153,   157,   156,   162,     0,   145,
     137,   285,   286,   284,    66,     0,   301,   307,   313,   316,
     309,   315,   310,   314,   312,   308,   311,     0,   306,   302,
     324,   329,   335,   338,   331,   337,   332,   336,   334,   330,
     333,     0,   328,   365,     0,   409,     0,   549,   525,   597,
       0,   589,     0,   261,     0,   379,     0,   222,     0,   240,
     237,   236,     0,     0,     0,     0,   102,   167,     0,   143,
       0,    67,   304,     0,   326,     0,   366,   410,   598,   590,
     262,   380,   223,   109,   118,   121,   120,   117,   122,   119,
     116,     0,   115,   111,   110,   168,   144,   305,   327,   113,
       0,   114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   818,   819,   960,   961,    26,   248,   249,
     250,   251,    27,   284,   285,   286,   569,  1038,  1039,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      28,    74,    75,    76,    77,    78,    29,   239,   240,   241,
     242,   243,   244,  1002,  1003,  1004,  1005,  1006,  1149,  1281,
    1282,    30,    63,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   761,  1198,  1199,   542,   757,  1173,  1174,    31,
      51,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,    32,    60,   507,   741,
    1140,  1141,   508,   509,   510,  1146,   993,   994,   511,   512,
      33,    58,   483,   484,   485,   486,   487,   488,   489,   727,
    1125,  1126,   490,   491,   492,    34,    64,   547,   548,   549,
     550,   551,    35,   302,   303,   304,    36,    67,   580,   581,
     582,   583,   584,   794,  1217,  1218,    37,    68,   588,   589,
     590,   591,   800,  1231,  1232,    38,    52,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   640,  1079,  1080,
     383,   384,   385,   386,    39,    59,   497,   736,  1134,  1135,
     498,   499,   500,   501,    40,    53,   390,   391,   392,   393,
      41,   123,   124,   125,    42,    55,   401,   658,  1093,  1094,
     402,   403,   404,   405,    43,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   436,   940,   941,   227,   434,   917,   918,
     228,   229,   230,   231,    44,    57,   466,   467,   468,   469,
     470,   719,  1110,  1111,   471,   472,   473,   716,  1104,  1105,
      45,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,    46,   262,   263,   264,   265,   266,   267,   268,   269,
     270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -772
static const yytype_int16 yypact[] =
{
    -772,   643,  -772,  -190,  -234,  -231,  -772,  -772,  -772,  -225,
    -772,  -215,  -772,  -772,  -772,  -772,  -207,  -205,  -772,  -772,
    -202,  -194,  -772,  -772,  -174,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   258,
     533,  -171,  -168,  -155,    14,  -146,   367,  -143,  -141,  -134,
    -131,     3,    41,  -128,  -112,   746,   326,  -109,   -98,    20,
    -115,   -90,   -87,   -81,     4,  -772,  -772,  -772,  -772,  -772,
     -71,   -68,   -48,   -45,   -31,   -24,   -15,    21,    23,    54,
      63,    72,    77,    78,    79,    80,    87,    88,   274,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   683,   449,
      47,  -772,    90,    32,  -772,  -772,   192,  -772,    98,   130,
     137,   147,   148,   156,   167,   168,   169,   172,   175,   176,
     177,   178,   179,   183,   188,   196,   197,   199,   200,   203,
     207,   211,   212,   214,   217,   225,  -772,   226,  -772,   228,
     232,   239,   240,   246,   247,   251,   255,   256,   262,   264,
     265,   267,   268,   269,   270,   271,   276,   277,   278,   108,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,   562,   299,    58,   317,    35,   279,   284,    71,
    -772,  -772,  -772,  -772,   116,   209,   285,   288,    53,  -772,
    -772,  -772,   507,   283,  -772,   291,   293,   300,   301,   306,
     309,   310,    18,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,   261,   313,   314,   315,   318,   323,   328,   329,  -772,
     330,   331,   333,   334,   152,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,    12,    70,
    -772,   335,    28,  -772,  -772,  -772,   119,   260,   394,   339,
    -772,   406,   458,   471,   408,   410,   476,   476,   479,   480,
     418,   420,   486,   476,   423,   426,   428,   434,   436,   360,
    -772,   376,   374,   375,   378,   381,   382,   383,   384,   386,
     392,   395,   399,   400,   404,     2,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
     417,   405,   415,   416,   419,  -772,   421,   427,   429,   430,
     433,   435,   438,     8,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   440,   441,
      16,  -772,  -772,  -772,   529,   431,  -772,  -772,   443,   444,
    -772,  -772,    26,  -772,  -772,  -772,   504,   476,   476,   577,
     516,   517,   586,   566,   525,   593,   597,   598,   536,   537,
     538,   476,   585,   543,   608,   609,   476,   610,   611,   591,
     613,   617,   554,   556,   489,   564,   499,   476,   476,   572,
     476,   579,   583,   589,  -117,   -91,   590,   592,   476,   476,
     657,   637,   476,   595,   600,   602,   603,   539,  -772,  -772,
    -772,   542,   544,  -772,   547,   548,    36,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   540,   549,   551,  -772,   555,   557,
     558,   561,   571,    22,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   580,  -772,   581,  -772,    11,  -772,
    -772,  -772,   541,  -772,   599,   601,   605,  -772,    30,  -772,
    -772,  -772,  -772,  -772,   624,   645,   546,  -772,   587,  -772,
     703,   711,   606,  -772,   615,   620,   621,  -772,   623,   627,
     631,  -772,   632,   206,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,   618,   634,   635,   636,    17,  -772,  -772,
    -772,  -772,   670,   674,   706,   751,   709,   710,   476,   646,
    -772,  -772,   755,   713,   757,   758,   759,   760,   761,   651,
     763,   785,   765,   767,   660,  -772,   661,   659,  -772,   662,
      42,  -772,  -772,  -772,  -772,   663,   664,  -772,     5,  -772,
    -772,  -772,   772,   666,  -772,   669,   671,   672,  -772,   673,
     675,   676,   677,   678,   325,   679,   680,   681,   682,   684,
     685,   686,   687,   688,   689,   690,   691,   692,  -772,  -772,
     797,   799,   476,   803,   812,   822,   823,   804,   824,   826,
     476,   476,   657,   698,  -772,  -772,   807,    44,   808,   766,
     699,   811,   813,   814,   815,   833,   816,   817,   712,  -772,
     818,   819,   714,  -772,   715,  -772,   821,   825,   716,   718,
    -772,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   747,   748,   749,   552,
     750,   633,   752,   753,   754,   756,   762,   764,   768,   769,
     770,   771,   773,   774,   775,   776,   777,   355,   778,   779,
     780,   781,   782,   783,   784,  -772,   786,   476,   794,   787,
     854,   859,   788,  -772,  -772,   863,   828,   789,   865,   845,
     866,   867,   868,   791,  -772,   869,   790,   873,   795,  -772,
    -772,   793,   874,   875,   901,   798,  -772,   800,   801,  -772,
     171,   802,   805,  -772,  -772,   893,   851,   796,   895,   902,
     905,   806,   911,   810,  -772,  -772,   912,   914,   915,   820,
    -772,   827,   829,   830,   831,   832,   834,   835,  -772,   836,
     837,   838,   839,   840,   841,   842,   143,   843,   844,   846,
     847,  -772,  -772,   916,   809,   919,   848,  -772,  -772,   921,
     849,   850,  -772,   853,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,   476,   476,   476,   476,   476,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,   855,   856,   857,   858,   860,   861,   862,
     864,   870,   871,   872,   876,   877,  -772,   878,   879,   880,
     881,   882,    10,   883,   884,   885,   886,   887,   888,   889,
    -772,   890,   891,  -772,  -772,   892,   894,   917,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -187,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
     -77,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   657,   657,   657,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,    19,
     896,   897,    33,   898,   899,  -772,   900,   903,   729,   904,
     906,   907,   908,   909,  -772,   910,   918,   913,  -772,     7,
     920,   922,   923,   924,  -772,  -772,  -772,  -772,   925,   926,
    -772,   927,    96,  -772,  -772,  -772,  -772,  -772,  -772,   931,
     932,   490,   933,   934,   935,   668,   936,  -772,   937,   938,
     939,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   -29,  -772,
    -772,  -772,  -772,  -772,   940,   425,   941,  -772,   942,   442,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   -26,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,    74,  -772,  -772,   552,  -772,   633,  -772,
    -772,  -772,  -772,  -772,   102,  -772,  -772,  -772,  -772,  -772,
     104,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,   112,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,   122,  -772,  -772,  -772,  -772,  -772,
     123,  -772,  -772,  -772,   945,   901,   943,  -772,   929,   944,
     -69,   946,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,   124,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,   134,  -772,
    -772,  -772,  -772,  -772,  -772,   143,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   139,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,   158,  -772,  -772,    10,  -772,   917,  -772,  -772,  -772,
      19,  -772,    33,  -772,   729,  -772,   918,  -772,     7,  -772,
    -772,  -772,   948,   149,   949,   950,  -772,  -772,   490,  -772,
     668,  -772,  -772,   425,  -772,   442,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,   160,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
     149,  -772
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -772,  -772,  -772,  -753,  -315,  -771,  -450,  -772,  -772,   947,
    -772,  -772,  -772,  -772,   928,  -772,  -772,  -772,  -149,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,   983,  -772,  -772,  -772,  -772,  -772,   951,  -772,
    -772,  -772,  -772,  -772,    56,  -772,  -772,  -772,  -772,  -772,
    -229,  -772,  -772,  -772,   530,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -198,  -772,  -772,  -772,  -193,  -772,
    -772,  -772,   719,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -181,  -772,   576,  -772,  -772,  -772,   -73,  -772,  -772,
    -772,  -772,  -772,   607,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -156,  -772,  -772,  -772,  -772,  -772,  -772,   559,  -772,
    -772,  -772,  -772,  -772,   852,  -772,  -772,  -772,  -772,   513,
    -772,  -772,  -772,  -772,  -772,  -165,  -772,  -772,  -772,   519,
    -772,  -772,  -772,  -772,  -161,  -772,  -772,  -772,   792,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -129,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -138,
    -772,   614,  -772,  -772,  -772,  -772,  -772,   930,  -772,  -772,
    -772,  -772,   990,  -772,  -772,  -772,  -772,  -772,  -772,  -122,
    -772,   952,  -772,  -772,  -772,  -772,   953,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,    43,  -772,  -772,  -772,    38,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,   694,  -772,  -772,
    -772,  -772,  -772,  -102,  -772,  -772,  -772,  -772,  -772,   -96,
    -772,  -772,  1052,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,  -772,
    -772,  -772,  -772,   954,  -772,  -772,  -772,  -772,  -772,  -772,
    -772
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
     708,   605,   606,   331,   236,    70,   585,    49,   612,   360,
      50,   361,   493,   576,   362,   121,    54,   387,   543,   254,
    1075,   300,  1076,   474,   332,   333,    56,   397,   334,   300,
    1102,   502,   363,   121,    61,    71,    62,   459,   544,    65,
     460,   707,   245,   576,  1108,    72,   475,    66,   387,    47,
      48,   364,  1095,   255,   245,   365,  1096,   699,   700,   493,
    1052,  1053,  1054,  1055,  1056,   476,   256,    69,  1137,   477,
     118,   585,   236,   119,   366,   461,   367,   503,   462,   257,
     258,   259,   260,   701,   702,   122,   120,   388,   368,   335,
     336,   337,   662,   663,   338,   126,   504,   998,   232,   261,
     233,   505,   339,   122,    73,   586,   676,   234,   369,   127,
     235,   681,   577,   252,   340,   341,   128,   129,   388,   463,
     301,   545,   692,   693,   305,   695,   398,   130,   301,   253,
     342,   343,   298,   705,   706,   131,   464,   710,   370,   246,
    1254,   132,   577,   299,   494,   133,   134,   478,   135,   389,
     546,   246,   306,   271,   136,   307,   479,   480,   344,   399,
     506,   308,  1097,   137,   138,   371,  1098,   247,   139,   587,
     586,   311,   998,   140,   312,   495,   578,   141,   142,   247,
     389,   143,   845,   272,   144,   145,  1099,  1100,  1101,   481,
     400,   494,   146,   397,   313,  1103,   999,   314,   147,   148,
    1274,   149,   150,   151,   152,   153,   578,   524,  1138,  1109,
    1204,   315,  1139,  1233,  1205,  1077,   154,  1234,   316,   273,
     237,  1275,   495,  1276,   155,   156,   157,   317,   158,  1078,
     525,   159,   160,   238,   587,   161,   496,   579,   848,   849,
     372,  -101,   633,   777,   309,   801,   162,   482,   648,   526,
     595,   738,   274,   527,   275,   276,   652,   769,   559,    70,
    1000,   465,   733,   318,  1277,   319,   659,   579,   593,   163,
     745,   999,   395,   164,   513,    79,   722,   165,   166,   167,
     168,   169,   796,   496,   543,   170,   171,    80,   237,    71,
    1036,  1037,   398,   522,   172,   277,   320,   278,   279,    72,
     474,   238,    81,    82,   544,   321,   528,   835,    83,  -101,
      84,   516,   280,  1235,   322,   843,   844,  1236,   502,   323,
     324,   325,   326,   475,   173,   399,   174,   271,   175,   327,
     328,   529,   394,  1001,   176,  1000,  1151,  1278,  1279,   177,
     406,  1239,   476,  1241,   178,  1240,   477,  1242,   457,   281,
     530,  1243,    85,    86,   518,  1244,   400,   272,    73,    87,
      88,  1245,  1247,  1257,   503,  1246,  1248,  1258,   127,   957,
     958,   959,   407,  1259,  1280,   128,   129,  1260,  1262,   408,
      89,    90,  1263,   504,   282,   283,   130,   545,   505,   409,
     410,   596,   574,   273,   131,    91,    92,  1264,   411,  1289,
     132,  1265,   970,  1290,   133,   134,    93,   135,  1001,   412,
     413,   414,   531,   136,   415,    94,   546,   416,   417,   418,
     419,   420,   137,   138,   478,   421,   274,   139,   275,   276,
     422,   532,   140,   479,   480,   604,   141,   142,   423,   424,
     143,   425,   426,   144,   145,   427,   763,   506,   519,   428,
     360,   146,   361,   429,   430,   362,   431,   147,   148,   432,
     149,   150,   151,   152,   153,   707,   481,   433,   435,   277,
     437,   278,   279,   363,   438,   154,   813,   814,   815,   816,
     817,   439,   440,   155,   156,   157,   280,   158,   441,   442,
     159,   160,   364,   443,   161,  1155,   365,   444,   445,  1207,
     561,    95,    96,    97,   446,   162,   447,   448,   524,   449,
     450,   451,   452,   453,   329,   366,  1221,   367,   454,   455,
     456,   514,  1156,   281,   482,   597,   515,   520,   163,   368,
     521,   525,   164,   552,    79,   553,   165,   166,   167,   168,
     169,  1157,   554,   555,   170,   171,    80,  1158,   556,   369,
     526,   557,   558,   172,   527,   562,   563,   564,   282,   283,
     565,    81,    82,   459,  1159,   566,   460,    83,   600,    84,
     567,   568,   570,   571,  1208,   572,   573,   592,   598,   370,
     599,   601,   602,   173,   603,   174,   604,   175,  1160,   607,
     608,  1222,   609,   176,   610,  1161,   611,   613,   177,   618,
     614,   461,   615,   178,   462,  1209,   371,   528,   616,  1162,
     617,    85,    86,   897,  1210,   619,   620,   621,    87,    88,
     622,  1211,  1223,   623,   624,   625,   626,  1163,   627,  1164,
    1165,  1224,   529,  1212,   628,  1213,  1214,   629,  1225,    89,
      90,   630,   631,     2,     3,   463,   632,   636,     4,  1215,
    1226,   530,  1227,  1228,    91,    92,   635,   637,   638,  1216,
     654,   639,   464,   641,     5,    93,  1229,     6,     7,   642,
     655,   643,   644,     8,    94,   645,  1230,   646,   661,  1166,
     647,   372,   650,   651,   331,   656,   657,   664,     9,  1167,
     665,   666,    10,    11,   920,    12,   667,   668,  1168,   669,
    1255,    13,  1169,   670,  1170,   332,   333,   671,   672,   334,
     673,   674,   675,   531,  1171,    14,   677,   678,   679,   680,
     682,   683,   684,   685,  1172,    15,    16,   686,   687,  1178,
     688,   689,   532,   898,   899,   900,   901,   902,   690,   903,
     904,   691,    17,   905,   906,   907,   694,   254,   908,  1116,
     909,   910,   911,   696,   912,   913,   914,   697,    18,   915,
      95,    96,    97,   698,   703,   916,   704,   707,   709,   711,
     335,   336,   337,  1117,   712,   338,   713,   714,   715,   724,
     740,   255,  1118,   339,   717,   749,   718,   465,  1119,   720,
     721,   725,    19,   726,   256,   340,   341,   728,   747,   729,
     730,    20,    21,   731,  1120,    22,    23,   257,   258,   259,
     260,   342,   343,   732,   921,   922,   923,   924,   925,   748,
     926,   927,   735,   737,   928,   929,   930,   261,   750,   931,
    1121,   932,   933,   934,   751,   935,   936,   937,  1122,   344,
     938,   742,   752,   743,   771,   753,   939,   744,   772,  1179,
    1180,  1181,  1182,  1183,   754,  1184,  1185,   765,    24,  1186,
    1187,  1188,   755,   756,  1189,   758,  1190,  1191,  1192,   759,
    1193,  1194,  1195,   760,   762,  1196,   766,   767,   768,  1123,
     773,  1197,   774,   775,   776,   778,   779,   780,   781,   782,
     783,   784,   785,   786,   787,   788,   789,  1124,   790,   791,
     792,   793,   798,   803,   795,   804,   799,   833,   805,   834,
     806,   807,   808,   836,   809,   810,   811,   812,   820,   821,
     822,   823,   837,   824,   825,   826,   827,   828,   829,   830,
     831,   832,   838,   839,   841,   840,   842,   846,   847,   850,
     851,   852,   853,   857,   854,   855,   856,   858,   859,   861,
     862,   860,   865,   863,   864,   980,   866,   868,   867,   869,
     870,   871,   872,   873,   874,   875,   876,   877,   971,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     889,   890,   891,   892,   893,   973,   894,   895,   896,   919,
     974,   942,   943,   944,   976,   945,   979,   981,   982,   983,
     985,   946,   977,   947,   987,   990,   991,   948,   949,   950,
     951,   992,   952,   953,   954,   955,   956,   962,   963,   964,
     965,   966,   967,   968,  1009,  1010,  1012,   975,   969,   972,
     984,   978,   986,  1013,   988,   989,  1014,   995,  1011,   996,
     997,  1007,  1016,  1018,  1008,  1019,  1020,  1044,  1015,  1017,
    1046,  1045,  1048,  1092,  1133,  1249,  1261,   310,  1152,  1021,
    1252,  1291,  1286,   764,   634,  1285,  1022,  1272,  1023,  1024,
    1025,  1026,  1250,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1040,  1041,   746,  1042,  1043,  1047,  1270,  1050,
     734,  1049,  1051,   797,  1057,  1058,  1059,  1060,  1287,  1061,
    1062,  1063,  1144,  1064,  1288,  1266,   770,   802,  1271,  1065,
    1066,  1067,   739,   396,  1267,  1068,  1069,  1070,  1071,  1072,
    1073,  1074,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,   458,  1091,  1237,  1106,  1107,  1112,  1113,  1114,
    1269,  1238,  1115,  1127,  1268,  1128,  1129,  1130,  1131,  1132,
     330,     0,  1136,     0,   594,     0,     0,     0,     0,  1142,
     723,  1143,     0,     0,  1147,   649,     0,  1145,  1148,  1150,
    1153,  1154,  1175,  1176,  1177,  1200,  1201,  1202,  1203,  1206,
    1219,  1220,  1251,     0,     0,  1256,  1253,  1273,  1283,  1284,
     517,     0,     0,     0,     0,   523,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,     0,     0,     0,   560,     0,     0,     0,
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
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-772))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     450,   316,   317,     1,     1,     1,     1,   241,   323,     1,
     241,     3,     1,     1,     6,     1,   241,     1,     1,     1,
      10,     1,    12,     1,    22,    23,   241,     1,    26,     1,
      11,     1,    24,     1,   241,    31,   241,     1,    21,   241,
       4,   110,     1,     1,    11,    41,    24,   241,     1,   239,
     240,    43,   239,    35,     1,    47,   243,   174,   175,     1,
     813,   814,   815,   816,   817,    43,    48,   241,    61,    47,
     241,     1,     1,   241,    66,    39,    68,    47,    42,    61,
      62,    63,    64,   174,   175,    71,   241,    71,    80,    87,
      88,    89,   407,   408,    92,   241,    66,     1,   241,    81,
     241,    71,   100,    71,   100,   100,   421,   241,   100,     1,
     241,   426,   100,   241,   112,   113,     8,     9,    71,    83,
     100,   104,   437,   438,   239,   440,   100,    19,   100,   241,
     128,   129,   241,   448,   449,    27,   100,   452,   130,    98,
     209,    33,   100,   241,   133,    37,    38,   125,    40,   133,
     133,    98,   242,     1,    46,   242,   134,   135,   156,   133,
     130,   242,   239,    55,    56,   157,   243,   126,    60,   164,
     100,   242,     1,    65,   242,   164,   164,    69,    70,   126,
     133,    73,   632,    31,    76,    77,   957,   958,   959,   167,
     164,   133,    84,     1,   242,   176,   100,   242,    90,    91,
      51,    93,    94,    95,    96,    97,   164,     1,   201,   176,
     239,   242,   205,   239,   243,   205,   108,   243,   242,    67,
     217,    72,   164,    74,   116,   117,   118,   242,   120,   219,
      24,   123,   124,   230,   164,   127,   225,   225,   194,   195,
     232,   238,   240,   558,   240,   240,   138,   225,   240,    43,
     131,   240,   100,    47,   102,   103,   240,   240,   240,     1,
     164,   225,   240,   242,   115,   242,   240,   225,   240,   161,
     240,   100,   240,   165,   239,     1,   240,   169,   170,   171,
     172,   173,   240,   225,     1,   177,   178,    13,   217,    31,
     147,   148,   100,   240,   186,   143,   242,   145,   146,    41,
       1,   230,    28,    29,    21,   242,   100,   622,    34,   238,
      36,   240,   160,   239,   242,   630,   631,   243,     1,   242,
     242,   242,   242,    24,   216,   133,   218,     1,   220,   242,
     242,   125,   242,   237,   226,   164,   240,   188,   189,   231,
     242,   239,    43,   239,   236,   243,    47,   243,   240,   197,
     144,   239,    78,    79,   238,   243,   164,    31,   100,    85,
      86,   239,   239,   239,    47,   243,   243,   243,     1,    14,
      15,    16,   242,   239,   225,     8,     9,   243,   239,   242,
     106,   107,   243,    66,   232,   233,    19,   104,    71,   242,
     242,   131,   240,    67,    27,   121,   122,   239,   242,   239,
      33,   243,   717,   243,    37,    38,   132,    40,   237,   242,
     242,   242,   206,    46,   242,   141,   133,   242,   242,   242,
     242,   242,    55,    56,   125,   242,   100,    60,   102,   103,
     242,   225,    65,   134,   135,   110,    69,    70,   242,   242,
      73,   242,   242,    76,    77,   242,   240,   130,   239,   242,
       1,    84,     3,   242,   242,     6,   242,    90,    91,   242,
      93,    94,    95,    96,    97,   110,   167,   242,   242,   143,
     242,   145,   146,    24,   242,   108,   151,   152,   153,   154,
     155,   242,   242,   116,   117,   118,   160,   120,   242,   242,
     123,   124,    43,   242,   127,     5,    47,   242,   242,    74,
     239,   227,   228,   229,   242,   138,   242,   242,     1,   242,
     242,   242,   242,   242,   240,    66,    74,    68,   242,   242,
     242,   242,    32,   197,   225,   131,   242,   242,   161,    80,
     242,    24,   165,   242,     1,   242,   169,   170,   171,   172,
     173,    51,   242,   242,   177,   178,    13,    57,   242,   100,
      43,   242,   242,   186,    47,   242,   242,   242,   232,   233,
     242,    28,    29,     1,    74,   242,     4,    34,   110,    36,
     242,   242,   242,   242,   149,   242,   242,   242,   239,   130,
     174,   110,   174,   216,   174,   218,   110,   220,    98,   110,
     110,   149,   174,   226,   174,   105,   110,   174,   231,   239,
     174,    39,   174,   236,    42,   180,   157,   100,   174,   119,
     174,    78,    79,    61,   189,   239,   242,   242,    85,    86,
     242,   196,   180,   242,   242,   242,   242,   137,   242,   139,
     140,   189,   125,   208,   242,   210,   211,   242,   196,   106,
     107,   242,   242,     0,     1,    83,   242,   242,     5,   224,
     208,   144,   210,   211,   121,   122,   239,   242,   242,   234,
     131,   242,   100,   242,    21,   132,   224,    24,    25,   242,
     239,   242,   242,    30,   141,   242,   234,   242,   174,   189,
     242,   232,   242,   242,     1,   242,   242,   110,    45,   199,
     174,   174,    49,    50,    61,    52,   110,   131,   208,   174,
    1150,    58,   212,   110,   214,    22,    23,   110,   110,    26,
     174,   174,   174,   206,   224,    72,   131,   174,   110,   110,
     110,   110,   131,   110,   234,    82,    83,   110,   174,    61,
     174,   242,   225,   181,   182,   183,   184,   185,   174,   187,
     188,   242,    99,   191,   192,   193,   174,     1,   196,    20,
     198,   199,   200,   174,   202,   203,   204,   174,   115,   207,
     227,   228,   229,   174,   174,   213,   174,   110,   131,   174,
      87,    88,    89,    44,   174,    92,   174,   174,   239,   239,
     239,    35,    53,   100,   242,   239,   242,   225,    59,   242,
     242,   242,   149,   242,    48,   112,   113,   242,   174,   242,
     242,   158,   159,   242,    75,   162,   163,    61,    62,    63,
      64,   128,   129,   242,   181,   182,   183,   184,   185,   174,
     187,   188,   242,   242,   191,   192,   193,    81,   241,   196,
     101,   198,   199,   200,   131,   202,   203,   204,   109,   156,
     207,   242,   131,   242,   174,   239,   213,   242,   174,   181,
     182,   183,   184,   185,   239,   187,   188,   239,   215,   191,
     192,   193,   242,   242,   196,   242,   198,   199,   200,   242,
     202,   203,   204,   242,   242,   207,   242,   242,   242,   150,
     174,   213,   131,   174,   174,   239,   131,   174,   131,   131,
     131,   131,   131,   242,   131,   110,   131,   168,   131,   239,
     239,   242,   239,   131,   242,   239,   242,   110,   239,   110,
     239,   239,   239,   110,   239,   239,   239,   239,   239,   239,
     239,   239,   110,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   110,   110,   110,   131,   110,   239,   131,   131,
     174,   242,   131,   110,   131,   131,   131,   131,   131,   131,
     131,   239,   131,   239,   239,   110,   131,   239,   242,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   174,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   131,   239,   239,   239,   239,
     131,   239,   239,   239,   131,   239,   131,   131,   131,   131,
     131,   239,   174,   239,   131,   131,   131,   239,   239,   239,
     239,   110,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   131,   174,   131,   239,   242,   242,
     239,   242,   242,   131,   239,   242,   131,   239,   242,   239,
     239,   239,   131,   131,   239,   131,   131,   131,   242,   239,
     131,   242,   131,   136,   136,   110,  1205,    74,  1002,   239,
     131,  1290,  1260,   533,   345,  1258,   239,  1248,   239,   239,
     239,   239,  1145,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   508,   239,   239,   239,  1244,   239,
     483,   242,   239,   580,   239,   239,   239,   239,  1263,   239,
     239,   239,   179,   239,  1265,  1234,   547,   588,  1246,   239,
     239,   239,   498,   123,  1236,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   179,   239,  1096,   239,   239,   239,   239,   239,
    1242,  1098,   239,   239,  1240,   239,   239,   239,   239,   239,
      98,    -1,   239,    -1,   302,    -1,    -1,    -1,    -1,   239,
     466,   239,    -1,    -1,   239,   373,    -1,   243,   242,   242,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,    -1,    -1,   239,   242,   239,   239,   239,
     239,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   284,    -1,    -1,    -1,   262,    -1,    -1,    -1,
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
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   402
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   245,     0,     1,     5,    21,    24,    25,    30,    45,
      49,    50,    52,    58,    72,    82,    83,    99,   115,   149,
     158,   159,   162,   163,   215,   246,   251,   256,   274,   280,
     295,   313,   330,   344,   359,   366,   370,   380,   389,   408,
     418,   424,   428,   438,   498,   514,   535,   239,   240,   241,
     241,   314,   390,   419,   241,   429,   241,   499,   345,   409,
     331,   241,   241,   296,   360,   241,   241,   371,   381,   241,
       1,    31,    41,   100,   275,   276,   277,   278,   279,     1,
      13,    28,    29,    34,    36,    78,    79,    85,    86,   106,
     107,   121,   122,   132,   141,   227,   228,   229,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   241,   241,
     241,     1,    71,   425,   426,   427,   241,     1,     8,     9,
      19,    27,    33,    37,    38,    40,    46,    55,    56,    60,
      65,    69,    70,    73,    76,    77,    84,    90,    91,    93,
      94,    95,    96,    97,   108,   116,   117,   118,   120,   123,
     124,   127,   138,   161,   165,   169,   170,   171,   172,   173,
     177,   178,   186,   216,   218,   220,   226,   231,   236,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   490,   494,   495,
     496,   497,   241,   241,   241,   241,     1,   217,   230,   281,
     282,   283,   284,   285,   286,     1,    98,   126,   252,   253,
     254,   255,   241,   241,     1,    35,    48,    61,    62,    63,
      64,    81,   536,   537,   538,   539,   540,   541,   542,   543,
     544,     1,    31,    67,   100,   102,   103,   143,   145,   146,
     160,   197,   232,   233,   257,   258,   259,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   241,   241,
       1,   100,   367,   368,   369,   239,   242,   242,   242,   240,
     276,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   240,
     516,     1,    22,    23,    26,    87,    88,    89,    92,   100,
     112,   113,   128,   129,   156,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
       1,     3,     6,    24,    43,    47,    66,    68,    80,   100,
     130,   157,   232,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   404,   405,   406,   407,     1,    71,   133,
     420,   421,   422,   423,   242,   240,   426,     1,   100,   133,
     164,   430,   434,   435,   436,   437,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   491,   242,   487,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   240,   440,     1,
       4,    39,    42,    83,   100,   225,   500,   501,   502,   503,
     504,   508,   509,   510,     1,    24,    43,    47,   125,   134,
     135,   167,   225,   346,   347,   348,   349,   350,   351,   352,
     356,   357,   358,     1,   133,   164,   225,   410,   414,   415,
     416,   417,     1,    47,    66,    71,   130,   332,   336,   337,
     338,   342,   343,   239,   242,   242,   240,   282,   238,   239,
     242,   242,   240,   253,     1,    24,    43,    47,   100,   125,
     144,   206,   225,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   309,     1,    21,   104,   133,   361,   362,   363,
     364,   365,   242,   242,   242,   242,   242,   242,   242,   240,
     537,   239,   242,   242,   242,   242,   242,   242,   242,   260,
     242,   242,   242,   242,   240,   258,     1,   100,   164,   225,
     372,   373,   374,   375,   376,     1,   100,   164,   382,   383,
     384,   385,   242,   240,   368,   131,   131,   131,   239,   174,
     110,   110,   174,   174,   110,   248,   248,   110,   110,   174,
     174,   110,   248,   174,   174,   174,   174,   174,   239,   239,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   240,   316,   239,   242,   242,   242,   242,
     401,   242,   242,   242,   242,   242,   242,   242,   240,   392,
     242,   242,   240,   421,   131,   239,   242,   242,   431,   240,
     435,   174,   248,   248,   110,   174,   174,   110,   131,   174,
     110,   110,   110,   174,   174,   174,   248,   131,   174,   110,
     110,   248,   110,   110,   131,   110,   110,   174,   174,   242,
     174,   242,   248,   248,   174,   248,   174,   174,   174,   174,
     175,   174,   175,   174,   174,   248,   248,   110,   250,   131,
     248,   174,   174,   174,   174,   239,   511,   242,   242,   505,
     242,   242,   240,   501,   239,   242,   242,   353,   242,   242,
     242,   242,   242,   240,   347,   242,   411,   242,   240,   415,
     239,   333,   242,   242,   242,   240,   337,   174,   174,   239,
     241,   131,   131,   239,   239,   242,   242,   310,   242,   242,
     242,   306,   242,   240,   298,   239,   242,   242,   242,   240,
     362,   174,   174,   174,   131,   174,   174,   248,   239,   131,
     174,   131,   131,   131,   131,   131,   242,   131,   110,   131,
     131,   239,   239,   242,   377,   242,   240,   373,   239,   242,
     386,   240,   383,   131,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   151,   152,   153,   154,   155,   247,   248,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   110,   110,   248,   110,   110,   110,   110,
     131,   110,   110,   248,   248,   250,   239,   131,   194,   195,
     131,   174,   242,   131,   131,   131,   131,   110,   131,   131,
     239,   131,   131,   239,   239,   131,   131,   242,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,    61,   181,   182,
     183,   184,   185,   187,   188,   191,   192,   193,   196,   198,
     199,   200,   202,   203,   204,   207,   213,   492,   493,   239,
      61,   181,   182,   183,   184,   185,   187,   188,   191,   192,
     193,   196,   198,   199,   200,   202,   203,   204,   207,   213,
     488,   489,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,    14,    15,    16,
     249,   250,   239,   239,   239,   239,   239,   239,   239,   242,
     248,   174,   242,   131,   131,   239,   131,   174,   242,   131,
     110,   131,   131,   131,   239,   131,   242,   131,   239,   242,
     131,   131,   110,   340,   341,   239,   239,   239,     1,   100,
     164,   237,   287,   288,   289,   290,   291,   239,   239,   131,
     174,   242,   131,   131,   131,   242,   131,   239,   131,   131,
     131,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   147,   148,   261,   262,
     239,   239,   239,   239,   131,   242,   131,   239,   131,   242,
     239,   239,   247,   247,   247,   247,   247,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,    10,    12,   205,   219,   402,
     403,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   136,   432,   433,   239,   243,   239,   243,   249,
     249,   249,    11,   176,   512,   513,   239,   239,    11,   176,
     506,   507,   239,   239,   239,   239,    20,    44,    53,    59,
      75,   101,   109,   150,   168,   354,   355,   239,   239,   239,
     239,   239,   239,   136,   412,   413,   239,    61,   201,   205,
     334,   335,   239,   239,   179,   243,   339,   239,   242,   292,
     242,   240,   288,   239,   239,     5,    32,    51,    57,    74,
      98,   105,   119,   137,   139,   140,   189,   199,   208,   212,
     214,   224,   234,   311,   312,   239,   239,   239,    61,   181,
     182,   183,   184,   185,   187,   188,   191,   192,   193,   196,
     198,   199,   200,   202,   203,   204,   207,   213,   307,   308,
     239,   239,   239,   239,   239,   243,   239,    74,   149,   180,
     189,   196,   208,   210,   211,   224,   234,   378,   379,   239,
     239,    74,   149,   180,   189,   196,   208,   210,   211,   224,
     234,   387,   388,   239,   243,   239,   243,   493,   489,   239,
     243,   239,   243,   239,   243,   239,   243,   239,   243,   110,
     341,   239,   131,   242,   209,   250,   239,   239,   243,   239,
     243,   262,   239,   243,   239,   243,   403,   433,   513,   507,
     355,   413,   335,   239,    51,    72,    74,   115,   188,   189,
     225,   293,   294,   239,   239,   312,   308,   379,   388,   239,
     243,   294
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
#line 404 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 406 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 410 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 414 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 418 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 422 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 426 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 431 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 432 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 433 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 434 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 435 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 449 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 475 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 481 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
  {
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_SSLV3))
    {
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
      SSL_CTX_set_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
    }

    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_TLSV1))
    {
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
      SSL_CTX_set_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
    }
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

  case 72:

/* Line 1806 of yacc.c  */
#line 555 "ircd_parser.y"
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
#line 615 "ircd_parser.y"
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
#line 630 "ircd_parser.y"
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
#line 645 "ircd_parser.y"
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
#line 654 "ircd_parser.y"
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
#line 668 "ircd_parser.y"
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
#line 677 "ircd_parser.y"
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
#line 705 "ircd_parser.y"
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
#line 735 "ircd_parser.y"
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
#line 758 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 773 "ircd_parser.y"
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
#line 782 "ircd_parser.y"
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
#line 791 "ircd_parser.y"
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
#line 809 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 815 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.timestamp = yylval.number;
}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 821 "ircd_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 826 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 838 "ircd_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 843 "ircd_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 846 "ircd_parser.y"
    {
  lsize = 0;
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 858 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 862 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 866 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 870 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 874 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 878 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 882 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 892 "ircd_parser.y"
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
#line 905 "ircd_parser.y"
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

  case 137:

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
#line 1044 "ircd_parser.y"
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
#line 1056 "ircd_parser.y"
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
#line 1067 "ircd_parser.y"
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
#line 1109 "ircd_parser.y"
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
#line 1118 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1125 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1129 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1133 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1137 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1141 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1145 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1149 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1153 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1157 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1161 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1165 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1169 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1173 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1177 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1181 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1189 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1193 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1197 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1201 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1207 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1222 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1226 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1234 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1238 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1246 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1250 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1254 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1258 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1262 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1266 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1270 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1274 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1278 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1282 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1292 "ircd_parser.y"
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
#line 1299 "ircd_parser.y"
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
#line 1357 "ircd_parser.y"
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
#line 1366 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 208:

/* Line 1806 of yacc.c  */
#line 1372 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 209:

/* Line 1806 of yacc.c  */
#line 1378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 210:

/* Line 1806 of yacc.c  */
#line 1384 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 211:

/* Line 1806 of yacc.c  */
#line 1390 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 212:

/* Line 1806 of yacc.c  */
#line 1396 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 213:

/* Line 1806 of yacc.c  */
#line 1402 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1408 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1414 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1420 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1426 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1432 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1441 "ircd_parser.y"
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
#line 1448 "ircd_parser.y"
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
#line 1457 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1463 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1467 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1481 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 239:

/* Line 1806 of yacc.c  */
#line 1486 "ircd_parser.y"
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
#line 1500 "ircd_parser.y"
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
#line 1529 "ircd_parser.y"
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
#line 1541 "ircd_parser.y"
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
#line 1553 "ircd_parser.y"
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
#line 1615 "ircd_parser.y"
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
#line 1652 "ircd_parser.y"
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
#line 1665 "ircd_parser.y"
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
#line 1674 "ircd_parser.y"
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
#line 1685 "ircd_parser.y"
    {
}
    break;

  case 264:

/* Line 1806 of yacc.c  */
#line 1690 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 265:

/* Line 1806 of yacc.c  */
#line 1694 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1698 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 267:

/* Line 1806 of yacc.c  */
#line 1702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1706 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 269:

/* Line 1806 of yacc.c  */
#line 1710 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 270:

/* Line 1806 of yacc.c  */
#line 1714 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1718 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1722 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1729 "ircd_parser.y"
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
#line 1748 "ircd_parser.y"
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
#line 1758 "ircd_parser.y"
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
#line 1771 "ircd_parser.y"
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
#line 1778 "ircd_parser.y"
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
#line 1790 "ircd_parser.y"
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
#line 1799 "ircd_parser.y"
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
#line 1814 "ircd_parser.y"
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
#line 1832 "ircd_parser.y"
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
#line 1847 "ircd_parser.y"
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
#line 1855 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1866 "ircd_parser.y"
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
#line 1875 "ircd_parser.y"
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
#line 1897 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 307:

/* Line 1806 of yacc.c  */
#line 1904 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1908 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1912 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1920 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 312:

/* Line 1806 of yacc.c  */
#line 1924 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 313:

/* Line 1806 of yacc.c  */
#line 1928 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1932 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1936 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1940 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1949 "ircd_parser.y"
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
#line 1956 "ircd_parser.y"
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
#line 1969 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1975 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 329:

/* Line 1806 of yacc.c  */
#line 1982 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 330:

/* Line 1806 of yacc.c  */
#line 1986 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 331:

/* Line 1806 of yacc.c  */
#line 1990 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1994 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 333:

/* Line 1806 of yacc.c  */
#line 1998 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2002 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2006 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 2010 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 2014 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2027 "ircd_parser.y"
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
#line 2042 "ircd_parser.y"
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

  case 356:

/* Line 1806 of yacc.c  */
#line 2164 "ircd_parser.y"
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

  case 357:

/* Line 1806 of yacc.c  */
#line 2176 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 358:

/* Line 1806 of yacc.c  */
#line 2185 "ircd_parser.y"
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

  case 359:

/* Line 1806 of yacc.c  */
#line 2211 "ircd_parser.y"
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

  case 360:

/* Line 1806 of yacc.c  */
#line 2229 "ircd_parser.y"
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

  case 361:

/* Line 1806 of yacc.c  */
#line 2247 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 362:

/* Line 1806 of yacc.c  */
#line 2253 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 363:

/* Line 1806 of yacc.c  */
#line 2257 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 364:

/* Line 1806 of yacc.c  */
#line 2265 "ircd_parser.y"
    {
}
    break;

  case 368:

/* Line 1806 of yacc.c  */
#line 2270 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 369:

/* Line 1806 of yacc.c  */
#line 2274 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2278 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 2282 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2288 "ircd_parser.y"
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

  case 373:

/* Line 1806 of yacc.c  */
#line 2299 "ircd_parser.y"
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

  case 374:

/* Line 1806 of yacc.c  */
#line 2312 "ircd_parser.y"
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

  case 375:

/* Line 1806 of yacc.c  */
#line 2325 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2337 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2344 "ircd_parser.y"
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

  case 378:

/* Line 1806 of yacc.c  */
#line 2400 "ircd_parser.y"
    {
}
    break;

  case 382:

/* Line 1806 of yacc.c  */
#line 2405 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 2414 "ircd_parser.y"
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

  case 390:

/* Line 1806 of yacc.c  */
#line 2433 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2442 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2446 "ircd_parser.y"
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

  case 398:

/* Line 1806 of yacc.c  */
#line 2468 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 2474 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2488 "ircd_parser.y"
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

  case 406:

/* Line 1806 of yacc.c  */
#line 2506 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 407:

/* Line 1806 of yacc.c  */
#line 2513 "ircd_parser.y"
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

  case 408:

/* Line 1806 of yacc.c  */
#line 2553 "ircd_parser.y"
    {
}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 2558 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 419:

/* Line 1806 of yacc.c  */
#line 2567 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 420:

/* Line 1806 of yacc.c  */
#line 2573 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 476:

/* Line 1806 of yacc.c  */
#line 2617 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 477:

/* Line 1806 of yacc.c  */
#line 2622 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 478:

/* Line 1806 of yacc.c  */
#line 2627 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 479:

/* Line 1806 of yacc.c  */
#line 2632 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 480:

/* Line 1806 of yacc.c  */
#line 2637 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 481:

/* Line 1806 of yacc.c  */
#line 2642 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 482:

/* Line 1806 of yacc.c  */
#line 2647 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 483:

/* Line 1806 of yacc.c  */
#line 2652 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 484:

/* Line 1806 of yacc.c  */
#line 2657 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2662 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2667 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2672 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2677 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2682 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2687 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2692 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2697 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2708 "ircd_parser.y"
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

  case 495:

/* Line 1806 of yacc.c  */
#line 2719 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2724 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2733 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2738 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2743 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2748 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2753 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2758 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2761 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2766 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2769 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2774 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2779 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2784 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2789 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2794 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2799 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2804 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2809 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2814 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2825 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2830 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2835 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2849 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2858 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2863 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2868 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2873 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2879 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2882 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2885 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2888 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2891 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2894 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 2897 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 2900 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 2903 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2906 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2909 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2912 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2915 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2918 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2921 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2924 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2927 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2930 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2933 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2941 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2947 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2950 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2953 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2956 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2959 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2962 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 2965 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 2968 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 2971 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 2974 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2977 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2980 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2983 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2986 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2989 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 2992 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 2995 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 2998 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3001 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3004 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3009 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3014 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3019 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3024 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3033 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
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

  case 586:

/* Line 1806 of yacc.c  */
#line 3066 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3072 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3084 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3088 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3094 "ircd_parser.y"
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

  case 595:

/* Line 1806 of yacc.c  */
#line 3128 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3137 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3141 "ircd_parser.y"
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

  case 600:

/* Line 1806 of yacc.c  */
#line 3188 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3192 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 3226 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 627:

/* Line 1806 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 628:

/* Line 1806 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 3241 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 3246 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 631:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 3256 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 3261 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3266 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3271 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3276 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3286 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3291 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3296 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3301 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3320 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3326 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3332 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3341 "ircd_parser.y"
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

  case 657:

/* Line 1806 of yacc.c  */
#line 3355 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3361 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3367 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7646 "ircd_parser.c"
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



