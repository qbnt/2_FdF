/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:28:30 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 14:26:58 by qbanet           ###   ########.fr       */
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
