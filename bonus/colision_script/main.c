/*
** EPITECH PROJECT, 2024
** main
** File description:
** main for generator
*/

#include <stdlib.h>
#include "functions.h"

char **get_map(char const* const path)
{
	char *buffer = get_buffer(path);
	char **map = NULL;

	if (buffer == NULL)
		return NULL;
	map = format_line(buffer, "\n", "");
	free(buffer);
	return map;
}

int main(void)
{
	char **floor = get_map("./config/static.txt");
	char **structure = get_map("./config/structures.txt");
	int return_value = 0;

	if (floor == NULL || structure == NULL) {
		if (floor != NULL)
			free_array(floor);
		if (structure != NULL)
			free_array(structure);
		return (84);
	}
	if (!generate_colision((char const *const *const)floor, (char const *const *const)structure)) {
	    return_value = 84;
	}
	free_array(floor);
	free_array(structure);
	return return_value;
}
