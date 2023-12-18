#include "monty.h"

/**
 * f_push - Pushed an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 */
void f_push(stack_t **stack, unsigned int line_number){
	char *arg = strtok(NULL, " \t\n");
	int value = atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || !isdigit(*arg)) {
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL) {
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL) {
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
