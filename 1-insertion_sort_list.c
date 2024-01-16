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
while (current->prev != NULL && current->n < current->prev->n)
{
temp = current->prev;
/* Swapping nodes 'current' and 'temp' */
current->prev = temp->prev;
temp->next = current->next;

if (current->next != NULL)
current->next->prev = temp;

if (temp->prev != NULL)
temp->prev->next = current;
else
*list = current;

current->next = temp;
temp->prev = current;

print_list(*list);
/* After swap, reposition 'current' */
current = temp;
}
current = current->next;
}
}
