/*
** EPITECH PROJECT, 2022
** my_ftp
** File description:
** server reading new client
*/

#include "server.h"
#include "comp/create_message.h"

int new_client(server_info_t *serv_info)
{
    client_t client = accept_client(serv_info->socket);
    user_t *client_struct = malloc(sizeof(user_t));
    char *new_message = calloc(9, sizeof(char));

    if (client_struct == NULL)
        return ERROR;
    client_struct->socket = client.nb;
    client_struct->listing_type = bwrite;
    client_struct->answer = NULL;
    client_struct->user_type = UNSET;
    strcpy(new_message, "WELCOME\n");
    linked_list_add_elem_at_back(&client_struct->answer, new_message);
    linked_list_add_elem_at_back(&serv_info->user_list, client_struct);
    return EXIT_SUCCESS;
}