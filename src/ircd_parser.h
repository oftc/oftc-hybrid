/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
     CHANNEL = 276,
     CIDR_BITLEN_IPV4 = 277,
     CIDR_BITLEN_IPV6 = 278,
     CLASS = 279,
     CONNECT = 280,
     CONNECTFREQ = 281,
     DEFAULT_FLOODCOUNT = 282,
     DEFAULT_SPLIT_SERVER_COUNT = 283,
     DEFAULT_SPLIT_USER_COUNT = 284,
     DENY = 285,
     DESCRIPTION = 286,
     DIE = 287,
     DISABLE_AUTH = 288,
     DISABLE_FAKE_CHANNELS = 289,
     DISABLE_HIDDEN = 290,
     DISABLE_LOCAL_CHANNELS = 291,
     DISABLE_REMOTE_COMMANDS = 292,
     DOTS_IN_IDENT = 293,
     DURATION = 294,
     EGDPOOL_PATH = 295,
     EMAIL = 296,
     ENABLE = 297,
     ENCRYPTED = 298,
     EXCEED_LIMIT = 299,
     EXEMPT = 300,
     FAILED_OPER_NOTICE = 301,
     IRCD_FLAGS = 302,
     FLATTEN_LINKS = 303,
     GECOS = 304,
     GENERAL = 305,
     GLINE = 306,
     GLINES = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
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
     T_SSL_CONNECTION_METHOD = 401,
     T_SSLV3 = 402,
     T_TLSV1 = 403,
     RESV = 404,
     RESV_EXEMPT = 405,
     SECONDS = 406,
     MINUTES = 407,
     HOURS = 408,
     DAYS = 409,
     WEEKS = 410,
     SENDQ = 411,
     SEND_PASSWORD = 412,
     SERVERHIDE = 413,
     SERVERINFO = 414,
     IRCD_SID = 415,
     TKLINE_EXPIRE_NOTICES = 416,
     T_SHARED = 417,
     T_CLUSTER = 418,
     TYPE = 419,
     SHORT_MOTD = 420,
     SILENT = 421,
     SPOOF = 422,
     SPOOF_NOTICE = 423,
     STATS_E_DISABLED = 424,
     STATS_I_OPER_ONLY = 425,
     STATS_K_OPER_ONLY = 426,
     STATS_O_OPER_ONLY = 427,
     STATS_P_OPER_ONLY = 428,
     TBOOL = 429,
     TMASKED = 430,
     T_REJECT = 431,
     TS_MAX_DELTA = 432,
     TS_WARN_DELTA = 433,
     TWODOTS = 434,
     T_ALL = 435,
     T_BOTS = 436,
     T_SOFTCALLERID = 437,
     T_CALLERID = 438,
     T_CCONN = 439,
     T_CCONN_FULL = 440,
     T_CLIENT_FLOOD = 441,
     T_DEAF = 442,
     T_DEBUG = 443,
     T_DLINE = 444,
     T_DRONE = 445,
     T_EXTERNAL = 446,
     T_FULL = 447,
     T_INVISIBLE = 448,
     T_IPV4 = 449,
     T_IPV6 = 450,
     T_LOCOPS = 451,
     T_MAX_CLIENTS = 452,
     T_NCHANGE = 453,
     T_OPERWALL = 454,
     T_REJ = 455,
     T_SERVER = 456,
     T_SERVNOTICE = 457,
     T_SKILL = 458,
     T_SPY = 459,
     T_SSL = 460,
     T_UMODES = 461,
     T_UNAUTH = 462,
     T_UNDLINE = 463,
     T_UNLIMITED = 464,
     T_UNRESV = 465,
     T_UNXLINE = 466,
     T_GLOBOPS = 467,
     T_WALLOP = 468,
     T_RESTART = 469,
     T_SERVICE = 470,
     T_SERVICES_NAME = 471,
     T_TIMESTAMP = 472,
     THROTTLE_TIME = 473,
     TOPICBURST = 474,
     TRUE_NO_OPER_FLOOD = 475,
     TKLINE = 476,
     TXLINE = 477,
     TRESV = 478,
     UNKLINE = 479,
     USER = 480,
     USE_EGD = 481,
     USE_EXCEPT = 482,
     USE_INVEX = 483,
     USE_KNOCK = 484,
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
#define BURST_TOPICWHO 268
#define BYTES 269
#define KBYTES 270
#define MBYTES 271
#define GBYTES 272
#define TBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CHANNEL 276
#define CIDR_BITLEN_IPV4 277
#define CIDR_BITLEN_IPV6 278
#define CLASS 279
#define CONNECT 280
#define CONNECTFREQ 281
#define DEFAULT_FLOODCOUNT 282
#define DEFAULT_SPLIT_SERVER_COUNT 283
#define DEFAULT_SPLIT_USER_COUNT 284
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_HIDDEN 290
#define DISABLE_LOCAL_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DOTS_IN_IDENT 293
#define DURATION 294
#define EGDPOOL_PATH 295
#define EMAIL 296
#define ENABLE 297
#define ENCRYPTED 298
#define EXCEED_LIMIT 299
#define EXEMPT 300
#define FAILED_OPER_NOTICE 301
#define IRCD_FLAGS 302
#define FLATTEN_LINKS 303
#define GECOS 304
#define GENERAL 305
#define GLINE 306
#define GLINES 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
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
#define T_SSL_CONNECTION_METHOD 401
#define T_SSLV3 402
#define T_TLSV1 403
#define RESV 404
#define RESV_EXEMPT 405
#define SECONDS 406
#define MINUTES 407
#define HOURS 408
#define DAYS 409
#define WEEKS 410
#define SENDQ 411
#define SEND_PASSWORD 412
#define SERVERHIDE 413
#define SERVERINFO 414
#define IRCD_SID 415
#define TKLINE_EXPIRE_NOTICES 416
#define T_SHARED 417
#define T_CLUSTER 418
#define TYPE 419
#define SHORT_MOTD 420
#define SILENT 421
#define SPOOF 422
#define SPOOF_NOTICE 423
#define STATS_E_DISABLED 424
#define STATS_I_OPER_ONLY 425
#define STATS_K_OPER_ONLY 426
#define STATS_O_OPER_ONLY 427
#define STATS_P_OPER_ONLY 428
#define TBOOL 429
#define TMASKED 430
#define T_REJECT 431
#define TS_MAX_DELTA 432
#define TS_WARN_DELTA 433
#define TWODOTS 434
#define T_ALL 435
#define T_BOTS 436
#define T_SOFTCALLERID 437
#define T_CALLERID 438
#define T_CCONN 439
#define T_CCONN_FULL 440
#define T_CLIENT_FLOOD 441
#define T_DEAF 442
#define T_DEBUG 443
#define T_DLINE 444
#define T_DRONE 445
#define T_EXTERNAL 446
#define T_FULL 447
#define T_INVISIBLE 448
#define T_IPV4 449
#define T_IPV6 450
#define T_LOCOPS 451
#define T_MAX_CLIENTS 452
#define T_NCHANGE 453
#define T_OPERWALL 454
#define T_REJ 455
#define T_SERVER 456
#define T_SERVNOTICE 457
#define T_SKILL 458
#define T_SPY 459
#define T_SSL 460
#define T_UMODES 461
#define T_UNAUTH 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_GLOBOPS 467
#define T_WALLOP 468
#define T_RESTART 469
#define T_SERVICE 470
#define T_SERVICES_NAME 471
#define T_TIMESTAMP 472
#define THROTTLE_TIME 473
#define TOPICBURST 474
#define TRUE_NO_OPER_FLOOD 475
#define TKLINE 476
#define TXLINE 477
#define TRESV 478
#define UNKLINE 479
#define USER 480
#define USE_EGD 481
#define USE_EXCEPT 482
#define USE_INVEX 483
#define USE_KNOCK 484
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

/* Line 2068 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 533 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


