#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 *
 * Description: Sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm. It swaps the nodes themselves instead
 * of the integer `n` in the node. The function prints the list after each
 * time two elements are swapped.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;
while (current != NULL)
{
temp = current->prev;
while (temp != NULL && current->n < temp->n)
{
/* Swap nodes 'current' and 'temp' */
if (temp->prev != NULL)
temp->prev->next = current;
if (current->next != NULL)
current->next->prev = temp;

temp->next = current->next;
current->prev = temp->prev;
current->next = temp;
temp->prev = current;

/* Update the head of the list if necessary */
if (current->prev == NULL)
*list = current;
else
temp = current->prev;

print_list(*list);
}
current = current->next;
}
}
