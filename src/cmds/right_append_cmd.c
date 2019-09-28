#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <cmds/cmd.h>
#include <cmds/right_append_cmd.h>
#include <utils/vector.h>
#include <utils/xmemory.h>

struct right_append_cmd *right_append_cmd_init(char *filename)
{
    struct right_append_cmd *right_append_cmd = xmalloc(sizeof(struct right_append_cmd));
    right_append_cmd_init_allocated(right_append_cmd, filename);
    return right_append_cmd;
}

void right_append_cmd_init_allocated(struct right_append_cmd *c, char *filename)
{
    cmd_init_allocated(&c->base, CMD_T_RIGHT_APPEND_CMD, right_append_cmd_run, right_append_cmd_print);
    c->filename = filename;
}

bool right_append_cmd_run(struct cmd *c)
{
    return true;
}

void right_append_cmd_print(struct cmd *c)
{
    struct right_append_cmd *right_append = (struct right_append_cmd *)c;

    printf(">> ");

    if (!right_append->filename)
        printf("<error>");
    else
        printf("%s", right_append->filename);
}
