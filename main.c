#include "shell.h"

int main(void)
{
	char *line, *clean_line;
	char **args = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		line = read_line();

	if (!line)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		break;
	}

	clean_line = strip_newline(line);
	if (*clean_line != '\0')
	{
		args = tokenize_line(clean_line);
	if (args != NULL)
	{
		execute_command(args);
		free(args);
	}
	}

	free(line);
	}
	return (0);
}
