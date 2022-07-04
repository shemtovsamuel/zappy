/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** is nbr
*/

#include <stdbool.h>

bool is_nbr(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return false;
    return true;
}