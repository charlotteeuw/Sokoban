/*
** EPITECH PROJECT, 2023
** $CHECK_ORIGINAL
** File description:
** Checks original map
*/

#include "../include/sokoban.h"

void increment_boxes(map_t *map, int *nb_boxes, int i, int j)
{
    if (map->real_map[i][j] == 'X')
        (*nb_boxes)++;
}

int number_of_boxes(map_t *map)
{
    int nb_boxes = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            increment_boxes(map, &nb_boxes, i, j);
        }
    }
    return nb_boxes;
}

void in_if(map_t *map, int *nb_locations, int i, int j)
{
    if (map->original_map[i][j] == 'O')
        (*nb_locations)++;
}

int number_of_locations(map_t *map)
{
    int nb_locations = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            in_if(map, &nb_locations, i, j);
        }
    }
    return nb_locations;
}

void copy_real_map(map_t *map, int number_lines)
{
    map->real_map = malloc(sizeof(char *) * number_lines);
    for (int i = 0; i < number_lines; i++) {
        map->real_map[i] = malloc(sizeof(char)
    * count_nb_columns(map->map[i]));
        for (int j = 0; j < count_nb_columns(map->map[i]); j++) {
            map->real_map[i][j] = map->map[i][j];
        }
    }
}
