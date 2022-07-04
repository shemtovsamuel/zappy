/*
** EPITECH PROJECT, 2022
** my_teams server
** File description:
** check if we have new client or message
*/

#include "../../include/server.h"
#include "../../include/comp/create_message.h"
#include "game/event_to_do.h"
#include "game/player.h"
#include <stdio.h>

static void delete_related_event(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *temp;

    for (int i = 0; i < linked_list_get_size(serv_info->data.event_registered); i++) {
        temp = linked_list_get_elem_at_position(serv_info->data.event_registered, i);
        if (temp->user->player.player_number == user->player.player_number) {
            linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
            i--;
        }
    }
}

static void close_client(server_info_t *serv_info, user_t *user, int i)
{
    team_t *team;

    if (close(user->socket) != 0) {
        perror("close");
        return;
    }
    printf("close\n");
    if (user->user_type == PLAYER) {
        team = get_team_from_nb(serv_info, user);
        remove_player_from_tile(
            &serv_info->data.map.map[user->player.pos_y][user->player.pos_x],
            user);
        delete_related_event(serv_info, user);
        team->player_alive--;
    }
    linked_list_del_elem_at_position(&serv_info->user_list, i);
}

static int client_read(server_info_t *serv_info, user_t *user, int i)
{
    int size;

    memset(serv_info->buf, 0, MAX_BUF_SIZE);
    size = read(user->socket, serv_info->buf, MAX_BUF_SIZE);
    if (size <= 0) {
        close_client(serv_info, user, i);
        return -1;
    }
    do_cmd(serv_info, serv_info->buf, user);
    return 0;
}

void check_read(server_info_t *serv_info, fd_set r_list)
{
    user_t *temp;

    if (FD_ISSET(serv_info->socket, &r_list))
        new_client(serv_info);
    for (int i = 0; i < linked_list_get_size(serv_info->user_list); i++) {
        temp = linked_list_get_elem_at_position(serv_info->user_list, i);
        if (FD_ISSET(temp->socket, &r_list))
            i += client_read(serv_info, temp, i);
    }
}