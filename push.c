#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @c: line_number
 *
 * Return: no return
*/
void f_push(stack_t **head, unsigned int c)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;

		for (; bus.arg[j] != '\0'; j++)
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.monty_file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, n);
	else
		add_queue(head, n);
}

