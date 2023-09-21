#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "main.h"


/**
 * is_builtin - Check if a command is a built-in.
 *
 * @command: The command to check.
 *
 * Return: 1 if the command is a built-in, 0 otherwise.
 */

int is_builtin(const char *command)
{
	const char *builtins[] = {"exit", "env", "cd", NULL};
	int i;

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * execute_command - Execute a shell command.
 *
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	if (!is_builtin(command))
	{
		if (access(command, F_OK) == -1)
		{
			fprintf(stderr, "File does not exist: %s\n", command);
			return;
		}
	}
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
