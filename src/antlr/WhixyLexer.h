
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
        RUNE = 5,
        WHITESPACE = 6,
        COMMA = 7,
        SEMICOLON = 8,
        DOLLAR_OPENPARENTHESIS = 9,
        OPENPARENTHESIS = 10,
        CLOSEDPARENTHESIS = 11,
        OPENBRACE = 12,
        CLOSEDBRACE = 13,
        OPENBRACKET = 14,
        CLOSEDBRACKET = 15,
        DOT_TYPE = 16,
        DOT_LEN = 17,
        DOT_ASTERISK = 18,
        DOT_AMPERSAND = 19,
        QUESTION = 20,
        EXCLAMATION = 21,
        DOT = 22,
        GREATERTHAN_GREATERTHAN_PERCENT_EQUAL = 23,
        GREATERTHAN_GREATERTHAN_PERCENT = 24,
        GREATERTHAN_GREATERTHAN_EQUAL = 25,
        GREATERTHAN_GREATERTHAN = 26,
        GREATERTHAN_EQUAL = 27,
        GREATERTHAN = 28,
        LESSTHAN_LESSTHAN_PERCENT_EQUAL = 29,
        LESSTHAN_LESSTHAN_PERCENT = 30,
        LESSTHAN_LESSTHAN_EQUAL = 31,
        LESSTHAN_LESSTHAN = 32,
        LESSTHAN_EQUAL = 33,
        LESSTHAN = 34,
        ASTERISK_PERCENT_EQUAL = 35,
        ASTERISK_PERCENT = 36,
        ASTERISK_EQUAL = 37,
        ASTERISK_ASTERISK = 38,
        ASTERISK = 39,
        PLUS_PERCENT_EQUAL = 40,
        PLUS_PERCENT = 41,
        PLUS_EQUAL = 42,
        PLUS_PLUS = 43,
        PLUS = 44,
        MINUS_PERCENT_EQUAL = 45,
        MINUS_PERCENT = 46,
        MINUS_EQUAL = 47,
        MINUS = 48,
        TILDE_EQUAL = 49,
        TILDE = 50,
        AMPERSAND_EQUAL = 51,
        AMPERSAND = 52,
        PERCENT_EQUAL = 53,
        PERCENT = 54,
        CARROT_EQUAL = 55,
        CARROT = 56,
        SLASH_EQUAL = 57,
        SLASH = 58,
        EQUAL_EQUAL = 59,
        EQUAL = 60,
        PIPE_EQUAL = 61,
        PIPE = 62,
        THIS = 63,
        AUTO = 64,
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
        WHERE = 76,
        DEFER = 77,
        ERRDEFER = 78,
        FAST = 79,
        BARE = 80,
        IMPORT = 81,
        ALIGN = 82,
        THREADL = 83,
        UNREACHABLE = 84,
        VOLATILE = 85,
        UNROLL = 86,
        COMPT = 87,
        TEST = 88,
        ENUM = 89,
        UNION = 90,
        STD = 91,
        ORELSE = 92,
        CATCH = 93,
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
