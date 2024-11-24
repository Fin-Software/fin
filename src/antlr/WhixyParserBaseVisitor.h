
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"
#include "WhixyParserVisitor.h"

namespace Whixy {

/**
 * This class provides an empty implementation of WhixyParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class WhixyParserBaseVisitor: public WhixyParserVisitor {
  public:
    virtual std::any visitSrcFile(WhixyParser::SrcFileContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStmt(WhixyParser::StmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitValsStmt(WhixyParser::ValsStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCallStmt(WhixyParser::CallStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBlockStmt(WhixyParser::BlockStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitReturnStmt(WhixyParser::ReturnStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitFuncStmt(WhixyParser::FuncStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitProcStmt(WhixyParser::ProcStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIfStmt(WhixyParser::IfStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIsStmt(WhixyParser::IsStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMatchStmt(WhixyParser::MatchStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWhileStmt(WhixyParser::WhileStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitForStmt(WhixyParser::ForStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitComptStmt(WhixyParser::ComptStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDeferStmt(WhixyParser::DeferStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitErrdeferStmt(WhixyParser::ErrdeferStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExpr(WhixyParser::ExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIsExpr(WhixyParser::IsExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMatchExpr(WhixyParser::MatchExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWhileExpr(WhixyParser::WhileExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitForExpr(WhixyParser::ForExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitFuncExpr(WhixyParser::FuncExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitProcExpr(WhixyParser::ProcExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDQStringExpr(WhixyParser::DQStringExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBTStringExpr(WhixyParser::BTStringExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAtom(WhixyParser::AtomContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBlockExpr(WhixyParser::BlockExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTypeExpr(WhixyParser::TypeExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTupleExpr(WhixyParser::TupleExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitToken(WhixyParser::TokenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitEof(WhixyParser::EofContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitEqual(WhixyParser::EqualContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOBracket(WhixyParser::OBracketContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCBracket(WhixyParser::CBracketContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOAngleBracket(WhixyParser::OAngleBracketContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCAngleBracket(WhixyParser::CAngleBracketContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOParen(WhixyParser::OParenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCParen(WhixyParser::CParenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOBrace(WhixyParser::OBraceContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCBrace(WhixyParser::CBraceContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGtGtPercentEq(WhixyParser::GtGtPercentEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGtGtPercent(WhixyParser::GtGtPercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGtGtEq(WhixyParser::GtGtEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGtGt(WhixyParser::GtGtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGtEq(WhixyParser::GtEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGt(WhixyParser::GtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLtLtPercentEq(WhixyParser::LtLtPercentEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLtLtPercent(WhixyParser::LtLtPercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLtLtEq(WhixyParser::LtLtEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLtLt(WhixyParser::LtLtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLtEq(WhixyParser::LtEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLt(WhixyParser::LtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStarPercentEq(WhixyParser::StarPercentEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStarPercent(WhixyParser::StarPercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStarEq(WhixyParser::StarEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStarStar(WhixyParser::StarStarContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStar(WhixyParser::StarContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlusPercentEq(WhixyParser::PlusPercentEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlusPercent(WhixyParser::PlusPercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlusEq(WhixyParser::PlusEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlusPlus(WhixyParser::PlusPlusContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlus(WhixyParser::PlusContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMinusPercentEq(WhixyParser::MinusPercentEqContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitMinusPercent(WhixyParser::MinusPercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMinusEq(WhixyParser::MinusEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMinus(WhixyParser::MinusContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExclamationEq(WhixyParser::ExclamationEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExclamation(WhixyParser::ExclamationContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAmpersandEq(WhixyParser::AmpersandEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAmpersand(WhixyParser::AmpersandContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPercentEq(WhixyParser::PercentEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPercent(WhixyParser::PercentContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCarrotEq(WhixyParser::CarrotEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCarrot(WhixyParser::CarrotContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitSlashEq(WhixyParser::SlashEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitSlash(WhixyParser::SlashContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitEqualEq(WhixyParser::EqualEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPipeEq(WhixyParser::PipeEqContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPipe(WhixyParser::PipeContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAs(WhixyParser::AsContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* ctx) override { return visitChildren(ctx); }
};

} // namespace Whixy
