/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:30:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 13:57:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	rotate(t_line *line, t_cam *cam)
{
	rotate_x(line, cam->alpha);
	rotate_y(line, cam->beta);
	rotate_z(line, cam->gamma);
}

void	rotate_x(t_line *line, double angle)
{
	t_point	new_point;

	new_point.y = line->start.y * cos(angle) - line->start.x * sin(angle);
	new_point.z = line->start.y * sin(angle) + line->start.x * cos(angle);
	line->start.y = new_point.y;
	line->start.z = new_point.z;
	new_point.y = line->end.y * cos(angle) - line->end.x * sin(angle);
	new_point.z = line->end.y * sin(angle) + line->end.x * cos(angle);
	line->end.y = new_point.y;
	line->end.z = new_point.z;
}

void	rotate_y(t_line *line, double angle)
{
	t_point	new_point;

	new_point.x = line->start.x * cos(angle) + line->start.z * sin(angle);
	new_point.z = -line->start.x * sin(angle) + line->start.z * cos(angle);
	line->start.x = new_point.x;
	line->start.z = new_point.z;
	new_point.x = line->end.x * cos(angle) + line->end.z * sin(angle);
	new_point.z = -line->end.x * sin(angle) + line->end.z * cos(angle);
	line->end.x = new_point.x;
	line->end.z = new_point.z;
}

void	rotate_z(t_line *line, double angle)
{
	t_point	new_point;

	new_point.x = line->start.x * cos(angle) - line->start.y * sin(angle);
	new_point.y = line->start.x * sin(angle) + line->start.y * cos(angle);
	line->start.x = new_point.x;
	line->start.y = new_point.y;
	new_point.x = line->end.x * cos(angle) - line->end.y * sin(angle);
	new_point.y = line->end.x * sin(angle) + line->end.y * cos(angle);
	line->end.x = new_point.x;
	line->end.y = new_point.y;
}
