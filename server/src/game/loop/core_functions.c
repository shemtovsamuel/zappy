/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** core_functions
*/

#include "game/game_loop.h"
#include "parser/map_creation.h"

void check_event(server_info_t *serv_info)
{
    event_to_do_t *temp;

    for (int j = 0; j < linked_list_get_size(serv_info->data.event_registered); j++) {
        temp = linked_list_get_elem_at_position(serv_info->data.event_registered, j);
        for (int i = 0; i < ACTION_SIZE - 1; i++) {
            if (temp->event == TAB_EVENT[i].evt) {
                j += TAB_EVENT[i].function(serv_info, temp, j);
            }
        }
    }
}

void eat_food(server_info_t *serv_info)
{
    user_t *temp;
    double sec;

    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (temp->user_type == PLAYER) {
            sec = (double)(clock() - temp->player.eat_st) / CLOCKS_PER_SEC;
            if (sec >= (double)(126.0 / serv_info->data.freq)) {
                if (temp->player.ressource[FOOD] > 0) {
                    --temp->player.ressource[FOOD];
                    temp->player.eat_st = clock();
                } else
                    create_message(temp, "dead\n");
            }
        }
    }
}

void hatch_eggs(server_info_t *serv_info)
{
    team_t *team;
    egg_t *egg;
    double sec;

    for (int i = 0; i < linked_list_get_size(serv_info->data.team); i++) {
        team = linked_list_get_elem_at_position(serv_info->data.team, i);
        for (int j = 0; j < linked_list_get_size(team->egg); j++) {
            egg = linked_list_get_elem_at_position(team->egg, j);
            sec = (double)(clock() - egg->hatch_st) / CLOCKS_PER_SEC;
            if (!egg->hatched && sec >= (double)(600.0 / serv_info->data.freq)) {
                ++team->player_limit;
                // egg->hatched = true;
                linked_list_add_elem_at_back(&serv_info->data.map.map[egg->pos_y][egg->pos_x].egg_list, egg);
                printf("hatched\n");
                linked_list_del_elem_at_position(&team->egg, j);
                --j;
            }
        }
    }
}

static int *item_to_refill(tile_map_t *map)
{
    int *items_remaining = calloc(RESSOURCE_SIZE, sizeof(int));
    int *items_refilled = calloc(RESSOURCE_SIZE, sizeof(int));
    int total_ressource;

    for (int i = 0; i < map->size_y; i++)
        for (int j = 0; j < map->size_x; j++)
            for (int k = 0; k < RESSOURCE_SIZE; k++)
                items_remaining[k] += map->map[i][j].ressource[k];
    for (int k = 0; k < RESSOURCE_SIZE; k++) {
        total_ressource = percentage_item[k] * map->size_x * map->size_y;
        items_refilled[k] = total_ressource - items_remaining[k];
        if (items_refilled[k] < 0)
            items_refilled[k] = 0;
    }
    return items_refilled;
}

void refill_map(server_info_t *serv_info)
{
    double sec = (double)(clock() - serv_info->data.map.refill_st) / CLOCKS_PER_SEC;
    int *items_refilled;

    if (sec >= (double)(20.0 / serv_info->data.freq)) {
        items_refilled = item_to_refill(&serv_info->data.map);
        fill_map(&items_refilled, &serv_info->data.map);
        free(items_refilled);
        serv_info->data.map.refill_st = clock();
    }
}
