/*
** EPITECH PROJECT, 2022
** c_incantation.c
** File description:
** c_incantation
*/

#include "game/player.h"

void c_incantation(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = INCANTATION;
    evt->user = user;
    evt->incantation.started = false;
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
