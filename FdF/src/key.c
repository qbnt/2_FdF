/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 09:49:53 by qbanet           ###   ########.fr       */
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
	if (keycode == R || keycode == G || keycode == B)
		ft_key_color(obj, keycode);
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		ft_key_move(obj, keycode);
	if (keycode == P)
		ft_key_proj(obj);
	if (keycode == I || keycode == O)
		ft_key_zoom(obj, keycode);
	if (keycode == M || keycode == L)
		ft_key_alt(obj, keycode);
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