
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "PG_PrintStates.h"

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::PrintStates ()
{
      int t, h, s, n, x, p, i;

   // if (optn[PG_STATES] > 1) return; // Already output once!

      prt_sta ("\nSTATE MACHINE LISTING:\n\n");
      if (!optn[PG_STATES])
		{
	      prt_sta ("'st' option was not specified.\n");
			return;
		}
      n = 0;
      for (s = 0; s < N_states; s++)
      {
         if (N_Conflicts[s] > 0)
         {
            n++;
            char* str;
            if (optn[PG_NONDETER]) str = "nondeterministic";
            else                   str = "conflict";
            if (N_Conflicts[s] == 1)
                 prt_sta ("%3d. STATE %-3d has %2d %s\n",  n, s, 1, str);
            else prt_sta ("%3d. STATE %-3d has %2d %ss\n", n, s, N_Conflicts[s], str);
         }
      }
      if (n) prt_sta ("\n");
      else
      {
         if (optn[PG_NONDETER]) prt_sta ("No Nondeterministic States.\n\n");
         else                   prt_sta ("No Conflicts Reported.\n\n");
      }
      for (s = 0; s < N_states; s++)
      {
         PRT_STA (s);
         if (optn[PG_TRANSITIONS])
         {
				int na = 0;
         // max_symbl = C_max_symbl (s);
            if (nd_item[s+1] > nd_item[s])
            {
               if (optn[PG_NONDETER])
                  prt_sta ("   Nondeterministic\n");
               else
                  prt_sta ("   Conflicts\n");
            }
            for (i = nd_item[s]; i < nd_item[s+1]; i++)
            {
					na++;
               t = nd_term[i];
               x = nd_action[i];
               if (x > 0) // shift and ...
               {
                  if (optn[PG_NONDETER]) P_SYMBOL (t, "   N ");
                  else                   P_SYMBOL (t, "   C ");
                  if (x > opt_states)
                  {
                     prt_sta (" shift & reduce ");
							p = x - opt_states;
                     p_prod  (p, prod_len[p]-1, "", "\n");
                  }
                  else prt_sta (" shift & goto   %4d\n",  x);
               }
					else // reduce.
               {
                  if (optn[PG_NONDETER]) P_SYMBOL (t, "   N ");
                  else                   P_SYMBOL (t, "   C ");
                  p = -x;
                  int c = 0;
                  for (int f = f_final [s]; f < f_final [s+1]; f++)
                  {
                     if (item [final[f]].prod == p)
                     {
                        c++;
                        prt_sta (" reduce         ");
                        break;
                     }
                  }
						p_prod (p, -1, "", "\n");
               }
            }
            if (na) prt_sta ("\n");
            na = 0;
            for (i = tt_start[s]; i < tt_start[s+1]; i++)
            {
					if (tt_action[i] != 0)
					{
						na++;
						x = tt_action [i];
						t = tt_symb [i];
						P_SYMBOL (t);
						if (x > 0) prt_sta (" shift & goto   %4d\n", x);
					  	else
                  {
                     p = -x;
                     int c = 0; // counter.
                     for (int f = f_final [s]; f < f_final [s+1]; f++)
                     {
                        if (item [final[f]].prod == p)
                        {
                           c++;
                           prt_sta (" reduce         ");
                           break;
                        }
                     }
							if (c == 0)
							{
								prt_sta (" shift & reduce ");
								p_prod (p, prod_len[p] - 1, "", "\n");
							}
							else p_prod (p, -1, "", "\n");
                  }
					}
            }
            if (la_start != NULL)
            {
               for (i = la_start[s]; i < la_start[s+1]; i++)
               {
						na++;
                  t = la_symb [i];
                  P_SYMBOL (t);
                  p = la_red [i];
                  int c = 0; // counter.
                  for (int f = f_final [s]; f < f_final [s+1]; f++)
                  {
                     if (item [final[f]].prod == p)
                     {
                        c++;
                        prt_sta (" reduce         ");
                        break;
                     }
                  }
						if (c == 0)
						{
							prt_sta (" shift & reduce ");
							p_prod (p, prod_len[p] - 1, "", "\n");
						}
						else p_prod(p, -1, "", "\n");
					}
            }
				if (D_red[s] > 0)
				{
					na++;
               p = D_red[s];
               if (N_Conflicts[s]) P_SYMBOL (-32767, "   # "); // default
               else                P_SYMBOL (-32767);          // default
               prt_sta (" reduce         ");
   			  	p_prod (p, -1, "", "\n");
				}
				if (na > 0) prt_sta ("\n");
            n = 0;
            for (i = ntt_start[s]; i < ntt_start[s+1]; i++)
            {
					if (ntt_action[i] != 0)
					{
						n++;
						x = ntt_action [i];
						h = ntt_symb [i];
						P_SYMBOL (-h);
						if (x > 0) prt_sta (" goto           %4d\n", x);
						else
                  {
                     p = -x;
                     prt_sta (" reduce         ");
     		  	         p_prod (p, -1, "", "\n");
                  }
					}
            }
				if (n > 0) prt_sta ("\n");
			/*	if (f_camefrom[s+1] > f_camefrom[s])
				{
					prt_sta ("   from:");
					for (i = f_camefrom[s]; i < f_camefrom[s+1]; i++)
					{
	               prt_sta (" %d", camefrom[i]);
					}
					prt_sta ("\n");
				}  */
         }
      }
      PRT_STA (-1);
		prt_sta ("\n\n");
}

////////////////////////////////////////////////////////////////////////////////

int   PG_PrintStates::C_max_symbl (int s)
{
      int max_symbl = 20;
      for (int i = tt_start[s]; i < tt_start[s+1]; i++)
      {
			if (tt_action[i] != 0)
			{
				int t   = tt_symb [i];
            int len = (int)strlen (term_name[t]);
            if (len > max_symbl) max_symbl = len;
			}
      }
   // if (optn[PG_NONDETER])
      {
         for (int i = nd_item[s]; i < nd_item[s+1]; i++)
         {
            int t   = nd_term[i];
            int len = (int)strlen (term_name[t]);
            if (len > max_symbl) max_symbl = len;
         }
      }
      if (la_start != NULL)
      {
         for (int i = la_start[s]; i < la_start[s+1]; i++)
         {
            int t   = la_symb [i];
            int len = (int)strlen (term_name[t]);
            if (len > max_symbl) max_symbl = len;
         }
      }
      for (int i = ntt_start[s]; i < ntt_start[s+1]; i++)
      {
			if (ntt_action[i] != 0)
			{
				int h   = ntt_symb [i];
            int len = (int)strlen (head_name[h]);
            if (len > max_symbl) max_symbl = len;
			}
      }
      return max_symbl;
}

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::P_HEAD (int s)
{
      int L = 0;
      prt_sta ("           ");
      L = p_head (s, " ");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::P_SYMBOL (int s)
{
      int L = 0;
		if (s >= 0)           prt_sta ("     %4d  ",  s);
		else if (s == -32767) prt_sta ("           "   );
		else if (s == -32768) prt_sta ("           "   );
		else                  prt_sta ("     %4d  ", -s);
      L = p_sym60 (s, " ");
}

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::P_SYMBOL (int s, char* prefix)
{
      int L = 0;
		if (s >= 0)           prt_sta ("%s%4d  ", prefix, s);
		else if (s == -32767) prt_sta ("%s      ", prefix); // (default)
		else if (s == -32768) prt_sta ("           ");      // (error)
		else                  prt_sta ("     %4d  ", -s);
      L = p_sym60 (s, " ");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::PRT_STA (int s)
{
      int k, i, f, p;

		if (s == -1)
		{
			prt_sta ("END ................................................................................................\n\n", s);
			return;
		}

      if (optn[PG_NONDETER] == 0)
      {
         if (N_Conflicts[s] == 0)
            prt_sta ("STATE %d ..........................................................................................\n\n", s);
         else
            prt_sta ("STATE %d conflicts = %d ...........................................................................\n\n", s, N_Conflicts[s]);
      }
      else
      {
         if (nd_state[s] == 2)
            prt_sta ("STATE %d nd_max = 2 ..............................................................................\n\n", s);
         else if (nd_state[s] > 2)
            prt_sta ("STATE %d nd_max > 2 = %d .........................................................................\n\n", s, nd_state[s]);
         else
            prt_sta ("STATE %d .........................................................................................\n\n", s);
      }

      for (k = f_kernel [s]; k < f_kernel [s+1]; k++)
      {
         i = kernel [k];
         if (item[i].symb != -32767) // Not final item?
         {
            prt_sta ("   * ");
            p_prod (item[i].prod, item[i].dot, "", "\n");
         }
      }
      for (f = f_final [s]; f < f_final [s+1]; f++)
      {
         p = item [final[f]].prod;
         prt_sta ("   * ");
         p_prod (p, -1, "", "\n");
      }
		prt_sta("\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_PrintStates::p_prod (int p, int dot, char *before, char* after)
{
      int t, u, d;
      prt_sta ("%s%4d  %s -> ", before, p, head_name [head_sym [p]]);
      t = F_tail [p];
      u = F_tail [p+1];
      d = t + dot;
      if (dot == -1) d = u;
      for (;;)
      {
         if (t == d) prt_sta (". ");
         if (t >= u) break;
         p_sym (Tail [t], " ");
         t++;
      }
      prt_sta ("%s", after);
}

///////////////////////////////////////////////////////////////////////////////

int	PG_PrintStates::p_head (int s, char *sp)
{
		int len;
      char *p;
      p = head_name[s];
      prt_sta ("%s%s", p, sp);
		len = (int)strlen(p) + (int)strlen(sp);
		return (len);
}

///////////////////////////////////////////////////////////////////////////////

int	PG_PrintStates::p_sym (int s, char *sp)
{
		int len;
      char *p;
      if (s == -32767)            /* Default symbol? */
      {
         p = "(default)";
      }
      else if (s == -32768)       /* Error symbol? */
      {
         p = "(error)";
      }
      else if (s >= 0)            /* Terminal symbol? */
		{
         p = term_name[s];
		}
      else                        /* Nonterminal symbol? */
		{
         p = head_name[-s];
		}
      prt_sta ("%s%s", p, sp);
		len = (int)strlen(p) + (int)strlen(sp);
		return (len);
}

///////////////////////////////////////////////////////////////////////////////

int	PG_PrintStates::p_sym60 (int s, char *sp)
{
      char *p;
      if (s == -32767)            /* Default symbol? */
      {
         p = "(default)";
      }
      else if (s == -32768)       /* Error symbol? */
      {
         p = "(error)";
      }
      else if (s >= 0)            /* Terminal symbol? */
		{
         p = term_name[s];
		}
      else                        /* Nonterminal symbol? */
		{
         p = head_name[-s];
		}
      prt_sta ("%-30s%s", p, sp);
		return (0);
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

