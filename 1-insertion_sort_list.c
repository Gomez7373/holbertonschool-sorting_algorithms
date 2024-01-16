#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Description: This function sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm. It swaps
 * the nodes themselves instead of the integer `n` in the node.
 * The function prints the list after each time two elements are swapped.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
temp = current;
while (temp->prev != NULL && temp->n < temp->prev->n)
{
/* Swap nodes */
temp->prev->next = temp->next;
if (temp->next != NULL)
temp->next->prev = temp->prev;

temp->next = temp->prev;
temp->prev = temp->prev->prev;
temp->next->prev = temp;

if (temp->prev != NULL)
temp->prev->next = temp;
else
*list = temp;

if (temp->next->next != NULL)
temp->next->next->prev = temp->next;

print_list(*list);
}
current = current->next;
}
}
