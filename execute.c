#include "shell.h"

int execute_command(char **args)
{
	pid_t pid;
	char *command_path = NULL;
	int status = 0;
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
			return 127;
		}
	}
	pid = fork();
	if (pid == 0)
	{
		execve(command_path, args, environ);
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	if (command_path != args[0])
		free(command_path);

	return status;
}
