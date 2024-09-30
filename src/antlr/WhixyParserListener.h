
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "WhixyParser.h"


namespace Whixy {

/**
 * This interface defines an abstract listener for a parse tree produced by WhixyParser.
 */
class  WhixyParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSrcFile(WhixyParser::SrcFileContext *ctx) = 0;
  virtual void exitSrcFile(WhixyParser::SrcFileContext *ctx) = 0;

  virtual void enterStatement(WhixyParser::StatementContext *ctx) = 0;
  virtual void exitStatement(WhixyParser::StatementContext *ctx) = 0;

  virtual void enterValStmt(WhixyParser::ValStmtContext *ctx) = 0;
  virtual void exitValStmt(WhixyParser::ValStmtContext *ctx) = 0;

  virtual void enterExpression(WhixyParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(WhixyParser::ExpressionContext *ctx) = 0;

  virtual void enterBlockExpr(WhixyParser::BlockExprContext *ctx) = 0;
  virtual void exitBlockExpr(WhixyParser::BlockExprContext *ctx) = 0;

  virtual void enterValsExpr(WhixyParser::ValsExprContext *ctx) = 0;
  virtual void exitValsExpr(WhixyParser::ValsExprContext *ctx) = 0;

  virtual void enterProcedureExpr(WhixyParser::ProcedureExprContext *ctx) = 0;
  virtual void exitProcedureExpr(WhixyParser::ProcedureExprContext *ctx) = 0;

  virtual void enterFunctionExpr(WhixyParser::FunctionExprContext *ctx) = 0;
  virtual void exitFunctionExpr(WhixyParser::FunctionExprContext *ctx) = 0;

  virtual void enterTypeExpr(WhixyParser::TypeExprContext *ctx) = 0;
  virtual void exitTypeExpr(WhixyParser::TypeExprContext *ctx) = 0;

  virtual void enterTupleExpr(WhixyParser::TupleExprContext *ctx) = 0;
  virtual void exitTupleExpr(WhixyParser::TupleExprContext *ctx) = 0;

  virtual void enterCallExpr(WhixyParser::CallExprContext *ctx) = 0;
  virtual void exitCallExpr(WhixyParser::CallExprContext *ctx) = 0;

  virtual void enterEndOfExp(WhixyParser::EndOfExpContext *ctx) = 0;
  virtual void exitEndOfExp(WhixyParser::EndOfExpContext *ctx) = 0;

  virtual void enterEndOfStmt(WhixyParser::EndOfStmtContext *ctx) = 0;
  virtual void exitEndOfStmt(WhixyParser::EndOfStmtContext *ctx) = 0;


};

}  // namespace Whixy
