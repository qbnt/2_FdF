/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:03:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/16 10:00:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	transform(t_fdf *fdf, t_cam *cam)
{
	scale(&fdf->line, cam->scale_factor);
	translate(fdf, cam->move_x, cam->move_y, cam->scale_factor);
}

void	scale(t_line *line, int scale_factor)
{
	line->start.x *= scale_factor;
	line->start.y *= scale_factor;
	line->end.x *= scale_factor;
	line->end.y *= scale_factor;
}

void	translate(t_fdf *fdf, int move_x, int move_y, int scale_factor)
{
	fdf->line.start.x += move_x - ((fdf->map.max_x * scale_factor) / 2);
	fdf->line.start.y += move_y - ((fdf->map.max_y * scale_factor) / 2);
	fdf->line.end.x += move_x - ((fdf->map.max_x * scale_factor) / 2);
	fdf->line.end.y += move_y - ((fdf->map.max_y * scale_factor) / 2);
}
