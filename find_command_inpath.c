#include "main.h"
char *path_copy;
char *token;

char *find_command_in_path(char *command)
{
char *path = getenv("PATH");

if (path == NULL)
{
return NULL;
}

path_copy = strdup(path);
if (path_copy == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
token = strtok(path_copy, ":");
while (token != NULL)
{
char *full_path = (char *)malloc(strlen(token) + strlen(command) + 2);
if (full_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
sprintf(full_path, "%s/%s", token, command);
if (access(full_path, X_OK) == 0)
{
free(path_copy);
return full_path;
}
free(full_path);
token = strtok(NULL, ":");
}
free(path_copy);
return NULL;
}
