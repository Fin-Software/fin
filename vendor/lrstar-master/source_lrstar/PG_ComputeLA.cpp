
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
		#include "PG_ComputeLA.h"

      #ifdef _DEBUG
      #define PRINTF prt_con
      #else
      #define PRINTF prt_con
      #endif

		int    PG_ComputeLA::n_nditems;
		int    PG_ComputeLA::n_ndstates;
		int    PG_ComputeLA::n_ndterms;
		int*   PG_ComputeLA::nd_state;
	   int*   PG_ComputeLA::nd_item;
	   int*   PG_ComputeLA::nd_start;
		int*   PG_ComputeLA::nd_term;
		int*   PG_ComputeLA::nd_action;
		int    PG_ComputeLA::c_states;

		int*   PG_ComputeLA::D_red;
      int*   PG_ComputeLA::N_Conflicts;
		int*   PG_ComputeLA::la_start;
		int*   PG_ComputeLA::la_end;
		int*   PG_ComputeLA::la_symb;
		int*   PG_ComputeLA::la_red;

		int    PG_ComputeLA::n_lookbacks;
		int    PG_ComputeLA::n_lookah;
		int    PG_ComputeLA::n_includes;
      int    PG_ComputeLA::rr_con;
      int    PG_ComputeLA::sr_con;
      int    PG_ComputeLA::nd_maxcount;

      static char*  ntt_done;
      static int    top;
      static int*   ntt_stack;
      static int    nw;
      static int    sum;
      static char** LA;
      static int*   ntt_include;
      static int*   action;
      static int*   actionindx;
      static char*  firstaction;
      static int*   conflict;
      static int*   already;
		static int	  depth;
      static int*   f_lookback;
      static int    inc_on;
      static int*   include;
      static int*   lookback;
      static int    max_lookback;
      static int    max_include;
		static int    max_nditems;
      static int    n_bytes;
      static int    n_relations;
      static int    n_words;
      static int*   newloc;
      static int*   redconf;
		static int    sr_con_left;
		static int    rr_con_left;
		static int    c_states_left;
		static int    n_states_fixed;
      static int    n_shift_prior;
      static int    n_oper_prec;
      static int    sr, rr;
      static char*  LASUM;

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::ComputeLA () /* Analyze States */
{
      char* ch;
		PRINTF("\n");
		if (optn[PG_CONSHIFT] && optn[PG_CONREDUCE])
		{
			PRINTF("Shift-Reduce and Reduce-Reduce Conflicts Report\n\n");
		}
		else if (optn[PG_CONSHIFT])
		{
			PRINTF ("Shift-Reduce Conflicts Report:\n\n");
		}
		else if (optn[PG_CONREDUCE])
		{
			PRINTF ("Reduce-Reduce Conflicts Report:\n\n");
		}
		else
		{
	      PRINTF ("Conflicts Report:\n\n");
			PRINTF ("Neither 'csr' nor 'crr' option was specified.\n\n");
		}

      n_lookah      = 0;
      n_nditems     = 0;
      c_states      = 0;
      sr_con        = 0;
      rr_con        = 0;
		c_states_left = 0;
		sr_con_left   = 0;
		rr_con_left   = 0;
      n_oper_prec   = 0;
      n_shift_prior = 0;

		n_words = (N_terms +  3)/4;   // Number of 4-byte words.

      n_bytes     = 4*n_words;           /* Number of bytes to allocate. */
      max_lookah  = optn[MAX_LA];
      max_child   = optn[MAX_CH];

      ALLOC (D_red,    N_states);
      ALLOC (la_start, N_states+1);
      ALLOC (la_symb,  max_lookah);
      ALLOC (la_red,   max_lookah);
      ALLOC (N_Conflicts, N_states);
      for (int s = 0; s < N_states; s++) N_Conflicts[s] = 0;

	 	C_LOOKBACKS ();
		C_READS ();
		C_LOOKAHEADS ();

		ALLOC (nd_state, N_states);
		for (int s = 0; s < N_states; s++)
		{
			if (nd_item[s+1] > nd_item[s]) nd_state[s] = 1;
			else                             nd_state[s] = 0;
		}

   // Get maximum number of choices for a terminal in each state ...
      nd_maxcount = 0;
      for (int s = 0; s < N_states; s++)
      {
         if (nd_state[s] > 0)
         {
            int term = -1;
            int count = 0;
            int max_count = 0;
            for (int i = nd_item[s]; i < nd_item[s+1]; i++)
            {
               if (nd_term[i] != term) // New terminal?
               {
                  if (count > max_count) max_count = count;
                  term = nd_term[i];
                  count = 1;
               }
               else count++; // Same terminal.
            }
            if (count > max_count) max_count = count;
            nd_state[s] = max_count;
            if (max_count > nd_maxcount) nd_maxcount = max_count;
         // if (max_count > 2 && optn[PG_VERBOSE] > 2)
         //    printf ("nd_state[%d] = %d\n", s, max_count);
         }
      }

      if (sr_con || rr_con) PRINTF ("\n");

		ch = "s";
		if (c_states == 1) ch = "";
		if (optn[PG_VERBOSE])
		     prt_log     ("Conflicts %6d state%s, %d shift-reduce, %d reduce-reduce.\n", c_states, ch, sr_con, rr_con);
		else prt_logonly ("Conflicts %6d state%s, %d shift-reduce, %d reduce-reduce.\n", c_states, ch, sr_con, rr_con);

		prt_con ("%5d conflict state%s.\n", c_states, ch);
		prt_con ("%5d shift-reduce conflicts.\n", sr_con);
		prt_con ("%5d reduce-reduce conflicts.\n\n", rr_con);

		if (n_ndstates > 0)
		{
		/*	ch = "s";
			if (n_ndstates == 1) ch = "";
			if (optn[PG_VERBOSE])
				  prt_log     ("ND       %7d state%s will use LR(*) parsing.\n", n_ndstates, ch);
			else prt_logonly ("ND       %7d state%s will use LR(*) parsing.\n", n_ndstates, ch);
		*/
		}
		return 1;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::C_LOOKAHEADS ()
{
      int  nfi, t, h, i, p, s, f, n;

      for (i = 0; i < n_includes; i++)
      {
         include[i] = -(include[i]+1); // Reset includes.
      }
		max_nditems = optn[MAX_ND];
      ALLOC (LASUM,       n_bytes);
      ALLOC (action,      N_terms);
      ALLOC (actionindx,  N_terms);
      ALLOC (firstaction, N_terms);
      ALLOC (conflict,    N_terms);
		ALLOC (nd_item,     N_states+1);
		ALLOC (nd_term,     max_nditems);
		ALLOC (nd_action,   max_nditems);

      n_ndstates = 0;
		n_states_fixed = 0;
		nw = n_warnings;
      for (s = 0; s < opt_states; s++)
      {
		//	printf ("state = %d\n", s);
			sr = rr = 0;
			la_start[s] = n_lookah;
			nfi = f_final[s+1] - f_final[s];
			D_red[s] = -1;	                        // No default reduction.
			nd_item[s] = n_nditems;
			if (nfi)			                        // Any reductions in this state?
			{
            memset (firstaction, 1, N_terms);
				FASTINI (0, conflict,   N_terms);
				FASTINI (0, action,     N_terms);
				for (i = tt_start [s]; i < tt_start [s+1]; i++)
				{
					action [tt_symb[i]] = tt_action[i];
               actionindx [tt_symb[i]] = i;
				}

				for (f = f_final [s]; f < f_final [s+1]; f++) // For each reduction.
				{
					ANALYZE (s, f);
				}

            if (sr+rr > 0)							// Any conflicts?
				{
					c_states++;							// Update conflict state count.
					sr_con += sr;						// Add to SR total.
					rr_con += rr;						// Add to RR total.
					if (REPORT_CONFLICTS (s,sr,rr))
					{
						DF_TRACE_BACK (s,sr,rr);
					}
					if (sr > 0)							// Any SR conflicts?
					{
					//	nd_item[s+1] = n_nditems;	// Update.
					//	CYCLE_CHECK (s);				// Chack for if-else situation.
					}
					if (n_nditems > nd_item[s])	// Any new nditems?
					{
						n = nd_item[s];
						for (i = nd_item[s]; i < n_nditems; i++)	// For all new items.
						{
							if (nd_action[i] != 0)						// nd action not deleted?
							{
								t            = nd_term[i];				// Get terminal symbol.
								nd_term[n]   = nd_term[i];				// Move term.
								nd_action[n] = nd_action[i];			// Move action.
         				   if (optn[PG_NONDETER])					// ND is on?
                        {
				 	  			   if (action[t] > 0)               // Shift action?
									   tt_action[actionindx[t]] = 0; // Cancel tt_action.
								   action[t] = 0;	                  // Cancel action.
                        }
								n++;
							}
						}
						n_nditems = n;						// Update nditems.
						if (n_nditems > nd_item[s])	// Any nd entries?
						{
				  			SORT2 (nd_term + nd_item[s], nd_action + nd_item[s], n_nditems - nd_item[s]);
                  // Create LA terms, larger parser tables, but faster parser code.
                     if (optn[PG_NONDETER])
                     {
							// Add all terminals that cause a reduction ...
                        for (t = 0; t < N_terms; t++)	// For all terminal symbols.
							   {
								   if (action[t] < 0)			// Reduce action?
								   {
									   if (n_lookah >= max_lookah) MemCrash ("Number of lookaheads", max_lookah);
									   la_symb[n_lookah] = t;
									   la_red [n_lookah++] = -action[t];
								   }
							   }
                        D_red[s] = -1; // No default reduction.
   							n_ndstates++;
	   						goto Next;
                     }
						}
						else // Removed by CYCLE_CHECK.
						{
							n_states_fixed++;
							prt_con ("STATE %d does not require ND parsing.\n\n", s);
						}
					}
				}
			// Can have default reduction if no ND items ...
				if (optn[PG_DEFAULTRED])
				{
				   p = -1;											// No default reduction set.
					for (t = 0; t < N_terms; t++)				// For all terminal symbols.
					{
						if (action[t] < 0)						// Reduction?
						{
							if (p == -1)                     // Undefined?
                        p = -action[t];				   // Define it.
							else if (p != -action[t])        // Defined to something else?.
                        goto NoDef;                   // No default reduction.
						}
					}
               D_red[s] = p;
				}
				else // PG_DEFAULTRED not specified.
				{
NoDef:			D_red[s] = -1;									// No default reduction.
					for (t = 0; t < N_terms; t++)				// For all terminal symbols.
					{
						if (action[t] < 0)						// Reduction?
						{
							if (n_lookah >= max_lookah)
							{
								n_lookah++;
								MemCrash ("Number of lookaheads", max_lookah);
							}
							la_symb[n_lookah] = t;
							la_red [n_lookah++] = -action[t];
						}
					}
				}
         }
Next:    continue;
      }
		for (s = opt_states; s < N_states; s++)
		{
			la_start[s] = n_lookah;
			nd_item[s] = n_nditems;
			D_red[s] = item [final[f_final[s]]].prod;
		}
		la_start[s] = n_lookah;
		nd_item[s] = n_nditems;

      FREE (conflict,   N_terms);
      FREE (action,     N_terms);
      FREE (actionindx, N_terms);
      FREE (LASUM,      n_bytes);

      for (i = 0; i < n_includes; i++) FREE (LA [i], n_bytes);
      FREE (LA, n_includes);

      for (h = 0; h < N_heads; h++) FREE (FIRST [h], n_bytes);
      FREE (FIRST, N_heads);

      FREE (lookback,   max_lookback);
	   FREE (f_lookback, n_finals+2);
		FREE (prod_line, N_prods);
		FREE (head_line, N_heads);
}

///////////////////////////////////////////////////////////////////////////////

void	PG_ComputeLA::ANALYZE (int s, int f)
{
		int p, lb, t;
		p = item [final[f]].prod;
      FASTINI (0, LASUM, n_words);
		for (lb = f_lookback[f]; lb < f_lookback[f+1]; lb++)
		{
			FASTOR (LA[lookback[lb]], LASUM, n_words);
		}
		for (t = 0; t < N_terms; t++)								// For all terminal symbols.
		{
			if (LASUM[t])												// Reduction defined for t?
			{
				if (action[t] == 0)								   // Current action undefined?
				{
					action[t] = -p;									// Reduce by -p
				}
				else if (action[t] < 0)								// Reduce already defined for t?
				{
			      rr++;					                        // Increment number of RR conflicts.
               if (firstaction[t])								// If first action for this t ...
               {
					   if (n_nditems >= max_nditems) MemCrash ("Number of ND entries", max_nditems);
					   nd_term   [n_nditems  ] = t;           // Assign t to terminal list.
					   nd_action [n_nditems++] = action[t];	// Assign original action.
                  firstaction[t] = 0;							// Clear first action flag.
               }
				   if (n_nditems >= max_nditems) MemCrash ("Number of ND entries", max_nditems);
				   nd_term   [n_nditems  ] =  t;
				   nd_action [n_nditems++] = -p;				// Assign previous reduction, keep in order.
			      if (-action[t] < p)
               {
                  conflict[t] = -p;						   // Save the reduction first seen in the grammar.
               }
			      else
			      {
				      conflict[t] = action[t];			   // Switch to reduction first seen.
				      action[t]   = -p;
			      }
				}
				else
				{
               int op = OPER_PREC (s,p,t);	         // Operator precedence.
               if (op == 0)
               {
                  int pr = PRIORITY (s,p,t);          // Rule has priority?
						if (pr == 0)								//	NO.
						{
							if (!optn[PG_FORCESHIFT])
							{
								sr++;										// Increment number of SR conflicts.
								if (firstaction[t])              // If first action for this t ...
								{
									if (n_nditems >= max_nditems) MemCrash("Number of ND entries", max_nditems);
									nd_term[n_nditems] = t;					// Assign t to terminal list.
									nd_action[n_nditems++] = action[t];	// Assign original action.
									firstaction[t] = 0;						// Clear first action flag.
								}
								if (n_nditems >= max_nditems) MemCrash("Number of ND entries", max_nditems);
								nd_term[n_nditems] = t;
								nd_action[n_nditems++] = -p;		   // Assign previous reduction, keep in order.
								conflict[t] = -p;							// Save reduction for reporting.
							}
                  }
               }
				}
			}
		}
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::OPER_PREC (int s, int p, int t)					// Operator precedence defined?
{
      int a, b;
      a = abs (Oper_prec [t]);
      if (a == 32767) return (0);						// Already warned.
		if (a == -32768)										// Non associative, make syntax error at runtime.
		{
			/* nothing yet */
		}
      if (prod_len [p]         >=  3					// Prod length >= 3?
      && Tail [F_tail [p]]     == -head_sym [p]		// Left recursive?
      && Tail [F_tail [p+1]-1] == -head_sym [p])	// Right recursive?
      {
         if (a == 0)											// Oper_prec undefined?
         {
				Oper_prec [t] = 32767;
				sprintf (string, "%s has no operator precedence in state %d", term_name[t], s);
				prt_warning (string, NULL, NULL, 0);
            return (0);
         }
         n_oper_prec++;
         b = abs (Oper_prec [Tail [F_tail [p] + 1]]);
         if (a > b)		// Higher?
         {
            return (1); // Choose shift.
         }
         if (a == b && Oper_prec [t] < 0) // Right Associativity?
         {
            return (1); // Choose shift.
         }
			tt_action[actionindx[t]] = 0; // Cancel shift and goto action.
         action [t] = -p;			      // Force reduction instead.
         return (1);
      }
      return (0);
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::PRIORITY (int s, int p, int t)
{
   // New Version, May 11 2019

   // Check for a reduce priority (illegal) ...
      int shift_priority;
      int reduce_priority = Priority[p];
      if (reduce_priority > 0)
      {
         printf ("\nIn state %d, priority (#) cannot be applied to a reduce action (rule %d).\n", s, p);
         prt_prod (p);
         printf ("\n");
         return 0;
      }

   // Check for any priorities specified on a transition ...
      int npm = 0;
      int nsp = 0;
      for (int k = f_kernel[s]; k < f_kernel[s+1]; k++)
      {
         int i = kernel[k];
         int sym = item[i].symb;
         if (sym != -32767) // Not a final item?
         {
            if (prod_len[p] == item[i].dot)
            {
               if (sym >= 0) // terminal?
               {
                  if (sym == t) goto Bingo;
               }
               else // nonterminal.
               {
			         if (FIRST[-sym][t])
                  {
Bingo:               npm++;    // number of production matches for t.
                     int p2 = item[i].prod;
                     shift_priority = Priority[p2];
                     if (shift_priority > 0)
                     {
                        int len = 0;
                        int tail2 = F_tail[p2];
                        for (int tail = F_tail[p]; tail < F_tail[p+1]; )
                        {
                           if (Tail[tail++] == Tail[tail2++]) len++;
                        }
                        if (len == item[i].dot)
                        {
                           nsp++; // number of shift priorities.
                        }
                     }
                  }
               }
            }
         }
      }
      if (nsp > 0) // Any shift priorities ?
      {
         if (npm != nsp) // Not applied to all shift rules ?
         {
            printf ("\nIn state %d, priority (#) is not applied to all rules which allow shift %s.\n", s, term_name[t]);
            return 0;
         }
         n_shift_prior++;
         return 1; // Shift priority.
      }
      return 0; // No shift priority.
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::REPORT_CONFLICTS (int state, int sr, int rr)
{
		int nc, t, first = 1, rc = 0;

      N_Conflicts[state] += sr + rr;
		nc = 0; // Number of conflicts.
      if (rr) // Do reduce-reduce conflicts first.
      {
			if (optn[PG_CONREDUCE])
			{
				for (t = 0; t < N_terms; t++)
				{
					if (conflict[t] != 0)	// Got conflict on this terminal?
					{
						if (action[t] < 0)	// Reduce action?
						{
							nc++;
							if (first)
							{
								first = 0;
								PRT_STA (state);
								PRINTF ("\n");
							}
							PRINTF ("   RR conflict on %-20s, ", term_name[t]);
							PRINTF ("reduce %d or reduce %d, ", -action[t], -conflict[t]);
							if (optn[PG_NONDETER])
								PRINTF ("resolved by ND parsing.\n");
							else
								PRINTF ("choosing reduce %d.\n", -action[t]);
						}
					}
				}
			}
      }
		if (nc) rc = 1;
		nc = 0; // Number of conflicts.
      if (sr) // Do shift-reduce conflicts.
      {
			if (optn[PG_CONSHIFT])
			{
				for (t = 0; t < N_terms; t++)
				{
					if (conflict[t] != 0) // Got conflict on this terminal?
					{
						if (action[t] > 0) // Shift action?
						{
							nc++;
							if (first)
							{
								first = 0;
								PRT_STA (state);
								PRINTF ("\n");
							}
							PRINTF ("   SR conflict on %-20s, ", term_name[t]);
							PRINTF ("shift or reduce %d, ", -conflict[t]);
							if (optn[PG_NONDETER])
								PRINTF ("resolved by ND parsing.\n");
							else
                     {
                        int x = action[t];
                        if (x > opt_states)
                        {
                           x = item[final[f_final[x]]].prod;
   								PRINTF ("choosing shift and reduce %d.\n", x);
                        }
								else PRINTF ("choosing shift and goto %d.\n", x);
                     }
						}
					}
				}
			}
      }
		if (nc) rc = 1;
		if (first == 0) PRINTF ("\n");
		return (rc);
}

///////////////////////////////////////////////////////////////////////////////

void	PG_ComputeLA::prt_prod (int p)
{
		printf ("%6d %s -> ", p, head_name[head_sym[p]]);
		for (int i = F_tail[p]; i < F_tail[p+1]; i++)
		{
			char* symb;
			int   s = Tail[i];
			if (s >= 0) symb = term_name[ s];
			else        symb = head_name[-s];
			printf ("%s ", symb);
		}
		printf ("\n");
}

///////////////////////////////////////////////////////////////////////////////

void	PG_ComputeLA::prt_prod (int p, int dot)
{
      int d = 0;
		printf ("%6d %s -> ", p, head_name[head_sym[p]]);
		for (int i = F_tail[p]; i < F_tail[p+1]; i++)
		{
			char* symb;
			int   s = Tail[i];
			if (s >= 0) symb = term_name[ s];
			else        symb = head_name[-s];
         if (d++ == dot) printf (". ");
			printf ("%s ", symb);
		}
		printf ("\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::C_LOOKBACKS ()
{
      int p, dot, i, state, f;

      i            = 0;  /* include number. */
      inc_on       = 0;  /* Include switch. */
      n_lookbacks  = 0;
      n_childs     = 0;
      n_relations  = 0;
      n_includes   = 0;
		max_child_usage   = 0;

      max_lookback = optn[MAX_LB];
      max_include  = optn[MAX_INC];

      ALLOC (f_lookback,  n_finals+2);
      ALLOC (lookback,    max_lookback);
      ALLOC (include,     max_include);
      ALLOC (ntt_include, n_nttran);
      ALLOC (f_child,     n_nttran);
      ALLOC (child,       max_child);

      FASTINI (-1, ntt_include, n_nttran);
      FASTINI (-1, f_child,     n_nttran);

      for (state = 0; state < N_states; state++) // for all states.
      {
         for (f = f_final [state]; f < f_final [state+1]; f++) // for each final item.
         {
            p = item [final[f]].prod;                          // Get production number.
            dot = prod_len [p];                                // Get dot position.
            f_lookback[f] = n_lookbacks;                       // Set first lookback number.
            LOOK_BACK (i++, p, dot, state);                    // Find all lookbacks.
         }
         f_lookback [f] = n_lookbacks;                         // Set last lookback number.
      }
   // FREE    (ntt_include, n_nttran);
      REALLOC (lookback, max_lookback, n_lookbacks);
      REALLOC (include,  max_include,  n_includes);
      REALLOC (f_child,  n_nttran,     n_includes);
      REALLOC (child,    max_child,    n_relations);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::LOOK_BACK (int i, int p, int dot, int state)
{
      int cfi, inc;
      if (dot-- > 0)
      {
         for (cfi = f_camefrom [state]; cfi < f_camefrom [state+1]; cfi++)
         {
            LOOK_BACK (i, p, dot, camefrom [cfi]);
         }
      }
	   else if ((inc = NTX (state, head_sym [p])) >= 0)
      {
         if (inc_on == 0)
         {
            if (n_lookbacks >= max_lookback) MemCrash ("Number of lookbacks", max_lookback);
            lookback [n_lookbacks++] = inc;
            inc_on = 1;
            C_INCLUDE (state, inc);
            inc_on = 0;
         }
         else if (i != inc && ATTACH (i, inc) == 0)
         {
            n_relations++;
            C_INCLUDE (state, inc);
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

int	PG_ComputeLA::NTX (int s, int h) /* Nonterminal transition. */
{
      int ntti;
      for (ntti = ntt_start[s]; ntti < ntt_start[s+1]; ntti++)
      {
         if (ntt_symb[ntti] == h)
         {
            if (ntt_include[ntti] < 0) // New include?
            {
               if (n_includes >= max_include) MemCrash ("Number of includes", max_include);
               ntt_include[ntti] = n_includes;
               include[n_includes] = ntti;
               return (n_includes++);
            }
            return (ntt_include[ntti]); // Old include!
         }
      }
      return -1;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::C_INCLUDE (int s, int inc)
{
      int ntti, S, k, p, dot, t;

      ntti = include [inc];
      if (ntti >= 0) /* If not done before? */
      {
         include [inc] = -(ntti+1); /* Mark it done. */
         S = ntt_action [ntti];
         for (k = f_kernel [S]; k < f_kernel [S+1]; )
         {
            dot = item[kernel[k]].dot;
            if (dot > 0) /* If not null production? */
            {
               p = item[kernel[k]].prod;
               for (t = F_tail[p]+dot; t < F_tail[p+1]; t++)
               {
                  if (Tail [t] >= 0) goto Next;
                  if (!nullable [-Tail [t]]) goto Next;
               }
               LOOK_BACK (inc, p, (int)(dot-1), s);
            }
Next:       k++;
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::C_READS ()
{
      int i, s, m, ntti;

      ALLOC (LA, n_includes);
      for (i = 0; i < n_includes; i++)
      {
         ALLOC (LA[i], n_bytes);
         memset (LA[i], 0, n_bytes);
      }

      ALLOC (already, N_states);
      ALLOC (newloc, N_states);
      FASTINI (-1, already, N_states);
      FASTINI (-1, newloc, N_states);

      for (i = 0; i < n_includes; i++)
      {
         ntti = include [i];
         if (ntti < 0) ntti = -(ntti+1);
         if ((s = ntt_action [ntti]) > 0)
         {
            if (newloc [s] == -1)
            {
               IND_READ (i, s);
               newloc [s] = i;
            }
            else
            {
               m = newloc [s];
            // PRINTF ("copying LA[%4d] to LA[%4d]\n", m, i);
               FASTCPY (LA[m], LA[i], n_words);
            }
         }
      }

      FREE (newloc,   N_states);
      FREE (already, N_states);
      T_GRAPH (LA,   n_includes, N_terms);
      FREE (child,   n_relations);
      FREE (f_child, n_includes);
   // FREE (include, n_includes);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::IND_READ (int i, int s)
{
      int x, j, t;
      already [s] = i;
      for (j = ntt_start [s]; j < ntt_start [s+1]; j++)
      {
         if ((x = ntt_action [j]) > 0)
         {
            if (nullable [ntt_symb[j]])
            {
               if (already [x] != i)
               {
                  IND_READ (i, x);
               }
            }
         }
      }
      for (j = tt_start [s]; j < tt_start [s+1]; j++)
      {
      // Some goto's may be disabled by ND option or disambiguating rules.
         if (tt_action [j] > 0)
         {
            t = tt_symb [j];
				LA[i][t] = 1;
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::RESOLUTION ()
{
      int t, l;
      PRINTF ("\n   Lookahead symbol and action chosen:\n");
      for (t = 0; t < N_terms; t++)
      {
         if (redconf [t] != 0)
         {
            PRINTF ("   ");
            l = prt_sym (t, " ");
            if (l > max_terml) l = max_terml;
            spaces [max_terml-l] = 0;
            PRINTF ("%s", spaces);
            spaces [max_terml-l] = ' ';
            if (action [t] < 0) /* If shift action for t? */
            {
               PRINTF(" shift, not reduce %d\n", abs (redconf [t]));
            }
            else /* If two reductions for t? */
            {
               PRINTF(" reduce %d,  not %d\n", action[t], abs (redconf [t]));
            }
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::PRT_STA (int s)
{
      int k, i;
      int f, p;

		PRINTF ("STATE %d ..........................................................................................\n\n", s);
      for (k = f_kernel [s]; k < f_kernel [s+1]; k++)
      {
         i = kernel [k];
         if (item[i].symb != -32767)
         {
            PRINTF ("   * ");
            prt_prod (item[i].prod, item[i].dot, "");
         }
      }
      for (f = f_final [s]; f < f_final [s+1]; f++)
      {
         p = item [final[f]].prod;
         if (p >= 0) // Not disabled ?
         {
            PRINTF ("   * ");
            prt_prod (p, -1, "");
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::prt_prod (int p, int dot, char *before)
{
      int t, u, d;
      PRINTF ("%s%5d %s -> ", before, p, head_name [head_sym [p]]);
      t = F_tail [p];
      u = F_tail [p+1];
      d = t + dot;
      if (dot == -1) d = u;
      for (;;)
      {
         if (t == d) PRINTF (". ");
         if (t >= u) break;
         prt_sym (Tail [t], " ");
         t++;
      }
      PRINTF ("\n");
}

///////////////////////////////////////////////////////////////////////////////

int	PG_ComputeLA::prt_sym (int s, char *sp)
{
      char *p;

      if (s >= 0)                 /* Terminal symbol? */
         p = term_name[s];
      else                        /* Nonterminal symbol? */
         p = head_name[-s];

      PRINTF ("%s%s", p, sp);
      return ((int)strlen(p) + (int)strlen(sp));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Bredth-first trace back.

void  PG_ComputeLA::BF_TRACE_BACK (int state, int sr, int rr)
{
      int lb, ntti, orig, next, last, i, t, f, p, h, n, dot;
      if (!optn[PG_CONTRACEBACK]) return;

      #ifdef _DEBUG
      PRINTF ("TRACE BACK from state %d:\n", state);
      prt_state (state);
      #endif

   // PRINTF ("\n");
      ALLOC (ntt_done, n_nttran);
      for (t = 0; t < N_terms; t++)								// For all terminal symbols.
      {
         if (conflict[t])
         {
            n = 0;
		      memset (ntt_done, 0, n_nttran);
            PRINTF ("CHOICES for lookahead '%s'\n\n", term_name[t]);
            if (action[t] >= 0)  // shift-reduce conflict? (zeroed action is possible)
            {
               PRINTF ("%d   shift        %s\n", ++n, term_name[t]);
               PRINTF ("    goto    %4d\n", action[t]);
               prt_state (action[t]);
               PRINTF ("\n");
            }
            else                 // reduce-reduce conflict!
            {
               if (rr == 0) continue; // skip this one.
            }
	         for (f = f_final[state]; f < f_final[state+1]; f++)      // For each reduction.
	         {
               p = item [final[f]].prod;
               h = head_sym[p];
               if (p == -conflict[t] || p == -action[t])
               {
                  PRINTF ("%d   reduce ", ++n);
                  prt_prod (p, -1, "");
                  for (lb = f_lookback[f]; lb < f_lookback[f+1]; lb++)  // For all lookbacks of final item.
                  {
			            if (LA[lookback[lb]][t])								   // Reduction defined for t?
			            {
                        ntti = include[lookback[lb]];
                        next = ntt_action[ntti]; // Get next state.
                        for (i = tt_start[next]; i < tt_start[next+1]; i++)
                        {
                           if (tt_symb[i] == t)
                           {
                              last = tt_action[i];
                              goto Shift;
                           }
                        }
                        p = item[ntt_item[ntti]].prod;
                        if (prod_len[p] > 0)
                        {
                           dot  = item[ntt_item[ntti]].dot;
                           orig = ntt_origin[ntti]; // Back to origin state.
                           ntt_done[ntti] = 1;
                        // printf ("    backto  %4d\n", orig);
                           for (depth = 1;; depth++)
                           {
                           // printf ("\ndepth = %d\n", depth);
                              if (bf_look_back (1, t, p, dot, orig, next, last))
                              {
Shift:                           PRINTF ("    goto    %4d\n", next);
                                 prt_state (next);
                                 PRINTF ("    shift        %s\n", term_name[t]);
                                 PRINTF ("    goto    %4d\n", last);
                                 prt_state (last);
                              // PRINTF ("\n");
                                 ntt_done[ntti] = 0;
                                 goto Cont;
                              }
                           }
                           ntt_done[ntti] = 0;
                        }
                        else
                        {
                           printf ("production length = 0\n");
                           Quit ();
                        }
                     }
                  }
               }
Cont:          continue;
            }
         }
	   }
      FREE (ntt_done, n_nttran);
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::bf_look_back (int d, int t, int p, int dot, int state, int& next, int& last)
{
      int cfi, h, ntti, i;
      if (dot-- > 0)
      {
         for (cfi = f_camefrom[state]; cfi < f_camefrom[state+1]; cfi++)
         {
            if (bf_look_back (d, t, p, dot, camefrom[cfi], next, last))
            {
               return 1;
            }
         }
         return 0;
      }
      else // Get nonterminal transition from this state.
      {
         h = head_sym[p];
         for (ntti = ntt_start[state]; ntti < ntt_start[state+1]; ntti++)
         {
            if (ntt_symb[ntti] == h)
            {
               if (ntt_done[ntti] == 0)
               {
                  if (d == depth)
                  {
                     next = ntt_action[ntti];
                     if (LA[ntt_include[ntti]][t])
                     {
                        for (i = tt_start[next]; i < tt_start[next+1]; i++)
                        {
                           if (tt_symb[i] == t)
                           {
                              PRINTF ("    backto  %4d\n", state);
                              prt_state (state);
                              last = tt_action[i];
                              return 1;
                           }
                        }
                     }
                  }
                  else
                  {
                     ntt_done[ntti] = 1;
                     p   = item[ntt_item[ntti]].prod;
                     dot = item[ntt_item[ntti]].dot;
                  // prt_prod (p, dot, "");
                     if (bf_look_back (++d, t, p, dot, state, next, last))
                     {
                        ntt_done[ntti] = 0;
                        return 1;
                     }
                     ntt_done[ntti] = 0;
                  }
               }
               return 0;
            }
         }
      }
      return 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    Depth-first trace back.

void  PG_ComputeLA::DF_TRACE_BACK (int state, int sr, int rr)
{
      int lb, ntti, orig, next, last, i, t, f, p, h, n, dot;
      if (!optn[PG_CONTRACEBACK]) return;

      PRINTF ("CONFLICT ANALYSIS for state %d:\n\n", state);
   // prt_state (state);
   // PRINTF ("\n");

      ALLOC (ntt_done, n_nttran);
      for (t = 0; t < N_terms; t++) // For all terminal symbols.
      {
         if (conflict[t]) // Conflict on this terminal?
         {
            n = 0;
		      memset (ntt_done, 0, n_nttran);
            PRINTF ("Choices for lookahead: %s\n\n", term_name[t]);
            if (action[t] >= 0)  // shift-reduce conflict? (zeroed action is possible)
            {
               PRINTF ("%2d. shift        %s\n", ++n, term_name[t]);
               PRINTF ("    goto    %4d\n", action[t]);
               prt_state (action[t]);
            // PRINTF ("\n");
            }
            else                 // reduce-reduce conflict!
            {
               if (rr == 0) continue; // skip this one.
            }
	         for (f = f_final[state]; f < f_final[state+1]; f++)      // For each reduction.
	         {
               p = item [final[f]].prod;
               h = head_sym[p];
               if (p == -conflict[t] || p == -action[t])
               {
                  PRINTF ("%2d. reduce ", ++n);
                  prt_prod (p, -1, "");
                  for (lb = f_lookback[f]; lb < f_lookback[f+1]; lb++)  // For all lookbacks of final item.
                  {
			            if (LA[lookback[lb]][t])								   // Reduction defined for t?
			            {
                     // printf ("\nLookback %d\n", lb);
                        ntti = include[lookback[lb]];
                        if (ntt_done[ntti] == 0)
                        {
                           orig = ntt_origin[ntti];
                        // printf ("    BACKTO  %4d\n", orig);
                           next = ntt_action[ntti]; // Get next state.
                           for (i = tt_start[next]; i < tt_start[next+1]; i++)
                           {
                              if (tt_symb[i] == t)
                              {
                                 last = tt_action[i];
                                 goto Shift;
                              }
                           }
                           p = item[ntt_item[ntti]].prod;
                           if (prod_len[p] > 0)
                           {
                              dot  = item[ntt_item[ntti]].dot;
                           // prt_prod (p, dot, "           ");
                              ntt_done[ntti] = 1;
                              if (df_look_back (t, p, dot, orig, next, last))
                              {
Shift:                           PRINTF ("    goto    %4d\n", next);
                                 prt_state (next);
                                 PRINTF ("    shift        %s\n", term_name[t]);
                                 PRINTF ("    goto    %4d\n", last);
                                 prt_state (last);
                                 goto Cont; // next final item.
                              }
                           }
                           else
                           {
                              printf ("production length = 0\n");
                              Quit ();
                           }
                        }
                     }
                  }
               }
Cont:          continue;
            }
			//	PRINTF ("\n");
         }
	   }
      FREE (ntt_done, n_nttran);
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::df_look_back (int t, int p, int dot, int state, int& next, int& last)
{
      int cfi, h, ntti, i;
      if (dot-- > 0)
      {
         for (cfi = f_camefrom[state]; cfi < f_camefrom[state+1]; cfi++)
         {
            if (df_look_back (t, p, dot, camefrom[cfi], next, last))
            {
               return 1;
            }
         }
         return 0;
      }
      else // Get nonterminal transition from this state.
      {
      // printf ("    backto  %4d\n", state);
         h = head_sym[p];
         for (ntti = ntt_start[state]; ntti < ntt_start[state+1]; ntti++)
         {
            if (ntt_symb[ntti] == h)
            {
            // printf ("ntti = %d\n", ntti);
               if (ntt_done[ntti] == 0)
               {
                  next = ntt_action[ntti];
                  if (LA[ntt_include[ntti]][t])
                  {
                     for (i = tt_start[next]; i < tt_start[next+1]; i++)
                     {
                        if (tt_symb[i] == t)
                        {
                           PRINTF ("    backto  %4d\n", state);
                           prt_state (state);
                           last = tt_action[i];
                           ntt_done[ntti] = 1;
                           return 1;
                        }
                     }
                     ntt_done[ntti] = 1;
                  }
                  p    = item[ntt_item[ntti]].prod;
                  dot  = item[ntt_item[ntti]].dot;
               // prt_prod (p, dot, "           ");
                  if (state > 0)
                  {
                     ntt_done[ntti] = 1;
                     if (df_look_back (t, p, dot, state, next, last))
                     {
                        ntt_done[ntti] = 1;
                        return 1;
                     }
                     else
                     {
                     // printf ("ntti = %d\n", ntti);
                     // printf ("    failed\n\n");
                        ntt_done[ntti] = 1;
                        return 0;
                     }
                  }
                  else
                  {
                  // printf ("ntti = %d\n", ntti);
                  // printf ("    failed\n\n");
                     ntt_done[ntti] = 1; // Done and failed.
                     return 0;
                  }
               }
               else
               {
                  return 0;
               }
            }
         }
      }
		PRINTF ("\nNonfatal error caused by 'ca' option\n");
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::CYCLE_CHECK (int state)
{
      int lb, ntti, orig, next, last, i, t, f, p, h, n, dot;
   // PRINTF ("\nCYCLE CHECK for state %d:\n\n", state);
   // prt_state (state);
   // PRINTF ("\n");

      ALLOC (ntt_done, n_nttran);
      for (t = 0; t < N_terms; t++) // For all terminal symbols.
      {
         if (conflict[t] && action[t] >= 0) // conflict and shift action?
         {
            n = 0;
		      memset (ntt_done, 0, n_nttran);
            if (action[t] == 0) action[t] = tt_action [actionindx[t]];
	         for (f = f_final[state]; f < f_final[state+1]; f++)      // For each reduction.
	         {
               p = item [final[f]].prod;
               h = head_sym[p];
               if (p == -conflict[t] || p == -action[t])
               {
               // PRINTF ("%d   reduce ", ++n);
               // prt_prod (p, -1, "");
                  for (lb = f_lookback[f]; lb < f_lookback[f+1]; lb++)  // For all lookbacks of final item.
                  {
			            if (LA[lookback[lb]][t])								   // Reduction defined for t?
			            {
                     // printf ("\nLookback %d\n", lb);
                        ntti = include[lookback[lb]];
                        if (ntt_done[ntti] == 0)
                        {
                           orig = ntt_origin[ntti];
                        // printf ("    BACKTO  %4d\n", orig);
                           next = ntt_action[ntti]; // Get next state.
                           for (i = tt_start[next]; i < tt_start[next+1]; i++)
                           {
                              if (tt_symb[i] == t)
                              {
                                 last = tt_action[i];
                                 goto Shift;
                              }
                           }
                           p = item[ntt_item[ntti]].prod;
                           if (prod_len[p] > 0)
                           {
                              dot  = item[ntt_item[ntti]].dot;
                           // prt_prod (p, dot, "           ");
                              ntt_done[ntti] = 1;
                              if (cycle_look_back (t, p, dot, orig, next, last))
                              {
Shift:                           if (next == state /* || last == action[t]*/ )
                                 {
												sr--;
												PRINTF ("CYCLE in state %d, choosing shift instead of reduce for %s.\n", state, term_name[t]);
											/*	if (optn[PG_CONTRACEBACK])
												{
												//	prt_state (state);
												   PRINTF ("\n");
													PRINTF ("%d   shift        %s\n", ++n, term_name[t]);
													PRINTF ("    goto    %4d\n", action[t]);
													prt_state (action[t]);
												// PRINTF ("\n");
													PRINTF ("%d   reduce ", ++n);
													prt_prod (item[final[f]].prod, -1, "");
													PRINTF ("    goto    %4d\n", next);
													prt_state (next);
													PRINTF ("    shift        %s\n", term_name[t]);
													PRINTF ("    goto    %4d\n", last);
													prt_state (last);
												// PRINTF ("\n");
												}	*/
                                    for (i = nd_item[state]; i < nd_item[state+1]; i++)
                                    {
                                       if (nd_term[i] == t) nd_action[i] = 0; // Delete this action.
                                    }
                                    goto Nextt; // next terminal symbol.
                                 }
                                 goto Nextf; // next final item.
                              }
                           }
                           else
                           {
                              printf ("production length = 0\n");
                              Quit ();
                           }
                        }
                     }
                  }
               }
Nextf:         continue;
            }
            tt_action [actionindx[t]] = 0; // Delete deterministic action.
         }
Nextt:   continue;
	   }
      FREE (ntt_done, n_nttran);
}

///////////////////////////////////////////////////////////////////////////////

int   PG_ComputeLA::cycle_look_back (int t, int p, int dot, int state, int& next, int& last)
{
      int cfi, h, ntti, i;
      if (dot-- > 0)
      {
         for (cfi = f_camefrom[state]; cfi < f_camefrom[state+1]; cfi++)
         {
            if (cycle_look_back (t, p, dot, camefrom[cfi], next, last))
            {
               return 1;
            }
         }
         return 0;
      }
      else // Get nonterminal transition from this state.
      {
      // printf ("    backto  %4d\n", state);
         h = head_sym[p];
         for (ntti = ntt_start[state]; ntti < ntt_start[state+1]; ntti++)
         {
            if (ntt_symb[ntti] == h)
            {
            // printf ("ntti = %d\n", ntti);
               if (ntt_done[ntti] == 0)
               {
                  next = ntt_action[ntti];
                  if (LA[ntt_include[ntti]][t])
                  {
                     for (i = tt_start[next]; i < tt_start[next+1]; i++)
                     {
                        if (tt_symb[i] == t)
                        {
                        // PRINTF ("    backto  %4d\n", state);
                        // prt_state (state);
                           last = tt_action[i];
                           ntt_done[ntti] = 1;
                           return 1;
                        }
                     }
                     ntt_done[ntti] = 1;
                  }
                  p    = item[ntt_item[ntti]].prod;
                  dot  = item[ntt_item[ntti]].dot;
               // prt_prod (p, dot, "           ");
                  if (state > 0)
                  {
                     ntt_done[ntti] = 1;
                     if (cycle_look_back (t, p, dot, state, next, last))
                     {
                        ntt_done[ntti] = 1;
                        return 1;
                     }
                     else
                     {
                     // printf ("ntti = %d\n", ntti);
                     // printf ("    failed\n\n");
                        ntt_done[ntti] = 1;
                        return 0;
                     }
                  }
                  else
                  {
                  // printf ("ntti = %d\n", ntti);
                  // printf ("    failed\n\n");
                     ntt_done[ntti] = 1; // Done and failed.
                     return 0;
                  }
               }
               else
               {
                  return 0;
               }
            }
         }
      }
		PRINTF ("\nNonfatal error caused by 'ct' option\n");
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::prt_state (int s)
{
      int k, i, f, p;
		PRINTF ("\n    //STATE %4d ////////////////////////////////////////////////////////////////\n", s);
      for (k = f_kernel [s]; k < f_kernel [s+1]; k++)
      {
         i = kernel [k];
         if (item[i].symb != -32767)
         {
            PRINTF ("    // rule");
            prt_prod2 (item[i].prod, item[i].dot, "");
         }
      }
      for (f = f_final [s]; f < f_final [s+1]; f++)
      {
         p = item [final[f]].prod;
         PRINTF ("    // rule");
         prt_prod2 (p, -1, "");
      }
		PRINTF ("    /////////////////////////////////////////////////////////////////////////////\n\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_ComputeLA::prt_prod2 (int p, int dot, char *before)
{
      int t, u, d;
      PRINTF ("%s%5d %s -> ", before, p, head_name [head_sym [p]]);
      t = F_tail [p];
      u = F_tail [p+1];
      d = t + dot;
      if (dot == -1) d = u;
      for (;;)
      {
         if (t == d) PRINTF (". ");
         if (t >= u) break;
         prt_sym2 (Tail [t], " ");
         t++;
      }
      PRINTF ("\n");
}

///////////////////////////////////////////////////////////////////////////////

int	PG_ComputeLA::prt_sym2 (int s, char *sp)
{
      char *p;
      if (s >= 0) p = term_name[s];
      else        p = head_name[-s];
      PRINTF ("%s%s", p, sp);
      return 1;
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

