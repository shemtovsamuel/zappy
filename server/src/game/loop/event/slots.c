/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** slots
*/

#include "game/game_loop.h"

static void slots_exec(server_info_t *serv_info, event_to_do_t *event)
{
    team_t *team = get_team_from_nb(serv_info, event->user);
    int unused = team->player_limit - team->player_alive - 1;
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);

    if (unused < 0)
        unused = 0;
    sprintf(res, "%d\n", unused);
    create_message(event->user, res);
}

int event_slots(server_info_t *serv_info, event_to_do_t *event, int i)
{
    slots_exec(serv_info, event);
    linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
    return -1;
}