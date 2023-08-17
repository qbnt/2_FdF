/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:07:31 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 20:07:46 by qbanet           ###   ########.fr       */
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
