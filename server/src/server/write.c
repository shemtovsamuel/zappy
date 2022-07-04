/*
** EPITECH PROJECT, 2022
** my_teams server
** File description:
** check if need to send message to client or close one
*/

#include "../../include/server.h"

static int check_client(server_info_t *serv_info, user_t *user, int client)
{
    if (linked_list_is_empty(user->answer) == true) {
        user->listing_type = bread;
        return ERROR;
    }
    send_message(user);
    if (linked_list_is_empty(user->answer) == true)
        user->listing_type = bread;
    return EXIT_SUCCESS;
}

void check_write(server_info_t *serv_info, fd_set w_list)
{
    user_t *temp;

    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (FD_ISSET(temp->socket, &w_list)) {
            check_client(serv_info, temp, i);
        }
    }
}