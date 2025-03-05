
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
		#include "PG_Main.h"

      char* program = "LRSTAR";
      char* version = "24.0.025";
      #include <cstdint>
      #if INTPTR_MAX == INT64_MAX
      char* bits    = "64b";
		#else
      char* bits    = "32b";
		#endif
      char* copywrt = "Copyright Paul B Mann";

      OPTION PGOption[]= // Parser Generator Options
		{
			"crr",		"Conflict report for Reduce-Reduce",		PG_CONREDUCE,			0,
		  	"csr",		"Conflict report for Shift-Reduce",			PG_CONSHIFT,			0,
			"fsa",		"Force shift actions in conflicts",			PG_FORCESHIFT,			0,
							"",			"",									1,				         0,
			"g",			"Grammar listing",								PG_GRAMMAR,				1,
			"gh",			"Grammar HTML format output",					PG_GRAMMARHTML,		0,
							"",			"",									1,				         0,
			"st",			"States listing",							   	PG_STATES,	   		0,
			"ci",			"Case-insensitive input",						PG_INSENSITIVE,		0,
							"",			"",									1,				         0,
			"pt",       "Parser-table creation",                  PG_PARSERTABLES,     1,
			"o",			"Optimize parser-tables",						PG_OPTIMIZE,			0,
			"m",			"Minimize parser-tables",						PG_MINIMIZE,			0,
							"",			"",									1,				         0,
			"k",			"k-lookaheads for LR(*) parsing",			PG_LOOKAHEADS,		   1,
							"",			"",									1,				         0,
			"ast",		"AST activated in parser",						PG_ASTCONST,			1,
			"exp",		"Expecting-list activated",					PG_EXPECTING,			1,
			"ta",			"Terminal-actions activated",					PG_TERMACTIONS,	   1,
			"na",		   "Node-actions activated",						PG_NODEACTIONS,      1,
							"",			"",									1,				         0,
			"d",			"Debug parser activated.",						PG_DEBUG,			   0,
			"dt",			"Debug trace activated.",						PG_DEBUGTRACE,		   0,
							"",			"",									1,				         0,
			"v",			"Verbose listing (0,1,2)",						PG_VERBOSE,				2,
			"w",			"Warnings listed on screen",					PG_WARNINGS,			0,
							"",			"",									1,				         0,
			"wa",			"Warning, arguments -> nonterminals",	   PG_ARGPOINTATNT,   	0,
			"wc",			"Warning, constants not used",			   PG_CONSTANTSUNUSED,	0,
			"wk",			"Warning, keywords not declared",			PG_KEYWORDUNDECL,		0,
			"wm",			"Warning, mixed case keywords",				PG_MIXEDCASEUNDECL,	0,
			"wu",			"Warning, upper case keywords",				PG_UPPERCASEUNDECL,	0,
							"",			"",									0,				         0
		};

///////////////////////////////////////////////////////////////////////////////

int   PG_Main::Main (int na, char** arg)
{
      if (Start (na, arg))
		{
			parse_init (optn[MAX_SYM], grmfid);
			if (parse (input_start) > 0)
			{
				PrintHtml();
				PrintGrammar();
				if (CheckGrammar())
				{
					DeleteLexFile();
					OutputLexFile();
               if (BuildLR0())
					{
						if (ComputeLA())
						{
							if (OptimizeStates())
							{
								PrintStates();
								if (optn[PG_PARSERTABLES])
								{
									CreateTables();
									GenerateOtherFiles ();
									GenerateParserTables ();
								}
							}
							PrintStats();
						}
			      }
				}
			}
			parse_term ();
			inputt ();
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_Main::Start (int na, char** arg) /* Display program information. */
{
		int ne = 0;
      time1 = clock();
		PRT_ARGS (na, arg, 0);
		if (na == 1) // No arguments?
		{
			printf ("|\n");
			printf ("|   LR(*) PARSER GENERATOR\n|\n");
			printf ("|   lrstar <grammar> [<option>...]\n|\n");
			ShowOptions ();
			Quit ();
		}

		if (!get_fid (arg[1], gdn, gfn, gft)) Quit ();

		mystrlwr (gft);
		if (*gft == 0) strcpy (gft, ".grm"); // Default filetype.
		else if (strcmp (gft, ".lex") == 0)
      {
         printf ("Cannot use a file type of \"%s\", use \".grm\" instead.\n", gft);
			Quit ();
      }
		else if (strcmp (gft, ".lgr") == 0)
      {
         printf ("Cannot use a file type of \"%s\", use \".grm\" instead.\n", gft);
			Quit ();
      }

		strcpy (grmfid, gdn);
		strcat (grmfid, gfn);
		strcat (grmfid, gft);

      if (open_log (grmfid) == 0) Quit ();

      PRT_ARGS (na, arg, 1);

		if (!SetOptions (na, arg)) Quit ();

		char dn[256], fn[256], ft[256];
		if (get_fid (arg[0], dn, fn, ft)    == 0) Quit ();
		if (GetMaxValues (dn) == 0) Quit ();
		if (!open_con  (grmfid)) Quit ();
		if (!open_grm  (grmfid)) Quit ();
		if (!open_sta  (grmfid)) Quit ();
		if (!open_warn (grmfid)) Quit ();

		if (!inputi ("File not found")) Quit ();

	//	prt_log ("Reading \"%s%s\" ...\n", gfn, gft);

		line_ptr = ::line_ptr;
		input_start = ::input_start;
		input_end = ::input_end;

		for (int i = 0; i < 159; i++) spaces[i] = ' ';

		memory_usage = 0;
		memory_max = 0;
		n_warnings = 0;
		n_errors = 0;
		return 1;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_Main::SetOptions (int na, char** arg)
{
		int i;
	// SET LRSTAR OPTIONS TO UNDEFINED ...
		for (i = 0; i < N_OPTIONS; i++)
		{
			optn[i] = -1; // undefined
		}

	// SET OPTIONS FROM COMMAND LINE ...
		if (!SET_OPTNS (na, arg, PGOption))
		{
			ShowOptions ();
			return 0;
		}

		int op = 0;
		optn[PG_LR]   = 0;
		optn[PG_LALR] = 1;
		optn[PG_CLR]  = 0;
		if (op > 1)
		{
			printf ("\nChoose only one of these: /clr, /lalr, /lr.\n\n");
			return 0;
		}
		if (optn[PG_LR] > 0)
		{
			optn[PG_CLR]  = 0;
			optn[PG_LALR] = 0;
			optn[PG_LR]   = 1;
			optn[PG_DEFAULTRED]  = 1;
			optn[PG_SHIFTREDUCE] = 1;
			optn[PG_BOOLMATRIX]  = 2;
		}
		else if (optn[PG_LALR] > 0)
		{
			optn[PG_CLR]  = 0;
			optn[PG_LALR] = 1;
			optn[PG_LR]   = 0;
			optn[PG_DEFAULTRED]  = 1;
			optn[PG_SHIFTREDUCE] = 1;
			optn[PG_BOOLMATRIX]  = 2;
		}
		else if (optn[PG_CLR] > 0)
		{
			optn[PG_CLR]  = 1;
			optn[PG_LALR] = 0;
			optn[PG_LR]   = 0;
			optn[PG_DEFAULTRED]  = 0;
			optn[PG_SHIFTREDUCE] = 0;
			optn[PG_OPTIMIZE]    = 0;
			optn[PG_BOOLMATRIX]  = 1;
		}

	// SET UNDEFINED OPTIONS TO DEFAULT VALUES ...
		i = 0;
		do
		{
			for (; *PGOption[i].name != 0; i++)
			{
				if (optn[PGOption[i].numb] == -1)
					 optn[PGOption[i].numb] = PGOption[i].defvalue;
			}
		}
		while (PGOption[i++].numb != 0);

		if (optn[PG_LALR] > 0)
		{
			optn[PG_CLR] = 0;
			optn[PG_LALR] = 1;
			optn[PG_LR] = 0;
			optn[PG_DEFAULTRED] = 1;
			optn[PG_SHIFTREDUCE] = 1;
			optn[PG_BOOLMATRIX]  = 2;
		}

		if (optn[PG_LOOKAHEADS] == 0)	optn[PG_LOOKAHEADS]  = 1;
		if (optn[PG_LOOKAHEADS]  > 1) optn[PG_NONDETER]    = 1;
		if (optn[PG_ASTCONST]   == 0) optn[PG_NODEACTIONS] = 0;

		optn[PG_TAB]         = 3;
		optn[PG_SYMBOLS]     = 0;
		optn[PG_BACKSLASH]   = 0;
		optn[PG_TRANSITIONS] = 1;

		option_warnings = optn[PG_WARNINGS];
		max_errors      = 100;

	// SET UNDEFINED OPTIONS TO ZERO ...
		for (i = 0; i < N_OPTIONS; i++)
		{
			if (optn[i] == -1) // If unlisted option
				optn[i] = 0;	 // Set to zero
		}
	// SET MEMORY OPTIONS TO DEFAULT VALUES ...
		for (i = 0; *MAOption[i].name != 0; i++)
		{
			optn[MAOption[i].numb] = MAOption[i].defvalue;
		}
		return 1;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::ShowOptions ()
{
		int i;
		printf ("|   OPTION  DEFAULT  DESCRIPTION\n");

		i = 0;
		do
		{
			printf("|\n");
			for (; *PGOption[i].name != 0; i++)
			{
				printf ("|   %-6s %5d     %s\n", PGOption[i].name, PGOption[i].defvalue, PGOption[i].desc);
			}
		}
		while (PGOption[i++].numb != 0);
		printf ("|_\n\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::DeleteLexFile ()
{
		char  lexfid[256];
      strcpy (lexfid, gdn);
      strcat (lexfid, gfn);
      strcat (lexfid, ".lex");
		if (chmod (lexfid, S_IWRITE) == 0) // File can be written ?
		{
			if (unlink (lexfid) != 0) // Not deleted?
			{
				prt_log ("Output file '%s' cannot be written!\n", lexfid);
				Quit ();
			}
      }
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::OutputLexFile ()
{
		char* p;
		char  lexfid[256];
      char  string[256];
      int   filedesc, first, i, k, n, ns, len;

      strcpy (lexfid, gdn);
      strcat (lexfid, gfn);
      strcat (lexfid, ".lex");

		filedesc = open (lexfid, O_CREAT | O_TRUNC | O_WRONLY, S_IREAD | S_IWRITE);
		if (filedesc < 0)
		{
	      if (++n_errors == 1) prt_log ("\n");
			prt_log ("Output file '%s' cannot be written!\n", lexfid);
         Quit ();
		}

		first = 0;
		int* seq;
		ALLOC (seq, N_terms);
		SORTNAMES (term_name, N_terms, seq);

		len = sprintf (string, "\n/* Lexical symbols found in %s%s.\n   This file was generated by %s %s.\n*/\n\n",
      gfn, gft, program, version);
		write (filedesc, string, len);

	/* <lexical> symbols */

		n = 0;
		for (i = 0; i < N_terms; i++)
		{
			if (seq[i] == 0) continue; // Skip <error> symbol.
			if (term_name[seq[i]][0] == '<')
			{
 				n++;
				write (filedesc, "   ", 3);
				k = (int)strlen (term_name[seq[i]]);
				write (filedesc, term_name[seq[i]], k);
				ns = (max_terml - k + 1);
				if (ns > 0) write (filedesc, spaces, ns);
				k = sprintf (string, "%5d", seq[i]);
				write (filedesc, string, k);
				write (filedesc, "\n", 1);
			}
		}
		if (n) first = 1;

	/* {semantic} symbols

		n = 0;
		for (i = 0; i < N_terms; i++)
		{
			if (seq[i] == 0) continue; // Skip <error> symbol.
			if (term_name[seq[i]][0] == '{')
			{
 				n++;
				if (first)
				{
					first = 0;
					write (filedesc, "\n", 1);
				}
				write (filedesc, "   ", 3);
				k = (int)strlen (term_name[seq[i]]);
				write (filedesc, term_name[seq[i]], k);
				ns = (max_terml - k + 1);
				if (ns > 0) write (filedesc, spaces, ns);
				k = sprintf (string, "%5d", seq[i]);
				write (filedesc, string, k);
				write (filedesc, "\n", 1);
			}
		}
		if (n) first = 1;
   */
	/* Keywords */

		n = 0;
		char quote = '\'';
		for (i = 0; i < N_terms; i++)
		{
			if (!(term_type[seq[i]] & CONSTANT))
			{
				if (itsakeyword (term_name[seq[i]]))
				{
					n++;
					if (first)
					{
						first = 0;
						write (filedesc, "\n", 1);
					}
					write (filedesc, "   ", 3);
					p   = term_name[seq[i]];
					len = (int)strlen (p);
					write (filedesc, p, len);
					ns = (max_terml - len + 1);
					if (ns > 0) write (filedesc, spaces, ns);
					len = sprintf (string, "%5d", seq[i]);
					write (filedesc, string, len);
					write (filedesc, "\n", 1);
				}
			}
		}
		if (n) first = 1;

	/* 'literal' symbols */

		for (i = 0; i < N_terms; i++)
		{
			if (term_name[seq[i]][0] == '{') continue;
			if (term_name[seq[i]][0] == '<') continue;
			if (itsakeyword (term_name[seq[i]])) continue;
			if (first)
			{
				first = 0;
				write (filedesc, "\n", 1);
			}
			write (filedesc, "   ", 3);
			p   = term_name[seq[i]];
			len = (int)strlen (p);
			write (filedesc, p, len);
			ns = (max_terml - len + 1);
			if (ns > 0) write (filedesc, spaces, ns);
			len = sprintf (string, "%5d", seq[i]);
			write (filedesc, string, len);
			write (filedesc, "\n", 1);
		}

		FREE (seq, N_terms);

		len = sprintf (string, "\n/* End of %s lexical symbols. */\n\n", gfn);
		write (filedesc, string, len);
		close (filedesc);

      chmod (lexfid, S_IREAD); // Make output file read-only.
}

///////////////////////////////////////////////////////////////////////////////

char* PG_Main::slash_inside (char* term_name)
{
		static char string[128];
		char *p = term_name;

	//	printf("%s\n", term_name);
		char  c = 0;
		int   i = 0;
		do
		{
		//	if (*p != '\\')
			{
				string[i++] = *p++;
				if (i > 127)
				{
					n_errors++;
					if (n_errors == 1) prt_log ("\n");
					prt_log ("In file '%s', literal is longer than 128 characters.\n\n", grmfid);
					Quit ();
				}
			}
		/*	else
			{
				p++; // skip over '\'
				if (*p == '\'')
				{
					if      (c ==     0) c = '\"';
					else if (c == '\'')
					{
						n_errors++;
						if (n_errors == 1) prt_log ("\n");
						prt_log ("In file '%s', literal contains both \' and \", cannot convert for use in lexical grammar.\n", grmfid);
						Quit ();
					}
				}
				else if (*p == '\"')
				{
					if (c == 0) c = '\'';
					else if (c == '\"')
					{
						n_errors++;
						if (n_errors == 1) prt_log ("\n");
						prt_log ("In file '%s', literal contains both \' and \", cannot convert for use in lexical grammar.\n\n", grmfid);
						Quit ();
					}
				}
				string[i++] = *p++;
			}	*/
		}
		while (*p != 0);
	/*	if (c != '\"')
		{
			string[0] = '\'';
		}
		else
		{
			string[0] = '\"';
			string[i-1] = '\"';
		}	*/
		string[i] = 0;
//	 	printf ("%s\n", string);
		return (string);
}

///////////////////////////////////////////////////////////////////////////////

char* PG_Main::slash_inside_keyword (char* term_name, char quote)
{
		static char string[128];
		int i = 0;
		char *p;
      p = term_name;
		do
		{
		//	if (*p != '\\')
			{
				string[i++] = *p++;
				if (i > 127)
				{
					n_errors++;
					if (n_errors == 1) prt_log ("\n");
					prt_log ("In file '%s', literal is longer than 128 characters.\n\n", grmfid);
					Quit ();
				}
			}
		/*	else
			{
				p++;
				string[i++] = *p++;
			}	*/
		}
		while (*p != 0);
		string[i] = 0;
//	 	printf ("%s\n", string);
		return (string);
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::PrintStats ()
{
      optncount[MAX_SYM]   = PG_Parser::n_symbols;
      optncount[MAX_PRO]   = N_prods;
      optncount[MAX_TAIL]  = N_tails;
      optncount[MAX_STA]   = org_states;
      optncount[MAX_FIN]   = n_finals;
      optncount[MAX_KER]   = n_kernels;
      optncount[MAX_NTT]   = n_nttran;
      optncount[MAX_TT]    = n_ttran;
      optncount[MAX_TTA]   = 0;
      optncount[MAX_LB]    = n_lookbacks;
      optncount[MAX_LA]    = n_lookah;
      optncount[MAX_INC]   = n_includes;
      optncount[MAX_CH]    = max_child_usage;
      optncount[MAX_ND]    = n_nditems;
		for (int i = 0; *MAOption[i].name != 0; i++)
		{
			prt_num (MAOption[i].desc, optncount[MAOption[i].numb], MAOption[i].name, optn[MAOption[i].numb]);
		}
	  	prt_logonly ("\n");
}

///////////////////////////////////////////////////////////////////////////////

void  PG_Main::Terminate ()
{
		char* es = "S";
		char* ws = "S";
		if (n_errors    == 0) es = "s";
		if (n_warnings  == 0) ws = "s";
		if (n_errors    == 1) es = "";
		if (n_warnings  == 1) ws = "";
		char* wstr = "warning";
		if (n_warnings > 0) wstr = "WARNING";
		char* estr = "error";
		if (n_errors > 0) estr = "ERROR";

      time2  = clock ();

      int clocks, min, sec, thou;
      clocks = time2 - time1;
      min    = clocks/CLOCKS_PER_SEC / 60;
      sec    = clocks/CLOCKS_PER_SEC - min*60;
      thou   = clocks*1000/CLOCKS_PER_SEC - min*60000 - sec*1000;
      int x  = memory_max/1024/1024;
      int y  = memory_max/1024 - 1024*x;

		prt_log ("%1d min %1d.%03d sec, %d.%03d MB, %d %s%s, %d %s%s.\n",
		min, sec, thou, x, y, n_warnings, wstr, ws, n_errors, estr, es);
		prt_logonly ("\n");

		close_con ();
	  	close_log ();
		close_sta ();
		close_warn();
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

