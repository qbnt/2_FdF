/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/12 15:29:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/******************************************************************************/

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		ft_end_hook(fdf);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z
		|| keycode == KEY_X)
		key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
		key_project(keycode, fdf);
	else if (keycode == KEY_R)
		reset(fdf);
	else if (keycode == KEY_SPACE)
	{
		if (fdf->cam.color_pallet == FALSE)
			fdf->cam.color_pallet = TRUE;
		else
			fdf->cam.color_pallet = FALSE;
	}
	ft_expose_hook(fdf);
	return (0);
}

int	ft_expose_hook(t_fdf *fdf)
{
	fdf->img.ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_length);
	fdf->img.data = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bpp,
			&fdf->img.size, &fdf->img.endian);
	render(fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.ptr);
	return (0);
}

int	ft_end_hook(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->mlx_ptr);
	ft_free_int_tab(fdf->map.map, fdf->map.nb_line);
	ft_free_int_tab(fdf->map.color_map, fdf->map.nb_line);
	free(fdf);
	exit(EXIT_SUCCESS);
	return (0);
}