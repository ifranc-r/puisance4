/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmerlot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 15:56:10 by qmerlot           #+#    #+#             */
/*   Updated: 2016/01/08 20:12:28 by qmerlot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_check_newline(char *line, char **ptr)
{
	int		n;
	char	*tmp;
	char	*ptrtmp;

	n = 0;
	if ((ptrtmp = ft_strchr(line, '\n')))
	{
		ptrtmp++;
		*ptr = ft_strdup(ptrtmp);
		tmp = ft_strdup(line);
		ft_bzero(line, ft_strlen(line));
		while (tmp[n] != '\0')
		{
			if (tmp[n] == '\n')
			{
				ft_strncpy(line, tmp, n);
				free(tmp);
				return (1);
			}
			n++;
		}
	}
	return (0);
}

int		ft_check_line(char **line)
{
	static char	rem[BUFF_SIZE + 1];
	char		*tmp;

	if (rem[0] != '\0')
	{
		free(*line);
		*line = ft_strdup(rem);
		ft_bzero(rem, BUFF_SIZE);
	}
	if (*line)
	{
		if (ft_check_newline(*line, &tmp) == 1)
		{
			ft_strcpy(rem, tmp);
			free(tmp);
			tmp = NULL;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*ltmp;

	if (fd < 0 || line == NULL || !(*line = ft_strnew(0)))
		return (-1);
	if (ft_check_line(line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ltmp = ft_strjoin(*line, buf);
		free(*line);
		*line = ltmp;
		if (ft_check_line(line) == 1)
			return (1);
	}
	if (buf[0] != '\0' && *line[0] != '\0')
		return (1);
	if (*line != NULL)
		ft_strdel(line);
	if (ret < 0)
		return (-1);
	return (0);
}
