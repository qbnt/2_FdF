/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:33:13 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 13:56:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	isometric(t_line *line);
static void	perspective(t_line *line, t_cam *cam);

/******************************************************************************/

void	project(t_line *line, t_cam *cam)
{
	if (cam->projection == ISOMETRIC)
		isometric(line);
	else if (cam->projection == PERSPECTIVE)
		perspective(line, cam);
	else if (cam->projection == TOP)
		return ;
}

static void	isometric(t_line *line)
{
	t_point	new_point;

	new_point.x = (line->start.x - line->start.y) * cos(ANG_30);
	new_point.y = (line->start.x + line->start.y) * sin(ANG_30) - line->start.z;
	line->start.x = new_point.x;
	line->start.y = new_point.y;
	new_point.x = (line->end.x - line->end.y) * cos(ANG_30);
	new_point.y = (line->end.x + line->end.y) * sin(ANG_30) - line->end.z;
	line->end.x = new_point.x;
	line->end.y = new_point.y;
}

static void	perspective(t_line *line, t_cam *cam)
{
	t_point	new_point;
	float	z;

	rotate_x(line, 3 * -ANG_45);
	z = line->start.z + cam->transform_z;
	new_point.x = line->start.x / z;
	new_point.y = line->start.y / z;
	line->start.x = new_point.x;
	line->start.y = -new_point.y;
	z = line->end.z + cam->transform_z;
	new_point.x = line->end.x / z;
	new_point.y = line->end.y / z;
	line->end.x = new_point.x;
	line->end.y = -new_point.y;
	scale(line, cam->transform_z);
}
