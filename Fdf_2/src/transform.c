/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:03:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 15:47:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	transform(t_fdf *fdf)
{
	scale(fdf, fdf->cam.scale_factor);
	translate(fdf, fdf->cam.move_x, fdf->cam.move_y);
}

void	scale(t_fdf *fdf, int scale_factor)
{
	fdf->point.x1 *= scale_factor;
	fdf->point.y1 *= scale_factor;
	fdf->point.x2 *= scale_factor;
	fdf->point.y2 *= scale_factor;
}

void	translate(t_fdf *fdf, int move_x, int move_y)
{
	fdf->point.x1 += move_x;
	fdf->point.y1 += move_y;
	fdf->point.x2 += move_x;
	fdf->point.y2 += move_y;
}