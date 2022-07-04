/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** create_message
*/

#include "comp/create_message.h"
#include "server/server_struct.h"
#include <string.h>
#include <stdlib.h>

void create_message(user_t *user, char *message)
{
    char *to_send = malloc(strlen(message) + 1);

    strcpy(to_send, message);
    linked_list_add_elem_at_back(&user->answer, to_send);
    user->listing_type = bwrite;
}

void create_gui_message(server_info_t *info, char *message)
{
    user_t *temp;

    for (int i = 0; i < linked_list_get_size(info->user_list); i++) {
        temp = linked_list_get_elem_at_position(info->user_list, i);
        if (temp->user_type == GUI) 
            create_message(temp, message);
    }
}
