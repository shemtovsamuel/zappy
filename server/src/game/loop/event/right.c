/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** right
*/

#include "game/game_loop.h"

static void right_exec(user_t *user)
{
    --user->player.direction;
    if (user->player.direction < NORTH)
        user->player.direction = WEST;
    create_message(user, "ok\n");
}

int event_right(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->turn_right.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        right_exec(event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}