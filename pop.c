#include "monty.h"

/**
 * _pop -  removes the top element of the stack
 *
 * @stack: Pointer
 * @line: line number
 */
void _pop(stack_t **stack, unsigned int line)
{
	stack_t *h;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}

	h = *stack;
	*stack = h->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(h);
}
