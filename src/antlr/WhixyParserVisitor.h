
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"
#include "WhixyParser.h"

namespace Whixy {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by WhixyParser.
 */
class WhixyParserVisitor: public antlr4::tree::AbstractParseTreeVisitor {
  public:
    /**
   * Visit parse trees produced by WhixyParser.
   */
    virtual std::any visitSrcFile(WhixyParser::SrcFileContext* context) = 0;

    virtual std::any visitStmt(WhixyParser::StmtContext* context) = 0;

    virtual std::any visitValsStmt(WhixyParser::ValsStmtContext* context) = 0;

    virtual std::any visitCallStmt(WhixyParser::CallStmtContext* context) = 0;

    virtual std::any visitBlockStmt(WhixyParser::BlockStmtContext* context) = 0;

    virtual std::any visitReturnStmt(WhixyParser::ReturnStmtContext* context) = 0;

    virtual std::any visitFuncStmt(WhixyParser::FuncStmtContext* context) = 0;

    virtual std::any visitProcStmt(WhixyParser::ProcStmtContext* context) = 0;

    virtual std::any visitIfStmt(WhixyParser::IfStmtContext* context) = 0;

    virtual std::any visitIsStmt(WhixyParser::IsStmtContext* context) = 0;

    virtual std::any visitMatchStmt(WhixyParser::MatchStmtContext* context) = 0;

    virtual std::any visitWhileStmt(WhixyParser::WhileStmtContext* context) = 0;

    virtual std::any visitForStmt(WhixyParser::ForStmtContext* context) = 0;

    virtual std::any visitComptStmt(WhixyParser::ComptStmtContext* context) = 0;

    virtual std::any visitDeferStmt(WhixyParser::DeferStmtContext* context) = 0;

    virtual std::any visitErrdeferStmt(WhixyParser::ErrdeferStmtContext* context) = 0;

    virtual std::any visitExpr(WhixyParser::ExprContext* context) = 0;

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* context) = 0;

    virtual std::any visitIsExpr(WhixyParser::IsExprContext* context) = 0;

    virtual std::any visitMatchExpr(WhixyParser::MatchExprContext* context) = 0;

    virtual std::any visitFuncExpr(WhixyParser::FuncExprContext* context) = 0;

    virtual std::any visitProcExpr(WhixyParser::ProcExprContext* context) = 0;

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* context) = 0;

    virtual std::any visitDQStringExpr(WhixyParser::DQStringExprContext* context) = 0;

    virtual std::any visitBTStringExpr(WhixyParser::BTStringExprContext* context) = 0;

    virtual std::any visitAtom(WhixyParser::AtomContext* context) = 0;

    virtual std::any visitBlockExpr(WhixyParser::BlockExprContext* context) = 0;

    virtual std::any visitTypeExpr(WhixyParser::TypeExprContext* context) = 0;

    virtual std::any visitTupleExpr(WhixyParser::TupleExprContext* context) = 0;

    virtual std::any visitToken(WhixyParser::TokenContext* context) = 0;

    virtual std::any visitEof(WhixyParser::EofContext* context) = 0;

    virtual std::any visitEqual(WhixyParser::EqualContext* context) = 0;

    virtual std::any visitOBracket(WhixyParser::OBracketContext* context) = 0;

    virtual std::any visitCBracket(WhixyParser::CBracketContext* context) = 0;

    virtual std::any visitOAngleBracket(WhixyParser::OAngleBracketContext* context) = 0;

    virtual std::any visitCAngleBracket(WhixyParser::CAngleBracketContext* context) = 0;

    virtual std::any visitOParen(WhixyParser::OParenContext* context) = 0;

    virtual std::any visitCParen(WhixyParser::CParenContext* context) = 0;

    virtual std::any visitOBrace(WhixyParser::OBraceContext* context) = 0;

    virtual std::any visitCBrace(WhixyParser::CBraceContext* context) = 0;

    virtual std::any visitGtGtPercentEq(WhixyParser::GtGtPercentEqContext* context) = 0;

    virtual std::any visitGtGtPercent(WhixyParser::GtGtPercentContext* context) = 0;

    virtual std::any visitGtGtEq(WhixyParser::GtGtEqContext* context) = 0;

    virtual std::any visitGtGt(WhixyParser::GtGtContext* context) = 0;

    virtual std::any visitGtEq(WhixyParser::GtEqContext* context) = 0;

    virtual std::any visitGt(WhixyParser::GtContext* context) = 0;

    virtual std::any visitLtLtPercentEq(WhixyParser::LtLtPercentEqContext* context) = 0;

    virtual std::any visitLtLtPercent(WhixyParser::LtLtPercentContext* context) = 0;

    virtual std::any visitLtLtEq(WhixyParser::LtLtEqContext* context) = 0;

    virtual std::any visitLtLt(WhixyParser::LtLtContext* context) = 0;

    virtual std::any visitLtEq(WhixyParser::LtEqContext* context) = 0;

    virtual std::any visitLt(WhixyParser::LtContext* context) = 0;

    virtual std::any visitStarPercentEq(WhixyParser::StarPercentEqContext* context) = 0;

    virtual std::any visitStarPercent(WhixyParser::StarPercentContext* context) = 0;

    virtual std::any visitStarEq(WhixyParser::StarEqContext* context) = 0;

    virtual std::any visitStarStar(WhixyParser::StarStarContext* context) = 0;

    virtual std::any visitStar(WhixyParser::StarContext* context) = 0;

    virtual std::any visitPlusPercentEq(WhixyParser::PlusPercentEqContext* context) = 0;

    virtual std::any visitPlusPercent(WhixyParser::PlusPercentContext* context) = 0;

    virtual std::any visitPlusEq(WhixyParser::PlusEqContext* context) = 0;

    virtual std::any visitPlusPlus(WhixyParser::PlusPlusContext* context) = 0;

    virtual std::any visitPlus(WhixyParser::PlusContext* context) = 0;

    virtual std::any visitMinusPercentEq(WhixyParser::MinusPercentEqContext* context) = 0;

    virtual std::any visitMinusPercent(WhixyParser::MinusPercentContext* context) = 0;

    virtual std::any visitMinusEq(WhixyParser::MinusEqContext* context) = 0;

    virtual std::any visitMinus(WhixyParser::MinusContext* context) = 0;

    virtual std::any visitExclamationEq(WhixyParser::ExclamationEqContext* context) = 0;

    virtual std::any visitExclamation(WhixyParser::ExclamationContext* context) = 0;

    virtual std::any visitAmpersandEq(WhixyParser::AmpersandEqContext* context) = 0;

    virtual std::any visitAmpersand(WhixyParser::AmpersandContext* context) = 0;

    virtual std::any visitPercentEq(WhixyParser::PercentEqContext* context) = 0;

    virtual std::any visitPercent(WhixyParser::PercentContext* context) = 0;

    virtual std::any visitCarrotEq(WhixyParser::CarrotEqContext* context) = 0;

    virtual std::any visitCarrot(WhixyParser::CarrotContext* context) = 0;

    virtual std::any visitSlashEq(WhixyParser::SlashEqContext* context) = 0;

    virtual std::any visitSlash(WhixyParser::SlashContext* context) = 0;

    virtual std::any visitEqualEq(WhixyParser::EqualEqContext* context) = 0;

    virtual std::any visitPipeEq(WhixyParser::PipeEqContext* context) = 0;

    virtual std::any visitPipe(WhixyParser::PipeContext* context) = 0;

    virtual std::any visitAs(WhixyParser::AsContext* context) = 0;

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* context) = 0;

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* context) = 0;
};

} // namespace Whixy
