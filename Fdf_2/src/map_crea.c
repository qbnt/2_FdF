/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:21:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 15:10:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	mesure_map(t_map *map, int fd);
void	save_map(t_map *map, int fd);
void	set_value(t_map *map, char *line);

/***********************************************************/

void	create_map(t_map *map, char *s)
{
	mesure_map(map, open(s, O_RDONLY));
	save_map(map, open(s, O_RDONLY));
}

void	mesure_map(t_map *map, int fd)
{
	char	*str;

	if (fd == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (!map->max_x)
			map->max_x = ft_count_wrd_sep(str, ' ') - 1;
		map->max_y ++;
		free(str);
	}
	close(fd);
}

void	save_map(t_map *map, int fd)
{
	char	*line;

	map->map = ft_calloc(map->max_y, sizeof(int *));
	map->color_map = ft_calloc(map->max_y, sizeof(int *));
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		map->map[map->i.y] = ft_calloc(map->max_x, sizeof(int));
		map->color_map[map->i.y] = ft_calloc(map->max_x, sizeof(int));
		set_value(map, line);
		free(line);
		map->i.y ++;
	}
	map->pad = map->max - map->min;
	map->i.y = 0;
	close(fd);
}

void	set_value(t_map *map, char *str)
{
	char	**elems;

	elems = ft_split(str, ' ');
	while (map->i.x < map->max_x)
	{
		map->map[map->i.y][map->i.x] = ft_atoi(elems[map->i.x]);
		if (!ft_strchr(elems[map->i.x], ','))
			map->color_map[map->i.y][map->i.x] = color(1, "FFFFFF");
		else
		{
			map->color = 1;
			map->color_map[map->i.y][map->i.x] = color(0, elems[map->i.x]);
		}
		free(elems[map->i.x]);
		map->i.x ++;
	}
	if (elems[map->i.x])
		free(elems[map->i.x++]);
	if (ft_max(map->map[map->i.y], map->max_x) > map->max)
		map->max = ft_max(map->map[map->i.y], map->max_x);
	if (ft_min(map->map[map->i.y], map->max_x) > map->min)
		map->min = ft_min(map->map[map->i.y], map->max_x);
	free(elems[map->i.x]);
	free(elems);
	map->i.x = 0;
}
