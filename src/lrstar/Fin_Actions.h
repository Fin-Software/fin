
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#pragma once

#include "Fin_Parser.h"

#ifdef ACTIONS

class ACTIONS: public PARSER {
  public:
    static void init_actions();
    static void term_actions();
};

#endif
#ifdef TERM_ACTIONS

class TERM_ACTIONS: public ACTIONS {
  public:
    static int error(int& t);
    static int lookup(int& t);
};

#endif
#ifdef NODE_ACTIONS

class NODE_ACTIONS: public ACTIONS {
  public:
};

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////
