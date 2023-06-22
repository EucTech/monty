#include "monty.h"

/**
 * _nop - does nothing
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: nothing
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _div - divides the first two stacks
 * @stack: double pointer to the stack
 * @line_number: line
 * Return: nothing
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL )
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = *stack;
		result = (temp)->next->n / temp->n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		(*stack)->n = result;
		free(temp);
	}
}
		
