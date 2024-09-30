parser grammar WhixyParser; // $antlr-format off
options { tokenVocab = WhixyLexer; }

srcFile: statement+;

statement: valStmt | blockExpr;

valStmt: VAL valsExpr endOfStmt;

expression: blockExpr | valsExpr | procedureExpr | functionExpr | typeExpr | tupleExpr | callExpr;

blockExpr: OBRACE ((statement endOfStmt)* statement endOfStmt?)? CBRACE;
valsExpr: ID+ (COLON expression)? (EQ expression)?;
procedureExpr: PROC typeExpr expression blockExpr;
functionExpr: FUNC typeExpr expression blockExpr;
typeExpr: OBRACE ((valsExpr endOfExp)* valsExpr endOfExp?)? CBRACE;
tupleExpr: OPAREN ((expression endOfExp)* expression endOfExp?)? CPAREN;
callExpr: ID tupleExpr;

endOfExp: EXP_SEP | NL; endOfStmt: STMT_SEP | NL;
