#include "main.h"

void get_builtin_env()
{
int i;

extern char **environ;

for (i = 0; environ[i] != NULL; i++)
{
printf("%s\n", environ[i]);
}
}
