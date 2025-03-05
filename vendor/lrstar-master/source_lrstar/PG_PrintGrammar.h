
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "PG_CheckGrammar.h"

		class PG_PrintGrammar : public PG_CheckGrammar
		{
			public:
			static void  PrintGrammar();
			static void  PrintHtml();

			private:
			static int   p_head    (char* before, int s, char *after);
			static int   p_tail    (char* before, int s, char *after);
			static void  print_struc ();

			static int   ph_nont   (char* before, int s, char *after);
			static int   ph_head   (char* before, int s, char *after);
			static int   ph_tail   (char* before, int s, char *after);
			static int   ph_sym    (int nont_on, int tail_on, char* before, int s, char *after);
			static void  ph_spaces (int ns);
			static void  ph_arg    (int i);
			static int   ph_gensym (int h, char *sp);

		};
