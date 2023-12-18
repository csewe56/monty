#include "monty.h"

/**
 * f_pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line_number in the file.
 */
void f_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number) {
	stack_t *current = *stack;

	while (current != NULL) {
		printf("%d\n", current->n);
		current = current->next;
	}
}
