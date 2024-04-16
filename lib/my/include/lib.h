/*
** EPITECH PROJECT, 2023
** lib
** File description:
** lib
*/

#ifndef LIB_
    #define LIB_

    #include <stddef.h>

char **format_line(char *line, const char *separators, const char *ignorers);
char *get_buffer(char const *const path);
void free_array(char **);
size_t my_arraylen(char const *const *const array);

#endif
