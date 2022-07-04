/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** set
*/

#include "game/game_loop.h"

static void set_exec(tile_t *tile, event_to_do_t *event)
{
    if (!set_object_1(tile, event->set_event.name, &event->user->player))
        create_message(event->user, "ko\n");
    else
        create_message(event->user, "ok\n");
}

int event_set(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->set_event.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        set_exec(&serv_info->data.map.map[event->user->player.pos_y]\
        [event->user->player.pos_x], event);
        free(event->set_event.name);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}