// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 65536

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

lexer grammar WhixyLexer;

// TODO: Tokens are to be reordered to maximize lexing speed of std, barring overshadowing other rules.

// TODO: When Whixy is self-hostable, replace ANTLR4 with a recursive descent parser. Predicates here are especially slow.

DOUBLEQUOTESTRING: '"' ('\\"' | ~["])* '"';                                // NB: separate tokens saves work
BACKTICKSTRING:    '`' ('\\`' | ~[`])* '`';                                // NB: separate tokens saves work
BACKSLASHSTRING:   (WHITESPACE? '\\ ' ~[\r\n]* [\r\n])+;                   // TODO(@p7r0x7): missing predicate
BLOCKDOCCOMMENT:   (WHITESPACE? '##' ~[\r\n]* [\r\n])+ -> channel(HIDDEN); // TODO(@p7r0x7): missing predicate
BLOCKCOMMENT:      (WHITESPACE? '#' ~[\r\n]* [\r\n])+ -> channel(HIDDEN);  // TODO(@p7r0x7): missing predicate
DOCCOMMENT:        '##' ~[\r\n]* -> channel(HIDDEN);
COMMENT:           '#' ~[\r\n]* -> channel(HIDDEN);
WHITESPACE:        [ \t]+ -> channel(HIDDEN);
NEWLINE:           [\r\n]+;

// SORTED ^^

OPENPARENTHESIS:        '(';  // open group expression
CLOSEDPARENTHESIS:      ')';  // close group expression
DOT:                    '.';  // postfix op: access field (after DOT...)
COMMA:                  ',';  // expression separator
UNDERSCORE:             '_';  // type inferrence directive or 
EXCLAMATION:            '!';  // infix op: logical NOT; bitwise NOT (after EXCLAMATION...)
OPENBRACE:              '{';  // open type expression
CLOSEDBRACE:            '}';  // close type expression
OPENBRACKET:            '[';  // open indexing expression
CLOSEDBRACKET:          ']';  // close indexing expression
SEMICOLON:              ';';  // statement separator
QUESTION:               '?';  // postfix op: explicitly unwrap optional
DOLLAR_OPENPARENTHESIS: '$('; //
SINGLEQUOTE:            '\''; //

GREATERTHAN_GREATERTHAN_PERCENT_EQUAL: '>>%='; // combined assignment: rotr
GREATERTHAN_GREATERTHAN_PERCENT:       '>>%';  //
GREATERTHAN_GREATERTHAN_EQUAL:         '>>=';  // combined assignment: right shift
GREATERTHAN_GREATERTHAN:               '>>';   //
GREATERTHAN_EQUAL:                     '>=';   // infix op: greater than or equal to comparison
GREATERTHAN:                           '>';    // infix op: greater than comparison
LESSTHAN_LESSTHAN_PERCENT_EQUAL:       '<<%='; // combined assignment: rotl
LESSTHAN_LESSTHAN_PERCENT:             '<<%';  // rotl
LESSTHAN_LESSTHAN_EQUAL:               '<<=';  // combined assignment: left shift
LESSTHAN_LESSTHAN:                     '<<';   // left shift
LESSTHAN_EQUAL:                        '<=';   // infix op: less than or equal to comparison
LESSTHAN:                              '<';    // infix op: less than comparison
ASTERISK_PERCENT_EQUAL:                '*%=';  // combined wrapping assignment: multiplication
ASTERISK_PERCENT:                      '*%';   //
ASTERISK_EQUAL:                        '*=';   // combined assignment: multiplication
ASTERISK_ASTERISK:                     '**';   // infix op: comptime value repetition
ASTERISK:                              '*';    // (after ASTERISK...)
PLUS_PERCENT_EQUAL:                    '+%=';  // combined wrapping assignment: addition
PLUS_PERCENT:                          '+%';   //
PLUS_EQUAL:                            '+=';   // combined assignment: addition
PLUS_PLUS:                             '++';   // infix op: comptime value concatenation
PLUS:                                  '+';    // infix op: addition (after PLUS...)
MINUS_PERCENT_EQUAL:                   '-%=';  // combined wrapping assignment: subtraction
MINUS_PERCENT:                         '-%';   //
MINUS_EQUAL:                           '-=';   // combined assignment: subtraction
MINUS:                                 '-';    // infix op: subtraction; prefix: negation (after MINUS...)
TILDE_EQUAL:                           '~=';   // infix op: inequality comparison
TILDE:                                 '~';    // infix op: logical NOT; bitwise NOT (after EXCLAMATION...)
AMPERSAND_EQUAL:                       '&=';   // combined assignment: bitwise AND
AMPERSAND:                             '&';    // infix op: logical AND; bitwise AND (after AMPERSAND...)
PERCENT_EQUAL:                         '%=';   // combined assignment: modulus
PERCENT:                               '%';    // (after PERCENT...)
CARROT_EQUAL:                          '^=';   // combined assignment: bitwise XOR
CARROT:                                '^';    // infix op: logical XOR bitwise XOR (after CARROT...)
SLASH_EQUAL:                           '/=';   // combined assignment: division
SLASH:                                 '/';    // (after SLASH...)
EQUAL_EQUAL:                           '==';   // infix op: equality comparison
EQUAL:                                 '=';    // infix op: assign type instance to value; declare default type instance of value (after EQUAL...)
PIPE_EQUAL:                            '|=';   // combined assignment: bitwise OR
PIPE:                                  '|';    // infix op: logical OR; bitwise OR; routine overloading (after PIPE...)

AND:         'and';         //
OR:          'or';          // logical or operator
TYPE:        'type';        // postfix: access comptime type
LEN:         'len';         // postfix: access length
THIS:        'this';        // immediately encapsulating type directive
MUT:         'mut';         // value mutability modifier
INLINE:      'inline';      // routine inlining modifier
RETURN:      'return';      // return statement
CONTINUE:    'continue';    // goto continue statement
BREAK:       'break';       // goto break statement
GOTO:        'goto';        // goto label statement
WHILE:       'while';       // while loop statement/expression
FOR:         'for';         // for loop statement/expression
IF:          'if';          // if statement statement/expression
ELSEIF:      'elseif';      // elseif statement/expression
ELSE:        'else';        // else statement/expression
WHERE:       'where';       // enhanced switch statement/expression
DEFER:       'defer';       // defer statement
ERRDEFER:    'errdefer';    // errdefer statement
FAST:        'fast';        // routine fastcall convention modifier
BARE:        'bare';        // routine freestanding convention modifier
IMPORT:      'import';      // import statement/expression
ALIGN:       'align';       // value alignment modifier
THREADL:     'threadl';     // value thread-local modifier
UNREACHABLE: 'unreachable'; // unreachable statement/expression
VOLATILE:    'volatile';    // value volatile modifier
UNROLL:      'unroll';      // loop inlining modifier
COMPT:       'compt';       // type/statement/expression comptime modifier
TEST:        'test';        // routine test modifier
ENUM:        'enum';        // enumeration type expression
EMBED:       'embed';       // disk data embed directive
UNION:       'union';       // union type expression
STD:         'std';         // standard library value
ORELSE:      'orelse';      // optional unwrapping operator
CATCH:       'catch';       // error handling operator
AS:          'as';          // coercion operator

// SORTED vv

TOKEN: .+?; // tokens to be parsed during AST semantic analysis (-1st)