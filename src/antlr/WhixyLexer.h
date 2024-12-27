
// Generated from WhixyLexer.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"

namespace Whixy {

class WhixyLexer: public antlr4::Lexer {
  public:
    enum {
        DOUBLEQUOTESTRING = 1,
        BACKTICKSTRING = 2,
        BACKSLASHSTRING = 3,
        BLOCKDOCCOMMENT = 4,
        BLOCKCOMMENT = 5,
        DOCCOMMENT = 6,
        COMMENT = 7,
        WHITESPACE = 8,
        NEWLINE = 9,
        OPENPARENTHESIS = 10,
        CLOSEDPARENTHESIS = 11,
        DOT = 12,
        COMMA = 13,
        UNDERSCORE = 14,
        EXCLAMATION = 15,
        OPENBRACE = 16,
        CLOSEDBRACE = 17,
        OPENBRACKET = 18,
        CLOSEDBRACKET = 19,
        SEMICOLON = 20,
        QUESTION = 21,
        DOLLAR_OPENPARENTHESIS = 22,
        SINGLEQUOTE = 23,
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
        TILDE_EQUAL = 50,
        TILDE = 51,
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
        AND = 64,
        OR = 65,
        TYPE = 66,
        LEN = 67,
        THIS = 68,
        MUT = 69,
        INLINE = 70,
        RETURN = 71,
        CONTINUE = 72,
        BREAK = 73,
        GOTO = 74,
        WHILE = 75,
        FOR = 76,
        IF = 77,
        ELSEIF = 78,
        ELSE = 79,
        WHERE = 80,
        DEFER = 81,
        ERRDEFER = 82,
        FAST = 83,
        BARE = 84,
        IMPORT = 85,
        ALIGN = 86,
        THREADL = 87,
        UNREACHABLE = 88,
        VOLATILE = 89,
        UNROLL = 90,
        COMPT = 91,
        TEST = 92,
        ENUM = 93,
        EMBED = 94,
        UNION = 95,
        STD = 96,
        ORELSE = 97,
        CATCH = 98,
        AS = 99,
        TOKEN = 100
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
