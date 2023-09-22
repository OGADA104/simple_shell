#include "main.h"

void execute_command(char **args_from_input) {

pid_t child_pid;
int status;

if (strcmp(args_from_input[0], "exit") == 0) {
free_dynamic_memory(args_from_input);
exit(EXIT_SUCCESS);
}

if (strcmp(args_from_input[0], "env") == 0) {
get_builtin_env();
return;
}

if (args_from_input[0][0] == '/') {
child_pid = fork();

if (child_pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
}

if (child_pid == 0) {
if (execve(args_from_input[0], args_from_input, NULL) == -1) {
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);

/*if (WIFEXITED(status))
{
printf("Child exited with status %d\n", WEXITSTATUS(status));
}*/
}
}
else
{
char *command_path = find_command_in_path(args_from_input[0]);

if (command_path != NULL) {

child_pid = fork();

if (child_pid == -1) {
perror("fork");
exit(EXIT_FAILURE);
}

if (child_pid == 0) {

if (execve(command_path, args_from_input, NULL) == -1) {
perror("execve");
exit(EXIT_FAILURE);
}
} else {

wait(&status);

/*
if (WIFEXITED(status)) {
// Print the exit status of the child process
printf("Child exited with status %d\n", WEXITSTATUS(status));
}*/

}
free(command_path);
} else
{
fprintf(stderr, "Command not found: %s\n", args_from_input[0]);
}
}
}
