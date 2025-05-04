#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

void display_prompt(void);
char *read_line(void);
char *strip_newline(char *line);
int execute_command(char **args);
char *find_command_in_path(char *command);
char **tokenize_line(char *line);
void free_tokens(char **tokens);

#endif
