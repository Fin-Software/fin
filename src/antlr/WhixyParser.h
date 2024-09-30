
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

namespace Whixy {

class WhixyParser : public antlr4::Parser {
  public:
    enum {
	COMMENT = 1,
	STRING = 2,
	DEFER = 3,
	ELSE = 4,
	ENUM = 5,
	ERRDEFER = 6,
	FOR = 7,
	FUNC = 8,
	IF = 9,
	IMPORT = 10,
	IS = 11,
	PROC = 12,
	STD = 13,
	TEST = 14,
	UNION = 15,
	VAL = 16,
	WHILE = 17,
	ALIGN = 18,
	BREAK = 19,
	CATCH = 20,
	COMPT = 21,
	CONTINUE = 22,
	INLINE = 23,
	MUT = 24,
	ORELSE = 25,
	RETURN = 26,
	THREADLOCAL = 27,
	TRY = 28,
	UNROLL = 29,
	VOLATILE = 30,
	ID = 31,
	INTEGER = 32,
	EXP_SEP = 33,
	STMT_SEP = 34,
	OBRACE = 35,
	CBRACE = 36,
	OPAREN = 37,
	CPAREN = 38,
	COLON = 39,
	EQ = 40,
	NL = 41,
	WS = 42
    };

    enum {
	RuleSrcFile = 0,
	RuleStatement = 1,
	RuleValStmt = 2,
	RuleExpression = 3,
	RuleBlockExpr = 4,
	RuleValsExpr = 5,
	RuleProcedureExpr = 6,
	RuleFunctionExpr = 7,
	RuleTypeExpr = 8,
	RuleTupleExpr = 9,
	RuleCallExpr = 10,
	RuleEndOfExp = 11,
	RuleEndOfStmt = 12
    };

    explicit WhixyParser(antlr4::TokenStream *input);

    WhixyParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

    ~WhixyParser() override;

    std::string getGrammarFileName() const override;

    const antlr4::atn::ATN &getATN() const override;

    const std::vector<std::string> &getRuleNames() const override;

    const antlr4::dfa::Vocabulary &getVocabulary() const override;

    antlr4::atn::SerializedATNView getSerializedATN() const override;

    class SrcFileContext;
    class StatementContext;
    class ValStmtContext;
    class ExpressionContext;
    class BlockExprContext;
    class ValsExprContext;
    class ProcedureExprContext;
    class FunctionExprContext;
    class TypeExprContext;
    class TupleExprContext;
    class CallExprContext;
    class EndOfExpContext;
    class EndOfStmtContext;

    class SrcFileContext : public antlr4::ParserRuleContext {
      public:
	SrcFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	std::vector<StatementContext *> statement();
	StatementContext *statement(size_t i);

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    SrcFileContext *srcFile();

    class StatementContext : public antlr4::ParserRuleContext {
      public:
	StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	ValStmtContext *valStmt();
	BlockExprContext *blockExpr();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    StatementContext *statement();

    class ValStmtContext : public antlr4::ParserRuleContext {
      public:
	ValStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *VAL();
	ValsExprContext *valsExpr();
	EndOfStmtContext *endOfStmt();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    ValStmtContext *valStmt();

    class ExpressionContext : public antlr4::ParserRuleContext {
      public:
	ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	BlockExprContext *blockExpr();
	ValsExprContext *valsExpr();
	ProcedureExprContext *procedureExpr();
	FunctionExprContext *functionExpr();
	TypeExprContext *typeExpr();
	TupleExprContext *tupleExpr();
	CallExprContext *callExpr();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    ExpressionContext *expression();

    class BlockExprContext : public antlr4::ParserRuleContext {
      public:
	BlockExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *OBRACE();
	antlr4::tree::TerminalNode *CBRACE();
	std::vector<StatementContext *> statement();
	StatementContext *statement(size_t i);
	std::vector<EndOfStmtContext *> endOfStmt();
	EndOfStmtContext *endOfStmt(size_t i);

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    BlockExprContext *blockExpr();

    class ValsExprContext : public antlr4::ParserRuleContext {
      public:
	ValsExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	std::vector<antlr4::tree::TerminalNode *> ID();
	antlr4::tree::TerminalNode *ID(size_t i);
	antlr4::tree::TerminalNode *COLON();
	std::vector<ExpressionContext *> expression();
	ExpressionContext *expression(size_t i);
	antlr4::tree::TerminalNode *EQ();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    ValsExprContext *valsExpr();

    class ProcedureExprContext : public antlr4::ParserRuleContext {
      public:
	ProcedureExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *PROC();
	TypeExprContext *typeExpr();
	ExpressionContext *expression();
	BlockExprContext *blockExpr();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    ProcedureExprContext *procedureExpr();

    class FunctionExprContext : public antlr4::ParserRuleContext {
      public:
	FunctionExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *FUNC();
	TypeExprContext *typeExpr();
	ExpressionContext *expression();
	BlockExprContext *blockExpr();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    FunctionExprContext *functionExpr();

    class TypeExprContext : public antlr4::ParserRuleContext {
      public:
	TypeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *OBRACE();
	antlr4::tree::TerminalNode *CBRACE();
	std::vector<ValsExprContext *> valsExpr();
	ValsExprContext *valsExpr(size_t i);
	std::vector<EndOfExpContext *> endOfExp();
	EndOfExpContext *endOfExp(size_t i);

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    TypeExprContext *typeExpr();

    class TupleExprContext : public antlr4::ParserRuleContext {
      public:
	TupleExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *OPAREN();
	antlr4::tree::TerminalNode *CPAREN();
	std::vector<ExpressionContext *> expression();
	ExpressionContext *expression(size_t i);
	std::vector<EndOfExpContext *> endOfExp();
	EndOfExpContext *endOfExp(size_t i);

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    TupleExprContext *tupleExpr();

    class CallExprContext : public antlr4::ParserRuleContext {
      public:
	CallExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *ID();
	TupleExprContext *tupleExpr();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    CallExprContext *callExpr();

    class EndOfExpContext : public antlr4::ParserRuleContext {
      public:
	EndOfExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *EXP_SEP();
	antlr4::tree::TerminalNode *NL();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    EndOfExpContext *endOfExp();

    class EndOfStmtContext : public antlr4::ParserRuleContext {
      public:
	EndOfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
	virtual size_t getRuleIndex() const override;
	antlr4::tree::TerminalNode *STMT_SEP();
	antlr4::tree::TerminalNode *NL();

	virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
	virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
    };

    EndOfStmtContext *endOfStmt();

    // By default the static state used to implement the parser is lazily initialized during the
    // first call to the constructor. You can call this function if you wish to initialize the
    // static state ahead of time.
    static void initialize();

  private:
};

} // namespace Whixy
