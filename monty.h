#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define STACK 0
#define QUEUE 1
#define UNDEFINED -1

extern int mode;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *
 * Description: doubly linked list node structure for a stack
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
 * Description: opcode and its function for a stack
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Opcode functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* Helper functions */
void exec_instruction(char *opcode, stack_t **stack, unsigned int line_number);
void process_file(const char *filename);

int is_numeric(const char *str);
void free_stack(stack_t *stack);

void set_mode(int op_mode);
void set_stack_mode(stack_t **stack, unsigned int line_number);
void set_queue_mode(stack_t **stack, unsigned int line_number);
stack_t *create_node(int data, unsigned int line_number);
void push_stack(stack_t **stack, stack_t *new_node);
void push_queue(stack_t **stack, stack_t *new_node);

#endif /* MONTY_H */
