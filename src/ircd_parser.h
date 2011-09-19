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
     FFAILED_OPERLOG = 309,
     FKILLLOG = 310,
     FKLINELOG = 311,
     FGLINELOG = 312,
     FIOERRLOG = 313,
     FOPERLOG = 314,
     FOPERSPYLOG = 315,
     FUSERLOG = 316,
     GECOS = 317,
     GENERAL = 318,
     GLINE = 319,
     GLINES = 320,
     GLINE_EXEMPT = 321,
     GLINE_LOG = 322,
     GLINE_TIME = 323,
     GLINE_MIN_CIDR = 324,
     GLINE_MIN_CIDR6 = 325,
     GLOBAL_KILL = 326,
     IRCD_AUTH = 327,
     NEED_IDENT = 328,
     HAVENT_READ_CONF = 329,
     HIDDEN = 330,
     HIDDEN_ADMIN = 331,
     HIDDEN_NAME = 332,
     HIDDEN_OPER = 333,
     HIDE_SERVER_IPS = 334,
     HIDE_SERVERS = 335,
     HIDE_SPOOF_IPS = 336,
     HOST = 337,
     HUB = 338,
     HUB_MASK = 339,
     IGNORE_BOGUS_TS = 340,
     INVISIBLE_ON_CONNECT = 341,
     IP = 342,
     KILL = 343,
     KILL_CHASE_TIME_LIMIT = 344,
     KLINE = 345,
     KLINE_EXEMPT = 346,
     KLINE_REASON = 347,
     KLINE_WITH_REASON = 348,
     KNOCK_DELAY = 349,
     KNOCK_DELAY_CHANNEL = 350,
     LEAF_MASK = 351,
     LINKS_DELAY = 352,
     LISTEN = 353,
     T_LOG = 354,
     LOGGING = 355,
     LOG_LEVEL = 356,
     MAX_ACCEPT = 357,
     MAX_BANS = 358,
     MAX_CHANS_PER_USER = 359,
     MAX_GLOBAL = 360,
     MAX_IDENT = 361,
     MAX_LOCAL = 362,
     MAX_NICK_CHANGES = 363,
     MAX_NICK_TIME = 364,
     MAX_NUMBER = 365,
     MAX_TARGETS = 366,
     MAX_WATCH = 367,
     MESSAGE_LOCALE = 368,
     MIN_NONWILDCARD = 369,
     MIN_NONWILDCARD_SIMPLE = 370,
     MODULE = 371,
     MODULES = 372,
     NAME = 373,
     NEED_PASSWORD = 374,
     NETWORK_DESC = 375,
     NETWORK_NAME = 376,
     NICK = 377,
     NICK_CHANGES = 378,
     NO_CREATE_ON_SPLIT = 379,
     NO_JOIN_ON_SPLIT = 380,
     NO_OPER_FLOOD = 381,
     NO_TILDE = 382,
     NUMBER = 383,
     NUMBER_PER_IDENT = 384,
     NUMBER_PER_CIDR = 385,
     NUMBER_PER_IP = 386,
     NUMBER_PER_IP_GLOBAL = 387,
     OPERATOR = 388,
     OPERS_BYPASS_CALLERID = 389,
     OPER_LOG = 390,
     OPER_ONLY_UMODES = 391,
     OPER_PASS_RESV = 392,
     OPER_SPY_T = 393,
     OPER_UMODES = 394,
     JOIN_FLOOD_COUNT = 395,
     JOIN_FLOOD_TIME = 396,
     PACE_WAIT = 397,
     PACE_WAIT_SIMPLE = 398,
     PASSWORD = 399,
     PATH = 400,
     PING_COOKIE = 401,
     PING_TIME = 402,
     PING_WARNING = 403,
     PORT = 404,
     QSTRING = 405,
     QUIET_ON_BAN = 406,
     REASON = 407,
     REDIRPORT = 408,
     REDIRSERV = 409,
     REGEX_T = 410,
     REHASH = 411,
     TREJECT_HOLD_TIME = 412,
     REMOTE = 413,
     REMOTEBAN = 414,
     RESTRICT_CHANNELS = 415,
     RESTRICTED = 416,
     RSA_PRIVATE_KEY_FILE = 417,
     RSA_PUBLIC_KEY_FILE = 418,
     SSL_CERTIFICATE_FILE = 419,
     T_SSL_CONNECTION_METHOD = 420,
     T_SSLV3 = 421,
     T_TLSV1 = 422,
     RESV = 423,
     RESV_EXEMPT = 424,
     SECONDS = 425,
     MINUTES = 426,
     HOURS = 427,
     DAYS = 428,
     WEEKS = 429,
     SENDQ = 430,
     SEND_PASSWORD = 431,
     SERVERHIDE = 432,
     SERVERINFO = 433,
     SERVLINK_PATH = 434,
     IRCD_SID = 435,
     TKLINE_EXPIRE_NOTICES = 436,
     T_SHARED = 437,
     T_CLUSTER = 438,
     TYPE = 439,
     SHORT_MOTD = 440,
     SILENT = 441,
     SPOOF = 442,
     SPOOF_NOTICE = 443,
     STATS_E_DISABLED = 444,
     STATS_I_OPER_ONLY = 445,
     STATS_K_OPER_ONLY = 446,
     STATS_O_OPER_ONLY = 447,
     STATS_P_OPER_ONLY = 448,
     TBOOL = 449,
     TMASKED = 450,
     T_REJECT = 451,
     TS_MAX_DELTA = 452,
     TS_WARN_DELTA = 453,
     TWODOTS = 454,
     T_ALL = 455,
     T_BOTS = 456,
     T_SOFTCALLERID = 457,
     T_CALLERID = 458,
     T_CCONN = 459,
     T_CCONN_FULL = 460,
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
     T_SERVER = 483,
     T_SERVNOTICE = 484,
     T_SKILL = 485,
     T_SPY = 486,
     T_SSL = 487,
     T_UMODES = 488,
     T_UNAUTH = 489,
     T_UNRESV = 490,
     T_UNXLINE = 491,
     T_GLOBOPS = 492,
     T_WALLOP = 493,
     T_RESTART = 494,
     T_SERVICE = 495,
     T_SERVICES_NAME = 496,
     THROTTLE_TIME = 497,
     TOPICBURST = 498,
     TRUE_NO_OPER_FLOOD = 499,
     TKLINE = 500,
     TXLINE = 501,
     TRESV = 502,
     UNKLINE = 503,
     USER = 504,
     USE_EGD = 505,
     USE_EXCEPT = 506,
     USE_INVEX = 507,
     USE_KNOCK = 508,
     USE_LOGGING = 509,
     USE_WHOIS_ACTUALLY = 510,
     VHOST = 511,
     VHOST6 = 512,
     XLINE = 513,
     WARN = 514,
     WARN_NO_NLINE = 515
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
#define FFAILED_OPERLOG 309
#define FKILLLOG 310
#define FKLINELOG 311
#define FGLINELOG 312
#define FIOERRLOG 313
#define FOPERLOG 314
#define FOPERSPYLOG 315
#define FUSERLOG 316
#define GECOS 317
#define GENERAL 318
#define GLINE 319
#define GLINES 320
#define GLINE_EXEMPT 321
#define GLINE_LOG 322
#define GLINE_TIME 323
#define GLINE_MIN_CIDR 324
#define GLINE_MIN_CIDR6 325
#define GLOBAL_KILL 326
#define IRCD_AUTH 327
#define NEED_IDENT 328
#define HAVENT_READ_CONF 329
#define HIDDEN 330
#define HIDDEN_ADMIN 331
#define HIDDEN_NAME 332
#define HIDDEN_OPER 333
#define HIDE_SERVER_IPS 334
#define HIDE_SERVERS 335
#define HIDE_SPOOF_IPS 336
#define HOST 337
#define HUB 338
#define HUB_MASK 339
#define IGNORE_BOGUS_TS 340
#define INVISIBLE_ON_CONNECT 341
#define IP 342
#define KILL 343
#define KILL_CHASE_TIME_LIMIT 344
#define KLINE 345
#define KLINE_EXEMPT 346
#define KLINE_REASON 347
#define KLINE_WITH_REASON 348
#define KNOCK_DELAY 349
#define KNOCK_DELAY_CHANNEL 350
#define LEAF_MASK 351
#define LINKS_DELAY 352
#define LISTEN 353
#define T_LOG 354
#define LOGGING 355
#define LOG_LEVEL 356
#define MAX_ACCEPT 357
#define MAX_BANS 358
#define MAX_CHANS_PER_USER 359
#define MAX_GLOBAL 360
#define MAX_IDENT 361
#define MAX_LOCAL 362
#define MAX_NICK_CHANGES 363
#define MAX_NICK_TIME 364
#define MAX_NUMBER 365
#define MAX_TARGETS 366
#define MAX_WATCH 367
#define MESSAGE_LOCALE 368
#define MIN_NONWILDCARD 369
#define MIN_NONWILDCARD_SIMPLE 370
#define MODULE 371
#define MODULES 372
#define NAME 373
#define NEED_PASSWORD 374
#define NETWORK_DESC 375
#define NETWORK_NAME 376
#define NICK 377
#define NICK_CHANGES 378
#define NO_CREATE_ON_SPLIT 379
#define NO_JOIN_ON_SPLIT 380
#define NO_OPER_FLOOD 381
#define NO_TILDE 382
#define NUMBER 383
#define NUMBER_PER_IDENT 384
#define NUMBER_PER_CIDR 385
#define NUMBER_PER_IP 386
#define NUMBER_PER_IP_GLOBAL 387
#define OPERATOR 388
#define OPERS_BYPASS_CALLERID 389
#define OPER_LOG 390
#define OPER_ONLY_UMODES 391
#define OPER_PASS_RESV 392
#define OPER_SPY_T 393
#define OPER_UMODES 394
#define JOIN_FLOOD_COUNT 395
#define JOIN_FLOOD_TIME 396
#define PACE_WAIT 397
#define PACE_WAIT_SIMPLE 398
#define PASSWORD 399
#define PATH 400
#define PING_COOKIE 401
#define PING_TIME 402
#define PING_WARNING 403
#define PORT 404
#define QSTRING 405
#define QUIET_ON_BAN 406
#define REASON 407
#define REDIRPORT 408
#define REDIRSERV 409
#define REGEX_T 410
#define REHASH 411
#define TREJECT_HOLD_TIME 412
#define REMOTE 413
#define REMOTEBAN 414
#define RESTRICT_CHANNELS 415
#define RESTRICTED 416
#define RSA_PRIVATE_KEY_FILE 417
#define RSA_PUBLIC_KEY_FILE 418
#define SSL_CERTIFICATE_FILE 419
#define T_SSL_CONNECTION_METHOD 420
#define T_SSLV3 421
#define T_TLSV1 422
#define RESV 423
#define RESV_EXEMPT 424
#define SECONDS 425
#define MINUTES 426
#define HOURS 427
#define DAYS 428
#define WEEKS 429
#define SENDQ 430
#define SEND_PASSWORD 431
#define SERVERHIDE 432
#define SERVERINFO 433
#define SERVLINK_PATH 434
#define IRCD_SID 435
#define TKLINE_EXPIRE_NOTICES 436
#define T_SHARED 437
#define T_CLUSTER 438
#define TYPE 439
#define SHORT_MOTD 440
#define SILENT 441
#define SPOOF 442
#define SPOOF_NOTICE 443
#define STATS_E_DISABLED 444
#define STATS_I_OPER_ONLY 445
#define STATS_K_OPER_ONLY 446
#define STATS_O_OPER_ONLY 447
#define STATS_P_OPER_ONLY 448
#define TBOOL 449
#define TMASKED 450
#define T_REJECT 451
#define TS_MAX_DELTA 452
#define TS_WARN_DELTA 453
#define TWODOTS 454
#define T_ALL 455
#define T_BOTS 456
#define T_SOFTCALLERID 457
#define T_CALLERID 458
#define T_CCONN 459
#define T_CCONN_FULL 460
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
#define T_SERVER 483
#define T_SERVNOTICE 484
#define T_SKILL 485
#define T_SPY 486
#define T_SSL 487
#define T_UMODES 488
#define T_UNAUTH 489
#define T_UNRESV 490
#define T_UNXLINE 491
#define T_GLOBOPS 492
#define T_WALLOP 493
#define T_RESTART 494
#define T_SERVICE 495
#define T_SERVICES_NAME 496
#define THROTTLE_TIME 497
#define TOPICBURST 498
#define TRUE_NO_OPER_FLOOD 499
#define TKLINE 500
#define TXLINE 501
#define TRESV 502
#define UNKLINE 503
#define USER 504
#define USE_EGD 505
#define USE_EXCEPT 506
#define USE_INVEX 507
#define USE_KNOCK 508
#define USE_LOGGING 509
#define USE_WHOIS_ACTUALLY 510
#define VHOST 511
#define VHOST6 512
#define XLINE 513
#define WARN 514
#define WARN_NO_NLINE 515




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 130 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 577 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


