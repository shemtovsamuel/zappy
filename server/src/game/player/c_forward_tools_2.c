/*
** EPITECH PROJECT, 2022
** c_forward_tools_2.c
** File description:
** c_forward_tools_2
*/

#include "game/player.h"

void forward_north(player_t *player, tile_map_t *map)
{
    --player->pos_y;
    if (player->pos_y < 0)
        player->pos_y = map->size_y - 1;
}

void forward_east(player_t *player, tile_map_t *map)
{
    --player->pos_x;
    if (player->pos_x < 0)
        player->pos_x = map->size_x - 1;
}

void forward_south(player_t *player, tile_map_t *map)
{
    ++player->pos_y;
    if (player->pos_y > map->size_y - 1)
        player->pos_y = 0;
}

void forward_west(player_t *player, tile_map_t *map)
{
    ++player->pos_x;
    if (player->pos_x > map->size_x - 1)
        player->pos_x = 0;
}
