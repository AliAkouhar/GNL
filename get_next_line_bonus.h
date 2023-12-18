/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:58:36 by aakouhar          #+#    #+#             */
/*   Updated: 2023/12/18 11:28:17 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

char    *get_next_line(int fd);
char    *new_save(char *str);
char    *ft_fill(char *str);
char    *ft_read(int fd, char *str);
//utils
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_strchr(char *s, int c);

#endif