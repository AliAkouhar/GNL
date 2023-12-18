/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:56:26 by aakouhar          #+#    #+#             */
/*   Updated: 2023/12/18 09:57:56 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    static char *save;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    save = ft_read(fd, save);
    line = ft_fill(save);
    save = new_save(save);
    return (line);
}


/* #include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == s[i])
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	l_total;
	size_t	l_sub;

	if (!s)
		return (NULL);
	l_total = ft_strlen(s);
	l_sub = l_total - start;
	if (start > l_total || !len)
		return (ft_strdup("\n"));
	if (len > l_sub)
		len = l_sub;
	if (ft_strchr(s, '\n') != NULL && s[0] != '\n' && s[1] != '\0')
		len += 2;
	else
		len += 1;
	res = (char *)malloc(sizeof(char) * (len));
	if (!res)
		return (free(s), (NULL));
	ft_memmove(res, s + start, len);
	res[len - 1] = '\0';
	return (res);
}

char	*ft_rest(char *store)
{
	char	*nplace;
	char	*eplace;
	char	*rest;
	int		len;

	len = 0;
	nplace = ft_strchr(store, '\n');
	eplace = ft_strchr(store, '\0');
	if (!nplace || !eplace)
		return (free(store), (NULL));
	len = (eplace - nplace);
	if (len)
		rest = malloc(sizeof(char) * len);
	else
		return (free(store), (NULL));
	if (!rest)
		return (free(store), (NULL));
	ft_memmove(rest, nplace + 1, len);
	rest[len - 1] = '\0';
	return (free(store), (rest));
}

char	*get_store(int fd, char *store, char *res, char *buffer)
{
	int	check;

	check = 1;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(store), free(buffer), NULL);
	while (check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if ((check == 0 && ((!store) || store[0] == '\0')) || check == -1)
			return (free(store), free(buffer), NULL);
		buffer[check] = 0;
		res = ft_strdup(store);
		if (!res)
			return (free(store), free(buffer), (NULL));
		if (store)
			free(store);
		store = ft_strjoin(res, buffer);
		if (store[0] == '\0' && res)
			return (free(res), free(store), free(buffer), (NULL));
		free(res);
		if (ft_strchr(store, '\n') != NULL)
			break ;
	}
	return (free(buffer), store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*buffer;
	char		*res;
	int			check;

	res = NULL;
	check = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(store), NULL);
	store = get_store(fd, store, res, buffer);
	if (!store)
		return (NULL);
	if (store[0] == '\0')
		return (free(store), (NULL));
	res = ft_strchr(store, '\n');
	if (res)
		check = (res - store);
	else
		check = ft_strlen(store);
	res = ft_substr(store, 0, check);
	store = ft_rest(store);
	return (res);
} */