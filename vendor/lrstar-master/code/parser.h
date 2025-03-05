
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Parser Header

		#pragma once

	// AST Traversal Passes.
      #define FIRST_PASS       1
      #define SECOND_PASS      2
      #define THIRD_PASS       3
      #define FOURTH_PASS      4

      class Symbol		   // Symbol in Symbol Table.
      {
         public:
			char*  start;     // Start of symbol in input file or ?.
			int    length;    // Length of symbol.
			int    cell;      // Cell number in hash vector (if need to delete later).
			int    type;      // Type of symbol: int, char, float, short, ...
			int    term;      // Terminal number for lookup function.
			int    scope;     // Scope: global, local, inner loop, ...
      };

		class Node				// AST Node.
		{
			public:
			int    id;			// Node ID number  .  								4
			int    sti;			// Symbol-table index (perm or temp var).		4
			int    line;		// Line number in input file.                4
			char*  start;		// Start of symbol in input area.            4
			Node*  prev;		// Previous node.			   						4
			Node*  next;		// Next node.											4
			Node*  child;		// Child node.                              	4
			Node*  parent;		// Parent node.                             	4  32 bytes
		};

      class PStack			// Parser stack.
      {
         public:
         int    state;		// Parser state.
			int    sym;			// Tail symbol.
			int    sti;			// Symbol table index.
         int    line;		// Input line number.
			char*  start;		// Start of symbol in input file area.
			Node*  node;		// Pointer to node.
         Node*  last;		// Pointer to last in list.
      };

      class RStack			// Restore Stack.
      {
         public:
         PStack* ptr;		// Parse stack pointer.			4	4
         int     state;		// State.								4
         int     sym;		// Symbol.								4	12	bytes.
      };

      class SStack			// State stack.
      {
         public:
         int    state;		// Parser state.
      };

      class Stack				// AST Stack.
      {
         public:
			int    id;			// Node id.                      4
			int    counter;	// Counter of node accesses.     4	 8 bytes
      };

 		class PARSER : public PARSER_TABLES, public LEXER
      {
         public:
      // Parser functions
         static int     init_parser  (char* path, char* input, int max_syms, int max_nodes);
         static int     parse			 ();
         static void    term_parser	 ();
			static void	   print_prod   (char* prefix, int p, int dot);

         public:
		// Parser variables
			static char    path[256];		// Path of input file.
			static PStack  PSstart[];		// Parser stack start.
			static PStack* PS;				// Parse stack pointer.
			static int	   n_nodes;			// Number of nodes in AST.
			static int     n_symbols;	   // Number of symbols.

			private:
      // Parser functions
         static void    reduce		 (int p);
			static int     linkup       (int p);

			private:
		// Parser variables
			static RStack* RS;
			static RStack  RSstart[];
			static uchar*  T_exp;		 // Terminal expected.
			static uchar*  S_exam;		 // State examined.

		// Expecting functions ...
         static int     restore      ();
         static void    syntax_error (char*, Token*, char*);
         static void    expecting    (int x);
         static void    reduction    (int p, int x);
         static void    print_terms	 (int x);
         static void    sort_terms	 (int*);
         static void    print_stack	 ();

		// ND parsing ...
			#ifdef ND_PARSING
			static int     LA;							// Look Ahead token.
			static int     n_warnings;             // Numbor of warnings.
			static int     last_line;
			static SStack* SS      [ND_THREADS];	// State stack pointer.
			static SStack* SSstart [ND_THREADS];	// State stack start.
			static int     State   [ND_THREADS];	// State, during lookahead.
			static int     Action  [ND_THREADS];	// Parsing action.
			static int     Parsed  [ND_THREADS];	// Parsed (0 or 1).
			static int		LAcount [LOOKAHEADS+1];	// Lookahead count.

			static void    nd_optimize       ();
			static int     nd_parser         (int x, int t, int i);
         static int     nd_parser_la      (int i, int la);
			static void    print_action      (char* str, int i);
			static void    print_actions     (int na);
			static void    print_lookaheads  ();
			#endif

		// Symbol-Table Area ...
         public:
         static int     init_symtab  (int max_symbs);
         static void    term_symtab  ();
         static void    print_symtab ();
         static int     add_symbol	 (int, char*, char*);
         static char*   symbol_name	 (int sti);
         static char*   symbol_name	 (char* start, char* end);

         public:
			static Symbol* symbol;		   // Symbol.

         private:
			static uint    hashdiv;			// Hash divisor.
			static int*    hashvec;			// Hash vector.
			static int     max_cells;		// Maximum number of cells in the hash vector.
			static int     max_symbols;	// Maximum number of symbols.

		// AST Area ...
         public:
			static Node*	root;				// Current root node.
			static Node*	node;				// Current AST node.
			static int	  	traversal;		// AST traversal number: 1, 2, 3 ...
			static int		direction;		// Node direction: TOP_DOWN, BOTTOM_UP.
			static Stack*	stack;			// AST stack array.
			static int		stacki;			// AST stack index.

         private:
			static int		max_nodes;		// Maximum number of nodes.
			static int*		counter;			// Node counter array.
			static Node*   nodearea;		// Node area or Node block allocated.
			static char		indent[256];	// Indentation for printing current node.
			static char		draw_plus[3];
			static char		draw_vbar[3];
			static char		draw_last[3];
			static char		draw_space[3];

         public:
			static int     init_ast		(int max_nodes);
			static void    term_ast		();
			static Node*   new_node		();
			static void    find_root	(Node* last);
			static void    print_ast	();
			static void    print_ast	(Node* n);
			static void    traverse		(int trav);
			static void    traverse		(Node* n);
			static void    traverse		(char* indent, Node* n);
			static void    print_node	(char* indent, Node* n);
			static void    tracer      (Node* n);

		};

