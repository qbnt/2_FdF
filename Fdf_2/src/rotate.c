/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:30:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/16 13:41:05 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	rotate(t_fdf *fdf, t_cam *cam)
{
	rotate_x(&fdf->line, fdf, cam->alpha);
	rotate_y(&fdf->line, fdf, cam->beta);
	rotate_z(&fdf->line, fdf, cam->gamma);
}

void	rotate_x(t_line *line, t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	fdf += 0;
	new_start.y = line->start.y * cos(angle) - line->start.x * sin(angle);
	new_start.z = line->start.y * sin(angle) + line->start.x * cos(angle);
	line->start.y = new_start.y;
	line->start.z = new_start.z;
	new_end.y = line->end.y * cos(angle) - line->end.x * sin(angle);
	new_end.z = line->end.y * sin(angle) + line->end.x * cos(angle);
	line->end.y = new_end.y;
	line->end.z = new_end.z;
}

void	rotate_y(t_line *line, t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	fdf += 0;
	new_start.x = line->start.x * cos(angle) + line->start.z * sin(angle);
	new_start.z = -line->start.x * sin(angle) + line->start.z * cos(angle);
	line->start.x = new_start.x;
	line->start.z = new_start.z;
	new_end.x = line->end.x * cos(angle) + line->end.z * sin(angle);
	new_end.z = -line->end.x * sin(angle) + line->end.z * cos(angle);
	line->end.x = new_end.x;
	line->end.z = new_end.z;
}

void	rotate_z(t_line *line, t_fdf *fdf, double angle)
{
	t_point	new_start;
	t_point	new_end;

	fdf += 0;
	new_start.x = line->start.x * cos(angle) - line->start.y * sin(angle);
	new_start.y = line->start.x * sin(angle) + line->start.y * cos(angle);
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = line->end.x * cos(angle) - line->end.y * sin(angle);
	new_end.y = line->end.x * sin(angle) + line->end.y * cos(angle);
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}
