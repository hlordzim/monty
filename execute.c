#include "monty.h"
#include <stdio.h>


void f_add(stack_t **stack, unsigned int line_number);
void f_queue(stack_t **stack, unsigned int line_number);

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	unsigned int i = 0;
	instruction_t opst[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"pop", f_pop}, {"swap", f_swap}, {"add", f_add},
		{"nop", f_nop}, {"sub", f_sub}, {"div", f_div},
		{"mul", f_mul}, {"mod", f_mod}, {"pchar", f_pchar},
		{"pstr", f_pstr}, {"rotl", f_rotl}, {"rotr", f_rotr},
		{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}
	};
	char *op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	for (i = 0; opst[i].opcode; i++)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			if (opst[i].f)
				opst[i].f(stack, counter);
			return (0);
		}
	}
	if (op)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
