/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 20:28:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_3d *obj)
{
	ft_printf("Touche appuyée: %d\n", keycode);
	if (keycode == ESC)
	{
		ft_close_mlx(&obj->e);
		ft_free_tab(obj->map.map, obj->map.nb_line);
		free(obj);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	ft_free_tab(int **map, int nb_line)
{
	int	i;

	i = 0;
	while(i < nb_line)
	{
		free(map[i]);
		i ++;
	}
	free(map);
}
