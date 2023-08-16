/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/16 21:50:00 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	bresenham(t_line *line, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = line->end.x - line->start.x;
	y_step = line->end.y - line->start.y;
	max_steps = (int)nb_max(nb_absol(x_step), nb_absol(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	color_init(line);
	while (i_line < max_steps)
	{
		line->start.color = get_color(line, i_line ++, max_steps);
		if (line->start.x > 0 && line->start.y > 0
			&& line->start.x < WINDOW_WIDTH && line->start.y < WINDOW_HEIGHT
			&& line->start.x > MENU_WIDTH)
			ft_endian(&line->start, img);
		line->start.x += x_step;
		line->start.y += y_step;
	}
}

void	ft_endian(t_point *point, t_img *image)
{
	int	pix;

	pix = ((int)point->y * image->size + ((int)point->x * 4));
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
			if (oui.x < MENU_WIDTH - 15)
				oui.color = CO_GREENY;
			else if (oui.x < MENU_WIDTH)
				oui.color = CO_WHITE;
			else
				oui.color = BACKGROUND_DEFAULT;
			ft_endian(&oui, &fdf->img);
			oui.x++;
		}
		oui.y++;
	}
}
