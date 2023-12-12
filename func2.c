#include "monty.h"

/**
 * sub_op - Subtracts the top element of the stack from the second top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
    int element1, element2;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    element1 = (*stack)->n;
    element2 = (*stack)->next->n;

    (*stack)->next->n = element2 - element1;
    pop(stack, line_number);
}

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    int element1, element2;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    element1 = (*stack)->n;
    element2 = (*stack)->next->n;

    if (element1 == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n = element2 / element1;
    pop(stack, line_number);
}

/**
 * mul_op - Multiplies the second top element of the stack with the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
    int element1, element2;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    element1 = (*stack)->n;
    element2 = (*stack)->next->n;

    (*stack)->next->n = element2 * element1;
    pop(stack, line_number);
}

/**
 * mod_op - Computes the rest of the division of the second top element by the top element.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
    int element1, element2;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    element1 = (*stack)->n;
    element2 = (*stack)->next->n;

    if (element1 == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n = element2 % element1;
    pop(stack, line_number);
}
