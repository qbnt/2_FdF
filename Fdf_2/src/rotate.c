/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:30:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 16:11:18 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	rotate(t_fdf *fdf)
{
	rotate_x(fdf, fdf->cam.alpha);
	rotate_y(fdf, fdf->cam.beta);
	rotate_z(fdf, fdf->cam.gamma);
}

void	rotate_x(t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.y = fdf->point.y1 * cos(angle) - fdf->point.x1 * sin(angle);
	new_start.z = fdf->point.y1 * sin(angle) + fdf->point.x1 * cos(angle);
	fdf->point.y1 = new_start.y;
	fdf->point.z1 = new_start.z;
	new_end.y = fdf->point.y2 * cos(angle) - fdf->point.x2 * sin(angle);
	new_end.z = fdf->point.y2 * sin(angle) + fdf->point.x2 * cos(angle);
	fdf->point.y2 = new_end.y;
	fdf->point.z2 = new_end.z;
}

void	rotate_y(t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = fdf->point.x1 * cos(angle) + fdf->point.z1 * sin(angle);
	new_start.z = -fdf->point.x1 * sin(angle) + fdf->point.z1 * cos(angle);
	fdf->point.x1 = new_start.x;
	fdf->point.z1 = new_start.z;
	new_end.x = fdf->point.x2 * cos(angle) + fdf->point.z2 * sin(angle);
	new_end.z = -fdf->point.x2 * sin(angle) + fdf->point.z2 * cos(angle);
	fdf->point.x2 = new_end.x;
	fdf->point.z2 = new_end.z;
}

void	rotate_z(t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = fdf->point.x1 * cos(angle) - fdf->point.y1 * sin(angle);
	new_start.y = fdf->point.x1 * sin(angle) + fdf->point.y1 * cos(angle);
	fdf->point.x1 = new_start.x;
	fdf->point.y1 = new_start.y;
	new_end.x = fdf->point.x2 * cos(angle) - fdf->point.y2 * sin(angle);
	new_end.y = fdf->point.x2 * sin(angle) + fdf->point.y2 * cos(angle);
	fdf->point.x2 = new_end.x;
	fdf->point.y2 = new_end.y;
}
