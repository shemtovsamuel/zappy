/*
** EPITECH PROJECT, 2022
** c_right.c
** File description:
** c_right
*/

#include "game/player.h"

void c_right(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = RIGHT;
    evt->user = user;
    evt->turn_right.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
