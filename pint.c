#include "monty.h"

/**
 * _pint -  prints the value at the top of the stack
 *
 * @stack: Pointer
 * @line: line number
 */
void _pint(stack_t **stack, unsigned int line)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		free_me();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
