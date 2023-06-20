/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/20 21:54:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_window(t_3d *obj)
{
	obj->e.mlx = mlx_init();
	if (obj->e.mlx == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	obj->e.win = mlx_new_window(obj->e.mlx, WIDTH, HEIGHT,
			"Fil de Fer Aka FdF");
	if (obj->e.win == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	obj->e.img = mlx_new_image(obj->e.mlx, WIDTH, HEIGHT);
	if (obj->e.img == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	return (0);
}

void	ft_close_mlx(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
}

int	ft_mlx(t_3d *obj)
{
	ft_init_window(obj);
	mlx_key_hook(obj->e.win, &key_hook, obj);
	obj->sprite.ptr = mlx_xpm_file_to_image(obj->e.mlx, "loading.xpm",
			&obj->sprite.x, &obj->sprite.y);
	obj->sprite.pixels = mlx_get_data_addr(obj->sprite.ptr, &obj->sprite.bpp,
			&obj->sprite.size, &obj->sprite.endian);
	mlx_put_image_to_window(obj->e.mlx, obj->e.win, obj->sprite.ptr,
			(WIDTH - obj->sprite.x)/2, (HEIGHT - obj->sprite.y)/2);
	mlx_loop(obj->e.mlx);
	return (0);
}
