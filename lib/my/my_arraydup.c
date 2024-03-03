/*
** EPITECH PROJECT, 2024
** arraydup
** File description:
** duplicate an array
*/

#include "header.h"
#include <stdlib.h>

char **my_arraydup(char **array)
{
    char **new = malloc(sizeof(char *) * (my_arraylen(array) + 1));
    int i;

    if (new == NULL)
        return NULL;
    for (i = 0; array[i] != NULL; i++) {
        new[i] = my_strdup(array[i]);
        if (new[i] == NULL)
            return NULL;
    }
    new[i] = NULL;
    return new;
}
