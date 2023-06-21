#include "monty.h"

/**
 * _push - This is the function that adds to the stack
 * @stack: This is the stack
 * @line_number: This is the line
 * Return: void
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *curr = NULL;
	char *ag;

	ag = strtok(NULL, " \t\n");
	if (ag == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		exit(EXIT_FAILURE);

	new_node->n = atoi(ag);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (stack == NULL || (*stack) == NULL)
	{
		*stack = new_node;
		return;
	}
	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	new_node->prev = curr;
}

/**
 * _pall - This function is for printing all values stores in the stack
 * @stack: This is the stack
 * @line_number: This is the line
 * Return: void
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curt = *stack;
	(void)line_number;

	while (curt->next != NULL)
	{
		curt = curt->next;
	}

	while (curt != NULL)
	{
		printf("%d\n", curt->n);
		curt = curt->prev;
	}
}
