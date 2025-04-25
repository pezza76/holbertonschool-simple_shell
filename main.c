#include "shell.h"

int main(void)
{
    char *line, *clean_line;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            display_prompt();

        line = read_line();

        if (!line)
        {
            if (isatty(STDIN_FILENO) write(STDOUT_FILENO, "\n", 1);)
                break;
        }

        clean_line = strip_newline(line);
        if (*clean_line != '\0')
        {
            execute_command(clean_line);
        }

        free(line);
    }
    return (0);
}