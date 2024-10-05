// SPDX-License-Identifier: Apache-2.0
// Copyright © 2024 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

parser grammar WhixyParser; // $antlr-format off
options { tokenVocab = WhixyLexer; }

srcFile: stmt+;

stmt:
	VAL valsExpr stmtSep  #valStmt
	| RETURN expr stmtSep #returnStmt
	| blockExpr stmtSep   #blockStmt
	| callExpr stmtSep    #callStmt;

expr: callExpr | valsExpr | blockExpr | tupleExpr | typeExpr | routineExpr | unaryExpr | binaryExpr | literalExpr;

callExpr: expr (ID | tupleExpr);
valsExpr: ID+ (COLON expr)? (EQ expr)?;
blockExpr: OBRACE (stmt (stmtSep stmt)* stmtSep?)? CBRACE;
tupleExpr: OPAREN (expr (exprSep expr)* exprSep?)? CPAREN;
typeExpr: OBRACE (valsExpr (exprSep valsExpr)* exprSep?)? CBRACE;

routineExpr:
	FUNC typeExpr expr blockExpr   #functionExpr
	| PROC typeExpr expr blockExpr #procedureExpr;

unaryExpr:
	OPAREN expr CPAREN  #parentheticExpr
	| EXCLAMATION expr  #notExpr
	| MINUS expr        #negationExpr
	| AMPERSAND expr    #addressOfExpr
	| expr DOT ASTERISK #dereferencingMethodExpr
	| expr DOT TYPE     #typeOfMethodExpr
	| expr DOT LEN      #lengthOfMethodExpr;

binaryExpr:
	expr AS expr                 #asExpr
	| expr PLUSPLUS expr         #concatenationExpr
	| expr ASTERISKASTERISK expr #repititionExpr
	| expr PLUS expr             #additionExpr
	| expr MINUS expr            #subtractionExpr
	| expr ASTERISK expr         #multiplicationExpr
	| expr FSLASH expr           #divisionExpr
	| expr LTLT expr             #leftShiftingExpr
	| expr GTGT expr             #rightShiftingExpr
	| expr PERCENTPLUS expr      #wrappingAdditionExpr
	| expr PERCENTMINUS expr     #wrappingSubtrationExpr
	| expr PERCENTASTERISK expr  #wrappingMultiplicationExpr
	| expr PERCENTLTLT expr      #leftRotationExpr
	| expr PERCENTGTGT expr      #rightRotationExpr;

literalExpr: ID | INTEGER | STRING;

stmtSep: SEMICOLON | NL; exprSep: COMMA | NL; 
