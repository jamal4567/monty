#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * 
 */
 void _push(stack_t **stack, unsigned int line_number)
 {
	stack_t *head = NULL;
	stack_t *h = *stack;
	char *nb;

	nb = strtok(NULL, " \r\t\n");
	if (!nb || (isdigit(nb) != 0 && nb[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	head = malloc(sizeof(stack_t));
	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	head->n = atoi(nb);
	if (para.stat == 0 || *stack == NULL)
	{
		head->next = *stack;
		head->prev = NULL;
		if (*stack)
			(*stack)->prev = head;
		*stack = head;
	}
	else
	{
		while (h->next)
			h = h->next;
		h->next = head;
		head->prev = h;
		head->next = NULL;
	}
}
