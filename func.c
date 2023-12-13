#include "monty.h"

/**
 * is_numeric - check if string represent valid integer
 * @str: string to check
 * Return: 0 on sucess else return 1
 */
int is_numeric(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * push - Push an element to stack or queue based on the current mode
 * @stack: pointer to top of stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *data_str;
	int data;
	stack_t *new_node;

	data_str = strtok(NULL, " \t\n");

	if (data_str == NULL || !is_numeric(data_str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(data_str);
	new_node = create_node(data, line_number);

	if (mode == UNDEFINED)
	{
		set_mode(STACK);
	}

	if (mode == STACK)
	{
		push_stack(stack, new_node);
	}
	else if (mode == QUEUE)
	{
		push_queue(stack, new_node);
	}
	else
	{
		fprintf(stderr, "L%u: invalid mode\n", line_number);
		exit(EXIT_FAILURE);
	}
}


/**
 * pall - Print all data on the stack
 * @stack: pointer to top of stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number; /* Unused variable */

	if (current == NULL)
	{
		return;
	}

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", (*stack)->n);
		current = current->next;
	}
}

/**
 * pint - Print data at the top of stack
 * @stack: pointer to top of stack
 * @line_number: line number in the file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - Remove top element of the stack
 * @stack: pointer to top of  stack
 * @line_number: line number in the file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(tmp);
}
