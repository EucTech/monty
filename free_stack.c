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


/**
 * is_digit - This is a function that convers to an integer
 * @value: This is the value
 * Return: bool
 */

bool is_digit(const char *value)
{
	char *endptr;

	strtol(value, &endptr, 10);
	return (*endptr == '\0');
}
