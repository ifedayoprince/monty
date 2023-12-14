#include "main.h"

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

	if (GLOBAL_ENV.queue_mode)
	{
		queue_push(stack, n);
		return;
	}

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

	if (GLOBAL_ENV.queue_mode)
		return (queue_pop(stack));

	/* Go to top of stack */
	if (!head)
		return (0);

	while (head->next != NULL)
		head = head->next;

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

	if (GLOBAL_ENV.queue_mode)
	{
		queue_print(stack);
		return;
	}

	if (!head)
		return;

	if (fifo)
	{
		while (head != NULL)
		{
			printf("%d\n", head->n);
			head = head->next;
		}
	}
	else
	{
		while (head->next != NULL)
			head = head->next;

		while (head != NULL)
		{
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

	if (GLOBAL_ENV.queue_mode)
		return (queue_pint(stack));

	/* Go to top of stack */
	if (!head)
		return (0);

	while (head->next != NULL)
		head = head->next;

	n = head->n;

	printf("%d\n", n);

	return (n);
}

/**
 * stack_len - prints the values of a stack.
 * @stack: the stack to print.
 *
 * Return: the length of the stack
 */
int stack_len(stack_t **stack)
{
	stack_t *head = *stack;
	int stack_size = 0;

	if (GLOBAL_ENV.queue_mode)
		return (queue_len(stack));

	if (!head)
		return (0);

	while (head != NULL)
	{
		head = head->next;
		stack_size++;
	}

	return (stack_size);
}
