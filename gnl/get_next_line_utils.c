#include "gnl.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strdup(char *str)
{
    int size;
    char    *dup;
    int i;

    size = ft_strlen(str);
    dup = malloc(sizeof(char) * size);
    if (!dup)
        return (NULL);
    i = -1;
    while (str[++i])
        dup[i] = str[i];
    i++;
    dup[i] = '\0';
    return (dup);
}

int find_new_line(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (str[i] == '\n')
            break ;
    }
    return (i);
}

int ft_strjoin(char *s1, char *s2)
{
    int i;
    int size1;
    int size2;
    char *str;

    if (!s1)
        return (s2);
    if (!s2)
        return (s1);
    size1 = ft_strlen(s1);
    size2 = ft_strlen(s2);
    str = malloc()
    i = 0;
    while ()
    
}