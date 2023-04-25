/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:29 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/25 12:49:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_squar(t_env *e, t_squar *squar)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (SQUAR_SIZE > ++i)
		while (SQUAR_SIZE > ++j)
			mlx_pixel_put(e->mlx, e->win, squar->x + i, squar->y + j, RED);
}

int	main(void)
{
	t_env	e;
	t_squar	squar;

	ft_init_t_env(&e);
	ft_init_t_squar(&squar);
	ft_init_window(&e);
	squar.x = (WIDTH - SQUAR_SIZE) / 2;
	squar.y = (HEIGHT - SQUAR_SIZE) / 2;
	make_squar(&e, &squar);
	mlx_key_hook(e.win, &key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
