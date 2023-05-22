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

int		ft_count(char *s, t_3d *obj)
{
	char	*line;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd = -1)
		return (-1);
	ft_gnl(fd, &line);
	obj->map.y_max++;
	obj->map.x_max = ft_count_wrd_sep(line, ' ');
	if (lien)
		free (line);
	while(ft_gnl(fd, &line))
	{
		obj->map.y_max++;
		free (line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_pars_map(int fd, t_3d *obj)
{
	
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
