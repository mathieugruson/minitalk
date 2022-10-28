/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgruson <mgruson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:41:57 by mgruson           #+#    #+#             */
/*   Updated: 2022/10/18 15:48:34 by mgruson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*pull_end_line(char *work_line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (work_line)
	{
		tmp = malloc(sizeof(char) * ((ft_strlen_gnl(work_line)) + 1));
		if (!tmp)
			return (NULL);
		while (work_line[i])
		{
			tmp[i] = work_line[i];
			i++;
		}
		tmp[i] = '\0';
	}
	if (!work_line)
	{
		tmp = malloc(sizeof(char) * 1);
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	return (tmp);
}

char	*stock_end_line(char *work_line, char *print_line)
{
	int			j;
	static char	tmp[BUFFER_SIZE + 1];
	int			print_line_len;

	j = 0;
	tmp[BUFFER_SIZE] = '\0';
	print_line_len = ft_strlen_gnl(print_line);
	if (!work_line)
		return (free(work_line), NULL);
	while (work_line[print_line_len])
		tmp[j++] = work_line[print_line_len++];
	tmp[j] = '\0';
	return (free(work_line), tmp);
}

char	*get_print_line(char *src)
{
	int		i;
	char	*tmp;
	int		len;

	len = ft_strlen_gnl(src);
	i = 0;
	if (!src || len == 0)
		return (NULL);
	while (src[i] != '\n' && i < len)
	{
		i++;
	}
	i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[i] = '\0';
	while (i > 0)
	{
		i--;
		tmp[i] = src[i];
	}
	return (tmp);
}

char	*get_work_line(int fd, char *work_line)
{
	char	*buf;
	int		buflen;

	buflen = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		return (NULL);
	}
	while (!ft_memchr_gnl(work_line, '\n', ft_strlen_gnl(work_line))
		&& buflen != 0)
	{
		buflen = read(fd, buf, (BUFFER_SIZE));
		if (buflen == -1)
			return (free(buf), NULL);
		buf[buflen] = '\0';
		if (buflen < ft_strlen_gnl(work_line) || buflen == 0)
			buf[buflen] = '\0';
		work_line = ft_strjoin_gnl(work_line, buf);
	}
	return (free(buf), work_line);
}

char	*get_next_line(int fd)
{
	static char	*work_line;
	char		*print_line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	work_line = pull_end_line(work_line);
	work_line = get_work_line(fd, work_line);
	print_line = get_print_line(work_line);
	work_line = stock_end_line(work_line, print_line);
	return (print_line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = 0;
// 	fd = open("map.ber", O_RDONLY);
// 	line = "start";
// 	while(line)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// } 