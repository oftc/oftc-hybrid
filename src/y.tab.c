/* A Bison parser, made from ircd_parser.y, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
#define YYBISON	1

/* Pure parsers.  */
#define YYPURE	0

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
     T_UNAUTH = 487,
     T_UNRESV = 488,
     T_UNXLINE = 489,
     T_WALLOP = 490,
     THROTTLE_TIME = 491,
     TOPICBURST = 492,
     TRUE_NO_OPER_FLOOD = 493,
     TKLINE = 494,
     TXLINE = 495,
     TRESV = 496,
     UNKLINE = 497,
     USER = 498,
     USE_EGD = 499,
     USE_EXCEPT = 500,
     USE_INVEX = 501,
     USE_KNOCK = 502,
     USE_LOGGING = 503,
     USE_WHOIS_ACTUALLY = 504,
     VHOST = 505,
     VHOST6 = 506,
     XLINE = 507,
     WARN = 508,
     WARN_NO_NLINE = 509
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
#define T_UNAUTH 487
#define T_UNRESV 488
#define T_UNXLINE 489
#define T_WALLOP 490
#define THROTTLE_TIME 491
#define TOPICBURST 492
#define TRUE_NO_OPER_FLOOD 493
#define TKLINE 494
#define TXLINE 495
#define TRESV 496
#define UNKLINE 497
#define USER 498
#define USE_EGD 499
#define USE_EXCEPT 500
#define USE_INVEX 501
#define USE_KNOCK 502
#define USE_LOGGING 503
#define USE_WHOIS_ACTUALLY 504
#define VHOST 505
#define VHOST6 506
#define XLINE 507
#define WARN 508
#define WARN_NO_NLINE 509




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

#ifndef YYSTYPE
#line 134 "ircd_parser.y"
typedef union {
  int number;
  char *string;
} yystype;
/* Line 193 of /usr/local/share/bison/yacc.c.  */
#line 695 "y.tab.c"
# define YYSTYPE yystype
# define YYSTYPE_IS_TRIVIAL 1
#endif

#ifndef YYLTYPE
typedef struct yyltype
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} yyltype;
# define YYLTYPE yyltype
# define YYLTYPE_IS_TRIVIAL 1
#endif

/* Copy the second part of user declarations.  */


/* Line 213 of /usr/local/share/bison/yacc.c.  */
#line 716 "y.tab.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
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
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYLTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAX)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];	\
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
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
#define YYLAST   1402

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  260
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  328
/* YYNRULES -- Number of rules. */
#define YYNRULES  697
/* YYNRULES -- Number of states. */
#define YYNSTATES  1431

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   509

#define YYTRANSLATE(X) \
  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[X] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   259,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   255,
       2,   258,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   257,     2,   256,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
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
     428,   430,   432,   434,   436,   438,   441,   446,   448,   453,
     458,   463,   468,   473,   478,   483,   488,   493,   498,   503,
     508,   513,   518,   523,   528,   533,   538,   543,   544,   550,
     554,   556,   559,   561,   563,   565,   567,   569,   571,   573,
     575,   577,   579,   581,   583,   585,   587,   589,   591,   593,
     594,   602,   603,   605,   608,   610,   612,   614,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   639,
     644,   646,   651,   656,   661,   666,   671,   676,   681,   686,
     691,   696,   701,   706,   707,   714,   715,   721,   725,   727,
     729,   731,   734,   736,   738,   740,   742,   744,   747,   752,
     756,   758,   760,   764,   769,   774,   775,   782,   785,   787,
     789,   791,   793,   795,   797,   799,   801,   803,   805,   807,
     809,   811,   813,   815,   817,   819,   822,   827,   832,   837,
     842,   847,   848,   854,   858,   860,   863,   865,   867,   869,
     871,   873,   875,   877,   879,   881,   883,   885,   890,   895,
     900,   905,   910,   915,   920,   925,   930,   935,   936,   943,
     946,   948,   950,   952,   954,   957,   962,   967,   972,   973,
     980,   983,   985,   987,   989,   991,   994,   999,  1004,  1005,
    1011,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,  1031,
    1033,  1035,  1037,  1039,  1040,  1047,  1050,  1052,  1054,  1056,
    1059,  1064,  1065,  1071,  1075,  1077,  1079,  1081,  1083,  1085,
    1087,  1089,  1091,  1093,  1095,  1097,  1099,  1100,  1108,  1109,
    1111,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1155,  1160,  1162,  1167,  1172,  1177,  1182,  1187,  1192,
    1197,  1202,  1203,  1209,  1213,  1215,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1237,  1242,  1247,  1252,  1257,  1262,
    1267,  1272,  1277,  1278,  1285,  1286,  1292,  1296,  1298,  1300,
    1303,  1305,  1307,  1309,  1311,  1313,  1318,  1323,  1324,  1331,
    1334,  1336,  1338,  1340,  1342,  1347,  1352,  1358,  1361,  1363,
    1365,  1367,  1372,  1373,  1380,  1381,  1387,  1391,  1393,  1395,
    1398,  1400,  1402,  1404,  1406,  1408,  1413,  1418,  1424,  1427,
    1429,  1431,  1433,  1435,  1437,  1439,  1441,  1443,  1445,  1447,
    1449,  1451,  1453,  1455,  1457,  1459,  1461,  1463,  1465,  1467,
    1469,  1471,  1473,  1475,  1477,  1479,  1481,  1483,  1485,  1487,
    1489,  1491,  1493,  1495,  1497,  1499,  1501,  1503,  1505,  1507,
    1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,  1527,
    1529,  1531,  1533,  1535,  1537,  1539,  1544,  1549,  1554,  1559,
    1564,  1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,  1609,
    1614,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1654,  1659,
    1664,  1669,  1674,  1679,  1684,  1689,  1694,  1699,  1704,  1709,
    1714,  1719,  1724,  1729,  1734,  1739,  1744,  1749,  1754,  1759,
    1764,  1769,  1774,  1779,  1784,  1785,  1791,  1795,  1797,  1799,
    1801,  1803,  1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,
    1821,  1823,  1825,  1827,  1829,  1831,  1833,  1834,  1840,  1844,
    1846,  1848,  1850,  1852,  1854,  1856,  1858,  1860,  1862,  1864,
    1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,  1882,  1887,
    1892,  1897,  1902,  1907,  1908,  1915,  1918,  1920,  1922,  1924,
    1926,  1928,  1930,  1932,  1934,  1939,  1944,  1945,  1951,  1955,
    1957,  1959,  1961,  1966,  1971,  1972,  1978,  1982,  1984,  1986,
    1988,  1994,  1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,
    2013,  2015,  2017,  2019,  2021,  2023,  2025,  2027,  2029,  2031,
    2033,  2035,  2037,  2042,  2047,  2052,  2057,  2062,  2067,  2072,
    2077,  2082,  2087,  2092,  2097,  2102,  2107,  2112,  2117,  2122,
    2127,  2133,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,
    2152,  2154,  2159,  2164,  2169,  2174,  2179,  2184
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     261,     0,    -1,    -1,   261,   262,    -1,   286,    -1,   292,
      -1,   307,    -1,   557,    -1,   338,    -1,   357,    -1,   370,
      -1,   272,    -1,   578,    -1,   394,    -1,   401,    -1,   411,
      -1,   420,    -1,   448,    -1,   458,    -1,   464,    -1,   478,
      -1,   541,    -1,   468,    -1,   267,    -1,     1,   255,    -1,
       1,   256,    -1,    -1,   264,    -1,   132,   263,    -1,   132,
     172,   263,    -1,   132,   173,   263,    -1,   132,   174,   263,
      -1,   132,   175,   263,    -1,   132,   176,   263,    -1,    -1,
     266,    -1,   132,   265,    -1,   132,    14,   265,    -1,   132,
      15,   265,    -1,   132,    16,   265,    -1,   120,   257,   268,
     256,   255,    -1,   268,   269,    -1,   269,    -1,   270,    -1,
     271,    -1,     1,   255,    -1,   119,   258,   155,   255,    -1,
     150,   258,   155,   255,    -1,   180,   257,   273,   256,   255,
      -1,   273,   274,    -1,   274,    -1,   277,    -1,   282,    -1,
     285,    -1,   279,    -1,   280,    -1,   281,    -1,   284,    -1,
     276,    -1,   283,    -1,   278,    -1,   275,    -1,     1,   255,
      -1,   169,   258,   155,   255,    -1,   167,   258,   155,   255,
      -1,   121,   258,   155,   255,    -1,   182,   258,   155,   255,
      -1,    37,   258,   155,   255,    -1,   124,   258,   155,   255,
      -1,   123,   258,   155,   255,    -1,   250,   258,   155,   255,
      -1,   251,   258,   155,   255,    -1,   224,   258,   132,   255,
      -1,    85,   258,   195,   255,    -1,     5,   257,   287,   256,
     255,    -1,   287,   288,    -1,   288,    -1,   289,    -1,   291,
      -1,   290,    -1,     1,   255,    -1,   121,   258,   155,   255,
      -1,    47,   258,   155,   255,    -1,    37,   258,   155,   255,
      -1,   104,   257,   293,   256,   255,    -1,   293,   294,    -1,
     294,    -1,   295,    -1,   296,    -1,   305,    -1,   306,    -1,
     297,    -1,   299,    -1,   301,    -1,   302,    -1,   304,    -1,
     300,    -1,   303,    -1,   298,    -1,     1,   255,    -1,   216,
     258,   155,   255,    -1,   139,   258,   155,   255,    -1,    63,
     258,   155,   255,    -1,    56,   258,   155,   255,    -1,    61,
     258,   155,   255,    -1,    62,   258,   155,   255,    -1,    59,
     258,   155,   255,    -1,    58,   258,   155,   255,    -1,    60,
     258,   155,   255,    -1,    57,   258,   155,   255,    -1,   105,
     258,   217,   255,    -1,   105,   258,   219,   255,    -1,   105,
     258,   223,   255,    -1,   105,   258,   221,   255,    -1,   105,
     258,   222,   255,    -1,   105,   258,   220,   255,    -1,   105,
     258,   218,   255,    -1,   248,   258,   195,   255,    -1,    -1,
     137,   308,   309,   257,   310,   256,   255,    -1,    -1,   313,
      -1,   310,   311,    -1,   311,    -1,   312,    -1,   314,    -1,
     315,    -1,   330,    -1,   331,    -1,   318,    -1,   319,    -1,
     320,    -1,   322,    -1,   323,    -1,   324,    -1,   325,    -1,
     326,    -1,   321,    -1,   327,    -1,   328,    -1,   329,    -1,
     332,    -1,   316,    -1,   317,    -1,   333,    -1,     1,   255,
      -1,   121,   258,   155,   255,    -1,   155,    -1,   243,   258,
     155,   255,    -1,   149,   258,   155,   255,    -1,    49,   258,
     195,   255,    -1,   168,   258,   155,   255,    -1,    26,   258,
     155,   255,    -1,    73,   258,   195,   255,    -1,   163,   258,
     195,   255,    -1,   164,   258,   195,   255,    -1,    93,   258,
     195,   255,    -1,   252,   258,   195,   255,    -1,   242,   258,
     195,   255,    -1,    66,   258,   195,   255,    -1,   126,   258,
     195,   255,    -1,    38,   258,   195,   255,    -1,   161,   258,
     195,   255,    -1,     5,   258,   195,   255,    -1,    78,   258,
     195,   255,    -1,    80,   258,   195,   255,    -1,   226,   258,
     195,   255,    -1,    -1,    54,   334,   258,   335,   255,    -1,
     335,   259,   336,    -1,   336,    -1,   131,   337,    -1,   337,
      -1,    73,    -1,   163,    -1,    93,    -1,   242,    -1,   252,
      -1,    66,    -1,    38,    -1,   161,    -1,     5,    -1,    78,
      -1,   126,    -1,   226,    -1,   142,    -1,    80,    -1,   164,
      -1,    49,    -1,    -1,    26,   339,   340,   257,   341,   256,
     255,    -1,    -1,   344,    -1,   341,   342,    -1,   342,    -1,
     343,    -1,   354,    -1,   355,    -1,   345,    -1,   346,    -1,
     356,    -1,   347,    -1,   348,    -1,   349,    -1,   350,    -1,
     351,    -1,   352,    -1,   353,    -1,     1,   255,    -1,   121,
     258,   155,   255,    -1,   155,    -1,   152,   258,   264,   255,
      -1,   153,   258,   264,   255,    -1,   135,   258,   132,   255,
      -1,    30,   258,   264,   255,    -1,   114,   258,   132,   255,
      -1,   109,   258,   132,   255,    -1,   111,   258,   132,   255,
      -1,   110,   258,   132,   255,    -1,   177,   258,   266,   255,
      -1,    23,   258,   132,   255,    -1,    24,   258,   132,   255,
      -1,   134,   258,   132,   255,    -1,    -1,   102,   358,   257,
     363,   256,   255,    -1,    -1,    54,   360,   258,   361,   255,
      -1,   361,   259,   362,    -1,   362,    -1,   231,    -1,    77,
      -1,   363,   364,    -1,   364,    -1,   365,    -1,   359,    -1,
     368,    -1,   369,    -1,     1,   255,    -1,   154,   258,   366,
     255,    -1,   366,   259,   367,    -1,   367,    -1,   132,    -1,
     132,   200,   132,    -1,    90,   258,   155,   255,    -1,    84,
     258,   155,   255,    -1,    -1,    74,   371,   257,   372,   256,
     255,    -1,   372,   373,    -1,   373,    -1,   374,    -1,   375,
      -1,   377,    -1,   379,    -1,   384,    -1,   385,    -1,   386,
      -1,   388,    -1,   389,    -1,   390,    -1,   376,    -1,   391,
      -1,   392,    -1,   387,    -1,   393,    -1,   378,    -1,     1,
     255,    -1,   243,   258,   155,   255,    -1,   149,   258,   155,
     255,    -1,   190,   258,   195,   255,    -1,    26,   258,   155,
     255,    -1,    49,   258,   195,   255,    -1,    -1,    54,   380,
     258,   381,   255,    -1,   381,   259,   382,    -1,   382,    -1,
     131,   383,    -1,   383,    -1,   190,    -1,    50,    -1,    94,
      -1,    75,    -1,    20,    -1,    21,    -1,   130,    -1,    68,
      -1,   171,    -1,   122,    -1,    94,   258,   195,   255,    -1,
      75,   258,   195,   255,    -1,    50,   258,   195,   255,    -1,
      20,   258,   195,   255,    -1,   130,   258,   195,   255,    -1,
      68,   258,   195,   255,    -1,   189,   258,   155,   255,    -1,
     159,   258,   155,   255,    -1,   158,   258,   132,   255,    -1,
     122,   258,   195,   255,    -1,    -1,   170,   395,   257,   396,
     256,   255,    -1,   396,   397,    -1,   397,    -1,   398,    -1,
     399,    -1,   400,    -1,     1,   255,    -1,   157,   258,   155,
     255,    -1,    22,   258,   155,   255,    -1,   125,   258,   155,
     255,    -1,    -1,   184,   402,   257,   403,   256,   255,    -1,
     403,   404,    -1,   404,    -1,   405,    -1,   406,    -1,   407,
      -1,     1,   255,    -1,   121,   258,   155,   255,    -1,   243,
     258,   155,   255,    -1,    -1,   186,   408,   258,   409,   255,
      -1,   409,   259,   410,    -1,   410,    -1,    93,    -1,   239,
      -1,   242,    -1,   252,    -1,   240,    -1,   234,    -1,   170,
      -1,   241,    -1,   233,    -1,   215,    -1,   201,    -1,    -1,
     185,   412,   257,   413,   256,   255,    -1,   413,   414,    -1,
     414,    -1,   415,    -1,   416,    -1,     1,   255,    -1,   121,
     258,   155,   255,    -1,    -1,   186,   417,   258,   418,   255,
      -1,   418,   259,   419,    -1,   419,    -1,    93,    -1,   239,
      -1,   242,    -1,   252,    -1,   240,    -1,   234,    -1,   170,
      -1,   241,    -1,   233,    -1,   215,    -1,   201,    -1,    -1,
      29,   421,   422,   257,   423,   256,   255,    -1,    -1,   426,
      -1,   423,   424,    -1,   424,    -1,   425,    -1,   427,    -1,
     428,    -1,   429,    -1,   430,    -1,   432,    -1,   431,    -1,
     433,    -1,   434,    -1,   444,    -1,   445,    -1,   446,    -1,
     443,    -1,   440,    -1,   442,    -1,   441,    -1,   439,    -1,
     447,    -1,     1,   255,    -1,   121,   258,   155,   255,    -1,
     155,    -1,    84,   258,   155,   255,    -1,   250,   258,   155,
     255,    -1,   178,   258,   155,   255,    -1,     3,   258,   155,
     255,    -1,   154,   258,   132,   255,    -1,     6,   258,   213,
     255,    -1,     6,   258,   214,   255,    -1,    53,   258,   155,
     255,    -1,    -1,    54,   435,   258,   436,   255,    -1,   436,
     259,   437,    -1,   437,    -1,   131,   438,    -1,   438,    -1,
      99,    -1,    27,    -1,    31,    -1,    10,    -1,    12,    -1,
     237,    -1,   168,   258,   155,   255,    -1,    49,   258,   195,
     255,    -1,    31,   258,   195,   255,    -1,    27,   258,   195,
     255,    -1,    10,   258,   195,   255,    -1,    86,   258,   155,
     255,    -1,   100,   258,   155,   255,    -1,    26,   258,   155,
     255,    -1,    25,   258,   155,   255,    -1,    -1,    91,   449,
     257,   454,   256,   255,    -1,    -1,   186,   451,   258,   452,
     255,    -1,   452,   259,   453,    -1,   453,    -1,   160,    -1,
     454,   455,    -1,   455,    -1,   456,    -1,   457,    -1,   450,
      -1,     1,    -1,   243,   258,   155,   255,    -1,   157,   258,
     155,   255,    -1,    -1,    36,   459,   257,   460,   256,   255,
      -1,   460,   461,    -1,   461,    -1,   462,    -1,   463,    -1,
       1,    -1,    90,   258,   155,   255,    -1,   157,   258,   155,
     255,    -1,    51,   257,   465,   256,   255,    -1,   465,   466,
      -1,   466,    -1,   467,    -1,     1,    -1,    90,   258,   155,
     255,    -1,    -1,    64,   469,   257,   474,   256,   255,    -1,
      -1,   186,   471,   258,   472,   255,    -1,   472,   259,   473,
      -1,   473,    -1,   160,    -1,   474,   475,    -1,   475,    -1,
     476,    -1,   477,    -1,   470,    -1,     1,    -1,   121,   258,
     155,   255,    -1,   157,   258,   155,   255,    -1,    65,   257,
     479,   256,   255,    -1,   479,   480,    -1,   480,    -1,   488,
      -1,   489,    -1,   491,    -1,   492,    -1,   493,    -1,   494,
      -1,   495,    -1,   496,    -1,   497,    -1,   498,    -1,   487,
      -1,   500,    -1,   501,    -1,   502,    -1,   503,    -1,   518,
      -1,   504,    -1,   506,    -1,   508,    -1,   507,    -1,   511,
      -1,   505,    -1,   512,    -1,   513,    -1,   514,    -1,   515,
      -1,   517,    -1,   516,    -1,   532,    -1,   519,    -1,   523,
      -1,   524,    -1,   528,    -1,   509,    -1,   510,    -1,   538,
      -1,   536,    -1,   537,    -1,   520,    -1,   490,    -1,   521,
      -1,   522,    -1,   539,    -1,   527,    -1,   499,    -1,   540,
      -1,   525,    -1,   526,    -1,   483,    -1,   486,    -1,   481,
      -1,   482,    -1,   484,    -1,   485,    -1,     1,    -1,    71,
     258,   132,   255,    -1,    72,   258,   132,   255,    -1,    12,
     258,   195,   255,    -1,   249,   258,   195,   255,    -1,   162,
     258,   264,   255,    -1,   183,   258,   195,   255,    -1,    92,
     258,   132,   255,    -1,    83,   258,   195,   255,    -1,    88,
     258,   195,   255,    -1,    42,   258,   195,   255,    -1,    52,
     258,   195,   255,    -1,     8,   258,   195,   255,    -1,   113,
     258,   264,   255,    -1,   112,   258,   132,   255,    -1,   106,
     258,   132,   255,    -1,     9,   258,   264,   255,    -1,   199,
     258,   264,   255,    -1,   198,   258,   264,   255,    -1,    76,
     258,   132,   255,    -1,    96,   258,   195,   255,    -1,    95,
     258,   155,   255,    -1,    89,   258,   195,   255,    -1,   254,
     258,   195,   255,    -1,   193,   258,   195,   255,    -1,   194,
     258,   195,   255,    -1,   192,   258,   195,   255,    -1,   192,
     258,   196,   255,    -1,   191,   258,   195,   255,    -1,   191,
     258,   196,   255,    -1,   147,   258,   264,   255,    -1,    19,
     258,   264,   255,    -1,   138,   258,   195,   255,    -1,   148,
     258,   264,   255,    -1,   187,   258,   195,   255,    -1,   129,
     258,   195,   255,    -1,   238,   258,   195,   255,    -1,   141,
     258,   195,   255,    -1,   116,   258,   155,   255,    -1,    87,
     258,   264,   255,    -1,    44,   258,   132,   255,    -1,   115,
     258,   132,   255,    -1,   181,   258,   155,   255,    -1,    32,
     258,   155,   255,    -1,    28,   258,   132,   255,    -1,   244,
     258,   195,   255,    -1,    46,   258,   155,   255,    -1,   151,
     258,   195,   255,    -1,    39,   258,   195,   255,    -1,   236,
     258,   264,   255,    -1,    -1,   143,   529,   258,   530,   255,
      -1,   530,   259,   531,    -1,   531,    -1,   202,    -1,   205,
      -1,   207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,
      -1,   227,    -1,   232,    -1,   230,    -1,   210,    -1,   226,
      -1,   228,    -1,   212,    -1,   235,    -1,   203,    -1,   204,
      -1,   215,    -1,    -1,   140,   533,   258,   534,   255,    -1,
     534,   259,   535,    -1,   535,    -1,   202,    -1,   205,    -1,
     207,    -1,   208,    -1,   211,    -1,   229,    -1,   225,    -1,
     227,    -1,   232,    -1,   230,    -1,   210,    -1,   226,    -1,
     228,    -1,   212,    -1,   235,    -1,   203,    -1,   204,    -1,
     215,    -1,   117,   258,   132,   255,    -1,   118,   258,   132,
     255,    -1,    33,   258,   132,   255,    -1,   206,   258,   266,
     255,    -1,    43,   258,   195,   255,    -1,    -1,    67,   542,
     257,   543,   256,   255,    -1,   543,   544,    -1,   544,    -1,
     545,    -1,   546,    -1,   547,    -1,   551,    -1,   552,    -1,
     553,    -1,     1,    -1,    48,   258,   195,   255,    -1,    45,
     258,   264,   255,    -1,    -1,   104,   548,   258,   549,   255,
      -1,   549,   259,   550,    -1,   550,    -1,   197,    -1,    11,
      -1,   243,   258,   155,   255,    -1,   121,   258,   155,   255,
      -1,    -1,     4,   554,   258,   555,   255,    -1,   555,   259,
     556,    -1,   556,    -1,   197,    -1,    11,    -1,    22,   257,
     558,   256,   255,    -1,   558,   559,    -1,   559,    -1,   561,
      -1,   562,    -1,   563,    -1,   564,    -1,   570,    -1,   565,
      -1,   566,    -1,   567,    -1,   568,    -1,   569,    -1,   571,
      -1,   572,    -1,   573,    -1,   560,    -1,   574,    -1,   575,
      -1,   576,    -1,   577,    -1,     1,    -1,   165,   258,   195,
     255,    -1,    41,   258,   195,   255,    -1,   245,   258,   195,
     255,    -1,   246,   258,   195,   255,    -1,   247,   258,   195,
     255,    -1,    97,   258,   264,   255,    -1,    98,   258,   264,
     255,    -1,   144,   258,   195,   255,    -1,   108,   258,   132,
     255,    -1,   156,   258,   195,   255,    -1,   107,   258,   132,
     255,    -1,    35,   258,   132,   255,    -1,    34,   258,   132,
     255,    -1,   127,   258,   195,   255,    -1,   128,   258,   195,
     255,    -1,    13,   258,   195,   255,    -1,   145,   258,   132,
     255,    -1,   146,   258,   264,   255,    -1,   179,   257,   579,
     256,   255,    -1,   579,   580,    -1,   580,    -1,   581,    -1,
     582,    -1,   584,    -1,   586,    -1,   585,    -1,   583,    -1,
     587,    -1,     1,    -1,    55,   258,   195,   255,    -1,    82,
     258,   195,   255,    -1,    79,   258,   155,   255,    -1,   101,
     258,   264,   255,    -1,    77,   258,   195,   255,    -1,    40,
     258,   195,   255,    -1,    81,   258,   195,   255,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   392,   392,   393,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   421,   421,   422,   426,
     430,   434,   438,   442,   448,   448,   449,   450,   451,   452,
     459,   462,   462,   463,   463,   463,   465,   482,   493,   496,
     496,   498,   498,   498,   499,   499,   500,   500,   501,   502,
     502,   503,   503,   506,   540,   600,   614,   632,   641,   655,
     664,   692,   722,   745,   795,   797,   797,   798,   798,   798,
     799,   801,   810,   819,   832,   834,   834,   837,   837,   837,
     838,   839,   839,   840,   840,   841,   841,   842,   842,   843,
     846,   850,   854,   861,   868,   875,   882,   889,   896,   903,
     910,   914,   918,   922,   926,   930,   934,   940,   950,   949,
    1043,  1043,  1044,  1044,  1045,  1045,  1045,  1045,  1045,  1046,
    1047,  1047,  1047,  1048,  1048,  1048,  1049,  1049,  1049,  1050,
    1050,  1050,  1050,  1051,  1051,  1052,  1054,  1066,  1078,  1097,
    1109,  1120,  1162,  1171,  1182,  1193,  1204,  1215,  1226,  1237,
    1248,  1259,  1270,  1281,  1292,  1303,  1314,  1326,  1325,  1329,
    1329,  1330,  1331,  1333,  1340,  1347,  1354,  1361,  1368,  1375,
    1382,  1389,  1396,  1403,  1410,  1417,  1424,  1431,  1438,  1452,
    1451,  1493,  1493,  1495,  1495,  1496,  1496,  1497,  1497,  1498,
    1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,  1510,
    1519,  1528,  1534,  1540,  1546,  1552,  1558,  1564,  1570,  1576,
    1582,  1588,  1594,  1604,  1603,  1620,  1619,  1623,  1623,  1624,
    1628,  1634,  1634,  1635,  1635,  1635,  1635,  1635,  1637,  1639,
    1639,  1641,  1656,  1678,  1687,  1700,  1699,  1768,  1768,  1769,
    1769,  1769,  1769,  1769,  1770,  1770,  1771,  1771,  1771,  1772,
    1772,  1773,  1773,  1773,  1774,  1774,  1776,  1795,  1808,  1819,
    1828,  1840,  1839,  1843,  1843,  1844,  1845,  1847,  1855,  1862,
    1869,  1876,  1883,  1890,  1897,  1904,  1911,  1920,  1931,  1942,
    1953,  1964,  1975,  1987,  2006,  2016,  2025,  2041,  2040,  2056,
    2056,  2057,  2057,  2057,  2057,  2059,  2068,  2083,  2097,  2096,
    2112,  2112,  2113,  2113,  2113,  2113,  2115,  2124,  2133,  2132,
    2138,  2138,  2139,  2143,  2147,  2151,  2155,  2159,  2163,  2167,
    2171,  2175,  2179,  2189,  2188,  2205,  2205,  2206,  2206,  2206,
    2208,  2215,  2214,  2220,  2220,  2221,  2225,  2229,  2233,  2237,
    2241,  2245,  2249,  2253,  2257,  2261,  2271,  2270,  2420,  2420,
    2421,  2421,  2422,  2422,  2422,  2422,  2423,  2423,  2424,  2424,
    2425,  2425,  2425,  2426,  2426,  2426,  2427,  2427,  2427,  2428,
    2428,  2431,  2443,  2455,  2464,  2490,  2508,  2526,  2532,  2536,
    2544,  2554,  2553,  2557,  2557,  2558,  2559,  2561,  2568,  2579,
    2586,  2593,  2600,  2610,  2651,  2662,  2673,  2688,  2699,  2712,
    2725,  2734,  2770,  2769,  2831,  2830,  2834,  2834,  2835,  2841,
    2841,  2842,  2842,  2842,  2842,  2844,  2860,  2870,  2869,  2891,
    2891,  2892,  2892,  2892,  2894,  2903,  2915,  2917,  2917,  2918,
    2918,  2920,  2942,  2941,  2983,  2982,  2986,  2986,  2987,  2993,
    2993,  2994,  2994,  2994,  2994,  2996,  3002,  3011,  3014,  3014,
    3015,  3015,  3015,  3016,  3016,  3017,  3017,  3018,  3018,  3019,
    3019,  3020,  3020,  3021,  3021,  3022,  3022,  3023,  3023,  3024,
    3024,  3025,  3025,  3026,  3026,  3027,  3027,  3028,  3028,  3029,
    3029,  3030,  3030,  3031,  3031,  3032,  3032,  3033,  3033,  3034,
    3034,  3035,  3036,  3036,  3037,  3037,  3038,  3038,  3039,  3039,
    3040,  3040,  3041,  3041,  3042,  3047,  3052,  3057,  3062,  3067,
    3072,  3077,  3082,  3087,  3092,  3097,  3102,  3107,  3112,  3117,
    3122,  3127,  3132,  3138,  3149,  3154,  3163,  3168,  3173,  3178,
    3183,  3186,  3191,  3194,  3199,  3204,  3209,  3214,  3219,  3224,
    3229,  3234,  3239,  3250,  3255,  3260,  3265,  3274,  3306,  3324,
    3329,  3338,  3343,  3348,  3354,  3353,  3358,  3358,  3359,  3362,
    3365,  3368,  3371,  3374,  3377,  3380,  3383,  3386,  3389,  3392,
    3395,  3398,  3401,  3404,  3407,  3410,  3416,  3415,  3420,  3420,
    3421,  3424,  3427,  3430,  3433,  3436,  3439,  3442,  3445,  3448,
    3451,  3454,  3457,  3460,  3463,  3466,  3469,  3472,  3477,  3482,
    3487,  3492,  3497,  3506,  3505,  3531,  3531,  3532,  3532,  3533,
    3534,  3535,  3536,  3537,  3540,  3546,  3553,  3552,  3557,  3557,
    3558,  3562,  3568,  3587,  3597,  3596,  3639,  3639,  3640,  3644,
    3653,  3656,  3656,  3657,  3657,  3657,  3658,  3658,  3659,  3659,
    3660,  3660,  3661,  3661,  3662,  3663,  3664,  3664,  3665,  3665,
    3666,  3666,  3669,  3674,  3679,  3684,  3689,  3694,  3699,  3704,
    3709,  3714,  3719,  3724,  3729,  3734,  3739,  3744,  3749,  3754,
    3762,  3765,  3765,  3766,  3766,  3766,  3767,  3768,  3769,  3769,
    3770,  3773,  3779,  3785,  3794,  3808,  3814,  3820
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN", 
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", 
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", 
  "KBYTES", "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", 
  "CAN_IDLE", "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", 
  "CIPHER_PREFERENCE", "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", 
  "CONNECT", "CONNECTFREQ", "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", 
  "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT", 
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", 
  "DISABLE_AUTH", "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS", 
  "DISABLE_REMOTE_COMMANDS", "DOT_IN_IP6_ADDR", "DOTS_IN_IDENT", 
  "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE", "ENCRYPTED", 
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME", 
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
  "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", 
  "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH", "TREJECT_HOLD_TIME", 
  "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS", "RESTRICTED", 
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", 
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", 
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", 
  "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", 
  "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY", 
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", 
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", 
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", 
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE", "T_EXTERNAL", 
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOGPATH", 
  "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR", "T_L_INFO", "T_L_NOTICE", 
  "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", 
  "T_REJ", "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UNAUTH", 
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
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", 
  "admin_items", "admin_item", "admin_name", "admin_email", 
  "admin_description", "logging_entry", "logging_items", "logging_item", 
  "logging_path", "logging_oper_log", "logging_fuserlog", 
  "logging_ffailed_operlog", "logging_foperlog", "logging_foperspylog", 
  "logging_fglinelog", "logging_fklinelog", "logging_ioerrlog", 
  "logging_killlog", "logging_log_level", "logging_use_logging", 
  "oper_entry", "@1", "oper_name_b", "oper_items", "oper_item", 
  "oper_name", "oper_name_t", "oper_user", "oper_password", 
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class", 
  "oper_global_kill", "oper_remote", "oper_remoteban", "oper_kline", 
  "oper_xline", "oper_unkline", "oper_gline", "oper_nick_changes", 
  "oper_die", "oper_rehash", "oper_admin", "oper_hidden_admin", 
  "oper_hidden_oper", "oper_operwall", "oper_flags", "@2", 
  "oper_flags_items", "oper_flags_item", "oper_flags_item_atom", 
  "class_entry", "@3", "class_name_b", "class_items", "class_item", 
  "class_name", "class_name_t", "class_ping_time", "class_ping_warning", 
  "class_number_per_ip", "class_connectfreq", "class_max_number", 
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq", 
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6", 
  "class_number_per_cidr", "listen_entry", "@4", "listen_flags", "@5", 
  "listen_flags_items", "listen_flags_item", "listen_items", 
  "listen_item", "listen_port", "port_items", "port_item", 
  "listen_address", "listen_host", "auth_entry", "@6", "auth_items", 
  "auth_item", "auth_user", "auth_passwd", "auth_spoof_notice", 
  "auth_class", "auth_encrypted", "auth_flags", "@7", "auth_flags_items", 
  "auth_flags_item", "auth_flags_item_atom", "auth_kline_exempt", 
  "auth_need_ident", "auth_exceed_limit", "auth_can_flood", 
  "auth_no_tilde", "auth_gline_exempt", "auth_spoof", "auth_redir_serv", 
  "auth_redir_port", "auth_need_password", "resv_entry", "@8", 
  "resv_items", "resv_item", "resv_creason", "resv_channel", "resv_nick", 
  "shared_entry", "@9", "shared_items", "shared_item", "shared_name", 
  "shared_user", "shared_type", "@10", "shared_types", "shared_type_item", 
  "cluster_entry", "@11", "cluster_items", "cluster_item", "cluster_name", 
  "cluster_type", "@12", "cluster_types", "cluster_type_item", 
  "connect_entry", "@13", "connect_name_b", "connect_items", 
  "connect_item", "connect_name", "connect_name_t", "connect_host", 
  "connect_vhost", "connect_send_password", "connect_accept_password", 
  "connect_port", "connect_aftype", "connect_fakename", "connect_flags", 
  "@14", "connect_flags_items", "connect_flags_item", 
  "connect_flags_item_atom", "connect_rsa_public_key_file", 
  "connect_encrypted", "connect_cryptlink", "connect_compressed", 
  "connect_auto", "connect_hub_mask", "connect_leaf_mask", 
  "connect_class", "connect_cipher_preference", "kill_entry", "@15", 
  "kill_type", "@16", "kill_type_items", "kill_type_item", "kill_items", 
  "kill_item", "kill_user", "kill_reason", "deny_entry", "@17", 
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry", 
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "@18", 
  "gecos_flags", "@19", "gecos_flags_items", "gecos_flags_item", 
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason", 
  "general_entry", "general_items", "general_item", 
  "general_gline_min_cidr", "general_gline_min_cidr6", 
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
  "@20", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@21", 
  "umode_items", "umode_item", "general_min_nonwildcard", 
  "general_min_nonwildcard_simple", "general_default_floodcount", 
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@22", 
  "gline_items", "gline_item", "gline_enable", "gline_duration", 
  "gline_logging", "@23", "gline_logging_types", 
  "gline_logging_type_item", "gline_user", "gline_server", "gline_action", 
  "@24", "gdeny_types", "gdeny_type_item", "channel_entry", 
  "channel_items", "channel_item", "channel_restrict_channels", 
  "channel_disable_local_channels", "channel_use_except", 
  "channel_use_invex", "channel_use_knock", "channel_knock_delay", 
  "channel_knock_delay_channel", "channel_invite_ops_only", 
  "channel_max_chans_per_user", "channel_quiet_on_ban", 
  "channel_max_bans", "channel_default_split_user_count", 
  "channel_default_split_server_count", "channel_no_create_on_split", 
  "channel_no_join_on_split", "channel_burst_topicwho", 
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry", 
  "serverhide_items", "serverhide_item", "serverhide_flatten_links", 
  "serverhide_hide_servers", "serverhide_hidden_name", 
  "serverhide_links_delay", "serverhide_hidden", 
  "serverhide_disable_hidden", "serverhide_hide_server_ips", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
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
     505,   506,   507,   508,   509,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   265,   265,   266,   266,   266,   266,
     267,   268,   268,   269,   269,   269,   270,   271,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   287,   288,   288,   288,
     288,   289,   290,   291,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   305,   305,   305,   305,   305,   305,   306,   308,   307,
     309,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   334,   333,   335,
     335,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     337,   337,   337,   337,   337,   337,   337,   337,   337,   339,
     338,   340,   340,   341,   341,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   358,   357,   360,   359,   361,   361,   362,
     362,   363,   363,   364,   364,   364,   364,   364,   365,   366,
     366,   367,   367,   368,   369,   371,   370,   372,   372,   373,
     373,   373,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,   373,   373,   374,   375,   376,   377,
     378,   380,   379,   381,   381,   382,   382,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   395,   394,   396,
     396,   397,   397,   397,   397,   398,   399,   400,   402,   401,
     403,   403,   404,   404,   404,   404,   405,   406,   408,   407,
     409,   409,   410,   410,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   412,   411,   413,   413,   414,   414,   414,
     415,   417,   416,   418,   418,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   421,   420,   422,   422,
     423,   423,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   432,
     433,   435,   434,   436,   436,   437,   437,   438,   438,   438,
     438,   438,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   449,   448,   451,   450,   452,   452,   453,   454,
     454,   455,   455,   455,   455,   456,   457,   459,   458,   460,
     460,   461,   461,   461,   462,   463,   464,   465,   465,   466,
     466,   467,   469,   468,   471,   470,   472,   472,   473,   474,
     474,   475,   475,   475,   475,   476,   477,   478,   479,   479,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   506,   507,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   529,   528,   530,   530,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   533,   532,   534,   534,
     535,   535,   535,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,   535,   535,   535,   535,   535,   536,   537,
     538,   539,   540,   542,   541,   543,   543,   544,   544,   544,
     544,   544,   544,   544,   545,   546,   548,   547,   549,   549,
     550,   550,   551,   552,   554,   553,   555,   555,   556,   556,
     557,   558,   558,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   579,   580,   580,   580,   580,   580,   580,   580,
     580,   581,   582,   583,   584,   585,   586,   587
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
       1,     1,     1,     1,     1,     2,     4,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     6,     0,     5,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     4,     3,
       1,     1,     3,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     7,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
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
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     0,     5,     3,     1,     1,     1,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
       2,     0,     1,     0,     0,     0,   189,   356,   427,     0,
     442,     0,   613,   245,   412,   223,     0,     0,   118,   297,
       0,     0,   308,   333,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   191,
     358,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   661,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   642,   656,   643,   644,
     645,   646,   648,   649,   650,   651,   652,   647,   653,   654,
     655,   657,   658,   659,   660,   210,     0,   192,   382,     0,
     359,     0,   440,     0,     0,   438,   439,     0,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   586,     0,   564,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   459,   510,   511,   508,   512,   513,
     509,   470,   460,   461,   499,   462,   463,   464,   465,   466,
     467,   468,   469,   504,   471,   472,   473,   474,   476,   481,
     477,   479,   478,   493,   494,   480,   482,   483,   484,   485,
     487,   486,   475,   489,   498,   500,   501,   490,   491,   506,
     507,   503,   492,   488,   496,   497,   495,   502,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      91,    98,    92,    96,    93,    94,    97,    95,    89,    90,
       0,     0,     0,     0,    42,    43,    44,   147,     0,   121,
       0,   690,     0,     0,     0,     0,     0,     0,     0,     0,
     682,   683,   684,   688,   685,   687,   686,   689,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    61,    58,    51,    60,    54,    55,    56,    52,
      59,    57,    53,     0,     0,    80,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,     0,     0,   433,     0,     0,     0,   430,   431,   432,
       0,     0,   437,   454,     0,     0,   444,   453,     0,   450,
     451,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   458,   623,   634,
       0,     0,   626,     0,     0,     0,   616,   617,   618,   619,
     620,   621,   622,     0,     0,     0,     0,     0,   271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   248,   249,   250,   259,   251,   264,   252,   253,   254,
     255,   262,   256,   257,   258,   260,   261,   263,   424,     0,
     414,     0,   423,     0,   420,   421,   422,     0,   225,     0,
       0,     0,   234,     0,   232,   233,   235,   236,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    45,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,   300,   301,   302,   303,     0,     0,
       0,     0,     0,     0,     0,     0,   681,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   318,     0,     0,   311,   312,   313,   314,
       0,     0,   341,     0,   336,   337,   338,     0,     0,     0,
      74,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,   195,   198,   199,
     201,   202,   203,   204,   205,   206,   207,   196,   197,   200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     391,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     361,   362,   363,   364,   365,   366,   368,   367,   369,   370,
     378,   375,   377,   376,   374,   371,   372,   373,   379,     0,
       0,     0,   429,     0,   436,     0,     0,     0,     0,   449,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,   457,     0,     0,
       0,     0,     0,     0,     0,   615,   265,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,     0,     0,     0,     0,   419,
     237,     0,     0,     0,     0,     0,   231,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,     0,    40,     0,
       0,     0,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,   126,   142,   143,   129,   130,
     131,   137,   132,   133,   134,   135,   136,   138,   139,   140,
     127,   128,   141,   144,   304,     0,     0,     0,     0,   299,
       0,     0,     0,     0,     0,     0,     0,   680,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     315,     0,     0,     0,     0,   310,   339,     0,     0,     0,
     335,    83,    82,    81,   677,   674,   673,   663,    26,    26,
      26,    26,    26,    28,    27,   667,   668,   672,   670,   675,
     676,   669,   678,   679,   671,   662,   664,   665,   666,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   380,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   360,     0,     0,   428,   441,
       0,     0,     0,   443,   526,   530,   517,   545,   558,   557,
     610,   562,   524,   612,   554,   560,   525,   515,   516,   533,
     522,   553,   523,   536,   521,   535,   534,   529,   528,   527,
     555,   552,   608,   609,   549,   546,   590,   605,   606,   591,
     592,   593,   600,   594,   603,   607,   596,   601,   597,   602,
     595,   599,   598,   604,     0,   589,   551,   568,   583,   584,
     569,   570,   571,   578,   572,   581,   585,   574,   579,   575,
     580,   573,   577,   576,   582,     0,   567,   544,   547,   561,
     519,   556,   520,   548,   542,   543,   540,   541,   538,   539,
     532,   531,    34,    34,    34,    36,    35,   611,   563,   550,
     559,   518,   537,     0,     0,     0,     0,     0,     0,   614,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,     0,     0,
     413,     0,     0,     0,   241,     0,   240,   224,   103,   109,
     107,   106,   108,   104,   105,   102,   110,   116,   111,   115,
     113,   114,   112,   101,   100,   117,    46,    47,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,     0,     0,     0,   298,   696,   691,   695,   693,
     697,   692,   694,    67,    73,    65,    69,    68,    64,    63,
      66,    72,    70,    71,     0,     0,     0,   309,     0,     0,
     334,    29,    30,    31,    32,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   357,
     434,   435,   455,   456,   448,     0,   447,   587,     0,   565,
       0,    37,    38,    39,   639,   638,     0,   637,   625,   624,
     631,   630,     0,   629,   633,   632,   290,   269,   270,   289,
     281,   282,   278,   284,   280,   279,   286,   283,     0,   285,
     277,     0,   274,   276,   292,   288,   287,   296,   291,   267,
     295,   294,   293,   268,   266,   426,   418,     0,   417,   425,
     230,   229,     0,   228,   244,   243,     0,   238,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   306,   307,   305,   316,   322,   328,   332,   331,   330,
     327,   323,   326,   329,   324,   325,     0,   321,   317,   340,
     345,   351,   355,   354,   353,   350,   346,   349,   352,   347,
     348,     0,   344,   220,   221,   214,   216,   218,   217,   215,
     209,   222,   213,   211,   212,   219,   386,   388,   389,   407,
     411,   410,   406,   405,   404,   390,   400,   401,   398,   399,
     397,     0,   402,     0,   394,   396,   383,   408,   409,   381,
     387,   403,   385,   384,   445,     0,   588,   566,   635,     0,
     627,     0,   275,   272,     0,   415,     0,   226,     0,   242,
     239,   163,   152,   161,   150,   181,   179,   188,   178,   173,
     182,   186,   175,   183,     0,   185,   180,   174,   187,   184,
     176,   177,     0,   170,   172,   159,   153,   164,   165,   156,
     146,   160,   149,   162,   154,   155,   151,   166,   158,   148,
     157,   319,     0,   342,     0,   395,   392,     0,   446,   636,
     628,   273,   416,   227,   171,   168,     0,   320,   343,   393,
     169
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     1,    24,   883,   884,  1035,  1036,    25,   273,   274,
     275,   276,    26,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,    27,    71,    72,    73,
      74,    75,    28,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,    29,    61,   278,
     811,   812,   813,   279,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   824,   825,   826,   827,   828,   829,
     830,   831,   832,   833,  1103,  1392,  1393,  1394,    30,    49,
     116,   605,   606,   607,   117,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,    31,    58,   492,
     761,  1252,  1253,   493,   494,   495,  1075,  1076,   496,   497,
      32,    56,   460,   461,   462,   463,   464,   465,   466,   467,
     741,  1231,  1232,  1233,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,    33,    62,   523,   524,   525,   526,
     527,    34,    65,   555,   556,   557,   558,   559,   862,  1296,
    1297,    35,    66,   563,   564,   565,   566,   868,  1311,  1312,
      36,    50,   119,   639,   640,   641,   120,   642,   643,   644,
     645,   646,   647,   648,   649,   925,  1343,  1344,  1345,   650,
     651,   652,   653,   654,   655,   656,   657,   658,    37,    57,
     482,   756,  1247,  1248,   483,   484,   485,   486,    38,    51,
     356,   357,   358,   359,    39,   124,   125,   126,    40,    53,
     367,   667,  1195,  1196,   368,   369,   370,   371,    41,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   406,
    1015,  1016,   233,   404,   994,   995,   234,   235,   236,   237,
     238,    42,    55,   435,   436,   437,   438,   439,   731,  1212,
    1213,   440,   441,   442,   728,  1206,  1207,    43,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,   289,
     290,   291,   292,   293,   294,   295,   296,   297
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -848
static const short yypact[] =
{
    -848,   775,  -848,  -231,  -241,  -221,  -848,  -848,  -848,  -214,
    -848,  -199,  -848,  -848,  -848,  -848,  -186,  -178,  -848,  -848,
    -175,  -167,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,   245,   757,   -56,
     -42,  -137,     3,  -127,   476,  -114,   -91,   -90,   -76,   694,
      22,    -9,   -75,   420,   345,   -51,   -38,   -34,   -27,   -21,
     -20,    10,  -848,  -848,  -848,  -848,  -848,   -14,   -10,    -6,
      -1,    15,    29,    31,    32,    37,    51,    52,    54,    57,
      63,    72,    76,    79,    80,   152,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,    56,  -848,  -848,    83,
    -848,    55,  -848,    84,    19,  -848,  -848,   215,  -848,    85,
      87,    89,    92,    93,    94,   105,   111,   112,   120,   121,
     123,   127,   129,   132,   134,   135,   142,   147,   156,   157,
     159,   161,   162,   166,   167,   168,   169,   176,   177,   180,
     181,  -848,   182,  -848,   183,   184,   188,   189,   191,   193,
     199,   200,   201,   203,   209,   212,   213,   214,   216,   218,
     220,   222,   223,     9,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   113,
     334,    28,   290,    17,   224,   228,   229,   231,   232,   233,
     238,   240,   242,   247,   248,   252,   117,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
     109,   253,   259,    14,  -848,  -848,  -848,  -848,   114,  -848,
     261,  -848,   268,   272,   277,   278,   279,   280,   284,   276,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   136,   285,
     286,   287,   288,   291,   292,   293,   303,   304,   308,   312,
     283,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,   190,    18,  -848,   131,   255,   318,   305,
    -848,   346,   316,   442,   383,   447,   447,   451,   454,   392,
     395,   402,   466,   447,   404,   405,   407,   408,   409,   352,
    -848,   814,   682,  -848,   351,   354,    13,  -848,  -848,  -848,
     455,   365,  -848,  -848,   363,   364,  -848,  -848,    11,  -848,
    -848,  -848,   431,   447,   435,   447,   499,   477,   501,   440,
     441,   444,   505,   485,   446,   510,   513,   515,   453,   447,
     459,   460,   524,   509,   470,   539,   544,   447,   546,   525,
     547,   549,   489,   491,   429,   494,   432,   447,   447,   496,
     447,   538,   502,   507,  -146,  -119,   508,   516,   447,   447,
     562,   447,   520,   522,   523,   526,   445,  -848,  -848,  -848,
     452,   461,  -848,   464,   465,   106,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,   449,   468,   469,   474,   479,  -848,   480,
     481,   484,   488,   504,   506,   511,   514,   521,   527,   528,
     273,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   530,
    -848,   531,  -848,    12,  -848,  -848,  -848,   473,  -848,   532,
     536,   537,  -848,     5,  -848,  -848,  -848,  -848,  -848,   569,
     579,   594,   604,   608,   610,   612,   616,   650,   618,   619,
     583,   529,  -848,  -848,   626,   628,   541,  -848,   580,   545,
     550,   552,   554,    38,  -848,  -848,  -848,  -848,   607,   621,
     622,   652,   623,   624,   447,   558,  -848,  -848,   659,   625,
     666,   669,   670,   672,   679,   680,   673,   686,   688,   590,
    -848,   591,   589,  -848,   593,     8,  -848,  -848,  -848,  -848,
     597,   595,  -848,   133,  -848,  -848,  -848,   601,   602,   603,
    -848,   606,   620,   627,   631,   381,   632,   635,   639,   641,
     642,   643,   644,   645,   649,   653,   656,   660,   661,   662,
    -848,   665,   605,   647,   668,   671,   675,   676,   683,   689,
     692,   695,   698,   699,   700,   302,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
     685,   703,   705,   706,   710,   713,   714,   715,   716,   721,
    -848,   722,   723,   724,   725,   726,   727,   728,   729,   275,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   693,
     704,   697,  -848,   734,  -848,   707,   719,   737,   739,  -848,
     741,   742,   745,   754,   761,   762,   764,   765,   766,   767,
     768,   769,   770,   771,   772,   779,   781,   782,   785,   786,
     792,   795,   799,   800,   802,   804,   805,   807,   808,   809,
     810,   817,   803,   819,   841,   820,   822,   823,   824,   825,
     826,   827,   828,   829,   830,   831,   832,   833,   834,   835,
      30,   836,   837,   838,   839,   840,   842,  -848,   843,   447,
     681,   844,   752,   759,   845,  -848,  -848,   732,   776,   735,
     743,   846,   749,   797,   901,   903,   904,   857,   746,   948,
     950,   911,   952,   853,  -848,   954,   852,   956,   858,  -848,
    -848,   854,   959,   960,   748,   861,  -848,   862,   863,   864,
     865,   866,   867,   869,   870,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,  -848,   882,   883,  -848,   884,
     885,   886,   887,   888,  -848,   889,   890,   891,   892,   893,
     894,   895,   896,   897,   898,   899,   900,   902,   905,   906,
     907,    62,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,   968,   971,   985,   912,  -848,
     913,   914,   915,   916,   917,   918,   919,  -848,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,  -848,
    -848,   986,   908,   987,   931,  -848,  -848,  1004,   932,   933,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   447,   447,
     447,   447,   447,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
     751,  1029,   447,  1030,  1055,  1057,  1059,  1037,  1061,  1062,
     447,   447,   562,   940,  -848,  -848,  1041,   -77,  1002,  1043,
    1044,  1005,  1006,  1007,  1048,   946,  1050,  1051,  1052,  1053,
    1077,  1056,  1058,  1060,   955,  -848,   957,   961,  -848,  -848,
     962,   963,  1054,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -191,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -190,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,   562,   562,   562,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,    -8,   964,   965,    16,   966,   967,  -848,
     969,   970,   972,   973,   868,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,  -848,   988,  1063,   989,
    -848,   -47,   990,   991,  1026,  -189,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  1045,
    1086,  1047,  1064,   992,  1065,  1066,  1067,  1068,  1069,  1092,
    1070,  1093,  1071,  1072,  1073,  1094,  1074,  1075,  1096,  1076,
     997,  -848,   998,   999,  1000,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  1001,   410,  1003,  -848,  1017,   736,
    -848,  -848,  -848,  -848,  -848,  -848,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1027,  1028,  1031,  1032,  1033,  -848,
    1034,  1035,  1036,  1038,  1039,  1040,  1042,  1046,  1049,  1078,
     208,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1087,  -848,
    -848,  -848,  -848,  -848,  -848,  -181,  -848,  -848,   803,  -848,
     841,  -848,  -848,  -848,  -848,  -848,  -168,  -848,  -848,  -848,
    -848,  -848,  -153,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,   871,  -848,
    -848,  -147,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -136,  -848,  -848,
    -848,  -848,  -111,  -848,  -848,  -848,  1125,  -848,   748,  1088,
    1089,  1090,  1091,   535,  1095,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,   -50,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,   -31,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,    -5,  -848,   -26,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  1054,  -848,  -848,  -848,    -8,
    -848,    16,  -848,  -848,   868,  -848,  1063,  -848,   -47,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,   667,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,   -19,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,   410,  -848,   736,  -848,  -848,   208,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,   535,  -848,  -848,  -848,
    -848
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -848,  -848,  -848,  -847,  -335,  -791,  -418,  -848,  -848,  1008,
    -848,  -848,  -848,  -848,   571,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  1213,  -848,
    -848,  -848,  -848,  -848,  1112,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,   487,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -141,   -92,  -848,  -848,
    -848,  -848,   691,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,   -69,  -848,   812,  -848,  -848,    42,  -848,  -848,
    -848,  -848,  -848,   847,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,   -62,    75,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,   783,  -848,  -848,
    -848,  -848,  -848,  -848,   753,  -848,  -848,  -848,  -848,  -848,
    -103,  -848,  -848,  -848,   747,  -848,  -848,  -848,  -848,  -102,
    -848,  -848,  -848,  -848,   674,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -106,   -25,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,   -52,  -848,   848,  -848,  -848,  -848,  -848,
    -848,   993,  -848,  -848,  -848,  -848,  1191,  -848,  -848,  -848,
    -848,  -848,  -848,   -37,  -848,   949,  -848,  -848,  -848,  -848,
    1136,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,   122,  -848,  -848,  -848,   125,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,   934,  -848,  -848,  -848,  -848,  -848,
     -41,  -848,  -848,  -848,  -848,  -848,   -35,  -848,  -848,  1226,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,  -848,
    1113,  -848,  -848,  -848,  -848,  -848,  -848,  -848
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, parse error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
{
     576,   577,   721,  1204,   122,  1336,   487,  1337,   584,   551,
     128,    67,   363,   478,   353,   270,    47,   129,   130,   560,
     122,   131,  1338,   270,    45,    46,  1339,  1210,   132,   478,
    1250,  1151,  1152,  1153,  1154,  1155,    48,   133,   671,   519,
     673,   134,   135,    52,  1032,  1033,  1034,    68,   136,   712,
     713,   137,   138,   139,   687,   140,   353,    69,    54,   488,
     520,   141,   695,   789,  1197,  1199,  1257,   790,  1198,  1200,
    1258,    59,   705,   706,  1354,   708,   714,   715,  1355,    60,
     142,   143,    63,   718,   719,   144,   722,  1358,   791,   489,
      64,  1359,   145,   123,  1340,   490,   146,   147,   148,   115,
     792,   149,  1360,   354,   150,   151,  1361,   428,  1363,   123,
     429,   793,  1364,   118,   428,   152,   794,   429,   243,  1365,
     121,   153,   154,  1366,   155,   156,   157,   158,   795,   552,
     127,    70,   364,   271,   560,   796,  1171,  1172,   159,   561,
     797,   271,   798,   239,  1367,   354,   277,   160,  1368,   161,
     162,   430,   163,    76,   431,   799,   164,   165,   430,   491,
     166,   431,   720,   521,   272,    77,   240,   241,   365,   479,
     355,   167,   272,   244,   245,   246,   247,   248,   249,   250,
     251,   242,   280,   800,  1251,   479,    78,    79,   801,  1205,
     168,   551,   169,    80,   553,   522,   170,   366,   480,   846,
     171,   172,   173,   174,   562,  1411,   323,   175,   176,  1412,
     432,   802,   355,  1211,   480,   177,   363,   432,  1336,   324,
    1337,   325,   252,   803,  1413,   804,   805,   433,  1414,  1416,
     806,   326,  1342,  1417,   433,  1338,  1425,   327,   328,  1339,
    1426,  1201,  1202,  1203,   331,   178,    67,   179,   332,    81,
      82,   554,   333,   180,   561,   481,   253,   334,   181,    83,
      84,   765,   519,   182,   864,   426,   329,   668,   758,   661,
     516,   481,   498,   335,   443,   361,   620,   281,   621,    85,
      86,   622,    68,   520,   298,   623,   567,   336,   807,   337,
     338,   487,    69,   444,   838,   339,    87,    88,    89,   445,
     624,   625,   626,   591,   808,   809,   627,  1340,    90,   340,
     341,   552,   342,   351,   810,   343,   282,    91,  1120,   562,
     299,   344,   446,   447,   628,   592,   593,   448,   629,   630,
     345,   283,   594,   254,   346,   443,   364,   347,   348,  1341,
     352,   449,   360,   372,   488,   373,   298,   374,   450,   434,
     375,   376,   377,   284,   444,   285,   434,   286,   287,   631,
     445,   632,   734,   378,   513,   255,    70,   451,   300,   379,
     380,   518,   365,   511,   489,   633,   553,   288,   381,   382,
     490,   383,   299,   446,   447,   384,   521,   385,   448,   869,
     386,   537,   387,   388,  1044,   452,   634,    92,    93,    94,
     389,   366,   449,   453,   301,   390,   302,   303,   349,   450,
     568,   595,   596,   597,   391,   392,   598,   393,   522,   394,
     395,   281,   454,   599,   396,   397,   398,   399,   451,   635,
     300,   455,   456,   554,   400,   401,   600,   601,   402,   403,
     405,   407,   408,   636,   491,  1342,   409,   410,   572,   411,
     304,   412,   305,   637,   602,   603,   452,   413,   414,   415,
     282,   416,   457,   458,   453,   306,   301,   417,   302,   303,
     418,   419,   420,   569,   421,   283,   422,   128,   423,   604,
     424,   425,   499,   454,   129,   130,   500,   501,   131,   502,
     503,   504,   455,   456,  1168,   132,   505,   284,   506,   285,
     507,   286,   287,  1285,   133,   508,   509,   307,   134,   135,
     510,   514,   304,   575,   305,   136,   459,   515,   137,   138,
     139,   288,   140,   457,   458,   638,   528,   306,   141,   753,
     529,   934,   535,   308,   309,   530,   531,   532,   533,   549,
    1375,   571,   534,   538,   539,   540,   541,   142,   143,   542,
     543,   544,   144,   878,   879,   880,   881,   882,   913,   145,
     570,   545,   546,   146,   147,   148,   547,  1158,   149,   307,
     548,   150,   151,  1376,   573,  1166,  1167,   459,   574,   575,
    1286,   789,   152,   578,  1377,   790,   579,   580,   153,   154,
     581,   155,   156,   157,   158,   308,   309,   582,   583,   585,
     586,  1378,   587,   588,   589,   159,   791,   590,  1379,   659,
     663,  1287,   660,  1380,   160,  1381,   161,   162,   792,   163,
     664,   665,   666,   164,   165,  1288,   670,   166,  1382,   793,
     672,   674,   675,   676,   794,   677,   678,   680,   167,   679,
     681,   682,   683,  1289,  1290,   684,   795,   685,   686,  1291,
    1292,  1293,  1294,   796,   688,   689,   690,   168,   797,   169,
     798,  1383,  1295,   170,   691,   692,  1384,   171,   172,   173,
     174,   693,  1375,   799,   175,   176,   694,  1385,   696,   698,
     697,   699,   177,   620,   700,   621,   701,   702,   622,   703,
     704,   707,   623,   709,   720,   243,  1386,   710,  1387,  1388,
     727,   800,   711,   716,   736,  1376,   801,   624,   625,   626,
     729,   717,   178,   627,   179,   723,  1377,   724,   725,   730,
     180,   726,   732,   733,   767,   181,   737,   738,   760,   802,
     182,   628,   739,  1378,   768,   629,   630,   740,   742,   743,
    1379,   803,   744,   804,   805,  1380,   745,  1381,   806,   769,
     244,   245,   246,   247,   248,   249,   250,   251,    76,   770,
    1382,  1389,   746,   771,   747,   772,   631,   773,   632,   748,
      77,   774,   749,   782,   783,     2,     3,  1390,   784,   750,
       4,   786,   633,   787,   785,   751,   752,  1391,   755,   757,
     762,    78,    79,  1383,   763,   764,   788,     5,    80,   252,
     834,     6,   840,   634,     7,   856,   807,   843,   835,  1385,
     836,     8,   837,   847,   848,   591,   841,   842,   844,   845,
     849,   850,   808,   809,   851,   852,     9,   853,  1386,  1300,
    1387,  1388,   810,   253,   854,   855,   635,   592,   593,    10,
      11,   857,    12,   858,   594,   859,   860,   861,   936,    13,
     636,   863,   866,   867,    81,    82,   871,   872,   873,   937,
     637,   874,   940,   900,    83,    84,    14,   775,   776,   777,
     778,   779,   780,   781,   941,   875,  1045,    15,  1061,    16,
    1074,   550,   876,  1156,    85,    86,   877,   885,  1220,  1221,
     886,  1220,  1221,  1389,   887,    17,   888,   889,   890,   891,
     892,    87,    88,    89,   893,   901,  1301,  1047,   894,  1390,
     254,   895,    18,    90,  1048,   896,   897,   898,  1222,  1391,
     899,  1222,    91,   595,   596,   597,   902,  1050,   598,   903,
    1052,  1051,   638,   904,   905,   599,  1223,  1302,  1053,  1223,
     915,   906,   255,  1224,  1055,    19,  1224,   907,   600,   601,
     908,  1303,   938,   909,    20,    21,   910,   911,   912,    22,
      23,   916,  1225,   917,   918,  1225,   602,   603,   919,  1304,
    1305,   920,   921,   922,   923,  1306,  1307,  1308,  1309,   924,
     926,   927,   928,   929,   930,   931,   932,   933,  1310,   939,
    1226,   604,  1056,  1226,   943,   942,   944,   945,  1227,  1228,
     946,  1227,    92,    93,    94,   976,   977,   978,   979,   947,
     980,   981,  1060,   982,   983,   984,   948,   949,   985,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   986,   987,
     988,   989,   990,   991,   959,   992,   960,   961,   993,  1229,
     962,   963,  1229,   997,   998,   999,  1000,   964,  1001,  1002,
     965,  1003,  1004,  1005,   966,   967,  1006,   968,  1230,   969,
     970,  1230,   971,   972,   973,   974,  1007,  1008,  1009,  1010,
    1011,  1012,   975,  1013,   996,  1017,  1014,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1037,  1038,  1039,  1040,  1041,  1057,  1042,  1058,  1059,
    1049,  1043,  1046,  1062,  1054,  1063,  1064,  1065,  1066,  1067,
    1068,  1069,  1071,  1070,  1072,  1073,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1122,  1084,  1085,  1123,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1124,  1144,  1146,  1099,  1100,  1101,  1102,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1148,
    1116,  1157,  1159,  1117,  1118,  1119,  1145,  1125,  1126,  1127,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1147,  1160,  1150,  1161,
    1149,  1162,  1163,  1164,  1165,  1169,  1170,  1173,  1174,  1175,
    1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,
    1189,  1186,  1190,  1187,  1194,  1188,  1191,  1192,  1193,  1208,
    1209,  1214,  1215,  1246,  1216,  1217,  1256,  1218,  1219,  1234,
    1235,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,
    1259,  1260,  1261,  1245,  1249,  1254,  1255,  1269,  1271,  1275,
    1263,  1278,  1280,  1281,  1282,  1283,  1284,  1369,  1298,  1262,
    1264,  1265,  1266,  1267,  1268,  1270,  1272,  1273,  1274,  1276,
    1277,  1279,  1299,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,   517,  1321,  1322,   330,  1430,  1323,  1324,  1325,  1326,
    1327,  1328,  1424,  1329,  1330,  1331,   914,  1332,  1121,  1423,
    1370,  1333,  1421,  1362,  1334,   766,   839,   754,   865,  1427,
     870,  1429,  1428,   935,  1422,   362,  1415,   669,  1418,   427,
    1420,   350,  1357,  1356,  1419,     0,     0,     0,     0,     0,
       0,   759,     0,  1335,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,     0,  1353,  1371,  1372,  1373,  1374,     0,     0,   662,
    1395,     0,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  1403,
    1404,  1405,  1406,  1407,  1408,  1409,  1410,     0,   512,   735,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536
};

static const short yycheck[] =
{
     335,   336,   420,    11,     1,    10,     1,    12,   343,     1,
       1,     1,     1,     1,     1,     1,   257,     8,     9,     1,
       1,    12,    27,     1,   255,   256,    31,    11,    19,     1,
      77,   878,   879,   880,   881,   882,   257,    28,   373,     1,
     375,    32,    33,   257,    14,    15,    16,    37,    39,   195,
     196,    42,    43,    44,   389,    46,     1,    47,   257,    54,
      22,    52,   397,     1,   255,   255,   255,     5,   259,   259,
     259,   257,   407,   408,   255,   410,   195,   196,   259,   257,
      71,    72,   257,   418,   419,    76,   421,   255,    26,    84,
     257,   259,    83,    90,    99,    90,    87,    88,    89,   155,
      38,    92,   255,    90,    95,    96,   259,     1,   255,    90,
       4,    49,   259,   155,     1,   106,    54,     4,     1,   255,
     257,   112,   113,   259,   115,   116,   117,   118,    66,   121,
     257,   121,   121,   119,     1,    73,   213,   214,   129,   121,
      78,   119,    80,   257,   255,    90,   155,   138,   259,   140,
     141,    45,   143,     1,    48,    93,   147,   148,    45,   154,
     151,    48,   132,   125,   150,    13,   257,   257,   157,   157,
     157,   162,   150,    56,    57,    58,    59,    60,    61,    62,
      63,   257,   257,   121,   231,   157,    34,    35,   126,   197,
     181,     1,   183,    41,   186,   157,   187,   186,   186,   534,
     191,   192,   193,   194,   186,   255,   257,   198,   199,   259,
     104,   149,   157,   197,   186,   206,     1,   104,    10,   257,
      12,   255,   105,   161,   255,   163,   164,   121,   259,   255,
     168,   258,   237,   259,   121,    27,   255,   258,   258,    31,
     259,  1032,  1033,  1034,   258,   236,     1,   238,   258,    97,
      98,   243,   258,   244,   121,   243,   139,   258,   249,   107,
     108,   256,     1,   254,   256,   256,   256,   256,   256,   256,
     256,   243,   255,   258,     1,   256,     1,     1,     3,   127,
     128,     6,    37,    22,     1,    10,   155,   258,   226,   258,
     258,     1,    47,    20,   256,   258,   144,   145,   146,    26,
      25,    26,    27,     1,   242,   243,    31,    99,   156,   258,
     258,   121,   258,   257,   252,   258,    40,   165,   256,   186,
      37,   258,    49,    50,    49,    23,    24,    54,    53,    54,
     258,    55,    30,   216,   258,     1,   121,   258,   258,   131,
     257,    68,   258,   258,    54,   258,     1,   258,    75,   243,
     258,   258,   258,    77,    20,    79,   243,    81,    82,    84,
      26,    86,   256,   258,   255,   248,   121,    94,    85,   258,
     258,   257,   157,   256,    84,   100,   186,   101,   258,   258,
      90,   258,    37,    49,    50,   258,   125,   258,    54,   256,
     258,   255,   258,   258,   729,   122,   121,   245,   246,   247,
     258,   186,    68,   130,   121,   258,   123,   124,   256,    75,
     155,   109,   110,   111,   258,   258,   114,   258,   157,   258,
     258,     1,   149,   121,   258,   258,   258,   258,    94,   154,
      85,   158,   159,   243,   258,   258,   134,   135,   258,   258,
     258,   258,   258,   168,   154,   237,   258,   258,   132,   258,
     167,   258,   169,   178,   152,   153,   122,   258,   258,   258,
      40,   258,   189,   190,   130,   182,   121,   258,   123,   124,
     258,   258,   258,   155,   258,    55,   258,     1,   258,   177,
     258,   258,   258,   149,     8,     9,   258,   258,    12,   258,
     258,   258,   158,   159,   912,    19,   258,    77,   258,    79,
     258,    81,    82,    93,    28,   258,   258,   224,    32,    33,
     258,   258,   167,   132,   169,    39,   243,   258,    42,    43,
      44,   101,    46,   189,   190,   250,   258,   182,    52,   256,
     258,   256,   256,   250,   251,   258,   258,   258,   258,   256,
       5,   195,   258,   258,   258,   258,   258,    71,    72,   258,
     258,   258,    76,   172,   173,   174,   175,   176,   256,    83,
     255,   258,   258,    87,    88,    89,   258,   902,    92,   224,
     258,    95,    96,    38,   132,   910,   911,   243,   195,   132,
     170,     1,   106,   132,    49,     5,   132,   195,   112,   113,
     195,   115,   116,   117,   118,   250,   251,   195,   132,   195,
     195,    66,   195,   195,   195,   129,    26,   255,    73,   258,
     155,   201,   258,    78,   138,    80,   140,   141,    38,   143,
     255,   258,   258,   147,   148,   215,   195,   151,    93,    49,
     195,   132,   155,   132,    54,   195,   195,   132,   162,   195,
     155,   195,   132,   233,   234,   132,    66,   132,   195,   239,
     240,   241,   242,    73,   195,   195,   132,   181,    78,   183,
      80,   126,   252,   187,   155,   195,   131,   191,   192,   193,
     194,   132,     5,    93,   198,   199,   132,   142,   132,   132,
     155,   132,   206,     1,   195,     3,   195,   258,     6,   195,
     258,   195,    10,   155,   132,     1,   161,   195,   163,   164,
     255,   121,   195,   195,   255,    38,   126,    25,    26,    27,
     258,   195,   236,    31,   238,   195,    49,   195,   195,   258,
     244,   195,   258,   258,   155,   249,   258,   258,   255,   149,
     254,    49,   258,    66,   155,    53,    54,   258,   258,   258,
      73,   161,   258,   163,   164,    78,   258,    80,   168,   155,
      56,    57,    58,    59,    60,    61,    62,    63,     1,   155,
      93,   226,   258,   155,   258,   155,    84,   155,    86,   258,
      13,   155,   258,   155,   155,     0,     1,   242,   195,   258,
       5,   155,   100,   155,   255,   258,   258,   252,   258,   258,
     258,    34,    35,   126,   258,   258,   255,    22,    41,   105,
     255,    26,   195,   121,    29,   132,   226,   155,   258,   142,
     258,    36,   258,   255,   155,     1,   195,   195,   195,   195,
     195,   155,   242,   243,   155,   155,    51,   155,   161,    93,
     163,   164,   252,   139,   155,   155,   154,    23,    24,    64,
      65,   155,    67,   155,    30,   255,   255,   258,   155,    74,
     168,   258,   255,   258,    97,    98,   255,   255,   255,   155,
     178,   255,   155,   258,   107,   108,    91,   217,   218,   219,
     220,   221,   222,   223,   155,   255,   195,   102,   132,   104,
     132,   310,   255,   132,   127,   128,   255,   255,    20,    21,
     255,    20,    21,   226,   255,   120,   255,   255,   255,   255,
     255,   144,   145,   146,   255,   258,   170,   155,   255,   242,
     216,   255,   137,   156,   155,   255,   255,   255,    50,   252,
     255,    50,   165,   109,   110,   111,   258,   195,   114,   258,
     195,   155,   250,   258,   258,   121,    68,   201,   195,    68,
     255,   258,   248,    75,   195,   170,    75,   258,   134,   135,
     258,   215,   255,   258,   179,   180,   258,   258,   258,   184,
     185,   258,    94,   258,   258,    94,   152,   153,   258,   233,
     234,   258,   258,   258,   258,   239,   240,   241,   242,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   252,   255,
     122,   177,   195,   122,   255,   258,   255,   255,   130,   131,
     255,   130,   245,   246,   247,   202,   203,   204,   205,   255,
     207,   208,   155,   210,   211,   212,   255,   255,   215,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   225,   226,
     227,   228,   229,   230,   255,   232,   255,   255,   235,   171,
     255,   255,   171,   202,   203,   204,   205,   255,   207,   208,
     255,   210,   211,   212,   255,   255,   215,   255,   190,   255,
     255,   190,   255,   255,   255,   255,   225,   226,   227,   228,
     229,   230,   255,   232,   255,   255,   235,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   195,   255,   195,   195,
     255,   258,   258,   155,   258,   155,   195,   155,   255,   155,
     258,   155,   258,   255,   155,   155,   255,   255,   255,   255,
     255,   255,   255,   155,   255,   255,   155,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     155,   155,   155,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   155,
     258,   132,   132,   258,   258,   258,   258,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   132,   255,   132,
     258,   132,   155,   132,   132,   255,   155,   195,   155,   155,
     195,   195,   195,   155,   258,   155,   155,   155,   155,   132,
     255,   155,   255,   155,   160,   155,   255,   255,   255,   255,
     255,   255,   255,   160,   255,   255,   200,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     195,   155,   195,   255,   255,   255,   255,   155,   155,   155,
     258,   155,   255,   255,   255,   255,   255,   132,   255,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   273,   255,   255,    71,  1426,   255,   255,   255,   255,
     255,   255,  1384,   255,   255,   255,   605,   255,   811,  1368,
    1258,   255,  1364,  1228,   255,   493,   523,   460,   555,  1412,
     563,  1417,  1414,   639,  1366,   124,  1341,   368,  1355,   183,
    1361,    95,  1200,  1198,  1359,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,   255,   255,   255,   255,   255,   255,   255,
     255,    -1,   255,   255,   255,   255,   255,    -1,    -1,   356,
     255,    -1,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,    -1,   256,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   289
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,   261,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   102,   104,   120,   137,   170,
     179,   180,   184,   185,   262,   267,   272,   286,   292,   307,
     338,   357,   370,   394,   401,   411,   420,   448,   458,   464,
     468,   478,   541,   557,   578,   255,   256,   257,   257,   339,
     421,   459,   257,   469,   257,   542,   371,   449,   358,   257,
     257,   308,   395,   257,   257,   402,   412,     1,    37,    47,
     121,   287,   288,   289,   290,   291,     1,    13,    34,    35,
      41,    97,    98,   107,   108,   127,   128,   144,   145,   146,
     156,   165,   245,   246,   247,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   155,   340,   344,   155,   422,
     426,   257,     1,    90,   465,   466,   467,   257,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    42,    43,    44,
      46,    52,    71,    72,    76,    83,    87,    88,    89,    92,
      95,    96,   106,   112,   113,   115,   116,   117,   118,   129,
     138,   140,   141,   143,   147,   148,   151,   162,   181,   183,
     187,   191,   192,   193,   194,   198,   199,   206,   236,   238,
     244,   249,   254,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   532,   536,   537,   538,   539,   540,   257,
     257,   257,   257,     1,    56,    57,    58,    59,    60,    61,
      62,    63,   105,   139,   216,   248,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
       1,   119,   150,   268,   269,   270,   271,   155,   309,   313,
     257,     1,    40,    55,    77,    79,    81,    82,   101,   579,
     580,   581,   582,   583,   584,   585,   586,   587,     1,    37,
      85,   121,   123,   124,   167,   169,   182,   224,   250,   251,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   257,   257,   255,   258,   258,   258,   256,
     288,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   256,
     559,   257,   257,     1,    90,   157,   460,   461,   462,   463,
     258,   256,   466,     1,   121,   157,   186,   470,   474,   475,
     476,   477,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   533,   258,   529,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   256,   480,     1,     4,
      45,    48,   104,   121,   243,   543,   544,   545,   546,   547,
     551,   552,   553,     1,    20,    26,    49,    50,    54,    68,
      75,    94,   122,   130,   149,   158,   159,   189,   190,   243,
     372,   373,   374,   375,   376,   377,   378,   379,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,     1,   157,
     186,   243,   450,   454,   455,   456,   457,     1,    54,    84,
      90,   154,   359,   363,   364,   365,   368,   369,   255,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   256,   294,   255,   258,   258,   256,   269,   257,     1,
      22,   125,   157,   396,   397,   398,   399,   400,   258,   258,
     258,   258,   258,   258,   258,   256,   580,   255,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   256,
     274,     1,   121,   186,   243,   403,   404,   405,   406,   407,
       1,   121,   186,   413,   414,   415,   416,   155,   155,   155,
     255,   195,   132,   132,   195,   132,   264,   264,   132,   132,
     195,   195,   195,   132,   264,   195,   195,   195,   195,   195,
     255,     1,    23,    24,    30,   109,   110,   111,   114,   121,
     134,   135,   152,   153,   177,   341,   342,   343,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
       1,     3,     6,    10,    25,    26,    27,    31,    49,    53,
      54,    84,    86,   100,   121,   154,   168,   178,   250,   423,
     424,   425,   427,   428,   429,   430,   431,   432,   433,   434,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   258,
     258,   256,   461,   155,   255,   258,   258,   471,   256,   475,
     195,   264,   195,   264,   132,   155,   132,   195,   195,   195,
     132,   155,   195,   132,   132,   132,   195,   264,   195,   195,
     132,   155,   195,   132,   132,   264,   132,   155,   132,   132,
     195,   195,   258,   195,   258,   264,   264,   195,   264,   155,
     195,   195,   195,   196,   195,   196,   195,   195,   264,   264,
     132,   266,   264,   195,   195,   195,   195,   255,   554,   258,
     258,   548,   258,   258,   256,   544,   255,   258,   258,   258,
     258,   380,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   256,   373,   258,   451,   258,   256,   455,
     255,   360,   258,   258,   258,   256,   364,   155,   155,   155,
     155,   155,   155,   155,   155,   217,   218,   219,   220,   221,
     222,   223,   155,   155,   195,   255,   155,   155,   255,     1,
       5,    26,    38,    49,    54,    66,    73,    78,    80,    93,
     121,   126,   149,   161,   163,   164,   168,   226,   242,   243,
     252,   310,   311,   312,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   255,   258,   258,   258,   256,   397,
     195,   195,   195,   155,   195,   195,   264,   255,   155,   195,
     155,   155,   155,   155,   155,   155,   132,   155,   155,   255,
     255,   258,   408,   258,   256,   404,   255,   258,   417,   256,
     414,   255,   255,   255,   255,   255,   255,   255,   172,   173,
     174,   175,   176,   263,   264,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   256,   342,   255,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   435,   258,   258,   258,   258,
     258,   258,   258,   258,   256,   424,   155,   155,   255,   255,
     155,   155,   258,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   202,   203,   204,   205,
     207,   208,   210,   211,   212,   215,   225,   226,   227,   228,
     229,   230,   232,   235,   534,   535,   255,   202,   203,   204,
     205,   207,   208,   210,   211,   212,   215,   225,   226,   227,
     228,   229,   230,   232,   235,   530,   531,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,    14,    15,    16,   265,   266,   255,   255,   255,
     255,   255,   255,   258,   264,   195,   258,   155,   155,   255,
     195,   155,   195,   195,   258,   195,   195,   195,   195,   195,
     155,   132,   155,   155,   195,   155,   255,   155,   258,   155,
     255,   258,   155,   155,   132,   366,   367,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   258,
     258,   258,   258,   334,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     256,   311,   155,   155,   155,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   155,   258,   155,   255,   155,   258,
     255,   263,   263,   263,   263,   263,   132,   132,   264,   132,
     132,   132,   132,   155,   132,   132,   264,   264,   266,   255,
     155,   213,   214,   195,   155,   155,   195,   195,   195,   155,
     258,   155,   155,   155,   155,   132,   155,   155,   155,   255,
     255,   255,   255,   255,   160,   472,   473,   255,   259,   255,
     259,   265,   265,   265,    11,   197,   555,   556,   255,   255,
      11,   197,   549,   550,   255,   255,   255,   255,   255,   255,
      20,    21,    50,    68,    75,    94,   122,   130,   131,   171,
     190,   381,   382,   383,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   160,   452,   453,   255,
      77,   231,   361,   362,   255,   255,   200,   255,   259,   195,
     155,   195,   195,   258,   195,   195,   195,   195,   195,   155,
     195,   155,   195,   195,   195,   155,   195,   195,   155,   195,
     255,   255,   255,   255,   255,    93,   170,   201,   215,   233,
     234,   239,   240,   241,   242,   252,   409,   410,   255,   255,
      93,   170,   201,   215,   233,   234,   239,   240,   241,   242,
     252,   418,   419,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,    10,    12,    27,    31,
      99,   131,   237,   436,   437,   438,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   259,   535,   531,   255,   259,
     255,   259,   383,   255,   259,   255,   259,   255,   259,   132,
     367,   255,   255,   255,   255,     5,    38,    49,    66,    73,
      78,    80,    93,   126,   131,   142,   161,   163,   164,   226,
     242,   252,   335,   336,   337,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   259,   255,   259,   438,   255,   259,   473,   556,
     550,   382,   453,   362,   337,   255,   259,   410,   419,   437,
     336
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
#define YYEMPTY		-2
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");			\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)           \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#define YYLEX	yylex ()

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
# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)
/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
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

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

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
/*-----------------------------.
| Print this symbol on YYOUT.  |
`-----------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yysymprint (FILE* yyout, int yytype, YYSTYPE yyvalue)
#else
yysymprint (yyout, yytype, yyvalue)
    FILE* yyout;
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyout, yytoknum[yytype], yyvalue);
# endif
    }
  else
    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyout, ")");
}
#endif /* YYDEBUG. */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
#if defined (__STDC__) || defined (__cplusplus)
yydestruct (int yytype, YYSTYPE yyvalue)
#else
yydestruct (yytype, yyvalue)
    int yytype;
    YYSTYPE yyvalue;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvalue;

  switch (yytype)
    {
      default:
        break;
    }
}



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL
# else
#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
# endif
#else /* !YYPARSE_PARAM */
# define YYPARSE_PARAM_ARG
# define YYPARSE_PARAM_DECL
#endif /* !YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
# ifdef YYPARSE_PARAM
int yyparse (void *);
# else
int yyparse (void);
# endif
#endif


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of parse errors so far.  */
int yynerrs;


int
yyparse (YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yychar1 = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

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

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


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
      if (yystacksize >= YYMAXDEPTH)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
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

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with.  */

  if (yychar <= 0)		/* This means end of input.  */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more.  */

      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yychar1 = YYTRANSLATE (yychar);

      /* We have to keep this `#if YYDEBUG', since we use variables
	 which are defined only if `YYDEBUG' is set.  */
      YYDPRINTF ((stderr, "Next token is "));
      YYDSYMPRINT ((stderr, yychar1, yylval));
      YYDPRINTF ((stderr, "\n"));
    }

  /* If the proper action on seeing token YYCHAR1 is to reduce or to
     detect an error, take that action.  */
  yyn += yychar1;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
	      yychar, yytname[yychar1]));

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



#if YYDEBUG
  /* We have to keep this `#if YYDEBUG', since we use variables which
     are defined only if `YYDEBUG' is set.  */
  if (yydebug)
    {
      int yyi;

      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
		 yyn - 1, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (yyi = yyprhs[yyn]; yyrhs[yyi] >= 0; yyi++)
	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif
  switch (yyn)
    {
        case 26:
#line 421 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 28:
#line 423 "ircd_parser.y"
    {
			yyval.number = yyvsp[-1].number + yyvsp[0].number;
		}
    break;

  case 29:
#line 427 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number + yyvsp[0].number;
		}
    break;

  case 30:
#line 431 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 + yyvsp[0].number;
		}
    break;

  case 31:
#line 435 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 + yyvsp[0].number;
		}
    break;

  case 32:
#line 439 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 + yyvsp[0].number;
		}
    break;

  case 33:
#line 443 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 * 7 + yyvsp[0].number;
		}
    break;

  case 34:
#line 448 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 36:
#line 449 "ircd_parser.y"
    { yyval.number = yyvsp[-1].number + yyvsp[0].number; }
    break;

  case 37:
#line 450 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number + yyvsp[0].number; }
    break;

  case 38:
#line 451 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 + yyvsp[0].number; }
    break;

  case 39:
#line 452 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 * 1024 + yyvsp[0].number; }
    break;

  case 46:
#line 466 "ircd_parser.y"
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
#line 483 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 507 "ircd_parser.y"
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
#line 541 "ircd_parser.y"
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
#line 601 "ircd_parser.y"
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
#line 615 "ircd_parser.y"
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
#line 633 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 642 "ircd_parser.y"
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
#line 656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 665 "ircd_parser.y"
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
#line 693 "ircd_parser.y"
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
#line 723 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if (yyvsp[-1].number < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if (yyvsp[-1].number > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = yyvsp[-1].number;
  }
}
    break;

  case 73:
#line 746 "ircd_parser.y"
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
#line 802 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 811 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 820 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 847 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 851 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 855 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 862 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 869 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 876 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 883 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 890 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 897 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 904 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 911 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 915 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 919 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 923 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 927 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 931 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 935 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 941 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 950 "ircd_parser.y"
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
#line 963 "ircd_parser.y"
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

  case 146:
#line 1055 "ircd_parser.y"
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

  case 147:
#line 1067 "ircd_parser.y"
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
#line 1079 "ircd_parser.y"
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

  case 149:
#line 1098 "ircd_parser.y"
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

  case 150:
#line 1110 "ircd_parser.y"
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

  case 151:
#line 1121 "ircd_parser.y"
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

  case 152:
#line 1163 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 153:
#line 1172 "ircd_parser.y"
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

  case 154:
#line 1183 "ircd_parser.y"
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

  case 155:
#line 1194 "ircd_parser.y"
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

  case 156:
#line 1205 "ircd_parser.y"
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

  case 157:
#line 1216 "ircd_parser.y"
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

  case 158:
#line 1227 "ircd_parser.y"
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

  case 159:
#line 1238 "ircd_parser.y"
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

  case 160:
#line 1249 "ircd_parser.y"
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

  case 161:
#line 1260 "ircd_parser.y"
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

  case 162:
#line 1271 "ircd_parser.y"
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

  case 163:
#line 1282 "ircd_parser.y"
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

  case 164:
#line 1293 "ircd_parser.y"
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

  case 165:
#line 1304 "ircd_parser.y"
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

  case 166:
#line 1315 "ircd_parser.y"
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

  case 167:
#line 1326 "ircd_parser.y"
    {
}
    break;

  case 171:
#line 1330 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 172:
#line 1331 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 173:
#line 1334 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 174:
#line 1341 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 175:
#line 1348 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 176:
#line 1355 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 177:
#line 1362 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 178:
#line 1369 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 179:
#line 1376 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 180:
#line 1383 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 181:
#line 1390 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 182:
#line 1397 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 183:
#line 1404 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 184:
#line 1411 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 185:
#line 1418 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 186:
#line 1425 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 187:
#line 1432 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 188:
#line 1439 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 189:
#line 1452 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 190:
#line 1459 "ircd_parser.y"
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

  case 209:
#line 1511 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 210:
#line 1520 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 211:
#line 1529 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 212:
#line 1535 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = yyvsp[-1].number;
}
    break;

  case 213:
#line 1541 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = yyvsp[-1].number;
}
    break;

  case 214:
#line 1547 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 215:
#line 1553 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = yyvsp[-1].number;
}
    break;

  case 216:
#line 1559 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = yyvsp[-1].number;
}
    break;

  case 217:
#line 1565 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = yyvsp[-1].number;
}
    break;

  case 218:
#line 1571 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = yyvsp[-1].number;
}
    break;

  case 219:
#line 1577 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = yyvsp[-1].number;
}
    break;

  case 220:
#line 1583 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = yyvsp[-1].number;
}
    break;

  case 221:
#line 1589 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = yyvsp[-1].number;
}
    break;

  case 222:
#line 1595 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = yyvsp[-1].number;
}
    break;

  case 223:
#line 1604 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 224:
#line 1611 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 225:
#line 1620 "ircd_parser.y"
    {
}
    break;

  case 229:
#line 1625 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 230:
#line 1629 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 241:
#line 1642 "ircd_parser.y"
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
    add_listener(yyvsp[0].number, listener_address, listener_flags);
    listener_flags = 0;
  }
}
    break;

  case 242:
#line 1657 "ircd_parser.y"
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

    for (i = yyvsp[-2].number; i <= yyvsp[0].number; ++i)
      add_listener(i, listener_address, listener_flags);

    listener_flags = 0;
  }
}
    break;

  case 243:
#line 1679 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 244:
#line 1688 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 245:
#line 1700 "ircd_parser.y"
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

  case 246:
#line 1712 "ircd_parser.y"
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

  case 266:
#line 1777 "ircd_parser.y"
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

  case 267:
#line 1796 "ircd_parser.y"
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

  case 268:
#line 1809 "ircd_parser.y"
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

  case 269:
#line 1820 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 270:
#line 1829 "ircd_parser.y"
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

  case 271:
#line 1840 "ircd_parser.y"
    {
}
    break;

  case 275:
#line 1844 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 276:
#line 1845 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 277:
#line 1848 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 278:
#line 1856 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 279:
#line 1863 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 280:
#line 1870 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 281:
#line 1877 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 282:
#line 1884 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 283:
#line 1891 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 284:
#line 1898 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 285:
#line 1905 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 286:
#line 1912 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 287:
#line 1921 "ircd_parser.y"
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

  case 288:
#line 1932 "ircd_parser.y"
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

  case 289:
#line 1943 "ircd_parser.y"
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

  case 290:
#line 1954 "ircd_parser.y"
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

  case 291:
#line 1965 "ircd_parser.y"
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

  case 292:
#line 1976 "ircd_parser.y"
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

  case 293:
#line 1988 "ircd_parser.y"
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

  case 294:
#line 2007 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 295:
#line 2017 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = yyvsp[-1].number;
  }
}
    break;

  case 296:
#line 2026 "ircd_parser.y"
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

  case 297:
#line 2041 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 298:
#line 2048 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 305:
#line 2060 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 306:
#line 2069 "ircd_parser.y"
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

  case 307:
#line 2084 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 308:
#line 2097 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 309:
#line 2105 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 316:
#line 2116 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 317:
#line 2125 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 318:
#line 2133 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 322:
#line 2140 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 323:
#line 2144 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 324:
#line 2148 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 325:
#line 2152 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 326:
#line 2156 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 327:
#line 2160 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 328:
#line 2164 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 329:
#line 2168 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 330:
#line 2172 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 331:
#line 2176 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 332:
#line 2180 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 333:
#line 2189 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 334:
#line 2196 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 340:
#line 2209 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 341:
#line 2215 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 345:
#line 2222 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 346:
#line 2226 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 347:
#line 2230 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 348:
#line 2234 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 349:
#line 2238 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 350:
#line 2242 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 351:
#line 2246 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 352:
#line 2250 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 353:
#line 2254 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 354:
#line 2258 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 355:
#line 2262 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 356:
#line 2271 "ircd_parser.y"
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

  case 357:
#line 2289 "ircd_parser.y"
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

  case 381:
#line 2432 "ircd_parser.y"
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

  case 382:
#line 2444 "ircd_parser.y"
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

  case 383:
#line 2456 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 384:
#line 2465 "ircd_parser.y"
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

  case 385:
#line 2491 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yyvsp[-1].string[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr(yyvsp[-1].string, ' ') != NULL)
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

  case 386:
#line 2509 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yyvsp[-1].string[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr(yyvsp[-1].string, ' ') != NULL)
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

  case 387:
#line 2527 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = yyvsp[-1].number;
}
    break;

  case 388:
#line 2533 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 389:
#line 2537 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 390:
#line 2545 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 391:
#line 2554 "ircd_parser.y"
    {
}
    break;

  case 395:
#line 2558 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 396:
#line 2559 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 397:
#line 2562 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 398:
#line 2569 "ircd_parser.y"
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

  case 399:
#line 2580 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 400:
#line 2587 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 401:
#line 2594 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 402:
#line 2601 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 403:
#line 2611 "ircd_parser.y"
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

  case 404:
#line 2652 "ircd_parser.y"
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

  case 405:
#line 2663 "ircd_parser.y"
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

  case 406:
#line 2674 "ircd_parser.y"
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

  case 407:
#line 2689 "ircd_parser.y"
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

  case 408:
#line 2700 "ircd_parser.y"
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

  case 409:
#line 2713 "ircd_parser.y"
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

  case 410:
#line 2726 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 411:
#line 2735 "ircd_parser.y"
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

  case 412:
#line 2770 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 413:
#line 2777 "ircd_parser.y"
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

  case 414:
#line 2831 "ircd_parser.y"
    {
}
    break;

  case 418:
#line 2836 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 425:
#line 2845 "ircd_parser.y"
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

  case 426:
#line 2861 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 427:
#line 2870 "ircd_parser.y"
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

  case 428:
#line 2879 "ircd_parser.y"
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

  case 434:
#line 2895 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 435:
#line 2904 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 441:
#line 2921 "ircd_parser.y"
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

  case 442:
#line 2942 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 443:
#line 2949 "ircd_parser.y"
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

  case 444:
#line 2983 "ircd_parser.y"
    {
}
    break;

  case 448:
#line 2988 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 455:
#line 2997 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 456:
#line 3003 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 515:
#line 3048 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = yyvsp[-1].number;
}
    break;

  case 516:
#line 3053 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = yyvsp[-1].number;
}
    break;

  case 517:
#line 3058 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 518:
#line 3063 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 519:
#line 3068 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 520:
#line 3073 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 521:
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = yyvsp[-1].number;
}
    break;

  case 522:
#line 3083 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 523:
#line 3088 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 524:
#line 3093 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 525:
#line 3098 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 526:
#line 3103 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 527:
#line 3108 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = yyvsp[-1].number; 
}
    break;

  case 528:
#line 3113 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = yyvsp[-1].number;
}
    break;

  case 529:
#line 3118 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = yyvsp[-1].number;
}
    break;

  case 530:
#line 3123 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = yyvsp[-1].number;
}
    break;

  case 531:
#line 3128 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = yyvsp[-1].number;
}
    break;

  case 532:
#line 3133 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = yyvsp[-1].number;
}
    break;

  case 533:
#line 3139 "ircd_parser.y"
    {
  if ((yyvsp[-1].number > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 534:
#line 3150 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 535:
#line 3155 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 536:
#line 3164 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 537:
#line 3169 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 538:
#line 3174 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 539:
#line 3179 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 540:
#line 3184 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 541:
#line 3187 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 542:
#line 3192 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 543:
#line 3195 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 544:
#line 3200 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = yyvsp[-1].number;
}
    break;

  case 545:
#line 3205 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = yyvsp[-1].number;
}
    break;

  case 546:
#line 3210 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 547:
#line 3215 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = yyvsp[-1].number;
}
    break;

  case 548:
#line 3220 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 549:
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 550:
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 551:
#line 3235 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 552:
#line 3240 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 553:
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = yyvsp[-1].number;
}
    break;

  case 554:
#line 3256 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = yyvsp[-1].number;
}
    break;

  case 555:
#line 3261 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = yyvsp[-1].number;
}
    break;

  case 556:
#line 3266 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 557:
#line 3275 "ircd_parser.y"
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

  case 558:
#line 3307 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = yyvsp[-1].number;
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

  case 559:
#line 3325 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 560:
#line 3330 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 561:
#line 3339 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 562:
#line 3344 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 563:
#line 3349 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 564:
#line 3354 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 568:
#line 3360 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 569:
#line 3363 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 570:
#line 3366 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 571:
#line 3369 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 572:
#line 3372 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 573:
#line 3375 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 574:
#line 3378 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 575:
#line 3381 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 576:
#line 3384 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 577:
#line 3387 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 578:
#line 3390 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 579:
#line 3393 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 580:
#line 3396 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 581:
#line 3399 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 582:
#line 3402 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 583:
#line 3405 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 584:
#line 3408 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 585:
#line 3411 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 586:
#line 3416 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 590:
#line 3422 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 591:
#line 3425 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 592:
#line 3428 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 593:
#line 3431 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 594:
#line 3434 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 595:
#line 3437 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 596:
#line 3440 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 597:
#line 3443 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 598:
#line 3446 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 599:
#line 3449 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 600:
#line 3452 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 601:
#line 3455 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 602:
#line 3458 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 603:
#line 3461 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 604:
#line 3464 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 605:
#line 3467 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 606:
#line 3470 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 607:
#line 3473 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 608:
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = yyvsp[-1].number;
}
    break;

  case 609:
#line 3483 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = yyvsp[-1].number;
}
    break;

  case 610:
#line 3488 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = yyvsp[-1].number;
}
    break;

  case 611:
#line 3493 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = yyvsp[-1].number;
}
    break;

  case 612:
#line 3498 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 613:
#line 3506 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->flags = 0;
  }
}
    break;

  case 614:
#line 3514 "ircd_parser.y"
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

  case 624:
#line 3541 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 625:
#line 3547 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = yyvsp[-1].number;
}
    break;

  case 626:
#line 3553 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 630:
#line 3559 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 631:
#line 3563 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 632:
#line 3569 "ircd_parser.y"
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

  case 633:
#line 3588 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 634:
#line 3597 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 635:
#line 3601 "ircd_parser.y"
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

  case 638:
#line 3641 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 639:
#line 3645 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 662:
#line 3670 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 663:
#line 3675 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 664:
#line 3680 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 665:
#line 3685 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 666:
#line 3690 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 667:
#line 3695 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = yyvsp[-1].number;
}
    break;

  case 668:
#line 3700 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = yyvsp[-1].number;
}
    break;

  case 669:
#line 3705 "ircd_parser.y"
    {
  ConfigChannel.invite_ops_only = yylval.number;
}
    break;

  case 670:
#line 3710 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = yyvsp[-1].number;
}
    break;

  case 671:
#line 3715 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 672:
#line 3720 "ircd_parser.y"
    {
  ConfigChannel.max_bans = yyvsp[-1].number;
}
    break;

  case 673:
#line 3725 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = yyvsp[-1].number;
}
    break;

  case 674:
#line 3730 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = yyvsp[-1].number;
}
    break;

  case 675:
#line 3735 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 676:
#line 3740 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 677:
#line 3745 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 678:
#line 3750 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 679:
#line 3755 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 691:
#line 3774 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 692:
#line 3780 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 693:
#line 3786 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 694:
#line 3795 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].number > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, yyvsp[-1].number);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = yyvsp[-1].number;
  }
}
    break;

  case 695:
#line 3809 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 696:
#line 3815 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 697:
#line 3821 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


    }

/* Line 1016 of /usr/local/share/bison/yacc.c.  */
#line 7079 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


#if YYDEBUG
  if (yydebug)
    {
      short *yyssp1 = yyss - 1;
      YYFPRINTF (stderr, "state stack now");
      while (yyssp1 != yyssp)
	YYFPRINTF (stderr, " %d", *++yyssp1);
      YYFPRINTF (stderr, "\n");
    }
#endif

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
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("parse error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "parse error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("parse error");
    }
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyssp > yyss)
	    {
	      YYDPRINTF ((stderr, "Error: popping "));
	      YYDSYMPRINT ((stderr,
			    yystos[*yyssp],
			    *yyvsp));
	      YYDPRINTF ((stderr, "\n"));
	      yydestruct (yystos[*yyssp], *yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
		  yychar, yytname[yychar1]));
      yydestruct (yychar1, yylval);
      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */

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

      YYDPRINTF ((stderr, "Error: popping "));
      YYDSYMPRINT ((stderr,
		    yystos[*yyssp], *yyvsp));
      YYDPRINTF ((stderr, "\n"));

      yydestruct (yystos[yystate], *yyvsp);
      yyvsp--;
      yystate = *--yyssp;


#if YYDEBUG
      if (yydebug)
	{
	  short *yyssp1 = yyss - 1;
	  YYFPRINTF (stderr, "Error: state stack now");
	  while (yyssp1 != yyssp)
	    YYFPRINTF (stderr, " %d", *++yyssp1);
	  YYFPRINTF (stderr, "\n");
	}
#endif
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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


#line 392 "ircd_parser.y"

