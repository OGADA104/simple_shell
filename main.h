#include <stddef.h>

#ifndef MAIN_H
#define MAIN_H
extern char **environ;
char *custom_getline(void);
void execute_command(char *command);
void process_input(void);
void process_command(char *command,size_t len);
void print_environment(void);
char *generate_prompt(char *cwd, char *home_dir);
void handle_cd_command(char *command);
void handle_cd_with_path(char *path);
int is_builtin( const char *command);
#endif
