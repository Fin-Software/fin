
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_CheckGrammar.h"

		class PG_BuildLR0 : public PG_CheckGrammar
		{
			public:
		// Variables:
	      static int    N_states;
			static int*   ntt_item;
			static int*   accessor;
			static char** FIRST;
			static char** FOLLOW;
			static int*   f_kernel;
			static int*   f_final;
			static int*   final;
			static int*   kernel;
			static ITEM*  item;
			static int*   f_item;
			static int    n_ttran;
			static int    n_nttran;
			static int*   ntt_origin;
			static int    n_kernels;
			static int    n_finals;
			static int    org_states;
			static int    n_items;
			static int*   ntt_start;
			static int*   ntt_symb;
			static int*   ntt_action;
			static int*   tt_start;
			static int*   tt_action;
			static int*   tt_symb;
			static int*   f_camefrom;
			static int*   camefrom;

		// Functions:
			static int    BuildLR0 ();
			static void   C_ITEMS ();
			static void   MTSL ();

			private:
			static void   EXPAND (int state);
			static void   ADD_ITEM (int, int);
			static void   MAKE_STATE (int);
			static void   MODIFY (int);
			static void   DO_CLOSURE (int);
			static void   MAKE_KERNEL (int);
			static int    TRANSIT (int, int);
		};

