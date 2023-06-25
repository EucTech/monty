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
	size_t n = 0;
	ssize_t g_line;
	char *line = NULL;
	unsigned int line_number = 1;
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	m_file = fopen(av[1], "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while ((g_line = getline(&line, &n, m_file)) != -1)
	{
		opcode = strtok(line, "\t\n ");
		if (opcode != NULL && opcode[0] != '#')
		{
			get_opcode(&stack_top, opcode, line_number);
		}
		line_number++;
	}

	fclose(m_file);
	free(line);
	free_st(stack_top);

	return (EXIT_SUCCESS);
}
