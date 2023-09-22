#include "main.h"

void free_dynamic_memory(char **args_from_input)
{
int i;

for (i = 0; args_from_input[i] != NULL; i++)
{
free(args_from_input[i]);
}
free(args_from_input);
}
