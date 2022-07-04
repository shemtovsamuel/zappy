/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** quick message
*/

#include "comp/quick_message.h" 

char *add_end_to_msg(char *message)
{
    char *new_message = malloc(sizeof(char) * (strlen(message) + 2));

    memset(new_message, 0, sizeof(char) * (strlen(message) + 2));
    strcat(new_message, message);
    strcat(new_message, "\n\0");
    free(message);
    return new_message;
}

char *add_number_to_msg(char *message, int nbr)
{
    char *string = intostr(nbr);
    char *new_message = malloc(sizeof(char) * (strlen(message) +
        strlen(string) + 2));

    memset(new_message, 0, sizeof(char) * (strlen(message) +
        strlen(string) + 2));
    strcat(new_message, message);
    strcat(new_message, " \0");
    strcat(new_message, string);
    strcat(new_message, "\0");
    free(message);
    return new_message;
}

char *add_char_to_msg(char *message, char *string)
{
    char *new_message = malloc(sizeof(char) * (strlen(message) +
        strlen(string) + 2));

    memset(new_message, 0, sizeof(char) * (strlen(message) +
        strlen(string) + 2));
    strcat(new_message, message);
    strcat(new_message, " \0");
    strcat(new_message, string);
    strcat(new_message, "\0");
    free(message);
    return new_message;
}