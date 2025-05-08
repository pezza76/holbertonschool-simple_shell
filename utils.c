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
		F
			line[len - 1] = '\0';
	return (line);
}

void free_tokens(char **tokens)
{
	int i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}

int handle_builtins(char **args, char *line)
{
	int i;

	if (strcmp(args[0], "exit") == 0)
	{
		free_tokens(args);
		free(line);
		exit(0);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		free_tokens(args);
		return (1);
	}

	return (0);
}
