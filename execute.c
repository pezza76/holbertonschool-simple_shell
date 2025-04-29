#include "shell.h"

int execute_command(char **args)
{
    pid_t pid = fork();
    int status;

    if (pid == 0)
    {
        char *argv[] = {command, NULL};
        execve(command, argv, environ);
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
   return status; 
}
