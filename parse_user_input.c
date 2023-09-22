#include "main.h"

char **parse_user_input(char *input_string, int *arg_count)
{
	const char *delimiters;
	char **args_from_input = NULL;
	char *token = NULL;
	int arg_capacity = 16;
	*arg_count = 0;
	delimiters = " \t\r\n\a";
	args_from_input = (char **)malloc(sizeof(char *) * arg_capacity);
	if (!args_from_input)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	token = strtok(input_string, delimiters);
	while (token != NULL)
	{
		args_from_input[*arg_count] = strdup(token);
		if (!args_from_input[*arg_count])
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		(*arg_count)++;
		if (*arg_count >= arg_capacity)
		{arg_capacity *= 2;
			args_from_input = (char **)realloc(args_from_input, sizeof(char *) * arg_capacity);
			if (!args_from_input)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delimiters);
	}
	args_from_input[*arg_count] = NULL;
	return args_from_input;
}
