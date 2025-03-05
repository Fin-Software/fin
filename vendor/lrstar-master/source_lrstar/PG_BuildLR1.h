
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

  		#include "PG_BuildLR0.h"

      typedef struct LRKERNEL
      {
         ushort item; // Item.
         ushort LA;   // Lookahead.
      }
      LRKERNEL;       // LR(1) Kernel.

		class PG_BuildLR1 : public PG_BuildLR0
		{
			public:
			static int   BuildLR1 ();
			static int	 extra_states;

			private:
			static void  EXPAND (int state);
			static void  MAKE_STATE (int);
			static void  DO_CLOSURE (int state);
			static void  ADD_ITEM (int i, int la);
			static void  MAKE_KERNEL (int s);
			static int   MAKE_KERNEL (int state, int symb);
			static int   TRANSITION (int symb);
			static void  PRT_CLO (int state);
			static void  PRT_STA(int state);
			static void  PRT_LRSTA (int state);
			static int 	 LR0_SORT (LRKERNEL* lrkernel, int fk, int lk);
			static void	 LR1_SORT (LRKERNEL* lrkernel, int fk, int lk);
			static int   COMPATIBLE (int, int);
			static int   ProblemWithKernels (int, int);
			static int   EQUIVALENT (int, int);
			static void  MAKE_LR0_KERNELS ();
			static void  MAKE_LR0_TRANSITIONS ();
			static void  MODIFY_TRANSITIONS ();
			static void  P_HEAD (int s);
			static void  P_SYMB (int s);
			static void  PRT_TRAN (int s);
			static void  prt_item (char* before, int i, int la);
			static void  prt_prod (int p, int dot, char* before, char* after);
			static int   prt_sym (int s, char *after);
			static int   prt_head (int s, char *after);
		};

