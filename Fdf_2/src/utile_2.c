/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:26:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 12:25:29 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/******************************************************************************/

float	nb_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	nb_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	nb_absol(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WINDOW_WIDTH / map->max_x;
	scale_y = WINDOW_HEIGHT / map->max_y;
	scale_factor = nb_min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

void	def_color(t_fdf *fdf, t_point *point)
{
	if (point->z >= 0)
	{
		custom_color_init(CO_ORANGY, CO_WHITE, fdf);
		point->color = get_color(&fdf->line, point->z,
				fdf->map.max / fdf->cam.scale_factor);
	}
	else
	{
		custom_color_init(CO_ORANGY, CO_BLACK, fdf);
		point->color = get_color(&fdf->line, nb_absol(point->z),
				fdf->map.max / fdf->cam.scale_factor);
	}
}
