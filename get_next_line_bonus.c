/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:58:43 by aakouhar          #+#    #+#             */
/*   Updated: 2023/12/18 11:27:01 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *ft_read(int fd, char *str)
{
    int     n_byte;
    char    *palestine;

    palestine = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!palestine)
	{
		free (str);
		return (NULL);
	}
    n_byte = 1;
    while (n_byte > 0)
    {       
        n_byte = read(fd, palestine, BUFFER_SIZE);
        if (n_byte == -1)
        {
			return (free (palestine),free(str),NULL);
        }
        palestine[n_byte] = '\0';
        str = ft_strjoin(str, palestine);
        if(ft_strchr(str, '\n') == 1)
            break;
    }
    return (free(palestine), str);
}

char    *ft_fill(char *str)
{
    int     i;
    char    *s;
    
    s = NULL;
    i = 0;
	if(!str || str[0] == '\0')
		return(NULL);
    while(str[i] != '\n' && str[i])
        i++;
    s = malloc(sizeof(char) * (i + 2));
    if (!s)
        return(free(str),NULL);
    i = 0;
    while(str[i] && str[i] != '\n')
    {
        s[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}

char    *new_save(char *str)
{
    char    *p;
    int     i;
    int     j;

    i = 0;
    p = NULL;
	if(!str || str[0] == '\0')
		return(free(str), NULL);
    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
    {
        free(str);
        return (NULL);
    }
    p = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!p)
        return (free(str), NULL);
    i++;
    j = 0;
    while (str[i])
    {
        p[j] = str[i];
        i++;
        j++;
    }
    p[j] = '\0';
    free(str);
    return (p);
}

char    *get_next_line(int fd)
{
    static char *save[OPEN_MAX];
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    save[fd] = ft_read(fd, save[fd]);
    line = ft_fill(save[fd]);
    save[fd] = new_save(save[fd]);
    return (line);
}