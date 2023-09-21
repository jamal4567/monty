#include "monty.h"
/**
 * _swap -  function that swaps the top two elements of the stack
 *
 * @stack: Pointer
 * @line: line number
 *
 */
void _swap(stack_t **stack, unsigned int line)
{
	stack_t *h;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}
	h = (*stack)->next;
	(*stack)->next = h->next;

	if (h->next)
		h->next->prev = *stack;
	h->next = *stack;
	(*stack)->prev = h;
	h->prev = NULL;
	*stack = h;
}
