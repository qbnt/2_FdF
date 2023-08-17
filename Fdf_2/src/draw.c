/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 11:33:33 by qbanet           ###   ########.fr       */
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
			ft_endian(line, img, line->start.color);
		line->start.x += x_step;
		line->start.y += y_step;
	}
}

void	ft_endian(t_line *line, t_img *image, int color)
{
	int	pix;

	pix = ((int)line->start.y * image->size + ((int)line->start.x * 4));
	if (image->endian == 1)
	{
		image->data[pix + 0] = color >> 24;
		image->data[pix + 1] = color >> 16 & 0xFF;
		image->data[pix + 2] = color >> 8 & 0xFF;
		image->data[pix + 3] = color >> 0 & 0xFF;
	}
	else
	{
		image->data[pix + 0] = color >> 0 & 0xFF;
		image->data[pix + 1] = color >> 8 & 0xFF;
		image->data[pix + 2] = color >> 16 & 0xFF;
		image->data[pix + 3] = color >> 24;
	}
}

void	image_background(t_fdf *fdf)
{
	t_line	oui;

	oui.start.y = 0;
	while (oui.start.y < fdf->win_heigth)
	{
		oui.start.x = 0;
		while (oui.start.x < fdf->win_width)
		{
			if (oui.start.x < MENU_WIDTH - 15)
				oui.colors.start_color = CO_GREENY;
			else if (oui.start.x < MENU_WIDTH)
				oui.colors.start_color = CO_WHITE;
			else
				oui.colors.start_color = BACKGROUND_DEFAULT;
			ft_endian(&oui, &fdf->img, oui.colors.start_color);
			oui.start.x++;
		}
		oui.start.y++;
	}
}
