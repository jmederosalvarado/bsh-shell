#ifndef LEFT_CMD_H
#define LEFT_CMD_H

#include <cmds/cmd.h>

struct left_cmd
{
    struct cmd base;
    struct cmd *cmd;
    char *filename;
};

struct left_cmd *left_cmd_init();
void left_cmd_init_allocated(struct left_cmd *c);

struct cmd *left_cmd_get_cmd(struct left_cmd *c);
void left_cmd_set_cmd(struct left_cmd *c, struct cmd *cmd);

char *left_cmd_get_filename(struct left_cmd *c);
void left_cmd_set_filename(struct left_cmd *c, char *filename);

int left_cmd_run(struct cmd *c);

#endif