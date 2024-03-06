/*
** EPITECH PROJECT, 2024
** is same
** File description:
** is it the same color
*/

#include <SFML/Graphics.h>

sfBool is_same_color(sfColor first, sfColor second)
{
    if (first.a == second.a &&
        first.b == second.b &&
        first.g == second.g &&
        first.r == second.r)
        return sfTrue;
    return sfFalse;
}