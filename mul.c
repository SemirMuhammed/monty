#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @c: line_number
 *
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int c)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", c);
		fclose(bus.monty_file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	num = temp->next->n * temp->n;
	temp->next->n = num;
	*head = temp->next;
	free(temp);
}
