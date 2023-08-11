/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/11 17:10:21 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	render_line(t_fdf *fdf, int start, int end);

/******************************************************************************/

void	ft_draw(t_fdf *fdf)
{
	clear_image(fdf, MAX_PIXEL * 4);
	fdf->map.x = 0;
	while (fdf->map.x < fdf->map.nb_line)
	{
		fdf->map.y = 0;
		while (fdf->map.y < fdf->map.nb_colon)
		{
			if (fdf->map.x < fdf->map.nb_line - 1)
				render_line(fdf, fdf->map.map[fdf->map.x][fdf->map.y],
					fdf->map.map[fdf->map.x + 1][fdf->map.y]);
			if (fdf->map.y < fdf->map.nb_colon - 1)
				render_line(fdf, fdf->map.map[fdf->map.x][fdf->map.y],
					fdf->map.map[fdf->map.x][fdf->map.y + 1]);
			fdf->map.y++;
		}
		fdf->map.x++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	print_menu(fdf);
}

static void	render_line(t_fdf *fdf, int start, int end)
{
	fdf->point.z1 *= fdf->cam.scale_z;
	fdf->point.z2 *= fdf->cam.scale_z;
	start += 0;
	end += 0;
	rotate(fdf);
	project(fdf);
	transform(fdf);
	bresenham(fdf);
}
