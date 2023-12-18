/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:52:38 by aakouhar          #+#    #+#             */
/*   Updated: 2023/12/18 10:01:57 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char    *get_next_line(int fd);
char    *new_save(char *str);
char    *ft_fill(char *str);
char    *ft_read(int fd, char *str);
char	*ft_strdup(char *str);
//utilschar	*ft_strdup(char *s1)
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_strchr(char *s, int c);

#endif




/* #ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char				*get_next_line(int fd);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
void				*ft_memmove(void *dst, const void *src, size_t len);
#endif */