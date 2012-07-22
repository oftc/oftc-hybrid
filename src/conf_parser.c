/* A Bison parser, made by GNU Bison 2.6.  */

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
#define YYBISON_VERSION "2.6"

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
#line 155 "conf_parser.c"

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
     DISABLE_HIDDEN = 289,
     DISABLE_REMOTE_COMMANDS = 290,
     DOTS_IN_IDENT = 291,
     DURATION = 292,
     EGDPOOL_PATH = 293,
     EMAIL = 294,
     ENABLE = 295,
     ENCRYPTED = 296,
     EXCEED_LIMIT = 297,
     EXEMPT = 298,
     FAILED_OPER_NOTICE = 299,
     IRCD_FLAGS = 300,
     FLATTEN_LINKS = 301,
     GECOS = 302,
     GENERAL = 303,
     GLINE = 304,
     GLINE_DURATION = 305,
     GLINE_ENABLE = 306,
     GLINE_EXEMPT = 307,
     GLINE_TIME = 308,
     GLINE_REQUEST_DURATION = 309,
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
     MAX_CHANS_PER_OPER = 341,
     MAX_CHANS_PER_USER = 342,
     MAX_GLOBAL = 343,
     MAX_IDENT = 344,
     MAX_LOCAL = 345,
     MAX_NICK_CHANGES = 346,
     MAX_NICK_TIME = 347,
     MAX_NUMBER = 348,
     MAX_TARGETS = 349,
     MAX_WATCH = 350,
     MESSAGE_LOCALE = 351,
     MIN_NONWILDCARD = 352,
     MIN_NONWILDCARD_SIMPLE = 353,
     MODULE = 354,
     MODULES = 355,
     NAME = 356,
     NEED_PASSWORD = 357,
     NETWORK_DESC = 358,
     NETWORK_NAME = 359,
     NICK = 360,
     NICK_CHANGES = 361,
     NO_CREATE_ON_SPLIT = 362,
     NO_JOIN_ON_SPLIT = 363,
     NO_OPER_FLOOD = 364,
     NO_TILDE = 365,
     NUMBER = 366,
     NUMBER_PER_IDENT = 367,
     NUMBER_PER_CIDR = 368,
     NUMBER_PER_IP = 369,
     NUMBER_PER_IP_GLOBAL = 370,
     OPERATOR = 371,
     OPERS_BYPASS_CALLERID = 372,
     OPER_ONLY_UMODES = 373,
     OPER_PASS_RESV = 374,
     OPER_SPY_T = 375,
     OPER_UMODES = 376,
     JOIN_FLOOD_COUNT = 377,
     JOIN_FLOOD_TIME = 378,
     PACE_WAIT = 379,
     PACE_WAIT_SIMPLE = 380,
     PASSWORD = 381,
     PATH = 382,
     PING_COOKIE = 383,
     PING_TIME = 384,
     PING_WARNING = 385,
     PORT = 386,
     QSTRING = 387,
     QUIET_ON_BAN = 388,
     REASON = 389,
     REDIRPORT = 390,
     REDIRSERV = 391,
     REGEX_T = 392,
     REHASH = 393,
     TREJECT_HOLD_TIME = 394,
     REMOTE = 395,
     REMOTEBAN = 396,
     RESTRICT_CHANNELS = 397,
     RESTRICTED = 398,
     RSA_PRIVATE_KEY_FILE = 399,
     RSA_PUBLIC_KEY_FILE = 400,
     SSL_CERTIFICATE_FILE = 401,
     SSL_DH_PARAM_FILE = 402,
     T_SSL_CLIENT_METHOD = 403,
     T_SSL_SERVER_METHOD = 404,
     T_SSLV3 = 405,
     T_TLSV1 = 406,
     RESV = 407,
     RESV_EXEMPT = 408,
     SECONDS = 409,
     MINUTES = 410,
     HOURS = 411,
     DAYS = 412,
     WEEKS = 413,
     SENDQ = 414,
     SEND_PASSWORD = 415,
     SERVERHIDE = 416,
     SERVERINFO = 417,
     IRCD_SID = 418,
     TKLINE_EXPIRE_NOTICES = 419,
     T_SHARED = 420,
     T_CLUSTER = 421,
     TYPE = 422,
     SHORT_MOTD = 423,
     SILENT = 424,
     SPOOF = 425,
     SPOOF_NOTICE = 426,
     STATS_E_DISABLED = 427,
     STATS_I_OPER_ONLY = 428,
     STATS_K_OPER_ONLY = 429,
     STATS_O_OPER_ONLY = 430,
     STATS_P_OPER_ONLY = 431,
     TBOOL = 432,
     TMASKED = 433,
     T_REJECT = 434,
     TS_MAX_DELTA = 435,
     TS_WARN_DELTA = 436,
     TWODOTS = 437,
     T_ALL = 438,
     T_BOTS = 439,
     T_SOFTCALLERID = 440,
     T_CALLERID = 441,
     T_CCONN = 442,
     T_CCONN_FULL = 443,
     T_SSL_CIPHER_LIST = 444,
     T_CLIENT_FLOOD = 445,
     T_DEAF = 446,
     T_DEBUG = 447,
     T_DLINE = 448,
     T_DRONE = 449,
     T_EXTERNAL = 450,
     T_FULL = 451,
     T_INVISIBLE = 452,
     T_IPV4 = 453,
     T_IPV6 = 454,
     T_LOCOPS = 455,
     T_MAX_CLIENTS = 456,
     T_NCHANGE = 457,
     T_OPERWALL = 458,
     T_REJ = 459,
     T_SERVER = 460,
     T_SERVNOTICE = 461,
     T_SET = 462,
     T_SKILL = 463,
     T_SPY = 464,
     T_SSL = 465,
     T_UMODES = 466,
     T_UNAUTH = 467,
     T_UNDLINE = 468,
     T_UNLIMITED = 469,
     T_UNRESV = 470,
     T_UNXLINE = 471,
     T_GLOBOPS = 472,
     T_WALLOP = 473,
     T_RESTART = 474,
     T_SERVICE = 475,
     T_SERVICES_NAME = 476,
     THROTTLE_TIME = 477,
     TOPICBURST = 478,
     TRUE_NO_OPER_FLOOD = 479,
     TKLINE = 480,
     TXLINE = 481,
     TRESV = 482,
     UNKLINE = 483,
     USER = 484,
     USE_EGD = 485,
     USE_EXCEPT = 486,
     USE_INVEX = 487,
     USE_KNOCK = 488,
     USE_LOGGING = 489,
     USE_WHOIS_ACTUALLY = 490,
     VHOST = 491,
     VHOST6 = 492,
     XLINE = 493,
     WARN = 494,
     WARN_NO_NLINE = 495,
     T_SIZE = 496,
     T_FILE = 497
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
#define DISABLE_HIDDEN 289
#define DISABLE_REMOTE_COMMANDS 290
#define DOTS_IN_IDENT 291
#define DURATION 292
#define EGDPOOL_PATH 293
#define EMAIL 294
#define ENABLE 295
#define ENCRYPTED 296
#define EXCEED_LIMIT 297
#define EXEMPT 298
#define FAILED_OPER_NOTICE 299
#define IRCD_FLAGS 300
#define FLATTEN_LINKS 301
#define GECOS 302
#define GENERAL 303
#define GLINE 304
#define GLINE_DURATION 305
#define GLINE_ENABLE 306
#define GLINE_EXEMPT 307
#define GLINE_TIME 308
#define GLINE_REQUEST_DURATION 309
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
#define MAX_CHANS_PER_OPER 341
#define MAX_CHANS_PER_USER 342
#define MAX_GLOBAL 343
#define MAX_IDENT 344
#define MAX_LOCAL 345
#define MAX_NICK_CHANGES 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_WATCH 350
#define MESSAGE_LOCALE 351
#define MIN_NONWILDCARD 352
#define MIN_NONWILDCARD_SIMPLE 353
#define MODULE 354
#define MODULES 355
#define NAME 356
#define NEED_PASSWORD 357
#define NETWORK_DESC 358
#define NETWORK_NAME 359
#define NICK 360
#define NICK_CHANGES 361
#define NO_CREATE_ON_SPLIT 362
#define NO_JOIN_ON_SPLIT 363
#define NO_OPER_FLOOD 364
#define NO_TILDE 365
#define NUMBER 366
#define NUMBER_PER_IDENT 367
#define NUMBER_PER_CIDR 368
#define NUMBER_PER_IP 369
#define NUMBER_PER_IP_GLOBAL 370
#define OPERATOR 371
#define OPERS_BYPASS_CALLERID 372
#define OPER_ONLY_UMODES 373
#define OPER_PASS_RESV 374
#define OPER_SPY_T 375
#define OPER_UMODES 376
#define JOIN_FLOOD_COUNT 377
#define JOIN_FLOOD_TIME 378
#define PACE_WAIT 379
#define PACE_WAIT_SIMPLE 380
#define PASSWORD 381
#define PATH 382
#define PING_COOKIE 383
#define PING_TIME 384
#define PING_WARNING 385
#define PORT 386
#define QSTRING 387
#define QUIET_ON_BAN 388
#define REASON 389
#define REDIRPORT 390
#define REDIRSERV 391
#define REGEX_T 392
#define REHASH 393
#define TREJECT_HOLD_TIME 394
#define REMOTE 395
#define REMOTEBAN 396
#define RESTRICT_CHANNELS 397
#define RESTRICTED 398
#define RSA_PRIVATE_KEY_FILE 399
#define RSA_PUBLIC_KEY_FILE 400
#define SSL_CERTIFICATE_FILE 401
#define SSL_DH_PARAM_FILE 402
#define T_SSL_CLIENT_METHOD 403
#define T_SSL_SERVER_METHOD 404
#define T_SSLV3 405
#define T_TLSV1 406
#define RESV 407
#define RESV_EXEMPT 408
#define SECONDS 409
#define MINUTES 410
#define HOURS 411
#define DAYS 412
#define WEEKS 413
#define SENDQ 414
#define SEND_PASSWORD 415
#define SERVERHIDE 416
#define SERVERINFO 417
#define IRCD_SID 418
#define TKLINE_EXPIRE_NOTICES 419
#define T_SHARED 420
#define T_CLUSTER 421
#define TYPE 422
#define SHORT_MOTD 423
#define SILENT 424
#define SPOOF 425
#define SPOOF_NOTICE 426
#define STATS_E_DISABLED 427
#define STATS_I_OPER_ONLY 428
#define STATS_K_OPER_ONLY 429
#define STATS_O_OPER_ONLY 430
#define STATS_P_OPER_ONLY 431
#define TBOOL 432
#define TMASKED 433
#define T_REJECT 434
#define TS_MAX_DELTA 435
#define TS_WARN_DELTA 436
#define TWODOTS 437
#define T_ALL 438
#define T_BOTS 439
#define T_SOFTCALLERID 440
#define T_CALLERID 441
#define T_CCONN 442
#define T_CCONN_FULL 443
#define T_SSL_CIPHER_LIST 444
#define T_CLIENT_FLOOD 445
#define T_DEAF 446
#define T_DEBUG 447
#define T_DLINE 448
#define T_DRONE 449
#define T_EXTERNAL 450
#define T_FULL 451
#define T_INVISIBLE 452
#define T_IPV4 453
#define T_IPV6 454
#define T_LOCOPS 455
#define T_MAX_CLIENTS 456
#define T_NCHANGE 457
#define T_OPERWALL 458
#define T_REJ 459
#define T_SERVER 460
#define T_SERVNOTICE 461
#define T_SET 462
#define T_SKILL 463
#define T_SPY 464
#define T_SSL 465
#define T_UMODES 466
#define T_UNAUTH 467
#define T_UNDLINE 468
#define T_UNLIMITED 469
#define T_UNRESV 470
#define T_UNXLINE 471
#define T_GLOBOPS 472
#define T_WALLOP 473
#define T_RESTART 474
#define T_SERVICE 475
#define T_SERVICES_NAME 476
#define THROTTLE_TIME 477
#define TOPICBURST 478
#define TRUE_NO_OPER_FLOOD 479
#define TKLINE 480
#define TXLINE 481
#define TRESV 482
#define UNKLINE 483
#define USER 484
#define USE_EGD 485
#define USE_EXCEPT 486
#define USE_INVEX 487
#define USE_KNOCK 488
#define USE_LOGGING 489
#define USE_WHOIS_ACTUALLY 490
#define VHOST 491
#define VHOST6 492
#define XLINE 493
#define WARN 494
#define WARN_NO_NLINE 495
#define T_SIZE 496
#define T_FILE 497



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 350 of yacc.c  */
#line 690 "conf_parser.c"
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
#line 719 "conf_parser.c"

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
#define YYLAST   1193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  645
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1270

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   247,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   243,
       2,   246,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   245,     2,   244,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242
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
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1934,
    1939,  1944,  1949,  1954,  1959,  1964
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     249,     0,    -1,    -1,   249,   250,    -1,   282,    -1,   288,
      -1,   302,    -1,   509,    -1,   320,    -1,   337,    -1,   351,
      -1,   260,    -1,   529,    -1,   366,    -1,   373,    -1,   377,
      -1,   387,    -1,   396,    -1,   416,    -1,   426,    -1,   432,
      -1,   446,    -1,   436,    -1,   255,    -1,     1,   243,    -1,
       1,   244,    -1,    -1,   252,    -1,   111,   251,    -1,   111,
     154,   251,    -1,   111,   155,   251,    -1,   111,   156,   251,
      -1,   111,   157,   251,    -1,   111,   158,   251,    -1,    -1,
     254,    -1,   111,   253,    -1,   111,    13,   253,    -1,   111,
      14,   253,    -1,   111,    15,   253,    -1,   100,   245,   256,
     244,   243,    -1,   256,   257,    -1,   257,    -1,   258,    -1,
     259,    -1,     1,   243,    -1,    99,   246,   132,   243,    -1,
     127,   246,   132,   243,    -1,   162,   245,   261,   244,   243,
      -1,   261,   262,    -1,   262,    -1,   273,    -1,   278,    -1,
     281,    -1,   275,    -1,   276,    -1,   277,    -1,   280,    -1,
     271,    -1,   270,    -1,   279,    -1,   274,    -1,   269,    -1,
     263,    -1,   264,    -1,   272,    -1,     1,   243,    -1,   148,
     246,   265,   243,    -1,   149,   246,   267,   243,    -1,   265,
     247,   266,    -1,   266,    -1,   150,    -1,   151,    -1,   267,
     247,   268,    -1,   268,    -1,   150,    -1,   151,    -1,   146,
     246,   132,   243,    -1,   144,   246,   132,   243,    -1,   147,
     246,   132,   243,    -1,   189,   246,   132,   243,    -1,   101,
     246,   132,   243,    -1,   163,   246,   132,   243,    -1,    30,
     246,   132,   243,    -1,   104,   246,   132,   243,    -1,   103,
     246,   132,   243,    -1,   236,   246,   132,   243,    -1,   237,
     246,   132,   243,    -1,   201,   246,   111,   243,    -1,    67,
     246,   177,   243,    -1,     5,   245,   283,   244,   243,    -1,
     283,   284,    -1,   284,    -1,   285,    -1,   287,    -1,   286,
      -1,     1,   243,    -1,   101,   246,   132,   243,    -1,    39,
     246,   132,   243,    -1,    30,   246,   132,   243,    -1,    83,
     245,   289,   244,   243,    -1,   289,   290,    -1,   290,    -1,
     291,    -1,   292,    -1,     1,   243,    -1,   234,   246,   177,
     243,    -1,    -1,   293,   242,   245,   294,   244,   243,    -1,
     294,   295,    -1,   295,    -1,   296,    -1,   298,    -1,   297,
      -1,     1,   243,    -1,   101,   246,   132,   243,    -1,   241,
     246,   254,   243,    -1,   241,   246,   214,   243,    -1,    -1,
     167,   299,   246,   300,   243,    -1,   300,   247,   301,    -1,
     301,    -1,   229,    -1,   116,    -1,    49,    -1,   193,    -1,
      74,    -1,    72,    -1,   192,    -1,    -1,   116,   303,   245,
     304,   244,   243,    -1,   304,   305,    -1,   305,    -1,   306,
      -1,   307,    -1,   308,    -1,   312,    -1,   311,    -1,   309,
      -1,   310,    -1,   316,    -1,     1,   243,    -1,   101,   246,
     132,   243,    -1,   229,   246,   132,   243,    -1,   126,   246,
     132,   243,    -1,    41,   246,   177,   243,    -1,   145,   246,
     132,   243,    -1,    23,   246,   132,   243,    -1,    -1,   211,
     313,   246,   314,   243,    -1,   314,   247,   315,    -1,   315,
      -1,   184,    -1,   187,    -1,   188,    -1,   191,    -1,   192,
      -1,   196,    -1,    61,    -1,   208,    -1,   202,    -1,   204,
      -1,   212,    -1,   209,    -1,   195,    -1,   203,    -1,   206,
      -1,   197,    -1,   218,    -1,   185,    -1,   186,    -1,   200,
      -1,    -1,    45,   317,   246,   318,   243,    -1,   318,   247,
     319,    -1,   319,    -1,    57,    -1,   140,    -1,    74,    -1,
     228,    -1,   193,    -1,   213,    -1,   238,    -1,    49,    -1,
      31,    -1,   219,    -1,   138,    -1,     5,    -1,   106,    -1,
     203,    -1,   217,    -1,   120,    -1,   141,    -1,   207,    -1,
      99,    -1,    -1,    23,   321,   245,   322,   244,   243,    -1,
     322,   323,    -1,   323,    -1,   324,    -1,   334,    -1,   335,
      -1,   325,    -1,   326,    -1,   336,    -1,   327,    -1,   328,
      -1,   329,    -1,   330,    -1,   331,    -1,   332,    -1,   333,
      -1,     1,   243,    -1,   101,   246,   132,   243,    -1,   129,
     246,   252,   243,    -1,   130,   246,   252,   243,    -1,   114,
     246,   111,   243,    -1,    25,   246,   252,   243,    -1,    93,
     246,   111,   243,    -1,    88,   246,   111,   243,    -1,    90,
     246,   111,   243,    -1,    89,   246,   111,   243,    -1,   159,
     246,   254,   243,    -1,    21,   246,   111,   243,    -1,    22,
     246,   111,   243,    -1,   113,   246,   111,   243,    -1,    -1,
      82,   338,   245,   343,   244,   243,    -1,    -1,    45,   340,
     246,   341,   243,    -1,   341,   247,   342,    -1,   342,    -1,
     210,    -1,    61,    -1,   205,    -1,   343,   344,    -1,   344,
      -1,   345,    -1,   339,    -1,   349,    -1,   350,    -1,     1,
     243,    -1,    -1,   131,   246,   347,   346,   243,    -1,   347,
     247,   348,    -1,   348,    -1,   111,    -1,   111,   182,   111,
      -1,    71,   246,   132,   243,    -1,    66,   246,   132,   243,
      -1,    -1,    58,   352,   245,   353,   244,   243,    -1,   353,
     354,    -1,   354,    -1,   355,    -1,   356,    -1,   357,    -1,
     359,    -1,   363,    -1,   364,    -1,   365,    -1,   358,    -1,
       1,   243,    -1,   229,   246,   132,   243,    -1,   126,   246,
     132,   243,    -1,    23,   246,   132,   243,    -1,    41,   246,
     177,   243,    -1,    -1,    45,   360,   246,   361,   243,    -1,
     361,   247,   362,    -1,   362,    -1,   171,    -1,    42,    -1,
      75,    -1,    59,    -1,    19,    -1,   110,    -1,    52,    -1,
     153,    -1,   102,    -1,   170,   246,   132,   243,    -1,   136,
     246,   132,   243,    -1,   135,   246,   111,   243,    -1,    -1,
     152,   367,   245,   368,   244,   243,    -1,   368,   369,    -1,
     369,    -1,   370,    -1,   371,    -1,   372,    -1,     1,   243,
      -1,   134,   246,   132,   243,    -1,    20,   246,   132,   243,
      -1,   105,   246,   132,   243,    -1,   220,   245,   374,   244,
     243,    -1,   374,   375,    -1,   375,    -1,   376,    -1,     1,
      -1,   101,   246,   132,   243,    -1,    -1,   165,   378,   245,
     379,   244,   243,    -1,   379,   380,    -1,   380,    -1,   381,
      -1,   382,    -1,   383,    -1,     1,   243,    -1,   101,   246,
     132,   243,    -1,   229,   246,   132,   243,    -1,    -1,   167,
     384,   246,   385,   243,    -1,   385,   247,   386,    -1,   386,
      -1,    74,    -1,   228,    -1,   193,    -1,   213,    -1,   238,
      -1,   216,    -1,   152,    -1,   215,    -1,   200,    -1,   183,
      -1,    -1,   166,   388,   245,   389,   244,   243,    -1,   389,
     390,    -1,   390,    -1,   391,    -1,   392,    -1,     1,   243,
      -1,   101,   246,   132,   243,    -1,    -1,   167,   393,   246,
     394,   243,    -1,   394,   247,   395,    -1,   395,    -1,    74,
      -1,   228,    -1,   193,    -1,   213,    -1,   238,    -1,   216,
      -1,   152,    -1,   215,    -1,   200,    -1,   183,    -1,    -1,
      24,   397,   245,   398,   244,   243,    -1,   398,   399,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,   406,    -1,   405,    -1,   415,    -1,   407,    -1,
     412,    -1,   413,    -1,   414,    -1,   411,    -1,     1,   243,
      -1,   101,   246,   132,   243,    -1,    66,   246,   132,   243,
      -1,   236,   246,   132,   243,    -1,   160,   246,   132,   243,
      -1,     3,   246,   132,   243,    -1,   131,   246,   111,   243,
      -1,     6,   246,   198,   243,    -1,     6,   246,   199,   243,
      -1,    -1,    45,   408,   246,   409,   243,    -1,   409,   247,
     410,    -1,   410,    -1,    10,    -1,    12,    -1,   223,    -1,
     210,    -1,    41,   246,   177,   243,    -1,    68,   246,   132,
     243,    -1,    80,   246,   132,   243,    -1,    23,   246,   132,
     243,    -1,   189,   246,   132,   243,    -1,    -1,    72,   417,
     245,   422,   244,   243,    -1,    -1,   167,   419,   246,   420,
     243,    -1,   420,   247,   421,    -1,   421,    -1,   137,    -1,
     422,   423,    -1,   423,    -1,   424,    -1,   425,    -1,   418,
      -1,     1,    -1,   229,   246,   132,   243,    -1,   134,   246,
     132,   243,    -1,    -1,    29,   427,   245,   428,   244,   243,
      -1,   428,   429,    -1,   429,    -1,   430,    -1,   431,    -1,
       1,    -1,    71,   246,   132,   243,    -1,   134,   246,   132,
     243,    -1,    43,   245,   433,   244,   243,    -1,   433,   434,
      -1,   434,    -1,   435,    -1,     1,    -1,    71,   246,   132,
     243,    -1,    -1,    47,   437,   245,   442,   244,   243,    -1,
      -1,   167,   439,   246,   440,   243,    -1,   440,   247,   441,
      -1,   441,    -1,   137,    -1,   442,   443,    -1,   443,    -1,
     444,    -1,   445,    -1,   438,    -1,     1,    -1,   101,   246,
     132,   243,    -1,   134,   246,   132,   243,    -1,    48,   245,
     447,   244,   243,    -1,   447,   448,    -1,   448,    -1,   459,
      -1,   460,    -1,   462,    -1,   463,    -1,   464,    -1,   465,
      -1,   466,    -1,   467,    -1,   468,    -1,   469,    -1,   458,
      -1,   471,    -1,   472,    -1,   473,    -1,   474,    -1,   489,
      -1,   476,    -1,   478,    -1,   480,    -1,   479,    -1,   483,
      -1,   477,    -1,   484,    -1,   485,    -1,   486,    -1,   487,
      -1,   488,    -1,   501,    -1,   490,    -1,   491,    -1,   492,
      -1,   497,    -1,   481,    -1,   482,    -1,   507,    -1,   505,
      -1,   506,    -1,   461,    -1,   508,    -1,   496,    -1,   470,
      -1,   494,    -1,   495,    -1,   457,    -1,   450,    -1,   451,
      -1,   452,    -1,   453,    -1,   454,    -1,   455,    -1,   456,
      -1,   475,    -1,   449,    -1,   493,    -1,     1,    -1,    95,
     246,   111,   243,    -1,    51,   246,   177,   243,    -1,    50,
     246,   252,   243,    -1,    54,   246,   252,   243,    -1,    55,
     246,   111,   243,    -1,    56,   246,   111,   243,    -1,   235,
     246,   177,   243,    -1,   139,   246,   252,   243,    -1,   164,
     246,   177,   243,    -1,    73,   246,   252,   243,    -1,    65,
     246,   177,   243,    -1,    69,   246,   177,   243,    -1,    35,
     246,   177,   243,    -1,    44,   246,   177,   243,    -1,     8,
     246,   177,   243,    -1,    92,   246,   252,   243,    -1,    91,
     246,   111,   243,    -1,    84,   246,   111,   243,    -1,     9,
     246,   252,   243,    -1,   181,   246,   252,   243,    -1,   180,
     246,   252,   243,    -1,    60,   246,   111,   243,    -1,    77,
     246,   177,   243,    -1,    76,   246,   132,   243,    -1,    70,
     246,   177,   243,    -1,   240,   246,   177,   243,    -1,   172,
     246,   177,   243,    -1,   175,   246,   177,   243,    -1,   176,
     246,   177,   243,    -1,   174,   246,   177,   243,    -1,   174,
     246,   178,   243,    -1,   173,   246,   177,   243,    -1,   173,
     246,   178,   243,    -1,   124,   246,   252,   243,    -1,    18,
     246,   252,   243,    -1,   117,   246,   177,   243,    -1,   125,
     246,   252,   243,    -1,   168,   246,   177,   243,    -1,   109,
     246,   177,   243,    -1,   224,   246,   177,   243,    -1,   119,
     246,   177,   243,    -1,    96,   246,   132,   243,    -1,    36,
     246,   111,   243,    -1,    94,   246,   111,   243,    -1,   230,
     246,   177,   243,    -1,    38,   246,   132,   243,    -1,   221,
     246,   132,   243,    -1,   128,   246,   177,   243,    -1,    32,
     246,   177,   243,    -1,   222,   246,   252,   243,    -1,    -1,
     121,   498,   246,   499,   243,    -1,   499,   247,   500,    -1,
     500,    -1,   184,    -1,   187,    -1,   188,    -1,   191,    -1,
     192,    -1,   196,    -1,    61,    -1,   208,    -1,   202,    -1,
     204,    -1,   212,    -1,   209,    -1,   195,    -1,   203,    -1,
     206,    -1,   197,    -1,   218,    -1,   185,    -1,   186,    -1,
     200,    -1,    -1,   118,   502,   246,   503,   243,    -1,   503,
     247,   504,    -1,   504,    -1,   184,    -1,   187,    -1,   188,
      -1,   191,    -1,   192,    -1,   196,    -1,   208,    -1,    61,
      -1,   202,    -1,   204,    -1,   212,    -1,   209,    -1,   195,
      -1,   203,    -1,   206,    -1,   197,    -1,   218,    -1,   185,
      -1,   186,    -1,   200,    -1,    97,   246,   111,   243,    -1,
      98,   246,   111,   243,    -1,    26,   246,   111,   243,    -1,
     190,   246,   254,   243,    -1,    20,   245,   510,   244,   243,
      -1,   510,   511,    -1,   511,    -1,   514,    -1,   515,    -1,
     516,    -1,   522,    -1,   517,    -1,   518,    -1,   519,    -1,
     520,    -1,   521,    -1,   523,    -1,   524,    -1,   525,    -1,
     513,    -1,   526,    -1,   527,    -1,   528,    -1,   512,    -1,
       1,    -1,    33,   246,   177,   243,    -1,   142,   246,   177,
     243,    -1,   231,   246,   177,   243,    -1,   232,   246,   177,
     243,    -1,   233,   246,   177,   243,    -1,    78,   246,   252,
     243,    -1,    79,   246,   252,   243,    -1,    87,   246,   111,
     243,    -1,    86,   246,   111,   243,    -1,   133,   246,   177,
     243,    -1,    85,   246,   111,   243,    -1,    28,   246,   111,
     243,    -1,    27,   246,   111,   243,    -1,   107,   246,   177,
     243,    -1,   108,   246,   177,   243,    -1,   122,   246,   111,
     243,    -1,   123,   246,   252,   243,    -1,   161,   245,   530,
     244,   243,    -1,   530,   531,    -1,   531,    -1,   532,    -1,
     533,    -1,   535,    -1,   537,    -1,   536,    -1,   534,    -1,
     538,    -1,     1,    -1,    46,   246,   177,   243,    -1,    64,
     246,   177,   243,    -1,    62,   246,   132,   243,    -1,    81,
     246,   252,   243,    -1,    61,   246,   177,   243,    -1,    34,
     246,   177,   243,    -1,    63,   246,   177,   243,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   356,   356,   357,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   385,   385,   386,   390,
     394,   398,   402,   406,   412,   412,   413,   414,   415,   416,
     423,   426,   426,   427,   427,   427,   429,   435,   442,   444,
     444,   445,   445,   446,   446,   447,   447,   448,   448,   449,
     449,   450,   450,   451,   451,   452,   453,   456,   457,   459,
     459,   460,   466,   474,   474,   475,   481,   489,   528,   587,
     615,   623,   638,   653,   662,   676,   685,   713,   743,   766,
     775,   777,   777,   778,   778,   779,   779,   781,   790,   799,
     811,   812,   812,   814,   814,   815,   817,   824,   824,   834,
     835,   837,   837,   838,   838,   840,   845,   848,   854,   853,
     859,   859,   860,   864,   868,   872,   876,   880,   884,   895,
     894,   992,   992,   993,   993,   993,   994,   994,   994,   995,
     995,   995,   997,  1006,  1043,  1055,  1066,  1108,  1118,  1117,
    1123,  1123,  1124,  1128,  1132,  1136,  1140,  1144,  1148,  1152,
    1156,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,  1192,
    1196,  1200,  1207,  1206,  1212,  1212,  1213,  1217,  1221,  1225,
    1229,  1233,  1237,  1241,  1245,  1249,  1253,  1257,  1261,  1265,
    1269,  1273,  1277,  1281,  1285,  1296,  1295,  1345,  1345,  1346,
    1347,  1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,
    1356,  1357,  1358,  1360,  1369,  1375,  1381,  1387,  1393,  1399,
    1405,  1411,  1417,  1423,  1429,  1435,  1445,  1444,  1461,  1460,
    1465,  1465,  1466,  1470,  1474,  1482,  1482,  1483,  1483,  1483,
    1483,  1483,  1485,  1485,  1487,  1487,  1489,  1503,  1523,  1532,
    1545,  1544,  1613,  1613,  1614,  1614,  1614,  1614,  1615,  1615,
    1615,  1616,  1616,  1618,  1653,  1666,  1675,  1687,  1686,  1690,
    1690,  1691,  1695,  1699,  1703,  1707,  1711,  1715,  1719,  1723,
    1730,  1749,  1759,  1773,  1772,  1788,  1788,  1789,  1789,  1789,
    1789,  1791,  1800,  1815,  1828,  1830,  1830,  1831,  1831,  1833,
    1849,  1848,  1864,  1864,  1865,  1865,  1865,  1865,  1867,  1876,
    1899,  1898,  1904,  1904,  1905,  1909,  1913,  1917,  1921,  1925,
    1929,  1933,  1937,  1941,  1951,  1950,  1967,  1967,  1968,  1968,
    1968,  1970,  1977,  1976,  1982,  1982,  1983,  1987,  1991,  1995,
    1999,  2003,  2007,  2011,  2015,  2019,  2029,  2028,  2079,  2079,
    2080,  2080,  2080,  2081,  2081,  2082,  2082,  2082,  2083,  2083,
    2083,  2084,  2084,  2085,  2087,  2096,  2105,  2131,  2149,  2167,
    2173,  2177,  2186,  2185,  2189,  2189,  2190,  2194,  2198,  2202,
    2208,  2219,  2230,  2241,  2250,  2269,  2268,  2334,  2333,  2337,
    2337,  2338,  2344,  2344,  2345,  2345,  2345,  2345,  2347,  2366,
    2376,  2375,  2400,  2400,  2401,  2401,  2401,  2403,  2409,  2418,
    2420,  2420,  2421,  2421,  2423,  2442,  2441,  2489,  2488,  2492,
    2492,  2493,  2499,  2499,  2500,  2500,  2500,  2500,  2502,  2508,
    2517,  2520,  2520,  2521,  2521,  2522,  2522,  2523,  2523,  2524,
    2524,  2525,  2525,  2526,  2526,  2527,  2527,  2528,  2528,  2529,
    2529,  2530,  2530,  2531,  2531,  2532,  2532,  2533,  2533,  2534,
    2535,  2535,  2536,  2536,  2537,  2537,  2538,  2538,  2539,  2539,
    2540,  2541,  2542,  2542,  2543,  2544,  2545,  2545,  2546,  2546,
    2547,  2548,  2548,  2549,  2549,  2550,  2550,  2551,  2554,  2559,
    2565,  2571,  2577,  2582,  2587,  2592,  2597,  2602,  2607,  2612,
    2617,  2622,  2627,  2632,  2637,  2642,  2647,  2652,  2657,  2663,
    2674,  2679,  2688,  2693,  2698,  2703,  2708,  2713,  2716,  2721,
    2724,  2729,  2734,  2739,  2744,  2749,  2754,  2759,  2764,  2769,
    2780,  2785,  2790,  2795,  2804,  2813,  2818,  2823,  2829,  2828,
    2833,  2833,  2834,  2837,  2840,  2843,  2846,  2849,  2852,  2855,
    2858,  2861,  2864,  2867,  2870,  2873,  2876,  2879,  2882,  2885,
    2888,  2891,  2897,  2896,  2901,  2901,  2902,  2905,  2908,  2911,
    2914,  2917,  2920,  2923,  2926,  2929,  2932,  2935,  2938,  2941,
    2944,  2947,  2950,  2953,  2956,  2959,  2964,  2969,  2974,  2979,
    2988,  2991,  2991,  2992,  2993,  2993,  2993,  2994,  2994,  2995,
    2995,  2996,  2996,  2997,  2998,  2998,  2999,  3000,  3000,  3001,
    3001,  3003,  3008,  3013,  3018,  3023,  3028,  3033,  3038,  3043,
    3048,  3053,  3058,  3063,  3068,  3073,  3078,  3083,  3091,  3094,
    3094,  3095,  3095,  3096,  3097,  3098,  3098,  3099,  3100,  3102,
    3108,  3114,  3123,  3137,  3143,  3149
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
  "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", "DISABLE_REMOTE_COMMANDS",
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE",
  "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_TIME",
  "GLINE_REQUEST_DURATION", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_REASON", "KLINE_WITH_REASON", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_WATCH",
  "MESSAGE_LOCALE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULES", "NAME", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NICK_CHANGES", "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_IDENT",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "NUMBER_PER_IP_GLOBAL", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON",
  "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH", "TREJECT_HOLD_TIME",
  "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS", "RESTRICTED",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVER", "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL",
  "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD",
  "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT",
  "USE_INVEX", "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST",
  "VHOST6", "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'",
  "'}'", "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
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
  "serverhide_disable_hidden", "serverhide_hide_server_ips", YY_NULL
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
     495,   496,   497,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   248,   249,   249,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   252,
     252,   252,   252,   252,   253,   253,   254,   254,   254,   254,
     255,   256,   256,   257,   257,   257,   258,   259,   260,   261,
     261,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   283,   284,   284,   284,   284,   285,   286,   287,
     288,   289,   289,   290,   290,   290,   291,   293,   292,   294,
     294,   295,   295,   295,   295,   296,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   303,
     302,   304,   304,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   306,   307,   308,   309,   310,   311,   313,   312,
     314,   314,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   317,   316,   318,   318,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   321,   320,   322,   322,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   338,   337,   340,   339,
     341,   341,   342,   342,   342,   343,   343,   344,   344,   344,
     344,   344,   346,   345,   347,   347,   348,   348,   349,   350,
     352,   351,   353,   353,   354,   354,   354,   354,   354,   354,
     354,   354,   354,   355,   356,   357,   358,   360,   359,   361,
     361,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     363,   364,   365,   367,   366,   368,   368,   369,   369,   369,
     369,   370,   371,   372,   373,   374,   374,   375,   375,   376,
     378,   377,   379,   379,   380,   380,   380,   380,   381,   382,
     384,   383,   385,   385,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   388,   387,   389,   389,   390,   390,
     390,   391,   393,   392,   394,   394,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   397,   396,   398,   398,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   400,   401,   402,   403,   404,   405,
     406,   406,   408,   407,   409,   409,   410,   410,   410,   410,
     411,   412,   413,   414,   415,   417,   416,   419,   418,   420,
     420,   421,   422,   422,   423,   423,   423,   423,   424,   425,
     427,   426,   428,   428,   429,   429,   429,   430,   431,   432,
     433,   433,   434,   434,   435,   437,   436,   439,   438,   440,
     440,   441,   442,   442,   443,   443,   443,   443,   444,   445,
     446,   447,   447,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   478,   479,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   498,   497,
     499,   499,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   502,   501,   503,   503,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   505,   506,   507,   508,
     509,   510,   510,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     530,   531,   531,   531,   531,   531,   531,   531,   531,   532,
     533,   534,   535,   536,   537,   538
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4
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
       0,     0,   638,     0,     0,     0,     0,     0,     0,     0,
       0,   630,   631,   632,   636,   633,   635,   634,   637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    63,    64,    62,
      59,    58,    65,    51,    61,    54,    55,    56,    52,    60,
      57,    53,     0,     0,   298,     0,     0,   296,   297,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   591,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   202,   203,   205,   206,   207,   208,   209,   210,   211,
     200,   201,   204,     0,     0,     0,     0,     0,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   349,   350,
     351,   352,   353,   354,   356,   355,   358,   362,   359,   360,
     361,   357,   406,     0,     0,     0,   403,   404,   405,     0,
       0,   410,   427,     0,     0,   417,   426,     0,   423,   424,
     425,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   431,     0,     0,     0,
     267,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,   261,   257,   258,   259,   260,   397,     0,   387,     0,
     396,     0,   393,   394,   395,     0,   228,     0,     0,     0,
     238,     0,   236,   237,   239,   240,   105,     0,     0,   101,
       0,    45,     0,     0,     0,    41,     0,     0,     0,   172,
       0,     0,     0,   148,     0,     0,   132,   133,   134,   135,
     138,   139,   137,   136,   140,     0,     0,     0,     0,     0,
     286,   287,   288,   289,     0,     0,     0,     0,     0,     0,
       0,     0,   629,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   310,     0,     0,   303,   304,   305,   306,
       0,     0,   332,     0,   327,   328,   329,     0,     0,   295,
       0,     0,     0,    90,     0,     0,     0,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,   402,     0,
     409,     0,     0,     0,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,   430,   262,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   252,     0,     0,     0,     0,   392,
     241,     0,     0,     0,     0,     0,   235,     0,   100,     0,
       0,     0,    40,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   290,     0,     0,     0,     0,   285,
       0,     0,     0,     0,     0,     0,     0,   628,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72,     0,    70,
      75,    76,     0,    74,     0,     0,     0,     0,     0,    48,
     307,     0,     0,     0,     0,   302,   330,     0,     0,     0,
     326,     0,   294,    99,    98,    97,   623,   622,   611,    26,
      26,    26,    26,    26,    28,    27,   616,   617,   621,   619,
     618,   624,   625,   626,   627,   620,   612,   613,   614,   615,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,     0,
       0,   401,   414,     0,     0,     0,   416,   502,   506,   522,
     588,   536,   500,   530,   533,   501,   490,   489,   491,   492,
     493,   509,   498,   499,   512,   497,   511,   510,   505,   504,
     503,   531,   488,   529,   586,   587,   526,   523,   573,   566,
     583,   584,   567,   568,   569,   570,   578,   571,   581,   585,
     574,   579,   575,   580,   572,   577,   576,   582,     0,   565,
     528,   548,   542,   559,   560,   543,   544,   545,   546,   554,
     547,   557,   561,   550,   555,   551,   556,   549,   553,   552,
     558,     0,   541,   521,   524,   535,   495,   496,   525,   514,
     519,   520,   517,   518,   515,   516,   508,   507,    34,    34,
      34,    36,    35,   589,   534,   537,   527,   532,   494,   513,
       0,     0,     0,     0,     0,     0,     0,     0,   251,     0,
       0,     0,   386,     0,     0,     0,   246,   242,   245,   227,
     106,     0,     0,   118,     0,     0,   110,   111,   113,   112,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,   284,   644,   639,   643,   641,   645,
     640,   642,    83,    89,    81,    85,    84,    78,    77,    79,
      67,     0,    68,     0,    82,    80,    88,    86,    87,     0,
       0,     0,   301,     0,     0,   325,   299,    29,    30,    31,
      32,    33,   223,   224,   217,   219,   221,   220,   218,   213,
     225,   216,   214,   215,   222,   368,   370,   371,   383,   380,
     376,   377,   379,   378,     0,   375,   365,   381,   382,   364,
     369,   367,   384,   366,   407,   408,   428,   429,   421,     0,
     420,   563,     0,   539,     0,    37,    38,    39,   265,   266,
     275,   272,   277,   274,   273,   279,   276,   278,   271,     0,
     270,   264,   282,   281,   280,   263,   399,   391,     0,   390,
     398,   233,   234,   232,     0,   231,   249,   248,     0,     0,
       0,   114,     0,     0,     0,     0,   109,   147,   145,   187,
     184,   183,   176,   178,   194,   188,   191,   186,   177,   192,
     180,   189,   193,   181,   190,   185,   179,   182,     0,   175,
     142,   144,   146,   158,   152,   169,   170,   153,   154,   155,
     156,   164,   157,   167,   171,   160,   165,   161,   166,   159,
     163,   162,   168,     0,   151,   143,   292,   293,   291,    69,
      73,   308,   314,   320,   323,   316,   322,   317,   321,   319,
     315,   318,     0,   313,   309,   331,   336,   342,   345,   338,
     344,   339,   343,   341,   337,   340,     0,   335,   373,     0,
     418,     0,   564,   540,   268,     0,   388,     0,   229,     0,
     247,   244,   243,     0,     0,     0,     0,   108,   173,     0,
     149,     0,   311,     0,   333,     0,   374,   419,   269,   389,
     230,   115,   124,   127,   126,   123,   128,   125,   122,     0,
     121,   117,   116,   174,   150,   312,   334,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   814,   815,   961,   962,    25,   246,   247,
     248,   249,    26,   285,   286,   287,   288,   778,   779,   782,
     783,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,    27,    71,    72,    73,    74,    75,
      28,   238,   239,   240,   241,   242,   995,   996,   997,   998,
     999,  1133,  1259,  1260,    29,    60,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   750,  1183,  1184,   534,   746,
    1158,  1159,    30,    49,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,    31,
      57,   500,   731,  1124,  1125,   501,   502,   503,  1130,   987,
     988,   504,   505,    32,    55,   476,   477,   478,   479,   480,
     481,   482,   717,  1109,  1110,   483,   484,   485,    33,    61,
     539,   540,   541,   542,   543,    34,   306,   307,   308,    35,
      64,   575,   576,   577,   578,   579,   792,  1202,  1203,    36,
      65,   583,   584,   585,   586,   798,  1216,  1217,    37,    50,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     634,  1074,  1075,   387,   388,   389,   390,   391,    38,    56,
     490,   726,  1118,  1119,   491,   492,   493,   494,    39,    51,
     395,   396,   397,   398,    40,   118,   119,   120,    41,    53,
     406,   653,  1089,  1090,   407,   408,   409,   410,    42,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     444,   941,   942,   228,   442,   918,   919,   229,   230,   231,
     232,    43,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    44,   260,   261,   262,   263,   264,   265,   266,   267,
     268
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -584
static const yytype_int16 yypact[] =
{
    -584,   645,  -584,  -213,  -229,  -220,  -584,  -584,  -584,  -212,
    -584,  -199,  -584,  -584,  -584,  -192,  -187,  -584,  -584,  -171,
    -165,  -584,  -584,  -163,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,   311,   549,  -156,
    -151,  -148,    16,  -134,   379,  -129,  -124,  -111,    10,    75,
    -103,   -93,   696,   424,   -87,   -82,     3,  -205,  -169,   -71,
     -63,     5,  -584,  -584,  -584,  -584,  -584,   -56,   -38,   -35,
     -24,   -17,    -3,    -1,    40,    46,    52,    77,    88,    97,
     103,   112,   121,   123,   209,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,   715,   444,     7,  -584,   132,    22,  -584,
    -584,   219,  -584,   133,   135,   136,   137,   139,   143,   144,
     149,   150,   152,   158,   160,   161,   163,   164,   167,   172,
     173,   174,   176,   180,   181,   182,   185,   186,   190,   191,
     192,   200,   211,   212,  -584,   214,  -584,   218,   220,   222,
     226,   232,   235,   236,   237,   238,   240,   244,   246,   247,
     248,   249,   253,   255,   259,   260,   262,   100,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,   598,    48,    36,    41,   263,    49,  -584,
    -584,  -584,    64,    68,   265,   268,    26,  -584,  -584,  -584,
     420,    28,  -584,   269,   271,   273,   276,   277,   280,   283,
       9,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   151,
     284,   286,   288,   289,   290,   291,   292,   294,   295,   296,
     298,   302,   303,   312,   315,   156,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,   170,    13,  -584,   316,    14,  -584,  -584,  -584,
     270,   330,   401,   314,  -584,   305,   452,   387,   455,   455,
     456,   463,   467,   402,   403,   472,   455,   407,   408,   409,
     412,   413,   348,  -584,   350,   346,   351,   352,   359,   360,
     361,   362,   364,   365,   369,   370,   371,   372,   225,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,   353,   378,   380,   383,   386,  -584,   391,
     392,   394,   395,   396,   398,   405,   406,    18,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,   416,   417,    53,  -584,  -584,  -584,   462,
     404,  -584,  -584,   418,   421,  -584,  -584,    65,  -584,  -584,
    -584,   471,   455,   455,   484,   476,   477,   544,   526,   489,
     455,   493,   455,   548,   562,   566,   501,   502,   504,   455,
     551,   507,   575,   576,   455,   583,   585,   568,   587,   591,
     527,   528,   460,   532,   465,   455,   455,   535,   455,   536,
     537,   541,  -110,   -86,   542,   545,   455,   455,   604,   593,
     455,   546,   552,   555,   558,   483,  -584,   498,   497,   506,
    -584,   509,   516,   517,   518,   519,    11,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,   521,  -584,   524,
    -584,    38,  -584,  -584,  -584,   505,  -584,   533,   539,   540,
    -584,    17,  -584,  -584,  -584,  -584,  -584,   567,   530,  -584,
     529,  -584,   615,   618,   547,  -584,   550,   543,   553,  -584,
     554,   563,   569,  -584,   571,    19,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,   559,   572,   573,   574,    25,
    -584,  -584,  -584,  -584,   601,   606,   610,   656,   614,   619,
     455,   570,  -584,  -584,   660,   621,   663,   669,   680,   682,
     689,   690,   -51,   128,   691,   692,   724,   693,   694,   596,
    -584,   597,   590,  -584,   605,    12,  -584,  -584,  -584,  -584,
     613,   607,  -584,    21,  -584,  -584,  -584,   725,   616,  -584,
     617,   620,   623,  -584,   624,   625,   632,   216,   635,   636,
     640,   641,   643,   647,   649,   652,   653,   661,   664,   665,
     670,   672,  -584,  -584,   736,   750,   455,   751,   801,   808,
     810,   792,   814,   816,   455,   455,   604,   686,  -584,  -584,
     796,   148,   798,   754,   687,   802,   803,   804,   805,   827,
     807,   809,   811,   697,  -584,   812,   813,   699,  -584,   703,
    -584,   815,   817,   702,   707,  -584,   708,   709,   710,   711,
     712,   713,   716,   717,   718,   719,   720,   721,   722,   723,
     726,   727,   728,   729,   730,   731,   732,   733,   734,   735,
     737,   738,   739,   740,   741,   742,   743,   646,   744,   685,
     745,   746,   747,   748,   749,   752,   753,   755,   756,   757,
     758,   759,   760,   761,   762,   199,   763,   764,   765,   766,
     767,   768,   769,  -584,  -584,   825,   781,   770,   835,   857,
     847,   861,   862,   771,  -584,   865,   772,   881,   774,  -584,
    -584,   773,   883,   888,   910,   779,  -584,   780,  -584,    60,
     782,   783,  -584,  -584,   892,   850,   784,   896,   897,   899,
     786,   901,   791,  -584,  -584,   903,   904,   905,   795,  -584,
     797,   799,   800,   806,   818,   819,   820,  -584,   821,   822,
     823,   824,   826,   828,   829,   830,  -584,  -584,  -215,  -584,
    -584,  -584,  -207,  -584,   831,   832,   833,   834,   836,  -584,
    -584,   907,   837,   909,   838,  -584,  -584,   912,   839,   841,
    -584,   843,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   455,
     455,   455,   455,   455,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
     844,   845,   846,   848,   849,   851,   852,   853,   854,   855,
     856,   858,   859,  -584,   860,   863,   864,   866,   867,    -7,
     868,   869,   870,   871,   872,   873,   874,   875,  -584,   876,
     877,  -584,  -584,   878,   879,   908,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -196,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -178,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   604,   604,
     604,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
     880,   882,   349,   884,   885,   886,   887,   889,  -584,   890,
     911,   891,  -584,    -4,   893,   894,   898,   895,  -584,  -584,
    -584,   900,   902,  -584,   906,    84,  -584,  -584,  -584,  -584,
    -584,  -584,   913,   914,   482,   915,   916,   917,   714,   918,
    -584,   919,   920,   921,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,   -51,  -584,   128,  -584,  -584,  -584,  -584,  -584,   922,
     538,   923,  -584,   924,   556,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -168,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -120,
    -584,  -584,   646,  -584,   685,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   -54,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   -43,  -584,
    -584,  -584,  -584,  -584,   -12,  -584,  -584,  -584,   935,   910,
     925,  -584,   926,   927,  -104,   928,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,    -9,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,    42,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,    86,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,   105,  -584,  -584,    -7,
    -584,   908,  -584,  -584,  -584,   349,  -584,   911,  -584,    -4,
    -584,  -584,  -584,   929,   287,   931,   932,  -584,  -584,   482,
    -584,   714,  -584,   538,  -584,   556,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   113,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,   287,  -584
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -584,  -584,  -584,  -447,  -317,  -583,  -458,  -584,  -584,   930,
    -584,  -584,  -584,  -584,   775,  -584,  -584,  -584,    20,  -584,
      23,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,   976,  -584,  -584,  -584,
    -584,  -584,   840,  -584,  -584,  -584,  -584,    55,  -584,  -584,
    -584,  -584,  -584,  -216,  -584,  -584,  -584,   534,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -188,  -584,  -584,
    -584,  -185,  -584,  -584,  -584,   776,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -174,  -584,   581,  -584,  -584,  -584,
     -72,  -584,  -584,  -584,  -584,  -584,   592,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -155,  -584,  -584,  -584,  -584,  -584,
    -584,   561,  -584,  -584,  -584,  -584,  -584,   787,  -584,  -584,
    -584,  -584,   515,  -584,  -584,  -584,  -584,  -584,  -139,  -584,
    -584,  -584,   522,  -584,  -584,  -584,  -584,  -137,  -584,  -584,
    -584,   777,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,   -88,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -101,  -584,   644,  -584,  -584,  -584,  -584,
    -584,   785,  -584,  -584,  -584,  -584,  1020,  -584,  -584,  -584,
    -584,  -584,  -584,   -81,  -584,   778,  -584,  -584,  -584,  -584,
     962,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,    47,  -584,  -584,  -584,    54,  -584,  -584,  -584,
    -584,  -584,  -584,  1050,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,  -584,
    -584,  -584,  -584,   933,  -584,  -584,  -584,  -584,  -584,  -584,
    -584
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     706,   598,   599,  1070,   304,  1071,    67,   705,   392,   606,
     252,   236,   467,   571,   580,   304,    47,   116,   495,   363,
     516,   364,   580,   116,   365,    48,   535,   243,  1030,   535,
      45,    46,  1031,    52,   468,    68,  1032,   495,   309,   486,
    1033,   366,   517,   253,    69,   536,    54,  1091,   536,   486,
     236,  1092,   469,    58,   392,   254,   470,  1121,    59,   367,
     518,   991,   496,   368,   519,  1093,   402,   697,   698,  1094,
     255,   256,   257,   258,    62,  1218,   243,   310,   393,  1219,
      63,   496,    66,   497,   369,   991,   370,   117,   498,   113,
     259,   699,   700,   117,   114,   657,   658,   115,   371,   776,
     777,   122,   497,   665,   305,   667,    70,   498,   123,   124,
    1235,   121,   674,   572,   581,   305,   233,   679,   125,   372,
     520,   234,   581,  1220,   393,   244,   126,  1221,   690,   691,
     537,   693,   127,   537,   235,   128,   129,   471,   130,   703,
     704,   394,   250,   708,   131,   521,   472,   473,   499,   373,
     132,   133,   251,   245,   134,   135,   136,   269,   302,   538,
     137,   992,   538,   303,   522,   138,   403,   499,   842,   139,
     140,   571,   487,   141,   244,   311,   142,   143,   374,   573,
     582,   474,   487,   312,   144,   992,   270,   394,   582,  1224,
     315,   145,   146,  1225,   147,   148,   149,   150,   151,   404,
    1226,  1122,   245,  1072,  1227,   488,  1123,   375,   316,   152,
      76,   317,   958,   959,   960,   488,  1073,   153,   154,   155,
     402,   156,   318,   271,   157,   158,   334,   993,   159,   319,
     523,  1228,   405,   766,  1238,  1229,    77,    78,  1239,   160,
     475,   574,    79,   320,   237,   321,   335,   336,   524,   313,
     337,   993,  -107,   551,   376,   723,   794,   272,   588,   273,
     274,   735,   643,   752,   161,   799,   400,   489,   162,   758,
     514,   572,   163,   164,   165,   166,   167,   489,   780,   781,
     168,   169,   728,   237,   506,  1240,   322,    80,    81,  1241,
     170,  -107,   323,   508,    82,    83,    84,   647,   324,   832,
     275,   994,   276,   277,   278,   279,   510,   840,   841,   654,
     705,   511,    67,   338,   339,   340,    85,    86,   341,   280,
     403,   171,   172,   325,   173,   994,   342,   597,  1135,  1242,
     174,    87,    88,  1243,   326,   175,  1252,   573,   343,   344,
     176,    68,    89,   327,   465,   281,   845,   846,  1244,   328,
      69,    90,  1245,   404,   345,   346,  1267,   282,   329,  1253,
    1268,  1254,  1047,  1048,  1049,  1050,  1051,   330,  1100,   331,
     809,   810,   811,   812,   813,  1095,  1096,  1097,   399,   411,
     122,   412,   413,   414,   347,   415,   405,   123,   124,   416,
     417,  1101,   283,   284,   553,   418,   419,   125,   420,   574,
     569,  1102,   590,  1255,   421,   126,   422,   423,  1103,   424,
     425,   127,    70,   426,   128,   129,   594,   130,   427,   428,
     429,   516,   430,   131,  1104,   269,   431,   432,   433,   132,
     133,   434,   435,   134,   135,   136,   436,   437,   438,   137,
      91,    92,    93,   517,   138,   363,   439,   364,   139,   140,
     365,  1105,   141,   332,   270,   142,   143,   440,   441,  1106,
     443,   518,   591,   144,   445,   519,   446,   366,   447,   627,
     145,   146,   448,   147,   148,   149,   150,   151,   449,  1256,
    1257,   450,   451,   452,   453,   367,   454,  1139,   152,   368,
     455,   271,   456,   457,   458,   459,   153,   154,   155,   460,
     156,   461,  1107,   157,   158,   462,   463,   159,   464,   507,
     369,   512,   370,  1140,   513,   544,  1258,   545,   160,   546,
    1108,   520,   547,   548,   371,   272,   549,   273,   274,   550,
     554,  1141,   555,   592,   556,   557,   558,   559,   560,  1142,
     561,   562,   563,   161,   564,   372,   521,   162,   565,   566,
      76,   163,   164,   165,   166,   167,  1143,   593,   567,   168,
     169,   568,   587,   595,   596,   522,   597,   600,   275,   170,
     276,   277,   278,   279,   601,   373,    77,    78,   602,   603,
     604,  1144,    79,   605,   607,   608,   609,   280,  1145,   610,
     611,   612,   614,   613,   649,   659,   629,   615,   616,   467,
     171,   172,  1146,   173,   374,   617,   618,   619,   620,   174,
     621,   622,  1192,   281,   175,   623,   624,   625,   626,   176,
    1147,   468,  1148,  1149,   630,   282,   631,    80,    81,   632,
    1206,   523,   633,   375,    82,    83,    84,   635,   636,   469,
     637,   638,   639,   470,   640,     2,     3,   650,   656,   524,
       4,   641,   642,   660,   661,   662,    85,    86,   663,   668,
     283,   284,   645,   646,   651,     5,   664,   652,     6,     7,
     666,    87,    88,   669,     8,  1150,  1236,   670,   671,   672,
     376,   673,    89,   675,   676,  1151,   677,   678,     9,  1152,
    1193,    90,    10,    11,   680,  1153,   681,   252,   683,  1154,
     682,  1155,   684,    12,   685,   686,   687,   898,  1207,   688,
    1156,   689,   692,   694,   695,   705,   334,    13,   696,   701,
    1157,  1194,   702,   709,   471,   707,   713,    14,    15,   710,
     253,  1195,   711,   472,   473,   712,   335,   336,  1196,  1208,
     337,   714,   254,   715,   737,    16,   921,   740,   730,  1209,
     741,  1197,   716,  1198,  1199,   718,  1210,   255,   256,   257,
     258,    17,   719,   720,   721,   722,  1200,   725,   474,  1211,
     727,  1212,  1213,   738,   739,  1163,  1201,   259,   760,   732,
      91,    92,    93,   761,  1214,   733,   734,   762,   763,   744,
     742,   764,   768,   743,  1215,   770,   765,    18,   769,   745,
     747,   771,   754,   338,   339,   340,    19,    20,   341,   748,
      21,    22,   772,   767,   773,   749,   342,   751,   755,   756,
     757,   774,   775,   784,   785,   787,   788,   475,   343,   344,
     899,   900,   901,   902,   903,   786,   791,   904,   905,   789,
     790,   906,   907,   908,   345,   346,   909,   830,   910,   911,
     912,   793,   913,   797,   914,   915,   796,   801,   916,   802,
     803,   831,   833,   804,   917,    23,   805,   806,   807,   922,
     923,   924,   925,   926,   347,   808,   927,   928,   816,   817,
     929,   930,   931,   818,   819,   932,   820,   933,   934,   935,
     821,   936,   822,   937,   938,   823,   824,   939,  1164,  1165,
    1166,  1167,  1168,   940,   825,  1169,  1170,   826,   827,  1171,
    1172,  1173,   834,   828,  1174,   829,  1175,  1176,  1177,   835,
    1178,   836,  1179,  1180,   837,   838,  1181,   839,   844,   843,
     847,   848,  1182,   849,   850,   851,   852,   853,   854,   855,
     858,   856,   861,   857,   859,   860,   862,   863,   865,   864,
     866,   867,   868,   869,   870,   871,   872,   970,   971,   873,
     874,   875,   876,   877,   878,   879,   880,   973,   974,   881,
     882,   883,   884,   885,   886,   887,   888,   889,   890,   975,
     891,   892,   893,   894,   895,   896,   897,   920,   943,   944,
     945,   946,   947,   976,   977,   948,   949,   979,   950,   951,
     952,   953,   954,   955,   956,   957,   963,   964,   965,   966,
     967,   968,   969,   981,   978,   984,   972,   982,   980,   983,
     985,   986,   989,   990,  1002,  1000,  1001,  1003,  1005,  1006,
    1004,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1039,
    1015,  1041,  1016,  1017,  1043,  1088,  1230,   314,  1117,  1018,
    1136,  1189,  1269,  1264,  1263,  1250,  1190,  1231,  1233,   753,
     570,  1019,  1020,  1021,  1022,  1023,  1024,  1025,   724,  1026,
    1248,  1027,  1028,  1029,  1034,  1035,  1036,  1037,   509,  1038,
    1128,  1042,   736,  1040,  1045,  1044,  1046,  1052,  1053,  1054,
     795,  1055,  1056,   589,  1057,  1058,  1059,  1060,  1061,  1062,
     759,  1063,  1064,  1065,  1265,   800,  1066,  1067,  1266,  1068,
    1069,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1098,   628,  1099,  1249,  1111,  1112,  1113,
    1114,  1246,  1115,  1116,  1120,   729,  1126,  1127,   401,   466,
    1247,  1223,  1129,  1131,   333,     0,  1222,     0,  1132,     0,
       0,     0,  1134,     0,   644,     0,  1137,  1138,  1160,  1161,
    1162,  1185,  1186,  1187,  1188,  1191,  1204,  1205,  1232,     0,
       0,  1237,  1251,  1234,  1261,  1262,   515,     0,     0,     0,
     648,     0,     0,     0,     0,   655,     0,     0,     0,     0,
       0,     0,     0,   552
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-584))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     458,   318,   319,    10,     1,    12,     1,   111,     1,   326,
       1,     1,     1,     1,     1,     1,   245,     1,     1,     1,
       1,     3,     1,     1,     6,   245,     1,     1,   243,     1,
     243,   244,   247,   245,    23,    30,   243,     1,   243,     1,
     247,    23,    23,    34,    39,    20,   245,   243,    20,     1,
       1,   247,    41,   245,     1,    46,    45,    61,   245,    41,
      41,     1,    45,    45,    45,   243,     1,   177,   178,   247,
      61,    62,    63,    64,   245,   243,     1,   246,    71,   247,
     245,    45,   245,    66,    66,     1,    68,    71,    71,   245,
      81,   177,   178,    71,   245,   412,   413,   245,    80,   150,
     151,     1,    66,   420,   101,   422,   101,    71,     8,     9,
     214,   245,   429,   101,   101,   101,   245,   434,    18,   101,
     101,   245,   101,   243,    71,    99,    26,   247,   445,   446,
     105,   448,    32,   105,   245,    35,    36,   126,    38,   456,
     457,   134,   245,   460,    44,   126,   135,   136,   131,   131,
      50,    51,   245,   127,    54,    55,    56,     1,   245,   134,
      60,   101,   134,   245,   145,    65,   101,   131,   626,    69,
      70,     1,   134,    73,    99,   246,    76,    77,   160,   167,
     167,   170,   134,   246,    84,   101,    30,   134,   167,   243,
     246,    91,    92,   247,    94,    95,    96,    97,    98,   134,
     243,   205,   127,   210,   247,   167,   210,   189,   246,   109,
       1,   246,    13,    14,    15,   167,   223,   117,   118,   119,
       1,   121,   246,    67,   124,   125,     1,   167,   128,   246,
     211,   243,   167,   550,   243,   247,    27,    28,   247,   139,
     229,   229,    33,   246,   234,   246,    21,    22,   229,   244,
      25,   167,   242,   244,   236,   244,   244,   101,   244,   103,
     104,   244,   244,   244,   164,   244,   244,   229,   168,   244,
     244,   101,   172,   173,   174,   175,   176,   229,   150,   151,
     180,   181,   244,   234,   243,   243,   246,    78,    79,   247,
     190,   242,   246,   244,    85,    86,    87,   244,   246,   616,
     144,   241,   146,   147,   148,   149,   242,   624,   625,   244,
     111,   243,     1,    88,    89,    90,   107,   108,    93,   163,
     101,   221,   222,   246,   224,   241,   101,   111,   244,   243,
     230,   122,   123,   247,   246,   235,    49,   167,   113,   114,
     240,    30,   133,   246,   244,   189,   198,   199,   243,   246,
      39,   142,   247,   134,   129,   130,   243,   201,   246,    72,
     247,    74,   809,   810,   811,   812,   813,   246,    19,   246,
     154,   155,   156,   157,   158,   958,   959,   960,   246,   246,
       1,   246,   246,   246,   159,   246,   167,     8,     9,   246,
     246,    42,   236,   237,   243,   246,   246,    18,   246,   229,
     244,    52,   132,   116,   246,    26,   246,   246,    59,   246,
     246,    32,   101,   246,    35,    36,   111,    38,   246,   246,
     246,     1,   246,    44,    75,     1,   246,   246,   246,    50,
      51,   246,   246,    54,    55,    56,   246,   246,   246,    60,
     231,   232,   233,    23,    65,     1,   246,     3,    69,    70,
       6,   102,    73,   244,    30,    76,    77,   246,   246,   110,
     246,    41,   132,    84,   246,    45,   246,    23,   246,   244,
      91,    92,   246,    94,    95,    96,    97,    98,   246,   192,
     193,   246,   246,   246,   246,    41,   246,     5,   109,    45,
     246,    67,   246,   246,   246,   246,   117,   118,   119,   246,
     121,   246,   153,   124,   125,   246,   246,   128,   246,   246,
      66,   246,    68,    31,   246,   246,   229,   246,   139,   246,
     171,   101,   246,   246,    80,   101,   246,   103,   104,   246,
     246,    49,   246,   132,   246,   246,   246,   246,   246,    57,
     246,   246,   246,   164,   246,   101,   126,   168,   246,   246,
       1,   172,   173,   174,   175,   176,    74,   243,   246,   180,
     181,   246,   246,   111,   177,   145,   111,   111,   144,   190,
     146,   147,   148,   149,   111,   131,    27,    28,   111,   177,
     177,    99,    33,   111,   177,   177,   177,   163,   106,   177,
     177,   243,   246,   243,   132,   111,   243,   246,   246,     1,
     221,   222,   120,   224,   160,   246,   246,   246,   246,   230,
     246,   246,    74,   189,   235,   246,   246,   246,   246,   240,
     138,    23,   140,   141,   246,   201,   246,    78,    79,   246,
      74,   211,   246,   189,    85,    86,    87,   246,   246,    41,
     246,   246,   246,    45,   246,     0,     1,   243,   177,   229,
       5,   246,   246,   177,   177,   111,   107,   108,   132,   111,
     236,   237,   246,   246,   246,    20,   177,   246,    23,    24,
     177,   122,   123,   111,    29,   193,  1134,   111,   177,   177,
     236,   177,   133,   132,   177,   203,   111,   111,    43,   207,
     152,   142,    47,    48,   111,   213,   111,     1,   111,   217,
     132,   219,   111,    58,   177,   177,   246,    61,   152,   177,
     228,   246,   177,   177,   177,   111,     1,    72,   177,   177,
     238,   183,   177,   177,   126,   132,   243,    82,    83,   177,
      34,   193,   177,   135,   136,   177,    21,    22,   200,   183,
      25,   243,    46,   246,   177,   100,    61,   132,   243,   193,
     132,   213,   246,   215,   216,   246,   200,    61,    62,    63,
      64,   116,   246,   246,   246,   246,   228,   246,   170,   213,
     246,   215,   216,   243,   245,    61,   238,    81,   177,   246,
     231,   232,   233,   177,   228,   246,   246,   177,   132,   246,
     243,   177,   132,   243,   238,   132,   177,   152,   177,   246,
     246,   132,   243,    88,    89,    90,   161,   162,    93,   246,
     165,   166,   132,   243,   132,   246,   101,   246,   246,   246,
     246,   132,   132,   132,   132,   132,   132,   229,   113,   114,
     184,   185,   186,   187,   188,   111,   246,   191,   192,   243,
     243,   195,   196,   197,   129,   130,   200,   111,   202,   203,
     204,   246,   206,   246,   208,   209,   243,   132,   212,   243,
     243,   111,   111,   243,   218,   220,   243,   243,   243,   184,
     185,   186,   187,   188,   159,   243,   191,   192,   243,   243,
     195,   196,   197,   243,   243,   200,   243,   202,   203,   204,
     243,   206,   243,   208,   209,   243,   243,   212,   184,   185,
     186,   187,   188,   218,   243,   191,   192,   243,   243,   195,
     196,   197,   111,   243,   200,   243,   202,   203,   204,   111,
     206,   111,   208,   209,   132,   111,   212,   111,   132,   243,
     132,   177,   218,   246,   132,   132,   132,   132,   111,   132,
     243,   132,   243,   132,   132,   132,   243,   132,   246,   132,
     243,   243,   243,   243,   243,   243,   243,   132,   177,   243,
     243,   243,   243,   243,   243,   243,   243,   132,   111,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   132,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   132,   132,   243,   243,   132,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   132,   243,   132,   246,   243,   246,   246,
     132,   111,   243,   243,   132,   243,   243,   177,   132,   132,
     246,   132,   246,   132,   243,   132,   132,   132,   243,   132,
     243,   132,   243,   243,   132,   137,   111,    71,   137,   243,
     995,  1031,  1268,  1241,  1239,  1229,  1033,  1129,   132,   525,
     285,   243,   243,   243,   243,   243,   243,   243,   476,   243,
    1225,   243,   243,   243,   243,   243,   243,   243,   238,   243,
     182,   243,   501,   246,   243,   246,   243,   243,   243,   243,
     575,   243,   243,   306,   243,   243,   243,   243,   243,   243,
     539,   243,   243,   243,  1243,   583,   243,   243,  1245,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   348,   243,  1227,   243,   243,   243,
     243,  1219,   243,   243,   243,   491,   243,   243,   118,   177,
    1221,  1094,   247,   243,    94,    -1,  1092,    -1,   246,    -1,
      -1,    -1,   246,    -1,   377,    -1,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,    -1,
      -1,   243,   243,   246,   243,   243,   246,    -1,    -1,    -1,
     395,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   249,     0,     1,     5,    20,    23,    24,    29,    43,
      47,    48,    58,    72,    82,    83,   100,   116,   152,   161,
     162,   165,   166,   220,   250,   255,   260,   282,   288,   302,
     320,   337,   351,   366,   373,   377,   387,   396,   416,   426,
     432,   436,   446,   509,   529,   243,   244,   245,   245,   321,
     397,   427,   245,   437,   245,   352,   417,   338,   245,   245,
     303,   367,   245,   245,   378,   388,   245,     1,    30,    39,
     101,   283,   284,   285,   286,   287,     1,    27,    28,    33,
      78,    79,    85,    86,    87,   107,   108,   122,   123,   133,
     142,   231,   232,   233,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   245,   245,   245,     1,    71,   433,   434,
     435,   245,     1,     8,     9,    18,    26,    32,    35,    36,
      38,    44,    50,    51,    54,    55,    56,    60,    65,    69,
      70,    73,    76,    77,    84,    91,    92,    94,    95,    96,
      97,    98,   109,   117,   118,   119,   121,   124,   125,   128,
     139,   164,   168,   172,   173,   174,   175,   176,   180,   181,
     190,   221,   222,   224,   230,   235,   240,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   501,   505,
     506,   507,   508,   245,   245,   245,     1,   234,   289,   290,
     291,   292,   293,     1,    99,   127,   256,   257,   258,   259,
     245,   245,     1,    34,    46,    61,    62,    63,    64,    81,
     530,   531,   532,   533,   534,   535,   536,   537,   538,     1,
      30,    67,   101,   103,   104,   144,   146,   147,   148,   149,
     163,   189,   201,   236,   237,   261,   262,   263,   264,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   245,   245,     1,   101,   374,   375,   376,   243,
     246,   246,   246,   244,   284,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   244,   511,     1,    21,    22,    25,    88,    89,
      90,    93,   101,   113,   114,   129,   130,   159,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,     1,     3,     6,    23,    41,    45,    66,
      68,    80,   101,   131,   160,   189,   236,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   411,   412,   413,
     414,   415,     1,    71,   134,   428,   429,   430,   431,   246,
     244,   434,     1,   101,   134,   167,   438,   442,   443,   444,
     445,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   502,   246,   498,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   244,   448,     1,    23,    41,
      45,   126,   135,   136,   170,   229,   353,   354,   355,   356,
     357,   358,   359,   363,   364,   365,     1,   134,   167,   229,
     418,   422,   423,   424,   425,     1,    45,    66,    71,   131,
     339,   343,   344,   345,   349,   350,   243,   246,   244,   290,
     242,   243,   246,   246,   244,   257,     1,    23,    41,    45,
     101,   126,   145,   211,   229,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   316,     1,    20,   105,   134,   368,
     369,   370,   371,   372,   246,   246,   246,   246,   246,   246,
     246,   244,   531,   243,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   244,
     262,     1,   101,   167,   229,   379,   380,   381,   382,   383,
       1,   101,   167,   389,   390,   391,   392,   246,   244,   375,
     132,   132,   132,   243,   111,   111,   177,   111,   252,   252,
     111,   111,   111,   177,   177,   111,   252,   177,   177,   177,
     177,   177,   243,   243,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   244,   323,   243,
     246,   246,   246,   246,   408,   246,   246,   246,   246,   246,
     246,   246,   246,   244,   399,   246,   246,   244,   429,   132,
     243,   246,   246,   439,   244,   443,   177,   252,   252,   111,
     177,   177,   111,   132,   177,   252,   177,   252,   111,   111,
     111,   177,   177,   177,   252,   132,   177,   111,   111,   252,
     111,   111,   132,   111,   111,   177,   177,   246,   177,   246,
     252,   252,   177,   252,   177,   177,   177,   177,   178,   177,
     178,   177,   177,   252,   252,   111,   254,   132,   252,   177,
     177,   177,   177,   243,   243,   246,   246,   360,   246,   246,
     246,   246,   246,   244,   354,   246,   419,   246,   244,   423,
     243,   340,   246,   246,   246,   244,   344,   177,   243,   245,
     132,   132,   243,   243,   246,   246,   317,   246,   246,   246,
     313,   246,   244,   305,   243,   246,   246,   246,   244,   369,
     177,   177,   177,   132,   177,   177,   252,   243,   132,   177,
     132,   132,   132,   132,   132,   132,   150,   151,   265,   266,
     150,   151,   267,   268,   132,   132,   111,   132,   132,   243,
     243,   246,   384,   246,   244,   380,   243,   246,   393,   244,
     390,   132,   243,   243,   243,   243,   243,   243,   243,   154,
     155,   156,   157,   158,   251,   252,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     111,   111,   252,   111,   111,   111,   111,   132,   111,   111,
     252,   252,   254,   243,   132,   198,   199,   132,   177,   246,
     132,   132,   132,   132,   111,   132,   132,   132,   243,   132,
     132,   243,   243,   132,   132,   246,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,    61,   184,
     185,   186,   187,   188,   191,   192,   195,   196,   197,   200,
     202,   203,   204,   206,   208,   209,   212,   218,   503,   504,
     243,    61,   184,   185,   186,   187,   188,   191,   192,   195,
     196,   197,   200,   202,   203,   204,   206,   208,   209,   212,
     218,   499,   500,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,    13,    14,
      15,   253,   254,   243,   243,   243,   243,   243,   243,   243,
     132,   177,   246,   132,   111,   132,   132,   132,   243,   132,
     246,   132,   243,   246,   132,   132,   111,   347,   348,   243,
     243,     1,   101,   167,   241,   294,   295,   296,   297,   298,
     243,   243,   132,   177,   246,   132,   132,   132,   246,   132,
     243,   132,   132,   132,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   247,   243,   247,   243,   243,   243,   243,   243,   132,
     246,   132,   243,   132,   246,   243,   243,   251,   251,   251,
     251,   251,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
      10,    12,   210,   223,   409,   410,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   137,   440,
     441,   243,   247,   243,   247,   253,   253,   253,   243,   243,
      19,    42,    52,    59,    75,   102,   110,   153,   171,   361,
     362,   243,   243,   243,   243,   243,   243,   137,   420,   421,
     243,    61,   205,   210,   341,   342,   243,   243,   182,   247,
     346,   243,   246,   299,   246,   244,   295,   243,   243,     5,
      31,    49,    57,    74,    99,   106,   120,   138,   140,   141,
     193,   203,   207,   213,   217,   219,   228,   238,   318,   319,
     243,   243,   243,    61,   184,   185,   186,   187,   188,   191,
     192,   195,   196,   197,   200,   202,   203,   204,   206,   208,
     209,   212,   218,   314,   315,   243,   243,   243,   243,   266,
     268,   243,    74,   152,   183,   193,   200,   213,   215,   216,
     228,   238,   385,   386,   243,   243,    74,   152,   183,   193,
     200,   213,   215,   216,   228,   238,   394,   395,   243,   247,
     243,   247,   504,   500,   243,   247,   243,   247,   243,   247,
     111,   348,   243,   132,   246,   214,   254,   243,   243,   247,
     243,   247,   243,   247,   243,   247,   410,   441,   362,   421,
     342,   243,    49,    72,    74,   116,   192,   193,   229,   300,
     301,   243,   243,   319,   315,   386,   395,   243,   247,   301
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

/* Line 1788 of yacc.c  */
#line 385 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1788 of yacc.c  */
#line 387 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1788 of yacc.c  */
#line 391 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1788 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1788 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1788 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1788 of yacc.c  */
#line 407 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1788 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1788 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1788 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1788 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1788 of yacc.c  */
#line 416 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1788 of yacc.c  */
#line 430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:

/* Line 1788 of yacc.c  */
#line 436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:

/* Line 1788 of yacc.c  */
#line 461 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:

/* Line 1788 of yacc.c  */
#line 467 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:

/* Line 1788 of yacc.c  */
#line 476 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:

/* Line 1788 of yacc.c  */
#line 482 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:

/* Line 1788 of yacc.c  */
#line 490 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 529 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 588 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 616 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:

/* Line 1788 of yacc.c  */
#line 624 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 639 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:

/* Line 1788 of yacc.c  */
#line 663 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:

/* Line 1788 of yacc.c  */
#line 686 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 714 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 744 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 767 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:

/* Line 1788 of yacc.c  */
#line 782 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:

/* Line 1788 of yacc.c  */
#line 791 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:

/* Line 1788 of yacc.c  */
#line 800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:

/* Line 1788 of yacc.c  */
#line 818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:

/* Line 1788 of yacc.c  */
#line 824 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:

/* Line 1788 of yacc.c  */
#line 829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:

/* Line 1788 of yacc.c  */
#line 841 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:

/* Line 1788 of yacc.c  */
#line 846 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:

/* Line 1788 of yacc.c  */
#line 849 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:

/* Line 1788 of yacc.c  */
#line 854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:

/* Line 1788 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:

/* Line 1788 of yacc.c  */
#line 865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:

/* Line 1788 of yacc.c  */
#line 869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:

/* Line 1788 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:

/* Line 1788 of yacc.c  */
#line 877 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:

/* Line 1788 of yacc.c  */
#line 881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:

/* Line 1788 of yacc.c  */
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:

/* Line 1788 of yacc.c  */
#line 895 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 908 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 998 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:

/* Line 1788 of yacc.c  */
#line 1007 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1044 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1056 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1067 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:

/* Line 1788 of yacc.c  */
#line 1118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1788 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1788 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1788 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1788 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1788 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1788 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1788 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:

/* Line 1788 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:

/* Line 1788 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:

/* Line 1788 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:

/* Line 1788 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:

/* Line 1788 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:

/* Line 1788 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:

/* Line 1788 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:

/* Line 1788 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:

/* Line 1788 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:

/* Line 1788 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:

/* Line 1788 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:

/* Line 1788 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:

/* Line 1788 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:

/* Line 1788 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:

/* Line 1788 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:

/* Line 1788 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:

/* Line 1788 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:

/* Line 1788 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:

/* Line 1788 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:

/* Line 1788 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:

/* Line 1788 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:

/* Line 1788 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:

/* Line 1788 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:

/* Line 1788 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:

/* Line 1788 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:

/* Line 1788 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:

/* Line 1788 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:

/* Line 1788 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:

/* Line 1788 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:

/* Line 1788 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:

/* Line 1788 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:

/* Line 1788 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:

/* Line 1788 of yacc.c  */
#line 1286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:

/* Line 1788 of yacc.c  */
#line 1296 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:

/* Line 1788 of yacc.c  */
#line 1303 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1361 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:

/* Line 1788 of yacc.c  */
#line 1370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1788 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1788 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1788 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1788 of yacc.c  */
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1788 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1788 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1788 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1788 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1788 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1788 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1788 of yacc.c  */
#line 1436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1788 of yacc.c  */
#line 1445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:

/* Line 1788 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:

/* Line 1788 of yacc.c  */
#line 1461 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:

/* Line 1788 of yacc.c  */
#line 1467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:

/* Line 1788 of yacc.c  */
#line 1471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:

/* Line 1788 of yacc.c  */
#line 1475 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:

/* Line 1788 of yacc.c  */
#line 1485 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:

/* Line 1788 of yacc.c  */
#line 1490 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1504 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1524 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:

/* Line 1788 of yacc.c  */
#line 1533 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:

/* Line 1788 of yacc.c  */
#line 1545 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1557 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1619 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1654 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1667 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:

/* Line 1788 of yacc.c  */
#line 1676 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1687 "conf_parser.y"
    {
}
    break;

  case 271:

/* Line 1788 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:

/* Line 1788 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:

/* Line 1788 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:

/* Line 1788 of yacc.c  */
#line 1704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:

/* Line 1788 of yacc.c  */
#line 1708 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:

/* Line 1788 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:

/* Line 1788 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:

/* Line 1788 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:

/* Line 1788 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:

/* Line 1788 of yacc.c  */
#line 1731 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1750 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1760 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:

/* Line 1788 of yacc.c  */
#line 1773 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:

/* Line 1788 of yacc.c  */
#line 1780 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:

/* Line 1788 of yacc.c  */
#line 1792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:

/* Line 1788 of yacc.c  */
#line 1801 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1816 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:

/* Line 1788 of yacc.c  */
#line 1834 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1849 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:

/* Line 1788 of yacc.c  */
#line 1868 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:

/* Line 1788 of yacc.c  */
#line 1877 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1899 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:

/* Line 1788 of yacc.c  */
#line 1906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:

/* Line 1788 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:

/* Line 1788 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:

/* Line 1788 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:

/* Line 1788 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1788 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:

/* Line 1788 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:

/* Line 1788 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:

/* Line 1788 of yacc.c  */
#line 1938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:

/* Line 1788 of yacc.c  */
#line 1942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:

/* Line 1788 of yacc.c  */
#line 1951 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:

/* Line 1788 of yacc.c  */
#line 1958 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 1971 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:

/* Line 1788 of yacc.c  */
#line 1977 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:

/* Line 1788 of yacc.c  */
#line 1984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:

/* Line 1788 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:

/* Line 1788 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:

/* Line 1788 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:

/* Line 1788 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:

/* Line 1788 of yacc.c  */
#line 2004 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:

/* Line 1788 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:

/* Line 1788 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:

/* Line 1788 of yacc.c  */
#line 2016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:

/* Line 1788 of yacc.c  */
#line 2020 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:

/* Line 1788 of yacc.c  */
#line 2029 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2044 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2088 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:

/* Line 1788 of yacc.c  */
#line 2097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:

/* Line 1788 of yacc.c  */
#line 2106 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2132 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2150 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:

/* Line 1788 of yacc.c  */
#line 2174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:

/* Line 1788 of yacc.c  */
#line 2178 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:

/* Line 1788 of yacc.c  */
#line 2186 "conf_parser.y"
    {
}
    break;

  case 376:

/* Line 1788 of yacc.c  */
#line 2191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:

/* Line 1788 of yacc.c  */
#line 2195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:

/* Line 1788 of yacc.c  */
#line 2199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:

/* Line 1788 of yacc.c  */
#line 2203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:

/* Line 1788 of yacc.c  */
#line 2209 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2220 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2231 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:

/* Line 1788 of yacc.c  */
#line 2251 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:

/* Line 1788 of yacc.c  */
#line 2276 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2334 "conf_parser.y"
    {
}
    break;

  case 391:

/* Line 1788 of yacc.c  */
#line 2339 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:

/* Line 1788 of yacc.c  */
#line 2348 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2367 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:

/* Line 1788 of yacc.c  */
#line 2376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:

/* Line 1788 of yacc.c  */
#line 2380 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:

/* Line 1788 of yacc.c  */
#line 2410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:

/* Line 1788 of yacc.c  */
#line 2424 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:

/* Line 1788 of yacc.c  */
#line 2449 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2489 "conf_parser.y"
    {
}
    break;

  case 421:

/* Line 1788 of yacc.c  */
#line 2494 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:

/* Line 1788 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:

/* Line 1788 of yacc.c  */
#line 2509 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 488:

/* Line 1788 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:

/* Line 1788 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 490:

/* Line 1788 of yacc.c  */
#line 2566 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1788 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1788 of yacc.c  */
#line 2578 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:

/* Line 1788 of yacc.c  */
#line 2583 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:

/* Line 1788 of yacc.c  */
#line 2588 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 495:

/* Line 1788 of yacc.c  */
#line 2593 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 496:

/* Line 1788 of yacc.c  */
#line 2598 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 497:

/* Line 1788 of yacc.c  */
#line 2603 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:

/* Line 1788 of yacc.c  */
#line 2608 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 499:

/* Line 1788 of yacc.c  */
#line 2613 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 500:

/* Line 1788 of yacc.c  */
#line 2618 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 501:

/* Line 1788 of yacc.c  */
#line 2623 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 502:

/* Line 1788 of yacc.c  */
#line 2628 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 503:

/* Line 1788 of yacc.c  */
#line 2633 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 504:

/* Line 1788 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1788 of yacc.c  */
#line 2643 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1788 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:

/* Line 1788 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:

/* Line 1788 of yacc.c  */
#line 2658 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:

/* Line 1788 of yacc.c  */
#line 2664 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 511:

/* Line 1788 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 512:

/* Line 1788 of yacc.c  */
#line 2689 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 513:

/* Line 1788 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 514:

/* Line 1788 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 515:

/* Line 1788 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 516:

/* Line 1788 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 517:

/* Line 1788 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 518:

/* Line 1788 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 519:

/* Line 1788 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 520:

/* Line 1788 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 521:

/* Line 1788 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1788 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:

/* Line 1788 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 524:

/* Line 1788 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1788 of yacc.c  */
#line 2750 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 526:

/* Line 1788 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 527:

/* Line 1788 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 528:

/* Line 1788 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 529:

/* Line 1788 of yacc.c  */
#line 2770 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:

/* Line 1788 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:

/* Line 1788 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 533:

/* Line 1788 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 534:

/* Line 1788 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 535:

/* Line 1788 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 536:

/* Line 1788 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 537:

/* Line 1788 of yacc.c  */
#line 2824 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 538:

/* Line 1788 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 542:

/* Line 1788 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 543:

/* Line 1788 of yacc.c  */
#line 2838 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 544:

/* Line 1788 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 545:

/* Line 1788 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 546:

/* Line 1788 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 547:

/* Line 1788 of yacc.c  */
#line 2850 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 548:

/* Line 1788 of yacc.c  */
#line 2853 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 549:

/* Line 1788 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 550:

/* Line 1788 of yacc.c  */
#line 2859 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 551:

/* Line 1788 of yacc.c  */
#line 2862 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 552:

/* Line 1788 of yacc.c  */
#line 2865 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 553:

/* Line 1788 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 554:

/* Line 1788 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 555:

/* Line 1788 of yacc.c  */
#line 2874 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 556:

/* Line 1788 of yacc.c  */
#line 2877 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 557:

/* Line 1788 of yacc.c  */
#line 2880 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 558:

/* Line 1788 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 559:

/* Line 1788 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 560:

/* Line 1788 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 561:

/* Line 1788 of yacc.c  */
#line 2892 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 562:

/* Line 1788 of yacc.c  */
#line 2897 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 566:

/* Line 1788 of yacc.c  */
#line 2903 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 567:

/* Line 1788 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 568:

/* Line 1788 of yacc.c  */
#line 2909 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 569:

/* Line 1788 of yacc.c  */
#line 2912 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 570:

/* Line 1788 of yacc.c  */
#line 2915 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 571:

/* Line 1788 of yacc.c  */
#line 2918 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 572:

/* Line 1788 of yacc.c  */
#line 2921 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 573:

/* Line 1788 of yacc.c  */
#line 2924 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 574:

/* Line 1788 of yacc.c  */
#line 2927 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 575:

/* Line 1788 of yacc.c  */
#line 2930 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 576:

/* Line 1788 of yacc.c  */
#line 2933 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 577:

/* Line 1788 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 578:

/* Line 1788 of yacc.c  */
#line 2939 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 579:

/* Line 1788 of yacc.c  */
#line 2942 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 580:

/* Line 1788 of yacc.c  */
#line 2945 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 581:

/* Line 1788 of yacc.c  */
#line 2948 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 582:

/* Line 1788 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 583:

/* Line 1788 of yacc.c  */
#line 2954 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 584:

/* Line 1788 of yacc.c  */
#line 2957 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 585:

/* Line 1788 of yacc.c  */
#line 2960 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 586:

/* Line 1788 of yacc.c  */
#line 2965 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:

/* Line 1788 of yacc.c  */
#line 2970 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:

/* Line 1788 of yacc.c  */
#line 2975 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:

/* Line 1788 of yacc.c  */
#line 2980 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:

/* Line 1788 of yacc.c  */
#line 3004 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 612:

/* Line 1788 of yacc.c  */
#line 3009 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 613:

/* Line 1788 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 614:

/* Line 1788 of yacc.c  */
#line 3019 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 615:

/* Line 1788 of yacc.c  */
#line 3024 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 616:

/* Line 1788 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:

/* Line 1788 of yacc.c  */
#line 3034 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:

/* Line 1788 of yacc.c  */
#line 3039 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:

/* Line 1788 of yacc.c  */
#line 3044 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:

/* Line 1788 of yacc.c  */
#line 3049 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 621:

/* Line 1788 of yacc.c  */
#line 3054 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:

/* Line 1788 of yacc.c  */
#line 3059 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:

/* Line 1788 of yacc.c  */
#line 3064 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:

/* Line 1788 of yacc.c  */
#line 3069 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 625:

/* Line 1788 of yacc.c  */
#line 3074 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 626:

/* Line 1788 of yacc.c  */
#line 3079 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 627:

/* Line 1788 of yacc.c  */
#line 3084 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 639:

/* Line 1788 of yacc.c  */
#line 3103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 640:

/* Line 1788 of yacc.c  */
#line 3109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 641:

/* Line 1788 of yacc.c  */
#line 3115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 642:

/* Line 1788 of yacc.c  */
#line 3124 "conf_parser.y"
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

  case 643:

/* Line 1788 of yacc.c  */
#line 3138 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 644:

/* Line 1788 of yacc.c  */
#line 3144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 645:

/* Line 1788 of yacc.c  */
#line 3150 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1788 of yacc.c  */
#line 7366 "conf_parser.c"
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



