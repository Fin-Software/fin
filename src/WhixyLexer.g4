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

COLON:                     ':';                   // type specifier
COMMA:                     ',';                   // expression separator
SEMICOLON:                 ';';                   // statement separator
QUESTION:                  '?';                   // Type modifier (optional types)
OPENPARENTHESIS:           NEWLINE? '(' NEWLINE?; // open group expression
CLOSEDPARENTHESIS:         NEWLINE? ')' NEWLINE?; // close group expression
OPENBRACE:                 NEWLINE? '{' NEWLINE?; // open block or type expression
CLOSEDBRACE:               NEWLINE? '}' NEWLINE?; // close block or type expression
LESSTHAN_OPENBRACKET:      '<[' NEWLINE?;         // open indexing expression
CLOSEDBRACKET_GREATERTHAN: NEWLINE? ']>';         // close indexing expression
OPENBRACKET:               '[' NEWLINE?;          // open indexing expression
CLOSEDBRACKET:             NEWLINE? ']';          // close indexing expression

DOT_TYPE:      '.type'; // postfix op: access comptime type
DOT_LEN:       '.len';  // postfix op: access length
DOT_ASTERISK:  '.*';    // postfix op: dereference pointer 
DOT_AMPERSAND: '.&';    // postfix op: access address-of
DOT_QUESTION:  '.?';    // postfix op: explicitly unwrap optional
DOT:           '.';     // postfix op: access field (after DOT...)

GREATERTHAN_GREATERTHAN_PERCENT_EQUAL: NEWLINE? '>>%=' NEWLINE?; // combined assignment: rotr
GREATERTHAN_GREATERTHAN_PERCENT:       NEWLINE? '>>%' NEWLINE?;  //
GREATERTHAN_GREATERTHAN_EQUAL:         NEWLINE? '>>=' NEWLINE?;  // combined assignment: right shift
GREATERTHAN_GREATERTHAN:               NEWLINE? '>>' NEWLINE?;   //
GREATERTHAN_EQUAL:                     NEWLINE? '>=' NEWLINE?;   // infix op: greater than or equal to comparison
GREATERTHAN:                           NEWLINE? '>' NEWLINE?;    // infix op: greater than comparison
LESSTHAN_LESSTHAN_PERCENT_EQUAL:       NEWLINE? '<<%=' NEWLINE?; // combined assignment: rotl
LESSTHAN_LESSTHAN_PERCENT:             NEWLINE? '<<%' NEWLINE?;  // rotl
LESSTHAN_LESSTHAN_EQUAL:               NEWLINE? '<<=' NEWLINE?;  // combined assignment: left shift
LESSTHAN_LESSTHAN:                     NEWLINE? '<<' NEWLINE?;   // left shift
LESSTHAN_EQUAL:                        NEWLINE? '<=' NEWLINE?;   // infix op: less than or equal to comparison
LESSTHAN:                              NEWLINE? '<' NEWLINE?;    // infix op: less than comparison

ASTERISK_PERCENT_EQUAL: NEWLINE? '*%=' NEWLINE?; // combined wrapping assignment: multiplication
ASTERISK_PERCENT:       NEWLINE? '*%' NEWLINE?;  //
ASTERISK_EQUAL:         NEWLINE? '*=' NEWLINE?;  // combined assignment: multiplication
ASTERISK_ASTERISK:      NEWLINE? '**' NEWLINE?;  // infix op: comptime value repetition
ASTERISK:               NEWLINE? '*' NEWLINE?;   // (after ASTERISK...)
PLUS_PERCENT_EQUAL:     NEWLINE? '+%=' NEWLINE?; // combined wrapping assignment: addition
PLUS_PERCENT:           NEWLINE? '+%' NEWLINE?;  //
PLUS_EQUAL:             NEWLINE? '+=' NEWLINE?;  // combined assignment: addition
PLUS_PLUS:              NEWLINE? '++' NEWLINE?;  // infix op: comptime value concatenation
PLUS:                   NEWLINE? '+' NEWLINE?;   // infix op: addition (after PLUS...)

MINUS_PERCENT_EQUAL: NEWLINE? '-%=' NEWLINE?; // combined wrapping assignment: subtraction
MINUS_PERCENT:       NEWLINE? '-%' NEWLINE?;  //
MINUS_EQUAL:         NEWLINE? '-=' NEWLINE?;  // combined assignment: subtraction
MINUS:               NEWLINE? '-' NEWLINE?;   // infix op: subtraction; prefix: negation (after MINUS...)

EXCLAMATION_EQUAL: NEWLINE? '!=' NEWLINE?; // infix op: inequality comparison
EXCLAMATION:       NEWLINE? '!' NEWLINE?;  // infix op: logical NOT; bitwise NOT (after EXCLAMATION...)

AMPERSAND_EQUAL: NEWLINE? '&=' NEWLINE?; // combined assignment: bitwise AND
AMPERSAND:       NEWLINE? '&' NEWLINE?;  // infix op: logical AND; bitwise AND (after AMPERSAND...)

PERCENT_EQUAL: NEWLINE? '%=' NEWLINE?; // combined assignment: modulus
PERCENT:       NEWLINE? '%' NEWLINE?;  // (after PERCENT...)

CARROT_EQUAL: NEWLINE? '^=' NEWLINE?; // combined assignment: bitwise XOR
CARROT:       NEWLINE? '^' NEWLINE?;  // infix op: logical XOR bitwise XOR (after CARROT...)

SLASH_EQUAL: NEWLINE? '/=' NEWLINE?; // combined assignment: division
SLASH:       NEWLINE? '/' NEWLINE?;  // (after SLASH...)

EQUAL_EQUAL: NEWLINE? '==' NEWLINE?; // infix op: equality comparison
EQUAL:       NEWLINE? '=' NEWLINE?;  // infix op: assign type instance to value; declare default type instance of value (after EQUAL...)

PIPE_EQUAL: NEWLINE? '|=' NEWLINE?; // combined assignment: bitwise OR
PIPE:       NEWLINE? '|' NEWLINE?;  // infix op: logical OR; bitwise OR; routine overloading (after PIPE...)

DEF:         'def';         //
PROC:        'proc';        // Routine keyword (procedure)
FUNC:        'func';        // Routine keyword (function)
MUT:         'mut';         // Type modifier (mutable)
INLINE:      'inline';      // Inline optimization hint
RETURN:      'return';      // Return statement
BREAK:       'break';       // Break from loop
CONTINUE:    'continue';    // Continue loop iteration
WHILE:       'while';       // Loop control structure
FOR:         'for';         // Loop control structure
IF:          'if';          // Conditional structure
ELSEIF:      'elseif';      // Else if statement
ELSE:        'else';        // Conditional alternative
MATCH:       'match';       // Pattern matching
IS:          'is';          // Enhanced switch statement
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