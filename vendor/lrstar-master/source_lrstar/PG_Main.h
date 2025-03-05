
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_CreateTables.h"
		#include "PG_PrintGrammar.h"
		#include "PG_PrintStates.h"

   	class PG_Main : public PGCreateTables, public PG_PrintStates, public PG_PrintGrammar
		{
			public:
			static int    Main (int na, char** arg);
			static void   Terminate ();
         static void   prt_prod (FILE* tables, int p, char* before, char* after);
			static void   nd_optimize();

			private:
			static void   PrintStats ();
			static int    SetOptions   (int na, char** arg);
			static void   ShowOptions  ();
			static int    Start        (int na, char** arg );
			static char*  slash_inside (char* term_name);
			static char*  make_term    (char* s);
			static char*  slash_inside_keyword  (char* term_name, char quote);
			static void   GenerateParserTables  ();
			static void   GenerateOtherFiles    ();
			static void   DeleteLexFile ();
			static void   OutputLexFile ();
		};

