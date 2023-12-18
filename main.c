#include "monty.h"
stack_t *head = NULL;

/**
 * main - main  entry point.
 * @argc: arguments count.
 * @argv: list of arguments.
 * Return: always 0.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * free_nodes - frees all nodes.
 * Return: Nothing.
 */
void free_nodes(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}

/**
 * create_node - creates a new node.
 * @n: integer to go into the node.
 * Return: A pointer to the new node on success else 0.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sixeof(stack_t));
	if (node == NULL)
	{
		perror("Error: Unable to allocate memory");
		exit(EXIT_FAILURE);
	}

	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
