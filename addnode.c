#include "monty.h"
#include <stdio.h>

/**
 * addnode - add node to the head of the stack
 * @head: pointer to the head of the stack
 * @n: new value to be added to the node
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}
