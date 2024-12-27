
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

namespace Whixy {

class WhixyParser: public antlr4::Parser {
  public:
    enum {
        DOUBLEQUOTESTRING = 1,
        BACKTICKSTRING = 2,
        BACKSLASHSTRING = 3,
        BLOCKDOCCOMMENT = 4,
        BLOCKCOMMENT = 5,
        DOCCOMMENT = 6,
        COMMENT = 7,
        WHITESPACE = 8,
        NEWLINE = 9,
        OPENPARENTHESIS = 10,
        CLOSEDPARENTHESIS = 11,
        DOT = 12,
        COMMA = 13,
        UNDERSCORE = 14,
        EXCLAMATION = 15,
        OPENBRACE = 16,
        CLOSEDBRACE = 17,
        OPENBRACKET = 18,
        CLOSEDBRACKET = 19,
        SEMICOLON = 20,
        QUESTION = 21,
        DOLLAR_OPENPARENTHESIS = 22,
        SINGLEQUOTE = 23,
        GREATERTHAN_GREATERTHAN_PERCENT_EQUAL = 24,
        GREATERTHAN_GREATERTHAN_PERCENT = 25,
        GREATERTHAN_GREATERTHAN_EQUAL = 26,
        GREATERTHAN_GREATERTHAN = 27,
        GREATERTHAN_EQUAL = 28,
        GREATERTHAN = 29,
        LESSTHAN_LESSTHAN_PERCENT_EQUAL = 30,
        LESSTHAN_LESSTHAN_PERCENT = 31,
        LESSTHAN_LESSTHAN_EQUAL = 32,
        LESSTHAN_LESSTHAN = 33,
        LESSTHAN_EQUAL = 34,
        LESSTHAN = 35,
        ASTERISK_PERCENT_EQUAL = 36,
        ASTERISK_PERCENT = 37,
        ASTERISK_EQUAL = 38,
        ASTERISK_ASTERISK = 39,
        ASTERISK = 40,
        PLUS_PERCENT_EQUAL = 41,
        PLUS_PERCENT = 42,
        PLUS_EQUAL = 43,
        PLUS_PLUS = 44,
        PLUS = 45,
        MINUS_PERCENT_EQUAL = 46,
        MINUS_PERCENT = 47,
        MINUS_EQUAL = 48,
        MINUS = 49,
        TILDE_EQUAL = 50,
        TILDE = 51,
        AMPERSAND_EQUAL = 52,
        AMPERSAND = 53,
        PERCENT_EQUAL = 54,
        PERCENT = 55,
        CARROT_EQUAL = 56,
        CARROT = 57,
        SLASH_EQUAL = 58,
        SLASH = 59,
        EQUAL_EQUAL = 60,
        EQUAL = 61,
        PIPE_EQUAL = 62,
        PIPE = 63,
        AND = 64,
        OR = 65,
        TYPE = 66,
        LEN = 67,
        THIS = 68,
        MUT = 69,
        INLINE = 70,
        RETURN = 71,
        CONTINUE = 72,
        BREAK = 73,
        GOTO = 74,
        WHILE = 75,
        FOR = 76,
        IF = 77,
        ELSEIF = 78,
        ELSE = 79,
        WHERE = 80,
        DEFER = 81,
        ERRDEFER = 82,
        FAST = 83,
        BARE = 84,
        IMPORT = 85,
        ALIGN = 86,
        THREADL = 87,
        UNREACHABLE = 88,
        VOLATILE = 89,
        UNROLL = 90,
        COMPT = 91,
        TEST = 92,
        ENUM = 93,
        EMBED = 94,
        UNION = 95,
        STD = 96,
        ORELSE = 97,
        CATCH = 98,
        AS = 99,
        TOKEN = 100
    };

    enum {
        RuleSrcFile = 0,
        RuleStmtSep = 1,
        RuleStmt = 2,
        RuleField = 3,
        RuleMutable = 4,
        RuleVolatile = 5,
        RuleThreadl = 6,
        RuleAssignStmt = 7,
        RuleAssignOp = 8,
        RuleCall = 9,
        RuleBlockStmt = 10,
        RuleDollarOParen = 11,
        RuleRoutineStmt = 12,
        RuleInline = 13,
        RuleFast = 14,
        RuleBare = 15,
        RuleReturnStmt = 16,
        RuleIfStmt = 17,
        RuleWhereStmt = 18,
        RuleComparisonOp = 19,
        RuleCaseStmtBlock = 20,
        RuleLoopStmt = 21,
        RuleUnroll = 22,
        RuleWhile = 23,
        RuleFor = 24,
        RuleComptStmt = 25,
        RuleUnreachable = 26,
        RuleDeferStmt = 27,
        RuleErrdeferStmt = 28,
        RuleExprSep = 29,
        RuleExpr = 30,
        RuleTypeExpr = 31,
        RuleUnderscore = 32,
        RulePointer = 33,
        RuleThis = 34,
        RuleBinaryExpr = 35,
        RuleAsOp = 36,
        RuleConcatOp = 37,
        RuleRepeatOp = 38,
        RuleAddOp = 39,
        RuleSubOp = 40,
        RuleTimesOp = 41,
        RuleDivideOp = 42,
        RuleLessThanOp = 43,
        RuleGreaterThanOp = 44,
        RuleLessThanOrEqualToOp = 45,
        RuleGreaterThanOrEqualToOp = 46,
        RuleWrappingAddOp = 47,
        RuleWrappingSubOp = 48,
        RuleWrappingTimesOp = 49,
        RuleLeftShiftOp = 50,
        RuleRightShiftOp = 51,
        RuleLeftRotateOp = 52,
        RuleRightRotateOp = 53,
        RuleEqualityOp = 54,
        RuleInequalityOp = 55,
        RuleLogicalAndOp = 56,
        RuleLogicalOrOp = 57,
        RuleBitwiseAndOp = 58,
        RuleBitwiseOrOp = 59,
        RuleModOp = 60,
        RuleXorOp = 61,
        RulePostExpr = 62,
        RulePostOp = 63,
        RulePreExpr = 64,
        RulePreOp = 65,
        RuleIfExpr = 66,
        RuleWhereExpr = 67,
        RuleCaseExprBlock = 68,
        RuleComptExpr = 69,
        RuleRoutineExpr = 70,
        RuleString = 71,
        RuleRune = 72,
        RuleAtom = 73,
        RuleToken = 74,
        RuleTupleExpr = 75,
        RuleBlockExpr = 76,
        RuleStructExpr = 77,
        RuleOParen = 78,
        RuleCParen = 79,
        RuleOBrace = 80,
        RuleCBrace = 81
    };

    explicit WhixyParser(antlr4::TokenStream* input);

    WhixyParser(antlr4::TokenStream* input, const antlr4::atn::ParserATNSimulatorOptions& options);

    ~WhixyParser() override;

    std::string getGrammarFileName() const override;

    const antlr4::atn::ATN& getATN() const override;

    const std::vector<std::string>& getRuleNames() const override;

    const antlr4::dfa::Vocabulary& getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    class SrcFileContext;
    class StmtSepContext;
    class StmtContext;
    class FieldContext;
    class MutableContext;
    class VolatileContext;
    class ThreadlContext;
    class AssignStmtContext;
    class AssignOpContext;
    class CallContext;
    class BlockStmtContext;
    class DollarOParenContext;
    class RoutineStmtContext;
    class InlineContext;
    class FastContext;
    class BareContext;
    class ReturnStmtContext;
    class IfStmtContext;
    class WhereStmtContext;
    class ComparisonOpContext;
    class CaseStmtBlockContext;
    class LoopStmtContext;
    class UnrollContext;
    class WhileContext;
    class ForContext;
    class ComptStmtContext;
    class UnreachableContext;
    class DeferStmtContext;
    class ErrdeferStmtContext;
    class ExprSepContext;
    class ExprContext;
    class TypeExprContext;
    class UnderscoreContext;
    class PointerContext;
    class ThisContext;
    class BinaryExprContext;
    class AsOpContext;
    class ConcatOpContext;
    class RepeatOpContext;
    class AddOpContext;
    class SubOpContext;
    class TimesOpContext;
    class DivideOpContext;
    class LessThanOpContext;
    class GreaterThanOpContext;
    class LessThanOrEqualToOpContext;
    class GreaterThanOrEqualToOpContext;
    class WrappingAddOpContext;
    class WrappingSubOpContext;
    class WrappingTimesOpContext;
    class LeftShiftOpContext;
    class RightShiftOpContext;
    class LeftRotateOpContext;
    class RightRotateOpContext;
    class EqualityOpContext;
    class InequalityOpContext;
    class LogicalAndOpContext;
    class LogicalOrOpContext;
    class BitwiseAndOpContext;
    class BitwiseOrOpContext;
    class ModOpContext;
    class XorOpContext;
    class PostExprContext;
    class PostOpContext;
    class PreExprContext;
    class PreOpContext;
    class IfExprContext;
    class WhereExprContext;
    class CaseExprBlockContext;
    class ComptExprContext;
    class RoutineExprContext;
    class StringContext;
    class RuneContext;
    class AtomContext;
    class TokenContext;
    class TupleExprContext;
    class BlockExprContext;
    class StructExprContext;
    class OParenContext;
    class CParenContext;
    class OBraceContext;
    class CBraceContext;

    class SrcFileContext: public antlr4::ParserRuleContext {
      public:
        SrcFileContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        antlr4::tree::TerminalNode* EOF();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    SrcFileContext* srcFile();

    class StmtSepContext: public antlr4::ParserRuleContext {
      public:
        StmtSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SEMICOLON();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StmtSepContext* stmtSep();

    class StmtContext: public antlr4::ParserRuleContext {
      public:
        StmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        FieldContext* field();
        AssignStmtContext* assignStmt();
        CallContext* call();
        BlockStmtContext* blockStmt();
        RoutineStmtContext* routineStmt();
        ReturnStmtContext* returnStmt();
        IfStmtContext* ifStmt();
        WhereStmtContext* whereStmt();
        LoopStmtContext* loopStmt();
        ComptStmtContext* comptStmt();
        UnreachableContext* unreachable();
        DeferStmtContext* deferStmt();
        ErrdeferStmtContext* errdeferStmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StmtContext* stmt();

    class FieldContext: public antlr4::ParserRuleContext {
      public:
        FieldContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AtomContext* atom();
        MutableContext* mutable_();
        VolatileContext* volatile_();
        ThreadlContext* threadl();
        std::vector<TokenContext*> token();
        TokenContext* token(size_t i);
        antlr4::tree::TerminalNode* EQUAL();
        ExprContext* expr();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    FieldContext* field();

    class MutableContext: public antlr4::ParserRuleContext {
      public:
        MutableContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MUT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MutableContext* mutable_();

    class VolatileContext: public antlr4::ParserRuleContext {
      public:
        VolatileContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* VOLATILE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    VolatileContext* volatile_();

    class ThreadlContext: public antlr4::ParserRuleContext {
      public:
        ThreadlContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* THREADL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ThreadlContext* threadl();

    class AssignStmtContext: public antlr4::ParserRuleContext {
      public:
        AssignStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        AssignOpContext* assignOp();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AssignStmtContext* assignStmt();

    class AssignOpContext: public antlr4::ParserRuleContext {
      public:
        AssignOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        AssignOpContext() = default;
        void copyFrom(AssignOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class SubEqualsOpContext: public AssignOpContext {
      public:
        SubEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingTimesEqualsOpContext: public AssignOpContext {
      public:
        WrappingTimesEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AndEqualsOpContext: public AssignOpContext {
      public:
        AndEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftRotateEqualsOpContext: public AssignOpContext {
      public:
        LeftRotateEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftShiftEqualsOpContext: public AssignOpContext {
      public:
        LeftShiftEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrEqualsOpContext: public AssignOpContext {
      public:
        OrEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightRotateEqualsOpContext: public AssignOpContext {
      public:
        RightRotateEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class TimesEqualsOpContext: public AssignOpContext {
      public:
        TimesEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AddEqualsOpContext: public AssignOpContext {
      public:
        AddEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightShiftEqualsOpContext: public AssignOpContext {
      public:
        RightShiftEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingAddEqualsOpContext: public AssignOpContext {
      public:
        WrappingAddEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ModEqualsOpContext: public AssignOpContext {
      public:
        ModEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DivideEqualsOpContext: public AssignOpContext {
      public:
        DivideEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingSubEqualsOpContext: public AssignOpContext {
      public:
        WrappingSubEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class XorEqualsOpContext: public AssignOpContext {
      public:
        XorEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AssignOpContext* assignOp();

    class CallContext: public antlr4::ParserRuleContext {
      public:
        CallContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        ExprContext* expr();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CallContext* call();

    class BlockStmtContext: public antlr4::ParserRuleContext {
      public:
        BlockStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        CParenContext* cParen();
        OParenContext* oParen();
        DollarOParenContext* dollarOParen();
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BlockStmtContext* blockStmt();

    class DollarOParenContext: public antlr4::ParserRuleContext {
      public:
        DollarOParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* DOLLAR_OPENPARENTHESIS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DollarOParenContext* dollarOParen();

    class RoutineStmtContext: public antlr4::ParserRuleContext {
      public:
        RoutineStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        TypeExprContext* typeExpr();
        TokenContext* token();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        InlineContext* inline_();
        FastContext* fast();
        BareContext* bare();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RoutineStmtContext* routineStmt();

    class InlineContext: public antlr4::ParserRuleContext {
      public:
        InlineContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* INLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    InlineContext* inline_();

    class FastContext: public antlr4::ParserRuleContext {
      public:
        FastContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FAST();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    FastContext* fast();

    class BareContext: public antlr4::ParserRuleContext {
      public:
        BareContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* BARE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BareContext* bare();

    class ReturnStmtContext: public antlr4::ParserRuleContext {
      public:
        ReturnStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* RETURN();
        ExprContext* expr();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ReturnStmtContext* returnStmt();

    class IfStmtContext: public antlr4::ParserRuleContext {
      public:
        IfStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IF();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<antlr4::tree::TerminalNode*> ELSEIF();
        antlr4::tree::TerminalNode* ELSEIF(size_t i);
        antlr4::tree::TerminalNode* ELSE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IfStmtContext* ifStmt();

    class WhereStmtContext: public antlr4::ParserRuleContext {
      public:
        WhereStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHERE();
        AtomContext* atom();
        ComparisonOpContext* comparisonOp();
        CaseStmtBlockContext* caseStmtBlock();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhereStmtContext* whereStmt();

    class ComparisonOpContext: public antlr4::ParserRuleContext {
      public:
        ComparisonOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComparisonOpContext* comparisonOp();

    class CaseStmtBlockContext: public antlr4::ParserRuleContext {
      public:
        CaseStmtBlockContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CaseStmtBlockContext* caseStmtBlock();

    class LoopStmtContext: public antlr4::ParserRuleContext {
      public:
        LoopStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        StmtContext* stmt();
        WhileContext* while_();
        ForContext* for_();
        UnrollContext* unroll();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LoopStmtContext* loopStmt();

    class UnrollContext: public antlr4::ParserRuleContext {
      public:
        UnrollContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* UNROLL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    UnrollContext* unroll();

    class WhileContext: public antlr4::ParserRuleContext {
      public:
        WhileContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHILE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhileContext* while_();

    class ForContext: public antlr4::ParserRuleContext {
      public:
        ForContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FOR();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ForContext* for_();

    class ComptStmtContext: public antlr4::ParserRuleContext {
      public:
        ComptStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        StmtContext* stmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComptStmtContext* comptStmt();

    class UnreachableContext: public antlr4::ParserRuleContext {
      public:
        UnreachableContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* UNREACHABLE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    UnreachableContext* unreachable();

    class DeferStmtContext: public antlr4::ParserRuleContext {
      public:
        DeferStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* DEFER();
        StmtContext* stmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DeferStmtContext* deferStmt();

    class ErrdeferStmtContext: public antlr4::ParserRuleContext {
      public:
        ErrdeferStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ERRDEFER();
        StmtContext* stmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ErrdeferStmtContext* errdeferStmt();

    class ExprSepContext: public antlr4::ParserRuleContext {
      public:
        ExprSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMMA();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprSepContext* exprSep();

    class ExprContext: public antlr4::ParserRuleContext {
      public:
        ExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        FieldContext* field();
        TypeExprContext* typeExpr();
        CallContext* call();
        BinaryExprContext* binaryExpr();
        PostExprContext* postExpr();
        PreExprContext* preExpr();
        IfExprContext* ifExpr();
        WhereExprContext* whereExpr();
        ComptExprContext* comptExpr();
        UnreachableContext* unreachable();
        RoutineExprContext* routineExpr();
        StringContext* string();
        RuneContext* rune();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprContext* expr();

    class TypeExprContext: public antlr4::ParserRuleContext {
      public:
        TypeExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        UnderscoreContext* underscore();
        ThisContext* this_();
        PointerContext* pointer();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TypeExprContext* typeExpr();

    class UnderscoreContext: public antlr4::ParserRuleContext {
      public:
        UnderscoreContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* UNDERSCORE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    UnderscoreContext* underscore();

    class PointerContext: public antlr4::ParserRuleContext {
      public:
        PointerContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PointerContext* pointer();

    class ThisContext: public antlr4::ParserRuleContext {
      public:
        ThisContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* THIS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ThisContext* this_();

    class BinaryExprContext: public antlr4::ParserRuleContext {
      public:
        BinaryExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        AsOpContext* asOp();
        LogicalAndOpContext* logicalAndOp();
        LogicalOrOpContext* logicalOrOp();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);
        TimesOpContext* timesOp();
        DivideOpContext* divideOp();
        ModOpContext* modOp();
        BitwiseAndOpContext* bitwiseAndOp();
        LeftShiftOpContext* leftShiftOp();
        RightShiftOpContext* rightShiftOp();
        WrappingTimesOpContext* wrappingTimesOp();
        LeftRotateOpContext* leftRotateOp();
        RightRotateOpContext* rightRotateOp();
        AddOpContext* addOp();
        SubOpContext* subOp();
        BitwiseOrOpContext* bitwiseOrOp();
        XorOpContext* xorOp();
        WrappingAddOpContext* wrappingAddOp();
        WrappingSubOpContext* wrappingSubOp();
        EqualityOpContext* equalityOp();
        InequalityOpContext* inequalityOp();
        LessThanOpContext* lessThanOp();
        GreaterThanOpContext* greaterThanOp();
        LessThanOrEqualToOpContext* lessThanOrEqualToOp();
        GreaterThanOrEqualToOpContext* greaterThanOrEqualToOp();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BinaryExprContext* binaryExpr();

    class AsOpContext: public antlr4::ParserRuleContext {
      public:
        AsOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AsOpContext* asOp();

    class ConcatOpContext: public antlr4::ParserRuleContext {
      public:
        ConcatOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_PLUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ConcatOpContext* concatOp();

    class RepeatOpContext: public antlr4::ParserRuleContext {
      public:
        RepeatOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RepeatOpContext* repeatOp();

    class AddOpContext: public antlr4::ParserRuleContext {
      public:
        AddOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AddOpContext* addOp();

    class SubOpContext: public antlr4::ParserRuleContext {
      public:
        SubOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    SubOpContext* subOp();

    class TimesOpContext: public antlr4::ParserRuleContext {
      public:
        TimesOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TimesOpContext* timesOp();

    class DivideOpContext: public antlr4::ParserRuleContext {
      public:
        DivideOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SLASH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DivideOpContext* divideOp();

    class LessThanOpContext: public antlr4::ParserRuleContext {
      public:
        LessThanOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LessThanOpContext* lessThanOp();

    class GreaterThanOpContext: public antlr4::ParserRuleContext {
      public:
        GreaterThanOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GreaterThanOpContext* greaterThanOp();

    class LessThanOrEqualToOpContext: public antlr4::ParserRuleContext {
      public:
        LessThanOrEqualToOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LessThanOrEqualToOpContext* lessThanOrEqualToOp();

    class GreaterThanOrEqualToOpContext: public antlr4::ParserRuleContext {
      public:
        GreaterThanOrEqualToOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GreaterThanOrEqualToOpContext* greaterThanOrEqualToOp();

    class WrappingAddOpContext: public antlr4::ParserRuleContext {
      public:
        WrappingAddOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WrappingAddOpContext* wrappingAddOp();

    class WrappingSubOpContext: public antlr4::ParserRuleContext {
      public:
        WrappingSubOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WrappingSubOpContext* wrappingSubOp();

    class WrappingTimesOpContext: public antlr4::ParserRuleContext {
      public:
        WrappingTimesOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WrappingTimesOpContext* wrappingTimesOp();

    class LeftShiftOpContext: public antlr4::ParserRuleContext {
      public:
        LeftShiftOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LeftShiftOpContext* leftShiftOp();

    class RightShiftOpContext: public antlr4::ParserRuleContext {
      public:
        RightShiftOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RightShiftOpContext* rightShiftOp();

    class LeftRotateOpContext: public antlr4::ParserRuleContext {
      public:
        LeftRotateOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LeftRotateOpContext* leftRotateOp();

    class RightRotateOpContext: public antlr4::ParserRuleContext {
      public:
        RightRotateOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RightRotateOpContext* rightRotateOp();

    class EqualityOpContext: public antlr4::ParserRuleContext {
      public:
        EqualityOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EQUAL_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    EqualityOpContext* equalityOp();

    class InequalityOpContext: public antlr4::ParserRuleContext {
      public:
        InequalityOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* TILDE_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    InequalityOpContext* inequalityOp();

    class LogicalAndOpContext: public antlr4::ParserRuleContext {
      public:
        LogicalAndOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LogicalAndOpContext* logicalAndOp();

    class LogicalOrOpContext: public antlr4::ParserRuleContext {
      public:
        LogicalOrOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OR();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LogicalOrOpContext* logicalOrOp();

    class BitwiseAndOpContext: public antlr4::ParserRuleContext {
      public:
        BitwiseAndOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AMPERSAND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BitwiseAndOpContext* bitwiseAndOp();

    class BitwiseOrOpContext: public antlr4::ParserRuleContext {
      public:
        BitwiseOrOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PIPE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BitwiseOrOpContext* bitwiseOrOp();

    class ModOpContext: public antlr4::ParserRuleContext {
      public:
        ModOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ModOpContext* modOp();

    class XorOpContext: public antlr4::ParserRuleContext {
      public:
        XorOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CARROT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    XorOpContext* xorOp();

    class PostExprContext: public antlr4::ParserRuleContext {
      public:
        PostExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AtomContext* atom();
        PostOpContext* postOp();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PostExprContext* postExpr();

    class PostOpContext: public antlr4::ParserRuleContext {
      public:
        PostOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        PostOpContext() = default;
        void copyFrom(PostOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class AccessTypeOpContext: public PostOpContext {
      public:
        AccessTypeOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* TYPE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class TryOpContext: public PostOpContext {
      public:
        TryOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* EXCLAMATION();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AccessLengthOpContext: public PostOpContext {
      public:
        AccessLengthOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* LEN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AddressOfOpContext: public PostOpContext {
      public:
        AddressOfOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* AMPERSAND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AccessIndexOpContext: public PostOpContext {
      public:
        AccessIndexOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* OPENBRACKET();
        ExprContext* expr();
        antlr4::tree::TerminalNode* CLOSEDBRACKET();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class UnwrapOptionalOpContext: public PostOpContext {
      public:
        UnwrapOptionalOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* QUESTION();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AccessMemberOpContext: public PostOpContext {
      public:
        AccessMemberOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DereferencePointerOpContext: public PostOpContext {
      public:
        DereferencePointerOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PostOpContext* postOp();

    class PreExprContext: public antlr4::ParserRuleContext {
      public:
        PreExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        PreOpContext* preOp();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PreExprContext* preExpr();

    class PreOpContext: public antlr4::ParserRuleContext {
      public:
        PreOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        PreOpContext() = default;
        void copyFrom(PreOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class NegateOpContext: public PreOpContext {
      public:
        NegateOpContext(PreOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class NotOpContext: public PreOpContext {
      public:
        NotOpContext(PreOpContext* ctx);

        antlr4::tree::TerminalNode* TILDE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PreOpContext* preOp();

    class IfExprContext: public antlr4::ParserRuleContext {
      public:
        IfExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IF();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        std::vector<antlr4::tree::TerminalNode*> ELSEIF();
        antlr4::tree::TerminalNode* ELSEIF(size_t i);
        antlr4::tree::TerminalNode* ELSE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IfExprContext* ifExpr();

    class WhereExprContext: public antlr4::ParserRuleContext {
      public:
        WhereExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHERE();
        AtomContext* atom();
        ComparisonOpContext* comparisonOp();
        CaseExprBlockContext* caseExprBlock();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhereExprContext* whereExpr();

    class CaseExprBlockContext: public antlr4::ParserRuleContext {
      public:
        CaseExprBlockContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CaseExprBlockContext* caseExprBlock();

    class ComptExprContext: public antlr4::ParserRuleContext {
      public:
        ComptExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        ExprContext* expr();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComptExprContext* comptExpr();

    class RoutineExprContext: public antlr4::ParserRuleContext {
      public:
        RoutineExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        TypeExprContext* typeExpr();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        InlineContext* inline_();
        FastContext* fast();
        BareContext* bare();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RoutineExprContext* routineExpr();

    class StringContext: public antlr4::ParserRuleContext {
      public:
        StringContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        StringContext() = default;
        void copyFrom(StringContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class BSStringContext: public StringContext {
      public:
        BSStringContext(StringContext* ctx);

        antlr4::tree::TerminalNode* BACKSLASHSTRING();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DQStringContext: public StringContext {
      public:
        DQStringContext(StringContext* ctx);

        antlr4::tree::TerminalNode* DOUBLEQUOTESTRING();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class BTStringContext: public StringContext {
      public:
        BTStringContext(StringContext* ctx);

        antlr4::tree::TerminalNode* BACKTICKSTRING();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StringContext* string();

    class RuneContext: public antlr4::ParserRuleContext {
      public:
        RuneContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<antlr4::tree::TerminalNode*> SINGLEQUOTE();
        antlr4::tree::TerminalNode* SINGLEQUOTE(size_t i);
        TokenContext* token();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RuneContext* rune();

    class AtomContext: public antlr4::ParserRuleContext {
      public:
        AtomContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        TokenContext* token();
        TupleExprContext* tupleExpr();
        BlockExprContext* blockExpr();
        StructExprContext* structExpr();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AtomContext* atom();

    class TokenContext: public antlr4::ParserRuleContext {
      public:
        TokenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* TOKEN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TokenContext* token();

    class TupleExprContext: public antlr4::ParserRuleContext {
      public:
        TupleExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        OParenContext* oParen();
        CParenContext* cParen();
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        std::vector<ExprSepContext*> exprSep();
        ExprSepContext* exprSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TupleExprContext* tupleExpr();

    class BlockExprContext: public antlr4::ParserRuleContext {
      public:
        BlockExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        OParenContext* oParen();
        CParenContext* cParen();
        ExprContext* expr();
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BlockExprContext* blockExpr();

    class StructExprContext: public antlr4::ParserRuleContext {
      public:
        StructExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        OBraceContext* oBrace();
        CBraceContext* cBrace();
        std::vector<FieldContext*> field();
        FieldContext* field(size_t i);
        std::vector<ExprSepContext*> exprSep();
        ExprSepContext* exprSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StructExprContext* structExpr();

    class OParenContext: public antlr4::ParserRuleContext {
      public:
        OParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OPENPARENTHESIS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    OParenContext* oParen();

    class CParenContext: public antlr4::ParserRuleContext {
      public:
        CParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDPARENTHESIS();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CParenContext* cParen();

    class OBraceContext: public antlr4::ParserRuleContext {
      public:
        OBraceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OPENBRACE();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    OBraceContext* oBrace();

    class CBraceContext: public antlr4::ParserRuleContext {
      public:
        CBraceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDBRACE();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CBraceContext* cBrace();

    // By default the static state used to implement the parser is lazily initialized during the first
    // call to the constructor. You can call this function if you wish to initialize the static state
    // ahead of time.
    static void initialize();

  private:
};

} // namespace Whixy
