
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"
#include "WhixyParser.h"

namespace Whixy {

/**
 * This interface defines an abstract listener for a parse tree produced by WhixyParser.
 */
class WhixyParserListener: public antlr4::tree::ParseTreeListener {
  public:
    virtual void enterSrcFile(WhixyParser::SrcFileContext* ctx) = 0;
    virtual void exitSrcFile(WhixyParser::SrcFileContext* ctx) = 0;

    virtual void enterStmtSep(WhixyParser::StmtSepContext* ctx) = 0;
    virtual void exitStmtSep(WhixyParser::StmtSepContext* ctx) = 0;

    virtual void enterStmt(WhixyParser::StmtContext* ctx) = 0;
    virtual void exitStmt(WhixyParser::StmtContext* ctx) = 0;

    virtual void enterImmutableVals(WhixyParser::ImmutableValsContext* ctx) = 0;
    virtual void exitImmutableVals(WhixyParser::ImmutableValsContext* ctx) = 0;

    virtual void enterMutableVals(WhixyParser::MutableValsContext* ctx) = 0;
    virtual void exitMutableVals(WhixyParser::MutableValsContext* ctx) = 0;

    virtual void enterAssignStmt(WhixyParser::AssignStmtContext* ctx) = 0;
    virtual void exitAssignStmt(WhixyParser::AssignStmtContext* ctx) = 0;

    virtual void enterAndEqualsOp(WhixyParser::AndEqualsOpContext* ctx) = 0;
    virtual void exitAndEqualsOp(WhixyParser::AndEqualsOpContext* ctx) = 0;

    virtual void enterOrEqualsOp(WhixyParser::OrEqualsOpContext* ctx) = 0;
    virtual void exitOrEqualsOp(WhixyParser::OrEqualsOpContext* ctx) = 0;

    virtual void enterModEqualsOp(WhixyParser::ModEqualsOpContext* ctx) = 0;
    virtual void exitModEqualsOp(WhixyParser::ModEqualsOpContext* ctx) = 0;

    virtual void enterXorEqualsOp(WhixyParser::XorEqualsOpContext* ctx) = 0;
    virtual void exitXorEqualsOp(WhixyParser::XorEqualsOpContext* ctx) = 0;

    virtual void enterDivideEqualsOp(WhixyParser::DivideEqualsOpContext* ctx) = 0;
    virtual void exitDivideEqualsOp(WhixyParser::DivideEqualsOpContext* ctx) = 0;

    virtual void enterAddEqualsOp(WhixyParser::AddEqualsOpContext* ctx) = 0;
    virtual void exitAddEqualsOp(WhixyParser::AddEqualsOpContext* ctx) = 0;

    virtual void enterSubEqualsOp(WhixyParser::SubEqualsOpContext* ctx) = 0;
    virtual void exitSubEqualsOp(WhixyParser::SubEqualsOpContext* ctx) = 0;

    virtual void enterTimesEqualsOp(WhixyParser::TimesEqualsOpContext* ctx) = 0;
    virtual void exitTimesEqualsOp(WhixyParser::TimesEqualsOpContext* ctx) = 0;

    virtual void enterLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* ctx) = 0;
    virtual void exitLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* ctx) = 0;

    virtual void enterRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* ctx) = 0;
    virtual void exitRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* ctx) = 0;

    virtual void enterWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* ctx) = 0;
    virtual void exitWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* ctx) = 0;

    virtual void enterWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* ctx) = 0;
    virtual void exitWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* ctx) = 0;

    virtual void enterWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* ctx) = 0;
    virtual void exitWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* ctx) = 0;

    virtual void enterRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* ctx) = 0;
    virtual void exitRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* ctx) = 0;

    virtual void enterLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* ctx) = 0;
    virtual void exitLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* ctx) = 0;

    virtual void enterCall(WhixyParser::CallContext* ctx) = 0;
    virtual void exitCall(WhixyParser::CallContext* ctx) = 0;

    virtual void enterFuncBlockStmt(WhixyParser::FuncBlockStmtContext* ctx) = 0;
    virtual void exitFuncBlockStmt(WhixyParser::FuncBlockStmtContext* ctx) = 0;

    virtual void enterProcBlockStmt(WhixyParser::ProcBlockStmtContext* ctx) = 0;
    virtual void exitProcBlockStmt(WhixyParser::ProcBlockStmtContext* ctx) = 0;

    virtual void enterPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* ctx) = 0;
    virtual void exitPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* ctx) = 0;

    virtual void enterInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* ctx) = 0;
    virtual void exitInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* ctx) = 0;

    virtual void enterReturnStmt(WhixyParser::ReturnStmtContext* ctx) = 0;
    virtual void exitReturnStmt(WhixyParser::ReturnStmtContext* ctx) = 0;

    virtual void enterIfStmt(WhixyParser::IfStmtContext* ctx) = 0;
    virtual void exitIfStmt(WhixyParser::IfStmtContext* ctx) = 0;

    virtual void enterWhereStmt(WhixyParser::WhereStmtContext* ctx) = 0;
    virtual void exitWhereStmt(WhixyParser::WhereStmtContext* ctx) = 0;

    virtual void enterComparisonOp(WhixyParser::ComparisonOpContext* ctx) = 0;
    virtual void exitComparisonOp(WhixyParser::ComparisonOpContext* ctx) = 0;

    virtual void enterCaseStmtBlock(WhixyParser::CaseStmtBlockContext* ctx) = 0;
    virtual void exitCaseStmtBlock(WhixyParser::CaseStmtBlockContext* ctx) = 0;

    virtual void enterUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* ctx) = 0;
    virtual void exitUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* ctx) = 0;

    virtual void enterUnrollForStmt(WhixyParser::UnrollForStmtContext* ctx) = 0;
    virtual void exitUnrollForStmt(WhixyParser::UnrollForStmtContext* ctx) = 0;

    virtual void enterPlainWhileStmt(WhixyParser::PlainWhileStmtContext* ctx) = 0;
    virtual void exitPlainWhileStmt(WhixyParser::PlainWhileStmtContext* ctx) = 0;

    virtual void enterPlainForStmt(WhixyParser::PlainForStmtContext* ctx) = 0;
    virtual void exitPlainForStmt(WhixyParser::PlainForStmtContext* ctx) = 0;

    virtual void enterComptStmt(WhixyParser::ComptStmtContext* ctx) = 0;
    virtual void exitComptStmt(WhixyParser::ComptStmtContext* ctx) = 0;

    virtual void enterUnreachable(WhixyParser::UnreachableContext* ctx) = 0;
    virtual void exitUnreachable(WhixyParser::UnreachableContext* ctx) = 0;

    virtual void enterDeferStmt(WhixyParser::DeferStmtContext* ctx) = 0;
    virtual void exitDeferStmt(WhixyParser::DeferStmtContext* ctx) = 0;

    virtual void enterErrdeferStmt(WhixyParser::ErrdeferStmtContext* ctx) = 0;
    virtual void exitErrdeferStmt(WhixyParser::ErrdeferStmtContext* ctx) = 0;

    virtual void enterExprSep(WhixyParser::ExprSepContext* ctx) = 0;
    virtual void exitExprSep(WhixyParser::ExprSepContext* ctx) = 0;

    virtual void enterExpr(WhixyParser::ExprContext* ctx) = 0;
    virtual void exitExpr(WhixyParser::ExprContext* ctx) = 0;

    virtual void enterBinaryExpr(WhixyParser::BinaryExprContext* ctx) = 0;
    virtual void exitBinaryExpr(WhixyParser::BinaryExprContext* ctx) = 0;

    virtual void enterAsOp(WhixyParser::AsOpContext* ctx) = 0;
    virtual void exitAsOp(WhixyParser::AsOpContext* ctx) = 0;

    virtual void enterConcatOp(WhixyParser::ConcatOpContext* ctx) = 0;
    virtual void exitConcatOp(WhixyParser::ConcatOpContext* ctx) = 0;

    virtual void enterRepeatOp(WhixyParser::RepeatOpContext* ctx) = 0;
    virtual void exitRepeatOp(WhixyParser::RepeatOpContext* ctx) = 0;

    virtual void enterAddOp(WhixyParser::AddOpContext* ctx) = 0;
    virtual void exitAddOp(WhixyParser::AddOpContext* ctx) = 0;

    virtual void enterSubOp(WhixyParser::SubOpContext* ctx) = 0;
    virtual void exitSubOp(WhixyParser::SubOpContext* ctx) = 0;

    virtual void enterTimesOp(WhixyParser::TimesOpContext* ctx) = 0;
    virtual void exitTimesOp(WhixyParser::TimesOpContext* ctx) = 0;

    virtual void enterDivideOp(WhixyParser::DivideOpContext* ctx) = 0;
    virtual void exitDivideOp(WhixyParser::DivideOpContext* ctx) = 0;

    virtual void enterLessThanOp(WhixyParser::LessThanOpContext* ctx) = 0;
    virtual void exitLessThanOp(WhixyParser::LessThanOpContext* ctx) = 0;

    virtual void enterGreaterThanOp(WhixyParser::GreaterThanOpContext* ctx) = 0;
    virtual void exitGreaterThanOp(WhixyParser::GreaterThanOpContext* ctx) = 0;

    virtual void enterLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* ctx) = 0;
    virtual void exitLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* ctx) = 0;

    virtual void enterGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* ctx) = 0;
    virtual void exitGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* ctx) = 0;

    virtual void enterWrappingAddOp(WhixyParser::WrappingAddOpContext* ctx) = 0;
    virtual void exitWrappingAddOp(WhixyParser::WrappingAddOpContext* ctx) = 0;

    virtual void enterWrappingSubOp(WhixyParser::WrappingSubOpContext* ctx) = 0;
    virtual void exitWrappingSubOp(WhixyParser::WrappingSubOpContext* ctx) = 0;

    virtual void enterWrappingTimesOp(WhixyParser::WrappingTimesOpContext* ctx) = 0;
    virtual void exitWrappingTimesOp(WhixyParser::WrappingTimesOpContext* ctx) = 0;

    virtual void enterLeftShiftOp(WhixyParser::LeftShiftOpContext* ctx) = 0;
    virtual void exitLeftShiftOp(WhixyParser::LeftShiftOpContext* ctx) = 0;

    virtual void enterRightShiftOp(WhixyParser::RightShiftOpContext* ctx) = 0;
    virtual void exitRightShiftOp(WhixyParser::RightShiftOpContext* ctx) = 0;

    virtual void enterLeftRotateOp(WhixyParser::LeftRotateOpContext* ctx) = 0;
    virtual void exitLeftRotateOp(WhixyParser::LeftRotateOpContext* ctx) = 0;

    virtual void enterRightRotateOp(WhixyParser::RightRotateOpContext* ctx) = 0;
    virtual void exitRightRotateOp(WhixyParser::RightRotateOpContext* ctx) = 0;

    virtual void enterEqualityOp(WhixyParser::EqualityOpContext* ctx) = 0;
    virtual void exitEqualityOp(WhixyParser::EqualityOpContext* ctx) = 0;

    virtual void enterInequalityOp(WhixyParser::InequalityOpContext* ctx) = 0;
    virtual void exitInequalityOp(WhixyParser::InequalityOpContext* ctx) = 0;

    virtual void enterAndOp(WhixyParser::AndOpContext* ctx) = 0;
    virtual void exitAndOp(WhixyParser::AndOpContext* ctx) = 0;

    virtual void enterOrOp(WhixyParser::OrOpContext* ctx) = 0;
    virtual void exitOrOp(WhixyParser::OrOpContext* ctx) = 0;

    virtual void enterModOp(WhixyParser::ModOpContext* ctx) = 0;
    virtual void exitModOp(WhixyParser::ModOpContext* ctx) = 0;

    virtual void enterXorOp(WhixyParser::XorOpContext* ctx) = 0;
    virtual void exitXorOp(WhixyParser::XorOpContext* ctx) = 0;

    virtual void enterPostExpr(WhixyParser::PostExprContext* ctx) = 0;
    virtual void exitPostExpr(WhixyParser::PostExprContext* ctx) = 0;

    virtual void enterAccessMemberOp(WhixyParser::AccessMemberOpContext* ctx) = 0;
    virtual void exitAccessMemberOp(WhixyParser::AccessMemberOpContext* ctx) = 0;

    virtual void enterAccessIndexOp(WhixyParser::AccessIndexOpContext* ctx) = 0;
    virtual void exitAccessIndexOp(WhixyParser::AccessIndexOpContext* ctx) = 0;

    virtual void enterAccessTypeOp(WhixyParser::AccessTypeOpContext* ctx) = 0;
    virtual void exitAccessTypeOp(WhixyParser::AccessTypeOpContext* ctx) = 0;

    virtual void enterAccessLengthOp(WhixyParser::AccessLengthOpContext* ctx) = 0;
    virtual void exitAccessLengthOp(WhixyParser::AccessLengthOpContext* ctx) = 0;

    virtual void enterDereferencePointerOp(WhixyParser::DereferencePointerOpContext* ctx) = 0;
    virtual void exitDereferencePointerOp(WhixyParser::DereferencePointerOpContext* ctx) = 0;

    virtual void enterAddressOfOp(WhixyParser::AddressOfOpContext* ctx) = 0;
    virtual void exitAddressOfOp(WhixyParser::AddressOfOpContext* ctx) = 0;

    virtual void enterUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* ctx) = 0;
    virtual void exitUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* ctx) = 0;

    virtual void enterTryOp(WhixyParser::TryOpContext* ctx) = 0;
    virtual void exitTryOp(WhixyParser::TryOpContext* ctx) = 0;

    virtual void enterPreExpr(WhixyParser::PreExprContext* ctx) = 0;
    virtual void exitPreExpr(WhixyParser::PreExprContext* ctx) = 0;

    virtual void enterNotOp(WhixyParser::NotOpContext* ctx) = 0;
    virtual void exitNotOp(WhixyParser::NotOpContext* ctx) = 0;

    virtual void enterNegateOp(WhixyParser::NegateOpContext* ctx) = 0;
    virtual void exitNegateOp(WhixyParser::NegateOpContext* ctx) = 0;

    virtual void enterIfExpr(WhixyParser::IfExprContext* ctx) = 0;
    virtual void exitIfExpr(WhixyParser::IfExprContext* ctx) = 0;

    virtual void enterWhereExpr(WhixyParser::WhereExprContext* ctx) = 0;
    virtual void exitWhereExpr(WhixyParser::WhereExprContext* ctx) = 0;

    virtual void enterCaseExprBlock(WhixyParser::CaseExprBlockContext* ctx) = 0;
    virtual void exitCaseExprBlock(WhixyParser::CaseExprBlockContext* ctx) = 0;

    virtual void enterUnrollWhileExpr(WhixyParser::UnrollWhileExprContext* ctx) = 0;
    virtual void exitUnrollWhileExpr(WhixyParser::UnrollWhileExprContext* ctx) = 0;

    virtual void enterUnrollForExpr(WhixyParser::UnrollForExprContext* ctx) = 0;
    virtual void exitUnrollForExpr(WhixyParser::UnrollForExprContext* ctx) = 0;

    virtual void enterPlainWhileExpr(WhixyParser::PlainWhileExprContext* ctx) = 0;
    virtual void exitPlainWhileExpr(WhixyParser::PlainWhileExprContext* ctx) = 0;

    virtual void enterPlainForExpr(WhixyParser::PlainForExprContext* ctx) = 0;
    virtual void exitPlainForExpr(WhixyParser::PlainForExprContext* ctx) = 0;

    virtual void enterComptExpr(WhixyParser::ComptExprContext* ctx) = 0;
    virtual void exitComptExpr(WhixyParser::ComptExprContext* ctx) = 0;

    virtual void enterPlainRoutineExpr(WhixyParser::PlainRoutineExprContext* ctx) = 0;
    virtual void exitPlainRoutineExpr(WhixyParser::PlainRoutineExprContext* ctx) = 0;

    virtual void enterInlineRoutineExpr(WhixyParser::InlineRoutineExprContext* ctx) = 0;
    virtual void exitInlineRoutineExpr(WhixyParser::InlineRoutineExprContext* ctx) = 0;

    virtual void enterDQStringExpr(WhixyParser::DQStringExprContext* ctx) = 0;
    virtual void exitDQStringExpr(WhixyParser::DQStringExprContext* ctx) = 0;

    virtual void enterBTStringExpr(WhixyParser::BTStringExprContext* ctx) = 0;
    virtual void exitBTStringExpr(WhixyParser::BTStringExprContext* ctx) = 0;

    virtual void enterAtom(WhixyParser::AtomContext* ctx) = 0;
    virtual void exitAtom(WhixyParser::AtomContext* ctx) = 0;

    virtual void enterToken(WhixyParser::TokenContext* ctx) = 0;
    virtual void exitToken(WhixyParser::TokenContext* ctx) = 0;

    virtual void enterTupleExpr(WhixyParser::TupleExprContext* ctx) = 0;
    virtual void exitTupleExpr(WhixyParser::TupleExprContext* ctx) = 0;

    virtual void enterBlockExpr(WhixyParser::BlockExprContext* ctx) = 0;
    virtual void exitBlockExpr(WhixyParser::BlockExprContext* ctx) = 0;

    virtual void enterStructExpr(WhixyParser::StructExprContext* ctx) = 0;
    virtual void exitStructExpr(WhixyParser::StructExprContext* ctx) = 0;

    virtual void enterOParen(WhixyParser::OParenContext* ctx) = 0;
    virtual void exitOParen(WhixyParser::OParenContext* ctx) = 0;

    virtual void enterCParen(WhixyParser::CParenContext* ctx) = 0;
    virtual void exitCParen(WhixyParser::CParenContext* ctx) = 0;

    virtual void enterOBrace(WhixyParser::OBraceContext* ctx) = 0;
    virtual void exitOBrace(WhixyParser::OBraceContext* ctx) = 0;

    virtual void enterCBrace(WhixyParser::CBraceContext* ctx) = 0;
    virtual void exitCBrace(WhixyParser::CBraceContext* ctx) = 0;
};

} // namespace Whixy
