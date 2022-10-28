/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:54:55 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/28 12:39:09 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 

# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*get_work_line(int fd, char *line);
char	*get_print_line(char *src);
char	*stock_end_line(char *work_line, char *print_line);
char	*pull_end_line(char *work_line);

int		ft_strlen_gnl(const char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_memchr_gnl(char *s, int c, size_t n);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		5
# endif

#endif 