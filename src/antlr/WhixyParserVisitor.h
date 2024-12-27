
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

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* context) = 0;

    virtual std::any visitStmt(WhixyParser::StmtContext* context) = 0;

    virtual std::any visitField(WhixyParser::FieldContext* context) = 0;

    virtual std::any visitMutable(WhixyParser::MutableContext* context) = 0;

    virtual std::any visitVolatile(WhixyParser::VolatileContext* context) = 0;

    virtual std::any visitThreadl(WhixyParser::ThreadlContext* context) = 0;

    virtual std::any visitAssignStmt(WhixyParser::AssignStmtContext* context) = 0;

    virtual std::any visitAndEqualsOp(WhixyParser::AndEqualsOpContext* context) = 0;

    virtual std::any visitOrEqualsOp(WhixyParser::OrEqualsOpContext* context) = 0;

    virtual std::any visitModEqualsOp(WhixyParser::ModEqualsOpContext* context) = 0;

    virtual std::any visitXorEqualsOp(WhixyParser::XorEqualsOpContext* context) = 0;

    virtual std::any visitDivideEqualsOp(WhixyParser::DivideEqualsOpContext* context) = 0;

    virtual std::any visitAddEqualsOp(WhixyParser::AddEqualsOpContext* context) = 0;

    virtual std::any visitSubEqualsOp(WhixyParser::SubEqualsOpContext* context) = 0;

    virtual std::any visitTimesEqualsOp(WhixyParser::TimesEqualsOpContext* context) = 0;

    virtual std::any visitLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* context) = 0;

    virtual std::any visitRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* context) = 0;

    virtual std::any visitWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* context) = 0;

    virtual std::any visitWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* context) = 0;

    virtual std::any visitWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* context) = 0;

    virtual std::any visitRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* context) = 0;

    virtual std::any visitLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* context) = 0;

    virtual std::any visitCall(WhixyParser::CallContext* context) = 0;

    virtual std::any visitBlockStmt(WhixyParser::BlockStmtContext* context) = 0;

    virtual std::any visitDollarOParen(WhixyParser::DollarOParenContext* context) = 0;

    virtual std::any visitRoutineStmt(WhixyParser::RoutineStmtContext* context) = 0;

    virtual std::any visitInline(WhixyParser::InlineContext* context) = 0;

    virtual std::any visitFast(WhixyParser::FastContext* context) = 0;

    virtual std::any visitBare(WhixyParser::BareContext* context) = 0;

    virtual std::any visitReturnStmt(WhixyParser::ReturnStmtContext* context) = 0;

    virtual std::any visitIfStmt(WhixyParser::IfStmtContext* context) = 0;

    virtual std::any visitWhereStmt(WhixyParser::WhereStmtContext* context) = 0;

    virtual std::any visitComparisonOp(WhixyParser::ComparisonOpContext* context) = 0;

    virtual std::any visitCaseStmtBlock(WhixyParser::CaseStmtBlockContext* context) = 0;

    virtual std::any visitLoopStmt(WhixyParser::LoopStmtContext* context) = 0;

    virtual std::any visitUnroll(WhixyParser::UnrollContext* context) = 0;

    virtual std::any visitWhile(WhixyParser::WhileContext* context) = 0;

    virtual std::any visitFor(WhixyParser::ForContext* context) = 0;

    virtual std::any visitComptStmt(WhixyParser::ComptStmtContext* context) = 0;

    virtual std::any visitUnreachable(WhixyParser::UnreachableContext* context) = 0;

    virtual std::any visitDeferStmt(WhixyParser::DeferStmtContext* context) = 0;

    virtual std::any visitErrdeferStmt(WhixyParser::ErrdeferStmtContext* context) = 0;

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* context) = 0;

    virtual std::any visitExpr(WhixyParser::ExprContext* context) = 0;

    virtual std::any visitTypeExpr(WhixyParser::TypeExprContext* context) = 0;

    virtual std::any visitUnderscore(WhixyParser::UnderscoreContext* context) = 0;

    virtual std::any visitPointer(WhixyParser::PointerContext* context) = 0;

    virtual std::any visitThis(WhixyParser::ThisContext* context) = 0;

    virtual std::any visitBinaryExpr(WhixyParser::BinaryExprContext* context) = 0;

    virtual std::any visitAsOp(WhixyParser::AsOpContext* context) = 0;

    virtual std::any visitConcatOp(WhixyParser::ConcatOpContext* context) = 0;

    virtual std::any visitRepeatOp(WhixyParser::RepeatOpContext* context) = 0;

    virtual std::any visitAddOp(WhixyParser::AddOpContext* context) = 0;

    virtual std::any visitSubOp(WhixyParser::SubOpContext* context) = 0;

    virtual std::any visitTimesOp(WhixyParser::TimesOpContext* context) = 0;

    virtual std::any visitDivideOp(WhixyParser::DivideOpContext* context) = 0;

    virtual std::any visitLessThanOp(WhixyParser::LessThanOpContext* context) = 0;

    virtual std::any visitGreaterThanOp(WhixyParser::GreaterThanOpContext* context) = 0;

    virtual std::any visitLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* context) = 0;

    virtual std::any visitGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* context) = 0;

    virtual std::any visitWrappingAddOp(WhixyParser::WrappingAddOpContext* context) = 0;

    virtual std::any visitWrappingSubOp(WhixyParser::WrappingSubOpContext* context) = 0;

    virtual std::any visitWrappingTimesOp(WhixyParser::WrappingTimesOpContext* context) = 0;

    virtual std::any visitLeftShiftOp(WhixyParser::LeftShiftOpContext* context) = 0;

    virtual std::any visitRightShiftOp(WhixyParser::RightShiftOpContext* context) = 0;

    virtual std::any visitLeftRotateOp(WhixyParser::LeftRotateOpContext* context) = 0;

    virtual std::any visitRightRotateOp(WhixyParser::RightRotateOpContext* context) = 0;

    virtual std::any visitEqualityOp(WhixyParser::EqualityOpContext* context) = 0;

    virtual std::any visitInequalityOp(WhixyParser::InequalityOpContext* context) = 0;

    virtual std::any visitLogicalAndOp(WhixyParser::LogicalAndOpContext* context) = 0;

    virtual std::any visitLogicalOrOp(WhixyParser::LogicalOrOpContext* context) = 0;

    virtual std::any visitBitwiseAndOp(WhixyParser::BitwiseAndOpContext* context) = 0;

    virtual std::any visitBitwiseOrOp(WhixyParser::BitwiseOrOpContext* context) = 0;

    virtual std::any visitModOp(WhixyParser::ModOpContext* context) = 0;

    virtual std::any visitXorOp(WhixyParser::XorOpContext* context) = 0;

    virtual std::any visitPostExpr(WhixyParser::PostExprContext* context) = 0;

    virtual std::any visitAccessMemberOp(WhixyParser::AccessMemberOpContext* context) = 0;

    virtual std::any visitAccessIndexOp(WhixyParser::AccessIndexOpContext* context) = 0;

    virtual std::any visitAccessTypeOp(WhixyParser::AccessTypeOpContext* context) = 0;

    virtual std::any visitAccessLengthOp(WhixyParser::AccessLengthOpContext* context) = 0;

    virtual std::any visitDereferencePointerOp(WhixyParser::DereferencePointerOpContext* context) = 0;

    virtual std::any visitAddressOfOp(WhixyParser::AddressOfOpContext* context) = 0;

    virtual std::any visitUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* context) = 0;

    virtual std::any visitTryOp(WhixyParser::TryOpContext* context) = 0;

    virtual std::any visitPreExpr(WhixyParser::PreExprContext* context) = 0;

    virtual std::any visitNotOp(WhixyParser::NotOpContext* context) = 0;

    virtual std::any visitNegateOp(WhixyParser::NegateOpContext* context) = 0;

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* context) = 0;

    virtual std::any visitWhereExpr(WhixyParser::WhereExprContext* context) = 0;

    virtual std::any visitCaseExprBlock(WhixyParser::CaseExprBlockContext* context) = 0;

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* context) = 0;

    virtual std::any visitRoutineExpr(WhixyParser::RoutineExprContext* context) = 0;

    virtual std::any visitDQString(WhixyParser::DQStringContext* context) = 0;

    virtual std::any visitBSString(WhixyParser::BSStringContext* context) = 0;

    virtual std::any visitBTString(WhixyParser::BTStringContext* context) = 0;

    virtual std::any visitRune(WhixyParser::RuneContext* context) = 0;

    virtual std::any visitAtom(WhixyParser::AtomContext* context) = 0;

    virtual std::any visitToken(WhixyParser::TokenContext* context) = 0;

    virtual std::any visitTupleExpr(WhixyParser::TupleExprContext* context) = 0;

    virtual std::any visitBlockExpr(WhixyParser::BlockExprContext* context) = 0;

    virtual std::any visitStructExpr(WhixyParser::StructExprContext* context) = 0;

    virtual std::any visitOParen(WhixyParser::OParenContext* context) = 0;

    virtual std::any visitCParen(WhixyParser::CParenContext* context) = 0;

    virtual std::any visitOBrace(WhixyParser::OBraceContext* context) = 0;

    virtual std::any visitCBrace(WhixyParser::CBraceContext* context) = 0;
};

} // namespace Whixy
