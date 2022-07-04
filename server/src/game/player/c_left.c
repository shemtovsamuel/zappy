/*
** EPITECH PROJECT, 2022
** c_left.c
** File description:
** c_left
*/

#include "game/player.h"

void c_left(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = LEFT;
    evt->user = user;
    evt->turn_left.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
