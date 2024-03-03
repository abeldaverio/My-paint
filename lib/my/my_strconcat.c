/*
** EPITECH PROJECT, 2024
** my str concatenate
** File description:
** concat
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

char *my_strconcat(const char *str1, const char *str2)
{
    char *new = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));

    my_strcpy(new, str1);
    my_strcpy(new + my_strlen(str1), str2);
    return new;
}
