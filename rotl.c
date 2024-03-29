#include "monty.h"
/**
  *f_rotl- rotates the stack to the top
  *@head: stack head
  *@c: line_number
  *Return: no return
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int c)
{
	stack_t *current, *next;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	current = *head;
	next = (*head)->next;
	next->prev = NULL;
	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = *head;
	(*head)->next = NULL;
	(*head)->prev = current;
	*head = next;
}
