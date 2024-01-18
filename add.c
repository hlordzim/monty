#include "monty.h"
#include <stdio.h>

/**
 * f_add - Adds the top two elements of the stack.
 * @stack: Pointer to the head of the stack
 * @line_num: Line number in the Monty file
 * Return: No return value
 */
void f_add(stack_t **stack, unsigned int line_num)
{
	stack_t *current;
	int size = 0, result;

	current = *stack;
	while (current)
	{
		current = current->next;
		size++;
	}

	if (size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	result = current->n + current->next->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
