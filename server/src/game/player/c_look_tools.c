/*
** EPITECH PROJECT, 2022
** c_look_tools.c
** File description:
** c_look_tools
*/

#include "game/player.h"

static void look_object(tile_t *tile, char **res)
{
    for (int k = 0; k < linked_list_get_size(tile->player_list); k++)
        strcat(*res, " player");
    for (int k = 0; k < linked_list_get_size(tile->egg_list); k++)
        strcat(*res, " player");
    for (int k = 0; k < tile->ressource[FOOD]; k++)
        strcat(*res, " food");
    for (int k = 0; k < tile->ressource[LINEMATE]; k++)
        strcat(*res, " linemate");
    for (int k = 0; k < tile->ressource[DERAUMERE]; k++)
        strcat(*res, " deraumere");
    for (int k = 0; k < tile->ressource[SIBUR]; k++)
        strcat(*res, " sibur");
    for (int k = 0; k < tile->ressource[MENDIANE]; k++)
        strcat(*res, " mendiane");
    for (int k = 0; k < tile->ressource[PHIRAS]; k++)
        strcat(*res, " phiras");
    for (int k = 0; k < tile->ressource[THYSTAME]; k++)
        strcat(*res, " thystame");
}

void look_north(tile_map_t *map, player_t *player, char **res)
{
    for (int k = 0, i = 0; k <= player->level; k++) {
        i = player->pos_y - k;
        i = (i < 0) ? map->size_y - k : i;
        for (int m = -k, j = 0; m <= k; m++) {
            j = player->pos_x + m;
            j = (j < 0) ? map->size_x + m : j;
            j = (j > map->size_x - 1) ? -1 + m : j;
            look_object(&map->map[i][j], res);
            strcat(*res, (k == player->level && m == k) ? "" : ",");
        }
    }
}

void look_east(tile_map_t *map, player_t *player, char **res)
{
    for (int m = 0, j = 0; m <= player->level; m++) {
        j = player->pos_x - m;
        j = (j < 0) ? map->size_x - m : j;
        for (int k = m, i = 0; k >= -m; k--) {
            i = player->pos_y + k;
            i = (i > map->size_y - 1) ? -1 + k : i;
            i = (i < 0) ? map->size_y + k : i;
            look_object(&map->map[i][j], res);
            strcat(*res, (m == player->level && k == -m) ? "" : ",");
        }
    }
}

void look_south(tile_map_t *map, player_t *player, char **res)
{
    for (int k = 0, i = 0; k <= player->level; k++) {
        i = player->pos_y + k;
        i = (i > map->size_y - 1) ? -1 + k : i;
        for (int m = k, j = 0; m >= -k; m--) {
            j = player->pos_x + m;
            j = (j > map->size_x - 1) ? -1 + m : j;
            j = (j < 0) ? map->size_x + m : j;
            look_object(&map->map[i][j], res);
            strcat(*res, (k == player->level && m == -k) ? "" : ",");
        }
    }
}

void look_west(tile_map_t *map, player_t *player, char **res)
{
    for (int m = 0, j = 0; m <= player->level; m++) {
        j = player->pos_x + m;
        j = (j > map->size_x - 1) ? -1 + m : j;
        for (int k = m, i = 0; k >= -m; k--) {
            i = player->pos_y + k;
            i = (i < 0) ? map->size_y + k : i;
            i = (i > map->size_y - 1) ? -1 + k : i;
            look_object(&map->map[i][j], res);
            strcat(*res, (m == player->level && k == -m) ? "" : ",");
        }
    }
}
