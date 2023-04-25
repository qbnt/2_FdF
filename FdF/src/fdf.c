/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/25 16:43:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_squar(t_env *e, t_squar *squar, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SQUAR_SIZE)
	{
		j = -1;
		while (++j < SQUAR_SIZE)
			mlx_pixel_put(e->mlx, e->win, squar->x + i, squar->y + j, color);
	}
}

int	main(void)
{
	t_env	e;
	t_squar	squar;

	ft_init_t_env(&e);
	ft_init_t_squar(&squar);
	squar.x = (WIDTH - SQUAR_SIZE) / 2;
	squar.y = (HEIGHT - SQUAR_SIZE) / 2;
	ft_init_window(&e);
	make_squar(&e, &squar, GREEN);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
