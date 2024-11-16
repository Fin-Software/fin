
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
        DEF = 64,
        PROC = 65,
        FUNC = 66,
        MUT = 67,
        INLINE = 68,
        RETURN = 69,
        BREAK = 70,
        CONTINUE = 71,
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
