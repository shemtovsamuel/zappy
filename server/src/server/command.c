/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** command
*/

#include "../../include/server.h"

client_t accept_client(int socket)
{
    client_t client;
    client.socketSize = sizeof(client.clientSocket);

    client.nb = accept(socket, (struct sockaddr *)
        &client.clientSocket, &client.socketSize);
    if (client.nb == ERROR)
        perror("accept");
    return client;
}

static int biggest_fd(server_info_t *serv_info)
{
    int biggest = serv_info->socket;
    user_t *temp;

    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (temp->socket > biggest)
            biggest = temp->socket;
    }
    return biggest;
}

int check_select(server_info_t *serv_info, fd_set *r_list, fd_set *w_list)
{
    int info = 0;
    int fd_max = biggest_fd(serv_info);
    struct timeval time;

    time.tv_sec = 0;
    time.tv_usec = 0;
    info = select(fd_max + 1, r_list, w_list, NULL, &time);
    if (info == ERROR) {
        perror("select");
        return ERROR;
    }
    return info;
}