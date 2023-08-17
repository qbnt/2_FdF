/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:28:30 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 20:07:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam.move_x -= 10;
	else if (keycode == KEY_LEFT)
		fdf->cam.move_x += 10;
	else if (keycode == KEY_DOWN)
		fdf->cam.move_y -= 10;
	else if (keycode == KEY_UP)
		fdf->cam.move_y += 10;
}

void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->cam.scale_factor += 1;
	else if (keycode == KEY_MINUS && fdf->cam.scale_factor > 2)
		fdf->cam.scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->cam.scale_z > -1)
		fdf->cam.scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->cam.scale_z < 1)
		fdf->cam.scale_z += 0.1;
}

void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->cam.alpha -= (5 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam.alpha += (5 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam.gamma -= (5 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam.gamma += (5 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam.beta -= (5 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam.beta += (5 * ANG_1);
}

void	key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
		fdf->cam.projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->cam.projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam.projection = TOP;
}

int	ft_end_hook(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	ft_free_int_tab(fdf->map.map, fdf->map.max_y);
	ft_free_int_tab(fdf->map.color_map, fdf->map.max_y);
	free(fdf);
	exit(EXIT_SUCCESS);
	return (0);
}
