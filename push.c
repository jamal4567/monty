#include "monty.h"

/**
 * _push - function that add node into the stack
 *
 * @node: Pointer
 * @line: line number
 *
 */
void _push(stack_t **node, __attribute__((unused))unsigned int line)
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
	head = *node;
	head->next = tmp;
	tmp->prev = head;
}
