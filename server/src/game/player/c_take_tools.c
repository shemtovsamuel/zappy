/*
** EPITECH PROJECT, 2022
** c_take_tools.c
** File description:
** c_take_tools
*/

#include "game/player.h"

static bool take_object_3(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "mendiane") == 0 && tile->ressource[MENDIANE] > 0) {
        --tile->ressource[MENDIANE];
        ++player->ressource[MENDIANE];
        return true;
    }
    if (strcmp(name, "phiras") == 0 && tile->ressource[PHIRAS] > 0) {
        --tile->ressource[PHIRAS];
        ++player->ressource[PHIRAS];
        return true;
    }
    if (strcmp(name, "thystame") == 0 && tile->ressource[THYSTAME] > 0 ) {
        --tile->ressource[THYSTAME];
        ++player->ressource[THYSTAME];
        return true;
    }
    return false;
}

static bool take_object_2(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "linemate") == 0 && tile->ressource[LINEMATE] > 0) {
        --tile->ressource[LINEMATE];
        ++player->ressource[LINEMATE];
        return true;
    }
    if (strcmp(name, "deraumere") == 0 && tile->ressource[DERAUMERE] > 0) {
        --tile->ressource[DERAUMERE];
        ++player->ressource[DERAUMERE];
        return true;
    }
    if (strcmp(name, "sibur") == 0 && tile->ressource[SIBUR] > 0) {
        --tile->ressource[SIBUR];
        ++player->ressource[SIBUR];
        return true;
    }
    return take_object_3(tile, name, player);
}

bool take_object_1(tile_t *tile, char *name, player_t *player)
{
    if (strcmp(name, "food") == 0 && tile->ressource[FOOD] > 0) {
        --tile->ressource[FOOD];
        ++player->ressource[FOOD];
        return true;
    }
    return take_object_2(tile, name, player);
}
