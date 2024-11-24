// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 200

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

parser grammar WhixyParser;
options {
    tokenVocab = WhixyLexer;
}

srcFile: stmt (stmtSep stmt)* eof;

//
//    Statements
//

stmt: valsStmt | callStmt | blockStmt | returnStmt | functionStmt | procedureStmt | ifStmt | whileStmt | forStmt;

valsStmt: token+ COLON (expr EQUAL | EQUAL)? expr;

callStmt: atom+;

blockStmt: oParen (stmt (stmtSep stmt)*)? cParen;

returnStmt: RETURN atom+;

functionStmt: INLINE? FUNC token typeExpr tupleExpr blockStmt;

procedureStmt: INLINE? PROC token typeExpr tupleExpr blockStmt;

ifStmt: IF blockExpr blockStmt (ELSEIF blockExpr blockStmt)* (ELSE blockStmt)?;

whileStmt: UNROLL? WHILE blockExpr? blockExpr? blockStmt;

forStmt: UNROLL? FOR blockExpr? blockExpr? blockStmt;

//
//    Expressions
//

expr
    : valsStmt
    | callStmt
    | ifExpr
    | functionExpr
    | procedureExpr //| unaryExpr | binaryExpr
    | string
    | atom;

ifExpr: IF blockExpr expr (ELSEIF blockExpr expr)* (ELSE expr)?;

functionExpr: INLINE? FUNC typeExpr tupleExpr blockStmt;

procedureExpr: INLINE? PROC typeExpr tupleExpr blockStmt;

string: DOUBLEQUOTESTRING # doubleQuoteStringExpr | BACKTICKSTRING # backTickStringExpr;

//unaryExpr
//    : EXCLAMATION expr  # notExpr
//    | MINUS expr        # negationExpr
//    | AMPERSAND expr    # addressOfExpr
//    | expr DOT_ASTERISK # dereferencingMethodExpr
//    | expr DOT_TYPE     # typeOfMethodExpr
//    | expr DOT_LEN      # lengthOfMethodExpr;
//
//binaryExpr
//    : expr AS expr                              # asExpr
//    | expr PLUS_PLUS expr                       # concatenationExpr
//    | expr ASTERISK_ASTERISK expr               # repititionExpr
//    | expr PLUS expr                            # additionExpr
//    | expr MINUS expr                           # subtractionExpr
//    | expr ASTERISK expr                        # multiplicationExpr
//    | expr SLASH expr                           # divisionExpr
//    | expr LESSTHAN expr                        # leftShiftingExpr
//    | expr GREATERTHAN expr                     # rightShiftingExpr
//    | expr PLUS_PERCENT expr                    # wrappingAdditionExpr
//    | expr MINUS_PERCENT expr                   # wrappingSubtrationExpr
//    | expr ASTERISK_PERCENT expr                # wrappingMultiplicationExpr
//    | expr LESSTHAN_LESSTHAN_PERCENT expr       # leftRotationExpr
//    | expr GREATERTHAN_GREATERTHAN_PERCENT expr # rightRotationExpr;

atom: blockExpr | typeExpr | tupleExpr | token;

blockExpr: oParen ((stmt (stmtSep stmt)* stmtSep)? expr)? cParen;

typeExpr: oBrace (valsStmt (exprSep valsStmt)*)? cBrace;

tupleExpr: oParen (expr (exprSep expr)*)? cParen;

token: TOKEN;

//
//    Flexibility
//

// NL? ID
eof: NEWLINE? EOF;

// ID NL?
equal: EQUAL NEWLINE?;

// ID NL?; NL? ID
oBracket:      OPENBRACKET NEWLINE?;
cBracket:      NEWLINE? CLOSEDBRACKET;
oAngleBracket: LESSTHAN_OPENBRACKET NEWLINE?;
cAngleBracket: NEWLINE? CLOSEDBRACKET_GREATERTHAN;

// NL? ID NL?
oParen:         NEWLINE? OPENPARENTHESIS NEWLINE?;
cParen:         NEWLINE? CLOSEDPARENTHESIS NEWLINE?;
oBrace:         NEWLINE? OPENBRACE NEWLINE?;
cBrace:         NEWLINE? CLOSEDBRACE NEWLINE?;
gtGtPercentEq:  NEWLINE? GREATERTHAN_GREATERTHAN_PERCENT_EQUAL NEWLINE?;
gtGtPercent:    NEWLINE? GREATERTHAN_GREATERTHAN_PERCENT NEWLINE?;
gtGtEq:         NEWLINE? GREATERTHAN_GREATERTHAN_EQUAL NEWLINE?;
gtGt:           NEWLINE? GREATERTHAN_GREATERTHAN NEWLINE?;
gtEq:           NEWLINE? GREATERTHAN_EQUAL NEWLINE?;
gt:             NEWLINE? GREATERTHAN NEWLINE?;
ltLtPercentEq:  NEWLINE? LESSTHAN_LESSTHAN_PERCENT_EQUAL NEWLINE?;
ltLtPercent:    NEWLINE? LESSTHAN_LESSTHAN_PERCENT NEWLINE?;
ltLtEq:         NEWLINE? LESSTHAN_LESSTHAN_EQUAL NEWLINE?;
ltLt:           NEWLINE? LESSTHAN_LESSTHAN NEWLINE?;
ltEq:           NEWLINE? LESSTHAN_EQUAL NEWLINE?;
lt:             NEWLINE? LESSTHAN NEWLINE?;
starPercentEq:  NEWLINE? ASTERISK_PERCENT_EQUAL NEWLINE?;
starPercent:    NEWLINE? ASTERISK_PERCENT NEWLINE?;
starEq:         NEWLINE? ASTERISK_EQUAL NEWLINE?;
starStar:       NEWLINE? ASTERISK_ASTERISK NEWLINE?;
star:           NEWLINE? ASTERISK NEWLINE?;
plusPercentEq:  NEWLINE? PLUS_PERCENT_EQUAL NEWLINE?;
plusPercent:    NEWLINE? PLUS_PERCENT NEWLINE?;
plusEq:         NEWLINE? PLUS_EQUAL NEWLINE?;
plusPlus:       NEWLINE? PLUS_PLUS NEWLINE?;
plus:           NEWLINE? PLUS NEWLINE?;
minusPercentEq: NEWLINE? MINUS_PERCENT_EQUAL NEWLINE?;
minusPercent:   NEWLINE? MINUS_PERCENT NEWLINE?;
minusEq:        NEWLINE? MINUS_EQUAL NEWLINE?;
minus:          NEWLINE? MINUS NEWLINE?;
exclamationEq:  NEWLINE? EXCLAMATION_EQUAL NEWLINE?;
exclamation:    NEWLINE? EXCLAMATION NEWLINE?;
ampersandEq:    NEWLINE? AMPERSAND_EQUAL NEWLINE?;
ampersand:      NEWLINE? AMPERSAND NEWLINE?;
percentEq:      NEWLINE? PERCENT_EQUAL NEWLINE?;
percent:        NEWLINE? PERCENT NEWLINE?;
carrotEq:       NEWLINE? CARROT_EQUAL NEWLINE?;
carrot:         NEWLINE? CARROT NEWLINE?;
slashEq:        NEWLINE? SLASH_EQUAL NEWLINE?;
slash:          NEWLINE? SLASH NEWLINE?;
equalEq:        NEWLINE? EQUAL_EQUAL NEWLINE?;
pipeEq:         NEWLINE? PIPE_EQUAL NEWLINE?;
pipe:           NEWLINE? PIPE NEWLINE?;
as:             NEWLINE? AS NEWLINE?;

stmtSep: SEMICOLON | NEWLINE;
exprSep: COMMA | NEWLINE;