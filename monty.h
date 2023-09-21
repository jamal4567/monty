#ifndef monty_h
#define monty_h

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct globals - global structure to use in the functions
 * @stat: is stack or queue
 * @nline: current line
 * @argument: second parameter inside the current line
 * @tmp: doubly linked list
 * @file: file descriptor
 * @buff: input text
 *
 */
typedef struct global_variables
{
	FILE *file;
	stack_t *tmp;
	int stat;
	unsigned int nline;
	char *buff;
	char  *argument;
} g_vars_t;

extern g_vars_t para;


void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
FILE *check_input(int ac, char *av[]);
int _isdigit(char *str);
void free_nodes(void);
int start_para(FILE *file);
int main(int ac, char **av);
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

#endif
