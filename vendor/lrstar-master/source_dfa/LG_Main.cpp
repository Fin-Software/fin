
/* Copyright 2018 Paul B Mann.  BSD License. */

      #include "CM_Global.h"
      #include "LG_Global.h"

///////////////////////////////////////////////////////////////////////////////

int   LG::Main () /* Display program information. */
{
      int rc;
      char *ch;
		if (!Start ()) Quit();
      if (GetFile (".lex", "")) // Try .lex file first.
      {
         already_readlex = 0;
         lex_input_start = input_start;
         lex_input_end   = input_end;
         lex_line_ptr    = line_ptr;
  		   if (!LG_ParseActions::init()) Quit();
         if (!ParseInit()) Quit();
         rc = Parse();
         if (rc < 0) // Not finished parsing?
         {
            if (!GetFile (".lgr", "File not found")) Quit();
            already_readlex = 1;
            rc = Parse();
         }
      }
      else
      {
         already_readlex = 0;
         if (!GetFile (".lgr", "File not found")) Quit();
  		   if (!LG_ParseActions::init()) Quit();
         if (!ParseInit()) Quit();
         rc = Parse();
      }
      if (rc <= 0) Quit();
      if (!LG_ParseActions::term ()) Quit();
	   if (!CheckGrammar()) Quit();
      if (!BuildStates()) Quit();
      rc  = AddExtra();
      rc += ComputeLA();
      PrintStates (1);
      if (rc != 2) Quit();
      if (!OptimizeStates()) Quit();
      if (c_states == 1) ch = "";
      else               ch = "s";
      if (optn[LG_VERBOSE])
           prt_log     ("Conflicts%7d state%s, %d shift-reduce, %d reduce-reduce.\n", c_states, ch, sr_con, rr_con);
      else prt_logonly ("Conflicts%7d state%s, %d shift-reduce, %d reduce-reduce.\n", c_states, ch, sr_con, rr_con);
      PrintStates (2);
      CreateTables();
      return 1;
}

int   LG::Start () // Display program information.
{
      int i, ne;

      time1 = clock();
		if (!CheckOptions()) return 0;

		memory_usage  		 =  0;
		memory_max    		 =  0;
      ne            		 =  0;
      n_errors      		 =  0;
		max_child_usage    =  0;
      exefid[0]          =  0;
		illegal_char_state = -1;

   	for (i = 0; i < 256; i++) spaces [i] = ' ';

		memory_usage  = 0;
		memory_max    = 0;
      ne            = 0;
      n_warnings    = 0;
      n_errors      = 0;
		return 1;
}

int   LG::GetFile (char* file_type, char* Msg)
{
		strcpy (gft, file_type);
		strcpy (grmfid, gdn);
		strcat (grmfid, gfn);
      strcpy (gft, file_type);
		strcat (grmfid, gft);
   	if (!inputi (Msg)) return 0;
	// prt_log ("Reading   %s%s ...\n", gfn, file_type);
      return 1;
}

int   LG::FreeFile ()
{
		inputt ();
      return 1;
}

///////////////////////////////////////////////////////////////////////////////

int	LG::CheckOptions ()
{
		int n_outputs = 0;
		if (optn[LG_TABL_SMALL])	n_outputs++;
		if (optn[LG_TABL_MEDIUM])	n_outputs++;
		if (optn[LG_TABL_LARGE])	n_outputs++;

		if      (n_outputs == 0) optn[LG_TABL_MEDIUM] = 1;
		else if (n_outputs > 1)
		{
			printf ("More than one table size spedified, choosing 'medium'.\n\n");
			optn[LG_TABL_SMALL]  = 0;
			optn[LG_TABL_MEDIUM] = 1;
			optn[LG_TABL_LARGE]  = 0;
		}

		if (optn[LG_STATELIST] && optn[LG_STATELISTOPT])
		{
         n_errors++;
         printf ("State machine option should be 'st' or 'sto', but not both.\n\n");
		}

		if (optn[LG_NUMBCHAR] == 0)
		{
			optn[LG_NUMBCHAR] = 256; // If undefined.
		}
		max_char_set = optn[LG_NUMBCHAR];

      if (optn[LG_KEYWORDONLY]  == 0) optn[LG_KEYWORDIDENT] = 1;
      if (optn[LG_KEYWORDONLY]  == 1) optn[LG_KEYWORDIDENT] = 0;
      if (optn[LG_REMOVEDUP]    == 0) optn[LG_REMOVEDUP]    = 1;

		max_errors      = 100;
		option_grammar  = optn[LG_GRAMMAR];
		option_warnings = optn[LG_WARNINGS];

		if (n_errors > 0) return 0;
      return (1);
}

void  LG::PrintStats ()
{
		if (N_states > org_states) org_states = N_states;
		if (n_prods > max_n_prods) max_n_prods = n_prods;  // brute force fix.
		else                       max_n_prods++;				// brute force fix again.
		if (n_prods < 0) n_prods = 0;                      // In case of early syntax error.

      optncount[MAX_SYM]  = n_symbs;
      optncount[MAX_PRO]  = n_prods;
      optncount[MAX_TAIL] = n_tails;
      optncount[MAX_STA]  = org_states;
      optncount[MAX_FIN]  = n_finals;
      optncount[MAX_KER]  = n_kernels;
      optncount[MAX_NTT]  = n_nonttran;
      optncount[MAX_TT]   = n_termtran;
      optncount[MAX_TTA]  = n_ttas;
      optncount[MAX_LB]   = n_lookbacks;
      optncount[MAX_LA]   = n_lookah;
      optncount[MAX_INC]  = n_includes;
      optncount[MAX_CH]   = max_child_usage;
      optncount[MAX_ND]   = 0;
		for (int i = 0; *MAOption[i].name != 0; i++)
		{
			prt_num (MAOption[i].desc, optncount[MAOption[i].numb], MAOption[i].name, optn[MAOption[i].numb]);
		}
	  	prt_logonly ("\n");
}

///////////////////////////////////////////////////////////////////////////////

void  LG::Terminate ()
{
		char* es  = "s";
		char* ws  = "s";

		if (n_errors    == 1) es  = "";
		if (n_warnings  == 1) ws  = "";

      time2 = clock ();

      int clocks, min, sec, thou;
      clocks = time2 - time1;
      min    = clocks/CLOCKS_PER_SEC / 60;
      sec    = clocks/CLOCKS_PER_SEC - min*60;
      thou   = clocks*1000/CLOCKS_PER_SEC - min*60000 - sec*1000;
      int x = memory_max/1024/1024;
      int y = memory_max/1024 - 1024*x;

		prt_log ("%1d min %1d.%03d sec, %d.%03d MB, %d warning%s, %d error%s.\n",
		min, sec, thou, x, y, n_warnings, ws, n_errors, es);
		prt_logonly ("\n");

		close_con ();
		close_grm ();
	  	close_log ();
		close_sta ();
		close_warn();
}

/*--- End of Main Program. ------------------------------------------------- */

