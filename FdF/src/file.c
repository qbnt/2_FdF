/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/22 16:53:14 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_count(char *s, t_3d *obj)
{
	char	*line;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd = -1)
		return (-1);
	ft_gnl(fd, &line);
	obj->map.nb_line++;
	obj->map.nb_colon = ft_count_wrd_sep(line, ' ');
	if (lien)
		free (line);
	while(ft_gnl(fd, &line))
	{
		obj->map.nb_line++;
		free (line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

static int		ft_pars_map(int fd, t_3d *obj)
{
	char	*line;
	char	**split_line;

	obj->map.map = ft_calloc(obj->map.x_max, obj->map.y_max);
	if (!obj->map.map)
		return (-1);
	while (ft_gnl(fd, &line))
	{
		obj->map.x = 0;
		split_line = ft_split(line, ' ');
		while(split_line[obj->map.x])
		{
			obj->map.map[obj->map.y][obj->map.x] =
				ft_atoi(split_line[obj->map.x]);
			free (split_line[obj->map.x]);
			obj->map.x++;
		}
		obj->map.max = ft_max(obj->map.map[obj->map.y], obj->map.nb_line);
		if (obj->map.max > obj->map.pad)
			obj->map.pad = obj->map.max;
		free (split_line);
		free (line);
		obj->map.y++;
	}
}

void	create_map(t_3d *obj, char *s)
{
	int		fd;

	ft_count(s, obj)
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_OPEN);
	ft_pars_map(fd, obj);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
