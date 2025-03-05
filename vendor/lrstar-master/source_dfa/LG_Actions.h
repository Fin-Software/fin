
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once
		#include "LG_Parser.h"

		#ifdef ACTIONS

		class ACTIONS : public PARSER
		{
			public:
			static void  init_actions();
			static void  term_actions();
		};

		#endif
		#ifdef TERM_ACTIONS

		class TERM_ACTIONS : public ACTIONS
      {
			public:
			static char**  Defcon_term;
			static char**  head_name;
			static int*    head_sym;
			static int*    head_line;
			static int*    term_line;
			static int*    prod_len;
			static int*    prod_line;
			static int*    nullable;
			static int     n_nulls;
			static int     n_constants;
			static int     N_prods;				// Number of token productions (<identifier> => 1).
			static int     n_prods;				// Number of other productions.
			static int     N_tails;				// Number of tails for token productions.
			static int     n_tails;				// Number of tails for other productions.
			static int     amt_space;
			static int*    Tail;
			static int*    F_tail;
			static char**  term_name;
			static int*    term_type;
         static int     in_lex_part;
         static int     already_exists;
         static int     already_readlex;

			static char**  str_start;
			static char**  code_start;
	      static int*    Defcon_value;
		   static char**  Defcon_name;
	      static int*		ret_value;
		   static char**  ret_name;
			static char**  ret_term;
			static int*    ret_numb;
			static int   	n_symbs;
      	static int   	n_strings;
      	static int   	n_actioncodes;
      	static int   	N_terms;
      	static int   	n_lex_terms;
      	static int   	n_heads;
      	static int   	n_tokens;
      	static int   	n_keywords;
			static char* 	pool_ptr;
			static char* 	pool_end;
			static int   	ignore;
			static int*  	f_tail;
			static int*  	l_tail;
			static int*  	f_prod;
			static int*  	l_prod;
			static int*  	tail;
			static int*    prod_type;
			static int    	max_trans;
			static int    	max_errs;
			static int    	max_final;
			static int    	max_include;
			static int    	max_kernel;
			static int    	max_tt;
			static int    	max_ntt;
			static int    	max_lookback;
			static int    	max_prods;
			static int    	max_ebnf;
			static int    	max_states;
			static int    	max_symbs;
			static int    	max_tails;
			static int    	max_space;
			static int    	max_lev;
			static int    	max_code;
			static int    	max_ttas;
			static int    	max_n_prods;
			static char*  	tokenstartstr;
			static char*  	tokenendstr;
			static char*  	tokenlinestr;
			static char*  	linenumbstr;
			static char*  	colnumbstr;
			static char*  	tabstopstr;
			static int    	anl_stat_memory;
			static int    	amt_code;
			static int*   	camefrom2;
			static int    	end_symb;	// $end	(128 | 256)
			static int*   	final2;
			static int    	final_state;
			static int    	gen_tabl_memory;
			static int    	get_memory_data;
			static int*   	head_type;
			static int*   	head_level;
			static int    	illegal_char_state;
			static int    	n_genliterals;
			static int    	n_original_prods;
			static int    	n_outputfiles;
			static int    	n_added;
			static int    	n_levels;
			static int    	n_bytes;
			static int    	NDLeft;
			static int    	n_nonttran;
			static int    	n_oprods;
			static int    	n_termtran;
			static int    	n_words;
			static int*   	ntt_goto2;
			static int*   	ntt_symb2;
			static int    	n_totalterm;
			static int    	n_codelines;
			static int    	opt_stat_memory;
			static int    	parser_memory;
			static int*   	possibil;
			static int    	rr_con;
			static int    	SLA_expired;
			static int    	sr_con;
			static int*   	st_type;
			static int*   	tt_goto2;

      // Token data ...
			static short 	arrow_col;
			static short 	prev_token;

			static void    init_actions ();
			static void    term_actions ();


      // Token actions ...
         static int   	error (int&);
         static int   	is_head (int&);
         static int   	first (int&);
			static int   	arrow (int&);
         static int   	checkcase (int&);
         static int   	checkstring (int&);
		};

		#endif
		#ifdef PARSE_ACTIONS

		class PARSE_ACTIONS : public TERM_ACTIONS
		{

      // Functions ...
			public:
			static void	 	Count_terms ();
         static int   	init ();
         static int   	term ();
         static int   	get_char ();
         static int   	GEN_EBNF ();
			static int  	ADDSYM (char*, int);
			static char* 	ADDSYMBOL (char*, int);
         static int   	ADD_TOKEN (int p);
         static int   	ADD_TOKEN2 (int p);
         static int   	ADD_IGNORE (int p);
         static int   	ADD_KEYWORD (int p);
         static void  	EXPAND_SETS ();
			static int   	NUM_PRODS (int s);
         static int   	MAKE_TERMINALS ();
         static int   	FIRST_CHAR (int p);
         static int   	FIRST_RANGE (int p);
         static int   	FIRST_SET (int p);
         static int   	DEF_SET (int p);
			static void  	CHECK_SET (int s);
         static int   	GEN_SYMB ();
         static int   	GEN_HEAD (int);
         static int   	GEN_HEAD_LITERAL (int, char*, int);
         static int   	GEN_PROD ();
         static int   	GEN_TAIL (int);
         static int   	REMOVE_QUOTES ();
	   	static int   	CHECK_SYMBOL (int);
         static int   	GEN_CON ();
         static int   	GEN_STRINGS ();
         static void  	EXP_LITERALS ();
         static int   	EXIST ();
         static int   	SYMNUMB ();
         static int   	GENSYMNUMB ();
			static int   	ADD_SYMBOL (char* name, int& sym_numb);

      // Production actions ...
			static int     SET_DEBUG (int p);
         static int   	EOGI (int p);
         static int   	PRO_OPTNS (int p);
         static int   	ADD_TAIL (int p);
         static int   	PUSH_UNDEF (int p);
         static int   	PUSH_TAIL (int p);
         static int   	SET_START (int p);
         static int   	SET_END (int p);
         static int   	MAKE_SETNAME (int p);
         static int   	ADD_HEAD (int p);
         static int   	ADD_HEADLEX (int p);
         static int   	ADD_HEADIGNORE (int p);
         static int   	ADD_HEADSET (int p);
         static int   	ADD_PROD (int p);
         static int   	CHECK_PROD (int p);
         static int   	DEF_TAIL ();
         static int   	ADD_TERMINAL ();
         static int   	CHK_NUMB ();
			static void	 	MAKE_SET (int s);
			static void  	P_PROD (int p);
			static void  	ADDSETNAME (int s, char* hit);
			static void  	SUBSETNAME (int s, char* hit);
         static int   	ADD_NOTERM (int p);
         static int   	ADD_TERMNO (int p);
         static int   	ADD_DEFCON (int p);
         static int   	ADD_STRING (int p);
         static int   	ADD_CODE   (int p);
         static int   	START_GRM ();
         static int   	ADD_GOAL (int p);
         static int   	ADD_EOF (int p);
         static int   	ADD_CHAR (int p);
         static int   	SUB_CHAR (int p);
         static int   	RANGE_START (int p);
         static int   	RANGE_END (int p);
         static int   	RANGE_TOP (int p);
         static int   	RANGE_ALL (int p);
         static int   	ADD_RANGE (int p);
         static int   	SUB_RANGE (int p);
         static int   	ADD_PRODADD ();
         static int   	ADD_PRODSUB ();
         static int   	ADD_PRODTO ();
         static int   	ADD_SETNAME (int p);
         static int   	ADD_SET (int p);
         static int   	SUB_SET (int p);
         static int   	CHK_SETNAME ();
         static int   	ADD_NULL (int p);
         static int   	POP_ALL (int p);
         static int   	POP_SET (int p);
         static int   	PUSH_GBEG (int p);
         static int   	PUSH_GEND (int p);
         static int   	PUSH_OR (int p);
         static int   	PUSH_DOTS (int p);
         static int   	PUSH_PLUS (int p);
         static int   	PUSH_ASTER (int p);
         static int   	PUSH_QUEST (int p);
         static int   	PUSH_GDOTS (int p);
         static int   	PUSH_GPLUS (int p);
         static int   	PUSH_GASTER (int p);
         static int   	PUSH_GQUEST (int p);
         static int   	PUSH_OBEG (int p);
         static int   	PUSH_OEND (int p);
         static int   	PUSH_ODOTS (int p);

      };

		#endif

