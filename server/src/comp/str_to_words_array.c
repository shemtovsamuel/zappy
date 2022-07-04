/*
** EPITECH PROJECT, 2022
** lib
** File description:
** str to array
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int take_word(int i, char const *str, char **array, int pos)
{
    int j = i;
    int k = 0;

    for (; str[j] != '\0' && str[j] != ' ' && str[j] != '\n'; j++);
    k = j - i;
    array[pos] = malloc(sizeof(char) * (k + 1));
    array[pos][k] = '\0';
    for (int l = 0; l < k; l++)
        array[pos][l] = str[i + l];
    return (j);
}

static int nb_word(char const *str)
{
    int i = 0;
    int nb = 0;
    int bool = 0;

    if (str == NULL)
        return (0);
    if (str[0] != ' ')
        nb++;
    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ' && bool == 0)
            bool = 1;
        if (str[i] != ' ' && bool == 1) {
            nb++;
            bool = 0;
        }
    }
    return (nb);
}

char **str_to_word_array(char const *str)
{
    int nb = nb_word(str);
    char **array = NULL;
    int pos = 0;

    if (nb == 0)
        return (array);
    array = malloc(sizeof(char *) * (nb + 1));
    array[nb] = NULL;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] != ' ') {
            i = take_word(i, str, array, pos);
            pos++;
        }
    }
    array[pos] = NULL;
    return (array);
}

void array_free(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}