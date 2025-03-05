
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
  		#include "PG_Actions.h"
		#include "PG_ParserTables.hpp"

		#define STKSIZE    1000 // Parser stack size.

	// Expecting list variables ...
      RStack*	PG_Parser::RS;
      RStack	PG_Parser::R_stack[STKSIZE];
		uchar*   PG_Parser::T_exp;
		uchar*   PG_Parser::S_exam;

		int		PG_Parser::N_args;
		int*		PG_Parser::F_narg;
		int*		PG_Parser::Arg_numb;
		int    	PG_Parser::N_strings;
		int    	PG_Parser::N_tails;
		int    	PG_Parser::N_terms;
		int*   	PG_Parser::Node_numb;
		int*   	PG_Parser::Nact_numb;
		char** 	PG_Parser::Node_start;
		char** 	PG_Parser::Nact_start;
		int    	PG_Parser::N_heads;
		int    	PG_Parser::N_nodes;
		int    	PG_Parser::N_tacts;  // token actions.
		int    	PG_Parser::N_nacts;
		int    	PG_Parser::N_ints;
		int    	PG_Parser::N_prods;
		int    	PG_Parser::N_semantics;
	   char**	PG_Parser::Str_start;
		int*		PG_Parser::f_eri;
		int*		PG_Parser::F_targ;
		int*		PG_Parser::N_targ;
		int*		PG_Parser::F_parg;
		int*		PG_Parser::N_parg;
		int*		PG_Parser::F_prod;
	   int*		PG_Parser::eri_prod;
		int*		PG_Parser::eri_dot;
		int		PG_Parser::n_eris;
	   char**	PG_Parser::Tact_start;
		int*		PG_Parser::Tact_numb;
	   int*		PG_Parser::Reverse;
		int      PG_Parser::N_reverses;
		int*		PG_Parser::Priority;
		int		PG_Parser::opt_states;
		int*     PG_Parser::Oper_prec;
		int*     PG_Parser::Pact_numb;
	   int*     PG_Parser::Defcon_value;
	   int*     PG_Parser::Defcon_type;
		char**   PG_Parser::Defcon_name;
		int      PG_Parser::eol_term;
		int      PG_Parser::eof_term;
		int      PG_Parser::error_used;
	   int      PG_Parser::keyword_sym;
		int      PG_Parser::n_constants;
		char* 	PG_Parser::path;

	// Parser stuff ...
		PStack*  PG_Parser::PS;
		PStack*  PG_Parser::PS_end;
      PStack   PG_Parser::P_stack[STKSIZE];
		int      PG_Parser::max_errs;
		int		PG_Parser::prev_token;
		int		PG_Parser::goal_symbol;
		int		PG_Parser::n_declared;
		int		PG_Parser::prod_numb;
		int		PG_Parser::start_sti;
		int		PG_Parser::yacc;

	// Symbol table stuff ...
      Symbol*  PG_Parser::symbol;
		int      PG_Parser::sti;
		short    PG_Parser::length;
		int      PG_Parser::n_symbols;
		uint     PG_Parser::hashdiv;
		int*		PG_Parser::hashvec;
		int      PG_Parser::cell;
		int		PG_Parser::max_cells;
		int      PG_Parser::max_symbols;

	// PG_Parser stuff ...
		Node*		PG_Parser::node;
		Node*		PG_Parser::root;
		Node*		PG_Parser::ebnf;
		Node*		PG_Parser::currnode;
      int*		PG_Parser::counter;
      char     PG_Parser::indent[256];
      Stack*	PG_Parser::stack;
      short    PG_Parser::stacki;
      int      PG_Parser::n_nodenames =    40;		// Number of node names.
      int      PG_Parser::n_nodeactions =    40;	// Number of node actions.
      int      PG_Parser::n_nodes;
		short    PG_Parser::direction;
		short    PG_Parser::pass;

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::parse_init (int max_symb, char* grm_path)
{
      int  sti;
      char *p, sym[256];
      int  t, len, terminal;

		path = grm_path;

		init_symtab (max_symb);                            // Initialize the symbol table.
		init_ast ();                                       // Initialize the PG_Parser.
		p = "";
		sti = add_symbol (p, p+1, 0, 0);              	// Add blank symbol as number 0.
      symbol[sti].value = -1;

	// See if lexer can read the 'literal' terminal symbols.
		n_errors = 0;
		for (t = 1; t < n_terms; t++)		                  // For all terminals except <error> (0).
		{
			if (*term_symb[t] == '\'')                      // Literal symbol?
			{
   			len = -1;
				for (p = term_symb[t]+1; *p != 0; p++)       // For all characters in terminal symbol.
				{
					if (++len > 255)                          // If length greater than 255 ...
					{
						n_errors++;
						printf ("Terminal symbol is longer than 255 characters:\n%s\n\n", term_symb[t]);
						Quit ();
					}
					sym[len] = *p;                            // Move character to sym.
				}
				if (len < 0) len = 0;
				sym[len]  = 26;					               // Replace last ' with end-of-file character.
				token.end = sym;				                  // Starting point for next Lexer read.
				terminal  = get_token();		               // Try to read symbol, get it's terminal number.
				sym[len]  = '\'';				                  // Replace end-of-file with '.
				if ((token.end-token.start) != len)          // Did not read the whole symbol?
				{
					n_errors++;
					printf ("Lexer was not able to recognized %s\n", term_symb[t]);
				}
				else if (terminal != t)			               // Terminal number not t?, must be a keyword!
				{
					if (terminal == 0)		                  // Got an error on this symbol?
					{
						n_errors++;
						printf ("Lexer returns zero for %s (check reduce-reduce conflicts).\n", term_symb[t]);
					}
					add_symbol (term_symb[t]+1, term_symb[t]+1+len, 0, 0); // Put terminal into symbol table.
				}
			}
		}
		if (n_errors) Quit ();

	// Initialize some stuff.
      n_errors    = 0;
      n_warnings  = 0;
      max_errs    = 10;
      keyword_sym = 0;
      n_declared  = 0;
		prod_numb   = 0;
      n_constants = 0;
      n_nodes     = 0;
      start_sti   = 0;
		yacc        = 0;

      N_tails     = 0;
      N_prods     = 0;
      N_terms     = 0;
      N_heads     = 0;
      N_nodes     = 0;
      N_tacts     = 0;
      N_nacts     = 0;
      N_args      = 0;
      N_ints      = 0;
      N_strings   = 0;

		char* start = "<error>";
		char* end = start + 7;
		sti = add_symbol(start, end, TERMINAL, 0);
		symbol[sti].type = TERMINAL;
		symbol[sti].numb = N_terms++;	// = 0
		symbol[sti].value = -1;			// Undefined.

		start = "<eof>";
		end = start + 5;
		sti = add_symbol(start, end, TERMINAL, 0);
		symbol[sti].type = TERMINAL;
		symbol[sti].numb = N_terms++;	// = 0
		symbol[sti].value = -1;			// Undefined.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::parse_term ()
{
		term_ast  ();
		term_symtab ();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::parse (char* input_start)
{
      int    p;                                          // Production (rule) number.
      int    t = 0;                                      // Terminal symbol number.
      int    x = 0;                                      // State number.

		init_lexer (input_start);									// Initialize Lexer.
		goal_symbol = 0;												// Not seen yet.
		PS     = P_stack;							               // Set parse-stack pointer.
      PS_end = P_stack + STKSIZE;			               // Set parse-stack end pointer.

Read:	t = get_token ();							               // Get incoming token.
		token.sti = -t;							               // Point at terminal symbol.
      if (tact_numb[t] >= 0)					               // If token action ...
      {
			token.sti = (*tact_func [tact_numb[t]])(t);     // Call token-action function.
			if (t < 0) goto Read;									// To bypass {...} yacc code.
      }
		RS = R_stack;													// Set restore-stack pointer.
		RS->state = x;													// Save current state.
		RS->ptr = PS;													// Save parse-stack pointer.

Shft: if (Bm [Br[x] + Bc[t]] & Bf[t])							// Check B-matrix for shift action.
      {
			if (++PS >= PS_end) goto Overflow;
         PS->state = x;                                  // Put current state on stack.
         PS->sti   = token.sti;                          // Put token symbol table index on stack.
         PS->start = token.start;                        // Put token.start into parse stack.
         PS->end   = token.end;                          // Put token.end   into parse stack.
         PS->line  = token.line;                         // Put its line number on stack.
         PS->node  = NULL;			   	                  // Set node on stack to null.
         x = Tm [Tr[x] + Tc[t]];                         // Get next state from terminal transition matrix.
         while (x <= 0)                                  // While shift-reduce actions.
         {
				PS -= PL[-x];                                // Reduce stack ptr by production length.
			  	if (reduce(-x) != 0) return -line_numb;  // Call reduce action with rule number.
            x = Nm [Nr[PS->state] + Nc[-x]];             // Get next state from nonterminal transition.
         }
         goto Read;								               // Go to read next token.
      }

		if ((p = Rr[x]) > 0 || (p = Rm [Rc[t] - p]) > 0)   // Get reduction?
      {
			if (PL[p] < 0)							               // Null production?
         {
				if (++PS >= PS_end) goto Overflow;
				RS++;									               // Increment the restore stack pointer.
				RS->ptr   = PS;					               // Save parse-stack pointer.
     		   RS->state = PS->state;			               // Save old state before replacing it.
            PS->state = x;						               // Stack current state, replacing old state.
            PS->sti   = 0;					                  // Clear sti.
				PS->node  = NULL;					               // Clear node pointer.
				goto Red2;
         }
         while (1)
         {
            PS -= PL[p];                                 // Reduce parse stack ptr by rule length - 1.
Red2:		  	if (reduce (p) != 0) return -line_numb;		// Call reduce action with rule number.
            x = Nm [Nr[PS->state] + Nc[p]];	            // Get next state from nonterminal transition.
            if (x > 0) goto Shft;                        // Continue parsing.
            p = -x;								               // Set production number.
         }
      }

      if (x == accept_state)					               // If Goal production.
      {
         PS -= PL[p];                                    // Reduce parse stack ptr by rule length - 1.
			if (reduce (p) != 0) return -line_numb;			// Call reduce action with rule number.
			line_numb--;			      	                  // Reduce line number by one.
         if (n_errors) return -line_numb;

			find_root ();
		//	print_ast ();
         pass = FIRST_PASS;										// Assign operators to tails (bottom up).
  		   traverse ();
         if (n_errors) return -line_numb;

		//	print_ast();
			pass = SECOND_PASS;										// Make generated symbols (top down).
			traverse ();
			if (n_errors) return -line_numb;

		//	find_ebnf ();
		//	print_ast ();
			pass = THIRD_PASS;										// Make EBNF rules (top down).
			traverse ();
			if (n_errors) return -line_numb;

			return line_numb;
      }

		x = restore ();
		print_stack ();
		syntax_error ("Error", &token, term_symb[t]);
		expecting   (x);
		print_terms (x);
		return -line_numb;

Overflow:
		prt_log ("\nInternal error, Parser stack overflow.\n\n");
		return -line_numb;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::find_root()
{
		root = PS[0].node;            // Define root node.
		if (root != 0)
		{
			while (root->prev != 0)		// In case of a list only.
			{
				root = root->prev;		// Go up the list to first node.
			}
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::find_ebnf()
{
		ebnf = ebnf->next; // first EBNF nonterminal.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::reduce (int p)
{
		if (pact_numb[p] >= 0)	  							// PARSE ACTION ?
		{
			int rc;												// Return code.
			rc = (*pact_func [pact_numb[p]])(p);		// Call parse action with production number.
			if (rc < 0)											// Bypass make node operation?
			goto Linkup;
		}
      int psi;											      // Parse Stack Index.
      currnode = NULL;
      if (node_numb[p] >= 0)   					      // MAKE NODE ?
      {
         currnode = (Node*)ALLOC(node, 1);
         currnode->id     = node_numb[p];				// Set node id.
         currnode->numb   = n_nodes++;				   // Set node number.
         currnode->prod   = p;							// Set production number.
			currnode->oper   = 0;							// Set operator (* 9,+ 10,? 6).
         currnode->next   = NULL;						// Set next to none.
         currnode->prev   = NULL;						// Set prev to none.
         currnode->child  = NULL;		            // Define no child.
         currnode->parent = NULL;		            // Define no parent.
         if (argx[p] >= 0)				   				// If argument defined,...
         {
            psi = argx[p];	   							// Get parse-stack index.
            currnode->sti   = PS[psi].sti;		   // Move sti from parse stack to node.
            currnode->start = PS[psi].start;	      // Move start from parse stack to node.
            currnode->end   = PS[psi].end;	      // Move end from parse stack to node.
            currnode->line  = PS[psi].line;	      // Move line from parse stack to node.
         }
         else // No argument.
         {
            currnode->sti   = 0;    					// Set symbol-table index to zero.
            currnode->start = NULL;	               // Set start to null.
            currnode->end   = NULL;	               // Set end to null.
				currnode->line  = PS[0].line;				// Move line from parse stack to node.
			}
			psi = linkup(p);									// Linkup the nodes in this rule.
			if (psi >= 0)										// Any nodes found in this rule?
         {
				currnode->child = PS[psi].node;			// Define child.
            PS[psi].node->parent = currnode;			// Define parent.
         }
			PS[0].node = PS[0].last = currnode;		   // Define node in the parse stack.
      }
		else	                                       // Check for nodes not linked?
		{
Linkup:  psi = linkup (p);                         // Get parse-stack index.
			if (psi > 0)                              // If we have a node here ...
			{
				PS[0].node = PS[psi].node;		         // Move node value to 1st position.
				PS[0].last = PS[psi].last;		         // Move last value also.
			}
		}
      return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::linkup (int p)
{
      int i;
      int next = -1;
      for (i = PL[p]; i >= 0; i--)				         // For each tail pointer.
      {
         if (PS[i].node != NULL)                      // If tail points to node.
         {
            if (next >= 0)                            // If one waiting.
            {
               PS[i].last->next = PS[next].node;      // Attach node to end of list.
               PS[next].node->prev = PS[i].last;      // Define previous node.
               PS[i].last = PS[next].last;            // Change last to next last.

            }
            next = i;									      // Next = Curr.
			}
		}
      return (next);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::restore ()
{
		if (t_error == POSITION) return 0;

 		while (RS > R_stack)   // Restore PS, RS and states.
      {
         RS->ptr->state = RS->state;	// Reset state to saved state.
			RS--;
      }
		PS = RS->ptr;
		T_exp  = new uchar[n_terms];
		S_exam = new uchar[n_states];
		memset (T_exp,  0, n_terms);
		memset (S_exam, 0, n_states);
		return RS->state;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::expecting (int x)
{
		int t;													// Terminal number.
		int p;													// Production for default reduction.
		int q;													// Production for a terminal.

		if (t_error == POSITION) return;

		S_exam[x] = 1;											// Mark this state as seen.

   // TERMINAL TRANSITIONS TO NEXT STATE ...
     	for (t = 0; t < n_terms; t++)						// For all terminals.
		{
  			if (Bm [Br[x] + Bc[t]] & Bf[t])				// Terminal transition?
			{
            T_exp[t] = 1;                          // Mark this terminal.
			}
		}

   // DEFAULT REDUCTION IN THIS STATE ? ...
		if ((p = Rr[x]) > 0)									// Default reduction?
		{
			reduction (p, x);
			return;
		}

   // REDUCTIONS TRIGGERED BY TERMINAL SYMBOLS ? ...
		for (t = 0; t < n_terms; t++)						// For all terminals.
		{
			q = Rm [Rc[t] - p];								// Reduction for this terminal.
			if (q > 0)											// If not zero production?
			{
				reduction (q, x);
			}
		}
		return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::reduction (int q, int x)
{
	// Save parse stack pointers.
		RStack* RSx = RS;							// Reset restore-stack pointer.
		PStack* PSx = PS;							// Save parse-stack pointer.

		PS -= PL[q];								// Reduce parse stack ptr by rule length - 1.
		if (PL[q] < 0)								// Null production?
		{
			(++RS)->ptr = PS;					   // Save parse-stack pointer.
			RS->state = PS->state;			   // Save old state before replacing it.
			PS->state = x;						   // Stack current state, replacing old state.
		}
		while (1)
		{
			x = Nm[Nr[PS->state] + Nc[q]];	// Get next state from nonterminal transition.
			if (x > 0)
			{
				if (S_exam[x] == 0)				// Not been there yet?
					expecting (x);					// Recursive call, potential loop, but very rare.
				goto Done;
			}
			q = -x;								   // Set production number.
			PS -= PL[q];							// Reduce parse stack pointer.
		}

 	// Restore parse stack.
Done: PS = PSx;									// Restore PS.
 		while (RS > RSx)
      {
         RS->ptr->state = RS->state;      // Reset state to saved state.
			RS--;
      }
		return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::print_terms (int state)
{
      int i, t;
		if (t_error == POSITION) return;

		printf ("\nExpecting one of the following:\n\n");

		int* seq = new int [n_terms];
		sort_terms (seq);

		for (i = 0; i < n_terms; i++)
      {
			t = seq[i];
         if (t == EOFSYMBOL) continue; // <eof>
			if (T_exp[t] == 1)
         {
				if (term_symb[t][0] == '<' || term_symb[t][0] == '{')
            {
       	      printf ("      %s\n", term_symb[t]);
            }
         }
      }
		for (i = 0; i < n_terms; i++)
      {
			t = seq[i];
			if (t == EOFSYMBOL) continue; // <eof>
			if (T_exp[t] == 1)
         {
				if (term_symb[t][0] != '<' && term_symb[t][0] != '{')
            {
       	      printf ("      %s\n", term_symb[t]);
            }
         }
      }
		printf ("\n");
		delete [] seq;
}

////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::sort_terms (int* seq)
{
	/* seq - the sorted sequence:
	         name[seq[0]] gives the first name in the sorted list.
	*/
		char**P, *P_temp;
		int*  L, L_temp, seq_temp, i, j, leng, c;

		L = new int  [n_terms];
		P = new char*[n_terms];
		for (i = 0; i < n_terms; i++)
      {
         P[i] = term_symb[i];
         L[i] = (int)strlen(term_symb[i]);
         seq[i] = i;
      }
      for (i = 1; i < n_terms; i++)	// Bubble sort algorithm.
      {
         P_temp   = P[i];
         L_temp   = L[i];
         seq_temp = seq[i];
         j        = i - 1;
         do
         {
            leng = L[j];
            if (L_temp < L[j]) leng = L_temp;
            c = strncmp (P_temp, P[j], leng);
            if (c < 0 || (c == 0 && L_temp < L[j]))
            {
               P[j+1]   = P[j];
               L[j+1]	= L[j];
               seq[j+1]	= seq[j];
               P[j]		= P_temp;
               L[j]		= L_temp;
               seq[j]	= seq_temp;
            }
            else break;
         }
         while (--j >= 0);
      }
      delete [] L;
      delete [] P;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PG_Parser::print_stack () // Print parser stack.
{
/*		if (t_error == POSITION) return;

		printf ("\nParse stack:\n");
		for (PStack* ps = P_stack + 1; ps <= PS; ps++)
		{
			char *name, *name2;
			int sym = ps->sym;
			if (sym <= 0)
			{
				name = term_symb[-sym];
				if (*name == '<' || *name == '{')
					  name2 = symbol_name (ps->sti);
				else name2 = "";
				printf ("\t%4d %s %s\n", -sym, name, name2);
			}
			else
			{
				name = head_symb[sym];
				printf ("\t%4d %s\n", sym, name);
			}
		}
*/
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::syntax_error (char *msg, Token* T, char* symb)
{
      char  c;
		char* p;
      char* lineout;
      char* pointer;
      char* linestart;
      char  string[256];

		if (t_error == POSITION) return;

		n_errors++;
		if (*T->start <= 32)
		{
			T->end = T->start+1;
			*(T->end) = '\n';
			if (*T->start == 26) T->line--;
		}

		// Get line start ...
		for (linestart = T->start; *linestart != '\n'; linestart--);
		linestart++;

		// Get untabified line ...
		pointer = T->start;
		lineout = untabify (linestart, pointer);

		// Make pointer line ...
		int i = 0;
		for (p = lineout; p < pointer; p++) string[i++] = '-';
		string[i] = 0;

		printf ("\n%s(%d) : %s, %s\n", path, T->line, msg, lineout);
		printf (  "%s(%d) : %s, %s^ ", path, T->line, msg, string);

      if (*T->start > 32)
      {
         c = *T->end;
         *T->end = 0;
         printf ("at %s %s\n", T->start, symb);
         *T->end = c;
      }
      else
      {
         int x = *T->start;
         if (x < 0) x += 256;
         printf ("at %d %s\n", x, symb);
      }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::init_symtab (int max_symb)
{
      int i;
		max_symbols   = max_symb;
		max_cells     = 2*max_symbols;
		ALLOC (symbol,  max_symbols);
      ALLOC (hashvec, max_cells);
      hashdiv       = UINT_MAX / max_cells + 1;
      n_symbols	  = 0;
      if (hashvec == NULL)
      {
			printf ("Not enough memory available for Symbol Table.\n\n");
         Quit ();
      }
		else
		{
	      for (i = 0; i < max_cells; i++) hashvec[i] = -1;
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::term_symtab ()
{
      if (symbol != NULL) delete [] symbol;
      if (symbol != NULL) delete [] hashvec;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::add_symbol (char* token_start, char* token_end, int type, int line)
{
      char*p;
		sti = get_symbol (token_start, token_end, type);
		if (sti < 0)
		{
			sti = n_symbols;
			if (n_symbols >= max_symbols)				   // Reached maximum number?
			{
            MemCrash ("Number of symbols", max_symbols);
				Quit ();
			}
			hashvec[cell] = n_symbols;					   // Put symbol number into hash vector.
         p = ALLOC (p, length+1);                  // Allocate space for text string.
         memcpy (p, token_start, length);	         // Move string to allocated space.
         *(p+length) = 0;                          // Padd with zero byte.
         symbol[n_symbols].name     = p;           // Define pointer to symbol name.
         symbol[n_symbols].original = 0;           // Define pointer to original name.
         symbol[n_symbols].start    = token_start; // Define pointer to symbol start address in source code.
			symbol[n_symbols].line     = line;			// Define line number in grammar.
			symbol[n_symbols].type     = 0;  			// Don't define type.
			symbol[n_symbols].numb     = -1;			   // Define sequence number as -1 (undefined).
			symbol[n_symbols].value    = -1;				// Define value as undefined.
			symbol[n_symbols].length   = length;		//	Define symbol length.
			symbol[n_symbols].origleng = 0;				//	Define original length.
			n_symbols++;									   // Increment number of symbols.
		}
      return (sti);									      // Return symbol-table index.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::rename_symbol (short sti, int gen_numb)
{
      char*p;
      p = ALLOC (p, 8);									// Allocate space for text string.
		sprintf (p, "$%05d", gen_numb);
      *(p+6) = 0;											// Padd with zero byte.
      symbol[sti].original = symbol[sti].name;	// Save original name.
      symbol[sti].name     = p;             		// Define pointer to symbol name.
      symbol[sti].origleng = symbol[sti].length;// Save original length.
		symbol[sti].length   = 6;		   			//	Define symbol length.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_Parser::get_symbol (char* token_start, char* token_end, int type)
{
		int len;
		if (token_start == 0) return 0;
      char* p = token_start;		    	         // Point at start.
      char* q = token_end;			 	            // Point at end.
      length = (short)(q-p);       				   // Get length.
      uint hash = length;         	   		   // Set hash to length.
      int i = 0;						   			   // Set shift value to 0.
      do									      		   // Assume length != 0
      {
         hash += *p << i;
         i += 4;
         i %= 32;
      }
      while (++p < q);
      cell = hash % max_cells; 					   // Get first cell.
		i = hashvec [cell];				   		   // Get symbol index.
      if (i >= 0)
		{
         p = token_start;				            // Point at token start.
			do
			{
				if (symbol[i].origleng != 0)
					  len = symbol[i].origleng;
				else len = symbol[i].length;
				if (len == length && symbol[i].type & type) // Length and type match?
				{
					if (symbol[i].original != 0)
						  q = symbol[i].original;		// Point at original name.
					else q = symbol[i].name;			// Point at symbol name.
					short j = 0;
					do
					{
						if (p[j] != q[j]) goto Cont;	// If characters not equal ...
					}
					while (++j < length);				// while end not reached.
					return (i);								// Found it.
				}
Cont:			cell = (hash *= 65549) / hashdiv;	// Get new cell number.
				i = hashvec [cell];					   // Get symbol index.
			}
			while (i >= 0);      					   // While not empty slot.
		}
      return (i);										   // Return symbol number.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::print_symtab (char** term_symb)
{
		/* Nothing */
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PG_Parser::symname (int i)
{
      static char name[2000];
      char* p;
      short L;

		if (i == 0)
		{
			name[0] = 0;
			return name;
		}

      p = symbol[i].name;
      L = symbol[i].length;

      if (L >= 2000)
      {
	      for (i = 0; i < 100; i++) name[i] = p[i];
		   name[i] = 0;
			prt_log ("Symbol length of %d is too big (>= 2000).\n", L);
			prt_log ("for '%s'\n.", name);
         Quit ();
      }
      for (i = 0; i < L; i++) name[i] = p[i];
      name[i] = 0;
      return name;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//																										                     //
//    ABSTRACT-SYNTAX-TREE FUNCTIONS

/*    static uchar numeric[256] = // numeric[x] gives 1..10 for digits 0..9
      {
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
      };
*/
		char draw_plus [] = "+ ";
		char draw_vbar [] = "| ";
		char draw_last [] = "+ ";
		char draw_space[] = "  ";

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::init_ast ()
{
	  	root = (Node*)ALLOC (node, 1);
      root->id     = -1;  // Undefined.
      root->numb   = 0;
      root->prod   = 0;
      root->sti    = 0;
		root->oper   = 0;
		root->line   = 0;
      root->next   = NULL;
      root->prev   = NULL;
      root->child  = NULL;
      root->parent = NULL;

		ebnf = (Node*)ALLOC(node, 1);
		ebnf->id     = -1;  // Undefined.
		ebnf->numb   = 0;
		ebnf->prod   = 0;
		ebnf->sti    = 0;
		ebnf->oper   = 0;
		ebnf->line   = 0;
		ebnf->next   = NULL;
		ebnf->prev   = NULL;
		ebnf->child  = NULL;
		ebnf->parent = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::term_ast ()
{
   //	delete [] node; Should delete all nodes.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::print_ast ()
{
		if (n_nodes > 1)
			print_ast (root);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::print_ast (Node* n) // Print subtree.
{
		#ifdef _DEBUG
      char indent [512];
		strcpy (indent, draw_space);
		printf ("\nAbstract Syntax Tree ...\n\n");
		if (n != 0)
		{
			printf ("   node   prev   next parent  child   line    sti \n");
			traverse (indent, n); // Start AST traversal.
		}
		else printf ("   Tree is empty.\n\n");
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::traverse (char *indent, Node* n)
{
      while (n->next != 0)
      {
         strcat (indent, draw_plus);
         print_node (indent, n);
         indent [(int)strlen(indent)-2] = 0;
         if (n->child != 0)
         {
            strcat (indent, draw_vbar);
            traverse (indent, n->child);
            indent [(int)strlen(indent)-2] = 0;
         }
         n = n->next;
      }

      strcat (indent, draw_last);
      print_node (indent, n);
      indent [(int)strlen(indent)-2] = 0;
      if (n->child != 0)
      {
         strcat (indent, draw_space);
         traverse (indent, n->child);
         indent [(int)strlen(indent)-2] = 0;
      }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::print_node (char *indent, Node* n) /* Print this node function. */
{
      int i;
      int sti    = n->sti;
		int numb   = n->numb;
		int line   = n->line;
		int prev   = 0;
		int next   = 0;
		int parent = 0;
		int child  = 0;
		if (n->prev)   prev   = n->prev->numb;
		if (n->next)   next   = n->next->numb;
		if (n->parent) parent = n->parent->numb;
		if (n->child)  child  = n->child->numb;

		char oper = oper_char (n);

		printf (" %6d %6d %6d %6d %6d %6d %6d %s%s",
			numb,
  			prev,
  			next,
  			parent,
  			child,
		  	line,
			sti,
			indent,
			node_name[n->id]);

		if (sti != 0) // zero means no symbol.
		{
			int L;
			char* q;
			char string[100];
			if (sti > 0) // a symbol found in the input file?
			{
				q = symbol[sti].name;
				L = symbol[sti].length;
			}
			else // a terminal symbol of the grammar!
			{
				q = (char*)term_symb[-sti];
				L = (int)strlen((const char*)q);
			}
			if (L > 99) L = 99;
			for (i = 0; i < L; i++, q++) // Replace '\n' with \1
			{
				if (*q == '\n') string[i] = 1; // one = happy face.
				else            string[i] = *q;
			}
			string[i] = 0;
			printf (" %s", string);
		}
		printf (" %c", oper);
		printf ("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::traverse ()
{
	  	if (n_nodes > 1) // Any nodes in the tree?
		{
         if (n_nodeactions > 0) // Any PG_Parser actions in the parser?
			{
  				traverse (root);	// Start PG_Parser traversal.
			}
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_Parser::traverse (Node* np)
{
		int na;		 // Mode action.
		Node* cp;	 // Child pointer.
		na = np->id;
		if (na >= 0)
		{
			direction = TOP_DOWN;
			(*nact_func[na]) (np);
		}
    	cp = np->child;
      while (cp != NULL)
		{
    	   traverse (cp);
			cp = cp->next;
		}
		if (na >= 0)
		{
			direction = BOTTOM_UP;
			(*nact_func[na]) (np);
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

short PG_Parser::emitstr (Node* np, char* str)
{
      short sti;
      int   i, x;
      char  string[1000];
      char  *symb, *s, *p;

   // Get symbol from node.
      sti  = np->sti;
		if (sti < 0) symb = term_symb[-sti];
      else         symb = symname(sti);

   // Scan string for &-codes ...
      p = str;
      s = string;
      while (1)
      {
         *s = *p;
         if (*s == 0)
         {
				prt_warn (string, symb);
            return (0);
         }
         if (*s == '&') // &-code ?
         {
            if (numeric[*++p]) // number ?
            {
               x = *p - '0';
               while (numeric[*++p]) x = 10*x + *p - '0';
               i = stacki - x;
               if (i < 0) *s++ = '?'; // Error.
               else
               {
                  switch (*p)
                  {
                     case 'c':
							s += sprintf (s, "%d", stack[i].counter); // Get counter.
                     p++;
                     break;

                  // case 'n':
						//	s += sprintf (s, "%s", node_name[stack[i].id]); // Get node name.
                  // p++;
                  // break;

                     default:
							s += sprintf (s, "%d", stack[i].counter); // Get counter.
                     break;
                  }
               }
            }
            else s++;
         }
         else { s++; p++; }
      }
		return (0);
}

//																																   //
/////////////////////////////////////////////////////////////////////////////////////////////////////

