/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:00:09 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/07 15:33:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	ft_space(t_3d *obj)
{
	
}

void	ft_init(t_3d *obj)
{
	ft_space(obj);
	fdf->point.cte = fdf->map.pad / 200.00;
	fdf->point.cte1 = 0.5;
	fdf->point.cte2 = 0.5;
	fdf->point.pos = 1;
	fdf->mov.l_r = fdf->win_length / 4;
	fdf->mov.d_u = fdf->win_width / 4;
}
