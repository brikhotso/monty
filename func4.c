#include "monty.h"

/**
 * set_mode - Set the mode to either STACK or QUEUE
 * @op_mode: mode to set (STACK or QUEUE)
 */
void set_mode(int op_mode)
{
	if (op_mode != STACK && op_mode != QUEUE)
	{
		fprintf(stderr, "Invalid mode\n");
		exit(EXIT_FAILURE);
	}

	mode = op_mode;
}

/**
 * push_stack - Push an element to the stack
 * @stack: pointer to top of stack
 * @new_node: pointer to the new node
 */
void push_stack(stack_t **stack, stack_t *new_node)
{
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * push_queue - Push an element to the queue
 * @stack: pointer to top of stack
 * @new_node: pointer to the new node
 */
void push_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *current = *stack;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = new_node;
		new_node->prev = current;
	}
}

/**
 * set_stack_mode - sets mode to stack
 * @stack: pointer to top of stack
 * @line_number: line number
 */
void set_stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	set_mode(STACK);
}

/**
 * set_queue_mode - sets mode to queue
 * @stack: pointer to the top of the stack
 * @line_number: line number
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	set_mode(QUEUE);
}
