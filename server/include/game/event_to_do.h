/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** header
*/

#ifndef EVENT_TO_DO_HEADER
#define EVENT_TO_DO_HEADER

#include <time.h>
#include "../server/server_struct.h"

void game_loop(server_info_t *);

typedef struct forward_event_s {
    clock_t clock;
} forward_event_t;

typedef struct turn_right_event_s {
    clock_t clock;
} turn_right_event_t;

typedef struct turn_left_event_s {
    clock_t clock;
} turn_left_event_t;

typedef struct look_around_event_s {
    clock_t clock;
} look_around_event_t;

typedef struct inventory_event_s {
    clock_t clock;
} inventory_event_t;

typedef struct broadcast_event_s {
    clock_t clock;
    char *text;
} broadcast_event_t;

typedef struct fork_event_s {
    clock_t clock;
} fork_event_t;

typedef struct eject_event_s {
    clock_t clock;
} eject_event_t;

typedef struct set_event_s {
    clock_t clock;
    char *name;
} set_event_t;

typedef struct take_object_event_s {
    clock_t clock;
    char *name;
} take_object_event_t;

typedef struct incantation_event_s {
    clock_t clock;
    bool started;
    bool success;
} incantation_event_t;

typedef struct event_to_do_s
{
    action_t event;
    user_t *user;
    union {
        forward_event_t forward;
        turn_right_event_t turn_right;
        turn_left_event_t turn_left;
        look_around_event_t look_around;
        inventory_event_t inventory;
        broadcast_event_t broadcast;
        fork_event_t fork;
        eject_event_t eject;
        take_object_event_t take_object;
        incantation_event_t incantation;
        set_event_t set_event;
    };
}event_to_do_t;


#endif /*EVENT_TO_DO*/