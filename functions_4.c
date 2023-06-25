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

/**
 * _rotr - rotates the stack to the bottom.
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: nothing
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom, *temp;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	bottom = *stack;

	while (bottom->next != NULL)
		bottom = bottom->next;

	temp = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	temp->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}

/**
 * _stack - sets the format of the data to a stack
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: nothing
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	input.flag = 0;
}

/**
 * _queue - sets the foramt of the data to a queue
 * @stack: double pointer to the stack
 * @line_number: the line
 * Return: nothing
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	input.flag = 1;
}
