#include "monty.h"

/**
 * push - pushes a value unto a stack.
 * @stack: the stack to push to.
 * @line_number: the current line being executed.
 *
 * Return: void
*/
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_push(stack, GLOBAL_ENV.operand);
}

/**
 * pop - pops a value off the stack.
 * @stack: the stack to pop from.
 * @line_number: the current line being executed.
 *
 * Return: void
*/
void pop(stack_t **stack, __attribute__((unused))  unsigned int line_number)
{
	stack_pop(stack);
}

/**
 * pall - prints all values in a stack.
 * @stack: the stack to push to.
 * @line_number: the current line being executed.
 *
 * Return: void
*/
void pall(stack_t **stack, __attribute__((unused))  unsigned int line_number)
{
	stack_print(stack, false);
}

/**
 * pint - prints the value at the top of the stack.
 * @stack: the stack to push to.
 * @line_number: the current line being executed.
 *
 * Return: void
*/
void pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_pint(stack);
}
