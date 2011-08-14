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
     NOT = 383,
     NUMBER = 384,
     NUMBER_PER_IDENT = 385,
     NUMBER_PER_CIDR = 386,
     NUMBER_PER_IP = 387,
     NUMBER_PER_IP_GLOBAL = 388,
     OPERATOR = 389,
     OPERS_BYPASS_CALLERID = 390,
     OPER_LOG = 391,
     OPER_ONLY_UMODES = 392,
     OPER_PASS_RESV = 393,
     OPER_SPY_T = 394,
     OPER_UMODES = 395,
     JOIN_FLOOD_COUNT = 396,
     JOIN_FLOOD_TIME = 397,
     PACE_WAIT = 398,
     PACE_WAIT_SIMPLE = 399,
     PASSWORD = 400,
     PATH = 401,
     PING_COOKIE = 402,
     PING_TIME = 403,
     PING_WARNING = 404,
     PORT = 405,
     QSTRING = 406,
     QUIET_ON_BAN = 407,
     REASON = 408,
     REDIRPORT = 409,
     REDIRSERV = 410,
     REGEX_T = 411,
     REHASH = 412,
     TREJECT_HOLD_TIME = 413,
     REMOTE = 414,
     REMOTEBAN = 415,
     RESTRICT_CHANNELS = 416,
     RESTRICTED = 417,
     RSA_PRIVATE_KEY_FILE = 418,
     RSA_PUBLIC_KEY_FILE = 419,
     SSL_CERTIFICATE_FILE = 420,
     T_SSL_CONNECTION_METHOD = 421,
     T_SSLV3 = 422,
     T_TLSV1 = 423,
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
     T_CCONN_FULL = 461,
     T_CLIENT_FLOOD = 462,
     T_DEAF = 463,
     T_DEBUG = 464,
     T_DRONE = 465,
     T_EXTERNAL = 466,
     T_FULL = 467,
     T_INVISIBLE = 468,
     T_IPV4 = 469,
     T_IPV6 = 470,
     T_LOCOPS = 471,
     T_LOGPATH = 472,
     T_L_CRIT = 473,
     T_L_DEBUG = 474,
     T_L_ERROR = 475,
     T_L_INFO = 476,
     T_L_NOTICE = 477,
     T_L_TRACE = 478,
     T_L_WARN = 479,
     T_MAX_CLIENTS = 480,
     T_NCHANGE = 481,
     T_OPERWALL = 482,
     T_REJ = 483,
     T_SERVER = 484,
     T_SERVNOTICE = 485,
     T_SKILL = 486,
     T_SPY = 487,
     T_SSL = 488,
     T_UMODES = 489,
     T_UNAUTH = 490,
     T_UNRESV = 491,
     T_UNXLINE = 492,
     T_WALLOP = 493,
     T_SERVICE = 494,
     T_SERVICES_NAME = 495,
     THROTTLE_TIME = 496,
     TOPICBURST = 497,
     TRUE_NO_OPER_FLOOD = 498,
     TKLINE = 499,
     TXLINE = 500,
     TRESV = 501,
     UNKLINE = 502,
     USER = 503,
     USE_EGD = 504,
     USE_EXCEPT = 505,
     USE_INVEX = 506,
     USE_KNOCK = 507,
     USE_LOGGING = 508,
     USE_WHOIS_ACTUALLY = 509,
     VHOST = 510,
     VHOST6 = 511,
     XLINE = 512,
     WARN = 513,
     WARN_NO_NLINE = 514
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
#define NOT 383
#define NUMBER 384
#define NUMBER_PER_IDENT 385
#define NUMBER_PER_CIDR 386
#define NUMBER_PER_IP 387
#define NUMBER_PER_IP_GLOBAL 388
#define OPERATOR 389
#define OPERS_BYPASS_CALLERID 390
#define OPER_LOG 391
#define OPER_ONLY_UMODES 392
#define OPER_PASS_RESV 393
#define OPER_SPY_T 394
#define OPER_UMODES 395
#define JOIN_FLOOD_COUNT 396
#define JOIN_FLOOD_TIME 397
#define PACE_WAIT 398
#define PACE_WAIT_SIMPLE 399
#define PASSWORD 400
#define PATH 401
#define PING_COOKIE 402
#define PING_TIME 403
#define PING_WARNING 404
#define PORT 405
#define QSTRING 406
#define QUIET_ON_BAN 407
#define REASON 408
#define REDIRPORT 409
#define REDIRSERV 410
#define REGEX_T 411
#define REHASH 412
#define TREJECT_HOLD_TIME 413
#define REMOTE 414
#define REMOTEBAN 415
#define RESTRICT_CHANNELS 416
#define RESTRICTED 417
#define RSA_PRIVATE_KEY_FILE 418
#define RSA_PUBLIC_KEY_FILE 419
#define SSL_CERTIFICATE_FILE 420
#define T_SSL_CONNECTION_METHOD 421
#define T_SSLV3 422
#define T_TLSV1 423
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
#define T_CCONN_FULL 461
#define T_CLIENT_FLOOD 462
#define T_DEAF 463
#define T_DEBUG 464
#define T_DRONE 465
#define T_EXTERNAL 466
#define T_FULL 467
#define T_INVISIBLE 468
#define T_IPV4 469
#define T_IPV6 470
#define T_LOCOPS 471
#define T_LOGPATH 472
#define T_L_CRIT 473
#define T_L_DEBUG 474
#define T_L_ERROR 475
#define T_L_INFO 476
#define T_L_NOTICE 477
#define T_L_TRACE 478
#define T_L_WARN 479
#define T_MAX_CLIENTS 480
#define T_NCHANGE 481
#define T_OPERWALL 482
#define T_REJ 483
#define T_SERVER 484
#define T_SERVNOTICE 485
#define T_SKILL 486
#define T_SPY 487
#define T_SSL 488
#define T_UMODES 489
#define T_UNAUTH 490
#define T_UNRESV 491
#define T_UNXLINE 492
#define T_WALLOP 493
#define T_SERVICE 494
#define T_SERVICES_NAME 495
#define THROTTLE_TIME 496
#define TOPICBURST 497
#define TRUE_NO_OPER_FLOOD 498
#define TKLINE 499
#define TXLINE 500
#define TRESV 501
#define UNKLINE 502
#define USER 503
#define USE_EGD 504
#define USE_EXCEPT 505
#define USE_INVEX 506
#define USE_KNOCK 507
#define USE_LOGGING 508
#define USE_WHOIS_ACTUALLY 509
#define VHOST 510
#define VHOST6 511
#define XLINE 512
#define WARN 513
#define WARN_NO_NLINE 514




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 575 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


