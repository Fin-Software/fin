
// Generated from WhixyLexer.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace Whixy {


class  WhixyLexer : public antlr4::Lexer {
public:
  enum {
    COMMENT = 1, STRING = 2, DEFER = 3, ELSE = 4, ENUM = 5, ERRDEFER = 6, 
    FOR = 7, FUNC = 8, IF = 9, IMPORT = 10, IS = 11, PROC = 12, STD = 13, 
    TEST = 14, UNION = 15, VAL = 16, WHILE = 17, ALIGN = 18, BREAK = 19, 
    CATCH = 20, COMPT = 21, CONTINUE = 22, INLINE = 23, MUT = 24, ORELSE = 25, 
    RETURN = 26, THREADLOCAL = 27, TRY = 28, UNROLL = 29, VOLATILE = 30, 
    ID = 31, INTEGER = 32, EXP_SEP = 33, STMT_SEP = 34, OBRACE = 35, CBRACE = 36, 
    OPAREN = 37, CPAREN = 38, COLON = 39, EQ = 40, NL = 41, WS = 42
  };

  explicit WhixyLexer(antlr4::CharStream *input);

  ~WhixyLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace Whixy
