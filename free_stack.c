#include "monty.h"
#include <stdio.h>
/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	while (head)
	{
		stack_t *aux = head;
		head = head->next;
		free(aux);
	}
}
