#include "shell.h"
#include <sys/stat.h>

/**
 * find_command_in_path - Searches for a command in the system PATH
 * @command: Command to search for
 * Return: Full path to the command if found, otherwise NULL
 */
char *find_command_in_path(char *command)
{
    char *path = getenv("PATH");
    char *path_copy, *dir, *full_path;
    struct stat st;

    if (!path)
        return (NULL);

    path_copy = strdup(path);
    if (!path_copy)
        return (NULL);

    dir = strtok(path_copy, ":");
    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path)
        {
            free(path_copy);
            return (NULL);
        }

        sprintf(full_path, "%s/%s", dir, command);

        if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return (full_path);
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}
