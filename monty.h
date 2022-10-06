#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int cmd;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int is_number(const char *n);
void push(stack_t **inst, unsigned int line_number, const char *n);
void free_dlist(stack_t **inst);
int add_element(stack_t **inst, int n);
void pall(stack_t **inst, unsigned int line_number);
void (*opCode(char *token1))(stack_t **stack, unsigned int line_number);
void pint(stack_t **inst, unsigned int line_number);
void pop(stack_t **inst, unsigned int line_number);
void swap(stack_t **inst, unsigned int line_number);
size_t dlistint_len(const stack_t *h);
int delete_index(stack_t **head, unsigned int index);
void _add(stack_t **inst, unsigned int line_number);
void _mul(stack_t **inst, unsigned int line_number);
void _sub(stack_t **inst, unsigned int line_number);
void mod(stack_t **inst, unsigned int line_number);
void _div(stack_t **inst, unsigned int line_number);
void nop(stack_t **inst, unsigned int line_number);
#endif
