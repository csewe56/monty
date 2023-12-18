#include "monty.h"

/**
 * handle_file_error - Handles errors related to file processing.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 */
void handle_file_error(int error_code, ...)
{
    va_list args;

    va_start(args, error_code);
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * handle_instruction_error - Handles errors related to invalid instructions.
 * @error_code: The error codes are the following:
 * (3) => The file provided contains an invalid instruction.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 */
void handle_instruction_error(int error_code, ...)
{
    va_list args;
    int line_num;
    char *instruction;

    va_start(args, error_code);
    switch (error_code)
    {
        case 3:
            line_num = va_arg(args, int);
            instruction = va_arg(args, char *);
            fprintf(stderr, "L%d: unknown instruction %s\n", line_num, instruction);
            break;
        case 5:
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * handle_stack_error - Handles errors related to stack operations.
 * @error_code: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for an operation.
 * (9) => Division by zero.
 */
void handle_stack_error(int error_code, ...)
{
    va_list args;
    int line_num;
    char *operation;

    va_start(args, error_code);
    switch (error_code)
    {
        case 6:
            fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
            break;
        case 7:
            fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
            break;
        case 8:
            line_num = va_arg(args, unsigned int);
            operation = va_arg(args, char *);
            fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, operation);
            break;
        case 9:
            fprintf(stderr, "L%d: division by zero\n", va_arg(args, unsigned int));
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * handle_string_error - Handles errors related to string operations.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void handle_string_error(int error_code, ...)
{
    va_list args;
    int line_num;

    va_start(args, error_code);
    line_num = va_arg(args, int);
    switch (error_code)
    {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
            break;
        default:
            break;
    }
    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

