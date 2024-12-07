
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
