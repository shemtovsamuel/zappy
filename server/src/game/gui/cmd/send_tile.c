/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** bct
*/

#include "game/gui.h"
#include "comp/create_message.h"
#include "comp/quick_message.h"
#include "comp/int_to_str.h"

void send_tile(server_info_t *serv, user_t *usr, int x, int y)
{
    char *message = malloc(sizeof(char) * 4);

    memset(message, 0, sizeof(char) * 4);
    strcat(message, "bct\0");
    message = add_number_to_msg(message, x);
    message = add_number_to_msg(message, y);
    for (int i = 0; i < RESSOURCE_SIZE; i++) {
        message = add_number_to_msg(message,
            serv->data.map.map[y][x].ressource[i]);
    }
    message = add_end_to_msg(message);
    create_message(usr, message);
    free(message);
}