
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
        RuleIfExpr = 17,
        RuleIsExpr = 18,
        RuleMatchExpr = 19,
        RuleWhileExpr = 20,
        RuleForExpr = 21,
        RuleFuncExpr = 22,
        RuleProcExpr = 23,
        RuleComptExpr = 24,
        RuleString = 25,
        RuleAtom = 26,
        RuleBlockExpr = 27,
        RuleTypeExpr = 28,
        RuleTupleExpr = 29,
        RuleToken = 30,
        RuleEof = 31,
        RuleEqual = 32,
        RuleOBracket = 33,
        RuleCBracket = 34,
        RuleOAngleBracket = 35,
        RuleCAngleBracket = 36,
        RuleOParen = 37,
        RuleCParen = 38,
        RuleOBrace = 39,
        RuleCBrace = 40,
        RuleGtGtPercentEq = 41,
        RuleGtGtPercent = 42,
        RuleGtGtEq = 43,
        RuleGtGt = 44,
        RuleGtEq = 45,
        RuleGt = 46,
        RuleLtLtPercentEq = 47,
        RuleLtLtPercent = 48,
        RuleLtLtEq = 49,
        RuleLtLt = 50,
        RuleLtEq = 51,
        RuleLt = 52,
        RuleStarPercentEq = 53,
        RuleStarPercent = 54,
        RuleStarEq = 55,
        RuleStarStar = 56,
        RuleStar = 57,
        RulePlusPercentEq = 58,
        RulePlusPercent = 59,
        RulePlusEq = 60,
        RulePlusPlus = 61,
        RulePlus = 62,
        RuleMinusPercentEq = 63,
        RuleMinusPercent = 64,
        RuleMinusEq = 65,
        RuleMinus = 66,
        RuleExclamationEq = 67,
        RuleExclamation = 68,
        RuleAmpersandEq = 69,
        RuleAmpersand = 70,
        RulePercentEq = 71,
        RulePercent = 72,
        RuleCarrotEq = 73,
        RuleCarrot = 74,
        RuleSlashEq = 75,
        RuleSlash = 76,
        RuleEqualEq = 77,
        RulePipeEq = 78,
        RulePipe = 79,
        RuleAs = 80,
        RuleStmtSep = 81,
        RuleExprSep = 82
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
    class IfExprContext;
    class IsExprContext;
    class MatchExprContext;
    class WhileExprContext;
    class ForExprContext;
    class FuncExprContext;
    class ProcExprContext;
    class ComptExprContext;
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
    class GtGtPercentEqContext;
    class GtGtPercentContext;
    class GtGtEqContext;
    class GtGtContext;
    class GtEqContext;
    class GtContext;
    class LtLtPercentEqContext;
    class LtLtPercentContext;
    class LtLtEqContext;
    class LtLtContext;
    class LtEqContext;
    class LtContext;
    class StarPercentEqContext;
    class StarPercentContext;
    class StarEqContext;
    class StarStarContext;
    class StarContext;
    class PlusPercentEqContext;
    class PlusPercentContext;
    class PlusEqContext;
    class PlusPlusContext;
    class PlusContext;
    class MinusPercentEqContext;
    class MinusPercentContext;
    class MinusEqContext;
    class MinusContext;
    class ExclamationEqContext;
    class ExclamationContext;
    class AmpersandEqContext;
    class AmpersandContext;
    class PercentEqContext;
    class PercentContext;
    class CarrotEqContext;
    class CarrotContext;
    class SlashEqContext;
    class SlashContext;
    class EqualEqContext;
    class PipeEqContext;
    class PipeContext;
    class AsContext;
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
        IfExprContext* ifExpr();
        IsExprContext* isExpr();
        MatchExprContext* matchExpr();
        WhileExprContext* whileExpr();
        ForExprContext* forExpr();
        FuncExprContext* funcExpr();
        ProcExprContext* procExpr();
        ComptExprContext* comptExpr();
        StringContext* string();
        AtomContext* atom();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExprContext* expr();

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

    class ComptExprContext: public antlr4::ParserRuleContext {
      public:
        ComptExprContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* COMPT();
        ExprContext* expr();

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ComptExprContext* comptExpr();

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

    class GtGtPercentEqContext: public antlr4::ParserRuleContext {
      public:
        GtGtPercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtGtPercentEqContext* gtGtPercentEq();

    class GtGtPercentContext: public antlr4::ParserRuleContext {
      public:
        GtGtPercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtGtPercentContext* gtGtPercent();

    class GtGtEqContext: public antlr4::ParserRuleContext {
      public:
        GtGtEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtGtEqContext* gtGtEq();

    class GtGtContext: public antlr4::ParserRuleContext {
      public:
        GtGtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_GREATERTHAN();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtGtContext* gtGt();

    class GtEqContext: public antlr4::ParserRuleContext {
      public:
        GtEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtEqContext* gtEq();

    class GtContext: public antlr4::ParserRuleContext {
      public:
        GtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* GREATERTHAN();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    GtContext* gt();

    class LtLtPercentEqContext: public antlr4::ParserRuleContext {
      public:
        LtLtPercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtLtPercentEqContext* ltLtPercentEq();

    class LtLtPercentContext: public antlr4::ParserRuleContext {
      public:
        LtLtPercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtLtPercentContext* ltLtPercent();

    class LtLtEqContext: public antlr4::ParserRuleContext {
      public:
        LtLtEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtLtEqContext* ltLtEq();

    class LtLtContext: public antlr4::ParserRuleContext {
      public:
        LtLtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_LESSTHAN();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtLtContext* ltLt();

    class LtEqContext: public antlr4::ParserRuleContext {
      public:
        LtEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtEqContext* ltEq();

    class LtContext: public antlr4::ParserRuleContext {
      public:
        LtContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* LESSTHAN();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    LtContext* lt();

    class StarPercentEqContext: public antlr4::ParserRuleContext {
      public:
        StarPercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StarPercentEqContext* starPercentEq();

    class StarPercentContext: public antlr4::ParserRuleContext {
      public:
        StarPercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StarPercentContext* starPercent();

    class StarEqContext: public antlr4::ParserRuleContext {
      public:
        StarEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StarEqContext* starEq();

    class StarStarContext: public antlr4::ParserRuleContext {
      public:
        StarStarContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK_ASTERISK();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StarStarContext* starStar();

    class StarContext: public antlr4::ParserRuleContext {
      public:
        StarContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* ASTERISK();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    StarContext* star();

    class PlusPercentEqContext: public antlr4::ParserRuleContext {
      public:
        PlusPercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PlusPercentEqContext* plusPercentEq();

    class PlusPercentContext: public antlr4::ParserRuleContext {
      public:
        PlusPercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PlusPercentContext* plusPercent();

    class PlusEqContext: public antlr4::ParserRuleContext {
      public:
        PlusEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PlusEqContext* plusEq();

    class PlusPlusContext: public antlr4::ParserRuleContext {
      public:
        PlusPlusContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS_PLUS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PlusPlusContext* plusPlus();

    class PlusContext: public antlr4::ParserRuleContext {
      public:
        PlusContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PLUS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PlusContext* plus();

    class MinusPercentEqContext: public antlr4::ParserRuleContext {
      public:
        MinusPercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS_PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MinusPercentEqContext* minusPercentEq();

    class MinusPercentContext: public antlr4::ParserRuleContext {
      public:
        MinusPercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS_PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MinusPercentContext* minusPercent();

    class MinusEqContext: public antlr4::ParserRuleContext {
      public:
        MinusEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MinusEqContext* minusEq();

    class MinusContext: public antlr4::ParserRuleContext {
      public:
        MinusContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* MINUS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    MinusContext* minus();

    class ExclamationEqContext: public antlr4::ParserRuleContext {
      public:
        ExclamationEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EXCLAMATION_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExclamationEqContext* exclamationEq();

    class ExclamationContext: public antlr4::ParserRuleContext {
      public:
        ExclamationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EXCLAMATION();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    ExclamationContext* exclamation();

    class AmpersandEqContext: public antlr4::ParserRuleContext {
      public:
        AmpersandEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AMPERSAND_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AmpersandEqContext* ampersandEq();

    class AmpersandContext: public antlr4::ParserRuleContext {
      public:
        AmpersandContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AMPERSAND();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AmpersandContext* ampersand();

    class PercentEqContext: public antlr4::ParserRuleContext {
      public:
        PercentEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PERCENT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PercentEqContext* percentEq();

    class PercentContext: public antlr4::ParserRuleContext {
      public:
        PercentContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PERCENT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PercentContext* percent();

    class CarrotEqContext: public antlr4::ParserRuleContext {
      public:
        CarrotEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CARROT_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CarrotEqContext* carrotEq();

    class CarrotContext: public antlr4::ParserRuleContext {
      public:
        CarrotContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* CARROT();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    CarrotContext* carrot();

    class SlashEqContext: public antlr4::ParserRuleContext {
      public:
        SlashEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SLASH_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    SlashEqContext* slashEq();

    class SlashContext: public antlr4::ParserRuleContext {
      public:
        SlashContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* SLASH();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    SlashContext* slash();

    class EqualEqContext: public antlr4::ParserRuleContext {
      public:
        EqualEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* EQUAL_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    EqualEqContext* equalEq();

    class PipeEqContext: public antlr4::ParserRuleContext {
      public:
        PipeEqContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PIPE_EQUAL();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PipeEqContext* pipeEq();

    class PipeContext: public antlr4::ParserRuleContext {
      public:
        PipeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* PIPE();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    PipeContext* pipe();

    class AsContext: public antlr4::ParserRuleContext {
      public:
        AsContext(antlr4::ParserRuleContext* parent, size_t invokingState);
        virtual size_t getRuleIndex() const override;
        antlr4::tree::TerminalNode* AS();
        std::vector<antlr4::tree::TerminalNode*> NEWLINE();
        antlr4::tree::TerminalNode* NEWLINE(size_t i);

        virtual std::any accept(antlr4::tree::ParseTreeVisitor* visitor) override;
    };

    AsContext* as();

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
