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
     SSL_DH_PARAM_FILE = 401,
     T_SSL_CLIENT_METHOD = 402,
     T_SSL_SERVER_METHOD = 403,
     T_SSLV3 = 404,
     T_TLSV1 = 405,
     RESV = 406,
     RESV_EXEMPT = 407,
     SECONDS = 408,
     MINUTES = 409,
     HOURS = 410,
     DAYS = 411,
     WEEKS = 412,
     SENDQ = 413,
     SEND_PASSWORD = 414,
     SERVERHIDE = 415,
     SERVERINFO = 416,
     IRCD_SID = 417,
     TKLINE_EXPIRE_NOTICES = 418,
     T_SHARED = 419,
     T_CLUSTER = 420,
     TYPE = 421,
     SHORT_MOTD = 422,
     SILENT = 423,
     SPOOF = 424,
     SPOOF_NOTICE = 425,
     STATS_E_DISABLED = 426,
     STATS_I_OPER_ONLY = 427,
     STATS_K_OPER_ONLY = 428,
     STATS_O_OPER_ONLY = 429,
     STATS_P_OPER_ONLY = 430,
     TBOOL = 431,
     TMASKED = 432,
     T_REJECT = 433,
     TS_MAX_DELTA = 434,
     TS_WARN_DELTA = 435,
     TWODOTS = 436,
     T_ALL = 437,
     T_BOTS = 438,
     T_SOFTCALLERID = 439,
     T_CALLERID = 440,
     T_CCONN = 441,
     T_CCONN_FULL = 442,
     T_SSL_CIPHER_LIST = 443,
     T_CLIENT_FLOOD = 444,
     T_DEAF = 445,
     T_DEBUG = 446,
     T_DLINE = 447,
     T_DRONE = 448,
     T_EXTERNAL = 449,
     T_FULL = 450,
     T_INVISIBLE = 451,
     T_IPV4 = 452,
     T_IPV6 = 453,
     T_LOCOPS = 454,
     T_MAX_CLIENTS = 455,
     T_NCHANGE = 456,
     T_OPERWALL = 457,
     T_REJ = 458,
     T_SERVER = 459,
     T_SERVNOTICE = 460,
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
     TOPICBURST = 476,
     TRUE_NO_OPER_FLOOD = 477,
     TKLINE = 478,
     TXLINE = 479,
     TRESV = 480,
     UNKLINE = 481,
     USER = 482,
     USE_EGD = 483,
     USE_EXCEPT = 484,
     USE_INVEX = 485,
     USE_KNOCK = 486,
     USE_LOGGING = 487,
     USE_WHOIS_ACTUALLY = 488,
     VHOST = 489,
     VHOST6 = 490,
     XLINE = 491,
     WARN = 492,
     WARN_NO_NLINE = 493,
     T_SIZE = 494,
     T_FILE = 495
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
#define SSL_DH_PARAM_FILE 401
#define T_SSL_CLIENT_METHOD 402
#define T_SSL_SERVER_METHOD 403
#define T_SSLV3 404
#define T_TLSV1 405
#define RESV 406
#define RESV_EXEMPT 407
#define SECONDS 408
#define MINUTES 409
#define HOURS 410
#define DAYS 411
#define WEEKS 412
#define SENDQ 413
#define SEND_PASSWORD 414
#define SERVERHIDE 415
#define SERVERINFO 416
#define IRCD_SID 417
#define TKLINE_EXPIRE_NOTICES 418
#define T_SHARED 419
#define T_CLUSTER 420
#define TYPE 421
#define SHORT_MOTD 422
#define SILENT 423
#define SPOOF 424
#define SPOOF_NOTICE 425
#define STATS_E_DISABLED 426
#define STATS_I_OPER_ONLY 427
#define STATS_K_OPER_ONLY 428
#define STATS_O_OPER_ONLY 429
#define STATS_P_OPER_ONLY 430
#define TBOOL 431
#define TMASKED 432
#define T_REJECT 433
#define TS_MAX_DELTA 434
#define TS_WARN_DELTA 435
#define TWODOTS 436
#define T_ALL 437
#define T_BOTS 438
#define T_SOFTCALLERID 439
#define T_CALLERID 440
#define T_CCONN 441
#define T_CCONN_FULL 442
#define T_SSL_CIPHER_LIST 443
#define T_CLIENT_FLOOD 444
#define T_DEAF 445
#define T_DEBUG 446
#define T_DLINE 447
#define T_DRONE 448
#define T_EXTERNAL 449
#define T_FULL 450
#define T_INVISIBLE 451
#define T_IPV4 452
#define T_IPV6 453
#define T_LOCOPS 454
#define T_MAX_CLIENTS 455
#define T_NCHANGE 456
#define T_OPERWALL 457
#define T_REJ 458
#define T_SERVER 459
#define T_SERVNOTICE 460
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
#define TOPICBURST 476
#define TRUE_NO_OPER_FLOOD 477
#define TKLINE 478
#define TXLINE 479
#define TRESV 480
#define UNKLINE 481
#define USER 482
#define USE_EGD 483
#define USE_EXCEPT 484
#define USE_INVEX 485
#define USE_KNOCK 486
#define USE_LOGGING 487
#define USE_WHOIS_ACTUALLY 488
#define VHOST 489
#define VHOST6 490
#define XLINE 491
#define WARN 492
#define WARN_NO_NLINE 493
#define T_SIZE 494
#define T_FILE 495




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 537 "conf_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


