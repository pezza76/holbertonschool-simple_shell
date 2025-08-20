#include "shell.h"
#include <sys/stat.h>

/**
 * search_in_dirs - Searches for a command in a list of directories.
 * @dir: The first directory from the tokenized PATH.
 * @command: The command to search for.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
static char *search_in_dirs(char *dir, char *command)
{
	char *full_path;
	struct stat st;

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (!full_path)
			return (NULL);

		sprintf(full_path, "%s/%s", dir, command);

		/* Check if the file exists and is executable */
		if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
			return (full_path);

		free(full_path);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * find_command_in_path - Searches for a command in the system PATH.
 * @command: Command name to search for.
 *
 * Return: Full path string if found and executable, NULL otherwise.
 */
char *find_command_in_path(char *command)
{
	char *path, *path_copy, *dir, *full_path = NULL;

	/* Use getenv for a safer and simpler way to get PATH */
	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	full_path = search_in_dirs(dir, command);

	free(path_copy);
	return (full_path);
}
