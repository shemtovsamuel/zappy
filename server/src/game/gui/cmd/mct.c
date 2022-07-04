/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** mct
*/

#include "game/gui.h"
#include "comp/create_message.h"

void command_mct(server_info_t *serv, char *cmd, user_t *usr)
{
    for (int x = 0; x < serv->data.map.size_x; x++)
        for (int y = 0; y < serv->data.map.size_x; y++)
            send_tile(serv, usr, x, y);
}