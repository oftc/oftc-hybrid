/* A Bison parser, made from parser.y, by GNU bison 1.75.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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

#ifndef BISON_Y_TAB_H
# define BISON_Y_TAB_H

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     BYTES = 259,
     DAYS = 260,
     HOURS = 261,
     KBYTES = 262,
     MBYTES = 263,
     NUMBER = 264,
     IDENTIFIER = 265,
     MINUTES = 266,
     QSTRING = 267,
     SECONDS = 268,
     WEEKS = 269
   };
#endif
#define BOOL 258
#define BYTES 259
#define DAYS 260
#define HOURS 261
#define KBYTES 262
#define MBYTES 263
#define NUMBER 264
#define IDENTIFIER 265
#define MINUTES 266
#define QSTRING 267
#define SECONDS 268
#define WEEKS 269




#ifndef YYSTYPE
#line 53 "parser.y"
typedef union {
    int number;
    char *string;
    dlink_list *idlist;
} yystype;
/* Line 1281 of /usr/local/share/bison/yacc.c.  */
#line 74 "y.tab.h"
# define YYSTYPE yystype
#endif

extern YYSTYPE yylval;


#endif /* not BISON_Y_TAB_H */

