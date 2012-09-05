/* A Bison parser, made by GNU Bison 2.6.2.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2049 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 2049 of yacc.c  */
#line 535 "conf_parser.h"
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
