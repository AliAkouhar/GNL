#include "gnl.h"

char *ft_read_line(int fd, char *str)
{
    char    *buffer;
    int     n;

    n = 1;
    buffer = malloc(sizeof(char) * 1 + BUFFER_SIZE);
    if (!buffer)
        return (free(str), NULL);
    while (n > 0)
    {
        n = read_line(fd, buffer, BUFFER_SIZE);
        if (n == -1)
            return (free(buffer), free(str), NULL);
        buffer[n] = '\0';
        str = ft_strjoin(str, buffer);
        if (ft_strchr(str, '\n'))
            break ;
    }
    return (free(buffer), str);
}

char *ft_fill(char *str)
{
    int i;
    char    *ptr;

    i = 0;
    if (!str || str[0] == '\0')
        return (NULL);
    while (!str[i] && str[i] != '\0')
        i++;
    ptr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!ptr)
        return (NULL);
    i = 0;
    while (!str[i] && str[i] != '\0')
    {
        ptr[i] = str[i];
        i++;
    }
    if (str[++i] == '\n')
        ptr[i] = '\n';
    ptr[++i] = '\0';
    return (ptr);
}

char    *save_data(char *str)
{
    int i;
    int j;
    char    *save;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i] == '\n')
        i++;
    j = 0;
    while (str[i])
    {
        save[j] = str[i];
        j++;
        i++;
    }
    save[j] = '\0';
    return (save);
}

char *get_next_line(int fd)
{
    static char *str;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_line(fd, str);
    if (!str)
        return (NULL);
    line = ft_fill(str);
    str = save_data(str);
    return (line);
}