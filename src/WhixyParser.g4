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

field: mutable? volatile? threadlocal? atom token+ (EQUAL NEWLINE? expr)?;
mutable: MUT;
volatile: VOLATILE;
threadlocal: THREADLOCAL;

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
    | LESSTHAN_LESSTHAN_PERCENT_EQUAL       # leftRotateEqualsOp; // TODO(@p7r0x7): Needs reordering.

call: atom (atom+ | expr);

blockStmt
    : oParen (stmt (stmtSep stmt)*)? cParen                                   # funcBlockStmt
    | NEWLINE? DOLLAR_OPENPARENTHESIS NEWLINE? (stmt (stmtSep stmt)*)? cParen # procBlockStmt;

routineStmt
    : typeExpr token structExpr blockStmt        # plainRoutineStmt
    | INLINE typeExpr token structExpr blockStmt # inlineRoutineStmt;

returnStmt: RETURN (atom+ | expr);

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
    | typeExpr
    | call
    | binaryExpr
    | postExpr
    | preExpr
    | ifExpr
    | whereExpr
    | comptExpr
    | unreachable
    | routineExpr
    | string
    | atom;

typeExpr: UNDERSCORE | ASTERISK? THIS | atom;

binaryExpr
    : atom NEWLINE? (
        asOp
        | (
            timesOp
            | divideOp
            | modOp
            | bitwiseAndOp
            | leftShiftOp
            | rightShiftOp
            | wrappingTimesOp
            | leftRotateOp
            | rightRotateOp
        )
        | (addOp | subOp | bitwiseOrOp | xorOp | wrappingAddOp | wrappingSubOp)
        | (
            equalityOp
            | inequalityOp
            | lessThanOp
            | greaterThanOp
            | lessThanOrEqualToOp
            | greaterThanOrEqualToOp
        )
        | logicalAndOp
        | logicalOrOp
    ) NEWLINE? atom;
asOp:                   AS;
concatOp:               PLUS_PLUS;
repeatOp:               ASTERISK_ASTERISK;
addOp:                  PLUS;
subOp:                  MINUS;
timesOp:                ASTERISK;
divideOp:               SLASH;
lessThanOp:             LESSTHAN;
greaterThanOp:          GREATERTHAN;
lessThanOrEqualToOp:    LESSTHAN_EQUAL;
greaterThanOrEqualToOp: GREATERTHAN_EQUAL;
wrappingAddOp:          PLUS_PERCENT;
wrappingSubOp:          MINUS_PERCENT;
wrappingTimesOp:        ASTERISK_PERCENT;
leftShiftOp:            LESSTHAN_LESSTHAN;
rightShiftOp:           GREATERTHAN_GREATERTHAN;
leftRotateOp:           LESSTHAN_LESSTHAN_PERCENT;
rightRotateOp:          GREATERTHAN_GREATERTHAN_PERCENT;
equalityOp:             EQUAL_EQUAL;
inequalityOp:           TILDE_EQUAL;
logicalAndOp:           AND;
logicalOrOp:            OR;
bitwiseAndOp:           AMPERSAND;
bitwiseOrOp:            PIPE;
modOp:                  PERCENT;
xorOp:                  CARROT;

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

comptExpr: COMPT expr;

routineExpr
    : atom structExpr blockStmt        # plainRoutineExpr
    | INLINE atom structExpr blockStmt # inlineRoutineExpr;

string: DOUBLEQUOTESTRING # dQString | BACKSLASHSTRING # bSString | BACKTICKSTRING # bTString;

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