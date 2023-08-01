/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:21:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/01 16:05:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	mesure_map(t_map *map, int fd);
void	save_map(t_map *map, int fd);
void	set_value(t_map *map, char *line);
void	set_color(t_map *map, char **elems);

/***********************************************************/

void	create_map(t_map *map, char *s)
{
	mesure_map(map, open(s, O_RDONLY));
	map->map = ft_calloc(map->nb_line, sizeof(int *));
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
		if (!map->nb_colon)
			map->nb_colon = ft_count_wrd_sep(str, ' ');
		map->nb_line ++;
		free(str);
	}
	close(fd);
}

void	save_map(t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		map->map[map->x] = ft_calloc(map->nb_colon, sizeof(int));
		line = get_next_line(fd);
		if (!line)
			break ;
		set_value(map, line);
		free(line);
	}
	close(fd);
}

void	set_value(t_map *map, char *str)
{
	char	**elems;
	int		i;

	i = 0;
	elems = ft_split(str, ' ');
	while (elems[i])
	{
		map->map[map->x][map->y] = ft_atoi(elems[i]);
		map->y ++;
		i ++;
	}
	set_color(map, elems);
	free(elems);
	map->x ++;
}

void	set_color(t_map *map, char **elems)
{
	int	i;

	i = 0;
	map->def_color = 0xFFFFFF;
	map->y = 0;
	while (elems[i])
	{
		if (ft_strchr(elems[i], ','))
			map->color_map[map->x][map->y] = color(0, elems[i]);
		else
			color(1, "FFFFFF");
		free(elems[i]);
		i ++;
	}
}
