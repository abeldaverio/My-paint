/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** dup
*/

#include <stdlib.h>

static int my_strlen(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

static void my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
}

char *my_strdup(const char *str)
{
    char *dup;

    if (str == NULL)
        return NULL;
    dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(dup, str);
    return dup;
}
