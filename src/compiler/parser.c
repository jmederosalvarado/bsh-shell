#include <stdlib.h>
#include <stdio.h>

#include <compiler/parser.h>
#include <cmds/path_cmd.h>
#include <utils/vector.h>
#include <utils/xmemory.h>
#include <compiler/token.h>

struct path_cmd *parser_parse_path_cmd(struct parser *p);

void parser_init(struct parser *p, struct vector *tokens)
{
    p->i = 0;
    p->tokens = tokens;
}

struct token *parser_lookahead(struct parser *p)
{
    return vector_get(p->tokens, p->i);
}

void parse_next(struct parser *p)
{
    p->i++;
}

struct cmd *parser_parse(struct parser *p)
{
    return (struct cmd *)parser_parse_path_cmd(p);
}

struct path_cmd *parser_parse_path_cmd(struct parser *p)
{
    struct path_cmd *path_cmd = xmalloc(sizeof(struct path_cmd));
    path_cmd_init(path_cmd);

    struct token *t = parser_lookahead(p);
    while (token_get_type(t) == TOKEN_T_STR)
    {
        path_cmd_add_arg(path_cmd, token_get_lex(t));

        parse_next(p);
        t = parser_lookahead(p);
    }

    return path_cmd;
}
