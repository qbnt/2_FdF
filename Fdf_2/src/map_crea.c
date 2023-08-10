/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:21:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/10 15:53:53 by qbanet           ###   ########.fr       */
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
	ft_printf("Mesures de la map : ");
	ft_printf("Ligne = %d / Colonne = %d\n\n", map->nb_line, map->nb_colon);
	save_map(map, open(s, O_RDONLY));
	ft_printf("Visuel de la map :\n");
	ft_print_tab(map->map, map->nb_line, map->nb_colon);
	ft_printf("\nVisuel de la map couleur :\n");
	ft_print_tab(map->color_map, map->nb_line, map->nb_colon);
	ft_printf("\n");
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
		if (ft_count_wrd_sep(str, ' ') > map->nb_colon)
			map->nb_colon = ft_count_wrd_sep(str, ' ');
		map->nb_line ++;
		free(str);
	}
	close(fd);
}

void	save_map(t_map *map, int fd)
{
	char	*line;

	map->map = ft_calloc(map->nb_line, sizeof(int *));
	map->color_map = ft_calloc(map->nb_line, sizeof(int *));
	while (map->x < map->nb_line)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		map->map[map->x] = ft_calloc(map->nb_colon, sizeof(int));
		map->color_map[map->x] = ft_calloc(map->nb_colon, sizeof(int));
		set_value(map, line);
		free(line);
		map->x ++;
	}
	map->pad = map->max - map->min;
	map->x = 0;
	close(fd);
}

void	set_value(t_map *map, char *str)
{
	char	**elems;

	elems = ft_split(str, ' ');
	while (map->y < map->nb_colon)
	{
		map->map[map->x][map->y] = ft_atoi(elems[map->y]);
		if (!ft_strchr(elems[map->y], ','))
			map->color_map[map->x][map->y] = color(1, "FFFFFF");
		else
			map->color_map[map->x][map->y] = color(0, elems[map->y]);
		free(elems[map->y]);
		map->y ++;
	}
	if (ft_max(map->map[map->x], map->nb_colon) > map->max)
		map->max = ft_max(map->map[map->x], map->nb_colon);
	if (ft_min(map->map[map->x], map->nb_colon) > map->min)
		map->min = ft_min(map->map[map->x], map->nb_colon);
	free(elems[map->y]);
	free(elems);
	map->y = 0;
}
