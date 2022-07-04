/*
** EPITECH PROJECT, 2022
** my_ftp server
** File description:
** send message to client
*/

#include "../../include/server.h"

int send_message(user_t *user)
{
    char *msg = linked_list_get_elem_at_front(user->answer);

    write(user->socket, msg, strlen(msg));
    linked_list_del_elem_at_front(&user->answer);
    return SUCCESS_EXIT;
}