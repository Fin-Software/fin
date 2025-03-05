
/* Copyright 2018 Paul B Mann.  BSD License. */

#include "CM_Global.h"
#include "LG_Lexer.h"
#include "LG_LexerTables.hpp"

Token LG_Lexer::token;
int   LG_Lexer::line_numb;
int   LG_Lexer::line_pos;
int   LG_Lexer::max_char_set;
int   LG_Lexer::col_numb;
int   LG_Lexer::tab;
char* LG_Lexer::line_start;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    init                                                                   //

void  LG_Lexer::init_lexer () // General purpose lexer.
{
		int i;
		line_numb  = 1;
		col_numb   = 0;
		line_pos   = 0;
		line_start = input_start;
		token.end  = line_start;
  		line_ptr[line_numb] = input_start;
		tab = 3;
  		if (max_char_set == 128)
		{
			for (i = 128; i < 256; i++)
			{
				Tc[i] = Tc[0]; // Make higher characters an error.
			}
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    term                                                                   //

void  LG_Lexer::term_lexer () // General purpose lexer.
{
		/* Nothing */
}

/*--- DFA Lexer Engine. -----------------------------------------------------*/

int   LG_Lexer::get_token ()		// DFA LG_Lexer Engine.
{
      int state, next;		// State, next state, terminal, keyword.
		do
		{
			state = 0;									// Start in state zero.
			token.start = token.end;				// Set start of token.
			token.line  = line_numb;				// Set line number of token.
			token.column = col_numb + 1;			// Set column number.
       	while (next = Tm [Tr [state] + Tc [*token.end]])
			{
			   if (*token.end == '\n')				// If end-of-line character.
				{
					col_numb = 0;
					line_pos = 0;
					line_start = token.end + 1;	// Set beginning of next line.
				  	line_ptr [++line_numb] = line_start;
				}
			   else if (*token.end == '\t')				// If tab character.
				{
					col_numb += tab - (col_numb % tab);
				}
				else
				{
					col_numb++;							// Increment column.
				}
				token.end++;							// Increment token pointer.
				state = next;							// Set next state number.
			}
		}
      while (term_numb[state] == -1);			// If whitespace, continue.

		line_pos++;
      return term_numb[state];					// Return terminal number.
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int	LG_Lexer::get_lookahead (int& linenumber)
{
      char* TS   = token.start;
      char* TE   = token.end;
      int   TSTI = token.sti;
		int   TL   = token.line;
      int   TC   = token.column;
      int   LN   = line_numb;
      int   LC   = col_numb;
      int   LP   = line_pos;

      int   la = get_token();    // Get look ahead token.
		linenumber = token.line;	// Set line number of lookahead.

      token.start  = TS;         // Reset token start.
      token.end    = TE;         // Reset token end.
		token.sti    = TSTI;
      token.line   = TL;         // Reset token column.
      token.column = TC;         // Reset token column.
      line_numb    = LN;         // Reset line number.
      col_numb     = LC;         // Reset line column.
      line_pos     = LP;         // Reset line position.
		return (la);
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////
