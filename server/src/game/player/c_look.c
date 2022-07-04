/*
** EPITECH PROJECT, 2022
** c_look.c
** File description:
** c_look
*/

#include "game/player.h"

void c_look(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = LOOK;
    evt->user = user;
    evt->look_around.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
