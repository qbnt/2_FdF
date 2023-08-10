/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/10 16:46:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

//static void	ft_endian(t_fdf *fdf);

/******************************************************************************/

void	ft_draw(t_fdf *fdf)
{
	t_index	i;

	ft_bzero(&i, sizeof(int) * 2);
	while (i.x < fdf->map.nb_line)
	{
		while (i.y < fdf->map.nb_colon)
		{
			
		}
	}
}
/*
static void	ft_endian(t_fdf *fdf)
{
	if (fdf->img.endian == 1)
	{
		fdf->img.data[fdf->img.i + 0]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 24);
		fdf->img.data[fdf->img.i + 1]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 16) & 0xFF;
		fdf->img.data[fdf->img.i + 2]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 8) & 0xFF;
		fdf->img.data[fdf->img.i + 3]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 0) & 0xFF;
	}
	else
	{
		fdf->img.data[fdf->img.i + 0]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 0) & 0xFF;
		fdf->img.data[fdf->img.i + 1]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 8) & 0xFF;
		fdf->img.data[fdf->img.i + 2]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 16) & 0xFF;
		fdf->img.data[fdf->img.i + 3]
			= (fdf->map.color_map[fdf->map.x][fdf->map.y] >> 24);
	}
}
*/
