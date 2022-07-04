/*
** EPITECH PROJECT, 2022
** c_incantation_tools.c
** File description:
** c_incantation_tools
*/

#include "game/player.h"

bool check_available_players(tile_t *tile, int level)
{
    int available_players = 0;
    user_t *temp;

    for (int i = 0; i < linked_list_get_size(tile->player_list); i++) {
        temp = linked_list_get_elem_at_position(tile->player_list, i);
        available_players += (temp->player.level == level);
    }
    return (available_players >= ELEV_SECRET[level - 1].nb_players);
}

bool check_available_ressource(tile_t *tile, int level)
{
    if (tile->ressource[LINEMATE] >= ELEV_SECRET[level - 1].linemate &&
        tile->ressource[DERAUMERE] >= ELEV_SECRET[level - 1].deraumere &&
        tile->ressource[SIBUR] >= ELEV_SECRET[level - 1].sibur &&
        tile->ressource[MENDIANE] >= ELEV_SECRET[level - 1].mendiane &&
        tile->ressource[PHIRAS] >= ELEV_SECRET[level - 1].phiras &&
        tile->ressource[THYSTAME] >= ELEV_SECRET[level - 1].thystame)
        return true;
    return false;
}
