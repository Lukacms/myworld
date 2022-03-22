/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** random_seed
*/

#include <stdlib.h>

double random_seed(double nbr)
{
    double random_seed = 0;

    random_seed = ((rand() % 100 + nbr) / 100);
    return random_seed;
}
