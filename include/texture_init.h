/*
** EPITECH PROJECT, 2024
** texture
** File description:
** init
*/

#ifndef TEXTURE_INIT_H
    #define TEXTURE_INIT_H

    #include <stddef.h>

static const char *INIT_FLOOR_TEXTURE[] = {
    "./assets/sprites/static/grass.png",
    "./assets/sprites/static/sand.png",
    "./assets/sprites/static/water.png",
    NULL,
};

static const char *INIT_COLISION_TEXTURE[] = {
    "./assets/sprites/static/test.png",
	NULL,
};


static const char *INIT_STRUCTURE_TEXTURE[] = {
    "./assets/sprites/structure/house.png",
    "./assets/sprites/structure/bush.png",
    "./assets/sprites/structure/big_tree.png",
    "./assets/sprites/structure/small_tree.png",
    "./assets/sprites/structure/pink_flower.png",
    "./assets/sprites/structure/red_flower.png",
    "./assets/sprites/structure/blue_flower.png",
    "./assets/sprites/structure/grass1.png",
    "./assets/sprites/structure/rock.png",
    NULL,
};

static const char **INIT_TEXTURE_TAB[] = {
    INIT_FLOOR_TEXTURE,
    INIT_STRUCTURE_TEXTURE,
	INIT_COLISION_TEXTURE,
};

static const size_t TEXTURE_TAB_S = sizeof(INIT_TEXTURE_TAB) / sizeof(char *);

#endif
