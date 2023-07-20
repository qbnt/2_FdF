/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:41:03 by qbanet            #+#    #+#             */
/*   Updated: 2023/07/20 17:28:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_3d *obj, int x, int y)
{
	if (x > 0 && y > 0 && x < obj->win_length && y < obj->win_width)
	{
		PIX[(x * (obj->bpp / 8)) + (y * obj->size_line)] = RED;
		PIX[(x * (obj->bpp / 8)) + (y * obj->size_line) + 1] = GRE;
		PIX[(x * (obj->bpp / 8)) + (y * obj->size_line) + 2] = BLU;
	}
}