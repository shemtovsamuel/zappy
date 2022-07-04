/*
** EPITECH PROJECT, 2022
** c_take.c
** File description:
** c_take
*/

#include "game/player.h"

void c_take(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = TAKE;
    evt->user = user;
    evt->take_object.clock = clock();
    evt->take_object.name = strdup(user->player.arg);
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
