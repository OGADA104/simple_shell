#include "main.h"

char *read_input_command()
{
	char *input_string = NULL;
	size_t buffer_size = 0;
	
	ssize_t getline_status = getline(&input_string, &buffer_size, stdin);
	if (getline_status == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			free(input_string);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			free(input_string);
			exit(EXIT_FAILURE);
		}
	}
	if (input_string[strlen(input_string) - 1] == '\n')
	{
		input_string[strlen(input_string) - 1] = '\0';
	}
	return input_string;
}
