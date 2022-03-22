/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** task01d06
*/

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0' && dest[i] != '\0'; i += 1)
        dest[i] = src[i];
    return dest;
}
