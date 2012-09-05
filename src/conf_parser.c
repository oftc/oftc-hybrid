/* A Bison parser, made by GNU Bison 2.6.2.  */

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
#define YYBISON_VERSION "2.6.2"

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
     BYTES = 267,
     KBYTES = 268,
     MBYTES = 269,
     GBYTES = 270,
     TBYTES = 271,
     CALLER_ID_WAIT = 272,
     CAN_FLOOD = 273,
     CHANNEL = 274,
     CIDR_BITLEN_IPV4 = 275,
     CIDR_BITLEN_IPV6 = 276,
     CLASS = 277,
     CONNECT = 278,
     CONNECTFREQ = 279,
     DEFAULT_FLOODCOUNT = 280,
     DEFAULT_SPLIT_SERVER_COUNT = 281,
     DEFAULT_SPLIT_USER_COUNT = 282,
     DENY = 283,
     DESCRIPTION = 284,
     DIE = 285,
     DISABLE_AUTH = 286,
     DISABLE_FAKE_CHANNELS = 287,
     DISABLE_REMOTE_COMMANDS = 288,
     DOTS_IN_IDENT = 289,
     DURATION = 290,
     EGDPOOL_PATH = 291,
     EMAIL = 292,
     ENABLE = 293,
     ENCRYPTED = 294,
     EXCEED_LIMIT = 295,
     EXEMPT = 296,
     FAILED_OPER_NOTICE = 297,
     IRCD_FLAGS = 298,
     FLATTEN_LINKS = 299,
     GECOS = 300,
     GENERAL = 301,
     GLINE = 302,
     GLINE_DURATION = 303,
     GLINE_ENABLE = 304,
     GLINE_EXEMPT = 305,
     GLINE_TIME = 306,
     GLINE_REQUEST_DURATION = 307,
     GLINE_MIN_CIDR = 308,
     GLINE_MIN_CIDR6 = 309,
     GLOBAL_KILL = 310,
     IRCD_AUTH = 311,
     NEED_IDENT = 312,
     HAVENT_READ_CONF = 313,
     HIDDEN = 314,
     HIDDEN_NAME = 315,
     HIDE_SERVER_IPS = 316,
     HIDE_SERVERS = 317,
     HIDE_SPOOF_IPS = 318,
     HOST = 319,
     HUB = 320,
     HUB_MASK = 321,
     IGNORE_BOGUS_TS = 322,
     INVISIBLE_ON_CONNECT = 323,
     IP = 324,
     KILL = 325,
     KILL_CHASE_TIME_LIMIT = 326,
     KLINE = 327,
     KLINE_EXEMPT = 328,
     KLINE_REASON = 329,
     KLINE_WITH_REASON = 330,
     KNOCK_DELAY = 331,
     KNOCK_DELAY_CHANNEL = 332,
     LEAF_MASK = 333,
     LINKS_DELAY = 334,
     LISTEN = 335,
     T_LOG = 336,
     MAX_ACCEPT = 337,
     MAX_BANS = 338,
     MAX_CHANS_PER_OPER = 339,
     MAX_CHANS_PER_USER = 340,
     MAX_GLOBAL = 341,
     MAX_IDENT = 342,
     MAX_LOCAL = 343,
     MAX_NICK_CHANGES = 344,
     MAX_NICK_TIME = 345,
     MAX_NUMBER = 346,
     MAX_TARGETS = 347,
     MAX_WATCH = 348,
     MESSAGE_LOCALE = 349,
     MIN_NONWILDCARD = 350,
     MIN_NONWILDCARD_SIMPLE = 351,
     MODULE = 352,
     MODULES = 353,
     NAME = 354,
     NEED_PASSWORD = 355,
     NETWORK_DESC = 356,
     NETWORK_NAME = 357,
     NICK = 358,
     NICK_CHANGES = 359,
     NO_CREATE_ON_SPLIT = 360,
     NO_JOIN_ON_SPLIT = 361,
     NO_OPER_FLOOD = 362,
     NO_TILDE = 363,
     NUMBER = 364,
     NUMBER_PER_IDENT = 365,
     NUMBER_PER_CIDR = 366,
     NUMBER_PER_IP = 367,
     NUMBER_PER_IP_GLOBAL = 368,
     OPERATOR = 369,
     OPERS_BYPASS_CALLERID = 370,
     OPER_ONLY_UMODES = 371,
     OPER_PASS_RESV = 372,
     OPER_SPY_T = 373,
     OPER_UMODES = 374,
     JOIN_FLOOD_COUNT = 375,
     JOIN_FLOOD_TIME = 376,
     PACE_WAIT = 377,
     PACE_WAIT_SIMPLE = 378,
     PASSWORD = 379,
     PATH = 380,
     PING_COOKIE = 381,
     PING_TIME = 382,
     PING_WARNING = 383,
     PORT = 384,
     QSTRING = 385,
     QUIET_ON_BAN = 386,
     REASON = 387,
     REDIRPORT = 388,
     REDIRSERV = 389,
     REGEX_T = 390,
     REHASH = 391,
     TREJECT_HOLD_TIME = 392,
     REMOTE = 393,
     REMOTEBAN = 394,
     RESTRICT_CHANNELS = 395,
     RESTRICTED = 396,
     RSA_PRIVATE_KEY_FILE = 397,
     RSA_PUBLIC_KEY_FILE = 398,
     SSL_CERTIFICATE_FILE = 399,
     SSL_DH_PARAM_FILE = 400,
     T_SSL_CLIENT_METHOD = 401,
     T_SSL_SERVER_METHOD = 402,
     T_SSLV3 = 403,
     T_TLSV1 = 404,
     RESV = 405,
     RESV_EXEMPT = 406,
     SECONDS = 407,
     MINUTES = 408,
     HOURS = 409,
     DAYS = 410,
     WEEKS = 411,
     SENDQ = 412,
     SEND_PASSWORD = 413,
     SERVERHIDE = 414,
     SERVERINFO = 415,
     IRCD_SID = 416,
     TKLINE_EXPIRE_NOTICES = 417,
     T_SHARED = 418,
     T_CLUSTER = 419,
     TYPE = 420,
     SHORT_MOTD = 421,
     SILENT = 422,
     SPOOF = 423,
     SPOOF_NOTICE = 424,
     STATS_E_DISABLED = 425,
     STATS_I_OPER_ONLY = 426,
     STATS_K_OPER_ONLY = 427,
     STATS_O_OPER_ONLY = 428,
     STATS_P_OPER_ONLY = 429,
     TBOOL = 430,
     TMASKED = 431,
     T_REJECT = 432,
     TS_MAX_DELTA = 433,
     TS_WARN_DELTA = 434,
     TWODOTS = 435,
     T_ALL = 436,
     T_BOTS = 437,
     T_SOFTCALLERID = 438,
     T_CALLERID = 439,
     T_CCONN = 440,
     T_CCONN_FULL = 441,
     T_SSL_CIPHER_LIST = 442,
     T_DEAF = 443,
     T_DEBUG = 444,
     T_DLINE = 445,
     T_DRONE = 446,
     T_EXTERNAL = 447,
     T_FULL = 448,
     T_INVISIBLE = 449,
     T_IPV4 = 450,
     T_IPV6 = 451,
     T_LOCOPS = 452,
     T_MAX_CLIENTS = 453,
     T_NCHANGE = 454,
     T_OPERWALL = 455,
     T_RECVQ = 456,
     T_REJ = 457,
     T_SERVER = 458,
     T_SERVNOTICE = 459,
     T_SET = 460,
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
     TRUE_NO_OPER_FLOOD = 476,
     TKLINE = 477,
     TXLINE = 478,
     TRESV = 479,
     UNKLINE = 480,
     USER = 481,
     USE_EGD = 482,
     USE_LOGGING = 483,
     USE_WHOIS_ACTUALLY = 484,
     VHOST = 485,
     VHOST6 = 486,
     XLINE = 487,
     WARN = 488,
     WARN_NO_NLINE = 489,
     T_SIZE = 490,
     T_FILE = 491
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
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define GBYTES 270
#define TBYTES 271
#define CALLER_ID_WAIT 272
#define CAN_FLOOD 273
#define CHANNEL 274
#define CIDR_BITLEN_IPV4 275
#define CIDR_BITLEN_IPV6 276
#define CLASS 277
#define CONNECT 278
#define CONNECTFREQ 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_SPLIT_SERVER_COUNT 281
#define DEFAULT_SPLIT_USER_COUNT 282
#define DENY 283
#define DESCRIPTION 284
#define DIE 285
#define DISABLE_AUTH 286
#define DISABLE_FAKE_CHANNELS 287
#define DISABLE_REMOTE_COMMANDS 288
#define DOTS_IN_IDENT 289
#define DURATION 290
#define EGDPOOL_PATH 291
#define EMAIL 292
#define ENABLE 293
#define ENCRYPTED 294
#define EXCEED_LIMIT 295
#define EXEMPT 296
#define FAILED_OPER_NOTICE 297
#define IRCD_FLAGS 298
#define FLATTEN_LINKS 299
#define GECOS 300
#define GENERAL 301
#define GLINE 302
#define GLINE_DURATION 303
#define GLINE_ENABLE 304
#define GLINE_EXEMPT 305
#define GLINE_TIME 306
#define GLINE_REQUEST_DURATION 307
#define GLINE_MIN_CIDR 308
#define GLINE_MIN_CIDR6 309
#define GLOBAL_KILL 310
#define IRCD_AUTH 311
#define NEED_IDENT 312
#define HAVENT_READ_CONF 313
#define HIDDEN 314
#define HIDDEN_NAME 315
#define HIDE_SERVER_IPS 316
#define HIDE_SERVERS 317
#define HIDE_SPOOF_IPS 318
#define HOST 319
#define HUB 320
#define HUB_MASK 321
#define IGNORE_BOGUS_TS 322
#define INVISIBLE_ON_CONNECT 323
#define IP 324
#define KILL 325
#define KILL_CHASE_TIME_LIMIT 326
#define KLINE 327
#define KLINE_EXEMPT 328
#define KLINE_REASON 329
#define KLINE_WITH_REASON 330
#define KNOCK_DELAY 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LINKS_DELAY 334
#define LISTEN 335
#define T_LOG 336
#define MAX_ACCEPT 337
#define MAX_BANS 338
#define MAX_CHANS_PER_OPER 339
#define MAX_CHANS_PER_USER 340
#define MAX_GLOBAL 341
#define MAX_IDENT 342
#define MAX_LOCAL 343
#define MAX_NICK_CHANGES 344
#define MAX_NICK_TIME 345
#define MAX_NUMBER 346
#define MAX_TARGETS 347
#define MAX_WATCH 348
#define MESSAGE_LOCALE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define NAME 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NICK_CHANGES 359
#define NO_CREATE_ON_SPLIT 360
#define NO_JOIN_ON_SPLIT 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_IDENT 365
#define NUMBER_PER_CIDR 366
#define NUMBER_PER_IP 367
#define NUMBER_PER_IP_GLOBAL 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define OPER_ONLY_UMODES 371
#define OPER_PASS_RESV 372
#define OPER_SPY_T 373
#define OPER_UMODES 374
#define JOIN_FLOOD_COUNT 375
#define JOIN_FLOOD_TIME 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PING_WARNING 383
#define PORT 384
#define QSTRING 385
#define QUIET_ON_BAN 386
#define REASON 387
#define REDIRPORT 388
#define REDIRSERV 389
#define REGEX_T 390
#define REHASH 391
#define TREJECT_HOLD_TIME 392
#define REMOTE 393
#define REMOTEBAN 394
#define RESTRICT_CHANNELS 395
#define RESTRICTED 396
#define RSA_PRIVATE_KEY_FILE 397
#define RSA_PUBLIC_KEY_FILE 398
#define SSL_CERTIFICATE_FILE 399
#define SSL_DH_PARAM_FILE 400
#define T_SSL_CLIENT_METHOD 401
#define T_SSL_SERVER_METHOD 402
#define T_SSLV3 403
#define T_TLSV1 404
#define RESV 405
#define RESV_EXEMPT 406
#define SECONDS 407
#define MINUTES 408
#define HOURS 409
#define DAYS 410
#define WEEKS 411
#define SENDQ 412
#define SEND_PASSWORD 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define IRCD_SID 416
#define TKLINE_EXPIRE_NOTICES 417
#define T_SHARED 418
#define T_CLUSTER 419
#define TYPE 420
#define SHORT_MOTD 421
#define SILENT 422
#define SPOOF 423
#define SPOOF_NOTICE 424
#define STATS_E_DISABLED 425
#define STATS_I_OPER_ONLY 426
#define STATS_K_OPER_ONLY 427
#define STATS_O_OPER_ONLY 428
#define STATS_P_OPER_ONLY 429
#define TBOOL 430
#define TMASKED 431
#define T_REJECT 432
#define TS_MAX_DELTA 433
#define TS_WARN_DELTA 434
#define TWODOTS 435
#define T_ALL 436
#define T_BOTS 437
#define T_SOFTCALLERID 438
#define T_CALLERID 439
#define T_CCONN 440
#define T_CCONN_FULL 441
#define T_SSL_CIPHER_LIST 442
#define T_DEAF 443
#define T_DEBUG 444
#define T_DLINE 445
#define T_DRONE 446
#define T_EXTERNAL 447
#define T_FULL 448
#define T_INVISIBLE 449
#define T_IPV4 450
#define T_IPV6 451
#define T_LOCOPS 452
#define T_MAX_CLIENTS 453
#define T_NCHANGE 454
#define T_OPERWALL 455
#define T_RECVQ 456
#define T_REJ 457
#define T_SERVER 458
#define T_SERVNOTICE 459
#define T_SET 460
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
#define TRUE_NO_OPER_FLOOD 476
#define TKLINE 477
#define TXLINE 478
#define TRESV 479
#define UNKLINE 480
#define USER 481
#define USE_EGD 482
#define USE_LOGGING 483
#define USE_WHOIS_ACTUALLY 484
#define VHOST 485
#define VHOST6 486
#define XLINE 487
#define WARN 488
#define WARN_NO_NLINE 489
#define T_SIZE 490
#define T_FILE 491



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 674 "conf_parser.c"
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
#line 702 "conf_parser.c"

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
#define YYLAST   1210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  242
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  287
/* YYNRULES -- Number of rules.  */
#define YYNRULES  635
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   491

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   241,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   237,
       2,   240,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   239,     2,   238,     2,     2,     2,     2,
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
     235,   236
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
     587,   589,   591,   593,   596,   601,   606,   611,   616,   621,
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
    1115,  1120,  1125,  1130,  1135,  1140,  1141,  1148,  1149,  1155,
    1159,  1161,  1163,  1166,  1168,  1170,  1172,  1174,  1176,  1181,
    1186,  1187,  1194,  1197,  1199,  1201,  1203,  1205,  1210,  1215,
    1221,  1224,  1226,  1228,  1230,  1235,  1236,  1243,  1244,  1250,
    1254,  1256,  1258,  1261,  1263,  1265,  1267,  1269,  1271,  1276,
    1281,  1287,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,
    1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,
    1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1405,  1410,
    1415,  1420,  1425,  1430,  1435,  1440,  1445,  1450,  1455,  1460,
    1465,  1470,  1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,
    1515,  1520,  1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,
    1565,  1570,  1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,
    1615,  1620,  1625,  1630,  1635,  1640,  1645,  1650,  1651,  1657,
    1661,  1663,  1665,  1667,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,
    1701,  1703,  1704,  1710,  1714,  1716,  1718,  1720,  1722,  1724,
    1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1761,  1766,  1771,  1777,
    1780,  1782,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1817,  1822,  1827,
    1832,  1837,  1842,  1847,  1852,  1857,  1862,  1867,  1872,  1877,
    1882,  1888,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1912,  1917,  1922,  1927,  1932
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     243,     0,    -1,    -1,   243,   244,    -1,   276,    -1,   282,
      -1,   296,    -1,   503,    -1,   314,    -1,   332,    -1,   346,
      -1,   254,    -1,   520,    -1,   361,    -1,   368,    -1,   372,
      -1,   382,    -1,   391,    -1,   411,    -1,   421,    -1,   427,
      -1,   441,    -1,   431,    -1,   249,    -1,     1,   237,    -1,
       1,   238,    -1,    -1,   246,    -1,   109,   245,    -1,   109,
     152,   245,    -1,   109,   153,   245,    -1,   109,   154,   245,
      -1,   109,   155,   245,    -1,   109,   156,   245,    -1,    -1,
     248,    -1,   109,   247,    -1,   109,    12,   247,    -1,   109,
      13,   247,    -1,   109,    14,   247,    -1,    98,   239,   250,
     238,   237,    -1,   250,   251,    -1,   251,    -1,   252,    -1,
     253,    -1,     1,   237,    -1,    97,   240,   130,   237,    -1,
     125,   240,   130,   237,    -1,   160,   239,   255,   238,   237,
      -1,   255,   256,    -1,   256,    -1,   267,    -1,   272,    -1,
     275,    -1,   269,    -1,   270,    -1,   271,    -1,   274,    -1,
     265,    -1,   264,    -1,   273,    -1,   268,    -1,   263,    -1,
     257,    -1,   258,    -1,   266,    -1,     1,   237,    -1,   146,
     240,   259,   237,    -1,   147,   240,   261,   237,    -1,   259,
     241,   260,    -1,   260,    -1,   148,    -1,   149,    -1,   261,
     241,   262,    -1,   262,    -1,   148,    -1,   149,    -1,   144,
     240,   130,   237,    -1,   142,   240,   130,   237,    -1,   145,
     240,   130,   237,    -1,   187,   240,   130,   237,    -1,    99,
     240,   130,   237,    -1,   161,   240,   130,   237,    -1,    29,
     240,   130,   237,    -1,   102,   240,   130,   237,    -1,   101,
     240,   130,   237,    -1,   230,   240,   130,   237,    -1,   231,
     240,   130,   237,    -1,   198,   240,   109,   237,    -1,    65,
     240,   175,   237,    -1,     5,   239,   277,   238,   237,    -1,
     277,   278,    -1,   278,    -1,   279,    -1,   281,    -1,   280,
      -1,     1,   237,    -1,    99,   240,   130,   237,    -1,    37,
     240,   130,   237,    -1,    29,   240,   130,   237,    -1,    81,
     239,   283,   238,   237,    -1,   283,   284,    -1,   284,    -1,
     285,    -1,   286,    -1,     1,   237,    -1,   228,   240,   175,
     237,    -1,    -1,   287,   236,   239,   288,   238,   237,    -1,
     288,   289,    -1,   289,    -1,   290,    -1,   292,    -1,   291,
      -1,     1,   237,    -1,    99,   240,   130,   237,    -1,   235,
     240,   248,   237,    -1,   235,   240,   212,   237,    -1,    -1,
     165,   293,   240,   294,   237,    -1,   294,   241,   295,    -1,
     295,    -1,   226,    -1,   114,    -1,    47,    -1,   190,    -1,
      72,    -1,    70,    -1,   189,    -1,    -1,   114,   297,   239,
     298,   238,   237,    -1,   298,   299,    -1,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,   306,    -1,   305,    -1,   303,
      -1,   304,    -1,   310,    -1,     1,   237,    -1,    99,   240,
     130,   237,    -1,   226,   240,   130,   237,    -1,   124,   240,
     130,   237,    -1,    39,   240,   175,   237,    -1,   143,   240,
     130,   237,    -1,    22,   240,   130,   237,    -1,    -1,   209,
     307,   240,   308,   237,    -1,   308,   241,   309,    -1,   309,
      -1,   182,    -1,   185,    -1,   186,    -1,   188,    -1,   189,
      -1,   193,    -1,    59,    -1,   206,    -1,   199,    -1,   202,
      -1,   210,    -1,   207,    -1,   192,    -1,   200,    -1,   204,
      -1,   194,    -1,   216,    -1,   183,    -1,   184,    -1,   197,
      -1,    -1,    43,   311,   240,   312,   237,    -1,   312,   241,
     313,    -1,   313,    -1,    55,    -1,   138,    -1,    72,    -1,
     225,    -1,   190,    -1,   211,    -1,   232,    -1,    47,    -1,
      30,    -1,   217,    -1,   136,    -1,     5,    -1,   104,    -1,
     200,    -1,   215,    -1,   118,    -1,   139,    -1,   205,    -1,
      97,    -1,    -1,    22,   315,   239,   316,   238,   237,    -1,
     316,   317,    -1,   317,    -1,   318,    -1,   329,    -1,   330,
      -1,   319,    -1,   320,    -1,   331,    -1,   321,    -1,   322,
      -1,   323,    -1,   324,    -1,   325,    -1,   326,    -1,   327,
      -1,   328,    -1,     1,   237,    -1,    99,   240,   130,   237,
      -1,   127,   240,   246,   237,    -1,   128,   240,   246,   237,
      -1,   112,   240,   109,   237,    -1,    24,   240,   246,   237,
      -1,    91,   240,   109,   237,    -1,    86,   240,   109,   237,
      -1,    88,   240,   109,   237,    -1,    87,   240,   109,   237,
      -1,   157,   240,   248,   237,    -1,   201,   240,   248,   237,
      -1,    20,   240,   109,   237,    -1,    21,   240,   109,   237,
      -1,   111,   240,   109,   237,    -1,    -1,    80,   333,   239,
     338,   238,   237,    -1,    -1,    43,   335,   240,   336,   237,
      -1,   336,   241,   337,    -1,   337,    -1,   208,    -1,    59,
      -1,   203,    -1,   338,   339,    -1,   339,    -1,   340,    -1,
     334,    -1,   344,    -1,   345,    -1,     1,   237,    -1,    -1,
     129,   240,   342,   341,   237,    -1,   342,   241,   343,    -1,
     343,    -1,   109,    -1,   109,   180,   109,    -1,    69,   240,
     130,   237,    -1,    64,   240,   130,   237,    -1,    -1,    56,
     347,   239,   348,   238,   237,    -1,   348,   349,    -1,   349,
      -1,   350,    -1,   351,    -1,   352,    -1,   354,    -1,   358,
      -1,   359,    -1,   360,    -1,   353,    -1,     1,   237,    -1,
     226,   240,   130,   237,    -1,   124,   240,   130,   237,    -1,
      22,   240,   130,   237,    -1,    39,   240,   175,   237,    -1,
      -1,    43,   355,   240,   356,   237,    -1,   356,   241,   357,
      -1,   357,    -1,   169,    -1,    40,    -1,    73,    -1,    57,
      -1,    18,    -1,   108,    -1,    50,    -1,   151,    -1,   100,
      -1,   168,   240,   130,   237,    -1,   134,   240,   130,   237,
      -1,   133,   240,   109,   237,    -1,    -1,   150,   362,   239,
     363,   238,   237,    -1,   363,   364,    -1,   364,    -1,   365,
      -1,   366,    -1,   367,    -1,     1,   237,    -1,   132,   240,
     130,   237,    -1,    19,   240,   130,   237,    -1,   103,   240,
     130,   237,    -1,   218,   239,   369,   238,   237,    -1,   369,
     370,    -1,   370,    -1,   371,    -1,     1,    -1,    99,   240,
     130,   237,    -1,    -1,   163,   373,   239,   374,   238,   237,
      -1,   374,   375,    -1,   375,    -1,   376,    -1,   377,    -1,
     378,    -1,     1,   237,    -1,    99,   240,   130,   237,    -1,
     226,   240,   130,   237,    -1,    -1,   165,   379,   240,   380,
     237,    -1,   380,   241,   381,    -1,   381,    -1,    72,    -1,
     225,    -1,   190,    -1,   211,    -1,   232,    -1,   214,    -1,
     150,    -1,   213,    -1,   197,    -1,   181,    -1,    -1,   164,
     383,   239,   384,   238,   237,    -1,   384,   385,    -1,   385,
      -1,   386,    -1,   387,    -1,     1,   237,    -1,    99,   240,
     130,   237,    -1,    -1,   165,   388,   240,   389,   237,    -1,
     389,   241,   390,    -1,   390,    -1,    72,    -1,   225,    -1,
     190,    -1,   211,    -1,   232,    -1,   214,    -1,   150,    -1,
     213,    -1,   197,    -1,   181,    -1,    -1,    23,   392,   239,
     393,   238,   237,    -1,   393,   394,    -1,   394,    -1,   395,
      -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,   401,
      -1,   400,    -1,   410,    -1,   402,    -1,   407,    -1,   408,
      -1,   409,    -1,   406,    -1,     1,   237,    -1,    99,   240,
     130,   237,    -1,    64,   240,   130,   237,    -1,   230,   240,
     130,   237,    -1,   158,   240,   130,   237,    -1,     3,   240,
     130,   237,    -1,   129,   240,   109,   237,    -1,     6,   240,
     195,   237,    -1,     6,   240,   196,   237,    -1,    -1,    43,
     403,   240,   404,   237,    -1,   404,   241,   405,    -1,   405,
      -1,    10,    -1,   208,    -1,    39,   240,   175,   237,    -1,
      66,   240,   130,   237,    -1,    78,   240,   130,   237,    -1,
      22,   240,   130,   237,    -1,   187,   240,   130,   237,    -1,
      -1,    70,   412,   239,   417,   238,   237,    -1,    -1,   165,
     414,   240,   415,   237,    -1,   415,   241,   416,    -1,   416,
      -1,   135,    -1,   417,   418,    -1,   418,    -1,   419,    -1,
     420,    -1,   413,    -1,     1,    -1,   226,   240,   130,   237,
      -1,   132,   240,   130,   237,    -1,    -1,    28,   422,   239,
     423,   238,   237,    -1,   423,   424,    -1,   424,    -1,   425,
      -1,   426,    -1,     1,    -1,    69,   240,   130,   237,    -1,
     132,   240,   130,   237,    -1,    41,   239,   428,   238,   237,
      -1,   428,   429,    -1,   429,    -1,   430,    -1,     1,    -1,
      69,   240,   130,   237,    -1,    -1,    45,   432,   239,   437,
     238,   237,    -1,    -1,   165,   434,   240,   435,   237,    -1,
     435,   241,   436,    -1,   436,    -1,   135,    -1,   437,   438,
      -1,   438,    -1,   439,    -1,   440,    -1,   433,    -1,     1,
      -1,    99,   240,   130,   237,    -1,   132,   240,   130,   237,
      -1,    46,   239,   442,   238,   237,    -1,   442,   443,    -1,
     443,    -1,   454,    -1,   455,    -1,   457,    -1,   458,    -1,
     459,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     464,    -1,   453,    -1,   466,    -1,   467,    -1,   468,    -1,
     469,    -1,   484,    -1,   471,    -1,   473,    -1,   475,    -1,
     474,    -1,   478,    -1,   472,    -1,   479,    -1,   480,    -1,
     481,    -1,   482,    -1,   483,    -1,   496,    -1,   485,    -1,
     486,    -1,   487,    -1,   492,    -1,   476,    -1,   477,    -1,
     502,    -1,   500,    -1,   501,    -1,   456,    -1,   491,    -1,
     465,    -1,   489,    -1,   490,    -1,   452,    -1,   445,    -1,
     446,    -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,
     451,    -1,   470,    -1,   444,    -1,   488,    -1,     1,    -1,
      93,   240,   109,   237,    -1,    49,   240,   175,   237,    -1,
      48,   240,   246,   237,    -1,    52,   240,   246,   237,    -1,
      53,   240,   109,   237,    -1,    54,   240,   109,   237,    -1,
     229,   240,   175,   237,    -1,   137,   240,   246,   237,    -1,
     162,   240,   175,   237,    -1,    71,   240,   246,   237,    -1,
      63,   240,   175,   237,    -1,    67,   240,   175,   237,    -1,
      33,   240,   175,   237,    -1,    42,   240,   175,   237,    -1,
       8,   240,   175,   237,    -1,    90,   240,   246,   237,    -1,
      89,   240,   109,   237,    -1,    82,   240,   109,   237,    -1,
       9,   240,   246,   237,    -1,   179,   240,   246,   237,    -1,
     178,   240,   246,   237,    -1,    58,   240,   109,   237,    -1,
      75,   240,   175,   237,    -1,    74,   240,   130,   237,    -1,
      68,   240,   175,   237,    -1,   234,   240,   175,   237,    -1,
     170,   240,   175,   237,    -1,   173,   240,   175,   237,    -1,
     174,   240,   175,   237,    -1,   172,   240,   175,   237,    -1,
     172,   240,   176,   237,    -1,   171,   240,   175,   237,    -1,
     171,   240,   176,   237,    -1,   122,   240,   246,   237,    -1,
      17,   240,   246,   237,    -1,   115,   240,   175,   237,    -1,
     123,   240,   246,   237,    -1,   166,   240,   175,   237,    -1,
     107,   240,   175,   237,    -1,   221,   240,   175,   237,    -1,
     117,   240,   175,   237,    -1,    94,   240,   130,   237,    -1,
      34,   240,   109,   237,    -1,    92,   240,   109,   237,    -1,
     227,   240,   175,   237,    -1,    36,   240,   130,   237,    -1,
     219,   240,   130,   237,    -1,   126,   240,   175,   237,    -1,
      31,   240,   175,   237,    -1,   220,   240,   246,   237,    -1,
      -1,   119,   493,   240,   494,   237,    -1,   494,   241,   495,
      -1,   495,    -1,   182,    -1,   185,    -1,   186,    -1,   188,
      -1,   189,    -1,   193,    -1,    59,    -1,   206,    -1,   199,
      -1,   202,    -1,   210,    -1,   207,    -1,   192,    -1,   200,
      -1,   204,    -1,   194,    -1,   216,    -1,   183,    -1,   184,
      -1,   197,    -1,    -1,   116,   497,   240,   498,   237,    -1,
     498,   241,   499,    -1,   499,    -1,   182,    -1,   185,    -1,
     186,    -1,   188,    -1,   189,    -1,   193,    -1,   206,    -1,
      59,    -1,   199,    -1,   202,    -1,   210,    -1,   207,    -1,
     192,    -1,   200,    -1,   204,    -1,   194,    -1,   216,    -1,
     183,    -1,   184,    -1,   197,    -1,    95,   240,   109,   237,
      -1,    96,   240,   109,   237,    -1,    25,   240,   109,   237,
      -1,    19,   239,   504,   238,   237,    -1,   504,   505,    -1,
     505,    -1,   513,    -1,   508,    -1,   509,    -1,   510,    -1,
     511,    -1,   512,    -1,   514,    -1,   515,    -1,   516,    -1,
     507,    -1,   517,    -1,   518,    -1,   519,    -1,   506,    -1,
       1,    -1,    32,   240,   175,   237,    -1,   140,   240,   175,
     237,    -1,    76,   240,   246,   237,    -1,    77,   240,   246,
     237,    -1,    85,   240,   109,   237,    -1,    84,   240,   109,
     237,    -1,   131,   240,   175,   237,    -1,    83,   240,   109,
     237,    -1,    27,   240,   109,   237,    -1,    26,   240,   109,
     237,    -1,   105,   240,   175,   237,    -1,   106,   240,   175,
     237,    -1,   120,   240,   109,   237,    -1,   121,   240,   246,
     237,    -1,   159,   239,   521,   238,   237,    -1,   521,   522,
      -1,   522,    -1,   523,    -1,   524,    -1,   526,    -1,   527,
      -1,   525,    -1,   528,    -1,     1,    -1,    44,   240,   175,
     237,    -1,    62,   240,   175,   237,    -1,    60,   240,   130,
     237,    -1,    79,   240,   246,   237,    -1,    59,   240,   175,
     237,    -1,    61,   240,   175,   237,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   350,   350,   351,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   379,   379,   380,   384,
     388,   392,   396,   400,   406,   406,   407,   408,   409,   410,
     417,   420,   420,   421,   421,   421,   423,   429,   436,   438,
     438,   439,   439,   440,   440,   441,   441,   442,   442,   443,
     443,   444,   444,   445,   445,   446,   447,   450,   451,   453,
     453,   454,   460,   468,   468,   469,   475,   483,   522,   581,
     609,   617,   632,   647,   656,   670,   679,   707,   737,   760,
     769,   771,   771,   772,   772,   773,   773,   775,   784,   793,
     805,   806,   806,   808,   808,   809,   811,   818,   818,   828,
     829,   831,   831,   832,   832,   834,   839,   842,   848,   847,
     853,   853,   854,   858,   862,   866,   870,   874,   878,   889,
     888,   986,   986,   987,   987,   987,   988,   988,   988,   989,
     989,   989,   991,  1000,  1037,  1049,  1060,  1102,  1112,  1111,
    1117,  1117,  1118,  1122,  1126,  1130,  1134,  1138,  1142,  1146,
    1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,
    1190,  1194,  1201,  1200,  1206,  1206,  1207,  1211,  1215,  1219,
    1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,  1255,  1259,
    1263,  1267,  1271,  1275,  1279,  1290,  1289,  1339,  1339,  1340,
    1341,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1351,  1352,  1354,  1363,  1369,  1375,  1381,  1387,
    1393,  1399,  1405,  1411,  1417,  1424,  1430,  1436,  1446,  1445,
    1462,  1461,  1466,  1466,  1467,  1471,  1475,  1483,  1483,  1484,
    1484,  1484,  1484,  1484,  1486,  1486,  1488,  1488,  1490,  1504,
    1524,  1533,  1546,  1545,  1614,  1614,  1615,  1615,  1615,  1615,
    1616,  1616,  1616,  1617,  1617,  1619,  1654,  1667,  1676,  1688,
    1687,  1691,  1691,  1692,  1696,  1700,  1704,  1708,  1712,  1716,
    1720,  1724,  1731,  1750,  1760,  1774,  1773,  1789,  1789,  1790,
    1790,  1790,  1790,  1792,  1801,  1816,  1829,  1831,  1831,  1832,
    1832,  1834,  1850,  1849,  1865,  1865,  1866,  1866,  1866,  1866,
    1868,  1877,  1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,
    1922,  1926,  1930,  1934,  1938,  1942,  1952,  1951,  1968,  1968,
    1969,  1969,  1969,  1971,  1978,  1977,  1983,  1983,  1984,  1988,
    1992,  1996,  2000,  2004,  2008,  2012,  2016,  2020,  2030,  2029,
    2080,  2080,  2081,  2081,  2081,  2082,  2082,  2083,  2083,  2083,
    2084,  2084,  2084,  2085,  2085,  2086,  2088,  2097,  2106,  2132,
    2150,  2168,  2174,  2178,  2187,  2186,  2190,  2190,  2191,  2195,
    2201,  2212,  2223,  2234,  2243,  2262,  2261,  2327,  2326,  2330,
    2330,  2331,  2337,  2337,  2338,  2338,  2338,  2338,  2340,  2359,
    2369,  2368,  2393,  2393,  2394,  2394,  2394,  2396,  2402,  2411,
    2413,  2413,  2414,  2414,  2416,  2435,  2434,  2482,  2481,  2485,
    2485,  2486,  2492,  2492,  2493,  2493,  2493,  2493,  2495,  2501,
    2510,  2513,  2513,  2514,  2514,  2515,  2515,  2516,  2516,  2517,
    2517,  2518,  2518,  2519,  2519,  2520,  2520,  2521,  2521,  2522,
    2522,  2523,  2523,  2524,  2524,  2525,  2525,  2526,  2526,  2527,
    2528,  2528,  2529,  2529,  2530,  2530,  2531,  2531,  2532,  2532,
    2533,  2534,  2534,  2535,  2536,  2537,  2537,  2538,  2538,  2539,
    2540,  2540,  2541,  2541,  2542,  2542,  2543,  2546,  2551,  2557,
    2563,  2569,  2574,  2579,  2584,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2624,  2629,  2634,  2639,  2644,  2649,  2655,  2666,
    2671,  2680,  2685,  2690,  2695,  2700,  2705,  2708,  2713,  2716,
    2721,  2726,  2731,  2736,  2741,  2746,  2751,  2756,  2761,  2772,
    2777,  2782,  2787,  2796,  2805,  2810,  2815,  2821,  2820,  2825,
    2825,  2826,  2829,  2832,  2835,  2838,  2841,  2844,  2847,  2850,
    2853,  2856,  2859,  2862,  2865,  2868,  2871,  2874,  2877,  2880,
    2883,  2889,  2888,  2893,  2893,  2894,  2897,  2900,  2903,  2906,
    2909,  2912,  2915,  2918,  2921,  2924,  2927,  2930,  2933,  2936,
    2939,  2942,  2945,  2948,  2951,  2956,  2961,  2966,  2975,  2978,
    2978,  2979,  2980,  2980,  2981,  2981,  2982,  2982,  2983,  2984,
    2984,  2985,  2986,  2986,  2987,  2987,  2989,  2994,  2999,  3004,
    3009,  3014,  3019,  3024,  3029,  3034,  3039,  3044,  3049,  3054,
    3062,  3065,  3065,  3066,  3066,  3067,  3068,  3068,  3069,  3070,
    3072,  3078,  3084,  3093,  3107,  3113
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BYTES", "KBYTES", "MBYTES", "GBYTES", "TBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CONNECT", "CONNECTFREQ",
  "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
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
  "T_CALLERID", "T_CCONN", "T_CCONN_FULL", "T_SSL_CIPHER_LIST", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE",
  "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SET",
  "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS", "T_WALLOP",
  "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
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
  "class_max_local", "class_max_ident", "class_sendq", "class_recvq",
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
  "general_default_floodcount", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels",
  "channel_restrict_channels", "channel_knock_delay",
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
     485,   486,   487,   488,   489,   490,   491,    59,   125,   123,
      61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   242,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   245,   245,   246,   246,
     246,   246,   246,   246,   247,   247,   248,   248,   248,   248,
     249,   250,   250,   251,   251,   251,   252,   253,   254,   255,
     255,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   257,   258,   259,
     259,   260,   260,   261,   261,   262,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   277,   278,   278,   278,   278,   279,   280,   281,
     282,   283,   283,   284,   284,   284,   285,   287,   286,   288,
     288,   289,   289,   289,   289,   290,   291,   291,   293,   292,
     294,   294,   295,   295,   295,   295,   295,   295,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   301,   302,   303,   304,   305,   307,   306,
     308,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   311,   310,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   315,   314,   316,   316,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   333,   332,
     335,   334,   336,   336,   337,   337,   337,   338,   338,   339,
     339,   339,   339,   339,   341,   340,   342,   342,   343,   343,
     344,   345,   347,   346,   348,   348,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   350,   351,   352,   353,   355,
     354,   356,   356,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   358,   359,   360,   362,   361,   363,   363,   364,
     364,   364,   364,   365,   366,   367,   368,   369,   369,   370,
     370,   371,   373,   372,   374,   374,   375,   375,   375,   375,
     376,   377,   379,   378,   380,   380,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   383,   382,   384,   384,
     385,   385,   385,   386,   388,   387,   389,   389,   390,   390,
     390,   390,   390,   390,   390,   390,   390,   390,   392,   391,
     393,   393,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   395,   396,   397,   398,
     399,   400,   401,   401,   403,   402,   404,   404,   405,   405,
     406,   407,   408,   409,   410,   412,   411,   414,   413,   415,
     415,   416,   417,   417,   418,   418,   418,   418,   419,   420,
     422,   421,   423,   423,   424,   424,   424,   425,   426,   427,
     428,   428,   429,   429,   430,   432,   431,   434,   433,   435,
     435,   436,   437,   437,   438,   438,   438,   438,   439,   440,
     441,   442,   442,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   473,   474,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   493,   492,   494,
     494,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   497,   496,   498,   498,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   500,   501,   502,   503,   504,
     504,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   521,   522,   522,   522,   522,   522,   522,   522,
     523,   524,   525,   526,   527,   528
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
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   348,   400,     0,
     415,     0,   252,   385,   228,     0,     0,   129,   285,     0,
       0,   302,   326,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   604,   600,   592,   593,   594,   595,   596,
     591,   597,   598,   599,   601,   602,   603,     0,     0,     0,
     413,     0,     0,   411,   412,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   484,   476,   477,   478,   479,   480,   481,   482,
     475,   443,   433,   434,   470,   435,   436,   437,   438,   439,
     440,   441,   442,   472,   444,   445,   446,   447,   483,   449,
     454,   450,   452,   451,   465,   466,   453,   455,   456,   457,
     458,   459,   448,   461,   462,   463,   485,   473,   474,   471,
     464,   460,   468,   469,   467,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,   622,   623,   624,   627,   625,   626,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    63,    64,    62,
      59,    58,    65,    51,    61,    54,    55,    56,    52,    60,
      57,    53,     0,     0,   300,     0,     0,   298,   299,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   212,   200,
     201,   204,     0,     0,     0,     0,     0,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,   356,   358,   357,   360,   364,   361,   362,   363,
     359,   406,     0,     0,     0,   403,   404,   405,     0,     0,
     410,   427,     0,     0,   417,   426,     0,   423,   424,   425,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,   263,
     259,   260,   261,   262,   397,     0,   387,     0,   396,     0,
     393,   394,   395,     0,   230,     0,     0,     0,   240,     0,
     238,   239,   241,   242,   105,     0,     0,   101,     0,    45,
       0,     0,     0,    41,     0,     0,     0,   172,     0,     0,
       0,   148,     0,     0,   132,   133,   134,   135,   138,   139,
     137,   136,   140,     0,     0,     0,     0,     0,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   621,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
     312,     0,     0,   305,   306,   307,   308,     0,     0,   334,
       0,   329,   330,   331,     0,     0,   297,     0,     0,     0,
      90,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
       0,     0,     0,   402,     0,   409,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   430,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   392,   243,     0,     0,     0,     0,     0,   237,
       0,   100,     0,     0,     0,    40,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   292,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
       0,    70,    75,    76,     0,    74,     0,     0,     0,     0,
       0,    48,   309,     0,     0,     0,     0,   304,   332,     0,
       0,     0,   328,     0,   296,    99,    98,    97,   615,   614,
     606,    26,    26,    26,    26,    26,    28,    27,   608,   609,
     613,   611,   610,   616,   617,   618,   619,   612,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   349,
       0,     0,   401,   414,     0,     0,     0,   416,   501,   505,
     521,   587,   535,   499,   529,   532,   500,   489,   488,   490,
     491,   492,   508,   497,   498,   511,   496,   510,   509,   504,
     503,   502,   530,   487,   528,   585,   586,   525,   522,   572,
     565,   582,   583,   566,   567,   568,   569,   577,   570,   580,
     584,   573,   578,   574,   579,   571,   576,   575,   581,     0,
     564,   527,   547,   541,   558,   559,   542,   543,   544,   545,
     553,   546,   556,   560,   549,   554,   550,   555,   548,   552,
     551,   557,     0,   540,   520,   523,   534,   494,   495,   524,
     513,   518,   519,   516,   517,   514,   515,   507,   506,   533,
     536,   526,   531,   493,   512,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,   386,     0,     0,
       0,   248,   244,   247,   229,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   286,
     630,   634,   632,   635,   631,   633,    83,    89,    81,    85,
      84,    78,    77,    79,    67,     0,    68,     0,    82,    80,
      88,    86,    87,     0,     0,     0,   303,     0,     0,   327,
     301,    29,    30,    31,    32,    33,   225,   226,   218,   220,
     222,   221,   219,   214,   227,   217,   215,   216,    34,    34,
      34,    36,    35,   223,   224,   370,   372,   373,   383,   380,
     378,   379,     0,   377,   367,   381,   382,   366,   371,   369,
     384,   368,   407,   408,   428,   429,   421,     0,   420,   562,
       0,   538,     0,   267,   268,   277,   274,   279,   276,   275,
     281,   278,   280,   273,     0,   272,   266,   284,   283,   282,
     265,   399,   391,     0,   390,   398,   235,   236,   234,     0,
     233,   251,   250,     0,     0,     0,   114,     0,     0,     0,
       0,   109,   147,   145,   187,   184,   183,   176,   178,   194,
     188,   191,   186,   177,   192,   180,   189,   193,   181,   190,
     185,   179,   182,     0,   175,   142,   144,   146,   158,   152,
     169,   170,   153,   154,   155,   156,   164,   157,   167,   171,
     160,   165,   161,   166,   159,   163,   162,   168,     0,   151,
     143,   294,   295,   293,    69,    73,   310,   316,   322,   325,
     318,   324,   319,   323,   321,   317,   320,     0,   315,   311,
     333,   338,   344,   347,   340,   346,   341,   345,   343,   339,
     342,     0,   337,    37,    38,    39,   375,     0,   418,     0,
     563,   539,   270,     0,   388,     0,   231,     0,   249,   246,
     245,     0,     0,     0,     0,   108,   173,     0,   149,     0,
     313,     0,   335,     0,   376,   419,   271,   389,   232,   115,
     124,   127,   126,   123,   128,   125,   122,     0,   121,   117,
     116,   174,   150,   314,   336,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   796,   797,  1041,  1042,    25,   238,   239,
     240,   241,    26,   275,   276,   277,   278,   760,   761,   764,
     765,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    27,    71,    72,    73,    74,    75,
      28,   230,   231,   232,   233,   234,   970,   971,   972,   973,
     974,  1108,  1237,  1238,    29,    60,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   733,  1158,  1159,   522,   729,
    1133,  1134,    30,    49,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
      31,    57,   488,   714,  1099,  1100,   489,   490,   491,  1105,
     962,   963,   492,   493,    32,    55,   464,   465,   466,   467,
     468,   469,   470,   700,  1084,  1085,   471,   472,   473,    33,
      61,   527,   528,   529,   530,   531,    34,   296,   297,   298,
      35,    64,   562,   563,   564,   565,   566,   774,  1177,  1178,
      36,    65,   570,   571,   572,   573,   780,  1191,  1192,    37,
      50,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   619,  1052,  1053,   376,   377,   378,   379,   380,    38,
      56,   478,   709,  1093,  1094,   479,   480,   481,   482,    39,
      51,   384,   385,   386,   387,    40,   112,   113,   114,    41,
      53,   395,   638,  1067,  1068,   396,   397,   398,   399,    42,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   433,   922,   923,   221,   431,   899,   900,   222,   223,
     224,    43,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    44,   251,
     252,   253,   254,   255,   256,   257,   258
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -801
static const yytype_int16 yypact[] =
{
    -801,   615,  -801,  -218,  -226,  -198,  -801,  -801,  -801,  -188,
    -801,  -181,  -801,  -801,  -801,  -178,  -175,  -801,  -801,  -168,
    -162,  -801,  -801,  -160,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,     7,   821,  -145,
    -140,  -118,     4,  -116,   375,  -105,   -75,   -64,    64,   103,
     -62,   -56,   306,   424,   -54,   -49,    47,  -163,  -149,   -44,
     -42,    10,  -801,  -801,  -801,  -801,  -801,   -39,   -23,   -16,
     -13,    11,    58,    66,    68,    71,    89,   104,   105,   112,
     129,     5,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,   611,   348,    23,
    -801,   137,    16,  -801,  -801,   181,  -801,   139,   146,   148,
     149,   150,   154,   158,   159,   162,   163,   164,   165,   167,
     170,   173,   175,   180,   190,   191,   192,   194,   195,   201,
     204,   211,   212,   214,   215,   216,   218,   219,  -801,   220,
    -801,   221,   222,   226,   235,   239,   240,   241,   248,   253,
     255,   256,   260,   262,   264,   269,   270,   271,   273,   276,
      99,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   339,    65,   267,    18,   277,
      48,  -801,  -801,  -801,    28,   123,   278,   279,    74,  -801,
    -801,  -801,   379,   313,  -801,   280,   281,   284,   287,   288,
     289,     8,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   184,
     290,   291,   292,   294,   296,   298,   299,   300,   302,   303,
     304,   312,   315,   316,   317,   143,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,   136,    15,  -801,   319,    59,  -801,  -801,  -801,
     151,   346,   430,   324,  -801,   186,   453,   388,   455,   455,
     458,   463,   464,   399,   401,   468,   455,   404,   405,   344,
    -801,   345,   347,   349,   350,   352,   353,   357,   358,   359,
     361,   363,   366,   368,   370,   373,   236,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,   380,   378,   384,   385,   386,  -801,   387,   389,
     393,   396,   400,   408,   409,   410,    20,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,   411,   413,    44,  -801,  -801,  -801,   454,   382,
    -801,  -801,   419,   422,  -801,  -801,    55,  -801,  -801,  -801,
     470,   455,   455,   477,   488,   489,   557,   498,   492,   455,
     493,   455,   561,   563,   564,   500,   501,   502,   455,   548,
     504,   571,   572,   455,   573,   574,   556,   578,   579,   514,
     515,   452,   526,   465,   455,   455,   529,   455,   531,   536,
     537,  -148,    34,   540,   542,   455,   455,   589,   455,   546,
     549,   550,   551,   490,  -801,   499,   497,   505,  -801,   506,
     507,   508,   509,   510,    79,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   512,  -801,   513,  -801,    37,
    -801,  -801,  -801,   517,  -801,   516,   518,   520,  -801,    14,
    -801,  -801,  -801,  -801,  -801,   565,   522,  -801,   523,  -801,
     613,   625,   524,  -801,   527,   530,   532,  -801,   533,   553,
     554,  -801,   559,   210,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   534,   566,   567,   569,    24,  -801,  -801,
    -801,  -801,   582,   588,   636,   592,   594,   455,   539,  -801,
    -801,   647,   614,   658,   666,   671,   680,   681,   683,    85,
     118,   685,   686,   632,   695,   696,   593,  -801,   599,   591,
    -801,   600,     3,  -801,  -801,  -801,  -801,   601,   603,  -801,
      21,  -801,  -801,  -801,   714,   609,  -801,   612,   622,   626,
    -801,   630,   631,   633,   331,   638,   640,   643,   644,   646,
     648,   649,   650,   652,   653,   654,  -801,  -801,   741,   743,
     455,   753,   764,   775,   783,   763,   785,   786,   455,   455,
     787,   787,   662,  -801,  -801,   770,   120,   771,   727,   663,
     777,   778,   779,   780,   802,   782,   784,   788,   676,  -801,
     789,   790,   678,  -801,   679,  -801,   791,   792,   677,   687,
    -801,   688,   691,   692,   693,   694,   697,   698,   699,   700,
     701,   702,   703,   706,   707,   708,   709,   710,   711,   712,
     713,   716,   717,   718,   719,   720,   721,   722,   723,   725,
     726,   728,   598,   729,   635,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   742,   744,   745,   746,
     747,   748,   749,   750,   751,   752,  -801,  -801,   793,   757,
     724,   803,   842,   848,   850,   860,   754,  -801,   862,   755,
     863,   759,  -801,  -801,   758,   864,   867,   890,   765,  -801,
     766,  -801,    39,   767,   768,  -801,  -801,   870,   826,   769,
     876,   877,   878,   772,   880,   774,  -801,  -801,   883,   884,
     885,   781,  -801,   794,   795,   796,   797,   798,   799,  -801,
     800,   801,   804,   805,   806,   807,   808,   809,  -801,  -801,
    -223,  -801,  -801,  -801,  -208,  -801,   810,   811,   812,   813,
     814,  -801,  -801,   886,   815,   887,   816,  -801,  -801,   889,
     817,   819,  -801,   822,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,   455,   455,   455,   455,   455,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   823,
     824,   825,   827,   828,   829,   830,   831,   832,   833,   834,
     835,    41,   836,   837,  -801,   838,   839,   840,   841,   843,
      -3,   844,   845,   846,   847,   849,   851,   852,   853,  -801,
     854,   855,  -801,  -801,   856,   857,   888,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -207,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -191,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,   858,   859,   634,   861,   865,
     866,   868,   869,  -801,   871,   891,   872,  -801,   -24,   873,
     874,   899,   875,  -801,  -801,  -801,   881,   818,  -801,   879,
      61,  -801,  -801,  -801,  -801,  -801,  -801,   892,   893,   503,
     894,   895,   896,   672,   897,  -801,   898,   900,   901,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,    85,  -801,   118,  -801,  -801,
    -801,  -801,  -801,   902,   433,   903,  -801,   904,   519,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,   787,   787,
     787,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -165,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -144,  -801,  -801,
     598,  -801,   635,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,   -78,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   -76,  -801,  -801,  -801,  -801,  -801,   -18,
    -801,  -801,  -801,   911,   890,   905,  -801,   909,   882,   -97,
     906,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,    42,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,    84,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,   101,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,   102,  -801,  -801,  -801,  -801,  -801,    -3,  -801,   888,
    -801,  -801,  -801,   634,  -801,   891,  -801,   -24,  -801,  -801,
    -801,   907,   325,   908,   910,  -801,  -801,   503,  -801,   672,
    -801,   433,  -801,   519,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,   134,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,   325,  -801
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -801,  -801,  -801,  -436,  -306,  -800,  -610,  -801,  -801,   912,
    -801,  -801,  -801,  -801,   913,  -801,  -801,  -801,    17,  -801,
      22,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,   950,  -801,  -801,  -801,
    -801,  -801,   916,  -801,  -801,  -801,  -801,    54,  -801,  -801,
    -801,  -801,  -801,  -221,  -801,  -801,  -801,   541,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -192,  -801,  -801,
    -801,  -189,  -801,  -801,  -801,   704,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -177,  -801,   596,  -801,  -801,
    -801,   -52,  -801,  -801,  -801,  -801,  -801,   623,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -106,  -801,  -801,  -801,  -801,
    -801,  -801,   577,  -801,  -801,  -801,  -801,  -801,   914,  -801,
    -801,  -801,  -801,   538,  -801,  -801,  -801,  -801,  -801,  -158,
    -801,  -801,  -801,   543,  -801,  -801,  -801,  -801,  -124,  -801,
    -801,  -801,   760,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,   -96,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,   -98,  -801,   641,  -801,  -801,  -801,
    -801,  -801,   773,  -801,  -801,  -801,  -801,  1000,  -801,  -801,
    -801,  -801,  -801,  -801,   -85,  -801,   756,  -801,  -801,  -801,
    -801,   945,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,    45,  -801,  -801,  -801,    51,  -801,  -801,
    -801,  -801,  -801,  1032,  -801,  -801,  -801,  -801,  -801,  -801,
    -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,  -801,
     915,  -801,  -801,  -801,  -801,  -801,  -801
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     822,   823,   585,   586,   558,   110,    76,  1050,    67,   244,
     593,    67,   821,    47,  1004,   483,   567,   110,  1005,    45,
      46,   352,   567,   353,   381,   523,   354,   682,   683,  1006,
    1069,    77,    78,  1007,  1070,  1096,    68,    79,   474,    68,
     966,    48,   355,   524,    69,   381,  1071,    69,   294,   228,
    1072,    52,   245,  1038,  1039,  1040,   391,   484,    54,   356,
     294,    58,   966,   357,    59,   228,   474,   246,   247,   248,
     249,    62,  1196,   111,   299,   235,  1197,    63,   485,    66,
     455,    80,    81,   486,   358,   111,   359,   250,    82,    83,
      84,   300,   382,  1198,   107,   642,   643,  1199,   360,   108,
     116,   456,   559,   650,   235,   652,    70,   117,   118,    70,
      85,    86,   659,   382,   568,  1213,   119,   664,   457,   361,
     568,   109,   458,   115,   120,    87,    88,   525,   675,   676,
     121,   678,   122,   123,   225,   124,    89,   558,   967,   688,
     689,   125,   691,   487,   259,    90,   295,   126,   127,   362,
     821,   128,   129,   130,   392,   383,   526,   131,   295,  1202,
     967,  1204,   132,  1203,   226,  1205,   133,   134,   560,   475,
     135,   236,   260,   136,   137,   227,   383,   242,   363,  1097,
     569,   138,   391,   243,  1098,   292,   569,   393,   139,   140,
     293,   141,   142,   143,   144,   145,   301,   475,   302,   237,
     236,   305,   476,   459,   968,  1051,   146,   364,   261,   684,
     685,   504,   460,   461,   147,   148,   149,   306,   150,  1206,
     394,   151,   152,  1207,   307,   153,   968,   308,   237,   561,
     476,   748,   505,   758,   759,   559,   154,   321,  1193,  1194,
    1195,   776,   262,   319,   263,   264,   538,   462,   303,   506,
     365,   309,   718,   507,   389,   494,   322,   323,   628,   781,
     324,   155,   741,   477,   498,   156,   762,   763,   483,   157,
     158,   159,   160,   161,   969,   711,   229,   162,   163,  1216,
     392,   577,   632,  1217,  -107,   265,   496,   266,   267,   268,
     269,   477,   229,   639,   811,   581,   969,   575,   310,  1110,
    -107,   560,   819,   820,   270,   463,   311,   244,   312,   508,
     484,   313,   502,   393,   523,   826,   827,   706,   164,   165,
     166,  1218,   325,   326,   327,  1219,   167,   328,   168,   314,
     271,   485,   524,   169,   509,   329,   486,   453,  1220,  1222,
     455,   272,  1221,  1223,   315,   316,   394,   330,   331,   352,
     245,   353,   317,   510,   354,  1021,  1022,  1023,  1024,  1025,
     499,   456,   561,   332,   333,   246,   247,   248,   249,   318,
     355,  1245,  1230,   273,   274,  1246,   116,   388,   457,   400,
     504,   556,   458,   117,   118,   250,   401,   356,   402,   403,
     404,   357,   119,   334,   405,  1231,   487,  1232,   406,   407,
     120,   505,   408,   409,   410,   411,   121,   412,   122,   123,
     413,   124,   358,   414,   359,   415,   525,   125,   506,   511,
     416,   540,   507,   126,   127,   259,   360,   128,   129,   130,
     417,   418,   419,   131,   420,   421,   512,   335,   132,  1233,
     584,   422,   133,   134,   423,   526,   135,   361,   735,   136,
     137,   424,   425,   260,   426,   427,   428,   138,   429,   430,
     432,   434,   435,   459,   139,   140,   436,   141,   142,   143,
     144,   145,   460,   461,   612,   437,   578,   362,   508,   438,
     439,   440,   146,   791,   792,   793,   794,   795,   441,   261,
     147,   148,   149,   442,   150,   443,   444,   151,   152,  1214,
     445,   153,   446,   509,   447,  1167,   363,   462,  1114,   448,
     449,   450,   154,   451,  1234,  1235,   452,   495,   500,   501,
     532,   533,   510,   262,   534,   263,   264,   535,   536,   537,
     541,   542,   543,  1115,   544,   364,   545,   155,   546,   547,
     548,   156,   549,   550,   551,   157,   158,   159,   160,   161,
    1116,  1236,   552,   162,   163,   553,   554,   555,  1117,   574,
     579,   580,   582,   583,   584,   463,   265,   587,   266,   267,
     268,   269,   588,   589,   590,  1118,   591,   592,   365,   594,
     595,   596,   597,  1168,   634,   270,   644,   598,   511,   599,
     600,  1181,   601,   602,   164,   165,   166,   603,   604,   605,
    1119,   606,   167,   607,   168,   512,   608,  1120,   609,   169,
     610,   271,   321,   611,  1169,     2,     3,   614,   615,   635,
       4,  1121,   272,  1170,   616,   617,   618,   620,   648,   621,
    1171,   322,   323,   622,     5,   324,   623,     6,     7,  1122,
     624,  1123,  1124,     8,  1172,   641,  1173,  1174,   625,   626,
     627,   630,  1075,   631,   273,   274,     9,   879,  1175,   636,
      10,    11,   637,   645,   646,  1176,   647,   649,   651,  1182,
     653,    12,   654,   655,  1076,   656,   657,   658,   660,   661,
     662,   663,   665,   666,  1077,    13,   667,   668,   669,   670,
     671,  1078,   672,  1125,   902,    14,    15,   325,   326,   327,
    1183,   673,   328,  1126,   677,   674,   679,  1079,  1127,  1184,
     329,   680,   681,    16,  1128,   686,  1185,   687,  1129,   690,
    1130,   692,   330,   331,   693,   694,   695,   696,  1131,    17,
    1186,  1138,  1187,  1188,  1080,  1132,   697,   698,   332,   333,
     720,   768,  1081,   723,  1189,   699,   701,   702,   703,   704,
     705,  1190,   708,   710,   713,   724,   715,   743,   716,   721,
     717,   725,   722,   744,   726,    18,   745,   746,   334,   747,
     727,   737,   728,   730,    19,    20,   749,   750,    21,    22,
     880,   881,   882,   883,   884,  1082,   885,   886,   752,   751,
     887,   888,   889,   731,   732,   890,   753,   891,   892,   734,
     893,   754,   894,  1083,   895,   896,   738,   739,   897,   740,
     755,   756,   335,   757,   898,   766,   767,   903,   904,   905,
     906,   907,    76,   908,   909,   769,   770,   910,   911,   912,
     771,   773,   913,    23,   914,   915,   772,   916,   778,   917,
     775,   918,   919,   779,   783,   920,   784,    77,    78,   785,
     809,   921,   810,    79,  1139,  1140,  1141,  1142,  1143,   786,
    1144,  1145,   812,   787,  1146,  1147,  1148,   788,   789,  1149,
     790,  1150,  1151,   813,  1152,   798,  1153,   799,  1154,  1155,
     800,   801,  1156,   802,   814,   803,   804,   805,  1157,   806,
     807,   808,   815,   816,   817,   818,   821,    80,    81,   824,
     825,   828,   829,   830,    82,    83,    84,   831,   832,   833,
     834,   835,   836,   839,   837,   842,   843,   846,   838,   840,
     841,   844,   845,   945,   847,   848,    85,    86,   849,   850,
     851,   852,   946,   948,   853,   854,   855,   856,   857,   858,
     859,    87,    88,   860,   861,   862,   863,   864,   865,   866,
     867,   949,    89,   868,   869,   870,   871,   872,   873,   874,
     875,    90,   876,   877,   947,   878,   901,   924,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,   950,   935,
     951,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     952,   953,   954,   956,   959,   955,   957,   960,   958,   961,
     977,   978,   964,   965,   975,   976,   980,   981,   982,   979,
     984,   985,   983,   986,   987,   988,  1013,  1015,   989,  1017,
    1208,   304,  1164,  1066,  1111,  1247,  1092,  1242,  1241,  1165,
    1228,   990,   991,   992,   993,   994,   995,   996,   997,  1211,
     613,   998,   999,  1000,  1001,  1002,  1003,  1008,  1009,  1010,
    1011,  1012,  1209,  1016,   736,  1014,  1019,  1018,  1107,  1020,
    1026,  1027,  1028,  1243,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1043,  1044,  1045,  1046,  1047,  1048,  1103,
    1049,  1054,  1055,  1056,  1057,   719,  1058,   707,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1073,  1074,  1226,  1086,  1244,
     777,  1224,  1087,  1088,   742,  1089,  1090,  1227,  1091,  1095,
    1101,  1102,   390,   782,  1225,   454,  1104,  1201,  1106,  1109,
     712,  1200,  1212,   320,     0,     0,   629,     0,     0,  1112,
    1113,  1135,  1136,  1137,  1160,  1161,     0,  1162,  1163,  1166,
    1179,  1180,  1210,  1215,  1229,  1239,   497,  1240,     0,     0,
     503,     0,   640,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     576
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-801))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     610,   611,   308,   309,     1,     1,     1,    10,     1,     1,
     316,     1,   109,   239,   237,     1,     1,     1,   241,   237,
     238,     1,     1,     3,     1,     1,     6,   175,   176,   237,
     237,    26,    27,   241,   241,    59,    29,    32,     1,    29,
       1,   239,    22,    19,    37,     1,   237,    37,     1,     1,
     241,   239,    44,    12,    13,    14,     1,    43,   239,    39,
       1,   239,     1,    43,   239,     1,     1,    59,    60,    61,
      62,   239,   237,    69,   237,     1,   241,   239,    64,   239,
       1,    76,    77,    69,    64,    69,    66,    79,    83,    84,
      85,   240,    69,   237,   239,   401,   402,   241,    78,   239,
       1,    22,    99,   409,     1,   411,    99,     8,     9,    99,
     105,   106,   418,    69,    99,   212,    17,   423,    39,    99,
      99,   239,    43,   239,    25,   120,   121,   103,   434,   435,
      31,   437,    33,    34,   239,    36,   131,     1,    99,   445,
     446,    42,   448,   129,     1,   140,    99,    48,    49,   129,
     109,    52,    53,    54,    99,   132,   132,    58,    99,   237,
      99,   237,    63,   241,   239,   241,    67,    68,   165,   132,
      71,    97,    29,    74,    75,   239,   132,   239,   158,   203,
     165,    82,     1,   239,   208,   239,   165,   132,    89,    90,
     239,    92,    93,    94,    95,    96,   240,   132,   240,   125,
      97,   240,   165,   124,   165,   208,   107,   187,    65,   175,
     176,     1,   133,   134,   115,   116,   117,   240,   119,   237,
     165,   122,   123,   241,   240,   126,   165,   240,   125,   226,
     165,   537,    22,   148,   149,    99,   137,     1,  1038,  1039,
    1040,   238,    99,   238,   101,   102,   238,   168,   238,    39,
     230,   240,   238,    43,   238,   237,    20,    21,   238,   238,
      24,   162,   238,   226,   236,   166,   148,   149,     1,   170,
     171,   172,   173,   174,   235,   238,   228,   178,   179,   237,
      99,   130,   238,   241,   236,   142,   238,   144,   145,   146,
     147,   226,   228,   238,   600,   109,   235,   238,   240,   238,
     236,   165,   608,   609,   161,   226,   240,     1,   240,    99,
      43,   240,   238,   132,     1,   195,   196,   238,   219,   220,
     221,   237,    86,    87,    88,   241,   227,    91,   229,   240,
     187,    64,    19,   234,   124,    99,    69,   238,   237,   237,
       1,   198,   241,   241,   240,   240,   165,   111,   112,     1,
      44,     3,   240,   143,     6,   791,   792,   793,   794,   795,
     237,    22,   226,   127,   128,    59,    60,    61,    62,   240,
      22,   237,    47,   230,   231,   241,     1,   240,    39,   240,
       1,   238,    43,     8,     9,    79,   240,    39,   240,   240,
     240,    43,    17,   157,   240,    70,   129,    72,   240,   240,
      25,    22,   240,   240,   240,   240,    31,   240,    33,    34,
     240,    36,    64,   240,    66,   240,   103,    42,    39,   209,
     240,   237,    43,    48,    49,     1,    78,    52,    53,    54,
     240,   240,   240,    58,   240,   240,   226,   201,    63,   114,
     109,   240,    67,    68,   240,   132,    71,    99,   238,    74,
      75,   240,   240,    29,   240,   240,   240,    82,   240,   240,
     240,   240,   240,   124,    89,    90,   240,    92,    93,    94,
      95,    96,   133,   134,   238,   240,   130,   129,    99,   240,
     240,   240,   107,   152,   153,   154,   155,   156,   240,    65,
     115,   116,   117,   240,   119,   240,   240,   122,   123,  1109,
     240,   126,   240,   124,   240,    72,   158,   168,     5,   240,
     240,   240,   137,   240,   189,   190,   240,   240,   240,   240,
     240,   240,   143,    99,   240,   101,   102,   240,   240,   240,
     240,   240,   240,    30,   240,   187,   240,   162,   240,   240,
     240,   166,   240,   240,   240,   170,   171,   172,   173,   174,
      47,   226,   240,   178,   179,   240,   240,   240,    55,   240,
     130,   237,   109,   175,   109,   226,   142,   109,   144,   145,
     146,   147,   109,   109,   175,    72,   175,   109,   230,   175,
     175,   237,   237,   150,   130,   161,   109,   240,   209,   240,
     240,    72,   240,   240,   219,   220,   221,   240,   240,   240,
      97,   240,   227,   240,   229,   226,   240,   104,   240,   234,
     240,   187,     1,   240,   181,     0,     1,   237,   240,   237,
       5,   118,   198,   190,   240,   240,   240,   240,   130,   240,
     197,    20,    21,   240,    19,    24,   240,    22,    23,   136,
     240,   138,   139,    28,   211,   175,   213,   214,   240,   240,
     240,   240,    18,   240,   230,   231,    41,    59,   225,   240,
      45,    46,   240,   175,   175,   232,   109,   175,   175,   150,
     109,    56,   109,   109,    40,   175,   175,   175,   130,   175,
     109,   109,   109,   109,    50,    70,   130,   109,   109,   175,
     175,    57,   240,   190,    59,    80,    81,    86,    87,    88,
     181,   175,    91,   200,   175,   240,   175,    73,   205,   190,
      99,   175,   175,    98,   211,   175,   197,   175,   215,   130,
     217,   175,   111,   112,   175,   175,   175,   237,   225,   114,
     211,    59,   213,   214,   100,   232,   237,   240,   127,   128,
     175,   109,   108,   130,   225,   240,   240,   240,   240,   240,
     240,   232,   240,   240,   237,   130,   240,   175,   240,   237,
     240,   237,   239,   175,   237,   150,   130,   175,   157,   175,
     240,   237,   240,   240,   159,   160,   237,   130,   163,   164,
     182,   183,   184,   185,   186,   151,   188,   189,   130,   175,
     192,   193,   194,   240,   240,   197,   130,   199,   200,   240,
     202,   130,   204,   169,   206,   207,   240,   240,   210,   240,
     130,   130,   201,   130,   216,   130,   130,   182,   183,   184,
     185,   186,     1,   188,   189,   130,   130,   192,   193,   194,
     237,   240,   197,   218,   199,   200,   237,   202,   237,   204,
     240,   206,   207,   240,   130,   210,   237,    26,    27,   237,
     109,   216,   109,    32,   182,   183,   184,   185,   186,   237,
     188,   189,   109,   237,   192,   193,   194,   237,   237,   197,
     237,   199,   200,   109,   202,   237,   204,   237,   206,   207,
     237,   237,   210,   237,   109,   237,   237,   237,   216,   237,
     237,   237,   109,   130,   109,   109,   109,    76,    77,   237,
     130,   130,   175,   240,    83,    84,    85,   130,   130,   130,
     130,   109,   130,   237,   130,   237,   237,   240,   130,   130,
     130,   130,   130,   130,   237,   237,   105,   106,   237,   237,
     237,   237,   175,   130,   237,   237,   237,   237,   237,   237,
     237,   120,   121,   237,   237,   237,   237,   237,   237,   237,
     237,   109,   131,   237,   237,   237,   237,   237,   237,   237,
     237,   140,   237,   237,   240,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   130,   237,
     130,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     130,   237,   130,   130,   130,   240,   237,   130,   240,   109,
     130,   175,   237,   237,   237,   237,   130,   130,   130,   240,
     130,   237,   240,   130,   130,   130,   130,   130,   237,   130,
     109,    71,  1005,   135,   970,  1246,   135,  1219,  1217,  1007,
    1207,   237,   237,   237,   237,   237,   237,   237,   237,   130,
     336,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,  1104,   237,   513,   240,   237,   240,   240,   237,
     237,   237,   237,  1221,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   180,
     237,   237,   237,   237,   237,   489,   237,   464,   237,   237,
     237,   237,   237,   237,   237,   237,   237,  1203,   237,  1223,
     562,  1197,   237,   237,   527,   237,   237,  1205,   237,   237,
     237,   237,   112,   570,  1199,   170,   241,  1072,   237,   240,
     479,  1070,   240,    91,    -1,    -1,   366,    -1,    -1,   237,
     237,   237,   237,   237,   237,   237,    -1,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   230,   237,    -1,    -1,
     238,    -1,   396,    -1,    -1,    -1,    -1,   384,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     296
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   243,     0,     1,     5,    19,    22,    23,    28,    41,
      45,    46,    56,    70,    80,    81,    98,   114,   150,   159,
     160,   163,   164,   218,   244,   249,   254,   276,   282,   296,
     314,   332,   346,   361,   368,   372,   382,   391,   411,   421,
     427,   431,   441,   503,   520,   237,   238,   239,   239,   315,
     392,   422,   239,   432,   239,   347,   412,   333,   239,   239,
     297,   362,   239,   239,   373,   383,   239,     1,    29,    37,
      99,   277,   278,   279,   280,   281,     1,    26,    27,    32,
      76,    77,    83,    84,    85,   105,   106,   120,   121,   131,
     140,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   239,   239,   239,
       1,    69,   428,   429,   430,   239,     1,     8,     9,    17,
      25,    31,    33,    34,    36,    42,    48,    49,    52,    53,
      54,    58,    63,    67,    68,    71,    74,    75,    82,    89,
      90,    92,    93,    94,    95,    96,   107,   115,   116,   117,
     119,   122,   123,   126,   137,   162,   166,   170,   171,   172,
     173,   174,   178,   179,   219,   220,   221,   227,   229,   234,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   496,   500,   501,   502,   239,   239,   239,     1,   228,
     283,   284,   285,   286,   287,     1,    97,   125,   250,   251,
     252,   253,   239,   239,     1,    44,    59,    60,    61,    62,
      79,   521,   522,   523,   524,   525,   526,   527,   528,     1,
      29,    65,    99,   101,   102,   142,   144,   145,   146,   147,
     161,   187,   198,   230,   231,   255,   256,   257,   258,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   239,   239,     1,    99,   369,   370,   371,   237,
     240,   240,   240,   238,   278,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   238,
     505,     1,    20,    21,    24,    86,    87,    88,    91,    99,
     111,   112,   127,   128,   157,   201,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,     1,     3,     6,    22,    39,    43,    64,    66,
      78,    99,   129,   158,   187,   230,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   406,   407,   408,   409,
     410,     1,    69,   132,   423,   424,   425,   426,   240,   238,
     429,     1,    99,   132,   165,   433,   437,   438,   439,   440,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   497,   240,   493,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   238,   443,     1,    22,    39,    43,   124,
     133,   134,   168,   226,   348,   349,   350,   351,   352,   353,
     354,   358,   359,   360,     1,   132,   165,   226,   413,   417,
     418,   419,   420,     1,    43,    64,    69,   129,   334,   338,
     339,   340,   344,   345,   237,   240,   238,   284,   236,   237,
     240,   240,   238,   251,     1,    22,    39,    43,    99,   124,
     143,   209,   226,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   310,     1,    19,   103,   132,   363,   364,   365,
     366,   367,   240,   240,   240,   240,   240,   240,   238,   522,
     237,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   238,   256,     1,    99,
     165,   226,   374,   375,   376,   377,   378,     1,    99,   165,
     384,   385,   386,   387,   240,   238,   370,   130,   130,   130,
     237,   109,   109,   175,   109,   246,   246,   109,   109,   109,
     175,   175,   109,   246,   175,   175,   237,   237,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   238,   317,   237,   240,   240,   240,   240,   403,
     240,   240,   240,   240,   240,   240,   240,   240,   238,   394,
     240,   240,   238,   424,   130,   237,   240,   240,   434,   238,
     438,   175,   246,   246,   109,   175,   175,   109,   130,   175,
     246,   175,   246,   109,   109,   109,   175,   175,   175,   246,
     130,   175,   109,   109,   246,   109,   109,   130,   109,   109,
     175,   175,   240,   175,   240,   246,   246,   175,   246,   175,
     175,   175,   175,   176,   175,   176,   175,   175,   246,   246,
     130,   246,   175,   175,   175,   175,   237,   237,   240,   240,
     355,   240,   240,   240,   240,   240,   238,   349,   240,   414,
     240,   238,   418,   237,   335,   240,   240,   240,   238,   339,
     175,   237,   239,   130,   130,   237,   237,   240,   240,   311,
     240,   240,   240,   307,   240,   238,   299,   237,   240,   240,
     240,   238,   364,   175,   175,   130,   175,   175,   246,   237,
     130,   175,   130,   130,   130,   130,   130,   130,   148,   149,
     259,   260,   148,   149,   261,   262,   130,   130,   109,   130,
     130,   237,   237,   240,   379,   240,   238,   375,   237,   240,
     388,   238,   385,   130,   237,   237,   237,   237,   237,   237,
     237,   152,   153,   154,   155,   156,   245,   246,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   109,
     109,   246,   109,   109,   109,   109,   130,   109,   109,   246,
     246,   109,   248,   248,   237,   130,   195,   196,   130,   175,
     240,   130,   130,   130,   130,   109,   130,   130,   130,   237,
     130,   130,   237,   237,   130,   130,   240,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,    59,
     182,   183,   184,   185,   186,   188,   189,   192,   193,   194,
     197,   199,   200,   202,   204,   206,   207,   210,   216,   498,
     499,   237,    59,   182,   183,   184,   185,   186,   188,   189,
     192,   193,   194,   197,   199,   200,   202,   204,   206,   207,
     210,   216,   494,   495,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   130,   175,   240,   130,   109,
     130,   130,   130,   237,   130,   240,   130,   237,   240,   130,
     130,   109,   342,   343,   237,   237,     1,    99,   165,   235,
     288,   289,   290,   291,   292,   237,   237,   130,   175,   240,
     130,   130,   130,   240,   130,   237,   130,   130,   130,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   241,   237,   241,   237,   237,
     237,   237,   237,   130,   240,   130,   237,   130,   240,   237,
     237,   245,   245,   245,   245,   245,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,    12,    13,
      14,   247,   248,   237,   237,   237,   237,   237,   237,   237,
      10,   208,   404,   405,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   135,   435,   436,   237,
     241,   237,   241,   237,   237,    18,    40,    50,    57,    73,
     100,   108,   151,   169,   356,   357,   237,   237,   237,   237,
     237,   237,   135,   415,   416,   237,    59,   203,   208,   336,
     337,   237,   237,   180,   241,   341,   237,   240,   293,   240,
     238,   289,   237,   237,     5,    30,    47,    55,    72,    97,
     104,   118,   136,   138,   139,   190,   200,   205,   211,   215,
     217,   225,   232,   312,   313,   237,   237,   237,    59,   182,
     183,   184,   185,   186,   188,   189,   192,   193,   194,   197,
     199,   200,   202,   204,   206,   207,   210,   216,   308,   309,
     237,   237,   237,   237,   260,   262,   237,    72,   150,   181,
     190,   197,   211,   213,   214,   225,   232,   380,   381,   237,
     237,    72,   150,   181,   190,   197,   211,   213,   214,   225,
     232,   389,   390,   247,   247,   247,   237,   241,   237,   241,
     499,   495,   237,   241,   237,   241,   237,   241,   109,   343,
     237,   130,   240,   212,   248,   237,   237,   241,   237,   241,
     237,   241,   237,   241,   405,   436,   357,   416,   337,   237,
      47,    70,    72,   114,   189,   190,   226,   294,   295,   237,
     237,   313,   309,   381,   390,   237,   241,   295
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
#line 379 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 381 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 385 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 389 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 393 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 397 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 401 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 406 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 407 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 409 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 455 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 461 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 470 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 476 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 484 "conf_parser.y"
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
#line 523 "conf_parser.y"
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
#line 582 "conf_parser.y"
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
#line 610 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 618 "conf_parser.y"
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
#line 633 "conf_parser.y"
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
#line 648 "conf_parser.y"
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
#line 657 "conf_parser.y"
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
#line 671 "conf_parser.y"
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
#line 680 "conf_parser.y"
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
#line 708 "conf_parser.y"
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
#line 738 "conf_parser.y"
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
#line 761 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 776 "conf_parser.y"
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
#line 785 "conf_parser.y"
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
#line 794 "conf_parser.y"
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
#line 812 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 818 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 823 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 835 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 840 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 843 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 863 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 889 "conf_parser.y"
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
#line 902 "conf_parser.y"
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
#line 992 "conf_parser.y"
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
#line 1001 "conf_parser.y"
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
#line 1038 "conf_parser.y"
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
#line 1050 "conf_parser.y"
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
#line 1061 "conf_parser.y"
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
#line 1103 "conf_parser.y"
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
#line 1112 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1183 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1264 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1290 "conf_parser.y"
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
#line 1297 "conf_parser.y"
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

  case 214:
/* Line 1787 of yacc.c  */
#line 1355 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1364 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1425 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1462 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1468 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1472 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1486 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1491 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1505 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1525 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1546 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1558 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1620 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1655 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1668 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1677 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1688 "conf_parser.y"
    {
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1701 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1713 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1717 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1721 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1725 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1732 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1751 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1761 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1774 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1781 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1793 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1802 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1817 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1835 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1850 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1878 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1900 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1959 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1978 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 2013 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2017 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2030 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2045 "conf_parser.y"
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

  case 366:
/* Line 1787 of yacc.c  */
#line 2089 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 2098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 2107 "conf_parser.y"
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

  case 369:
/* Line 1787 of yacc.c  */
#line 2133 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2151 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2179 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 2187 "conf_parser.y"
    {
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2202 "conf_parser.y"
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
#line 2213 "conf_parser.y"
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
#line 2224 "conf_parser.y"
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
#line 2235 "conf_parser.y"
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
#line 2244 "conf_parser.y"
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
#line 2262 "conf_parser.y"
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
#line 2269 "conf_parser.y"
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
#line 2327 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2332 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2341 "conf_parser.y"
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
#line 2360 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2373 "conf_parser.y"
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
#line 2397 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2403 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2417 "conf_parser.y"
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
#line 2435 "conf_parser.y"
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
#line 2442 "conf_parser.y"
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
#line 2482 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2496 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 2547 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2558 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2564 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
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

  case 509:
/* Line 1787 of yacc.c  */
#line 2667 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2672 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2681 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2686 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2752 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2773 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2797 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2821 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2827 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2833 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2836 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2845 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2848 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2851 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2854 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2857 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2860 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2863 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2875 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2895 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2898 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2910 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2919 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2943 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2957 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2962 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2990 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 2995 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 3000 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 3010 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 3015 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3025 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3030 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3040 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3045 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 3055 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 3073 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 3079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 3085 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 3094 "conf_parser.y"
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

  case 634:
/* Line 1787 of yacc.c  */
#line 3108 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 3114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6951 "conf_parser.c"
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


