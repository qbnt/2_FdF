/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:33:13 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:36:14 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	isometric(t_fdf *fdf);
static void	perspective(t_fdf *fdf);

/******************************************************************************/

void	project(t_fdf *fdf)
{
	if (fdf->cam.projection == ISOMETRIC)
		isometric(fdf);
	else if (fdf->cam.projection == PERSPECTIVE)
		perspective(fdf);
	else if (fdf->cam.projection == TOP)
		return ;
}

static void	isometric(t_fdf *fdf)
{
	t_point	point;

	point.i.x = (fdf->point.x1 - fdf->point.y1) * cos(ANG_30);
	point.i.y = (fdf->point.x1 + fdf->point.y1) * sin(ANG_30) - fdf->point.z1;
	fdf->point.x1 = point.i.x;
	fdf->point.y1 = point.i.y;
	point.i.x = (fdf->point.x2 - fdf->point.y2) * cos(ANG_30);
	point.i.y = (fdf->point.x2 + fdf->point.y2) * sin(ANG_30) - fdf->point.z2;
	fdf->point.x2 = point.i.x;
	fdf->point.y2 = point.i.y;
}

static void	perspective(t_fdf *fdf)
{
	t_point	new_start;
	t_point	point;
	double	z;

	rotate_x(fdf, 3 * -ANG_45);
	z = fdf->point.z1 + fdf->cam.transform_z;
	new_start.i.x = fdf->point.x1 / z;
	new_start.i.y = fdf->point.y1 / z;
	fdf->point.x1 = new_start.i.x;
	fdf->point.y1 = -new_start.i.y;
	z = fdf->point.z2 + fdf->cam.transform_z;
	point.i.x = fdf->point.x2 / z;
	point.i.y = fdf->point.y2 / z;
	fdf->point.x2 = point.i.x;
	fdf->point.y2 = -point.i.y;
	scale(fdf, fdf->cam.transform_z);
}