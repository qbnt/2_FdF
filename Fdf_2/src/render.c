/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 09:40:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	set_val_render_x(t_fdf *fdf);
static void	set_val_render_y(t_fdf *fdf);
static void	select_color(t_fdf *fdf, t_point *point);

/******************************************************************************/

void	render(t_fdf *fdf)
{
	image_background(fdf);
	fdf->map.i.y = 0;
	while (fdf->map.i.y < fdf->map.max_y)
	{
		fdf->map.i.x = 0;
		while (fdf->map.i.x < fdf->map.max_x)
		{
			if (fdf->map.i.x < fdf->map.max_x - 1)
				set_val_render_x(fdf);
			if (fdf->map.i.y < fdf->map.max_y - 1)
				set_val_render_y(fdf);
			fdf->map.i.x ++;
		}
		fdf->map.i.y ++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	print_menu(fdf);
}

static void	set_val_render_x(t_fdf *fdf)
{
	fdf->line.start.x = (float)fdf->map.i.x - fdf->map.max_x / 2;
	fdf->line.start.y = (float)fdf->map.i.y - fdf->map.max_y / 2;
	fdf->line.start.z = (float)fdf->map.map[fdf->map.i.y][fdf->map.i.x];
	fdf->line.start.color = fdf->map.color_map[fdf->map.i.y][fdf->map.i.x];
	fdf->line.end.x = (float)fdf->map.i.x + 1 - fdf->map.max_x / 2;
	fdf->line.end.y = (float)fdf->map.i.y - fdf->map.max_y / 2;
	fdf->line.end.z = (float)fdf->map.map[fdf->map.i.y][fdf->map.i.x + 1];
	fdf->line.end.color
		= fdf->map.color_map[fdf->map.i.y][fdf->map.i.x + 1];
	render_line(fdf);
}

static void	set_val_render_y(t_fdf *fdf)
{
	fdf->line.start.x = (float)fdf->map.i.x - fdf->map.max_x / 2;
	fdf->line.start.y = (float)fdf->map.i.y - fdf->map.max_y / 2;
	fdf->line.start.z = (float)fdf->map.map[fdf->map.i.y][fdf->map.i.x];
	fdf->line.start.color = fdf->map.color_map[fdf->map.i.y][fdf->map.i.x];
	fdf->line.end.x = (float)fdf->map.i.x - fdf->map.max_x / 2;
	fdf->line.end.y = (float)fdf->map.i.y + 1 - fdf->map.max_y / 2;
	fdf->line.end.z = (float)fdf->map.map[fdf->map.i.y + 1][fdf->map.i.x];
	fdf->line.end.color
		= fdf->map.color_map[fdf->map.i.y + 1][fdf->map.i.x];
	render_line(fdf);
}

void	render_line(t_fdf *fdf)
{
	if (fdf->map.pad > 20)
	{
		fdf->line.start.z *= fdf->cam.scale_z / (fdf->cam.scale_factor / 2);
		fdf->line.end.z *= fdf->cam.scale_z / (fdf->cam.scale_factor / 2);
	}
	else
	{
		fdf->line.start.z *= fdf->cam.scale_z;
		fdf->line.end.z *= fdf->cam.scale_z;
	}
	select_color(fdf, &fdf->line.start);
	select_color(fdf, &fdf->line.end);
	rotate(fdf, &fdf->cam);
	project(&fdf->line, &fdf->cam, fdf);
	transform(fdf, &fdf->cam);
	bresenham(&fdf->line, &fdf->img);
}

static void	select_color(t_fdf *fdf, t_point *point)
{
	if (fdf->cam.color_pallet == FALSE)
	{
		if (!fdf->map.color)
			def_color(fdf, point);
	}
	else
	{
		set_pad_color(fdf, point);
	}
}
