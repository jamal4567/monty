#include "monty.h"
/**
 * _pall - prints values of the stack
 *
 *
 * @stack: head of the linked list
 * @line_number: line numbers execution
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void)line_number;


	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
