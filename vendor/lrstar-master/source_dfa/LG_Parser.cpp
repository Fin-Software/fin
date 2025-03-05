
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "LG_Parser.h"
		#include "LG_ParserTables.hpp"

		#define STKSIZE 500

      int      LG_Parser::state;
  		int      LG_Parser::top_state;
  		PStack*  LG_Parser::top_ptr;

      PStack*  LG_Parser::PS;
      PStack   LG_Parser::P_stack[STKSIZE];

      RStack*	LG_Parser::RS;
      RStack	LG_Parser::R_stack[STKSIZE];

		char*    LG_Parser::T_list;
		char*    LG_Parser::H_list;
		int*     LG_Parser::P_list;

		char*    LG_Parser::T_start;
		char*    LG_Parser::T_end;
		int      LG_Parser::T_line;

		static char*	prt_line   (char* ls, int ln);

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    ParseInit

int   LG_Parser::ParseInit ()
{
      PS = P_stack;										// Set parse stack pointer.
      n_errors = 0;										// Set number of errors.
      RS = R_stack;										// Reset reduction stack pointer.
		top_ptr = PS;										// Save parse stack top pointer.
		top_state = 0;										// Save current state.
      state = 0;
      return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    term                                                                   //
/*
int   LG_Parser::term ()
{
		delete [] node;
      LGLexer::term();
      return (0);
}
*/
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Parse                                                                  //

int   LG_Parser::Parse ()                        // LR Parser.
{
      int t;												// Terminal.
      int p;												// Production.
      int x = state;	   								// State.
		init_lexer ();										// Initialize lexer.
		t = get_token ();									// Get token.
		if (t == 0) goto Err;							// Bad token!
		goto Cont;

Read: RS = R_stack;										// Reset reduction stack pointer.
		top_ptr = PS;										// Save parse stack top pointer.
		top_state = x;										// Save current state.
		t = get_token ();									// Get next token.
Cont:	if (tact_numb[t] >= 0)							// If input action ...
      {
			int t1 = t;
      // T_start = token.start;						// Set token start.
      // T_end   = token.end;							// Set token end.
         t = (*tact_func[tact_numb [t]]) (t);	// Call token action.
      }
    	/*	For debugging ...
			char ch = *token.end;
  			*token.end = 0;
			printf ("       %-20s %3d, %s\n", token.start, t, term_symb[t]);
  			*token.end = ch;
		*/
Shft: if (Bm [Br[x] + Bc[t]] & Bf[t])				// Accept this terminal symbol?
      {
         (++PS)->state = x;                     // Stack state.
         PS->start = token.start;					// Stack token start pointer.
         PS->end   = token.end;						// Stack token end pointer.
         PS->line  = token.line;						// Stack token line number.
         p = -Tm [Tr[x] + Tc[t]];					// Get reduction or next state.
         while (p >= 0)							      // While shift-reduce action.
         {
            PS -= PL[p];                        // Reduce parse stack pointer.
				if (apply (p) != 0) return (0);		// Apply reduction, quit parsing?
            p = -Nm [Nr[PS->state] + Nc[p]];		// Get reduction or next state.
         }
			x = -p;											// Set next state.
         goto Read;										// Go read next token.
      }
      if ((p = Rr[x]) > 0 || (p = Rm [Rc[t] - p]) > 0) // Get reduction?
      {
         if (PL[p] == -1)                       // Null production?
         {
     		   (++RS)->state = (++PS)->state;		// Save state before destroying it.
            PS->state  = x;							// Stack state.
				RS->ptr = PS;								// Save parse-stack pointer.
            PS->start  = NULL;					   // Clear start.
            PS->end    = NULL;					   // Clear end.
				goto Apply;
         }
         do
         {
            PS -= PL[p];                        // Reduce parse stack ptr by production length.
Apply:		if (apply (p) != 0) return (0);		// Apply reduction, quit parsing?
            p = -Nm [Nr[PS->state] + Nc[p]];		// Get reduction or next state.
         }
         while (p > 0);
         x = -p;											// Set new state.
         goto Shft;										// Try to shift from this new state.
      }

      if (x == accept_state)
      {
         PS -= PL[0];
         line_numb--;
			if (n_errors > 0) return (0);
         return (1);
      }

      if (strcmp (gft, ".lex") == 0 && t == T_EOF)
      {
         state = restore();
         return -1;
      }

//		Error ...
Err:  syntax_error (t);
		expecting ();
      return (0);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    apply                                                                  //

int   LG_Parser::apply (int p)
{
      int i, r;
      if (pact_numb[p] >= 0)				      // Call function?
      {
         i = argx [p];								// Get parse stack position.
			if (i >= 0)									// Valid parse stack position?
			{
				T_start = PS[i].start;           // Define T_start working pointer.
				T_end   = PS[i].end;             // Define T_end working pointer.
				T_line  = PS[i].line;            // Define T_line.
			}
			else											// Use last token accepted.
			{
				T_start = token.start;           // Define T_start working pointer.
				T_end   = token.end;             // Define T_end working pointer.
				T_line  = token.line;            // Define T_line.
			}
         r = (*pact_func [pact_numb[p]]) (p);   // Call production action.
			if (r != 0) return (r);
      }
      return (0);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  LG_Parser::syntax_error (int t)
{
      ushort ln;
      char *ls, *le, c;

		if (++n_errors == 1) prt_log ("\n");

		ls = line_start;
		ln = line_numb;
		if (*token.start == 26 || *ls == 26)  // At <eof> ?
		{
			do // Backup to last line start.
			{
				for (ls -= 2; *ls != '\n'; ls--);
				ls++;
				ln--;
			}
			while (token.start < ls);
		}
		else if (token.start < ls) // If token starts before current line start.
		{
			do
			{
				for (ls--; *ls != '\n'; ls--);
			}
			while (token.start < ls);
			ls++;
		}
		le = prt_line (ls, ln);
		prt_pointer (ls, ln, token.start);
      if (*token.start <= 32)
      {
         short x = *token.start;
         if (x < 0) x += 256;
         prt_log ("at (%d) %s\n", x,  term_symb[t]);
      }
      else
      {
         if (token.end == token.start) token.end++;
         if (token.end > le)
         {
            if (*token.end == 26) line_numb--;
            prt_log ("starts here\n");
				prt_line (line_start, line_numb);
				prt_pointer (line_start, line_numb, token.end);
				prt_log ("ends here.\n");
         }
         else
         {
            c = *token.end;
            *token.end = 0;
				int x = *(token.start+1);
				if (x < 0) x += 256;
            prt_log ("at %s (%d) %s\n", token.start, x, term_symb[t]);
            *token.end = c;
         }
      }
      prt_log ("%s(%04d) : Syntax error.\n\n", grmfid, line_numb);
}

char* LG_Parser::prt_line (char* ls, int ln)
{
		char *p;
	// Replace tabs with spaces.
      for (p = ls; *p != '\n'; p++)
      {
         if (*p == '\t') *p = ' ';
      }
	// Remove ending spaces.
      while (*(--p) == ' ');
      *(++p) = 0;
	// Print the line.
      prt_log ("%s(%04d) : %s\n", grmfid, ln, ls);
		*p = '\n';
		return (p);
}

void	LG_Parser::prt_pointer (char* ls, int ln, char* token)
{
      int  i = 0;
		char *p, string[10000];
      for (p = ls; p < token; p++)
      {
			string[i++] = '-';
			if (i == 9999) break;
      }
      string[i++] = 0;
      prt_log ("%s(%04d) : %s^ ", grmfid, ln, string);
}

////////////////////////////////////////////////////////////////////////////////
//

void  LG_Parser::expecting ()
{
		int t, x;

		ALLOC (T_list, n_terms);
		ALLOC (H_list, n_heads);
		ALLOC (P_list, n_prods);

		for (t = 0; t < n_terms; t++) T_list[t] = 0;

		prt_log ("Expecting one of the following:\n\n");

		x = restore ();
	  	collect (x);

		prt_log ("\n");

		free (P_list);
		free (H_list);
		free (T_list);
}

////////////////////////////////////////////////////////////////////////////////
//

int   LG_Parser::restore () // Restore parse stack.
{
		while (RS > R_stack) // For all null reductions.
		{
			(RS->ptr)->state = RS->state;	// Replace state with the saved one.
			RS--;
		}
		PS = top_ptr;
      return top_state;
}

////////////////////////////////////////////////////////////////////////////////
//

void	LG_Parser::collect (int x) // Collect terminals that cause a transition or reduction.
{
		int t, y, p, h, i, la, offset, n_red;
	//	printf ("Collecting terminals in state %d\n", x);
		for (h = 0; h < n_heads; h++) H_list[h] = -1;
     	for (t = 0; t < n_terms; t++)							// For all terminals.
		{
  			if (Bm [Br[x] + Bc[t]] & Bf[t])				// Accept this terminal?
			{
				if (T_list[t] == 0)
				{
					T_list[t] = 1;										// Mark it done, in case of SR conflict.
					y = Tm [Tr[x] + Tc[t]];							// Get action?
					if (y > 0)											// Shift & goto y action?
					{
			    		if ((p = Rr[y]) > 0)							// Default reduction in state y?
						{
							if (PL[p] == 0) H_list [head_numb[p]] = t;
						}
						else
						{
							offset = -p;
     						for (la = 0; la < n_terms; la++)			// For all lookaheads.
							{
								if ((p = Rm [Rc[la] + offset]) > 0)	// Got a reduction on this terminal?
								{
									if (PL[p] == 0) H_list [head_numb[p]] = t; // Yes t and not la.
								}
							}
						}
					}
					else 													// Shift & reduce action!
					{
						p = -y;											// Get production.
						if (PL[p] == 0) H_list [head_numb[p]] = t;
					}
               if (t == T_EOF) continue;
               if (term_symb[t][0] == '{') continue;
					prt_log ("\t%-32s", term_symb[t]);
					char first = 1;
					char blank[21] = "                    ";
/*					for (h = 0; h < n_heads; h++)
					{
						if (H_list[h] == t)
						{
							if (first)
							{
								prt_log (" => %s\n", head_symb[h]);
								first = 0;
							}
							else
							{
								prt_log ("\t%-32s => %s\n", blank, head_symb[h]);
							}
						}
					}
*/
					if (first)
					{
						prt_log ("\n");
					}
				}
			}
		}
    	if ((p = Rr[x]) > 0)										// Default reduction?
		{
			reduce (p, x);
		}
		else															// Reductions based on lookaheads!
		{
			n_red  = 0;
			offset = -p;
			for (la = 0; la < n_terms; la++)
			{
				if ((p = Rm [Rc[la] + offset]) > 0)			// Got a reduction on this terminal?
				{
			  		for (i = 0; i < n_red; i++)				// For all reductions in the list.
					{
						if (P_list[i] == p) break;				// Already in this list?
					}
					if (i == n_red) P_list [n_red++] = p;	// Add this production to list.
				}
			}
		  	for (i = 0; i < n_red; i++)
			{
				reduce (P_list[i], x);
			}
		}
}

////////////////////////////////////////////////////////////////////////////////
//

void	LG_Parser::reduce (int p, int x)			// Reduce production.
{
      if (PL[p] == -1)                       // Null production?
      {
			PS++;											// Increment stack pointer.
         PS->state = x;								// Stack state.
			goto Cont;
      }
		do
		{
			PS -= PL[p];								// Reduce parse stack pointer.
Cont:		p = -Nm [Nr[PS->state] + Nc[p]];		// Get reduction or next state.
		}
		while (p > 0);
		x = -p;											// Set new state.
		collect (x);									// Go collect terminals.
}

///// End of Parser ////////////////////////////////////////////////////////////




