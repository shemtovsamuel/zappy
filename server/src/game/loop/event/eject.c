/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** eject
*/

#include "game/game_loop.h"

static void eject_exec(tile_map_t *map, user_t *user)
{
    if (linked_list_is_empty(
        map->map[user->player.pos_y][user->player.pos_x].player_list))
        create_message(user, "ko\n");
    else {
        switch (user->player.direction) {
            case NORTH:
                eject_north(map, &user->player);
                break;
            case EAST:
                eject_east(map, &user->player);
                break;
            case SOUTH:
                eject_south(map, &user->player);
                break;
            default:
                eject_west(map, &user->player);
        }
        create_message(user, "ok\n");
    }
}

int event_eject(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->eject.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        eject_exec(&serv_info->data.map, event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}