#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shellmain.h"
/**
 * handle_cd_command - Handle 'cd' command.
 *
 * @command: The 'cd' command and optional path.
 *
 * This function handles changing the current directory
 * based on the 'cd' command.
 * If no path is provided, it changes to the home directory.
 *
 * Example usage:
 *   handle_cd_command("cd /path/to/directory");
 *   handle_cd_command("cd"); // Change to the home directory
 */
void handle_cd_command(char *command)
{
	char *path = command + 2;

	while (*path == ' ')
	{
		path++;
	}
	if (*path == '\0')
	{
		char *home_dir = getenv("HOME");

		if (home_dir)
		{
			chdir(home_dir);
		}
	}
	else
	{
		handle_cd_with_path(path);
	}
}
