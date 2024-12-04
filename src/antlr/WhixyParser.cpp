
// Generated from WhixyParser.g4 by ANTLR 4.13.2

#include "WhixyParserVisitor.h"

#include "WhixyParser.h"

using namespace antlrcpp;
using namespace Whixy;

using namespace antlr4;

namespace {

struct WhixyParserStaticData final {
    WhixyParserStaticData(
        std::vector<std::string> ruleNames, std::vector<std::string> literalNames,
        std::vector<std::string> symbolicNames
    )
        : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
          symbolicNames(std::move(symbolicNames)), vocabulary(this->literalNames, this->symbolicNames)
    {}

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
    std::unique_ptr<WhixyParserStaticData>
        whixyparserParserStaticData = nullptr;

void whixyparserParserInitialize()
{
#if ANTLR4_USE_THREAD_LOCAL_CACHE
    if (whixyparserParserStaticData != nullptr) { return; }
#else
    assert(whixyparserParserStaticData == nullptr);
#endif
    auto staticData = std::make_unique<WhixyParserStaticData>(
        std::vector<std::string>{"srcFile",     "stmt",          "valsStmt",      "assignOpStmt",  "assignOp",
                                 "callStmt",    "blockStmt",     "routineStmt",   "returnStmt",    "ifStmt",
                                 "whereStmt",   "comparisonOp",  "caseStmtBlock", "loopStmt",      "comptStmt",
                                 "deferStmt",   "errdeferStmt",  "expr",          "binaryOpExpr",  "binaryOp",
                                 "postOpExpr",  "postOp",        "preOpExpr",     "preOp",         "ifExpr",
                                 "whereExpr",   "caseExprBlock", "loopExpr",      "comptExpr",     "routineExpr",
                                 "string",      "atom",          "token",         "blockExpr",     "typeExpr",
                                 "tupleExpr",   "oBracket",      "cBracket",      "oAngleBracket", "cAngleBracket",
                                 "dollarParen", "oParen",        "cParen",        "oBrace",        "cBrace",
                                 "stmtSep",     "exprSep"},
        std::vector<std::string>{
            "",
            "",
            "",
            "",
            "",
            "",
            "':'",
            "','",
            "';'",
            "'\\u003F'",
            "'$('",
            "'('",
            "')'",
            "'{'",
            "'}'",
            "'<['",
            "']>'",
            "'['",
            "']'",
            "'.type'",
            "'.len'",
            "'.*'",
            "'.&'",
            "'.\\u003F'",
            "'.'",
            "'>>%='",
            "'>>%'",
            "'>>='",
            "'>>'",
            "'>='",
            "'>'",
            "'<<%='",
            "'<<%'",
            "'<<='",
            "'<<'",
            "'<='",
            "'<'",
            "'*%='",
            "'*%'",
            "'*='",
            "'**'",
            "'*'",
            "'+%='",
            "'+%'",
            "'+='",
            "'++'",
            "'+'",
            "'-%='",
            "'-%'",
            "'-='",
            "'-'",
            "'!='",
            "'!'",
            "'&='",
            "'&'",
            "'%='",
            "'%'",
            "'^='",
            "'^'",
            "'/='",
            "'/'",
            "'=='",
            "'='",
            "'|='",
            "'|'",
            "'mut'",
            "'inline'",
            "'return'",
            "'continue'",
            "'break'",
            "'goto'",
            "'while'",
            "'for'",
            "'if'",
            "'elseif'",
            "'else'",
            "'where'",
            "'defer'",
            "'errdefer'",
            "'orelse'",
            "'try'",
            "'catch'",
            "'import'",
            "'align'",
            "'threadlocal'",
            "'unreachable'",
            "'volatile'",
            "'unroll'",
            "'compt'",
            "'test'",
            "'enum'",
            "'union'",
            "'std'",
            "'as'"
        },
        std::vector<std::string>{
            "",
            "DOUBLEQUOTESTRING",
            "BACKTICKSTRING",
            "DOCCOMMENT",
            "COMMENT",
            "WHITESPACE",
            "COLON",
            "COMMA",
            "SEMICOLON",
            "QUESTION",
            "DOLLAR_OPENPARENTHESIS",
            "OPENPARENTHESIS",
            "CLOSEDPARENTHESIS",
            "OPENBRACE",
            "CLOSEDBRACE",
            "LESSTHAN_OPENBRACKET",
            "CLOSEDBRACKET_GREATERTHAN",
            "OPENBRACKET",
            "CLOSEDBRACKET",
            "DOT_TYPE",
            "DOT_LEN",
            "DOT_ASTERISK",
            "DOT_AMPERSAND",
            "DOT_QUESTION",
            "DOT",
            "GREATERTHAN_GREATERTHAN_PERCENT_EQUAL",
            "GREATERTHAN_GREATERTHAN_PERCENT",
            "GREATERTHAN_GREATERTHAN_EQUAL",
            "GREATERTHAN_GREATERTHAN",
            "GREATERTHAN_EQUAL",
            "GREATERTHAN",
            "LESSTHAN_LESSTHAN_PERCENT_EQUAL",
            "LESSTHAN_LESSTHAN_PERCENT",
            "LESSTHAN_LESSTHAN_EQUAL",
            "LESSTHAN_LESSTHAN",
            "LESSTHAN_EQUAL",
            "LESSTHAN",
            "ASTERISK_PERCENT_EQUAL",
            "ASTERISK_PERCENT",
            "ASTERISK_EQUAL",
            "ASTERISK_ASTERISK",
            "ASTERISK",
            "PLUS_PERCENT_EQUAL",
            "PLUS_PERCENT",
            "PLUS_EQUAL",
            "PLUS_PLUS",
            "PLUS",
            "MINUS_PERCENT_EQUAL",
            "MINUS_PERCENT",
            "MINUS_EQUAL",
            "MINUS",
            "EXCLAMATION_EQUAL",
            "EXCLAMATION",
            "AMPERSAND_EQUAL",
            "AMPERSAND",
            "PERCENT_EQUAL",
            "PERCENT",
            "CARROT_EQUAL",
            "CARROT",
            "SLASH_EQUAL",
            "SLASH",
            "EQUAL_EQUAL",
            "EQUAL",
            "PIPE_EQUAL",
            "PIPE",
            "MUT",
            "INLINE",
            "RETURN",
            "CONTINUE",
            "BREAK",
            "GOTO",
            "WHILE",
            "FOR",
            "IF",
            "ELSEIF",
            "ELSE",
            "WHERE",
            "DEFER",
            "ERRDEFER",
            "ORELSE",
            "TRY",
            "CATCH",
            "IMPORT",
            "ALIGN",
            "THREADLOCAL",
            "UNREACHABLE",
            "VOLATILE",
            "UNROLL",
            "COMPT",
            "TEST",
            "ENUM",
            "UNION",
            "STD",
            "AS",
            "NEWLINE",
            "TOKEN"
        }
    );
    static const int32_t serializedATNSegment[] = {
        4,   1,   95,  537, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,   4,
        7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,
        2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  2,   14,  7,   14,  2,   15,
        7,   15,  2,   16,  7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,
        2,   21,  7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25,  7,   25,  2,   26,
        7,   26,  2,   27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,  7,   31,
        2,   32,  7,   32,  2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,  2,   37,
        7,   37,  2,   38,  7,   38,  2,   39,  7,   39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,  7,   42,
        2,   43,  7,   43,  2,   44,  7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  1,   0,   3,   0,   96,  8,
        0,   1,   0,   1,   0,   1,   0,   1,   0,   5,   0,   102, 8,   0,   10,  0,   12,  0,   105, 9,   0,   1,
        0,   3,   0,   108, 8,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   1,   124, 8,   1,   1,   2,   4,   2,   127,
        8,   2,   11,  2,   12,  2,   128, 1,   2,   1,   2,   3,   2,   133, 8,   2,   1,   2,   1,   2,   3,   2,
        137, 8,   2,   3,   2,   139, 8,   2,   1,   2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   1,   4,
        1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,
        1,   4,   1,   4,   1,   4,   3,   4,   162, 8,   4,   1,   5,   1,   5,   1,   5,   1,   6,   1,   6,   1,
        6,   1,   6,   1,   6,   5,   6,   172, 8,   6,   10,  6,   12,  6,   175, 9,   6,   3,   6,   177, 8,   6,
        1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   5,   6,   186, 8,   6,   10,  6,   12,
        6,   189, 9,   6,   3,   6,   191, 8,   6,   1,   6,   1,   6,   3,   6,   195, 8,   6,   1,   7,   1,   7,
        1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   3,   7,   208, 8,
        7,   1,   8,   1,   8,   1,   8,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   5,
        9,   220, 8,   9,   10,  9,   12,  9,   223, 9,   9,   1,   9,   1,   9,   3,   9,   227, 8,   9,   1,   10,
        1,   10,  1,   10,  1,   10,  1,   10,  1,   11,  1,   11,  1,   12,  1,   12,  1,   13,  1,   13,  1,   13,
        3,   13,  241, 8,   13,  1,   13,  3,   13,  244, 8,   13,  1,   13,  1,   13,  1,   13,  1,   13,  3,   13,
        250, 8,   13,  1,   13,  3,   13,  253, 8,   13,  1,   13,  1,   13,  1,   13,  3,   13,  258, 8,   13,  1,
        13,  3,   13,  261, 8,   13,  1,   13,  1,   13,  1,   13,  3,   13,  266, 8,   13,  1,   13,  3,   13,  269,
        8,   13,  1,   13,  3,   13,  272, 8,   13,  1,   14,  1,   14,  1,   14,  1,   15,  1,   15,  1,   15,  1,
        16,  1,   16,  1,   16,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,   17,  1,
        17,  1,   17,  1,   17,  1,   17,  3,   17,  295, 8,   17,  1,   18,  1,   18,  3,   18,  299, 8,   18,  1,
        18,  1,   18,  3,   18,  303, 8,   18,  1,   18,  1,   18,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,
        1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,
        1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  1,   19,  3,   19,  331, 8,   19,  1,
        20,  1,   20,  1,   20,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  1,   21,  3,   21,  343,
        8,   21,  1,   22,  1,   22,  1,   22,  1,   23,  1,   23,  3,   23,  350, 8,   23,  1,   24,  1,   24,  1,
        24,  1,   24,  1,   24,  1,   24,  1,   24,  5,   24,  359, 8,   24,  10,  24,  12,  24,  362, 9,   24,  1,
        24,  1,   24,  3,   24,  366, 8,   24,  1,   25,  1,   25,  1,   25,  1,   25,  1,   25,  1,   26,  1,   26,
        1,   27,  1,   27,  1,   27,  3,   27,  378, 8,   27,  1,   27,  3,   27,  381, 8,   27,  1,   27,  1,   27,
        1,   27,  1,   27,  3,   27,  387, 8,   27,  1,   27,  3,   27,  390, 8,   27,  1,   27,  1,   27,  1,   27,
        3,   27,  395, 8,   27,  1,   27,  3,   27,  398, 8,   27,  1,   27,  1,   27,  1,   27,  3,   27,  403, 8,
        27,  1,   27,  3,   27,  406, 8,   27,  1,   27,  3,   27,  409, 8,   27,  1,   28,  1,   28,  1,   28,  1,
        29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  3,   29,  423, 8,   29,
        1,   30,  1,   30,  3,   30,  427, 8,   30,  1,   31,  1,   31,  1,   31,  1,   31,  3,   31,  433, 8,   31,
        1,   32,  1,   32,  1,   33,  1,   33,  1,   33,  1,   33,  1,   33,  5,   33,  442, 8,   33,  10,  33,  12,
        33,  445, 9,   33,  1,   33,  1,   33,  3,   33,  449, 8,   33,  1,   33,  3,   33,  452, 8,   33,  1,   33,
        1,   33,  1,   34,  1,   34,  1,   34,  1,   34,  1,   34,  5,   34,  461, 8,   34,  10,  34,  12,  34,  464,
        9,   34,  3,   34,  466, 8,   34,  1,   34,  1,   34,  1,   35,  1,   35,  1,   35,  1,   35,  1,   35,  5,
        35,  475, 8,   35,  10,  35,  12,  35,  478, 9,   35,  3,   35,  480, 8,   35,  1,   35,  1,   35,  1,   36,
        1,   36,  3,   36,  486, 8,   36,  1,   37,  3,   37,  489, 8,   37,  1,   37,  1,   37,  1,   38,  1,   38,
        3,   38,  495, 8,   38,  1,   39,  3,   39,  498, 8,   39,  1,   39,  1,   39,  1,   40,  3,   40,  503, 8,
        40,  1,   40,  1,   40,  3,   40,  507, 8,   40,  1,   41,  3,   41,  510, 8,   41,  1,   41,  1,   41,  3,
        41,  514, 8,   41,  1,   42,  3,   42,  517, 8,   42,  1,   42,  1,   42,  1,   43,  3,   43,  522, 8,   43,
        1,   43,  1,   43,  3,   43,  526, 8,   43,  1,   44,  3,   44,  529, 8,   44,  1,   44,  1,   44,  1,   45,
        1,   45,  1,   46,  1,   46,  1,   46,  0,   0,   47,  0,   2,   4,   6,   8,   10,  12,  14,  16,  18,  20,
        22,  24,  26,  28,  30,  32,  34,  36,  38,  40,  42,  44,  46,  48,  50,  52,  54,  56,  58,  60,  62,  64,
        66,  68,  70,  72,  74,  76,  78,  80,  82,  84,  86,  88,  90,  92,  0,   2,   2,   0,   8,   8,   94,  94,
        2,   0,   7,   7,   94,  94,  619, 0,   95,  1,   0,   0,   0,   2,   123, 1,   0,   0,   0,   4,   126, 1,
        0,   0,   0,   6,   142, 1,   0,   0,   0,   8,   161, 1,   0,   0,   0,   10,  163, 1,   0,   0,   0,   12,
        194, 1,   0,   0,   0,   14,  207, 1,   0,   0,   0,   16,  209, 1,   0,   0,   0,   18,  212, 1,   0,   0,
        0,   20,  228, 1,   0,   0,   0,   22,  233, 1,   0,   0,   0,   24,  235, 1,   0,   0,   0,   26,  271, 1,
        0,   0,   0,   28,  273, 1,   0,   0,   0,   30,  276, 1,   0,   0,   0,   32,  279, 1,   0,   0,   0,   34,
        294, 1,   0,   0,   0,   36,  296, 1,   0,   0,   0,   38,  330, 1,   0,   0,   0,   40,  332, 1,   0,   0,
        0,   42,  342, 1,   0,   0,   0,   44,  344, 1,   0,   0,   0,   46,  349, 1,   0,   0,   0,   48,  351, 1,
        0,   0,   0,   50,  367, 1,   0,   0,   0,   52,  372, 1,   0,   0,   0,   54,  408, 1,   0,   0,   0,   56,
        410, 1,   0,   0,   0,   58,  422, 1,   0,   0,   0,   60,  426, 1,   0,   0,   0,   62,  432, 1,   0,   0,
        0,   64,  434, 1,   0,   0,   0,   66,  436, 1,   0,   0,   0,   68,  455, 1,   0,   0,   0,   70,  469, 1,
        0,   0,   0,   72,  483, 1,   0,   0,   0,   74,  488, 1,   0,   0,   0,   76,  492, 1,   0,   0,   0,   78,
        497, 1,   0,   0,   0,   80,  502, 1,   0,   0,   0,   82,  509, 1,   0,   0,   0,   84,  516, 1,   0,   0,
        0,   86,  521, 1,   0,   0,   0,   88,  528, 1,   0,   0,   0,   90,  532, 1,   0,   0,   0,   92,  534, 1,
        0,   0,   0,   94,  96,  5,   94,  0,   0,   95,  94,  1,   0,   0,   0,   95,  96,  1,   0,   0,   0,   96,
        97,  1,   0,   0,   0,   97,  103, 3,   2,   1,   0,   98,  99,  3,   90,  45,  0,   99,  100, 3,   2,   1,
        0,   100, 102, 1,   0,   0,   0,   101, 98,  1,   0,   0,   0,   102, 105, 1,   0,   0,   0,   103, 101, 1,
        0,   0,   0,   103, 104, 1,   0,   0,   0,   104, 107, 1,   0,   0,   0,   105, 103, 1,   0,   0,   0,   106,
        108, 5,   94,  0,   0,   107, 106, 1,   0,   0,   0,   107, 108, 1,   0,   0,   0,   108, 109, 1,   0,   0,
        0,   109, 110, 5,   0,   0,   1,   110, 1,   1,   0,   0,   0,   111, 124, 3,   4,   2,   0,   112, 124, 3,
        6,   3,   0,   113, 124, 3,   10,  5,   0,   114, 124, 3,   12,  6,   0,   115, 124, 3,   14,  7,   0,   116,
        124, 3,   16,  8,   0,   117, 124, 3,   18,  9,   0,   118, 124, 3,   20,  10,  0,   119, 124, 3,   26,  13,
        0,   120, 124, 3,   28,  14,  0,   121, 124, 3,   30,  15,  0,   122, 124, 3,   32,  16,  0,   123, 111, 1,
        0,   0,   0,   123, 112, 1,   0,   0,   0,   123, 113, 1,   0,   0,   0,   123, 114, 1,   0,   0,   0,   123,
        115, 1,   0,   0,   0,   123, 116, 1,   0,   0,   0,   123, 117, 1,   0,   0,   0,   123, 118, 1,   0,   0,
        0,   123, 119, 1,   0,   0,   0,   123, 120, 1,   0,   0,   0,   123, 121, 1,   0,   0,   0,   123, 122, 1,
        0,   0,   0,   124, 3,   1,   0,   0,   0,   125, 127, 3,   64,  32,  0,   126, 125, 1,   0,   0,   0,   127,
        128, 1,   0,   0,   0,   128, 126, 1,   0,   0,   0,   128, 129, 1,   0,   0,   0,   129, 130, 1,   0,   0,
        0,   130, 138, 5,   6,   0,   0,   131, 133, 3,   34,  17,  0,   132, 131, 1,   0,   0,   0,   132, 133, 1,
        0,   0,   0,   133, 134, 1,   0,   0,   0,   134, 136, 5,   62,  0,   0,   135, 137, 5,   94,  0,   0,   136,
        135, 1,   0,   0,   0,   136, 137, 1,   0,   0,   0,   137, 139, 1,   0,   0,   0,   138, 132, 1,   0,   0,
        0,   138, 139, 1,   0,   0,   0,   139, 140, 1,   0,   0,   0,   140, 141, 3,   34,  17,  0,   141, 5,   1,
        0,   0,   0,   142, 143, 3,   62,  31,  0,   143, 144, 3,   8,   4,   0,   144, 145, 3,   62,  31,  0,   145,
        7,   1,   0,   0,   0,   146, 162, 5,   53,  0,   0,   147, 162, 5,   63,  0,   0,   148, 162, 5,   55,  0,
        0,   149, 162, 5,   57,  0,   0,   150, 162, 5,   59,  0,   0,   151, 162, 5,   44,  0,   0,   152, 162, 5,
        49,  0,   0,   153, 162, 5,   39,  0,   0,   154, 162, 5,   33,  0,   0,   155, 162, 5,   27,  0,   0,   156,
        162, 5,   37,  0,   0,   157, 162, 5,   42,  0,   0,   158, 162, 5,   47,  0,   0,   159, 162, 5,   25,  0,
        0,   160, 162, 5,   31,  0,   0,   161, 146, 1,   0,   0,   0,   161, 147, 1,   0,   0,   0,   161, 148, 1,
        0,   0,   0,   161, 149, 1,   0,   0,   0,   161, 150, 1,   0,   0,   0,   161, 151, 1,   0,   0,   0,   161,
        152, 1,   0,   0,   0,   161, 153, 1,   0,   0,   0,   161, 154, 1,   0,   0,   0,   161, 155, 1,   0,   0,
        0,   161, 156, 1,   0,   0,   0,   161, 157, 1,   0,   0,   0,   161, 158, 1,   0,   0,   0,   161, 159, 1,
        0,   0,   0,   161, 160, 1,   0,   0,   0,   162, 9,   1,   0,   0,   0,   163, 164, 3,   62,  31,  0,   164,
        165, 3,   34,  17,  0,   165, 11,  1,   0,   0,   0,   166, 176, 3,   82,  41,  0,   167, 173, 3,   2,   1,
        0,   168, 169, 3,   90,  45,  0,   169, 170, 3,   2,   1,   0,   170, 172, 1,   0,   0,   0,   171, 168, 1,
        0,   0,   0,   172, 175, 1,   0,   0,   0,   173, 171, 1,   0,   0,   0,   173, 174, 1,   0,   0,   0,   174,
        177, 1,   0,   0,   0,   175, 173, 1,   0,   0,   0,   176, 167, 1,   0,   0,   0,   176, 177, 1,   0,   0,
        0,   177, 178, 1,   0,   0,   0,   178, 179, 3,   84,  42,  0,   179, 195, 1,   0,   0,   0,   180, 190, 3,
        80,  40,  0,   181, 187, 3,   2,   1,   0,   182, 183, 3,   90,  45,  0,   183, 184, 3,   2,   1,   0,   184,
        186, 1,   0,   0,   0,   185, 182, 1,   0,   0,   0,   186, 189, 1,   0,   0,   0,   187, 185, 1,   0,   0,
        0,   187, 188, 1,   0,   0,   0,   188, 191, 1,   0,   0,   0,   189, 187, 1,   0,   0,   0,   190, 181, 1,
        0,   0,   0,   190, 191, 1,   0,   0,   0,   191, 192, 1,   0,   0,   0,   192, 193, 3,   84,  42,  0,   193,
        195, 1,   0,   0,   0,   194, 166, 1,   0,   0,   0,   194, 180, 1,   0,   0,   0,   195, 13,  1,   0,   0,
        0,   196, 197, 3,   64,  32,  0,   197, 198, 3,   62,  31,  0,   198, 199, 3,   62,  31,  0,   199, 200, 3,
        12,  6,   0,   200, 208, 1,   0,   0,   0,   201, 202, 5,   66,  0,   0,   202, 203, 3,   64,  32,  0,   203,
        204, 3,   62,  31,  0,   204, 205, 3,   62,  31,  0,   205, 206, 3,   12,  6,   0,   206, 208, 1,   0,   0,
        0,   207, 196, 1,   0,   0,   0,   207, 201, 1,   0,   0,   0,   208, 15,  1,   0,   0,   0,   209, 210, 5,
        67,  0,   0,   210, 211, 3,   34,  17,  0,   211, 17,  1,   0,   0,   0,   212, 213, 5,   73,  0,   0,   213,
        214, 3,   62,  31,  0,   214, 221, 3,   2,   1,   0,   215, 216, 5,   74,  0,   0,   216, 217, 3,   62,  31,
        0,   217, 218, 3,   2,   1,   0,   218, 220, 1,   0,   0,   0,   219, 215, 1,   0,   0,   0,   220, 223, 1,
        0,   0,   0,   221, 219, 1,   0,   0,   0,   221, 222, 1,   0,   0,   0,   222, 226, 1,   0,   0,   0,   223,
        221, 1,   0,   0,   0,   224, 225, 5,   75,  0,   0,   225, 227, 3,   2,   1,   0,   226, 224, 1,   0,   0,
        0,   226, 227, 1,   0,   0,   0,   227, 19,  1,   0,   0,   0,   228, 229, 5,   76,  0,   0,   229, 230, 3,
        62,  31,  0,   230, 231, 3,   22,  11,  0,   231, 232, 3,   24,  12,  0,   232, 21,  1,   0,   0,   0,   233,
        234, 1,   0,   0,   0,   234, 23,  1,   0,   0,   0,   235, 236, 1,   0,   0,   0,   236, 25,  1,   0,   0,
        0,   237, 238, 5,   87,  0,   0,   238, 240, 5,   71,  0,   0,   239, 241, 3,   62,  31,  0,   240, 239, 1,
        0,   0,   0,   240, 241, 1,   0,   0,   0,   241, 243, 1,   0,   0,   0,   242, 244, 3,   62,  31,  0,   243,
        242, 1,   0,   0,   0,   243, 244, 1,   0,   0,   0,   244, 245, 1,   0,   0,   0,   245, 272, 3,   2,   1,
        0,   246, 247, 5,   87,  0,   0,   247, 249, 5,   72,  0,   0,   248, 250, 3,   62,  31,  0,   249, 248, 1,
        0,   0,   0,   249, 250, 1,   0,   0,   0,   250, 252, 1,   0,   0,   0,   251, 253, 3,   62,  31,  0,   252,
        251, 1,   0,   0,   0,   252, 253, 1,   0,   0,   0,   253, 254, 1,   0,   0,   0,   254, 272, 3,   2,   1,
        0,   255, 257, 5,   71,  0,   0,   256, 258, 3,   62,  31,  0,   257, 256, 1,   0,   0,   0,   257, 258, 1,
        0,   0,   0,   258, 260, 1,   0,   0,   0,   259, 261, 3,   62,  31,  0,   260, 259, 1,   0,   0,   0,   260,
        261, 1,   0,   0,   0,   261, 262, 1,   0,   0,   0,   262, 272, 3,   2,   1,   0,   263, 265, 5,   72,  0,
        0,   264, 266, 3,   62,  31,  0,   265, 264, 1,   0,   0,   0,   265, 266, 1,   0,   0,   0,   266, 268, 1,
        0,   0,   0,   267, 269, 3,   62,  31,  0,   268, 267, 1,   0,   0,   0,   268, 269, 1,   0,   0,   0,   269,
        270, 1,   0,   0,   0,   270, 272, 3,   2,   1,   0,   271, 237, 1,   0,   0,   0,   271, 246, 1,   0,   0,
        0,   271, 255, 1,   0,   0,   0,   271, 263, 1,   0,   0,   0,   272, 27,  1,   0,   0,   0,   273, 274, 5,
        88,  0,   0,   274, 275, 3,   2,   1,   0,   275, 29,  1,   0,   0,   0,   276, 277, 5,   77,  0,   0,   277,
        278, 3,   2,   1,   0,   278, 31,  1,   0,   0,   0,   279, 280, 5,   78,  0,   0,   280, 281, 3,   2,   1,
        0,   281, 33,  1,   0,   0,   0,   282, 295, 3,   4,   2,   0,   283, 295, 3,   10,  5,   0,   284, 295, 3,
        36,  18,  0,   285, 295, 3,   40,  20,  0,   286, 295, 3,   44,  22,  0,   287, 295, 3,   48,  24,  0,   288,
        295, 3,   50,  25,  0,   289, 295, 3,   54,  27,  0,   290, 295, 3,   56,  28,  0,   291, 295, 3,   58,  29,
        0,   292, 295, 3,   60,  30,  0,   293, 295, 3,   62,  31,  0,   294, 282, 1,   0,   0,   0,   294, 283, 1,
        0,   0,   0,   294, 284, 1,   0,   0,   0,   294, 285, 1,   0,   0,   0,   294, 286, 1,   0,   0,   0,   294,
        287, 1,   0,   0,   0,   294, 288, 1,   0,   0,   0,   294, 289, 1,   0,   0,   0,   294, 290, 1,   0,   0,
        0,   294, 291, 1,   0,   0,   0,   294, 292, 1,   0,   0,   0,   294, 293, 1,   0,   0,   0,   295, 35,  1,
        0,   0,   0,   296, 298, 3,   62,  31,  0,   297, 299, 5,   94,  0,   0,   298, 297, 1,   0,   0,   0,   298,
        299, 1,   0,   0,   0,   299, 300, 1,   0,   0,   0,   300, 302, 3,   38,  19,  0,   301, 303, 5,   94,  0,
        0,   302, 301, 1,   0,   0,   0,   302, 303, 1,   0,   0,   0,   303, 304, 1,   0,   0,   0,   304, 305, 3,
        62,  31,  0,   305, 37,  1,   0,   0,   0,   306, 331, 5,   93,  0,   0,   307, 331, 5,   45,  0,   0,   308,
        331, 5,   40,  0,   0,   309, 331, 5,   46,  0,   0,   310, 331, 5,   50,  0,   0,   311, 331, 5,   41,  0,
        0,   312, 331, 5,   60,  0,   0,   313, 331, 5,   36,  0,   0,   314, 331, 5,   30,  0,   0,   315, 331, 5,
        35,  0,   0,   316, 331, 5,   29,  0,   0,   317, 331, 5,   43,  0,   0,   318, 331, 5,   48,  0,   0,   319,
        331, 5,   38,  0,   0,   320, 331, 5,   34,  0,   0,   321, 331, 5,   28,  0,   0,   322, 331, 5,   32,  0,
        0,   323, 331, 5,   26,  0,   0,   324, 331, 5,   61,  0,   0,   325, 331, 5,   51,  0,   0,   326, 331, 5,
        54,  0,   0,   327, 331, 5,   64,  0,   0,   328, 331, 5,   56,  0,   0,   329, 331, 5,   58,  0,   0,   330,
        306, 1,   0,   0,   0,   330, 307, 1,   0,   0,   0,   330, 308, 1,   0,   0,   0,   330, 309, 1,   0,   0,
        0,   330, 310, 1,   0,   0,   0,   330, 311, 1,   0,   0,   0,   330, 312, 1,   0,   0,   0,   330, 313, 1,
        0,   0,   0,   330, 314, 1,   0,   0,   0,   330, 315, 1,   0,   0,   0,   330, 316, 1,   0,   0,   0,   330,
        317, 1,   0,   0,   0,   330, 318, 1,   0,   0,   0,   330, 319, 1,   0,   0,   0,   330, 320, 1,   0,   0,
        0,   330, 321, 1,   0,   0,   0,   330, 322, 1,   0,   0,   0,   330, 323, 1,   0,   0,   0,   330, 324, 1,
        0,   0,   0,   330, 325, 1,   0,   0,   0,   330, 326, 1,   0,   0,   0,   330, 327, 1,   0,   0,   0,   330,
        328, 1,   0,   0,   0,   330, 329, 1,   0,   0,   0,   331, 39,  1,   0,   0,   0,   332, 333, 3,   62,  31,
        0,   333, 334, 3,   42,  21,  0,   334, 41,  1,   0,   0,   0,   335, 336, 5,   24,  0,   0,   336, 343, 3,
        62,  31,  0,   337, 343, 5,   19,  0,   0,   338, 343, 5,   20,  0,   0,   339, 343, 5,   21,  0,   0,   340,
        343, 5,   22,  0,   0,   341, 343, 5,   23,  0,   0,   342, 335, 1,   0,   0,   0,   342, 337, 1,   0,   0,
        0,   342, 338, 1,   0,   0,   0,   342, 339, 1,   0,   0,   0,   342, 340, 1,   0,   0,   0,   342, 341, 1,
        0,   0,   0,   343, 43,  1,   0,   0,   0,   344, 345, 3,   46,  23,  0,   345, 346, 3,   62,  31,  0,   346,
        45,  1,   0,   0,   0,   347, 350, 5,   52,  0,   0,   348, 350, 5,   50,  0,   0,   349, 347, 1,   0,   0,
        0,   349, 348, 1,   0,   0,   0,   350, 47,  1,   0,   0,   0,   351, 352, 5,   73,  0,   0,   352, 353, 3,
        62,  31,  0,   353, 360, 3,   34,  17,  0,   354, 355, 5,   74,  0,   0,   355, 356, 3,   62,  31,  0,   356,
        357, 3,   34,  17,  0,   357, 359, 1,   0,   0,   0,   358, 354, 1,   0,   0,   0,   359, 362, 1,   0,   0,
        0,   360, 358, 1,   0,   0,   0,   360, 361, 1,   0,   0,   0,   361, 365, 1,   0,   0,   0,   362, 360, 1,
        0,   0,   0,   363, 364, 5,   75,  0,   0,   364, 366, 3,   34,  17,  0,   365, 363, 1,   0,   0,   0,   365,
        366, 1,   0,   0,   0,   366, 49,  1,   0,   0,   0,   367, 368, 5,   76,  0,   0,   368, 369, 3,   62,  31,
        0,   369, 370, 3,   22,  11,  0,   370, 371, 3,   52,  26,  0,   371, 51,  1,   0,   0,   0,   372, 373, 1,
        0,   0,   0,   373, 53,  1,   0,   0,   0,   374, 375, 5,   87,  0,   0,   375, 377, 5,   71,  0,   0,   376,
        378, 3,   62,  31,  0,   377, 376, 1,   0,   0,   0,   377, 378, 1,   0,   0,   0,   378, 380, 1,   0,   0,
        0,   379, 381, 3,   62,  31,  0,   380, 379, 1,   0,   0,   0,   380, 381, 1,   0,   0,   0,   381, 382, 1,
        0,   0,   0,   382, 409, 3,   34,  17,  0,   383, 384, 5,   87,  0,   0,   384, 386, 5,   72,  0,   0,   385,
        387, 3,   62,  31,  0,   386, 385, 1,   0,   0,   0,   386, 387, 1,   0,   0,   0,   387, 389, 1,   0,   0,
        0,   388, 390, 3,   62,  31,  0,   389, 388, 1,   0,   0,   0,   389, 390, 1,   0,   0,   0,   390, 391, 1,
        0,   0,   0,   391, 409, 3,   34,  17,  0,   392, 394, 5,   71,  0,   0,   393, 395, 3,   62,  31,  0,   394,
        393, 1,   0,   0,   0,   394, 395, 1,   0,   0,   0,   395, 397, 1,   0,   0,   0,   396, 398, 3,   62,  31,
        0,   397, 396, 1,   0,   0,   0,   397, 398, 1,   0,   0,   0,   398, 399, 1,   0,   0,   0,   399, 409, 3,
        34,  17,  0,   400, 402, 5,   72,  0,   0,   401, 403, 3,   62,  31,  0,   402, 401, 1,   0,   0,   0,   402,
        403, 1,   0,   0,   0,   403, 405, 1,   0,   0,   0,   404, 406, 3,   62,  31,  0,   405, 404, 1,   0,   0,
        0,   405, 406, 1,   0,   0,   0,   406, 407, 1,   0,   0,   0,   407, 409, 3,   34,  17,  0,   408, 374, 1,
        0,   0,   0,   408, 383, 1,   0,   0,   0,   408, 392, 1,   0,   0,   0,   408, 400, 1,   0,   0,   0,   409,
        55,  1,   0,   0,   0,   410, 411, 5,   88,  0,   0,   411, 412, 3,   34,  17,  0,   412, 57,  1,   0,   0,
        0,   413, 414, 3,   62,  31,  0,   414, 415, 3,   62,  31,  0,   415, 416, 3,   12,  6,   0,   416, 423, 1,
        0,   0,   0,   417, 418, 5,   66,  0,   0,   418, 419, 3,   62,  31,  0,   419, 420, 3,   62,  31,  0,   420,
        421, 3,   12,  6,   0,   421, 423, 1,   0,   0,   0,   422, 413, 1,   0,   0,   0,   422, 417, 1,   0,   0,
        0,   423, 59,  1,   0,   0,   0,   424, 427, 5,   1,   0,   0,   425, 427, 5,   2,   0,   0,   426, 424, 1,
        0,   0,   0,   426, 425, 1,   0,   0,   0,   427, 61,  1,   0,   0,   0,   428, 433, 3,   64,  32,  0,   429,
        433, 3,   66,  33,  0,   430, 433, 3,   68,  34,  0,   431, 433, 3,   70,  35,  0,   432, 428, 1,   0,   0,
        0,   432, 429, 1,   0,   0,   0,   432, 430, 1,   0,   0,   0,   432, 431, 1,   0,   0,   0,   433, 63,  1,
        0,   0,   0,   434, 435, 5,   95,  0,   0,   435, 65,  1,   0,   0,   0,   436, 451, 3,   82,  41,  0,   437,
        443, 3,   2,   1,   0,   438, 439, 3,   90,  45,  0,   439, 440, 3,   2,   1,   0,   440, 442, 1,   0,   0,
        0,   441, 438, 1,   0,   0,   0,   442, 445, 1,   0,   0,   0,   443, 441, 1,   0,   0,   0,   443, 444, 1,
        0,   0,   0,   444, 446, 1,   0,   0,   0,   445, 443, 1,   0,   0,   0,   446, 447, 3,   90,  45,  0,   447,
        449, 1,   0,   0,   0,   448, 437, 1,   0,   0,   0,   448, 449, 1,   0,   0,   0,   449, 450, 1,   0,   0,
        0,   450, 452, 3,   34,  17,  0,   451, 448, 1,   0,   0,   0,   451, 452, 1,   0,   0,   0,   452, 453, 1,
        0,   0,   0,   453, 454, 3,   84,  42,  0,   454, 67,  1,   0,   0,   0,   455, 465, 3,   86,  43,  0,   456,
        462, 3,   4,   2,   0,   457, 458, 3,   92,  46,  0,   458, 459, 3,   4,   2,   0,   459, 461, 1,   0,   0,
        0,   460, 457, 1,   0,   0,   0,   461, 464, 1,   0,   0,   0,   462, 460, 1,   0,   0,   0,   462, 463, 1,
        0,   0,   0,   463, 466, 1,   0,   0,   0,   464, 462, 1,   0,   0,   0,   465, 456, 1,   0,   0,   0,   465,
        466, 1,   0,   0,   0,   466, 467, 1,   0,   0,   0,   467, 468, 3,   88,  44,  0,   468, 69,  1,   0,   0,
        0,   469, 479, 3,   82,  41,  0,   470, 476, 3,   34,  17,  0,   471, 472, 3,   92,  46,  0,   472, 473, 3,
        34,  17,  0,   473, 475, 1,   0,   0,   0,   474, 471, 1,   0,   0,   0,   475, 478, 1,   0,   0,   0,   476,
        474, 1,   0,   0,   0,   476, 477, 1,   0,   0,   0,   477, 480, 1,   0,   0,   0,   478, 476, 1,   0,   0,
        0,   479, 470, 1,   0,   0,   0,   479, 480, 1,   0,   0,   0,   480, 481, 1,   0,   0,   0,   481, 482, 3,
        84,  42,  0,   482, 71,  1,   0,   0,   0,   483, 485, 5,   17,  0,   0,   484, 486, 5,   94,  0,   0,   485,
        484, 1,   0,   0,   0,   485, 486, 1,   0,   0,   0,   486, 73,  1,   0,   0,   0,   487, 489, 5,   94,  0,
        0,   488, 487, 1,   0,   0,   0,   488, 489, 1,   0,   0,   0,   489, 490, 1,   0,   0,   0,   490, 491, 5,
        18,  0,   0,   491, 75,  1,   0,   0,   0,   492, 494, 5,   15,  0,   0,   493, 495, 5,   94,  0,   0,   494,
        493, 1,   0,   0,   0,   494, 495, 1,   0,   0,   0,   495, 77,  1,   0,   0,   0,   496, 498, 5,   94,  0,
        0,   497, 496, 1,   0,   0,   0,   497, 498, 1,   0,   0,   0,   498, 499, 1,   0,   0,   0,   499, 500, 5,
        16,  0,   0,   500, 79,  1,   0,   0,   0,   501, 503, 5,   94,  0,   0,   502, 501, 1,   0,   0,   0,   502,
        503, 1,   0,   0,   0,   503, 504, 1,   0,   0,   0,   504, 506, 5,   10,  0,   0,   505, 507, 5,   94,  0,
        0,   506, 505, 1,   0,   0,   0,   506, 507, 1,   0,   0,   0,   507, 81,  1,   0,   0,   0,   508, 510, 5,
        94,  0,   0,   509, 508, 1,   0,   0,   0,   509, 510, 1,   0,   0,   0,   510, 511, 1,   0,   0,   0,   511,
        513, 5,   11,  0,   0,   512, 514, 5,   94,  0,   0,   513, 512, 1,   0,   0,   0,   513, 514, 1,   0,   0,
        0,   514, 83,  1,   0,   0,   0,   515, 517, 5,   94,  0,   0,   516, 515, 1,   0,   0,   0,   516, 517, 1,
        0,   0,   0,   517, 518, 1,   0,   0,   0,   518, 519, 5,   12,  0,   0,   519, 85,  1,   0,   0,   0,   520,
        522, 5,   94,  0,   0,   521, 520, 1,   0,   0,   0,   521, 522, 1,   0,   0,   0,   522, 523, 1,   0,   0,
        0,   523, 525, 5,   13,  0,   0,   524, 526, 5,   94,  0,   0,   525, 524, 1,   0,   0,   0,   525, 526, 1,
        0,   0,   0,   526, 87,  1,   0,   0,   0,   527, 529, 5,   94,  0,   0,   528, 527, 1,   0,   0,   0,   528,
        529, 1,   0,   0,   0,   529, 530, 1,   0,   0,   0,   530, 531, 5,   14,  0,   0,   531, 89,  1,   0,   0,
        0,   532, 533, 7,   0,   0,   0,   533, 91,  1,   0,   0,   0,   534, 535, 7,   1,   0,   0,   535, 93,  1,
        0,   0,   0,   65,  95,  103, 107, 123, 128, 132, 136, 138, 161, 173, 176, 187, 190, 194, 207, 221, 226, 240,
        243, 249, 252, 257, 260, 265, 268, 271, 294, 298, 302, 330, 342, 349, 360, 365, 377, 380, 386, 389, 394, 397,
        402, 405, 408, 422, 426, 432, 443, 448, 451, 462, 465, 476, 479, 485, 488, 494, 497, 502, 506, 509, 513, 516,
        521, 525, 528
    };
    staticData->serializedATN = antlr4::atn::SerializedATNView(
        serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0])
    );

    antlr4::atn::ATNDeserializer deserializer;
    staticData->atn = deserializer.deserialize(staticData->serializedATN);

    const size_t count = staticData->atn->getNumberOfDecisions();
    staticData->decisionToDFA.reserve(count);
    for (size_t i = 0; i < count; i++) {
        staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
    }
    whixyparserParserStaticData = std::move(staticData);
}

} // namespace

WhixyParser::WhixyParser(TokenStream* input): WhixyParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

WhixyParser::WhixyParser(TokenStream* input, const antlr4::atn::ParserATNSimulatorOptions& options): Parser(input)
{
    WhixyParser::initialize();
    _interpreter = new atn::ParserATNSimulator(
        this, *whixyparserParserStaticData->atn, whixyparserParserStaticData->decisionToDFA,
        whixyparserParserStaticData->sharedContextCache, options
    );
}

WhixyParser::~WhixyParser() { delete _interpreter; }

const atn::ATN& WhixyParser::getATN() const { return *whixyparserParserStaticData->atn; }

std::string WhixyParser::getGrammarFileName() const { return "WhixyParser.g4"; }

const std::vector<std::string>& WhixyParser::getRuleNames() const { return whixyparserParserStaticData->ruleNames; }

const dfa::Vocabulary& WhixyParser::getVocabulary() const { return whixyparserParserStaticData->vocabulary; }

antlr4::atn::SerializedATNView WhixyParser::getSerializedATN() const
{
    return whixyparserParserStaticData->serializedATN;
}

//----------------- SrcFileContext ------------------------------------------------------------------

WhixyParser::SrcFileContext::SrcFileContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<WhixyParser::StmtContext*> WhixyParser::SrcFileContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::SrcFileContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

tree::TerminalNode* WhixyParser::SrcFileContext::EOF() { return getToken(WhixyParser::EOF, 0); }

std::vector<tree::TerminalNode*> WhixyParser::SrcFileContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::SrcFileContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

std::vector<WhixyParser::StmtSepContext*> WhixyParser::SrcFileContext::stmtSep()
{
    return getRuleContexts<WhixyParser::StmtSepContext>();
}

WhixyParser::StmtSepContext* WhixyParser::SrcFileContext::stmtSep(size_t i)
{
    return getRuleContext<WhixyParser::StmtSepContext>(i);
}

size_t WhixyParser::SrcFileContext::getRuleIndex() const { return WhixyParser::RuleSrcFile; }

std::any WhixyParser::SrcFileContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitSrcFile(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::SrcFileContext* WhixyParser::srcFile()
{
    SrcFileContext* _localctx = _tracker.createInstance<SrcFileContext>(_ctx, getState());
    enterRule(_localctx, 0, WhixyParser::RuleSrcFile);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(95);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
            setState(94);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }
        setState(97);
        stmt();
        setState(103);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(98);
                stmtSep();
                setState(99);
                stmt();
            }
            setState(105);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
        }
        setState(107);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(106);
            match(WhixyParser::NEWLINE);
        }
        setState(109);
        match(WhixyParser::EOF);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

WhixyParser::StmtContext::StmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::ValsStmtContext* WhixyParser::StmtContext::valsStmt()
{
    return getRuleContext<WhixyParser::ValsStmtContext>(0);
}

WhixyParser::AssignOpStmtContext* WhixyParser::StmtContext::assignOpStmt()
{
    return getRuleContext<WhixyParser::AssignOpStmtContext>(0);
}

WhixyParser::CallStmtContext* WhixyParser::StmtContext::callStmt()
{
    return getRuleContext<WhixyParser::CallStmtContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::StmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::RoutineStmtContext* WhixyParser::StmtContext::routineStmt()
{
    return getRuleContext<WhixyParser::RoutineStmtContext>(0);
}

WhixyParser::ReturnStmtContext* WhixyParser::StmtContext::returnStmt()
{
    return getRuleContext<WhixyParser::ReturnStmtContext>(0);
}

WhixyParser::IfStmtContext* WhixyParser::StmtContext::ifStmt() { return getRuleContext<WhixyParser::IfStmtContext>(0); }

WhixyParser::WhereStmtContext* WhixyParser::StmtContext::whereStmt()
{
    return getRuleContext<WhixyParser::WhereStmtContext>(0);
}

WhixyParser::LoopStmtContext* WhixyParser::StmtContext::loopStmt()
{
    return getRuleContext<WhixyParser::LoopStmtContext>(0);
}

WhixyParser::ComptStmtContext* WhixyParser::StmtContext::comptStmt()
{
    return getRuleContext<WhixyParser::ComptStmtContext>(0);
}

WhixyParser::DeferStmtContext* WhixyParser::StmtContext::deferStmt()
{
    return getRuleContext<WhixyParser::DeferStmtContext>(0);
}

WhixyParser::ErrdeferStmtContext* WhixyParser::StmtContext::errdeferStmt()
{
    return getRuleContext<WhixyParser::ErrdeferStmtContext>(0);
}

size_t WhixyParser::StmtContext::getRuleIndex() const { return WhixyParser::RuleStmt; }

std::any WhixyParser::StmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::StmtContext* WhixyParser::stmt()
{
    StmtContext* _localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
    enterRule(_localctx, 2, WhixyParser::RuleStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(123);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(111);
            valsStmt();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(112);
            assignOpStmt();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(113);
            callStmt();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(114);
            blockStmt();
            break;
        }

        case 5: {
            enterOuterAlt(_localctx, 5);
            setState(115);
            routineStmt();
            break;
        }

        case 6: {
            enterOuterAlt(_localctx, 6);
            setState(116);
            returnStmt();
            break;
        }

        case 7: {
            enterOuterAlt(_localctx, 7);
            setState(117);
            ifStmt();
            break;
        }

        case 8: {
            enterOuterAlt(_localctx, 8);
            setState(118);
            whereStmt();
            break;
        }

        case 9: {
            enterOuterAlt(_localctx, 9);
            setState(119);
            loopStmt();
            break;
        }

        case 10: {
            enterOuterAlt(_localctx, 10);
            setState(120);
            comptStmt();
            break;
        }

        case 11: {
            enterOuterAlt(_localctx, 11);
            setState(121);
            deferStmt();
            break;
        }

        case 12: {
            enterOuterAlt(_localctx, 12);
            setState(122);
            errdeferStmt();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ValsStmtContext ------------------------------------------------------------------

WhixyParser::ValsStmtContext::ValsStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ValsStmtContext::COLON() { return getToken(WhixyParser::COLON, 0); }

std::vector<WhixyParser::ExprContext*> WhixyParser::ValsStmtContext::expr()
{
    return getRuleContexts<WhixyParser::ExprContext>();
}

WhixyParser::ExprContext* WhixyParser::ValsStmtContext::expr(size_t i)
{
    return getRuleContext<WhixyParser::ExprContext>(i);
}

std::vector<WhixyParser::TokenContext*> WhixyParser::ValsStmtContext::token()
{
    return getRuleContexts<WhixyParser::TokenContext>();
}

WhixyParser::TokenContext* WhixyParser::ValsStmtContext::token(size_t i)
{
    return getRuleContext<WhixyParser::TokenContext>(i);
}

tree::TerminalNode* WhixyParser::ValsStmtContext::EQUAL() { return getToken(WhixyParser::EQUAL, 0); }

tree::TerminalNode* WhixyParser::ValsStmtContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::ValsStmtContext::getRuleIndex() const { return WhixyParser::RuleValsStmt; }

std::any WhixyParser::ValsStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitValsStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ValsStmtContext* WhixyParser::valsStmt()
{
    ValsStmtContext* _localctx = _tracker.createInstance<ValsStmtContext>(_ctx, getState());
    enterRule(_localctx, 4, WhixyParser::RuleValsStmt);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(126);
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
            setState(125);
            token();
            setState(128);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        while (_la == WhixyParser::TOKEN);
        setState(130);
        match(WhixyParser::COLON);
        setState(138);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
            setState(132);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if ((((_la & ~0x3fULL) == 0) && ((1ULL << _la) & 5629499534223366) != 0)
                || ((((_la - 66) & ~0x3fULL) == 0) && ((1ULL << (_la - 66)) & 811599073) != 0)) {
                setState(131);
                expr();
            }
            setState(134);
            match(WhixyParser::EQUAL);
            setState(136);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
            case 1: {
                setState(135);
                match(WhixyParser::NEWLINE);
                break;
            }

            default: break;
            }
            break;
        }

        default: break;
        }
        setState(140);
        expr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AssignOpStmtContext ------------------------------------------------------------------

WhixyParser::AssignOpStmtContext::AssignOpStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<WhixyParser::AtomContext*> WhixyParser::AssignOpStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::AssignOpStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::AssignOpContext* WhixyParser::AssignOpStmtContext::assignOp()
{
    return getRuleContext<WhixyParser::AssignOpContext>(0);
}

size_t WhixyParser::AssignOpStmtContext::getRuleIndex() const { return WhixyParser::RuleAssignOpStmt; }

std::any WhixyParser::AssignOpStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAssignOpStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::AssignOpStmtContext* WhixyParser::assignOpStmt()
{
    AssignOpStmtContext* _localctx = _tracker.createInstance<AssignOpStmtContext>(_ctx, getState());
    enterRule(_localctx, 6, WhixyParser::RuleAssignOpStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(142);
        atom();
        setState(143);
        assignOp();
        setState(144);
        atom();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AssignOpContext ------------------------------------------------------------------

WhixyParser::AssignOpContext::AssignOpContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::AssignOpContext::getRuleIndex() const { return WhixyParser::RuleAssignOp; }

void WhixyParser::AssignOpContext::copyFrom(AssignOpContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- LeftShiftAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftShiftAssignOpContext::LESSTHAN_LESSTHAN_EQUAL()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN_EQUAL, 0);
}

WhixyParser::LeftShiftAssignOpContext::LeftShiftAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LeftShiftAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLeftShiftAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingMultiplicationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingMultiplicationAssignOpContext::ASTERISK_PERCENT_EQUAL()
{
    return getToken(WhixyParser::ASTERISK_PERCENT_EQUAL, 0);
}

WhixyParser::WrappingMultiplicationAssignOpContext::WrappingMultiplicationAssignOpContext(AssignOpContext* ctx)
{
    copyFrom(ctx);
}

std::any WhixyParser::WrappingMultiplicationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingMultiplicationAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LeftRotationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftRotationAssignOpContext::LESSTHAN_LESSTHAN_PERCENT_EQUAL()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN_PERCENT_EQUAL, 0);
}

WhixyParser::LeftRotationAssignOpContext::LeftRotationAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LeftRotationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLeftRotationAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AndAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AndAssignOpContext::AMPERSAND_EQUAL()
{
    return getToken(WhixyParser::AMPERSAND_EQUAL, 0);
}

WhixyParser::AndAssignOpContext::AndAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AndAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAndAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- DivisionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::DivisionAssignOpContext::SLASH_EQUAL()
{
    return getToken(WhixyParser::SLASH_EQUAL, 0);
}

WhixyParser::DivisionAssignOpContext::DivisionAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::DivisionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDivisionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- ModulusAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::ModulusAssignOpContext::PERCENT_EQUAL()
{
    return getToken(WhixyParser::PERCENT_EQUAL, 0);
}

WhixyParser::ModulusAssignOpContext::ModulusAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::ModulusAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitModulusAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- RightRotationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightRotationAssignOpContext::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL, 0);
}

WhixyParser::RightRotationAssignOpContext::RightRotationAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightRotationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightRotationAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- RightShiftAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightShiftAssignOpContext::GREATERTHAN_GREATERTHAN_EQUAL()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL, 0);
}

WhixyParser::RightShiftAssignOpContext::RightShiftAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightShiftAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightShiftAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingSubtractionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingSubtractionAssignOpContext::MINUS_PERCENT_EQUAL()
{
    return getToken(WhixyParser::MINUS_PERCENT_EQUAL, 0);
}

WhixyParser::WrappingSubtractionAssignOpContext::WrappingSubtractionAssignOpContext(AssignOpContext* ctx)
{
    copyFrom(ctx);
}

std::any WhixyParser::WrappingSubtractionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingSubtractionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- OrAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::OrAssignOpContext::PIPE_EQUAL() { return getToken(WhixyParser::PIPE_EQUAL, 0); }

WhixyParser::OrAssignOpContext::OrAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::OrAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOrAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- MultiplicationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::MultiplicationAssignOpContext::ASTERISK_EQUAL()
{
    return getToken(WhixyParser::ASTERISK_EQUAL, 0);
}

WhixyParser::MultiplicationAssignOpContext::MultiplicationAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::MultiplicationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitMultiplicationAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- XorAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::XorAssignOpContext::CARROT_EQUAL() { return getToken(WhixyParser::CARROT_EQUAL, 0); }

WhixyParser::XorAssignOpContext::XorAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::XorAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitXorAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AdditionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AdditionAssignOpContext::PLUS_EQUAL() { return getToken(WhixyParser::PLUS_EQUAL, 0); }

WhixyParser::AdditionAssignOpContext::AdditionAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AdditionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAdditionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- SubtractionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::SubtractionAssignOpContext::MINUS_EQUAL()
{
    return getToken(WhixyParser::MINUS_EQUAL, 0);
}

WhixyParser::SubtractionAssignOpContext::SubtractionAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::SubtractionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitSubtractionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingAdditionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingAdditionAssignOpContext::PLUS_PERCENT_EQUAL()
{
    return getToken(WhixyParser::PLUS_PERCENT_EQUAL, 0);
}

WhixyParser::WrappingAdditionAssignOpContext::WrappingAdditionAssignOpContext(AssignOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::WrappingAdditionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingAdditionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::AssignOpContext* WhixyParser::assignOp()
{
    AssignOpContext* _localctx = _tracker.createInstance<AssignOpContext>(_ctx, getState());
    enterRule(_localctx, 8, WhixyParser::RuleAssignOp);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(161);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::AMPERSAND_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::AndAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(146);
            match(WhixyParser::AMPERSAND_EQUAL);
            break;
        }

        case WhixyParser::PIPE_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::OrAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(147);
            match(WhixyParser::PIPE_EQUAL);
            break;
        }

        case WhixyParser::PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::ModulusAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(148);
            match(WhixyParser::PERCENT_EQUAL);
            break;
        }

        case WhixyParser::CARROT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::XorAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(149);
            match(WhixyParser::CARROT_EQUAL);
            break;
        }

        case WhixyParser::SLASH_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::DivisionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 5);
            setState(150);
            match(WhixyParser::SLASH_EQUAL);
            break;
        }

        case WhixyParser::PLUS_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::AdditionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 6);
            setState(151);
            match(WhixyParser::PLUS_EQUAL);
            break;
        }

        case WhixyParser::MINUS_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::SubtractionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 7);
            setState(152);
            match(WhixyParser::MINUS_EQUAL);
            break;
        }

        case WhixyParser::ASTERISK_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::MultiplicationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 8);
            setState(153);
            match(WhixyParser::ASTERISK_EQUAL);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LeftShiftAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 9);
            setState(154);
            match(WhixyParser::LESSTHAN_LESSTHAN_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::RightShiftAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 10);
            setState(155);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL);
            break;
        }

        case WhixyParser::ASTERISK_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingMultiplicationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 11);
            setState(156);
            match(WhixyParser::ASTERISK_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::PLUS_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingAdditionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 12);
            setState(157);
            match(WhixyParser::PLUS_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::MINUS_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingSubtractionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 13);
            setState(158);
            match(WhixyParser::MINUS_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::RightRotationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 14);
            setState(159);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LeftRotationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 15);
            setState(160);
            match(WhixyParser::LESSTHAN_LESSTHAN_PERCENT_EQUAL);
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CallStmtContext ------------------------------------------------------------------

WhixyParser::CallStmtContext::CallStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::AtomContext* WhixyParser::CallStmtContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

WhixyParser::ExprContext* WhixyParser::CallStmtContext::expr() { return getRuleContext<WhixyParser::ExprContext>(0); }

size_t WhixyParser::CallStmtContext::getRuleIndex() const { return WhixyParser::RuleCallStmt; }

std::any WhixyParser::CallStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCallStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CallStmtContext* WhixyParser::callStmt()
{
    CallStmtContext* _localctx = _tracker.createInstance<CallStmtContext>(_ctx, getState());
    enterRule(_localctx, 10, WhixyParser::RuleCallStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(163);
        atom();
        setState(164);
        expr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BlockStmtContext ------------------------------------------------------------------

WhixyParser::BlockStmtContext::BlockStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::BlockStmtContext::getRuleIndex() const { return WhixyParser::RuleBlockStmt; }

void WhixyParser::BlockStmtContext::copyFrom(BlockStmtContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- FuncBlockStmtContext ------------------------------------------------------------------

WhixyParser::OParenContext* WhixyParser::FuncBlockStmtContext::oParen()
{
    return getRuleContext<WhixyParser::OParenContext>(0);
}

WhixyParser::CParenContext* WhixyParser::FuncBlockStmtContext::cParen()
{
    return getRuleContext<WhixyParser::CParenContext>(0);
}

std::vector<WhixyParser::StmtContext*> WhixyParser::FuncBlockStmtContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::FuncBlockStmtContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

std::vector<WhixyParser::StmtSepContext*> WhixyParser::FuncBlockStmtContext::stmtSep()
{
    return getRuleContexts<WhixyParser::StmtSepContext>();
}

WhixyParser::StmtSepContext* WhixyParser::FuncBlockStmtContext::stmtSep(size_t i)
{
    return getRuleContext<WhixyParser::StmtSepContext>(i);
}

WhixyParser::FuncBlockStmtContext::FuncBlockStmtContext(BlockStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::FuncBlockStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitFuncBlockStmt(this);
    else
        return visitor->visitChildren(this);
}
//----------------- ProcBlockStmtContext ------------------------------------------------------------------

WhixyParser::DollarParenContext* WhixyParser::ProcBlockStmtContext::dollarParen()
{
    return getRuleContext<WhixyParser::DollarParenContext>(0);
}

WhixyParser::CParenContext* WhixyParser::ProcBlockStmtContext::cParen()
{
    return getRuleContext<WhixyParser::CParenContext>(0);
}

std::vector<WhixyParser::StmtContext*> WhixyParser::ProcBlockStmtContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::ProcBlockStmtContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

std::vector<WhixyParser::StmtSepContext*> WhixyParser::ProcBlockStmtContext::stmtSep()
{
    return getRuleContexts<WhixyParser::StmtSepContext>();
}

WhixyParser::StmtSepContext* WhixyParser::ProcBlockStmtContext::stmtSep(size_t i)
{
    return getRuleContext<WhixyParser::StmtSepContext>(i);
}

WhixyParser::ProcBlockStmtContext::ProcBlockStmtContext(BlockStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::ProcBlockStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitProcBlockStmt(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::BlockStmtContext* WhixyParser::blockStmt()
{
    BlockStmtContext* _localctx = _tracker.createInstance<BlockStmtContext>(_ctx, getState());
    enterRule(_localctx, 12, WhixyParser::RuleBlockStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        setState(194);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
            _localctx = _tracker.createInstance<WhixyParser::FuncBlockStmtContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(166);
            oParen();
            setState(176);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
            case 1: {
                setState(167);
                stmt();
                setState(173);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                    if (alt == 1) {
                        setState(168);
                        stmtSep();
                        setState(169);
                        stmt();
                    }
                    setState(175);
                    _errHandler->sync(this);
                    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
                }
                break;
            }

            default: break;
            }
            setState(178);
            cParen();
            break;
        }

        case 2: {
            _localctx = _tracker.createInstance<WhixyParser::ProcBlockStmtContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(180);
            dollarParen();
            setState(190);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
            case 1: {
                setState(181);
                stmt();
                setState(187);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                    if (alt == 1) {
                        setState(182);
                        stmtSep();
                        setState(183);
                        stmt();
                    }
                    setState(189);
                    _errHandler->sync(this);
                    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
                }
                break;
            }

            default: break;
            }
            setState(192);
            cParen();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- RoutineStmtContext ------------------------------------------------------------------

WhixyParser::RoutineStmtContext::RoutineStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::RoutineStmtContext::getRuleIndex() const { return WhixyParser::RuleRoutineStmt; }

void WhixyParser::RoutineStmtContext::copyFrom(RoutineStmtContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- PlainRoutineStmtContext ------------------------------------------------------------------

WhixyParser::TokenContext* WhixyParser::PlainRoutineStmtContext::token()
{
    return getRuleContext<WhixyParser::TokenContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainRoutineStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainRoutineStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::BlockStmtContext* WhixyParser::PlainRoutineStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::PlainRoutineStmtContext::PlainRoutineStmtContext(RoutineStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainRoutineStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainRoutineStmt(this);
    else
        return visitor->visitChildren(this);
}
//----------------- InlineRoutineStmtContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::InlineRoutineStmtContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

WhixyParser::TokenContext* WhixyParser::InlineRoutineStmtContext::token()
{
    return getRuleContext<WhixyParser::TokenContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::InlineRoutineStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::InlineRoutineStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::BlockStmtContext* WhixyParser::InlineRoutineStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::InlineRoutineStmtContext::InlineRoutineStmtContext(RoutineStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::InlineRoutineStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitInlineRoutineStmt(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::RoutineStmtContext* WhixyParser::routineStmt()
{
    RoutineStmtContext* _localctx = _tracker.createInstance<RoutineStmtContext>(_ctx, getState());
    enterRule(_localctx, 14, WhixyParser::RuleRoutineStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(207);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::TOKEN: {
            _localctx = _tracker.createInstance<WhixyParser::PlainRoutineStmtContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(196);
            token();
            setState(197);
            atom();
            setState(198);
            atom();
            setState(199);
            blockStmt();
            break;
        }

        case WhixyParser::INLINE: {
            _localctx = _tracker.createInstance<WhixyParser::InlineRoutineStmtContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(201);
            match(WhixyParser::INLINE);
            setState(202);
            token();
            setState(203);
            atom();
            setState(204);
            atom();
            setState(205);
            blockStmt();
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

WhixyParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ReturnStmtContext::RETURN() { return getToken(WhixyParser::RETURN, 0); }

WhixyParser::ExprContext* WhixyParser::ReturnStmtContext::expr() { return getRuleContext<WhixyParser::ExprContext>(0); }

size_t WhixyParser::ReturnStmtContext::getRuleIndex() const { return WhixyParser::RuleReturnStmt; }

std::any WhixyParser::ReturnStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitReturnStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ReturnStmtContext* WhixyParser::returnStmt()
{
    ReturnStmtContext* _localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
    enterRule(_localctx, 16, WhixyParser::RuleReturnStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(209);
        match(WhixyParser::RETURN);
        setState(210);
        expr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

WhixyParser::IfStmtContext::IfStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::IfStmtContext::IF() { return getToken(WhixyParser::IF, 0); }

std::vector<WhixyParser::AtomContext*> WhixyParser::IfStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::IfStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

std::vector<WhixyParser::StmtContext*> WhixyParser::IfStmtContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::IfStmtContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

std::vector<tree::TerminalNode*> WhixyParser::IfStmtContext::ELSEIF() { return getTokens(WhixyParser::ELSEIF); }

tree::TerminalNode* WhixyParser::IfStmtContext::ELSEIF(size_t i) { return getToken(WhixyParser::ELSEIF, i); }

tree::TerminalNode* WhixyParser::IfStmtContext::ELSE() { return getToken(WhixyParser::ELSE, 0); }

size_t WhixyParser::IfStmtContext::getRuleIndex() const { return WhixyParser::RuleIfStmt; }

std::any WhixyParser::IfStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitIfStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::IfStmtContext* WhixyParser::ifStmt()
{
    IfStmtContext* _localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
    enterRule(_localctx, 18, WhixyParser::RuleIfStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(212);
        match(WhixyParser::IF);
        setState(213);
        atom();
        setState(214);
        stmt();
        setState(221);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(215);
                match(WhixyParser::ELSEIF);
                setState(216);
                atom();
                setState(217);
                stmt();
            }
            setState(223);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        }
        setState(226);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
            setState(224);
            match(WhixyParser::ELSE);
            setState(225);
            stmt();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- WhereStmtContext ------------------------------------------------------------------

WhixyParser::WhereStmtContext::WhereStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::WhereStmtContext::WHERE() { return getToken(WhixyParser::WHERE, 0); }

WhixyParser::AtomContext* WhixyParser::WhereStmtContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

WhixyParser::ComparisonOpContext* WhixyParser::WhereStmtContext::comparisonOp()
{
    return getRuleContext<WhixyParser::ComparisonOpContext>(0);
}

WhixyParser::CaseStmtBlockContext* WhixyParser::WhereStmtContext::caseStmtBlock()
{
    return getRuleContext<WhixyParser::CaseStmtBlockContext>(0);
}

size_t WhixyParser::WhereStmtContext::getRuleIndex() const { return WhixyParser::RuleWhereStmt; }

std::any WhixyParser::WhereStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWhereStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::WhereStmtContext* WhixyParser::whereStmt()
{
    WhereStmtContext* _localctx = _tracker.createInstance<WhereStmtContext>(_ctx, getState());
    enterRule(_localctx, 20, WhixyParser::RuleWhereStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(228);
        match(WhixyParser::WHERE);
        setState(229);
        atom();
        setState(230);
        comparisonOp();
        setState(231);
        caseStmtBlock();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ComparisonOpContext ------------------------------------------------------------------

WhixyParser::ComparisonOpContext::ComparisonOpContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::ComparisonOpContext::getRuleIndex() const { return WhixyParser::RuleComparisonOp; }

std::any WhixyParser::ComparisonOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitComparisonOp(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ComparisonOpContext* WhixyParser::comparisonOp()
{
    ComparisonOpContext* _localctx = _tracker.createInstance<ComparisonOpContext>(_ctx, getState());
    enterRule(_localctx, 22, WhixyParser::RuleComparisonOp);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CaseStmtBlockContext ------------------------------------------------------------------

WhixyParser::CaseStmtBlockContext::CaseStmtBlockContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::CaseStmtBlockContext::getRuleIndex() const { return WhixyParser::RuleCaseStmtBlock; }

std::any WhixyParser::CaseStmtBlockContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCaseStmtBlock(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CaseStmtBlockContext* WhixyParser::caseStmtBlock()
{
    CaseStmtBlockContext* _localctx = _tracker.createInstance<CaseStmtBlockContext>(_ctx, getState());
    enterRule(_localctx, 24, WhixyParser::RuleCaseStmtBlock);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LoopStmtContext ------------------------------------------------------------------

WhixyParser::LoopStmtContext::LoopStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::LoopStmtContext::getRuleIndex() const { return WhixyParser::RuleLoopStmt; }

void WhixyParser::LoopStmtContext::copyFrom(LoopStmtContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- PlainForStmtContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::PlainForStmtContext::FOR() { return getToken(WhixyParser::FOR, 0); }

WhixyParser::StmtContext* WhixyParser::PlainForStmtContext::stmt()
{
    return getRuleContext<WhixyParser::StmtContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainForStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainForStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::PlainForStmtContext::PlainForStmtContext(LoopStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainForStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainForStmt(this);
    else
        return visitor->visitChildren(this);
}
//----------------- UnrollWhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::UnrollWhileStmtContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

tree::TerminalNode* WhixyParser::UnrollWhileStmtContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

WhixyParser::StmtContext* WhixyParser::UnrollWhileStmtContext::stmt()
{
    return getRuleContext<WhixyParser::StmtContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::UnrollWhileStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::UnrollWhileStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::UnrollWhileStmtContext::UnrollWhileStmtContext(LoopStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::UnrollWhileStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitUnrollWhileStmt(this);
    else
        return visitor->visitChildren(this);
}
//----------------- PlainWhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::PlainWhileStmtContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

WhixyParser::StmtContext* WhixyParser::PlainWhileStmtContext::stmt()
{
    return getRuleContext<WhixyParser::StmtContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainWhileStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainWhileStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::PlainWhileStmtContext::PlainWhileStmtContext(LoopStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainWhileStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainWhileStmt(this);
    else
        return visitor->visitChildren(this);
}
//----------------- UnrollForStmtContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::UnrollForStmtContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

tree::TerminalNode* WhixyParser::UnrollForStmtContext::FOR() { return getToken(WhixyParser::FOR, 0); }

WhixyParser::StmtContext* WhixyParser::UnrollForStmtContext::stmt()
{
    return getRuleContext<WhixyParser::StmtContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::UnrollForStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::UnrollForStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::UnrollForStmtContext::UnrollForStmtContext(LoopStmtContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::UnrollForStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitUnrollForStmt(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::LoopStmtContext* WhixyParser::loopStmt()
{
    LoopStmtContext* _localctx = _tracker.createInstance<LoopStmtContext>(_ctx, getState());
    enterRule(_localctx, 26, WhixyParser::RuleLoopStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(271);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
            _localctx = _tracker.createInstance<WhixyParser::UnrollWhileStmtContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(237);
            match(WhixyParser::UNROLL);
            setState(238);
            match(WhixyParser::WHILE);
            setState(240);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
            case 1: {
                setState(239);
                atom();
                break;
            }

            default: break;
            }
            setState(243);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
            case 1: {
                setState(242);
                atom();
                break;
            }

            default: break;
            }
            setState(245);
            stmt();
            break;
        }

        case 2: {
            _localctx = _tracker.createInstance<WhixyParser::UnrollForStmtContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(246);
            match(WhixyParser::UNROLL);
            setState(247);
            match(WhixyParser::FOR);
            setState(249);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
            case 1: {
                setState(248);
                atom();
                break;
            }

            default: break;
            }
            setState(252);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
            case 1: {
                setState(251);
                atom();
                break;
            }

            default: break;
            }
            setState(254);
            stmt();
            break;
        }

        case 3: {
            _localctx = _tracker.createInstance<WhixyParser::PlainWhileStmtContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(255);
            match(WhixyParser::WHILE);
            setState(257);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
            case 1: {
                setState(256);
                atom();
                break;
            }

            default: break;
            }
            setState(260);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
            case 1: {
                setState(259);
                atom();
                break;
            }

            default: break;
            }
            setState(262);
            stmt();
            break;
        }

        case 4: {
            _localctx = _tracker.createInstance<WhixyParser::PlainForStmtContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(263);
            match(WhixyParser::FOR);
            setState(265);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
            case 1: {
                setState(264);
                atom();
                break;
            }

            default: break;
            }
            setState(268);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
            case 1: {
                setState(267);
                atom();
                break;
            }

            default: break;
            }
            setState(270);
            stmt();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ComptStmtContext ------------------------------------------------------------------

WhixyParser::ComptStmtContext::ComptStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ComptStmtContext::COMPT() { return getToken(WhixyParser::COMPT, 0); }

WhixyParser::StmtContext* WhixyParser::ComptStmtContext::stmt() { return getRuleContext<WhixyParser::StmtContext>(0); }

size_t WhixyParser::ComptStmtContext::getRuleIndex() const { return WhixyParser::RuleComptStmt; }

std::any WhixyParser::ComptStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitComptStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ComptStmtContext* WhixyParser::comptStmt()
{
    ComptStmtContext* _localctx = _tracker.createInstance<ComptStmtContext>(_ctx, getState());
    enterRule(_localctx, 28, WhixyParser::RuleComptStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(273);
        match(WhixyParser::COMPT);
        setState(274);
        stmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DeferStmtContext ------------------------------------------------------------------

WhixyParser::DeferStmtContext::DeferStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::DeferStmtContext::DEFER() { return getToken(WhixyParser::DEFER, 0); }

WhixyParser::StmtContext* WhixyParser::DeferStmtContext::stmt() { return getRuleContext<WhixyParser::StmtContext>(0); }

size_t WhixyParser::DeferStmtContext::getRuleIndex() const { return WhixyParser::RuleDeferStmt; }

std::any WhixyParser::DeferStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDeferStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::DeferStmtContext* WhixyParser::deferStmt()
{
    DeferStmtContext* _localctx = _tracker.createInstance<DeferStmtContext>(_ctx, getState());
    enterRule(_localctx, 30, WhixyParser::RuleDeferStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(276);
        match(WhixyParser::DEFER);
        setState(277);
        stmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ErrdeferStmtContext ------------------------------------------------------------------

WhixyParser::ErrdeferStmtContext::ErrdeferStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ErrdeferStmtContext::ERRDEFER() { return getToken(WhixyParser::ERRDEFER, 0); }

WhixyParser::StmtContext* WhixyParser::ErrdeferStmtContext::stmt()
{
    return getRuleContext<WhixyParser::StmtContext>(0);
}

size_t WhixyParser::ErrdeferStmtContext::getRuleIndex() const { return WhixyParser::RuleErrdeferStmt; }

std::any WhixyParser::ErrdeferStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitErrdeferStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ErrdeferStmtContext* WhixyParser::errdeferStmt()
{
    ErrdeferStmtContext* _localctx = _tracker.createInstance<ErrdeferStmtContext>(_ctx, getState());
    enterRule(_localctx, 32, WhixyParser::RuleErrdeferStmt);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(279);
        match(WhixyParser::ERRDEFER);
        setState(280);
        stmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

WhixyParser::ExprContext::ExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::ValsStmtContext* WhixyParser::ExprContext::valsStmt()
{
    return getRuleContext<WhixyParser::ValsStmtContext>(0);
}

WhixyParser::CallStmtContext* WhixyParser::ExprContext::callStmt()
{
    return getRuleContext<WhixyParser::CallStmtContext>(0);
}

WhixyParser::BinaryOpExprContext* WhixyParser::ExprContext::binaryOpExpr()
{
    return getRuleContext<WhixyParser::BinaryOpExprContext>(0);
}

WhixyParser::PostOpExprContext* WhixyParser::ExprContext::postOpExpr()
{
    return getRuleContext<WhixyParser::PostOpExprContext>(0);
}

WhixyParser::PreOpExprContext* WhixyParser::ExprContext::preOpExpr()
{
    return getRuleContext<WhixyParser::PreOpExprContext>(0);
}

WhixyParser::IfExprContext* WhixyParser::ExprContext::ifExpr() { return getRuleContext<WhixyParser::IfExprContext>(0); }

WhixyParser::WhereExprContext* WhixyParser::ExprContext::whereExpr()
{
    return getRuleContext<WhixyParser::WhereExprContext>(0);
}

WhixyParser::LoopExprContext* WhixyParser::ExprContext::loopExpr()
{
    return getRuleContext<WhixyParser::LoopExprContext>(0);
}

WhixyParser::ComptExprContext* WhixyParser::ExprContext::comptExpr()
{
    return getRuleContext<WhixyParser::ComptExprContext>(0);
}

WhixyParser::RoutineExprContext* WhixyParser::ExprContext::routineExpr()
{
    return getRuleContext<WhixyParser::RoutineExprContext>(0);
}

WhixyParser::StringContext* WhixyParser::ExprContext::string() { return getRuleContext<WhixyParser::StringContext>(0); }

WhixyParser::AtomContext* WhixyParser::ExprContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

size_t WhixyParser::ExprContext::getRuleIndex() const { return WhixyParser::RuleExpr; }

std::any WhixyParser::ExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ExprContext* WhixyParser::expr()
{
    ExprContext* _localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
    enterRule(_localctx, 34, WhixyParser::RuleExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(294);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(282);
            valsStmt();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(283);
            callStmt();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(284);
            binaryOpExpr();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(285);
            postOpExpr();
            break;
        }

        case 5: {
            enterOuterAlt(_localctx, 5);
            setState(286);
            preOpExpr();
            break;
        }

        case 6: {
            enterOuterAlt(_localctx, 6);
            setState(287);
            ifExpr();
            break;
        }

        case 7: {
            enterOuterAlt(_localctx, 7);
            setState(288);
            whereExpr();
            break;
        }

        case 8: {
            enterOuterAlt(_localctx, 8);
            setState(289);
            loopExpr();
            break;
        }

        case 9: {
            enterOuterAlt(_localctx, 9);
            setState(290);
            comptExpr();
            break;
        }

        case 10: {
            enterOuterAlt(_localctx, 10);
            setState(291);
            routineExpr();
            break;
        }

        case 11: {
            enterOuterAlt(_localctx, 11);
            setState(292);
            string();
            break;
        }

        case 12: {
            enterOuterAlt(_localctx, 12);
            setState(293);
            atom();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BinaryOpExprContext ------------------------------------------------------------------

WhixyParser::BinaryOpExprContext::BinaryOpExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<WhixyParser::AtomContext*> WhixyParser::BinaryOpExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::BinaryOpExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::BinaryOpContext* WhixyParser::BinaryOpExprContext::binaryOp()
{
    return getRuleContext<WhixyParser::BinaryOpContext>(0);
}

std::vector<tree::TerminalNode*> WhixyParser::BinaryOpExprContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::BinaryOpExprContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

size_t WhixyParser::BinaryOpExprContext::getRuleIndex() const { return WhixyParser::RuleBinaryOpExpr; }

std::any WhixyParser::BinaryOpExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitBinaryOpExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::BinaryOpExprContext* WhixyParser::binaryOpExpr()
{
    BinaryOpExprContext* _localctx = _tracker.createInstance<BinaryOpExprContext>(_ctx, getState());
    enterRule(_localctx, 36, WhixyParser::RuleBinaryOpExpr);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(296);
        atom();
        setState(298);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(297);
            match(WhixyParser::NEWLINE);
        }
        setState(300);
        binaryOp();
        setState(302);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
            setState(301);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }
        setState(304);
        atom();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BinaryOpContext ------------------------------------------------------------------

WhixyParser::BinaryOpContext::BinaryOpContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::BinaryOpContext::getRuleIndex() const { return WhixyParser::RuleBinaryOp; }

void WhixyParser::BinaryOpContext::copyFrom(BinaryOpContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- WrappingSubtractionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingSubtractionOpContext::MINUS_PERCENT()
{
    return getToken(WhixyParser::MINUS_PERCENT, 0);
}

WhixyParser::WrappingSubtractionOpContext::WrappingSubtractionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::WrappingSubtractionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingSubtractionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- GreaterThanOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::GreaterThanOpContext::GREATERTHAN() { return getToken(WhixyParser::GREATERTHAN, 0); }

WhixyParser::GreaterThanOpContext::GreaterThanOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::GreaterThanOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitGreaterThanOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- EqualityOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::EqualityOpContext::EQUAL_EQUAL() { return getToken(WhixyParser::EQUAL_EQUAL, 0); }

WhixyParser::EqualityOpContext::EqualityOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::EqualityOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitEqualityOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- ConcatenationOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::ConcatenationOpContext::PLUS_PLUS() { return getToken(WhixyParser::PLUS_PLUS, 0); }

WhixyParser::ConcatenationOpContext::ConcatenationOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::ConcatenationOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitConcatenationOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- RepetitionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RepetitionOpContext::ASTERISK_ASTERISK()
{
    return getToken(WhixyParser::ASTERISK_ASTERISK, 0);
}

WhixyParser::RepetitionOpContext::RepetitionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RepetitionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRepetitionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LeftShiftOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftShiftOpContext::LESSTHAN_LESSTHAN()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN, 0);
}

WhixyParser::LeftShiftOpContext::LeftShiftOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LeftShiftOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLeftShiftOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- MultiplicationOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::MultiplicationOpContext::ASTERISK() { return getToken(WhixyParser::ASTERISK, 0); }

WhixyParser::MultiplicationOpContext::MultiplicationOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::MultiplicationOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitMultiplicationOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- RightRotationOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightRotationOpContext::GREATERTHAN_GREATERTHAN_PERCENT()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT, 0);
}

WhixyParser::RightRotationOpContext::RightRotationOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightRotationOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightRotationOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingMultiplicationOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingMultiplicationOpContext::ASTERISK_PERCENT()
{
    return getToken(WhixyParser::ASTERISK_PERCENT, 0);
}

WhixyParser::WrappingMultiplicationOpContext::WrappingMultiplicationOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::WrappingMultiplicationOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingMultiplicationOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- OrOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::OrOpContext::PIPE() { return getToken(WhixyParser::PIPE, 0); }

WhixyParser::OrOpContext::OrOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::OrOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOrOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LessThanEqualOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LessThanEqualOpContext::LESSTHAN_EQUAL()
{
    return getToken(WhixyParser::LESSTHAN_EQUAL, 0);
}

WhixyParser::LessThanEqualOpContext::LessThanEqualOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LessThanEqualOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLessThanEqualOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AndOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AndOpContext::AMPERSAND() { return getToken(WhixyParser::AMPERSAND, 0); }

WhixyParser::AndOpContext::AndOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AndOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAndOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingAdditionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingAdditionOpContext::PLUS_PERCENT()
{
    return getToken(WhixyParser::PLUS_PERCENT, 0);
}

WhixyParser::WrappingAdditionOpContext::WrappingAdditionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::WrappingAdditionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingAdditionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- XorOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::XorOpContext::CARROT() { return getToken(WhixyParser::CARROT, 0); }

WhixyParser::XorOpContext::XorOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::XorOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitXorOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LessThanOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LessThanOpContext::LESSTHAN() { return getToken(WhixyParser::LESSTHAN, 0); }

WhixyParser::LessThanOpContext::LessThanOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LessThanOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLessThanOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LeftRotationOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftRotationOpContext::LESSTHAN_LESSTHAN_PERCENT()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN_PERCENT, 0);
}

WhixyParser::LeftRotationOpContext::LeftRotationOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LeftRotationOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLeftRotationOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- SubtractionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::SubtractionOpContext::MINUS() { return getToken(WhixyParser::MINUS, 0); }

WhixyParser::SubtractionOpContext::SubtractionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::SubtractionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitSubtractionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- RightShiftOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightShiftOpContext::GREATERTHAN_GREATERTHAN()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN, 0);
}

WhixyParser::RightShiftOpContext::RightShiftOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightShiftOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightShiftOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- GreaterThanEqualOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::GreaterThanEqualOpContext::GREATERTHAN_EQUAL()
{
    return getToken(WhixyParser::GREATERTHAN_EQUAL, 0);
}

WhixyParser::GreaterThanEqualOpContext::GreaterThanEqualOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::GreaterThanEqualOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitGreaterThanEqualOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- ModulusOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::ModulusOpContext::PERCENT() { return getToken(WhixyParser::PERCENT, 0); }

WhixyParser::ModulusOpContext::ModulusOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::ModulusOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitModulusOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AdditionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AdditionOpContext::PLUS() { return getToken(WhixyParser::PLUS, 0); }

WhixyParser::AdditionOpContext::AdditionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AdditionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAdditionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- DivisionOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::DivisionOpContext::SLASH() { return getToken(WhixyParser::SLASH, 0); }

WhixyParser::DivisionOpContext::DivisionOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::DivisionOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDivisionOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AsOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AsOpContext::AS() { return getToken(WhixyParser::AS, 0); }

WhixyParser::AsOpContext::AsOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AsOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAsOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- InequalityOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::InequalityOpContext::EXCLAMATION_EQUAL()
{
    return getToken(WhixyParser::EXCLAMATION_EQUAL, 0);
}

WhixyParser::InequalityOpContext::InequalityOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::InequalityOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitInequalityOp(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::BinaryOpContext* WhixyParser::binaryOp()
{
    BinaryOpContext* _localctx = _tracker.createInstance<BinaryOpContext>(_ctx, getState());
    enterRule(_localctx, 38, WhixyParser::RuleBinaryOp);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(330);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::AS: {
            _localctx = _tracker.createInstance<WhixyParser::AsOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(306);
            match(WhixyParser::AS);
            break;
        }

        case WhixyParser::PLUS_PLUS: {
            _localctx = _tracker.createInstance<WhixyParser::ConcatenationOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(307);
            match(WhixyParser::PLUS_PLUS);
            break;
        }

        case WhixyParser::ASTERISK_ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::RepetitionOpContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(308);
            match(WhixyParser::ASTERISK_ASTERISK);
            break;
        }

        case WhixyParser::PLUS: {
            _localctx = _tracker.createInstance<WhixyParser::AdditionOpContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(309);
            match(WhixyParser::PLUS);
            break;
        }

        case WhixyParser::MINUS: {
            _localctx = _tracker.createInstance<WhixyParser::SubtractionOpContext>(_localctx);
            enterOuterAlt(_localctx, 5);
            setState(310);
            match(WhixyParser::MINUS);
            break;
        }

        case WhixyParser::ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::MultiplicationOpContext>(_localctx);
            enterOuterAlt(_localctx, 6);
            setState(311);
            match(WhixyParser::ASTERISK);
            break;
        }

        case WhixyParser::SLASH: {
            _localctx = _tracker.createInstance<WhixyParser::DivisionOpContext>(_localctx);
            enterOuterAlt(_localctx, 7);
            setState(312);
            match(WhixyParser::SLASH);
            break;
        }

        case WhixyParser::LESSTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::LessThanOpContext>(_localctx);
            enterOuterAlt(_localctx, 8);
            setState(313);
            match(WhixyParser::LESSTHAN);
            break;
        }

        case WhixyParser::GREATERTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::GreaterThanOpContext>(_localctx);
            enterOuterAlt(_localctx, 9);
            setState(314);
            match(WhixyParser::GREATERTHAN);
            break;
        }

        case WhixyParser::LESSTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LessThanEqualOpContext>(_localctx);
            enterOuterAlt(_localctx, 10);
            setState(315);
            match(WhixyParser::LESSTHAN_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::GreaterThanEqualOpContext>(_localctx);
            enterOuterAlt(_localctx, 11);
            setState(316);
            match(WhixyParser::GREATERTHAN_EQUAL);
            break;
        }

        case WhixyParser::PLUS_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingAdditionOpContext>(_localctx);
            enterOuterAlt(_localctx, 12);
            setState(317);
            match(WhixyParser::PLUS_PERCENT);
            break;
        }

        case WhixyParser::MINUS_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingSubtractionOpContext>(_localctx);
            enterOuterAlt(_localctx, 13);
            setState(318);
            match(WhixyParser::MINUS_PERCENT);
            break;
        }

        case WhixyParser::ASTERISK_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingMultiplicationOpContext>(_localctx);
            enterOuterAlt(_localctx, 14);
            setState(319);
            match(WhixyParser::ASTERISK_PERCENT);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::LeftShiftOpContext>(_localctx);
            enterOuterAlt(_localctx, 15);
            setState(320);
            match(WhixyParser::LESSTHAN_LESSTHAN);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::RightShiftOpContext>(_localctx);
            enterOuterAlt(_localctx, 16);
            setState(321);
            match(WhixyParser::GREATERTHAN_GREATERTHAN);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::LeftRotationOpContext>(_localctx);
            enterOuterAlt(_localctx, 17);
            setState(322);
            match(WhixyParser::LESSTHAN_LESSTHAN_PERCENT);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::RightRotationOpContext>(_localctx);
            enterOuterAlt(_localctx, 18);
            setState(323);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT);
            break;
        }

        case WhixyParser::EQUAL_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::EqualityOpContext>(_localctx);
            enterOuterAlt(_localctx, 19);
            setState(324);
            match(WhixyParser::EQUAL_EQUAL);
            break;
        }

        case WhixyParser::EXCLAMATION_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::InequalityOpContext>(_localctx);
            enterOuterAlt(_localctx, 20);
            setState(325);
            match(WhixyParser::EXCLAMATION_EQUAL);
            break;
        }

        case WhixyParser::AMPERSAND: {
            _localctx = _tracker.createInstance<WhixyParser::AndOpContext>(_localctx);
            enterOuterAlt(_localctx, 21);
            setState(326);
            match(WhixyParser::AMPERSAND);
            break;
        }

        case WhixyParser::PIPE: {
            _localctx = _tracker.createInstance<WhixyParser::OrOpContext>(_localctx);
            enterOuterAlt(_localctx, 22);
            setState(327);
            match(WhixyParser::PIPE);
            break;
        }

        case WhixyParser::PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::ModulusOpContext>(_localctx);
            enterOuterAlt(_localctx, 23);
            setState(328);
            match(WhixyParser::PERCENT);
            break;
        }

        case WhixyParser::CARROT: {
            _localctx = _tracker.createInstance<WhixyParser::XorOpContext>(_localctx);
            enterOuterAlt(_localctx, 24);
            setState(329);
            match(WhixyParser::CARROT);
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PostOpExprContext ------------------------------------------------------------------

WhixyParser::PostOpExprContext::PostOpExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::AtomContext* WhixyParser::PostOpExprContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

WhixyParser::PostOpContext* WhixyParser::PostOpExprContext::postOp()
{
    return getRuleContext<WhixyParser::PostOpContext>(0);
}

size_t WhixyParser::PostOpExprContext::getRuleIndex() const { return WhixyParser::RulePostOpExpr; }

std::any WhixyParser::PostOpExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPostOpExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::PostOpExprContext* WhixyParser::postOpExpr()
{
    PostOpExprContext* _localctx = _tracker.createInstance<PostOpExprContext>(_ctx, getState());
    enterRule(_localctx, 40, WhixyParser::RulePostOpExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(332);
        atom();
        setState(333);
        postOp();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PostOpContext ------------------------------------------------------------------

WhixyParser::PostOpContext::PostOpContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::PostOpContext::getRuleIndex() const { return WhixyParser::RulePostOp; }

void WhixyParser::PostOpContext::copyFrom(PostOpContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- AccessTypeOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AccessTypeOpContext::DOT_TYPE() { return getToken(WhixyParser::DOT_TYPE, 0); }

WhixyParser::AccessTypeOpContext::AccessTypeOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AccessTypeOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAccessTypeOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AccessLengthOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AccessLengthOpContext::DOT_LEN() { return getToken(WhixyParser::DOT_LEN, 0); }

WhixyParser::AccessLengthOpContext::AccessLengthOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AccessLengthOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAccessLengthOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AddressOfOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AddressOfOpContext::DOT_AMPERSAND() { return getToken(WhixyParser::DOT_AMPERSAND, 0); }

WhixyParser::AddressOfOpContext::AddressOfOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AddressOfOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAddressOfOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AccessFieldOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AccessFieldOpContext::DOT() { return getToken(WhixyParser::DOT, 0); }

WhixyParser::AtomContext* WhixyParser::AccessFieldOpContext::atom()
{
    return getRuleContext<WhixyParser::AtomContext>(0);
}

WhixyParser::AccessFieldOpContext::AccessFieldOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AccessFieldOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAccessFieldOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- UnwrapOptionalOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::UnwrapOptionalOpContext::DOT_QUESTION()
{
    return getToken(WhixyParser::DOT_QUESTION, 0);
}

WhixyParser::UnwrapOptionalOpContext::UnwrapOptionalOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::UnwrapOptionalOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitUnwrapOptionalOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- DereferencePointerOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::DereferencePointerOpContext::DOT_ASTERISK()
{
    return getToken(WhixyParser::DOT_ASTERISK, 0);
}

WhixyParser::DereferencePointerOpContext::DereferencePointerOpContext(PostOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::DereferencePointerOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDereferencePointerOp(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::PostOpContext* WhixyParser::postOp()
{
    PostOpContext* _localctx = _tracker.createInstance<PostOpContext>(_ctx, getState());
    enterRule(_localctx, 42, WhixyParser::RulePostOp);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(342);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::DOT: {
            _localctx = _tracker.createInstance<WhixyParser::AccessFieldOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(335);
            match(WhixyParser::DOT);
            setState(336);
            atom();
            break;
        }

        case WhixyParser::DOT_TYPE: {
            _localctx = _tracker.createInstance<WhixyParser::AccessTypeOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(337);
            match(WhixyParser::DOT_TYPE);
            break;
        }

        case WhixyParser::DOT_LEN: {
            _localctx = _tracker.createInstance<WhixyParser::AccessLengthOpContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(338);
            match(WhixyParser::DOT_LEN);
            break;
        }

        case WhixyParser::DOT_ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::DereferencePointerOpContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(339);
            match(WhixyParser::DOT_ASTERISK);
            break;
        }

        case WhixyParser::DOT_AMPERSAND: {
            _localctx = _tracker.createInstance<WhixyParser::AddressOfOpContext>(_localctx);
            enterOuterAlt(_localctx, 5);
            setState(340);
            match(WhixyParser::DOT_AMPERSAND);
            break;
        }

        case WhixyParser::DOT_QUESTION: {
            _localctx = _tracker.createInstance<WhixyParser::UnwrapOptionalOpContext>(_localctx);
            enterOuterAlt(_localctx, 6);
            setState(341);
            match(WhixyParser::DOT_QUESTION);
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PreOpExprContext ------------------------------------------------------------------

WhixyParser::PreOpExprContext::PreOpExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::PreOpContext* WhixyParser::PreOpExprContext::preOp()
{
    return getRuleContext<WhixyParser::PreOpContext>(0);
}

WhixyParser::AtomContext* WhixyParser::PreOpExprContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

size_t WhixyParser::PreOpExprContext::getRuleIndex() const { return WhixyParser::RulePreOpExpr; }

std::any WhixyParser::PreOpExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPreOpExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::PreOpExprContext* WhixyParser::preOpExpr()
{
    PreOpExprContext* _localctx = _tracker.createInstance<PreOpExprContext>(_ctx, getState());
    enterRule(_localctx, 44, WhixyParser::RulePreOpExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(344);
        preOp();
        setState(345);
        atom();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- PreOpContext ------------------------------------------------------------------

WhixyParser::PreOpContext::PreOpContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::PreOpContext::getRuleIndex() const { return WhixyParser::RulePreOp; }

void WhixyParser::PreOpContext::copyFrom(PreOpContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- NegateOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::NegateOpContext::MINUS() { return getToken(WhixyParser::MINUS, 0); }

WhixyParser::NegateOpContext::NegateOpContext(PreOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::NegateOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitNegateOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- NotOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::NotOpContext::EXCLAMATION() { return getToken(WhixyParser::EXCLAMATION, 0); }

WhixyParser::NotOpContext::NotOpContext(PreOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::NotOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitNotOp(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::PreOpContext* WhixyParser::preOp()
{
    PreOpContext* _localctx = _tracker.createInstance<PreOpContext>(_ctx, getState());
    enterRule(_localctx, 46, WhixyParser::RulePreOp);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(349);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::EXCLAMATION: {
            _localctx = _tracker.createInstance<WhixyParser::NotOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(347);
            match(WhixyParser::EXCLAMATION);
            break;
        }

        case WhixyParser::MINUS: {
            _localctx = _tracker.createInstance<WhixyParser::NegateOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(348);
            match(WhixyParser::MINUS);
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IfExprContext ------------------------------------------------------------------

WhixyParser::IfExprContext::IfExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::IfExprContext::IF() { return getToken(WhixyParser::IF, 0); }

std::vector<WhixyParser::AtomContext*> WhixyParser::IfExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::IfExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

std::vector<WhixyParser::ExprContext*> WhixyParser::IfExprContext::expr()
{
    return getRuleContexts<WhixyParser::ExprContext>();
}

WhixyParser::ExprContext* WhixyParser::IfExprContext::expr(size_t i)
{
    return getRuleContext<WhixyParser::ExprContext>(i);
}

std::vector<tree::TerminalNode*> WhixyParser::IfExprContext::ELSEIF() { return getTokens(WhixyParser::ELSEIF); }

tree::TerminalNode* WhixyParser::IfExprContext::ELSEIF(size_t i) { return getToken(WhixyParser::ELSEIF, i); }

tree::TerminalNode* WhixyParser::IfExprContext::ELSE() { return getToken(WhixyParser::ELSE, 0); }

size_t WhixyParser::IfExprContext::getRuleIndex() const { return WhixyParser::RuleIfExpr; }

std::any WhixyParser::IfExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitIfExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::IfExprContext* WhixyParser::ifExpr()
{
    IfExprContext* _localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
    enterRule(_localctx, 48, WhixyParser::RuleIfExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(351);
        match(WhixyParser::IF);
        setState(352);
        atom();
        setState(353);
        expr();
        setState(360);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(354);
                match(WhixyParser::ELSEIF);
                setState(355);
                atom();
                setState(356);
                expr();
            }
            setState(362);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        }
        setState(365);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
            setState(363);
            match(WhixyParser::ELSE);
            setState(364);
            expr();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- WhereExprContext ------------------------------------------------------------------

WhixyParser::WhereExprContext::WhereExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::WhereExprContext::WHERE() { return getToken(WhixyParser::WHERE, 0); }

WhixyParser::AtomContext* WhixyParser::WhereExprContext::atom() { return getRuleContext<WhixyParser::AtomContext>(0); }

WhixyParser::ComparisonOpContext* WhixyParser::WhereExprContext::comparisonOp()
{
    return getRuleContext<WhixyParser::ComparisonOpContext>(0);
}

WhixyParser::CaseExprBlockContext* WhixyParser::WhereExprContext::caseExprBlock()
{
    return getRuleContext<WhixyParser::CaseExprBlockContext>(0);
}

size_t WhixyParser::WhereExprContext::getRuleIndex() const { return WhixyParser::RuleWhereExpr; }

std::any WhixyParser::WhereExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWhereExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::WhereExprContext* WhixyParser::whereExpr()
{
    WhereExprContext* _localctx = _tracker.createInstance<WhereExprContext>(_ctx, getState());
    enterRule(_localctx, 50, WhixyParser::RuleWhereExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(367);
        match(WhixyParser::WHERE);
        setState(368);
        atom();
        setState(369);
        comparisonOp();
        setState(370);
        caseExprBlock();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CaseExprBlockContext ------------------------------------------------------------------

WhixyParser::CaseExprBlockContext::CaseExprBlockContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::CaseExprBlockContext::getRuleIndex() const { return WhixyParser::RuleCaseExprBlock; }

std::any WhixyParser::CaseExprBlockContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCaseExprBlock(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CaseExprBlockContext* WhixyParser::caseExprBlock()
{
    CaseExprBlockContext* _localctx = _tracker.createInstance<CaseExprBlockContext>(_ctx, getState());
    enterRule(_localctx, 52, WhixyParser::RuleCaseExprBlock);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- LoopExprContext ------------------------------------------------------------------

WhixyParser::LoopExprContext::LoopExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::LoopExprContext::getRuleIndex() const { return WhixyParser::RuleLoopExpr; }

void WhixyParser::LoopExprContext::copyFrom(LoopExprContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- UnrollWhileExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::UnrollWhileExprContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

tree::TerminalNode* WhixyParser::UnrollWhileExprContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

WhixyParser::ExprContext* WhixyParser::UnrollWhileExprContext::expr()
{
    return getRuleContext<WhixyParser::ExprContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::UnrollWhileExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::UnrollWhileExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::UnrollWhileExprContext::UnrollWhileExprContext(LoopExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::UnrollWhileExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitUnrollWhileExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- UnrollForExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::UnrollForExprContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

tree::TerminalNode* WhixyParser::UnrollForExprContext::FOR() { return getToken(WhixyParser::FOR, 0); }

WhixyParser::ExprContext* WhixyParser::UnrollForExprContext::expr()
{
    return getRuleContext<WhixyParser::ExprContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::UnrollForExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::UnrollForExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::UnrollForExprContext::UnrollForExprContext(LoopExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::UnrollForExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitUnrollForExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- PlainForExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::PlainForExprContext::FOR() { return getToken(WhixyParser::FOR, 0); }

WhixyParser::ExprContext* WhixyParser::PlainForExprContext::expr()
{
    return getRuleContext<WhixyParser::ExprContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainForExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainForExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::PlainForExprContext::PlainForExprContext(LoopExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainForExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainForExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- PlainWhileExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::PlainWhileExprContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

WhixyParser::ExprContext* WhixyParser::PlainWhileExprContext::expr()
{
    return getRuleContext<WhixyParser::ExprContext>(0);
}

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainWhileExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainWhileExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::PlainWhileExprContext::PlainWhileExprContext(LoopExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainWhileExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainWhileExpr(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::LoopExprContext* WhixyParser::loopExpr()
{
    LoopExprContext* _localctx = _tracker.createInstance<LoopExprContext>(_ctx, getState());
    enterRule(_localctx, 54, WhixyParser::RuleLoopExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(408);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
            _localctx = _tracker.createInstance<WhixyParser::UnrollWhileExprContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(374);
            match(WhixyParser::UNROLL);
            setState(375);
            match(WhixyParser::WHILE);
            setState(377);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
            case 1: {
                setState(376);
                atom();
                break;
            }

            default: break;
            }
            setState(380);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
            case 1: {
                setState(379);
                atom();
                break;
            }

            default: break;
            }
            setState(382);
            expr();
            break;
        }

        case 2: {
            _localctx = _tracker.createInstance<WhixyParser::UnrollForExprContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(383);
            match(WhixyParser::UNROLL);
            setState(384);
            match(WhixyParser::FOR);
            setState(386);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
            case 1: {
                setState(385);
                atom();
                break;
            }

            default: break;
            }
            setState(389);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
            case 1: {
                setState(388);
                atom();
                break;
            }

            default: break;
            }
            setState(391);
            expr();
            break;
        }

        case 3: {
            _localctx = _tracker.createInstance<WhixyParser::PlainWhileExprContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(392);
            match(WhixyParser::WHILE);
            setState(394);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
            case 1: {
                setState(393);
                atom();
                break;
            }

            default: break;
            }
            setState(397);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
            case 1: {
                setState(396);
                atom();
                break;
            }

            default: break;
            }
            setState(399);
            expr();
            break;
        }

        case 4: {
            _localctx = _tracker.createInstance<WhixyParser::PlainForExprContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(400);
            match(WhixyParser::FOR);
            setState(402);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
            case 1: {
                setState(401);
                atom();
                break;
            }

            default: break;
            }
            setState(405);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
            case 1: {
                setState(404);
                atom();
                break;
            }

            default: break;
            }
            setState(407);
            expr();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ComptExprContext ------------------------------------------------------------------

WhixyParser::ComptExprContext::ComptExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ComptExprContext::COMPT() { return getToken(WhixyParser::COMPT, 0); }

WhixyParser::ExprContext* WhixyParser::ComptExprContext::expr() { return getRuleContext<WhixyParser::ExprContext>(0); }

size_t WhixyParser::ComptExprContext::getRuleIndex() const { return WhixyParser::RuleComptExpr; }

std::any WhixyParser::ComptExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitComptExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ComptExprContext* WhixyParser::comptExpr()
{
    ComptExprContext* _localctx = _tracker.createInstance<ComptExprContext>(_ctx, getState());
    enterRule(_localctx, 56, WhixyParser::RuleComptExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(410);
        match(WhixyParser::COMPT);
        setState(411);
        expr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- RoutineExprContext ------------------------------------------------------------------

WhixyParser::RoutineExprContext::RoutineExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::RoutineExprContext::getRuleIndex() const { return WhixyParser::RuleRoutineExpr; }

void WhixyParser::RoutineExprContext::copyFrom(RoutineExprContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- InlineRoutineExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::InlineRoutineExprContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

std::vector<WhixyParser::AtomContext*> WhixyParser::InlineRoutineExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::InlineRoutineExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::BlockStmtContext* WhixyParser::InlineRoutineExprContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::InlineRoutineExprContext::InlineRoutineExprContext(RoutineExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::InlineRoutineExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitInlineRoutineExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- PlainRoutineExprContext ------------------------------------------------------------------

std::vector<WhixyParser::AtomContext*> WhixyParser::PlainRoutineExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::PlainRoutineExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

WhixyParser::BlockStmtContext* WhixyParser::PlainRoutineExprContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::PlainRoutineExprContext::PlainRoutineExprContext(RoutineExprContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::PlainRoutineExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitPlainRoutineExpr(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::RoutineExprContext* WhixyParser::routineExpr()
{
    RoutineExprContext* _localctx = _tracker.createInstance<RoutineExprContext>(_ctx, getState());
    enterRule(_localctx, 58, WhixyParser::RuleRoutineExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(422);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::OPENPARENTHESIS:
        case WhixyParser::OPENBRACE:
        case WhixyParser::NEWLINE:
        case WhixyParser::TOKEN: {
            _localctx = _tracker.createInstance<WhixyParser::PlainRoutineExprContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(413);
            atom();
            setState(414);
            atom();
            setState(415);
            blockStmt();
            break;
        }

        case WhixyParser::INLINE: {
            _localctx = _tracker.createInstance<WhixyParser::InlineRoutineExprContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(417);
            match(WhixyParser::INLINE);
            setState(418);
            atom();
            setState(419);
            atom();
            setState(420);
            blockStmt();
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StringContext ------------------------------------------------------------------

WhixyParser::StringContext::StringContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

size_t WhixyParser::StringContext::getRuleIndex() const { return WhixyParser::RuleString; }

void WhixyParser::StringContext::copyFrom(StringContext* ctx) { ParserRuleContext::copyFrom(ctx); }

//----------------- DQStringExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::DQStringExprContext::DOUBLEQUOTESTRING()
{
    return getToken(WhixyParser::DOUBLEQUOTESTRING, 0);
}

WhixyParser::DQStringExprContext::DQStringExprContext(StringContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::DQStringExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDQStringExpr(this);
    else
        return visitor->visitChildren(this);
}
//----------------- BTStringExprContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::BTStringExprContext::BACKTICKSTRING()
{
    return getToken(WhixyParser::BACKTICKSTRING, 0);
}

WhixyParser::BTStringExprContext::BTStringExprContext(StringContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::BTStringExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitBTStringExpr(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::StringContext* WhixyParser::string()
{
    StringContext* _localctx = _tracker.createInstance<StringContext>(_ctx, getState());
    enterRule(_localctx, 60, WhixyParser::RuleString);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(426);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::DOUBLEQUOTESTRING: {
            _localctx = _tracker.createInstance<WhixyParser::DQStringExprContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(424);
            match(WhixyParser::DOUBLEQUOTESTRING);
            break;
        }

        case WhixyParser::BACKTICKSTRING: {
            _localctx = _tracker.createInstance<WhixyParser::BTStringExprContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(425);
            match(WhixyParser::BACKTICKSTRING);
            break;
        }

        default: throw NoViableAltException(this);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

WhixyParser::AtomContext::AtomContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::TokenContext* WhixyParser::AtomContext::token() { return getRuleContext<WhixyParser::TokenContext>(0); }

WhixyParser::BlockExprContext* WhixyParser::AtomContext::blockExpr()
{
    return getRuleContext<WhixyParser::BlockExprContext>(0);
}

WhixyParser::TypeExprContext* WhixyParser::AtomContext::typeExpr()
{
    return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::AtomContext::tupleExpr()
{
    return getRuleContext<WhixyParser::TupleExprContext>(0);
}

size_t WhixyParser::AtomContext::getRuleIndex() const { return WhixyParser::RuleAtom; }

std::any WhixyParser::AtomContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAtom(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::AtomContext* WhixyParser::atom()
{
    AtomContext* _localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
    enterRule(_localctx, 62, WhixyParser::RuleAtom);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        setState(432);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(428);
            token();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(429);
            blockExpr();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(430);
            typeExpr();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(431);
            tupleExpr();
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- TokenContext ------------------------------------------------------------------

WhixyParser::TokenContext::TokenContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::TokenContext::TOKEN() { return getToken(WhixyParser::TOKEN, 0); }

size_t WhixyParser::TokenContext::getRuleIndex() const { return WhixyParser::RuleToken; }

std::any WhixyParser::TokenContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitToken(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::TokenContext* WhixyParser::token()
{
    TokenContext* _localctx = _tracker.createInstance<TokenContext>(_ctx, getState());
    enterRule(_localctx, 64, WhixyParser::RuleToken);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(434);
        match(WhixyParser::TOKEN);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- BlockExprContext ------------------------------------------------------------------

WhixyParser::BlockExprContext::BlockExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::OParenContext* WhixyParser::BlockExprContext::oParen()
{
    return getRuleContext<WhixyParser::OParenContext>(0);
}

WhixyParser::CParenContext* WhixyParser::BlockExprContext::cParen()
{
    return getRuleContext<WhixyParser::CParenContext>(0);
}

WhixyParser::ExprContext* WhixyParser::BlockExprContext::expr() { return getRuleContext<WhixyParser::ExprContext>(0); }

std::vector<WhixyParser::StmtContext*> WhixyParser::BlockExprContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::BlockExprContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

std::vector<WhixyParser::StmtSepContext*> WhixyParser::BlockExprContext::stmtSep()
{
    return getRuleContexts<WhixyParser::StmtSepContext>();
}

WhixyParser::StmtSepContext* WhixyParser::BlockExprContext::stmtSep(size_t i)
{
    return getRuleContext<WhixyParser::StmtSepContext>(i);
}

size_t WhixyParser::BlockExprContext::getRuleIndex() const { return WhixyParser::RuleBlockExpr; }

std::any WhixyParser::BlockExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitBlockExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::BlockExprContext* WhixyParser::blockExpr()
{
    BlockExprContext* _localctx = _tracker.createInstance<BlockExprContext>(_ctx, getState());
    enterRule(_localctx, 66, WhixyParser::RuleBlockExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(436);
        oParen();
        setState(451);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
        case 1: {
            setState(448);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
            case 1: {
                setState(437);
                stmt();
                setState(443);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                    if (alt == 1) {
                        setState(438);
                        stmtSep();
                        setState(439);
                        stmt();
                    }
                    setState(445);
                    _errHandler->sync(this);
                    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
                }
                setState(446);
                stmtSep();
                break;
            }

            default: break;
            }
            setState(450);
            expr();
            break;
        }

        default: break;
        }
        setState(453);
        cParen();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- TypeExprContext ------------------------------------------------------------------

WhixyParser::TypeExprContext::TypeExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::OBraceContext* WhixyParser::TypeExprContext::oBrace()
{
    return getRuleContext<WhixyParser::OBraceContext>(0);
}

WhixyParser::CBraceContext* WhixyParser::TypeExprContext::cBrace()
{
    return getRuleContext<WhixyParser::CBraceContext>(0);
}

std::vector<WhixyParser::ValsStmtContext*> WhixyParser::TypeExprContext::valsStmt()
{
    return getRuleContexts<WhixyParser::ValsStmtContext>();
}

WhixyParser::ValsStmtContext* WhixyParser::TypeExprContext::valsStmt(size_t i)
{
    return getRuleContext<WhixyParser::ValsStmtContext>(i);
}

std::vector<WhixyParser::ExprSepContext*> WhixyParser::TypeExprContext::exprSep()
{
    return getRuleContexts<WhixyParser::ExprSepContext>();
}

WhixyParser::ExprSepContext* WhixyParser::TypeExprContext::exprSep(size_t i)
{
    return getRuleContext<WhixyParser::ExprSepContext>(i);
}

size_t WhixyParser::TypeExprContext::getRuleIndex() const { return WhixyParser::RuleTypeExpr; }

std::any WhixyParser::TypeExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitTypeExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::TypeExprContext* WhixyParser::typeExpr()
{
    TypeExprContext* _localctx = _tracker.createInstance<TypeExprContext>(_ctx, getState());
    enterRule(_localctx, 68, WhixyParser::RuleTypeExpr);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(455);
        oBrace();
        setState(465);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::TOKEN) {
            setState(456);
            valsStmt();
            setState(462);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                    setState(457);
                    exprSep();
                    setState(458);
                    valsStmt();
                }
                setState(464);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
            }
        }
        setState(467);
        cBrace();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- TupleExprContext ------------------------------------------------------------------

WhixyParser::TupleExprContext::TupleExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

WhixyParser::OParenContext* WhixyParser::TupleExprContext::oParen()
{
    return getRuleContext<WhixyParser::OParenContext>(0);
}

WhixyParser::CParenContext* WhixyParser::TupleExprContext::cParen()
{
    return getRuleContext<WhixyParser::CParenContext>(0);
}

std::vector<WhixyParser::ExprContext*> WhixyParser::TupleExprContext::expr()
{
    return getRuleContexts<WhixyParser::ExprContext>();
}

WhixyParser::ExprContext* WhixyParser::TupleExprContext::expr(size_t i)
{
    return getRuleContext<WhixyParser::ExprContext>(i);
}

std::vector<WhixyParser::ExprSepContext*> WhixyParser::TupleExprContext::exprSep()
{
    return getRuleContexts<WhixyParser::ExprSepContext>();
}

WhixyParser::ExprSepContext* WhixyParser::TupleExprContext::exprSep(size_t i)
{
    return getRuleContext<WhixyParser::ExprSepContext>(i);
}

size_t WhixyParser::TupleExprContext::getRuleIndex() const { return WhixyParser::RuleTupleExpr; }

std::any WhixyParser::TupleExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitTupleExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::TupleExprContext* WhixyParser::tupleExpr()
{
    TupleExprContext* _localctx = _tracker.createInstance<TupleExprContext>(_ctx, getState());
    enterRule(_localctx, 70, WhixyParser::RuleTupleExpr);

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        size_t alt;
        enterOuterAlt(_localctx, 1);
        setState(469);
        oParen();
        setState(479);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
        case 1: {
            setState(470);
            expr();
            setState(476);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                    setState(471);
                    exprSep();
                    setState(472);
                    expr();
                }
                setState(478);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
            }
            break;
        }

        default: break;
        }
        setState(481);
        cParen();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- OBracketContext ------------------------------------------------------------------

WhixyParser::OBracketContext::OBracketContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::OBracketContext::OPENBRACKET() { return getToken(WhixyParser::OPENBRACKET, 0); }

tree::TerminalNode* WhixyParser::OBracketContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::OBracketContext::getRuleIndex() const { return WhixyParser::RuleOBracket; }

std::any WhixyParser::OBracketContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOBracket(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::OBracketContext* WhixyParser::oBracket()
{
    OBracketContext* _localctx = _tracker.createInstance<OBracketContext>(_ctx, getState());
    enterRule(_localctx, 72, WhixyParser::RuleOBracket);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(483);
        match(WhixyParser::OPENBRACKET);
        setState(485);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(484);
            match(WhixyParser::NEWLINE);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CBracketContext ------------------------------------------------------------------

WhixyParser::CBracketContext::CBracketContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::CBracketContext::CLOSEDBRACKET() { return getToken(WhixyParser::CLOSEDBRACKET, 0); }

tree::TerminalNode* WhixyParser::CBracketContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::CBracketContext::getRuleIndex() const { return WhixyParser::RuleCBracket; }

std::any WhixyParser::CBracketContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCBracket(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CBracketContext* WhixyParser::cBracket()
{
    CBracketContext* _localctx = _tracker.createInstance<CBracketContext>(_ctx, getState());
    enterRule(_localctx, 74, WhixyParser::RuleCBracket);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(488);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(487);
            match(WhixyParser::NEWLINE);
        }
        setState(490);
        match(WhixyParser::CLOSEDBRACKET);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- OAngleBracketContext ------------------------------------------------------------------

WhixyParser::OAngleBracketContext::OAngleBracketContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::OAngleBracketContext::LESSTHAN_OPENBRACKET()
{
    return getToken(WhixyParser::LESSTHAN_OPENBRACKET, 0);
}

tree::TerminalNode* WhixyParser::OAngleBracketContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::OAngleBracketContext::getRuleIndex() const { return WhixyParser::RuleOAngleBracket; }

std::any WhixyParser::OAngleBracketContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOAngleBracket(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::OAngleBracketContext* WhixyParser::oAngleBracket()
{
    OAngleBracketContext* _localctx = _tracker.createInstance<OAngleBracketContext>(_ctx, getState());
    enterRule(_localctx, 76, WhixyParser::RuleOAngleBracket);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(492);
        match(WhixyParser::LESSTHAN_OPENBRACKET);
        setState(494);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(493);
            match(WhixyParser::NEWLINE);
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CAngleBracketContext ------------------------------------------------------------------

WhixyParser::CAngleBracketContext::CAngleBracketContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::CAngleBracketContext::CLOSEDBRACKET_GREATERTHAN()
{
    return getToken(WhixyParser::CLOSEDBRACKET_GREATERTHAN, 0);
}

tree::TerminalNode* WhixyParser::CAngleBracketContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::CAngleBracketContext::getRuleIndex() const { return WhixyParser::RuleCAngleBracket; }

std::any WhixyParser::CAngleBracketContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCAngleBracket(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CAngleBracketContext* WhixyParser::cAngleBracket()
{
    CAngleBracketContext* _localctx = _tracker.createInstance<CAngleBracketContext>(_ctx, getState());
    enterRule(_localctx, 78, WhixyParser::RuleCAngleBracket);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(497);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(496);
            match(WhixyParser::NEWLINE);
        }
        setState(499);
        match(WhixyParser::CLOSEDBRACKET_GREATERTHAN);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- DollarParenContext ------------------------------------------------------------------

WhixyParser::DollarParenContext::DollarParenContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::DollarParenContext::DOLLAR_OPENPARENTHESIS()
{
    return getToken(WhixyParser::DOLLAR_OPENPARENTHESIS, 0);
}

std::vector<tree::TerminalNode*> WhixyParser::DollarParenContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::DollarParenContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

size_t WhixyParser::DollarParenContext::getRuleIndex() const { return WhixyParser::RuleDollarParen; }

std::any WhixyParser::DollarParenContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDollarParen(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::DollarParenContext* WhixyParser::dollarParen()
{
    DollarParenContext* _localctx = _tracker.createInstance<DollarParenContext>(_ctx, getState());
    enterRule(_localctx, 80, WhixyParser::RuleDollarParen);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(502);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(501);
            match(WhixyParser::NEWLINE);
        }
        setState(504);
        match(WhixyParser::DOLLAR_OPENPARENTHESIS);
        setState(506);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx)) {
        case 1: {
            setState(505);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- OParenContext ------------------------------------------------------------------

WhixyParser::OParenContext::OParenContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::OParenContext::OPENPARENTHESIS() { return getToken(WhixyParser::OPENPARENTHESIS, 0); }

std::vector<tree::TerminalNode*> WhixyParser::OParenContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::OParenContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

size_t WhixyParser::OParenContext::getRuleIndex() const { return WhixyParser::RuleOParen; }

std::any WhixyParser::OParenContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOParen(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::OParenContext* WhixyParser::oParen()
{
    OParenContext* _localctx = _tracker.createInstance<OParenContext>(_ctx, getState());
    enterRule(_localctx, 82, WhixyParser::RuleOParen);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(509);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(508);
            match(WhixyParser::NEWLINE);
        }
        setState(511);
        match(WhixyParser::OPENPARENTHESIS);
        setState(513);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
        case 1: {
            setState(512);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CParenContext ------------------------------------------------------------------

WhixyParser::CParenContext::CParenContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::CParenContext::CLOSEDPARENTHESIS()
{
    return getToken(WhixyParser::CLOSEDPARENTHESIS, 0);
}

tree::TerminalNode* WhixyParser::CParenContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::CParenContext::getRuleIndex() const { return WhixyParser::RuleCParen; }

std::any WhixyParser::CParenContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCParen(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CParenContext* WhixyParser::cParen()
{
    CParenContext* _localctx = _tracker.createInstance<CParenContext>(_ctx, getState());
    enterRule(_localctx, 84, WhixyParser::RuleCParen);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(516);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(515);
            match(WhixyParser::NEWLINE);
        }
        setState(518);
        match(WhixyParser::CLOSEDPARENTHESIS);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- OBraceContext ------------------------------------------------------------------

WhixyParser::OBraceContext::OBraceContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::OBraceContext::OPENBRACE() { return getToken(WhixyParser::OPENBRACE, 0); }

std::vector<tree::TerminalNode*> WhixyParser::OBraceContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::OBraceContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

size_t WhixyParser::OBraceContext::getRuleIndex() const { return WhixyParser::RuleOBrace; }

std::any WhixyParser::OBraceContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOBrace(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::OBraceContext* WhixyParser::oBrace()
{
    OBraceContext* _localctx = _tracker.createInstance<OBraceContext>(_ctx, getState());
    enterRule(_localctx, 86, WhixyParser::RuleOBrace);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(521);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(520);
            match(WhixyParser::NEWLINE);
        }
        setState(523);
        match(WhixyParser::OPENBRACE);
        setState(525);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
        case 1: {
            setState(524);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- CBraceContext ------------------------------------------------------------------

WhixyParser::CBraceContext::CBraceContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::CBraceContext::CLOSEDBRACE() { return getToken(WhixyParser::CLOSEDBRACE, 0); }

tree::TerminalNode* WhixyParser::CBraceContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::CBraceContext::getRuleIndex() const { return WhixyParser::RuleCBrace; }

std::any WhixyParser::CBraceContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitCBrace(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::CBraceContext* WhixyParser::cBrace()
{
    CBraceContext* _localctx = _tracker.createInstance<CBraceContext>(_ctx, getState());
    enterRule(_localctx, 88, WhixyParser::RuleCBrace);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(528);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(527);
            match(WhixyParser::NEWLINE);
        }
        setState(530);
        match(WhixyParser::CLOSEDBRACE);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- StmtSepContext ------------------------------------------------------------------

WhixyParser::StmtSepContext::StmtSepContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::StmtSepContext::SEMICOLON() { return getToken(WhixyParser::SEMICOLON, 0); }

tree::TerminalNode* WhixyParser::StmtSepContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::StmtSepContext::getRuleIndex() const { return WhixyParser::RuleStmtSep; }

std::any WhixyParser::StmtSepContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitStmtSep(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::StmtSepContext* WhixyParser::stmtSep()
{
    StmtSepContext* _localctx = _tracker.createInstance<StmtSepContext>(_ctx, getState());
    enterRule(_localctx, 90, WhixyParser::RuleStmtSep);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(532);
        _la = _input->LA(1);
        if (!(_la == WhixyParser::SEMICOLON || _la == WhixyParser::NEWLINE)) { _errHandler->recoverInline(this); }
        else {
            _errHandler->reportMatch(this);
            consume();
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ExprSepContext ------------------------------------------------------------------

WhixyParser::ExprSepContext::ExprSepContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ExprSepContext::COMMA() { return getToken(WhixyParser::COMMA, 0); }

tree::TerminalNode* WhixyParser::ExprSepContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::ExprSepContext::getRuleIndex() const { return WhixyParser::RuleExprSep; }

std::any WhixyParser::ExprSepContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitExprSep(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ExprSepContext* WhixyParser::exprSep()
{
    ExprSepContext* _localctx = _tracker.createInstance<ExprSepContext>(_ctx, getState());
    enterRule(_localctx, 92, WhixyParser::RuleExprSep);
    size_t _la = 0;

#if __cplusplus > 201703L
    auto onExit = finally(
        [=, this]
        {
#else
    auto onExit = finally(
        [=]
        {
#endif
            exitRule();
        }
    );
    try {
        enterOuterAlt(_localctx, 1);
        setState(534);
        _la = _input->LA(1);
        if (!(_la == WhixyParser::COMMA || _la == WhixyParser::NEWLINE)) { _errHandler->recoverInline(this); }
        else {
            _errHandler->reportMatch(this);
            consume();
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

void WhixyParser::initialize()
{
#if ANTLR4_USE_THREAD_LOCAL_CACHE
    whixyparserParserInitialize();
#else
    ::antlr4::internal::call_once(whixyparserParserOnceFlag, whixyparserParserInitialize);
#endif
}
