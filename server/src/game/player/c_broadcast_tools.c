/*
** EPITECH PROJECT, 2022
** c_broadcast_tools.c
** File description:
** c_broadcast_tools
*/

#include "game/player.h"

static int get_x_dir_shortest_dist(tile_map_t *map, player_t *src, 
player_t *dst)
{
    int dist_x_regular = ABS(dst->pos_x - src->pos_x);
    int dist_x_opposite = ABS(map->size_x - dist_x_regular);
    int x_dir;

    if (src->pos_x < dst->pos_x)
        x_dir = -1;
    else if (src->pos_x > dst->pos_x)
        x_dir = 1;
    else
        x_dir = 0;
    if (dist_x_regular > dist_x_opposite)
        x_dir *= -1;
    return x_dir;
}

static int get_y_dir_shortest_dist(tile_map_t *map, player_t *src, 
player_t *dst)
{
    int dist_y_regular = ABS(dst->pos_y - src->pos_y);
    int dist_y_opposite = ABS(map->size_y - dist_y_regular);
    int y_dir;

    if (src->pos_y < dst->pos_y)
        y_dir = -1;
    else if (src->pos_y > dst->pos_y)
        y_dir = 1;
    else
        y_dir = 0;
    if (dist_y_regular > dist_y_opposite)
        y_dir *= -1;
    return y_dir;
}

static int find_trigonometric_dir(int direction, int trigonometric_dir)
{
    switch (trigonometric_dir) {
        case 11:
            return (TRIG_DIR[direction - 1].top_left);
        case 12:
            return (TRIG_DIR[direction - 1].top_center);
        case 13:
            return (TRIG_DIR[direction - 1].top_right);
        case 21:
            return (TRIG_DIR[direction - 1].mid_left);
        case 22:
            return (TRIG_DIR[direction - 1].mid_center);
        case 23:
            return (TRIG_DIR[direction - 1].mid_right);
        case 31:
            return (TRIG_DIR[direction - 1].bot_left);
        case 32:
            return (TRIG_DIR[direction - 1].bot_center);
        case 33:
            return (TRIG_DIR[direction - 1].bot_right);
    }
}

int get_trigonometric_dir(tile_map_t *map, player_t *src, player_t *dst)
{
    int x_dir_shortest_dist = get_x_dir_shortest_dist(map, src, dst);
    int y_dir_shortest_dist = get_y_dir_shortest_dist(map, src, dst);
    int trigonometric_dir = 0;

    if (x_dir_shortest_dist == -1)
        trigonometric_dir += 1;
    else if (x_dir_shortest_dist == 0)
        trigonometric_dir += 2;
    else
        trigonometric_dir += 3;
    if (y_dir_shortest_dist == -1)
        trigonometric_dir += 10;
    else if (y_dir_shortest_dist == 0)
        trigonometric_dir += 20;
    else
        trigonometric_dir += 30;
    return find_trigonometric_dir(dst->direction, trigonometric_dir);
}
