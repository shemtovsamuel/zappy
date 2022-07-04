/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser
*/

#include "parser/parser.h"
#include "parser/map_creation.h"
#include <stdio.h>
#include <string.h>

static int handle_arg(char *cmd, char **av, int i, database_t *data)
{
    for (int j = 0; j != TAB_SIZE; j++) {
        if (strcmp(cmd, TAB[j].name) == 0) {
            return TAB[j].function(av, i + 1, data);
        }
    }
    printf("badArgument : \'%s\'\n");
    return -1;
}

static void default_values(database_t *data)
{
    data->freq = 100;
    data->clientNb = -1;
    data->port = -1;
    data->map.size_x = -1;
    data->map.size_y = -1;
    data->event_registered = NULL;
    data->team = NULL;
}

bool data_correctly_fill(database_t *data)
{
    if (data->clientNb == -1 || data->port == -1 || data->map.size_x == -1 ||
        data->map.size_y == -1 || linked_list_is_empty(data->team))
        return false;
    return true;
}

database_t parser(char **av)
{
    database_t data;

    default_values(&data);
    for (int i = 1; av[i];) {
        i = handle_arg(av[i], av, i, &data);
        if (i == -1) {
            data.clientNb = -1;
            return data;
        }
    }
    if (create_map(&data.map) == ERROR)
        data.clientNb = -1;
    return data;
}