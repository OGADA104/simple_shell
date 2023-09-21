#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include "shellmain.h"

/**
 * process_input - Process user input.
 *
 * This function reads user input, processes it
 * and executes the corresponding actions.
 */
void process_input(void)
{
	char *buffer = NULL;
	char dollar_sign[] = " $ ";
        ssize_t No_of_chars_in_buffer;
	size_t initial_bufsize = 0;
	char *current_directory;
	char *full_prompt;

	while (1)
	{

		current_directory = getcwd(NULL, 0);
		full_prompt = malloc(strlen(current_directory) + 4);
		strcpy(full_prompt, current_directory);
		strcat(full_prompt, dollar_sign);
		write(STDOUT_FILENO, full_prompt, strlen(full_prompt));

		No_of_chars_in_buffer = getline(&buffer, &initial_bufsize, stdin);
		if (buffer == NULL)
		{
			printf("Memory allocation failed\n");
			break;
		}
		process_command(buffer, No_of_chars_in_buffer);
		free(buffer);
		free(full_prompt);
	}
	free(current_directory);
}

/**
 * process_command - Process a single user command.
 * @command: The user command to process.
 * @len: Length of the command.
 *
 * This function takes a single user command and performs the
 * corresponding action, such as executing a command or changing
 * the directory.
 */
void process_command(char *command, size_t len)
{
    char *token;
    char *args[MAX_ARGS];
    int arg_count = 0;

    if (len > 0 && command[len - 1] == '\n')
    {
        command[len - 1] = '\0';
    }

    token = strtok(command, " ");

    if (token == NULL)
    {
        return;
    }

    args[arg_count++] = token;

    while ((token = strtok(NULL, " ")) != NULL && arg_count < MAX_ARGS - 1)
    {
        args[arg_count++] = token;
    }

    args[arg_count] = NULL;

    if (strcmp(args[0], "exit") == 0)
    {
        exit(0);
    }
    else if (strcmp(args[0], "env") == 0)
    {
        print_environment();
    }
    else if (strcmp(args[0], "cd") == 0)
    {
        handle_cd_command(args[1]);
    }
    else
    {
        execute_command(args[0], args);
    }
}


bool is_executable_in_path(const char *file) {
    char *path = getenv("PATH");
    char *path_copy;
    char *dir;
    char *path_buffer;

    if (path == NULL) {
        return false;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return false;
    }

    dir = strtok(path_copy, ":");
    while (dir != NULL) {
        size_t path_buffer_len = strlen(dir) + strlen(file) + 2;
        path_buffer = (char *)malloc(path_buffer_len);
        if (path_buffer == NULL) {
            perror("malloc");
            free(path_copy);
            return false;
        }
        
        snprintf(path_buffer, path_buffer_len, "%s/%s", dir, file);
        if (access(path_buffer, X_OK) == 0) {
            free(path_buffer);
            free(path_copy);
            return true;
        }
        free(path_buffer);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return false;
}




/**
 * print_environment - Print the current environment variables.
 */
void print_environment(void)
{
	char **env_varia = environ;

	while (*env_varia != NULL)
	{
		_printf("%s\n", *env_varia);
		env_varia++;
	}
}
