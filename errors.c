#include "main.h"

/**
 * malloc_check - checks if malloc failed and throw an error.
 * @ptr: the newly allocated pointer.
 *
 * Return: void
*/
void malloc_check(void *ptr)
{
	if (ptr == NULL)
		malloc_error();
}

/**
 * malloc_error - print an error message and exit.
 * Return: void
*/
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * unknown_instruction - prints an unknown instruction
 *                 error and exit with EXIT_FAILURE
 * @line: the line where the error happened.
 * @opcode: the opcode that caused the error.
 *
 * Return: void
*/
void unknown_instruction(int line, opcode_t *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode->opcode);
	exit(EXIT_FAILURE);
}

/**
 * error_occured - exits the program.
 * @msg: the message to print before exit.
 * @line: the line that triggered the shutdown.
 *
 * Return: void
*/
void error_occured(char *msg, __attribute__((unused)) int line)
{
	fprintf(stderr, "L%d: %s\n", line, msg);
	exit(EXIT_FAILURE);
}
