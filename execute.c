#include "shell.h"

/**
 * fork_and_execute - Creates a child process to execute a command.
 * @command_path: The full path to the command to execute.
 * @args: The array of arguments for the command.
 *
 * Return: The exit status of the command.
 */
static int fork_and_execute(char *command_path, char **args)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0)
	{
		execve(command_path, args, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));

	return (status);
}

/**
 * execute_command - Finds and executes a command.
 * @args: Array of command and arguments.
 *
 * Return: Exit status of the executed command.
 */
int execute_command(char **args)
{
	char *command_path = NULL;
	int status = 0;

	if (args == NULL || args[0] == NULL)
		return (0);

	/* Check if the command is a full path or find it in PATH */
	if (access(args[0], X_OK) == 0)
	{
		command_path = args[0];
	}
	else
	{
		command_path = find_command_in_path(args[0]);
		if (!command_path)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return (127);
		}
	}

	status = fork_and_execute(command_path, args);

	/* Free the path only if it was allocated by find_command_in_path */
	if (command_path != args[0])
		free(command_path);

	return (status);
}
