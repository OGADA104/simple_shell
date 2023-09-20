#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include "main.h"

/**
 * process_input - Process user input.
 *
 * This function reads user input, processes it
 * and executes the corresponding actions.
 */
void process_input(void)
{
	char *buffer;
	char *cwd = getcwd(NULL, 0);
	char *prompt;

	while (1)
	{
		cwd = getcwd(NULL, 0);
		prompt = malloc(strlen(cwd) + 4);
		strcpy(prompt, cwd);
		strcat(prompt, " $ ");
		write(STDOUT_FILENO, prompt, strlen(prompt));
		buffer = custom_getline();
		if (buffer == NULL || *buffer == '\0')
		{
			printf("\n");
			break;
		}
		process_command(buffer);
		free(buffer);
		free(prompt);
	}
	free(cwd);
}

/**
 * process_command - Process a single user command.
 * @command: The user command to process.
 *
 * This function takes a single user command and performs the
 * corresponding action, such as executing a command or changing
 * the directory.
 */
void process_command(char *command)
{
	size_t len = strlen(command);

	if (len > 0 && command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
	}
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "env") == 0)
	{
		print_environment();
	}
	else if (strncmp(command, "cd", 2) == 0)
	{
		handle_cd_command(command);
	}
	else
	{
		execute_command(command);
	}
}

/**
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}

/**
 * generate_prompt - Generate the shell prompt.
 * @cwd: The current working directory.
 * @home_dir: The user's home directory.
 *Return: dynamically allocated prompt string
 * This function generates the shell prompt string that includes
 * the current working directory (cwd) and the home directory.
 * It returns the dynamically allocated prompt string.
 */

char *generate_prompt(char *cwd, char *home_dir)
{
	char *prompt;
	char *relative_cwd;

	if (strcmp(cwd, home_dir) == 0)
	{
		prompt = strdup("~$ ");
	}
	else
	{
		relative_cwd = strstr(cwd, home_dir);
		if (relative_cwd != NULL)
		{
			prompt = malloc(strlen(relative_cwd) + 3);
			sprintf(prompt, "~%s$ ", relative_cwd + strlen(home_dir));
		}
		else
		{
			prompt = malloc(strlen(cwd) + 3);
			sprintf(prompt, "%s$ ", cwd);
		}
	}
	return (prompt);
}
