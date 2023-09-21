#include "monty.h"

/**
 * _pall -  prints all the values on the stack
 *
 * @stack: Pointer
 * @line: line number
 *
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *h;

	(void) line;

	if (!stack)
		exit(EXIT_FAILURE);
	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
