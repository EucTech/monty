#include "monty.h"


/**
 * main - This a program for doubly linked list and stack
 * @ac: This is the argument count
 * @av: This is the argument vector
 * Return: Success
 */

int main(int ac, char **av)
{

	stack_t *stack_top = NULL;
	FILE *m_file;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_file = fopen(av[1], "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't Open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	get_opcode(m_file);

	fclose(m_file);
	free_st(stack_top);
	exit(EXIT_FAILURE);
}
