
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Parser Code

      #include "string.h"
		#include "main.h"

	  	#define  UINT_MAX  0xffffffff
	  	#define  INT_MAX   0x7fffffff
		#define  EOF_CHAR          26
      #define  FAILURE            0
		#define  STKSIZE          100			// Parser-stack size.
        

	// Parser variables ...
		char		PARSER::path[256];			// Path of input file.
      PStack	PARSER::PSstart[STKSIZE];	// Parser stack.
		PStack*  PARSER::PS;                // Parser stack pointer.
		int      PARSER::n_nodes;				// Number of nodes in AST.
		int      PARSER::n_symbols;			// Number of symbols in symbol table.

	// Expecting list variables ...
      RStack*	PARSER::RS;
      RStack	PARSER::RSstart[STKSIZE];
		uchar*   PARSER::T_exp;
		uchar*   PARSER::S_exam;

	// Symbol-table variables ...
		Symbol*	PARSER::symbol;
		uint		PARSER::hashdiv;				// Hash divisor.
		int*		PARSER::hashvec;				// Hash vector.
		int		PARSER::max_cells;			// Maximum number of cells in the hash vector.
		int		PARSER::max_symbols;			// Maximum number of symbols.

	// Look-ahead parsing variables ...
		#ifdef ND_PARSING
      int		PARSER::LA;							// Look Ahead token.
		int      PARSER::last_line;				// Last line from previous ND start.
		int      PARSER::n_warnings;				// Number of warnings.
  		SStack*	PARSER::SS      [ND_THREADS];	// State stack pointer.
      SStack*	PARSER::SSstart [ND_THREADS];	// State stack.
      int		PARSER::State   [ND_THREADS];	// State.
      int		PARSER::Action  [ND_THREADS];	// Action.
      int 		PARSER::Parsed  [ND_THREADS];	// Parsed (0 or 1).
		int      PARSER::LAcount [LOOKAHEADS+1];
		#endif

	// AST variables ...
		#ifdef MAKE_AST
		Node*		PARSER::root;				// Current root node.
		Node*		PARSER::node;				// Current PARSER node.
		int      PARSER::max_nodes;		// Maximum number of nodes in PARSER.
		int*		PARSER::counter;			// Node counter array.
		Node*		PARSER::nodearea;			// Node area or Node block allocated.
		char		PARSER::indent[256];		// Indentation for printing current node.
		int	  	PARSER::traversal;		// PARSER traversal number: 1, 2, 3 ...
		int		PARSER::direction;		// Node direction: TOP_DOWN, BOTTOM_UP.
		Stack*   PARSER::stack;				// PARSER stack array.
		int		PARSER::stacki;			// PARSER stack index.
		char		PARSER::draw_plus[3];
		char		PARSER::draw_vbar[3];
		char		PARSER::draw_last[3];
		char		PARSER::draw_space[3];
		#endif

	// lowercase[x] is x.
		#ifdef INSENSITIVE
		uchar lowercase[256] =
		{
			  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
			 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
			 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
			 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
			 64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
			112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95,
			 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
			112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,

			128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
			144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
			160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
			176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
			192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
			208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
			224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
			240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
		};
		#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::init_parser (char* patharg, char* input_start, int max_syms, int max_nodes)
{
		#ifdef ND_PARSING
		for (int i = 0; i < ND_THREADS; i++)
		{
			SSstart[i] = new SStack[STKSIZE];
		}
		for (int i = 0; i < LOOKAHEADS + 1; i++)
		{
			LAcount[i] = 0;
		}
		last_line = 0;
		n_warnings = 0;
		#endif

		strcpy (path, patharg);
      PS           = PSstart;					// Set parse-stack pointer.
      n_errors     = 0;							// Set number of errors.
		n_nodes      = 0;							// In case of no PARSER creation.

      init_lexer (input_start, 3);			// Initialize the lexer.
		init_symtab (max_syms);					// Initialize the symbol table.

		#ifdef MAKE_AST
		init_ast (max_nodes);					// Initialize the PARSER.
		#endif

		#ifdef ACTIONS
		(*init_func[0])();						// init_action()
		#endif

		T_exp  = new uchar[n_terms];
		S_exam = new uchar[n_states];

		memset (T_exp,  0, n_terms);
		memset (S_exam, 0, n_states);
		return 1; // Return OK.

Err:  n_errors++;
      return 0;

		goto Err; // Stops compiler from complaining.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::term_parser ()
{
		#ifdef MAKE_AST
		term_ast ();
		#endif
		term_symtab ();
		#ifdef ACTIONS
		(*init_func[1])();						// term_action()
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//		LR Parser

int   PARSER::parse ()
{
      int x, t, T, p;
		x = 0;														// State = 0 to start.
Read:	T = t = get_token ();									// Get incoming token.
		#ifdef TERM_ACTIONS
		if (tact_numb[t] >= 0)									// If token action ...
			token.sti = (*tact_func[tact_numb[t]]) (t);	// Call token-action function.
		#else
			token.sti = -t;
		#endif
		#ifdef EXPECTING
		RS = RSstart;
		RS->state = x;
		RS->ptr = PS;
		#endif

Test: if (Bm [Br[x] + Bc[t]] & Bf[t])					// Check B-matrix for shift action.
      {
         PS++;
         PS->state = x;                       		// Put current state on stack.
			PS->sti   = token.sti;             			// Put symbol-table index on stack.
			#ifdef MAKE_AST
         PS->line  = token.line;                  	// Put line number on stack.
			PS->start = token.start;                 	// Put start address on stack.
			PS->node  = 0;						         	// Set node on stack to zero.
			#endif
			#ifdef EXPECTING
			PS->sym   = -t;                           // Put symbol on stack.
			#endif
			x = Tm [Tr[x] + Tc[t]];                	// Get next state from terminal transition matrix.
         while (x < 0)                          	// While shift-reduce actions.
         {
	     		p = -x;
SR:         PS -= PL[p];									// Reduce stack ptr by production length.
				#ifdef EXPECTING
				PS->sym = head_numb[p];                // Put symbol on stack.
				#endif
				reduce (p);										// Call reduce action with production number.
            x = Nm [Nr[PS->state] + Nc[p]];			// Get next state from nonterminal transition.
         }
         goto Read;								         // Go to read next token.
      }
		if ((p = Rr[x]) > 0									// Default reduction 90% of the time.
		||  (p = Rm[Rc[t] - p]) > 0)						// Compute reduction?
      {
Red:     PS -= PL[p];										// Reduce parse stack ptr by rule length - 1.
         if (PL[p] < 0)							         // Null production?
         {
				#ifdef EXPECTING
				RS++;
				RS->ptr   = PS;
				RS->state = PS->state;
				RS->sym   = PS->sym;
				#endif
            PS->state = x;						         // Stack current state, replacing old state.
				#ifdef MAKE_AST
				PS->node  = 0;						        	// Set node on stack to zero.
				#endif
			}
         while (1)
         {
				#ifdef EXPECTING
				PS->sym = head_numb[p];                // Put symbol on stack.
				#endif
				reduce (p);										// Call reduce action with production number.
            x = Nm [Nr[PS->state] + Nc[p]];	      // Get next state from nonterminal transition.
            if (x > 0) goto Test;				      // Continue parsing.
            p = -x;								         // Set production number.
            PS -= PL[p];                           // Reduce parse stack ptr by rule length - 1.
			}
		}
		#ifdef ND_PARSING
		int  y;
		uint i, j, na;
		for (i = nd_fterm[x]; i < nd_fterm[x+1]; i++)	// For all ND terminals in this state.
		{
			if (nd_term[i] == t)								//	Got a match?
			{
				j = nd_faction[i];							// Start of actions.
				na = 0;											// Number of actions.
				do
				{
					State[na] = x;								// Copy this state.
					Action[na++] = nd_action[j];			// Copy this action.
				}
				while (++j < nd_faction[i+1]);			// While there's more.
				y = nd_parser (x,t,na);						// ND lookahead parser.
				if (y > 0)										// Shift?
				{
					PS++;											// Increment parser stack pointer.
					PS->state = x;								// Put current state on stack.
					PS->sti   = token.sti;           	// Put symbol table index on stack.
					#ifdef MAKE_AST
					PS->line  = token.line;            	// Put line number on stack.
					PS->start = token.start;            // Put start address on stack.
					PS->node  = 0;						     	// Set node on stack to zero.
					#endif
					if (y > accept_state)					// Shift and reduce action?
					{
						p = y - accept_state;				// Shift and reduce.
						goto SR;									// Go to shift reduce.
					}
					#ifdef EXPECTING
					PS->sym = -t;								// Put symbol on stack.
					#endif
					x = y;										// Shift and goto.
					goto Read;									// Go to read another token.
				}
				if (y < 0)										// Reduce ?
				{
					p = -y;										// Reduce action.
					goto Red;									// Go to reduce.
				}
			}
		}
		#endif
      if (x == accept_state)								// If Goal production.
      {
			PS -= PL[p];										// Reduce parse stack ptr by rule length - 1.
			reduce (p);											// Call reduce action with production number.
			#ifdef ND_PARSING
			print_lookaheads();								// Print lookahead statistics.
			#endif
			print_symtab ();									// Print the symbol table contents.
			#ifdef MAKE_AST
			find_root (PS[0].node);
			print_ast ();
			traverse	(FIRST_PASS);
			#endif
			#ifdef DEBUG_PARSER
			fprintf (output, "\nDone.\n\n");
			#endif
			return linenumb-1;								// Success.
      }
		#ifdef EXPECTING
		x = restore ();
		if (t != 0)
		{
			t = 0;											   // Try <error>
			goto Test;
		}
		#endif
		if (n_errors < INT_MAX)								// Error message not printed?
		{
			#ifdef EXPECTING
			print_stack ();
			#endif
			syntax_error ("Error", &token, term_symb[T]);
			#ifdef EXPECTING
			expecting (x);
			print_terms (x);
			#endif
		}
   	return -linenumb; // Failure.

		goto SR;  // Stops compiler from complaining.
		goto Red; // Stops compiler from complaining.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::reduce (int p)
{
		#ifdef SEMANTICS
		if (argy[p] >= 0)
		{
			symbol[PS[0].sti].term = argy[p];
		}
		#endif
		#ifdef MAKE_AST
		int psi;	 														// Parse stack index.
		if (node_numb[p] >= 0)   									// MAKE NODE ?
		{
			Node* n   = new_node ();								// Get a new node.
			n->id     = node_numb[p];								// Set node id number.
			n->prev   = 0;												// Set prev to nonexistent.
			n->next   = 0;												// Set next to nonexistent.
			n->child  = 0;												// Set child to nonexistent.
			n->parent = 0;												// Set parent to nonexistent.
			if (argx[p] >= 0)	   			   					// If first argument specified.
			{
				psi      = argx[p];	   							// Get parse-stack index.
				n->sti   = PS[psi].sti;								// Move sti from parse stack to node.
				n->line  = PS[psi].line;							// Move line from parse stack to node.
				n->start = PS[psi].start;							// Move start from parse stack to node.
			}
         else // No argument on production.
         {
			   n->sti   = 0;    										// Set symbol-table index to zero.
			   n->line  = 0;    										// Set line number to zero.
				n->start = 0;
         }
			psi = linkup(p);									      // Linkup the nodes in this rule.
			if (psi >= 0)										      // Any nodes found in this rule?
			{
				n->child = PS[psi].node;							// Define child.
				PS[psi].node->parent = n;							// Define parent.
			}
			PS[0].node = n;											// Define this node in the parse stack.
			PS[0].last = n;											// Define this node in the parse stack.
		}
		else	                                             // Check for nodes not linked?
		{
			psi = linkup (p);                               // Get parse-stack index.
		  	if (psi > 0)                                    // If we have a node here ...
			{
			  	PS[0].node = PS[psi].node;		               // Move node to 1st position.
			  	PS[0].last = PS[psi].last;		               // Move last also.
			}
		}
		#endif
}

#ifdef ND_PARSING

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::nd_parser (int x, int t, int na)
{
	  	int  i;
		int  la;					// Lookaheads to try.
		int  total;				// Total number parsed.
		int  limit;				// Lookahead limit.
		char string[64];

		#ifdef DEBUG_PARSER
		if (token.line > last_line) printf ("\n");
		last_line = token.line;
		sprintf (string, "In state %d", x);
		printf ("/////////////////////////////////////////////////////////////////////////////////////////////////////\n");
		syntax_error (string, &token, term_symb [t]);
		printf ("\n   STARTED LR(*) parsing for the following choices:\n\n");
		print_actions (na);
		n_warnings++;
		#endif

	// COPY PARSE STACK TO ND STATE STACK FOR EACH ACTION ...
		for (i = 0; i < na; i++)
      {
         SS[i] = SSstart[i];
         for (PStack* P = PSstart; P < PS;)
         {
            (++SS[i])->state = (++P)->state;
         }
			Parsed[i] = 1;
      }

	//	TRY TO ACCEPT LOOKAHEAD TOKENS ...
		LA = t;
		total = 0;
		la = 0;
		i = 0;
		do
		{
			if (Parsed[i] > 0)
			{
				total += Parsed[i] = nd_parser_la (i,la);
			}
		}
		while (++i < na);

	// ONE ACTION SUCCEEDED ? ...
   	if (total == 1)
		{
			LAcount[1]++;
			#ifdef DEBUG_PARSER
			n_warnings = 0;
			#endif
			i = 0;
			do
			{
				if (Parsed[i] > 0)
				{
					#ifdef DEBUG_PARSER
					printf ("   CHOOSING ");
					print_action ("", i);
					printf ("\n");
					#endif
					return Action[i];
				}
			}
			while (++i < na);
		}

		lookahead.end = token.end; // Prime get_lookahead().
		lookahead_linenumb = linenumb;
		limit = LOOKAHEADS;
		la = 1;
		do
      {
         total = 0;
			LA = get_lookahead();
			#ifdef TERM_ACTIONS
			if (tact_numb[LA] >= 0)						// If term action ...
				(*tact_func[tact_numb[LA]]) (LA);	// Call term-action function.
			#endif
			if (LA == eof_symb) limit = la; // <eof> ?
         i = 0;
			do
         {
				if (Parsed[i] > 0)
				{
					total += Parsed[i] = nd_parser_la (i,la);
				}
         }
			while (++i < na);

		// ONE ACTION SUCCEEDED ? ...
   		if (total == 1)
			{
				LAcount[la+1]++;
				#ifdef DEBUG_PARSER
				n_warnings = 0;
				#endif
				i = 0;
				do
				{
					if (Parsed[i] > 0)
					{
						#ifdef DEBUG_PARSER
						printf ("   CHOOSING ");
						print_action ("", i);
						printf("\n");
						#endif
						lookahead.start = 0; // Stop lookahead mode in lookup().
						return Action[i];
					}
				}
				while (++i < na);
			}

		// TOKEN NOT ACCEPTED, SYNTAX ERROR ...
		  	if (total == 0)
			{
				if (n_warnings == 0)
				{
					syntax_error ("Error", &lookahead, term_symb[LA]);
					printf ("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n", la+1);
					print_actions(na);
				}
				else printf ("\n   AMBIGUITY after %d lookaheads, cannot make a decision.\n", la+1);
				n_errors = INT_MAX; // No more error messages.
				return FAILURE;
			}
		}
		while (++la < limit);

	// TRIED ALL LOOKAHEADS, STILL AMBIGUOUS ...
		LAcount[limit]++;
		if (Action[0] > 0) // Shift action?
		{
			#ifdef DEBUG_PARSER
			printf("\n   AMBIGUITY after %d lookaheads, choosing the Shift action.\n", limit);
			printf("\n");
			n_warnings = 0;
			#endif
			lookahead.start = 0; // Stop lookahead mode in lookup().
			return Action[0];
		}

   // Some parsers choose the lowest numbered reduction.
	// Not a good idea, because the grammar is ambiguous.
	// Fix the grammar or increase option /k, if necessary.
		#ifdef DEBUG_PARSER
		printf("\n   AMBIGUITY after %d lookaheads, unable to decide.\n", limit);
		#else
	  	sprintf (string, "In state %d", x);
	  	syntax_error (string, &token, term_symb[t]);
		printf ("\n   AMBIGUITY after %d lookaheads, unable to choose from:\n\n", limit);
		print_actions (na);
		#endif
		n_errors = INT_MAX; // No more error messages.
		return FAILURE;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PARSER::print_actions (int na)
{
		int i = 0;
		do
		{
			print_action ("   * ", i);
		}
		while (++i < na);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PARSER::print_action (char* str, int i)
{
		printf (str);
		int y = Action[i];
		if (y > 0)
		{
			printf ("Shift %s and ", symbol_name (token.sti));
			if (y > accept_state)			   // Shift and reduce ?
			{
				int p = y - accept_state;	   // Convert to production number.
				print_prod ("reduce", p, -1);
			}
			else printf ("goto %d\n", y);
		}
		else
		{
			print_prod ("Reduce", -y, 0);
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::nd_parser_la (int i, int la)				// ND LA Parser.
{
      int p;														// Production (rule).
      if (la == 0) // LA is first one?
      {
     	   if (Action[i] > 0)									// Shift and goto action?
		   {
            SS[i]++;
            SS[i]->state = State[i];						// Put State stack.
				if (Action[i] > accept_state)					// Shift and reduce?
				{
					State[i] = accept_state - Action[i];	// Convert to production number.
					goto SR;
				}
				State[i] = Action[i];							// Get next state.
				return 1;
		   }
	      p = -Action[i];										// Get production.
	      goto Red;												// Reduce.
      }

Shft: if (Bm [Br[State[i]] + Bc[LA]] & Bf[LA])			// Check B-matrix for shift action.
      {
         SS[i]++;
         SS[i]->state = State[i];							// Put current state on stack.
         State[i] = Tm [Tr[State[i]] + Tc[LA]];			// Get next state from terminal transition matrix.
         while (State[i] < 0)									// While shift-reduce actions.
         {
SR:         p = -State[i];
				SS[i] -= PL[p];									// Reduce stack ptr by production length.
            State[i] = Nm [Nr[SS[i]->state] + Nc[p]];	// Get next state from nonterminal transition matrix.
         }
         return 1;												// Return success.
      }

		if ((p = Rr[State[i]]) > 0 							// Default reduction?
		||  (p = Rm [Rc[LA] - p]) > 0)						// Compute reduction?
      {
Red:		SS[i] -= PL[p];										// Reduce parse stack ptr by rule length - 1.
         if (PL[p] < 0)	SS[i]->state = State[i];		// Stack current state.
         while (1)
         {
   		   State[i] = Nm [Nr[SS[i]->state] + Nc[p]];	// Get next state from nonterminal transition.
            if (State[i] > 0) goto Shft;					// If a state, continue parsing.
            p = -State[i];										// Make the production number positive.
            SS[i] -= PL[p];									// Reduce parse stack ptr by rule length - 1.
         }
      }

		if (State[i] == accept_state)	return 1;

	// LOOK FOR A SHIFT ACTION FOR THIS TOKEN ...
		for (uint j = nd_fterm [State[i]]; j < nd_fterm [State[i]+1]; j++)
		{
			if (nd_term[j] == LA)
			{
				uint k = nd_faction[j];
				if (nd_action[k] > 0)								// Shift action (always first one)?
				{
					SS[i]++;
					SS[i]->state = State[i];						// Put State on stack.
					if (nd_action[k] > accept_state)				// Shift and reduce?
					{
						State[i] = accept_state - nd_action[k];// Convert to production number.
						goto SR;
					}
					State[i] = nd_action[k];
					return 1;
				}
				#ifdef DEBUG_PARSER
			// A recursive call to nd_parse() is needed to continue the ND lookahead parsing.
			// This version of the LR(*) algorithm does not support 2nd, 3rd or more depths of
			//	recursion.  Probably the grammar has ambiguity that needs to be resolved.
				n_warnings++;
				char string[16];
				sprintf (string, "In state %d", State[i]);
				if (la == 0)
					  syntax_error (string, &token,     term_symb[LA]);
				else syntax_error (string, &lookahead, term_symb[LA]);
				printf ("\n   STOPPED LR(*) parsing after %d lookaheads, for conflicting actions:\n\n", la+1);
				do
				{
					print_prod ("   * Reduce", -nd_action[k], 0);
				}
				while (++k < nd_faction[j+1]);
				print_action ("\n   IGNORING ", i);
				#endif
				return 0;
			}
		}
		#ifdef DEBUG_PARSER
		char string[16];
		sprintf (string, "In state %d", State[i]);
		if (la == 0)
			  syntax_error (string, &token,     term_symb[LA]);
		else syntax_error (string, &lookahead, term_symb[LA]);
		print_action ("\n   IGNORING ", i);
		#endif
		return 0; // Did not find a match for LA in this state.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PARSER::print_lookaheads()
{
	  	int n = 0;
		for (int i = 0; i <= LOOKAHEADS; i++)
		{
			if (LAcount[i] != 0)
			{
				char* msg;
				if (n++ == 0) printf ("\n");
				if (LAcount[i] == 1) msg = "time";
				else                 msg = "times";
				if (i == 1)
					  printf  ("      %3d Lookahead  needed: %6d %s\n", i, LAcount[i], msg);
				else printf  ("      %3d Lookaheads needed: %6d %s\n", i, LAcount[i], msg);
			}
		}
}

#endif ND_PARSING

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::restore ()
{
 		while (RS > RSstart)   // Restore PS, RS and states.
      {
         RS->ptr->state = RS->state;	// Reset state to saved state.
         RS->ptr->sym   = RS->sym;	   // Reset symbol to saved symbol.
			RS--;
      }
		PS = RS->ptr;
		return RS->state;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::syntax_error (char *msg, Token* T, char* symb)
{
      char  c;
		char* p;
      char* lineout;
      char* pointer;
      char* linestart;
      char  string[256];

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

void  PARSER::expecting (int x)
{
		int t;													// Terminal number.
		S_exam[x] = 1;											// Mark this state as seen.
     	for (t = 0; t < n_terms; t++)						// For all terminals.
		{
			if (Bm [Br[x] + Bc[t]] & Bf[t])				// Check B-matrix for shift action.
			{
            T_exp[t] = 1;                          // Mark this terminal.
			}
		}
		#ifdef ND_PARSING
		uint i, j;
     	for (i = nd_fterm[x]; i < nd_fterm[x+1]; i++)		// For all terminals in this state.
		{
			for (j = nd_faction[i]; j < nd_faction[i+1]; j++)	// For all actions for these terminals.
			{
				if (nd_action[j] > 0)								// Terminal transition.
				{
					T_exp[nd_term[i]] = 1;							// Mark this terminal.
				}
				else if (nd_action[j] < 0)
				{
					int p = -nd_action[j];
					reduction (p, x);
				}
			}
		}
		#endif
		int p, q;
		if ((p = Rr[x]) > 0)								// Default reduction?
		{
			reduction (p, x);
			return;
		}
		for (t = 0; t < n_terms; t++)					// For all terminals.
		{
			q = Rm [Rc[t] - p];							// Reduction for this terminal.
			if (q > 0)										// If not zero production?
			{
				reduction (q, x);
			}
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::reduction (int q, int x)
{
	// Save parse stack pointers.
		RStack* RSx = RS;						// Reset restore-stack pointer.
		PStack* PSx = PS;						// Save parse-stack pointer.

		PS -= PL[q];							// Reduce parse stack ptr by rule length - 1.
		if (PL[q] < 0)                   // Null production?
		{
			(++RS)->ptr = PS;					// Save parse-stack pointer.
			RS->state = PS->state;			// Save old state before replacing it.
			PS->state = x;						// Stack current state, replacing old state.
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
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::print_terms (int state)
{
		printf ("\n");
		if (state >= 0)
		{
			printf ("In state%5d, ", state);
		}
		printf ("Expecting one of the following:\n\n");

      int t, x;
		int* seq = new int [n_terms];
		sort_terms (seq);

		for (t = 0; t < n_terms; t++)
      {
			x = seq[t];
      // if (x == eof_symb) continue;
         if (T_exp[x] == 1)
         {
				if (term_symb[x][0] == '<' ||  term_symb[x][0] == '{')
            {
       	      printf ("         %4d %-30s\n", x, term_symb[x]);
            }
         }
      }
		for (t = 0; t < n_terms; t++)
      {
			x = seq[t];
         if (x == eof_symb) continue;
         if (T_exp[x] == 1)
         {
				if (term_symb[x][0] != '<' &&  term_symb[x][0] != '{')
            {
       	      printf ("         %4d %-30s\n", x, term_symb[x]);
            }
         }
      }
		delete [] seq;
}

////////////////////////////////////////////////////////////////////////////////

void  PARSER::sort_terms (int* seq)
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

void	PARSER::print_prod (char* prefix, int p, int dot)
{
		char* symb;
		int len = f_tail[p+1] - f_tail[p];
		printf ("%s %4d %s -> ", prefix, p, head_symb [head_numb[p]]);
		for (int i = f_tail[p]; i < f_tail[p+1]; i++)
		{
			int s = tail[i];
			if (s >= 0) symb = term_symb[ s];
			else        symb = head_symb[-s];
			if (len++ == dot) printf (". ");
			printf ("%s ", symb);
		}
		if (len == dot) printf (". ");
		printf ("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void	PARSER::print_stack () // Print parser stack.
{
		#ifdef DEBUG_PARSER
		printf ("\nParse stack:\n");
		for (PStack* ps = PSstart + 1; ps <= PS; ps++)
		{
			char *name, *name2;
			int sym = ps->sym;
			if (sym <= 0) // Terminal?
			{
				name  = term_symb[-sym];
				name2 = "";
				if (*name == '<' || *name == '{')
				{
					if (ps->sti > 0) name2 = symbol_name (ps->sti);
				}
				printf ("   state%5d %4d %s %s\n",  ps->state, -sym, name, name2);
			}
			else // Nonterminal.
			{
				name = head_symb[sym];
				printf ("   state%5d %4d %s\n", ps->state, sym, name);
			}
		}
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int	PARSER::init_symtab (int max_symb)
{
      int i;
		if (max_symb <= 0)
		{
			printf ("Maximum number of symbols cannot be zero or negative.\n");
         quit (1); // Failure.
		}
		max_symbols = max_symb;
		max_cells   = 2*max_symbols;
		symbol      = new Symbol[max_symbols];
      hashvec     = new int[max_cells];
      hashdiv     = UINT_MAX / max_cells + 1;
      if (symbol == NULL || hashvec == NULL)
      {
			printf ("Not enough memory available for Symbol Table.\n");
			quit (1); // Failure.
		}
      for (i = 0; i < max_cells; i++)
		{
			hashvec[i] = -1;
		}
	// Define symbol[0] for symbol_name(sti=0).
		symbol[0].start = " "; // Pointer to blank.
		symbol[0].length = 0;  // Length of symbol.
		n_symbols = 1;						// 0 is reserved for null symbol.
		return 1; // Success.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::term_symtab ()
{
		n_symbols--;
      delete [] symbol;
      delete [] hashvec;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int	PARSER::add_symbol (int t, char* token_start, char* token_end)
{
      char* p = token_start;					 		// Point at start.
      int   length = (int)(token_end - p);		// Set length.
      uint  hash = length;         	   			// Set hash to length.
      int   i = 0;						   			// Set shift value to 0.
      do									      			// Assume length != 0
      {
			#ifdef INSENSITIVE
         hash += lowercase[*p] << i;
			#else
         hash += *p << i;
			#endif
         i += 4;
         i %= 32;
      }
      while (++p < token_end);
      int cell = hash % max_cells; 					// Get first cell.
		int sti  = hashvec [cell];				   	// Get symbol table index.
      while (sti >= 0) 									// Symbol exists?
		{
			if (symbol[sti].length == length)		// If lengths are equal ...
			{
				p = token_start;							// Point at token start.
				char* start = symbol[sti].start;
				char* end   = start + length;
				do
				{
					#ifdef INSENSITIVE
					if (lowercase[*p] != lowercase[*start]) goto Cont;
					#else
					if (*p != *start) goto Cont;		// If characters not equal ...
					#endif
					start++;
					p++;
				}
				while (start < end);						// while end not reached.
				return sti;									// Return sti.
			}
Cont:    cell = (hash *= 65549)/hashdiv;			// Get new cell number.
			sti  = hashvec[cell];							// Get symbol table index.
		}
	// NEW SYMBOL ...
		if (n_symbols >= max_symbols)					// Reached maximum number?
		{
			printf("\nNumber of symbols exceeds %d.\n\n", max_symbols);
			quit (1); // Failure.
		}
		sti = hashvec[cell] = n_symbols;				// Put symbol number into hash vector.
		symbol[sti].start   = token_start;			// Pointer to original location in input file.
		symbol[sti].length  = length;					// Length of symbol.
		symbol[sti].cell    = cell;					// Cell in the hash vector.
		symbol[sti].type    = 0;						// Type of symbol: int, char, float, short, ...
		symbol[sti].term    = t;						// Terminal number for lookup funciton.
		symbol[sti].scope   = 0;						// Scope: global, local, inner loop, ...
		n_symbols++;
		return sti;											// Return symbol table index.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::print_symtab ()
{
		#ifdef DEBUG_PARSER
		fprintf (output, "\nSymbol Table ...\n\n");
		if (n_symbols > 1)
		{
			fprintf (output, "   sti  leng  type     name                                terminal\n");
			for (int i = 1; i < n_symbols; i++)
			{
				fprintf(output, " %5d %5d %5d     %-30s %4d %s\n",
					i,
					symbol[i].length,
					symbol[i].type,
					symbol_name(i),
					symbol[i].term,
					term_symb[symbol[i].term]);
			}
		}
		else // No symbols in the table.
		{
			fprintf (output, "   Symbol Table is empty.\n");
		}
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PARSER::symbol_name (int sti)
{
		int i;
      char* p;
      static char name[256];
		if (sti < 0) // Terminal symbol?
		{
			p = (char*)term_symb[-sti];
			for (i = 0; p[i] != 0; i++)
			{
				if (i < 255) name[i] = p[i];
				else break;
			}
			name[i] = 0;
		}
		else // Input symbol or sti == 0.
		{
			int L;
			p = symbol[sti].start;
			L = symbol[sti].length;
			if (L > 255) L = 255;
			for (i = 0; i < L; i++)
			{
				name[i] = p[i];
			}
			name[i] = 0;
		}
      return name;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

char* PARSER::symbol_name (char* start, char* end)
{
      char *p, *q;
      static char name[256];
		if (end - start > 255) end = start + 255;
		p = start;
		q = name;
		do
		{
			*q++ = *p++;
		}
		while (p < end);
		*q = 0;
      return name;
}

#ifdef MAKE_AST

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::linkup (int p)
{
      int i;
      int next = -1;
		#ifdef REVERSABLE
      if (reverse[p] != 0)                               // IF NOT TO REVERSE THE ORDER.
      {
         for (i = 0; i <= PL[p]; i++)				         // For each tail pointer.
         {
            if (PS[i].node != 0)                          // If tail points to node.
            {
               if (next >= 0)                            // If one waiting.
               {
                  PS[i   ].last->next = PS[next].node;	// Define next node.
                  PS[next].node->prev = PS[i].last;		// Define previous node.
                  PS[i   ].last       = PS[next].last;   // Change last to next last.
               }
               next = i;									      // Next = Curr.
				}
			}
		}
      else                                               // REVERSE THE ORDER.
		#endif
      {
         for (i = PL[p]; i >= 0; i--)				         // For each tail pointer.
         {
            if (PS[i].node != 0)                          // If tail points to node.
            {
               if (next >= 0)                            // If one waiting.
               {
						PS[i   ].last->next = PS[next].node;	// Define next node.
                  PS[next].node->prev = PS[i   ].last;	// Define previous node.
                  PS[i   ].last       = PS[next].last;   // Change last to next last.
               }
               next = i;									      // Next = Curr.
				}
			}
		}
      return (next);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::tracer (Node* n)
{
		#ifdef DEBUG_TRACE
		#ifdef NODE_ACTIONS
		char* dir;
		if      (direction == TOP_DOWN ) dir = "*>";
		else if (direction == PASS_OVER) dir = "**";
		else                             dir = "<*";
		printf ("   %d %s %s (%s)\n", traversal, dir, node_name[n->id], symbol_name(n->sti));
		#endif
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PARSER::init_ast (int max)
{
		n_nodes   = 1;
		max_nodes = max;	// max_nodes to allocate as needed.
		nodearea  = new Node[max_nodes];
      if (nodearea == NULL)
      {
			printf ("Not enough memory available for %d PARSER nodes.\n", max_nodes);
         quit (1); // Failure.
      }
		node         =  new_node();
      node->id     = -1; // Undefined.
      node->sti	 =  0;
      node->line   =  0;
      node->start  =  0;
      node->next   =  0;
      node->prev   =  0;
      node->child  =  0;
      node->parent =  0;

		strcpy (draw_plus,  "+ ");
		strcpy (draw_vbar,  "| ");
		strcpy (draw_last,  "+ ");
		strcpy (draw_space, "  ");
      return 1; // Success.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::term_ast ()
{
		n_nodes--;
      delete [] stack;
      delete [] counter;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

Node* PARSER::new_node()
{
		if (n_nodes % max_nodes == 0) 						// Filled up nodearea?
		{
			nodearea = new Node[max_nodes];					// Get another nodearea.
			if (nodearea == NULL)								// Not got?
			{
				printf ("\nNot enough memory available for %d PARSER nodes.\n\n", max_nodes);
				quit (1); // Failure.
			}
		}
		Node* n = &(nodearea[n_nodes % max_nodes]);
		n_nodes++;
		return n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::find_root (Node* last_node)
{
		root = last_node;						// Define root node.
		if (root != 0)
		{
			while (root->prev != 0)			// In case of a list only.
			{
				root = root->prev;			// Go up the list to first node.
			}
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::print_ast ()
{
		#ifdef DEBUG_PARSER
		print_ast (root);
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::print_ast (Node* n) // Print subtree.
{
      char indent [512];
		strcpy (indent, draw_space);
		fprintf (output, "\nAbstract Syntax Tree ...\n\n");
		if (n != 0)
		{
			fprintf (output, "   sti  line   col  \n");
			traverse (indent, n); // Start PARSER traversal.
		}
		else
		{
			fprintf (output, "   PARSER is empty.\n");
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::traverse (int trav)
{
		#ifdef NODE_ACTIONS
	  	if (n_nodes > 1) // Any nodes in the tree?
		{
		  	if (n_nodeactns > 0) // Any node actions?
			{
				stacki  = -1;
				stack   = new Stack [STKSIZE];
				counter = new int [n_nodenames];
				for (int i = 0; i < n_nodenames; i++)
				{
					counter[i] = 0;
				}
				#ifdef DEBUG_PARSER
				fprintf (output, "\nDoing Tree Traversal ...\n\n");
				#else
				fprintf (output, "\n");
				#endif
				traversal = trav;
				Node* n = root;
				do
				{
  					traverse (n);
					n = n->next;
				}
				while (n != 0);
			}
		}
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::traverse (Node* n)
{
		#ifdef NODE_ACTIONS
		int   i  = n->id;					// Node id.
		Node* c  = n->child;				// Child nove pointer.
      stacki++;
      counter[i]++;
      stack[stacki].id = i;
      stack[stacki].counter = counter[i];
		if (nact_func[i] != 0) // Got a node action ?
		{
			direction = TOP_DOWN;
			tracer (n);
			(*nact_func[i]) (n);
		}
      while (c != 0)
		{
   	   traverse (c);
			c = c->next;
		/*	if (c != 0)
			{
				if (nact_func[i] != 0) // Got a node action ?
				{
					direction = PASS_OVER;
					tracer (n);
					(*nact_func[i])(n);
				}
			} */
		}
		if (nact_func[i] != 0) // Got a node action ?
		{
			direction = BOTTOM_UP;
			tracer (n);
			(*nact_func[i]) (n);
		}
      stacki--;
		#endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::traverse (char *indent, Node* n)
{
      while (n->next != 0)
      {
         strcat (indent, draw_plus);
         print_node (indent, n);
         indent [strlen(indent)-2] = 0;
         if (n->child != 0)
         {
            strcat (indent, draw_vbar);
            traverse (indent, n->child);
            indent [strlen(indent)-2] = 0;
         }
         n = n->next;
      }

      strcat (indent, draw_last);
      print_node (indent, n);
      indent [strlen(indent)-2] = 0;
      if (n->child != 0)
      {
         strcat (indent, draw_space);
         traverse (indent, n->child);
         indent [strlen(indent)-2] = 0;
      }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PARSER::print_node (char *indent, Node* n)
{
		int id  = n->id;
      int sti = n->sti;
		if (sti != 0) // zero means no symbol.
		{
			int line = n->line;
			char* p = n->start - 1;
			while (*p != '\n') p--;
			int col = (int)(n->start - p);

			fprintf (output, "  %4d  %4d  %4d  %s%s",	sti, line, col, indent, node_name[id]);

			if (sti > 0) // In the symbol table?
			{
				char* p = symbol[sti].start + symbol[sti].length;
				char ch = *p;
				*p = 0;
				fprintf (output, " (%s)\n", symbol[sti].start);
				*p = ch;
			}
			else // A terminal symbol of the grammar!
			{
				fprintf (output, " (%s)\n", term_symb[-sti]);
			}
		}
		else
		{
			fprintf(output, "     .     .     .  %s%s\n", indent, node_name[id]);
		}
}

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

