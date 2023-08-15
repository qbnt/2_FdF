/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 20:50:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	bresen_atrib(t_line *line);

/******************************************************************************/

void	bresenham(t_line *line, t_img *img)
{
	int	i;
	int	max_steps;

	bresen_atrib(line);
	i = 0;
	max_steps = (int)nb_max(nb_absol(line->dx), nb_absol(line->dy));
	while (i < max_steps)
	{
		if (line->start.x > 0 && line->start.y > 0
			&& line->start.x < WINDOW_WIDTH && line->start.y < WINDOW_HEIGHT)
			ft_endian(&line->start, img);
		line->err2 = line->err;
		if (line->err2 > -line->dx)
		{
			line->err -= line->dy;
			line->start.x += line->sx;
		}
		if (line->err2 < line->dy)
		{
			line->err += line->dx;
			line->start.y += line->sy;
		}
		i ++;
	}
}

static void	bresen_atrib(t_line *line)
{
	line->dx = nb_absol(line->end.x - line->start.x);
	line->dy = nb_absol(line->end.y - line->start.y);
	if (line->start.x < line->end.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->start.y < line->end.y)
		line->sy = 1;
	else
		line->sy = -1;
	if (line->dx > line->dy)
		line->err = line->dx / 2;
	else
		line->err = line->dy / 2;
}

void	ft_endian(t_point *point, t_img *image)
{
	int	pix;

	pix = (point->y * WINDOW_WIDTH + point->x) * 4;
	if (image->endian == 1)
	{
		image->data[pix + 0] = point->color >> 24;
		image->data[pix + 1] = point->color >> 16 & 0xFF;
		image->data[pix + 2] = point->color >> 8 & 0xFF;
		image->data[pix + 3] = point->color >> 0 & 0xFF;
	}
	else
	{
		image->data[pix + 0] = point->color >> 0 & 0xFF;
		image->data[pix + 1] = point->color >> 8 & 0xFF;
		image->data[pix + 2] = point->color >> 16 & 0xFF;
		image->data[pix + 3] = point->color >> 24;
	}
}

void	image_background(t_fdf *fdf, int image_size)
{
	t_point	oui;

	ft_bzero(fdf->img.data, image_size * 4);
	oui.y = 0;
	while (oui.y < fdf->win_heigth)
	{
		oui.x = 0;
		while (oui.x < fdf->win_width)
		{
			if (oui.x < MENU_WIDTH)
				oui.color = CO_GREENY;
			else
				oui.color = BACKGROUND_DEFAULT;
			ft_endian(&oui, &fdf->img);
			oui.x++;
		}
		oui.y++;
	}
}
