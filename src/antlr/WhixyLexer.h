
// Generated from WhixyLexer.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

namespace Whixy {

class WhixyLexer: public antlr4::Lexer {
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

    explicit WhixyLexer(antlr4::CharStream* input);

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

} // namespace Whixy
