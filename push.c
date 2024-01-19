#include "monty.h"

/**
 * f_push - pushes an element to the stack.
 * @stack: Pointer to the head of the stack
 * @line_number: Line number in the Monty file
 *
 * Return: 
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	char *arg = bus.arg;
	int value;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	if (!push_stack(stack, value))
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
