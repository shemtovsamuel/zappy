/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** unset
*/

#include "game/unset.h"
#include "server/prototype.h"
#include "comp/create_empty_struct.h"
#include "comp/create_message.h"
#include "comp/int_to_str.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "game/gui.h"

// static player_t create_player_from_egg(server_info_t *serv_info, team_t *team_struct)
// {
    // player_t player;
    // egg_t *temp;
    // int i = 0;
    // egg_t *egg;
// 
    // for (; i < linked_list_get_size(team_struct->egg); i++) {
        // egg = linked_list_get_elem_at_position(team_struct->egg, i);
        // if (egg->hatched)
            // break;
    // }
    // srand(time(NULL));
    // player.player_number = serv_info->nb;
    // player.level = 1;
    // player.pos_x = egg->pos_x;
    // player.pos_y = egg->pos_y;
    // player.team = team_struct->team_nb;
    // player.direction = rand() % 4 + 1;
    // player.eat_st = clock();
    // player.arg = malloc(sizeof(char) * MAX_BUF_SIZE);
    // player.ressource[FOOD] = 9;
    // player.ressource[LINEMATE] = 0;
    // player.ressource[DERAUMERE] = 0;
    // player.ressource[SIBUR] = 0;
    // player.ressource[MENDIANE] = 0;
    // player.ressource[PHIRAS] = 0;
    // player.ressource[THYSTAME] = 0;
    // for (int j = 0; j < linked_list_get_size(serv_info->data.map.map[egg->pos_y][egg->pos_x].egg_list); j++) {
        // temp = linked_list_get_elem_at_position(serv_info->data.map.map[egg->pos_y][egg->pos_x].egg_list, j);
        // if (temp == egg) {
            // linked_list_del_elem_at_position(&serv_info->data.map.map[egg->pos_y][egg->pos_x].egg_list, j);
            // break;
        // }
    // }
    // linked_list_del_elem_at_position(&team_struct->egg, i);
    // return player;
// }

static void fill_info(server_info_t *serv_info, team_t *team_struct,
    user_t *user)
{
    char *msg = malloc(sizeof(char) * MAX_BUF_SIZE);
    int temp = team_struct->player_limit - team_struct->player_alive;

    serv_info->nb++;
    team_struct->player_alive++;
    user->user_type = PLAYER;
    // if (!linked_list_is_empty(team_struct->egg))
        // user->player = create_player_from_egg(serv_info, team_struct);
    // else
        user->player = create_player(team_struct->team_nb, serv_info);
    sprintf(msg, "%d\n%d %d\n", (temp > 0) ? temp : 0,
    serv_info->data.map.size_x,
    serv_info->data.map.size_y);
    create_message(user, msg);
    linked_list_add_elem_at_back(
        &serv_info->data.map.map[user->player.pos_y]\
        [user->player.pos_x].player_list,
        user);
}

static bool same_team_name(server_info_t *serv_info, team_t *team_struct,
                            user_t *user)
{
    char *team = malloc((strlen(team_struct->name) + 2) * sizeof(char));

    sprintf(team, "%s\n", team_struct->name);
    if (strcmp(serv_info->buf, team) != 0) {
        free(team);
        return false;
    }
    free(team);
    fill_info(serv_info, team_struct, user);
    return true;
}

void call_unset(server_info_t *serv_info, char *command, user_t *user)
{
    if (strcmp(serv_info->buf, "gui\n") == 0) {
        user->user_type = GUI;
        command_bct(serv_info, command, user);
        command_mcz(serv_info, command, user);
        command_mct(serv_info, command, user);
        command_tna(serv_info, command, user);
        return;
    }
    for (int i = 0; i < linked_list_get_size(serv_info->data.team); i++) {
        if (same_team_name(serv_info, linked_list_get_elem_at_position(
            serv_info->data.team, i), user)) {
                return;
        }
    }
    printf("user '%i' tried to connect with '%s', but it's not a team\n",
    user->socket, serv_info->buf);
    create_message(user, "ko\n");
}