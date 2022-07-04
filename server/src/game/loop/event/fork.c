/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** fork
*/

#include "game/game_loop.h"

void fork_exec(server_info_t *serv_info, user_t *user)
{
    team_t *team = get_team_from_nb(serv_info, user);
    egg_t *egg = malloc(sizeof(egg_t));

    egg->pos_x = user->player.pos_x;
    egg->pos_y = user->player.pos_y;
    egg->team = user->player.team;
    egg->hatch_st = clock();
    egg->hatched = false;
    linked_list_add_elem_at_back(&team->egg, egg);
    create_message(user, "ok\n");
}

int event_fork(server_info_t *serv_info, event_to_do_t *event, int i)
{
    double sec = (double)(clock() - event->fork.clock) / CLOCKS_PER_SEC;

    if (sec >= (double)(42.0 / serv_info->data.freq)) {
        printf("fork\n");
        fork_exec(serv_info, event->user);
        linked_list_del_elem_at_position(&serv_info->data.event_registered, i);
        return -1;
    }
    return 0;
}