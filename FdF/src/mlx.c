/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 11:45:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_close_mlx(t_env *e, t_3d *obj)
{
	mlx_destroy_image(e->mlx, obj->image.ptr);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_display(e->mlx);
	free(e->mlx);
}

int	ft_mlx(t_3d *obj)
{
	obj->e.mlx = mlx_init();
	ft_init(obj);
	obj->e.win = mlx_new_window(obj->e.mlx, WIDTH, HEIGHT,
			"Fil de Fer Aka FdF");
	mlx_key_hook(obj->e.win, &key_hook, obj);
	mlx_loop(obj->e.mlx);
	return (0);
}
