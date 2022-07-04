/*
** EPITECH PROJECT, 2022
** c_eject_tools.c
** File description:
** c_eject_tools
*/

#include "game/player.h"

void eject_north(tile_map_t *map, player_t *player)
{
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);
    tile_t *tile = &map->map[player->pos_y][player->pos_x];
    user_t *temp;

    sprintf(res, "eject: %d\n", player->direction);
    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        if (&temp->player != player) {
            remove_player_from_tile(tile, temp);
            temp->listing_type = bwrite;
            --temp->player.pos_y;
            temp->player.pos_y = (temp->player.pos_y < 0) ?
            map->size_y - 1 : temp->player.pos_y;
            add_player_to_tile(&map->map[player->pos_y][player->pos_x], temp);
            create_message(temp, res);
            send_message(temp);
        }
    }
}

void eject_east(tile_map_t *map, player_t *player)
{
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);
    tile_t *tile = &map->map[player->pos_y][player->pos_x];
    user_t *temp;

    sprintf(res, "eject: %d\n", player->direction);
    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        if (&temp->player != player) {
            remove_player_from_tile(tile, temp);
            temp->listing_type = bwrite;
            --temp->player.pos_x;
            temp->player.pos_x = (temp->player.pos_x < 0) ?
            map->size_x - 1 : temp->player.pos_x;
            add_player_to_tile(&map->map[player->pos_y][player->pos_x], temp);
            create_message(temp, res);
            send_message(temp);
        }
    }
}

void eject_south(tile_map_t *map, player_t *player)
{
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);
    tile_t *tile = &map->map[player->pos_y][player->pos_x];
    user_t *temp;

    sprintf(res, "eject: %d\n", player->direction);
    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        if (&temp->player != player) {
            remove_player_from_tile(tile, temp);
            temp->listing_type = bwrite;
            ++temp->player.pos_y;
            temp->player.pos_y = (temp->player.pos_y > map->size_y - 1) ?
            0 : temp->player.pos_y;
            add_player_to_tile(&map->map[player->pos_y][player->pos_x], temp);
            create_message(temp, res);
            send_message(temp);
        }
    }
}

void eject_west(tile_map_t *map, player_t *player)
{
    char *res = malloc(sizeof(char) * MAX_BUF_SIZE);
    tile_t *tile = &map->map[player->pos_y][player->pos_x];
    user_t *temp;

    sprintf(res, "eject: %d\n", player->direction);
    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        if (&temp->player != player) {
            remove_player_from_tile(tile, temp);
            temp->listing_type = bwrite;
            ++temp->player.pos_x;
            temp->player.pos_x = (temp->player.pos_x > map->size_x - 1) ?
            0 : temp->player.pos_x;
            add_player_to_tile(&map->map[player->pos_y][player->pos_x], temp);
            create_message(temp, res);
            send_message(temp);
        }
    }
}
