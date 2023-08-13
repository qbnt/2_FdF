/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:00:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:32:19 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/******************************************************************************/

void	ft_endian(t_fdf *fdf, int color)
{
	int	pix;

	pix = (fdf->point.i.y * fdf->win_width + fdf->point.i.x) * 4;
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
	fdf->point.i.y = 0;
	while (fdf->point.i.y < fdf->win_length)
	{
		fdf->point.i.x = 0;
		while (fdf->point.i.x < fdf->win_width)
		{
			ft_endian(fdf, BACKGROUND_DEFAULT);
			fdf->point.i.x++;
		}
		fdf->point.i.y++;
	}
}
