#include "monty.h"

/**
 * get_opcode - This a function that reads the line
 * @m_file: This is the file
 * @stack: This is a the stack
 * Return: Void
 */

void get_opcode(FILE *m_file, stack_t **stack)
{
	unsigned int line_number = 1;
	char f_line[100];
	char *opcode;
	int lo, opc_valid = 0;

	instruction_t instruction[] = {
		{ "push", _push },
		{ "pall", _pall },
		{ NULL, NULL }
	};

	while (fgets(f_line, sizeof(f_line), m_file))
	{
		opcode = strtok(f_line, " \t\n");

		if (opcode != NULL)
		{
			for (lo = 0; instruction[lo].opcode != NULL; lo++)
			{
				if (strcmp(opcode, instruction[lo].opcode) == 0)
				{
					opc_valid = 1;
					instruction[lo].f(stack, line_number);
					break;
				}
			}
			if (opc_valid == 0)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free_st(*stack);
				fclose(m_file);
				exit(EXIT_FAILURE);
			}
		}

		line_number++;
	}
}

