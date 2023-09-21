#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shellmain.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the simple shell program
 *
 * Return: 0 on success
 */
int main(void)
{
        process_input();
        return (0);
}
