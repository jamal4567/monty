#include "monty.h"

g_vars_t para;

/**
 * main - Start LIFO, FILO program
 * @ac: Number of arguments
 * @av: Pointer containing arguments
 * Return: 0 Success, 1 Failed
 */
int main(int ac, char **av)
{
    void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t l = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(ac, av);
	start_para(fd);
	l = getline(&para.buff, &size, fd);
	while (l != -1)
	{
		lines[0] = strtok(para.buff, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				fprintf(stderr, "L%u: ", para.nline);
				fprintf(stderr, "unknown instruction %s\n", lines[0]);
				free_nodes();
				exit(EXIT_FAILURE);
			}
			para.argument = strtok(NULL, " \t\n");
			f(&para.tmp, para.nline);
		}
		l = getline(&para.buff, &size, fd);
		para.nline++;
	}

	free_nodes();

	return (0);
}
