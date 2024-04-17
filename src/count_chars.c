/*
** EPITECH PROJECT, 2023
** $COUNT_CHARS
** File description:
** Counts the number of certain chars
*/

#include "../include/sokoban.h"

int count_nb_lines(char *buffer)
{
    int nb_lines = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int count_nb_columns(char *buffer)
{
    int nb_columns = 0;

    for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        nb_columns++;
    }
    return nb_columns;
}

void display_map2(map_t *tab)
{
    clear();
    for (int i = 0; tab->map[i] != NULL; i++) {
        printw(tab->map[i]);
        printw("\n");
    }
    mvprintw(tab->position.player_y, tab->position.player_x, "P");
    refresh();
}

int display_map(map_t *tab)
{
    clear();
    for (int i = 0; tab->map[i] != NULL; i++) {
        printw(tab->map[i]);
        printw("\n");
    }
    mvprintw(tab->position.player_y, tab->position.player_x, "P");
    refresh();
    return key_pressed(tab);
}
