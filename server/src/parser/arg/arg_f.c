/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser
*/

#include "parser/parser.h"
#include "comp/is_nbr.h"


int arg_f(char **av, int i, database_t *data)
{
    if (!av[i]) {
        printf("no argument for arg -f\n");
        return -1;
    }
    if (!is_nbr(av[i])) {
        printf("argument \'%s\' is not a nbr\n", av[i]);
        return -1;
    }
    data->freq = atoi(av[i]);
    return i + 1;
}
