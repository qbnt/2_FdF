/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/27 11:01:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count(char *s, t_map *map, int fd)
{
	char	*line;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = NULL;
	ft_gnl(fd, &line, 0);
	map->nb_line++;
	map->nb_colon = ft_count_wrd_sep(line, ' ');
	if (line)
		free(line);
	while (ft_gnl(fd, &line, 0))
	{
		if (map->nb_colon != ft_count_wrd_sep(line, ' '))
		{
			ft_gnl(fd, &line, 1);
			return (free(line), -1);
		}
		map->nb_line++;
		free(line);
	}
	ft_gnl(fd, &line, 1);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

static void	ft_convert(t_map *map, char**splited_line, int *color_line,
		int *inted_line)
{
	int	i;

	i = 0;
	while (splited_line[i])
	{
		if (ft_strchr(splited_line[i], ','))
		{
			map->color = 1;
			color_line[i] = ft_color(splited_line[i]);
		}
		else
			color_line[i] = 0;
		inted_line[i] = ft_atoi(splited_line[i]);
		i ++;
	}
}

int	*ft_compute_line(char *line, t_map *map, int **mappc, int j)
{
	char	**splited_line;
	int		*color_line;
	int		*inted_line;
	int		i;

	splited_line = ft_split(line, ' ');
	inted_line = (int *)ft_calloc(map->nb_colon, sizeof(int));
	color_line = (int *)ft_calloc(map->nb_colon, sizeof(int));
	ft_convert(map, splited_line, color_line, inted_line);
	i = 0;
	while (splited_line[i])
		free(splited_line[i ++]);
	free(splited_line);
	mappc += 0;
	mappc[j] = color_line;
	return (inted_line);
}

static int	ft_pars_map(int fd, t_map *map)
{
	char		*line;
	int			**mappc;
	int			**mappi;
	int			i;

	i = 0;
	line = NULL;
	map->color = 0;
	mappi = (int **)ft_calloc((map->nb_line), sizeof(int *));
	mappc = (int **)malloc(map->nb_line * sizeof(int *));
	if (!mappi || !mappc)
		return (-1);
	while (ft_gnl(fd, &line, 0))
	{
		mappi[i] = ft_compute_line(line, map, mappc, i);
		free(line);
		i ++;
	}
	ft_gnl(fd, &line, 1);
	map->map = mappi;
	map->color_map = mappc;
	return (0);
}

int	create_map(t_map *map, char *s, t_3d *obj)
{
	int	fd;

	if (ft_form(s) == -1)
		return (ft_error(ERROR_FORMAT, obj));
	if (ft_count(s, map, 0) == -1)
		return (ft_error(ERROR_INTRA_MAP, obj));
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (ft_error(ERROR_OPEN, obj));
	if (ft_pars_map(fd, map) == -1)
		return (ft_error(ERROR_MAP, obj));
	if (close(fd) == -1)
		return (ft_error(ERROR_CLOSE, obj));
	ft_printf("line : %d, colon : %d\n\nMap :\n", map->nb_line, map->nb_colon);
	ft_print_tab(map->map, map->nb_line, map->nb_colon);
	if (map->color)
	{
		ft_printf("\n\nColor map :\n");
		ft_print_color(map->color_map, map->nb_line, map->nb_colon);
	}
	ft_printf("\n\nMap Set !\n");
	return (0);
}
