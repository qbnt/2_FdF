/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:00:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 10:40:02 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_place_colon_point_one(t_3d *obj)
{
	if (obj->map.proj == 1)
	{
		obj->point.x1
			= obj->point.x + (obj->point.cte * (obj->map.pad * Z1PC));
		obj->point.y1
			= obj->point.y + ((obj->point.cte / 2) * (obj->map.pad * Z1PC));
	}
	else
	{
		obj->point.x1
			= obj->point.x * obj->point.cte1 - obj->point.y * obj->point.cte2;
		obj->point.y1
			= ((obj->point.pos * Z1IC) + (obj->point.cte1 / 2)
				* obj->point.x + (obj->point.cte2 / 2) * obj->point.y);
	}
	ft_printf("Colon x1 = %d et y1 = %d\n", obj->point.x1, obj->point.y1);
}

void	ft_place_colon_point_two(t_3d *obj)
{
	if (obj->map.proj == 1)
	{
		obj->point.x2 = obj->point.x + (obj->point.cte * (obj->map.pad * Z2PC));
		obj->point.y2
			= obj->point.y + ((obj->point.cte / 2) * (obj->map.pad * Z2PC));
	}
	else
	{
		obj->point.x2
			= obj->point.x * obj->point.cte1 - obj->point.y * obj->point.cte2;
		obj->point.y2
			= (obj->point.pos * Z2IC) + (obj->point.cte1 / 2) * obj->point.x
			+ (obj->point.cte2 / 2) * (obj->point.y + obj->point.spc);
	}
	ft_printf("Colon x2 = %d et y2 = %d\n", obj->point.x1, obj->point.y1);
}

void	ft_place_line_point_one(t_3d *obj)
{
	if (obj->map.proj == 1)
	{
		obj->point.x1 = obj->point.x + (obj->point.cte * (obj->map.pad * Z1PL));
		obj->point.y1
			= obj->point.y + ((obj->point.cte / 2) * (obj->map.pad * Z1PL));
	}
	else
	{
		obj->point.x1
			= obj->point.x * obj->point.cte1 - obj->point.y * obj->point.cte2;
		obj->point.y1
			= ((obj->point.pos * Z1IL) + (obj->point.cte1 / 2) * obj->point.x
				+ (obj->point.cte2 / 2) * obj->point.y);
	}
	ft_printf("Line x1 = %d et y1 = %d\n", obj->point.x1, obj->point.y1);
}

void	ft_place_line_point_two(t_3d *obj)
{
	if (obj->map.proj == 1)
	{
		obj->point.x2 = obj->point.x + (obj->point.cte * (obj->map.pad * Z2PL));
		obj->point.y2
			= obj->point.y + ((obj->point.cte / 2) * (obj->map.pad * Z2PL));
	}
	else
	{
		obj->point.x2
			= obj->point.x * obj->point.cte1 - obj->point.y * obj->point.cte2;
		obj->point.y2
			= (obj->point.pos * Z2IL) + (obj->point.cte1 / 2) * obj->point.x
			+ (obj->point.cte2 / 2) * (obj->point.y + obj->point.spc);
	}
	ft_printf("Line x1 = %d et y1 = %d\n", obj->point.x1, obj->point.y1);
}
