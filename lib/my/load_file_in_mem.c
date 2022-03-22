/*
** EPITECH PROJECT, 2022
** my
** File description:
** load_file_in_mem
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char *load_file_in_mem(char const *filepath)
{
    int fd = -1;
    int status = -1;
    char *buffer = NULL;

    if (filepath == NULL)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return NULL;
    buffer = malloc(sizeof(char) * (10000 + 1));
    if (!buffer)
        return NULL;
    if ((status = read(fd, buffer, 10000)) < 0)
        return NULL;
    buffer[status] = '\0';
    close(fd);
    return buffer;
}
