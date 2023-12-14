#include "monty.h"

/**
 * sub - subtract the top value by the bottom in a stack
 *       and push the result onto the stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void sub(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int first, second;
	if (stack_len(stack) < 2)
		error_occured("can't sub, stack too short", line_number);

	first = stack_pop(stack);
	second = stack_pop(stack);

	stack_push(stack, second - first);
}

/**
 * divide - divide the top value by the bottom in a stack
 *       and push the result onto the stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void divide(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int first, second;
	if (stack_len(stack) < 2)
		error_occured("can't div, stack too short", line_number);

	first = stack_pop(stack);
	second = stack_pop(stack);

	if (first == 0)
		error_occured("division by zero", line_number);

	stack_push(stack, second / first);
}

/**
 * multiply - multiply the top value by the bottom in a stack
 *       and push the result onto the stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	int first, second;
	if (stack_len(stack) < 2)
		error_occured("can't mul, stack too short", line_number);

	first = stack_pop(stack);
	second = stack_pop(stack);

	stack_push(stack, second * first);
}

/**
 * mod - get the remainder of the top value by
 *      the bottom in a stack and push the result
 *      onto the stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void mod(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int first, second;
	if (stack_len(stack) < 2)
		error_occured("can't mod, stack too short", line_number);

	first = stack_pop(stack);
	second = stack_pop(stack);

	if (first == 0)
		error_occured("division by zero", line_number);

	stack_push(stack, second % first);
}

/**
 * pchar - print the number at the top of the stack
 *       as a character.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void pchar(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int first;

	if (stack_len(stack) == 0)
		error_occured("can't pchar, stack empty", line_number);

	first = stack_pop(stack);
	if (first > 128 || first < 0)
		error_occured("can't pchar, value out of range", line_number);

	printf("%c\n", first);
}
