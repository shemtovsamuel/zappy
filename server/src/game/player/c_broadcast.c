/*
** EPITECH PROJECT, 2022
** c_broadcast.c
** File description:
** c_broadcast
*/

#include "game/player.h"

void c_broadcast(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = BROADCAST;
    evt->user = user;
    evt->broadcast.clock = clock();
    evt->broadcast.text = strdup(user->player.arg);
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
