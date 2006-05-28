/* A Bison parser, made by GNU Bison 1.875d.  */

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
     ANTI_NICK_FLOOD = 262,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 263,
     IRCD_AUTH = 264,
     AUTOCONN = 265,
     BASE_PATH = 266,
     BYTES = 267,
     KBYTES = 268,
     MBYTES = 269,
     GBYTES = 270,
     TBYTES = 271,
     CALLER_ID_WAIT = 272,
     CAN_FLOOD = 273,
     CHANNEL = 274,
     CIPHER_PREFERENCE = 275,
     CLASS = 276,
     COMPRESSED = 277,
     COMPRESSION_LEVEL = 278,
     CONNECT = 279,
     CONNECTFREQ = 280,
     CRYPTLINK = 281,
     DEFAULT_CIPHER_PREFERENCE = 282,
     DEFAULT_FLOODCOUNT = 283,
     DEFAULT_SPLIT_SERVER_COUNT = 284,
     DEFAULT_SPLIT_USER_COUNT = 285,
     DENY = 286,
     DESCRIPTION = 287,
     DIE = 288,
     DISABLE_AUTH = 289,
     DISABLE_HIDDEN = 290,
     DISABLE_LOCAL_CHANNELS = 291,
     DISABLE_REMOTE_COMMANDS = 292,
     DOT_IN_IP6_ADDR = 293,
     DOTS_IN_IDENT = 294,
     EGDPOOL_PATH = 295,
     EMAIL = 296,
     ENCRYPTED = 297,
     EXCEED_LIMIT = 298,
     EXEMPT = 299,
     FAILED_OPER_NOTICE = 300,
     FAKENAME = 301,
     FLATTEN_LINKS = 302,
     FFAILED_OPERLOG = 303,
     FOPERLOG = 304,
     FUSERLOG = 305,
     GECOS = 306,
     GENERAL = 307,
     GLINE = 308,
     GLINES = 309,
     GLINE_EXEMPT = 310,
     GLINE_LOG = 311,
     GLINE_TIME = 312,
     GLOBAL_KILL = 313,
     HAVE_IDENT = 314,
     HAVENT_READ_CONF = 315,
     HIDDEN = 316,
     HIDDEN_ADMIN = 317,
     HIDE_SERVER_IPS = 318,
     HIDE_SERVERS = 319,
     HIDE_SPOOF_IPS = 320,
     HOST = 321,
     HUB = 322,
     HUB_MASK = 323,
     IAUTH_PORT = 324,
     IAUTH_SERVER = 325,
     IDLETIME = 326,
     IGNORE_BOGUS_TS = 327,
     IP = 328,
     KILL = 329,
     KLINE = 330,
     KLINE_EXEMPT = 331,
     KLINE_WITH_CONNECTION_CLOSED = 332,
     KLINE_WITH_REASON = 333,
     KNOCK_DELAY = 334,
     KNOCK_DELAY_CHANNEL = 335,
     LAZYLINK = 336,
     LEAF_MASK = 337,
     LINKS_DELAY = 338,
     LISTEN = 339,
     LOGGING = 340,
     LOG_LEVEL = 341,
     MAXIMUM_LINKS = 342,
     MAX_ACCEPT = 343,
     MAX_BANS = 344,
     MAX_CHANS_PER_USER = 345,
     MAX_GLOBAL = 346,
     MAX_IDENT = 347,
     MAX_LOCAL = 348,
     MAX_NICK_CHANGES = 349,
     MAX_NICK_TIME = 350,
     MAX_NUMBER = 351,
     MAX_TARGETS = 352,
     MESSAGE_LOCALE = 353,
     MIN_NONWILDCARD = 354,
     MIN_NONWILDCARD_SIMPLE = 355,
     MODULE = 356,
     MODULES = 357,
     NAME = 358,
     NEED_PASSWORD = 359,
     NETWORK_DESC = 360,
     NETWORK_NAME = 361,
     NICK = 362,
     NICK_CHANGES = 363,
     NO_CREATE_ON_SPLIT = 364,
     NO_JOIN_ON_SPLIT = 365,
     NO_OPER_FLOOD = 366,
     NO_TILDE = 367,
     NUMBER = 368,
     NUMBER_PER_IDENT = 369,
     NUMBER_PER_IP = 370,
     NUMBER_PER_IP_GLOBAL = 371,
     OPERATOR = 372,
     OPER_LOG = 373,
     OPER_ONLY_UMODES = 374,
     OPER_PASS_RESV = 375,
     OPER_UMODES = 376,
     CRYPT_OPER_PASSWORD = 377,
     PACE_WAIT = 378,
     PACE_WAIT_SIMPLE = 379,
     PASSWORD = 380,
     PATH = 381,
     PING_COOKIE = 382,
     PING_TIME = 383,
     PORT = 384,
     SSLPORT = 385,
     QSTRING = 386,
     QUIET_ON_BAN = 387,
     REASON = 388,
     REDIRPORT = 389,
     REDIRSERV = 390,
     REHASH = 391,
     REMOTE = 392,
     RESTRICTED = 393,
     RSA_PRIVATE_KEY_FILE = 394,
     RSA_PUBLIC_KEY_FILE = 395,
     SSL_CERTIFICATE_FILE = 396,
     RESV = 397,
     SECONDS = 398,
     MINUTES = 399,
     HOURS = 400,
     DAYS = 401,
     WEEKS = 402,
     SENDQ = 403,
     SEND_PASSWORD = 404,
     SERVERHIDE = 405,
     SERVERINFO = 406,
     SERVLINK_PATH = 407,
     SID = 408,
     T_SHARED = 409,
     T_CLUSTER = 410,
     TYPE = 411,
     SHORT_MOTD = 412,
     SILENT = 413,
     SPOOF = 414,
     SPOOF_NOTICE = 415,
     STATS_I_OPER_ONLY = 416,
     STATS_K_OPER_ONLY = 417,
     STATS_O_OPER_ONLY = 418,
     STATS_P_OPER_ONLY = 419,
     TBOOL = 420,
     TMASKED = 421,
     TREJECT = 422,
     TS_MAX_DELTA = 423,
     TS_WARN_DELTA = 424,
     TWODOTS = 425,
     T_ALL = 426,
     T_BOTS = 427,
     T_CALLERID = 428,
     T_CCONN = 429,
     T_CLIENT_FLOOD = 430,
     T_DEBUG = 431,
     T_DRONE = 432,
     T_EXTERNAL = 433,
     T_FULL = 434,
     T_INVISIBLE = 435,
     T_IPV4 = 436,
     T_IPV6 = 437,
     T_LOCOPS = 438,
     T_LOGPATH = 439,
     T_L_CRIT = 440,
     T_L_DEBUG = 441,
     T_L_ERROR = 442,
     T_L_INFO = 443,
     T_L_NOTICE = 444,
     T_L_TRACE = 445,
     T_L_WARN = 446,
     T_MAX_CLIENTS = 447,
     T_NCHANGE = 448,
     T_OPERWALL = 449,
     T_REJ = 450,
     T_SERVNOTICE = 451,
     T_SERVCONN = 452,
     T_SKILL = 453,
     T_SPY = 454,
     T_UNAUTH = 455,
     T_UNRESV = 456,
     T_UNXLINE = 457,
     T_WALLOP = 458,
     T_GOD = 459,
     T_NICKSERVREG = 460,
     THROTTLE_TIME = 461,
     TRUE_NO_OPER_FLOOD = 462,
     UNKLINE = 463,
     USER = 464,
     USE_EGD = 465,
     USE_EXCEPT = 466,
     USE_INVEX = 467,
     USE_KNOCK = 468,
     USE_LOGGING = 469,
     VHOST = 470,
     VHOST6 = 471,
     XLINE = 472,
     WARN = 473,
     WARN_NO_NLINE = 474
   };
#endif
#define ACCEPT_PASSWORD 258
#define ACTION 259
#define ADMIN 260
#define AFTYPE 261
#define ANTI_NICK_FLOOD 262
#define ANTI_SPAM_EXIT_MESSAGE_TIME 263
#define IRCD_AUTH 264
#define AUTOCONN 265
#define BASE_PATH 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define GBYTES 270
#define TBYTES 271
#define CALLER_ID_WAIT 272
#define CAN_FLOOD 273
#define CHANNEL 274
#define CIPHER_PREFERENCE 275
#define CLASS 276
#define COMPRESSED 277
#define COMPRESSION_LEVEL 278
#define CONNECT 279
#define CONNECTFREQ 280
#define CRYPTLINK 281
#define DEFAULT_CIPHER_PREFERENCE 282
#define DEFAULT_FLOODCOUNT 283
#define DEFAULT_SPLIT_SERVER_COUNT 284
#define DEFAULT_SPLIT_USER_COUNT 285
#define DENY 286
#define DESCRIPTION 287
#define DIE 288
#define DISABLE_AUTH 289
#define DISABLE_HIDDEN 290
#define DISABLE_LOCAL_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DOT_IN_IP6_ADDR 293
#define DOTS_IN_IDENT 294
#define EGDPOOL_PATH 295
#define EMAIL 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define FAILED_OPER_NOTICE 300
#define FAKENAME 301
#define FLATTEN_LINKS 302
#define FFAILED_OPERLOG 303
#define FOPERLOG 304
#define FUSERLOG 305
#define GECOS 306
#define GENERAL 307
#define GLINE 308
#define GLINES 309
#define GLINE_EXEMPT 310
#define GLINE_LOG 311
#define GLINE_TIME 312
#define GLOBAL_KILL 313
#define HAVE_IDENT 314
#define HAVENT_READ_CONF 315
#define HIDDEN 316
#define HIDDEN_ADMIN 317
#define HIDE_SERVER_IPS 318
#define HIDE_SERVERS 319
#define HIDE_SPOOF_IPS 320
#define HOST 321
#define HUB 322
#define HUB_MASK 323
#define IAUTH_PORT 324
#define IAUTH_SERVER 325
#define IDLETIME 326
#define IGNORE_BOGUS_TS 327
#define IP 328
#define KILL 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_WITH_CONNECTION_CLOSED 332
#define KLINE_WITH_REASON 333
#define KNOCK_DELAY 334
#define KNOCK_DELAY_CHANNEL 335
#define LAZYLINK 336
#define LEAF_MASK 337
#define LINKS_DELAY 338
#define LISTEN 339
#define LOGGING 340
#define LOG_LEVEL 341
#define MAXIMUM_LINKS 342
#define MAX_ACCEPT 343
#define MAX_BANS 344
#define MAX_CHANS_PER_USER 345
#define MAX_GLOBAL 346
#define MAX_IDENT 347
#define MAX_LOCAL 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_TIME 350
#define MAX_NUMBER 351
#define MAX_TARGETS 352
#define MESSAGE_LOCALE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define NAME 358
#define NEED_PASSWORD 359
#define NETWORK_DESC 360
#define NETWORK_NAME 361
#define NICK 362
#define NICK_CHANGES 363
#define NO_CREATE_ON_SPLIT 364
#define NO_JOIN_ON_SPLIT 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER 368
#define NUMBER_PER_IDENT 369
#define NUMBER_PER_IP 370
#define NUMBER_PER_IP_GLOBAL 371
#define OPERATOR 372
#define OPER_LOG 373
#define OPER_ONLY_UMODES 374
#define OPER_PASS_RESV 375
#define OPER_UMODES 376
#define CRYPT_OPER_PASSWORD 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PORT 384
#define SSLPORT 385
#define QSTRING 386
#define QUIET_ON_BAN 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REHASH 391
#define REMOTE 392
#define RESTRICTED 393
#define RSA_PRIVATE_KEY_FILE 394
#define RSA_PUBLIC_KEY_FILE 395
#define SSL_CERTIFICATE_FILE 396
#define RESV 397
#define SECONDS 398
#define MINUTES 399
#define HOURS 400
#define DAYS 401
#define WEEKS 402
#define SENDQ 403
#define SEND_PASSWORD 404
#define SERVERHIDE 405
#define SERVERINFO 406
#define SERVLINK_PATH 407
#define SID 408
#define T_SHARED 409
#define T_CLUSTER 410
#define TYPE 411
#define SHORT_MOTD 412
#define SILENT 413
#define SPOOF 414
#define SPOOF_NOTICE 415
#define STATS_I_OPER_ONLY 416
#define STATS_K_OPER_ONLY 417
#define STATS_O_OPER_ONLY 418
#define STATS_P_OPER_ONLY 419
#define TBOOL 420
#define TMASKED 421
#define TREJECT 422
#define TS_MAX_DELTA 423
#define TS_WARN_DELTA 424
#define TWODOTS 425
#define T_ALL 426
#define T_BOTS 427
#define T_CALLERID 428
#define T_CCONN 429
#define T_CLIENT_FLOOD 430
#define T_DEBUG 431
#define T_DRONE 432
#define T_EXTERNAL 433
#define T_FULL 434
#define T_INVISIBLE 435
#define T_IPV4 436
#define T_IPV6 437
#define T_LOCOPS 438
#define T_LOGPATH 439
#define T_L_CRIT 440
#define T_L_DEBUG 441
#define T_L_ERROR 442
#define T_L_INFO 443
#define T_L_NOTICE 444
#define T_L_TRACE 445
#define T_L_WARN 446
#define T_MAX_CLIENTS 447
#define T_NCHANGE 448
#define T_OPERWALL 449
#define T_REJ 450
#define T_SERVNOTICE 451
#define T_SERVCONN 452
#define T_SKILL 453
#define T_SPY 454
#define T_UNAUTH 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_WALLOP 458
#define T_GOD 459
#define T_NICKSERVREG 460
#define THROTTLE_TIME 461
#define TRUE_NO_OPER_FLOOD 462
#define UNKLINE 463
#define USER 464
#define USE_EGD 465
#define USE_EXCEPT 466
#define USE_INVEX 467
#define USE_KNOCK 468
#define USE_LOGGING 469
#define VHOST 470
#define VHOST6 471
#define XLINE 472
#define WARN 473
#define WARN_NO_NLINE 474




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


/* XXX */
#define WE_ARE_MEMORY_C

#define YY_NO_UNPUT
#include "stdinc.h"
#include "dalloca.h"
#include "ircd.h"
#include "tools.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "irc_getaddrinfo.h"
#include "ircdauth.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "cluster.h"

static char *class_name;
static struct ConfItem *yy_conf = NULL;
struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static dlink_list hub_conf_list  = { NULL, NULL, 0 };
static dlink_list leaf_conf_list = { NULL, NULL, 0 };

static char *resv_reason;
static char *listener_address;

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
#line 118 "ircd_parser.y"
typedef union YYSTYPE {
  int number;
  char *string;
  struct ip_value ip_entry;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 613 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 625 "y.tab.c"

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
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
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
#define YYLAST   1147

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  225
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  264
/* YYNRULES -- Number of rules. */
#define YYNRULES  551
/* YYNRULES -- Number of states. */
#define YYNSTATES  1172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   474

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   224,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   220,
       2,   223,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   222,     2,   221,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    48,    51,    52,    54,    57,    61,
      65,    69,    73,    77,    78,    80,    83,    87,    91,    95,
     101,   104,   106,   108,   110,   112,   114,   119,   124,   129,
     135,   138,   140,   142,   144,   146,   148,   150,   152,   154,
     156,   158,   160,   162,   164,   169,   174,   179,   184,   189,
     194,   199,   204,   209,   214,   219,   225,   228,   230,   232,
     234,   236,   238,   243,   248,   253,   259,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   287,   292,
     297,   302,   307,   312,   317,   322,   327,   332,   337,   342,
     347,   352,   353,   360,   363,   365,   367,   369,   371,   373,
     375,   377,   379,   381,   383,   385,   387,   389,   391,   393,
     395,   397,   399,   404,   409,   414,   419,   424,   429,   434,
     439,   444,   449,   454,   459,   464,   469,   474,   479,   480,
     487,   490,   492,   494,   496,   498,   500,   502,   504,   506,
     508,   510,   512,   517,   522,   527,   532,   537,   542,   547,
     552,   557,   558,   565,   568,   570,   572,   574,   576,   578,
     580,   585,   589,   591,   593,   597,   602,   606,   608,   610,
     614,   619,   624,   625,   632,   635,   637,   639,   641,   643,
     645,   647,   649,   651,   653,   655,   657,   659,   661,   663,
     665,   667,   669,   674,   679,   684,   689,   694,   699,   704,
     709,   714,   719,   724,   729,   734,   739,   744,   745,   752,
     755,   757,   759,   761,   763,   765,   770,   775,   780,   781,
     788,   791,   793,   795,   797,   799,   801,   806,   811,   812,
     818,   822,   824,   826,   828,   830,   832,   834,   836,   838,
     839,   846,   849,   851,   853,   855,   857,   862,   863,   869,
     873,   875,   877,   879,   881,   883,   885,   887,   889,   891,
     892,   899,   902,   904,   906,   908,   910,   912,   914,   916,
     918,   920,   922,   924,   926,   928,   930,   932,   934,   936,
     938,   940,   945,   950,   955,   960,   965,   970,   975,   980,
     985,   990,   995,  1000,  1005,  1010,  1015,  1020,  1025,  1030,
    1031,  1038,  1041,  1043,  1045,  1047,  1049,  1054,  1059,  1060,
    1067,  1070,  1072,  1074,  1076,  1078,  1083,  1088,  1089,  1096,
    1099,  1101,  1103,  1105,  1110,  1111,  1118,  1121,  1123,  1125,
    1127,  1129,  1131,  1136,  1141,  1146,  1151,  1156,  1162,  1165,
    1167,  1169,  1171,  1173,  1175,  1177,  1179,  1181,  1183,  1185,
    1187,  1189,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1207,  1209,  1211,  1213,  1215,  1217,  1219,  1221,  1223,  1225,
    1227,  1229,  1231,  1233,  1235,  1237,  1239,  1241,  1243,  1245,
    1247,  1249,  1251,  1253,  1255,  1257,  1259,  1261,  1263,  1265,
    1267,  1269,  1271,  1276,  1281,  1286,  1291,  1296,  1301,  1306,
    1311,  1316,  1321,  1326,  1331,  1336,  1341,  1346,  1351,  1356,
    1361,  1366,  1371,  1376,  1381,  1386,  1391,  1396,  1401,  1406,
    1411,  1416,  1421,  1426,  1431,  1436,  1441,  1446,  1451,  1456,
    1461,  1466,  1471,  1476,  1481,  1486,  1491,  1496,  1497,  1503,
    1507,  1509,  1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,
    1527,  1529,  1531,  1533,  1535,  1537,  1539,  1541,  1543,  1544,
    1550,  1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,
    1572,  1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,
    1592,  1597,  1602,  1607,  1612,  1617,  1622,  1628,  1631,  1633,
    1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,
    1655,  1657,  1659,  1661,  1666,  1671,  1676,  1681,  1686,  1691,
    1696,  1701,  1706,  1711,  1716,  1721,  1726,  1732,  1735,  1737,
    1739,  1741,  1743,  1745,  1747,  1749,  1751,  1756,  1761,  1766,
    1771,  1776
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     226,     0,    -1,    -1,   226,   227,    -1,   252,    -1,   258,
      -1,   269,    -1,   464,    -1,   289,    -1,   302,    -1,   314,
      -1,   238,    -1,   480,    -1,   333,    -1,   340,    -1,   350,
      -1,   359,    -1,   380,    -1,   386,    -1,   392,    -1,   404,
      -1,   397,    -1,   232,    -1,     1,   220,    -1,     1,   221,
      -1,    -1,   229,    -1,   113,   228,    -1,   113,   143,   228,
      -1,   113,   144,   228,    -1,   113,   145,   228,    -1,   113,
     146,   228,    -1,   113,   147,   228,    -1,    -1,   231,    -1,
     113,   230,    -1,   113,    12,   230,    -1,   113,    13,   230,
      -1,   113,    14,   230,    -1,   102,   222,   233,   221,   220,
      -1,   233,   234,    -1,   234,    -1,   235,    -1,   237,    -1,
     236,    -1,     1,    -1,   101,   223,   131,   220,    -1,   126,
     223,   131,   220,    -1,    11,   223,   131,   220,    -1,   151,
     222,   239,   221,   220,    -1,   239,   240,    -1,   240,    -1,
     243,    -1,   248,    -1,   251,    -1,   245,    -1,   246,    -1,
     247,    -1,   250,    -1,   241,    -1,   249,    -1,   242,    -1,
     244,    -1,     1,    -1,   139,   223,   131,   220,    -1,   141,
     223,   131,   220,    -1,   103,   223,   131,   220,    -1,   153,
     223,   131,   220,    -1,    32,   223,   131,   220,    -1,   106,
     223,   131,   220,    -1,   105,   223,   131,   220,    -1,   215,
     223,   131,   220,    -1,   216,   223,   131,   220,    -1,   192,
     223,   113,   220,    -1,    67,   223,   165,   220,    -1,     5,
     222,   253,   221,   220,    -1,   253,   254,    -1,   254,    -1,
     255,    -1,   257,    -1,   256,    -1,     1,    -1,   103,   223,
     131,   220,    -1,    41,   223,   131,   220,    -1,    32,   223,
     131,   220,    -1,    85,   222,   259,   221,   220,    -1,   259,
     260,    -1,   260,    -1,   261,    -1,   262,    -1,   263,    -1,
     267,    -1,   268,    -1,   264,    -1,   266,    -1,   265,    -1,
       1,    -1,   184,   223,   131,   220,    -1,   118,   223,   131,
     220,    -1,    56,   223,   131,   220,    -1,    50,   223,   131,
     220,    -1,    48,   223,   131,   220,    -1,    49,   223,   131,
     220,    -1,    86,   223,   185,   220,    -1,    86,   223,   187,
     220,    -1,    86,   223,   191,   220,    -1,    86,   223,   189,
     220,    -1,    86,   223,   190,   220,    -1,    86,   223,   188,
     220,    -1,    86,   223,   186,   220,    -1,   214,   223,   165,
     220,    -1,    -1,   117,   270,   222,   271,   221,   220,    -1,
     271,   272,    -1,   272,    -1,   273,    -1,   274,    -1,   275,
      -1,   276,    -1,   278,    -1,   279,    -1,   280,    -1,   281,
      -1,   282,    -1,   283,    -1,   284,    -1,   285,    -1,   286,
      -1,   287,    -1,   288,    -1,   277,    -1,     1,    -1,   103,
     223,   131,   220,    -1,   209,   223,   131,   220,    -1,   125,
     223,   131,   220,    -1,    62,   223,   165,   220,    -1,   140,
     223,   131,   220,    -1,    21,   223,   131,   220,    -1,    58,
     223,   165,   220,    -1,   137,   223,   165,   220,    -1,    75,
     223,   165,   220,    -1,   217,   223,   165,   220,    -1,   208,
     223,   165,   220,    -1,    53,   223,   165,   220,    -1,   108,
     223,   165,   220,    -1,    33,   223,   165,   220,    -1,   136,
     223,   165,   220,    -1,     5,   223,   165,   220,    -1,    -1,
      21,   290,   222,   291,   221,   220,    -1,   291,   292,    -1,
     292,    -1,   293,    -1,   294,    -1,   295,    -1,   296,    -1,
     297,    -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,
       1,    -1,   103,   223,   131,   220,    -1,   128,   223,   229,
     220,    -1,   115,   223,   113,   220,    -1,    25,   223,   229,
     220,    -1,    96,   223,   113,   220,    -1,    91,   223,   113,
     220,    -1,    93,   223,   113,   220,    -1,    92,   223,   113,
     220,    -1,   148,   223,   231,   220,    -1,    -1,    84,   303,
     222,   304,   221,   220,    -1,   304,   305,    -1,   305,    -1,
     306,    -1,   309,    -1,   312,    -1,   313,    -1,     1,    -1,
     129,   223,   307,   220,    -1,   307,   224,   308,    -1,   308,
      -1,   113,    -1,   113,   170,   113,    -1,   130,   223,   310,
     220,    -1,   310,   224,   311,    -1,   311,    -1,   113,    -1,
     113,   170,   113,    -1,    73,   223,   131,   220,    -1,    66,
     223,   131,   220,    -1,    -1,     9,   315,   222,   316,   221,
     220,    -1,   316,   317,    -1,   317,    -1,   318,    -1,   319,
      -1,   331,    -1,   324,    -1,   325,    -1,   323,    -1,   322,
      -1,   327,    -1,   328,    -1,   321,    -1,   320,    -1,   329,
      -1,   330,    -1,   326,    -1,   332,    -1,     1,    -1,   209,
     223,   131,   220,    -1,   125,   223,   131,   220,    -1,   160,
     223,   165,   220,    -1,   159,   223,   131,   220,    -1,    43,
     223,   165,   220,    -1,   138,   223,   165,   220,    -1,    76,
     223,   165,   220,    -1,    59,   223,   165,   220,    -1,    18,
     223,   165,   220,    -1,   112,   223,   165,   220,    -1,    55,
     223,   165,   220,    -1,   135,   223,   131,   220,    -1,   134,
     223,   113,   220,    -1,    21,   223,   131,   220,    -1,   104,
     223,   165,   220,    -1,    -1,   142,   334,   222,   335,   221,
     220,    -1,   335,   336,    -1,   336,    -1,   337,    -1,   338,
      -1,   339,    -1,     1,    -1,   133,   223,   131,   220,    -1,
      19,   223,   131,   220,    -1,   107,   223,   131,   220,    -1,
      -1,   154,   341,   222,   342,   221,   220,    -1,   342,   343,
      -1,   343,    -1,   344,    -1,   345,    -1,   346,    -1,     1,
      -1,   103,   223,   131,   220,    -1,   209,   223,   131,   220,
      -1,    -1,   156,   347,   223,   348,   220,    -1,   348,   224,
     349,    -1,   349,    -1,    75,    -1,   208,    -1,   217,    -1,
     202,    -1,   142,    -1,   201,    -1,   171,    -1,    -1,   155,
     351,   222,   352,   221,   220,    -1,   352,   353,    -1,   353,
      -1,   354,    -1,   355,    -1,     1,    -1,   103,   223,   131,
     220,    -1,    -1,   156,   356,   223,   357,   220,    -1,   357,
     224,   358,    -1,   358,    -1,    75,    -1,   208,    -1,   217,
      -1,   202,    -1,   142,    -1,   201,    -1,   183,    -1,   171,
      -1,    -1,    24,   360,   222,   361,   221,   220,    -1,   361,
     362,    -1,   362,    -1,   363,    -1,   364,    -1,   365,    -1,
     366,    -1,   367,    -1,   368,    -1,   369,    -1,   370,    -1,
     376,    -1,   377,    -1,   378,    -1,   375,    -1,   371,    -1,
     374,    -1,   373,    -1,   372,    -1,   379,    -1,     1,    -1,
     103,   223,   131,   220,    -1,    66,   223,   131,   220,    -1,
     149,   223,   131,   220,    -1,     3,   223,   131,   220,    -1,
     129,   223,   113,   220,    -1,     6,   223,   181,   220,    -1,
       6,   223,   182,   220,    -1,    46,   223,   131,   220,    -1,
      81,   223,   165,   220,    -1,    42,   223,   165,   220,    -1,
     140,   223,   131,   220,    -1,    26,   223,   165,   220,    -1,
      22,   223,   165,   220,    -1,    10,   223,   165,   220,    -1,
      68,   223,   131,   220,    -1,    82,   223,   131,   220,    -1,
      21,   223,   131,   220,    -1,    20,   223,   131,   220,    -1,
      -1,    74,   381,   222,   382,   221,   220,    -1,   382,   383,
      -1,   383,    -1,   384,    -1,   385,    -1,     1,    -1,   209,
     223,   131,   220,    -1,   133,   223,   131,   220,    -1,    -1,
      31,   387,   222,   388,   221,   220,    -1,   388,   389,    -1,
     389,    -1,   390,    -1,   391,    -1,     1,    -1,    73,   223,
     131,   220,    -1,   133,   223,   131,   220,    -1,    -1,    44,
     393,   222,   394,   221,   220,    -1,   394,   395,    -1,   395,
      -1,   396,    -1,     1,    -1,    73,   223,   131,   220,    -1,
      -1,    51,   398,   222,   399,   221,   220,    -1,   399,   400,
      -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,     1,
      -1,   103,   223,   131,   220,    -1,   133,   223,   131,   220,
      -1,     4,   223,   218,   220,    -1,     4,   223,   167,   220,
      -1,     4,   223,   158,   220,    -1,    52,   222,   405,   221,
     220,    -1,   405,   406,    -1,   406,    -1,   407,    -1,   408,
      -1,   410,    -1,   411,    -1,   412,    -1,   413,    -1,   414,
      -1,   415,    -1,   416,    -1,   417,    -1,   419,    -1,   420,
      -1,   421,    -1,   439,    -1,   422,    -1,   424,    -1,   426,
      -1,   425,    -1,   428,    -1,   423,    -1,   429,    -1,   430,
      -1,   431,    -1,   432,    -1,   433,    -1,   434,    -1,   435,
      -1,   437,    -1,   438,    -1,   440,    -1,   436,    -1,   454,
      -1,   441,    -1,   445,    -1,   446,    -1,   450,    -1,   458,
      -1,   427,    -1,   461,    -1,   459,    -1,   460,    -1,   442,
      -1,   409,    -1,   443,    -1,   444,    -1,   462,    -1,   449,
      -1,   418,    -1,   463,    -1,   447,    -1,   448,    -1,     1,
      -1,    65,   223,   165,   220,    -1,    72,   223,   165,   220,
      -1,    37,   223,   165,   220,    -1,    45,   223,   165,   220,
      -1,     7,   223,   165,   220,    -1,    95,   223,   229,   220,
      -1,    94,   223,   113,   220,    -1,    88,   223,   113,   220,
      -1,     8,   223,   229,   220,    -1,   169,   223,   229,   220,
      -1,   168,   223,   229,   220,    -1,    60,   223,   113,   220,
      -1,    78,   223,   165,   220,    -1,    77,   223,   165,   220,
      -1,   219,   223,   165,   220,    -1,   163,   223,   165,   220,
      -1,   164,   223,   165,   220,    -1,   162,   223,   165,   220,
      -1,   162,   223,   166,   220,    -1,   161,   223,   165,   220,
      -1,   161,   223,   166,   220,    -1,   123,   223,   229,   220,
      -1,    17,   223,   229,   220,    -1,   124,   223,   229,   220,
      -1,   157,   223,   165,   220,    -1,   111,   223,   165,   220,
      -1,   207,   223,   165,   220,    -1,   120,   223,   165,   220,
      -1,    70,   223,   131,   220,    -1,    69,   223,   113,   220,
      -1,    54,   223,   165,   220,    -1,    98,   223,   131,   220,
      -1,    57,   223,   229,   220,    -1,    71,   223,   229,   220,
      -1,    39,   223,   113,   220,    -1,    87,   223,   113,   220,
      -1,    97,   223,   113,   220,    -1,   152,   223,   131,   220,
      -1,    27,   223,   131,   220,    -1,    23,   223,   113,   220,
      -1,   210,   223,   165,   220,    -1,    40,   223,   131,   220,
      -1,   127,   223,   165,   220,    -1,    34,   223,   165,   220,
      -1,   206,   223,   229,   220,    -1,    -1,   121,   451,   223,
     452,   220,    -1,   452,   224,   453,    -1,   453,    -1,   172,
      -1,   174,    -1,   176,    -1,   179,    -1,   198,    -1,   193,
      -1,   195,    -1,   200,    -1,   199,    -1,   178,    -1,   194,
      -1,   196,    -1,   197,    -1,   180,    -1,   203,    -1,   173,
      -1,   183,    -1,    -1,   119,   455,   223,   456,   220,    -1,
     456,   224,   457,    -1,   457,    -1,   172,    -1,   174,    -1,
     176,    -1,   179,    -1,   198,    -1,   193,    -1,   195,    -1,
     200,    -1,   199,    -1,   178,    -1,   194,    -1,   196,    -1,
     197,    -1,   180,    -1,   203,    -1,   173,    -1,   183,    -1,
     204,    -1,   122,   223,   165,   220,    -1,    99,   223,   113,
     220,    -1,   100,   223,   113,   220,    -1,    28,   223,   113,
     220,    -1,   175,   223,   231,   220,    -1,    38,   223,   165,
     220,    -1,    19,   222,   465,   221,   220,    -1,   465,   466,
      -1,   466,    -1,   467,    -1,   468,    -1,   469,    -1,   470,
      -1,   475,    -1,   471,    -1,   472,    -1,   473,    -1,   474,
      -1,   476,    -1,   477,    -1,   478,    -1,   479,    -1,     1,
      -1,    36,   223,   165,   220,    -1,   211,   223,   165,   220,
      -1,   212,   223,   165,   220,    -1,   213,   223,   165,   220,
      -1,    79,   223,   229,   220,    -1,    80,   223,   229,   220,
      -1,    90,   223,   113,   220,    -1,   132,   223,   165,   220,
      -1,    89,   223,   113,   220,    -1,    30,   223,   113,   220,
      -1,    29,   223,   113,   220,    -1,   109,   223,   165,   220,
      -1,   110,   223,   165,   220,    -1,   150,   222,   481,   221,
     220,    -1,   481,   482,    -1,   482,    -1,   483,    -1,   484,
      -1,   485,    -1,   487,    -1,   486,    -1,   488,    -1,     1,
      -1,    47,   223,   165,   220,    -1,    64,   223,   165,   220,
      -1,    83,   223,   229,   220,    -1,    61,   223,   165,   220,
      -1,    35,   223,   165,   220,    -1,    63,   223,   165,   220,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   342,   342,   343,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   370,   370,   371,   375,   379,
     383,   387,   391,   397,   397,   398,   399,   400,   401,   407,
     410,   410,   411,   411,   411,   411,   413,   432,   440,   451,
     454,   455,   456,   456,   457,   457,   458,   458,   459,   460,
     460,   461,   461,   462,   464,   519,   545,   559,   569,   578,
     592,   601,   631,   661,   677,   727,   729,   729,   730,   730,
     731,   731,   733,   742,   751,   763,   765,   766,   768,   768,
     769,   769,   770,   770,   771,   771,   772,   774,   778,   782,
     786,   793,   800,   807,   811,   815,   819,   823,   827,   831,
     837,   847,   846,   935,   935,   936,   936,   936,   936,   937,
     937,   937,   938,   938,   938,   939,   939,   940,   940,   940,
     941,   941,   943,   955,   978,   990,  1001,  1043,  1052,  1063,
    1074,  1085,  1096,  1107,  1118,  1129,  1140,  1151,  1166,  1165,
    1185,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,  1193,
    1194,  1195,  1197,  1242,  1248,  1254,  1260,  1266,  1272,  1278,
    1284,  1294,  1293,  1306,  1306,  1307,  1307,  1308,  1308,  1308,
    1310,  1312,  1312,  1314,  1318,  1330,  1332,  1332,  1334,  1338,
    1351,  1360,  1373,  1372,  1446,  1446,  1447,  1447,  1447,  1448,
    1448,  1448,  1449,  1449,  1449,  1450,  1450,  1451,  1451,  1451,
    1452,  1452,  1454,  1483,  1497,  1509,  1527,  1538,  1549,  1560,
    1571,  1582,  1593,  1604,  1614,  1623,  1632,  1647,  1646,  1659,
    1659,  1660,  1660,  1660,  1660,  1662,  1671,  1686,  1705,  1704,
    1720,  1720,  1721,  1721,  1721,  1721,  1723,  1732,  1742,  1741,
    1747,  1747,  1748,  1752,  1756,  1760,  1764,  1768,  1772,  1782,
    1781,  1797,  1797,  1798,  1798,  1798,  1800,  1807,  1806,  1812,
    1812,  1813,  1817,  1821,  1825,  1829,  1833,  1837,  1841,  1851,
    1850,  1986,  1986,  1987,  1987,  1987,  1988,  1988,  1988,  1989,
    1989,  1989,  1990,  1990,  1990,  1991,  1991,  1991,  1992,  1992,
    1993,  1995,  2007,  2016,  2034,  2052,  2058,  2062,  2070,  2079,
    2090,  2101,  2142,  2153,  2168,  2179,  2192,  2205,  2214,  2250,
    2249,  2272,  2272,  2273,  2273,  2273,  2275,  2284,  2297,  2296,
    2318,  2318,  2319,  2319,  2319,  2321,  2330,  2343,  2342,  2363,
    2363,  2364,  2364,  2366,  2379,  2378,  2392,  2392,  2393,  2393,
    2393,  2393,  2395,  2404,  2413,  2417,  2421,  2430,  2433,  2433,
    2434,  2434,  2435,  2435,  2436,  2436,  2437,  2437,  2438,  2438,
    2439,  2440,  2441,  2441,  2442,  2442,  2443,  2443,  2444,  2444,
    2445,  2445,  2446,  2446,  2447,  2447,  2448,  2448,  2449,  2449,
    2450,  2451,  2451,  2452,  2452,  2453,  2453,  2454,  2454,  2455,
    2455,  2456,  2456,  2457,  2458,  2458,  2459,  2459,  2460,  2460,
    2461,  2462,  2464,  2470,  2476,  2482,  2488,  2494,  2500,  2506,
    2512,  2518,  2524,  2530,  2541,  2547,  2553,  2559,  2565,  2571,
    2575,  2581,  2585,  2591,  2597,  2603,  2609,  2615,  2621,  2627,
    2633,  2641,  2649,  2655,  2666,  2672,  2678,  2684,  2690,  2696,
    2705,  2737,  2755,  2761,  2770,  2776,  2781,  2788,  2787,  2793,
    2793,  2794,  2798,  2802,  2806,  2810,  2814,  2818,  2822,  2826,
    2830,  2834,  2838,  2842,  2846,  2850,  2854,  2858,  2865,  2864,
    2870,  2870,  2871,  2875,  2879,  2883,  2887,  2891,  2895,  2899,
    2903,  2907,  2911,  2915,  2919,  2923,  2927,  2931,  2935,  2939,
    2945,  2951,  2957,  2963,  2969,  2975,  2984,  2987,  2987,  2988,
    2989,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,  2998,
    2999,  3000,  3001,  3003,  3009,  3015,  3021,  3027,  3033,  3039,
    3045,  3051,  3057,  3063,  3069,  3075,  3084,  3087,  3087,  3088,
    3088,  3089,  3090,  3091,  3092,  3093,  3095,  3101,  3107,  3121,
    3127,  3133
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "IRCD_AUTH",
  "AUTOCONN", "BASE_PATH", "BYTES", "KBYTES", "MBYTES", "GBYTES", "TBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIPHER_PREFERENCE", "CLASS",
  "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ", "CRYPTLINK",
  "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_HIDDEN",
  "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOT_IN_IP6_ADDR",
  "DOTS_IN_IDENT", "EGDPOOL_PATH", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME", "FLATTEN_LINKS",
  "FFAILED_OPERLOG", "FOPERLOG", "FUSERLOG", "GECOS", "GENERAL", "GLINE",
  "GLINES", "GLINE_EXEMPT", "GLINE_LOG", "GLINE_TIME", "GLOBAL_KILL",
  "HAVE_IDENT", "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_ADMIN",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB",
  "HUB_MASK", "IAUTH_PORT", "IAUTH_SERVER", "IDLETIME", "IGNORE_BOGUS_TS",
  "IP", "KILL", "KLINE", "KLINE_EXEMPT", "KLINE_WITH_CONNECTION_CLOSED",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LAZYLINK",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "LOGGING", "LOG_LEVEL",
  "MAXIMUM_LINKS", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MESSAGE_LOCALE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_IP", "NUMBER_PER_IP_GLOBAL",
  "OPERATOR", "OPER_LOG", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_UMODES", "CRYPT_OPER_PASSWORD", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PORT", "SSLPORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "RESTRICTED", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SSL_CERTIFICATE_FILE", "RESV", "SECONDS", "MINUTES", "HOURS", "DAYS",
  "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO",
  "SERVLINK_PATH", "SID", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "TREJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN", "T_CLIENT_FLOOD", "T_DEBUG",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR",
  "T_L_INFO", "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVNOTICE", "T_SERVCONN",
  "T_SKILL", "T_SPY", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "T_GOD", "T_NICKSERVREG", "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD",
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK",
  "USE_LOGGING", "VHOST", "VHOST6", "XLINE", "WARN", "WARN_NO_NLINE",
  "';'", "'}'", "'{'", "'='", "','", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
  "modules_base_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_rsa_private_key_file",
  "serverinfo_ssl_certificate_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_gline_log", "logging_fuserlog",
  "logging_ffailed_operlog", "logging_foperlog", "logging_log_level",
  "logging_use_logging", "oper_entry", "@1", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_hidden_admin",
  "oper_rsa_public_key_file", "oper_class", "oper_global_kill",
  "oper_remote", "oper_kline", "oper_xline", "oper_unkline", "oper_gline",
  "oper_nick_changes", "oper_die", "oper_rehash", "oper_admin",
  "class_entry", "@2", "class_items", "class_item", "class_name",
  "class_ping_time", "class_number_per_ip", "class_connectfreq",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "listen_entry", "@3", "listen_items",
  "listen_item", "listen_port", "port_items", "port_item",
  "listen_sslport", "sslport_items", "sslport_item", "listen_address",
  "listen_host", "auth_entry", "@4", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_spoof",
  "auth_exceed_limit", "auth_is_restricted", "auth_kline_exempt",
  "auth_have_ident", "auth_can_flood", "auth_no_tilde",
  "auth_gline_exempt", "auth_redir_serv", "auth_redir_port", "auth_class",
  "auth_need_password", "resv_entry", "@5", "resv_items", "resv_item",
  "resv_creason", "resv_channel", "resv_nick", "shared_entry", "@6",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "@7", "shared_types", "shared_type_item", "cluster_entry",
  "@8", "cluster_items", "cluster_item", "cluster_name", "cluster_type",
  "@9", "cluster_types", "cluster_type_item", "connect_entry", "@10",
  "connect_items", "connect_item", "connect_name", "connect_host",
  "connect_send_password", "connect_accept_password", "connect_port",
  "connect_aftype", "connect_fakename", "connect_lazylink",
  "connect_encrypted", "connect_rsa_public_key_file", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_cipher_preference",
  "kill_entry", "@11", "kill_items", "kill_item", "kill_user",
  "kill_reason", "deny_entry", "@12", "deny_items", "deny_item", "deny_ip",
  "deny_reason", "exempt_entry", "@13", "exempt_items", "exempt_item",
  "exempt_ip", "gecos_entry", "@14", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "gecos_action", "general_entry",
  "general_items", "general_item", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_kline_with_reason",
  "general_kline_with_connection_closed", "general_warn_no_nline",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_iauth_server", "general_iauth_port",
  "general_glines", "general_message_locale", "general_gline_time",
  "general_idletime", "general_dots_in_ident", "general_maximum_links",
  "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@15", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@16",
  "umode_items", "umode_item", "general_crypt_oper_password",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood",
  "general_dot_in_ip6_addr", "channel_entry", "channel_items",
  "channel_item", "channel_disable_local_channels", "channel_use_except",
  "channel_use_invex", "channel_use_knock", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_hide_servers",
  "serverhide_links_delay", "serverhide_hidden",
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
      59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   229,   229,   229,
     229,   229,   229,   230,   230,   231,   231,   231,   231,   232,
     233,   233,   234,   234,   234,   234,   235,   236,   237,   238,
     239,   239,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   253,   254,   254,
     254,   254,   255,   256,   257,   258,   259,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   261,   262,   263,
     264,   265,   266,   267,   267,   267,   267,   267,   267,   267,
     268,   270,   269,   271,   271,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   290,   289,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   303,   302,   304,   304,   305,   305,   305,   305,   305,
     306,   307,   307,   308,   308,   309,   310,   310,   311,   311,
     312,   313,   315,   314,   316,   316,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   334,   333,   335,
     335,   336,   336,   336,   336,   337,   338,   339,   341,   340,
     342,   342,   343,   343,   343,   343,   344,   345,   347,   346,
     348,   348,   349,   349,   349,   349,   349,   349,   349,   351,
     350,   352,   352,   353,   353,   353,   354,   356,   355,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   358,   360,
     359,   361,   361,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   364,   365,   366,   367,   368,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   381,
     380,   382,   382,   383,   383,   383,   384,   385,   387,   386,
     388,   388,   389,   389,   389,   390,   391,   393,   392,   394,
     394,   395,   395,   396,   398,   397,   399,   399,   400,   400,
     400,   400,   401,   402,   403,   403,   403,   404,   405,   405,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     424,   425,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   451,   450,   452,
     452,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   455,   454,
     456,   456,   457,   457,   457,   457,   457,   457,   457,   457,
     457,   457,   457,   457,   457,   457,   457,   457,   457,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   465,   466,
     466,   466,   466,   466,   466,   466,   466,   466,   466,   466,
     466,   466,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   481,   482,
     482,   482,   482,   482,   482,   482,   483,   484,   485,   486,
     487,   488
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     1,     2,     3,     3,
       3,     3,     3,     0,     1,     2,     3,     3,     3,     5,
       2,     1,     1,     1,     1,     1,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     3,     4,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,   192,     0,   148,   279,   328,
     337,   344,     0,   319,   171,     0,     0,   111,   227,     0,
       0,   238,   259,     3,    22,    11,     4,     5,     6,     8,
       9,    10,    13,    14,    15,    16,    17,    18,    19,    21,
      20,     7,    12,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,     0,     0,     0,     0,    77,
      78,    80,    79,     0,   522,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   508,
     509,   510,   511,   512,   514,   515,   516,   517,   513,   518,
     519,   520,   521,     0,     0,     0,     0,     0,   411,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,     0,   457,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,   402,   362,   363,   364,   365,   366,
     367,   368,   369,   407,   370,   371,   372,   374,   379,   375,
     377,   376,   397,   378,   380,   381,   382,   383,   384,   385,
     386,   390,   387,   388,   373,   389,   392,   401,   403,   404,
     393,   394,   409,   410,   406,   395,   391,   396,   399,   400,
     398,   405,   408,     0,     0,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    88,    89,    90,    93,
      95,    94,    91,    92,    45,     0,     0,     0,     0,    41,
      42,    44,    43,     0,     0,   545,     0,     0,     0,     0,
       0,     0,     0,   538,   539,   540,   541,   543,   542,   544,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    59,    61,    52,    62,    55,    56,
      57,    53,    60,    58,    54,     0,     0,     0,     0,     0,
       0,    76,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   195,
     196,   197,   206,   205,   202,   201,   199,   200,   209,   203,
     204,   207,   208,   198,   210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   507,
     161,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   295,
     298,   297,   296,   294,   291,   292,   293,   299,   334,     0,
       0,     0,   331,   332,   333,   342,     0,     0,   340,   341,
     351,     0,     0,     0,     0,   347,   348,   349,   350,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   358,   325,     0,     0,     0,   322,   323,   324,   179,
       0,     0,     0,     0,     0,   174,   175,   176,   177,   178,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,    40,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   130,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     234,     0,     0,     0,     0,   230,   231,   232,   233,     0,
       0,     0,     0,     0,     0,     0,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
     245,     0,   248,     0,     0,   241,   242,   243,   244,   265,
       0,   267,     0,   262,   263,   264,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   194,     0,     0,     0,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   281,     0,     0,     0,   330,     0,     0,   339,     0,
       0,     0,     0,   346,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,   357,     0,
       0,     0,   321,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,     0,     0,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
     229,     0,     0,     0,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,     0,     0,   240,     0,     0,     0,   261,    84,
      83,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   193,   533,   532,
     523,    25,    25,    25,    25,    25,    27,    26,   527,   528,
     531,   529,   534,   535,   530,   524,   525,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   280,     0,     0,   329,
       0,   338,     0,     0,     0,     0,     0,   345,   416,   420,
     434,   451,   450,   503,   455,   414,   505,   446,   453,   415,
     442,   444,   423,   412,   441,   440,   445,   413,   425,   424,
     447,   419,   418,   417,   448,   443,   501,   502,   437,   482,
     497,   483,   484,   491,   485,   495,   498,   487,   492,   488,
     493,   494,   486,   490,   489,   496,   499,     0,   481,   439,
     461,   476,   462,   463,   470,   464,   474,   477,   466,   471,
     467,   472,   473,   465,   469,   468,   475,     0,   460,   500,
     433,   435,   454,   449,   436,   431,   432,   429,   430,   427,
     428,   422,   421,    33,    33,    33,    35,    34,   504,   456,
     438,   452,   426,     0,     0,   320,     0,     0,   183,     0,
     182,   188,     0,   187,   172,   101,   102,   100,    99,   103,
     109,   104,   108,   106,   107,   105,    98,    97,   110,    48,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,   228,   550,   546,   549,   551,   547,   548,    68,
      74,    66,    70,    69,    64,    65,    67,    73,    71,    72,
       0,     0,     0,   239,     0,     0,   260,   220,   225,   216,
     222,   219,   218,   226,   221,   213,   224,   223,   217,   215,
     214,   212,    28,    29,    30,    31,    32,   165,   167,   169,
     168,   166,   162,   164,   163,   170,   304,   306,   307,   314,
     318,   317,   313,   312,   310,   308,   302,   315,   309,   316,
     301,   305,   311,   303,   335,   336,   343,   356,   355,   354,
     352,   353,   479,     0,   458,     0,    36,    37,    38,   327,
     326,   191,   190,     0,   180,     0,     0,   185,     0,   147,
     137,   145,   143,   138,   135,   140,   132,   144,   134,   146,
     139,   136,   142,   133,   141,   236,   237,   235,   246,   252,
     256,   258,   257,   255,   253,   254,     0,   251,   247,   266,
     271,   275,   278,   277,   276,   274,   272,   273,     0,   270,
     480,   459,   184,   181,   189,   186,   249,     0,   268,     0,
     250,   269
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    23,   826,   827,   966,   967,    24,   238,   239,
     240,   241,   242,    25,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,    26,    68,    69,
      70,    71,    72,    27,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,    28,    58,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,    29,    48,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,    30,    55,   484,
     485,   486,   979,   980,   487,   982,   983,   488,   489,    31,
      46,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,    32,    59,
     544,   545,   546,   547,   548,    33,    62,   574,   575,   576,
     577,   578,   791,  1146,  1147,    34,    63,   582,   583,   584,
     585,   796,  1158,  1159,    35,    49,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,    36,    54,   475,   476,   477,
     478,    37,    50,   401,   402,   403,   404,    38,    51,   407,
     408,   409,    39,    52,   414,   415,   416,   417,   418,    40,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   452,   947,   948,   206,
     450,   927,   928,   207,   208,   209,   210,   211,   212,    41,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    42,   252,   253,   254,   255,
     256,   257,   258,   259
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -647
static const short int yypact[] =
{
    -647,   602,  -647,  -177,  -216,  -647,  -202,  -647,  -647,  -647,
    -647,  -647,  -199,  -647,  -647,  -196,  -191,  -647,  -647,  -188,
    -186,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   107,  -165,   488,  -162,  -160,
    -153,  -148,  -135,   351,  -112,  -103,   405,    14,   -92,   -79,
     380,   393,   -76,   -68,  -647,  -171,   -66,   -48,    15,  -647,
    -647,  -647,  -647,   558,  -647,   -40,   -32,   -14,    -7,    -6,
       6,    30,    40,    43,    44,    49,    60,    65,   189,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   635,   629,    18,    21,    41,  -647,    66,
      68,    70,    74,    82,    87,    91,    92,    97,   104,   108,
     109,   110,   111,   112,   118,   120,   122,   123,   124,   127,
     128,   130,   131,   132,   137,   139,   141,   142,   149,   150,
    -647,   152,  -647,   153,   160,   161,   170,   174,   180,   181,
     184,   186,   190,   191,   194,   207,   208,   209,   210,   211,
       1,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,     4,   116,  -647,   212,   214,   219,   224,
     229,   234,   235,   236,   280,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   242,   243,   244,    79,  -647,
    -647,  -647,  -647,   435,    48,  -647,   246,   253,   254,   263,
     264,   267,    50,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   269,   272,   277,   279,   281,   282,   283,   284,   286,
     288,   293,   203,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,    31,    47,   101,   133,   171,
      22,  -647,  -647,   298,   299,   302,   304,   305,   306,   307,
     308,   310,   312,   313,   314,   316,   317,   318,   178,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,   125,   226,    59,   250,   250,
     256,   429,    76,   217,   227,   247,   261,   379,   325,  -647,
    -647,   324,   326,   327,   328,   329,   330,   331,   332,   333,
     159,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   339,   340,   341,   342,   343,   346,   350,   357,
     359,   360,   361,   363,   364,   365,   367,   368,   369,   146,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   370,
     371,     9,  -647,  -647,  -647,  -647,   372,    13,  -647,  -647,
    -647,   373,   376,   377,    26,  -647,  -647,  -647,  -647,   383,
     250,   250,   461,   473,   492,   441,   445,   447,   501,   484,
     451,   453,   250,   509,   459,   512,   496,   250,   463,   464,
     466,   524,   525,   527,   250,   528,   511,   532,   534,   491,
     434,   493,   436,   498,   250,   250,   499,   530,   500,   -63,
      29,   502,   503,   250,   250,   553,   250,   504,   507,   508,
     454,  -647,  -647,   455,   456,    52,  -647,  -647,  -647,  -647,
     457,   458,   462,   465,     2,  -647,  -647,  -647,  -647,  -647,
     551,   559,   560,   563,   294,   567,   571,   519,   483,  -647,
     574,   575,   578,   495,  -647,  -647,   489,   490,   497,   510,
     513,   514,   516,   517,   518,   520,   522,   523,   526,   531,
     536,   537,   140,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   538,   539,   550,    64,  -647,  -647,  -647,  -647,   556,
     557,   564,   565,   569,   250,   505,  -647,   585,   570,   593,
     611,   616,   617,   620,   624,   661,   645,   646,   561,  -647,
    -647,   577,  -647,   579,    75,  -647,  -647,  -647,  -647,  -647,
     583,  -647,    83,  -647,  -647,  -647,   562,   573,   587,  -647,
     614,   649,   619,   644,   647,   648,   650,   651,   663,   697,
     680,   652,   683,   662,   695,   609,  -647,   610,   612,   613,
     179,   615,   618,   621,   622,   623,   626,   627,   628,   630,
     631,  -647,   250,   718,   721,   723,   724,   708,   727,   250,
     553,   632,  -647,   713,    19,   684,   714,   722,   689,   690,
     691,   726,   728,   729,   693,   730,   731,   750,   733,   734,
     653,  -647,   735,   736,   654,  -647,   737,   655,  -647,  -154,
     738,   739,   656,  -647,   657,   658,   659,   660,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   681,   682,   685,   686,   687,   688,
     692,   694,   696,   698,   699,   592,   700,   625,   701,   702,
     703,   704,   705,   706,   707,   709,   710,   711,   712,   715,
     716,   717,    93,   719,   720,   725,   732,   740,  -647,   741,
     751,   742,  -647,   752,   769,   758,   768,   743,  -647,   744,
     745,   746,   747,   748,   749,   753,   754,   755,   756,   757,
     759,   760,   761,  -647,   762,   763,   764,  -647,   773,   772,
     776,   777,   778,   779,   781,   780,   782,   784,   783,   785,
     786,   788,   797,   789,   765,  -647,   802,   803,   818,   766,
    -647,   767,   770,   771,   774,   775,   787,  -647,   790,   791,
     792,   793,   794,   795,   796,   798,   799,   800,   801,  -647,
     820,   804,   824,   805,  -647,   825,   806,   808,  -647,  -647,
    -647,  -647,   810,   811,   812,   813,   814,   815,   816,   817,
     819,   821,   822,   823,   826,   827,   828,  -647,  -647,  -647,
    -647,   250,   250,   250,   250,   250,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   829,   830,
     831,   832,   833,   834,   835,   836,   837,  -647,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,   851,   852,   853,   854,   855,  -647,   856,   857,  -647,
     858,  -647,   859,   860,   861,   862,   863,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -213,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -203,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   553,   553,   553,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   864,   865,  -647,   866,   867,   868,  -187,
    -647,   870,  -170,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,   869,   871,   872,   873,   874,   875,   876,   877,
     878,   879,   880,   881,   882,   883,   884,   885,  -647,   886,
     887,   888,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     889,   169,   890,  -647,   891,   506,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   592,  -647,   625,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,   892,  -647,   758,   893,  -647,   768,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -161,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -143,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   169,  -647,   506,
    -647,  -647
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -647,  -647,  -647,  -565,  -328,  -646,  -453,  -647,  -647,   807,
    -647,  -647,  -647,  -647,  -647,   637,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   902,
    -647,  -647,  -647,  -647,  -647,   894,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   382,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   607,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
     426,  -647,  -647,  -157,  -647,  -647,  -205,  -647,  -647,  -647,
    -647,  -647,   809,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   415,  -647,  -647,  -647,  -647,  -647,  -647,   387,  -647,
    -647,  -647,  -647,  -647,  -195,  -647,  -647,  -647,   389,  -647,
    -647,  -647,  -647,  -181,  -647,  -647,  -647,   599,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,   521,  -647,
    -647,  -647,  -647,  -647,   588,  -647,  -647,  -647,  -647,  -647,
     586,  -647,  -647,  -647,  -647,   584,  -647,  -647,  -647,  -647,
    -647,   928,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -113,  -647,
    -647,  -647,  -106,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,   911,  -647,  -647,  -647,  -647,  -647,  -647,  -647,  -647,
    -647,  -647,  -647,  -647,  -647,  -647,  -647,   895,  -647,  -647,
    -647,  -647,  -647,  -647
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     611,   612,   108,   479,   872,   472,    45,  1102,   109,   110,
     398,  1103,   713,   873,   405,   234,    64,  1104,   111,   398,
      47,  1105,   405,    53,   112,   235,    56,   410,   113,   114,
     411,    57,   570,  1114,    60,   115,    61,  1115,   116,   117,
     118,   119,   410,    43,    44,   411,   120,    65,   579,   540,
    1117,   245,   287,   472,  1118,   121,    66,    73,   122,  1166,
     103,   123,   104,  1167,   874,   540,   124,   541,   480,   105,
     125,   126,   127,   128,   106,   481,   570,  1168,   129,   130,
     234,  1169,   399,   541,   579,   246,   406,   107,   131,   132,
     235,   399,   665,   666,   406,   133,   134,   247,   135,   136,
     137,   138,   704,   705,   677,   963,   964,   965,    64,   682,
     213,   248,   139,   249,   250,   236,   689,   479,    67,   214,
     140,   141,   142,   143,   144,   145,   699,   700,   146,   412,
     243,   482,   483,   251,   571,   710,   711,   473,   714,    65,
     237,   505,   400,   244,   412,   506,   285,   361,    66,   362,
     580,   400,   363,   147,   286,   542,   364,   288,   148,   413,
     340,   507,   149,   150,   151,   152,   365,   366,   367,   153,
     154,   542,   368,   508,   413,   289,   155,   846,   571,   292,
     236,   543,   480,   325,   341,   473,   580,   572,   369,   481,
      74,   326,   370,   509,   706,   707,   293,   543,   510,   294,
     849,   850,   511,   581,   260,   237,   712,   156,   157,   327,
      67,   158,   371,   474,   372,   512,   328,   329,    75,    76,
     159,   295,   470,   727,   609,    77,   776,   373,   374,   330,
     654,   572,   586,   296,   657,   261,   290,   297,   607,   581,
     573,   615,   589,   513,  1139,   482,   483,   662,   514,   375,
     342,   343,   344,   331,   298,   345,  1062,  1063,  1064,  1065,
    1066,   474,   346,   332,   587,   515,   333,   334,    78,    79,
     262,   555,   335,   721,   347,   376,   516,   517,    80,    81,
     518,   215,   299,   336,   573,   769,   377,   348,   337,   419,
     300,   420,   610,   421,   838,   378,   793,   422,    82,    83,
     503,   845,   588,   301,   797,   423,   263,   349,   264,   265,
     424,  1140,   302,   303,   425,   426,   304,  1106,  1107,  1108,
     427,    84,   821,   822,   823,   824,   825,   428,   216,   217,
     218,   429,   430,   431,   432,   433,   219,   305,   306,   608,
    1141,   434,   266,   435,   267,   436,   437,   438,   519,   520,
     439,   440,   108,   441,   442,   443,   268,   521,   109,   110,
     444,   764,   445,   610,   446,   447,   220,   650,   111,   613,
    1142,  1143,   448,   449,   112,   451,   453,  1144,   113,   114,
     631,   245,   616,   454,   455,   115,  1145,   307,   116,   117,
     118,   119,   617,   456,   260,   269,   120,   457,   221,   605,
      85,    86,    87,   458,   459,   121,   215,   460,   122,   461,
     338,   123,   618,   462,   463,   246,   124,   464,   270,   271,
     125,   126,   127,   128,   568,   261,   619,   247,   129,   130,
     465,   466,   467,   468,   469,   490,   505,   491,   131,   132,
     506,   248,   492,   249,   250,   133,   134,   493,   135,   136,
     137,   138,   494,   216,   217,   218,   507,   495,   496,   497,
     262,   219,   139,   251,   222,   500,   501,   502,   508,   549,
     140,   141,   142,   143,   144,   145,   550,   551,   146,   733,
     734,   735,   736,   737,   738,   739,   552,   553,   509,    74,
     554,   220,   557,   510,   223,   558,   263,   511,   264,   265,
     559,   498,   560,   147,   561,   562,   563,   564,   148,   565,
     512,   566,   149,   150,   151,   152,   567,    75,    76,   153,
     154,   590,   591,   221,    77,   592,   155,   593,   594,   595,
     596,   597,   266,   598,   267,   599,   600,   601,   513,   602,
     603,   604,   614,   514,   620,   621,   268,   622,   664,   623,
     624,   625,   626,   627,   628,   629,   630,   156,   157,   292,
     515,   158,   633,   634,   635,   636,   637,    78,    79,   638,
     159,   516,   517,   639,   667,   518,   293,    80,    81,   294,
     640,  1150,   641,   642,   643,   269,   644,   645,   646,   222,
     647,   648,   649,   652,   653,   656,   659,    82,    83,   660,
     661,   295,     2,     3,   668,   669,   670,     4,   270,   271,
     671,     5,   672,   296,   673,   674,   675,   297,   676,   223,
      84,     6,   678,     7,   679,   680,     8,   681,   683,   684,
     361,   685,   362,     9,   298,   363,   340,   686,   687,   364,
     688,   690,   691,   519,   520,   692,    10,   693,  1151,   365,
     366,   367,   521,    11,    12,   368,   694,   695,   696,   697,
     341,   702,   299,   698,   701,   703,   712,   708,   709,   715,
     300,   369,   716,   717,   718,   370,    13,  1152,   719,   720,
     723,   724,   729,   301,   742,   725,    14,    15,   726,  1153,
     730,   731,   302,   303,   732,   371,   304,   372,   740,    85,
      86,    87,   741,   743,    16,   744,   745,  1154,  1155,   746,
     373,   374,   748,   749,  1156,   747,   778,   305,   306,    17,
     750,   771,   772,  1157,   780,   777,   342,   343,   344,   773,
     774,   345,   375,   751,   775,   779,   752,   753,   346,   754,
     755,   756,   781,   757,    18,   758,   759,   782,   783,   760,
     347,   784,    19,    20,   761,   785,    21,    22,   376,   762,
     763,   766,   767,   348,   909,   910,   911,   307,   912,   377,
     913,   914,   915,   768,   786,   916,   787,   788,   378,   802,
     803,   789,   799,   349,   804,   917,   918,   919,   920,   921,
     922,   923,   924,   800,   810,   925,   926,   930,   931,   932,
     790,   933,   792,   934,   935,   936,   795,   801,   937,   805,
     811,   812,   806,   807,   814,   808,   809,   813,   938,   939,
     940,   941,   942,   943,   944,   945,   816,   815,   946,   817,
     818,   839,   819,   820,   840,   828,   841,   842,   829,   843,
     844,   830,   831,   832,   848,   852,   833,   834,   835,   851,
     836,   837,   847,   853,   854,   855,   856,   857,   860,   858,
     859,   861,   862,   863,   864,   865,   867,   868,   870,   875,
     876,   978,   973,   866,   869,   871,   877,   878,   879,   880,
     881,   981,   974,   976,   882,   883,   884,   885,   886,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     977,   898,   899,  1003,   765,   900,   901,   902,   903,   569,
     728,  1009,   904,  1165,   905,  1011,   906,  1014,   907,   908,
     929,   949,   950,   951,   952,   953,   954,   955,  1016,   956,
     957,   958,   959,  1019,  1020,   960,   961,   962,  1002,   968,
     969,  1004,  1005,  1006,  1007,   970,  1008,  1010,  1012,  1021,
    1013,  1040,   971,  1015,  1017,  1042,  1044,   632,  1163,   770,
     972,   794,   975,   984,   985,   986,   987,   988,   989,   990,
     291,   798,  1170,   991,   992,   993,   994,   995,   651,   996,
     997,   998,   999,  1000,  1001,  1018,  1022,  1023,  1171,   655,
    1024,  1025,  1161,   658,  1026,  1027,   722,  1160,   663,   339,
       0,     0,     0,     0,     0,  1162,  1164,  1028,     0,     0,
    1029,  1030,  1031,  1032,  1033,  1034,  1035,     0,  1036,  1037,
    1038,  1039,     0,     0,     0,  1043,     0,  1041,  1046,  1045,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1113,  1055,
    1116,  1056,  1057,  1058,     0,   504,  1059,  1060,  1061,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1109,  1110,  1111,  1112,   471,  1119,
       0,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1148,  1149,     0,     0,     0,     0,     0,   606,   499,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   556
};

static const short int yycheck[] =
{
     328,   329,     1,     1,   158,     1,   222,   220,     7,     8,
       1,   224,   465,   167,     1,     1,     1,   220,    17,     1,
     222,   224,     1,   222,    23,    11,   222,     1,    27,    28,
       4,   222,     1,   220,   222,    34,   222,   224,    37,    38,
      39,    40,     1,   220,   221,     4,    45,    32,     1,     1,
     220,     1,   223,     1,   224,    54,    41,   222,    57,   220,
     222,    60,   222,   224,   218,     1,    65,    19,    66,   222,
      69,    70,    71,    72,   222,    73,     1,   220,    77,    78,
       1,   224,    73,    19,     1,    35,    73,   222,    87,    88,
      11,    73,   420,   421,    73,    94,    95,    47,    97,    98,
      99,   100,   165,   166,   432,    12,    13,    14,     1,   437,
     222,    61,   111,    63,    64,   101,   444,     1,   103,   222,
     119,   120,   121,   122,   123,   124,   454,   455,   127,   103,
     222,   129,   130,    83,   103,   463,   464,   133,   466,    32,
     126,     1,   133,   222,   103,     5,   222,     1,    41,     3,
     103,   133,     6,   152,   222,   107,    10,   223,   157,   133,
       1,    21,   161,   162,   163,   164,    20,    21,    22,   168,
     169,   107,    26,    33,   133,   223,   175,   630,   103,     1,
     101,   133,    66,   223,    25,   133,   103,   156,    42,    73,
       1,   223,    46,    53,   165,   166,    18,   133,    58,    21,
     181,   182,    62,   156,     1,   126,   113,   206,   207,   223,
     103,   210,    66,   209,    68,    75,   223,   223,    29,    30,
     219,    43,   221,   221,   165,    36,   554,    81,    82,   223,
     221,   156,   131,    55,   221,    32,   221,    59,   113,   156,
     209,   165,   220,   103,    75,   129,   130,   221,   108,   103,
      91,    92,    93,   223,    76,    96,   821,   822,   823,   824,
     825,   209,   103,   223,   131,   125,   223,   223,    79,    80,
      67,   221,   223,   221,   115,   129,   136,   137,    89,    90,
     140,     1,   104,   223,   209,   221,   140,   128,   223,   223,
     112,   223,   113,   223,   622,   149,   221,   223,   109,   110,
     221,   629,   131,   125,   221,   223,   103,   148,   105,   106,
     223,   142,   134,   135,   223,   223,   138,   963,   964,   965,
     223,   132,   143,   144,   145,   146,   147,   223,    48,    49,
      50,   223,   223,   223,   223,   223,    56,   159,   160,   113,
     171,   223,   139,   223,   141,   223,   223,   223,   208,   209,
     223,   223,     1,   223,   223,   223,   153,   217,     7,     8,
     223,   221,   223,   113,   223,   223,    86,   221,    17,   113,
     201,   202,   223,   223,    23,   223,   223,   208,    27,    28,
     221,     1,   165,   223,   223,    34,   217,   209,    37,    38,
      39,    40,   165,   223,     1,   192,    45,   223,   118,   221,
     211,   212,   213,   223,   223,    54,     1,   223,    57,   223,
     221,    60,   165,   223,   223,    35,    65,   223,   215,   216,
      69,    70,    71,    72,   221,    32,   165,    47,    77,    78,
     223,   223,   223,   223,   223,   223,     1,   223,    87,    88,
       5,    61,   223,    63,    64,    94,    95,   223,    97,    98,
      99,   100,   223,    48,    49,    50,    21,   223,   223,   223,
      67,    56,   111,    83,   184,   223,   223,   223,    33,   223,
     119,   120,   121,   122,   123,   124,   223,   223,   127,   185,
     186,   187,   188,   189,   190,   191,   223,   223,    53,     1,
     223,    86,   223,    58,   214,   223,   103,    62,   105,   106,
     223,   221,   223,   152,   223,   223,   223,   223,   157,   223,
      75,   223,   161,   162,   163,   164,   223,    29,    30,   168,
     169,   223,   223,   118,    36,   223,   175,   223,   223,   223,
     223,   223,   139,   223,   141,   223,   223,   223,   103,   223,
     223,   223,   113,   108,   165,   220,   153,   223,   165,   223,
     223,   223,   223,   223,   223,   223,   223,   206,   207,     1,
     125,   210,   223,   223,   223,   223,   223,    79,    80,   223,
     219,   136,   137,   223,   113,   140,    18,    89,    90,    21,
     223,    75,   223,   223,   223,   192,   223,   223,   223,   184,
     223,   223,   223,   223,   223,   223,   223,   109,   110,   223,
     223,    43,     0,     1,   131,   113,   165,     5,   215,   216,
     165,     9,   165,    55,   113,   131,   165,    59,   165,   214,
     132,    19,   113,    21,   165,   113,    24,   131,   165,   165,
       1,   165,     3,    31,    76,     6,     1,   113,   113,    10,
     113,   113,   131,   208,   209,   113,    44,   113,   142,    20,
      21,    22,   217,    51,    52,    26,   165,   223,   165,   223,
      25,   131,   104,   165,   165,   165,   113,   165,   165,   165,
     112,    42,   165,   165,   220,    46,    74,   171,   223,   223,
     223,   223,   131,   125,   165,   223,    84,    85,   223,   183,
     131,   131,   134,   135,   131,    66,   138,    68,   131,   211,
     212,   213,   131,   220,   102,   131,   131,   201,   202,   131,
      81,    82,   223,   223,   208,   220,   131,   159,   160,   117,
     223,   165,   165,   217,   131,   220,    91,    92,    93,   165,
     165,    96,   103,   223,   165,   165,   223,   223,   103,   223,
     223,   223,   131,   223,   142,   223,   223,   131,   131,   223,
     115,   131,   150,   151,   223,   131,   154,   155,   129,   223,
     223,   223,   223,   128,   172,   173,   174,   209,   176,   140,
     178,   179,   180,   223,   113,   183,   131,   131,   149,   165,
     131,   220,   220,   148,   165,   193,   194,   195,   196,   197,
     198,   199,   200,   220,   131,   203,   204,   172,   173,   174,
     223,   176,   223,   178,   179,   180,   223,   220,   183,   165,
     113,   131,   165,   165,   131,   165,   165,   165,   193,   194,
     195,   196,   197,   198,   199,   200,   131,   165,   203,   220,
     220,   113,   220,   220,   113,   220,   113,   113,   220,   131,
     113,   220,   220,   220,   131,   131,   220,   220,   220,   165,
     220,   220,   220,   131,   165,   165,   165,   131,   165,   131,
     131,   131,   131,   113,   131,   131,   131,   131,   131,   131,
     131,   113,   131,   220,   220,   220,   220,   220,   220,   220,
     220,   113,   131,   131,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     131,   220,   220,   131,   522,   220,   220,   220,   220,   272,
     484,   131,   220,  1118,   220,   131,   220,   131,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   131,   220,
     220,   220,   220,   131,   131,   220,   220,   220,   165,   220,
     220,   165,   165,   165,   165,   220,   165,   165,   165,   131,
     165,   131,   220,   165,   165,   131,   131,   350,  1115,   544,
     220,   574,   220,   220,   220,   220,   220,   220,   220,   220,
      68,   582,  1167,   220,   220,   220,   220,   220,   379,   220,
     220,   220,   220,   220,   220,   220,   220,   220,  1169,   401,
     220,   220,  1105,   407,   220,   220,   475,  1103,   414,    88,
      -1,    -1,    -1,    -1,    -1,   113,   113,   220,    -1,    -1,
     220,   220,   220,   220,   220,   220,   220,    -1,   220,   220,
     220,   220,    -1,    -1,    -1,   220,    -1,   223,   220,   223,
     220,   220,   220,   220,   220,   220,   220,   220,   170,   220,
     170,   220,   220,   220,    -1,   238,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   160,   220,
      -1,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,    -1,    -1,    -1,    -1,    -1,   308,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   252
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   226,     0,     1,     5,     9,    19,    21,    24,    31,
      44,    51,    52,    74,    84,    85,   102,   117,   142,   150,
     151,   154,   155,   227,   232,   238,   252,   258,   269,   289,
     302,   314,   333,   340,   350,   359,   380,   386,   392,   397,
     404,   464,   480,   220,   221,   222,   315,   222,   290,   360,
     387,   393,   398,   222,   381,   303,   222,   222,   270,   334,
     222,   222,   341,   351,     1,    32,    41,   103,   253,   254,
     255,   256,   257,   222,     1,    29,    30,    36,    79,    80,
      89,    90,   109,   110,   132,   211,   212,   213,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   222,   222,   222,   222,   222,     1,     7,
       8,    17,    23,    27,    28,    34,    37,    38,    39,    40,
      45,    54,    57,    60,    65,    69,    70,    71,    72,    77,
      78,    87,    88,    94,    95,    97,    98,    99,   100,   111,
     119,   120,   121,   122,   123,   124,   127,   152,   157,   161,
     162,   163,   164,   168,   169,   175,   206,   207,   210,   219,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   454,   458,   459,   460,
     461,   462,   463,   222,   222,     1,    48,    49,    50,    56,
      86,   118,   184,   214,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,     1,    11,   101,   126,   233,   234,
     235,   236,   237,   222,   222,     1,    35,    47,    61,    63,
      64,    83,   481,   482,   483,   484,   485,   486,   487,   488,
       1,    32,    67,   103,   105,   106,   139,   141,   153,   192,
     215,   216,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   222,   222,   223,   223,   223,
     221,   254,     1,    18,    21,    43,    55,    59,    76,   104,
     112,   125,   134,   135,   138,   159,   160,   209,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   221,   466,
       1,    25,    91,    92,    93,    96,   103,   115,   128,   148,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,     1,     3,     6,    10,    20,    21,    22,    26,    42,
      46,    66,    68,    81,    82,   103,   129,   140,   149,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,     1,    73,
     133,   388,   389,   390,   391,     1,    73,   394,   395,   396,
       1,     4,   103,   133,   399,   400,   401,   402,   403,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     455,   223,   451,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     221,   406,     1,   133,   209,   382,   383,   384,   385,     1,
      66,    73,   129,   130,   304,   305,   306,   309,   312,   313,
     223,   223,   223,   223,   223,   223,   223,   223,   221,   260,
     223,   223,   223,   221,   234,     1,     5,    21,    33,    53,
      58,    62,    75,   103,   108,   125,   136,   137,   140,   208,
     209,   217,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
       1,    19,   107,   133,   335,   336,   337,   338,   339,   223,
     223,   223,   223,   223,   223,   221,   482,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   221,   240,
       1,   103,   156,   209,   342,   343,   344,   345,   346,     1,
     103,   156,   352,   353,   354,   355,   131,   131,   131,   220,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   221,   317,   113,   113,   165,
     113,   229,   229,   113,   113,   165,   165,   165,   165,   165,
     165,   220,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   221,   292,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     221,   362,   223,   223,   221,   389,   223,   221,   395,   223,
     223,   223,   221,   400,   165,   229,   229,   113,   131,   113,
     165,   165,   165,   113,   131,   165,   165,   229,   113,   165,
     113,   131,   229,   165,   165,   165,   113,   113,   113,   229,
     113,   131,   113,   113,   165,   223,   165,   223,   165,   229,
     229,   165,   131,   165,   165,   166,   165,   166,   165,   165,
     229,   229,   113,   231,   229,   165,   165,   165,   220,   223,
     223,   221,   383,   223,   223,   223,   223,   221,   305,   131,
     131,   131,   131,   185,   186,   187,   188,   189,   190,   191,
     131,   131,   165,   220,   131,   131,   131,   220,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   221,   272,   223,   223,   223,   221,
     336,   165,   165,   165,   165,   165,   229,   220,   131,   165,
     131,   131,   131,   131,   131,   131,   113,   131,   131,   220,
     223,   347,   223,   221,   343,   223,   356,   221,   353,   220,
     220,   220,   165,   131,   165,   165,   165,   165,   165,   165,
     131,   113,   131,   165,   131,   165,   131,   220,   220,   220,
     220,   143,   144,   145,   146,   147,   228,   229,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   229,   113,
     113,   113,   113,   131,   113,   229,   231,   220,   131,   181,
     182,   165,   131,   131,   165,   165,   165,   131,   131,   131,
     165,   131,   131,   113,   131,   131,   220,   131,   131,   220,
     131,   220,   158,   167,   218,   131,   131,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   172,
     173,   174,   176,   178,   179,   180,   183,   193,   194,   195,
     196,   197,   198,   199,   200,   203,   204,   456,   457,   220,
     172,   173,   174,   176,   178,   179,   180,   183,   193,   194,
     195,   196,   197,   198,   199,   200,   203,   452,   453,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,    12,    13,    14,   230,   231,   220,   220,
     220,   220,   220,   131,   131,   220,   131,   131,   113,   307,
     308,   113,   310,   311,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   165,   131,   165,   165,   165,   165,   165,   131,
     165,   131,   165,   165,   131,   165,   131,   165,   220,   131,
     131,   131,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     131,   223,   131,   220,   131,   223,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   228,   228,   228,   228,   228,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   224,   220,   224,   230,   230,   230,   220,
     220,   220,   220,   170,   220,   224,   170,   220,   224,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,    75,
     142,   171,   201,   202,   208,   217,   348,   349,   220,   220,
      75,   142,   171,   183,   201,   202,   208,   217,   357,   358,
     457,   453,   113,   308,   113,   311,   220,   224,   220,   224,
     349,   358
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

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
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
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
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
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

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
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
  /* Lookahead token as an internal (translated) token number.  */
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
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

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
        case 25:
#line 370 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 27:
#line 372 "ircd_parser.y"
    {
			yyval.number = yyvsp[-1].number + yyvsp[0].number;
		}
    break;

  case 28:
#line 376 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number + yyvsp[0].number;
		}
    break;

  case 29:
#line 380 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 + yyvsp[0].number;
		}
    break;

  case 30:
#line 384 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 + yyvsp[0].number;
		}
    break;

  case 31:
#line 388 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 + yyvsp[0].number;
		}
    break;

  case 32:
#line 392 "ircd_parser.y"
    {
			yyval.number = yyvsp[-2].number * 60 * 60 * 24 * 7 + yyvsp[0].number;
		}
    break;

  case 33:
#line 397 "ircd_parser.y"
    { yyval.number = 0; }
    break;

  case 35:
#line 398 "ircd_parser.y"
    { yyval.number = yyvsp[-1].number + yyvsp[0].number; }
    break;

  case 36:
#line 399 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number + yyvsp[0].number; }
    break;

  case 37:
#line 400 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 + yyvsp[0].number; }
    break;

  case 38:
#line 401 "ircd_parser.y"
    { yyval.number = yyvsp[-2].number * 1024 * 1024 + yyvsp[0].number; }
    break;

  case 46:
#line 414 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    if (findmodule_byname(m_bn) == -1)
      /* XXX - should we unload this module on /rehash, if it isn't listed? */
      load_one_module(yylval.string, 0);
  }
#endif
}
    break;

  case 47:
#line 433 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 48:
#line 441 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
     mod_set_base(yylval.string);
#endif
}
    break;

  case 64:
#line 465 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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
      yyerror("Ignoring config file entry rsa_private_key -- file open failed");
      break;
    }

    ServerInfo.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Ignoring config file entry rsa_private_key -- "
              "couldn't extract key");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      yyerror("Ignoring config file entry rsa_private_key -- invalid key");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      yyerror("Ignoring config file entry rsa_private_key -- not 2048 bit");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif
}
    break;

  case 65:
#line 520 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    if (ServerInfo.ssl_certificate_file)
    {
      MyFree(ServerInfo.ssl_certificate_file);
      ServerInfo.ssl_certificate_file = NULL;
    }
        
    if ((ServerInfo.rsa_private_key == NULL) ||
        (!RSA_check_key(ServerInfo.rsa_private_key)) ||
        (RSA_size(ServerInfo.rsa_private_key) != 256))
    {
      yyerror("Ignoring config file entry ssl_certificate -- no rsa_private_key");
      break;
    }
    else
    {
      DupString(ServerInfo.ssl_certificate_file, yylval.string);
    }
  }
#endif
}
    break;

  case 66:
#line 546 "ircd_parser.y"
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

  case 67:
#line 560 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2)
  {
    MyFree(ServerInfo.sid);
    DupString(ServerInfo.sid, yylval.string);
  }
}
    break;

  case 68:
#line 570 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 69:
#line 579 "ircd_parser.y"
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

  case 70:
#line 593 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 71:
#line 602 "ircd_parser.y"
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
      ServerInfo.specific_ipv4_vhost = 1;

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

  case 72:
#line 632 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
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

  case 73:
#line 662 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (MAXCONN >= yyvsp[-1].number)
    {
      ServerInfo.max_clients = yyvsp[-1].number;
    }
    else
    {
      ilog(L_ERROR, "Setting serverinfo_max_clients to MAXCONN");
      ServerInfo.max_clients = MAXCONN;
    }
  }
}
    break;

  case 74:
#line 678 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
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
      dlink_node *ptr;

      ServerInfo.hub = 0;
      delete_capability("HUB");

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        if (MyConnect((struct Client *)ptr->data) &&
            IsCapable((struct Client *)ptr->data, CAP_LL))
        {
          sendto_gnotice_flags(UMODE_ALL, L_ALL, me.name, &me, NULL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               ((struct Client *)ptr->data)->name);
          add_capability("HUB", CAP_HUB, 1);
          ServerInfo.hub = 1;
          break;
        }
      }
    }
  }
}
    break;

  case 82:
#line 734 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 83:
#line 743 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 84:
#line 752 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 97:
#line 775 "ircd_parser.y"
    {
                        }
    break;

  case 98:
#line 779 "ircd_parser.y"
    {
                        }
    break;

  case 99:
#line 783 "ircd_parser.y"
    {
                        }
    break;

  case 100:
#line 787 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(fuserlog, yylval.string,
            sizeof(fuserlog));
}
    break;

  case 101:
#line 794 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ffailed_operlog, yylval.string,
            sizeof(ffailed_operlog));
}
    break;

  case 102:
#line 801 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(foperlog, yylval.string,
            sizeof(foperlog));
}
    break;

  case 103:
#line 808 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 104:
#line 812 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 105:
#line 816 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 106:
#line 820 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 107:
#line 824 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 108:
#line 828 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 109:
#line 832 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 110:
#line 838 "ircd_parser.y"
    {
  if (ypass == 2)
    use_logging = yylval.number;
}
    break;

  case 111:
#line 847 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 112:
#line 859 "ircd_parser.y"
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

  case 132:
#line 944 "ircd_parser.y"
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

  case 133:
#line 956 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->host, yylval.string);
      split_user_host(yy_aconf->host, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->host, yylval.string);
      split_user_host(yy_tmp->host, &yy_tmp->user, &yy_tmp->host);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 134:
#line 979 "ircd_parser.y"
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

  case 135:
#line 991 "ircd_parser.y"
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

  case 136:
#line 1002 "ircd_parser.y"
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

  case 137:
#line 1044 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 138:
#line 1053 "ircd_parser.y"
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

  case 139:
#line 1064 "ircd_parser.y"
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

  case 140:
#line 1075 "ircd_parser.y"
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

  case 141:
#line 1086 "ircd_parser.y"
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

  case 142:
#line 1097 "ircd_parser.y"
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

  case 143:
#line 1108 "ircd_parser.y"
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

  case 144:
#line 1119 "ircd_parser.y"
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

  case 145:
#line 1130 "ircd_parser.y"
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

  case 146:
#line 1141 "ircd_parser.y"
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

  case 147:
#line 1152 "ircd_parser.y"
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

  case 148:
#line 1166 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 149:
#line 1173 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    if ((yy_conf != NULL) && (yy_conf->name == NULL))
    {
      delete_conf_item(yy_conf);
      yy_conf = NULL;
      yy_class = NULL;
    }
  }
}
    break;

  case 162:
#line 1198 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf = find_exact_name_conf(CLASS_TYPE, yylval.string,
                                                  NULL, NULL);
    struct ClassItem *class = NULL;

    if (cconf != NULL)
    {
      if (cconf == yy_conf)
        cconf = NULL;
      else
        class = (struct ClassItem *) map_to_conf(cconf);
    }

    if (class != NULL && MaxTotal(class) >= 0)
    {
      yyerror("Multiple classes with the same name, using the first entry");
      MyFree(yy_conf->name);
      yy_conf->name = NULL;
    }
    else {
      if (class != NULL)
      {
        PingFreq(class) = PingFreq(yy_class);
        MaxPerIp(class) = MaxPerIp(yy_class);
        ConFreq(class) = ConFreq(yy_class);
        MaxTotal(class) = MaxTotal(yy_class);
        MaxGlobal(class) = MaxGlobal(yy_class);
        MaxLocal(class) = MaxLocal(yy_class);
        MaxIdent(class) = MaxIdent(yy_class);
        MaxSendq(class) = MaxSendq(yy_class);
        delete_conf_item(yy_conf);
        yy_conf = cconf;
        yy_class = class;
        /* allow changing case - replace old name */
      }

      MyFree(yy_conf->name);
      DupString(yy_conf->name, yylval.string);
    }
  }
}
    break;

  case 163:
#line 1243 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 164:
#line 1249 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = yyvsp[-1].number;
}
    break;

  case 165:
#line 1255 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = yyvsp[-1].number;
}
    break;

  case 166:
#line 1261 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = yyvsp[-1].number;
}
    break;

  case 167:
#line 1267 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = yyvsp[-1].number;
}
    break;

  case 168:
#line 1273 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = yyvsp[-1].number;
}
    break;

  case 169:
#line 1279 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = yyvsp[-1].number;
}
    break;

  case 170:
#line 1285 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = yyvsp[-1].number;
}
    break;

  case 171:
#line 1294 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_address = NULL;
}
    break;

  case 172:
#line 1298 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 183:
#line 1315 "ircd_parser.y"
    {
  if (ypass == 2)
  add_listener(yyvsp[0].number, listener_address, 0);
}
    break;

  case 184:
#line 1319 "ircd_parser.y"
    {
    if (ypass == 2)
    {
        int i;
        for (i = yyvsp[-2].number; i <= yyvsp[0].number; i++)
	{
            add_listener(i, listener_address, 0);
	}
    }
}
    break;

  case 188:
#line 1335 "ircd_parser.y"
    {
    if (ypass == 2)
        add_listener(yyvsp[0].number, listener_address, 1);
}
    break;

  case 189:
#line 1339 "ircd_parser.y"
    {
    if (ypass == 2)
    {
        int i;
        
        for (i = yyvsp[-2].number; i <= yyvsp[0].number; i++)
        {
            add_listener(i, listener_address, 1);
        }
    }
}
    break;

  case 190:
#line 1352 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 191:
#line 1361 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 192:
#line 1373 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 193:
#line 1385 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);
    add_conf_by_address(CONF_CLIENT, yy_aconf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

      yy_tmp = ptr->data;

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);

      if (yy_aconf->passwd != NULL)
	DupString(new_aconf->passwd, yy_aconf->passwd);

      yy_aconf->flags = yy_aconf->flags;
      yy_aconf->port  = yy_aconf->port;

      if (yy_tmp->user != NULL)
      {
	DupString(new_aconf->user, yy_tmp->user);
        collapse(new_aconf->user);
      }
      else
        DupString(new_aconf->user, "*");

      if (yy_tmp->host != NULL)
      {
	DupString(new_aconf->host, yy_tmp->host);
        collapse(new_aconf->host);
      }
      else
	DupString(new_aconf->host, "*");

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

  case 212:
#line 1455 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      if (yylval.string != NULL)
      {
	DupString(yy_aconf->host, yylval.string);
	split_user_host(yy_aconf->host, &yy_aconf->user, &yy_aconf->host);
      }
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
      if (yylval.string != NULL)
      {
	DupString(yy_tmp->host, yylval.string);
	split_user_host(yy_tmp->host, &yy_tmp->user, &yy_tmp->host);
      }
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 213:
#line 1484 "ircd_parser.y"
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

  case 214:
#line 1498 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 215:
#line 1510 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 216:
#line 1528 "ircd_parser.y"
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

  case 217:
#line 1539 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_RESTRICTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_RESTRICTED;
  }
}
    break;

  case 218:
#line 1550 "ircd_parser.y"
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

  case 219:
#line 1561 "ircd_parser.y"
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

  case 220:
#line 1572 "ircd_parser.y"
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

  case 221:
#line 1583 "ircd_parser.y"
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

  case 222:
#line 1594 "ircd_parser.y"
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

  case 223:
#line 1605 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 224:
#line 1615 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = yyvsp[-1].number;
  }
}
    break;

  case 225:
#line 1624 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 226:
#line 1633 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 227:
#line 1647 "ircd_parser.y"
    {
  if (ypass == 2)
    resv_reason = NULL;
}
    break;

  case 228:
#line 1651 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 235:
#line 1663 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 236:
#line 1672 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (IsChannelName(yylval.string))
    {
      char def_reason[] = "No reason specified";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
}
    break;

  case 237:
#line 1687 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (clean_resv_nick(yylval.string))
    {
      char def_reason[] = "No reason specified";

      create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }

  /* otherwise its erroneous, but ignore it for now */
}
    break;

  case 238:
#line 1705 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 239:
#line 1713 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 246:
#line 1724 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 247:
#line 1733 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    DupString(yy_match_item->user, yylval.string);
    split_user_host(yy_match_item->user, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 248:
#line 1742 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 252:
#line 1749 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 253:
#line 1753 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 254:
#line 1757 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 255:
#line 1761 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 256:
#line 1765 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 257:
#line 1769 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 258:
#line 1773 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 259:
#line 1782 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_match_item = (struct MatchItem *)map_to_conf(yy_conf);
    yy_match_item->action = CLUSTER_ALL;
  }
}
    break;

  case 260:
#line 1790 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 266:
#line 1801 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 267:
#line 1807 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 271:
#line 1814 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_KLINE;
}
    break;

  case 272:
#line 1818 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_UNKLINE;
}
    break;

  case 273:
#line 1822 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_XLINE;
}
    break;

  case 274:
#line 1826 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_UNXLINE;
}
    break;

  case 275:
#line 1830 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_RESV;
}
    break;

  case 276:
#line 1834 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_UNRESV;
}
    break;

  case 277:
#line 1838 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= CLUSTER_LOCOPS;
}
    break;

  case 278:
#line 1842 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = CLUSTER_ALL;
}
    break;

  case 279:
#line 1851 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 280:
#line 1866 "ircd_parser.y"
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

  case 301:
#line 1996 "ircd_parser.y"
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

  case 302:
#line 2008 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 303:
#line 2017 "ircd_parser.y"
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

  case 304:
#line 2035 "ircd_parser.y"
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

  case 305:
#line 2053 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = yyvsp[-1].number;
}
    break;

  case 306:
#line 2059 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 307:
#line 2063 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 308:
#line 2071 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 309:
#line 2080 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_LAZY_LINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_LAZY_LINK;
  }
}
    break;

  case 310:
#line 2091 "ircd_parser.y"
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

  case 311:
#line 2102 "ircd_parser.y"
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

  case 312:
#line 2143 "ircd_parser.y"
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

  case 313:
#line 2154 "ircd_parser.y"
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

  case 314:
#line 2169 "ircd_parser.y"
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

  case 315:
#line 2180 "ircd_parser.y"
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

  case 316:
#line 2193 "ircd_parser.y"
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

  case 317:
#line 2206 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 318:
#line 2215 "ircd_parser.y"
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

  case 319:
#line 2250 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(KLINE_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 320:
#line 2257 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->user && yy_aconf->reason && yy_aconf->host)
    {
      if (yy_aconf->host != NULL)
        add_conf_by_address(CONF_KILL, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 326:
#line 2276 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    DupString(yy_aconf->host, yylval.string);
    split_user_host(yy_aconf->host, &yy_aconf->user, &yy_aconf->host);
  }
}
    break;

  case 327:
#line 2285 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 328:
#line 2297 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "NO REASON");
  }
}
    break;

  case 329:
#line 2306 "ircd_parser.y"
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

  case 335:
#line 2322 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 336:
#line 2331 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 337:
#line 2343 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    DupString(yy_aconf->passwd, "*");
  }
}
    break;

  case 338:
#line 2351 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 343:
#line 2367 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 344:
#line 2379 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(XLINE_TYPE);
    yy_match_item = (struct MatchItem *)map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_match_item->reason,"Something about your name");
  }
}
    break;

  case 345:
#line 2388 "ircd_parser.y"
    {
  /* XXX */
}
    break;

  case 352:
#line 2396 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    DupString(yy_conf->name, yylval.string);
    collapse(yy_conf->name);
  }
}
    break;

  case 353:
#line 2405 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_match_item->reason);
    DupString(yy_match_item->reason, yylval.string);
  }
}
    break;

  case 354:
#line 2414 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 355:
#line 2418 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 1;
}
    break;

  case 356:
#line 2422 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 2;
}
    break;

  case 412:
#line 2465 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 413:
#line 2471 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 414:
#line 2477 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 415:
#line 2483 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 416:
#line 2489 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 417:
#line 2495 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.max_nick_time = yyvsp[-1].number; 
}
    break;

  case 418:
#line 2501 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.max_nick_changes = yyvsp[-1].number;
}
    break;

  case 419:
#line 2507 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.max_accept = yyvsp[-1].number;
}
    break;

  case 420:
#line 2513 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.anti_spam_exit_message_time = yyvsp[-1].number;
}
    break;

  case 421:
#line 2519 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_warn_delta = yyvsp[-1].number;
}
    break;

  case 422:
#line 2525 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = yyvsp[-1].number;
}
    break;

  case 423:
#line 2531 "ircd_parser.y"
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

  case 424:
#line 2542 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 425:
#line 2548 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.kline_with_connection_closed = yylval.number;
}
    break;

  case 426:
#line 2554 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 427:
#line 2560 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 428:
#line 2566 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 429:
#line 2572 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 430:
#line 2576 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 431:
#line 2582 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 432:
#line 2586 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 433:
#line 2592 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.pace_wait = yyvsp[-1].number;
}
    break;

  case 434:
#line 2598 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.caller_id_wait = yyvsp[-1].number;
}
    break;

  case 435:
#line 2604 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.pace_wait_simple = yyvsp[-1].number;
}
    break;

  case 436:
#line 2610 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 437:
#line 2616 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 438:
#line 2622 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 439:
#line 2628 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 440:
#line 2634 "ircd_parser.y"
    {
#if 0
  if (ypass == 2)
    strncpy(iAuth.hostname, yylval.string, HOSTLEN)[HOSTLEN] = 0;
#endif
}
    break;

  case 441:
#line 2642 "ircd_parser.y"
    {
#if 0
  if (ypass == 2)
    iAuth.port = yyvsp[-1].number;
#endif
}
    break;

  case 442:
#line 2650 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 443:
#line 2656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 444:
#line 2667 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = yyvsp[-1].number;
}
    break;

  case 445:
#line 2673 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.idletime = yyvsp[-1].number;
}
    break;

  case 446:
#line 2679 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.dots_in_ident = yyvsp[-1].number;
}
    break;

  case 447:
#line 2685 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.maximum_links = yyvsp[-1].number;
}
    break;

  case 448:
#line 2691 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.max_targets = yyvsp[-1].number;
}
    break;

  case 449:
#line 2697 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 450:
#line 2706 "ircd_parser.y"
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

  case 451:
#line 2738 "ircd_parser.y"
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

  case 452:
#line 2756 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 453:
#line 2762 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 454:
#line 2771 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 455:
#line 2777 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 456:
#line 2782 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 457:
#line 2788 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 461:
#line 2795 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 462:
#line 2799 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 463:
#line 2803 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 464:
#line 2807 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 465:
#line 2811 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 466:
#line 2815 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 467:
#line 2819 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 468:
#line 2823 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 469:
#line 2827 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 470:
#line 2831 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 471:
#line 2835 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 472:
#line 2839 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 473:
#line 2843 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_SERV;
}
    break;

  case 474:
#line 2847 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 475:
#line 2851 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 476:
#line 2855 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 477:
#line 2859 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 478:
#line 2865 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 482:
#line 2872 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 483:
#line 2876 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 484:
#line 2880 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 485:
#line 2884 "ircd_parser.y"
    { 
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 486:
#line 2888 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 487:
#line 2892 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 488:
#line 2896 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 489:
#line 2900 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 490:
#line 2904 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 491:
#line 2908 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 492:
#line 2912 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 493:
#line 2916 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 494:
#line 2920 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_SERV;
}
    break;

  case 495:
#line 2924 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 496:
#line 2928 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 497:
#line 2932 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 498:
#line 2936 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 499:
#line 2940 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.oper_only_umodes |= UMODE_GOD;
}
    break;

  case 500:
#line 2946 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.crypt_oper_password = yylval.number;
}
    break;

  case 501:
#line 2952 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.min_nonwildcard = yyvsp[-1].number;
}
    break;

  case 502:
#line 2958 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.min_nonwildcard_simple = yyvsp[-1].number;
}
    break;

  case 503:
#line 2964 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.default_floodcount = yyvsp[-1].number;
}
    break;

  case 504:
#line 2970 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.client_flood = yyvsp[-1].number;
}
    break;

  case 505:
#line 2976 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 523:
#line 3004 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 524:
#line 3010 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.use_except = yylval.number;
}
    break;

  case 525:
#line 3016 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.use_invex = yylval.number;
}
    break;

  case 526:
#line 3022 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.use_knock = yylval.number;
}
    break;

  case 527:
#line 3028 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.knock_delay = yyvsp[-1].number;
}
    break;

  case 528:
#line 3034 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.knock_delay_channel = yyvsp[-1].number;
}
    break;

  case 529:
#line 3040 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.max_chans_per_user = yyvsp[-1].number;
}
    break;

  case 530:
#line 3046 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 531:
#line 3052 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.max_bans = yyvsp[-1].number;
}
    break;

  case 532:
#line 3058 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.default_split_user_count = yyvsp[-1].number;
}
    break;

  case 533:
#line 3064 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.default_split_server_count = yyvsp[-1].number;
}
    break;

  case 534:
#line 3070 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 535:
#line 3076 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 546:
#line 3096 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 547:
#line 3102 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 548:
#line 3108 "ircd_parser.y"
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

  case 549:
#line 3122 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 550:
#line 3128 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 551:
#line 3134 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


    }

/* Line 1010 of yacc.c.  */
#line 5924 "y.tab.c"

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
      /* If just tried and failed to reuse lookahead token after an
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
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
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



