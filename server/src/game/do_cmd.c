/*
** EPITECH PROJECT, 2022
** server
** File description:
** check_cmd
*/

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game/gui.h"
#include "game/player.h"
#include "game/unset.h"

void do_cmd(server_info_t *serv_info, char *command, user_t *user)
{
    if (user->user_type == UNSET) {
        call_unset(serv_info, command, user);
    } else if (user->user_type == GUI) {
        call_gui(serv_info, command, user);
    } else {
        call_player(serv_info, command, user);
    }
}