// $antlr-format alignTrailingComments true, allowShortRulesOnASingleLine true, minEmptyLines 0
// $antlr-format useTab false, maxEmptyLinesToKeep 1, alignSemicolons none, alignColons hanging
// $antlr-format reflowComments false, alignFirstTokens true, columnLimit 100

// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

parser grammar WhixyParser;
options {
    tokenVocab = WhixyLexer;
}

srcFile: stmt+ EOF;

stmt
    : DEF valsExpr stmtSep # valStmt
    | RETURN expr stmtSep  # returnStmt
    | blockExpr stmtSep    # blockStmt
    | callExpr stmtSep     # callStmt;

expr
    : callExpr
    | valsExpr
    | blockExpr
    | tupleExpr
    | typeExpr
    | routineExpr
    | unaryExpr
    | binaryExpr
    | literalExpr;

callExpr: expr (TOKEN | tupleExpr);

valsExpr: TOKEN+ (COLON expr)? (EQUAL expr)?;

blockExpr
    : OPENBRACE (stmt (stmtSep stmt)* stmtSep?)? CLOSEDBRACE;

tupleExpr
    : OPENPARENTHESIS (expr (exprSep expr)* exprSep?)? CLOSEDPARENTHESIS;

typeExpr
    : OPENBRACE (valsExpr (exprSep valsExpr)* exprSep?)? CLOSEDBRACE;

routineExpr
    : FUNC typeExpr expr blockExpr # functionExpr
    | PROC typeExpr expr blockExpr # procedureExpr;

unaryExpr
    : OPENPARENTHESIS expr CLOSEDPARENTHESIS # parentheticExpr
    | EXCLAMATION expr                       # notExpr
    | MINUS expr                             # negationExpr
    | AMPERSAND expr                         # addressOfExpr
    | expr DOT_ASTERISK                      # dereferencingMethodExpr
    | expr DOT_TYPE                          # typeOfMethodExpr
    | expr DOT_LEN                           # lengthOfMethodExpr;

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

literalExpr: TOKEN | DOUBLEQUOTESTRING | BACKTICKSTRING;
stmtSep:     SEMICOLON | NEWLINE;
exprSep:     COMMA | NEWLINE;