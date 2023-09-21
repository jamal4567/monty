#include "monty.h"
/**
 * free_nodes - frees the global malloc memory
 * Return: void
 */
void free_nodes(void)
{
	if (para.buff != NULL)
		free(para.buff);
	if (para.file != NULL)
		fclose(para.file);
	if (para.tmp)
	{
		while (para.tmp->next)
		{
			para.tmp = para.tmp->next;
			free(para.tmp->prev);
		}
		free(para.tmp);
	}
}
/**
 * isdigit - check for digit
 * @str: strings
 * Return: 0 or 1 
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
/**
 * start_para - Fake rand to jackpoint Giga Millions
 * @para: Global variables to initialize
 * Return: 0 Success, 1 Failed
 */
int start_para(FILE *file)
{
	para.file = file;
	para.buff = NULL;
	para.tmp = NULL;
	para.nline = 1;
	para.stat = 1;
	para.argument = NULL;

	return (0);
}
/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @ac: argument count
 * @av: argument vector
 * Return: file struct
 */
FILE *check_input(int ac, char *av[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
