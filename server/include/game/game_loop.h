/*
** EPITECH PROJECT, 2022
** ZAPPY
** File description:
** header
*/

#ifndef ZAPPY_GAME_LOOP_HEADER
#define ZAPPY_GAME_LOOP_HEADER

/* Includes */
#include "game/event_to_do.h"
#include "comp/create_message.h"
#include "comp/int_to_str.h"
#include "game/player.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Prototypes */
void check_event(server_info_t *serv_info);
void eat_food(server_info_t *serv_info);
void hatch_eggs(server_info_t *serv_info);
void refill_map(server_info_t *serv_info);

typedef int (*fp_evnt)(server_info_t *, event_to_do_t *, int);

int event_forward(server_info_t *serv_info, event_to_do_t *event, int i);
int event_left(server_info_t *serv_info, event_to_do_t *event, int i);
int event_right(server_info_t *serv_info, event_to_do_t *event, int i);
int event_look(server_info_t *serv_info, event_to_do_t *event, int i);
int event_inventory(server_info_t *serv_info, event_to_do_t *event, int i);
int event_broadcast(server_info_t *serv_info, event_to_do_t *event, int i);
int event_slots(server_info_t *serv_info, event_to_do_t *event, int i);
int event_fork(server_info_t *serv_info, event_to_do_t *event, int i);
int event_eject(server_info_t *serv_info, event_to_do_t *event, int i);
int event_take(server_info_t *serv_info, event_to_do_t *event, int i);
int event_set(server_info_t *serv_info, event_to_do_t *event, int i);
int event_incantation(server_info_t *serv_info, event_to_do_t *event, int i);

typedef struct cmd_event_s
{
    action_t evt;
    fp_evnt function;
} cmd_event_t;

static const cmd_event_t TAB_EVENT[] = {
    {FORWARD, event_forward},
    {RIGHT, event_right},
    {LEFT, event_left},
    {LOOK, event_look},
    {INVENTORY, event_inventory},
    {BROADCAST, event_broadcast},
    {CONNECT_NBR, event_slots},
    {FORK, event_fork},
    {EJECT, event_eject},
    {TAKE, event_take},
    {SET, event_set},
    {INCANTATION, event_incantation},
};

#endif /*ZAPPY_GAME_LOOP*/