/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** incantation
*/

#include "game/game_loop.h"

static void incantation_exec_st(server_info_t *serv_info, tile_t *tile, 
    event_to_do_t *event)
{
    user_t *temp;
    event_to_do_t *evt;

    event->incantation.clock = clock();
    event->incantation.started = true;
    if (event->user->player.level < 8 &&
        check_available_players(tile, event->user->player.level) && 
        check_available_ressource(tile, event->user->player.level)) {
        create_message(event->user, "Elevation underway\n");
        event->incantation.success = true;
        for (int i = 0, j = 0; j < ELEV_SECRET[event->user->player.level - 1].nb_players - 1 && i < linked_list_get_size(tile->player_list); i++) {
            temp = linked_list_get_elem_at_position(tile->player_list, i);
            if (temp->player.player_number != event->user->player.player_number) {
                create_message(temp, "Elevation underway\n");
                evt = malloc(sizeof(event_to_do_t));
                evt->event = INCANTATION;
                evt->user = temp;
                evt->incantation.clock = event->incantation.clock;
                evt->incantation.started = event->incantation.started;
                evt->incantation.success = event->incantation.success;
                linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
                ++j;
            }
        }
    } else {
        create_message(event->user, "ko\n");
        event->incantation.success = false;
    }
}

static int incantation_exec_ed(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->incantation.clock) / CLOCKS_PER_SEC;
    char *res;

    if (sec >= (double)(300.0 / serv_info->data.freq)) {
        if (event->incantation.success) {
            event->user->player.level++;
            res = malloc(sizeof(char) * MAX_BUF_SIZE);
            sprintf(res, "Current level: %d\n", event->user->player.level);
            create_message(event->user, res);
            free(res);
        } else
            create_message(event->user, "ko\n");
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}

int event_incantation(server_info_t *serv_info, event_to_do_t *event, int i)
{
    if (!event->incantation.started) {
        printf("incantation\n");
        incantation_exec_st(serv_info, 
        &serv_info->data.map.map[event->user->player.pos_y][event->user->player.pos_x], 
        event);
        return 0;
    }
    return incantation_exec_ed(serv_info, event, i);
}