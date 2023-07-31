/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:21:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/31 16:04:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	mesure_map(t_map *map, int fd);
void	copy_map(t_map *map, int fd);

/***********************************************************/

void	create_map(t_map *map, char *s)
{
	mesure_map(map, open(s, O_RDONLY));
	copy_map(map, open(s, O_RDONLY));
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
		if (!map->nb_colon)
			map->nb_colon = ft_count_wrd_sep(str, ' ');
		map->nb_line ++;
		free(str);
	}
}

static void	map_mem(t_map *map)
{
	map->map = ft_calloc((map->nb_colon * map->nb_line), sizeof(int **));
	map->color_map = ft_calloc((map->nb_colon * map->nb_line),
			sizeof(t_color **));
}

static void	comput_map(t_map *map, char **split_line, int i)
{
	if (ft_strchr(split_line[i], ','))
		ft_color(map, ft_strchr(split_line, ',') + 1);
	else
		map->color_map[map->x][map->y]
			= ft_bzero(map->color_map[map->x][map->y], sizeof(t_color));
}

void	copy_map(t_map *map, int fd)
{
	char	*str;
	char	**split_line;
	int		i;

	i = 0;
	map_mem(map);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		split_line = ft_split(str, ' ');
		while (split_line[i])
		{
			comput_map(map, split_line, i ++);
			map->map[map->x][map->y] = ft_atoi(split_line[i++]);
			map->y ++;
		}
		map->x ++;
		free(split_line);
		free(str);
	}
}
