
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#include "Fin_Actions.h"
#include "../../code/main.h"

///////////////////////////////////////////////////////////////////////////////

#ifdef ACTIONS

void ACTIONS::init_actions() { /* Initialization code goes here */ }

void ACTIONS::term_actions() { /* Termination code goes here */ }

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef TERM_ACTIONS

int TERM_ACTIONS::error(int& t) {
    if (token.end == token.start) // Illegal character?
    {
        token.end++;
    }
    return 0;
}

int TERM_ACTIONS::lookup(int& t) // Lookup in symbol table.
{
    int sti;
    #ifdef ND_PARSING
    if (lookahead.start != 0) // In lookahead mode?
    {
        sti = add_symbol(t, lookahead.start, lookahead.end);
    } else // Regular mode of parsing.
    #endif
    {
        sti = add_symbol(t, token.start, token.end);
    }
    #ifdef SEMANTICS
    t = symbol[sti].term; // Redefine terminal number?
    #endif
    return sti;
}

#endif

///////////////////////////////////////////////////////////////////////////////

#ifdef NODE_ACTIONS

#endif

//                                                                           //
///////////////////////////////////////////////////////////////////////////////
