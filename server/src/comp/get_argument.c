/*
** EPITECH PROJECT, 2022
** get_argument.c
** File description:
** get_argument
*/

#include "server.h"

void get_argument(char *cmd, char **arg)
{
    char *clean_cmd = strtok(cmd, "\r\n\0");

    if (clean_cmd == NULL)
        return;
    for (int i = 0, j = 0; clean_cmd[i] != '\0'; i++) {
        if (clean_cmd[i] != ' ') {
            for (j = 0; clean_cmd[i + j] != '\0'; j++);
            (*arg) = malloc(sizeof(char) * (j + 1));
            (*arg) = strncpy((*arg), &clean_cmd[i], j);
            (*arg)[j] = '\0';
            break;
        }
    }
}
