/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  numeric.h: A header for the numeric functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#ifndef INCLUDED_numeric_h
#define INCLUDED_numeric_h

/*
 * Reserve numerics 000-099 for server-client connections where the client
 * is local to the server. If any server is passed a numeric in this range
 * from another server then it is remapped to 100-199. -avalon
 */
#define RPL_WELCOME          001
#define RPL_YOURHOST         002
#define RPL_CREATED          003
#define RPL_MYINFO           004
#define RPL_ISUPPORT         005
     /* RPL_BOUNCE                         IRCnet extension */
/*	RPL_MAP		       6	unreal */
/*	RPL_MAPEND	       7	unreal */
/*	RPL_SNOMASK            8        Undernet extension */
/*	RPL_STATMEMTOT         9        Undernet extension */
/*	RPL_STATMEM           10        Undernet extension */

#define RPL_REDIR            10
#define RPL_MAP		     15		/* Undernet extension */
#define RPL_MAPMORE	     16		/* Undernet extension */
#define RPL_MAPEND	     17		/* Undernet extension */

#define RPL_YOURID	     42		/* IRCnet extension */
/*      RPL_ATTEMPTINGJUNC    50           aircd extension */
/*      RPL_ATTEMPTINGREROUTE 51           aircd extension */

/*
 * Numeric replies from server commands.
 * These are currently in the range 200-399.
 */
#define RPL_TRACELINK        200
#define RPL_TRACECONNECTING  201
#define RPL_TRACEHANDSHAKE   202
#define RPL_TRACEUNKNOWN     203
#define RPL_TRACEOPERATOR    204
#define RPL_TRACEUSER        205
#define RPL_TRACESERVER      206
#define RPL_TRACECAPTURED    207
#define RPL_TRACENEWTYPE     208
#define RPL_TRACECLASS       209

/*      RPL_STATS            210 aircd extension, used instead of having
                                 multiple stats numerics */
/*      RPL_TRACERECONNECT   210 IRCnet extension */                                 

#define RPL_STATSLINKINFO    211
#define RPL_STATSCOMMANDS    212
#define RPL_STATSCLINE       213
#define RPL_STATSNLINE       214
/*	RPL_STATSOLDNLINE    214    unreal */
#define RPL_STATSILINE       215
#define RPL_STATSKLINE       216
#define RPL_STATSQLINE       217
#define RPL_STATSYLINE       218
#define RPL_ENDOFSTATS       219
/* note ircu uses 217 for STATSPLINE frip. conflict
 * as RPL_STATSQLINE was used in old 2.8 for Q line 
 * I'm going to steal 220 for now *sigh*
 * -Dianora
 */

#define RPL_STATSPLINE       220
#define RPL_UMODEIS          221

/*	RPL_SQLINE_NICK	     222	   Numerics List: Dalnet */
/*	RPL_STATSELINE       223	   dalnet */
/*	RPL_STATSGLINE	     223	   unreal */
/*      RPL_STATSFLINE       224           Hybrid extension,Dalnet */
/*	RPL_STATSTLINE	     224	   unreal */
/*      RPL_STATSDLINE       225           Hybrid extension */
/*	RPL_STATSZLINE	     225	   Dalnet
 	RPL_STATSELINE	     225	   unreal
 	RPL_STATSCOUNT	     226	   Dalnet
	RPL_STATSNLINE	     226	   unreal
	RPL_STATSGLINE	     227	   Dalnet 
	RPL_STATSVLINE	     227	   unreal */

#define RPL_STATSFLINE       224
#define RPL_STATSDLINE       225
#define RPL_STATSALINE	     226
#define RPL_STATSCCOUNT      228

/*	RPL_RULES	     232	unreal */

/*      RPL_STATSIAUTH       239           IRCnet extension */
/*      RPL_STATSVLINE       240           IRCnet extension */
/*	RPL_STATSXLINE	     240	austnet */

#define RPL_STATSLLINE       241
#define RPL_STATSUPTIME      242
#define RPL_STATSOLINE       243
#define RPL_STATSHLINE       244
/* 245 No longer used in ircd-hybrid */
#define RPL_STATSSLINE       245
#define RPL_STATSXLINE       247
#define RPL_STATSULINE       248
#define RPL_STATSDEBUG       249
#define RPL_STATSCONN        250
/*	RPL_STATSDLINE	     250	   Numerics List: IRCnet */
#define RPL_LUSERCLIENT      251
#define RPL_LUSEROP          252
#define RPL_LUSERUNKNOWN     253
#define RPL_LUSERCHANNELS    254
#define RPL_LUSERME          255
#define RPL_ADMINME          256
#define RPL_ADMINLOC1        257
#define RPL_ADMINLOC2        258
#define RPL_ADMINEMAIL       259

#define RPL_ENDOFTRACE       262
#define RPL_LOAD2HI          263

/*	RPL_TRYAGAIN	     263	   Numerics List: IRCnet */
/*	RPL_LOAD2HI	     263	   Dalnet */
/*      RPL_CURRENT_LOCAL    265           aircd/efnet/hybrid/dalnet*/
/*      RPL_CURRENT_GLOBAL   266           aircd/efnet/hybrid/dalnet */
/*      RPL_START_NETSTAT    267           aircd */
/*      RPL_NETSTAT          268           aircd */
/*      RPL_END_NETSTAT      269           aircd */

#define RPL_LOCALUSERS       265
#define RPL_GLOBALUSERS      266

#define RPL_WHOISSSL         275
#define RPL_WHOISCERTFP      276

#define RPL_ACCEPTLIST	     281
#define RPL_ENDOFACCEPT      282

/*	RPL_GLIST            280        Undernet extension */
/*	RPL_ENDOFGLIST       281        Undernet extension */
/*	RPL_JUPELIST         282        Undernet extension - jupe -Kev */
/*	RPL_ENDOFJUPELIST    283        Undernet extension - jupe -Kev */
/*	RPL_FEATURE	     284	Undernet extension - features */
/*      RPL_CHANINFO_HANDLE  285           aircd */
/*      RPL_CHANINFO_USERS   286           aircd */
/*      RPL_CHANINFO_CHOPS   287           aircd */
/*      RPL_CHANINFO_VOICES  288           aircd */
/*      RPL_CHANINFO_AWAY    289           aircd */
/*      RPL_CHANINFO_OPERS   290           aircd */
/*	RPL_HELPHDR	     290	Numeric List: Dalnet */
/*      RPL_CHANINFO_BANNED  291           aircd */
/*	RPL_HELPOP	     291	Numeric List: Dalnet */
/*      RPL_CHANINFO_BANS    292           aircd */
/*	RPL_HELPTLR	     292	Numeric List: Dalnet */
/*      RPL_CHANINFO_INVITE  293           aircd */
/*	RPL_HELPHLP	     293	Numeric List: Dalnet */
/*      RPL_CHANINFO_INVITES 294           aircd */
/*	RPL_HELPFWD	     294	Numeric List: Dalnet */
/*      RPL_CHANINFO_KICK    295           aircd */
/*	RPL_HELPIGN	     295	Numeric List: Dalnet */
/*      RPL_CHANINFO_KICKS   296           aircd */

/*      RPL_END_CHANINFO     299           aircd */

/* numeric_replies */
#define RPL_AWAY             301
#define RPL_USERHOST         302
#define RPL_ISON             303
#define RPL_TEXT             304
#define RPL_UNAWAY           305
#define RPL_NOWAWAY          306
#define	RPL_USERIP	     307	/* Undernet extension */
/*	RPL_WHOISREGNICK     307 	Numeric List: Dalnet */
/*	RPL_SUSERHOST	     307	austnet */
/*      RPL_NOTIFYACTION     308         aircd */
#define RPL_WHOISADMIN	     308	/* Numeric List: Dalnet */
/*	RPL_RULESSTART	     308	unreal */
/*      RPL_NICKTRACE        309         aircd */
/*	RPL_WHOISSADMIN	     309	Numeric List: Dalnet */
/*	RPL_ENDOFRULES	     309	unreal */
/*	RPL_WHOISHELPER	     309	austnet */
/*      RPL_WHOISSVCMSG      310         Dalnet */
/*	RPL_WHOISHELPOP	     310	unreal */
/*	RPL_WHOISSERVICE     310	austnet */

#define RPL_WHOISNICKSERVREG 307
#define RPL_WHOISADMIN       308
#define RPL_WHOISSERVICE     309

#define RPL_WHOISREAL        320
#define RPL_WHOISUSER        311
#define RPL_WHOISSERVER      312
#define RPL_WHOISOPERATOR    313

#define RPL_WHOWASUSER       314
/* rpl_endofwho below (315) */
#define RPL_ENDOFWHOWAS      369

#define RPL_WHOISCHANOP      316 /* redundant and not needed but reserved */
#define RPL_WHOISIDLE        317

#define RPL_ENDOFWHOIS       318
#define RPL_WHOISCHANNELS    319
/*      RPL_WHOIS_HIDDEN     320         Anothernet +h, ick! */
/*	RPL_WHOISSPECIAL     320	unreal */
#define RPL_LISTSTART        321
#define RPL_LIST             322
#define RPL_LISTEND          323
#define RPL_CHANNELMODEIS    324
/*      RPL_CHANNELPASSIS    325           IRCnet extension */
/*      RPL_UNIQOPIS         325           IRCnet extension */
/*      RPL_NOCHANPASS       326           IRCnet extension */
/*      RPL_CHPASSUNKNOWN    327           IRCnet extension */
/*      RPL_CHANNEL_URL      328           dalnet, anothernet */
#define RPL_CREATIONTIME     329
/*      RPL_WHOWAS_TIME      330               ? */
#define RPL_NOTOPIC          331
#define RPL_TOPIC            332
#define RPL_TOPICWHOTIME     333
#define RPL_WHOHELP          334
/*	RPL_LISTSYNTAX	     334	   unreal */
/*      RPL_CHANPASSOK       338           IRCnet extension (?)*/
#define	RPL_WHOISACTUALLY    338	/* dalnet */
/*	RPL_WHOISACTUALLY    338	   Undernet extension, dalnet */
/*      RPL_BADCHANPASS      339           IRCnet extension (?)*/
/*	RPL_USERIP           340           (old) Undernet extension */
#define RPL_INVITING         341
/*	RPL_SUMMONING        342	   removed from RFC1459 */

#define RPL_QUIETLIST        344
#define RPL_ENDOFQUIETLIST   345
#define RPL_INVITELIST       346
#define RPL_ENDOFINVITELIST  347	/* IRCnet, Undernet extension */
#define RPL_EXCEPTLIST       348
#define RPL_ENDOFEXCEPTLIST  349

#define RPL_VERSION          351

#define RPL_WHOREPLY         352
#define RPL_ENDOFWHO         315
#define RPL_NAMREPLY         353
#define RPL_ENDOFNAMES       366

#define RPL_CLOSING          362
#define RPL_CLOSEEND         363
#define RPL_LINKS            364
#define RPL_ENDOFLINKS       365
/* rpl_endofnames above (366) */
#define RPL_BANLIST          367
#define RPL_ENDOFBANLIST     368
/* rpl_endofwhowas above (369) */

#define RPL_INFO             371
#define RPL_MOTD             372
#define RPL_INFOSTART        373
#define RPL_ENDOFINFO        374
#define RPL_MOTDSTART        375
#define RPL_ENDOFMOTD        376

/*      RPL_KICKEXPIRED      377   aircd */
/*	RPL_SPAM	     377   austnet */
/*      RPL_BANEXPIRED       378   aircd */
/*      RPL_KICKLINKED       379   aircd */
/*      RPL_BANLINKED        380   aircd */

#define RPL_YOUREOPER        381
#define RPL_REHASHING        382
/*	RPL_YOURSERVICE	     383	   Numeric List: various */
#define RPL_RSACHALLENGE     386

/*	RPL_QLIST	     386	unreal */
/*	RPL_ENDOFQLIST	     387	unreal */
/*	RPL_ALIST	     388	unreal */
/*	RPL_ENDOFALIST	     389	unreal */ 

#define RPL_TIME             391
#define RPL_USERSSTART       392
#define RPL_USERS            393
#define RPL_ENDOFUSERS       394
#define RPL_NOUSERS          395
#define RPL_HOSTHIDDEN       396

/*
 * Errors are in the range from 400-599 currently and are grouped by what
 * commands they come from.
 */
#define ERR_NOSUCHNICK       401
#define ERR_NOSUCHSERVER     402
#define ERR_NOSUCHCHANNEL    403
#define ERR_CANNOTSENDTOCHAN 404
#define ERR_TOOMANYCHANNELS  405
#define ERR_WASNOSUCHNICK    406
#define ERR_TOOMANYTARGETS   407
#define ERR_NOORIGIN         409
#define ERR_INVALIDCAPCMD    410


#define ERR_NORECIPIENT      411
#define ERR_NOTEXTTOSEND     412
#define ERR_NOTOPLEVEL       413
#define ERR_WILDTOPLEVEL     414
/*	ERR_BADMASK          415           IRCnet extension */
#define ERR_CANTSENDREGONLY  415
#define ERR_UNKNOWNCOMMAND   421
#define ERR_NOMOTD           422
#define ERR_NOADMININFO      423

/* 	ERR_TOOMANYAWAY	     429	    Dalnet */

#define ERR_NONICKNAMEGIVEN  431
#define ERR_ERRONEUSNICKNAME 432
#define ERR_NICKNAMEINUSE    433

/*      ERR_SERVICENAMEINUSE 434 ? */
/*	ERR_NORULES	     434   unreal */
/*      ERR_SERVICECONFUSED  435 ? */
#define ERR_NONICKWHILEBAN   434 
/*      ERR_NICKONBAN        435 dalnet */

#define ERR_NICKCOLLISION    436
#define ERR_UNAVAILRESOURCE  437
#define ERR_NICKTOOFAST	     438	/* We did it first Undernet! ;) db */

#define ERR_SERVICESDOWN     440

#define ERR_USERNOTINCHANNEL 441
#define ERR_NOTONCHANNEL     442
#define ERR_USERONCHANNEL    443

#define ERR_NOTREGISTERED    451

/*      ERR_IDCOLLISION      452           IRCnet extension ? */
/*      ERR_NICKLOST         453           IRCnet extension ? */

/*	ERR_HOSTILENAME	     455	   unreal */

/*	ERR_NOHIDING	     459	   unreal */
/*	ERR_NOTFORHALFOPS    460	   unreal */

#define ERR_ACCEPTFULL       456
#define ERR_ACCEPTEXIST      457
#define ERR_ACCEPTNOT        458

#define ERR_NEEDMOREPARAMS   461
#define ERR_ALREADYREGISTRED 462
#define ERR_PASSWDMISMATCH   464
#define ERR_YOUREBANNEDCREEP 465
/* 	ERR_ONLYSERVERSCANCHANGE 468	   Dalnet,unreal */
/*	ERR_LINKSET	     469	unreal */
/*	ERR_LINKCHANNEL	     470	unreal */
/*      ERR_KICKEDFROMCHAN   470         aircd */
#define ERR_CHANNELISFULL    471
#define ERR_UNKNOWNMODE      472
#define ERR_INVITEONLYCHAN   473
#define ERR_BANNEDFROMCHAN   474
#define ERR_BADCHANNELKEY    475
#define ERR_REGONLYCHAN      477
#define ERR_BANLISTFULL      478        /* I stole the numeric from ircu -db */
#define ERR_BADCHANNAME      479
/* 	ERR_LINKFAIL	     479	unreal */
/*	ERR_CANNOTKNOCK	     480	unreal */
/*	ERR_NOULINE	     480	austnet */
#define ERR_SSLONLYCHAN      480
#define ERR_NOPRIVILEGES     481
#define ERR_CHANOPRIVSNEEDED 482
#define ERR_CANTKILLSERVER   483
#define ERR_RESTRICTED       484
/*	ERR_DESYNC	     484	 Dalnet,PTlink */
/*	ERR_ATTACKDENY	     484	 unreal */
/*	ERR_RESTRICTED	     484	   IRCnet extension */
/*      ERR_UNIQOPRIVSNEEDED 485           IRCnet extension */
/*	ERR_KILLDENY         485	   unreal */
/*	ERR_CANTKICKADMIN    485	   PTlink */
/*	ERR_HTMDISABLED      486	   unreal */
/*      ERR_CHANTOORECENT    487           IRCnet extension (?) */
/*      ERR_TSLESSCHAN       488           IRCnet extension (?) */
/*	ERR_VOICENEEDED      489           Undernet extension */
#define ERR_NOOPERHOST       491
/*      ERR_NOSERVICEHOST    492 	   IRCnet extension */

#define ERR_UMODEUNKNOWNFLAG 501
#define ERR_USERSDONTMATCH   502

#define ERR_GHOSTEDCLIENT    503
/*	ERR_VWORLDWARN	     503	   austnet */

#define ERR_USERNOTONSERV    504

/* #define ERR_LAST_ERR_MSG 505 
 * moved to 999
 */

/*      ERR_NOTIFYFULL       512           aircd */
/*	ERR_TOOMANYWATCH     512           Numeric List: Dalnet */
/*      ERR_NEEDPONG	     512           Numeric List: Dalnet */

#define ERR_WRONGPONG	     513
/*	ERR_TOOMANYDCC	     514	dalnet */
/*	ERR_NOINVITE	     518	unreal */
#define ERR_LONGMASK	     518	/* Undernet extension -Kev */
/*	ERR_ADMONLY	     519	unreal */
/*	ERR_TOOMANYUSERS     519	Undernet extension -Kev */
/*	ERR_OPERONLY	     520	unreal */
/*	ERR_MASKTOOWIDE	     520	Undernet extension -Kev */
/*	ERR_WHOTRUNC	     520	austnet */
/*	ERR_LASTERROR        521	Undernet extension -Kev */
#define	ERR_LISTSYNTAX       521
#define	ERR_WHOSYNTAX	       522
#define ERR_WHOLIMEXCEED     523

#define ERR_HELPNOTFOUND     524

/*	RPL_LOGON	     600	dalnet,unreal
	RPL_LOGOFF           601	dalnet,unreal
	RPL_WATCHOFF         602	dalnet,unreal
	RPL_WATCHSTAT        603	dalnet,unreal
	RPL_NOWON            604	dalnet,unreal
	RPL_NOWOFF           605	dalnet,unreal
	RPL_WATCHLIST        606	dalnet,unreal
	RPL_ENDOFWATCHLIST   607	dalnet,unreal

	RPL_MAPMORE          610	unreal

	RPL_MAPMORE          615	PTlink
	
	RPL_DCCSTATUS        617	dalnet
	RPL_DCCLIST          618	dalnet
	RPL_ENDOFDCCLIST     619	dalnet
	RPL_DCCINFO          620	dalnet
	
	RPL_DUMPING	     640	unreal
	RPL_DUMPRPL	     641	unreal
	RPL_EODUMP	     642	unreal
*/

#define RPL_MODLIST          702
#define RPL_ENDOFMODLIST     703

#define RPL_HELPSTART        704
#define RPL_HELPTXT          705
#define RPL_ENDOFHELP        706

#define RPL_KNOCK	     710
#define RPL_KNOCKDLVR	     711

#define ERR_TOOMANYKNOCK     712
#define ERR_CHANOPEN         713
#define ERR_KNOCKONCHAN      714
#define ERR_KNOCKDISABLED    715

#define RPL_TARGUMODEG       716
#define RPL_TARGNOTIFY       717
#define RPL_UMODEGMSG        718

#define RPL_OMOTDSTART	     720
#define RPL_OMOTD	     721
#define RPL_ENDOFOMOTD	     722

#define ERR_NOPRIVS	     723

#define RPL_TESTMASK	     724
#define RPL_TESTLINE	     725
#define RPL_NOTESTLINE	     726
#define RPL_ISCAPTURED	     727
#define RPL_ISUNCAPTURED     728

#define ERR_LAST_ERR_MSG     999

#define FORM_STR1(numeric)   NUMERIC_STR_##numeric
#define form_str(numeric)    FORM_STR1(numeric)

#define NUMERIC_STR_001 ":%s 001 %s :Welcome to the %s Internet Relay Chat Network %s"
#define NUMERIC_STR_002 ":%s 002 %s :Your host is %s, running version %s"
#define NUMERIC_STR_003 ":%s 003 %s :This server was created %s"
#ifdef HALFOPS
#define NUMERIC_STR_004 ":%s 004 %s %s %s %s biklmnopstveIh bkloveIh"
#else
#define NUMERIC_STR_004 ":%s 004 %s %s %s %s bciklmnopstvzeIMRS bkloveI"
#endif
#define NUMERIC_STR_005 ":%s 005 %s %s :are supported by this server"
#define NUMERIC_STR_10 ":%s 010 %s %s %d :Please use this Server/Port instead"
#define NUMERIC_STR_15 ":%s 015 %s :%s"
#define NUMERIC_STR_17 ":%s 017 %s :End of /MAP"
#define NUMERIC_STR_42 ":%s 042 %s %s :your unique ID"
#define NUMERIC_STR_200 ":%s 200 %s Link %s %s %s"
#define NUMERIC_STR_201 ":%s 201 %s Try. %s %s"
#define NUMERIC_STR_202 ":%s 202 %s H.S. %s %s"
#define NUMERIC_STR_203 ":%s 203 %s ???? %s %s (%s) %ld"
#define NUMERIC_STR_204 ":%s 204 %s Oper %s %s (%s) %lu %lu"
#define NUMERIC_STR_205 ":%s 205 %s User %s %s (%s) %lu %lu"
#define NUMERIC_STR_206 ":%s 206 %s Serv %s %dS %dC %s %s!%s@%s %lu"
#define NUMERIC_STR_207 ":%s 207 %s Capt %s %s (%s) %lu %lu"
#define NUMERIC_STR_208 ":%s 208 %s <newtype> 0 %s"
#define NUMERIC_STR_209 ":%s 209 %s Class %s %d"
#define NUMERIC_STR_211 ":%s 211 %s %s %zu %u %" PRIu64 " %u %" PRIu64 " :%u %u %s"
#define NUMERIC_STR_212 ":%s 212 %s %s %u %lu :%u"
#define NUMERIC_STR_213 ":%s 213 %s %c %s %s %s %d %s"
#define NUMERIC_STR_214 ":%s 214 %s %c %s * %s %d %s"
#define NUMERIC_STR_215 ":%s 215 %s %c %s * %s@%s %d %s"
#define NUMERIC_STR_216 ":%s 216 %s %s %s * %s :%s | %s"
#define NUMERIC_STR_217 ":%s 217 %s %c %s :%s"
#define NUMERIC_STR_218 ":%s 218 %s %c %s %d %d %d %lu %d %s"
#define NUMERIC_STR_219 ":%s 219 %s %c :End of /STATS report"
#define NUMERIC_STR_220 ":%s 220 %s %c %d %s %d %s :%s"
#define NUMERIC_STR_221 ":%s 221 %s %s"
#define NUMERIC_STR_225 ":%s 225 %s %c %s :%s | %s"
#define NUMERIC_STR_226 ":%s 226 %s %s"
#define NUMERIC_STR_241 ":%s 241 %s %c %s * %s %d %s"
#define NUMERIC_STR_242 ":%s 242 %s :Server Up %ld days, %ld:%02ld:%02ld"
#define NUMERIC_STR_243 ":%s 243 %s %c %s@%s * %s %s %s"
#define NUMERIC_STR_244 ":%s 244 %s %c %s * %s %d %s"
#define NUMERIC_STR_247 ":%s 247 %s %s %d %s :%s"
#define NUMERIC_STR_248 ":%s 248 %s U %s %s@%s %s"
#define NUMERIC_STR_250 ":%s 250 %s :Highest connection count: %d (%d clients) (%lu connections received)"
#define NUMERIC_STR_251 ":%s 251 %s :There are %d users and %d invisible on %lu servers"
#define NUMERIC_STR_252 ":%s 252 %s %d :IRC Operators online"
#define NUMERIC_STR_253 ":%s 253 %s %lu :unknown connection(s)"
#define NUMERIC_STR_254 ":%s 254 %s %lu :channels formed"
#define NUMERIC_STR_255 ":%s 255 %s :I have %d clients and %d servers"
#define NUMERIC_STR_256 ":%s 256 %s :Administrative info about %s"
#define NUMERIC_STR_257 ":%s 257 %s :%s"
#define NUMERIC_STR_258 ":%s 258 %s :%s"
#define NUMERIC_STR_259 ":%s 259 %s :%s"
#define NUMERIC_STR_262 ":%s 262 %s %s :End of TRACE"
#define NUMERIC_STR_263 ":%s 263 %s :Server load is temporarily too heavy. Please wait a while and try again."
#define NUMERIC_STR_265 ":%s 265 %s :Current local users: %d  Max: %d"
#define NUMERIC_STR_266 ":%s 266 %s :Current global users: %d  Max: %d"
#define NUMERIC_STR_275 ":%s 275 %s %s :is connected via SSL (secure link)"
#define NUMERIC_STR_276 ":%s 276 %s %s :has client certificate fingerprint %s"
#define NUMERIC_STR_281 ":%s 281 %s :%s"
#define NUMERIC_STR_282 ":%s 282 %s :End of /ACCEPT list."
#define NUMERIC_STR_301 ":%s 301 %s %s :%s"
#define NUMERIC_STR_302 ":%s 302 %s :%s"
#define NUMERIC_STR_303 ":%s 303 %s :"
#define NUMERIC_STR_305 ":%s 305 %s :You are no longer marked as being away"
#define NUMERIC_STR_306 ":%s 306 %s :You have been marked as being away"
#define NUMERIC_STR_307 ":%s 307 %s %s :user has identified and verified with services"
#define NUMERIC_STR_308 ":%s 308 %s %s :is a Server Administrator"
#define NUMERIC_STR_309 ":%s 309 %s %s :is a Network Service"
#define NUMERIC_STR_311 ":%s 311 %s %s %s %s * :%s"
#define NUMERIC_STR_312 ":%s 312 %s %s %s :%s"
#define NUMERIC_STR_313 ":%s 313 %s %s :is an IRC Operator"
#define NUMERIC_STR_314 ":%s 314 %s %s %s %s * :%s"
#define NUMERIC_STR_315 ":%s 315 %s %s :End of /WHO list."
#define NUMERIC_STR_317 ":%s 317 %s %s %ld %ld :seconds idle, signon time"
#define NUMERIC_STR_318 ":%s 318 %s %s :End of /WHOIS list."
#define NUMERIC_STR_319 ":%s 319 %s %s :%s"
#define NUMERIC_STR_320 ":%s 320 %s %s :is really (%s)"
#define NUMERIC_STR_321 ":%s 321 %s Channel :Users  Name"
#define NUMERIC_STR_322 ":%s 322 %s %s %lu :%s"
#define NUMERIC_STR_323 ":%s 323 %s :End of /LIST"
#define NUMERIC_STR_324 ":%s 324 %s %s %s %s"
#define NUMERIC_STR_329 ":%s 329 %s %s %lu"
#define NUMERIC_STR_331 ":%s 331 %s %s :No topic is set."
#define NUMERIC_STR_332 ":%s 332 %s %s :%s"
#define NUMERIC_STR_333 ":%s 333 %s %s %s %lu"
#define NUMERIC_STR_334 ":%s 334 %s :%s"
#define NUMERIC_STR_338 ":%s 338 %s %s %s :actually using host"
#define NUMERIC_STR_341 ":%s 341 %s %s %s"
#define NUMERIC_STR_344 ":%s 344 %s %s %s!%s@%s %s %lu"
#define NUMERIC_STR_345 ":%s 345 %s %s :End of Channel Quiet List"
#define NUMERIC_STR_346 ":%s 346 %s %s %s!%s@%s %s %lu"
#define NUMERIC_STR_347 ":%s 347 %s %s :End of Channel Invite List"
#define NUMERIC_STR_348 ":%s 348 %s %s %s!%s@%s %s %lu"
#define NUMERIC_STR_349 ":%s 349 %s %s :End of Channel Exception List"
#define NUMERIC_STR_351 ":%s 351 %s %s(%s). %s :%s%s"
#define NUMERIC_STR_352 ":%s 352 %s %s %s %s %s %s %s :%d %s"
#define NUMERIC_STR_353 ":%s 353 %s %s %s :"
#define NUMERIC_STR_362 ":%s 362 %s %s :Closed. Status = %d"
#define NUMERIC_STR_363 ":%s 363 %s %d: Connections Closed"
#define NUMERIC_STR_364 ":%s 364 %s %s %s :%d %s"
#define NUMERIC_STR_365 ":%s 365 %s %s :End of /LINKS list."
#define NUMERIC_STR_366 ":%s 366 %s %s :End of /NAMES list."
#define NUMERIC_STR_367 ":%s 367 %s %s %s!%s@%s %s %lu"
#define NUMERIC_STR_368 ":%s 368 %s %s :End of Channel Ban List"
#define NUMERIC_STR_369 ":%s 369 %s %s :End of WHOWAS"
#define NUMERIC_STR_371 ":%s 371 %s :%s"
#define NUMERIC_STR_372 ":%s 372 %s :- %s"
#define NUMERIC_STR_373 ":%s 373 %s :Server INFO"
#define NUMERIC_STR_374 ":%s 374 %s :End of /INFO list."
#define NUMERIC_STR_375 ":%s 375 %s :- %s Message of the Day - "
#define NUMERIC_STR_376 ":%s 376 %s :End of /MOTD command."
#define NUMERIC_STR_381 ":%s 381 %s :You have entered... the Twilight Zone!"
#define NUMERIC_STR_382 ":%s 382 %s %s :Rehashing"
#define NUMERIC_STR_386 ":%s 386 %s :%s"
#define NUMERIC_STR_391 ":%s 391 %s %s :%s"
#define NUMERIC_STR_396 ":%s 396 %s %s :is now your hidden host"
#define NUMERIC_STR_401 ":%s 401 %s %s :No such nick/channel"
#define NUMERIC_STR_402 ":%s 402 %s %s :No such server"
#define NUMERIC_STR_403 ":%s 403 %s %s :No such channel"
#define NUMERIC_STR_404 ":%s 404 %s %s :Cannot send to channel"
#define NUMERIC_STR_405 ":%s 405 %s %s :You have joined too many channels"
#define NUMERIC_STR_406 ":%s 406 %s %s :There was no such nickname"
#define NUMERIC_STR_407 ":%s 407 %s %s :Too many recipients. Only %d processed"
#define NUMERIC_STR_409 ":%s 409 %s :No origin specified"
#define NUMERIC_STR_410 ":%s 410 %s %s :Invalid CAP subcommand"
#define NUMERIC_STR_411 ":%s 411 %s :No recipient given (%s)"
#define NUMERIC_STR_412 ":%s 412 %s :No text to send"
#define NUMERIC_STR_413 ":%s 413 %s %s :No toplevel domain specified"
#define NUMERIC_STR_414 ":%s 414 %s %s :Wildcard in toplevel Domain"
#define NUMERIC_STR_415 ":%s 415 %s %s :Cannot send to channel (You are not registered and verified.  '/msg NickServ help' to learn how to register and verify)"
#define NUMERIC_STR_421 ":%s 421 %s %s :Unknown command"
#define NUMERIC_STR_422 ":%s 422 %s :MOTD File is missing"
#define NUMERIC_STR_423 ":%s 423 %s %s :No administrative info available"
#define NUMERIC_STR_431 ":%s 431 %s :No nickname given"
#define NUMERIC_STR_432 ":%s 432 %s %s :Erroneous Nickname"
#define NUMERIC_STR_433 ":%s 433 %s %s :Nickname is already in use."
#define NUMERIC_STR_434 ":%s 434 %s %s :You may not change nickname while banned or moderated on a channel (+b/+q/+m)"
#define NUMERIC_STR_436 ":%s 436 %s %s :Nickname collision KILL"
#define NUMERIC_STR_437 ":%s 437 %s %s :Nick/channel is temporarily unavailable"
#define NUMERIC_STR_438 ":%s 438 %s %s %s :Nick change too fast. Please wait %d seconds."
#define NUMERIC_STR_440 ":%s 440 %s :Services is currently down."
#define NUMERIC_STR_441 ":%s 441 %s %s %s :They aren't on that channel"
#define NUMERIC_STR_442 ":%s 442 %s %s :You're not on that channel"
#define NUMERIC_STR_443 ":%s 443 %s %s %s :is already on channel"
#define NUMERIC_STR_451 ":%s 451 %s :You have not registered"
#define NUMERIC_STR_456 ":%s 456 %s :Accept list is full"
#define NUMERIC_STR_457 ":%s 457 %s %s :is already on your accept list"
#define NUMERIC_STR_458 ":%s 458 %s %s :is not on your accept list"
#define NUMERIC_STR_461 ":%s 461 %s %s :Not enough parameters"
#define NUMERIC_STR_462 ":%s 462 %s :You may not reregister"
#define NUMERIC_STR_464 ":%s 464 %s :Password Incorrect"
#define NUMERIC_STR_465 ":%s 465 %s :You are banned from this server- %s"
#define NUMERIC_STR_471 ":%s 471 %s %s :Cannot join channel (+l)"
#define NUMERIC_STR_472 ":%s 472 %s %c :is unknown mode char to me"
#define NUMERIC_STR_473 ":%s 473 %s %s :Cannot join channel (+i)"
#define NUMERIC_STR_474 ":%s 474 %s %s :Cannot join channel (+b)"
#define NUMERIC_STR_475 ":%s 475 %s %s :Cannot join channel (+k)"
#define NUMERIC_STR_477 ":%s 477 %s %s :Cannot join channel (Need to be identified and verified to join this channel, '/msg NickServ help' to learn how to register and verify.)"
#define NUMERIC_STR_478 ":%s 478 %s %s %s :Channel ban list is full"
#define NUMERIC_STR_479 ":%s 479 %s %s :Illegal channel name"
#define NUMERIC_STR_480 ":%s 480 %s %s :You must connect via SSL to join this channel (+S)"
#define NUMERIC_STR_481 ":%s 481 %s :Permission Denied - You're not an IRC operator"
#define NUMERIC_STR_482 ":%s 482 %s %s :You're not channel operator"
#define NUMERIC_STR_483 ":%s 483 %s :You can't kill a server!"
#define NUMERIC_STR_484 ":%s 484 %s :You are restricted"
#define NUMERIC_STR_491 ":%s 491 %s :Only few of mere mortals may try to enter the twilight zone"
#define NUMERIC_STR_501 ":%s 501 %s :Unknown MODE flag"
#define NUMERIC_STR_502 ":%s 502 %s :Can't change mode for other users"
#define NUMERIC_STR_503 ":%s 503 %s :Message could not be delivered to %s"
#define NUMERIC_STR_504 ":%s 504 %s %s :User is not on this server"
#define NUMERIC_STR_513 ":%s 513 %s :To connect type /QUOTE PONG %lu"
#define NUMERIC_STR_521 ":%s 521 %s :Bad list syntax, type /QUOTE HELP LIST"
#define NUMERIC_STR_522 ":%s 522 %s :/WHO Syntax incorrect, use /who ? for help"
#define NUMERIC_STR_523 ":%s 523 %s %d :WHO search limit exceeded."
#define NUMERIC_STR_524 ":%s 524 %s %s :Help not found"
#define NUMERIC_STR_702 ":%s 702 %s %s %p %s %s"
#define NUMERIC_STR_703 ":%s 703 %s :End of /MODLIST."
#define NUMERIC_STR_704 ":%s 704 %s %s :%s"
#define NUMERIC_STR_705 ":%s 705 %s %s :%s"
#define NUMERIC_STR_706 ":%s 706 %s %s :End of /HELP."
#define NUMERIC_STR_710 ":%s 710 %s %s %s!%s@%s :has asked for an invite."
#define NUMERIC_STR_711 ":%s 711 %s %s :Your KNOCK has been delivered."
#define NUMERIC_STR_712 ":%s 712 %s %s :Too many KNOCKs (%s)."
#define NUMERIC_STR_713 ":%s 713 %s %s :Channel is open."
#define NUMERIC_STR_714 ":%s 714 %s %s :You are already on that channel."
#define NUMERIC_STR_715 ":%s 715 %s :KNOCKs are disabled."
#define NUMERIC_STR_716 ":%s 716 %s %s :is in +g mode (server side ignore)"
#define NUMERIC_STR_717 ":%s 717 %s %s :has been informed that you messaged or invited them."
#define NUMERIC_STR_718 ":%s 718 %s %s :is messaging or inviting you, and you are umode +g, +j, or +G."
#define NUMERIC_STR_720 ":%s 720 %s :Start of OPER MOTD for server %s."
#define NUMERIC_STR_721 ":%s 721 %s :%s"
#define NUMERIC_STR_722 ":%s 722 %s :End of OPER MOTD."
#define NUMERIC_STR_723 ":%s 723 %s %s :Insufficient oper privs."
#define NUMERIC_STR_724 ":%s 724 %s %s@%s %d %d :Local/remote clients match."
#define NUMERIC_STR_725 ":%s 725 %s %c %ld %s :%s | %s"
#define NUMERIC_STR_726 ":%s 726 %s %s :No matches"
#define NUMERIC_STR_727 ":%s 727 %s %s :Is Captured."
#define NUMERIC_STR_728 ":%s 728 %s %s :Is UnCaptured."

#endif /* INCLUDED_numeric_h */
