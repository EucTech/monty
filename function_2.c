#include "monty.h"

/**
 * _add - This is a function that adds the top elements of a stack
 * @stack: This is the pointer to the stack
 * @line_number: This is the line_number
 * Return: Void
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *t_stack;
	stack_t *s_stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	t_stack = *stack;
	s_stack = t_stack->next;

	s_stack->n += t_stack->n;
	s_stack->prev = NULL;
	*stack = s_stack;

	free(t_stack);
}
