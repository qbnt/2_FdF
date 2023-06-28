/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/28 18:09:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_image(t_3d *obj)
{
	obj->image.ptr = mlx_new_image(obj->e.mlx, WIDTH, HEIGHT);
	if (obj->image.ptr == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	obj->image.pixels = mlx_get_data_addr(obj->image.ptr, &obj->image.bpp,
			&obj->image.size, &obj->image.endian);
	obj->loading.ptr = mlx_xpm_file_to_image(obj->e.mlx, "loading.xpm",
			&obj->loading.x, &obj->loading.y);
	obj->loading.pixels = mlx_get_data_addr(obj->loading.ptr, &obj->loading.bpp,
			&obj->loading.size, &obj->loading.endian);
	return (0);
}

int	ft_init_window(t_3d *obj)
{
	obj->e.mlx = mlx_init();
	if (obj->e.mlx == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	obj->e.win = mlx_new_window(obj->e.mlx, WIDTH, HEIGHT,
			"Fil de Fer Aka FdF");
	if (obj->e.win == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	return (0);
}

void	ft_close_mlx(t_env *e, t_3d *obj)
{
	mlx_destroy_image(e->mlx, obj->image.ptr);
	mlx_destroy_image(e->mlx, obj->loading.ptr);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
}

int	ft_mlx(t_3d *obj)
{
	ft_init_window(obj);
	ft_init_image(obj);
	mlx_key_hook(obj->e.win, &key_hook, obj);
	mlx_loop(obj->e.mlx);
	return (0);
}
