#include "monty.h"
/**
  *f_rotr- rotates the stack to the bottom
  *@head: stack head
  *@c: line_number
  *Return: no return
 */
void f_rotr(stack_t **head, unsigned int c)
{
	stack_t *temp;

	(void)c;
	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}
