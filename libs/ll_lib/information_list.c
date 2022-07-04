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

unsigned int linked_list_get_size(list_t list)
{
    list_t select = list;
    int i = 0;

    while (select) {
        i++;
        select = select->next;
    }
    return i;
}

bool linked_list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

void linked_list_dump(list_t list)
{
    list_t select = list;

    while (select != NULL) {
        printf("%i\n", select->value);
        select = select->next;
    }
}