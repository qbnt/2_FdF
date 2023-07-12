/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:00:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/12 08:05:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	ft_space(t_3d *obj)
{
	if (obj->map.nb_colon <= 20)
		obj->point.spc = 25;
	else if (obj->map.nb_colon >= 20 && obj->map.nb_colon <= 50)
		obj->point.spc = 20;
	else if (obj->map.nb_colon >= 50 && obj->map.nb_colon <= 100)
		obj->point.spc = 15;
	else if (obj->map.nb_colon >= 100 && obj->map.nb_colon <= 200)
		obj->point.spc = 5;
	else
		obj->point.spc = 1;
}

void	ft_init(t_3d *obj)
{
	ft_space(obj);
	obj->point.cte = obj->map.pad / 200.00;
	obj->point.cte1 = 0.5;
	obj->point.cte2 = 0.5;
	obj->point.pos = 1;
	obj->mov.l_r = obj->e.height / 4;
	obj->mov.d_u = obj->e.width / 4;
}
