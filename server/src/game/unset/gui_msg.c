/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** GUI message for pnw
*/

#include "comp/create_message.h"
#include "comp/quick_message.h"
#include "comp/int_to_str.h"
#include "game/unset.h"

void send_pnw(server_info_t *serv, player_t new_player, char *team_name)
{
    char *message = malloc(sizeof(char) * 4);

    memset(message, 0, sizeof(char) * 4);
    strcat(message, "pnw\0");
    message = add_number_to_msg(message, new_player.player_number);
    message = add_number_to_msg(message, new_player.pos_x);
    message = add_number_to_msg(message, new_player.pos_y);
    message = add_number_to_msg(message, new_player.ressource[FOOD]);
    message = add_number_to_msg(message, new_player.level);
    message = add_char_to_msg(message, team_name);
    message = add_end_to_msg(message);
    create_gui_message(serv, message);
    free(message);
}