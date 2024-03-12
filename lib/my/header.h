/*
** EPITECH PROJECT, 2024
** header for libmy
** File description:
** sidefunctions
*/

#ifndef LIBMY_H
    #define LIBMY_H

int my_strlen(const char *);
int my_arraylen(char **);
void free_array(char **);
void my_putstr_error(const char *);
char *my_strconcat(const char *str1, const char *str2);
void my_strcpy(char *dest, const char *src);
char *my_strdup(const char *);
char **str_to_separators(char *str, const char *separators);
int my_strcmp(const char *, const char *);
int str_to_int(char *);
char *int_to_str(int);
char **my_arraydup(char **);
void my_putstr(char const *);

#endif
