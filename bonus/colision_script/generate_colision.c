/*
** EPITECH PROJECT, 2024
** generate colision
** File description:
** generate the colision file
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "models.h"

static size_t my_arraylen(char const *const *const array)
{
	size_t i = 0;

	while (array[i])
		++i;
	return i;
}

void free_array(char **array)
{
	for (size_t i = 0; array[i]; ++i)
		free(array[i]);
	free(array);
}

static char *init_string(size_t len) {
	char *str = calloc(sizeof(char), len + 1);

	if (str == NULL)
		return NULL;
	for (size_t i = 0; i < len; ++i) {
		str[i] = ' ';
	}
	return str;
}

static char **init_colision_array(char const *const *const floor, char const *const *const structure)
{
	size_t floor_len = my_arraylen((char const *const *const)floor);
	size_t structure_len = my_arraylen((char const *const *const)structure);
	char **colision = calloc(sizeof(char *),
	    (floor_len > structure_len) ? floor_len + 1 : structure_len + 1);

	if (colision == NULL)
		return NULL;
	for (size_t i = 0; i < floor_len || i < structure_len; ++i) {
		if (i >= floor_len) {
			colision[i] = init_string(strlen(structure[i]));
		} else if (i >= structure_len) {
			colision[i] = init_string(strlen(floor[i]));
		}
		if (i < floor_len && i < structure_len) {
			colision[i] = init_string((strlen(floor[i]) > strlen(structure[i])) ? strlen(floor[i]) : strlen(structure[i]));
		}
		if (colision[i] == NULL) {
			free_array(colision);
			return NULL;
		}
	}
	return colision;
}

static bool is_in_string(char c, char const *const str)
{
	for (size_t i = 0; str[i]; ++i)
		if (str[i] == c)
			return true;
	return false;
}

static void generate_floor_colision(char *const *const colision, char const *const *const floor)
{
	for (size_t i = 0; floor[i]; ++i) {
		for (size_t j = 0; floor[i][j]; ++j) {
			if (is_in_string(floor[i][j], FLOOR_COLISION))
				colision[i][j] = '#';
		}
	}
}

static void replace_colision(char *const *const colision, size_t i, size_t j, char const *const *const model)
{
	for (size_t k = 0; model[k]; ++k) {
		if ((int)(i - k) < 0)
			break;
		for (size_t z = 0; model[k][z] && colision[i][j + z]; ++z) {
			if (model[k][z] != ' ')
				colision[i - k][j + z] = model[k][z];
		}
	}
}

static void generate_struct_colision(char *const *const colision, char const *const *const structure)
{
	for (size_t i = 0; structure[i]; ++i) {
		for (size_t j = 0; structure[i][j]; ++j) {
		    for (size_t k = 0; STRUCT_ARRAY_SIZE > k; ++k)
				if (STRUCT_ARRAY[k].character == structure[i][j])
					replace_colision(colision, i, j, STRUCT_ARRAY[k].model);
		}
	}
}

static bool write_in_file(char const *const *const colision)
{
	FILE *fd = fopen("./config/colisions.txt", "w+");

	if (fd == NULL)
		return false;
	for (int i = 0; colision[i]; ++i) {
		fwrite(colision[i], sizeof(char), strlen(colision[i]), fd);
		fwrite("\n", sizeof(char), 1, fd);
	}
	fclose(fd);
	return true;
}

bool generate_colision(char const *const *const floor, char const *const *const structure)
{
	char **colision = init_colision_array(floor, structure);

	if (colision == NULL)
		return false;
	generate_floor_colision(colision, floor);
	generate_struct_colision(colision, structure);
	if (!write_in_file((char const *const *const)colision)) {
		free_array(colision);
		return false;
	}
	free_array(colision);
	return true;
}
