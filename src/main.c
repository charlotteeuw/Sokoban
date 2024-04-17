/*
** EPITECH PROJECT, 2023
** $MAIN
** File description:
** Main
*/

#include "../include/sokoban.h"

void main(int argc, char **argv)
{
    char *filepath = argv[1];
    map_t *map = malloc(sizeof(map_t));

    if (argc != 2)
        exit(84);
    if (argv[1][0] == '-' && argv[1][1] == 'h')
        information();
    open_file(filepath, map);
    return;
}
