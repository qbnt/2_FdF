/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:32 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/25 12:15:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_window(t_env *e)
{
	e->mlx = mlx_init();
	if (e->mlx == NULL)
		exit(EXIT_FAILURE);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fil de Fer Aka FdF");
	if (e->win == NULL)
		exit(EXIT_FAILURE);
}

void	ft_close_window(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	mlx_destroy_display(e->mlx);
}

int		ft_mlx(t_3d *obj)
{
	ft_init_window(&obj->e);
	mlx_key_hook(&obj->e.win, &key_hook, &obj->e);
	mlx_loop(&obj->e.mlx);
}
