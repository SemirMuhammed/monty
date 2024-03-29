#include "monty.h"
/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @c: line_number
 *
 * Return: no return
*/
void f_mod(stack_t **head, unsigned int c)
{
	stack_t *temp;
	int length = 0, num;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	num = temp->next->n % temp->n;
	temp->next->n = num;
	*head = temp->next;
	free(temp);
}
