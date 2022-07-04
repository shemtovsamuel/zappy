/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** forward
*/

#include "game/game_loop.h"

static void forward_exec(tile_map_t *map, user_t *user)
{
    remove_player_from_tile(
        &map->map[user->player.pos_y][user->player.pos_x], user);
    switch (user->player.direction) {
        case NORTH:
            forward_north(&user->player, map);
            break;
        case EAST:
            forward_east(&user->player, map);
            break;
        case SOUTH:
            forward_south(&user->player, map);
            break;
        default:
            forward_west(&user->player, map);
    }
    add_player_to_tile(
        &map->map[user->player.pos_y][user->player.pos_x], user);
    create_message(user, "ok\n");
}

int event_forward(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->forward.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        forward_exec(&serv_info->data.map, event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}
