
/* Copyright 2018 Paul B Mann.  BSD License. */

      char* program = "DFA";
      char* version = "24.0.025";
      #include <cstdint>
      #if INTPTR_MAX == INT64_MAX
      char* bits = "64b";
		#else
      char* bits = "32b";
		#endif
      char* copywrt = "Copyright Paul B Mann";

		#ifdef WINDOWS
		#include "conio.h"
      #include <windows.h>
		#endif
      #define MAIN
		#include "CM_Global.h"
		#include "LG_Global.h"

      OPTION LGOption[]= // Lexer Generator Options
		{
			"crr",		"Conflict report for Reduce-Reduce",	LG_CONRR,		      1,
			"csr",		"Conflict report for Shift-Reduce",		LG_CONSR,		      1,
			"d",     	"Debug lexer activated",  					LG_DEBUG,            0,
			"g",     	"Grammar listing",  							LG_GRAMMAR,          0,
			"ko",			"Keywords only (no identifiers).",		LG_KEYWORDONLY,		0,
			"m",			"Minimize lexer-table size",				LG_MINIMIZE,			0,
			"st",   		"State machine for conflicts report",	LG_STATELIST,			0,
			"sto",  		"State machine optimized",					LG_STATELISTOPT,		0,
			"v",			"Verbose mode (0,1,2)",						LG_VERBOSE,				2,
			"w",			"Print warnings on screen",				LG_WARNINGS,			0,
			"",			"",												0,				         0
		};

      OPTION MAOption[]= // Memory Allocation Options
		{
			"sym",		"Symbols in the grammar",  				MAX_SYM,		   100000,
			"pro",		"Productions in the grammar",				MAX_PRO,		   100000,
			"tail",		"Tail symbols in the grammar",			MAX_TAIL,	   500000,
			"sta",		"States created",								MAX_STA,		   100000,
			"fin",		"Final state items",							MAX_FIN,		   100000,
			"ker",		"Kernel state items",						MAX_KER,		  1000000,
			"ntt",		"Nonterminal transitions",					MAX_NTT,		  1000000,
			"tt",			"Terminal transitions",						MAX_TT,		  1000000,
			"tta",		"Terminal transitions added",				MAX_TTA,		  1000000,
			"la",			"Lookaheads in LALR computation",		MAX_LA,		  1000000,
			"lb",			"Lookbacks in LALR computation",			MAX_LB,		  1000000,
			"inc",		"Includes in LALR computation",			MAX_INC,		  1000000,
			"ch",			"Child nodes in graph",						MAX_CH,		  1000000,
			"nd",			"Nondeterministic/conflict items",		MAX_ND,		  1000000,
							"", "",											0,			           0
		};

		void  ShowOptions ();
		void  InitOptions ();

///////////////////////////////////////////////////////////////////////////////

int   main (int na, char *arg[])
{
		int fd = open ("lrstar.txt", 0);
		if (fd >= 0)
		{
			char input[100];
         int nb = read (fd, input, 100);
			close (fd);
			unlink ("lrstar.txt");
			if (*input != '0') exit(1);
		}

		InitOptions ();
	   PRT_ARGS (na, arg, 0);
		if (na == 1) // No arguments after program name?
		{
			ShowOptions();
			Quit ();
		}

 		if (!SET_OPTNS (na, arg)) Quit ();
		if (get_fid (arg[1], gdn, gfn, gft))
		{
         mystrlwr (gft);
			if (*gft == 0) strcpy (gft, ".lgr"); // Default filetype.
			if (strcmp (gft, ".lgr") != 0)
         {
            printf ("Cannot use a file type of \"%s\", use \".lgr\" instead.\n", gft);
            Quit ();
         }
			strcpy (grmfid, gdn);
			strcat (grmfid, gfn);
			strcat (grmfid, gft);

         if (open_log (grmfid))
         {
            PRT_ARGS (na, arg, 1);
				char dn[256], fn[256], ft[256];
				if (!open_con  (grmfid)) return 0;
  				if (!open_grm  (grmfid)) return 0;
				if (!open_sta  (grmfid)) return 0;
				if (!open_warn (grmfid)) return 0;

				if (get_fid (arg[0], dn, fn, ft)    == 0)	Quit ();
				if (GetMaxValues (dn) == 0) Quit ();;

    			if (LG::Main ())
				{
					LG::GenerateLexerDefines();
					LG::PrintStats();
				}
         }
		}
		LG::Terminate ();
		close_log ();
		exit (n_errors);
}

///////////////////////////////////////////////////////////////////////////////

void  ShowOptions ()
{
		int i;
      char  programdesc[] =
			"|\n"
			"|   DFA LEXER GENERATOR\n"
			"|\n"
			"|   dfa <grammar> [<option>...]\n"
      ;
		printf ("%s|\n", programdesc);
		printf ("|   OPTION  DEFAULT  DESCRIPTION\n");
		for (i = 0; *LGOption[i].name != 0; i++)
		{
			printf ("|   %-6s  %5d    %s\n", LGOption[i].name, LGOption[i].defvalue, LGOption[i].desc);
		}
		printf ("|_\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  InitOptions ()
{
		int i;
		for (i = 0; i < N_OPTIONS; i++)
		{
			optn[i] = 0;
		}
		for (i = 0; * LGOption[i].name != 0; i++)
		{
			optn[LGOption[i].numb] = LGOption[i].defvalue;
		}
		for (i = 0; * MAOption[i].name != 0; i++)
		{
			optn[MAOption[i].numb] = MAOption[i].defvalue;
		}

	// Define invisible LG options ...
		optn [LG_TABLES]        = 1;
      optn [LG_BACKSLASH]    	= 0;
      optn [LG_TRANSITIONS] 	= 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
/*
void  wait (int na)
{
  		#ifdef WINDOWS
		double dsec;
		int time1, time2, min, sec, thou, limit;
		if (na == 1) return;
		if (!optn[LG_WAIT]) return;
		limit = 3; // Seconds.
		time1 = clock();
		printf("Press a key to lock this ...\n");
		do
		{
			time2 = clock();
			dsec = (double)(time2-time1)/CLOCKS_PER_SEC;
			sec  = dsec;
			if (_kbhit())
			{
				printf("Locked.\n");
Halt:			goto Halt;
			}
		}
		while (sec < limit);
		#endif
}
*/

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  Quit (int rc)
{
  		#ifdef WINDOWS
		#ifdef _DEBUG
      {
			printf("Waiting for a key to be pressed ...\n");
			while (!_kbhit());
      }
		#endif
		#endif
		exit(0);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  InternalError (int n)
{
		n_errors++;
		if (n_errors == 1) printf ("\n");
      printf ("INTERNAL ERROR %d\n\n", n);
      Quit();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  MemCrash (char* msg)
{
      prt_log ("\n%s\n", msg);
      Quit ();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  MemCrash (char* value, int n)
{
      n_errors++;
		if (n_errors == 1) prt_log ("\n");
      prt_log ("%s(%04d) : %s exceeds the limit of %d.\n", exefid, 1, value, n);
		prt_log ("%s(%04d) : %s\n", exefid, 1, "Please increase the appropriate maximum value in this file:");
  		prt_log ("%s(%04d) : %s\n", exefid, 1, "<-- double click here.");
      Quit ();
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////
