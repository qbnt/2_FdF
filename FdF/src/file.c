/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:28:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/22 15:19:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(t_3d *obj, char *s)
{
	int		fd;
	char	**line;

	line = NULL;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		ft_error(ERROR_OPEN);
	while (ft_gnl(fd, line))
	{
		ft_printf("%s\n", line++);
		obj->map.y_max ++;
	}
	close(fd);
}
