/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:09:16 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 09:46:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_move(t_3d *obj, int keycode)
{
	if (keycode == UP)
		obj->mov.d_u -= 40;
	if (keycode == DOWN)
		obj->mov.d_u += 40;
	if (keycode == LEFT)
		obj->mov.l_r -= 40;
	if (keycode == RIGHT)
		obj->mov.l_r += 40;
	return ;
}

void	ft_key_alt(t_3d *obj, int keycode)
{
	if (keycode == M)
	{
		obj->point.cte += 0.5;
		obj->point.pos += 5;
	}
	if (keycode == L)
	{
		obj->point.cte -= 0.5;
		obj->point.cte -= 5;
	}
}

void	ft_key_zoom(t_3d *obj, int keycode)
{
	if (keycode == I)
	{
		obj->point.spc -= 5;
		if (obj->point.spc < 0)
			obj->point.spc += 5;
	}
	if (keycode == O)
	{
		obj->point.spc += 5;
		if (obj->point.spc < 0)
			obj->point.spc += 5;
	}
}

void	ft_key_proj(t_3d *obj)
{
	if (obj->map.proj == 0)
		obj->map.proj = 1;
	else if (obj->map.proj == 1)
		obj->map.proj = 0;
}
