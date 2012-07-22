/* A Bison parser, made by GNU Bison 2.6.  */

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

#ifndef YY_CONF_PARSER_H
# define YY_CONF_PARSER_H
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

/* Line 2050 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 2050 of yacc.c  */
#line 549 "conf_parser.h"
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

#endif /* !YY_CONF_PARSER_H  */
