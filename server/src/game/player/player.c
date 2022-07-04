/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** player
*/

#include "game/player.h"

void call_player(server_info_t *serv_info, char *command, user_t *user)
{
    int j = 0;

    for (; command[j] == ' '; j++);
    for (int i = 0; i < ACTION_SIZE - 1; ++i) {
        if (strncmp(&command[j], CMD[i].name, CMD[i].length) == 0) {
            memset(user->player.arg, 0, sizeof(char));
            get_argument(&command[j + CMD[i].length], &user->player.arg);
            (*CMD[i].f) (serv_info, user);
            return;
        }
    }
    create_message(user, "ko\n");
} 