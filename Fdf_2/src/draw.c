/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/12 16:27:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

static void	ft_atribut_bres(t_fdf *fdf)
{
	fdf->point.dx = nb_absol(fdf->point.x2 - fdf->point.x1);
	fdf->point.dy = nb_absol(fdf->point.y2 - fdf->point.y1);
	fdf->point.sx = fdf->point.x1 < fdf->point.x2 ? 1 : -1;
	fdf->point.sy = fdf->point.y1 < fdf->point.y2 ? 1 : -1;
	fdf->point.err
		= (fdf->point.dx > fdf->point.dy ? fdf->point.dx : -fdf->point.dy) / 2;
	fdf->point.total_distance = nb_max(fdf->point.dx, fdf->point.dy);
}

static void	ft_test_end_bres(t_fdf *fdf)
{
	fdf->point.err2 = fdf->point.err;
	if (fdf->point.err2 > -fdf->point.dx)
	{
		fdf->point.err -= fdf->point.dy;
		fdf->point.x1 += fdf->point.sx;
		fdf->point.distance_done++;
	}
	if (fdf->point.err2 < fdf->point.dy)
	{
		fdf->point.err += fdf->point.dx;
		fdf->point.y1 += fdf->point.sy;
		fdf->point.distance_done++;
	}
}

void	bresenham(t_fdf *fdf)
{
	int	start_color;
	int	end_color;

	ft_atribut_bres(fdf);
	start_color = fdf->map.color_map[5][5];
	end_color = fdf->map.color_map[8][8];
	while (1)
	{
		fdf->point.x = fdf->point.x1;
		fdf->point.y = fdf->point.y1;

		ft_endian(fdf,
			set_color
			(fdf->point.distance_done / fdf->point.total_distance,
				start_color, end_color));
		if (fdf->point.x1 == fdf->point.x2 && fdf->point.y1 == fdf->point.y2)
			break ;
		ft_test_end_bres(fdf);
	}
}


void	ft_endian(t_fdf *fdf, int color)
{
	int	pix;

	pix = (fdf->point.y * fdf->win_width + fdf->point.x) * 4;
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
	ft_bzero(fdf->img.data, image_size * 4);
	fdf->point.y = 0;
	while (fdf->point.y < fdf->win_length)
	{
		fdf->point.x = 0;
		while (fdf->point.x < fdf->win_width)
		{
			ft_endian(fdf, BACKGROUND_DEFAULT);
			fdf->point.x++;
		}
		fdf->point.y++;
	}
}
