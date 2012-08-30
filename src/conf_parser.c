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
     T_DEAF = 444,
     T_DEBUG = 445,
     T_DLINE = 446,
     T_DRONE = 447,
     T_EXTERNAL = 448,
     T_FULL = 449,
     T_INVISIBLE = 450,
     T_IPV4 = 451,
     T_IPV6 = 452,
     T_LOCOPS = 453,
     T_MAX_CLIENTS = 454,
     T_NCHANGE = 455,
     T_OPERWALL = 456,
     T_RECVQ = 457,
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
#define T_DEAF 444
#define T_DEBUG 445
#define T_DLINE 446
#define T_DRONE 447
#define T_EXTERNAL 448
#define T_FULL 449
#define T_INVISIBLE 450
#define T_IPV4 451
#define T_IPV6 452
#define T_LOCOPS 453
#define T_MAX_CLIENTS 454
#define T_NCHANGE 455
#define T_OPERWALL 456
#define T_RECVQ 457
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
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 678 "conf_parser.c"
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
#line 706 "conf_parser.c"

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
#define YYLAST   1161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  244
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  287
/* YYNRULES -- Number of rules.  */
#define YYNRULES  637
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1250

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
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,
    1409,  1414,  1419,  1424,  1429,  1434,  1439,  1444,  1449,  1454,
    1459,  1464,  1469,  1474,  1479,  1484,  1489,  1494,  1499,  1504,
    1509,  1514,  1519,  1524,  1529,  1534,  1539,  1544,  1549,  1554,
    1559,  1564,  1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,
    1609,  1614,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1654,
    1655,  1661,  1665,  1667,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,
    1701,  1703,  1705,  1707,  1708,  1714,  1718,  1720,  1722,  1724,
    1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1765,  1770,
    1775,  1781,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1821,
    1826,  1831,  1836,  1841,  1846,  1851,  1856,  1861,  1866,  1871,
    1876,  1881,  1886,  1892,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1909,  1911,  1916,  1921,  1926,  1931,  1936
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     245,     0,    -1,    -1,   245,   246,    -1,   278,    -1,   284,
      -1,   298,    -1,   505,    -1,   316,    -1,   334,    -1,   348,
      -1,   256,    -1,   522,    -1,   363,    -1,   370,    -1,   374,
      -1,   384,    -1,   393,    -1,   413,    -1,   423,    -1,   429,
      -1,   443,    -1,   433,    -1,   251,    -1,     1,   239,    -1,
       1,   240,    -1,    -1,   248,    -1,   110,   247,    -1,   110,
     153,   247,    -1,   110,   154,   247,    -1,   110,   155,   247,
      -1,   110,   156,   247,    -1,   110,   157,   247,    -1,    -1,
     250,    -1,   110,   249,    -1,   110,    13,   249,    -1,   110,
      14,   249,    -1,   110,    15,   249,    -1,    99,   241,   252,
     240,   239,    -1,   252,   253,    -1,   253,    -1,   254,    -1,
     255,    -1,     1,   239,    -1,    98,   242,   131,   239,    -1,
     126,   242,   131,   239,    -1,   161,   241,   257,   240,   239,
      -1,   257,   258,    -1,   258,    -1,   269,    -1,   274,    -1,
     277,    -1,   271,    -1,   272,    -1,   273,    -1,   276,    -1,
     267,    -1,   266,    -1,   275,    -1,   270,    -1,   265,    -1,
     259,    -1,   260,    -1,   268,    -1,     1,   239,    -1,   147,
     242,   261,   239,    -1,   148,   242,   263,   239,    -1,   261,
     243,   262,    -1,   262,    -1,   149,    -1,   150,    -1,   263,
     243,   264,    -1,   264,    -1,   149,    -1,   150,    -1,   145,
     242,   131,   239,    -1,   143,   242,   131,   239,    -1,   146,
     242,   131,   239,    -1,   188,   242,   131,   239,    -1,   100,
     242,   131,   239,    -1,   162,   242,   131,   239,    -1,    30,
     242,   131,   239,    -1,   103,   242,   131,   239,    -1,   102,
     242,   131,   239,    -1,   232,   242,   131,   239,    -1,   233,
     242,   131,   239,    -1,   199,   242,   110,   239,    -1,    66,
     242,   176,   239,    -1,     5,   241,   279,   240,   239,    -1,
     279,   280,    -1,   280,    -1,   281,    -1,   283,    -1,   282,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,    38,
     242,   131,   239,    -1,    30,   242,   131,   239,    -1,    82,
     241,   285,   240,   239,    -1,   285,   286,    -1,   286,    -1,
     287,    -1,   288,    -1,     1,   239,    -1,   230,   242,   176,
     239,    -1,    -1,   289,   238,   241,   290,   240,   239,    -1,
     290,   291,    -1,   291,    -1,   292,    -1,   294,    -1,   293,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,   237,
     242,   250,   239,    -1,   237,   242,   213,   239,    -1,    -1,
     166,   295,   242,   296,   239,    -1,   296,   243,   297,    -1,
     297,    -1,   228,    -1,   115,    -1,    48,    -1,   191,    -1,
      73,    -1,    71,    -1,   190,    -1,    -1,   115,   299,   241,
     300,   240,   239,    -1,   300,   301,    -1,   301,    -1,   302,
      -1,   303,    -1,   304,    -1,   308,    -1,   307,    -1,   305,
      -1,   306,    -1,   312,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,   228,   242,   131,   239,    -1,   125,   242,
     131,   239,    -1,    40,   242,   176,   239,    -1,   144,   242,
     131,   239,    -1,    23,   242,   131,   239,    -1,    -1,   210,
     309,   242,   310,   239,    -1,   310,   243,   311,    -1,   311,
      -1,   183,    -1,   186,    -1,   187,    -1,   189,    -1,   190,
      -1,   194,    -1,    60,    -1,   207,    -1,   200,    -1,   203,
      -1,   211,    -1,   208,    -1,   193,    -1,   201,    -1,   205,
      -1,   195,    -1,   217,    -1,   184,    -1,   185,    -1,   198,
      -1,    -1,    44,   313,   242,   314,   239,    -1,   314,   243,
     315,    -1,   315,    -1,    56,    -1,   139,    -1,    73,    -1,
     227,    -1,   191,    -1,   212,    -1,   234,    -1,    48,    -1,
      31,    -1,   218,    -1,   137,    -1,     5,    -1,   105,    -1,
     201,    -1,   216,    -1,   119,    -1,   140,    -1,   206,    -1,
      98,    -1,    -1,    23,   317,   241,   318,   240,   239,    -1,
     318,   319,    -1,   319,    -1,   320,    -1,   331,    -1,   332,
      -1,   321,    -1,   322,    -1,   333,    -1,   323,    -1,   324,
      -1,   325,    -1,   326,    -1,   327,    -1,   328,    -1,   329,
      -1,   330,    -1,     1,   239,    -1,   100,   242,   131,   239,
      -1,   128,   242,   248,   239,    -1,   129,   242,   248,   239,
      -1,   113,   242,   110,   239,    -1,    25,   242,   248,   239,
      -1,    92,   242,   110,   239,    -1,    87,   242,   110,   239,
      -1,    89,   242,   110,   239,    -1,    88,   242,   110,   239,
      -1,   158,   242,   250,   239,    -1,   202,   242,   250,   239,
      -1,    21,   242,   110,   239,    -1,    22,   242,   110,   239,
      -1,   112,   242,   110,   239,    -1,    -1,    81,   335,   241,
     340,   240,   239,    -1,    -1,    44,   337,   242,   338,   239,
      -1,   338,   243,   339,    -1,   339,    -1,   209,    -1,    60,
      -1,   204,    -1,   340,   341,    -1,   341,    -1,   342,    -1,
     336,    -1,   346,    -1,   347,    -1,     1,   239,    -1,    -1,
     130,   242,   344,   343,   239,    -1,   344,   243,   345,    -1,
     345,    -1,   110,    -1,   110,   181,   110,    -1,    70,   242,
     131,   239,    -1,    65,   242,   131,   239,    -1,    -1,    57,
     349,   241,   350,   240,   239,    -1,   350,   351,    -1,   351,
      -1,   352,    -1,   353,    -1,   354,    -1,   356,    -1,   360,
      -1,   361,    -1,   362,    -1,   355,    -1,     1,   239,    -1,
     228,   242,   131,   239,    -1,   125,   242,   131,   239,    -1,
      23,   242,   131,   239,    -1,    40,   242,   176,   239,    -1,
      -1,    44,   357,   242,   358,   239,    -1,   358,   243,   359,
      -1,   359,    -1,   170,    -1,    41,    -1,    74,    -1,    58,
      -1,    19,    -1,   109,    -1,    51,    -1,   152,    -1,   101,
      -1,   169,   242,   131,   239,    -1,   135,   242,   131,   239,
      -1,   134,   242,   110,   239,    -1,    -1,   151,   364,   241,
     365,   240,   239,    -1,   365,   366,    -1,   366,    -1,   367,
      -1,   368,    -1,   369,    -1,     1,   239,    -1,   133,   242,
     131,   239,    -1,    20,   242,   131,   239,    -1,   104,   242,
     131,   239,    -1,   219,   241,   371,   240,   239,    -1,   371,
     372,    -1,   372,    -1,   373,    -1,     1,    -1,   100,   242,
     131,   239,    -1,    -1,   164,   375,   241,   376,   240,   239,
      -1,   376,   377,    -1,   377,    -1,   378,    -1,   379,    -1,
     380,    -1,     1,   239,    -1,   100,   242,   131,   239,    -1,
     228,   242,   131,   239,    -1,    -1,   166,   381,   242,   382,
     239,    -1,   382,   243,   383,    -1,   383,    -1,    73,    -1,
     227,    -1,   191,    -1,   212,    -1,   234,    -1,   215,    -1,
     151,    -1,   214,    -1,   198,    -1,   182,    -1,    -1,   165,
     385,   241,   386,   240,   239,    -1,   386,   387,    -1,   387,
      -1,   388,    -1,   389,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,    -1,   166,   390,   242,   391,   239,    -1,
     391,   243,   392,    -1,   392,    -1,    73,    -1,   227,    -1,
     191,    -1,   212,    -1,   234,    -1,   215,    -1,   151,    -1,
     214,    -1,   198,    -1,   182,    -1,    -1,    24,   394,   241,
     395,   240,   239,    -1,   395,   396,    -1,   396,    -1,   397,
      -1,   398,    -1,   399,    -1,   400,    -1,   401,    -1,   403,
      -1,   402,    -1,   412,    -1,   404,    -1,   409,    -1,   410,
      -1,   411,    -1,   408,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,    65,   242,   131,   239,    -1,   232,   242,
     131,   239,    -1,   159,   242,   131,   239,    -1,     3,   242,
     131,   239,    -1,   130,   242,   110,   239,    -1,     6,   242,
     196,   239,    -1,     6,   242,   197,   239,    -1,    -1,    44,
     405,   242,   406,   239,    -1,   406,   243,   407,    -1,   407,
      -1,    10,    -1,    12,    -1,   222,    -1,   209,    -1,    40,
     242,   176,   239,    -1,    67,   242,   131,   239,    -1,    79,
     242,   131,   239,    -1,    23,   242,   131,   239,    -1,   188,
     242,   131,   239,    -1,    -1,    71,   414,   241,   419,   240,
     239,    -1,    -1,   166,   416,   242,   417,   239,    -1,   417,
     243,   418,    -1,   418,    -1,   136,    -1,   419,   420,    -1,
     420,    -1,   421,    -1,   422,    -1,   415,    -1,     1,    -1,
     228,   242,   131,   239,    -1,   133,   242,   131,   239,    -1,
      -1,    29,   424,   241,   425,   240,   239,    -1,   425,   426,
      -1,   426,    -1,   427,    -1,   428,    -1,     1,    -1,    70,
     242,   131,   239,    -1,   133,   242,   131,   239,    -1,    42,
     241,   430,   240,   239,    -1,   430,   431,    -1,   431,    -1,
     432,    -1,     1,    -1,    70,   242,   131,   239,    -1,    -1,
      46,   434,   241,   439,   240,   239,    -1,    -1,   166,   436,
     242,   437,   239,    -1,   437,   243,   438,    -1,   438,    -1,
     136,    -1,   439,   440,    -1,   440,    -1,   441,    -1,   442,
      -1,   435,    -1,     1,    -1,   100,   242,   131,   239,    -1,
     133,   242,   131,   239,    -1,    47,   241,   444,   240,   239,
      -1,   444,   445,    -1,   445,    -1,   456,    -1,   457,    -1,
     459,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     464,    -1,   465,    -1,   466,    -1,   455,    -1,   468,    -1,
     469,    -1,   470,    -1,   471,    -1,   486,    -1,   473,    -1,
     475,    -1,   477,    -1,   476,    -1,   480,    -1,   474,    -1,
     481,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     498,    -1,   487,    -1,   488,    -1,   489,    -1,   494,    -1,
     478,    -1,   479,    -1,   504,    -1,   502,    -1,   503,    -1,
     458,    -1,   493,    -1,   467,    -1,   491,    -1,   492,    -1,
     454,    -1,   447,    -1,   448,    -1,   449,    -1,   450,    -1,
     451,    -1,   452,    -1,   453,    -1,   472,    -1,   446,    -1,
     490,    -1,     1,    -1,    94,   242,   110,   239,    -1,    50,
     242,   176,   239,    -1,    49,   242,   248,   239,    -1,    53,
     242,   248,   239,    -1,    54,   242,   110,   239,    -1,    55,
     242,   110,   239,    -1,   231,   242,   176,   239,    -1,   138,
     242,   248,   239,    -1,   163,   242,   176,   239,    -1,    72,
     242,   248,   239,    -1,    64,   242,   176,   239,    -1,    68,
     242,   176,   239,    -1,    34,   242,   176,   239,    -1,    43,
     242,   176,   239,    -1,     8,   242,   176,   239,    -1,    91,
     242,   248,   239,    -1,    90,   242,   110,   239,    -1,    83,
     242,   110,   239,    -1,     9,   242,   248,   239,    -1,   180,
     242,   248,   239,    -1,   179,   242,   248,   239,    -1,    59,
     242,   110,   239,    -1,    76,   242,   176,   239,    -1,    75,
     242,   131,   239,    -1,    69,   242,   176,   239,    -1,   236,
     242,   176,   239,    -1,   171,   242,   176,   239,    -1,   174,
     242,   176,   239,    -1,   175,   242,   176,   239,    -1,   173,
     242,   176,   239,    -1,   173,   242,   177,   239,    -1,   172,
     242,   176,   239,    -1,   172,   242,   177,   239,    -1,   123,
     242,   248,   239,    -1,    18,   242,   248,   239,    -1,   116,
     242,   176,   239,    -1,   124,   242,   248,   239,    -1,   167,
     242,   176,   239,    -1,   108,   242,   176,   239,    -1,   223,
     242,   176,   239,    -1,   118,   242,   176,   239,    -1,    95,
     242,   131,   239,    -1,    35,   242,   110,   239,    -1,    93,
     242,   110,   239,    -1,   229,   242,   176,   239,    -1,    37,
     242,   131,   239,    -1,   220,   242,   131,   239,    -1,   127,
     242,   176,   239,    -1,    32,   242,   176,   239,    -1,   221,
     242,   248,   239,    -1,    -1,   120,   495,   242,   496,   239,
      -1,   496,   243,   497,    -1,   497,    -1,   183,    -1,   186,
      -1,   187,    -1,   189,    -1,   190,    -1,   194,    -1,    60,
      -1,   207,    -1,   200,    -1,   203,    -1,   211,    -1,   208,
      -1,   193,    -1,   201,    -1,   205,    -1,   195,    -1,   217,
      -1,   184,    -1,   185,    -1,   198,    -1,    -1,   117,   499,
     242,   500,   239,    -1,   500,   243,   501,    -1,   501,    -1,
     183,    -1,   186,    -1,   187,    -1,   189,    -1,   190,    -1,
     194,    -1,   207,    -1,    60,    -1,   200,    -1,   203,    -1,
     211,    -1,   208,    -1,   193,    -1,   201,    -1,   205,    -1,
     195,    -1,   217,    -1,   184,    -1,   185,    -1,   198,    -1,
      96,   242,   110,   239,    -1,    97,   242,   110,   239,    -1,
      26,   242,   110,   239,    -1,    20,   241,   506,   240,   239,
      -1,   506,   507,    -1,   507,    -1,   515,    -1,   510,    -1,
     511,    -1,   512,    -1,   513,    -1,   514,    -1,   516,    -1,
     517,    -1,   518,    -1,   509,    -1,   519,    -1,   520,    -1,
     521,    -1,   508,    -1,     1,    -1,    33,   242,   176,   239,
      -1,   141,   242,   176,   239,    -1,    77,   242,   248,   239,
      -1,    78,   242,   248,   239,    -1,    86,   242,   110,   239,
      -1,    85,   242,   110,   239,    -1,   132,   242,   176,   239,
      -1,    84,   242,   110,   239,    -1,    28,   242,   110,   239,
      -1,    27,   242,   110,   239,    -1,   106,   242,   176,   239,
      -1,   107,   242,   176,   239,    -1,   121,   242,   110,   239,
      -1,   122,   242,   248,   239,    -1,   160,   241,   523,   240,
     239,    -1,   523,   524,    -1,   524,    -1,   525,    -1,   526,
      -1,   528,    -1,   529,    -1,   527,    -1,   530,    -1,     1,
      -1,    45,   242,   176,   239,    -1,    63,   242,   176,   239,
      -1,    61,   242,   131,   239,    -1,    80,   242,   248,   239,
      -1,    60,   242,   176,   239,    -1,    62,   242,   176,   239,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   352,   352,   353,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   381,   381,   382,   386,
     390,   394,   398,   402,   408,   408,   409,   410,   411,   412,
     419,   422,   422,   423,   423,   423,   425,   431,   438,   440,
     440,   441,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   446,   446,   447,   447,   448,   449,   452,   453,   455,
     455,   456,   462,   470,   470,   471,   477,   485,   524,   583,
     611,   619,   634,   649,   658,   672,   681,   709,   739,   762,
     771,   773,   773,   774,   774,   775,   775,   777,   786,   795,
     807,   808,   808,   810,   810,   811,   813,   820,   820,   830,
     831,   833,   833,   834,   834,   836,   841,   844,   850,   849,
     855,   855,   856,   860,   864,   868,   872,   876,   880,   891,
     890,   988,   988,   989,   989,   989,   990,   990,   990,   991,
     991,   991,   993,  1002,  1039,  1051,  1062,  1104,  1114,  1113,
    1119,  1119,  1120,  1124,  1128,  1132,  1136,  1140,  1144,  1148,
    1152,  1156,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1196,  1203,  1202,  1208,  1208,  1209,  1213,  1217,  1221,
    1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,  1257,  1261,
    1265,  1269,  1273,  1277,  1281,  1292,  1291,  1341,  1341,  1342,
    1343,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1353,  1354,  1356,  1365,  1371,  1377,  1383,  1389,
    1395,  1401,  1407,  1413,  1419,  1426,  1432,  1438,  1448,  1447,
    1464,  1463,  1468,  1468,  1469,  1473,  1477,  1485,  1485,  1486,
    1486,  1486,  1486,  1486,  1488,  1488,  1490,  1490,  1492,  1506,
    1526,  1535,  1548,  1547,  1616,  1616,  1617,  1617,  1617,  1617,
    1618,  1618,  1618,  1619,  1619,  1621,  1656,  1669,  1678,  1690,
    1689,  1693,  1693,  1694,  1698,  1702,  1706,  1710,  1714,  1718,
    1722,  1726,  1733,  1752,  1762,  1776,  1775,  1791,  1791,  1792,
    1792,  1792,  1792,  1794,  1803,  1818,  1831,  1833,  1833,  1834,
    1834,  1836,  1852,  1851,  1867,  1867,  1868,  1868,  1868,  1868,
    1870,  1879,  1902,  1901,  1907,  1907,  1908,  1912,  1916,  1920,
    1924,  1928,  1932,  1936,  1940,  1944,  1954,  1953,  1970,  1970,
    1971,  1971,  1971,  1973,  1980,  1979,  1985,  1985,  1986,  1990,
    1994,  1998,  2002,  2006,  2010,  2014,  2018,  2022,  2032,  2031,
    2082,  2082,  2083,  2083,  2083,  2084,  2084,  2085,  2085,  2085,
    2086,  2086,  2086,  2087,  2087,  2088,  2090,  2099,  2108,  2134,
    2152,  2170,  2176,  2180,  2189,  2188,  2192,  2192,  2193,  2197,
    2201,  2205,  2211,  2222,  2233,  2244,  2253,  2272,  2271,  2337,
    2336,  2340,  2340,  2341,  2347,  2347,  2348,  2348,  2348,  2348,
    2350,  2369,  2379,  2378,  2403,  2403,  2404,  2404,  2404,  2406,
    2412,  2421,  2423,  2423,  2424,  2424,  2426,  2445,  2444,  2492,
    2491,  2495,  2495,  2496,  2502,  2502,  2503,  2503,  2503,  2503,
    2505,  2511,  2520,  2523,  2523,  2524,  2524,  2525,  2525,  2526,
    2526,  2527,  2527,  2528,  2528,  2529,  2529,  2530,  2530,  2531,
    2531,  2532,  2532,  2533,  2533,  2534,  2534,  2535,  2535,  2536,
    2536,  2537,  2538,  2538,  2539,  2539,  2540,  2540,  2541,  2541,
    2542,  2542,  2543,  2544,  2544,  2545,  2546,  2547,  2547,  2548,
    2548,  2549,  2550,  2550,  2551,  2551,  2552,  2552,  2553,  2556,
    2561,  2567,  2573,  2579,  2584,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2624,  2629,  2634,  2639,  2644,  2649,  2654,  2659,
    2665,  2676,  2681,  2690,  2695,  2700,  2705,  2710,  2715,  2718,
    2723,  2726,  2731,  2736,  2741,  2746,  2751,  2756,  2761,  2766,
    2771,  2782,  2787,  2792,  2797,  2806,  2815,  2820,  2825,  2831,
    2830,  2835,  2835,  2836,  2839,  2842,  2845,  2848,  2851,  2854,
    2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,
    2887,  2890,  2893,  2899,  2898,  2903,  2903,  2904,  2907,  2910,
    2913,  2916,  2919,  2922,  2925,  2928,  2931,  2934,  2937,  2940,
    2943,  2946,  2949,  2952,  2955,  2958,  2961,  2966,  2971,  2976,
    2985,  2988,  2988,  2989,  2990,  2990,  2991,  2991,  2992,  2992,
    2993,  2994,  2994,  2995,  2996,  2996,  2997,  2997,  2999,  3004,
    3009,  3014,  3019,  3024,  3029,  3034,  3039,  3044,  3049,  3054,
    3059,  3064,  3072,  3075,  3075,  3076,  3076,  3077,  3078,  3078,
    3079,  3080,  3082,  3088,  3094,  3103,  3117,  3123
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
  "T_CALLERID", "T_CCONN", "T_CCONN_FULL", "T_SSL_CIPHER_LIST", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE",
  "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SET",
  "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS", "T_WALLOP",
  "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV",
  "UNKLINE", "USER", "USE_EGD", "USE_LOGGING", "USE_WHOIS_ACTUALLY",
  "VHOST", "VHOST6", "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE",
  "';'", "'}'", "'{'", "'='", "','", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_ssl_client_method", "serverinfo_ssl_server_method",
  "client_method_types", "client_method_type_item", "server_method_types",
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
     485,   486,   487,   488,   489,   490,   491,   492,   493,    59,
     125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247,   247,   248,   248,
     248,   248,   248,   248,   249,   249,   250,   250,   250,   250,
     251,   252,   252,   253,   253,   253,   254,   255,   256,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   259,   260,   261,
     261,   262,   262,   263,   263,   264,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   279,   280,   280,   280,   280,   281,   282,   283,
     284,   285,   285,   286,   286,   286,   287,   289,   288,   290,
     290,   291,   291,   291,   291,   292,   293,   293,   295,   294,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   299,
     298,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   302,   303,   304,   305,   306,   307,   309,   308,
     310,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   313,   312,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   317,   316,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   335,   334,
     337,   336,   338,   338,   339,   339,   339,   340,   340,   341,
     341,   341,   341,   341,   343,   342,   344,   344,   345,   345,
     346,   347,   349,   348,   350,   350,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   353,   354,   355,   357,
     356,   358,   358,   359,   359,   359,   359,   359,   359,   359,
     359,   359,   360,   361,   362,   364,   363,   365,   365,   366,
     366,   366,   366,   367,   368,   369,   370,   371,   371,   372,
     372,   373,   375,   374,   376,   376,   377,   377,   377,   377,
     378,   379,   381,   380,   382,   382,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   385,   384,   386,   386,
     387,   387,   387,   388,   390,   389,   391,   391,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   394,   393,
     395,   395,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   397,   398,   399,   400,
     401,   402,   403,   403,   405,   404,   406,   406,   407,   407,
     407,   407,   408,   409,   410,   411,   412,   414,   413,   416,
     415,   417,   417,   418,   419,   419,   420,   420,   420,   420,
     421,   422,   424,   423,   425,   425,   426,   426,   426,   427,
     428,   429,   430,   430,   431,   431,   432,   434,   433,   436,
     435,   437,   437,   438,   439,   439,   440,   440,   440,   440,
     441,   442,   443,   444,   444,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   475,
     476,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   495,
     494,   496,   496,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   499,   498,   500,   500,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   502,   503,   504,
     505,   506,   506,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   523,   524,   524,   524,   524,   524,
     524,   524,   525,   526,   527,   528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   348,   402,     0,
     417,     0,   252,   387,   228,     0,     0,   129,   285,     0,
       0,   302,   326,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   606,   602,   594,   595,   596,   597,   598,
     593,   599,   600,   601,   603,   604,   605,     0,     0,     0,
     415,     0,     0,   413,   414,     0,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   563,     0,
     539,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   434,   486,   478,   479,   480,   481,   482,   483,   484,
     477,   445,   435,   436,   472,   437,   438,   439,   440,   441,
     442,   443,   444,   474,   446,   447,   448,   449,   485,   451,
     456,   452,   454,   453,   467,   468,   455,   457,   458,   459,
     460,   461,   450,   463,   464,   465,   487,   475,   476,   473,
     466,   462,   470,   471,   469,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,   631,     0,     0,     0,     0,     0,
       0,     0,   624,   625,   626,   629,   627,   628,   630,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    63,    64,    62,
      59,    58,    65,    51,    61,    54,    55,    56,    52,    60,
      57,    53,     0,     0,   300,     0,     0,   298,   299,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   212,   200,
     201,   204,     0,     0,     0,     0,     0,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,   356,   358,   357,   360,   364,   361,   362,   363,
     359,   408,     0,     0,     0,   405,   406,   407,     0,     0,
     412,   429,     0,     0,   419,   428,     0,   425,   426,   427,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   433,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,   263,
     259,   260,   261,   262,   399,     0,   389,     0,   398,     0,
     395,   396,   397,     0,   230,     0,     0,     0,   240,     0,
     238,   239,   241,   242,   105,     0,     0,   101,     0,    45,
       0,     0,     0,    41,     0,     0,     0,   172,     0,     0,
       0,   148,     0,     0,   132,   133,   134,   135,   138,   139,
     137,   136,   140,     0,     0,     0,     0,     0,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   623,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
     312,     0,     0,   305,   306,   307,   308,     0,     0,   334,
       0,   329,   330,   331,     0,     0,   297,     0,     0,     0,
      90,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
       0,     0,     0,   404,     0,   411,     0,     0,     0,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   432,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   394,   243,     0,     0,     0,     0,     0,   237,
       0,   100,     0,     0,     0,    40,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   292,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,   622,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
       0,    70,    75,    76,     0,    74,     0,     0,     0,     0,
       0,    48,   309,     0,     0,     0,     0,   304,   332,     0,
       0,     0,   328,     0,   296,    99,    98,    97,   617,   616,
     608,    26,    26,    26,    26,    26,    28,    27,   610,   611,
     615,   613,   612,   618,   619,   620,   621,   614,   609,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   349,
       0,     0,   403,   416,     0,     0,     0,   418,   503,   507,
     523,   589,   537,   501,   531,   534,   502,   491,   490,   492,
     493,   494,   510,   499,   500,   513,   498,   512,   511,   506,
     505,   504,   532,   489,   530,   587,   588,   527,   524,   574,
     567,   584,   585,   568,   569,   570,   571,   579,   572,   582,
     586,   575,   580,   576,   581,   573,   578,   577,   583,     0,
     566,   529,   549,   543,   560,   561,   544,   545,   546,   547,
     555,   548,   558,   562,   551,   556,   552,   557,   550,   554,
     553,   559,     0,   542,   522,   525,   536,   496,   497,   526,
     515,   520,   521,   518,   519,   516,   517,   509,   508,   535,
     538,   528,   533,   495,   514,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,   388,     0,     0,
       0,   248,   244,   247,   229,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   286,
     632,   636,   634,   637,   633,   635,    83,    89,    81,    85,
      84,    78,    77,    79,    67,     0,    68,     0,    82,    80,
      88,    86,    87,     0,     0,     0,   303,     0,     0,   327,
     301,    29,    30,    31,    32,    33,   225,   226,   218,   220,
     222,   221,   219,   214,   227,   217,   215,   216,    34,    34,
      34,    36,    35,   223,   224,   370,   372,   373,   385,   382,
     378,   379,   381,   380,     0,   377,   367,   383,   384,   366,
     371,   369,   386,   368,   409,   410,   430,   431,   423,     0,
     422,   564,     0,   540,     0,   267,   268,   277,   274,   279,
     276,   275,   281,   278,   280,   273,     0,   272,   266,   284,
     283,   282,   265,   401,   393,     0,   392,   400,   235,   236,
     234,     0,   233,   251,   250,     0,     0,     0,   114,     0,
       0,     0,     0,   109,   147,   145,   187,   184,   183,   176,
     178,   194,   188,   191,   186,   177,   192,   180,   189,   193,
     181,   190,   185,   179,   182,     0,   175,   142,   144,   146,
     158,   152,   169,   170,   153,   154,   155,   156,   164,   157,
     167,   171,   160,   165,   161,   166,   159,   163,   162,   168,
       0,   151,   143,   294,   295,   293,    69,    73,   310,   316,
     322,   325,   318,   324,   319,   323,   321,   317,   320,     0,
     315,   311,   333,   338,   344,   347,   340,   346,   341,   345,
     343,   339,   342,     0,   337,    37,    38,    39,   375,     0,
     420,     0,   565,   541,   270,     0,   390,     0,   231,     0,
     249,   246,   245,     0,     0,     0,     0,   108,   173,     0,
     149,     0,   313,     0,   335,     0,   376,   421,   271,   391,
     232,   115,   124,   127,   126,   123,   128,   125,   122,     0,
     121,   117,   116,   174,   150,   314,   336,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   796,   797,  1041,  1042,    25,   238,   239,
     240,   241,    26,   275,   276,   277,   278,   760,   761,   764,
     765,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    27,    71,    72,    73,    74,    75,
      28,   230,   231,   232,   233,   234,   970,   971,   972,   973,
     974,  1110,  1239,  1240,    29,    60,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   733,  1160,  1161,   522,   729,
    1135,  1136,    30,    49,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
      31,    57,   488,   714,  1101,  1102,   489,   490,   491,  1107,
     962,   963,   492,   493,    32,    55,   464,   465,   466,   467,
     468,   469,   470,   700,  1086,  1087,   471,   472,   473,    33,
      61,   527,   528,   529,   530,   531,    34,   296,   297,   298,
      35,    64,   562,   563,   564,   565,   566,   774,  1179,  1180,
      36,    65,   570,   571,   572,   573,   780,  1193,  1194,    37,
      50,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   619,  1054,  1055,   376,   377,   378,   379,   380,    38,
      56,   478,   709,  1095,  1096,   479,   480,   481,   482,    39,
      51,   384,   385,   386,   387,    40,   112,   113,   114,    41,
      53,   395,   638,  1069,  1070,   396,   397,   398,   399,    42,
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
#define YYPACT_NINF -876
static const yytype_int16 yypact[] =
{
    -876,   685,  -876,  -199,  -234,  -216,  -876,  -876,  -876,  -194,
    -876,  -186,  -876,  -876,  -876,  -173,  -162,  -876,  -876,  -159,
    -153,  -876,  -876,  -147,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,     4,   910,  -141,
    -139,  -127,    20,  -119,   453,  -107,   -83,   -70,    11,    85,
     -51,    -2,   523,   493,    41,    42,    18,  -209,  -169,  -151,
      -5,     8,  -876,  -876,  -876,  -876,  -876,    59,    66,    68,
      75,    78,    84,    89,    90,    95,   100,   101,   102,   104,
     109,   174,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,   690,   346,    22,
    -876,   112,    14,  -876,  -876,    97,  -876,   114,   116,   117,
     118,   119,   122,   125,   126,   128,   129,   134,   135,   139,
     143,   150,   151,   152,   160,   163,   175,   176,   179,   182,
     184,   185,   187,   188,   190,   191,   192,   193,  -876,   194,
    -876,   195,   197,   198,   199,   200,   201,   202,   203,   208,
     209,   211,   213,   215,   216,   218,   221,   222,   223,   225,
      98,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   313,    12,   430,    54,   227,
      69,  -876,  -876,  -876,    67,    72,   228,   231,    28,  -876,
    -876,  -876,   372,    23,  -876,   235,   236,   238,   241,   244,
     256,     3,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   145,
     257,   267,   271,   272,   273,   276,   278,   284,   285,   288,
     290,   293,   295,   296,   297,   142,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,   120,    19,  -876,   298,    15,  -876,  -876,  -876,
     167,   325,   388,   294,  -876,   229,   230,   366,   435,   435,
     441,   442,   443,   379,   380,   447,   435,   382,   389,   327,
    -876,   328,   330,   332,   333,   337,   339,   345,   348,   350,
     352,   355,   356,   357,   359,   360,   291,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,   349,   362,   363,   365,   367,  -876,   368,   369,
     370,   371,   373,   375,   376,   377,   322,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,   381,   387,    17,  -876,  -876,  -876,   433,   383,
    -876,  -876,   392,   393,  -876,  -876,    13,  -876,  -876,  -876,
     432,   435,   435,   511,   454,   461,   532,   512,   468,   435,
     469,   435,   536,   537,   538,   473,   474,   475,   435,   521,
     477,   544,   547,   435,   548,   549,   529,   551,   552,   488,
     489,   424,   491,   426,   435,   435,   494,   435,   495,   496,
     499,    56,    58,   502,   503,   435,   435,   556,   435,   504,
     507,   517,   518,   449,  -876,   457,   427,   458,  -876,   459,
     462,   464,   465,   471,    34,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   476,  -876,   478,  -876,    51,
    -876,  -876,  -876,   460,  -876,   479,   480,   481,  -876,     7,
    -876,  -876,  -876,  -876,  -876,   527,   485,  -876,   487,  -876,
     579,   585,   490,  -876,   497,   492,   498,  -876,   505,   506,
     508,  -876,   509,    36,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   500,   510,   513,   515,    16,  -876,  -876,
    -876,  -876,   541,   543,   599,   557,   559,   435,   514,  -876,
    -876,   606,   562,   610,   613,   614,   615,   623,   627,    49,
      63,   630,   631,   650,   632,   634,   530,  -876,   534,   526,
    -876,   533,    10,  -876,  -876,  -876,  -876,   542,   545,  -876,
      44,  -876,  -876,  -876,   640,   550,  -876,   554,   555,   560,
    -876,   565,   566,   567,   253,   568,   569,   570,   571,   573,
     574,   575,   576,   577,   578,   582,  -876,  -876,   673,   676,
     435,   678,   681,   686,   687,   664,   688,   713,   435,   435,
     714,   714,   583,  -876,  -876,   694,    70,   695,   652,   587,
     699,   700,   701,   702,   724,   704,   706,   707,   600,  -876,
     709,   711,   608,  -876,   612,  -876,   721,   722,   616,   618,
    -876,   620,   621,   622,   625,   626,   635,   636,   641,   643,
     646,   648,   654,   669,   670,   675,   677,   679,   682,   693,
     708,   715,   716,   717,   718,   720,   723,   725,   726,   727,
     728,   729,   683,   730,   712,   731,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   742,   743,   744,   745,   746,
     747,   750,   751,   752,   753,   754,  -876,  -876,   748,   757,
     647,   772,   761,   791,   809,   814,   758,  -876,   819,   719,
     820,   759,  -876,  -876,   760,   822,   829,   853,   762,  -876,
     764,  -876,    38,   765,   766,  -876,  -876,   849,   823,   767,
     869,   875,   876,   768,   877,   773,  -876,  -876,   880,   882,
     883,   776,  -876,   779,   780,   781,   782,   783,   784,  -876,
     785,   786,   787,   788,   789,   790,   794,   795,  -876,  -876,
    -217,  -876,  -876,  -876,  -212,  -876,   796,   797,   798,   799,
     800,  -876,  -876,   899,   801,   909,   802,  -876,  -876,   913,
     803,   807,  -876,   808,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   435,   435,   435,   435,   435,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   810,
     811,   813,   815,   816,   817,   818,   821,   824,   825,   826,
     827,   214,   828,   830,  -876,   831,   832,   833,   834,   835,
     113,   836,   837,   838,   839,   840,   841,   842,   843,  -876,
     844,   845,  -876,  -876,   846,   847,   912,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -211,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -190,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   848,   850,   314,   851,   852,
     854,   855,   856,  -876,   857,   917,   858,  -876,   -27,   859,
     860,   674,   611,  -876,  -876,  -876,   861,   862,  -876,   863,
      60,  -876,  -876,  -876,  -876,  -876,  -876,   864,   867,   558,
     868,   870,   871,   741,   872,  -876,   873,   874,   878,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,    49,  -876,    63,  -876,  -876,
    -876,  -876,  -876,   879,   277,   881,  -876,   884,   629,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   714,   714,
     714,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -189,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -183,
    -876,  -876,   683,  -876,   712,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -181,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -168,  -876,  -876,  -876,  -876,
    -876,  -158,  -876,  -876,  -876,   948,   853,   885,  -876,   928,
     866,  -104,   886,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -150,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -142,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   -43,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   -34,  -876,  -876,  -876,  -876,  -876,   113,
    -876,   912,  -876,  -876,  -876,   314,  -876,   917,  -876,   -27,
    -876,  -876,  -876,   887,    -4,   888,   889,  -876,  -876,   558,
    -876,   741,  -876,   277,  -876,   629,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   -20,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,    -4,  -876
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -876,  -876,  -876,  -395,  -306,  -875,  -610,  -876,  -876,   624,
    -876,  -876,  -876,  -876,   793,  -876,  -876,  -876,    57,  -876,
      81,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   990,  -876,  -876,  -876,
    -876,  -876,   891,  -876,  -876,  -876,  -876,   131,  -876,  -876,
    -876,  -876,  -876,  -156,  -876,  -876,  -876,   589,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -106,  -876,  -876,
    -876,  -105,  -876,  -876,  -876,   804,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   -93,  -876,   633,  -876,  -876,
    -876,    24,  -876,  -876,  -876,  -876,  -876,   655,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   -76,  -876,  -876,  -876,  -876,
    -876,  -876,   604,  -876,  -876,  -876,  -876,  -876,   865,  -876,
    -876,  -876,  -876,   572,  -876,  -876,  -876,  -876,  -876,   -91,
    -876,  -876,  -876,   563,  -876,  -876,  -876,  -876,   -90,  -876,
    -876,  -876,   770,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   -62,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,   -69,  -876,   660,  -876,  -876,  -876,
    -876,  -876,   763,  -876,  -876,  -876,  -876,  1029,  -876,  -876,
    -876,  -876,  -876,  -876,   -59,  -876,   749,  -876,  -876,  -876,
    -876,   973,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,    74,  -876,  -876,  -876,    77,  -876,  -876,
    -876,  -876,  -876,  1053,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
     895,  -876,  -876,  -876,  -876,  -876,  -876
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     822,   823,   585,   586,   244,    67,   821,    47,   483,    67,
     593,   558,   228,   474,   391,   110,   294,   523,   381,   294,
     567,   110,  1004,   381,   523,    48,  1005,  1006,  1071,   235,
     299,  1007,  1072,  1098,    68,   455,   524,   504,    68,   966,
      45,    46,    69,   524,  1232,   567,    69,    52,   245,  1073,
    1198,   484,   474,  1074,  1199,    54,  1200,   456,  1204,   505,
    1201,   966,  1205,   246,   247,   248,   249,  1233,    58,  1234,
     228,  1206,   485,   300,   457,  1207,   506,   486,   458,    59,
     507,  1208,    62,   250,   111,  1209,   235,   382,    63,  1218,
     111,   301,   382,  1219,    66,   642,   643,  1220,   391,   116,
     107,  1221,   108,   650,    70,   652,   117,   118,    70,  1215,
     559,  1235,   659,   392,   109,   295,   119,   664,   295,   568,
     525,   558,   115,  1050,   120,  1051,   236,   525,   675,   676,
     121,   678,   122,   123,   225,   124,   508,   487,   967,   688,
     689,   125,   691,   259,   568,   475,   393,   126,   127,   526,
     383,   128,   129,   130,   237,   383,   526,   131,   226,   459,
     967,   509,   132,  1195,  1196,  1197,   133,   134,   460,   461,
     135,   227,   260,   136,   137,    76,   560,  1099,   476,   394,
     510,   138,  1100,   236,   475,   569,  1236,  1237,   139,   140,
     242,   141,   142,   143,   144,   145,  1222,   392,   758,   759,
    1223,    77,    78,   462,   968,  1224,   146,    79,   261,  1225,
     569,   237,   762,   763,   147,   148,   149,   476,   150,  1247,
     559,   151,   152,  1248,  1238,   153,   968,  1038,  1039,  1040,
     393,   748,   682,   683,   684,   685,   154,   302,   561,   243,
     477,   229,   262,   538,   263,   264,   511,   718,   303,  -107,
     776,    80,    81,   639,   389,   575,   741,   632,    82,    83,
      84,   155,   463,   394,   512,   156,   826,   827,   502,   157,
     158,   159,   160,   161,   706,   969,   735,   162,   163,   477,
      85,    86,   292,   293,   781,   265,   560,   266,   267,   268,
     269,   711,   321,   494,   811,    87,    88,   969,   577,   229,
    1112,   305,   819,   820,   270,   498,    89,  -107,   306,   496,
     307,   499,   322,   323,   455,    90,   324,   308,   164,   165,
     309,   166,  1052,   352,   821,   353,   310,   167,   354,   168,
     271,   311,   312,  1077,   169,  1053,   456,   313,   453,   581,
     582,   272,   314,   315,   316,   355,   317,   352,   561,   353,
    1169,   318,   354,   457,   388,  1078,   400,   458,   401,   402,
     403,   404,   356,   584,   405,  1079,   357,   406,   407,   355,
     408,   409,  1080,   504,   273,   274,   410,   411,   325,   326,
     327,   412,   556,   328,   540,   413,   356,   358,  1081,   359,
     357,   329,   414,   415,   416,   505,  1021,  1022,  1023,  1024,
    1025,   360,   417,   330,   331,   418,   791,   792,   793,   794,
     795,   358,   506,   359,   319,  1082,   507,   419,   420,   332,
     333,   421,   361,  1083,   422,   360,   423,   424,  1170,   425,
     426,   483,   427,   428,   429,   430,   432,   434,   459,   435,
     436,   437,   438,   439,   440,   441,   361,   460,   461,   334,
     442,   443,   362,   444,   116,   445,   578,   446,   447,  1171,
     448,   117,   118,   449,   450,   451,  1084,   452,  1172,   495,
     500,   119,   508,   501,   484,  1173,   362,   532,   533,   120,
     534,   363,   462,   535,  1085,   121,   536,   122,   123,  1174,
     124,  1175,  1176,   335,   259,   485,   125,   509,   537,   541,
     486,  1216,   126,   127,  1177,   363,   128,   129,   130,   542,
     364,  1178,   131,   543,   544,   545,   510,   132,   546,   579,
     547,   133,   134,   260,   244,   135,   548,   549,   136,   137,
     550,   612,   551,   580,   364,   552,   138,   553,   554,   555,
     574,   463,   583,   139,   140,   584,   141,   142,   143,   144,
     145,   587,   588,   589,   365,   590,   591,   592,   594,   261,
     487,   146,   628,  1116,   634,   595,   596,   597,   245,   147,
     148,   149,   598,   150,   599,   600,   151,   152,   365,   601,
     153,   602,   511,   246,   247,   248,   249,   603,   614,  1117,
     604,   154,   605,   262,   606,   263,   264,   607,   608,   609,
     512,   610,   611,   250,   615,   616,  1118,   617,   641,   618,
     620,   621,   622,   623,  1119,   624,   155,   625,   626,   627,
     156,   644,   635,   630,   157,   158,   159,   160,   161,   631,
     645,  1120,   162,   163,   636,   637,   265,   646,   266,   267,
     268,   269,   647,   648,   649,   651,   653,   654,   655,   656,
     657,   658,   660,   661,   662,   270,  1121,   663,   665,   666,
     667,   668,   669,  1122,   670,   671,   672,   673,   674,   698,
     677,   679,   680,   164,   165,   681,   166,  1123,   686,   687,
     692,   271,   167,   693,   168,     2,     3,   690,   696,   169,
       4,   321,   272,   694,   695,  1124,   697,  1125,  1126,   713,
     699,   701,  1183,   720,   702,     5,   703,   704,     6,     7,
     723,   322,   323,   705,     8,   324,   724,   743,   708,   744,
     710,   715,   716,   717,   721,   273,   274,     9,   722,   725,
     745,    10,    11,   746,   727,   747,   726,   750,   751,   737,
     728,   752,    12,   879,   753,   754,   755,   730,   731,  1127,
     732,   734,   738,   749,   756,   739,    13,   740,   757,  1128,
     768,   766,   767,   769,  1129,   770,    14,    15,   773,   771,
    1130,   783,   902,   772,  1131,   775,  1132,   325,   326,   327,
    1184,   778,   328,   809,    16,  1133,   810,   779,   812,   784,
     329,   813,  1134,   785,   786,   816,   814,   815,   817,   787,
      17,  1140,   330,   331,   788,   789,   790,   798,   799,   800,
     801,  1185,   802,   803,   804,   805,   806,   807,   332,   333,
    1186,   808,   824,   818,   821,   825,   828,  1187,   829,   830,
     831,   832,   833,   834,   835,   836,    18,   837,   838,   839,
     840,  1188,   841,  1189,  1190,    19,    20,   842,   334,    21,
      22,   843,   844,   845,  1106,  1105,  1191,   847,   846,   848,
     849,   850,   503,  1192,   851,   852,   880,   881,   882,   883,
     884,   949,   885,   886,   853,   854,   887,   888,   889,   945,
     855,   890,   856,   891,   892,   857,   893,   858,   894,   947,
     895,   896,   335,   859,   897,   903,   904,   905,   906,   907,
     898,   908,   909,   948,    23,   910,   911,   912,   860,   861,
     913,    76,   914,   915,   862,   916,   863,   917,   864,   918,
     919,   865,   950,   920,  1141,  1142,  1143,  1144,  1145,   921,
    1146,  1147,   866,   946,  1148,  1149,  1150,    77,    78,  1151,
     951,  1152,  1153,    79,  1154,   952,  1155,   867,  1156,  1157,
     954,   956,  1158,   959,   868,   869,   870,   871,  1159,   872,
     960,   955,   873,   961,   874,   875,   876,   877,   878,   901,
     924,   925,   926,   927,   928,   929,   930,   931,   932,   933,
     977,   934,   935,   936,   937,   938,   939,    80,    81,   940,
     941,   942,   943,   944,    82,    83,    84,   953,   957,   978,
     980,   964,   958,   965,   975,   976,   981,   982,   984,   979,
     983,   986,   985,   987,   988,   989,    85,    86,   990,   991,
     992,   993,   994,   995,   996,   997,   998,   999,  1000,  1001,
    1013,    87,    88,  1002,  1003,  1008,  1009,  1010,  1011,  1012,
    1015,  1016,    89,  1014,  1017,  1018,  1019,  1020,  1068,  1026,
    1027,    90,  1028,  1094,  1029,  1030,  1031,  1032,  1210,  1213,
    1033,   304,  1166,  1034,  1035,  1036,  1037,  1043,   557,  1044,
    1045,  1046,  1047,  1048,  1049,  1056,  1057,  1058,  1059,  1060,
    1061,  1062,  1063,  1064,  1065,  1066,  1067,  1075,  1167,  1076,
    1088,  1089,  1249,  1090,  1091,  1092,  1093,  1097,  1103,  1104,
    1108,  1113,   736,  1114,  1109,  1111,  1115,  1137,  1214,  1138,
    1139,  1162,  1163,  1164,  1243,  1244,  1230,  1165,  1168,   707,
    1181,   497,   719,  1182,  1212,  1217,  1231,  1241,  1242,  1228,
    1211,   742,  1245,   782,   777,  1246,   629,  1226,  1229,   712,
     613,   390,  1227,   454,   320,   640,   539,   633,  1203,  1202,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-876))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     610,   611,   308,   309,     1,     1,   110,   241,     1,     1,
     316,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,   239,     1,     1,   241,   243,   239,   239,     1,
     239,   243,   243,    60,    30,     1,    20,     1,    30,     1,
     239,   240,    38,    20,    48,     1,    38,   241,    45,   239,
     239,    44,     1,   243,   243,   241,   239,    23,   239,    23,
     243,     1,   243,    60,    61,    62,    63,    71,   241,    73,
       1,   239,    65,   242,    40,   243,    40,    70,    44,   241,
      44,   239,   241,    80,    70,   243,     1,    70,   241,   239,
      70,   242,    70,   243,   241,   401,   402,   239,     1,     1,
     241,   243,   241,   409,   100,   411,     8,     9,   100,   213,
     100,   115,   418,   100,   241,   100,    18,   423,   100,   100,
     104,     1,   241,    10,    26,    12,    98,   104,   434,   435,
      32,   437,    34,    35,   241,    37,   100,   130,   100,   445,
     446,    43,   448,     1,   100,   133,   133,    49,    50,   133,
     133,    53,    54,    55,   126,   133,   133,    59,   241,   125,
     100,   125,    64,  1038,  1039,  1040,    68,    69,   134,   135,
      72,   241,    30,    75,    76,     1,   166,   204,   166,   166,
     144,    83,   209,    98,   133,   166,   190,   191,    90,    91,
     241,    93,    94,    95,    96,    97,   239,   100,   149,   150,
     243,    27,    28,   169,   166,   239,   108,    33,    66,   243,
     166,   126,   149,   150,   116,   117,   118,   166,   120,   239,
     100,   123,   124,   243,   228,   127,   166,    13,    14,    15,
     133,   537,   176,   177,   176,   177,   138,   242,   228,   241,
     228,   230,   100,   240,   102,   103,   210,   240,   240,   238,
     240,    77,    78,   240,   240,   240,   240,   240,    84,    85,
      86,   163,   228,   166,   228,   167,   196,   197,   240,   171,
     172,   173,   174,   175,   240,   237,   240,   179,   180,   228,
     106,   107,   241,   241,   240,   143,   166,   145,   146,   147,
     148,   240,     1,   239,   600,   121,   122,   237,   131,   230,
     240,   242,   608,   609,   162,   238,   132,   238,   242,   240,
     242,   239,    21,    22,     1,   141,    25,   242,   220,   221,
     242,   223,   209,     1,   110,     3,   242,   229,     6,   231,
     188,   242,   242,    19,   236,   222,    23,   242,   240,   110,
     110,   199,   242,   242,   242,    23,   242,     1,   228,     3,
      73,   242,     6,    40,   242,    41,   242,    44,   242,   242,
     242,   242,    40,   110,   242,    51,    44,   242,   242,    23,
     242,   242,    58,     1,   232,   233,   242,   242,    87,    88,
      89,   242,   240,    92,   239,   242,    40,    65,    74,    67,
      44,   100,   242,   242,   242,    23,   791,   792,   793,   794,
     795,    79,   242,   112,   113,   242,   153,   154,   155,   156,
     157,    65,    40,    67,   240,   101,    44,   242,   242,   128,
     129,   242,   100,   109,   242,    79,   242,   242,   151,   242,
     242,     1,   242,   242,   242,   242,   242,   242,   125,   242,
     242,   242,   242,   242,   242,   242,   100,   134,   135,   158,
     242,   242,   130,   242,     1,   242,   131,   242,   242,   182,
     242,     8,     9,   242,   242,   242,   152,   242,   191,   242,
     242,    18,   100,   242,    44,   198,   130,   242,   242,    26,
     242,   159,   169,   242,   170,    32,   242,    34,    35,   212,
      37,   214,   215,   202,     1,    65,    43,   125,   242,   242,
      70,  1111,    49,    50,   227,   159,    53,    54,    55,   242,
     188,   234,    59,   242,   242,   242,   144,    64,   242,   131,
     242,    68,    69,    30,     1,    72,   242,   242,    75,    76,
     242,   240,   242,   239,   188,   242,    83,   242,   242,   242,
     242,   228,   176,    90,    91,   110,    93,    94,    95,    96,
      97,   110,   110,   110,   232,   176,   176,   110,   176,    66,
     130,   108,   240,     5,   131,   176,   239,   239,    45,   116,
     117,   118,   242,   120,   242,   242,   123,   124,   232,   242,
     127,   242,   210,    60,    61,    62,    63,   242,   239,    31,
     242,   138,   242,   100,   242,   102,   103,   242,   242,   242,
     228,   242,   242,    80,   242,   242,    48,   242,   176,   242,
     242,   242,   242,   242,    56,   242,   163,   242,   242,   242,
     167,   110,   239,   242,   171,   172,   173,   174,   175,   242,
     176,    73,   179,   180,   242,   242,   143,   176,   145,   146,
     147,   148,   110,   131,   176,   176,   110,   110,   110,   176,
     176,   176,   131,   176,   110,   162,    98,   110,   110,   110,
     131,   110,   110,   105,   176,   176,   242,   176,   242,   242,
     176,   176,   176,   220,   221,   176,   223,   119,   176,   176,
     176,   188,   229,   176,   231,     0,     1,   131,   239,   236,
       5,     1,   199,   176,   176,   137,   239,   139,   140,   239,
     242,   242,    73,   176,   242,    20,   242,   242,    23,    24,
     131,    21,    22,   242,    29,    25,   131,   176,   242,   176,
     242,   242,   242,   242,   239,   232,   233,    42,   241,   239,
     131,    46,    47,   176,   242,   176,   239,   131,   176,   239,
     242,   131,    57,    60,   131,   131,   131,   242,   242,   191,
     242,   242,   242,   239,   131,   242,    71,   242,   131,   201,
     110,   131,   131,   131,   206,   131,    81,    82,   242,   239,
     212,   131,    60,   239,   216,   242,   218,    87,    88,    89,
     151,   239,    92,   110,    99,   227,   110,   242,   110,   239,
     100,   110,   234,   239,   239,   131,   110,   110,   110,   239,
     115,    60,   112,   113,   239,   239,   239,   239,   239,   239,
     239,   182,   239,   239,   239,   239,   239,   239,   128,   129,
     191,   239,   239,   110,   110,   131,   131,   198,   176,   242,
     131,   131,   131,   131,   110,   131,   151,   131,   131,   239,
     131,   212,   131,   214,   215,   160,   161,   239,   158,   164,
     165,   239,   131,   131,   243,   181,   227,   239,   242,   239,
     239,   239,   238,   234,   239,   239,   183,   184,   185,   186,
     187,   110,   189,   190,   239,   239,   193,   194,   195,   131,
     239,   198,   239,   200,   201,   239,   203,   239,   205,   242,
     207,   208,   202,   239,   211,   183,   184,   185,   186,   187,
     217,   189,   190,   131,   219,   193,   194,   195,   239,   239,
     198,     1,   200,   201,   239,   203,   239,   205,   239,   207,
     208,   239,   131,   211,   183,   184,   185,   186,   187,   217,
     189,   190,   239,   176,   193,   194,   195,    27,    28,   198,
     131,   200,   201,    33,   203,   131,   205,   239,   207,   208,
     131,   131,   211,   131,   239,   239,   239,   239,   217,   239,
     131,   242,   239,   110,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     131,   239,   239,   239,   239,   239,   239,    77,    78,   239,
     239,   239,   239,   239,    84,    85,    86,   239,   239,   176,
     131,   239,   242,   239,   239,   239,   131,   131,   131,   242,
     242,   131,   239,   131,   131,   239,   106,   107,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     131,   121,   122,   239,   239,   239,   239,   239,   239,   239,
     131,   239,   132,   242,   131,   242,   239,   239,   136,   239,
     239,   141,   239,   136,   239,   239,   239,   239,   110,   131,
     239,    71,  1005,   239,   239,   239,   239,   239,   275,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,  1007,   239,
     239,   239,  1248,   239,   239,   239,   239,   239,   239,   239,
     239,   970,   513,   239,   242,   242,   239,   239,   242,   239,
     239,   239,   239,   239,  1219,  1221,  1209,   239,   239,   464,
     239,   230,   489,   239,   239,   239,   239,   239,   239,  1205,
    1106,   527,  1223,   570,   562,  1225,   366,  1199,  1207,   479,
     336,   112,  1201,   170,    91,   396,   251,   384,  1074,  1072,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   245,     0,     1,     5,    20,    23,    24,    29,    42,
      46,    47,    57,    71,    81,    82,    99,   115,   151,   160,
     161,   164,   165,   219,   246,   251,   256,   278,   284,   298,
     316,   334,   348,   363,   370,   374,   384,   393,   413,   423,
     429,   433,   443,   505,   522,   239,   240,   241,   241,   317,
     394,   424,   241,   434,   241,   349,   414,   335,   241,   241,
     299,   364,   241,   241,   375,   385,   241,     1,    30,    38,
     100,   279,   280,   281,   282,   283,     1,    27,    28,    33,
      77,    78,    84,    85,    86,   106,   107,   121,   122,   132,
     141,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   241,   241,   241,
       1,    70,   430,   431,   432,   241,     1,     8,     9,    18,
      26,    32,    34,    35,    37,    43,    49,    50,    53,    54,
      55,    59,    64,    68,    69,    72,    75,    76,    83,    90,
      91,    93,    94,    95,    96,    97,   108,   116,   117,   118,
     120,   123,   124,   127,   138,   163,   167,   171,   172,   173,
     174,   175,   179,   180,   220,   221,   223,   229,   231,   236,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   498,   502,   503,   504,   241,   241,   241,     1,   230,
     285,   286,   287,   288,   289,     1,    98,   126,   252,   253,
     254,   255,   241,   241,     1,    45,    60,    61,    62,    63,
      80,   523,   524,   525,   526,   527,   528,   529,   530,     1,
      30,    66,   100,   102,   103,   143,   145,   146,   147,   148,
     162,   188,   199,   232,   233,   257,   258,   259,   260,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   241,   241,     1,   100,   371,   372,   373,   239,
     242,   242,   242,   240,   280,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   240,
     507,     1,    21,    22,    25,    87,    88,    89,    92,   100,
     112,   113,   128,   129,   158,   202,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,     1,     3,     6,    23,    40,    44,    65,    67,
      79,   100,   130,   159,   188,   232,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   408,   409,   410,   411,
     412,     1,    70,   133,   425,   426,   427,   428,   242,   240,
     431,     1,   100,   133,   166,   435,   439,   440,   441,   442,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   499,   242,   495,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   240,   445,     1,    23,    40,    44,   125,
     134,   135,   169,   228,   350,   351,   352,   353,   354,   355,
     356,   360,   361,   362,     1,   133,   166,   228,   415,   419,
     420,   421,   422,     1,    44,    65,    70,   130,   336,   340,
     341,   342,   346,   347,   239,   242,   240,   286,   238,   239,
     242,   242,   240,   253,     1,    23,    40,    44,   100,   125,
     144,   210,   228,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   312,     1,    20,   104,   133,   365,   366,   367,
     368,   369,   242,   242,   242,   242,   242,   242,   240,   524,
     239,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   240,   258,     1,   100,
     166,   228,   376,   377,   378,   379,   380,     1,   100,   166,
     386,   387,   388,   389,   242,   240,   372,   131,   131,   131,
     239,   110,   110,   176,   110,   248,   248,   110,   110,   110,
     176,   176,   110,   248,   176,   176,   239,   239,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   240,   319,   239,   242,   242,   242,   242,   405,
     242,   242,   242,   242,   242,   242,   242,   242,   240,   396,
     242,   242,   240,   426,   131,   239,   242,   242,   436,   240,
     440,   176,   248,   248,   110,   176,   176,   110,   131,   176,
     248,   176,   248,   110,   110,   110,   176,   176,   176,   248,
     131,   176,   110,   110,   248,   110,   110,   131,   110,   110,
     176,   176,   242,   176,   242,   248,   248,   176,   248,   176,
     176,   176,   176,   177,   176,   177,   176,   176,   248,   248,
     131,   248,   176,   176,   176,   176,   239,   239,   242,   242,
     357,   242,   242,   242,   242,   242,   240,   351,   242,   416,
     242,   240,   420,   239,   337,   242,   242,   242,   240,   341,
     176,   239,   241,   131,   131,   239,   239,   242,   242,   313,
     242,   242,   242,   309,   242,   240,   301,   239,   242,   242,
     242,   240,   366,   176,   176,   131,   176,   176,   248,   239,
     131,   176,   131,   131,   131,   131,   131,   131,   149,   150,
     261,   262,   149,   150,   263,   264,   131,   131,   110,   131,
     131,   239,   239,   242,   381,   242,   240,   377,   239,   242,
     390,   240,   387,   131,   239,   239,   239,   239,   239,   239,
     239,   153,   154,   155,   156,   157,   247,   248,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   110,
     110,   248,   110,   110,   110,   110,   131,   110,   110,   248,
     248,   110,   250,   250,   239,   131,   196,   197,   131,   176,
     242,   131,   131,   131,   131,   110,   131,   131,   131,   239,
     131,   131,   239,   239,   131,   131,   242,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,    60,
     183,   184,   185,   186,   187,   189,   190,   193,   194,   195,
     198,   200,   201,   203,   205,   207,   208,   211,   217,   500,
     501,   239,    60,   183,   184,   185,   186,   187,   189,   190,
     193,   194,   195,   198,   200,   201,   203,   205,   207,   208,
     211,   217,   496,   497,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   131,   176,   242,   131,   110,
     131,   131,   131,   239,   131,   242,   131,   239,   242,   131,
     131,   110,   344,   345,   239,   239,     1,   100,   166,   237,
     290,   291,   292,   293,   294,   239,   239,   131,   176,   242,
     131,   131,   131,   242,   131,   239,   131,   131,   131,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   243,   239,   243,   239,   239,
     239,   239,   239,   131,   242,   131,   239,   131,   242,   239,
     239,   247,   247,   247,   247,   247,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,    13,    14,
      15,   249,   250,   239,   239,   239,   239,   239,   239,   239,
      10,    12,   209,   222,   406,   407,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   136,   437,
     438,   239,   243,   239,   243,   239,   239,    19,    41,    51,
      58,    74,   101,   109,   152,   170,   358,   359,   239,   239,
     239,   239,   239,   239,   136,   417,   418,   239,    60,   204,
     209,   338,   339,   239,   239,   181,   243,   343,   239,   242,
     295,   242,   240,   291,   239,   239,     5,    31,    48,    56,
      73,    98,   105,   119,   137,   139,   140,   191,   201,   206,
     212,   216,   218,   227,   234,   314,   315,   239,   239,   239,
      60,   183,   184,   185,   186,   187,   189,   190,   193,   194,
     195,   198,   200,   201,   203,   205,   207,   208,   211,   217,
     310,   311,   239,   239,   239,   239,   262,   264,   239,    73,
     151,   182,   191,   198,   212,   214,   215,   227,   234,   382,
     383,   239,   239,    73,   151,   182,   191,   198,   212,   214,
     215,   227,   234,   391,   392,   249,   249,   249,   239,   243,
     239,   243,   501,   497,   239,   243,   239,   243,   239,   243,
     110,   345,   239,   131,   242,   213,   250,   239,   239,   243,
     239,   243,   239,   243,   239,   243,   407,   438,   359,   418,
     339,   239,    48,    71,    73,   115,   190,   191,   228,   296,
     297,   239,   239,   315,   311,   383,   392,   239,   243,   297
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
#line 381 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 383 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 387 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 391 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 409 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 457 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 463 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 472 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 478 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 486 "conf_parser.y"
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
#line 525 "conf_parser.y"
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
#line 584 "conf_parser.y"
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
#line 612 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 620 "conf_parser.y"
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
#line 635 "conf_parser.y"
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
#line 650 "conf_parser.y"
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
#line 659 "conf_parser.y"
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
#line 673 "conf_parser.y"
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
#line 682 "conf_parser.y"
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
#line 710 "conf_parser.y"
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
#line 740 "conf_parser.y"
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
#line 763 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 778 "conf_parser.y"
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
#line 787 "conf_parser.y"
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
#line 796 "conf_parser.y"
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
#line 814 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 820 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 837 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 842 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 845 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 877 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 891 "conf_parser.y"
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
#line 904 "conf_parser.y"
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
#line 994 "conf_parser.y"
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
#line 1003 "conf_parser.y"
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
#line 1040 "conf_parser.y"
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
#line 1052 "conf_parser.y"
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
#line 1063 "conf_parser.y"
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
#line 1105 "conf_parser.y"
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
#line 1114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1292 "conf_parser.y"
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
#line 1299 "conf_parser.y"
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
#line 1357 "conf_parser.y"
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
#line 1366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1378 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1384 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1396 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1402 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1420 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1427 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1448 "conf_parser.y"
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
#line 1455 "conf_parser.y"
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
#line 1464 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1488 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1493 "conf_parser.y"
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
#line 1507 "conf_parser.y"
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
#line 1527 "conf_parser.y"
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
#line 1536 "conf_parser.y"
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
#line 1548 "conf_parser.y"
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
#line 1560 "conf_parser.y"
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
#line 1622 "conf_parser.y"
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
#line 1657 "conf_parser.y"
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
#line 1670 "conf_parser.y"
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
#line 1679 "conf_parser.y"
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
#line 1690 "conf_parser.y"
    {
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1695 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1699 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1703 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1707 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1711 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1715 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1719 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1723 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1727 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1734 "conf_parser.y"
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
#line 1753 "conf_parser.y"
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
#line 1763 "conf_parser.y"
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
#line 1776 "conf_parser.y"
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
#line 1783 "conf_parser.y"
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
#line 1795 "conf_parser.y"
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
#line 1804 "conf_parser.y"
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
#line 1819 "conf_parser.y"
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
#line 1837 "conf_parser.y"
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
#line 1852 "conf_parser.y"
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
#line 1860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1871 "conf_parser.y"
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
#line 1880 "conf_parser.y"
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
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1921 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1929 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1954 "conf_parser.y"
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
#line 1961 "conf_parser.y"
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
#line 1974 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1995 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 2003 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2007 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2011 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 2015 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2019 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2023 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2032 "conf_parser.y"
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
#line 2047 "conf_parser.y"
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
#line 2091 "conf_parser.y"
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
#line 2100 "conf_parser.y"
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
#line 2109 "conf_parser.y"
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
#line 2135 "conf_parser.y"
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
#line 2153 "conf_parser.y"
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
#line 2171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2181 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 2189 "conf_parser.y"
    {
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2212 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2254 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 2279 "conf_parser.y"
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

  case 389:
/* Line 1787 of yacc.c  */
#line 2337 "conf_parser.y"
    {
}
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 2342 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2351 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2379 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2383 "conf_parser.y"
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

  case 409:
/* Line 1787 of yacc.c  */
#line 2407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2427 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2452 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2492 "conf_parser.y"
    {
}
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2506 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2512 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2568 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2574 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2655 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2666 "conf_parser.y"
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

  case 511:
/* Line 1787 of yacc.c  */
#line 2677 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2682 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2711 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2752 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2807 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2821 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2826 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2894 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2905 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2917 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2923 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2929 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2935 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2947 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2950 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2953 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2959 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2962 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2972 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2977 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 3000 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 3010 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 3015 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3025 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3030 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3040 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3045 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 3055 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 3060 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 3065 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 3083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 3089 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 634:
/* Line 1787 of yacc.c  */
#line 3095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 3104 "conf_parser.y"
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

  case 636:
/* Line 1787 of yacc.c  */
#line 3118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 3124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6964 "conf_parser.c"
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


