/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 17:43:13 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_window(t_ins *soft)
{
	soft->mlx_ptr = mlx_init();
	soft->win_ptr = mlx_new_window(soft->mlx_ptr, soft->win_wi,
			soft->win_he, "FdF");
	soft->img_ptr = mlx_new_image(soft->mlx_ptr, soft->win_wi, soft->win_he);
	mlx_loop(soft->mlx_ptr);
}

void	ft_close_window(t_ins *soft)
{
	mlx_destroy_image(soft->mlx_ptr, soft->img_ptr);
	mlx_destroy_window(soft->mlx_ptr, soft->win_ptr);
	mlx_destroy_display(soft->mlx_ptr);
}

int	ft_close_hook(int keycode, void *context)
{
	(void)context;
	if (keycode == 53)
	{
		ft_printf("Esc\n");
		exit(0);
	}
	return (0);
}
