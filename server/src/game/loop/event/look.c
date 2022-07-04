/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** look
*/

#include "game/game_loop.h"

void look_exec(tile_map_t *map, user_t *user)
{
    char *res = calloc(MAX_BUF_SIZE, sizeof(char));

    strcat(res, "[");
    switch (user->player.direction) {
        case 1:
            look_north(map, &user->player, &res);
            break;
        case 2:
            look_east(map, &user->player, &res);
            break;
        case 3:
            look_south(map, &user->player, &res);
            break;
        default:
            look_west(map, &user->player, &res);
    }
    strcat(res, " ]\n");
    create_message(user, res);
    free(res);
}

int event_look(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->look_around.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(7.0 / serv_info->data.freq)) {
        look_exec(&serv_info->data.map, event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return (0);
}