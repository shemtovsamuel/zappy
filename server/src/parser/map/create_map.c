/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** Map creation
*/

#include "parser/map_creation.h"
#include "comp/create_empty_struct.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

static int *item_to_spawn(tile_map_t *map)
{
    int *item = malloc(sizeof(int) * RESSOURCE_SIZE);

    for (int i = 0; i < RESSOURCE_SIZE; i++)
        item[i] = percentage_item[i] * map->size_x * map->size_y;
    return item;
}

static int fill_map_with_item(int *item, ressources_t type, tile_map_t *map)
{
    srand(time(NULL));
    int percentage = percentage_item[type] * 100;

    for (int y = 0; y < map->size_y; y++) {
        for (int x = 0; x < map->size_x; x++) {
            if ((*item) != 0 && (rand() % 101) < percentage) {
                map->map[y][x].ressource[type]++;
                (*item)--;
            }
        }
    }
    return (*item);
}

void fill_map(int **item, tile_map_t *map)
{
    for (int i = 0; i < RESSOURCE_SIZE; i++)
        (*item)[i] = fill_map_with_item(&(*item)[i], i, map);
}

int create_map(tile_map_t *map)
{
    int *item;

    if (map->size_x < 5 || map->size_y < 5)
        return ERROR;
    item = item_to_spawn(map);
    map->map = malloc(sizeof(tile_t *) * map->size_y);
    for (int i = 0; i < map->size_y; i++) {
        map->map[i] = malloc(sizeof(tile_t) * map->size_x);
        for (int j = 0; j < map->size_x; j++) {
            map->map[i][j].pos_x = j;
            map->map[i][j].pos_y = i;
            map->map[i][j].player_list = NULL;
            map->map[i][j].egg_list = NULL;
            for (int k = 0; k < RESSOURCE_SIZE; k++)
                map->map[i][j].ressource[k] = 0;
            // memset(map->map[i][j].ressource, 0, sizeof(int) * RESSOURCE_SIZE);
        }
    }
    fill_map(&item, map);
    free(item);
    map->refill_st = clock();
    return SUCCESS_EXIT;
}