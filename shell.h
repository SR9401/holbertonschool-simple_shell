#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;
char **split_string(char *str, const char *delim);
char *_getenv(const char *name);
void execute_command(char **argv, const char *full_path);
char **get_path(const char *cmd, char **argv, char *name);
void arg(char *line, char **argv);
int free_token(char **token);

#endif