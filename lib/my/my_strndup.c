/*
** EPITECH PROJECT, 2024
** my_strndup
** File description:
** my_str n dup
*/

#include <stdlib.h>
#include "header.h"

char *my_strndup(char *src, int n)
{
    int size = n > my_strlen(src) ? my_strlen(src) : n;
    char *dest = malloc(sizeof(char) * size + 1);

    for (int i = 0; i < size; ++i)
        dest[i] = src[i];
    dest[size] = '\0';
    return (dest);
}
