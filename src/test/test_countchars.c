/*
** EPITECH PROJECT, 2023
** $TEST_COUNT_CHARS
** File description:
** Unit test
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(count_nb_lines, lines)
{
    char *buffer = "sokoban\ngame\n";
    int result = count_nb_lines(buffer);
    cr_assert_eq(result, 2);
}

Test(count_nb_lines, lines2)
{
    char *buffer = "";
    int result = count_nb_lines(buffer);
    cr_assert_eq(result, 0);
}

Test(count_nb_columns, columns)
{
    char *buffer = "Sokoban";
    int result = count_nb_columns(buffer);
    cr_assert_eq(result, 7);
}

Test(count_nb_columns, columns2)
{
    char *buffer = "";
    int result = count_nb_columns(buffer);
    cr_assert_eq(result, 0);
}
