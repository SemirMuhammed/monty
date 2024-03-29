#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
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
 * struct bus_s - variables -args, monty_file, line content
 * @arg: value
 * @monty_file: pointer to monty monty_file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */

typedef struct bus_s
{
	char *arg;
	FILE *monty_file;
	char *content;
	int lifi;
}  bus_t;

extern bus_t bus;

/**
 * struct op_s - op_code and its function
 * @op_code: the op_code
 * @f: function to handle the op_code
 *
 * Description: op_code and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct op_s
{
	char *op_code;
	void (*f)(stack_t **stack, unsigned int line_number);
} op_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int monty_file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int c, FILE *monty_file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int c);
void f_swap(stack_t **head, unsigned int c);
void f_add(stack_t **head, unsigned int c);
void f_nop(stack_t **head, unsigned int c);
void f_sub(stack_t **head, unsigned int c);
void f_div(stack_t **head, unsigned int c);
void f_mul(stack_t **head, unsigned int c);
void f_mod(stack_t **head, unsigned int c);
void f_pchar(stack_t **head, unsigned int c);
void f_pstr(stack_t **head, unsigned int c);
void f_rotl(stack_t **head, unsigned int c);
void f_rotr(stack_t **head, unsigned int c);
void add_node(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int c);
void f_stack(stack_t **head, unsigned int c);

#endif /* MONTY_H */
