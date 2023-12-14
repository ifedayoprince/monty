#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * main - entry point for program.
 * @argc: number of arguments passed.
 * @argv: array of arguments passed to program.
 *
 * Return: an exit value.
*/
int main(int argc, char **argv)
{
	FILE *file;

	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	read_file_and_execute(file);

	fclose(file);
	return (0);
}
