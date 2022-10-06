#include "monty.h"
/**
 * _add - adds nodes to the top of the list
 * @inst: pointer to head of list
 * @line_number: line count position
 */
void _add(stack_t **inst, unsigned int line_number)
{

	if (dlistint_len(*inst) < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*inst)->next->n += (*inst)->n;
	(*inst) = (*inst)->next;
	free((*inst)->prev);
	(*inst)->prev = NULL;
}
/**
 * nop - does nothing
 * @inst: pointer to head of a list
 * @line_number: bytecode line number
 */
void nop(stack_t **inst, unsigned int line_number)
{
	(void) inst;
	(void) line_number;
}
/**
 * _sub - sub nodes to the top of the list
 * @inst: pointer to head of list
 * @line_number: line count position
 */
void _sub(stack_t **inst, unsigned int line_number)
{

        if (dlistint_len(*inst) < 2)
        {
                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*inst)->next->n -= (*inst)->n;
        (*inst) = (*inst)->next;
        free((*inst)->prev);
        (*inst)->prev = NULL;
}
/**
 * _mul - mul nodes to the top of the list
 * @inst: pointer to head of list
 * @line_number: line count position
 */
void _mul(stack_t **inst, unsigned int line_number)
{

        if (dlistint_len(*inst) < 2)
        {
                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        (*inst)->next->n *= (*inst)->n;
        (*inst) = (*inst)->next;
        free((*inst)->prev);
        (*inst)->prev = NULL;
}
/**
 * _div - div nodes to the top of the list
 * @inst: pointer to head of list
 * @line_number: line count position
 */
void _div(stack_t **inst, unsigned int line_number)
{

        if (dlistint_len(*inst) < 2)
        {
                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
	if ((*inst)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
        (*inst)->next->n /= (*inst)->n;
	delete_index(inst, 0);
}
