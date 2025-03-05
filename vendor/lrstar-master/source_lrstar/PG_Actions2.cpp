
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
      #include "PG_Actions.h"
		#include "PG_Parser.h"

#ifdef PARSE_ACTIONS

      static int nodename_sti;
		int   PG_ParseActions::STI;
		int   PG_ParseActions::production_length;
      char* PG_ParseActions::restart;

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::goalsymbol_ (int p)  // LR goal symbol.
{
		goal_symbol = 1;
		N_prods = 0;
		int x = argx[p];
		int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|ARGUMENT|CONSTANT, PS[x].line);
		if (symbol[sti].type & TERMINAL)    // Already a terminal?
		{
			prt_error ("Symbol '%s' has already been defined as a terminal", PS[x].start, PS[x].end, PS[x].line);
		}
		else if (symbol[sti].type & CONSTANT)    // Already a constant?
		{
			prt_error ("Symbol '%s' has already been defined as a constant", PS[x].start, PS[x].end, PS[x].line);
		}
      else
      {
   		symbol[sti].value = -1;
      }
		symbol[sti].type |= NONTERMINAL; // Make it a nonterminal.
		symbol[sti].numb  = N_heads++;   // Increment nonterminal counter.
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::defcon_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, CONSTANT|ARGUMENT|TERMINAL, PS[x].line);
      if (symbol[sti].numb >= 0) // Already defined?
      {
			if (symbol[sti].type & CONSTANT)
         {
				prt_error ("Constant symbol '%s' has already been defined", PS[x].start, PS[x].end, PS[x].line);
         }
			else if (symbol[sti].type & TERMINAL)
         {
				prt_error ("Symbol '%s' has already been defined as a terminal", PS[x].start, PS[x].end, PS[x].line);
         }
      }
      else
      {
         symbol[sti].type |= CONSTANT;
         symbol[sti].numb  = n_constants++;  // Increment terminal counter.
      }
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::terminal_decl_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti;
		if (sti >= 0)
		{
			int stiterm = PS[x+1].sti;	   // Get sti of terminal symbol.
			symbol[sti].value = stiterm;	// Set value of <alpha> to sti of terminal.
			symbol[sti].type |= TERMINAL;	// Add type of TERMINAL.
			symbol[stiterm].value = sti;	// Set value of terminal to sti of defined constant.
		}
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::terminal_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|ARGUMENT|CONSTANT, PS[x].line);
      if (symbol[sti].numb >= 0) // Already a declared or defined?
      {
			if (symbol[sti].type & CONSTANT)
			{
				prt_error ("'%s' has been defined as a constant and cannot be a terminal symbol", PS[x].start, PS[x].end, PS[x].line);
			}
			else if (symbol[sti].numb == 0)			// <error> symbol?
			{
				if (symbol[sti].line == 0)				// First declaration of <error>?
				{
					symbol[sti].line = PS[x].line;	// Give it the line number.
				}
				else goto Err;
			}
			else if (symbol[sti].numb == 1)			// <eof> symbol?
			{
				if (symbol[sti].line == 0)				// First declaration of <eof>?
				{
					symbol[sti].line = PS[x].line;	// Give it the line number.
				}
				else goto Err;
			}
			else
			{
Err:		  	prt_error ("'%s' has already been declared", PS[x].start, PS[x].end, PS[x].line);  // Removed by pbm 20140903.
			}
      }
      else
      {
         symbol[sti].type |= TERMINAL;		// Arguments could come here, have to use |=.
         symbol[sti].numb  = N_terms++;
         symbol[sti].value = -1;				// Undefined.
         n_declared++;
      }
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::oper_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|ARGUMENT|CONSTANT, PS[x].line);
      if (symbol[sti].numb < 0) // New terminal or argument?
      {
			symbol[sti].type |= TERMINAL|OPERATOR;
         symbol[sti].numb  = N_terms++;
         symbol[sti].value = -1;			// Undefined
      }
		else if (symbol[sti].type & CONSTANT)
		{
			PS[x].sti = symbol[sti].value; // Replace constant sti with the real terminal sti (e.g. '&&').
   		symbol[PS[x].sti].type |= TERMINAL|OPERATOR;
		}
		else if (symbol[sti].type & OPERATOR)
		{
			prt_error ("Symbol '%s' has already been defined as an operator", PS[x].start, PS[x].end, PS[x].line);
		}
		else // ARGUMENT or TERMINAL.
		{
			if (symbol[sti].value >= 0 && optn[PG_CONSTANTSUNUSED]) // Defined constant exists for this operator?
			{
				char buffer[256];
				int a = symbol[sti].value;
				sprintf (buffer, "Operator symbol %%s has a defined constant %s", symbol[a].name);
				prt_warning (buffer, PS[x].start, PS[x].end, PS[x].line);
			}
			symbol[sti].type |= TERMINAL|OPERATOR;
		}
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::bypass_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|TAIL|NONTERMINAL|ARGUMENT|CONSTANT, PS[x].line);
      symbol[sti].type |= NONTERMINAL; // Make it a nonterminal.
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::headsymbol_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|TAIL|NONTERMINAL|ARGUMENT|CONSTANT, PS[x].line);
   // printf ("-> headsymbol_ %s\n", symname(sti));
      if (symbol[sti].type & NONTERMINAL) // Already a nonterminal?
      {
			prt_error ("Nonterminal symbol '%s' has already been defined", PS[x].start, PS[x].end, PS[x].line);
      }
      else if (symbol[sti].type & TERMINAL)    // Already a terminal?
      {
			prt_error ("Symbol '%s' has already been defined as a terminal", PS[x].start, PS[x].end, PS[x].line);
      }
      else if (symbol[sti].type & CONSTANT)    // Already a constant?
      {
			prt_error ("Symbol '%s' has already been defined as a constant", PS[x].start, PS[x].end, PS[x].line);
      }
      else
      {
         symbol[sti].type |= NONTERMINAL; // Make it a nonterminal.
         symbol[sti].numb  = N_heads++;
         symbol[sti].value = -1;				// Undefined.
      }
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::priority_(int p)
{
		prod_(p);
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::prod_(int p)
{
		production_length = 0;
		nodename_sti = 0;
		N_prods++;
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::tail_expr_ (int p)
{
		production_length++;
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::tail_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|NONTERMINAL|TAIL|CONSTANT|ARGUMENT, PS[x].line);
      if (symbol[sti].type & CONSTANT)	 // Definded constant?
		{
			if (symbol[symbol[sti].value].numb == 1) // EOF CONSTANT ?
			{
				prt_error ("Constant %s is <eof> and not allowed outside the goal production", PS[x].start, PS[x].end, PS[x].line);
			}
			PS[x].sti = symbol[sti].value; // Replace defined constant sti with terminal sti.
			symbol[PS[x].sti].type |= TAIL;
			return 0;
		}
		else // Not a defined constant!
		{
		   if (symbol[sti].value >= 0 && optn[PG_CONSTANTSUNUSED]) // Defined constant exists for this tail?
			{
            char buffer[256];
            int a = symbol[sti].value;
            sprintf (buffer, "Terminal symbol %%s has a defined constant %s", symbol[a].name);
				prt_warning (buffer, PS[x].start, PS[x].end, PS[x].line);
         }
			symbol[sti].type |= TAIL;
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::tail_eof_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|NONTERMINAL|TAIL|CONSTANT|ARGUMENT, PS[x].line);
		if (symbol[sti].type & CONSTANT)	 // Definded constant?
		{
			if (symbol[symbol[sti].value].numb != 1) // Not <eof> ?
			{
				prt_error ("Expecting <eof>, but constant %s has not been defined as <eof>", PS[x].start, PS[x].end, PS[x].line);
				Quit();
			}
			PS[x].sti = symbol[sti].value; // Replace defined constant sti with terminal sti.
			symbol[PS[x].sti].type |= TAIL;
			return 0;
		}
		else // Not a defined constant and not <eof>
		{
		/*	if (strcmp (symbol[sti].name, "EOF") == 0)  // For ANTLR grammars.
			{
				symbol[sti].type |= CONSTANT|TAIL|TERMINAL;
				symbol[sti].numb  = n_constants++;
				PS[x].sti = symbol[sti].value = 2; // sti of <eof>
				symbol[2].type |= TAIL;
				symbol[2].value = sti;
			}
			else */
			{
				prt_error ("Expecting <eof>, but symbol %s has not been defined as <eof>", PS[x].start, PS[x].end, PS[x].line);
				symbol[sti].type |= TAIL;
				Quit();
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::sep_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|NONTERMINAL|TAIL|ARGUMENT|CONSTANT, PS[x].line);
      if (symbol[sti].numb == 0 && symbol[sti].type & NONTERMINAL) // Goal symbol?
      {
			prt_error ("Goal symbol '%s' cannot be used in grammar rules", PS[x].start, PS[x].end, PS[x].line);
      }
      else if (symbol[sti].type & CONSTANT)	// A constant?
      {
			PS[x].sti = symbol[sti].value;		// Replace constant sti with the real sti.
   		symbol[PS[x].sti].type |= TAIL;
      }
      else
      {
			if (symbol[sti].value >= 0 && optn[PG_CONSTANTSUNUSED]) // Defined constant exists for this tail?
			{
				char buffer[256];
				int a = symbol[sti].value;
				sprintf (buffer, "Separator symbol %%s has a defined constant %s", symbol[a].name);
				prt_warning (buffer, PS[x].start, PS[x].end, PS[x].line);
			}
			symbol[sti].type |= TAIL;
      }
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::ta_name_ (int p)
{
		int x, sti;
		if (optn[PG_TERMACTIONS])
		{
			x = argx[p];	// Token action name.
			sti = PS[x].sti = add_symbol(PS[x].start, PS[x].end, TACTION, PS[x].line);
			if (symbol[sti].numb < 0)
			{
				symbol[sti].type = TACTION;
				symbol[sti].numb = N_tacts++;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::node_name_ (int p)
{
		int x, sti;
		x = argx[p];
		sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, NODENAME, PS[x].line);
		if (symbol[sti].numb < 0) // New name.
		{
			symbol[sti].type = NODENAME;
			symbol[sti].numb = N_nodes++;
		}
		if (symbol[sti].type & TACTION)
		{
			prt_error("Node name cannot be the same as a terminal action", symbol[sti].name, 0, line_numb);
			Quit();
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::node_action_ (int p)
{
		int x, sti;
		x = argx[p];
		sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, NACTION|NODENAME, PS[x].line);
		if (symbol[sti].numb < 0) // New name.
		{
			symbol[sti].numb = N_nodes++;
		}
		symbol[sti].type |= NACTION|NODENAME;
		if (symbol[sti].type & TACTION)
		{
			prt_error("Node action cannot be the same as a terminal action", symbol[sti].name, 0, line_numb);
			Quit();
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::args_ (int p)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_first_ (int p)
{
		if (symbol[STI].type & INTEGER)		// Current arg is an integer?
		{
			if (production_length > 0)
			{
				if (symbol[STI].value > production_length || symbol[STI].value < 1)
				{
					char string[132];
					sprintf (string, "First argument is outside of range: 1-%d", production_length);
					prt_error(string, symbol[STI].name, 0, line_numb);
					Quit ();
				}
				else // Within range.
				{
					// Cannot check for nonterminal position until AST is finished.
				}
			}
			else // Empty rule.
			{
				if (symbol[STI].value >= 0)
				{
					prt_error ("First argument is not allowed on empty rule", symbol[STI].name, 0, line_numb);
					Quit ();
				}
			}
		}
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_semantic_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|NONTERMINAL|TAIL|ARGUMENT|CONSTANT, PS[x].line);
		symbol[sti].type |= ARGUMENT;
		if (symbol[sti].type & CONSTANT)
		{
			int sti2 = symbol[sti].value; // Get sti from CONSTANT value.
			symbol[sti2].type |= ARGUMENT;
			if (symbol[sti2].name[0] != '{')
			{
				prt_error ("Second argument is not defined as a {semantic} symbol", symbol[sti].name, 0, line_numb);
				Quit ();
			}
			N_args++;
			STI = sti;
			return 0;
		}
		prt_error ("Second argument is not a {semantic} symbol", symbol[sti].name, 0, line_numb);
		Quit ();
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_alpha_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|NONTERMINAL|TAIL|ARGUMENT|CONSTANT, PS[x].line);
		symbol[sti].type |= ARGUMENT;
		if (symbol[sti].type & CONSTANT)
		{
			sti = symbol[sti].value; // Get sti from CONSTANT value.
			symbol[sti].type |= ARGUMENT;
		}
		N_args++;
		STI = sti;
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_terminal_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, TERMINAL|ARGUMENT|TAIL, PS[x].line);
      symbol[sti].type |= ARGUMENT;
		if (symbol[sti].value >= 0 && optn[PG_CONSTANTSUNUSED]) // Defined constant exists for this tail?
		{
			char buffer[256];
			int a = symbol[sti].value;
			sprintf(buffer, "Argument %%s has a defined constant %s", symbol[a].name);
			prt_warning (buffer, PS[x].start, PS[x].end, PS[x].line);
		}
		N_args++;
		STI = sti;
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_integer_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, INTEGER|ARGUMENT, PS[x].line);
      if (symbol[sti].numb < 0) // New integer or old argument?
      {
         symbol[sti].type |= INTEGER|ARGUMENT;
         symbol[sti].numb  = N_ints++;
         symbol[sti].value = atoi (symbol[sti].name);
      }
      else // Old integer
		{
			symbol[sti].type |= ARGUMENT;
		}
      N_args++;
		STI = sti;
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ParseActions::arg_string_ (int p)
{
      int x = argx[p];
      int sti = PS[x].sti = add_symbol (PS[x].start, PS[x].end, STRING|ARGUMENT, PS[x].line);
      if (symbol[sti].numb < 0)
      {
         symbol[sti].type  = STRING|ARGUMENT;
         symbol[sti].numb  = N_strings++;
         symbol[sti].value = -1;
      }
      else // Old string
		{
			symbol[sti].type |= ARGUMENT;
		}
      N_args++;
		STI = sti;
      return 0;
}

#endif
