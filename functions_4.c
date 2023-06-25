#include "monty.h"

/**
 * _rotl - rotates the stack to the top.
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: nothing
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;

	*stack = temp->next;
	temp->next->prev = NULL;
	temp->next = NULL;
	last->next = temp;
	temp->prev = last;
}
