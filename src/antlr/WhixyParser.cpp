
// Generated from WhixyParser.g4 by ANTLR 4.13.2


#include "WhixyParserListener.h"

#include "WhixyParser.h"


using namespace antlrcpp;
using namespace Whixy;

using namespace antlr4;

namespace {

struct WhixyParserStaticData final {
  WhixyParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  WhixyParserStaticData(const WhixyParserStaticData&) = delete;
  WhixyParserStaticData(WhixyParserStaticData&&) = delete;
  WhixyParserStaticData& operator=(const WhixyParserStaticData&) = delete;
  WhixyParserStaticData& operator=(WhixyParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag whixyparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<WhixyParserStaticData> whixyparserParserStaticData = nullptr;

void whixyparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (whixyparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(whixyparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<WhixyParserStaticData>(
    std::vector<std::string>{
      "srcFile", "statement", "valStmt", "expression", "blockExpr", "valsExpr", 
      "procedureExpr", "functionExpr", "typeExpr", "tupleExpr", "callExpr", 
      "endOfExp", "endOfStmt"
    },
    std::vector<std::string>{
      "", "", "", "'defer'", "'else'", "'enum'", "'errdefer'", "'for'", 
      "'func'", "'if'", "'import'", "'is'", "'proc'", "'std'", "'test'", 
      "'union'", "'val'", "'while'", "'align'", "'break'", "'catch'", "'compt'", 
      "'continue'", "'inline'", "'mut'", "'orelse'", "'return'", "'threadlocal'", 
      "'try'", "'unroll'", "'volatile'", "", "", "','", "';'"
    },
    std::vector<std::string>{
      "", "COMMENT", "STRING", "DEFER", "ELSE", "ENUM", "ERRDEFER", "FOR", 
      "FUNC", "IF", "IMPORT", "IS", "PROC", "STD", "TEST", "UNION", "VAL", 
      "WHILE", "ALIGN", "BREAK", "CATCH", "COMPT", "CONTINUE", "INLINE", 
      "MUT", "ORELSE", "RETURN", "THREADLOCAL", "TRY", "UNROLL", "VOLATILE", 
      "ID", "INTEGER", "EXP_SEP", "STMT_SEP", "OBRACE", "CBRACE", "OPAREN", 
      "CPAREN", "COLON", "EQ", "NL", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,42,130,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,1,0,4,0,28,8,0,11,
  	0,12,0,29,1,1,1,1,3,1,34,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,3,3,47,8,3,1,4,1,4,1,4,1,4,5,4,53,8,4,10,4,12,4,56,9,4,1,4,1,4,3,
  	4,60,8,4,3,4,62,8,4,1,4,1,4,1,5,4,5,67,8,5,11,5,12,5,68,1,5,1,5,3,5,73,
  	8,5,1,5,1,5,3,5,77,8,5,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,8,1,
  	8,1,8,1,8,5,8,93,8,8,10,8,12,8,96,9,8,1,8,1,8,3,8,100,8,8,3,8,102,8,8,
  	1,8,1,8,1,9,1,9,1,9,1,9,5,9,110,8,9,10,9,12,9,113,9,9,1,9,1,9,3,9,117,
  	8,9,3,9,119,8,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,12,0,0,13,
  	0,2,4,6,8,10,12,14,16,18,20,22,24,0,2,2,0,33,33,41,41,2,0,34,34,41,41,
  	136,0,27,1,0,0,0,2,33,1,0,0,0,4,35,1,0,0,0,6,46,1,0,0,0,8,48,1,0,0,0,
  	10,66,1,0,0,0,12,78,1,0,0,0,14,83,1,0,0,0,16,88,1,0,0,0,18,105,1,0,0,
  	0,20,122,1,0,0,0,22,125,1,0,0,0,24,127,1,0,0,0,26,28,3,2,1,0,27,26,1,
  	0,0,0,28,29,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,1,1,0,0,0,31,34,3,
  	4,2,0,32,34,3,8,4,0,33,31,1,0,0,0,33,32,1,0,0,0,34,3,1,0,0,0,35,36,5,
  	16,0,0,36,37,3,10,5,0,37,38,3,24,12,0,38,5,1,0,0,0,39,47,3,8,4,0,40,47,
  	3,10,5,0,41,47,3,12,6,0,42,47,3,14,7,0,43,47,3,16,8,0,44,47,3,18,9,0,
  	45,47,3,20,10,0,46,39,1,0,0,0,46,40,1,0,0,0,46,41,1,0,0,0,46,42,1,0,0,
  	0,46,43,1,0,0,0,46,44,1,0,0,0,46,45,1,0,0,0,47,7,1,0,0,0,48,61,5,35,0,
  	0,49,50,3,2,1,0,50,51,3,24,12,0,51,53,1,0,0,0,52,49,1,0,0,0,53,56,1,0,
  	0,0,54,52,1,0,0,0,54,55,1,0,0,0,55,57,1,0,0,0,56,54,1,0,0,0,57,59,3,2,
  	1,0,58,60,3,24,12,0,59,58,1,0,0,0,59,60,1,0,0,0,60,62,1,0,0,0,61,54,1,
  	0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,64,5,36,0,0,64,9,1,0,0,0,65,67,5,
  	31,0,0,66,65,1,0,0,0,67,68,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,72,
  	1,0,0,0,70,71,5,39,0,0,71,73,3,6,3,0,72,70,1,0,0,0,72,73,1,0,0,0,73,76,
  	1,0,0,0,74,75,5,40,0,0,75,77,3,6,3,0,76,74,1,0,0,0,76,77,1,0,0,0,77,11,
  	1,0,0,0,78,79,5,12,0,0,79,80,3,16,8,0,80,81,3,6,3,0,81,82,3,8,4,0,82,
  	13,1,0,0,0,83,84,5,8,0,0,84,85,3,16,8,0,85,86,3,6,3,0,86,87,3,8,4,0,87,
  	15,1,0,0,0,88,101,5,35,0,0,89,90,3,10,5,0,90,91,3,22,11,0,91,93,1,0,0,
  	0,92,89,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,1,0,0,
  	0,96,94,1,0,0,0,97,99,3,10,5,0,98,100,3,22,11,0,99,98,1,0,0,0,99,100,
  	1,0,0,0,100,102,1,0,0,0,101,94,1,0,0,0,101,102,1,0,0,0,102,103,1,0,0,
  	0,103,104,5,36,0,0,104,17,1,0,0,0,105,118,5,37,0,0,106,107,3,6,3,0,107,
  	108,3,22,11,0,108,110,1,0,0,0,109,106,1,0,0,0,110,113,1,0,0,0,111,109,
  	1,0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,111,1,0,0,0,114,116,3,6,3,
  	0,115,117,3,22,11,0,116,115,1,0,0,0,116,117,1,0,0,0,117,119,1,0,0,0,118,
  	111,1,0,0,0,118,119,1,0,0,0,119,120,1,0,0,0,120,121,5,38,0,0,121,19,1,
  	0,0,0,122,123,5,31,0,0,123,124,3,18,9,0,124,21,1,0,0,0,125,126,7,0,0,
  	0,126,23,1,0,0,0,127,128,7,1,0,0,128,25,1,0,0,0,15,29,33,46,54,59,61,
  	68,72,76,94,99,101,111,116,118
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  whixyparserParserStaticData = std::move(staticData);
}

}

WhixyParser::WhixyParser(TokenStream *input) : WhixyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

WhixyParser::WhixyParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  WhixyParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *whixyparserParserStaticData->atn, whixyparserParserStaticData->decisionToDFA, whixyparserParserStaticData->sharedContextCache, options);
}

WhixyParser::~WhixyParser() {
  delete _interpreter;
}

const atn::ATN& WhixyParser::getATN() const {
  return *whixyparserParserStaticData->atn;
}

std::string WhixyParser::getGrammarFileName() const {
  return "WhixyParser.g4";
}

const std::vector<std::string>& WhixyParser::getRuleNames() const {
  return whixyparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& WhixyParser::getVocabulary() const {
  return whixyparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView WhixyParser::getSerializedATN() const {
  return whixyparserParserStaticData->serializedATN;
}


//----------------- SrcFileContext ------------------------------------------------------------------

WhixyParser::SrcFileContext::SrcFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WhixyParser::StatementContext *> WhixyParser::SrcFileContext::statement() {
  return getRuleContexts<WhixyParser::StatementContext>();
}

WhixyParser::StatementContext* WhixyParser::SrcFileContext::statement(size_t i) {
  return getRuleContext<WhixyParser::StatementContext>(i);
}


size_t WhixyParser::SrcFileContext::getRuleIndex() const {
  return WhixyParser::RuleSrcFile;
}

void WhixyParser::SrcFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSrcFile(this);
}

void WhixyParser::SrcFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSrcFile(this);
}

WhixyParser::SrcFileContext* WhixyParser::srcFile() {
  SrcFileContext *_localctx = _tracker.createInstance<SrcFileContext>(_ctx, getState());
  enterRule(_localctx, 0, WhixyParser::RuleSrcFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      statement();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == WhixyParser::VAL

    || _la == WhixyParser::OBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

WhixyParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WhixyParser::ValStmtContext* WhixyParser::StatementContext::valStmt() {
  return getRuleContext<WhixyParser::ValStmtContext>(0);
}

WhixyParser::BlockExprContext* WhixyParser::StatementContext::blockExpr() {
  return getRuleContext<WhixyParser::BlockExprContext>(0);
}


size_t WhixyParser::StatementContext::getRuleIndex() const {
  return WhixyParser::RuleStatement;
}

void WhixyParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void WhixyParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

WhixyParser::StatementContext* WhixyParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, WhixyParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WhixyParser::VAL: {
        enterOuterAlt(_localctx, 1);
        setState(31);
        valStmt();
        break;
      }

      case WhixyParser::OBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(32);
        blockExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValStmtContext ------------------------------------------------------------------

WhixyParser::ValStmtContext::ValStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::ValStmtContext::VAL() {
  return getToken(WhixyParser::VAL, 0);
}

WhixyParser::ValsExprContext* WhixyParser::ValStmtContext::valsExpr() {
  return getRuleContext<WhixyParser::ValsExprContext>(0);
}

WhixyParser::EndOfStmtContext* WhixyParser::ValStmtContext::endOfStmt() {
  return getRuleContext<WhixyParser::EndOfStmtContext>(0);
}


size_t WhixyParser::ValStmtContext::getRuleIndex() const {
  return WhixyParser::RuleValStmt;
}

void WhixyParser::ValStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValStmt(this);
}

void WhixyParser::ValStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValStmt(this);
}

WhixyParser::ValStmtContext* WhixyParser::valStmt() {
  ValStmtContext *_localctx = _tracker.createInstance<ValStmtContext>(_ctx, getState());
  enterRule(_localctx, 4, WhixyParser::RuleValStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(WhixyParser::VAL);
    setState(36);
    valsExpr();
    setState(37);
    endOfStmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

WhixyParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WhixyParser::BlockExprContext* WhixyParser::ExpressionContext::blockExpr() {
  return getRuleContext<WhixyParser::BlockExprContext>(0);
}

WhixyParser::ValsExprContext* WhixyParser::ExpressionContext::valsExpr() {
  return getRuleContext<WhixyParser::ValsExprContext>(0);
}

WhixyParser::ProcedureExprContext* WhixyParser::ExpressionContext::procedureExpr() {
  return getRuleContext<WhixyParser::ProcedureExprContext>(0);
}

WhixyParser::FunctionExprContext* WhixyParser::ExpressionContext::functionExpr() {
  return getRuleContext<WhixyParser::FunctionExprContext>(0);
}

WhixyParser::TypeExprContext* WhixyParser::ExpressionContext::typeExpr() {
  return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::ExpressionContext::tupleExpr() {
  return getRuleContext<WhixyParser::TupleExprContext>(0);
}

WhixyParser::CallExprContext* WhixyParser::ExpressionContext::callExpr() {
  return getRuleContext<WhixyParser::CallExprContext>(0);
}


size_t WhixyParser::ExpressionContext::getRuleIndex() const {
  return WhixyParser::RuleExpression;
}

void WhixyParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void WhixyParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

WhixyParser::ExpressionContext* WhixyParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 6, WhixyParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(46);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(39);
      blockExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(40);
      valsExpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(41);
      procedureExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(42);
      functionExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(43);
      typeExpr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(44);
      tupleExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(45);
      callExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockExprContext ------------------------------------------------------------------

WhixyParser::BlockExprContext::BlockExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::BlockExprContext::OBRACE() {
  return getToken(WhixyParser::OBRACE, 0);
}

tree::TerminalNode* WhixyParser::BlockExprContext::CBRACE() {
  return getToken(WhixyParser::CBRACE, 0);
}

std::vector<WhixyParser::StatementContext *> WhixyParser::BlockExprContext::statement() {
  return getRuleContexts<WhixyParser::StatementContext>();
}

WhixyParser::StatementContext* WhixyParser::BlockExprContext::statement(size_t i) {
  return getRuleContext<WhixyParser::StatementContext>(i);
}

std::vector<WhixyParser::EndOfStmtContext *> WhixyParser::BlockExprContext::endOfStmt() {
  return getRuleContexts<WhixyParser::EndOfStmtContext>();
}

WhixyParser::EndOfStmtContext* WhixyParser::BlockExprContext::endOfStmt(size_t i) {
  return getRuleContext<WhixyParser::EndOfStmtContext>(i);
}


size_t WhixyParser::BlockExprContext::getRuleIndex() const {
  return WhixyParser::RuleBlockExpr;
}

void WhixyParser::BlockExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockExpr(this);
}

void WhixyParser::BlockExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockExpr(this);
}

WhixyParser::BlockExprContext* WhixyParser::blockExpr() {
  BlockExprContext *_localctx = _tracker.createInstance<BlockExprContext>(_ctx, getState());
  enterRule(_localctx, 8, WhixyParser::RuleBlockExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(WhixyParser::OBRACE);
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WhixyParser::VAL

    || _la == WhixyParser::OBRACE) {
      setState(54);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(49);
          statement();
          setState(50);
          endOfStmt(); 
        }
        setState(56);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      }
      setState(57);
      statement();
      setState(59);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WhixyParser::STMT_SEP

      || _la == WhixyParser::NL) {
        setState(58);
        endOfStmt();
      }
    }
    setState(63);
    match(WhixyParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValsExprContext ------------------------------------------------------------------

WhixyParser::ValsExprContext::ValsExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> WhixyParser::ValsExprContext::ID() {
  return getTokens(WhixyParser::ID);
}

tree::TerminalNode* WhixyParser::ValsExprContext::ID(size_t i) {
  return getToken(WhixyParser::ID, i);
}

tree::TerminalNode* WhixyParser::ValsExprContext::COLON() {
  return getToken(WhixyParser::COLON, 0);
}

std::vector<WhixyParser::ExpressionContext *> WhixyParser::ValsExprContext::expression() {
  return getRuleContexts<WhixyParser::ExpressionContext>();
}

WhixyParser::ExpressionContext* WhixyParser::ValsExprContext::expression(size_t i) {
  return getRuleContext<WhixyParser::ExpressionContext>(i);
}

tree::TerminalNode* WhixyParser::ValsExprContext::EQ() {
  return getToken(WhixyParser::EQ, 0);
}


size_t WhixyParser::ValsExprContext::getRuleIndex() const {
  return WhixyParser::RuleValsExpr;
}

void WhixyParser::ValsExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValsExpr(this);
}

void WhixyParser::ValsExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValsExpr(this);
}

WhixyParser::ValsExprContext* WhixyParser::valsExpr() {
  ValsExprContext *_localctx = _tracker.createInstance<ValsExprContext>(_ctx, getState());
  enterRule(_localctx, 10, WhixyParser::RuleValsExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(65);
      match(WhixyParser::ID);
      setState(68); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == WhixyParser::ID);
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WhixyParser::COLON) {
      setState(70);
      match(WhixyParser::COLON);
      setState(71);
      expression();
    }
    setState(76);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      setState(74);
      match(WhixyParser::EQ);
      setState(75);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureExprContext ------------------------------------------------------------------

WhixyParser::ProcedureExprContext::ProcedureExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::ProcedureExprContext::PROC() {
  return getToken(WhixyParser::PROC, 0);
}

WhixyParser::TypeExprContext* WhixyParser::ProcedureExprContext::typeExpr() {
  return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::ExpressionContext* WhixyParser::ProcedureExprContext::expression() {
  return getRuleContext<WhixyParser::ExpressionContext>(0);
}

WhixyParser::BlockExprContext* WhixyParser::ProcedureExprContext::blockExpr() {
  return getRuleContext<WhixyParser::BlockExprContext>(0);
}


size_t WhixyParser::ProcedureExprContext::getRuleIndex() const {
  return WhixyParser::RuleProcedureExpr;
}

void WhixyParser::ProcedureExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureExpr(this);
}

void WhixyParser::ProcedureExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureExpr(this);
}

WhixyParser::ProcedureExprContext* WhixyParser::procedureExpr() {
  ProcedureExprContext *_localctx = _tracker.createInstance<ProcedureExprContext>(_ctx, getState());
  enterRule(_localctx, 12, WhixyParser::RuleProcedureExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(WhixyParser::PROC);
    setState(79);
    typeExpr();
    setState(80);
    expression();
    setState(81);
    blockExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionExprContext ------------------------------------------------------------------

WhixyParser::FunctionExprContext::FunctionExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::FunctionExprContext::FUNC() {
  return getToken(WhixyParser::FUNC, 0);
}

WhixyParser::TypeExprContext* WhixyParser::FunctionExprContext::typeExpr() {
  return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::ExpressionContext* WhixyParser::FunctionExprContext::expression() {
  return getRuleContext<WhixyParser::ExpressionContext>(0);
}

WhixyParser::BlockExprContext* WhixyParser::FunctionExprContext::blockExpr() {
  return getRuleContext<WhixyParser::BlockExprContext>(0);
}


size_t WhixyParser::FunctionExprContext::getRuleIndex() const {
  return WhixyParser::RuleFunctionExpr;
}

void WhixyParser::FunctionExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExpr(this);
}

void WhixyParser::FunctionExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExpr(this);
}

WhixyParser::FunctionExprContext* WhixyParser::functionExpr() {
  FunctionExprContext *_localctx = _tracker.createInstance<FunctionExprContext>(_ctx, getState());
  enterRule(_localctx, 14, WhixyParser::RuleFunctionExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(WhixyParser::FUNC);
    setState(84);
    typeExpr();
    setState(85);
    expression();
    setState(86);
    blockExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeExprContext ------------------------------------------------------------------

WhixyParser::TypeExprContext::TypeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::TypeExprContext::OBRACE() {
  return getToken(WhixyParser::OBRACE, 0);
}

tree::TerminalNode* WhixyParser::TypeExprContext::CBRACE() {
  return getToken(WhixyParser::CBRACE, 0);
}

std::vector<WhixyParser::ValsExprContext *> WhixyParser::TypeExprContext::valsExpr() {
  return getRuleContexts<WhixyParser::ValsExprContext>();
}

WhixyParser::ValsExprContext* WhixyParser::TypeExprContext::valsExpr(size_t i) {
  return getRuleContext<WhixyParser::ValsExprContext>(i);
}

std::vector<WhixyParser::EndOfExpContext *> WhixyParser::TypeExprContext::endOfExp() {
  return getRuleContexts<WhixyParser::EndOfExpContext>();
}

WhixyParser::EndOfExpContext* WhixyParser::TypeExprContext::endOfExp(size_t i) {
  return getRuleContext<WhixyParser::EndOfExpContext>(i);
}


size_t WhixyParser::TypeExprContext::getRuleIndex() const {
  return WhixyParser::RuleTypeExpr;
}

void WhixyParser::TypeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeExpr(this);
}

void WhixyParser::TypeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeExpr(this);
}

WhixyParser::TypeExprContext* WhixyParser::typeExpr() {
  TypeExprContext *_localctx = _tracker.createInstance<TypeExprContext>(_ctx, getState());
  enterRule(_localctx, 16, WhixyParser::RuleTypeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(WhixyParser::OBRACE);
    setState(101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WhixyParser::ID) {
      setState(94);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(89);
          valsExpr();
          setState(90);
          endOfExp(); 
        }
        setState(96);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
      }
      setState(97);
      valsExpr();
      setState(99);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WhixyParser::EXP_SEP

      || _la == WhixyParser::NL) {
        setState(98);
        endOfExp();
      }
    }
    setState(103);
    match(WhixyParser::CBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TupleExprContext ------------------------------------------------------------------

WhixyParser::TupleExprContext::TupleExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::TupleExprContext::OPAREN() {
  return getToken(WhixyParser::OPAREN, 0);
}

tree::TerminalNode* WhixyParser::TupleExprContext::CPAREN() {
  return getToken(WhixyParser::CPAREN, 0);
}

std::vector<WhixyParser::ExpressionContext *> WhixyParser::TupleExprContext::expression() {
  return getRuleContexts<WhixyParser::ExpressionContext>();
}

WhixyParser::ExpressionContext* WhixyParser::TupleExprContext::expression(size_t i) {
  return getRuleContext<WhixyParser::ExpressionContext>(i);
}

std::vector<WhixyParser::EndOfExpContext *> WhixyParser::TupleExprContext::endOfExp() {
  return getRuleContexts<WhixyParser::EndOfExpContext>();
}

WhixyParser::EndOfExpContext* WhixyParser::TupleExprContext::endOfExp(size_t i) {
  return getRuleContext<WhixyParser::EndOfExpContext>(i);
}


size_t WhixyParser::TupleExprContext::getRuleIndex() const {
  return WhixyParser::RuleTupleExpr;
}

void WhixyParser::TupleExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTupleExpr(this);
}

void WhixyParser::TupleExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTupleExpr(this);
}

WhixyParser::TupleExprContext* WhixyParser::tupleExpr() {
  TupleExprContext *_localctx = _tracker.createInstance<TupleExprContext>(_ctx, getState());
  enterRule(_localctx, 18, WhixyParser::RuleTupleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(WhixyParser::OPAREN);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 173946179840) != 0)) {
      setState(111);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(106);
          expression();
          setState(107);
          endOfExp(); 
        }
        setState(113);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      }
      setState(114);
      expression();
      setState(116);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WhixyParser::EXP_SEP

      || _la == WhixyParser::NL) {
        setState(115);
        endOfExp();
      }
    }
    setState(120);
    match(WhixyParser::CPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallExprContext ------------------------------------------------------------------

WhixyParser::CallExprContext::CallExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::CallExprContext::ID() {
  return getToken(WhixyParser::ID, 0);
}

WhixyParser::TupleExprContext* WhixyParser::CallExprContext::tupleExpr() {
  return getRuleContext<WhixyParser::TupleExprContext>(0);
}


size_t WhixyParser::CallExprContext::getRuleIndex() const {
  return WhixyParser::RuleCallExpr;
}

void WhixyParser::CallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallExpr(this);
}

void WhixyParser::CallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallExpr(this);
}

WhixyParser::CallExprContext* WhixyParser::callExpr() {
  CallExprContext *_localctx = _tracker.createInstance<CallExprContext>(_ctx, getState());
  enterRule(_localctx, 20, WhixyParser::RuleCallExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(WhixyParser::ID);
    setState(123);
    tupleExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndOfExpContext ------------------------------------------------------------------

WhixyParser::EndOfExpContext::EndOfExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::EndOfExpContext::EXP_SEP() {
  return getToken(WhixyParser::EXP_SEP, 0);
}

tree::TerminalNode* WhixyParser::EndOfExpContext::NL() {
  return getToken(WhixyParser::NL, 0);
}


size_t WhixyParser::EndOfExpContext::getRuleIndex() const {
  return WhixyParser::RuleEndOfExp;
}

void WhixyParser::EndOfExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndOfExp(this);
}

void WhixyParser::EndOfExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndOfExp(this);
}

WhixyParser::EndOfExpContext* WhixyParser::endOfExp() {
  EndOfExpContext *_localctx = _tracker.createInstance<EndOfExpContext>(_ctx, getState());
  enterRule(_localctx, 22, WhixyParser::RuleEndOfExp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _la = _input->LA(1);
    if (!(_la == WhixyParser::EXP_SEP

    || _la == WhixyParser::NL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndOfStmtContext ------------------------------------------------------------------

WhixyParser::EndOfStmtContext::EndOfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WhixyParser::EndOfStmtContext::STMT_SEP() {
  return getToken(WhixyParser::STMT_SEP, 0);
}

tree::TerminalNode* WhixyParser::EndOfStmtContext::NL() {
  return getToken(WhixyParser::NL, 0);
}


size_t WhixyParser::EndOfStmtContext::getRuleIndex() const {
  return WhixyParser::RuleEndOfStmt;
}

void WhixyParser::EndOfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndOfStmt(this);
}

void WhixyParser::EndOfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WhixyParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndOfStmt(this);
}

WhixyParser::EndOfStmtContext* WhixyParser::endOfStmt() {
  EndOfStmtContext *_localctx = _tracker.createInstance<EndOfStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, WhixyParser::RuleEndOfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _la = _input->LA(1);
    if (!(_la == WhixyParser::STMT_SEP

    || _la == WhixyParser::NL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void WhixyParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  whixyparserParserInitialize();
#else
  ::antlr4::internal::call_once(whixyparserParserOnceFlag, whixyparserParserInitialize);
#endif
}
