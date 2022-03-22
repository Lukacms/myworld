/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** task07d06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            break;
    return (s1[i] - s2[i]);
}
