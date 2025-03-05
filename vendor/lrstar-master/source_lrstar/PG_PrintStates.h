
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_ComputeLA.h"

		class PG_PrintStates : public PG_ComputeLA
		{
			public:
			static void  PrintStates ();

			private:
         static int   C_max_symbl (int s);
			static void  PRT_STA (int s);
			static void  P_HEAD  (int s);
			static void  P_SYMBOL (int s);
			static void  P_SYMBOL (int s, char* prefix);
			static int   p_head (int s, char *sp);
			static int   p_sym (int s, char* sp);
			static int   p_sym60 (int s, char* sp);
			static void  p_prod (int p, int dot, char *before, char* after);
		};

