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
     HIDDEN_NAME = 322,
     HIDE_SERVER_IPS = 323,
     HIDE_SERVERS = 324,
     HIDE_SPOOF_IPS = 325,
     HOST = 326,
     HUB = 327,
     HUB_MASK = 328,
     IGNORE_BOGUS_TS = 329,
     INVISIBLE_ON_CONNECT = 330,
     IP = 331,
     KILL = 332,
     KILL_CHASE_TIME_LIMIT = 333,
     KLINE = 334,
     KLINE_EXEMPT = 335,
     KLINE_REASON = 336,
     KLINE_WITH_REASON = 337,
     KNOCK_DELAY = 338,
     KNOCK_DELAY_CHANNEL = 339,
     LEAF_MASK = 340,
     LINKS_DELAY = 341,
     LISTEN = 342,
     T_LOG = 343,
     MAX_ACCEPT = 344,
     MAX_BANS = 345,
     MAX_CHANS_PER_USER = 346,
     MAX_GLOBAL = 347,
     MAX_IDENT = 348,
     MAX_LOCAL = 349,
     MAX_NICK_CHANGES = 350,
     MAX_NICK_TIME = 351,
     MAX_NUMBER = 352,
     MAX_TARGETS = 353,
     MAX_WATCH = 354,
     MESSAGE_LOCALE = 355,
     MIN_NONWILDCARD = 356,
     MIN_NONWILDCARD_SIMPLE = 357,
     MODULE = 358,
     MODULES = 359,
     NAME = 360,
     NEED_PASSWORD = 361,
     NETWORK_DESC = 362,
     NETWORK_NAME = 363,
     NICK = 364,
     NICK_CHANGES = 365,
     NO_CREATE_ON_SPLIT = 366,
     NO_JOIN_ON_SPLIT = 367,
     NO_OPER_FLOOD = 368,
     NO_TILDE = 369,
     NUMBER = 370,
     NUMBER_PER_IDENT = 371,
     NUMBER_PER_CIDR = 372,
     NUMBER_PER_IP = 373,
     NUMBER_PER_IP_GLOBAL = 374,
     OPERATOR = 375,
     OPERS_BYPASS_CALLERID = 376,
     OPER_ONLY_UMODES = 377,
     OPER_PASS_RESV = 378,
     OPER_SPY_T = 379,
     OPER_UMODES = 380,
     JOIN_FLOOD_COUNT = 381,
     JOIN_FLOOD_TIME = 382,
     PACE_WAIT = 383,
     PACE_WAIT_SIMPLE = 384,
     PASSWORD = 385,
     PATH = 386,
     PING_COOKIE = 387,
     PING_TIME = 388,
     PING_WARNING = 389,
     PORT = 390,
     QSTRING = 391,
     QUIET_ON_BAN = 392,
     REASON = 393,
     REDIRPORT = 394,
     REDIRSERV = 395,
     REGEX_T = 396,
     REHASH = 397,
     TREJECT_HOLD_TIME = 398,
     REMOTE = 399,
     REMOTEBAN = 400,
     RESTRICT_CHANNELS = 401,
     RESTRICTED = 402,
     RSA_PRIVATE_KEY_FILE = 403,
     RSA_PUBLIC_KEY_FILE = 404,
     SSL_CERTIFICATE_FILE = 405,
     T_SSL_CONNECTION_METHOD = 406,
     T_SSLV3 = 407,
     T_TLSV1 = 408,
     RESV = 409,
     RESV_EXEMPT = 410,
     SECONDS = 411,
     MINUTES = 412,
     HOURS = 413,
     DAYS = 414,
     WEEKS = 415,
     SENDQ = 416,
     SEND_PASSWORD = 417,
     SERVERHIDE = 418,
     SERVERINFO = 419,
     SERVLINK_PATH = 420,
     IRCD_SID = 421,
     TKLINE_EXPIRE_NOTICES = 422,
     T_SHARED = 423,
     T_CLUSTER = 424,
     TYPE = 425,
     SHORT_MOTD = 426,
     SILENT = 427,
     SPOOF = 428,
     SPOOF_NOTICE = 429,
     STATS_E_DISABLED = 430,
     STATS_I_OPER_ONLY = 431,
     STATS_K_OPER_ONLY = 432,
     STATS_O_OPER_ONLY = 433,
     STATS_P_OPER_ONLY = 434,
     TBOOL = 435,
     TMASKED = 436,
     T_REJECT = 437,
     TS_MAX_DELTA = 438,
     TS_WARN_DELTA = 439,
     TWODOTS = 440,
     T_ALL = 441,
     T_BOTS = 442,
     T_SOFTCALLERID = 443,
     T_CALLERID = 444,
     T_CCONN = 445,
     T_CCONN_FULL = 446,
     T_CLIENT_FLOOD = 447,
     T_DEAF = 448,
     T_DEBUG = 449,
     T_DLINE = 450,
     T_DRONE = 451,
     T_EXTERNAL = 452,
     T_FULL = 453,
     T_INVISIBLE = 454,
     T_IPV4 = 455,
     T_IPV6 = 456,
     T_LOCOPS = 457,
     T_MAX_CLIENTS = 458,
     T_NCHANGE = 459,
     T_OPERWALL = 460,
     T_REJ = 461,
     T_SERVER = 462,
     T_SERVNOTICE = 463,
     T_SKILL = 464,
     T_SPY = 465,
     T_SSL = 466,
     T_UMODES = 467,
     T_UNAUTH = 468,
     T_UNLIMITED = 469,
     T_UNRESV = 470,
     T_UNXLINE = 471,
     T_GLOBOPS = 472,
     T_WALLOP = 473,
     T_RESTART = 474,
     T_SERVICE = 475,
     T_SERVICES_NAME = 476,
     T_TIMESTAMP = 477,
     THROTTLE_TIME = 478,
     TOPICBURST = 479,
     TRUE_NO_OPER_FLOOD = 480,
     TKLINE = 481,
     TXLINE = 482,
     TRESV = 483,
     UNKLINE = 484,
     USER = 485,
     USE_EGD = 486,
     USE_EXCEPT = 487,
     USE_INVEX = 488,
     USE_KNOCK = 489,
     USE_LOGGING = 490,
     USE_WHOIS_ACTUALLY = 491,
     VHOST = 492,
     VHOST6 = 493,
     XLINE = 494,
     WARN = 495,
     WARN_NO_NLINE = 496,
     T_SIZE = 497,
     T_FILE = 498
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
#define HIDDEN_NAME 322
#define HIDE_SERVER_IPS 323
#define HIDE_SERVERS 324
#define HIDE_SPOOF_IPS 325
#define HOST 326
#define HUB 327
#define HUB_MASK 328
#define IGNORE_BOGUS_TS 329
#define INVISIBLE_ON_CONNECT 330
#define IP 331
#define KILL 332
#define KILL_CHASE_TIME_LIMIT 333
#define KLINE 334
#define KLINE_EXEMPT 335
#define KLINE_REASON 336
#define KLINE_WITH_REASON 337
#define KNOCK_DELAY 338
#define KNOCK_DELAY_CHANNEL 339
#define LEAF_MASK 340
#define LINKS_DELAY 341
#define LISTEN 342
#define T_LOG 343
#define MAX_ACCEPT 344
#define MAX_BANS 345
#define MAX_CHANS_PER_USER 346
#define MAX_GLOBAL 347
#define MAX_IDENT 348
#define MAX_LOCAL 349
#define MAX_NICK_CHANGES 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_WATCH 354
#define MESSAGE_LOCALE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MODULE 358
#define MODULES 359
#define NAME 360
#define NEED_PASSWORD 361
#define NETWORK_DESC 362
#define NETWORK_NAME 363
#define NICK 364
#define NICK_CHANGES 365
#define NO_CREATE_ON_SPLIT 366
#define NO_JOIN_ON_SPLIT 367
#define NO_OPER_FLOOD 368
#define NO_TILDE 369
#define NUMBER 370
#define NUMBER_PER_IDENT 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP 373
#define NUMBER_PER_IP_GLOBAL 374
#define OPERATOR 375
#define OPERS_BYPASS_CALLERID 376
#define OPER_ONLY_UMODES 377
#define OPER_PASS_RESV 378
#define OPER_SPY_T 379
#define OPER_UMODES 380
#define JOIN_FLOOD_COUNT 381
#define JOIN_FLOOD_TIME 382
#define PACE_WAIT 383
#define PACE_WAIT_SIMPLE 384
#define PASSWORD 385
#define PATH 386
#define PING_COOKIE 387
#define PING_TIME 388
#define PING_WARNING 389
#define PORT 390
#define QSTRING 391
#define QUIET_ON_BAN 392
#define REASON 393
#define REDIRPORT 394
#define REDIRSERV 395
#define REGEX_T 396
#define REHASH 397
#define TREJECT_HOLD_TIME 398
#define REMOTE 399
#define REMOTEBAN 400
#define RESTRICT_CHANNELS 401
#define RESTRICTED 402
#define RSA_PRIVATE_KEY_FILE 403
#define RSA_PUBLIC_KEY_FILE 404
#define SSL_CERTIFICATE_FILE 405
#define T_SSL_CONNECTION_METHOD 406
#define T_SSLV3 407
#define T_TLSV1 408
#define RESV 409
#define RESV_EXEMPT 410
#define SECONDS 411
#define MINUTES 412
#define HOURS 413
#define DAYS 414
#define WEEKS 415
#define SENDQ 416
#define SEND_PASSWORD 417
#define SERVERHIDE 418
#define SERVERINFO 419
#define SERVLINK_PATH 420
#define IRCD_SID 421
#define TKLINE_EXPIRE_NOTICES 422
#define T_SHARED 423
#define T_CLUSTER 424
#define TYPE 425
#define SHORT_MOTD 426
#define SILENT 427
#define SPOOF 428
#define SPOOF_NOTICE 429
#define STATS_E_DISABLED 430
#define STATS_I_OPER_ONLY 431
#define STATS_K_OPER_ONLY 432
#define STATS_O_OPER_ONLY 433
#define STATS_P_OPER_ONLY 434
#define TBOOL 435
#define TMASKED 436
#define T_REJECT 437
#define TS_MAX_DELTA 438
#define TS_WARN_DELTA 439
#define TWODOTS 440
#define T_ALL 441
#define T_BOTS 442
#define T_SOFTCALLERID 443
#define T_CALLERID 444
#define T_CCONN 445
#define T_CCONN_FULL 446
#define T_CLIENT_FLOOD 447
#define T_DEAF 448
#define T_DEBUG 449
#define T_DLINE 450
#define T_DRONE 451
#define T_EXTERNAL 452
#define T_FULL 453
#define T_INVISIBLE 454
#define T_IPV4 455
#define T_IPV6 456
#define T_LOCOPS 457
#define T_MAX_CLIENTS 458
#define T_NCHANGE 459
#define T_OPERWALL 460
#define T_REJ 461
#define T_SERVER 462
#define T_SERVNOTICE 463
#define T_SKILL 464
#define T_SPY 465
#define T_SSL 466
#define T_UMODES 467
#define T_UNAUTH 468
#define T_UNLIMITED 469
#define T_UNRESV 470
#define T_UNXLINE 471
#define T_GLOBOPS 472
#define T_WALLOP 473
#define T_RESTART 474
#define T_SERVICE 475
#define T_SERVICES_NAME 476
#define T_TIMESTAMP 477
#define THROTTLE_TIME 478
#define TOPICBURST 479
#define TRUE_NO_OPER_FLOOD 480
#define TKLINE 481
#define TXLINE 482
#define TRESV 483
#define UNKLINE 484
#define USER 485
#define USE_EGD 486
#define USE_EXCEPT 487
#define USE_INVEX 488
#define USE_KNOCK 489
#define USE_LOGGING 490
#define USE_WHOIS_ACTUALLY 491
#define VHOST 492
#define VHOST6 493
#define XLINE 494
#define WARN 495
#define WARN_NO_NLINE 496
#define T_SIZE 497
#define T_FILE 498




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 543 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


