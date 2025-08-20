#include "shell.h"

/**
 * main - Entry point of the simple shell
 *
 * Return: Exit status of the last executed command
 */
int main(void)
{
	char *line, *clean_line;
	char **args = NULL;
	int last_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		line = read_line();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		clean_line = strip_newline(line);
		if (*clean_line != '\0')
		{
			args = tokenize_line(clean_line);
			/* The fix is on the next line */
			if (args && !handle_builtins(args, line, last_status))
			{
				last_status = execute_command(args);
				free_tokens(args);
			}
		}
		free(line);
	}
	return (last_status);
}
