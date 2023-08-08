/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:22:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/07 18:22:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	ft_draw_colons(t_fdf *fdf);
static int	ft_draw_single_colon(t_fdf *fdf);
/*
static void	ft_draw_lines(t_fdf *fdf);
static int	ft_draw_single_line(t_fdf *fdf)
*/
/******************************************************************************/

void	ft_draw(t_fdf *fdf)
{
	fdf += 0;
	ft_printf("ft_draw\n");
	ft_draw_colons(fdf);
//	ft_draw_lines(fdf);
}

static void	ft_draw_colons(t_fdf *fdf)
{
	int	res;

	res = 1;
	fdf->map.x = 0;
	fdf->point.x = 0;
	ft_printf("ft_draw_colons\n");
	while (res)
	{
		ft_place_point_zero(fdf);
		res = ft_draw_single_colon(fdf);
	}
}

static int	ft_draw_single_colon(t_fdf *fdf)
{
	ft_place_next_point(fdf);
//	ft_bresenham(fdf);
	if (fdf->map.x == fdf->map.nb_line - 1)
		return (0);
	return (0);
}
/*
static void	ft_draw_lines(t_fdf *fdf)
{
	
}

static int	ft_draw_single_line(t_fdf *fdf)
{
	
}
*/