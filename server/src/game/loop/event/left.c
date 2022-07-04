/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** left
*/

#include "game/game_loop.h"

static void left_exec(user_t *user)
{
    ++user->player.direction;
    if (user->player.direction > WEST)
        user->player.direction = NORTH;
    create_message(user, "ok\n");
}

int event_left(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->turn_left.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        left_exec(event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}