#include "monty.h"

/**
 * pstr - print the values the stack as a string
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int i, ch;

	for (i = 0; i < stack_len(stack); i++)
	{
		ch = stack_pop(stack);

		if (ch < 1 || ch > 127)
			break;

		printf("%c", ch);
	}
	printf("\n");
}

/**
 * rotl - moves the top element to the bottom of stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int top = stack_pop(stack);

	GLOBAL_ENV.queue_mode = true;
	stack_push(stack, top);
	GLOBAL_ENV.queue_mode = false;
}

/**
 * rotr - rotates the element of the stack.
 * @stack: the stack.
 * @line_number: the current line being executed.
 *
 * Return: void
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int first = stack_pop(stack);
	int second = stack_pop(stack);

	stack_push(stack, first);
	stack_push(stack, second);
}

void swap(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if(stack_len(stack) < 2)
		error_occured("can't swap, stack too short", line_number);
	
	int first_element = stack_pop(stack);
	int second_element = stack_pop(stack);

	stack_push(stack, first_element);
	stack_push(stack, second_element);
}
