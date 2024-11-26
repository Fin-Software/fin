
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
        std::vector<std::string>{"srcFile",      "stmt",      "valsStmt",      "callStmt",      "blockStmt",
                                 "returnStmt",   "funcStmt",  "procStmt",      "ifStmt",        "isStmt",
                                 "matchStmt",    "whileStmt", "forStmt",       "comptStmt",     "deferStmt",
                                 "errdeferStmt", "expr",      "accessExpr",    "ifExpr",        "isExpr",
                                 "matchExpr",    "whileExpr", "forExpr",       "funcExpr",      "procExpr",
                                 "binaryOpExpr", "binaryOp",  "comptExpr",     "preOpExpr",     "preOp",
                                 "postOpExpr",   "postOp",    "string",        "atom",          "blockExpr",
                                 "typeExpr",     "tupleExpr", "token",         "eof",           "equal",
                                 "oBracket",     "cBracket",  "oAngleBracket", "cAngleBracket", "oParen",
                                 "cParen",       "oBrace",    "cBrace",        "stmtSep",       "exprSep"},
        std::vector<std::string>{"",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "",
                                 "':'",
                                 "','",
                                 "';'",
                                 "'\\u003F'",
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
                                 "'proc'",
                                 "'func'",
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
                                 "'match'",
                                 "'is'",
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
                                 "'as'"},
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
            "PROC",
            "FUNC",
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
            "MATCH",
            "IS",
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
        4,   1,   97,  509, 2,   0,   7,   0,   2,   1,   7,   1,   2,   2,   7,   2,   2,   3,   7,   3,   2,   4,
        7,   4,   2,   5,   7,   5,   2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,   9,
        2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,  7,   13,  2,   14,  7,   14,  2,   15,
        7,   15,  2,   16,  7,   16,  2,   17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,
        2,   21,  7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,   24,  2,   25,  7,   25,  2,   26,
        7,   26,  2,   27,  7,   27,  2,   28,  7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,  7,   31,
        2,   32,  7,   32,  2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,  2,   36,  7,   36,  2,   37,
        7,   37,  2,   38,  7,   38,  2,   39,  7,   39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,  7,   42,
        2,   43,  7,   43,  2,   44,  7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  2,   47,  7,   47,  2,   48,
        7,   48,  2,   49,  7,   49,  1,   0,   1,   0,   1,   0,   1,   0,   5,   0,   105, 8,   0,   10,  0,   12,
        0,   108, 9,   0,   1,   0,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,
        1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   1,   126, 8,   1,   1,   2,   4,
        2,   129, 8,   2,   11,  2,   12,  2,   130, 1,   2,   1,   2,   1,   2,   1,   2,   1,   2,   3,   2,   138,
        8,   2,   1,   2,   1,   2,   1,   3,   4,   3,   143, 8,   3,   11,  3,   12,  3,   144, 1,   4,   1,   4,
        1,   4,   1,   4,   1,   4,   5,   4,   152, 8,   4,   10,  4,   12,  4,   155, 9,   4,   3,   4,   157, 8,
        4,   1,   4,   1,   4,   1,   5,   1,   5,   4,   5,   163, 8,   5,   11,  5,   12,  5,   164, 1,   6,   3,
        6,   168, 8,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   6,   1,   7,   3,   7,   177, 8,
        7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   7,   1,   8,   1,   8,   1,   8,   1,   8,   1,
        8,   1,   8,   1,   8,   5,   8,   192, 8,   8,   10,  8,   12,  8,   195, 9,   8,   1,   8,   1,   8,   3,
        8,   199, 8,   8,   1,   9,   1,   9,   1,   10,  1,   10,  1,   11,  3,   11,  206, 8,   11,  1,   11,  1,
        11,  3,   11,  210, 8,   11,  1,   11,  3,   11,  213, 8,   11,  1,   11,  1,   11,  1,   12,  3,   12,  218,
        8,   12,  1,   12,  1,   12,  3,   12,  222, 8,   12,  1,   12,  3,   12,  225, 8,   12,  1,   12,  1,   12,
        1,   13,  1,   13,  1,   13,  1,   14,  1,   14,  1,   14,  1,   15,  1,   15,  1,   15,  1,   16,  1,   16,
        1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,  1,   16,
        1,   16,  1,   16,  1,   16,  3,   16,  254, 8,   16,  1,   17,  1,   17,  1,   17,  1,   17,  1,   18,  1,
        18,  1,   18,  1,   18,  1,   18,  1,   18,  1,   18,  5,   18,  267, 8,   18,  10,  18,  12,  18,  270, 9,
        18,  1,   18,  1,   18,  3,   18,  274, 8,   18,  1,   19,  1,   19,  1,   20,  1,   20,  1,   21,  3,   21,
        281, 8,   21,  1,   21,  1,   21,  3,   21,  285, 8,   21,  1,   21,  3,   21,  288, 8,   21,  1,   21,  1,
        21,  1,   22,  3,   22,  293, 8,   22,  1,   22,  1,   22,  3,   22,  297, 8,   22,  1,   22,  3,   22,  300,
        8,   22,  1,   22,  1,   22,  1,   23,  3,   23,  305, 8,   23,  1,   23,  1,   23,  1,   23,  1,   23,  1,
        23,  1,   24,  3,   24,  313, 8,   24,  1,   24,  1,   24,  1,   24,  1,   24,  1,   24,  1,   25,  1,   25,
        3,   25,  322, 8,   25,  1,   25,  1,   25,  3,   25,  326, 8,   25,  1,   25,  1,   25,  1,   26,  1,   26,
        1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,
        1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,
        1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,  1,   26,
        1,   26,  1,   26,  1,   26,  1,   26,  3,   26,  369, 8,   26,  1,   27,  1,   27,  1,   27,  1,   28,  1,
        28,  1,   28,  1,   29,  1,   29,  3,   29,  379, 8,   29,  1,   30,  1,   30,  1,   30,  1,   31,  1,   31,
        1,   31,  1,   31,  1,   31,  3,   31,  389, 8,   31,  1,   32,  1,   32,  3,   32,  393, 8,   32,  1,   33,
        1,   33,  1,   33,  1,   33,  3,   33,  399, 8,   33,  1,   34,  1,   34,  1,   34,  1,   34,  1,   34,  5,
        34,  406, 8,   34,  10,  34,  12,  34,  409, 9,   34,  1,   34,  1,   34,  3,   34,  413, 8,   34,  1,   34,
        3,   34,  416, 8,   34,  1,   34,  1,   34,  1,   35,  1,   35,  1,   35,  1,   35,  1,   35,  5,   35,  425,
        8,   35,  10,  35,  12,  35,  428, 9,   35,  3,   35,  430, 8,   35,  1,   35,  1,   35,  1,   36,  1,   36,
        1,   36,  1,   36,  1,   36,  5,   36,  439, 8,   36,  10,  36,  12,  36,  442, 9,   36,  3,   36,  444, 8,
        36,  1,   36,  1,   36,  1,   37,  1,   37,  1,   38,  3,   38,  451, 8,   38,  1,   38,  1,   38,  1,   39,
        1,   39,  3,   39,  457, 8,   39,  1,   40,  1,   40,  3,   40,  461, 8,   40,  1,   41,  3,   41,  464, 8,
        41,  1,   41,  1,   41,  1,   42,  1,   42,  3,   42,  470, 8,   42,  1,   43,  3,   43,  473, 8,   43,  1,
        43,  1,   43,  1,   44,  3,   44,  478, 8,   44,  1,   44,  1,   44,  3,   44,  482, 8,   44,  1,   45,  3,
        45,  485, 8,   45,  1,   45,  1,   45,  3,   45,  489, 8,   45,  1,   46,  3,   46,  492, 8,   46,  1,   46,
        1,   46,  3,   46,  496, 8,   46,  1,   47,  3,   47,  499, 8,   47,  1,   47,  1,   47,  3,   47,  503, 8,
        47,  1,   48,  1,   48,  1,   49,  1,   49,  1,   49,  0,   0,   50,  0,   2,   4,   6,   8,   10,  12,  14,
        16,  18,  20,  22,  24,  26,  28,  30,  32,  34,  36,  38,  40,  42,  44,  46,  48,  50,  52,  54,  56,  58,
        60,  62,  64,  66,  68,  70,  72,  74,  76,  78,  80,  82,  84,  86,  88,  90,  92,  94,  96,  98,  0,   2,
        2,   0,   8,   8,   96,  96,  2,   0,   7,   7,   96,  96,  584, 0,   100, 1,   0,   0,   0,   2,   125, 1,
        0,   0,   0,   4,   128, 1,   0,   0,   0,   6,   142, 1,   0,   0,   0,   8,   146, 1,   0,   0,   0,   10,
        160, 1,   0,   0,   0,   12,  167, 1,   0,   0,   0,   14,  176, 1,   0,   0,   0,   16,  184, 1,   0,   0,
        0,   18,  200, 1,   0,   0,   0,   20,  202, 1,   0,   0,   0,   22,  205, 1,   0,   0,   0,   24,  217, 1,
        0,   0,   0,   26,  228, 1,   0,   0,   0,   28,  231, 1,   0,   0,   0,   30,  234, 1,   0,   0,   0,   32,
        253, 1,   0,   0,   0,   34,  255, 1,   0,   0,   0,   36,  259, 1,   0,   0,   0,   38,  275, 1,   0,   0,
        0,   40,  277, 1,   0,   0,   0,   42,  280, 1,   0,   0,   0,   44,  292, 1,   0,   0,   0,   46,  304, 1,
        0,   0,   0,   48,  312, 1,   0,   0,   0,   50,  319, 1,   0,   0,   0,   52,  368, 1,   0,   0,   0,   54,
        370, 1,   0,   0,   0,   56,  373, 1,   0,   0,   0,   58,  378, 1,   0,   0,   0,   60,  380, 1,   0,   0,
        0,   62,  388, 1,   0,   0,   0,   64,  392, 1,   0,   0,   0,   66,  398, 1,   0,   0,   0,   68,  400, 1,
        0,   0,   0,   70,  419, 1,   0,   0,   0,   72,  433, 1,   0,   0,   0,   74,  447, 1,   0,   0,   0,   76,
        450, 1,   0,   0,   0,   78,  454, 1,   0,   0,   0,   80,  458, 1,   0,   0,   0,   82,  463, 1,   0,   0,
        0,   84,  467, 1,   0,   0,   0,   86,  472, 1,   0,   0,   0,   88,  477, 1,   0,   0,   0,   90,  484, 1,
        0,   0,   0,   92,  491, 1,   0,   0,   0,   94,  498, 1,   0,   0,   0,   96,  504, 1,   0,   0,   0,   98,
        506, 1,   0,   0,   0,   100, 106, 3,   2,   1,   0,   101, 102, 3,   96,  48,  0,   102, 103, 3,   2,   1,
        0,   103, 105, 1,   0,   0,   0,   104, 101, 1,   0,   0,   0,   105, 108, 1,   0,   0,   0,   106, 104, 1,
        0,   0,   0,   106, 107, 1,   0,   0,   0,   107, 109, 1,   0,   0,   0,   108, 106, 1,   0,   0,   0,   109,
        110, 3,   76,  38,  0,   110, 1,   1,   0,   0,   0,   111, 126, 3,   4,   2,   0,   112, 126, 3,   6,   3,
        0,   113, 126, 3,   8,   4,   0,   114, 126, 3,   10,  5,   0,   115, 126, 3,   12,  6,   0,   116, 126, 3,
        14,  7,   0,   117, 126, 3,   16,  8,   0,   118, 126, 3,   18,  9,   0,   119, 126, 3,   20,  10,  0,   120,
        126, 3,   22,  11,  0,   121, 126, 3,   24,  12,  0,   122, 126, 3,   26,  13,  0,   123, 126, 3,   28,  14,
        0,   124, 126, 3,   30,  15,  0,   125, 111, 1,   0,   0,   0,   125, 112, 1,   0,   0,   0,   125, 113, 1,
        0,   0,   0,   125, 114, 1,   0,   0,   0,   125, 115, 1,   0,   0,   0,   125, 116, 1,   0,   0,   0,   125,
        117, 1,   0,   0,   0,   125, 118, 1,   0,   0,   0,   125, 119, 1,   0,   0,   0,   125, 120, 1,   0,   0,
        0,   125, 121, 1,   0,   0,   0,   125, 122, 1,   0,   0,   0,   125, 123, 1,   0,   0,   0,   125, 124, 1,
        0,   0,   0,   126, 3,   1,   0,   0,   0,   127, 129, 3,   74,  37,  0,   128, 127, 1,   0,   0,   0,   129,
        130, 1,   0,   0,   0,   130, 128, 1,   0,   0,   0,   130, 131, 1,   0,   0,   0,   131, 132, 1,   0,   0,
        0,   132, 137, 5,   6,   0,   0,   133, 134, 3,   32,  16,  0,   134, 135, 5,   61,  0,   0,   135, 138, 1,
        0,   0,   0,   136, 138, 5,   61,  0,   0,   137, 133, 1,   0,   0,   0,   137, 136, 1,   0,   0,   0,   137,
        138, 1,   0,   0,   0,   138, 139, 1,   0,   0,   0,   139, 140, 3,   32,  16,  0,   140, 5,   1,   0,   0,
        0,   141, 143, 3,   66,  33,  0,   142, 141, 1,   0,   0,   0,   143, 144, 1,   0,   0,   0,   144, 142, 1,
        0,   0,   0,   144, 145, 1,   0,   0,   0,   145, 7,   1,   0,   0,   0,   146, 156, 3,   88,  44,  0,   147,
        153, 3,   2,   1,   0,   148, 149, 3,   96,  48,  0,   149, 150, 3,   2,   1,   0,   150, 152, 1,   0,   0,
        0,   151, 148, 1,   0,   0,   0,   152, 155, 1,   0,   0,   0,   153, 151, 1,   0,   0,   0,   153, 154, 1,
        0,   0,   0,   154, 157, 1,   0,   0,   0,   155, 153, 1,   0,   0,   0,   156, 147, 1,   0,   0,   0,   156,
        157, 1,   0,   0,   0,   157, 158, 1,   0,   0,   0,   158, 159, 3,   90,  45,  0,   159, 9,   1,   0,   0,
        0,   160, 162, 5,   68,  0,   0,   161, 163, 3,   66,  33,  0,   162, 161, 1,   0,   0,   0,   163, 164, 1,
        0,   0,   0,   164, 162, 1,   0,   0,   0,   164, 165, 1,   0,   0,   0,   165, 11,  1,   0,   0,   0,   166,
        168, 5,   67,  0,   0,   167, 166, 1,   0,   0,   0,   167, 168, 1,   0,   0,   0,   168, 169, 1,   0,   0,
        0,   169, 170, 5,   65,  0,   0,   170, 171, 3,   74,  37,  0,   171, 172, 3,   70,  35,  0,   172, 173, 3,
        72,  36,  0,   173, 174, 3,   8,   4,   0,   174, 13,  1,   0,   0,   0,   175, 177, 5,   67,  0,   0,   176,
        175, 1,   0,   0,   0,   176, 177, 1,   0,   0,   0,   177, 178, 1,   0,   0,   0,   178, 179, 5,   64,  0,
        0,   179, 180, 3,   74,  37,  0,   180, 181, 3,   70,  35,  0,   181, 182, 3,   72,  36,  0,   182, 183, 3,
        8,   4,   0,   183, 15,  1,   0,   0,   0,   184, 185, 5,   74,  0,   0,   185, 186, 3,   68,  34,  0,   186,
        193, 3,   8,   4,   0,   187, 188, 5,   75,  0,   0,   188, 189, 3,   68,  34,  0,   189, 190, 3,   8,   4,
        0,   190, 192, 1,   0,   0,   0,   191, 187, 1,   0,   0,   0,   192, 195, 1,   0,   0,   0,   193, 191, 1,
        0,   0,   0,   193, 194, 1,   0,   0,   0,   194, 198, 1,   0,   0,   0,   195, 193, 1,   0,   0,   0,   196,
        197, 5,   76,  0,   0,   197, 199, 3,   8,   4,   0,   198, 196, 1,   0,   0,   0,   198, 199, 1,   0,   0,
        0,   199, 17,  1,   0,   0,   0,   200, 201, 5,   78,  0,   0,   201, 19,  1,   0,   0,   0,   202, 203, 5,
        77,  0,   0,   203, 21,  1,   0,   0,   0,   204, 206, 5,   89,  0,   0,   205, 204, 1,   0,   0,   0,   205,
        206, 1,   0,   0,   0,   206, 207, 1,   0,   0,   0,   207, 209, 5,   72,  0,   0,   208, 210, 3,   68,  34,
        0,   209, 208, 1,   0,   0,   0,   209, 210, 1,   0,   0,   0,   210, 212, 1,   0,   0,   0,   211, 213, 3,
        68,  34,  0,   212, 211, 1,   0,   0,   0,   212, 213, 1,   0,   0,   0,   213, 214, 1,   0,   0,   0,   214,
        215, 3,   8,   4,   0,   215, 23,  1,   0,   0,   0,   216, 218, 5,   89,  0,   0,   217, 216, 1,   0,   0,
        0,   217, 218, 1,   0,   0,   0,   218, 219, 1,   0,   0,   0,   219, 221, 5,   73,  0,   0,   220, 222, 3,
        68,  34,  0,   221, 220, 1,   0,   0,   0,   221, 222, 1,   0,   0,   0,   222, 224, 1,   0,   0,   0,   223,
        225, 3,   68,  34,  0,   224, 223, 1,   0,   0,   0,   224, 225, 1,   0,   0,   0,   225, 226, 1,   0,   0,
        0,   226, 227, 3,   8,   4,   0,   227, 25,  1,   0,   0,   0,   228, 229, 5,   90,  0,   0,   229, 230, 3,
        2,   1,   0,   230, 27,  1,   0,   0,   0,   231, 232, 5,   79,  0,   0,   232, 233, 3,   2,   1,   0,   233,
        29,  1,   0,   0,   0,   234, 235, 5,   80,  0,   0,   235, 236, 3,   2,   1,   0,   236, 31,  1,   0,   0,
        0,   237, 254, 3,   4,   2,   0,   238, 254, 3,   6,   3,   0,   239, 254, 3,   34,  17,  0,   240, 254, 3,
        36,  18,  0,   241, 254, 3,   38,  19,  0,   242, 254, 3,   40,  20,  0,   243, 254, 3,   42,  21,  0,   244,
        254, 3,   44,  22,  0,   245, 254, 3,   46,  23,  0,   246, 254, 3,   48,  24,  0,   247, 254, 3,   50,  25,
        0,   248, 254, 3,   54,  27,  0,   249, 254, 3,   56,  28,  0,   250, 254, 3,   60,  30,  0,   251, 254, 3,
        64,  32,  0,   252, 254, 3,   66,  33,  0,   253, 237, 1,   0,   0,   0,   253, 238, 1,   0,   0,   0,   253,
        239, 1,   0,   0,   0,   253, 240, 1,   0,   0,   0,   253, 241, 1,   0,   0,   0,   253, 242, 1,   0,   0,
        0,   253, 243, 1,   0,   0,   0,   253, 244, 1,   0,   0,   0,   253, 245, 1,   0,   0,   0,   253, 246, 1,
        0,   0,   0,   253, 247, 1,   0,   0,   0,   253, 248, 1,   0,   0,   0,   253, 249, 1,   0,   0,   0,   253,
        250, 1,   0,   0,   0,   253, 251, 1,   0,   0,   0,   253, 252, 1,   0,   0,   0,   254, 33,  1,   0,   0,
        0,   255, 256, 3,   66,  33,  0,   256, 257, 5,   23,  0,   0,   257, 258, 3,   66,  33,  0,   258, 35,  1,
        0,   0,   0,   259, 260, 5,   74,  0,   0,   260, 261, 3,   68,  34,  0,   261, 268, 3,   32,  16,  0,   262,
        263, 5,   75,  0,   0,   263, 264, 3,   68,  34,  0,   264, 265, 3,   32,  16,  0,   265, 267, 1,   0,   0,
        0,   266, 262, 1,   0,   0,   0,   267, 270, 1,   0,   0,   0,   268, 266, 1,   0,   0,   0,   268, 269, 1,
        0,   0,   0,   269, 273, 1,   0,   0,   0,   270, 268, 1,   0,   0,   0,   271, 272, 5,   76,  0,   0,   272,
        274, 3,   32,  16,  0,   273, 271, 1,   0,   0,   0,   273, 274, 1,   0,   0,   0,   274, 37,  1,   0,   0,
        0,   275, 276, 5,   78,  0,   0,   276, 39,  1,   0,   0,   0,   277, 278, 5,   77,  0,   0,   278, 41,  1,
        0,   0,   0,   279, 281, 5,   89,  0,   0,   280, 279, 1,   0,   0,   0,   280, 281, 1,   0,   0,   0,   281,
        282, 1,   0,   0,   0,   282, 284, 5,   72,  0,   0,   283, 285, 3,   68,  34,  0,   284, 283, 1,   0,   0,
        0,   284, 285, 1,   0,   0,   0,   285, 287, 1,   0,   0,   0,   286, 288, 3,   68,  34,  0,   287, 286, 1,
        0,   0,   0,   287, 288, 1,   0,   0,   0,   288, 289, 1,   0,   0,   0,   289, 290, 3,   68,  34,  0,   290,
        43,  1,   0,   0,   0,   291, 293, 5,   89,  0,   0,   292, 291, 1,   0,   0,   0,   292, 293, 1,   0,   0,
        0,   293, 294, 1,   0,   0,   0,   294, 296, 5,   73,  0,   0,   295, 297, 3,   68,  34,  0,   296, 295, 1,
        0,   0,   0,   296, 297, 1,   0,   0,   0,   297, 299, 1,   0,   0,   0,   298, 300, 3,   68,  34,  0,   299,
        298, 1,   0,   0,   0,   299, 300, 1,   0,   0,   0,   300, 301, 1,   0,   0,   0,   301, 302, 3,   68,  34,
        0,   302, 45,  1,   0,   0,   0,   303, 305, 5,   67,  0,   0,   304, 303, 1,   0,   0,   0,   304, 305, 1,
        0,   0,   0,   305, 306, 1,   0,   0,   0,   306, 307, 5,   65,  0,   0,   307, 308, 3,   70,  35,  0,   308,
        309, 3,   72,  36,  0,   309, 310, 3,   8,   4,   0,   310, 47,  1,   0,   0,   0,   311, 313, 5,   67,  0,
        0,   312, 311, 1,   0,   0,   0,   312, 313, 1,   0,   0,   0,   313, 314, 1,   0,   0,   0,   314, 315, 5,
        64,  0,   0,   315, 316, 3,   70,  35,  0,   316, 317, 3,   72,  36,  0,   317, 318, 3,   8,   4,   0,   318,
        49,  1,   0,   0,   0,   319, 321, 3,   66,  33,  0,   320, 322, 5,   96,  0,   0,   321, 320, 1,   0,   0,
        0,   321, 322, 1,   0,   0,   0,   322, 323, 1,   0,   0,   0,   323, 325, 3,   52,  26,  0,   324, 326, 5,
        96,  0,   0,   325, 324, 1,   0,   0,   0,   325, 326, 1,   0,   0,   0,   326, 327, 1,   0,   0,   0,   327,
        328, 3,   66,  33,  0,   328, 51,  1,   0,   0,   0,   329, 369, 5,   95,  0,   0,   330, 369, 5,   44,  0,
        0,   331, 369, 5,   39,  0,   0,   332, 369, 5,   45,  0,   0,   333, 369, 5,   49,  0,   0,   334, 369, 5,
        40,  0,   0,   335, 369, 5,   59,  0,   0,   336, 369, 5,   35,  0,   0,   337, 369, 5,   29,  0,   0,   338,
        369, 5,   34,  0,   0,   339, 369, 5,   28,  0,   0,   340, 369, 5,   42,  0,   0,   341, 369, 5,   47,  0,
        0,   342, 369, 5,   37,  0,   0,   343, 369, 5,   33,  0,   0,   344, 369, 5,   27,  0,   0,   345, 369, 5,
        31,  0,   0,   346, 369, 5,   25,  0,   0,   347, 369, 5,   60,  0,   0,   348, 369, 5,   50,  0,   0,   349,
        369, 5,   53,  0,   0,   350, 369, 5,   52,  0,   0,   351, 369, 5,   63,  0,   0,   352, 369, 5,   62,  0,
        0,   353, 369, 5,   55,  0,   0,   354, 369, 5,   54,  0,   0,   355, 369, 5,   57,  0,   0,   356, 369, 5,
        56,  0,   0,   357, 369, 5,   58,  0,   0,   358, 369, 5,   43,  0,   0,   359, 369, 5,   48,  0,   0,   360,
        369, 5,   38,  0,   0,   361, 369, 5,   32,  0,   0,   362, 369, 5,   26,  0,   0,   363, 369, 5,   36,  0,
        0,   364, 369, 5,   41,  0,   0,   365, 369, 5,   46,  0,   0,   366, 369, 5,   24,  0,   0,   367, 369, 5,
        30,  0,   0,   368, 329, 1,   0,   0,   0,   368, 330, 1,   0,   0,   0,   368, 331, 1,   0,   0,   0,   368,
        332, 1,   0,   0,   0,   368, 333, 1,   0,   0,   0,   368, 334, 1,   0,   0,   0,   368, 335, 1,   0,   0,
        0,   368, 336, 1,   0,   0,   0,   368, 337, 1,   0,   0,   0,   368, 338, 1,   0,   0,   0,   368, 339, 1,
        0,   0,   0,   368, 340, 1,   0,   0,   0,   368, 341, 1,   0,   0,   0,   368, 342, 1,   0,   0,   0,   368,
        343, 1,   0,   0,   0,   368, 344, 1,   0,   0,   0,   368, 345, 1,   0,   0,   0,   368, 346, 1,   0,   0,
        0,   368, 347, 1,   0,   0,   0,   368, 348, 1,   0,   0,   0,   368, 349, 1,   0,   0,   0,   368, 350, 1,
        0,   0,   0,   368, 351, 1,   0,   0,   0,   368, 352, 1,   0,   0,   0,   368, 353, 1,   0,   0,   0,   368,
        354, 1,   0,   0,   0,   368, 355, 1,   0,   0,   0,   368, 356, 1,   0,   0,   0,   368, 357, 1,   0,   0,
        0,   368, 358, 1,   0,   0,   0,   368, 359, 1,   0,   0,   0,   368, 360, 1,   0,   0,   0,   368, 361, 1,
        0,   0,   0,   368, 362, 1,   0,   0,   0,   368, 363, 1,   0,   0,   0,   368, 364, 1,   0,   0,   0,   368,
        365, 1,   0,   0,   0,   368, 366, 1,   0,   0,   0,   368, 367, 1,   0,   0,   0,   369, 53,  1,   0,   0,
        0,   370, 371, 5,   90,  0,   0,   371, 372, 3,   32,  16,  0,   372, 55,  1,   0,   0,   0,   373, 374, 3,
        58,  29,  0,   374, 375, 3,   66,  33,  0,   375, 57,  1,   0,   0,   0,   376, 379, 5,   51,  0,   0,   377,
        379, 5,   49,  0,   0,   378, 376, 1,   0,   0,   0,   378, 377, 1,   0,   0,   0,   379, 59,  1,   0,   0,
        0,   380, 381, 3,   66,  33,  0,   381, 382, 3,   62,  31,  0,   382, 61,  1,   0,   0,   0,   383, 389, 5,
        18,  0,   0,   384, 389, 5,   19,  0,   0,   385, 389, 5,   20,  0,   0,   386, 389, 5,   21,  0,   0,   387,
        389, 5,   22,  0,   0,   388, 383, 1,   0,   0,   0,   388, 384, 1,   0,   0,   0,   388, 385, 1,   0,   0,
        0,   388, 386, 1,   0,   0,   0,   388, 387, 1,   0,   0,   0,   389, 63,  1,   0,   0,   0,   390, 393, 5,
        1,   0,   0,   391, 393, 5,   2,   0,   0,   392, 390, 1,   0,   0,   0,   392, 391, 1,   0,   0,   0,   393,
        65,  1,   0,   0,   0,   394, 399, 3,   68,  34,  0,   395, 399, 3,   70,  35,  0,   396, 399, 3,   72,  36,
        0,   397, 399, 3,   74,  37,  0,   398, 394, 1,   0,   0,   0,   398, 395, 1,   0,   0,   0,   398, 396, 1,
        0,   0,   0,   398, 397, 1,   0,   0,   0,   399, 67,  1,   0,   0,   0,   400, 415, 3,   88,  44,  0,   401,
        407, 3,   2,   1,   0,   402, 403, 3,   96,  48,  0,   403, 404, 3,   2,   1,   0,   404, 406, 1,   0,   0,
        0,   405, 402, 1,   0,   0,   0,   406, 409, 1,   0,   0,   0,   407, 405, 1,   0,   0,   0,   407, 408, 1,
        0,   0,   0,   408, 410, 1,   0,   0,   0,   409, 407, 1,   0,   0,   0,   410, 411, 3,   96,  48,  0,   411,
        413, 1,   0,   0,   0,   412, 401, 1,   0,   0,   0,   412, 413, 1,   0,   0,   0,   413, 414, 1,   0,   0,
        0,   414, 416, 3,   32,  16,  0,   415, 412, 1,   0,   0,   0,   415, 416, 1,   0,   0,   0,   416, 417, 1,
        0,   0,   0,   417, 418, 3,   90,  45,  0,   418, 69,  1,   0,   0,   0,   419, 429, 3,   92,  46,  0,   420,
        426, 3,   4,   2,   0,   421, 422, 3,   98,  49,  0,   422, 423, 3,   4,   2,   0,   423, 425, 1,   0,   0,
        0,   424, 421, 1,   0,   0,   0,   425, 428, 1,   0,   0,   0,   426, 424, 1,   0,   0,   0,   426, 427, 1,
        0,   0,   0,   427, 430, 1,   0,   0,   0,   428, 426, 1,   0,   0,   0,   429, 420, 1,   0,   0,   0,   429,
        430, 1,   0,   0,   0,   430, 431, 1,   0,   0,   0,   431, 432, 3,   94,  47,  0,   432, 71,  1,   0,   0,
        0,   433, 443, 3,   88,  44,  0,   434, 440, 3,   32,  16,  0,   435, 436, 3,   98,  49,  0,   436, 437, 3,
        32,  16,  0,   437, 439, 1,   0,   0,   0,   438, 435, 1,   0,   0,   0,   439, 442, 1,   0,   0,   0,   440,
        438, 1,   0,   0,   0,   440, 441, 1,   0,   0,   0,   441, 444, 1,   0,   0,   0,   442, 440, 1,   0,   0,
        0,   443, 434, 1,   0,   0,   0,   443, 444, 1,   0,   0,   0,   444, 445, 1,   0,   0,   0,   445, 446, 3,
        90,  45,  0,   446, 73,  1,   0,   0,   0,   447, 448, 5,   97,  0,   0,   448, 75,  1,   0,   0,   0,   449,
        451, 5,   96,  0,   0,   450, 449, 1,   0,   0,   0,   450, 451, 1,   0,   0,   0,   451, 452, 1,   0,   0,
        0,   452, 453, 5,   0,   0,   1,   453, 77,  1,   0,   0,   0,   454, 456, 5,   61,  0,   0,   455, 457, 5,
        96,  0,   0,   456, 455, 1,   0,   0,   0,   456, 457, 1,   0,   0,   0,   457, 79,  1,   0,   0,   0,   458,
        460, 5,   16,  0,   0,   459, 461, 5,   96,  0,   0,   460, 459, 1,   0,   0,   0,   460, 461, 1,   0,   0,
        0,   461, 81,  1,   0,   0,   0,   462, 464, 5,   96,  0,   0,   463, 462, 1,   0,   0,   0,   463, 464, 1,
        0,   0,   0,   464, 465, 1,   0,   0,   0,   465, 466, 5,   17,  0,   0,   466, 83,  1,   0,   0,   0,   467,
        469, 5,   14,  0,   0,   468, 470, 5,   96,  0,   0,   469, 468, 1,   0,   0,   0,   469, 470, 1,   0,   0,
        0,   470, 85,  1,   0,   0,   0,   471, 473, 5,   96,  0,   0,   472, 471, 1,   0,   0,   0,   472, 473, 1,
        0,   0,   0,   473, 474, 1,   0,   0,   0,   474, 475, 5,   15,  0,   0,   475, 87,  1,   0,   0,   0,   476,
        478, 5,   96,  0,   0,   477, 476, 1,   0,   0,   0,   477, 478, 1,   0,   0,   0,   478, 479, 1,   0,   0,
        0,   479, 481, 5,   10,  0,   0,   480, 482, 5,   96,  0,   0,   481, 480, 1,   0,   0,   0,   481, 482, 1,
        0,   0,   0,   482, 89,  1,   0,   0,   0,   483, 485, 5,   96,  0,   0,   484, 483, 1,   0,   0,   0,   484,
        485, 1,   0,   0,   0,   485, 486, 1,   0,   0,   0,   486, 488, 5,   11,  0,   0,   487, 489, 5,   96,  0,
        0,   488, 487, 1,   0,   0,   0,   488, 489, 1,   0,   0,   0,   489, 91,  1,   0,   0,   0,   490, 492, 5,
        96,  0,   0,   491, 490, 1,   0,   0,   0,   491, 492, 1,   0,   0,   0,   492, 493, 1,   0,   0,   0,   493,
        495, 5,   12,  0,   0,   494, 496, 5,   96,  0,   0,   495, 494, 1,   0,   0,   0,   495, 496, 1,   0,   0,
        0,   496, 93,  1,   0,   0,   0,   497, 499, 5,   96,  0,   0,   498, 497, 1,   0,   0,   0,   498, 499, 1,
        0,   0,   0,   499, 500, 1,   0,   0,   0,   500, 502, 5,   13,  0,   0,   501, 503, 5,   96,  0,   0,   502,
        501, 1,   0,   0,   0,   502, 503, 1,   0,   0,   0,   503, 95,  1,   0,   0,   0,   504, 505, 7,   0,   0,
        0,   505, 97,  1,   0,   0,   0,   506, 507, 7,   1,   0,   0,   507, 99,  1,   0,   0,   0,   57,  106, 125,
        130, 137, 144, 153, 156, 164, 167, 176, 193, 198, 205, 209, 212, 217, 221, 224, 253, 268, 273, 280, 284, 287,
        292, 296, 299, 304, 312, 321, 325, 368, 378, 388, 392, 398, 407, 412, 415, 426, 429, 440, 443, 450, 456, 460,
        463, 469, 472, 477, 481, 484, 488, 491, 495, 498, 502
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

WhixyParser::EofContext* WhixyParser::SrcFileContext::eof() { return getRuleContext<WhixyParser::EofContext>(0); }

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
        setState(100);
        stmt();
        setState(106);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(101);
                stmtSep();
                setState(102);
                stmt();
            }
            setState(108);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
        }
        setState(109);
        eof();

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

WhixyParser::CallStmtContext* WhixyParser::StmtContext::callStmt()
{
    return getRuleContext<WhixyParser::CallStmtContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::StmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

WhixyParser::ReturnStmtContext* WhixyParser::StmtContext::returnStmt()
{
    return getRuleContext<WhixyParser::ReturnStmtContext>(0);
}

WhixyParser::FuncStmtContext* WhixyParser::StmtContext::funcStmt()
{
    return getRuleContext<WhixyParser::FuncStmtContext>(0);
}

WhixyParser::ProcStmtContext* WhixyParser::StmtContext::procStmt()
{
    return getRuleContext<WhixyParser::ProcStmtContext>(0);
}

WhixyParser::IfStmtContext* WhixyParser::StmtContext::ifStmt() { return getRuleContext<WhixyParser::IfStmtContext>(0); }

WhixyParser::IsStmtContext* WhixyParser::StmtContext::isStmt() { return getRuleContext<WhixyParser::IsStmtContext>(0); }

WhixyParser::MatchStmtContext* WhixyParser::StmtContext::matchStmt()
{
    return getRuleContext<WhixyParser::MatchStmtContext>(0);
}

WhixyParser::WhileStmtContext* WhixyParser::StmtContext::whileStmt()
{
    return getRuleContext<WhixyParser::WhileStmtContext>(0);
}

WhixyParser::ForStmtContext* WhixyParser::StmtContext::forStmt()
{
    return getRuleContext<WhixyParser::ForStmtContext>(0);
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
        setState(125);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(111);
            valsStmt();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(112);
            callStmt();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(113);
            blockStmt();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(114);
            returnStmt();
            break;
        }

        case 5: {
            enterOuterAlt(_localctx, 5);
            setState(115);
            funcStmt();
            break;
        }

        case 6: {
            enterOuterAlt(_localctx, 6);
            setState(116);
            procStmt();
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
            isStmt();
            break;
        }

        case 9: {
            enterOuterAlt(_localctx, 9);
            setState(119);
            matchStmt();
            break;
        }

        case 10: {
            enterOuterAlt(_localctx, 10);
            setState(120);
            whileStmt();
            break;
        }

        case 11: {
            enterOuterAlt(_localctx, 11);
            setState(121);
            forStmt();
            break;
        }

        case 12: {
            enterOuterAlt(_localctx, 12);
            setState(122);
            comptStmt();
            break;
        }

        case 13: {
            enterOuterAlt(_localctx, 13);
            setState(123);
            deferStmt();
            break;
        }

        case 14: {
            enterOuterAlt(_localctx, 14);
            setState(124);
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
        setState(128);
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
            setState(127);
            token();
            setState(130);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        while (_la == WhixyParser::TOKEN);
        setState(132);
        match(WhixyParser::COLON);
        setState(137);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
            setState(133);
            expr();
            setState(134);
            match(WhixyParser::EQUAL);
            break;
        }

        case 2: {
            setState(136);
            match(WhixyParser::EQUAL);
            break;
        }

        default: break;
        }
        setState(139);
        expr();

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

std::vector<WhixyParser::AtomContext*> WhixyParser::CallStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::CallStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

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
    enterRule(_localctx, 6, WhixyParser::RuleCallStmt);

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
        setState(142);
        _errHandler->sync(this);
        alt = 1;
        do {
            switch (alt) {
            case 1: {
                setState(141);
                atom();
                break;
            }

            default: throw NoViableAltException(this);
            }
            setState(144);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
        }
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);

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

WhixyParser::OParenContext* WhixyParser::BlockStmtContext::oParen()
{
    return getRuleContext<WhixyParser::OParenContext>(0);
}

WhixyParser::CParenContext* WhixyParser::BlockStmtContext::cParen()
{
    return getRuleContext<WhixyParser::CParenContext>(0);
}

std::vector<WhixyParser::StmtContext*> WhixyParser::BlockStmtContext::stmt()
{
    return getRuleContexts<WhixyParser::StmtContext>();
}

WhixyParser::StmtContext* WhixyParser::BlockStmtContext::stmt(size_t i)
{
    return getRuleContext<WhixyParser::StmtContext>(i);
}

std::vector<WhixyParser::StmtSepContext*> WhixyParser::BlockStmtContext::stmtSep()
{
    return getRuleContexts<WhixyParser::StmtSepContext>();
}

WhixyParser::StmtSepContext* WhixyParser::BlockStmtContext::stmtSep(size_t i)
{
    return getRuleContext<WhixyParser::StmtSepContext>(i);
}

size_t WhixyParser::BlockStmtContext::getRuleIndex() const { return WhixyParser::RuleBlockStmt; }

std::any WhixyParser::BlockStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitBlockStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::BlockStmtContext* WhixyParser::blockStmt()
{
    BlockStmtContext* _localctx = _tracker.createInstance<BlockStmtContext>(_ctx, getState());
    enterRule(_localctx, 8, WhixyParser::RuleBlockStmt);

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
        setState(146);
        oParen();
        setState(156);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
            setState(147);
            stmt();
            setState(153);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                    setState(148);
                    stmtSep();
                    setState(149);
                    stmt();
                }
                setState(155);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
            }
            break;
        }

        default: break;
        }
        setState(158);
        cParen();

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

std::vector<WhixyParser::AtomContext*> WhixyParser::ReturnStmtContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::ReturnStmtContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

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
    enterRule(_localctx, 10, WhixyParser::RuleReturnStmt);

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
        setState(160);
        match(WhixyParser::RETURN);
        setState(162);
        _errHandler->sync(this);
        alt = 1;
        do {
            switch (alt) {
            case 1: {
                setState(161);
                atom();
                break;
            }

            default: throw NoViableAltException(this);
            }
            setState(164);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
        }
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FuncStmtContext ------------------------------------------------------------------

WhixyParser::FuncStmtContext::FuncStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::FuncStmtContext::FUNC() { return getToken(WhixyParser::FUNC, 0); }

WhixyParser::TokenContext* WhixyParser::FuncStmtContext::token()
{
    return getRuleContext<WhixyParser::TokenContext>(0);
}

WhixyParser::TypeExprContext* WhixyParser::FuncStmtContext::typeExpr()
{
    return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::FuncStmtContext::tupleExpr()
{
    return getRuleContext<WhixyParser::TupleExprContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::FuncStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::FuncStmtContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

size_t WhixyParser::FuncStmtContext::getRuleIndex() const { return WhixyParser::RuleFuncStmt; }

std::any WhixyParser::FuncStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitFuncStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::FuncStmtContext* WhixyParser::funcStmt()
{
    FuncStmtContext* _localctx = _tracker.createInstance<FuncStmtContext>(_ctx, getState());
    enterRule(_localctx, 12, WhixyParser::RuleFuncStmt);
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
        setState(167);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::INLINE) {
            setState(166);
            match(WhixyParser::INLINE);
        }
        setState(169);
        match(WhixyParser::FUNC);
        setState(170);
        token();
        setState(171);
        typeExpr();
        setState(172);
        tupleExpr();
        setState(173);
        blockStmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ProcStmtContext ------------------------------------------------------------------

WhixyParser::ProcStmtContext::ProcStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ProcStmtContext::PROC() { return getToken(WhixyParser::PROC, 0); }

WhixyParser::TokenContext* WhixyParser::ProcStmtContext::token()
{
    return getRuleContext<WhixyParser::TokenContext>(0);
}

WhixyParser::TypeExprContext* WhixyParser::ProcStmtContext::typeExpr()
{
    return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::ProcStmtContext::tupleExpr()
{
    return getRuleContext<WhixyParser::TupleExprContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::ProcStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::ProcStmtContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

size_t WhixyParser::ProcStmtContext::getRuleIndex() const { return WhixyParser::RuleProcStmt; }

std::any WhixyParser::ProcStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitProcStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ProcStmtContext* WhixyParser::procStmt()
{
    ProcStmtContext* _localctx = _tracker.createInstance<ProcStmtContext>(_ctx, getState());
    enterRule(_localctx, 14, WhixyParser::RuleProcStmt);
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
        setState(176);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::INLINE) {
            setState(175);
            match(WhixyParser::INLINE);
        }
        setState(178);
        match(WhixyParser::PROC);
        setState(179);
        token();
        setState(180);
        typeExpr();
        setState(181);
        tupleExpr();
        setState(182);
        blockStmt();

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

std::vector<WhixyParser::BlockExprContext*> WhixyParser::IfStmtContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::IfStmtContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
}

std::vector<WhixyParser::BlockStmtContext*> WhixyParser::IfStmtContext::blockStmt()
{
    return getRuleContexts<WhixyParser::BlockStmtContext>();
}

WhixyParser::BlockStmtContext* WhixyParser::IfStmtContext::blockStmt(size_t i)
{
    return getRuleContext<WhixyParser::BlockStmtContext>(i);
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
    enterRule(_localctx, 16, WhixyParser::RuleIfStmt);
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
        setState(184);
        match(WhixyParser::IF);
        setState(185);
        blockExpr();
        setState(186);
        blockStmt();
        setState(193);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WhixyParser::ELSEIF) {
            setState(187);
            match(WhixyParser::ELSEIF);
            setState(188);
            blockExpr();
            setState(189);
            blockStmt();
            setState(195);
            _errHandler->sync(this);
            _la = _input->LA(1);
        }
        setState(198);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::ELSE) {
            setState(196);
            match(WhixyParser::ELSE);
            setState(197);
            blockStmt();
        }

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- IsStmtContext ------------------------------------------------------------------

WhixyParser::IsStmtContext::IsStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::IsStmtContext::IS() { return getToken(WhixyParser::IS, 0); }

size_t WhixyParser::IsStmtContext::getRuleIndex() const { return WhixyParser::RuleIsStmt; }

std::any WhixyParser::IsStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitIsStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::IsStmtContext* WhixyParser::isStmt()
{
    IsStmtContext* _localctx = _tracker.createInstance<IsStmtContext>(_ctx, getState());
    enterRule(_localctx, 18, WhixyParser::RuleIsStmt);

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
        setState(200);
        match(WhixyParser::IS);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- MatchStmtContext ------------------------------------------------------------------

WhixyParser::MatchStmtContext::MatchStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::MatchStmtContext::MATCH() { return getToken(WhixyParser::MATCH, 0); }

size_t WhixyParser::MatchStmtContext::getRuleIndex() const { return WhixyParser::RuleMatchStmt; }

std::any WhixyParser::MatchStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitMatchStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::MatchStmtContext* WhixyParser::matchStmt()
{
    MatchStmtContext* _localctx = _tracker.createInstance<MatchStmtContext>(_ctx, getState());
    enterRule(_localctx, 20, WhixyParser::RuleMatchStmt);

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
        setState(202);
        match(WhixyParser::MATCH);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

WhixyParser::WhileStmtContext::WhileStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::WhileStmtContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

WhixyParser::BlockStmtContext* WhixyParser::WhileStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::WhileStmtContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

std::vector<WhixyParser::BlockExprContext*> WhixyParser::WhileStmtContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::WhileStmtContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
}

size_t WhixyParser::WhileStmtContext::getRuleIndex() const { return WhixyParser::RuleWhileStmt; }

std::any WhixyParser::WhileStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWhileStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::WhileStmtContext* WhixyParser::whileStmt()
{
    WhileStmtContext* _localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
    enterRule(_localctx, 22, WhixyParser::RuleWhileStmt);
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
        setState(205);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::UNROLL) {
            setState(204);
            match(WhixyParser::UNROLL);
        }
        setState(207);
        match(WhixyParser::WHILE);
        setState(209);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
            setState(208);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(212);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
            setState(211);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(214);
        blockStmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

WhixyParser::ForStmtContext::ForStmtContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ForStmtContext::FOR() { return getToken(WhixyParser::FOR, 0); }

WhixyParser::BlockStmtContext* WhixyParser::ForStmtContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::ForStmtContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

std::vector<WhixyParser::BlockExprContext*> WhixyParser::ForStmtContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::ForStmtContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
}

size_t WhixyParser::ForStmtContext::getRuleIndex() const { return WhixyParser::RuleForStmt; }

std::any WhixyParser::ForStmtContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitForStmt(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ForStmtContext* WhixyParser::forStmt()
{
    ForStmtContext* _localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
    enterRule(_localctx, 24, WhixyParser::RuleForStmt);
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
        setState(217);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::UNROLL) {
            setState(216);
            match(WhixyParser::UNROLL);
        }
        setState(219);
        match(WhixyParser::FOR);
        setState(221);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
            setState(220);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(224);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
            setState(223);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(226);
        blockStmt();

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
    enterRule(_localctx, 26, WhixyParser::RuleComptStmt);

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
        match(WhixyParser::COMPT);
        setState(229);
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
    enterRule(_localctx, 28, WhixyParser::RuleDeferStmt);

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
        setState(231);
        match(WhixyParser::DEFER);
        setState(232);
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
    enterRule(_localctx, 30, WhixyParser::RuleErrdeferStmt);

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
        setState(234);
        match(WhixyParser::ERRDEFER);
        setState(235);
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

WhixyParser::AccessExprContext* WhixyParser::ExprContext::accessExpr()
{
    return getRuleContext<WhixyParser::AccessExprContext>(0);
}

WhixyParser::IfExprContext* WhixyParser::ExprContext::ifExpr() { return getRuleContext<WhixyParser::IfExprContext>(0); }

WhixyParser::IsExprContext* WhixyParser::ExprContext::isExpr() { return getRuleContext<WhixyParser::IsExprContext>(0); }

WhixyParser::MatchExprContext* WhixyParser::ExprContext::matchExpr()
{
    return getRuleContext<WhixyParser::MatchExprContext>(0);
}

WhixyParser::WhileExprContext* WhixyParser::ExprContext::whileExpr()
{
    return getRuleContext<WhixyParser::WhileExprContext>(0);
}

WhixyParser::ForExprContext* WhixyParser::ExprContext::forExpr()
{
    return getRuleContext<WhixyParser::ForExprContext>(0);
}

WhixyParser::FuncExprContext* WhixyParser::ExprContext::funcExpr()
{
    return getRuleContext<WhixyParser::FuncExprContext>(0);
}

WhixyParser::ProcExprContext* WhixyParser::ExprContext::procExpr()
{
    return getRuleContext<WhixyParser::ProcExprContext>(0);
}

WhixyParser::BinaryOpExprContext* WhixyParser::ExprContext::binaryOpExpr()
{
    return getRuleContext<WhixyParser::BinaryOpExprContext>(0);
}

WhixyParser::ComptExprContext* WhixyParser::ExprContext::comptExpr()
{
    return getRuleContext<WhixyParser::ComptExprContext>(0);
}

WhixyParser::PreOpExprContext* WhixyParser::ExprContext::preOpExpr()
{
    return getRuleContext<WhixyParser::PreOpExprContext>(0);
}

WhixyParser::PostOpExprContext* WhixyParser::ExprContext::postOpExpr()
{
    return getRuleContext<WhixyParser::PostOpExprContext>(0);
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
    enterRule(_localctx, 32, WhixyParser::RuleExpr);

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
        setState(253);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(237);
            valsStmt();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(238);
            callStmt();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(239);
            accessExpr();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(240);
            ifExpr();
            break;
        }

        case 5: {
            enterOuterAlt(_localctx, 5);
            setState(241);
            isExpr();
            break;
        }

        case 6: {
            enterOuterAlt(_localctx, 6);
            setState(242);
            matchExpr();
            break;
        }

        case 7: {
            enterOuterAlt(_localctx, 7);
            setState(243);
            whileExpr();
            break;
        }

        case 8: {
            enterOuterAlt(_localctx, 8);
            setState(244);
            forExpr();
            break;
        }

        case 9: {
            enterOuterAlt(_localctx, 9);
            setState(245);
            funcExpr();
            break;
        }

        case 10: {
            enterOuterAlt(_localctx, 10);
            setState(246);
            procExpr();
            break;
        }

        case 11: {
            enterOuterAlt(_localctx, 11);
            setState(247);
            binaryOpExpr();
            break;
        }

        case 12: {
            enterOuterAlt(_localctx, 12);
            setState(248);
            comptExpr();
            break;
        }

        case 13: {
            enterOuterAlt(_localctx, 13);
            setState(249);
            preOpExpr();
            break;
        }

        case 14: {
            enterOuterAlt(_localctx, 14);
            setState(250);
            postOpExpr();
            break;
        }

        case 15: {
            enterOuterAlt(_localctx, 15);
            setState(251);
            string();
            break;
        }

        case 16: {
            enterOuterAlt(_localctx, 16);
            setState(252);
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

//----------------- AccessExprContext ------------------------------------------------------------------

WhixyParser::AccessExprContext::AccessExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

std::vector<WhixyParser::AtomContext*> WhixyParser::AccessExprContext::atom()
{
    return getRuleContexts<WhixyParser::AtomContext>();
}

WhixyParser::AtomContext* WhixyParser::AccessExprContext::atom(size_t i)
{
    return getRuleContext<WhixyParser::AtomContext>(i);
}

tree::TerminalNode* WhixyParser::AccessExprContext::DOT() { return getToken(WhixyParser::DOT, 0); }

size_t WhixyParser::AccessExprContext::getRuleIndex() const { return WhixyParser::RuleAccessExpr; }

std::any WhixyParser::AccessExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAccessExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::AccessExprContext* WhixyParser::accessExpr()
{
    AccessExprContext* _localctx = _tracker.createInstance<AccessExprContext>(_ctx, getState());
    enterRule(_localctx, 34, WhixyParser::RuleAccessExpr);

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
        setState(255);
        atom();
        setState(256);
        match(WhixyParser::DOT);
        setState(257);
        atom();

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

std::vector<WhixyParser::BlockExprContext*> WhixyParser::IfExprContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::IfExprContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
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
    enterRule(_localctx, 36, WhixyParser::RuleIfExpr);

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
        setState(259);
        match(WhixyParser::IF);
        setState(260);
        blockExpr();
        setState(261);
        expr();
        setState(268);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
                setState(262);
                match(WhixyParser::ELSEIF);
                setState(263);
                blockExpr();
                setState(264);
                expr();
            }
            setState(270);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
        }
        setState(273);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
            setState(271);
            match(WhixyParser::ELSE);
            setState(272);
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

//----------------- IsExprContext ------------------------------------------------------------------

WhixyParser::IsExprContext::IsExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::IsExprContext::IS() { return getToken(WhixyParser::IS, 0); }

size_t WhixyParser::IsExprContext::getRuleIndex() const { return WhixyParser::RuleIsExpr; }

std::any WhixyParser::IsExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitIsExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::IsExprContext* WhixyParser::isExpr()
{
    IsExprContext* _localctx = _tracker.createInstance<IsExprContext>(_ctx, getState());
    enterRule(_localctx, 38, WhixyParser::RuleIsExpr);

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
        setState(275);
        match(WhixyParser::IS);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- MatchExprContext ------------------------------------------------------------------

WhixyParser::MatchExprContext::MatchExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::MatchExprContext::MATCH() { return getToken(WhixyParser::MATCH, 0); }

size_t WhixyParser::MatchExprContext::getRuleIndex() const { return WhixyParser::RuleMatchExpr; }

std::any WhixyParser::MatchExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitMatchExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::MatchExprContext* WhixyParser::matchExpr()
{
    MatchExprContext* _localctx = _tracker.createInstance<MatchExprContext>(_ctx, getState());
    enterRule(_localctx, 40, WhixyParser::RuleMatchExpr);

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
        setState(277);
        match(WhixyParser::MATCH);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- WhileExprContext ------------------------------------------------------------------

WhixyParser::WhileExprContext::WhileExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::WhileExprContext::WHILE() { return getToken(WhixyParser::WHILE, 0); }

std::vector<WhixyParser::BlockExprContext*> WhixyParser::WhileExprContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::WhileExprContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
}

tree::TerminalNode* WhixyParser::WhileExprContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

size_t WhixyParser::WhileExprContext::getRuleIndex() const { return WhixyParser::RuleWhileExpr; }

std::any WhixyParser::WhileExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWhileExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::WhileExprContext* WhixyParser::whileExpr()
{
    WhileExprContext* _localctx = _tracker.createInstance<WhileExprContext>(_ctx, getState());
    enterRule(_localctx, 42, WhixyParser::RuleWhileExpr);
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
        setState(280);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::UNROLL) {
            setState(279);
            match(WhixyParser::UNROLL);
        }
        setState(282);
        match(WhixyParser::WHILE);
        setState(284);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
            setState(283);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(287);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
            setState(286);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(289);
        blockExpr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ForExprContext ------------------------------------------------------------------

WhixyParser::ForExprContext::ForExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ForExprContext::FOR() { return getToken(WhixyParser::FOR, 0); }

std::vector<WhixyParser::BlockExprContext*> WhixyParser::ForExprContext::blockExpr()
{
    return getRuleContexts<WhixyParser::BlockExprContext>();
}

WhixyParser::BlockExprContext* WhixyParser::ForExprContext::blockExpr(size_t i)
{
    return getRuleContext<WhixyParser::BlockExprContext>(i);
}

tree::TerminalNode* WhixyParser::ForExprContext::UNROLL() { return getToken(WhixyParser::UNROLL, 0); }

size_t WhixyParser::ForExprContext::getRuleIndex() const { return WhixyParser::RuleForExpr; }

std::any WhixyParser::ForExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitForExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ForExprContext* WhixyParser::forExpr()
{
    ForExprContext* _localctx = _tracker.createInstance<ForExprContext>(_ctx, getState());
    enterRule(_localctx, 44, WhixyParser::RuleForExpr);
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
        setState(292);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::UNROLL) {
            setState(291);
            match(WhixyParser::UNROLL);
        }
        setState(294);
        match(WhixyParser::FOR);
        setState(296);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
            setState(295);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(299);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
            setState(298);
            blockExpr();
            break;
        }

        default: break;
        }
        setState(301);
        blockExpr();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- FuncExprContext ------------------------------------------------------------------

WhixyParser::FuncExprContext::FuncExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::FuncExprContext::FUNC() { return getToken(WhixyParser::FUNC, 0); }

WhixyParser::TypeExprContext* WhixyParser::FuncExprContext::typeExpr()
{
    return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::FuncExprContext::tupleExpr()
{
    return getRuleContext<WhixyParser::TupleExprContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::FuncExprContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::FuncExprContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

size_t WhixyParser::FuncExprContext::getRuleIndex() const { return WhixyParser::RuleFuncExpr; }

std::any WhixyParser::FuncExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitFuncExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::FuncExprContext* WhixyParser::funcExpr()
{
    FuncExprContext* _localctx = _tracker.createInstance<FuncExprContext>(_ctx, getState());
    enterRule(_localctx, 46, WhixyParser::RuleFuncExpr);
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
        setState(304);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::INLINE) {
            setState(303);
            match(WhixyParser::INLINE);
        }
        setState(306);
        match(WhixyParser::FUNC);
        setState(307);
        typeExpr();
        setState(308);
        tupleExpr();
        setState(309);
        blockStmt();

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- ProcExprContext ------------------------------------------------------------------

WhixyParser::ProcExprContext::ProcExprContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::ProcExprContext::PROC() { return getToken(WhixyParser::PROC, 0); }

WhixyParser::TypeExprContext* WhixyParser::ProcExprContext::typeExpr()
{
    return getRuleContext<WhixyParser::TypeExprContext>(0);
}

WhixyParser::TupleExprContext* WhixyParser::ProcExprContext::tupleExpr()
{
    return getRuleContext<WhixyParser::TupleExprContext>(0);
}

WhixyParser::BlockStmtContext* WhixyParser::ProcExprContext::blockStmt()
{
    return getRuleContext<WhixyParser::BlockStmtContext>(0);
}

tree::TerminalNode* WhixyParser::ProcExprContext::INLINE() { return getToken(WhixyParser::INLINE, 0); }

size_t WhixyParser::ProcExprContext::getRuleIndex() const { return WhixyParser::RuleProcExpr; }

std::any WhixyParser::ProcExprContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitProcExpr(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::ProcExprContext* WhixyParser::procExpr()
{
    ProcExprContext* _localctx = _tracker.createInstance<ProcExprContext>(_ctx, getState());
    enterRule(_localctx, 48, WhixyParser::RuleProcExpr);
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
        setState(312);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::INLINE) {
            setState(311);
            match(WhixyParser::INLINE);
        }
        setState(314);
        match(WhixyParser::PROC);
        setState(315);
        typeExpr();
        setState(316);
        tupleExpr();
        setState(317);
        blockStmt();

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
    enterRule(_localctx, 50, WhixyParser::RuleBinaryOpExpr);
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
        setState(319);
        atom();
        setState(321);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(320);
            match(WhixyParser::NEWLINE);
        }
        setState(323);
        binaryOp();
        setState(325);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
        case 1: {
            setState(324);
            match(WhixyParser::NEWLINE);
            break;
        }

        default: break;
        }
        setState(327);
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
//----------------- LeftRotationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftRotationAssignOpContext::LESSTHAN_LESSTHAN_PERCENT_EQUAL()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN_PERCENT_EQUAL, 0);
}

WhixyParser::LeftRotationAssignOpContext::LeftRotationAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::LeftRotationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitLeftRotationAssignOp(this);
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
//----------------- ModulusAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::ModulusAssignOpContext::PERCENT_EQUAL()
{
    return getToken(WhixyParser::PERCENT_EQUAL, 0);
}

WhixyParser::ModulusAssignOpContext::ModulusAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::ModulusAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitModulusAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- WrappingSubtractionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingSubtractionAssignOpContext::MINUS_PERCENT_EQUAL()
{
    return getToken(WhixyParser::MINUS_PERCENT_EQUAL, 0);
}

WhixyParser::WrappingSubtractionAssignOpContext::WrappingSubtractionAssignOpContext(BinaryOpContext* ctx)
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
//----------------- MultiplicationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::MultiplicationAssignOpContext::ASTERISK_EQUAL()
{
    return getToken(WhixyParser::ASTERISK_EQUAL, 0);
}

WhixyParser::MultiplicationAssignOpContext::MultiplicationAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::MultiplicationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitMultiplicationAssignOp(this);
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
//----------------- SubtractionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::SubtractionAssignOpContext::MINUS_EQUAL()
{
    return getToken(WhixyParser::MINUS_EQUAL, 0);
}

WhixyParser::SubtractionAssignOpContext::SubtractionAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::SubtractionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitSubtractionAssignOp(this);
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
//----------------- OrAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::OrAssignOpContext::PIPE_EQUAL() { return getToken(WhixyParser::PIPE_EQUAL, 0); }

WhixyParser::OrAssignOpContext::OrAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::OrAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitOrAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- LeftShiftAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::LeftShiftAssignOpContext::LESSTHAN_LESSTHAN_EQUAL()
{
    return getToken(WhixyParser::LESSTHAN_LESSTHAN_EQUAL, 0);
}

WhixyParser::LeftShiftAssignOpContext::LeftShiftAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

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

WhixyParser::WrappingMultiplicationAssignOpContext::WrappingMultiplicationAssignOpContext(BinaryOpContext* ctx)
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
//----------------- DivisionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::DivisionAssignOpContext::SLASH_EQUAL()
{
    return getToken(WhixyParser::SLASH_EQUAL, 0);
}

WhixyParser::DivisionAssignOpContext::DivisionAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::DivisionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitDivisionAssignOp(this);
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
//----------------- RightRotationAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightRotationAssignOpContext::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL, 0);
}

WhixyParser::RightRotationAssignOpContext::RightRotationAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightRotationAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightRotationAssignOp(this);
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
//----------------- RightShiftAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::RightShiftAssignOpContext::GREATERTHAN_GREATERTHAN_EQUAL()
{
    return getToken(WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL, 0);
}

WhixyParser::RightShiftAssignOpContext::RightShiftAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::RightShiftAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitRightShiftAssignOp(this);
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
//----------------- AndAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AndAssignOpContext::AMPERSAND_EQUAL()
{
    return getToken(WhixyParser::AMPERSAND_EQUAL, 0);
}

WhixyParser::AndAssignOpContext::AndAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AndAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAndAssignOp(this);
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
//----------------- XorAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::XorAssignOpContext::CARROT_EQUAL() { return getToken(WhixyParser::CARROT_EQUAL, 0); }

WhixyParser::XorAssignOpContext::XorAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::XorAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitXorAssignOp(this);
    else
        return visitor->visitChildren(this);
}
//----------------- AdditionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::AdditionAssignOpContext::PLUS_EQUAL() { return getToken(WhixyParser::PLUS_EQUAL, 0); }

WhixyParser::AdditionAssignOpContext::AdditionAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::AdditionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitAdditionAssignOp(this);
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
//----------------- WrappingAdditionAssignOpContext ------------------------------------------------------------------

tree::TerminalNode* WhixyParser::WrappingAdditionAssignOpContext::PLUS_PERCENT_EQUAL()
{
    return getToken(WhixyParser::PLUS_PERCENT_EQUAL, 0);
}

WhixyParser::WrappingAdditionAssignOpContext::WrappingAdditionAssignOpContext(BinaryOpContext* ctx) { copyFrom(ctx); }

std::any WhixyParser::WrappingAdditionAssignOpContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitWrappingAdditionAssignOp(this);
    else
        return visitor->visitChildren(this);
}
WhixyParser::BinaryOpContext* WhixyParser::binaryOp()
{
    BinaryOpContext* _localctx = _tracker.createInstance<BinaryOpContext>(_ctx, getState());
    enterRule(_localctx, 52, WhixyParser::RuleBinaryOp);

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
        setState(368);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::AS: {
            _localctx = _tracker.createInstance<WhixyParser::AsOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(329);
            match(WhixyParser::AS);
            break;
        }

        case WhixyParser::PLUS_PLUS: {
            _localctx = _tracker.createInstance<WhixyParser::ConcatenationOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(330);
            match(WhixyParser::PLUS_PLUS);
            break;
        }

        case WhixyParser::ASTERISK_ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::RepetitionOpContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(331);
            match(WhixyParser::ASTERISK_ASTERISK);
            break;
        }

        case WhixyParser::PLUS: {
            _localctx = _tracker.createInstance<WhixyParser::AdditionOpContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(332);
            match(WhixyParser::PLUS);
            break;
        }

        case WhixyParser::MINUS: {
            _localctx = _tracker.createInstance<WhixyParser::SubtractionOpContext>(_localctx);
            enterOuterAlt(_localctx, 5);
            setState(333);
            match(WhixyParser::MINUS);
            break;
        }

        case WhixyParser::ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::MultiplicationOpContext>(_localctx);
            enterOuterAlt(_localctx, 6);
            setState(334);
            match(WhixyParser::ASTERISK);
            break;
        }

        case WhixyParser::SLASH: {
            _localctx = _tracker.createInstance<WhixyParser::DivisionOpContext>(_localctx);
            enterOuterAlt(_localctx, 7);
            setState(335);
            match(WhixyParser::SLASH);
            break;
        }

        case WhixyParser::LESSTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::LessThanOpContext>(_localctx);
            enterOuterAlt(_localctx, 8);
            setState(336);
            match(WhixyParser::LESSTHAN);
            break;
        }

        case WhixyParser::GREATERTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::GreaterThanOpContext>(_localctx);
            enterOuterAlt(_localctx, 9);
            setState(337);
            match(WhixyParser::GREATERTHAN);
            break;
        }

        case WhixyParser::LESSTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LessThanEqualOpContext>(_localctx);
            enterOuterAlt(_localctx, 10);
            setState(338);
            match(WhixyParser::LESSTHAN_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::GreaterThanEqualOpContext>(_localctx);
            enterOuterAlt(_localctx, 11);
            setState(339);
            match(WhixyParser::GREATERTHAN_EQUAL);
            break;
        }

        case WhixyParser::PLUS_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingAdditionOpContext>(_localctx);
            enterOuterAlt(_localctx, 12);
            setState(340);
            match(WhixyParser::PLUS_PERCENT);
            break;
        }

        case WhixyParser::MINUS_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingSubtractionOpContext>(_localctx);
            enterOuterAlt(_localctx, 13);
            setState(341);
            match(WhixyParser::MINUS_PERCENT);
            break;
        }

        case WhixyParser::ASTERISK_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingMultiplicationOpContext>(_localctx);
            enterOuterAlt(_localctx, 14);
            setState(342);
            match(WhixyParser::ASTERISK_PERCENT);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::LeftShiftOpContext>(_localctx);
            enterOuterAlt(_localctx, 15);
            setState(343);
            match(WhixyParser::LESSTHAN_LESSTHAN);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN: {
            _localctx = _tracker.createInstance<WhixyParser::RightShiftOpContext>(_localctx);
            enterOuterAlt(_localctx, 16);
            setState(344);
            match(WhixyParser::GREATERTHAN_GREATERTHAN);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::LeftRotationOpContext>(_localctx);
            enterOuterAlt(_localctx, 17);
            setState(345);
            match(WhixyParser::LESSTHAN_LESSTHAN_PERCENT);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::RightRotationOpContext>(_localctx);
            enterOuterAlt(_localctx, 18);
            setState(346);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT);
            break;
        }

        case WhixyParser::EQUAL_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::EqualityOpContext>(_localctx);
            enterOuterAlt(_localctx, 19);
            setState(347);
            match(WhixyParser::EQUAL_EQUAL);
            break;
        }

        case WhixyParser::EXCLAMATION_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::InequalityOpContext>(_localctx);
            enterOuterAlt(_localctx, 20);
            setState(348);
            match(WhixyParser::EXCLAMATION_EQUAL);
            break;
        }

        case WhixyParser::AMPERSAND: {
            _localctx = _tracker.createInstance<WhixyParser::AndOpContext>(_localctx);
            enterOuterAlt(_localctx, 21);
            setState(349);
            match(WhixyParser::AMPERSAND);
            break;
        }

        case WhixyParser::AMPERSAND_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::AndAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 22);
            setState(350);
            match(WhixyParser::AMPERSAND_EQUAL);
            break;
        }

        case WhixyParser::PIPE: {
            _localctx = _tracker.createInstance<WhixyParser::OrOpContext>(_localctx);
            enterOuterAlt(_localctx, 23);
            setState(351);
            match(WhixyParser::PIPE);
            break;
        }

        case WhixyParser::PIPE_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::OrAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 24);
            setState(352);
            match(WhixyParser::PIPE_EQUAL);
            break;
        }

        case WhixyParser::PERCENT: {
            _localctx = _tracker.createInstance<WhixyParser::ModulusOpContext>(_localctx);
            enterOuterAlt(_localctx, 25);
            setState(353);
            match(WhixyParser::PERCENT);
            break;
        }

        case WhixyParser::PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::ModulusAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 26);
            setState(354);
            match(WhixyParser::PERCENT_EQUAL);
            break;
        }

        case WhixyParser::CARROT: {
            _localctx = _tracker.createInstance<WhixyParser::XorOpContext>(_localctx);
            enterOuterAlt(_localctx, 27);
            setState(355);
            match(WhixyParser::CARROT);
            break;
        }

        case WhixyParser::CARROT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::XorAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 28);
            setState(356);
            match(WhixyParser::CARROT_EQUAL);
            break;
        }

        case WhixyParser::SLASH_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::DivisionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 29);
            setState(357);
            match(WhixyParser::SLASH_EQUAL);
            break;
        }

        case WhixyParser::PLUS_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::AdditionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 30);
            setState(358);
            match(WhixyParser::PLUS_EQUAL);
            break;
        }

        case WhixyParser::MINUS_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::SubtractionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 31);
            setState(359);
            match(WhixyParser::MINUS_EQUAL);
            break;
        }

        case WhixyParser::ASTERISK_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::MultiplicationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 32);
            setState(360);
            match(WhixyParser::ASTERISK_EQUAL);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LeftShiftAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 33);
            setState(361);
            match(WhixyParser::LESSTHAN_LESSTHAN_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::RightShiftAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 34);
            setState(362);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_EQUAL);
            break;
        }

        case WhixyParser::ASTERISK_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingMultiplicationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 35);
            setState(363);
            match(WhixyParser::ASTERISK_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::PLUS_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingAdditionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 36);
            setState(364);
            match(WhixyParser::PLUS_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::MINUS_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::WrappingSubtractionAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 37);
            setState(365);
            match(WhixyParser::MINUS_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::RightRotationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 38);
            setState(366);
            match(WhixyParser::GREATERTHAN_GREATERTHAN_PERCENT_EQUAL);
            break;
        }

        case WhixyParser::LESSTHAN_LESSTHAN_PERCENT_EQUAL: {
            _localctx = _tracker.createInstance<WhixyParser::LeftRotationAssignOpContext>(_localctx);
            enterOuterAlt(_localctx, 39);
            setState(367);
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
    enterRule(_localctx, 54, WhixyParser::RuleComptExpr);

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
        setState(370);
        match(WhixyParser::COMPT);
        setState(371);
        expr();

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
    enterRule(_localctx, 56, WhixyParser::RulePreOpExpr);

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
        setState(373);
        preOp();
        setState(374);
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
    enterRule(_localctx, 58, WhixyParser::RulePreOp);

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
        setState(378);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::EXCLAMATION: {
            _localctx = _tracker.createInstance<WhixyParser::NotOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(376);
            match(WhixyParser::EXCLAMATION);
            break;
        }

        case WhixyParser::MINUS: {
            _localctx = _tracker.createInstance<WhixyParser::NegateOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(377);
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
    enterRule(_localctx, 60, WhixyParser::RulePostOpExpr);

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
        setState(380);
        atom();
        setState(381);
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
    enterRule(_localctx, 62, WhixyParser::RulePostOp);

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
        setState(388);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::DOT_TYPE: {
            _localctx = _tracker.createInstance<WhixyParser::AccessTypeOpContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(383);
            match(WhixyParser::DOT_TYPE);
            break;
        }

        case WhixyParser::DOT_LEN: {
            _localctx = _tracker.createInstance<WhixyParser::AccessLengthOpContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(384);
            match(WhixyParser::DOT_LEN);
            break;
        }

        case WhixyParser::DOT_ASTERISK: {
            _localctx = _tracker.createInstance<WhixyParser::DereferencePointerOpContext>(_localctx);
            enterOuterAlt(_localctx, 3);
            setState(385);
            match(WhixyParser::DOT_ASTERISK);
            break;
        }

        case WhixyParser::DOT_AMPERSAND: {
            _localctx = _tracker.createInstance<WhixyParser::AddressOfOpContext>(_localctx);
            enterOuterAlt(_localctx, 4);
            setState(386);
            match(WhixyParser::DOT_AMPERSAND);
            break;
        }

        case WhixyParser::DOT_QUESTION: {
            _localctx = _tracker.createInstance<WhixyParser::UnwrapOptionalOpContext>(_localctx);
            enterOuterAlt(_localctx, 5);
            setState(387);
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
    enterRule(_localctx, 64, WhixyParser::RuleString);

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
        setState(392);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
        case WhixyParser::DOUBLEQUOTESTRING: {
            _localctx = _tracker.createInstance<WhixyParser::DQStringExprContext>(_localctx);
            enterOuterAlt(_localctx, 1);
            setState(390);
            match(WhixyParser::DOUBLEQUOTESTRING);
            break;
        }

        case WhixyParser::BACKTICKSTRING: {
            _localctx = _tracker.createInstance<WhixyParser::BTStringExprContext>(_localctx);
            enterOuterAlt(_localctx, 2);
            setState(391);
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

WhixyParser::TokenContext* WhixyParser::AtomContext::token() { return getRuleContext<WhixyParser::TokenContext>(0); }

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
    enterRule(_localctx, 66, WhixyParser::RuleAtom);

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
        setState(398);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
        case 1: {
            enterOuterAlt(_localctx, 1);
            setState(394);
            blockExpr();
            break;
        }

        case 2: {
            enterOuterAlt(_localctx, 2);
            setState(395);
            typeExpr();
            break;
        }

        case 3: {
            enterOuterAlt(_localctx, 3);
            setState(396);
            tupleExpr();
            break;
        }

        case 4: {
            enterOuterAlt(_localctx, 4);
            setState(397);
            token();
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
    enterRule(_localctx, 68, WhixyParser::RuleBlockExpr);

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
        setState(400);
        oParen();
        setState(415);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
        case 1: {
            setState(412);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
            case 1: {
                setState(401);
                stmt();
                setState(407);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                    if (alt == 1) {
                        setState(402);
                        stmtSep();
                        setState(403);
                        stmt();
                    }
                    setState(409);
                    _errHandler->sync(this);
                    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
                }
                setState(410);
                stmtSep();
                break;
            }

            default: break;
            }
            setState(414);
            expr();
            break;
        }

        default: break;
        }
        setState(417);
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
    enterRule(_localctx, 70, WhixyParser::RuleTypeExpr);
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
        setState(419);
        oBrace();
        setState(429);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::TOKEN) {
            setState(420);
            valsStmt();
            setState(426);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                    setState(421);
                    exprSep();
                    setState(422);
                    valsStmt();
                }
                setState(428);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
            }
        }
        setState(431);
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
    enterRule(_localctx, 72, WhixyParser::RuleTupleExpr);

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
        setState(433);
        oParen();
        setState(443);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
            setState(434);
            expr();
            setState(440);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
            while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                    setState(435);
                    exprSep();
                    setState(436);
                    expr();
                }
                setState(442);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx);
            }
            break;
        }

        default: break;
        }
        setState(445);
        cParen();

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
    enterRule(_localctx, 74, WhixyParser::RuleToken);

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
        setState(447);
        match(WhixyParser::TOKEN);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- EofContext ------------------------------------------------------------------

WhixyParser::EofContext::EofContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::EofContext::EOF() { return getToken(WhixyParser::EOF, 0); }

tree::TerminalNode* WhixyParser::EofContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::EofContext::getRuleIndex() const { return WhixyParser::RuleEof; }

std::any WhixyParser::EofContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitEof(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::EofContext* WhixyParser::eof()
{
    EofContext* _localctx = _tracker.createInstance<EofContext>(_ctx, getState());
    enterRule(_localctx, 76, WhixyParser::RuleEof);
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
        setState(450);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(449);
            match(WhixyParser::NEWLINE);
        }
        setState(452);
        match(WhixyParser::EOF);

    } catch (RecognitionException& e) {
        _errHandler->reportError(this, e);
        _localctx->exception = std::current_exception();
        _errHandler->recover(this, _localctx->exception);
    }

    return _localctx;
}

//----------------- EqualContext ------------------------------------------------------------------

WhixyParser::EqualContext::EqualContext(ParserRuleContext* parent, size_t invokingState)
    : ParserRuleContext(parent, invokingState)
{}

tree::TerminalNode* WhixyParser::EqualContext::EQUAL() { return getToken(WhixyParser::EQUAL, 0); }

tree::TerminalNode* WhixyParser::EqualContext::NEWLINE() { return getToken(WhixyParser::NEWLINE, 0); }

size_t WhixyParser::EqualContext::getRuleIndex() const { return WhixyParser::RuleEqual; }

std::any WhixyParser::EqualContext::accept(tree::ParseTreeVisitor* visitor)
{
    if (auto parserVisitor = dynamic_cast<WhixyParserVisitor*>(visitor))
        return parserVisitor->visitEqual(this);
    else
        return visitor->visitChildren(this);
}

WhixyParser::EqualContext* WhixyParser::equal()
{
    EqualContext* _localctx = _tracker.createInstance<EqualContext>(_ctx, getState());
    enterRule(_localctx, 78, WhixyParser::RuleEqual);
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
        setState(454);
        match(WhixyParser::EQUAL);
        setState(456);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(455);
            match(WhixyParser::NEWLINE);
        }

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
    enterRule(_localctx, 80, WhixyParser::RuleOBracket);
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
        setState(458);
        match(WhixyParser::OPENBRACKET);
        setState(460);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(459);
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
    enterRule(_localctx, 82, WhixyParser::RuleCBracket);
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
        setState(463);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(462);
            match(WhixyParser::NEWLINE);
        }
        setState(465);
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
    enterRule(_localctx, 84, WhixyParser::RuleOAngleBracket);
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
        setState(467);
        match(WhixyParser::LESSTHAN_OPENBRACKET);
        setState(469);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(468);
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
    enterRule(_localctx, 86, WhixyParser::RuleCAngleBracket);
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
        setState(472);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(471);
            match(WhixyParser::NEWLINE);
        }
        setState(474);
        match(WhixyParser::CLOSEDBRACKET_GREATERTHAN);

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
    enterRule(_localctx, 88, WhixyParser::RuleOParen);
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
        setState(477);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(476);
            match(WhixyParser::NEWLINE);
        }
        setState(479);
        match(WhixyParser::OPENPARENTHESIS);
        setState(481);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
        case 1: {
            setState(480);
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

std::vector<tree::TerminalNode*> WhixyParser::CParenContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::CParenContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

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
    enterRule(_localctx, 90, WhixyParser::RuleCParen);
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
        setState(484);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(483);
            match(WhixyParser::NEWLINE);
        }
        setState(486);
        match(WhixyParser::CLOSEDPARENTHESIS);
        setState(488);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
        case 1: {
            setState(487);
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
    enterRule(_localctx, 92, WhixyParser::RuleOBrace);
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
        setState(491);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(490);
            match(WhixyParser::NEWLINE);
        }
        setState(493);
        match(WhixyParser::OPENBRACE);
        setState(495);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
        case 1: {
            setState(494);
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

std::vector<tree::TerminalNode*> WhixyParser::CBraceContext::NEWLINE() { return getTokens(WhixyParser::NEWLINE); }

tree::TerminalNode* WhixyParser::CBraceContext::NEWLINE(size_t i) { return getToken(WhixyParser::NEWLINE, i); }

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
    enterRule(_localctx, 94, WhixyParser::RuleCBrace);
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
        setState(498);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == WhixyParser::NEWLINE) {
            setState(497);
            match(WhixyParser::NEWLINE);
        }
        setState(500);
        match(WhixyParser::CLOSEDBRACE);
        setState(502);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
        case 1: {
            setState(501);
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
    enterRule(_localctx, 96, WhixyParser::RuleStmtSep);
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
        setState(504);
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
    enterRule(_localctx, 98, WhixyParser::RuleExprSep);
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
        setState(506);
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
