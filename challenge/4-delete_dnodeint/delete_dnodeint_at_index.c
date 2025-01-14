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
    dlistint_t *current;
    unsigned int p;

    if (*head == NULL)
        return (-1);

    current = *head;

    /* Si l'index est 0, supprime le premier nœud */
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    /* Parcours jusqu'à l'index désiré */
    for (p = 0; current != NULL && p < index; p++)
        current = current->next;

    /* Si on n'a pas trouvé l'index */
    if (current == NULL)
        return (-1);

    /* Ajuste les pointeurs pour le nœud à supprimer */
    if (current->next != NULL)
        current->next->prev = current->prev;
    current->prev->next = current->next;

    free(current);
    return (1);
}