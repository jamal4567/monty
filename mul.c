#include "monty.h"
/**
 * _mul -  multiplies the second top element of the stack with the top
 *
 * @stack: Pointer
 * @line: line number
 *
 */
void _mul(stack_t **stack, unsigned int line)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
