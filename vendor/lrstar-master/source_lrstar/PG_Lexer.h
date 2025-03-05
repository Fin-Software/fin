
/* Copyright 2018 Paul B Mann.  BSD License. */

#pragma once

#include "stdio.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    PG_Lexer.h

		class Token
		{
			public:
			char* start;	   // Start of symbol.
			char* end;		   // End of symbol.
			short pos;			// Symbol table index.
			int   sti;			// Symbol table index.
			int   line;	      // Input line number.
			int   col;			// Input column number.
		};

		class PG_Lexer
		{
			public:
         static Token  token;
			static int    tab;
			static int    line_numb;
			static int    col_numb;
			static int    line_pos;
			static char*  line_start;
			static int    line_start_numb;
			static int    linenumb_printed;
			static FILE*  output;

			static void   init_lexer (char*);
			static int    get_token ();
			static int    get_nexttoken (char*&, char*&);
			static int    get_lookahead ();
			static void   prt_line ();
			static char*  untabify (char* ls);
			static char*  untabify (char* ls, char*& ts);

		};

