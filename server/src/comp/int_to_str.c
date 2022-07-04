/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** Int to str
*/

#include <stdlib.h>

static int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    else
        nb = nb * my_compute_power_rec(nb, p - 1);
    return (nb);
}

char *intostr(int number)
{
    int size = 0;
    char *result;

    for (int copy = number; copy != 0; copy = copy / 10)
        size++;
    if (size == 0)
        return ("0");
    result = malloc(sizeof(char) * (size + 1));
    for (int i = 0; i != size; i++) {
        result[i] = (number / my_compute_power_rec(10, size - i - 1)) % 10 + 48;
        result[i + 1] = 0;
    }
    return (result);
} 