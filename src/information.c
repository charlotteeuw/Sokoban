/*
** EPITECH PROJECT, 2023
** $INFORMATION
** File description:
** Display information
*/

#include "../include/sokoban.h"

void information(void)
{
    my_putstr("USAGE");
    my_putchar('\n');
    my_putstr("     ./my_sokoban map");
    my_putchar('\n');
    my_putstr("DESCRIPTION");
    my_putchar('\n');
    my_putstr("     map file representing the warehouse map, ");
    my_putstr("containing '#' for walls, 'P' for the player, ");
    my_putstr("'X' for boxes and '0' for storage locations.");
    my_putchar('\n');
}
