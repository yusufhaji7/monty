#include "monty.h"
/**
 * _mod - div nodes to the top of the list
 * @inst: pointer to head of list
 * @line_number: line count position
 */
void mod(stack_t **inst, unsigned int line_number)
{

        if (dlistint_len(*inst) < 2)
        {
                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		close(cmd);
		exit(EXIT_FAILURE);
        }
        if ((*inst)->n == 0)
        {
                fprintf(stderr, "L%u: division by zero\n", line_number);
		close(cmd);
		exit(EXIT_FAILURE);
        }
        (*inst)->next->n %= (*inst)->n;
        delete_index(inst, 0);
}
