/*
** EPITECH PROJECT, 2022
** c_connect_nbr.c
** File description:
** c_connect_nbr
*/

#include "game/player.h"

void c_connect_nbr(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = CONNECT_NBR;
    evt->user = user;
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}
