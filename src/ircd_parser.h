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
     CIPHER_PREFERENCE = 279,
     CLASS = 280,
     COMPRESSED = 281,
     COMPRESSION_LEVEL = 282,
     CONNECT = 283,
     CONNECTFREQ = 284,
     CRYPTLINK = 285,
     DEFAULT_CIPHER_PREFERENCE = 286,
     DEFAULT_FLOODCOUNT = 287,
     DEFAULT_SPLIT_SERVER_COUNT = 288,
     DEFAULT_SPLIT_USER_COUNT = 289,
     DENY = 290,
     DESCRIPTION = 291,
     DIE = 292,
     DISABLE_AUTH = 293,
     DISABLE_FAKE_CHANNELS = 294,
     DISABLE_HIDDEN = 295,
     DISABLE_LOCAL_CHANNELS = 296,
     DISABLE_REMOTE_COMMANDS = 297,
     DOTS_IN_IDENT = 298,
     DURATION = 299,
     EGDPOOL_PATH = 300,
     EMAIL = 301,
     ENABLE = 302,
     ENCRYPTED = 303,
     EXCEED_LIMIT = 304,
     EXEMPT = 305,
     FAILED_OPER_NOTICE = 306,
     IRCD_FLAGS = 307,
     FLATTEN_LINKS = 308,
     GECOS = 309,
     GENERAL = 310,
     GLINE = 311,
     GLINES = 312,
     GLINE_EXEMPT = 313,
     GLINE_TIME = 314,
     GLINE_MIN_CIDR = 315,
     GLINE_MIN_CIDR6 = 316,
     GLOBAL_KILL = 317,
     IRCD_AUTH = 318,
     NEED_IDENT = 319,
     HAVENT_READ_CONF = 320,
     HIDDEN = 321,
     HIDDEN_ADMIN = 322,
     HIDDEN_NAME = 323,
     HIDDEN_OPER = 324,
     HIDE_SERVER_IPS = 325,
     HIDE_SERVERS = 326,
     HIDE_SPOOF_IPS = 327,
     HOST = 328,
     HUB = 329,
     HUB_MASK = 330,
     IGNORE_BOGUS_TS = 331,
     INVISIBLE_ON_CONNECT = 332,
     IP = 333,
     KILL = 334,
     KILL_CHASE_TIME_LIMIT = 335,
     KLINE = 336,
     KLINE_EXEMPT = 337,
     KLINE_REASON = 338,
     KLINE_WITH_REASON = 339,
     KNOCK_DELAY = 340,
     KNOCK_DELAY_CHANNEL = 341,
     LEAF_MASK = 342,
     LINKS_DELAY = 343,
     LISTEN = 344,
     T_LOG = 345,
     MAX_ACCEPT = 346,
     MAX_BANS = 347,
     MAX_CHANS_PER_USER = 348,
     MAX_GLOBAL = 349,
     MAX_IDENT = 350,
     MAX_LOCAL = 351,
     MAX_NICK_CHANGES = 352,
     MAX_NICK_TIME = 353,
     MAX_NUMBER = 354,
     MAX_TARGETS = 355,
     MAX_WATCH = 356,
     MESSAGE_LOCALE = 357,
     MIN_NONWILDCARD = 358,
     MIN_NONWILDCARD_SIMPLE = 359,
     MODULE = 360,
     MODULES = 361,
     NAME = 362,
     NEED_PASSWORD = 363,
     NETWORK_DESC = 364,
     NETWORK_NAME = 365,
     NICK = 366,
     NICK_CHANGES = 367,
     NO_CREATE_ON_SPLIT = 368,
     NO_JOIN_ON_SPLIT = 369,
     NO_OPER_FLOOD = 370,
     NO_TILDE = 371,
     NUMBER = 372,
     NUMBER_PER_IDENT = 373,
     NUMBER_PER_CIDR = 374,
     NUMBER_PER_IP = 375,
     NUMBER_PER_IP_GLOBAL = 376,
     OPERATOR = 377,
     OPERS_BYPASS_CALLERID = 378,
     OPER_ONLY_UMODES = 379,
     OPER_PASS_RESV = 380,
     OPER_SPY_T = 381,
     OPER_UMODES = 382,
     JOIN_FLOOD_COUNT = 383,
     JOIN_FLOOD_TIME = 384,
     PACE_WAIT = 385,
     PACE_WAIT_SIMPLE = 386,
     PASSWORD = 387,
     PATH = 388,
     PING_COOKIE = 389,
     PING_TIME = 390,
     PING_WARNING = 391,
     PORT = 392,
     QSTRING = 393,
     QUIET_ON_BAN = 394,
     REASON = 395,
     REDIRPORT = 396,
     REDIRSERV = 397,
     REGEX_T = 398,
     REHASH = 399,
     TREJECT_HOLD_TIME = 400,
     REMOTE = 401,
     REMOTEBAN = 402,
     RESTRICT_CHANNELS = 403,
     RESTRICTED = 404,
     RSA_PRIVATE_KEY_FILE = 405,
     RSA_PUBLIC_KEY_FILE = 406,
     SSL_CERTIFICATE_FILE = 407,
     T_SSL_CONNECTION_METHOD = 408,
     T_SSLV3 = 409,
     T_TLSV1 = 410,
     RESV = 411,
     RESV_EXEMPT = 412,
     SECONDS = 413,
     MINUTES = 414,
     HOURS = 415,
     DAYS = 416,
     WEEKS = 417,
     SENDQ = 418,
     SEND_PASSWORD = 419,
     SERVERHIDE = 420,
     SERVERINFO = 421,
     SERVLINK_PATH = 422,
     IRCD_SID = 423,
     TKLINE_EXPIRE_NOTICES = 424,
     T_SHARED = 425,
     T_CLUSTER = 426,
     TYPE = 427,
     SHORT_MOTD = 428,
     SILENT = 429,
     SPOOF = 430,
     SPOOF_NOTICE = 431,
     STATS_E_DISABLED = 432,
     STATS_I_OPER_ONLY = 433,
     STATS_K_OPER_ONLY = 434,
     STATS_O_OPER_ONLY = 435,
     STATS_P_OPER_ONLY = 436,
     TBOOL = 437,
     TMASKED = 438,
     T_REJECT = 439,
     TS_MAX_DELTA = 440,
     TS_WARN_DELTA = 441,
     TWODOTS = 442,
     T_ALL = 443,
     T_BOTS = 444,
     T_SOFTCALLERID = 445,
     T_CALLERID = 446,
     T_CCONN = 447,
     T_CCONN_FULL = 448,
     T_CLIENT_FLOOD = 449,
     T_DEAF = 450,
     T_DEBUG = 451,
     T_DLINE = 452,
     T_DRONE = 453,
     T_EXTERNAL = 454,
     T_FULL = 455,
     T_INVISIBLE = 456,
     T_IPV4 = 457,
     T_IPV6 = 458,
     T_LOCOPS = 459,
     T_MAX_CLIENTS = 460,
     T_NCHANGE = 461,
     T_OPERWALL = 462,
     T_REJ = 463,
     T_SERVER = 464,
     T_SERVNOTICE = 465,
     T_SKILL = 466,
     T_SPY = 467,
     T_SSL = 468,
     T_UMODES = 469,
     T_UNAUTH = 470,
     T_UNLIMITED = 471,
     T_UNRESV = 472,
     T_UNXLINE = 473,
     T_GLOBOPS = 474,
     T_WALLOP = 475,
     T_RESTART = 476,
     T_SERVICE = 477,
     T_SERVICES_NAME = 478,
     T_TIMESTAMP = 479,
     THROTTLE_TIME = 480,
     TOPICBURST = 481,
     TRUE_NO_OPER_FLOOD = 482,
     TKLINE = 483,
     TXLINE = 484,
     TRESV = 485,
     UNKLINE = 486,
     USER = 487,
     USE_EGD = 488,
     USE_EXCEPT = 489,
     USE_INVEX = 490,
     USE_KNOCK = 491,
     USE_LOGGING = 492,
     USE_WHOIS_ACTUALLY = 493,
     VHOST = 494,
     VHOST6 = 495,
     XLINE = 496,
     WARN = 497,
     WARN_NO_NLINE = 498,
     T_SIZE = 499,
     T_FILE = 500
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
#define CIPHER_PREFERENCE 279
#define CLASS 280
#define COMPRESSED 281
#define COMPRESSION_LEVEL 282
#define CONNECT 283
#define CONNECTFREQ 284
#define CRYPTLINK 285
#define DEFAULT_CIPHER_PREFERENCE 286
#define DEFAULT_FLOODCOUNT 287
#define DEFAULT_SPLIT_SERVER_COUNT 288
#define DEFAULT_SPLIT_USER_COUNT 289
#define DENY 290
#define DESCRIPTION 291
#define DIE 292
#define DISABLE_AUTH 293
#define DISABLE_FAKE_CHANNELS 294
#define DISABLE_HIDDEN 295
#define DISABLE_LOCAL_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DOTS_IN_IDENT 298
#define DURATION 299
#define EGDPOOL_PATH 300
#define EMAIL 301
#define ENABLE 302
#define ENCRYPTED 303
#define EXCEED_LIMIT 304
#define EXEMPT 305
#define FAILED_OPER_NOTICE 306
#define IRCD_FLAGS 307
#define FLATTEN_LINKS 308
#define GECOS 309
#define GENERAL 310
#define GLINE 311
#define GLINES 312
#define GLINE_EXEMPT 313
#define GLINE_TIME 314
#define GLINE_MIN_CIDR 315
#define GLINE_MIN_CIDR6 316
#define GLOBAL_KILL 317
#define IRCD_AUTH 318
#define NEED_IDENT 319
#define HAVENT_READ_CONF 320
#define HIDDEN 321
#define HIDDEN_ADMIN 322
#define HIDDEN_NAME 323
#define HIDDEN_OPER 324
#define HIDE_SERVER_IPS 325
#define HIDE_SERVERS 326
#define HIDE_SPOOF_IPS 327
#define HOST 328
#define HUB 329
#define HUB_MASK 330
#define IGNORE_BOGUS_TS 331
#define INVISIBLE_ON_CONNECT 332
#define IP 333
#define KILL 334
#define KILL_CHASE_TIME_LIMIT 335
#define KLINE 336
#define KLINE_EXEMPT 337
#define KLINE_REASON 338
#define KLINE_WITH_REASON 339
#define KNOCK_DELAY 340
#define KNOCK_DELAY_CHANNEL 341
#define LEAF_MASK 342
#define LINKS_DELAY 343
#define LISTEN 344
#define T_LOG 345
#define MAX_ACCEPT 346
#define MAX_BANS 347
#define MAX_CHANS_PER_USER 348
#define MAX_GLOBAL 349
#define MAX_IDENT 350
#define MAX_LOCAL 351
#define MAX_NICK_CHANGES 352
#define MAX_NICK_TIME 353
#define MAX_NUMBER 354
#define MAX_TARGETS 355
#define MAX_WATCH 356
#define MESSAGE_LOCALE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULES 361
#define NAME 362
#define NEED_PASSWORD 363
#define NETWORK_DESC 364
#define NETWORK_NAME 365
#define NICK 366
#define NICK_CHANGES 367
#define NO_CREATE_ON_SPLIT 368
#define NO_JOIN_ON_SPLIT 369
#define NO_OPER_FLOOD 370
#define NO_TILDE 371
#define NUMBER 372
#define NUMBER_PER_IDENT 373
#define NUMBER_PER_CIDR 374
#define NUMBER_PER_IP 375
#define NUMBER_PER_IP_GLOBAL 376
#define OPERATOR 377
#define OPERS_BYPASS_CALLERID 378
#define OPER_ONLY_UMODES 379
#define OPER_PASS_RESV 380
#define OPER_SPY_T 381
#define OPER_UMODES 382
#define JOIN_FLOOD_COUNT 383
#define JOIN_FLOOD_TIME 384
#define PACE_WAIT 385
#define PACE_WAIT_SIMPLE 386
#define PASSWORD 387
#define PATH 388
#define PING_COOKIE 389
#define PING_TIME 390
#define PING_WARNING 391
#define PORT 392
#define QSTRING 393
#define QUIET_ON_BAN 394
#define REASON 395
#define REDIRPORT 396
#define REDIRSERV 397
#define REGEX_T 398
#define REHASH 399
#define TREJECT_HOLD_TIME 400
#define REMOTE 401
#define REMOTEBAN 402
#define RESTRICT_CHANNELS 403
#define RESTRICTED 404
#define RSA_PRIVATE_KEY_FILE 405
#define RSA_PUBLIC_KEY_FILE 406
#define SSL_CERTIFICATE_FILE 407
#define T_SSL_CONNECTION_METHOD 408
#define T_SSLV3 409
#define T_TLSV1 410
#define RESV 411
#define RESV_EXEMPT 412
#define SECONDS 413
#define MINUTES 414
#define HOURS 415
#define DAYS 416
#define WEEKS 417
#define SENDQ 418
#define SEND_PASSWORD 419
#define SERVERHIDE 420
#define SERVERINFO 421
#define SERVLINK_PATH 422
#define IRCD_SID 423
#define TKLINE_EXPIRE_NOTICES 424
#define T_SHARED 425
#define T_CLUSTER 426
#define TYPE 427
#define SHORT_MOTD 428
#define SILENT 429
#define SPOOF 430
#define SPOOF_NOTICE 431
#define STATS_E_DISABLED 432
#define STATS_I_OPER_ONLY 433
#define STATS_K_OPER_ONLY 434
#define STATS_O_OPER_ONLY 435
#define STATS_P_OPER_ONLY 436
#define TBOOL 437
#define TMASKED 438
#define T_REJECT 439
#define TS_MAX_DELTA 440
#define TS_WARN_DELTA 441
#define TWODOTS 442
#define T_ALL 443
#define T_BOTS 444
#define T_SOFTCALLERID 445
#define T_CALLERID 446
#define T_CCONN 447
#define T_CCONN_FULL 448
#define T_CLIENT_FLOOD 449
#define T_DEAF 450
#define T_DEBUG 451
#define T_DLINE 452
#define T_DRONE 453
#define T_EXTERNAL 454
#define T_FULL 455
#define T_INVISIBLE 456
#define T_IPV4 457
#define T_IPV6 458
#define T_LOCOPS 459
#define T_MAX_CLIENTS 460
#define T_NCHANGE 461
#define T_OPERWALL 462
#define T_REJ 463
#define T_SERVER 464
#define T_SERVNOTICE 465
#define T_SKILL 466
#define T_SPY 467
#define T_SSL 468
#define T_UMODES 469
#define T_UNAUTH 470
#define T_UNLIMITED 471
#define T_UNRESV 472
#define T_UNXLINE 473
#define T_GLOBOPS 474
#define T_WALLOP 475
#define T_RESTART 476
#define T_SERVICE 477
#define T_SERVICES_NAME 478
#define T_TIMESTAMP 479
#define THROTTLE_TIME 480
#define TOPICBURST 481
#define TRUE_NO_OPER_FLOOD 482
#define TKLINE 483
#define TXLINE 484
#define TRESV 485
#define UNKLINE 486
#define USER 487
#define USE_EGD 488
#define USE_EXCEPT 489
#define USE_INVEX 490
#define USE_KNOCK 491
#define USE_LOGGING 492
#define USE_WHOIS_ACTUALLY 493
#define VHOST 494
#define VHOST6 495
#define XLINE 496
#define WARN 497
#define WARN_NO_NLINE 498
#define T_SIZE 499
#define T_FILE 500




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 547 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


