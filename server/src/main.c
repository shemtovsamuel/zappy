/*
** EPITECH PROJECT, 2022
** zappy server
** File description:
** main
*/

#include "server.h"
#include "parser/parser.h"

int main(int ac, char **av)
{
    database_t data = parser(av);
    int socket;

    if (!data_correctly_fill(&data))
        return ERROR_EXIT;
    set_team_player_limit(&data);
    socket = init_server(data.port);
    if (socket == ERROR)
        return ERROR_EXIT;
    if (init_serv_values(socket, data) == ERROR)
        return ERROR_EXIT;
    close(socket);
    return SUCCESS_EXIT;
}