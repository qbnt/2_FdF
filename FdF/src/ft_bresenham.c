/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:33:53 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 10:01:57 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_test(t_3d *obj)
{
	obj->point.dx = (abs(obj->point.x2 - obj->point.x1));
	if (obj->point.x1 < obj->point.x2)
		obj->point.sx = 1;
	else
		obj->point.sx = -1;
	obj->point.dy = (abs(obj->point.y2 - obj->point.y1));
	if (obj->point.y1 < obj->point.y2)
		obj->point.sy = 1;
	else
		obj->point.sy = -1;
	if (obj->point.dx > obj->point.dy)
		obj->point.err = obj->point.dx / 2;
	else
		obj->point.err = obj->point.dy / 2;
}

void	ft_bresenham(t_3d *obj)
{
	ft_test(obj);
	while (1)
	{
		ft_pixel_put(obj, obj->mov.l_r + obj->point.x1,
			obj->mov.d_u + obj->point.y1);
		if (obj->point.x1 == obj->point.x2 && obj->point.y1 == obj->point.y2)
			break ;
		obj->point.e2 = obj->point.err;
		if (obj->point.e2 > -obj->point.dx)
		{
			obj->point.err -= obj->point.dy;
			obj->point.x1 += obj->point.sx;
		}
		if (obj->point.e2 < obj->point.dy)
		{
			obj->point.err += obj->point.dx;
			obj->point.y1 += obj->point.sy;
		}
	}
}