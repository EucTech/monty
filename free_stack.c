#include "monty.h"

/**
 * free_st - This is a free function that frees the stack
 * @stack: This is a pointer to the stack
 * Return: Void
 */

void free_st(stack_t *stack)
{
	stack_t *temporal = stack;
	stack_t *next;

	while (temporal != NULL)
	{
		next = temporal->next;
		free(temporal);
		temporal = next;
	}
}
