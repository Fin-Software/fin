
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		DFA Lexer Header

		#pragma once

		class Token
      {
         public:
         char*  start;		// Start of token.
			char*  end;			// End of token (character following token).
			int    sti;			// Symbol table index.
			int    line;		// Line number.
		};

////////////////////////////////////////////////////////////////////////////////////////////////////

      class LEXER
      {
         public:
         static Token	token;					// Token being read.
			static Token   lookahead;				// Lookahead being read.
			static int		tab;						// Tab setting in input file.
			static int		linenumb;				// Line number in input file.
			static int		linenumb_printed;		// Line number already printed.
			static int     lookahead_linenumb;  // Line number in input file.

			static void		init_lexer (char* input_start, int tab);
			static int		get_token ();
			static int		get_lookahead ();
			static void		prt_line ();
			static char*	untabify (char* ls);
			static char*	untabify (char* ls, char*& token);
		};

//
////////////////////////////////////////////////////////////////////////////////////////////////////
