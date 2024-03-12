/*
** EPITECH PROJECT, 2024
** my str len
** File description:
** counts char in str
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
