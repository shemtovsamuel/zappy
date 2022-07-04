/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** header
*/

#ifndef GENERAL_VALUE_HEADER
#define GENERAL_VALUE_HEADER

    #define ABS(x) ((x < 0) ? (-x) : (x))
    #define MAX_BUF_SIZE 2048

/* const */
static const int ERROR = -1;
static const int ERROR_EXIT = 84;
static const int SUCCESS_EXIT = 0;

/* Module */
typedef struct vector2i_s
{
    int x;
    int y;
} vector2i_t;


#endif /*GENERAL_VALUE*/