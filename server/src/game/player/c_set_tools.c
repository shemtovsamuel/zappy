/*
** EPITECH PROJECT, 2022
** c_set_tools.c
** File description:
** c_set_tools
*/

#include "game/player.h"

bool set_object_3(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "mendiane") == 0 && player->ressource[MENDIANE] > 0) {
        --player->ressource[MENDIANE];
        ++tile->ressource[MENDIANE];
        return true;
    }
    if (strcmp(name, "phiras") == 0 && player->ressource[PHIRAS] > 0) {
        --player->ressource[PHIRAS];
        ++tile->ressource[PHIRAS];
        return true;
    }
    if (strcmp(name, "thystame") == 0 && player->ressource[THYSTAME] > 0 ) {
        --player->ressource[THYSTAME];
        ++tile->ressource[THYSTAME];
        return true;
    }
    return false;
}

bool set_object_2(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "linemate") == 0 && player->ressource[LINEMATE] > 0) {
        --player->ressource[LINEMATE];
        ++tile->ressource[LINEMATE];
        return true;
    }
    if (strcmp(name, "deraumere") == 0 && player->ressource[DERAUMERE] > 0) {
        --player->ressource[DERAUMERE];
        ++tile->ressource[DERAUMERE];
        return true;
    }
    if (strcmp(name, "sibur") == 0 && player->ressource[SIBUR] > 0) {
        --player->ressource[SIBUR];
        ++tile->ressource[SIBUR];
        return true;
    }
    return set_object_3(tile, name, player);
}

bool set_object_1(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "food") == 0 && player->ressource[FOOD] > 0) {
        --player->ressource[FOOD];
        ++tile->ressource[FOOD];
        return true;
    }
    return set_object_2(tile, name, player);
}
