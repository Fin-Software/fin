
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
		#include "PG_Main.h"
		#include "PG_CheckGrammar.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   PG_CheckGrammar::CheckGrammar ()
{
      if (optn[PG_VERBOSE])
           prt_log     ("Grammar  %7d rules, %d terminals, %d nonterminals.\n", N_prods, N_terms, N_heads);
		else prt_logonly ("Grammar  %7d rules, %d terminals, %d nonterminals.\n", N_prods, N_terms, N_heads);

		eof_term = Tail [F_tail[0]+1];

      C_LENG ();
      C_NULLS ();
      C_HEADSYM ();
		check_first_args ();
      P_UNUSED_OR_UNDECLARED ();
      P_USELESS_PROD ();
      P_UNREACHABLES ();
      P_UNREDUCIBLES ();

      FREE (term_start, N_terms);
      FREE (term_end,   N_terms);
      FREE (term_line,  N_terms);

		if (n_errors) return (0);
      return (1);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  prt_chars (char* sym, char ch, char prev)
{
		prt_warnscreen ("%c", prev);
		int len = (int)strlen (sym);
		while (len-- > 0)
		{
			prt_warnscreen("%c", ch);
		}
}

void  prt_chars (int len, char ch)
{
		while (len-- > 0)
		{
			prt_warnscreen("%c", ch);
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::check_first_args()
{
      if (optn[PG_ARGPOINTATNT] == 0) return;
		char *name, *sym;
		int p, argx, tail, n = 0;
		for (p = 0; p < N_prods; p++)
		{
			if (F_parg[p] >= 0)
			{
				argx = Arg_numb[F_parg[p]] - 1;
				tail = Tail[F_tail[p] + argx];
				if (tail < 0)
				{
					n++;
					n_warnings++;
					name = head_name[-tail];
					prt_warnscreen("\n%s(%04d) : %s -> ", grmfid, prod_line[p], head_name[head_sym[p]]);
					for (int t = F_tail[p]; t < F_tail[p + 1]; t++)
					{
						tail = Tail[t];
						if (tail < 0) sym = head_name[-tail];
						else          sym = term_name[ tail];
						prt_warnscreen("%s ", sym);
					}
					prt_warnscreen("\n%s(%04d) : ", grmfid, prod_line[p]);
					prt_chars (head_name[head_sym[p]],'.','.');
					prt_chars (2,'.');
					int t, i = 0;
					for (t = F_tail[p]; t < F_tail[p + 1]; t++)
					{
						tail = Tail[t];
						if (tail < 0) sym = head_name[-tail];
						else          sym = term_name[ tail];
						if (i++ == argx) prt_chars (sym,'^','.');
						else             prt_chars (sym,'.','.');
					}
					prt_warnscreen ("\n%s(%04d) : Warning, Argument %d points at nonterminal %s\n", grmfid, prod_line[p], argx+1, name);
				}
			}
		}
		if (n) prt_warnscreen("\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::C_LENG () /* Compute maximum symbol length. */
{
      int i, L;
      if (optn [PG_BACKSLASH])
      {
         for (i = 0; i < N_terms; i++)
         {
            fix_backslash (term_name [i]);
         }
      }
		max_terml = 30;
		for (i = 0; i < N_terms; i++)
		{
			L = (int)strlen (term_name[i]);
			if (L > max_terml) max_terml = L;
		}
		max_headl = 30;
		for (i = 0; i < N_heads; i++)
		{
			L = (int)strlen (head_name[i]);
			if (L > max_headl) max_headl = L;
		}
		if (max_headl > max_terml) max_symbl = max_headl;
		else                       max_symbl = max_terml;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::C_NULLS ()
{
      int h, p, t, s, n;

      n_nulls = 0;
      ALLOC (nullable, N_heads);
      FASTINI (0, nullable, N_heads);
      do
		{
         n = 0;
         for (h = 0; h < N_heads; h++)
         {
            if (nullable [h] == 0)
            {
               for (p = F_prod [h]; p < F_prod [h+1]; p++)
               {
                  for (t = F_tail [p]; t < F_tail [p+1]; t++)
                  {
                     if ((s = Tail [t]) < 0)
                     {
                        if (nullable [-s] == 0) goto nextp;
                     }
                     else goto nextp;
                  }
                  n++;
                  n_nulls++;
                  nullable [h] = 1;
                  goto nexth;
nextp:            continue;
               }
            }
nexth:      continue;
         }
      }
      while (n > 0);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::C_HEADSYM ()
{
      int h, p;
      ALLOC (head_sym,  N_prods);
      ALLOC (prod_len,  N_prods);
      for (h = 0; h < N_heads; h++)
      {
         for (p = F_prod[h]; p < F_prod[h+1]; p++)
         {
            head_sym[p] = h;
            prod_len[p] = F_tail[p+1] - F_tail[p];
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::P_UNUSED_OR_UNDECLARED ()
{
      int t;
   // Define whether <error> symbol was used in the grammar ...
      error_used = 0;
      if (term_type[0] & TAIL) error_used = 1;

   // Check terminal symbols for usage in the grammar rules ...
		for (t = 1; t < N_terms; t++)
		{
			if (!(term_type[t] & UNDECLARED)) // Declared ?
			{
				if (!(term_type[t] & TAIL)) // Not used in grammar?
				{
					if (!(term_type[t] & ARGUMENT)) // Not used as argument?
					{
						if (term_const[t] >= 0) // Defined constant for this term?
						{
							prt_warning ("Constant %s was declared but not used anywhere",
								term_start[t], term_end[t], term_line[t]);
						}
						else
						{
							prt_warning ("Terminal %s was declared but not used anywhere",
								term_start[t], term_end[t], term_line[t]);
						}
					}
				}
			}
			else // Not declared!
			{
				if (!(term_type[t] & TAIL)) // Not used in grammar?
				{
					if ((term_type[t] & ARGUMENT)) // Used as argument?
					{
						prt_warning ("Argument %s was not used in the grammar",
						term_start[t], term_end[t], term_line[t]);
					}
				}
			}
		}
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::P_USELESS_PROD ()
{
      int h, p;
		for (h = 1; h < N_heads; h++)
		{
			for (p = F_prod[h]; p < F_prod[h+1]; p++)
			{
				if ((F_tail[p+1]-F_tail[p]) == 1)
				{
					if (h == -Tail[F_tail[p]])
					{
						prt_log ("%s(%04d) : ", grmfid, prod_line[p]);
						p_prod (-p, -1, "");
						prt_log ("\n");
						prt_error ("Useless production", 0, 0, prod_line[p]);
					}
				}
			}
		}
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::P_UNREACHABLES ()
{
      char *h_vect;
      int  *h_list, h, p, t, s, i, nh;

      ALLOC (h_vect, N_heads);
      ALLOC (h_list, N_heads);
      memset (h_vect, 0, N_heads);

      h_vect [0] = 1; // Mark it used.
      h_list [0] = 0; // Add zero to list.
      nh         = 1; // Number of heads encountered.

      for (i = 0; i < nh; i++)
      {
         h = h_list [i];                                /* Pick next head.   */
         for (p = F_prod [h]; p < F_prod [h+1]; p++)    /* All of its rules. */
         {
            for (t = F_tail [p]; t < F_tail [p+1]; t++) /* All of its tails. */
            {
               if ((s = Tail [t]) < 0)                  /* Nonterminal?      */
               {
                  if (h_vect [-s] == 0)                 /* Not marked yet?   */
                  {
                     h_vect [-s] = 1;                   /* Mark it used.     */
                     h_list [nh++] = -s;                /* Add it to list.   */
                  }
               }
            }
         }
      }

      for (h = 0; h < N_heads; h++)
      {
		// if (h_vect[h] == 0 && *head_name[h] != '$')  /* Not used?         */
         if (h_vect[h] == 0)  /* Not used?         */
         {
            if (head_line[h] != 0) // Added by PBM, 2018-08-16.
				prt_warning ("Nonterminal symbol %s is not reachable from the goal symbol",
					head_name[h], 0, head_line[h]);
         }
      }
      FREE (h_list, N_heads);
      FREE (h_vect, N_heads);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::P_UNREDUCIBLES ()
{
      char *red;
      int  h, p, t, s, n, m;

      ALLOC (red, N_heads);
      memset (red, 2, N_heads); /* undefined */
      m = 0;
      do
      {
         n = 0;
         for (h = 0; h < N_heads; h++)
         {
            if (red [h] == 2)
            {
               for (p = F_prod [h]; p < F_prod [h+1]; p++)
               {
                  for (t = F_tail [p]; t < F_tail [p+1]; t++)
                  {
                     if ((s = Tail [t]) < 0)
                     {
                        if (red [-s] != 1) goto nextp;
                     }
                  }
                  n++;
                  red [h] = 1;
                  goto nexth;
nextp:            continue;
               }
            }
nexth:      continue;
         }
         m += n;
      }
      while (n > 0);
      if (m < N_heads)
      {
         for (h = 0; h < N_heads; h++)
         {
            if (red [h] != 1)
            {
					prt_error ("Nonterminal symbol %s is in a cycle, cannot derive anything", head_name[h], 0, head_line[h]);
            }
         }
      }
      FREE (red, N_heads);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_CheckGrammar::p_prod (int p, int dot, char *before)
{
      int t, u, d;
		if (p < 0)
		{
			p = -p;
	      prt_log ("%s%s -> ", before, head_name [head_sym [p]]);
		}
		else
		{
			prt_log ("%s%5d %s -> ", before, p, head_name [head_sym [p]]);
		}
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
      prt_log ("\n");
}

///////////////////////////////////////////////////////////////////////////////

int	PG_CheckGrammar::p_sym (int s, char *sp)
{
      char *p;

      if (s >= 0)                 /* Terminal symbol? */
         p = term_name[s];
      else                        /* Nonterminal symbol? */
         p = head_name[-s];

      prt_log ("%s%s", p, sp);
      return ((int)strlen(p) + (int)strlen(sp));
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////


