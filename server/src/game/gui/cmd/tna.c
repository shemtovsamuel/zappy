/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** tna
*/

#include "game/gui.h"
#include "comp/create_message.h"

static void send_team_name(team_t *temp, user_t *usr)
{
    char *message = malloc(sizeof(char) * (strlen(temp->name) + 6));

    memset(message, 0, sizeof(char) * (strlen(temp->name) + 6));
    strcat(message, "tna ");
    strcat(message, temp->name);
    strcat(message, "\n\0");
    create_message(usr, message);
    free(message);
}

void command_tna(server_info_t *serv, char *cmd, user_t *usr)
{
    for (int i = 0; i < linked_list_get_size(serv->data.team); i++)
        send_team_name(linked_list_get_elem_at_position(serv->data.team, i),
            usr);
}