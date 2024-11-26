
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
        OPENPARENTHESIS = 10,
        CLOSEDPARENTHESIS = 11,
        OPENBRACE = 12,
        CLOSEDBRACE = 13,
        LESSTHAN_OPENBRACKET = 14,
        CLOSEDBRACKET_GREATERTHAN = 15,
        OPENBRACKET = 16,
        CLOSEDBRACKET = 17,
        DOT_TYPE = 18,
        DOT_LEN = 19,
        DOT_ASTERISK = 20,
        DOT_AMPERSAND = 21,
        DOT_QUESTION = 22,
        DOT = 23,
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
        EXCLAMATION_EQUAL = 50,
        EXCLAMATION = 51,
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
        PROC = 64,
        FUNC = 65,
        MUT = 66,
        INLINE = 67,
        RETURN = 68,
        CONTINUE = 69,
        BREAK = 70,
        GOTO = 71,
        WHILE = 72,
        FOR = 73,
        IF = 74,
        ELSEIF = 75,
        ELSE = 76,
        MATCH = 77,
        IS = 78,
        DEFER = 79,
        ERRDEFER = 80,
        ORELSE = 81,
        TRY = 82,
        CATCH = 83,
        IMPORT = 84,
        ALIGN = 85,
        THREADLOCAL = 86,
        UNREACHABLE = 87,
        VOLATILE = 88,
        UNROLL = 89,
        COMPT = 90,
        TEST = 91,
        ENUM = 92,
        UNION = 93,
        STD = 94,
        AS = 95,
        NEWLINE = 96,
        TOKEN = 97
    };

    enum {
        RuleSrcFile = 0,
        RuleStmt = 1,
        RuleValsStmt = 2,
        RuleCallStmt = 3,
        RuleBlockStmt = 4,
        RuleReturnStmt = 5,
        RuleFuncStmt = 6,
        RuleProcStmt = 7,
        RuleIfStmt = 8,
        RuleIsStmt = 9,
        RuleMatchStmt = 10,
        RuleWhileStmt = 11,
        RuleForStmt = 12,
        RuleComptStmt = 13,
        RuleDeferStmt = 14,
        RuleErrdeferStmt = 15,
        RuleExpr = 16,
        RuleAccessExpr = 17,
        RuleIfExpr = 18,
        RuleIsExpr = 19,
        RuleMatchExpr = 20,
        RuleWhileExpr = 21,
        RuleForExpr = 22,
        RuleFuncExpr = 23,
        RuleProcExpr = 24,
        RuleBinaryOpExpr = 25,
        RuleBinaryOp = 26,
        RuleComptExpr = 27,
        RulePreOpExpr = 28,
        RulePreOp = 29,
        RulePostOpExpr = 30,
        RulePostOp = 31,
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
        RuleOParen = 44,
        RuleCParen = 45,
        RuleOBrace = 46,
        RuleCBrace = 47,
        RuleStmtSep = 48,
        RuleExprSep = 49
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
    class CallStmtContext;
    class BlockStmtContext;
    class ReturnStmtContext;
    class FuncStmtContext;
    class ProcStmtContext;
    class IfStmtContext;
    class IsStmtContext;
    class MatchStmtContext;
    class WhileStmtContext;
    class ForStmtContext;
    class ComptStmtContext;
    class DeferStmtContext;
    class ErrdeferStmtContext;
    class ExprContext;
    class AccessExprContext;
    class IfExprContext;
    class IsExprContext;
    class MatchExprContext;
    class WhileExprContext;
    class ForExprContext;
    class FuncExprContext;
    class ProcExprContext;
    class BinaryOpExprContext;
    class BinaryOpContext;
    class ComptExprContext;
    class PreOpExprContext;
    class PreOpContext;
    class PostOpExprContext;
    class PostOpContext;
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
        CallStmtContext* callStmt();
        BlockStmtContext* blockStmt();
        ReturnStmtContext* returnStmt();
        FuncStmtContext* funcStmt();
        ProcStmtContext* procStmt();
        IfStmtContext* ifStmt();
        IsStmtContext* isStmt();
        MatchStmtContext* matchStmt();
        WhileStmtContext* whileStmt();
        ForStmtContext* forStmt();
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
        virtual size_t getRuleIndex() const override;
        OParenContext* oParen();
        CParenContext* cParen();
        std::vector<StmtContext*> stmt();
        StmtContext* stmt(size_t i);
        std::vector<StmtSepContext*> stmtSep();
        StmtSepContext* stmtSep(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BlockStmtContext* blockStmt();

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

    class FuncStmtContext: public antlr4::ParserRuleContext {
      public:
        FuncStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FUNC();
        TokenContext* token();
        TypeExprContext* typeExpr();
        TupleExprContext* tupleExpr();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* INLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    FuncStmtContext* funcStmt();

    class ProcStmtContext: public antlr4::ParserRuleContext {
      public:
        ProcStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PROC();
        TokenContext* token();
        TypeExprContext* typeExpr();
        TupleExprContext* tupleExpr();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* INLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ProcStmtContext* procStmt();

    class IfStmtContext: public antlr4::ParserRuleContext {
      public:
        IfStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IF();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);
        std::vector<BlockStmtContext*> blockStmt();
        BlockStmtContext* blockStmt(size_t i);
        std::vector<antlr4::tree::TerminalNode*> ELSEIF();
        antlr4::tree::TerminalNode* ELSEIF(size_t i);
        antlr4::tree::TerminalNode* ELSE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IfStmtContext* ifStmt();

    class IsStmtContext: public antlr4::ParserRuleContext {
      public:
        IsStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IsStmtContext* isStmt();

    class MatchStmtContext: public antlr4::ParserRuleContext {
      public:
        MatchStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MATCH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MatchStmtContext* matchStmt();

    class WhileStmtContext: public antlr4::ParserRuleContext {
      public:
        WhileStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHILE();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* UNROLL();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhileStmtContext* whileStmt();

    class ForStmtContext: public antlr4::ParserRuleContext {
      public:
        ForStmtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FOR();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* UNROLL();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ForStmtContext* forStmt();

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
        AccessExprContext* accessExpr();
        IfExprContext* ifExpr();
        IsExprContext* isExpr();
        MatchExprContext* matchExpr();
        WhileExprContext* whileExpr();
        ForExprContext* forExpr();
        FuncExprContext* funcExpr();
        ProcExprContext* procExpr();
        BinaryOpExprContext* binaryOpExpr();
        ComptExprContext* comptExpr();
        PreOpExprContext* preOpExpr();
        PostOpExprContext* postOpExpr();
        StringContext* string();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprContext* expr();

    class AccessExprContext: public antlr4::ParserRuleContext {
      public:
        AccessExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        std::vector<AtomContext*> atom();
        AtomContext* atom(size_t i);
        antlr4::tree::TerminalNode* DOT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AccessExprContext* accessExpr();

    class IfExprContext: public antlr4::ParserRuleContext {
      public:
        IfExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IF();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);
        std::vector<ExprContext*> expr();
        ExprContext* expr(size_t i);
        std::vector<antlr4::tree::TerminalNode*> ELSEIF();
        antlr4::tree::TerminalNode* ELSEIF(size_t i);
        antlr4::tree::TerminalNode* ELSE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IfExprContext* ifExpr();

    class IsExprContext: public antlr4::ParserRuleContext {
      public:
        IsExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* IS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    IsExprContext* isExpr();

    class MatchExprContext: public antlr4::ParserRuleContext {
      public:
        MatchExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MATCH();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MatchExprContext* matchExpr();

    class WhileExprContext: public antlr4::ParserRuleContext {
      public:
        WhileExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* WHILE();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);
        antlr4::tree::TerminalNode* UNROLL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    WhileExprContext* whileExpr();

    class ForExprContext: public antlr4::ParserRuleContext {
      public:
        ForExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FOR();
        std::vector<BlockExprContext*> blockExpr();
        BlockExprContext* blockExpr(size_t i);
        antlr4::tree::TerminalNode* UNROLL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ForExprContext* forExpr();

    class FuncExprContext: public antlr4::ParserRuleContext {
      public:
        FuncExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* FUNC();
        TypeExprContext* typeExpr();
        TupleExprContext* tupleExpr();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* INLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    FuncExprContext* funcExpr();

    class ProcExprContext: public antlr4::ParserRuleContext {
      public:
        ProcExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PROC();
        TypeExprContext* typeExpr();
        TupleExprContext* tupleExpr();
        BlockStmtContext* blockStmt();
        antlr4::tree::TerminalNode* INLINE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ProcExprContext* procExpr();

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

    class GreaterThanOpContext: public BinaryOpContext {
      public:
        GreaterThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftRotationAssignOpContext: public BinaryOpContext {
      public:
        LeftRotationAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ConcatenationOpContext: public BinaryOpContext {
      public:
        ConcatenationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PLUS();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ModulusAssignOpContext: public BinaryOpContext {
      public:
        ModulusAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingSubtractionAssignOpContext: public BinaryOpContext {
      public:
        WrappingSubtractionAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultiplicationOpContext: public BinaryOpContext {
      public:
        MultiplicationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingMultiplicationOpContext: public BinaryOpContext {
      public:
        WrappingMultiplicationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class MultiplicationAssignOpContext: public BinaryOpContext {
      public:
        MultiplicationAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingAdditionOpContext: public BinaryOpContext {
      public:
        WrappingAdditionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LessThanOpContext: public BinaryOpContext {
      public:
        LessThanOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN();

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

    class SubtractionAssignOpContext: public BinaryOpContext {
      public:
        SubtractionAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class InequalityOpContext: public BinaryOpContext {
      public:
        InequalityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* EXCLAMATION_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingSubtractionOpContext: public BinaryOpContext {
      public:
        WrappingSubtractionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* MINUS_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrOpContext: public BinaryOpContext {
      public:
        OrOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class OrAssignOpContext: public BinaryOpContext {
      public:
        OrAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PIPE_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftShiftAssignOpContext: public BinaryOpContext {
      public:
        LeftShiftAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingMultiplicationAssignOpContext: public BinaryOpContext {
      public:
        WrappingMultiplicationAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class EqualityOpContext: public BinaryOpContext {
      public:
        EqualityOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* EQUAL_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class DivisionAssignOpContext: public BinaryOpContext {
      public:
        DivisionAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* SLASH_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RepetitionOpContext: public BinaryOpContext {
      public:
        RepetitionOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* ASTERISK_ASTERISK();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightRotationAssignOpContext: public BinaryOpContext {
      public:
        RightRotationAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftShiftOpContext: public BinaryOpContext {
      public:
        LeftShiftOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightShiftAssignOpContext: public BinaryOpContext {
      public:
        RightShiftAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class RightRotationOpContext: public BinaryOpContext {
      public:
        RightRotationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AndAssignOpContext: public BinaryOpContext {
      public:
        AndAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class XorOpContext: public BinaryOpContext {
      public:
        XorOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LessThanEqualOpContext: public BinaryOpContext {
      public:
        LessThanEqualOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class LeftRotationOpContext: public BinaryOpContext {
      public:
        LeftRotationOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class XorAssignOpContext: public BinaryOpContext {
      public:
        XorAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* CARROT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AdditionAssignOpContext: public BinaryOpContext {
      public:
        AdditionAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class ModulusOpContext: public BinaryOpContext {
      public:
        ModulusOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PERCENT();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class AndOpContext: public BinaryOpContext {
      public:
        AndOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* AMPERSAND();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    class WrappingAdditionAssignOpContext: public BinaryOpContext {
      public:
        WrappingAdditionAssignOpContext(BinaryOpContext* ctx);

        antlr4::tree::TerminalNode* PLUS_PERCENT_EQUAL();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    BinaryOpContext* binaryOp();

    class ComptExprContext: public antlr4::ParserRuleContext {
      public:
        ComptExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        ExprContext* expr();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComptExprContext* comptExpr();

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
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

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
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

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
