#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <unistd.h>
#include "shellmain.h"
#include <string.h>

#define MAX_PATH_LENGTH 4096

/**
 * execute_command - Execute a shell command.
 *
 * @command: The command to execute.
 * @args: Array of command-line arguments, including the command itself.
 */
void execute_command(char *command, char *args[])
{
    pid_t pid;
    char *full_path = NULL;

    if (is_executable_in_path(command))
    {
        full_path = get_full_executable_path(command);
        if (full_path == NULL)
        {
            fprintf(stderr, "Failed to get the full path for: %s\n", command);
            return;
        }

        pid = fork();

        if (pid == 0)
        {
            execve(full_path, args, NULL);
            perror("execve");
            free(full_path);
            exit(1);
        }
        else if (pid > 0)
        {
            int status;
            waitpid(pid, &status, 0);
        }
        else
        {
            perror("fork");
        }
        free(full_path);
    }
    else
    {
        fprintf(stderr, "Command not found: %s\n", command);
    }
}
    

char *get_full_executable_path(const char *command) {
    char *path = getenv("PATH");
    char *path_copy;
    char *dir;
    char *full_path;

    if (path == NULL) {
        return NULL;
    }

    path_copy = strdup(path);
    if (path_copy == NULL) {
        perror("strdup");
        return NULL;
    }

    dir = strtok(path_copy, ":");
    while (dir != NULL) {
        size_t full_path_len = strlen(dir) + strlen(command) + 2;
        full_path = (char *)malloc(full_path_len);
        if (full_path == NULL) {
            perror("malloc");
            free(path_copy);
            return NULL;
        }

        snprintf(full_path, full_path_len, "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }
        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

