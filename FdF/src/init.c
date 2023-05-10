/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:47:16 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/10 09:39:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_t_env(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;
	e->width = WIDTH;
	e->height = HEIGHT;
}

void	ft_init_t_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
}
