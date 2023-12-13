#include "main.h"

/**
 * stack_init - initializes a new stack.
 * Return: the newly initialized stack.
*/
stack_t *stack_init()
{
	stack_t *stack = NULL;

	return (stack);
}

/**
 * stack_push - pushes a value to stack.
 * @stack: the stack to push to.
 * @n: the value to push to stack.
 *
 * Return: void
*/
void stack_push(stack_t **stack, int n)
{
	stack_t *head = *stack;
	stack_t *block;

	/* Go to top of stack */
	if (head)
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
	}

	/* Allocate new block */
	block = malloc(sizeof(stack_t));
	malloc_check(block);

	block->n = n;
	block->prev = head;
	block->next = NULL;

	if (head)
		head->next = block;
	else
		*stack = block;
}

/**
 * stack_pop - removes a value from the stack.
 * @stack: the stack to pop from.
 *
 * Return: the value of the block that was popped.
*/
int stack_pop(stack_t **stack)
{
	stack_t *head = *stack;
	stack_t *prev;
	int n;

	/* Go to top of stack */
	if (!head)
		return (0);

	while (head->next != NULL)
	{
		head = head->next;
	}

	prev = head->prev;
	if (prev)
		prev->next = NULL;
	else
		*stack = NULL;

	n = head->n;
	free(head);

	return (n);
}

/**
 * stack_print - prints the values of a stack.
 * @stack: the stack to print.
 * @fifo: if true, the stack is printed in FIFO order.
 *
 * Return: void
*/
void stack_print(stack_t **stack, bool fifo)
{
	stack_t *head = *stack;
	int stack_size = 0;

	if (!head)
		return;

	if (fifo)
	{
		while (head != NULL)
		{
			printf("%d\n", head->n);
			head = head->next;
			stack_size++;
		}
	}
	else
	{
		while (head->next != NULL)
			head = head->next;

		while (head != NULL)
		{
			stack_size++;
			printf("%d\n", head->n);
			head = head->prev;
		}
	}
}

/**
 * stack_pint - prints the value at the top of the stack.
 * @stack: the stack containing the value to print.
 *
 * Return: void
*/
int stack_pint(stack_t **stack)
{
	stack_t *head = *stack;
	int n;

	/* Go to top of stack */
	if (!head)
		return (0);

	while (head->next != NULL)
	{
		head = head->next;
	}

	n = head->n;

	printf("%d\n", n);

	return (n);
}
