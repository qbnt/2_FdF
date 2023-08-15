/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 17:01:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	set_val_render(t_fdf *fdf);
static void	set_col_render(t_fdf *fdf);

/******************************************************************************/

void	render(t_fdf *fdf)
{
	clear_image(fdf, MAX_PIXEL);
	fdf->map.i.x = 0;
	while (fdf->map.i.x < fdf->map.nb_line)
	{
		fdf->map.i.y = 0;
		while (fdf->map.i.y < fdf->map.nb_colon)
		{
			set_val_render(fdf);
			set_col_render(fdf);
			render_line(fdf);
			fdf->map.i.y ++;
		}
		fdf->map.i.x ++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
	print_menu(fdf);
}

static void	set_val_render(t_fdf *fdf)
{
	fdf->line.start.x = (float)fdf->map.i.x;
	fdf->line.start.y = (float)fdf->map.i.y;
	fdf->line.start.z = (float)fdf->map.map[fdf->map.i.x][fdf->map.i.y];
	fdf->line.start.color = fdf->map.color_map[fdf->map.i.x][fdf->map.i.y];
	if (fdf->map.i.y < fdf->map.nb_line - 1)
	{
		fdf->line.end.x = (float)fdf->map.i.x;
		fdf->line.end.y = (float)fdf->map.i.y + 1;
		fdf->line.end.z = (float)fdf->map.map[fdf->map.i.x][fdf->map.i.y + 1];
		fdf->line.end.color
			= fdf->map.color_map[fdf->map.i.x][fdf->map.i.y + 1];
	}
	else if (fdf->map.i.x < fdf->map.nb_line - 1)
	{
		fdf->line.end.x = (float)fdf->map.i.x + 1;
		fdf->line.end.y = (float)fdf->map.i.y;
		fdf->line.end.z = (float)fdf->map.map[fdf->map.i.x + 1][fdf->map.i.y];
		fdf->line.end.color
			= fdf->map.color_map[fdf->map.i.x + 1][fdf->map.i.y];
	}
}

static void	set_col_render(t_fdf *fdf)
{
	if (fdf->cam.color_pallet == FALSE)
	{
		printf("custom color a faire\n");
	}
	else
		printf("def color a faire\n");
}

void	render_line(t_fdf *fdf)
{
	fdf->line.start.z *= fdf->cam.scale_z;
	fdf->line.end.z *= fdf->cam.scale_z;
//	rotate(&fdf->line, &fdf->cam);
//	project(&fdf->line, &fdf->cam);
//	transform(&fdf->line, &fdf->cam);
	printf("start.x = %.1f, start.y = %.1f, start.z = %.1f\n",
		fdf->line.start.x, fdf->line.start.y, fdf->line.start.z);
	printf("end.x 	= %.1f,   end.y = %.1f,   end.z = %.1f\n\n",
		fdf->line.end.x, fdf->line.end.y, fdf->line.end.z);
	bresenham(&fdf->line, &fdf->img);
	fdf->line.start.x += 50;
	fdf->line.start.y += 50;
}
