#include "monty.h"
/**
 * _sub -  subtracts the top element of the stack ,
 *      ,from the second top element of the stack
 *
 * @stack: Pointer
 * @line: line number
 *
 */
void _sub(stack_t **stack, unsigned int line)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
