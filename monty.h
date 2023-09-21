#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void _open(char *file);
int _parse(char *buff, int nline, int fmt);
void _read(FILE *file);

void get_opcode(char *opc, char *argv, int line, int fmt);

stack_t *_putnd(int nb);

void free_me(void);

void _push(stack_t **node, __attribute__((unused))unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _nope(stack_t **stack, unsigned int line);

void put_in_queue(stack_t **node, __attribute__((unused))unsigned int line);
void opcode_call(op_func ptr, char *s, char *vars, int line, int fmt);
#endif
