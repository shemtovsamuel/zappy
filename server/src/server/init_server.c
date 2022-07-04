/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** init server
*/

#include "../../include/server.h"

static int create_socket(void)
{
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);

    if (mySocket == ERROR) {
        perror("socket can't be load");
        return ERROR;
    }
    return mySocket;
}

static int socket_configuration(int mySocket, int port)
{
    struct sockaddr_in mySocketInfo;

    mySocketInfo.sin_family = AF_INET;
    mySocketInfo.sin_port = htons(port);
    mySocketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(mySocket, (const struct sockaddr *)
        &mySocketInfo, sizeof(mySocketInfo)) == ERROR) {
        perror("bind");
        return ERROR;
    }
    return SUCCESS_EXIT;
}

static int init_listen(int socket)
{
    if (listen(socket, 100) == ERROR) {
        perror("listen");
        return ERROR_EXIT;
    }
    return SUCCESS_EXIT;
}

int init_server(int port)
{
    int socket = create_socket();

    if (socket == ERROR)
        return ERROR;
    if (socket_configuration(socket, port) == ERROR)
        return ERROR;
    if (init_listen(socket) == ERROR)
        return ERROR;
    printf("Port : %i\n", port);
    return socket;
}