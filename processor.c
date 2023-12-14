#include "monty.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * read_file_and_execute - reads the file line by line
 *              and triggers their execution.
 * @fd: the file descriptor of the current Monty file.
 *
 * Return: 0 if success.
 */
int read_file_and_execute(FILE *fd)
{
	char text[1024];
	int line = 0;
	stack_t *stack;
	opcode_t *opcode_instruction = malloc(sizeof(opcode_t));

	malloc_check(opcode_instruction);

	stack = NULL;

	while (fgets(text, sizeof(text), fd) != NULL)
	{
		line++;
		if (!(
				strcmp(strtrim(text), "") &&
				strncmp(strtrim(text), "#", 1)))
			continue;

		parse_line(opcode_instruction, text);
		run_operation(&stack, opcode_instruction, line);
	}

	free(opcode_instruction);
	return (0);
}

/**
 * parse_line - extracts the opcode and oprand from a line.
 * @instruction: the current instructions buffer
 *            to write to.
 * @text: the current line to be parsed.
 *
 * Return. void
 */
void parse_line(opcode_t *instruction, char *text)
{
	int parts_found = 0, i;
	char *delim = " ";
	char *part = "";

	for (i = 0; parts_found != (MAX_INSTRUCTION_PARTS); i++)
	{
		part = strtok(i == 0 ? text : NULL, delim);
		if (part == delim || !part)
			continue;

		if (parts_found == 0)
		{
			part = strtrim(part);
			instruction->opcode = part;

			if (strcmp(part, (char *)"push"))
			{
				instruction->value = 0;
				break;
			}
		}
		else
			instruction->value = atoi(strtrim(part));
		parts_found++;
	}
}

/**
 * run_operation - executes and instruction.
 * @stack: the pointer to the currently initialized
 *         stack.
 * @operation: the operation to execute.
 * @line: the current line being executed.
 *
 * Return: void
 */
void run_operation(stack_t **stack, opcode_t *operation, int line)
{
	int i;
	instruction_t *operations = get_instructions();
	bool operation_success = false;

	if (!(strcmp(operation->opcode, "stack")))
	{
		GLOBAL_ENV.queue_mode = false;
		return;
	}
	else if (!strcmp(operation->opcode, "queue"))
	{
		GLOBAL_ENV.queue_mode = true;
		return;
	}

	for (i = 0; i < ALLOWED_INSTRUCTIONS; i++)
	{

		if (!strcmp((operations[i]).opcode, operation->opcode))
		{
			GLOBAL_ENV.operand = operation->value;
			(operations[i]).f(stack, line);
			operation_success = true;
		}
	}

	free(operations);

	if (operation_success == false)
		unknown_instruction(line, operation);
}

/**
 * get_instructions - gets the function that runs an opcode.
 *
 * Return: an array of instruction mapped to its function.
 */
instruction_t *get_instructions()
{
	int i;
	instruction_t *dynamic_instructions;
	static instruction_t instructions[ALLOWED_INSTRUCTIONS] = {
		{"pint", pint},
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotr", rotr},
		{"rotl", rotl},
	};

	dynamic_instructions = malloc(ALLOWED_INSTRUCTIONS * sizeof(instruction_t));
	malloc_check(dynamic_instructions);

	for (i = 0; i < ALLOWED_INSTRUCTIONS; i++)
	{
		dynamic_instructions[i] = instructions[i];
	}

	return (dynamic_instructions);
}
