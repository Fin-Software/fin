
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

    virtual std::any visitAssignOpStmt(WhixyParser::AssignOpStmtContext* context) = 0;

    virtual std::any visitAndAssignOp(WhixyParser::AndAssignOpContext* context) = 0;

    virtual std::any visitOrAssignOp(WhixyParser::OrAssignOpContext* context) = 0;

    virtual std::any visitModulusAssignOp(WhixyParser::ModulusAssignOpContext* context) = 0;

    virtual std::any visitXorAssignOp(WhixyParser::XorAssignOpContext* context) = 0;

    virtual std::any visitDivisionAssignOp(WhixyParser::DivisionAssignOpContext* context) = 0;

    virtual std::any visitAdditionAssignOp(WhixyParser::AdditionAssignOpContext* context) = 0;

    virtual std::any visitSubtractionAssignOp(WhixyParser::SubtractionAssignOpContext* context) = 0;

    virtual std::any visitMultiplicationAssignOp(WhixyParser::MultiplicationAssignOpContext* context) = 0;

    virtual std::any visitLeftShiftAssignOp(WhixyParser::LeftShiftAssignOpContext* context) = 0;

    virtual std::any visitRightShiftAssignOp(WhixyParser::RightShiftAssignOpContext* context) = 0;

    virtual std::any visitWrappingMultiplicationAssignOp(WhixyParser::WrappingMultiplicationAssignOpContext* context
    ) = 0;

    virtual std::any visitWrappingAdditionAssignOp(WhixyParser::WrappingAdditionAssignOpContext* context) = 0;

    virtual std::any visitWrappingSubtractionAssignOp(WhixyParser::WrappingSubtractionAssignOpContext* context) = 0;

    virtual std::any visitRightRotationAssignOp(WhixyParser::RightRotationAssignOpContext* context) = 0;

    virtual std::any visitLeftRotationAssignOp(WhixyParser::LeftRotationAssignOpContext* context) = 0;

    virtual std::any visitCallStmt(WhixyParser::CallStmtContext* context) = 0;

    virtual std::any visitFuncBlockStmt(WhixyParser::FuncBlockStmtContext* context) = 0;

    virtual std::any visitProcBlockStmt(WhixyParser::ProcBlockStmtContext* context) = 0;

    virtual std::any visitPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* context) = 0;

    virtual std::any visitInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* context) = 0;

    virtual std::any visitReturnStmt(WhixyParser::ReturnStmtContext* context) = 0;

    virtual std::any visitIfStmt(WhixyParser::IfStmtContext* context) = 0;

    virtual std::any visitWhereStmt(WhixyParser::WhereStmtContext* context) = 0;

    virtual std::any visitComparisonOp(WhixyParser::ComparisonOpContext* context) = 0;

    virtual std::any visitCaseStmtBlock(WhixyParser::CaseStmtBlockContext* context) = 0;

    virtual std::any visitMatchStmt(WhixyParser::MatchStmtContext* context) = 0;

    virtual std::any visitUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* context) = 0;

    virtual std::any visitUnrollForStmt(WhixyParser::UnrollForStmtContext* context) = 0;

    virtual std::any visitPlainWhileStmt(WhixyParser::PlainWhileStmtContext* context) = 0;

    virtual std::any visitPlainForStmt(WhixyParser::PlainForStmtContext* context) = 0;

    virtual std::any visitComptStmt(WhixyParser::ComptStmtContext* context) = 0;

    virtual std::any visitDeferStmt(WhixyParser::DeferStmtContext* context) = 0;

    virtual std::any visitErrdeferStmt(WhixyParser::ErrdeferStmtContext* context) = 0;

    virtual std::any visitExpr(WhixyParser::ExprContext* context) = 0;

    virtual std::any visitBinaryOpExpr(WhixyParser::BinaryOpExprContext* context) = 0;

    virtual std::any visitAsOp(WhixyParser::AsOpContext* context) = 0;

    virtual std::any visitConcatenationOp(WhixyParser::ConcatenationOpContext* context) = 0;

    virtual std::any visitRepetitionOp(WhixyParser::RepetitionOpContext* context) = 0;

    virtual std::any visitAdditionOp(WhixyParser::AdditionOpContext* context) = 0;

    virtual std::any visitSubtractionOp(WhixyParser::SubtractionOpContext* context) = 0;

    virtual std::any visitMultiplicationOp(WhixyParser::MultiplicationOpContext* context) = 0;

    virtual std::any visitDivisionOp(WhixyParser::DivisionOpContext* context) = 0;

    virtual std::any visitLessThanOp(WhixyParser::LessThanOpContext* context) = 0;

    virtual std::any visitGreaterThanOp(WhixyParser::GreaterThanOpContext* context) = 0;

    virtual std::any visitLessThanEqualOp(WhixyParser::LessThanEqualOpContext* context) = 0;

    virtual std::any visitGreaterThanEqualOp(WhixyParser::GreaterThanEqualOpContext* context) = 0;

    virtual std::any visitWrappingAdditionOp(WhixyParser::WrappingAdditionOpContext* context) = 0;

    virtual std::any visitWrappingSubtractionOp(WhixyParser::WrappingSubtractionOpContext* context) = 0;

    virtual std::any visitWrappingMultiplicationOp(WhixyParser::WrappingMultiplicationOpContext* context) = 0;

    virtual std::any visitLeftShiftOp(WhixyParser::LeftShiftOpContext* context) = 0;

    virtual std::any visitRightShiftOp(WhixyParser::RightShiftOpContext* context) = 0;

    virtual std::any visitLeftRotationOp(WhixyParser::LeftRotationOpContext* context) = 0;

    virtual std::any visitRightRotationOp(WhixyParser::RightRotationOpContext* context) = 0;

    virtual std::any visitEqualityOp(WhixyParser::EqualityOpContext* context) = 0;

    virtual std::any visitInequalityOp(WhixyParser::InequalityOpContext* context) = 0;

    virtual std::any visitAndOp(WhixyParser::AndOpContext* context) = 0;

    virtual std::any visitOrOp(WhixyParser::OrOpContext* context) = 0;

    virtual std::any visitModulusOp(WhixyParser::ModulusOpContext* context) = 0;

    virtual std::any visitXorOp(WhixyParser::XorOpContext* context) = 0;

    virtual std::any visitPostOpExpr(WhixyParser::PostOpExprContext* context) = 0;

    virtual std::any visitAccessFieldOp(WhixyParser::AccessFieldOpContext* context) = 0;

    virtual std::any visitAccessTypeOp(WhixyParser::AccessTypeOpContext* context) = 0;

    virtual std::any visitAccessLengthOp(WhixyParser::AccessLengthOpContext* context) = 0;

    virtual std::any visitDereferencePointerOp(WhixyParser::DereferencePointerOpContext* context) = 0;

    virtual std::any visitAddressOfOp(WhixyParser::AddressOfOpContext* context) = 0;

    virtual std::any visitUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* context) = 0;

    virtual std::any visitPreOpExpr(WhixyParser::PreOpExprContext* context) = 0;

    virtual std::any visitNotOp(WhixyParser::NotOpContext* context) = 0;

    virtual std::any visitNegateOp(WhixyParser::NegateOpContext* context) = 0;

    virtual std::any visitIfExpr(WhixyParser::IfExprContext* context) = 0;

    virtual std::any visitWhereExpr(WhixyParser::WhereExprContext* context) = 0;

    virtual std::any visitCaseExprBlock(WhixyParser::CaseExprBlockContext* context) = 0;

    virtual std::any visitMatchExpr(WhixyParser::MatchExprContext* context) = 0;

    virtual std::any visitLoopExpr(WhixyParser::LoopExprContext* context) = 0;

    virtual std::any visitComptExpr(WhixyParser::ComptExprContext* context) = 0;

    virtual std::any visitRoutineExpr(WhixyParser::RoutineExprContext* context) = 0;

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

    virtual std::any visitDollarParen(WhixyParser::DollarParenContext* context) = 0;

    virtual std::any visitOParen(WhixyParser::OParenContext* context) = 0;

    virtual std::any visitCParen(WhixyParser::CParenContext* context) = 0;

    virtual std::any visitOBrace(WhixyParser::OBraceContext* context) = 0;

    virtual std::any visitCBrace(WhixyParser::CBraceContext* context) = 0;

    virtual std::any visitStmtSep(WhixyParser::StmtSepContext* context) = 0;

    virtual std::any visitExprSep(WhixyParser::ExprSepContext* context) = 0;
};

} // namespace Whixy
