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

void *linked_list_get_elem_at_front(list_t list)
{
    if (!list)
        return 0;
    return list->value;
}

void *linked_list_get_elem_at_back(list_t list)
{
    list_t select = list;

    if (!list)
        return 0;
    while (select->next)
        select = select->next;
    return select->value;
}

void *linked_list_get_elem_at_position(list_t list,
                                        unsigned int position)
{
    list_t select = list;
    unsigned int i = 0;

    if (position == 0)
        return linked_list_get_elem_at_front(list);
    if (!list)
        return 0;
    while (select->next && i < position) {
        select = select->next;
        i++;
    }
    if (!select->next && i < position)
        return 0;
    return select->value;
}

node_t  *linked_list_get_first_node_with_value(list_t list, void *value)
{
    node_t *select = list;

    if (list == NULL)
        return NULL;
    while (select && select->value != value)
        select = select->next;
    return select;
}