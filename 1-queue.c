#include "monty.h"

/**
 * queue_push - pushes a value to queue.
 * @queue: the queue to push to.
 * @n: the value to push.
 *
 * Return: void
 */
void queue_push(stack_t **queue, int n)
{
	stack_t *ptr = *queue;
	stack_t *block = malloc(sizeof(stack_t));

	malloc_check(block);
	if (ptr)
	{
		ptr->prev = block;
	}
	block->n = n;
	block->prev = NULL;
	block->next = ptr;

	*queue = block;
}

/**
 * queue_pop - removes a value from the queue.
 * @queue: the queue to pop from.
 *
 * Return: the value of the block that was popped.
 */
int queue_pop(stack_t **queue)
{
	stack_t *ptr = *queue, *prev;
	int n;

	if (!ptr)
		return (0);

	while (ptr->next != NULL)
		ptr = ptr->next;

	prev = ptr->prev;
	if (prev)
		prev->next = NULL;
	else
		*queue = NULL;

	n = ptr->n;
	free(ptr);

	return (n);
}

/**
 * queue_print - prints the values of a queue.
 * @queue: the queue to print.
 *
 * Return: void
 */
void queue_print(stack_t **queue)
{
	stack_t *ptr = *queue;

	if (!ptr)
		return;

	while (ptr->next != NULL)
		ptr = ptr->next;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->prev;
	}
}

/**
 * queue_pint - prints the value at the top of the queue.
 * @queue: the queue containing the value to print.
 *
 * Return: void
 */
int queue_pint(stack_t **queue)
{
	stack_t *ptr = *queue;

	if (!ptr)
		return (0);

	while (ptr->next != NULL)
		ptr = ptr->next;

	printf("%d\n", ptr->n);
	return (ptr->n);
}

/**
 * queue_len - prints the values of a queue.
 * @queue: the queue to print.
 *
 * Return: the length of the queue
 */
int queue_len(stack_t **queue)
{
	stack_t *ptr = *queue;
	int len = 0;

	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}

	return (len);
}
