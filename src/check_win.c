/*
** EPITECH PROJECT, 2023
** $CHECK_WIN
** File description:
** Checks if the player won
*/

#include "../include/sokoban.h"

void increment_counter(int *counter, map_t *map, int i, int j)
{
    if (map->original_map[i][j] == 'O' && map->map[i][j] == 'X')
        (*counter)++;
}

int check_win(map_t *map)
{
    int nb_locations = number_of_locations(map);
    int counter = 0;

    for (int i = 0; map->map[i] != NULL; i++) {
        for (int j = 0; map->map[i][j] != '\0'; j++) {
            increment_counter(&counter, map, i, j);
        }
    }
    if (counter == nb_locations)
        return 1;
    else
        return 0;
}
