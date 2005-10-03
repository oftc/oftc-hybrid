/* A Bison parser, made by GNU Bison 2.0.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

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
     INVITE_OPS_ONLY = 399,
     JOIN_FLOOD_COUNT = 400,
     JOIN_FLOOD_TIME = 401,
     PACE_WAIT = 402,
     PACE_WAIT_SIMPLE = 403,
     PASSWORD = 404,
     PATH = 405,
     PING_COOKIE = 406,
     PING_TIME = 407,
     PING_WARNING = 408,
     PORT = 409,
     QSTRING = 410,
     QUIET_ON_BAN = 411,
     REASON = 412,
     REDIRPORT = 413,
     REDIRSERV = 414,
     REGEX_T = 415,
     REHASH = 416,
     TREJECT_HOLD_TIME = 417,
     REMOTE = 418,
     REMOTEBAN = 419,
     RESTRICT_CHANNELS = 420,
     RESTRICTED = 421,
     RSA_PRIVATE_KEY_FILE = 422,
     RSA_PUBLIC_KEY_FILE = 423,
     SSL_CERTIFICATE_FILE = 424,
     RESV = 425,
     RESV_EXEMPT = 426,
     SECONDS = 427,
     MINUTES = 428,
     HOURS = 429,
     DAYS = 430,
     WEEKS = 431,
     SENDQ = 432,
     SEND_PASSWORD = 433,
     SERVERHIDE = 434,
     SERVERINFO = 435,
     SERVLINK_PATH = 436,
     IRCD_SID = 437,
     TKLINE_EXPIRE_NOTICES = 438,
     T_SHARED = 439,
     T_CLUSTER = 440,
     TYPE = 441,
     SHORT_MOTD = 442,
     SILENT = 443,
     SPOOF = 444,
     SPOOF_NOTICE = 445,
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
#define INVITE_OPS_ONLY 399
#define JOIN_FLOOD_COUNT 400
#define JOIN_FLOOD_TIME 401
#define PACE_WAIT 402
#define PACE_WAIT_SIMPLE 403
#define PASSWORD 404
#define PATH 405
#define PING_COOKIE 406
#define PING_TIME 407
#define PING_WARNING 408
#define PORT 409
#define QSTRING 410
#define QUIET_ON_BAN 411
#define REASON 412
#define REDIRPORT 413
#define REDIRSERV 414
#define REGEX_T 415
#define REHASH 416
#define TREJECT_HOLD_TIME 417
#define REMOTE 418
#define REMOTEBAN 419
#define RESTRICT_CHANNELS 420
#define RESTRICTED 421
#define RSA_PRIVATE_KEY_FILE 422
#define RSA_PUBLIC_KEY_FILE 423
#define SSL_CERTIFICATE_FILE 424
#define RESV 425
#define RESV_EXEMPT 426
#define SECONDS 427
#define MINUTES 428
#define HOURS 429
#define DAYS 430
#define WEEKS 431
#define SENDQ 432
#define SEND_PASSWORD 433
#define SERVERHIDE 434
#define SERVERINFO 435
#define SERVLINK_PATH 436
#define IRCD_SID 437
#define TKLINE_EXPIRE_NOTICES 438
#define T_SHARED 439
#define T_CLUSTER 440
#define TYPE 441
#define SHORT_MOTD 442
#define SILENT 443
#define SPOOF 444
#define SPOOF_NOTICE 445
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 134 "ircd_parser.y"
typedef union YYSTYPE {
  int number;
  char *string;
} YYSTYPE;
/* Line 190 of yacc.c.  */
#line 700 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 213 of yacc.c.  */
#line 712 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
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
	  register YYSIZE_T yyi;		\
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
#define YYLAST   1424

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  261
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  332
/* YYNRULES -- Number of rules. */
#define YYNRULES  720
/* YYNRULES -- Number of states. */
#define YYNSTATES  1458

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   510

#define YYTRANSLATE(YYX) 						\
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
     594,   595,   601,   605,   607,   610,   612,   614,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   645,   653,   654,   656,   659,   661,   663,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   690,   695,   697,   702,   707,   712,   717,   722,
     727,   732,   737,   742,   747,   752,   757,   758,   765,   766,
     772,   776,   778,   780,   782,   785,   787,   789,   791,   793,
     795,   798,   803,   807,   809,   811,   815,   820,   825,   826,
     833,   836,   838,   840,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   873,
     878,   883,   888,   893,   898,   899,   905,   909,   911,   914,
     916,   918,   920,   922,   924,   926,   928,   930,   932,   934,
     936,   941,   946,   951,   956,   961,   966,   971,   976,   981,
     986,   987,   994,   997,   999,  1001,  1003,  1005,  1008,  1013,
    1018,  1023,  1024,  1031,  1034,  1036,  1038,  1040,  1042,  1045,
    1050,  1055,  1056,  1062,  1066,  1068,  1070,  1072,  1074,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1091,  1098,  1101,
    1103,  1105,  1107,  1110,  1115,  1116,  1122,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1151,  1159,  1160,  1162,  1165,  1167,  1169,  1171,  1173,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1206,  1211,  1213,  1218,  1223,  1228,
    1233,  1238,  1243,  1248,  1253,  1254,  1260,  1264,  1266,  1269,
    1271,  1273,  1275,  1277,  1279,  1281,  1283,  1288,  1293,  1298,
    1303,  1308,  1313,  1318,  1323,  1328,  1329,  1336,  1337,  1343,
    1347,  1349,  1351,  1354,  1356,  1358,  1360,  1362,  1364,  1369,
    1374,  1375,  1382,  1385,  1387,  1389,  1391,  1393,  1398,  1403,
    1409,  1412,  1414,  1416,  1418,  1423,  1424,  1431,  1432,  1438,
    1442,  1444,  1446,  1449,  1451,  1453,  1455,  1457,  1459,  1464,
    1469,  1475,  1478,  1480,  1482,  1484,  1486,  1488,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1595,
    1600,  1605,  1610,  1615,  1620,  1625,  1630,  1635,  1640,  1645,
    1650,  1655,  1660,  1665,  1670,  1675,  1680,  1685,  1690,  1695,
    1700,  1705,  1710,  1715,  1720,  1725,  1730,  1735,  1740,  1745,
    1750,  1755,  1760,  1765,  1770,  1775,  1780,  1785,  1790,  1795,
    1800,  1805,  1810,  1815,  1820,  1825,  1830,  1835,  1836,  1842,
    1846,  1848,  1850,  1852,  1854,  1856,  1858,  1860,  1862,  1864,
    1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,  1882,  1884,
    1885,  1891,  1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,
    1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,
    1931,  1933,  1938,  1943,  1948,  1953,  1958,  1959,  1966,  1969,
    1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1990,  1995,
    1996,  2002,  2006,  2008,  2010,  2012,  2017,  2022,  2023,  2029,
    2033,  2035,  2037,  2039,  2045,  2048,  2050,  2052,  2054,  2056,
    2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,
    2078,  2080,  2082,  2084,  2086,  2088,  2093,  2098,  2103,  2108,
    2113,  2118,  2123,  2128,  2133,  2138,  2143,  2148,  2153,  2158,
    2163,  2168,  2173,  2178,  2184,  2187,  2189,  2191,  2193,  2195,
    2197,  2199,  2201,  2203,  2205,  2210,  2215,  2220,  2225,  2230,
    2235
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     262,     0,    -1,    -1,   262,   263,    -1,   287,    -1,   293,
      -1,   308,    -1,   562,    -1,   343,    -1,   362,    -1,   375,
      -1,   273,    -1,   583,    -1,   399,    -1,   406,    -1,   416,
      -1,   425,    -1,   453,    -1,   463,    -1,   469,    -1,   483,
      -1,   546,    -1,   473,    -1,   268,    -1,     1,   256,    -1,
       1,   257,    -1,    -1,   265,    -1,   132,   264,    -1,   132,
     172,   264,    -1,   132,   173,   264,    -1,   132,   174,   264,
      -1,   132,   175,   264,    -1,   132,   176,   264,    -1,    -1,
     267,    -1,   132,   266,    -1,   132,    14,   266,    -1,   132,
      15,   266,    -1,   132,    16,   266,    -1,   120,   258,   269,
     257,   256,    -1,   269,   270,    -1,   270,    -1,   271,    -1,
     272,    -1,     1,   256,    -1,   119,   259,   155,   256,    -1,
     150,   259,   155,   256,    -1,   180,   258,   274,   257,   256,
      -1,   274,   275,    -1,   275,    -1,   278,    -1,   283,    -1,
     286,    -1,   280,    -1,   281,    -1,   282,    -1,   285,    -1,
     277,    -1,   284,    -1,   279,    -1,   276,    -1,     1,   256,
      -1,   169,   259,   155,   256,    -1,   167,   259,   155,   256,
      -1,   121,   259,   155,   256,    -1,   182,   259,   155,   256,
      -1,    37,   259,   155,   256,    -1,   124,   259,   155,   256,
      -1,   123,   259,   155,   256,    -1,   251,   259,   155,   256,
      -1,   252,   259,   155,   256,    -1,   224,   259,   132,   256,
      -1,    85,   259,   195,   256,    -1,     5,   258,   288,   257,
     256,    -1,   288,   289,    -1,   289,    -1,   290,    -1,   292,
      -1,   291,    -1,     1,   256,    -1,   121,   259,   155,   256,
      -1,    47,   259,   155,   256,    -1,    37,   259,   155,   256,
      -1,   104,   258,   294,   257,   256,    -1,   294,   295,    -1,
     295,    -1,   296,    -1,   297,    -1,   306,    -1,   307,    -1,
     298,    -1,   300,    -1,   302,    -1,   303,    -1,   305,    -1,
     301,    -1,   304,    -1,   299,    -1,     1,   256,    -1,   216,
     259,   155,   256,    -1,   139,   259,   155,   256,    -1,    63,
     259,   155,   256,    -1,    56,   259,   155,   256,    -1,    61,
     259,   155,   256,    -1,    62,   259,   155,   256,    -1,    59,
     259,   155,   256,    -1,    58,   259,   155,   256,    -1,    60,
     259,   155,   256,    -1,    57,   259,   155,   256,    -1,   105,
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
       1,   256,    -1,   121,   259,   155,   256,    -1,   155,    -1,
     244,   259,   155,   256,    -1,   149,   259,   155,   256,    -1,
      49,   259,   195,   256,    -1,   168,   259,   155,   256,    -1,
      26,   259,   155,   256,    -1,    -1,   232,   321,   259,   322,
     256,    -1,   322,   260,   323,    -1,   323,    -1,   202,    -1,
     205,    -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,
     225,    -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,
     226,    -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,
     204,    -1,   215,    -1,    73,   259,   195,   256,    -1,   163,
     259,   195,   256,    -1,   164,   259,   195,   256,    -1,    93,
     259,   195,   256,    -1,   253,   259,   195,   256,    -1,   243,
     259,   195,   256,    -1,    66,   259,   195,   256,    -1,   126,
     259,   195,   256,    -1,    38,   259,   195,   256,    -1,   161,
     259,   195,   256,    -1,     5,   259,   195,   256,    -1,    78,
     259,   195,   256,    -1,    80,   259,   195,   256,    -1,   226,
     259,   195,   256,    -1,    -1,    54,   339,   259,   340,   256,
      -1,   340,   260,   341,    -1,   341,    -1,   131,   342,    -1,
     342,    -1,    73,    -1,   163,    -1,    93,    -1,   243,    -1,
     253,    -1,    66,    -1,    38,    -1,   161,    -1,     5,    -1,
      78,    -1,   126,    -1,   226,    -1,   142,    -1,    80,    -1,
     164,    -1,    49,    -1,    -1,    26,   344,   345,   258,   346,
     257,   256,    -1,    -1,   349,    -1,   346,   347,    -1,   347,
      -1,   348,    -1,   359,    -1,   360,    -1,   350,    -1,   351,
      -1,   361,    -1,   352,    -1,   353,    -1,   354,    -1,   355,
      -1,   356,    -1,   357,    -1,   358,    -1,     1,   256,    -1,
     121,   259,   155,   256,    -1,   155,    -1,   152,   259,   265,
     256,    -1,   153,   259,   265,   256,    -1,   135,   259,   132,
     256,    -1,    30,   259,   265,   256,    -1,   114,   259,   132,
     256,    -1,   109,   259,   132,   256,    -1,   111,   259,   132,
     256,    -1,   110,   259,   132,   256,    -1,   177,   259,   267,
     256,    -1,    23,   259,   132,   256,    -1,    24,   259,   132,
     256,    -1,   134,   259,   132,   256,    -1,    -1,   102,   363,
     258,   368,   257,   256,    -1,    -1,    54,   365,   259,   366,
     256,    -1,   366,   260,   367,    -1,   367,    -1,   231,    -1,
      77,    -1,   368,   369,    -1,   369,    -1,   370,    -1,   364,
      -1,   373,    -1,   374,    -1,     1,   256,    -1,   154,   259,
     371,   256,    -1,   371,   260,   372,    -1,   372,    -1,   132,
      -1,   132,   200,   132,    -1,    90,   259,   155,   256,    -1,
      84,   259,   155,   256,    -1,    -1,    74,   376,   258,   377,
     257,   256,    -1,   377,   378,    -1,   378,    -1,   379,    -1,
     380,    -1,   382,    -1,   384,    -1,   389,    -1,   390,    -1,
     391,    -1,   393,    -1,   394,    -1,   395,    -1,   381,    -1,
     396,    -1,   397,    -1,   392,    -1,   398,    -1,   383,    -1,
       1,   256,    -1,   244,   259,   155,   256,    -1,   149,   259,
     155,   256,    -1,   190,   259,   195,   256,    -1,    26,   259,
     155,   256,    -1,    49,   259,   195,   256,    -1,    -1,    54,
     385,   259,   386,   256,    -1,   386,   260,   387,    -1,   387,
      -1,   131,   388,    -1,   388,    -1,   190,    -1,    50,    -1,
      94,    -1,    75,    -1,    20,    -1,    21,    -1,   130,    -1,
      68,    -1,   171,    -1,   122,    -1,    94,   259,   195,   256,
      -1,    75,   259,   195,   256,    -1,    50,   259,   195,   256,
      -1,    20,   259,   195,   256,    -1,   130,   259,   195,   256,
      -1,    68,   259,   195,   256,    -1,   189,   259,   155,   256,
      -1,   159,   259,   155,   256,    -1,   158,   259,   132,   256,
      -1,   122,   259,   195,   256,    -1,    -1,   170,   400,   258,
     401,   257,   256,    -1,   401,   402,    -1,   402,    -1,   403,
      -1,   404,    -1,   405,    -1,     1,   256,    -1,   157,   259,
     155,   256,    -1,    22,   259,   155,   256,    -1,   125,   259,
     155,   256,    -1,    -1,   184,   407,   258,   408,   257,   256,
      -1,   408,   409,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,     1,   256,    -1,   121,   259,   155,   256,    -1,
     244,   259,   155,   256,    -1,    -1,   186,   413,   259,   414,
     256,    -1,   414,   260,   415,    -1,   415,    -1,    93,    -1,
     240,    -1,   243,    -1,   253,    -1,   241,    -1,   235,    -1,
     170,    -1,   242,    -1,   234,    -1,   215,    -1,   201,    -1,
      -1,   185,   417,   258,   418,   257,   256,    -1,   418,   419,
      -1,   419,    -1,   420,    -1,   421,    -1,     1,   256,    -1,
     121,   259,   155,   256,    -1,    -1,   186,   422,   259,   423,
     256,    -1,   423,   260,   424,    -1,   424,    -1,    93,    -1,
     240,    -1,   243,    -1,   253,    -1,   241,    -1,   235,    -1,
     170,    -1,   242,    -1,   234,    -1,   215,    -1,   201,    -1,
      -1,    29,   426,   427,   258,   428,   257,   256,    -1,    -1,
     431,    -1,   428,   429,    -1,   429,    -1,   430,    -1,   432,
      -1,   433,    -1,   434,    -1,   435,    -1,   437,    -1,   436,
      -1,   438,    -1,   439,    -1,   449,    -1,   450,    -1,   451,
      -1,   448,    -1,   445,    -1,   447,    -1,   446,    -1,   444,
      -1,   452,    -1,     1,   256,    -1,   121,   259,   155,   256,
      -1,   155,    -1,    84,   259,   155,   256,    -1,   251,   259,
     155,   256,    -1,   178,   259,   155,   256,    -1,     3,   259,
     155,   256,    -1,   154,   259,   132,   256,    -1,     6,   259,
     213,   256,    -1,     6,   259,   214,   256,    -1,    53,   259,
     155,   256,    -1,    -1,    54,   440,   259,   441,   256,    -1,
     441,   260,   442,    -1,   442,    -1,   131,   443,    -1,   443,
      -1,    99,    -1,    27,    -1,    31,    -1,    10,    -1,    12,
      -1,   238,    -1,   168,   259,   155,   256,    -1,    49,   259,
     195,   256,    -1,    31,   259,   195,   256,    -1,    27,   259,
     195,   256,    -1,    10,   259,   195,   256,    -1,    86,   259,
     155,   256,    -1,   100,   259,   155,   256,    -1,    26,   259,
     155,   256,    -1,    25,   259,   155,   256,    -1,    -1,    91,
     454,   258,   459,   257,   256,    -1,    -1,   186,   456,   259,
     457,   256,    -1,   457,   260,   458,    -1,   458,    -1,   160,
      -1,   459,   460,    -1,   460,    -1,   461,    -1,   462,    -1,
     455,    -1,     1,    -1,   244,   259,   155,   256,    -1,   157,
     259,   155,   256,    -1,    -1,    36,   464,   258,   465,   257,
     256,    -1,   465,   466,    -1,   466,    -1,   467,    -1,   468,
      -1,     1,    -1,    90,   259,   155,   256,    -1,   157,   259,
     155,   256,    -1,    51,   258,   470,   257,   256,    -1,   470,
     471,    -1,   471,    -1,   472,    -1,     1,    -1,    90,   259,
     155,   256,    -1,    -1,    64,   474,   258,   479,   257,   256,
      -1,    -1,   186,   476,   259,   477,   256,    -1,   477,   260,
     478,    -1,   478,    -1,   160,    -1,   479,   480,    -1,   480,
      -1,   481,    -1,   482,    -1,   475,    -1,     1,    -1,   121,
     259,   155,   256,    -1,   157,   259,   155,   256,    -1,    65,
     258,   484,   257,   256,    -1,   484,   485,    -1,   485,    -1,
     493,    -1,   494,    -1,   496,    -1,   497,    -1,   498,    -1,
     499,    -1,   500,    -1,   501,    -1,   502,    -1,   503,    -1,
     492,    -1,   505,    -1,   506,    -1,   507,    -1,   508,    -1,
     523,    -1,   509,    -1,   511,    -1,   513,    -1,   512,    -1,
     516,    -1,   510,    -1,   517,    -1,   518,    -1,   519,    -1,
     520,    -1,   522,    -1,   521,    -1,   537,    -1,   524,    -1,
     528,    -1,   529,    -1,   533,    -1,   514,    -1,   515,    -1,
     543,    -1,   541,    -1,   542,    -1,   525,    -1,   495,    -1,
     526,    -1,   527,    -1,   544,    -1,   532,    -1,   504,    -1,
     545,    -1,   530,    -1,   531,    -1,   488,    -1,   491,    -1,
     486,    -1,   487,    -1,   489,    -1,   490,    -1,     1,    -1,
      71,   259,   132,   256,    -1,    72,   259,   132,   256,    -1,
      12,   259,   195,   256,    -1,   250,   259,   195,   256,    -1,
     162,   259,   265,   256,    -1,   183,   259,   195,   256,    -1,
      92,   259,   132,   256,    -1,    83,   259,   195,   256,    -1,
      88,   259,   195,   256,    -1,    42,   259,   195,   256,    -1,
      52,   259,   195,   256,    -1,     8,   259,   195,   256,    -1,
     113,   259,   265,   256,    -1,   112,   259,   132,   256,    -1,
     106,   259,   132,   256,    -1,     9,   259,   265,   256,    -1,
     199,   259,   265,   256,    -1,   198,   259,   265,   256,    -1,
      76,   259,   132,   256,    -1,    96,   259,   195,   256,    -1,
      95,   259,   155,   256,    -1,    89,   259,   195,   256,    -1,
     255,   259,   195,   256,    -1,   193,   259,   195,   256,    -1,
     194,   259,   195,   256,    -1,   192,   259,   195,   256,    -1,
     192,   259,   196,   256,    -1,   191,   259,   195,   256,    -1,
     191,   259,   196,   256,    -1,   147,   259,   265,   256,    -1,
      19,   259,   265,   256,    -1,   138,   259,   195,   256,    -1,
     148,   259,   265,   256,    -1,   187,   259,   195,   256,    -1,
     129,   259,   195,   256,    -1,   239,   259,   195,   256,    -1,
     141,   259,   195,   256,    -1,   116,   259,   155,   256,    -1,
      87,   259,   265,   256,    -1,    44,   259,   132,   256,    -1,
     115,   259,   132,   256,    -1,   181,   259,   155,   256,    -1,
      32,   259,   155,   256,    -1,    28,   259,   132,   256,    -1,
     245,   259,   195,   256,    -1,    46,   259,   155,   256,    -1,
     151,   259,   195,   256,    -1,    39,   259,   195,   256,    -1,
     237,   259,   265,   256,    -1,    -1,   143,   534,   259,   535,
     256,    -1,   535,   260,   536,    -1,   536,    -1,   202,    -1,
     205,    -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,
     225,    -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,
     226,    -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,
     204,    -1,   215,    -1,    -1,   140,   538,   259,   539,   256,
      -1,   539,   260,   540,    -1,   540,    -1,   202,    -1,   205,
      -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,
      -1,   227,    -1,   233,    -1,   230,    -1,   210,    -1,   226,
      -1,   228,    -1,   212,    -1,   236,    -1,   203,    -1,   204,
      -1,   215,    -1,   117,   259,   132,   256,    -1,   118,   259,
     132,   256,    -1,    33,   259,   132,   256,    -1,   206,   259,
     267,   256,    -1,    43,   259,   195,   256,    -1,    -1,    67,
     547,   258,   548,   257,   256,    -1,   548,   549,    -1,   549,
      -1,   550,    -1,   551,    -1,   552,    -1,   556,    -1,   557,
      -1,   558,    -1,     1,    -1,    48,   259,   195,   256,    -1,
      45,   259,   265,   256,    -1,    -1,   104,   553,   259,   554,
     256,    -1,   554,   260,   555,    -1,   555,    -1,   197,    -1,
      11,    -1,   244,   259,   155,   256,    -1,   121,   259,   155,
     256,    -1,    -1,     4,   559,   259,   560,   256,    -1,   560,
     260,   561,    -1,   561,    -1,   197,    -1,    11,    -1,    22,
     258,   563,   257,   256,    -1,   563,   564,    -1,   564,    -1,
     566,    -1,   567,    -1,   568,    -1,   569,    -1,   575,    -1,
     570,    -1,   571,    -1,   572,    -1,   573,    -1,   574,    -1,
     576,    -1,   577,    -1,   578,    -1,   565,    -1,   579,    -1,
     580,    -1,   581,    -1,   582,    -1,     1,    -1,   165,   259,
     195,   256,    -1,    41,   259,   195,   256,    -1,   246,   259,
     195,   256,    -1,   247,   259,   195,   256,    -1,   248,   259,
     195,   256,    -1,    97,   259,   265,   256,    -1,    98,   259,
     265,   256,    -1,   144,   259,   195,   256,    -1,   108,   259,
     132,   256,    -1,   156,   259,   195,   256,    -1,   107,   259,
     132,   256,    -1,    35,   259,   132,   256,    -1,    34,   259,
     132,   256,    -1,   127,   259,   195,   256,    -1,   128,   259,
     195,   256,    -1,    13,   259,   195,   256,    -1,   145,   259,
     132,   256,    -1,   146,   259,   265,   256,    -1,   179,   258,
     584,   257,   256,    -1,   584,   585,    -1,   585,    -1,   586,
      -1,   587,    -1,   589,    -1,   591,    -1,   590,    -1,   588,
      -1,   592,    -1,     1,    -1,    55,   259,   195,   256,    -1,
      82,   259,   195,   256,    -1,    79,   259,   155,   256,    -1,
     101,   259,   265,   256,    -1,    77,   259,   195,   256,    -1,
      40,   259,   195,   256,    -1,    81,   259,   195,   256,    -1
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
     504,   504,   505,   507,   541,   601,   615,   633,   642,   656,
     665,   693,   723,   746,   796,   798,   798,   799,   799,   800,
     800,   802,   811,   820,   833,   835,   836,   838,   838,   839,
     840,   840,   841,   841,   842,   842,   843,   843,   844,   845,
     847,   851,   855,   862,   869,   876,   883,   890,   897,   904,
     911,   915,   919,   923,   927,   931,   935,   941,   951,   950,
    1044,  1044,  1045,  1045,  1046,  1046,  1046,  1046,  1047,  1047,
    1048,  1048,  1048,  1049,  1049,  1049,  1050,  1050,  1050,  1051,
    1051,  1051,  1051,  1052,  1052,  1053,  1053,  1055,  1067,  1079,
    1098,  1110,  1121,  1163,  1173,  1172,  1177,  1177,  1178,  1181,
    1184,  1187,  1190,  1193,  1196,  1199,  1202,  1205,  1208,  1211,
    1214,  1217,  1220,  1223,  1226,  1229,  1234,  1245,  1256,  1267,
    1278,  1289,  1300,  1311,  1322,  1333,  1344,  1355,  1366,  1377,
    1389,  1388,  1392,  1392,  1393,  1394,  1396,  1403,  1410,  1417,
    1424,  1431,  1438,  1445,  1452,  1459,  1466,  1473,  1480,  1487,
    1494,  1501,  1515,  1514,  1556,  1556,  1558,  1558,  1559,  1560,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1573,  1582,  1591,  1597,  1603,  1609,  1615,  1621,
    1627,  1633,  1639,  1645,  1651,  1657,  1667,  1666,  1683,  1682,
    1686,  1686,  1687,  1691,  1697,  1697,  1698,  1698,  1698,  1698,
    1698,  1700,  1702,  1702,  1704,  1719,  1741,  1750,  1763,  1762,
    1831,  1831,  1832,  1832,  1832,  1832,  1833,  1833,  1834,  1834,
    1834,  1835,  1835,  1836,  1836,  1836,  1837,  1837,  1837,  1839,
    1858,  1871,  1882,  1891,  1903,  1902,  1906,  1906,  1907,  1908,
    1910,  1918,  1925,  1932,  1939,  1946,  1953,  1960,  1967,  1974,
    1983,  1994,  2005,  2016,  2027,  2038,  2050,  2069,  2079,  2088,
    2104,  2103,  2119,  2119,  2120,  2120,  2120,  2120,  2122,  2131,
    2146,  2160,  2159,  2175,  2175,  2176,  2176,  2176,  2176,  2178,
    2187,  2196,  2195,  2201,  2201,  2202,  2206,  2210,  2214,  2218,
    2222,  2226,  2230,  2234,  2238,  2242,  2252,  2251,  2268,  2268,
    2269,  2269,  2269,  2271,  2278,  2277,  2283,  2283,  2284,  2288,
    2292,  2296,  2300,  2304,  2308,  2312,  2316,  2320,  2324,  2334,
    2333,  2483,  2483,  2484,  2484,  2485,  2485,  2485,  2486,  2486,
    2487,  2487,  2488,  2488,  2488,  2489,  2489,  2489,  2490,  2490,
    2490,  2491,  2491,  2492,  2494,  2506,  2518,  2527,  2553,  2571,
    2589,  2595,  2599,  2607,  2617,  2616,  2620,  2620,  2621,  2622,
    2624,  2631,  2642,  2649,  2656,  2663,  2673,  2714,  2725,  2736,
    2751,  2762,  2775,  2788,  2797,  2833,  2832,  2894,  2893,  2897,
    2897,  2898,  2904,  2904,  2905,  2905,  2905,  2905,  2907,  2923,
    2933,  2932,  2954,  2954,  2955,  2955,  2955,  2957,  2966,  2978,
    2980,  2980,  2981,  2981,  2983,  3005,  3004,  3046,  3045,  3049,
    3049,  3050,  3056,  3056,  3057,  3057,  3057,  3057,  3059,  3065,
    3074,  3077,  3077,  3078,  3078,  3079,  3079,  3080,  3080,  3081,
    3081,  3082,  3082,  3083,  3083,  3084,  3084,  3085,  3085,  3086,
    3086,  3087,  3087,  3088,  3088,  3089,  3089,  3090,  3090,  3091,
    3091,  3092,  3092,  3093,  3093,  3094,  3094,  3095,  3095,  3096,
    3096,  3097,  3097,  3098,  3099,  3099,  3100,  3100,  3101,  3101,
    3102,  3102,  3103,  3103,  3104,  3104,  3105,  3106,  3110,  3115,
    3120,  3125,  3130,  3135,  3140,  3145,  3150,  3155,  3160,  3165,
    3170,  3175,  3180,  3185,  3190,  3195,  3201,  3212,  3217,  3226,
    3231,  3236,  3241,  3246,  3249,  3254,  3257,  3262,  3267,  3272,
    3277,  3282,  3287,  3292,  3297,  3302,  3313,  3318,  3323,  3328,
    3337,  3369,  3387,  3392,  3401,  3406,  3411,  3417,  3416,  3421,
    3421,  3422,  3425,  3428,  3431,  3434,  3437,  3440,  3443,  3446,
    3449,  3452,  3455,  3458,  3461,  3464,  3467,  3470,  3473,  3479,
    3478,  3483,  3483,  3484,  3487,  3490,  3493,  3496,  3499,  3502,
    3505,  3508,  3511,  3514,  3517,  3520,  3523,  3526,  3529,  3532,
    3535,  3540,  3545,  3550,  3555,  3560,  3569,  3568,  3594,  3594,
    3595,  3596,  3597,  3598,  3599,  3600,  3601,  3603,  3609,  3616,
    3615,  3620,  3620,  3621,  3625,  3631,  3650,  3660,  3659,  3702,
    3702,  3703,  3707,  3716,  3719,  3719,  3720,  3720,  3721,  3721,
    3722,  3722,  3723,  3723,  3724,  3724,  3725,  3726,  3727,  3727,
    3728,  3728,  3729,  3729,  3730,  3732,  3737,  3742,  3747,  3752,
    3757,  3762,  3767,  3772,  3777,  3782,  3787,  3792,  3797,  3802,
    3807,  3812,  3817,  3825,  3828,  3828,  3829,  3829,  3830,  3831,
    3832,  3832,  3833,  3834,  3836,  3842,  3848,  3857,  3871,  3877,
    3883
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
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
  "INVITE_OPS_ONLY", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT",
  "REDIRSERV", "REGEX_T", "REHASH", "TREJECT_HOLD_TIME", "REMOTE",
  "REMOTEBAN", "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE", "T_EXTERNAL", "T_FULL",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOGPATH", "T_L_CRIT",
  "T_L_DEBUG", "T_L_ERROR", "T_L_INFO", "T_L_NOTICE", "T_L_TRACE",
  "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
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
  "oper_flags_item", "oper_flags_item_atom", "class_entry", "@4",
  "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "@5", "listen_flags", "@6",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@7", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@8", "auth_flags_items",
  "auth_flags_item", "auth_flags_item_atom", "auth_kline_exempt",
  "auth_need_ident", "auth_exceed_limit", "auth_can_flood",
  "auth_no_tilde", "auth_gline_exempt", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "auth_need_password", "resv_entry", "@9",
  "resv_items", "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "shared_entry", "@10", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "@11", "shared_types", "shared_type_item",
  "cluster_entry", "@12", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "@13", "cluster_types", "cluster_type_item",
  "connect_entry", "@14", "connect_name_b", "connect_items",
  "connect_item", "connect_name", "connect_name_t", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_fakename", "connect_flags",
  "@15", "connect_flags_items", "connect_flags_item",
  "connect_flags_item_atom", "connect_rsa_public_key_file",
  "connect_encrypted", "connect_cryptlink", "connect_compressed",
  "connect_auto", "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "@16", "kill_type", "@17",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "@18", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "@19", "gecos_flags", "@20",
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
  "general_warn_no_nline", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_message_locale", "general_idletime",
  "general_dots_in_ident", "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@21", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@22",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@23",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@24", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@25", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_invite_ops_only", "channel_max_chans_per_user",
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
     339,   338,   340,   340,   341,   341,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   344,   343,   345,   345,   346,   346,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   363,   362,   365,   364,
     366,   366,   367,   367,   368,   368,   369,   369,   369,   369,
     369,   370,   371,   371,   372,   372,   373,   374,   376,   375,
     377,   377,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   378,   379,
     380,   381,   382,   383,   385,   384,   386,   386,   387,   387,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     400,   399,   401,   401,   402,   402,   402,   402,   403,   404,
     405,   407,   406,   408,   408,   409,   409,   409,   409,   410,
     411,   413,   412,   414,   414,   415,   415,   415,   415,   415,
     415,   415,   415,   415,   415,   415,   417,   416,   418,   418,
     419,   419,   419,   420,   422,   421,   423,   423,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   426,
     425,   427,   427,   428,   428,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   437,   438,   440,   439,   441,   441,   442,   442,
     443,   443,   443,   443,   443,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   454,   453,   456,   455,   457,
     457,   458,   459,   459,   460,   460,   460,   460,   461,   462,
     464,   463,   465,   465,   466,   466,   466,   467,   468,   469,
     470,   470,   471,   471,   472,   474,   473,   476,   475,   477,
     477,   478,   479,   479,   480,   480,   480,   480,   481,   482,
     483,   484,   484,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   511,   512,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   534,   533,   535,
     535,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   538,
     537,   539,   539,   540,   540,   540,   540,   540,   540,   540,
     540,   540,   540,   540,   540,   540,   540,   540,   540,   540,
     540,   541,   542,   543,   544,   545,   547,   546,   548,   548,
     549,   549,   549,   549,   549,   549,   549,   550,   551,   553,
     552,   554,   554,   555,   555,   556,   557,   559,   558,   560,
     560,   561,   561,   562,   563,   563,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   564,   564,   564,   564,   564,
     564,   564,   564,   564,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   584,   585,   585,   585,   585,
     585,   585,   585,   585,   586,   587,   588,   589,   590,   591,
     592
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
       0,     5,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     7,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     6,     0,     5,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     4,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
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
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     0,     6,     2,     1,
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,     0,   212,   379,   450,     0,
     465,     0,   636,   268,   435,   246,     0,     0,   118,   320,
       0,     0,   331,   356,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   214,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   684,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   665,   679,   666,   667,
     668,   669,   671,   672,   673,   674,   675,   670,   676,   677,
     678,   680,   681,   682,   683,   233,     0,   215,   405,     0,
     382,     0,   463,     0,     0,   461,   462,     0,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   609,     0,   587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   482,   533,   534,   531,   535,   536,
     532,   493,   483,   484,   522,   485,   486,   487,   488,   489,
     490,   491,   492,   527,   494,   495,   496,   497,   499,   504,
     500,   502,   501,   516,   517,   503,   505,   506,   507,   508,
     510,   509,   498,   512,   521,   523,   524,   513,   514,   529,
     530,   526,   515,   511,   519,   520,   518,   525,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      91,    98,    92,    96,    93,    94,    97,    95,    89,    90,
       0,     0,     0,     0,    42,    43,    44,   148,     0,   121,
       0,   713,     0,     0,     0,     0,     0,     0,     0,     0,
     705,   706,   707,   711,   708,   710,   709,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    61,    58,    51,    60,    54,    55,    56,    52,
      59,    57,    53,     0,     0,    80,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     664,     0,     0,   456,     0,     0,     0,   453,   454,   455,
       0,     0,   460,   477,     0,     0,   467,   476,     0,   473,
     474,   475,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   481,   646,   657,
       0,     0,   649,     0,     0,     0,   639,   640,   641,   642,
     643,   644,   645,     0,     0,     0,     0,     0,   294,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   272,   273,   282,   274,   287,   275,   276,   277,
     278,   285,   279,   280,   281,   283,   284,   286,   447,     0,
     437,     0,   446,     0,   443,   444,   445,     0,   248,     0,
       0,     0,   257,     0,   255,   256,   258,   259,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    45,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   323,   324,   325,   326,     0,     0,
       0,     0,     0,     0,     0,     0,   704,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   341,     0,     0,   334,   335,   336,   337,
       0,     0,   364,     0,   359,   360,   361,     0,     0,     0,
      74,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     663,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,   218,   221,   222,
     224,   225,   226,   227,   228,   229,   230,   219,   220,   223,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     414,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,   385,   386,   387,   388,   389,   391,   390,   392,   393,
     401,   398,   400,   399,   397,   394,   395,   396,   402,     0,
       0,     0,   452,     0,   459,     0,     0,     0,     0,   472,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,     0,   638,   288,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,   442,
     260,     0,     0,     0,     0,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    40,     0,
       0,     0,     0,     0,   190,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
       0,     0,     0,   123,   124,   125,   126,   143,   144,   130,
     129,   131,   132,   138,   133,   134,   135,   136,   137,   139,
     140,   141,   127,   128,   142,   145,   327,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,   703,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   338,     0,     0,     0,     0,   333,   362,     0,
       0,     0,   358,    83,    82,    81,   700,   697,   696,   686,
      26,    26,    26,    26,    26,    28,    27,   690,   691,   695,
     693,   698,   699,   692,   701,   702,   694,   685,   687,   688,
     689,   231,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   383,     0,     0,
     451,   464,     0,     0,     0,   466,   549,   553,   540,   568,
     581,   580,   633,   585,   547,   635,   577,   583,   548,   538,
     539,   556,   545,   576,   546,   559,   544,   558,   557,   552,
     551,   550,   578,   575,   631,   632,   572,   569,   613,   628,
     629,   614,   615,   616,   623,   617,   626,   630,   619,   624,
     620,   625,   618,   622,   621,   627,     0,   612,   574,   591,
     606,   607,   592,   593,   594,   601,   595,   604,   608,   597,
     602,   598,   603,   596,   600,   599,   605,     0,   590,   567,
     570,   584,   542,   579,   543,   571,   565,   566,   563,   564,
     561,   562,   555,   554,    34,    34,    34,    36,    35,   634,
     586,   573,   582,   541,   560,     0,     0,     0,     0,     0,
       0,   637,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,     0,
       0,     0,   436,     0,     0,     0,   264,     0,   263,   247,
     103,   109,   107,   106,   108,   104,   105,   102,   110,   116,
     111,   115,   113,   114,   112,   101,   100,   117,    46,    47,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,     0,     0,     0,   321,   719,
     714,   718,   716,   720,   715,   717,    67,    73,    65,    69,
      68,    64,    63,    66,    72,    70,    71,     0,     0,     0,
     332,     0,     0,   357,    29,    30,    31,    32,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   380,   457,   458,   478,   479,   471,     0,   470,
     610,     0,   588,     0,    37,    38,    39,   662,   661,     0,
     660,   648,   647,   654,   653,     0,   652,   656,   655,   313,
     292,   293,   312,   304,   305,   301,   307,   303,   302,   309,
     306,     0,   308,   300,     0,   297,   299,   315,   311,   310,
     319,   314,   290,   318,   317,   316,   291,   289,   449,   441,
       0,   440,   448,   253,   252,     0,   251,   267,   266,     0,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   329,   330,   328,   339,   345,
     351,   355,   354,   353,   350,   346,   349,   352,   347,   348,
       0,   344,   340,   363,   368,   374,   378,   377,   376,   373,
     369,   372,   375,   370,   371,     0,   367,   243,   244,   237,
     239,   241,   240,   238,   232,   245,   236,   234,   235,   242,
     409,   411,   412,   430,   434,   433,   429,   428,   427,   413,
     423,   424,   421,   422,   420,     0,   425,     0,   417,   419,
     406,   431,   432,   404,   410,   426,   408,   407,   468,     0,
     611,   589,   658,     0,   650,     0,   298,   295,     0,   438,
       0,   249,     0,   265,   262,   186,   153,   184,   151,   204,
     202,   211,   201,   196,   205,   209,   198,   206,     0,   208,
     203,   197,   210,   207,   199,   200,     0,   193,   195,   182,
     176,   187,   188,   179,   147,   183,   150,   185,   177,   178,
     152,   189,   158,   173,   174,   159,   160,   161,   168,   162,
     171,   175,   164,   169,   165,   170,   163,   167,   166,   172,
       0,   157,   181,   149,   180,   342,     0,   365,     0,   418,
     415,     0,   469,   659,   651,   296,   439,   250,   194,   191,
       0,   155,     0,   343,   366,   416,   192,   156
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    24,   885,   886,  1037,  1038,    25,   273,   274,
     275,   276,    26,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    27,    71,    72,    73,
      74,    75,    28,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    29,    61,   278,
     812,   813,   814,   279,   815,   816,   817,   818,   819,   820,
    1119,  1430,  1431,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   830,   831,   832,   833,   834,   835,  1105,  1396,
    1397,  1398,    30,    49,   116,   605,   606,   607,   117,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,    31,    58,   492,   761,  1255,  1256,   493,   494,   495,
    1077,  1078,   496,   497,    32,    56,   460,   461,   462,   463,
     464,   465,   466,   467,   741,  1234,  1235,  1236,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,    33,    62,
     523,   524,   525,   526,   527,    34,    65,   555,   556,   557,
     558,   559,   864,  1300,  1301,    35,    66,   563,   564,   565,
     566,   870,  1315,  1316,    36,    50,   119,   639,   640,   641,
     120,   642,   643,   644,   645,   646,   647,   648,   649,   927,
    1347,  1348,  1349,   650,   651,   652,   653,   654,   655,   656,
     657,   658,    37,    57,   482,   756,  1250,  1251,   483,   484,
     485,   486,    38,    51,   356,   357,   358,   359,    39,   124,
     125,   126,    40,    53,   367,   667,  1198,  1199,   368,   369,
     370,   371,    41,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   406,  1017,  1018,   233,   404,   996,   997,
     234,   235,   236,   237,   238,    42,    55,   435,   436,   437,
     438,   439,   731,  1215,  1216,   440,   441,   442,   728,  1209,
    1210,    43,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   289,   290,   291,   292,   293,   294,   295,
     296,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -823
static const short int yypact[] =
{
    -823,   887,  -823,  -213,  -255,  -249,  -823,  -823,  -823,  -244,
    -823,  -238,  -823,  -823,  -823,  -823,  -233,  -223,  -823,  -823,
    -208,  -202,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,    22,   783,   -97,
     -84,  -179,    12,  -171,   513,  -155,  -150,  -135,  -129,   398,
      15,   -16,  -112,   350,   549,  -107,  -105,   -89,   -87,   -85,
     -55,    10,  -823,  -823,  -823,  -823,  -823,   -53,   -37,   -35,
     -31,   -30,   -24,   -18,   -14,   -12,    -8,    -6,     2,    24,
      42,    48,    52,    59,    82,   135,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   -74,  -823,  -823,    -3,
    -823,    30,  -823,    85,     3,  -823,  -823,    23,  -823,    86,
      87,    88,    96,   101,   102,   103,   104,   112,   114,   116,
     119,   125,   132,   139,   144,   145,   149,   150,   153,   155,
     158,   159,   160,   163,   165,   166,   169,   171,   174,   177,
     178,  -823,   182,  -823,   183,   185,   186,   187,   189,   203,
     210,   213,   214,   216,   218,   220,   221,   224,   225,   226,
     227,   229,   230,     9,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   248,
     814,    64,   269,    13,   231,   232,   234,   235,   236,   238,
     239,   240,   242,   243,   245,   246,   271,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
      18,   249,   250,    14,  -823,  -823,  -823,  -823,    80,  -823,
       5,  -823,   251,   252,   253,   254,   256,   257,   258,   334,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   121,   259,
     260,   265,   268,   274,   275,   276,   277,   279,   280,   281,
     219,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,   106,   136,  -823,   294,   323,   326,   288,
    -823,   335,   399,   410,   352,   416,   416,   417,   419,   358,
     363,   365,   429,   416,   369,   371,   373,   377,   378,   314,
    -823,   721,   683,  -823,   315,   316,    29,  -823,  -823,  -823,
     421,   324,  -823,  -823,   320,   322,  -823,  -823,    11,  -823,
    -823,  -823,   387,   416,   388,   416,   455,   433,   458,   400,
     402,   403,   461,   439,   404,   474,   475,   478,   422,   416,
     423,   426,   479,   457,   428,   484,   492,   416,   495,   480,
     501,   504,   442,   443,   381,   446,   384,   416,   416,   450,
     416,   493,   454,   460,  -119,   118,   462,   463,   416,   416,
     518,   416,   467,   468,   470,   471,   396,  -823,  -823,  -823,
     408,   409,  -823,   412,   415,   113,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,   413,   424,   431,   436,   438,  -823,   440,
     444,   464,   465,   466,   469,   476,   481,   482,   487,   488,
     190,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   489,
    -823,   490,  -823,    32,  -823,  -823,  -823,   435,  -823,   496,
     497,   498,  -823,    28,  -823,  -823,  -823,  -823,  -823,   530,
     533,   543,   546,   547,   558,   562,   571,   459,   578,   584,
     526,   503,  -823,  -823,   599,   605,   505,  -823,   566,   506,
     507,   511,   515,    38,  -823,  -823,  -823,  -823,   570,   580,
     581,   622,   583,   585,   416,   523,  -823,  -823,   630,   591,
     632,   634,   636,   639,   647,   648,   673,   652,   657,   564,
    -823,   565,   555,  -823,   563,    33,  -823,  -823,  -823,  -823,
     567,   568,  -823,    45,  -823,  -823,  -823,   569,   572,   573,
    -823,   577,   582,   587,   589,   192,   592,   593,   594,   597,
     598,   602,   604,   606,   609,   610,   611,   613,   614,   615,
    -823,   621,   588,   624,   625,   626,   627,   640,   641,   642,
     643,   644,   646,   655,   656,   286,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     650,   658,   659,   660,   661,   662,   663,   665,   666,   667,
    -823,   671,   672,   674,   676,   678,   681,   684,   686,   272,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   740,
     752,   690,  -823,   691,  -823,   777,   787,   694,   699,  -823,
     700,   701,   704,   706,   708,   709,   710,   711,   713,   714,
     718,   719,   723,   726,   727,   728,   729,   731,   732,   734,
     736,   737,   739,   741,   742,   743,   744,   745,   746,   749,
     750,   753,   871,   754,   906,   755,   759,   760,   761,   762,
     767,   769,   771,   772,   778,   780,   781,   782,   784,   785,
     222,   786,   788,   791,   792,   793,   794,  -823,   712,   416,
     801,   774,   795,   822,   799,  -823,  -823,   813,   880,   844,
     848,   797,   864,   865,   866,   867,   868,   910,   707,   913,
     914,   875,   922,   824,  -823,   929,   826,   932,   832,  -823,
    -823,   830,   935,   936,   960,   837,  -823,   838,   839,   846,
     847,   849,   850,   856,   859,   863,   869,   870,   872,   873,
     874,   881,   882,   884,   885,  -823,   891,   894,  -823,   898,
     861,   896,   899,   900,  -823,   901,   902,   903,   904,   905,
     916,   917,   919,   920,   921,   923,   924,   925,  -823,   926,
     927,   928,    62,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   967,   968,   969,
     909,  -823,   933,   934,   937,   938,   939,   940,   942,  -823,
     943,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,  -823,  -823,   972,   954,  1002,   955,  -823,  -823,  1017,
     956,   958,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     416,   416,   416,   416,   416,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  1041,  1049,   416,  1056,  1059,  1060,  1065,  1055,
    1080,  1084,   416,   416,   518,   961,  -823,  -823,  1063,   123,
    1024,  1066,  1067,  1025,  1028,  1029,  1070,   970,  1071,  1072,
    1073,  1075,  1099,  1077,  1078,  1079,   979,  -823,   980,   981,
    -823,  -823,   982,   983,  1081,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -234,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -224,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,   518,   518,   518,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,    -4,   984,   986,     8,   987,
     988,  -823,   989,   990,   991,   992,   432,   993,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1003,  1004,  -823,  1005,
    1098,  1006,  -823,   -72,  1007,  1008,  1068,  -211,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  1074,  1110,  1076,  1082,  1011,  1083,  1085,  1086,  1087,
    1088,  1111,  1089,  1112,  1090,  1091,  1092,  1117,  1093,  1014,
    1094,  1119,  1095,  1019,  -823,  1020,  1023,  1035,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  1036,   779,  1037,
    -823,  1038,   811,  -823,  -823,  -823,  -823,  -823,  -823,  1039,
    1040,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1050,  1051,
    1052,  1053,  -823,  1054,  1057,  1058,  1061,  1062,  1064,  1069,
    1096,  1097,  1100,   375,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  -823,  -823,  -823,  -823,  -823,  -823,  -192,  -823,
    -823,   871,  -823,   906,  -823,  -823,  -823,  -823,  -823,  -190,
    -823,  -823,  -823,  -823,  -823,  -182,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   722,  -823,  -823,  -166,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -161,  -823,  -823,  -823,  -823,  -147,  -823,  -823,  -823,  1165,
    -823,   960,  1109,  1113,  1114,  1115,   715,  1116,  1118,  1120,
    1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,
     941,  1131,  1132,  1133,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -115,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   -83,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,    79,  -823,   -81,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  1081,
    -823,  -823,  -823,    -4,  -823,     8,  -823,  -823,   432,  -823,
    1098,  -823,   -72,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   733,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   -75,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     -62,  -823,  -823,  -823,  -823,  -823,   779,  -823,   811,  -823,
    -823,   375,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
     715,  -823,   941,  -823,  -823,  -823,  -823,  -823
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -823,  -823,  -823,  -416,  -335,  -822,  -418,  -823,  -823,  1032,
    -823,  -823,  -823,  -823,  1009,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   765,  -823,
    -823,  -823,  -823,  -823,  1134,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   499,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -140,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -134,   -73,  -823,  -823,  -823,  -823,   716,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   -50,  -823,   831,  -823,
    -823,    65,  -823,  -823,  -823,  -823,  -823,   876,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,   -45,    97,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,   804,  -823,  -823,  -823,  -823,  -823,  -823,   775,  -823,
    -823,  -823,  -823,  -823,  -104,  -823,  -823,  -823,   766,  -823,
    -823,  -823,  -823,  -103,  -823,  -823,  -823,  -823,   692,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -108,   -11,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,   -33,  -823,   855,
    -823,  -823,  -823,  -823,  -823,   985,  -823,  -823,  -823,  -823,
    1215,  -823,  -823,  -823,  -823,  -823,  -823,   -19,  -823,   974,
    -823,  -823,  -823,  -823,  1160,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,   141,  -823,  -823,  -823,   146,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,   911,  -823,
    -823,  -823,  -823,  -823,   -20,  -823,  -823,  -823,  -823,  -823,
     -15,  -823,  -823,  1254,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,  -823,
    -823,  -823,  -823,  -823,  1135,  -823,  -823,  -823,  -823,  -823,
    -823,  -823
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     576,   577,   721,    47,   122,  1253,   519,  1207,   584,    48,
     128,    67,   363,   122,    52,   270,   270,   129,   130,  1213,
      54,   131,  1200,    67,   363,    59,  1201,   520,   132,   487,
     353,   353,  1202,   478,   551,    60,  1203,   133,   671,   519,
     673,   134,   135,    45,    46,  1260,   560,    68,   136,  1261,
      63,   137,   138,   139,   687,   140,    64,    69,   115,    68,
     520,   141,   695,   789,  1358,   478,  1362,   790,  1359,    69,
    1363,   118,   705,   706,  1364,   708,   712,   713,  1365,   121,
     142,   143,   488,   718,   719,   144,   722,   127,   791,  1340,
    1367,  1341,   145,   123,  1368,  1369,   146,   147,   148,  1370,
     792,   149,   123,   239,   150,   151,  1342,   551,   240,  1371,
    1343,   793,   489,  1372,   428,   152,   794,   429,   490,   354,
     354,   153,   154,   241,   155,   156,   157,   158,   795,   242,
     521,    70,   364,   271,   271,   796,    76,   560,   159,   277,
     797,  1435,   798,    70,   364,  1436,   280,   160,    77,   161,
     162,   323,   163,   324,   552,   799,   164,   165,   430,  1254,
     166,   431,   522,   521,   272,   272,   561,   325,   365,    78,
      79,   167,   326,  1437,   327,  1440,    80,  1438,  1344,  1441,
     365,  1449,   491,   800,   351,  1450,   355,   355,   801,   479,
     168,   443,   169,  1208,  1451,   522,   170,   366,  1452,   848,
     171,   172,   173,   174,   328,  1214,   331,   175,   176,   366,
     444,   802,  1204,  1205,  1206,   177,   445,   432,   480,   553,
     298,   479,   332,   803,   333,   804,   805,   552,   334,   335,
     806,   562,    81,    82,   433,   336,  1034,  1035,  1036,   446,
     447,   337,    83,    84,   448,   338,   178,   339,   179,   428,
     480,   340,   429,   341,   180,   352,   299,   561,   449,   181,
     361,   342,    85,    86,   182,   450,   426,   329,   668,   498,
     487,   516,   243,   620,   513,   621,   481,   554,   622,    87,
      88,    89,   623,   343,   451,   765,   661,   591,   807,   758,
     866,    90,   553,   430,   808,   840,   431,   624,   625,   626,
      91,   344,   871,   627,   300,   809,   810,   345,   481,   592,
     593,   346,   452,   714,   715,   811,   594,  1346,   347,  1123,
     453,   628,   562,   488,   575,   629,   630,   244,   245,   246,
     247,   248,   249,   250,   251,   281,  1174,  1175,   518,   454,
     301,   348,   302,   303,   360,   372,   373,   374,   455,   456,
     554,   281,   432,   489,   720,   375,   631,   434,   632,   490,
     376,   377,   378,   379,   880,   881,   882,   883,   884,   433,
     734,   380,   633,   381,   282,   382,   252,   537,   383,   457,
     458,    92,    93,    94,   384,  1340,   304,  1341,   305,   283,
     282,   385,   349,   634,  1046,   595,   596,   597,   386,   243,
     598,   306,  1342,   387,   388,   283,  1343,   599,   389,   390,
     253,   284,   391,   285,   392,   286,   287,   393,   394,   395,
     600,   601,   396,   491,   397,   398,   635,   284,   399,   285,
     400,   286,   287,   401,   459,   288,   402,   403,   602,   603,
     636,   405,   407,   307,   408,   409,   410,   753,   411,   567,
     637,   288,  1223,  1224,   244,   245,   246,   247,   248,   249,
     250,   251,   412,   604,  1154,  1155,  1156,  1157,  1158,   413,
     308,   309,   414,   415,  1344,   416,   549,   417,   568,   418,
     419,   569,  1225,   420,   421,   422,   423,   254,   424,   425,
     499,   500,   434,   501,   502,   503,  1171,   504,   505,   506,
    1226,   507,   508,   252,   509,   510,  1345,  1227,   514,   515,
     528,   529,   530,   531,   128,   532,   533,   534,   538,   539,
     255,   129,   130,   638,   540,   131,  1228,   541,   511,   936,
     571,   572,   132,   542,   543,   544,   545,   253,   546,   547,
     548,   133,   573,   915,   570,   134,   135,   574,   575,   578,
     298,   579,   136,   580,  1229,   137,   138,   139,   581,   140,
     582,   583,  1230,  1231,   585,   141,   586,   789,   587,  1161,
     590,   790,   588,   589,   659,   660,   663,  1169,  1170,   665,
     664,   666,   670,   672,   142,   143,   299,   674,   675,   144,
     676,   535,   791,   680,   681,   677,   145,   678,   679,   682,
     146,   147,   148,  1232,   792,   149,   683,   684,   150,   151,
     685,   690,   691,  1346,   254,   793,   693,   686,   688,   152,
     794,   689,  1233,   692,   694,   153,   154,   696,   155,   156,
     157,   158,   795,   698,   300,   697,   699,   700,   701,   796,
     702,   703,   159,   704,   797,   707,   798,   255,   709,   710,
     720,   160,   727,   161,   162,   711,   163,   716,   717,   799,
     164,   165,   723,   724,   166,   725,   726,   729,   730,   736,
     301,   732,   302,   303,   733,   167,   775,   776,   777,   778,
     779,   780,   781,   737,   620,   767,   621,   800,   768,   622,
     738,   760,   801,   623,   168,   739,   169,   740,   769,   742,
     170,   770,   771,   743,   171,   172,   173,   174,   624,   625,
     626,   175,   176,   772,   627,   802,   304,   773,   305,   177,
    1379,   784,   591,   744,   745,   746,   774,   803,   747,   804,
     805,   306,   628,   782,   806,   748,   629,   630,  1379,   783,
     749,   750,  1223,  1224,   592,   593,   751,   752,   755,   757,
     178,   594,   179,  1380,   786,   762,   763,   764,   180,   785,
     787,   788,   836,   181,  1381,   842,   837,   631,   182,   632,
     838,  1380,  1225,   307,   839,   843,   844,   845,   846,   849,
     847,  1382,  1381,   633,    76,   850,   851,   852,  1383,   853,
    1226,   854,   807,  1384,   855,  1385,    77,  1227,   808,  1382,
     308,   309,   856,   857,   634,   858,  1383,   859,  1386,   809,
     810,  1384,   860,  1385,   863,   443,  1228,    78,    79,   811,
     861,   862,   865,   868,    80,   873,  1386,   869,   874,   875,
     595,   596,   597,   876,   444,   598,   330,   635,   877,  1063,
     445,  1387,   599,   878,  1229,   879,  1388,   902,   887,   888,
     889,   636,  1230,   890,   891,   600,   601,  1389,   892,  1387,
     893,   637,   894,   446,   447,   895,   896,   897,   448,   898,
     899,   900,  1289,   602,   603,  1389,  1390,   901,  1391,  1392,
      81,    82,   449,   903,   904,   905,   906,     2,     3,   450,
      83,    84,     4,  1232,  1390,   938,  1391,  1392,   604,   907,
     908,   909,   910,   911,  1304,   912,   917,   939,   451,     5,
      85,    86,  1233,     6,   913,   914,     7,   918,   919,   920,
     921,   922,   923,     8,   924,   925,   926,    87,    88,    89,
     928,   929,   942,   930,   638,   931,   452,   932,     9,    90,
     933,  1393,   943,   934,   453,   935,   940,   941,    91,  1290,
    1049,    10,    11,   944,    12,   945,   946,   947,  1394,  1393,
     948,    13,   949,   454,   950,   951,   952,   953,  1395,   954,
     955,  1045,   455,   456,   956,   957,  1394,  1050,    14,   958,
    1291,  1305,   959,   960,   961,   962,  1395,   963,   964,    15,
     965,    16,   966,   967,  1292,   968,  1047,   969,   970,   971,
     972,   973,   974,   457,   458,   975,   976,    17,  1052,   977,
     998,  1019,  1306,  1293,  1294,  1020,  1021,  1022,  1023,  1295,
    1296,  1297,  1298,  1024,    18,  1025,  1307,  1026,  1027,    92,
      93,    94,  1299,  1048,  1028,  1053,  1029,  1030,  1031,  1054,
    1032,  1033,  1039,  1055,  1040,  1308,  1309,  1041,  1042,  1043,
    1044,  1310,  1311,  1312,  1313,  1051,  1056,    19,   459,  1057,
    1058,  1059,  1060,  1061,  1314,  1062,    20,    21,  1064,  1065,
    1066,    22,    23,   978,   979,   980,   981,  1067,   982,   983,
    1068,   984,   985,   986,  1069,  1070,   987,  1071,  1072,  1073,
    1074,  1075,  1076,  1079,  1080,  1081,   988,   989,   990,   991,
     992,   993,  1082,  1083,   994,  1084,  1085,   995,   999,  1000,
    1001,  1002,  1086,  1003,  1004,  1087,  1005,  1006,  1007,  1088,
    1101,  1008,  1125,  1126,  1127,  1089,  1090,  1147,  1091,  1092,
    1093,  1009,  1010,  1011,  1012,  1013,  1014,  1094,  1095,  1015,
    1096,  1097,  1016,  1412,  1413,  1414,  1415,  1098,  1416,  1417,
    1099,  1418,  1419,  1420,  1100,  1102,  1421,  1149,  1103,  1104,
    1106,  1107,  1108,  1109,  1110,  1128,  1422,  1423,  1424,  1425,
    1426,  1427,  1151,  1159,  1428,  1111,  1112,  1429,  1113,  1114,
    1115,  1160,  1116,  1117,  1118,  1120,  1121,  1122,  1162,  1129,
    1130,  1163,  1164,  1131,  1132,  1133,  1134,  1165,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1166,  1150,  1167,  1148,  1153,  1152,  1168,  1172,  1173,  1176,
    1179,  1177,  1178,  1180,  1181,  1182,  1184,  1185,  1186,  1183,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1211,  1197,  1212,  1217,  1218,  1219,  1220,  1221,  1222,  1237,
    1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1249,  1246,
    1247,  1248,  1252,  1257,  1258,  1263,  1272,  1274,  1259,  1262,
    1266,  1264,  1278,  1280,  1282,  1284,  1285,  1265,  1267,  1286,
    1268,  1269,  1270,  1271,  1273,  1275,  1276,  1277,  1279,  1281,
    1283,  1287,  1288,  1302,  1303,  1317,  1318,  1373,  1319,  1320,
    1321,  1322,  1323,  1324,  1325,   517,  1326,  1327,  1328,  1329,
    1330,  1124,  1457,  1331,  1332,  1448,  1456,  1333,  1334,   550,
    1335,   916,  1447,  1445,   766,  1336,  1374,   841,  1366,   872,
     867,   937,  1453,  1455,  1439,  1454,   754,  1446,   759,   362,
    1442,   662,   669,   427,  1361,  1444,   735,  1360,  1443,   350,
       0,     0,  1337,  1338,     0,     0,  1339,  1350,  1351,  1352,
    1353,  1354,  1355,  1356,  1357,  1375,     0,     0,     0,  1376,
    1377,  1378,  1399,     0,  1400,     0,  1401,  1402,  1403,  1404,
    1405,  1406,  1407,  1408,  1409,  1410,  1411,  1432,  1433,  1434,
     512,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536
};

static const short int yycheck[] =
{
     335,   336,   420,   258,     1,    77,     1,    11,   343,   258,
       1,     1,     1,     1,   258,     1,     1,     8,     9,    11,
     258,    12,   256,     1,     1,   258,   260,    22,    19,     1,
       1,     1,   256,     1,     1,   258,   260,    28,   373,     1,
     375,    32,    33,   256,   257,   256,     1,    37,    39,   260,
     258,    42,    43,    44,   389,    46,   258,    47,   155,    37,
      22,    52,   397,     1,   256,     1,   256,     5,   260,    47,
     260,   155,   407,   408,   256,   410,   195,   196,   260,   258,
      71,    72,    54,   418,   419,    76,   421,   258,    26,    10,
     256,    12,    83,    90,   260,   256,    87,    88,    89,   260,
      38,    92,    90,   258,    95,    96,    27,     1,   258,   256,
      31,    49,    84,   260,     1,   106,    54,     4,    90,    90,
      90,   112,   113,   258,   115,   116,   117,   118,    66,   258,
     125,   121,   121,   119,   119,    73,     1,     1,   129,   155,
      78,   256,    80,   121,   121,   260,   258,   138,    13,   140,
     141,   258,   143,   258,   121,    93,   147,   148,    45,   231,
     151,    48,   157,   125,   150,   150,   121,   256,   157,    34,
      35,   162,   259,   256,   259,   256,    41,   260,    99,   260,
     157,   256,   154,   121,   258,   260,   157,   157,   126,   157,
     181,     1,   183,   197,   256,   157,   187,   186,   260,   534,
     191,   192,   193,   194,   259,   197,   259,   198,   199,   186,
      20,   149,  1034,  1035,  1036,   206,    26,   104,   186,   186,
       1,   157,   259,   161,   259,   163,   164,   121,   259,   259,
     168,   186,    97,    98,   121,   259,    14,    15,    16,    49,
      50,   259,   107,   108,    54,   259,   237,   259,   239,     1,
     186,   259,     4,   259,   245,   258,    37,   121,    68,   250,
     257,   259,   127,   128,   255,    75,   257,   257,   257,   256,
       1,   257,     1,     1,   256,     3,   244,   244,     6,   144,
     145,   146,    10,   259,    94,   257,   257,     1,   226,   257,
     257,   156,   186,    45,   232,   257,    48,    25,    26,    27,
     165,   259,   257,    31,    85,   243,   244,   259,   244,    23,
      24,   259,   122,   195,   196,   253,    30,   238,   259,   257,
     130,    49,   186,    54,   132,    53,    54,    56,    57,    58,
      59,    60,    61,    62,    63,     1,   213,   214,   258,   149,
     121,   259,   123,   124,   259,   259,   259,   259,   158,   159,
     244,     1,   104,    84,   132,   259,    84,   244,    86,    90,
     259,   259,   259,   259,   172,   173,   174,   175,   176,   121,
     257,   259,   100,   259,    40,   259,   105,   256,   259,   189,
     190,   246,   247,   248,   259,    10,   167,    12,   169,    55,
      40,   259,   257,   121,   729,   109,   110,   111,   259,     1,
     114,   182,    27,   259,   259,    55,    31,   121,   259,   259,
     139,    77,   259,    79,   259,    81,    82,   259,   259,   259,
     134,   135,   259,   154,   259,   259,   154,    77,   259,    79,
     259,    81,    82,   259,   244,   101,   259,   259,   152,   153,
     168,   259,   259,   224,   259,   259,   259,   257,   259,   155,
     178,   101,    20,    21,    56,    57,    58,    59,    60,    61,
      62,    63,   259,   177,   880,   881,   882,   883,   884,   259,
     251,   252,   259,   259,    99,   259,   257,   259,   155,   259,
     259,   155,    50,   259,   259,   259,   259,   216,   259,   259,
     259,   259,   244,   259,   259,   259,   914,   259,   259,   259,
      68,   259,   259,   105,   259,   259,   131,    75,   259,   259,
     259,   259,   259,   259,     1,   259,   259,   259,   259,   259,
     249,     8,     9,   251,   259,    12,    94,   259,   257,   257,
     195,   132,    19,   259,   259,   259,   259,   139,   259,   259,
     259,    28,   132,   257,   256,    32,    33,   195,   132,   132,
       1,   132,    39,   195,   122,    42,    43,    44,   195,    46,
     195,   132,   130,   131,   195,    52,   195,     1,   195,   904,
     256,     5,   195,   195,   259,   259,   155,   912,   913,   259,
     256,   259,   195,   195,    71,    72,    37,   132,   155,    76,
     132,   257,    26,   132,   155,   195,    83,   195,   195,   195,
      87,    88,    89,   171,    38,    92,   132,   132,    95,    96,
     132,   132,   155,   238,   216,    49,   132,   195,   195,   106,
      54,   195,   190,   195,   132,   112,   113,   132,   115,   116,
     117,   118,    66,   132,    85,   155,   132,   195,   195,    73,
     259,   195,   129,   259,    78,   195,    80,   249,   155,   195,
     132,   138,   256,   140,   141,   195,   143,   195,   195,    93,
     147,   148,   195,   195,   151,   195,   195,   259,   259,   256,
     121,   259,   123,   124,   259,   162,   217,   218,   219,   220,
     221,   222,   223,   259,     1,   155,     3,   121,   155,     6,
     259,   256,   126,    10,   181,   259,   183,   259,   155,   259,
     187,   155,   155,   259,   191,   192,   193,   194,    25,    26,
      27,   198,   199,   155,    31,   149,   167,   155,   169,   206,
       5,   195,     1,   259,   259,   259,   155,   161,   259,   163,
     164,   182,    49,   155,   168,   259,    53,    54,     5,   155,
     259,   259,    20,    21,    23,    24,   259,   259,   259,   259,
     237,    30,   239,    38,   155,   259,   259,   259,   245,   256,
     155,   256,   256,   250,    49,   195,   259,    84,   255,    86,
     259,    38,    50,   224,   259,   195,   195,   155,   195,   256,
     195,    66,    49,   100,     1,   155,   195,   155,    73,   155,
      68,   155,   226,    78,   155,    80,    13,    75,   232,    66,
     251,   252,   155,   155,   121,   132,    73,   155,    93,   243,
     244,    78,   155,    80,   259,     1,    94,    34,    35,   253,
     256,   256,   259,   256,    41,   256,    93,   259,   256,   256,
     109,   110,   111,   256,    20,   114,    71,   154,   256,   132,
      26,   126,   121,   256,   122,   256,   131,   259,   256,   256,
     256,   168,   130,   256,   256,   134,   135,   142,   256,   126,
     256,   178,   256,    49,    50,   256,   256,   256,    54,   256,
     256,   256,    93,   152,   153,   142,   161,   256,   163,   164,
      97,    98,    68,   259,   259,   259,   259,     0,     1,    75,
     107,   108,     5,   171,   161,   155,   163,   164,   177,   259,
     259,   259,   259,   259,    93,   259,   256,   155,    94,    22,
     127,   128,   190,    26,   259,   259,    29,   259,   259,   259,
     259,   259,   259,    36,   259,   259,   259,   144,   145,   146,
     259,   259,   155,   259,   251,   259,   122,   259,    51,   156,
     259,   226,   155,   259,   130,   259,   256,   256,   165,   170,
     155,    64,    65,   259,    67,   256,   256,   256,   243,   226,
     256,    74,   256,   149,   256,   256,   256,   256,   253,   256,
     256,   259,   158,   159,   256,   256,   243,   155,    91,   256,
     201,   170,   256,   256,   256,   256,   253,   256,   256,   102,
     256,   104,   256,   256,   215,   256,   195,   256,   256,   256,
     256,   256,   256,   189,   190,   256,   256,   120,   195,   256,
     256,   256,   201,   234,   235,   256,   256,   256,   256,   240,
     241,   242,   243,   256,   137,   256,   215,   256,   256,   246,
     247,   248,   253,   259,   256,   155,   256,   256,   256,   195,
     256,   256,   256,   195,   256,   234,   235,   256,   256,   256,
     256,   240,   241,   242,   243,   256,   259,   170,   244,   195,
     195,   195,   195,   195,   253,   155,   179,   180,   155,   155,
     195,   184,   185,   202,   203,   204,   205,   155,   207,   208,
     256,   210,   211,   212,   155,   259,   215,   155,   256,   259,
     155,   155,   132,   256,   256,   256,   225,   226,   227,   228,
     229,   230,   256,   256,   233,   256,   256,   236,   202,   203,
     204,   205,   256,   207,   208,   256,   210,   211,   212,   256,
     259,   215,   155,   155,   155,   256,   256,   155,   256,   256,
     256,   225,   226,   227,   228,   229,   230,   256,   256,   233,
     256,   256,   236,   202,   203,   204,   205,   256,   207,   208,
     256,   210,   211,   212,   256,   259,   215,   155,   259,   259,
     259,   259,   259,   259,   259,   256,   225,   226,   227,   228,
     229,   230,   155,   132,   233,   259,   259,   236,   259,   259,
     259,   132,   259,   259,   259,   259,   259,   259,   132,   256,
     256,   132,   132,   256,   256,   256,   256,   132,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     155,   256,   132,   259,   256,   259,   132,   256,   155,   195,
     195,   155,   155,   195,   195,   155,   155,   155,   155,   259,
     155,   132,   155,   155,   155,   256,   256,   256,   256,   256,
     256,   160,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   160,   256,
     256,   256,   256,   256,   256,   155,   155,   155,   200,   195,
     259,   195,   155,   259,   155,   256,   256,   195,   195,   256,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   256,   256,   256,   256,   256,   256,   132,   256,   256,
     256,   256,   256,   256,   256,   273,   256,   256,   256,   256,
     256,   812,  1452,   256,   256,  1388,  1450,   256,   256,   310,
     256,   605,  1372,  1368,   493,   256,  1261,   523,  1231,   563,
     555,   639,  1436,  1441,  1345,  1438,   460,  1370,   483,   124,
    1359,   356,   368,   183,  1203,  1365,   435,  1201,  1363,    95,
      -1,    -1,   256,   256,    -1,    -1,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,    -1,    -1,    -1,   256,
     256,   256,   256,    -1,   256,    -1,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   289
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   262,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   102,   104,   120,   137,   170,
     179,   180,   184,   185,   263,   268,   273,   287,   293,   308,
     343,   362,   375,   399,   406,   416,   425,   453,   463,   469,
     473,   483,   546,   562,   583,   256,   257,   258,   258,   344,
     426,   464,   258,   474,   258,   547,   376,   454,   363,   258,
     258,   309,   400,   258,   258,   407,   417,     1,    37,    47,
     121,   288,   289,   290,   291,   292,     1,    13,    34,    35,
      41,    97,    98,   107,   108,   127,   128,   144,   145,   146,
     156,   165,   246,   247,   248,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   155,   345,   349,   155,   427,
     431,   258,     1,    90,   470,   471,   472,   258,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    42,    43,    44,
      46,    52,    71,    72,    76,    83,    87,    88,    89,    92,
      95,    96,   106,   112,   113,   115,   116,   117,   118,   129,
     138,   140,   141,   143,   147,   148,   151,   162,   181,   183,
     187,   191,   192,   193,   194,   198,   199,   206,   237,   239,
     245,   250,   255,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   537,   541,   542,   543,   544,   545,   258,
     258,   258,   258,     1,    56,    57,    58,    59,    60,    61,
      62,    63,   105,   139,   216,   249,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
       1,   119,   150,   269,   270,   271,   272,   155,   310,   314,
     258,     1,    40,    55,    77,    79,    81,    82,   101,   584,
     585,   586,   587,   588,   589,   590,   591,   592,     1,    37,
      85,   121,   123,   124,   167,   169,   182,   224,   251,   252,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   258,   258,   256,   259,   259,   259,   257,
     289,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     564,   258,   258,     1,    90,   157,   465,   466,   467,   468,
     259,   257,   471,     1,   121,   157,   186,   475,   479,   480,
     481,   482,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   538,   259,   534,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   257,   485,     1,     4,
      45,    48,   104,   121,   244,   548,   549,   550,   551,   552,
     556,   557,   558,     1,    20,    26,    49,    50,    54,    68,
      75,    94,   122,   130,   149,   158,   159,   189,   190,   244,
     377,   378,   379,   380,   381,   382,   383,   384,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,     1,   157,
     186,   244,   455,   459,   460,   461,   462,     1,    54,    84,
      90,   154,   364,   368,   369,   370,   373,   374,   256,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   257,   295,   256,   259,   259,   257,   270,   258,     1,
      22,   125,   157,   401,   402,   403,   404,   405,   259,   259,
     259,   259,   259,   259,   259,   257,   585,   256,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   257,
     275,     1,   121,   186,   244,   408,   409,   410,   411,   412,
       1,   121,   186,   418,   419,   420,   421,   155,   155,   155,
     256,   195,   132,   132,   195,   132,   265,   265,   132,   132,
     195,   195,   195,   132,   265,   195,   195,   195,   195,   195,
     256,     1,    23,    24,    30,   109,   110,   111,   114,   121,
     134,   135,   152,   153,   177,   346,   347,   348,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
       1,     3,     6,    10,    25,    26,    27,    31,    49,    53,
      54,    84,    86,   100,   121,   154,   168,   178,   251,   428,
     429,   430,   432,   433,   434,   435,   436,   437,   438,   439,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   259,
     259,   257,   466,   155,   256,   259,   259,   476,   257,   480,
     195,   265,   195,   265,   132,   155,   132,   195,   195,   195,
     132,   155,   195,   132,   132,   132,   195,   265,   195,   195,
     132,   155,   195,   132,   132,   265,   132,   155,   132,   132,
     195,   195,   259,   195,   259,   265,   265,   195,   265,   155,
     195,   195,   195,   196,   195,   196,   195,   195,   265,   265,
     132,   267,   265,   195,   195,   195,   195,   256,   559,   259,
     259,   553,   259,   259,   257,   549,   256,   259,   259,   259,
     259,   385,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   257,   378,   259,   456,   259,   257,   460,
     256,   365,   259,   259,   259,   257,   369,   155,   155,   155,
     155,   155,   155,   155,   155,   217,   218,   219,   220,   221,
     222,   223,   155,   155,   195,   256,   155,   155,   256,     1,
       5,    26,    38,    49,    54,    66,    73,    78,    80,    93,
     121,   126,   149,   161,   163,   164,   168,   226,   232,   243,
     244,   253,   311,   312,   313,   315,   316,   317,   318,   319,
     320,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   256,   259,   259,   259,
     257,   402,   195,   195,   195,   155,   195,   195,   265,   256,
     155,   195,   155,   155,   155,   155,   155,   155,   132,   155,
     155,   256,   256,   259,   413,   259,   257,   409,   256,   259,
     422,   257,   419,   256,   256,   256,   256,   256,   256,   256,
     172,   173,   174,   175,   176,   264,   265,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   257,   347,   256,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   440,   259,   259,
     259,   259,   259,   259,   259,   259,   257,   429,   155,   155,
     256,   256,   155,   155,   259,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   202,   203,
     204,   205,   207,   208,   210,   211,   212,   215,   225,   226,
     227,   228,   229,   230,   233,   236,   539,   540,   256,   202,
     203,   204,   205,   207,   208,   210,   211,   212,   215,   225,
     226,   227,   228,   229,   230,   233,   236,   535,   536,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,    14,    15,    16,   266,   267,   256,
     256,   256,   256,   256,   256,   259,   265,   195,   259,   155,
     155,   256,   195,   155,   195,   195,   259,   195,   195,   195,
     195,   195,   155,   132,   155,   155,   195,   155,   256,   155,
     259,   155,   256,   259,   155,   155,   132,   371,   372,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   259,   259,   259,   259,   339,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   259,   321,
     259,   259,   259,   257,   312,   155,   155,   155,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   155,   259,   155,
     256,   155,   259,   256,   264,   264,   264,   264,   264,   132,
     132,   265,   132,   132,   132,   132,   155,   132,   132,   265,
     265,   267,   256,   155,   213,   214,   195,   155,   155,   195,
     195,   195,   155,   259,   155,   155,   155,   155,   132,   155,
     155,   155,   256,   256,   256,   256,   256,   160,   477,   478,
     256,   260,   256,   260,   266,   266,   266,    11,   197,   560,
     561,   256,   256,    11,   197,   554,   555,   256,   256,   256,
     256,   256,   256,    20,    21,    50,    68,    75,    94,   122,
     130,   131,   171,   190,   386,   387,   388,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   160,
     457,   458,   256,    77,   231,   366,   367,   256,   256,   200,
     256,   260,   195,   155,   195,   195,   259,   195,   195,   195,
     195,   195,   155,   195,   155,   195,   195,   195,   155,   195,
     259,   195,   155,   195,   256,   256,   256,   256,   256,    93,
     170,   201,   215,   234,   235,   240,   241,   242,   243,   253,
     414,   415,   256,   256,    93,   170,   201,   215,   234,   235,
     240,   241,   242,   243,   253,   423,   424,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
      10,    12,    27,    31,    99,   131,   238,   441,   442,   443,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   260,
     540,   536,   256,   260,   256,   260,   388,   256,   260,   256,
     260,   256,   260,   132,   372,   256,   256,   256,   256,     5,
      38,    49,    66,    73,    78,    80,    93,   126,   131,   142,
     161,   163,   164,   226,   243,   253,   340,   341,   342,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   202,   203,   204,   205,   207,   208,   210,   211,
     212,   215,   225,   226,   227,   228,   229,   230,   233,   236,
     322,   323,   256,   256,   256,   256,   260,   256,   260,   443,
     256,   260,   478,   561,   555,   387,   458,   367,   342,   256,
     260,   256,   260,   415,   424,   442,   341,   323
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
    { 								\
      yyerror ("syntax error: cannot back up");\
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
      yysymprint (stderr, 					\
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
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
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
  register const char *yys = yystr;

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
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



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

#endif
#endif
{
  
  register int yystate;
  register int yyn;
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
  register short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



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


  yyvsp[0] = yylval;

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
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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
    if ((strlen(yylval.string) == IRC_MAXSID) && IsDigit(yylval.string[0])
	&& IsAlNum(yylval.string[1]) && IsAlNum(yylval.string[2]))
    {
      DupString(ServerInfo.sid, yylval.string);
    }
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 634 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 643 "ircd_parser.y"
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
#line 657 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 666 "ircd_parser.y"
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
#line 694 "ircd_parser.y"
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
#line 724 "ircd_parser.y"
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
#line 747 "ircd_parser.y"
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
#line 803 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 812 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 821 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 848 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 852 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 856 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 863 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 870 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 877 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 884 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 891 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 898 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 905 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 912 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 916 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 920 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 924 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 928 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 932 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 936 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 942 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 951 "ircd_parser.y"
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
#line 964 "ircd_parser.y"
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
#line 1056 "ircd_parser.y"
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
#line 1068 "ircd_parser.y"
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
#line 1080 "ircd_parser.y"
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
#line 1099 "ircd_parser.y"
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
#line 1111 "ircd_parser.y"
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
#line 1122 "ircd_parser.y"
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
#line 1164 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1173 "ircd_parser.y"
    {
  yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1179 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1182 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1185 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1188 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1191 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1194 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1197 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1200 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1203 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1206 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1209 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1212 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1215 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1218 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1221 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1224 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1227 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1230 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1235 "ircd_parser.y"
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
#line 1246 "ircd_parser.y"
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
#line 1257 "ircd_parser.y"
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
#line 1268 "ircd_parser.y"
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
#line 1279 "ircd_parser.y"
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
#line 1290 "ircd_parser.y"
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
#line 1301 "ircd_parser.y"
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
#line 1312 "ircd_parser.y"
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
#line 1323 "ircd_parser.y"
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
#line 1334 "ircd_parser.y"
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
#line 1345 "ircd_parser.y"
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
#line 1356 "ircd_parser.y"
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
#line 1367 "ircd_parser.y"
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
#line 1378 "ircd_parser.y"
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
#line 1389 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1393 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 195:
#line 1394 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 196:
#line 1397 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 197:
#line 1404 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 198:
#line 1411 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 199:
#line 1418 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 200:
#line 1425 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 201:
#line 1432 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 202:
#line 1439 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 203:
#line 1446 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 204:
#line 1453 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 205:
#line 1460 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 206:
#line 1467 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 207:
#line 1474 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 208:
#line 1481 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 209:
#line 1488 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 210:
#line 1495 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 211:
#line 1502 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 212:
#line 1515 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 213:
#line 1522 "ircd_parser.y"
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

  case 232:
#line 1574 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 233:
#line 1583 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 234:
#line 1592 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 235:
#line 1598 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[-1].number);
}
    break;

  case 236:
#line 1604 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[-1].number);
}
    break;

  case 237:
#line 1610 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 238:
#line 1616 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 239:
#line 1622 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 240:
#line 1628 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 241:
#line 1634 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[-1].number);
}
    break;

  case 242:
#line 1640 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 243:
#line 1646 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[-1].number);
}
    break;

  case 244:
#line 1652 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[-1].number);
}
    break;

  case 245:
#line 1658 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[-1].number);
}
    break;

  case 246:
#line 1667 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 247:
#line 1674 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 248:
#line 1683 "ircd_parser.y"
    {
}
    break;

  case 252:
#line 1688 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 253:
#line 1692 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 264:
#line 1705 "ircd_parser.y"
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
    listener_flags = 0;
  }
}
    break;

  case 265:
#line 1720 "ircd_parser.y"
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

    listener_flags = 0;
  }
}
    break;

  case 266:
#line 1742 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 267:
#line 1751 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 268:
#line 1763 "ircd_parser.y"
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

  case 269:
#line 1775 "ircd_parser.y"
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

  case 289:
#line 1840 "ircd_parser.y"
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

  case 290:
#line 1859 "ircd_parser.y"
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

  case 291:
#line 1872 "ircd_parser.y"
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

  case 292:
#line 1883 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 293:
#line 1892 "ircd_parser.y"
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

  case 294:
#line 1903 "ircd_parser.y"
    {
}
    break;

  case 298:
#line 1907 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 299:
#line 1908 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 300:
#line 1911 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 301:
#line 1919 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 302:
#line 1926 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 303:
#line 1933 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 304:
#line 1940 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 305:
#line 1947 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 306:
#line 1954 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 307:
#line 1961 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 308:
#line 1968 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 309:
#line 1975 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 310:
#line 1984 "ircd_parser.y"
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

  case 311:
#line 1995 "ircd_parser.y"
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

  case 312:
#line 2006 "ircd_parser.y"
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

  case 313:
#line 2017 "ircd_parser.y"
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

  case 314:
#line 2028 "ircd_parser.y"
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

  case 315:
#line 2039 "ircd_parser.y"
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

  case 316:
#line 2051 "ircd_parser.y"
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

  case 317:
#line 2070 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 318:
#line 2080 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[-1].number);
  }
}
    break;

  case 319:
#line 2089 "ircd_parser.y"
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

  case 320:
#line 2104 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 321:
#line 2111 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 328:
#line 2123 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 329:
#line 2132 "ircd_parser.y"
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

  case 330:
#line 2147 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 331:
#line 2160 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 332:
#line 2168 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 339:
#line 2179 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 340:
#line 2188 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 341:
#line 2196 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 345:
#line 2203 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 346:
#line 2207 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 347:
#line 2211 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 348:
#line 2215 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 349:
#line 2219 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 350:
#line 2223 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 351:
#line 2227 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 352:
#line 2231 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 353:
#line 2235 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 354:
#line 2239 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 355:
#line 2243 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 356:
#line 2252 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 357:
#line 2259 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 363:
#line 2272 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 364:
#line 2278 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 368:
#line 2285 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 369:
#line 2289 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 370:
#line 2293 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 371:
#line 2297 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 372:
#line 2301 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 373:
#line 2305 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 374:
#line 2309 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 375:
#line 2313 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 376:
#line 2317 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 377:
#line 2321 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 378:
#line 2325 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 379:
#line 2334 "ircd_parser.y"
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

  case 380:
#line 2352 "ircd_parser.y"
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

  case 404:
#line 2495 "ircd_parser.y"
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

  case 405:
#line 2507 "ircd_parser.y"
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

  case 406:
#line 2519 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 407:
#line 2528 "ircd_parser.y"
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

  case 408:
#line 2554 "ircd_parser.y"
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

  case 409:
#line 2572 "ircd_parser.y"
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

  case 410:
#line 2590 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[-1].number);
}
    break;

  case 411:
#line 2596 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 412:
#line 2600 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 413:
#line 2608 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 414:
#line 2617 "ircd_parser.y"
    {
}
    break;

  case 418:
#line 2621 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 419:
#line 2622 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 420:
#line 2625 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 421:
#line 2632 "ircd_parser.y"
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

  case 422:
#line 2643 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 423:
#line 2650 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 424:
#line 2657 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 425:
#line 2664 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 426:
#line 2674 "ircd_parser.y"
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

  case 427:
#line 2715 "ircd_parser.y"
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

  case 428:
#line 2726 "ircd_parser.y"
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

  case 429:
#line 2737 "ircd_parser.y"
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

  case 430:
#line 2752 "ircd_parser.y"
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

  case 431:
#line 2763 "ircd_parser.y"
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

  case 432:
#line 2776 "ircd_parser.y"
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

  case 433:
#line 2789 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 434:
#line 2798 "ircd_parser.y"
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

  case 435:
#line 2833 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 436:
#line 2840 "ircd_parser.y"
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

  case 437:
#line 2894 "ircd_parser.y"
    {
}
    break;

  case 441:
#line 2899 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 448:
#line 2908 "ircd_parser.y"
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

  case 449:
#line 2924 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 450:
#line 2933 "ircd_parser.y"
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

  case 451:
#line 2942 "ircd_parser.y"
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

  case 457:
#line 2958 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 458:
#line 2967 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 464:
#line 2984 "ircd_parser.y"
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

  case 465:
#line 3005 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 466:
#line 3012 "ircd_parser.y"
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

  case 467:
#line 3046 "ircd_parser.y"
    {
}
    break;

  case 471:
#line 3051 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 478:
#line 3060 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 479:
#line 3066 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 538:
#line 3111 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
    break;

  case 539:
#line 3116 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
    break;

  case 540:
#line 3121 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 541:
#line 3126 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 542:
#line 3131 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 543:
#line 3136 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 544:
#line 3141 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
    break;

  case 545:
#line 3146 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 546:
#line 3151 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 547:
#line 3156 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 548:
#line 3161 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 549:
#line 3166 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 550:
#line 3171 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
    break;

  case 551:
#line 3176 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
    break;

  case 552:
#line 3181 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
    break;

  case 553:
#line 3186 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
    break;

  case 554:
#line 3191 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
    break;

  case 555:
#line 3196 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
    break;

  case 556:
#line 3202 "ircd_parser.y"
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

  case 557:
#line 3213 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 558:
#line 3218 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 559:
#line 3227 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 560:
#line 3232 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 561:
#line 3237 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 562:
#line 3242 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 563:
#line 3247 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 564:
#line 3250 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 565:
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 566:
#line 3258 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 567:
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
    break;

  case 568:
#line 3268 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
    break;

  case 569:
#line 3273 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 570:
#line 3278 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
    break;

  case 571:
#line 3283 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 572:
#line 3288 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 573:
#line 3293 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 574:
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 575:
#line 3303 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 576:
#line 3314 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[-1].number);
}
    break;

  case 577:
#line 3319 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
    break;

  case 578:
#line 3324 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
    break;

  case 579:
#line 3329 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 580:
#line 3338 "ircd_parser.y"
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

  case 581:
#line 3370 "ircd_parser.y"
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

  case 582:
#line 3388 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 583:
#line 3393 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 584:
#line 3402 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 585:
#line 3407 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 586:
#line 3412 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 587:
#line 3417 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 591:
#line 3423 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 592:
#line 3426 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 593:
#line 3429 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 594:
#line 3432 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 595:
#line 3435 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 596:
#line 3438 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 597:
#line 3441 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 598:
#line 3444 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 599:
#line 3447 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 600:
#line 3450 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 601:
#line 3453 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 602:
#line 3456 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 603:
#line 3459 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 604:
#line 3462 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 605:
#line 3465 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 606:
#line 3468 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 607:
#line 3471 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 608:
#line 3474 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 609:
#line 3479 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 613:
#line 3485 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 614:
#line 3488 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 615:
#line 3491 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 616:
#line 3494 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 617:
#line 3497 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 618:
#line 3500 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 619:
#line 3503 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 620:
#line 3506 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 621:
#line 3509 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 622:
#line 3512 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 623:
#line 3515 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 624:
#line 3518 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 625:
#line 3521 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 626:
#line 3524 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 627:
#line 3527 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 628:
#line 3530 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 629:
#line 3533 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 630:
#line 3536 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 631:
#line 3541 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
    break;

  case 632:
#line 3546 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
    break;

  case 633:
#line 3551 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
    break;

  case 634:
#line 3556 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[-1].number);
}
    break;

  case 635:
#line 3561 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 636:
#line 3569 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->flags = 0;
  }
}
    break;

  case 637:
#line 3577 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /*
     * since we re-allocate yy_conf/yy_aconf after the end of action=, at the
     * end we will have one extra, so we should free it.
     */
    if (yy_conf->name == NULL && gdeny_items.length)
    {
      dlinkDelete(gdeny_items.tail, &gdeny_items);
      MyFree(yy_conf);
      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 647:
#line 3604 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 648:
#line 3610 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
    break;

  case 649:
#line 3616 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 653:
#line 3622 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 654:
#line 3626 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 655:
#line 3632 "ircd_parser.y"
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

  case 656:
#line 3651 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 657:
#line 3660 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 658:
#line 3664 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr, *next_ptr;

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      yy_tmp = ptr->data;
      new_conf = make_conf_item(GDENY_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

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
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->flags = 0;
  }
}
    break;

  case 661:
#line 3704 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 662:
#line 3708 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 685:
#line 3733 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 686:
#line 3738 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 687:
#line 3743 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 688:
#line 3748 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 689:
#line 3753 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 690:
#line 3758 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
    break;

  case 691:
#line 3763 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
    break;

  case 692:
#line 3768 "ircd_parser.y"
    {
  ConfigChannel.invite_ops_only = yylval.number;
}
    break;

  case 693:
#line 3773 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
    break;

  case 694:
#line 3778 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 695:
#line 3783 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
    break;

  case 696:
#line 3788 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
    break;

  case 697:
#line 3793 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
    break;

  case 698:
#line 3798 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 699:
#line 3803 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 700:
#line 3808 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 701:
#line 3813 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 702:
#line 3818 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 714:
#line 3837 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 715:
#line 3843 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 716:
#line 3849 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 717:
#line 3858 "ircd_parser.y"
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

  case 718:
#line 3872 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 719:
#line 3878 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 720:
#line 3884 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


    }

/* Line 1037 of yacc.c.  */
#line 7331 "y.tab.c"

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
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {

		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 yydestruct ("Error: popping",
                             yystos[*yyssp], yyvsp);
	       }
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

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
  yydestruct ("Error: discarding lookahead",
              yytoken, &yylval);
  yychar = YYEMPTY;
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



