/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_crea.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:21:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/08 17:07:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	mesure_map(t_map *map, int fd);
void	save_map(t_map *map, int fd);
void	set_value(t_map *map, char *line);

/***********************************************************/

void	create_map(t_map *map, char *s)
{
	ft_printf("Mesures de la map : ");
	mesure_map(map, open(s, O_RDONLY));
	ft_printf("Ligne = %d / Colonne = %d\n\n", map->nb_line, map->nb_colon);
	ft_printf("Visuel de la map :\n");
	save_map(map, open(s, O_RDONLY));
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

	map->map = ft_calloc(map->nb_line, sizeof(int *));
	map->color_map = ft_calloc(map->nb_line, sizeof(int *));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->map[map->x] = ft_calloc(map->nb_colon, sizeof(int));
		map->color_map[map->x] = ft_calloc(map->nb_colon, sizeof(int));
		set_value(map, line);
		free(line);
		map->x ++;
	}
	close(fd);
}

void	set_value(t_map *map, char *str)
{
	char	**elems;
	int		i;

	i = 0;
	map->y = 0;
	elems = ft_split(str, ' ');
	while (i < map->nb_colon)
	{
		ft_printf("i = %d, x = %d, y = %d\n", i, map->x, map->y);
		map->map[map->x][map->y] = ft_atoi(elems[i]);
		if (!ft_strchr(elems[i], ','))
			map->color_map[map->x][map->y] = color(1, "FFFFFF");
		else
			map->color_map[map->x][map->y] = color(0, elems[i]);
		free(elems[i]);
		map->y ++;
		i ++;
	}
	free(elems[i]);
	free(elems);
}
