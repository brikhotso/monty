#include "monty.h"

/**
 * execute_instruction - Executes the instruction based on the opcode.
 * @opcode: The opcode to execute.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the file.
 */
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
    int count = 0;
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add_op},
        {"nop", nop},
        {"sub", sub_op},
        {"div", div_op},
        {"mul", mul_op},
        {"mod", mod_op},
        {NULL, NULL}
    };

    while (instructions[count].opcode != NULL)
    {
        if (strcmp(opcode, instructions[count].opcode) == 0)
        {
            instructions[count].f(stack, line_number);
            return;
        }
        count++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

/**
 * process_file - Processes the Monty bytecode file.
 * @filename: The name of the file containing Monty bytecode.
 */
void process_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL, *opcode;
    size_t len = 0;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    ssize_t read_line;

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&line, &len, file)) != -1)
    {
        line_number++;

        /* Check for comment lines */
        if (line[0] == '#')
            continue;

        opcode = strtok(line, " \t\n");

        if (opcode != NULL)
        {
            execute_instruction(opcode, &stack, line_number);
        }
    }

    if (feof(file))
    {
        free(line);
        fclose(file);
        free_stack(stack);
    }
    else
    {
        fprintf(stderr, "Error reading the file\n");
        exit(EXIT_FAILURE);
    }
}


void free_stack(stack_t *stack)
{
    stack_t *tmp;

    while (stack != NULL)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    process_file(argv[1]);

    return EXIT_SUCCESS;
}
