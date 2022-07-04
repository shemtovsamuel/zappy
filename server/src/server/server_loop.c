/*
** EPITECH PROJECT, 2022
** my_teams server
** File description:
** init et launch loop
*/

#include "../../include/server.h"

static fd_set create_list(server_info_t *serv_info, bool type)
{
    fd_set new;
    user_t *temp;

    FD_ZERO(&new);
    if (type == serv_info->bsocket)
        FD_SET(serv_info->socket, &new);
    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (temp->listing_type == type)
            FD_SET(temp->socket, &new);
    }
    return new;
}

static int server_loop(server_info_t *serv_info)
{
    fd_set r_list;
    fd_set w_list;
    int info;

    while (1) {
        r_list = create_list(serv_info, bread);
        w_list = create_list(serv_info, bwrite);
        info = check_select(serv_info, &r_list, &w_list);
        if (info == ERROR)
            return ERROR;
        if (info != 0) {
            check_read(serv_info, r_list);
            check_write(serv_info, w_list);
        }
        game_loop(serv_info);
        FD_ZERO(&r_list);
        FD_ZERO(&w_list);
    }
    return SUCCESS_EXIT;
}

int init_serv_values(int socket, database_t data)
{
    server_info_t *serv_info = malloc(sizeof(server_info_t));

    serv_info->socket = socket;
    serv_info->bsocket = bread;
    serv_info->user_list = NULL;
    serv_info->data = data;
    serv_info->buf = calloc(MAX_BUF_SIZE, sizeof(char));
    serv_info->nb = 0;
    return server_loop(serv_info);
}