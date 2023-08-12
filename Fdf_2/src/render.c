/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/12 16:33:52 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	render_line(t_fdf *fdf);

/******************************************************************************/

void	render(t_fdf *fdf)
{
	clear_image(fdf, MAX_PIXEL);
	fdf->map.y = 0;
	while (fdf->map.y < fdf->map.nb_colon)
	{
		fdf->map.x = 0;
		while (fdf->map.x < fdf->map.nb_line)
		{
			if (fdf->map.x < fdf->map.nb_line - 1)
				render_line(fdf);
			if (fdf->map.y < fdf->map.nb_colon - 1)
				render_line(fdf);
			fdf->map.x++;
		}
		fdf->map.y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	print_menu(fdf);
}

static void	render_line(t_fdf *fdf)
{
	fdf->point.z1 *= fdf->cam.scale_z;
	fdf->point.z2 *= fdf->cam.scale_z;
	rotate(fdf);
	project(fdf);
	transform(fdf);
	bresenham(fdf);
}
