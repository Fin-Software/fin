// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 200

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

// Statement and expression IDs each end as such; punctuation IDs do not.

parser grammar WhixyParser;
options {
    tokenVocab = WhixyLexer;
}

srcFile: stmt (stmtSep stmt)* eof;

//
//    Statements
//

stmt
    : fieldExpr   # defStmt
    | blockStmt   # blockStmt
    | callExpr    # callStmt
    | RETURN expr # returnStmt
    |             # procStmt
    |             # funcStmt
    |             # ifStmt
    |             # forStmt
    |             # whileStmt;

blockStmt: oParen (stmt (stmtSep stmt)* NEWLINE?)? cParen;

//
//    Expressions
//

rootExpr: TOKEN # token | DOUBLEQUOTESTRING # doubleQuoteString | BACKTICKSTRING # backtickString;

expr
    : callExpr    # j
    | fieldExpr   # j
    | blockExpr   # j
    | tupleExpr   # j
    | typeExpr    # typeExpr
    | routineExpr # routineExpr
    | unaryExpr   # unaryExpr
    | binaryExpr  # binaryExpr
    | rootExpr    # rootExpr;

callExpr: expr (rootExpr | tupleExpr);

fieldExpr: TOKEN+ (COLON expr)? (EQUAL expr)?;

tupleExpr: oParen (expr (exprSep expr)* exprSep?)? cParen;

typeExpr: oBrace (fieldExpr (exprSep fieldExpr)* exprSep?)? cBrace;

blockExpr: oParen ((stmt (stmtSep stmt)* stmtSep)? expr NEWLINE?)? cParen;

routineExpr: FUNC typeExpr expr blockExpr # functionExpr | PROC typeExpr expr blockExpr # procedureExpr;

unaryExpr
    : EXCLAMATION expr  # notExpr
    | MINUS expr        # negationExpr
    | AMPERSAND expr    # addressOfExpr
    | expr DOT_ASTERISK # dereferencingMethodExpr
    | expr DOT_TYPE     # typeOfMethodExpr
    | expr DOT_LEN      # lengthOfMethodExpr;

binaryExpr
    : expr AS expr                              # asExpr
    | expr PLUS_PLUS expr                       # concatenationExpr
    | expr ASTERISK_ASTERISK expr               # repititionExpr
    | expr PLUS expr                            # additionExpr
    | expr MINUS expr                           # subtractionExpr
    | expr ASTERISK expr                        # multiplicationExpr
    | expr SLASH expr                           # divisionExpr
    | expr LESSTHAN expr                        # leftShiftingExpr
    | expr GREATERTHAN expr                     # rightShiftingExpr
    | expr PLUS_PERCENT expr                    # wrappingAdditionExpr
    | expr MINUS_PERCENT expr                   # wrappingSubtrationExpr
    | expr ASTERISK_PERCENT expr                # wrappingMultiplicationExpr
    | expr LESSTHAN_LESSTHAN_PERCENT expr       # leftRotationExpr
    | expr GREATERTHAN_GREATERTHAN_PERCENT expr # rightRotationExpr;

//
//    Flexibiliy
//

stmtSep: SEMICOLON | NEWLINE;
exprSep: COMMA | NEWLINE;

// NL? ID
eof: NEWLINE? EOF;

// ID NL?; NL? ID
oBracket:      OPENBRACKET NEWLINE?;
cBracket:      NEWLINE? CLOSEDBRACKET;
oAngleBracket: LESSTHAN_OPENBRACKET NEWLINE?;
cAngleBracket: NEWLINE? CLOSEDBRACKET_GREATERTHAN;

// NL? ID NL?
oParen:               NEWLINE? OPENPARENTHESIS NEWLINE?;
cParen:               NEWLINE? CLOSEDPARENTHESIS NEWLINE?;
oBrace:               NEWLINE? OPENBRACE NEWLINE?;
cBrace:               NEWLINE? CLOSEDBRACE NEWLINE?;
gtGtPercentEqual:     NEWLINE? GREATERTHAN_GREATERTHAN_PERCENT_EQUAL NEWLINE?;
gtGtPercent:          NEWLINE? GREATERTHAN_GREATERTHAN_PERCENT NEWLINE?;
gtGtEqual:            NEWLINE? GREATERTHAN_GREATERTHAN_EQUAL NEWLINE?;
gtGt:                 NEWLINE? GREATERTHAN_GREATERTHAN NEWLINE?;
gtEqual:              NEWLINE? GREATERTHAN_EQUAL NEWLINE?;
gt:                   NEWLINE? GREATERTHAN NEWLINE?;
ltLtPercentEqual:     NEWLINE? LESSTHAN_LESSTHAN_PERCENT_EQUAL NEWLINE?;
ltLtPercent:          NEWLINE? LESSTHAN_LESSTHAN_PERCENT NEWLINE?;
ltLtEqual:            NEWLINE? LESSTHAN_LESSTHAN_EQUAL NEWLINE?;
ltLt:                 NEWLINE? LESSTHAN_LESSTHAN NEWLINE?;
ltEqual:              NEWLINE? LESSTHAN_EQUAL NEWLINE?;
lt:                   NEWLINE? LESSTHAN NEWLINE?;
asteriskPercentEqual: NEWLINE? ASTERISK_PERCENT_EQUAL NEWLINE?;
asteriskPercent:      NEWLINE? ASTERISK_PERCENT NEWLINE?;
asteriskEqual:        NEWLINE? ASTERISK_EQUAL NEWLINE?;
asteriskAsterisk:     NEWLINE? ASTERISK_ASTERISK NEWLINE?;
asterisk:             NEWLINE? ASTERISK NEWLINE?;
plusPercentEqual:     NEWLINE? PLUS_PERCENT_EQUAL NEWLINE?;
plusPercent:          NEWLINE? PLUS_PERCENT NEWLINE?;
plusEqual:            NEWLINE? PLUS_EQUAL NEWLINE?;
plusPlus:             NEWLINE? PLUS_PLUS NEWLINE?;
plus:                 NEWLINE? PLUS NEWLINE?;
minusPercentEqual:    NEWLINE? MINUS_PERCENT_EQUAL NEWLINE?;
minusPercent:         NEWLINE? MINUS_PERCENT NEWLINE?;
minusEqual:           NEWLINE? MINUS_EQUAL NEWLINE?;
minus:                NEWLINE? MINUS NEWLINE?;
exclamationEqual:     NEWLINE? EXCLAMATION_EQUAL NEWLINE?;
exclamation:          NEWLINE? EXCLAMATION NEWLINE?;
ampersandEqual:       NEWLINE? AMPERSAND_EQUAL NEWLINE?;
ampersand:            NEWLINE? AMPERSAND NEWLINE?;
percentEqual:         NEWLINE? PERCENT_EQUAL NEWLINE?;
percent:              NEWLINE? PERCENT NEWLINE?;
carrotEqual:          NEWLINE? CARROT_EQUAL NEWLINE?;
carrot:               NEWLINE? CARROT NEWLINE?;
slashEqual:           NEWLINE? SLASH_EQUAL NEWLINE?;
slash:                NEWLINE? SLASH NEWLINE?;
equalEqual:           NEWLINE? EQUAL_EQUAL NEWLINE?;
equal:                NEWLINE? EQUAL NEWLINE?;
pipeEqual:            NEWLINE? PIPE_EQUAL NEWLINE?;
pipe:                 NEWLINE? PIPE NEWLINE?;
as:                   NEWLINE? AS NEWLINE?;