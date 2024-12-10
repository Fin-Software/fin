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

stmtSep: SEMICOLON | NEWLINE;
stmt
    : field
    | assignStmt
    | call
    | blockStmt
    | routineStmt
    | returnStmt
    | ifStmt
    | whereStmt
    | loopStmt
    | comptStmt
    | unreachable
    | deferStmt
    | errdeferStmt;

field
    : (AUTO | ASTERISK THIS | atom) token+ (EQUAL NEWLINE? expr)?     # immutableVals
    | MUT (AUTO | ASTERISK THIS | atom) token+ (EQUAL NEWLINE? expr)? # mutableVals;

assignStmt: atom assignOp atom;
assignOp
    : AMPERSAND_EQUAL                       # andEqualsOp
    | PIPE_EQUAL                            # orEqualsOp
    | PERCENT_EQUAL                         # modEqualsOp
    | CARROT_EQUAL                          # xorEqualsOp
    | SLASH_EQUAL                           # divideEqualsOp
    | PLUS_EQUAL                            # addEqualsOp
    | MINUS_EQUAL                           # subEqualsOp
    | ASTERISK_EQUAL                        # timesEqualsOp
    | LESSTHAN_LESSTHAN_EQUAL               # leftShiftEqualsOp
    | GREATERTHAN_GREATERTHAN_EQUAL         # rightShiftEqualsOp
    | ASTERISK_PERCENT_EQUAL                # wrappingTimesEqualsOp
    | PLUS_PERCENT_EQUAL                    # wrappingAddEqualsOp
    | MINUS_PERCENT_EQUAL                   # wrappingSubEqualsOp
    | GREATERTHAN_GREATERTHAN_PERCENT_EQUAL # rightRotateEqualsOp
    | LESSTHAN_LESSTHAN_PERCENT_EQUAL       # leftRotateEqualsOp;

call: atom expr;

blockStmt
    : oParen (stmt (stmtSep stmt)*)? cParen                                   # funcBlockStmt
    | NEWLINE? DOLLAR OPENPARENTHESIS NEWLINE? (stmt (stmtSep stmt)*)? cParen # procBlockStmt;

routineStmt
    : atom token structExpr blockStmt        # plainRoutineStmt
    | INLINE atom token structExpr blockStmt # inlineRoutineStmt;

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

unreachable: UNREACHABLE;

deferStmt: DEFER stmt;

errdeferStmt: ERRDEFER stmt;

//
//    Expressions
//

exprSep: COMMA | NEWLINE;
expr
    : field
    | call
    | binaryExpr
    | postExpr
    | preExpr
    | ifExpr
    | whereExpr
    | loopExpr
    | comptExpr
    | unreachable
    | routineExpr
    | string
    | atom;

binaryExpr: atom NEWLINE? binaryOp NEWLINE? atom;
binaryOp
    : AS                              # asOp
    | PLUS_PLUS                       # concatOp
    | ASTERISK_ASTERISK               # repeatOp
    | PLUS                            # addOp
    | MINUS                           # subOp
    | ASTERISK                        # timesOp
    | SLASH                           # divideOp
    | LESSTHAN                        # lessThanOp
    | GREATERTHAN                     # greaterThanOp
    | LESSTHAN_EQUAL                  # lessThanOrEqualToOp
    | GREATERTHAN_EQUAL               # greaterThanOrEqualToOp
    | PLUS_PERCENT                    # wrappingAddOp
    | MINUS_PERCENT                   # wrappingSubOp
    | ASTERISK_PERCENT                # wrappingTimesOp
    | LESSTHAN_LESSTHAN               # leftShiftOp
    | GREATERTHAN_GREATERTHAN         # rightShiftOp
    | LESSTHAN_LESSTHAN_PERCENT       # leftRotateOp
    | GREATERTHAN_GREATERTHAN_PERCENT # rightRotateOp
    | EQUAL_EQUAL                     # equalityOp
    | TILDE_EQUAL                     # inequalityOp
    | AMPERSAND                       # andOp
    | PIPE                            # orOp
    | PERCENT                         # modOp
    | CARROT                          # xorOp;

postExpr: atom postOp;
postOp
    : DOT atom                                         # accessMemberOp
    | OPENBRACKET NEWLINE? expr NEWLINE? CLOSEDBRACKET # accessIndexOp
    | DOT TYPE                                         # accessTypeOp
    | DOT LEN                                          # accessLengthOp
    | DOT ASTERISK                                     # dereferencePointerOp
    | DOT AMPERSAND                                    # addressOfOp
    | QUESTION                                         # unwrapOptionalOp
    | EXCLAMATION                                      # tryOp;

preExpr: preOp atom;
preOp:   TILDE # notOp | MINUS # negateOp;

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
    : atom structExpr blockStmt        # plainRoutineExpr
    | INLINE atom structExpr blockStmt # inlineRoutineExpr;

string: DOUBLEQUOTESTRING # dQStringExpr | BACKTICKSTRING # bTStringExpr;

atom: token | tupleExpr | blockExpr | structExpr;

token: TOKEN;

tupleExpr: oParen (expr (exprSep expr)*)? cParen;

blockExpr: oParen ((stmt (stmtSep stmt)* stmtSep)? expr)? cParen;

structExpr: oBrace (field (exprSep field)*)? cBrace;

// NL? ID NL?; NL? ID
oParen: NEWLINE? OPENPARENTHESIS NEWLINE?;
cParen: NEWLINE? CLOSEDPARENTHESIS;
oBrace: NEWLINE? OPENBRACE NEWLINE?;
cBrace: NEWLINE? CLOSEDBRACE;