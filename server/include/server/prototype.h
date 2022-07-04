/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** header
*/

#ifndef PROTOTYPE_SERVER_HEADER
#define PROTOTYPE_SERVER_HEADER

#include "server_struct.h"

/* Prototypes */
int check_select(server_info_t *serv_info, fd_set *r_list, fd_set *w_list);

client_t accept_client(int socket);

int init_server(int port);

int send_message(user_t *user);

int new_client(server_info_t *serv_info);

void close_user(server_info_t *serv_info, user_t *user, int *i);

void do_cmd(server_info_t *serv_info, char *command, user_t *user);

void check_read(server_info_t *serv_info, fd_set r_list);

int init_serv_values(int socket, database_t data);

void check_write(server_info_t *serv_info, fd_set w_list);

void game_loop(server_info_t *);

#endif /*PROTOTYPE_SERVER*/