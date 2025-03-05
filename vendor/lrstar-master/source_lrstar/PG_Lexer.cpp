
/* Copyright 2018 Paul B Mann.  BSD License. */

#include "PG_Lexer.h"
#include "PG_Main.h"
#include "PG_Lexer.h"
#include "PG_LexerTables.hpp"

Token   PG_Lexer::token;				// Token.
int     PG_Lexer::tab;				   // Tab setting for the input file.
int     PG_Lexer::line_numb;		   // Line number of token.
int     PG_Lexer::col_numb;			// Column number of token.
int	  PG_Lexer::line_pos;
char*   PG_Lexer::line_start;		   // Line start pointer.
int     PG_Lexer::line_start_numb;	// Line number associated with line_start.
int     PG_Lexer::linenumb_printed;
FILE*   PG_Lexer::output;

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Lexer::init_lexer (char* input_start)
{
		line_numb			 = 1;
		col_numb           = 0;
		line_pos				 = 1;
		tab					 = 3;
		token.end          = input_start;
		line_start			 = input_start;
		line_ptr[1]			 = input_start;
		line_start_numb	 = 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Lexer::get_token ()			// Medium size lexer.
{
		int x, y;							// State, next state.
		do
		{
			x = 0;
			token.start = token.end;
		  	token.line  = line_numb;
			token.col   = col_numb + 1;
			token.pos   = line_pos;

			while ((y = Tm[Tr[x] + Tc[*(uchar*)token.end]]) > 0)
			{
				x = y;
			  	if (*token.end == '\n')
				{
					line_numb++;
					col_numb = 0;
					line_pos = 1;
					line_ptr[line_numb] = ++token.end;
				/*	#ifdef _DEBUG
					prt_line();
					#endif  */
				}
				else if (*token.end == '\t')
				{
					col_numb += 3 - (col_numb % 3);	// Increment column.
					token.end++;							// Increment Token pointer.
				}
				else
				{
					col_numb++;							// Increment column.
					token.end++;							// Increment Token pointer.
				}
			}
		}
		while (term_numb[x] < 0);	// Ignore whitespace.
		line_pos++;
		return term_numb[x];			// Return token_number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PG_Lexer::prt_line() // Print current line.
{
		if (line_numb > linenumb_printed)
		{
			if (line_numb == 1)
			{
				printf  (        "\n");
			//	fprintf (output, "\nInput File ...\n\n");
			}
			char* str;
			char* ls = token.end+1;
			linenumb_printed = line_numb;
			if (*ls != 26) // Not end of file?
			{
				str = untabify (ls);
				printf  (        "%6d  %s\n", line_numb, str);
			//	fprintf (output, "%6d  %s\n", line_numb, str);
			}
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Lexer::get_nexttoken (char*& start, char*& end)	// Medium size lexer.
{
		int x, y;								// State, next state.
		do
		{
			x = 0;
			start = end;
			while ((y = Tm[Tr[x] + Tc[*(uchar*)end]]) > 0)
			{
				x = y;
				end++;
			}
		}
		while (term_numb[x] < 0);	// Ignore whitespace.
		return term_numb[x];			// Return token_number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Lexer::get_lookahead ()			// Medium size lexer.
{
	int x, y;							// State, next state.
	do
	{
		x = 0;
		token.start = token.end;
		token.line = line_numb;
		while ((y = Tm[Tr[x] + Tc[*(uchar*)token.end]]) > 0)
		{
			x = y;
			if (*token.end == '\n')
			{
				line_numb++;
			}
			token.end++;
		}
	} while (term_numb[x] < 0);	// Ignore whitespace.
	return term_numb[x];				// Return token_number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PG_Lexer::untabify (char* ls, char*& ts)
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
			if (s > stringend) break;
		}
		*s = 0;
		ts = string + (ts - ls) + incr;
		return string;
}

char*	PG_Lexer::untabify (char* ls) // Untabify this line.
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

/////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void  PG_Lexer::prt_line ()
{
      char line[256];
	  	if (line_start != NULL)
      {
			int len = 0;
         char* p = line_start;
         char* q = line;
		   while (*p != '\n')
         {
            if (*p == '\t') *q++ = ' ';
            else            *q++ = *p;
            p++;
				if (++len == 255) break;
         }
		   *q = 0;
		   prt_log ("%05d %s\n\n", line_start_numb, line);
		   line_start = NULL; // Disable printing line until PG_Lexer sees a '\n'
      }
}
*/
//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

