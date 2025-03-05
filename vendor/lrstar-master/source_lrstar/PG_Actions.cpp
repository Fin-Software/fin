
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
      #include "PG_Actions.h"
		#include "PG_Parser.h"

		int PG_Actions::head_col;
		int PG_Actions::arrow_col;
		int PG_Actions::colon_col;
		int PG_Actions::n_terms;

///////////////////////////////////////////////////////////////////////////////

void	PG_Actions::init_actions ()
{
	/* Initialization code goes here */
	   int sti;

		char* p = "<error>";
		sti = add_symbol (p, p+7, LEXICAL, 0);		// Add ERROR symbol.
		symbol[sti].type = TERMINAL;
		symbol[sti].numb = 0;

		char* q = "<eof>";
		sti = add_symbol (q, q+5, EOFLITERAL, 0);	// Add EOF symbol.
		symbol[sti].type = TERMINAL;
		symbol[sti].numb = 1;

		n_terms  = 2;
		n_errors = 0;
		t_error  = 0;
		goal_symbol = 0;								// Not encountered yet.
}

///////////////////////////////////////////////////////////////////////////////

void	PG_Actions::term_actions ()
{
	/* Termination code goes here */
}

