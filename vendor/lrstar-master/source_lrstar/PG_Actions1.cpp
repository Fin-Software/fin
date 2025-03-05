
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "PG_Actions.h"
		#include "PG_Parser.h"

#ifdef TERM_ACTIONS

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::error (int& t)
{
		if (token.end == token.start) // Illegal character?
		{
			token.end++;
		}
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::headsymbol (int& t)
{
		if (token.pos == 1) // Position on line is 1?
		{
			if (goal_symbol == 0) // Goal not defined?
			{
				char* start;
				char* end = token.end;
				int   tk = get_nexttoken (start, end);
				if (tk != ARROW && tk != COLON) goto Ret;	 // Declaration.
     			if (token.col <= 5)
				{
					goal_symbol = 1;
					head_col = token.col;
					t = GOALSYMBOL;		 // Change terminal to {goalsymbol}
					int sti = lookup (t); // Make symbol.term a {goalsymbol}
					return sti;
				}
				else
				{
					syntax_error ("Error", &token, term_symb[t]);
					t = 0; // <error>
					char ch = *token.end;
					*token.end = 0;
					printf("\n%s symbol is not in {headsymbol} position, columns 1 to 5.\n\n", token.start);
					*token.end = ch;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}
			}
			else // Goal already defined.
			{
				if (token.col <= 5) // Head symbol position?
				{
					if (colon_col != 0) goto Ret;			 // ':' already seen, don't care about head position.
				  	if (arrow_col != 0 && token.col > arrow_col) goto Ret; // Not a head symbol.
					head_col = token.col;
					int sti = lookup (t); // If new, make symbol.term an <alpha>
					if (t != GOALSYMBOL)  // Make sure it's not {goalsymbol}
						t = HEADSYMBOL;	 // Change terminal to {headsymbol}
					return sti;
				}
				if (arrow_col != 0 && token.col < arrow_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					t = 0;
					char ch = *token.end;
					*token.end = 0;
					printf ("\nSymbol %s is left of previous '->', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}
			/*	if (colon_col != 0 && token.col < colon_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					t = 0;
					char ch = *token.end;
					*token.end = 0;
					printf ("\nSymbol %s is left of previous ':', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}	*/
			}
		}
Ret:	return lookup (t);
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::position (int& t)
{
		if (token.pos == 1) // Position on line is 1?
		{
			if (goal_symbol == 0) // Goal not defined?
			{
				return 0; // No sti.
			}
			else // Goal already defined.
			{
				if (arrow_col != 0 && token.col < arrow_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					t = 0;
					char ch = *token.end;
					*token.end = 0;
					printf("\nSymbol %s is left of previous '->', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}
			/*	if (colon_col != 0 && token.col < colon_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					t = 0;
					char ch = *token.end;
					*token.end = 0;
					printf("\nSymbol %s is left of previous ':', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}	*/
			}
		}
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::semi (int& t)
{
		if (goal_symbol == 0) // Goal not defined?
		{
			return 0; // No sti.
		}
		else // Goal already defined.
		{
		/*	if (token.pos > 1)
			{
				syntax_error ("Error", &token, term_symb[t]);
				printf ("\n%s is out of place, part of a rule.\n\n", term_symb[t]);
				n_errors++;
				t_error = POSITION;
				t = 0;
				return 0;
			}	*/
		/*	if (token.col < head_col)
			{
				syntax_error ("Error", &token, term_symb[t]);
				printf ("\n%s is out of place, too far left.\n\n", term_symb[t]);
				n_errors++;
				t_error = POSITION;
				t = 0;
				return 0;
			}	*/
		}
		colon_col = 0; // Disable YACC style, next could be a '->'.
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::arrow (int& t)
{
		if (token.pos > 2)
		{
			syntax_error ("Error", &token, term_symb[t]);
			printf ("\n%s is out of place, inside a rule.\n\n", term_symb[t]);
			n_errors++;
			t_error = POSITION;
			t = 0;
			return 0;
		}
		if (token.col < head_col)
		{
			syntax_error ("Error", &token, term_symb[t]);
			printf ("\n%s is out of place, too far left.\n\n", term_symb[t]);
			n_errors++;
			t_error = POSITION;
			t = 0;
			return 0;
		}
		arrow_col = token.col;
		colon_col = 0;
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::colon (int& t)
{
		if (token.pos > 2)
		{
			syntax_error ("Error", &token, term_symb[t]);
			printf ("\n%s is out of place, inside a rule.\n\n", term_symb[t]);
			n_errors++;
			t_error = POSITION;
			t = 0;
			return 0;
		}
		if (token.col < head_col)
		{
			syntax_error ("Error", &token, term_symb[t]);
			printf ("\n%s is out of place, too far left.\n\n", term_symb[t]);
			n_errors++;
			t_error = POSITION;
			t = 0;
			return 0;
		}
		colon_col = token.col;
		arrow_col = 0;
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::bar (int& t)
{
	/*	if (token.col < colon_col)
		{
			syntax_error ("Error", &token, term_symb[t]);
			printf ("\n%s is out of place, left of previous ':'.\n\n", term_symb[t]);
			n_errors++;
			t_error = POSITION;
			t = 0;
			return 0;
		}	*/
		return -t;
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::poslookup (int& t)	// Lookup in symbol table.
{
		if (token.pos == 1) // Position on line is 1?
		{
			if (goal_symbol == 1) // Goal defined?
			{
				if (arrow_col != 0 && token.col < arrow_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					char ch = *token.end;
					*token.end = 0;
					printf ("\nSymbol %s is left of previous '->', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					t = 0;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}
			/*	if (colon_col != 0 && token.col < colon_col)
				{
					syntax_error ("Error", &token, term_symb[t]);
					char ch = *token.end;
					*token.end = 0;
					printf ("\nSymbol %s is left of previous ':', but not a {headsymbol}\n\n", token.start);
					*token.end = ch;
					t = 0;
					n_errors++;
					t_error = POSITION;
					return 0; // No sti.
				}	*/
			}
		}
		return lookup (t);	// Symbol-table index.
}

///////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::lookup (int& t)	// Lookup in symbol table.
{
		int sti;																		// Symbol-table index.
		sti = add_symbol (token.start, token.end, t, token.line);	// Add to symbol table.
		return sti;																	// Return symbol-table index.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   TERM_ACTIONS::code_reader (int& t)
{
		if (goal_symbol == 1) // Already defined, after operator precedence.
		{
			int level = 0;
			for (char* p = token.end;; p++)
			{
				switch (*p)
				{
					case '\'':  // literal ?
					{
Loop1:				p++;
						while (*p != '\'' && *p != '\\' && *p != '\n' && *p != 26) p++;
						switch (*p)
						{
							case '\'': break;
							case '\\': goto Loop1;
							case '\n': goto Err1;
						}
						break;
					}
					case '\"':  // string ?
					{
Loop2:				p++;
						while (*p != '\"' && *p != '\\' && *p != '\n' && *p != 26) p++;
						switch (*p)
						{
							case '\"': break;
							case '\\': goto Loop2;
							case '\n': goto Err2;
						}
						break;
					}
					case '\n':  // end of line ?
					{
						line_numb++;
						break;
					}
					case 26:    // end of file ?
					{
						goto Err3;
					}
					case '{': // opening brace ?
					{
						level++;
						break;
					}
					case '}': // closing brace ?
					{
						if (level == 0)
						{
							token.end = p + 1;
							t = -1;   // make t negative to bypass this.
							return 0; // sti of blank.
						}
						level--;
						break;
					}
				}
			}
		}
		return -t; // '{'

Err1: printf ("\nEnd of line found, when expecting single quote.\n\n");
		t = 0; // <error>
		n_errors++;
		t_error = POSITION;
		return 0;

Err2: printf ("\nEnd of line found, when expecting double quote.\n\n");
		t = 0; // <error>
		n_errors++;
		t_error = POSITION;
		return 0;

Err3: printf ("\nEnd of file found, when expecting closing brace }.\n\n");
		t = 0; // <error>
		n_errors++;
		t_error = POSITION;
		return 0;
}

#endif
