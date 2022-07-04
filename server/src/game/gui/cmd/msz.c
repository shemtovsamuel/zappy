/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** mcz
*/

#include "game/gui.h"
#include "comp/create_message.h"
#include "comp/int_to_str.h"

void command_mcz(server_info_t *serv, char *cmd, user_t *usr)
{
    char *X = intostr(serv->data.map.size_x);
    char *Y = intostr(serv->data.map.size_y);
    char *map_size = malloc(sizeof(char) * (strlen(X) + strlen(Y) + 7));

    memset(map_size, 0, sizeof(char) * (strlen(X) + strlen(Y) + 7));
    strcat(map_size, "msz ");
    strcat(map_size, X);
    strcat(map_size, " ");
    strcat(map_size, Y);
    strcat(map_size, "\n\0");
    create_message(usr, map_size);
    free(X);
    free(Y);
    free(map_size);
}