#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void show_input_prompt();
char *read_input_command();
char **parse_user_input(char *input, int *arg_count);
char *find_command_in_path(char *command);
void execute_command(char **args_from_input);
int count_command_arguments(char **args_from_input);
void handle_errors();
void free_dynamic_memory(char **args_from_input);
void builtin_exit_shell();
void launch_shell_program();
void get_builtin_env();

#endif
