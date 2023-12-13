#include "main.h"
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
	size_t num_bytes = 0;
	char *text;
	int line = 0;
	opcode_t *opcode_instruction = malloc(sizeof(opcode_t));

	malloc_check(opcode_instruction);

	stack_t *stack = stack_init();

	while (getline(&text, &num_bytes, fd) != -1)
	{
		line++;
		if (!strcmp(strtrim(text), ""))
			continue;

		parse_line(opcode_instruction, text);
		run_operation(&stack, opcode_instruction, line);
	}

	free(opcode_instruction);
	free(text);
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

			if (!(
					strcmp(part, (char *)"pall") &&
					strcmp(part, (char *)"pint") &&
					strcmp(part, (char *)"pop")))
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
	instruction_t operations[ALLOWED_INSTRUCTIONS] = {
		{"pint", pint},
		{"push", push},
		{"pop", pop},
		{"pall", pall},
	};
	bool operation_success = false;

	for (i = 0; i < ALLOWED_INSTRUCTIONS; i++)
	{
		if (!strcmp((operations[i]).opcode, operation->opcode))
		{
			GLOBAL_OPCODE_VALUE = &operation->value;
			(operations[i]).f(stack, line);
			operation_success = true;
		}
	}

	if (operation_success == false)
		unknown_instruction(line, operation);
}
