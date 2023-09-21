#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define PRINTF_BUFFER_SIZE 1024
#define MAX_ARGS 64

#ifndef MAIN_H
#define MAIN_H
extern char **environ;
char *custom_getline(void);
void execute_command(char *command, char *args[]);
void process_input(void);
void process_command(char *command, size_t len);
void print_environment(void);
char *generate_prompt(char *cwd, char *home_dir);
void handle_cd_command(char *command);
void handle_cd_with_path(char *path);
bool is_executable_in_path(const char *file);
char *get_full_executable_path(const char *command);

int _printf(const char *format, ...);
void printChar(char c, int *count);
void print_number(int n, int *count);
void flush_buffer(char *buffer, int *count);
void printBinary(unsigned int n, int *count);
void printPointer(void *ptr, char *buffer, int *count);
void printHexadecimal(unsigned int num, char *buffer, int *count, int uppercase);
void print_unsigned(unsigned int n, int *count);
void printOctal(unsigned int num, char *buffer, int *count);
void printStr(const char *str, int *count);
#endif
