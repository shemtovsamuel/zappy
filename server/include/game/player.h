/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** header
*/

#ifndef PLAYER_GAME_HEADER
#define PLAYER_GAME_HEADER

#include "../server.h"
#include "../comp/create_message.h"
#include "../comp/get_argument.h"
#include "../comp/get_team_from_nb.h"
#include "event_to_do.h"

typedef void (*f_ptr) (server_info_t *, user_t *);

typedef struct command_s {
    char *name;
    int length;
    f_ptr f;
} command_t;

typedef struct elevation_secret_s {
    int level;
    int nb_players;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} elevation_secret_t;

typedef struct trigonometric_dir_s {
    int direction;
    int top_left;
    int mid_left;
    int bot_left;
    int top_center;
    int mid_center;
    int bot_center;
    int top_right;
    int mid_right;
    int bot_right;
} trigonometric_dir_t;

void call_player(server_info_t *, char *, user_t *);

void c_forward(server_info_t *, user_t *);
void remove_player_from_tile(tile_t *, user_t *);
void add_player_to_tile(tile_t *, user_t *);
void forward_north(player_t *, tile_map_t *);
void forward_east(player_t *, tile_map_t *);
void forward_south(player_t *, tile_map_t *);
void forward_west(player_t *, tile_map_t *);

void c_right(server_info_t *, user_t *);

void c_left(server_info_t *, user_t *);

void c_look(server_info_t *, user_t *);
void look_north(tile_map_t *, player_t *, char **);
void look_south(tile_map_t *, player_t *, char **);
void look_east(tile_map_t *, player_t *, char **);
void look_west(tile_map_t *, player_t *, char **);

void c_inventory(server_info_t *, user_t *);

void c_broadcast(server_info_t *, user_t *);
void c_broadcast_exec(server_info_t *, player_t *);
int get_trigonometric_dir(tile_map_t *, player_t *, player_t *);

void c_connect_nbr(server_info_t *, user_t *);

void c_fork(server_info_t *, user_t *);

void c_eject(server_info_t *, user_t *);
void eject_north(tile_map_t *, player_t *);
void eject_east(tile_map_t *, player_t *);
void eject_south(tile_map_t *, player_t *);
void eject_west(tile_map_t *, player_t *);

void c_take(server_info_t *, user_t *);
bool take_object_1(tile_t *, char *, player_t *);

void c_set(server_info_t *, user_t *);
bool set_object_1(tile_t *, char *, player_t *);

void c_incantation(server_info_t *, user_t *);
bool check_incantation(tile_t *, user_t *);
bool check_available_players(tile_t *, int);
bool check_available_ressource(tile_t *, int);

static const char *IVT_BASE[] = {
    "food ",
    ", linemate ",
    ", deraumere ",
    ", sibur ",
    ", mendiane ",
    ", phiras ",
    ", thystame "
};

static const command_t CMD[] = {
    {"Forward", 7, &c_forward},
    {"Right", 5, &c_right},
    {"Left", 4, &c_left},
    {"Look", 4, &c_look},
    {"Inventory", 9, &c_inventory},
    {"Broadcast", 9, &c_broadcast},
    {"Connect_nbr", 11, &c_connect_nbr},
    {"Fork", 4, &c_fork},
    {"Eject", 5, &c_eject},
    {"Take", 4, &c_take},
    {"Set", 3, &c_set},
    {"Incantation", 11, &c_incantation},
};

static const elevation_secret_t ELEV_SECRET[] = {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 3, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 5, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1}
};

static const trigonometric_dir_t TRIG_DIR[] = {
    {1, 2, 3, 4, 1, 0, 5, 8, 7, 6},
    {2, 8, 1, 2, 7, 0, 3, 6, 5, 4},
    {3, 6, 7, 8, 5, 0, 1, 4, 3, 2},
    {4, 4, 5, 6, 3, 0, 7, 2, 1, 8}
};

#endif /*PLAYER_GAME*/ 