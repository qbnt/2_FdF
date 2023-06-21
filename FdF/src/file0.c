/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/21 07:45:07 by qbanet           ###   ########.fr       */
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
	ft_gnl(fd, &line, 0);
	map->nb_line++;
	map->nb_colon = ft_count_wrd_sep(line, ' ');
	if (line)
		free(line);
	while (ft_gnl(fd, &line, 0))
	{
		if (map->nb_colon != ft_count_wrd_sep(line, ' '))
			return (-1);
		map->nb_line++;
		free(line);
	}
	ft_gnl(fd, &line, 1);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

char	*ft_color(char *node)
{
	char	*str;

	str = ft_strchr(node, ',') + 1;
	return (ft_strdup(str));
}

int	*ft_compute_line(char *line, int nm_colon, char ***mappc, int j)
{
	char	**splited_line;
	char	**color_line;
	int		*inted_line;
	int		i;

	splited_line = ft_split(line, ' ');
	inted_line = (int *)ft_calloc(nm_colon, sizeof(int));
	color_line = (char **)ft_calloc(nm_colon, sizeof(char *));
	i = 0;
	while (splited_line[i])
	{
		if (ft_strchr(splited_line[i], ','))
			color_line[i] = ft_color(splited_line[i]);
		else
			color_line[i] = "0";
		inted_line[i] = ft_atoi(splited_line[i]);
		i ++;
	}
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
	char		***mappc;
	int			**mappi;
	int			i;

	i = 0;
	line = NULL;
	mappi = (int **)ft_calloc((map->nb_line), sizeof(int *));
	mappc = (char ***)malloc(map->nb_line * sizeof(char **));
	if (!mappi || !mappc)
		return (-1);
	while (ft_gnl(fd, &line, 0))
	{
		mappi[i] = ft_compute_line(line, map->nb_colon, mappc, i);
		free(line);
		i ++;
	}
	ft_gnl(fd, &line, 1);
	map->map = mappi;
	map->color_map = mappc;
	return (0);
}

int	create_map(t_map *map, char *s)
{
	int	fd;

	if (ft_form(s) == -1)
		return (ft_error(ERROR_FORMAT, NULL));
	if (ft_count(s, map) == -1)
		return (ft_error(ERROR_ARG, NULL));
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (ft_error(ERROR_OPEN, NULL));
	if (ft_pars_map(fd, map) == -1)
		return (ft_error(ERROR_MAP, NULL));
	if (close(fd) == -1)
		return (ft_error(ERROR_CLOSE, NULL));
	ft_printf("line : %d, colon : %d\n\nMap :\n", map->nb_line, map->nb_colon);
	ft_print_tab(map->map, map->nb_line, map->nb_colon);
	if (map->color_map)
	{
		ft_printf("\n\nColor map :\n");
		ft_print_color(map->color_map, map->nb_line, map->nb_colon);
	}
	ft_printf("\n\nMap Set !\n");
	return (0);
}
