#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * handle_cd_with_path - Change the current directory to the specified path.
 *
 * @path: The path to change to.
 *
 * This function changes the current working directory to the specified path.
 *
 * Example usage:
 *   handle_cd_with_path("/path/to/directory");
 */

void handle_cd_with_path(char *path)
{
	if (chdir(path) != 0)
	{
		perror("cd failed");
	}
}
