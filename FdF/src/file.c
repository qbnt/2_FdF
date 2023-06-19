/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 19:57:30 by qbanet           ###   ########.fr       */
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
		if (map->nb_colon != ft_count_wrd_sep(line, ' '))
			return (-1);
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
	int		**split_line;
	int		i;

	line = NULL;
	i = 0;
	split_line = (int **)ft_calloc((map->nb_line), sizeof(int *));
	if (!split_line)
		return (-1);
	while (ft_gnl(fd, &line))
	{
		split_line[i++] = ft_inted_line(line, map->nb_colon);
		free (line);
	}
	map->map = split_line;
	return (0);
}


int	create_map(t_map *map, char *s)
{
	int		fd;

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
	ft_printf("line : %d, colon : %d\n\n", map->nb_line, map->nb_colon);
	ft_print_tab(map->map, map->nb_line, map->nb_colon);
	ft_printf("\nMap Set !\n");
	return (0);
}
