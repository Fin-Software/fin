
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    DFA Lexer Code

		#include "main.h"

		Token   LEXER::token;				// Token.
		Token   LEXER::lookahead;			// Token.
		int     LEXER::linenumb;			// Line number of token.
		int     LEXER::lookahead_linenumb;	// Line number of token.
		int     LEXER::linenumb_printed;	// Line number printed already.
		int     LEXER::tab;					// Tab setting for the input file.

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  LEXER::init_lexer (char* input_start, int tab_setting)
{
		linenumb				= 0;
		linenumb_printed	= 0;
		tab					= tab_setting; // Tab.
		token.start       = input_start;	// Point at beginning of first line.
		token.end         = input_start;	// Point at beginning of first line.
		lookahead.start   = 0;				// Not activated.
		lookahead.end     = 0;				// Not activated.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   LEXER::get_token ()				// Medium size lexer.
{
		int x, y;							// State, next state.
		do
		{
			x = 0;
			token.start = token.end;
			token.line  = linenumb;
			while ((y = Tm[Tr[x] + Tc[*(uchar*)token.end]]) > 0)
			{
				x = y;
			  	if (*token.end == '\n')
				{
					linenumb++;
					#ifdef DEBUG_LEXER
					prt_line();
					#endif
				}
				token.end++;
			}
		}
		while (term_numb[x] < 0);	// Ignore whitespace.
		return term_numb[x];			// Return token_number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   LEXER::get_lookahead ()			// Medium size lexer.
{
		int x, y;							// State, next state.
		do
		{
			x = 0;
			lookahead.start = lookahead.end;
			lookahead.line  = lookahead_linenumb;
			while ((y = Tm[Tr[x] + Tc[*(uchar*)lookahead.end]]) > 0)
			{
				x = y;
			  	if (*lookahead.end == '\n')
				{
					lookahead_linenumb++;
				}
				lookahead.end++;
			}
		}
		while (term_numb[x] < 0);	// Ignore whitespace.
		return term_numb[x];			// Return token_number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* LEXER::untabify (char* ls, char*& ts)
{
	// ls = line start.
	// ts = token start within this line.;
		static char string[256];
		char* stringend = string + 250;
		char* p;
		char* s;
		int   ns;
		int   col = 0;
		int   incr = 0;
		for (p = ls, s = string; *p != '\n'; p++)
		{
			if (*p == '\t')				 // col = 0 1 2 3 4 5
			{									 // ns  = 3	2 1 3	2 1
				ns = 3 - (col % 3);
				switch (ns)
				{
					case 3:
						*s++ = ' ';
						if (p < ts) incr++;
					case 2:
						*s++ = ' ';
						if (p < ts) incr++;
					case 1:
						*s++ = ' ';
				}
				col += ns;
			}
			else
			{
				*s++ = *p;
				col++;
			}
			if (s > stringend)
				goto Over;
		}
		*s = 0;
		ts = string + (ts - ls) + incr;
		return string;

Over:	*s = 0;
		ts = s;
		return string;
}

#ifdef DEBUG_LEXER
/////////////////////////////////////////////////////////////////////////////////////////////////////

void	LEXER::prt_line() // Print current line.
{
		if (linenumb > linenumb_printed)
		{
			if (linenumb == 1)
			{
				printf  (        "\n");
				fprintf (output, "\nInput File ...\n\n");
			}
			char* str;
			char* ls = token.end+1;
			linenumb_printed = linenumb;
			if (*ls != 26) // Not end of file?
			{
				str = untabify (ls);
				printf  (        "%6d  %s\n", linenumb, str);
				fprintf (output, "%6d  %s\n", linenumb, str);
			}
		}
}

char*	LEXER::untabify (char* ls) // Untabify this line.
{
		int ns;
		int col;
		char* p;
		char* s;
		static char string [256];
		char*  stringend = string + 250;
		col = 0;
		for (p = ls, s = string; *p != '\n'; p++)
		{
			if (*p == '\t')				 // col = 0 1 2 3 4 5
			{									 // ns  = 3	2 1 3	2 1
				ns = 3 - (col % 3);
				switch (ns)
				{
					case 3: *s++ = ' ';
					case 2: *s++ = ' ';
					case 1: *s++ = ' ';
				}
				col += ns;
			}
			else
			{
				*s++ = *p;
				col++;
			}
			if (s > stringend) break;
		}
		*s = 0;
		return string;
}

#endif

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

