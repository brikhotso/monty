#include "monty.h"

#include <ctype.h>

int is_numeric(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

/**
 * push - Pushes an element to the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *data_str;
    int data;
    stack_t *new_node;

    data_str = strtok(NULL, " \t\n");

    if (data_str == NULL) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (!is_numeric(data_str)) {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    data = atoi(data_str);
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = data;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void pall(stack_t **stack, unsigned int line_number) {

    stack_t *current;

    (void)line_number;

    current = *stack;

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}


/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void pint(stack_t **stack, unsigned int line_number) {
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
    if (*stack == NULL) {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }

    free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
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
 * nop - Does nothing.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}
