#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @c: line_number
 *
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int c)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
