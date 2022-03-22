/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Espace de travail)
** File description:
** two_d_noise
*/

#include <stdlib.h>
#include "myworld.h"

double two_d_noise(double x, double y)
{
    double tmp = ((random_seed(x) + 1.) / 2) * (rand() % 8000);

    return (random_seed(tmp + y) + 1.) / 2;
}
