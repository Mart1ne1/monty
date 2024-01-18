#include "monty.h"

stack_t *head = NULL;

/**
 * main -Entry point
 * @argc: arguments count
 * @argv: list of arguments
 *
 * Return: Always Success
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
 * free_nodes -Frees the nodes in the stack
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * create_node -creates a node.
 * @n: number added to the node
 *
 * Return: Pointer to the node
 * otherwise NULL
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->prev = NULL;
	node->next = NULL;
	node->n = n;
	return (node);
}

/**
 * add_to_queue- adds a node to a queue
 * @new_node: pointer to new node
 * @ln: line number
 *
 * Return: success
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
