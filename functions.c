#include "monty.h"
/**
 * is_number - checks if character is a string
 *
 * @n: integer
 * Return: Always O
 */
int is_number(const char *n)
{
	int i = 0;


	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * free_dlist - frees a doubly linked list
 *
 * @inst: pointer to head of list
 *
 */
void free_dlist(stack_t **inst)
{
	if (!inst)
		return;

	while (*inst && (*inst)->next)
	{
		*inst = (*inst)->next;
		free((*inst)->prev);
	}
	free(*inst);
}
/**
 * add_element - Adds element to the front of a list
 *
 * @inst: Pointer to the head of a list
 * @n: Integer
 * Return: Always 0
 */
int add_element(stack_t **inst, int n)
{
	stack_t *new;

	if (!inst)
		return (-1);

	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		return (-1);
	}
	new->n = n;

	if (*inst == NULL)
	{
		*inst = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *inst;
		(*inst)->prev = new;
		*inst = new;
	}
	return (0);
}
