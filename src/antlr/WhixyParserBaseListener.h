
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "WhixyParserListener.h"


namespace Whixy {

/**
 * This class provides an empty implementation of WhixyParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WhixyParserBaseListener : public WhixyParserListener {
public:

  virtual void enterSrcFile(WhixyParser::SrcFileContext * /*ctx*/) override { }
  virtual void exitSrcFile(WhixyParser::SrcFileContext * /*ctx*/) override { }

  virtual void enterStatement(WhixyParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(WhixyParser::StatementContext * /*ctx*/) override { }

  virtual void enterValStmt(WhixyParser::ValStmtContext * /*ctx*/) override { }
  virtual void exitValStmt(WhixyParser::ValStmtContext * /*ctx*/) override { }

  virtual void enterExpression(WhixyParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(WhixyParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterBlockExpr(WhixyParser::BlockExprContext * /*ctx*/) override { }
  virtual void exitBlockExpr(WhixyParser::BlockExprContext * /*ctx*/) override { }

  virtual void enterValsExpr(WhixyParser::ValsExprContext * /*ctx*/) override { }
  virtual void exitValsExpr(WhixyParser::ValsExprContext * /*ctx*/) override { }

  virtual void enterProcedureExpr(WhixyParser::ProcedureExprContext * /*ctx*/) override { }
  virtual void exitProcedureExpr(WhixyParser::ProcedureExprContext * /*ctx*/) override { }

  virtual void enterFunctionExpr(WhixyParser::FunctionExprContext * /*ctx*/) override { }
  virtual void exitFunctionExpr(WhixyParser::FunctionExprContext * /*ctx*/) override { }

  virtual void enterTypeExpr(WhixyParser::TypeExprContext * /*ctx*/) override { }
  virtual void exitTypeExpr(WhixyParser::TypeExprContext * /*ctx*/) override { }

  virtual void enterTupleExpr(WhixyParser::TupleExprContext * /*ctx*/) override { }
  virtual void exitTupleExpr(WhixyParser::TupleExprContext * /*ctx*/) override { }

  virtual void enterCallExpr(WhixyParser::CallExprContext * /*ctx*/) override { }
  virtual void exitCallExpr(WhixyParser::CallExprContext * /*ctx*/) override { }

  virtual void enterEndOfExp(WhixyParser::EndOfExpContext * /*ctx*/) override { }
  virtual void exitEndOfExp(WhixyParser::EndOfExpContext * /*ctx*/) override { }

  virtual void enterEndOfStmt(WhixyParser::EndOfStmtContext * /*ctx*/) override { }
  virtual void exitEndOfStmt(WhixyParser::EndOfStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace Whixy
