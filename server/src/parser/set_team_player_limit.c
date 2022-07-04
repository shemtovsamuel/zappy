/*
** EPITECH PROJECT, 2022
** set_team_player_limit.c
** File description:
** set_team_player_limit
*/

#include "parser/parser.h"

void set_team_player_limit(database_t *data)
{
    team_t *temp;

    for (int i = 0; i < linked_list_get_size(data->team); i++) {
        temp = linked_list_get_elem_at_position(data->team, i);
        temp->player_limit = data->clientNb;
    }
}