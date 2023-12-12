#include "monty.h"

/**
 * swap - Swap top two elements of the stack
 * @stack: pointer to the top of stack
 * @line_number: line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add_op - Add top two elements of the stack
 * @stack: pointer to top of stack
 * @line_number: line number in the file
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	int element1, element2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	element1 = (*stack)->n;
	element2 = (*stack)->next->n;

	(*stack)->next->n = element1 + element2;
	pop(stack, line_number);
}
/**
 * nop - Do nothing
 * @stack: pointer to top of the stack
 * @line_number: The line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
