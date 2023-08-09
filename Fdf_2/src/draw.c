/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/09 17:38:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	ft_endian(t_fdf *fdf);

/******************************************************************************/

void	ft_draw(t_fdf *fdf)
{
	fdf += 0;
	ft_printf("ft_draw\n");
	while ()
	{
		
	}
}

static void	ft_endian(t_fdf *fdf)
{
	if (fdf->img.endian == 1)
	{
		fdf->img.data[fdf->img.i + 0] = (fdf->map.color_map >> 24);
		fdf->img.data[fdf->img.i + 1] = (fdf->map.color_map >> 16) & 0xFF;
		fdf->img.data[fdf->img.i + 2] = (fdf->map.color_map >> 8) & 0xFF;
		fdf->img.data[fdf->img.i + 3] = (fdf->map.color_map >> 0) & 0xFF;
	}
	else
	{
		fdf->img.data[fdf->img.i + 0] = (fdf->map.color_map >> 0) & 0xFF;
		fdf->img.data[fdf->img.i + 1] = (fdf->map.color_map >> 8) & 0xFF;
		fdf->img.data[fdf->img.i + 2] = (fdf->map.color_map >> 16) & 0xFF;
		fdf->img.data[fdf->img.i + 3] = (fdf->map.color_map >> 24);
	}
}
