#include "monty.h"


stack_t *head = NULL;

/**
 * main - entry point
 *
 * @ac: counter
 * @av: arguments
 *
 * Return: 0 (success)
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(av[1]);
	free_me();
	return (0);
}

