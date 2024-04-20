/*
** EPITECH PROJECT, 2024
** floor size
** File description:
** floor case size
*/

#ifndef FLOOR_SIZE_H
    #define FLOOR_SIZE_H

    #include <SFML/Graphics.h>

static const sfVector2f FLOOR_SIZE[] = {
    {25.0, 25.0},
    {25.0, 25.0},
    {25.0, 25.0},
};

static const sfVector2f STRUCTURE_SIZE[] = {
    {175.0, 125.0},
    {25.0, 25.0},
    {175.0, 150.0},
    {75.0, 100.0},
    {25.0, 25.0},
    {25.0, 25.0},
    {25.0, 25.0},
    {25.0, 25.0},
    {25.0, 25.0},
};

static const sfVector2f COLISION_SIZE[] = {
    {25.0, 25.0},
};

static const sfVector2f *ELEMENTS_SIZE[] = {
    FLOOR_SIZE,
    STRUCTURE_SIZE,
    COLISION_SIZE,
};

#endif
