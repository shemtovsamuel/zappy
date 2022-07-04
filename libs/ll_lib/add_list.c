/*
** EPITECH PROJECT, 2022
** double_list
** File description:
** Pool 02 Day 02 A Ex00
*/

#include "ll.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

bool linked_list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(*node));

    if (!node)
        return false;
    node->value = elem;
    node->next = *front_ptr;
    *front_ptr = node;
    return true;
}

bool linked_list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(*node));
    list_t select = (*front_ptr);

    if (!node)
        return false;
    node->value = elem;
    node->next = NULL;
    if (*front_ptr == NULL)
        return linked_list_add_elem_at_front(front_ptr, elem);
    while (select->next != NULL)
        select = select->next;
    select->next = node;
    return true;
}

bool linked_list_add_elem_at_position(list_t *front_ptr, void *elem,
                                        unsigned int position)
{
    list_t select = *front_ptr;
    node_t *node = malloc(sizeof(*node));
    unsigned int i = 0;

    if (position == 0)
        return linked_list_add_elem_at_front(front_ptr, elem);
    if (!node)
        return false;
    node->value = elem;
    for (; select->next && i < position - 1; i++)
        select = select->next;
    if (!select->next && i < position - 1)
        return false;
    node->next = select->next;
    select->next = node;
    return true;
}