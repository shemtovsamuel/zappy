/*
** EPITECH PROJECT, 2022
** c_eject.c
** File description:
** c_eject
*/

#include "game/player.h"

void c_eject(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = EJECT;
    evt->user = user;
    evt->eject.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
