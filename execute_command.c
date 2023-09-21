#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"
/**
 * execute_command - Execute a shell command.
 *
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char **args = malloc(sizeof(char *) * 4);

		if (args == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		args[0] = "/bin/sh";
		args[1] = "-c";
		args[2] = command;
		args[3] = NULL;
		execve(args[0], args, environ);
		perror("Execution failed");
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "Command failed: %s\n", command);
		}
	}
}
