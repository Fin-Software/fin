
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

namespace Whixy {

class WhixyParser: public antlr4::Parser {
  public:
    enum {
        DOUBLEQUOTESTRING = 1,
        BACKTICKSTRING = 2,
        DOCCOMMENT = 3,
        COMMENT = 4,
        RUNE = 5,
        NEWLINE = 6,
        WHITESPACE = 7,
        DOT = 8,
        COMMA = 9,
        SEMICOLON = 10,
        OPENPARENTHESIS = 11,
        CLOSEDPARENTHESIS = 12,
        OPENBRACE = 13,
        CLOSEDBRACE = 14,
        OPENBRACKET = 15,
        CLOSEDBRACKET = 16,
        EXCLAMATION = 17,
        DOLLAR = 18,
        QUESTION = 19,
        GREATERTHAN_GREATERTHAN_PERCENT_EQUAL = 20,
        GREATERTHAN_GREATERTHAN_PERCENT = 21,
        GREATERTHAN_GREATERTHAN_EQUAL = 22,
        GREATERTHAN_GREATERTHAN = 23,
        GREATERTHAN_EQUAL = 24,
        GREATERTHAN = 25,
        LESSTHAN_LESSTHAN_PERCENT_EQUAL = 26,
        LESSTHAN_LESSTHAN_PERCENT = 27,
        LESSTHAN_LESSTHAN_EQUAL = 28,
        LESSTHAN_LESSTHAN = 29,
        LESSTHAN_EQUAL = 30,
        LESSTHAN = 31,
        ASTERISK_PERCENT_EQUAL = 32,
        ASTERISK_PERCENT = 33,
        ASTERISK_EQUAL = 34,
        ASTERISK_ASTERISK = 35,
        ASTERISK = 36,
        PLUS_PERCENT_EQUAL = 37,
        PLUS_PERCENT = 38,
        PLUS_EQUAL = 39,
        PLUS_PLUS = 40,
        PLUS = 41,
        MINUS_PERCENT_EQUAL = 42,
        MINUS_PERCENT = 43,
        MINUS_EQUAL = 44,
        MINUS = 45,
        TILDE_EQUAL = 46,
        TILDE = 47,
        AMPERSAND_EQUAL = 48,
        AMPERSAND = 49,
        PERCENT_EQUAL = 50,
        PERCENT = 51,
        CARROT_EQUAL = 52,
        CARROT = 53,
        SLASH_EQUAL = 54,
        SLASH = 55,
        EQUAL_EQUAL = 56,
        EQUAL = 57,
        PIPE_EQUAL = 58,
        PIPE = 59,
        TYPE = 60,
        LEN = 61,
        THIS = 62,
        AUTO = 63,
        MUT = 64,
        INLINE = 65,
        RETURN = 66,
        CONTINUE = 67,
        BREAK = 68,
        GOTO = 69,
        WHILE = 70,
        FOR = 71,
        IF = 72,
        ELSEIF = 73,
        ELSE = 74,
        WHERE = 75,
        DEFER = 76,
        ERRDEFER = 77,
        FAST = 78,
        BARE = 79,
        IMPORT = 80,
        ALIGN = 81,
        THREADL = 82,
        UNREACHABLE = 83,
        VOLATILE = 84,
        UNROLL = 85,
        COMPT = 86,
        TEST = 87,
        ENUM = 88,
        UNION = 89,
        STD = 90,
        ORELSE = 91,
        CATCH = 92,
        AS = 93,
        TOKEN = 94
    };

    enum {
        RuleSrcFile = 0,
        RuleStmtSep = 1,
        RuleStmt = 2,
        RuleField = 3,
        RuleAssignStmt = 4,
        RuleAssignOp = 5,
        RuleCall = 6,
        RuleBlockStmt = 7,
        RuleRoutineStmt = 8,
        RuleReturnStmt = 9,
        RuleIfStmt = 10,
        RuleWhereStmt = 11,
        RuleComparisonOp = 12,
        RuleCaseStmtBlock = 13,
        RuleLoopStmt = 14,
        RuleComptStmt = 15,
        RuleUnreachable = 16,
        RuleDeferStmt = 17,
        RuleErrdeferStmt = 18,
        RuleExprSep = 19,
        RuleExpr = 20,
        RuleBinaryExpr = 21,
        RuleBinaryOp = 22,
        RulePostExpr = 23,
        RulePostOp = 24,
        RulePreExpr = 25,
        RulePreOp = 26,
        RuleIfExpr = 27,
        RuleWhereExpr = 28,
        RuleCaseExprBlock = 29,
        RuleLoopExpr = 30,
        RuleComptExpr = 31,
        RuleRoutineExpr = 32,
        RuleString = 33,
        RuleAtom = 34,
        RuleToken = 35,
        RuleTupleExpr = 36,
        RuleBlockExpr = 37,
        RuleStructExpr = 38,
        RuleOParen = 39,
        RuleCParen = 40,
        RuleOBrace = 41,
        RuleCBrace = 42
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
    class AssignStmtContext;
    class AssignOpContext;
    class CallContext;
    class BlockStmtContext;
    class RoutineStmtContext;
    class ReturnStmtContext;
    class IfStmtContext;
    class WhereStmtContext;
    class ComparisonOpContext;
    class CaseStmtBlockContext;
    class LoopStmtContext;
    class ComptStmtContext;
    class UnreachableContext;
    class DeferStmtContext;
    class ErrdeferStmtContext;
    class ExprSepContext;
    class ExprContext;
    class BinaryExprContext;
    class BinaryOpContext;
    class PostExprContext;
    class PostOpContext;
    class PreExprContext;
    class PreOpContext;
    class IfExprContext;
    class WhereExprContext;
    class CaseExprBlockContext;
    class LoopExprContext;
    class ComptExprContext;
    class RoutineExprContext;
    class StringContext;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    SrcFileContext* srcFile();

    class StmtSepContext: public antlr4::ParserRuleContext {
      public:
        StmtSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SEMICOLON();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    StmtContext* stmt();

    class FieldContext: public antlr4::ParserRuleContext {
      public:
        FieldContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        FieldContext() = default;
        void copyFrom(FieldContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class MutableValsContext: public FieldContext {
      public:
        MutableValsContext(FieldContext* ctx);

        antlr4::tree::TerminalNode* MUT();
        antlr4::tree::TerminalNode* AUTO();
        antlr4::tree::TerminalNode* ASTERISK();
        antlr4::tree::TerminalNode* THIS();
        AtomContext* atom();
        std::vector<TokenContext*> token();
        TokenContext* token(size_t i);
        antlr4::tree::TerminalNode* EQUAL();
        ExprContext* expr();
        antlr4::tree::TerminalNode* NEWLINE();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class ImmutableValsContext: public FieldContext {
      public:
        ImmutableValsContext(FieldContext* ctx);

        antlr4::tree::TerminalNode* AUTO();
        antlr4::tree::TerminalNode* ASTERISK();
        antlr4::tree::TerminalNode* THIS();
        AtomContext* atom();
        std::vector<TokenContext*> token();
        TokenContext* token(size_t i);
        antlr4::tree::TerminalNode* EQUAL();
        ExprContext* expr();
        antlr4::tree::TerminalNode* NEWLINE();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    FieldContext* field();

    class AssignStmtContext: public antlr4::ParserRuleContext {
      public:
        AssignStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        AssignOpContext* assignOp();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingTimesEqualsOpContext: public AssignOpContext {
      public:
        WrappingTimesEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AndEqualsOpContext: public AssignOpContext {
      public:
        AndEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LeftRotateEqualsOpContext: public AssignOpContext {
      public:
        LeftRotateEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LeftShiftEqualsOpContext: public AssignOpContext {
      public:
        LeftShiftEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class OrEqualsOpContext: public AssignOpContext {
      public:
        OrEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class RightRotateEqualsOpContext: public AssignOpContext {
      public:
        RightRotateEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class TimesEqualsOpContext: public AssignOpContext {
      public:
        TimesEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AddEqualsOpContext: public AssignOpContext {
      public:
        AddEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class RightShiftEqualsOpContext: public AssignOpContext {
      public:
        RightShiftEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingAddEqualsOpContext: public AssignOpContext {
      public:
        WrappingAddEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class ModEqualsOpContext: public AssignOpContext {
      public:
        ModEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class DivideEqualsOpContext: public AssignOpContext {
      public:
        DivideEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingSubEqualsOpContext: public AssignOpContext {
      public:
        WrappingSubEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class XorEqualsOpContext: public AssignOpContext {
      public:
        XorEqualsOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    AssignOpContext* assignOp();

    class CallContext: public antlr4::ParserRuleContext {
      public:
        CallContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AtomContext* atom();
        ExprContext* expr();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    CallContext* call();

    class BlockStmtContext: public antlr4::ParserRuleContext {
      public:
        BlockStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        BlockStmtContext() = default;
        void copyFrom(BlockStmtContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class FuncBlockStmtContext: public BlockStmtContext {
      public:
        FuncBlockStmtContext(BlockStmtContext* ctx);

        OParenContext* oParen();
        CParenContext* cParen();
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class ProcBlockStmtContext: public BlockStmtContext {
      public:
        ProcBlockStmtContext(BlockStmtContext* ctx);

        antlr4::tree::TerminalNode* DOLLAR();
        antlr4::tree::TerminalNode* OPENPARENTHESIS();
        CParenContext* cParen();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    BlockStmtContext* blockStmt();

    class RoutineStmtContext: public antlr4::ParserRuleContext {
      public:
        RoutineStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        RoutineStmtContext() = default;
        void copyFrom(RoutineStmtContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class PlainRoutineStmtContext: public RoutineStmtContext {
      public:
        PlainRoutineStmtContext(RoutineStmtContext* ctx);

        AtomContext* atom();
        TokenContext* token();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class InlineRoutineStmtContext: public RoutineStmtContext {
      public:
        InlineRoutineStmtContext(RoutineStmtContext* ctx);

        antlr4::tree::TerminalNode* INLINE();
        AtomContext* atom();
        TokenContext* token();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    RoutineStmtContext* routineStmt();

    class ReturnStmtContext: public antlr4::ParserRuleContext {
      public:
        ReturnStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* RETURN();
        ExprContext* expr();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    WhereStmtContext* whereStmt();

    class ComparisonOpContext: public antlr4::ParserRuleContext {
      public:
        ComparisonOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ComparisonOpContext* comparisonOp();

    class CaseStmtBlockContext: public antlr4::ParserRuleContext {
      public:
        CaseStmtBlockContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    CaseStmtBlockContext* caseStmtBlock();

    class LoopStmtContext: public antlr4::ParserRuleContext {
      public:
        LoopStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        LoopStmtContext() = default;
        void copyFrom(LoopStmtContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class PlainForStmtContext: public LoopStmtContext {
      public:
        PlainForStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* FOR();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class UnrollWhileStmtContext: public LoopStmtContext {
      public:
        UnrollWhileStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* WHILE();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class PlainWhileStmtContext: public LoopStmtContext {
      public:
        PlainWhileStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* WHILE();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class UnrollForStmtContext: public LoopStmtContext {
      public:
        UnrollForStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* FOR();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    LoopStmtContext* loopStmt();

    class ComptStmtContext: public antlr4::ParserRuleContext {
      public:
        ComptStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        StmtContext* stmt();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ComptStmtContext* comptStmt();

    class UnreachableContext: public antlr4::ParserRuleContext {
      public:
        UnreachableContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* UNREACHABLE();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    UnreachableContext* unreachable();

    class DeferStmtContext: public antlr4::ParserRuleContext {
      public:
        DeferStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* DEFER();
        StmtContext* stmt();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    DeferStmtContext* deferStmt();

    class ErrdeferStmtContext: public antlr4::ParserRuleContext {
      public:
        ErrdeferStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ERRDEFER();
        StmtContext* stmt();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ErrdeferStmtContext* errdeferStmt();

    class ExprSepContext: public antlr4::ParserRuleContext {
      public:
        ExprSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMMA();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ExprSepContext* exprSep();

    class ExprContext: public antlr4::ParserRuleContext {
      public:
        ExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        FieldContext* field();
        CallContext* call();
        BinaryExprContext* binaryExpr();
        PostExprContext* postExpr();
        PreExprContext* preExpr();
        IfExprContext* ifExpr();
        WhereExprContext* whereExpr();
        LoopExprContext* loopExpr();
        ComptExprContext* comptExpr();
        UnreachableContext* unreachable();
        RoutineExprContext* routineExpr();
        StringContext* string();
        AtomContext* atom();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ExprContext* expr();

    class BinaryExprContext: public antlr4::ParserRuleContext {
      public:
        BinaryExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        BinaryOpContext* binaryOp();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    BinaryExprContext* binaryExpr();

    class BinaryOpContext: public antlr4::ParserRuleContext {
      public:
        BinaryOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        BinaryOpContext() = default;
        void copyFrom(BinaryOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class GreaterThanOrEqualToOpContext: public BinaryOpContext {
      public:
        GreaterThanOrEqualToOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class GreaterThanOpContext: public BinaryOpContext {
      public:
        GreaterThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class EqualityOpContext: public BinaryOpContext {
      public:
        EqualityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* EQUAL_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LeftRotateOpContext: public BinaryOpContext {
      public:
        LeftRotateOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AddOpContext: public BinaryOpContext {
      public:
        AddOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class TimesOpContext: public BinaryOpContext {
      public:
        TimesOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class SubOpContext: public BinaryOpContext {
      public:
        SubOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingAddOpContext: public BinaryOpContext {
      public:
        WrappingAddOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LeftShiftOpContext: public BinaryOpContext {
      public:
        LeftShiftOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class ConcatOpContext: public BinaryOpContext {
      public:
        ConcatOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PLUS();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class RepeatOpContext: public BinaryOpContext {
      public:
        RepeatOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_ASTERISK();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class DivideOpContext: public BinaryOpContext {
      public:
        DivideOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class OrOpContext: public BinaryOpContext {
      public:
        OrOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class ModOpContext: public BinaryOpContext {
      public:
        ModOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AndOpContext: public BinaryOpContext {
      public:
        AndOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class XorOpContext: public BinaryOpContext {
      public:
        XorOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingSubOpContext: public BinaryOpContext {
      public:
        WrappingSubOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LessThanOpContext: public BinaryOpContext {
      public:
        LessThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class RightShiftOpContext: public BinaryOpContext {
      public:
        RightShiftOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class LessThanOrEqualToOpContext: public BinaryOpContext {
      public:
        LessThanOrEqualToOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class WrappingTimesOpContext: public BinaryOpContext {
      public:
        WrappingTimesOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class RightRotateOpContext: public BinaryOpContext {
      public:
        RightRotateOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AsOpContext: public BinaryOpContext {
      public:
        AsOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AS();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class InequalityOpContext: public BinaryOpContext {
      public:
        InequalityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* TILDE_EQUAL();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    BinaryOpContext* binaryOp();

    class PostExprContext: public antlr4::ParserRuleContext {
      public:
        PostExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AtomContext* atom();
        PostOpContext* postOp();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class TryOpContext: public PostOpContext {
      public:
        TryOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* EXCLAMATION();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AccessLengthOpContext: public PostOpContext {
      public:
        AccessLengthOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* LEN();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AddressOfOpContext: public PostOpContext {
      public:
        AddressOfOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* AMPERSAND();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AccessIndexOpContext: public PostOpContext {
      public:
        AccessIndexOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* OPENBRACKET();
        ExprContext* expr();
        antlr4::tree::TerminalNode* CLOSEDBRACKET();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class UnwrapOptionalOpContext: public PostOpContext {
      public:
        UnwrapOptionalOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* QUESTION();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class AccessMemberOpContext: public PostOpContext {
      public:
        AccessMemberOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        AtomContext* atom();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class DereferencePointerOpContext: public PostOpContext {
      public:
        DereferencePointerOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        antlr4::tree::TerminalNode* ASTERISK();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    PostOpContext* postOp();

    class PreExprContext: public antlr4::ParserRuleContext {
      public:
        PreExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        PreOpContext* preOp();
        AtomContext* atom();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class NotOpContext: public PreOpContext {
      public:
        NotOpContext(PreOpContext* ctx);

        antlr4::tree::TerminalNode* TILDE();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    WhereExprContext* whereExpr();

    class CaseExprBlockContext: public antlr4::ParserRuleContext {
      public:
        CaseExprBlockContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    CaseExprBlockContext* caseExprBlock();

    class LoopExprContext: public antlr4::ParserRuleContext {
      public:
        LoopExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        LoopExprContext() = default;
        void copyFrom(LoopExprContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class UnrollWhileExprContext: public LoopExprContext {
      public:
        UnrollWhileExprContext(LoopExprContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* WHILE();
        ExprContext* expr();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class UnrollForExprContext: public LoopExprContext {
      public:
        UnrollForExprContext(LoopExprContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* FOR();
        ExprContext* expr();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class PlainForExprContext: public LoopExprContext {
      public:
        PlainForExprContext(LoopExprContext* ctx);

        antlr4::tree::TerminalNode* FOR();
        ExprContext* expr();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class PlainWhileExprContext: public LoopExprContext {
      public:
        PlainWhileExprContext(LoopExprContext* ctx);

        antlr4::tree::TerminalNode* WHILE();
        ExprContext* expr();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    LoopExprContext* loopExpr();

    class ComptExprContext: public antlr4::ParserRuleContext {
      public:
        ComptExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        ExprContext* expr();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    ComptExprContext* comptExpr();

    class RoutineExprContext: public antlr4::ParserRuleContext {
      public:
        RoutineExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        RoutineExprContext() = default;
        void copyFrom(RoutineExprContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class InlineRoutineExprContext: public RoutineExprContext {
      public:
        InlineRoutineExprContext(RoutineExprContext* ctx);

        antlr4::tree::TerminalNode* INLINE();
        AtomContext* atom();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class PlainRoutineExprContext: public RoutineExprContext {
      public:
        PlainRoutineExprContext(RoutineExprContext* ctx);

        AtomContext* atom();
        StructExprContext* structExpr();
        BlockStmtContext* blockStmt();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

    class DQStringExprContext: public StringContext {
      public:
        DQStringExprContext(StringContext* ctx);

        antlr4::tree::TerminalNode* DOUBLEQUOTESTRING();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    class BTStringExprContext: public StringContext {
      public:
        BTStringExprContext(StringContext* ctx);

        antlr4::tree::TerminalNode* BACKTICKSTRING();
        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    StringContext* string();

    class AtomContext: public antlr4::ParserRuleContext {
      public:
        AtomContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        TokenContext* token();
        TupleExprContext* tupleExpr();
        BlockExprContext* blockExpr();
        StructExprContext* structExpr();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    AtomContext* atom();

    class TokenContext: public antlr4::ParserRuleContext {
      public:
        TokenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* TOKEN();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
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

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    StructExprContext* structExpr();

    class OParenContext: public antlr4::ParserRuleContext {
      public:
        OParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OPENPARENTHESIS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    OParenContext* oParen();

    class CParenContext: public antlr4::ParserRuleContext {
      public:
        CParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDPARENTHESIS();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    CParenContext* cParen();

    class OBraceContext: public antlr4::ParserRuleContext {
      public:
        OBraceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OPENBRACE();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    OBraceContext* oBrace();

    class CBraceContext: public antlr4::ParserRuleContext {
      public:
        CBraceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDBRACE();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual void enterRule(antlr4::tree::ParseTreeListener* listener) override;
        virtual void exitRule(antlr4::tree::ParseTreeListener* listener) override;
    };

    CBraceContext* cBrace();

    // By default the static state used to implement the parser is lazily initialized during the first
    // call to the constructor. You can call this function if you wish to initialize the static state
    // ahead of time.
    static void initialize();

  private:
};

} // namespace Whixy
