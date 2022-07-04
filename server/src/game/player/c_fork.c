/*
** EPITECH PROJECT, 2022
** c_fork.c
** File description:
** c_fork
*/

#include "game/player.h"

void c_fork(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = FORK;
    evt->user = user;
    evt->fork.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
