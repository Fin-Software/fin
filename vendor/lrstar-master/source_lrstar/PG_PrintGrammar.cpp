
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
		#include "PG_Main.h"

      static FILE* fp;
      static int   nont_on;

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintGrammar::PrintGrammar ()
{
      char fid [MAX_PATH];
      int  h, p, t, nh;

      strcpy (fid, gdn);
      strcat (fid, gfn);
      strcat (fid, gft);
      strcat (fid, ".grammar.txt");

	// GRAMMAR NAME

		fprintf (grmfp, "\n/* %s grammar */\n\n", gfn);

		if (optn[PG_GRAMMAR] == 0)
		{
			fprintf (grmfp, "Option '/g=0' was specified.\n\n");
			goto Ret;
		}

	// TERMINALS.

		int *seq, i, n;
		ALLOC (seq, N_terms);
		SORTNAMES (const_name, N_terms, seq);

		fprintf (grmfp, "/* Terminal Symbols */\n\n");
		n = 0;
		for (t = 0; t < N_terms; t++)
		{
			char* con;
			i = seq[t]; // In alphabetical order.
			if (term_const[t] >= 0)
			{
				n++;
				con = const_name[term_const[t]];
				fprintf (grmfp, "       %-24s  %s;\n", con, term_name[t]);
			}
		}
		if (n) fprintf (grmfp, "\n");

		SORTNAMES (term_name, N_terms, seq);
		for (t = 0; t < N_terms; t++)
		{
			i = seq[t]; // In alphabetical order.
		//	fprintf (grmfp, " %4d  %-24s  ", i, term_name[i]);
			fprintf (grmfp, " %4d  %s\n",    t, term_name[t]);
		}
		fprintf (grmfp, "\n");

		FREE (seq, N_terms);

   // PRODUCTIONS.

		fprintf(grmfp, "/* Productions */\n\n");

		nh = N_heads;
      for (h = 0; h < nh; h++)
      {
			fprintf (grmfp, " %4d       %s\n", h, head_name[h]);
         for (p = F_prod[h]; p < F_prod[h+1]; p++)
         {
				if (p == F_prod[h])
					  fprintf (grmfp, "    %5d      : ", p);
            else fprintf (grmfp, "    %5d      | ", p);

            for (t = F_tail[p]; t < F_tail[p+1]; t++)
            {
               p_tail ("", Tail[t], " ");
				}
				fprintf (grmfp, "\n");
         }
			fprintf (grmfp, "               ;\n\n");
      }
		fprintf (grmfp, "/* End of %s grammar \n\n", gfn);
Ret:	fclose (grmfp);
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::p_head (char* before, int s, char* after)
{
		char* p;
      if (s <= 0)
			  p = head_name[-s]; // Nonterminal
      else p = term_name[s];	// Terminal

      fprintf (grmfp, "%s%s%s", before, p, after);
      return 1;
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::p_tail (char* before, int s, char* after)
{
		char* p;
      if (s < 0)
			  p = head_name[-s]; // Nonterminal
      else p = term_name[s];	// Terminal

      fprintf (grmfp, "%s%s%s", before, p, after);
      return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_PrintGrammar::print_struc()
{
	   if (optn[PG_GRAMMAR] == 2)
		{
			int  i;
			int* seq;
			prt_grm ("Constants\n");
			for (i = 0; i < n_constants; i++)
			{
				prt_grm ("%5d %s\n", i, Defcon_name[i]);
			}
			prt_grm ("\n");

			prt_grm ("Terminals\n");
			for (i = 0; i < N_terms; i++)
			{
				prt_grm ("%5d %s\n", i, term_name[i]);
			}
			prt_grm ("\n");

			prt_grm ("Nonterminals\n");
			ALLOC (seq, N_heads);
			SORTNAMES (head_name, N_heads, seq);
			for (i = 0; i < N_heads; i++)
			{
				prt_grm ("%5d %s\n", seq[i], head_name[seq[i]]);
			}
			FREE (seq, N_heads);
			prt_grm ("\n");

			prt_grm ("Terminal Actions\n");
			ALLOC (seq, N_tacts);
			SORTNAMES (Tact_start, N_tacts, seq);
			for (i = 0; i < N_tacts; i++)
			{
				prt_grm ("%5d %s\n", seq[i], Tact_start[seq[i]]);
			}
			FREE (seq, N_tacts);
			prt_grm ("\n");

			prt_grm ("Nodes\n");
			ALLOC (seq, N_nodes);
			SORTNAMES (Node_start, N_nodes, seq);
			for (i = 0; i < N_nodes; i++)
			{
				prt_grm ("%5d %s\n", seq[i], Node_start[seq[i]]);
			}
			FREE (seq, N_nodes);
			prt_grm ("\n");

			prt_grm ("Node Actions\n");
			ALLOC (seq, N_nacts);
			SORTNAMES (Nact_start, N_nacts, seq);
			for (i = 0; i < N_nacts; i++)
			{
				prt_grm ("%5d %s\n", seq[i], Nact_start[seq[i]]);
			}
			FREE (seq, N_nacts);
			prt_grm ("\n");

			prt_grm ("Strings\n");
			for (i = 0; i < N_strings; i++)
			{
				prt_grm ("%5d %s\n", i, Str_start[i]);
			}
			prt_grm ("\n");

			prt_grm ("Integers\n");
			for (i = 0; i < N_ints; i++)
			{
				prt_grm ("%5d %s\n", i, Int_start[i]);
			}
			prt_grm ("\n");

			prt_grm ("Arguments\n");
			for (i = 0; i < N_args; i++)
			{
				prt_grm ("%5d %5d\n", i, Arg_numb[i]);
			}
			prt_grm ("\n");

			prt_grm ("End of lists.\n");
		}
}

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintGrammar::PrintHtml ()
{
      char fid [MAX_PATH];
      int  h, p, t, nh;

      nont_on = 0;
      strcpy (fid, gdn);
      strcat (fid, gfn);
      strcat (fid, gft);
      strcat (fid, ".grammar.html");
		if (optn[PG_GRAMMARHTML] == 0)
		{
			unlink (fid);
			return;
		}
      fp = fopen (fid, "w");
      if (fp == NULL)
      {
         n_errors++;
         prt_log ("\nFile %s cannot be created.\n", fid);
			return;
      }

		fprintf (fp, "<head>\n");
		fprintf (fp, "<title>%s grammar.</title>\n", gfn);
		fprintf (fp, "<meta name=\"description\" content=\"%s grammar.\">\n", gfn);
		fprintf (fp, "<style>\n");
      fprintf (fp, "i         { color: #cc0000; font-style: normal; }\n");
      fprintf (fp, "u         { color: #0000cc; text-decoration: none; }\n");
		fprintf (fp, "a:link    { color: #000000; text-decoration: none;      }\n");
		fprintf (fp, "a:visited { color: #000000; text-decoration: none;      }\n");
		fprintf (fp, "a:hover   { color: #000000; text-decoration: underline; }\n");
		fprintf (fp, "a:active  { color: #000000; text-decoration: underline; }\n");
      fprintf (fp, "pre       { font-family: consolas, courier new; font-size: 15px; line-height: 20px; }\n");
		fprintf (fp, "</style>\n");
		fprintf (fp, "</head>\n");
		fprintf (fp, "<basefont face=\"arial\">\n");
		fprintf (fp, "<body bgcolor=\"white\" text=\"#000000\">\n");

		if (optn[PG_GRAMMARHTML] == 0)
		{
			fprintf (fp, "<pre>\n            'h' option was not specified.</pre>\n");
			goto Ret;
		}

		fprintf (fp, "<table cellspacing=20 cellpadding=0>\n");
		fprintf (fp, "<tr>\n<td valign=top width=350>\n\n");

   // NONTERMINALS.

      int  i;
      int* seq;
		ALLOC (seq, N_heads);
  		SORTNAMES (head_name, N_heads, seq);
		fprintf (fp, "<pre>        Nonterminal Symbols\n</pre>\n\n");
		nh = N_heads;
		fprintf (fp, "<pre>\n");
      for (i = 0; i < nh; i++)
      {
         if (head_type[seq[i]] & GENERATED) continue;
         fprintf (fp, "%4d    ", seq[i]);
         ph_nont ("", seq[i], "\n");
      }
		fprintf (fp, "</pre>\n\n");
		FREE (seq, N_heads);

   // TERMINALS.

		ALLOC (seq, N_terms);
  		SORTNAMES (term_name, N_terms, seq);
		fprintf (fp, "<pre>        Terminal Symbols\n</pre>\n\n");
		fprintf (fp, "<pre>\n");
      for (t = 0; t < N_terms; t++)
      {
         if (*term_name[seq[t]] == '<')
         {
            fprintf (fp, "%4d    ", seq[t]);
            ph_tail ("", seq[t], "\n");
         }
      }
      for (t = 0; t < N_terms; t++)
      {
         if (*term_name[seq[t]] == '{')
         {
            fprintf (fp, "%4d    ", seq[t]);
            ph_tail ("", seq[t], "\n");
         }
      }
      for (t = 0; t < N_terms; t++)
      {
         if (term_name[seq[t]][0] == '\''
         &&  term_name[seq[t]][1] >= 'a'
         &&  term_name[seq[t]][1] <= 'z')
         {
            fprintf (fp, "%4d    ", seq[t]);
            ph_tail ("", seq[t], "\n");
         }
      }
      for (t = 0; t < N_terms; t++)
      {
         if (term_name[seq[t]][0] == '\''
         &&  term_name[seq[t]][1] >= 'A'
         &&  term_name[seq[t]][1] <= 'Z')
         {
            fprintf (fp, "%4d    ", seq[t]);
            ph_tail ("", seq[t], "\n");
         }
      }
      for (t = 0; t < N_terms; t++)
      {
         if (*term_name[seq[t]] == '<') continue;
         if (*term_name[seq[t]] == '{') continue;
         if ( term_name[seq[t]][0] == '\''
         &&   term_name[seq[t]][1] >= 'a'
         &&   term_name[seq[t]][1] <= 'z') continue;
         if ( term_name[seq[t]][0] == '\''
         &&   term_name[seq[t]][1] >= 'A'
         &&   term_name[seq[t]][1] <= 'Z') continue;
         fprintf (fp, "%4d    ", seq[t]);
         ph_tail ("", seq[t], "\n");
      }
		fprintf (fp, "</pre>\n\n");
		FREE (seq, N_terms);

		fprintf (fp, "</td>\n<td valign=top>\n\n");

   // PRODUCTIONS.

		fprintf (fp, "<pre>           %s grammar (output from <a href=\"http://lrgen.org/\" target=\"_blank\">%s %s</a>).\n</pre>\n", gfn, program, version);
		nh = N_heads;
      for (h = 0; h < nh; h++)
      {
      // if (head_type[h] & GENERATED) continue;
			fprintf (fp, "<a name=\"%s\"></a>\n<pre>", head_name[h]);
         fprintf (fp, "%4d       ", h);
         ph_head ("", h, "\n");
         for (p = F_prod[h]; p < F_prod[h+1]; p++)
         {
            if (p == F_prod[h]) fprintf (fp, "    %4d      : ", p);
            else
            {
               if (Priority[p]) fprintf (fp, "    %4d     .| ", p);
               else             fprintf (fp, "    %4d      | ", p);
            }
            for (t = F_tail [p]; t < F_tail [p+1]; t++)
            {
               ph_tail ("", Tail [t], " ");
				}
				fprintf (fp, "\n");
         }
			fprintf (fp, "              ;\n</pre>\n");
      }
		fprintf (fp, "<pre>\n           End of %s grammar listing.\n</pre>\n", gfn);
		for (h = 0; h < 30; h++)
		{
			fprintf (fp, "<pre><br></pre>\n");
		}
		fprintf (fp, "</td>\n</tr>\n</table>\n");

Ret:	fprintf (fp, "</body>\n");
		fprintf (fp, "</html>\n\n");
		fclose (fp);
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::ph_nont (char* before, int s, char* after)
{
		return (ph_sym (1, 1, before, s, after));
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::ph_head (char* before, int s, char* after)
{
		return (ph_sym (1, 0, before, s, after));
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::ph_tail (char* before, int s, char* after)
{
		return (ph_sym (0, 1, before, s, after));
}

////////////////////////////////////////////////////////////////////////////////

int	PG_PrintGrammar::ph_sym (int nont_on, int tail_on, char* before, int s, char* after)
{
      int i, j, l;
      char string[1024];
      char* p = "undefined";

      if (nont_on)      // Nonterminal?
      {
         p = head_name[s];
      }
      else if (tail_on) // Tail?
      {
         if (s < 0)
         {
            nont_on = 1;
            p = head_name[-s];
         }
         else p = term_name[s];
      }

		j = 0;
		l = (int)strlen (p);
      if (l > 1023) l = 1023;
		for (i = 0; i < l; i++)
		{
			if (p[i] == '<')
			{
				string[j++] = '&';
				string[j++] = 'l';
				string[j++] = 't';
				string[j++] = ';';
			}
			else if (p[i] == '>')
			{
				string[j++] = '&';
				string[j++] = 'g';
				string[j++] = 't';
				string[j++] = ';';
			}
			else
			{
				string[j++] = p[i];
			}
		}
   	string [j] = 0;
      fprintf (fp, "%s", before);
      if (nont_on)
      {
         if (tail_on)
         {
         // if ((head_type[-s] & GENERATED) == 0)
            fprintf (fp, "<a href=\"#%s\">", p); // Link to NT definition.
         }
      }
      else
      {
         if (tail_on)
         {
            if      (*p == '<') fprintf (fp, "<i>");
            else if (*p == '{') fprintf (fp, "<font color=\"#00cc00\">");
            else                fprintf (fp, "<u>");
         }
      }
      fprintf (fp, "%s", string);
      if (nont_on)
      {
         if (tail_on)
         {
         // if ((head_type[-s] & GENERATED) == 0)
            fprintf (fp, "</a>"); // Link end.
         }
      }
      else
      {
         if (tail_on)
         {
            if      (*p == '<') fprintf (fp, "</i>");
            else if (*p == '{') fprintf (fp, "</font>");
            else                fprintf (fp, "</u>");
         }
      }
      fprintf (fp, "%s", after);
      return ((int)strlen(p) + (int)strlen(before) + (int)strlen(after));
}

////////////////////////////////////////////////////////////////////////////////

void  PG_PrintGrammar::ph_spaces (int ns)
{
      if (ns < 0)
      {
         ns = 5 + (ns % 5);
         if (ns == 5) return;
      }
      spaces [ns] = 0;
      fprintf (fp, "%s", spaces);
      spaces [ns] = ' ';
}

////////////////////////////////////////////////////////////////////////////////


