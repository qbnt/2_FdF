/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 15:00:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_window(t_3d *obj)
{
	obj->e.mlx = mlx_init();
	if (obj->e.mlx == NULL)
		return (ft_error(ERROR_MLX_CREA, obj));
	obj->e.win = mlx_new_window(obj->e.mlx, WIDTH, HEIGHT, "Fil de Fer Aka FdF");
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
	mlx_loop(obj->e.mlx);
	return (0);
}
