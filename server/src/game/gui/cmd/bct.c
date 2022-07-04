/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** bct
*/

#include "game/gui.h"
#include "comp/create_message.h"
#include "comp/str_to_words_array.h"

void command_bct(server_info_t *serv, char *cmd, user_t *usr)
{
    char **array = str_to_word_array(cmd);
    int x;
    int y;

    if (!array[1] && !array[2]) {
        create_message(usr, "ko\n\0");
        return;
    }
    x = atoi(array[1]);
    y = atoi(array[2]);
    if (x >= serv->data.map.size_x || y >= serv->data.map.size_y) {
        create_message(usr, "ko\n\0");
        return;
    }
    send_tile(serv, usr, x, y);
    array_free(array);
}