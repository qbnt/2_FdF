/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 17:22:17 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	ft_endian(t_fdf *fdf, int color);

/******************************************************************************/


void	bresenham(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = fdf->point.x2 - fdf->point.x1;
	y_step = fdf->point.y2 - fdf->point.y1;
	max_steps = (int)nb_max(nb_absol(x_step), nb_absol(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	while (i_line < max_steps)
	{
		if (fdf->point.x > 0 && fdf->point.y > 0 && fdf->point.x
			< fdf->win_width && fdf->point.y < fdf->win_length)
			ft_endian(fdf, fdf->map.color_map[fdf->map.x][fdf->map.y]);
		fdf->point.x += x_step;
		fdf->point.y += y_step;
	}
}

static void	ft_endian(t_fdf *fdf, int color)
{
	int	pix;

	pix = ((int)fdf->point.y * fdf->img.bpp) + ((int)fdf->point.x * 4);
	if (fdf->img.endian == 1)
	{
		fdf->img.data[pix + 0] = color >> 24;
		fdf->img.data[pix + 1] = color >> 16 & 0xFF;
		fdf->img.data[pix + 2] = color >> 8 & 0xFF;
		fdf->img.data[pix + 3] = color >> 0 & 0xFF;
	}
	else
	{
		fdf->img.data[pix + 0] = color >> 0 & 0xFF;
		fdf->img.data[pix + 1] = color >> 8 & 0xFF;
		fdf->img.data[pix + 2] = color >> 16 & 0xFF;
		fdf->img.data[pix + 3] = color >> 24;
	}
}

void	clear_image(t_fdf *fdf, int image_size)
{
	int	x;
	int	y;

	ft_bzero(fdf->img.data, image_size);
	y = 0;
	while (y < fdf->win_length)
	{
		x = 0;
		while (x < fdf->win_width)
		{
			ft_endian(fdf, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}
