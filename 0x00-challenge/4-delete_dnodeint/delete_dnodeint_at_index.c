#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head, *tmp, *to_delete;
    unsigned int p = 0;

    if (*head == NULL)
    {
        return (-1);  /* Failure: List is empty */
    }

    saved_head = *head;

    if (index == 0)
    {
        to_delete = *head;
        *head = (*head)->next;
        if (*head)
        {
            (*head)->prev = NULL;
        }
        free(to_delete);
        return (1);  /* Success */
    }

    tmp = *head;
    while (p < index - 1 && tmp != NULL)
    {
        tmp = tmp->next;
        p++;
    }

    if (tmp == NULL || tmp->next == NULL)
    {
        *head = saved_head;
        return (-1);  /* Failure: Index out of bounds */
    }

    to_delete = tmp->next;
    tmp->next = to_delete->next;

    if (to_delete->next)
    {
        to_delete->next->prev = tmp;
    }

    free(to_delete);
    *head = saved_head;
    return (1);  /* Success */
}
