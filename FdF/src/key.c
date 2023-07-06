/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/06 12:15:40 by qbanet           ###   ########.fr       */
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
		ft_free_map(obj->map.color_map, obj->map.nb_line);
		free(obj);
		exit(EXIT_SUCCESS);
	}
	ft_expose_hook(obj);
	return (0);
}

int	ft_expose_hook(t_3d *obj)
{
	obj->image.ptr = mlx_new_image(obj->e.mlx, WIDTH, HEIGHT);
	obj->image.pixels = mlx_get_data_addr(obj->image.ptr, &obj->image.bpp,
			&obj->image.size, &obj->image.endian);
	ft_draw(obj);
	mlx_put_image_to_window(obj->e.mlx, obj->e.win, obj->image.ptr, 0, 0);
	mlx_destroy_image(obj->e.mlx, obj->image.ptr);
	return (0);
}