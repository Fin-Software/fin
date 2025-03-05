
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
      #include "PG_Actions.h"
		#include "PG_Parser.h"

#ifdef NODE_ACTIONS

		#define EBNF_TAIL   1
		#define EBNF_REPEAT 2
		#define EBNF_GROUP  3
		static int priority = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::start_ (void* v)
{
		if (pass == FIRST_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:	 break;
				case BOTTOM_UP: break;
			}
      }
		else if (pass == SECOND_PASS)
		{
			switch (direction)
			{
				case TOP_DOWN:
					get_last_nonterminal();
					number_the_terminals();
					check_for_quotes();
					break;
				case BOTTOM_UP:
					connect_ebnf_tree();
					break;
			}
		}
		else if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
		         alloc_struc();
               N_args     = 0;
               N_prods    = 0;
               N_tails    = 0;
					N_reverses = 0;
               precedence = 0;
					n_values   = 0;
					N_semantics = 0;
					terminal_mode = 1;
               break;
			   case BOTTOM_UP:
               F_prod[N_heads] = N_prods;
               F_tail[N_prods] = N_tails;
               fill_struc();
               break;
		   }
      }
		return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::get_last_nonterminal()
{
      Node* np;
      np = root;        // start
      np = np->child;   // declarations
      np = np->next;    // operator precedence
      np = np->next;    // rules
      np = np->child;   // nonterminal
      while (np->next != NULL)
      {
         np = np->next;
      }
      lastnonterm = np;
		lastebnf = ebnf;  // EBNF root.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::connect_ebnf_tree()
{
		lastnonterm->next = ebnf->next;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::goaldef_ (void* v)
{
		Node* np = (Node*)v;
      headdef_(np);
      return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::headdef_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               if (symbol[np->sti].type & GENERATED) generated = 1;
               head_line [symbol[np->sti].numb] = np->line;
               F_prod [symbol[np->sti].numb] = N_prods;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::priority_ (void* v)
{
		Node* np = (Node*)v;
		priority = 1;
		prod_(np);
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::prod_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					Node* ptr = np->child->child;	 // prod_/tails_/tail_
					while (ptr != NULL)
					{
						N_tails++;
						ptr = ptr->next;
					}
					break;
		   }
      }
		else if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               F_tail  [N_prods] = N_tails;
               Reverse [N_prods] = 0;
					Priority[N_prods] = priority;
					priority = 0;
               break;
			   case BOTTOM_UP:
               prod_line[N_prods++] = np->line;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::tail_list_(void* v)
{
		Node* np = (Node*)v;
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::repeat_one_or_more_(void* v)
{
		char oper;
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				np->oper	|= ONE_OR_MORE;
		      if (np->child->id == N_tail_)
				{
					np->oper |= np->child->oper;	// Upgrade oper.
					np->child->oper = 0;				// Reset child.
				}
				else if (np->child->id == N_repeat_one_or_more_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_more_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_one_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				break;
			}
		}
		else if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				oper      = oper_char (np);
				np->sti   = make_ebnf (np,EBNF_REPEAT,oper);
				np->id    = N_tail_;
				np->child = NULL;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::repeat_zero_or_more_(void* v)
{
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				np->oper = ZERO_OR_MORE;
		      if (np->child->id == N_tail_)
				{
					np->child->oper = 0;				// Reset child.
				}
				else if (np->child->id == N_optgroup_)
				{
					np->child->id = N_group_;		// Reset child.
					np->child->oper = 0;				// Reset child.
				}
				else if (np->child->id == N_repeat_one_or_more_)
				{
					np->sti = np->child->sti;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_more_)
				{
					np->sti = np->child->sti;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_one_)
				{
					np->sti = np->child->sti;
					np->child = np->child->child;
				}
				break;
			}
		}
		else if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				np->sti   = make_ebnf (np,EBNF_REPEAT,'*');
				np->id    = N_tail_;
				np->child = NULL;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::repeat_zero_or_one_(void* v)
{
		char oper;
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				np->oper |= ZERO_OR_ONE;
		      if (np->child->id == N_tail_)
				{
					np->oper |= np->child->oper;	// Upgrade this.
					np->child->oper = 0;				// Reset child.
				}
				else if (np->child->id == N_repeat_one_or_more_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_more_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				else if (np->child->id == N_repeat_zero_or_one_)
				{
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
				break;
			}
		}
		else if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				oper      = oper_char (np);
				np->sti   = make_ebnf (np,EBNF_REPEAT,oper);
				np->id    = N_tail_;
				np->child = NULL;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::group_(void* v)
{
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				if (np->child->id != N_section_) // section_ removed ?
				{
					np->id = np->child->id;
					np->sti = np->child->sti;
					np->oper = np->child->oper;
					np->child = np->child->child;
				}
			}
		}
		else if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				np->sti   = make_ebnf (np,EBNF_GROUP,' ');
				np->id    = N_tail_;
				np->child = NULL;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::optgroup_(void* v)
{
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				np->oper |= ZERO_OR_ONE;			// Mark oper.
				if (np->child->id != N_section_) // section_ removed ?
				{
					np->id = np->child->id;
					np->sti = np->child->sti;
					np->oper |= np->child->oper;
					np->child = np->child->child;
				}
			}
		}
		else if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				np->sti   = make_ebnf (np,EBNF_GROUP,'?');
				np->id    = N_tail_;
				np->child = NULL;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::sepgroup_(void* v)
{
		Node* np = (Node*)v;
		group_(np);
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::section_(void* v)
{
		Node* np = (Node*)v;
		if (pass == FIRST_PASS)
		{
			switch (direction)
			{
				case BOTTOM_UP:
				if (np->prev == NULL && np->next == NULL)	// No other section_s?
				{
					if (np->child->next == NULL) // No other tail_s?
					{
						np->id = np->child->id;
						np->sti = np->child->sti;
						np->oper = np->child->oper;	// repeat_one_or_nore_ ?
						np->child = np->child->child;	// tail_ ?
					}
				}
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::bypass_(void* v)
{
		Node* np = (Node*)v;
		if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				char *h = "<error>*";
				char *p = h + 8;
				int head = add_symbol (h, p, NONTERMINAL|TAIL, 0);
				if (symbol[head].numb <= 0)
				{
					symbol[head].numb = N_heads++;
					symbol[head].type = NONTERMINAL|GENERATED|TAIL;
					make_head (head);
					make_prod (0);
					make_prod (0);
					make_tail (head);
					make_tail (1); // <error>
				}
				symbol[np->sti].name = h;
				symbol[np->sti].numb = symbol[head].numb;
				symbol[np->sti].type = NONTERMINAL|GENERATED|TAIL;
				symbol[np->sti].length = 8;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::tail_ (void* v)
{
		char oper;
		Node* np = (Node*)v;
		if (pass == SECOND_PASS)
      {
         switch (direction)
		   {
			   case BOTTOM_UP:
				if (np->oper & 15) // Any operation?
				{
					oper = oper_char (np);
					np->sti = make_ebnf (np,EBNF_TAIL,oper);
				}
		   }
      }
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
            if (symbol[np->sti].type & NONTERMINAL)
                 Tail[N_tails] = -symbol[np->sti].numb;
            else Tail[N_tails] =  symbol[np->sti].numb;
            N_tails++;
            break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::tail_eof_ (void* v)
{
		Node* np = (Node*)v;
		return tail_(np);
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::sep_(void* v)
{
		Node* np = (Node*)v;
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::make_ebnf (Node* np, int type, char oper)
{
		char *h, *p;
		int  head, leng, sep;
		leng = get_length (np, type);
		h = p = ALLOC (h, leng + 5);	// ( ... ) ' ' '|' ' '
		p = make_nonterminal (np, type, p, sep, oper);
		head = add_symbol (h, p, NONTERMINAL|TAIL, 0);
		if (symbol[head].numb < 0)			// New symbol?
		{
			make_productions (np, type, head, sep, oper);
		}
		return head;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::get_length (Node* np, int type)
{
		int leng;
		Node *s, *t;
		if (type == EBNF_REPEAT)
		{
			if (np->child != NULL) np = np->child;
			if      (np->id == N_tail_    ) leng = get_length (np, EBNF_TAIL);
			else if (np->id == N_group_   ) leng = get_length (np, EBNF_GROUP);
			else if (np->id == N_optgroup_) leng = get_length (np, EBNF_GROUP);
			if (np->next != NULL)
			{
				if (np->next->id == N_sep_)
					leng += get_length (np->next, EBNF_TAIL);
				if (np->next->id == N_sepgroup_)
					leng += get_length (np->next, EBNF_GROUP);
			}
			return leng;
		}
		else if (type == EBNF_TAIL)
		{
			leng = symbol[np->sti].length;
		}
		else if (type == EBNF_GROUP)
		{
			s = np->child;		// first section_
			leng = 0;
			do
			{
				t = s->child;	// first tail_
				do
				{
					leng += symbol[t->sti].length + 1; // ' '
					t = t->next;
				}
				while (t != NULL);
				leng += 2;  // '| '
				s = s->next;
			}
			while (s != NULL);
			leng -= 3;
		}
		else printf ("\nINTERNAL ERROR\n\n");
		return leng;
}

///////////////////////////////////////////////////////////////////////////////

char* PG_NodeActions::make_nonterminal (Node* np, int type, char* p, int& sep, char oper)
{
		int leng;
		Node *s, *t;
		if (type == EBNF_REPEAT)
		{
			np = np->child;
			if      (np->id == N_tail_    ) p = make_nonterminal (np, EBNF_TAIL,  p, sep, ' ');
			else if (np->id == N_group_   ) p = make_nonterminal (np, EBNF_GROUP, p, sep, ' ');
			else if (np->id == N_optgroup_) p = make_nonterminal (np, EBNF_GROUP, p, sep, ' ');
			if (np->next != NULL)
			{
				if (np->next->id == N_sep_)
				{
					*p++ = '/';
					p = make_nonterminal (np->next, EBNF_TAIL, p, sep, oper);
					sep = np->next->sti;
				}
				else if (np->next->id == N_sepgroup_)
				{
					*p++ = '/';
					p = make_nonterminal (np->next, EBNF_GROUP, p, sep, oper);
					sep = np->next->sti;
				}
			}
			else
			{
				*p++ = oper;
				*p = 0;
			}
			return p;
		}
		if (type == EBNF_TAIL)
		{
			leng = symbol[np->sti].length;
			memcpy (p, symbol[np->sti].name, leng);
			p += leng;
		}
		else // group_
		{
		//	SORT_GROUP (np->child);
		   *p++ = '(';
			s = np->child; // first section_
			do
			{
				t = s->child;	// first tail_
				do
				{
					leng = symbol[t->sti].length;
					memcpy (p, symbol[t->sti].name, leng);
					p += leng;
					*p++ = ' ';
					t = t->next;
				}
				while (t != NULL);
				*p++ = '|';
				*p++ = ' ';
				s = s->next;
			}
			while (s != NULL);
			p -= 3;
			*p++ = ')';
		}
		sep = 0;
		if (oper != ' ') *p++ = oper;
		*p = 0;
		return p;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::SORT_GROUP (Node* v)
{

}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::make_productions (Node* np, int type, int head, int sep, char oper)
{
		Node *s, *t;
		symbol[head].numb = N_heads++;
		symbol[head].type = NONTERMINAL|GENERATED|TAIL;
		make_head (head);
		if (oper == '*' || oper == '?')
		{
			make_prod (ARROW); // Null production.
		}
		if (type == EBNF_REPEAT)
		{
			np = np->child;
			if (np->id == N_tail_    ) goto Tail;
			if (np->id == N_group_   ) goto Group;
			if (np->id == N_optgroup_) goto Group;
		}
		else if (type == EBNF_TAIL)
		{
Tail: 	if (oper == '?' || oper == '+' || sep != 0)
			{
				make_prod (ARROW);
				make_tail (np->sti);
			}
			if (oper == '*' || oper == '+')
			{
				make_prod (ARROW);
				make_tail (head);
				make_tail (sep);
				make_tail (np->sti);
			}
		}
		else // group_ situation
		{
Group:	if (oper == '?' || oper == '+' || oper == ' ' || sep != 0)
			{
				s = np->child; // first section_
				do
				{
					make_prod (ARROW);
					t = s->child; // first tail_
					do
					{
						make_tail (t->sti);
						t = t->next;
					}
					while (t != NULL);
					s = s->next;
				}
				while (s != NULL);
			}
			if (oper == '*' || oper == '+')
			{
				s = np->child; // first section_
				do
				{
					make_prod (ARROW);
					make_tail (head);
					make_tail (sep);
					t = s->child; // first tail_
					do
					{
						make_tail(t->sti); // tail_
						t = t->next;
					}
					while (t != NULL);
					s = s->next;
				}
				while (s != NULL);
			}
		}
		return head;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::make_head (int sti)
{
      Node* np;
   // printf ("%s ", symname(sti));
		np = lastebnf;
		np = np->next = (Node*)ALLOC(node, 1);
      np->id     = N_headdef_;
      np->numb   = n_nodes++;
      np->prod   = -1;
      np->sti    = sti;
		np->oper   = 0;
      np->line   = 0;
      np->start  = NULL;
      np->end    = NULL;
      np->next   = NULL;
      np->prev   = NULL;
      np->child  = NULL;
      np->parent = NULL;
		lastebnf   = np;
      lastprod   = NULL;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::make_prod (int terminal)
{
		/* headdef_
			+ prod_
			  + tail_list_
					+ tail_
					+ tail_
			  + rule_actions_
		*/
	   Node* np;
      if (lastprod == NULL) // First time for current nonterminal.
      {
         np = lastebnf;
         np = np->child = (Node*)ALLOC(node,1);
         np->parent = lastebnf;
         np->prev   = NULL;
      }
      else // New production linkage!
      {
         np = lastprod;
         np = np->next = (Node*)ALLOC(node,1);
         np->parent = NULL;
         np->prev   = lastprod;
      }
      np->id     = N_prod_;
      np->numb   = n_nodes++;
      np->prod   = -1;
      np->sti    = 0;
		np->oper   = 0;
      np->line   = 0;
      np->start  = NULL;
      np->end    = NULL;
      np->next   = NULL;
      lastprod   = np;

      np = np->child = (Node*)ALLOC(node,1);
      np->id     = N_tail_list_;
      np->numb   = n_nodes++;
      np->parent = lastprod;
      np->prev   = NULL;
      np->prod   = -1;
      np->sti    = 0;
		np->oper   = 0;
      np->line   = 0;
      np->next   = NULL;
      np->start  = NULL;
      np->end    = NULL;
      np->child  = NULL;
      lastsection = np;
      lasttail   = NULL;
		N_prods++;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::make_tail (int sti)
{
		/* headdef_
			+ prod_
			  + tails_
				 + tail_
				 + tail_
			  + rule_actions_
		*/
		Node* np;
		if (sti == 0) return;
		symbol[sti].type |= TAIL;
      if (lasttail == NULL)
      {
         np = lastsection;
         np = np->child = (Node*)ALLOC(node,1);
         np->parent = lastsection;
         np->prev   = NULL;
      }
      else
      {
         np = lasttail;
         np = np->next = (Node*)ALLOC(node,1);
         np->parent = NULL;
         np->prev   = lasttail;
      }
      np->id     = N_tail_;
      np->numb   = n_nodes++;
      np->prod   = -1;
      np->sti    = sti;
		np->oper   = 0;
      np->line   = 0;
      np->next   = NULL;
      np->start  = NULL;
      np->end    = NULL;
      np->child  = NULL;
      lasttail   = np;
		N_tails++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

      int   	PG_NodeActions::arrow_;
      char* 	PG_NodeActions::oper;
      int   	PG_NodeActions::assoc;
      int   	PG_NodeActions::constant;
      int   	PG_NodeActions::generated;
      int   	PG_NodeActions::precedence;
      int   	PG_NodeActions::n_values;
      int   	PG_NodeActions::terminal_mode;
      int   	PG_NodeActions::separator;
	   char**   PG_NodeActions::term_start;
		char**   PG_NodeActions::term_end;
		int*     PG_NodeActions::term_type;
		int*     PG_NodeActions::term_const;
		int*     PG_NodeActions::const_term;
		char**   PG_NodeActions::const_name;
		char**   PG_NodeActions::Int_start;
      int*     PG_NodeActions::Tail;
		int*     PG_NodeActions::F_tail;
		int*     PG_NodeActions::head_sym;
		int*     PG_NodeActions::prod_len;
		char**   PG_NodeActions::head_name;
		int*     PG_NodeActions::head_type;
		char**   PG_NodeActions::term_name;
		int*     PG_NodeActions::term_line;
		int*     PG_NodeActions::head_line;
		int*     PG_NodeActions::prod_line;
		int*     PG_NodeActions::nullable;
		int      PG_NodeActions::n_nulls;
		int      PG_NodeActions::stmt_beg;
		int      PG_NodeActions::stmt_end;

      Node* 	PG_NodeActions::lastnonterm;
		Node*    PG_NodeActions::lastebnf;
		Node* 	PG_NodeActions::lastprod;
      Node* 	PG_NodeActions::lastsection;
      Node* 	PG_NodeActions::lasttail;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    Assign sequence numbers to the terminal tail symbols (not declared).
/*
		Note that the classification changes here.  TERMINAL meant declared.
		But now we have to mark all terminals as TERMINAL and so we mark the
      declared as DECLARED and leave the undeclared as just TERMINAL.
*/
void  PG_NodeActions::number_the_terminals()
{
      int i;
		int nu = 0;
      for (i = 0; i < n_symbols; i++)
      {
         if (symbol[i].type & TAIL)										// In the grammar?
         {
            if (!(symbol[i].type & NONTERMINAL))					// Not a nonterminal?
            {
               if (!(symbol[i].type & TERMINAL))					// Not declared as terminal?
               {
	               if (!(symbol[i].type & CONSTANT))				// Not declared as constant?
		            {
							symbol[i].type |= TERMINAL;					// Make it a terminal.
							symbol[i].type |= UNDECLARED;					// Make it undeclared.
							symbol[i].numb  = N_terms++;
							symbol[i].value = -1;
							if (optn[PG_KEYWORDUNDECL] && itsakeyword (symbol[i].name))
							{
								nu++;
								prt_warning ("Keyword %s was in a grammar rule but not declared",
									symbol[i].name, 0, symbol[i].line);
							}
						}
               }
            }
         }
      }
      for (i = 0; i < n_symbols; i++)
      {
         if (symbol[i].type & ARGUMENT)								// In the arguments?
         {
            if (!(symbol[i].type & NONTERMINAL))					// Not a nonterminal?
            {
               if (!(symbol[i].type & CONSTANT))					// Not constant?
               {
                  if (!(symbol[i].type & STRING))					// Not string?
                  {
                     if (!(symbol[i].type & INTEGER))				// Not integer?
                     {
                        if (!(symbol[i].type & TERMINAL))		// Not declared?
                        {
									symbol[i].type |= UNDECLARED;
									symbol[i].type |= TERMINAL;
									symbol[i].numb = N_terms++;
									symbol[i].value = -1;
									if (optn[PG_KEYWORDUNDECL] && itsakeyword (symbol[i].name))
									{
										nu++;
										prt_warning ("Keyword %s was as argument but not declared",
											symbol[i].name, 0, symbol[i].line);
									}
                        }
                     }
                  }
               }
            }
         }
      }
      ALLOC (term_name,  N_terms);
      ALLOC (term_start, N_terms);
      ALLOC (term_end,   N_terms);
      ALLOC (term_type,  N_terms);
      ALLOC (term_line,  N_terms);
		ALLOC (term_const, N_terms); // Defined constant associated with this term.
		ALLOC (const_term, N_terms); // Defined term     associated with this constant.
		ALLOC (const_name, N_terms);

		for (i = 0; i < N_terms; i++) term_const[i] = -1;
		for (i = 0; i < N_terms; i++) const_term[i] = -1;
		for (i = 0; i < N_terms; i++) const_name[i] = "?";

      for (i = 0; i < n_symbols; i++)
      {
         if (symbol[i].type & TERMINAL)
         {
				if (!(symbol[i].type & CONSTANT))
				{
				// printf ("%4d %4d %s\n", i, symbol[i].numb, symbol[i].name);
					term_name [symbol[i].numb] = symbol[i].name;
					term_start[symbol[i].numb] = symbol[i].start;
					term_end  [symbol[i].numb] = symbol[i].start + symbol[i].length;
					term_type [symbol[i].numb] = symbol[i].type;
					term_line [symbol[i].numb] = symbol[i].line;
					if (symbol[i].value >= 0) // Got a defined constant?
					{
						term_const[symbol[i].numb] = symbol[i].numb;
						const_name[symbol[i].numb] = symbol[symbol[i].value].name;
					}
				}
         }
      }
		if (nu)
		{
			prt_warn ("// List of undeclared symbols in grammar:\n\n");
			int* seq;
			ALLOC (seq, N_terms);
			SORTNAMES (term_name, N_terms, seq);
			for (i = 0; i < N_terms; i++)
			{
				int j = seq[i];
				if (itsakeyword (term_name[j]))
				{
					prt_warn ("   %s;\n", term_name[j]);
				}
			}
			FREE (seq, N_terms);
			prt_warn ("\n");
		}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::alloc_struc ()
{
      ALLOC (head_name,    N_heads);
      ALLOC (head_type,    N_heads);
      ALLOC (head_line,    N_heads);
      ALLOC (prod_line,    N_prods);
      ALLOC (Reverse,      N_prods);
      ALLOC (Priority,     N_prods);
      ALLOC (F_prod,       N_heads+1);
      ALLOC (F_tail,       N_prods+1);
      ALLOC (Tail,         N_tails);

      ALLOC (Tact_start,   N_tacts+1);
      ALLOC (Node_start,   N_nodes+1);
      ALLOC (Nact_start,   N_nodes+1);
      ALLOC (Oper_prec,    N_terms);
      ALLOC (Tact_numb,    N_terms);
      ALLOC (Pact_numb,    N_prods);
      ALLOC (Node_numb,    N_prods);
      ALLOC (Nact_numb,    N_prods);
      ALLOC (F_targ,       N_terms);
      ALLOC (N_targ,       N_terms);
		ALLOC (F_parg,			N_prods);
		ALLOC (N_parg,			N_prods);
		ALLOC (F_narg,       N_prods);
      ALLOC (Arg_numb,     N_args+1);
      ALLOC (Str_start,    N_strings+1);
      ALLOC (Int_start,    N_ints+1);
      ALLOC (Defcon_name,  n_constants+1);
      ALLOC (Defcon_value, n_constants+1);
      ALLOC (Defcon_type,  n_constants+1);

		FASTINI( 0, Priority,  N_prods);
		FASTINI( 0, Oper_prec, N_terms);
      FASTINI(-1, Tact_numb, N_terms);
      FASTINI(-1, Pact_numb, N_prods);
      FASTINI(-1, Node_numb, N_prods);
      FASTINI(-1, Nact_numb, N_prods);
      FASTINI(-1, F_targ,    N_terms);
      FASTINI(-1, N_targ,    N_terms);
		FASTINI(-1, F_parg,    N_prods);
		FASTINI( 0, N_parg,    N_prods);
		FASTINI(-1, F_narg,    N_prods);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::fill_struc ()
{
      int i, nc = 0;
      for (i = 0; i < n_symbols; i++)
      {
         if (symbol[i].type & CONSTANT)
         {
				Defcon_name [nc]   = symbol[i].name;
				Defcon_type [nc]   = symbol[i].type;
				Defcon_value[nc++] = symbol[symbol[i].value].numb;
         }
      }
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & NONTERMINAL)
         {
            head_name[symbol[i].numb] = symbol[i].name;
            head_type[symbol[i].numb] = symbol[i].type; // PBM 20180904
         }
      }
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & TACTION)
         {
            Tact_start[symbol[i].numb] = symbol[i].name;
         }
      }
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & NODENAME)
         {
            Node_start[symbol[i].numb] = symbol[i].name;
         }
      }
		N_nacts = 0;
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & NODENAME)
         {
				N_nacts++;
			//	printf ("NODENAME %s\n", symbol[i].name);
				if (symbol[i].type & NACTION)
				{
				//	printf ("NACTION  %s\n", symbol[i].name);
					Nact_start[symbol[i].numb] = symbol[i].name;
				}
				else
				{
					Nact_start[symbol[i].numb] = "NULL";
				}
         }
      }
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & STRING)
         {
            Str_start[symbol[i].numb] = symbol[i].name;
         }
      }
      for (i = 1; i < n_symbols; i++)
      {
         if (symbol[i].type & INTEGER)
         {
            Int_start[symbol[i].numb] = symbol[i].name;
         }
      }
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::declarations_(void* v)
{
	// Neede for structure, finding last nonterm.
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::terminal_decl_ (void* v)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::defcon_ (void* v)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::terminal_ (void* v)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::operprec_ (void* v)
{
	// Neede for structure, finding last nonterm.
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::leftassoc_ (void* v)
{
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
            case TOP_DOWN:
               assoc = (++precedence);
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::rightassoc_ (void* v)
{
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               assoc = -(++precedence);
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::oper_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               Oper_prec[symbol[np->sti].numb] = assoc;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::rules_ (void* v)
{
	// Neede for structure, finding last nonterm.
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::ta_name_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
            static int terminal;
			   case TOP_DOWN:
					if (optn[PG_TERMACTIONS])
					{
						terminal = symbol[np->parent->prev->sti].numb;
						if (Tact_numb[terminal] >= 0) // Already defined?
						{
							prt_error("Terminal symbol %s has already been assigned an action.",
								term_start[terminal], term_end[terminal], np->line);
						}
						if (optn[PG_TERMACTIONS])
						Tact_numb[terminal] = symbol[np->sti].numb;
						F_targ[terminal] = N_args;
					}
					else
					{
						terminal = symbol[np->parent->prev->sti].numb;
						Tact_numb[terminal] = -1;
						F_targ[terminal] = N_args;
					}
               break;
			   case BOTTOM_UP:
					if (optn[PG_TERMACTIONS])
					{
						if (N_args == F_targ[terminal])
						{
							F_targ[terminal] = -1;
							N_targ[terminal] = 0;
						}
						else
						{
							N_targ[terminal] = N_args - F_targ[terminal];
						}
					}
					else
					{
						F_targ[terminal] = -1;
						N_targ[terminal] = 0;
					}
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::node_name_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
		{
			switch (direction)
			{
			case TOP_DOWN:
				if (optn[PG_ASTCONST])
				Node_numb[N_prods] = symbol[np->sti].numb;
				break;
			}
		}
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::node_action_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					if (optn[PG_NODEACTIONS])
					Nact_numb[N_prods] = symbol[np->sti].numb;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::targs_ (void* v)
{
/*
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					F_targ[N_terms] = N_args;
               break;
				case BOTTOM_UP:
					if (N_args == F_targ[N_terms])
					{
						F_targ[N_terms] = -1; // First production argument.
						N_targ[N_terms] = 0;  // Number of production arguments.
					}
					else
					{
						F_targ[N_terms] = N_args - F_targ[N_terms];
					}
					break;
			}
      }	*/
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::semargs_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					F_parg[N_prods] = N_args;
	            Arg_numb[N_args++] = 1;	// First arg is always 1.
               break;
				case BOTTOM_UP:
					if (N_args == F_parg[N_prods]) // No arguments.
					{
						F_parg[N_prods] = -1; // First production argument.
						N_parg[N_prods] = 0;  // Number of production arguments.
					}
					else // One semantic argument.
					{
						N_parg[N_prods] = N_args - F_parg[N_prods];
					}
					break;
			}
      }
		N_semantics = 1;
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::pargs_ (void* v)
{
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					if (N_parg[N_prods] == 0)
					{
						F_parg[N_prods] = N_args;
					}
					else // In case of semarg_
					{
						N_args -= N_parg[N_prods];
						F_parg[N_prods] = N_args;
					}
               break;
				case BOTTOM_UP:
					if (N_args == F_parg[N_prods])
					{
						F_parg[N_prods] = -1; // First production argument.
						N_parg[N_prods] = 0;  // Number of production arguments.
					}
					else if (N_parg[N_prods] == 0)
					{
						N_parg[N_prods] = N_args - F_parg[N_prods];
					}
					break;
			}
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::reverse_ (void* v)
{
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               Reverse[N_prods] = 1;
					N_reverses++;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::terminal_action_(void* v)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::rule_actions_ (void* v)
{
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::arg_integer_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               Arg_numb[N_args++] = symbol[np->sti].value;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::arg_semantic_ (void* v)
{
		arg_alpha_ (v);
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::arg_alpha_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
               if (symbol[np->sti].type & NONTERMINAL)
               {
                  prt_error ("at '%s', nonterminal symbols cannot be used as arguments",
							np->start, np->end, np->line);
               }
					else if (symbol[np->sti].type & CONSTANT)
					{
						Arg_numb[N_args++] = symbol[symbol[np->sti].value].numb;
					}
               else // Not CONSTANT.
               {
					   if (symbol[np->sti].type & TERMINAL)
						{
							Arg_numb[N_args++] = symbol[np->sti].numb;
						}
						else // Not TERMINAL.
						{
							symbol[np->sti].type |= TERMINAL | ARGUMENT;
							symbol[np->sti].numb = N_terms++;
							symbol[np->sti].value = -1;
							if (!(symbol[np->sti].type & TAIL))
							{
								prt_error ("at '%s', not used in grammar, not a constant and not declared",
									np->start, np->end, np->line);
							}
						}
               }
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::arg_terminal_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
            Arg_numb[N_args++] = symbol[np->sti].numb; // This is second arg.
				if (symbol[np->sti].value >= 0 && optn[PG_CONSTANTSUNUSED]) // Defined constant exists for this tail?
				{
					char buffer[256];
					int a = symbol[np->sti].value;
					sprintf (buffer, "Argument symbol %%s has a defined constant %s", symbol[a].name);
					prt_warning (buffer, np->start, np->end, np->line);
				}
            break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

int   PG_NodeActions::arg_string_ (void* v)
{
		Node* np = (Node*)v;
		if (pass == THIRD_PASS)
      {
         switch (direction)
		   {
			   case TOP_DOWN:
					// sequence number of string arg.
					Arg_numb[N_args++] = symbol[np->sti].numb;
               break;
		   }
      }
		return 0;
}

///////////////////////////////////////////////////////////////////////////////

void  PG_NodeActions::check_for_quotes () // Check for quotes on terminals.
{
      char c;
      int  t;
		static uchar which_case[256] = /* Gives 1 for upper and 2 for lower. */
		{
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
			  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,
			  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
			  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,

			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		};

		for (t = 0; t < N_terms; t++)
		{
         c = *term_name[t];
			if (c == '\'') continue;		// Already in quotes?
		  	if (c == '<' ) continue;	   // <...> symbol?
		  	if (c == '{' ) continue;	   // {...} symbol?
			if (term_type[t] & UNDECLARED)
			{
				int result = 0;
				int len = (int)strlen(term_name[t]);
				for (int i = 0; i < len; i++)
				{
					result |= which_case[term_name[t][i]];
				}
				if (result == 3 && optn[PG_MIXEDCASEUNDECL]) // Mixed case?
				{
					prt_warning ("Terminal %s has mixed case, better to declare or put in single quotes (')",
						term_start[t], term_end[t], term_line[t]);
				}
				if (result == 1 && optn[PG_UPPERCASEUNDECL]) // Uppercase?
				{
					prt_warning ("Terminal %s is all uppercase, better to declare or put in single quotes (')",
						term_start[t], term_end[t], term_line[t]);
				}
			}
         int sti, len, x;
         char *p, *s;
         len = (int)strlen (term_name[t]);
         s = ALLOC (p, len+3);
         *p++ = '\'';
         memcpy (p, term_name[t], len);
         p += len;
         *p++ = '\'';
         *p = 0;
			sti = add_symbol (s, p, TERMINAL|TAIL|ARGUMENT, term_line[t]);
         if (symbol[sti].numb >= 0) // Already used in grammar?
         {
            x = symbol[sti].numb;
				sprintf (string, "%s and %s were used in the grammar, cannot have both", term_name[t], term_name[x]);
            prt_error (string, term_start[t], term_end[t], term_line[t]);
         }
			term_name[t] = s;
		}
}

//                                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
