/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:33:13 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/16 12:29:27 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	isometric(t_line *line);
static void	perspective(t_line *line, t_cam *cam, t_fdf *fdf);

/******************************************************************************/

void	project(t_line *line, t_cam *cam, t_fdf *fdf)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line, cam, fdf);
	else if (cam->projection == TOP)
		return ;
}

static void	isometric(t_line *line)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_start.y = (line->start.x + line->start.y) * sin(ANG_30) - line->start.z;
	line->start.x = new_start.x;
	line->start.y = new_start.y;
	new_end.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_end.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_end.x;
	line->end.y = new_end.y;
}

static void	perspective(t_line *line, t_cam *cam, t_fdf *fdf)
{
	t_point	new_start;
	t_point	new_end;
	float	z;

	rotate_x(line, fdf, 3 * -ANG_45);
	z = line->start.z + cam->transform_z;
	new_start.x = line->start.x / z;
	new_start.y = line->start.y / z;
	line->start.x = new_start.x;
	line->start.y = -new_start.y;
	z = line->end.z + cam->transform_z;
	new_end.x = line->end.x / z;
	new_end.y = line->end.y / z;
	line->end.x = new_end.x;
	line->end.y = -new_end.y;
	scale(line, cam->transform_z);
}
