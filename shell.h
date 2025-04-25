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
int execute_command(char *command);

// Function prototypes

#endif /* SHELL_H */