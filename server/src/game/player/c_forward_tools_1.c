/*
** EPITECH PROJECT, 2022
** c_forward_tools_1.c
** File description:
** c_forward_tools_1
*/

#include "game/player.h"

void remove_player_from_tile(tile_t *tile, user_t *user)
{
    user_t *temp;

    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        if (temp->player.player_number == user->player.player_number) {
            linked_list_del_elem_at_position(&tile->player_list, i);
            return;
        }
    }
}

void add_player_to_tile(tile_t *tile, user_t *user)
{
    linked_list_add_elem_at_back(&tile->player_list, user);
}
