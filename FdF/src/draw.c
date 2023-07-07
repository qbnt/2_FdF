/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:08:00 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/07 15:09:10 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_one_colon(t_3d *obj)
{
	while (obj->point.y < ((obj->map.nb_line - 1) * obj->point.spc))
	{
		ft_place_colon_point_two(obj);
		ft_bresenham(obj);
		obj->map.y++;
		obj->point.y += obj->point.spc;
		obj->point.x1 = obj->point.x2;
		obj->point.y1 = obj->point.y2;
	}
}

static void	ft_draw_colon(t_3d *obj)
{
	obj->map.x = 0;
	obj->point.x = 0;
	while (obj->point.x < obj->map.nb_colon * obj->point.spc)
	{
		obj->map.y = 0;
		obj->point.y = 0;
		ft_place_colon_point_one(obj);
		ft_draw_one_colon(obj);
		obj->map.x ++;
		obj->point.x += obj->point.spc;
	}
}

static void	ft_draw_one_line(t_3d *obj)
{
	while (obj->point.x < ((obj->map.nb_colon - 1) * obj->point.spc))
	{
		ft_place_line_point_two(obj);
		ft_bresenham(obj);
		obj->map.x ++;
		obj->point.x += obj->point.spc;
		obj->point.x1 = obj->point.x2;
		obj->point.y1 = obj->point.y2;
	}
}

static void	ft_draw_line(t_3d *obj)
{
	obj->map.y = 0;
	obj->point.y = 0;
	while (obj->point.x < obj->map.nb_line * obj->point.spc)
	{
		obj->map.x = 0;
		obj->point.x = 0;
		ft_place_line_point_one(obj);
		ft_draw_one_line(obj);
		obj->map.y ++;
		obj->point.x += obj->point.spc;
	}
}

void	ft_draw(t_3d *obj)
{
	ft_draw_colon(obj);
	ft_draw_line(obj);
}