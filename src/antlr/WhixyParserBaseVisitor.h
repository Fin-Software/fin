
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

    virtual std::any visitAccessExpr(WhixyParser::AccessExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIsExpr(WhixyParser::IsExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMatchExpr(WhixyParser::MatchExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWhileExpr(WhixyParser::WhileExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitForExpr(WhixyParser::ForExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitFuncExpr(WhixyParser::FuncExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitProcExpr(WhixyParser::ProcExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBinaryOpExpr(WhixyParser::BinaryOpExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAsOp(WhixyParser::AsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitConcatenationOp(WhixyParser::ConcatenationOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRepetitionOp(WhixyParser::RepetitionOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAdditionOp(WhixyParser::AdditionOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitSubtractionOp(WhixyParser::SubtractionOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMultiplicationOp(WhixyParser::MultiplicationOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitDivisionOp(WhixyParser::DivisionOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLessThanOp(WhixyParser::LessThanOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGreaterThanOp(WhixyParser::GreaterThanOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLessThanEqualOp(WhixyParser::LessThanEqualOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitGreaterThanEqualOp(WhixyParser::GreaterThanEqualOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingAdditionOp(WhixyParser::WrappingAdditionOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingSubtractionOp(WhixyParser::WrappingSubtractionOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingMultiplicationOp(WhixyParser::WrappingMultiplicationOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitLeftShiftOp(WhixyParser::LeftShiftOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitRightShiftOp(WhixyParser::RightShiftOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLeftRotationOp(WhixyParser::LeftRotationOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRightRotationOp(WhixyParser::RightRotationOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitEqualityOp(WhixyParser::EqualityOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitInequalityOp(WhixyParser::InequalityOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAndOp(WhixyParser::AndOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAndAssignOp(WhixyParser::AndAssignOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOrOp(WhixyParser::OrOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOrAssignOp(WhixyParser::OrAssignOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitModulusOp(WhixyParser::ModulusOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitModulusAssignOp(WhixyParser::ModulusAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitXorOp(WhixyParser::XorOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitXorAssignOp(WhixyParser::XorAssignOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDivisionAssignOp(WhixyParser::DivisionAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitAdditionAssignOp(WhixyParser::AdditionAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitSubtractionAssignOp(WhixyParser::SubtractionAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitMultiplicationAssignOp(WhixyParser::MultiplicationAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitLeftShiftAssignOp(WhixyParser::LeftShiftAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRightShiftAssignOp(WhixyParser::RightShiftAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingMultiplicationAssignOp(WhixyParser::WrappingMultiplicationAssignOpContext* ctx
    ) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingAdditionAssignOp(WhixyParser::WrappingAdditionAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingSubtractionAssignOp(WhixyParser::WrappingSubtractionAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRightRotationAssignOp(WhixyParser::RightRotationAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitLeftRotationAssignOp(WhixyParser::LeftRotationAssignOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPreOpExpr(WhixyParser::PreOpExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitNotOp(WhixyParser::NotOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitNegateOp(WhixyParser::NegateOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPostOpExpr(WhixyParser::PostOpExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAccessTypeOp(WhixyParser::AccessTypeOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAccessLengthOp(WhixyParser::AccessLengthOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitDereferencePointerOp(WhixyParser::DereferencePointerOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitAddressOfOp(WhixyParser::AddressOfOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

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

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* ctx) override { return visitChildren(ctx); }
};

} // namespace Whixy
