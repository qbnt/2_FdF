/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/26 15:06:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_3d *obj)
{
	ft_printf("Touche appuyée: %d\n", keycode);
	if (keycode == ESC)
	{
		ft_close_mlx(&obj->e, obj);
		ft_free_map(obj->map.map, obj->map.nb_line);
		ft_free_color(obj->map.color_map, obj->map.nb_line, obj->map.nb_colon);
		free(obj);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_free_map(int **map, int nb_line)
{
	int	i;

	i = 0;
	while (i < nb_line)
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

void	ft_free_color(char ***color, int nb_line, int nb_col)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col)
		{
			free(color[i][j]);
			j ++;
		}
		free(color[i]);
		i ++;
	}
	free(color);
}
