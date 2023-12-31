#include "monty.h"

/**
 * pchar - Print character at the top of a stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 127)
		{
			fprintf(stdout, "%c\n", ((*stack)->n));
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n"
				, line_number);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - Print string starting from the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* Unused variable */

	if (*stack == NULL)
	{
		fprintf(stdout, "\n");
		return;
	}

	while (current != NULL && current->n != 0 &&
	       (current->n >= 0 && current->n <= 127))
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}

	fprintf(stdout, "\n");
}

/**
 * rotl - Rotate stack to the top
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second, *last;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		second = (*stack)->next;
		last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		*stack = second;
		second->prev = NULL;
		last->next = first;
		first->prev = last;
		first->next = NULL;
	}
}

/**
 * rotr - Rotate stack to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
		{
			last = last->next;
		}

		last->prev->next = NULL;
		last->prev = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}
