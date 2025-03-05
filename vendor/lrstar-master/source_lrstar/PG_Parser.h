
/* Copyright 2018 Paul B Mann.  BSD License. */

#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    PG_Parser.h

		#include "CM_Global.h"
		#include "PG_Lexer.h"
		#include "PG_ParserTables.h"
		#include "stdio.h"

	// AST Action Mode.
      #define TOP_DOWN        0  // Top down.
   	#define PASS_OVER       1  // Pass over.
   	#define BOTTOM_UP       2  // Bottom up.

	// AST Traversal Passes.
      #define FIRST_PASS       1  // EBNF normalization.
      #define SECOND_PASS      2  // EBNF expansion.
      #define THIRD_PASS       3  // Count variables.
      #define FOURTH_PASS      4  // Print the grammar.

      class PG_Parser : public PG_Lexer, public PG_ParserTables
		{
		   public:
		// Functions ...
			static void    parse_init      (int maxsymbols, char* patharg);
			static int     parse           (char* input_start);
			static void    parse_term      ();
			static void    syntax_error    (char* msg, Token* T, char* symb);

		// Variables ...
			static int     n_constants;
		   static int     N_args;
		   static int*    F_narg;
			static int*    Arg_numb;
			static int    	N_strings;
			static int    	N_tails;
			static int    	N_terms;
			static int*   	Node_numb;
			static int*   	Nact_numb;
			static char** 	Node_start;
			static char** 	Nact_start;
			static int    	N_heads;
			static int    	N_nodes;
			static int    	N_tacts;			// terminal actions.
			static int    	N_nacts;			// node actions.
			static int    	N_ints;
			static int    	N_prods;
			static int    	N_semantics;
	      static char**  Str_start;
			static int*    f_eri;
			static int*    F_targ;
			static int*    N_targ;
			static int*    F_parg;
			static int*    N_parg;
			static int*    F_prod;
	      static int*    eri_prod;
		   static int*    eri_dot;
		   static int     n_eris;
	      static char**  Tact_start;
		   static int*    Tact_numb;
	      static int*    Reverse;
			static int     N_reverses;
			static int*    Priority;
			static int     opt_states;
			static int*    Oper_prec;
			static int*    Pact_numb;
	      static int*    Defcon_value;
	      static int*    Defcon_type;
		   static char**  Defcon_name;
			static int     eol_term;
			static int     eof_term;
			static int     error_used;
	      static int     keyword_sym;
	      static int     n_declared;
	      static int     prod_numb;
			static char*   path;

         static PStack* PS;           	      // Parse Stack pointer.
         static PStack* PS_end;        	   // Parse Stack end.
			static int     prev_token;
			static int		goal_symbol;
			static int		error_mode;
         static int     start_sti;
         static int     yacc;

		   private:
		// Functions ...
			static int     reduce         (int p);
			static int     linkup			(int p);
         static int     restore        ();
         static void    expecting      (int x);
         static void    reduction      (int p, int x);
         static void    print_terms	   (int x);
         static void    sort_terms	   (int*);
         static void    print_stack	   ();

		// Variables ...
  		  	static char*   tact_name[];		// Parser action name.
  		  	static char*   pact_name[];		// Parser action name.

			static int     max_errs;			// Maximum allowable errors.
			static int     eof_symb;			// <eof> symbol number.
			static int     eol_symb;			// <eol> symbol number.
			static int     err_used;			// <error> used in grammar?

         static RStack* RS;           		// Reduction Stack pointer.
			static uchar*  T_exp;				// Terminal expecting list.
			static uchar*  S_exam;           // State examined yet.
         static RStack  R_stack[];			// Reduction stack.
         static PStack  P_stack[];			// Parser stack.

			static char*   head_symb[];      // Head (nonterminal) symbols of the grammar.
			static uchar   head_numb[];      // Head symbol number for a production (rule).

			public:
			static char    indent[256];	   // Indentation for printing current node.
         static int*    counter;				// Node counter array.
         static short   stacki;		      // AST stack index.
         static Stack*  stack;			   // AST stack array.
			static Node*   node;					// AST node array.
			static Node*   root;					// Root node pointer.
			static Node*   ebnf;					// EBNF node pointer.
			static Node*   currnode;		   // Current node pointer.
			static int     n_nodes;				// Number of nodes created.
			static int     n_nodenames;		// Number of node names.
			static int     n_nodeactions;		// Number of node actions.
			static short   pass;					// Pass number when traversing the AST.
			static short   direction;		   // Direction of travel (TOP_DOWN | PASS_OVER | BOTTOM_UP).

		// Functions ...
			static void    find_root  ();
			static void    find_ebnf  ();
			static void    init_ast	  ();
			static void    term_ast	  ();
			static void    print_ast  ();
			static void    print_ast  (Node* np);
			static void    print_node (char *indent, Node* np);
         static void    traverse	  ();
         static void    traverse	  (Node* np);
			static void    traverse	  (char *indent, Node* np);
			static short   emitstr	  (Node* np, char* str);

		   public:
			static Symbol* symbol;			   // Symbols.
			static int     n_symbols;		   // Number of symbols.
			static short   length;			   // Current length of symbol name.
			static int     cell;					// Current hash cell number.
			static int     sti;				   // Current symbol-table index.
			static uint    hashdiv;				// Hash divisor.
			static int*    hashvec;				// Hash vector.
			static int     max_cells;			// Maximum number of cells in the hash vector = 2*max_symbols.
			static int     max_symbols;	   // Maximum number of symbols.

      // Functions ...
			static void    init_symtab  (int);							// initialize the symbol table.
			static void    term_symtab  ();								// terminate the symbol table.
			static char*   symname      (int);							// Get symbol name.
			static int     add_symbol   (char*, char*, int, int);	// Add symbol to symbol table.
			static void    rename_symbol(short, int);					// Rename symbol.
			static int     get_symbol   (char*, char*, int);		// Get symbol number.
			static void    print_symtab (char**);						// Print the symbol table.
		};

