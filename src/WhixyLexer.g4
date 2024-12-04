// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 65536

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

lexer grammar WhixyLexer;

// TODO: Tokens are to be reordered to maximize lexing speed of std, barring overshadowing other rules.

DOUBLEQUOTESTRING: '"' ('\\"' | .)*? '"'; // NB: separate tokens saves work
BACKTICKSTRING:    '`' ('\\`' | .)*? '`'; // NB: separate tokens saves work
DOCCOMMENT:        '###' ~[\r\n]*;
COMMENT:           '#' ~[\r\n]* -> channel(HIDDEN);
WHITESPACE:        [ \t]+ -> channel(HIDDEN);

// SORTED ^^

COLON:                     ':';  // type specifier
COMMA:                     ',';  // expression separator
SEMICOLON:                 ';';  // statement separator
QUESTION:                  '?';  // Type modifier (optional types)
DOLLAR_OPENPARENTHESIS:    '$('; //
OPENPARENTHESIS:           '(';  // open group expression
CLOSEDPARENTHESIS:         ')';  // close group expression
OPENBRACE:                 '{';  // open block or type expression
CLOSEDBRACE:               '}';  // close block or type expression
LESSTHAN_OPENBRACKET:      '<['; // open indexing expression
CLOSEDBRACKET_GREATERTHAN: ']>'; // close indexing expression
OPENBRACKET:               '[';  // open indexing expression
CLOSEDBRACKET:             ']';  // close indexing expression

DOT_TYPE:      '.type'; // postfix op: access comptime type
DOT_LEN:       '.len';  // postfix op: access length
DOT_ASTERISK:  '.*';    // postfix op: dereference pointer 
DOT_AMPERSAND: '.&';    // postfix op: access address-of
DOT_QUESTION:  '.?';    // postfix op: explicitly unwrap optional
DOT:           '.';     // postfix op: access field (after DOT...)

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
EXCLAMATION_EQUAL:                     '!=';   // infix op: inequality comparison
EXCLAMATION:                           '!';    // infix op: logical NOT; bitwise NOT (after EXCLAMATION...)
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

MUT:         'mut';         // Type modifier (mutable)
INLINE:      'inline';      // Inline optimization hint
RETURN:      'return';      // Return statement
CONTINUE:    'continue';    // Continue loop iteration
BREAK:       'break';       // Break from loop
GOTO:        'goto';        // Goto
WHILE:       'while';       // Loop control structure
FOR:         'for';         // Loop control structure
IF:          'if';          // Conditional structure
ELSEIF:      'elseif';      // Else if statement
ELSE:        'else';        // Conditional alternative
WHERE:       'where';       // Enhanced switch statement
DEFER:       'defer';       // Defer execution until scope ends
ERRDEFER:    'errdefer';    // Error handling with defer
ORELSE:      'orelse';      // Alternate error handling
TRY:         'try';         // Error handling structure
CATCH:       'catch';       // Error handling structure
IMPORT:      'import';      // Import modules
ALIGN:       'align';       // Type alignment modifier
THREADLOCAL: 'threadlocal'; // Type modifier (thread-local storage)
UNREACHABLE: 'unreachable'; //
VOLATILE:    'volatile';    // Type modifier (volatile)
UNROLL:      'unroll';      // Loop optimization hint
COMPT:       'compt';       // Type modifier (comptime/compile-time)
TEST:        'test';        // Unit test declaration
ENUM:        'enum';        // Enumeration type
UNION:       'union';       // Union type
STD:         'std';         // Standard library access
AS:          'as';          // infix op: Type casting

// SORTED vv

NEWLINE: [\r\n]+; // statement separator; expression separator; whitespace (-2nd)
TOKEN:   .+?;     // tokens to be parsed during AST generation (-1st)