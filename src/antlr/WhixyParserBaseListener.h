
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
class WhixyParserBaseListener: public WhixyParserListener {
  public:
    virtual void enterSrcFile(WhixyParser::SrcFileContext* /*ctx*/) override {}
    virtual void exitSrcFile(WhixyParser::SrcFileContext* /*ctx*/) override {}

    virtual void enterStmtSep(WhixyParser::StmtSepContext* /*ctx*/) override {}
    virtual void exitStmtSep(WhixyParser::StmtSepContext* /*ctx*/) override {}

    virtual void enterStmt(WhixyParser::StmtContext* /*ctx*/) override {}
    virtual void exitStmt(WhixyParser::StmtContext* /*ctx*/) override {}

    virtual void enterImmutableVals(WhixyParser::ImmutableValsContext* /*ctx*/) override {}
    virtual void exitImmutableVals(WhixyParser::ImmutableValsContext* /*ctx*/) override {}

    virtual void enterMutableVals(WhixyParser::MutableValsContext* /*ctx*/) override {}
    virtual void exitMutableVals(WhixyParser::MutableValsContext* /*ctx*/) override {}

    virtual void enterAssignStmt(WhixyParser::AssignStmtContext* /*ctx*/) override {}
    virtual void exitAssignStmt(WhixyParser::AssignStmtContext* /*ctx*/) override {}

    virtual void enterAndEqualsOp(WhixyParser::AndEqualsOpContext* /*ctx*/) override {}
    virtual void exitAndEqualsOp(WhixyParser::AndEqualsOpContext* /*ctx*/) override {}

    virtual void enterOrEqualsOp(WhixyParser::OrEqualsOpContext* /*ctx*/) override {}
    virtual void exitOrEqualsOp(WhixyParser::OrEqualsOpContext* /*ctx*/) override {}

    virtual void enterModEqualsOp(WhixyParser::ModEqualsOpContext* /*ctx*/) override {}
    virtual void exitModEqualsOp(WhixyParser::ModEqualsOpContext* /*ctx*/) override {}

    virtual void enterXorEqualsOp(WhixyParser::XorEqualsOpContext* /*ctx*/) override {}
    virtual void exitXorEqualsOp(WhixyParser::XorEqualsOpContext* /*ctx*/) override {}

    virtual void enterDivideEqualsOp(WhixyParser::DivideEqualsOpContext* /*ctx*/) override {}
    virtual void exitDivideEqualsOp(WhixyParser::DivideEqualsOpContext* /*ctx*/) override {}

    virtual void enterAddEqualsOp(WhixyParser::AddEqualsOpContext* /*ctx*/) override {}
    virtual void exitAddEqualsOp(WhixyParser::AddEqualsOpContext* /*ctx*/) override {}

    virtual void enterSubEqualsOp(WhixyParser::SubEqualsOpContext* /*ctx*/) override {}
    virtual void exitSubEqualsOp(WhixyParser::SubEqualsOpContext* /*ctx*/) override {}

    virtual void enterTimesEqualsOp(WhixyParser::TimesEqualsOpContext* /*ctx*/) override {}
    virtual void exitTimesEqualsOp(WhixyParser::TimesEqualsOpContext* /*ctx*/) override {}

    virtual void enterLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* /*ctx*/) override {}
    virtual void exitLeftShiftEqualsOp(WhixyParser::LeftShiftEqualsOpContext* /*ctx*/) override {}

    virtual void enterRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* /*ctx*/) override {}
    virtual void exitRightShiftEqualsOp(WhixyParser::RightShiftEqualsOpContext* /*ctx*/) override {}

    virtual void enterWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* /*ctx*/) override {}
    virtual void exitWrappingTimesEqualsOp(WhixyParser::WrappingTimesEqualsOpContext* /*ctx*/) override {}

    virtual void enterWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* /*ctx*/) override {}
    virtual void exitWrappingAddEqualsOp(WhixyParser::WrappingAddEqualsOpContext* /*ctx*/) override {}

    virtual void enterWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* /*ctx*/) override {}
    virtual void exitWrappingSubEqualsOp(WhixyParser::WrappingSubEqualsOpContext* /*ctx*/) override {}

    virtual void enterRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* /*ctx*/) override {}
    virtual void exitRightRotateEqualsOp(WhixyParser::RightRotateEqualsOpContext* /*ctx*/) override {}

    virtual void enterLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* /*ctx*/) override {}
    virtual void exitLeftRotateEqualsOp(WhixyParser::LeftRotateEqualsOpContext* /*ctx*/) override {}

    virtual void enterCall(WhixyParser::CallContext* /*ctx*/) override {}
    virtual void exitCall(WhixyParser::CallContext* /*ctx*/) override {}

    virtual void enterFuncBlockStmt(WhixyParser::FuncBlockStmtContext* /*ctx*/) override {}
    virtual void exitFuncBlockStmt(WhixyParser::FuncBlockStmtContext* /*ctx*/) override {}

    virtual void enterProcBlockStmt(WhixyParser::ProcBlockStmtContext* /*ctx*/) override {}
    virtual void exitProcBlockStmt(WhixyParser::ProcBlockStmtContext* /*ctx*/) override {}

    virtual void enterPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* /*ctx*/) override {}
    virtual void exitPlainRoutineStmt(WhixyParser::PlainRoutineStmtContext* /*ctx*/) override {}

    virtual void enterInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* /*ctx*/) override {}
    virtual void exitInlineRoutineStmt(WhixyParser::InlineRoutineStmtContext* /*ctx*/) override {}

    virtual void enterReturnStmt(WhixyParser::ReturnStmtContext* /*ctx*/) override {}
    virtual void exitReturnStmt(WhixyParser::ReturnStmtContext* /*ctx*/) override {}

    virtual void enterIfStmt(WhixyParser::IfStmtContext* /*ctx*/) override {}
    virtual void exitIfStmt(WhixyParser::IfStmtContext* /*ctx*/) override {}

    virtual void enterWhereStmt(WhixyParser::WhereStmtContext* /*ctx*/) override {}
    virtual void exitWhereStmt(WhixyParser::WhereStmtContext* /*ctx*/) override {}

    virtual void enterComparisonOp(WhixyParser::ComparisonOpContext* /*ctx*/) override {}
    virtual void exitComparisonOp(WhixyParser::ComparisonOpContext* /*ctx*/) override {}

    virtual void enterCaseStmtBlock(WhixyParser::CaseStmtBlockContext* /*ctx*/) override {}
    virtual void exitCaseStmtBlock(WhixyParser::CaseStmtBlockContext* /*ctx*/) override {}

    virtual void enterUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* /*ctx*/) override {}
    virtual void exitUnrollWhileStmt(WhixyParser::UnrollWhileStmtContext* /*ctx*/) override {}

    virtual void enterUnrollForStmt(WhixyParser::UnrollForStmtContext* /*ctx*/) override {}
    virtual void exitUnrollForStmt(WhixyParser::UnrollForStmtContext* /*ctx*/) override {}

    virtual void enterPlainWhileStmt(WhixyParser::PlainWhileStmtContext* /*ctx*/) override {}
    virtual void exitPlainWhileStmt(WhixyParser::PlainWhileStmtContext* /*ctx*/) override {}

    virtual void enterPlainForStmt(WhixyParser::PlainForStmtContext* /*ctx*/) override {}
    virtual void exitPlainForStmt(WhixyParser::PlainForStmtContext* /*ctx*/) override {}

    virtual void enterComptStmt(WhixyParser::ComptStmtContext* /*ctx*/) override {}
    virtual void exitComptStmt(WhixyParser::ComptStmtContext* /*ctx*/) override {}

    virtual void enterUnreachable(WhixyParser::UnreachableContext* /*ctx*/) override {}
    virtual void exitUnreachable(WhixyParser::UnreachableContext* /*ctx*/) override {}

    virtual void enterDeferStmt(WhixyParser::DeferStmtContext* /*ctx*/) override {}
    virtual void exitDeferStmt(WhixyParser::DeferStmtContext* /*ctx*/) override {}

    virtual void enterErrdeferStmt(WhixyParser::ErrdeferStmtContext* /*ctx*/) override {}
    virtual void exitErrdeferStmt(WhixyParser::ErrdeferStmtContext* /*ctx*/) override {}

    virtual void enterExprSep(WhixyParser::ExprSepContext* /*ctx*/) override {}
    virtual void exitExprSep(WhixyParser::ExprSepContext* /*ctx*/) override {}

    virtual void enterExpr(WhixyParser::ExprContext* /*ctx*/) override {}
    virtual void exitExpr(WhixyParser::ExprContext* /*ctx*/) override {}

    virtual void enterBinaryExpr(WhixyParser::BinaryExprContext* /*ctx*/) override {}
    virtual void exitBinaryExpr(WhixyParser::BinaryExprContext* /*ctx*/) override {}

    virtual void enterAsOp(WhixyParser::AsOpContext* /*ctx*/) override {}
    virtual void exitAsOp(WhixyParser::AsOpContext* /*ctx*/) override {}

    virtual void enterConcatOp(WhixyParser::ConcatOpContext* /*ctx*/) override {}
    virtual void exitConcatOp(WhixyParser::ConcatOpContext* /*ctx*/) override {}

    virtual void enterRepeatOp(WhixyParser::RepeatOpContext* /*ctx*/) override {}
    virtual void exitRepeatOp(WhixyParser::RepeatOpContext* /*ctx*/) override {}

    virtual void enterAddOp(WhixyParser::AddOpContext* /*ctx*/) override {}
    virtual void exitAddOp(WhixyParser::AddOpContext* /*ctx*/) override {}

    virtual void enterSubOp(WhixyParser::SubOpContext* /*ctx*/) override {}
    virtual void exitSubOp(WhixyParser::SubOpContext* /*ctx*/) override {}

    virtual void enterTimesOp(WhixyParser::TimesOpContext* /*ctx*/) override {}
    virtual void exitTimesOp(WhixyParser::TimesOpContext* /*ctx*/) override {}

    virtual void enterDivideOp(WhixyParser::DivideOpContext* /*ctx*/) override {}
    virtual void exitDivideOp(WhixyParser::DivideOpContext* /*ctx*/) override {}

    virtual void enterLessThanOp(WhixyParser::LessThanOpContext* /*ctx*/) override {}
    virtual void exitLessThanOp(WhixyParser::LessThanOpContext* /*ctx*/) override {}

    virtual void enterGreaterThanOp(WhixyParser::GreaterThanOpContext* /*ctx*/) override {}
    virtual void exitGreaterThanOp(WhixyParser::GreaterThanOpContext* /*ctx*/) override {}

    virtual void enterLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* /*ctx*/) override {}
    virtual void exitLessThanOrEqualToOp(WhixyParser::LessThanOrEqualToOpContext* /*ctx*/) override {}

    virtual void enterGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* /*ctx*/) override {}
    virtual void exitGreaterThanOrEqualToOp(WhixyParser::GreaterThanOrEqualToOpContext* /*ctx*/) override {}

    virtual void enterWrappingAddOp(WhixyParser::WrappingAddOpContext* /*ctx*/) override {}
    virtual void exitWrappingAddOp(WhixyParser::WrappingAddOpContext* /*ctx*/) override {}

    virtual void enterWrappingSubOp(WhixyParser::WrappingSubOpContext* /*ctx*/) override {}
    virtual void exitWrappingSubOp(WhixyParser::WrappingSubOpContext* /*ctx*/) override {}

    virtual void enterWrappingTimesOp(WhixyParser::WrappingTimesOpContext* /*ctx*/) override {}
    virtual void exitWrappingTimesOp(WhixyParser::WrappingTimesOpContext* /*ctx*/) override {}

    virtual void enterLeftShiftOp(WhixyParser::LeftShiftOpContext* /*ctx*/) override {}
    virtual void exitLeftShiftOp(WhixyParser::LeftShiftOpContext* /*ctx*/) override {}

    virtual void enterRightShiftOp(WhixyParser::RightShiftOpContext* /*ctx*/) override {}
    virtual void exitRightShiftOp(WhixyParser::RightShiftOpContext* /*ctx*/) override {}

    virtual void enterLeftRotateOp(WhixyParser::LeftRotateOpContext* /*ctx*/) override {}
    virtual void exitLeftRotateOp(WhixyParser::LeftRotateOpContext* /*ctx*/) override {}

    virtual void enterRightRotateOp(WhixyParser::RightRotateOpContext* /*ctx*/) override {}
    virtual void exitRightRotateOp(WhixyParser::RightRotateOpContext* /*ctx*/) override {}

    virtual void enterEqualityOp(WhixyParser::EqualityOpContext* /*ctx*/) override {}
    virtual void exitEqualityOp(WhixyParser::EqualityOpContext* /*ctx*/) override {}

    virtual void enterInequalityOp(WhixyParser::InequalityOpContext* /*ctx*/) override {}
    virtual void exitInequalityOp(WhixyParser::InequalityOpContext* /*ctx*/) override {}

    virtual void enterAndOp(WhixyParser::AndOpContext* /*ctx*/) override {}
    virtual void exitAndOp(WhixyParser::AndOpContext* /*ctx*/) override {}

    virtual void enterOrOp(WhixyParser::OrOpContext* /*ctx*/) override {}
    virtual void exitOrOp(WhixyParser::OrOpContext* /*ctx*/) override {}

    virtual void enterModOp(WhixyParser::ModOpContext* /*ctx*/) override {}
    virtual void exitModOp(WhixyParser::ModOpContext* /*ctx*/) override {}

    virtual void enterXorOp(WhixyParser::XorOpContext* /*ctx*/) override {}
    virtual void exitXorOp(WhixyParser::XorOpContext* /*ctx*/) override {}

    virtual void enterPostExpr(WhixyParser::PostExprContext* /*ctx*/) override {}
    virtual void exitPostExpr(WhixyParser::PostExprContext* /*ctx*/) override {}

    virtual void enterAccessMemberOp(WhixyParser::AccessMemberOpContext* /*ctx*/) override {}
    virtual void exitAccessMemberOp(WhixyParser::AccessMemberOpContext* /*ctx*/) override {}

    virtual void enterAccessIndexOp(WhixyParser::AccessIndexOpContext* /*ctx*/) override {}
    virtual void exitAccessIndexOp(WhixyParser::AccessIndexOpContext* /*ctx*/) override {}

    virtual void enterAccessTypeOp(WhixyParser::AccessTypeOpContext* /*ctx*/) override {}
    virtual void exitAccessTypeOp(WhixyParser::AccessTypeOpContext* /*ctx*/) override {}

    virtual void enterAccessLengthOp(WhixyParser::AccessLengthOpContext* /*ctx*/) override {}
    virtual void exitAccessLengthOp(WhixyParser::AccessLengthOpContext* /*ctx*/) override {}

    virtual void enterDereferencePointerOp(WhixyParser::DereferencePointerOpContext* /*ctx*/) override {}
    virtual void exitDereferencePointerOp(WhixyParser::DereferencePointerOpContext* /*ctx*/) override {}

    virtual void enterAddressOfOp(WhixyParser::AddressOfOpContext* /*ctx*/) override {}
    virtual void exitAddressOfOp(WhixyParser::AddressOfOpContext* /*ctx*/) override {}

    virtual void enterUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* /*ctx*/) override {}
    virtual void exitUnwrapOptionalOp(WhixyParser::UnwrapOptionalOpContext* /*ctx*/) override {}

    virtual void enterTryOp(WhixyParser::TryOpContext* /*ctx*/) override {}
    virtual void exitTryOp(WhixyParser::TryOpContext* /*ctx*/) override {}

    virtual void enterPreExpr(WhixyParser::PreExprContext* /*ctx*/) override {}
    virtual void exitPreExpr(WhixyParser::PreExprContext* /*ctx*/) override {}

    virtual void enterNotOp(WhixyParser::NotOpContext* /*ctx*/) override {}
    virtual void exitNotOp(WhixyParser::NotOpContext* /*ctx*/) override {}

    virtual void enterNegateOp(WhixyParser::NegateOpContext* /*ctx*/) override {}
    virtual void exitNegateOp(WhixyParser::NegateOpContext* /*ctx*/) override {}

    virtual void enterIfExpr(WhixyParser::IfExprContext* /*ctx*/) override {}
    virtual void exitIfExpr(WhixyParser::IfExprContext* /*ctx*/) override {}

    virtual void enterWhereExpr(WhixyParser::WhereExprContext* /*ctx*/) override {}
    virtual void exitWhereExpr(WhixyParser::WhereExprContext* /*ctx*/) override {}

    virtual void enterCaseExprBlock(WhixyParser::CaseExprBlockContext* /*ctx*/) override {}
    virtual void exitCaseExprBlock(WhixyParser::CaseExprBlockContext* /*ctx*/) override {}

    virtual void enterUnrollWhileExpr(WhixyParser::UnrollWhileExprContext* /*ctx*/) override {}
    virtual void exitUnrollWhileExpr(WhixyParser::UnrollWhileExprContext* /*ctx*/) override {}

    virtual void enterUnrollForExpr(WhixyParser::UnrollForExprContext* /*ctx*/) override {}
    virtual void exitUnrollForExpr(WhixyParser::UnrollForExprContext* /*ctx*/) override {}

    virtual void enterPlainWhileExpr(WhixyParser::PlainWhileExprContext* /*ctx*/) override {}
    virtual void exitPlainWhileExpr(WhixyParser::PlainWhileExprContext* /*ctx*/) override {}

    virtual void enterPlainForExpr(WhixyParser::PlainForExprContext* /*ctx*/) override {}
    virtual void exitPlainForExpr(WhixyParser::PlainForExprContext* /*ctx*/) override {}

    virtual void enterComptExpr(WhixyParser::ComptExprContext* /*ctx*/) override {}
    virtual void exitComptExpr(WhixyParser::ComptExprContext* /*ctx*/) override {}

    virtual void enterPlainRoutineExpr(WhixyParser::PlainRoutineExprContext* /*ctx*/) override {}
    virtual void exitPlainRoutineExpr(WhixyParser::PlainRoutineExprContext* /*ctx*/) override {}

    virtual void enterInlineRoutineExpr(WhixyParser::InlineRoutineExprContext* /*ctx*/) override {}
    virtual void exitInlineRoutineExpr(WhixyParser::InlineRoutineExprContext* /*ctx*/) override {}

    virtual void enterDQStringExpr(WhixyParser::DQStringExprContext* /*ctx*/) override {}
    virtual void exitDQStringExpr(WhixyParser::DQStringExprContext* /*ctx*/) override {}

    virtual void enterBTStringExpr(WhixyParser::BTStringExprContext* /*ctx*/) override {}
    virtual void exitBTStringExpr(WhixyParser::BTStringExprContext* /*ctx*/) override {}

    virtual void enterAtom(WhixyParser::AtomContext* /*ctx*/) override {}
    virtual void exitAtom(WhixyParser::AtomContext* /*ctx*/) override {}

    virtual void enterToken(WhixyParser::TokenContext* /*ctx*/) override {}
    virtual void exitToken(WhixyParser::TokenContext* /*ctx*/) override {}

    virtual void enterBlockExpr(WhixyParser::BlockExprContext* /*ctx*/) override {}
    virtual void exitBlockExpr(WhixyParser::BlockExprContext* /*ctx*/) override {}

    virtual void enterStructExpr(WhixyParser::StructExprContext* /*ctx*/) override {}
    virtual void exitStructExpr(WhixyParser::StructExprContext* /*ctx*/) override {}

    virtual void enterTupleExpr(WhixyParser::TupleExprContext* /*ctx*/) override {}
    virtual void exitTupleExpr(WhixyParser::TupleExprContext* /*ctx*/) override {}

    virtual void enterOParen(WhixyParser::OParenContext* /*ctx*/) override {}
    virtual void exitOParen(WhixyParser::OParenContext* /*ctx*/) override {}

    virtual void enterCParen(WhixyParser::CParenContext* /*ctx*/) override {}
    virtual void exitCParen(WhixyParser::CParenContext* /*ctx*/) override {}

    virtual void enterOBrace(WhixyParser::OBraceContext* /*ctx*/) override {}
    virtual void exitOBrace(WhixyParser::OBraceContext* /*ctx*/) override {}

    virtual void enterCBrace(WhixyParser::CBraceContext* /*ctx*/) override {}
    virtual void exitCBrace(WhixyParser::CBraceContext* /*ctx*/) override {}

    virtual void enterEveryRule(antlr4::ParserRuleContext* /*ctx*/) override {}
    virtual void exitEveryRule(antlr4::ParserRuleContext* /*ctx*/) override {}
    virtual void visitTerminal(antlr4::tree::TerminalNode* /*node*/) override {}
    virtual void visitErrorNode(antlr4::tree::ErrorNode* /*node*/) override {}
};

} // namespace Whixy
