/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** empty struct
*/

#include "server/server_struct.h"
#include <global/struct.h>
#include <stdlib.h>

player_t create_player(const int team, server_info_t *serv_info)
{
    player_t player;

    srand(time(NULL));
    player.player_number = serv_info->nb;
    player.level = 1;
    player.pos_x = rand() % serv_info->data.map.size_x;
    player.pos_y = rand() % serv_info->data.map.size_y;
    player.team = team;
    player.direction = rand() % 4 + 1;
    player.eat_st = clock();
    player.arg = malloc(sizeof(char) * MAX_BUF_SIZE);
    player.ressource[FOOD] = 9;
    player.ressource[LINEMATE] = 0;
    player.ressource[DERAUMERE] = 0;
    player.ressource[SIBUR] = 0;
    player.ressource[MENDIANE] = 0;
    player.ressource[PHIRAS] = 0;
    player.ressource[THYSTAME] = 0;
    return player;
} 