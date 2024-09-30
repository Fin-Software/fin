lexer grammar WhixyLexer; // $antlr-format off

// TODO: Groups are to be reoardered internally to maximize lexing speed of std.

COMMENT: '#' ~[\r\n]* -> skip;
STRING: ('"' .*? '"') | ('`' .*? '`');

DEFER: 'defer'; ELSE: 'else'; ENUM: 'enum'; ERRDEFER: 'errdefer'; FOR: 'for'; FUNC: 'func'; IF:
'if'; IMPORT: 'import'; IS: 'is'; PROC: 'proc'; STD: 'std'; TEST: 'test'; UNION: 'union'; VAL:
'val'; WHILE: 'while'; ALIGN: 'align'; BREAK: 'break'; CATCH: 'catch'; COMPT: 'compt'; CONTINUE:
'continue'; INLINE: 'inline'; MUT: 'mut'; ORELSE: 'orelse'; RETURN: 'return'; THREADLOCAL:
'threadlocal'; TRY: 'try'; UNROLL: 'unroll'; VOLATILE: 'volatile';

ID: '_' | ([a-zA-Z] [a-zA-Z0-9_]*);
INTEGER: BASE10 | BASE16 | BASE8 | BASE64 | BASE32 | BASE85 | BASE91;
fragment BASE10: '10_'? [0-9]+;
fragment BASE16: (('0' [Xx]) | '16_') [0-9A-Fa-f]+;
fragment BASE8: (('0' [Xx]) | '08_') [0-7]+;
fragment BASE32: '32_' [A-Z2-7]+;
fragment BASE64: '64_' [A-Za-z0-9+/]+;
fragment BASE85: '85_' [!-u]+;
fragment BASE91: '91_' [!-~]+;
EXP_SEP: ','; STMT_SEP: ';';
OBRACE: '{' NL?; CBRACE: '}' NL?;
OPAREN: '(' NL?; CPAREN: ')' NL?;
COLON: ':' NL?; EQ: '=' NL?;
NL: [\r\n]+;

WS: [ \t]+ -> skip;
