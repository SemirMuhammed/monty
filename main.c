#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty monty_file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	unsigned int c = 0;
	char *content;
	FILE *monty_file;
	size_t size = 0;
	ssize_t line_count = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty monty_file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	bus.monty_file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open monty_file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_count > 0)
	{
		content = NULL;
		line_count = getline(&content, &size, monty_file);
		bus.content = content;
		c++;
		if (line_count > 0)
		{
			execute(content, &stack, c, monty_file);
		}
		free(content);
	}

	free_stack(stack);
	fclose(monty_file);
	return (0);
}
