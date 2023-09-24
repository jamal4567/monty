#include "monty.h"
/**
 * _mod -  computes the rest of the division
 *of the second top element of the stack by the top element of the stack
 *
 * @stack: Pointer
 * @line: line number
 *
 */
void _mod(stack_t **stack, unsigned int line)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
