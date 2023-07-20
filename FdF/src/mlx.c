/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 17:58:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mlx(t_3d *obj)
{
	obj->mlx_ptr = mlx_init();
	ft_window(obj);
	ft_init(obj);
	obj->win_ptr = mlx_new_window(obj->mlx_ptr, obj->win_width, obj->win_length,
			"Fil de Fer Aka FdF");
	mlx_key_hook(obj->win_ptr, &key_hook, obj);
	mlx_expose_hook(obj->win_ptr, &ft_expose_hook, obj);
	mlx_loop(obj->mlx_ptr);
	return (0);
}
