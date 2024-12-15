
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

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStmt(WhixyParser::StmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitField(WhixyParser::FieldContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitMutable(WhixyParser::MutableContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitVolatile(WhixyParser::VolatileContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitThreadlocal(WhixyParser::ThreadlocalContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAssignStmt(WhixyParser::AssignStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAndEqualsOp(WhixyParser::AndEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOrEqualsOp(WhixyParser::OrEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitModEqualsOp(WhixyParser::ModEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitXorEqualsOp(WhixyParser::XorEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDivideEqualsOp(WhixyParser::DivideEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitAddEqualsOp(WhixyParser::AddEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitSubEqualsOp(WhixyParser::SubEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTimesEqualsOp(WhixyParser::TimesEqualsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitCall(WhixyParser::CallContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitFuncBlockStmt(WhixyParser::FuncBlockStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitProcBlockStmt(WhixyParser::ProcBlockStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitReturnStmt(WhixyParser::ReturnStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIfStmt(WhixyParser::IfStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWhereStmt(WhixyParser::WhereStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitComparisonOp(WhixyParser::ComparisonOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCaseStmtBlock(WhixyParser::CaseStmtBlockContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitUnrollForStmt(WhixyParser::UnrollForStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlainWhileStmt(WhixyParser::PlainWhileStmtContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitPlainForStmt(WhixyParser::PlainForStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitComptStmt(WhixyParser::ComptStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitUnreachable(WhixyParser::UnreachableContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDeferStmt(WhixyParser::DeferStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitErrdeferStmt(WhixyParser::ErrdeferStmtContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitExpr(WhixyParser::ExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTypeExpr(WhixyParser::TypeExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBinaryExpr(WhixyParser::BinaryExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAsOp(WhixyParser::AsOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitConcatOp(WhixyParser::ConcatOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitRepeatOp(WhixyParser::RepeatOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAddOp(WhixyParser::AddOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitSubOp(WhixyParser::SubOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTimesOp(WhixyParser::TimesOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitDivideOp(WhixyParser::DivideOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLessThanOp(WhixyParser::LessThanOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitGreaterThanOp(WhixyParser::GreaterThanOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitWrappingAddOp(WhixyParser::WrappingAddOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWrappingSubOp(WhixyParser::WrappingSubOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWrappingTimesOp(WhixyParser::WrappingTimesOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitLeftShiftOp(WhixyParser::LeftShiftOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitRightShiftOp(WhixyParser::RightShiftOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLeftRotateOp(WhixyParser::LeftRotateOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitRightRotateOp(WhixyParser::RightRotateOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitEqualityOp(WhixyParser::EqualityOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitInequalityOp(WhixyParser::InequalityOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLogicalAndOp(WhixyParser::LogicalAndOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitLogicalOrOp(WhixyParser::LogicalOrOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBitwiseAndOp(WhixyParser::BitwiseAndOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBitwiseOrOp(WhixyParser::BitwiseOrOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitModOp(WhixyParser::ModOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitXorOp(WhixyParser::XorOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPostExpr(WhixyParser::PostExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAccessMemberOp(WhixyParser::AccessMemberOpContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitAccessIndexOp(WhixyParser::AccessIndexOpContext* ctx) override { return visitChildren(ctx); }

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

    virtual std::any visitTryOp(WhixyParser::TryOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPreExpr(WhixyParser::PreExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitNotOp(WhixyParser::NotOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitNegateOp(WhixyParser::NegateOpContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitWhereExpr(WhixyParser::WhereExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCaseExprBlock(WhixyParser::CaseExprBlockContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitPlainRoutineExpr(WhixyParser::PlainRoutineExprContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitInlineRoutineExpr(WhixyParser::InlineRoutineExprContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual std::any visitDQString(WhixyParser::DQStringContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBSString(WhixyParser::BSStringContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBTString(WhixyParser::BTStringContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitAtom(WhixyParser::AtomContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitToken(WhixyParser::TokenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitTupleExpr(WhixyParser::TupleExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitBlockExpr(WhixyParser::BlockExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitStructExpr(WhixyParser::StructExprContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOParen(WhixyParser::OParenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCParen(WhixyParser::CParenContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitOBrace(WhixyParser::OBraceContext* ctx) override { return visitChildren(ctx); }

    virtual std::any visitCBrace(WhixyParser::CBraceContext* ctx) override { return visitChildren(ctx); }
};

} // namespace Whixy
