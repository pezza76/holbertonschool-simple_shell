#include "shell.h"

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
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		if (!isatty(STDIN_FILENO))
		{
			exit(last_status);
		}
		break;
	}

	clean_line = strip_newline(line);

	if (*clean_line != '\0')
	{
		args = tokenize_line(clean_line);

		if (args != NULL)
		{
		if (strcmp(args[0], "exit") == 0)
		{
			free_tokens(args);
			free(line);
			exit(last_status);
		}

		if (strcmp(args[0], "env") == 0)
		{
			int i = 0;
			while (environ[i])
			{
				write(STDOUT_FILENO, environ[i], strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}

			free_tokens(args);
			continue;
		}

		last_status = execute_command(args);
		free_tokens(args);
		}
	}

	free(line);
	
	return last_status;
}
