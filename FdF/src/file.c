/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/23 16:21:47 by qbanet           ###   ########.fr       */
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

}

void	create_map(t_map *map, char *s)
{
	int		fd;

	ft_count(s, map);
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_OPEN);
	ft_pars_map(fd, map);
	if (close(fd) == -1)
		return ;
}
