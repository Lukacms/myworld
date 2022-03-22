/*
** EPITECH PROJECT, 2021
** B-MUL-100-BDX-1-1-myrunner-chloe.camus
** File description:
** display_info
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "myworld/game.h"

static char *load_help_in_mem(char const *filepath)
{
    int fd = -1;
    int status = -1;
    char *buffer = NULL;

    if (filepath == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (1000 + 1));
    status = read(fd, buffer, 1000);
    if (status < 0)
        return NULL;
    buffer[status] = '\0';
    close(fd);
    return buffer;
}

int display_info(void)
{
    char *info_program = load_help_in_mem(INFO_PROGRAM);

    if (info_program == NULL)
        return 84;
    my_putstr(info_program);
    free(info_program);
    return 0;
}
