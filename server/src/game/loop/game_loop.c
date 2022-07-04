/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** game Loop
*/

#include "game/game_loop.h"

void game_loop(server_info_t *serv_info)
{
    check_event(serv_info);
    eat_food(serv_info);
    hatch_eggs(serv_info);
    refill_map(serv_info);
}
