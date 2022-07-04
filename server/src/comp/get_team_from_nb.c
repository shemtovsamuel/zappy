/*
** EPITECH PROJECT, 2022
** get_team_from_nb.c
** File description:
** get_team_from_nb
*/

#include "server/server_struct.h"

team_t *get_team_from_nb(server_info_t *serv_info, user_t *user)
{
    team_t *temp;

    for (int i = 0; i < linked_list_get_size(serv_info->data.team); i++) {
        temp = linked_list_get_elem_at_position(serv_info->data.team, i);
        if (temp->team_nb == user->player.team)
            return temp;
    }
    return NULL;
}
