
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
		#include "PG_OptimizeStates.h"

		int    PG_OptimizeStates::Accept_state;
		int    PG_OptimizeStates::ntt_states;
		int    PG_OptimizeStates::tt_states;

		int   *pr_type;
		int   *hs_type;
		int   *old_state;
		int   *new_state;
      int   *reductions;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   PG_OptimizeStates::OptimizeStates ()
{
      Accept_state = FIND_ACCEPT_STATE ();

      MAKE_SHIFT_REDUCE_ACTIONS ();
      ELIMINATE_CHAIN_REDUCTIONS ();

		if (optn[PG_SHIFTREDUCE])
		{
			N_states   = opt_states+1;
			tt_states  = opt_states+1;
			ntt_states = opt_states+1;
		}
		else
		{
			tt_states  = N_states;
			ntt_states = N_states;
		}
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//		Find accept state (need this for PG_CLR_PARSER, works for the others too) //
//		This is a generalized version. Could have searched state 1 for <eof>.

int   PG_OptimizeStates::FIND_ACCEPT_STATE ()
{
		int ntt, tt;
		int state = 0;
		int symb  = Tail [F_tail [F_prod[0]]];
		if (symb < 0) // Nonterminal symbol?
		{
			for (ntt = ntt_start[state]; ntt < ntt_start[state+1]; ntt++)
			{
				if (ntt_symb[ntt] == -symb)
				{
					state = ntt_action[ntt];
					break;
				}
			}
		}
		else // Terminal symbol!
		{
			for (tt = tt_start[state]; tt < tt_start[state+1]; tt++)
			{
				if (tt_symb[tt] == symb)
				{
					state = tt_action[tt];
					break;
				}
			}
		}
		symb = Tail [F_tail [F_prod[0]] + 1]; // <eof> symbol
		for (tt = tt_start[state]; tt < tt_start[state+1]; tt++)
		{
			if (tt_symb[tt] == symb)
			{
				state = tt_action[tt];
				break;
			}
		}
		return state;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  PG_OptimizeStates::MAKE_SHIFT_REDUCE_ACTIONS ()
{
      int state, i;
      if (optn[PG_SHIFTREDUCE]) // Shift-reduce actions wanted?
      {
         for (state = 0; state < opt_states; state++)
         {
            for (i = tt_start [state]; i < tt_start [state+1]; i++)
            {
               if (tt_action[i] > opt_states)
               {
                  tt_action[i] = -D_red [tt_action[i]];
               }
            }
            for (i = ntt_start [state]; i < ntt_start [state+1]; i++)
            {
               if (ntt_action[i] >= opt_states)
               {
                  ntt_action[i] = -D_red [ntt_action[i]];
               }
            }
			   if (optn[PG_NONDETER])
			   {
				   for (i = nd_item[state]; i < nd_item[state+1]; i++)
				   {
					   if (nd_action[i] >= opt_states)
						    nd_action[i]  = opt_states + D_red [nd_action[i]];
				   }
			   }
         }
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  PG_OptimizeStates::ELIMINATE_CHAIN_REDUCTIONS () // Eliminate Chain Shift-Reduce Actions.
{
		int state, h, p, i, n, N_total, T_total, n_changed;
		N_total = 0;
	   T_total = 0;
      if (optn [PG_OPTIMIZE])
		{
			for (state = 0; state < opt_states; state++)
			{
Loop:       n_changed = 0;
				for (i = ntt_start[state]; i < ntt_start[state + 1]; i++)
				{
					p = -ntt_action[i];				// Action.
					if (p > 0 							// Shift?
					&& prod_len[p]  ==  1 			// Reduce?
					&& Node_numb[p] == -1)			// No make node action?
					{
						h = head_sym[p];
						for (n = ntt_start[state]; n < ntt_start[state + 1]; n++)
						{
							if (ntt_symb[n] == h) break;
						}
						ntt_action[i] = ntt_action[n];	// Upgrade NTT action.
						n_changed++;
						N_total++;
					}
				}
				if (n_changed > 0) goto Loop;

				for (i = tt_start[state]; i < tt_start[state + 1]; i++)
				{
					if (tt_symb[i] == 27)
						i = i;
					p = -tt_action[i]; 				// Action.
    				if (p > 0 							// Shift?
					&& prod_len[p]  ==  1 			// Reduce?
					&& Node_numb[p] == -1)			// No make node action?
					{
						h = head_sym[p];				// Nonterminal.
						for (n = ntt_start[state]; n < ntt_start[state + 1]; n++)
						{
							if (ntt_symb[n] == h) break;	// Got nonterminal?
						}
						tt_action[i] = ntt_action[n];		// Upgrade TT action.
						T_total++;								// Count terminal trans.
					}
				}
			}
			if (optn[PG_VERBOSE] > 1)
			prt_log ("Optimized%7d N-transactions, %d T-transactions, were optimized.\n", N_total, T_total);
		}
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

