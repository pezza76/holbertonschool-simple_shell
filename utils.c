#include "shell.h"

void display_prompt(void)
{
    write(STDOUT_FILENO, "($) ", 4);
}

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

char *strip_newline(char *line)
{
    size_t len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}