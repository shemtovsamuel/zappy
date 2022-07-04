/*
** EPITECH PROJECT, 2022
** c_inventory.c
** File description:
** c_inventory
*/

#include "game/player.h"

void c_inventory(server_info_t *serv_info, user_t *user)
{
    event_to_do_t *evt = malloc(sizeof(event_to_do_t));

    evt->event = INVENTORY;
    evt->user = user;
    evt->inventory.clock = clock();
    linked_list_add_elem_at_back(&serv_info->data.event_registered, evt);
}