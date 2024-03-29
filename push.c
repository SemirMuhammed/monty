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

/**
 * add_node - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 *
 * Return: no return
*/
void add_node(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (current)
		current->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 *
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;
	if (current)
		while (current->next)
			current = current->next;

	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}
