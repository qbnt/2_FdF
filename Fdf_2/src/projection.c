/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:33:13 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 16:06:47 by qbanet           ###   ########.fr       */
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

	point.x = (fdf->point.x1 - fdf->point.y1) * cos(ANG_30);
	point.y = (fdf->point.x1 + fdf->point.y1) * sin(ANG_30) - fdf->point.z1;
	fdf->point.x1 = point.x;
	fdf->point.y1 = point.y;
	point.x = (fdf->point.x2 - fdf->point.y2) * cos(ANG_30);
	point.y = (fdf->point.x2 + fdf->point.y2) * sin(ANG_30) - fdf->point.z2;
	fdf->point.x2 = point.x;
	fdf->point.y2 = point.y;
}

static void	perspective(t_fdf *fdf)
{
	t_point	new_start;
	t_point	point;
	double	z;

	rotate_x(fdf, 3 * -ANG_45);
	z = fdf->point.z1 + fdf->map.transform_z;
	new_start.x = fdf->point.x1 / z;
	new_start.y = fdf->point.y1 / z;
	fdf->point.x1 = new_start.x;
	fdf->point.y1 = -new_start.y;
	z = fdf->point.z2 + fdf->map.transform_z;
	point.x = fdf->point.x2 / z;
	point.y = fdf->point.y2 / z;
	fdf->point.x2 = point.x;
	fdf->point.y2 = -point.y;
	scale(fdf, fdf->map.transform_z);
}