/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:08:50 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 10:44:04 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mouse_scale(int mousecode, t_fdf *fdf);

/******************************************************************************/

int	mouse_hook(int mousecode, int x, int y, t_fdf *fdf)
{
	x += 0;
	y += 0;
	if (mousecode == PAD_UP || mousecode == PAD_DOWN || mousecode == PAD_LEFT
		|| mousecode == PAD_RIGHT)
		mouse_scale(mousecode, fdf);
	else if (mousecode == MID_CLIC)
	{
		if (fdf->cam.color_pallet == FALSE)
			fdf->cam.color_pallet = TRUE;
		else
			fdf->cam.color_pallet = FALSE;
	}
	ft_expose_hook(fdf);
	return (0);
}

static void	mouse_scale(int mousecode, t_fdf *fdf)
{
	if (mousecode == PAD_LEFT)
		fdf->cam.scale_factor += 1;
	else if (mousecode == PAD_RIGHT && fdf->cam.scale_factor > 2)
		fdf->cam.scale_factor -= 1;
	else if (mousecode == PAD_UP && fdf->cam.scale_z > -1)
		fdf->cam.scale_z -= 0.1;
	else if (mousecode == PAD_DOWN && fdf->cam.scale_z < 1)
		fdf->cam.scale_z += 0.1;
}
