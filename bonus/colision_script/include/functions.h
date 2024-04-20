/*
** EPITECH PROJECT, 2024
** functions
** File description:
** functions
*/

#ifndef FUNCTIONS_H
    #define FUNCTIONS_H

    #include <stdbool.h>

char **format_line(char *line, const char *separators, const char *ignorer);
char *get_buffer(char const *const path);
bool generate_colision(char const *const *const floor, char const *const *const structure);
void free_array(char **array);

#endif
