
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

      #include "PG_Parser.h"

   // Grammar Symbol Types ...
      #define TOKEN                 1
      #define TERMINAL              2
      #define NONTERMINAL           4
      #define TAIL                  8
      #define ARGUMENT             16
      #define CONSTANT             32
      #define GENERATED            64
      #define STRING              128
      #define RESERVED            256
      #define NODENAME            512
      #define TACTION            1024
      #define NACTION            4096
      #define INTEGER            8192
      #define UNDECLARED        16384
      #define OPTIONSYM         32768
		#define OPERATOR			  65536

		#define SYNTAX 0
		#define POSITION 1

		#ifdef ACTIONS

      class ACTIONS : public PARSER
      {
         public:
			static void init_actions();
			static void term_actions();

			static int  head_col;
			static int  arrow_col;
			static int  colon_col;
			static int  n_terms;
		};

		#endif
		#ifdef TERM_ACTIONS

      class TERM_ACTIONS : public ACTIONS
      {
         public:
         static int error        (int& t);
         static int lookup       (int& t);
			static int headsymbol   (int& t);
			static int arrow        (int& t);
			static int colon			(int& t);
			static int bar				(int& t);
			static int semi         (int& t);
			static int position     (int& t);
			static int poslookup    (int& t);
			static int code_reader  (int& t);
		};

		#endif
		#ifdef PARSE_ACTIONS

      class PARSE_ACTIONS : public TERM_ACTIONS
      {

         public:
      // Variables ...
			static int   	STI;
			static int   	production_length;
         static char*   restart;

      // Functions ...
         static int   	parse_action_				(int p);
         static int   	defcon_     				(int p);
         static int   	terminal_decl_  			(int p);
         static int   	terminal_     				(int p);
         static int   	oper_         				(int p);
         static int   	goalsymbol_   				(int p);
         static int   	headsymbol_   				(int p);
         static int   	prod_         				(int p);
         static int   	priority_     				(int p);
         static int   	tail_         				(int p);
         static int   	tail_eof_     				(int p);
         static int   	sep_          				(int p);
			static int   	sep_expr_               (int p);
			static int   	tail_expr_              (int p);
			static int   	tail_list_					(int p);
			static int   	ta_name_  	            (int p);
         static int   	pa_name_  		         (int p);
         static int   	node_name_     			(int p);
         static int   	node_action_    			(int p);
			static int   	reverse_                (int p);
			static int   	arg_first_     			(int p);
         static int   	arg_integer_       		(int p);
         static int   	arg_alpha_     			(int p);
         static int   	arg_semantic_    			(int p);
         static int   	arg_terminal_      		(int p);
         static int   	arg_string_       		(int p);
         static int   	make_node_ 					(int p);
         static int   	make_node_wa_ 				(int p);
         static int   	parse_action_make_node_ (int p);
         static int   	parse_action_make_node_wa_	(int p);
         static int   	args_ 						(int p);
         static int     bypass_                 (int p);
		};

		#endif
		#ifdef NODE_ACTIONS

		class NODE_ACTIONS : public PARSE_ACTIONS
		{
         public:
      // Variables ...
			static char**  Defcon_term;
			static char**  head_name;
			static int*    head_type;
			static int*    head_sym;
			static int*    head_line;
			static int*    term_line;
			static int*    term_const;
			static int*    const_term;
			static char**  const_name;
			static int*    prod_len;
			static int*    prod_line;
			static int*    nullable;
			static int     n_nulls;
			static int     n_prods;
			static int     amt_space;
			static int*    Tail;
	      static int*    F_tail;
			static char**  term_name;
         static int   	linelength;
         static int   	prevtail;
         static int   	arrow_;
         static char* 	oper;
         static int   	assoc;
         static int   	constant;
         static int   	n_values;
         static int   	generated;
         static int   	precedence;
         static int   	terminal_mode;
         static int   	separator;
	      static char**  term_start;
		   static char**  term_end;
			static int*    term_type;
			static char**  Int_start;
         static Node* 	lastnonterm;
			static Node*   lastebnf;
			static Node* 	lastprod;
         static Node* 	lastsection;
         static Node* 	lasttail;
			static int     stmt_beg;
			static int		stmt_end;

      // Functions ...
			static int   	start_(void*);
         static int   	declarations_(void*);
			static int   	operprec_(void*);
			static int   	rules_(void*);
			static int   	goaldef_(void*);
			static int   	headdef_(void*);
         static int   	terminal_decl_(void*);
         static int   	defcon_(void*);
         static int   	terminal_(void*);
			static int   	oper_(void*);
			static int   	leftassoc_(void*);
         static int   	rightassoc_(void*);
         static int   	prod_(void*);
         static int   	priority_(void*);
			static int   	section_(void*);
         static int   	tail_(void*);
			static int   	tail_eof_(void*);
			static int   	tail_list_(void*);
			static int   	sep_(void*);
			static int   	terminal_action_(void*);
			static int   	rule_actions_(void*);
         static int   	pa_name_(void*);
			static int   	ta_name_(void*);
			static int   	node_name_(void*);
			static int   	node_action_(void*);
         static int   	targs_(void*);
			static int   	pargs_(void*);
			static int   	semargs_(void*);
			static int   	arg_integer_(void*);
         static int   	arg_alpha_(void*);
         static int   	arg_terminal_(void*);
         static int   	arg_semantic_(void*);
         static int   	arg_string_(void*);
         static int     reverse_(void*);
         static int     bypass_(void*);

			static int     repeat_one_or_more_ (void* np);
			static int     repeat_zero_or_more_(void* np);
			static int     repeat_zero_or_one_ (void* np);

			static int     group_   (void* np);
			static int     optgroup_(void* np);
			static int     sepgroup_(void* np);

			static int     make_ebnf        (Node* np, int type, char oper);
			static int     get_length       (Node* np, int type);
			static char*   make_nonterminal (Node* np, int type, char* p, int& sep, char oper);
			static int     make_productions (Node* np, int type, int head, int sep, char oper);

			static void  	make_head (int);
         static void  	make_prod (int);
         static void  	make_tail (int);

			static void  	SORT_GROUP (Node* np);

			static void    get_last_nonterminal();
			static void    connect_ebnf_tree();
			static void  	number_the_terminals();
			static void  	check_for_quotes();
			static void  	alloc_struc();
			static void  	fill_struc();
		};

		#endif

