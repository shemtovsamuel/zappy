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

bool linked_list_del_elem_at_front(list_t *front_ptr)
{
    list_t select = *front_ptr;

    if (!front_ptr)
        return false;
    *front_ptr = select->next;
    free(select);
    return true;
}

bool linked_list_del_elem_at_back(list_t *front_ptr)
{
    list_t select = *front_ptr;
    list_t second;

    if (!front_ptr)
        return false;
    if (!select->next) {
        free(select);
        *front_ptr = NULL;
        return true;
    }
    while (select->next->next)
        select = select->next;
    second = select;
    select = select->next;
    free(select);
    second->next = NULL;
    return true;
}

bool linked_list_del_elem_at_position(list_t *front_ptr,
                                        unsigned int position)
{
    list_t select = *front_ptr;
    list_t second;
    unsigned int i = 0;

    if (position == 0)
        return linked_list_del_elem_at_front(front_ptr);
    for (; select->next && i < position - 1; i++)
        select = select->next;
    if (!select->next && i < position - 1)
        return false;
    second = select->next;
    select->next = select->next->next;
    free(second);
    return true;
}
