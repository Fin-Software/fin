
/* Copyright 2018 Paul B Mann.  BSD License. */

		#pragma once

		#include "PG_ComputeLA.h"

		class PG_OptimizeStates : public PG_ComputeLA
		{
			public:
			static int  OptimizeStates ();
			static int  Accept_state;
			static int  ntt_states;
			static int  tt_states;

			private:
			static int  FIND_ACCEPT_STATE ();
			static void MAKE_SHIFT_REDUCE_ACTIONS ();
			static void ELIMINATE_CHAIN_REDUCTIONS ();
		};
