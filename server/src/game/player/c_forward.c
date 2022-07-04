/*
** EPITECH PROJECT, 2022
** c_forward.c
** File description:
** c_forward
*/

#include "game/player.h"

void c_forward(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = FORWARD;
    evt->user = user;
    evt->forward.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
