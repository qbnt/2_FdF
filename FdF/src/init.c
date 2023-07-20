/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:00:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 17:23:10 by qbanet           ###   ########.fr       */
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

void	ft_window(t_3d *obj)
{
	if (obj->map.nb_colon <= 10)
		obj->win_length = obj->map.nb_colon * 100;
	else if (obj->map.nb_colon <= 20)
		obj->win_length = obj->map.nb_colon * 70;
	else if (obj->map.nb_colon >= 20 && obj->map.nb_colon <= 50)
		obj->win_length = obj->map.nb_colon * 40;
	else if (obj->map.nb_colon >= 50 && obj->map.nb_colon <= 100)
		obj->win_length = obj->map.nb_colon * 20;
	else if (obj->map.nb_colon >= 100 && obj->map.nb_colon <= 200)
		obj->win_length = obj->map.nb_colon * 10;
	else
		obj->win_length = obj->map.nb_colon * 10;
	if (obj->map.nb_line <= 20)
		obj->win_width = obj->map.nb_line * 100;
	else if (obj->map.nb_line >= 20 && obj->map.nb_line <= 50)
		obj->win_width = obj->map.nb_line * 40;
	else if (obj->map.nb_line >= 50 && obj->map.nb_line <= 100)
		obj->win_width = obj->map.nb_line * 20;
	else if (obj->map.nb_line >= 100 && obj->map.nb_line <= 200)
		obj->win_width = obj->map.nb_line * 10;
	else
		obj->win_width = obj->map.nb_line * 10;
}

void	ft_init(t_3d *obj)
{
	ft_space(obj);
	if (!obj->map.color)
	{
		obj->color.red = 255;
		obj->color.green = 255;
		obj->color.blue = 255;
	}
	obj->point.cte = obj->map.pad / 200.00;
	obj->point.cte1 = 0.5;
	obj->point.cte2 = 0.5;
	obj->point.pos = 1;
	obj->mov.l_r = obj->win_length / 4;
	obj->mov.d_u = obj->win_width / 4;
}
