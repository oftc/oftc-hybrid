/* A Bison parser, made by GNU Bison 2.6.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 336 of yacc.c  */
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


/* Line 336 of yacc.c  */
#line 153 "conf_parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_Y_TAB_H
# define YY_Y_TAB_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
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
     BYTES = 268,
     KBYTES = 269,
     MBYTES = 270,
     GBYTES = 271,
     TBYTES = 272,
     CALLER_ID_WAIT = 273,
     CAN_FLOOD = 274,
     CHANNEL = 275,
     CIDR_BITLEN_IPV4 = 276,
     CIDR_BITLEN_IPV6 = 277,
     CLASS = 278,
     CONNECT = 279,
     CONNECTFREQ = 280,
     DEFAULT_FLOODCOUNT = 281,
     DEFAULT_SPLIT_SERVER_COUNT = 282,
     DEFAULT_SPLIT_USER_COUNT = 283,
     DENY = 284,
     DESCRIPTION = 285,
     DIE = 286,
     DISABLE_AUTH = 287,
     DISABLE_FAKE_CHANNELS = 288,
     DISABLE_REMOTE_COMMANDS = 289,
     DOTS_IN_IDENT = 290,
     DURATION = 291,
     EGDPOOL_PATH = 292,
     EMAIL = 293,
     ENABLE = 294,
     ENCRYPTED = 295,
     EXCEED_LIMIT = 296,
     EXEMPT = 297,
     FAILED_OPER_NOTICE = 298,
     IRCD_FLAGS = 299,
     FLATTEN_LINKS = 300,
     GECOS = 301,
     GENERAL = 302,
     GLINE = 303,
     GLINE_DURATION = 304,
     GLINE_ENABLE = 305,
     GLINE_EXEMPT = 306,
     GLINE_TIME = 307,
     GLINE_REQUEST_DURATION = 308,
     GLINE_MIN_CIDR = 309,
     GLINE_MIN_CIDR6 = 310,
     GLOBAL_KILL = 311,
     IRCD_AUTH = 312,
     NEED_IDENT = 313,
     HAVENT_READ_CONF = 314,
     HIDDEN = 315,
     HIDDEN_NAME = 316,
     HIDE_SERVER_IPS = 317,
     HIDE_SERVERS = 318,
     HIDE_SPOOF_IPS = 319,
     HOST = 320,
     HUB = 321,
     HUB_MASK = 322,
     IGNORE_BOGUS_TS = 323,
     INVISIBLE_ON_CONNECT = 324,
     IP = 325,
     KILL = 326,
     KILL_CHASE_TIME_LIMIT = 327,
     KLINE = 328,
     KLINE_EXEMPT = 329,
     KLINE_REASON = 330,
     KLINE_WITH_REASON = 331,
     KNOCK_DELAY = 332,
     KNOCK_DELAY_CHANNEL = 333,
     LEAF_MASK = 334,
     LINKS_DELAY = 335,
     LISTEN = 336,
     T_LOG = 337,
     MAX_ACCEPT = 338,
     MAX_BANS = 339,
     MAX_CHANS_PER_OPER = 340,
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
     T_SET = 461,
     T_SKILL = 462,
     T_SPY = 463,
     T_SSL = 464,
     T_UMODES = 465,
     T_UNAUTH = 466,
     T_UNDLINE = 467,
     T_UNLIMITED = 468,
     T_UNRESV = 469,
     T_UNXLINE = 470,
     T_GLOBOPS = 471,
     T_WALLOP = 472,
     T_RESTART = 473,
     T_SERVICE = 474,
     T_SERVICES_NAME = 475,
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
#define BYTES 268
#define KBYTES 269
#define MBYTES 270
#define GBYTES 271
#define TBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CLASS 278
#define CONNECT 279
#define CONNECTFREQ 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DOTS_IN_IDENT 290
#define DURATION 291
#define EGDPOOL_PATH 292
#define EMAIL 293
#define ENABLE 294
#define ENCRYPTED 295
#define EXCEED_LIMIT 296
#define EXEMPT 297
#define FAILED_OPER_NOTICE 298
#define IRCD_FLAGS 299
#define FLATTEN_LINKS 300
#define GECOS 301
#define GENERAL 302
#define GLINE 303
#define GLINE_DURATION 304
#define GLINE_ENABLE 305
#define GLINE_EXEMPT 306
#define GLINE_TIME 307
#define GLINE_REQUEST_DURATION 308
#define GLINE_MIN_CIDR 309
#define GLINE_MIN_CIDR6 310
#define GLOBAL_KILL 311
#define IRCD_AUTH 312
#define NEED_IDENT 313
#define HAVENT_READ_CONF 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_SERVER_IPS 317
#define HIDE_SERVERS 318
#define HIDE_SPOOF_IPS 319
#define HOST 320
#define HUB 321
#define HUB_MASK 322
#define IGNORE_BOGUS_TS 323
#define INVISIBLE_ON_CONNECT 324
#define IP 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_REASON 330
#define KLINE_WITH_REASON 331
#define KNOCK_DELAY 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LINKS_DELAY 335
#define LISTEN 336
#define T_LOG 337
#define MAX_ACCEPT 338
#define MAX_BANS 339
#define MAX_CHANS_PER_OPER 340
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
#define T_SET 461
#define T_SKILL 462
#define T_SPY 463
#define T_SSL 464
#define T_UMODES 465
#define T_UNAUTH 466
#define T_UNDLINE 467
#define T_UNLIMITED 468
#define T_UNRESV 469
#define T_UNXLINE 470
#define T_GLOBOPS 471
#define T_WALLOP 472
#define T_RESTART 473
#define T_SERVICE 474
#define T_SERVICES_NAME 475
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
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 684 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_Y_TAB_H  */

/* Copy the second part of user declarations.  */

/* Line 353 of yacc.c  */
#line 712 "conf_parser.c"

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
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
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
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  247
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  290
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1265

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
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   169,   174,   179,
     183,   185,   187,   189,   193,   195,   197,   199,   204,   209,
     214,   219,   224,   229,   234,   239,   244,   249,   254,   259,
     264,   270,   273,   275,   277,   279,   281,   284,   289,   294,
     299,   305,   308,   310,   312,   314,   317,   322,   323,   330,
     333,   335,   337,   339,   341,   344,   349,   354,   359,   360,
     366,   370,   372,   374,   376,   378,   380,   382,   384,   386,
     387,   394,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   418,   423,   428,   433,   438,   443,   448,   449,
     455,   459,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   502,   508,   512,   514,   516,   518,   520,
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
    1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1399,  1404,
    1409,  1414,  1419,  1424,  1429,  1434,  1439,  1444,  1449,  1454,
    1459,  1464,  1469,  1474,  1479,  1484,  1489,  1494,  1499,  1504,
    1509,  1514,  1519,  1524,  1529,  1534,  1539,  1544,  1549,  1554,
    1559,  1564,  1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,
    1609,  1614,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1650,
    1656,  1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,
    1698,  1700,  1702,  1703,  1709,  1713,  1715,  1717,  1719,  1721,
    1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,
    1743,  1745,  1747,  1749,  1751,  1753,  1755,  1760,  1765,  1770,
    1775,  1781,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,
    1820,  1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,
    1867,  1872,  1877,  1882,  1887,  1892,  1897,  1902,  1907,  1913,
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1937,
    1942,  1947,  1952,  1957
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     248,     0,    -1,    -1,   248,   249,    -1,   281,    -1,   287,
      -1,   301,    -1,   508,    -1,   319,    -1,   336,    -1,   350,
      -1,   259,    -1,   528,    -1,   365,    -1,   372,    -1,   376,
      -1,   386,    -1,   395,    -1,   415,    -1,   425,    -1,   431,
      -1,   445,    -1,   435,    -1,   254,    -1,     1,   242,    -1,
       1,   243,    -1,    -1,   251,    -1,   110,   250,    -1,   110,
     153,   250,    -1,   110,   154,   250,    -1,   110,   155,   250,
      -1,   110,   156,   250,    -1,   110,   157,   250,    -1,    -1,
     253,    -1,   110,   252,    -1,   110,    13,   252,    -1,   110,
      14,   252,    -1,   110,    15,   252,    -1,    99,   244,   255,
     243,   242,    -1,   255,   256,    -1,   256,    -1,   257,    -1,
     258,    -1,     1,   242,    -1,    98,   245,   131,   242,    -1,
     126,   245,   131,   242,    -1,   161,   244,   260,   243,   242,
      -1,   260,   261,    -1,   261,    -1,   272,    -1,   277,    -1,
     280,    -1,   274,    -1,   275,    -1,   276,    -1,   279,    -1,
     270,    -1,   269,    -1,   278,    -1,   273,    -1,   268,    -1,
     262,    -1,   263,    -1,   271,    -1,     1,   242,    -1,   147,
     245,   264,   242,    -1,   148,   245,   266,   242,    -1,   264,
     246,   265,    -1,   265,    -1,   149,    -1,   150,    -1,   266,
     246,   267,    -1,   267,    -1,   149,    -1,   150,    -1,   145,
     245,   131,   242,    -1,   143,   245,   131,   242,    -1,   146,
     245,   131,   242,    -1,   188,   245,   131,   242,    -1,   100,
     245,   131,   242,    -1,   162,   245,   131,   242,    -1,    30,
     245,   131,   242,    -1,   103,   245,   131,   242,    -1,   102,
     245,   131,   242,    -1,   235,   245,   131,   242,    -1,   236,
     245,   131,   242,    -1,   200,   245,   110,   242,    -1,    66,
     245,   176,   242,    -1,     5,   244,   282,   243,   242,    -1,
     282,   283,    -1,   283,    -1,   284,    -1,   286,    -1,   285,
      -1,     1,   242,    -1,   100,   245,   131,   242,    -1,    38,
     245,   131,   242,    -1,    30,   245,   131,   242,    -1,    82,
     244,   288,   243,   242,    -1,   288,   289,    -1,   289,    -1,
     290,    -1,   291,    -1,     1,   242,    -1,   233,   245,   176,
     242,    -1,    -1,   292,   241,   244,   293,   243,   242,    -1,
     293,   294,    -1,   294,    -1,   295,    -1,   297,    -1,   296,
      -1,     1,   242,    -1,   100,   245,   131,   242,    -1,   240,
     245,   253,   242,    -1,   240,   245,   213,   242,    -1,    -1,
     166,   298,   245,   299,   242,    -1,   299,   246,   300,    -1,
     300,    -1,   228,    -1,   115,    -1,    48,    -1,   192,    -1,
      73,    -1,    71,    -1,   191,    -1,    -1,   115,   302,   244,
     303,   243,   242,    -1,   303,   304,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,   311,    -1,   310,    -1,   308,
      -1,   309,    -1,   315,    -1,     1,   242,    -1,   100,   245,
     131,   242,    -1,   228,   245,   131,   242,    -1,   125,   245,
     131,   242,    -1,    40,   245,   176,   242,    -1,   144,   245,
     131,   242,    -1,    23,   245,   131,   242,    -1,    -1,   210,
     312,   245,   313,   242,    -1,   313,   246,   314,    -1,   314,
      -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,   191,
      -1,   195,    -1,    60,    -1,   207,    -1,   201,    -1,   203,
      -1,   211,    -1,   208,    -1,   194,    -1,   202,    -1,   205,
      -1,   196,    -1,   217,    -1,   184,    -1,   185,    -1,   199,
      -1,    -1,    44,   316,   245,   317,   242,    -1,   317,   246,
     318,    -1,   318,    -1,    56,    -1,   139,    -1,    73,    -1,
     227,    -1,   192,    -1,   212,    -1,   237,    -1,    48,    -1,
      31,    -1,   218,    -1,   137,    -1,     5,    -1,   105,    -1,
     202,    -1,   216,    -1,   119,    -1,   140,    -1,   206,    -1,
      98,    -1,    -1,    23,   320,   244,   321,   243,   242,    -1,
     321,   322,    -1,   322,    -1,   323,    -1,   333,    -1,   334,
      -1,   324,    -1,   325,    -1,   335,    -1,   326,    -1,   327,
      -1,   328,    -1,   329,    -1,   330,    -1,   331,    -1,   332,
      -1,     1,   242,    -1,   100,   245,   131,   242,    -1,   128,
     245,   251,   242,    -1,   129,   245,   251,   242,    -1,   113,
     245,   110,   242,    -1,    25,   245,   251,   242,    -1,    92,
     245,   110,   242,    -1,    87,   245,   110,   242,    -1,    89,
     245,   110,   242,    -1,    88,   245,   110,   242,    -1,   158,
     245,   253,   242,    -1,    21,   245,   110,   242,    -1,    22,
     245,   110,   242,    -1,   112,   245,   110,   242,    -1,    -1,
      81,   337,   244,   342,   243,   242,    -1,    -1,    44,   339,
     245,   340,   242,    -1,   340,   246,   341,    -1,   341,    -1,
     209,    -1,    60,    -1,   204,    -1,   342,   343,    -1,   343,
      -1,   344,    -1,   338,    -1,   348,    -1,   349,    -1,     1,
     242,    -1,    -1,   130,   245,   346,   345,   242,    -1,   346,
     246,   347,    -1,   347,    -1,   110,    -1,   110,   181,   110,
      -1,    70,   245,   131,   242,    -1,    65,   245,   131,   242,
      -1,    -1,    57,   351,   244,   352,   243,   242,    -1,   352,
     353,    -1,   353,    -1,   354,    -1,   355,    -1,   356,    -1,
     358,    -1,   362,    -1,   363,    -1,   364,    -1,   357,    -1,
       1,   242,    -1,   228,   245,   131,   242,    -1,   125,   245,
     131,   242,    -1,    23,   245,   131,   242,    -1,    40,   245,
     176,   242,    -1,    -1,    44,   359,   245,   360,   242,    -1,
     360,   246,   361,    -1,   361,    -1,   170,    -1,    41,    -1,
      74,    -1,    58,    -1,    19,    -1,   109,    -1,    51,    -1,
     152,    -1,   101,    -1,   169,   245,   131,   242,    -1,   135,
     245,   131,   242,    -1,   134,   245,   110,   242,    -1,    -1,
     151,   366,   244,   367,   243,   242,    -1,   367,   368,    -1,
     368,    -1,   369,    -1,   370,    -1,   371,    -1,     1,   242,
      -1,   133,   245,   131,   242,    -1,    20,   245,   131,   242,
      -1,   104,   245,   131,   242,    -1,   219,   244,   373,   243,
     242,    -1,   373,   374,    -1,   374,    -1,   375,    -1,     1,
      -1,   100,   245,   131,   242,    -1,    -1,   164,   377,   244,
     378,   243,   242,    -1,   378,   379,    -1,   379,    -1,   380,
      -1,   381,    -1,   382,    -1,     1,   242,    -1,   100,   245,
     131,   242,    -1,   228,   245,   131,   242,    -1,    -1,   166,
     383,   245,   384,   242,    -1,   384,   246,   385,    -1,   385,
      -1,    73,    -1,   227,    -1,   192,    -1,   212,    -1,   237,
      -1,   215,    -1,   151,    -1,   214,    -1,   199,    -1,   182,
      -1,    -1,   165,   387,   244,   388,   243,   242,    -1,   388,
     389,    -1,   389,    -1,   390,    -1,   391,    -1,     1,   242,
      -1,   100,   245,   131,   242,    -1,    -1,   166,   392,   245,
     393,   242,    -1,   393,   246,   394,    -1,   394,    -1,    73,
      -1,   227,    -1,   192,    -1,   212,    -1,   237,    -1,   215,
      -1,   151,    -1,   214,    -1,   199,    -1,   182,    -1,    -1,
      24,   396,   244,   397,   243,   242,    -1,   397,   398,    -1,
     398,    -1,   399,    -1,   400,    -1,   401,    -1,   402,    -1,
     403,    -1,   405,    -1,   404,    -1,   414,    -1,   406,    -1,
     411,    -1,   412,    -1,   413,    -1,   410,    -1,     1,   242,
      -1,   100,   245,   131,   242,    -1,    65,   245,   131,   242,
      -1,   235,   245,   131,   242,    -1,   159,   245,   131,   242,
      -1,     3,   245,   131,   242,    -1,   130,   245,   110,   242,
      -1,     6,   245,   197,   242,    -1,     6,   245,   198,   242,
      -1,    -1,    44,   407,   245,   408,   242,    -1,   408,   246,
     409,    -1,   409,    -1,    10,    -1,    12,    -1,   222,    -1,
     209,    -1,    40,   245,   176,   242,    -1,    67,   245,   131,
     242,    -1,    79,   245,   131,   242,    -1,    23,   245,   131,
     242,    -1,   188,   245,   131,   242,    -1,    -1,    71,   416,
     244,   421,   243,   242,    -1,    -1,   166,   418,   245,   419,
     242,    -1,   419,   246,   420,    -1,   420,    -1,   136,    -1,
     421,   422,    -1,   422,    -1,   423,    -1,   424,    -1,   417,
      -1,     1,    -1,   228,   245,   131,   242,    -1,   133,   245,
     131,   242,    -1,    -1,    29,   426,   244,   427,   243,   242,
      -1,   427,   428,    -1,   428,    -1,   429,    -1,   430,    -1,
       1,    -1,    70,   245,   131,   242,    -1,   133,   245,   131,
     242,    -1,    42,   244,   432,   243,   242,    -1,   432,   433,
      -1,   433,    -1,   434,    -1,     1,    -1,    70,   245,   131,
     242,    -1,    -1,    46,   436,   244,   441,   243,   242,    -1,
      -1,   166,   438,   245,   439,   242,    -1,   439,   246,   440,
      -1,   440,    -1,   136,    -1,   441,   442,    -1,   442,    -1,
     443,    -1,   444,    -1,   437,    -1,     1,    -1,   100,   245,
     131,   242,    -1,   133,   245,   131,   242,    -1,    47,   244,
     446,   243,   242,    -1,   446,   447,    -1,   447,    -1,   458,
      -1,   459,    -1,   461,    -1,   462,    -1,   463,    -1,   464,
      -1,   465,    -1,   466,    -1,   467,    -1,   468,    -1,   457,
      -1,   470,    -1,   471,    -1,   472,    -1,   473,    -1,   488,
      -1,   475,    -1,   477,    -1,   479,    -1,   478,    -1,   482,
      -1,   476,    -1,   483,    -1,   484,    -1,   485,    -1,   486,
      -1,   487,    -1,   500,    -1,   489,    -1,   490,    -1,   491,
      -1,   496,    -1,   480,    -1,   481,    -1,   506,    -1,   504,
      -1,   505,    -1,   460,    -1,   507,    -1,   495,    -1,   469,
      -1,   493,    -1,   494,    -1,   456,    -1,   449,    -1,   450,
      -1,   451,    -1,   452,    -1,   453,    -1,   454,    -1,   455,
      -1,   474,    -1,   448,    -1,   492,    -1,     1,    -1,    94,
     245,   110,   242,    -1,    50,   245,   176,   242,    -1,    49,
     245,   251,   242,    -1,    53,   245,   251,   242,    -1,    54,
     245,   110,   242,    -1,    55,   245,   110,   242,    -1,   234,
     245,   176,   242,    -1,   138,   245,   251,   242,    -1,   163,
     245,   176,   242,    -1,    72,   245,   251,   242,    -1,    64,
     245,   176,   242,    -1,    68,   245,   176,   242,    -1,    34,
     245,   176,   242,    -1,    43,   245,   176,   242,    -1,     8,
     245,   176,   242,    -1,    91,   245,   251,   242,    -1,    90,
     245,   110,   242,    -1,    83,   245,   110,   242,    -1,     9,
     245,   251,   242,    -1,   180,   245,   251,   242,    -1,   179,
     245,   251,   242,    -1,    59,   245,   110,   242,    -1,    76,
     245,   176,   242,    -1,    75,   245,   131,   242,    -1,    69,
     245,   176,   242,    -1,   239,   245,   176,   242,    -1,   171,
     245,   176,   242,    -1,   174,   245,   176,   242,    -1,   175,
     245,   176,   242,    -1,   173,   245,   176,   242,    -1,   173,
     245,   177,   242,    -1,   172,   245,   176,   242,    -1,   172,
     245,   177,   242,    -1,   123,   245,   251,   242,    -1,    18,
     245,   251,   242,    -1,   116,   245,   176,   242,    -1,   124,
     245,   251,   242,    -1,   167,   245,   176,   242,    -1,   108,
     245,   176,   242,    -1,   223,   245,   176,   242,    -1,   118,
     245,   176,   242,    -1,    95,   245,   131,   242,    -1,    35,
     245,   110,   242,    -1,    93,   245,   110,   242,    -1,   229,
     245,   176,   242,    -1,    37,   245,   131,   242,    -1,   220,
     245,   131,   242,    -1,   127,   245,   176,   242,    -1,    32,
     245,   176,   242,    -1,   221,   245,   251,   242,    -1,    -1,
     120,   497,   245,   498,   242,    -1,   498,   246,   499,    -1,
     499,    -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,
     191,    -1,   195,    -1,    60,    -1,   207,    -1,   201,    -1,
     203,    -1,   211,    -1,   208,    -1,   194,    -1,   202,    -1,
     205,    -1,   196,    -1,   217,    -1,   184,    -1,   185,    -1,
     199,    -1,    -1,   117,   501,   245,   502,   242,    -1,   502,
     246,   503,    -1,   503,    -1,   183,    -1,   186,    -1,   187,
      -1,   190,    -1,   191,    -1,   195,    -1,   207,    -1,    60,
      -1,   201,    -1,   203,    -1,   211,    -1,   208,    -1,   194,
      -1,   202,    -1,   205,    -1,   196,    -1,   217,    -1,   184,
      -1,   185,    -1,   199,    -1,    96,   245,   110,   242,    -1,
      97,   245,   110,   242,    -1,    26,   245,   110,   242,    -1,
     189,   245,   253,   242,    -1,    20,   244,   509,   243,   242,
      -1,   509,   510,    -1,   510,    -1,   513,    -1,   514,    -1,
     515,    -1,   521,    -1,   516,    -1,   517,    -1,   518,    -1,
     519,    -1,   520,    -1,   522,    -1,   523,    -1,   524,    -1,
     512,    -1,   525,    -1,   526,    -1,   527,    -1,   511,    -1,
       1,    -1,    33,   245,   176,   242,    -1,   141,   245,   176,
     242,    -1,   230,   245,   176,   242,    -1,   231,   245,   176,
     242,    -1,   232,   245,   176,   242,    -1,    77,   245,   251,
     242,    -1,    78,   245,   251,   242,    -1,    86,   245,   110,
     242,    -1,    85,   245,   110,   242,    -1,   132,   245,   176,
     242,    -1,    84,   245,   110,   242,    -1,    28,   245,   110,
     242,    -1,    27,   245,   110,   242,    -1,   106,   245,   176,
     242,    -1,   107,   245,   176,   242,    -1,   121,   245,   110,
     242,    -1,   122,   245,   251,   242,    -1,   160,   244,   529,
     243,   242,    -1,   529,   530,    -1,   530,    -1,   531,    -1,
     532,    -1,   534,    -1,   535,    -1,   533,    -1,   536,    -1,
       1,    -1,    45,   245,   176,   242,    -1,    63,   245,   176,
     242,    -1,    61,   245,   131,   242,    -1,    80,   245,   251,
     242,    -1,    60,   245,   176,   242,    -1,    62,   245,   176,
     242,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   355,   355,   356,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   384,   384,   385,   389,
     393,   397,   401,   405,   411,   411,   412,   413,   414,   415,
     422,   425,   425,   426,   426,   426,   428,   434,   441,   443,
     443,   444,   444,   445,   445,   446,   446,   447,   447,   448,
     448,   449,   449,   450,   450,   451,   452,   455,   456,   458,
     458,   459,   465,   473,   473,   474,   480,   488,   527,   586,
     614,   622,   637,   652,   661,   675,   684,   712,   742,   765,
     774,   776,   776,   777,   777,   778,   778,   780,   789,   798,
     810,   811,   811,   813,   813,   814,   816,   823,   823,   833,
     834,   836,   836,   837,   837,   839,   844,   847,   853,   852,
     858,   858,   859,   863,   867,   871,   875,   879,   883,   894,
     893,   991,   991,   992,   992,   992,   993,   993,   993,   994,
     994,   994,   996,  1005,  1042,  1054,  1065,  1107,  1117,  1116,
    1122,  1122,  1123,  1127,  1131,  1135,  1139,  1143,  1147,  1151,
    1155,  1159,  1163,  1167,  1171,  1175,  1179,  1183,  1187,  1191,
    1195,  1199,  1206,  1205,  1211,  1211,  1212,  1216,  1220,  1224,
    1228,  1232,  1236,  1240,  1244,  1248,  1252,  1256,  1260,  1264,
    1268,  1272,  1276,  1280,  1284,  1295,  1294,  1344,  1344,  1345,
    1346,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,
    1355,  1356,  1357,  1359,  1368,  1374,  1380,  1386,  1392,  1398,
    1404,  1410,  1416,  1422,  1428,  1434,  1444,  1443,  1460,  1459,
    1464,  1464,  1465,  1469,  1473,  1481,  1481,  1482,  1482,  1482,
    1482,  1482,  1484,  1484,  1486,  1486,  1488,  1502,  1522,  1531,
    1544,  1543,  1612,  1612,  1613,  1613,  1613,  1613,  1614,  1614,
    1614,  1615,  1615,  1617,  1652,  1665,  1674,  1686,  1685,  1689,
    1689,  1690,  1694,  1698,  1702,  1706,  1710,  1714,  1718,  1722,
    1729,  1748,  1758,  1772,  1771,  1787,  1787,  1788,  1788,  1788,
    1788,  1790,  1799,  1814,  1827,  1829,  1829,  1830,  1830,  1832,
    1848,  1847,  1863,  1863,  1864,  1864,  1864,  1864,  1866,  1875,
    1898,  1897,  1903,  1903,  1904,  1908,  1912,  1916,  1920,  1924,
    1928,  1932,  1936,  1940,  1950,  1949,  1966,  1966,  1967,  1967,
    1967,  1969,  1976,  1975,  1981,  1981,  1982,  1986,  1990,  1994,
    1998,  2002,  2006,  2010,  2014,  2018,  2028,  2027,  2078,  2078,
    2079,  2079,  2079,  2080,  2080,  2081,  2081,  2081,  2082,  2082,
    2082,  2083,  2083,  2084,  2086,  2095,  2104,  2130,  2148,  2166,
    2172,  2176,  2185,  2184,  2188,  2188,  2189,  2193,  2197,  2201,
    2207,  2218,  2229,  2240,  2249,  2268,  2267,  2333,  2332,  2336,
    2336,  2337,  2343,  2343,  2344,  2344,  2344,  2344,  2346,  2365,
    2375,  2374,  2399,  2399,  2400,  2400,  2400,  2402,  2408,  2417,
    2419,  2419,  2420,  2420,  2422,  2441,  2440,  2488,  2487,  2491,
    2491,  2492,  2498,  2498,  2499,  2499,  2499,  2499,  2501,  2507,
    2516,  2519,  2519,  2520,  2520,  2521,  2521,  2522,  2522,  2523,
    2523,  2524,  2524,  2525,  2525,  2526,  2526,  2527,  2527,  2528,
    2528,  2529,  2529,  2530,  2530,  2531,  2531,  2532,  2532,  2533,
    2534,  2534,  2535,  2535,  2536,  2536,  2537,  2537,  2538,  2538,
    2539,  2540,  2541,  2541,  2542,  2543,  2544,  2544,  2545,  2545,
    2546,  2547,  2547,  2548,  2548,  2549,  2549,  2550,  2553,  2558,
    2564,  2570,  2576,  2581,  2586,  2591,  2596,  2601,  2606,  2611,
    2616,  2621,  2626,  2631,  2636,  2641,  2646,  2651,  2656,  2662,
    2673,  2678,  2687,  2692,  2697,  2702,  2707,  2712,  2715,  2720,
    2723,  2728,  2733,  2738,  2743,  2748,  2753,  2758,  2763,  2768,
    2779,  2784,  2789,  2794,  2803,  2812,  2817,  2822,  2828,  2827,
    2832,  2832,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,
    2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,
    2887,  2890,  2896,  2895,  2900,  2900,  2901,  2904,  2907,  2910,
    2913,  2916,  2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,
    2943,  2946,  2949,  2952,  2955,  2958,  2963,  2968,  2973,  2978,
    2987,  2990,  2990,  2991,  2992,  2992,  2992,  2993,  2993,  2994,
    2994,  2995,  2995,  2996,  2997,  2997,  2998,  2999,  2999,  3000,
    3000,  3002,  3007,  3012,  3017,  3022,  3027,  3032,  3037,  3042,
    3047,  3052,  3057,  3062,  3067,  3072,  3077,  3082,  3090,  3093,
    3093,  3094,  3094,  3095,  3096,  3096,  3097,  3098,  3100,  3106,
    3112,  3121,  3135,  3141
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BYTES", "KBYTES", "MBYTES",
  "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "IRCD_FLAGS",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_TIME", "GLINE_REQUEST_DURATION",
  "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6", "GLOBAL_KILL", "IRCD_AUTH",
  "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB",
  "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
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
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
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
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
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
  "general_default_floodcount", "general_client_flood", "channel_entry",
  "channel_items", "channel_item", "channel_disable_fake_channels",
  "channel_restrict_channels", "channel_use_except", "channel_use_invex",
  "channel_use_knock", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_max_chans_per_oper", "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULL
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
     249,   249,   249,   249,   249,   249,   250,   250,   251,   251,
     251,   251,   251,   251,   252,   252,   253,   253,   253,   253,
     254,   255,   255,   256,   256,   256,   257,   258,   259,   260,
     260,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   262,   263,   264,
     264,   265,   265,   266,   266,   267,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   282,   283,   283,   283,   283,   284,   285,   286,
     287,   288,   288,   289,   289,   289,   290,   292,   291,   293,
     293,   294,   294,   294,   294,   295,   296,   296,   298,   297,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   302,
     301,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   306,   307,   308,   309,   310,   312,   311,
     313,   313,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   316,   315,   317,   317,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   320,   319,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   337,   336,   339,   338,
     340,   340,   341,   341,   341,   342,   342,   343,   343,   343,
     343,   343,   345,   344,   346,   346,   347,   347,   348,   349,
     351,   350,   352,   352,   353,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   355,   356,   357,   359,   358,   360,
     360,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     362,   363,   364,   366,   365,   367,   367,   368,   368,   368,
     368,   369,   370,   371,   372,   373,   373,   374,   374,   375,
     377,   376,   378,   378,   379,   379,   379,   379,   380,   381,
     383,   382,   384,   384,   385,   385,   385,   385,   385,   385,
     385,   385,   385,   385,   387,   386,   388,   388,   389,   389,
     389,   390,   392,   391,   393,   393,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   396,   395,   397,   397,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   398,   398,   399,   400,   401,   402,   403,   404,
     405,   405,   407,   406,   408,   408,   409,   409,   409,   409,
     410,   411,   412,   413,   414,   416,   415,   418,   417,   419,
     419,   420,   421,   421,   422,   422,   422,   422,   423,   424,
     426,   425,   427,   427,   428,   428,   428,   429,   430,   431,
     432,   432,   433,   433,   434,   436,   435,   438,   437,   439,
     439,   440,   441,   441,   442,   442,   442,   442,   443,   444,
     445,   446,   446,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   477,   478,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   497,   496,
     498,   498,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   501,   500,   502,   502,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   504,   505,   506,   507,
     508,   509,   509,   510,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   510,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     529,   530,   530,   530,   530,   530,   530,   530,   531,   532,
     533,   534,   535,   536
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
       1,     1,     1,     1,     1,     1,     2,     4,     4,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   346,   400,     0,
     415,     0,   250,   385,   226,     0,     0,   129,   283,     0,
       0,   300,   324,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   610,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   592,   609,   605,   593,   594,
     595,   597,   598,   599,   600,   601,   596,   602,   603,   604,
     606,   607,   608,     0,     0,     0,   413,     0,     0,   411,
     412,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   562,     0,   538,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   432,   485,
     477,   478,   479,   480,   481,   482,   483,   476,   443,   433,
     434,   470,   435,   436,   437,   438,   439,   440,   441,   442,
     473,   444,   445,   446,   447,   484,   449,   454,   450,   452,
     451,   465,   466,   453,   455,   456,   457,   458,   459,   448,
     461,   462,   463,   486,   474,   475,   472,   464,   460,   468,
     469,   467,   471,     0,     0,     0,     0,     0,     0,   102,
     103,   104,     0,     0,     0,     0,     0,    42,    43,    44,
       0,     0,   637,     0,     0,     0,     0,     0,     0,     0,
     630,   631,   632,   635,   633,   634,   636,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    63,    64,    62,    59,    58,
      65,    51,    61,    54,    55,    56,    52,    60,    57,    53,
       0,     0,   298,     0,     0,   296,   297,    96,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   591,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   200,   201,
     204,     0,     0,     0,     0,     0,   372,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,   350,   351,   352,
     353,   354,   356,   355,   358,   362,   359,   360,   361,   357,
     406,     0,     0,     0,   403,   404,   405,     0,     0,   410,
     427,     0,     0,   417,   426,     0,   423,   424,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,   253,   254,   255,   256,   261,
     257,   258,   259,   260,   397,     0,   387,     0,   396,     0,
     393,   394,   395,     0,   228,     0,     0,     0,   238,     0,
     236,   237,   239,   240,   105,     0,     0,   101,     0,    45,
       0,     0,     0,    41,     0,     0,     0,   172,     0,     0,
       0,   148,     0,     0,   132,   133,   134,   135,   138,   139,
     137,   136,   140,     0,     0,     0,     0,     0,   286,   287,
     288,   289,     0,     0,     0,     0,     0,     0,     0,   629,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
     310,     0,     0,   303,   304,   305,   306,     0,     0,   332,
       0,   327,   328,   329,     0,     0,   295,     0,     0,     0,
      90,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,   363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,   402,     0,   409,     0,     0,
       0,     0,   422,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
     430,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,   392,   241,     0,     0,
       0,     0,     0,   235,     0,   100,     0,     0,     0,    40,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   290,     0,     0,     0,     0,   285,     0,     0,     0,
       0,     0,     0,   628,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,    70,    75,    76,     0,    74,
       0,     0,     0,     0,     0,    48,   307,     0,     0,     0,
       0,   302,   330,     0,     0,     0,   326,     0,   294,    99,
      98,    97,   623,   622,   611,    26,    26,    26,    26,    26,
      28,    27,   616,   617,   621,   619,   618,   624,   625,   626,
     627,   620,   612,   613,   614,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   347,     0,     0,   401,   414,     0,
       0,     0,   416,   502,   506,   522,   588,   536,   500,   530,
     533,   501,   490,   489,   491,   492,   493,   509,   498,   499,
     512,   497,   511,   510,   505,   504,   503,   531,   488,   529,
     586,   587,   526,   523,   573,   566,   583,   584,   567,   568,
     569,   570,   578,   571,   581,   585,   574,   579,   575,   580,
     572,   577,   576,   582,     0,   565,   528,   548,   542,   559,
     560,   543,   544,   545,   546,   554,   547,   557,   561,   550,
     555,   551,   556,   549,   553,   552,   558,     0,   541,   521,
     524,   535,   495,   496,   525,   514,   519,   520,   517,   518,
     515,   516,   508,   507,    34,    34,    34,    36,    35,   589,
     534,   537,   527,   532,   494,   513,     0,     0,     0,     0,
       0,     0,     0,     0,   251,     0,     0,     0,   386,     0,
       0,     0,   246,   242,   245,   227,   106,     0,     0,   118,
       0,     0,   110,   111,   113,   112,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
     284,   638,   642,   640,   643,   639,   641,    83,    89,    81,
      85,    84,    78,    77,    79,    67,     0,    68,     0,    82,
      80,    88,    86,    87,     0,     0,     0,   301,     0,     0,
     325,   299,    29,    30,    31,    32,    33,   223,   224,   217,
     219,   221,   220,   218,   213,   225,   216,   214,   215,   222,
     368,   370,   371,   383,   380,   376,   377,   379,   378,     0,
     375,   365,   381,   382,   364,   369,   367,   384,   366,   407,
     408,   428,   429,   421,     0,   420,   563,     0,   539,     0,
      37,    38,    39,   265,   266,   275,   272,   277,   274,   273,
     279,   276,   278,   271,     0,   270,   264,   282,   281,   280,
     263,   399,   391,     0,   390,   398,   233,   234,   232,     0,
     231,   249,   248,     0,     0,     0,   114,     0,     0,     0,
       0,   109,   147,   145,   187,   184,   183,   176,   178,   194,
     188,   191,   186,   177,   192,   180,   189,   193,   181,   190,
     185,   179,   182,     0,   175,   142,   144,   146,   158,   152,
     169,   170,   153,   154,   155,   156,   164,   157,   167,   171,
     160,   165,   161,   166,   159,   163,   162,   168,     0,   151,
     143,   292,   293,   291,    69,    73,   308,   314,   320,   323,
     316,   322,   317,   321,   319,   315,   318,     0,   313,   309,
     331,   336,   342,   345,   338,   344,   339,   343,   341,   337,
     340,     0,   335,   373,     0,   418,     0,   564,   540,   268,
       0,   388,     0,   229,     0,   247,   244,   243,     0,     0,
       0,     0,   108,   173,     0,   149,     0,   311,     0,   333,
       0,   374,   419,   269,   389,   230,   115,   124,   127,   126,
     123,   128,   125,   122,     0,   121,   117,   116,   174,   150,
     312,   334,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   810,   811,   957,   958,    25,   246,   247,
     248,   249,    26,   283,   284,   285,   286,   774,   775,   778,
     779,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    27,    71,    72,    73,    74,    75,
      28,   238,   239,   240,   241,   242,   991,   992,   993,   994,
     995,  1128,  1254,  1255,    29,    60,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   747,  1178,  1179,   532,   743,
    1153,  1154,    30,    49,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,    31,
      57,   498,   728,  1119,  1120,   499,   500,   501,  1125,   983,
     984,   502,   503,    32,    55,   474,   475,   476,   477,   478,
     479,   480,   714,  1104,  1105,   481,   482,   483,    33,    61,
     537,   538,   539,   540,   541,    34,   304,   305,   306,    35,
      64,   572,   573,   574,   575,   576,   788,  1197,  1198,    36,
      65,   580,   581,   582,   583,   794,  1211,  1212,    37,    50,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     631,  1069,  1070,   385,   386,   387,   388,   389,    38,    56,
     488,   723,  1113,  1114,   489,   490,   491,   492,    39,    51,
     393,   394,   395,   396,    40,   118,   119,   120,    41,    53,
     404,   650,  1084,  1085,   405,   406,   407,   408,    42,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     442,   937,   938,   228,   440,   914,   915,   229,   230,   231,
     232,    43,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    44,   259,   260,   261,   262,   263,   264,   265,   266
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -619
static const yytype_int16 yypact[] =
{
    -619,   641,  -619,  -209,  -226,  -224,  -619,  -619,  -619,  -218,
    -619,  -182,  -619,  -619,  -619,  -180,  -144,  -619,  -619,  -136,
    -129,  -619,  -619,   -95,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,    21,   594,   -81,
     -76,   -73,    13,   -59,   409,   -45,   -40,   -37,     3,    26,
     -30,   -17,    27,   456,   -11,    -6,    62,    52,    51,    63,
      70,     6,  -619,  -619,  -619,  -619,  -619,    75,    81,    87,
      88,    96,    97,    98,   102,   104,   105,   107,   109,   111,
     115,   126,   127,   128,   207,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   896,   382,    14,  -619,   129,    10,  -619,
    -619,   225,  -619,   130,   132,   133,   134,   136,   137,   139,
     149,   150,   151,   152,   153,   154,   159,   161,   164,   168,
     169,   170,   171,   174,   175,   176,   178,   183,   188,   189,
     195,   197,   200,   203,  -619,   206,  -619,   209,   211,   215,
     220,   221,   222,   224,   226,   227,   230,   231,   234,   235,
     242,   243,   244,   245,   246,   248,   249,   101,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   385,    15,    60,   160,   250,    68,  -619,
    -619,  -619,    82,   228,   251,   256,    74,  -619,  -619,  -619,
     311,    78,  -619,   262,   263,   264,   266,   268,   269,     5,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,   274,   273,   279,
     283,   286,   289,   290,   292,   293,   295,   297,   298,   299,
     300,   301,   303,   157,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
     131,    37,  -619,   307,    18,  -619,  -619,  -619,   272,   322,
     422,   313,  -619,   236,   447,   384,   451,   451,   452,   453,
     454,   389,   392,   459,   451,   395,   397,   399,   401,   402,
     337,  -619,   343,   341,   345,   347,   348,   349,   351,   352,
     355,   360,   361,   362,   363,   364,   158,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,   368,   366,   367,   369,   370,  -619,   374,   375,   380,
     381,   383,   386,   388,   390,    34,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,   391,   394,    24,  -619,  -619,  -619,   503,   398,  -619,
    -619,   404,   405,  -619,  -619,    20,  -619,  -619,  -619,   471,
     451,   451,   541,   476,   477,   544,   528,   484,   451,   486,
     451,   553,   556,   557,   492,   493,   498,   451,   546,   499,
     571,   572,   451,   574,   575,   558,   580,   584,   519,   520,
     458,   521,   460,   451,   451,   523,   451,   531,   535,   537,
    -106,   -85,   538,   542,   451,   451,   607,   588,   451,   552,
     561,   562,   565,   485,  -619,   487,   497,   501,  -619,   504,
     506,   507,   508,   509,   255,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,   513,  -619,   514,  -619,     9,
    -619,  -619,  -619,   490,  -619,   515,   516,   517,  -619,    11,
    -619,  -619,  -619,  -619,  -619,   568,   525,  -619,   526,  -619,
     617,   638,   529,  -619,   530,   532,   534,  -619,   536,   539,
     540,  -619,   545,   287,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   533,   548,   549,   550,    12,  -619,  -619,
    -619,  -619,   597,   598,   645,   606,   610,   451,   547,  -619,
    -619,   652,   611,   660,   665,   666,   667,   668,   669,    80,
      92,   672,   673,   698,   678,   680,   570,  -619,   576,   569,
    -619,   577,    23,  -619,  -619,  -619,  -619,   578,   587,  -619,
      46,  -619,  -619,  -619,   682,   579,  -619,   581,   591,   595,
    -619,   599,   600,   602,   208,   608,   612,   614,   615,   625,
     626,   629,   630,   635,   637,   643,   646,   647,   658,  -619,
    -619,   700,   707,   451,   709,   726,   738,   743,   685,   749,
     773,   451,   451,   607,   659,  -619,  -619,   774,    85,   775,
     732,   675,   781,   783,   791,   792,   814,   795,   796,   797,
     687,  -619,   799,   800,   690,  -619,   691,  -619,   803,   804,
     692,   694,  -619,   696,   697,   699,   701,   702,   703,   704,
     705,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   727,   728,   729,
     730,   731,   733,   734,   644,   735,   679,   736,   737,   739,
     740,   744,   745,   747,   748,   750,   751,   752,   753,   755,
     756,   757,    16,   758,   759,   760,   761,   762,   763,   764,
    -619,  -619,   809,   766,   746,   817,   839,   819,   820,   837,
     765,  -619,   843,   767,   849,   768,  -619,  -619,   769,   880,
     882,   905,   776,  -619,   777,  -619,   113,   778,   779,  -619,
    -619,   885,   841,   782,   891,   892,   895,   784,   897,   788,
    -619,  -619,   900,   901,   902,   793,  -619,   794,   798,   801,
     802,   805,   806,  -619,   807,   808,   810,   811,   813,   815,
     816,   818,  -619,  -619,  -203,  -619,  -619,  -619,  -201,  -619,
     821,   822,   823,   824,   825,  -619,  -619,   903,   826,   906,
     827,  -619,  -619,   907,   828,   830,  -619,   832,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,   451,   451,   451,   451,   451,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,   833,   834,   835,   836,
     838,   840,   842,   844,   845,   846,   847,   848,   850,  -619,
     851,   852,   853,   854,   855,    -7,   856,   857,   858,   859,
     860,   861,   862,   863,  -619,   864,   865,  -619,  -619,   866,
     867,   240,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -200,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -194,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,   607,   607,   607,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,   868,   869,   706,   870,
     871,   872,   873,   874,  -619,   875,   909,   876,  -619,   -43,
     877,   878,   881,   879,  -619,  -619,  -619,   884,   883,  -619,
     886,    22,  -619,  -619,  -619,  -619,  -619,  -619,   887,   888,
     518,   890,   893,   894,   708,   898,  -619,   899,   904,   908,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,    80,  -619,    92,  -619,
    -619,  -619,  -619,  -619,   910,   494,   911,  -619,   912,   551,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -193,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -188,  -619,  -619,   644,  -619,   679,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -186,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -169,  -619,  -619,  -619,  -619,  -619,  -160,
    -619,  -619,  -619,   929,   905,   913,  -619,   915,   889,  -102,
     914,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -149,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,   -68,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,   -41,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,   -36,  -619,  -619,    -7,  -619,   240,  -619,  -619,  -619,
     706,  -619,   909,  -619,   -43,  -619,  -619,  -619,   916,   359,
     917,   918,  -619,  -619,   518,  -619,   708,  -619,   494,  -619,
     551,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,   -26,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   359,  -619
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -619,  -619,  -619,  -439,  -315,  -618,  -456,  -619,  -619,   919,
    -619,  -619,  -619,  -619,   785,  -619,  -619,  -619,    25,  -619,
      28,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,   970,  -619,  -619,  -619,
    -619,  -619,   923,  -619,  -619,  -619,  -619,    79,  -619,  -619,
    -619,  -619,  -619,  -221,  -619,  -619,  -619,   560,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -177,  -619,  -619,
    -619,  -173,  -619,  -619,  -619,   787,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -145,  -619,   582,  -619,  -619,  -619,
     -39,  -619,  -619,  -619,  -619,  -619,   648,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,   -99,  -619,  -619,  -619,  -619,  -619,
    -619,   554,  -619,  -619,  -619,  -619,  -619,   920,  -619,  -619,
    -619,  -619,   555,  -619,  -619,  -619,  -619,  -619,  -115,  -619,
    -619,  -619,   559,  -619,  -619,  -619,  -619,  -116,  -619,  -619,
    -619,   770,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,   -77,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   -84,  -619,   653,  -619,  -619,  -619,  -619,
    -619,   754,  -619,  -619,  -619,  -619,  1025,  -619,  -619,  -619,
    -619,  -619,  -619,   -72,  -619,   771,  -619,  -619,  -619,  -619,
     971,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,    73,  -619,  -619,  -619,    64,  -619,  -619,  -619,
    -619,  -619,  -619,  1055,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,  -619,
    -619,  -619,  -619,   921,  -619,  -619,  -619,  -619,  -619,  -619
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     703,   595,   596,  1065,   236,  1066,   252,    67,   702,   603,
     484,   116,   493,   533,   116,   390,   484,  1116,    47,   302,
      48,   400,    67,   987,   568,   390,    52,   243,   252,   954,
     955,   956,   534,    45,    46,   361,    68,   362,   577,  1025,
     363,  1027,  1086,  1026,    69,  1028,  1087,   577,  1088,  1213,
     253,    68,  1089,  1214,  1215,   494,  1219,   364,  1216,    69,
    1220,   493,    54,   302,    58,   254,   255,   256,   257,   236,
     694,   695,   253,  1221,   365,   243,   495,  1222,   366,   533,
     117,   496,  1223,   117,   391,   258,  1224,   254,   255,   256,
     257,   696,   697,  1233,   391,   654,   655,  1234,   534,   367,
      59,   368,   122,   662,   494,   664,    70,   258,    62,   123,
     124,  1230,   671,   369,   987,    63,   535,   676,   303,   125,
     401,    70,   988,   569,   244,   495,   702,   126,   687,   688,
     496,   690,   568,   127,   370,   128,   129,   578,   130,   700,
     701,   497,   485,   705,   131,   536,   578,   392,   485,    66,
     132,   133,   245,   402,   134,   135,   136,   392,   267,   332,
     137,  1117,   303,   113,   371,   138,  1118,   838,   114,   139,
     140,   115,   244,   141,  1235,   486,   142,   143,  1236,   333,
     334,   486,   535,   335,   144,   121,   403,   268,   989,   570,
     497,   145,   146,   372,   147,   148,   149,   150,   151,   233,
     245,  1237,  1067,   579,   234,  1238,  1239,   235,    76,   152,
    1240,   536,   579,   988,   250,  1068,  1262,   153,   154,   155,
    1263,   156,   373,   269,   157,   158,   400,   251,   159,   772,
     773,   569,   762,   300,    77,    78,   237,   487,   301,   160,
      79,   776,   777,   487,  -107,   336,   337,   338,   548,   311,
     339,   571,   725,   398,   732,   755,   465,   270,   340,   271,
     272,   585,   990,   651,   161,  1130,   790,   644,   162,   374,
     341,   342,   163,   164,   165,   166,   167,   640,   466,   989,
     168,   169,   841,   842,    80,    81,   343,   344,   514,   795,
     170,    82,    83,    84,   307,   467,   308,   570,   828,   468,
     273,   237,   274,   275,   276,   277,   836,   837,   309,  -107,
     515,   506,   514,    85,    86,   310,   345,   512,   594,   278,
     313,   171,   172,   508,   173,   401,   314,   516,    87,    88,
     174,   517,   315,   316,   515,   175,  1090,  1091,  1092,    89,
     176,   317,   318,   319,   463,   279,   591,   320,    90,   321,
     322,   516,   323,   990,   324,   517,   325,   280,   402,   571,
     326,   805,   806,   807,   808,   809,  1042,  1043,  1044,  1045,
    1046,   327,   328,   329,   397,   409,  1083,   410,   411,   412,
     469,   413,   414,   361,   415,   362,   465,   518,   363,   470,
     471,   403,   281,   282,   416,   417,   418,   419,   420,   421,
     566,   624,   504,   587,   422,   364,   423,  1247,   466,   424,
     122,   518,   519,   425,   426,   427,   428,   123,   124,   429,
     430,   431,   365,   432,   472,   467,   366,   125,   433,   468,
    1248,   520,  1249,   434,   435,   126,   519,    91,    92,    93,
     436,   127,   437,   128,   129,   438,   130,   367,   439,   368,
     330,   441,   131,   588,   443,   520,   444,   267,   132,   133,
     445,   369,   134,   135,   136,   446,   447,   448,   137,   449,
     509,   450,   451,   138,  1250,   452,   453,   139,   140,   454,
     455,   141,   370,   473,   142,   143,   268,   456,   457,   458,
     459,   460,   144,   461,   462,   505,   510,   521,   720,   145,
     146,   511,   147,   148,   149,   150,   151,   542,   543,   544,
     469,   545,   371,   546,   547,   522,   550,   152,   551,   470,
     471,   521,   269,  1134,   552,   153,   154,   155,   553,   156,
     749,   554,   157,   158,   555,   556,   159,   557,   558,   522,
     559,   372,   560,   561,   562,   563,   564,   160,   565,  1135,
    1251,  1252,   584,   589,   472,   590,   270,   592,   271,   272,
     593,   594,   597,   598,   599,   600,  1136,  1187,   601,   602,
     373,   604,   161,   605,  1137,   606,   162,   607,   608,   609,
     163,   164,   165,   166,   167,   610,   611,  1253,   168,   169,
     612,  1138,   613,   614,   615,    76,   616,   617,   170,   273,
     618,   274,   275,   276,   277,   619,   620,   621,   622,   623,
     626,   627,   628,   473,   629,   630,  1139,   374,   278,   632,
     633,    77,    78,  1140,  1201,   634,   635,    79,   636,   171,
     172,   637,   173,   638,   646,   639,   642,  1141,   174,   643,
     647,     2,     3,   175,   279,  1188,     4,   653,   176,   648,
     649,   656,   657,   658,   659,  1142,   280,  1143,  1144,   660,
     661,     5,   663,   665,     6,     7,   666,   667,   668,   669,
       8,    80,    81,  1231,   670,   673,  1189,   672,    82,    83,
      84,   674,   675,     9,   677,   678,  1190,    10,    11,   679,
     680,   281,   282,  1191,   681,   682,   683,   685,    12,   689,
      85,    86,  1202,   684,   894,   686,  1192,   691,  1193,  1194,
    1145,   692,    13,   693,   698,    87,    88,   702,   699,   704,
    1146,  1195,    14,    15,  1147,  1095,    89,   710,   706,   711,
    1148,  1196,   727,  1203,  1149,    90,  1150,   707,   708,   917,
      16,   709,   712,  1204,   734,  1151,   713,  1096,   737,   715,
    1205,   716,   717,   718,   719,  1152,    17,  1097,   722,   724,
     729,   730,   731,  1206,  1098,  1207,  1208,   735,  1158,   738,
     736,   739,   740,   757,   758,   751,   759,   741,  1209,   742,
    1099,   744,   760,   764,   745,   746,   761,   765,  1210,   763,
     748,   766,    18,   752,   753,   754,   767,   768,   769,   770,
     771,    19,    20,   780,   781,    21,    22,  1100,   782,   783,
     826,   784,   785,   797,   787,  1101,   833,   827,   786,   829,
     792,   798,   789,   799,    91,    92,    93,   895,   896,   897,
     898,   899,   793,   800,   900,   901,   830,   801,   902,   903,
     904,   802,   803,   905,   804,   906,   907,   908,   831,   909,
     812,   910,   911,   832,   813,   912,   814,   815,  1102,   834,
      23,   913,   918,   919,   920,   921,   922,   816,   817,   923,
     924,   818,   819,   925,   926,   927,  1103,   820,   928,   821,
     929,   930,   931,   835,   932,   822,   933,   934,   823,   824,
     935,  1159,  1160,  1161,  1162,  1163,   936,   332,  1164,  1165,
     825,   839,  1166,  1167,  1168,   840,   843,  1169,   844,  1170,
    1171,  1172,   846,  1173,   847,  1174,  1175,   333,   334,  1176,
     845,   335,   848,   849,   850,  1177,   851,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   862,   861,   863,   864,
     966,   865,   967,   866,   867,   868,   869,   870,   969,   970,
     971,   972,   871,   872,   873,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   973,   887,
     888,   889,   890,   891,   975,   892,   893,   916,   939,   940,
     977,   941,   942,   336,   337,   338,   943,   944,   339,   945,
     946,   968,   947,   948,   949,   950,   340,   951,   952,   953,
     959,   960,   961,   962,   963,   964,   965,   974,   341,   342,
     978,   980,   976,   981,   979,   982,   998,   999,   985,   986,
     996,   997,  1001,  1002,   343,   344,  1003,  1000,  1005,  1004,
    1006,  1007,  1008,  1009,  1034,  1010,  1011,  1036,  1038,  1225,
    1012,   312,  1264,  1013,  1014,  1112,  1228,  1015,  1016,  1017,
    1018,  1184,  1019,  1020,   345,  1021,  1185,  1022,  1023,  1259,
    1024,  1258,  1123,  1029,  1030,  1031,  1032,  1033,   567,  1037,
    1131,  1035,  1040,  1039,  1041,  1047,  1048,  1049,  1050,  1245,
    1051,   733,  1052,   750,  1053,  1226,  1054,  1055,  1056,  1057,
    1058,   756,  1059,  1060,  1061,  1062,  1063,  1064,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1093,  1094,  1106,  1107,  1108,  1109,  1110,  1111,  1115,  1121,
    1122,  1243,   721,  1260,  1261,  1124,  1126,   791,  1127,  1132,
    1133,  1129,  1155,   625,  1229,  1156,  1157,  1241,  1244,   796,
    1180,  1181,   726,   399,  1242,   641,  1182,   645,   464,   331,
    1183,  1217,  1186,  1199,  1200,  1227,  1232,     0,  1246,  1256,
    1257,   507,  1218,     0,     0,   513,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   652,     0,     0,     0,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   586
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-619))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     456,   316,   317,    10,     1,    12,     1,     1,   110,   324,
       1,     1,     1,     1,     1,     1,     1,    60,   244,     1,
     244,     1,     1,     1,     1,     1,   244,     1,     1,    13,
      14,    15,    20,   242,   243,     1,    30,     3,     1,   242,
       6,   242,   242,   246,    38,   246,   246,     1,   242,   242,
      45,    30,   246,   246,   242,    44,   242,    23,   246,    38,
     246,     1,   244,     1,   244,    60,    61,    62,    63,     1,
     176,   177,    45,   242,    40,     1,    65,   246,    44,     1,
      70,    70,   242,    70,    70,    80,   246,    60,    61,    62,
      63,   176,   177,   242,    70,   410,   411,   246,    20,    65,
     244,    67,     1,   418,    44,   420,   100,    80,   244,     8,
       9,   213,   427,    79,     1,   244,   104,   432,   100,    18,
     100,   100,   100,   100,    98,    65,   110,    26,   443,   444,
      70,   446,     1,    32,   100,    34,    35,   100,    37,   454,
     455,   130,   133,   458,    43,   133,   100,   133,   133,   244,
      49,    50,   126,   133,    53,    54,    55,   133,     1,     1,
      59,   204,   100,   244,   130,    64,   209,   623,   244,    68,
      69,   244,    98,    72,   242,   166,    75,    76,   246,    21,
      22,   166,   104,    25,    83,   244,   166,    30,   166,   166,
     130,    90,    91,   159,    93,    94,    95,    96,    97,   244,
     126,   242,   209,   166,   244,   246,   242,   244,     1,   108,
     246,   133,   166,   100,   244,   222,   242,   116,   117,   118,
     246,   120,   188,    66,   123,   124,     1,   244,   127,   149,
     150,   100,   547,   244,    27,    28,   233,   228,   244,   138,
      33,   149,   150,   228,   241,    87,    88,    89,   243,   243,
      92,   228,   243,   243,   243,   243,     1,   100,   100,   102,
     103,   243,   240,   243,   163,   243,   243,   243,   167,   235,
     112,   113,   171,   172,   173,   174,   175,   243,    23,   166,
     179,   180,   197,   198,    77,    78,   128,   129,     1,   243,
     189,    84,    85,    86,   242,    40,   245,   166,   613,    44,
     143,   233,   145,   146,   147,   148,   621,   622,   245,   241,
      23,   243,     1,   106,   107,   245,   158,   243,   110,   162,
     245,   220,   221,   241,   223,   100,   245,    40,   121,   122,
     229,    44,   245,   245,    23,   234,   954,   955,   956,   132,
     239,   245,   245,   245,   243,   188,   110,   245,   141,   245,
     245,    40,   245,   240,   245,    44,   245,   200,   133,   228,
     245,   153,   154,   155,   156,   157,   805,   806,   807,   808,
     809,   245,   245,   245,   245,   245,   136,   245,   245,   245,
     125,   245,   245,     1,   245,     3,     1,   100,     6,   134,
     135,   166,   235,   236,   245,   245,   245,   245,   245,   245,
     243,   243,   242,   131,   245,    23,   245,    48,    23,   245,
       1,   100,   125,   245,   245,   245,   245,     8,     9,   245,
     245,   245,    40,   245,   169,    40,    44,    18,   245,    44,
      71,   144,    73,   245,   245,    26,   125,   230,   231,   232,
     245,    32,   245,    34,    35,   245,    37,    65,   245,    67,
     243,   245,    43,   131,   245,   144,   245,     1,    49,    50,
     245,    79,    53,    54,    55,   245,   245,   245,    59,   245,
     242,   245,   245,    64,   115,   245,   245,    68,    69,   245,
     245,    72,   100,   228,    75,    76,    30,   245,   245,   245,
     245,   245,    83,   245,   245,   245,   245,   210,   243,    90,
      91,   245,    93,    94,    95,    96,    97,   245,   245,   245,
     125,   245,   130,   245,   245,   228,   242,   108,   245,   134,
     135,   210,    66,     5,   245,   116,   117,   118,   245,   120,
     243,   245,   123,   124,   245,   245,   127,   245,   245,   228,
     245,   159,   245,   245,   245,   245,   245,   138,   245,    31,
     191,   192,   245,   131,   169,   242,   100,   110,   102,   103,
     176,   110,   110,   110,   110,   176,    48,    73,   176,   110,
     188,   176,   163,   176,    56,   176,   167,   176,   176,   242,
     171,   172,   173,   174,   175,   242,   245,   228,   179,   180,
     245,    73,   245,   245,   245,     1,   245,   245,   189,   143,
     245,   145,   146,   147,   148,   245,   245,   245,   245,   245,
     242,   245,   245,   228,   245,   245,    98,   235,   162,   245,
     245,    27,    28,   105,    73,   245,   245,    33,   245,   220,
     221,   245,   223,   245,   131,   245,   245,   119,   229,   245,
     242,     0,     1,   234,   188,   151,     5,   176,   239,   245,
     245,   110,   176,   176,   110,   137,   200,   139,   140,   131,
     176,    20,   176,   110,    23,    24,   110,   110,   176,   176,
      29,    77,    78,  1129,   176,   176,   182,   131,    84,    85,
      86,   110,   110,    42,   110,   110,   192,    46,    47,   131,
     110,   235,   236,   199,   110,   176,   176,   176,    57,   176,
     106,   107,   151,   245,    60,   245,   212,   176,   214,   215,
     192,   176,    71,   176,   176,   121,   122,   110,   176,   131,
     202,   227,    81,    82,   206,    19,   132,   242,   176,   242,
     212,   237,   242,   182,   216,   141,   218,   176,   176,    60,
      99,   176,   245,   192,   176,   227,   245,    41,   131,   245,
     199,   245,   245,   245,   245,   237,   115,    51,   245,   245,
     245,   245,   245,   212,    58,   214,   215,   242,    60,   131,
     244,   242,   242,   176,   176,   242,   131,   245,   227,   245,
      74,   245,   176,   131,   245,   245,   176,   176,   237,   242,
     245,   131,   151,   245,   245,   245,   131,   131,   131,   131,
     131,   160,   161,   131,   131,   164,   165,   101,   110,   131,
     110,   131,   242,   131,   245,   109,   131,   110,   242,   110,
     242,   242,   245,   242,   230,   231,   232,   183,   184,   185,
     186,   187,   245,   242,   190,   191,   110,   242,   194,   195,
     196,   242,   242,   199,   242,   201,   202,   203,   110,   205,
     242,   207,   208,   110,   242,   211,   242,   242,   152,   110,
     219,   217,   183,   184,   185,   186,   187,   242,   242,   190,
     191,   242,   242,   194,   195,   196,   170,   242,   199,   242,
     201,   202,   203,   110,   205,   242,   207,   208,   242,   242,
     211,   183,   184,   185,   186,   187,   217,     1,   190,   191,
     242,   242,   194,   195,   196,   131,   131,   199,   176,   201,
     202,   203,   131,   205,   131,   207,   208,    21,    22,   211,
     245,    25,   131,   131,   110,   217,   131,   131,   131,   242,
     131,   131,   242,   242,   131,   131,   242,   245,   242,   242,
     131,   242,   176,   242,   242,   242,   242,   242,   131,   110,
     131,   131,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   131,   242,
     242,   242,   242,   242,   131,   242,   242,   242,   242,   242,
     131,   242,   242,    87,    88,    89,   242,   242,    92,   242,
     242,   245,   242,   242,   242,   242,   100,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   112,   113,
     242,   131,   245,   131,   245,   110,   131,   176,   242,   242,
     242,   242,   131,   131,   128,   129,   131,   245,   131,   245,
     242,   131,   131,   131,   131,   242,   242,   131,   131,   110,
     242,    71,  1263,   242,   242,   136,   131,   242,   242,   242,
     242,  1026,   242,   242,   158,   242,  1028,   242,   242,  1236,
     242,  1234,   181,   242,   242,   242,   242,   242,   283,   242,
     991,   245,   242,   245,   242,   242,   242,   242,   242,  1224,
     242,   499,   242,   523,   242,  1124,   242,   242,   242,   242,
     242,   537,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,  1220,   474,  1238,  1240,   246,   242,   572,   245,   242,
     242,   245,   242,   346,   245,   242,   242,  1214,  1222,   580,
     242,   242,   489,   118,  1216,   375,   242,   393,   177,    94,
     242,  1087,   242,   242,   242,   242,   242,    -1,   242,   242,
     242,   238,  1089,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,    -1,    -1,
     259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   304
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   248,     0,     1,     5,    20,    23,    24,    29,    42,
      46,    47,    57,    71,    81,    82,    99,   115,   151,   160,
     161,   164,   165,   219,   249,   254,   259,   281,   287,   301,
     319,   336,   350,   365,   372,   376,   386,   395,   415,   425,
     431,   435,   445,   508,   528,   242,   243,   244,   244,   320,
     396,   426,   244,   436,   244,   351,   416,   337,   244,   244,
     302,   366,   244,   244,   377,   387,   244,     1,    30,    38,
     100,   282,   283,   284,   285,   286,     1,    27,    28,    33,
      77,    78,    84,    85,    86,   106,   107,   121,   122,   132,
     141,   230,   231,   232,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   244,   244,   244,     1,    70,   432,   433,
     434,   244,     1,     8,     9,    18,    26,    32,    34,    35,
      37,    43,    49,    50,    53,    54,    55,    59,    64,    68,
      69,    72,    75,    76,    83,    90,    91,    93,    94,    95,
      96,    97,   108,   116,   117,   118,   120,   123,   124,   127,
     138,   163,   167,   171,   172,   173,   174,   175,   179,   180,
     189,   220,   221,   223,   229,   234,   239,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   500,   504,
     505,   506,   507,   244,   244,   244,     1,   233,   288,   289,
     290,   291,   292,     1,    98,   126,   255,   256,   257,   258,
     244,   244,     1,    45,    60,    61,    62,    63,    80,   529,
     530,   531,   532,   533,   534,   535,   536,     1,    30,    66,
     100,   102,   103,   143,   145,   146,   147,   148,   162,   188,
     200,   235,   236,   260,   261,   262,   263,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     244,   244,     1,   100,   373,   374,   375,   242,   245,   245,
     245,   243,   283,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     243,   510,     1,    21,    22,    25,    87,    88,    89,    92,
     100,   112,   113,   128,   129,   158,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,     1,     3,     6,    23,    40,    44,    65,    67,    79,
     100,   130,   159,   188,   235,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   410,   411,   412,   413,   414,
       1,    70,   133,   427,   428,   429,   430,   245,   243,   433,
       1,   100,   133,   166,   437,   441,   442,   443,   444,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     501,   245,   497,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   243,   447,     1,    23,    40,    44,   125,
     134,   135,   169,   228,   352,   353,   354,   355,   356,   357,
     358,   362,   363,   364,     1,   133,   166,   228,   417,   421,
     422,   423,   424,     1,    44,    65,    70,   130,   338,   342,
     343,   344,   348,   349,   242,   245,   243,   289,   241,   242,
     245,   245,   243,   256,     1,    23,    40,    44,   100,   125,
     144,   210,   228,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   315,     1,    20,   104,   133,   367,   368,   369,
     370,   371,   245,   245,   245,   245,   245,   245,   243,   530,
     242,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   243,   261,     1,   100,
     166,   228,   378,   379,   380,   381,   382,     1,   100,   166,
     388,   389,   390,   391,   245,   243,   374,   131,   131,   131,
     242,   110,   110,   176,   110,   251,   251,   110,   110,   110,
     176,   176,   110,   251,   176,   176,   176,   176,   176,   242,
     242,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   243,   322,   242,   245,   245,   245,
     245,   407,   245,   245,   245,   245,   245,   245,   245,   245,
     243,   398,   245,   245,   243,   428,   131,   242,   245,   245,
     438,   243,   442,   176,   251,   251,   110,   176,   176,   110,
     131,   176,   251,   176,   251,   110,   110,   110,   176,   176,
     176,   251,   131,   176,   110,   110,   251,   110,   110,   131,
     110,   110,   176,   176,   245,   176,   245,   251,   251,   176,
     251,   176,   176,   176,   176,   177,   176,   177,   176,   176,
     251,   251,   110,   253,   131,   251,   176,   176,   176,   176,
     242,   242,   245,   245,   359,   245,   245,   245,   245,   245,
     243,   353,   245,   418,   245,   243,   422,   242,   339,   245,
     245,   245,   243,   343,   176,   242,   244,   131,   131,   242,
     242,   245,   245,   316,   245,   245,   245,   312,   245,   243,
     304,   242,   245,   245,   245,   243,   368,   176,   176,   131,
     176,   176,   251,   242,   131,   176,   131,   131,   131,   131,
     131,   131,   149,   150,   264,   265,   149,   150,   266,   267,
     131,   131,   110,   131,   131,   242,   242,   245,   383,   245,
     243,   379,   242,   245,   392,   243,   389,   131,   242,   242,
     242,   242,   242,   242,   242,   153,   154,   155,   156,   157,
     250,   251,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   110,   110,   251,   110,
     110,   110,   110,   131,   110,   110,   251,   251,   253,   242,
     131,   197,   198,   131,   176,   245,   131,   131,   131,   131,
     110,   131,   131,   131,   242,   131,   131,   242,   242,   131,
     131,   245,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,    60,   183,   184,   185,   186,   187,
     190,   191,   194,   195,   196,   199,   201,   202,   203,   205,
     207,   208,   211,   217,   502,   503,   242,    60,   183,   184,
     185,   186,   187,   190,   191,   194,   195,   196,   199,   201,
     202,   203,   205,   207,   208,   211,   217,   498,   499,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,    13,    14,    15,   252,   253,   242,
     242,   242,   242,   242,   242,   242,   131,   176,   245,   131,
     110,   131,   131,   131,   242,   131,   245,   131,   242,   245,
     131,   131,   110,   346,   347,   242,   242,     1,   100,   166,
     240,   293,   294,   295,   296,   297,   242,   242,   131,   176,
     245,   131,   131,   131,   245,   131,   242,   131,   131,   131,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   246,   242,   246,   242,
     242,   242,   242,   242,   131,   245,   131,   242,   131,   245,
     242,   242,   250,   250,   250,   250,   250,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,    10,    12,   209,   222,   408,
     409,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   136,   439,   440,   242,   246,   242,   246,
     252,   252,   252,   242,   242,    19,    41,    51,    58,    74,
     101,   109,   152,   170,   360,   361,   242,   242,   242,   242,
     242,   242,   136,   419,   420,   242,    60,   204,   209,   340,
     341,   242,   242,   181,   246,   345,   242,   245,   298,   245,
     243,   294,   242,   242,     5,    31,    48,    56,    73,    98,
     105,   119,   137,   139,   140,   192,   202,   206,   212,   216,
     218,   227,   237,   317,   318,   242,   242,   242,    60,   183,
     184,   185,   186,   187,   190,   191,   194,   195,   196,   199,
     201,   202,   203,   205,   207,   208,   211,   217,   313,   314,
     242,   242,   242,   242,   265,   267,   242,    73,   151,   182,
     192,   199,   212,   214,   215,   227,   237,   384,   385,   242,
     242,    73,   151,   182,   192,   199,   212,   214,   215,   227,
     237,   393,   394,   242,   246,   242,   246,   503,   499,   242,
     246,   242,   246,   242,   246,   110,   347,   242,   131,   245,
     213,   253,   242,   242,   246,   242,   246,   242,   246,   242,
     246,   409,   440,   361,   420,   341,   242,    48,    71,    73,
     115,   191,   192,   228,   299,   300,   242,   242,   318,   314,
     385,   394,   242,   246,   300
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

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

       Refer to the stacks through separate pointers, to allow yyoverflow
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
        case 26:
/* Line 1787 of yacc.c  */
#line 384 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 386 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 390 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 394 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 398 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 402 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 406 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 460 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 466 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 475 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 481 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 489 "conf_parser.y"
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

  case 78:
/* Line 1787 of yacc.c  */
#line 528 "conf_parser.y"
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

  case 79:
/* Line 1787 of yacc.c  */
#line 587 "conf_parser.y"
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

  case 80:
/* Line 1787 of yacc.c  */
#line 615 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 623 "conf_parser.y"
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

  case 82:
/* Line 1787 of yacc.c  */
#line 638 "conf_parser.y"
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

  case 83:
/* Line 1787 of yacc.c  */
#line 653 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 662 "conf_parser.y"
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

  case 85:
/* Line 1787 of yacc.c  */
#line 676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 685 "conf_parser.y"
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

  case 87:
/* Line 1787 of yacc.c  */
#line 713 "conf_parser.y"
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

  case 88:
/* Line 1787 of yacc.c  */
#line 743 "conf_parser.y"
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

  case 89:
/* Line 1787 of yacc.c  */
#line 766 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 781 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 790 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 817 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 823 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 828 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 840 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 845 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 848 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 868 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 876 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 880 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 894 "conf_parser.y"
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

  case 130:
/* Line 1787 of yacc.c  */
#line 907 "conf_parser.y"
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

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->addr,
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

  case 142:
/* Line 1787 of yacc.c  */
#line 997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1006 "conf_parser.y"
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

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->addr,
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

  case 144:
/* Line 1787 of yacc.c  */
#line 1043 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1055 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1066 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1108 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1132 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1140 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1281 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1285 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1295 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1302 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1360 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1375 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1387 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1393 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1399 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1411 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1423 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1444 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1460 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1466 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1484 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1489 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1503 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1523 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1532 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1544 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1556 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1618 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1653 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1666 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1675 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1686 "conf_parser.y"
    {
}
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 1691 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1695 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1699 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1703 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1707 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1711 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1715 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1719 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1723 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1730 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1749 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1759 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1779 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1791 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1800 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1815 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1833 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1848 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1856 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1876 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1921 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1929 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1950 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1957 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1970 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 1976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1995 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 2003 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 2007 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2011 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2015 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 2019 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2028 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2043 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->host && yy_aconf->passwd && yy_aconf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
        delete_conf_item(yy_conf);
    }
    else
    {
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
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 2087 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 2096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 2105 "conf_parser.y"
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

      memcpy(&yy_aconf->bind, res->ai_addr, res->ai_addrlen);
      yy_aconf->bind.ss.ss_family = res->ai_family;
      yy_aconf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 2131 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2149 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 2173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 2177 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2185 "conf_parser.y"
    {
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2190 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2208 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2250 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2275 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2333 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2347 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2375 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2379 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2403 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2409 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2423 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2448 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2488 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2493 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2508 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2554 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2559 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2571 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2587 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2592 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2597 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2602 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2607 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2612 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2617 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2622 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2637 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2642 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2647 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2652 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2657 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2663 "conf_parser.y"
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

  case 510:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2708 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2744 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2749 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2754 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2759 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2764 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2769 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2785 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2818 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2905 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2917 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2923 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2929 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2935 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2947 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2950 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2953 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2959 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2964 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2969 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2974 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2979 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 3003 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3013 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3018 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3023 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3028 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3033 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 3038 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 3043 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 3048 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 3053 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 3058 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 3063 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 3068 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 3073 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 3078 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 3083 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 638:
/* Line 1787 of yacc.c  */
#line 3101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 639:
/* Line 1787 of yacc.c  */
#line 3107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 640:
/* Line 1787 of yacc.c  */
#line 3113 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 3122 "conf_parser.y"
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

  case 642:
/* Line 1787 of yacc.c  */
#line 3136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 3142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 7018 "conf_parser.c"
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

#if !defined yyoverflow || YYERROR_VERBOSE
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



