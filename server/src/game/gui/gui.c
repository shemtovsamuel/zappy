/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** gui
*/

#include "game/gui.h"
#include "comp/create_message.h"

static int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] == '\n')
            return 0;
        if (s1[i] == ' ' && s2[i] == '\n')
            return 0;
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return 0;
}

void call_gui(server_info_t *serv_info, char *command, user_t *user)
{
    for (int i = 0; i != TAB_SIZE; i++) {
        if (!my_strcmp(command, TAB_GUI[i].name)) {
            return TAB_GUI[i].function(serv_info, command, user);
        }
    }
    create_message(user, "ko\n");
}