#include "main.h"

void builtin_exit_shell(char **args_from_input)
{
free_dynamic_memory(args_from_input);
exit(EXIT_SUCCESS);
}
