/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 17:01:49 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	bresen_atrib(t_line *line);

/******************************************************************************/

void	bresenham(t_line *line, t_img *img)
{
	bresen_atrib(line);
	while (1)
	{
		printf("Bresenham\n");
		ft_endian(&line->start, img);
		if (line->start.x == line->end.x && line->start.y == line->end.y)
			break ;
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

void	clear_image(t_fdf *fdf, int image_size)
{
	t_point	oui;

	ft_bzero(fdf->img.data, image_size * 4);
	oui.y = 0;
	while (oui.y < fdf->win_length)
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
