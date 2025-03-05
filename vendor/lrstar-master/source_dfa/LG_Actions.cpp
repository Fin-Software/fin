
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "LG_Global.h"
      #include "LG_Actions.h"
		#include "LG_Global.h"

		char**  	LG_TermActions::Defcon_term;
		char**  	LG_TermActions::head_name;
		int*    	LG_TermActions::head_sym;
		int*    	LG_TermActions::head_line;
		int*    	LG_TermActions::term_line;
		int*    	LG_TermActions::prod_len;
		int*    	LG_TermActions::prod_line;
		int*    	LG_TermActions::nullable;
		int     	LG_TermActions::n_nulls;
		int     	LG_TermActions::n_constants;
		int     	LG_TermActions::N_prods;
		int     	LG_TermActions::n_prods;
		int     	LG_TermActions::N_tails;
		int     	LG_TermActions::n_tails;
		int     	LG_TermActions::amt_space;
		int*    	LG_TermActions::Tail;
      int*    	LG_TermActions::F_tail;
		char**  	LG_TermActions::term_name;
		int*    	LG_TermActions::term_type;

		char**   LG_TermActions::str_start;
		char**   LG_TermActions::code_start;
	   int*     LG_TermActions::Defcon_value;
		char**   LG_TermActions::Defcon_name;
	   int*		LG_TermActions::ret_value;
		char**   LG_TermActions::ret_name;
		char**   LG_TermActions::ret_term;
		int*     LG_TermActions::ret_numb;
		int*     LG_TermActions::prod_type;
		int    	LG_TermActions::max_trans;
		int    	LG_TermActions::max_errs;
		int    	LG_TermActions::max_final;
		int    	LG_TermActions::max_include;
		int    	LG_TermActions::max_kernel;
		int    	LG_TermActions::max_tt;
		int    	LG_TermActions::max_ntt;
		int    	LG_TermActions::max_lookback;
		int    	LG_TermActions::max_prods;
		int    	LG_TermActions::max_ebnf;
		int    	LG_TermActions::max_states;
		int    	LG_TermActions::max_symbs;
		int    	LG_TermActions::max_tails;
		int    	LG_TermActions::max_space;
		int    	LG_TermActions::max_lev;
		int    	LG_TermActions::max_code;
		int    	LG_TermActions::max_ttas;
		int    	LG_TermActions::max_n_prods;

		short 	LG_TermActions::arrow_col = 0;
		short 	LG_TermActions::prev_token;
		int*  	LG_TermActions::tail;
		char* 	LG_TermActions::pool_ptr;
		char* 	LG_TermActions::pool_end;
		int   	LG_TermActions::n_tokens;
		int*		LG_TermActions::f_prod;
		int*		LG_TermActions::l_prod;
		int*		LG_TermActions::f_tail;
		int*		LG_TermActions::l_tail;
		int		LG_TermActions::n_symbs;
		int		LG_TermActions::n_heads;
		int		LG_TermActions::n_keywords;
		int		LG_TermActions::n_strings;
		int		LG_TermActions::n_actioncodes;
		int		LG_TermActions::N_terms;
		int		LG_TermActions::n_lex_terms;

		char*  	LG_TermActions::tokenstartstr;
		char*  	LG_TermActions::tokenendstr;
		char*  	LG_TermActions::tokenlinestr;
		char*  	LG_TermActions::linenumbstr;
		char*  	LG_TermActions::colnumbstr;
		char*  	LG_TermActions::tabstopstr;
		int    	LG_TermActions::anl_stat_memory;
		int    	LG_TermActions::amt_code;
		int*   	LG_TermActions::camefrom2;
		int    	LG_TermActions::end_symb;	// $end	(128 | 256)
		int*   	LG_TermActions::final2;
		int    	LG_TermActions::final_state;
		int    	LG_TermActions::gen_tabl_memory;
		int    	LG_TermActions::get_memory_data;
		int*   	LG_TermActions::head_type;
		int*   	LG_TermActions::head_level;
		int    	LG_TermActions::illegal_char_state;
		int    	LG_TermActions::n_genliterals;
		int    	LG_TermActions::n_original_prods;
		int    	LG_TermActions::n_outputfiles;
		int    	LG_TermActions::n_added;
		int    	LG_TermActions::n_levels;
		int    	LG_TermActions::n_bytes;
		int    	LG_TermActions::NDLeft;
		int    	LG_TermActions::n_nonttran;
		int    	LG_TermActions::n_oprods;
		int    	LG_TermActions::n_termtran;
		int    	LG_TermActions::n_words;
		int*   	LG_TermActions::ntt_goto2;
		int*   	LG_TermActions::ntt_symb2;
		int    	LG_TermActions::n_totalterm;
		int    	LG_TermActions::n_codelines;
		int    	LG_TermActions::opt_stat_memory;
		int    	LG_TermActions::parser_memory;
		int*   	LG_TermActions::possibil;
		int    	LG_TermActions::rr_con;
		int    	LG_TermActions::SLA_expired;
		int    	LG_TermActions::sr_con;
		int*   	LG_TermActions::st_type;
		int*   	LG_TermActions::tt_goto2;
      int      LG_TermActions::in_lex_part;
      int      LG_TermActions::already_exists;
      int      LG_TermActions::already_readlex;

		#define  TAIL_SYMBOL 0
		#define  HEAD_SYMBOL 1

///////////////////////////////////////////////////////////////////////////////

void  LG_Actions::init_actions ()
{

}

///////////////////////////////////////////////////////////////////////////////

void  LG_Actions::term_actions ()
{

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    error                                                                  //

int   LG_TermActions::error (int &t) // New version
{
		if (token.end == token.start) token.end++;
      return (t); // t = 0
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    first()   																			  //

int   LG_TermActions::first (int &t) // New version
{
		int la, la_line;
		if (line_pos == 1)
		{
         if (in_lex_part)
         {
            return (arga[t]);
         }
			if (prev_token == T_SEMI)
			{
   			return (arga[t]);   // first argument
			}
			char *p;
			int blankline = 0;
			for (p = token.start; *p != '\n'; p--); // Find previous '\n'
			if (p > input_start)
			{
				while (*--p == ' ' || *p == '\t');	// Bypass whitespace.
				if (*p == '\n') blankline = 1;		// Blank line
			}
         if (blankline == 0)
         {
				la = get_lookahead (la_line);
            if (la == T_ARROW)
            {
               in_lex_part = 0;
               if (token.line == la_line) // Same line as <alpha> symbol?
               {
         			return (arga[t]);   // first argument
               }
            }
				return t;
         }
  			return (arga[t]);   // first argument
		}
		return t;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    arrow                                                                  //

int   LG_TermActions::arrow (int &t) // New version
{
		if (line_pos == 1) return (t);
		if (line_pos == 2) return (t);
		prt_error ("'%s' seems to be out of place on this line.", token.start, token.end, token.line);
		Quit();
		return 0;
}

/*--- End of Actions2.CPP ------------------------------------------------------*/

