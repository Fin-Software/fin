
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
        WHITESPACE = 5,
        COLON = 6,
        COMMA = 7,
        SEMICOLON = 8,
        QUESTION = 9,
        DOLLAR_OPENPARENTHESIS = 10,
        OPENPARENTHESIS = 11,
        CLOSEDPARENTHESIS = 12,
        OPENBRACE = 13,
        CLOSEDBRACE = 14,
        LESSTHAN_OPENBRACKET = 15,
        CLOSEDBRACKET_GREATERTHAN = 16,
        OPENBRACKET = 17,
        CLOSEDBRACKET = 18,
        DOT_TYPE = 19,
        DOT_LEN = 20,
        DOT_ASTERISK = 21,
        DOT_AMPERSAND = 22,
        DOT_QUESTION = 23,
        DOT = 24,
        GREATERTHAN_GREATERTHAN_PERCENT_EQUAL = 25,
        GREATERTHAN_GREATERTHAN_PERCENT = 26,
        GREATERTHAN_GREATERTHAN_EQUAL = 27,
        GREATERTHAN_GREATERTHAN = 28,
        GREATERTHAN_EQUAL = 29,
        GREATERTHAN = 30,
        LESSTHAN_LESSTHAN_PERCENT_EQUAL = 31,
        LESSTHAN_LESSTHAN_PERCENT = 32,
        LESSTHAN_LESSTHAN_EQUAL = 33,
        LESSTHAN_LESSTHAN = 34,
        LESSTHAN_EQUAL = 35,
        LESSTHAN = 36,
        ASTERISK_PERCENT_EQUAL = 37,
        ASTERISK_PERCENT = 38,
        ASTERISK_EQUAL = 39,
        ASTERISK_ASTERISK = 40,
        ASTERISK = 41,
        PLUS_PERCENT_EQUAL = 42,
        PLUS_PERCENT = 43,
        PLUS_EQUAL = 44,
        PLUS_PLUS = 45,
        PLUS = 46,
        MINUS_PERCENT_EQUAL = 47,
        MINUS_PERCENT = 48,
        MINUS_EQUAL = 49,
        MINUS = 50,
        EXCLAMATION_EQUAL = 51,
        EXCLAMATION = 52,
        AMPERSAND_EQUAL = 53,
        AMPERSAND = 54,
        PERCENT_EQUAL = 55,
        PERCENT = 56,
        CARROT_EQUAL = 57,
        CARROT = 58,
        SLASH_EQUAL = 59,
        SLASH = 60,
        EQUAL_EQUAL = 61,
        EQUAL = 62,
        PIPE_EQUAL = 63,
        PIPE = 64,
        MUT = 65,
        INLINE = 66,
        RETURN = 67,
        CONTINUE = 68,
        BREAK = 69,
        GOTO = 70,
        WHILE = 71,
        FOR = 72,
        IF = 73,
        ELSEIF = 74,
        ELSE = 75,
        MATCH = 76,
        WHERE = 77,
        DEFER = 78,
        ERRDEFER = 79,
        ORELSE = 80,
        TRY = 81,
        CATCH = 82,
        IMPORT = 83,
        ALIGN = 84,
        THREADLOCAL = 85,
        UNREACHABLE = 86,
        VOLATILE = 87,
        UNROLL = 88,
        COMPT = 89,
        TEST = 90,
        ENUM = 91,
        UNION = 92,
        STD = 93,
        AS = 94,
        NEWLINE = 95,
        TOKEN = 96
    };

    enum {
        RuleSrcFile = 0,
        RuleStmt = 1,
        RuleValsStmt = 2,
        RuleAssignOpStmt = 3,
        RuleAssignOp = 4,
        RuleCallStmt = 5,
        RuleBlockStmt = 6,
        RuleRoutineStmt = 7,
        RuleReturnStmt = 8,
        RuleIfStmt = 9,
        RuleWhereStmt = 10,
        RuleComparisonOp = 11,
        RuleCaseStmtBlock = 12,
        RuleMatchStmt = 13,
        RuleLoopStmt = 14,
        RuleComptStmt = 15,
        RuleDeferStmt = 16,
        RuleErrdeferStmt = 17,
        RuleExpr = 18,
        RuleBinaryOpExpr = 19,
        RuleBinaryOp = 20,
        RulePostOpExpr = 21,
        RulePostOp = 22,
        RulePreOpExpr = 23,
        RulePreOp = 24,
        RuleIfExpr = 25,
        RuleWhereExpr = 26,
        RuleCaseExprBlock = 27,
        RuleMatchExpr = 28,
        RuleLoopExpr = 29,
        RuleComptExpr = 30,
        RuleRoutineExpr = 31,
        RuleString = 32,
        RuleAtom = 33,
        RuleBlockExpr = 34,
        RuleTypeExpr = 35,
        RuleTupleExpr = 36,
        RuleToken = 37,
        RuleEof = 38,
        RuleEqual = 39,
        RuleOBracket = 40,
        RuleCBracket = 41,
        RuleOAngleBracket = 42,
        RuleCAngleBracket = 43,
        RuleDollarParen = 44,
        RuleOParen = 45,
        RuleCParen = 46,
        RuleOBrace = 47,
        RuleCBrace = 48,
        RuleStmtSep = 49,
        RuleExprSep = 50
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
    class StmtContext;
    class ValsStmtContext;
    class AssignOpStmtContext;
    class AssignOpContext;
    class CallStmtContext;
    class BlockStmtContext;
    class RoutineStmtContext;
    class ReturnStmtContext;
    class IfStmtContext;
    class WhereStmtContext;
    class ComparisonOpContext;
    class CaseStmtBlockContext;
    class MatchStmtContext;
    class LoopStmtContext;
    class ComptStmtContext;
    class DeferStmtContext;
    class ErrdeferStmtContext;
    class ExprContext;
    class BinaryOpExprContext;
    class BinaryOpContext;
    class PostOpExprContext;
    class PostOpContext;
    class PreOpExprContext;
    class PreOpContext;
    class IfExprContext;
    class WhereExprContext;
    class CaseExprBlockContext;
    class MatchExprContext;
    class LoopExprContext;
    class ComptExprContext;
    class RoutineExprContext;
    class StringContext;
    class AtomContext;
    class BlockExprContext;
    class TypeExprContext;
    class TupleExprContext;
    class TokenContext;
    class EofContext;
    class EqualContext;
    class OBracketContext;
    class CBracketContext;
    class OAngleBracketContext;
    class CAngleBracketContext;
    class DollarParenContext;
    class OParenContext;
    class CParenContext;
    class OBraceContext;
    class CBraceContext;
    class StmtSepContext;
    class ExprSepContext;

    class SrcFileContext: public antlr4::ParserRuleContext {
      public:
        SrcFileContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        EofContext* eof();
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    SrcFileContext* srcFile();

    class StmtContext: public antlr4::ParserRuleContext {
      public:
        StmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ValsStmtContext* valsStmt();
        AssignOpStmtContext* assignOpStmt();
        CallStmtContext* callStmt();
        BlockStmtContext* blockStmt();
        RoutineStmtContext* routineStmt();
        ReturnStmtContext* returnStmt();
        IfStmtContext* ifStmt();
        WhereStmtContext* whereStmt();
        MatchStmtContext* matchStmt();
        LoopStmtContext* loopStmt();
        ComptStmtContext* comptStmt();
        DeferStmtContext* deferStmt();
        ErrdeferStmtContext* errdeferStmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StmtContext* stmt();

    class ValsStmtContext: public antlr4::ParserRuleContext {
      public:
        ValsStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COLON();
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        std::vector<TokenContext*> token();
        TokenContext* token(size_t i);
        antlr4::tree::TerminalNode* EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ValsStmtContext* valsStmt();

    class AssignOpStmtContext: public antlr4::ParserRuleContext {
      public:
        AssignOpStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AssignOpContext* assignOp();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AssignOpStmtContext* assignOpStmt();

    class AssignOpContext: public antlr4::ParserRuleContext {
      public:
        AssignOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        AssignOpContext() = default;
        void copyFrom(AssignOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class LeftShiftAssignOpContext: public AssignOpContext {
      public:
        LeftShiftAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingMultiplicationAssignOpContext: public AssignOpContext {
      public:
        WrappingMultiplicationAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftRotationAssignOpContext: public AssignOpContext {
      public:
        LeftRotationAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AndAssignOpContext: public AssignOpContext {
      public:
        AndAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DivisionAssignOpContext: public AssignOpContext {
      public:
        DivisionAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ModulusAssignOpContext: public AssignOpContext {
      public:
        ModulusAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightRotationAssignOpContext: public AssignOpContext {
      public:
        RightRotationAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightShiftAssignOpContext: public AssignOpContext {
      public:
        RightShiftAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingSubtractionAssignOpContext: public AssignOpContext {
      public:
        WrappingSubtractionAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrAssignOpContext: public AssignOpContext {
      public:
        OrAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultiplicationAssignOpContext: public AssignOpContext {
      public:
        MultiplicationAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class XorAssignOpContext: public AssignOpContext {
      public:
        XorAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AdditionAssignOpContext: public AssignOpContext {
      public:
        AdditionAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class SubtractionAssignOpContext: public AssignOpContext {
      public:
        SubtractionAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingAdditionAssignOpContext: public AssignOpContext {
      public:
        WrappingAdditionAssignOpContext(AssignOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AssignOpContext* assignOp();

    class CallStmtContext: public antlr4::ParserRuleContext {
      public:
        CallStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CallStmtContext* callStmt();

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

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ProcBlockStmtContext: public BlockStmtContext {
      public:
        ProcBlockStmtContext(BlockStmtContext* ctx);

        DollarParenContext* dollarParen();
        CParenContext* cParen();
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
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

        TokenContext* token();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        BlockStmtContext* blockStmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class InlineRoutineStmtContext: public RoutineStmtContext {
      public:
        InlineRoutineStmtContext(RoutineStmtContext* ctx);

        antlr4::tree::TerminalNode* INLINE();
        TokenContext* token();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        BlockStmtContext* blockStmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    RoutineStmtContext* routineStmt();

    class ReturnStmtContext: public antlr4::ParserRuleContext {
      public:
        ReturnStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* RETURN();
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
        std::vector<BlockStmtContext*> blockStmt();
        BlockStmtContext* blockStmt(size_t i);
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

    class MatchStmtContext: public antlr4::ParserRuleContext {
      public:
        MatchStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MATCH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MatchStmtContext* matchStmt();

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

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class UnrollWhileStmtContext: public LoopStmtContext {
      public:
        UnrollWhileStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* WHILE();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class PlainWhileStmtContext: public LoopStmtContext {
      public:
        PlainWhileStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* WHILE();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class UnrollForStmtContext: public LoopStmtContext {
      public:
        UnrollForStmtContext(LoopStmtContext* ctx);

        antlr4::tree::TerminalNode* UNROLL();
        antlr4::tree::TerminalNode* FOR();
        StmtContext* stmt();
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LoopStmtContext* loopStmt();

    class ComptStmtContext: public antlr4::ParserRuleContext {
      public:
        ComptStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        StmtContext* stmt();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComptStmtContext* comptStmt();

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

    class ExprContext: public antlr4::ParserRuleContext {
      public:
        ExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        ValsStmtContext* valsStmt();
        CallStmtContext* callStmt();
        BinaryOpExprContext* binaryOpExpr();
        PostOpExprContext* postOpExpr();
        PreOpExprContext* preOpExpr();
        IfExprContext* ifExpr();
        WhereExprContext* whereExpr();
        MatchExprContext* matchExpr();
        LoopExprContext* loopExpr();
        ComptExprContext* comptExpr();
        RoutineExprContext* routineExpr();
        StringContext* string();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprContext* expr();

    class BinaryOpExprContext: public antlr4::ParserRuleContext {
      public:
        BinaryOpExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        BinaryOpContext* binaryOp();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BinaryOpExprContext* binaryOpExpr();

    class BinaryOpContext: public antlr4::ParserRuleContext {
      public:
        BinaryOpContext(antlr4::ParserRuleContext* parent, size_t invokingState);

        BinaryOpContext() = default;
        void copyFrom(BinaryOpContext* context);
        using antlr4::ParserRuleContext::copyFrom;

        virtual size_t getRuleIndex() const override;
    };

    class WrappingSubtractionOpContext: public BinaryOpContext {
      public:
        WrappingSubtractionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class GreaterThanOpContext: public BinaryOpContext {
      public:
        GreaterThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class EqualityOpContext: public BinaryOpContext {
      public:
        EqualityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* EQUAL_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ConcatenationOpContext: public BinaryOpContext {
      public:
        ConcatenationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PLUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RepetitionOpContext: public BinaryOpContext {
      public:
        RepetitionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftShiftOpContext: public BinaryOpContext {
      public:
        LeftShiftOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultiplicationOpContext: public BinaryOpContext {
      public:
        MultiplicationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightRotationOpContext: public BinaryOpContext {
      public:
        RightRotationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingMultiplicationOpContext: public BinaryOpContext {
      public:
        WrappingMultiplicationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrOpContext: public BinaryOpContext {
      public:
        OrOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LessThanEqualOpContext: public BinaryOpContext {
      public:
        LessThanEqualOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AndOpContext: public BinaryOpContext {
      public:
        AndOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingAdditionOpContext: public BinaryOpContext {
      public:
        WrappingAdditionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class XorOpContext: public BinaryOpContext {
      public:
        XorOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LessThanOpContext: public BinaryOpContext {
      public:
        LessThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftRotationOpContext: public BinaryOpContext {
      public:
        LeftRotationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class SubtractionOpContext: public BinaryOpContext {
      public:
        SubtractionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightShiftOpContext: public BinaryOpContext {
      public:
        RightShiftOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class GreaterThanEqualOpContext: public BinaryOpContext {
      public:
        GreaterThanEqualOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ModulusOpContext: public BinaryOpContext {
      public:
        ModulusOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AdditionOpContext: public BinaryOpContext {
      public:
        AdditionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DivisionOpContext: public BinaryOpContext {
      public:
        DivisionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AsOpContext: public BinaryOpContext {
      public:
        AsOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class InequalityOpContext: public BinaryOpContext {
      public:
        InequalityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* EXCLAMATION_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BinaryOpContext* binaryOp();

    class PostOpExprContext: public antlr4::ParserRuleContext {
      public:
        PostOpExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        AtomContext* atom();
        PostOpContext* postOp();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PostOpExprContext* postOpExpr();

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

        antlr4::tree::TerminalNode* DOT_TYPE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AccessLengthOpContext: public PostOpContext {
      public:
        AccessLengthOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT_LEN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AddressOfOpContext: public PostOpContext {
      public:
        AddressOfOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT_AMPERSAND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AccessFieldOpContext: public PostOpContext {
      public:
        AccessFieldOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class UnwrapOptionalOpContext: public PostOpContext {
      public:
        UnwrapOptionalOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT_QUESTION();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DereferencePointerOpContext: public PostOpContext {
      public:
        DereferencePointerOpContext(PostOpContext* ctx);

        antlr4::tree::TerminalNode* DOT_ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PostOpContext* postOp();

    class PreOpExprContext: public antlr4::ParserRuleContext {
      public:
        PreOpExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        PreOpContext* preOp();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PreOpExprContext* preOpExpr();

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

        antlr4::tree::TerminalNode* EXCLAMATION();

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

    class MatchExprContext: public antlr4::ParserRuleContext {
      public:
        MatchExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MATCH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MatchExprContext* matchExpr();

    class LoopExprContext: public antlr4::ParserRuleContext {
      public:
        LoopExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LoopExprContext* loopExpr();

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

    class DQStringExprContext: public StringContext {
      public:
        DQStringExprContext(StringContext* ctx);

        antlr4::tree::TerminalNode* DOUBLEQUOTESTRING();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class BTStringExprContext: public StringContext {
      public:
        BTStringExprContext(StringContext* ctx);

        antlr4::tree::TerminalNode* BACKTICKSTRING();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StringContext* string();

    class AtomContext: public antlr4::ParserRuleContext {
      public:
        AtomContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        BlockExprContext* blockExpr();
        TypeExprContext* typeExpr();
        TupleExprContext* tupleExpr();
        TokenContext* token();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AtomContext* atom();

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

    class TypeExprContext: public antlr4::ParserRuleContext {
      public:
        TypeExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        OBraceContext* oBrace();
        CBraceContext* cBrace();
        std::vector<ValsStmtContext*> valsStmt();
        ValsStmtContext* valsStmt(size_t i);
        std::vector<ExprSepContext*> exprSep();
        ExprSepContext* exprSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TypeExprContext* typeExpr();

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

    class TokenContext: public antlr4::ParserRuleContext {
      public:
        TokenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* TOKEN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    TokenContext* token();

    class EofContext: public antlr4::ParserRuleContext {
      public:
        EofContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EOF();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    EofContext* eof();

    class EqualContext: public antlr4::ParserRuleContext {
      public:
        EqualContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EQUAL();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    EqualContext* equal();

    class OBracketContext: public antlr4::ParserRuleContext {
      public:
        OBracketContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* OPENBRACKET();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    OBracketContext* oBracket();

    class CBracketContext: public antlr4::ParserRuleContext {
      public:
        CBracketContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDBRACKET();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CBracketContext* cBracket();

    class OAngleBracketContext: public antlr4::ParserRuleContext {
      public:
        OAngleBracketContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_OPENBRACKET();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    OAngleBracketContext* oAngleBracket();

    class CAngleBracketContext: public antlr4::ParserRuleContext {
      public:
        CAngleBracketContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CLOSEDBRACKET_GREATERTHAN();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CAngleBracketContext* cAngleBracket();

    class DollarParenContext: public antlr4::ParserRuleContext {
      public:
        DollarParenContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* DOLLAR_OPENPARENTHESIS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    DollarParenContext* dollarParen();

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

    class StmtSepContext: public antlr4::ParserRuleContext {
      public:
        StmtSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SEMICOLON();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StmtSepContext* stmtSep();

    class ExprSepContext: public antlr4::ParserRuleContext {
      public:
        ExprSepContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMMA();
        antlr4::tree::TerminalNode* NEWLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprSepContext* exprSep();

    // By default the static state used to implement the parser is lazily initialized during the first
    // call to the constructor. You can call this function if you wish to initialize the static state
    // ahead of time.
    static void initialize();

  private:
};

} // namespace Whixy
