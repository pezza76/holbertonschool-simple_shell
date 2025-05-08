#include "shell.h"

/**
 * tokenize_line - Splits a line into tokens (arguments)
 * @line: Line to split
 * Return: Pointer to array of tokens
 */
char **tokenize_line(char *line)
{
	char *token = NULL;
	char **tokens = NULL;
	int size = 64, i = 0;

	tokens = malloc(sizeof(char *) * size);
	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n");
	while (token != NULL)
	{
		tokens[i++] = strdup(token);
		if (i >= size)
		{
			size += 64;
			tokens = realloc(tokens, sizeof(char *) * size);
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
