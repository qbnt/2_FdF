/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 17:58:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_3d *obj)
{
	ft_printf("Touche appuyée: %d\n", keycode);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == R || keycode == G || keycode == B)
		ft_key_color(obj, keycode);
	else if (keycode == UP || keycode == DOWN || keycode == RIGHT
		|| keycode == LEFT)
		ft_key_move(obj, keycode);
	else if (keycode == P)
		ft_key_proj(obj);
	else if (keycode == I || keycode == O)
		ft_key_zoom(obj, keycode);
	else if (keycode == M || keycode == L)
		ft_key_alt(obj, keycode);
	else if (keycode == Z)
		ft_init(obj);
	ft_expose_hook(obj);
	return (0);
}

int	ft_expose_hook(t_3d *obj)
{
	obj->img_ptr = mlx_new_image(obj->mlx_ptr, obj->win_width,
			obj->win_length);
	obj->data = mlx_get_data_addr(obj->img_ptr, &obj->bpp,
			&obj->size_line, &obj->endian);
	ft_draw(obj);
	mlx_put_image_to_window(obj->mlx_ptr, obj->win_ptr, obj->img_ptr, 0, 0);
	mlx_destroy_image(obj->mlx_ptr, obj->img_ptr);
	return (0);
}