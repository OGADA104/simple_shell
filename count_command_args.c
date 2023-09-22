#include "main.h"

int count_command_arguments(char **args_from_input) {
int count = 0;
while (args_from_input[count] != NULL) {
count++;
}
return count;
}
