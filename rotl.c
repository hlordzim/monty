#include "monty.h"

/**
 * f_rotl - rotates the stack to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
	stack_t *last, *new_front;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	last = *head;
	new_front = (*head)->next;

	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *head;
	(*head)->next = NULL;
	(*head)->prev = last;
	*head = new_front;
	new_front->prev = NULL;

	(void)counter;
}
