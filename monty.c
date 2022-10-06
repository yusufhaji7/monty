#include "monty.h"

int main(int argc, char *argv[])
{
	char *size, *token;
	int line_count = 0;
	stack_t *inst = NULL;
	unsigned int line = 1;
	ssize_t n_read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	cmd = open(argv[1], O_RDONLY);
	if (cmd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	size = malloc(sizeof(char) * 10000);
	if (!size)
	{
		return (0);
	}
	n_read = read(cmd, size, 10000);
	if (n_read == -1)
	{
		free(size);
		close(cmd);
		exit(EXIT_FAILURE);
	}
	token = strtok(size, "\n ");
	while (token != NULL)
	{
		if (line_count == 1)
		{
			push(&inst, line, token);
			line_count = 0;
			token = strtok(NULL, "\n ");
			line++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			line_count = 1;
			token = strtok(NULL, "\n ");
			continue;
		}
		else
		{
			if (opCode(token) != 0)
			{
				opCode(token)(&inst, line);
			}
			else
			{
				free_dlist(&inst);
				fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
				exit(EXIT_FAILURE);
			}
		}
		line++;
		token = strtok(NULL, "\n ");
	}
	free_dlist(&inst);
	free(size);
	close(cmd);
	return (0);
}
