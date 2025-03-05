
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "LG_Global.h"
		#include "LG_CheckGrammar.h"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  LG_CheckGrammar::PrintGrammar ()
{
      int line_length;
      int h, p, t, s;

   // if (n_errors) return;

      if (!optn [LG_GRAMMAR])
		{
			option_grammar = 1;
	      prt_grm ("\n/* %s%s grammar */\n\n", gfn, gft);
	      prt_grm ("/* 'g' option was not specified */\n");
			return;
		}
      prt_grm ("\n/* %s%s grammar */\n\n", gfn, gft);

   /* NONTERMINALS. */

      for (h = 0; h < n_heads; h++)
      {
			if (head_type != NULL && head_type[h] & SETNAME)
			     prt_grm ("$%5d      ", h);
         else prt_grm ( "%6d      ", h);
         prt_head (h, "");

		//	printf ("\n%s\n", head_name[h]);
         for (p = f_prod [h]; p < l_prod [h]; p++)
         {
			//	printf ("-> ");
            line_length = 16;
				if (prod_type != NULL)
				{
					if (prod_type[p] == PRODARROW) prt_grm ("\n   %6d      -> ", p);
					else if (prod_type[p] == PRODADD  ) prt_grm (" | ");
					else if (prod_type[p] == PRODSUB  ) prt_grm (" - ");
					else if (prod_type[p] == PRODTO   ) prt_grm ("..");
				}
				else prt_grm ("\n   %6d      -> ", p);

            for (t = f_tail [p]; t < l_tail [p]; t++)
            {
               s = tail [t];
				//	if (s < 0) printf ("%s ", head_name[-s]);
				//	else       printf ("%s ", term_name[ s]);
					char* ch = " ";
					if (t == l_tail[p]-1) ch = "";
               line_length += prt_sym2 (s, ch);
               if (line_length > 100 && t+1 < l_tail[p])
               {
                  prt_grm ("\n                ");
                  line_length = 16;
               }
            }
				if (h == 1)
				{
					prt_grm (" (%d)", ret_numb[p]);
				}

			//	printf ("\n");
         }
         prt_grm ("\n\n");
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  LG_CheckGrammar::PRT_SYMB (int s)
{
      int L;
      if (s == -32767)
      {
         prt_grm ("        (default) ");
         L = 10;
      }
      else
      {
         prt_grm ("        ");
         L = prt_sym2 (s, " ");
      }
		L = max_headl-L+1;
		if (L < 0) L = 0;
      spaces [L] = 0;
      prt_grm ("%s", spaces);
      spaces [L] = ' ';
}

int   LG_CheckGrammar::prt_sym2 (int s, char *after)
{
      char *p;
      if (s >= 0)
		{
			if (s >= N_terms) p = "???";
			else              p = term_name[s];
	      prt_grm ("%s%s", p, after);
		}
      else
		{
			if (-s >= n_heads) p = "???";
			else               p = head_name[-s];
	      prt_grm ("%s%s", p, after);
		}
      return ((int)strlen(p) + (int)strlen(after));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  LG_CheckGrammar::PRT_HEAD (int s)
{
      int L;
      prt_grm ("        ");
      L = PRT_HEAD (s, " ");

		L = max_headl-L+1;
		if (L < 0) L = 0;
      spaces [L] = 0;
      prt_grm ("%s", spaces);
      spaces [L] = ' ';
}

int   LG_CheckGrammar::PRT_HEAD (int s, char *after)
{
      char *p;
      if (s < 0) p = "(ERROR)";
      else       p = head_name[s];
      prt_grm ("%s%s", p, after);
      return ((int)strlen(p) + (int)strlen(after));
}

int   LG_CheckGrammar::prt_head (int s, char *after)
{
      char *p;
      if (s < 0) p = "(ERROR)";
      else       p = head_name[s];
      prt_grm ("%s%s", p, after);
      return ((int)strlen(p) + (int)strlen(after));
}

//
////////////////////////////////////////////////////////////////////////////////


















