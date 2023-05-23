/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:47:16 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/23 16:22:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_t_3d(t_3d *obj)
{
	ft_init_t_env(&obj->e);
	ft_init_t_point(&obj->pt);
	ft_init_t_map(&obj->map);
}

void	ft_init_t_env(t_env *e)
{
	e->mlx = NULL;
	e->win = NULL;
	e->img = NULL;
	e->width = WIDTH;
	e->height = HEIGHT;
}

void	ft_init_t_map(t_map *map)
{
	map->map = NULL;
	map->nb_colon = 0;
	map->nb_line = 0;
	map->x = 0;
	map->y = 0;
	map->max = 0;
	map->pad = 0;
}

void	ft_init_t_point(t_point *point)
{
	point->x = 0;
	point->y = 0;
}
