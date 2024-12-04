// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 150

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

parser grammar WhixyParser;
options {
    tokenVocab = WhixyLexer;
}

srcFile: NEWLINE? stmt (stmtSep stmt)* NEWLINE? EOF;

//
//    Statements
//

stmt
    : valsStmt
    | assignOpStmt
    | callStmt
    | blockStmt
    | routineStmt
    | returnStmt
    | ifStmt
    | whereStmt
    | loopStmt
    | comptStmt
    | deferStmt
    | errdeferStmt;

valsStmt: token+ COLON (expr? EQUAL NEWLINE?)? expr;

assignOpStmt: atom assignOp atom;
assignOp
    : AMPERSAND_EQUAL                       # andAssignOp
    | PIPE_EQUAL                            # orAssignOp
    | PERCENT_EQUAL                         # modulusAssignOp
    | CARROT_EQUAL                          # xorAssignOp
    | SLASH_EQUAL                           # divisionAssignOp
    | PLUS_EQUAL                            # additionAssignOp
    | MINUS_EQUAL                           # subtractionAssignOp
    | ASTERISK_EQUAL                        # multiplicationAssignOp
    | LESSTHAN_LESSTHAN_EQUAL               # leftShiftAssignOp
    | GREATERTHAN_GREATERTHAN_EQUAL         # rightShiftAssignOp
    | ASTERISK_PERCENT_EQUAL                # wrappingMultiplicationAssignOp
    | PLUS_PERCENT_EQUAL                    # wrappingAdditionAssignOp
    | MINUS_PERCENT_EQUAL                   # wrappingSubtractionAssignOp
    | GREATERTHAN_GREATERTHAN_PERCENT_EQUAL # rightRotationAssignOp
    | LESSTHAN_LESSTHAN_PERCENT_EQUAL       # leftRotationAssignOp;

callStmt: atom expr;

blockStmt
    : oParen (stmt (stmtSep stmt)*)? cParen      # funcBlockStmt
    | dollarParen (stmt (stmtSep stmt)*)? cParen # procBlockStmt;

routineStmt
    : token atom atom blockStmt        # plainRoutineStmt
    | INLINE token atom atom blockStmt # inlineRoutineStmt;

returnStmt: RETURN expr;

ifStmt: IF atom stmt (ELSEIF atom stmt)* (ELSE stmt)?;

whereStmt:     WHERE atom comparisonOp caseStmtBlock;
comparisonOp:  ;
caseStmtBlock: ;

loopStmt
    : UNROLL WHILE atom? atom? stmt # unrollWhileStmt
    | UNROLL FOR atom? atom? stmt   # unrollForStmt
    | WHILE atom? atom? stmt        # plainWhileStmt
    | FOR atom? atom? stmt          # plainForStmt;

comptStmt: COMPT stmt;

deferStmt: DEFER stmt;

errdeferStmt: ERRDEFER stmt;

//
//    Expressions
//

expr
    : valsStmt
    | callStmt
    | binaryOpExpr
    | postOpExpr
    | preOpExpr
    | ifExpr
    | whereExpr
    | loopExpr
    | comptExpr
    | routineExpr
    | string
    | atom;

binaryOpExpr: atom NEWLINE? binaryOp NEWLINE? atom;
binaryOp
    : AS                              # asOp
    | PLUS_PLUS                       # concatenationOp
    | ASTERISK_ASTERISK               # repetitionOp
    | PLUS                            # additionOp
    | MINUS                           # subtractionOp
    | ASTERISK                        # multiplicationOp
    | SLASH                           # divisionOp
    | LESSTHAN                        # lessThanOp
    | GREATERTHAN                     # greaterThanOp
    | LESSTHAN_EQUAL                  # lessThanEqualOp
    | GREATERTHAN_EQUAL               # greaterThanEqualOp
    | PLUS_PERCENT                    # wrappingAdditionOp
    | MINUS_PERCENT                   # wrappingSubtractionOp
    | ASTERISK_PERCENT                # wrappingMultiplicationOp
    | LESSTHAN_LESSTHAN               # leftShiftOp
    | GREATERTHAN_GREATERTHAN         # rightShiftOp
    | LESSTHAN_LESSTHAN_PERCENT       # leftRotationOp
    | GREATERTHAN_GREATERTHAN_PERCENT # rightRotationOp
    | EQUAL_EQUAL                     # equalityOp
    | EXCLAMATION_EQUAL               # inequalityOp
    | AMPERSAND                       # andOp
    | PIPE                            # orOp
    | PERCENT                         # modulusOp
    | CARROT                          # xorOp;

postOpExpr: atom postOp;
postOp
    : DOT atom      # accessFieldOp
    | DOT_TYPE      # accessTypeOp
    | DOT_LEN       # accessLengthOp
    | DOT_ASTERISK  # dereferencePointerOp
    | DOT_AMPERSAND # addressOfOp
    | DOT_QUESTION  # unwrapOptionalOp;

preOpExpr: preOp atom;
preOp:     EXCLAMATION # notOp | MINUS # negateOp;

ifExpr: IF atom expr (ELSEIF atom expr)* (ELSE expr)?;

whereExpr:     WHERE atom comparisonOp caseExprBlock;
caseExprBlock: ;

loopExpr
    : UNROLL WHILE atom? atom? expr # unrollWhileExpr
    | UNROLL FOR atom? atom? expr   # unrollForExpr
    | WHILE atom? atom? expr        # plainWhileExpr
    | FOR atom? atom? expr          # plainForExpr;

comptExpr: COMPT expr;

routineExpr
    : atom atom blockStmt        # plainRoutineExpr
    | INLINE atom atom blockStmt # inlineRoutineExpr;

string: DOUBLEQUOTESTRING # dQStringExpr | BACKTICKSTRING # bTStringExpr;

atom: token | blockExpr | typeExpr | tupleExpr;

token: TOKEN;

blockExpr: oParen ((stmt (stmtSep stmt)* stmtSep)? expr)? cParen;

typeExpr: oBrace (valsStmt (exprSep valsStmt)*)? cBrace;

tupleExpr: oParen (expr (exprSep expr)*)? cParen;

//
//    Flexibility
//

// ID NL?; NL? ID
oBracket:      OPENBRACKET NEWLINE?;
cBracket:      NEWLINE? CLOSEDBRACKET;
oAngleBracket: LESSTHAN_OPENBRACKET NEWLINE?;
cAngleBracket: NEWLINE? CLOSEDBRACKET_GREATERTHAN;

// NL? ID NL?; NL? ID
dollarParen: NEWLINE? DOLLAR_OPENPARENTHESIS NEWLINE?;
oParen:      NEWLINE? OPENPARENTHESIS NEWLINE?;
cParen:      NEWLINE? CLOSEDPARENTHESIS;
oBrace:      NEWLINE? OPENBRACE NEWLINE?;
cBrace:      NEWLINE? CLOSEDBRACE;

stmtSep: SEMICOLON | NEWLINE;
exprSep: COMMA | NEWLINE;