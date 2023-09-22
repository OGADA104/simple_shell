#include "main.h"

void launch_shell_program()
{
	char *input_string;
	char **args_from_input;
	int arg_count;
	
	while (1)
	{
		show_input_prompt();
		input_string = read_input_command();
		args_from_input = parse_user_input(input_string, &arg_count);
		
		if (arg_count > 0)
		{
			execute_command(args_from_input);
		}

		free_dynamic_memory(args_from_input);
		free(input_string);
	}
}
