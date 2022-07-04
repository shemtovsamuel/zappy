/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** header
*/

#ifndef ZAPPY_PARSER_HEADER
#define ZAPPY_PARSER_HEADER

/* Includes */
#include "../server/server_struct.h"
#include <stdlib.h>
#include <stdio.h>

/* Prototypes */
database_t parser(char **av);
bool data_correctly_fill(database_t *data);
void set_team_player_limit(database_t *data);

typedef int (*fp)(char **, int, database_t *);

int arg_p(char **av, int i, database_t *data);
int arg_x(char **av, int i, database_t *data);
int arg_y(char **av, int i, database_t *data);
int arg_n(char **av, int i, database_t *data);
int arg_c(char **av, int i, database_t *data);
int arg_f(char **av, int i, database_t *data);

static const int TAB_SIZE = 6;

typedef struct arg_s
{
    char *name;
    fp function;
} arg_t;

static const arg_t TAB[] = {
    {"-p", arg_p},
    {"-x", arg_x},
    {"-y", arg_y},
    {"-n", arg_n},
    {"-c", arg_c},
    {"-f", arg_f},
};

/* Modules */

#endif /*ZAPPY_PARSER*/