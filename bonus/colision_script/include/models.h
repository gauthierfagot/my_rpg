/*
** EPITECH PROJECT, 2024
** models
** File description:
** models
*/

#ifndef MODELS_H
    #define MODELS_H

    #include <stddef.h>

static const char *const FLOOR_COLISION = "~ ";

typedef struct model_s {
	char character;
	char const *const *const model;
}model_t;

static char const *const HOUSE[] = {
	" ## ##",
	" #####",
	" #####",
	NULL,
};

static char const *const BIG_TREE[] = {
	"  ###",
	"  ###",
	NULL,
};

static char const *const TREE[] = {
	" #",
	NULL,
};

static const model_t STRUCT_ARRAY[] = {
	{
		'H',
		HOUSE
	},
	{
		'T',
	    BIG_TREE
	},
	{
		't',
	    TREE
	}
};

static const size_t STRUCT_ARRAY_SIZE = sizeof(STRUCT_ARRAY) / sizeof(model_t);

#endif
