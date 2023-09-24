#include "monty.h"
/**
 * get_opcode - function that chose opcode
 * @opc: opcode
 * @argv: argument
 * @fmt:  storage
 * @line: line number
 *
 */
void get_opcode(char *opc, char *argv, int line, int fmt)
{
	int i, flag;

	instruction_t opcod_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nope},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	if (opc[0] == '#')
		return;

	for (flag = 1, i = 0; opcod_list[i].opcode != NULL; i++)
	{
		if (strcmp(opc, opcod_list[i].opcode) == 0)
		{
			opcode_call(opcod_list[i].f, opc, argv, line, fmt);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opc);
		free_me();
		exit(EXIT_FAILURE);
	}
}


/**
 * opcode_call - function tha call the require opcode
 *
 * @ptr: Pointer
 * @s: string
 * @vars: string
 * @line: line numeber
 * @fmt: specifier
 *
 */
void opcode_call(op_func ptr, char *s, char *vars, int line, int fmt)
{
	stack_t *h;
	int i, flag;

	flag = 1;
	if (strcmp(s, "push") == 0)
	{
		if (vars != NULL && vars[0] == '-')
		{
			vars = vars + 1;
			flag = -1;
		}
		if (!vars)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_me();
			exit(EXIT_FAILURE);
		}
		for (i = 0; vars[i] != '\0'; i++)
		{
			if (isdigit(vars[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				free_me();
				exit(EXIT_FAILURE);
			}
		}
		h = _putnd(atoi(vars) * flag);
		if (fmt == 0)
			ptr(&h, line);
		if (fmt == 1)
			put_in_queue(&h, line);
	}
	else
		ptr(&head, line);
}

/**
 * _open - function that open file
 *
 * @file: file
 *
 */

void _open(char *file)
{
	FILE *fd = fopen(file, "r");

	if (!file || !fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		free_me();
		exit(EXIT_FAILURE);
	}

	_read(fd);
	fclose(fd);
}


/**
 * _read - function that read file
 * @file: pointer
 * Return: void
 */

void _read(FILE *file)
{
	int nline;
	int fmt = 0;
	char *buff = NULL;
	size_t size = 0;

	for (nline = 1; getline(&buff, &size, file) != -1; nline++)
	{
		fmt = _parse(buff, nline, fmt);
	}
	free(buff);
}


/**
 * _parse - function that splite each line
 *
 * @buff: line from the file
 * @nline: line number
 * @fmt:  storage
 *
 * Return: 0 or 1
 */

int _parse(char *buff, int nline, int fmt)
{
	char *opc;
	char *vars;
	const char *m = "\n ";

	if (!buff)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_me();
		exit(EXIT_FAILURE);
	}

	opc = strtok(buff, m);
	if (opc == NULL)
		return (fmt);
	vars = strtok(NULL, m);

	if (strcmp(opc, "stack") == 0)
		return (0);
	if (strcmp(opc, "queue") == 0)
		return (1);

	get_opcode(opc, vars, nline, fmt);
	return (fmt);
}
