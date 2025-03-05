
/* Copyright 2018 Paul B Mann.  BSD License. */

#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LG_Parser.h

		#include "LG_Lexer.h"
		#include "LG_ParserTables.h"

      class LG_Parser : public LG_Lexer, public LG_ParserTables
		{
		   public:
		// Functions ...
			static void     initialize   (int);
			static int      Parse        ();
			static int      ParseInit    ();
			static int      parse        ();
			static void     terminate    ();
			static void     syntax_error (int);

		// Variables ...
         static PStack*  PS;           	      // Parse Stack pointer.
         static PStack*  PS_end;        	      // Parse Stack end.

			static char     pact_arg[];		      // Parse-action argument index (for first arg).
			static char     nact_arg[];		      // Node-action argument index (for first arg).
			static uchar    arg_numb[];		      // Argument numbers.
			static char*    arg_text[];		      // Argument text (for string arguments).
	      static uchar    f_prod[];
		   static uchar    f_tail[];

			static char*    T_start;
			static char*    T_end;
			static int      T_line;

		   private:
		// Functions ...
			static int      nd_parse      (int*, int*, int*, int x, int t, int a);
			static int      apply         (int p);
			static int      linkup			(int p);
			static void     rebuild		   ();
			static short    err_rec		   (short, short);
			static short    lookahead		(short t, short x);
			static void     get_list		(short);
			static void     prt_token		(short);
			static void     prt_prod		(short);
			static void     prt_stack		();
			static void     expecting		();
			static int      restore       ();
			static void	    collect		   (int x);
			static void	    reduce			(int p, int x);
			static void     prt_list      (int t);
			static char*    prt_line      (char* ls, int ln);
			static void	    prt_pointer   (char* ls, int ln, char* token);

		// Variables ...
			static int      max_errs;				   // Maximum allowable errors.
         static RStack*  RS;           		   // Reduction Stack pointer.
			static char*    T_list;					   // Terminal symbol list (0 or 1).
			static char*    H_list;					   // Head symbol list (0 or 1).
			static int*     P_list;					   // Production list.
         static RStack   R_stack[];				   // Reduction stack.
         static PStack   P_stack[];				   // Parser stack.
			static PStack*  PStop;				      // Top pointer for Parser stack.
         static int      state;
			static int      top_state;				   // Top state (before reductions start).
  		   static PStack*  top_ptr;
		};


