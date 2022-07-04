/*
** EPITECH PROJECT, 2022
** c_set.c
** File description:
** c_set
*/

#include "game/player.h"

void c_set(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = SET;
    evt->user = user;
    evt->set_event.clock = clock();
    evt->set_event.name = strdup(user->player.arg);
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
