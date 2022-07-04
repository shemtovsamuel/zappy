/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** header
*/

#ifndef GAME_STRUCT_HEADER
#define GAME_STRUCT_HEADER

/* Includes */
#include "../../../libs/ll_lib/ll.h"
#include "../general_value.h"
#include <time.h>
#include <stdlib.h>

/* Enum */

typedef enum action_e {
    NONE = 0,
    FORWARD,
    RIGHT,
    LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT_NBR,
    FORK,
    EJECT,
    TAKE,
    SET,
    INCANTATION,
    ACTION_SIZE
} action_t;

typedef enum direction_s {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
} direction_t;

/* Const */
static const float percentage_item[7] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};

/* Module */
typedef enum ressources_s {
    FOOD = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    RESSOURCE_SIZE
} ressources_t;

typedef struct tile_s {
    int pos_x;
    int pos_y;
    list_t player_list;
    list_t egg_list;
    int ressource[RESSOURCE_SIZE];
} tile_t;

typedef struct tile_map_s {
    tile_t **map;
    int size_x;
    int size_y;
    clock_t refill_st;
} tile_map_t;

typedef struct player_s {
    int player_number;
    int level;
    int team;
    int pos_x;
    int pos_y;
    direction_t direction;
    clock_t eat_st;
    char *arg;
    int ressource[RESSOURCE_SIZE];
} player_t;

typedef struct egg_s {
    int pos_x;
    int pos_y;
    clock_t hatch_st;
    int team;
    bool hatched;
} egg_t;

typedef struct teams_s
{
    char *name;
    list_t egg;
    int team_nb;
    int player_limit;
    int player_alive;
} team_t;

typedef struct database_s
{
    tile_map_t map;
    list_t team;
    int port;
    int freq;
    int clientNb;
    list_t event_registered;
} database_t;

typedef struct gui_s {
} gui_t;

#endif /* GAME_STRUCT*/