#include "monty.h"
/**
* execute - executes the op_code
* @stack: head linked list - stack
* @c: line_counter
* @monty_file: poiner to monty monty_file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int c, FILE *monty_file)
{
	unsigned int i;
	char *op;
	op_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},   {"swap", f_swap}, {"add", f_add},
				{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
				{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
				{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
				{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}
				};

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].op_code && op; i++)
	{
		if (strcmp(op, opst[i].op_code) == 0)
		{	opst[i].f(stack, c);
			return (0);
		}
	}

	if (op && opst[i].op_code == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(monty_file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
