/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** parser
*/

#include "parser/parser.h"
#include <string.h>

static bool is_cmd(char *str)
{
    if (str[0] == '-')
        return true;
    return false;
}

team_t *create_team(char *name, int i)
{
    team_t *team;

    team = malloc(sizeof(team_t) + 1);
    team->egg = NULL;
    team->name = name;
    team->player_alive = 0;
    team->team_nb = i;
    return team;
}

int arg_n(char **av, int i, database_t *data)
{
    int cmp = i;
    for (; av[i] && !is_cmd(av[i]); i++) {
        if (strcmp(av[i], "gui") == 0) {
            printf("can't name a team \"gui\"\n");
            return -1;
        }
        linked_list_add_elem_at_back(&data->team, create_team(av[i], i - cmp));
    }
    if (cmp == i) {
        printf("no argument for -f\n");
        return -1;
    }
    return i;
}