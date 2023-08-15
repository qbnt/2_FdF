/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:59:53 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/15 20:42:10 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/******************************************************************************/

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		error(3);
	create_map(&fdf->map, file);
	fdf->mlx_ptr = mlx_init();
	fdf->win_width = WINDOW_WIDTH;
	fdf->win_heigth = WINDOW_HEIGHT;
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_width, fdf->win_heigth,
			win_name(file));
	init_image(fdf);
	init_cam(fdf);
	return (fdf);
}

void	init_image(t_fdf *fdf)
{
	fdf->img.ptr = mlx_new_image(fdf->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img.data = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bpp,
			&fdf->img.size, &fdf->img.endian);
}

void	init_cam(t_fdf *fdf)
{
	fdf->cam.projection = TOP;
	fdf->cam.color_pallet = FALSE;
	fdf->cam.scale_factor = scale_to_fit(&fdf->map);
	fdf->cam.scale_z = 1;
	fdf->cam.move_x = WINDOW_WIDTH / 2;
	fdf->cam.move_y = WINDOW_HEIGHT / 2;
	fdf->cam.alpha = 0;
	fdf->cam.beta = 0;
	fdf->cam.gamma = 0;
}
