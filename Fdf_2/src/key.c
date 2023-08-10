/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/10 14:47:14 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/******************************************************************************/

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		ft_end_hook(fdf);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		ft_key_move(fdf, keycode);
	else if (keycode == KEY_W || keycode == KEY_S)
		ft_key_zoom(fdf, keycode);
	else if (keycode == KEY_A || keycode == KEY_D)
		ft_key_rot(fdf, keycode);
	else if (keycode == KEY_P)
		ft_key_proj(fdf, keycode);
	else
		ft_printf("Touche inconnue: %d\n", keycode);
	ft_expose_hook(fdf);
	return (0);
}

int	ft_expose_hook(t_fdf *fdf)
{
	fdf->img.ptr = mlx_new_image(fdf->mlx_ptr, fdf->win_width, fdf->win_length);
	fdf->img.data = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bpp,
			&fdf->img.size, &fdf->img.endian);
	ft_draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.ptr, 0, 0);
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