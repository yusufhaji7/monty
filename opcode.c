#include "monty.h"
/**
 * opCode - function to select correct operation function
 * @token1: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */
void (*opCode(char *token1))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction_s[] = {

		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mod", mod},
		{"div", _div},
		{"mul", _mul},
		{"nop", nop},
		{NULL, NULL}
		};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
		{
			return (instruction_s[i].f);
		}
		i++;
	}
	return (NULL);
}
