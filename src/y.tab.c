/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     CAN_IDLE = 276,
     CHANNEL = 277,
     CIDR_BITLEN_IPV4 = 278,
     CIDR_BITLEN_IPV6 = 279,
     CIPHER_PREFERENCE = 280,
     CLASS = 281,
     COMPRESSED = 282,
     COMPRESSION_LEVEL = 283,
     CONNECT = 284,
     CONNECTFREQ = 285,
     CRYPTLINK = 286,
     DEFAULT_CIPHER_PREFERENCE = 287,
     DEFAULT_FLOODCOUNT = 288,
     DEFAULT_SPLIT_SERVER_COUNT = 289,
     DEFAULT_SPLIT_USER_COUNT = 290,
     DENY = 291,
     DESCRIPTION = 292,
     DIE = 293,
     DISABLE_AUTH = 294,
     DISABLE_HIDDEN = 295,
     DISABLE_LOCAL_CHANNELS = 296,
     DISABLE_REMOTE_COMMANDS = 297,
     DOT_IN_IP6_ADDR = 298,
     DOTS_IN_IDENT = 299,
     DURATION = 300,
     EGDPOOL_PATH = 301,
     EMAIL = 302,
     ENABLE = 303,
     ENCRYPTED = 304,
     EXCEED_LIMIT = 305,
     EXEMPT = 306,
     FAILED_OPER_NOTICE = 307,
     FAKENAME = 308,
     IRCD_FLAGS = 309,
     FLATTEN_LINKS = 310,
     FFAILED_OPERLOG = 311,
     FKILLLOG = 312,
     FKLINELOG = 313,
     FGLINELOG = 314,
     FIOERRLOG = 315,
     FOPERLOG = 316,
     FOPERSPYLOG = 317,
     FUSERLOG = 318,
     GECOS = 319,
     GENERAL = 320,
     GLINE = 321,
     GLINES = 322,
     GLINE_EXEMPT = 323,
     GLINE_LOG = 324,
     GLINE_TIME = 325,
     GLINE_MIN_CIDR = 326,
     GLINE_MIN_CIDR6 = 327,
     GLOBAL_KILL = 328,
     IRCD_AUTH = 329,
     NEED_IDENT = 330,
     HAVENT_READ_CONF = 331,
     HIDDEN = 332,
     HIDDEN_ADMIN = 333,
     HIDDEN_NAME = 334,
     HIDDEN_OPER = 335,
     HIDE_SERVER_IPS = 336,
     HIDE_SERVERS = 337,
     HIDE_SPOOF_IPS = 338,
     HOST = 339,
     HUB = 340,
     HUB_MASK = 341,
     IDLETIME = 342,
     IGNORE_BOGUS_TS = 343,
     INVISIBLE_ON_CONNECT = 344,
     IP = 345,
     KILL = 346,
     KILL_CHASE_TIME_LIMIT = 347,
     KLINE = 348,
     KLINE_EXEMPT = 349,
     KLINE_REASON = 350,
     KLINE_WITH_REASON = 351,
     KNOCK_DELAY = 352,
     KNOCK_DELAY_CHANNEL = 353,
     LAZYLINK = 354,
     LEAF_MASK = 355,
     LINKS_DELAY = 356,
     LISTEN = 357,
     T_LOG = 358,
     LOGGING = 359,
     LOG_LEVEL = 360,
     MAX_ACCEPT = 361,
     MAX_BANS = 362,
     MAX_CHANS_PER_USER = 363,
     MAX_GLOBAL = 364,
     MAX_IDENT = 365,
     MAX_LOCAL = 366,
     MAX_NICK_CHANGES = 367,
     MAX_NICK_TIME = 368,
     MAX_NUMBER = 369,
     MAX_TARGETS = 370,
     MESSAGE_LOCALE = 371,
     MIN_NONWILDCARD = 372,
     MIN_NONWILDCARD_SIMPLE = 373,
     MODULE = 374,
     MODULES = 375,
     NAME = 376,
     NEED_PASSWORD = 377,
     NETWORK_DESC = 378,
     NETWORK_NAME = 379,
     NICK = 380,
     NICK_CHANGES = 381,
     NO_CREATE_ON_SPLIT = 382,
     NO_JOIN_ON_SPLIT = 383,
     NO_OPER_FLOOD = 384,
     NO_TILDE = 385,
     NOT = 386,
     NUMBER = 387,
     NUMBER_PER_IDENT = 388,
     NUMBER_PER_CIDR = 389,
     NUMBER_PER_IP = 390,
     NUMBER_PER_IP_GLOBAL = 391,
     OPERATOR = 392,
     OPERS_BYPASS_CALLERID = 393,
     OPER_LOG = 394,
     OPER_ONLY_UMODES = 395,
     OPER_PASS_RESV = 396,
     OPER_SPY_T = 397,
     OPER_UMODES = 398,
     JOIN_FLOOD_COUNT = 399,
     JOIN_FLOOD_TIME = 400,
     PACE_WAIT = 401,
     PACE_WAIT_SIMPLE = 402,
     PASSWORD = 403,
     PATH = 404,
     PING_COOKIE = 405,
     PING_TIME = 406,
     PING_WARNING = 407,
     PORT = 408,
     QSTRING = 409,
     QUIET_ON_BAN = 410,
     REASON = 411,
     REDIRPORT = 412,
     REDIRSERV = 413,
     REGEX_T = 414,
     REHASH = 415,
     TREJECT_HOLD_TIME = 416,
     REMOTE = 417,
     REMOTEBAN = 418,
     RESTRICT_CHANNELS = 419,
     RESTRICTED = 420,
     RSA_PRIVATE_KEY_FILE = 421,
     RSA_PUBLIC_KEY_FILE = 422,
     SSL_CERTIFICATE_FILE = 423,
     RESV = 424,
     RESV_EXEMPT = 425,
     SECONDS = 426,
     MINUTES = 427,
     HOURS = 428,
     DAYS = 429,
     WEEKS = 430,
     SENDQ = 431,
     SEND_PASSWORD = 432,
     SERVERHIDE = 433,
     SERVERINFO = 434,
     SERVLINK_PATH = 435,
     IRCD_SID = 436,
     TKLINE_EXPIRE_NOTICES = 437,
     T_SHARED = 438,
     T_CLUSTER = 439,
     TYPE = 440,
     SHORT_MOTD = 441,
     SILENT = 442,
     SPOOF = 443,
     SPOOF_NOTICE = 444,
     STATS_E_DISABLED = 445,
     STATS_I_OPER_ONLY = 446,
     STATS_K_OPER_ONLY = 447,
     STATS_O_OPER_ONLY = 448,
     STATS_P_OPER_ONLY = 449,
     TBOOL = 450,
     TMASKED = 451,
     T_REJECT = 452,
     TS_MAX_DELTA = 453,
     TS_WARN_DELTA = 454,
     TWODOTS = 455,
     T_ALL = 456,
     T_BOTS = 457,
     T_SOFTCALLERID = 458,
     T_CALLERID = 459,
     T_CCONN = 460,
     T_CLIENT_FLOOD = 461,
     T_DEAF = 462,
     T_DEBUG = 463,
     T_DRONE = 464,
     T_EXTERNAL = 465,
     T_FULL = 466,
     T_INVISIBLE = 467,
     T_IPV4 = 468,
     T_IPV6 = 469,
     T_LOCOPS = 470,
     T_LOGPATH = 471,
     T_L_CRIT = 472,
     T_L_DEBUG = 473,
     T_L_ERROR = 474,
     T_L_INFO = 475,
     T_L_NOTICE = 476,
     T_L_TRACE = 477,
     T_L_WARN = 478,
     T_MAX_CLIENTS = 479,
     T_NCHANGE = 480,
     T_OPERWALL = 481,
     T_REJ = 482,
     T_SERVNOTICE = 483,
     T_SKILL = 484,
     T_SPY = 485,
     T_SSL = 486,
     T_UMODES = 487,
     T_UNAUTH = 488,
     T_UNRESV = 489,
     T_UNXLINE = 490,
     T_WALLOP = 491,
     THROTTLE_TIME = 492,
     TOPICBURST = 493,
     TRUE_NO_OPER_FLOOD = 494,
     TKLINE = 495,
     TXLINE = 496,
     TRESV = 497,
     UNKLINE = 498,
     USER = 499,
     USE_EGD = 500,
     USE_EXCEPT = 501,
     USE_INVEX = 502,
     USE_KNOCK = 503,
     USE_LOGGING = 504,
     USE_WHOIS_ACTUALLY = 505,
     VHOST = 506,
     VHOST6 = 507,
     XLINE = 508,
     WARN = 509,
     WARN_NO_NLINE = 510
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
#define CAN_IDLE 276
#define CHANNEL 277
#define CIDR_BITLEN_IPV4 278
#define CIDR_BITLEN_IPV6 279
#define CIPHER_PREFERENCE 280
#define CLASS 281
#define COMPRESSED 282
#define COMPRESSION_LEVEL 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CRYPTLINK 286
#define DEFAULT_CIPHER_PREFERENCE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_SPLIT_SERVER_COUNT 289
#define DEFAULT_SPLIT_USER_COUNT 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_AUTH 294
#define DISABLE_HIDDEN 295
#define DISABLE_LOCAL_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DOT_IN_IP6_ADDR 298
#define DOTS_IN_IDENT 299
#define DURATION 300
#define EGDPOOL_PATH 301
#define EMAIL 302
#define ENABLE 303
#define ENCRYPTED 304
#define EXCEED_LIMIT 305
#define EXEMPT 306
#define FAILED_OPER_NOTICE 307
#define FAKENAME 308
#define IRCD_FLAGS 309
#define FLATTEN_LINKS 310
#define FFAILED_OPERLOG 311
#define FKILLLOG 312
#define FKLINELOG 313
#define FGLINELOG 314
#define FIOERRLOG 315
#define FOPERLOG 316
#define FOPERSPYLOG 317
#define FUSERLOG 318
#define GECOS 319
#define GENERAL 320
#define GLINE 321
#define GLINES 322
#define GLINE_EXEMPT 323
#define GLINE_LOG 324
#define GLINE_TIME 325
#define GLINE_MIN_CIDR 326
#define GLINE_MIN_CIDR6 327
#define GLOBAL_KILL 328
#define IRCD_AUTH 329
#define NEED_IDENT 330
#define HAVENT_READ_CONF 331
#define HIDDEN 332
#define HIDDEN_ADMIN 333
#define HIDDEN_NAME 334
#define HIDDEN_OPER 335
#define HIDE_SERVER_IPS 336
#define HIDE_SERVERS 337
#define HIDE_SPOOF_IPS 338
#define HOST 339
#define HUB 340
#define HUB_MASK 341
#define IDLETIME 342
#define IGNORE_BOGUS_TS 343
#define INVISIBLE_ON_CONNECT 344
#define IP 345
#define KILL 346
#define KILL_CHASE_TIME_LIMIT 347
#define KLINE 348
#define KLINE_EXEMPT 349
#define KLINE_REASON 350
#define KLINE_WITH_REASON 351
#define KNOCK_DELAY 352
#define KNOCK_DELAY_CHANNEL 353
#define LAZYLINK 354
#define LEAF_MASK 355
#define LINKS_DELAY 356
#define LISTEN 357
#define T_LOG 358
#define LOGGING 359
#define LOG_LEVEL 360
#define MAX_ACCEPT 361
#define MAX_BANS 362
#define MAX_CHANS_PER_USER 363
#define MAX_GLOBAL 364
#define MAX_IDENT 365
#define MAX_LOCAL 366
#define MAX_NICK_CHANGES 367
#define MAX_NICK_TIME 368
#define MAX_NUMBER 369
#define MAX_TARGETS 370
#define MESSAGE_LOCALE 371
#define MIN_NONWILDCARD 372
#define MIN_NONWILDCARD_SIMPLE 373
#define MODULE 374
#define MODULES 375
#define NAME 376
#define NEED_PASSWORD 377
#define NETWORK_DESC 378
#define NETWORK_NAME 379
#define NICK 380
#define NICK_CHANGES 381
#define NO_CREATE_ON_SPLIT 382
#define NO_JOIN_ON_SPLIT 383
#define NO_OPER_FLOOD 384
#define NO_TILDE 385
#define NOT 386
#define NUMBER 387
#define NUMBER_PER_IDENT 388
#define NUMBER_PER_CIDR 389
#define NUMBER_PER_IP 390
#define NUMBER_PER_IP_GLOBAL 391
#define OPERATOR 392
#define OPERS_BYPASS_CALLERID 393
#define OPER_LOG 394
#define OPER_ONLY_UMODES 395
#define OPER_PASS_RESV 396
#define OPER_SPY_T 397
#define OPER_UMODES 398
#define JOIN_FLOOD_COUNT 399
#define JOIN_FLOOD_TIME 400
#define PACE_WAIT 401
#define PACE_WAIT_SIMPLE 402
#define PASSWORD 403
#define PATH 404
#define PING_COOKIE 405
#define PING_TIME 406
#define PING_WARNING 407
#define PORT 408
#define QSTRING 409
#define QUIET_ON_BAN 410
#define REASON 411
#define REDIRPORT 412
#define REDIRSERV 413
#define REGEX_T 414
#define REHASH 415
#define TREJECT_HOLD_TIME 416
#define REMOTE 417
#define REMOTEBAN 418
#define RESTRICT_CHANNELS 419
#define RESTRICTED 420
#define RSA_PRIVATE_KEY_FILE 421
#define RSA_PUBLIC_KEY_FILE 422
#define SSL_CERTIFICATE_FILE 423
#define RESV 424
#define RESV_EXEMPT 425
#define SECONDS 426
#define MINUTES 427
#define HOURS 428
#define DAYS 429
#define WEEKS 430
#define SENDQ 431
#define SEND_PASSWORD 432
#define SERVERHIDE 433
#define SERVERINFO 434
#define SERVLINK_PATH 435
#define IRCD_SID 436
#define TKLINE_EXPIRE_NOTICES 437
#define T_SHARED 438
#define T_CLUSTER 439
#define TYPE 440
#define SHORT_MOTD 441
#define SILENT 442
#define SPOOF 443
#define SPOOF_NOTICE 444
#define STATS_E_DISABLED 445
#define STATS_I_OPER_ONLY 446
#define STATS_K_OPER_ONLY 447
#define STATS_O_OPER_ONLY 448
#define STATS_P_OPER_ONLY 449
#define TBOOL 450
#define TMASKED 451
#define T_REJECT 452
#define TS_MAX_DELTA 453
#define TS_WARN_DELTA 454
#define TWODOTS 455
#define T_ALL 456
#define T_BOTS 457
#define T_SOFTCALLERID 458
#define T_CALLERID 459
#define T_CCONN 460
#define T_CLIENT_FLOOD 461
#define T_DEAF 462
#define T_DEBUG 463
#define T_DRONE 464
#define T_EXTERNAL 465
#define T_FULL 466
#define T_INVISIBLE 467
#define T_IPV4 468
#define T_IPV6 469
#define T_LOCOPS 470
#define T_LOGPATH 471
#define T_L_CRIT 472
#define T_L_DEBUG 473
#define T_L_ERROR 474
#define T_L_INFO 475
#define T_L_NOTICE 476
#define T_L_TRACE 477
#define T_L_WARN 478
#define T_MAX_CLIENTS 479
#define T_NCHANGE 480
#define T_OPERWALL 481
#define T_REJ 482
#define T_SERVNOTICE 483
#define T_SKILL 484
#define T_SPY 485
#define T_SSL 486
#define T_UMODES 487
#define T_UNAUTH 488
#define T_UNRESV 489
#define T_UNXLINE 490
#define T_WALLOP 491
#define THROTTLE_TIME 492
#define TOPICBURST 493
#define TRUE_NO_OPER_FLOOD 494
#define TKLINE 495
#define TXLINE 496
#define TRESV 497
#define UNKLINE 498
#define USER 499
#define USE_EGD 500
#define USE_EXCEPT 501
#define USE_INVEX 502
#define USE_KNOCK 503
#define USE_LOGGING 504
#define USE_WHOIS_ACTUALLY 505
#define VHOST 506
#define VHOST6 507
#define XLINE 508
#define WARN 509
#define WARN_NO_NLINE 510




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "dalloca.h"
#include "ircd.h"
#include "tools.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "pcre.h"
#include "irc_string.h"
#include "irc_getaddrinfo.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
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

extern dlink_list gdeny_items; /* XXX */

static char *resv_reason = NULL;
static char *listener_address = NULL;
static int not_atom = 0;

struct CollectItem {
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 134 "ircd_parser.y"
typedef union YYSTYPE {
  int number;
  char *string;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 709 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 721 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1396

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  340
/* YYNRULES -- Number of rules. */
#define YYNRULES  729
/* YYNRULES -- Number of states. */
#define YYNSTATES  1470

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   510

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   260,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   256,
       2,   259,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   258,     2,   257,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   161,   166,   171,   176,   181,   186,   191,
     196,   201,   206,   211,   216,   222,   225,   227,   229,   231,
     233,   236,   241,   246,   251,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     289,   294,   299,   304,   309,   314,   319,   324,   329,   334,
     339,   344,   349,   354,   359,   364,   369,   374,   379,   380,
     388,   389,   391,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   443,   448,   450,
     455,   460,   465,   470,   475,   476,   482,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   529,   534,   539,
     544,   549,   554,   559,   564,   569,   574,   579,   584,   589,
     594,   595,   601,   605,   607,   608,   612,   613,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   649,   657,   658,   660,   663,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   689,   691,   694,   699,   701,   706,   711,   716,
     721,   726,   731,   736,   741,   746,   751,   756,   761,   762,
     769,   770,   776,   780,   782,   784,   786,   789,   791,   793,
     795,   797,   799,   802,   803,   809,   813,   815,   817,   821,
     826,   831,   832,   839,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   879,   884,   889,   894,   899,   904,   905,   911,
     915,   917,   918,   922,   923,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   951,   956,   961,   966,
     971,   976,   981,   986,   991,   996,   997,  1004,  1007,  1009,
    1011,  1013,  1015,  1018,  1023,  1028,  1033,  1034,  1041,  1044,
    1046,  1048,  1050,  1052,  1055,  1060,  1065,  1066,  1072,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1101,  1108,  1111,  1113,  1115,  1117,  1120,  1125,
    1126,  1132,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1161,  1169,  1170,  1172,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,
    1218,  1223,  1225,  1230,  1235,  1240,  1245,  1250,  1255,  1260,
    1265,  1266,  1272,  1276,  1278,  1279,  1283,  1284,  1287,  1289,
    1291,  1293,  1295,  1297,  1299,  1304,  1309,  1314,  1319,  1324,
    1329,  1334,  1339,  1344,  1349,  1350,  1357,  1358,  1364,  1368,
    1370,  1372,  1375,  1377,  1379,  1381,  1383,  1385,  1390,  1395,
    1396,  1403,  1406,  1408,  1410,  1412,  1414,  1419,  1424,  1430,
    1433,  1435,  1437,  1439,  1444,  1445,  1452,  1453,  1459,  1463,
    1465,  1467,  1470,  1472,  1474,  1476,  1478,  1480,  1485,  1490,
    1496,  1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1618,
    1623,  1628,  1633,  1638,  1643,  1648,  1653,  1658,  1663,  1668,
    1673,  1678,  1683,  1688,  1693,  1698,  1703,  1708,  1713,  1718,
    1723,  1728,  1733,  1738,  1743,  1748,  1753,  1758,  1763,  1768,
    1773,  1778,  1783,  1788,  1793,  1798,  1803,  1808,  1813,  1818,
    1823,  1828,  1833,  1838,  1843,  1848,  1853,  1858,  1863,  1864,
    1870,  1874,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,
    1912,  1913,  1919,  1923,  1925,  1927,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,
    1957,  1959,  1961,  1966,  1971,  1976,  1981,  1986,  1987,  1994,
    1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,  2018,
    2023,  2024,  2030,  2034,  2036,  2038,  2040,  2045,  2050,  2051,
    2057,  2061,  2063,  2065,  2067,  2073,  2076,  2078,  2080,  2082,
    2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,
    2104,  2106,  2108,  2110,  2112,  2114,  2119,  2124,  2129,  2134,
    2139,  2144,  2149,  2154,  2159,  2164,  2169,  2174,  2179,  2184,
    2189,  2194,  2199,  2205,  2208,  2210,  2212,  2214,  2216,  2218,
    2220,  2222,  2224,  2226,  2231,  2236,  2241,  2246,  2251,  2256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     262,     0,    -1,    -1,   262,   263,    -1,   287,    -1,   293,
      -1,   308,    -1,   571,    -1,   345,    -1,   364,    -1,   378,
      -1,   273,    -1,   591,    -1,   404,    -1,   411,    -1,   421,
      -1,   430,    -1,   461,    -1,   471,    -1,   477,    -1,   491,
      -1,   555,    -1,   481,    -1,   268,    -1,     1,   256,    -1,
       1,   257,    -1,    -1,   265,    -1,   132,   264,    -1,   132,
     171,   264,    -1,   132,   172,   264,    -1,   132,   173,   264,
      -1,   132,   174,   264,    -1,   132,   175,   264,    -1,    -1,
     267,    -1,   132,   266,    -1,   132,    14,   266,    -1,   132,
      15,   266,    -1,   132,    16,   266,    -1,   120,   258,   269,
     257,   256,    -1,   269,   270,    -1,   270,    -1,   271,    -1,
     272,    -1,     1,   256,    -1,   119,   259,   154,   256,    -1,
     149,   259,   154,   256,    -1,   179,   258,   274,   257,   256,
      -1,   274,   275,    -1,   275,    -1,   278,    -1,   283,    -1,
     286,    -1,   280,    -1,   281,    -1,   282,    -1,   285,    -1,
     277,    -1,   284,    -1,   279,    -1,   276,    -1,     1,   256,
      -1,   168,   259,   154,   256,    -1,   166,   259,   154,   256,
      -1,   121,   259,   154,   256,    -1,   181,   259,   154,   256,
      -1,    37,   259,   154,   256,    -1,   124,   259,   154,   256,
      -1,   123,   259,   154,   256,    -1,   251,   259,   154,   256,
      -1,   252,   259,   154,   256,    -1,   224,   259,   132,   256,
      -1,    85,   259,   195,   256,    -1,     5,   258,   288,   257,
     256,    -1,   288,   289,    -1,   289,    -1,   290,    -1,   292,
      -1,   291,    -1,     1,   256,    -1,   121,   259,   154,   256,
      -1,    47,   259,   154,   256,    -1,    37,   259,   154,   256,
      -1,   104,   258,   294,   257,   256,    -1,   294,   295,    -1,
     295,    -1,   296,    -1,   297,    -1,   306,    -1,   307,    -1,
     298,    -1,   300,    -1,   302,    -1,   303,    -1,   305,    -1,
     301,    -1,   304,    -1,   299,    -1,     1,   256,    -1,   216,
     259,   154,   256,    -1,   139,   259,   154,   256,    -1,    63,
     259,   154,   256,    -1,    56,   259,   154,   256,    -1,    61,
     259,   154,   256,    -1,    62,   259,   154,   256,    -1,    59,
     259,   154,   256,    -1,    58,   259,   154,   256,    -1,    60,
     259,   154,   256,    -1,    57,   259,   154,   256,    -1,   105,
     259,   217,   256,    -1,   105,   259,   219,   256,    -1,   105,
     259,   223,   256,    -1,   105,   259,   221,   256,    -1,   105,
     259,   222,   256,    -1,   105,   259,   220,   256,    -1,   105,
     259,   218,   256,    -1,   249,   259,   195,   256,    -1,    -1,
     137,   309,   310,   258,   311,   257,   256,    -1,    -1,   314,
      -1,   311,   312,    -1,   312,    -1,   313,    -1,   315,    -1,
     316,    -1,   335,    -1,   336,    -1,   320,    -1,   319,    -1,
     324,    -1,   325,    -1,   327,    -1,   328,    -1,   329,    -1,
     330,    -1,   331,    -1,   326,    -1,   332,    -1,   333,    -1,
     334,    -1,   337,    -1,   317,    -1,   318,    -1,   338,    -1,
       1,   256,    -1,   121,   259,   154,   256,    -1,   154,    -1,
     244,   259,   154,   256,    -1,   148,   259,   154,   256,    -1,
      49,   259,   195,   256,    -1,   167,   259,   154,   256,    -1,
      26,   259,   154,   256,    -1,    -1,   232,   321,   259,   322,
     256,    -1,   322,   260,   323,    -1,   323,    -1,   202,    -1,
     205,    -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,
     225,    -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,
     226,    -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,
     204,    -1,   215,    -1,    73,   259,   195,   256,    -1,   162,
     259,   195,   256,    -1,   163,   259,   195,   256,    -1,    93,
     259,   195,   256,    -1,   253,   259,   195,   256,    -1,   243,
     259,   195,   256,    -1,    66,   259,   195,   256,    -1,   126,
     259,   195,   256,    -1,    38,   259,   195,   256,    -1,   160,
     259,   195,   256,    -1,     5,   259,   195,   256,    -1,    78,
     259,   195,   256,    -1,    80,   259,   195,   256,    -1,   226,
     259,   195,   256,    -1,    -1,    54,   339,   259,   340,   256,
      -1,   340,   260,   341,    -1,   341,    -1,    -1,   131,   342,
     344,    -1,    -1,   343,   344,    -1,    73,    -1,   162,    -1,
      93,    -1,   243,    -1,   253,    -1,    66,    -1,    38,    -1,
     160,    -1,     5,    -1,    78,    -1,   126,    -1,   226,    -1,
     142,    -1,    80,    -1,   163,    -1,    49,    -1,    -1,    26,
     346,   347,   258,   348,   257,   256,    -1,    -1,   351,    -1,
     348,   349,    -1,   349,    -1,   350,    -1,   361,    -1,   362,
      -1,   352,    -1,   353,    -1,   363,    -1,   354,    -1,   355,
      -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,   360,
      -1,     1,   256,    -1,   121,   259,   154,   256,    -1,   154,
      -1,   151,   259,   265,   256,    -1,   152,   259,   265,   256,
      -1,   135,   259,   132,   256,    -1,    30,   259,   265,   256,
      -1,   114,   259,   132,   256,    -1,   109,   259,   132,   256,
      -1,   111,   259,   132,   256,    -1,   110,   259,   132,   256,
      -1,   176,   259,   267,   256,    -1,    23,   259,   132,   256,
      -1,    24,   259,   132,   256,    -1,   134,   259,   132,   256,
      -1,    -1,   102,   365,   258,   370,   257,   256,    -1,    -1,
      54,   367,   259,   368,   256,    -1,   368,   260,   369,    -1,
     369,    -1,   231,    -1,    77,    -1,   370,   371,    -1,   371,
      -1,   372,    -1,   366,    -1,   376,    -1,   377,    -1,     1,
     256,    -1,    -1,   153,   259,   374,   373,   256,    -1,   374,
     260,   375,    -1,   375,    -1,   132,    -1,   132,   200,   132,
      -1,    90,   259,   154,   256,    -1,    84,   259,   154,   256,
      -1,    -1,    74,   379,   258,   380,   257,   256,    -1,   380,
     381,    -1,   381,    -1,   382,    -1,   383,    -1,   385,    -1,
     387,    -1,   394,    -1,   395,    -1,   396,    -1,   398,    -1,
     399,    -1,   400,    -1,   384,    -1,   401,    -1,   402,    -1,
     397,    -1,   403,    -1,   386,    -1,     1,   256,    -1,   244,
     259,   154,   256,    -1,   148,   259,   154,   256,    -1,   189,
     259,   195,   256,    -1,    26,   259,   154,   256,    -1,    49,
     259,   195,   256,    -1,    -1,    54,   388,   259,   389,   256,
      -1,   389,   260,   390,    -1,   390,    -1,    -1,   131,   391,
     393,    -1,    -1,   392,   393,    -1,   189,    -1,    50,    -1,
      94,    -1,    75,    -1,    20,    -1,    21,    -1,   130,    -1,
      68,    -1,   170,    -1,   122,    -1,    94,   259,   195,   256,
      -1,    75,   259,   195,   256,    -1,    50,   259,   195,   256,
      -1,    20,   259,   195,   256,    -1,   130,   259,   195,   256,
      -1,    68,   259,   195,   256,    -1,   188,   259,   154,   256,
      -1,   158,   259,   154,   256,    -1,   157,   259,   132,   256,
      -1,   122,   259,   195,   256,    -1,    -1,   169,   405,   258,
     406,   257,   256,    -1,   406,   407,    -1,   407,    -1,   408,
      -1,   409,    -1,   410,    -1,     1,   256,    -1,   156,   259,
     154,   256,    -1,    22,   259,   154,   256,    -1,   125,   259,
     154,   256,    -1,    -1,   183,   412,   258,   413,   257,   256,
      -1,   413,   414,    -1,   414,    -1,   415,    -1,   416,    -1,
     417,    -1,     1,   256,    -1,   121,   259,   154,   256,    -1,
     244,   259,   154,   256,    -1,    -1,   185,   418,   259,   419,
     256,    -1,   419,   260,   420,    -1,   420,    -1,    93,    -1,
     240,    -1,   243,    -1,   253,    -1,   241,    -1,   235,    -1,
     169,    -1,   242,    -1,   234,    -1,   215,    -1,   201,    -1,
      -1,   184,   422,   258,   423,   257,   256,    -1,   423,   424,
      -1,   424,    -1,   425,    -1,   426,    -1,     1,   256,    -1,
     121,   259,   154,   256,    -1,    -1,   185,   427,   259,   428,
     256,    -1,   428,   260,   429,    -1,   429,    -1,    93,    -1,
     240,    -1,   243,    -1,   253,    -1,   241,    -1,   235,    -1,
     169,    -1,   242,    -1,   234,    -1,   215,    -1,   201,    -1,
      -1,    29,   431,   432,   258,   433,   257,   256,    -1,    -1,
     436,    -1,   433,   434,    -1,   434,    -1,   435,    -1,   437,
      -1,   438,    -1,   439,    -1,   440,    -1,   442,    -1,   441,
      -1,   443,    -1,   444,    -1,   457,    -1,   458,    -1,   459,
      -1,   455,    -1,   452,    -1,   454,    -1,   453,    -1,   451,
      -1,   460,    -1,   456,    -1,     1,   256,    -1,   121,   259,
     154,   256,    -1,   154,    -1,    84,   259,   154,   256,    -1,
     251,   259,   154,   256,    -1,   177,   259,   154,   256,    -1,
       3,   259,   154,   256,    -1,   153,   259,   132,   256,    -1,
       6,   259,   213,   256,    -1,     6,   259,   214,   256,    -1,
      53,   259,   154,   256,    -1,    -1,    54,   445,   259,   446,
     256,    -1,   446,   260,   447,    -1,   447,    -1,    -1,   131,
     448,   450,    -1,    -1,   449,   450,    -1,    99,    -1,    27,
      -1,    31,    -1,    10,    -1,    12,    -1,   238,    -1,   167,
     259,   154,   256,    -1,    49,   259,   195,   256,    -1,    31,
     259,   195,   256,    -1,    27,   259,   195,   256,    -1,    10,
     259,   195,   256,    -1,   238,   259,   195,   256,    -1,    86,
     259,   154,   256,    -1,   100,   259,   154,   256,    -1,    26,
     259,   154,   256,    -1,    25,   259,   154,   256,    -1,    -1,
      91,   462,   258,   467,   257,   256,    -1,    -1,   185,   464,
     259,   465,   256,    -1,   465,   260,   466,    -1,   466,    -1,
     159,    -1,   467,   468,    -1,   468,    -1,   469,    -1,   470,
      -1,   463,    -1,     1,    -1,   244,   259,   154,   256,    -1,
     156,   259,   154,   256,    -1,    -1,    36,   472,   258,   473,
     257,   256,    -1,   473,   474,    -1,   474,    -1,   475,    -1,
     476,    -1,     1,    -1,    90,   259,   154,   256,    -1,   156,
     259,   154,   256,    -1,    51,   258,   478,   257,   256,    -1,
     478,   479,    -1,   479,    -1,   480,    -1,     1,    -1,    90,
     259,   154,   256,    -1,    -1,    64,   482,   258,   487,   257,
     256,    -1,    -1,   185,   484,   259,   485,   256,    -1,   485,
     260,   486,    -1,   486,    -1,   159,    -1,   487,   488,    -1,
     488,    -1,   489,    -1,   490,    -1,   483,    -1,     1,    -1,
     121,   259,   154,   256,    -1,   156,   259,   154,   256,    -1,
      65,   258,   492,   257,   256,    -1,   492,   493,    -1,   493,
      -1,   501,    -1,   502,    -1,   504,    -1,   505,    -1,   506,
      -1,   507,    -1,   508,    -1,   509,    -1,   510,    -1,   511,
      -1,   500,    -1,   513,    -1,   514,    -1,   515,    -1,   516,
      -1,   532,    -1,   518,    -1,   520,    -1,   522,    -1,   521,
      -1,   525,    -1,   519,    -1,   526,    -1,   527,    -1,   528,
      -1,   529,    -1,   531,    -1,   530,    -1,   546,    -1,   533,
      -1,   537,    -1,   538,    -1,   542,    -1,   523,    -1,   524,
      -1,   552,    -1,   550,    -1,   551,    -1,   534,    -1,   503,
      -1,   535,    -1,   536,    -1,   553,    -1,   541,    -1,   512,
      -1,   554,    -1,   539,    -1,   540,    -1,   496,    -1,   499,
      -1,   494,    -1,   495,    -1,   497,    -1,   498,    -1,   517,
      -1,     1,    -1,    71,   259,   132,   256,    -1,    72,   259,
     132,   256,    -1,    12,   259,   195,   256,    -1,   250,   259,
     195,   256,    -1,   161,   259,   265,   256,    -1,   182,   259,
     195,   256,    -1,    92,   259,   132,   256,    -1,    83,   259,
     195,   256,    -1,    88,   259,   195,   256,    -1,    42,   259,
     195,   256,    -1,    52,   259,   195,   256,    -1,     8,   259,
     195,   256,    -1,   113,   259,   265,   256,    -1,   112,   259,
     132,   256,    -1,   106,   259,   132,   256,    -1,     9,   259,
     265,   256,    -1,   199,   259,   265,   256,    -1,   198,   259,
     265,   256,    -1,    76,   259,   132,   256,    -1,    96,   259,
     195,   256,    -1,    95,   259,   154,   256,    -1,    89,   259,
     195,   256,    -1,   255,   259,   195,   256,    -1,   190,   259,
     195,   256,    -1,   193,   259,   195,   256,    -1,   194,   259,
     195,   256,    -1,   192,   259,   195,   256,    -1,   192,   259,
     196,   256,    -1,   191,   259,   195,   256,    -1,   191,   259,
     196,   256,    -1,   146,   259,   265,   256,    -1,    19,   259,
     265,   256,    -1,   138,   259,   195,   256,    -1,   147,   259,
     265,   256,    -1,   186,   259,   195,   256,    -1,   129,   259,
     195,   256,    -1,   239,   259,   195,   256,    -1,   141,   259,
     195,   256,    -1,   116,   259,   154,   256,    -1,    87,   259,
     265,   256,    -1,    44,   259,   132,   256,    -1,   115,   259,
     132,   256,    -1,   180,   259,   154,   256,    -1,    32,   259,
     154,   256,    -1,    28,   259,   132,   256,    -1,   245,   259,
     195,   256,    -1,    46,   259,   154,   256,    -1,   150,   259,
     195,   256,    -1,    39,   259,   195,   256,    -1,   237,   259,
     265,   256,    -1,    -1,   143,   543,   259,   544,   256,    -1,
     544,   260,   545,    -1,   545,    -1,   202,    -1,   205,    -1,
     207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,    -1,
     227,    -1,   233,    -1,   230,    -1,   210,    -1,   226,    -1,
     228,    -1,   212,    -1,   236,    -1,   203,    -1,   204,    -1,
     215,    -1,    -1,   140,   547,   259,   548,   256,    -1,   548,
     260,   549,    -1,   549,    -1,   202,    -1,   205,    -1,   207,
      -1,   208,    -1,   211,    -1,   229,    -1,   225,    -1,   227,
      -1,   233,    -1,   230,    -1,   210,    -1,   226,    -1,   228,
      -1,   212,    -1,   236,    -1,   203,    -1,   204,    -1,   215,
      -1,   117,   259,   132,   256,    -1,   118,   259,   132,   256,
      -1,    33,   259,   132,   256,    -1,   206,   259,   267,   256,
      -1,    43,   259,   195,   256,    -1,    -1,    67,   556,   258,
     557,   257,   256,    -1,   557,   558,    -1,   558,    -1,   559,
      -1,   560,    -1,   561,    -1,   565,    -1,   566,    -1,   567,
      -1,     1,    -1,    48,   259,   195,   256,    -1,    45,   259,
     265,   256,    -1,    -1,   104,   562,   259,   563,   256,    -1,
     563,   260,   564,    -1,   564,    -1,   197,    -1,    11,    -1,
     244,   259,   154,   256,    -1,   121,   259,   154,   256,    -1,
      -1,     4,   568,   259,   569,   256,    -1,   569,   260,   570,
      -1,   570,    -1,   197,    -1,    11,    -1,    22,   258,   572,
     257,   256,    -1,   572,   573,    -1,   573,    -1,   575,    -1,
     576,    -1,   577,    -1,   578,    -1,   583,    -1,   579,    -1,
     580,    -1,   581,    -1,   582,    -1,   584,    -1,   585,    -1,
     586,    -1,   574,    -1,   587,    -1,   588,    -1,   589,    -1,
     590,    -1,     1,    -1,   164,   259,   195,   256,    -1,    41,
     259,   195,   256,    -1,   246,   259,   195,   256,    -1,   247,
     259,   195,   256,    -1,   248,   259,   195,   256,    -1,    97,
     259,   265,   256,    -1,    98,   259,   265,   256,    -1,   108,
     259,   132,   256,    -1,   155,   259,   195,   256,    -1,   107,
     259,   132,   256,    -1,    35,   259,   132,   256,    -1,    34,
     259,   132,   256,    -1,   127,   259,   195,   256,    -1,   128,
     259,   195,   256,    -1,    13,   259,   195,   256,    -1,   144,
     259,   132,   256,    -1,   145,   259,   265,   256,    -1,   178,
     258,   592,   257,   256,    -1,   592,   593,    -1,   593,    -1,
     594,    -1,   595,    -1,   597,    -1,   599,    -1,   598,    -1,
     596,    -1,   600,    -1,     1,    -1,    55,   259,   195,   256,
      -1,    82,   259,   195,   256,    -1,    79,   259,   154,   256,
      -1,   101,   259,   265,   256,    -1,    77,   259,   195,   256,
      -1,    40,   259,   195,   256,    -1,    81,   259,   195,   256,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   393,   393,   394,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   422,   422,   423,   427,
     431,   435,   439,   443,   449,   449,   450,   451,   452,   453,
     460,   463,   463,   464,   464,   464,   466,   483,   494,   497,
     498,   499,   499,   500,   500,   501,   501,   502,   503,   503,
     504,   504,   505,   507,   541,   601,   615,   630,   639,   653,
     662,   690,   720,   743,   793,   795,   795,   796,   796,   797,
     797,   799,   808,   817,   830,   832,   833,   835,   835,   836,
     837,   837,   838,   838,   839,   839,   840,   840,   841,   842,
     844,   848,   852,   859,   866,   873,   880,   887,   894,   901,
     908,   912,   916,   920,   924,   928,   932,   938,   948,   947,
    1041,  1041,  1042,  1042,  1043,  1043,  1043,  1043,  1044,  1044,
    1045,  1045,  1045,  1046,  1046,  1046,  1047,  1047,  1047,  1048,
    1048,  1048,  1048,  1049,  1049,  1050,  1050,  1052,  1064,  1076,
    1095,  1107,  1118,  1160,  1170,  1169,  1175,  1175,  1176,  1180,
    1184,  1188,  1192,  1196,  1200,  1204,  1208,  1212,  1216,  1220,
    1224,  1228,  1232,  1236,  1240,  1244,  1250,  1261,  1272,  1283,
    1294,  1305,  1316,  1327,  1338,  1349,  1360,  1371,  1382,  1393,
    1405,  1404,  1408,  1408,  1409,  1409,  1410,  1410,  1412,  1419,
    1426,  1433,  1440,  1447,  1454,  1461,  1468,  1475,  1482,  1489,
    1496,  1503,  1510,  1517,  1531,  1530,  1572,  1572,  1574,  1574,
    1575,  1576,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1585,  1586,  1587,  1589,  1598,  1607,  1613,  1619,  1625,
    1631,  1637,  1643,  1649,  1655,  1661,  1667,  1673,  1683,  1682,
    1699,  1698,  1703,  1703,  1704,  1708,  1714,  1714,  1715,  1715,
    1715,  1715,  1715,  1717,  1717,  1719,  1719,  1721,  1735,  1755,
    1764,  1777,  1776,  1845,  1845,  1846,  1846,  1846,  1846,  1847,
    1847,  1848,  1848,  1848,  1849,  1849,  1850,  1850,  1850,  1851,
    1851,  1851,  1853,  1872,  1885,  1896,  1905,  1917,  1916,  1920,
    1920,  1921,  1921,  1922,  1922,  1924,  1932,  1939,  1946,  1953,
    1960,  1967,  1974,  1981,  1988,  1997,  2008,  2019,  2030,  2041,
    2052,  2064,  2083,  2093,  2102,  2118,  2117,  2133,  2133,  2134,
    2134,  2134,  2134,  2136,  2145,  2160,  2174,  2173,  2189,  2189,
    2190,  2190,  2190,  2190,  2192,  2201,  2210,  2209,  2215,  2215,
    2216,  2220,  2224,  2228,  2232,  2236,  2240,  2244,  2248,  2252,
    2256,  2266,  2265,  2282,  2282,  2283,  2283,  2283,  2285,  2292,
    2291,  2297,  2297,  2298,  2302,  2306,  2310,  2314,  2318,  2322,
    2326,  2330,  2334,  2338,  2348,  2347,  2497,  2497,  2498,  2498,
    2499,  2499,  2499,  2500,  2500,  2501,  2501,  2502,  2502,  2502,
    2503,  2503,  2503,  2504,  2504,  2504,  2505,  2505,  2506,  2506,
    2508,  2520,  2532,  2541,  2567,  2585,  2603,  2609,  2613,  2621,
    2631,  2630,  2634,  2634,  2635,  2635,  2636,  2636,  2638,  2645,
    2656,  2663,  2670,  2677,  2687,  2728,  2739,  2750,  2765,  2776,
    2787,  2800,  2813,  2822,  2858,  2857,  2919,  2918,  2922,  2922,
    2923,  2929,  2929,  2930,  2930,  2930,  2930,  2932,  2948,  2958,
    2957,  2979,  2979,  2980,  2980,  2980,  2982,  2991,  3003,  3005,
    3005,  3006,  3006,  3008,  3030,  3029,  3071,  3070,  3074,  3074,
    3075,  3081,  3081,  3082,  3082,  3082,  3082,  3084,  3090,  3099,
    3102,  3102,  3103,  3103,  3104,  3104,  3105,  3105,  3106,  3106,
    3107,  3107,  3108,  3108,  3109,  3109,  3110,  3110,  3111,  3111,
    3112,  3112,  3113,  3113,  3114,  3114,  3115,  3115,  3116,  3116,
    3117,  3117,  3118,  3118,  3119,  3119,  3120,  3120,  3121,  3121,
    3122,  3122,  3123,  3124,  3124,  3125,  3125,  3126,  3126,  3127,
    3127,  3128,  3128,  3129,  3129,  3130,  3130,  3131,  3135,  3140,
    3145,  3150,  3155,  3160,  3165,  3170,  3175,  3180,  3185,  3190,
    3195,  3200,  3205,  3210,  3215,  3220,  3226,  3237,  3242,  3251,
    3256,  3261,  3266,  3271,  3276,  3279,  3284,  3287,  3292,  3297,
    3302,  3307,  3312,  3317,  3322,  3327,  3332,  3343,  3348,  3353,
    3358,  3367,  3399,  3417,  3422,  3431,  3436,  3441,  3447,  3446,
    3451,  3451,  3452,  3455,  3458,  3461,  3464,  3467,  3470,  3473,
    3476,  3479,  3482,  3485,  3488,  3491,  3494,  3497,  3500,  3503,
    3509,  3508,  3513,  3513,  3514,  3517,  3520,  3523,  3526,  3529,
    3532,  3535,  3538,  3541,  3544,  3547,  3550,  3553,  3556,  3559,
    3562,  3565,  3570,  3575,  3580,  3585,  3590,  3599,  3598,  3622,
    3622,  3623,  3624,  3625,  3626,  3627,  3628,  3629,  3631,  3637,
    3644,  3643,  3648,  3648,  3649,  3653,  3659,  3678,  3688,  3687,
    3737,  3737,  3738,  3742,  3751,  3754,  3754,  3755,  3755,  3756,
    3756,  3757,  3757,  3758,  3758,  3759,  3759,  3760,  3761,  3761,
    3762,  3762,  3763,  3763,  3764,  3766,  3771,  3776,  3781,  3786,
    3791,  3796,  3801,  3806,  3811,  3816,  3821,  3826,  3831,  3836,
    3841,  3846,  3854,  3857,  3857,  3858,  3858,  3859,  3860,  3861,
    3861,  3862,  3863,  3865,  3871,  3877,  3886,  3900,  3906,  3912
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", "KBYTES",
  "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CAN_IDLE",
  "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIPHER_PREFERENCE",
  "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ",
  "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_HIDDEN",
  "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOT_IN_IP6_ADDR",
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME",
  "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IDLETIME",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LAZYLINK",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NOT", "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID",
  "T_CALLERID", "T_CCONN", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR",
  "T_L_INFO", "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "@1",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "@2",
  "oper_umodes_items", "oper_umodes_item", "oper_global_kill",
  "oper_remote", "oper_remoteban", "oper_kline", "oper_xline",
  "oper_unkline", "oper_gline", "oper_nick_changes", "oper_die",
  "oper_rehash", "oper_admin", "oper_hidden_admin", "oper_hidden_oper",
  "oper_operwall", "oper_flags", "@3", "oper_flags_items",
  "oper_flags_item", "@4", "@5", "oper_flags_item_atom", "class_entry",
  "@6", "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "@7", "listen_flags", "@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@11", "auth_flags_items",
  "auth_flags_item", "@12", "@13", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "@14", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "@15", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "@16", "shared_types",
  "shared_type_item", "cluster_entry", "@17", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "@18", "cluster_types",
  "cluster_type_item", "connect_entry", "@19", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "@20", "connect_flags_items",
  "connect_flags_item", "@21", "@22", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_topicburst",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "@23", "kill_type", "@24",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "@25", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "@26", "gecos_flags", "@27",
  "gecos_flags_items", "gecos_flags_item", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_burst_away", "general_use_whois_actually",
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
  "general_message_locale", "general_idletime", "general_dots_in_ident",
  "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@28", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@29",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@30",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@31", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@32", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
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
static const unsigned short int yytoknum[] =
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
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,    59,   125,   123,    61,
      44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   261,   262,   262,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   264,   264,   265,   265,
     265,   265,   265,   265,   266,   266,   267,   267,   267,   267,
     268,   269,   269,   270,   270,   270,   271,   272,   273,   274,
     274,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   288,   289,   289,   289,
     289,   290,   291,   292,   293,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   306,   306,   306,   306,   306,   306,   307,   309,   308,
     310,   310,   311,   311,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   313,   314,   315,
     316,   317,   318,   319,   321,   320,   322,   322,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     339,   338,   340,   340,   342,   341,   343,   341,   344,   344,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   346,   345,   347,   347,   348,   348,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   365,   364,
     367,   366,   368,   368,   369,   369,   370,   370,   371,   371,
     371,   371,   371,   373,   372,   374,   374,   375,   375,   376,
     377,   379,   378,   380,   380,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   382,   383,   384,   385,   386,   388,   387,   389,
     389,   391,   390,   392,   390,   393,   393,   393,   393,   393,
     393,   393,   393,   393,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   405,   404,   406,   406,   407,
     407,   407,   407,   408,   409,   410,   412,   411,   413,   413,
     414,   414,   414,   414,   415,   416,   418,   417,   419,   419,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   422,   421,   423,   423,   424,   424,   424,   425,   427,
     426,   428,   428,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   431,   430,   432,   432,   433,   433,
     434,   434,   434,   434,   434,   434,   434,   434,   434,   434,
     434,   434,   434,   434,   434,   434,   434,   434,   434,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   442,   443,
     445,   444,   446,   446,   448,   447,   449,   447,   450,   450,
     450,   450,   450,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   462,   461,   464,   463,   465,   465,
     466,   467,   467,   468,   468,   468,   468,   469,   470,   472,
     471,   473,   473,   474,   474,   474,   475,   476,   477,   478,
     478,   479,   479,   480,   482,   481,   484,   483,   485,   485,
     486,   487,   487,   488,   488,   488,   488,   489,   490,   491,
     492,   492,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   520,   521,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   543,   542,
     544,   544,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     547,   546,   548,   548,   549,   549,   549,   549,   549,   549,
     549,   549,   549,   549,   549,   549,   549,   549,   549,   549,
     549,   549,   550,   551,   552,   553,   554,   556,   555,   557,
     557,   558,   558,   558,   558,   558,   558,   558,   559,   560,
     562,   561,   563,   563,   564,   564,   565,   566,   568,   567,
     569,   569,   570,   570,   571,   572,   572,   573,   573,   573,
     573,   573,   573,   573,   573,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   592,   593,   593,   593,   593,   593,
     593,   593,   593,   594,   595,   596,   597,   598,   599,   600
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     0,     1,     2,     3,     3,     3,
       5,     2,     1,     1,     1,     2,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     7,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     0,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   384,   459,     0,
     474,     0,   647,   271,   444,   248,     0,     0,   118,   325,
       0,     0,   336,   361,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     386,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   694,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   676,   689,   677,   678,   679,
     680,   682,   683,   684,   685,   681,   686,   687,   688,   690,
     691,   692,   693,   235,     0,   217,   411,     0,   387,     0,
     472,     0,     0,   470,   471,     0,   547,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   620,
       0,   598,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   491,   542,   543,   540,   544,   545,   541,
     502,   492,   493,   531,   494,   495,   496,   497,   498,   499,
     500,   501,   536,   503,   504,   505,   506,   546,   508,   513,
     509,   511,   510,   525,   526,   512,   514,   515,   516,   517,
     519,   518,   507,   521,   530,   532,   533,   522,   523,   538,
     539,   535,   524,   520,   528,   529,   527,   534,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      91,    98,    92,    96,    93,    94,    97,    95,    89,    90,
       0,     0,     0,     0,    42,    43,    44,   148,     0,   121,
       0,   722,     0,     0,     0,     0,     0,     0,     0,     0,
     714,   715,   716,   720,   717,   719,   718,   721,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    61,    58,    51,    60,    54,    55,    56,    52,
      59,    57,    53,     0,     0,    80,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   675,
       0,     0,   465,     0,     0,     0,   462,   463,   464,     0,
       0,   469,   486,     0,     0,   476,   485,     0,   482,   483,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   490,   657,   668,
       0,     0,   660,     0,     0,     0,   650,   651,   652,   653,
     654,   655,   656,     0,     0,     0,     0,     0,   297,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   275,   276,   285,   277,   290,   278,   279,   280,
     281,   288,   282,   283,   284,   286,   287,   289,   456,     0,
     446,     0,   455,     0,   452,   453,   454,     0,   250,     0,
       0,     0,   259,     0,   257,   258,   260,   261,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    45,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   328,   329,   330,   331,     0,     0,
       0,     0,     0,     0,     0,     0,   713,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   346,     0,     0,   339,   340,   341,   342,
       0,     0,   369,     0,   364,   365,   366,     0,     0,     0,
      74,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   674,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,   220,   223,   224,   226,
     227,   228,   229,   230,   231,   232,   221,   222,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,   391,   392,   393,   394,   396,   395,   397,   398,
     406,   403,   405,   404,   402,   408,   399,   400,   401,   407,
       0,     0,     0,   461,     0,   468,     0,     0,     0,     0,
     481,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,   489,
       0,     0,     0,     0,     0,     0,     0,   649,   291,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   273,     0,     0,     0,
       0,   451,   262,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,     0,     0,
      40,     0,     0,     0,     0,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,     0,     0,     0,     0,   123,   124,   125,   126,   143,
     144,   130,   129,   131,   132,   138,   133,   134,   135,   136,
     137,   139,   140,   141,   127,   128,   142,   145,   332,     0,
       0,     0,     0,   327,     0,     0,     0,     0,     0,     0,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,   343,     0,     0,     0,     0,   338,
     367,     0,     0,     0,   363,    83,    82,    81,   709,   706,
     705,   696,    26,    26,    26,    26,    26,    28,    27,   700,
     701,   704,   702,   707,   708,   710,   711,   703,   695,   697,
     698,   699,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   218,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
       0,     0,   460,   473,     0,     0,     0,   475,   559,   563,
     550,   579,   592,   591,   644,   596,   557,   646,   588,   594,
     558,   548,   549,   566,   555,   587,   556,   569,   554,   568,
     567,   562,   561,   560,   589,   586,   642,   643,   583,   580,
     624,   639,   640,   625,   626,   627,   634,   628,   637,   641,
     630,   635,   631,   636,   629,   633,   632,   638,     0,   623,
     585,   602,   617,   618,   603,   604,   605,   612,   606,   615,
     619,   608,   613,   609,   614,   607,   611,   610,   616,     0,
     601,   578,   581,   595,   552,   590,   553,   582,   571,   576,
     577,   574,   575,   572,   573,   565,   564,    34,    34,    34,
      36,    35,   645,   597,   584,   593,   551,   570,     0,     0,
       0,     0,     0,     0,   648,     0,     0,     0,     0,   303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,     0,   445,     0,     0,     0,   267,
     263,   266,   249,   103,   109,   107,   106,   108,   104,   105,
     102,   110,   116,   111,   115,   113,   114,   112,   101,   100,
     117,    46,    47,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,     0,     0,
       0,   326,   728,   723,   727,   725,   729,   724,   726,    67,
      73,    65,    69,    68,    64,    63,    66,    72,    70,    71,
       0,     0,     0,   337,     0,     0,   362,    29,    30,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   426,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   385,   466,   467,   487,
     488,   480,     0,   479,   621,     0,   599,     0,    37,    38,
      39,   673,   672,     0,   671,   659,   658,   665,   664,     0,
     663,   667,   666,   318,   295,   296,   317,   301,     0,   300,
       0,   320,   316,   315,   324,   319,   293,   323,   322,   321,
     294,   292,   458,   450,     0,   449,   457,   255,   254,     0,
     253,   270,   269,     0,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   334,
     335,   333,   344,   350,   356,   360,   359,   358,   355,   351,
     354,   357,   352,   353,     0,   349,   345,   368,   373,   379,
     383,   382,   381,   378,   374,   377,   380,   375,   376,     0,
     372,   245,   246,   239,   241,   243,   242,   240,   234,   247,
     238,   236,   237,   244,   415,   417,   418,   438,   443,   442,
     437,   436,   435,   419,   424,     0,   423,     0,   412,   440,
     441,   410,   416,   434,   414,   439,   413,   477,     0,   622,
     600,   669,     0,   661,     0,     0,   298,   303,   309,   310,
     306,   312,   308,   307,   314,   311,   313,   305,   304,   447,
       0,   251,     0,   268,   265,   264,   186,   153,   184,   151,
     194,     0,   193,     0,   182,   176,   187,   188,   179,   147,
     183,   150,   185,   177,   178,   152,   189,   158,   173,   174,
     159,   160,   161,   168,   162,   171,   175,   164,   169,   165,
     170,   163,   167,   166,   172,     0,   157,   181,   149,   180,
     347,     0,   370,     0,     0,   421,   426,   431,   432,   429,
     430,   428,   433,   427,   478,   670,   662,   302,   299,   448,
     252,     0,   191,   196,   206,   204,   213,   203,   198,   207,
     211,   200,   208,   210,   205,   199,   212,   209,   201,   202,
     197,   155,     0,   348,   371,   425,   422,   195,   192,   156
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    24,   887,   888,  1040,  1041,    25,   273,   274,
     275,   276,    26,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    27,    71,    72,    73,
      74,    75,    28,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    29,    61,   278,
     814,   815,   816,   279,   817,   818,   819,   820,   821,   822,
    1122,  1415,  1416,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   832,   833,   834,   835,   836,   837,  1108,  1381,
    1382,  1441,  1383,  1460,    30,    49,   114,   604,   605,   606,
     115,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,    31,    58,   492,   763,  1249,  1250,   493,
     494,   495,  1255,  1080,  1081,   496,   497,    32,    56,   460,
     461,   462,   463,   464,   465,   466,   467,   743,  1228,  1229,
    1355,  1230,  1368,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,    33,    62,   523,   524,   525,   526,   527,
      34,    65,   555,   556,   557,   558,   559,   866,  1294,  1295,
      35,    66,   563,   564,   565,   566,   872,  1309,  1310,    36,
      50,   117,   639,   640,   641,   118,   642,   643,   644,   645,
     646,   647,   648,   649,   928,  1335,  1336,  1424,  1337,  1433,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
      37,    57,   482,   758,  1244,  1245,   483,   484,   485,   486,
      38,    51,   355,   356,   357,   358,    39,   122,   123,   124,
      40,    53,   366,   668,  1202,  1203,   367,   368,   369,   370,
      41,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   405,  1019,  1020,   233,   403,   998,   999,   234,
     235,   236,   237,   238,    42,    55,   435,   436,   437,   438,
     439,   733,  1219,  1220,   440,   441,   442,   730,  1213,  1214,
      43,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      44,   289,   290,   291,   292,   293,   294,   295,   296,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -796
static const short int yypact[] =
{
    -796,   799,  -796,  -206,  -253,  -243,  -796,  -796,  -796,  -227,
    -796,  -218,  -796,  -796,  -796,  -796,  -195,  -185,  -796,  -796,
    -183,  -168,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,   124,   741,  -109,
     -76,  -161,    29,  -151,   493,  -142,  -140,  -123,  -111,   754,
       2,     1,   -98,   427,   309,   -86,   -65,   -59,   -56,   -54,
     -47,    17,  -796,  -796,  -796,  -796,  -796,   -40,   -29,   -21,
     -20,   -13,   -12,    -1,    20,    24,    36,    38,    43,    47,
      49,    53,    63,    68,   222,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,    -6,  -796,  -796,    22,  -796,    11,
    -796,    72,    10,  -796,  -796,     9,  -796,    77,    79,    81,
      82,    84,    86,    88,    89,    93,    94,    96,    98,   101,
     106,   109,   110,   114,   115,   116,   120,   125,   126,   129,
     133,   139,   140,   142,   144,   146,   148,   150,   151,  -796,
     158,  -796,   160,   161,   163,   167,   168,   170,   172,   179,
     180,   187,   189,   192,   193,   198,   199,   200,   201,   212,
     213,   214,    16,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   314,
     777,   143,   350,     4,   217,   224,   230,   232,   233,   234,
     236,   237,   239,   240,   241,   248,   123,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
      35,   251,   261,    21,  -796,  -796,  -796,  -796,    26,  -796,
      95,  -796,   263,   264,   268,   279,   281,   283,   284,    12,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,    40,   285,
     287,   288,   289,   291,   292,   293,   297,   298,   303,   304,
     190,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,   119,    15,  -796,   134,   229,   254,   122,
    -796,    97,   270,   317,   159,   349,   349,   434,   435,   373,
     378,   443,   349,   382,   388,   389,   392,   395,   335,  -796,
     420,   641,  -796,   333,   334,    33,  -796,  -796,  -796,   440,
     339,  -796,  -796,   341,   342,  -796,  -796,    32,  -796,  -796,
    -796,   403,   349,   408,   349,   472,   453,   480,   418,   421,
     422,   483,   464,   424,   488,   491,   492,   430,   349,   432,
     442,   497,   476,   450,   503,   506,   349,   514,   494,   517,
     518,   457,   458,   396,   461,   398,   349,   349,   463,   349,
     505,   465,   466,   467,  -139,   -69,   468,   469,   349,   349,
     538,   349,   482,   485,   486,   487,   415,  -796,  -796,  -796,
     419,   429,  -796,   438,   439,    37,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,   433,   444,   445,   447,   454,  -796,   455,
     459,   460,   462,   470,   474,   475,   477,   478,   481,   490,
     267,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   498,
    -796,   499,  -796,    80,  -796,  -796,  -796,   446,  -796,   500,
     501,   502,  -796,    25,  -796,  -796,  -796,  -796,  -796,   547,
     555,   558,   562,   563,   570,   572,   574,   296,   577,   581,
     544,   489,  -796,  -796,   590,   592,   495,  -796,   548,   507,
     509,   512,   513,    76,  -796,  -796,  -796,  -796,   552,   561,
     569,   596,   571,   578,   349,   523,  -796,  -796,   611,   586,
     629,   630,   631,   632,   634,   639,   663,   648,   651,   550,
    -796,   551,   560,  -796,   564,   149,  -796,  -796,  -796,  -796,
     553,   575,  -796,    28,  -796,  -796,  -796,   566,   573,   580,
    -796,   584,   585,   588,   591,   313,   595,   598,   599,   600,
     601,   602,   604,   605,   606,   609,   620,   621,   622,  -796,
     625,   583,   587,   608,   623,   624,   628,   635,   636,   638,
     643,   645,   652,   653,   302,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   642,
     654,   659,   662,   664,   665,   667,   669,   670,   671,  -796,
     672,   673,   678,   679,   682,   683,   684,   685,   690,   223,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
     666,   676,   644,  -796,   677,  -796,   730,   734,   691,   695,
    -796,   696,   697,   698,   699,   700,   701,   703,   704,   706,
     707,   708,   711,   713,   715,   716,   717,   718,   719,   720,
     723,   724,   725,   728,   729,   739,   742,   746,   749,   750,
     751,   752,   753,   789,   755,   824,   756,   757,   764,   767,
     768,   774,   781,   782,   784,   785,   786,   787,   788,   790,
     791,   792,     5,   800,   802,   803,   809,   812,   816,  -796,
     727,   349,   766,   731,   856,   879,   817,  -796,  -796,   850,
     901,   880,   881,   818,   883,   884,   885,   886,   887,   929,
     778,   936,   937,   898,   940,   840,  -796,   943,   839,   945,
     844,  -796,  -796,   842,   948,   949,   972,   849,  -796,   851,
     852,   853,   854,   855,   857,   858,   860,   861,   862,   863,
     864,   865,   866,   867,   868,   869,   870,  -796,   871,   872,
    -796,   873,   847,   874,   875,   876,  -796,   877,   878,   882,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
    -796,   899,   900,   902,   138,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   958,
     961,   976,   904,  -796,   906,   907,   908,   909,   910,   911,
     912,  -796,   913,   914,   915,   916,   917,   918,   919,   920,
     921,   922,   923,  -796,  -796,   977,   924,   978,   925,  -796,
    -796,   984,   926,   928,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,   349,   349,   349,   349,   349,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  1007,  1008,   349,  1010,  1011,  1012,  1013,
     992,  1025,  1048,   349,   349,   538,   930,  -796,  -796,  1028,
     -39,   993,  1033,  1035,   995,   996,   997,  1039,   935,  1041,
    1042,  1043,  1044,  1067,  1046,  1047,  1009,  1049,   946,  -796,
     950,   951,  -796,  -796,   952,   953,   763,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -224,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -214,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,   538,   538,   538,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,    -7,   954,
     955,    -2,   956,   957,  -796,   959,   960,   962,   963,  1074,
     964,   965,   966,   967,   968,   969,   970,   971,   973,   974,
     975,  -796,   979,  1055,   980,  -796,   -63,   981,   982,   633,
     983,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  1022,  1078,  1038,  1045,   985,  1050,
    1051,  1052,  1053,  1054,  1080,  1056,  1085,  1057,  1058,  1059,
    1087,  1060,   991,  1061,  1088,  1062,  1002,  -796,  1003,  1004,
    1005,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    1006,   674,  1014,  -796,  1015,   705,  -796,  -796,  -796,  -796,
    -796,  -796,  1016,  1017,  1018,  1019,  1020,  1021,  1023,  1024,
    1026,  1027,  1029,  1030,  1031,  -796,  1032,  1034,  1036,  1037,
    1040,  1063,  1064,  1065,  1066,  1068,  1097,  1069,  1070,  1071,
    1072,  1073,  1075,  1076,  1077,  1079,  -796,  -796,  -796,  -796,
    -796,  -796,  -213,  -796,  -796,   789,  -796,   824,  -796,  -796,
    -796,  -796,  -796,  -191,  -796,  -796,  -796,  -796,  -796,  -190,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -180,  -796,
     702,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -154,  -796,  -796,  -796,  -796,  -146,
    -796,  -796,  -796,  1131,   972,  1081,  1082,  1083,  1084,  1086,
    1133,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1098,
    1099,  1100,  1101,  1102,   859,  1103,  1104,  1105,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -114,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -108,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,   -87,  -796,    -4,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   763,  -796,
    -796,  -796,    -7,  -796,    -2,   702,  -796,  1074,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    1055,  -796,   -63,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,   -35,  -796,   627,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,   -19,  -796,  -796,  -796,  -796,
    -796,   674,  -796,   705,    -4,  -796,  1097,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,   627,  -796,  1133,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,   859,  -796,  -796,  -796,  -796,  -796,  -796,  -796
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -796,  -796,  -796,  -420,  -335,  -795,  -418,  -796,  -796,   994,
    -796,  -796,  -796,  -796,   527,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  1194,  -796,
    -796,  -796,  -796,  -796,  1106,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,   452,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -194,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -174,  -796,  -796,  -163,  -796,  -796,  -796,  -796,   680,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   -91,  -796,
     796,  -796,  -796,  -796,    41,  -796,  -796,  -796,  -796,  -796,
     831,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,   -60,
    -796,  -796,   -61,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,   775,  -796,  -796,  -796,
    -796,  -796,  -796,   744,  -796,  -796,  -796,  -796,  -796,  -121,
    -796,  -796,  -796,   738,  -796,  -796,  -796,  -796,  -120,  -796,
    -796,  -796,  -796,   668,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -124,  -796,  -796,  -119,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,   -66,  -796,   823,  -796,  -796,
    -796,  -796,  -796,   986,  -796,  -796,  -796,  -796,  1186,  -796,
    -796,  -796,  -796,  -796,  -796,   -38,  -796,   942,  -796,  -796,
    -796,  -796,  1129,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,   105,  -796,  -796,  -796,   108,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,   931,  -796,  -796,
    -796,  -796,  -796,   -37,  -796,  -796,  -796,  -796,  -796,   -36,
    -796,  -796,  1220,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,  -796,
    -796,  -796,  1107,  -796,  -796,  -796,  -796,  -796,  -796,  -796
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     576,   577,   723,   270,  1211,    47,  1427,   583,  1428,  1217,
     362,   120,   352,   281,  1247,    48,   560,   126,    67,  1037,
    1038,  1039,   270,  1429,   127,   128,   487,  1430,   129,   560,
     120,    52,  1204,   362,   352,   130,  1205,   672,   428,   674,
      54,   429,  1206,  1347,   131,   113,  1207,  1348,   132,   133,
      45,    46,   282,   688,    68,   134,   714,   715,   135,   136,
     137,   696,   138,    59,    69,  1351,  1353,   283,   139,  1352,
    1354,   706,   707,    60,   709,    63,  1356,   519,   116,   488,
    1357,   478,   430,   720,   721,   431,   724,   140,   141,   284,
      64,   285,   142,   286,   287,  1431,   519,   119,   520,   143,
     121,   353,  1369,   144,   145,   146,  1370,   125,   147,   489,
    1371,   148,   149,   288,  1372,   490,   239,   520,   240,   121,
     551,   271,   150,   353,   243,    67,   716,   717,   151,   152,
     363,   153,   154,   155,   156,   241,   561,   722,    70,   791,
     271,   432,  1420,   792,   478,   157,  1421,   242,  1422,   561,
     551,   272,  1423,   363,   158,   277,   159,   160,   433,   161,
     280,    68,   162,   163,   793,   364,   164,   354,  1248,  1425,
     272,    69,   323,  1426,  1177,  1178,   794,   165,   491,   244,
     245,   246,   247,   248,   249,   250,   251,   795,   364,   354,
    1212,   298,   796,   324,   365,  1218,   166,   325,   167,   850,
     562,   521,   168,   326,   797,   327,   169,   170,   171,   172,
     173,   798,   328,   562,   174,   175,   799,   365,   800,   331,
     521,  1442,   176,    76,   619,  1443,   620,   299,   252,   621,
     332,   801,   522,   622,  1432,    77,   479,  1461,   333,   334,
     552,  1462,  1208,  1209,  1210,    70,   335,   336,   623,   624,
     625,   522,   350,   177,   626,   178,    78,    79,   337,   802,
     498,   179,   253,    80,   803,   480,   180,   360,   443,   535,
     552,   181,   627,   426,   329,   300,   628,   629,   516,   338,
     351,   434,   767,   339,   518,   873,   804,   444,   567,   669,
     662,   513,   571,   445,   736,   340,   537,   341,   805,   479,
     806,   807,   342,   590,   553,   808,   343,   630,   344,   631,
     298,   301,   345,   302,   303,   428,   446,   447,   429,    81,
      82,   448,   346,   632,   481,   591,   592,   347,   480,    83,
      84,   359,   593,   842,   553,   449,   371,   760,   372,   254,
     373,   374,   450,   375,   633,   376,   299,   377,   378,    85,
      86,   487,   379,   380,   574,   381,   304,   382,   305,   430,
     383,   451,   431,   554,   809,   384,    87,    88,   385,   386,
     810,   306,   255,   387,   388,   389,   634,    89,   570,   390,
     511,   811,   812,   568,   391,   392,    90,   481,   393,   452,
     635,   813,   394,   554,   300,  1126,  1049,   453,   395,   396,
     636,   397,   572,   398,   488,   399,   868,   400,   569,   401,
     402,   594,   595,   596,   307,   454,   597,   404,   432,   406,
     407,   590,   408,   598,   455,   456,   409,   410,   281,   411,
     301,   412,   302,   303,   489,   433,   599,   600,   413,   414,
     490,   308,   309,   591,   592,   575,   415,   549,   416,   573,
     593,   417,   418,   601,   602,   457,   458,   419,   420,   421,
     422,   637,  1157,  1158,  1159,  1160,  1161,   282,    91,    92,
      93,   423,   424,   425,   638,   304,   499,   305,   603,   348,
     938,   575,   283,   500,   882,   883,   884,   885,   886,   501,
     306,   502,   503,   504,   126,   505,   506,  1174,   507,   508,
     509,   127,   128,   491,   284,   129,   285,   510,   286,   287,
     514,   459,   130,   777,   778,   779,   780,   781,   782,   783,
     515,   131,   528,   529,   755,   132,   133,   530,   288,   594,
     595,   596,   134,   307,   597,   135,   136,   137,   531,   138,
     532,   598,   533,   534,   538,   139,   539,   540,   541,   791,
     542,   543,   544,   792,   599,   600,   545,   546,   434,   916,
     308,   309,   547,   548,   140,   141,   578,   579,   580,   142,
    1164,   601,   602,   581,   793,   582,   143,   584,  1172,  1173,
     144,   145,   146,   585,   586,   147,   794,   587,   148,   149,
     588,   589,   660,   661,   664,   665,   603,   795,   671,   150,
     666,   667,   796,   673,   675,   151,   152,   676,   153,   154,
     155,   156,   677,   678,   797,   681,   679,   680,   682,   683,
     684,   798,   157,   685,   686,   687,   799,   689,   800,   691,
     692,   158,  1444,   159,   160,   694,   161,   690,   695,   162,
     163,   801,   619,   164,   620,   693,   697,   621,   698,   699,
     700,   622,   701,   702,   165,   703,   704,   705,   708,   710,
     711,   712,   713,   718,   719,  1445,   623,   624,   625,   802,
     722,   729,   626,   166,   803,   167,  1446,   725,   731,   168,
     726,   727,   728,   169,   170,   171,   172,   173,   732,   738,
     627,   174,   175,  1447,   628,   629,   804,   734,   735,   176,
    1448,   769,   762,   739,   740,  1449,   741,  1450,   805,   770,
     806,   807,   771,   742,   744,   808,   772,   773,   745,   746,
    1451,   747,  1358,  1359,   774,   630,   775,   631,   776,   748,
     177,   784,   178,   749,   750,   785,   751,   752,   179,   786,
     753,   632,    76,   180,   788,   787,   789,   844,   181,   754,
     847,   790,  1360,  1452,    77,   243,   845,   757,   759,   764,
     765,   766,   633,   838,   846,   852,   848,  1283,   839,  1453,
    1361,   840,   841,   849,   809,    78,    79,  1362,   443,   851,
     810,   853,    80,   854,   855,   856,   857,  1454,   858,  1455,
    1456,   811,   812,   859,   634,   860,  1363,   444,  1298,     2,
       3,   813,   861,   445,     4,   862,   863,   864,   635,   870,
     244,   245,   246,   247,   248,   249,   250,   251,   636,   865,
     940,     5,   875,   867,  1364,     6,   446,   447,     7,   876,
     941,   448,  1365,  1253,   871,     8,   877,   550,    81,    82,
     878,   879,   903,  1284,   880,   449,   904,   881,    83,    84,
       9,   889,   450,  1457,   890,   891,   892,   893,   894,   252,
     895,   896,   897,    10,    11,   898,    12,   905,    85,    86,
    1458,   451,  1366,    13,  1299,  1285,   899,   900,   901,   637,
    1459,   902,   906,   907,   944,    87,    88,   908,   945,  1286,
      14,  1367,   638,   253,   909,   910,    89,   911,   918,   452,
     942,    15,   912,    16,   913,    90,  1300,   453,  1287,  1288,
    1066,   914,   915,   919,  1289,  1290,  1291,  1292,   920,    17,
    1301,   921,  1201,   922,   923,   454,   924,  1293,   925,   926,
     927,   929,   930,   943,   455,   456,    18,   931,   932,  1302,
    1303,   933,   934,   935,   936,  1304,  1305,  1306,  1307,   937,
     946,   947,   948,   949,   950,   951,   952,   953,  1308,   954,
     955,  1050,   956,   957,   958,   457,   458,   959,    19,   960,
     254,   961,   962,   963,   964,   965,   966,    20,    21,   967,
     968,   969,    22,    23,   970,   971,  1048,    91,    92,    93,
    1051,   980,   981,   982,   983,   972,   984,   985,   973,   986,
     987,   988,   974,   255,   989,   975,   976,   977,   978,   979,
    1052,  1000,  1021,  1022,   990,   991,   992,   993,   994,   995,
    1023,   459,   996,  1024,  1025,   997,  1001,  1002,  1003,  1004,
    1026,  1005,  1006,  1053,  1007,  1008,  1009,  1027,  1028,  1010,
    1029,  1030,  1031,  1032,  1033,  1055,  1034,  1035,  1036,  1011,
    1012,  1013,  1014,  1015,  1016,  1056,  1042,  1017,  1043,  1044,
    1018,  1397,  1398,  1399,  1400,  1045,  1401,  1402,  1046,  1403,
    1404,  1405,  1047,  1054,  1406,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1065,  1407,  1408,  1409,  1410,  1411,  1412,
    1067,  1068,  1413,  1069,  1070,  1414,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1082,  1104,  1083,  1084,  1085,
    1086,  1087,  1128,  1088,  1089,  1129,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1130,  1150,  1152,  1105,  1106,  1107,  1109,  1110,  1154,  1162,
    1163,  1111,  1165,  1166,  1167,  1168,  1169,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1170,  1123,  1124,
    1131,  1125,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,
    1171,  1153,  1176,  1151,  1156,  1155,  1175,  1180,  1179,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1196,  1195,  1194,  1227,  1197,  1198,  1199,  1200,
    1215,  1216,  1221,  1222,  1243,  1223,  1224,  1256,  1225,  1226,
    1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1334,  1239,
    1240,  1241,  1257,  1258,  1266,  1242,  1246,  1251,  1252,  1268,
    1259,  1272,  1276,  1254,  1260,  1261,  1262,  1263,  1264,  1265,
    1274,  1267,  1269,  1270,  1271,  1273,  1275,  1277,  1278,  1279,
    1280,  1281,  1282,  1373,  1380,   330,  1127,   517,  1469,  1468,
    1296,  1297,  1311,  1312,  1313,  1314,  1315,  1316,  1467,  1317,
    1318,  1440,  1319,  1320,   917,  1321,  1322,  1323,  1324,   768,
    1325,   756,  1326,  1327,  1437,  1374,  1328,  1438,   843,   869,
    1463,   874,  1466,  1464,  1439,  1465,   761,   939,   361,   670,
    1434,   427,  1350,  1349,   349,     0,  1435,  1436,     0,  1329,
    1330,  1331,  1332,     0,  1333,  1338,  1339,  1340,  1341,  1342,
       0,  1343,  1344,  1345,     0,  1346,     0,  1375,  1376,  1377,
    1378,   663,  1379,     0,     0,  1384,  1385,  1386,  1387,  1388,
    1389,  1390,  1391,     0,  1392,  1393,  1394,  1395,  1396,  1417,
    1418,  1419,   512,     0,     0,     0,   737,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   536
};

static const short int yycheck[] =
{
     335,   336,   420,     1,    11,   258,    10,   342,    12,    11,
       1,     1,     1,     1,    77,   258,     1,     1,     1,    14,
      15,    16,     1,    27,     8,     9,     1,    31,    12,     1,
       1,   258,   256,     1,     1,    19,   260,   372,     1,   374,
     258,     4,   256,   256,    28,   154,   260,   260,    32,    33,
     256,   257,    40,   388,    37,    39,   195,   196,    42,    43,
      44,   396,    46,   258,    47,   256,   256,    55,    52,   260,
     260,   406,   407,   258,   409,   258,   256,     1,   154,    54,
     260,     1,    45,   418,   419,    48,   421,    71,    72,    77,
     258,    79,    76,    81,    82,    99,     1,   258,    22,    83,
      90,    90,   256,    87,    88,    89,   260,   258,    92,    84,
     256,    95,    96,   101,   260,    90,   258,    22,   258,    90,
       1,   119,   106,    90,     1,     1,   195,   196,   112,   113,
     121,   115,   116,   117,   118,   258,   121,   132,   121,     1,
     119,   104,   256,     5,     1,   129,   260,   258,   256,   121,
       1,   149,   260,   121,   138,   154,   140,   141,   121,   143,
     258,    37,   146,   147,    26,   156,   150,   156,   231,   256,
     149,    47,   258,   260,   213,   214,    38,   161,   153,    56,
      57,    58,    59,    60,    61,    62,    63,    49,   156,   156,
     197,     1,    54,   258,   185,   197,   180,   256,   182,   534,
     185,   125,   186,   259,    66,   259,   190,   191,   192,   193,
     194,    73,   259,   185,   198,   199,    78,   185,    80,   259,
     125,   256,   206,     1,     1,   260,     3,    37,   105,     6,
     259,    93,   156,    10,   238,    13,   156,   256,   259,   259,
     121,   260,  1037,  1038,  1039,   121,   259,   259,    25,    26,
      27,   156,   258,   237,    31,   239,    34,    35,   259,   121,
     256,   245,   139,    41,   126,   185,   250,   257,     1,   257,
     121,   255,    49,   257,   257,    85,    53,    54,   257,   259,
     258,   244,   257,   259,   258,   257,   148,    20,   154,   257,
     257,   256,   195,    26,   257,   259,   256,   259,   160,   156,
     162,   163,   259,     1,   185,   167,   259,    84,   259,    86,
       1,   121,   259,   123,   124,     1,    49,    50,     4,    97,
      98,    54,   259,   100,   244,    23,    24,   259,   185,   107,
     108,   259,    30,   257,   185,    68,   259,   257,   259,   216,
     259,   259,    75,   259,   121,   259,    37,   259,   259,   127,
     128,     1,   259,   259,   195,   259,   166,   259,   168,    45,
     259,    94,    48,   244,   226,   259,   144,   145,   259,   259,
     232,   181,   249,   259,   259,   259,   153,   155,   256,   259,
     257,   243,   244,   154,   259,   259,   164,   244,   259,   122,
     167,   253,   259,   244,    85,   257,   731,   130,   259,   259,
     177,   259,   132,   259,    54,   259,   257,   259,   154,   259,
     259,   109,   110,   111,   224,   148,   114,   259,   104,   259,
     259,     1,   259,   121,   157,   158,   259,   259,     1,   259,
     121,   259,   123,   124,    84,   121,   134,   135,   259,   259,
      90,   251,   252,    23,    24,   132,   259,   257,   259,   132,
      30,   259,   259,   151,   152,   188,   189,   259,   259,   259,
     259,   238,   882,   883,   884,   885,   886,    40,   246,   247,
     248,   259,   259,   259,   251,   166,   259,   168,   176,   257,
     257,   132,    55,   259,   171,   172,   173,   174,   175,   259,
     181,   259,   259,   259,     1,   259,   259,   915,   259,   259,
     259,     8,     9,   153,    77,    12,    79,   259,    81,    82,
     259,   244,    19,   217,   218,   219,   220,   221,   222,   223,
     259,    28,   259,   259,   257,    32,    33,   259,   101,   109,
     110,   111,    39,   224,   114,    42,    43,    44,   259,    46,
     259,   121,   259,   259,   259,    52,   259,   259,   259,     1,
     259,   259,   259,     5,   134,   135,   259,   259,   244,   257,
     251,   252,   259,   259,    71,    72,   132,   132,   195,    76,
     905,   151,   152,   195,    26,   132,    83,   195,   913,   914,
      87,    88,    89,   195,   195,    92,    38,   195,    95,    96,
     195,   256,   259,   259,   154,   256,   176,    49,   195,   106,
     259,   259,    54,   195,   132,   112,   113,   154,   115,   116,
     117,   118,   132,   195,    66,   132,   195,   195,   154,   195,
     132,    73,   129,   132,   132,   195,    78,   195,    80,   132,
     154,   138,     5,   140,   141,   132,   143,   195,   132,   146,
     147,    93,     1,   150,     3,   195,   132,     6,   154,   132,
     132,    10,   195,   195,   161,   259,   195,   259,   195,   154,
     195,   195,   195,   195,   195,    38,    25,    26,    27,   121,
     132,   256,    31,   180,   126,   182,    49,   195,   259,   186,
     195,   195,   195,   190,   191,   192,   193,   194,   259,   256,
      49,   198,   199,    66,    53,    54,   148,   259,   259,   206,
      73,   154,   256,   259,   259,    78,   259,    80,   160,   154,
     162,   163,   154,   259,   259,   167,   154,   154,   259,   259,
      93,   259,    20,    21,   154,    84,   154,    86,   154,   259,
     237,   154,   239,   259,   259,   154,   259,   259,   245,   195,
     259,   100,     1,   250,   154,   256,   154,   195,   255,   259,
     154,   256,    50,   126,    13,     1,   195,   259,   259,   259,
     259,   259,   121,   256,   195,   154,   195,    93,   259,   142,
      68,   259,   259,   195,   226,    34,    35,    75,     1,   256,
     232,   195,    41,   154,   154,   154,   154,   160,   154,   162,
     163,   243,   244,   154,   153,   132,    94,    20,    93,     0,
       1,   253,   154,    26,     5,   154,   256,   256,   167,   256,
      56,    57,    58,    59,    60,    61,    62,    63,   177,   259,
     154,    22,   256,   259,   122,    26,    49,    50,    29,   256,
     154,    54,   130,   200,   259,    36,   256,   310,    97,    98,
     256,   256,   259,   169,   256,    68,   259,   256,   107,   108,
      51,   256,    75,   226,   256,   256,   256,   256,   256,   105,
     256,   256,   256,    64,    65,   256,    67,   259,   127,   128,
     243,    94,   170,    74,   169,   201,   256,   256,   256,   238,
     253,   256,   259,   259,   154,   144,   145,   259,   154,   215,
      91,   189,   251,   139,   259,   259,   155,   259,   256,   122,
     256,   102,   259,   104,   259,   164,   201,   130,   234,   235,
     132,   259,   259,   259,   240,   241,   242,   243,   259,   120,
     215,   259,   159,   259,   259,   148,   259,   253,   259,   259,
     259,   259,   259,   256,   157,   158,   137,   259,   259,   234,
     235,   259,   259,   259,   259,   240,   241,   242,   243,   259,
     259,   256,   256,   256,   256,   256,   256,   256,   253,   256,
     256,   195,   256,   256,   256,   188,   189,   256,   169,   256,
     216,   256,   256,   256,   256,   256,   256,   178,   179,   256,
     256,   256,   183,   184,   256,   256,   259,   246,   247,   248,
     259,   202,   203,   204,   205,   256,   207,   208,   256,   210,
     211,   212,   256,   249,   215,   256,   256,   256,   256,   256,
     154,   256,   256,   256,   225,   226,   227,   228,   229,   230,
     256,   244,   233,   256,   256,   236,   202,   203,   204,   205,
     256,   207,   208,   154,   210,   211,   212,   256,   256,   215,
     256,   256,   256,   256,   256,   195,   256,   256,   256,   225,
     226,   227,   228,   229,   230,   154,   256,   233,   256,   256,
     236,   202,   203,   204,   205,   256,   207,   208,   256,   210,
     211,   212,   256,   256,   215,   195,   195,   259,   195,   195,
     195,   195,   195,   154,   225,   226,   227,   228,   229,   230,
     154,   154,   233,   195,   154,   236,   256,   154,   259,   154,
     256,   259,   154,   154,   132,   256,   259,   256,   256,   256,
     256,   256,   154,   256,   256,   154,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     154,   154,   154,   259,   259,   259,   259,   259,   154,   132,
     132,   259,   132,   132,   132,   132,   154,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   132,   259,   259,
     256,   259,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     132,   256,   154,   259,   256,   259,   256,   154,   195,   154,
     195,   195,   195,   154,   259,   154,   154,   154,   154,   132,
     154,   154,   256,   154,   195,   131,   256,   256,   256,   256,
     256,   256,   256,   256,   159,   256,   256,   195,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   131,   256,
     256,   256,   154,   195,   154,   256,   256,   256,   256,   154,
     195,   154,   154,   260,   259,   195,   195,   195,   195,   195,
     259,   195,   195,   195,   195,   195,   195,   195,   256,   256,
     256,   256,   256,   132,   131,    71,   814,   273,  1462,  1443,
     256,   256,   256,   256,   256,   256,   256,   256,  1441,   256,
     256,  1372,   256,   256,   604,   256,   256,   256,   256,   493,
     256,   460,   256,   256,  1355,  1254,   256,  1357,   523,   555,
    1421,   563,  1426,  1423,  1370,  1424,   483,   639,   122,   367,
    1348,   182,  1207,  1205,    94,    -1,  1352,  1354,    -1,   256,
     256,   256,   256,    -1,   256,   256,   256,   256,   256,   256,
      -1,   256,   256,   256,    -1,   256,    -1,   256,   256,   256,
     256,   355,   256,    -1,    -1,   256,   256,   256,   256,   256,
     256,   256,   256,    -1,   256,   256,   256,   256,   256,   256,
     256,   256,   256,    -1,    -1,    -1,   435,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   289
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   262,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   102,   104,   120,   137,   169,
     178,   179,   183,   184,   263,   268,   273,   287,   293,   308,
     345,   364,   378,   404,   411,   421,   430,   461,   471,   477,
     481,   491,   555,   571,   591,   256,   257,   258,   258,   346,
     431,   472,   258,   482,   258,   556,   379,   462,   365,   258,
     258,   309,   405,   258,   258,   412,   422,     1,    37,    47,
     121,   288,   289,   290,   291,   292,     1,    13,    34,    35,
      41,    97,    98,   107,   108,   127,   128,   144,   145,   155,
     164,   246,   247,   248,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   154,   347,   351,   154,   432,   436,   258,
       1,    90,   478,   479,   480,   258,     1,     8,     9,    12,
      19,    28,    32,    33,    39,    42,    43,    44,    46,    52,
      71,    72,    76,    83,    87,    88,    89,    92,    95,    96,
     106,   112,   113,   115,   116,   117,   118,   129,   138,   140,
     141,   143,   146,   147,   150,   161,   180,   182,   186,   190,
     191,   192,   193,   194,   198,   199,   206,   237,   239,   245,
     250,   255,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   546,   550,   551,   552,   553,   554,   258,
     258,   258,   258,     1,    56,    57,    58,    59,    60,    61,
      62,    63,   105,   139,   216,   249,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
       1,   119,   149,   269,   270,   271,   272,   154,   310,   314,
     258,     1,    40,    55,    77,    79,    81,    82,   101,   592,
     593,   594,   595,   596,   597,   598,   599,   600,     1,    37,
      85,   121,   123,   124,   166,   168,   181,   224,   251,   252,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   258,   258,   256,   259,   259,   259,   257,
     289,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   257,   573,
     258,   258,     1,    90,   156,   473,   474,   475,   476,   259,
     257,   479,     1,   121,   156,   185,   483,   487,   488,   489,
     490,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   547,   259,   543,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   257,   493,     1,     4,
      45,    48,   104,   121,   244,   557,   558,   559,   560,   561,
     565,   566,   567,     1,    20,    26,    49,    50,    54,    68,
      75,    94,   122,   130,   148,   157,   158,   188,   189,   244,
     380,   381,   382,   383,   384,   385,   386,   387,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,     1,   156,
     185,   244,   463,   467,   468,   469,   470,     1,    54,    84,
      90,   153,   366,   370,   371,   372,   376,   377,   256,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   257,   295,   256,   259,   259,   257,   270,   258,     1,
      22,   125,   156,   406,   407,   408,   409,   410,   259,   259,
     259,   259,   259,   259,   259,   257,   593,   256,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     275,     1,   121,   185,   244,   413,   414,   415,   416,   417,
       1,   121,   185,   423,   424,   425,   426,   154,   154,   154,
     256,   195,   132,   132,   195,   132,   265,   265,   132,   132,
     195,   195,   132,   265,   195,   195,   195,   195,   195,   256,
       1,    23,    24,    30,   109,   110,   111,   114,   121,   134,
     135,   151,   152,   176,   348,   349,   350,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,     1,
       3,     6,    10,    25,    26,    27,    31,    49,    53,    54,
      84,    86,   100,   121,   153,   167,   177,   238,   251,   433,
     434,   435,   437,   438,   439,   440,   441,   442,   443,   444,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     259,   259,   257,   474,   154,   256,   259,   259,   484,   257,
     488,   195,   265,   195,   265,   132,   154,   132,   195,   195,
     195,   132,   154,   195,   132,   132,   132,   195,   265,   195,
     195,   132,   154,   195,   132,   132,   265,   132,   154,   132,
     132,   195,   195,   259,   195,   259,   265,   265,   195,   265,
     154,   195,   195,   195,   195,   196,   195,   196,   195,   195,
     265,   265,   132,   267,   265,   195,   195,   195,   195,   256,
     568,   259,   259,   562,   259,   259,   257,   558,   256,   259,
     259,   259,   259,   388,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   257,   381,   259,   464,   259,
     257,   468,   256,   367,   259,   259,   259,   257,   371,   154,
     154,   154,   154,   154,   154,   154,   154,   217,   218,   219,
     220,   221,   222,   223,   154,   154,   195,   256,   154,   154,
     256,     1,     5,    26,    38,    49,    54,    66,    73,    78,
      80,    93,   121,   126,   148,   160,   162,   163,   167,   226,
     232,   243,   244,   253,   311,   312,   313,   315,   316,   317,
     318,   319,   320,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   256,   259,
     259,   259,   257,   407,   195,   195,   195,   154,   195,   195,
     265,   256,   154,   195,   154,   154,   154,   154,   154,   154,
     132,   154,   154,   256,   256,   259,   418,   259,   257,   414,
     256,   259,   427,   257,   424,   256,   256,   256,   256,   256,
     256,   256,   171,   172,   173,   174,   175,   264,   265,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   257,   349,   256,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   445,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   257,   434,
     154,   154,   256,   256,   154,   154,   259,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     202,   203,   204,   205,   207,   208,   210,   211,   212,   215,
     225,   226,   227,   228,   229,   230,   233,   236,   548,   549,
     256,   202,   203,   204,   205,   207,   208,   210,   211,   212,
     215,   225,   226,   227,   228,   229,   230,   233,   236,   544,
     545,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,    14,    15,    16,
     266,   267,   256,   256,   256,   256,   256,   256,   259,   265,
     195,   259,   154,   154,   256,   195,   154,   195,   195,   259,
     195,   195,   195,   195,   195,   154,   132,   154,   154,   195,
     154,   256,   154,   259,   154,   256,   259,   154,   154,   132,
     374,   375,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   259,   259,   259,   259,   339,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   321,   259,   259,   259,   257,   312,   154,   154,
     154,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     154,   259,   154,   256,   154,   259,   256,   264,   264,   264,
     264,   264,   132,   132,   265,   132,   132,   132,   132,   154,
     132,   132,   265,   265,   267,   256,   154,   213,   214,   195,
     154,   154,   195,   195,   195,   154,   259,   154,   154,   154,
     154,   132,   154,   154,   195,   154,   256,   256,   256,   256,
     256,   159,   485,   486,   256,   260,   256,   260,   266,   266,
     266,    11,   197,   569,   570,   256,   256,    11,   197,   563,
     564,   256,   256,   256,   256,   256,   256,   131,   389,   390,
     392,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   159,   465,   466,   256,    77,   231,   368,
     369,   256,   256,   200,   260,   373,   195,   154,   195,   195,
     259,   195,   195,   195,   195,   195,   154,   195,   154,   195,
     195,   195,   154,   195,   259,   195,   154,   195,   256,   256,
     256,   256,   256,    93,   169,   201,   215,   234,   235,   240,
     241,   242,   243,   253,   419,   420,   256,   256,    93,   169,
     201,   215,   234,   235,   240,   241,   242,   243,   253,   428,
     429,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   131,   446,   447,   449,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   260,   549,
     545,   256,   260,   256,   260,   391,   256,   260,    20,    21,
      50,    68,    75,    94,   122,   130,   170,   189,   393,   256,
     260,   256,   260,   132,   375,   256,   256,   256,   256,   256,
     131,   340,   341,   343,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   202,   203,   204,
     205,   207,   208,   210,   211,   212,   215,   225,   226,   227,
     228,   229,   230,   233,   236,   322,   323,   256,   256,   256,
     256,   260,   256,   260,   448,   256,   260,    10,    12,    27,
      31,    99,   238,   450,   486,   570,   564,   393,   390,   466,
     369,   342,   256,   260,     5,    38,    49,    66,    73,    78,
      80,    93,   126,   142,   160,   162,   163,   226,   243,   253,
     344,   256,   260,   420,   429,   450,   447,   344,   341,   323
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 422 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 424 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
    break;

  case 29:
#line 428 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
    break;

  case 30:
#line 432 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
    break;

  case 31:
#line 436 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
    break;

  case 32:
#line 440 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
    break;

  case 33:
#line 444 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
    break;

  case 34:
#line 449 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 450 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
    break;

  case 37:
#line 451 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
    break;

  case 38:
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
    break;

  case 39:
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
    break;

  case 46:
#line 467 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    add_conf_module(yylval.string);
  }
#endif
}
    break;

  case 47:
#line 484 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 508 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2 && ServerInfo.ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.ctx,
      yylval.string, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.ctx,
      ServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.ctx))
    {
      yyerror("RSA private key does not match the SSL certificate public key!");
      break;
    }
  }
#endif
}
    break;

  case 64:
#line 542 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 1)
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

  case 65:
#line 602 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2)
  {
    if (ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if (strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name, yylval.string);
    }
  }
}
    break;

  case 66:
#line 616 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 631 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 640 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 69:
#line 654 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 663 "ircd_parser.y"
    {
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 71:
#line 691 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 72:
#line 721 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = (yyvsp[-1].number);
  }
}
    break;

  case 73:
#line 744 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "Ignoring config file line hub=yes; "
                             "due to active LazyLink (%s)", uplink->name);
      }
      else
      {
        ServerInfo.hub = 1;
        uplink = NULL;
        delete_capability("HUB");
        add_capability("HUB", CAP_HUB, 1);
      }
    }
    else if (ServerInfo.hub)
    {
      dlink_node *ptr = NULL;

      ServerInfo.hub = 0;
      delete_capability("HUB");

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        const struct Client *acptr = ptr->data;
        if (MyConnect(acptr) && IsCapable(acptr, CAP_LL))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               acptr->name);
          add_capability("HUB", CAP_HUB, 1);
          ServerInfo.hub = 1;
          break;
        }
      }
    }
  }
}
    break;

  case 81:
#line 800 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 809 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 818 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 845 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 849 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 853 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 860 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 867 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 874 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 881 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 888 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 895 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 902 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 909 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 913 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 917 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 921 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 925 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 929 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 933 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 939 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 948 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 119:
#line 961 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 147:
#line 1053 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 148:
#line 1065 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 149:
#line 1077 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 150:
#line 1096 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 151:
#line 1108 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 152:
#line 1119 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

  case 153:
#line 1161 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1170 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1177 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1181 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1185 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1189 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1193 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1197 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1201 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1205 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1209 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1213 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1217 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1221 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1225 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1229 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1233 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1237 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1241 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1245 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1251 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 177:
#line 1262 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
}
    break;

  case 178:
#line 1273 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 179:
#line 1284 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
}
    break;

  case 180:
#line 1295 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
}
    break;

  case 181:
#line 1306 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
}
    break;

  case 182:
#line 1317 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
}
    break;

  case 183:
#line 1328 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
}
    break;

  case 184:
#line 1339 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
}
    break;

  case 185:
#line 1350 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
}
    break;

  case 186:
#line 1361 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
}
    break;

  case 187:
#line 1372 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 188:
#line 1383 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 189:
#line 1394 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
}
    break;

  case 190:
#line 1405 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1409 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1410 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1413 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1420 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1427 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1434 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1441 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1448 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1455 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1462 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1469 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1476 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1483 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1490 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1497 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1504 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1511 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1518 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1531 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 215:
#line 1538 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
    {
      delete_conf_item(yy_conf);
    }
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        rebuild_cidr_class(cconf, yy_class);
        class = (struct ClassItem *) map_to_conf(cconf);
        *class = *yy_class;
        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
      }
    }
    yy_class_name = NULL;
  }
}
    break;

  case 234:
#line 1590 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1599 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1608 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 237:
#line 1614 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[-1].number);
}
    break;

  case 238:
#line 1620 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[-1].number);
}
    break;

  case 239:
#line 1626 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 240:
#line 1632 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 241:
#line 1638 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 242:
#line 1644 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 243:
#line 1650 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[-1].number);
}
    break;

  case 244:
#line 1656 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 245:
#line 1662 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[-1].number);
}
    break;

  case 246:
#line 1668 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[-1].number);
}
    break;

  case 247:
#line 1674 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[-1].number);
}
    break;

  case 248:
#line 1683 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1690 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1699 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 254:
#line 1705 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1709 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 263:
#line 1717 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 267:
#line 1722 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[0].number), listener_address, listener_flags);
  }
}
    break;

  case 268:
#line 1736 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, listener_address, listener_flags);
  }
}
    break;

  case 269:
#line 1756 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1765 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 271:
#line 1777 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 272:
#line 1789 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 292:
#line 1854 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 293:
#line 1873 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 294:
#line 1886 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 295:
#line 1897 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 296:
#line 1906 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 297:
#line 1917 "ircd_parser.y"
    {
}
    break;

  case 301:
#line 1921 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 303:
#line 1922 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 305:
#line 1925 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 306:
#line 1933 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 307:
#line 1940 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 308:
#line 1947 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 309:
#line 1954 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 310:
#line 1961 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 311:
#line 1968 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 312:
#line 1975 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 313:
#line 1982 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 314:
#line 1989 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 315:
#line 1998 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
}
    break;

  case 316:
#line 2009 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 317:
#line 2020 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 318:
#line 2031 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 319:
#line 2042 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
}
    break;

  case 320:
#line 2053 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
}
    break;

  case 321:
#line 2065 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 322:
#line 2084 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 323:
#line 2094 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[-1].number);
  }
}
    break;

  case 324:
#line 2103 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 325:
#line 2118 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 326:
#line 2125 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 333:
#line 2137 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 334:
#line 2146 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 335:
#line 2161 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 336:
#line 2174 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 337:
#line 2182 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 344:
#line 2193 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 345:
#line 2202 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 346:
#line 2210 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 350:
#line 2217 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 351:
#line 2221 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 352:
#line 2225 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 353:
#line 2229 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 354:
#line 2233 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 355:
#line 2237 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 356:
#line 2241 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 357:
#line 2245 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 358:
#line 2249 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 359:
#line 2253 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 360:
#line 2257 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 361:
#line 2266 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 362:
#line 2273 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 368:
#line 2286 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 369:
#line 2292 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 373:
#line 2299 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 374:
#line 2303 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 375:
#line 2307 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 376:
#line 2311 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 377:
#line 2315 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 378:
#line 2319 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 379:
#line 2323 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 380:
#line 2327 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 381:
#line 2331 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 382:
#line 2335 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 383:
#line 2339 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 384:
#line 2348 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->passwd = NULL;
    /* defaults */
    yy_aconf->port = PORTNUM;

    if (ConfigFileEntry.burst_away)
      yy_aconf->flags = CONF_FLAGS_BURST_AWAY;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 385:
#line 2366 "ircd_parser.y"
    {
  if (ypass == 2)
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
	  if (conf_add_server(yy_conf, scount, class_name) >= 0)
	  {
	    ++scount;
	  }
	  else
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

  case 410:
#line 2509 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 411:
#line 2521 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 412:
#line 2533 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 413:
#line 2542 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);
    }
  }
}
    break;

  case 414:
#line 2568 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
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

  case 415:
#line 2586 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
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

  case 416:
#line 2604 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[-1].number);
}
    break;

  case 417:
#line 2610 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 418:
#line 2614 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 419:
#line 2622 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 420:
#line 2631 "ircd_parser.y"
    {
}
    break;

  case 424:
#line 2635 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 426:
#line 2636 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 428:
#line 2639 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 429:
#line 2646 "ircd_parser.y"
    {
  if (ypass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   if (not_atom)ClearConfCompressed(yy_aconf);
   else SetConfCompressed(yy_aconf);
 }
#endif
}
    break;

  case 430:
#line 2657 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 431:
#line 2664 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 432:
#line 2671 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 433:
#line 2678 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 434:
#line 2688 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

  case 435:
#line 2729 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 436:
#line 2740 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
}
    break;

  case 437:
#line 2751 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
#ifndef HAVE_LIBZ
      yyerror("Ignoring compressed=yes; -- no zlib support");
#else
      yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
    else
      yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  }
}
    break;

  case 438:
#line 2766 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
}
    break;

  case 439:
#line 2777 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfTopicBurst(yy_aconf);
    else
      ClearConfTopicBurst(yy_aconf);
  }
}
    break;

  case 440:
#line 2788 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 441:
#line 2801 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 442:
#line 2814 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 443:
#line 2823 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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
  if (ypass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 444:
#line 2858 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 445:
#line 2865 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
        pcre *exp_user = NULL;
        pcre *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
      }
      else
      {
        yy_conf = make_conf_item(KLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }
    else
      delete_conf_item(yy_conf);

    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 446:
#line 2919 "ircd_parser.y"
    {
}
    break;

  case 450:
#line 2924 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 457:
#line 2933 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *user = NULL, *host = NULL;

    split_nuh(yylval.string, NULL, &user, &host);

    strlcpy(userbuf, user, sizeof(userbuf));
    strlcpy(hostbuf, host, sizeof(hostbuf));

    MyFree(user);
    MyFree(host);
  }
}
    break;

  case 458:
#line 2949 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 459:
#line 2958 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
}
    break;

  case 460:
#line 2967 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_DLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 466:
#line 2983 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 467:
#line 2992 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 473:
#line 3009 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
      yy_aconf = map_to_conf(yy_conf);
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);

      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 474:
#line 3030 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 475:
#line 3037 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
        pcre *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
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

  case 476:
#line 3071 "ircd_parser.y"
    {
}
    break;

  case 480:
#line 3076 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 487:
#line 3085 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 488:
#line 3091 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 548:
#line 3136 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
    break;

  case 549:
#line 3141 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
    break;

  case 550:
#line 3146 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 551:
#line 3151 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 552:
#line 3156 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 553:
#line 3161 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 554:
#line 3166 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
    break;

  case 555:
#line 3171 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 556:
#line 3176 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 557:
#line 3181 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 558:
#line 3186 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 559:
#line 3191 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 560:
#line 3196 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
    break;

  case 561:
#line 3201 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
    break;

  case 562:
#line 3206 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
    break;

  case 563:
#line 3211 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
    break;

  case 564:
#line 3216 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
    break;

  case 565:
#line 3221 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
    break;

  case 566:
#line 3227 "ircd_parser.y"
    {
  if (((yyvsp[-1].number) > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 567:
#line 3238 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 568:
#line 3243 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 569:
#line 3252 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 570:
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 571:
#line 3262 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 572:
#line 3267 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 573:
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 574:
#line 3277 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 575:
#line 3280 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 576:
#line 3285 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 577:
#line 3288 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 578:
#line 3293 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
    break;

  case 579:
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
    break;

  case 580:
#line 3303 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 581:
#line 3308 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
    break;

  case 582:
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 583:
#line 3318 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 584:
#line 3323 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 585:
#line 3328 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 586:
#line 3333 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 587:
#line 3344 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[-1].number);
}
    break;

  case 588:
#line 3349 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
    break;

  case 589:
#line 3354 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
    break;

  case 590:
#line 3359 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 591:
#line 3368 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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
  if (ypass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 592:
#line 3400 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = (yyvsp[-1].number);
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

  case 593:
#line 3418 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 594:
#line 3423 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 595:
#line 3432 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 596:
#line 3437 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 597:
#line 3442 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 598:
#line 3447 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 602:
#line 3453 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 603:
#line 3456 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 604:
#line 3459 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 605:
#line 3462 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 606:
#line 3465 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 607:
#line 3468 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 608:
#line 3471 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 609:
#line 3474 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 610:
#line 3477 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 611:
#line 3480 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 612:
#line 3483 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 613:
#line 3486 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 614:
#line 3489 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 615:
#line 3492 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 616:
#line 3495 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 617:
#line 3498 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 618:
#line 3501 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 619:
#line 3504 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 620:
#line 3509 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 624:
#line 3515 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 625:
#line 3518 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 626:
#line 3521 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 627:
#line 3524 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 628:
#line 3527 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 629:
#line 3530 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 630:
#line 3533 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 631:
#line 3536 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 632:
#line 3539 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 633:
#line 3542 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 634:
#line 3545 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 635:
#line 3548 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 636:
#line 3551 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 637:
#line 3554 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 638:
#line 3557 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 639:
#line 3560 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 640:
#line 3563 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 641:
#line 3566 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 642:
#line 3571 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
    break;

  case 643:
#line 3576 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
    break;

  case 644:
#line 3581 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
    break;

  case 645:
#line 3586 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[-1].number);
}
    break;

  case 646:
#line 3591 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 647:
#line 3599 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 648:
#line 3606 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 658:
#line 3632 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 659:
#line 3638 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
    break;

  case 660:
#line 3644 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 664:
#line 3650 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 665:
#line 3654 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 666:
#line 3660 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 667:
#line 3679 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 668:
#line 3688 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 669:
#line 3692 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 672:
#line 3739 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 673:
#line 3743 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 695:
#line 3767 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 696:
#line 3772 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 697:
#line 3777 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 698:
#line 3782 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 699:
#line 3787 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 700:
#line 3792 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
    break;

  case 701:
#line 3797 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
    break;

  case 702:
#line 3802 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
    break;

  case 703:
#line 3807 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 704:
#line 3812 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
    break;

  case 705:
#line 3817 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
    break;

  case 706:
#line 3822 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
    break;

  case 707:
#line 3827 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 708:
#line 3832 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 709:
#line 3837 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 710:
#line 3842 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 711:
#line 3847 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 723:
#line 3866 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 724:
#line 3872 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 725:
#line 3878 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 726:
#line 3887 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[-1].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
    break;

  case 727:
#line 3901 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 728:
#line 3907 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 729:
#line 3913 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 7457 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



