#include "monty.h"
/**
 * _putnd - function that creat node
 * @nb: Number
 * Return: adrress if success or NULL.
 */
stack_t *_putnd(int nb)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_me();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = nb;
	return (node);
}

/**
 * free_me - function that free a stack.
 */
void free_me(void)
{
	stack_t *tmp;

	if (!head)
		return;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * put_in_queue - function that add node to queue
 *
 * @node: Pointer
 * @line: line number
 *
 */
void put_in_queue(stack_t **node, __attribute__((unused))unsigned int line)
{
	stack_t *tmp;

	if (!node || !*node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *node;
		return;
	}
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *node;
	(*node)->prev = tmp;

}
