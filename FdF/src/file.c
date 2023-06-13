/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/13 12:28:25 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count(char *s, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	ft_gnl(fd, &line);
	map->nb_line++;
	map->nb_colon = ft_count_wrd_sep(line, ' ');
	if (line)
		free (line);
	while (ft_gnl(fd, &line))
	{
		map->nb_line++;
		free (line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

static int	ft_pars_map(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	int		i;

	line = NULL;
	i = 0;
	split_line = (char **)ft_calloc((map->nb_colon * map->nb_line),
			sizeof(char *));
	if (!split_line)
		return (-1);
	while (ft_gnl(fd, &line))
	{
		split_line[i++] = ft_strdup(line);
		free (line);
	}
	map->map = split_line;
	return (0);
}

int	ft_form(char *s)
{
	s = ft_strrchr(s, '.');
	if (ft_strlen(s) != 4)
		return (-1);
	if (ft_strncmp(s, ".fdf", 4) == 0)
		return (0);
	return (-1);
}

int	create_map(t_map *map, char *s)
{
	int		fd;

	if (ft_form(s) == -1)
		return (ft_error(ERROR_FORMAT));
	if (ft_count(s, map) == -1)
		return (ft_error(ERROR_ARG));
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (ft_error(ERROR_OPEN));
	if (ft_pars_map(fd, map) == -1)
		return (ERROR_MAP);
	if (close(fd) == -1)
		return (ft_error(ERROR_CLOSE));
	ft_printf("Map Set !\n");
	return (0);
}
