/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 18:16:26 by qbanet           ###   ########.fr       */
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
		if (fdf->point.x1 > 0 && fdf->point.y1 > 0 && fdf->point.x1
			< fdf->win_width && fdf->point.y1 < fdf->win_length)
			ft_endian(fdf, fdf->map.color_map[fdf->map.x][fdf->map.y]);
		fdf->point.x1 += x_step;
		fdf->point.y1 += y_step;
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
	fdf->point.y = 0;
	ft_bzero(fdf->img.data, image_size);
	printf("y = %f\n", fdf->point.y);
	while ((int)fdf->point.y < WINDOW_WIDTH)
	{
		fdf->point.x = 0;
		while ((int)fdf->point.x < WINDOW_HEIGHT)
		{
			ft_endian(fdf, BACKGROUND_DEFAULT);
			fdf->point.x++;
		}
		fdf->point.y++;
	}
}
