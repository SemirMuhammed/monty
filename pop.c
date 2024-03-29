#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @c: line_number
 *
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int c)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = temp->next;
	free(temp);
}
