/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:00:39 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/07 15:32:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	ft_place_colon_point_one(t_3d *obj)
{
	if (obj->map.proj == 1)
	{
		obj->point.x1 = obj->point.x + (obj->point.cte * (obj->map.pad * Z1PC);
		obj->point.y1 = obj->point.y + ((obj->point.cte / 2) *
				(obj->map.pad * Z1PC);
	}
	else
	{
		
	}
}

void	ft_place_colon_point_two(t_3d *obj)
{
	
}