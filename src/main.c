/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-chloe.camus
** File description:
** main
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "myworld.h"

bool check_env(char **env)
{
    if (env == NULL)
        return false;
    for (int i = 0; env[i]; i += 1) {
        if (my_strncmp(env[i], "DISPLAY", 7) == '=') {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[], char **env)
{
    if (check_env(env) != true)
        return 84;
    if (argc == 1)
        return launch();
    else if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return display_info();
    display_info();
    return 84;
}
