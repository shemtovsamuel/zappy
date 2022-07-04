/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser
*/

#include "parser/parser.h"
#include "comp/is_nbr.h"

int arg_x(char **av, int i, database_t *data)
{
    if (!av[i]) {
        printf("no argument for arg -x\n");
        return -1;
    }
    if (!is_nbr(av[i])) {
        printf("argument \'%s\' is not a nbr\n", av[i]);
        return -1;
    }
    data->map.size_x = atoi(av[i]);
    return i + 1;
}
